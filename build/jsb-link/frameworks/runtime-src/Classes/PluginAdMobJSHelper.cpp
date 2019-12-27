
#include "PluginAdMobJSHelper.h"
#include "PluginAdMob/PluginAdMob.h"
#include "PluginAdMobJS.hpp"
#include "SDKBoxJSHelper.h"

class AdMobListenerJS : public sdkbox::AdMobListener, public sdkbox::JSListenerBase {
public:
    AdMobListenerJS() : sdkbox::JSListenerBase() {
    }

    void adViewDidReceiveAd(const std::string &name) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void adViewDidFailToReceiveAdWithError(const std::string &name, const std::string &msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(2);
        args.push_back(se::Value(name));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void adViewWillPresentScreen(const std::string &name) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFunNow(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void adViewDidDismissScreen(const std::string &name) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void adViewWillDismissScreen(const std::string &name) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void adViewWillLeaveApplication(const std::string &name) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    void reward(const std::string &name, const std::string &currency, double amount) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(3);
        args.push_back(se::Value(name));
        args.push_back(se::Value(currency));
        args.push_back(se::Value(amount));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
};

static bool js_PluginAdMobJS_PluginAdMob_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        AdMobListenerJS* nativeDelegate = dynamic_cast<AdMobListenerJS*>(sdkbox::PluginAdMob::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) AdMobListenerJS();
            sdkbox::PluginAdMob::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdMobJS_PluginAdMob_setListener)

bool register_all_PluginAdMobJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginAdMob");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginAdMobJS_PluginAdMob_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

