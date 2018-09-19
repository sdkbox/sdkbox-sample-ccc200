#include "PluginApteligentJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginApteligent/PluginApteligent.h"

se::Object* __jsb_sdkbox_PluginApteligent_proto = nullptr;
se::Class* __jsb_sdkbox_PluginApteligent_class = nullptr;

static bool js_PluginApteligentJS_PluginApteligent_beginUserflow(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            int arg1 = 0;
            ok &= seval_to_int32(args[1], (int32_t*)&arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginApteligent::beginUserflow(arg0, arg1);
            return true;
        }
    } while (false);
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginApteligent::beginUserflow(arg0);
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_beginUserflow)

static bool js_PluginApteligentJS_PluginApteligent_setLoggingLevel(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setLoggingLevel : Error processing arguments");
        sdkbox::PluginApteligent::setLoggingLevel(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setLoggingLevel)

static bool js_PluginApteligentJS_PluginApteligent_setOptOutStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setOptOutStatus : Error processing arguments");
        sdkbox::PluginApteligent::setOptOutStatus(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setOptOutStatus)

static bool js_PluginApteligentJS_PluginApteligent_setValueforKey(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setValueforKey : Error processing arguments");
        sdkbox::PluginApteligent::setValueforKey(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setValueforKey)

static bool js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode : Error processing arguments");
        sdkbox::PluginApteligent::setAsyncBreadcrumbMode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode)

static bool js_PluginApteligentJS_PluginApteligent_endUserflow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_endUserflow : Error processing arguments");
        sdkbox::PluginApteligent::endUserflow(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_endUserflow)

static bool js_PluginApteligentJS_PluginApteligent_setUsername(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setUsername : Error processing arguments");
        sdkbox::PluginApteligent::setUsername(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setUsername)

static bool js_PluginApteligentJS_PluginApteligent_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginApteligent::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_init)

static bool js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = sdkbox::PluginApteligent::maxOfflineCrashReports();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports)

static bool js_PluginApteligentJS_PluginApteligent_updateLocation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= seval_to_double(args[0], &arg0);
        ok &= seval_to_double(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_updateLocation : Error processing arguments");
        sdkbox::PluginApteligent::updateLocation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_updateLocation)

static bool js_PluginApteligentJS_PluginApteligent_valueForUserflow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_valueForUserflow : Error processing arguments");
        int result = sdkbox::PluginApteligent::valueForUserflow(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_valueForUserflow : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_valueForUserflow)

static bool js_PluginApteligentJS_PluginApteligent_logNetworkRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        long arg2 = 0;
        long arg3 = 0;
        long arg4 = 0;
        long arg5 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_long(args[2], &arg2);
        ok &= seval_to_long(args[3], &arg3);
        ok &= seval_to_long(args[4], &arg4);
        ok &= seval_to_long(args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_logNetworkRequest : Error processing arguments");
        bool result = sdkbox::PluginApteligent::logNetworkRequest(arg0, arg1, arg2, arg3, arg4, arg5);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_logNetworkRequest : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_logNetworkRequest)

static bool js_PluginApteligentJS_PluginApteligent_sendAppLoadData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginApteligent::sendAppLoadData();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_sendAppLoadData)

static bool js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports : Error processing arguments");
        sdkbox::PluginApteligent::setMaxOfflineCrashReports(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports)

static bool js_PluginApteligentJS_PluginApteligent_getUserUUID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginApteligent::getUserUUID();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_getUserUUID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_getUserUUID)

static bool js_PluginApteligentJS_PluginApteligent_cancelUserflow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_cancelUserflow : Error processing arguments");
        sdkbox::PluginApteligent::cancelUserflow(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_cancelUserflow)

static bool js_PluginApteligentJS_PluginApteligent_setValueforUserflow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_setValueforUserflow : Error processing arguments");
        sdkbox::PluginApteligent::setValueforUserflow(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_setValueforUserflow)

static bool js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginApteligent::didCrashOnLastLoad();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad)

static bool js_PluginApteligentJS_PluginApteligent_addFilter(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_addFilter : Error processing arguments");
        sdkbox::PluginApteligent::addFilter(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_addFilter)

static bool js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb : Error processing arguments");
        sdkbox::PluginApteligent::leaveBreadcrumb(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb)

static bool js_PluginApteligentJS_PluginApteligent_getOptOutStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginApteligent::getOptOutStatus();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_getOptOutStatus : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_getOptOutStatus)

static bool js_PluginApteligentJS_PluginApteligent_failUserflow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginApteligentJS_PluginApteligent_failUserflow : Error processing arguments");
        sdkbox::PluginApteligent::failUserflow(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginApteligentJS_PluginApteligent_failUserflow)



static bool js_sdkbox_PluginApteligent_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginApteligent)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginApteligent* cobj = (sdkbox::PluginApteligent*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginApteligent_finalize)

bool js_register_PluginApteligentJS_PluginApteligent(se::Object* obj)
{
    auto cls = se::Class::create("PluginApteligent", obj, nullptr, nullptr);

    cls->defineStaticFunction("beginUserflow", _SE(js_PluginApteligentJS_PluginApteligent_beginUserflow));
    cls->defineStaticFunction("setLoggingLevel", _SE(js_PluginApteligentJS_PluginApteligent_setLoggingLevel));
    cls->defineStaticFunction("setOptOutStatus", _SE(js_PluginApteligentJS_PluginApteligent_setOptOutStatus));
    cls->defineStaticFunction("setValueforKey", _SE(js_PluginApteligentJS_PluginApteligent_setValueforKey));
    cls->defineStaticFunction("setAsyncBreadcrumbMode", _SE(js_PluginApteligentJS_PluginApteligent_setAsyncBreadcrumbMode));
    cls->defineStaticFunction("endUserflow", _SE(js_PluginApteligentJS_PluginApteligent_endUserflow));
    cls->defineStaticFunction("setUsername", _SE(js_PluginApteligentJS_PluginApteligent_setUsername));
    cls->defineStaticFunction("init", _SE(js_PluginApteligentJS_PluginApteligent_init));
    cls->defineStaticFunction("maxOfflineCrashReports", _SE(js_PluginApteligentJS_PluginApteligent_maxOfflineCrashReports));
    cls->defineStaticFunction("updateLocation", _SE(js_PluginApteligentJS_PluginApteligent_updateLocation));
    cls->defineStaticFunction("valueForUserflow", _SE(js_PluginApteligentJS_PluginApteligent_valueForUserflow));
    cls->defineStaticFunction("logNetworkRequest", _SE(js_PluginApteligentJS_PluginApteligent_logNetworkRequest));
    cls->defineStaticFunction("sendAppLoadData", _SE(js_PluginApteligentJS_PluginApteligent_sendAppLoadData));
    cls->defineStaticFunction("setMaxOfflineCrashReports", _SE(js_PluginApteligentJS_PluginApteligent_setMaxOfflineCrashReports));
    cls->defineStaticFunction("getUserUUID", _SE(js_PluginApteligentJS_PluginApteligent_getUserUUID));
    cls->defineStaticFunction("cancelUserflow", _SE(js_PluginApteligentJS_PluginApteligent_cancelUserflow));
    cls->defineStaticFunction("setValueforUserflow", _SE(js_PluginApteligentJS_PluginApteligent_setValueforUserflow));
    cls->defineStaticFunction("didCrashOnLastLoad", _SE(js_PluginApteligentJS_PluginApteligent_didCrashOnLastLoad));
    cls->defineStaticFunction("addFilter", _SE(js_PluginApteligentJS_PluginApteligent_addFilter));
    cls->defineStaticFunction("leaveBreadcrumb", _SE(js_PluginApteligentJS_PluginApteligent_leaveBreadcrumb));
    cls->defineStaticFunction("getOptOutStatus", _SE(js_PluginApteligentJS_PluginApteligent_getOptOutStatus));
    cls->defineStaticFunction("failUserflow", _SE(js_PluginApteligentJS_PluginApteligent_failUserflow));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginApteligent_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginApteligent>(cls);

    __jsb_sdkbox_PluginApteligent_proto = cls->getProto();
    __jsb_sdkbox_PluginApteligent_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginApteligentJS(se::Object* obj)
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

    js_register_PluginApteligentJS_PluginApteligent(ns);
    return true;
}

