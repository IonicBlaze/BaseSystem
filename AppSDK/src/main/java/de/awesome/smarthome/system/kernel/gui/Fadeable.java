package de.awesome.smarthome.system.kernel.gui;

import de.awesome.smarthome.highlevelprotocols.qa.QAMessage;
import de.awesome.smarthome.system.kernel.Kernel;
import de.awesome.smarthome.system.kernel.ReturnCode;
import de.awesome.smarthome.system.kernel.Wrapper;
import de.awesome.smarthome.transport.Parameter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Sebif on 20.02.2017.
 */
public abstract class Fadeable {
    /**
     * Returns the alpha value of a fadeable render object
     * @param renderObjectID ID of the render object
     * @param outReturnCode General Return Code
     * @param outGuiReturnCode Gui Return Code
     * @param outAlpha Alpha value
     */
    public static void systemCallFadeableGet(
            int renderObjectID,
            Wrapper<ReturnCode> outReturnCode, Wrapper<GuiReturnCode> outGuiReturnCode,
            Wrapper<Byte> outAlpha
    ){

        List<Parameter> params = new ArrayList<>();
        params.add(Parameter.createInt(renderObjectID));
        QAMessage response = Kernel.systemCall("de.awesome.smarthome.td.systemcall.gui.fadeable.get",  params);

        outReturnCode.value = ReturnCode.getEnumValue(response.getParameters().get(0).getInt());
        outGuiReturnCode.value = GuiReturnCode.getEnumValue(response.getParameters().get(1).getInt());
        outAlpha.value = response.getParameters().get(2).getInt().byteValue();
    }

    /**
     * Sets the alpha value of a render object
     * @param renderObjectID ID of the render object
     * @param alpha Alpha value
     * @param outReturnCode General Return Code
     * @param outGuiReturnCode Gui Return Code
     */
    public static void systemCallFadeableSet(
            int renderObjectID, byte alpha,
            Wrapper<ReturnCode> outReturnCode, Wrapper<GuiReturnCode> outGuiReturnCode
    ){

        List<Parameter> params = new ArrayList<>();
        params.add(Parameter.createInt(renderObjectID));
        params.add(Parameter.createInt(alpha));
        QAMessage response = Kernel.systemCall("de.awesome.smarthome.td.systemcall.gui.fadeable.set", params);

        outReturnCode.value = ReturnCode.getEnumValue(response.getParameters().get(0).getInt());
        outGuiReturnCode.value = GuiReturnCode.getEnumValue(response.getParameters().get(1).getInt());
    }
}
