/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_UNITYADS_H_
#define _PLUGIN_UNITYADS_H_

#include <string>
#include <map>

namespace sdkbox {

    class UnityAdsListener;
    class PluginUnityAds {

    public:

        typedef enum {
        /**
         *  An error that indicates failure due to `UnityAds` currently being uninitialized.
         */
        kUnityAdsErrorNotInitialized = 0,
        /**
         *  An error that indicates failure due to a failure in the initialization process.
         */
        kUnityAdsErrorInitializedFailed,
        /**
         *  An error that indicates failure due to attempting to initialize `UnityAds` with invalid parameters.
         */
        kUnityAdsErrorInvalidArgument,
        /**
         *  An error that indicates failure of the video player.
         */
        kUnityAdsErrorVideoPlayerError,
        /**
         *  An error that indicates failure due to having attempted to initialize the `UnityAds` class in an invalid environment.
         */
        kUnityAdsErrorInitSanityCheckFail,
        /**
         *  An error that indicates failure due to the presence of an ad blocker.
         */
        kUnityAdsErrorAdBlockerDetected,
        /**
         *  An error that indicates failure due to inability to read or write a file.
         */
        kUnityAdsErrorFileIoError,
        /**
         *  An error that indicates failure due to a bad device identifier.
         */
        kUnityAdsErrorDeviceIdError,
        /**
         *  An error that indicates a failure when attempting to show an ad.
         */
        kUnityAdsErrorShowError,
        /**
         *  An error that indicates an internal failure in `UnityAds`.
         */
        kUnityAdsErrorInternalError,
    } SBUnityAdsError;

    typedef enum {
        /**
         *  A state that indicates that the ad did not successfully display.
         */
        kUnityAdsFinishStateError,
        /**
         *  A state that indicates that the user skipped the ad.
         */
        kUnityAdsFinishStateSkipped,
        /**
         *  A state that indicates that the ad was played entirely.
         */
        kUnityAdsFinishStateCompleted
    } SBUnityAdsFinishState;

    typedef enum {
        /**
         *  A state that indicates that the placement is ready to show an ad. The `show:` selector can be called.
         */
        kUnityAdsPlacementStateReady,
        /**
         *  A state that indicates that no state is information is available.
         *  @warning This state can that UnityAds is not initialized or that the placement is not correctly configured in the Unity Ads admin tool.
         */
        kUnityAdsPlacementStateNotAvailable,
        /**
         *  A state that indicates that the placement is currently disabled. The placement can be enabled in the Unity Ads admin tools.
         */
        kUnityAdsPlacementStateDisabled,
        /**
         *  A state that indicates that the placement is not currently ready, but will be in the future.
         *  @note This state most likely indicates that the ad content is currently caching.
         */
        kUnityAdsPlacementStateWaiting,
        /**
         *  A state that indicates that the placement is properly configured, but there are currently no ads available for the placement.
         */
        kUnityAdsPlacementStateNoFill
    } SBUnityAdsPlacementState;


        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for inmobi events
         */
        static void setListener(UnityAdsListener* listener);

        /**
         * Get the listener
         */
        static UnityAdsListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        static bool isSupported();

        static bool isReady(const std::string& placementId);

        static void show(const std::string& placementId);

        static SBUnityAdsPlacementState getPlacementState(const std::string& placementId);

        /**
         * Enable GDPR
         */
        static void setGDPR(bool enabled);
        
        static void setServerId(const std::string& sid);
    };

    class UnityAdsListener {
    public:

        virtual void unityAdsDidClick(const std::string& placementId) {};
        virtual void unityAdsPlacementStateChanged(const std::string& placementId, PluginUnityAds::SBUnityAdsPlacementState oldState, PluginUnityAds::SBUnityAdsPlacementState newState) {};
        virtual void unityAdsReady(const std::string& placementId) {};
        virtual void unityAdsDidError(PluginUnityAds::SBUnityAdsError error, const std::string& message) {};
        virtual void unityAdsDidStart(const std::string& placementId) {};
        virtual void unityAdsDidFinish(const std::string& placementId, PluginUnityAds::SBUnityAdsFinishState state) {};
    };

}

#endif
