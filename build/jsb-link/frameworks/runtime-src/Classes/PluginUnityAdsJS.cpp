#include "PluginUnityAdsJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginUnityAds/PluginUnityAds.h"

se::Object* __jsb_sdkbox_PluginUnityAds_proto = nullptr;
se::Class* __jsb_sdkbox_PluginUnityAds_class = nullptr;

static bool js_PluginUnityAdsJS_PluginUnityAds_isSupported(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginUnityAds::isSupported();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_isSupported : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_isSupported)

static bool js_PluginUnityAdsJS_PluginUnityAds_isReady(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_isReady : Error processing arguments");
        bool result = sdkbox::PluginUnityAds::isReady(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_isReady : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_isReady)

static bool js_PluginUnityAdsJS_PluginUnityAds_getPlacementState(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_getPlacementState : Error processing arguments");
        unsigned int result = (unsigned int)sdkbox::PluginUnityAds::getPlacementState(arg0);
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_getPlacementState : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_getPlacementState)

static bool js_PluginUnityAdsJS_PluginUnityAds_show(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_show : Error processing arguments");
        sdkbox::PluginUnityAds::show(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_show)

static bool js_PluginUnityAdsJS_PluginUnityAds_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginUnityAds::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_init)

static bool js_PluginUnityAdsJS_PluginUnityAds_setServerId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_setServerId : Error processing arguments");
        sdkbox::PluginUnityAds::setServerId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_setServerId)

static bool js_PluginUnityAdsJS_PluginUnityAds_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginUnityAdsJS_PluginUnityAds_setGDPR : Error processing arguments");
        sdkbox::PluginUnityAds::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginUnityAdsJS_PluginUnityAds_setGDPR)



static bool js_sdkbox_PluginUnityAds_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginUnityAds)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginUnityAds* cobj = (sdkbox::PluginUnityAds*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginUnityAds_finalize)

bool js_register_PluginUnityAdsJS_PluginUnityAds(se::Object* obj)
{
    auto cls = se::Class::create("PluginUnityAds", obj, nullptr, nullptr);

    cls->defineStaticFunction("isSupported", _SE(js_PluginUnityAdsJS_PluginUnityAds_isSupported));
    cls->defineStaticFunction("isReady", _SE(js_PluginUnityAdsJS_PluginUnityAds_isReady));
    cls->defineStaticFunction("getPlacementState", _SE(js_PluginUnityAdsJS_PluginUnityAds_getPlacementState));
    cls->defineStaticFunction("show", _SE(js_PluginUnityAdsJS_PluginUnityAds_show));
    cls->defineStaticFunction("init", _SE(js_PluginUnityAdsJS_PluginUnityAds_init));
    cls->defineStaticFunction("setServerId", _SE(js_PluginUnityAdsJS_PluginUnityAds_setServerId));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginUnityAdsJS_PluginUnityAds_setGDPR));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginUnityAds_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginUnityAds>(cls);

    __jsb_sdkbox_PluginUnityAds_proto = cls->getProto();
    __jsb_sdkbox_PluginUnityAds_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginUnityAdsJS(se::Object* obj)
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

    js_register_PluginUnityAdsJS_PluginUnityAds(ns);
    return true;
}

