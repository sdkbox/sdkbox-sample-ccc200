/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef __SDKBOX_GPG_PLATFORM_CONFIG_
#define __SDKBOX_GPG_PLATFORM_CONFIG_

#include <gpg/gpg.h>
#include "CocosPlatform.h"

std::string getGPGURLSchemes();

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    #include "bridge.h"
    #include "Log.h"
    #include "SdkboxCore.h"
    static bool __initialized = false;

    class SdkboxGPGListener : public sdkbox::AppLifeCycleListener {
        virtual void onActivityResult( void*activity, int request_code, int result_code, void*data ) {
             gpg::AndroidSupport::OnActivityResult( sdkbox::JNIUtils::__getEnv(), (jobject)activity, (jint)request_code, (jint)result_code, (jobject)data);
        }
    };

    std::unique_ptr<gpg::PlatformConfiguration> CreatePlatformConfiguration() {
        
        if (!__initialized) {
            sdkbox::Logger::i("SDKBOX_GPG", "SDKBOX<->GPG Initialization with jni_onload.");
            gpg::AndroidInitialization::JNI_OnLoad(sdkbox::JNIUtils::__getVM());	

            sdkbox::SdkboxCore::getInstance()->addListener( new SdkboxGPGListener() );

            __initialized = true;
        }

        gpg::AndroidPlatformConfiguration* config = new gpg::AndroidPlatformConfiguration();
        config->SetActivity(sdkbox::JNIUtils::__getActivity());

        return std::unique_ptr<gpg::PlatformConfiguration>(config);
    }

#else

    std::unique_ptr<gpg::PlatformConfiguration> CreatePlatformConfiguration() {
        std::string client_id = getGPGURLSchemes();
        gpg::IosPlatformConfiguration* config = new gpg::IosPlatformConfiguration();
        config->SetClientID( client_id );
        
        return std::unique_ptr<gpg::PlatformConfiguration>(config);
    }

#endif

#endif
