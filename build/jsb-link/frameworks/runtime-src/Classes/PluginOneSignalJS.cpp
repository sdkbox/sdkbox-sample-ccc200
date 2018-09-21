#include "PluginOneSignalJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginOneSignal/PluginOneSignal.h"

se::Object* __jsb_sdkbox_PluginOneSignal_proto = nullptr;
se::Class* __jsb_sdkbox_PluginOneSignal_class = nullptr;

static bool js_PluginOneSignalJS_PluginOneSignal_getTags(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginOneSignal::getTags();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_getTags)

static bool js_PluginOneSignalJS_PluginOneSignal_enableInAppAlertNotification(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_enableInAppAlertNotification : Error processing arguments");
        sdkbox::PluginOneSignal::enableInAppAlertNotification(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_enableInAppAlertNotification)

static bool js_PluginOneSignalJS_PluginOneSignal_postNotification(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_postNotification : Error processing arguments");
        sdkbox::PluginOneSignal::postNotification(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_postNotification)

static bool js_PluginOneSignalJS_PluginOneSignal_setLogLevel(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_setLogLevel : Error processing arguments");
        sdkbox::PluginOneSignal::setLogLevel(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_setLogLevel)

static bool js_PluginOneSignalJS_PluginOneSignal_idsAvailable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginOneSignal::idsAvailable();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_idsAvailable)

static bool js_PluginOneSignalJS_PluginOneSignal_setEmail(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_setEmail : Error processing arguments");
        sdkbox::PluginOneSignal::setEmail(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_setEmail)

static bool js_PluginOneSignalJS_PluginOneSignal_promptLocation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginOneSignal::promptLocation();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_promptLocation)

static bool js_PluginOneSignalJS_PluginOneSignal_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginOneSignal::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_init)

static bool js_PluginOneSignalJS_PluginOneSignal_registerForPushNotifications(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginOneSignal::registerForPushNotifications();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_registerForPushNotifications)

static bool js_PluginOneSignalJS_PluginOneSignal_deleteTag(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_deleteTag : Error processing arguments");
        sdkbox::PluginOneSignal::deleteTag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_deleteTag)

static bool js_PluginOneSignalJS_PluginOneSignal_setSubscription(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_setSubscription : Error processing arguments");
        sdkbox::PluginOneSignal::setSubscription(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_setSubscription)

static bool js_PluginOneSignalJS_PluginOneSignal_sendTag(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginOneSignalJS_PluginOneSignal_sendTag : Error processing arguments");
        sdkbox::PluginOneSignal::sendTag(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginOneSignalJS_PluginOneSignal_sendTag)



static bool js_sdkbox_PluginOneSignal_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginOneSignal)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginOneSignal* cobj = (sdkbox::PluginOneSignal*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginOneSignal_finalize)

bool js_register_PluginOneSignalJS_PluginOneSignal(se::Object* obj)
{
    auto cls = se::Class::create("PluginOneSignal", obj, nullptr, nullptr);

    cls->defineStaticFunction("getTags", _SE(js_PluginOneSignalJS_PluginOneSignal_getTags));
    cls->defineStaticFunction("enableInAppAlertNotification", _SE(js_PluginOneSignalJS_PluginOneSignal_enableInAppAlertNotification));
    cls->defineStaticFunction("postNotification", _SE(js_PluginOneSignalJS_PluginOneSignal_postNotification));
    cls->defineStaticFunction("setLogLevel", _SE(js_PluginOneSignalJS_PluginOneSignal_setLogLevel));
    cls->defineStaticFunction("idsAvailable", _SE(js_PluginOneSignalJS_PluginOneSignal_idsAvailable));
    cls->defineStaticFunction("setEmail", _SE(js_PluginOneSignalJS_PluginOneSignal_setEmail));
    cls->defineStaticFunction("promptLocation", _SE(js_PluginOneSignalJS_PluginOneSignal_promptLocation));
    cls->defineStaticFunction("init", _SE(js_PluginOneSignalJS_PluginOneSignal_init));
    cls->defineStaticFunction("registerForPushNotifications", _SE(js_PluginOneSignalJS_PluginOneSignal_registerForPushNotifications));
    cls->defineStaticFunction("deleteTag", _SE(js_PluginOneSignalJS_PluginOneSignal_deleteTag));
    cls->defineStaticFunction("setSubscription", _SE(js_PluginOneSignalJS_PluginOneSignal_setSubscription));
    cls->defineStaticFunction("sendTag", _SE(js_PluginOneSignalJS_PluginOneSignal_sendTag));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginOneSignal_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginOneSignal>(cls);

    __jsb_sdkbox_PluginOneSignal_proto = cls->getProto();
    __jsb_sdkbox_PluginOneSignal_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginOneSignalJS(se::Object* obj)
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

    js_register_PluginOneSignalJS_PluginOneSignal(ns);
    return true;
}

