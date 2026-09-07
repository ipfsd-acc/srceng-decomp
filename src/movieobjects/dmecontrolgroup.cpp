// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmecontrolgroup.cpp
// Functions: 10
// ============================================================

#include "movieobjects\dmecontrolgroup.h"

//------------------------------------------------------------------------------
// Address: 0x0055FC40
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x0055FDD0
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0055FE60
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055FE90
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055FED0
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AE6E0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B08F0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AE710
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE720
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0900
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005BC280
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x005BC3B0
// Name: public: bool CDmeControlGroup::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsEmpty(CDmeControlGroup *this)
{
  return this->m_Controls.m_Storage.m_Size <= 0 && this->m_Children.m_Storage.m_Size <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x005BC460
// Name: public: bool CDmeControlGroup::RemoveControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveControl(CDmeControlGroup *this, const CDmElement *pControl)
{
  int v2; // edi
  CDmaElementArray<CDmElement> *p_m_Controls; // ebx
  CDmElement *v4; // eax
  const CDmElement *v5; // esi
  int nControls; // [esp+Ch] [ebp-4h]

  if ( pControl == nullptr )
    return 0;
  v2 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
    return 0;
  p_m_Controls = &this->m_Controls;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Controls->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    if ( pControl == v5 )
      break;
    if ( ++v2 >= nControls )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Controls,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005BC4E0
// Name: public: class CDmElement __near * CDmeControlGroup::FindControlByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeControlGroup::FindControlByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmElement *result; // eax
  int nControls; // [esp+Ch] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
  {
LABEL_8:
    if ( recursive && (v9 = 0, (nChildren = this->m_Children.m_Storage.m_Size) > 0) )
    {
      while ( 1 )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v9]);
        v11 = (CDmeControlGroup *)v10;
        if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindControlByName(this: v11, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v9 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
      {
        m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v5 >= nControls )
        goto LABEL_8;
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BC5E0
// Name: public: bool CDmeControlGroup::RemoveChild(class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveChild(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  int v2; // edi
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // ebx
  CDmElement *v4; // eax
  const CDmeControlGroup *v5; // esi
  int nChildren; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return 0;
  p_m_Children = &this->m_Children;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmeControlGroup *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      v5 = nullptr;
    if ( v5 == pGroup )
      break;
    if ( ++v2 >= nChildren )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Children,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005BC660
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindChildByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindChildByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int m_Size; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  int v10; // edi
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  CDmeControlGroup *result; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Children.m_Storage.m_Size;
  v6 = 0;
  nChildren = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    if ( recursive && (v10 = 0, m_Size > 0) )
    {
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v10]);
        v12 = (CDmeControlGroup *)v11;
        if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindChildByName(this: v12, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v10 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v6 >= nChildren )
      {
        m_Size = nChildren;
        goto LABEL_9;
      }
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmeControlGroup *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BC760
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindParent(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_7 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_7 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  return FindReferringElement<CDmeControlGroup>(
           pElement: this,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x005BC7B0
// Name: public: bool CDmeControlGroup::IsAncestorOfGroup(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::IsAncestorOfGroup(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // esi
  CDmeControlGroup *v5; // edi
  CUtlSymbolLarge *(__thiscall *v6)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *v7; // eax

  if ( pGroup == nullptr )
    return 0;
  if ( (_S1_7 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_7 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: pGroup,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    v5 = Referring;
    if ( (_S1_7 & 1) == 0 )
    {
      v6 = g_pDataModel->GetSymbol;
      _S1_7 |= 1u;
      v6(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    v7 = FindReferringElement<CDmeControlGroup>(
           pElement: Referring,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
    Referring = v7;
    if ( v5 == v7 || v7 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005BC880
// Name: private: static void CDmeControlGroup::DestroyGroup_R(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup_R(int pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CExpressionCalculator *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int v7; // edi
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // esi
  IDataModel_vtbl *v10; // esi
  int BufferType; // eax
  int nControls; // [esp+Ch] [ebp-8h]
  int nChildren; // [esp+10h] [ebp-4h]
  CDmaElementArray<CDmElement> *nChildrena; // [esp+10h] [ebp-4h]

  v3 = (CExpressionCalculator *)pGroup;
  if ( pGroup != 0 && (pRecipient != nullptr || *(int *)(pGroup + 108) <= 0 && *(int *)(pGroup + 80) <= 0) )
  {
    v4 = 0;
    nChildren = *(_DWORD *)(pGroup + 80);
    if ( nChildren > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v3->m_stack.m_Size + 4 * v4));
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
        {
          if ( recursive )
          {
            CDmeControlGroup::DestroyGroup_R(pGroup: v6, pRecipient, recursive: true);
          }
          else
          {
            pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &pRecipient->m_Children,
              src: (DmElementHandle_t *)&pGroup);
          }
        }
        ++v4;
      }
      while ( v4 < nChildren );
    }
    v7 = 0;
    nControls = v3[1].m_varNames.m_Size;
    if ( nControls > 0 )
    {
      nChildrena = &pRecipient->m_Controls;
      do
      {
        v8 = g_pDataModel->GetElement(
               this: g_pDataModel,
               a2: *((_DWORD *)&v3[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v7));
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          pGroup = CCodecBuffer_Block::GetBufferType(this: v9);
        else
          pGroup = -1;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: nChildrena,
          src: (DmElementHandle_t *)&pGroup);
        ++v7;
      }
      while ( v7 < nControls );
    }
    v10 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BC9C0
// Name: public: void CDmeControlGroup::SetGroupColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetGroupColor(CDmeControlGroup *this, const Color *groupColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_GroupColor.m_pAttribute, value: groupColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetGroupColor(this: v9, groupColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BCA80
// Name: public: bool CDmeControlGroup::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsVisible(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_7 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_7 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Visible.m_Storage;
  result = CDmeControlGroup::IsVisible(this: Referring);
  if ( result )
    return this->m_Visible.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BCAE0
// Name: public: bool CDmeControlGroup::IsSelectable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsSelectable(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_7 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_7 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Selectable.m_Storage;
  result = CDmeControlGroup::IsSelectable(this: Referring);
  if ( result )
    return this->m_Selectable.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BCB40
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindRootControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindRootControlGroup(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *i; // esi
  CUtlSymbolLarge *(__thiscall *v4)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( (_S1_7 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_7 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  for ( i = FindReferringElement<CDmeControlGroup>(
              pElement: this,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL);
        i != nullptr;
        i = FindReferringElement<CDmeControlGroup>(
              pElement: i,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL) )
  {
    this = i;
    if ( (_S1_7 & 1) == 0 )
    {
      v4 = g_pDataModel->GetSymbol;
      _S1_7 |= 1u;
      v4(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005BCBE0
// Name: public: class CDmeAnimationSet __near * CDmeControlGroup::FindAnimationSet(bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CDmeControlGroup::FindAnimationSet(CDmeControlGroup *this, bool bSearchAncestors)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeAnimationSet *result; // eax
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *Referring; // eax

  if ( (_S2_3 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_3 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symRootControlGroup, a3: "rootControlGroup");
  }
  if ( this == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = FindReferringElement<CDmeAnimationSet>(
               pElement: (CExpressionCalculator *)this,
               symAttrName: symRootControlGroup,
               bMustBeInSameFile: true,
               depth: TD_ALL);
    if ( result != nullptr )
      break;
    if ( bSearchAncestors )
    {
      if ( (_S1_7 & 1) == 0 )
      {
        v5 = g_pDataModel->GetSymbol;
        _S1_7 |= 1u;
        v5(this: g_pDataModel, result: &symChildren_2, a3: "children");
      }
      Referring = FindReferringElement<CDmeControlGroup>(
                    pElement: this,
                    symAttrName: symChildren_2,
                    bMustBeInSameFile: true,
                    depth: TD_ALL);
      if ( this != Referring )
      {
        this = Referring;
        if ( Referring != nullptr )
          continue;
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BCC90
// Name: public: static class CDmeControlGroup __near * CDmeControlGroup::FindGroupContainingControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl CDmeControlGroup::FindGroupContainingControl(const CDmElement *pControl)
{
  CUtlSymbolLarge *v1; // eax
  _BYTE v3[4]; // [esp+0h] [ebp-4h] BYREF

  v1 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v3, a3: "controls");
  return FindReferringElement<CDmeControlGroup>(
           pElement: pControl,
           symAttrName: (CUtlSymbolLarge)v1->u.m_Id,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x005BCCD0
// Name: public: void CDmeControlGroup::AddChild(class CDmeControlGroup __near *,class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddChild(
        CDmeControlGroup *this,
        int pGroup,
        CExpressionCalculator *pInsertBeforeGroup)
{
  CDmeControlGroup *v3; // ebx
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *v7; // edi

  v3 = (CDmeControlGroup *)pGroup;
  if ( (CDmeControlGroup *)pGroup != this )
  {
    if ( (_S1_7 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_7 |= 1u;
      GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveChild(this: Referring, pGroup: v3);
    if ( pInsertBeforeGroup == nullptr
      || (pGroup = CCodecBuffer_Block::GetBufferType(this: pInsertBeforeGroup),
          (v7 = (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                                                                          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Children,
                                                                          src: (vgui::PageTab **)&pGroup)) == (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)-1) )
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        src: (DmElementHandle_t *)&pGroup);
    }
    else
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Children,
        elem: v7,
        src: (DmElementHandle_t *)&pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BCDD0
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::CreateControlGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CreateControlGroup(CDmeControlGroup *this, const char *pchName)
{
  CDmeControlGroup *result; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  int v6; // esi

  result = CDmeControlGroup::FindChildByName(this, pchName, recursive: false, pParentGroup: nullptr);
  if ( result == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id,
           a3: pchName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (int)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
      v6 = 0;
    CDmeControlGroup::AddChild(this, pGroup: v6, pInsertBeforeGroup: nullptr);
    return (CDmeControlGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BCE50
// Name: public: static void CDmeControlGroup::DestroyGroup(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup(CDmeControlGroup *pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CDmeControlGroup *v5; // esi
  CDmeControlGroup *v6; // eax

  if ( pGroup != nullptr )
  {
    if ( (_S1_7 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_7 |= 1u;
      GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: pGroup,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v5 = Referring;
    if ( Referring != nullptr )
    {
      CDmeControlGroup::RemoveChild(this: Referring, pGroup);
      v6 = pRecipient;
      if ( pRecipient == nullptr )
      {
        CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v5, recursive);
        return;
      }
    }
    else
    {
      v6 = pRecipient;
    }
    CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v6, recursive);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BCEE0
// Name: public: void CDmeControlGroup::AddControl(class CDmElement __near *,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddControl(
        CDmeControlGroup *this,
        CDmElement *pControl,
        CExpressionCalculator *pInsertBeforeControl)
{
  CDmElement *v3; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeControlGroup *Referring; // eax
  CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *v7; // ebx

  v3 = pControl;
  if ( pControl != nullptr )
  {
    v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pControl, a3: "controls");
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveControl(this: Referring, pControl: v3);
    if ( pInsertBeforeControl == nullptr
      || (pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: pInsertBeforeControl),
          (v7 = (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                                                                          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Controls,
                                                                          src: (vgui::PageTab **)&pControl)) == (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)-1) )
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Controls,
        src: (DmElementHandle_t *)&pControl);
    }
    else
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Controls,
        elem: v7,
        src: (DmElementHandle_t *)&pControl);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BCF90
// Name: public: void CDmeControlGroup::GetAllChildren(class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetAllChildren(
        CDmeControlGroup *this,
        CUtlMemory<vgui::TreeNode *,int> *childGroupList)
{
  int v2; // edi
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // ebx
  int BufferType; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *v9; // ecx
  int v10; // eax
  DmElementHandle_t *v11; // edi
  int nChildren; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *v13; // [esp+10h] [ebp-8h]
  int iChild; // [esp+14h] [ebp-4h]
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *childGroupLista; // [esp+20h] [ebp+8h]

  v2 = 0;
  v13 = this;
  nChildren = this->m_Children.m_Storage.m_Size;
  iChild = 0;
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CExpressionCalculator *)v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      {
        BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
        m_pMemory = (int)childGroupList[1].m_pMemory;
        childGroupLista = (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)BufferType;
        m_nAllocationCount = childGroupList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: childGroupList, num: m_pMemory - m_nAllocationCount + 1);
        ++childGroupList[1].m_pMemory;
        v9 = (DmElementHandle_t *)childGroupList->m_pMemory;
        v10 = (int)childGroupList[1].m_pMemory - m_pMemory - 1;
        childGroupList[1].m_nAllocationCount = (int)childGroupList->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
        v11 = (DmElementHandle_t *)&childGroupList->m_pMemory[m_pMemory];
        if ( v11 != nullptr )
          *v11 = (DmElementHandle_t)childGroupLista;
        CDmeControlGroup::GetAllChildren(
          this: (CDmeControlGroup *)v5,
          (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)childGroupList);
        v2 = iChild;
      }
      iChild = ++v2;
      if ( v2 >= nChildren )
        break;
      this = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BD070
// Name: private: static bool CDmeControlGroup::DestroyEmptyChildren_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmeControlGroup::DestroyEmptyChildren_R(CDmeControlGroup *pGroup)
{
  int m_Size; // edi
  int v2; // esi
  CDmeControlGroup **m_pMemory; // ebx
  CDmElement *v4; // eax
  CDmeControlGroup *v5; // edi
  int v6; // edi
  CDmeControlGroup **v7; // edi
  int i; // edi
  char result; // al
  CUtlVector<CDmeControlGroup *,CUtlMemory<CDmeControlGroup *,int> > childrenToDestroy; // [esp+Ch] [ebp-20h] BYREF
  int nNumChildren; // [esp+20h] [ebp-Ch]
  CDmElement *v12; // [esp+24h] [ebp-8h]
  int iChild; // [esp+28h] [ebp-4h]
  char pGroup_3; // [esp+37h] [ebp+Bh]

  m_Size = pGroup->m_Children.m_Storage.m_Size;
  v2 = 0;
  m_pMemory = nullptr;
  nNumChildren = m_Size;
  childrenToDestroy.m_Memory.m_pMemory = nullptr;
  childrenToDestroy.m_Memory.m_nAllocationCount = m_Size;
  childrenToDestroy.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
  {
    m_pMemory = (CDmeControlGroup **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    childrenToDestroy.m_Memory.m_pMemory = m_pMemory;
  }
  childrenToDestroy.m_Size = 0;
  childrenToDestroy.m_pElements = m_pMemory;
  iChild = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[iChild]);
      v5 = (CDmeControlGroup *)v4;
      v12 = v4;
      if ( v4 != nullptr
        && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType)
        && CDmeControlGroup::DestroyEmptyChildren_R(pGroup: v5) )
      {
        v6 = v2;
        if ( v2 + 1 > childrenToDestroy.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&childrenToDestroy,
            num: v2 - childrenToDestroy.m_Memory.m_nAllocationCount + 1);
          v2 = childrenToDestroy.m_Size;
          m_pMemory = childrenToDestroy.m_Memory.m_pMemory;
        }
        childrenToDestroy.m_Size = ++v2;
        childrenToDestroy.m_pElements = m_pMemory;
        if ( v2 - v6 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (v2 - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          *v7 = (CDmeControlGroup *)v12;
      }
      ++iChild;
    }
    while ( iChild < nNumChildren );
  }
  for ( i = 0; i < v2; ++i )
    CDmeControlGroup::RemoveChild(this: pGroup, pGroup: m_pMemory[i]);
  if ( pGroup->m_Children.m_Storage.m_Size != 0 || pGroup->m_Controls.m_Storage.m_Size != 0 )
  {
    pGroup_3 = 0;
    result = 0;
  }
  else
  {
    result = 1;
    pGroup_3 = 1;
  }
  if ( childrenToDestroy.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pGroup_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BD1D0
// Name: public: void CDmeControlGroup::DestroyEmptyChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::DestroyEmptyChildren(CDmeControlGroup *this)
{
  CDmeControlGroup::DestroyEmptyChildren_R(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x005BD1E0
// Name: public: void CDmeControlGroup::GetControlsInGroup(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetControlsInGroup(
        CDmeControlGroup *this,
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *controlList,
        bool recursive)
{
  int v4; // ebx
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmElement **m_pMemory; // ecx
  int v13; // eax
  CDmElement **v14; // edi
  int nControls; // [esp+18h] [ebp+8h]
  int iControl; // [esp+1Ch] [ebp+Ch]
  int iControla; // [esp+1Ch] [ebp+Ch]

  if ( recursive )
  {
    v4 = 0;
    iControl = this->m_Children.m_Storage.m_Size;
    if ( iControl > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
          CDmeControlGroup::GetControlsInGroup(this: v6, controlList, recursive: true);
        ++v4;
      }
      while ( v4 < iControl );
    }
  }
  v7 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  iControla = 0;
  if ( nControls > 0 )
  {
    do
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v7]);
      v9 = v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
      {
        m_Size = controlList->m_Size;
        m_nAllocationCount = controlList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)controlList,
            num: m_Size - m_nAllocationCount + 1);
        ++controlList->m_Size;
        m_pMemory = controlList->m_Memory.m_pMemory;
        v13 = controlList->m_Size - m_Size - 1;
        controlList->m_pElements = controlList->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
        v14 = &controlList->m_Memory.m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = v9;
      }
      v7 = iControla + 1;
      iControla = v7;
    }
    while ( v7 < nControls );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BD360
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005BD3F0
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BD420
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BD460
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006800A0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682EA0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005BC3D0
// Name: class CDmeControlGroup __near * FindReferringElement<class CDmeControlGroup>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindReferringElement<CDmeControlGroup>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeControlGroup *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006800D0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006800E0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682EB0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104F1930
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x104F1A60
// Name: public: bool CDmeControlGroup::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsEmpty(CDmeControlGroup *this)
{
  return this->m_Controls.m_Storage.m_Size <= 0 && this->m_Children.m_Storage.m_Size <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x104F1B10
// Name: public: bool CDmeControlGroup::RemoveControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveControl(CDmeControlGroup *this, const CDmElement *pControl)
{
  int v2; // edi
  CDmaElementArray<CDmElement> *p_m_Controls; // ebx
  CDmElement *v4; // eax
  const CDmElement *v5; // esi
  int nControls; // [esp+Ch] [ebp-4h]

  if ( pControl == nullptr )
    return 0;
  v2 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
    return 0;
  p_m_Controls = &this->m_Controls;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Controls->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    if ( pControl == v5 )
      break;
    if ( ++v2 >= nControls )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Controls,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1B90
// Name: public: class CDmElement __near * CDmeControlGroup::FindControlByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeControlGroup::FindControlByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmElement *result; // eax
  int nControls; // [esp+Ch] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
  {
LABEL_8:
    if ( recursive && (v9 = 0, (nChildren = this->m_Children.m_Storage.m_Size) > 0) )
    {
      while ( 1 )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v9]);
        v11 = (CDmeControlGroup *)v10;
        if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindControlByName(this: v11, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v9 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
      {
        m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v5 >= nControls )
        goto LABEL_8;
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F1C90
// Name: public: bool CDmeControlGroup::RemoveChild(class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveChild(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  int v2; // edi
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // ebx
  CDmElement *v4; // eax
  const CDmeControlGroup *v5; // esi
  int nChildren; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return 0;
  p_m_Children = &this->m_Children;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmeControlGroup *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      v5 = nullptr;
    if ( v5 == pGroup )
      break;
    if ( ++v2 >= nChildren )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Children,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1D10
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindChildByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindChildByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int m_Size; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  int v10; // edi
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  CDmeControlGroup *result; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Children.m_Storage.m_Size;
  v6 = 0;
  nChildren = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    if ( recursive && (v10 = 0, m_Size > 0) )
    {
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v10]);
        v12 = (CDmeControlGroup *)v11;
        if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindChildByName(this: v12, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v10 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v6 >= nChildren )
      {
        m_Size = nChildren;
        goto LABEL_9;
      }
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmeControlGroup *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F1E10
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindParent(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_53 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_53 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  return FindReferringElement<CDmeControlGroup>(
           pElement: this,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x104F1E60
// Name: public: bool CDmeControlGroup::IsAncestorOfGroup(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::IsAncestorOfGroup(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // esi
  CDmeControlGroup *v5; // edi
  CUtlSymbolLarge *(__thiscall *v6)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *v7; // eax

  if ( pGroup == nullptr )
    return 0;
  if ( (_S1_53 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_53 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: pGroup,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    v5 = Referring;
    if ( (_S1_53 & 1) == 0 )
    {
      v6 = g_pDataModel->GetSymbol;
      _S1_53 |= 1u;
      v6(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    v7 = FindReferringElement<CDmeControlGroup>(
           pElement: Referring,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
    Referring = v7;
    if ( v5 == v7 || v7 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104F1F30
// Name: private: static void CDmeControlGroup::DestroyGroup_R(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup_R(int pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CExpressionCalculator *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int v7; // edi
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // esi
  IDataModel_vtbl *v10; // esi
  int BufferType; // eax
  int nControls; // [esp+Ch] [ebp-8h]
  int nChildren; // [esp+10h] [ebp-4h]
  CDmaElementArray<CDmElement> *nChildrena; // [esp+10h] [ebp-4h]

  v3 = (CExpressionCalculator *)pGroup;
  if ( pGroup != 0 && (pRecipient != nullptr || *(int *)(pGroup + 108) <= 0 && *(int *)(pGroup + 80) <= 0) )
  {
    v4 = 0;
    nChildren = *(_DWORD *)(pGroup + 80);
    if ( nChildren > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v3->m_stack.m_Size + 4 * v4));
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
        {
          if ( recursive )
          {
            CDmeControlGroup::DestroyGroup_R(pGroup: v6, pRecipient, recursive: true);
          }
          else
          {
            pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &pRecipient->m_Children,
              src: (DmElementHandle_t *)&pGroup);
          }
        }
        ++v4;
      }
      while ( v4 < nChildren );
    }
    v7 = 0;
    nControls = v3[1].m_varNames.m_Size;
    if ( nControls > 0 )
    {
      nChildrena = &pRecipient->m_Controls;
      do
      {
        v8 = g_pDataModel->GetElement(
               this: g_pDataModel,
               a2: *((_DWORD *)&v3[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v7));
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          pGroup = CCodecBuffer_Block::GetBufferType(this: v9);
        else
          pGroup = -1;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: nChildrena,
          src: (DmElementHandle_t *)&pGroup);
        ++v7;
      }
      while ( v7 < nControls );
    }
    v10 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2070
// Name: public: void CDmeControlGroup::SetGroupColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetGroupColor(CDmeControlGroup *this, const Color *groupColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_GroupColor.m_pAttribute, value: groupColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetGroupColor(this: v9, groupColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2130
// Name: public: bool CDmeControlGroup::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsVisible(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_53 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_53 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Visible.m_Storage;
  result = CDmeControlGroup::IsVisible(this: Referring);
  if ( result )
    return this->m_Visible.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F2190
// Name: public: bool CDmeControlGroup::IsSelectable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsSelectable(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_53 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_53 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Selectable.m_Storage;
  result = CDmeControlGroup::IsSelectable(this: Referring);
  if ( result )
    return this->m_Selectable.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F21F0
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindRootControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindRootControlGroup(CDmeControlGroup *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *i; // esi
  CUtlSymbolLarge *(__thiscall *v4)(IDataModel *, CUtlSymbolLarge *, const char *); // eax

  if ( (_S1_53 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_53 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
  }
  for ( i = FindReferringElement<CDmeControlGroup>(
              pElement: this,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL);
        i != nullptr;
        i = FindReferringElement<CDmeControlGroup>(
              pElement: i,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL) )
  {
    this = i;
    if ( (_S1_53 & 1) == 0 )
    {
      v4 = g_pDataModel->GetSymbol;
      _S1_53 |= 1u;
      v4(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104F2290
// Name: public: class CDmeAnimationSet __near * CDmeControlGroup::FindAnimationSet(bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CDmeControlGroup::FindAnimationSet(CDmeControlGroup *this, bool bSearchAncestors)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeAnimationSet *result; // eax
  CUtlSymbolLarge *(__thiscall *v5)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *Referring; // eax

  if ( (_S2_22 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S2_22 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symRootControlGroup, a3: "rootControlGroup");
  }
  if ( this == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = FindReferringElement<CDmeAnimationSet>(
               pElement: (CExpressionCalculator *)this,
               symAttrName: symRootControlGroup,
               bMustBeInSameFile: true,
               depth: TD_ALL);
    if ( result != nullptr )
      break;
    if ( bSearchAncestors )
    {
      if ( (_S1_53 & 1) == 0 )
      {
        v5 = g_pDataModel->GetSymbol;
        _S1_53 |= 1u;
        v5(this: g_pDataModel, result: &symChildren_2, a3: "children");
      }
      Referring = FindReferringElement<CDmeControlGroup>(
                    pElement: this,
                    symAttrName: symChildren_2,
                    bMustBeInSameFile: true,
                    depth: TD_ALL);
      if ( this != Referring )
      {
        this = Referring;
        if ( Referring != nullptr )
          continue;
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F2340
// Name: public: static class CDmeControlGroup __near * CDmeControlGroup::FindGroupContainingControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl CDmeControlGroup::FindGroupContainingControl(const CDmElement *pControl)
{
  CUtlSymbolLarge *v1; // eax
  _BYTE v3[4]; // [esp+0h] [ebp-4h] BYREF

  v1 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v3, a3: "controls");
  return FindReferringElement<CDmeControlGroup>(
           pElement: pControl,
           symAttrName: (CUtlSymbolLarge)v1->u.m_Id,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x104F2380
// Name: public: void CDmeControlGroup::AddChild(class CDmeControlGroup __near *,class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddChild(
        CDmeControlGroup *this,
        int pGroup,
        CExpressionCalculator *pInsertBeforeGroup)
{
  CDmeControlGroup *v3; // ebx
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *v7; // edi

  v3 = (CDmeControlGroup *)pGroup;
  if ( (CDmeControlGroup *)pGroup != this )
  {
    if ( (_S1_53 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_53 |= 1u;
      GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveChild(this: Referring, pGroup: v3);
    if ( pInsertBeforeGroup == nullptr
      || (pGroup = CCodecBuffer_Block::GetBufferType(this: pInsertBeforeGroup),
          (v7 = (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)CUtlVector<CMapSolid *,CUtlMemory<CMapSolid *,int>>::Find(
                                                                          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Children,
                                                                          src: (vgui::PageTab *const *)&pGroup)) == (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)-1) )
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        src: (DmElementHandle_t *)&pGroup);
    }
    else
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Children,
        elem: v7,
        src: (DmElementHandle_t *)&pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2480
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::CreateControlGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CreateControlGroup(CDmeControlGroup *this, const char *pchName)
{
  CDmeControlGroup *result; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  int v6; // esi

  result = CDmeControlGroup::FindChildByName(this, pchName, recursive: false, pParentGroup: nullptr);
  if ( result == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id,
           a3: pchName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (int)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
      v6 = 0;
    CDmeControlGroup::AddChild(this, pGroup: v6, pInsertBeforeGroup: nullptr);
    return (CDmeControlGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F2500
// Name: public: static void CDmeControlGroup::DestroyGroup(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup(CDmeControlGroup *pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CDmeControlGroup *v5; // esi
  CDmeControlGroup *v6; // eax

  if ( pGroup != nullptr )
  {
    if ( (_S1_53 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_53 |= 1u;
      GetSymbol(this: g_pDataModel, result: &symChildren_2, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: pGroup,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v5 = Referring;
    if ( Referring != nullptr )
    {
      CDmeControlGroup::RemoveChild(this: Referring, pGroup);
      v6 = pRecipient;
      if ( pRecipient == nullptr )
      {
        CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v5, recursive);
        return;
      }
    }
    else
    {
      v6 = pRecipient;
    }
    CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v6, recursive);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2590
// Name: public: void CDmeControlGroup::AddControl(class CDmElement __near *,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddControl(
        CDmeControlGroup *this,
        CDmElement *pControl,
        CExpressionCalculator *pInsertBeforeControl)
{
  CDmElement *v3; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeControlGroup *Referring; // eax
  CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *v7; // ebx

  v3 = pControl;
  if ( pControl != nullptr )
  {
    v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pControl, a3: "controls");
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveControl(this: Referring, pControl: v3);
    if ( pInsertBeforeControl == nullptr
      || (pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: pInsertBeforeControl),
          (v7 = (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)CUtlVector<CMapSolid *,CUtlMemory<CMapSolid *,int>>::Find(
                                                                          this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Controls,
                                                                          src: (vgui::PageTab *const *)&pControl)) == (CUndoAttributeArrayBase<enum DmElementHandle_t>_vtbl *)-1) )
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Controls,
        src: (DmElementHandle_t *)&pControl);
    }
    else
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Controls,
        elem: v7,
        src: (DmElementHandle_t *)&pControl);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2640
// Name: public: void CDmeControlGroup::GetAllChildren(class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetAllChildren(
        CDmeControlGroup *this,
        CUtlMemory<vgui::TreeNode *,int> *childGroupList)
{
  int v2; // edi
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // ebx
  int BufferType; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *v9; // ecx
  int v10; // eax
  DmElementHandle_t *v11; // edi
  int nChildren; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *v13; // [esp+10h] [ebp-8h]
  int iChild; // [esp+14h] [ebp-4h]
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *childGroupLista; // [esp+20h] [ebp+8h]

  v2 = 0;
  v13 = this;
  nChildren = this->m_Children.m_Storage.m_Size;
  iChild = 0;
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CExpressionCalculator *)v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      {
        BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
        m_pMemory = (int)childGroupList[1].m_pMemory;
        childGroupLista = (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)BufferType;
        m_nAllocationCount = childGroupList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: childGroupList, num: m_pMemory - m_nAllocationCount + 1);
        ++childGroupList[1].m_pMemory;
        v9 = (DmElementHandle_t *)childGroupList->m_pMemory;
        v10 = (int)childGroupList[1].m_pMemory - m_pMemory - 1;
        childGroupList[1].m_nAllocationCount = (int)childGroupList->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v9[m_pMemory + 1],
            src: (unsigned __int8 *)&v9[m_pMemory],
            count: 4 * v10);
        v11 = (DmElementHandle_t *)&childGroupList->m_pMemory[m_pMemory];
        if ( v11 != nullptr )
          *v11 = (DmElementHandle_t)childGroupLista;
        CDmeControlGroup::GetAllChildren(
          this: (CDmeControlGroup *)v5,
          (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)childGroupList);
        v2 = iChild;
      }
      iChild = ++v2;
      if ( v2 >= nChildren )
        break;
      this = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2720
// Name: private: static bool CDmeControlGroup::DestroyEmptyChildren_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmeControlGroup::DestroyEmptyChildren_R(CDmeControlGroup *pGroup)
{
  int m_Size; // edi
  int v2; // esi
  CDmeControlGroup **m_pMemory; // ebx
  CDmElement *v4; // eax
  CDmeControlGroup *v5; // edi
  int v6; // edi
  CDmeControlGroup **v7; // edi
  int i; // edi
  char result; // al
  CUtlVector<CDmeControlGroup *,CUtlMemory<CDmeControlGroup *,int> > childrenToDestroy; // [esp+Ch] [ebp-20h] BYREF
  int nNumChildren; // [esp+20h] [ebp-Ch]
  CDmElement *v12; // [esp+24h] [ebp-8h]
  int iChild; // [esp+28h] [ebp-4h]
  char pGroup_3; // [esp+37h] [ebp+Bh]

  m_Size = pGroup->m_Children.m_Storage.m_Size;
  v2 = 0;
  m_pMemory = nullptr;
  nNumChildren = m_Size;
  childrenToDestroy.m_Memory.m_pMemory = nullptr;
  childrenToDestroy.m_Memory.m_nAllocationCount = m_Size;
  childrenToDestroy.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
  {
    m_pMemory = (CDmeControlGroup **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    childrenToDestroy.m_Memory.m_pMemory = m_pMemory;
  }
  childrenToDestroy.m_Size = 0;
  childrenToDestroy.m_pElements = m_pMemory;
  iChild = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[iChild]);
      v5 = (CDmeControlGroup *)v4;
      v12 = v4;
      if ( v4 != nullptr
        && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType)
        && CDmeControlGroup::DestroyEmptyChildren_R(pGroup: v5) )
      {
        v6 = v2;
        if ( v2 + 1 > childrenToDestroy.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&childrenToDestroy,
            num: v2 - childrenToDestroy.m_Memory.m_nAllocationCount + 1);
          v2 = childrenToDestroy.m_Size;
          m_pMemory = childrenToDestroy.m_Memory.m_pMemory;
        }
        childrenToDestroy.m_Size = ++v2;
        childrenToDestroy.m_pElements = m_pMemory;
        if ( v2 - v6 - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v6 + 1],
            src: (unsigned __int8 *)&m_pMemory[v6],
            count: 4 * (v2 - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          *v7 = (CDmeControlGroup *)v12;
      }
      ++iChild;
    }
    while ( iChild < nNumChildren );
  }
  for ( i = 0; i < v2; ++i )
    CDmeControlGroup::RemoveChild(this: pGroup, pGroup: m_pMemory[i]);
  if ( pGroup->m_Children.m_Storage.m_Size != 0 || pGroup->m_Controls.m_Storage.m_Size != 0 )
  {
    pGroup_3 = 0;
    result = 0;
  }
  else
  {
    result = 1;
    pGroup_3 = 1;
  }
  if ( childrenToDestroy.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pGroup_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104F2880
// Name: public: void CDmeControlGroup::DestroyEmptyChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::DestroyEmptyChildren(CDmeControlGroup *this)
{
  CDmeControlGroup::DestroyEmptyChildren_R(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x104F2890
// Name: public: void CDmeControlGroup::GetControlsInGroup(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetControlsInGroup(
        CDmeControlGroup *this,
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *controlList,
        bool recursive)
{
  int v4; // ebx
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmElement **m_pMemory; // ecx
  int v13; // eax
  CDmElement **v14; // edi
  int nControls; // [esp+18h] [ebp+8h]
  int iControl; // [esp+1Ch] [ebp+Ch]
  int iControla; // [esp+1Ch] [ebp+Ch]

  if ( recursive )
  {
    v4 = 0;
    iControl = this->m_Children.m_Storage.m_Size;
    if ( iControl > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
          CDmeControlGroup::GetControlsInGroup(this: v6, controlList, recursive: true);
        ++v4;
      }
      while ( v4 < iControl );
    }
  }
  v7 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  iControla = 0;
  if ( nControls > 0 )
  {
    do
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v7]);
      v9 = v8;
      if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
      {
        m_Size = controlList->m_Size;
        m_nAllocationCount = controlList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)controlList,
            num: m_Size - m_nAllocationCount + 1);
        ++controlList->m_Size;
        m_pMemory = controlList->m_Memory.m_pMemory;
        v13 = controlList->m_Size - m_Size - 1;
        controlList->m_pElements = controlList->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v13);
        v14 = &controlList->m_Memory.m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = v9;
      }
      v7 = iControla + 1;
      iControla = v7;
    }
    while ( v7 < nControls );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104F2A10
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104F2AA0
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F2AD0
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104F2B20
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C80E0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD310
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x104F1A80
// Name: class CDmeControlGroup __near * FindReferringElement<class CDmeControlGroup>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindReferringElement<CDmeControlGroup>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeControlGroup *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C8110
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C8120
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD320
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056B1C0
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x0056B350
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056B3E0
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B410
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B450
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D600
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F9E0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D630
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D640
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F9F0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005B4200
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x005B4390
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B4420
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4450
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4490
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F22A0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4CF0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F22D0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F22E0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D00
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x005242F0
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x00524480
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524510
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524540
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524580
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC80
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F080
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056CCB0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056CCC0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F090
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0052B910
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x0052BA40
// Name: public: void CDmeControlGroup::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetVisible(CDmeControlGroup *this, bool bVisible)
{
  CDmAttribute::SetValue<bool>(this: this->m_Visible.m_pAttribute, value: &bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x0052BA60
// Name: public: void CDmeControlGroup::SetSelectable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetSelectable(CDmeControlGroup *this, bool bSelectable)
{
  CDmAttribute::SetValue<bool>(this: this->m_Selectable.m_pAttribute, value: &bSelectable);
}

//------------------------------------------------------------------------------
// Address: 0x0052BA80
// Name: public: void CDmeControlGroup::SetSnappable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetSnappable(CDmeControlGroup *this, bool bSnappable)
{
  CDmAttribute::SetValue<bool>(this: this->m_Snappable.m_pAttribute, value: &bSnappable);
}

//------------------------------------------------------------------------------
// Address: 0x0052BAA0
// Name: public: bool CDmeControlGroup::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsEmpty(CDmeControlGroup *this)
{
  return this->m_Controls.m_Storage.m_Size <= 0 && this->m_Children.m_Storage.m_Size <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0052BB50
// Name: public: bool CDmeControlGroup::RemoveControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveControl(CDmeControlGroup *this, const CDmElement *pControl)
{
  int v2; // edi
  CDmaElementArray<CDmElement> *p_m_Controls; // ebx
  CDmElement *v4; // eax
  const CDmElement *v5; // esi
  int nControls; // [esp+Ch] [ebp-4h]

  if ( pControl == nullptr )
    return 0;
  v2 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
    return 0;
  p_m_Controls = &this->m_Controls;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Controls->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    if ( pControl == v5 )
      break;
    if ( ++v2 >= nControls )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Controls,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BBD0
// Name: public: class CDmElement __near * CDmeControlGroup::FindControlByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeControlGroup::FindControlByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmElement *result; // eax
  int nControls; // [esp+Ch] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
  {
LABEL_8:
    if ( recursive && (v9 = 0, (nChildren = this->m_Children.m_Storage.m_Size) > 0) )
    {
      while ( 1 )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v9]);
        v11 = (CDmeControlGroup *)v10;
        if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindControlByName(this: v11, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v9 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
      {
        m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pParentName;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v5 >= nControls )
        goto LABEL_8;
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052BCD0
// Name: public: bool CDmeControlGroup::RemoveChild(class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveChild(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  int v2; // edi
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // ebx
  CDmElement *v4; // eax
  const CDmeControlGroup *v5; // esi
  int nChildren; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return 0;
  p_m_Children = &this->m_Children;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmeControlGroup *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      v5 = nullptr;
    if ( v5 == pGroup )
      break;
    if ( ++v2 >= nChildren )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Children,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BD50
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindChildByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindChildByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int m_Size; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  int v10; // edi
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  CDmeControlGroup *result; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Children.m_Storage.m_Size;
  v6 = 0;
  nChildren = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    if ( recursive && (v10 = 0, m_Size > 0) )
    {
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v10]);
        v12 = (CDmeControlGroup *)v11;
        if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindChildByName(this: v12, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v10 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pParentName;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v6 >= nChildren )
      {
        m_Size = nChildren;
        goto LABEL_9;
      }
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmeControlGroup *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052BE50
// Name: private: static void CDmeControlGroup::DestroyGroup_R(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup_R(int pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CExpressionCalculator *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int v7; // edi
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // esi
  IDataModel_vtbl *v10; // esi
  int v11; // eax
  int nControls; // [esp+Ch] [ebp-8h]
  int nChildren; // [esp+10h] [ebp-4h]
  CDmaElementArray<CDmElement> *nChildrena; // [esp+10h] [ebp-4h]

  v3 = (CExpressionCalculator *)pGroup;
  if ( pGroup != 0 && (pRecipient != nullptr || *(int *)(pGroup + 108) <= 0 && *(int *)(pGroup + 80) <= 0) )
  {
    v4 = 0;
    nChildren = *(_DWORD *)(pGroup + 80);
    if ( nChildren > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v3->m_stack.m_Size + 4 * v4));
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
        {
          if ( recursive )
          {
            CDmeControlGroup::DestroyGroup_R(pGroup: v6, pRecipient, recursive: true);
          }
          else
          {
            pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &pRecipient->m_Children,
              src: (DmElementHandle_t *)&pGroup);
          }
        }
        ++v4;
      }
      while ( v4 < nChildren );
    }
    v7 = 0;
    nControls = v3[1].m_varNames.m_Size;
    if ( nControls > 0 )
    {
      nChildrena = &pRecipient->m_Controls;
      do
      {
        v8 = g_pDataModel->GetElement(
               this: g_pDataModel,
               a2: *((_DWORD *)&v3[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v7));
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          pGroup = CExpressionCalculator::VariableCount(this: v9);
        else
          pGroup = -1;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: nChildrena,
          src: (DmElementHandle_t *)&pGroup);
        ++v7;
      }
      while ( v7 < nControls );
    }
    v10 = g_pDataModel->__vftable;
    v11 = CExpressionCalculator::VariableCount(this: v3);
    v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BF90
// Name: public: void CDmeControlGroup::SetGroupColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetGroupColor(CDmeControlGroup *this, const Color *groupColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_GroupColor.m_pAttribute, value: groupColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetGroupColor(this: v9, groupColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C050
// Name: public: void CDmeControlGroup::SetControlColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetControlColor(CDmeControlGroup *this, const Color *controlColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_ControlColor.m_pAttribute, value: controlColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetControlColor(this: v9, controlColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C110
// Name: public: void CDmeControlGroup::AddChild(class CDmeControlGroup __near *,class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddChild(
        CDmeControlGroup *this,
        int pGroup,
        CExpressionCalculator *pInsertBeforeGroup)
{
  CDmeControlGroup *v3; // ebx
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  int v7; // edi

  v3 = (CDmeControlGroup *)pGroup;
  if ( (CDmeControlGroup *)pGroup != this )
  {
    if ( (_S1_4 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_4 |= 1u;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&dword_5EA974, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)dword_5EA974,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveChild(this: Referring, pGroup: v3);
    if ( pInsertBeforeGroup == nullptr
      || (pGroup = CExpressionCalculator::VariableCount(this: pInsertBeforeGroup),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: &this->m_Children,
                  value: (const DmElementHandle_t *)&pGroup)) == -1) )
    {
      if ( v3 != nullptr )
        pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        src: (DmElementHandle_t *)&pGroup);
    }
    else
    {
      if ( v3 != nullptr )
        pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Children,
        elem: v7,
        src: (const DmElementHandle_t *)&pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C210
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::CreateControlGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CreateControlGroup(CDmeControlGroup *this, const char *pchName)
{
  CDmeControlGroup *result; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  int v6; // esi

  result = CDmeControlGroup::FindChildByName(this, pchName, recursive: false, pParentGroup: nullptr);
  if ( result == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id,
           a3: pchName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (int)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
      v6 = 0;
    CDmeControlGroup::AddChild(this, pGroup: v6, pInsertBeforeGroup: nullptr);
    return (CDmeControlGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052C290
// Name: public: static void CDmeControlGroup::DestroyGroup(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup(CDmeControlGroup *pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CDmeControlGroup *v5; // esi
  CDmeControlGroup *v6; // eax

  if ( pGroup != nullptr )
  {
    if ( (_S1_4 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_4 |= 1u;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&dword_5EA974, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: pGroup,
                  symAttrName: (CUtlSymbolLarge)dword_5EA974,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v5 = Referring;
    if ( Referring != nullptr )
    {
      CDmeControlGroup::RemoveChild(this: Referring, pGroup);
      v6 = pRecipient;
      if ( pRecipient == nullptr )
      {
        CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v5, recursive);
        return;
      }
    }
    else
    {
      v6 = pRecipient;
    }
    CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v6, recursive);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C320
// Name: public: void CDmeControlGroup::AddControl(class CDmElement __near *,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddControl(
        CDmeControlGroup *this,
        CDmElement *pControl,
        CExpressionCalculator *pInsertBeforeControl)
{
  CDmElement *v3; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeControlGroup *Referring; // eax
  int v7; // ebx

  v3 = pControl;
  if ( pControl != nullptr )
  {
    v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pControl, a3: "controls");
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveControl(this: Referring, pControl: v3);
    if ( pInsertBeforeControl == nullptr
      || (pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: pInsertBeforeControl),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: &this->m_Controls,
                  value: (const DmElementHandle_t *)&pControl)) == -1) )
    {
      pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Controls,
        src: (DmElementHandle_t *)&pControl);
    }
    else
    {
      pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Controls,
        elem: v7,
        src: (const DmElementHandle_t *)&pControl);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C3D0
// Name: private: static bool CDmeControlGroup::DestroyEmptyChildren_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmeControlGroup::DestroyEmptyChildren_R(CDmeControlGroup *pGroup)
{
  int m_Size; // edi
  int v2; // esi
  CDmeControlGroup **m_pMemory; // ebx
  CDmElement *v4; // eax
  CDmeControlGroup *v5; // edi
  int v6; // edi
  CDmeControlGroup **v7; // edi
  int i; // edi
  char result; // al
  CUtlVector<CDmeControlGroup *,CUtlMemory<CDmeControlGroup *,int> > childrenToDestroy; // [esp+Ch] [ebp-20h] BYREF
  int nNumChildren; // [esp+20h] [ebp-Ch]
  CDmElement *v12; // [esp+24h] [ebp-8h]
  int iChild; // [esp+28h] [ebp-4h]
  char pGroup_3; // [esp+37h] [ebp+Bh]

  m_Size = pGroup->m_Children.m_Storage.m_Size;
  v2 = 0;
  m_pMemory = nullptr;
  nNumChildren = m_Size;
  childrenToDestroy.m_Memory.m_pMemory = nullptr;
  childrenToDestroy.m_Memory.m_nAllocationCount = m_Size;
  childrenToDestroy.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
  {
    m_pMemory = (CDmeControlGroup **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    childrenToDestroy.m_Memory.m_pMemory = m_pMemory;
  }
  childrenToDestroy.m_Size = 0;
  childrenToDestroy.m_pElements = m_pMemory;
  iChild = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[iChild]);
      v5 = (CDmeControlGroup *)v4;
      v12 = v4;
      if ( v4 != nullptr
        && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType)
        && CDmeControlGroup::DestroyEmptyChildren_R(pGroup: v5) )
      {
        v6 = v2;
        if ( v2 + 1 > childrenToDestroy.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&childrenToDestroy,
            num: v2 - childrenToDestroy.m_Memory.m_nAllocationCount + 1);
          v2 = childrenToDestroy.m_Size;
          m_pMemory = childrenToDestroy.m_Memory.m_pMemory;
        }
        childrenToDestroy.m_Size = ++v2;
        childrenToDestroy.m_pElements = m_pMemory;
        if ( v2 - v6 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (v2 - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          *v7 = (CDmeControlGroup *)v12;
      }
      ++iChild;
    }
    while ( iChild < nNumChildren );
  }
  for ( i = 0; i < v2; ++i )
    CDmeControlGroup::RemoveChild(this: pGroup, pGroup: m_pMemory[i]);
  if ( pGroup->m_Children.m_Storage.m_Size != 0 || pGroup->m_Controls.m_Storage.m_Size != 0 )
  {
    pGroup_3 = 0;
    result = 0;
  }
  else
  {
    result = 1;
    pGroup_3 = 1;
  }
  if ( childrenToDestroy.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pGroup_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052C530
// Name: public: void CDmeControlGroup::DestroyEmptyChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::DestroyEmptyChildren(CDmeControlGroup *this)
{
  CDmeControlGroup::DestroyEmptyChildren_R(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x0052C5A0
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052C630
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C660
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C6A0
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CDA0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F1B0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0052BAC0
// Name: class CDmeControlGroup __near * FindReferringElement<class CDmeControlGroup>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindReferringElement<CDmeControlGroup>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeControlGroup *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057CDD0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CDE0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F1C0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E9A90
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x005E9BC0
// Name: public: bool CDmeControlGroup::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsEmpty(CDmeControlGroup *this)
{
  return this->m_Controls.m_Storage.m_Size <= 0 && this->m_Children.m_Storage.m_Size <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E9C70
// Name: public: bool CDmeControlGroup::RemoveControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveControl(CDmeControlGroup *this, const CDmElement *pControl)
{
  int v2; // edi
  CDmaElementArray<CDmElement> *p_m_Controls; // ebx
  int v4; // eax
  const CDmElement *v5; // esi
  int nControls; // [esp+Ch] [ebp-4h]

  if ( pControl == nullptr )
    return 0;
  v2 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
    return 0;
  p_m_Controls = &this->m_Controls;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: p_m_Controls->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmElement *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( pControl == v5 )
      break;
    if ( ++v2 >= nControls )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Controls,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9CF0
// Name: public: class CDmElement __near * CDmeControlGroup::FindControlByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeControlGroup::FindControlByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int v5; // edi
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  int v9; // edi
  int v10; // eax
  CDmeControlGroup *v11; // esi
  CDmElement *result; // eax
  int nControls; // [esp+Ch] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
  {
LABEL_8:
    if ( recursive && (v9 = 0, (nChildren = this->m_Children.m_Storage.m_Size) > 0) )
    {
      while ( 1 )
      {
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v9]);
        v11 = (CDmeControlGroup *)v10;
        if ( v10 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
               a1: v10,
               a2: CDmeControlGroup::m_classType.u) != 0 )
        {
          result = CDmeControlGroup::FindControlByName(this: v11, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v9 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmElement::m_classType.u) != 0 )
      {
        v8 = *(const char **)(v7 + 20);
        if ( v8 == (const char *)-1 )
          v8 = defaultValue;
        if ( _V_stricmp(s1: v8, s2: pchName) == 0 )
          break;
      }
      if ( ++v5 >= nControls )
        goto LABEL_8;
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmElement *)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E9DF0
// Name: public: bool CDmeControlGroup::RemoveChild(class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveChild(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  int v2; // edi
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // ebx
  int v4; // eax
  const CDmeControlGroup *v5; // esi
  int nChildren; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return 0;
  p_m_Children = &this->m_Children;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmeControlGroup *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeControlGroup::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( v5 == pGroup )
      break;
    if ( ++v2 >= nChildren )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Children,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9E70
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindChildByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindChildByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // edi
  int v11; // eax
  CDmeControlGroup *v12; // esi
  CDmeControlGroup *result; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Children.m_Storage.m_Size;
  v6 = 0;
  nChildren = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    if ( recursive && (v10 = 0, m_Size > 0) )
    {
      while ( 1 )
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v10]);
        v12 = (CDmeControlGroup *)v11;
        if ( v11 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmeControlGroup::m_classType.u) != 0 )
        {
          result = CDmeControlGroup::FindChildByName(this: v12, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v10 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeControlGroup::m_classType.u) != 0 )
      {
        v9 = *(const char **)(v8 + 20);
        if ( v9 == (const char *)-1 )
          v9 = defaultValue;
        if ( _V_stricmp(s1: v9, s2: pchName) == 0 )
          break;
      }
      if ( ++v6 >= nChildren )
      {
        m_Size = nChildren;
        goto LABEL_9;
      }
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmeControlGroup *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E9F70
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindParent(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindParent(CDmeControlGroup *this)
{
  void (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_9 & 1) == 0 )
  {
    v2 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_9 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_2,
      a3: "children");
  }
  return FindReferringElement<CDmeControlGroup>(
           pElement: this,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x005E9FC0
// Name: public: bool CDmeControlGroup::IsAncestorOfGroup(class CDmeControlGroup const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::IsAncestorOfGroup(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // esi
  CDmeControlGroup *v5; // edi
  void (__thiscall *v6)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *v7; // eax

  if ( pGroup == nullptr )
    return 0;
  if ( (_S1_9 & 1) == 0 )
  {
    v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_9 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_2,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: pGroup,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return 0;
  while ( Referring != this )
  {
    v5 = Referring;
    if ( (_S1_9 & 1) == 0 )
    {
      v6 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
      _S1_9 |= 1u;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v6)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: &symChildren_2,
        a3: "children");
    }
    v7 = FindReferringElement<CDmeControlGroup>(
           pElement: Referring,
           symAttrName: symChildren_2,
           bMustBeInSameFile: true,
           depth: TD_ALL);
    Referring = v7;
    if ( v5 == v7 || v7 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EA090
// Name: private: static void CDmeControlGroup::DestroyGroup_R(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup_R(int pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CExpressionCalculator *v3; // ebx
  int v4; // edi
  int v5; // eax
  CDmeControlGroup *v6; // esi
  int v7; // edi
  int v8; // eax
  CExpressionCalculator *v9; // esi
  int v10; // esi
  int BufferType; // eax
  int nControls; // [esp+Ch] [ebp-8h]
  int nChildren; // [esp+10h] [ebp-4h]
  CDmaElementArray<CDmElement> *nChildrena; // [esp+10h] [ebp-4h]

  v3 = (CExpressionCalculator *)pGroup;
  if ( pGroup != 0 && (pRecipient != nullptr || *(int *)(pGroup + 108) <= 0 && *(int *)(pGroup + 80) <= 0) )
  {
    v4 = 0;
    nChildren = *(_DWORD *)(pGroup + 80);
    if ( nChildren > 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *(_DWORD *)(v3->m_stack.m_Size + 4 * v4));
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeControlGroup::m_classType.u) != 0 )
        {
          if ( recursive )
          {
            CDmeControlGroup::DestroyGroup_R(pGroup: v6, pRecipient, recursive: true);
          }
          else
          {
            pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &pRecipient->m_Children,
              src: (const DmElementHandle_t *)&pGroup);
          }
        }
        ++v4;
      }
      while ( v4 < nChildren );
    }
    v7 = 0;
    nControls = v3[1].m_varNames.m_Size;
    if ( nControls > 0 )
    {
      nChildrena = &pRecipient->m_Controls;
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: *((_DWORD *)&v3[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v7));
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmElement::m_classType.u) != 0 )
        {
          pGroup = CCodecBuffer_Block::GetBufferType(this: v9);
        }
        else
        {
          pGroup = -1;
        }
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: nChildrena,
          src: (const DmElementHandle_t *)&pGroup);
        ++v7;
      }
      while ( v7 < nControls );
    }
    v10 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: v3);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v10 + 68))(a1: g_pDataModel.u, a2: BufferType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA1D0
// Name: public: void CDmeControlGroup::SetGroupColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetGroupColor(CDmeControlGroup *this, const Color *groupColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  int v6; // eax
  int v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_GroupColor.m_pAttribute, value: groupColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeControlGroup::m_classType.u) != 0 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeControlGroup::m_classType.u) != 0 )
        {
          v9 = v8;
        }
        else
        {
          v9 = nullptr;
        }
        CDmeControlGroup::SetGroupColor(this: v9, groupColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA290
// Name: public: bool CDmeControlGroup::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsVisible(CDmeControlGroup *this)
{
  void (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_9 & 1) == 0 )
  {
    v2 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_9 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_2,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Visible.m_Storage;
  result = CDmeControlGroup::IsVisible(this: Referring);
  if ( result )
    return this->m_Visible.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA2F0
// Name: public: bool CDmeControlGroup::IsSelectable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsSelectable(CDmeControlGroup *this)
{
  void (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  bool result; // al

  if ( (_S1_9 & 1) == 0 )
  {
    v2 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_9 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_2,
      a3: "children");
  }
  Referring = FindReferringElement<CDmeControlGroup>(
                pElement: this,
                symAttrName: symChildren_2,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring == nullptr )
    return this->m_Selectable.m_Storage;
  result = CDmeControlGroup::IsSelectable(this: Referring);
  if ( result )
    return this->m_Selectable.m_Storage;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA350
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindRootControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindRootControlGroup(CDmeControlGroup *this)
{
  void (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *i; // esi
  void (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // eax

  if ( (_S1_9 & 1) == 0 )
  {
    v2 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_9 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symChildren_2,
      a3: "children");
  }
  for ( i = FindReferringElement<CDmeControlGroup>(
              pElement: this,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL);
        i != nullptr;
        i = FindReferringElement<CDmeControlGroup>(
              pElement: i,
              symAttrName: symChildren_2,
              bMustBeInSameFile: true,
              depth: TD_ALL) )
  {
    this = i;
    if ( (_S1_9 & 1) == 0 )
    {
      v4 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
      _S1_9 |= 1u;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v4)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: &symChildren_2,
        a3: "children");
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005EA3F0
// Name: public: class CDmeAnimationSet __near * CDmeControlGroup::FindAnimationSet(bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationSet *__thiscall CDmeControlGroup::FindAnimationSet(CDmeControlGroup *this, bool bSearchAncestors)
{
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeAnimationSet *result; // eax
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // eax
  CDmeControlGroup *Referring; // eax

  if ( (_S2_3 & 1) == 0 )
  {
    v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S2_3 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symRootControlGroup,
      a3: "rootControlGroup");
  }
  if ( this == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = FindReferringElement<CDmeAnimationSet>(
               pElement: (CExpressionCalculator *)this,
               symAttrName: symRootControlGroup,
               bMustBeInSameFile: true,
               depth: TD_ALL);
    if ( result != nullptr )
      break;
    if ( bSearchAncestors )
    {
      if ( (_S1_9 & 1) == 0 )
      {
        v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
        _S1_9 |= 1u;
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v5)(
          a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
          a2: &symChildren_2,
          a3: "children");
      }
      Referring = FindReferringElement<CDmeControlGroup>(
                    pElement: this,
                    symAttrName: symChildren_2,
                    bMustBeInSameFile: true,
                    depth: TD_ALL);
      if ( this != Referring )
      {
        this = Referring;
        if ( Referring != nullptr )
          continue;
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA4A0
// Name: public: static class CDmeControlGroup __near * CDmeControlGroup::FindGroupContainingControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl CDmeControlGroup::FindGroupContainingControl(const CDmElement *pControl)
{
  CUtlSymbolLarge *v1; // eax
  _BYTE v3[4]; // [esp+0h] [ebp-4h] BYREF

  v1 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v3,
                            a3: "controls");
  return FindReferringElement<CDmeControlGroup>(
           pElement: pControl,
           symAttrName: (CUtlSymbolLarge)v1->u.m_Id,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x005EA4E0
// Name: public: void CDmeControlGroup::AddChild(class CDmeControlGroup __near *,class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddChild(
        CDmeControlGroup *this,
        int pGroup,
        CExpressionCalculator *pInsertBeforeGroup)
{
  CDmeControlGroup *v3; // ebx
  void (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  int v7; // edi

  v3 = (CDmeControlGroup *)pGroup;
  if ( (CDmeControlGroup *)pGroup != this )
  {
    if ( (_S1_9 & 1) == 0 )
    {
      v5 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
      _S1_9 |= 1u;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v5)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: &symChildren_2,
        a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveChild(this: Referring, pGroup: v3);
    if ( pInsertBeforeGroup == nullptr
      || (pGroup = CCodecBuffer_Block::GetBufferType(this: pInsertBeforeGroup),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Children,
                  src: (vgui::PageTab **)&pGroup)) == -1) )
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        src: (const DmElementHandle_t *)&pGroup);
    }
    else
    {
      if ( v3 != nullptr )
        pGroup = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Children,
        elem: v7,
        src: (const DmElementHandle_t *)&pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA5E0
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::CreateControlGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CreateControlGroup(CDmeControlGroup *this, const char *pchName)
{
  CDmeControlGroup *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi

  result = CDmeControlGroup::FindChildByName(this, pchName, recursive: false, pParentGroup: nullptr);
  if ( result == nullptr )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeControlGroup::m_classType.u,
           a3: pchName,
           a4: this->m_fileId,
           a5: 0);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v4);
    v6 = v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeControlGroup::m_classType.u) == 0 )
    {
      v6 = 0;
    }
    CDmeControlGroup::AddChild(this, pGroup: v6, pInsertBeforeGroup: nullptr);
    return (CDmeControlGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA660
// Name: public: static void CDmeControlGroup::DestroyGroup(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup(CDmeControlGroup *pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CDmeControlGroup *v5; // esi
  CDmeControlGroup *v6; // eax

  if ( pGroup != nullptr )
  {
    if ( (_S1_9 & 1) == 0 )
    {
      v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
      _S1_9 |= 1u;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: &symChildren_2,
        a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: pGroup,
                  symAttrName: symChildren_2,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v5 = Referring;
    if ( Referring != nullptr )
    {
      CDmeControlGroup::RemoveChild(this: Referring, pGroup);
      v6 = pRecipient;
      if ( pRecipient == nullptr )
      {
        CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v5, recursive);
        return;
      }
    }
    else
    {
      v6 = pRecipient;
    }
    CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v6, recursive);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA6F0
// Name: public: void CDmeControlGroup::AddControl(class CDmElement __near *,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddControl(
        CDmeControlGroup *this,
        CDmElement *pControl,
        CExpressionCalculator *pInsertBeforeControl)
{
  CDmElement *v3; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeControlGroup *Referring; // eax
  int v7; // ebx

  v3 = pControl;
  if ( pControl != nullptr )
  {
    v5 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                              a1: g_pDataModel.u,
                              a2: &pControl,
                              a3: "controls");
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveControl(this: Referring, pControl: v3);
    if ( pInsertBeforeControl == nullptr
      || (pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: pInsertBeforeControl),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)&this->m_Controls,
                  src: (vgui::PageTab **)&pControl)) == -1) )
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Controls,
        src: (const DmElementHandle_t *)&pControl);
    }
    else
    {
      pControl = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Controls,
        elem: v7,
        src: (const DmElementHandle_t *)&pControl);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA7A0
// Name: public: void CDmeControlGroup::GetAllChildren(class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetAllChildren(
        CDmeControlGroup *this,
        CUtlMemory<vgui::TreeNode *,int> *childGroupList)
{
  int v2; // edi
  int v4; // eax
  CExpressionCalculator *v5; // ebx
  int BufferType; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *v9; // ecx
  int v10; // eax
  DmElementHandle_t *v11; // edi
  int nChildren; // [esp+Ch] [ebp-Ch]
  CDmeControlGroup *v13; // [esp+10h] [ebp-8h]
  int iChild; // [esp+14h] [ebp-4h]
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *childGroupLista; // [esp+20h] [ebp+8h]

  v2 = 0;
  v13 = this;
  nChildren = this->m_Children.m_Storage.m_Size;
  iChild = 0;
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CExpressionCalculator *)v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeControlGroup::m_classType.u) != 0 )
      {
        BufferType = CCodecBuffer_Block::GetBufferType(this: v5);
        m_pMemory = (int)childGroupList[1].m_pMemory;
        childGroupLista = (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)BufferType;
        m_nAllocationCount = childGroupList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: childGroupList, num: m_pMemory - m_nAllocationCount + 1);
        ++childGroupList[1].m_pMemory;
        v9 = (DmElementHandle_t *)childGroupList->m_pMemory;
        v10 = (int)childGroupList[1].m_pMemory - m_pMemory - 1;
        childGroupList[1].m_nAllocationCount = (int)childGroupList->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
        v11 = (DmElementHandle_t *)&childGroupList->m_pMemory[m_pMemory];
        if ( v11 != nullptr )
          *v11 = (DmElementHandle_t)childGroupLista;
        CDmeControlGroup::GetAllChildren(
          this: (CDmeControlGroup *)v5,
          (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)childGroupList);
        v2 = iChild;
      }
      iChild = ++v2;
      if ( v2 >= nChildren )
        break;
      this = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EA880
// Name: private: static bool CDmeControlGroup::DestroyEmptyChildren_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmeControlGroup::DestroyEmptyChildren_R(CDmeControlGroup *pGroup)
{
  int m_Size; // edi
  int v2; // esi
  CDmeControlGroup **m_pMemory; // ebx
  int v4; // eax
  CDmeControlGroup *v5; // edi
  int v6; // edi
  CDmeControlGroup **v7; // edi
  int i; // edi
  char result; // al
  CUtlVector<CDmeControlGroup *,CUtlMemory<CDmeControlGroup *,int> > childrenToDestroy; // [esp+Ch] [ebp-20h] BYREF
  int nNumChildren; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h]
  int iChild; // [esp+28h] [ebp-4h]
  char pGroup_3; // [esp+37h] [ebp+Bh]

  m_Size = pGroup->m_Children.m_Storage.m_Size;
  v2 = 0;
  m_pMemory = nullptr;
  nNumChildren = m_Size;
  childrenToDestroy.m_Memory.m_pMemory = nullptr;
  childrenToDestroy.m_Memory.m_nAllocationCount = m_Size;
  childrenToDestroy.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
  {
    m_pMemory = (CDmeControlGroup **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    childrenToDestroy.m_Memory.m_pMemory = m_pMemory;
  }
  childrenToDestroy.m_Size = 0;
  childrenToDestroy.m_pElements = m_pMemory;
  iChild = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[iChild]);
      v5 = (CDmeControlGroup *)v4;
      v12 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeControlGroup::m_classType.u) != 0
        && CDmeControlGroup::DestroyEmptyChildren_R(pGroup: v5) )
      {
        v6 = v2;
        if ( v2 + 1 > childrenToDestroy.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&childrenToDestroy,
            num: v2 - childrenToDestroy.m_Memory.m_nAllocationCount + 1);
          v2 = childrenToDestroy.m_Size;
          m_pMemory = childrenToDestroy.m_Memory.m_pMemory;
        }
        childrenToDestroy.m_Size = ++v2;
        childrenToDestroy.m_pElements = m_pMemory;
        if ( v2 - v6 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (v2 - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          *v7 = (CDmeControlGroup *)v12;
      }
      ++iChild;
    }
    while ( iChild < nNumChildren );
  }
  for ( i = 0; i < v2; ++i )
    CDmeControlGroup::RemoveChild(this: pGroup, pGroup: m_pMemory[i]);
  if ( pGroup->m_Children.m_Storage.m_Size != 0 || pGroup->m_Controls.m_Storage.m_Size != 0 )
  {
    pGroup_3 = 0;
    result = 0;
  }
  else
  {
    result = 1;
    pGroup_3 = 1;
  }
  if ( childrenToDestroy.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pGroup_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005EA9E0
// Name: public: void CDmeControlGroup::DestroyEmptyChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::DestroyEmptyChildren(CDmeControlGroup *this)
{
  CDmeControlGroup::DestroyEmptyChildren_R(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x005EA9F0
// Name: public: void CDmeControlGroup::GetControlsInGroup(class CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>> __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::GetControlsInGroup(
        CDmeControlGroup *this,
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *controlList,
        bool recursive)
{
  int v4; // ebx
  int v5; // eax
  CDmeControlGroup *v6; // edi
  int v7; // eax
  int v8; // eax
  CDmElement *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmElement **m_pMemory; // ecx
  int v13; // eax
  CDmElement **v14; // edi
  int nControls; // [esp+18h] [ebp+8h]
  int iControl; // [esp+1Ch] [ebp+Ch]
  int iControla; // [esp+1Ch] [ebp+Ch]

  if ( recursive )
  {
    v4 = 0;
    iControl = this->m_Children.m_Storage.m_Size;
    if ( iControl > 0 )
    {
      do
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeControlGroup::m_classType.u) != 0 )
        {
          CDmeControlGroup::GetControlsInGroup(this: v6, controlList, recursive: true);
        }
        ++v4;
      }
      while ( v4 < iControl );
    }
  }
  v7 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  iControla = 0;
  if ( nControls > 0 )
  {
    do
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v7]);
      v9 = (CDmElement *)v8;
      if ( v8 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) != 0 )
      {
        m_Size = controlList->m_Size;
        m_nAllocationCount = controlList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)controlList,
            num: m_Size - m_nAllocationCount + 1);
        ++controlList->m_Size;
        m_pMemory = controlList->m_Memory.m_pMemory;
        v13 = controlList->m_Size - m_Size - 1;
        controlList->m_pElements = controlList->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
        v14 = &controlList->m_Memory.m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = v9;
      }
      v7 = iControla + 1;
      iControla = v7;
    }
    while ( v7 < nControls );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005EAB70
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005EAC00
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EAC30
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EAC70
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1EF0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B59A0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E9BE0
// Name: class CDmeControlGroup __near * FindReferringElement<class CDmeControlGroup>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindReferringElement<CDmeControlGroup>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeControlGroup *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B1F20
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1F30
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B59B0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0052CA70
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x0052CBA0
// Name: public: void CDmeControlGroup::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetVisible(CDmeControlGroup *this, bool bVisible)
{
  CDmAttribute::SetValue<bool>(this: this->m_Visible.m_pAttribute, value: &bVisible);
}

//------------------------------------------------------------------------------
// Address: 0x0052CBC0
// Name: public: void CDmeControlGroup::SetSelectable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetSelectable(CDmeControlGroup *this, bool bSelectable)
{
  CDmAttribute::SetValue<bool>(this: this->m_Selectable.m_pAttribute, value: &bSelectable);
}

//------------------------------------------------------------------------------
// Address: 0x0052CBE0
// Name: public: void CDmeControlGroup::SetSnappable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetSnappable(CDmeControlGroup *this, bool bSnappable)
{
  CDmAttribute::SetValue<bool>(this: this->m_Snappable.m_pAttribute, value: &bSnappable);
}

//------------------------------------------------------------------------------
// Address: 0x0052CC00
// Name: public: bool CDmeControlGroup::IsEmpty(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsEmpty(CDmeControlGroup *this)
{
  return this->m_Controls.m_Storage.m_Size <= 0 && this->m_Children.m_Storage.m_Size <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0052CCB0
// Name: public: bool CDmeControlGroup::RemoveControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveControl(CDmeControlGroup *this, const CDmElement *pControl)
{
  int v2; // edi
  CDmaElementArray<CDmElement> *p_m_Controls; // ebx
  CDmElement *v4; // eax
  const CDmElement *v5; // esi
  int nControls; // [esp+Ch] [ebp-4h]

  if ( pControl == nullptr )
    return 0;
  v2 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
    return 0;
  p_m_Controls = &this->m_Controls;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Controls->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
      v5 = nullptr;
    if ( pControl == v5 )
      break;
    if ( ++v2 >= nControls )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Controls,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CD30
// Name: public: class CDmElement __near * CDmeControlGroup::FindControlByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeControlGroup::FindControlByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  int v9; // edi
  CDmElement *v10; // eax
  CDmeControlGroup *v11; // esi
  CDmElement *result; // eax
  int nControls; // [esp+Ch] [ebp-4h]
  int nChildren; // [esp+1Ch] [ebp+Ch]

  v5 = 0;
  nControls = this->m_Controls.m_Storage.m_Size;
  if ( nControls <= 0 )
  {
LABEL_8:
    if ( recursive && (v9 = 0, (nChildren = this->m_Children.m_Storage.m_Size) > 0) )
    {
      while ( 1 )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v9]);
        v11 = (CDmeControlGroup *)v10;
        if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindControlByName(this: v11, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v9 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Controls.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmElement::m_classType) )
      {
        m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pch;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v5 >= nControls )
        goto LABEL_8;
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052CE30
// Name: public: bool CDmeControlGroup::RemoveChild(class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeControlGroup::RemoveChild(CDmeControlGroup *this, const CDmeControlGroup *pGroup)
{
  int v2; // edi
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // ebx
  CDmElement *v4; // eax
  const CDmeControlGroup *v5; // esi
  int nChildren; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nChildren = this->m_Children.m_Storage.m_Size;
  if ( nChildren <= 0 )
    return 0;
  p_m_Children = &this->m_Children;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Children->m_Storage.m_Memory.m_pMemory[v2]);
    v5 = (const CDmeControlGroup *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeControlGroup::m_classType) )
      v5 = nullptr;
    if ( v5 == pGroup )
      break;
    if ( ++v2 >= nChildren )
      return 0;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
    this: p_m_Children,
    elem: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052CEB0
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::FindChildByName(char const __near *,bool,class CDmeControlGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::FindChildByName(
        CDmeControlGroup *this,
        const char *pchName,
        bool recursive,
        CDmeControlGroup **pParentGroup)
{
  int m_Size; // eax
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  int v10; // edi
  CDmElement *v11; // eax
  CDmeControlGroup *v12; // esi
  CDmeControlGroup *result; // eax
  int nChildren; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Children.m_Storage.m_Size;
  v6 = 0;
  nChildren = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_9:
    if ( recursive && (v10 = 0, m_Size > 0) )
    {
      while ( 1 )
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v10]);
        v12 = (CDmeControlGroup *)v11;
        if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeControlGroup::m_classType) )
        {
          result = CDmeControlGroup::FindChildByName(this: v12, pchName, recursive: true, pParentGroup);
          if ( result != nullptr )
            break;
        }
        if ( ++v10 >= nChildren )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v6]);
      v8 = v7;
      if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
      {
        m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pch;
        if ( _V_stricmp(s1: m_pAsString, s2: pchName) == 0 )
          break;
      }
      if ( ++v6 >= nChildren )
      {
        m_Size = nChildren;
        goto LABEL_9;
      }
    }
    if ( pParentGroup != nullptr )
      *pParentGroup = this;
    return (CDmeControlGroup *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052CFB0
// Name: private: static void CDmeControlGroup::DestroyGroup_R(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup_R(int pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CExpressionCalculator *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CDmeControlGroup *v6; // esi
  int v7; // edi
  CDmElement *v8; // eax
  CExpressionCalculator *v9; // esi
  IDataModel_vtbl *v10; // esi
  int v11; // eax
  int nControls; // [esp+Ch] [ebp-8h]
  int nChildren; // [esp+10h] [ebp-4h]
  CDmaElementArray<CDmElement> *nChildrena; // [esp+10h] [ebp-4h]

  v3 = (CExpressionCalculator *)pGroup;
  if ( pGroup != 0 && (pRecipient != nullptr || *(int *)(pGroup + 108) <= 0 && *(int *)(pGroup + 80) <= 0) )
  {
    v4 = 0;
    nChildren = *(_DWORD *)(pGroup + 80);
    if ( nChildren > 0 )
    {
      do
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v3->m_stack.m_Size + 4 * v4));
        v6 = (CDmeControlGroup *)v5;
        if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
        {
          if ( recursive )
          {
            CDmeControlGroup::DestroyGroup_R(pGroup: v6, pRecipient, recursive: true);
          }
          else
          {
            pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
              this: &pRecipient->m_Children,
              src: (const DmElementHandle_t *)&pGroup);
          }
        }
        ++v4;
      }
      while ( v4 < nChildren );
    }
    v7 = 0;
    nControls = v3[1].m_varNames.m_Size;
    if ( nControls > 0 )
    {
      nChildrena = &pRecipient->m_Controls;
      do
      {
        v8 = g_pDataModel->GetElement(
               this: g_pDataModel,
               a2: *((_DWORD *)&v3[1].m_varNames.m_Memory.m_pMemory->m_Storage.m_Memory.m_pMemory + v7));
        v9 = (CExpressionCalculator *)v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          pGroup = CExpressionCalculator::VariableCount(this: v9);
        else
          pGroup = -1;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: nChildrena,
          src: (const DmElementHandle_t *)&pGroup);
        ++v7;
      }
      while ( v7 < nControls );
    }
    v10 = g_pDataModel->__vftable;
    v11 = CExpressionCalculator::VariableCount(this: v3);
    v10->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D0F0
// Name: public: void CDmeControlGroup::SetGroupColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetGroupColor(CDmeControlGroup *this, const Color *groupColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_GroupColor.m_pAttribute, value: groupColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetGroupColor(this: v9, groupColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D1B0
// Name: public: void CDmeControlGroup::SetControlColor(class Color const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::SetControlColor(CDmeControlGroup *this, const Color *controlColor, bool bRecursive)
{
  int m_Size; // esi
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // eax
  CDmeControlGroup *v8; // esi
  CDmeControlGroup *v9; // ecx
  int nChildren; // [esp+18h] [ebp+Ch]

  CDmAttribute::SetValue<Color>(this: this->m_ControlColor.m_pAttribute, value: controlColor);
  if ( bRecursive )
  {
    m_Size = this->m_Children.m_Storage.m_Size;
    v5 = 0;
    for ( nChildren = m_Size; v5 < m_Size; ++v5 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeControlGroup::m_classType) )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Children.m_Storage.m_Memory.m_pMemory[v5]);
        v8 = (CDmeControlGroup *)v7;
        if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeControlGroup::m_classType) )
          v9 = v8;
        else
          v9 = nullptr;
        CDmeControlGroup::SetControlColor(this: v9, controlColor, bRecursive: true);
        m_Size = nChildren;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D270
// Name: public: void CDmeControlGroup::AddChild(class CDmeControlGroup __near *,class CDmeControlGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddChild(
        CDmeControlGroup *this,
        int pGroup,
        CExpressionCalculator *pInsertBeforeGroup)
{
  CDmeControlGroup *v3; // ebx
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  int v7; // edi

  v3 = (CDmeControlGroup *)pGroup;
  if ( (CDmeControlGroup *)pGroup != this )
  {
    if ( (_S1_4 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_4 |= 1u;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&dword_5ECA54, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)dword_5ECA54,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveChild(this: Referring, pGroup: v3);
    if ( pInsertBeforeGroup == nullptr
      || (pGroup = CExpressionCalculator::VariableCount(this: pInsertBeforeGroup),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: &this->m_Children,
                  value: (const DmElementHandle_t *)&pGroup)) == -1) )
    {
      if ( v3 != nullptr )
        pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Children,
        src: (const DmElementHandle_t *)&pGroup);
    }
    else
    {
      if ( v3 != nullptr )
        pGroup = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      else
        pGroup = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Children,
        elem: v7,
        src: (const DmElementHandle_t *)&pGroup);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D370
// Name: public: class CDmeControlGroup __near * CDmeControlGroup::CreateControlGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CreateControlGroup(CDmeControlGroup *this, const char *pchName)
{
  CDmeControlGroup *result; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  int v6; // esi

  result = CDmeControlGroup::FindChildByName(this, pchName, recursive: false, pParentGroup: nullptr);
  if ( result == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeControlGroup::m_classType.u.m_Id,
           a3: pchName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (int)v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeControlGroup::m_classType) )
      v6 = 0;
    CDmeControlGroup::AddChild(this, pGroup: v6, pInsertBeforeGroup: nullptr);
    return (CDmeControlGroup *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D3F0
// Name: public: static void CDmeControlGroup::DestroyGroup(class CDmeControlGroup __near *,class CDmeControlGroup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDmeControlGroup::DestroyGroup(CDmeControlGroup *pGroup, CDmeControlGroup *pRecipient, bool recursive)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  CDmeControlGroup *Referring; // eax
  CDmeControlGroup *v5; // esi
  CDmeControlGroup *v6; // eax

  if ( pGroup != nullptr )
  {
    if ( (_S1_4 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S1_4 |= 1u;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&dword_5ECA54, a3: "children");
    }
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: pGroup,
                  symAttrName: (CUtlSymbolLarge)dword_5ECA54,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    v5 = Referring;
    if ( Referring != nullptr )
    {
      CDmeControlGroup::RemoveChild(this: Referring, pGroup);
      v6 = pRecipient;
      if ( pRecipient == nullptr )
      {
        CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v5, recursive);
        return;
      }
    }
    else
    {
      v6 = pRecipient;
    }
    CDmeControlGroup::DestroyGroup_R((int)pGroup, pRecipient: v6, recursive);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D480
// Name: public: void CDmeControlGroup::AddControl(class CDmElement __near *,class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::AddControl(
        CDmeControlGroup *this,
        CDmElement *pControl,
        CExpressionCalculator *pInsertBeforeControl)
{
  CDmElement *v3; // esi
  CUtlSymbolLarge *v5; // eax
  CDmeControlGroup *Referring; // eax
  int v7; // ebx

  v3 = pControl;
  if ( pControl != nullptr )
  {
    v5 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pControl, a3: "controls");
    Referring = FindReferringElement<CDmeControlGroup>(
                  pElement: v3,
                  symAttrName: (CUtlSymbolLarge)v5->u.m_Id,
                  bMustBeInSameFile: true,
                  depth: TD_ALL);
    if ( Referring != nullptr )
      CDmeControlGroup::RemoveControl(this: Referring, pControl: v3);
    if ( pInsertBeforeControl == nullptr
      || (pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: pInsertBeforeControl),
          (v7 = CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Find(
                  this: &this->m_Controls,
                  value: (const DmElementHandle_t *)&pControl)) == -1) )
    {
      pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Controls,
        src: (const DmElementHandle_t *)&pControl);
    }
    else
    {
      pControl = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v3);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::InsertBefore(
        this: &this->m_Controls,
        elem: v7,
        src: (const DmElementHandle_t *)&pControl);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D530
// Name: private: static bool CDmeControlGroup::DestroyEmptyChildren_R(class CDmeControlGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDmeControlGroup::DestroyEmptyChildren_R(CDmeControlGroup *pGroup)
{
  int m_Size; // edi
  int v2; // esi
  CDmeControlGroup **m_pMemory; // ebx
  CDmElement *v4; // eax
  CDmeControlGroup *v5; // edi
  int v6; // edi
  CDmeControlGroup **v7; // edi
  int i; // edi
  char result; // al
  CUtlVector<CDmeControlGroup *,CUtlMemory<CDmeControlGroup *,int> > childrenToDestroy; // [esp+Ch] [ebp-20h] BYREF
  int nNumChildren; // [esp+20h] [ebp-Ch]
  CDmElement *v12; // [esp+24h] [ebp-8h]
  int iChild; // [esp+28h] [ebp-4h]
  char pGroup_3; // [esp+37h] [ebp+Bh]

  m_Size = pGroup->m_Children.m_Storage.m_Size;
  v2 = 0;
  m_pMemory = nullptr;
  nNumChildren = m_Size;
  childrenToDestroy.m_Memory.m_pMemory = nullptr;
  childrenToDestroy.m_Memory.m_nAllocationCount = m_Size;
  childrenToDestroy.m_Memory.m_nGrowSize = 0;
  if ( m_Size != 0 )
  {
    m_pMemory = (CDmeControlGroup **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    childrenToDestroy.m_Memory.m_pMemory = m_pMemory;
  }
  childrenToDestroy.m_Size = 0;
  childrenToDestroy.m_pElements = m_pMemory;
  iChild = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: pGroup->m_Children.m_Storage.m_Memory.m_pMemory[iChild]);
      v5 = (CDmeControlGroup *)v4;
      v12 = v4;
      if ( v4 != nullptr
        && v4->IsA(this: v4, a2: CDmeControlGroup::m_classType)
        && CDmeControlGroup::DestroyEmptyChildren_R(pGroup: v5) )
      {
        v6 = v2;
        if ( v2 + 1 > childrenToDestroy.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&childrenToDestroy,
            num: v2 - childrenToDestroy.m_Memory.m_nAllocationCount + 1);
          v2 = childrenToDestroy.m_Size;
          m_pMemory = childrenToDestroy.m_Memory.m_pMemory;
        }
        childrenToDestroy.m_Size = ++v2;
        childrenToDestroy.m_pElements = m_pMemory;
        if ( v2 - v6 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (v2 - v6 - 1));
        v7 = &m_pMemory[v6];
        if ( v7 != nullptr )
          *v7 = (CDmeControlGroup *)v12;
      }
      ++iChild;
    }
    while ( iChild < nNumChildren );
  }
  for ( i = 0; i < v2; ++i )
    CDmeControlGroup::RemoveChild(this: pGroup, pGroup: m_pMemory[i]);
  if ( pGroup->m_Children.m_Storage.m_Size != 0 || pGroup->m_Controls.m_Storage.m_Size != 0 )
  {
    pGroup_3 = 0;
    result = 0;
  }
  else
  {
    result = 1;
    pGroup_3 = 1;
  }
  if ( childrenToDestroy.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pGroup_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D690
// Name: public: void CDmeControlGroup::DestroyEmptyChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::DestroyEmptyChildren(CDmeControlGroup *this)
{
  CDmeControlGroup::DestroyEmptyChildren_R(pGroup: this);
}

//------------------------------------------------------------------------------
// Address: 0x0052D700
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052D790
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D7C0
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D800
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED70
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581190
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0052CC20
// Name: class CDmeControlGroup __near * FindReferringElement<class CDmeControlGroup>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *__cdecl FindReferringElement<CDmeControlGroup>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeControlGroup *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeControlGroup>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057EDA0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDB0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005811A0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005AD180
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x005AD310
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AD3A0
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD3D0
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD410
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EB140
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB90
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EB170
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB180
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBA0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00532C20
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x00532DB0
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00532E40
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532E70
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532EB0
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5C0
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E880
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5F0
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C600
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E890
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00635D30
// Name: protected: void CDmeControlGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::OnConstruction(CDmeControlGroup *this)
{
  CDmaElementArray<CDmeControlGroup> *p_m_Children; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  Color value; // [esp+Fh] [ebp-5h] BYREF
  bool v9; // [esp+13h] [ebp-1h] BYREF

  p_m_Children = &this->m_Children;
  this->m_Children.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "children",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Children);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Children->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  this->m_Controls.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "controls",
                                    type: AT_FIRST_ARRAY_TYPE,
                                    pMemory: &this->m_Controls);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Controls.m_pAttribute, typeSymbol: CDmElement::m_classType);
  value = (Color)-3618616;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "groupColor",
         type: AT_COLOR,
         pMemory: &this->m_GroupColor);
  this->m_GroupColor.m_pAttribute = v3;
  CDmAttribute::SetValue<Color>(this: v3, &value);
  value = (Color)-3618616;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "controlColor",
         type: AT_COLOR,
         pMemory: &this->m_ControlColor);
  this->m_ControlColor.m_pAttribute = v4;
  CDmAttribute::SetValue<Color>(this: v4, &value);
  v9 = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_Visible);
  this->m_Visible.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, value: &v9);
  v9 = true;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "selectable", type: AT_BOOL, pMemory: &this->m_Selectable);
  this->m_Selectable.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, value: &v9);
  v9 = true;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "snappable", type: AT_BOOL, pMemory: &this->m_Snappable);
  this->m_Snappable.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x00635EC0
// Name: protected: CDmeControlGroup::CDmeControlGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeControlGroup *__thiscall CDmeControlGroup::CDmeControlGroup(
        CDmeControlGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeControlGroup_vtbl *)&CDmeControlGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Controls);
  this->m_GroupColor.m_pAttribute = nullptr;
  this->m_GroupColor.m_Storage = (Color)-16777216;
  this->m_ControlColor.m_pAttribute = nullptr;
  this->m_ControlColor.m_Storage = (Color)-16777216;
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_Selectable.m_pAttribute = nullptr;
  this->m_Selectable.m_Storage = false;
  this->m_Snappable.m_pAttribute = nullptr;
  this->m_Snappable.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00635F50
// Name: public: virtual bool CDmeControlGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeControlGroup::IsA(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00635F80
// Name: public: virtual int CDmeControlGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeControlGroup::GetInheritanceDepth(CDmeControlGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeControlGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00635FC0
// Name: protected: virtual void CDmeControlGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeControlGroup::PerformConstruction(CDmeControlGroup *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeControlGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BA530
// Name: _dynamic_initializer_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeControlGroup::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeControlGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD6A0
// Name: _dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeControlGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeControlGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BA560
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeControlGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA570
// Name: _dynamic_initializer_for__g_CDmeControlGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeControlGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeControlGroup_Helper,
           classname: "DmeControlGroup",
           pFactory: &g_CDmeControlGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD6B0
// Name: _dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeControlGroup_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeControlGroup_Factory.m_CallBackList);
}

} // namespace vmap
