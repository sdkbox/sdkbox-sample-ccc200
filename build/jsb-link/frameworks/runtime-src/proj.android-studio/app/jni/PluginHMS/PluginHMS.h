/****************************************************************************

 Copyright (c) 2014-2020 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_HMS_H_
#define _PLUGIN_HMS_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
    class HMSListener {
    public:

        /*
         * login callback
         * code: 0, success; !=0, failed
         */
        virtual void onLogin(int code, const std::string& msg) = 0;

        /*
         * callback for hws iap env check
         */
        virtual void onIAPReady(int code, const std::string& msg) = 0;

        /*
         * callback for iapRequestProducts
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPProducts(int code, const std::string& errorOrJson) = 0;

        /*
         * callback for iapPurchase
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPPurchase(int code, const std::string& errorOrJson) = 0;

        /*
         * callback for iapConsume
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPPConsume(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for iapRequestOwnedPurchases
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPOwnedPurchases(int code, const std::string& errorOrJson) {};
        
        /*
         * callback for iapRequestOwnedPurchaseRecords
         * errorOrJson: products json if code == 0, error msg if code != 0
         */
        virtual void onIAPOwnedPurchaseRecords(int code, const std::string& errorOrJson) {};
        
    };

    class PluginHMS {
    public:

        /**
         * Set GDPR
         *
         * **NOTE**: please call before 'init' function
         */
        static void setGDPR(bool enabled);

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(HMSListener* listener);

        /**
         * Get the listener
         */
        static HMSListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * HMS provider three way to login
         * loginType: 0, slient login 1, login with HuaweiID(ID Token) 2, login with HuaweID(Authorization Code)
         *
         * slient login should invoke after `login with HuaweiID`(loginType 2 or 3) have success
         *
         * will trigger `onLogin` event. and the msg paramater will include account info when login success
         *
         */
        static void login(int loginType);

        /**
         * logout HMS
         */
        static void logout();

        /*
         * request product list
         *
         * will trigger onIAPProducts
         */
        static void iapRequestProducts();
        
        /*
         * purchase managed product
         * name: product name
         *
         * will trigger onIAPPurchase
         */
        static void iapPurchase(const std::string& name);
        
        /*
         * purchase unmanaged product
         * productJson: product name info
         *
         * will trigger onIAPPurchase
         *
         * {
         * "priceType": 0, //0:consumable 1:non-consumable 2:subscription
         * "productName": "product name",
         * "productId": "product id",
         * "amount": "1.00",
         * "currency": "CNY",
         * "country": "CN",
         * "sdkChannel": "1", // sdkChannel size must be between 0 and 4
         * "serviceCatalog": "X58",
         * "reservedInfor": "{\"a\": 1, \"b\":\"s\"}", // reservedInfor must be json string
         * "developerPayload": "payload1"
         * }
         *
         * more info about purchase unmanaged product: https://developer.huawei.com/consumer/cn/doc/development/HMS-Guides/iap-development-guide-v4#h1-1576554485195
         */
        static void iapPurchaseWithPrice(const std::string& productJson);

        /*
         * request owned purchase
         *
         * will trigger onIAPOwnedPurchases
         */
        static void iapRequestOwnedPurchases();

        /*
         * consume consumable product
         *
         * will trigger onIAPPConsume
         */
        static void iapConsume(const std::string& purchaseToken);

        /*
         * request purchase records, include all purchase history
         *
         * will trigger onIAPOwnedPurchaseRecords
         */
        static void iapRequestOwnedPurchaseRecords();


    };
}

#endif
