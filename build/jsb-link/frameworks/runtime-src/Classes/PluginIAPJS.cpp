#include "PluginIAPJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginIAP/PluginIAP.h"

se::Object* __jsb_sdkbox_IAP_proto = nullptr;
se::Class* __jsb_sdkbox_IAP_class = nullptr;

static bool js_PluginIAPJS_IAP_purchase(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_purchase : Error processing arguments");
        sdkbox::IAP::purchase(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_purchase)

static bool js_PluginIAPJS_IAP_getInitializedErrMsg(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::IAP::getInitializedErrMsg();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_getInitializedErrMsg : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_getInitializedErrMsg)

static bool js_PluginIAPJS_IAP_updateStorePromotionVisibility(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_updateStorePromotionVisibility : Error processing arguments");
        sdkbox::IAP::updateStorePromotionVisibility(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_updateStorePromotionVisibility)

static bool js_PluginIAPJS_IAP_updateStorePromotionOrder(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_updateStorePromotionOrder : Error processing arguments");
        sdkbox::IAP::updateStorePromotionOrder(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_updateStorePromotionOrder)

static bool js_PluginIAPJS_IAP_restore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::restore();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_restore)

static bool js_PluginIAPJS_IAP_isAutoFinishTransaction(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::IAP::isAutoFinishTransaction();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_isAutoFinishTransaction : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_isAutoFinishTransaction)

static bool js_PluginIAPJS_IAP_fetchStorePromotionOrder(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::fetchStorePromotionOrder();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_fetchStorePromotionOrder)

static bool js_PluginIAPJS_IAP_refresh(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::refresh();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_refresh)

static bool js_PluginIAPJS_IAP_fetchStorePromotionVisibility(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_fetchStorePromotionVisibility : Error processing arguments");
        sdkbox::IAP::fetchStorePromotionVisibility(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_fetchStorePromotionVisibility)

static bool js_PluginIAPJS_IAP_setAutoFinishTransaction(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_setAutoFinishTransaction : Error processing arguments");
        sdkbox::IAP::setAutoFinishTransaction(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_setAutoFinishTransaction)

static bool js_PluginIAPJS_IAP_getPurchaseHistory(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::getPurchaseHistory();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_getPurchaseHistory)

static bool js_PluginIAPJS_IAP_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::IAP::init();
        return true;
    }
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= seval_to_std_string(args[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_init : Error processing arguments");
        sdkbox::IAP::init(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_init)

static bool js_PluginIAPJS_IAP_setDebug(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_setDebug : Error processing arguments");
        sdkbox::IAP::setDebug(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_setDebug)

static bool js_PluginIAPJS_IAP_requestUpdateTransaction(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::requestUpdateTransaction();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_requestUpdateTransaction)

static bool js_PluginIAPJS_IAP_enableUserSideVerification(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_enableUserSideVerification : Error processing arguments");
        sdkbox::IAP::enableUserSideVerification(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_enableUserSideVerification)

static bool js_PluginIAPJS_IAP_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_setGDPR : Error processing arguments");
        sdkbox::IAP::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_setGDPR)

static bool js_PluginIAPJS_IAP_finishTransaction(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginIAPJS_IAP_finishTransaction : Error processing arguments");
        sdkbox::IAP::finishTransaction(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_finishTransaction)

static bool js_PluginIAPJS_IAP_removeListener(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::IAP::removeListener();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginIAPJS_IAP_removeListener)



static bool js_sdkbox_IAP_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::IAP)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::IAP* cobj = (sdkbox::IAP*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_IAP_finalize)

bool js_register_PluginIAPJS_IAP(se::Object* obj)
{
    auto cls = se::Class::create("IAP", obj, nullptr, nullptr);

    cls->defineStaticFunction("purchase", _SE(js_PluginIAPJS_IAP_purchase));
    cls->defineStaticFunction("getInitializedErrMsg", _SE(js_PluginIAPJS_IAP_getInitializedErrMsg));
    cls->defineStaticFunction("updateStorePromotionVisibility", _SE(js_PluginIAPJS_IAP_updateStorePromotionVisibility));
    cls->defineStaticFunction("updateStorePromotionOrder", _SE(js_PluginIAPJS_IAP_updateStorePromotionOrder));
    cls->defineStaticFunction("restore", _SE(js_PluginIAPJS_IAP_restore));
    cls->defineStaticFunction("isAutoFinishTransaction", _SE(js_PluginIAPJS_IAP_isAutoFinishTransaction));
    cls->defineStaticFunction("fetchStorePromotionOrder", _SE(js_PluginIAPJS_IAP_fetchStorePromotionOrder));
    cls->defineStaticFunction("refresh", _SE(js_PluginIAPJS_IAP_refresh));
    cls->defineStaticFunction("fetchStorePromotionVisibility", _SE(js_PluginIAPJS_IAP_fetchStorePromotionVisibility));
    cls->defineStaticFunction("setAutoFinishTransaction", _SE(js_PluginIAPJS_IAP_setAutoFinishTransaction));
    cls->defineStaticFunction("getPurchaseHistory", _SE(js_PluginIAPJS_IAP_getPurchaseHistory));
    cls->defineStaticFunction("init", _SE(js_PluginIAPJS_IAP_init));
    cls->defineStaticFunction("setDebug", _SE(js_PluginIAPJS_IAP_setDebug));
    cls->defineStaticFunction("requestUpdateTransaction", _SE(js_PluginIAPJS_IAP_requestUpdateTransaction));
    cls->defineStaticFunction("enableUserSideVerification", _SE(js_PluginIAPJS_IAP_enableUserSideVerification));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginIAPJS_IAP_setGDPR));
    cls->defineStaticFunction("finishTransaction", _SE(js_PluginIAPJS_IAP_finishTransaction));
    cls->defineStaticFunction("removeListener", _SE(js_PluginIAPJS_IAP_removeListener));
    cls->defineFinalizeFunction(_SE(js_sdkbox_IAP_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::IAP>(cls);

    __jsb_sdkbox_IAP_proto = cls->getProto();
    __jsb_sdkbox_IAP_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginIAPJS(se::Object* obj)
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

    js_register_PluginIAPJS_IAP(ns);
    return true;
}

