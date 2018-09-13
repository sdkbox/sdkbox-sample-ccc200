#include "PluginSdkboxPlayJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"

se::Object* __jsb_sdkbox_PluginSdkboxPlay_proto = nullptr;
se::Class* __jsb_sdkbox_PluginSdkboxPlay_class = nullptr;

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_double(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement : Error processing arguments");
        sdkbox::PluginSdkboxPlay::incrementAchievement(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginSdkboxPlay::getPlayerId();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore : Error processing arguments");
        sdkbox::PluginSdkboxPlay::getMyScore(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAllLeaderboards();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField : Error processing arguments");
        std::string result = sdkbox::PluginSdkboxPlay::getPlayerAccountField(arg0);
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::loadAllData();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllData)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores : Error processing arguments");
        sdkbox::PluginSdkboxPlay::getPlayerCenteredScores(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_fetchGameDataNames(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::fetchGameDataNames();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_fetchGameDataNames)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showLeaderboard();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard : Error processing arguments");
        sdkbox::PluginSdkboxPlay::showLeaderboard(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signout();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginSdkboxPlay::isSignedIn();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginSdkboxPlay::init();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_init)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement : Error processing arguments");
        sdkbox::PluginSdkboxPlay::unlockAchievement(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadOneGameData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadOneGameData : Error processing arguments");
        sdkbox::PluginSdkboxPlay::loadOneGameData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadOneGameData)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements : Error processing arguments");
        sdkbox::PluginSdkboxPlay::loadAchievements(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadGameData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadGameData : Error processing arguments");
        sdkbox::PluginSdkboxPlay::loadGameData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadGameData)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::showAchievements();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_resetAchievements(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::resetAchievements();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_resetAchievements)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::PluginSdkboxPlay::isConnected();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        long arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_long(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore : Error processing arguments");
        sdkbox::PluginSdkboxPlay::submitScore(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_double(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps : Error processing arguments");
        sdkbox::PluginSdkboxPlay::setSteps(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::PluginSdkboxPlay::getVersion();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::removeListener();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllGameData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::loadAllGameData();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllGameData)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal : Error processing arguments");
        sdkbox::PluginSdkboxPlay::reveal(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_saveGameData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_saveGameData : Error processing arguments");
        sdkbox::PluginSdkboxPlay::saveGameData(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_saveGameData)

static bool js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        sdkbox::PluginSdkboxPlay::signin();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin : Error processing arguments");
        sdkbox::PluginSdkboxPlay::signin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin)



static bool js_sdkbox_PluginSdkboxPlay_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::PluginSdkboxPlay)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::PluginSdkboxPlay* cobj = (sdkbox::PluginSdkboxPlay*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_PluginSdkboxPlay_finalize)

bool js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(se::Object* obj)
{
    auto cls = se::Class::create("PluginSdkboxPlay", obj, nullptr, nullptr);

    cls->defineStaticFunction("incrementAchievement", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement));
    cls->defineStaticFunction("getPlayerId", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerId));
    cls->defineStaticFunction("getMyScore", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getMyScore));
    cls->defineStaticFunction("showAllLeaderboards", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAllLeaderboards));
    cls->defineStaticFunction("getPlayerAccountField", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerAccountField));
    cls->defineStaticFunction("loadAllData", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllData));
    cls->defineStaticFunction("getPlayerCenteredScores", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getPlayerCenteredScores));
    cls->defineStaticFunction("fetchGameDataNames", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_fetchGameDataNames));
    cls->defineStaticFunction("showLeaderboard", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showLeaderboard));
    cls->defineStaticFunction("signout", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_signout));
    cls->defineStaticFunction("isSignedIn", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_isSignedIn));
    cls->defineStaticFunction("init", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_init));
    cls->defineStaticFunction("unlockAchievement", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_unlockAchievement));
    cls->defineStaticFunction("loadOneGameData", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadOneGameData));
    cls->defineStaticFunction("loadAchievements", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAchievements));
    cls->defineStaticFunction("loadGameData", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadGameData));
    cls->defineStaticFunction("showAchievements", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_showAchievements));
    cls->defineStaticFunction("resetAchievements", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_resetAchievements));
    cls->defineStaticFunction("isConnected", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_isConnected));
    cls->defineStaticFunction("submitScore", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_submitScore));
    cls->defineStaticFunction("setSteps", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_setSteps));
    cls->defineStaticFunction("getVersion", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_getVersion));
    cls->defineStaticFunction("removeListener", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_removeListener));
    cls->defineStaticFunction("loadAllGameData", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_loadAllGameData));
    cls->defineStaticFunction("reveal", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_reveal));
    cls->defineStaticFunction("saveGameData", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_saveGameData));
    cls->defineStaticFunction("signin", _SE(js_PluginSdkboxPlayJS_PluginSdkboxPlay_signin));
    cls->defineFinalizeFunction(_SE(js_sdkbox_PluginSdkboxPlay_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::PluginSdkboxPlay>(cls);

    __jsb_sdkbox_PluginSdkboxPlay_proto = cls->getProto();
    __jsb_sdkbox_PluginSdkboxPlay_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginSdkboxPlayJS(se::Object* obj)
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

    js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(ns);
    return true;
}

