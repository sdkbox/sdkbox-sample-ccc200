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
        this.initPluginGoogleAnalytics();
    },

    initPluginGoogleAnalytics: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginGoogleAnalytics) {
            this.log('sdkbox.PluginGoogleAnalytics is undefined');
            return;
        }

        this.log('Google Analytics init');
        sdkbox.PluginGoogleAnalytics.init();
    },

    onButton1: function() {
        this.log('log event');
        sdkbox.PluginGoogleAnalytics.logEvent("Test", "Click", "", 1);
        sdkbox.PluginGoogleAnalytics.dispatchHits();
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
