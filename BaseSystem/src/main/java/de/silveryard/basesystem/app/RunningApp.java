package de.silveryard.basesystem.app;

import de.silveryard.basesystem.app.kernel.Kernel;
import de.silveryard.basesystem.gui.Frame;
import de.silveryard.basesystem.gui.GraphicsManager;
import de.silveryard.basesystem.util.IDisposable;
import de.silveryard.transport.Message;
import de.silveryard.transport.highlevelprotocols.qa.QAMessage;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by Sebif on 12.03.2017.
 */
public class RunningApp implements IDisposable {
    private static final int FRAME_LAYER = 5;

    private String appIdentifier;
    private AppLoader appLoader;
    private Frame frame;

    private int nextObjectId;
    private Map<Integer, Object> objects;

    public RunningApp(String appIdentifier, AppLoader appLoader){
        this.appIdentifier = appIdentifier;
        this.appLoader = appLoader;

        this.frame = GraphicsManager.getInstance().createFrame();
        this.frame.setLayer(FRAME_LAYER);

        nextObjectId = 1;
        objects = new HashMap<>();

        appLoader.setSystemMessageHandler(this::handleMessage);
    }

    public String getAppIdentifier(){
        return appIdentifier;
    }
    public Frame getFrame(){
        return frame;
    }

    private void handleMessage(Message message){
        QAMessage qaMessage = new QAMessage(message);
        QAMessage qaResponse = Kernel.getInstance().handleSystemCall(this, qaMessage);
        appLoader.sendMessage(qaResponse.getMessage());
    }

    public int registerObject(Object obj){
        int i = nextObjectId;
        nextObjectId++;
        objects.put(i, obj);
        return i;
    }
    public Object getRegisteredObject(int objectId){
        if(objects.containsKey(objectId)){
            return objects.get(objectId);
        }else{
            return null;
        }
    }
    public void unregisterObject(int objectId){
        objects.remove(objectId);
    }
    public Integer getId(Object obj){
        for(Integer key : objects.keySet()){
            if(objects.get(key) == obj){
                return key;
            }
        }
        return -1;
    }

    @Override
    public void dispose() {
        frame.dispose();
        appLoader.dispose();
    }
}