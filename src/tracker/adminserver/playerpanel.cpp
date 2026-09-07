// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/playerpanel.cpp
// Functions: 21
// ============================================================

#include "tracker\adminserver\playerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1000C1B0
// Name: public: static char const __near * CPlayerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPlayerPanel::GetPanelClassName()
{
  return "CPlayerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1000C1C0
// Name: protected: virtual void CPlayerPanel::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnResetData(CPlayerPanel *this)
{
  IServerDataResponse *v2; // eax
  CRemoteServer *v3; // eax
  IServerDataResponse *v4; // [esp-8h] [ebp-Ch]

  if ( this != nullptr )
    v2 = &this->IServerDataResponse;
  else
    v2 = nullptr;
  v4 = v2;
  v3 = RemoteServer();
  CRemoteServer::RequestValue(this: v3, requester: v4, variable: "playerlist");
  this->m_flUpdateTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000C200
// Name: protected: virtual void CPlayerPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnThink(CPlayerPanel *this)
{
  long double m_flUpdateTime; // [esp+4h] [ebp-8h]

  m_flUpdateTime = this->m_flUpdateTime;
  if ( g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) > m_flUpdateTime )
    this->OnResetData(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: FormatSeconds
// Source: json
//------------------------------------------------------------------------------
char *__usercall FormatSeconds@<eax>(int seconds@<eax>)
{
  int v1; // esi
  int v2; // ecx

  v1 = seconds;
  v2 = seconds / 60;
  if ( seconds / 60 <= 0 || (v1 = seconds % 60, v2 / 60 <= 0) )
  {
    V_snprintf(pDest: string, maxLen: 64, pFormat: "%02i:%02i", v2, v1);
    return string;
  }
  else
  {
    V_snprintf(pDest: string, maxLen: 64, pFormat: "%2i:%02i:%02i", v2 / 60, v2 % 60, v1);
    return string;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C300
// Name: protected: virtual void CPlayerPanel::OnServerDataResponse(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnServerDataResponse(CPlayerPanel *this, const char *value, const char *response)
{
  const char *v3; // edi
  const char *v5; // edi
  char v6; // al
  char *v7; // edi
  int v8; // ecx
  char *v9; // edi
  char *v10; // ebx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  int v13; // eax
  char authID[64]; // [esp+8h] [ebp-ACh] BYREF
  char name[64]; // [esp+48h] [ebp-6Ch] BYREF
  char netAdr[32]; // [esp+88h] [ebp-2Ch] BYREF
  int connectTime; // [esp+A8h] [ebp-Ch] BYREF
  CPlayerPanel *v18; // [esp+ACh] [ebp-8h]
  int frags; // [esp+B0h] [ebp-4h] BYREF

  v3 = value;
  v18 = this;
  if ( _V_stricmp(s1: value, s2: "UpdatePlayers") != 0 )
  {
    if ( _V_stricmp(s1: v3, s2: "playerlist") == 0 )
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_OnNavigateFrom_register + 972))(a1: *(_DWORD *)&this->m_OnNavigateFrom_register);
      v5 = response;
      if ( response != nullptr )
      {
        do
        {
          if ( *v5 == 0 )
            break;
          g_pVGui->DPrintf2(this: g_pVGui, a2: "orig:  %s\n", v5);
          if ( *v5 != 34 )
            break;
          v6 = v5[1];
          v7 = (char *)(v5 + 1);
          v8 = 0;
          if ( v6 != 0 )
          {
            do
            {
              if ( v6 == 34 )
                break;
              ++v7;
              name[v8] = v6;
              v6 = *v7;
              ++v8;
            }
            while ( *v7 != 0 );
          }
          name[v8] = 0;
          v9 = v7 + 1;
          if ( sscanf(
                 string: v9,
                 format: " %s %s %d %d %d %d\n",
                 authID,
                 netAdr,
                 &value,
                 &response,
                 &frags,
                 &connectTime) != 6 )
            break;
          v10 = FormatSeconds(seconds: connectTime);
          ((void (__stdcall *)(vgui::IVGui *))g_pVGui->DPrintf2)(a1: g_pVGui);
          v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v12 = v11 != nullptr ? KeyValues::KeyValues(this: v11, setName: "Player") : nullptr;
          KeyValues::SetString(this: v12, keyName: "name", value: name);
          KeyValues::SetString(this: v12, keyName: "authID", value: authID);
          KeyValues::SetString(this: v12, keyName: "netAdr", value: netAdr);
          KeyValues::SetInt(this: v12, keyName: "ping", (int)value);
          KeyValues::SetInt(this: v12, keyName: "loss", value: (int)response);
          KeyValues::SetInt(this: v12, keyName: "frags", value: frags);
          KeyValues::SetString(this: v12, keyName: "time", value: v10);
          (*(void (__thiscall **)(_DWORD, KeyValues *, _DWORD, _DWORD))(**(_DWORD **)&v18->m_OnNavigateFrom_register
                                                                      + 916))(
            a1: *(_DWORD *)&v18->m_OnNavigateFrom_register,
            a2: v12,
            a3: 0,
            a4: 0);
          strchr(string: v9, chr: 0xAu);
          if ( v13 == 0 )
            break;
          v5 = (const char *)(v13 + 1);
        }
        while ( v13 != -1 );
      }
    }
  }
  else
  {
    *(_DWORD *)&this->m_InternalKeyCodePressed_register = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C4E0
// Name: private: virtual void CPlayerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnCommand(CPlayerPanel *this, const char *command)
{
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1000C4F0
// Name: private: virtual void CPlayerPanel::OnKickButtonPressed(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlayerPanel::OnKickButtonPressed(CPlayerPanel *this@<ecx>, int a2@<esi>)
{
  vgui::QueryBox *v3; // eax
  vgui::QueryBox *Box; // esi
  vgui::ListPanel_vtbl *v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  vgui::ILocalize_vtbl *v8; // esi
  const char *String; // eax
  vgui::ILocalize_vtbl *v10; // esi
  int v11; // eax
  vgui::QueryBox *v12; // esi
  const wchar_t *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  int v16; // [esp-4h] [ebp-488h]
  wchar_t msg[512]; // [esp+4h] [ebp-480h] BYREF
  wchar_t playerName[64]; // [esp+404h] [ebp-80h] BYREF

  if ( this->m_pPlayerListPanel->GetSelectedItemsCount(this: this->m_pPlayerListPanel) < 1 )
    return;
  if ( ((int (__thiscall *)(vgui::ListPanel *, int))this->m_pPlayerListPanel->GetSelectedItemsCount)(
         a1: this->m_pPlayerListPanel,
         a2) <= 1 )
  {
    v5 = this->m_pPlayerListPanel->__vftable;
    v6 = v5->GetSelectedItem(this: this->m_pPlayerListPanel, a2: 0);
    v7 = v5->GetItem(this: this->m_pPlayerListPanel, a2: v6);
    if ( v7 == nullptr )
      return;
    v8 = g_pVGuiLocalize->__vftable;
    String = KeyValues::GetString(this: v7, keyName: "name", defaultValue: defaultValue);
    ((void (__thiscall *)(vgui::ILocalize *, const char *, wchar_t *, int, int))v8->ConvertANSIToUnicode)(
      a1: g_pVGuiLocalize,
      a2: String,
      a3: playerName,
      a4: 128,
      a5: v16);
    v10 = g_pVGuiLocalize->__vftable;
    v11 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
            a1: g_pVGuiLocalize,
            a2: "Kick_Single_Player_Question",
            a3: 1,
            a4: playerName);
    ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v10->ConstructString_3)(
      a1: g_pVGuiLocalize,
      a2: msg,
      a3: 1024,
      a4: v11);
    v12 = (vgui::QueryBox *)operator new(nSize: 0x244u);
    if ( v12 != nullptr )
    {
      v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Kick_Single_Player_Title");
      Box = vgui::QueryBox::QueryBox(this: v12, wszTitle: v13, wszQueryText: msg, parent: nullptr);
      goto LABEL_9;
    }
LABEL_8:
    Box = nullptr;
    goto LABEL_9;
  }
  v3 = (vgui::QueryBox *)operator new(nSize: 0x244u);
  if ( v3 == nullptr )
    goto LABEL_8;
  Box = vgui::QueryBox::QueryBox(
          this: v3,
          title: "#Kick_Multiple_Players_Title",
          queryText: "#Kick_Multiple_Players_Question",
          parent: nullptr);
LABEL_9:
  Box->AddActionSignalTarget_2(this: Box, a2: this);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "KickSelectedPlayers");
  else
    v15 = nullptr;
  vgui::QueryBox::SetOKCommand(this: Box, keyValues: v15);
  Box->ShowWindow(this: Box, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000C670
// Name: private: virtual void CPlayerPanel::OnBanButtonPressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnBanButtonPressed(CPlayerPanel *this)
{
  vgui::ListPanel *m_pPlayerListPanel; // ecx
  vgui::ListPanel_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  char *String; // eax
  const char *v8; // ebx
  CDialogAddBan *v9; // eax
  CDialogAddBan *v10; // esi
  char buf[64]; // [esp+4h] [ebp-58h] BYREF
  const char *player; // [esp+44h] [ebp-18h]
  const char *authid; // [esp+48h] [ebp-14h]
  int s1; // [esp+4Ch] [ebp-10h] BYREF
  int s2; // [esp+50h] [ebp-Ch] BYREF
  int s3; // [esp+54h] [ebp-8h] BYREF
  int s4; // [esp+58h] [ebp-4h] BYREF

  if ( this->m_pPlayerListPanel->GetSelectedItemsCount(this: this->m_pPlayerListPanel) == 1 )
  {
    m_pPlayerListPanel = this->m_pPlayerListPanel;
    v3 = m_pPlayerListPanel->__vftable;
    v4 = m_pPlayerListPanel->GetSelectedItem(this: m_pPlayerListPanel, a2: 0);
    v5 = v3->GetItem(this: this->m_pPlayerListPanel, a2: v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      player = KeyValues::GetString(this: v5, keyName: "name", defaultValue: defaultValue);
      authid = KeyValues::GetString(this: v6, keyName: "authid", defaultValue: defaultValue);
      String = (char *)KeyValues::GetString(this: v6, keyName: "netAdr", defaultValue: defaultValue);
      if ( strcmp(authid, "UNKNOWN") == 0 && sscanf(string: String, format: "%d.%d.%d.%d", &s1, &s2, &s3, &s4) == 4 )
      {
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "%d.%d.%d.%d", s1, s2, s3, s4);
        v8 = buf;
      }
      else
      {
        v8 = authid;
      }
      v9 = (CDialogAddBan *)operator new(nSize: 0x230u);
      if ( v9 != nullptr )
        v10 = CDialogAddBan::CDialogAddBan(this: v9, parent: this);
      else
        v10 = nullptr;
      v10->AddActionSignalTarget_2(this: v10, a2: this);
      CDialogAddBan::Activate(this: v10, type: "addban", player, authid: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C7C0
// Name: private: virtual void CPlayerPanel::KickSelectedPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::KickSelectedPlayers(CPlayerPanel *this)
{
  int i; // edi
  int v3; // eax
  KeyValues *v4; // eax
  const char *String; // eax
  CRemoteServer *v6; // eax
  char cmd[512]; // [esp+8h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_pPlayerListPanel->GetSelectedItemsCount(this: this->m_pPlayerListPanel); ++i )
  {
    v3 = this->m_pPlayerListPanel->GetSelectedItem(this: this->m_pPlayerListPanel, a2: i);
    v4 = this->m_pPlayerListPanel->GetItem(this: this->m_pPlayerListPanel, a2: v3);
    if ( v4 != nullptr )
    {
      String = KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
      _snprintf(string: cmd, count: 0x200u, format: "kick \"%s\"", String);
      v6 = RemoteServer();
      CRemoteServer::SendCommand(this: v6, commandString: cmd);
    }
  }
  this->m_pPlayerListPanel->ClearSelectedItems(this: this->m_pPlayerListPanel);
  this->m_pKickButton->SetEnabled(this: this->m_pKickButton, a2: false);
  this->m_pBanButton->SetEnabled(this: this->m_pBanButton, a2: false);
  this->OnResetData(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C8B0
// Name: private: virtual void CPlayerPanel::AddBanByID(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::AddBanByID(CPlayerPanel *this, char *id, const char *newtime)
{
  char *v3; // ebx
  const char *v4; // esi
  const char *v5; // edi
  CRemoteServer *v6; // eax
  CRemoteServer *v7; // eax
  char cmd[512]; // [esp+4h] [ebp-210h] BYREF
  int s3; // [esp+204h] [ebp-10h] BYREF
  int s1; // [esp+208h] [ebp-Ch] BYREF
  int s2; // [esp+20Ch] [ebp-8h] BYREF
  CPlayerPanel *v12; // [esp+210h] [ebp-4h]

  v3 = id;
  v12 = this;
  if ( id != nullptr && *id != 0 )
  {
    if ( newtime == nullptr || atof(nptr: newtime) < 0.001 )
      newtime = "0";
    v4 = "banid";
    v5 = "writeip";
    if ( sscanf(string: v3, format: "%d.%d.%d.%d", &s1, &s2, &s3, &id) == 4 )
    {
      v4 = "addip";
      v5 = "writeid";
    }
    _snprintf(string: cmd, count: 0x1FFu, format: "%s %s %s\n", v4, newtime, v3);
    v6 = RemoteServer();
    CRemoteServer::SendCommand(this: v6, commandString: cmd);
    v7 = RemoteServer();
    CRemoteServer::SendCommand(this: v7, commandString: v5);
    v12->OnResetData(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C990
// Name: private: virtual void CPlayerPanel::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerPanel::OnItemSelected(CPlayerPanel *this)
{
  bool state; // [esp+4h] [ebp-4h]

  state = this->m_pPlayerListPanel->GetSelectedItemsCount(this: this->m_pPlayerListPanel) != 0;
  this->m_pKickButton->SetEnabled(this: this->m_pKickButton, a2: state);
  this->m_pBanButton->SetEnabled(this: this->m_pBanButton, a2: state);
  if ( this->m_pPlayerListPanel->GetSelectedItemsCount(this: this->m_pPlayerListPanel) > 1 )
    this->m_pBanButton->SetEnabled(this: this->m_pBanButton, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA30
// Name: public: virtual struct vgui::PanelMessageMap __near * CPlayerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPlayerPanel::GetMessageMap(CPlayerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPlayerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlayerPanel::GetMessageMap'::`2'::s_pMap;
  `CPlayerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
  `CPlayerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CA60
// Name: public: virtual struct PanelAnimationMap __near * CPlayerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPlayerPanel::GetAnimMap(CPlayerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPlayerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1000CA70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPlayerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPlayerPanel::GetKBMap(CPlayerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPlayerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlayerPanel::GetKBMap'::`2'::s_pMap;
  `CPlayerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPlayerPanel");
  `CPlayerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CAF0
// Name: public: static void CPlayerPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRawLogPanel::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "OpenContextMenu";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB90
// Name: public: static void CPlayerPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CC20
// Name: public: static void CPlayerPanel::PanelMessageFunc_OnKickButtonPressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_OnKickButtonPressed::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_OnKickButtonPressed::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_OnKickButtonPressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KickPlayer";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CCB0
// Name: public: static void CPlayerPanel::PanelMessageFunc_OnBanButtonPressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_OnBanButtonPressed::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_OnBanButtonPressed::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_OnBanButtonPressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVarListPropertyPage::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "BanPlayer";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CD40
// Name: public: static void CPlayerPanel::PanelMessageFunc_KickSelectedPlayers::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_KickSelectedPlayers::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_KickSelectedPlayers::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_KickSelectedPlayers::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CPlayerPanel::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "KickSelectedPlayers";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CDD0
// Name: public: static void CPlayerPanel::PanelMessageFunc_AddBanByID::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerPanel::PanelMessageFunc_AddBanByID::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CPlayerPanel::PanelMessageFunc_AddBanByID::InitVar'::`2'::bAdded )
  {
    `CPlayerPanel::PanelMessageFunc_AddBanByID::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Label::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    v4.secondParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.nameSymbol, 0, 12);
    v4.name = "AddBanValue";
    v4.func = v3;
    v4.numParams = 2;
    v4.firstParamName = "id";
    v4.secondParamName = "time";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE70
// Name: public: CPlayerPanel::CPlayerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPlayerPanel *__thiscall CPlayerPanel::CPlayerPanel(CPlayerPanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  CPlayerContextMenu *v13; // eax
  CPlayerContextMenu *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  CRemoteServer *v19; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&IServerDataResponse::`vftable';
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CPlayerPanel_vtbl *)&CPlayerPanel::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CPlayerPanel::`vftable'{for `IServerDataResponse'};
  if ( `CPlayerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPlayerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPlayerPanel");
    v4->pfnClassName = CPlayerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CPlayerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPlayerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPlayerPanel");
    v5->pfnClassName = CPlayerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CPlayerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPlayerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPlayerPanel");
    v6->pfnClassName = CPlayerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CPlayerPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CPlayerPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CPlayerPanel::PanelMessageFunc_OnKickButtonPressed::InitVar(a1: (int)&savedregs);
  CPlayerPanel::PanelMessageFunc_OnBanButtonPressed::InitVar(a1: (int)&savedregs);
  CPlayerPanel::PanelMessageFunc_KickSelectedPlayers::InitVar(a1: (int)&savedregs);
  CPlayerPanel::PanelMessageFunc_AddBanByID::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "Players list");
  else
    v8 = nullptr;
  this->m_pPlayerListPanel = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "#Player_Panel_Name", a5: 200, a6: 2);
  this->m_pPlayerListPanel->AddColumnHeader(
    this: this->m_pPlayerListPanel,
    a2: 1,
    a3: "authid",
    a4: "#Player_Panel_ID",
    a5: 100,
    a6: 0);
  this->m_pPlayerListPanel->AddColumnHeader(
    this: this->m_pPlayerListPanel,
    a2: 2,
    a3: "ping",
    a4: "#Player_Panel_Ping",
    a5: 50,
    a6: 0);
  this->m_pPlayerListPanel->AddColumnHeader(
    this: this->m_pPlayerListPanel,
    a2: 3,
    a3: "loss",
    a4: "#Player_Panel_Loss",
    a5: 50,
    a6: 0);
  this->m_pPlayerListPanel->AddColumnHeader(
    this: this->m_pPlayerListPanel,
    a2: 4,
    a3: "frags",
    a4: "#Player_Panel_Frags",
    a5: 50,
    a6: 0);
  this->m_pPlayerListPanel->AddColumnHeader(
    this: this->m_pPlayerListPanel,
    a2: 5,
    a3: "time",
    a4: "#Player_Panel_Time",
    a5: 75,
    a6: 0);
  this->m_pPlayerListPanel->SetSortFunc(this: this->m_pPlayerListPanel, a2: 5, a3: PlayerTimeCompare);
  this->m_pPlayerListPanel->SetEmptyListText_2(this: this->m_pPlayerListPanel, a2: "#Player_Panel_No_Players");
  this->m_pPlayerListPanel->SetSortColumn(this: this->m_pPlayerListPanel, a2: 0);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "Kick",
            text: "#Player_Panel_Kick",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pKickButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Ban",
            text: "#Player_Panel_Ban",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pBanButton = v12;
  v13 = (CPlayerContextMenu *)operator new(nSize: 0x428u);
  if ( v13 != nullptr )
    v14 = CPlayerContextMenu::CPlayerContextMenu(this: v13, parent: this);
  else
    v14 = nullptr;
  this->m_pPlayerContextMenu = v14;
  v14->SetVisible(this: v14, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin/PlayerPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "KickPlayer");
  else
    v16 = nullptr;
  this->m_pKickButton->SetCommand(this: this->m_pKickButton, a2: v16);
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "BanPlayer");
  else
    v18 = nullptr;
  this->m_pBanButton->SetCommand(this: this->m_pBanButton, a2: v18);
  CPlayerPanel::OnItemSelected(this);
  this->m_flUpdateTime = 0.0;
  v19 = RemoteServer();
  CRemoteServer::AddServerMessageHandler(this: v19, handler: &this->IServerDataResponse, watch: "UpdatePlayers");
  return this;
}
