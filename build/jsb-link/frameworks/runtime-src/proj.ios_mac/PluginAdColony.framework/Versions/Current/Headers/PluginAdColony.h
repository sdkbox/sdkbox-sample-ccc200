/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_ADCOLONY_H_
#define _PLUGIN_ADCOLONY_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox
{
    typedef enum {
        /**< AdColony has not been configured with that zone ID. */
        ADCOLONY_ZONE_STATUS_NO_ZONE = 0,
        /**< The zone has been turned off on the [Control Panel](http://clients.adcolony.com). */
        ADCOLONY_ZONE_STATUS_OFF,
        /**< The zone is preparing ads for display. */
        ADCOLONY_ZONE_STATUS_LOADING,
        /**< The zone has completed preparing ads for display. */
        ADCOLONY_ZONE_STATUS_ACTIVE,
        /**< AdColony has not yet received the zone's configuration from the server. */
        ADCOLONY_ZONE_STATUS_UNKNOWN
    } AdColonyAdStatus;

    struct AdColonyAdInfo
    {
        std::string name;
        bool shown;
        std::string zoneID;
        bool iapEnabled;
        std::string iapProductID;
        int iapQuantity;
        int iapEngagementType;
    };

    class AdColonyListener
    {
    public:
        /*!
         * called when AdColony is finished loading.
         */
        virtual void onAdColonyChange(const AdColonyAdInfo& info, bool available) = 0;
        /*!
         * reward was received.
         */
        virtual void onAdColonyReward(const AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success) = 0;
        /*!
         * showing an ad has started.
         */
        virtual void onAdColonyStarted(const AdColonyAdInfo& info) = 0;
        /*!
         * showing an ad has finished.
         */
        virtual void onAdColonyFinished(const AdColonyAdInfo& info) = 0;
    };

    class PluginAdColony
    {
    public:

        /**
         * Set GDPR
         *
         * **NOTE**: please call before 'init' function
         */
        static void setGDPR(bool enabled);
        
        /**
         * initialize the plugin instance.
         */
        static void init();

        /**
         * play video ad using provided name that was specified in sdkbox_config.json
         */
        static void show(const std::string& name);

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(AdColonyListener* listener);

        /**
         * Get the listener
         */
        static AdColonyListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * Returns the zone status for the specified zone.
         *
         * @deprecated please use getStatus(name) instead
         */
        static int zoneStatusForZone(const std::string& zoneID);

        /**
         * Check the availability of the adcolony ads by name
         */
        static AdColonyAdStatus getStatus(const std::string& name);

        /**
         * Assigns your own custom identifier to the current app user.
         *
         * Once you've provided an identifier, AdColony will persist it across app
         * restarts (stored on disk only) until you update it. If using this method,
         * call it before `+ configureWithAppID:zoneIDs:delegate:logging:` so that the
         * identifier is used consistently across all server communications. The
         * identifier will also pass through to server-side V4VC callbacks.
         * @param customID An arbitrary, application-specific identifier string for the current user. Must be less than 128 characters.
         * @see getCustomID
         */
        static void setCustomID(const std::string& customID);

        /**
         * Returns the device's current custom identifier.
         *
         * @return The custom identifier string most recently set using `+ setCustomID:`.
         * @see setCustomID:
         */
        static std::string getCustomID();

        /**
         * Returns an AdColony-defined device identifier.
         *
         * This identifier should remain constant across the lifetime of an iOS device.
         * The identifier is a SHA-1 hash of the lowercase colon-separated MAC address of the device's WiFi interface.
         * We do not recommend using this
         * identifier for new integrations. This method is provided for backwards compatibility.
         * @return The string representation of the device's AdColony identifier.
         */
        static std::string getUniqueDeviceID();

        /**
         * Returns the device's advertising identifier.
         *
         * This value can change if the user restores their device or resets ad tracking.
         * @return The string representation of the device's advertising identifier, introduced in iOS 6. Returns `nil` on iOS 5 or below.
         * @note this function only available on ios
         */
        static std::string getAdvertisingIdentifier();

        /**
         * Returns the device's vendor identifier.
         *
         * @return As of version 2.3 of our iOS SDK, AdColony no longer collects the vendor identifier and this method will return `nil`. This method is provided for backwards compatibility.
         * @note this function only available on ios
         */
        static std::string getVendorIdentifier();

        /**
         * Returns the number of ads that the user must play to earn the designated reward.
         *
         * @note this function only available on ios
         */
        static int getVideosPerReward(const std::string& currencyName);

        /**
         * Returns the number of ads that the user has seen towards their next reward.
         *
         * @note this function only available on ios
         */
        static int getVideoCreditBalance(const std::string& currencyName);

        /**
         * Cancels any full-screen ad that is currently playing and returns control to the app.
         *
         * No earnings or V4VC rewards will occur if an ad is canceled programmatically by the app.
         * This should only be used by apps that must immediately respond to non-standard incoming events,
         * like a VoIP phone call. This should not be used for standard app interruptions such as
         * multitasking or regular phone calls.
         */
        static void cancelAd();

        /**
        * Whether a full-screen AdColony ad is currently being played.
        *
        * @return A boolean indicating if AdColony is currently playing an ad.
        * @note this function only available on ios
        */
        static bool videoAdCurrentlyRunning();

        /**
        * This method permanently turns off all AdColony ads for this app on the current device.
        *
        * After this method is called, no ads will be played unless the app is deleted and reinstalled.
        * This method could be used in the implementation of an In-App Purchase to disable ads;
        * make sure to allow In-App Purchases to be restored by the user in the case of deleting and reinstalling the app.
        * @note this function only available on ios
        */
        static void turnAllAdsOff();

        /**
        * Provide AdColony with per-user non personally-identifiable information for ad targeting purposes.
        *
        * Providing non personally-identifiable information using this API will improve targeting and unlock
        * improved earnings for your app. [This support article](http://support.adcolony.com/customer/portal/articles/700183-sdk-user-metadata-pass-through) contains usage guidelines.
        * @param metadataType One of the predefined user metadata keys.
        * @param value Either a predefined user metadata value, or arbitrary value.
        * @note this function only available on ios
        */
        static void setUserMetadata(const std::string& metadataType, const std::string& value);

        /**
        * Provide AdColony with real-time feedback about what a user is interested in.
        *
        * Providing non personally-identifiable information using this API will improve targeting and unlock
        * improved earnings for your app. [This support article](http://support.adcolony.com/customer/portal/articles/700183-sdk-user-metadata-pass-through) contains usage guidelines.
        * You can call this as often as you want with various topics that the user has engaged in
        * within your app or as the user engages in them. For example, if the user has started browsing
        * the finance section of a news app, a developer should call: `[AdColony userInterestedIn:@"finance"]`.
        * @param topic An arbitrary topic string.
        * @note this function only available on ios
        */
        static void userInterestedIn(const std::string& topic);

        /**
        * Call this method to report IAPs within your application. Note that this API can be leveraged to report standard IAPs
        * as well as those triggered by AdColony’s IAP Promo (IAPP) advertisements and will improve overall ad targeting.
        *
        * @param transactionID An NSString representing the unique SKPaymentTransaction identifier for the IAP. Must be 128 chars or less.
        * @param productID An NSString identifying the purchased product. Must be 128 chars or less.
        * @param quantity An int indicating the number of items.
        * @param price (*optional*) An NSNumber indicating the total price of the items purchased.
        * @param currencyCode (*optional*) An NSString indicating the real-world, three-letter ISO 4217 (e.g. USD) currency code of the transaction.
        * @see onAdColonyIAPRequest:quantity
        */
        static void notifyIAPComplete(const std::string& transactionID, const std::string& productID, int quantity, float price, const std::string& currencyCode);
        
        /**
         * Request all ads
         */
        static void requestAllAds();
    };
}

#endif
