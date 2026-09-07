// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeassemblycommand.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeassemblycommand.h"

//------------------------------------------------------------------------------
// Address: 0x004A93E0
// Name: public: virtual bool CDmeAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssemblyCommand::IsA(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A9410
// Name: public: virtual int CDmeAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssemblyCommand::GetInheritanceDepth(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0059A440
// Name: _dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E920
// Name: _dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A470
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A480
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssemblyCommand_Helper,
           classname: "DmeAssemblyCommand",
           pFactory: &g_CDmeAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059A4A0
// Name: _dynamic_initializer_for__LOG_DME_AAC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DME_AAC__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DmeAnimationAssemblyCommand",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_102);
  LOG_DME_AAC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0059E930
// Name: _dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssemblyCommand_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EEBC0
// Name: public: virtual bool CDmeAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssemblyCommand::IsA(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EEBF0
// Name: public: virtual int CDmeAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssemblyCommand::GetInheritanceDepth(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005EEFC0
// Name: _dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3BD0
// Name: _dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EEFF0
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF000
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssemblyCommand_Helper,
           classname: "DmeAssemblyCommand",
           pFactory: &g_CDmeAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF020
// Name: _dynamic_initializer_for__LOG_DME_AAC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DME_AAC__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DmeAnimationAssemblyCommand",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_109);
  LOG_DME_AAC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F3BE0
// Name: _dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssemblyCommand_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00518E50
// Name: public: virtual bool CDmeAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssemblyCommand::IsA(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518E80
// Name: public: virtual int CDmeAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssemblyCommand::GetInheritanceDepth(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006AE840
// Name: _dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B46F0
// Name: _dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE870
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE880
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssemblyCommand_Helper,
           classname: "DmeAssemblyCommand",
           pFactory: &g_CDmeAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AE8A0
// Name: _dynamic_initializer_for__LOG_DME_AAC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DME_AAC__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DmeAnimationAssemblyCommand",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_166);
  LOG_DME_AAC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B4700
// Name: _dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAssemblyCommand_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E7CE0
// Name: public: virtual bool CDmeAssemblyCommand::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAssemblyCommand::IsA(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7D10
// Name: public: virtual int CDmeAssemblyCommand::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAssemblyCommand::GetInheritanceDepth(CDmeAssemblyCommand *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAssemblyCommand::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E7E60
// Name: _dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAssemblyCommand::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAssemblyCommand pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECA70
// Name: _dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAssemblyCommand::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAssemblyCommand::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7E90
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAssemblyCommand_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7EA0
// Name: _dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAssemblyCommand_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAssemblyCommand_Helper,
           classname: "DmeAssemblyCommand",
           pFactory: &g_CDmeAssemblyCommand_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7EC0
// Name: _dynamic_initializer_for__LOG_DME_AAC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DME_AAC__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DmeAnimationAssemblyCommand",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_109);
  LOG_DME_AAC = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005ECA80
// Name: _dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAssemblyCommand_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAssemblyCommand_Factory.m_CallBackList);
}

} // namespace studiomdl
