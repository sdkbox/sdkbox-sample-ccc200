const sdkbox_config = require('../SDKBox/sdkbox_config')

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
        this.initIAP();
    },

    initIAP: function() {
        if ('undefined' == typeof sdkbox) {
            this.log('sdkbox is undefined');
            return;
        }

        if ('undefined' == typeof sdkbox.IAP) {
            this.log('sdkbox.IAP is undefined');
            return;
        }

        if (sdkbox.setConfig) {
            sdkbox.setConfig(JSON.stringify(sdkbox_config));
        }

        const self = this;
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
                self.log("Purchase successful: " + product.name);
                self.printProduct(product);
            },
            onFailure : function (product, msg) {
                //Purchase failed
                //msg is the error message
                self.log("Purchase failed: " + product.name + " error: " + msg);

            },
            onCanceled : function (product) {
                //Purchase was canceled by user
                self.log("Purchase canceled: " + product.name);
            },
            onRestored : function (product) {
                //Purchase restored
                self.log("Restored: " + product.name);

                self.printProduct(product);
            },
            onProductRequestSuccess : function (products) {
                //Returns you the data for all the iap products
                //You can get each item using following method
                for (var i = 0; i < products.length; i++) {
                    self.printProduct(products[i]);
                    // self.log("================");
                    // self.log("name: " + products[i].name);
                    // self.log("price: " + products[i].price);
                    // self.log("priceValue: " + products[i].priceValue);
                    // self.log("================");
                }
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
                self.log("Failed to get products");
            },
            onShouldAddStorePayment: function(productId) {
                self.log("onShouldAddStorePayment:" + productId);
                return true;
            },
            onFetchStorePromotionOrder : function (productIds, error) {
                self.log("onFetchStorePromotionOrder:" + " " + " e:" + error);
            },
            onFetchStorePromotionVisibility : function (productId, visibility, error) {
                self.log("onFetchStorePromotionVisibility:" + productId + " v:" + visibility + " e:" + error);
            },
            onUpdateStorePromotionOrder : function (error) {
                self.log("onUpdateStorePromotionOrder:" + error);
            },
            onUpdateStorePromotionVisibility : function (error) {
                self.log("onUpdateStorePromotionVisibility:" + error);
            },
        });
        sdkbox.IAP.init();
        // sdkbox.IAP.setAutoFinishTransaction(false);
        sdkbox.IAP.setDebug(true);
    },

    onButton1: function() {
        sdkbox.IAP.refresh();
    },

    onButton2: function() {
        sdkbox.IAP.purchase("coin_package");
    },

    onButton3: function() {
        sdkbox.IAP.requestUpdateTransaction();
    },

    printProduct: function(p) {
        // this.log("======The product info======");

        this.log(p.name + ":" + p.price);

        // this.log("name=" + p.name);
        // this.log("title=" + p.title);
        // this.log("description=" + p.description);
        // this.log("price=" + p.price);
        // this.log("priceValue=" + p.priceValue);
        // this.log("currencyCode=" + p.currencyCode);
        // this.log("receipt=" + p.receipt);
        // this.log("receiptCipheredPayload=" + p.receiptCipheredPayload);
        // this.log("transactionID=" + p.transactionID);
        // this.log("");
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
