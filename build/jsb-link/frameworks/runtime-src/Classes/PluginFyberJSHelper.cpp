
#include "PluginFyberJSHelper.h"
#include "SDKBoxJSHelper.h"
#include "PluginFyber/PluginFyber.h"

class FyberListenerJS : public sdkbox::FyberListener, public sdkbox::JSListenerBase
{
public:
    FyberListenerJS() : sdkbox::JSListenerBase() {
    }

    void onVirtualCurrencyConnectorFailed(int error,
                                          const std::string& errorCode,
                                          const std::string& errorMsg)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(error));
        args.push_back(se::Value(errorCode));
        args.push_back(se::Value(errorMsg));
        invokeJSFun(__FUNCTION__, args);
    }
    void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                           const std::string& currencyId,
                                           const std::string& currencyName,
                                           const std::string& transactionId)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(deltaOfCoins));
        args.push_back(se::Value(currencyId));
        args.push_back(se::Value(currencyName));
        args.push_back(se::Value(transactionId));
        invokeJSFun(__FUNCTION__, args);
    }
    void onCanShowInterstitial(bool canShowInterstitial)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(canShowInterstitial));
        invokeJSFun(__FUNCTION__, args);
    }
    void onInterstitialDidShow()
    {
        invokeJSFun(__FUNCTION__);
    }
    void onInterstitialDismiss(const std::string& reason)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(reason));
        invokeJSFun(__FUNCTION__, args);
    }
    void onInterstitialFailed()
    {
        invokeJSFun(__FUNCTION__);
    }

    void onBrandEngageClientReceiveOffers(bool areOffersAvailable)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(areOffersAvailable));
        invokeJSFun(__FUNCTION__, args);
    }
    void onBrandEngageClientChangeStatus(int status, const std::string& msg)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(status));
        args.push_back(se::Value(msg));
        invokeJSFun(__FUNCTION__, args);
    }

    void onOfferWallFinish(int status)
    {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(status));
        invokeJSFun(__FUNCTION__, args);
    }
};

void fyber_register_constants(se::Object* fyber)
{
    cocos2d::ValueMap enums;
    se::Value event;

    //  The device of the user
    enums["Undefined"] = sdkbox::FYB_UserDeviceUndefined;
    enums["IPhone"] = sdkbox::FYB_UserDeviceIPhone;
    enums["IPad"] = sdkbox::FYB_UserDeviceIPad;
    enums["IPod"] = sdkbox::FYB_UserDeviceIPod;
    enums["Android"] = sdkbox::FYB_UserDeviceAndroid;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserDevice", event);


    // UserConnectionType
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserConnectionTypeUndefined;
    enums["WiFi"] = sdkbox::FYB_UserConnectionTypeWiFi;
    enums["3G"] = sdkbox::FYB_UserConnectionType3G;
    enums["LTE"] = sdkbox::FYB_UserConnectionTypeLTE;
    enums["Edge"] = sdkbox::FYB_UserConnectionTypeEdge;
    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserConnectionType", event);

    // UserEducation
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserEducationUndefined;
    enums["Other"] = sdkbox::FYB_UserEducationOther;
    enums["None"] = sdkbox::FYB_UserEducationNone;
    enums["HighSchool"] = sdkbox::FYB_UserEducationHighSchool;
    enums["InCollege"] = sdkbox::FYB_UserEducationInCollege;
    enums["SomeCollege"] = sdkbox::FYB_UserEducationSomeCollege;
    enums["Associates"] = sdkbox::FYB_UserEducationAssociates;
    enums["Bachelors"] = sdkbox::FYB_UserEducationBachelors;
    enums["Masters"] = sdkbox::FYB_UserEducationMasters;
    enums["Doctorate"] = sdkbox::FYB_UserEducationDoctorate;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserEducation", event);

    // The marital status of the user
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserMaritalStatusUndefined;
    enums["Single"] = sdkbox::FYB_UserMartialStatusSingle;
    enums["Relationship"] = sdkbox::FYB_UserMartialStatusRelationship;
    enums["Married"] = sdkbox::FYB_UserMartialStatusMarried;
    enums["Divorced"] = sdkbox::FYB_UserMartialStatusDivorced;
    enums["Engaged"] = sdkbox::FYB_UserMartialStatusEngaged;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserMartialStatus", event);

    // The ethnicity of the user
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserEthnicityUndefined;
    enums["Asian"] = sdkbox::FYB_UserEthnicityAsian;
    enums["Black"] = sdkbox::FYB_UserEthnicityBlack;
    enums["Hispanic"] = sdkbox::FYB_UserEthnicityHispanic;
    enums["Indian"] = sdkbox::FYB_UserEthnicityIndian;
    enums["MiddleEastern"] = sdkbox::FYB_UserEthnicityMiddleEastern;
    enums["NativeAmerican"] = sdkbox::FYB_UserEthnicityNativeAmerican;
    enums["PacificIslander"] = sdkbox::FYB_UserEthnicityPacificIslander;
    enums["White"] = sdkbox::FYB_UserEthnicityWhite;
    enums["Other"] = sdkbox::FYB_UserEthnicityOther;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserEthnicity", event);

    // The gender of the user
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserGenderUndefined;
    enums["Male"] = sdkbox::FYB_UserGenderMale;
    enums["Female"] = sdkbox::FYB_UserGenderFemale;
    enums["Other"] = sdkbox::FYB_UserGenderOther;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserGender", event);

    // The sexual orientation of the user
    enums.clear();
    enums["Undefined"] = sdkbox::FYB_UserSexualOrientationUndefined;
    enums["Straight"] = sdkbox::FYB_UserSexualOrientationStraight;
    enums["Bisexual"] = sdkbox::FYB_UserSexualOrientationBisexual;
    enums["Gay"] = sdkbox::FYB_UserSexualOrientationGay;
    enums["Unknown"] = sdkbox::FYB_UserSexualOrientationUnknown;

    ccvaluemap_to_seval(enums, &event);
    fyber->setProperty("UserSexualOrientation", event);
}

static bool js_PluginFyberJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        FyberListenerJS* nativeDelegate = dynamic_cast<FyberListenerJS*>(sdkbox::PluginFyber::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) FyberListenerJS();
            sdkbox::PluginFyber::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_setListener)

extern se::Object* __jsb_sdkbox_PluginFyber_proto;
extern se::Class* __jsb_sdkbox_PluginFyber_class;
bool register_all_PluginFyberJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginFyber");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginFyberJS_setListener));
    fyber_register_constants(plugin);

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

