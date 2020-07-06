#include "PluginHMSJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginHMS/PluginHMS.h"

se::Object* __jsb_sdkbox_PluginHMS_proto = nullptr;
se::Class* __jsb_sdkbox_PluginHMS_class = nullptr;

static bool js_PluginHMSJS_PluginHMS_adCache(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adCache : Error processing arguments");
        sdkbox::PluginHMS::adCache(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adCache)

static bool js_PluginHMSJS_PluginHMS_adSetAdContentClassification(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetAdContentClassification : Error processing arguments");
        sdkbox::PluginHMS::adSetAdContentClassification(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetAdContentClassification)

static bool js_PluginHMSJS_PluginHMS_adSetNonPersonalizedAd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetNonPersonalizedAd : Error processing arguments");
        sdkbox::PluginHMS::adSetNonPersonalizedAd(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetNonPersonalizedAd)

static bool js_PluginHMSJS_PluginHMS_archiveShow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        bool arg1;
        bool arg2;
        int arg3 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        ok &= seval_to_boolean(args[2], &arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveShow : Error processing arguments");
        sdkbox::PluginHMS::archiveShow(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveShow)

static bool js_PluginHMSJS_PluginHMS_buoyHide(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::buoyHide();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_buoyHide)

static bool js_PluginHMSJS_PluginHMS_rankingRequestList(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestList : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestList(arg0);
        return true;
    }
    if (argc == 2) {
        bool arg0;
        std::string arg1;
        ok &= seval_to_boolean(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestList : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestList(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestList)

static bool js_PluginHMSJS_PluginHMS_playerRequestExtraInfo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::playerRequestExtraInfo();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_playerRequestExtraInfo)

static bool js_PluginHMSJS_PluginHMS_adSetTagForChildProtection(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetTagForChildProtection : Error processing arguments");
        sdkbox::PluginHMS::adSetTagForChildProtection(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetTagForChildProtection)

static bool js_PluginHMSJS_PluginHMS_buoyShow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::buoyShow();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_buoyShow)

static bool js_PluginHMSJS_PluginHMS_rankingRequestPlayerCenteredScores(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        bool arg3;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_boolean(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestPlayerCenteredScores : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestPlayerCenteredScores(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestPlayerCenteredScores)

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

static bool js_PluginHMSJS_PluginHMS_achievementReach(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_achievementReach : Error processing arguments");
        sdkbox::PluginHMS::achievementReach(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementReach)

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

static bool js_PluginHMSJS_PluginHMS_rankingSubmitScore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        long arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_long(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingSubmitScore : Error processing arguments");
        sdkbox::PluginHMS::rankingSubmitScore(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        long arg1 = 0;
        std::string arg2;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_long(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingSubmitScore : Error processing arguments");
        sdkbox::PluginHMS::rankingSubmitScore(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingSubmitScore)

static bool js_PluginHMSJS_PluginHMS_eventGrow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_eventGrow : Error processing arguments");
        sdkbox::PluginHMS::eventGrow(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_eventGrow)

static bool js_PluginHMSJS_PluginHMS_rankingRequestMoreScores(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        int arg4 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestMoreScores : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestMoreScores(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestMoreScores)

static bool js_PluginHMSJS_PluginHMS_adShow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adShow : Error processing arguments");
        sdkbox::PluginHMS::adShow(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adShow)

static bool js_PluginHMSJS_PluginHMS_achievementRequestList(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::achievementRequestList();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementRequestList)

static bool js_PluginHMSJS_PluginHMS_playerSubmitGameEnd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::playerSubmitGameEnd();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_playerSubmitGameEnd)

static bool js_PluginHMSJS_PluginHMS_achievementMakeSteps(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_achievementMakeSteps : Error processing arguments");
        sdkbox::PluginHMS::achievementMakeSteps(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementMakeSteps)

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

static bool js_PluginHMSJS_PluginHMS_archiveRequestThumbnail(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveRequestThumbnail : Error processing arguments");
        sdkbox::PluginHMS::archiveRequestThumbnail(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveRequestThumbnail)

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

static bool js_PluginHMSJS_PluginHMS_adHide(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adHide : Error processing arguments");
        sdkbox::PluginHMS::adHide(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adHide)

static bool js_PluginHMSJS_PluginHMS_rankingSetSwitchStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingSetSwitchStatus : Error processing arguments");
        sdkbox::PluginHMS::rankingSetSwitchStatus(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingSetSwitchStatus)

static bool js_PluginHMSJS_PluginHMS_adSetTagForUnderAgeOfPromise(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetTagForUnderAgeOfPromise : Error processing arguments");
        sdkbox::PluginHMS::adSetTagForUnderAgeOfPromise(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetTagForUnderAgeOfPromise)

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

static bool js_PluginHMSJS_PluginHMS_playerSubmitGameBegin(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::playerSubmitGameBegin();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_playerSubmitGameBegin)

static bool js_PluginHMSJS_PluginHMS_playerRequestInfo(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::playerRequestInfo();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_playerRequestInfo)

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

static bool js_PluginHMSJS_PluginHMS_archiveRequestLimitDetailsSize(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::archiveRequestLimitDetailsSize();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveRequestLimitDetailsSize)

static bool js_PluginHMSJS_PluginHMS_rankingRequestCurPlayerScore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestCurPlayerScore : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestCurPlayerScore(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestCurPlayerScore)

static bool js_PluginHMSJS_PluginHMS_rankingShow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingShow : Error processing arguments");
        sdkbox::PluginHMS::rankingShow(arg0);
        return true;
    }
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingShow : Error processing arguments");
        sdkbox::PluginHMS::rankingShow(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingShow)

static bool js_PluginHMSJS_PluginHMS_archiveLoad(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveLoad : Error processing arguments");
        sdkbox::PluginHMS::archiveLoad(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveLoad)

static bool js_PluginHMSJS_PluginHMS_gameSummaryRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_gameSummaryRequest : Error processing arguments");
        sdkbox::PluginHMS::gameSummaryRequest(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_gameSummaryRequest)

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

static bool js_PluginHMSJS_PluginHMS_adIsAvailable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adIsAvailable : Error processing arguments");
        bool result = sdkbox::PluginHMS::adIsAvailable(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adIsAvailable : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adIsAvailable)

static bool js_PluginHMSJS_PluginHMS_rankingRequestSwitchStatus(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::rankingRequestSwitchStatus();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestSwitchStatus)

static bool js_PluginHMSJS_PluginHMS_achievementGrow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_achievementGrow : Error processing arguments");
        sdkbox::PluginHMS::achievementGrow(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementGrow)

static bool js_PluginHMSJS_PluginHMS_archiveRequestLimitThumbnailSize(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::archiveRequestLimitThumbnailSize();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveRequestLimitThumbnailSize)

static bool js_PluginHMSJS_PluginHMS_gamePlayerStatsRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_gamePlayerStatsRequest : Error processing arguments");
        sdkbox::PluginHMS::gamePlayerStatsRequest(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_gamePlayerStatsRequest)

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

static bool js_PluginHMSJS_PluginHMS_adSetRewardData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetRewardData : Error processing arguments");
        sdkbox::PluginHMS::adSetRewardData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetRewardData)

static bool js_PluginHMSJS_PluginHMS_archiveRequestSummaryList(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveRequestSummaryList : Error processing arguments");
        sdkbox::PluginHMS::archiveRequestSummaryList(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveRequestSummaryList)

static bool js_PluginHMSJS_PluginHMS_adSetRewardUserId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_adSetRewardUserId : Error processing arguments");
        sdkbox::PluginHMS::adSetRewardUserId(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_adSetRewardUserId)

static bool js_PluginHMSJS_PluginHMS_rankingRequestTopScores(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        int arg4 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_rankingRequestTopScores : Error processing arguments");
        sdkbox::PluginHMS::rankingRequestTopScores(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_rankingRequestTopScores)

static bool js_PluginHMSJS_PluginHMS_archiveRemove(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveRemove : Error processing arguments");
        sdkbox::PluginHMS::archiveRemove(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveRemove)

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

static bool js_PluginHMSJS_PluginHMS_eventRequestList(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_eventRequestList : Error processing arguments");
        sdkbox::PluginHMS::eventRequestList(arg0);
        return true;
    }
    if (argc == 2) {
        bool arg0;
        std::string arg1;
        ok &= seval_to_boolean(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_eventRequestList : Error processing arguments");
        sdkbox::PluginHMS::eventRequestList(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_eventRequestList)

static bool js_PluginHMSJS_PluginHMS_achievementShow(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginHMS::achievementShow();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementShow)

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

static bool js_PluginHMSJS_PluginHMS_achievementVisualize(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_achievementVisualize : Error processing arguments");
        sdkbox::PluginHMS::achievementVisualize(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_achievementVisualize)



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

    cls->defineStaticFunction("adCache", _SE(js_PluginHMSJS_PluginHMS_adCache));
    cls->defineStaticFunction("adSetAdContentClassification", _SE(js_PluginHMSJS_PluginHMS_adSetAdContentClassification));
    cls->defineStaticFunction("adSetNonPersonalizedAd", _SE(js_PluginHMSJS_PluginHMS_adSetNonPersonalizedAd));
    cls->defineStaticFunction("archiveShow", _SE(js_PluginHMSJS_PluginHMS_archiveShow));
    cls->defineStaticFunction("buoyHide", _SE(js_PluginHMSJS_PluginHMS_buoyHide));
    cls->defineStaticFunction("rankingRequestList", _SE(js_PluginHMSJS_PluginHMS_rankingRequestList));
    cls->defineStaticFunction("playerRequestExtraInfo", _SE(js_PluginHMSJS_PluginHMS_playerRequestExtraInfo));
    cls->defineStaticFunction("adSetTagForChildProtection", _SE(js_PluginHMSJS_PluginHMS_adSetTagForChildProtection));
    cls->defineStaticFunction("buoyShow", _SE(js_PluginHMSJS_PluginHMS_buoyShow));
    cls->defineStaticFunction("rankingRequestPlayerCenteredScores", _SE(js_PluginHMSJS_PluginHMS_rankingRequestPlayerCenteredScores));
    cls->defineStaticFunction("iapPurchaseWithPrice", _SE(js_PluginHMSJS_PluginHMS_iapPurchaseWithPrice));
    cls->defineStaticFunction("achievementReach", _SE(js_PluginHMSJS_PluginHMS_achievementReach));
    cls->defineStaticFunction("iapPurchase", _SE(js_PluginHMSJS_PluginHMS_iapPurchase));
    cls->defineStaticFunction("rankingSubmitScore", _SE(js_PluginHMSJS_PluginHMS_rankingSubmitScore));
    cls->defineStaticFunction("eventGrow", _SE(js_PluginHMSJS_PluginHMS_eventGrow));
    cls->defineStaticFunction("rankingRequestMoreScores", _SE(js_PluginHMSJS_PluginHMS_rankingRequestMoreScores));
    cls->defineStaticFunction("adShow", _SE(js_PluginHMSJS_PluginHMS_adShow));
    cls->defineStaticFunction("achievementRequestList", _SE(js_PluginHMSJS_PluginHMS_achievementRequestList));
    cls->defineStaticFunction("playerSubmitGameEnd", _SE(js_PluginHMSJS_PluginHMS_playerSubmitGameEnd));
    cls->defineStaticFunction("achievementMakeSteps", _SE(js_PluginHMSJS_PluginHMS_achievementMakeSteps));
    cls->defineStaticFunction("init", _SE(js_PluginHMSJS_PluginHMS_init));
    cls->defineStaticFunction("archiveRequestThumbnail", _SE(js_PluginHMSJS_PluginHMS_archiveRequestThumbnail));
    cls->defineStaticFunction("iapRequestProducts", _SE(js_PluginHMSJS_PluginHMS_iapRequestProducts));
    cls->defineStaticFunction("adHide", _SE(js_PluginHMSJS_PluginHMS_adHide));
    cls->defineStaticFunction("rankingSetSwitchStatus", _SE(js_PluginHMSJS_PluginHMS_rankingSetSwitchStatus));
    cls->defineStaticFunction("adSetTagForUnderAgeOfPromise", _SE(js_PluginHMSJS_PluginHMS_adSetTagForUnderAgeOfPromise));
    cls->defineStaticFunction("setGDPR", _SE(js_PluginHMSJS_PluginHMS_setGDPR));
    cls->defineStaticFunction("playerSubmitGameBegin", _SE(js_PluginHMSJS_PluginHMS_playerSubmitGameBegin));
    cls->defineStaticFunction("playerRequestInfo", _SE(js_PluginHMSJS_PluginHMS_playerRequestInfo));
    cls->defineStaticFunction("iapRequestOwnedPurchases", _SE(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchases));
    cls->defineStaticFunction("archiveRequestLimitDetailsSize", _SE(js_PluginHMSJS_PluginHMS_archiveRequestLimitDetailsSize));
    cls->defineStaticFunction("rankingRequestCurPlayerScore", _SE(js_PluginHMSJS_PluginHMS_rankingRequestCurPlayerScore));
    cls->defineStaticFunction("rankingShow", _SE(js_PluginHMSJS_PluginHMS_rankingShow));
    cls->defineStaticFunction("archiveLoad", _SE(js_PluginHMSJS_PluginHMS_archiveLoad));
    cls->defineStaticFunction("gameSummaryRequest", _SE(js_PluginHMSJS_PluginHMS_gameSummaryRequest));
    cls->defineStaticFunction("logout", _SE(js_PluginHMSJS_PluginHMS_logout));
    cls->defineStaticFunction("adIsAvailable", _SE(js_PluginHMSJS_PluginHMS_adIsAvailable));
    cls->defineStaticFunction("rankingRequestSwitchStatus", _SE(js_PluginHMSJS_PluginHMS_rankingRequestSwitchStatus));
    cls->defineStaticFunction("achievementGrow", _SE(js_PluginHMSJS_PluginHMS_achievementGrow));
    cls->defineStaticFunction("archiveRequestLimitThumbnailSize", _SE(js_PluginHMSJS_PluginHMS_archiveRequestLimitThumbnailSize));
    cls->defineStaticFunction("gamePlayerStatsRequest", _SE(js_PluginHMSJS_PluginHMS_gamePlayerStatsRequest));
    cls->defineStaticFunction("iapRequestOwnedPurchaseRecords", _SE(js_PluginHMSJS_PluginHMS_iapRequestOwnedPurchaseRecords));
    cls->defineStaticFunction("adSetRewardData", _SE(js_PluginHMSJS_PluginHMS_adSetRewardData));
    cls->defineStaticFunction("archiveRequestSummaryList", _SE(js_PluginHMSJS_PluginHMS_archiveRequestSummaryList));
    cls->defineStaticFunction("adSetRewardUserId", _SE(js_PluginHMSJS_PluginHMS_adSetRewardUserId));
    cls->defineStaticFunction("rankingRequestTopScores", _SE(js_PluginHMSJS_PluginHMS_rankingRequestTopScores));
    cls->defineStaticFunction("archiveRemove", _SE(js_PluginHMSJS_PluginHMS_archiveRemove));
    cls->defineStaticFunction("iapConsume", _SE(js_PluginHMSJS_PluginHMS_iapConsume));
    cls->defineStaticFunction("eventRequestList", _SE(js_PluginHMSJS_PluginHMS_eventRequestList));
    cls->defineStaticFunction("achievementShow", _SE(js_PluginHMSJS_PluginHMS_achievementShow));
    cls->defineStaticFunction("login", _SE(js_PluginHMSJS_PluginHMS_login));
    cls->defineStaticFunction("achievementVisualize", _SE(js_PluginHMSJS_PluginHMS_achievementVisualize));
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

