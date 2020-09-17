/****************************************************************************

 Copyright (c) 2014-2020 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_SIGN_WITH_APPLE_H_
#define _PLUGIN_SIGN_WITH_APPLE_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class SignInWithAppleListener {
    public:

        /**
         * authorization delegate
         * 
         * https://developer.apple.com/documentation/authenticationservices/asauthorizationcontrollerdelegate
         * 
         */
        virtual void onAuthorizationDidComplete(const std::string& authInfo) = 0;
        virtual void onAuthorizationCompleteWithError(const std::string& authInfo) = 0;

        /**
         * authorization status
         *
         * https://developer.apple.com/documentation/authenticationservices/asauthorizationappleidprovidercredentialstate
         *
         */
        virtual void onAuthorizationStatus(const std::string& authState) {};
    };

    class PluginSignInWithApple {
    public:

        /**
         * Set GDPR
         *
         * **NOTE**: please call before 'init' function
         */
        static void setGDPR(bool enabled);

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for hms events
         */
        static void setListener(SignInWithAppleListener* listener);

        /**
         * Get the listener
         */
        static SignInWithAppleListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        static bool isAvailable();

        static void sign();
        
        static void signWithExistingAccount();
    };
}

#endif
