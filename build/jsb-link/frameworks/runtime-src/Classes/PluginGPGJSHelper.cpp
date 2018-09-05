
#include "PluginGPGJSHelper.h"
#include "PluginGPG/PluginGPG.h"
#include "PluginGPGJS.hpp"
#include "SDKBoxJSHelper.h"

#include "cocos2d.h"
#include "base/CCScheduler.h"
#include "platform/CCApplication.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"

void sdkbox::GPGWrapper::NotifyToScripting( int id, const std::string& str_json ) {
    if ( id >= 0 ) {
        void* dummyTarget = (void*)1;
        cocos2d::Application::getInstance()->getScheduler()->schedule([id, str_json](float dt) {
            se::ScriptEngine::getInstance()->clearException();
            se::AutoHandleScope hs;

            se::ValueArray args;
            args.reserve(2);
            args.push_back(se::Value(id));
            args.push_back(se::Value(str_json));

            se::Object* globalObj = se::ScriptEngine::getInstance()->getGlobalObject();
            se::Value func;

            globalObj->getProperty("__nativeNotify", &func);
            assert(func.isObject() && func.toObject()->isFunction());
            func.toObject()->call(args, globalObj);
        }, dummyTarget, 0, 0, false, false, "sdkbox-gpg-notifytoscripting");
    } else {
        CCLOG("Notifying on wrong callback id: %d", id );
    }
}

bool register_all_PluginGPGJS_helper(se::Object* obj) {
    se::ScriptEngine::getInstance()->runScript("res/sdkboxgpg.js");

    return true;
}
