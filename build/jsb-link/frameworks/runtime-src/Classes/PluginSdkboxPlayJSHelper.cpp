#include "PluginSdkboxPlayJSHelper.h"
#include "PluginSdkboxPlay/PluginSdkboxPlay.h"
#include "SDKBoxJSHelper.h"


static se::Value savedGameData_to_jsobj(const sdkbox::SavedGameData* gameData) {
    se::Value ret;
    if (nullptr == gameData) {
        return ret;
    }
    std::string dataStr(reinterpret_cast<char const*>(gameData->data), (unsigned int)gameData->dataLength);
    cocos2d::ValueMap map;
    map["name"] = cocos2d::Value(gameData->name);
    map["data"] = cocos2d::Value(dataStr);
    map["dataLength"] = cocos2d::Value(gameData->dataLength);
    map["lastModifiedTimestamp"] = cocos2d::Value((double)gameData->lastModifiedTimestamp);
    map["deviceName"] = cocos2d::Value(gameData->deviceName);
    ccvaluemap_to_seval(map, &ret);
    return ret;
}

class SdkboxPlayListenerJS : public sdkbox::SdkboxPlayListener, public sdkbox::JSListenerBase
{
public:
    SdkboxPlayListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onConnectionStatusChanged(int connection_status) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(connection_status));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onScoreSubmitted(const std::string &leaderboard_name, long score, bool alltime, bool week, bool day) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(score));
        args.push_back(se::Value(alltime));
        args.push_back(se::Value(week));
        args.push_back(se::Value(day));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onMyScore( const std::string& leaderboard_name, int time_span, int collection_type, long score ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(score));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onMyScoreError( const std::string& leaderboard_name, int time_span, int collection_type,
                                int error_code, const std::string& error_description) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onPlayerCenteredScores( const std::string& leaderboard_name,
                                         int time_span,
                                         int collection_type,
                                         const std::string& json_with_score_entries ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(json_with_score_entries));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onPlayerCenteredScoresError( const std::string& leaderboard_name,
                                              int time_span,
                                              int collection_type,
                                              int error_code,
                                              const std::string& error_description) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(leaderboard_name));
        args.push_back(se::Value(time_span));
        args.push_back(se::Value(collection_type));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onIncrementalAchievementUnlocked(const std::string &achievement_name) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onIncrementalAchievementStep(const std::string &achievement_name, double step) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(step));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onIncrementalAchievementStepError( const std::string& name, double steps,
                                                   int error_code, const std::string& error_description ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onAchievementUnlocked(const std::string &achievement_name, bool newly) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(newly));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onAchievementUnlockError( const std::string& achievement_name, int error_code, const std::string& error_description ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(achievement_name));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(reload_forced));
        args.push_back(se::Value(json_achievements_info));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onSetSteps( const std::string& name, double steps ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onSetStepsError( const std::string& name, double steps, int error_code, const std::string& error_description ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(steps));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onReveal( const std::string& name) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }
    virtual void onRevealError( const std::string& name, int error_code, const std::string& error_description ) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(error_code));
        args.push_back(se::Value(error_description));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onGameData(const std::string& action, const std::string& name, const std::string& data, const std::string& error) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(action));
        args.push_back(se::Value(name));
        args.push_back(se::Value(data));
        args.push_back(se::Value(error));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onSaveGameData(bool success, const std::string& error) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(se::Value(success));
        args.push_back(se::Value(error));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onLoadGameData(const sdkbox::SavedGameData* savedData, const std::string& error) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY
        se::ValueArray args;
        args.push_back(savedGameData_to_jsobj(savedData));
        args.push_back(se::Value(error));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
    }

    virtual void onGameDataNames(const std::vector<std::string>& names, const std::string& error) {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::Value namesValue;
        cocos2d::ValueVector vec;
        for (std::string name : names) {
            vec.push_back(cocos2d::Value(name));
        }
        ccvaluevector_to_seval(vec, &namesValue);

        se::ValueArray args;
        args.push_back(namesValue);
        args.push_back(se::Value(error));
        invokeJSFun(funcName, args);
        RUN_ON_MAIN_THREAD_END
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
