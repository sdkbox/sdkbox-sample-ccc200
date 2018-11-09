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
        this.initPluginSdkboxPlay();
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

    onButton1: function() {
        if (sdkbox.PluginSdkboxPlay.isSignedIn()) {
            this.log('to signout...');
            sdkbox.PluginSdkboxPlay.signout();
        } else {
            this.log('to signin...');
            sdkbox.PluginSdkboxPlay.signin();
        }
    },

    onButton2: function() {
        if (sdkbox.PluginSdkboxPlay.isSignedIn()) {
            this.log('to save game data...');
            sdkbox.PluginSdkboxPlay.saveGameDataString("key1", "data");
        } else {
            this.log('need signin..');
        }
    },

    onButton3: function() {
        if (sdkbox.PluginSdkboxPlay.isSignedIn()) {
            this.log('to load all game data...');
            sdkbox.PluginSdkboxPlay.loadAllGameData();
        } else {
            this.log('need signin...');
        }
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
