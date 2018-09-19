/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_APTELIGENT_H_
#define _PLUGIN_APTELIGENT_H_

#include <string>
#include <map>

namespace sdkbox {

    static const int CRLoggingLevelSilent  = 0;
    static const int CRLoggingLevelError   = 1;
    static const int CRLoggingLevelWarning = 2;
    static const int CRLoggingLevelInfo    = 3;

    class ApteligentListener;
    class PluginApteligent {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for apteligent events
         */
        static void setListener(ApteligentListener* listener);

        /**
         * Get the listener
         */
        static ApteligentListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();


        /**
         * Adds an additional filter for network instrumentation.
         */
        static void addFilter(const std::string& filter);

        /**
         * Breadcrumbs provide the ability to track activity within your app.
         *
         *
         * A breadcrumb is a free form string you supply, which will be timestamped,
         * and stored in case a crash occurs. Crash reports will contain the breadcrumb
         * trail from the run of your app that crashed, as well as that of the prior
         * run.
         *
         * Breadcrumbs are limited to 140 characters, and only the most recent 100 are
         * kept. Apteligent will automatically insert a breadcrumb marked
         *   "session_start"
         * on each initial launch, or foreground of your app.
         *
         * Note - Breadcrumbs are an Enterprise level feature.
         */
        static void leaveBreadcrumb(const std::string& breadcrumb);

        /**
         * By default, breadcrumbs are flushed to disk immediately when written.
         * This is by design - in order to provide an accurate record of everything
         * that happened up until the point your app crashed.
         *
         * If you are concerned about the performance costs of writing the file, you can
         * instruct the library to perform all breadcrumb writes on a background thread.
         */
        static void setAsyncBreadcrumbMode(bool writeAsync);

        /**
         * Inform Apteligent of the device's most recent location for use with
         * performance monitoring.
         */
        static void updateLocation(double latitude, double longitude);

        /**
         * Logging endpoints is a way of manually logging custom network library
         * network access to URL's which fall outside Apteligent's monitoring
         * of NSURLConnection and ASIHTTPRequest method calls.
         */
        static bool logNetworkRequest(const std::string& method, const std::string& urlString, long latency, long bytesRead, long bytesSent, long responseCode);

        /**
         * If you wish to offer your users the ability to opt out of Apteligent
         * crash reporting, you can set the OptOutStatus to YES. If you do so, any
         * pending crash reports will be purged.
         */
        static void setOptOutStatus(bool status);

        /**
         * Retrieve current opt out status.
         */
        static bool getOptOutStatus();

        /**
         * Set the maximum number of crash reports that will be stored on
         * the local device if the device does not have internet connectivity. If
         * more than |maxOfflineCrashReports| crashes occur, the oldest crash will be
         * overwritten. Decreasing the value of this setting will not delete
         * any offline crash reports. Unsent crash reports will be kept until they are
         * successfully transmitted to Apteligent, hence there may be more than
         * |maxOfflineCrashReports| stored on the device for a short period of time.
         *
         * The default value is 3, and there is an upper bound of 10.
         */
        static void setMaxOfflineCrashReports(int max);

        /**
         * Get the maximum number of Apteligent crash reports that will be stored on
         * the local device if the device does not have internet connectivity.
         */
        static int maxOfflineCrashReports();

        /**
         * Get the Apteligent generated unique identifier for this device.
         *
         * !! This is NOT the device's UDID.
         *
         * If called before enabling the library, this will return an empty string.
         *
         * All Apteligent enabled apps on a device will share the UUID created by the
         * first installed Apteligent enabled app.
         *
         * If all Apteligent enabled applications are removed from a device, a new
         * UUID will be generated when the next one is installed.
         */
        static std::string getUserUUID();

        /**
         * Associate a username string with the device's Apteligent UUID. This will
         * send the association to Apteligent's back end.
         */
        static void setUsername(const std::string& username);

        /**
         * Associate an arbitrary key/value pair with the device's Apteligent UUID.
         */
        static void setValueforKey(const std::string& value, const std::string& key);

        /**
         * Did the application crash on the previous load?
         */
        static bool didCrashOnLastLoad();

        /**
         * Init and begin a userflow with a default value.
         */
        static void beginUserflow(const std::string& name);

        /**
         * Init and begin a userflow with an input value.
         */
        static void beginUserflow(const std::string& name, int value);

        /**
         * Cancel a userflow as if it never existed.
         */
        static void cancelUserflow(const std::string& name);

        /**
         * End an already begun userflow successfully.
         */
        static void endUserflow(const std::string& name);

        /**
         * End an already begun userflow as a failure.
         */
        static void failUserflow(const std::string& name);

        /**
         * Get the currency cents value of a userflow.
         */
        static int valueForUserflow(const std::string& name);

        /**
         * Set the currency cents value of a userflow.
         */
        static void setValueforUserflow(int value, const std::string& name);

        /**
         * Tell Apteligent to send app load event.
         * By default, Apteligent will send app load event automatically when your app is started
         * However, if you set delaySendingAppLoad flag to YES on config, you can call this method to
         * manually send app load event.
         */
        static void sendAppLoadData();

        /**
         * Set the logging level to tune the verbosity of Apteligent log messages.
         */
        static void setLoggingLevel(int loggingLevel);
    };

    class ApteligentListener {
    public:

        /**
         * Notifies the delegate that the app has crash last time.
         */
        virtual void onCrashOnLastLoad() {}
    };
}

#endif
