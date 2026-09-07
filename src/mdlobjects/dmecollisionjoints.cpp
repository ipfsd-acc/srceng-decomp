// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmecollisionjoints.cpp
// Functions: 41
// ============================================================

#include "mdlobjects\dmecollisionjoints.h"

//------------------------------------------------------------------------------
// Address: 0x0049D650
// Name: protected: void CDmeJointConstrain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnConstruction(CDmeJointConstrain *this)
{
  CDmaVar<int> *p_m_nType; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nType = &this->m_nType;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "type", type: AT_INT, pMemory: &this->m_nType);
  p_m_nType->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_aLimitMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "minAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMin);
  this->m_aLimitMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "maxAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMax);
  this->m_flFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "friction",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flFriction);
}

//------------------------------------------------------------------------------
// Address: 0x0049D6D0
// Name: private: virtual void CDmeJointConstrain::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnAttributeChanged(CDmeJointConstrain *this, CDmAttribute *pAttribute)
{
  CDmAttribute *m_pAttribute; // ecx
  int m_Storage; // eax

  m_pAttribute = this->m_nType.m_pAttribute;
  if ( pAttribute == m_pAttribute )
  {
    m_Storage = this->m_nType.m_Storage;
    if ( m_Storage >= 0 )
    {
      if ( m_Storage > 2 )
        m_Storage = 2;
      pAttribute = (CDmAttribute *)m_Storage;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
    else
    {
      pAttribute = nullptr;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049D710
// Name: protected: void CDmeJointAnimatedFriction::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::OnConstruction(CDmeJointAnimatedFriction *this)
{
  CDmaVar<int> *p_m_nMinFriction; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nMinFriction = &this->m_nMinFriction;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minFriction",
         type: AT_INT,
         pMemory: &this->m_nMinFriction);
  p_m_nMinFriction->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxFriction",
         type: AT_INT,
         pMemory: &this->m_nMaxFriction);
  this->m_nMaxFriction.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  this->m_tTimeIn.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "timeIn",
                                   type: AT_TIME,
                                   pMemory: &this->m_tTimeIn);
  this->m_tTimeHold.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "timeHold",
                                     type: AT_TIME,
                                     pMemory: &this->m_tTimeHold);
  this->m_tTimeOut.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "timeOut",
                                    type: AT_TIME,
                                    pMemory: &this->m_tTimeOut);
}

//------------------------------------------------------------------------------
// Address: 0x0049D7B0
// Name: protected: void CDmeCollisionJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::OnConstruction(CDmeCollisionJoint *this)
{
  CDmaVar<float> *p_m_flMassBias; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flMassBias = &this->m_flMassBias;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "massBias", type: AT_FLOAT, pMemory: &this->m_flMassBias);
  p_m_flMassBias->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotDamping);
  this->m_flRotDamping.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  this->m_ConstrainX.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainX",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainX);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainX.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainY.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainY",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainY);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainY.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainZ",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainZ);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainZ.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointMergeList,
    pOwner: this,
    pAttributeName: "jointMergeList",
    nFlags: 0);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointCollideList,
    pOwner: this,
    pAttributeName: "jointCollideList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049D910
// Name: protected: void CDmeCollisionJoints::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::OnConstruction(CDmeCollisionJoints *this)
{
  CDmaVar<bool> *p_m_bConcavePerJoint; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bConcavePerJoint = &this->m_bConcavePerJoint;
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "concavePerJoint",
         type: AT_BOOL,
         pMemory: &this->m_bConcavePerJoint);
  p_m_bConcavePerJoint->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "selfCollisions",
         type: AT_BOOL,
         pMemory: &this->m_bSelfCollisions);
  this->m_bSelfCollisions.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "boneFollower",
         type: AT_BOOL,
         pMemory: &this->m_bBoneFollower);
  this->m_bBoneFollower.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_RootBone.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rootBone",
                                    type: AT_STRING,
                                    pMemory: &this->m_RootBone);
  this->m_AnimatedFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "animatedFriction",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_AnimatedFriction);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimatedFriction.m_pAttribute,
    typeSymbol: CDmeJointAnimatedFriction::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointSkipList,
    pOwner: this,
    pAttributeName: "jointSkipList",
    nFlags: 0);
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_JointList.m_pAttribute, typeSymbol: CDmeCollisionJoint::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0049DAB0
// Name: public: virtual bool CDmeJointConstrain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointConstrain::IsA(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DAE0
// Name: public: virtual int CDmeJointConstrain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointConstrain::GetInheritanceDepth(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DB90
// Name: protected: virtual void CDmeJointConstrain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::PerformConstruction(CDmeJointConstrain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointConstrain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049DC30
// Name: public: virtual bool CDmeJointAnimatedFriction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointAnimatedFriction::IsA(CDmeJointAnimatedFriction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DC60
// Name: public: virtual int CDmeJointAnimatedFriction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointAnimatedFriction::GetInheritanceDepth(
        CDmeJointAnimatedFriction *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DD10
// Name: protected: virtual void CDmeJointAnimatedFriction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::PerformConstruction(CDmeJointAnimatedFriction *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointAnimatedFriction::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049DDE0
// Name: protected: CDmeCollisionJoint::CDmeCollisionJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoint *__thiscall CDmeCollisionJoint::CDmeCollisionJoint(
        CDmeCollisionJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoint_vtbl *)&CDmeCollisionJoint::`vftable';
  this->m_flMassBias.m_Storage = 0.0;
  this->m_flMassBias.m_pAttribute = nullptr;
  this->m_flDamping = 0;
  this->m_flRotDamping = 0;
  this->m_flInertia = 0;
  this->m_ConstrainX.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainX.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainX.m_pAttribute = nullptr;
  this->m_ConstrainY.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainY.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainY.m_pAttribute = nullptr;
  this->m_ConstrainZ.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainZ.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainZ.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointMergeList);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointCollideList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049DE70
// Name: public: virtual bool CDmeCollisionJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoint::IsA(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DEA0
// Name: public: virtual int CDmeCollisionJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::GetInheritanceDepth(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049DEE0
// Name: protected: virtual int CDmeCollisionJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::AllocatedSize(CDmeCollisionJoint *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x0049DEF0
// Name: protected: virtual void CDmeCollisionJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::PerformConstruction(CDmeCollisionJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049DF50
// Name: protected: CDmeCollisionJoints::CDmeCollisionJoints(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoints *__thiscall CDmeCollisionJoints::CDmeCollisionJoints(
        CDmeCollisionJoints *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeCollisionModel::CDmeCollisionModel(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoints_vtbl *)&CDmeCollisionJoints::`vftable';
  this->m_bConcavePerJoint.m_pAttribute = nullptr;
  this->m_bConcavePerJoint.m_Storage = false;
  this->m_bSelfCollisions.m_pAttribute = nullptr;
  this->m_bSelfCollisions.m_Storage = false;
  this->m_bBoneFollower.m_pAttribute = nullptr;
  this->m_bBoneFollower.m_Storage = false;
  this->m_RootBone.m_Storage.u.m_Id = -1;
  this->m_RootBone.m_pAttribute = nullptr;
  this->m_AnimatedFriction.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_AnimatedFriction.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_AnimatedFriction.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointSkipList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049DFE0
// Name: public: virtual bool CDmeCollisionJoints::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoints::IsA(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E010
// Name: public: virtual int CDmeCollisionJoints::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::GetInheritanceDepth(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E060
// Name: protected: virtual int CDmeCollisionJoints::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::AllocatedSize(CDmeCollisionJoints *this)
{
  return 292;
}

//------------------------------------------------------------------------------
// Address: 0x0049E070
// Name: protected: virtual void CDmeCollisionJoints::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::PerformConstruction(CDmeCollisionJoints *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
  CDmeCollisionJoints::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005989A0
// Name: _dynamic_initializer_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointConstrain::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointConstrain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598A00
// Name: _dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointAnimatedFriction::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointAnimatedFriction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598A60
// Name: _dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoint::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598AC0
// Name: _dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoints::s_Allocator,
    blockSize: 292,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoints pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E040
// Name: _dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointConstrain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E050
// Name: _dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointAnimatedFriction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E060
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E070
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoints::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005989D0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointConstrain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005989E0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointConstrain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointConstrain_Helper,
           classname: "DmeJointConstrain",
           pFactory: &g_CDmeJointConstrain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598A30
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598A40
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointAnimatedFriction_Helper,
           classname: "DmeJointAnimatedFriction",
           pFactory: &g_CDmeJointAnimatedFriction_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598A90
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598AA0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoint_Helper,
           classname: "DmeCollisionJoint",
           pFactory: &g_CDmeCollisionJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598AF0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoints_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598B00
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoints_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoints_Helper,
           classname: "DmeCollisionJoints",
           pFactory: &g_CDmeCollisionJoints_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E080
// Name: _dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointAnimatedFriction_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E090
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0A0
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoints_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0B0
// Name: _dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointConstrain_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E1020
// Name: protected: void CDmeJointConstrain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnConstruction(CDmeJointConstrain *this)
{
  CDmaVar<int> *p_m_nType; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nType = &this->m_nType;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "type", type: AT_INT, pMemory: &this->m_nType);
  p_m_nType->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_aLimitMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "minAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMin);
  this->m_aLimitMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "maxAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMax);
  this->m_flFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "friction",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flFriction);
}

//------------------------------------------------------------------------------
// Address: 0x004E10A0
// Name: private: virtual void CDmeJointConstrain::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnAttributeChanged(CDmeJointConstrain *this, CDmAttribute *pAttribute)
{
  CDmAttribute *m_pAttribute; // ecx
  int m_Storage; // eax

  m_pAttribute = this->m_nType.m_pAttribute;
  if ( pAttribute == m_pAttribute )
  {
    m_Storage = this->m_nType.m_Storage;
    if ( m_Storage >= 0 )
    {
      if ( m_Storage > 2 )
        m_Storage = 2;
      pAttribute = (CDmAttribute *)m_Storage;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
    else
    {
      pAttribute = nullptr;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E10E0
// Name: protected: void CDmeJointAnimatedFriction::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::OnConstruction(CDmeJointAnimatedFriction *this)
{
  CDmaVar<int> *p_m_nMinFriction; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nMinFriction = &this->m_nMinFriction;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minFriction",
         type: AT_INT,
         pMemory: &this->m_nMinFriction);
  p_m_nMinFriction->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxFriction",
         type: AT_INT,
         pMemory: &this->m_nMaxFriction);
  this->m_nMaxFriction.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  this->m_tTimeIn.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "timeIn",
                                   type: AT_TIME,
                                   pMemory: &this->m_tTimeIn);
  this->m_tTimeHold.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "timeHold",
                                     type: AT_TIME,
                                     pMemory: &this->m_tTimeHold);
  this->m_tTimeOut.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "timeOut",
                                    type: AT_TIME,
                                    pMemory: &this->m_tTimeOut);
}

//------------------------------------------------------------------------------
// Address: 0x004E1180
// Name: protected: void CDmeCollisionJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::OnConstruction(CDmeCollisionJoint *this)
{
  CDmaVar<float> *p_m_flMassBias; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flMassBias = &this->m_flMassBias;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "massBias", type: AT_FLOAT, pMemory: &this->m_flMassBias);
  p_m_flMassBias->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotDamping);
  this->m_flRotDamping.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  this->m_ConstrainX.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainX",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainX);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainX.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainY.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainY",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainY);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainY.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainZ",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainZ);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainZ.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointMergeList,
    pOwner: this,
    pAttributeName: "jointMergeList",
    nFlags: 0);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointCollideList,
    pOwner: this,
    pAttributeName: "jointCollideList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E12E0
// Name: protected: void CDmeCollisionJoints::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::OnConstruction(CDmeCollisionJoints *this)
{
  CDmaVar<bool> *p_m_bConcavePerJoint; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bConcavePerJoint = &this->m_bConcavePerJoint;
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "concavePerJoint",
         type: AT_BOOL,
         pMemory: &this->m_bConcavePerJoint);
  p_m_bConcavePerJoint->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "selfCollisions",
         type: AT_BOOL,
         pMemory: &this->m_bSelfCollisions);
  this->m_bSelfCollisions.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "boneFollower",
         type: AT_BOOL,
         pMemory: &this->m_bBoneFollower);
  this->m_bBoneFollower.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_RootBone.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rootBone",
                                    type: AT_STRING,
                                    pMemory: &this->m_RootBone);
  this->m_AnimatedFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "animatedFriction",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_AnimatedFriction);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimatedFriction.m_pAttribute,
    typeSymbol: CDmeJointAnimatedFriction::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointSkipList,
    pOwner: this,
    pAttributeName: "jointSkipList",
    nFlags: 0);
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_JointList.m_pAttribute, typeSymbol: CDmeCollisionJoint::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E1480
// Name: public: virtual bool CDmeJointConstrain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointConstrain::IsA(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E14B0
// Name: public: virtual int CDmeJointConstrain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointConstrain::GetInheritanceDepth(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1560
// Name: protected: virtual void CDmeJointConstrain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::PerformConstruction(CDmeJointConstrain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointConstrain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E1600
// Name: public: virtual bool CDmeJointAnimatedFriction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointAnimatedFriction::IsA(CDmeJointAnimatedFriction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1630
// Name: public: virtual int CDmeJointAnimatedFriction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointAnimatedFriction::GetInheritanceDepth(
        CDmeJointAnimatedFriction *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E16E0
// Name: protected: virtual void CDmeJointAnimatedFriction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::PerformConstruction(CDmeJointAnimatedFriction *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointAnimatedFriction::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E17B0
// Name: protected: CDmeCollisionJoint::CDmeCollisionJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoint *__thiscall CDmeCollisionJoint::CDmeCollisionJoint(
        CDmeCollisionJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoint_vtbl *)&CDmeCollisionJoint::`vftable';
  this->m_flMassBias.m_Storage = 0.0;
  this->m_flMassBias.m_pAttribute = nullptr;
  this->m_flDamping = 0;
  this->m_flRotDamping = 0;
  this->m_flInertia = 0;
  this->m_ConstrainX.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainX.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainX.m_pAttribute = nullptr;
  this->m_ConstrainY.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainY.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainY.m_pAttribute = nullptr;
  this->m_ConstrainZ.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainZ.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainZ.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointMergeList);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointCollideList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E1840
// Name: public: virtual bool CDmeCollisionJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoint::IsA(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1870
// Name: public: virtual int CDmeCollisionJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::GetInheritanceDepth(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E18B0
// Name: protected: virtual int CDmeCollisionJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::AllocatedSize(CDmeCollisionJoint *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x004E18C0
// Name: protected: virtual void CDmeCollisionJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::PerformConstruction(CDmeCollisionJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E1920
// Name: protected: CDmeCollisionJoints::CDmeCollisionJoints(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoints *__thiscall CDmeCollisionJoints::CDmeCollisionJoints(
        CDmeCollisionJoints *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeCollisionModel::CDmeCollisionModel(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoints_vtbl *)&CDmeCollisionJoints::`vftable';
  this->m_bConcavePerJoint.m_pAttribute = nullptr;
  this->m_bConcavePerJoint.m_Storage = false;
  this->m_bSelfCollisions.m_pAttribute = nullptr;
  this->m_bSelfCollisions.m_Storage = false;
  this->m_bBoneFollower.m_pAttribute = nullptr;
  this->m_bBoneFollower.m_Storage = false;
  this->m_RootBone.m_Storage.u.m_Id = -1;
  this->m_RootBone.m_pAttribute = nullptr;
  this->m_AnimatedFriction.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_AnimatedFriction.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_AnimatedFriction.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointSkipList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E19B0
// Name: public: virtual bool CDmeCollisionJoints::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoints::IsA(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E19E0
// Name: public: virtual int CDmeCollisionJoints::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::GetInheritanceDepth(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1A40
// Name: protected: virtual int CDmeCollisionJoints::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::AllocatedSize(CDmeCollisionJoints *this)
{
  return 292;
}

//------------------------------------------------------------------------------
// Address: 0x004E1A50
// Name: protected: virtual void CDmeCollisionJoints::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::PerformConstruction(CDmeCollisionJoints *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
  CDmeCollisionJoints::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ED100
// Name: _dynamic_initializer_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointConstrain::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointConstrain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED160
// Name: _dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointAnimatedFriction::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointAnimatedFriction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1C0
// Name: _dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoint::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED220
// Name: _dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoints::s_Allocator,
    blockSize: 292,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoints pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3190
// Name: _dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointConstrain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F31A0
// Name: _dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointAnimatedFriction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F31B0
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F31C0
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoints::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED130
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointConstrain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED140
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointConstrain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointConstrain_Helper,
           classname: "DmeJointConstrain",
           pFactory: &g_CDmeJointConstrain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED190
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1A0
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointAnimatedFriction_Helper,
           classname: "DmeJointAnimatedFriction",
           pFactory: &g_CDmeJointAnimatedFriction_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1F0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED200
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoint_Helper,
           classname: "DmeCollisionJoint",
           pFactory: &g_CDmeCollisionJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED250
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoints_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED260
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoints_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoints_Helper,
           classname: "DmeCollisionJoints",
           pFactory: &g_CDmeCollisionJoints_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F31D0
// Name: _dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointAnimatedFriction_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F31E0
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F31F0
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoints_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3200
// Name: _dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointConstrain_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050D200
// Name: protected: void CDmeJointConstrain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnConstruction(CDmeJointConstrain *this)
{
  CDmaVar<int> *p_m_nType; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nType = &this->m_nType;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "type", type: AT_INT, pMemory: &this->m_nType);
  p_m_nType->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_aLimitMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "minAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMin);
  this->m_aLimitMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "maxAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMax);
  this->m_flFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "friction",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flFriction);
}

//------------------------------------------------------------------------------
// Address: 0x0050D280
// Name: private: virtual void CDmeJointConstrain::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnAttributeChanged(CDmeJointConstrain *this, CDmAttribute *pAttribute)
{
  CDmAttribute *m_pAttribute; // ecx
  int m_Storage; // eax

  m_pAttribute = this->m_nType.m_pAttribute;
  if ( pAttribute == m_pAttribute )
  {
    m_Storage = this->m_nType.m_Storage;
    if ( m_Storage >= 0 )
    {
      if ( m_Storage > 2 )
        m_Storage = 2;
      pAttribute = (CDmAttribute *)m_Storage;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (const int *)&pAttribute);
    }
    else
    {
      pAttribute = nullptr;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (const int *)&pAttribute);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050D2C0
// Name: protected: void CDmeJointAnimatedFriction::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::OnConstruction(CDmeJointAnimatedFriction *this)
{
  CDmaVar<int> *p_m_nMinFriction; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nMinFriction = &this->m_nMinFriction;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minFriction",
         type: AT_INT,
         pMemory: &this->m_nMinFriction);
  p_m_nMinFriction->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxFriction",
         type: AT_INT,
         pMemory: &this->m_nMaxFriction);
  this->m_nMaxFriction.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  this->m_tTimeIn.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "timeIn",
                                   type: AT_TIME,
                                   pMemory: &this->m_tTimeIn);
  this->m_tTimeHold.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "timeHold",
                                     type: AT_TIME,
                                     pMemory: &this->m_tTimeHold);
  this->m_tTimeOut.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "timeOut",
                                    type: AT_TIME,
                                    pMemory: &this->m_tTimeOut);
}

//------------------------------------------------------------------------------
// Address: 0x0050D360
// Name: protected: void CDmeCollisionJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::OnConstruction(CDmeCollisionJoint *this)
{
  CDmaVar<float> *p_m_flMassBias; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flMassBias = &this->m_flMassBias;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "massBias", type: AT_FLOAT, pMemory: &this->m_flMassBias);
  p_m_flMassBias->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotDamping);
  this->m_flRotDamping.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  this->m_ConstrainX.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainX",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainX);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainX.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainY.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainY",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainY);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainY.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainZ",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainZ);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainZ.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointMergeList,
    pOwner: this,
    pAttributeName: "jointMergeList",
    nFlags: 0);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointCollideList,
    pOwner: this,
    pAttributeName: "jointCollideList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0050D4C0
// Name: protected: void CDmeCollisionJoints::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::OnConstruction(CDmeCollisionJoints *this)
{
  CDmaVar<bool> *p_m_bConcavePerJoint; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bConcavePerJoint = &this->m_bConcavePerJoint;
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "concavePerJoint",
         type: AT_BOOL,
         pMemory: &this->m_bConcavePerJoint);
  p_m_bConcavePerJoint->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "selfCollisions",
         type: AT_BOOL,
         pMemory: &this->m_bSelfCollisions);
  this->m_bSelfCollisions.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "boneFollower",
         type: AT_BOOL,
         pMemory: &this->m_bBoneFollower);
  this->m_bBoneFollower.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_RootBone.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rootBone",
                                    type: AT_STRING,
                                    pMemory: &this->m_RootBone);
  this->m_AnimatedFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "animatedFriction",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_AnimatedFriction);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimatedFriction.m_pAttribute,
    typeSymbol: CDmeJointAnimatedFriction::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointSkipList,
    pOwner: this,
    pAttributeName: "jointSkipList",
    nFlags: 0);
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_JointList.m_pAttribute, typeSymbol: CDmeCollisionJoint::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0050D660
// Name: public: virtual bool CDmeJointConstrain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointConstrain::IsA(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D690
// Name: public: virtual int CDmeJointConstrain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointConstrain::GetInheritanceDepth(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D740
// Name: protected: virtual void CDmeJointConstrain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::PerformConstruction(CDmeJointConstrain *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeJointConstrain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050D7E0
// Name: public: virtual bool CDmeJointAnimatedFriction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointAnimatedFriction::IsA(CDmeJointAnimatedFriction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D810
// Name: public: virtual int CDmeJointAnimatedFriction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointAnimatedFriction::GetInheritanceDepth(
        CDmeJointAnimatedFriction *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D8C0
// Name: protected: virtual void CDmeJointAnimatedFriction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::PerformConstruction(CDmeJointAnimatedFriction *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeJointAnimatedFriction::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050D990
// Name: protected: CDmeCollisionJoint::CDmeCollisionJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoint *__thiscall CDmeCollisionJoint::CDmeCollisionJoint(
        CDmeCollisionJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoint_vtbl *)&CDmeCollisionJoint::`vftable';
  this->m_flMassBias.m_Storage = 0.0;
  this->m_flMassBias.m_pAttribute = nullptr;
  this->m_flDamping = 0;
  this->m_flRotDamping = 0;
  this->m_flInertia = 0;
  this->m_ConstrainX.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainX.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainX.m_pAttribute = nullptr;
  this->m_ConstrainY.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainY.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainY.m_pAttribute = nullptr;
  this->m_ConstrainZ.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainZ.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainZ.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointMergeList);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointCollideList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050DA20
// Name: public: virtual bool CDmeCollisionJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoint::IsA(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DA50
// Name: public: virtual int CDmeCollisionJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::GetInheritanceDepth(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DAA0
// Name: protected: virtual void CDmeCollisionJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::PerformConstruction(CDmeCollisionJoint *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeCollisionJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050DB00
// Name: protected: CDmeCollisionJoints::CDmeCollisionJoints(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoints *__thiscall CDmeCollisionJoints::CDmeCollisionJoints(
        CDmeCollisionJoints *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeCollisionModel::CDmeCollisionModel(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoints_vtbl *)&CDmeCollisionJoints::`vftable';
  this->m_bConcavePerJoint.m_pAttribute = nullptr;
  this->m_bConcavePerJoint.m_Storage = false;
  this->m_bSelfCollisions.m_pAttribute = nullptr;
  this->m_bSelfCollisions.m_Storage = false;
  this->m_bBoneFollower.m_pAttribute = nullptr;
  this->m_bBoneFollower.m_Storage = false;
  this->m_RootBone.m_Storage.u.m_Id = -1;
  this->m_RootBone.m_pAttribute = nullptr;
  this->m_AnimatedFriction.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_AnimatedFriction.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_AnimatedFriction.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointSkipList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050DB90
// Name: public: virtual bool CDmeCollisionJoints::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoints::IsA(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DBC0
// Name: public: virtual int CDmeCollisionJoints::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::GetInheritanceDepth(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DC10
// Name: protected: virtual int CDmeCollisionJoints::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::AllocatedSize(CDmeCollisionJoints *this)
{
  return 292;
}

//------------------------------------------------------------------------------
// Address: 0x0050DC20
// Name: protected: virtual void CDmeCollisionJoints::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::PerformConstruction(CDmeCollisionJoints *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeCollisionModel::OnConstruction(this);
  CDmeCollisionJoints::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006ACDA0
// Name: _dynamic_initializer_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointConstrain::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointConstrain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACE00
// Name: _dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointAnimatedFriction::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointAnimatedFriction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACE60
// Name: _dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoint::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACEC0
// Name: _dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoints::s_Allocator,
    blockSize: 292,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoints pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E10
// Name: _dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointConstrain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E20
// Name: _dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointAnimatedFriction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E30
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E40
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoints::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACDD0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointConstrain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACDE0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointConstrain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointConstrain_Helper,
           classname: "DmeJointConstrain",
           pFactory: &g_CDmeJointConstrain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ACE30
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACE40
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointAnimatedFriction_Helper,
           classname: "DmeJointAnimatedFriction",
           pFactory: &g_CDmeJointAnimatedFriction_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ACE90
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACEA0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoint_Helper,
           classname: "DmeCollisionJoint",
           pFactory: &g_CDmeCollisionJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ACEF0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoints_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACF00
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoints_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoints_Helper,
           classname: "DmeCollisionJoints",
           pFactory: &g_CDmeCollisionJoints_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E50
// Name: _dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeJointAnimatedFriction_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E60
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeCollisionJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E70
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeCollisionJoints_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E80
// Name: _dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeJointConstrain_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DCC70
// Name: protected: void CDmeJointConstrain::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnConstruction(CDmeJointConstrain *this)
{
  CDmaVar<int> *p_m_nType; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nType = &this->m_nType;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "type", type: AT_INT, pMemory: &this->m_nType);
  p_m_nType->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_aLimitMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "minAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMin);
  this->m_aLimitMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "maxAngle",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_aLimitMax);
  this->m_flFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "friction",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flFriction);
}

//------------------------------------------------------------------------------
// Address: 0x004DCCF0
// Name: private: virtual void CDmeJointConstrain::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::OnAttributeChanged(CDmeJointConstrain *this, CDmAttribute *pAttribute)
{
  CDmAttribute *m_pAttribute; // ecx
  int m_Storage; // eax

  m_pAttribute = this->m_nType.m_pAttribute;
  if ( pAttribute == m_pAttribute )
  {
    m_Storage = this->m_nType.m_Storage;
    if ( m_Storage >= 0 )
    {
      if ( m_Storage > 2 )
        m_Storage = 2;
      pAttribute = (CDmAttribute *)m_Storage;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
    else
    {
      pAttribute = nullptr;
      CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pAttribute);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DCD30
// Name: protected: void CDmeJointAnimatedFriction::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::OnConstruction(CDmeJointAnimatedFriction *this)
{
  CDmaVar<int> *p_m_nMinFriction; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nMinFriction = &this->m_nMinFriction;
  value = 1;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minFriction",
         type: AT_INT,
         pMemory: &this->m_nMinFriction);
  p_m_nMinFriction->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxFriction",
         type: AT_INT,
         pMemory: &this->m_nMaxFriction);
  this->m_nMaxFriction.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  this->m_tTimeIn.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "timeIn",
                                   type: AT_TIME,
                                   pMemory: &this->m_tTimeIn);
  this->m_tTimeHold.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "timeHold",
                                     type: AT_TIME,
                                     pMemory: &this->m_tTimeHold);
  this->m_tTimeOut.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "timeOut",
                                    type: AT_TIME,
                                    pMemory: &this->m_tTimeOut);
}

//------------------------------------------------------------------------------
// Address: 0x004DCDD0
// Name: protected: void CDmeCollisionJoint::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::OnConstruction(CDmeCollisionJoint *this)
{
  CDmaVar<float> *p_m_flMassBias; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flMassBias = &this->m_flMassBias;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "massBias", type: AT_FLOAT, pMemory: &this->m_flMassBias);
  p_m_flMassBias->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotDamping);
  this->m_flRotDamping.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  this->m_ConstrainX.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainX",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainX);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainX.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainY.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainY",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainY);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainY.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  this->m_ConstrainZ.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "constrainZ",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_ConstrainZ);
  CDmAttribute::SetElementTypeSymbol(this: this->m_ConstrainZ.m_pAttribute, typeSymbol: CDmeJointConstrain::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointMergeList,
    pOwner: this,
    pAttributeName: "jointMergeList",
    nFlags: 0);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointCollideList,
    pOwner: this,
    pAttributeName: "jointCollideList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004DCF30
// Name: protected: void CDmeCollisionJoints::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::OnConstruction(CDmeCollisionJoints *this)
{
  CDmaVar<bool> *p_m_bConcavePerJoint; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  p_m_bConcavePerJoint = &this->m_bConcavePerJoint;
  value = false;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "concavePerJoint",
         type: AT_BOOL,
         pMemory: &this->m_bConcavePerJoint);
  p_m_bConcavePerJoint->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "selfCollisions",
         type: AT_BOOL,
         pMemory: &this->m_bSelfCollisions);
  this->m_bSelfCollisions.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "boneFollower",
         type: AT_BOOL,
         pMemory: &this->m_bBoneFollower);
  this->m_bBoneFollower.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_RootBone.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "rootBone",
                                    type: AT_STRING,
                                    pMemory: &this->m_RootBone);
  this->m_AnimatedFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "animatedFriction",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_AnimatedFriction);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_AnimatedFriction.m_pAttribute,
    typeSymbol: CDmeJointAnimatedFriction::m_classType);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_JointSkipList,
    pOwner: this,
    pAttributeName: "jointSkipList",
    nFlags: 0);
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_JointList.m_pAttribute, typeSymbol: CDmeCollisionJoint::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004DD0D0
// Name: public: virtual bool CDmeJointConstrain::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointConstrain::IsA(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD100
// Name: public: virtual int CDmeJointConstrain::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointConstrain::GetInheritanceDepth(CDmeJointConstrain *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointConstrain::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD1B0
// Name: protected: virtual void CDmeJointConstrain::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointConstrain::PerformConstruction(CDmeJointConstrain *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointConstrain::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DD250
// Name: public: virtual bool CDmeJointAnimatedFriction::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJointAnimatedFriction::IsA(CDmeJointAnimatedFriction *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD280
// Name: public: virtual int CDmeJointAnimatedFriction::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJointAnimatedFriction::GetInheritanceDepth(
        CDmeJointAnimatedFriction *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJointAnimatedFriction::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD330
// Name: protected: virtual void CDmeJointAnimatedFriction::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJointAnimatedFriction::PerformConstruction(CDmeJointAnimatedFriction *this)
{
  CDmeFXClip::OnDestruction();
  CDmeJointAnimatedFriction::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DD400
// Name: protected: CDmeCollisionJoint::CDmeCollisionJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoint *__thiscall CDmeCollisionJoint::CDmeCollisionJoint(
        CDmeCollisionJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoint_vtbl *)&CDmeCollisionJoint::`vftable';
  this->m_flMassBias.m_Storage = 0.0;
  this->m_flMassBias.m_pAttribute = nullptr;
  this->m_flDamping = 0;
  this->m_flRotDamping = 0;
  this->m_flInertia = 0;
  this->m_ConstrainX.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainX.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainX.m_pAttribute = nullptr;
  this->m_ConstrainY.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainY.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainY.m_pAttribute = nullptr;
  this->m_ConstrainZ.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_ConstrainZ.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ConstrainZ.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointMergeList);
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointCollideList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DD490
// Name: public: virtual bool CDmeCollisionJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoint::IsA(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD4C0
// Name: public: virtual int CDmeCollisionJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::GetInheritanceDepth(CDmeCollisionJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoint::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD500
// Name: protected: virtual int CDmeCollisionJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoint::AllocatedSize(CDmeCollisionJoint *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x004DD510
// Name: protected: virtual void CDmeCollisionJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoint::PerformConstruction(CDmeCollisionJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DD570
// Name: protected: CDmeCollisionJoints::CDmeCollisionJoints(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionJoints *__thiscall CDmeCollisionJoints::CDmeCollisionJoints(
        CDmeCollisionJoints *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeCollisionModel::CDmeCollisionModel(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionJoints_vtbl *)&CDmeCollisionJoints::`vftable';
  this->m_bConcavePerJoint.m_pAttribute = nullptr;
  this->m_bConcavePerJoint.m_Storage = false;
  this->m_bSelfCollisions.m_pAttribute = nullptr;
  this->m_bSelfCollisions.m_Storage = false;
  this->m_bBoneFollower.m_pAttribute = nullptr;
  this->m_bBoneFollower.m_Storage = false;
  this->m_RootBone.m_Storage.u.m_Id = -1;
  this->m_RootBone.m_pAttribute = nullptr;
  this->m_AnimatedFriction.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_AnimatedFriction.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_AnimatedFriction.m_pAttribute = nullptr;
  CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>::CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataInternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&this->m_JointSkipList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DD600
// Name: public: virtual bool CDmeCollisionJoints::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionJoints::IsA(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD630
// Name: public: virtual int CDmeCollisionJoints::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::GetInheritanceDepth(CDmeCollisionJoints *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionJoints::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD680
// Name: protected: virtual int CDmeCollisionJoints::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionJoints::AllocatedSize(CDmeCollisionJoints *this)
{
  return 292;
}

//------------------------------------------------------------------------------
// Address: 0x004DD690
// Name: protected: virtual void CDmeCollisionJoints::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionJoints::PerformConstruction(CDmeCollisionJoints *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
  CDmeCollisionJoints::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E6470
// Name: _dynamic_initializer_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointConstrain::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointConstrain pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E64D0
// Name: _dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJointAnimatedFriction::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJointAnimatedFriction pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6530
// Name: _dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoint::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6590
// Name: _dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionJoints::s_Allocator,
    blockSize: 292,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionJoints pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1D0
// Name: _dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointConstrain::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointConstrain::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1E0
// Name: _dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJointAnimatedFriction::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJointAnimatedFriction::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1F0
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC200
// Name: _dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionJoints::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionJoints::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E64A0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointConstrain_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E64B0
// Name: _dynamic_initializer_for__g_CDmeJointConstrain_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointConstrain_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointConstrain_Helper,
           classname: "DmeJointConstrain",
           pFactory: &g_CDmeJointConstrain_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6500
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJointAnimatedFriction_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6510
// Name: _dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJointAnimatedFriction_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJointAnimatedFriction_Helper,
           classname: "DmeJointAnimatedFriction",
           pFactory: &g_CDmeJointAnimatedFriction_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6560
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6570
// Name: _dynamic_initializer_for__g_CDmeCollisionJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoint_Helper,
           classname: "DmeCollisionJoint",
           pFactory: &g_CDmeCollisionJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E65C0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionJoints_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E65D0
// Name: _dynamic_initializer_for__g_CDmeCollisionJoints_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionJoints_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionJoints_Helper,
           classname: "DmeCollisionJoints",
           pFactory: &g_CDmeCollisionJoints_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC210
// Name: _dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointAnimatedFriction_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointAnimatedFriction_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC220
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoint_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC230
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionJoints_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionJoints_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC240
// Name: _dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJointConstrain_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJointConstrain_Factory.m_CallBackList);
}

} // namespace studiomdl
