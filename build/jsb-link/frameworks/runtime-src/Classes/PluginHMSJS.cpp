#include "PluginHMSJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginHMS/PluginHMS.h"

se::Object* __jsb_sdkbox_PluginHMS_proto = nullptr;
se::Class* __jsb_sdkbox_PluginHMS_class = nullptr;

static bool js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchases(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::iapRequestOwnedPurchases();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchases)

static bool js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchaseRecords(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::iapRequestOwnedPurchaseRecords();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchaseRecords)

static bool js_PluginHMSJS_PluginHMS_iapPurchase(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_iapPurchase : Error processing arguments");
        sdkbox::PluginHMS::iapPurchase(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapPurchase)

static bool js_PluginHMSJS_PluginHMS_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginHMS::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_init)

static bool js_PluginHMSJS_PluginHMS_logout(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::logout();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_logout)

static bool js_PluginHMSJS_PluginHMS_iapConsume(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_iapConsume : Error processing arguments");
        sdkbox::PluginHMS::iapConsume(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapConsume)

static bool js_PluginHMSJS_PluginHMS_iapRequestProducts(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::iapRequestProducts();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapRequestProducts)

static bool js_PluginHMSJS_PluginHMS_login(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_login : Error processing arguments");
        sdkbox::PluginHMS::login(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_login)

static bool js_PluginHMSJS_PluginHMS_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_setGDPR : Error processing arguments");
        sdkbox::PluginHMS::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_setGDPR)

static bool js_PluginHMSJS_PluginHMS_iapPurchaseWithPrice(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_iapPurchaseWithPrice : Error processing arguments");
        sdkbox::PluginHMS::iapPurchaseWithPrice(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_iapPurchaseWithPrice)



static bool js_sdkbox_PluginHMS_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginHMS)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginHMS* cobj = (sdkbox::PluginHMS*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginHMS_finalize)

bool js_register_PluginHMSJS_PluginHMS(se::Object* obj)
{
    auto cls = se::Class::create("PluginHMS", obj, nullptr, nullptr);

    cls->defineStaticFunction("iapRequestOwnedPurchases", _SE(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchases));
    cls->defineStaticFunction("iapRequestOwnedPurchaseRecords", _SE(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchaseRecords));
    cls->defineStaticFunction("iapPurchase", _SE(js_PluginHMSJS_PluginHMS_iapPurchase));
    cls->defineStaticFunction("init", _SE(js_PluginHMSJS_PluginHMS_init));
    cls->defineStaticFunction("logout", _SE(js_PluginHMSJS_PluginHMS_logout));
    cls->defineStaticFunction("iapConsume", _SE(js_PluginHMSJS_PluginHMS_iapConsume));
    cls->defineStaticFunction("iapRequestProducts", _SE(js_PluginHMSJS_PluginHMS_iapRequestProducts));
    cls->defineStaticFunction("login", _SE(js_PluginHMSJS_PluginHMS_login));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginHMSJS_PluginHMS_setGDPR));
    cls->defineStaticFunction("iapPurchaseWithPrice", _SE(js_PluginHMSJS_PluginHMS_iapPurchaseWithPrice));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginHMS_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginHMS>(cls);

    __jsb_sdkbox_PluginHMS_proto = cls->getProto();
    __jsb_sdkbox_PluginHMS_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginHMSJS(se::Object* obj)
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

    js_register_PluginHMSJS_PluginHMS(ns);
    return true;
}

