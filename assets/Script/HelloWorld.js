cc.Class({
    extends: cc.Component,

    properties: {
        logs: {
            default: null,
            type: cc.Label
        },
        camera: {
            default: null,
            type: cc.Camera
        },
        // defaults, set visually when attaching this script to the Canvas
        text: 'Hello, World!'
    },

    captureScreen: function (captureScreenFilePath) {
        const filpYImage = function (data, width, height) {
            // create the data array
            let picData = new Uint8Array(width * height * 4);
            let rowBytes = width * 4;
            for (let row = 0; row < height; row++) {
                let srow = height - 1 - row;
                let start = srow * width * 4;
                let reStart = row * width * 4;
                // save the piexls data
                for (let i = 0; i < rowBytes; i++) {
                    picData[reStart + i] = data[start + i];
                }
            }
            return picData;
        }

        const width = cc.visibleRect.width;
        const height = cc.visibleRect.height;
        let texture = new cc.RenderTexture();
        texture.initWithSize(width, height);
        const backupRenderer = this.camera.targetTexture;
        this.camera.targetTexture = texture;
        this.camera.render();
        this.camera.targetTexture = backupRenderer;
        let picData = texture.readPixels();
        // picData = filpYImage(picData, width, height);

        let success = false;
        if (jsb.saveImageData) {
            success = jsb.saveImageData(picData, width, height, captureScreenFilePath);
        }

        return success;
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
        sdkbox.PluginShare.setFileProviderAuthorities("com.sdkbox.test.app.fileprovider");

        const shareInfo = {};
        shareInfo.title = "title";
        shareInfo.text = "text";
        shareInfo.image = this.captureScreenFilePath;
        shareInfo.link = "www.sdkbox.com";
        sdkbox.PluginShare.nativeShare(shareInfo);
    },

    onButton3: function() {
        this.captureScreenFilePath = jsb.fileUtils.getWritablePath() + "capturetest.png";
        this.captureScreenFilePath = "/mnt/sdcard/screenshot.png";
        if (this.captureScreen(this.captureScreenFilePath)) {
            cc.log("save image data success, file: " + this.captureScreenFilePath);
        } else {
            this.captureScreenFilePath = null;
            cc.error("save image data failed!");
        }
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
