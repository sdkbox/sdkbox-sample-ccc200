package org.cocos2dx.javascript;

import android.app.Application;

public class CocosApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        com.sdkbox.plugin.PluginHMS.ApplicationInit(this);
    }
}
