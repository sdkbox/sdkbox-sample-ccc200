window.__require = function e(i, t, n) {
function r(s, a) {
if (!t[s]) {
if (!i[s]) {
var l = s.split("/");
l = l[l.length - 1];
if (!i[l]) {
var f = "function" == typeof __require && __require;
if (!a && f) return f(l, !0);
if (o) return o(l, !0);
throw new Error("Cannot find module '" + s + "'");
}
}
var c = t[s] = {
exports: {}
};
i[s][0].call(c.exports, function(e) {
return r(i[s][1][e] || e);
}, c, c.exports, e, i, t, n);
}
return t[s].exports;
}
for (var o = "function" == typeof __require && __require, s = 0; s < n.length; s++) r(n[s]);
return r;
}({
HelloWorld: [ function(e, i, t) {
"use strict";
cc._RF.push(i, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
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
this.initPluginFirebase();
},
initPluginFirebase: function() {
"undefined" != typeof sdkbox ? "undefined" != typeof sdkbox.firebase ? sdkbox.firebase.Analytics.init() : this.log("sdkbox.firebase is undefined") : this.log("sdkbox is undefined");
},
onButton1: function() {
var e = {};
e[sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = "id123456";
e[sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = "name123456";
e[sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = "category123456";
e[sdkbox.firebase.Analytics.Param.kFIRParameterPrice] = "123.4";
sdkbox.firebase.Analytics.logEvent(sdkbox.firebase.Analytics.Event.kFIREventViewItem, e);
},
log: function(e) {
cc.log(e);
var i = this.logs.string.split("\n");
cc.log(i);
for (;i.length > 5; ) i.shift();
i.push(e);
this.logs.string = i.join("\n");
},
update: function(e) {}
});
cc._RF.pop();
}, {} ]
}, {}, [ "HelloWorld" ]);