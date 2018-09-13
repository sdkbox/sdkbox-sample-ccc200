#include "PluginAdColonyJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginAdColony/PluginAdColony.h"

se::Object* __jsb_sdkbox_PluginAdColony_proto = nullptr;
se::Class* __jsb_sdkbox_PluginAdColony_class = nullptr;

static bool js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone : Error processing arguments");
        int result = sdkbox::PluginAdColony::zoneStatusForZone(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone)

static bool js_PluginAdColonyJS_PluginAdColony_show(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_show : Error processing arguments");
        sdkbox::PluginAdColony::show(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_show)

static bool js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginAdColony::getUniqueDeviceID();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID)

static bool js_PluginAdColonyJS_PluginAdColony_getStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getStatus : Error processing arguments");
        unsigned int result = (unsigned int)sdkbox::PluginAdColony::getStatus(arg0);
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getStatus : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getStatus)

static bool js_PluginAdColonyJS_PluginAdColony_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAdColony::init();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_init)

static bool js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginAdColony::videoAdCurrentlyRunning();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning)

static bool js_PluginAdColonyJS_PluginAdColony_setUserMetadata(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_setUserMetadata : Error processing arguments");
        sdkbox::PluginAdColony::setUserMetadata(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_setUserMetadata)

static bool js_PluginAdColonyJS_PluginAdColony_setGDPR(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_setGDPR : Error processing arguments");
        sdkbox::PluginAdColony::setGDPR(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_setGDPR)

static bool js_PluginAdColonyJS_PluginAdColony_getCustomID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginAdColony::getCustomID();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getCustomID : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getCustomID)

static bool js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginAdColony::getAdvertisingIdentifier();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier)

static bool js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAdColony::turnAllAdsOff();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff)

static bool js_PluginAdColonyJS_PluginAdColony_requestAllAds(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAdColony::requestAllAds();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_requestAllAds)

static bool js_PluginAdColonyJS_PluginAdColony_setCustomID(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_setCustomID : Error processing arguments");
        sdkbox::PluginAdColony::setCustomID(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_setCustomID)

static bool js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance : Error processing arguments");
        int result = sdkbox::PluginAdColony::getVideoCreditBalance(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance)

static bool js_PluginAdColonyJS_PluginAdColony_getVideosPerReward(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getVideosPerReward : Error processing arguments");
        int result = sdkbox::PluginAdColony::getVideosPerReward(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getVideosPerReward : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getVideosPerReward)

static bool js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginAdColony::getVendorIdentifier();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier)

static bool js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        int arg2 = 0;
        float arg3 = 0;
        std::string arg4;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_float(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete : Error processing arguments");
        sdkbox::PluginAdColony::notifyIAPComplete(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete)

static bool js_PluginAdColonyJS_PluginAdColony_userInterestedIn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAdColonyJS_PluginAdColony_userInterestedIn : Error processing arguments");
        sdkbox::PluginAdColony::userInterestedIn(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_userInterestedIn)

static bool js_PluginAdColonyJS_PluginAdColony_cancelAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAdColony::cancelAd();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAdColonyJS_PluginAdColony_cancelAd)



static bool js_sdkbox_PluginAdColony_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginAdColony)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginAdColony* cobj = (sdkbox::PluginAdColony*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginAdColony_finalize)

bool js_register_PluginAdColonyJS_PluginAdColony(se::Object* obj)
{
    auto cls = se::Class::create("PluginAdColony", obj, nullptr, nullptr);

    cls->defineStaticFunction("zoneStatusForZone", _SE(js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone));
    cls->defineStaticFunction("show", _SE(js_PluginAdColonyJS_PluginAdColony_show));
    cls->defineStaticFunction("getUniqueDeviceID", _SE(js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID));
    cls->defineStaticFunction("getStatus", _SE(js_PluginAdColonyJS_PluginAdColony_getStatus));
    cls->defineStaticFunction("init", _SE(js_PluginAdColonyJS_PluginAdColony_init));
    cls->defineStaticFunction("videoAdCurrentlyRunning", _SE(js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning));
    cls->defineStaticFunction("setUserMetadata", _SE(js_PluginAdColonyJS_PluginAdColony_setUserMetadata));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginAdColonyJS_PluginAdColony_setGDPR));
    cls->defineStaticFunction("getCustomID", _SE(js_PluginAdColonyJS_PluginAdColony_getCustomID));
    cls->defineStaticFunction("getAdvertisingIdentifier", _SE(js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier));
    cls->defineStaticFunction("turnAllAdsOff", _SE(js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff));
    cls->defineStaticFunction("requestAllAds", _SE(js_PluginAdColonyJS_PluginAdColony_requestAllAds));
    cls->defineStaticFunction("setCustomID", _SE(js_PluginAdColonyJS_PluginAdColony_setCustomID));
    cls->defineStaticFunction("getVideoCreditBalance", _SE(js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance));
    cls->defineStaticFunction("getVideosPerReward", _SE(js_PluginAdColonyJS_PluginAdColony_getVideosPerReward));
    cls->defineStaticFunction("getVendorIdentifier", _SE(js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier));
    cls->defineStaticFunction("notifyIAPComplete", _SE(js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete));
    cls->defineStaticFunction("userInterestedIn", _SE(js_PluginAdColonyJS_PluginAdColony_userInterestedIn));
    cls->defineStaticFunction("cancelAd", _SE(js_PluginAdColonyJS_PluginAdColony_cancelAd));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginAdColony_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginAdColony>(cls);

    __jsb_sdkbox_PluginAdColony_proto = cls->getProto();
    __jsb_sdkbox_PluginAdColony_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginAdColonyJS(se::Object* obj)
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

    js_register_PluginAdColonyJS_PluginAdColony(ns);
    return true;
}

