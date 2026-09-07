// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeik.cpp
// Functions: 68
// ============================================================

#include "mdlobjects\dmeik.h"

//------------------------------------------------------------------------------
// Address: 0x0049EDD0
// Name: protected: void CDmeIkRange::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::OnConstruction(CDmeIkRange *this)
{
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
  this->m_nMaxStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "maxStartFrame",
                                          type: AT_INT,
                                          pMemory: &this->m_nMaxStartFrame);
  this->m_nMaxEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxEndFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0049EED0
// Name: protected: void CDmeIkChain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::OnConstruction(CDmeIkChain *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sEndJoint.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endJoint",
                                     type: AT_STRING,
                                     pMemory: &this->m_sEndJoint);
  value = 18.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_FLOAT, pMemory: &this->m_flHeight);
  this->m_flHeight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  this->m_flPad.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pad",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flPad);
  this->m_flFloor.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "floor",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flFloor);
  this->m_vKnee.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "knee",
                                 type: AT_VECTOR3,
                                 pMemory: &this->m_vKnee);
  this->m_vCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "center",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vCenter);
}

//------------------------------------------------------------------------------
// Address: 0x0049EF80
// Name: protected: void CDmeIkLock::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::OnConstruction(CDmeIkLock *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_flLockPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockPosition",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockPosition);
  this->m_flLockRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockRotation",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockRotation);
}

//------------------------------------------------------------------------------
// Address: 0x0049F000
// Name: protected: void CDmeIkRule::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::OnConstruction(CDmeIkRule *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  CDmaElement<CDmeIkRange>::InitAndCreate(
    this: &this->m_eRange,
    pOwner: this,
    pAttributeName: "range",
    pElementName: nullptr,
    flags: 0);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "useType", type: AT_INT, pMemory: &this->m_nUseType);
  this->m_nUseType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0049F110
// Name: public: virtual bool CDmeIkChain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkChain::IsA(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F140
// Name: public: virtual int CDmeIkChain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::GetInheritanceDepth(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F220
// Name: protected: virtual void CDmeIkChain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::PerformConstruction(CDmeIkChain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkChain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049F2C0
// Name: public: virtual bool CDmeIkLock::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkLock::IsA(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F2F0
// Name: public: virtual int CDmeIkLock::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkLock::GetInheritanceDepth(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F3B0
// Name: protected: virtual void CDmeIkLock::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::PerformConstruction(CDmeIkLock *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkLock::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049F450
// Name: public: virtual bool CDmeIkRange::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRange::IsA(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F480
// Name: public: virtual int CDmeIkRange::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRange::GetInheritanceDepth(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F530
// Name: protected: virtual void CDmeIkRange::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::PerformConstruction(CDmeIkRange *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRange::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049F5D0
// Name: public: virtual bool CDmeIkRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRule::IsA(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F600
// Name: public: virtual int CDmeIkRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::GetInheritanceDepth(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F6B0
// Name: protected: virtual void CDmeIkRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::PerformConstruction(CDmeIkReleaseRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049F750
// Name: public: virtual bool CDmeIkTouchRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkTouchRule::IsA(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F780
// Name: public: virtual int CDmeIkTouchRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkTouchRule::GetInheritanceDepth(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F850
// Name: protected: virtual void CDmeIkTouchRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkTouchRule::PerformConstruction(CDmeIkTouchRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
}

//------------------------------------------------------------------------------
// Address: 0x0049F910
// Name: public: virtual bool CDmeIkFootstepRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkFootstepRule::IsA(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049F940
// Name: public: virtual int CDmeIkFootstepRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkFootstepRule::GetInheritanceDepth(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049FA90
// Name: public: virtual bool CDmeIkAttachmentRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkAttachmentRule::IsA(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049FAC0
// Name: public: virtual int CDmeIkAttachmentRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkAttachmentRule::GetInheritanceDepth(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049FB90
// Name: protected: virtual void CDmeIkAttachmentRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkAttachmentRule::PerformConstruction(CDmeIkAttachmentRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0049FC60
// Name: public: virtual bool CDmeIkReleaseRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkReleaseRule::IsA(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049FC90
// Name: public: virtual int CDmeIkReleaseRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkReleaseRule::GetInheritanceDepth(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1380
// Name: protected: virtual int CDmeIkRule::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x005656D0
// Name: protected: virtual int CDmeIkChain::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x00598D60
// Name: _dynamic_initializer_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkChain::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkChain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598DC0
// Name: _dynamic_initializer_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkLock::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkLock pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598E20
// Name: _dynamic_initializer_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRange::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRange pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598E80
// Name: _dynamic_initializer_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598EE0
// Name: _dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkTouchRule::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkTouchRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598F40
// Name: _dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkFootstepRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkFootstepRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598FA0
// Name: _dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkAttachmentRule::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkAttachmentRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599000
// Name: _dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkReleaseRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkReleaseRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E180
// Name: _dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkChain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E190
// Name: _dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkLock::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1A0
// Name: _dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRange::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1B0
// Name: _dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1C0
// Name: _dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkTouchRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1D0
// Name: _dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkFootstepRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1E0
// Name: _dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkAttachmentRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E1F0
// Name: _dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkReleaseRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598D90
// Name: _dynamic_initializer_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkChain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598DA0
// Name: _dynamic_initializer_for__g_CDmeIkChain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkChain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkChain_Helper,
           classname: "DmeIkChain",
           pFactory: &g_CDmeIkChain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598DF0
// Name: _dynamic_initializer_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkLock_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598E00
// Name: _dynamic_initializer_for__g_CDmeIkLock_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkLock_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkLock_Helper,
           classname: "DmeIkLock",
           pFactory: &g_CDmeIkLock_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598E50
// Name: _dynamic_initializer_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRange_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598E60
// Name: _dynamic_initializer_for__g_CDmeIkRange_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRange_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRange_Helper,
           classname: "DmeIkRange",
           pFactory: &g_CDmeIkRange_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598EB0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598EC0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRule_Helper,
           classname: "DmeIkRule",
           pFactory: &g_CDmeIkRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598F10
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkTouchRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598F20
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkTouchRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkTouchRule_Helper,
           classname: "DmeIkTouchRule",
           pFactory: &g_CDmeIkTouchRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598F70
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598F80
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkFootstepRule_Helper,
           classname: "DmeIkFootstepRule",
           pFactory: &g_CDmeIkFootstepRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598FD0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598FE0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkAttachmentRule_Helper,
           classname: "DmeIkAttachmentRule",
           pFactory: &g_CDmeIkAttachmentRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599030
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599040
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkReleaseRule_Helper,
           classname: "DmeIkReleaseRule",
           pFactory: &g_CDmeIkReleaseRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E200
// Name: _dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkLock_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E210
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRange_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E220
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E230
// Name: _dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkTouchRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E240
// Name: _dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkFootstepRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E250
// Name: _dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkAttachmentRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E260
// Name: _dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkReleaseRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E270
// Name: _dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkChain_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E3500
// Name: public: void CDmaElement<class CDmeMotionControl>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeMotionControl>::InitAndCreate(
        CDmaElement<CDmeMotionControl> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeMotionControl::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeMotionControl::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004E35A0
// Name: public: void CDmaElement<class CDmeSequenceActivity>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeSequenceActivity>::InitAndCreate(
        CDmaElement<CDmeSequenceActivity> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeSequenceActivity::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeSequenceActivity::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004E7590
// Name: protected: void CDmeIkRange::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::OnConstruction(CDmeIkRange *this)
{
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
  this->m_nMaxStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "maxStartFrame",
                                          type: AT_INT,
                                          pMemory: &this->m_nMaxStartFrame);
  this->m_nMaxEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxEndFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004E75F0
// Name: public: void CDmaElement<class CDmeIkRange>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeIkRange>::InitAndCreate(
        CDmaElement<CDmeIkRange> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeIkRange::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeIkRange::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004E7690
// Name: protected: void CDmeIkChain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::OnConstruction(CDmeIkChain *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sEndJoint.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endJoint",
                                     type: AT_STRING,
                                     pMemory: &this->m_sEndJoint);
  value = 18.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_FLOAT, pMemory: &this->m_flHeight);
  this->m_flHeight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  this->m_flPad.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pad",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flPad);
  this->m_flFloor.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "floor",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flFloor);
  this->m_vKnee.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "knee",
                                 type: AT_VECTOR3,
                                 pMemory: &this->m_vKnee);
  this->m_vCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "center",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vCenter);
}

//------------------------------------------------------------------------------
// Address: 0x004E7740
// Name: protected: void CDmeIkLock::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::OnConstruction(CDmeIkLock *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_flLockPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockPosition",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockPosition);
  this->m_flLockRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockRotation",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockRotation);
}

//------------------------------------------------------------------------------
// Address: 0x004E77B0
// Name: protected: void CDmeIkRule::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::OnConstruction(CDmeIkRule *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  CDmaElement<CDmeIkRange>::InitAndCreate(
    this: &this->m_eRange,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"range",
    pElementName: nullptr,
    flags: 0);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "useType", type: AT_INT, pMemory: &this->m_nUseType);
  this->m_nUseType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E78C0
// Name: public: virtual bool CDmeIkChain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkChain::IsA(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E78F0
// Name: public: virtual int CDmeIkChain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::GetInheritanceDepth(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E79D0
// Name: protected: virtual void CDmeIkChain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::PerformConstruction(CDmeIkChain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkChain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E7A70
// Name: public: virtual bool CDmeIkLock::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkLock::IsA(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7AA0
// Name: public: virtual int CDmeIkLock::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkLock::GetInheritanceDepth(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7B70
// Name: protected: virtual void CDmeIkLock::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::PerformConstruction(CDmeIkLock *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkLock::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E7C10
// Name: public: virtual bool CDmeIkRange::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRange::IsA(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7C40
// Name: public: virtual int CDmeIkRange::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRange::GetInheritanceDepth(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7CF0
// Name: protected: virtual void CDmeIkRange::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::PerformConstruction(CDmeIkRange *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRange::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E7D90
// Name: public: virtual bool CDmeIkRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRule::IsA(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7DC0
// Name: public: virtual int CDmeIkRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::GetInheritanceDepth(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7F00
// Name: public: virtual bool CDmeIkTouchRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkTouchRule::IsA(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7F30
// Name: public: virtual int CDmeIkTouchRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkTouchRule::GetInheritanceDepth(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7FF0
// Name: protected: virtual void CDmeIkTouchRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkTouchRule::PerformConstruction(CDmeIkTouchRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
}

//------------------------------------------------------------------------------
// Address: 0x004E80B0
// Name: public: virtual bool CDmeIkFootstepRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkFootstepRule::IsA(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E80E0
// Name: public: virtual int CDmeIkFootstepRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkFootstepRule::GetInheritanceDepth(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8230
// Name: public: virtual bool CDmeIkAttachmentRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkAttachmentRule::IsA(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8260
// Name: public: virtual int CDmeIkAttachmentRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkAttachmentRule::GetInheritanceDepth(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8330
// Name: protected: virtual void CDmeIkAttachmentRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkAttachmentRule::PerformConstruction(CDmeIkAttachmentRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x004E8400
// Name: public: virtual bool CDmeIkReleaseRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkReleaseRule::IsA(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8430
// Name: public: virtual int CDmeIkReleaseRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkReleaseRule::GetInheritanceDepth(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E84F0
// Name: protected: virtual void CDmeIkRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::PerformConstruction(CDmeIkReleaseRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004ED150
// Name: public: void CDmaElement<class CDmeMatSysPanelSettings>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeMatSysPanelSettings>::InitAndCreate(
        CDmaElement<CDmeMatSysPanelSettings> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeMatSysPanelSettings::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeMatSysPanelSettings::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004EDD10
// Name: protected: virtual int CDmeIkRule::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x004F4620
// Name: public: void CDmaElement<class CDmeAttributeReference>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeAttributeReference>::InitAndCreate(
        CDmaElement<CDmeAttributeReference> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeAttributeReference::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeAttributeReference::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004F5320
// Name: public: void CDmaElement<class CDmeTransform>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeTransform>::InitAndCreate(
        CDmaElement<CDmeTransform> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeTransform::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeTransform::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x004FD8B0
// Name: public: void CDmaElement<class CDmeTimeFrame>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeTimeFrame>::InitAndCreate(
        CDmaElement<CDmeTimeFrame> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeTimeFrame::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeTimeFrame::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x00505120
// Name: public: void CDmaElement<class CDmeConstraintSlave>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeConstraintSlave>::InitAndCreate(
        CDmaElement<CDmeConstraintSlave> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeConstraintSlave::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeConstraintSlave::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x005AE780
// Name: protected: virtual int CDmeIkChain::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x005B1370
// Name: public: void CDmaElement<class CDmeControlGroup>::InitAndCreate(class CDmElement __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaElement<CDmeControlGroup>::InitAndCreate(
        CDmaElement<CDmeControlGroup> *this,
        CDmElement *pOwner,
        DmElementHandle_t pAttributeName,
        const char *pElementName,
        __int16 flags)
{
  this->m_pAttribute = CDmElement::AddExternalAttribute(
                         this: pOwner,
                         (const char *)pAttributeName,
                         type: AT_FIRST_VALUE_TYPE,
                         pMemory: this);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pAttribute, typeSymbol: CDmeControlGroup::m_classType);
  pAttributeName = DMELEMENT_HANDLE_INVALID;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 152))(a1: g_pDataModel.u) == 0 )
    pAttributeName = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                       a1: g_pDataModel.u,
                       a2: CDmeControlGroup::m_classType.u,
                       a3: pElementName,
                       a4: pOwner->m_fileId,
                       a5: 0);
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pAttribute, value: &pAttributeName);
  this->m_pAttribute->m_nFlags |= flags & 0xF7E0 | 0x800;
}

//------------------------------------------------------------------------------
// Address: 0x005EDE80
// Name: _dynamic_initializer_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkChain::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkChain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDEE0
// Name: _dynamic_initializer_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkLock::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkLock pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDF40
// Name: _dynamic_initializer_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRange::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRange pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDFA0
// Name: _dynamic_initializer_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE000
// Name: _dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkTouchRule::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkTouchRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE060
// Name: _dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkFootstepRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkFootstepRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE0C0
// Name: _dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkAttachmentRule::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkAttachmentRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE120
// Name: _dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkReleaseRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkReleaseRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3610
// Name: _dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkChain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3620
// Name: _dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkLock::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3630
// Name: _dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRange::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3640
// Name: _dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3650
// Name: _dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkTouchRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3660
// Name: _dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkFootstepRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3670
// Name: _dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkAttachmentRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3680
// Name: _dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkReleaseRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDEB0
// Name: _dynamic_initializer_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkChain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDEC0
// Name: _dynamic_initializer_for__g_CDmeIkChain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkChain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkChain_Helper,
           classname: "DmeIkChain",
           pFactory: &g_CDmeIkChain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDF10
// Name: _dynamic_initializer_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkLock_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDF20
// Name: _dynamic_initializer_for__g_CDmeIkLock_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkLock_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkLock_Helper,
           classname: "DmeIkLock",
           pFactory: &g_CDmeIkLock_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDF70
// Name: _dynamic_initializer_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRange_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDF80
// Name: _dynamic_initializer_for__g_CDmeIkRange_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRange_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRange_Helper,
           classname: "DmeIkRange",
           pFactory: &g_CDmeIkRange_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDFD0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDFE0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRule_Helper,
           classname: "DmeIkRule",
           pFactory: &g_CDmeIkRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE030
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkTouchRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE040
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkTouchRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkTouchRule_Helper,
           classname: "DmeIkTouchRule",
           pFactory: &g_CDmeIkTouchRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE090
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE0A0
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkFootstepRule_Helper,
           classname: "DmeIkFootstepRule",
           pFactory: &g_CDmeIkFootstepRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE0F0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE100
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkAttachmentRule_Helper,
           classname: "DmeIkAttachmentRule",
           pFactory: &g_CDmeIkAttachmentRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE150
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE160
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkReleaseRule_Helper,
           classname: "DmeIkReleaseRule",
           pFactory: &g_CDmeIkReleaseRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3690
// Name: _dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkLock_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36A0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRange_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36B0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36C0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkTouchRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36D0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkFootstepRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36E0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkAttachmentRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F36F0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkReleaseRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3700
// Name: _dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkChain_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E970
// Name: protected: void CDmeIkRange::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::OnConstruction(CDmeIkRange *this)
{
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
  this->m_nMaxStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "maxStartFrame",
                                          type: AT_INT,
                                          pMemory: &this->m_nMaxStartFrame);
  this->m_nMaxEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxEndFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0050EA70
// Name: protected: void CDmeIkChain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::OnConstruction(CDmeIkChain *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sEndJoint.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endJoint",
                                     type: AT_STRING,
                                     pMemory: &this->m_sEndJoint);
  value = 18.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_FLOAT, pMemory: &this->m_flHeight);
  this->m_flHeight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  this->m_flPad.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pad",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flPad);
  this->m_flFloor.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "floor",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flFloor);
  this->m_vKnee.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "knee",
                                 type: AT_VECTOR3,
                                 pMemory: &this->m_vKnee);
  this->m_vCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "center",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vCenter);
}

//------------------------------------------------------------------------------
// Address: 0x0050EB20
// Name: protected: void CDmeIkLock::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::OnConstruction(CDmeIkLock *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_flLockPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockPosition",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockPosition);
  this->m_flLockRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockRotation",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockRotation);
}

//------------------------------------------------------------------------------
// Address: 0x0050EB90
// Name: protected: void CDmeIkRule::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::OnConstruction(CDmeIkRule *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  CDmaElement<CDmeIkRange>::InitAndCreate(
    this: &this->m_eRange,
    pOwner: this,
    pAttributeName: "range",
    pElementName: nullptr,
    flags: 0);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "useType", type: AT_INT, pMemory: &this->m_nUseType);
  this->m_nUseType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050ECA0
// Name: public: virtual bool CDmeIkChain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkChain::IsA(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050ECD0
// Name: public: virtual int CDmeIkChain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::GetInheritanceDepth(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050ED10
// Name: protected: virtual int CDmeIkChain::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x0050EDC0
// Name: protected: virtual void CDmeIkChain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::PerformConstruction(CDmeIkChain *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkChain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050EE60
// Name: public: virtual bool CDmeIkLock::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkLock::IsA(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050EE90
// Name: public: virtual int CDmeIkLock::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkLock::GetInheritanceDepth(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050EF50
// Name: protected: virtual void CDmeIkLock::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::PerformConstruction(CDmeIkLock *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkLock::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050EFF0
// Name: public: virtual bool CDmeIkRange::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRange::IsA(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F020
// Name: public: virtual int CDmeIkRange::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRange::GetInheritanceDepth(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F0D0
// Name: protected: virtual void CDmeIkRange::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::PerformConstruction(CDmeIkRange *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkRange::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050F170
// Name: public: virtual bool CDmeIkRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRule::IsA(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F1A0
// Name: public: virtual int CDmeIkRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::GetInheritanceDepth(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F2E0
// Name: public: virtual bool CDmeIkTouchRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkTouchRule::IsA(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F310
// Name: public: virtual int CDmeIkTouchRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkTouchRule::GetInheritanceDepth(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F3D0
// Name: protected: virtual void CDmeIkTouchRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkTouchRule::PerformConstruction(CDmeIkTouchRule *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkRule::OnConstruction(this);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
}

//------------------------------------------------------------------------------
// Address: 0x0050F490
// Name: public: virtual bool CDmeIkFootstepRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkFootstepRule::IsA(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F4C0
// Name: public: virtual int CDmeIkFootstepRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkFootstepRule::GetInheritanceDepth(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F610
// Name: public: virtual bool CDmeIkAttachmentRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkAttachmentRule::IsA(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F640
// Name: public: virtual int CDmeIkAttachmentRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkAttachmentRule::GetInheritanceDepth(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F710
// Name: protected: virtual void CDmeIkAttachmentRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkAttachmentRule::PerformConstruction(CDmeIkAttachmentRule *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkRule::OnConstruction(this);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x0050F7E0
// Name: public: virtual bool CDmeIkReleaseRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkReleaseRule::IsA(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F810
// Name: public: virtual int CDmeIkReleaseRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkReleaseRule::GetInheritanceDepth(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F8D0
// Name: protected: virtual void CDmeIkRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::PerformConstruction(CDmeIkReleaseRule *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeIkRule::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00516450
// Name: protected: virtual int CDmeIkRule::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x006AD160
// Name: _dynamic_initializer_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkChain::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkChain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD1C0
// Name: _dynamic_initializer_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkLock::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkLock pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD220
// Name: _dynamic_initializer_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRange::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRange pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD280
// Name: _dynamic_initializer_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD2E0
// Name: _dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkTouchRule::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkTouchRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD340
// Name: _dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkFootstepRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkFootstepRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD3A0
// Name: _dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkAttachmentRule::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkAttachmentRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD400
// Name: _dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkReleaseRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkReleaseRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F50
// Name: _dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkChain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F60
// Name: _dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkLock::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F70
// Name: _dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRange::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F80
// Name: _dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F90
// Name: _dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkTouchRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FA0
// Name: _dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkFootstepRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FB0
// Name: _dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkAttachmentRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FC0
// Name: _dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkReleaseRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD190
// Name: _dynamic_initializer_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkChain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD1A0
// Name: _dynamic_initializer_for__g_CDmeIkChain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkChain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkChain_Helper,
           classname: "DmeIkChain",
           pFactory: &g_CDmeIkChain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD1F0
// Name: _dynamic_initializer_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkLock_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD200
// Name: _dynamic_initializer_for__g_CDmeIkLock_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkLock_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkLock_Helper,
           classname: "DmeIkLock",
           pFactory: &g_CDmeIkLock_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD250
// Name: _dynamic_initializer_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRange_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD260
// Name: _dynamic_initializer_for__g_CDmeIkRange_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRange_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRange_Helper,
           classname: "DmeIkRange",
           pFactory: &g_CDmeIkRange_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD2B0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD2C0
// Name: _dynamic_initializer_for__g_CDmeIkRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRule_Helper,
           classname: "DmeIkRule",
           pFactory: &g_CDmeIkRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD310
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkTouchRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD320
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkTouchRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkTouchRule_Helper,
           classname: "DmeIkTouchRule",
           pFactory: &g_CDmeIkTouchRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD370
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD380
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkFootstepRule_Helper,
           classname: "DmeIkFootstepRule",
           pFactory: &g_CDmeIkFootstepRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD3D0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD3E0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkAttachmentRule_Helper,
           classname: "DmeIkAttachmentRule",
           pFactory: &g_CDmeIkAttachmentRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD430
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD440
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkReleaseRule_Helper,
           classname: "DmeIkReleaseRule",
           pFactory: &g_CDmeIkReleaseRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FD0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkLock_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FE0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkRange_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3FF0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4000
// Name: _dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkTouchRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4010
// Name: _dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkFootstepRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4020
// Name: _dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkAttachmentRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4030
// Name: _dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkReleaseRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4040
// Name: _dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIkChain_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DE3E0
// Name: protected: void CDmeIkRange::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::OnConstruction(CDmeIkRange *this)
{
  this->m_nStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "startFrame",
                                       type: AT_INT,
                                       pMemory: &this->m_nStartFrame);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
  this->m_nMaxStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "maxStartFrame",
                                          type: AT_INT,
                                          pMemory: &this->m_nMaxStartFrame);
  this->m_nMaxEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxEndFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004DE4E0
// Name: protected: void CDmeIkChain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::OnConstruction(CDmeIkChain *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  this->m_sEndJoint.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endJoint",
                                     type: AT_STRING,
                                     pMemory: &this->m_sEndJoint);
  value = 18.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_FLOAT, pMemory: &this->m_flHeight);
  this->m_flHeight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
  this->m_flPad.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "pad",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flPad);
  this->m_flFloor.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "floor",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flFloor);
  this->m_vKnee.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "knee",
                                 type: AT_VECTOR3,
                                 pMemory: &this->m_vKnee);
  this->m_vCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "center",
                                   type: AT_VECTOR3,
                                   pMemory: &this->m_vCenter);
}

//------------------------------------------------------------------------------
// Address: 0x004DE590
// Name: protected: void CDmeIkLock::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::OnConstruction(CDmeIkLock *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_flLockPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockPosition",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockPosition);
  this->m_flLockRotation.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "lockRotation",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flLockRotation);
}

//------------------------------------------------------------------------------
// Address: 0x004DE600
// Name: protected: void CDmeIkRule::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::OnConstruction(CDmeIkRule *this)
{
  CDmaElement<CDmeIkChain> *p_m_eIkChain; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_eIkChain = &this->m_eIkChain;
  this->m_eIkChain.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "ikChain",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_eIkChain);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eIkChain->m_pAttribute, typeSymbol: CDmeIkChain::m_classType);
  p_m_eIkChain->m_pAttribute->m_nFlags |= 0x1000u;
  CDmaElement<CDmeIkRange>::InitAndCreate(
    this: &this->m_eRange,
    pOwner: this,
    pAttributeName: "range",
    pElementName: nullptr,
    flags: 0);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "useType", type: AT_INT, pMemory: &this->m_nUseType);
  this->m_nUseType.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004DE710
// Name: public: virtual bool CDmeIkChain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkChain::IsA(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE740
// Name: public: virtual int CDmeIkChain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::GetInheritanceDepth(CDmeIkChain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkChain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE780
// Name: protected: virtual int CDmeIkChain::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkChain::AllocatedSize(CDmeRigAnimSetElements *this)
{
  return 132;
}

//------------------------------------------------------------------------------
// Address: 0x004DE830
// Name: protected: virtual void CDmeIkChain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkChain::PerformConstruction(CDmeIkChain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkChain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DE8D0
// Name: public: virtual bool CDmeIkLock::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkLock::IsA(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE900
// Name: public: virtual int CDmeIkLock::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkLock::GetInheritanceDepth(CDmeIkLock *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkLock::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE9C0
// Name: protected: virtual void CDmeIkLock::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkLock::PerformConstruction(CDmeIkLock *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkLock::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DEA60
// Name: public: virtual bool CDmeIkRange::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRange::IsA(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DEA90
// Name: public: virtual int CDmeIkRange::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRange::GetInheritanceDepth(CDmeIkRange *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRange::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DEB40
// Name: protected: virtual void CDmeIkRange::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRange::PerformConstruction(CDmeIkRange *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRange::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DEBE0
// Name: public: virtual bool CDmeIkRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkRule::IsA(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DEC10
// Name: public: virtual int CDmeIkRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::GetInheritanceDepth(CDmeIkRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DED50
// Name: public: virtual bool CDmeIkTouchRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkTouchRule::IsA(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DED80
// Name: public: virtual int CDmeIkTouchRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkTouchRule::GetInheritanceDepth(CDmeIkTouchRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkTouchRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DEE50
// Name: protected: virtual void CDmeIkTouchRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkTouchRule::PerformConstruction(CDmeIkTouchRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
}

//------------------------------------------------------------------------------
// Address: 0x004DEF10
// Name: public: virtual bool CDmeIkFootstepRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkFootstepRule::IsA(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DEF40
// Name: public: virtual int CDmeIkFootstepRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkFootstepRule::GetInheritanceDepth(CDmeIkFootstepRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkFootstepRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF000
// Name: protected: virtual void CDmeIkRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkRule::PerformConstruction(CDmeIkReleaseRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DF0A0
// Name: public: virtual bool CDmeIkAttachmentRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkAttachmentRule::IsA(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF0D0
// Name: public: virtual int CDmeIkAttachmentRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkAttachmentRule::GetInheritanceDepth(CDmeIkAttachmentRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkAttachmentRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF1A0
// Name: protected: virtual void CDmeIkAttachmentRule::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIkAttachmentRule::PerformConstruction(CDmeIkAttachmentRule *this)
{
  CDmeFXClip::OnDestruction();
  CDmeIkRule::OnConstruction(this);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  this->m_flRadius.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "radius",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x004DF270
// Name: public: virtual bool CDmeIkReleaseRule::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIkReleaseRule::IsA(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF2A0
// Name: public: virtual int CDmeIkReleaseRule::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkReleaseRule::GetInheritanceDepth(CDmeIkReleaseRule *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIkReleaseRule::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeIkRule::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005081A0
// Name: protected: virtual int CDmeIkRule::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIkRule::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x005E6830
// Name: _dynamic_initializer_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkChain::s_Allocator,
    blockSize: 132,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkChain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6890
// Name: _dynamic_initializer_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkLock::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkLock pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E68F0
// Name: _dynamic_initializer_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRange::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRange pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6950
// Name: _dynamic_initializer_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E69B0
// Name: _dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkTouchRule::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkTouchRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6A10
// Name: _dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkFootstepRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkFootstepRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6A70
// Name: _dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkAttachmentRule::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkAttachmentRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6AD0
// Name: _dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIkReleaseRule::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIkReleaseRule pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC310
// Name: _dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkChain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkChain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC320
// Name: _dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkLock::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkLock::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC330
// Name: _dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRange::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRange::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC340
// Name: _dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC350
// Name: _dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkTouchRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkTouchRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC360
// Name: _dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkFootstepRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkFootstepRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC370
// Name: _dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkAttachmentRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkAttachmentRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC380
// Name: _dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIkReleaseRule::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIkReleaseRule::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6860
// Name: _dynamic_initializer_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkChain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6870
// Name: _dynamic_initializer_for__g_CDmeIkChain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkChain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkChain_Helper,
           classname: "DmeIkChain",
           pFactory: &g_CDmeIkChain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E68C0
// Name: _dynamic_initializer_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkLock_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E68D0
// Name: _dynamic_initializer_for__g_CDmeIkLock_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkLock_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkLock_Helper,
           classname: "DmeIkLock",
           pFactory: &g_CDmeIkLock_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6920
// Name: _dynamic_initializer_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRange_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6930
// Name: _dynamic_initializer_for__g_CDmeIkRange_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRange_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRange_Helper,
           classname: "DmeIkRange",
           pFactory: &g_CDmeIkRange_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6980
// Name: _dynamic_initializer_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6990
// Name: _dynamic_initializer_for__g_CDmeIkRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkRule_Helper,
           classname: "DmeIkRule",
           pFactory: &g_CDmeIkRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E69E0
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkTouchRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E69F0
// Name: _dynamic_initializer_for__g_CDmeIkTouchRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkTouchRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkTouchRule_Helper,
           classname: "DmeIkTouchRule",
           pFactory: &g_CDmeIkTouchRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6A40
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkFootstepRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6A50
// Name: _dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkFootstepRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkFootstepRule_Helper,
           classname: "DmeIkFootstepRule",
           pFactory: &g_CDmeIkFootstepRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6AA0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkAttachmentRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6AB0
// Name: _dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkAttachmentRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkAttachmentRule_Helper,
           classname: "DmeIkAttachmentRule",
           pFactory: &g_CDmeIkAttachmentRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6B00
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIkReleaseRule_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6B10
// Name: _dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIkReleaseRule_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIkReleaseRule_Helper,
           classname: "DmeIkReleaseRule",
           pFactory: &g_CDmeIkReleaseRule_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC390
// Name: _dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkLock_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkLock_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3A0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRange_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRange_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3B0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3C0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkTouchRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkTouchRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3D0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkFootstepRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkFootstepRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3E0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkAttachmentRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkAttachmentRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC3F0
// Name: _dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkReleaseRule_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkReleaseRule_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC400
// Name: _dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIkChain_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIkChain_Factory.m_CallBackList);
}

} // namespace studiomdl
