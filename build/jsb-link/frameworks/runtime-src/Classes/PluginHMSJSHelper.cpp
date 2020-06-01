#include "PluginHMSJSHelper.h"
#include "PluginHMS/PluginHMS.h"
#include "SDKBoxJSHelper.h"

extern se::Class* __jsb_sdkbox_PluginHMS_class;;

class HMSListenerJS : public sdkbox::HMSListener, public sdkbox::JSListenerBase {
public:
    HMSListenerJS() : sdkbox::JSListenerBase() {
    }

    void onLogin(int code, const std::string &msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }
    
    void onIAPReady(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPProducts(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPPurchase(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPPConsume(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onIAPOwnedPurchases(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onIAPOwnedPurchaseRecords(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

};

static bool js_PluginHMSJS_PluginHMS_setListener(se::State& s) {
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        HMSListenerJS* nativeDelegate = dynamic_cast<HMSListenerJS*>(sdkbox::PluginHMS::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) HMSListenerJS();
            sdkbox::PluginHMS::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_setListener)

bool register_all_PluginHMSJS_helper(se::Object* obj) {
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginHMS");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginHMSJS_PluginHMS_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
