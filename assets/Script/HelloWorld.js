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
        this.initPluginHMS();
    },

    initPluginHMS: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginHMS) {
            this.log('sdkbox.PluginHMS is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginHMS.setListener({
            onLogin: function(code, msg) {
                self.log('HMS Listener onLogin:' + code + ' ' + msg);
            },
        });
        sdkbox.PluginHMS.init();
    },

    onButton1: function() {
        // const loginType = 0; //slient login
        const loginType = 1; //idtoken login
        // const loginType = 2; //authcode login

        this.log('to login with type:' + loginType);
        sdkbox.PluginHMS.login(loginType);
    },

    onButton2: function() {
        this.log('to logout');
        sdkbox.PluginHMS.logout();
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
