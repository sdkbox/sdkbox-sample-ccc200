#include "PluginShareJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginShare/PluginShare.h"

se::Object* __jsb_sdkbox_PluginShare_proto = nullptr;
se::Class* __jsb_sdkbox_PluginShare_class = nullptr;

static bool js_PluginShareJS_PluginShare_setSharePanelTitle(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_setSharePanelTitle : Error processing arguments");
        sdkbox::PluginShare::setSharePanelTitle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_setSharePanelTitle)

static bool js_PluginShareJS_PluginShare_setSharePanelCancel(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_setSharePanelCancel : Error processing arguments");
        sdkbox::PluginShare::setSharePanelCancel(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_setSharePanelCancel)

static bool js_PluginShareJS_PluginShare_setFileProviderAuthorities(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_setFileProviderAuthorities : Error processing arguments");
        sdkbox::PluginShare::setFileProviderAuthorities(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_setFileProviderAuthorities)

static bool js_PluginShareJS_PluginShare_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginShare::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_init : Error processing arguments");
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_init : Error processing arguments");
        bool result = sdkbox::PluginShare::init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_init)

static bool js_PluginShareJS_PluginShare_logoutTwitter(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginShare::logoutTwitter();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_logoutTwitter)

static bool js_PluginShareJS_PluginShare_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginShareJS_PluginShare_setGDPR : Error processing arguments");
        sdkbox::PluginShare::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_setGDPR)



static bool js_sdkbox_PluginShare_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginShare)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginShare* cobj = (sdkbox::PluginShare*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginShare_finalize)

bool js_register_PluginShareJS_PluginShare(se::Object* obj)
{
    auto cls = se::Class::create("PluginShare", obj, nullptr, nullptr);

    cls->defineStaticFunction("setSharePanelTitle", _SE(js_PluginShareJS_PluginShare_setSharePanelTitle));
    cls->defineStaticFunction("setSharePanelCancel", _SE(js_PluginShareJS_PluginShare_setSharePanelCancel));
    cls->defineStaticFunction("setFileProviderAuthorities", _SE(js_PluginShareJS_PluginShare_setFileProviderAuthorities));
    cls->defineStaticFunction("init", _SE(js_PluginShareJS_PluginShare_init));
    cls->defineStaticFunction("logoutTwitter", _SE(js_PluginShareJS_PluginShare_logoutTwitter));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginShareJS_PluginShare_setGDPR));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginShare_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginShare>(cls);

    __jsb_sdkbox_PluginShare_proto = cls->getProto();
    __jsb_sdkbox_PluginShare_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginShareJS(se::Object* obj)
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

    js_register_PluginShareJS_PluginShare(ns);
    return true;
}

