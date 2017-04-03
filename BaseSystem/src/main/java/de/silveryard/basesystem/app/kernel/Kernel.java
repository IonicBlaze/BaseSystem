package de.silveryard.basesystem.app.kernel;

import de.silveryard.basesystem.app.RunningApp;
import de.silveryard.basesystem.util.Utils;
import de.silveryard.transport.Parameter;
import de.silveryard.transport.highlevelprotocols.qa.QAMessage;

import java.util.*;

/**
 * Created by Sebif on 13.03.2017.
 */
public class Kernel {
    private static Kernel instance;
    public static Kernel getInstance(){
        return instance;
    }
    public static void beginInitialize(){
        instance = new Kernel();
    }
    public static void endInitialize(){
        instance.endInitializeKernel();
    }

    private boolean initializing;

    private Map<String, String> hashToSystemCallMap;
    private Map<String, ISystemCallHandler> systemCalls;

    private Kernel(){
        initializing = true;

        hashToSystemCallMap = new HashMap<>();
        systemCalls = new HashMap<>();
    }

    public void endInitializeKernel(){
        if(!initializing){
            throw new RuntimeException("Kernel aready finished initializing");
        }

        initializing = false;
    }

    public void registerSystemCall(String command, ISystemCallHandler handler){
        if(!initializing){
            throw new RuntimeException("Cannot register initialization after endInitializeKernel has been called");
        }

        String md5 = Utils.generateMd5(command);
        hashToSystemCallMap.put(md5, command);
        systemCalls.put(md5, handler);
    }

    public List<String> dump(){
        List<String> calls = new ArrayList<>();
        for(String key : hashToSystemCallMap.keySet()){
            calls.add(hashToSystemCallMap.get(key));
        }
        Collections.sort(calls);
        return calls;
    }

    public QAMessage handleSystemCall(RunningApp app, QAMessage message){
        QAMessage response = null;

        if(systemCalls.containsKey(message.getMessage().getCommandHash())){
            ISystemCallHandler handler = systemCalls.get(message.getMessage().getCommandHash());
            response = handler.invoke(app, message);
        }else{
            List<Parameter> params = new ArrayList<>();
            params.add(Parameter.createInt(ReturnCode.NOT_IMPLEMENTED.getValue()));
            response = new QAMessage(message, params);
        }

        return response;
    }

    public QAMessage createResponse(QAMessage source, int genericReturnCode, int specificReturnCode, Parameter... result){
        List<Parameter> params = new ArrayList<>();
        params.add(Parameter.createInt(genericReturnCode));
        params.add(Parameter.createInt(specificReturnCode));

        for(Parameter param : result){
            params.add(param);
        }

        return new QAMessage(source, params);
    }
}