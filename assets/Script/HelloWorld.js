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
        this.initPluginAppodeal();
    },

    initPluginAppodeal: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginAppodeal) {
            this.log('sdkbox.PluginAppodeal is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginAppodeal.setListener({
            onBannerDidLoadAd: function() {
                self.log("onBannerDidLoadAd");
            },
            onBannerDidFailToLoadAd: function() {
                self.log("onBannerDidFailToLoadAd");
            },
            onBannerDidClick: function() {
                self.log("onBannerDidClick");
            },
            onBannerPresent: function() {
                self.log("onBannerPresent");
            },
            onInterstitialDidLoadAd: function() {
                self.log("onInterstitialDidLoadAd");
            },
            onInterstitialDidFailToLoadAd: function() {
                self.log("onInterstitialDidFailToLoadAd");
            },
            onInterstitialWillPresent: function() {
                self.log("onInterstitialWillPresent");
            },
            onInterstitialDidDismiss: function() {
                self.log("onInterstitialDidDismiss");
            },
            onInterstitialDidClick: function() {
                self.log("onInterstitialDidClick");
            },
            onVideoDidLoadAd: function() {
                self.log("onVideoDidLoadAd");
            },
            onVideoDidFailToLoadAd: function() {
                self.log("onVideoDidFailToLoadAd");
            },
            onVideoDidPresent: function() {
                self.log("onVideoDidPresent");
            },
            onVideoWillDismiss: function() {
                self.log("onVideoWillDismiss");
            },
            onVideoDidFinish: function() {
                self.log("onVideoDidFinish");
            },
            onRewardVideoDidLoadAd: function() {
                self.log("onRewardVideoDidLoadAd");
            },
            onRewardVideoDidFailToLoadAd: function() {
                self.log("onRewardVideoDidFailToLoadAd");
            },
            onRewardVideoDidPresent: function() {
                self.log("onRewardVideoDidPresent");
            },
            onRewardVideoWillDismiss: function() {
                self.log("onRewardVideoWillDismiss");
            },
            onRewardVideoDidFinish: function(amount, name) {
                self.log("onRewardVideoDidFinish:" + amount + ':' + name);
            },
            onSkippableVideoDidLoadAd: function() {
                self.log("onSkippableVideoDidLoadAd");
            },
            onSkippableVideoDidFailToLoadAd: function() {
                self.log("onSkippableVideoDidFailToLoadAd");
            },
            onSkippableVideoDidPresent: function() {
                self.log("onSkippableVideoDidPresent");
            },
            onSkippableVideoWillDismiss: function() {
                self.log("onSkippableVideoWillDismiss");
            },
            onSkippableVideoDidFinish: function() {
                self.log("onSkippableVideoDidFinish");
            },
            onSkippableVideoDidClick: function() {
                self.log("onSkippableVideoDidClick");
            },
            onNonSkippableVideoDidLoadAd: function() {
                self.log("onNonSkippableVideoDidLoadAd");
            },
            onNonSkippableVideoDidFailToLoadAd: function() {
                self.log("onNonSkippableVideoDidFailToLoadAd");
            },
            onNonSkippableVideoDidPresent: function() {
                self.log("onNonSkippableVideoDidPresent");
            },
            onNonSkippableVideoWillDismiss: function() {
                self.log("onNonSkippableVideoWillDismiss");
            },
            onNonSkippableVideoDidFinish: function() {
                self.log("onNonSkippableVideoDidFinish");
            },
            onNonSkippableVideoDidClick: function() {
                self.log("onNonSkippableVideoDidClick");
            }
        });
        sdkbox.PluginAppodeal.init();

        // const AppodealShowStyleInterstitial = 1;
        // const AppodealShowStyleBannerTop = 4;
        // const AppodealShowStyleBannerBottom = 8;
        // const AppodealShowStyleRewardedVideo = 16;
        // const AppodealShowStyleNonSkippableVideo = 32;

    },

    onButton1: function() {
        const AppodealShowStyleBannerBottom = 8;
        if (sdkbox.PluginAppodeal.isReadyForShowWithStyle(AppodealShowStyleBannerBottom)) {
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleBannerBottom);
        } else {
            this.log("banner is not ready");
        }
    },

    onButton2: function() {
        const AppodealShowStyleRewardedVideo = 16;
        if (sdkbox.PluginAppodeal.isReadyForShowWithStyle(AppodealShowStyleRewardedVideo)) {
            sdkbox.PluginAppodeal.showAd(AppodealShowStyleRewardedVideo);
        } else {
            this.log("video is not ready");
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
