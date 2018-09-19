#include "PluginApteligentJSHelper.h"
#include "PluginApteligent/PluginApteligent.h"
#include "SDKBoxJSHelper.h"

class ApteligentListenerJS : public sdkbox::ApteligentListener, public sdkbox::JSListenerBase
{
public:
    ApteligentListenerJS() : sdkbox::JSListenerBase() {
    }

    void onCrashOnLastLoad() {
        invokeJSFun(__FUNCTION__);
    }
};

static bool js_PluginApteligentJS_PluginAgeCheq_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        ApteligentListenerJS* nativeDelegate = dynamic_cast<ApteligentListenerJS*>(sdkbox::PluginApteligent::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) ApteligentListenerJS();
            sdkbox::PluginApteligent::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginAgeCheq_setListener)

extern se::Object* __jsb_sdkbox_PluginApteligent_proto;
extern se::Class* __jsb_sdkbox_PluginApteligent_class;
bool register_all_PluginApteligentJS_helper(se::Object* obj)
{
    cocos2d::ValueMap enums;
    enums["Silent"] = sdkbox::CRLoggingLevelSilent;
    enums["Error"] = sdkbox::CRLoggingLevelError;
    enums["Warning"] = sdkbox::CRLoggingLevelWarning;
    enums["Info"] = sdkbox::CRLoggingLevelInfo;

    se::Value constants;
    ccvaluemap_to_seval(enums, &constants);

    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginApteligent");
    auto plugin = pluginValue.toObject();
    plugin->setProperty("LoggingLevel", constants);
    plugin->defineFunction("setListener", _SE(js_PluginApteligentJS_PluginAgeCheq_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

