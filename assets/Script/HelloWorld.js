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
