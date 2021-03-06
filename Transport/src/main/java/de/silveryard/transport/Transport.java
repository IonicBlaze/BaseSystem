package de.silveryard.transport;

import de.silveryard.transport.filecache.BufferList;

import java.io.*;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * Created by CHofm on 08.01.2017.
 */
public class Transport {
    private final static char[] hexArray = "0123456789abcdef".toCharArray();
    private static char[] hexChars = new char[32];

    private DataOutputStream outStream;
    private DataInputStream inStream;
    private Thread messageReceiverThread;
    private BufferList buffer;

    private int nextStartIndex;
    private int nextMsgLength;

    private volatile boolean running;

    /**
     * Constructor
     * @param out Output Stream to send messages over
     * @param in Input Stream to read messages from
     * @param handler Handler that gets callen when a message is received
     */
    public Transport(OutputStream out, InputStream in, MessageHandler handler){
        Objects.requireNonNull(out);
        Objects.requireNonNull(in);
        Objects.requireNonNull(handler);

        nextStartIndex = -1;
        nextMsgLength = -1;

        this.outStream = new DataOutputStream(out);
        this.inStream = new DataInputStream(in);
        this.running = true;

        messageReceiverThread = new Thread(() -> {
            buffer = new BufferList(65280);
            int bytesRead = 0;
            byte[] readBuffer = new byte[4096];
            while(running){
                try {
                    try{
                        bytesRead = inStream.read(readBuffer);
                        if(bytesRead == -1){
                            //connection closed
                            disconnect();
                            continue;
                        }
                        buffer.addRange(readBuffer, 0, bytesRead);
                    }catch(SocketException e){
                        disconnect();
                    }


                    while(findNextMessage()){
                        handler.handle(constructMessage());
                    }
                } catch (IOException e) {
                    disconnect();
                }
            }
        });
        messageReceiverThread.setName("messageReceiverThread");
        messageReceiverThread.setDaemon(true);
        messageReceiverThread.start();
    }

    /**
     * @param m The message to be sent
     * @return If sending was successful this method returns true, else it returns false
     */
    public synchronized boolean send(Message m){
        try {
            byte[] data = m.toBytes();
            outStream.write(data);
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    /**
     * Constructs a message using the beginIndex and length if a message was found by findNextMessage()
     * @return a message constructed from the byte array
     */
    private Message constructMessage(){
        String senderID = bytesToHex(nextStartIndex + 8);
        String destinationID = bytesToHex(nextStartIndex + 24);
        String commandHash = bytesToHex(nextStartIndex + 40);

        int paramCount = buffer.get(nextStartIndex + 56) & 0xFF;
        List<Parameter> params = new ArrayList<>(paramCount);

        //Can't use buffer array for parameter data because array is passed by reference
        //Update buffer -> update all parameters that reference the buffer -> bad.
        int index = 57;
        int paramLength = 0;

        for(int i = 0; i < paramCount; i++){
            paramLength = buffer.get(index) & 0xFF;
            params.add(Parameter.createByteArray(buffer.subList(index + 1, paramLength).toArray()));
            index += paramLength + 1;
        }

        buffer.removeRange(nextStartIndex, nextMsgLength);
        return new Message(senderID, destinationID, commandHash, params);
    }

    /**
     * Constructs a hex string from a given byte array
     * @param offset the offset from which to read 16 bytes and transform them into a hex string
     * @return the hex string constructed from the given byte array
     */
    private String bytesToHex(int offset) {
        for ( int j = 0, v = 0; j < 16; j++ ) {
            v = buffer.get(offset + j) & 0xFF;
            hexChars[j * 2] = hexArray[v >>> 4];
            hexChars[j * 2 + 1] = hexArray[v & 0x0F];
        }
        return new String(hexChars);
    }

    private boolean findNextMessage(){
        nextStartIndex = -1;
        nextMsgLength = -1;

        int startSeqPointer = 0;

        for(int i = 0; i < buffer.size(); i++) {
            startSeqPointer = (buffer.get(i) == Message.MESSAGE_START_SEQUENCE[startSeqPointer])
                    ? startSeqPointer + 1
                    : 0;

            if (startSeqPointer == 8) {
                //If no end sequence found
                if(buffer.size() < i+57){
                    return false;
                }

                int paramCount = buffer.get(i+49) & 0xFF;
                int index = i + 50;


                for(int j = 0; j < paramCount; j++){
                    if(index >= buffer.size()){
                        return false;
                    }
                    index += (buffer.get(index) & 0xFF) + 1;
                }

                if(buffer.size() < index + 8){
                    return false;
                }

                for(int k = index; k < index + 8; k++) {
                    if(!(buffer.get(k) == Message.MESSAGE_END_SEQUENCE[k - index])){
                        throw new InvalidMessageException("No end sequence found");
                    }
                }

                nextStartIndex = i - 7;
                nextMsgLength = index + 8 - nextStartIndex;
                return true;
            }
        }
        return false;
    }

    /**
     *  Frees all resources associated with this transport object
     */
    public void disconnect(){
        running = false;
        try {
            inStream.close();
        } catch (IOException e) {/* fuck it */}
        try {
            outStream.close();
        } catch (IOException e) {/* fuck it */}
    }

    /**
     * @return Returns if a connection is currently active
     */
    public boolean isConnected(){
        return running;
    }
}
