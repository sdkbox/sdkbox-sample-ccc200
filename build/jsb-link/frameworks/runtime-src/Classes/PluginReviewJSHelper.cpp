#include "PluginReviewJSHelper.h"
#include "PluginReview/PluginReview.h"
#include "SDKBoxJSHelper.h"

class ReviewListenerJS : public sdkbox::ReviewListener, public sdkbox::JSListenerBase
{
public:
    ReviewListenerJS() : sdkbox::JSListenerBase() {
    }

    void onDisplayAlert() {
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }

    void onDeclineToRate() {
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }

    void onRate() {
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }

    void onRemindLater() {
        se::ValueArray args;
        invokeJSFun(__FUNCTION__, args);
    }
};

static bool js_PluginReviewJS_setListener(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    if (argc == 1)
    {
        ReviewListenerJS* nativeDelegate = dynamic_cast<ReviewListenerJS*>(sdkbox::PluginReview::getListener());
        if (!nativeDelegate) {
            nativeDelegate = new (std::nothrow) ReviewListenerJS();
            sdkbox::PluginReview::setListener(nativeDelegate);
        }
        nativeDelegate->setJSDelegate(args[0]);


        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginReviewJS_setListener)

extern se::Object* __jsb_sdkbox_PluginReview_proto;
extern se::Class* __jsb_sdkbox_PluginReview_class;
bool register_all_PluginReviewJS_helper(se::Object* obj)
{
    auto pluginValue = sdkbox::getPluginValue(obj, "sdkbox.PluginReview");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("setListener", _SE(js_PluginReviewJS_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}


