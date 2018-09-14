
#include "PluginChartboostJSHelper.h"
#include "PluginChartboost/PluginChartboost.h"
#include "SDKBoxJSHelper.h"

class ChartboostListenerJS : public sdkbox::ChartboostListener, public sdkbox::JSListenerBase
{
public:
    ChartboostListenerJS() : sdkbox::JSListenerBase() {
    }

    //Ad callbacks
    void onChartboostCached(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    bool onChartboostShouldDisplay(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
        return true;
    }
    void onChartboostDisplay(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostDismiss(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostClose(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostClick(const std::string& name) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostReward(const std::string& name, int reward) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value(reward));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value((int)e));
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e) {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        args.push_back(se::Value(name));
        args.push_back(se::Value((int)e));
        invokeJSFun(__FUNCTION__, args);
    }

    //Miscellaneous callbacks
    void onChartboostConfirmation() {
        MAKE_V8_HAPPY
        
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }
    void onChartboostCompleteStore() {
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }
};

static bool js_PluginChartboostJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        ChartboostListenerJS* nativeDelegate = dynamic_cast<ChartboostListenerJS*>(sdkbox::PluginChartboost::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) ChartboostListenerJS();
            sdkbox::PluginChartboost::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginChartboostJS_setListener)

extern se::Object* __jsb_sdkbox_PluginChartboost_proto;
extern se::Class* __jsb_sdkbox_PluginChartboost_class;
bool register_all_PluginChartboostJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginChartboost");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginChartboostJS_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}


