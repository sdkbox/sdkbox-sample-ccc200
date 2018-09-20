#include "PluginAppodealJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginAppodeal/PluginAppodeal.h"

se::Object* __jsb_sdkbox_PluginAppodeal_proto = nullptr;
se::Class* __jsb_sdkbox_PluginAppodeal_class = nullptr;

static bool js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible : Error processing arguments");
        sdkbox::PluginAppodeal::setBannerBackgroundVisible(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible)

static bool js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled : Error processing arguments");
        bool result = sdkbox::PluginAppodeal::isAutocacheEnabled(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled)

static bool js_PluginAppodealJS_PluginAppodeal_hideBanner(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAppodeal::hideBanner();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_hideBanner)

static bool js_PluginAppodealJS_PluginAppodeal_setUserGender(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Gender arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserGender : Error processing arguments");
        sdkbox::PluginAppodeal::setUserGender(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserGender)

static bool js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setBannerAnimationEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled)

static bool js_PluginAppodealJS_PluginAppodeal_getSDKVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginAppodeal::getSDKVersion();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_getSDKVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_getSDKVersion)

static bool js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        sdkbox::PluginAppodeal::AdType arg0;
        std::string arg1;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType : Error processing arguments");
        sdkbox::PluginAppodeal::disableNetworkForAdType(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType)

static bool js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::SmokingAttitude arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude : Error processing arguments");
        sdkbox::PluginAppodeal::setUserSmokingAttitude(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude)

static bool js_PluginAppodealJS_PluginAppodeal_setUserInterests(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserInterests : Error processing arguments");
        sdkbox::PluginAppodeal::setUserInterests(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserInterests)

static bool js_PluginAppodealJS_PluginAppodeal_setUserBirthday(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserBirthday : Error processing arguments");
        sdkbox::PluginAppodeal::setUserBirthday(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserBirthday)

static bool js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setSmartBannersEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled)

static bool js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginAppodeal::disableLocationPermissionCheck();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck)

static bool js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AlcoholAttitude arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude : Error processing arguments");
        sdkbox::PluginAppodeal::setUserAlcoholAttitude(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude)

static bool js_PluginAppodealJS_PluginAppodeal_setUserOccupation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Occupation arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserOccupation : Error processing arguments");
        sdkbox::PluginAppodeal::setUserOccupation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserOccupation)

static bool js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle : Error processing arguments");
        bool result = sdkbox::PluginAppodeal::isReadyForShowWithStyle(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle)

static bool js_PluginAppodealJS_PluginAppodeal_setUserVkId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserVkId : Error processing arguments");
        sdkbox::PluginAppodeal::setUserVkId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserVkId)

static bool js_PluginAppodealJS_PluginAppodeal_cacheAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_cacheAd : Error processing arguments");
        sdkbox::PluginAppodeal::cacheAd(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_cacheAd)

static bool js_PluginAppodealJS_PluginAppodeal_setAutocache(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        bool arg0;
        sdkbox::PluginAppodeal::AdType arg1;
        ok &= seval_to_boolean(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setAutocache : Error processing arguments");
        sdkbox::PluginAppodeal::setAutocache(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setAutocache)

static bool js_PluginAppodealJS_PluginAppodeal_setDebugEnabled(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setDebugEnabled : Error processing arguments");
        sdkbox::PluginAppodeal::setDebugEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setDebugEnabled)

static bool js_PluginAppodealJS_PluginAppodeal_setUserAge(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserAge : Error processing arguments");
        sdkbox::PluginAppodeal::setUserAge(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserAge)

static bool js_PluginAppodealJS_PluginAppodeal_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginAppodeal::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_init : Error processing arguments");
        return true;
    }
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_init : Error processing arguments");
        bool result = sdkbox::PluginAppodeal::init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_init)

static bool js_PluginAppodealJS_PluginAppodeal_setUserEmail(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserEmail : Error processing arguments");
        sdkbox::PluginAppodeal::setUserEmail(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserEmail)

static bool js_PluginAppodealJS_PluginAppodeal_confirmUsage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::AdType arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_confirmUsage : Error processing arguments");
        sdkbox::PluginAppodeal::confirmUsage(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_confirmUsage)

static bool js_PluginAppodealJS_PluginAppodeal_setUserFacebookId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserFacebookId : Error processing arguments");
        sdkbox::PluginAppodeal::setUserFacebookId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserFacebookId)

static bool js_PluginAppodealJS_PluginAppodeal_setUserRelationship(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::Relationship arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_setUserRelationship : Error processing arguments");
        sdkbox::PluginAppodeal::setUserRelationship(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_setUserRelationship)

static bool js_PluginAppodealJS_PluginAppodeal_showAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        sdkbox::PluginAppodeal::ShowStyle arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_showAd : Error processing arguments");
        bool result = sdkbox::PluginAppodeal::showAd(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginAppodealJS_PluginAppodeal_showAd : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginAppodealJS_PluginAppodeal_showAd)



static bool js_sdkbox_PluginAppodeal_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginAppodeal)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginAppodeal* cobj = (sdkbox::PluginAppodeal*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginAppodeal_finalize)

bool js_register_PluginAppodealJS_PluginAppodeal(se::Object* obj)
{
    auto cls = se::Class::create("PluginAppodeal", obj, nullptr, nullptr);

    cls->defineStaticFunction("setBannerBackgroundVisible", _SE(js_PluginAppodealJS_PluginAppodeal_setBannerBackgroundVisible));
    cls->defineStaticFunction("isAutocacheEnabled", _SE(js_PluginAppodealJS_PluginAppodeal_isAutocacheEnabled));
    cls->defineStaticFunction("hideBanner", _SE(js_PluginAppodealJS_PluginAppodeal_hideBanner));
    cls->defineStaticFunction("setUserGender", _SE(js_PluginAppodealJS_PluginAppodeal_setUserGender));
    cls->defineStaticFunction("setBannerAnimationEnabled", _SE(js_PluginAppodealJS_PluginAppodeal_setBannerAnimationEnabled));
    cls->defineStaticFunction("getSDKVersion", _SE(js_PluginAppodealJS_PluginAppodeal_getSDKVersion));
    cls->defineStaticFunction("disableNetworkForAdType", _SE(js_PluginAppodealJS_PluginAppodeal_disableNetworkForAdType));
    cls->defineStaticFunction("setUserSmokingAttitude", _SE(js_PluginAppodealJS_PluginAppodeal_setUserSmokingAttitude));
    cls->defineStaticFunction("setUserInterests", _SE(js_PluginAppodealJS_PluginAppodeal_setUserInterests));
    cls->defineStaticFunction("setUserBirthday", _SE(js_PluginAppodealJS_PluginAppodeal_setUserBirthday));
    cls->defineStaticFunction("setSmartBannersEnabled", _SE(js_PluginAppodealJS_PluginAppodeal_setSmartBannersEnabled));
    cls->defineStaticFunction("disableLocationPermissionCheck", _SE(js_PluginAppodealJS_PluginAppodeal_disableLocationPermissionCheck));
    cls->defineStaticFunction("setUserAlcoholAttitude", _SE(js_PluginAppodealJS_PluginAppodeal_setUserAlcoholAttitude));
    cls->defineStaticFunction("setUserOccupation", _SE(js_PluginAppodealJS_PluginAppodeal_setUserOccupation));
    cls->defineStaticFunction("isReadyForShowWithStyle", _SE(js_PluginAppodealJS_PluginAppodeal_isReadyForShowWithStyle));
    cls->defineStaticFunction("setUserVkId", _SE(js_PluginAppodealJS_PluginAppodeal_setUserVkId));
    cls->defineStaticFunction("cacheAd", _SE(js_PluginAppodealJS_PluginAppodeal_cacheAd));
    cls->defineStaticFunction("setAutocache", _SE(js_PluginAppodealJS_PluginAppodeal_setAutocache));
    cls->defineStaticFunction("setDebugEnabled", _SE(js_PluginAppodealJS_PluginAppodeal_setDebugEnabled));
    cls->defineStaticFunction("setUserAge", _SE(js_PluginAppodealJS_PluginAppodeal_setUserAge));
    cls->defineStaticFunction("init", _SE(js_PluginAppodealJS_PluginAppodeal_init));
    cls->defineStaticFunction("setUserEmail", _SE(js_PluginAppodealJS_PluginAppodeal_setUserEmail));
    cls->defineStaticFunction("confirmUsage", _SE(js_PluginAppodealJS_PluginAppodeal_confirmUsage));
    cls->defineStaticFunction("setUserFacebookId", _SE(js_PluginAppodealJS_PluginAppodeal_setUserFacebookId));
    cls->defineStaticFunction("setUserRelationship", _SE(js_PluginAppodealJS_PluginAppodeal_setUserRelationship));
    cls->defineStaticFunction("showAd", _SE(js_PluginAppodealJS_PluginAppodeal_showAd));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginAppodeal_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginAppodeal>(cls);

    __jsb_sdkbox_PluginAppodeal_proto = cls->getProto();
    __jsb_sdkbox_PluginAppodeal_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginAppodealJS(se::Object* obj)
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

    js_register_PluginAppodealJS_PluginAppodeal(ns);
    return true;
}

