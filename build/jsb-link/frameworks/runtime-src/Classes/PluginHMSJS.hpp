#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_sdkbox_PluginHMS_proto;
extern se::Class* __jsb_sdkbox_PluginHMS_class;

bool js_register_sdkbox_PluginHMS(se::Object* obj);
bool register_all_PluginHMSJS(se::Object* obj);
SE_DECLARE_FUNC(js_PluginHMSJS_PluginHMS_init);
SE_DECLARE_FUNC(js_PluginHMSJS_PluginHMS_logout);
SE_DECLARE_FUNC(js_PluginHMSJS_PluginHMS_login);
SE_DECLARE_FUNC(js_PluginHMSJS_PluginHMS_setGDPR);

