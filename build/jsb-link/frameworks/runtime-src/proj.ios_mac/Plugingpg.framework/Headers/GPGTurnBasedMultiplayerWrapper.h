
#pragma once

#if __cplusplus > 199711L
#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include "GPGConstants.h"
#endif // #if __cplusplus > 199711L

namespace sdkbox
{
#if __cplusplus > 199711L

	template <typename K, typename T>
	class GPGTypeMapT
	{
	public:
		
        std::map<K, T> _T_K_map;
	    void set(const K& id, const T* data)
	    {
	        if (nullptr == data)
	            _T_K_map.erase(id);
	        else
	            _T_K_map[id] = *data;
	    }
	    T* get(const K& id)
	    {
	        auto it = _T_K_map.find(id);
	        if (it == _T_K_map.end())
	            return nullptr;
	        return &(*it).second;
	    }
	};
	
    class GPGTurnBasedMultiplayerWrapper
    {
    public:
    
        // matches
        static void CreateTurnBasedMatch(int callback_id, const std::string& json_params);
        static void DismissMatch(const std::string& match_id);
        static void FetchMatch(int callback_id, const std::string& match_id);
        static void Rematch(int callback_id, const std::string& match_id);
        static void CancelMatch(int callback_id, const std::string& match_id);
        static void FetchMatches(int callback_id);
        static void ShowMatchInboxUI(int callback_id);
        static void TakeMyTurn(int callback_id, const std::string& match_id, const std::string& participant_results_id, const std::string& next_participant_id, const std::string& data);
        static void FinishMatchDuringMyTurn(int callback_id, const std::string& match_id, const std::string& participant_results_id, const std::string& data);
		static void ConfirmPendingCompletion(int callback_id, const std::string& match_id);
		static void LeaveMatchDuringTheirTurn(int callback_id, const std::string& match_id);
		static void LeaveMatchDuringMyTurn(int callback_id, const std::string& match_id, const std::string& next_participant_id);
		static std::string CreateParticipantResult(const std::string& match_id, const std::string& participant_id, int placing, int matchResult);
		
        // invitations
        static void AcceptInvitation(int callback_id, const std::string& invitation_id);
        static void DeclineInvitation(const std::string& invitation_id);
        static void DismissInvitation(const std::string& invitation_id);
        
        // misc
        static void SynchronizeData();
        static void ShowPlayerSelectUI(int callback_id, int min_players, int max_players, bool allow_automatch);
    };
    
#endif // #if __cplusplus > 199711L
}