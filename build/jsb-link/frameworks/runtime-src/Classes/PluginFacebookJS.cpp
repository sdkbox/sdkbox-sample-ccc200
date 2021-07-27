#include "PluginFacebookJS.hpp"
#ifdef SDKBOX_JSBINDING_CC3
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#else
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#endif
#include "PluginFacebook/PluginFacebook.h"

se::Object* __jsb_sdkbox_PluginFacebook_proto = nullptr;
se::Class* __jsb_sdkbox_PluginFacebook_class = nullptr;

static bool js_PluginFacebookJS_PluginFacebook_isLoggedIn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginFacebook::isLoggedIn();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_isLoggedIn : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_isLoggedIn)

static bool js_PluginFacebookJS_PluginFacebook_getSDKVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginFacebook::getSDKVersion();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_getSDKVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_getSDKVersion)

static bool js_PluginFacebookJS_PluginFacebook_getUserID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginFacebook::getUserID();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_getUserID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_getUserID)

static bool js_PluginFacebookJS_PluginFacebook_setLoginBehavior(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_setLoginBehavior : Error processing arguments");
        sdkbox::PluginFacebook::setLoginBehavior(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_setLoginBehavior)

static bool js_PluginFacebookJS_PluginFacebook_requestGift(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3);
        return true;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_requestGift)

static bool js_PluginFacebookJS_PluginFacebook_gameRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_gameRequest : Error processing arguments");
        sdkbox::PluginFacebook::gameRequest(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_gameRequest)

static bool js_PluginFacebookJS_PluginFacebook_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFacebook::init();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_init)

static bool js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix : Error processing arguments");
        sdkbox::PluginFacebook::setAppURLSchemeSuffix(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix)

static bool js_PluginFacebookJS_PluginFacebook_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_setGDPR : Error processing arguments");
        sdkbox::PluginFacebook::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_setGDPR)

static bool js_PluginFacebookJS_PluginFacebook_logEvent(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::logEvent(arg0, arg1);
            return true;
        }
    } while (false);
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::logEvent(arg0);
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_logEvent)

static bool js_PluginFacebookJS_PluginFacebook_logout(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFacebook::logout();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_logout)

static bool js_PluginFacebookJS_PluginFacebook_sendGift(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_sendGift : Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3);
        return true;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_sendGift : Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_sendGift)

static bool js_PluginFacebookJS_PluginFacebook_setAppId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_setAppId : Error processing arguments");
        sdkbox::PluginFacebook::setAppId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_setAppId)

static bool js_PluginFacebookJS_PluginFacebook_fetchFriends(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFacebook::fetchFriends();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_fetchFriends)

static bool js_PluginFacebookJS_PluginFacebook_logPurchase(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        std::string arg1;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_logPurchase : Error processing arguments");
        sdkbox::PluginFacebook::logPurchase(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_logPurchase)

static bool js_PluginFacebookJS_PluginFacebook_login(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            std::vector<std::string> arg0;
            ok &= seval_to_std_vector_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::login(arg0);
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            sdkbox::PluginFacebook::login();
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_login)

static bool js_PluginFacebookJS_PluginFacebook_getAccessToken(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginFacebook::getAccessToken();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_getAccessToken : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_getAccessToken)



static bool js_sdkbox_PluginFacebook_finalize(se::State& s)
{
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginFacebook* cobj = (sdkbox::PluginFacebook*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginFacebook_finalize)

bool js_register_PluginFacebookJS_PluginFacebook(se::Object* obj)
{
    auto cls = se::Class::create("PluginFacebook", obj, nullptr, nullptr);

    cls->defineStaticFunction("isLoggedIn", _SE(js_PluginFacebookJS_PluginFacebook_isLoggedIn));
    cls->defineStaticFunction("getSDKVersion", _SE(js_PluginFacebookJS_PluginFacebook_getSDKVersion));
    cls->defineStaticFunction("getUserID", _SE(js_PluginFacebookJS_PluginFacebook_getUserID));
    cls->defineStaticFunction("setLoginBehavior", _SE(js_PluginFacebookJS_PluginFacebook_setLoginBehavior));
    cls->defineStaticFunction("requestGift", _SE(js_PluginFacebookJS_PluginFacebook_requestGift));
    cls->defineStaticFunction("gameRequest", _SE(js_PluginFacebookJS_PluginFacebook_gameRequest));
    cls->defineStaticFunction("init", _SE(js_PluginFacebookJS_PluginFacebook_init));
    cls->defineStaticFunction("setAppURLSchemeSuffix", _SE(js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginFacebookJS_PluginFacebook_setGDPR));
    cls->defineStaticFunction("logEvent", _SE(js_PluginFacebookJS_PluginFacebook_logEvent));
    cls->defineStaticFunction("logout", _SE(js_PluginFacebookJS_PluginFacebook_logout));
    cls->defineStaticFunction("sendGift", _SE(js_PluginFacebookJS_PluginFacebook_sendGift));
    cls->defineStaticFunction("setAppId", _SE(js_PluginFacebookJS_PluginFacebook_setAppId));
    cls->defineStaticFunction("fetchFriends", _SE(js_PluginFacebookJS_PluginFacebook_fetchFriends));
    cls->defineStaticFunction("logPurchase", _SE(js_PluginFacebookJS_PluginFacebook_logPurchase));
    cls->defineStaticFunction("login", _SE(js_PluginFacebookJS_PluginFacebook_login));
    cls->defineStaticFunction("getAccessToken", _SE(js_PluginFacebookJS_PluginFacebook_getAccessToken));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginFacebook_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginFacebook>(cls);

    __jsb_sdkbox_PluginFacebook_proto = cls->getProto();
    __jsb_sdkbox_PluginFacebook_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginFacebookJS(se::Object* obj)
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

    js_register_PluginFacebookJS_PluginFacebook(ns);
    return true;
}

