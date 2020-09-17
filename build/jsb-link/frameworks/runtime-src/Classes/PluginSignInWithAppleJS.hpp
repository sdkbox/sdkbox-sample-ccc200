#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginSignInWithApple_proto;
extern se::Class* __jsb_sdkbox_PluginSignInWithApple_class;

bool js_register_sdkbox_PluginSignInWithApple(se::Object* obj);
bool register_all_PluginSignInWithAppleJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_signWithExistingAccount);
SE_DECLARE_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_sign);
SE_DECLARE_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_init);
SE_DECLARE_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_isAvailable);
SE_DECLARE_FUNC(js_PluginSignInWithAppleJS_PluginSignInWithApple_setGDPR);

