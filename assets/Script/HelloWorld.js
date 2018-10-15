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
        this.initPluginFacebook();
    },

    initPluginFacebook: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginFacebook) {
            this.log('sdkbox.PluginFacebook is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginFacebook.setListener({
            onLogin: function(isLogin, msg) {
              if(isLogin){
                self.log("login successful");
              } else {
                self.log("login failed");
              }
            },
            onAPI: function(tag, data) {
                self.log(`onAPI t:${tag}`);
                if (tag == "me") {
                    const obj = JSON.parse(data);
                    self.log('onAPI Name:' + obj.name);
                // } else if (tag == "/me/friendlists") {
                //     var obj = JSON.parse(data);
                //     var friends = obj.data;
                //     for (var i = 0; i < friends.length; i++) {
                //     self.log("id %s", friends[i].id);
                //     }
                // } else if (tag == "__fetch_picture_tag__") {
                //     var obj = JSON.parse(data);
                //     var url = obj.data.url;
                //     self.log("get friend's profile picture=%s", url);
                }
            },
            onSharedSuccess: function(data) {
                self.log("share successful");
            },
            onSharedFailed: function(data) {
                self.log("share failed");
            },
            onSharedCancel: function() {
                self.log("share canceled");
            },
            onPermission: function(isLogin, msg) {
                if(isLogin) {
                    self.log("request permission successful");
                }
                else {
                    self.log("request permission failed");
                }
            },
            onFetchFriends: function(ok, msg) {
                self.log(ok + ":"+msg, "onFetchFriends");
            },
            onRequestInvitableFriends: function(friendsData) {
                self.log(JSON.stringify(friendsData));
            },
            onInviteFriendsWithInviteIdsResult: function (result, description) {
                self.log("onInviteFriendsWithInviteIdsResult result=" + (result?"ok":"error") + " " + description);
            },
            onInviteFriendsResult: function (result, description) {
                self.log("onInviteFriendsResult result=" + (result?"ok":"error") + " " + description);
            }
        });
        sdkbox.PluginFacebook.init();
    },

    onButton1: function() {
        if (sdkbox.PluginFacebook.isLoggedIn()) {
            this.log("FB to Logout");
            sdkbox.PluginFacebook.logout();
        } else {
            this.log("FB to Login");
            sdkbox.PluginFacebook.login(['public_profile']);
        }
    },

    onButton2: function() {
        const permission = sdkbox.PluginFacebook.getPermissionList();
        this.log('FB permission:' + permission);
        cc.log("FB token:" + sdkbox.PluginFacebook.getAccessToken());
        this.log("FB UserID:" + sdkbox.PluginFacebook.getUserID());
        this.log("FB SDK Ver:" + sdkbox.PluginFacebook.getSDKVersion());

        sdkbox.PluginFacebook.api("me", "GET", ['first_name'], "me");
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
