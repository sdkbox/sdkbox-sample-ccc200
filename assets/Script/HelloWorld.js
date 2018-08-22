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
        this.label.string = this.text;

        if (cc.sys.isMobile) {
            console.log("===== SDKBOX TEST ====");
            sdkbox.PluginFacebook.init();
        }
    },

    // called every frame
    update: function (dt) {

    },
});
