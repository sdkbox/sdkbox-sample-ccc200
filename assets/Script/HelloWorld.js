cc.Class({
    extends: cc.Component,

    properties: {
        label: {
            default: null,
            type: cc.Label
        },
        // defaults, set visually when attaching this script to the Canvas
        // text: 'Hello, World!'
    },

    // use this for initialization
    onLoad: function () {
        // this.label.string = this.text;
        this.initPlugin();
    },

    // called every frame
    update: function (dt) {

    },

    initPlugin: function() {
        this.initPluginGPG();
    },

    initPluginGPG: function() {
        if ('undefined' == typeof gpg) {
            this.log('gpg is undefined');
            return;
        }

        const config = new gpg.PlatformConfiguration();
        config.SetClientID('777734739048-cdkbeieil19d6pfkavddrri5o19gk4ni.apps.googleusercontent.com');

        const l = 1;
        this.gameServices = null;
        this.signIn = false;
        const self = this;
        new gpg.GameServices.Builder()
            .SetOnAuthActionStarted (
                function(result) {
                    self.log('GPG on auth action start');
                }
            ).SetOnAuthActionFinished (
                function(result) {
                    self.log('GPG on auth action finished: ' + result.AuthOperation + ' ' + result.AuthStatus);
                    self.signIn = gpg.IsSuccess(result.AuthStatus);
                    self.log('GPG signed in:' + self.signIn);
                }
            ).SetOnMultiplayerInvitationEvent(
                function(result) {
                    self.log('GPG on multiplayer invitation');
                }
            ).SetLogging(gpg.LogLevel.INFO)
            .EnableSnapshots()
            .Create(
                function(gs) {
                    if (gs) {
                        self.gameServices = gs;
                        self.log('GPG game services connect');
                    } else {
                        self.log('GPG game services not connect')
                    }
                }, config);
    },

    onButton1: function() {
        if (null == this.gameServices) {
            cc.log('GPG game services is null');
            return;
        }
        if (this.signIn) {
            cc.log('GPG to sign out ...');
            this.gameServices.SignOut();
        } else {
            cc.log('GPG to sign in ...');
            this.gameServices.StartAuthorizationUI();
        }
    },

    log: function(s) {
        cc.log(s);
    }

});
