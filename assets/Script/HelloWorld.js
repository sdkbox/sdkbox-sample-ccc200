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
        this.initPluginOneSignal();
    },

    initPluginOneSignal: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginOneSignal) {
            this.log('sdkbox.PluginOneSignal is undefined');
            return;
        }

        this.userId = null;
        const self = this;
        // sdkbox.PluginOneSignal.LogLevel.None
        // sdkbox.PluginOneSignal.LogLevel.Fatal
        // sdkbox.PluginOneSignal.LogLevel.Error
        // sdkbox.PluginOneSignal.LogLevel.Warn
        // sdkbox.PluginOneSignal.LogLevel.Info
        // sdkbox.PluginOneSignal.LogLevel.Debug
        // sdkbox.PluginOneSignal.LogLevel.Verbose
        // sdkbox.PluginOneSignal.setLogLevel(sdkbox.PluginOneSignal.LogLevel.Verbose, sdkbox.PluginOneSignal.LogLevel.Verbose);
        sdkbox.PluginOneSignal.setListener({
            onSendTag :function (success, key, message) {
                self.log('onSendTag:' + success + ':' + key + ':' + message);
            },
            onGetTags :function (jsonString) {
                self.log("onGetTags:" + jsonString);
            },
            onIdsAvailable :function (userId,  pushToken) {
                self.log("onIdsAvailable:" + userId + ':' + pushToken);
                self.userId = userId;
            },
            onPostNotification :function (success,  message) {
                self.log("onPostNotification:" + success);
                cc.log(message);
            },
            onNotification :function (isActive,  message, additionalData) {
                self.log("onNotification" + ':' + isActive);
                cc.log(message);
                cc.log(additionalData);
            }
        });
        sdkbox.PluginOneSignal.init();

        sdkbox.PluginOneSignal.setSubscription(true);
        sdkbox.PluginOneSignal.setEmail("test@example.com");
        sdkbox.PluginOneSignal.sendTag("keyjs", "valuejs");
        sdkbox.PluginOneSignal.sendTag("keyjs1", "valuejs1");
        sdkbox.PluginOneSignal.getTags();
        sdkbox.PluginOneSignal.deleteTag("keyjs");
        sdkbox.PluginOneSignal.idsAvailable();
        sdkbox.PluginOneSignal.enableInAppAlertNotification(true);
        sdkbox.PluginOneSignal.promptLocation();
    },

    onButton1: function() {
        const data = {
            "contents": {
                "en": "Js test message"
            },
            "include_player_ids": [
                this.userId,
                "33ad9d96-df00-42a2-b5ab-73417f777d42",
                "5ea075c5-016d-4f55-891c-3b6c4b393e49"
            ],
            "data": {
                "foo": "bar"
            }
        };
        const postStr = JSON.stringify(data);
        cc.log(postStr);
        sdkbox.PluginOneSignal.postNotification(postStr);
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
