#include "PluginSignInWithAppleJSHelper.h"
#include "PluginSignInWithApple/PluginSignInWithApple.h"
#include "SDKBoxJSHelper.h"

extern se::Class* __jsb_sdkbox_PluginSignInWithApple_class;;

class SignInWithAppleListenerJS : public sdkbox::SignInWithAppleListener, public sdkbox::JSListenerBase
{
public:
    SignInWithAppleListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onAuthorizationDidComplete(const std::string& authInfo) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(authInfo));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onAuthorizationCompleteWithError(const std::string& authInfo) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(authInfo));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onAuthorizationStatus(const std::string& authState) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.reserve(1);
        args.push_back(se::Value(authState));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

};

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        SignInWithAppleListenerJS* nativeDelegate = dynamic_cast<SignInWithAppleListenerJS*>(sdkbox::PluginSignInWithApple::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) SignInWithAppleListenerJS();
            sdkbox::PluginSignInWithApple::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_setListener)

bool register_all_PluginSignInWithAppleJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginSignInWithApple");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
