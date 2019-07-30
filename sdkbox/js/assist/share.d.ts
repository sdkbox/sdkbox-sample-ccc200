declare module sdkbox {     module ShareListener {        /**        * Notifies the delegate that share completion        */        export function onShareState(response : object) : object;
    }     module PluginShare {        /**        * Set GDPR        *        * **NOTE**: please call before 'init' function        */        export function setGDPR(enabled : boolean) : object;
        /*** ENUM CHANGE ****//**        *  initialize the plugin instance.        */        export function init(jsonConfig : object) : boolean;
        /**        * Set listener to listen for share events        */        export function setListener(listener : object) : object;
        /**        * Get the listener        */        export function getListener() : object;
        /**        * Remove the listener, and can't listen to events anymore        */        export function removeListener() : object;
        /**        * set custome share platform choose panel title, default is "Share to"        */        export function setSharePanelTitle(s : string) : object;
        /**        * set custome share platform choose panel cancel button, default is "Cancel"        */        export function setSharePanelCancel(s : string) : object;
        /**        * Share content        */        export function share(info : object) : object;
        /**        * will use ios/android system share panel        *        * IOS:        * when trigger share success event, action name will pass by error in sdkbox::SocialShareResponse        *        * Android:        * share success event will trigger, but this is not real share success, just show share panel success        * can't get real share success event on android        *        */        export function nativeShare(info : object) : object;
        export function logoutTwitter() : object;
        export function setFileProviderAuthorities(authority : string) : object;
    }}