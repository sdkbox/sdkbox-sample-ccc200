cc.Class({
    extends: cc.Component,

    properties: {
        logs: {
            default: null,
            type: cc.Label
        },
        // defaults, set visually when attaching this script to the Canvas
        text: 'Hello, World!'
    },

    // use this for initialization
    onLoad: function () {
        this.initPlugin();
    },

    initPlugin: function() {
        this.initPluginAdMob();
        this.initPluginFirebase();
        this.initPluginSdkboxPlay();
        this.initIAP();
    },

    initPluginAdMob: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginAdMob) {
            this.log('sdkbox.PluginAdMob is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginAdMob.setListener({
            adViewDidReceiveAd: function(name) {
                self.log('adViewDidReceiveAd:'+name);
            },
            adViewDidFailToReceiveAdWithError: function(name, msg) {
                self.log('adViewDidFailToReceiveAdWithError:'+name+':'+msg);
            },
            adViewWillPresentScreen: function(name) {
                self.log('adViewWillPresentScreen:'+name);
            },
            adViewDidDismissScreen: function(name) {
                self.log('adViewDidDismissScreen:'+name);
            },
            adViewWillDismissScreen: function(name) {
                self.log('adViewWillDismissScreen:'+name);
            },
            adViewWillLeaveApplication: function(name) {
                self.log('adViewWillLeaveApplication:'+name);
            },
            reward: function(name, currency, amount) {
                self.log('reward:'+name+':'+currency+':'+amount);
            }
        });
        sdkbox.PluginAdMob.init();
    },

    initPluginFirebase: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.firebase) {
            this.log('sdkbox.firebase is undefined');
            return;
        }

        sdkbox.firebase.Analytics.init();
    },

    initPluginSdkboxPlay: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginSdkboxPlay) {
            this.log('sdkbox.PluginSdkboxPlay is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginSdkboxPlay.setListener({
            onConnectionStatusChanged: function(connection_status) {
                self.log("onConnectionStatusChanged: " + connection_status);
                if (connection_status == 1000) {
                    self.log('Player id: ' + sdkbox.PluginSdkboxPlay.getPlayerId());
                    self.log('Player name: ' + sdkbox.PluginSdkboxPlay.getPlayerAccountField("name"));
                }
            },
            onScoreSubmitted: function(leaderboard_name, score, maxScoreAllTime, maxScoreWeek, maxScoreToday) {
                self.log('onScoreSubmitted' + leaderboard_name + ':' + score + ':' + maxScoreAllTime + ':' + maxScoreWeek + ':' + maxScoreToday);
            },
            onMyScore: function(leaderboard_name, time_span, collection_type, score) {
                self.log('onMyScore:' + leaderboard_name + ':' + time_span + ':' + collection_type + ':' + score);
            },
            onMyScoreError: function(leaderboard_name, time_span, collection_type, error_code, error_description) {
                self.log('onMyScoreError:' + leaderboard_name + ':' + time_span + ':' + collection_type + ':' + error_code + ':' + error_description);
            },
            onPlayerCenteredScores: function(leaderboard_name, time_span, collection_type, json_with_score_entries) {
                self.log('onPlayerCenteredScores:' + leaderboard_name + ':' + time_span + ':' + collection_type + ':' + json_with_score_entries);
            },
            onPlayerCenteredScoresError: function(leaderboard_name, time_span, collection_type, error_code, error_description) {
                self.log('onPlayerCenteredScoresError:' + leaderboard_name + ':' + time_span + ':' + collection_type + ':' + error_code + ':' + error_description);
            },
            onIncrementalAchievementUnlocked: function(achievement_name) {
                self.log("onIncrementalAchievementUnlocked:" + achievement_name);
            },
            onIncrementalAchievementStep: function(achievement_name, step) {
                self.log("onIncrementalAchievementStep:" + achievement_name + ":" + step);
            },
            onIncrementalAchievementStepError: function(name, steps, error_code, error_description) {
                self.log('onIncrementalAchievementStepError:' + name + ':' + steps + ':' + error_code + ':' + error_description);
            },
            onAchievementUnlocked: function(achievement_name, newlyUnlocked) {
                self.log('onAchievementUnlocked:' + achievement_name + ':' + newlyUnlocked);
            },
            onAchievementUnlockError: function(achievement_name, error_code, error_description) {
                self.log('onAchievementUnlockError:' + achievement_name + ':' + error_code + ':' + error_description);
            },
            onAchievementsLoaded: function(reload_forced, json_achievements_info) {
                self.log('onAchievementsLoaded:' + reload_forced + ':' + json_achievements_info);
            },
            onSetSteps: function(name, steps) {
                self.log('onSetSteps:' + name + ':' + steps);
            },
            onSetStepsError: function(name, steps, error_code, error_description) {
                self.log('onSetStepsError:' + name + ':' + steps + ':' + error_code + ':' + error_description);
            },
            onReveal: function(name) {
                self.log('onReveal:' + name);
            },
            onRevealError: function(name, error_code, error_description) {
                self.log('onRevealError:' + name + ':' + error_code + ':' + error_description);
            },
            onGameData: function(action, name, data, error) {
                if (error) {
                    // failed
                    self.log('onGameData failed:' + error);
                } else {
                    //success
                    if ('load' == action) {
                        self.log('onGameData load:' + name + ':' + data);
                    } else if ('save' == action) {
                        self.log('onGameData save:' + name + ':' + data);
                    } else {
                        self.log('onGameData unknown action:' + action);
                    }
                }
            },
            onSaveGameData: function(success, error) {
                if (error) {
                    // failed
                    self.log('onSaveGameData failed:' + error);
                } else {
                    //success
                    self.log('onSaveGameData success');
                }
            },
            onLoadGameData: function(savedData, error) {
                if (error) {
                    // failed
                    self.log('onLoadGameData failed:' + error);
                } else {
                    //success
                    if (savedData) {
                        // map["name"]
                        // map["data"] = cocos2d::Value((char*)gameData->data);
                        // map["dataLength"] = cocos2d::Value(gameData->dataLength);
                        // map["lastModifiedTimestamp"] = cocos2d::Value((double)gameData->lastModifiedTimestamp);
                        // map["deviceName"]

                        console.log(JSON.stringify(savedData));
                        self.log('onLoadGameData:' + savedData.name);
                    } else {
                        self.log('Load Game Data Finish');
                    }
                }
            },
            onGameDataNames: function(names, error) {
                if (error) {
                    // failed
                    self.log('onGameDataNames failed:' + error);
                } else {
                    //success
                    console.log(JSON.stringify(names));
                    self.log('onGameDataNames count:' + names.length);
                }
            }
        });
        sdkbox.PluginSdkboxPlay.init();
    },

    initIAP: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.IAP) {
            this.log('sdkbox.IAP is undefined');
            return;
        }

        if (sdkbox.setConfig) {
            sdkbox.setConfig(JSON.stringify(sdkbox_config));
        }

        const self = this;
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
                self.log("Purchase successful: " + product.name);
                self.printProduct(product);
            },
            onFailure : function (product, msg) {
                //Purchase failed
                //msg is the error message
                self.log("Purchase failed: " + product.name + " error: " + msg);

            },
            onCanceled : function (product) {
                //Purchase was canceled by user
                self.log("Purchase canceled: " + product.name);
            },
            onRestored : function (product) {
                //Purchase restored
                self.log("Restored: " + product.name);

                self.printProduct(product);
            },
            onProductRequestSuccess : function (products) {
                //Returns you the data for all the iap products
                //You can get each item using following method
                for (var i = 0; i < products.length; i++) {
                    self.printProduct(products[i]);
                    // self.log("================");
                    // self.log("name: " + products[i].name);
                    // self.log("price: " + products[i].price);
                    // self.log("priceValue: " + products[i].priceValue);
                    // self.log("================");
                }
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
                self.log("Failed to get products");
            },
            onShouldAddStorePayment: function(productId) {
                self.log("onShouldAddStorePayment:" + productId);
                return true;
            },
            onFetchStorePromotionOrder : function (productIds, error) {
                self.log("onFetchStorePromotionOrder:" + " " + " e:" + error);
            },
            onFetchStorePromotionVisibility : function (productId, visibility, error) {
                self.log("onFetchStorePromotionVisibility:" + productId + " v:" + visibility + " e:" + error);
            },
            onUpdateStorePromotionOrder : function (error) {
                self.log("onUpdateStorePromotionOrder:" + error);
            },
            onUpdateStorePromotionVisibility : function (error) {
                self.log("onUpdateStorePromotionVisibility:" + error);
            },
        });
        sdkbox.IAP.init();
        // sdkbox.IAP.setAutoFinishTransaction(false);
        sdkbox.IAP.setDebug(true);
    },

    onButton1: function() {
        const adName = 'interstitial'; //interstitial ad
        // const adName = 'reward'; //reward video
        if (sdkbox.PluginAdMob.isAvailable(adName)) {
            sdkbox.PluginAdMob.show(adName);
        } else {
            this.log(adName + ' is not available');
            sdkbox.PluginAdMob.cache(adName);
        }
    },

    onButton2: function() {
        const adName = 'banner';
        if (sdkbox.PluginAdMob.isAvailable(adName)) {
            sdkbox.PluginAdMob.show(adName);
        } else {
            this.log(adName + ' is not available');
            sdkbox.PluginAdMob.cache(adName);
        }
    },

    onButton3: function() {
        const evt = {}
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterPrice] = '123.4';

        // log event
        sdkbox.firebase.Analytics.logEvent(sdkbox.firebase.Analytics.Event.kFIREventViewItem, evt);

        // log custom event
        // evt['customKey'] = 'custom value';
        // sdkbox.firebase.Analytics.logEvent("customEvent", evt);
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
