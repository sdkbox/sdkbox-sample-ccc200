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
        this.initPluginMisc();
    },

    initPluginMisc: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginMisc) {
            this.log('sdkbox.PluginMisc is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginMisc.setListener({
            onHandleLocalNotify :function (json) {
                self.log("onHandleLocalNotify");
                cc.log(json);
            }
        });
        sdkbox.PluginMisc.init();

        this.log("Platform:" + sdkbox.PluginMisc.getPlatformName());
        const metaName = "store";
        this.log("MetaData: " + metaName + " -> " + sdkbox.PluginMisc.getMetaData(metaName));
        this.log("IAP Provider:" + sdkbox.PluginMisc.getIAPProvider());
        this.log("App Version:" + sdkbox.PluginMisc.getAppVersion());
        this.log("App Build Version:" + sdkbox.PluginMisc.getAppBuildVersion());
        this.log("App Version Code:" + sdkbox.PluginMisc.getAppVersionCode());
        this.log("DeviceInfo:" + sdkbox.PluginMisc.getDeviceInfo());

    },

    onButton1: function() {
        let nid = sdkbox.PluginMisc.localNotify("test title", "this a test notify content", 1000 * 10);
        this.log('Local Notification ID:' + nid);
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
