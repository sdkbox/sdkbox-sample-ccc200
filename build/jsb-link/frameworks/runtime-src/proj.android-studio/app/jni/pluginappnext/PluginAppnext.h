/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_APPNEXT_H_
#define _PLUGIN_APPNEXT_H_

#include <string>

namespace sdkbox {

    class AppnextListener;
    class PluginAppnext {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for appnext events
         */
        static void setListener(AppnextListener* listener);

        /**
         * Get the listener
         */
        static AppnextListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Hide advertisement
         */
        static void hideAd();

        /**
         * Show advertisement
         */
        static void showAd();

        /**
         * Refresh advertisement
         */
        static void refreshAds();

        /**
         * Cache advertisement
         */
        static void cacheAd(const std::string& name);

        /**
         * Check if advertisement is ready
         */
        static bool isAdReady();

        /**
         * Cache video with @name
         */
        static void cacheVideo(const std::string& name);

        /**
         * show video with @name
         */
        static void showVideo(const std::string& name);

        /**
         * Refresh video with @name
         */
        static void refreshVideo(const std::string& name);

        /**
         * Check if video is ready with @name
         */
        static bool isVideoReady(const std::string& name);

        /**
         * Set reward video transaction id
         */
        static void setRewardsTransactionId(const std::string& transactionId);

        /**
         * Set reward video user id
         */
        static void setRewardsUserId(const std::string& userId);

        /**
         * Set type of reward, such as life / credit / points.
         */
        static void setRewardsRewardTypeCurrency(const std::string& currency);

        /**
         * Set the amount of currency that was rewarded.
         */
        static void setRewardsAmountRewarded(const std::string& amount);

        /**
         * Set reward video custom parameter.
         */
        static void setRewardsCustomParameter(const std::string& parameter);
        };

    class AppnextListener {
    public:

        virtual void onAdError(const std::string& msg) {}
        virtual void onAdLoaded() {}
        virtual void onAdOpened() {}
        virtual void onAdClosed() {}
        virtual void onAdClicked() {}

        virtual void onVideoLoaded(const std::string& name) {}
        virtual void onVideoClicked(const std::string& name) {}
        virtual void onVideoClosed(const std::string& name) {}
        virtual void onVideoEnded(const std::string& name) {} // not support on ios
        virtual void onVideoError(const std::string& name, const std::string& msg) {}

    };
}

#endif
