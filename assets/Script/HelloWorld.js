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
        this.initSignInWithApple();
    },

    initSignInWithApple: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginSignInWithApple) {
            this.log('sdkbox.PluginSignInWithApple is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginSignInWithApple.setListener({
            onAuthorizationDidComplete: function(authInfo) {
                const s = 'onAuthorizationDidComplete:' + authInfo;
                self.log(s);
            },
            onAuthorizationCompleteWithError: function(authInfo) {
                const s = 'onAuthorizationCompleteWithError:' + authInfo;
                self.log(s);
            },
            onAuthorizationStatus: function(authState) {
                const s = 'onAuthorizationStatus:' + authState;
                self.log(s);
            },
        });
        sdkbox.PluginSignInWithApple.init();
        sdkbox.PluginSignInWithApple.signWithExistingAccount();
    },

    onButton1: function() {
        this.log('to Sign In with Apple ...');
        sdkbox.PluginSignInWithApple.sign();
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
