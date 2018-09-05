//
//  SnapshotManager.h
//  PluginSdkboxGooglePlay
//
//  Created by Justin Graham on 7/26/16.
//  Copyright © 2016 SDKBOX. All rights reserved.
//

#pragma once

#if __cplusplus > 199711L
#include "PluginGPG.h"
#include "gpg/snapshot_manager.h"
#endif

namespace sdkbox
{
    class SnapshotManager
    {
    public:

        #define MAX_DURATION Duration(INT_MAX)

        #if __cplusplus > 199711L
        #define ImportType(x) typedef gpg::SnapshotManager::x x;

        ImportType(FetchAllResponse);
        ImportType(FetchAllCallback);

        ImportType(OpenResponse);
        ImportType(OpenCallback);

        ImportType(CommitResponse);
        ImportType(CommitCallback);

        ImportType(ReadResponse);
        ImportType(ReadCallback);

        ImportType(SnapshotSelectUIResponse);
		ImportType(SnapshotSelectUICallback);

        void FetchAll(DataSource dataSource = DataSource::CACHE_OR_NETWORK, FetchAllCallback callback = nullptr);
        FetchAllResponse FetchAllBlocking(DataSource data_source = DataSource::CACHE_OR_NETWORK, Timeout timeout = MAX_DURATION);

        void Open(DataSource data_source, std::string const& file_name, SnapshotConflictPolicy conflict_policy, OpenCallback callback);
        OpenResponse OpenBlocking(DataSource data_source, std::string const& file_name, SnapshotConflictPolicy conflict_policy);

        void Commit(SnapshotMetadata const& snapshot_metadata, SnapshotMetadataChange const& metadata_change, const std::vector<uint8_t>& data, CommitCallback callback);
        CommitResponse CommitBlocking(SnapshotMetadata const& snapshot_metadata, SnapshotMetadataChange const& metadata_change, const std::vector<uint8_t>& data);



#if TARGET_OS_IPHONE
        // remove from from v3 https://developers.google.com/games/services/cpp/releaseNotes
        void ResolveConflict(SnapshotMetadata const& snapshot_metadata, SnapshotMetadataChange const& metadata_change, std::string const& conflict_id, CommitCallback callback);
        CommitResponse ResolveConflictBlocking(SnapshotMetadata const& snapshot_metadata, SnapshotMetadataChange const& metadata_change, std::string const& conflict_id);
#else
        // add from v3 https://developers.google.com/games/services/cpp/releaseNotes
        void ResolveConflict(const std::string &conflict_id, const SnapshotMetadata &snapshot_metadata, OpenCallback callback);
        void ResolveConflict(const std::string &conflict_id, const SnapshotMetadata &snapshot_metadata, const SnapshotMetadataChange &metadata_change, std::vector<uint8_t> contents, OpenCallback callback);

        // add from v3 https://developers.google.com/games/services/cpp/releaseNotes
        OpenResponse ResolveConflictBlocking(const std::string &conflict_id, const SnapshotMetadata &snapshot_metadata);
        OpenResponse ResolveConflictBlocking(const std::string &conflict_id,const SnapshotMetadata &snapshot_metadata,const SnapshotMetadataChange &metadata_change,std::vector<uint8_t> contents);

#endif

        void Delete(SnapshotMetadata const& snapshot_metadata);

        void Read(SnapshotMetadata const& snapshot_metadata, ReadCallback callback);
        ReadResponse ReadBlocking(Timeout timeout, SnapshotMetadata const& snapshot_metadata);

        void ShowSelectUIOperation(bool allow_create, bool allow_delete, uint32_t max_snapshots, std::string const& title, SnapshotSelectUICallback callback);
        SnapshotSelectUIResponse ShowSelectUIOperationBlocking(bool allow_create, bool allow_delete, uint32_t max_snapshots, std::string const& title, Timeout timeout = MAX_DURATION);

        #undef ImportType
        #endif
    };
}
