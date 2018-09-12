#include "PluginReviewJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginReview/PluginReview.h"

se::Object* __jsb_sdkbox_PluginReview_proto = nullptr;
se::Class* __jsb_sdkbox_PluginReview_class = nullptr;

static bool js_PluginReviewJS_PluginReview_userDidSignificantEvent(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginReviewJS_PluginReview_userDidSignificantEvent : Error processing arguments");
        sdkbox::PluginReview::userDidSignificantEvent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginReviewJS_PluginReview_userDidSignificantEvent)

static bool js_PluginReviewJS_PluginReview_show(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginReview::show();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginReviewJS_PluginReview_show : Error processing arguments");
        sdkbox::PluginReview::show(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginReviewJS_PluginReview_show)

static bool js_PluginReviewJS_PluginReview_rate(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginReview::rate();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginReviewJS_PluginReview_rate)

static bool js_PluginReviewJS_PluginReview_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginReview::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginReviewJS_PluginReview_init : Error processing arguments");
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginReviewJS_PluginReview_init : Error processing arguments");
        bool result = sdkbox::PluginReview::init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginReviewJS_PluginReview_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginReviewJS_PluginReview_init)



static bool js_sdkbox_PluginReview_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginReview)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginReview* cobj = (sdkbox::PluginReview*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginReview_finalize)

bool js_register_PluginReviewJS_PluginReview(se::Object* obj)
{
    auto cls = se::Class::create("PluginReview", obj, nullptr, nullptr);

    cls->defineStaticFunction("userDidSignificantEvent", _SE(js_PluginReviewJS_PluginReview_userDidSignificantEvent));
    cls->defineStaticFunction("show", _SE(js_PluginReviewJS_PluginReview_show));
    cls->defineStaticFunction("rate", _SE(js_PluginReviewJS_PluginReview_rate));
    cls->defineStaticFunction("init", _SE(js_PluginReviewJS_PluginReview_init));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginReview_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginReview>(cls);

    __jsb_sdkbox_PluginReview_proto = cls->getProto();
    __jsb_sdkbox_PluginReview_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginReviewJS(se::Object* obj)
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

    js_register_PluginReviewJS_PluginReview(ns);
    return true;
}

