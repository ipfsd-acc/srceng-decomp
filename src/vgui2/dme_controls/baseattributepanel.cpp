// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseattributepanel.cpp
// Functions: 28
// ============================================================

#include "vgui2\dme_controls\baseattributepanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046A970
// Name: private: virtual void CBaseAttributePanel::OnRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnRefresh(CBaseAttributePanel *this)
{
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046BB30
// Name: public: static char const __near * CBaseAttributePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributePanel::GetPanelClassName()
{
  return "CBaseAttributePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046BB40
// Name: public: virtual void CBaseAttributePanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetFont(CBaseAttributePanel *this, unsigned int font)
{
  this->m_hFont = font;
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0046BB70
// Name: public: void CBaseAttributePanel::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetDirty(CBaseAttributePanel *this, bool dirty)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  InvalidateLayout = this->InvalidateLayout;
  if ( dirty )
    this->m_nFlags |= 8u;
  else
    this->m_nFlags &= ~8u;
  ((void (__stdcall *)(_DWORD, int))InvalidateLayout)(a1: 0, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0046BBB0
// Name: protected: virtual void CBaseAttributePanel::GetPickerBounds(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBaseAttributePanel::GetPickerBounds(CBaseAttributePanel *this, int *x, int *y, int *w, int *h)
{
  double X; // xmm0_8
  double v6; // xmm0_8
  double v7; // [esp+8h] [ebp-14h] OVERLAPPED BYREF
  int viewY; // [esp+10h] [ebp-Ch] BYREF
  int viewWidth; // [esp+14h] [ebp-8h] BYREF
  int viewHeight; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetBounds(this, x: (int *)&v7 + 1, y: &viewY, wide: &viewWidth, tall: &viewHeight);
  X = (double)(viewHeight - 13) * 0.5;
  *x = 2;
  *w = 25;
  if ( ceil(X) >= 0.0 )
  {
    v7 = ceil(X: (double)(viewHeight - 13) * 0.5);
    v6 = v7;
  }
  else
  {
    v6 = 0.0;
  }
  *y = (int)(v6 + 1.0);
  *h = 13;
}

//------------------------------------------------------------------------------
// Address: 0x0046BC60
// Name: public: virtual void CBaseAttributePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::PerformLayout(CBaseAttributePanel *this)
{
  vgui::Panel *v2; // ebx
  vgui::Label *m_pType; // edi
  int viewWidth; // [esp+Ch] [ebp-8h] BYREF
  int viewHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  v2 = this->GetDataPanel(this);
  if ( v2 != nullptr && (this->m_nFlags & 2) != 0 )
    v2->SetVisible(this: v2, a2: false);
  m_pType = this->m_pType;
  if ( m_pType != nullptr && (this->m_nFlags & 1) != 0 )
    m_pType->SetVisible(this: m_pType, a2: false);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  if ( m_pType->IsVisible(this: m_pType) && v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 109, tall: viewHeight);
    vgui::Panel::SetBounds(this: m_pType, x: viewWidth - 75, y: 1, wide: 75, tall: viewHeight);
  }
  else if ( m_pType->IsVisible(this: m_pType) )
  {
    vgui::Panel::SetBounds(this: m_pType, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
  else if ( v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BD80
// Name: private: virtual void CBaseAttributePanel::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnApplyChanges(CBaseAttributePanel *this)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  this->Apply(this);
  InvalidateLayout = this->InvalidateLayout;
  this->m_nFlags &= ~8u;
  InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x0046BE20
// Name: public: virtual void CBaseAttributePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::ApplySchemeSettings(CBaseAttributePanel *this, int pScheme)
{
  int v2; // edi
  vgui::Label *m_pType; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // eax
  CBaseAttributePanel_vtbl *v6; // ebx
  int (__thiscall *v7)(int, int *, const char *, int); // edx
  int (__thiscall *v8)(int, int *, const char *, _DWORD); // eax
  int v9; // ebx
  bool v10; // al
  unsigned int v11; // eax
  int v12; // [esp+0h] [ebp-Ch]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  m_pType = this->m_pType;
  SetFgColor = m_pType->SetFgColor;
  pScheme = -6250336;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pType, a2: -6250336);
  v6 = this->__vftable;
  if ( (this->m_nFlags & 8) != 0 )
  {
    v7 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
    pScheme = 1070097508;
    v12 = *(_DWORD *)v7(a1: v2, a2: &pScheme, a3: "AttributeWidget.DirtyBgColor", a4: 1070097508);
  }
  else
  {
    v8 = *(int (__thiscall **)(int, int *, const char *, _DWORD))(*(_DWORD *)v2 + 20);
    pScheme = 0;
    v12 = *(_DWORD *)v8(a1: v2, a2: &pScheme, a3: "Panel.BgColor", a4: 0);
  }
  ((void (__thiscall *)(CBaseAttributePanel *, int))v6->SetBgColor)(a1: this, a2: v12);
  v9 = *(_DWORD *)v2;
  v10 = this->IsProportional(this);
  v11 = (*(int (__thiscall **)(int, const char *, bool))(v9 + 12))(a1: v2, a2: "DmePropertyVerySmall", a3: v10);
  if ( this->m_hFont == 0 )
    this->m_hFont = v11;
  this->SetFont(this, a2: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x0046BEF0
// Name: public: void CBaseAttributePanel::SetAttributeValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueFromString(CBaseAttributePanel *this, const char *pString)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  char *m_szAttributeName; // [esp-8h] [ebp-10h]
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
    CDmrGenericArray::SetFromString(this: &array, i: this->m_nArrayIndex, pValue: pString);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    CDmElement::SetValueFromString(this: v3, pAttributeName: m_szAttributeName, pValue: pString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BF70
// Name: public: bool CBaseAttributePanel::GetAttributeValueAsString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAttributePanel::GetAttributeValueAsString(
        CBaseAttributePanel *this,
        char *pBuf,
        unsigned int nLength)
{
  CDmElement *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v4 != nullptr )
  {
    if ( this->m_nArrayIndex >= 0 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
      CDmrGenericArrayConst::GetAsString(this: &array, i: this->m_nArrayIndex, pBuffer: pBuf, nBufLen: nLength);
    }
    else
    {
      CDmElement::GetValueAsString(this: v4, pAttributeName: this->m_szAttributeName, pBuffer: pBuf, nBufLen: nLength);
    }
    return 1;
  }
  else
  {
    *pBuf = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C000
// Name: public: class CDmAttribute __near * CBaseAttributePanel::GetAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAttributePanel::GetAttribute(CBaseAttributePanel *this)
{
  CDmElement *result; // eax

  result = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( result != nullptr )
    return (CDmElement *)CDmElement::FindAttribute(this: result, pAttributeName: this->m_szAttributeName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C030
// Name: public: virtual void CBaseAttributePanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnCreateDragData(CBaseAttributePanel *this, KeyValues *msg)
{
  CExpressionCalculator *v3; // eax
  int BufferType; // eax
  const char *v5; // eax
  DmAttributeType_t m_AttributeType; // eax
  char pTemp[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
    {
      v3 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    }
    else
    {
      BufferType = -1;
    }
    KeyValues::SetInt(this: msg, keyName: "root", value: BufferType);
    v5 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: this->m_AttributeType);
    KeyValues::SetString(this: msg, keyName: "type", value: v5);
    KeyValues::SetString(this: msg, keyName: "attributename", value: this->m_szAttributeName);
    if ( this->m_nArrayIndex >= 0 )
      KeyValues::SetInt(this: msg, keyName: "arrayIndex", value: this->m_nArrayIndex);
    m_AttributeType = this->m_AttributeType;
    if ( m_AttributeType != AT_FIRST_VALUE_TYPE && m_AttributeType != AT_FIRST_ARRAY_TYPE )
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: pTemp, nLength: 0x200u);
      KeyValues::SetString(this: msg, keyName: "text", value: pTemp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C190
// Name: private: void CBaseAttributePanel::InitializeFlags(struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::InitializeFlags(CBaseAttributePanel *this, const AttributeWidgetInfo_t *info)
{
  CDmeEditorAttributeInfo *m_pEditorInfo; // eax
  CDmAttribute *Attribute; // eax

  this->m_nFlags = 0;
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    if ( m_pEditorInfo->m_bHideType.m_Storage )
      this->m_nFlags = 1;
    if ( info->m_pEditorInfo->m_bHideValue.m_Storage )
      this->m_nFlags |= 2u;
    if ( info->m_pEditorInfo->m_bIsReadOnly.m_Storage )
      this->m_nFlags |= 4u;
  }
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x20) != 0 )
    this->m_nFlags |= 4u;
  if ( info->m_bAutoApply )
    this->m_nFlags |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x0046C210
// Name: public: class CDmeEditorAttributeInfo __near * CBaseAttributePanel::GetEditorInfo(void)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CBaseAttributePanel::GetEditorInfo(CBaseAttributePanel *this)
{
  return (CDmeEditorAttributeInfo *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hEditorInfo.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x0046C230
// Name: protected: bool CBaseAttributePanel::HasAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAttributePanel::HasAttribute(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  return CDmElement::HasAttribute(this: v2, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN);
}

//------------------------------------------------------------------------------
// Address: 0x0046C260
// Name: protected: int CBaseAttributePanel::GetAttributeArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CBaseAttributePanel::GetAttributeArrayCount(CBaseAttributePanel *this)
{
  CDmElement *v1; // eax
  CDmrGenericArrayConst array; // [esp+0h] [ebp-4h] BYREF

  array.m_pAttribute = (CDmAttribute *)this;
  v1 = (CDmElement *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, char *))g_pDataModel->GetElement)(
                       a1: g_pDataModel,
                       a2: this->m_hObject.m_handle,
                       a3: this->m_szAttributeName);
  CDmrGenericArrayConst::CDmrGenericArrayConst(
    this: &array,
    pElement: v1,
    pAttributeName: (const char *)array.m_pAttribute);
  if ( array.m_pAttribute != nullptr )
    return CDmrGenericArrayConst::Count(this: &array);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046CDD0
// Name: enum DmElementHandle_t const __near & GetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__cdecl GetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( pAttribute == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( *pAttribute == 0 )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute);
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  array.m_pAttribute = Attribute;
  array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  return &array.m_pStorage->m_Memory.m_pMemory[nArrayIndex];
}

//------------------------------------------------------------------------------
// Address: 0x0046CE40
// Name: void SetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex,
        const DmElementHandle_t *value)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement != nullptr
    && pAttribute != nullptr
    && *pAttribute != 0
    && (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute)) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = Attribute;
    array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  pElement = (CDmElement *)*value;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Set(
    this: &array,
    i: nArrayIndex,
    value: (DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0046CEB0
// Name: public: enum DmElementHandle_t const __near & CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      return (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                  pElement: v2,
                                                  pAttribute: m_szAttributeName,
                                                  nArrayIndex: m_nArrayIndex);
    else
      return CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    return (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CF10
// Name: public: void CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this,
        DmElementHandle_t *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    SetArrayAttributeValue<enum DmElementHandle_t>(
      pElement: v6,
      pAttribute: this->m_szAttributeName,
      nArrayIndex: this->m_nArrayIndex,
      value);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: v4,
                        pAttributeName: m_szAttributeName,
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D010
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D0A0
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Refresh";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D130
// Name: public: class CDmElement __near * CBaseAttributePanel::GetAttributeValueElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAttributePanel::GetAttributeValueElement(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmaVar<enum DmElementHandle_t> *ArrayAttribute; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi
  CDmElement *v6; // eax
  CDmElement *v7; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                            pElement: v2,
                                                            pAttribute: m_szAttributeName,
                                                            nArrayIndex: m_nArrayIndex);
    else
      ArrayAttribute = CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: ArrayAttribute->m_Storage.m_Handle);
  v7 = v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
    return v7;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046D1C0
// Name: public: void CBaseAttributePanel::SetAttributeValueElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueElement(CBaseAttributePanel *this, CDmElement *pElement)
{
  pElement = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(this, value: (DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0046D260
// Name: public: CBaseAttributePanel::CBaseAttributePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributePanel *__thiscall CBaseAttributePanel::CBaseAttributePanel(
        CBaseAttributePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmElement *m_pElement; // ecx
  DmElementHandle_t BufferType; // eax
  CExpressionCalculator *m_pEditorInfo; // ecx
  DmElementHandle_t v10; // eax
  CExpressionCalculator *m_pEditorTypeDictionary; // ecx
  DmElementHandle_t v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  int v15; // eax
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v17; // eax
  bool v18; // sf
  vgui::Label_vtbl *v19; // edi
  const char *v20; // eax
  CBaseAttributePanel::colinfo_t search; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: info->m_pAttributeName);
  this->__vftable = (CBaseAttributePanel_vtbl *)&CBaseAttributePanel::`vftable';
  if ( `CBaseAttributePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v4->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
    v5->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
    v6->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(a1: (int)&savedregs);
  this->m_pType = nullptr;
  m_pElement = info->m_pElement;
  this->m_hObject.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pElement);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hObject, h: BufferType);
  m_pEditorInfo = (CExpressionCalculator *)info->m_pEditorInfo;
  this->m_hEditorInfo.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorInfo != nullptr )
    v10 = CCodecBuffer_Block::GetBufferType(this: m_pEditorInfo);
  else
    v10 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorAttributeInfo,0>::Set(this: &this->m_hEditorInfo, h: v10);
  m_pEditorTypeDictionary = (CExpressionCalculator *)info->m_pEditorTypeDictionary;
  this->m_hEditorTypeDict.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorTypeDictionary != nullptr )
    v12 = CCodecBuffer_Block::GetBufferType(this: m_pEditorTypeDictionary);
  else
    v12 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hEditorTypeDict, h: v12);
  this->m_nArrayIndex = info->m_nArrayIndex;
  this->m_pNotify = info->m_pNotify;
  this->m_ColumnSize.m_LessFunc = (bool (__cdecl *)(const CBaseAttributePanel::colinfo_t *, const CBaseAttributePanel::colinfo_t *))CDefOps<CDmAttribute *>::LessFunc;
  this->m_ColumnSize.m_Elements.m_pMemory = nullptr;
  this->m_ColumnSize.m_Elements.m_nAllocationCount = 0;
  this->m_ColumnSize.m_Elements.m_nGrowSize = 0;
  this->m_ColumnSize.m_Root = -1;
  this->m_ColumnSize.m_FirstFree = -1;
  this->m_ColumnSize.m_NumElements = 0;
  this->m_ColumnSize.m_LastAlloc.index = -1;
  this->m_ColumnSize.m_pElements = this->m_ColumnSize.m_Elements.m_pMemory;
  CBaseAttributePanel::InitializeFlags(this, info);
  V_strncpy(pDest: this->m_szAttributeName, pSrc: info->m_pAttributeName, maxLen: 256);
  v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "AttributeType", text: defaultValue);
  else
    v14 = nullptr;
  this->m_pType = v14;
  search.panel = v14;
  v15 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Find(
          this: &this->m_ColumnSize,
          &search);
  if ( v15 == -1 )
    v15 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Insert(
            this: &this->m_ColumnSize,
            insert: &search);
  this->m_ColumnSize.m_Elements.m_pMemory[v15].m_Data.width = 100;
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr )
    v17 = Attribute->m_nFlags & 0x1F;
  else
    v17 = AT_UNKNOWN;
  v18 = this->m_nArrayIndex < 0;
  this->m_AttributeType = v17;
  if ( !v18 )
    this->m_AttributeType = v17 - 14;
  v19 = this->m_pType->__vftable;
  v20 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: this->m_AttributeType);
  v19->SetText_2(this: this->m_pType, a2: v20);
  this->m_hFont = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046D500
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributePanel::GetMessageMap(CBaseAttributePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D530
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributePanel::GetAnimMap(CBaseAttributePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046D540
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributePanel::GetKBMap(CBaseAttributePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048EFD0
// Name: public: static char const __near * CBaseAttributePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributePanel::GetPanelClassName()
{
  return "CBaseAttributePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1048EFE0
// Name: public: virtual void CBaseAttributePanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetFont(CBaseAttributePanel *this, unsigned int font)
{
  this->m_hFont = font;
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1048F010
// Name: public: void CBaseAttributePanel::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetDirty(CBaseAttributePanel *this, bool dirty)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  InvalidateLayout = this->InvalidateLayout;
  if ( dirty )
    this->m_nFlags |= 8u;
  else
    this->m_nFlags &= ~8u;
  ((void (__stdcall *)(_DWORD, int))InvalidateLayout)(a1: 0, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1048F050
// Name: protected: virtual void CBaseAttributePanel::GetPickerBounds(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::GetPickerBounds(CBaseAttributePanel *this, int *x, int *y, int *w, int *h)
{
  double v5; // xmm0_8
  double v6; // xmm0_8
  double X; // [esp+0h] [ebp-14h] BYREF
  int v8; // [esp+8h] [ebp-Ch] BYREF
  int viewX; // [esp+Ch] [ebp-8h] BYREF
  int viewY; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetBounds(this, x: (int *)&X + 1, y: &v8, wide: &viewX, tall: &viewY);
  v5 = (double)(viewY - 13) * 0.5;
  *x = 2;
  *w = 25;
  if ( ceil(X: v5) >= 0.0 )
  {
    X = ceil(X: (double)(viewY - 13) * 0.5);
    v6 = X;
  }
  else
  {
    v6 = 0.0;
  }
  *y = (int)(v6 + 1.0);
  *h = 13;
}

//------------------------------------------------------------------------------
// Address: 0x1048F100
// Name: public: virtual void CBaseAttributePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::PerformLayout(CBaseAttributePanel *this)
{
  vgui::Panel *v2; // ebx
  vgui::Label *m_pType; // edi
  int viewWidth; // [esp+Ch] [ebp-8h] BYREF
  int viewHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  v2 = this->GetDataPanel(this);
  if ( v2 != nullptr && (this->m_nFlags & 2) != 0 )
    v2->SetVisible(this: v2, a2: false);
  m_pType = this->m_pType;
  if ( m_pType != nullptr && (this->m_nFlags & 1) != 0 )
    m_pType->SetVisible(this: m_pType, a2: false);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  if ( m_pType->IsVisible(this: m_pType) && v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 109, tall: viewHeight);
    vgui::Panel::SetBounds(this: m_pType, x: viewWidth - 75, y: 1, wide: 75, tall: viewHeight);
  }
  else if ( m_pType->IsVisible(this: m_pType) )
  {
    vgui::Panel::SetBounds(this: m_pType, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
  else if ( v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048F220
// Name: private: virtual void CBaseAttributePanel::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnApplyChanges(CBaseAttributePanel *this)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  this->Apply(this);
  InvalidateLayout = this->InvalidateLayout;
  this->m_nFlags &= ~8u;
  InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1048F2D0
// Name: public: virtual void CBaseAttributePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::ApplySchemeSettings(CBaseAttributePanel *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Label *m_pType; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // eax
  CBaseAttributePanel_vtbl *v6; // ebx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  Color *(__thiscall *v8)(vgui::IScheme *, Color *, const char *, Color); // eax
  vgui::IScheme_vtbl *v9; // ebx
  bool v10; // al
  unsigned int v11; // eax
  int v12; // [esp+0h] [ebp-Ch]

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  m_pType = this->m_pType;
  SetFgColor = m_pType->SetFgColor;
  pScheme = -6250336;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pType, a2: -6250336);
  v6 = this->__vftable;
  if ( (this->m_nFlags & 8) != 0 )
  {
    GetColor = v2->GetColor;
    pScheme = 1070097508;
    v12 = *(_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                       a1: v2,
                       a2: &pScheme,
                       a3: "AttributeWidget.DirtyBgColor",
                       a4: 1070097508);
  }
  else
  {
    v8 = v2->GetColor;
    pScheme = 0;
    v12 = *(_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, _DWORD))v8)(
                       a1: v2,
                       a2: &pScheme,
                       a3: "Panel.BgColor",
                       a4: 0);
  }
  ((void (__thiscall *)(CBaseAttributePanel *, int))v6->SetBgColor)(a1: this, a2: v12);
  v9 = v2->__vftable;
  v10 = this->IsProportional(this);
  v11 = v9->GetFont(this: v2, a2: "DmePropertyVerySmall", a3: v10);
  if ( this->m_hFont == 0 )
    this->m_hFont = v11;
  this->SetFont(this, a2: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x1048F3A0
// Name: public: void CBaseAttributePanel::SetAttributeValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueFromString(CBaseAttributePanel *this, const char *pString)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  char *m_szAttributeName; // [esp-8h] [ebp-10h]
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
    CDmrGenericArray::SetFromString(this: &array, i: this->m_nArrayIndex, pValue: pString);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
    CDmElement::SetValueFromString(this: v3, pAttributeName: m_szAttributeName, pValue: pString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048F420
// Name: public: bool CBaseAttributePanel::GetAttributeValueAsString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAttributePanel::GetAttributeValueAsString(
        CBaseAttributePanel *this,
        char *pBuf,
        unsigned int nLength)
{
  CDmElement *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v4 != nullptr )
  {
    if ( this->m_nArrayIndex >= 0 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
      CDmrGenericArrayConst::GetAsString(this: &array, i: this->m_nArrayIndex, pBuffer: pBuf, nBufLen: nLength);
    }
    else
    {
      CDmElement::GetValueAsString(this: v4, pAttributeName: this->m_szAttributeName, pBuffer: pBuf, nBufLen: nLength);
    }
    return 1;
  }
  else
  {
    *pBuf = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048F4B0
// Name: public: class CDmAttribute __near * CBaseAttributePanel::GetAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAttributePanel::GetAttribute(CBaseAttributePanel *this)
{
  CDmElement *result; // eax

  result = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( result != nullptr )
    return (CDmElement *)CDmElement::FindAttribute(this: result, pAttributeName: this->m_szAttributeName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048F4E0
// Name: public: virtual void CBaseAttributePanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnCreateDragData(CBaseAttributePanel *this, KeyValues *msg)
{
  CExpressionCalculator *v3; // eax
  int BufferType; // eax
  char *v5; // eax
  DmAttributeType_t m_AttributeType; // eax
  char pTemp[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
  {
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle) != nullptr )
    {
      v3 = (CExpressionCalculator *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    }
    else
    {
      BufferType = -1;
    }
    KeyValues::SetInt(this: msg, keyName: "root", value: BufferType);
    v5 = (char *)g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: this->m_AttributeType);
    KeyValues::SetString(this: msg, keyName: "type", value: v5);
    KeyValues::SetString(this: msg, keyName: "attributename", value: this->m_szAttributeName);
    if ( this->m_nArrayIndex >= 0 )
      KeyValues::SetInt(this: msg, keyName: "arrayIndex", value: this->m_nArrayIndex);
    m_AttributeType = this->m_AttributeType;
    if ( m_AttributeType != AT_FIRST_VALUE_TYPE && m_AttributeType != AT_FIRST_ARRAY_TYPE )
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: pTemp, nLength: 0x200u);
      KeyValues::SetString(this: msg, keyName: "text", value: pTemp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048F640
// Name: private: void CBaseAttributePanel::InitializeFlags(struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::InitializeFlags(CBaseAttributePanel *this, const AttributeWidgetInfo_t *info)
{
  CDmeEditorAttributeInfo *m_pEditorInfo; // eax
  CDmAttribute *Attribute; // eax

  this->m_nFlags = 0;
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    if ( m_pEditorInfo->m_bHideType.m_Storage )
      this->m_nFlags = 1;
    if ( info->m_pEditorInfo->m_bHideValue.m_Storage )
      this->m_nFlags |= 2u;
    if ( info->m_pEditorInfo->m_bIsReadOnly.m_Storage )
      this->m_nFlags |= 4u;
  }
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x20) != 0 )
    this->m_nFlags |= 4u;
  if ( info->m_bAutoApply )
    this->m_nFlags |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x1048F6C0
// Name: public: class CDmeEditorAttributeInfo __near * CBaseAttributePanel::GetEditorInfo(void)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CBaseAttributePanel::GetEditorInfo(CBaseAttributePanel *this)
{
  return (CDmeEditorAttributeInfo *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hEditorInfo.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x1048F6E0
// Name: protected: bool CBaseAttributePanel::HasAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAttributePanel::HasAttribute(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  return CDmElement::HasAttribute(this: v2, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN);
}

//------------------------------------------------------------------------------
// Address: 0x1048F710
// Name: protected: int CBaseAttributePanel::GetAttributeArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CBaseAttributePanel::GetAttributeArrayCount(CBaseAttributePanel *this)
{
  CDmElement *v1; // eax
  CDmrGenericArrayConst array; // [esp+0h] [ebp-4h] BYREF

  array.m_pAttribute = (CDmAttribute *)this;
  v1 = (CDmElement *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, char *))g_pDataModel->GetElement)(
                       a1: g_pDataModel,
                       a2: this->m_hObject.m_handle,
                       a3: this->m_szAttributeName);
  CDmrGenericArrayConst::CDmrGenericArrayConst(
    this: &array,
    pElement: v1,
    pAttributeName: (const char *)array.m_pAttribute);
  if ( array.m_pAttribute != nullptr )
    return CDmrGenericArrayConst::Count(this: &array);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10490280
// Name: enum DmElementHandle_t const __near & GetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__cdecl GetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( pAttribute == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( *pAttribute == 0 )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute);
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  array.m_pAttribute = Attribute;
  array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  return &array.m_pStorage->m_Memory.m_pMemory[nArrayIndex];
}

//------------------------------------------------------------------------------
// Address: 0x104902F0
// Name: void SetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex,
        const DmElementHandle_t *value)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement != nullptr
    && pAttribute != nullptr
    && *pAttribute != 0
    && (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute)) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = Attribute;
    array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  pElement = (CDmElement *)*value;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Set(
    this: &array,
    i: nArrayIndex,
    value: (DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10490360
// Name: public: enum DmElementHandle_t const __near & CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      return (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                  pElement: v2,
                                                  pAttribute: m_szAttributeName,
                                                  nArrayIndex: m_nArrayIndex);
    else
      return CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    return (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104903C0
// Name: public: void CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this,
        DmElementHandle_t *value)
{
  char *m_szAttributeName; // edi
  CFmtStrN<256> *v4; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // eax
  DmElementHandle_t m_handle; // [esp+0h] [ebp-114h]
  CFmtStrN<256> v10; // [esp+8h] [ebp-10Ch] BYREF

  m_szAttributeName = this->m_szAttributeName;
  v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v10, pszFormat: "Set %s", this->m_szAttributeName);
  g_pDataModel->StartUndo(this: g_pDataModel, a2: v4->m_szBuf, a3: v4->m_szBuf, a4: 0);
  GetElement = g_pDataModel->GetElement;
  m_handle = this->m_hObject.m_handle;
  if ( this->m_nArrayIndex >= 0 )
  {
    v8 = (CDmElement *)((int (__cdecl *)(DmElementHandle_t))GetElement)(a1: m_handle);
    SetArrayAttributeValue<enum DmElementHandle_t>(
      pElement: v8,
      pAttribute: m_szAttributeName,
      nArrayIndex: this->m_nArrayIndex,
      value);
  }
  else
  {
    v6 = (CDmElement *)((int (__cdecl *)(DmElementHandle_t))GetElement)(a1: m_handle);
    Attribute = CDmElement::FindAttribute(this: v6, pAttributeName: m_szAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(
                        this: v6,
                        pAttributeName: m_szAttributeName,
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value);
    }
  }
  g_pDataModel->FinishUndo(this: g_pDataModel);
}

//------------------------------------------------------------------------------
// Address: 0x104904F0
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10490580
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Refresh";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10490610
// Name: public: class CDmElement __near * CBaseAttributePanel::GetAttributeValueElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAttributePanel::GetAttributeValueElement(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmaVar<enum DmElementHandle_t> *ArrayAttribute; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi
  CDmElement *v6; // eax
  CDmElement *v7; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                            pElement: v2,
                                                            pAttribute: m_szAttributeName,
                                                            nArrayIndex: m_nArrayIndex);
    else
      ArrayAttribute = CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: ArrayAttribute->m_Storage.m_Handle);
  v7 = v6;
  if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
    return v7;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104906A0
// Name: public: void CBaseAttributePanel::SetAttributeValueElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueElement(CBaseAttributePanel *this, CDmElement *pElement)
{
  pElement = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(this, value: (DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x10490740
// Name: public: CBaseAttributePanel::CBaseAttributePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributePanel *__userpurge CBaseAttributePanel::CBaseAttributePanel@<eax>(
        CBaseAttributePanel *this@<ecx>,
        PanelAnimationMap *a2@<edi>,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  CDmElement *m_pElement; // ecx
  DmElementHandle_t BufferType; // eax
  CDmeEditorAttributeInfo *m_pEditorInfo; // ecx
  DmElementHandle_t v8; // eax
  CDmeEditorTypeDictionary *m_pEditorTypeDictionary; // ecx
  DmElementHandle_t v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  int v13; // eax
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v15; // eax
  bool v16; // sf
  vgui::Label_vtbl *v17; // edi
  const char *v18; // eax
  CBaseAttributePanel::colinfo_t search; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: info->m_pAttributeName);
  this->__vftable = (CBaseAttributePanel_vtbl *)&CBaseAttributePanel::`vftable';
  if ( `CBaseAttributePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    a2[1].entries.m_Memory.m_pMemory = (PanelAnimationMapEntry *)CBaseAttributePanel::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained = 1;
    a2 = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
    a2->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    a2->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::KB_ChainToMap'::`2'::chained = 1;
    a2 = (PanelAnimationMap *)vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
    a2[2].entries.m_Size = (int)CBaseAttributePanel::GetPanelClassName;
    a2->pfnClassName = (const char *(__cdecl *)())vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(a1: (int)&savedregs);
  this->m_pType = nullptr;
  m_pElement = info->m_pElement;
  this->m_hObject.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pElement);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hObject, h: BufferType);
  m_pEditorInfo = info->m_pEditorInfo;
  this->m_hEditorInfo.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorInfo != nullptr )
    v8 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pEditorInfo);
  else
    v8 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorAttributeInfo,0>::Set(this: &this->m_hEditorInfo, h: v8);
  m_pEditorTypeDictionary = info->m_pEditorTypeDictionary;
  this->m_hEditorTypeDict.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorTypeDictionary != nullptr )
    v10 = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pEditorTypeDictionary);
  else
    v10 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hEditorTypeDict, h: v10);
  this->m_nArrayIndex = info->m_nArrayIndex;
  this->m_pNotify = info->m_pNotify;
  this->m_ColumnSize.m_LessFunc = (bool (__cdecl *)(const CBaseAttributePanel::colinfo_t *, const CBaseAttributePanel::colinfo_t *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  this->m_ColumnSize.m_Elements.m_pMemory = nullptr;
  this->m_ColumnSize.m_Elements.m_nAllocationCount = 0;
  this->m_ColumnSize.m_Elements.m_nGrowSize = 0;
  this->m_ColumnSize.m_Root = -1;
  this->m_ColumnSize.m_FirstFree = -1;
  this->m_ColumnSize.m_NumElements = 0;
  this->m_ColumnSize.m_LastAlloc.index = -1;
  this->m_ColumnSize.m_pElements = this->m_ColumnSize.m_Elements.m_pMemory;
  CBaseAttributePanel::InitializeFlags(this, info);
  V_strncpy(pDest: this->m_szAttributeName, pSrc: (char *)info->m_pAttributeName, maxLen: 256);
  v11 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "AttributeType", text: &var);
  else
    v12 = nullptr;
  this->m_pType = v12;
  search.panel = v12;
  v13 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Find(
          this: &this->m_ColumnSize,
          &search);
  if ( v13 == -1 )
    v13 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Insert(
            this: &this->m_ColumnSize,
            (const char *)a2,
            insert: &search);
  this->m_ColumnSize.m_Elements.m_pMemory[v13].m_Data.width = 100;
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr )
    v15 = Attribute->m_nFlags & 0x1F;
  else
    v15 = AT_UNKNOWN;
  v16 = this->m_nArrayIndex < 0;
  this->m_AttributeType = v15;
  if ( !v16 )
    this->m_AttributeType = v15 - 14;
  v17 = this->m_pType->__vftable;
  v18 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: this->m_AttributeType);
  v17->SetText(this: this->m_pType, a2: v18);
  this->m_hFont = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104909E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributePanel::GetMessageMap(CBaseAttributePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10490A10
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributePanel::GetAnimMap(CBaseAttributePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10490A20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributePanel::GetKBMap(CBaseAttributePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10492720
// Name: private: virtual void CBaseAttributePanel::OnRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnRefresh(CBaseAttributePanel *this)
{
  this->Refresh(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004956B0
// Name: public: static char const __near * CBaseAttributePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAttributePanel::GetPanelClassName()
{
  return "CBaseAttributePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004956C0
// Name: public: virtual void CBaseAttributePanel::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetFont(CBaseAttributePanel *this, unsigned int font)
{
  this->m_hFont = font;
  this->m_pType->SetFont(this: this->m_pType, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x004956F0
// Name: public: void CBaseAttributePanel::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetDirty(CBaseAttributePanel *this, bool dirty)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  InvalidateLayout = this->InvalidateLayout;
  if ( dirty )
    this->m_nFlags |= 8u;
  else
    this->m_nFlags &= ~8u;
  ((void (__stdcall *)(_DWORD, int))InvalidateLayout)(a1: 0, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00495730
// Name: protected: virtual void CBaseAttributePanel::GetPickerBounds(int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBaseAttributePanel::GetPickerBounds(CBaseAttributePanel *this, int *x, int *y, int *w, int *h)
{
  double X; // xmm0_8
  double v6; // xmm0_8
  double v7; // [esp+8h] [ebp-14h] OVERLAPPED BYREF
  int viewY; // [esp+10h] [ebp-Ch] BYREF
  int viewWidth; // [esp+14h] [ebp-8h] BYREF
  int viewHeight; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetBounds(this, x: (int *)&v7 + 1, y: &viewY, wide: &viewWidth, tall: &viewHeight);
  X = (double)(viewHeight - 13) * 0.5;
  *x = 2;
  *w = 25;
  if ( ceil(X) >= 0.0 )
  {
    v7 = ceil(X: (double)(viewHeight - 13) * 0.5);
    v6 = v7;
  }
  else
  {
    v6 = 0.0;
  }
  *y = (int)(v6 + 1.0);
  *h = 13;
}

//------------------------------------------------------------------------------
// Address: 0x004957E0
// Name: public: virtual void CBaseAttributePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::PerformLayout(CBaseAttributePanel *this)
{
  vgui::Panel *v2; // ebx
  vgui::Label *m_pType; // edi
  int viewWidth; // [esp+Ch] [ebp-8h] BYREF
  int viewHeight; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  v2 = this->GetDataPanel(this);
  if ( v2 != nullptr && (this->m_nFlags & 2) != 0 )
    v2->SetVisible(this: v2, a2: false);
  m_pType = this->m_pType;
  if ( m_pType != nullptr && (this->m_nFlags & 1) != 0 )
    m_pType->SetVisible(this: m_pType, a2: false);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  if ( m_pType->IsVisible(this: m_pType) && v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 109, tall: viewHeight);
    vgui::Panel::SetBounds(this: m_pType, x: viewWidth - 75, y: 1, wide: 75, tall: viewHeight);
  }
  else if ( m_pType->IsVisible(this: m_pType) )
  {
    vgui::Panel::SetBounds(this: m_pType, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
  else if ( v2->IsVisible(this: v2) )
  {
    vgui::Panel::SetBounds(this: v2, x: 30, y: 1, wide: viewWidth - 34, tall: viewHeight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495900
// Name: private: virtual void CBaseAttributePanel::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnApplyChanges(CBaseAttributePanel *this)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  this->Apply(this);
  InvalidateLayout = this->InvalidateLayout;
  this->m_nFlags &= ~8u;
  InvalidateLayout(this, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00495930
// Name: private: virtual void CBaseAttributePanel::OnRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnRefresh(CBaseAttributePanel *this)
{
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x004959C0
// Name: public: virtual void CBaseAttributePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::ApplySchemeSettings(CBaseAttributePanel *this, int pScheme)
{
  int v2; // edi
  vgui::Label *m_pType; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // eax
  CBaseAttributePanel_vtbl *v6; // ebx
  int (__thiscall *v7)(int, int *, const char *, int); // edx
  int (__thiscall *v8)(int, int *, const char *, _DWORD); // eax
  int v9; // ebx
  bool v10; // al
  unsigned int v11; // eax
  int v12; // [esp+0h] [ebp-Ch]

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  m_pType = this->m_pType;
  SetFgColor = m_pType->SetFgColor;
  pScheme = -6250336;
  ((void (__thiscall *)(vgui::Label *, int))SetFgColor)(a1: m_pType, a2: -6250336);
  v6 = this->__vftable;
  if ( (this->m_nFlags & 8) != 0 )
  {
    v7 = *(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v2 + 20);
    pScheme = 1070097508;
    v12 = *(_DWORD *)v7(a1: v2, a2: &pScheme, a3: "AttributeWidget.DirtyBgColor", a4: 1070097508);
  }
  else
  {
    v8 = *(int (__thiscall **)(int, int *, const char *, _DWORD))(*(_DWORD *)v2 + 20);
    pScheme = 0;
    v12 = *(_DWORD *)v8(a1: v2, a2: &pScheme, a3: "Panel.BgColor", a4: 0);
  }
  ((void (__thiscall *)(CBaseAttributePanel *, int))v6->SetBgColor)(a1: this, a2: v12);
  v9 = *(_DWORD *)v2;
  v10 = this->IsProportional(this);
  v11 = (*(int (__thiscall **)(int, const char *, bool))(v9 + 12))(a1: v2, a2: "DmePropertyVerySmall", a3: v10);
  if ( this->m_hFont == 0 )
    this->m_hFont = v11;
  this->SetFont(this, a2: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x00495A90
// Name: public: void CBaseAttributePanel::SetAttributeValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueFromString(CBaseAttributePanel *this, const char *pString)
{
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  char *m_szAttributeName; // [esp-8h] [ebp-10h]
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nArrayIndex >= 0 )
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
    CDmrGenericArray::SetFromString(this: &array, i: this->m_nArrayIndex, pValue: pString);
  }
  else
  {
    m_szAttributeName = this->m_szAttributeName;
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    CDmElement::SetValueFromString(this: v3, pAttributeName: m_szAttributeName, pValue: pString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495B10
// Name: public: bool CBaseAttributePanel::GetAttributeValueAsString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAttributePanel::GetAttributeValueAsString(
        CBaseAttributePanel *this,
        char *pBuf,
        unsigned int nLength)
{
  CDmElement *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  if ( v4 != nullptr )
  {
    if ( this->m_nArrayIndex >= 0 )
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pElement: v4, pAttributeName: this->m_szAttributeName);
      CDmrGenericArrayConst::GetAsString(this: &array, i: this->m_nArrayIndex, pBuffer: pBuf, nBufLen: nLength);
    }
    else
    {
      CDmElement::GetValueAsString(this: v4, pAttributeName: this->m_szAttributeName, pBuffer: pBuf, nBufLen: nLength);
    }
    return 1;
  }
  else
  {
    *pBuf = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495BA0
// Name: public: class CDmAttribute __near * CBaseAttributePanel::GetAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CBaseAttributePanel::GetAttribute(CBaseAttributePanel *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_hObject.m_handle);
  if ( result != nullptr )
    return CDmElement::FindAttribute(this: (CDmElement *)result, pAttributeName: this->m_szAttributeName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495BD0
// Name: public: virtual void CBaseAttributePanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::OnCreateDragData(CBaseAttributePanel *this, KeyValues *msg)
{
  CExpressionCalculator *v3; // eax
  int BufferType; // eax
  const char *v5; // eax
  DmAttributeType_t m_AttributeType; // eax
  char pTemp[512]; // [esp+4h] [ebp-200h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hObject.m_handle) != 0 )
  {
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hObject.m_handle) != 0 )
    {
      v3 = (CExpressionCalculator *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                      a1: g_pDataModel.u,
                                      a2: this->m_hObject.m_handle);
      BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    }
    else
    {
      BufferType = -1;
    }
    KeyValues::SetInt(this: msg, keyName: "root", value: BufferType);
    v5 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeType_t))(*(_DWORD *)g_pDataModel.u.m_Id + 88))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeType);
    KeyValues::SetString(this: msg, keyName: "type", value: v5);
    KeyValues::SetString(this: msg, keyName: "attributename", value: this->m_szAttributeName);
    if ( this->m_nArrayIndex >= 0 )
      KeyValues::SetInt(this: msg, keyName: "arrayIndex", value: this->m_nArrayIndex);
    m_AttributeType = this->m_AttributeType;
    if ( m_AttributeType != AT_FIRST_VALUE_TYPE && m_AttributeType != AT_FIRST_ARRAY_TYPE )
    {
      CBaseAttributePanel::GetAttributeValueAsString(this, pBuf: pTemp, nLength: 0x200u);
      KeyValues::SetString(this: msg, keyName: "text", value: pTemp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495D30
// Name: private: void CBaseAttributePanel::InitializeFlags(struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::InitializeFlags(CBaseAttributePanel *this, const AttributeWidgetInfo_t *info)
{
  CDmeEditorAttributeInfo *m_pEditorInfo; // eax
  CDmAttribute *Attribute; // eax

  this->m_nFlags = 0;
  m_pEditorInfo = info->m_pEditorInfo;
  if ( m_pEditorInfo != nullptr )
  {
    if ( m_pEditorInfo->m_bHideType.m_Storage )
      this->m_nFlags = 1;
    if ( info->m_pEditorInfo->m_bHideValue.m_Storage )
      this->m_nFlags |= 2u;
    if ( info->m_pEditorInfo->m_bIsReadOnly.m_Storage )
      this->m_nFlags |= 4u;
  }
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x20) != 0 )
    this->m_nFlags |= 4u;
  if ( info->m_bAutoApply )
    this->m_nFlags |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x00495DB0
// Name: public: class CDmeEditorAttributeInfo __near * CBaseAttributePanel::GetEditorInfo(void)
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CBaseAttributePanel::GetEditorInfo(CBaseAttributePanel *this)
{
  return (*(CDmeEditorAttributeInfo *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hEditorInfo.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00495DD0
// Name: protected: bool CBaseAttributePanel::HasAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAttributePanel::HasAttribute(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  return CDmElement::HasAttribute(this: v2, pAttributeName: this->m_szAttributeName, type: AT_UNKNOWN);
}

//------------------------------------------------------------------------------
// Address: 0x00495E00
// Name: protected: int CBaseAttributePanel::GetAttributeArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CBaseAttributePanel::GetAttributeArrayCount(CBaseAttributePanel *this)
{
  CDmElement *v1; // eax
  CDmrGenericArrayConst array; // [esp+0h] [ebp-4h] BYREF

  array.m_pAttribute = (CDmAttribute *)this;
  v1 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, char *))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle,
                       a3: this->m_szAttributeName);
  CDmrGenericArrayConst::CDmrGenericArrayConst(
    this: &array,
    pElement: v1,
    pAttributeName: (const char *)array.m_pAttribute);
  if ( array.m_pAttribute != nullptr )
    return CDmrGenericArrayConst::Count(this: &array);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00496A30
// Name: enum DmElementHandle_t const __near & GetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t *__cdecl GetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( pAttribute == nullptr )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  if ( *pAttribute == 0 )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute);
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return (DmElementHandle_t *)(MEMORY[0] + 4 * nArrayIndex);
  array.m_pAttribute = Attribute;
  array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  return &array.m_pStorage->m_Memory.m_pMemory[nArrayIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00496AA0
// Name: void SetArrayAttributeValue<enum DmElementHandle_t>(class CDmElement __near *,char const __near *,int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetArrayAttributeValue<enum DmElementHandle_t>(
        CDmElement *pElement,
        const char *pAttribute,
        int nArrayIndex,
        const DmElementHandle_t *value)
{
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> array; // [esp+0h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( pElement != nullptr
    && pAttribute != nullptr
    && *pAttribute != 0
    && (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pAttribute)) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = Attribute;
    array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  pElement = (CDmElement *)*value;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Set(
    this: &array,
    i: nArrayIndex,
    value: (const DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00496B10
// Name: public: enum DmElementHandle_t const __near & CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      return (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                  pElement: v2,
                                                  pAttribute: m_szAttributeName,
                                                  nArrayIndex: m_nArrayIndex);
    else
      return CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    return (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496B70
// Name: public: void CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(
        CBaseAttributePanel *this,
        const DmElementHandle_t *value)
{
  char *m_szAttributeName; // edi
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v6; // eax

  if ( this->m_nArrayIndex >= 0 )
  {
    v6 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hObject.m_handle);
    SetArrayAttributeValue<enum DmElementHandle_t>(
      pElement: v6,
      pAttribute: this->m_szAttributeName,
      nArrayIndex: this->m_nArrayIndex,
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
      || (Attribute = CDmElement::CreateAttribute(
                        this: v4,
                        pAttributeName: m_szAttributeName,
                        type: AT_FIRST_VALUE_TYPE)) != nullptr )
    {
      CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496C70
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496D00
// Name: public: static void CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded )
  {
    `CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Refresh";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496D90
// Name: public: class CDmElement __near * CBaseAttributePanel::GetAttributeValueElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAttributePanel::GetAttributeValueElement(CBaseAttributePanel *this)
{
  CDmElement *v2; // eax
  CDmaVar<enum DmElementHandle_t> *ArrayAttribute; // eax
  int m_nArrayIndex; // ecx
  char *m_szAttributeName; // esi
  int v6; // eax
  int v7; // esi

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hObject.m_handle);
  if ( v2 != nullptr )
  {
    m_nArrayIndex = this->m_nArrayIndex;
    m_szAttributeName = this->m_szAttributeName;
    if ( m_nArrayIndex >= 0 )
      ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)GetArrayAttributeValue<enum DmElementHandle_t>(
                                                            pElement: v2,
                                                            pAttribute: m_szAttributeName,
                                                            nArrayIndex: m_nArrayIndex);
    else
      ArrayAttribute = CDmElement::GetValue<enum DmElementHandle_t>(this: v2, pAttributeName: m_szAttributeName);
  }
  else
  {
    `CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp = DMELEMENT_HANDLE_INVALID;
    ArrayAttribute = (CDmaVar<enum DmElementHandle_t> *)&`CBaseAttributePanel::GetAttributeValue<enum DmElementHandle_t>'::`5'::temp;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: ArrayAttribute->m_Storage.m_Handle);
  v7 = v6;
  if ( v6 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496E20
// Name: public: void CBaseAttributePanel::SetAttributeValueElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAttributePanel::SetAttributeValueElement(CBaseAttributePanel *this, CDmElement *pElement)
{
  pElement = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  CBaseAttributePanel::SetAttributeValue<enum DmElementHandle_t>(this, value: (const DmElementHandle_t *)&pElement);
}

//------------------------------------------------------------------------------
// Address: 0x00496EC0
// Name: public: CBaseAttributePanel::CBaseAttributePanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseAttributePanel *__thiscall CBaseAttributePanel::CBaseAttributePanel(
        CBaseAttributePanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmElement *m_pElement; // ecx
  DmElementHandle_t BufferType; // eax
  CExpressionCalculator *m_pEditorInfo; // ecx
  DmElementHandle_t v10; // eax
  CExpressionCalculator *m_pEditorTypeDictionary; // ecx
  DmElementHandle_t v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  int v15; // eax
  CDmAttribute *Attribute; // eax
  DmAttributeType_t v17; // eax
  bool v18; // sf
  vgui::Label_vtbl *v19; // edi
  int v20; // eax
  CBaseAttributePanel::colinfo_t search; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: info->m_pAttributeName);
  this->__vftable = (CBaseAttributePanel_vtbl *)&CBaseAttributePanel::`vftable';
  if ( `CBaseAttributePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
    v4->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
    v5->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CBaseAttributePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAttributePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
    v6->pfnClassName = CBaseAttributePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CBaseAttributePanel::PanelMessageFunc_OnApplyChanges::InitVar(a1: (int)&savedregs);
  CBaseAttributePanel::PanelMessageFunc_OnRefresh::InitVar(a1: (int)&savedregs);
  this->m_pType = nullptr;
  m_pElement = info->m_pElement;
  this->m_hObject.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pElement != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pElement);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hObject, h: BufferType);
  m_pEditorInfo = (CExpressionCalculator *)info->m_pEditorInfo;
  this->m_hEditorInfo.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorInfo != nullptr )
    v10 = CCodecBuffer_Block::GetBufferType(this: m_pEditorInfo);
  else
    v10 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorAttributeInfo,0>::Set(this: &this->m_hEditorInfo, h: v10);
  m_pEditorTypeDictionary = (CExpressionCalculator *)info->m_pEditorTypeDictionary;
  this->m_hEditorTypeDict.m_handle = DMELEMENT_HANDLE_INVALID;
  if ( m_pEditorTypeDictionary != nullptr )
    v12 = CCodecBuffer_Block::GetBufferType(this: m_pEditorTypeDictionary);
  else
    v12 = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeEditorTypeDictionary,0>::Set(this: &this->m_hEditorTypeDict, h: v12);
  this->m_nArrayIndex = info->m_nArrayIndex;
  this->m_pNotify = info->m_pNotify;
  this->m_ColumnSize.m_LessFunc = (bool (__cdecl *)(const CBaseAttributePanel::colinfo_t *, const CBaseAttributePanel::colinfo_t *))CDefOps<CDmAttribute *>::LessFunc;
  this->m_ColumnSize.m_Elements.m_pMemory = nullptr;
  this->m_ColumnSize.m_Elements.m_nAllocationCount = 0;
  this->m_ColumnSize.m_Elements.m_nGrowSize = 0;
  this->m_ColumnSize.m_Root = -1;
  this->m_ColumnSize.m_FirstFree = -1;
  this->m_ColumnSize.m_NumElements = 0;
  this->m_ColumnSize.m_LastAlloc.index = -1;
  this->m_ColumnSize.m_pElements = this->m_ColumnSize.m_Elements.m_pMemory;
  CBaseAttributePanel::InitializeFlags(this, info);
  V_strncpy(pDest: this->m_szAttributeName, pSrc: info->m_pAttributeName, maxLen: 256);
  v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "AttributeType", text: defaultValue);
  else
    v14 = nullptr;
  this->m_pType = v14;
  search.panel = v14;
  v15 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Find(
          this: &this->m_ColumnSize,
          &search);
  if ( v15 == -1 )
    v15 = CUtlRBTree<CBaseAttributePanel::colinfo_t,int,bool (__cdecl *)(CBaseAttributePanel::colinfo_t const &,CBaseAttributePanel::colinfo_t const &),CUtlMemory<UtlRBTreeNode_t<CBaseAttributePanel::colinfo_t,int>,int>>::Insert(
            this: &this->m_ColumnSize,
            insert: &search);
  this->m_ColumnSize.m_Elements.m_pMemory[v15].m_Data.width = 100;
  Attribute = CDmElement::FindAttribute(this: info->m_pElement, pAttributeName: info->m_pAttributeName);
  if ( Attribute != nullptr )
    v17 = Attribute->m_nFlags & 0x1F;
  else
    v17 = AT_UNKNOWN;
  v18 = this->m_nArrayIndex < 0;
  this->m_AttributeType = v17;
  if ( !v18 )
    this->m_AttributeType = v17 - 14;
  v19 = this->m_pType->__vftable;
  v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeType_t))(*(_DWORD *)g_pDataModel.u.m_Id + 88))(
          a1: g_pDataModel.u,
          a2: this->m_AttributeType);
  v19->SetText_2(this: this->m_pType, a2: (const char *)v20);
  this->m_hFont = 0;
  vgui::Panel::SetDragEnabled(this, enabled: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00497160
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAttributePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAttributePanel::GetMessageMap(CBaseAttributePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497190
// Name: public: virtual struct PanelAnimationMap __near * CBaseAttributePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAttributePanel::GetAnimMap(CBaseAttributePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAttributePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004971A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAttributePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAttributePanel::GetKBMap(CBaseAttributePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAttributePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAttributePanel::GetKBMap'::`2'::s_pMap;
  `CBaseAttributePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAttributePanel");
  `CBaseAttributePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
