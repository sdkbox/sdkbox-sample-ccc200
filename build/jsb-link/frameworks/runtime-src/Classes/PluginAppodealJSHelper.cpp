
#include "PluginAppodealJSHelper.h"
#include "PluginAppodeal/PluginAppodeal.h"
#include "PluginAppodealJS.hpp"
#include "SDKBoxJSHelper.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"

class AppodealListenerJS : public sdkbox::AppodealListener, public sdkbox::JSListenerBase {
public:

    void onBannerDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onBannerDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onBannerDidClick() {
        invokeJSFun(__FUNCTION__);
    }

    void onBannerPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onInterstitialDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onInterstitialDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onInterstitialWillPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onInterstitialDidDismiss() {
        invokeJSFun(__FUNCTION__);
    }

    void onInterstitialDidClick() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoDidPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoWillDismiss() {
        invokeJSFun(__FUNCTION__);
    }

    void onVideoDidFinish() {
        invokeJSFun(__FUNCTION__);
    }

    void onRewardVideoDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onRewardVideoDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onRewardVideoDidPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onRewardVideoWillDismiss() {
        invokeJSFun(__FUNCTION__);
    }

    void onRewardVideoDidFinish(int amount, const std::string& name) {
        se::ValueArray args;
        args.reserve(2);
        args.push_back(se::Value(amount));
        args.push_back(se::Value(name));

        invokeJSFun(__FUNCTION__, args);
    }

    void onSkippableVideoDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onSkippableVideoDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onSkippableVideoDidPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onSkippableVideoWillDismiss() {
        invokeJSFun(__FUNCTION__);
    }

    void onSkippableVideoDidFinish() {
        invokeJSFun(__FUNCTION__);
    }

    void onSkippableVideoDidClick() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoDidLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoDidFailToLoadAd() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoDidPresent() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoWillDismiss() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoDidFinish() {
        invokeJSFun(__FUNCTION__);
    }

    void onNonSkippableVideoDidClick() {
        invokeJSFun(__FUNCTION__);
    }
};

static bool js_PluginAppodealJS_PluginAppodeal_setListener(se::State& s) {
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        AppodealListenerJS* nativeDelegate = new (std::nothrow) AppodealListenerJS();
        nativeDelegate->setJSDelegate(args[0]);
        sdkbox::PluginAppodeal::setListener(nativeDelegate);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setListener)

bool register_all_PluginAppodealJS_helper(se::Object* obj) {
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginAppodeal");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginAppodealJS_PluginAppodeal_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
