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
        this.initPluginReview();
    },

    initPluginReview: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginReview) {
            this.log('sdkbox.PluginReview is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginReview.setListener({
            onDisplayAlert: function(data) {
                self.log("didDisplayAlert");
            },
            onDeclineToRate: function(data) {
                self.log("didDeclineToRate");
            },
            onRate: function(data) {
                self.log("didToRate");
            },
            onRemindLater: function(data) {
                self.log("didToRemindLater");
            }
        });
        sdkbox.PluginReview.init();

    },

    onButton1: function() {
        sdkbox.PluginReview.rate();
    },

    onButton2: function() {
        sdkbox.PluginReview.show(true /* force */);
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
