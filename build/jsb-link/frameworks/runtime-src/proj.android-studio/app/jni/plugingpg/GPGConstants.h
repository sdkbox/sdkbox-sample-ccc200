/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/


#ifndef _SDKBOX_GPGCONSTANTS_H_
#define _SDKBOX_GPGCONSTANTS_H_

#define SDKBOX_GPG_TAG "SdkboxGPG"
#define SDKBOX_GPG_VERSION "1.0"

namespace sdkbox
{
    enum class BuilderCallbackIDs
    {
        AUTH_ACTION_STARTED = 1,
        AUTH_ACTION_FINISHED = 2,
        
        RTMP_ROOM_STATUS_CHANGED = 3,
        RTMP_CONNECTED_SET_CHANGED = 4,
        RTMP_P2P_CONNECTED = 5,
        RTMP_P2P_DISCONNECTED = 6,
        RTMP_PARTICIPANT_STATUS_CHANGED = 7,
        RTMP_DATA_RECEIVED = 8,
        
        TURN_BASED_MATCH_EVENT = 9,
        MULTIPLAYER_INVITATION_EVENT = 10
    };

    static const int ERROR_OPERATION_NUMERIC = -256;
    static const int ERROR_INVALID_GAME_SERVICES = -257;
    static const int ERROR_NULL_POINTER = -259;
}

#endif
