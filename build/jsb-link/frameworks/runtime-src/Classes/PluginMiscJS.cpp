#include "PluginMiscJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginMisc/PluginMisc.h"

se::Object* __jsb_sdkbox_PluginMisc_proto = nullptr;
se::Class* __jsb_sdkbox_PluginMisc_class = nullptr;

static bool js_PluginMiscJS_PluginMisc_setKeychainAccessGroup(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_setKeychainAccessGroup : Error processing arguments");
        sdkbox::PluginMisc::setKeychainAccessGroup(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_setKeychainAccessGroup)

static bool js_PluginMiscJS_PluginMisc_getAppVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginMisc::getAppVersion();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getAppVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getAppVersion)

static bool js_PluginMiscJS_PluginMisc_getMetaData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getMetaData : Error processing arguments");
        std::string result = sdkbox::PluginMisc::getMetaData(arg0);
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getMetaData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getMetaData)

static bool js_PluginMiscJS_PluginMisc_getAppVersionCode(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = sdkbox::PluginMisc::getAppVersionCode();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getAppVersionCode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getAppVersionCode)

static bool js_PluginMiscJS_PluginMisc_getPlatformName(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginMisc::getPlatformName();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getPlatformName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getPlatformName)

static bool js_PluginMiscJS_PluginMisc_getIAPProvider(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginMisc::getIAPProvider();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getIAPProvider : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getIAPProvider)

static bool js_PluginMiscJS_PluginMisc_setKeychainService(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_setKeychainService : Error processing arguments");
        sdkbox::PluginMisc::setKeychainService(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_setKeychainService)

static bool js_PluginMiscJS_PluginMisc_storeStringInKeychain(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_storeStringInKeychain : Error processing arguments");
        int result = sdkbox::PluginMisc::storeStringInKeychain(arg0, arg1);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_storeStringInKeychain : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_storeStringInKeychain)

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

static bool js_PluginMiscJS_PluginMisc_removeDataInKeychain(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_removeDataInKeychain : Error processing arguments");
        int result = sdkbox::PluginMisc::removeDataInKeychain(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_removeDataInKeychain : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_removeDataInKeychain)

static bool js_PluginMiscJS_PluginMisc_fetchStringInKeychain(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_fetchStringInKeychain : Error processing arguments");
        const std::string result = sdkbox::PluginMisc::fetchStringInKeychain(arg0);
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_fetchStringInKeychain : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_fetchStringInKeychain)

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

static bool js_PluginMiscJS_PluginMisc_getDeviceInfo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginMisc::getDeviceInfo();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getDeviceInfo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getDeviceInfo)

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

static bool js_PluginMiscJS_PluginMisc_getAppBuildVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginMisc::getAppBuildVersion();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_getAppBuildVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_getAppBuildVersion)

static bool js_PluginMiscJS_PluginMisc_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginMiscJS_PluginMisc_setGDPR : Error processing arguments");
        sdkbox::PluginMisc::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginMiscJS_PluginMisc_setGDPR)

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

    cls->defineStaticFunction("setKeychainAccessGroup", _SE(js_PluginMiscJS_PluginMisc_setKeychainAccessGroup));
    cls->defineStaticFunction("getAppVersion", _SE(js_PluginMiscJS_PluginMisc_getAppVersion));
    cls->defineStaticFunction("getMetaData", _SE(js_PluginMiscJS_PluginMisc_getMetaData));
    cls->defineStaticFunction("getAppVersionCode", _SE(js_PluginMiscJS_PluginMisc_getAppVersionCode));
    cls->defineStaticFunction("getPlatformName", _SE(js_PluginMiscJS_PluginMisc_getPlatformName));
    cls->defineStaticFunction("getIAPProvider", _SE(js_PluginMiscJS_PluginMisc_getIAPProvider));
    cls->defineStaticFunction("setKeychainService", _SE(js_PluginMiscJS_PluginMisc_setKeychainService));
    cls->defineStaticFunction("storeStringInKeychain", _SE(js_PluginMiscJS_PluginMisc_storeStringInKeychain));
    cls->defineStaticFunction("init", _SE(js_PluginMiscJS_PluginMisc_init));
    cls->defineStaticFunction("removeDataInKeychain", _SE(js_PluginMiscJS_PluginMisc_removeDataInKeychain));
    cls->defineStaticFunction("fetchStringInKeychain", _SE(js_PluginMiscJS_PluginMisc_fetchStringInKeychain));
    cls->defineStaticFunction("cleanLocalNotify", _SE(js_PluginMiscJS_PluginMisc_cleanLocalNotify));
    cls->defineStaticFunction("getDeviceInfo", _SE(js_PluginMiscJS_PluginMisc_getDeviceInfo));
    cls->defineStaticFunction("localNotify", _SE(js_PluginMiscJS_PluginMisc_localNotify));
    cls->defineStaticFunction("getAppBuildVersion", _SE(js_PluginMiscJS_PluginMisc_getAppBuildVersion));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginMiscJS_PluginMisc_setGDPR));
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

