#include "PluginGPGJS.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "PluginGPG/SdkboxGooglePlayWrappedObjects.h"

se::Object* __jsb_sdkbox_GPGRealTimeMultiplayerWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGRealTimeMultiplayerWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_CreateRealTimeRoom(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_CreateRealTimeRoom : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::CreateRealTimeRoom(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_CreateRealTimeRoom)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_LeaveRoom(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_LeaveRoom : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::LeaveRoom(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_LeaveRoom)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessage : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::SendUnreliableMessage(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessage)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DismissInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DismissInvitation : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::DismissInvitation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DismissInvitation)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DeclineInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DeclineInvitation : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::DeclineInvitation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DeclineInvitation)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendReliableMessage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendReliableMessage : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::SendReliableMessage(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendReliableMessage)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_AcceptInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_AcceptInvitation : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::AcceptInvitation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_AcceptInvitation)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_FetchInvitations(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_FetchInvitations : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::FetchInvitations(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_FetchInvitations)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessageToOthers(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessageToOthers : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::SendUnreliableMessageToOthers(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessageToOthers)

static bool js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_ShowRoomInboxUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_ShowRoomInboxUI : Error processing arguments");
        sdkbox::GPGRealTimeMultiplayerWrapper::ShowRoomInboxUI(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_ShowRoomInboxUI)



static bool js_sdkbox_GPGRealTimeMultiplayerWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGRealTimeMultiplayerWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGRealTimeMultiplayerWrapper* cobj = (sdkbox::GPGRealTimeMultiplayerWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGRealTimeMultiplayerWrapper_finalize)

bool js_register_PluginGPGJS_GPGRealTimeMultiplayerWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGRealTimeMultiplayerWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("CreateRealTimeRoom", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_CreateRealTimeRoom));
    cls->defineStaticFunction("LeaveRoom", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_LeaveRoom));
    cls->defineStaticFunction("SendUnreliableMessage", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessage));
    cls->defineStaticFunction("DismissInvitation", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DismissInvitation));
    cls->defineStaticFunction("DeclineInvitation", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_DeclineInvitation));
    cls->defineStaticFunction("SendReliableMessage", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendReliableMessage));
    cls->defineStaticFunction("AcceptInvitation", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_AcceptInvitation));
    cls->defineStaticFunction("FetchInvitations", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_FetchInvitations));
    cls->defineStaticFunction("SendUnreliableMessageToOthers", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_SendUnreliableMessageToOthers));
    cls->defineStaticFunction("ShowRoomInboxUI", _SE(js_PluginGPGJS_GPGRealTimeMultiplayerWrapper_ShowRoomInboxUI));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGRealTimeMultiplayerWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGRealTimeMultiplayerWrapper>(cls);

    __jsb_sdkbox_GPGRealTimeMultiplayerWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGRealTimeMultiplayerWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGTurnBasedMultiplayerWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGTurnBasedMultiplayerWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowPlayerSelectUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        bool arg3;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_boolean(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowPlayerSelectUI : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::ShowPlayerSelectUI(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowPlayerSelectUI)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CancelMatch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CancelMatch : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::CancelMatch(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CancelMatch)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissMatch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissMatch : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::DismissMatch(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissMatch)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowMatchInboxUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowMatchInboxUI : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::ShowMatchInboxUI(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowMatchInboxUI)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_SynchronizeData(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::GPGTurnBasedMultiplayerWrapper::SynchronizeData();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_SynchronizeData)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateTurnBasedMatch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateTurnBasedMatch : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::CreateTurnBasedMatch(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateTurnBasedMatch)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissInvitation : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::DismissInvitation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissInvitation)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatch : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::FetchMatch(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatch)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DeclineInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DeclineInvitation : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::DeclineInvitation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DeclineInvitation)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ConfirmPendingCompletion(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ConfirmPendingCompletion : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::ConfirmPendingCompletion(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ConfirmPendingCompletion)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FinishMatchDuringMyTurn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FinishMatchDuringMyTurn : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::FinishMatchDuringMyTurn(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FinishMatchDuringMyTurn)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_Rematch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_Rematch : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::Rematch(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_Rematch)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringTheirTurn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringTheirTurn : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::LeaveMatchDuringTheirTurn(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringTheirTurn)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateParticipantResult(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateParticipantResult : Error processing arguments");
        std::string result = sdkbox::GPGTurnBasedMultiplayerWrapper::CreateParticipantResult(arg0, arg1, arg2, arg3);
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateParticipantResult : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateParticipantResult)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_TakeMyTurn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        int arg0 = 0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_std_string(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_TakeMyTurn : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::TakeMyTurn(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_TakeMyTurn)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatches(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatches : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::FetchMatches(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatches)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringMyTurn(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        std::string arg2;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringMyTurn : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::LeaveMatchDuringMyTurn(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringMyTurn)

static bool js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_AcceptInvitation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_AcceptInvitation : Error processing arguments");
        sdkbox::GPGTurnBasedMultiplayerWrapper::AcceptInvitation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_AcceptInvitation)



static bool js_sdkbox_GPGTurnBasedMultiplayerWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGTurnBasedMultiplayerWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGTurnBasedMultiplayerWrapper* cobj = (sdkbox::GPGTurnBasedMultiplayerWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGTurnBasedMultiplayerWrapper_finalize)

bool js_register_PluginGPGJS_GPGTurnBasedMultiplayerWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGTurnBasedMultiplayerWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("ShowPlayerSelectUI", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowPlayerSelectUI));
    cls->defineStaticFunction("CancelMatch", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CancelMatch));
    cls->defineStaticFunction("DismissMatch", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissMatch));
    cls->defineStaticFunction("ShowMatchInboxUI", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ShowMatchInboxUI));
    cls->defineStaticFunction("SynchronizeData", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_SynchronizeData));
    cls->defineStaticFunction("CreateTurnBasedMatch", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateTurnBasedMatch));
    cls->defineStaticFunction("DismissInvitation", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DismissInvitation));
    cls->defineStaticFunction("FetchMatch", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatch));
    cls->defineStaticFunction("DeclineInvitation", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_DeclineInvitation));
    cls->defineStaticFunction("ConfirmPendingCompletion", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_ConfirmPendingCompletion));
    cls->defineStaticFunction("FinishMatchDuringMyTurn", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FinishMatchDuringMyTurn));
    cls->defineStaticFunction("Rematch", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_Rematch));
    cls->defineStaticFunction("LeaveMatchDuringTheirTurn", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringTheirTurn));
    cls->defineStaticFunction("CreateParticipantResult", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_CreateParticipantResult));
    cls->defineStaticFunction("TakeMyTurn", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_TakeMyTurn));
    cls->defineStaticFunction("FetchMatches", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_FetchMatches));
    cls->defineStaticFunction("LeaveMatchDuringMyTurn", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_LeaveMatchDuringMyTurn));
    cls->defineStaticFunction("AcceptInvitation", _SE(js_PluginGPGJS_GPGTurnBasedMultiplayerWrapper_AcceptInvitation));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGTurnBasedMultiplayerWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGTurnBasedMultiplayerWrapper>(cls);

    __jsb_sdkbox_GPGTurnBasedMultiplayerWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGTurnBasedMultiplayerWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGWrapper_StartAuthorizationUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::GPGWrapper::StartAuthorizationUI();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_StartAuthorizationUI)

static bool js_PluginGPGJS_GPGWrapper_getAuthCode(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::GPGWrapper::getAuthCode();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGWrapper_getAuthCode : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_getAuthCode)

static bool js_PluginGPGJS_GPGWrapper_IsAuthorized(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = sdkbox::GPGWrapper::IsAuthorized();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGWrapper_IsAuthorized : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_IsAuthorized)

static bool js_PluginGPGJS_GPGWrapper_NotifyToScripting(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGWrapper_NotifyToScripting : Error processing arguments");
        sdkbox::GPGWrapper::NotifyToScripting(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_NotifyToScripting)

static bool js_PluginGPGJS_GPGWrapper_CreateGameServices(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGWrapper_CreateGameServices : Error processing arguments");
        sdkbox::GPGWrapper::CreateGameServices(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_CreateGameServices)

static bool js_PluginGPGJS_GPGWrapper_SignOut(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::GPGWrapper::SignOut();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGWrapper_SignOut)



static bool js_sdkbox_GPGWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGWrapper* cobj = (sdkbox::GPGWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGWrapper_finalize)

bool js_register_PluginGPGJS_GPGWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("StartAuthorizationUI", _SE(js_PluginGPGJS_GPGWrapper_StartAuthorizationUI));
    cls->defineStaticFunction("getAuthCode", _SE(js_PluginGPGJS_GPGWrapper_getAuthCode));
    cls->defineStaticFunction("IsAuthorized", _SE(js_PluginGPGJS_GPGWrapper_IsAuthorized));
    cls->defineStaticFunction("NotifyToScripting", _SE(js_PluginGPGJS_GPGWrapper_NotifyToScripting));
    cls->defineStaticFunction("CreateGameServices", _SE(js_PluginGPGJS_GPGWrapper_CreateGameServices));
    cls->defineStaticFunction("SignOut", _SE(js_PluginGPGJS_GPGWrapper_SignOut));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGWrapper>(cls);

    __jsb_sdkbox_GPGWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGPlayerWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGPlayerWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyConnected(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyConnected : Error processing arguments");
        sdkbox::GPGPlayerWrapper::FetchRecentlyConnected(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyConnected)

static bool js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyInvitable(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyInvitable : Error processing arguments");
        sdkbox::GPGPlayerWrapper::FetchRecentlyInvitable(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyInvitable)

static bool js_PluginGPGJS_GPGPlayerWrapper_Fetch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        std::string arg2;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGPlayerWrapper_Fetch : Error processing arguments");
        sdkbox::GPGPlayerWrapper::Fetch(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGPlayerWrapper_Fetch)

static bool js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyPlayed(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyPlayed : Error processing arguments");
        sdkbox::GPGPlayerWrapper::FetchRecentlyPlayed(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyPlayed)

static bool js_PluginGPGJS_GPGPlayerWrapper_FetchSelf(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGPlayerWrapper_FetchSelf : Error processing arguments");
        sdkbox::GPGPlayerWrapper::FetchSelf(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGPlayerWrapper_FetchSelf)



static bool js_sdkbox_GPGPlayerWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGPlayerWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGPlayerWrapper* cobj = (sdkbox::GPGPlayerWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGPlayerWrapper_finalize)

bool js_register_PluginGPGJS_GPGPlayerWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGPlayerWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchRecentlyConnected", _SE(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyConnected));
    cls->defineStaticFunction("FetchRecentlyInvitable", _SE(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyInvitable));
    cls->defineStaticFunction("Fetch", _SE(js_PluginGPGJS_GPGPlayerWrapper_Fetch));
    cls->defineStaticFunction("FetchRecentlyPlayed", _SE(js_PluginGPGJS_GPGPlayerWrapper_FetchRecentlyPlayed));
    cls->defineStaticFunction("FetchSelf", _SE(js_PluginGPGJS_GPGPlayerWrapper_FetchSelf));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGPlayerWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGPlayerWrapper>(cls);

    __jsb_sdkbox_GPGPlayerWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGPlayerWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGSnapshotWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGSnapshotWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGSnapshotWrapper_Load(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGSnapshotWrapper_Load : Error processing arguments");
        sdkbox::GPGSnapshotWrapper::Load(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGSnapshotWrapper_Load)

static bool js_PluginGPGJS_GPGSnapshotWrapper_ShowSelectUIOperation(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGSnapshotWrapper_ShowSelectUIOperation : Error processing arguments");
        sdkbox::GPGSnapshotWrapper::ShowSelectUIOperation(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGSnapshotWrapper_ShowSelectUIOperation)

static bool js_PluginGPGJS_GPGSnapshotWrapper_Save(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGSnapshotWrapper_Save : Error processing arguments");
        sdkbox::GPGSnapshotWrapper::Save(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGSnapshotWrapper_Save)

static bool js_PluginGPGJS_GPGSnapshotWrapper_Delete(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGSnapshotWrapper_Delete : Error processing arguments");
        sdkbox::GPGSnapshotWrapper::Delete(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGSnapshotWrapper_Delete)

static bool js_PluginGPGJS_GPGSnapshotWrapper_FetchAll(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGSnapshotWrapper_FetchAll : Error processing arguments");
        sdkbox::GPGSnapshotWrapper::FetchAll(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGSnapshotWrapper_FetchAll)



static bool js_sdkbox_GPGSnapshotWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGSnapshotWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGSnapshotWrapper* cobj = (sdkbox::GPGSnapshotWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGSnapshotWrapper_finalize)

bool js_register_PluginGPGJS_GPGSnapshotWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGSnapshotWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("Load", _SE(js_PluginGPGJS_GPGSnapshotWrapper_Load));
    cls->defineStaticFunction("ShowSelectUIOperation", _SE(js_PluginGPGJS_GPGSnapshotWrapper_ShowSelectUIOperation));
    cls->defineStaticFunction("Save", _SE(js_PluginGPGJS_GPGSnapshotWrapper_Save));
    cls->defineStaticFunction("Delete", _SE(js_PluginGPGJS_GPGSnapshotWrapper_Delete));
    cls->defineStaticFunction("FetchAll", _SE(js_PluginGPGJS_GPGSnapshotWrapper_FetchAll));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGSnapshotWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGSnapshotWrapper>(cls);

    __jsb_sdkbox_GPGSnapshotWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGSnapshotWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGLeaderboardWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGLeaderboardWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchAll(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchAll : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchAll(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchAll)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchScoreSummary(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        int arg0 = 0;
        int arg1 = 0;
        std::string arg2;
        int arg3 = 0;
        int arg4 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchScoreSummary : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchScoreSummary(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchScoreSummary)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchPreviousScorePage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchPreviousScorePage : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchPreviousScorePage(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchPreviousScorePage)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_ShowAllUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_ShowAllUI : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::ShowAllUI(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_ShowAllUI)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchNextScorePage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchNextScorePage : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchNextScorePage(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchNextScorePage)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_SubmitScore(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        long arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_long(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_SubmitScore : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::SubmitScore(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        int arg0 = 0;
        std::string arg1;
        long arg2 = 0;
        std::string arg3;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_long(args[2], &arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_SubmitScore : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::SubmitScore(arg0, arg1, arg2, arg3);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_SubmitScore)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchAllScoreSummaries(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        int arg1 = 0;
        std::string arg2;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchAllScoreSummaries : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchAllScoreSummaries(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchAllScoreSummaries)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_ShowUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_ShowUI : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::ShowUI(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_ShowUI)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_Fetch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_Fetch : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::Fetch(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_Fetch)

static bool js_PluginGPGJS_GPGLeaderboardWrapper_FetchScorePage(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 7) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        int arg3 = 0;
        int arg4 = 0;
        int arg5 = 0;
        int arg6 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        ok &= seval_to_int32(args[5], (int32_t*)&arg5);
        ok &= seval_to_int32(args[6], (int32_t*)&arg6);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGLeaderboardWrapper_FetchScorePage : Error processing arguments");
        sdkbox::GPGLeaderboardWrapper::FetchScorePage(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGLeaderboardWrapper_FetchScorePage)



static bool js_sdkbox_GPGLeaderboardWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGLeaderboardWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGLeaderboardWrapper* cobj = (sdkbox::GPGLeaderboardWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGLeaderboardWrapper_finalize)

bool js_register_PluginGPGJS_GPGLeaderboardWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGLeaderboardWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchAll", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchAll));
    cls->defineStaticFunction("FetchScoreSummary", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchScoreSummary));
    cls->defineStaticFunction("FetchPreviousScorePage", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchPreviousScorePage));
    cls->defineStaticFunction("ShowAllUI", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_ShowAllUI));
    cls->defineStaticFunction("FetchNextScorePage", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchNextScorePage));
    cls->defineStaticFunction("SubmitScore", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_SubmitScore));
    cls->defineStaticFunction("FetchAllScoreSummaries", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchAllScoreSummaries));
    cls->defineStaticFunction("ShowUI", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_ShowUI));
    cls->defineStaticFunction("Fetch", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_Fetch));
    cls->defineStaticFunction("FetchScorePage", _SE(js_PluginGPGJS_GPGLeaderboardWrapper_FetchScorePage));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGLeaderboardWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGLeaderboardWrapper>(cls);

    __jsb_sdkbox_GPGLeaderboardWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGLeaderboardWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGAchievementWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGAchievementWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGAchievementWrapper_FetchAll(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_FetchAll : Error processing arguments");
        sdkbox::GPGAchievementWrapper::FetchAll(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_FetchAll)

static bool js_PluginGPGJS_GPGAchievementWrapper_Reveal(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_Reveal : Error processing arguments");
        sdkbox::GPGAchievementWrapper::Reveal(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_Reveal)

static bool js_PluginGPGJS_GPGAchievementWrapper_Unlock(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_Unlock : Error processing arguments");
        sdkbox::GPGAchievementWrapper::Unlock(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_Unlock)

static bool js_PluginGPGJS_GPGAchievementWrapper_ShowAllUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_ShowAllUI : Error processing arguments");
        sdkbox::GPGAchievementWrapper::ShowAllUI(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_ShowAllUI)

static bool js_PluginGPGJS_GPGAchievementWrapper_SetStepsAtLeast(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_SetStepsAtLeast : Error processing arguments");
        sdkbox::GPGAchievementWrapper::SetStepsAtLeast(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_SetStepsAtLeast)

static bool js_PluginGPGJS_GPGAchievementWrapper_Increment(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_Increment : Error processing arguments");
        sdkbox::GPGAchievementWrapper::Increment(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_Increment)

static bool js_PluginGPGJS_GPGAchievementWrapper_Fetch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGAchievementWrapper_Fetch : Error processing arguments");
        sdkbox::GPGAchievementWrapper::Fetch(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGAchievementWrapper_Fetch)



static bool js_sdkbox_GPGAchievementWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGAchievementWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGAchievementWrapper* cobj = (sdkbox::GPGAchievementWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGAchievementWrapper_finalize)

bool js_register_PluginGPGJS_GPGAchievementWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGAchievementWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchAll", _SE(js_PluginGPGJS_GPGAchievementWrapper_FetchAll));
    cls->defineStaticFunction("Reveal", _SE(js_PluginGPGJS_GPGAchievementWrapper_Reveal));
    cls->defineStaticFunction("Unlock", _SE(js_PluginGPGJS_GPGAchievementWrapper_Unlock));
    cls->defineStaticFunction("ShowAllUI", _SE(js_PluginGPGJS_GPGAchievementWrapper_ShowAllUI));
    cls->defineStaticFunction("SetStepsAtLeast", _SE(js_PluginGPGJS_GPGAchievementWrapper_SetStepsAtLeast));
    cls->defineStaticFunction("Increment", _SE(js_PluginGPGJS_GPGAchievementWrapper_Increment));
    cls->defineStaticFunction("Fetch", _SE(js_PluginGPGJS_GPGAchievementWrapper_Fetch));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGAchievementWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGAchievementWrapper>(cls);

    __jsb_sdkbox_GPGAchievementWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGAchievementWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGQuestsWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGQuestsWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGQuestsWrapper_FetchList(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_FetchList : Error processing arguments");
        sdkbox::GPGQuestsWrapper::FetchList(arg0);
        return true;
    }
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_FetchList : Error processing arguments");
        sdkbox::GPGQuestsWrapper::FetchList(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_FetchList)

static bool js_PluginGPGJS_GPGQuestsWrapper_Accept(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_Accept : Error processing arguments");
        sdkbox::GPGQuestsWrapper::Accept(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_Accept)

static bool js_PluginGPGJS_GPGQuestsWrapper_ShowAllUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_ShowAllUI : Error processing arguments");
        sdkbox::GPGQuestsWrapper::ShowAllUI(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_ShowAllUI)

static bool js_PluginGPGJS_GPGQuestsWrapper_ShowUI(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_ShowUI : Error processing arguments");
        sdkbox::GPGQuestsWrapper::ShowUI(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_ShowUI)

static bool js_PluginGPGJS_GPGQuestsWrapper_ClaimMilestone(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_ClaimMilestone : Error processing arguments");
        sdkbox::GPGQuestsWrapper::ClaimMilestone(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_ClaimMilestone)

static bool js_PluginGPGJS_GPGQuestsWrapper_Fetch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_Fetch : Error processing arguments");
        sdkbox::GPGQuestsWrapper::Fetch(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGQuestsWrapper_Fetch : Error processing arguments");
        sdkbox::GPGQuestsWrapper::Fetch(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGQuestsWrapper_Fetch)



static bool js_sdkbox_GPGQuestsWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGQuestsWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGQuestsWrapper* cobj = (sdkbox::GPGQuestsWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGQuestsWrapper_finalize)

bool js_register_PluginGPGJS_GPGQuestsWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGQuestsWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchList", _SE(js_PluginGPGJS_GPGQuestsWrapper_FetchList));
    cls->defineStaticFunction("Accept", _SE(js_PluginGPGJS_GPGQuestsWrapper_Accept));
    cls->defineStaticFunction("ShowAllUI", _SE(js_PluginGPGJS_GPGQuestsWrapper_ShowAllUI));
    cls->defineStaticFunction("ShowUI", _SE(js_PluginGPGJS_GPGQuestsWrapper_ShowUI));
    cls->defineStaticFunction("ClaimMilestone", _SE(js_PluginGPGJS_GPGQuestsWrapper_ClaimMilestone));
    cls->defineStaticFunction("Fetch", _SE(js_PluginGPGJS_GPGQuestsWrapper_Fetch));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGQuestsWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGQuestsWrapper>(cls);

    __jsb_sdkbox_GPGQuestsWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGQuestsWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGEventsWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGEventsWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGEventsWrapper_FetchAll(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_FetchAll : Error processing arguments");
        sdkbox::GPGEventsWrapper::FetchAll(arg0);
        return true;
    }
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_FetchAll : Error processing arguments");
        sdkbox::GPGEventsWrapper::FetchAll(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGEventsWrapper_FetchAll)

static bool js_PluginGPGJS_GPGEventsWrapper_Fetch(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        std::string arg1;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_Fetch : Error processing arguments");
        sdkbox::GPGEventsWrapper::Fetch(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        int arg0 = 0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_Fetch : Error processing arguments");
        sdkbox::GPGEventsWrapper::Fetch(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGEventsWrapper_Fetch)

static bool js_PluginGPGJS_GPGEventsWrapper_Increment(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_Increment : Error processing arguments");
        sdkbox::GPGEventsWrapper::Increment(arg0);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGEventsWrapper_Increment : Error processing arguments");
        sdkbox::GPGEventsWrapper::Increment(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGEventsWrapper_Increment)



static bool js_sdkbox_GPGEventsWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGEventsWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGEventsWrapper* cobj = (sdkbox::GPGEventsWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGEventsWrapper_finalize)

bool js_register_PluginGPGJS_GPGEventsWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGEventsWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchAll", _SE(js_PluginGPGJS_GPGEventsWrapper_FetchAll));
    cls->defineStaticFunction("Fetch", _SE(js_PluginGPGJS_GPGEventsWrapper_Fetch));
    cls->defineStaticFunction("Increment", _SE(js_PluginGPGJS_GPGEventsWrapper_Increment));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGEventsWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGEventsWrapper>(cls);

    __jsb_sdkbox_GPGEventsWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGEventsWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGStatsWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGStatsWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGStatsWrapper_FetchForPlayer(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        int arg0 = 0;
        int arg1 = 0;
        ok &= seval_to_int32(args[0], (int32_t*)&arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGStatsWrapper_FetchForPlayer : Error processing arguments");
        sdkbox::GPGStatsWrapper::FetchForPlayer(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGStatsWrapper_FetchForPlayer)



static bool js_sdkbox_GPGStatsWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGStatsWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGStatsWrapper* cobj = (sdkbox::GPGStatsWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGStatsWrapper_finalize)

bool js_register_PluginGPGJS_GPGStatsWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGStatsWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("FetchForPlayer", _SE(js_PluginGPGJS_GPGStatsWrapper_FetchForPlayer));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGStatsWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGStatsWrapper>(cls);

    __jsb_sdkbox_GPGStatsWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGStatsWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_sdkbox_GPGNearbyConnectionsWrapper_proto = nullptr;
se::Class* __jsb_sdkbox_GPGNearbyConnectionsWrapper_class = nullptr;

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartDiscovery(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartDiscovery : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::StartDiscovery(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartDiscovery)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_RejectConnectionRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_RejectConnectionRequest : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::RejectConnectionRequest(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_RejectConnectionRequest)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_Disconnect(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_Disconnect : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::Disconnect(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Disconnect)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendUnreliableMessage(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::vector<std::string> arg0;
            ok &= seval_to_std_vector_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::GPGNearbyConnectionsWrapper::SendUnreliableMessage(arg0, arg1);
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::GPGNearbyConnectionsWrapper::SendUnreliableMessage(arg0, arg1);
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendUnreliableMessage)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalDeviceId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::GPGNearbyConnectionsWrapper::GetLocalDeviceId();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalDeviceId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalDeviceId)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopAdvertising(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::GPGNearbyConnectionsWrapper::StopAdvertising();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopAdvertising)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_Stop(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        sdkbox::GPGNearbyConnectionsWrapper::Stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Stop)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendReliableMessage(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            std::vector<std::string> arg0;
            ok &= seval_to_std_vector_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::GPGNearbyConnectionsWrapper::SendReliableMessage(arg0, arg1);
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= seval_to_std_string(args[0], &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= seval_to_std_string(args[1], &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::GPGNearbyConnectionsWrapper::SendReliableMessage(arg0, arg1);
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendReliableMessage)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalEndpointId(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string result = sdkbox::GPGNearbyConnectionsWrapper::GetLocalEndpointId();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalEndpointId : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalEndpointId)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_Init(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_Init : Error processing arguments");
        bool result = sdkbox::GPGNearbyConnectionsWrapper::Init(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_Init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Init)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopDiscovery(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= seval_to_std_string(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopDiscovery : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::StopDiscovery(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopDiscovery)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendConnectionRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        int arg3 = 0;
        int arg4 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_std_string(args[2], &arg2);
        ok &= seval_to_int32(args[3], (int32_t*)&arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendConnectionRequest : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::SendConnectionRequest(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendConnectionRequest)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartAdvertising(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_int32(args[1], (int32_t*)&arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartAdvertising : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::StartAdvertising(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartAdvertising)

static bool js_PluginGPGJS_GPGNearbyConnectionsWrapper_AcceptConnectionRequest(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        int arg2 = 0;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        ok &= seval_to_int32(args[2], (int32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_PluginGPGJS_GPGNearbyConnectionsWrapper_AcceptConnectionRequest : Error processing arguments");
        sdkbox::GPGNearbyConnectionsWrapper::AcceptConnectionRequest(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_PluginGPGJS_GPGNearbyConnectionsWrapper_AcceptConnectionRequest)



static bool js_sdkbox_GPGNearbyConnectionsWrapper_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (sdkbox::GPGNearbyConnectionsWrapper)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        sdkbox::GPGNearbyConnectionsWrapper* cobj = (sdkbox::GPGNearbyConnectionsWrapper*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_sdkbox_GPGNearbyConnectionsWrapper_finalize)

bool js_register_PluginGPGJS_GPGNearbyConnectionsWrapper(se::Object* obj)
{
    auto cls = se::Class::create("GPGNearbyConnectionsWrapper", obj, nullptr, nullptr);

    cls->defineStaticFunction("StartDiscovery", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartDiscovery));
    cls->defineStaticFunction("RejectConnectionRequest", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_RejectConnectionRequest));
    cls->defineStaticFunction("Disconnect", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Disconnect));
    cls->defineStaticFunction("SendUnreliableMessage", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendUnreliableMessage));
    cls->defineStaticFunction("GetLocalDeviceId", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalDeviceId));
    cls->defineStaticFunction("StopAdvertising", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopAdvertising));
    cls->defineStaticFunction("Stop", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Stop));
    cls->defineStaticFunction("SendReliableMessage", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendReliableMessage));
    cls->defineStaticFunction("GetLocalEndpointId", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_GetLocalEndpointId));
    cls->defineStaticFunction("Init", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_Init));
    cls->defineStaticFunction("StopDiscovery", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StopDiscovery));
    cls->defineStaticFunction("SendConnectionRequest", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_SendConnectionRequest));
    cls->defineStaticFunction("StartAdvertising", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_StartAdvertising));
    cls->defineStaticFunction("AcceptConnectionRequest", _SE(js_PluginGPGJS_GPGNearbyConnectionsWrapper_AcceptConnectionRequest));
    cls->defineFinalizeFunction(_SE(js_sdkbox_GPGNearbyConnectionsWrapper_finalize));
    cls->install();
    JSBClassType::registerClass<sdkbox::GPGNearbyConnectionsWrapper>(cls);

    __jsb_sdkbox_GPGNearbyConnectionsWrapper_proto = cls->getProto();
    __jsb_sdkbox_GPGNearbyConnectionsWrapper_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_PluginGPGJS(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("_gpg", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("_gpg", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_PluginGPGJS_GPGEventsWrapper(ns);
    js_register_PluginGPGJS_GPGNearbyConnectionsWrapper(ns);
    js_register_PluginGPGJS_GPGPlayerWrapper(ns);
    js_register_PluginGPGJS_GPGSnapshotWrapper(ns);
    js_register_PluginGPGJS_GPGWrapper(ns);
    js_register_PluginGPGJS_GPGQuestsWrapper(ns);
    js_register_PluginGPGJS_GPGLeaderboardWrapper(ns);
    js_register_PluginGPGJS_GPGTurnBasedMultiplayerWrapper(ns);
    js_register_PluginGPGJS_GPGRealTimeMultiplayerWrapper(ns);
    js_register_PluginGPGJS_GPGAchievementWrapper(ns);
    js_register_PluginGPGJS_GPGStatsWrapper(ns);
    return true;
}

