// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmesound.cpp
// Functions: 18
// ============================================================

#include "movieobjects\dmesound.h"

//------------------------------------------------------------------------------
// Address: 0x00559BA0
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x00559CF0
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559D20
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559D60
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x00559E70
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00559F50
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559F80
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00559FD0
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC50
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADCB0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0570
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0580
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC80
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADC90
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADCE0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADCF0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0590
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B05A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B0CD0
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x005B0E20
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0E50
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0E90
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x005B0FA0
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B1080
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B10B0
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B1100
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067F440
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F4A0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682A80
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682A90
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F470
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F480
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F4D0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F4E0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682AB0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10595030
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x10595180
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x105951B0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x105951F0
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x10595300
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x105953E0
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10595410
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10595460
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9770
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C97D0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA90
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAA0
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C97A0
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C97B0
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9800
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9810
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAB0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00565DD0
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x00565F50
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565F80
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565FC0
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x005660D0
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005661B0
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005661E0
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566230
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D1D0
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D230
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F880
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F890
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D200
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D210
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D260
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D270
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8A0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AEE80
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x005AEFD0
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF000
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF040
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x005AF150
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AF230
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF260
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF2B0
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F1E60
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1EC0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B90
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BA0
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1E90
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1EA0
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1EF0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1F00
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BB0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051B410
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x0051B560
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B590
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B5D0
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x0051B6E0
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051B7C0
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B7F0
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051B850
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056C020
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C080
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC60
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC70
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C050
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C060
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056C0B0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C0C0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC80
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EC90
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00521640
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x00521790
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005217C0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521800
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x00521910
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005219F0
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521A20
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521A70
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C140
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1A0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED90
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDA0
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C170
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C180
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1D0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C1E0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDB0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EDC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DE550
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x005DE6A0
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE6D0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE710
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x005DE820
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DE900
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE930
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DE980
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1290
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B12F0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5580
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5590
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B12C0
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B12D0
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1320
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1330
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B55A0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B55B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00522780
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x00522840
// Name: public: class CDmElement __near * CDmeGameSound::FindOrAddPhonemeExtractionSettings(void)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeGameSound::FindOrAddPhonemeExtractionSettings(CDmeGameSound *this)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CExpressionCalculator *v5; // esi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  if ( CDmElement::HasAttribute(this, pAttributeName: "PhonemeExtractionSettings", type: AT_UNKNOWN) )
    return (CExpressionCalculator *)CDmElement::GetValueElement<CDmElement>(
                                      this,
                                      pAttributeName: "PhonemeExtractionSettings");
  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "PhonemeExtractionSettings",
         a4: this->m_fileId,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = (CExpressionCalculator *)v4;
  if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmElement::m_classType) )
    return nullptr;
  value = CExpressionCalculator::VariableCount(this: v5);
  Attribute = CDmElement::FindAttribute(this, pAttributeName: "PhonemeExtractionSettings");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(
                      this,
                      pAttributeName: "PhonemeExtractionSettings",
                      type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, &value);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00522990
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005229C0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522A00
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x00522B10
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00522BF0
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522C20
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00522C80
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057E110
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E170
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580D70
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580D80
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E140
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E150
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E1A0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E1B0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580D90
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580DA0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A7DE0
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x005A7F30
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7F60
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7FA0
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x005A80B0
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A8190
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A81C0
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A8210
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction();
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EAD10
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAD70
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA30
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA40
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAD40
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAD50
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EADA0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EADB0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA50
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA60
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00529D40
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x00529E90
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529EC0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529F10
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x0052A030
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052A110
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A140
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052A190
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057B960
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B9C0
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 164,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E460
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E470
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B990
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B9A0
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B9F0
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BA00
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E480
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E490
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062CD50
// Name: protected: void CDmeGameSound::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::OnConstruction(CDmeGameSound *this)
{
  this->m_Volume.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "volume",
                                  type: AT_FLOAT,
                                  pMemory: &this->m_Volume);
  this->m_Level.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "level",
                                 type: AT_INT,
                                 pMemory: &this->m_Level);
  this->m_Pitch.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pitch",
                                 type: AT_INT,
                                 pMemory: &this->m_Pitch);
  this->m_IsStatic.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "static",
                                    type: AT_BOOL,
                                    pMemory: &this->m_IsStatic);
  this->m_Channel.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "channel",
                                   type: AT_INT,
                                   pMemory: &this->m_Channel);
  this->m_Flags.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "flags",
                                 type: AT_INT,
                                 pMemory: &this->m_Flags);
  this->m_Origin.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "origin",
                                  type: AT_VECTOR3,
                                  pMemory: &this->m_Origin);
  this->m_Direction.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "direction",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_Direction);
}

//------------------------------------------------------------------------------
// Address: 0x0062CEA0
// Name: public: virtual bool CDmeSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSound::IsA(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CED0
// Name: public: virtual int CDmeSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSound::GetInheritanceDepth(CDmeSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062CF10
// Name: protected: virtual void CDmeSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSound::PerformConstruction(CDmeSound *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
}

//------------------------------------------------------------------------------
// Address: 0x0062D030
// Name: protected: CDmeGameSound::CDmeGameSound(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeGameSound *__thiscall CDmeGameSound::CDmeGameSound(
        CDmeGameSound *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_SoundName.m_pAttribute = nullptr;
  this->m_SoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->m_GameSoundName.m_pAttribute = nullptr;
  this->m_GameSoundName.m_Storage.u.CDmeSound::m_Id = -1;
  this->__vftable = (CDmeGameSound_vtbl *)&CDmeGameSound::`vftable';
  this->m_Volume = 0;
  this->m_Level.m_pAttribute = nullptr;
  this->m_Level.m_Storage = 0;
  this->m_Pitch.m_pAttribute = nullptr;
  this->m_Pitch.m_Storage = 0;
  this->m_IsStatic.m_pAttribute = nullptr;
  this->m_IsStatic.m_Storage = false;
  this->m_Channel.m_pAttribute = nullptr;
  this->m_Channel.m_Storage = 0;
  this->m_Flags.m_pAttribute = nullptr;
  this->m_Flags.m_Storage = 0;
  this->m_Origin.m_pAttribute = nullptr;
  this->m_Origin.m_Storage.x = 0.0;
  this->m_Origin.m_Storage.y = 0.0;
  this->m_Origin.m_Storage.z = 0.0;
  this->m_Direction.m_pAttribute = nullptr;
  this->m_Direction.m_Storage.x = 0.0;
  this->m_Direction.m_Storage.y = 0.0;
  this->m_Direction.m_Storage.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062D110
// Name: public: virtual bool CDmeGameSound::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGameSound::IsA(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062D140
// Name: public: virtual int CDmeGameSound::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGameSound::GetInheritanceDepth(CDmeGameSound *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGameSound::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSound::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062D190
// Name: protected: virtual void CDmeGameSound::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGameSound::PerformConstruction(CDmeGameSound *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_SoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "soundname",
                                     type: AT_STRING,
                                     pMemory: &this->m_SoundName);
  this->m_GameSoundName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "gameSoundName",
                                         type: AT_STRING,
                                         pMemory: &this->m_GameSoundName);
  CDmeGameSound::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B98D0
// Name: _dynamic_initializer_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSound::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9930
// Name: _dynamic_initializer_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGameSound::s_Allocator,
    blockSize: 0xA4u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGameSound pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD280
// Name: _dynamic_atexit_destructor_for__CDmeSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD290
// Name: _dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGameSound::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGameSound::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9900
// Name: _dynamic_initializer_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9910
// Name: _dynamic_initializer_for__g_CDmeSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSound_Helper,
           classname: "DmeSound",
           pFactory: &g_CDmeSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9960
// Name: _dynamic_initializer_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGameSound_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9970
// Name: _dynamic_initializer_for__g_CDmeGameSound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGameSound_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGameSound_Helper,
           classname: "DmeGameSound",
           pFactory: &g_CDmeGameSound_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2A0
// Name: _dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGameSound_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeGameSound_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD2B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSound_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSound_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSound_Factory.m_CallBackList);
}

} // namespace vmap
