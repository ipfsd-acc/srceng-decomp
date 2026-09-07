// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributetextpanel.cpp
// Functions: 13
// ============================================================

#include "vgui2\dme_controls\attributetextpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046A930
// Name: public: static char const __near * CAttributeTextPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextPanel::GetPanelClassName()
{
  return "CAttributeTextPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046A940
// Name: public: virtual void CAttributeTextPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::SetFont(CAttributeTextPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0046AA10
// Name: public: virtual void CAttributeTextPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Refresh(CAttributeTextPanel *this)
{
  DmAttributeType_t m_AttributeType; // eax
  int AttributeArrayCount; // edi
  CDmElement *v4; // eax
  CDmAttribute *v5; // eax
  const char *v6; // ebx
  int v7; // eax
  const char *v8; // eax
  char *i; // eax
  unsigned int ChannelTargetingAttribute; // eax
  CDmAttribute *Attribute; // eax
  char buf[512]; // [esp+18h] [ebp-200h] BYREF

  m_AttributeType = this->m_AttributeType;
  if ( (unsigned int)(m_AttributeType - 15) > 0xD )
  {
    if ( m_AttributeType == AT_FIRST_VALUE_TYPE )
    {
      this->m_pData->SetText(this: this->m_pData, a2: defaultValue);
    }
    else
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: buf, nLength: 512);
      if ( this->m_AttributeType == AT_VMATRIX )
      {
        for ( i = buf; *i != 0; ++i )
        {
          if ( *i == 10 )
            *i = 32;
        }
      }
      this->m_pData->SetText(this: this->m_pData, a2: buf);
      ChannelTargetingAttribute = (unsigned int)this->m_nFlags >> 2;
      if ( (this->m_nFlags & 4) != 0
        || (Attribute = CBaseAttributePanel::GetAttribute(this),
            (ChannelTargetingAttribute = (unsigned int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
      {
        LOBYTE(ChannelTargetingAttribute) = 0;
      }
      else
      {
        ChannelTargetingAttribute = 1;
      }
      this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
    }
  }
  else
  {
    AttributeArrayCount = CBaseAttributePanel::GetAttributeArrayCount(this);
    if ( this->m_bShowMemoryUsage )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
      v5 = CDmElement::FindAttribute(this: v4, pAttributeName: this->m_szAttributeName);
      v6 = "item";
      if ( AttributeArrayCount != 1 )
        v6 = "items";
      v7 = CDmAttribute::EstimateMemoryUsage(this: v5, depth: TD_DEEP);
      V_snprintf(
        pDest: buf,
        maxLen: 512,
        pFormat: "%d %s (%.3fMB)",
        AttributeArrayCount,
        v6,
        (float)((float)v7 * 0.00000095367432));
    }
    else
    {
      v8 = "item";
      if ( AttributeArrayCount != 1 )
        v8 = "items";
      V_snprintf(pDest: buf, maxLen: 512, pFormat: "%d %s", AttributeArrayCount, v8);
    }
    this->m_pData->SetText(this: this->m_pData, a2: buf);
    this->m_pData->SetEnabled(this: this->m_pData, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ABC0
// Name: public: void CBaseAttributePanel::SetAttributeValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue(CBaseAttributePanel *this, const char *pValue)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pValue, a3: pValue);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
      this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
      this: (CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)&v9,
      i: m_nArrayIndex,
      value: (const CUtlSymbolLarge *)&pValue);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pValue, a3: pValue);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ACA0
// Name: public: char const __near * CAttributeTextPanel::GetTextType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAttributeTextPanel::GetTextType(CAttributeTextPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  const char *result; // eax

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( EditorInfo == nullptr )
    return defaultValue;
  result = CDmElement::GetValueString(this: EditorInfo, pAttributeName: "texttype");
  if ( result == nullptr )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046ACC0
// Name: public: virtual void CAttributeTextPanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Apply(CAttributeTextPanel *this)
{
  IDmNotify *v2; // ebx
  IDmNotify *v3; // edi
  IDmNotify *m_pNotify; // ebx
  char curvalue[256]; // [esp+Ch] [ebp-200h] BYREF
  char txt[256]; // [esp+10Ch] [ebp-100h] BYREF

  this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
  CBaseAttributePanel::SetDirty(this, dirty: false);
  if ( this->m_AttributeType != AT_UNKNOWN )
  {
    CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: curvalue, nLength: 256);
    if ( _V_strcmp(s1: curvalue, s2: txt) == 0 )
      return;
    m_pNotify = this->m_pNotify;
    v3 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v3 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValueFromString(this, pString: txt);
  }
  else
  {
    v2 = this->m_pNotify;
    v3 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( v2 != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: v2) )
      v3 = v2;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue(this, pValue: defaultValue);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v3 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0046AF00
// Name: public: static void CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
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
// Address: 0x0046AFF0
// Name: public: virtual CBaseAttributePanel::~CBaseAttributePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::~CBaseAttributePanel(CBaseAttributePanel *this)
{
  CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::~CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>(this: &this->m_ColumnSize);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hEditorTypeDict,
      hElement: this->m_hEditorTypeDict.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hEditorInfo, hElement: this->m_hEditorInfo.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hObject, hElement: this->m_hObject.m_handle, handleType: HT_WEAK);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046B060
// Name: public: CAttributeTextPanel::CAttributeTextPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeTextPanel::CAttributeTextPanel(
        CAttributeTextPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAttributeTextEntry *v7; // eax
  int ChannelTargetingAttribute; // eax
  unsigned int v9; // ecx
  CDmAttribute *Attribute; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeTextPanel_vtbl *)&CAttributeTextPanel::`vftable';
  if ( `CAttributeTextPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
    v4->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
    v5->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
    v6->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  v7 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v7 != nullptr )
    ChannelTargetingAttribute = (int)CAttributeTextEntry::CAttributeTextEntry(
                                       this: v7,
                                       parent: this,
                                       panelName: "AttributeValue");
  else
    ChannelTargetingAttribute = 0;
  v9 = (unsigned int)this->m_nFlags >> 2;
  this->m_pData = (CAttributeTextEntry *)ChannelTargetingAttribute;
  if ( (v9 & 1) != 0
    || (Attribute = CBaseAttributePanel::GetAttribute(this),
        (ChannelTargetingAttribute = (int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
  {
    LOBYTE(ChannelTargetingAttribute) = 0;
  }
  else
  {
    ChannelTargetingAttribute = 1;
  }
  this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  vgui::Panel::SetAllowKeyBindingChainToParent(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046B1C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextPanel::GetMessageMap(CAttributeTextPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046B1F0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextPanel::GetAnimMap(CAttributeTextPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046B200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextPanel::GetKBMap(CAttributeTextPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471890
// Name: public: void CBaseAttributePanel::SetAttributeValue<class Color>(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<Color>(CBaseAttributePanel *this, const Color *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
      this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::Set(
      this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_COLOR)) != nullptr )
    {
      CDmAttribute::SetValue<Color>(this: Attribute, value);
    }
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048DD80
// Name: public: static char const __near * CAttributeTextPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextPanel::GetPanelClassName()
{
  return "CAttributeTextPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1048DD90
// Name: public: virtual void CAttributeTextPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::SetFont(CAttributeTextPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1048DE50
// Name: public: virtual void CAttributeTextPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Refresh(CAttributeTextPanel *this)
{
  DmAttributeType_t m_AttributeType; // eax
  int AttributeArrayCount; // edi
  CDmElement *v4; // eax
  CDmAttribute *v5; // eax
  const char *v6; // ebx
  int v7; // eax
  const char *v8; // eax
  char *i; // eax
  unsigned int ChannelTargetingAttribute; // eax
  CDmAttribute *Attribute; // eax
  char pDest[24]; // [esp+10h] [ebp-204h] BYREF

  m_AttributeType = this->m_AttributeType;
  if ( (unsigned int)(m_AttributeType - 15) > 0xD )
  {
    if ( m_AttributeType == AT_FIRST_VALUE_TYPE )
    {
      this->m_pData->SetText(this: this->m_pData, a2: &var);
    }
    else
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: &pDest[4], nLength: 512);
      if ( this->m_AttributeType == AT_VMATRIX )
      {
        for ( i = &pDest[4]; *i != 0; ++i )
        {
          if ( *i == 10 )
            *i = 32;
        }
      }
      this->m_pData->SetText(this: this->m_pData, a2: &pDest[4]);
      ChannelTargetingAttribute = (unsigned int)this->m_nFlags >> 2;
      if ( (this->m_nFlags & 4) != 0
        || (Attribute = CBaseAttributePanel::GetAttribute(this),
            (ChannelTargetingAttribute = (unsigned int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
      {
        LOBYTE(ChannelTargetingAttribute) = 0;
      }
      else
      {
        ChannelTargetingAttribute = 1;
      }
      this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
    }
  }
  else
  {
    AttributeArrayCount = CBaseAttributePanel::GetAttributeArrayCount(this);
    if ( this->m_bShowMemoryUsage )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
      v5 = CDmElement::FindAttribute(this: v4, pAttributeName: this->m_szAttributeName);
      v6 = "item";
      if ( AttributeArrayCount != 1 )
        v6 = "items";
      v7 = CDmAttribute::EstimateMemoryUsage(this: v5, depth: TD_DEEP);
      V_snprintf(
        pDest: &pDest[4],
        maxLen: 0x200u,
        pFormat: "%d %s (%.3fMB)",
        AttributeArrayCount,
        v6,
        (float)((float)v7 * 0.00000095367432));
    }
    else
    {
      v8 = "item";
      if ( AttributeArrayCount != 1 )
        v8 = "items";
      V_snprintf(pDest: &pDest[4], maxLen: 0x200u, pFormat: "%d %s", AttributeArrayCount, v8);
    }
    this->m_pData->SetText(this: this->m_pData, a2: &pDest[4]);
    this->m_pData->SetEnabled(this: this->m_pData, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048E000
// Name: public: void CBaseAttributePanel::SetAttributeValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue(CBaseAttributePanel *this, const char *pValue)
{
  char *m_szAttributeName; // edi
  CFmtStrN<256> *v4; // eax
  IDataModel_vtbl *v5; // edx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // eax
  int m_nArrayIndex; // esi
  CDmElement *v10; // ebx
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+114h] [ebp-8h] BYREF

  m_szAttributeName = this->m_szAttributeName;
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "Set %s", this->m_szAttributeName);
  g_pDataModel->StartUndo(this: g_pDataModel, a2: v4->m_szBuf, a3: v4->m_szBuf, a4: 0);
  v5 = g_pDataModel->__vftable;
  if ( this->m_nArrayIndex >= 0 )
  {
    ((void (__stdcall *)(const char **, const char *))v5->GetSymbol)(a1: &pValue, a2: pValue);
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v10 = v8;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
    CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
      this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v12,
      pElement: v10,
      pAttributeName: m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
      this: (CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)&v12,
      i: m_nArrayIndex,
      value: (const CUtlSymbolLarge *)&pValue);
  }
  else
  {
    v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))v5->GetElement)(a1: this->m_hObject.m_handle);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pValue, a3: pValue);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: m_szAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x1048E110
// Name: public: char const __near * CAttributeTextPanel::GetTextType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAttributeTextPanel::GetTextType(CAttributeTextPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  const char *result; // eax

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( EditorInfo == nullptr )
    return &var;
  result = CDmElement::GetValueString(this: EditorInfo, pAttributeName: "texttype");
  if ( result == nullptr )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048E130
// Name: public: virtual void CAttributeTextPanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Apply(CAttributeTextPanel *this)
{
  IDmNotify *v2; // ebx
  IDmNotify *v3; // edi
  IDmNotify *m_pNotify; // ebx
  char curvalue[256]; // [esp+Ch] [ebp-200h] BYREF
  char txt[256]; // [esp+10Ch] [ebp-100h] BYREF

  this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
  CBaseAttributePanel::SetDirty(this, dirty: false);
  if ( this->m_AttributeType != AT_UNKNOWN )
  {
    CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: curvalue, nLength: 256);
    if ( _V_strcmp(s1: curvalue, s2: txt) == 0 )
      return;
    m_pNotify = this->m_pNotify;
    v3 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( m_pNotify != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: m_pNotify) )
      v3 = m_pNotify;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValueFromString(this, pString: txt);
  }
  else
  {
    v2 = this->m_pNotify;
    v3 = nullptr;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Attribute Value", a3: "Set Attribute Value", a4: 0);
    if ( v2 != nullptr && g_pDataModel->InstallNotificationCallback(this: g_pDataModel, a2: v2) )
      v3 = v2;
    g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Set Attribute Value", a3: 4, a4: 256);
    CBaseAttributePanel::SetAttributeValue(this, pValue: &var);
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
  if ( v3 != nullptr )
    g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1048E370
// Name: public: static void CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
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
// Address: 0x1048E460
// Name: public: virtual CBaseAttributePanel::~CBaseAttributePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::~CBaseAttributePanel(CBaseAttributePanel *this)
{
  CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::~CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>(this: &this->m_ColumnSize);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(
      this: &this->m_hEditorTypeDict,
      hElement: this->m_hEditorTypeDict.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hEditorInfo, hElement: this->m_hEditorInfo.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hObject, hElement: this->m_hObject.m_handle, handleType: HT_WEAK);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1048E4D0
// Name: public: CAttributeTextPanel::CAttributeTextPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeTextPanel::CAttributeTextPanel(
        CAttributeTextPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAttributeTextEntry *v7; // eax
  int ChannelTargetingAttribute; // eax
  unsigned int v9; // ecx
  CDmAttribute *Attribute; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeTextPanel_vtbl *)&CAttributeTextPanel::`vftable';
  if ( `CAttributeTextPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
    v4->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
    v5->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
    v6->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  v7 = (CAttributeTextEntry *)operator new(nSize: 0x848u);
  if ( v7 != nullptr )
    ChannelTargetingAttribute = (int)CAttributeTextEntry::CAttributeTextEntry(
                                       this: v7,
                                       parent: this,
                                       panelName: "AttributeValue");
  else
    ChannelTargetingAttribute = 0;
  v9 = (unsigned int)this->m_nFlags >> 2;
  this->m_pData = (CAttributeTextEntry *)ChannelTargetingAttribute;
  if ( (v9 & 1) != 0
    || (Attribute = CBaseAttributePanel::GetAttribute(this),
        (ChannelTargetingAttribute = (int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
  {
    LOBYTE(ChannelTargetingAttribute) = 0;
  }
  else
  {
    ChannelTargetingAttribute = 1;
  }
  this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  vgui::Panel::SetAllowKeyBindingChainToParent(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1048E630
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextPanel::GetMessageMap(CAttributeTextPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048E660
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextPanel::GetAnimMap(CAttributeTextPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1048E670
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextPanel::GetKBMap(CAttributeTextPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494D70
// Name: public: void CBaseAttributePanel::SetAttributeValue<class Color>(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<Color>(CBaseAttributePanel *this, const Color *value)
{
  char *m_szAttributeName; // edi
  CFmtStrN<256> *v4; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  int v8; // eax
  int m_nArrayIndex; // esi
  CDmElement *v10; // ebx
  CFmtStrN<256> v11; // [esp+8h] [ebp-114h] BYREF
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v12; // [esp+114h] [ebp-8h] BYREF

  m_szAttributeName = this->m_szAttributeName;
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "Set %s", this->m_szAttributeName);
  g_pDataModel->StartUndo(this: g_pDataModel, a2: v4->m_szBuf, a3: v4->m_szBuf, a4: 0);
  GetElement = g_pDataModel->GetElement;
  if ( this->m_nArrayIndex >= 0 )
  {
    v8 = ((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v10 = (CDmElement *)v8;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v12);
    CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
      this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v12,
      pElement: v10,
      pAttributeName: m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::Set(
      this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v12,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: m_szAttributeName, type: AT_COLOR)) != nullptr )
    {
      CDmAttribute::SetValue<Color>(this: Attribute, value);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004944C0
// Name: public: static char const __near * CAttributeTextPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeTextPanel::GetPanelClassName()
{
  return "CAttributeTextPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004944D0
// Name: public: virtual void CAttributeTextPanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::SetFont(CAttributeTextPanel *this, unsigned int font)
{
  CBaseAttributePanel::SetFont(this, font);
  this->m_pData->SetFont(this: this->m_pData, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00494590
// Name: public: virtual void CAttributeTextPanel::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Refresh(CAttributeTextPanel *this)
{
  DmAttributeType_t m_AttributeType; // eax
  int AttributeArrayCount; // edi
  CDmElement *v4; // eax
  CDmAttribute *v5; // eax
  const char *v6; // ebx
  int v7; // eax
  const char *v8; // eax
  char *i; // eax
  unsigned int ChannelTargetingAttribute; // eax
  CDmAttribute *Attribute; // eax
  char buf[512]; // [esp+18h] [ebp-200h] BYREF

  m_AttributeType = this->m_AttributeType;
  if ( (unsigned int)(m_AttributeType - 15) > 0xD )
  {
    if ( m_AttributeType == AT_FIRST_VALUE_TYPE )
    {
      this->m_pData->SetText(this: this->m_pData, a2: defaultValue);
    }
    else
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: buf, nLength: 512);
      if ( this->m_AttributeType == AT_VMATRIX )
      {
        for ( i = buf; *i != 0; ++i )
        {
          if ( *i == 10 )
            *i = 32;
        }
      }
      this->m_pData->SetText(this: this->m_pData, a2: buf);
      ChannelTargetingAttribute = (unsigned int)this->m_nFlags >> 2;
      if ( (this->m_nFlags & 4) != 0
        || (Attribute = CBaseAttributePanel::GetAttribute(this),
            (ChannelTargetingAttribute = (unsigned int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
      {
        LOBYTE(ChannelTargetingAttribute) = 0;
      }
      else
      {
        ChannelTargetingAttribute = 1;
      }
      this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
    }
  }
  else
  {
    AttributeArrayCount = CBaseAttributePanel::GetAttributeArrayCount(this);
    if ( this->m_bShowMemoryUsage )
    {
      v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hObject.m_handle);
      v5 = CDmElement::FindAttribute(this: v4, pAttributeName: this->m_szAttributeName);
      v6 = "item";
      if ( AttributeArrayCount != 1 )
        v6 = "items";
      v7 = CDmAttribute::EstimateMemoryUsage(this: v5, depth: TD_DEEP);
      V_snprintf(
        pDest: buf,
        maxLen: 512,
        pFormat: "%d %s (%.3fMB)",
        AttributeArrayCount,
        v6,
        (float)((float)v7 * 0.00000095367432));
    }
    else
    {
      v8 = "item";
      if ( AttributeArrayCount != 1 )
        v8 = "items";
      V_snprintf(pDest: buf, maxLen: 512, pFormat: "%d %s", AttributeArrayCount, v8);
    }
    this->m_pData->SetText(this: this->m_pData, a2: buf);
    this->m_pData->SetEnabled(this: this->m_pData, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494740
// Name: public: void CBaseAttributePanel::SetAttributeValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue(CBaseAttributePanel *this, const char *pValue)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  int v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pValue,
      a3: pValue);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = (CDmElement *)v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
      this: (CDmrDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
      this: (CDmaArrayBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)&v9,
      i: m_nArrayIndex,
      value: (const CUtlSymbolLarge *)&pValue);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pValue,
      a3: pValue);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00494820
// Name: public: char const __near * CAttributeTextPanel::GetTextType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAttributeTextPanel::GetTextType(CAttributeTextPanel *this)
{
  CDmeEditorAttributeInfo *EditorInfo; // eax
  const char *result; // eax

  EditorInfo = CBaseAttributePanel::GetEditorInfo(this);
  if ( EditorInfo == nullptr )
    return defaultValue;
  result = CDmElement::GetValueString(this: EditorInfo, pAttributeName: "texttype");
  if ( result == nullptr )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494840
// Name: public: virtual void CAttributeTextPanel::Apply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeTextPanel::Apply(CAttributeTextPanel *this)
{
  IDmNotify *v2; // ebx
  IDmNotify *v3; // edi
  IDmNotify *m_pNotify; // ebx
  char curvalue[256]; // [esp+Ch] [ebp-200h] BYREF
  char txt[256]; // [esp+10Ch] [ebp-100h] BYREF

  this->m_pData->GetText_2(this: this->m_pData, a2: txt, a3: 256);
  CBaseAttributePanel::SetDirty(this, dirty: false);
  if ( this->m_AttributeType != AT_UNKNOWN )
  {
    CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: curvalue, nLength: 256);
    if ( _V_strcmp(s1: curvalue, s2: txt) == 0 )
      return;
    m_pNotify = this->m_pNotify;
    v3 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0);
    if ( m_pNotify != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: m_pNotify) != 0 )
    {
      v3 = m_pNotify;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4,
      a4: 256);
    CBaseAttributePanel::SetAttributeValueFromString(this, pString: txt);
  }
  else
  {
    v2 = this->m_pNotify;
    v3 = nullptr;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 256))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: "Set Attribute Value",
      a4: 0);
    if ( v2 != nullptr
      && (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 444))(
           a1: g_pDataModel.u,
           a2: v2) != 0 )
    {
      v3 = v2;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 460))(
      a1: g_pDataModel.u,
      a2: "Set Attribute Value",
      a3: 4,
      a4: 256);
    CBaseAttributePanel::SetAttributeValue(this, pValue: defaultValue);
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
  if ( v3 != nullptr )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
      a1: g_pDataModel.u,
      a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00494A80
// Name: public: static void CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
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
// Address: 0x00494B70
// Name: public: virtual CBaseAttributePanel::~CBaseAttributePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::~CBaseAttributePanel(CBaseAttributePanel *this)
{
  CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::~CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>(this: &this->m_ColumnSize);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hEditorTypeDict,
      hElement: this->m_hEditorTypeDict.m_handle,
      handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hEditorInfo, hElement: this->m_hEditorInfo.m_handle, handleType: HT_WEAK);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hObject, hElement: this->m_hObject.m_handle, handleType: HT_WEAK);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00494BE0
// Name: public: CAttributeTextPanel::CAttributeTextPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeTextPanel *__thiscall CAttributeTextPanel::CAttributeTextPanel(
        CAttributeTextPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CAttributeTextEntry *v7; // eax
  int ChannelTargetingAttribute; // eax
  unsigned int v9; // ecx
  CDmAttribute *Attribute; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseAttributePanel::CBaseAttributePanel(this, parent, info);
  this->__vftable = (CAttributeTextPanel_vtbl *)&CAttributeTextPanel::`vftable';
  if ( `CAttributeTextPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
    v4->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
    v5->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
  }
  if ( `CAttributeTextPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeTextPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
    v6->pfnClassName = CAttributeTextPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  }
  CAttributeTextPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pData = nullptr;
  this->m_bShowMemoryUsage = info->m_bShowMemoryUsage;
  v7 = (CAttributeTextEntry *)MemAlloc_Alloc(nSize: 0x848u);
  if ( v7 != nullptr )
    ChannelTargetingAttribute = (int)CAttributeTextEntry::CAttributeTextEntry(
                                       this: v7,
                                       parent: this,
                                       panelName: "AttributeValue");
  else
    ChannelTargetingAttribute = 0;
  v9 = (unsigned int)this->m_nFlags >> 2;
  this->m_pData = (CAttributeTextEntry *)ChannelTargetingAttribute;
  if ( (v9 & 1) != 0
    || (Attribute = CBaseAttributePanel::GetAttribute(this),
        (ChannelTargetingAttribute = (int)FindChannelTargetingAttribute(pTargetAttr: Attribute)) != 0) )
  {
    LOBYTE(ChannelTargetingAttribute) = 0;
  }
  else
  {
    ChannelTargetingAttribute = 1;
  }
  this->m_pData->SetEnabled(this: this->m_pData, a2: ChannelTargetingAttribute);
  this->m_pData->AddActionSignalTarget_2(this: this->m_pData, a2: this);
  vgui::Panel::SetAllowKeyBindingChainToParent(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00494D40
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeTextPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeTextPanel::GetMessageMap(CAttributeTextPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494D70
// Name: public: virtual struct PanelAnimationMap __near * CAttributeTextPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeTextPanel::GetAnimMap(CAttributeTextPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00494D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeTextPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeTextPanel::GetKBMap(CAttributeTextPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeTextPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeTextPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeTextPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  `CAttributeTextPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B470
// Name: public: void CBaseAttributePanel::SetAttributeValue<class Color>(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<Color>(CBaseAttributePanel *this, const Color *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  int v6; // eax
  int m_nArrayIndex; // ebx
  CDmElement *v8; // edi
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hObject.m_handle);
    m_nArrayIndex = this->m_nArrayIndex;
    v8 = (CDmElement *)v6;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v9);
    CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>>::Init(
      this: (CDmrDecorator<Color,CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > > *)&v9,
      pElement: v8,
      pAttributeName: this->m_szAttributeName,
      bAddAttribute: false);
    CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::Set(
      this: (CDmaArrayBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int> > > > *)&v9,
      i: m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: m_szAttributeName, type: AT_COLOR)) != nullptr )
    {
      CDmAttribute::SetValue<Color>(this: Attribute, value);
    }
  }
}

} // namespace sceneviewer
