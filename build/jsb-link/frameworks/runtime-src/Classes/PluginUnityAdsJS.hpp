#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginUnityAds_proto;
extern se::Class* __jsb_sdkbox_PluginUnityAds_class;

bool js_register_sdkbox_PluginUnityAds(se::Object* obj);
bool register_all_PluginUnityAdsJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_isSupported);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_isReady);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_getPlacementState);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_show);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_init);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_setServerId);
SE_DECLARE_FUNC(js_PluginUnityAdsJS_PluginUnityAds_setGDPR);

