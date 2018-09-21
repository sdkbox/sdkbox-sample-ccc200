/****************************************************************************

 Copyright (c) 2014-2015 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_ONESIGNAL_H_
#define _PLUGIN_ONESIGNAL_H_

#include <string>
#include <map>
#include <vector>

namespace sdkbox {

    // log level
    const static int OneSignalLogNone    = 0;
    const static int OneSignalLogFatal   = 1;
    const static int OneSignalLogError   = 2;
    const static int OneSignalLogWarn    = 3;
    const static int OneSignalLogInfo    = 4;
    const static int OneSignalLogDebug   = 5;
    const static int OneSignalLogVerbose = 6;

    class OneSignalListener;
    class PluginOneSignal {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for onesignal events
         */
        static void setListener(OneSignalListener* listener);

        /**
         * Get the listener
         */
        static OneSignalListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Only use if you set "auto_register":false in sdkbox_config.json (iOS only)
         */
        static void registerForPushNotifications();

        /**
         * Enable logging to help debug if you run into an issue setting up OneSignal. This selector
         * is static so you can call it before OneSignal init. The following options are available
         * with increasingly more information;
         * sdkbox::OneSignalLogNone, sdkbox::OneSignalLogFatal, sdkbox::OneSignalLogError,
         * sdkbox::OneSignalLogWarn, sdkbox::OneSignalLogInfo, sdkbox::OneSignalLogDebug,
         * sdkbox::OneSignalLogVerbose
         */
        static void setLogLevel(int logLevel, int visualLogLevel);

        /**
         * Tag a user based on an app event of your choosing so later you can create segments on
         * onesignal.com to target these users.
         *
         * callback: `onSendTag`
         */
        static void sendTag(const std::string& key, const std::string& value);

        /**
         * Set email
         */
        static void setEmail(const std::string& email);

        /**
         * Retrieve a list of tags that have been set on the user from the OneSignal server.
         *
         * callback: `onGetTags`
         */
        static void getTags();

        /**
         * Deletes a tag that was previously set on a user with sendTag
         */
        static void deleteTag(const std::string& key);

        /**
         * Lets you retrieve the OneSignal user id and the Google registration id. Your handler is
         * called after the device is successfully registered with OneSignal.
         *
         * callback: `onIdsAvailable`
         */
        static void idsAvailable();

        /**
         * By default this is false and notifications will not be shown when the user is in your app,
         * instead the NotificationOpenedHandler is fired. If set to true notifications will be shown
         * as native alert boxes if a notification is received when the user is in your app. The
         * NotificationOpenedHandler is then fired after the alert box is closed.
         */
        static void enableInAppAlertNotification(bool enable);

        /**
         * You can call this method with false to opt users out of receiving all notifications through
         * OneSignal. You can pass true later to opt users back into notifications.
         */
        static void setSubscription(bool enable);

        /**
         * Allows you to send notifications from user to user or schedule ones in the future to be
         * delivered to the current device.
         *
         * callback: `onPostNotification`
         */
        static void postNotification(const std::string& jsonString);

        /**
         * Prompts the user for location permissions. This allows for geotagging so you can send
         * notifications to users based on location.
         *
         * Note: Make sure you also have the required location permission in your AndroidManifest.xml.
         */
        static void promptLocation();
        };

    class OneSignalListener {
    public:
        virtual void onSendTag(bool success, const std::string& key, const std::string& message) {}
        virtual void onGetTags(const std::string& jsonString) {}
        virtual void onIdsAvailable(const std::string& userId, const std::string& pushToken) {}
        virtual void onPostNotification(bool success, const std::string& message) {}
        virtual void onNotification(bool isActive, const std::string& message, const std::string& additionalData) {}
        virtual void onNotificationOpened(const std::string &message) {}
        virtual void onNotificationReceived(const std::string& message) {}
    };
}

#endif
