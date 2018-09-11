cc.Class({
    extends: cc.Component,

    properties: {
        label: {
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
        this.initPluginName();
    },

    initPluginName: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginName) {
            this.log('sdkbox.PluginName is undefined');
            return;
        }

        sdkbox.PluginName.init();
    },

    onButton1: function() {
        this.log('button 1 clicked');
    },

    log: function(s) {
        cc.log(s);
    },

    // called every frame
    update: function (dt) {
    },
});
