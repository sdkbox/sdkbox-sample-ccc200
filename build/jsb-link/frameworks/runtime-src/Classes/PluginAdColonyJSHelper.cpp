#include "PluginAdColonyJSHelper.h"
#include "PluginAdColony/PluginAdColony.h"
#include "PluginAdColonyJS.hpp"
#include "SDKBoxJSHelper.h"

#include "scripting/js-bindings/manual/jsb_conversions.hpp"

static se::Value adinfo_to_jsobj(const sdkbox::AdColonyAdInfo& info) {
    se::Value ret;
    cocos2d::ValueMap map;
    map["name"] = cocos2d::Value(info.name);
    map["zoneID"] = cocos2d::Value(info.zoneID);
    map["shown"] = cocos2d::Value(info.shown);
    map["iapEnabled"] = cocos2d::Value(info.iapEnabled);
    map["iapProductID"] = cocos2d::Value(info.iapProductID);
    map["iapQuantity"] = cocos2d::Value(info.iapQuantity);
    map["iapEngagementType"] = cocos2d::Value(info.iapEngagementType);
    ccvaluemap_to_seval(map, &ret);
    return ret;
}

class AdColonyListenerJS : public sdkbox::AdColonyListener, public sdkbox::JSListenerBase
{
public:
    AdColonyListenerJS() : sdkbox::JSListenerBase() {
    }

    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(2);
        args.push_back(adinfo_to_jsobj(info));
        args.push_back(se::Value(available));
        invokeJSFun(__FUNCTION__, args);
    }

    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(4);
        args.push_back(adinfo_to_jsobj(info));
        args.push_back(se::Value(currencyName));
        args.push_back(se::Value(amount));
        args.push_back(se::Value(success));
        invokeJSFun(__FUNCTION__, args);
    }

    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(adinfo_to_jsobj(info));
        invokeJSFun(__FUNCTION__, args);
    }

    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.reserve(1);
        args.push_back(adinfo_to_jsobj(info));
        invokeJSFun(__FUNCTION__, args);
    }
};


static bool js_PluginAdColonyJS_PluginAdColony_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        AdColonyListenerJS* nativeDelegate = dynamic_cast<AdColonyListenerJS*>(sdkbox::PluginAdColony::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) AdColonyListenerJS();
            sdkbox::PluginAdColony::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_setListener)

bool register_all_PluginAdColonyJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginAdColony");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginAdColonyJS_PluginAdColony_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
