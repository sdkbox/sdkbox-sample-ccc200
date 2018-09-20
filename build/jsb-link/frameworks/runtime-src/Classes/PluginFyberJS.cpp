#include "PluginFyberJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginFyber/PluginFyber.h"

se::Object* __jsb_sdkbox_PluginFyber_proto = nullptr;
se::Class* __jsb_sdkbox_PluginFyber_class = nullptr;

static bool js_PluginFyberJS_PluginFyber_setZipcode(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setZipcode : Error processing arguments");
        sdkbox::PluginFyber::setZipcode(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setZipcode)

static bool js_PluginFyberJS_PluginFyber_showInterstitial(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFyber::showInterstitial();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_showInterstitial)

static bool js_PluginFyberJS_PluginFyber_setNumberOfSessions(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setNumberOfSessions : Error processing arguments");
        sdkbox::PluginFyber::setNumberOfSessions(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setNumberOfSessions)

static bool js_PluginFyberJS_PluginFyber_setNumberOfChildren(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setNumberOfChildren : Error processing arguments");
        sdkbox::PluginFyber::setNumberOfChildren(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setNumberOfChildren)

static bool js_PluginFyberJS_PluginFyber_setLocation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= seval_to_double(args[0], &arg0);
        ok &= seval_to_double(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setLocation : Error processing arguments");
        sdkbox::PluginFyber::setLocation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setLocation)

static bool js_PluginFyberJS_PluginFyber_setIap(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setIap : Error processing arguments");
        sdkbox::PluginFyber::setIap(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setIap)

static bool js_PluginFyberJS_PluginFyber_setVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setVersion : Error processing arguments");
        sdkbox::PluginFyber::setVersion(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setVersion)

static bool js_PluginFyberJS_PluginFyber_requestInterstitial(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFyber::requestInterstitial();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_requestInterstitial)

static bool js_PluginFyberJS_PluginFyber_showOfferWall(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginFyber::showOfferWall();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_showOfferWall : Error processing arguments");
        sdkbox::PluginFyber::showOfferWall(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_showOfferWall)

static bool js_PluginFyberJS_PluginFyber_requestOffers(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginFyber::requestOffers();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_requestOffers : Error processing arguments");
        sdkbox::PluginFyber::requestOffers(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_requestOffers)

static bool js_PluginFyberJS_PluginFyber_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginFyber::init();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_init : Error processing arguments");
        sdkbox::PluginFyber::init(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        const char* arg1 = nullptr;
        ok &= seval_to_std_string(args[0], &arg0);
        std::string arg1_tmp; ok &= seval_to_std_string(args[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_init : Error processing arguments");
        sdkbox::PluginFyber::init(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_init)

static bool js_PluginFyberJS_PluginFyber_setDevice(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setDevice : Error processing arguments");
        sdkbox::PluginFyber::setDevice(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setDevice)

static bool js_PluginFyberJS_PluginFyber_setLastSession(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        double arg0 = 0;
        ok &= seval_to_double(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setLastSession : Error processing arguments");
        sdkbox::PluginFyber::setLastSession(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setLastSession)

static bool js_PluginFyberJS_PluginFyber_setAnnualHouseholdIncome(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setAnnualHouseholdIncome : Error processing arguments");
        sdkbox::PluginFyber::setAnnualHouseholdIncome(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setAnnualHouseholdIncome)

static bool js_PluginFyberJS_PluginFyber_setMaritalStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setMaritalStatus : Error processing arguments");
        sdkbox::PluginFyber::setMaritalStatus(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setMaritalStatus)

static bool js_PluginFyberJS_PluginFyber_showOffers(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginFyber::showOffers();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_showOffers : Error processing arguments");
        sdkbox::PluginFyber::showOffers(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_showOffers)

static bool js_PluginFyberJS_PluginFyber_cleanLocation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFyber::cleanLocation();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_cleanLocation)

static bool js_PluginFyberJS_PluginFyber_setSexualOrientation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setSexualOrientation : Error processing arguments");
        sdkbox::PluginFyber::setSexualOrientation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setSexualOrientation)

static bool js_PluginFyberJS_PluginFyber_setGender(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setGender : Error processing arguments");
        sdkbox::PluginFyber::setGender(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setGender)

static bool js_PluginFyberJS_PluginFyber_setBirthdate(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setBirthdate : Error processing arguments");
        sdkbox::PluginFyber::setBirthdate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setBirthdate)

static bool js_PluginFyberJS_PluginFyber_setAge(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setAge : Error processing arguments");
        sdkbox::PluginFyber::setAge(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setAge)

static bool js_PluginFyberJS_PluginFyber_setConnectionType(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setConnectionType : Error processing arguments");
        sdkbox::PluginFyber::setConnectionType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setConnectionType)

static bool js_PluginFyberJS_PluginFyber_addCustomParameters(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_addCustomParameters : Error processing arguments");
        sdkbox::PluginFyber::addCustomParameters(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_addCustomParameters)

static bool js_PluginFyberJS_PluginFyber_setInterests(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setInterests : Error processing arguments");
        sdkbox::PluginFyber::setInterests(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setInterests)

static bool js_PluginFyberJS_PluginFyber_requestDeltaOfCoins(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginFyber::requestDeltaOfCoins();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_requestDeltaOfCoins : Error processing arguments");
        sdkbox::PluginFyber::requestDeltaOfCoins(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_requestDeltaOfCoins)

static bool js_PluginFyberJS_PluginFyber_setPsTime(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        double arg0 = 0;
        ok &= seval_to_double(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setPsTime : Error processing arguments");
        sdkbox::PluginFyber::setPsTime(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setPsTime)

static bool js_PluginFyberJS_PluginFyber_cleanCustomParameters(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginFyber::cleanCustomParameters();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_cleanCustomParameters)

static bool js_PluginFyberJS_PluginFyber_setIapAmount(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setIapAmount : Error processing arguments");
        sdkbox::PluginFyber::setIapAmount(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setIapAmount)

static bool js_PluginFyberJS_PluginFyber_setEthnicity(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setEthnicity : Error processing arguments");
        sdkbox::PluginFyber::setEthnicity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setEthnicity)

static bool js_PluginFyberJS_PluginFyber_setEducation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFyberJS_PluginFyber_setEducation : Error processing arguments");
        sdkbox::PluginFyber::setEducation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFyberJS_PluginFyber_setEducation)



static bool js_sdkbox_PluginFyber_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginFyber)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginFyber* cobj = (sdkbox::PluginFyber*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginFyber_finalize)

bool js_register_PluginFyberJS_PluginFyber(se::Object* obj)
{
    auto cls = se::Class::create("PluginFyber", obj, nullptr, nullptr);

    cls->defineStaticFunction("setZipcode", _SE(js_PluginFyberJS_PluginFyber_setZipcode));
    cls->defineStaticFunction("showInterstitial", _SE(js_PluginFyberJS_PluginFyber_showInterstitial));
    cls->defineStaticFunction("setNumberOfSessions", _SE(js_PluginFyberJS_PluginFyber_setNumberOfSessions));
    cls->defineStaticFunction("setNumberOfChildren", _SE(js_PluginFyberJS_PluginFyber_setNumberOfChildren));
    cls->defineStaticFunction("setLocation", _SE(js_PluginFyberJS_PluginFyber_setLocation));
    cls->defineStaticFunction("setIap", _SE(js_PluginFyberJS_PluginFyber_setIap));
    cls->defineStaticFunction("setVersion", _SE(js_PluginFyberJS_PluginFyber_setVersion));
    cls->defineStaticFunction("requestInterstitial", _SE(js_PluginFyberJS_PluginFyber_requestInterstitial));
    cls->defineStaticFunction("showOfferWall", _SE(js_PluginFyberJS_PluginFyber_showOfferWall));
    cls->defineStaticFunction("requestOffers", _SE(js_PluginFyberJS_PluginFyber_requestOffers));
    cls->defineStaticFunction("init", _SE(js_PluginFyberJS_PluginFyber_init));
    cls->defineStaticFunction("setDevice", _SE(js_PluginFyberJS_PluginFyber_setDevice));
    cls->defineStaticFunction("setLastSession", _SE(js_PluginFyberJS_PluginFyber_setLastSession));
    cls->defineStaticFunction("setAnnualHouseholdIncome", _SE(js_PluginFyberJS_PluginFyber_setAnnualHouseholdIncome));
    cls->defineStaticFunction("setMaritalStatus", _SE(js_PluginFyberJS_PluginFyber_setMaritalStatus));
    cls->defineStaticFunction("showOffers", _SE(js_PluginFyberJS_PluginFyber_showOffers));
    cls->defineStaticFunction("cleanLocation", _SE(js_PluginFyberJS_PluginFyber_cleanLocation));
    cls->defineStaticFunction("setSexualOrientation", _SE(js_PluginFyberJS_PluginFyber_setSexualOrientation));
    cls->defineStaticFunction("setGender", _SE(js_PluginFyberJS_PluginFyber_setGender));
    cls->defineStaticFunction("setBirthdate", _SE(js_PluginFyberJS_PluginFyber_setBirthdate));
    cls->defineStaticFunction("setAge", _SE(js_PluginFyberJS_PluginFyber_setAge));
    cls->defineStaticFunction("setConnectionType", _SE(js_PluginFyberJS_PluginFyber_setConnectionType));
    cls->defineStaticFunction("addCustomParameters", _SE(js_PluginFyberJS_PluginFyber_addCustomParameters));
    cls->defineStaticFunction("setInterests", _SE(js_PluginFyberJS_PluginFyber_setInterests));
    cls->defineStaticFunction("requestDeltaOfCoins", _SE(js_PluginFyberJS_PluginFyber_requestDeltaOfCoins));
    cls->defineStaticFunction("setPsTime", _SE(js_PluginFyberJS_PluginFyber_setPsTime));
    cls->defineStaticFunction("cleanCustomParameters", _SE(js_PluginFyberJS_PluginFyber_cleanCustomParameters));
    cls->defineStaticFunction("setIapAmount", _SE(js_PluginFyberJS_PluginFyber_setIapAmount));
    cls->defineStaticFunction("setEthnicity", _SE(js_PluginFyberJS_PluginFyber_setEthnicity));
    cls->defineStaticFunction("setEducation", _SE(js_PluginFyberJS_PluginFyber_setEducation));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginFyber_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginFyber>(cls);

    __jsb_sdkbox_PluginFyber_proto = cls->getProto();
    __jsb_sdkbox_PluginFyber_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginFyberJS(se::Object* obj)
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

    js_register_PluginFyberJS_PluginFyber(ns);
    return true;
}

