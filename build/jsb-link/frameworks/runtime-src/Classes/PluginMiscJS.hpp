#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginMisc_proto;
extern se::Class* __jsb_sdkbox_PluginMisc_class;

bool js_register_sdkbox_PluginMisc(se::Object* obj);
bool register_all_PluginMiscJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginMiscJS_PluginMisc_init);
SE_DECLARE_FUNC(js_PluginMiscJS_PluginMisc_cleanLocalNotify);
SE_DECLARE_FUNC(js_PluginMiscJS_PluginMisc_localNotify);
SE_DECLARE_FUNC(js_PluginMiscJS_PluginMisc_handleLocalNotify);

