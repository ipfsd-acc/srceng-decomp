// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmejigglebone.cpp
// Functions: 12
// ============================================================

#include "mdlobjects\dmejigglebone.h"

//------------------------------------------------------------------------------
// Address: 0x004A6F90
// Name: protected: void CDmeJiggleBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::OnConstruction(CDmeJiggleBone *this)
{
  CDmaVar<bool> *p_m_bRigid; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  float v21; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_bRigid = &this->m_bRigid;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "rigid", type: AT_BOOL, pMemory: &this->m_bRigid);
  p_m_bRigid->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "flexible", type: AT_BOOL, pMemory: &this->m_bFlexible);
  this->m_bFlexible.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "baseSpring",
         type: AT_BOOL,
         pMemory: &this->m_bBaseSpring);
  this->m_bBaseSpring.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "yawConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bYawConstrained);
  this->m_bYawConstrained.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "pitchConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bPitchConstrained);
  this->m_bPitchConstrained.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  value = false;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "lengthConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bLengthConstrained);
  this->m_bLengthConstrained.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = false;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "angleConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bAngleConstrained);
  this->m_bAngleConstrained.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v21 = 10.0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "length", type: AT_FLOAT, pMemory: &this->m_flLength);
  this->m_flLength.m_pAttribute = v10;
  CDmAttribute::SetValue<float>(this: v10, value: &v21);
  this->m_flTipMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "tipMass",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flTipMass);
  this->m_flAngleLimit.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "angleLimit",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flAngleLimit);
  this->m_flYawMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMin",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMin);
  this->m_flYawMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMax",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMax);
  this->m_flYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "yawFriction",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flYawFriction);
  this->m_flYawBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "yawBounce",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flYawBounce);
  v21 = 100.0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "yawStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flYawStiffness);
  this->m_flYawStiffness.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: &v21);
  this->m_flYawDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "yawDamping",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flYawDamping);
  v21 = 100.0;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "pitchStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flPitchStiffness);
  this->m_flPitchStiffness.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: &v21);
  this->m_flPitchDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "pitchDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flPitchDamping);
  v21 = 100.0;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "alongStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flAlongStiffness);
  this->m_flAlongStiffness.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: &v21);
  this->m_flAlongDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "alongDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flAlongDamping);
  this->m_flPitchMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMin",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMin);
  this->m_flPitchMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMax",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMax);
  this->m_flPitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "pitchFriction",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flPitchFriction);
  this->m_flPitchBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "pitchBounce",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flPitchBounce);
  this->m_flBaseMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseMass",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flBaseMass);
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseStiffness);
  this->m_flBaseStiffness.m_pAttribute = v14;
  v14->m_nFlags |= 0x60u;
  this->m_flBaseDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "baseDamping",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flBaseDamping);
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMin);
  this->m_flBaseYawMin.m_pAttribute = v15;
  v15->m_nFlags |= 0xFF80u;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMax);
  this->m_flBaseYawMax.m_pAttribute = v16;
  v16->m_nFlags |= 0x60u;
  this->m_flBaseYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "baseYawFriction",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flBaseYawFriction);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMin);
  this->m_flBasePitchMin.m_pAttribute = v17;
  v17->m_nFlags |= 0xFF80u;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMax);
  this->m_flBasePitchMax.m_pAttribute = v18;
  v18->m_nFlags |= 0x60u;
  this->m_flBasePitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "basePitchFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBasePitchFriction);
  v19 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMin);
  this->m_flBaseAlongMin.m_pAttribute = v19;
  v19->m_nFlags |= 0xFF80u;
  v20 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMax);
  this->m_flBaseAlongMax.m_pAttribute = v20;
  v20->m_nFlags |= 0x60u;
  this->m_flBaseAlongFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "baseAlongFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBaseAlongFriction);
}

//------------------------------------------------------------------------------
// Address: 0x004A7460
// Name: protected: CDmeJiggleBone::CDmeJiggleBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJiggleBone *__thiscall CDmeJiggleBone::CDmeJiggleBone(
        CDmeJiggleBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeProceduralBone::CDmeProceduralBone(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJiggleBone_vtbl *)&CDmeJiggleBone::`vftable';
  this->m_bRigid.m_pAttribute = nullptr;
  this->m_bRigid.m_Storage = false;
  this->m_bFlexible.m_pAttribute = nullptr;
  this->m_bFlexible.m_Storage = false;
  this->m_bBaseSpring.m_pAttribute = nullptr;
  this->m_bBaseSpring.m_Storage = false;
  this->m_bYawConstrained.m_pAttribute = nullptr;
  this->m_bYawConstrained.m_Storage = false;
  this->m_bPitchConstrained.m_pAttribute = nullptr;
  this->m_bPitchConstrained.m_Storage = false;
  this->m_bLengthConstrained.m_pAttribute = nullptr;
  this->m_bLengthConstrained.m_Storage = false;
  this->m_bAngleConstrained.m_pAttribute = nullptr;
  this->m_bAngleConstrained.m_Storage = false;
  this->m_flLength = 0;
  this->m_flTipMass = 0;
  this->m_flAngleLimit = 0;
  this->m_flYawMin = 0;
  this->m_flYawMax = 0;
  this->m_flYawFriction = 0;
  this->m_flYawBounce = 0;
  this->m_flPitchMin = 0;
  this->m_flPitchMax = 0;
  this->m_flPitchFriction = 0;
  this->m_flPitchBounce = 0;
  this->m_flYawStiffness = 0;
  this->m_flYawDamping = 0;
  this->m_flPitchStiffness = 0;
  this->m_flPitchDamping = 0;
  this->m_flAlongStiffness = 0;
  this->m_flAlongDamping = 0;
  this->m_flBaseMass = 0;
  this->m_flBaseStiffness = 0;
  this->m_flBaseDamping = 0;
  this->m_flBaseYawMin = 0;
  this->m_flBaseYawMax = 0;
  this->m_flBaseYawFriction = 0;
  this->m_flBasePitchMin = 0;
  this->m_flBasePitchMax = 0;
  this->m_flBasePitchFriction = 0;
  this->m_flBaseAlongMin = 0;
  this->m_flBaseAlongMax = 0;
  this->m_flBaseAlongFriction = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A7680
// Name: public: virtual bool CDmeJiggleBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJiggleBone::IsA(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A76C0
// Name: public: virtual int CDmeJiggleBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::GetInheritanceDepth(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A7730
// Name: protected: virtual void CDmeJiggleBone::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformDestruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004A7750
// Name: protected: virtual int CDmeJiggleBone::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::AllocatedSize(CDmeJiggleBone *this)
{
  return 428;
}

//------------------------------------------------------------------------------
// Address: 0x004A7760
// Name: protected: virtual void CDmeJiggleBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformConstruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeJiggleBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059A200
// Name: _dynamic_initializer_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJiggleBone::s_Allocator,
    blockSize: 428,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJiggleBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E860
// Name: _dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJiggleBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A230
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJiggleBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A240
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJiggleBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJiggleBone_Helper,
           classname: "DmeJiggleBone",
           pFactory: &g_CDmeJiggleBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E870
// Name: _dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJiggleBone_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EAC10
// Name: protected: void CDmeJiggleBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::OnConstruction(CDmeJiggleBone *this)
{
  CDmaVar<bool> *p_m_bRigid; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  float v21; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_bRigid = &this->m_bRigid;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "rigid", type: AT_BOOL, pMemory: &this->m_bRigid);
  p_m_bRigid->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "flexible", type: AT_BOOL, pMemory: &this->m_bFlexible);
  this->m_bFlexible.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "baseSpring",
         type: AT_BOOL,
         pMemory: &this->m_bBaseSpring);
  this->m_bBaseSpring.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "yawConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bYawConstrained);
  this->m_bYawConstrained.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "pitchConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bPitchConstrained);
  this->m_bPitchConstrained.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  value = false;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "lengthConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bLengthConstrained);
  this->m_bLengthConstrained.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = false;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "angleConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bAngleConstrained);
  this->m_bAngleConstrained.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v21 = 10.0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "length", type: AT_FLOAT, pMemory: &this->m_flLength);
  this->m_flLength.m_pAttribute = v10;
  CDmAttribute::SetValue<float>(this: v10, value: &v21);
  this->m_flTipMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "tipMass",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flTipMass);
  this->m_flAngleLimit.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "angleLimit",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flAngleLimit);
  this->m_flYawMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMin",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMin);
  this->m_flYawMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMax",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMax);
  this->m_flYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "yawFriction",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flYawFriction);
  this->m_flYawBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "yawBounce",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flYawBounce);
  v21 = 100.0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "yawStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flYawStiffness);
  this->m_flYawStiffness.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: &v21);
  this->m_flYawDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "yawDamping",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flYawDamping);
  v21 = 100.0;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "pitchStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flPitchStiffness);
  this->m_flPitchStiffness.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: &v21);
  this->m_flPitchDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "pitchDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flPitchDamping);
  v21 = 100.0;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "alongStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flAlongStiffness);
  this->m_flAlongStiffness.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: &v21);
  this->m_flAlongDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "alongDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flAlongDamping);
  this->m_flPitchMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMin",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMin);
  this->m_flPitchMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMax",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMax);
  this->m_flPitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "pitchFriction",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flPitchFriction);
  this->m_flPitchBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "pitchBounce",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flPitchBounce);
  this->m_flBaseMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseMass",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flBaseMass);
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseStiffness);
  this->m_flBaseStiffness.m_pAttribute = v14;
  v14->m_nFlags |= 0x60u;
  this->m_flBaseDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "baseDamping",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flBaseDamping);
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMin);
  this->m_flBaseYawMin.m_pAttribute = v15;
  v15->m_nFlags |= 0xFF80u;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMax);
  this->m_flBaseYawMax.m_pAttribute = v16;
  v16->m_nFlags |= 0x60u;
  this->m_flBaseYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "baseYawFriction",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flBaseYawFriction);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMin);
  this->m_flBasePitchMin.m_pAttribute = v17;
  v17->m_nFlags |= 0xFF80u;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMax);
  this->m_flBasePitchMax.m_pAttribute = v18;
  v18->m_nFlags |= 0x60u;
  this->m_flBasePitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "basePitchFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBasePitchFriction);
  v19 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMin);
  this->m_flBaseAlongMin.m_pAttribute = v19;
  v19->m_nFlags |= 0xFF80u;
  v20 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMax);
  this->m_flBaseAlongMax.m_pAttribute = v20;
  v20->m_nFlags |= 0x60u;
  this->m_flBaseAlongFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "baseAlongFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBaseAlongFriction);
}

//------------------------------------------------------------------------------
// Address: 0x004EB0E0
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeSkinner *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EB0F0
// Name: public: virtual bool CDmeDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsA(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB120
// Name: public: virtual int CDmeDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::GetInheritanceDepth(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB1A0
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EB210
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004EB230
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB260
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB300
// Name: protected: CDmeProceduralBone::CDmeProceduralBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeProceduralBone *__thiscall CDmeProceduralBone::CDmeProceduralBone(
        CDmeProceduralBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeProceduralBone::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EB380
// Name: protected: virtual void CDmeProceduralBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeProceduralBone::PerformConstruction(CDmeProceduralBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004EB3A0
// Name: protected: virtual void CDmeJiggleBone::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformDestruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004EB3C0
// Name: public: virtual bool CDmeProceduralBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeProceduralBone::IsA(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB400
// Name: public: virtual int CDmeProceduralBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeProceduralBone::GetInheritanceDepth(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB4B0
// Name: protected: CDmeJiggleBone::CDmeJiggleBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJiggleBone *__thiscall CDmeJiggleBone::CDmeJiggleBone(
        CDmeJiggleBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeProceduralBone::CDmeProceduralBone(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJiggleBone_vtbl *)&CDmeJiggleBone::`vftable';
  this->m_bRigid.m_pAttribute = nullptr;
  this->m_bRigid.m_Storage = false;
  this->m_bFlexible.m_pAttribute = nullptr;
  this->m_bFlexible.m_Storage = false;
  this->m_bBaseSpring.m_pAttribute = nullptr;
  this->m_bBaseSpring.m_Storage = false;
  this->m_bYawConstrained.m_pAttribute = nullptr;
  this->m_bYawConstrained.m_Storage = false;
  this->m_bPitchConstrained.m_pAttribute = nullptr;
  this->m_bPitchConstrained.m_Storage = false;
  this->m_bLengthConstrained.m_pAttribute = nullptr;
  this->m_bLengthConstrained.m_Storage = false;
  this->m_bAngleConstrained.m_pAttribute = nullptr;
  this->m_bAngleConstrained.m_Storage = false;
  this->m_flLength = 0;
  this->m_flTipMass = 0;
  this->m_flAngleLimit = 0;
  this->m_flYawMin = 0;
  this->m_flYawMax = 0;
  this->m_flYawFriction = 0;
  this->m_flYawBounce = 0;
  this->m_flPitchMin = 0;
  this->m_flPitchMax = 0;
  this->m_flPitchFriction = 0;
  this->m_flPitchBounce = 0;
  this->m_flYawStiffness = 0;
  this->m_flYawDamping = 0;
  this->m_flPitchStiffness = 0;
  this->m_flPitchDamping = 0;
  this->m_flAlongStiffness = 0;
  this->m_flAlongDamping = 0;
  this->m_flBaseMass = 0;
  this->m_flBaseStiffness = 0;
  this->m_flBaseDamping = 0;
  this->m_flBaseYawMin = 0;
  this->m_flBaseYawMax = 0;
  this->m_flBaseYawFriction = 0;
  this->m_flBasePitchMin = 0;
  this->m_flBasePitchMax = 0;
  this->m_flBasePitchFriction = 0;
  this->m_flBaseAlongMin = 0;
  this->m_flBaseAlongMax = 0;
  this->m_flBaseAlongFriction = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EB6D0
// Name: public: virtual bool CDmeJiggleBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJiggleBone::IsA(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB710
// Name: public: virtual int CDmeJiggleBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::GetInheritanceDepth(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB780
// Name: protected: virtual int CDmeJiggleBone::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::AllocatedSize(CDmeJiggleBone *this)
{
  return 428;
}

//------------------------------------------------------------------------------
// Address: 0x004EB790
// Name: protected: virtual void CDmeJiggleBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformConstruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeJiggleBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AB1A0
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x005EE960
// Name: _dynamic_initializer_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJiggleBone::s_Allocator,
    blockSize: 428,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJiggleBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EED80
// Name: _dynamic_initializer_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeProceduralBone::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeProceduralBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF400
// Name: _dynamic_initializer_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDag::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF460
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0270
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F39B0
// Name: _dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJiggleBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B10
// Name: _dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeProceduralBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D30
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D40
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x005F4220
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE990
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJiggleBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE9A0
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJiggleBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJiggleBone_Helper,
           classname: "DmeJiggleBone",
           pFactory: &g_CDmeJiggleBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEDB0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeProceduralBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEDC0
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeProceduralBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeProceduralBone_Helper,
           classname: "DmeProceduralBone",
           pFactory: &g_CDmeProceduralBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF430
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF440
// Name: _dynamic_initializer_for__g_CDmeDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDag_Helper,
           classname: "DmeDag",
           pFactory: &g_CDmeDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F02A0
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F02B0
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F39C0
// Name: _dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJiggleBone_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B20
// Name: _dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeProceduralBone_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D50
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4230
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00516AC0
// Name: protected: void CDmeJiggleBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::OnConstruction(CDmeJiggleBone *this)
{
  CDmaVar<bool> *p_m_bRigid; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  float v21; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_bRigid = &this->m_bRigid;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "rigid", type: AT_BOOL, pMemory: &this->m_bRigid);
  p_m_bRigid->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "flexible", type: AT_BOOL, pMemory: &this->m_bFlexible);
  this->m_bFlexible.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "baseSpring",
         type: AT_BOOL,
         pMemory: &this->m_bBaseSpring);
  this->m_bBaseSpring.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "yawConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bYawConstrained);
  this->m_bYawConstrained.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "pitchConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bPitchConstrained);
  this->m_bPitchConstrained.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  value = false;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "lengthConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bLengthConstrained);
  this->m_bLengthConstrained.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = false;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "angleConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bAngleConstrained);
  this->m_bAngleConstrained.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v21 = 10.0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "length", type: AT_FLOAT, pMemory: &this->m_flLength);
  this->m_flLength.m_pAttribute = v10;
  CDmAttribute::SetValue<float>(this: v10, value: &v21);
  this->m_flTipMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "tipMass",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flTipMass);
  this->m_flAngleLimit.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "angleLimit",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flAngleLimit);
  this->m_flYawMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMin",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMin);
  this->m_flYawMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMax",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMax);
  this->m_flYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "yawFriction",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flYawFriction);
  this->m_flYawBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "yawBounce",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flYawBounce);
  v21 = 100.0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "yawStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flYawStiffness);
  this->m_flYawStiffness.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: &v21);
  this->m_flYawDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "yawDamping",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flYawDamping);
  v21 = 100.0;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "pitchStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flPitchStiffness);
  this->m_flPitchStiffness.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: &v21);
  this->m_flPitchDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "pitchDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flPitchDamping);
  v21 = 100.0;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "alongStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flAlongStiffness);
  this->m_flAlongStiffness.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: &v21);
  this->m_flAlongDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "alongDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flAlongDamping);
  this->m_flPitchMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMin",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMin);
  this->m_flPitchMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMax",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMax);
  this->m_flPitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "pitchFriction",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flPitchFriction);
  this->m_flPitchBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "pitchBounce",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flPitchBounce);
  this->m_flBaseMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseMass",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flBaseMass);
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseStiffness);
  this->m_flBaseStiffness.m_pAttribute = v14;
  v14->m_nFlags |= 0x60u;
  this->m_flBaseDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "baseDamping",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flBaseDamping);
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMin);
  this->m_flBaseYawMin.m_pAttribute = v15;
  v15->m_nFlags |= 0xFF80u;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMax);
  this->m_flBaseYawMax.m_pAttribute = v16;
  v16->m_nFlags |= 0x60u;
  this->m_flBaseYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "baseYawFriction",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flBaseYawFriction);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMin);
  this->m_flBasePitchMin.m_pAttribute = v17;
  v17->m_nFlags |= 0xFF80u;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMax);
  this->m_flBasePitchMax.m_pAttribute = v18;
  v18->m_nFlags |= 0x60u;
  this->m_flBasePitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "basePitchFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBasePitchFriction);
  v19 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMin);
  this->m_flBaseAlongMin.m_pAttribute = v19;
  v19->m_nFlags |= 0xFF80u;
  v20 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMax);
  this->m_flBaseAlongMax.m_pAttribute = v20;
  v20->m_nFlags |= 0x60u;
  this->m_flBaseAlongFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "baseAlongFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBaseAlongFriction);
}

//------------------------------------------------------------------------------
// Address: 0x00516F90
// Name: protected: CDmeJiggleBone::CDmeJiggleBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJiggleBone *__thiscall CDmeJiggleBone::CDmeJiggleBone(
        CDmeJiggleBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeProceduralBone::CDmeProceduralBone(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJiggleBone_vtbl *)&CDmeJiggleBone::`vftable';
  this->m_bRigid.m_pAttribute = nullptr;
  this->m_bRigid.m_Storage = false;
  this->m_bFlexible.m_pAttribute = nullptr;
  this->m_bFlexible.m_Storage = false;
  this->m_bBaseSpring.m_pAttribute = nullptr;
  this->m_bBaseSpring.m_Storage = false;
  this->m_bYawConstrained.m_pAttribute = nullptr;
  this->m_bYawConstrained.m_Storage = false;
  this->m_bPitchConstrained.m_pAttribute = nullptr;
  this->m_bPitchConstrained.m_Storage = false;
  this->m_bLengthConstrained.m_pAttribute = nullptr;
  this->m_bLengthConstrained.m_Storage = false;
  this->m_bAngleConstrained.m_pAttribute = nullptr;
  this->m_bAngleConstrained.m_Storage = false;
  this->m_flLength = 0;
  this->m_flTipMass = 0;
  this->m_flAngleLimit = 0;
  this->m_flYawMin = 0;
  this->m_flYawMax = 0;
  this->m_flYawFriction = 0;
  this->m_flYawBounce = 0;
  this->m_flPitchMin = 0;
  this->m_flPitchMax = 0;
  this->m_flPitchFriction = 0;
  this->m_flPitchBounce = 0;
  this->m_flYawStiffness = 0;
  this->m_flYawDamping = 0;
  this->m_flPitchStiffness = 0;
  this->m_flPitchDamping = 0;
  this->m_flAlongStiffness = 0;
  this->m_flAlongDamping = 0;
  this->m_flBaseMass = 0;
  this->m_flBaseStiffness = 0;
  this->m_flBaseDamping = 0;
  this->m_flBaseYawMin = 0;
  this->m_flBaseYawMax = 0;
  this->m_flBaseYawFriction = 0;
  this->m_flBasePitchMin = 0;
  this->m_flBasePitchMax = 0;
  this->m_flBasePitchFriction = 0;
  this->m_flBaseAlongMin = 0;
  this->m_flBaseAlongMax = 0;
  this->m_flBaseAlongFriction = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005171B0
// Name: public: virtual bool CDmeJiggleBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJiggleBone::IsA(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005171F0
// Name: public: virtual int CDmeJiggleBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::GetInheritanceDepth(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00517260
// Name: protected: virtual void CDmeJiggleBone::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformDestruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00517280
// Name: protected: virtual int CDmeJiggleBone::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::AllocatedSize(CDmeJiggleBone *this)
{
  return 428;
}

//------------------------------------------------------------------------------
// Address: 0x00517290
// Name: protected: virtual void CDmeJiggleBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformConstruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeJiggleBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE600
// Name: _dynamic_initializer_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJiggleBone::s_Allocator,
    blockSize: 428,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJiggleBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4630
// Name: _dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJiggleBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE630
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJiggleBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE640
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJiggleBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJiggleBone_Helper,
           classname: "DmeJiggleBone",
           pFactory: &g_CDmeJiggleBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4640
// Name: _dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeJiggleBone_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DA440
// Name: protected: void CDmeJiggleBone::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::OnConstruction(CDmeJiggleBone *this)
{
  CDmaVar<bool> *p_m_bRigid; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  float v21; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  p_m_bRigid = &this->m_bRigid;
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "rigid", type: AT_BOOL, pMemory: &this->m_bRigid);
  p_m_bRigid->m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "flexible", type: AT_BOOL, pMemory: &this->m_bFlexible);
  this->m_bFlexible.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "baseSpring",
         type: AT_BOOL,
         pMemory: &this->m_bBaseSpring);
  this->m_bBaseSpring.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "yawConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bYawConstrained);
  this->m_bYawConstrained.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "pitchConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bPitchConstrained);
  this->m_bPitchConstrained.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  value = false;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "lengthConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bLengthConstrained);
  this->m_bLengthConstrained.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, &value);
  value = false;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "angleConstrained",
         type: AT_BOOL,
         pMemory: &this->m_bAngleConstrained);
  this->m_bAngleConstrained.m_pAttribute = v9;
  CDmAttribute::SetValue<bool>(this: v9, &value);
  v21 = 10.0;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "length", type: AT_FLOAT, pMemory: &this->m_flLength);
  this->m_flLength.m_pAttribute = v10;
  CDmAttribute::SetValue<float>(this: v10, value: &v21);
  this->m_flTipMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "tipMass",
                                     type: AT_FLOAT,
                                     pMemory: &this->m_flTipMass);
  this->m_flAngleLimit.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "angleLimit",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flAngleLimit);
  this->m_flYawMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMin",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMin);
  this->m_flYawMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "yawMax",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flYawMax);
  this->m_flYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "yawFriction",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flYawFriction);
  this->m_flYawBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "yawBounce",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flYawBounce);
  v21 = 100.0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "yawStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flYawStiffness);
  this->m_flYawStiffness.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: &v21);
  this->m_flYawDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "yawDamping",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flYawDamping);
  v21 = 100.0;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "pitchStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flPitchStiffness);
  this->m_flPitchStiffness.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: &v21);
  this->m_flPitchDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "pitchDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flPitchDamping);
  v21 = 100.0;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "alongStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flAlongStiffness);
  this->m_flAlongStiffness.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: &v21);
  this->m_flAlongDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "alongDamping",
                                          type: AT_FLOAT,
                                          pMemory: &this->m_flAlongDamping);
  this->m_flPitchMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMin",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMin);
  this->m_flPitchMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "pitchMax",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flPitchMax);
  this->m_flPitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "pitchFriction",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flPitchFriction);
  this->m_flPitchBounce.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "pitchBounce",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flPitchBounce);
  this->m_flBaseMass.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseMass",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flBaseMass);
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseStiffness",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseStiffness);
  this->m_flBaseStiffness.m_pAttribute = v14;
  v14->m_nFlags |= 0x60u;
  this->m_flBaseDamping.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "baseDamping",
                                         type: AT_FLOAT,
                                         pMemory: &this->m_flBaseDamping);
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMin);
  this->m_flBaseYawMin.m_pAttribute = v15;
  v15->m_nFlags |= 0xFF80u;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseYawMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseYawMax);
  this->m_flBaseYawMax.m_pAttribute = v16;
  v16->m_nFlags |= 0x60u;
  this->m_flBaseYawFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                             this,
                                             pAttributeName: "baseYawFriction",
                                             type: AT_FLOAT,
                                             pMemory: &this->m_flBaseYawFriction);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMin);
  this->m_flBasePitchMin.m_pAttribute = v17;
  v17->m_nFlags |= 0xFF80u;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "basePitchMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBasePitchMax);
  this->m_flBasePitchMax.m_pAttribute = v18;
  v18->m_nFlags |= 0x60u;
  this->m_flBasePitchFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "basePitchFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBasePitchFriction);
  v19 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMin",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMin);
  this->m_flBaseAlongMin.m_pAttribute = v19;
  v19->m_nFlags |= 0xFF80u;
  v20 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "baseAlongMax",
          type: AT_FLOAT,
          pMemory: &this->m_flBaseAlongMax);
  this->m_flBaseAlongMax.m_pAttribute = v20;
  v20->m_nFlags |= 0x60u;
  this->m_flBaseAlongFriction.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "baseAlongFriction",
                                               type: AT_FLOAT,
                                               pMemory: &this->m_flBaseAlongFriction);
}

//------------------------------------------------------------------------------
// Address: 0x004DA910
// Name: public: virtual bool CDmeDag::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDag::IsA(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA940
// Name: public: virtual int CDmeDag::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDag::GetInheritanceDepth(CDmeDag *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA9D0
// Name: protected: CDmeJoint::CDmeJoint(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJoint *__thiscall CDmeJoint::CDmeJoint(
        CDmeJoint *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeJoint_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DAA40
// Name: protected: virtual void CDmeJoint::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJoint::PerformConstruction(CDmeJoint *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DAA60
// Name: public: virtual bool CDmeJoint::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJoint::IsA(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAA90
// Name: public: virtual int CDmeJoint::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::GetInheritanceDepth(CDmeJoint *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAB30
// Name: protected: CDmeProceduralBone::CDmeProceduralBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeProceduralBone *__thiscall CDmeProceduralBone::CDmeProceduralBone(
        CDmeProceduralBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeJoint::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_MatRefJoint,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->__vftable = (CDmeProceduralBone_vtbl *)&CDmeProceduralBone::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DABB0
// Name: protected: virtual void CDmeProceduralBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeProceduralBone::PerformConstruction(CDmeProceduralBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004DABD0
// Name: protected: virtual void CDmeJiggleBone::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformDestruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004DABF0
// Name: public: virtual bool CDmeProceduralBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeProceduralBone::IsA(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAC30
// Name: public: virtual int CDmeProceduralBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeProceduralBone::GetInheritanceDepth(CDmeProceduralBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DACE0
// Name: protected: CDmeJiggleBone::CDmeJiggleBone(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeJiggleBone *__thiscall CDmeJiggleBone::CDmeJiggleBone(
        CDmeJiggleBone *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeProceduralBone::CDmeProceduralBone(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeJiggleBone_vtbl *)&CDmeJiggleBone::`vftable';
  this->m_bRigid.m_pAttribute = nullptr;
  this->m_bRigid.m_Storage = false;
  this->m_bFlexible.m_pAttribute = nullptr;
  this->m_bFlexible.m_Storage = false;
  this->m_bBaseSpring.m_pAttribute = nullptr;
  this->m_bBaseSpring.m_Storage = false;
  this->m_bYawConstrained.m_pAttribute = nullptr;
  this->m_bYawConstrained.m_Storage = false;
  this->m_bPitchConstrained.m_pAttribute = nullptr;
  this->m_bPitchConstrained.m_Storage = false;
  this->m_bLengthConstrained.m_pAttribute = nullptr;
  this->m_bLengthConstrained.m_Storage = false;
  this->m_bAngleConstrained.m_pAttribute = nullptr;
  this->m_bAngleConstrained.m_Storage = false;
  this->m_flLength = 0;
  this->m_flTipMass = 0;
  this->m_flAngleLimit = 0;
  this->m_flYawMin = 0;
  this->m_flYawMax = 0;
  this->m_flYawFriction = 0;
  this->m_flYawBounce = 0;
  this->m_flPitchMin = 0;
  this->m_flPitchMax = 0;
  this->m_flPitchFriction = 0;
  this->m_flPitchBounce = 0;
  this->m_flYawStiffness = 0;
  this->m_flYawDamping = 0;
  this->m_flPitchStiffness = 0;
  this->m_flPitchDamping = 0;
  this->m_flAlongStiffness = 0;
  this->m_flAlongDamping = 0;
  this->m_flBaseMass = 0;
  this->m_flBaseStiffness = 0;
  this->m_flBaseDamping = 0;
  this->m_flBaseYawMin = 0;
  this->m_flBaseYawMax = 0;
  this->m_flBaseYawFriction = 0;
  this->m_flBasePitchMin = 0;
  this->m_flBasePitchMax = 0;
  this->m_flBasePitchFriction = 0;
  this->m_flBaseAlongMin = 0;
  this->m_flBaseAlongMax = 0;
  this->m_flBaseAlongFriction = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DAF00
// Name: public: virtual bool CDmeJiggleBone::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeJiggleBone::IsA(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAF40
// Name: public: virtual int CDmeJiggleBone::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::GetInheritanceDepth(CDmeJiggleBone *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeJiggleBone::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeProceduralBone::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeJoint::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DAFB0
// Name: protected: virtual int CDmeJiggleBone::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJiggleBone::AllocatedSize(CDmeJiggleBone *this)
{
  return 428;
}

//------------------------------------------------------------------------------
// Address: 0x004DAFC0
// Name: protected: virtual void CDmeJiggleBone::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeJiggleBone::PerformConstruction(CDmeJiggleBone *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeJoint::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeJiggleBone::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E4A90
// Name: protected: virtual void CDmeDag::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDag::PerformConstruction(CDmeSkinner *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E7640
// Name: protected: virtual int CDmeJoint::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeJoint::AllocatedSize(CDmeSingleIndexedComponent *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x005E5FF0
// Name: _dynamic_initializer_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJiggleBone::s_Allocator,
    blockSize: 428,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJiggleBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7C20
// Name: _dynamic_initializer_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeProceduralBone::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeProceduralBone pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E82A0
// Name: _dynamic_initializer_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDag::s_Allocator,
    blockSize: 136,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDag pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8300
// Name: _dynamic_initializer_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDag::s_TransformStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9110
// Name: _dynamic_initializer_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeJoint::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeJoint pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC050
// Name: _dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJiggleBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJiggleBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9B0
// Name: _dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeProceduralBone::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeProceduralBone::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBD0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDag::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBE0
// Name: _dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDag::s_TransformStack__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeDag::s_TransformStack);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0C0
// Name: _dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeJoint::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeJoint::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6020
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJiggleBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6030
// Name: _dynamic_initializer_for__g_CDmeJiggleBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJiggleBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJiggleBone_Helper,
           classname: "DmeJiggleBone",
           pFactory: &g_CDmeJiggleBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7C50
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeProceduralBone_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7C60
// Name: _dynamic_initializer_for__g_CDmeProceduralBone_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeProceduralBone_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeProceduralBone_Helper,
           classname: "DmeProceduralBone",
           pFactory: &g_CDmeProceduralBone_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E82D0
// Name: _dynamic_initializer_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDag_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDag_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E82E0
// Name: _dynamic_initializer_for__g_CDmeDag_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDag_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDag_Helper,
           classname: "DmeDag",
           pFactory: &g_CDmeDag_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9140
// Name: _dynamic_initializer_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeJoint_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeJoint_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9150
// Name: _dynamic_initializer_for__g_CDmeJoint_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeJoint_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeJoint_Helper,
           classname: "DmeJoint",
           pFactory: &g_CDmeJoint_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC060
// Name: _dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJiggleBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJiggleBone_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC9C0
// Name: _dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeProceduralBone_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeProceduralBone_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBF0
// Name: _dynamic_atexit_destructor_for__g_CDmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDag_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDag_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0D0
// Name: _dynamic_atexit_destructor_for__g_CDmeJoint_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeJoint_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeJoint_Factory.m_CallBackList);
}

} // namespace studiomdl
