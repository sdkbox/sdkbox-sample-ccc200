/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_CHARTBOOST_H_
#define _PLUGIN_CHARTBOOST_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
/*! "Startup" - Initial startup of game. */
extern const char* CB_Location_Startup;
/*! "Home Screen" - Home screen the player first sees. */
extern const char* CB_Location_HomeScreen;
/*! "Main Menu" - Menu that provides game options. */
extern const char* CB_Location_MainMenu;
/*! "Game Screen" - Game screen where all the magic happens. */
extern const char* CB_Location_GameScreen;
/*! "Achievements" - Screen with list of achievements in the game. */
extern const char* CB_Location_Achievements;
/*! "Quests" - Quest, missions or goals screen describing things for a player to do. */
extern const char* CB_Location_Quests;
/*!  "Pause" - Pause screen. */
extern const char* CB_Location_Pause;
/*! "Level Start" - Start of the level. */
extern const char* CB_Location_LevelStart;
/*! "Level Complete" - Completion of the level */
extern const char* CB_Location_LevelComplete;
/*! "Turn Complete" - Finishing a turn in a game. */
extern const char* CB_Location_TurnComplete;
/*! "IAP Store" - The store where the player pays real money for currency or items. */
extern const char* CB_Location_IAPStore;
/*! "Item Store" - The store where a player buys virtual goods. */
extern const char* CB_Location_ItemStore;
/*! "Game Over" - The game over screen after a player is finished playing. */
extern const char* CB_Location_GameOver;
/*! "Leaderboard" - List of leaders in the game. */
extern const char* CB_Location_LeaderBoard;
/*! "Settings" - Screen where player can change settings such as sound. */
extern const char* CB_Location_Settings;
/*! "Quit" - Screen displayed right before the player exits a game. */
extern const char* CB_Location_Quit;
/*! "Default" - Supports legacy applications that only have one "Default" location */
extern const char* CB_Location_Default;

enum CB_StatusBarBehavior
{
    /*! Ignore status bar altogether; fullscreen ads will use the space of the status bar. */
    CB_StatusBarBehaviorIgnore,
    /*! Respect the status bar partially; fullscreen ads will use the space of the status bar but any user interactive buttons will not. */
    CB_StatusBarBehaviorRespectButtons,
    /*! Respect the status bar fully; fullscreen ads will not use the status bar space. */
    CB_StatusBarBehaviorRespect
};

enum CB_LoadError {
    /*! Unknown internal error. */
    CB_LoadErrorInternal = 0,
    /*! Network is currently unavailable. */
    CB_LoadErrorInternetUnavailable,
    /*! Too many requests are pending for that location.  */
    CB_LoadErrorTooManyConnections,
    /*! Interstitial loaded with wrong orientation. */
    CB_LoadErrorWrongOrientation,
    /*! Interstitial disabled, first session. */
    CB_LoadErrorFirstSessionInterstitialsDisabled,
    /*! Network request failed. */
    CB_LoadErrorNetworkFailure,
    /*!  No ad received. */
    CB_LoadErrorNoAdFound,
    /*! Session not started. */
    CB_LoadErrorSessionNotStarted,
    /*! User manually cancelled the impression. */
    CB_LoadErrorUserCancellation,
    /*! No location detected. */
    CB_LoadErrorNoLocationFound,
    /*! Video Prefetching is not finished */
    CB_LoadErrorPrefetchingIncomplete,

    CB_LoadErrorImpressionAlreadyVisible,
    CB_LoadErrorNoHostActivity,
    CB_LoadErrorVideoIDMissing,
    CB_LoadErrorErrorPlayingVideo,
    CB_LoadErrorInvalidResponse,
    CB_LoadErrorAssetsDownloadFailure,
    CB_LoadErrorErrorCreatingView,
    CB_LoadErrorErrorDisplayingView,
    CB_LoadErrorIncompatibleApiVersion
};

enum CB_ClickError
{
    /*! Invalid URI. */
    CB_ClickErrorUriInvalid = 0,
    /*! The device does not know how to open the protocol of the URI  */
    CB_ClickErrorUriUnrecognized,
    /*! User failed to pass the age gate. */
    CB_ClickErrorAgeGateFailure,
    /*! Unknown internal error */
    CB_ClickErrorInternal,
    /*! Android only no host activity */
    CB_ClickErrorNoHostActivity
};

class ChartboostListener
{
public:

    /*!
     * there is cached content
     */
    virtual void onChartboostCached(const std::string& name) = 0;
    /*!
     * should Chartboost display
     */
    virtual bool onChartboostShouldDisplay(const std::string& name) = 0;
    /*!
     * Charboost ad has displayed
     */
    virtual void onChartboostDisplay(const std::string& name) = 0;
    /*!
     * Chartboost ad has been dismissed
     */
    virtual void onChartboostDismiss(const std::string& name) = 0;
    /*!
     * Chartboost is not running
     */
    virtual void onChartboostClose(const std::string& name) = 0;
    /*!
     * Chartboost ad was clicked on
     */
    virtual void onChartboostClick(const std::string& name) = 0;
    /*!
     * Chartboost reward was given
     */
    virtual void onChartboostReward(const std::string& name, int reward) = 0;
    /*!
     * Chartboost failed to load
     */
    virtual void onChartboostFailedToLoad(const std::string& name, CB_LoadError e) = 0;
    /*!
     * Chartboost failed to record click
     */
    virtual void onChartboostFailToRecordClick(const std::string& name, CB_ClickError e) = 0;
    /*!
     * Chartboost confirmation
     */
    virtual void onChartboostConfirmation() = 0;
    /*!
     * Chartboost complete store
     */
    virtual void onChartboostCompleteStore() = 0;
};

class PluginChartboost
{
public:

    /*!
     * Set to restrict Chartboost's ability to collect personal data from the device.
     * When this is set to YES. IDFA and ip address will not be collected by the SDK or the server.
     * This method should be called before init
     */
    static void restrictDataCollection(bool shouldRestrict);
    
    /*!
     * initialize the plugin instance.
     */
    static void init(const char* jsonconfig = 0);

    /*!
     * show ad by specifying ad name.
     */
    static void show(const std::string& name);

    /*!
     * creates the an optional listener.
     */
    static void setListener(ChartboostListener* listener);
    static ChartboostListener* getListener();
    /*!
     * removed the listener.
     */
    static void removeListener();

    /*!
     * check to see if any views are visible.
     */
    static bool isAnyViewVisible();

    /*!
     * is the specified ad available?
     */
    static bool isAvailable(const std::string& name);

    static void cache(const std::string& name);

    /*!
     * set to enable and disable the auto cache feature (Enabled by default).
     */
    static void setAutoCacheAds(bool shouldCache);

    /*!
     * get the current auto cache behavior (Enabled by default).
     */
    static bool getAutoCacheAds();

    /*!
     * close any visible Chartboost impressions (interstitials, more apps, rewarded
     * video, etc..) and the loading view (if visible).
     *
     * deprecated >= 2.3.x
     */
    static void closeImpression();

    /*!
     * set to control how the fullscreen ad units should interact with the status bar.
     * (CBStatusBarBehaviorIgnore by default).
     */
    static void setStatusBarBehavior(CB_StatusBarBehavior behavior);

    /*!
     * confirm if an age gate passed or failed. When specified Chartboost will wait for
     * call before showing the IOS App Store.
     */
    static void didPassAgeGate(bool pass);

    /*!
     * decide if Chartboost SDK should block for an age gate.
     */
    static void setShouldPauseClickForConfirmation(bool shouldPause);

    /*!
     * opens a "deep link" URL for a Chartboost Custom Scheme.
     */
    static bool handleOpenURL(const std::string& url, const std::string& sourceApp);

    /*!
     * set a custom identifier to send in the POST body for all Chartboost API server requests.
     */
    static void setCustomID(const std::string& customID);

    /*!
     * get the current custom identifier being sent in the POST body for all Chartboost
     * API server requests.
     */
    static std::string getCustomID();

    /*!
     * decide if Chartboost SDK should show interstitials in the first session.
     */
    static void setShouldRequestInterstitialsInFirstSession(bool shouldRequest);

    /*!
     * decide if Chartboost SDK should show a loading view while preparing to display
     * the "more applications" UI.
     */
    static void setShouldDisplayLoadingViewForMoreApps(bool shouldDisplay);

    /*!
     * decide if Chartboost SDK will attempt to fetch videos from the Chartboost API
     * servers.
     */
    static void setShouldPrefetchVideoContent(bool shouldPrefetch);
};

}

#endif
