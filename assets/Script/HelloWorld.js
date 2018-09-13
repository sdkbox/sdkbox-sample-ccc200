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
        this.initPluginAdColony();
    },

    initPluginAdColony: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginAdColony) {
            this.log('sdkbox.PluginAdColony is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginAdColony.setListener({
            onAdColonyChange : function (data, available) {
                self.log("onAdColonyChange:" + data.name + ':' + available);
            },
            onAdColonyReward : function (data, currencyName, amount, success) {
                self.log("onAdColonyReward:" + data.name + ':' + currencyName + ':' + amount + ':' + success);
            },
            onAdColonyStarted : function (data) {
                self.log("onAdColonyStarted:" + data.name);
            },
            onAdColonyFinished : function (data) {
                self.log("onAdColonyFinished:" + data.name);
            }
        });
        sdkbox.PluginAdColony.init();
    },

    onButton1: function() {
        if (3 == sdkbox.PluginAdColony.getStatus("video")) {
            sdkbox.PluginAdColony.show("video");
        } else {
            this.log("video is not ready, to cache");
            sdkbox.PluginAdColony.requestAllAds();
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
