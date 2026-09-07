// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeelementpanel.cpp
// Functions: 9
// ============================================================

#include "vgui2\dme_controls\attributeelementpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046F1E0
// Name: public: static char const __near * CAttributeElementPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPanel::GetPanelClassName()
{
  return "CAttributeElementPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046F1F0
// Name: protected: virtual void CAttributeElementPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::SetFont(CAttributeElementPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0046F240
// Name: private: virtual void CAttributeElementPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::Refresh(CAttributeElementPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+Ch] [ebp-23Ch]
  char elemText[512]; // [esp+20h] [ebp-228h] BYREF
  char idstr[40]; // [esp+220h] [ebp-28h] BYREF

  elemText[0] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(idstr, 0, 37);
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: idstr, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: elemText,
          maxLen: 512,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          idstr,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = defaultValue;
        V_snprintf(pDest: elemText, maxLen: 512, pFormat: "%s %s", v10, idstr);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: elemText);
  this->m_pData->SetEnabled(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046F400
// Name: public: static void CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F490
// Name: protected: virtual void CAttributeElementPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::OnCreateDragData(CAttributeElementPanel *this, KeyValues *msg)
{
  CDmElement *v3; // eax
  CDmaVar<enum DmElementHandle_t> *Attribute; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  int BufferType; // eax
  char txt[256]; // [esp+8h] [ebp-100h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
  {
    this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
    KeyValues::SetString(this: msg, keyName: "text", value: txt);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    if ( CDmElement::HasAttribute(this: v3, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN) )
    {
      Attribute = CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(this);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Attribute->m_Storage.m_Handle);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F570
// Name: public: CAttributeElementPanel::CAttributeElementPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__thiscall CAttributeElementPanel::CAttributeElementPanel(
        CAttributeElementPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAttributeTextEntry *v7; // eax
  CAttributeTextEntry *v8; // eax
  BOOL v9; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeElementPanel_vtbl *)&CAttributeElementPanel::`vftable';
  if ( `CAttributeElementPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v4->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
    v5->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
    v6->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  v7 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v7 != nullptr )
    v8 = CAttributeTextEntry::CAttributeTextEntry(this: v7, parent: this, panelName: "AttributeValue");
  else
    v8 = nullptr;
  v9 = (this->m_nFlags & 4) == 0;
  this->m_pData = v8;
  v8->SetEnabled(this: v8, a2: v9);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText_2(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowUniqueID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046F6C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPanel::GetMessageMap(CAttributeElementPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F6F0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPanel::GetAnimMap(CAttributeElementPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046F700
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPanel::GetKBMap(CAttributeElementPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104926D0
// Name: public: static char const __near * CAttributeElementPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPanel::GetPanelClassName()
{
  return "CAttributeElementPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104926E0
// Name: protected: virtual void CAttributeElementPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::SetFont(CAttributeElementPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10492740
// Name: private: virtual void CAttributeElementPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CAttributeElementPanel::Refresh(CAttributeElementPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+8h] [ebp-23Ch]
  char pDest[32]; // [esp+18h] [ebp-22Ch] BYREF
  _BYTE elemText_484[37]; // [esp+21Ch] [ebp-28h] OVERLAPPED BYREF

  pDest[4] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(elemText_484, 0, sizeof(elemText_484));
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: elemText_484, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: &pDest[4],
          maxLen: 0x200u,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          elemText_484,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = &var;
        V_snprintf(pDest: &pDest[4], maxLen: 0x200u, pFormat: "%s %s", v10, elemText_484);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: &pDest[4]);
  this->m_pData->SetEnabled(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10492900
// Name: public: static void CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10492990
// Name: protected: virtual void CAttributeElementPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::OnCreateDragData(CAttributeElementPanel *this, KeyValues *msg)
{
  CDmElement *v3; // eax
  CDmaVar<enum DmElementHandle_t> *Attribute; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  int BufferType; // eax
  char txt[256]; // [esp+8h] [ebp-100h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
  {
    this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
    KeyValues::SetString(this: msg, keyName: "text", value: txt);
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    if ( CDmElement::HasAttribute(this: v3, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN) )
    {
      Attribute = CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(this);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: Attribute->m_Storage.m_Handle);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10492A70
// Name: public: CAttributeElementPanel::CAttributeElementPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__userpurge CAttributeElementPanel::CAttributeElementPanel@<eax>(
        CAttributeElementPanel *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CAttributeTextEntry *v8; // eax
  CAttributeTextEntry *v9; // eax
  BOOL v10; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, a2, parent, info);
  this->__vftable = (CAttributeElementPanel_vtbl *)&CAttributeElementPanel::`vftable';
  if ( `CAttributeElementPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v5->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
    v6->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
    v7->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  v8 = (CAttributeTextEntry *)operator new(nSize: 0x848u);
  if ( v8 != nullptr )
    v9 = CAttributeTextEntry::CAttributeTextEntry(this: v8, parent: this, panelName: "AttributeValue");
  else
    v9 = nullptr;
  v10 = (this->m_nFlags & 4) == 0;
  this->m_pData = v9;
  v9->SetEnabled(this: v9, a2: v10);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowUniqueID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10492BC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPanel::GetMessageMap(CAttributeElementPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10492BF0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPanel::GetAnimMap(CAttributeElementPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10492C00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPanel::GetKBMap(CAttributeElementPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00498E50
// Name: public: static char const __near * CAttributeElementPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeElementPanel::GetPanelClassName()
{
  return "CAttributeElementPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00498E60
// Name: protected: virtual void CAttributeElementPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::SetFont(CAttributeElementPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00498EB0
// Name: private: virtual void CAttributeElementPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::Refresh(CAttributeElementPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v4; // eax
  CDmElement *AttributeValueElement; // eax
  CDmElement *v6; // esi
  bool v7; // zf
  const char *m_pAsString; // ebx
  int v9; // eax
  const char *v10; // esi
  double v11; // [esp+Ch] [ebp-23Ch]
  char elemText[512]; // [esp+20h] [ebp-228h] BYREF
  char idstr[40]; // [esp+220h] [ebp-28h] BYREF

  elemText[0] = 0;
  if ( CBaseAttributePanel::GetEditorInfo(this) == nullptr )
    goto LABEL_24;
  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  Attribute = CDmElement::FindAttribute(this: EditorInfo, pAttributeName: "hideText");
  v4 = Attribute != nullptr
     ? CDmAttribute::GetValue<bool>(this: Attribute)
     : &`CDmElement::GetValue<bool>'::`2'::defaultVal;
  if ( !v4->m_Storage )
  {
LABEL_24:
    if ( CBaseAttributePanel::HasAttribute(this) )
      AttributeValueElement = CBaseAttributePanel::GetAttributeValueElement(this);
    else
      AttributeValueElement = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hObject.m_handle);
    v6 = AttributeValueElement;
    if ( AttributeValueElement != nullptr )
    {
      v7 = !this->m_bShowUniqueID;
      memset(idstr, 0, 37);
      if ( !v7 )
        UniqueIdToString(id: &AttributeValueElement->m_Id, pBuf: idstr, nMaxLen: 37);
      if ( this->m_bShowMemoryUsage )
      {
        m_pAsString = v6->m_Type.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        v11 = (float)((float)CDmElement::EstimateMemoryUsage(this: v6, depth: TD_NONE) * 0.0009765625);
        v9 = CDmElement::EstimateMemoryUsage(this: v6, depth: TD_DEEP);
        V_snprintf(
          pDest: elemText,
          maxLen: 512,
          pFormat: "%s %s (%.3fMB total / %.3fKB self)",
          m_pAsString,
          idstr,
          (float)((float)v9 * 0.00000095367432),
          v11);
      }
      else
      {
        v10 = v6->m_Type.u.m_pAsString;
        if ( v10 == (const char *)-1 )
          v10 = defaultValue;
        V_snprintf(pDest: elemText, maxLen: 512, pFormat: "%s %s", v10, idstr);
      }
    }
  }
  this->m_pData->SetText(this: this->m_pData, a2: elemText);
  this->m_pData->SetEnabled(this: this->m_pData, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00499070
// Name: public: static void CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00499100
// Name: protected: virtual void CAttributeElementPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeElementPanel::OnCreateDragData(CAttributeElementPanel *this, KeyValues *msg)
{
  CDmElement *v3; // eax
  CDmaVar<enum DmElementHandle_t> *Attribute; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  CExpressionCalculator *v7; // ecx
  int BufferType; // eax
  char txt[256]; // [esp+8h] [ebp-100h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hObject.m_handle) != 0 )
  {
    this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
    KeyValues::SetString(this: msg, keyName: "text", value: txt);
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    if ( CDmElement::HasAttribute(this: v3, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN) )
    {
      Attribute = CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(this);
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: Attribute->m_Storage.m_Handle);
      v6 = (CExpressionCalculator *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
      KeyValues::SetInt(this: msg, keyName: "dmeelement", value: BufferType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004991E0
// Name: public: CAttributeElementPanel::CAttributeElementPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeElementPanel *__thiscall CAttributeElementPanel::CAttributeElementPanel(
        CAttributeElementPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAttributeTextEntry *v7; // eax
  CAttributeTextEntry *v8; // eax
  BOOL v9; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeElementPanel_vtbl *)&CAttributeElementPanel::`vftable';
  if ( `CAttributeElementPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
    v4->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
    v5->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeElementPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeElementPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
    v6->pfnClassName = CAttributeElementPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeElementPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  v7 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v7 != nullptr )
    v8 = CAttributeTextEntry::CAttributeTextEntry(this: v7, parent: this, panelName: "AttributeValue");
  else
    v8 = nullptr;
  v9 = (this->m_nFlags & 4) == 0;
  this->m_pData = v8;
  v8->SetEnabled(this: v8, a2: v9);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  this->m_pType->SetText_2(this: this->m_pType, a2: "element");
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  this->m_bShowUniqueID = info->m_bShowUniqueID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00499330
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeElementPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeElementPanel::GetMessageMap(CAttributeElementPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00499360
// Name: public: virtual struct PanelAnimationMap __near * CAttributeElementPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeElementPanel::GetAnimMap(CAttributeElementPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeElementPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00499370
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeElementPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeElementPanel::GetKBMap(CAttributeElementPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeElementPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeElementPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeElementPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeElementPanel");
  `CAttributeElementPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
