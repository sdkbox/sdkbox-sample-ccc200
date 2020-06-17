/****************************************************************************

 Copyright (c) 2014-2020 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_HMS_H_
#define _PLUGIN_HMS_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class HMSListener {
    public:

        /*
         * login callback
         * code: 0, success; !=0, failed
         */
        virtual void onLogin(int code, const std::string& errorOrJson) = 0;

        /*
         * current palyer info callback
         */
        virtual void onPlayerInfo(int code, const std::string& errorOrJson) {};

        /*
         * player extra info callback
         */
        virtual void onPlayerExtraInfo(int code, const std::string& errorOrJson) {};

        /*
         * submit player game begin callback
         */
        virtual void onPlayerGameBegin(int code, const std::string& errorOrJson) {};
        
        /*
         * submit player game end callback
         */
        virtual void onPlayerGameEnd(int code, const std::string& errorOrJson) {};

        /*
         * callback for hws iap env check
         */
        virtual void onIAPReady(int code, const std::string& errorOrJson) {};

        /*
         * callback for iapRequestProducts
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPProducts(int code, const std::string& errorOrJson) {};

        /*
         * callback for iapPurchase
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPPurchase(int code, const std::string& errorOrJson) {};

        /*
         * callback for iapConsume
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPPConsume(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for iapRequestOwnedPurchases
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPOwnedPurchases(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for iapRequestOwnedPurchaseRecords
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPOwnedPurchaseRecords(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for achievementRequestList
         * errorOrJson: achievement json if code == 0, error msg if code != 0
         */
        virtual void onAchievementList(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for achievementShow
         */
        virtual void onAchievementShow(int code, const std::string& errorOrJson) {};

        /*
         * callback for achievementVisualize
         */
        virtual void onAchievementVisualize(int code, const std::string& errorOrJson) {};

        /*
         * callback for achievementGrow
         */
        virtual void onAchievementGrow(int code, const std::string& errorOrJson) {};

        /*
         * callback for achievementMakeSteps
         */
        virtual void onAchievementMakeSteps(int code, const std::string& errorOrJson) {};

        /*
         * callback for eventRequestList
         */
        virtual void onEventList(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for rankingRequestSwitchStatus
         */
        virtual void onRankingSwitchStatus(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for rankingSetSwitchStatus
         */
        virtual void onRankingSetSwitchStatus(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingSubmitScore
         */
        virtual void onRankingSubmitScore(int code, const std::string& errorOrJson) {};

        /**
         * callback for rankingShow
         */
        virtual void onRankingShow(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingRequestList
         */
        virtual void onRankingList(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingRequestCurPlayerScore
         */
        virtual void onRankingCurPlayerScore(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingRequestPlayerCenteredScores
         */
        virtual void onRankingPlayerCenteredScores(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingRequestMoreScores
         */
        virtual void onRankingMoreScores(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for rankingRequestTopScores
         */
        virtual void onRankingTopScores(int code, const std::string& errorOrJson) {};

        /**
         * callback for archiveRequestLimitThumbnailSize
         */
        virtual void onArchiveLimitThumbnailSize(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for archiveRequestLimitDetailsSize
         */
        virtual void onArchiveLimitDetailsSize(int code, const std::string& errorOrJson) {};

        /**
         * callback for archiveAdd
         */
        virtual void onArchiveAdd(int code, const std::string& errorOrJson) {};

        /**
         * callback for archiveShow
         */
        virtual void onArchiveShow(int code, const std::string& errorOrJson) {};

        /**
         * callback for archiveRequestSummaryList
         */
        virtual void onArchiveSummaryList(int code, const std::string& errorOrJson) {};

        /**
         * callback when user select archive
         */
        virtual void onArchiveSelect(int code, const std::string& errorOrJson) {};

        /**
         * callback for archiveRequestThumbnail
         */
        virtual void onArchiveThumbnail(int code, const std::string& errorOrJson, unsigned char* coverData, unsigned int coverDataLen) {};

        /**
         * callback for archiveUpdate
         */
        virtual void onArchiveUpdate(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for archiveLoad
         */
        virtual void onArchiveLoad(int code, const std::string& errorOrJson, unsigned char* contentData, unsigned int contentDataLen) {};

        /**
         * callback for archiveRemove
         */
        virtual void onArchiveRemove(int code, const std::string& errorOrJson) {};

        /**
         * callback for gamePlayerStatsRequest
         */
        virtual void onGamePlayerStats(int code, const std::string& errorOrJson) {};
        
        /**
         * callback for gameSummaryRequest
         */
        virtual void onGameSummary(int code, const std::string& errorOrJson) {};

    };

    class PluginHMS {
    public:

        /**
         * Set GDPR
         *
         * **NOTE**: please call before 'init' function
         */
        static void setGDPR(bool enabled);

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(HMSListener* listener);

        /**
         * Get the listener
         */
        static HMSListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * HMS provider three way to login
         * loginType: 0, slient login 1, login with HuaweiID(ID Token) 2, login with HuaweID(Authorization Code)
         *
         * slient login should invoke after `login with HuaweiID`(loginType 2 or 3) have success
         *
         * will trigger `onLogin` event. and the msg paramater will include account info when login success
         *
         */
        static void login(int loginType);

        /**
         * logout HMS
         */
        static void logout();

        /**
         * request current player info
         */
        static void playerRequestInfo();

        /**
         * request player extra info
         *
         */
        static void playerRequestExtraInfo();

        /**
         * submit game begin event
         */
        static void playerSubmitGameBegin();

        /**
         * submit game end event
         */
        static void playerSubmitGameEnd();

        /*
         * request product list
         *
         * will trigger onIAPProducts
         */
        static void iapRequestProducts();
        
        /*
         * purchase managed product
         * name: product name
         *
         * will trigger onIAPPurchase
         */
        static void iapPurchase(const std::string& name);
        
        /*
         * purchase unmanaged product
         * productJson: product name info
         *
         * will trigger onIAPPurchase
         *
         * {
         * "priceType": 0, //0:consumable 1:non-consumable 2:subscription
         * "productName": "product name",
         * "productId": "product id",
         * "amount": "1.00",
         * "currency": "CNY",
         * "country": "CN",
         * "sdkChannel": "1", // sdkChannel size must be between 0 and 4
         * "serviceCatalog": "X58",
         * "reservedInfor": "{\"a\": 1, \"b\":\"s\"}", // reservedInfor must be json string
         * "developerPayload": "payload1"
         * }
         *
         * more info about purchase unmanaged product: https://developer.huawei.com/consumer/cn/doc/development/HMS-Guides/iap-development-guide-v4#h1-1576554485195
         */
        static void iapPurchaseWithPrice(const std::string& productJson);

        /*
         * request owned purchase
         *
         * will trigger onIAPOwnedPurchases
         */
        static void iapRequestOwnedPurchases();

        /*
         * consume consumable product
         *
         * will trigger onIAPPConsume
         */
        static void iapConsume(const std::string& purchaseToken);

        /*
         * request purchase records, include all purchase history
         *
         * will trigger onIAPOwnedPurchaseRecords
         */
        static void iapRequestOwnedPurchaseRecords();

        /*
         * request achievement list, can use the result data to show achievement by self
         *
         * will trigger onAchievementList
         */
        static void achievementRequestList();

        /*
         * show achievement, use hms default ui to show
         *
         * will trigger onAchievementShow
         */
        static void achievementShow();

        /*
         * visualize achievement
         *
         * will trigger onAchievementVisualize
         */
        static void achievementVisualize(const std::string& name);

        /*
         * grow achievement
         *
         * will trigger onAchievementGrow
         */
        static void achievementGrow(const std::string& achiveName, int steps);

        /*
         * make step achievement
         *
         * will trigger onAchievementMakeSteps
         */
        static void achievementMakeSteps(const std::string& achiveName, int steps);
        
        /*
         * reach achievement
         */
        static void achievementReach(const std::string& achiveName);

        /*
         * grow event
         */
        static void eventGrow(const std::string& eventName, int amount);

        /*
         * request event list
         *
         * params:
         * realtime: true->request from hms server, false->use local cache
         * eventNames: special eventNames, empty will request all events, "evtName1,evtName2" will request evtName1 and evtName2 those two event.
         */
        static void eventRequestList(bool realtime, const std::string& eventNamas = "");

        /**
         * request if player allow open score in ranking
         */
        static void rankingRequestSwitchStatus();
        
        /**
         * request if player allow open score in ranking
         * status: 0->player allow submit score, 1->player not allow submit score
         */
        static void rankingSetSwitchStatus(int status);

        /**
         * submit score to ranking
         */
        static void rankingSubmitScore(const std::string& rankingName, long score, const std::string unit = "");

        /**
         * use hms's ui to show ranking
         *
         * params:
         * timeDimension: 0-> day, 1-> week, 2-> all time
         * rankingName: ranking name want to show, empty will show all ranking
         */
        static void rankingShow(int timeDimension, const std::string& rankingName="");

        /**
         * request ranking list
         *
         * params:
         * realtime: true->request data from hms server, false->use local cache data
         * rankingName: ranking name want to show, empty will show all ranking
         */
        static void rankingRequestList(bool realtime, const std::string& rankingName="");

        /**
         * request current player ranking score
         *
         * params:
         * rankingName: ranking name
         * timeDimension: 0-> day, 1-> week, 2-> all time
         */
        static void rankingRequestCurPlayerScore(const std::string& rankingName, int timeDimension);

        /**
         * request player centered scores
         *
         * params:
         * rankingName: ranking name
         * timeDimension: 0-> day, 1-> week, 2-> all time
         * size: max scores size, should be between 1-21
         * realtime: true->request data from hms server, false->use local cache data
         */
        static void rankingRequestPlayerCenteredScores(const std::string& rankingName, int timeDimension, int size, bool realtime);

        /**
         * request more scores
         *
         * params:
         * rankingName: ranking name
         * timeDimension: 0-> day, 1-> week, 2-> all time
         * offset: begin position in ranking
         * pageSize: max score size
         * pageDirection: 0->next page, returned score should be right after the offset postion score , 1->previous page, returned scores should be in front of the offset postion score
         */
        static void rankingRequestMoreScores(const std::string& rankingName, int timeDimension, int offset, int pageSize, int pageDirection);

        /**
         * submit score to ranking
         *
         * params:
         * rankingName: ranking name
         * timeDimension: 0-> day, 1-> week, 2-> all time
         * offset: begin position in ranking
         * pageSize: max score size
         * pageDirection: 0->next page, returned score should be right after the offset postion score , 1->previous page, returned scores should be in front of the offset postion score
         */
        static void rankingRequestTopScores(const std::string& rankingName, int timeDimension, int offset, int pageSize, int pageDirection);

        /**
         * get thumbnail max size
         */
        static void archiveRequestLimitThumbnailSize();
        
        /**
         * get detail max size
         */
        static void archiveRequestLimitDetailsSize();

        /**
         * add archive
         *
         * params:
         * playedTime: playedTime,
         * progress: game progress,
         * description: archive description
         * supportCache: true->can storge local when offline, and sumbit to hms server when online
         * bmBytes: archive cover image data
         * bmBytesLen: archive cover image data length
         * bmBytesType: archive cover image type
         * dataBytes: archive content data
         * dataBytesLen: archive content data length
         */
        static void archiveAdd(long playedTime, long progress, const std::string& description, bool supportCache,
                               const unsigned char* bmBytes, int bmBytesLen, const std::string& bmBytesType,
                               const unsigned char* dataBytes, int dataBytesLen);

        /**
         * use hms's default ui to show archive
         *
         * params:
         * title: archive title,
         * allowAdd: allow user add archive in the archive ui,
         * allowDelete: allow user add archive in the archive ui
         * pageSize: max archive show in one page
         */
        static void archiveShow(const std::string& title, bool allowAdd, bool allowDelete, int pageSize);
        
        /**
         * request archive summay list, developer can show custome archive list with the returned data
         *
         * params:
         * realtime: true-> use the data from hms server, false->use local cache data
         */
        static void archiveRequestSummaryList(bool realtime);

        /**
         * request archive cover thumbnail
         */
        static void archiveRequestThumbnail(const std::string& archiveId);

        /**
         * update archive
         *
         * params:
         * archiveId: archive id
         * playedTime: playedTime,
         * progress: game progress,
         * description: archive description
         * bmBytes: archive cover image data
         * bmBytesLen: archive cover image data length
         * bmBytesType: archive cover image type
         * dataBytes: archive content data
         * dataBytesLen: archive content data length
         */
        static void archiveUpdate(const std::string& archiveId,
                                  long playedTime, long progress, const std::string& description,
                                  const unsigned char* bmBytes, int bmBytesLen, const std::string& bmBytesType,
                                  const unsigned char* dataBytes, int dataBytesLen);

        /**
         * load archive
         *
         * params:
         * archiveId: archive id
         * conflictPolicy: -1->hms willn't hand conflict, 1->hms will resolved conflict by played time, 2->hms will resolved conflict by progress, 3->1->hms will resolved conflict by last update time
         */
        static void archiveLoad(const std::string& archiveId, int conflictPolicy);

        /**
         * remvoe archive
         */
        static void archiveRemove(const std::string& archiveId);

        /**
         * request game player statistics
         */
        static void gamePlayerStatsRequest(bool realtime);

        /**
         * request game summary
         */
        static void gameSummaryRequest(bool realtime);

        /*
         * show buoy
         */
        static void buoyShow();
        
        /*
         * hide buoy
         */
        static void buoyHide();

    };
}

#endif
