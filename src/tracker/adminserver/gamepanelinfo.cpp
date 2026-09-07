// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/gamepanelinfo.cpp
// Functions: 22
// ============================================================

#include "tracker\adminserver\gamepanelinfo.h"

//------------------------------------------------------------------------------
// Address: 0x10001610
// Name: public: static char const __near * CGamePanelInfo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGamePanelInfo::GetPanelClassName()
{
  return "CGamePanelInfo";
}

//------------------------------------------------------------------------------
// Address: 0x10001620
// Name: protected: void CGamePanelInfo::SetNewTitle(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::SetNewTitle(CGamePanelInfo *this, bool connectionFailed, const char *additional_text)
{
  const char *v4; // ebx
  vgui::ILocalize_vtbl *v5; // esi
  int v6; // eax
  int v7; // [esp-4h] [ebp-410h]
  wchar_t title[256]; // [esp+Ch] [ebp-400h] BYREF
  wchar_t serverName[256]; // [esp+20Ch] [ebp-200h] BYREF

  v4 = "#Game_RemoteTitle";
  if ( this->m_bRemoteServer )
  {
    if ( connectionFailed )
      v4 = "#Game_RemoteTitle_Failed";
  }
  else
  {
    v4 = "Game_LocalTitle";
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: additional_text, a3: serverName, a4: 512);
  v5 = g_pVGuiLocalize->__vftable;
  v6 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
         a1: g_pVGuiLocalize,
         a2: v4,
         a3: 1,
         a4: serverName);
  ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v5->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: title,
    a3: 512,
    a4: v6);
  ((void (__thiscall *)(CGamePanelInfo *, wchar_t *, int, int))this->SetTitle)(a1: this, a2: title, a3: 1, a4: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100016C0
// Name: protected: virtual void CGamePanelInfo::OnUpdateTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnUpdateTitle(CGamePanelInfo *this)
{
  const char *Hostname; // eax

  Hostname = CServerInfoPanel::GetHostname(this: this->m_pServerInfoPanel);
  CGamePanelInfo::SetNewTitle(this, connectionFailed: false, additional_text: Hostname);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: public: virtual void CGamePanelInfo::SetAsRemoteServer(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::SetAsRemoteServer(CGamePanelInfo *this, bool remote)
{
  LOBYTE(this->m_SkipChild.m_iPanelID) = remote;
}

//------------------------------------------------------------------------------
// Address: 0x10001710
// Name: protected: virtual void CGamePanelInfo::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnTick(CGamePanelInfo *this)
{
  CRemoteServer *v1; // eax

  v1 = RemoteServer();
  CRemoteServer::ProcessServerResponse(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: protected: virtual void CGamePanelInfo::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnCommand(CGamePanelInfo *this, const char *command)
{
  CRemoteServer *v3; // eax
  void (__thiscall *Close)(vgui::Frame *); // edx

  if ( _V_stricmp(s1: command, s2: "stop2") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    v3 = RemoteServer();
    CRemoteServer::SendCommand(this: v3, commandString: "quit");
    Close = this->Close;
    this->m_bShuttingDown = true;
    Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: protected: void CGamePanelInfo::OnStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnStop(CGamePanelInfo *this)
{
  vgui::QueryBox *v2; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::QueryBox *)operator new(nSize: 0x244u);
  if ( v2 != nullptr )
    Box = vgui::QueryBox::QueryBox(
            this: v2,
            title: "#Game_Stop_Server_Title",
            queryText: "#Game_Restart_Server",
            parent: nullptr);
  else
    Box = nullptr;
  Box->AddActionSignalTarget_2(this: Box, a2: this);
  Box->SetOKButtonText_2(this: Box, a2: "#Game_Stop_Server");
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "stop2");
  else
    v5 = nullptr;
  vgui::QueryBox::SetOKCommand(this: Box, keyValues: v5);
  Box->ShowWindow(this: Box, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: protected: virtual void CGamePanelInfo::OnHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnHelp(CGamePanelInfo *this)
{
  g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: "Admin\\Admin.html");
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: protected: virtual void CGamePanelInfo::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnClose(CGamePanelInfo *this)
{
  if ( this->m_bRemoteServer || this->m_bShuttingDown )
    vgui::Frame::OnClose(this);
  else
    CGamePanelInfo::OnStop(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: protected: virtual void CGamePanelInfo::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::ActivateBuildMode(CGamePanelInfo *this)
{
  vgui::Panel *v1; // eax
  void *v2; // eax

  v1 = this->m_pDetailsSheet->GetActivePage(this: this->m_pDetailsSheet);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 860))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: protected: virtual void CGamePanelInfo::OnRestartServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnRestartServer(CGamePanelInfo *this)
{
  CRemoteServer *v2; // eax
  void (__thiscall *Close)(vgui::Frame *); // edx

  v2 = RemoteServer();
  CRemoteServer::SendCommand(this: v2, commandString: "quit");
  Close = this->Close;
  this->m_bShuttingDown = true;
  Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x100018C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CGamePanelInfo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGamePanelInfo::GetMessageMap(CGamePanelInfo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGamePanelInfo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGamePanelInfo::GetMessageMap'::`2'::s_pMap;
  `CGamePanelInfo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGamePanelInfo");
  `CGamePanelInfo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: virtual struct PanelAnimationMap __near * CGamePanelInfo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGamePanelInfo::GetAnimMap(CGamePanelInfo *this)
{
  return FindOrAddPanelAnimationMap(className: "CGamePanelInfo");
}

//------------------------------------------------------------------------------
// Address: 0x10001900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGamePanelInfo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGamePanelInfo::GetKBMap(CGamePanelInfo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGamePanelInfo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGamePanelInfo::GetKBMap'::`2'::s_pMap;
  `CGamePanelInfo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGamePanelInfo");
  `CGamePanelInfo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001970
// Name: protected: void CGamePanelInfo::OnMasterOutOfDate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnMasterOutOfDate(CGamePanelInfo *this, const char *msg)
{
  vgui::DHANDLE<vgui::QueryBox> *p_m_hOutOfDateQueryBox; // ebx
  void *v3; // esp
  vgui::QueryBox *v4; // eax
  vgui::QueryBox *Box; // eax
  vgui::Panel *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::QueryBox *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  KeyValues *v12; // [esp-4h] [ebp-14h]
  char v13[12]; // [esp+0h] [ebp-10h] BYREF
  CGamePanelInfo *v14; // [esp+Ch] [ebp-4h]

  p_m_hOutOfDateQueryBox = &this->m_hOutOfDateQueryBox;
  v14 = this;
  if ( vgui::PHandle::Get(this: &this->m_hOutOfDateQueryBox) != nullptr )
  {
    v11 = vgui::PHandle::Get(this: p_m_hOutOfDateQueryBox);
    v11->__vftable[1].OnTick(this: v11);
  }
  else
  {
    v3 = alloca(strlen(msg) + 32);
    _snprintf(string: v13, count: strlen(msg) + 32, format: "%s\n\nDo you wish to shutdown now?\n", msg);
    v4 = (vgui::QueryBox *)operator new(nSize: 0x244u);
    if ( v4 != nullptr )
      Box = vgui::QueryBox::QueryBox(this: v4, title: "Server restart pending", queryText: v13, parent: nullptr);
    else
      Box = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_hOutOfDateQueryBox, pPanel: Box);
    v6 = vgui::PHandle::Get(this: p_m_hOutOfDateQueryBox);
    v6->AddActionSignalTarget_2(this: v6, a2: v14);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "RestartServer");
    else
      v8 = nullptr;
    v12 = v8;
    v9 = (vgui::QueryBox *)vgui::PHandle::Get(this: p_m_hOutOfDateQueryBox);
    vgui::QueryBox::SetOKCommand(this: v9, keyValues: v12);
    v10 = vgui::PHandle::Get(this: p_m_hOutOfDateQueryBox);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v10->__vftable[1].GetBorder)(a1: v10, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A80
// Name: protected: void CGamePanelInfo::OnMasterRequestRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::OnMasterRequestRestart(CGamePanelInfo *this)
{
  vgui::QueryBox *v2; // eax
  vgui::QueryBox *Box; // eax
  vgui::Panel *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::QueryBox *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  KeyValues *v10; // [esp-4h] [ebp-Ch]

  if ( vgui::PHandle::Get(this: &this->m_hRestartQueryBox) != nullptr )
  {
    v9 = vgui::PHandle::Get(this: &this->m_hRestartQueryBox);
    v9->__vftable[1].OnTick(this: v9);
  }
  else
  {
    v2 = (vgui::QueryBox *)operator new(nSize: 0x244u);
    if ( v2 != nullptr )
      Box = vgui::QueryBox::QueryBox(
              this: v2,
              title: "Server restart needed",
              queryText: "Your server is out of date, and will not be listed\n"
              "on the master server until you restart.\n"
              "\n"
              "Do you wish to shutdown now?\n",
              parent: nullptr);
    else
      Box = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hRestartQueryBox, pPanel: Box);
    v4 = vgui::PHandle::Get(this: &this->m_hRestartQueryBox);
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "RestartServer");
    else
      v6 = nullptr;
    v10 = v6;
    v7 = (vgui::QueryBox *)vgui::PHandle::Get(this: &this->m_hRestartQueryBox);
    vgui::QueryBox::SetOKCommand(this: v7, keyValues: v10);
    v8 = vgui::PHandle::Get(this: &this->m_hRestartQueryBox);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v8->__vftable[1].GetBorder)(a1: v8, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: virtual void CGamePanelInfo::AddToConsole(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::AddToConsole(CGamePanelInfo *this, char *msg)
{
  int v3; // eax

  if ( *(_DWORD *)&this->m_InternalKeyCodePressed_register != 0 )
  {
    if ( *msg != 3 )
      goto LABEL_9;
    if ( strncmp(first: msg + 1, last: "MasterRequestRestart", count: 0x14u) == 0 )
    {
      CGamePanelInfo::OnMasterRequestRestart(this: (CGamePanelInfo *)((char *)this - 528));
      return;
    }
    if ( *msg == 3 && strncmp(first: msg + 1, last: "MasterOutOfDate", count: 0xFu) == 0 )
    {
      strstr(str1: (unsigned __int8 *)msg, str2: "MasterOutOfDate");
      if ( v3 != 0 )
        CGamePanelInfo::OnMasterOutOfDate(this: (CGamePanelInfo *)((char *)this - 528), msg: (const char *)(v3 + 15));
    }
    else
    {
LABEL_9:
      CRawLogPanel::DoInsertString(this: *(CRawLogPanel **)&this->m_InternalKeyCodePressed_register, str: msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: public: static void CGamePanelInfo::PanelMessageFunc_OnHelp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGamePanelInfo::PanelMessageFunc_OnHelp::InitVar(int a1@<ebp>)
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
  if ( !`CGamePanelInfo::PanelMessageFunc_OnHelp::InitVar'::`2'::bAdded )
  {
    `CGamePanelInfo::PanelMessageFunc_OnHelp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGamePanelInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "Help";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C70
// Name: public: static void CGamePanelInfo::PanelMessageFunc_OnRestartServer::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGamePanelInfo::PanelMessageFunc_OnRestartServer::InitVar(int a1@<ebp>)
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
  if ( !`CGamePanelInfo::PanelMessageFunc_OnRestartServer::InitVar'::`2'::bAdded )
  {
    `CGamePanelInfo::PanelMessageFunc_OnRestartServer::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CMapCycleEditDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGamePanelInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "RestartServer";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D00
// Name: public: static void CGamePanelInfo::PanelMessageFunc_OnUpdateTitle::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CGamePanelInfo::PanelMessageFunc_OnUpdateTitle::InitVar(int a1@<ebp>)
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
  if ( !`CGamePanelInfo::PanelMessageFunc_OnUpdateTitle::InitVar'::`2'::bAdded )
  {
    `CGamePanelInfo::PanelMessageFunc_OnUpdateTitle::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CGamePanelInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "UpdateTitle";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: CGamePanelInfo::CGamePanelInfo(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGamePanelInfo *__thiscall CGamePanelInfo::CGamePanelInfo(
        CGamePanelInfo *this,
        vgui::Panel *parent,
        const char *name,
        const char *mod)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::AnimatingImagePanel *v8; // eax
  vgui::AnimatingImagePanel *v9; // eax
  vgui::PropertySheet *v10; // eax
  vgui::PropertySheet *v11; // eax
  CPlayerPanel *v12; // eax
  CPlayerPanel *v13; // eax
  CBanPanel *v14; // eax
  CBanPanel *v15; // eax
  CRawLogPanel *v16; // eax
  CRawLogPanel *v17; // eax
  CServerConfigPanel *v18; // eax
  CServerConfigPanel *v19; // eax
  CGraphPanel *v20; // eax
  CGraphPanel *v21; // eax
  CServerInfoPanel *v22; // eax
  CServerInfoPanel *v23; // eax
  int v24; // eax
  CBudgetPanelContainer *v25; // eax
  CBudgetPanelContainer *m_pBudgetPanel; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->IManageServer::IBaseInterface::__vftable = (IManageServer_vtbl *)&IManageServer::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CGamePanelInfo_vtbl *)&CGamePanelInfo::`vftable'{for `vgui::Frame'};
  this->IManageServer::IBaseInterface::__vftable = (IManageServer_vtbl *)&CGamePanelInfo::`vftable'{for `IManageServer'};
  if ( `CGamePanelInfo::ChainToMap'::`2'::chained == 0 )
  {
    `CGamePanelInfo::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CGamePanelInfo");
    v5->pfnClassName = CGamePanelInfo::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CGamePanelInfo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGamePanelInfo::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CGamePanelInfo");
    v6->pfnClassName = CGamePanelInfo::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CGamePanelInfo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGamePanelInfo::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CGamePanelInfo");
    v7->pfnClassName = CGamePanelInfo::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CGamePanelInfo::PanelMessageFunc_OnHelp::InitVar(a1: (int)&savedregs);
  CGamePanelInfo::PanelMessageFunc_OnRestartServer::InitVar(a1: (int)&savedregs);
  CGamePanelInfo::PanelMessageFunc_OnUpdateTitle::InitVar(a1: (int)&savedregs);
  this->m_hRestartQueryBox.m_iPanelID = -1;
  this->m_hOutOfDateQueryBox.m_iPanelID = -1;
  vgui::Panel::SetSize(this, wide: 560, tall: 420);
  vgui::Panel::SetMinimumSize(this, wide: 560, tall: 420);
  *(_WORD *)&this->m_bRemoteServer = 0;
  v8 = (vgui::AnimatingImagePanel *)operator new(nSize: 0x178u);
  if ( v8 != nullptr )
    v9 = vgui::AnimatingImagePanel::AnimatingImagePanel(this: v8, parent: this, name: "AnAnimatingImagePanel");
  else
    v9 = nullptr;
  this->m_pAnimImagePanel = v9;
  v9->LoadAnimation(this: v9, a2: "resource\\steam\\g", a3: 12);
  this->m_pAnimImagePanel->SetVisible(this: this->m_pAnimImagePanel, a2: false);
  v10 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = vgui::PropertySheet::PropertySheet(this: v10, parent: this, panelName: "Panels", draggableTabs: false);
  else
    v11 = nullptr;
  this->m_pDetailsSheet = v11;
  v12 = (CPlayerPanel *)operator new(nSize: 0x1ACu);
  if ( v12 != nullptr )
    v13 = CPlayerPanel::CPlayerPanel(this: v12, parent: this, name: "Player List");
  else
    v13 = nullptr;
  this->m_pPlayerListPanel = v13;
  v14 = (CBanPanel *)operator new(nSize: 0x1BCu);
  if ( v14 != nullptr )
    v15 = CBanPanel::CBanPanel(this: v14, parent: this, name: "Ban List");
  else
    v15 = nullptr;
  this->m_pBanListPanel = v15;
  v16 = (CRawLogPanel *)operator new(nSize: 0x190u);
  if ( v16 != nullptr )
    v17 = CRawLogPanel::CRawLogPanel(this: v16, parent: this, name: "ServerLog");
  else
    v17 = nullptr;
  this->m_pServerLogPanel = v17;
  v18 = (CServerConfigPanel *)operator new(nSize: 0x1A0u);
  if ( v18 != nullptr )
    v19 = CServerConfigPanel::CServerConfigPanel(this: v18, parent: this, name: "ServerConfigPanel", mod);
  else
    v19 = nullptr;
  this->m_pServerConfigPanel = v19;
  v20 = (CGraphPanel *)operator new(nSize: 0x1C4u);
  if ( v20 != nullptr )
    v21 = CGraphPanel::CGraphPanel(this: v20, parent: this, name: "GraphsPanel");
  else
    v21 = nullptr;
  this->m_pGraphsPanel = v21;
  v22 = (CServerInfoPanel *)operator new(nSize: 0x1E0u);
  if ( v22 != nullptr )
    v23 = CServerInfoPanel::CServerInfoPanel(this: v22, parent: this, name: "ServerInfo");
  else
    v23 = nullptr;
  this->m_pServerInfoPanel = v23;
  v24 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v24 + 12))(a1: v24, a2: "-BudgetPanel", a3: 0) != 0 )
  {
    v25 = (CBudgetPanelContainer *)operator new(nSize: 0x194u);
    if ( v25 != nullptr )
      this->m_pBudgetPanel = CBudgetPanelContainer::CBudgetPanelContainer(this: v25, parent: this, name: "BudgetPanel");
    else
      this->m_pBudgetPanel = nullptr;
  }
  else
  {
    this->m_pBudgetPanel = nullptr;
  }
  this->m_pServerInfoPanel->AddActionSignalTarget_2(this: this->m_pServerInfoPanel, a2: this);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pServerInfoPanel,
    a3: "#Game_Main_Settings",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pServerConfigPanel,
    a3: "#Game_Configure",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pGraphsPanel,
    a3: "#Game_Server_Statistics",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pPlayerListPanel,
    a3: "#Game_Current_Players",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pBanListPanel,
    a3: "#Game_Bans",
    a4: nullptr,
    a5: false,
    a6: -1);
  m_pBudgetPanel = this->m_pBudgetPanel;
  if ( m_pBudgetPanel != nullptr )
    this->m_pDetailsSheet->AddPage(
      this: this->m_pDetailsSheet,
      a2: m_pBudgetPanel,
      a3: "#Game_Budgets",
      a4: nullptr,
      a5: false,
      a6: -1);
  this->m_pDetailsSheet->AddPage(
    this: this->m_pDetailsSheet,
    a2: this->m_pServerLogPanel,
    a3: "#Game_Console",
    a4: nullptr,
    a5: false,
    a6: -1);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "Admin\\DialogGamePanelInfo.res",
    dialogID: 0);
  CGamePanelInfo::SetNewTitle(this, connectionFailed: false, additional_text: name);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::EditablePanel::RequestFocus(this, direction: 0);
  vgui::Panel::MoveToFront(this);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "ResetData");
  else
    v28 = nullptr;
  vgui::Panel::PostMessage(this, target: this->m_pServerInfoPanel, message: v28, delay: 0.1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002200
// Name: public: virtual void CGamePanelInfo::ShowPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGamePanelInfo::ShowPage(CGamePanelInfo *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 132) + 952))(a1: (char *)this - 528);
}
