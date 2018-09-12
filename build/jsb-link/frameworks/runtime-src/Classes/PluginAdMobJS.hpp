#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginAdMob_proto;
extern se::Class* __jsb_sdkbox_PluginAdMob_class;

bool js_register_sdkbox_PluginAdMob(se::Object* obj);
bool register_all_PluginAdMobJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_getCurrBannerHeight);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_getCurrBannerHeightInPixel);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_hide);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_setTestDevices);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_show);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_getCurrBannerWidthInPixel);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_cache);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_getCurrBannerWidth);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_init);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_getVersion);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_setGDPR);
SE_DECLARE_FUNC(js_PluginAdMobJS_PluginAdMob_isAvailable);

