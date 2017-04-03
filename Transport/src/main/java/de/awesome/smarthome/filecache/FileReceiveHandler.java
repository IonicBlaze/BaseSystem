package de.awesome.smarthome.filecache;

import de.awesome.smarthome.transport.Parameter;

import java.util.List;

/**
 * Created by CHofm on 14.01.2017.
 */
@FunctionalInterface
public interface FileReceiveHandler {
    /**
     * Called when a file is received
     * @param sourceID Sender GUID
     * @param uuid File GUID
     * @param commandHash Command Hash
     * @param params List of parameters
     * @param data File datat
     */
    void handle(String sourceID, String uuid, String commandHash, List<Parameter> params, byte[] data);
}
