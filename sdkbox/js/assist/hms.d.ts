declare module sdkbox {     module PluginHMS {        /**        * Set GDPR        *        * **NOTE**: please call before 'init' function        */        export function setGDPR(enabled : boolean) : object;
        /**        *  initialize the plugin instance.        */        export function init() : boolean;
        /**        * Set listener to listen for adcolony events        */        export function setListener(listener : object) : object;
        /**        * Get the listener        */        export function getListener() : object;
        /**        * Remove the listener, and can't listen to events anymore        */        export function removeListener() : object;
        /**        * HMS provider three way to login        * loginType: 0, slient login 1, login with HuaweiID(ID Token) 2, login with HuaweID(Authorization Code)        *        * slient login should invoke after `login with HuaweiID`(loginType 2 or 3) have success        *        * will trigger `onLogin` event. and the msg paramater will include account info when login success        *        */        export function login(loginType : number) : object;
        /**        * logout HMS        */        export function logout() : object;
    }     module HMSListener {        export function onLogin(code : number , msg : string) : object;
    }}