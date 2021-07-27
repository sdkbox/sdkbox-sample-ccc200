window.__require = function o(n, e, i) {
function t(l, r) {
if (!e[l]) {
if (!n[l]) {
var u = l.split("/");
u = u[u.length - 1];
if (!n[u]) {
var c = "function" == typeof __require && __require;
if (!r && c) return c(u, !0);
if (s) return s(u, !0);
throw new Error("Cannot find module '" + l + "'");
}
l = u;
}
var g = e[l] = {
exports: {}
};
n[l][0].call(g.exports, function(o) {
return t(n[l][1][o] || o);
}, g, g.exports, o, n, e, i);
}
return e[l].exports;
}
for (var s = "function" == typeof __require && __require, l = 0; l < i.length; l++) t(i[l]);
return t;
}({
HelloWorld: [ function(o, n) {
"use strict";
cc._RF.push(n, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
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
this.initPluginFacebook();
},
initPluginFacebook: function() {
if ("undefined" != typeof sdkbox) if ("undefined" != typeof sdkbox.PluginFacebook) {
var o = this;
sdkbox.PluginFacebook.setListener({
onLogin: function(n) {
n ? o.log("login successful") : o.log("login failed");
},
onAPI: function(n, e) {
o.log("onAPI t:" + n);
if ("me" == n) {
var i = JSON.parse(e);
o.log("onAPI Name:" + i.name);
}
},
onSharedSuccess: function() {
o.log("share successful");
},
onSharedFailed: function() {
o.log("share failed");
},
onSharedCancel: function() {
o.log("share canceled");
},
onPermission: function(n) {
n ? o.log("request permission successful") : o.log("request permission failed");
},
onFetchFriends: function(n, e) {
o.log(n + ":" + e, "onFetchFriends");
},
onRequestInvitableFriends: function(n) {
o.log(JSON.stringify(n));
},
onInviteFriendsWithInviteIdsResult: function(n, e) {
o.log("onInviteFriendsWithInviteIdsResult result=" + (n ? "ok" : "error") + " " + e);
},
onInviteFriendsResult: function(n, e) {
o.log("onInviteFriendsResult result=" + (n ? "ok" : "error") + " " + e);
}
});
sdkbox.PluginFacebook.init();
} else this.log("sdkbox.PluginFacebook is undefined"); else this.log("sdkbox is undefined");
},
onButton1: function() {
if (sdkbox.PluginFacebook.isLoggedIn()) {
this.log("FB to Logout");
sdkbox.PluginFacebook.logout();
} else {
this.log("FB to Login");
sdkbox.PluginFacebook.login([ "public_profile" ]);
}
},
onButton2: function() {
var o = sdkbox.PluginFacebook.getPermissionList();
this.log("FB permission:" + o);
cc.log("FB token:" + sdkbox.PluginFacebook.getAccessToken());
this.log("FB UserID:" + sdkbox.PluginFacebook.getUserID());
this.log("FB SDK Ver:" + sdkbox.PluginFacebook.getSDKVersion());
sdkbox.PluginFacebook.api("me", "GET", [ "first_name" ], "me");
},
log: function(o) {
cc.log(o);
for (var n = this.logs.string.split("\n"); n.length > 5; ) n.shift();
n.push(o);
this.logs.string = n.join("\n");
},
update: function() {}
});
cc._RF.pop();
}, {} ]
}, {}, [ "HelloWorld" ]);