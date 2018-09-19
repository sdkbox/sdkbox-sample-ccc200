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
        this.initPluginAppnext();
    },

    initPluginAppnext: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginAppnext) {
            this.log('sdkbox.PluginAppnext is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginAppnext.setListener({
            onAdError : function(msg) {
                self.log("onAdError: " + msg);
            },

            onAdLoaded : function() {
                self.log("onAdLoaded");
            },

            onAdOpened : function() {
                self.log("onAdOpened");
            },

            onAdClosed : function() {
                self.log("onAdClosed");
            },

            onAdClicked : function() {
                self.log("onAdClicked");
            },

            onVideoLoaded : function(name) {
                self.log("onVideoLoaded: " + name);
            },

            onVideoClicked : function(name) {
                self.log("onVideoClicked: " + name);
            },

            onVideoClosed : function(name) {
                self.log("onVideoClosed: " + name);
            },

            onVideoEnded : function(name) {
                self.log("onVideoEnded: " + name);
            },

            onVideoError : function(name, msg) {
                self.log("onVideoError: " + name);
            }
        });
        sdkbox.PluginAppnext.init();

    },

    onButton1: function() {
        if (sdkbox.PluginAppnext.isAdReady()) {
            sdkbox.PluginAppnext.showAd();
        } else {
            this.log("ad is not ready, to cache");
            sdkbox.PluginAppnext.cacheAd("default");
        }
    },

    onButton2: function() {
        const videoName = "fullscreen"; // 'reward'
        if (sdkbox.PluginAppnext.isVideoReady(videoName)) {
            sdkbox.PluginAppnext.showVideo(videoName);
        } else {
            this.log(videoName + " is not ready, to cache...");
            sdkbox.PluginAppnext.cacheVideo(videoName);
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
