LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

ifeq ($(USE_ARM_MODE),1)
LOCAL_ARM_MODE := arm
endif

LOCAL_SRC_FILES := hellojavascript/main.cpp \
../../../Classes/AppDelegate.cpp \
../../../Classes/jsb_module_register.cpp \
../../../Classes/PluginGPGJS.cpp \
../../../Classes/PluginGPGJSHelper.cpp \
../../../Classes/SDKBoxJSHelper.cpp
LOCAL_CPPFLAGS := -DSDKBOX_ENABLED \
-DSDKBOX_COCOS_CREATOR
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
./gpg/include/

ifeq ($(USE_ANY_SDK),1)
LOCAL_SRC_FILES += ../../../Classes/anysdk/SDKManager.cpp ../../../Classes/anysdk/jsb_anysdk_basic_conversions.cpp ../../../Classes/anysdk/manualanysdkbindings.cpp ../../../Classes/anysdk/jsb_anysdk_protocols_auto.cpp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/anysdk

LOCAL_WHOLE_STATIC_LIBRARIES := PluginProtocolStatic
endif

LOCAL_WHOLE_STATIC_LIBRARIES += PluginGPG
LOCAL_WHOLE_STATIC_LIBRARIES += sdkbox
LOCAL_WHOLE_STATIC_LIBRARIES += gpg-1

LOCAL_STATIC_LIBRARIES := cocos2dx_static

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_DEBUG=2

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path,$(LOCAL_PATH))


$(call import-module, cocos)
$(call import-module, ./sdkbox)
$(call import-module, ./plugingpg)
$(call import-module, ./gpg)
