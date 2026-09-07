// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/banpanel.cpp
// Functions: 39
// ============================================================

#include "tracker\adminserver\banpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10004570
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100045A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x100045B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008950
// Name: public: static char const __near * CBanPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBanPanel::GetPanelClassName()
{
  return "CBanPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10008960
// Name: protected: virtual void CBanPanel::OnPageShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnPageShow(CBanPanel *this)
{
  vgui::PropertyPage::OnPageHide(this);
  this->OnItemSelected(this);
  if ( !this->m_bPageViewed )
  {
    this->m_bPageViewed = true;
    this->m_flUpdateTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100089A0
// Name: public: virtual void CBanPanel::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnResetData(CBanPanel *this)
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
  CRemoteServer::RequestValue(this: v3, requester: v4, variable: "banlist");
  this->m_flUpdateTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 300.0;
}

//------------------------------------------------------------------------------
// Address: 0x100089E0
// Name: protected: virtual void CBanPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnThink(CBanPanel *this)
{
  long double m_flUpdateTime; // [esp+4h] [ebp-8h]

  m_flUpdateTime = this->m_flUpdateTime;
  if ( g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) > m_flUpdateTime )
    this->OnResetData(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008A20
// Name: private: virtual void CBanPanel::AddBan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::AddBan(CBanPanel *this)
{
  CDialogAddBan *v2; // eax
  CDialogAddBan *v3; // esi

  v2 = (CDialogAddBan *)operator new(nSize: 0x230u);
  if ( v2 != nullptr )
    v3 = CDialogAddBan::CDialogAddBan(this: v2, parent: this);
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CDialogAddBan::Activate(this: v3, type: "addban", player: defaultValue, authid: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x10008A70
// Name: private: virtual void CBanPanel::RemoveBan(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBanPanel::RemoveBan(CBanPanel *this@<ecx>, int a2@<edi>)
{
  vgui::ListPanel *m_pBanListPanel; // ecx
  int (__thiscall *GetSelectedItem)(vgui::ListPanel *, int); // edx
  int v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  vgui::ILocalize_vtbl *v8; // esi
  const char *String; // eax
  vgui::ILocalize_vtbl *v10; // esi
  int v11; // eax
  vgui::QueryBox *v12; // esi
  const wchar_t *v13; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v15; // ebx
  const char *v16; // eax
  KeyValues *v17; // eax
  wchar_t message[256]; // [esp+4h] [ebp-404h] BYREF
  wchar_t id[256]; // [esp+204h] [ebp-204h] BYREF
  CBanPanel *v21; // [esp+404h] [ebp-4h]

  m_pBanListPanel = this->m_pBanListPanel;
  GetSelectedItem = m_pBanListPanel->GetSelectedItem;
  v21 = this;
  v5 = GetSelectedItem(this: m_pBanListPanel, a2: 0);
  if ( v5 != -1 )
  {
    v6 = this->m_pBanListPanel->GetItem(this: this->m_pBanListPanel, a2: v5);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = g_pVGuiLocalize->__vftable;
      String = KeyValues::GetString(this: v6, keyName: "id", defaultValue: defaultValue);
      ((void (__thiscall *)(vgui::ILocalize *, const char *, wchar_t *, int, int))v8->ConvertANSIToUnicode)(
        a1: g_pVGuiLocalize,
        a2: String,
        a3: id,
        a4: 512,
        a5: a2);
      v10 = g_pVGuiLocalize->__vftable;
      v11 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
              a1: g_pVGuiLocalize,
              a2: "#Ban_Remove_Msg",
              a3: 1,
              a4: id);
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v10->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: message,
        a3: 512,
        a4: v11);
      v12 = (vgui::QueryBox *)operator new(nSize: 0x244u);
      if ( v12 != nullptr )
      {
        v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Ban_Title_Remove");
        Box = vgui::QueryBox::QueryBox(this: v12, wszTitle: v13, wszQueryText: message, parent: nullptr);
      }
      else
      {
        Box = nullptr;
      }
      v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v15 != nullptr )
      {
        v16 = KeyValues::GetString(this: v7, keyName: "id", defaultValue: defaultValue);
        v17 = KeyValues::KeyValues(this: v15, setName: "removebanbyid", firstKey: "id", firstValue: v16);
      }
      else
      {
        v17 = nullptr;
      }
      vgui::QueryBox::SetOKCommand(this: Box, keyValues: v17);
      Box->AddActionSignalTarget_2(this: Box, a2: v21);
      Box->DoModal_2(this: Box, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008BC0
// Name: private: virtual void CBanPanel::ChangeBan(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::ChangeBan(CBanPanel *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  double Float; // st7
  CDialogCvarChange *v6; // eax
  CDialogCvarChange *v7; // esi
  const char *String; // eax
  char timeText[20]; // [esp+1Ch] [ebp-14h] BYREF

  v2 = this->m_pBanListPanel->GetSelectedItem(this: this->m_pBanListPanel, a2: 0);
  if ( v2 != -1 )
  {
    v3 = this->m_pBanListPanel->GetItem(this: this->m_pBanListPanel, a2: v2);
    v4 = v3;
    if ( v3 != nullptr )
    {
      Float = KeyValues::GetFloat(this: v3, keyName: "time", defaultValue: 0.0);
      _snprintf(string: timeText, count: 0x14u, format: "%0.2f", Float);
      v6 = (CDialogCvarChange *)operator new(nSize: 0x228u);
      if ( v6 != nullptr )
        v7 = CDialogCvarChange::CDialogCvarChange(this: v6, parent: this);
      else
        v7 = nullptr;
      v7->AddActionSignalTarget_2(this: v7, a2: this);
      v7->SetTitle_2(this: v7, a2: "#Ban_Title_Change", a3: true);
      String = KeyValues::GetString(this: v4, keyName: "id", defaultValue: defaultValue);
      CDialogCvarChange::Activate(
        this: v7,
        cvarName: String,
        curValue: timeText,
        type: "changeban",
        question: "#Ban_Change_Time");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008CA0
// Name: private: virtual void CBanPanel::OnCvarChangeValue(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnCvarChangeValue(CBanPanel *this, KeyValues *kv)
{
  const char *String; // ebx
  const char *v4; // eax

  String = KeyValues::GetString(this: kv, keyName: "player", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: kv, keyName: "value", defaultValue: "0");
  this->ChangeBanTimeByID(this, a2: String, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10008CF0
// Name: private: virtual void CBanPanel::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnItemSelected(CBanPanel *this)
{
  int v2; // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx

  v2 = this->m_pBanListPanel->GetSelectedItem(this: this->m_pBanListPanel, a2: 0);
  SetEnabled = this->m_pRemoveButton->SetEnabled;
  if ( v2 == -1 )
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pChangeButton->SetEnabled(this: this->m_pChangeButton, a2: false);
  }
  else
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    this->m_pChangeButton->SetEnabled(this: this->m_pChangeButton, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008D50
// Name: private: virtual void CBanPanel::ImportBanList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::ImportBanList(CBanPanel *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi

  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "#Ban_Find_Ban_File",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.cfg",
    filterName: "#Config_files",
    bActive: true,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.*",
    filterName: "#All_files",
    bActive: false,
    pFilterInfo: nullptr);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: true);
  v3->Activate(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10008DC0
// Name: private: virtual void CBanPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnFileSelected(CBanPanel *this, char *fullpath)
{
  _iobuf *v3; // edi
  const char *Token; // eax
  TokenLine v5; // [esp+8h] [ebp-1308h] BYREF
  _iobuf string[8]; // [esp+1210h] [ebp-100h] BYREF

  TokenLine::TokenLine(this: &v5);
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  v3 = fopen(file: (_iobuf *)fullpath, mode: "rb");
  while ( feof(stream: v3) == 0 )
  {
    if ( fgets(string, count: 255, str: v3) == nullptr )
      break;
    TokenLine::SetLine(this: &v5, newLine: (const char *)string);
    if ( TokenLine::CountToken(this: &v5) == 3 )
    {
      Token = TokenLine::GetToken(this: &v5, i: 2);
      this->ChangeBanTimeByID(this, a2: Token, a3: "0");
    }
  }
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 0);
  if ( v3 != nullptr )
    fclose(stream: v3);
  TokenLine::~TokenLine(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x10008F20
// Name: public: virtual struct vgui::PanelMessageMap __near * CBanPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBanPanel::GetMessageMap(CBanPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBanPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBanPanel::GetMessageMap'::`2'::s_pMap;
  `CBanPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
  `CBanPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008F50
// Name: public: virtual struct PanelAnimationMap __near * CBanPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBanPanel::GetAnimMap(CBanPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBanPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10008F60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBanPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBanPanel::GetKBMap(CBanPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBanPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBanPanel::GetKBMap'::`2'::s_pMap;
  `CBanPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBanPanel");
  `CBanPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008FD0
// Name: protected: virtual void CBanPanel::OnServerDataResponse(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBanPanel::OnServerDataResponse(CBanPanel *this@<ecx>, int a2@<edi>, float value, char *response)
{
  char *v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  bool v8; // zf
  wchar_t *(__thiscall *Find)(ILocalize *, const char *); // eax
  const wchar_t *v10; // eax
  const wchar_t *v11; // eax
  int v12; // eax
  char id[64]; // [esp+10h] [ebp-54h] BYREF
  char v15; // [esp+50h] [ebp-14h] BYREF
  char v16; // [esp+54h] [ebp-10h] BYREF
  char v17; // [esp+58h] [ebp-Ch] BYREF
  CBanPanel *v18; // [esp+5Ch] [ebp-8h]
  int item; // [esp+60h] [ebp-4h] BYREF

  v18 = this;
  if ( _V_stricmp(s1: (const char *)LODWORD(value), s2: "banlist") == 0 )
  {
    (*(void (__thiscall **)(vgui::Panel::NAV_DIRECTION))(*(_DWORD *)this->m_LastNavDirection + 972))(a1: this->m_LastNavDirection);
    item = 0;
    value = 0.0;
    memset(id, 0, sizeof(id));
    v5 = response;
    if ( sscanf(string: response, format: "%i %s : %f min\n", &item, id, &value) == 3 )
    {
      do
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(this: v6, setName: "ban");
        else
          v7 = nullptr;
        v8 = sscanf(string: id, format: "%d.%d.%d.%d", &v15, &v16, &v17, &response) == 4;
        Find = g_pVGuiLocalize->Find;
        if ( v8 )
        {
          v10 = (const wchar_t *)((int (__stdcall *)(const char *, int))Find)(a1: "#Ban_IP", a2);
          if ( v10 == nullptr )
            v10 = L"IP Address";
        }
        else
        {
          v10 = (const wchar_t *)((int (__stdcall *)(const char *, int))Find)(a1: "#Ban_Auth_ID", a2);
          if ( v10 == nullptr )
            v10 = L"AuthID";
        }
        KeyValues::SetWString(this: v7, keyName: "type", value: v10);
        KeyValues::SetString(this: v7, keyName: "id", value: id);
        if ( value <= 0.0 )
        {
          v11 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Ban_Permanent");
          if ( v11 == nullptr )
            v11 = L"permanent";
          KeyValues::SetWString(this: v7, keyName: "time", value: v11);
        }
        else
        {
          KeyValues::SetFloat(this: v7, keyName: "time", value);
        }
        a2 = 0;
        (*(void (__thiscall **)(vgui::Panel::NAV_DIRECTION, KeyValues *, _DWORD, _DWORD))(*(_DWORD *)v18->m_LastNavDirection
                                                                                        + 916))(
          a1: v18->m_LastNavDirection,
          a2: v7,
          a3: 0,
          a4: 0);
        strchr(string: v5, chr: 0xAu);
        if ( v12 == 0 )
          break;
        v5 = (char *)(v12 + 1);
      }
      while ( sscanf(string: (char *)(v12 + 1), format: "%i %s : %f min\n", &item, id, &value) == 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009180
// Name: private: virtual void CBanPanel::RemoveBanByID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::RemoveBanByID(CBanPanel *this, char *id)
{
  char *v2; // esi
  bool v4; // zf
  const char *v5; // eax
  CRemoteServer *v6; // eax
  CRemoteServer *v7; // eax
  const char *v8; // [esp-4h] [ebp-218h]
  char cmd[512]; // [esp+8h] [ebp-20Ch] BYREF
  char v10; // [esp+208h] [ebp-Ch] BYREF
  char v11; // [esp+20Ch] [ebp-8h] BYREF
  char v12; // [esp+210h] [ebp-4h] BYREF

  v2 = id;
  if ( id != nullptr && *id != 0 )
  {
    v4 = sscanf(string: id, format: "%d.%d.%d.%d", &v11, &v12, &v10, &id) == 4;
    v5 = "removeip";
    if ( !v4 )
      v5 = "removeid";
    _snprintf(string: cmd, count: 0x1FFu, format: "%s %s\n", v5, v2);
    v6 = RemoteServer();
    CRemoteServer::SendCommand(this: v6, commandString: cmd);
    if ( sscanf(string: v2, format: "%d.%d.%d.%d", &v10, &v12, &v11, &id) == 4 )
      v8 = "writeip";
    else
      v8 = "writeid";
    v7 = RemoteServer();
    CRemoteServer::SendCommand(this: v7, commandString: v8);
    this->OnResetData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009250
// Name: private: virtual void CBanPanel::ChangeBanTimeByID(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::ChangeBanTimeByID(CBanPanel *this, char *id, const char *newtime)
{
  char *v3; // esi
  const char *v5; // edi
  bool v6; // zf
  const char *v7; // eax
  CRemoteServer *v8; // eax
  CRemoteServer *v9; // eax
  const char *v10; // [esp-4h] [ebp-214h]
  char cmd[512]; // [esp+8h] [ebp-208h] BYREF
  char v12; // [esp+208h] [ebp-8h] BYREF
  char v13; // [esp+20Ch] [ebp-4h] BYREF

  v3 = id;
  if ( id != nullptr && *id != 0 )
  {
    v5 = newtime;
    if ( newtime == nullptr || atof(nptr: newtime) < 0.001 )
      v5 = "0";
    v6 = sscanf(string: v3, format: "%d.%d.%d.%d", &v13, &v12, &newtime, &id) == 4;
    v7 = "addip";
    if ( !v6 )
      v7 = "banid";
    _snprintf(string: cmd, count: 0x1FFu, format: "%s %s %s\n", v7, v5, v3);
    v8 = RemoteServer();
    CRemoteServer::SendCommand(this: v8, commandString: cmd);
    if ( sscanf(string: v3, format: "%d.%d.%d.%d", &v12, &v13, &newtime, &id) == 4 )
      v10 = "writeip";
    else
      v10 = "writeid";
    v9 = RemoteServer();
    CRemoteServer::SendCommand(this: v9, commandString: v10);
    this->OnResetData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009340
// Name: public: static void CBanPanel::PanelMessageFunc_AddBan::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_AddBan::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_AddBan::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_AddBan::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRawLogPanel::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "addban";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100093D0
// Name: public: static void CBanPanel::PanelMessageFunc_RemoveBan::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_RemoveBan::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_RemoveBan::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_RemoveBan::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "removeban";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009460
// Name: public: static void CBanPanel::PanelMessageFunc_ChangeBan::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_ChangeBan::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_ChangeBan::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_ChangeBan::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "changeban";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100094F0
// Name: public: static void CBanPanel::PanelMessageFunc_RemoveBanByID::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_RemoveBanByID::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_RemoveBanByID::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_RemoveBanByID::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVarListPropertyPage::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "removebanbyid";
    v4.func = v2;
    v4.firstParamName = "id";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009590
// Name: public: static void CBanPanel::PanelMessageFunc_ChangeBanTimeByID::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_ChangeBanTimeByID::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_ChangeBanTimeByID::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_ChangeBanTimeByID::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CPlayerPanel::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
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
// Address: 0x10009630
// Name: public: static void CBanPanel::PanelMessageFunc_OnCvarChangeValue::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_OnCvarChangeValue::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_OnCvarChangeValue::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_OnCvarChangeValue::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Label::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "CvarChangeValue";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100096C0
// Name: public: static void CBanPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
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
// Address: 0x10009760
// Name: public: static void CBanPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Label::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
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
// Address: 0x100097F0
// Name: public: static void CBanPanel::PanelMessageFunc_ImportBanList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_ImportBanList::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_ImportBanList::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_ImportBanList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "importban";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009880
// Name: public: static void CBanPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBanPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBanPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBanPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBanPanel::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "FileSelected";
    v4.func = v2;
    v4.firstParamName = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009920
// Name: public: CBanPanel::CBanPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBanPanel *__thiscall CBanPanel::CBanPanel(CBanPanel *this, vgui::Panel *parent, const char *name)
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
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  CBanContextMenu *v25; // eax
  CBanContextMenu *v26; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&IServerDataResponse::`vftable';
  this->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBanPanel_vtbl *)&CBanPanel::`vftable'{for `vgui::PropertyPage'};
  this->IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CBanPanel::`vftable'{for `IServerDataResponse'};
  if ( `CBanPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBanPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBanPanel");
    v4->pfnClassName = CBanPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CBanPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBanPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBanPanel");
    v5->pfnClassName = CBanPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CBanPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBanPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBanPanel");
    v6->pfnClassName = CBanPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CBanPanel::PanelMessageFunc_AddBan::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_RemoveBan::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_ChangeBan::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_RemoveBanByID::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_ChangeBanTimeByID::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_OnCvarChangeValue::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_ImportBanList::InitVar(a1: (int)&savedregs);
  CBanPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "BanList");
  else
    v8 = nullptr;
  this->m_pBanListPanel = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "type", a4: "#Ban_List_Type", a5: 150, a6: 0);
  this->m_pBanListPanel->AddColumnHeader(
    this: this->m_pBanListPanel,
    a2: 1,
    a3: "id",
    a4: "#Ban_List_ID",
    a5: 200,
    a6: 0);
  this->m_pBanListPanel->AddColumnHeader(
    this: this->m_pBanListPanel,
    a2: 2,
    a3: "time",
    a4: "#Ban_List_Time",
    a5: 200,
    a6: 0);
  this->m_pBanListPanel->SetSortColumn(this: this->m_pBanListPanel, a2: 2);
  this->m_pBanListPanel->SetEmptyListText_2(this: this->m_pBanListPanel, a2: "#Ban_List_Empty");
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "Add",
            text: "#Ban_List_Add",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pAddButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Remove",
            text: "#Ban_List_Remove",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pRemoveButton = v12;
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "Change",
            text: "#Ban_List_Edit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pChangeButton = v14;
  v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "Import",
            text: "#Ban_List_Import",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  this->m_pImportButton = v16;
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "addban");
  else
    v18 = nullptr;
  this->m_pAddButton->SetCommand(this: this->m_pAddButton, a2: v18);
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "removeban");
  else
    v20 = nullptr;
  this->m_pRemoveButton->SetCommand(this: this->m_pRemoveButton, a2: v20);
  v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v21 != nullptr )
    v22 = KeyValues::KeyValues(this: v21, setName: "changeban");
  else
    v22 = nullptr;
  this->m_pChangeButton->SetCommand(this: this->m_pChangeButton, a2: v22);
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    v24 = KeyValues::KeyValues(this: v23, setName: "importban");
  else
    v24 = nullptr;
  this->m_pImportButton->SetCommand(this: this->m_pImportButton, a2: v24);
  v25 = (CBanContextMenu *)operator new(nSize: 0x428u);
  if ( v25 != nullptr )
    v26 = CBanContextMenu::CBanContextMenu(this: v25, parent: this);
  else
    v26 = nullptr;
  this->m_pBanContextMenu = v26;
  v26->SetVisible(this: v26, a2: false);
  this->m_flUpdateTime = 0.0;
  this->m_bPageViewed = false;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin/BanPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000C240
// Name: protected: virtual void CBanPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnKeyCodeTyped(CVarListPropertyPage *this, ButtonCode_t code)
{
  if ( code == KEY_F5 )
    this->OnResetData(this);
  else
    vgui::PropertyPage::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10030380
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x1004B820
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  wchar_t v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x1004CDA0
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x1004D2C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D2F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x1004D300
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F810
// Name: private: virtual void CBanPanel::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBanPanel::OnOpenContextMenu(vgui::TreeView *this, int itemIndex)
{
  ;
}
