package de.awesome.smarthome.td.sound;

import de.awesome.smarthome.td.util.Wrapper;

/**
 * Created by Sebif on 27.03.2017.
 */
public class FmodSound {
    private long handle;

    public FmodSound(){
        handle = 0;
    }

    public native void setHandle(long handle);
    public native long getHandle();

    public native FmodResult getLength(Wrapper<Integer> length, int lengthType);

    public native FmodResult release();
}
