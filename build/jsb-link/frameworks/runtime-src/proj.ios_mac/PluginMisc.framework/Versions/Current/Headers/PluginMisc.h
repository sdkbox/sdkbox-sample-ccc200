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
         * delayMillisecond: delay millisecond to notify, just valid on iOS
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
