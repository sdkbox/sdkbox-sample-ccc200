/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/
#ifndef _PLUGIN_GA_
#define _PLUGIN_GA_

#include <string>
#include <vector>
#include <map>

namespace sdkbox
{

    class PluginGoogleAnalytics
    {
    public:

        /*!
         * initialize the plugin instance.
         */
        static void init(const char* jsonconfig = 0);

        /*!
         * The analytics session is being explicitly started at plugin initialization time.
         */
        static void startSession();

        /*!
         * You normally will never stop a session manually.
         */
        static void stopSession();

        /*!
         * Manually request dispatch of hits. By default, data is dispatched from the
         * Google Analytics SDK for Android every 5 minutes.
         */
        static void dispatchHits();

        /*!
         * Change the dispatch info time period to the desired amount of seconds.
         */
        static void dispatchPeriodically( int seconds );

        /*!
         * Stop periodically sending info. Then manually the <code>dispatchPeridically</code>
         * or <code>dispatchHits</code> should be called.
         */
        static void stopPeriodicalDispatch();

        /*!
         * Set user ID for this tracking session
         */
        static void setUser(const std::string& userID);

        /*!
         * Set value to custom dimension
         */
        static void setDimension(int index, const std::string& value);

        /*!
         * Set value to custom metric
         */
        static void setMetric(int index, const std::string& value);

        /*!
         * Log screen info. title is the title of a screen. Screens are logical units
         * inside your app you'd like to identify at analytics panel.
         */
        static void logScreen(const std::string& title);

        /*!
         * GoogleAnalytics::logEvent("Achievement", "Unlocked", "Slay 10 dragons", 5);
         */
        static void logEvent(const std::string& eventCategory, const std::string& eventAction, const std::string& eventLabel, int value);

        /*!
         * Log an exception. It is a basic support for in-app events.
         */
        static void logException(const std::string& exceptionDescription, bool isFatal);

        /*!
         * Measure a time inside the application.
         */
        static void logTiming(const std::string& timingCategory, int timingInterval, const std::string& timingName, const std::string& timingLabel);

        /*!
         * Log a social event.
         */
        static void logSocial(const std::string& socialNetwork, const std::string& socialAction, const std::string& socialTarget);

        /*!
         * Log ecommerce event
         *
         *

            // 1. track purchase
            std::map<std::string, std::string> info;
            // transaction info
            info["action"] = "purchase";
            info["transaction"] = "T12345";
            info["affiliation"] = "Google Store - Online";
            info["transactionCouponCode"] = "SUMMER2017";
            info["revenue"] = "37.39";
            info["tax"] = "2.85";
            info["shipping"] = "5.34";

            // product info
            info["productID"] = "P12345";
            info["productName"] = "Android Warhol T-Shirt";
            info["category"] = "Apparel/T-Shirts";
            info["brand"] = "SDKBox";
            info["productVariant"] = "black";
            info["productCouponCode"] = "APPARELSALE";
            info["price"] = "29.20";
            info["quantity"] = "1"; // int

            // currency code
            // https://support.google.com/analytics/answer/6205902?#supported-currencies
            info["currencyCode"] = "EUR";

            sdkbox::PluginGoogleAnalytics::logECommerce(info);


            // 2. track refund
            // transaction info
            info["action"] = "refund";
            info["transaction"] = "T12345";

            // product info
            info["productID"] = "P12345";
            info["quantity"] = "1";

            sdkbox::PluginGoogleAnalytics::logECommerce(info);

         *
         *
         */
        static void logECommerce(std::map<std::string, std::string> info);

        /*!
         * While running on dry run, the tracked events won't be sent to the actual
         * analytics account.
         */
        static void setDryRun( bool enable );

        /*!
         * Enable advertising tracking when in google's ad vendors.
         */
        static void enableAdvertisingTracking( bool enable );

        /*!
         * Create a tracker identified by the google analytics tracker id XX-YYYYYYYY-Z.
         * If the tracker already existed, no new tracker will be created. In any case, the
         * tracker associated with tracker id will be set as default tracker for  analytics
         * operations.
         */
        static void createTracker( const std::string& trackerId );

        /*!
         * Enable a tracker identified by a trackerId. If the tracker does not exist,
         * nothing will happen.
         */
        static void enableTracker( const std::string& trackerId );

        /*!
         * Enables or disables uncaught exception reporting for a given tracker.
         */
        static void enableExceptionReporting(bool enable);
    };

}

#endif
