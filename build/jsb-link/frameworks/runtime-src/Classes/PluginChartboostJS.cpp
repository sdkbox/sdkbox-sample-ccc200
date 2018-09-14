#include "PluginChartboostJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginChartboost/PluginChartboost.h"

se::Object* __jsb_sdkbox_PluginChartboost_proto = nullptr;
se::Class* __jsb_sdkbox_PluginChartboost_class = nullptr;

static bool js_PluginChartboostJS_PluginChartboost_handleOpenURL(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_handleOpenURL : Error processing arguments");
        bool result = sdkbox::PluginChartboost::handleOpenURL(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_handleOpenURL : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_handleOpenURL)

static bool js_PluginChartboostJS_PluginChartboost_restrictDataCollection(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_restrictDataCollection : Error processing arguments");
        sdkbox::PluginChartboost::restrictDataCollection(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_restrictDataCollection)

static bool js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::CB_StatusBarBehavior arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior : Error processing arguments");
        sdkbox::PluginChartboost::setStatusBarBehavior(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior)

static bool js_PluginChartboostJS_PluginChartboost_isAnyViewVisible(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginChartboost::isAnyViewVisible();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_isAnyViewVisible : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_isAnyViewVisible)

static bool js_PluginChartboostJS_PluginChartboost_getCustomID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginChartboost::getCustomID();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_getCustomID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_getCustomID)

static bool js_PluginChartboostJS_PluginChartboost_show(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_show : Error processing arguments");
        sdkbox::PluginChartboost::show(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_show)

static bool js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent : Error processing arguments");
        sdkbox::PluginChartboost::setShouldPrefetchVideoContent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent)

static bool js_PluginChartboostJS_PluginChartboost_cache(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_cache : Error processing arguments");
        sdkbox::PluginChartboost::cache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_cache)

static bool js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps : Error processing arguments");
        sdkbox::PluginChartboost::setShouldDisplayLoadingViewForMoreApps(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps)

static bool js_PluginChartboostJS_PluginChartboost_setAutoCacheAds(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setAutoCacheAds : Error processing arguments");
        sdkbox::PluginChartboost::setAutoCacheAds(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setAutoCacheAds)

static bool js_PluginChartboostJS_PluginChartboost_didPassAgeGate(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_didPassAgeGate : Error processing arguments");
        sdkbox::PluginChartboost::didPassAgeGate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_didPassAgeGate)

static bool js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession : Error processing arguments");
        sdkbox::PluginChartboost::setShouldRequestInterstitialsInFirstSession(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession)

static bool js_PluginChartboostJS_PluginChartboost_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginChartboost::init();
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_init : Error processing arguments");
        sdkbox::PluginChartboost::init(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_init)

static bool js_PluginChartboostJS_PluginChartboost_getAutoCacheAds(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginChartboost::getAutoCacheAds();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_getAutoCacheAds : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_getAutoCacheAds)

static bool js_PluginChartboostJS_PluginChartboost_closeImpression(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginChartboost::closeImpression();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_closeImpression)

static bool js_PluginChartboostJS_PluginChartboost_setCustomID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setCustomID : Error processing arguments");
        sdkbox::PluginChartboost::setCustomID(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setCustomID)

static bool js_PluginChartboostJS_PluginChartboost_isAvailable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_isAvailable : Error processing arguments");
        bool result = sdkbox::PluginChartboost::isAvailable(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_isAvailable : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_isAvailable)

static bool js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation : Error processing arguments");
        sdkbox::PluginChartboost::setShouldPauseClickForConfirmation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation)



static bool js_sdkbox_PluginChartboost_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginChartboost)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginChartboost* cobj = (sdkbox::PluginChartboost*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginChartboost_finalize)

bool js_register_PluginChartboostJS_PluginChartboost(se::Object* obj)
{
    auto cls = se::Class::create("PluginChartboost", obj, nullptr, nullptr);

    cls->defineStaticFunction("handleOpenURL", _SE(js_PluginChartboostJS_PluginChartboost_handleOpenURL));
    cls->defineStaticFunction("restrictDataCollection", _SE(js_PluginChartboostJS_PluginChartboost_restrictDataCollection));
    cls->defineStaticFunction("setStatusBarBehavior", _SE(js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior));
    cls->defineStaticFunction("isAnyViewVisible", _SE(js_PluginChartboostJS_PluginChartboost_isAnyViewVisible));
    cls->defineStaticFunction("getCustomID", _SE(js_PluginChartboostJS_PluginChartboost_getCustomID));
    cls->defineStaticFunction("show", _SE(js_PluginChartboostJS_PluginChartboost_show));
    cls->defineStaticFunction("setShouldPrefetchVideoContent", _SE(js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent));
    cls->defineStaticFunction("cache", _SE(js_PluginChartboostJS_PluginChartboost_cache));
    cls->defineStaticFunction("setShouldDisplayLoadingViewForMoreApps", _SE(js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps));
    cls->defineStaticFunction("setAutoCacheAds", _SE(js_PluginChartboostJS_PluginChartboost_setAutoCacheAds));
    cls->defineStaticFunction("didPassAgeGate", _SE(js_PluginChartboostJS_PluginChartboost_didPassAgeGate));
    cls->defineStaticFunction("setShouldRequestInterstitialsInFirstSession", _SE(js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession));
    cls->defineStaticFunction("init", _SE(js_PluginChartboostJS_PluginChartboost_init));
    cls->defineStaticFunction("getAutoCacheAds", _SE(js_PluginChartboostJS_PluginChartboost_getAutoCacheAds));
    cls->defineStaticFunction("closeImpression", _SE(js_PluginChartboostJS_PluginChartboost_closeImpression));
    cls->defineStaticFunction("setCustomID", _SE(js_PluginChartboostJS_PluginChartboost_setCustomID));
    cls->defineStaticFunction("isAvailable", _SE(js_PluginChartboostJS_PluginChartboost_isAvailable));
    cls->defineStaticFunction("setShouldPauseClickForConfirmation", _SE(js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginChartboost_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginChartboost>(cls);

    __jsb_sdkbox_PluginChartboost_proto = cls->getProto();
    __jsb_sdkbox_PluginChartboost_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginChartboostJS(se::Object* obj)
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

    js_register_PluginChartboostJS_PluginChartboost(ns);
    return true;
}

