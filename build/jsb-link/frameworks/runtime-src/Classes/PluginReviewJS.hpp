#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginReview_proto;
extern se::Class* __jsb_sdkbox_PluginReview_class;

bool js_register_sdkbox_PluginReview(se::Object* obj);
bool register_all_PluginReviewJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginReviewJS_PluginReview_userDidSignificantEvent);
SE_DECLARE_FUNC(js_PluginReviewJS_PluginReview_show);
SE_DECLARE_FUNC(js_PluginReviewJS_PluginReview_rate);
SE_DECLARE_FUNC(js_PluginReviewJS_PluginReview_init);

