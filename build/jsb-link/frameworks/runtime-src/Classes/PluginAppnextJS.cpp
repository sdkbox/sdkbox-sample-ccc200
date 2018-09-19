#include "PluginAppnextJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginAppnext/PluginAppnext.h"

se::Object* __jsb_sdkbox_PluginAppnext_proto = nullptr;
se::Class* __jsb_sdkbox_PluginAppnext_class = nullptr;

static bool js_PluginAppnextJS_PluginAppnext_hideAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAppnext::hideAd();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_hideAd)

static bool js_PluginAppnextJS_PluginAppnext_cacheAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_cacheAd : Error processing arguments");
        sdkbox::PluginAppnext::cacheAd(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_cacheAd)

static bool js_PluginAppnextJS_PluginAppnext_showVideo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_showVideo : Error processing arguments");
        sdkbox::PluginAppnext::showVideo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_showVideo)

static bool js_PluginAppnextJS_PluginAppnext_refreshAds(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAppnext::refreshAds();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_refreshAds)

static bool js_PluginAppnextJS_PluginAppnext_isVideoReady(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_isVideoReady : Error processing arguments");
        bool result = sdkbox::PluginAppnext::isVideoReady(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_isVideoReady : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_isVideoReady)

static bool js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsRewardTypeCurrency(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency)

static bool js_PluginAppnextJS_PluginAppnext_isAdReady(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginAppnext::isAdReady();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_isAdReady : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_isAdReady)

static bool js_PluginAppnextJS_PluginAppnext_refreshVideo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_refreshVideo : Error processing arguments");
        sdkbox::PluginAppnext::refreshVideo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_refreshVideo)

static bool js_PluginAppnextJS_PluginAppnext_cacheVideo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_cacheVideo : Error processing arguments");
        sdkbox::PluginAppnext::cacheVideo(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_cacheVideo)

static bool js_PluginAppnextJS_PluginAppnext_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginAppnext::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_init)

static bool js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsTransactionId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId)

static bool js_PluginAppnextJS_PluginAppnext_setRewardsUserId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_setRewardsUserId : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsUserId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_setRewardsUserId)

static bool js_PluginAppnextJS_PluginAppnext_showAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAppnext::showAd();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_showAd)

static bool js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsCustomParameter(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter)

static bool js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded : Error processing arguments");
        sdkbox::PluginAppnext::setRewardsAmountRewarded(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded)



static bool js_sdkbox_PluginAppnext_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginAppnext)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginAppnext* cobj = (sdkbox::PluginAppnext*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginAppnext_finalize)

bool js_register_PluginAppnextJS_PluginAppnext(se::Object* obj)
{
    auto cls = se::Class::create("PluginAppnext", obj, nullptr, nullptr);

    cls->defineStaticFunction("hideAd", _SE(js_PluginAppnextJS_PluginAppnext_hideAd));
    cls->defineStaticFunction("cacheAd", _SE(js_PluginAppnextJS_PluginAppnext_cacheAd));
    cls->defineStaticFunction("showVideo", _SE(js_PluginAppnextJS_PluginAppnext_showVideo));
    cls->defineStaticFunction("refreshAds", _SE(js_PluginAppnextJS_PluginAppnext_refreshAds));
    cls->defineStaticFunction("isVideoReady", _SE(js_PluginAppnextJS_PluginAppnext_isVideoReady));
    cls->defineStaticFunction("setRewardsRewardTypeCurrency", _SE(js_PluginAppnextJS_PluginAppnext_setRewardsRewardTypeCurrency));
    cls->defineStaticFunction("isAdReady", _SE(js_PluginAppnextJS_PluginAppnext_isAdReady));
    cls->defineStaticFunction("refreshVideo", _SE(js_PluginAppnextJS_PluginAppnext_refreshVideo));
    cls->defineStaticFunction("cacheVideo", _SE(js_PluginAppnextJS_PluginAppnext_cacheVideo));
    cls->defineStaticFunction("init", _SE(js_PluginAppnextJS_PluginAppnext_init));
    cls->defineStaticFunction("setRewardsTransactionId", _SE(js_PluginAppnextJS_PluginAppnext_setRewardsTransactionId));
    cls->defineStaticFunction("setRewardsUserId", _SE(js_PluginAppnextJS_PluginAppnext_setRewardsUserId));
    cls->defineStaticFunction("showAd", _SE(js_PluginAppnextJS_PluginAppnext_showAd));
    cls->defineStaticFunction("setRewardsCustomParameter", _SE(js_PluginAppnextJS_PluginAppnext_setRewardsCustomParameter));
    cls->defineStaticFunction("setRewardsAmountRewarded", _SE(js_PluginAppnextJS_PluginAppnext_setRewardsAmountRewarded));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginAppnext_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginAppnext>(cls);

    __jsb_sdkbox_PluginAppnext_proto = cls->getProto();
    __jsb_sdkbox_PluginAppnext_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginAppnextJS(se::Object* obj)
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

    js_register_PluginAppnextJS_PluginAppnext(ns);
    return true;
}

