/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_REVIEW_H_
#define _PLUGIN_REVIEW_H_

#include <string>
#include <vector>
#include <map>
#include "sdkbox/Sdkbox.h"

namespace sdkbox
{
    class ReviewListener
    {
    public:

        /**
         * trigger when alert prompt show
         */
        virtual void onDisplayAlert() = 0;

        /**
         * trigger when user refuse to rate
         */
        virtual void onDeclineToRate() = 0;

        /**
         * trigger when user want to rate
         */
        virtual void onRate() = 0;

        /**
         * trigger when user want to remind later
         */
        virtual void onRemindLater() = 0;
    };

    class PluginReview
    {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init(const char* jsonconfig = 0);

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(ReviewListener* listener);

        /**
         * Get the listener
         */
        static ReviewListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Tells 'SDKBox review plugin' to try and show the prompt (a rating alert).
         * if you call `show` with `false` or null params,
         * the prompt will be showed if there is connection available,
         * the user hasn't declined to rate or hasn't rated current version.
         * if the item `tryPromptWhenInit` in sdkbox.config is false, you can call this try to show prompt
         * if you call `show` with `true` params
         * the prompt will be showed without checks (the prompt is always displayed).
         * The case where you should call this is if your app has an
         * explicit "Rate this app" command somewhere. This is similar to rateApp,
         * but instead of jumping to the review directly, an intermediary prompt is displayed.
         * another case is for debug
         */
        static void show(bool force = false);

        /**
         * goto rating page directly
         */
        static void rate();

        /*
         Tells `SDKbox reivew plugin` that the user performed a significant event. A significant
         event is whatever you want it to be. If you're app is used to make VoIP
         calls, then you might want to call this method whenever the user places
         a call. If it's a game, you might want to call this whenever the user
         beats a level boss.
         If the user has performed enough significant events and used the app enough,
         you can suppress the rating alert by passing NO for canPromptForRating. The
         rating alert will simply be postponed until it is called again with YES for
         canPromptForRating. The rating alert can also be triggered by appLaunched:
         and appEnteredForeground: (as long as you pass YES for canPromptForRating
         in those methods).
         */
        static void userDidSignificantEvent(bool canPromptForRating);

        /*
         * if you want to use custom string when prompt. there have two ways:

            1. modify res in `plugin_review_res_project` project (Recommend)

            2. set your custom string in sdkbox_config.json

            ```json
            {
                "ios": {
                    "Review":{
                        ...
                        "promptTitle":"cutom tile",
                        "promptMessage":"this is custom message",
                        "promptCancel":"取消",
                        "promptRate":"rate打分",
                        "promptRateLater":"稍后later"
                        ...
                    }
                }
            }
            ```

            this way will disable local language, if your app needn't localization, can use this way.
         *
         */
        /*
         * Set customized title for alert view.
         */
        SDKBOX_DEPRECATED("setTitle") static void setTitle(const std::string& title);

        /*
         * Set customized message for alert view.
         */
        SDKBOX_DEPRECATED("setMessage") static void setMessage(const std::string& message);

        /*
         * Set customized cancel button title for alert view.
         */
        SDKBOX_DEPRECATED("setCancelButtonTitle") static void setCancelButtonTitle(const std::string& cancelTitle);

        /*
         * Set customized rate button title for alert view.
         */
        SDKBOX_DEPRECATED("setRateButtonTitle") static void setRateButtonTitle(const std::string& rateTitle);

        /*
         * Set customized rate later button title for alert view.
         */
        SDKBOX_DEPRECATED("setRateLaterButtonTitle") static void setRateLaterButtonTitle(const std::string& rateLaterTitle);

    };
}

#endif
