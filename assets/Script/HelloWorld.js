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
        this.initPluginApteligent();
    },

    initPluginApteligent: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginApteligent) {
            this.log('sdkbox.PluginApteligent is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginApteligent.setListener({
            onCrashOnLastLoad: function() {
                self.log("onCrashOnLastRun");
            }
        });
        sdkbox.PluginApteligent.init();

        sdkbox.PluginApteligent.addFilter("sensitiveURL");
        sdkbox.PluginApteligent.addFilter("additionalURL");

        // sdkbox.PluginApteligent.LoggingLevel.Silent
        // sdkbox.PluginApteligent.LoggingLevel.Error
        // sdkbox.PluginApteligent.LoggingLevel.Warning
        sdkbox.PluginApteligent.setLoggingLevel(sdkbox.PluginApteligent.LoggingLevel.Info);
        sdkbox.PluginApteligent.setAsyncBreadcrumbMode(true);
        sdkbox.PluginApteligent.updateLocation(30.67, 104.06);

        sdkbox.PluginApteligent.setUsername("MrsCritter");
        sdkbox.PluginApteligent.setValueforKey("5", "Game Level");

        sdkbox.PluginApteligent.leaveBreadcrumb("User tapped start button");

        // flow test
        cc.log("begin user flow: login");
        sdkbox.PluginApteligent.beginUserflow("login");
        const v = Math.floor(Math.random()*99) + 10;
        if (v > 50) {
            cc.log("end user flow: login");
            sdkbox.PluginApteligent.setValueforUserflow(Math.floor(Math.random()*10) + 1, "login");
            const value = sdkbox.PluginApteligent.valueForUserflow("login");
            sdkbox.PluginApteligent.setValueforUserflow(value+5, "login");
            sdkbox.PluginApteligent.endUserflow("login");
        } else if (v > 30) {
            cc.log("fail user flow: login");
            sdkbox.PluginApteligent.failUserflow("login");
        } else {
            cc.log("cancel user flow: login");
            sdkbox.PluginApteligent.cancelUserflow("login");
        }

        // logging network requests
        sdkbox.PluginApteligent.logNetworkRequest("GET", "http://www.abc123def456.com", 2.0, 1000, 100, 200);

    },

    onButton1: function() {
        this.log('button 1 clicked');
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
