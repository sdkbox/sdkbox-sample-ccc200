#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginSdkboxAds_proto;
extern se::Class* __jsb_sdkbox_PluginSdkboxAds_class;

bool js_register_sdkbox_PluginSdkboxAds(se::Object* obj);
bool register_all_PluginSdkboxAdsJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_hideAd);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_hide);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_placement);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_cache);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_init);
SE_DECLARE_FUNC(js_PluginSdkboxAdsJS_PluginSdkboxAds_isAvailable);

