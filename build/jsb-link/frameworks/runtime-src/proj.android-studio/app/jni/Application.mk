APP_STL := gnustl_static

# Uncomment this line to compile to armeabi-v7a, your application will run faster but support less devices
APP_ABI := armeabi-v7a

APP_CPPFLAGS := -frtti \
-std=c++11 \
-fsigned-char
APP_LDFLAGS := -latomic

# To solve windows commands char length too long
#APP_SHORT_COMMANDS

USE_ARM_MODE := 1
#USE_ANY_SDK

ifeq ($(USE_ANY_SDK),1)
APP_CPPFLAGS += -DPACKAGE_AS
endif

ifeq ($(NDK_DEBUG),1)
APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
APP_CFLAGS += -DCOCOS2D_DEBUG=1
APP_OPTIM := debug
else
APP_CPPFLAGS += -DNDEBUG
APP_CFLAGS += -DNDEBUG
APP_OPTIM := release
endif

# Some Android Simulators don't support SSE instruction, so disable it for x86 arch.
APP_CPPFLAGS += -U__SSE__
APP_PLATFORM := android-9
USE_VIDEO := 1
USE_WEB_VIEW := 1
USE_EDIT_BOX := 1
USE_AUDIO := 1
USE_SPINE := 1
USE_DRAGONBONES := 1
USE_SOCKET := 1
