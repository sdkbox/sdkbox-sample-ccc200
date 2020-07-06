#include "PluginHMSJSHelper.h"
#include "PluginHMS/PluginHMS.h"
#include "SDKBoxJSHelper.h"

extern se::Class* __jsb_sdkbox_PluginHMS_class;;

class HMSListenerJS : public sdkbox::HMSListener, public sdkbox::JSListenerBase {
public:
    HMSListenerJS() : sdkbox::JSListenerBase() {
    }

    void onLogin(int code, const std::string &msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onPlayerInfo(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onPlayerExtraInfo(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onPlayerGameBegin(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onPlayerGameEnd(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };
    
    void onIAPReady(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPProducts(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPPurchase(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void onIAPConsume(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onIAPOwnedPurchases(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onIAPOwnedPurchaseRecords(int code, const std::string& msg) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(msg));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAchievementList(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAchievementShow(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAchievementVisualize(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAchievementGrow(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAchievementMakeSteps(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onEventList(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingSwitchStatus(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingSetSwitchStatus(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingSubmitScore(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingShow(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingList(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingCurPlayerScore(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingPlayerCenteredScores(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingMoreScores(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onRankingTopScores(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveLimitThumbnailSize(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveLimitDetailsSize(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveAdd(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveShow(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveSummaryList(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveSelect(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveThumbnail(int code, const std::string& errorOrJson, unsigned char* coverData, unsigned int coverDataLen) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));

        cocos2d::Data data;
        data.copy(coverData, coverDataLen);
        se::Value dataVal;
        Data_to_seval(data, &dataVal);
        args.push_back(dataVal);

        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveUpdate(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveLoad(int code, const std::string& errorOrJson, unsigned char* contentData, unsigned int contentDataLen) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));

        cocos2d::Data data;
        data.copy(contentData, contentDataLen);
        se::Value dataVal;
        Data_to_seval(data, &dataVal);
        args.push_back(dataVal);

        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onArchiveRemove(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onGamePlayerStats(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onGameSummary(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdClose(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdFail(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdLeave(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdOpen(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdLoad(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdClick(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdImpression(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

    void onAdReward(int code, const std::string& errorOrJson) override {
        RUN_ON_MAIN_THREAD_BEGIN
        MAKE_V8_HAPPY

        se::ValueArray args;
        args.push_back(se::Value(code));
        args.push_back(se::Value(errorOrJson));
        invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    };

};

static bool js_PluginHMSJS_PluginHMS_setListener(se::State& s) {
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        HMSListenerJS* nativeDelegate = dynamic_cast<HMSListenerJS*>(sdkbox::PluginHMS::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) HMSListenerJS();
            sdkbox::PluginHMS::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_setListener)

static bool js_PluginHMSJS_PluginHMS_archiveAdd(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 7) {
        long playedTime = 0;
        long progress = 0;
        std::string description;
        bool supportCache;
        cocos2d::Data cover;
        std::string coverType;
        cocos2d::Data archData;
        ok &= seval_to_long(args[0], &playedTime);
        ok &= seval_to_long(args[1], &progress);
        ok &= seval_to_std_string(args[2], &description);
        ok &= seval_to_boolean(args[3], &supportCache);
        ok &= seval_to_Data(args[4], &cover);
        ok &= seval_to_std_string(args[5], &coverType);
        ok &= seval_to_Data(args[6], &archData);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveAdd : Error processing arguments");
        sdkbox::PluginHMS::archiveAdd(playedTime, progress, description, supportCache,
                                      cover.getBytes(), (int)cover.getSize(), coverType,
                                      archData.getBytes(), (int)archData.getSize());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 9);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveAdd)

static bool js_PluginHMSJS_PluginHMS_archiveUpdate(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 7) {
        std::string archId;
        long playedTime = 0;
        long progress = 0;
        std::string description;
        cocos2d::Data cover;
        std::string coverType;
        cocos2d::Data archData;

        ok &= seval_to_std_string(args[0], &archId);
        ok &= seval_to_long(args[1], &playedTime);
        ok &= seval_to_long(args[2], &progress);
        ok &= seval_to_std_string(args[3], &description);
        ok &= seval_to_Data(args[4], &cover);
        ok &= seval_to_std_string(args[5], &coverType);
        ok &= seval_to_Data(args[6], &archData);
        SE_PRECONDITION2(ok, false, "js_PluginHMSJS_PluginHMS_archiveUpdate : Error processing arguments");
        sdkbox::PluginHMS::archiveUpdate(archId,
                                         playedTime, progress, description,
                                         cover.getBytes(), (int)cover.getSize(), coverType,
                                         archData.getBytes(), (int)archData.getSize());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 9);
    return false;
}
SE_BIND_FUNC(js_PluginHMSJS_PluginHMS_archiveUpdate)

bool register_all_PluginHMSJS_helper(se::Object* obj) {
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginHMS");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginHMSJS_PluginHMS_setListener));
    plugin->defineFunction("archiveAdd", _SE(js_PluginHMSJS_PluginHMS_archiveAdd));
    plugin->defineFunction("archiveUpdate", _SE(js_PluginHMSJS_PluginHMS_archiveUpdate));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
