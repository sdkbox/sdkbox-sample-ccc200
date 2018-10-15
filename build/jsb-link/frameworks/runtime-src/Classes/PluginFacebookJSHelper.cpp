
#include "PluginFacebookJSHelper.h"
#include "SDKBoxJSHelper.h"
#include "PluginFacebook/PluginFacebook.h"

#include "scripting/js-bindings/manual/jsb_conversions.hpp"

#include "cocos2d.h"
#include "base/CCScheduler.h"
#include "platform/CCApplication.h"

using namespace sdkbox;

static const std::string FBGraphUser_ID          ("uid");
static const std::string FBGraphUser_NAME        ("name");
static const std::string FBGraphUser_FIRST_NAME  ("firstName");
static const std::string FBGraphUser_LAST_NAME   ("lastName");
static const std::string FBGraphUser_INSTALLED   ("isInstalled");

void FBGraphUserToJS(const sdkbox::FBGraphUser& info, cocos2d::ValueMap &map) {

    for( std::pair<std::string, std::string> _p : info.getFields() ) {
        map[_p.first] = _p.second;
    }

}

void FBInvitableFriendsInfoToJS(const sdkbox::FBInvitableFriendsInfo& ifap, cocos2d::ValueMap &jsret) {

    cocos2d::ValueVector jsarray;
    uint32_t index=0;
    for( auto u= ifap.begin(); u!=ifap.end(); ++u ) {
        cocos2d::ValueMap map;
        FBGraphUserToJS(*(u), map);
        jsarray.push_back(cocos2d::Value(map));
        index++;
    }

    // cursor data
    cocos2d::ValueMap jsobj;
    jsobj["next_url"] = ifap.getNextURL();
    jsobj["prev_url"] = ifap.getPrevURL();
    jsobj["prev_cursor"] = ifap.getPrevCursor();
    jsobj["next_cursor"] = ifap.getNextCursor();

    // data
    jsret["data"] = cocos2d::Value(jsarray);
    jsret["paging"] = cocos2d::Value(jsobj);
}

class FacebookListenerJS : public sdkbox::FacebookListener, public sdkbox::JSListenerBase
{
public:
    FacebookListenerJS() : sdkbox::JSListenerBase() {
    }

    virtual void onLogin(bool isLogin, const std::string& error)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,isLogin,error,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(isLogin));
                params.push_back(se::Value(error));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }

    virtual void onSharedSuccess(const std::string& message)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,message,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(message));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onSharedFailed(const std::string& message)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,message,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(message));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onSharedCancel()
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onAPI(const std::string& tag, const std::string& jsonData)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,tag,jsonData,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(tag));
                params.push_back(se::Value(jsonData));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onPermission(bool isLogin, const std::string& error)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,isLogin,error,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(isLogin));
                params.push_back(se::Value(error));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onFetchFriends(bool ok, const std::string& msg)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,ok,msg,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(ok));
                params.push_back(se::Value(msg));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onInviteFriendsResult(bool ok, const std::string& msg)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,ok,msg,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {

                se::ValueArray params;
                params.push_back(se::Value(ok));
                params.push_back(se::Value(msg));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onInviteFriendsWithInviteIdsResult(bool ok, const std::string& msg)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,ok,msg,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(ok));
                params.push_back(se::Value(msg));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onRequestInvitableFriends(const sdkbox::FBInvitableFriendsInfo& invitable_friends_and_pagination )
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,invitable_friends_and_pagination,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {

                cocos2d::ValueMap info;
                FBInvitableFriendsInfoToJS(invitable_friends_and_pagination, info);
                se::Value jsinfo;
                ccvaluemap_to_seval(info, &jsinfo);

                se::ValueArray params;
                params.push_back(se::Value(jsinfo));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onGetUserInfo(const sdkbox::FBGraphUser& userInfo )
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,userInfo,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {

                cocos2d::ValueMap info;
                FBGraphUserToJS(userInfo, info);
                se::Value jsinfo;
                ccvaluemap_to_seval(info, &jsinfo);

                se::ValueArray params;
                params.push_back(jsinfo);
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onRequestGiftResult(bool result, const std::string& msg)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,result,msg,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(result));
                params.push_back(se::Value(msg));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
    virtual void onSendGiftResult(bool result, const std::string& msg)
    {
        std::string funName(__FUNCTION__);
        cocos2d::Application::getInstance()->getScheduler()->performFunctionInCocosThread([funName,result,msg,this](){
            if (!_JSDelegate.isObject())
                return;

            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;
            se::Value func;
            _JSDelegate.toObject()->getProperty(funName.c_str(), &func);

            if (func.isObject() && func.toObject()->isFunction()) {
                se::ValueArray params;
                params.push_back(se::Value(result));
                params.push_back(se::Value(msg));
                bool ok = func.toObject()->call(params, _JSDelegate.toObject());
                if (!ok) {
                    se::ScriptEngine::getInstance()->clearException();
                }
            }
        });
    }
};

static sdkbox::FBShareInfo map_to_FBShareInfo(const std::map<std::string, std::string>& dict)
{
    sdkbox::FBShareInfo info;

    if (dict.find("title") != dict.end())
    {
        info.title = dict.find("title")->second;
    }
    if (dict.find("link") != dict.end())
    {
        info.link = dict.find("link")->second;
    }
    if (dict.find("text") != dict.end())
    {
        info.text = dict.find("text")->second;
    }
    if (dict.find("image") != dict.end())
    {
        info.image = dict.find("image")->second;
    }
    if (dict.find("type") != dict.end())
    {
        std::string type = dict.find("type")->second;
        if (type.compare("link") == 0)
        {
            info.type = sdkbox::FB_LINK;
        }
        else if (type.compare("photo") == 0)
        {
            info.type = sdkbox::FB_PHOTO;
        }
    }

    return info;
}

static bool js_PluginFacebookJS_PluginFacebook_share(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        bool ok = true;
        std::map<std::string, std::string> arg0;
        ok &= seval_to_std_map_string_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_share : Error processing arguments");
        sdkbox::PluginFacebook::share(map_to_FBShareInfo(arg0));
        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_share : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_share)

static bool js_PluginFacebookJS_PluginFacebook_api(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 4) {
        bool ok = true;
        std::string path;
        ok &= seval_to_std_string(args[0], &path);
        std::string method;
        ok &= seval_to_std_string(args[1], &method);
        std::map<std::string, std::string> param;
        ok &= seval_to_std_map_string_string(args[2], &param);
        std::string tag;
        ok &= seval_to_std_string(args[3], &tag);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_api : Error processing arguments");
        sdkbox::PluginFacebook::api(path, method, param, tag);

        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_api : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_api)

static bool js_PluginFacebookJS_PluginFacebook_dialog(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        bool ok = true;
        std::map<std::string, std::string> arg0;
        ok &= seval_to_std_map_string_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_dialog : Error processing arguments");
        sdkbox::PluginFacebook::dialog(map_to_FBShareInfo(arg0));

        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_dialog : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_dialog)

static bool js_PluginFacebookJS_PluginFacebook_requestReadPermissions(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        bool ok = true;
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_requestReadPermissions : Error processing arguments");
        sdkbox::PluginFacebook::requestReadPermissions(arg0);

        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_requestReadPermissions : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_requestReadPermissions)

static bool js_PluginFacebookJS_PluginFacebook_requestPublishPermissions(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        bool ok = true;
        std::vector<std::string> arg0;
        ok &= seval_to_std_vector_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_requestPublishPermissions : Error processing arguments");
        sdkbox::PluginFacebook::requestPublishPermissions(arg0);
        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_requestPublishPermissions : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_requestPublishPermissions)

static bool js_PluginFacebookJS_PluginFacebook_getPermissionList(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 0) {
        std::vector<std::string> ret = sdkbox::PluginFacebook::getPermissionList();
        se::Value jsret;
        std_vector_string_to_seval(ret, &jsret);
        s.rval().setObject(jsret.toObject());
        return true;
    }
    SE_REPORT_ERROR("js_PluginFacebookJS_PluginFacebook_getPermissionList : wrong number of arguments");
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_getPermissionList)

static bool js_PluginFacebookJS_PluginFacebook_getFriends(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 0) {
        std::vector<sdkbox::FBGraphUser> ret = sdkbox::PluginFacebook::getFriends();
        size_t size = ret.size();

        cocos2d::ValueVector array;
        for (int i = 0; i < size; i++)
        {
            const sdkbox::FBGraphUser& friendInfo = ret.at(i);
            cocos2d::ValueMap friendInfoDict;
            friendInfoDict[FBGraphUser_ID] = cocos2d::Value(friendInfo.uid);
            friendInfoDict[FBGraphUser_NAME] = cocos2d::Value(friendInfo.name);
            friendInfoDict[FBGraphUser_FIRST_NAME] = cocos2d::Value(friendInfo.firstName);
            friendInfoDict[FBGraphUser_LAST_NAME] = cocos2d::Value(friendInfo.lastName);
            friendInfoDict[FBGraphUser_INSTALLED] = cocos2d::Value(friendInfo.isInstalled);

            array.push_back(cocos2d::Value(friendInfoDict));
        }

        se::Value jsret;
        ccvaluevector_to_seval(array, &jsret);
        s.rval().setObject(jsret.toObject());

        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_getFriends)

static bool js_PluginFacebookJS_PluginFacebook_canPresentWithFBApp(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1) {
        bool ok = true;
        std::map<std::string, std::string> arg0;
        ok &= seval_to_std_map_string_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginFacebookJS_PluginFacebook_canPresentWithFBApp : Error processing arguments");
        bool canPresent = sdkbox::PluginFacebook::canPresentWithFBApp(map_to_FBShareInfo(arg0));

        s.rval().setBoolean(canPresent);

        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_canPresentWithFBApp)

static bool js_PluginFacebookJS_PluginFacebook_inviteFriends(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 2) {
        bool ok = true;
        std::string app_link_url;
        ok &= seval_to_std_string(args[0], &app_link_url);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        std::string preview_image_url;
        ok &= seval_to_std_string(args[1], &preview_image_url);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        sdkbox::PluginFacebook::inviteFriends( app_link_url, preview_image_url );
        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_inviteFriends)

static bool js_PluginFacebookJS_PluginFacebook_requestInvitableFriends(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        bool ok = true;

        std::map<std::string, std::string> arg0;
        ok &= seval_to_std_map_string_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        sdkbox::PluginFacebook::requestInvitableFriends(arg0);

        return true;
    }
    else if (argc == 0)
    {
        std::map<std::string, std::string> arg0;
        sdkbox::PluginFacebook::requestInvitableFriends(arg0);
        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_requestInvitableFriends)

static bool js_PluginFacebookJS_PluginFacebook_inviteFriendsWithInviteIds(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 3)
    {
        bool ok = true;

        std::vector<std::string> ids;
        ok &= seval_to_std_vector_string(args[0], &ids);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        std::string title;
        ok &= seval_to_std_string(args[1], &title);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        std::string text;
        ok &= seval_to_std_string(args[2], &text);
        SE_PRECONDITION2(ok, false, "Error processing arguments");

        sdkbox::PluginFacebook::inviteFriendsWithInviteIds(ids, title, text);
        return true;
    }
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_PluginFacebook_inviteFriendsWithInviteIds)

static bool js_PluginFacebookJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        FacebookListenerJS* nativeDelegate = dynamic_cast<FacebookListenerJS*>(sdkbox::PluginFacebook::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) FacebookListenerJS();
            sdkbox::PluginFacebook::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginFacebookJS_setListener)

extern se::Object* __jsb_sdkbox_PluginFacebook_proto;
extern se::Class* __jsb_sdkbox_PluginFacebook_class;
bool register_all_PluginFacebookJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginFacebook");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginFacebookJS_setListener));
    plugin->defineFunction("share", _SE(js_PluginFacebookJS_PluginFacebook_share));
    plugin->defineFunction("api", _SE(js_PluginFacebookJS_PluginFacebook_api));
    plugin->defineFunction("dialog", _SE(js_PluginFacebookJS_PluginFacebook_dialog));
    plugin->defineFunction("requestReadPermissions", _SE(js_PluginFacebookJS_PluginFacebook_requestReadPermissions));
    plugin->defineFunction("requestPublishPermissions", _SE(js_PluginFacebookJS_PluginFacebook_requestPublishPermissions));
    plugin->defineFunction("getPermissionList", _SE(js_PluginFacebookJS_PluginFacebook_getPermissionList));
    plugin->defineFunction("getFriends", _SE(js_PluginFacebookJS_PluginFacebook_getFriends));
    plugin->defineFunction("canPresentWithFBApp", _SE(js_PluginFacebookJS_PluginFacebook_canPresentWithFBApp));
    plugin->defineFunction("inviteFriends", _SE(js_PluginFacebookJS_PluginFacebook_inviteFriends));
    plugin->defineFunction("requestInvitableFriends", _SE(js_PluginFacebookJS_PluginFacebook_requestInvitableFriends));
    plugin->defineFunction("inviteFriendsWithInviteIds", _SE(js_PluginFacebookJS_PluginFacebook_inviteFriendsWithInviteIds));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
