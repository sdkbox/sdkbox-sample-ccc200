window.__require = function i(e, n, o) {
function t(s, r) {
if (!n[s]) {
if (!e[s]) {
var c = s.split("/");
c = c[c.length - 1];
if (!e[c]) {
var d = "function" == typeof __require && __require;
if (!r && d) return d(c, !0);
if (l) return l(c, !0);
throw new Error("Cannot find module '" + s + "'");
}
s = c;
}
var u = n[s] = {
exports: {}
};
e[s][0].call(u.exports, function(i) {
return t(e[s][1][i] || i);
}, u, u.exports, i, e, n, o);
}
return n[s].exports;
}
for (var l = "function" == typeof __require && __require, s = 0; s < o.length; s++) t(o[s]);
return t;
}({
HelloWorld: [ function(i, e) {
"use strict";
cc._RF.push(e, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
cc.Class({
extends: cc.Component,
properties: {
logs: {
default: null,
type: cc.Label
},
text: "Hello, World!"
},
onLoad: function() {
this.initPlugin();
},
initPlugin: function() {
this.initPluginAdMob();
},
initPluginAdMob: function() {
if ("undefined" != typeof sdkbox) if ("undefined" != typeof sdkbox.PluginAdMob) {
var i = this;
sdkbox.PluginAdMob.setListener({
adViewDidReceiveAd: function(e) {
i.log("adViewDidReceiveAd:" + e);
},
adViewDidFailToReceiveAdWithError: function(e, n) {
i.log("adViewDidFailToReceiveAdWithError:" + e + ":" + n);
},
adViewWillPresentScreen: function(e) {
i.log("adViewWillPresentScreen:" + e);
},
adViewDidDismissScreen: function(e) {
i.log("adViewDidDismissScreen:" + e);
},
adViewWillDismissScreen: function(e) {
i.log("adViewWillDismissScreen:" + e);
},
adViewWillLeaveApplication: function(e) {
i.log("adViewWillLeaveApplication:" + e);
},
reward: function(e, n, o) {
i.log("reward:" + e + ":" + n + ":" + o);
}
});
sdkbox.PluginAdMob.init();
} else this.log("sdkbox.PluginAdMob is undefined"); else this.log("sdkbox is undefined");
},
onButton1: function() {
var i = "interstitial";
if (sdkbox.PluginAdMob.isAvailable(i)) sdkbox.PluginAdMob.show(i); else {
this.log(i + " is not available");
sdkbox.PluginAdMob.cache(i);
}
},
onButton2: function() {
if (sdkbox.PluginAdMob.isAvailable("banner")) sdkbox.PluginAdMob.show("banner"); else {
this.log("banner is not available");
sdkbox.PluginAdMob.cache("banner");
}
},
log: function(i) {
cc.log(i);
for (var e = this.logs.string.split("\n"); e.length > 5; ) e.shift();
e.push(i);
this.logs.string = e.join("\n");
},
update: function() {}
});
cc._RF.pop();
}, {} ],
"use_v2.0.x_cc.Toggle_event": [ function(i, e) {
"use strict";
cc._RF.push(e, "ed6492GRpdKo5DVHu0gZQqG", "use_v2.0.x_cc.Toggle_event");
cc.Toggle && (cc.Toggle._triggerEventInScript_check = !0);
cc._RF.pop();
}, {} ]
}, {}, [ "HelloWorld", "use_v2.0.x_cc.Toggle_event" ]);