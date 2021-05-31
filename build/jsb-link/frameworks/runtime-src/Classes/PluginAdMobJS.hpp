#pragma once

#include "SDKBoxJSHelper.h"

#ifdef SDKBOX_JSBINDING_CC3
namespace se { class Object; }
#else

#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

#endif

extern se::Object* __jsb_sdkbox_PluginAdMob_proto;
extern se::Class* __jsb_sdkbox_PluginAdMob_class;

bool js_register_sdkbox_PluginAdMob(se::Object* obj);
bool register_all_PluginAdMobJS(se::Object* obj);

















