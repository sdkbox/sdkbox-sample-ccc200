#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginShare_proto;
extern se::Class* __jsb_sdkbox_PluginShare_class;

bool js_register_sdkbox_PluginShare(se::Object* obj);
bool register_all_PluginShareJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_setSharePanelTitle);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_setSharePanelCancel);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_setFileProviderAuthorities);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_init);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_logoutTwitter);
SE_DECLARE_FUNC(js_PluginShareJS_PluginShare_setGDPR);

