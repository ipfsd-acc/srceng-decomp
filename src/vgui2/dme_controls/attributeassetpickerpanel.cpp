// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeassetpickerpanel.cpp
// Functions: 14
// ============================================================

#include "vgui2\dme_controls\attributeassetpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046FFF0
// Name: protected: virtual void CAttributeAssetPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::OnAssetSelected(CAttributeMDLPickerPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004709C0
// Name: public: static char const __near * CAttributeAssetPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAssetPickerPanel::GetPanelClassName()
{
  return "CAttributeAssetPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004709D0
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeBspPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAttributeBspPickerPanel::CreateAssetPickerFrame(CAttributeBspPickerPanel *this)
{
  CAssetPickerFrame *v2; // eax

  v2 = (CAssetPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CAssetPickerFrame::CAssetPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .BSP file",
             pAssetType: "BSP Files",
             pExt: "bsp",
             pSubDir: "maps",
             pTextType: "bspName");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00470A10
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVmtPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CAttributeVmtPickerPanel::CreateAssetPickerFrame(CAttributeVmtPickerPanel *this)
{
  CVMTPickerFrame *v2; // eax

  v2 = (CVMTPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVMTPickerFrame::CVMTPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .VMT file",
             bAllowMultiselect: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00470A40
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVtfPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CAttributeVtfPickerPanel::CreateAssetPickerFrame(CAttributeVtfPickerPanel *this)
{
  CVTFPickerFrame *v2; // eax

  v2 = (CVTFPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVTFPickerFrame::CVTFPickerFrame(this: v2, pParent: this, pTitle: "Select .VTF file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00470A70
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeTgaPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CAttributeTgaPickerPanel::CreateAssetPickerFrame(CAttributeTgaPickerPanel *this)
{
  CTGAPickerFrame *v2; // eax

  v2 = (CTGAPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CTGAPickerFrame::CTGAPickerFrame(this: v2, pParent: this, pTitle: "Select .TGA file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00470AA0
// Name: protected: virtual void CAttributeAssetPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::ShowPickerDialog(CAttributeAssetPickerPanel *this)
{
  CBaseAssetPickerFrame *v2; // edi

  v2 = this->CreateAssetPickerFrame(this);
  v2->AddActionSignalTarget_2(this: v2, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v2, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00470AD0
// Name: private: virtual void CAttributeVmtPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeVmtPickerPanel::OnAssetSelected(CAttributeVmtPickerPanel *this, KeyValues *kv)
{
  KeyValues *v2; // edi
  const char *String; // eax
  int Int; // ebx
  IDmNotify *m_pNotify; // edi
  IDmNotify *v7; // ebx
  CDmElement *v8; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  int nSecondSheetSequenceNum; // [esp+Ch] [ebp-4h] BYREF

  v2 = kv;
  String = KeyValues::GetString(this: kv, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
  Int = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_count", defaultValue: 0);
  kv = (KeyValues *)KeyValues::GetInt(this: v2, keyName: "sheet_sequence_number", defaultValue: 0);
  nSecondSheetSequenceNum = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_secondary_number", defaultValue: 0);
  if ( Int > 0 )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Auto-Set Sequence from VMT dialog",
      a3: "Auto-Set Sequence from VMT dialog",
      a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v7 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Auto-Set Sequence from VMT dialog", a3: 0, a4: 256);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number");
    if ( Attribute != nullptr )
      CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&kv);
    v10 = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number 1");
    if ( v10 != nullptr )
      CDmAttribute::SetValue<int>(this: v10, value: &nSecondSheetSequenceNum);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v7 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470C50
// Name: public: static void CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470CE0
// Name: public: virtual CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(CAttributeAssetPickerPanel *this)
{
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00470CF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAssetPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAssetPickerPanel::GetMessageMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D20
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAssetPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAssetPickerPanel::GetAnimMap(CAttributeAssetPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00470D30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAssetPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAssetPickerPanel::GetKBMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470D60
// Name: public: CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAssetPickerPanel *__thiscall CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(
        CAttributeAssetPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  if ( `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    v4->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
    v5->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
    v6->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10493E40
// Name: public: static char const __near * CAttributeAssetPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAssetPickerPanel::GetPanelClassName()
{
  return "CAttributeAssetPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10493E50
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeBspPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAttributeBspPickerPanel::CreateAssetPickerFrame(CAttributeBspPickerPanel *this)
{
  CAssetPickerFrame *v2; // eax

  v2 = (CAssetPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    return CAssetPickerFrame::CAssetPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .BSP file",
             pAssetType: "BSP Files",
             pExt: "bsp",
             pSubDir: "maps",
             pTextType: "bspName");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10493E90
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVmtPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CAttributeVmtPickerPanel::CreateAssetPickerFrame(CAttributeVmtPickerPanel *this)
{
  CVMTPickerFrame *v2; // eax

  v2 = (CVMTPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVMTPickerFrame::CVMTPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .VMT file",
             bAllowMultiselect: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10493EC0
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVtfPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CAttributeVtfPickerPanel::CreateAssetPickerFrame(CAttributeVtfPickerPanel *this)
{
  CVTFPickerFrame *v2; // eax

  v2 = (CVTFPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVTFPickerFrame::CVTFPickerFrame(this: v2, pParent: this, pTitle: "Select .VTF file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10493EF0
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeTgaPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CAttributeTgaPickerPanel::CreateAssetPickerFrame(CAttributeTgaPickerPanel *this)
{
  CTGAPickerFrame *v2; // eax

  v2 = (CTGAPickerFrame *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    return CTGAPickerFrame::CTGAPickerFrame(this: v2, pParent: this, pTitle: "Select .TGA file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10493F20
// Name: protected: virtual void CAttributeAssetPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::ShowPickerDialog(CAttributeAssetPickerPanel *this)
{
  CBaseAssetPickerFrame *v2; // edi

  v2 = this->CreateAssetPickerFrame(this);
  v2->AddActionSignalTarget_2(this: v2, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v2, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10493F50
// Name: protected: virtual void CAttributeAssetPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::OnAssetSelected(CAttributeMDLPickerPanel *this, KeyValues *pKeyValues)
{
  char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10493FB0
// Name: private: virtual void CAttributeVmtPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeVmtPickerPanel::OnAssetSelected(CAttributeVmtPickerPanel *this, KeyValues *kv)
{
  KeyValues *v2; // edi
  char *String; // eax
  int Int; // ebx
  IDmNotify *m_pNotify; // edi
  IDmNotify *v7; // ebx
  CDmElement *v8; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  int nSecondSheetSequenceNum; // [esp+Ch] [ebp-4h] BYREF

  v2 = kv;
  String = KeyValues::GetString(this: kv, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
  Int = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_count", defaultValue: 0);
  kv = (KeyValues *)KeyValues::GetInt(this: v2, keyName: "sheet_sequence_number", defaultValue: 0);
  nSecondSheetSequenceNum = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_secondary_number", defaultValue: 0);
  if ( Int > 0 )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    g_pDataModel->StartUndo(
      this: g_pDataModel,
      a2: "Auto-Set Sequence from VMT dialog",
      a3: "Auto-Set Sequence from VMT dialog",
      a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v7 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Auto-Set Sequence from VMT dialog", a3: 0, a4: 256);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number");
    if ( Attribute != nullptr )
      CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&kv);
    v10 = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number 1");
    if ( v10 != nullptr )
      CDmAttribute::SetValue<int>(this: v10, value: &nSecondSheetSequenceNum);
    g_pDataModel->FinishUndo(this: g_pDataModel);
    g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    if ( v7 != nullptr )
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10494130
// Name: public: static void CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104941C0
// Name: public: virtual CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(CAttributeAssetPickerPanel *this)
{
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x104941D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAssetPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAssetPickerPanel::GetMessageMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494200
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAssetPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAssetPickerPanel::GetAnimMap(CAttributeAssetPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10494210
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAssetPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAssetPickerPanel::GetKBMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494240
// Name: public: CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAssetPickerPanel *__thiscall CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(
        CAttributeAssetPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  if ( `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    v4->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
    v5->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
    v6->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00499BF0
// Name: protected: virtual void CAttributeAssetPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::OnAssetSelected(CAttributeMDLPickerPanel *this, KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A5C0
// Name: public: static char const __near * CAttributeAssetPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeAssetPickerPanel::GetPanelClassName()
{
  return "CAttributeAssetPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049A5D0
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeBspPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CAssetPickerFrame *__thiscall CAttributeBspPickerPanel::CreateAssetPickerFrame(CAttributeBspPickerPanel *this)
{
  CAssetPickerFrame *v2; // eax

  v2 = (CAssetPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CAssetPickerFrame::CAssetPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .BSP file",
             pAssetType: "BSP Files",
             pExt: "bsp",
             pSubDir: "maps",
             pTextType: "bspName");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A610
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVmtPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CAttributeVmtPickerPanel::CreateAssetPickerFrame(CAttributeVmtPickerPanel *this)
{
  CVMTPickerFrame *v2; // eax

  v2 = (CVMTPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVMTPickerFrame::CVMTPickerFrame(
             this: v2,
             pParent: this,
             pTitle: "Select .VMT file",
             bAllowMultiselect: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A640
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeVtfPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFPickerFrame *__thiscall CAttributeVtfPickerPanel::CreateAssetPickerFrame(CAttributeVtfPickerPanel *this)
{
  CVTFPickerFrame *v2; // eax

  v2 = (CVTFPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CVTFPickerFrame::CVTFPickerFrame(this: v2, pParent: this, pTitle: "Select .VTF file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A670
// Name: private: virtual class CBaseAssetPickerFrame __near * CAttributeTgaPickerPanel::CreateAssetPickerFrame(void)
// Source: json
//------------------------------------------------------------------------------
CTGAPickerFrame *__thiscall CAttributeTgaPickerPanel::CreateAssetPickerFrame(CAttributeTgaPickerPanel *this)
{
  CTGAPickerFrame *v2; // eax

  v2 = (CTGAPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
  if ( v2 != nullptr )
    return CTGAPickerFrame::CTGAPickerFrame(this: v2, pParent: this, pTitle: "Select .TGA file");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A6A0
// Name: protected: virtual void CAttributeAssetPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::ShowPickerDialog(CAttributeAssetPickerPanel *this)
{
  CBaseAssetPickerFrame *v2; // edi

  v2 = this->CreateAssetPickerFrame(this);
  v2->AddActionSignalTarget_2(this: v2, a2: this);
  CBaseAssetPickerFrame::DoModal(this: v2, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0049A6D0
// Name: private: virtual void CAttributeVmtPickerPanel::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeVmtPickerPanel::OnAssetSelected(CAttributeVmtPickerPanel *this, KeyValues *kv)
{
  KeyValues *v2; // edi
  const char *String; // eax
  int Int; // ebx
  IDmNotify *m_pNotify; // edi
  IDmNotify *v7; // ebx
  CDmElement *v8; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  int nSecondSheetSequenceNum; // [esp+Ch] [ebp-4h] BYREF

  v2 = kv;
  String = KeyValues::GetString(this: kv, keyName: "asset", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
  Int = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_count", defaultValue: 0);
  kv = (KeyValues *)KeyValues::GetInt(this: v2, keyName: "sheet_sequence_number", defaultValue: 0);
  nSecondSheetSequenceNum = KeyValues::GetInt(this: v2, keyName: "sheet_sequence_secondary_number", defaultValue: 0);
  if ( Int > 0 )
  {
    m_pNotify = this->m_pNotify;
    v7 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Auto-Set Sequence from VMT dialog",
      a3: "Auto-Set Sequence from VMT dialog",
      a4: 0);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v7 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 460))(
      a1: g_pDataModel.u,
      a2: "Auto-Set Sequence from VMT dialog",
      a3: 0,
      a4: 256);
    v8 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number");
    if ( Attribute != nullptr )
      CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&kv);
    v10 = CDmElement::FindAttribute(this: v8, pAttributeName: "sequence_number 1");
    if ( v10 != nullptr )
      CDmAttribute::SetValue<int>(this: v10, value: &nSecondSheetSequenceNum);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
      a1: g_pDataModel.u,
      a2: 0);
    if ( v7 != nullptr )
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A850
// Name: public: static void CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049A8E0
// Name: public: virtual CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeAssetPickerPanel::~CAttributeAssetPickerPanel(CAttributeAssetPickerPanel *this)
{
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  CBaseAttributePanel::~CBaseAttributePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049A8F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeAssetPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeAssetPickerPanel::GetMessageMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A920
// Name: public: virtual struct PanelAnimationMap __near * CAttributeAssetPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeAssetPickerPanel::GetAnimMap(CAttributeAssetPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049A930
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeAssetPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeAssetPickerPanel::GetKBMap(CAttributeAssetPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
  `CAttributeAssetPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A960
// Name: public: CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeAssetPickerPanel *__thiscall CAttributeAssetPickerPanel::CAttributeAssetPickerPanel(
        CAttributeAssetPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeAssetPickerPanel_vtbl *)&CAttributeAssetPickerPanel::`vftable';
  if ( `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeAssetPickerPanel");
    v4->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeAssetPickerPanel");
    v5->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeAssetPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeAssetPickerPanel");
    v6->pfnClassName = CAttributeAssetPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeAssetPickerPanel::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
