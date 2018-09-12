#include "PluginSdkboxAdsJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"

se::Object* __jsb_sdkbox_PluginSdkboxAds_proto = nullptr;
se::Class* __jsb_sdkbox_PluginSdkboxAds_class = nullptr;

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd : Error processing arguments");
        sdkbox::PluginSdkboxAds::hideAd(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd)

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_hide(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_hide : Error processing arguments");
        sdkbox::PluginSdkboxAds::hide(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_hide)

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_placement(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_placement : Error processing arguments");
        sdkbox::PluginSdkboxAds::placement(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_placement)

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_cache(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_cache : Error processing arguments");
        sdkbox::PluginSdkboxAds::cache(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_cache)

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxAds::init();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_init)

static bool js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable : Error processing arguments");
        bool result = sdkbox::PluginSdkboxAds::isAvailable(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable)



static bool js_sdkbox_PluginSdkboxAds_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginSdkboxAds)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginSdkboxAds* cobj = (sdkbox::PluginSdkboxAds*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginSdkboxAds_finalize)

bool js_register_PluginSdkboxAdsJS_PluginSdkboxAds(se::Object* obj)
{
    auto cls = se::Class::create("PluginSdkboxAds", obj, nullptr, nullptr);

    cls->defineStaticFunction("hideAd", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd));
    cls->defineStaticFunction("hide", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_hide));
    cls->defineStaticFunction("placement", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_placement));
    cls->defineStaticFunction("cache", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_cache));
    cls->defineStaticFunction("init", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_init));
    cls->defineStaticFunction("isAvailable", _SE(js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginSdkboxAds_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginSdkboxAds>(cls);

    __jsb_sdkbox_PluginSdkboxAds_proto = cls->getProto();
    __jsb_sdkbox_PluginSdkboxAds_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginSdkboxAdsJS(se::Object* obj)
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

    js_register_PluginSdkboxAdsJS_PluginSdkboxAds(ns);
    return true;
}

