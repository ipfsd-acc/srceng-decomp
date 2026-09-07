// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/dialogs/roomtemplateeditdialog.cpp
// Functions: 31
// ============================================================

#include "missionchooser\vgui\dialogs\roomtemplateeditdialog.h"

//------------------------------------------------------------------------------
// Address: 0x1002E750
// Name: public: static char const __near * CRoomTemplateEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRoomTemplateEditDialog::GetPanelClassName()
{
  return "CRoomTemplateEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1002E760
// Name: public: virtual struct vgui::PanelMap_t __near * CRoomTemplateEditDialog::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CRoomTemplateEditDialog::GetPanelMap(CRoomTemplateEditDialog *this)
{
  return &CRoomTemplateEditDialog::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x1002E770
// Name: public: virtual void CRoomTemplateEditDialog::OnCheckOutFromP4(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnCheckOutFromP4(CRoomTemplateEditDialog *this, KeyValues *pKV)
{
  const char *String; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  String = KeyValues::GetString(this: pKV, keyName: "file", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( p4->OpenFileForEdit(this: p4, a2: String) )
    {
      if ( CRoomTemplate::SaveRoomTemplate(this: this->m_pRoomTemplate) == 0 )
        VGUIMessageBox(
          pParent: this,
          pTitle: "Save Error!",
          pMsg: "Checked out '%s' from Perforce, but failed to save file.",
          String);
    }
    else
    {
      VGUIMessageBox(pParent: this, pTitle: "P4 Error!", pMsg: "Failed to check out '%s' from Perforce.", String);
    }
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "UpdateCurrentTheme");
  else
    v5 = nullptr;
  this->PostActionSignal(this, a2: v5);
  this->OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002E810
// Name: public: virtual void CRoomTemplateEditDialog::OnSliderMoved(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnSliderMoved(CRoomTemplateEditDialog *this, vgui::Slider *pSlider)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  CRoomTemplate *m_pRoomTemplate; // ecx
  char buffer[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( pSlider == this->m_pSpawnWeightSlider )
  {
    v3 = this->m_pSpawnWeightSlider->GetValue(this: this->m_pSpawnWeightSlider);
    if ( v3 >= 5 )
    {
      v3 = 5;
    }
    else if ( v3 <= 0 )
    {
      v3 = 0;
    }
    this->m_pRoomTemplate->m_nSpawnWeight = v3;
    V_snprintf(pDest: buffer, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nSpawnWeight);
    this->m_pSpawnWeightValue->SetText(this: this->m_pSpawnWeightValue, a2: buffer);
  }
  else
  {
    v4 = this->m_pTilesYSlider->GetValue(this: this->m_pTilesYSlider);
    v5 = this->m_pTilesXSlider->GetValue(this: this->m_pTilesXSlider);
    m_pRoomTemplate = this->m_pRoomTemplate;
    m_pRoomTemplate->m_nTilesX = v5;
    m_pRoomTemplate->m_nTilesY = v4;
    V_snprintf(pDest: buffer, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nTilesX);
    this->m_pTilesXValue->SetText(this: this->m_pTilesXValue, a2: buffer);
    V_snprintf(pDest: buffer, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nTilesY);
    this->m_pTilesYValue->SetText(this: this->m_pTilesYValue, a2: buffer);
    CRoomTemplatePanel::SetRoomTemplate(this: this->m_pRoomTemplatePanel, pTemplate: this->m_pRoomTemplate);
    CToggleExitsPanel::SetRoomTemplatePanel(
      this: this->m_pToggleExitsPanel,
      pPanel: this->m_pRoomTemplatePanel,
      bForceUpdate: true);
    this->m_pRoomTemplatePanel->InvalidateLayout(this: this->m_pRoomTemplatePanel, a2: true, a3: false);
    this->m_pToggleExitsPanel->InvalidateLayout(this: this->m_pToggleExitsPanel, a2: false, a3: false);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E990
// Name: public: virtual void CRoomTemplateEditDialog::OnCheckButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnCheckButtonChecked(CRoomTemplateEditDialog *this, vgui::Panel *panel)
{
  void *v3; // eax
  void *v4; // esi
  char tag[128]; // [esp+8h] [ebp-80h] BYREF

  v3 = __RTDynamicCast(
         inptr: panel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::CheckButton `RTTI Type Descriptor',
         isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v3 + 856))(a1: v3, a2: tag, a3: 128);
    if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v4 + 1024))(a1: v4) != 0 )
      CRoomTemplate::AddTag(this: this->m_pRoomTemplate, szTag: tag);
    else
      CRoomTemplate::RemoveTag(this: this->m_pRoomTemplate, szTag: tag);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EA10
// Name: public: void CRoomTemplateEditDialog::DoPickVMF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::DoPickVMF(CRoomTemplateEditDialog *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  char template_dir[1024]; // [esp+8h] [ebp-400h] BYREF

  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Set Room Template",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  V_snprintf(
    pDest: template_dir,
    maxLen: 1024,
    pFormat: "%s\\tilegen\\roomtemplates\\%s",
    g_gamedir,
    this->m_pRoomTemplate->m_pLevelTheme->m_szName);
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: template_dir);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.vmf",
    filterName: "Map file (*.vmf)",
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x1002EAB0
// Name: public: void CRoomTemplateEditDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnFileSelected(CRoomTemplateEditDialog *this, const char *fullpath)
{
  const char *v3; // edi
  char *v4; // ebx
  char *v5; // eax
  int v6; // edi
  int v7; // eax
  CRoomTemplate *m_pRoomTemplate; // ecx
  char themeName[260]; // [esp+8h] [ebp-2A0h] BYREF
  char roomName[260]; // [esp+10Ch] [ebp-19Ch] BYREF
  char szBaseRoom[128]; // [esp+210h] [ebp-98h] BYREF
  char width[12]; // [esp+290h] [ebp-18h] BYREF
  char height[12]; // [esp+29Ch] [ebp-Ch] BYREF
  int height_digits; // [esp+2B0h] [ebp+8h]

  v3 = _V_strstr(s1: fullpath, search: this->m_pRoomTemplate->m_pLevelTheme->m_szName);
  if ( v3 != nullptr )
  {
    if ( CLevelTheme::SplitThemeAndRoom(
           pszFullName: v3,
           szThemeOut: themeName,
           nThemeOutSize: 260,
           szRoomOut: roomName,
           nRoomOutSize: 260) != 0 )
    {
      this->m_pRoomTemplateNameEdit->SetText(this: this->m_pRoomTemplateNameEdit, a2: roomName);
      V_FileBase(in: roomName, out: szBaseRoom, maxlen: 128);
      v4 = V_stristr(pStr: szBaseRoom, pSearch: "x");
      v5 = V_stristr(pStr: szBaseRoom, pSearch: "_");
      if ( v4 != nullptr && v5 != nullptr )
      {
        height_digits = v5 - v4 - 1;
        V_strncpy(pDest: width, pSrc: szBaseRoom, maxLen: v4 - szBaseRoom + 1);
        width[v4 - szBaseRoom] = 0;
        V_strncpy(pDest: height, pSrc: v4 + 1, maxLen: height_digits + 1);
        height[height_digits] = 0;
        v6 = atoi(nptr: height);
        v7 = atoi(nptr: width);
        m_pRoomTemplate = this->m_pRoomTemplate;
        m_pRoomTemplate->m_nTilesX = v7;
        m_pRoomTemplate->m_nTilesY = v6;
        this->m_pSpawnWeightSlider->SetValue(
          this: this->m_pSpawnWeightSlider,
          a2: this->m_pRoomTemplate->m_nSpawnWeight,
          a3: true);
        this->m_pTilesXSlider->SetValue(this: this->m_pTilesXSlider, a2: this->m_pRoomTemplate->m_nTilesX, a3: true);
        this->m_pTilesYSlider->SetValue(this: this->m_pTilesYSlider, a2: this->m_pRoomTemplate->m_nTilesY, a3: true);
      }
    }
    else
    {
      _Warning(a1: "Failed to SplitThemeAndRoom while selecting file %s\n", v3);
    }
  }
  else
  {
    _Warning(
      a1: "Failed to pull theme name out of selected file.  Make sure vmf file is in the correct folder under tilegen/roomtemplates.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC60
// Name: public: char const __near * CRoomTemplateEditDialog::GetVMFFilename(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CRoomTemplateEditDialog::GetVMFFilename(CRoomTemplateEditDialog *this)
{
  V_snprintf(
    pDest: buffer_0,
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s",
    this->m_pRoomTemplate->m_pLevelTheme->m_szName,
    this->m_pRoomTemplate->m_FullName);
  return buffer_0;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC90
// Name: public: virtual void CRoomTemplateEditDialog::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnTextChanged(CRoomTemplateEditDialog *this, vgui::ComboBox *pPanel)
{
  vgui::ComboBox *v3; // eax

  if ( pPanel == this->m_pTileTypeBox )
  {
    v3 = (vgui::ComboBox *)__RTDynamicCast(
                             inptr: pPanel,
                             VfDelta: 0,
                             SrcType: &vgui::Panel `RTTI Type Descriptor',
                             TargetType: &vgui::ComboBox `RTTI Type Descriptor',
                             isReference: 0);
    if ( v3 != nullptr )
      this->m_pRoomTemplate->m_nTileType = vgui::ComboBox::GetActiveItem(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ECF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRoomTemplateEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRoomTemplateEditDialog::GetMessageMap(CRoomTemplateEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRoomTemplateEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplateEditDialog::GetMessageMap'::`2'::s_pMap;
  `CRoomTemplateEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
  `CRoomTemplateEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED20
// Name: public: virtual struct PanelAnimationMap __near * CRoomTemplateEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRoomTemplateEditDialog::GetAnimMap(CRoomTemplateEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CRoomTemplateEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1002ED30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRoomTemplateEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRoomTemplateEditDialog::GetKBMap(CRoomTemplateEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRoomTemplateEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplateEditDialog::GetKBMap'::`2'::s_pMap;
  `CRoomTemplateEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplateEditDialog");
  `CRoomTemplateEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED90
// Name: public: void CRoomTemplateEditDialog::EditExit(int,int,enum ExitDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::EditExit(
        CRoomTemplateEditDialog *this,
        int iXPos,
        int iYPos,
        ExitDirection_t dir)
{
  int i; // ebx
  CRoomTemplateExit *v6; // esi
  CExitEditDialog *v7; // eax
  CExitEditDialog *v8; // eax

  for ( i = this->m_pRoomTemplate->m_Exits.m_Size - 1; i >= 0; --i )
  {
    v6 = this->m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[i];
    if ( v6->m_iXPos == iXPos && v6->m_iYPos == iYPos && dir == v6->m_ExitDirection )
    {
      v7 = (CExitEditDialog *)operator new(nSize: 0x228u);
      if ( v7 != nullptr )
        v8 = CExitEditDialog::CExitEditDialog(
               this: v7,
               parent: this,
               name: "ExitEditDialog",
               pRoomTemplate: this->m_pRoomTemplate,
               pExit: v6);
      else
        v8 = nullptr;
      v8->DoModal(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE50
// Name: public: static void CRoomTemplateEditDialog::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateEditDialog::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateEditDialog::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateEditDialog::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EEF0
// Name: public: static void CRoomTemplateEditDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateEditDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateEditDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateEditDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EF90
// Name: public: static void CRoomTemplateEditDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateEditDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateEditDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateEditDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F030
// Name: public: static void CRoomTemplateEditDialog::PanelMessageFunc_OnCheckOutFromP4::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateEditDialog::PanelMessageFunc_OnCheckOutFromP4::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateEditDialog::PanelMessageFunc_OnCheckOutFromP4::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateEditDialog::PanelMessageFunc_OnCheckOutFromP4::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "CheckOutFromP4";
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
// Address: 0x1002F0C0
// Name: public: static void CRoomTemplateEditDialog::PanelMessageFunc_OnAddToP4::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateEditDialog::PanelMessageFunc_OnAddToP4::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateEditDialog::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateEditDialog::PanelMessageFunc_OnAddToP4::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddToP4";
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
// Address: 0x1002F150
// Name: public: CRoomTemplateEditDialog::CRoomTemplateEditDialog(class vgui::Panel __near *,char const __near *,class CRoomTemplate __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CRoomTemplateEditDialog *__thiscall CRoomTemplateEditDialog::CRoomTemplateEditDialog(
        CRoomTemplateEditDialog *this,
        vgui::Panel *parent,
        const char *name,
        CRoomTemplate *pRoomTemplate,
        bool bCreatingNew)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  CRoomTemplate *v9; // edi
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::TextEntry *v17; // eax
  vgui::TextEntry *v18; // eax
  vgui::TextEntry *v19; // eax
  CToggleExitsPanel *v20; // eax
  CToggleExitsPanel *v21; // eax
  CRoomTemplatePanel *v22; // eax
  CRoomTemplatePanel *v23; // eax
  vgui::Slider *v24; // eax
  vgui::Slider *v25; // eax
  vgui::Label *v26; // eax
  vgui::Label *v27; // eax
  vgui::ComboBox *v28; // eax
  vgui::ComboBox *v29; // eax
  const char **v30; // ebx
  vgui::Slider *v31; // eax
  vgui::Slider *v32; // eax
  vgui::Slider *v33; // eax
  vgui::Slider *v34; // eax
  vgui::Label *v35; // eax
  vgui::Label *v36; // eax
  vgui::Label *v37; // eax
  vgui::Label *v38; // eax
  vgui::PanelListPanel *v39; // eax
  vgui::PanelListPanel *v40; // eax
  int v41; // ebx
  vgui::CheckButton *v42; // edi
  CTagList *v43; // eax
  vgui::CheckButton *v44; // edi
  vgui::Tooltip *Tooltip; // eax
  CTagList *v46; // eax
  int m_nTileType; // edi
  CRoomTemplate *m_pRoomTemplate; // [esp-4h] [ebp-11Ch]
  const char *v50; // [esp-4h] [ebp-11Ch]
  char buffer[256]; // [esp+Ch] [ebp-10Ch] BYREF
  char pDest[12]; // [esp+10Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+118h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CRoomTemplateEditDialog_vtbl *)&CRoomTemplateEditDialog::`vftable';
  if ( `CRoomTemplateEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplateEditDialog::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateEditDialog");
    v6->pfnClassName = CRoomTemplateEditDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CRoomTemplateEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRoomTemplateEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CRoomTemplateEditDialog");
    v7->pfnClassName = CRoomTemplateEditDialog::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CRoomTemplateEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplateEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplateEditDialog");
    v8->pfnClassName = CRoomTemplateEditDialog::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CRoomTemplateEditDialog::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CRoomTemplateEditDialog::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CRoomTemplateEditDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CRoomTemplateEditDialog::PanelMessageFunc_OnCheckOutFromP4::InitVar(a1: (int)&savedregs);
  CRoomTemplateEditDialog::PanelMessageFunc_OnAddToP4::InitVar(a1: (int)&savedregs);
  v9 = pRoomTemplate;
  this->m_bCreatingNew = bCreatingNew;
  this->m_pRoomTemplate = pRoomTemplate;
  v10 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "RoomTemplateTheme", text: "Unknown");
  else
    v11 = nullptr;
  this->m_pThemeLabel = v11;
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "PickVMFButton",
            text: "...",
            pActionSignalTarget: this,
            pCmd: "PickVMF");
  else
    v13 = nullptr;
  this->m_pPickVMFButton = v13;
  v14 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v14 != nullptr )
    v15 = vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "RoomTemplateNameEdit");
  else
    v15 = nullptr;
  this->m_pRoomTemplateNameEdit = v15;
  v16 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v16 != nullptr )
    v17 = vgui::TextEntry::TextEntry(this: v16, parent: this, panelName: "RoomTemplateDescriptionEdit");
  else
    v17 = nullptr;
  this->m_pRoomTemplateDescriptionEdit = v17;
  v18 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v18 != nullptr )
    v19 = vgui::TextEntry::TextEntry(this: v18, parent: this, panelName: "RoomTemplateSoundscapeEdit");
  else
    v19 = nullptr;
  this->m_pRoomTemplateSoundscapeEdit = v19;
  v20 = (CToggleExitsPanel *)operator new(nSize: 0x168u);
  if ( v20 != nullptr )
    v21 = CToggleExitsPanel::CToggleExitsPanel(this: v20, parent: this, name: "CToggleExitsPanel");
  else
    v21 = nullptr;
  this->m_pToggleExitsPanel = v21;
  v22 = (CRoomTemplatePanel *)operator new(nSize: 0x19Cu);
  if ( v22 != nullptr )
    v23 = CRoomTemplatePanel::CRoomTemplatePanel(this: v22, parent: this, name: "RoomTemplatePanel");
  else
    v23 = nullptr;
  m_pRoomTemplate = this->m_pRoomTemplate;
  this->m_pRoomTemplatePanel = v23;
  CRoomTemplatePanel::SetRoomTemplate(this: v23, pTemplate: m_pRoomTemplate);
  this->m_pRoomTemplatePanel->m_bRoomTemplateEditMode = true;
  this->m_pRoomTemplatePanel->m_bForceShowExits = true;
  this->m_pRoomTemplatePanel->m_bForceShowTileSquares = true;
  CToggleExitsPanel::SetRoomTemplatePanel(
    this: this->m_pToggleExitsPanel,
    pPanel: this->m_pRoomTemplatePanel,
    bForceUpdate: false);
  v24 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v24 != nullptr )
    v25 = vgui::Slider::Slider(this: v24, parent: this, panelName: "SpawnWeightSlider");
  else
    v25 = nullptr;
  this->m_pSpawnWeightSlider = v25;
  v25->SetRange(this: v25, a2: 0, a3: 5);
  this->m_pSpawnWeightSlider->SetNumTicks(this: this->m_pSpawnWeightSlider, a2: 5);
  v26 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v26 != nullptr )
    v27 = vgui::Label::Label(this: v26, parent: this, panelName: "SpawnWeightValueLabel", text: "0");
  else
    v27 = nullptr;
  this->m_pSpawnWeightValue = v27;
  v28 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v28 != nullptr )
    v29 = vgui::ComboBox::ComboBox(this: v28, parent: this, panelName: "TileTypeCombo", numLines: 11, allowEdit: false);
  else
    v29 = nullptr;
  this->m_pTileTypeBox = v29;
  v30 = g_szASWTileTypeStrings_22;
  do
    this->m_pTileTypeBox->AddItem_2(this: this->m_pTileTypeBox, a2: *v30++, a3: nullptr);
  while ( (int)v30 < (int)&CRoomTemplateEditDialog::m_PanelMap );
  if ( this->m_pTileTypeBox->IsItemIDValid(this: this->m_pTileTypeBox, a2: 11) )
    this->m_pTileTypeBox->SetText(this: this->m_pTileTypeBox, a2: g_szASWTileTypeStrings_22[0]);
  V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%d", 32);
  v31 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v31 != nullptr )
    v32 = vgui::Slider::Slider(this: v31, parent: this, panelName: "TilesXSlider");
  else
    v32 = nullptr;
  this->m_pTilesXSlider = v32;
  v32->SetRange(this: v32, a2: 1, a3: 32);
  this->m_pTilesXSlider->SetNumTicks(this: this->m_pTilesXSlider, a2: 31);
  this->m_pTilesXSlider->SetTickCaptions(this: this->m_pTilesXSlider, a2: "1", a3: buffer);
  v33 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v33 != nullptr )
    v34 = vgui::Slider::Slider(this: v33, parent: this, panelName: "TilesYSlider");
  else
    v34 = nullptr;
  this->m_pTilesYSlider = v34;
  v34->SetRange(this: v34, a2: 1, a3: 32);
  this->m_pTilesYSlider->SetNumTicks(this: this->m_pTilesYSlider, a2: 31);
  this->m_pTilesYSlider->SetTickCaptions(this: this->m_pTilesYSlider, a2: "1", a3: buffer);
  v35 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v35 != nullptr )
    v36 = vgui::Label::Label(this: v35, parent: this, panelName: "TilesWideValueLabel", text: "1");
  else
    v36 = nullptr;
  this->m_pTilesXValue = v36;
  v37 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v37 != nullptr )
    v38 = vgui::Label::Label(this: v37, parent: this, panelName: "TilesTallValueLabel", text: "2");
  else
    v38 = nullptr;
  this->m_pTilesYValue = v38;
  v39 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v39 != nullptr )
    v40 = vgui::PanelListPanel::PanelListPanel(this: v39, parent: this, panelName: "TagListPanel");
  else
    v40 = nullptr;
  this->m_pTagListPanel = v40;
  vgui::PanelListPanel::SetShowScrollBar(this: v40, bShow: true);
  vgui::PanelListPanel::SetFirstColumnWidth(this: this->m_pTagListPanel, width: 0);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: this->m_pTagListPanel, buffer: 0);
  if ( TagList() != nullptr )
  {
    v41 = 0;
    if ( TagList()->m_tags.m_Size > 0 )
    {
      do
      {
        v42 = (vgui::CheckButton *)operator new(nSize: 0x218u);
        if ( v42 != nullptr )
        {
          v43 = TagList();
          v44 = vgui::CheckButton::CheckButton(
                  this: v42,
                  parent: this->m_pTagListPanel,
                  panelName: "TagCheckButton",
                  text: v43->m_tags.m_Memory.m_pMemory[v41]);
        }
        else
        {
          v44 = nullptr;
        }
        v44->AddActionSignalTarget_2(this: v44, a2: this);
        if ( vgui::Panel::GetTooltip(this: v44) != nullptr )
        {
          v50 = TagList()->m_tagDescriptions.m_Memory.m_pMemory[v41];
          Tooltip = vgui::Panel::GetTooltip(this: v44);
          vgui::Tooltip::SetText(this: Tooltip, text: v50);
        }
        v46 = TagList();
        if ( CRoomTemplate::HasTag(this: this->m_pRoomTemplate, szTag: v46->m_tags.m_Memory.m_pMemory[v41]) != 0 )
          v44->SetSelected(this: v44, a2: true);
        this->m_pTagListPanel->AddItem(this: this->m_pTagListPanel, a2: nullptr, a3: v44);
        ++v41;
      }
      while ( v41 < TagList()->m_tags.m_Size );
      v9 = pRoomTemplate;
    }
  }
  this->m_iSelectedTileX = -1;
  this->m_iSelectedTileY = -1;
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "RoomTemplateEditDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pThemeLabel->SetText(this: this->m_pThemeLabel, a2: (const char *)v9->m_pLevelTheme);
  if ( !bCreatingNew )
  {
    this->m_pRoomTemplateNameEdit->SetText(this: this->m_pRoomTemplateNameEdit, a2: v9->m_FullName);
    this->m_pRoomTemplateNameEdit->SetEditable(this: this->m_pRoomTemplateNameEdit, a2: false);
    this->m_pPickVMFButton->SetEnabled(this: this->m_pPickVMFButton, a2: false);
    this->m_pRoomTemplateDescriptionEdit->SetText(this: this->m_pRoomTemplateDescriptionEdit, a2: v9->m_Description);
    this->m_pRoomTemplateSoundscapeEdit->SetText(this: this->m_pRoomTemplateSoundscapeEdit, a2: v9->m_Soundscape);
    this->m_pSpawnWeightSlider->SetValue(
      this: this->m_pSpawnWeightSlider,
      a2: this->m_pRoomTemplate->m_nSpawnWeight,
      a3: true);
    this->m_pTilesXSlider->SetValue(this: this->m_pTilesXSlider, a2: this->m_pRoomTemplate->m_nTilesX, a3: true);
    this->m_pTilesYSlider->SetValue(this: this->m_pTilesYSlider, a2: this->m_pRoomTemplate->m_nTilesY, a3: true);
    V_snprintf(pDest, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nSpawnWeight);
    this->m_pSpawnWeightValue->SetText(this: this->m_pSpawnWeightValue, a2: pDest);
    V_snprintf(pDest, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nTilesX);
    this->m_pTilesXValue->SetText(this: this->m_pTilesXValue, a2: pDest);
    V_snprintf(pDest, maxLen: 12, pFormat: "%d", this->m_pRoomTemplate->m_nTilesY);
    this->m_pTilesYValue->SetText(this: this->m_pTilesYValue, a2: pDest);
    m_nTileType = this->m_pRoomTemplate->m_nTileType;
    if ( this->m_pTileTypeBox->IsItemIDValid(this: this->m_pTileTypeBox, a2: m_nTileType) )
      this->m_pTileTypeBox->SetText(this: this->m_pTileTypeBox, a2: g_szASWTileTypeStrings_22[m_nTileType]);
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002F910
// Name: public: virtual void CRoomTemplateEditDialog::OnAddToP4(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnAddToP4(CRoomTemplateEditDialog *this, KeyValues *pKV)
{
  const char *String; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  char vmfPath[260]; // [esp+8h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pKV, keyName: "file", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( p4->OpenFileForAdd(this: p4, a2: String) )
    {
      V_strncpy(pDest: vmfPath, pSrc: String, maxLen: 260);
      V_SetExtension(path: vmfPath, extension: "vmf", pathStringLength: 260);
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: vmfPath, a3: nullptr) )
        p4->OpenFileForAdd(this: p4, a2: vmfPath);
    }
    else
    {
      VGUIMessageBox(pParent: this, pTitle: "P4 Error!", pMsg: "Failed to add '%s' to Perforce.", String);
    }
  }
  CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::Insert(
    this: &CLevelTheme::s_pCurrentTheme->m_RoomTemplates,
    src: &this->m_pRoomTemplate);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "UpdateCurrentTheme");
  else
    v5 = nullptr;
  this->PostActionSignal(this, a2: v5);
  this->OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FA20
// Name: public: void CRoomTemplateEditDialog::AddExit(int,int,enum ExitDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::AddExit(
        CRoomTemplateEditDialog *this,
        vgui::TreeNode_vtbl *iXPos,
        int iYPos,
        ExitDirection_t dir)
{
  CRoomTemplate *m_pRoomTemplate; // ecx
  int v6; // eax
  CRoomTemplateExit **v7; // edx
  CRoomTemplateExit *v8; // ecx
  _DWORD *v9; // eax
  vgui::TreeNode *v10; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v11; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  vgui::TreeNode **v16; // edi
  CRoomTemplateEditDialog *v17; // esi
  CRoomTemplateEditDialog *v18; // [esp+Ch] [ebp-4h]

  m_pRoomTemplate = this->m_pRoomTemplate;
  v6 = m_pRoomTemplate->m_Exits.m_Size - 1;
  v18 = this;
  if ( v6 < 0 )
  {
LABEL_7:
    v9 = operator new(nSize: 0x54u);
    if ( v9 != nullptr )
    {
      *v9 = 0;
      v9[1] = 0;
      v9[2] = 0;
      v9[3] = 0;
      *((_BYTE *)v9 + 16) = 0;
      *((_BYTE *)v9 + 80) = 0;
      v10 = (vgui::TreeNode *)v9;
    }
    else
    {
      v10 = nullptr;
    }
    *(_DWORD *)&v10->vgui::Panel::m_RegisterClass = iYPos;
    *(_DWORD *)&v10->m_OnCommand_register = dir;
    v10->__vftable = iXPos;
    *(_DWORD *)&v10->m_OnDelete_register = 0;
    v11 = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pRoomTemplate;
    m_pMemory = v11[1].m_pMemory;
    m_nAllocationCount = v11->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: v11,
        num: (int)m_pMemory - m_nAllocationCount + 1);
    ++v11[1].m_pMemory;
    v14 = v11->m_pMemory;
    v15 = (char *)v11[1].m_pMemory - (char *)m_pMemory - 1;
    v11[1].m_nAllocationCount = (int)v11->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
    v16 = &v11->m_pMemory[(_DWORD)m_pMemory];
    if ( v16 != nullptr )
      *v16 = v10;
    v17 = v18;
    CRoomTemplatePanel::SetRoomTemplate(this: v18->m_pRoomTemplatePanel, pTemplate: v18->m_pRoomTemplate);
    CToggleExitsPanel::SetRoomTemplatePanel(
      this: v17->m_pToggleExitsPanel,
      pPanel: v17->m_pRoomTemplatePanel,
      bForceUpdate: true);
    v17->m_pRoomTemplatePanel->InvalidateLayout(this: v17->m_pRoomTemplatePanel, a2: true, a3: false);
    v17->Repaint(this: v17);
  }
  else
  {
    v7 = &m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[v6];
    while ( 1 )
    {
      v8 = *v7;
      if ( (vgui::TreeNode_vtbl *)(*v7)->m_iXPos == iXPos && v8->m_iYPos == iYPos && dir == v8->m_ExitDirection )
        break;
      --v7;
      if ( --v6 < 0 )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FB40
// Name: public: void CRoomTemplateEditDialog::ToggleExit(int,int,enum ExitDirection_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::ToggleExit(
        CRoomTemplateEditDialog *this,
        int iXPos,
        int iYPos,
        ExitDirection_t dir)
{
  CRoomTemplate *m_pRoomTemplate; // esi
  int v6; // eax
  CRoomTemplateExit **v7; // edx
  CRoomTemplateExit *v8; // ecx
  CRoomTemplateExit *v9; // eax
  CUtlMemory<vgui::TreeNode *,int> *v10; // esi
  vgui::TreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // ecx
  vgui::TreeNode **v13; // edx
  int v14; // ecx
  vgui::TreeNode **v15; // ebx
  CRoomTemplateExit *pExit; // [esp+Ch] [ebp-4h]

  m_pRoomTemplate = this->m_pRoomTemplate;
  v6 = m_pRoomTemplate->m_Exits.m_Size - 1;
  if ( v6 < 0 )
  {
LABEL_7:
    v9 = (CRoomTemplateExit *)operator new(nSize: 0x54u);
    if ( v9 != nullptr )
    {
      v9->m_iXPos = 0;
      v9->m_iYPos = 0;
      v9->m_ExitDirection = EXITDIR_BEGIN;
      v9->m_iZChange = 0;
      v9->m_szExitTag[0] = 0;
      v9->m_bChokepointGrowSource = false;
      pExit = v9;
    }
    else
    {
      pExit = nullptr;
      v9 = nullptr;
    }
    v9->m_ExitDirection = dir;
    v9->m_iXPos = iXPos;
    v9->m_iYPos = iYPos;
    v9->m_iZChange = 0;
    v10 = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pRoomTemplate;
    m_pMemory = v10[1].m_pMemory;
    m_nAllocationCount = v10->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: v10,
        num: (int)m_pMemory - m_nAllocationCount + 1);
      v9 = pExit;
    }
    ++v10[1].m_pMemory;
    v13 = v10->m_pMemory;
    v14 = (char *)v10[1].m_pMemory - (char *)m_pMemory - 1;
    v10[1].m_nAllocationCount = (int)v10->m_pMemory;
    if ( v14 > 0 )
    {
      _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
      v9 = pExit;
    }
    v15 = &v10->m_pMemory[(_DWORD)m_pMemory];
    if ( v15 != nullptr )
      *v15 = (vgui::TreeNode *)v9;
  }
  else
  {
    v7 = &m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[v6];
    while ( 1 )
    {
      v8 = *v7;
      if ( (*v7)->m_iXPos == iXPos && v8->m_iYPos == iYPos && dir == v8->m_ExitDirection )
        break;
      --v7;
      if ( --v6 < 0 )
        goto LABEL_7;
    }
    if ( m_pRoomTemplate->m_Exits.m_Size - v6 - 1 > 0 )
      _V_memmove(
        dest: &m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[v6],
        src: &m_pRoomTemplate->m_Exits.m_Memory.m_pMemory[v6 + 1],
        count: 4 * (m_pRoomTemplate->m_Exits.m_Size - v6 - 1));
    --m_pRoomTemplate->m_Exits.m_Size;
  }
  CRoomTemplatePanel::SetRoomTemplate(this: this->m_pRoomTemplatePanel, pTemplate: this->m_pRoomTemplate);
  CToggleExitsPanel::SetRoomTemplatePanel(
    this: this->m_pToggleExitsPanel,
    pPanel: this->m_pRoomTemplatePanel,
    bForceUpdate: true);
  this->m_pRoomTemplatePanel->InvalidateLayout(this: this->m_pRoomTemplatePanel, a2: true, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FCA0
// Name: public: virtual void CRoomTemplateEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateEditDialog::OnCommand(CRoomTemplateEditDialog *this, const char *command)
{
  CRoomTemplate **p_m_pRoomTemplate; // edi
  vgui::MessageBox *v4; // eax
  vgui::MessageBox *v5; // eax
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax
  vgui::MessageBox *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::MessageBox *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  CRoomTemplate *m_pRoomTemplate; // edi
  KeyValues *v21; // eax
  KeyValues *v22; // edi
  IBaseFileSystem *v23; // eax
  CMapLayout *v24; // eax
  CMapLayout *v25; // edi
  CRoom *v26; // eax
  CMapLayout *v27; // eax
  CRoom *v28; // eax
  CRoomTemplate *v29; // ecx
  CRoomTemplate *v30; // eax
  int i; // ebx
  CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *v32; // ecx
  _DWORD *v33; // edi
  char *VMFFilename; // [esp-4h] [ebp-51Ch]
  char buf[512]; // [esp+Ch] [ebp-50Ch] BYREF
  char name[260]; // [esp+20Ch] [ebp-30Ch] BYREF
  char buffer[260]; // [esp+310h] [ebp-208h] BYREF
  char szFullFileName[260]; // [esp+414h] [ebp-104h] BYREF

  if ( _V_stricmp(s1: command, s2: "Okay") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Close") == 0 )
    {
      if ( this->m_bCreatingNew )
      {
        m_pRoomTemplate = this->m_pRoomTemplate;
        if ( m_pRoomTemplate != nullptr )
        {
          CRoomTemplate::~CRoomTemplate(this: this->m_pRoomTemplate);
          free(pMem: m_pRoomTemplate);
        }
        this->m_pRoomTemplate = nullptr;
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        V_snprintf(
          pDest: &szFullFileName[4],
          maxLen: 256,
          pFormat: "tilegen/roomtemplates/%s/%s.roomtemplate",
          this->m_pRoomTemplate->m_pLevelTheme->m_szName,
          this->m_pRoomTemplate->m_FullName);
        v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v21 != nullptr )
          v22 = KeyValues::KeyValues(this: v21, setName: this->m_pRoomTemplate->m_FullName);
        else
          v22 = nullptr;
        if ( g_pFullFileSystem != nullptr )
          v23 = &g_pFullFileSystem->IBaseFileSystem;
        else
          v23 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v22,
               filesystem: v23,
               resourceName: &szFullFileName[4],
               pathID: "GAME",
               pfnEvaluateSymbolProc: nullptr) )
        {
          V_snprintf(pDest: buffer, maxLen: 260, pFormat: "%s", this->m_pRoomTemplate->m_FullName);
          CRoomTemplate::LoadFromKeyValues(this: this->m_pRoomTemplate, pRoomName: buffer, pKeyValues: v22);
          KeyValues::deleteThis(this: v22);
          vgui::Frame::OnCommand(this, command);
        }
        else
        {
          _Msg(a1: "Error: failed to load room template %s\n", &szFullFileName[4]);
          KeyValues::deleteThis(this: v22);
          vgui::Frame::OnCommand(this, command);
        }
      }
      return;
    }
    if ( _V_stricmp(s1: command, s2: "EditLights") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "GenerateNav") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "ClearAllExits") == 0 )
        {
          v29 = this->m_pRoomTemplate;
          if ( v29 != nullptr )
          {
            CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)v29);
            CRoomTemplatePanel::SetRoomTemplate(this: this->m_pRoomTemplatePanel, pTemplate: this->m_pRoomTemplate);
            CToggleExitsPanel::SetRoomTemplatePanel(
              this: this->m_pToggleExitsPanel,
              pPanel: this->m_pRoomTemplatePanel,
              bForceUpdate: true);
            this->m_pRoomTemplatePanel->InvalidateLayout(this: this->m_pRoomTemplatePanel, a2: true, a3: false);
            this->Repaint(this);
            vgui::Frame::OnCommand(this, command);
          }
          return;
        }
        if ( _V_stricmp(s1: command, s2: "ClearExitsFromTile") == 0 )
        {
          v30 = this->m_pRoomTemplate;
          if ( v30 != nullptr )
          {
            for ( i = v30->m_Exits.m_Size - 1; i >= 0; --i )
            {
              v32 = (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)this->m_pRoomTemplate;
              v33 = &v32->m_Memory.m_pMemory[i]->__vftable;
              if ( *v33 == this->m_iSelectedTileX && v33[1] == this->m_iSelectedTileY )
              {
                CUtlVector<CRoomTemplateExit *,CUtlMemory<CRoomTemplateExit *,int>>::Remove(this: v32, elem: i);
                free(pMem: v33);
              }
            }
            CRoomTemplatePanel::SetRoomTemplate(this: this->m_pRoomTemplatePanel, pTemplate: this->m_pRoomTemplate);
            CToggleExitsPanel::SetRoomTemplatePanel(
              this: this->m_pToggleExitsPanel,
              pPanel: this->m_pRoomTemplatePanel,
              bForceUpdate: true);
            this->m_pRoomTemplatePanel->InvalidateLayout(this: this->m_pRoomTemplatePanel, a2: true, a3: false);
            this->Repaint(this);
            vgui::Frame::OnCommand(this, command);
          }
          return;
        }
        if ( _V_stricmp(s1: command, s2: "AddExitNorth") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "AddExitEast") == 0 )
          {
            CRoomTemplateEditDialog::AddExit(
              this,
              iXPos: (vgui::TreeNode_vtbl *)this->m_iSelectedTileX,
              iYPos: this->m_iSelectedTileY,
              dir: EXITDIR_EAST);
            vgui::Frame::OnCommand(this, command);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "AddExitSouth") == 0 )
          {
            CRoomTemplateEditDialog::AddExit(
              this,
              iXPos: (vgui::TreeNode_vtbl *)this->m_iSelectedTileX,
              iYPos: this->m_iSelectedTileY,
              dir: EXITDIR_SOUTH);
            vgui::Frame::OnCommand(this, command);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "AddExitWest") != 0 )
          {
            if ( _V_stricmp(s1: command, s2: "EditExitNorth") != 0 )
            {
              if ( _V_stricmp(s1: command, s2: "EditExitEast") == 0 )
              {
                CRoomTemplateEditDialog::EditExit(
                  this,
                  iXPos: this->m_iSelectedTileX,
                  iYPos: this->m_iSelectedTileY,
                  dir: EXITDIR_EAST);
                vgui::Frame::OnCommand(this, command);
                return;
              }
              if ( _V_stricmp(s1: command, s2: "EditExitSouth") == 0 )
              {
                CRoomTemplateEditDialog::EditExit(
                  this,
                  iXPos: this->m_iSelectedTileX,
                  iYPos: this->m_iSelectedTileY,
                  dir: EXITDIR_SOUTH);
                vgui::Frame::OnCommand(this, command);
                return;
              }
              if ( _V_stricmp(s1: command, s2: "EditExitWest") != 0 )
              {
                if ( _V_stricmp(s1: command, s2: "PickVMF") == 0 )
                  CRoomTemplateEditDialog::DoPickVMF(this);
LABEL_102:
                vgui::Frame::OnCommand(this, command);
                return;
              }
              CRoomTemplateEditDialog::EditExit(
                this,
                iXPos: this->m_iSelectedTileX,
                iYPos: this->m_iSelectedTileY,
                dir: EXITDIR_WEST);
            }
            else
            {
              CRoomTemplateEditDialog::EditExit(
                this,
                iXPos: this->m_iSelectedTileX,
                iYPos: this->m_iSelectedTileY,
                dir: EXITDIR_BEGIN);
            }
          }
          else
          {
            CRoomTemplateEditDialog::AddExit(
              this,
              iXPos: (vgui::TreeNode_vtbl *)this->m_iSelectedTileX,
              iYPos: this->m_iSelectedTileY,
              dir: EXITDIR_WEST);
          }
        }
        else
        {
          CRoomTemplateEditDialog::AddExit(
            this,
            iXPos: (vgui::TreeNode_vtbl *)this->m_iSelectedTileX,
            iYPos: this->m_iSelectedTileY,
            dir: EXITDIR_BEGIN);
        }
        vgui::Frame::OnCommand(this, command);
        return;
      }
      this->OnClose(this);
      v27 = (CMapLayout *)operator new(nSize: 0xE264u);
      if ( v27 != nullptr )
        v25 = CMapLayout::CMapLayout(this: v27, pGenerationOptions: nullptr);
      else
        v25 = nullptr;
      v28 = (CRoom *)operator new(nSize: 0x24u);
      if ( v28 != nullptr )
        CRoom::CRoom(this: v28, pMapLayout: v25, pRoomTemplate: this->m_pRoomTemplate, TileX: 60, TileY: 60);
      CMapLayout::SaveMapLayout(this: v25, filename: "maps/output.layout");
      CRoomTemplateEditDialog::GetVMFFilename(this);
      V_snprintf(
        pDest: &szFullFileName[4],
        maxLen: 256,
        pFormat: "asw_random_weapons 0; asw_money 0; asw_director_spawn_npcs 0; asw_spawner_spawn_npcs 0; asw_build_map %s; asw_generate_nav 1",
        "output.layout");
    }
    else
    {
      this->OnClose(this);
      v24 = (CMapLayout *)operator new(nSize: 0xE264u);
      if ( v24 != nullptr )
        v25 = CMapLayout::CMapLayout(this: v24, pGenerationOptions: nullptr);
      else
        v25 = nullptr;
      v26 = (CRoom *)operator new(nSize: 0x24u);
      if ( v26 != nullptr )
        CRoom::CRoom(this: v26, pMapLayout: v25, pRoomTemplate: this->m_pRoomTemplate, TileX: 60, TileY: 60);
      CMapLayout::SaveMapLayout(this: v25, filename: "maps/output.layout");
      VMFFilename = CRoomTemplateEditDialog::GetVMFFilename(this);
      V_snprintf(
        pDest: &szFullFileName[4],
        maxLen: 256,
        pFormat: "asw_random_weapons 0; asw_money 0; asw_build_map %s edit %s",
        "output.layout",
        VMFFilename);
    }
    engine->ClientCmd_Unrestricted(this: engine, a2: &szFullFileName[4]);
    if ( v25 != nullptr )
    {
      ((void (__thiscall *)(CMapLayout *, int))v25->dtr_CMapLayout)(a1: v25, a2: 1);
      vgui::Frame::OnCommand(this, command);
      return;
    }
    goto LABEL_102;
  }
  this->m_pRoomTemplateDescriptionEdit->GetText_2(this: this->m_pRoomTemplateDescriptionEdit, a2: buf, a3: 512);
  p_m_pRoomTemplate = &this->m_pRoomTemplate;
  CRoomTemplate::SetDescription(this: this->m_pRoomTemplate, pDescription: buf);
  this->m_pRoomTemplateSoundscapeEdit->GetText_2(this: this->m_pRoomTemplateSoundscapeEdit, a2: buf, a3: 512);
  CRoomTemplate::SetSoundscape(this: this->m_pRoomTemplate, pSoundscape: buf);
  if ( this->m_bCreatingNew )
  {
    this->m_pRoomTemplateNameEdit->GetText_2(this: this->m_pRoomTemplateNameEdit, a2: name, a3: 260);
    if ( _V_strlen(str: name) <= 0 )
    {
      v4 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v4 != nullptr )
      {
        v5 = vgui::MessageBox::MessageBox(
               this: v4,
               title: "Bad Room template Name",
               text: "Please enter a valid name for this room template",
               parent: this);
        v5->DoModal_2(this: v5, a2: nullptr);
        return;
      }
      goto LABEL_6;
    }
    CRoomTemplate::SetFullName(this: *p_m_pRoomTemplate, pFullName: name);
  }
  V_snprintf(
    pDest: buffer,
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s.roomtemplate",
    (*p_m_pRoomTemplate)->m_pLevelTheme->m_szName,
    (*p_m_pRoomTemplate)->m_FullName);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: buffer,
    a3: "GAME",
    a4: szFullFileName,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( this->m_bCreatingNew
    && g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFullFileName, a3: nullptr) )
  {
    v7 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v7 != nullptr )
    {
      v6 = vgui::MessageBox::MessageBox(
             this: v7,
             title: "File Exists",
             text: "Room template already exists!",
             parent: this);
      goto LABEL_7;
    }
LABEL_6:
    v6 = nullptr;
LABEL_7:
    v6->DoModal_2(this: v6, a2: nullptr);
    return;
  }
  if ( CRoomTemplate::SaveRoomTemplate(this: *p_m_pRoomTemplate) == 0 )
  {
    if ( !this->m_bCreatingNew && p4 != nullptr && p4->IsFileInPerforce(this: p4, a2: szFullFileName) )
    {
      v8 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v8 != nullptr )
        v9 = vgui::MessageBox::MessageBox(
               this: v8,
               title: "Check Out?",
               text: "File is not writeable. Would you like to check it out from Perforce?",
               parent: this);
      else
        v9 = nullptr;
      vgui::MessageBox::SetCancelButtonVisible(this: v9, state: true);
      v9->SetOKButtonText_2(this: v9, a2: "#MessageBox_Yes");
      vgui::MessageBox::SetCancelButtonText(this: v9, buttonText: "#MessageBox_No");
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "CheckOutFromP4", firstKey: "file", firstValue: szFullFileName);
      else
        v11 = nullptr;
      v9->SetCommand(this: v9, a2: v11);
      v9->DoModal_2(this: v9, a2: nullptr);
    }
    else
    {
      VGUIMessageBox(
        pParent: this,
        pTitle: "Save Error",
        pMsg: "Failed to save %s.roomtemplate.  Make sure file is checked out from Perforce.",
        (*p_m_pRoomTemplate)->m_FullName);
    }
    return;
  }
  if ( this->m_bCreatingNew )
  {
    if ( p4 != nullptr )
    {
      g_pFullFileSystem->RelativePathToFullPath(
        this: g_pFullFileSystem,
        a2: buffer,
        a3: "GAME",
        a4: szFullFileName,
        a5: 260,
        a6: FILTER_NONE,
        a7: nullptr);
      v12 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v12 != nullptr )
        v13 = vgui::MessageBox::MessageBox(
                this: v12,
                title: "Add to P4?",
                text: "Would you like to add this template to perforce?",
                parent: this);
      else
        v13 = nullptr;
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      v13->SetOKButtonText_2(this: v13, a2: "#MessageBox_Yes");
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "#MessageBox_No");
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "AddToP4", firstKey: "file", firstValue: szFullFileName);
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "AddToP4", firstKey: "file", firstValue: 0);
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
      return;
    }
    CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::Insert(
      this: &CLevelTheme::s_pCurrentTheme->m_RoomTemplates,
      src: &this->m_pRoomTemplate);
  }
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "UpdateCurrentTheme");
  else
    v19 = nullptr;
  this->PostActionSignal(this, a2: v19);
  this->OnClose(this);
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x100A43B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenDialog::GetMessageMap(vgui::FileOpenDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A43E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenDialog::GetAnimMap(vgui::FileOpenDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenDialog");
}

//------------------------------------------------------------------------------
// Address: 0x100A43F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenDialog::GetKBMap(vgui::FileOpenDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenDialog");
  `vgui::FileOpenDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AB540
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100AECA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AECD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x100AECE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FD350
// Name: _dynamic_initializer_for__CRoomTemplateEditDialog::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CRoomTemplateEditDialog::m_MessageMap__()
{
  *(_QWORD *)&CRoomTemplateEditDialog::m_MessageMap[0].func = (unsigned int)CRoomTemplateEditDialog::OnFileSelected;
  *((_QWORD *)&CRoomTemplateEditDialog::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&CRoomTemplateEditDialog::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&CRoomTemplateEditDialog::m_MessageMap[0].nameSymbol = 0;
  CRoomTemplateEditDialog::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}
