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
        this.initPluginHMS();
    },

    initPluginHMS: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.PluginHMS) {
            this.log('sdkbox.PluginHMS is undefined');
            return;
        }

        const self = this;
        const listener = {
            onLogin: function(code, msg) {
                self.log('HMS Listener onLogin:' + code);
                cc.log(msg);
            },
            onIAPReady: function(code, msg) {
                self.log('HMS Listener onIAPReady:' + code);
                cc.log(msg);
            },
            onIAPProducts: function(code, msg) {
                self.log('HMS Listener onIAPProducts:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                self.hmsProducts = rst.products;
            },
            onIAPPurchase: function(code, msg) {
                self.log('HMS Listener onIAPPurchase:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                const iapData = rst["inAppPurchaseData"];
                const iapSignature = rst["inAppDataSignature"];

                const iapDataJson = JSON.parse(iapData);
                const pToken = iapDataJson["purchaseToken"];
                const pId = iapDataJson["productId"];

                self.log('Purchase ID:PurchaseToken' + pId + ":" + pToken);

                if (self.isConsumable(pId)) {
                    self.addPurchaseToken(pToken);
                } else {
                    // purchase success delivery product to player
                    self.log('Purchase Success, delivery ' + pId + " to player");
                }
            },
            onIAPPConsume: function(code, msg) {
                self.log('HMS Listener onIAPPConsume:' + code);
                cc.log(msg);

                if (0 == code) {
                    // consume success, delivery this consumable to player
                    self.log('Purchase Success, delivery to player');
                }
            },
            onIAPOwnedPurchases: function(code, msg) {
                self.log('HMS Listener onIAPOwnedPurchases:' + code);
                cc.log(msg);

                if (0 != code) {
                    return;
                }
                const rst = JSON.parse(msg);
                rst['ownedPurchases'].forEach(purchaseInfo => {
                    const purchase = JSON.parse(purchaseInfo.inAppPurchaseData);
                    const pToken = purchase["purchaseToken"];
                    const pId = purchase["productId"];
 
                    cc.log(pId);
                    cc.log(pToken);
                    if (self.isConsumable(pId)) {
                        self.addPurchaseToken(pToken);
                    }
                });
            },
            onIAPOwnedPurchaseRecords: function(code, msg) {
                self.log('HMS Listener onIAPOwnedPurchaseRecords:' + code);
                cc.log(msg);
            }
        };

        sdkbox.PluginHMS.setListener(listener);
        sdkbox.PluginHMS.init();
    },

    onButton1: function() {
        // const loginType = 0; //slient login
        const loginType = 1; //idtoken login
        // const loginType = 2; //authcode login

        this.log('to login with type:' + loginType);
        sdkbox.PluginHMS.login(loginType);
    },

    onButton2: function() {
        this.log('to logout');
        sdkbox.PluginHMS.logout();
    },

    onButton3: function() {
        this.log('to request products');
        sdkbox.PluginHMS.iapRequestProducts();
    },

    onButton4: function() {
        this.log('to purchase');
        const productName = "coin";
        // const productName = "remove_ads";
        // const productName = "vip";
        sdkbox.PluginHMS.iapPurchase(productName);
    },

    onButton5: function() {
        this.log('to purchase with price');
        const productInfo = {
            productName: "Unmanaged0",
            productId: "com.sdkbox.unmanaged.consumable1",
            priceType: 0, // 0: consumable 1: non-consumable 2: subscription
            amount: "1.99",
            currency: "CNY",
            country: "CN",
            sdkChannel: "1", // length must between 0, 4
            serviceCatalog: "X38",
            reservedInfor:  "{'a':1,'b':'s'}", // must be json string
            developerPayload: "payload1"
        };
        sdkbox.PluginHMS.iapPurchaseWithPrice(JSON.stringify(productInfo));
    },

    onButton6: function() {
        if (!this.purchaseTokens || 0 == this.purchaseTokens.length) {
            this.log('no consumable product')
            return;
        }
        this.log('to consume');
        const purchaseToken = this.purchaseTokens.shift();
        sdkbox.PluginHMS.iapConsume(purchaseToken);
    },

    onButton7: function() {
        this.log('to request owned purchase');
        sdkbox.PluginHMS.iapRequestOwnedPurchases();
    },

    onButton8: function() {
        this.log('to request owned purchase record');
        sdkbox.PluginHMS.iapRequestOwnedPurchaseRecords();
    },

    isConsumable: function(productId) {
        if (!this.hmsProducts) {
            return false;
        }
        for (let i = 0; i < this.hmsProducts.length; i++) {
            const product = this.hmsProducts[i];
            if (product.productId === productId) {
                if (product.type === 'consumable') {
                    return true;
                }
            }
        }

        if (productId == 'com.sdkbox.unmanaged.consumable1') {
            // this is unmanaged product
            return true;
        }

        return false;
    },

    addPurchaseToken: function(purchaseToken) {
        if (!this.purchaseTokens) {
            this.purchaseTokens = [];
        }
        this.purchaseTokens.push(purchaseToken);
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
