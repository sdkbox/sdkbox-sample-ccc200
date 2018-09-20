/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/
#ifndef __PLUGIN_FYBER_H__
#define __PLUGIN_FYBER_H__

#include <string>
#include <vector>

namespace sdkbox
{
    static const int FYB_OFFERWALL_PRESENTED = 1;
    static const int FYB_OFFERWALL_DISMISSED = 2;
    static const int FYB_OFFERWALL_ERROR     = 3;

    static const int FYB_REWARDED_VIDEO_STARTED  = 1;
    static const int FYB_REWARDED_VIDEO_FINISHED = 2;
    static const int FYB_REWARDED_VIDEO_ABORTED  = 4;
    static const int FYB_REWARDED_VIDEO_ERROR    = 3;
    static const int FYB_REWARDED_VIDEO_DISMISS  = FYB_REWARDED_VIDEO_FINISHED;

    // The device of the user
    extern std::string FYB_UserDeviceUndefined;
    extern std::string FYB_UserDeviceIPhone;
    extern std::string FYB_UserDeviceIPad;
    extern std::string FYB_UserDeviceIPod;
    extern std::string FYB_UserDeviceAndroid;

    // The connection type of the user
    extern int FYB_UserConnectionTypeUndefined;
    extern int FYB_UserConnectionTypeWiFi;
    extern int FYB_UserConnectionType3G;
    extern int FYB_UserConnectionTypeLTE;
    extern int FYB_UserConnectionTypeEdge;

    // The education of the user
    extern int FYB_UserEducationUndefined;
    extern int FYB_UserEducationOther;
    extern int FYB_UserEducationNone;
    extern int FYB_UserEducationHighSchool;
    extern int FYB_UserEducationInCollege;
    extern int FYB_UserEducationSomeCollege;
    extern int FYB_UserEducationAssociates;
    extern int FYB_UserEducationBachelors;
    extern int FYB_UserEducationMasters;
    extern int FYB_UserEducationDoctorate;

    // The marital status of the user
    extern int FYB_UserMaritalStatusUndefined;
    extern int FYB_UserMartialStatusSingle;
    extern int FYB_UserMartialStatusRelationship;
    extern int FYB_UserMartialStatusMarried;
    extern int FYB_UserMartialStatusDivorced;
    extern int FYB_UserMartialStatusEngaged;

    // The ethnicity of the user
    extern int FYB_UserEthnicityUndefined;
    extern int FYB_UserEthnicityAsian;
    extern int FYB_UserEthnicityBlack;
    extern int FYB_UserEthnicityHispanic;
    extern int FYB_UserEthnicityIndian;
    extern int FYB_UserEthnicityMiddleEastern;
    extern int FYB_UserEthnicityNativeAmerican;
    extern int FYB_UserEthnicityPacificIslander;
    extern int FYB_UserEthnicityWhite;
    extern int FYB_UserEthnicityOther;

    // The gender of the user
    extern int FYB_UserGenderUndefined;
    extern int FYB_UserGenderMale;
    extern int FYB_UserGenderFemale;
    extern int FYB_UserGenderOther;

    // The sexual orientation of the user
    extern int FYB_UserSexualOrientationUndefined;
    extern int FYB_UserSexualOrientationStraight;
    extern int FYB_UserSexualOrientationBisexual;
    extern int FYB_UserSexualOrientationGay;
    extern int FYB_UserSexualOrientationUnknown;

    class FyberListener
    {
    public:
        //
        // Virtual Currency Connection Delegate
        //

        virtual void onVirtualCurrencyConnectorFailed(int error,                    // deprecated filed, always: 0
                                                      const std::string& errorCode, // deprecated filed, alwasy: ""
                                                      const std::string& errorMsg) = 0;
        virtual void onVirtualCurrencyConnectorSuccess(double deltaOfCoins,
                                                       const std::string& currencyId,
                                                       const std::string& currencyName,
                                                       const std::string& transactionId) = 0;

        //
        // Interstitial
        //

        virtual void onCanShowInterstitial(bool canShowInterstitial) = 0;
        virtual void onInterstitialDidShow() = 0;
        virtual void onInterstitialDismiss(const std::string& reason) = 0;
        virtual void onInterstitialFailed() = 0;

        //
        // Rewarded Video
        //

        virtual void onBrandEngageClientReceiveOffers(bool areOffersAvailable) = 0;
        virtual void onBrandEngageClientChangeStatus(int status, const std::string& msg) = 0;

        //
        // Offer Wall
        //

        virtual void onOfferWallFinish(int status) = 0;
    };

    class PluginFyber
    {
    public:
        /*!
         * initialize the fyber plugin.
         */
        static void init(const std::string& userID = "", const char* jsonconfig = 0);

        /**
         * Set listener to listen for fyber events
         */
        static void setListener(FyberListener* listener);

        /**
         * Get the listener
         */
        static FyberListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore.
         */
        static void removeListener();

        // offer wall

        /**
         * Presents the Fyber Mobile OfferWall as a child view controller of your own view controller.
         *
         * @placementId (deprecated)
         */
        static void showOfferWall(const std::string& placementId = "");


        // rewarded video

        /**
         * Request the server for rewarded video availability.
         */
        static void requestOffers(const std::string& placementId = "");
        /**
         * Show an available rewarded video.
         *
         * @placementId (deprecated)
         */
        static void showOffers(const std::string& placementId = "");


        // interstitial

        /**
         * Check if interstitial ads are available
         */
        static void requestInterstitial();
        /**
         * Shows an interstitial ad. Check first that one is ready to be shown with requestInterstitial.
         */
        static void showInterstitial();

        /**
         * Fetches the amount of a given currency earned since the last time this method was
         * invoked for the current user ID / app ID combination.
         */
        static void requestDeltaOfCoins(const std::string& currencyId = "");


        // user segments

        /**
         *  Sets the user's age
         *
         *  @param age Age of the user. Pass `FYBEntryIgnore` if value needs to be ignored or to be removed, if already exists
         */
        static void setAge(int age);

        /**
         *  Sets the user's date of birth, format (yyyy-MM-dd)
         *
         *  @param date Date of birth of the user. Pass `""` if value needs to be ignored or to be removed, if already exists
         */
        static void setBirthdate(const std::string& data);

        /**
         *  Sets the user's gender
         *
         *  @param gender Gender of the user. Pass FYB_UserGenderUndefined if value needs to be ignored or to be removed, if already exists
         */
        static void setGender(int gender);

        /**
         *  Sets the user's sexual orientation
         *
         *  @param sexualOrientation Sexual orientation of the user. Pass FYB_UserSexualOrientationUndefined if value needs to be ignored or to be removed, if already exists.
         */
        static void setSexualOrientation(int sexualOrientation);

        /**
         *  Sets the user's ethnicity
         *
         *  @param ethnicity Ethnicity of the user. Pass FYB_UserEthnicityUndefined if value needs to be ignored or to be removed, if already exists
         */
        static void setEthnicity(int ethnicity);

        /**
         *  Set the user's location
         */
        static void setLocation(double latitude, double longitude);

        /**
         * Clean the user's location
         */
        static void cleanLocation();

        /**
         *  Sets the user's marital status
         *
         *  @param status Marital status of the user. Pass FYB_UserMaritalStatusUndefined if value needs to be ignored or to be removed if already exists
         */
        static void setMaritalStatus(int status);

        /**
         *  Sets the user's number of children
         *
         *  @param numberOfChildren The number of children
         */
        static void setNumberOfChildren(int numberOfChildren);
        /**
         *  Sets the user's annual household income
         *
         *  @param income Annual household income of the user. Pass `FYB_EntryIgnore` if value needs to be ignored or to be removed, if already exists
         */
        static void setAnnualHouseholdIncome(int income);

        /**
         *  Sets the user's educational background
         *
         *  @param education Education of the user. Pass FYB_UserEducationUndefined if value needs to be ignored or to be removed, if already exists
         */
        static void setEducation(int education);

        /**
         *  Sets the user's zipcode
         *
         *  @param zipcode Zipcode of the current living place of the user. Pass `""` if value needs to be ignored or to be removed, if already exists
         */
        static void setZipcode(const std::string& zipcode);

        /**
         *  Set the user's list of interests
         *
         *  @param interests List of interests of the user. Pass `{}` if value needs to be ignored or to be removed, if already exists
         */
        static void setInterests(const std::vector<std::string>& interests);

        /**
         *  Sets if in-app purchases are enabled.
         *
         *  @param flag Sets if in-app purchases are enabled
         */
        static void setIap(bool flag);

        /**
         *  Sets the amount that the user has already spent on in-app purchases
         *
         *  @param amount The amount of money that the user has spent
         */
        static void setIapAmount(float amount);

        /**
         *  Sets the number of sessions
         *
         *  @param numberOfSessions The number of sessions that has already been started
         */
        static void setNumberOfSessions(int numberOfSessions);

        /**
         *  Sets the time spent on the current session
         *
         *  @param timestamp The time spent on the current session
         */
        static void setPsTime(double timestamp);

        /**
         *  Sets the duration of the last session
         *
         *  @param session The duration of the last session
         */
        static void setLastSession(double session);

        /**
         *  Sets the connection type used by the user
         *
         *  @param connectionType The connection type used by the user
         */
        static void setConnectionType(int connectionType);

        /**
         *  Sets the device used by the user
         *
         *  @param device The device used by the user
         */
        static void setDevice(const std::string& device);

        /**
         *  Sets the app version
         *
         *  @param version The version of the app currently executed
         */
        static void setVersion(const std::string& version);

        /**
         * Clean custom parameters, iOS only
         */
        static void cleanCustomParameters();

        /**
         *  Sets custom parameters to be sent along with the standard parameters
         *
         *  @param parameters The custom parameters that must be set
         */
        static void addCustomParameters(const std::string& key, const std::string& value);
    };
}

#endif
