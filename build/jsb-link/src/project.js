__require = function e(r, t, o) {
function n(l, c) {
if (!t[l]) {
if (!r[l]) {
var u = l.split("/");
u = u[u.length - 1];
if (!r[u]) {
var s = "function" == typeof __require && __require;
if (!c && s) return s(u, !0);
if (i) return i(u, !0);
throw new Error("Cannot find module '" + l + "'");
}
}
var f = t[l] = {
exports: {}
};
r[l][0].call(f.exports, function(e) {
return n(r[l][1][e] || e);
}, f, f.exports, e, r, t, o);
}
return t[l].exports;
}
for (var i = "function" == typeof __require && __require, l = 0; l < o.length; l++) n(o[l]);
return n;
}({
HelloWorld: [ function(e, r, t) {
"use strict";
cc._RF.push(r, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
cc.Class({
extends: cc.Component,
properties: {
label: {
default: null,
type: cc.Label
},
text: "Hello, World!"
},
onLoad: function() {
this.label.string = this.text;
if (cc.sys.isMobile) {
console.log("===== SDKBOX TEST ====");
sdkbox.PluginFacebook.init();
}
},
update: function(e) {}
});
cc._RF.pop();
}, {} ]
}, {}, [ "HelloWorld" ]);