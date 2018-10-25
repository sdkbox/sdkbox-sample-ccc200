#include "PluginMiscJSHelper.h"
#include "PluginMisc/PluginMisc.h"
#include "SDKBoxJSHelper.h"

class MiscListenerJS : public sdkbox::MiscListener, public sdkbox::JSListenerBase
{
public:
    MiscListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onHandleLocalNotify(const std::string& payloadJson) {
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(payloadJson));
        invokeJSFun(__FUNCTION__, args);
    }

};

static bool js_PluginMiscJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        MiscListenerJS* nativeDelegate = dynamic_cast<MiscListenerJS*>(sdkbox::PluginMisc::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) MiscListenerJS();
            sdkbox::PluginMisc::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_setListener)

extern se::Object* __jsb_sdkbox_PluginMisc_proto;
extern se::Class* __jsb_sdkbox_PluginMisc_class;
bool register_all_PluginMiscJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginMisc");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginMiscJS_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

