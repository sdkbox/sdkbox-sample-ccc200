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
        this.initPluginChartboost();
    },

    initPluginChartboost: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginChartboost) {
            this.log('sdkbox.PluginChartboost is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginChartboost.setListener({
            onChartboostCached : function (name) {
                self.log("onChartboostCached:" + name);
            },
            onChartboostShouldDisplay : function (name) {
                self.log("onChartboostShouldDisplay:" + name);
            },
            onChartboostDisplay : function (name) {
                self.log("onChartboostDisplay:" + name);
            },
            onChartboostDismiss : function (name) {
                self.log("onChartboostDismiss:" + name);
            },
            onChartboostClose : function (name) {
                self.log("onChartboostClose:" + name);
            },
            onChartboostClick : function (name) {
                self.log("onChartboostClick:" + name);
            },
            onChartboostReward : function (name, reward) {
                self.log("onChartboostReward:" + name + ":" + reward.toString());
            },
            onChartboostFailedToLoad : function (name, e) {
                self.log("onChartboostFailedToLoad:" + name + ":" + e.toString());
            },
            onChartboostFailToRecordClick : function (name, e) {
                self.log("onChartboostFailToRecordClick:" + name + ":" + e.toString());
            },
            onChartboostConfirmation : function () {
                self.log("onChartboostConfirmation");
            },
            onChartboostCompleteStore : function () {
                self.log("onChartboostCompleteStore");
            }
        });
        sdkbox.PluginChartboost.init();
    },

    onButton1: function() {
        const adName = 'Default';
        if (sdkbox.PluginChartboost.isAvailable(adName)) {
            sdkbox.PluginChartboost.show(adName);
        } else {
            this.log(adName + ' is not available, to cache...');
            sdkbox.PluginChartboost.cache(adName);
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
