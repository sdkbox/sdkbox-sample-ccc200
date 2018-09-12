#include "SDKBoxJSHelper.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "PluginSdkboxAdsJSHelper.h"

class SdkboxAdsListenerJS : public sdkbox::PluginSdkboxAdsListener, public sdkbox::JSListenerBase
{
public:
    SdkboxAdsListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onAdAction( const std::string& ad_unit_id, const std::string& zone_place_location, sdkbox::AdActionType action_type) {
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(ad_unit_id));
        args.push_back(se::Value(zone_place_location));
        args.push_back(se::Value((int)action_type));
        invokeJSFun(__FUNCTION__, args);
    }

    virtual void onRewardAction( const std::string& ad_unit_id, const std::string& zone_place_location,
                                float reward_amount, bool reward_succeed) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(ad_unit_id));
        args.push_back(se::Value(zone_place_location));
        args.push_back(se::Value(reward_amount));
        args.push_back(se::Value(reward_succeed));
        invokeJSFun(__FUNCTION__, args);
    }
};

bool js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    bool ok = true;

    if (argc == 3) {

        std::string ad_unit;
        std::string ad_name;

        ok &= seval_to_std_string(args[0], &ad_unit);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");

        ok &= seval_to_std_string(args[1], &ad_name);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");

        std::map<std::string,std::string> req_args;
        ok &= seval_to_std_map_string_string(args[2], &req_args);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        sdkbox::PluginSdkboxAds::playAd( ad_unit, ad_name, req_args );

    } else if ( argc==2 ) {

        std::string ad_name;

        ok &= seval_to_std_string(args[0], &ad_name);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");


        if (args[1].isString()) {
            std::string ad_type;
            ok &= seval_to_std_string(args[1], &ad_type);
            SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : Error processing arguments");
            sdkbox::PluginSdkboxAds::playAd(ad_name, ad_type);
        } else if (args[1].isObject()) {
            std::map<std::string,std::string> req_args;
            ok &= seval_to_std_map_string_string(args[1], &req_args );
            SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd: Error processing arguments");

            sdkbox::PluginSdkboxAds::playAd( ad_name, req_args );
        }

    } else if ( argc==0 ) {

        sdkbox::PluginSdkboxAds::playAd( );

    } else {

        SE_REPORT_ERROR("js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd : wrong number of arguments");
    }

    return true;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd)

// bool js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl(se::State& s)
// {
//     const auto& args = s.args();
//     int argc = (int)args.size();
//     if (argc == 2) {
//         bool ok = true;

//         std::string ad_unit;
//         std::map<std::string,std::string> req_args;

//         ok &= seval_to_std_string(args[0], &ad_unit);
//         SE_PRECONDITION2(ok, false, "js_PluginSdkboxAds_cacheControl : Error processing arguments");

//         ok &= seval_to_std_map_string_string(args[1], &req_args );
//         SE_PRECONDITION2(ok, false, "js_PluginSdkboxAds_cacheControl : Error processing arguments");

//         sdkbox::PluginSdkboxAds::cacheControl( ad_unit, req_args );
//         return true;
//     }
//     SE_REPORT_ERROR("js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl : wrong number of arguments");
//     return false;
// }
// SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl)

static bool js_PluginSdkboxAdsJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        SdkboxAdsListenerJS* nativeDelegate = dynamic_cast<SdkboxAdsListenerJS*>(sdkbox::PluginSdkboxAds::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) SdkboxAdsListenerJS();
            sdkbox::PluginSdkboxAds::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_setListener)

extern se::Object* __jsb_sdkbox_PluginSdkboxAds_proto;
extern se::Class* __jsb_sdkbox_PluginSdkboxAds_class;
bool register_all_PluginSdkboxAdsJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginSdkboxAds");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginSdkboxAdsJS_setListener));
    plugin->defineFunction("playAd",      _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_playAd));
    // plugin->defineFunction("cacheControl",_SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_cacheControl));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}


