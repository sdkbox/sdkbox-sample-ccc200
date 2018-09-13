#pragma once

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

namespace se {
    class Object;
}

bool register_all_PluginAdColonyJS_helper(se::Object* obj);
