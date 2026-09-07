// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmesourceskinpanel.cpp
// Functions: 11
// ============================================================

#include "vgui2\dme_controls\dmesourceskinpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00472FA0
// Name: public: static char const __near * CDmeSourceSkinPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceSkinPanel::GetPanelClassName()
{
  return "CDmeSourceSkinPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00472FB0
// Name: public: class CDmaString __near & CDmaString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmaString *__thiscall CDmaString::operator=(CDmaString *this, const char *src)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&src, a3: src);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_pAttribute, value: (const CUtlSymbolLarge *)&src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00473060
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceSkinPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceSkinPanel::GetMessageMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473090
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceSkinPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceSkinPanel::GetAnimMap(CDmeSourceSkinPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004730A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceSkinPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceSkinPanel::GetKBMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473120
// Name: private: virtual void CDmeSourceSkinPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnCheckButtonChecked(CDmeSourceSkinPanel *this, int nChecked)
{
  DmElementHandle_t m_handle; // eax
  CDmElement *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  bool bFlipTriangles; // [esp+7h] [ebp-1h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle) != nullptr )
  {
    m_handle = this->m_hSourceSkin.m_handle;
    bFlipTriangles = nChecked != 0;
    if ( (nChecked != 0) != g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle)[1].m_Id.m_Value[8] )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
      CDmAttribute::SetValue<bool>(this: *(CDmAttribute **)&v4[1].m_Id.m_Value[12], value: &bFlipTriangles);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "DmeElementChanged");
        this->PostActionSignal(this, a2: v6);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004731D0
// Name: private: virtual void CDmeSourceSkinPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnTextChanged(CDmeSourceSkinPanel *this, float kv)
{
  vgui::TextEntry *Ptr; // eax
  const char *v4; // eax
  CDmElement *v5; // edi
  float v6; // xmm0_4
  DmElementHandle_t m_handle; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // eax
  char pTextBuf[256]; // [esp+4h] [ebp-100h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle) != nullptr )
  {
    Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: (KeyValues *)LODWORD(kv), keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pSkinName )
    {
      this->m_pSkinName->GetText_2(this: this->m_pSkinName, a2: pTextBuf, a3: 256);
      v4 = *(const char **)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle)[1].m_Id.m_Value;
      if ( v4 == (const char *)-1 )
        v4 = defaultValue;
      if ( _V_stricmp(s1: pTextBuf, s2: v4) != 0 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&kv, a3: pTextBuf);
        CDmAttribute::SetValue<CUtlSymbolLarge>(
          this: *(CDmAttribute **)&v5[1].m_Id.m_Value[4],
          value: (const CUtlSymbolLarge *)&kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
    else if ( Ptr == this->m_pScale )
    {
      this->m_pScale->GetText_2(this: this->m_pScale, a2: pTextBuf, a3: 256);
      v6 = (float)atoi(nptr: pTextBuf);
      m_handle = this->m_hSourceSkin.m_handle;
      kv = v6;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      if ( kv != *(float *)&v8[1].m_ref.m_hElement )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
        CDmAttribute::SetValue<float>(this: *((CDmAttribute **)&v9[1].m_ref + 1), value: &kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473350
// Name: public: void CDmeSourceSkinPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::SetDmeElement(CDmeSourceSkinPanel *this, CExpressionCalculator *pSourceSkin)
{
  CExpressionCalculator *v2; // ebx
  DmElementHandle_t BufferType; // eax
  const char *m_pElements; // eax
  char pBuf[32]; // [esp+20h] [ebp-20h] BYREF

  v2 = pSourceSkin;
  if ( pSourceSkin != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceSkin);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceSkin,0>::Set(this: &this->m_hSourceSkin, h: BufferType);
  LOBYTE(pSourceSkin) = pSourceSkin != nullptr;
  this->m_pSkinName->SetEnabled(this: this->m_pSkinName, a2: (bool)pSourceSkin);
  this->m_pScale->SetEnabled(this: this->m_pScale, a2: (bool)pSourceSkin);
  this->m_pFlipTriangles->SetEnabled(this: this->m_pFlipTriangles, a2: (bool)pSourceSkin);
  if ( v2 != nullptr )
  {
    V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%.3f", *(float *)&v2[1].m_varNames.m_Memory.m_pMemory);
    m_pElements = (const char *)v2->m_stack.m_pElements;
    if ( m_pElements == (const char *)-1 )
      m_pElements = defaultValue;
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: m_pElements);
    this->m_pScale->SetText(this: this->m_pScale, a2: pBuf);
    this->m_pFlipTriangles->SetSelected(
      this: this->m_pFlipTriangles,
      a2: (bool)v2[1].m_expr.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: defaultValue);
    this->m_pScale->SetText(this: this->m_pScale, a2: defaultValue);
    this->m_pFlipTriangles->SetSelected(this: this->m_pFlipTriangles, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004734A0
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x00473530
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004735D0
// Name: public: CDmeSourceSkinPanel::CDmeSourceSkinPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmeSourceSkinPanel::CDmeSourceSkinPanel(
        CDmeSourceSkinPanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceSkinPanel_vtbl *)&CDmeSourceSkinPanel::`vftable';
  if ( `CDmeSourceSkinPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    v4->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
    v5->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
    v6->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->m_hSourceSkin.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "SkinName");
  else
    v8 = nullptr;
  this->m_pSkinName = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Scale");
  else
    v10 = nullptr;
  this->m_pScale = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(this: v11, parent: this, panelName: "FlipTriangles", text: defaultValue);
  else
    v12 = nullptr;
  this->m_pFlipTriangles = v12;
  v12->AddActionSignalTarget_2(this: v12, a2: this);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceSkinPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10478D10
// Name: public: static char const __near * CDmeSourceSkinPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceSkinPanel::GetPanelClassName()
{
  return "CDmeSourceSkinPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10478D20
// Name: public: class CDmaString __near & CDmaString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmaString *__thiscall CDmaString::operator=(CDmaString *this, const char *src)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&src, a3: src);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_pAttribute, value: (const CUtlSymbolLarge *)&src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10478DD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceSkinPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceSkinPanel::GetMessageMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10478E00
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceSkinPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceSkinPanel::GetAnimMap(CDmeSourceSkinPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10478E10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceSkinPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceSkinPanel::GetKBMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10478E90
// Name: private: virtual void CDmeSourceSkinPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnCheckButtonChecked(CDmeSourceSkinPanel *this, int nChecked)
{
  DmElementHandle_t m_handle; // eax
  CDmElement *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  bool bFlipTriangles; // [esp+7h] [ebp-1h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle) != nullptr )
  {
    m_handle = this->m_hSourceSkin.m_handle;
    bFlipTriangles = nChecked != 0;
    if ( (nChecked != 0) != g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle)[1].m_Id.m_Value[8] )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
      CDmAttribute::SetValue<bool>(this: *(CDmAttribute **)&v4[1].m_Id.m_Value[12], value: &bFlipTriangles);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "DmeElementChanged");
        this->PostActionSignal(this, a2: v6);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10478F40
// Name: private: virtual void CDmeSourceSkinPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnTextChanged(CDmeSourceSkinPanel *this, float kv)
{
  vgui::TextEntry *Ptr; // eax
  const char *v4; // eax
  CDmElement *v5; // edi
  float v6; // xmm0_4
  DmElementHandle_t m_handle; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // eax
  char pTextBuf[256]; // [esp+4h] [ebp-100h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle) != nullptr )
  {
    Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: (KeyValues *)LODWORD(kv), keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pSkinName )
    {
      this->m_pSkinName->GetText_2(this: this->m_pSkinName, a2: pTextBuf, a3: 256);
      v4 = *(const char **)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle)[1].m_Id.m_Value;
      if ( v4 == (const char *)-1 )
        v4 = &var;
      if ( _V_stricmp(s1: pTextBuf, s2: v4) != 0 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&kv, a3: pTextBuf);
        CDmAttribute::SetValue<CUtlSymbolLarge>(
          this: *(CDmAttribute **)&v5[1].m_Id.m_Value[4],
          value: (const CUtlSymbolLarge *)&kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
    else if ( Ptr == this->m_pScale )
    {
      this->m_pScale->GetText_2(this: this->m_pScale, a2: pTextBuf, a3: 256);
      v6 = (float)atoi(nptr: pTextBuf);
      m_handle = this->m_hSourceSkin.m_handle;
      kv = v6;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      if ( kv != *(float *)&v8[1].m_ref.m_hElement )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceSkin.m_handle);
        CDmAttribute::SetValue<float>(this: *((CDmAttribute **)&v9[1].m_ref + 1), value: &kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104790C0
// Name: public: void CDmeSourceSkinPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::SetDmeElement(CDmeSourceSkinPanel *this, CExpressionCalculator *pSourceSkin)
{
  CExpressionCalculator *v2; // ebx
  DmElementHandle_t BufferType; // eax
  const char *m_pElements; // eax
  char pDest[20]; // [esp+14h] [ebp-20h] BYREF

  v2 = pSourceSkin;
  if ( pSourceSkin != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceSkin);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceSkin,0>::Set(this: &this->m_hSourceSkin, h: BufferType);
  LOBYTE(pSourceSkin) = pSourceSkin != nullptr;
  this->m_pSkinName->SetEnabled(this: this->m_pSkinName, a2: (bool)pSourceSkin);
  this->m_pScale->SetEnabled(this: this->m_pScale, a2: (bool)pSourceSkin);
  this->m_pFlipTriangles->SetEnabled(this: this->m_pFlipTriangles, a2: (bool)pSourceSkin);
  if ( v2 != nullptr )
  {
    V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.3f", *(float *)&v2[1].m_varNames.m_Memory.m_pMemory);
    m_pElements = (const char *)v2->m_stack.m_pElements;
    if ( m_pElements == (const char *)-1 )
      m_pElements = &var;
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: m_pElements);
    this->m_pScale->SetText(this: this->m_pScale, a2: pDest);
    this->m_pFlipTriangles->SetSelected(
      this: this->m_pFlipTriangles,
      a2: (bool)v2[1].m_expr.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: &var);
    this->m_pScale->SetText(this: this->m_pScale, a2: &var);
    this->m_pFlipTriangles->SetSelected(this: this->m_pFlipTriangles, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479210
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x104792A0
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10479340
// Name: public: CDmeSourceSkinPanel::CDmeSourceSkinPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmeSourceSkinPanel::CDmeSourceSkinPanel(
        CDmeSourceSkinPanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceSkinPanel_vtbl *)&CDmeSourceSkinPanel::`vftable';
  if ( `CDmeSourceSkinPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    v4->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
    v5->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
    v6->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->m_hSourceSkin.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: (vgui::Panel *)"SkinName");
  else
    v8 = nullptr;
  this->m_pSkinName = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: (vgui::Panel *)"Scale");
  else
    v10 = nullptr;
  this->m_pScale = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(this: v11, parent: this, panelName: "FlipTriangles", text: &var);
  else
    v12 = nullptr;
  this->m_pFlipTriangles = v12;
  v12->AddActionSignalTarget_2(this: v12, a2: this);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceSkinPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048E120
// Name: public: static char const __near * CDmeSourceSkinPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceSkinPanel::GetPanelClassName()
{
  return "CDmeSourceSkinPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048E130
// Name: public: class CDmaString __near & CDmaString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmaString *__thiscall CDmaString::operator=(CDmaString *this, const char *src)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &src,
    a3: src);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_pAttribute, value: (const CUtlSymbolLarge *)&src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048E220
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceSkinPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceSkinPanel::GetMessageMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E250
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceSkinPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceSkinPanel::GetAnimMap(CDmeSourceSkinPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0048E260
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceSkinPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceSkinPanel::GetKBMap(CDmeSourceSkinPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceSkinPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
  `CDmeSourceSkinPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E2E0
// Name: private: virtual void CDmeSourceSkinPanel::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnCheckButtonChecked(CDmeSourceSkinPanel *this, int nChecked)
{
  DmElementHandle_t m_handle; // eax
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  bool bFlipTriangles; // [esp+7h] [ebp-1h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceSkin.m_handle) != 0 )
  {
    m_handle = this->m_hSourceSkin.m_handle;
    bFlipTriangles = nChecked != 0;
    if ( (nChecked != 0) != *(_BYTE *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                         a1: g_pDataModel.u,
                                         a2: m_handle)
                                     + 80) )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hSourceSkin.m_handle);
      CDmAttribute::SetValue<bool>(this: *(CDmAttribute **)(v4 + 84), value: &bFlipTriangles);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "DmeElementChanged");
        this->PostActionSignal(this, a2: v6);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E390
// Name: private: virtual void CDmeSourceSkinPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::OnTextChanged(CDmeSourceSkinPanel *this, float kv)
{
  vgui::TextEntry *Ptr; // eax
  const char *v4; // eax
  int v5; // edi
  float v6; // xmm0_4
  DmElementHandle_t m_handle; // eax
  int v8; // eax
  int v9; // eax
  char pTextBuf[256]; // [esp+4h] [ebp-100h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceSkin.m_handle) != 0 )
  {
    Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: (KeyValues *)LODWORD(kv), keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pSkinName )
    {
      this->m_pSkinName->GetText_2(this: this->m_pSkinName, a2: pTextBuf, a3: 256);
      v4 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: this->m_hSourceSkin.m_handle)
                          + 72);
      if ( v4 == (const char *)-1 )
        v4 = defaultValue;
      if ( _V_stricmp(s1: pTextBuf, s2: v4) != 0 )
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_hSourceSkin.m_handle);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, float *, char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
          a1: g_pDataModel.u,
          a2: &kv,
          a3: pTextBuf);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v5 + 76), value: (const CUtlSymbolLarge *)&kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
    else if ( Ptr == this->m_pScale )
    {
      this->m_pScale->GetText_2(this: this->m_pScale, a2: pTextBuf, a3: 256);
      v6 = (float)atoi(nptr: pTextBuf);
      m_handle = this->m_hSourceSkin.m_handle;
      kv = v6;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_handle);
      if ( kv != *(float *)(v8 + 96) )
      {
        v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_hSourceSkin.m_handle);
        CDmAttribute::SetValue<float>(this: *(CDmAttribute **)(v9 + 100), value: &kv);
        CDmeSourceDCCFilePanel::SetDirty(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E510
// Name: public: void CDmeSourceSkinPanel::SetDmeElement(class CDmeSourceSkin __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceSkinPanel::SetDmeElement(CDmeSourceSkinPanel *this, CExpressionCalculator *pSourceSkin)
{
  CExpressionCalculator *v2; // ebx
  DmElementHandle_t BufferType; // eax
  const char *m_pElements; // eax
  char pBuf[32]; // [esp+20h] [ebp-20h] BYREF

  v2 = pSourceSkin;
  if ( pSourceSkin != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceSkin);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceSkin,0>::Set(this: &this->m_hSourceSkin, h: BufferType);
  LOBYTE(pSourceSkin) = pSourceSkin != nullptr;
  this->m_pSkinName->SetEnabled(this: this->m_pSkinName, a2: (bool)pSourceSkin);
  this->m_pScale->SetEnabled(this: this->m_pScale, a2: (bool)pSourceSkin);
  this->m_pFlipTriangles->SetEnabled(this: this->m_pFlipTriangles, a2: (bool)pSourceSkin);
  if ( v2 != nullptr )
  {
    V_snprintf(pDest: pBuf, maxLen: 32, pFormat: "%.3f", *(float *)&v2[1].m_varNames.m_Memory.m_pMemory);
    m_pElements = (const char *)v2->m_stack.m_pElements;
    if ( m_pElements == (const char *)-1 )
      m_pElements = defaultValue;
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: m_pElements);
    this->m_pScale->SetText(this: this->m_pScale, a2: pBuf);
    this->m_pFlipTriangles->SetSelected(
      this: this->m_pFlipTriangles,
      a2: (bool)v2[1].m_expr.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    this->m_pSkinName->SetText(this: this->m_pSkinName, a2: defaultValue);
    this->m_pScale->SetText(this: this->m_pScale, a2: defaultValue);
    this->m_pFlipTriangles->SetSelected(this: this->m_pFlipTriangles, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E660
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x0048E6F0
// Name: public: static void CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E790
// Name: public: CDmeSourceSkinPanel::CDmeSourceSkinPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *__thiscall CDmeSourceSkinPanel::CDmeSourceSkinPanel(
        CDmeSourceSkinPanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceSkinPanel_vtbl *)&CDmeSourceSkinPanel::`vftable';
  if ( `CDmeSourceSkinPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceSkinPanel");
    v4->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceSkinPanel");
    v5->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceSkinPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceSkinPanel");
    v6->pfnClassName = CDmeSourceSkinPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceSkinPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CDmeSourceSkinPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->m_hSourceSkin.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "SkinName");
  else
    v8 = nullptr;
  this->m_pSkinName = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Scale");
  else
    v10 = nullptr;
  this->m_pScale = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(this: v11, parent: this, panelName: "FlipTriangles", text: defaultValue);
  else
    v12 = nullptr;
  this->m_pFlipTriangles = v12;
  v12->AddActionSignalTarget_2(this: v12, a2: this);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceSkinPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

} // namespace sceneviewer
