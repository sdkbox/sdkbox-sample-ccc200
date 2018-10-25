#include "PluginMiscJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginMisc/PluginMisc.h"

se::Object* __jsb_sdkbox_PluginMisc_proto = nullptr;
se::Class* __jsb_sdkbox_PluginMisc_class = nullptr;

static bool js_PluginMiscJS_PluginMisc_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginMisc::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_init)

static bool js_PluginMiscJS_PluginMisc_cleanLocalNotify(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginMisc::cleanLocalNotify();
        return true;
    }
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_cleanLocalNotify : Error processing arguments");
        sdkbox::PluginMisc::cleanLocalNotify(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_cleanLocalNotify)

static bool js_PluginMiscJS_PluginMisc_localNotify(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_localNotify : Error processing arguments");
        int result = sdkbox::PluginMisc::localNotify(arg0, arg1, arg2);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_localNotify : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_localNotify)

static bool js_PluginMiscJS_PluginMisc_handleLocalNotify(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_handleLocalNotify : Error processing arguments");
        sdkbox::PluginMisc::handleLocalNotify(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_handleLocalNotify)



static bool js_sdkbox_PluginMisc_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginMisc)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginMisc* cobj = (sdkbox::PluginMisc*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginMisc_finalize)

bool js_register_PluginMiscJS_PluginMisc(se::Object* obj)
{
    auto cls = se::Class::create("PluginMisc", obj, nullptr, nullptr);

    cls->defineStaticFunction("init", _SE(js_PluginMiscJS_PluginMisc_init));
    cls->defineStaticFunction("cleanLocalNotify", _SE(js_PluginMiscJS_PluginMisc_cleanLocalNotify));
    cls->defineStaticFunction("localNotify", _SE(js_PluginMiscJS_PluginMisc_localNotify));
    cls->defineStaticFunction("handleLocalNotify", _SE(js_PluginMiscJS_PluginMisc_handleLocalNotify));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginMisc_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginMisc>(cls);

    __jsb_sdkbox_PluginMisc_proto = cls->getProto();
    __jsb_sdkbox_PluginMisc_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginMiscJS(se::Object* obj)
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

    js_register_PluginMiscJS_PluginMisc(ns);
    return true;
}

