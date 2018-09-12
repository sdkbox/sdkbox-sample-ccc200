#include "PluginShareJSHelper.h"
#include "PluginShare/PluginShare.h"
#include "SDKBoxJSHelper.h"

class ShareListenerJS : public sdkbox::ShareListener, public sdkbox::JSListenerBase
{
public:
    ShareListenerJS() : sdkbox::JSListenerBase() {
    }

    void onShareState(const sdkbox::SocialShareResponse& response) {
        MAKE_V8_HAPPY

        cocos2d::ValueMap data;
        data["state"] = response.state;
        data["error"] = response.error;
        data["platform"] = response.platform;
        se::Value jsdata;
        ccvaluemap_to_seval(data, &jsdata);

        se::ValueArray args;
        args.push_back(jsdata);
        invokeJSFun(__FUNCTION__, args);
    }
};

bool js_PluginShareJS_PluginShare_share(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    bool ok = true;

    do {
        if (argc == 1) {
            sdkbox::SocialShareInfo shareInfo;
            cocos2d::ValueMap map;
            ok &= seval_to_ccvaluemap(args[0], &map);
            shareInfo.text = map["text"].asString();
            shareInfo.title = map["title"].asString();
            shareInfo.image = map["image"].asString();
            shareInfo.link = map["link"].asString();
            shareInfo.showDialog = map["showDialog"].asBool();
            shareInfo.platform = (sdkbox::SocialPlatform)map["platform"].asInt();
            sdkbox::PluginShare::share(shareInfo);

            return true;
        }
    } while (0);

    SE_REPORT_ERROR("js_PluginShareJS_PluginShare_share : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_share)

bool js_PluginShareJS_PluginShare_nativeShare(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    bool ok = true;

    do {
        if (argc == 1) {
            sdkbox::SocialShareInfo shareInfo;
            cocos2d::ValueMap map;
            ok &= seval_to_ccvaluemap(args[0], &map);
            shareInfo.text = map["text"].asString();
            shareInfo.title = map["title"].asString();
            shareInfo.image = map["image"].asString();
            shareInfo.link = map["link"].asString();
            shareInfo.showDialog = map["showDialog"].asBool();
            shareInfo.platform = (sdkbox::SocialPlatform)map["platform"].asInt();
            sdkbox::PluginShare::nativeShare(shareInfo);

            return true;
        }
    } while (0);

    SE_REPORT_ERROR("js_PluginShareJS_PluginShare_nativeShare : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_PluginShare_nativeShare)

void share_register_constants(se::Object* share)
{
    se::Value v;
    cocos2d::ValueMap enums;
    enums.clear();
    enums["SocialShareStateNone"] = 0;
    enums["SocialShareStateUnkonw"] = 1;
    enums["SocialShareStateBegin"] = 2;
    enums["SocialShareStateSuccess"] = 3;
    enums["SocialShareStateFail"] = 4;
    enums["SocialShareStateCancelled"] = 5;
    enums["SocialShareStateSelectShow"] = 6;
    enums["SocialShareStateSelected"] = 7;
    enums["SocialShareStateSelectCancelled"] = 8;

    ccvaluemap_to_seval(enums, &v);
    share->setProperty("SocialShareState", v);

    enums.clear();
    enums["Platform_Unknow"] = 0;
    enums["Platform_Twitter"] = 1;
    enums["Platform_Facebook"] = 2;
    enums["Platform_SMS"] = 5;
    enums["Platform_EMail"] = 6;
    enums["Platform_Mail"] = 6;
    enums["Platform_Native"] = 7;

    enums["Platform_Select"] = 3;
    enums["Platform_All"] = 4;

    ccvaluemap_to_seval(enums, &v);
    share->setProperty("SocialPlatform", v);

}

static bool js_PluginShareJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        ShareListenerJS* nativeDelegate = dynamic_cast<ShareListenerJS*>(sdkbox::PluginShare::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) ShareListenerJS();
            sdkbox::PluginShare::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);


        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginShareJS_setListener)

extern se::Object* __jsb_sdkbox_PluginShare_proto;
extern se::Class* __jsb_sdkbox_PluginShare_class;
bool register_all_PluginShareJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginShare");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginShareJS_setListener));
    plugin->defineFunction("share", _SE(js_PluginShareJS_PluginShare_share));
    plugin->defineFunction("nativeShare", _SE(js_PluginShareJS_PluginShare_nativeShare));

    auto sdkboxValue = sdkbox::getPluginValue(obj, "sdkbox");
    share_register_constants(sdkboxValue.toObject());

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

