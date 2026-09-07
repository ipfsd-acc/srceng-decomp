// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeanimcmd.cpp
// Functions: 129
// ============================================================

#include "mdlobjects\dmeanimcmd.h"

//------------------------------------------------------------------------------
// Address: 0x0049EE30
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
// Address: 0x0049FD50
// Name: protected: void CDmeAnimCmdLocalHierarchy::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::OnConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_flStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "startFrame",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flStartFrame);
  this->m_flPeakFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "peakFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flPeakFrame);
  this->m_flTailFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "tailFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flTailFrame);
  this->m_flEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "endFrame",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0049FDE0
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
// Address: 0x0049FE80
// Name: protected: void CDmeAnimCmdAlign::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::OnConstruction(CDmeAnimCmdAlign *this)
{
  CDmaElement<CDmeSequenceBase> *p_m_eAnimation; // edi

  p_m_eAnimation = &this->m_eAnimation;
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eAnimation->m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  p_m_eAnimation->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_nSourceFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sourceFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nSourceFrame);
  this->m_nDestinatonFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "destinationFrame",
                                            type: AT_INT,
                                            pMemory: &this->m_nDestinatonFrame);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0049FFF0
// Name: public: virtual bool CDmeAnimCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmd::IsA(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0020
// Name: public: virtual int CDmeAnimCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmd::GetInheritanceDepth(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A00F0
// Name: public: virtual bool CDmeAnimCmdFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdFixupLoop::IsA(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0120
// Name: public: virtual int CDmeAnimCmdFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdFixupLoop::GetInheritanceDepth(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A01E0
// Name: protected: virtual void CDmeAnimCmdFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdFixupLoop::PerformConstruction(CDmeAnimCmdFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
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
}

//------------------------------------------------------------------------------
// Address: 0x004A02B0
// Name: public: virtual bool CDmeAnimCmdWeightList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWeightList::IsA(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A02E0
// Name: public: virtual int CDmeAnimCmdWeightList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWeightList::GetInheritanceDepth(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0330
// Name: protected: virtual void CDmeAnimCmdWeightList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWeightList::PerformConstruction(CDmeAnimCmdWeightList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sWeightListName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "weightListName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sWeightListName);
}

//------------------------------------------------------------------------------
// Address: 0x004A0450
// Name: public: virtual bool CDmeAnimCmdSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSubtract::IsA(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0480
// Name: public: virtual int CDmeAnimCmdSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSubtract::GetInheritanceDepth(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0540
// Name: protected: virtual void CDmeAnimCmdPreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdPreSubtract::PerformConstruction(CDmeAnimCmdPreSubtract *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eAnimation.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004A0630
// Name: public: virtual bool CDmeAnimCmdPreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdPreSubtract::IsA(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0670
// Name: public: virtual int CDmeAnimCmdPreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::GetInheritanceDepth(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A07D0
// Name: public: virtual bool CDmeAnimCmdAlign::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdAlign::IsA(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0800
// Name: public: virtual int CDmeAnimCmdAlign::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdAlign::GetInheritanceDepth(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A08D0
// Name: protected: virtual void CDmeAnimCmdAlign::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::PerformConstruction(CDmeAnimCmdAlign *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdAlign::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A0970
// Name: public: virtual bool CDmeAnimCmdRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdRotateTo::IsA(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A09A0
// Name: public: virtual int CDmeAnimCmdRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdRotateTo::GetInheritanceDepth(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0A50
// Name: protected: virtual void CDmeAnimCmdRotateTo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdRotateTo::PerformConstruction(CDmeAnimCmdRotateTo *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "angle",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flAngle);
}

//------------------------------------------------------------------------------
// Address: 0x004A0B10
// Name: public: virtual bool CDmeAnimCmdWalkFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWalkFrame::IsA(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0B40
// Name: public: virtual int CDmeAnimCmdWalkFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWalkFrame::GetInheritanceDepth(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0B90
// Name: protected: virtual int CDmeAnimCmdPreSubtract::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x004A0C10
// Name: protected: virtual void CDmeAnimCmdWalkFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWalkFrame::PerformConstruction(CDmeAnimCmdWalkFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004A0CE0
// Name: public: virtual bool CDmeAnimCmdDerivative::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdDerivative::IsA(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0D10
// Name: public: virtual int CDmeAnimCmdDerivative::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdDerivative::GetInheritanceDepth(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0DC0
// Name: protected: virtual void CDmeAnimCmdDerivative::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdDerivative::PerformConstruction(CDmeAnimCmdDerivative *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004A0EE0
// Name: public: virtual bool CDmeAnimCmdLinearDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLinearDelta::IsA(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A0F10
// Name: public: virtual int CDmeAnimCmdLinearDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLinearDelta::GetInheritanceDepth(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1040
// Name: public: virtual bool CDmeAnimCmdSplineDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSplineDelta::IsA(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1070
// Name: public: virtual int CDmeAnimCmdSplineDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSplineDelta::GetInheritanceDepth(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1150
// Name: public: virtual bool CDmeAnimCmdCompress::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdCompress::IsA(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1180
// Name: public: virtual int CDmeAnimCmdCompress::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdCompress::GetInheritanceDepth(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1230
// Name: protected: virtual void CDmeAnimCmdCompress::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdCompress::PerformConstruction(CDmeAnimCmdCompress *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nSkipFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "skipFrames",
                                       type: AT_INT,
                                       pMemory: &this->m_nSkipFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004A12F0
// Name: public: virtual bool CDmeAnimCmdNumFrames::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNumFrames::IsA(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1320
// Name: public: virtual int CDmeAnimCmdNumFrames::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNumFrames::GetInheritanceDepth(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A13D0
// Name: protected: virtual void CDmeAnimCmdNumFrames::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNumFrames::PerformConstruction(CDmeAnimCmdNumFrames *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "frames",
                                   type: AT_INT,
                                   pMemory: &this->m_nFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004A1490
// Name: public: virtual bool CDmeAnimCmdLocalHierarchy::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLocalHierarchy::IsA(CDmeAnimCmdLocalHierarchy *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A14C0
// Name: public: virtual int CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(
        CDmeAnimCmdLocalHierarchy *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A15A0
// Name: protected: virtual void CDmeAnimCmdLocalHierarchy::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::PerformConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdLocalHierarchy::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A1640
// Name: public: virtual bool CDmeAnimCmdNoAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNoAnimation::IsA(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1670
// Name: public: virtual int CDmeAnimCmdNoAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNoAnimation::GetInheritanceDepth(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A1730
// Name: protected: virtual void CDmeAnimCmdNoAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNoAnimation::PerformConstruction(CDmeAnimCmdNoAnimation *this)
{
  CDmeFXClip::OnDestruction();
  this->m_bNullAttr.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "nullAttr",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bNullAttr);
}

//------------------------------------------------------------------------------
// Address: 0x004A1830
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
// Address: 0x004A7890
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
// Address: 0x004B58A0
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
// Address: 0x004BC5F0
// Name: protected: virtual int CDmeAnimCmdLocalHierarchy::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::AllocatedSize(CDmeConstraintSlave *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x004BD460
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
// Address: 0x0055F3A0
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
// Address: 0x00560A60
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
// Address: 0x005682F0
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
// Address: 0x00599060
// Name: _dynamic_initializer_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005990C0
// Name: _dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599120
// Name: _dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWeightList::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWeightList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599180
// Name: _dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005991E0
// Name: _dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdPreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdPreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599240
// Name: _dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdAlign::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdAlign pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005992A0
// Name: _dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599300
// Name: _dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWalkFrame::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWalkFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599360
// Name: _dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdDerivative::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdDerivative pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005993C0
// Name: _dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLinearDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLinearDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599420
// Name: _dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSplineDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSplineDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599480
// Name: _dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdCompress::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdCompress pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005994E0
// Name: _dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNumFrames::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNumFrames pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599540
// Name: _dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLocalHierarchy::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLocalHierarchy pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005995A0
// Name: _dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNoAnimation::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNoAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E280
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E290
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2A0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWeightList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2B0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2C0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdPreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2D0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdAlign::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2E0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E2F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWalkFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E300
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdDerivative::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E310
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLinearDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E320
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSplineDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E330
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdCompress::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E340
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNumFrames::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E350
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLocalHierarchy::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E360
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNoAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599090
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005990A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmd_Helper,
           classname: "DmeAnimCmd",
           pFactory: &g_CDmeAnimCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005990F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599100
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdFixupLoop_Helper,
           classname: "DmeAnimCmdFixupLoop",
           pFactory: &g_CDmeAnimCmdFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599150
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599160
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWeightList_Helper,
           classname: "DmeAnimCmdWeightList",
           pFactory: &g_CDmeAnimCmdWeightList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005991B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005991C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSubtract_Helper,
           classname: "DmeAnimCmdSubtract",
           pFactory: &g_CDmeAnimCmdSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599210
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599220
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdPreSubtract_Helper,
           classname: "DmeAnimCmdPreSubtract",
           pFactory: &g_CDmeAnimCmdPreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599270
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599280
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdAlign_Helper,
           classname: "DmeAnimCmdAlign",
           pFactory: &g_CDmeAnimCmdAlign_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005992D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005992E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdRotateTo_Helper,
           classname: "DmeAnimCmdRotateTo",
           pFactory: &g_CDmeAnimCmdRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599330
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599340
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWalkFrame_Helper,
           classname: "DmeAnimCmdWalkFrame",
           pFactory: &g_CDmeAnimCmdWalkFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599390
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005993A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdDerivative_Helper,
           classname: "DmeAnimCmdDerivative",
           pFactory: &g_CDmeAnimCmdDerivative_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005993F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599400
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLinearDelta_Helper,
           classname: "DmeAnimCmdLinearDelta",
           pFactory: &g_CDmeAnimCmdLinearDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599450
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599460
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSplineDelta_Helper,
           classname: "DmeAnimCmdSplineDelta",
           pFactory: &g_CDmeAnimCmdSplineDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005994B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005994C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdCompress_Helper,
           classname: "DmeAnimCmdCompress",
           pFactory: &g_CDmeAnimCmdCompress_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599510
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599520
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNumFrames_Helper,
           classname: "DmeAnimCmdNumFrames",
           pFactory: &g_CDmeAnimCmdNumFrames_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599570
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599580
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLocalHierarchy_Helper,
           classname: "DmeAnimCmdLocalHierarchy",
           pFactory: &g_CDmeAnimCmdLocalHierarchy_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005995D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005995E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNoAnimation_Helper,
           classname: "DmeAnimCmdNoAnimation",
           pFactory: &g_CDmeAnimCmdNoAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E370
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E380
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWeightList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E390
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3A0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdPreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3B0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdAlign_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3D0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWalkFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdDerivative_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E3F0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLinearDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E400
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSplineDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E410
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdCompress_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E420
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNumFrames_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E430
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLocalHierarchy_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E440
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNoAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E450
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmd_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E8500
// Name: protected: void CDmeAnimCmdLocalHierarchy::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::OnConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_flStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "startFrame",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flStartFrame);
  this->m_flPeakFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "peakFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flPeakFrame);
  this->m_flTailFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "tailFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flTailFrame);
  this->m_flEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "endFrame",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004E8590
// Name: protected: void CDmeAnimCmdAlign::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::OnConstruction(CDmeAnimCmdAlign *this)
{
  CDmaElement<CDmeSequenceBase> *p_m_eAnimation; // edi

  p_m_eAnimation = &this->m_eAnimation;
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eAnimation->m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  p_m_eAnimation->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_nSourceFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sourceFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nSourceFrame);
  this->m_nDestinatonFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "destinationFrame",
                                            type: AT_INT,
                                            pMemory: &this->m_nDestinatonFrame);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E8700
// Name: public: virtual bool CDmeAnimCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmd::IsA(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8730
// Name: public: virtual int CDmeAnimCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmd::GetInheritanceDepth(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8800
// Name: public: virtual bool CDmeAnimCmdFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdFixupLoop::IsA(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8830
// Name: public: virtual int CDmeAnimCmdFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdFixupLoop::GetInheritanceDepth(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E88E0
// Name: protected: virtual void CDmeAnimCmdFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdFixupLoop::PerformConstruction(CDmeAnimCmdFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
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
}

//------------------------------------------------------------------------------
// Address: 0x004E89B0
// Name: public: virtual bool CDmeAnimCmdWeightList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWeightList::IsA(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E89E0
// Name: public: virtual int CDmeAnimCmdWeightList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWeightList::GetInheritanceDepth(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8A30
// Name: protected: virtual void CDmeAnimCmdWeightList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWeightList::PerformConstruction(CDmeAnimCmdWeightList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sWeightListName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "weightListName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sWeightListName);
}

//------------------------------------------------------------------------------
// Address: 0x004E8B50
// Name: public: virtual bool CDmeAnimCmdSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSubtract::IsA(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8B80
// Name: public: virtual int CDmeAnimCmdSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSubtract::GetInheritanceDepth(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8C40
// Name: protected: virtual void CDmeAnimCmdPreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdPreSubtract::PerformConstruction(CDmeAnimCmdPreSubtract *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eAnimation.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004E8D30
// Name: public: virtual bool CDmeAnimCmdPreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdPreSubtract::IsA(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8D70
// Name: public: virtual int CDmeAnimCmdPreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::GetInheritanceDepth(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8DD0
// Name: protected: virtual int CDmeAnimCmdPreSubtract::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x004E8EE0
// Name: public: virtual bool CDmeAnimCmdAlign::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdAlign::IsA(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8F10
// Name: public: virtual int CDmeAnimCmdAlign::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdAlign::GetInheritanceDepth(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8F60
// Name: protected: virtual int CDmeAnimCmdLocalHierarchy::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::AllocatedSize(CDmeConstraintSlave *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x004E8FF0
// Name: protected: virtual void CDmeAnimCmdAlign::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::PerformConstruction(CDmeAnimCmdAlign *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdAlign::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E9090
// Name: public: virtual bool CDmeAnimCmdRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdRotateTo::IsA(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E90C0
// Name: public: virtual int CDmeAnimCmdRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdRotateTo::GetInheritanceDepth(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9170
// Name: protected: virtual void CDmeAnimCmdRotateTo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdRotateTo::PerformConstruction(CDmeAnimCmdRotateTo *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "angle",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flAngle);
}

//------------------------------------------------------------------------------
// Address: 0x004E9230
// Name: public: virtual bool CDmeAnimCmdWalkFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWalkFrame::IsA(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9260
// Name: public: virtual int CDmeAnimCmdWalkFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWalkFrame::GetInheritanceDepth(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9320
// Name: protected: virtual void CDmeAnimCmdWalkFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWalkFrame::PerformConstruction(CDmeAnimCmdWalkFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004E93F0
// Name: public: virtual bool CDmeAnimCmdDerivative::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdDerivative::IsA(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9420
// Name: public: virtual int CDmeAnimCmdDerivative::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdDerivative::GetInheritanceDepth(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E94D0
// Name: protected: virtual void CDmeAnimCmdDerivative::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdDerivative::PerformConstruction(CDmeAnimCmdDerivative *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E95F0
// Name: public: virtual bool CDmeAnimCmdLinearDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLinearDelta::IsA(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9620
// Name: public: virtual int CDmeAnimCmdLinearDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLinearDelta::GetInheritanceDepth(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9750
// Name: public: virtual bool CDmeAnimCmdSplineDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSplineDelta::IsA(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9780
// Name: public: virtual int CDmeAnimCmdSplineDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSplineDelta::GetInheritanceDepth(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9860
// Name: public: virtual bool CDmeAnimCmdCompress::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdCompress::IsA(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9890
// Name: public: virtual int CDmeAnimCmdCompress::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdCompress::GetInheritanceDepth(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9940
// Name: protected: virtual void CDmeAnimCmdCompress::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdCompress::PerformConstruction(CDmeAnimCmdCompress *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nSkipFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "skipFrames",
                                       type: AT_INT,
                                       pMemory: &this->m_nSkipFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004E9A00
// Name: public: virtual bool CDmeAnimCmdNumFrames::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNumFrames::IsA(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9A30
// Name: public: virtual int CDmeAnimCmdNumFrames::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNumFrames::GetInheritanceDepth(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9AE0
// Name: protected: virtual void CDmeAnimCmdNumFrames::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNumFrames::PerformConstruction(CDmeAnimCmdNumFrames *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "frames",
                                   type: AT_INT,
                                   pMemory: &this->m_nFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004E9BA0
// Name: public: virtual bool CDmeAnimCmdLocalHierarchy::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLocalHierarchy::IsA(CDmeAnimCmdLocalHierarchy *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9BD0
// Name: public: virtual int CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(
        CDmeAnimCmdLocalHierarchy *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9CB0
// Name: protected: virtual void CDmeAnimCmdLocalHierarchy::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::PerformConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdLocalHierarchy::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E9D50
// Name: public: virtual bool CDmeAnimCmdNoAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNoAnimation::IsA(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9D80
// Name: public: virtual int CDmeAnimCmdNoAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNoAnimation::GetInheritanceDepth(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9E30
// Name: protected: virtual void CDmeAnimCmdNoAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNoAnimation::PerformConstruction(CDmeAnimCmdNoAnimation *this)
{
  CDmeFXClip::OnDestruction();
  this->m_bNullAttr.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "nullAttr",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bNullAttr);
}

//------------------------------------------------------------------------------
// Address: 0x005EE180
// Name: _dynamic_initializer_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE1E0
// Name: _dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE240
// Name: _dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWeightList::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWeightList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE2A0
// Name: _dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE300
// Name: _dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdPreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdPreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE360
// Name: _dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdAlign::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdAlign pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE3C0
// Name: _dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE420
// Name: _dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWalkFrame::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWalkFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE480
// Name: _dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdDerivative::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdDerivative pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE4E0
// Name: _dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLinearDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLinearDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE540
// Name: _dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSplineDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSplineDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE5A0
// Name: _dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdCompress::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdCompress pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE600
// Name: _dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNumFrames::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNumFrames pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE660
// Name: _dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLocalHierarchy::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLocalHierarchy pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE6C0
// Name: _dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNoAnimation::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNoAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3710
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3720
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3730
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWeightList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3740
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3750
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdPreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3760
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdAlign::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3770
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3780
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWalkFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3790
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdDerivative::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37A0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLinearDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37B0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSplineDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37C0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdCompress::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37D0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNumFrames::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37E0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLocalHierarchy::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F37F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNoAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE1B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE1C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmd_Helper,
           classname: "DmeAnimCmd",
           pFactory: &g_CDmeAnimCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE210
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE220
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdFixupLoop_Helper,
           classname: "DmeAnimCmdFixupLoop",
           pFactory: &g_CDmeAnimCmdFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE270
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE280
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWeightList_Helper,
           classname: "DmeAnimCmdWeightList",
           pFactory: &g_CDmeAnimCmdWeightList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE2D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE2E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSubtract_Helper,
           classname: "DmeAnimCmdSubtract",
           pFactory: &g_CDmeAnimCmdSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE330
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE340
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdPreSubtract_Helper,
           classname: "DmeAnimCmdPreSubtract",
           pFactory: &g_CDmeAnimCmdPreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE390
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE3A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdAlign_Helper,
           classname: "DmeAnimCmdAlign",
           pFactory: &g_CDmeAnimCmdAlign_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE3F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE400
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdRotateTo_Helper,
           classname: "DmeAnimCmdRotateTo",
           pFactory: &g_CDmeAnimCmdRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE450
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE460
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWalkFrame_Helper,
           classname: "DmeAnimCmdWalkFrame",
           pFactory: &g_CDmeAnimCmdWalkFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE4B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE4C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdDerivative_Helper,
           classname: "DmeAnimCmdDerivative",
           pFactory: &g_CDmeAnimCmdDerivative_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE510
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE520
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLinearDelta_Helper,
           classname: "DmeAnimCmdLinearDelta",
           pFactory: &g_CDmeAnimCmdLinearDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE570
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE580
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSplineDelta_Helper,
           classname: "DmeAnimCmdSplineDelta",
           pFactory: &g_CDmeAnimCmdSplineDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE5D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE5E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdCompress_Helper,
           classname: "DmeAnimCmdCompress",
           pFactory: &g_CDmeAnimCmdCompress_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE630
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE640
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNumFrames_Helper,
           classname: "DmeAnimCmdNumFrames",
           pFactory: &g_CDmeAnimCmdNumFrames_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE690
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE6A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLocalHierarchy_Helper,
           classname: "DmeAnimCmdLocalHierarchy",
           pFactory: &g_CDmeAnimCmdLocalHierarchy_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EE6F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE700
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNoAnimation_Helper,
           classname: "DmeAnimCmdNoAnimation",
           pFactory: &g_CDmeAnimCmdNoAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3800
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3810
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWeightList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3820
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3830
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdPreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3840
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdAlign_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3850
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3860
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWalkFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3870
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdDerivative_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3880
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLinearDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3890
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSplineDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F38A0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdCompress_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F38B0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNumFrames_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F38C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLocalHierarchy_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F38D0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNoAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F38E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmd_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E9D0
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
// Address: 0x0050F8E0
// Name: protected: void CDmeAnimCmdLocalHierarchy::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::OnConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_flStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "startFrame",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flStartFrame);
  this->m_flPeakFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "peakFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flPeakFrame);
  this->m_flTailFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "tailFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flTailFrame);
  this->m_flEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "endFrame",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x0050F970
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
// Address: 0x0050FA10
// Name: protected: void CDmeAnimCmdAlign::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::OnConstruction(CDmeAnimCmdAlign *this)
{
  CDmaElement<CDmeSequenceBase> *p_m_eAnimation; // edi

  p_m_eAnimation = &this->m_eAnimation;
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eAnimation->m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  p_m_eAnimation->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_nSourceFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sourceFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nSourceFrame);
  this->m_nDestinatonFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "destinationFrame",
                                            type: AT_INT,
                                            pMemory: &this->m_nDestinatonFrame);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0050FB80
// Name: public: virtual bool CDmeAnimCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmd::IsA(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FBB0
// Name: public: virtual int CDmeAnimCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmd::GetInheritanceDepth(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FC80
// Name: public: virtual bool CDmeAnimCmdFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdFixupLoop::IsA(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FCB0
// Name: public: virtual int CDmeAnimCmdFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdFixupLoop::GetInheritanceDepth(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FD70
// Name: protected: virtual void CDmeAnimCmdFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdFixupLoop::PerformConstruction(CDmeAnimCmdFixupLoop *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
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
}

//------------------------------------------------------------------------------
// Address: 0x0050FE40
// Name: public: virtual bool CDmeAnimCmdWeightList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWeightList::IsA(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FE70
// Name: public: virtual int CDmeAnimCmdWeightList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWeightList::GetInheritanceDepth(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FEC0
// Name: protected: virtual void CDmeAnimCmdWeightList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWeightList::PerformConstruction(CDmeAnimCmdWeightList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_sWeightListName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "weightListName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sWeightListName);
}

//------------------------------------------------------------------------------
// Address: 0x0050FFE0
// Name: public: virtual bool CDmeAnimCmdSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSubtract::IsA(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510010
// Name: public: virtual int CDmeAnimCmdSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSubtract::GetInheritanceDepth(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510060
// Name: protected: virtual int CDmeAnimCmdPreSubtract::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x005100E0
// Name: protected: virtual void CDmeAnimCmdPreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdPreSubtract::PerformConstruction(CDmeAnimCmdPreSubtract *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eAnimation.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x005101D0
// Name: public: virtual bool CDmeAnimCmdPreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdPreSubtract::IsA(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510210
// Name: public: virtual int CDmeAnimCmdPreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::GetInheritanceDepth(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510370
// Name: public: virtual bool CDmeAnimCmdAlign::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdAlign::IsA(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005103A0
// Name: public: virtual int CDmeAnimCmdAlign::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdAlign::GetInheritanceDepth(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510470
// Name: protected: virtual void CDmeAnimCmdAlign::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::PerformConstruction(CDmeAnimCmdAlign *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAnimCmdAlign::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00510510
// Name: public: virtual bool CDmeAnimCmdRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdRotateTo::IsA(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510540
// Name: public: virtual int CDmeAnimCmdRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdRotateTo::GetInheritanceDepth(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005105F0
// Name: protected: virtual void CDmeAnimCmdRotateTo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdRotateTo::PerformConstruction(CDmeAnimCmdRotateTo *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_flAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "angle",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flAngle);
}

//------------------------------------------------------------------------------
// Address: 0x005106B0
// Name: public: virtual bool CDmeAnimCmdWalkFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWalkFrame::IsA(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005106E0
// Name: public: virtual int CDmeAnimCmdWalkFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWalkFrame::GetInheritanceDepth(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005107A0
// Name: protected: virtual void CDmeAnimCmdWalkFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWalkFrame::PerformConstruction(CDmeAnimCmdWalkFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x00510870
// Name: public: virtual bool CDmeAnimCmdDerivative::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdDerivative::IsA(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005108A0
// Name: public: virtual int CDmeAnimCmdDerivative::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdDerivative::GetInheritanceDepth(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510950
// Name: protected: virtual void CDmeAnimCmdDerivative::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdDerivative::PerformConstruction(CDmeAnimCmdDerivative *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00510A70
// Name: public: virtual bool CDmeAnimCmdLinearDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLinearDelta::IsA(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510AA0
// Name: public: virtual int CDmeAnimCmdLinearDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLinearDelta::GetInheritanceDepth(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510BD0
// Name: public: virtual bool CDmeAnimCmdSplineDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSplineDelta::IsA(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510C00
// Name: public: virtual int CDmeAnimCmdSplineDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSplineDelta::GetInheritanceDepth(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510CE0
// Name: public: virtual bool CDmeAnimCmdCompress::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdCompress::IsA(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510D10
// Name: public: virtual int CDmeAnimCmdCompress::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdCompress::GetInheritanceDepth(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510DC0
// Name: protected: virtual void CDmeAnimCmdCompress::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdCompress::PerformConstruction(CDmeAnimCmdCompress *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_nSkipFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "skipFrames",
                                       type: AT_INT,
                                       pMemory: &this->m_nSkipFrames);
}

//------------------------------------------------------------------------------
// Address: 0x00510E80
// Name: public: virtual bool CDmeAnimCmdNumFrames::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNumFrames::IsA(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510EB0
// Name: public: virtual int CDmeAnimCmdNumFrames::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNumFrames::GetInheritanceDepth(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00510F60
// Name: protected: virtual void CDmeAnimCmdNumFrames::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNumFrames::PerformConstruction(CDmeAnimCmdNumFrames *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_nFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "frames",
                                   type: AT_INT,
                                   pMemory: &this->m_nFrames);
}

//------------------------------------------------------------------------------
// Address: 0x00511020
// Name: public: virtual bool CDmeAnimCmdLocalHierarchy::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLocalHierarchy::IsA(CDmeAnimCmdLocalHierarchy *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00511050
// Name: public: virtual int CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(
        CDmeAnimCmdLocalHierarchy *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00511130
// Name: protected: virtual void CDmeAnimCmdLocalHierarchy::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::PerformConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAnimCmdLocalHierarchy::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005111D0
// Name: public: virtual bool CDmeAnimCmdNoAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNoAnimation::IsA(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00511200
// Name: public: virtual int CDmeAnimCmdNoAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNoAnimation::GetInheritanceDepth(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005112B0
// Name: protected: virtual void CDmeAnimCmdNoAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNoAnimation::PerformConstruction(CDmeAnimCmdNoAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_bNullAttr.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "nullAttr",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bNullAttr);
}

//------------------------------------------------------------------------------
// Address: 0x005113B0
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
// Address: 0x005173C0
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
// Address: 0x0051E610
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
// Address: 0x00521240
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
// Address: 0x005DFEC0
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
// Address: 0x005E47C0
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
// Address: 0x005EB7E0
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
// Address: 0x006AD460
// Name: _dynamic_initializer_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD4C0
// Name: _dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD520
// Name: _dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWeightList::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWeightList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD580
// Name: _dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD5E0
// Name: _dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdPreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdPreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD640
// Name: _dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdAlign::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdAlign pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD6A0
// Name: _dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD700
// Name: _dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWalkFrame::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWalkFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD760
// Name: _dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdDerivative::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdDerivative pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD7C0
// Name: _dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLinearDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLinearDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD820
// Name: _dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSplineDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSplineDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD880
// Name: _dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdCompress::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdCompress pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD8E0
// Name: _dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNumFrames::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNumFrames pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD940
// Name: _dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLocalHierarchy::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLocalHierarchy pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD9A0
// Name: _dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNoAnimation::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNoAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4050
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4060
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4070
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWeightList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4080
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4090
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdPreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40A0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdAlign::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40B0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40C0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWalkFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40D0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdDerivative::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40E0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLinearDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B40F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSplineDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4100
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdCompress::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4110
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNumFrames::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4120
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLocalHierarchy::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4130
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNoAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD490
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD4A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmd_Helper,
           classname: "DmeAnimCmd",
           pFactory: &g_CDmeAnimCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD4F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD500
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdFixupLoop_Helper,
           classname: "DmeAnimCmdFixupLoop",
           pFactory: &g_CDmeAnimCmdFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD550
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD560
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWeightList_Helper,
           classname: "DmeAnimCmdWeightList",
           pFactory: &g_CDmeAnimCmdWeightList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD5B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD5C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSubtract_Helper,
           classname: "DmeAnimCmdSubtract",
           pFactory: &g_CDmeAnimCmdSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD610
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD620
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdPreSubtract_Helper,
           classname: "DmeAnimCmdPreSubtract",
           pFactory: &g_CDmeAnimCmdPreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD670
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD680
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdAlign_Helper,
           classname: "DmeAnimCmdAlign",
           pFactory: &g_CDmeAnimCmdAlign_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD6D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD6E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdRotateTo_Helper,
           classname: "DmeAnimCmdRotateTo",
           pFactory: &g_CDmeAnimCmdRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD730
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD740
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWalkFrame_Helper,
           classname: "DmeAnimCmdWalkFrame",
           pFactory: &g_CDmeAnimCmdWalkFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD790
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD7A0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdDerivative_Helper,
           classname: "DmeAnimCmdDerivative",
           pFactory: &g_CDmeAnimCmdDerivative_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD7F0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD800
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLinearDelta_Helper,
           classname: "DmeAnimCmdLinearDelta",
           pFactory: &g_CDmeAnimCmdLinearDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD850
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD860
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSplineDelta_Helper,
           classname: "DmeAnimCmdSplineDelta",
           pFactory: &g_CDmeAnimCmdSplineDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD8B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD8C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdCompress_Helper,
           classname: "DmeAnimCmdCompress",
           pFactory: &g_CDmeAnimCmdCompress_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD910
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD920
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNumFrames_Helper,
           classname: "DmeAnimCmdNumFrames",
           pFactory: &g_CDmeAnimCmdNumFrames_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD970
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD980
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLocalHierarchy_Helper,
           classname: "DmeAnimCmdLocalHierarchy",
           pFactory: &g_CDmeAnimCmdLocalHierarchy_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AD9D0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD9E0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNoAnimation_Helper,
           classname: "DmeAnimCmdNoAnimation",
           pFactory: &g_CDmeAnimCmdNoAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4140
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4150
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdWeightList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4160
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4170
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdPreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4180
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdAlign_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4190
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41A0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdWalkFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41B0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdDerivative_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdLinearDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41D0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdSplineDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdCompress_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B41F0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdNumFrames_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4200
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdLocalHierarchy_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4210
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmdNoAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4220
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimCmd_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DE440
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
// Address: 0x004DF360
// Name: protected: void CDmeAnimCmdLocalHierarchy::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::OnConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_flStartFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "startFrame",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flStartFrame);
  this->m_flPeakFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "peakFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flPeakFrame);
  this->m_flTailFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "tailFrame",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flTailFrame);
  this->m_flEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "endFrame",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004DF3F0
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
// Address: 0x004DF490
// Name: protected: void CDmeAnimCmdAlign::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::OnConstruction(CDmeAnimCmdAlign *this)
{
  CDmaElement<CDmeSequenceBase> *p_m_eAnimation; // edi

  p_m_eAnimation = &this->m_eAnimation;
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eAnimation->m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  p_m_eAnimation->m_pAttribute->m_nFlags |= 0x1000u;
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_nSourceFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sourceFrame",
                                        type: AT_INT,
                                        pMemory: &this->m_nSourceFrame);
  this->m_nDestinatonFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "destinationFrame",
                                            type: AT_INT,
                                            pMemory: &this->m_nDestinatonFrame);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004DF600
// Name: public: virtual bool CDmeAnimCmd::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmd::IsA(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF630
// Name: public: virtual int CDmeAnimCmd::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmd::GetInheritanceDepth(CDmeAnimCmd *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF700
// Name: public: virtual bool CDmeAnimCmdFixupLoop::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdFixupLoop::IsA(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF730
// Name: public: virtual int CDmeAnimCmdFixupLoop::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdFixupLoop::GetInheritanceDepth(CDmeAnimCmdFixupLoop *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdFixupLoop::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF7E0
// Name: protected: virtual void CDmeAnimCmdFixupLoop::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdFixupLoop::PerformConstruction(CDmeAnimCmdFixupLoop *this)
{
  CDmeFXClip::OnDestruction();
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
}

//------------------------------------------------------------------------------
// Address: 0x004DF8B0
// Name: public: virtual bool CDmeAnimCmdWeightList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWeightList::IsA(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF8E0
// Name: public: virtual int CDmeAnimCmdWeightList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWeightList::GetInheritanceDepth(CDmeAnimCmdWeightList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWeightList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DF930
// Name: protected: virtual void CDmeAnimCmdWeightList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWeightList::PerformConstruction(CDmeAnimCmdWeightList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sWeightListName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "weightListName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sWeightListName);
}

//------------------------------------------------------------------------------
// Address: 0x004DFA50
// Name: public: virtual bool CDmeAnimCmdSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSubtract::IsA(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFA80
// Name: public: virtual int CDmeAnimCmdSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSubtract::GetInheritanceDepth(CDmeAnimCmdSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFBD0
// Name: public: virtual bool CDmeAnimCmdPreSubtract::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdPreSubtract::IsA(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFC10
// Name: public: virtual int CDmeAnimCmdPreSubtract::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::GetInheritanceDepth(CDmeAnimCmdPreSubtract *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdPreSubtract::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSubtract::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFCE0
// Name: protected: virtual void CDmeAnimCmdPreSubtract::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdPreSubtract::PerformConstruction(CDmeAnimCmdPreSubtract *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  this->m_eAnimation.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004DFDD0
// Name: public: virtual bool CDmeAnimCmdAlign::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdAlign::IsA(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFE00
// Name: public: virtual int CDmeAnimCmdAlign::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdAlign::GetInheritanceDepth(CDmeAnimCmdAlign *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdAlign::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFED0
// Name: protected: virtual void CDmeAnimCmdAlign::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdAlign::PerformConstruction(CDmeAnimCmdAlign *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdAlign::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DFF70
// Name: public: virtual bool CDmeAnimCmdRotateTo::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdRotateTo::IsA(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DFFA0
// Name: public: virtual int CDmeAnimCmdRotateTo::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdRotateTo::GetInheritanceDepth(CDmeAnimCmdRotateTo *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdRotateTo::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0050
// Name: protected: virtual void CDmeAnimCmdRotateTo::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdRotateTo::PerformConstruction(CDmeAnimCmdRotateTo *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "angle",
                                   type: AT_FLOAT,
                                   pMemory: &this->m_flAngle);
}

//------------------------------------------------------------------------------
// Address: 0x004E0110
// Name: public: virtual bool CDmeAnimCmdWalkFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdWalkFrame::IsA(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0140
// Name: public: virtual int CDmeAnimCmdWalkFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdWalkFrame::GetInheritanceDepth(CDmeAnimCmdWalkFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdWalkFrame::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0200
// Name: protected: virtual void CDmeAnimCmdWalkFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdWalkFrame::PerformConstruction(CDmeAnimCmdWalkFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_nEndFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "endFrame",
                                     type: AT_INT,
                                     pMemory: &this->m_nEndFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004E02D0
// Name: public: virtual bool CDmeAnimCmdDerivative::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdDerivative::IsA(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0300
// Name: public: virtual int CDmeAnimCmdDerivative::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdDerivative::GetInheritanceDepth(CDmeAnimCmdDerivative *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdDerivative::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E03B0
// Name: protected: virtual void CDmeAnimCmdDerivative::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdDerivative::PerformConstruction(CDmeAnimCmdDerivative *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E04D0
// Name: public: virtual bool CDmeAnimCmdLinearDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLinearDelta::IsA(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0500
// Name: public: virtual int CDmeAnimCmdLinearDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLinearDelta::GetInheritanceDepth(CDmeAnimCmdLinearDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLinearDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0630
// Name: public: virtual bool CDmeAnimCmdSplineDelta::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdSplineDelta::IsA(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0660
// Name: public: virtual int CDmeAnimCmdSplineDelta::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdSplineDelta::GetInheritanceDepth(CDmeAnimCmdSplineDelta *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdSplineDelta::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0740
// Name: public: virtual bool CDmeAnimCmdCompress::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdCompress::IsA(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0770
// Name: public: virtual int CDmeAnimCmdCompress::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdCompress::GetInheritanceDepth(CDmeAnimCmdCompress *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdCompress::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0830
// Name: protected: virtual void CDmeAnimCmdCompress::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdCompress::PerformConstruction(CDmeAnimCmdCompress *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nSkipFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "skipFrames",
                                       type: AT_INT,
                                       pMemory: &this->m_nSkipFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004E08F0
// Name: public: virtual bool CDmeAnimCmdNumFrames::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNumFrames::IsA(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0920
// Name: public: virtual int CDmeAnimCmdNumFrames::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNumFrames::GetInheritanceDepth(CDmeAnimCmdNumFrames *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNumFrames::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E09D0
// Name: protected: virtual void CDmeAnimCmdNumFrames::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNumFrames::PerformConstruction(CDmeAnimCmdNumFrames *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrames.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "frames",
                                   type: AT_INT,
                                   pMemory: &this->m_nFrames);
}

//------------------------------------------------------------------------------
// Address: 0x004E0A90
// Name: public: virtual bool CDmeAnimCmdLocalHierarchy::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdLocalHierarchy::IsA(CDmeAnimCmdLocalHierarchy *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0AC0
// Name: public: virtual int CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::GetInheritanceDepth(
        CDmeAnimCmdLocalHierarchy *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdLocalHierarchy::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0BA0
// Name: protected: virtual void CDmeAnimCmdLocalHierarchy::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdLocalHierarchy::PerformConstruction(CDmeAnimCmdLocalHierarchy *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAnimCmdLocalHierarchy::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E0C40
// Name: public: virtual bool CDmeAnimCmdNoAnimation::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimCmdNoAnimation::IsA(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0C70
// Name: public: virtual int CDmeAnimCmdNoAnimation::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdNoAnimation::GetInheritanceDepth(CDmeAnimCmdNoAnimation *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimCmdNoAnimation::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeAnimCmd::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0D20
// Name: protected: virtual void CDmeAnimCmdNoAnimation::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimCmdNoAnimation::PerformConstruction(CDmeAnimCmdNoAnimation *this)
{
  CDmeFXClip::OnDestruction();
  this->m_bNullAttr.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "nullAttr",
                                     type: AT_BOOL,
                                     pMemory: &this->m_bNullAttr);
}

//------------------------------------------------------------------------------
// Address: 0x004E0E20
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
// Address: 0x004E6200
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
// Address: 0x004EB8B0
// Name: protected: virtual int CDmeAnimCmdPreSubtract::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdPreSubtract::AllocatedSize(CDmeSourceAnimation *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x004ED690
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
// Address: 0x004EDC10
// Name: protected: virtual int CDmeAnimCmdLocalHierarchy::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimCmdLocalHierarchy::AllocatedSize(CDmeConstraintSlave *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x004EE3C0
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
// Address: 0x004F68A0
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
// Address: 0x004FE130
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
// Address: 0x005AA2E0
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
// Address: 0x005E6B30
// Name: _dynamic_initializer_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmd::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmd pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6B90
// Name: _dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdFixupLoop::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdFixupLoop pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6BF0
// Name: _dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWeightList::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWeightList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6C50
// Name: _dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6CB0
// Name: _dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdPreSubtract::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdPreSubtract pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6D10
// Name: _dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdAlign::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdAlign pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6D70
// Name: _dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdRotateTo::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdRotateTo pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6DD0
// Name: _dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdWalkFrame::s_Allocator,
    blockSize: 88,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdWalkFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E30
// Name: _dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdDerivative::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdDerivative pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E90
// Name: _dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLinearDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLinearDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6EF0
// Name: _dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdSplineDelta::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdSplineDelta pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6F50
// Name: _dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdCompress::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdCompress pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6FB0
// Name: _dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNumFrames::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNumFrames pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7020
// Name: _dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdLocalHierarchy::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdLocalHierarchy pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7080
// Name: _dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimCmdNoAnimation::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimCmdNoAnimation pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC410
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmd::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmd::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC420
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdFixupLoop::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdFixupLoop::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC430
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWeightList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWeightList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC440
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC450
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdPreSubtract::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdPreSubtract::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC460
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdAlign::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdAlign::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC470
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdRotateTo::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdRotateTo::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC480
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdWalkFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdWalkFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC490
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdDerivative::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdDerivative::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4A0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLinearDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLinearDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4B0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdSplineDelta::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdSplineDelta::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4C0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdCompress::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdCompress::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4D0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNumFrames::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNumFrames::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4E0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdLocalHierarchy::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdLocalHierarchy::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC4F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimCmdNoAnimation::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimCmdNoAnimation::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6B60
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmd_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6B70
// Name: _dynamic_initializer_for__g_CDmeAnimCmd_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmd_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmd_Helper,
           classname: "DmeAnimCmd",
           pFactory: &g_CDmeAnimCmd_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6BC0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6BD0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdFixupLoop_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdFixupLoop_Helper,
           classname: "DmeAnimCmdFixupLoop",
           pFactory: &g_CDmeAnimCmdFixupLoop_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6C20
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWeightList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6C30
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWeightList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWeightList_Helper,
           classname: "DmeAnimCmdWeightList",
           pFactory: &g_CDmeAnimCmdWeightList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6C80
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6C90
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSubtract_Helper,
           classname: "DmeAnimCmdSubtract",
           pFactory: &g_CDmeAnimCmdSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6CE0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6CF0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdPreSubtract_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdPreSubtract_Helper,
           classname: "DmeAnimCmdPreSubtract",
           pFactory: &g_CDmeAnimCmdPreSubtract_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6D40
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdAlign_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6D50
// Name: _dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdAlign_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdAlign_Helper,
           classname: "DmeAnimCmdAlign",
           pFactory: &g_CDmeAnimCmdAlign_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6DA0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6DB0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdRotateTo_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdRotateTo_Helper,
           classname: "DmeAnimCmdRotateTo",
           pFactory: &g_CDmeAnimCmdRotateTo_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E00
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E10
// Name: _dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdWalkFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdWalkFrame_Helper,
           classname: "DmeAnimCmdWalkFrame",
           pFactory: &g_CDmeAnimCmdWalkFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E60
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdDerivative_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6E70
// Name: _dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdDerivative_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdDerivative_Helper,
           classname: "DmeAnimCmdDerivative",
           pFactory: &g_CDmeAnimCmdDerivative_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6EC0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6ED0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLinearDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLinearDelta_Helper,
           classname: "DmeAnimCmdLinearDelta",
           pFactory: &g_CDmeAnimCmdLinearDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6F20
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6F30
// Name: _dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdSplineDelta_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdSplineDelta_Helper,
           classname: "DmeAnimCmdSplineDelta",
           pFactory: &g_CDmeAnimCmdSplineDelta_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6F80
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdCompress_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6F90
// Name: _dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdCompress_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdCompress_Helper,
           classname: "DmeAnimCmdCompress",
           pFactory: &g_CDmeAnimCmdCompress_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E6FE0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7000
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNumFrames_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNumFrames_Helper,
           classname: "DmeAnimCmdNumFrames",
           pFactory: &g_CDmeAnimCmdNumFrames_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7050
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7060
// Name: _dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdLocalHierarchy_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdLocalHierarchy_Helper,
           classname: "DmeAnimCmdLocalHierarchy",
           pFactory: &g_CDmeAnimCmdLocalHierarchy_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E70B0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E70C0
// Name: _dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimCmdNoAnimation_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimCmdNoAnimation_Helper,
           classname: "DmeAnimCmdNoAnimation",
           pFactory: &g_CDmeAnimCmdNoAnimation_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC500
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdFixupLoop_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdFixupLoop_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC510
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWeightList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWeightList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC520
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC530
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdPreSubtract_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdPreSubtract_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC540
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdAlign_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdAlign_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC550
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdRotateTo_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdRotateTo_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC560
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdWalkFrame_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdWalkFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC570
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdDerivative_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdDerivative_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC580
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLinearDelta_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLinearDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC590
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdSplineDelta_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdSplineDelta_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5A0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdCompress_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdCompress_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5B0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNumFrames_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNumFrames_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdLocalHierarchy_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdLocalHierarchy_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5D0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmdNoAnimation_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmdNoAnimation_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimCmd_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimCmd_Factory.m_CallBackList);
}

} // namespace studiomdl
