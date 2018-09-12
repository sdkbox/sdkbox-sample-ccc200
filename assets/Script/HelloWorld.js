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
        this.initPluginShare();
    },

    initPluginShare: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginShare) {
            this.log('sdkbox.PluginShare is undefined');
            return;
        }

        const self = this;
        sdkbox.PluginShare.setListener({
            onShareState: function(response) {
                let str = 'onSharestate:';
                switch(response.platform) {
                    case sdkbox.SocialPlatform.Platform_Unknow: { str += "unknow"; break; }
                    case sdkbox.SocialPlatform.Platform_Twitter: { str += "twitter"; break; }
                    case sdkbox.SocialPlatform.Platform_Facebook: { str += "facebook"; break; }
                    case sdkbox.SocialPlatform.Platform_SMS: { str += "sms"; break; }
                    case sdkbox.SocialPlatform.Platform_Mail: { str += "mail"; break; }
                    case sdkbox.SocialPlatform.Platform_Native: { str += "native"; break; }
                    case sdkbox.SocialPlatform.Platform_Select: { str += "select"; break; }
                    case sdkbox.SocialPlatform.Platform_All: { str += "all"; break; }
                    default: { str += response.platform; break; }
                }

                str += ':';
                switch (response.state) {
                    case sdkbox.SocialShareState.SocialShareStateNone: { str += "none"; break; }
                    case sdkbox.SocialShareState.SocialShareStateUnkonw: { str += "unknow"; break; }
                    case sdkbox.SocialShareState.SocialShareStateBegin: { str += "begin"; break; }
                    case sdkbox.SocialShareState.SocialShareStateSuccess: { str += "success"; break; }
                    case sdkbox.SocialShareState.SocialShareStateFail: { str += "failed"; break; }
                    case sdkbox.SocialShareState.SocialShareStateCancelled: { str += "cancel"; break; }
                    case sdkbox.SocialShareStateSelectShow: { str += "select show"; break; }
                    case sdkbox.SocialShareStateSelectCancelled: { str += "select cancel"; break; }
                    case sdkbox.SocialShareStateSelected: { str += "selected"; break; }
                    default: { str += response.state; break; }
                }

                str += ':';
                str += response.error;
                self.log(str);
            }
        });
        sdkbox.PluginShare.init();
    },

    onButton1: function() {
        const shareInfo = {};
        shareInfo.text = "#sdkbox(www.sdkbox.com) - the cure for sdk fatigue - from js - " + this.generateRandomStr();
        shareInfo.title = "sdkbox";
        //shareInfo.image = "path to image path"
        shareInfo.link = "http://www.sdkbox.com";
        shareInfo.platform = sdkbox.SocialPlatform.Platform_Select;
        shareInfo.showDialog = false;
        sdkbox.PluginShare.share(shareInfo);
    },

    onButton2: function() {
        const shareInfo = {};
        shareInfo.title = "title";
        shareInfo.text = "text";
        shareInfo.image = "button.png";
        shareInfo.link = "www.sdkbox.com";
        sdkbox.PluginShare.nativeShare(shareInfo);
    },

    generateRandomStr: function() {
        const alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z'];

        const max = Math.floor(Math.random()*5) + 5; //generate [5, 10)
        let str = '';
        for (let i = 0; i < max; i++) {
            str += alphabet[Math.floor(Math.random()*26)]
        }

        return str;
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
