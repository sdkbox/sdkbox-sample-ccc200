#include "PluginGoogleAnalyticsJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"

se::Object* __jsb_sdkbox_PluginGoogleAnalytics_proto = nullptr;
se::Class* __jsb_sdkbox_PluginGoogleAnalytics_class = nullptr;

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::createTracker(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setMetric(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setMetric : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setMetric(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setMetric)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopPeriodicalDispatch();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logECommerce(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::map<std::string, std::string> arg0;
        ok &= seval_to_std_map_string_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logECommerce : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logECommerce(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logECommerce)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setDryRun(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        int arg3 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logEvent(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableExceptionReporting(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableExceptionReporting : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableExceptionReporting(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableExceptionReporting)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::dispatchPeriodically(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::init();
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::init(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logScreen(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::startSession();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logException(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setUser(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setUser : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setUser(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setUser)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopSession();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDimension(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDimension : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setDimension(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDimension)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logSocial(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableAdvertisingTracking(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::dispatchHits();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableTracker(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker)

static bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        int arg1 = 0;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logTiming(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming)



static bool js_sdkbox_PluginGoogleAnalytics_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginGoogleAnalytics)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginGoogleAnalytics* cobj = (sdkbox::PluginGoogleAnalytics*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginGoogleAnalytics_finalize)

bool js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(se::Object* obj)
{
    auto cls = se::Class::create("PluginGoogleAnalytics", obj, nullptr, nullptr);

    cls->defineStaticFunction("createTracker", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker));
    cls->defineStaticFunction("setMetric", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setMetric));
    cls->defineStaticFunction("stopPeriodicalDispatch", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch));
    cls->defineStaticFunction("logECommerce", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logECommerce));
    cls->defineStaticFunction("setDryRun", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun));
    cls->defineStaticFunction("logEvent", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent));
    cls->defineStaticFunction("enableExceptionReporting", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableExceptionReporting));
    cls->defineStaticFunction("dispatchPeriodically", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically));
    cls->defineStaticFunction("init", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init));
    cls->defineStaticFunction("logScreen", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen));
    cls->defineStaticFunction("startSession", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession));
    cls->defineStaticFunction("logException", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException));
    cls->defineStaticFunction("setUser", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setUser));
    cls->defineStaticFunction("stopSession", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession));
    cls->defineStaticFunction("setDimension", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDimension));
    cls->defineStaticFunction("logSocial", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial));
    cls->defineStaticFunction("enableAdvertisingTracking", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking));
    cls->defineStaticFunction("dispatchHits", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits));
    cls->defineStaticFunction("enableTracker", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker));
    cls->defineStaticFunction("logTiming", _SE(js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginGoogleAnalytics_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginGoogleAnalytics>(cls);

    __jsb_sdkbox_PluginGoogleAnalytics_proto = cls->getProto();
    __jsb_sdkbox_PluginGoogleAnalytics_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginGoogleAnalyticsJS(se::Object* obj)
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

    js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(ns);
    return true;
}

