// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeshaderpickerpanel.cpp
// Functions: 7
// ============================================================

#include "vgui2\dme_controls\attributeshaderpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00470E60
// Name: public: static char const __near * CAttributeShaderPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShaderPickerPanel::GetPanelClassName()
{
  return "CAttributeShaderPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00470ED0
// Name: public: static void CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x00470F60
// Name: private: virtual void CAttributeShaderPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShaderPickerPanel::ShowPickerDialog(CAttributeShaderPickerPanel *this)
{
  CPickerFrame *v2; // eax
  int v3; // edi
  IMaterialSystem *v4; // eax
  int v5; // esi
  void *v6; // esp
  IShader **v7; // ebx
  IMaterialSystem *v8; // eax
  PickerInfo_t *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  _DWORD *p_m_pChoiceString; // ebx
  int v15; // eax
  IShader **v16; // edx
  PickerInfo_t *v17; // esi
  int v18; // eax
  CPickerFrame *v19; // esi
  PickerInfo_t *v20; // eax
  _BYTE v21[12]; // [esp+0h] [ebp-34h] BYREF
  PickerList_t shaderList; // [esp+Ch] [ebp-28h] BYREF
  CAttributeShaderPickerPanel *v23; // [esp+24h] [ebp-10h]
  int nCount; // [esp+28h] [ebp-Ch]
  CPickerFrame *pShaderPickerDialog; // [esp+2Ch] [ebp-8h]
  IShader **ppShaderList; // [esp+30h] [ebp-4h]

  v23 = this;
  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  v3 = 0;
  if ( v2 != nullptr )
    pShaderPickerDialog = CPickerFrame::CPickerFrame(
                            this: v2,
                            pParent: this,
                            pTitle: "Select Shader",
                            pPickerType: "Shader",
                            pTextType: "shaderName");
  else
    pShaderPickerDialog = nullptr;
  v4 = vgui::MaterialSystem();
  v5 = v4->ShaderCount(this: v4);
  nCount = v5;
  v6 = alloca(4 * v5);
  v7 = (IShader **)v21;
  ppShaderList = (IShader **)v21;
  v8 = vgui::MaterialSystem();
  v8->GetShaders(this: v8, a2: 0, a3: v5, a4: (IShader **)v21);
  v9 = nullptr;
  shaderList.m_Type = PICKER_CHOICE_STRING;
  shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
  shaderList.m_Choices.m_Memory.m_nAllocationCount = v5;
  shaderList.m_Choices.m_Memory.m_nGrowSize = 0;
  if ( v5 != 0 )
  {
    v9 = (PickerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v5);
    shaderList.m_Choices.m_Memory.m_pMemory = v9;
  }
  shaderList.m_Choices.m_Size = 0;
  shaderList.m_Choices.m_pElements = v9;
  if ( v5 > 0 )
  {
    do
    {
      if ( (v7[v3]->GetFlags(this: v7[v3]) & 1) == 0 )
      {
        m_Size = shaderList.m_Choices.m_Size;
        v11 = shaderList.m_Choices.m_Size;
        if ( shaderList.m_Choices.m_Size + 1 > shaderList.m_Choices.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<MDLSquenceLayer_t,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&shaderList.m_Choices,
            num: shaderList.m_Choices.m_Size - shaderList.m_Choices.m_Memory.m_nAllocationCount + 1);
          m_Size = shaderList.m_Choices.m_Size;
        }
        m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        shaderList.m_Choices.m_Size = m_Size + 1;
        v13 = m_Size - v11;
        shaderList.m_Choices.m_pElements = shaderList.m_Choices.m_Memory.m_pMemory;
        if ( v13 > 0 )
        {
          _V_memmove(
            dest: &shaderList.m_Choices.m_Memory.m_pMemory[v11 + 1],
            src: &shaderList.m_Choices.m_Memory.m_pMemory[v11],
            count: 8 * v13);
          m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        }
        p_m_pChoiceString = &m_pMemory[v11].m_pChoiceString;
        v15 = ppShaderList[v3]->GetName(this: ppShaderList[v3]);
        v16 = ppShaderList;
        *p_m_pChoiceString = v15;
        v17 = &shaderList.m_Choices.m_Memory.m_pMemory[v11];
        v18 = v16[v3]->GetName(this: v16[v3]);
        v7 = ppShaderList;
        v17->m_pChoiceValue = (const char *)v18;
        v5 = nCount;
      }
      ++v3;
    }
    while ( v3 < v5 );
  }
  v19 = pShaderPickerDialog;
  pShaderPickerDialog->AddActionSignalTarget_2(this: pShaderPickerDialog, a2: v23);
  CPickerFrame::DoModal(this: v19, list: &shaderList, pContextKeyValues: nullptr);
  v20 = shaderList.m_Choices.m_Memory.m_pMemory;
  shaderList.m_Choices.m_Size = 0;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( shaderList.m_Choices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: shaderList.m_Choices.m_Memory.m_pMemory);
      v20 = nullptr;
      shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
    }
    shaderList.m_Choices.m_Memory.m_nAllocationCount = 0;
  }
  shaderList.m_Choices.m_pElements = v20;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x00471110
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShaderPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShaderPickerPanel::GetMessageMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471140
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShaderPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShaderPickerPanel::GetAnimMap(CAttributeShaderPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00471150
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShaderPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShaderPickerPanel::GetKBMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471180
// Name: public: CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(
        CAttributeShaderPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShaderPickerPanel_vtbl *)&CAttributeShaderPickerPanel::`vftable';
  if ( `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    v4->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
    v5->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
    v6->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10494340
// Name: public: static char const __near * CAttributeShaderPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShaderPickerPanel::GetPanelClassName()
{
  return "CAttributeShaderPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104943C0
// Name: public: static void CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x10494450
// Name: private: virtual void CAttributeShaderPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShaderPickerPanel::ShowPickerDialog(CAttributeShaderPickerPanel *this)
{
  CPickerFrame *v2; // eax
  int v3; // edi
  IMaterialSystem *v4; // eax
  int v5; // esi
  void *v6; // esp
  IShader **v7; // ebx
  IMaterialSystem *v8; // eax
  PickerInfo_t *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  _DWORD *p_m_pChoiceString; // ebx
  int v15; // eax
  IShader **v16; // edx
  PickerInfo_t *v17; // esi
  int v18; // eax
  CPickerFrame *v19; // esi
  PickerInfo_t *v20; // eax
  _BYTE v21[12]; // [esp+0h] [ebp-34h] BYREF
  PickerList_t shaderList; // [esp+Ch] [ebp-28h] BYREF
  CAttributeShaderPickerPanel *v23; // [esp+24h] [ebp-10h]
  int nCount; // [esp+28h] [ebp-Ch]
  CPickerFrame *pShaderPickerDialog; // [esp+2Ch] [ebp-8h]
  IShader **ppShaderList; // [esp+30h] [ebp-4h]

  v23 = this;
  v2 = (CPickerFrame *)operator new(nSize: 0x224u);
  v3 = 0;
  if ( v2 != nullptr )
    pShaderPickerDialog = CPickerFrame::CPickerFrame(
                            this: v2,
                            pParent: this,
                            pTitle: "Select Shader",
                            pPickerType: "Shader",
                            pTextType: "shaderName");
  else
    pShaderPickerDialog = nullptr;
  v4 = vgui::MaterialSystem();
  v5 = v4->ShaderCount(this: v4);
  nCount = v5;
  v6 = alloca(4 * v5);
  v7 = (IShader **)v21;
  ppShaderList = (IShader **)v21;
  v8 = vgui::MaterialSystem();
  v8->GetShaders(this: v8, a2: 0, a3: v5, a4: (IShader **)v21);
  v9 = nullptr;
  shaderList.m_Type = PICKER_CHOICE_STRING;
  shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
  shaderList.m_Choices.m_Memory.m_nAllocationCount = v5;
  shaderList.m_Choices.m_Memory.m_nGrowSize = 0;
  if ( v5 != 0 )
  {
    v9 = (PickerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v5);
    shaderList.m_Choices.m_Memory.m_pMemory = v9;
  }
  shaderList.m_Choices.m_Size = 0;
  shaderList.m_Choices.m_pElements = v9;
  if ( v5 > 0 )
  {
    do
    {
      if ( (v7[v3]->GetFlags(this: v7[v3]) & 1) == 0 )
      {
        m_Size = shaderList.m_Choices.m_Size;
        v11 = shaderList.m_Choices.m_Size;
        if ( shaderList.m_Choices.m_Size + 1 > shaderList.m_Choices.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CacheOptimizedKDNode,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&shaderList.m_Choices,
            num: shaderList.m_Choices.m_Size - shaderList.m_Choices.m_Memory.m_nAllocationCount + 1);
          m_Size = shaderList.m_Choices.m_Size;
        }
        m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        shaderList.m_Choices.m_Size = m_Size + 1;
        v13 = m_Size - v11;
        shaderList.m_Choices.m_pElements = shaderList.m_Choices.m_Memory.m_pMemory;
        if ( v13 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&shaderList.m_Choices.m_Memory.m_pMemory[v11 + 1],
            src: (unsigned __int8 *)&shaderList.m_Choices.m_Memory.m_pMemory[v11],
            count: 8 * v13);
          m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        }
        p_m_pChoiceString = &m_pMemory[v11].m_pChoiceString;
        v15 = ppShaderList[v3]->GetName(this: ppShaderList[v3]);
        v16 = ppShaderList;
        *p_m_pChoiceString = v15;
        v17 = &shaderList.m_Choices.m_Memory.m_pMemory[v11];
        v18 = v16[v3]->GetName(this: v16[v3]);
        v7 = ppShaderList;
        v17->m_pChoiceValue = (const char *)v18;
        v5 = nCount;
      }
      ++v3;
    }
    while ( v3 < v5 );
  }
  v19 = pShaderPickerDialog;
  pShaderPickerDialog->AddActionSignalTarget_2(this: pShaderPickerDialog, a2: v23);
  CPickerFrame::DoModal(this: v19, list: &shaderList, pContextKeyValues: nullptr);
  v20 = shaderList.m_Choices.m_Memory.m_pMemory;
  shaderList.m_Choices.m_Size = 0;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( shaderList.m_Choices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: shaderList.m_Choices.m_Memory.m_pMemory);
      v20 = nullptr;
      shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
    }
    shaderList.m_Choices.m_Memory.m_nAllocationCount = 0;
  }
  shaderList.m_Choices.m_pElements = v20;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x10494600
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShaderPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShaderPickerPanel::GetMessageMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494630
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShaderPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShaderPickerPanel::GetAnimMap(CAttributeShaderPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10494640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShaderPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShaderPickerPanel::GetKBMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494670
// Name: public: CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(
        CAttributeShaderPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShaderPickerPanel_vtbl *)&CAttributeShaderPickerPanel::`vftable';
  if ( `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    v4->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
    v5->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
    v6->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049AA60
// Name: public: static char const __near * CAttributeShaderPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeShaderPickerPanel::GetPanelClassName()
{
  return "CAttributeShaderPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049AA70
// Name: public: static void CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
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
// Address: 0x0049AB00
// Name: private: virtual void CAttributeShaderPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeShaderPickerPanel::ShowPickerDialog(CAttributeShaderPickerPanel *this)
{
  CPickerFrame *v2; // eax
  int v3; // edi
  IMaterialSystem *v4; // eax
  int v5; // esi
  void *v6; // esp
  IShader **v7; // ebx
  IMaterialSystem *v8; // eax
  PickerInfo_t *v9; // eax
  int m_Size; // eax
  int v11; // esi
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  _DWORD *p_m_pChoiceString; // ebx
  int v15; // eax
  IShader **v16; // edx
  PickerInfo_t *v17; // esi
  int v18; // eax
  CPickerFrame *v19; // esi
  PickerInfo_t *v20; // eax
  _BYTE v21[12]; // [esp+0h] [ebp-34h] BYREF
  PickerList_t shaderList; // [esp+Ch] [ebp-28h] BYREF
  CAttributeShaderPickerPanel *v23; // [esp+24h] [ebp-10h]
  int nCount; // [esp+28h] [ebp-Ch]
  CPickerFrame *pShaderPickerDialog; // [esp+2Ch] [ebp-8h]
  IShader **ppShaderList; // [esp+30h] [ebp-4h]

  v23 = this;
  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  v3 = 0;
  if ( v2 != nullptr )
    pShaderPickerDialog = CPickerFrame::CPickerFrame(
                            this: v2,
                            pParent: this,
                            pTitle: "Select Shader",
                            pPickerType: "Shader",
                            pTextType: "shaderName");
  else
    pShaderPickerDialog = nullptr;
  v4 = vgui::MaterialSystem();
  v5 = v4->ShaderCount(this: v4);
  nCount = v5;
  v6 = alloca(4 * v5);
  v7 = (IShader **)v21;
  ppShaderList = (IShader **)v21;
  v8 = vgui::MaterialSystem();
  v8->GetShaders(this: v8, a2: 0, a3: v5, a4: (IShader **)v21);
  v9 = nullptr;
  shaderList.m_Type = PICKER_CHOICE_STRING;
  shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
  shaderList.m_Choices.m_Memory.m_nAllocationCount = v5;
  shaderList.m_Choices.m_Memory.m_nGrowSize = 0;
  if ( v5 != 0 )
  {
    v9 = (PickerInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v5);
    shaderList.m_Choices.m_Memory.m_pMemory = v9;
  }
  shaderList.m_Choices.m_Size = 0;
  shaderList.m_Choices.m_pElements = v9;
  if ( v5 > 0 )
  {
    do
    {
      if ( (v7[v3]->GetFlags(this: v7[v3]) & 1) == 0 )
      {
        m_Size = shaderList.m_Choices.m_Size;
        v11 = shaderList.m_Choices.m_Size;
        if ( shaderList.m_Choices.m_Size + 1 > shaderList.m_Choices.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<MDLSquenceLayer_t,int>::Grow(
            this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&shaderList.m_Choices,
            num: shaderList.m_Choices.m_Size - shaderList.m_Choices.m_Memory.m_nAllocationCount + 1);
          m_Size = shaderList.m_Choices.m_Size;
        }
        m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        shaderList.m_Choices.m_Size = m_Size + 1;
        v13 = m_Size - v11;
        shaderList.m_Choices.m_pElements = shaderList.m_Choices.m_Memory.m_pMemory;
        if ( v13 > 0 )
        {
          _V_memmove(
            dest: &shaderList.m_Choices.m_Memory.m_pMemory[v11 + 1],
            src: &shaderList.m_Choices.m_Memory.m_pMemory[v11],
            count: 8 * v13);
          m_pMemory = shaderList.m_Choices.m_Memory.m_pMemory;
        }
        p_m_pChoiceString = &m_pMemory[v11].m_pChoiceString;
        v15 = ppShaderList[v3]->GetName(this: ppShaderList[v3]);
        v16 = ppShaderList;
        *p_m_pChoiceString = v15;
        v17 = &shaderList.m_Choices.m_Memory.m_pMemory[v11];
        v18 = v16[v3]->GetName(this: v16[v3]);
        v7 = ppShaderList;
        v17->m_pChoiceValue = (const char *)v18;
        v5 = nCount;
      }
      ++v3;
    }
    while ( v3 < v5 );
  }
  v19 = pShaderPickerDialog;
  pShaderPickerDialog->AddActionSignalTarget_2(this: pShaderPickerDialog, a2: v23);
  CPickerFrame::DoModal(this: v19, list: &shaderList, pContextKeyValues: nullptr);
  v20 = shaderList.m_Choices.m_Memory.m_pMemory;
  shaderList.m_Choices.m_Size = 0;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( shaderList.m_Choices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: shaderList.m_Choices.m_Memory.m_pMemory);
      v20 = nullptr;
      shaderList.m_Choices.m_Memory.m_pMemory = nullptr;
    }
    shaderList.m_Choices.m_Memory.m_nAllocationCount = 0;
  }
  shaderList.m_Choices.m_pElements = v20;
  if ( shaderList.m_Choices.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
}

//------------------------------------------------------------------------------
// Address: 0x0049ACB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeShaderPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeShaderPickerPanel::GetMessageMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049ACE0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeShaderPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeShaderPickerPanel::GetAnimMap(CAttributeShaderPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049ACF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeShaderPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeShaderPickerPanel::GetKBMap(CAttributeShaderPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
  `CAttributeShaderPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049AD20
// Name: public: CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeShaderPickerPanel *__thiscall CAttributeShaderPickerPanel::CAttributeShaderPickerPanel(
        CAttributeShaderPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeShaderPickerPanel_vtbl *)&CAttributeShaderPickerPanel::`vftable';
  if ( `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeShaderPickerPanel");
    v4->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeShaderPickerPanel");
    v5->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeShaderPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeShaderPickerPanel");
    v6->pfnClassName = CAttributeShaderPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeShaderPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
