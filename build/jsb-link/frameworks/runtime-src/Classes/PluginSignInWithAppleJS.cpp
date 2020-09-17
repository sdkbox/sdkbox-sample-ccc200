#include "PluginSignInWithAppleJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginSignInWithApple/PluginSignInWithApple.h"

se::Object* __jsb_sdkbox_PluginSignInWithApple_proto = nullptr;
se::Class* __jsb_sdkbox_PluginSignInWithApple_class = nullptr;

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_signWithExistingAccount(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSignInWithApple::signWithExistingAccount();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_signWithExistingAccount)

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_sign(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSignInWithApple::sign();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_sign)

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginSignInWithApple::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSignInWithAppleJS_PluginSignInWithApple_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_init)

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_isAvailable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginSignInWithApple::isAvailable();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSignInWithAppleJS_PluginSignInWithApple_isAvailable : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_isAvailable)

static bool js_PluginSignInWithAppleJS_PluginSignInWithApple_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSignInWithAppleJS_PluginSignInWithApple_setGDPR : Error processing arguments");
        sdkbox::PluginSignInWithApple::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_setGDPR)



static bool js_sdkbox_PluginSignInWithApple_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginSignInWithApple)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginSignInWithApple* cobj = (sdkbox::PluginSignInWithApple*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginSignInWithApple_finalize)

bool js_register_PluginSignInWithAppleJS_PluginSignInWithApple(se::Object* obj)
{
    auto cls = se::Class::create("PluginSignInWithApple", obj, nullptr, nullptr);

    cls->defineStaticFunction("signWithExistingAccount", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_signWithExistingAccount));
    cls->defineStaticFunction("sign", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_sign));
    cls->defineStaticFunction("init", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_init));
    cls->defineStaticFunction("isAvailable", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_isAvailable));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginSignInWithAppleJS_PluginSignInWithApple_setGDPR));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginSignInWithApple_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginSignInWithApple>(cls);

    __jsb_sdkbox_PluginSignInWithApple_proto = cls->getProto();
    __jsb_sdkbox_PluginSignInWithApple_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginSignInWithAppleJS(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("sdkbox", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("sdkbox", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_PluginSignInWithAppleJS_PluginSignInWithApple(ns);
    return true;
}

