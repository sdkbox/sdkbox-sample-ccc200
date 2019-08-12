/****************************************************************************

 Copyright (c) 2014-2015 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_MISC_H_
#define _PLUGIN_MISC_H_

#include <string>

namespace sdkbox {

    class MiscListener;
    class PluginMisc {
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
         * Set listener to listen for misc events
         */
        static void setListener(MiscListener* listener);

        /**
         * Get the listener
         */
        static MiscListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Local Notification
         *
         * title: notification title, just valid on android
         * content: notification content
         * delayMillisecond: delay millisecond to notify
         *
         * return notifyID
         */
        static int localNotify(const std::string& title, const std::string& content, int delayMillisecond);

        /**
         * Clear Local Notification
         *
         * notificationID: notification id, 0: will cancel all local notify
         */
        static void cleanLocalNotify(int notifyID = 0);

        /**
         * Handle Local Notification, just For iOS
         *
         * on Android, please use com.sdkbox.plugin.PluginMisc.onHandleNotification(intent);
         *
         */
        static void handleLocalNotify(const std::string& notificationUserInfo);

        /**
         * get current platform, iOS or Android
         *
         */
        static std::string getPlatformName();

        /**
         * just valid on android, can get meta data from AndroidManifest.xml
         *
         */
        static std::string getMetaData(const std::string& name);

        /**
         * get current iap provider of SDKBox IAP
         * return 'Apple', 'Google', 'Amazon' or 'Playphone'
         */
        static std::string getIAPProvider();

        /**
         * get app version
         *
         */
        static std::string getAppVersion();

        /**
         * get iOS app build version
         *
         */
        static std::string getAppBuildVersion();

        /**
         * get android app version code
         *
         */
        static int getAppVersionCode();

        /**
         * get device info
         */
        static std::string getDeviceInfo();

        /*** Keychain is valid on iOS  ***/
        /**
         * set keychain service
         */
        static void setKeychainService(const std::string& service);

        /**
         * set keychain accessgroup
         */
        static void setKeychainAccessGroup(const std::string& group);

        /**
         * store account data in keychain, if exist will update it
         * return SecurityFrameworkResultCode: https://developer.apple.com/documentation/security/1542001-security_framework_result_codes
         */
        static int storeStringInKeychain(const std::string& account, const std::string& value);

        /**
         * fetch account data from keychain
         */
        static const std::string fetchStringInKeychain(const std::string& account);

        /**
         * remove account in keychain
         */
        static int removeDataInKeychain(const std::string& account);
    };

    class MiscListener {
    public:

        /**
         * Notifies the delegate that user tap the notify
         */
        virtual void onHandleLocalNotify(const std::string& payloadJson) {};

    };
}

#endif
