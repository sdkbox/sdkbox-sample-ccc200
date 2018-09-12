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
        this.initPluginFirebase();
    },

    initPluginFirebase: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.firebase) {
            this.log('sdkbox.firebase is undefined');
            return;
        }

        sdkbox.firebase.Analytics.init();
    },

    onButton1: function() {
        const evt = {}
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456';
        evt[sdkbox.firebase.Analytics.Param.kFIRParameterPrice] = '123.4';

        // log event
        sdkbox.firebase.Analytics.logEvent(sdkbox.firebase.Analytics.Event.kFIREventViewItem, evt);

        // log custom event
        // evt['customKey'] = 'custom value';
        // sdkbox.firebase.Analytics.logEvent("customEvent", evt);

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
