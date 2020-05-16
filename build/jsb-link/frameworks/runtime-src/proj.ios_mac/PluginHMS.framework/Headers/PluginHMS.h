/****************************************************************************

 Copyright (c) 2014-2020 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_HMS_H_
#define _PLUGIN_HMS_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class HMSListener {
    public:

    /*
     * login callback
     * code: 0, success; !=0, failed
     */
    virtual void onLogin(int code, const std::string& msg) = 0;
    };

    class PluginHMS {
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
         * Set listener to listen for adcolony events
         */
        static void setListener(HMSListener* listener);

        /**
         * Get the listener
         */
        static HMSListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * HMS provider three way to login
         * loginType: 0, slient login 1, login with HuaweiID(ID Token) 2, login with HuaweID(Authorization Code)
         *
         * slient login should invoke after `login with HuaweiID`(loginType 2 or 3) have success
         *
         * will trigger `onLogin` event. and the msg paramater will include account info when login success
         *
         */
        static void login(int loginType);

        /**
         * logout HMS
         */
        static void logout();

    };
}

#endif
