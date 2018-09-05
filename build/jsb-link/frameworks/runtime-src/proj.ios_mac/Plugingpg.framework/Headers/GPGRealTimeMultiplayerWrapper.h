/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/


#pragma once

#include <string>
#include <vector>
#include "GPGConstants.h"

namespace sdkbox {
    
    class GPGRealTimeMultiplayerWrapper {
    public:
        
        /**
         *
         * str_json_params : {
         *     type : 'quick_match' | 'ui' | 'ui_custom',
         *     quick_match_params? : {
         *          minimumAutomatchingPlayers : number,
         *          maximumAutomatchingPlayers : number,
         *          exclusiveBitMask? :          number
         *     },
         *     ui_params? : {
         *          minimumPlayers : number,
         *          maximumPlayers : number
         *     }
         *
         * }
         */
        static void CreateRealTimeRoom( int callback_id, const std::string& str_json_params );
        static void LeaveRoom( int callback_id, const std::string& room_id );
        static void ShowRoomInboxUI( int callback_id );
        static void FetchInvitations( int callback_id );
        static void AcceptInvitation( int callback_id, const std::string& invitation_id );
        static void DeclineInvitation( const std::string& invitation_id );
        static void DismissInvitation( const std::string& invitation_id );
        
        static void SendReliableMessage( int callback_id, const std::string& room_id, const std::string& participant_id, const std::string& data );
        static void SendUnreliableMessageToOthers( const std::string& room_id, const std::string& data );
        static void SendUnreliableMessage(const std::string& str_json);
    };

}

