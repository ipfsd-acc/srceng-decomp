// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeanimationlist.cpp
// Functions: 16
// ============================================================

#include "movieobjects\dmeanimationlist.h"

//------------------------------------------------------------------------------
// Address: 0x00495220
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x004B4AB0
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4AE0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4B20
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  void *(__cdecl **v2)(const char *, int *); // [esp+0h] [ebp-8h]
  int v3; // [esp+4h] [ebp-4h]

  CDmeFXClip::OnDestruction(pFactoryList: v2, nFactoryCount: v3);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005AC340
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF460
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD40
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0E10
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x005AC370
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC380
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AF490
// Name: _dynamic_atexit_destructor_for__LuaFunc_s::m_dmxEdit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__LuaFunc_s::m_dmxEdit__()
{
  CDmxEdit::~CDmxEdit(this: &LuaFunc_s::m_dmxEdit);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4A0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CAppSystemGroup::~CAppSystemGroup(this: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4B0
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CAppSystemGroup::~CAppSystemGroup(this: &_s_ApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4C0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x005AF4D0
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFD50
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0050AB90
// Name: public: int CDmeAnimationList::FindAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::FindAnimation(CDmeAnimationList *this, const char *pAnimName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Animations.m_Storage.m_Size;
  if ( nCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Animations.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: pAnimName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0050AC80
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050ACB0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050ACF0
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005BB4E0
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x0067DA70
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682210
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067DAA0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067DAB0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682220
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104DB890
// Name: public: int CDmeAnimationList::FindAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::FindAnimation(CDmeAnimationList *this, const char *pAnimName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Animations.m_Storage.m_Size;
  if ( nCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Animations.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeChannelsClip::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: m_pAsString, s2: pAnimName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104DB980
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DB9B0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DB9F0
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x10594850
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x105C7500
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF40
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C7530
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7540
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF50
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004BD1C0
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD1F0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD230
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059B4A0
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EEF0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059B4D0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B4E0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EF00
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00501C60
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501C90
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00501CD0
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EF970
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3EE0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF9A0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF9B0
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3EF0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004666E0
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x00475E70
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475EA0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475EE0
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0056A650
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DA70
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E3F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F5B0
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x0056A680
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A690
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056DAA0
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E400
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F5C0
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00479B80
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00479BB0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00479C00
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x00479C10
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057A750
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DCD0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E520
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F780
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x0057A780
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A790
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD00
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD40
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD80
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E530
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00532FF0
// Name: public: int CDmeAnimationList::FindAnimation(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::FindAnimation(CDmeAnimationList *this, const char *pAnimName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Animations.m_Storage.m_Size;
  if ( nCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Animations.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = defaultValue;
    if ( _V_stricmp(s1: v6, s2: pAnimName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005330E0
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533110
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00533150
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AF330
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3360
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4AB0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B6010
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x006AF360
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AF370
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4AC0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0047A8F0
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A920
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A960
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0052BBF0
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x0057C740
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580500
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C770
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C780
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580510
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004FAC80
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FACB0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FACF0
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E8810
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECD80
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8840
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8850
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECD90
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00484A00
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00484A30
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00484A70
// Name: protected: virtual int CDmeAnimationList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x00484A80
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00579FF0
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D3A0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC10
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDE0
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x0057A020
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A030
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D3D0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057D410
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0057D450
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC20
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005876B0
// Name: public: virtual bool CDmeAnimationList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationList::IsA(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005876E0
// Name: public: virtual int CDmeAnimationList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationList::GetInheritanceDepth(CDmeAnimationList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00587720
// Name: protected: virtual void CDmeAnimationList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationList::PerformConstruction(CDmeAnimationList *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Animations.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animations",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Animations);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Animations.m_pAttribute, typeSymbol: CDmeChannelsClip::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006B7F00
// Name: _dynamic_initializer_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationList::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BCA10
// Name: _dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7F30
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7F40
// Name: _dynamic_initializer_for__g_CDmeAnimationList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationList_Helper,
           classname: "DmeAnimationList",
           pFactory: &g_CDmeAnimationList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BCA20
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationList_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAnimationList_Factory.m_CallBackList);
}

} // namespace vmap
