declare module sdkbox {     module MiscListener {        /**        * Notifies the delegate that user tap the notify        */        export function onHandleLocalNotify(payloadJson : string) : object;
    }     module PluginMisc {        /**        * Set GDPR        *        * **NOTE**: please call before 'init' function        */        export function setGDPR(enabled : boolean) : object;
        /**        *  initialize the plugin instance.        */        export function init() : boolean;
        /**        * Set listener to listen for misc events        */        export function setListener(listener : object) : object;
        /**        * Get the listener        */        export function getListener() : object;
        /**        * Remove the listener, and can't listen to events anymore        */        export function removeListener() : object;
        /**        * Local Notification        *        * title: notification title, just valid on android        * content: notification content        * delayMillisecond: delay millisecond to notify        *        * return notifyID        */        export function localNotify(title : string , content : string , delayMillisecond : number) : number;
        /**        * Clear Local Notification        *        * notificationID: notification id, 0: will cancel all local notify        */        export function cleanLocalNotify(notifyID : number) : object;
        /**        * Handle Local Notification, just For iOS        *        * on Android, please use com.sdkbox.plugin.PluginMisc.onHandleNotification(intent);        *        */        export function handleLocalNotify(notificationUserInfo : string) : object;
        /**        * get current platform, iOS or Android        *        */        export function getPlatformName() : string;
        /**        * just valid on android, can get meta data from AndroidManifest.xml        *        */        export function getMetaData(name : string) : string;
        /**        * get current iap provider of SDKBox IAP        * return 'Apple', 'Google', 'Amazon' or 'Playphone'        */        export function getIAPProvider() : string;
        /**        * get app version        *        */        export function getAppVersion() : string;
        /**        * get iOS app build version        *        */        export function getAppBuildVersion() : string;
        /**        * get android app version code        *        */        export function getAppVersionCode() : number;
        /**        * get device info        */        export function getDeviceInfo() : string;
        /*** Keychain is valid on iOS  ***//**        * set keychain service        */        export function setKeychainService(service : string) : object;
        /**        * set keychain accessgroup        */        export function setKeychainAccessGroup(group : string) : object;
        /**        * store account data in keychain, if exist will update it        * return SecurityFrameworkResultCode: https://developer.apple.com/documentation/security/1542001-security_framework_result_codes        */        export function storeStringInKeychain(account : string , value : string) : number;
        /**        * fetch account data from keychain        */        export function fetchStringInKeychain(account : string) : string;
        /**        * remove account in keychain        */        export function removeDataInKeychain(account : string) : number;
    }}