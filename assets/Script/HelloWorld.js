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
        this.initPluginUnityAds();
    },

    initPluginUnityAds: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginUnityAds) {
            this.log('sdkbox.PluginUnityAds is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginUnityAds.setListener({
            unityAdsDidClick: function(placementId) {
                self.log('unityAdsDidClick ' + placementId);
            },
            unityAdsPlacementStateChanged: function(placementId, oldState, newState) {
                self.log('unityAdsPlacementStateChanged:' + placementId + ' oldState:' + oldState + " newState:" + newState);
            },
            unityAdsReady: function(placementId) {
                self.log('unityAdsReady ' + placementId);
            },
            unityAdsDidError: function(error, message) {
                self.log('unityAdsDidError:' + error + ' message:' + message);
            },
            unityAdsDidStart: function(placementId) {
                self.log('unityAdsDidStart=' + placementId);
            },
            unityAdsDidFinish: function(placementId, state) {
                self.log('unityAdsDidFinish ' + placementId + ' state:' + state);
            }
        });
        sdkbox.PluginUnityAds.init();
    },

    onButton1: function() {
         const placementId = '';
        if (sdkbox.PluginUnityAds.isReady(placementId)) {
            sdkbox.PluginUnityAds.show(placementId);
        } else {
            this.log('unityads is not ready');
        }
    },

    log: function(s) {
        cc.log(s);
        let lines = this.logs.string.split('\n');
        cc.log(lines);
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
