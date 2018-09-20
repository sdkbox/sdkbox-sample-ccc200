/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_APPODEAL_H_
#define _PLUGIN_APPODEAL_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class AppodealListener {
    public:
        /**
         * trigger when banner ad load
         */
        virtual void onBannerDidLoadAd() {};
        /**
         * trigger when banner ad fail to load
         */
        virtual void onBannerDidFailToLoadAd() {};
        /**
         * trigger when banner ad clicked
         */
        virtual void onBannerDidClick() {};
        /**
         * trigger when banner ad present
         */
        virtual void onBannerPresent() {};


        /**
         * trigger when interstitial ad load
         */
        virtual void onInterstitialDidLoadAd() {};
        /**
         * trigger when interstitial ad fail to load
         */
        virtual void onInterstitialDidFailToLoadAd() {};
        /**
         * trigger when interstitial ad present
         */
        virtual void onInterstitialWillPresent() {};
        /**
         * trigger when interstitial dismiss
         */
        virtual void onInterstitialDidDismiss() {};
        /**
         * trigger when interstitial ad clicked
         */
        virtual void onInterstitialDidClick() {};
        /**
         * trigger when interstitial ad fail to present
         */
        virtual void onInterstitialDidFailToPresent() {};


        /**
         * trigger when video load
         * deprecated
         */
        virtual void onVideoDidLoadAd() {};
        /**
         * trigger when video fail to load
         * deprecated
         */
        virtual void onVideoDidFailToLoadAd() {};
        /**
         * trigger when video present
         * deprecated
         */
        virtual void onVideoDidPresent() {};
        /**
         * trigger when video dismiss
         * deprecated
         */
        virtual void onVideoWillDismiss() {};
        /**
         * trigger when video finish
         * deprecated
         */
        virtual void onVideoDidFinish() {};


        /**
         * trigger when reward video load
         */
        virtual void onRewardVideoDidLoadAd() {};
        /**
         * trigger when reward video fail to load
         */
        virtual void onRewardVideoDidFailToLoadAd() {};
        /**
         * trigger when reward video present
         */
        virtual void onRewardVideoDidPresent() {};
        /**
         * trigger when reward video dismiss
         */
        virtual void onRewardVideoWillDismiss() {};
        /**
         * trigger when reward video finish
         */
        virtual void onRewardVideoDidFinish(int amount, const std::string& name) {};
        /**
         * trigger when reward video fail to present
         */
        virtual void onRewardVideoDidFailToPresent() {};


        /**
         * trigger when skippable video load
         */
        virtual void onSkippableVideoDidLoadAd() {};
        /**
         * trigger when skippable video fial to load
         */
        virtual void onSkippableVideoDidFailToLoadAd() {};
        /**
         * trigger when skippable video present
         */
        virtual void onSkippableVideoDidPresent() {};
        /**
         * trigger when skippable video dismiss
         */
        virtual void onSkippableVideoWillDismiss() {};
        /**
         * trigger when skippable video finish
         */
        virtual void onSkippableVideoDidFinish() {};
        /**
         * trigger when skippable video click
         */
        virtual void onSkippableVideoDidClick() {};


        /**
         * trigger when nonskippable video load
         */
        virtual void onNonSkippableVideoDidLoadAd() {};
        /**
         * trigger when nonskippable video fial to load
         */
        virtual void onNonSkippableVideoDidFailToLoadAd() {};
        /**
         * trigger when nonskippable video present
         */
        virtual void onNonSkippableVideoDidPresent() {};
        /**
         * trigger when nonskippable video dismiss
         */
        virtual void onNonSkippableVideoWillDismiss() {};
        /**
         * trigger when nonskippable video finish
         */
        virtual void onNonSkippableVideoDidFinish() {};
        /**
         * trigger when nonskippable video click
         */
        virtual void onNonSkippableVideoDidClick() {};
        /**
         * trigger when nonskippable video fail to present
         */
        virtual void onNonSkippableVideoDidFailToPresent() {};
    };

    class PluginAppodeal {
    public:

        typedef enum {

            AppodealAdTypeInterstitial = 1 << 0,

            /**
             * Skippable video (can be skipped by user after several seconds of watch)
             */
            AppodealAdTypeSkippableVideo = 1 << 1,

            AppodealAdTypeBanner       = 1 << 2,

            AppodealAdTypeNativeAd     = 1 << 3,

            AppodealAdTypeRewardVideo  = 1 << 4,

            AppodealAdTypeMREC         = 1 << 5,

            /**
             * Non skippable video (does not return reward parameter in finish callback, can not be skipped by user)
             */
            AppodealAdTypeNonSkippableVideo = 1 <<6,

            /**
             * AppodealAdTypeNativeAd, AppodealAdTypeMREC is useless on game
             */
            AppodealAdTypeAll          = AppodealAdTypeInterstitial | AppodealAdTypeSkippableVideo | AppodealAdTypeBanner | AppodealAdTypeRewardVideo | AppodealAdTypeNonSkippableVideo,

            /**
             * deprecated, use AppodealAdTypeSkippableVideo instead
             */
            AppodealAdTypeVideo        = AppodealAdTypeSkippableVideo

        } AdType;

        typedef enum {
            AppodealShowStyleInterstitial = 1 << 0,
            AppodealShowStyleBannerTop = 1 << 2,
            AppodealShowStyleBannerBottom = 1 << 3,
            AppodealShowStyleRewardedVideo = 1 << 4,
            AppodealShowStyleNonSkippableVideo = 1 << 5,

            /**
             * deprecated
             */
            AppodealShowStyleSkippableVideo = AppodealShowStyleInterstitial,
            AppodealShowStyleVideoOrInterstitial = AppodealShowStyleInterstitial,
            AppodealShowStyleBannerCenter = AppodealShowStyleBannerBottom,
            AppodealShowStyleVideo = AppodealShowStyleSkippableVideo,

            UNKNOWN_STYLE
        } ShowStyle;

        typedef enum {
            AppodealUserGenderOther = 0,
            AppodealUserGenderMale,
            AppodealUserGenderFemale
        } Gender;

        typedef enum {
            AppodealUserOccupationOther = 0,
            AppodealUserOccupationWork,
            AppodealUserOccupationSchool,
            AppodealUserOccupationUniversity
        } Occupation;

        typedef enum {
            AppodealUserRelationshipOther = 0,
            AppodealUserRelationshipSingle,
            AppodealUserRelationshipDating,
            AppodealUserRelationshipEngaged,
            AppodealUserRelationshipMarried,
            AppodealUserRelationshipSearching
        } Relationship;

        typedef enum {
            AppodealUserSmokingAttitudeNegative = 1,
            AppodealUserSmokingAttitudeNeutral,
            AppodealUserSmokingAttitudePositive
        } SmokingAttitude;

        typedef enum {
            AppodealUserAlcoholAttitudeNegative = 1,
            AppodealUserAlcoholAttitudeNeutral,
            AppodealUserAlcoholAttitudePositive
        } AlcoholAttitude;

        /**
         *  initialize the plugin instance.
         */
        static bool init(AdType adType = AdType::AppodealAdTypeAll);

        /**
         * Set listener to listen for appodeal events
         */
        static void setListener(AppodealListener* listener);

        /**
         * Get the listener
         */
        static AppodealListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        static std::string getSDKVersion();
        /**
         * deprecated
         */
        static void disableNetworkForAdType(AdType adType, const std::string& networkName);
        static void disableLocationPermissionCheck();
        static void setAutocache(bool autocache, AdType types);
        static bool isAutocacheEnabled(AdType types);
        static void confirmUsage(AdType adTypes);

        static void setDebugEnabled(bool debugEnabled);
        static bool showAd(ShowStyle style);
        static void cacheAd(AdType type);
        static void hideBanner();
        static bool isReadyForShowWithStyle(ShowStyle showStyle);

        static void setSmartBannersEnabled(bool smartBannerEnabled);
        static void setBannerBackgroundVisible(bool bannerBackgroundVisible);
        static void setBannerAnimationEnabled(bool bannerAnimationEnabled);

        static void setUserVkId(const std::string& vkId);
        static void setUserFacebookId(const std::string& facebookId);
        static void setUserEmail(const std::string& email);
        static void setUserBirthday(const std::string& birthday);
        static void setUserAge(int age);
        static void setUserGender(Gender gender);
        static void setUserOccupation(Occupation occupation);
        static void setUserRelationship(Relationship relationship);
        static void setUserSmokingAttitude(SmokingAttitude smokingAttitude);
        static void setUserAlcoholAttitude(AlcoholAttitude alcoholAttitude);
        static void setUserInterests(const std::string& interests);

    };
}

#endif
