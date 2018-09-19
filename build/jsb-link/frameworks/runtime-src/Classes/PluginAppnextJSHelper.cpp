#include "PluginAppnextJSHelper.h"
#include "PluginAppnext/PluginAppnext.h"
#include "SDKBoxJSHelper.h"

class AppnextListenerJS : public sdkbox::AppnextListener, public sdkbox::JSListenerBase
{
public:
    AppnextListenerJS() : sdkbox::JSListenerBase() {
    }

    void onAdError(const std::string& msg) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(msg));
        invokeJSFun(__FUNCTION__, args);
    }
    void onAdLoaded() {
        invokeJSFun(__FUNCTION__);
    }
    void onAdOpened() {
        invokeJSFun(__FUNCTION__);
    }
    void onAdClosed() {
        invokeJSFun(__FUNCTION__);
    }
    void onAdClicked() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoLoaded(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onVideoClicked(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onVideoClosed(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onVideoEnded(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onVideoError(const std::string& name, const std::string& msg) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        args.push_back(se::Value(msg));
        invokeJSFun(__FUNCTION__, args);
    }
};

static bool js_PluginAppnextJS_PluginAgeCheq_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        AppnextListenerJS* nativeDelegate = dynamic_cast<AppnextListenerJS*>(sdkbox::PluginAppnext::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) AppnextListenerJS();
            sdkbox::PluginAppnext::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAgeCheq_setListener)

extern se::Object* __jsb_sdkbox_PluginAppnext_proto;
extern se::Class* __jsb_sdkbox_PluginAppnext_class;
bool register_all_PluginAppnextJS_helper(se::Object* obj)
{
    cocos2d::ValueMap enums;
    enums["AdOrientation_AutoDetect"] = 0;
    enums["AdOrientation_Landscape"] = 1;
    enums["AdOrientation_Portrait"] = 2;

    se::Value constants;
    ccvaluemap_to_seval(enums, &constants);

    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginAppnext");
    auto plugin = pluginValue.toObject();
    plugin->setProperty("AdOrientation", constants);
    plugin->defineFunction("setListener", _SE(js_PluginAppnextJS_PluginAgeCheq_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
