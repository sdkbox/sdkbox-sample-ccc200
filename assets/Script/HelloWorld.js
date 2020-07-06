cc.Class({
    extends: cc.Component,

    properties: {
        title: {
            default: null,
            type: cc.Label
        },
        menu: {
            default: null,
            type: cc.Layout
        },
        logs: {
            default: null,
            type: cc.Label
        },
        btnTemplate: {
            default: null,
            type: cc.Button
        },
        // defaults, set visually when attaching this script to the Canvas
        text: 'Hello, World!'
    },

    // use this for initialization
    onLoad: function () {
        this.initPlugin();
        this.showMenu("HMS");
        this.loadCoverImage();
    },

    initPlugin: function() {
        this.initPluginHMS();
    },

    initPluginHMS: function() {
        this.adNameArray = ['banner', 'institial', 'rewarded-video'];
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginHMS) {
            this.log('sdkbox.PluginHMS is undefined');
            return;
        }

        const self = this;
        const listener = {
            onLogin: function(code, msg) {
                self.log('HMS Listener onLogin:' + code);
                cc.log(msg);
            },

            onPlayerInfo(code, errorOrJson) {
                self.log('HMS Listener onPlayerInfo:' + code);
                cc.log(errorOrJson);
            },

            onPlayerExtraInfo(code, errorOrJson) {
                self.log('HMS Listener onPlayerExtraInfo:' + code);
                cc.log(errorOrJson);
            },

            onPlayerGameBegin(code, errorOrJson) {
                self.log('HMS Listener onPlayerGameBegin:' + code);
                cc.log(errorOrJson);
            },

            onPlayerGameEnd(code, errorOrJson) {
                self.log('HMS Listener onPlayerGameEnd:' + code);
                cc.log(errorOrJson);
            },

            onIAPReady: function(code, msg) {
                self.log('HMS Listener onIAPReady:' + code);
                cc.log(msg);
            },
            onIAPProducts: function(code, msg) {
                self.log('HMS Listener onIAPProducts:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                self.hmsProducts = rst.products;
            },
            onIAPPurchase: function(code, msg) {
                self.log('HMS Listener onIAPPurchase:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                const iapData = rst["inAppPurchaseData"];
                const iapSignature = rst["inAppDataSignature"];

                const iapDataJson = JSON.parse(iapData);
                const pToken = iapDataJson["purchaseToken"];
                const pId = iapDataJson["productId"];

                self.log('Purchase ID:PurchaseToken' + pId + ":" + pToken);

                if (self.isConsumable(pId)) {
                    self.addPurchaseToken(pToken);
                } else {
                    // purchase success delivery product to player
                    self.log('Purchase Success, delivery ' + pId + " to player");
                }
            },
            onIAPConsume: function(code, msg) {
                self.log('HMS Listener onIAPPConsume:' + code);
                cc.log(msg);

                if (0 == code) {
                    // consume success, delivery this consumable to player
                    self.log('Purchase Success, delivery to player');
                }
            },
            onIAPOwnedPurchases: function(code, msg) {
                self.log('HMS Listener onIAPOwnedPurchases:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                rst['ownedPurchases'].forEach(purchaseInfo => {
                    const purchase = JSON.parse(purchaseInfo.inAppPurchaseData);
                    const pToken = purchase["purchaseToken"];
                    const pId = purchase["productId"];
 
                    cc.log(pId);
                    cc.log(pToken);
                    if (self.isConsumable(pId)) {
                        self.addPurchaseToken(pToken);
                    }
                });
            },
            onIAPOwnedPurchaseRecords: function(code, msg) {
                self.log('HMS Listener onIAPOwnedPurchaseRecords:' + code);
                cc.log(msg);
            },

            onAchievementList(code, errorOrJson) {
                self.log('HMS Listener onAchievementList:' + code);
                cc.log(errorOrJson);
            },
        
            onAchievementShow(code, errorOrJson) {
                self.log('HMS Listener onAchievementShow:' + code);
                cc.log(errorOrJson);
            },
        
            onAchievementVisualize(code, errorOrJson) {
                self.log('HMS Listener onAchievementVisualize:' + code);
                cc.log(errorOrJson);
            },
        
            onAchievementGrow(code, errorOrJson) {
                self.log('HMS Listener onAchievementGrow:' + code);
                cc.log(errorOrJson);
            },
        
            onAchievementMakeSteps(code, errorOrJson) {
                self.log('HMS Listener onAchievementMakeSteps:' + code);
                cc.log(errorOrJson);
            },
        
            onEventList(code, errorOrJson) {
                self.log('HMS Listener onEventList:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingSwitchStatus(code, errorOrJson) {
                self.log('HMS Listener onRankingSwitchStatus:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingSetSwitchStatus(code, errorOrJson) {
                self.log('HMS Listener onRankingSetSwitchStatus:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingSubmitScore(code, errorOrJson) {
                self.log('HMS Listener onRankingSubmitScore:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingShow(code, errorOrJson) {
                self.log('HMS Listener onRankingShow:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingList(code, errorOrJson) {
                self.log('HMS Listener onRankingList:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingCurPlayerScore(code, errorOrJson) {
                self.log('HMS Listener onRankingCurPlayerScore:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingPlayerCenteredScores(code, errorOrJson) {
                self.log('HMS Listener onRankingPlayerCenteredScores:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingMoreScores(code, errorOrJson) {
                self.log('HMS Listener onRankingMoreScores:' + code);
                cc.log(errorOrJson);
            },
        
            onRankingTopScores(code, errorOrJson) {
                self.log('HMS Listener onRankingTopScores:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveLimitThumbnailSize(code, errorOrJson) {
                self.log('HMS Listener onArchiveLimitThumbnailSize:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveLimitDetailsSize(code, errorOrJson) {
                self.log('HMS Listener onArchiveLimitDetailsSize:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveAdd(code, errorOrJson) {
                self.log('HMS Listener onArchiveAdd:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveShow(code, errorOrJson) {
                self.log('HMS Listener onArchiveShow:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveSummaryList(code, errorOrJson) {
                self.log('HMS Listener onArchiveSummaryList:' + code);
                cc.log(errorOrJson);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(errorOrJson);

                // random select a archive id for test
                let idx = self.randomInt(0, rst.archiveSummarys.length);
                self.archiveId = rst.archiveSummarys[idx].id;
            },
        
            onArchiveSelect(code, errorOrJson) {
                self.log('HMS Listener onArchiveSelect:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveThumbnail(code, errorOrJson, coverData) {
                self.log('HMS Listener onArchiveThumbnail:' + code + ' len:' + coverData.length);
                cc.log(errorOrJson);
            },
        
            onArchiveUpdate(code, errorOrJson) {
                self.log('HMS Listener onArchiveUpdate:' + code);
                cc.log(errorOrJson);
            },
        
            onArchiveLoad(code, errorOrJson, contentData) {
                self.log('HMS Listener onArchiveLoad:' + code + ' len:' + contentData.length);
                cc.log(errorOrJson);
            },
        
            onArchiveRemove(code, errorOrJson) {
                self.log('HMS Listener onArchiveRemove:' + code);
                cc.log(errorOrJson);
            },
        
            onGamePlayerStats(code, errorOrJson) {
                self.log('HMS Listener onGamePlayerStats:' + code);
                cc.log(errorOrJson);
            },
        
            onGameSummary(code, errorOrJson) {
                self.log('HMS Listener onGameSummary:' + code);
                cc.log(errorOrJson);
            },

            onAdClose(code, errorOrJson) {
                self.log("HMS listener onAdClose code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdFail(code, errorOrJson) {
                self.log("HMS listener onAdFail code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdLeave(code, errorOrJson) {
                self.log("HMS listener onAdLeave code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdOpen(code, errorOrJson) {
                self.log("HMS listener onAdOpen code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdLoad(code, errorOrJson) {
                self.log("HMS listener onAdLoad code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdClick(code, errorOrJson) {
                self.log("HMS listener onAdClick code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdImpression(code, errorOrJson) {
                self.log("HMS listener onAdImpression code:" + code);
                cc.log(errorOrJson);
            },
        
            onAdReward(code, errorOrJson) {
                self.log("HMS listener onAdReward code:" + code);
                cc.log(errorOrJson);
            },


        };

        sdkbox.PluginHMS.setListener(listener);
        sdkbox.PluginHMS.init();
        sdkbox.PluginHMS.buoyShow();

        sdkbox.PluginHMS.adSetRewardData("cdata");
        sdkbox.PluginHMS.adSetRewardUserId("uid666");

        /*
         * adContentClassification:
         *   "W"->Content suitable for toddlers and older audiences;
         *  "PI"->Content suitable for kids and older audiences
         *   "J"->Content suitable for teenagers and older audiences.
         *   "A"->Content suitable only for adults.
         *    ""->Unknown rating.
         */
        sdkbox.PluginHMS.adSetAdContentClassification("A");

        /*
         * tagForUnderAgeOfPromise:
         *  0->Do not process ad requests as directed to users under the age of consent;
         *  1->Process ad requests as directed to users under the age of consent;
         * -1->Whether to process ad requests as directed to users under the age of consent is not specified;
         */
        sdkbox.PluginHMS.adSetTagForUnderAgeOfPromise(0);

        /*
        * tagForChildProtection:
        *  0->Do not process ad requests according to the COPPA;
        *  1->Process ad requests according to the COPPA;
        * -1->Whether to process ad requests according to the COPPA is not specified;
        */
        sdkbox.PluginHMS.adSetTagForChildProtection(0);

        /*
        * nonPersonalizedAd
        *  0->Request both personalized and non-personalized ads (default);
        *  1->Request only non-personalized ads;
        */
        sdkbox.PluginHMS.adSetNonPersonalizedAd(0);

    },

    isConsumable: function(productId) {
        if (!this.hmsProducts) {
            return false;
        }
        for (let i = 0; i < this.hmsProducts.length; i++) {
            const product = this.hmsProducts[i];
            if (product.productId === productId) {
                if (product.type === 'consumable') {
                    return true;
                }
            }
        }

        if (productId == 'com.sdkbox.unmanaged.consumable1') {
            // this is unmanaged product
            return true;
        }

        return false;
    },

    addPurchaseToken: function(purchaseToken) {
        if (!this.purchaseTokens) {
            this.purchaseTokens = [];
        }
        this.purchaseTokens.push(purchaseToken);
    },

    loadCoverImage: function() {
        const self = this;
        cc.loader.load(
            { url: cc.url.raw('resources/icon') + '.png', type: 'binary'},
            (err, binaryData) => {
                if (err) {
                    cc.log(err.message || err);
                    return;
                }
                self.coverData = binaryData;
            }
        );
    },

    stringToUint8Array(str) {
        let arr = [];
        for (let i = 0, j = str.length; i < j; ++i) {
          arr.push(str.charCodeAt(i));
        }

        return new Uint8Array(arr)
    },

    randomInt: function(min, max) {
        return parseInt(Math.random() * (max - min + 1) + min);
    },

    showMenu(menuName) {
        this.menu.node.removeAllChildren(true);
        let title = menuName;
        if ('' == title) {
            title = "HMS";
        }
        this.title.string = title;
        if (title == "HMS") {
            this.genMainMenu();
        } else if (title == "Account") {
            this.genAccountMenu();
        } else if (title == "IAP") {
            this.genIAPMenu();
        } else if (title == "Player") {
            this.genGamePlayerMenu();
        } else if (title == "Achievement") {
            this.genGameAchievementMenu();
        } else if (title == "Event") {
            this.genGameEventMenu();
        } else if (title == "Ranking") {
            this.genGameRankingMenu();
        } else if (title == "Archive") {
            this.genGameArchiveMenu();
        } else if (title == "Status") {
            this.genGameStatsMenu();
        } else if (title == "Ad") {
            this.genAdMenu();
        }
        this.menu.node.addChild(this.newMenuItem("Back"));

        // this.menu._doLayout();
    },

    newMenuItem(txt) {
        const item = cc.instantiate(this.btnTemplate.node);
        item.active = true;

        const lab = item.getChildByName('Label').getComponent(cc.Label);
        lab.string = txt;

        const btn = item.getComponent(cc.Button);

        const eventHandler = new cc.Component.EventHandler();
        eventHandler.target = this;
        eventHandler.component = "HelloWorld";
        eventHandler.handler = "onButtonClick";
        eventHandler.customEventData = txt;

        btn.clickEvents.push(eventHandler);

        return item;
    },

    onButtonClick: function(sender, menuItemType) {
        if (menuItemType == "Account Test") {
            this.showMenu('Account');
        } else if (menuItemType == "IAP Test") {
            this.showMenu('IAP');
        } else if (menuItemType == "Game Player Test") {
            this.showMenu('Player');
        } else if (menuItemType == "Game Achievement Test") {
            this.showMenu('Achievement');
        } else if (menuItemType == "Game Event Test") {
            this.showMenu('Event');
        } else if (menuItemType == "Game Ranking Test") {
            this.showMenu('Ranking');
        } else if (menuItemType == "Game Archive Test") {
            this.showMenu('Archive');
        } else if (menuItemType == "Game Status Test") {
            this.showMenu('Status');
        } else if (menuItemType == "Ad Test") {
            this.showMenu('Ad');

        // Account
        } else if (menuItemType == "Login") {
            // const loginType = 0; //slient login
            const loginType = 1; //idtoken login
            // const loginType = 2; //authcode login

            this.log('to login with type:' + loginType);
            sdkbox.PluginHMS.login(loginType);
        } else if (menuItemType == "Logout") {
            this.log('to logout...');
            sdkbox.PluginHMS.logout();


        // IAP
        } else if (menuItemType == "RequestProducts") {
            this.log('to request products');
            sdkbox.PluginHMS.iapRequestProducts();
        } else if (menuItemType == "Purchase") {
            this.log('to purchase');
            const productName = "coin";
            // const productName = "remove_ads";
            // const productName = "vip";
            sdkbox.PluginHMS.iapPurchase(productName);
        } else if (menuItemType == "PurchaseWithPrice") {
            this.log('to purchase with price');
            const productInfo = {
                productName: "Unmanaged0",
                productId: "com.sdkbox.unmanaged.consumable1",
                priceType: 0, // 0: consumable 1: non-consumable 2: subscription
                amount: "1.99",
                currency: "CNY",
                country: "CN",
                sdkChannel: "1", // length must between 0, 4
                serviceCatalog: "X38",
                reservedInfor:  "{'a':1,'b':'s'}", // must be json string
                developerPayload: "payload1"
            };
            sdkbox.PluginHMS.iapPurchaseWithPrice(JSON.stringify(productInfo));
        } else if (menuItemType == "Consume") {
            if (!this.purchaseTokens || 0 == this.purchaseTokens.length) {
                this.log('no consumable product')
                return;
            }
            this.log('to consume');
            const purchaseToken = this.purchaseTokens.shift();
            sdkbox.PluginHMS.iapConsume(purchaseToken);
        } else if (menuItemType == "RequestOwnedPurchase") {
            this.log('to request owned purchase');
            sdkbox.PluginHMS.iapRequestOwnedPurchases();
        } else if (menuItemType == "RequestOwnedPurchaseRecord") {
            this.log('to request owned purchase record');
            sdkbox.PluginHMS.iapRequestOwnedPurchaseRecords();


        // Player
        } else if (menuItemType == "ReqPlayInfo") {
            this.log('to ReqPlayInfo...');
            sdkbox.PluginHMS.playerRequestInfo();
        } else if (menuItemType == "ReqPlayExtraInfo") {
            this.log('to ReqPlayExtraInfo...');
            sdkbox.PluginHMS.playerRequestExtraInfo();
        } else if (menuItemType == "SubmitGameBegin") {
            this.log('to SubmitGameBegin...');
            sdkbox.PluginHMS.playerSubmitGameBegin();
        } else if (menuItemType == "SubmitGameEnd") {
            this.log('to SubmitGameEnd...');
            sdkbox.PluginHMS.playerSubmitGameEnd();


        // Achievement
        } else if (menuItemType == "ReqAchievementList") {
            this.log("to achievementRequestList...");
            sdkbox.PluginHMS.achievementRequestList();
        } else if (menuItemType == "ShowAchievementList") {
            this.log("to achievementShow...");
            sdkbox.PluginHMS.achievementShow();
        } else if (menuItemType == "VisualizeAchievement") {
            this.log("to achievementVisualize...");
            sdkbox.PluginHMS.achievementVisualize("5shoot");
        } else if (menuItemType == "GrowAchievement") {
            this.log("to achievementGrow...");
            sdkbox.PluginHMS.achievementGrow("3shoot", 1);
        } else if (menuItemType == "MakeStepsAchievement") {
            this.log("to achievementMakeSteps...");
            sdkbox.PluginHMS.achievementMakeSteps("3shoot", 2);
        } else if (menuItemType == "ReachAchievement") {
            this.log("to achievementReach...");
            sdkbox.PluginHMS.achievementReach("freshman");


        // Game Event
        } else if (menuItemType == "Grow Event") {
            this.log("to eventGrow...");
            sdkbox.PluginHMS.eventGrow("gencoin", 1);
        } else if (menuItemType == "Event List") {
            this.log("to eventRequestList...");
            sdkbox.PluginHMS.eventRequestList(true, "gencoin,consumecoin");


        // Game Ranking
        } else if (menuItemType == "Request Switch Status") {
            this.log("to rankingRequestSwitchStatus...");
            sdkbox.PluginHMS.rankingRequestSwitchStatus();
        } else if (menuItemType == "Set Switch Status") {
            this.log("to rankingSetSwitchStatus...");
            sdkbox.PluginHMS.rankingSetSwitchStatus(1);
        } else if (menuItemType == "Submit Score") {
            this.log("to rankingSubmitScore...");
            sdkbox.PluginHMS.rankingSubmitScore("shooter", 23, "H");
        } else if (menuItemType == "Show Ranking") {
            this.log("to rankingShow...");
            let timeDimension = 0; // day
            timeDimension = 1; // week
            timeDimension = 2; // all time
            sdkbox.PluginHMS.rankingShow(timeDimension, "shooter");
            // sdkbox.PluginHMS.rankingShow(timeDimension); // show all ranking
        } else if (menuItemType == "Request Ranking List") {
            this.log("to rankingRequestList...");
            let realtime = true;
            realtime = false; // use cachce
            sdkbox.PluginHMS.rankingRequestList(realtime, "shooter");
        } else if (menuItemType == "Request Cur Player Score") {
            this.log("to rankingRequestCurPlayerScore...");
            const rankingName = "shooter";
            let timeDimension = 0; // day
            timeDimension = 1; // week
            timeDimension = 2; // all time
            sdkbox.PluginHMS.rankingRequestCurPlayerScore(rankingName, timeDimension);
        } else if (menuItemType == "Request Player Centered Scores") {
            this.log("to rankingRequestPlayerCenteredScores...");
            const rankingName = "shooter";
            let timeDimension = 0; // day
            timeDimension = 1; // week
            timeDimension = 2; // all time
            sdkbox.PluginHMS.rankingRequestPlayerCenteredScores(rankingName, timeDimension, 9, false);
        } else if (menuItemType == "Request More Scores") {
            this.log("to rankingRequestMoreScores...");
            const rankingName = "shooter";
            let timeDimension = 0; // day
            timeDimension = 1; // week
            timeDimension = 2; // all time
            const offset = 1;
            const pageSize = 10;
            const pageDirection = 0; //0: next page, 1: previous page
            sdkbox.PluginHMS.rankingRequestMoreScores(rankingName, timeDimension, offset, pageSize, pageDirection);
        } else if (menuItemType == "Request Top Scores") {
            this.log("to rankingRequestTopScores...");
            const rankingName = "shooter";
            let timeDimension = 0; // day
            timeDimension = 1; // week
            timeDimension = 2; // all time
            const offset = 1;
            const pageSize = 10;
            const pageDirection = 0; //0: next page, 1: previous page
            sdkbox.PluginHMS.rankingRequestTopScores(rankingName, timeDimension, offset, pageSize, pageDirection);


        // Archive
        } else if (menuItemType == "Request LimitThumbnailSize") {
            this.log("to archiveRequestLimitThumbnailSize...");
            sdkbox.PluginHMS.archiveRequestLimitThumbnailSize();
        } else if (menuItemType == "Request LimitDetailsSize") {
            this.log("to archiveRequestLimitDetailsSize...");
            sdkbox.PluginHMS.archiveRequestLimitDetailsSize();
        } else if (menuItemType == "Add Archive") {
            this.log("to archiveAdd...");
            const playedTime = this.randomInt(1, 10000);
            const progress = this.randomInt(1, 100);
            const description = "this is archive description";
            const supportCache = true;
            const archiveData = this.stringToUint8Array('archive data from js');
            const coverBytesType = "png";

            cc.log(`time: ${playedTime}, progress: ${progress}, data: ${archiveData}`);
            sdkbox.PluginHMS.archiveAdd(playedTime, progress, description, supportCache,
                                          this.coverData, coverBytesType,
                                          archiveData);
        } else if (menuItemType == "Show Archives") {
            this.log("to archiveShow...");
            const archivesTitle = "Archive Title";
            const showAddButton = true;
            const showDeleteButton = true;
            const pageSize = 10;
            sdkbox.PluginHMS.archiveShow(archivesTitle, showAddButton, showDeleteButton, pageSize);
        } else if (menuItemType == "Request Archive Summary List") {
            this.log("to archiveRequestSummaryList...");
            const realtime = true;
            sdkbox.PluginHMS.archiveRequestSummaryList(realtime);
        } else if (menuItemType == "Request Archive Thumbnail") {
            if (!this.archiveId) {
                this.log("archive id is empty");
                return;
            }
            this.log("to archiveRequestThumbnail...");
            sdkbox.PluginHMS.archiveRequestThumbnail(this.archiveId);
        } else if (menuItemType == "Update Archive") {
            if (!this.archiveId) {
                this.log("archive id is empty");
                return;
            }
            this.log("to archiveUpdate...");
            const playedTime = this.randomInt(1, 10000);
            const progress = this.randomInt(1, 100);
            const description = "this is archive updated description";
            const coverBytesType = "png";
            const archiveData = this.stringToUint8Array('archive data from js ' + this.randomInt(1, 1000));

            sdkbox.PluginHMS.archiveUpdate(this.archiveId,
                                             playedTime, progress, description,
                                             this.coverData, coverBytesType,
                                             archiveData);
        } else if (menuItemType == "Load Archive") {
            if (!this.archiveId) {
                this.log("archive id is empty");
                return;
            }
            this.log("to archiveLoad...");
            let conflictPolicy = -1; //hms willn't process conflict
            conflictPolicy = 1; //hms will resolved conflict by played time
            conflictPolicy = 2; //hms will resolved conflict by progress
            conflictPolicy = 3; //hms will resolved conflict by last update time
            sdkbox.PluginHMS.archiveLoad(this.archiveId, conflictPolicy);
        } else if (menuItemType == "Remove Archive") {
            if (!this.archiveId) {
                this.log("archive id is empty");
                return;
            }
            this.log("to archiveRemove...");
            sdkbox.PluginHMS.archiveRemove(this.archiveId);


        // Game Status
        } else if (menuItemType == "Game Player Stats") {
            this.log("to gamePlayerStatsRequest...");
            const realtime = false;
            sdkbox.PluginHMS.gamePlayerStatsRequest(realtime);
        } else if (menuItemType == "Game Summary") {
            this.log("to gameSummaryRequest...");
            const realtime = false;
            sdkbox.PluginHMS.gameSummaryRequest(realtime);

        // Ad
        } else if (menuItemType == "Change AdName") {
            if (this.adName) {
                this.adNameArray.push(this.adName);
            }
            this.adName = this.adNameArray.shift();
            this.log("current ad: " + this.adName);
        } else if (menuItemType == "Cache") {
            this.log("to adCache...");
            sdkbox.PluginHMS.adCache(this.adName);
        } else if (menuItemType == "Show") {
            this.log("to adShow...");
            sdkbox.PluginHMS.adShow(this.adName);
        } else if (menuItemType == "Hide") {
            this.log("to adHide...");
            sdkbox.PluginHMS.adHide(this.adName);

        } else if (menuItemType == "Back") {
            this.showMenu('HMS');
        } else {
            cc.log("Error! unknow menu item:" + menuItemType);
        }
    },

    genMainMenu() {
        this.menu.node.addChild(this.newMenuItem('Account Test'));
        this.menu.node.addChild(this.newMenuItem('IAP Test'));
        this.menu.node.addChild(this.newMenuItem('Game Player Test'));
        this.menu.node.addChild(this.newMenuItem('Game Achievement Test'));
        this.menu.node.addChild(this.newMenuItem('Game Event Test'));
        this.menu.node.addChild(this.newMenuItem('Game Ranking Test'));
        this.menu.node.addChild(this.newMenuItem('Game Archive Test'));
        this.menu.node.addChild(this.newMenuItem('Game Status Test'));
        this.menu.node.addChild(this.newMenuItem('Ad Test'));
    },

    genAccountMenu() {
        this.menu.node.addChild(this.newMenuItem('Login'));
        this.menu.node.addChild(this.newMenuItem('Logout'));
    },

    genIAPMenu() {
        this.menu.node.addChild(this.newMenuItem('RequestProducts'));
        this.menu.node.addChild(this.newMenuItem('Purchase'));
        this.menu.node.addChild(this.newMenuItem('PurchaseWithPrice'));
        this.menu.node.addChild(this.newMenuItem('Consume'));
        this.menu.node.addChild(this.newMenuItem('RequestOwnedPurchase'));
        this.menu.node.addChild(this.newMenuItem('RequestOwnedPurchaseRecord'));
    },

    genGamePlayerMenu() {
        this.menu.node.addChild(this.newMenuItem('ReqPlayInfo'));
        this.menu.node.addChild(this.newMenuItem('ReqPlayExtraInfo'));
        this.menu.node.addChild(this.newMenuItem('SubmitGameBegin'));
        this.menu.node.addChild(this.newMenuItem('SubmitGameEnd'));
    },

    genGameAchievementMenu() {
        this.menu.node.addChild(this.newMenuItem('ReqAchievementList'));
        this.menu.node.addChild(this.newMenuItem('ShowAchievementList'));
        this.menu.node.addChild(this.newMenuItem('VisualizeAchievement'));
        this.menu.node.addChild(this.newMenuItem('GrowAchievement'));
        this.menu.node.addChild(this.newMenuItem('MakeStepsAchievement'));
        this.menu.node.addChild(this.newMenuItem('ReachAchievement'));
    },

    genGameEventMenu() {
        this.menu.node.addChild(this.newMenuItem('Grow Event'));
        this.menu.node.addChild(this.newMenuItem('Event List'));
    },

    genGameRankingMenu() {
        this.menu.node.addChild(this.newMenuItem('Request Switch Status'));
        this.menu.node.addChild(this.newMenuItem('Set Switch Status'));
        this.menu.node.addChild(this.newMenuItem('Submit Score'));
        this.menu.node.addChild(this.newMenuItem('Show Ranking'));
        this.menu.node.addChild(this.newMenuItem('Request Ranking List'));
        this.menu.node.addChild(this.newMenuItem('Request Cur Player Score'));
        this.menu.node.addChild(this.newMenuItem('Request Player Centered Scores'));
        this.menu.node.addChild(this.newMenuItem('Request More Scores'));
        this.menu.node.addChild(this.newMenuItem('Request Top Scores'));
    },

    genGameArchiveMenu() {
        this.menu.node.addChild(this.newMenuItem('Request LimitThumbnailSize'));
        this.menu.node.addChild(this.newMenuItem('Request LimitDetailsSize'));
        this.menu.node.addChild(this.newMenuItem('Add Archive'));
        this.menu.node.addChild(this.newMenuItem('Show Archives'));
        this.menu.node.addChild(this.newMenuItem('Request Archive Summary List'));
        this.menu.node.addChild(this.newMenuItem('Request Archive Thumbnail'));
        this.menu.node.addChild(this.newMenuItem('Update Archive'));
        this.menu.node.addChild(this.newMenuItem('Load Archive'));
        this.menu.node.addChild(this.newMenuItem('Remove Archive'));
    },

    genGameStatsMenu() {
        this.menu.node.addChild(this.newMenuItem('Game Player Stats'));
        this.menu.node.addChild(this.newMenuItem('Game Summary'));
    },

    genAdMenu() {
        this.menu.node.addChild(this.newMenuItem('Change AdName'));
        this.menu.node.addChild(this.newMenuItem('Cache'));
        this.menu.node.addChild(this.newMenuItem('Show'));
        this.menu.node.addChild(this.newMenuItem('Hide'));
    },

    log: function(s) {
        cc.log(s);
        let lines = this.logs.string.split('\n');
        while (lines.length > 5) {
            lines.shift();
        }
        lines.push(s);
        this.logs.string = lines.join('\n');
    },

    // called every frame
    update: function (dt) {
    },
});
