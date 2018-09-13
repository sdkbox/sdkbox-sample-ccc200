LOCAL_PATH := $(call my-dir)

# -------- include adcolony --------
include $(CLEAR_VARS)
LOCAL_MODULE := libadcolonyso
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libadcolony.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libjsso
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libjs.so
include $(PREBUILT_SHARED_LIBRARY)
# -------- include adcolony end --------

include $(CLEAR_VARS)
LOCAL_MODULE := PluginAdColony
LOCAL_MODULE_FILENAME := lib$(LOCAL_MODULE)

ifeq ($(APP_STL), c++_static)
    LOCAL_SRC_FILES := libs_c++_static/$(TARGET_ARCH_ABI)/$(LOCAL_MODULE_FILENAME).a
else
    LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/$(LOCAL_MODULE_FILENAME).a
endif

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_EXPORT_LDLIBS := -llog

LOCAL_STATIC_LIBRARIES := sdkbox

include $(PREBUILT_STATIC_LIBRARY)
