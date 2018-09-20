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
        this.initPluginFyber();
    },

    initPluginFyber: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginFyber) {
            this.log('sdkbox.PluginFyber is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginFyber.setListener({
            onVirtualCurrencyConnectorFailed : function (error, errorCode, errorMsg) {
                self.log("onVirtualCurrencyConnectorFailed:" + error + ":" + errorCode + ':' + errorMsg);
            },
            onVirtualCurrencyConnectorSuccess : function (deltaOfCoins, currencyId, currencyName, transactionId) {
                self.log("onVirtualCurrencyConnectorSuccess:" + deltaOfCoins + ":" + currencyId + ':' + currencyName + ':' + transactionId);
            },
            onCanShowInterstitial : function (canShowInterstitial) {
                self.log("onCanShowInterstitial:" + canShowInterstitial);
                // show ad
                if (canShowInterstitial) {
                    sdkbox.PluginFyber.showInterstitial();
                }
            },
            onInterstitialDidShow : function () {
                self.log("onInterstitialDidShow");
            },
            onInterstitialDismiss : function (reason) {
                self.log("onInterstitialDismiss:" + reason);
            },
            onInterstitialFailed : function () {
                self.log("onInterstitialFailed");
            },
            onBrandEngageClientReceiveOffers : function (areOffersAvailable) {
                self.log("onBrandEngageClientReceiveOffers:" + areOffersAvailable);
                // show ad
                if (areOffersAvailable) {
                    sdkbox.PluginFyber.showOffers();
                }
            },
            onBrandEngageClientChangeStatus : function (status, msg) {
                self.log("onBrandEngageClientChangeStatus:" + status + ':' + msg);
            },
            onOfferWallFinish : function (status) {
                self.log("onOfferWallFinish:" + status);
            }
        });
        sdkbox.PluginFyber.init();
    },

    onButton1: function() {
        sdkbox.PluginFyber.requestInterstitial();
    },

    onButton2: function() {
        sdkbox.PluginFyber.requestOffers();
    },

    onButton3: function() {
        sdkbox.PluginFyber.showOfferWall();
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
