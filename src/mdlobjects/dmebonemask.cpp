// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebonemask.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmebonemask.h"

//------------------------------------------------------------------------------
// Address: 0x0049E650
// Name: public: float CDmeBoneMask::GetBoneWeight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmeBoneMask::GetBoneWeight(CDmeBoneMask *this, const char *pszBoneName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = 0;
  if ( this->m_BoneWeights.m_Storage.m_Size <= 0 )
    return 1.0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BoneWeights.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBoneWeight::m_classType.u) != 0 )
    {
      v6 = *(const char **)(v5 + 20);
      if ( v6 == (const char *)-1 )
        v6 = WindowName;
      if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= this->m_BoneWeights.m_Storage.m_Size )
      return 1.0;
  }
  return *(float *)(v5 + 68);
}

//------------------------------------------------------------------------------
// Address: 0x0049E730
// Name: public: virtual bool CDmeBoneMask::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMask::IsA(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E760
// Name: public: virtual int CDmeBoneMask::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMask::GetInheritanceDepth(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E7B0
// Name: protected: virtual void CDmeBoneMask::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMask::PerformConstruction(CDmeBoneMask *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_BoneWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "boneWeightList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BoneWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneWeights.m_pAttribute, typeSymbol: CDmeBoneWeight::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00598C40
// Name: _dynamic_initializer_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMask::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMask pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E120
// Name: _dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMask::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598C70
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMask_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598C80
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMask_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMask_Helper,
           classname: "DmeBoneMask",
           pFactory: &g_CDmeBoneMask_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E130
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMask_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E7140
// Name: public: float CDmeBoneMask::GetBoneWeight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmeBoneMask::GetBoneWeight(CDmeBoneMask *this, const char *pszBoneName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = 0;
  if ( this->m_BoneWeights.m_Storage.m_Size <= 0 )
    return 1.0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BoneWeights.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBoneWeight::m_classType.u) != 0 )
    {
      v6 = *(const char **)(v5 + 20);
      if ( v6 == (const char *)-1 )
        v6 = pDeltaStateName;
      if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= this->m_BoneWeights.m_Storage.m_Size )
      return 1.0;
  }
  return *(float *)(v5 + 68);
}

//------------------------------------------------------------------------------
// Address: 0x004E7220
// Name: public: virtual bool CDmeBoneMask::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMask::IsA(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7250
// Name: public: virtual int CDmeBoneMask::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMask::GetInheritanceDepth(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E72A0
// Name: protected: virtual void CDmeBoneMask::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMask::PerformConstruction(CDmeBoneMask *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_BoneWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "boneWeightList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BoneWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneWeights.m_pAttribute, typeSymbol: CDmeBoneWeight::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EDDC0
// Name: _dynamic_initializer_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMask::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMask pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F35D0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMask::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDDF0
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMask_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDE00
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMask_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMask_Helper,
           classname: "DmeBoneMask",
           pFactory: &g_CDmeBoneMask_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F35E0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMask_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E200
// Name: public: float CDmeBoneMask::GetBoneWeight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmeBoneMask::GetBoneWeight(CDmeBoneMask *this, const char *pszBoneName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = 0;
  if ( this->m_BoneWeights.m_Storage.m_Size <= 0 )
    return 1.0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BoneWeights.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBoneWeight::m_classType.u) != 0 )
    {
      v6 = *(const char **)(v5 + 20);
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= this->m_BoneWeights.m_Storage.m_Size )
      return 1.0;
  }
  return *(float *)(v5 + 68);
}

//------------------------------------------------------------------------------
// Address: 0x0050E2E0
// Name: public: virtual bool CDmeBoneMask::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMask::IsA(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E310
// Name: public: virtual int CDmeBoneMask::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMask::GetInheritanceDepth(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E360
// Name: protected: virtual void CDmeBoneMask::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMask::PerformConstruction(CDmeBoneMask *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_BoneWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "boneWeightList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BoneWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneWeights.m_pAttribute, typeSymbol: CDmeBoneWeight::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AD040
// Name: _dynamic_initializer_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMask::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMask pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3EF0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMask::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD070
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMask_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD080
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMask_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMask_Helper,
           classname: "DmeBoneMask",
           pFactory: &g_CDmeBoneMask_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F00
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneMask_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DDC70
// Name: public: float CDmeBoneMask::GetBoneWeight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDmeBoneMask::GetBoneWeight(CDmeBoneMask *this, const char *pszBoneName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = 0;
  if ( this->m_BoneWeights.m_Storage.m_Size <= 0 )
    return 1.0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BoneWeights.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBoneWeight::m_classType.u) != 0 )
    {
      v6 = *(const char **)(v5 + 20);
      if ( v6 == (const char *)-1 )
        v6 = pDeltaStateName;
      if ( _V_stricmp(s1: pszBoneName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= this->m_BoneWeights.m_Storage.m_Size )
      return 1.0;
  }
  return *(float *)(v5 + 68);
}

//------------------------------------------------------------------------------
// Address: 0x004DDD50
// Name: public: virtual bool CDmeBoneMask::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMask::IsA(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDD80
// Name: public: virtual int CDmeBoneMask::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMask::GetInheritanceDepth(CDmeBoneMask *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMask::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDDD0
// Name: protected: virtual void CDmeBoneMask::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMask::PerformConstruction(CDmeBoneMask *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_BoneWeights.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "boneWeightList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BoneWeights);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneWeights.m_pAttribute, typeSymbol: CDmeBoneWeight::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E6710
// Name: _dynamic_initializer_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMask::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMask pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2B0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMask::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMask::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6740
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMask_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6750
// Name: _dynamic_initializer_for__g_CDmeBoneMask_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMask_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMask_Helper,
           classname: "DmeBoneMask",
           pFactory: &g_CDmeBoneMask_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2C0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMask_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMask_Factory.m_CallBackList);
}

} // namespace studiomdl
