#include "PluginSdkboxPlayJSHelper.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxJSHelper.h"

class SdkboxPlayListenerJS : public sdkbox::SdkboxPlayListener, public sdkbox::JSListenerBase
{
public:
    SdkboxPlayListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onConnectionStatusChanged(int connection_status) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(connection_status));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onScoreSubmitted(const std::string &leaderboard_name, long score, bool alltime, bool week, bool day) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(score));
        args.push_back(se::Value(alltime));
        args.push_back(se::Value(week));
        args.push_back(se::Value(day));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(score));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type,
                                int error_code, const std::string& error_description) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onPlayerCenteredScores( const std::string& leaderboard_name,
                                         int time_span,
                                         int collection_type,
                                         const std::string& json_with_score_entries ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(json_with_score_entries));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                              int time_span,
                                              int collection_type,
                                              int error_code,
                                              const std::string& error_description) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onIncrementalAchievementUnlocked(const std::string &achievement_name) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onIncrementalAchievementStep(const std::string &achievement_name, double step) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(step));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onIncrementalAchievementStepError( const std::string& name, double steps,
                                                   int error_code, const std::string& error_description ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onAchievementUnlocked(const std::string &achievement_name, bool newly) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(newly));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(reload_forced));
        args.push_back(se::Value(json_achievements_info));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onSetSteps( const std::string& name, double steps ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onSetStepsError( const std::string& name, double steps, int error_code, const std::string& error_description ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onReveal( const std::string& name) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    virtual void onRevealError( const std::string& name, int error_code, const std::string& error_description ) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(__FUNCTION__, args);
    }

    virtual void onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error) {
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(action));
        args.push_back(se::Value(name));
        args.push_back(se::Value(data));
        args.push_back(se::Value(error));
        invokeJSFun(__FUNCTION__, args);
    }
};


static bool js_PluginSdkboxPlayJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        SdkboxPlayListenerJS* nativeDelegate = dynamic_cast<SdkboxPlayListenerJS*>(sdkbox::PluginSdkboxPlay::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) SdkboxPlayListenerJS();
            sdkbox::PluginSdkboxPlay::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_setListener)

static bool js_PluginSdkboxPlayJS_saveGameDataString(se::State& s) {
    const auto& args = s.args();
    size_t argc = args.size();
    bool ok = true;
    if (argc == 2) {
        std::string name;
        std::string value;
        ok &= seval_to_std_string(args[0], &name);
        ok &= seval_to_std_string(args[1], &value);
        SE_PRECONDITION2(ok, false, "js_PluginSdkboxPlayJS_PluginSdkboxPlay_incrementAchievement : Error processing arguments");
        sdkbox::PluginSdkboxPlay::saveGameDataBinary(name, value.c_str(), (int)value.length());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d, should be ' sdkbox.PluginSdkboxPlay.saveGameDataString('name', 'stringdata'); '", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginSdkboxPlayJS_saveGameDataString)

extern se::Object* __jsb_sdkbox_PluginSdkboxPlay_proto;
extern se::Class* __jsb_sdkbox_PluginSdkboxPlay_class;
bool register_all_PluginSdkboxPlayJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginSdkboxPlay");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginSdkboxPlayJS_setListener));
    plugin->defineFunction("saveGameDataString", _SE(js_PluginSdkboxPlayJS_saveGameDataString));
    plugin->defineFunction("saveGameDataBinary", _SE(js_PluginSdkboxPlayJS_saveGameDataString));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
