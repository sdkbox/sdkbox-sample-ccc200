/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/


#ifndef _SDKBOX_GPG_WRAPPED_OBJECT_
#define _SDKBOX_GPG_WRAPPED_OBJECT_

#include <string>
#include "GPGConstants.h"
#include "GPGRealTimeMultiplayerWrapper.h"
#include "GPGTurnBasedMultiplayerWrapper.h"


/**
 * (ibon) TODO:
 * need to keep this classes separated because they automatically wrapped by bindings.
 * if i keep them in PluginSdkboxGooglePlay.h, the bidingins generator will fail.
 * I can then instrument the bindings config to read this file.
 */

namespace sdkbox {
    class GPGWrapper
    {
    public:

        /**
         * options : json representation of the builder object options.
         */
        static void CreateGameServices( int callback_id, const std::string& json );
        static bool IsAuthorized();
        static void StartAuthorizationUI();
        static void SignOut();
        static std::string getAuthCode();

        /**
         * Must be implemented per scripting language and native as empty function.
         * For js it is implemented in js/manual/PluginSdkboxGooglePlayJSHelper.cpp
         */
        static void NotifyToScripting( int id, const std::string& str_json );
    };

    class GPGPlayerWrapper {
    public:
        static void FetchSelf( int callback_id, int datasource );
        static void Fetch( int callback_id, int datasource, const std::string& player_id );
        static void FetchRecentlyPlayed( int callback_id, int datasource );
        static void FetchRecentlyConnected( int callback_id, int datasource );
        static void FetchRecentlyInvitable( int callback_id, int datasource );
    };

    class GPGSnapshotWrapper {
    public:

        /**
         * @param str_json  {
         *   allow_create : bool,
         *   allow_delete : bool,
         *   max_snapshots: number,
         *   title        : string
         * }
         */
        static void ShowSelectUIOperation( int callback_id, const std::string& str_json );

        /**
         *
         */
        static void Load( int callback_id, const std::string& filename, int snapshot_conflict_policy, int datasource );
        static void Save( int callback_id, const std::string& str_json );
        static void FetchAll( int callback_id, const std::string& str_json );
        static void Delete( int callback_id, const std::string& filename );
    };

    class GPGLeaderboardWrapper {
    public:

        static void Fetch( int callback_id, const std::string& leaderboard_id, int datasource );
        static void FetchAll( int callback_id, int datasource );
        static void FetchScoreSummary( int callback_id, int datasource, std::string const &leaderboard_id, int time_span, int collection );
        static void FetchAllScoreSummaries( int callback_id, int datasource, const std::string& leaderboard_id );
        static void SubmitScore( int callback_id, const std::string& leaderboard_id, long score, const std::string& metadata = "" );
        static void ShowAllUI( int callback_id );
        static void ShowUI( int callback_id, const std::string& leaderboard_id );
        static void FetchScorePage( int callback_id, const std::string& leaderboard_id, int data_source, int start, int time_span, int collection, int max_items );
        static void FetchNextScorePage( int callback_id, int data_source, int max_items );
        static void FetchPreviousScorePage( int callback_id, int data_source, int max_items );
    };

    class GPGAchievementWrapper {
    public:

        static void Fetch( int callback_id, const std::string& achievement_id, int datasource );
        static void FetchAll( int callback_id, int datasource );
        static void ShowAllUI(int callback_id );

        // these methods have no native callback.

        static void Increment( const std::string& achievement_id, uint32_t steps );
        static void Reveal( const std::string& achievement_id );
        static void SetStepsAtLeast(std::string const &achievement_id, uint32_t steps);
        static void Unlock(std::string const &achievement_id );
    };

    class GPGQuestsWrapper
    {
    public:

        static void Fetch          (int callback_id, const std::string& quest_id, int datasource = 1);
        static void FetchList      (int callback_id, int datasource = 1);
        static void Accept         (int callback_id, const std::string& quest_id);
        static void ClaimMilestone (int callback_id, const std::string& milestone_id);
        static void ShowAllUI      (int callback_id);
		static void ShowUI         (int callback_id, const std::string& quest_id);
    };

    class GPGEventsWrapper
    {
    public:

        static void Fetch     (int callback_id, const std::string& event_id, int datasource = 1);
        static void FetchAll  (int callback_id, int datasource = 1);
        static void Increment (const std::string& event_id, uint32_t steps = 1);
    };

    class GPGStatsWrapper
	{
	public:

		static void FetchForPlayer(int callback_id, int datasource);
	};

    /*
     * ONLY avaiable on android
     */
    class GPGNearbyConnectionsWrapper
    {
    public:

        static bool Init(const std::string& str_json, int callback_id);

        static std::string GetLocalEndpointId();
        static std::string GetLocalDeviceId();
        static void StartAdvertising(std::string const &str_json,
            int start_advertising_callback,
            int request_callback);
        static void StopAdvertising();
        static void AcceptConnectionRequest(std::string const &remote_endpoint_id,
                                   std::string const &payload,
                                   int callback);
        static void RejectConnectionRequest(std::string const &remote_endpoint_id);
        static void StartDiscovery(std::string const &service_id,
                          int duration,
                          int callback);
        static void StopDiscovery(std::string const &service_id);
        static void SendConnectionRequest(std::string const &name,
                                 std::string const &remote_endpoint_id,
                                 std::string const &payload,
                                 int connect_response_callback,
                                 int message_callback);
        static void SendReliableMessage(std::string const &remote_endpoint_id,
                               std::string const &payload);
        static void SendReliableMessage(std::vector<std::string> const &remote_endpoint_ids,
                               std::string const &payload);
        static void SendUnreliableMessage(std::string const &remote_endpoint_id,
                                 std::string const &payload);
        static void SendUnreliableMessage(
          std::vector<std::string> const &remote_endpoint_ids,
          std::string const &payload);
        static void Disconnect(std::string const &remote_endpoint_id);
        static void Stop();

    };
}

#endif
