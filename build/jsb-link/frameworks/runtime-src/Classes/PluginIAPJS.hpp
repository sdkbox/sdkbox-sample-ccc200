#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_IAP_proto;
extern se::Class* __jsb_sdkbox_IAP_class;

bool js_register_sdkbox_IAP(se::Object* obj);
bool register_all_PluginIAPJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_purchase);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_getInitializedErrMsg);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_updateStorePromotionVisibility);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_updateStorePromotionOrder);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_restore);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_isAutoFinishTransaction);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_fetchStorePromotionOrder);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_refresh);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_fetchStorePromotionVisibility);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_setAutoFinishTransaction);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_getPurchaseHistory);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_init);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_setDebug);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_requestUpdateTransaction);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_enableUserSideVerification);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_setGDPR);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_finishTransaction);
SE_DECLARE_FUNC(js_PluginIAPJS_IAP_removeListener);

