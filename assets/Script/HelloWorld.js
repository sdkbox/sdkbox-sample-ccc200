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
        this.initPluginYoutube();
    },

    initPluginYoutube: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginYoutube) {
            this.log('sdkbox.PluginYoutube is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginYoutube.setListener({
            onPlayEnds: function(ok) {
                self.log("onPlayEnds:" + ok);
            }
        });
        sdkbox.PluginYoutube.init();

    },

    onButton1: function() {
        sdkbox.PluginYoutube.playVideo("GrP3jHuLQ9o", 0, true, true);
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
