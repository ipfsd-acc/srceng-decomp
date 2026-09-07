// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_session.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1002DE60
// Name: void MatchSession_BroadcastSessionSettingsUpdate(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatchSession_BroadcastSessionSettingsUpdate(KeyValues *pUpdateDeletePackage)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  KeyValues *Key; // eax
  KeyValues *Copy; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "OnMatchSessionUpdate");
  else
    v2 = nullptr;
  KeyValues::SetString(this: v2, keyName: "state", value: "updated");
  Key = KeyValues::FindKey(this: pUpdateDeletePackage, keyName: "update", bCreate: false);
  if ( Key != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: Key);
    KeyValues::AddSubKey(this: v2, pSubkey: Copy);
  }
  v5 = KeyValues::FindKey(this: pUpdateDeletePackage, keyName: "delete", bCreate: false);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::MakeCopy(this: v5);
    KeyValues::AddSubKey(this: v2, pSubkey: v6);
  }
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1002DEF0
// Name: void MatchSession_PrepareClientForConnect(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatchSession_PrepareClientForConnect(KeyValues *pSettings)
{
  IMatchSession *v1; // eax
  KeyValues *v2; // eax
  unsigned __int64 Uint64; // rax
  IMatchTitle *v4; // eax
  char chSession[64]; // [esp+0h] [ebp-40h] BYREF

  v1 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  v2 = (KeyValues *)v1->GetSessionSystemData(this: v1);
  Uint64 = KeyValues::GetUint64(this: v2, keyName: "xuidReserve", defaultValue: 0);
  sprintf(string: chSession, format: "$%llx", Uint64);
  ConVar::SetValue(this: (ConVar *)&cl_session.IConVar, value: chSession);
  v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v4->PrepareClientForConnect(this: v4, a2: pSettings);
}

//------------------------------------------------------------------------------
// Address: 0x1002DF60
// Name: MatchSession_ResolveServerInfo_Helper_ConnectString
// Source: json
//------------------------------------------------------------------------------
char __usercall MatchSession_ResolveServerInfo_Helper_ConnectString@<al>(
        KeyValues *pSettings@<edi>,
        MatchSessionServerInfo_t *info@<esi>,
        CSysSessionBase *pSysSession)
{
  unsigned __int64 Uint64; // rax

  V_snprintf(
    pDest: info->m_szConnectCmd,
    maxLen: 256,
    pFormat: "connect %s %s\n",
    info->m_dsResult.m_szPublicConnectionString,
    info->m_dsResult.m_szPrivateConnectionString);
  info->m_xuidJingle = KeyValues::GetUint64(this: pSettings, keyName: "server/xuid", defaultValue: 0);
  Uint64 = KeyValues::GetUint64(this: pSettings, keyName: "server/reservationid", defaultValue: 0);
  if ( Uint64 != 0 )
    goto LABEL_4;
  if ( pSysSession != nullptr )
  {
    Uint64 = CSysSessionBase::GetReservationCookie(this: pSysSession);
LABEL_4:
    info->m_uiReservationCookie = Uint64;
    return 1;
  }
  info->m_uiReservationCookie = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002DFF0
// Name: bool MatchSession_ResolveServerInfo(class KeyValues __near *,class CSysSessionBase __near *,struct MatchSessionServerInfo_t __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatchSession_ResolveServerInfo(
        KeyValues *pSettings,
        CSysSessionBase *pSysSession,
        MatchSessionServerInfo_t *info,
        char uiResolveFlags)
{
  char *String; // eax
  char *v5; // eax
  char result; // al

  if ( (uiResolveFlags & 9) != 0 )
  {
    String = KeyValues::GetString(this: pSettings, keyName: "server/adronline", defaultValue: "0.0.0.0");
    V_strncpy(pDest: info->m_dsResult.m_szPublicConnectionString, pSrc: String, maxLen: 256);
    v5 = KeyValues::GetString(this: pSettings, keyName: "server/adrlocal", defaultValue: "0.0.0.0");
    V_strncpy(pDest: info->m_dsResult.m_szPrivateConnectionString, pSrc: v5, maxLen: 256);
  }
  if ( (uiResolveFlags & 2) == 0 )
    return 1;
  result = MatchSession_ResolveServerInfo_Helper_ConnectString(pSettings, info, pSysSession);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E080
// Name: unsigned __int64 MatchSession_GetMachineFlags(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __cdecl MatchSession_GetMachineFlags()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002E090
// Name: char const __near * MatchSession_GetTuInstalledString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MatchSession_GetTuInstalledString()
{
  char *result; // eax

  if ( (mm_tu_string.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = mm_tu_string.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E0C0
// Name: mm_debugprint
// Source: json
//------------------------------------------------------------------------------
void __cdecl mm_debugprint()
{
  IMatchSession *v0; // eax

  v0 = g_pMMF->GetMatchSession(this: g_pMMF);
  if ( v0 != nullptr )
    ((void (__thiscall *)(IMatchSession *))v0->__vftable[1].UpdateSessionSettings)(a1: v0);
  else
    DevMsg(a1: "No match session.\n");
}
