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
        this.initPluginSdkboxAds();
    },

    initPluginSdkboxAds: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginSdkboxAds) {
            this.log('sdkbox.PluginSdkboxAds is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginSdkboxAds.setListener({
            onAdAction : function(ad_unit_id, zone_location_place_you_name_it, action_type) {
                self.log("onAdAction:" + String(ad_unit_id) + ":" + String(zone_location_place_you_name_it) + ":" + String(action_type));
            },
            onRewardAction : function(ad_unit_id, zone_id, reward_amount, reward_succeed) {
                self.log("onRewardAction:" + String(ad_unit_id) + ":" + String(zone_id) + ":" + String(reward_amount) + ":" + String(reward_succeed));
            }
        });
        sdkbox.PluginSdkboxAds.init();
    },

    onButton1: function() {
        const placement = 'placement-1';
        if (sdkbox.PluginSdkboxAds.isAvailable(placement)) {
            sdkbox.PluginSdkboxAds.placement(placement);
        } else {
            this.log(placement + ' is not available');
        }
    },

    onButton2: function() {
        sdkbox.PluginSdkboxAds.playAd("AdMob", "interstitial");
        //sdkbox.PluginSdkboxAds.playAd("UnityAds", "rewardedVideo");
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
