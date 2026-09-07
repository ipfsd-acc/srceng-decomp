// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmesequence.cpp
// Functions: 108
// ============================================================

#include "mdlobjects\dmesequence.h"

//------------------------------------------------------------------------------
// Address: 0x004A0170
// Name: protected: virtual int CDmeAnimationEvent::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x004A1760
// Name: protected: void CDmeSequenceBlendLayer::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::OnConstruction(CDmeSequenceBlendLayer *this)
{
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
  this->m_bSpline.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "spline",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSpline);
  this->m_bCrossfade.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "crossfade",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bCrossfade);
  this->m_bNoBlend.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "noBlend",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bNoBlend);
  this->m_bLocal.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "local",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bLocal);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004A18D0
// Name: protected: void CDmeSequenceBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::OnConstruction(CDmeSequenceBase *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // eax
  int v11; // esi
  CUtlSymbolLarge v12; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  CDmaElement<CDmeSequenceActivity>::InitAndCreate(
    this: &this->m_eActivity,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"activity",
    pElementName: nullptr,
    flags: 0);
  value = false;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "hidden", type: AT_BOOL, pMemory: &this->m_bHidden);
  this->m_bHidden.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "delta", type: AT_BOOL, pMemory: &this->m_bDelta);
  this->m_bDelta.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "worldSpace",
         type: AT_BOOL,
         pMemory: &this->m_bWorldSpace);
  this->m_bWorldSpace.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "preDelta", type: AT_BOOL, pMemory: &this->m_bPreDelta);
  this->m_bPreDelta.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "autoPlay", type: AT_BOOL, pMemory: &this->m_bAutoPlay);
  this->m_bAutoPlay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "realtime", type: AT_BOOL, pMemory: &this->m_bRealtime);
  this->m_bRealtime.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  v12.u.m_Id = 1045220557;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadein", type: AT_FLOAT, pMemory: &this->m_flFadeIn);
  this->m_flFadeIn.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v12.u.m_Id);
  v12.u.m_Id = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadeout", type: AT_FLOAT, pMemory: &this->m_flFadeOut);
  this->m_flFadeOut.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v12.u.m_Id);
  this->m_sEntryNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "entryNode",
                                      type: AT_STRING,
                                      pMemory: &this->m_sEntryNode);
  this->m_sExitNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "exitNode",
                                     type: AT_STRING,
                                     pMemory: &this->m_sExitNode);
  this->m_bReverseNodeTransition.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "reverseNodeTransition",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bReverseNodeTransition);
  this->m_bSnap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "snap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bSnap);
  this->m_bPost.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "post",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bPost);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_eIkLockList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikLockList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkLockList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkLockList.m_pAttribute, typeSymbol: CDmeIkLock::m_classType);
  this->m_eIkLockList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eAnimationEventList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "animationEventList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eAnimationEventList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationEventList.m_pAttribute,
    typeSymbol: CDmeAnimationEvent::m_classType);
  this->m_eLayerList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "layerList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eLayerList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eLayerList.m_pAttribute,
    typeSymbol: CDmeSequenceLayerBase::m_classType);
  this->m_sKeyValues.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyValues",
                                      type: AT_STRING,
                                      pMemory: &this->m_sKeyValues);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eActivity.m_Storage.m_Handle) != 0 )
  {
    v10 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_eActivity.m_Storage.m_Handle)
                         + 20);
    if ( v10 == (const char *)-1 )
      v10 = WindowName;
    if ( _V_strcmp(s1: "unnamed", s2: v10) == 0 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_eActivity.m_Storage.m_Handle);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v12,
        a3: WindowName);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v11 + 24), value: &v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A1BE0
// Name: protected: void CDmeSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::OnConstruction(CDmeSequence *this)
{
  CDmaElement<CDmeDag> *p_m_eSkeleton; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  Vector v9; // [esp+8h] [ebp-14h] BYREF
  float value; // [esp+14h] [ebp-8h] BYREF
  bool v11; // [esp+1Bh] [ebp-1h] BYREF

  p_m_eSkeleton = &this->m_eSkeleton;
  this->m_eSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "skeleton",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSkeleton);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eSkeleton->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_eAnimationList.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "animationList",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_eAnimationList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationList.m_pAttribute,
    typeSymbol: CDmeAnimationList::m_classType);
  value = 30.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "fps", type: AT_FLOAT, pMemory: &this->m_flFPS);
  this->m_flFPS.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  memset(&v9, 0, sizeof(v9));
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "origin", type: AT_VECTOR3, pMemory: &this->m_vOrigin);
  this->m_vOrigin.m_pAttribute = v4;
  CDmAttribute::SetValue<Vector>(this: v4, value: &v9);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_nStartLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "startLoop",
                                      type: AT_INT,
                                      pMemory: &this->m_nStartLoop);
  this->m_bForceLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "forceLoop",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bForceLoop);
  this->m_bAutoIk.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "autoIk",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bAutoIk);
  value = 0.30000001;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "motionRollback",
         type: AT_FLOAT,
         pMemory: &this->m_flMotionRollback);
  this->m_flMotionRollback.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  v11 = true;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlocks",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlocks);
  this->m_bAnimBlocks.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v11);
  v11 = true;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlockStall",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlockStall);
  this->m_bAnimBlockStall.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v11);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_eAnimationCommandList.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "animationCommandList",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_eAnimationCommandList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationCommandList.m_pAttribute,
    typeSymbol: CDmeAnimCmd::m_classType);
  this->m_eIkRuleList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikRuleList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkRuleList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkRuleList.m_pAttribute, typeSymbol: CDmeIkRule::m_classType);
  this->m_eIkRuleList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneMask",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A1E50
// Name: protected: void CDmeMultiSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::OnConstruction(CDmeMultiSequence *this)
{
  CDmaVar<int> *p_m_nBlendWidth; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nBlendWidth = &this->m_nBlendWidth;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "blendWidth", type: AT_INT, pMemory: &this->m_nBlendWidth);
  p_m_nBlendWidth->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_eBlendRef.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "blendRef",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBlendRef);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendRef.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendRef.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendComp.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendComp",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eBlendComp);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendComp.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendComp.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "blendCenter",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_eBlendCenter);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendCenter.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendCenter.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eSequenceList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "sequenceList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eSequenceList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequenceList.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eSequenceList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eBlendList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBlendList.m_pAttribute,
    typeSymbol: CDmeSequenceBlendBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A1F90
// Name: public: static int CDmeSequenceBase::QSortFunction(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmeSequenceBase::QSortFunction(int *pVoidSeq1, int pVoidSeq2)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  unsigned __int8 (__thiscall *v5)(int, CUtlSymbolLarge::<unnamed_type_u>); // eax
  const CDmeSequence *v6; // ebx
  const CDmeSequence *v7; // eax
  int v9; // ecx
  const CDmeSequence *v10; // ebx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // esi
  const char *m_pAsString; // eax
  const char *v15; // ecx
  int m_Size; // eax
  int v17; // ecx
  const CDmeSequence *pSeq[2]; // [esp+Ch] [ebp-10h]
  const CDmeSequence *pSeq1; // [esp+14h] [ebp-8h]
  const CDmeSequence *pSeq2; // [esp+18h] [ebp-4h]

  v2 = *pVoidSeq1;
  v3 = *(_DWORD *)pVoidSeq2;
  if ( *pVoidSeq1 == 0 || v3 == 0 )
    return 0;
  v4 = (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeSequence::m_classType.u);
  v5 = *(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16);
  v6 = v4 != 0 ? (const CDmeSequence *)v2 : nullptr;
  pSeq1 = v6;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(
         a1: v3,
         a2: (CUtlSymbolLarge::<unnamed_type_u>)CDmeSequence::m_classType.u.m_Id) != 0
     ? (const CDmeSequence *)v3
     : nullptr;
  pSeq2 = v7;
  if ( v6 == nullptr )
    return v7 != nullptr;
  if ( v7 == nullptr )
    return -1;
  v9 = 0;
  LOWORD(pVoidSeq1) = 0;
  pSeq[0] = v6;
  pSeq[1] = v7;
  pVoidSeq2 = 0;
  do
  {
    v10 = pSeq[v9];
    v11 = 0;
    if ( v10->m_eAnimationCommandList.m_Storage.m_Size > 0 )
    {
      while ( 1 )
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v10->m_eAnimationCommandList.m_Storage.m_Memory.m_pMemory[v11]);
        v13 = (_DWORD *)v12;
        if ( v12 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
               a1: v12,
               a2: CDmeAnimCmd::m_classType.u) != 0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdSubtract::m_classType.u) != 0
            && v13[17] == CDmElement::GetHandle(this: &pSeq[(pVoidSeq2 + 1) % 2]->CDmeSequenceBase) )
          {
            *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
            goto LABEL_19;
          }
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdAlign::m_classType.u) != 0
            && v13[17] == CDmElement::GetHandle(this: &pSeq[(pVoidSeq2 + 1) % 2]->CDmeSequenceBase) )
          {
            break;
          }
        }
        if ( ++v11 >= v10->m_eAnimationCommandList.m_Storage.m_Size )
          goto LABEL_19;
      }
      *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
LABEL_19:
      v7 = pSeq2;
    }
    v9 = pVoidSeq2 + 1;
    pVoidSeq2 = v9;
  }
  while ( v9 < 2 );
  if ( (_BYTE)pVoidSeq1 != 0 )
  {
    if ( BYTE1(pVoidSeq1) == 0 )
      return 1;
    m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    v15 = pSeq1->m_Name.m_Storage.u.m_pAsString;
    if ( v15 == (const char *)-1 )
      v15 = WindowName;
    _Error(a1: "Animation %s & %s reference each other, circular references are not allowed\n", v15, m_pAsString);
    return 0;
  }
  if ( BYTE1(pVoidSeq1) != 0 )
    return -1;
  m_Size = v7->m_eAnimationCommandList.m_Storage.m_Size;
  v17 = pSeq1->m_eAnimationCommandList.m_Storage.m_Size;
  if ( v17 < m_Size )
    return -1;
  return v17 > m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A21B0
// Name: public: class CDmeChannelsClip __near * CDmeSequence::GetDmeChannelsClip(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetDmeChannelsClip(CDmeSequence *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  v2 = v1;
  if ( v1 == 0 )
    return nullptr;
  v3 = 0;
  if ( *(int *)(v1 + 80) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      break;
    }
    if ( ++v3 >= *(_DWORD *)(v2 + 80) )
      return nullptr;
  }
  return (CDmeChannelsClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004A2230
// Name: public: void CDmeSequence::UpdateChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::UpdateChannels(
        CDmeSequence *this,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList,
        DmeTime_t nClipTime)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  CDmeChannel *v10; // ecx
  CDmeAnimationList *pDmeAnimationList; // [esp+10h] [ebp-10h]
  int nChannelsCount; // [esp+14h] [ebp-Ch]
  DmeTime_t channelTime; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v3;
  if ( v3 != 0 )
  {
    v4 = 0;
    for ( i = 0; v4 < *(_DWORD *)(v3 + 80); i = v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v4));
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        CDmeClip::ToChildMediaTime(this: (CDmeClip *)v6, result: &channelTime, t: nClipTime, bClamp: 1);
        v7 = 0;
        nChannelsCount = *(_DWORD *)(v6 + 152);
        if ( nChannelsCount > 0 )
        {
          do
          {
            v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v6 + 140) + 4 * v7));
            v9 = v8;
            if ( v8 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                   a1: v8,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v10 = (CDmeChannel *)(v9 - 4);
            }
            else
            {
              v10 = nullptr;
            }
            CDmeChannel::SetCurrentTime(this: v10, time: channelTime);
            ++v7;
          }
          while ( v7 < nChannelsCount );
          v3 = (int)pDmeAnimationList;
        }
      }
      v4 = i + 1;
    }
    LOBYTE(pDmeAnimationList) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: dmeOperatorList);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeAnimationList *))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: pDmeAnimationList);
    g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A23A0
// Name: public: class DmeFramerate_t CDmeSequence::GetFrameRate(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
DmeFramerate_t *__thiscall CDmeSequence::GetFrameRate(
        CDmeSequence *this,
        DmeFramerate_t *result,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *DmeChannelsClip; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *p_bForceFallback; // eax
  int m_Storage; // eax
  DmeFramerate_t v9; // ecx
  unsigned __int16 dmeFrameRate; // [esp+4h] [ebp-4h]

  DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this);
  if ( DmeChannelsClip != nullptr )
  {
    dmeFrameRate = fallbackFrameRate.m_num;
    if ( (_BYTE)bForceFallback != 0
      || !CDmElement::HasAttribute(this: DmeChannelsClip, pAttributeName: "frameRate", type: AT_UNKNOWN)
      || ((bForceFallback = 0,
           (Attribute = CDmElement::FindAttribute(this: DmeChannelsClip, pAttributeName: "frameRate")) == nullptr)
        ? (p_bForceFallback = (CDmaVar<int> *)&bForceFallback)
        : (p_bForceFallback = CDmAttribute::GetValue<int>(this: Attribute)),
          (m_Storage = p_bForceFallback->m_Storage) < 0) )
    {
      v9.m_den = fallbackFrameRate.m_den;
    }
    else
    {
      v9 = *DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&bForceFallback, fps: m_Storage);
      dmeFrameRate = v9.m_num;
    }
    result->m_num = dmeFrameRate;
    result->m_den = v9.m_den;
    return result;
  }
  else
  {
    *result = fallbackFrameRate;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2450
// Name: public: int CDmeSequence::GetFrameCount(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetFrameCount(
        CDmeSequence *this,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *result; // eax
  CDmeClip *v5; // esi
  DmeFramerate_t v6; // kr00_4
  int v7; // eax
  DmeTime_t nEndTime; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t nStartTime; // [esp+10h] [ebp-4h] BYREF

  result = CDmeSequence::GetDmeChannelsClip(this);
  v5 = result;
  if ( result != nullptr )
  {
    CDmeSequence::GetFrameRate(this, result: (DmeFramerate_t *)&bForceFallback, fallbackFrameRate, bForceFallback);
    CDmeClip::GetStartTime(this: v5, result: &nStartTime);
    v6 = (DmeFramerate_t)bForceFallback;
    bForceFallback = FrameForTime(t: nStartTime, framerate: (DmeFramerate_t)bForceFallback);
    CDmeClip::GetEndTime(this: v5, result: &nEndTime);
    v7 = FrameForTime(t: nEndTime, framerate: v6);
    return (CDmeChannelsClip *)(v7 - bForceFallback + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A24F0
// Name: public: void CDmeSequence::GetDependentOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class CDmeOperator __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::GetDependentOperators(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CDmeOperator *pDmeOperator)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v3; // edx
  int k; // edi
  CUtlSymbolTable::StringPool_t *v5; // esi
  int *p_m_SpaceUsed; // esi
  CDmeOperator *v7; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v10; // ecx
  int v11; // eax
  CUtlSymbolTable::StringPool_t **v12; // esi
  void (__thiscall *GetOutputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  CDmAttribute **v14; // eax
  int v15; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // edx
  int v18; // eax
  CDmeAttributeReference *v19; // esi
  CDmAttribute **v20; // edi
  void (__stdcall *v21)(CUtlSymbolLarge *, const char *); // edx
  int m; // edi
  CDmElement *v23; // esi
  CDmeOperator *v24; // eax
  CUtlSymbolLarge v25; // [esp-Ch] [ebp-64h] BYREF
  BOOL v26; // [esp-8h] [ebp-60h]
  TraversalDepth_t v27; // [esp-4h] [ebp-5Ch]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-38h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-24h] BYREF
  CDmElement *pDmElement; // [esp+48h] [ebp-10h]
  CDmElement *v32; // [esp+4Ch] [ebp-Ch]
  CDmeSequence *v33; // [esp+50h] [ebp-8h]
  int j; // [esp+54h] [ebp-4h]
  int i; // [esp+64h] [ebp+Ch]

  v33 = this;
  if ( pDmeOperator != nullptr )
  {
    v32 = &pDmeOperator->CDmElement;
    if ( pDmeOperator != (CDmeOperator *)-4
      && ((int (__thiscall *)(_DWORD, _DWORD))pDmeOperator->IsA)(
           a1: &pDmeOperator->CDmElement,
           a2: (CUtlSymbolLarge)CDmeOperator::m_classType.u.m_Id) )
    {
      v3 = operatorList;
      for ( k = 0; k < (int)v3[1].m_pMemory; ++k )
      {
        v5 = v3->m_pMemory[k];
        if ( v5 != nullptr )
        {
          p_m_SpaceUsed = &v5->m_SpaceUsed;
          if ( p_m_SpaceUsed != nullptr )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*p_m_SpaceUsed + 16))(
                   a1: p_m_SpaceUsed,
                   a2: CDmeOperator::m_classType.u) != 0 )
            {
              v7 = (CDmeOperator *)(p_m_SpaceUsed - 1);
              if ( v7 != nullptr && v7 == pDmeOperator )
                return;
            }
            v3 = operatorList;
          }
        }
      }
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = operatorList;
      }
      ++v3[1].m_pMemory;
      v10 = v3->m_pMemory;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v11 > 0 )
      {
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
        v3 = operatorList;
      }
      v12 = &v3->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = (CUtlSymbolTable::StringPool_t *)pDmeOperator;
      GetOutputAttributes = pDmeOperator->GetOutputAttributes;
      memset(&outAttrList, 0, sizeof(outAttrList));
      GetOutputAttributes(this: pDmeOperator, a2: &outAttrList);
      v14 = outAttrList.m_Memory.m_pMemory;
      v15 = 0;
      for ( i = 0; v15 < outAttrList.m_Size; i = v15 )
      {
        m_pOwner = v14[v15]->m_pOwner;
        pDmElement = m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner != v32 )
          {
            v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v27 = TD_ALL;
            v26 = false;
            v25.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v17(a1: &v25, a2: "element");
            FindReferringElements<CDmElement>(
              list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList0,
              pElement: m_pOwner,
              symAttrName: v25,
              bMustBeInSameFile: v26,
              depth: v27);
            v18 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v19 = (CDmeAttributeReference *)reList0.m_Memory.m_pMemory[v18];
                if ( v19 != nullptr && v19->IsA(this: v19, a2: CDmeAttributeReference::m_classType) )
                {
                  v20 = &outAttrList.m_Memory.m_pMemory[v15];
                  if ( CDmeAttributeReference::GetReferencedAttribute(this: v19) == *v20 )
                  {
                    v21 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                    v27 = TD_ALL;
                    v26 = false;
                    v25.u.m_Id = g_pDataModel.u.m_Id;
                    memset(&reList1, 0, sizeof(reList1));
                    v21(a1: &v25, a2: "input");
                    FindReferringElements<CDmElement>(
                      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList1,
                      pElement: v19,
                      symAttrName: v25,
                      bMustBeInSameFile: v26,
                      depth: v27);
                    for ( m = 0; m < reList1.m_Size; ++m )
                    {
                      v23 = reList1.m_Memory.m_pMemory[m];
                      if ( v23 != nullptr
                        && v23->IsA(this: v23, a2: CDmeConnectionOperator::m_classType)
                        && v23 != (CDmElement *)4 )
                      {
                        CDmeSequence::GetDependentOperators(
                          this: v33,
                          (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                          pDmeOperator: (CDmeOperator *)((char *)&v23[-1] + 64));
                      }
                    }
                    if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                  }
                }
                v15 = i;
                v18 = j + 1;
                j = v18;
              }
              while ( v18 < reList0.m_Size );
              m_pOwner = pDmElement;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v24 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v24 = nullptr;
          CDmeSequence::GetDependentOperators(
            this: v33,
            (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
            pDmeOperator: v24);
          v14 = outAttrList.m_Memory.m_pMemory;
        }
        ++v15;
      }
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
          v14 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v14;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A2800
// Name: public: void CDmeSequence::PrepareChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PrepareChannels(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *dmeOperatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeAnimationList *pDmeAnimationList; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  dmeOperatorList[1].m_pMemory = nullptr;
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v2;
  if ( v2 != 0 )
  {
    v3 = 0;
    for ( i = 0; v3 < *(_DWORD *)(v2 + 80); i = v3 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        v6 = 0;
        if ( *(int *)(v5 + 152) > 0 )
        {
          do
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v5 + 140) + 4 * v6));
            v8 = v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v9 = (CDmeChannel *)(v8 - 4);
              if ( v9 != nullptr )
              {
                CDmeChannel::SetMode(this: v9, mode: CM_PLAY);
                CDmeSequence::GetDependentOperators(this, operatorList: dmeOperatorList, pDmeOperator: v9);
              }
            }
            ++v6;
          }
          while ( v6 < *(_DWORD *)(v5 + 152) );
          v2 = (int)pDmeAnimationList;
        }
      }
      v3 = i + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A29A0
// Name: public: virtual bool CDmeAnimationEvent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationEvent::IsA(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A29D0
// Name: public: virtual int CDmeAnimationEvent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::GetInheritanceDepth(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2A80
// Name: protected: virtual void CDmeAnimationEvent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationEvent::PerformConstruction(CDmeAnimationEvent *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
  this->m_sDataString.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "dataString",
                                       type: AT_STRING,
                                       pMemory: &this->m_sDataString);
}

//------------------------------------------------------------------------------
// Address: 0x004A2BB0
// Name: public: virtual bool CDmeSequenceBlendBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendBase::IsA(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2BE0
// Name: public: virtual int CDmeSequenceBlendBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendBase::GetInheritanceDepth(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2C80
// Name: protected: virtual void CDmeSequenceBlendBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendBase::PerformConstruction(CDmeSequenceBlendBase *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004A2D40
// Name: public: virtual bool CDmeSequenceBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlend::IsA(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2D70
// Name: public: virtual int CDmeSequenceBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::GetInheritanceDepth(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2E40
// Name: protected: virtual void CDmeSequenceBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlend::PerformConstruction(CDmeSequenceBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_flParamStart.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "paramStart",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flParamStart);
  this->m_flParamEnd.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "paramEnd",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flParamEnd);
}

//------------------------------------------------------------------------------
// Address: 0x004A2F20
// Name: public: virtual bool CDmeSequenceCalcBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceCalcBlend::IsA(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A2F50
// Name: public: virtual int CDmeSequenceCalcBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceCalcBlend::GetInheritanceDepth(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3020
// Name: protected: virtual void CDmeSequenceCalcBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceCalcBlend::PerformConstruction(CDmeSequenceCalcBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004A3100
// Name: public: virtual bool CDmeSequenceLayerBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceLayerBase::IsA(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3130
// Name: public: virtual int CDmeSequenceLayerBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceLayerBase::GetInheritanceDepth(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3260
// Name: public: virtual bool CDmeSequenceAddLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceAddLayer::IsA(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3290
// Name: public: virtual int CDmeSequenceAddLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::GetInheritanceDepth(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A32E0
// Name: protected: virtual int CDmeSequenceAddLayer::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x004A3350
// Name: protected: virtual void CDmeSequenceLayerBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceLayerBase::PerformConstruction(CDmeSequenceAddLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004A33F0
// Name: protected: CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *__thiscall CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(
        CDmeSequenceBlendLayer *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_eAnimation.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimation.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimation.m_pAttribute = nullptr;
  this->__vftable = (CDmeSequenceBlendLayer_vtbl *)&CDmeSequenceBlendLayer::`vftable';
  this->m_flStartFrame = 0;
  this->m_flPeakFrame = 0;
  this->m_flTailFrame = 0;
  this->m_flEndFrame = 0;
  this->m_bSpline.m_pAttribute = nullptr;
  this->m_bSpline.m_Storage = false;
  this->m_bCrossfade.m_pAttribute = nullptr;
  this->m_bCrossfade.m_Storage = false;
  this->m_bNoBlend.m_pAttribute = nullptr;
  this->m_bNoBlend.m_Storage = false;
  this->m_bLocal.m_pAttribute = nullptr;
  this->m_bLocal.m_Storage = false;
  this->m_sPoseParameterName.m_pAttribute = nullptr;
  this->m_sPoseParameterName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A34B0
// Name: public: virtual bool CDmeSequenceBlendLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendLayer::IsA(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A34E0
// Name: public: virtual int CDmeSequenceBlendLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendLayer::GetInheritanceDepth(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3570
// Name: protected: virtual void CDmeSequenceBlendLayer::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::PerformConstruction(CDmeSequenceBlendLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  CDmeSequenceBlendLayer::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A36D0
// Name: protected: CDmeSequenceBase::CDmeSequenceBase(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBase *__thiscall CDmeSequenceBase::CDmeSequenceBase(
        CDmeSequenceBase *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequenceBase_vtbl *)&CDmeSequenceBase::`vftable';
  this->m_eActivity.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eActivity.m_pAttribute = nullptr;
  this->m_eActivity.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_bHidden.m_pAttribute = nullptr;
  this->m_bHidden.m_Storage = false;
  this->m_bDelta.m_pAttribute = nullptr;
  this->m_bDelta.m_Storage = false;
  this->m_bWorldSpace.m_pAttribute = nullptr;
  this->m_bWorldSpace.m_Storage = false;
  this->m_bPreDelta.m_pAttribute = nullptr;
  this->m_bPreDelta.m_Storage = false;
  this->m_bAutoPlay.m_pAttribute = nullptr;
  this->m_bAutoPlay.m_Storage = false;
  this->m_bRealtime.m_pAttribute = nullptr;
  this->m_bRealtime.m_Storage = false;
  this->m_flFadeIn = 0;
  this->m_flFadeOut = 0;
  this->m_sEntryNode.m_pAttribute = nullptr;
  this->m_sEntryNode.m_Storage.u.m_Id = -1;
  this->m_sExitNode.m_pAttribute = nullptr;
  this->m_sExitNode.m_Storage.u.m_Id = -1;
  this->m_bReverseNodeTransition.m_pAttribute = nullptr;
  this->m_bReverseNodeTransition.m_Storage = false;
  this->m_bSnap.m_pAttribute = nullptr;
  this->m_bSnap.m_Storage = false;
  this->m_bPost.m_pAttribute = nullptr;
  this->m_bPost.m_Storage = false;
  this->m_bLoop.m_pAttribute = nullptr;
  this->m_bLoop.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkLockList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationEventList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eLayerList);
  this->m_sKeyValues.m_Storage.u.m_Id = -1;
  this->m_sKeyValues.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A37D0
// Name: public: virtual bool CDmeSequenceBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBase::IsA(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3800
// Name: public: virtual int CDmeSequenceBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::GetInheritanceDepth(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3840
// Name: protected: virtual int CDmeSequenceBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::AllocatedSize(CDmeSequenceBase *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x004A3850
// Name: protected: virtual void CDmeSequenceBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::PerformConstruction(CDmeSequenceBase *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A38B0
// Name: protected: CDmeSequence::CDmeSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequence *__thiscall CDmeSequence::CDmeSequence(
        CDmeSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequence_vtbl *)&CDmeSequence::`vftable';
  this->m_eSkeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eSkeleton.m_pAttribute = nullptr;
  this->m_eSkeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimationList.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimationList.m_pAttribute = nullptr;
  this->m_eAnimationList.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flFPS = 0;
  this->m_vOrigin.m_pAttribute = nullptr;
  this->m_vOrigin.m_Storage.x = 0.0;
  this->m_vOrigin.m_Storage.y = 0.0;
  this->m_vOrigin.m_Storage.z = 0.0;
  this->m_flScale = 0;
  this->m_nStartLoop.m_pAttribute = nullptr;
  this->m_nStartLoop.m_Storage = 0;
  this->m_bForceLoop.m_pAttribute = nullptr;
  this->m_bForceLoop.m_Storage = false;
  this->m_bAutoIk.m_pAttribute = nullptr;
  this->m_bAutoIk.m_Storage = false;
  this->m_flMotionRollback = 0;
  this->m_bAnimBlocks.m_pAttribute = nullptr;
  this->m_bAnimBlocks.m_Storage = false;
  this->m_bAnimBlockStall.m_pAttribute = nullptr;
  this->m_bAnimBlockStall.m_Storage = false;
  this->m_eMotionControl.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMotionControl.m_pAttribute = nullptr;
  this->m_eMotionControl.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationCommandList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkRuleList);
  this->m_eBoneMask.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBoneMask.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBoneMask.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A39D0
// Name: public: virtual bool CDmeSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequence::IsA(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3A00
// Name: public: virtual int CDmeSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::GetInheritanceDepth(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3A50
// Name: protected: virtual int CDmeSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::AllocatedSize(CDmeSequence *this)
{
  return 468;
}

//------------------------------------------------------------------------------
// Address: 0x004A3A60
// Name: protected: virtual void CDmeSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PerformConstruction(CDmeSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A3AF0
// Name: protected: CDmeMultiSequence::CDmeMultiSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMultiSequence *__thiscall CDmeMultiSequence::CDmeMultiSequence(
        CDmeMultiSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMultiSequence_vtbl *)&CDmeMultiSequence::`vftable';
  this->m_nBlendWidth.m_pAttribute = nullptr;
  this->m_nBlendWidth.m_Storage = 0;
  this->m_eBlendRef.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendRef.m_pAttribute = nullptr;
  this->m_eBlendRef.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendComp.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendComp.m_pAttribute = nullptr;
  this->m_eBlendComp.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendCenter.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendCenter.m_pAttribute = nullptr;
  this->m_eBlendCenter.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eSequenceList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eBlendList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A3B80
// Name: public: virtual bool CDmeMultiSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMultiSequence::IsA(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3BB0
// Name: public: virtual int CDmeMultiSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::GetInheritanceDepth(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3C00
// Name: protected: virtual int CDmeMultiSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::AllocatedSize(CDmeMultiSequence *this)
{
  return 384;
}

//------------------------------------------------------------------------------
// Address: 0x004A3C10
// Name: protected: virtual void CDmeMultiSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::PerformConstruction(CDmeMultiSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeMultiSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004A3D60
// Name: public: virtual bool CDmeSequenceActivity::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceActivity::IsA(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3D90
// Name: public: virtual int CDmeSequenceActivity::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceActivity::GetInheritanceDepth(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A3DD0
// Name: protected: virtual void CDmeSequenceActivity::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceActivity::PerformConstruction(CDmeSequenceActivity *this)
{
  CDmAttribute *v2; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_INT, pMemory: &this->m_nWeight);
  this->m_nWeight.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_sModifierList,
    pOwner: this,
    pAttributeName: "modifierList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004A4C50
// Name: protected: virtual int CDmeSequenceBlend::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x00599600
// Name: _dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationEvent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationEvent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599660
// Name: _dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceActivity::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceActivity pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005996C0
// Name: _dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendBase::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599720
// Name: _dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlend::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599780
// Name: _dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceCalcBlend::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceCalcBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005997E0
// Name: _dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceLayerBase::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceLayerBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599840
// Name: _dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceAddLayer::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceAddLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005998A0
// Name: _dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendLayer::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599900
// Name: _dynamic_initializer_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBase::s_Allocator,
    blockSize: 284,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00599960
// Name: _dynamic_initializer_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequence::s_Allocator,
    blockSize: 468,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005999C0
// Name: _dynamic_initializer_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMultiSequence::s_Allocator,
    blockSize: 384,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMultiSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E460
// Name: _dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationEvent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E470
// Name: _dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceActivity::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E480
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E490
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4A0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceCalcBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4B0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceLayerBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4C0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceAddLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4D0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4E0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E4F0
// Name: _dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059E500
// Name: _dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMultiSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599630
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationEvent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599640
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationEvent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationEvent_Helper,
           classname: "DmeAnimationEvent",
           pFactory: &g_CDmeAnimationEvent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599690
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceActivity_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005996A0
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceActivity_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceActivity_Helper,
           classname: "DmeSequenceActivity",
           pFactory: &g_CDmeSequenceActivity_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005996F0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599700
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendBase_Helper,
           classname: "DmeSequenceBlendBase",
           pFactory: &g_CDmeSequenceBlendBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599750
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599760
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlend_Helper,
           classname: "DmeSequenceBlend",
           pFactory: &g_CDmeSequenceBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005997B0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005997C0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceCalcBlend_Helper,
           classname: "DmeSequenceCalcBlend",
           pFactory: &g_CDmeSequenceCalcBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599810
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599820
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceLayerBase_Helper,
           classname: "DmeSequenceLayerBase",
           pFactory: &g_CDmeSequenceLayerBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599870
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599880
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceAddLayer_Helper,
           classname: "DmeSequenceAddLayer",
           pFactory: &g_CDmeSequenceAddLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005998D0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005998E0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendLayer_Helper,
           classname: "DmeSequenceBlendLayer",
           pFactory: &g_CDmeSequenceBlendLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599930
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599940
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBase_Helper,
           classname: "DmeSequenceBase",
           pFactory: &g_CDmeSequenceBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00599990
// Name: _dynamic_initializer_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005999A0
// Name: _dynamic_initializer_for__g_CDmeSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequence_Helper,
           classname: "DmeSequence",
           pFactory: &g_CDmeSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005999F0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMultiSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599A00
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMultiSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMultiSequence_Helper,
           classname: "DmeMultiSequence",
           pFactory: &g_CDmeMultiSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E510
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceActivity_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E520
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E530
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E540
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceCalcBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E550
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceLayerBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E560
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceAddLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E570
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E580
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E590
// Name: _dynamic_atexit_destructor_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMultiSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5B0
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationEvent_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E3430
// Name: protected: void CDmeSequenceBlendLayer::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::OnConstruction(CDmeSequenceBlendLayer *this)
{
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
  this->m_bSpline.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "spline",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSpline);
  this->m_bCrossfade.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "crossfade",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bCrossfade);
  this->m_bNoBlend.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "noBlend",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bNoBlend);
  this->m_bLocal.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "local",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bLocal);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004E3640
// Name: protected: void CDmeSequenceBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::OnConstruction(CDmeSequenceBase *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // eax
  int v11; // esi
  CUtlSymbolLarge v12; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  CDmaElement<CDmeSequenceActivity>::InitAndCreate(
    this: &this->m_eActivity,
    pOwner: this,
    pAttributeName: "activity",
    pElementName: nullptr,
    flags: 0);
  value = false;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "hidden", type: AT_BOOL, pMemory: &this->m_bHidden);
  this->m_bHidden.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "delta", type: AT_BOOL, pMemory: &this->m_bDelta);
  this->m_bDelta.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "worldSpace",
         type: AT_BOOL,
         pMemory: &this->m_bWorldSpace);
  this->m_bWorldSpace.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "preDelta", type: AT_BOOL, pMemory: &this->m_bPreDelta);
  this->m_bPreDelta.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "autoPlay", type: AT_BOOL, pMemory: &this->m_bAutoPlay);
  this->m_bAutoPlay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "realtime", type: AT_BOOL, pMemory: &this->m_bRealtime);
  this->m_bRealtime.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  v12.u.m_Id = 1045220557;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadein", type: AT_FLOAT, pMemory: &this->m_flFadeIn);
  this->m_flFadeIn.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v12.u.m_Id);
  v12.u.m_Id = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadeout", type: AT_FLOAT, pMemory: &this->m_flFadeOut);
  this->m_flFadeOut.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v12.u.m_Id);
  this->m_sEntryNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "entryNode",
                                      type: AT_STRING,
                                      pMemory: &this->m_sEntryNode);
  this->m_sExitNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "exitNode",
                                     type: AT_STRING,
                                     pMemory: &this->m_sExitNode);
  this->m_bReverseNodeTransition.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "reverseNodeTransition",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bReverseNodeTransition);
  this->m_bSnap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "snap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bSnap);
  this->m_bPost.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "post",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bPost);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_eIkLockList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikLockList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkLockList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkLockList.m_pAttribute, typeSymbol: CDmeIkLock::m_classType);
  this->m_eIkLockList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eAnimationEventList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "animationEventList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eAnimationEventList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationEventList.m_pAttribute,
    typeSymbol: CDmeAnimationEvent::m_classType);
  this->m_eLayerList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "layerList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eLayerList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eLayerList.m_pAttribute,
    typeSymbol: CDmeSequenceLayerBase::m_classType);
  this->m_sKeyValues.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyValues",
                                      type: AT_STRING,
                                      pMemory: &this->m_sKeyValues);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eActivity.m_Storage.m_Handle) != 0 )
  {
    v10 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_eActivity.m_Storage.m_Handle)
                         + 20);
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    if ( _V_strcmp(s1: "unnamed", s2: v10) == 0 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_eActivity.m_Storage.m_Handle);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v12,
        a3: pDeltaStateName);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v11 + 24), value: &v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E3950
// Name: protected: void CDmeSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::OnConstruction(CDmeSequence *this)
{
  CDmaElement<CDmeDag> *p_m_eSkeleton; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  Vector v9; // [esp+8h] [ebp-14h] BYREF
  float value; // [esp+14h] [ebp-8h] BYREF
  bool v11; // [esp+1Bh] [ebp-1h] BYREF

  p_m_eSkeleton = &this->m_eSkeleton;
  this->m_eSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "skeleton",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSkeleton);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eSkeleton->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_eAnimationList.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "animationList",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_eAnimationList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationList.m_pAttribute,
    typeSymbol: CDmeAnimationList::m_classType);
  value = 30.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "fps", type: AT_FLOAT, pMemory: &this->m_flFPS);
  this->m_flFPS.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  memset(&v9, 0, sizeof(v9));
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "origin", type: AT_VECTOR3, pMemory: &this->m_vOrigin);
  this->m_vOrigin.m_pAttribute = v4;
  CDmAttribute::SetValue<Vector>(this: v4, value: &v9);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_nStartLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "startLoop",
                                      type: AT_INT,
                                      pMemory: &this->m_nStartLoop);
  this->m_bForceLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "forceLoop",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bForceLoop);
  this->m_bAutoIk.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "autoIk",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bAutoIk);
  value = 0.30000001;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "motionRollback",
         type: AT_FLOAT,
         pMemory: &this->m_flMotionRollback);
  this->m_flMotionRollback.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  v11 = true;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlocks",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlocks);
  this->m_bAnimBlocks.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v11);
  v11 = true;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlockStall",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlockStall);
  this->m_bAnimBlockStall.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v11);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: "motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_eAnimationCommandList.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "animationCommandList",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_eAnimationCommandList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationCommandList.m_pAttribute,
    typeSymbol: CDmeAnimCmd::m_classType);
  this->m_eIkRuleList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikRuleList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkRuleList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkRuleList.m_pAttribute, typeSymbol: CDmeIkRule::m_classType);
  this->m_eIkRuleList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneMask",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E3BC0
// Name: protected: void CDmeMultiSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::OnConstruction(CDmeMultiSequence *this)
{
  CDmaVar<int> *p_m_nBlendWidth; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nBlendWidth = &this->m_nBlendWidth;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "blendWidth", type: AT_INT, pMemory: &this->m_nBlendWidth);
  p_m_nBlendWidth->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_eBlendRef.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "blendRef",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBlendRef);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendRef.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendRef.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendComp.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendComp",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eBlendComp);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendComp.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendComp.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "blendCenter",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_eBlendCenter);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendCenter.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendCenter.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eSequenceList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "sequenceList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eSequenceList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequenceList.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eSequenceList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eBlendList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBlendList.m_pAttribute,
    typeSymbol: CDmeSequenceBlendBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E3D00
// Name: public: static int CDmeSequenceBase::QSortFunction(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmeSequenceBase::QSortFunction(int *pVoidSeq1, int pVoidSeq2)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  unsigned __int8 (__thiscall *v5)(int, CUtlSymbolLarge::<unnamed_type_u>); // eax
  const CDmeSequence *v6; // ebx
  const CDmeSequence *v7; // eax
  int v9; // ecx
  const CDmeSequence *v10; // ebx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // esi
  const char *m_pAsString; // eax
  const char *v15; // ecx
  int m_Size; // eax
  int v17; // ecx
  const CDmeSequence *pSeq[2]; // [esp+Ch] [ebp-10h]
  const CDmeSequence *pSeq1; // [esp+14h] [ebp-8h]
  const CDmeSequence *pSeq2; // [esp+18h] [ebp-4h]

  v2 = *pVoidSeq1;
  v3 = *(_DWORD *)pVoidSeq2;
  if ( *pVoidSeq1 == 0 || v3 == 0 )
    return 0;
  v4 = (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeSequence::m_classType.u);
  v5 = *(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16);
  v6 = v4 != 0 ? (const CDmeSequence *)v2 : nullptr;
  pSeq1 = v6;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(
         a1: v3,
         a2: (CUtlSymbolLarge::<unnamed_type_u>)CDmeSequence::m_classType.u.m_Id) != 0
     ? (const CDmeSequence *)v3
     : nullptr;
  pSeq2 = v7;
  if ( v6 == nullptr )
    return v7 != nullptr;
  if ( v7 == nullptr )
    return -1;
  v9 = 0;
  LOWORD(pVoidSeq1) = 0;
  pSeq[0] = v6;
  pSeq[1] = v7;
  pVoidSeq2 = 0;
  do
  {
    v10 = pSeq[v9];
    v11 = 0;
    if ( v10->m_eAnimationCommandList.m_Storage.m_Size > 0 )
    {
      while ( 1 )
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v10->m_eAnimationCommandList.m_Storage.m_Memory.m_pMemory[v11]);
        v13 = (_DWORD *)v12;
        if ( v12 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
               a1: v12,
               a2: CDmeAnimCmd::m_classType.u) != 0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdSubtract::m_classType.u) != 0
            && v13[17] == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
            goto LABEL_19;
          }
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdAlign::m_classType.u) != 0
            && v13[17] == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            break;
          }
        }
        if ( ++v11 >= v10->m_eAnimationCommandList.m_Storage.m_Size )
          goto LABEL_19;
      }
      *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
LABEL_19:
      v7 = pSeq2;
    }
    v9 = pVoidSeq2 + 1;
    pVoidSeq2 = v9;
  }
  while ( v9 < 2 );
  if ( (_BYTE)pVoidSeq1 != 0 )
  {
    if ( BYTE1(pVoidSeq1) == 0 )
      return 1;
    m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    v15 = pSeq1->m_Name.m_Storage.u.m_pAsString;
    if ( v15 == (const char *)-1 )
      v15 = pDeltaStateName;
    _Error(a1: "Animation %s & %s reference each other, circular references are not allowed\n", v15, m_pAsString);
    return 0;
  }
  if ( BYTE1(pVoidSeq1) != 0 )
    return -1;
  m_Size = v7->m_eAnimationCommandList.m_Storage.m_Size;
  v17 = pSeq1->m_eAnimationCommandList.m_Storage.m_Size;
  if ( v17 < m_Size )
    return -1;
  return v17 > m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004E3F20
// Name: public: class CDmeChannelsClip __near * CDmeSequence::GetDmeChannelsClip(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetDmeChannelsClip(CDmeSequence *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  v2 = v1;
  if ( v1 == 0 )
    return nullptr;
  v3 = 0;
  if ( *(int *)(v1 + 80) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      break;
    }
    if ( ++v3 >= *(_DWORD *)(v2 + 80) )
      return nullptr;
  }
  return (CDmeChannelsClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E3FA0
// Name: public: void CDmeSequence::UpdateChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::UpdateChannels(
        CDmeSequence *this,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList,
        DmeTime_t nClipTime)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  CDmeChannel *v10; // ecx
  CDmeAnimationList *pDmeAnimationList; // [esp+10h] [ebp-10h]
  int nChannelsCount; // [esp+14h] [ebp-Ch]
  DmeTime_t channelTime; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v3;
  if ( v3 != 0 )
  {
    v4 = 0;
    for ( i = 0; v4 < *(_DWORD *)(v3 + 80); i = v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v4));
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        CDmeClip::ToChildMediaTime(this: (CDmeClip *)v6, result: &channelTime, t: nClipTime, bClamp: 1);
        v7 = 0;
        nChannelsCount = *(_DWORD *)(v6 + 152);
        if ( nChannelsCount > 0 )
        {
          do
          {
            v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v6 + 140) + 4 * v7));
            v9 = v8;
            if ( v8 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                   a1: v8,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v10 = (CDmeChannel *)(v9 - 4);
            }
            else
            {
              v10 = nullptr;
            }
            CDmeChannel::SetCurrentTime(this: v10, time: channelTime);
            ++v7;
          }
          while ( v7 < nChannelsCount );
          v3 = (int)pDmeAnimationList;
        }
      }
      v4 = i + 1;
    }
    LOBYTE(pDmeAnimationList) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: dmeOperatorList);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeAnimationList *))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: pDmeAnimationList);
    g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E4110
// Name: public: class DmeFramerate_t CDmeSequence::GetFrameRate(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
DmeFramerate_t *__thiscall CDmeSequence::GetFrameRate(
        CDmeSequence *this,
        DmeFramerate_t *result,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *DmeChannelsClip; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *p_bForceFallback; // eax
  int m_Storage; // eax
  DmeFramerate_t v9; // ecx
  unsigned __int16 dmeFrameRate; // [esp+4h] [ebp-4h]

  DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this);
  if ( DmeChannelsClip != nullptr )
  {
    dmeFrameRate = fallbackFrameRate.m_num;
    if ( (_BYTE)bForceFallback != 0
      || !CDmElement::HasAttribute(this: DmeChannelsClip, pAttributeName: "frameRate", type: AT_UNKNOWN)
      || ((bForceFallback = 0,
           (Attribute = CDmElement::FindAttribute(this: DmeChannelsClip, pAttributeName: "frameRate")) == nullptr)
        ? (p_bForceFallback = (CDmaVar<int> *)&bForceFallback)
        : (p_bForceFallback = CDmAttribute::GetValue<int>(this: Attribute)),
          (m_Storage = p_bForceFallback->m_Storage) < 0) )
    {
      v9.m_den = fallbackFrameRate.m_den;
    }
    else
    {
      v9 = *DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&bForceFallback, fps: m_Storage);
      dmeFrameRate = v9.m_num;
    }
    result->m_num = dmeFrameRate;
    result->m_den = v9.m_den;
    return result;
  }
  else
  {
    *result = fallbackFrameRate;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E41C0
// Name: public: int CDmeSequence::GetFrameCount(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetFrameCount(
        CDmeSequence *this,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *result; // eax
  CDmeClip *v5; // esi
  DmeFramerate_t v6; // kr00_4
  int v7; // eax
  DmeTime_t nEndTime; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t nStartTime; // [esp+10h] [ebp-4h] BYREF

  result = CDmeSequence::GetDmeChannelsClip(this);
  v5 = result;
  if ( result != nullptr )
  {
    CDmeSequence::GetFrameRate(this, result: (DmeFramerate_t *)&bForceFallback, fallbackFrameRate, bForceFallback);
    CDmeClip::GetStartTime(this: v5, result: &nStartTime);
    v6 = (DmeFramerate_t)bForceFallback;
    bForceFallback = FrameForTime(t: nStartTime, framerate: (DmeFramerate_t)bForceFallback);
    CDmeClip::GetEndTime(this: v5, result: &nEndTime);
    v7 = FrameForTime(t: nEndTime, framerate: v6);
    return (CDmeChannelsClip *)(v7 - bForceFallback + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E4260
// Name: public: void CDmeSequence::GetDependentOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class CDmeOperator __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::GetDependentOperators(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CDmeOperator *pDmeOperator)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v3; // edx
  int k; // edi
  CUtlSymbolTable::StringPool_t *v5; // esi
  int *p_m_SpaceUsed; // esi
  CDmeOperator *v7; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v10; // ecx
  int v11; // eax
  CUtlSymbolTable::StringPool_t **v12; // esi
  void (__thiscall *GetOutputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  CDmAttribute **v14; // eax
  int v15; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // edx
  int v18; // eax
  CExpressionCalculator *v19; // esi
  CDmAttribute **v20; // edi
  void (__stdcall *v21)(CUtlSymbolLarge *, const char *); // edx
  int m; // edi
  CDmElement *v23; // esi
  CDmeOperator *v24; // eax
  CUtlSymbolLarge v25; // [esp-Ch] [ebp-64h] BYREF
  BOOL v26; // [esp-8h] [ebp-60h]
  TraversalDepth_t v27; // [esp-4h] [ebp-5Ch]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-38h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-24h] BYREF
  CDmElement *pDmElement; // [esp+48h] [ebp-10h]
  CDmElement *v32; // [esp+4Ch] [ebp-Ch]
  CDmeSequence *v33; // [esp+50h] [ebp-8h]
  int j; // [esp+54h] [ebp-4h]
  int i; // [esp+64h] [ebp+Ch]

  v33 = this;
  if ( pDmeOperator != nullptr )
  {
    v32 = &pDmeOperator->CDmElement;
    if ( pDmeOperator != (CDmeOperator *)-4
      && ((int (__thiscall *)(_DWORD, _DWORD))pDmeOperator->IsA)(
           a1: &pDmeOperator->CDmElement,
           a2: (CUtlSymbolLarge)CDmeOperator::m_classType.u.m_Id) )
    {
      v3 = operatorList;
      for ( k = 0; k < (int)v3[1].m_pMemory; ++k )
      {
        v5 = v3->m_pMemory[k];
        if ( v5 != nullptr )
        {
          p_m_SpaceUsed = &v5->m_SpaceUsed;
          if ( p_m_SpaceUsed != nullptr )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*p_m_SpaceUsed + 16))(
                   a1: p_m_SpaceUsed,
                   a2: CDmeOperator::m_classType.u) != 0 )
            {
              v7 = (CDmeOperator *)(p_m_SpaceUsed - 1);
              if ( v7 != nullptr && v7 == pDmeOperator )
                return;
            }
            v3 = operatorList;
          }
        }
      }
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = operatorList;
      }
      ++v3[1].m_pMemory;
      v10 = v3->m_pMemory;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v11 > 0 )
      {
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
        v3 = operatorList;
      }
      v12 = &v3->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = (CUtlSymbolTable::StringPool_t *)pDmeOperator;
      GetOutputAttributes = pDmeOperator->GetOutputAttributes;
      memset(&outAttrList, 0, sizeof(outAttrList));
      GetOutputAttributes(this: pDmeOperator, a2: &outAttrList);
      v14 = outAttrList.m_Memory.m_pMemory;
      v15 = 0;
      for ( i = 0; v15 < outAttrList.m_Size; i = v15 )
      {
        m_pOwner = v14[v15]->m_pOwner;
        pDmElement = m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner != v32 )
          {
            v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v27 = TD_ALL;
            v26 = false;
            v25.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v17(a1: &v25, a2: "element");
            FindReferringElements<CDmElement>(
              list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList0,
              pElement: (CExpressionCalculator *)m_pOwner,
              symAttrName: v25,
              bMustBeInSameFile: v26,
              depth: v27);
            v18 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v19 = (CExpressionCalculator *)reList0.m_Memory.m_pMemory[v18];
                if ( v19 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v19->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v19,
                       a2: CDmeAttributeReference::m_classType.u) != 0 )
                {
                  v20 = &outAttrList.m_Memory.m_pMemory[v15];
                  if ( CDmeAttributeReference::GetReferencedAttribute(this: (CDmeAttributeReference *)v19) == *v20 )
                  {
                    v21 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                    v27 = TD_ALL;
                    v26 = false;
                    v25.u.m_Id = g_pDataModel.u.m_Id;
                    memset(&reList1, 0, sizeof(reList1));
                    v21(a1: &v25, a2: "input");
                    FindReferringElements<CDmElement>(
                      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList1,
                      pElement: v19,
                      symAttrName: v25,
                      bMustBeInSameFile: v26,
                      depth: v27);
                    for ( m = 0; m < reList1.m_Size; ++m )
                    {
                      v23 = reList1.m_Memory.m_pMemory[m];
                      if ( v23 != nullptr
                        && v23->IsA(this: v23, a2: CDmeConnectionOperator::m_classType)
                        && v23 != (CDmElement *)4 )
                      {
                        CDmeSequence::GetDependentOperators(
                          this: v33,
                          (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                          pDmeOperator: (CDmeOperator *)((char *)&v23[-1] + 64));
                      }
                    }
                    if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                  }
                }
                v15 = i;
                v18 = j + 1;
                j = v18;
              }
              while ( v18 < reList0.m_Size );
              m_pOwner = pDmElement;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v24 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v24 = nullptr;
          CDmeSequence::GetDependentOperators(
            this: v33,
            (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
            pDmeOperator: v24);
          v14 = outAttrList.m_Memory.m_pMemory;
        }
        ++v15;
      }
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
          v14 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v14;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E4570
// Name: public: void CDmeSequence::PrepareChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PrepareChannels(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *dmeOperatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeAnimationList *pDmeAnimationList; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  dmeOperatorList[1].m_pMemory = nullptr;
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v2;
  if ( v2 != 0 )
  {
    v3 = 0;
    for ( i = 0; v3 < *(_DWORD *)(v2 + 80); i = v3 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        v6 = 0;
        if ( *(int *)(v5 + 152) > 0 )
        {
          do
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v5 + 140) + 4 * v6));
            v8 = v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v9 = (CDmeChannel *)(v8 - 4);
              if ( v9 != nullptr )
              {
                CDmeChannel::SetMode(this: v9, mode: CM_PLAY);
                CDmeSequence::GetDependentOperators(this, operatorList: dmeOperatorList, pDmeOperator: v9);
              }
            }
            ++v6;
          }
          while ( v6 < *(_DWORD *)(v5 + 152) );
          v2 = (int)pDmeAnimationList;
        }
      }
      v3 = i + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E4710
// Name: public: virtual bool CDmeAnimationEvent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationEvent::IsA(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4740
// Name: public: virtual int CDmeAnimationEvent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::GetInheritanceDepth(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4780
// Name: protected: virtual int CDmeAnimationEvent::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x004E4800
// Name: protected: virtual void CDmeAnimationEvent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationEvent::PerformConstruction(CDmeAnimationEvent *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
  this->m_sDataString.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "dataString",
                                       type: AT_STRING,
                                       pMemory: &this->m_sDataString);
}

//------------------------------------------------------------------------------
// Address: 0x004E4930
// Name: public: virtual bool CDmeSequenceBlendBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendBase::IsA(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4960
// Name: public: virtual int CDmeSequenceBlendBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendBase::GetInheritanceDepth(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4A00
// Name: protected: virtual void CDmeSequenceBlendBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendBase::PerformConstruction(CDmeSequenceBlendBase *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004E4AC0
// Name: public: virtual bool CDmeSequenceBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlend::IsA(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4AF0
// Name: public: virtual int CDmeSequenceBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::GetInheritanceDepth(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4BC0
// Name: protected: virtual void CDmeSequenceBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlend::PerformConstruction(CDmeSequenceBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_flParamStart.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "paramStart",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flParamStart);
  this->m_flParamEnd.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "paramEnd",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flParamEnd);
}

//------------------------------------------------------------------------------
// Address: 0x004E4CA0
// Name: public: virtual bool CDmeSequenceCalcBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceCalcBlend::IsA(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4CD0
// Name: public: virtual int CDmeSequenceCalcBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceCalcBlend::GetInheritanceDepth(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4D90
// Name: protected: virtual void CDmeSequenceCalcBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceCalcBlend::PerformConstruction(CDmeSequenceCalcBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: "motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E4E70
// Name: public: virtual bool CDmeSequenceLayerBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceLayerBase::IsA(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4EA0
// Name: public: virtual int CDmeSequenceLayerBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceLayerBase::GetInheritanceDepth(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4FD0
// Name: public: virtual bool CDmeSequenceAddLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceAddLayer::IsA(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5000
// Name: public: virtual int CDmeSequenceAddLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::GetInheritanceDepth(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E50B0
// Name: protected: virtual void CDmeSequenceLayerBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceLayerBase::PerformConstruction(CDmeSequenceAddLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E5150
// Name: protected: CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *__thiscall CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(
        CDmeSequenceBlendLayer *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_eAnimation.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimation.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimation.m_pAttribute = nullptr;
  this->__vftable = (CDmeSequenceBlendLayer_vtbl *)&CDmeSequenceBlendLayer::`vftable';
  this->m_flStartFrame = 0;
  this->m_flPeakFrame = 0;
  this->m_flTailFrame = 0;
  this->m_flEndFrame = 0;
  this->m_bSpline.m_pAttribute = nullptr;
  this->m_bSpline.m_Storage = false;
  this->m_bCrossfade.m_pAttribute = nullptr;
  this->m_bCrossfade.m_Storage = false;
  this->m_bNoBlend.m_pAttribute = nullptr;
  this->m_bNoBlend.m_Storage = false;
  this->m_bLocal.m_pAttribute = nullptr;
  this->m_bLocal.m_Storage = false;
  this->m_sPoseParameterName.m_pAttribute = nullptr;
  this->m_sPoseParameterName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E5210
// Name: public: virtual bool CDmeSequenceBlendLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendLayer::IsA(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5240
// Name: public: virtual int CDmeSequenceBlendLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendLayer::GetInheritanceDepth(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E52D0
// Name: protected: virtual void CDmeSequenceBlendLayer::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::PerformConstruction(CDmeSequenceBlendLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  CDmeSequenceBlendLayer::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5430
// Name: protected: CDmeSequenceBase::CDmeSequenceBase(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBase *__thiscall CDmeSequenceBase::CDmeSequenceBase(
        CDmeSequenceBase *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequenceBase_vtbl *)&CDmeSequenceBase::`vftable';
  this->m_eActivity.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eActivity.m_pAttribute = nullptr;
  this->m_eActivity.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_bHidden.m_pAttribute = nullptr;
  this->m_bHidden.m_Storage = false;
  this->m_bDelta.m_pAttribute = nullptr;
  this->m_bDelta.m_Storage = false;
  this->m_bWorldSpace.m_pAttribute = nullptr;
  this->m_bWorldSpace.m_Storage = false;
  this->m_bPreDelta.m_pAttribute = nullptr;
  this->m_bPreDelta.m_Storage = false;
  this->m_bAutoPlay.m_pAttribute = nullptr;
  this->m_bAutoPlay.m_Storage = false;
  this->m_bRealtime.m_pAttribute = nullptr;
  this->m_bRealtime.m_Storage = false;
  this->m_flFadeIn = 0;
  this->m_flFadeOut = 0;
  this->m_sEntryNode.m_pAttribute = nullptr;
  this->m_sEntryNode.m_Storage.u.m_Id = -1;
  this->m_sExitNode.m_pAttribute = nullptr;
  this->m_sExitNode.m_Storage.u.m_Id = -1;
  this->m_bReverseNodeTransition.m_pAttribute = nullptr;
  this->m_bReverseNodeTransition.m_Storage = false;
  this->m_bSnap.m_pAttribute = nullptr;
  this->m_bSnap.m_Storage = false;
  this->m_bPost.m_pAttribute = nullptr;
  this->m_bPost.m_Storage = false;
  this->m_bLoop.m_pAttribute = nullptr;
  this->m_bLoop.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkLockList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationEventList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eLayerList);
  this->m_sKeyValues.m_Storage.u.m_Id = -1;
  this->m_sKeyValues.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E5530
// Name: public: virtual bool CDmeSequenceBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBase::IsA(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5560
// Name: public: virtual int CDmeSequenceBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::GetInheritanceDepth(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E55A0
// Name: protected: virtual int CDmeSequenceBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::AllocatedSize(CDmeSequenceBase *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x004E55B0
// Name: protected: virtual void CDmeSequenceBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::PerformConstruction(CDmeSequenceBase *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5610
// Name: protected: CDmeSequence::CDmeSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequence *__thiscall CDmeSequence::CDmeSequence(
        CDmeSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequence_vtbl *)&CDmeSequence::`vftable';
  this->m_eSkeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eSkeleton.m_pAttribute = nullptr;
  this->m_eSkeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimationList.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimationList.m_pAttribute = nullptr;
  this->m_eAnimationList.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flFPS = 0;
  this->m_vOrigin.m_pAttribute = nullptr;
  this->m_vOrigin.m_Storage.x = 0.0;
  this->m_vOrigin.m_Storage.y = 0.0;
  this->m_vOrigin.m_Storage.z = 0.0;
  this->m_flScale = 0;
  this->m_nStartLoop.m_pAttribute = nullptr;
  this->m_nStartLoop.m_Storage = 0;
  this->m_bForceLoop.m_pAttribute = nullptr;
  this->m_bForceLoop.m_Storage = false;
  this->m_bAutoIk.m_pAttribute = nullptr;
  this->m_bAutoIk.m_Storage = false;
  this->m_flMotionRollback = 0;
  this->m_bAnimBlocks.m_pAttribute = nullptr;
  this->m_bAnimBlocks.m_Storage = false;
  this->m_bAnimBlockStall.m_pAttribute = nullptr;
  this->m_bAnimBlockStall.m_Storage = false;
  this->m_eMotionControl.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMotionControl.m_pAttribute = nullptr;
  this->m_eMotionControl.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationCommandList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkRuleList);
  this->m_eBoneMask.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBoneMask.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBoneMask.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E5730
// Name: public: virtual bool CDmeSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequence::IsA(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5760
// Name: public: virtual int CDmeSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::GetInheritanceDepth(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E57B0
// Name: protected: virtual int CDmeSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::AllocatedSize(CDmeSequence *this)
{
  return 468;
}

//------------------------------------------------------------------------------
// Address: 0x004E57C0
// Name: protected: virtual void CDmeSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PerformConstruction(CDmeSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5850
// Name: protected: CDmeMultiSequence::CDmeMultiSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMultiSequence *__thiscall CDmeMultiSequence::CDmeMultiSequence(
        CDmeMultiSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMultiSequence_vtbl *)&CDmeMultiSequence::`vftable';
  this->m_nBlendWidth.m_pAttribute = nullptr;
  this->m_nBlendWidth.m_Storage = 0;
  this->m_eBlendRef.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendRef.m_pAttribute = nullptr;
  this->m_eBlendRef.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendComp.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendComp.m_pAttribute = nullptr;
  this->m_eBlendComp.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendCenter.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendCenter.m_pAttribute = nullptr;
  this->m_eBlendCenter.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eSequenceList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eBlendList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E58E0
// Name: public: virtual bool CDmeMultiSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMultiSequence::IsA(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5910
// Name: public: virtual int CDmeMultiSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::GetInheritanceDepth(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5960
// Name: protected: virtual int CDmeMultiSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::AllocatedSize(CDmeMultiSequence *this)
{
  return 384;
}

//------------------------------------------------------------------------------
// Address: 0x004E5970
// Name: protected: virtual void CDmeMultiSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::PerformConstruction(CDmeMultiSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeMultiSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E5AC0
// Name: public: virtual bool CDmeSequenceActivity::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceActivity::IsA(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5AF0
// Name: public: virtual int CDmeSequenceActivity::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceActivity::GetInheritanceDepth(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5B30
// Name: protected: virtual void CDmeSequenceActivity::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceActivity::PerformConstruction(CDmeSequenceActivity *this)
{
  CDmAttribute *v2; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_INT, pMemory: &this->m_nWeight);
  this->m_nWeight.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_sModifierList,
    pOwner: this,
    pAttributeName: "modifierList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EA390
// Name: protected: virtual int CDmeSequenceBlend::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x0050BAE0
// Name: protected: virtual int CDmeSequenceAddLayer::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x005ED5E0
// Name: _dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationEvent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationEvent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED640
// Name: _dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceActivity::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceActivity pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED6A0
// Name: _dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendBase::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED700
// Name: _dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlend::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED760
// Name: _dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceCalcBlend::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceCalcBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED7C0
// Name: _dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceLayerBase::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceLayerBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED820
// Name: _dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceAddLayer::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceAddLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED880
// Name: _dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendLayer::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8E0
// Name: _dynamic_initializer_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBase::s_Allocator,
    blockSize: 284,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED940
// Name: _dynamic_initializer_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequence::s_Allocator,
    blockSize: 468,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9A0
// Name: _dynamic_initializer_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMultiSequence::s_Allocator,
    blockSize: 384,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMultiSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3330
// Name: _dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationEvent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3340
// Name: _dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceActivity::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3350
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3360
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3370
// Name: _dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceCalcBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3380
// Name: _dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceLayerBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3390
// Name: _dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceAddLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F33A0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F33B0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F33C0
// Name: _dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F33D0
// Name: _dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMultiSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED610
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationEvent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED620
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationEvent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationEvent_Helper,
           classname: "DmeAnimationEvent",
           pFactory: &g_CDmeAnimationEvent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED670
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceActivity_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED680
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceActivity_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceActivity_Helper,
           classname: "DmeSequenceActivity",
           pFactory: &g_CDmeSequenceActivity_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED6D0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED6E0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendBase_Helper,
           classname: "DmeSequenceBlendBase",
           pFactory: &g_CDmeSequenceBlendBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED730
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED740
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlend_Helper,
           classname: "DmeSequenceBlend",
           pFactory: &g_CDmeSequenceBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED790
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED7A0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceCalcBlend_Helper,
           classname: "DmeSequenceCalcBlend",
           pFactory: &g_CDmeSequenceCalcBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED7F0
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED800
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceLayerBase_Helper,
           classname: "DmeSequenceLayerBase",
           pFactory: &g_CDmeSequenceLayerBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED850
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED860
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceAddLayer_Helper,
           classname: "DmeSequenceAddLayer",
           pFactory: &g_CDmeSequenceAddLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8B0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED8C0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendLayer_Helper,
           classname: "DmeSequenceBlendLayer",
           pFactory: &g_CDmeSequenceBlendLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED910
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED920
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBase_Helper,
           classname: "DmeSequenceBase",
           pFactory: &g_CDmeSequenceBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED970
// Name: _dynamic_initializer_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED980
// Name: _dynamic_initializer_for__g_CDmeSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequence_Helper,
           classname: "DmeSequence",
           pFactory: &g_CDmeSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9D0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMultiSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9E0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMultiSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMultiSequence_Helper,
           classname: "DmeMultiSequence",
           pFactory: &g_CDmeMultiSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F33E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceActivity_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F33F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3400
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3410
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceCalcBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3420
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceLayerBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3430
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceAddLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3440
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3450
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3460
// Name: _dynamic_atexit_destructor_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequence_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3470
// Name: _dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMultiSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3480
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationEvent_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005112E0
// Name: protected: void CDmeSequenceBlendLayer::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::OnConstruction(CDmeSequenceBlendLayer *this)
{
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
  this->m_bSpline.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "spline",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSpline);
  this->m_bCrossfade.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "crossfade",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bCrossfade);
  this->m_bNoBlend.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "noBlend",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bNoBlend);
  this->m_bLocal.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "local",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bLocal);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x00511450
// Name: protected: void CDmeSequenceBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::OnConstruction(CDmeSequenceBase *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // eax
  int v11; // esi
  CUtlSymbolLarge v12; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  CDmaElement<CDmeSequenceActivity>::InitAndCreate(
    this: &this->m_eActivity,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"activity",
    pElementName: nullptr,
    flags: 0);
  value = false;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "hidden", type: AT_BOOL, pMemory: &this->m_bHidden);
  this->m_bHidden.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "delta", type: AT_BOOL, pMemory: &this->m_bDelta);
  this->m_bDelta.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "worldSpace",
         type: AT_BOOL,
         pMemory: &this->m_bWorldSpace);
  this->m_bWorldSpace.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "preDelta", type: AT_BOOL, pMemory: &this->m_bPreDelta);
  this->m_bPreDelta.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "autoPlay", type: AT_BOOL, pMemory: &this->m_bAutoPlay);
  this->m_bAutoPlay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "realtime", type: AT_BOOL, pMemory: &this->m_bRealtime);
  this->m_bRealtime.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  v12.u.m_Id = 1045220557;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadein", type: AT_FLOAT, pMemory: &this->m_flFadeIn);
  this->m_flFadeIn.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&v12.u.m_Id);
  v12.u.m_Id = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadeout", type: AT_FLOAT, pMemory: &this->m_flFadeOut);
  this->m_flFadeOut.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&v12.u.m_Id);
  this->m_sEntryNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "entryNode",
                                      type: AT_STRING,
                                      pMemory: &this->m_sEntryNode);
  this->m_sExitNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "exitNode",
                                     type: AT_STRING,
                                     pMemory: &this->m_sExitNode);
  this->m_bReverseNodeTransition.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "reverseNodeTransition",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bReverseNodeTransition);
  this->m_bSnap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "snap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bSnap);
  this->m_bPost.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "post",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bPost);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_eIkLockList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikLockList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkLockList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkLockList.m_pAttribute, typeSymbol: CDmeIkLock::m_classType);
  this->m_eIkLockList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eAnimationEventList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "animationEventList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eAnimationEventList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationEventList.m_pAttribute,
    typeSymbol: CDmeAnimationEvent::m_classType);
  this->m_eLayerList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "layerList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eLayerList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eLayerList.m_pAttribute,
    typeSymbol: CDmeSequenceLayerBase::m_classType);
  this->m_sKeyValues.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyValues",
                                      type: AT_STRING,
                                      pMemory: &this->m_sKeyValues);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eActivity.m_Storage.m_Handle) != 0 )
  {
    v10 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_eActivity.m_Storage.m_Handle)
                         + 20);
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    if ( _V_strcmp(s1: "unnamed", s2: v10) == 0 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_eActivity.m_Storage.m_Handle);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v12,
        a3: defaultValue);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v11 + 24), value: &v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511760
// Name: protected: void CDmeSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::OnConstruction(CDmeSequence *this)
{
  CDmaElement<CDmeDag> *p_m_eSkeleton; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  Vector v9; // [esp+8h] [ebp-14h] BYREF
  float value; // [esp+14h] [ebp-8h] BYREF
  bool v11; // [esp+1Bh] [ebp-1h] BYREF

  p_m_eSkeleton = &this->m_eSkeleton;
  this->m_eSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "skeleton",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSkeleton);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eSkeleton->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_eAnimationList.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "animationList",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_eAnimationList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationList.m_pAttribute,
    typeSymbol: CDmeAnimationList::m_classType);
  value = 30.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "fps", type: AT_FLOAT, pMemory: &this->m_flFPS);
  this->m_flFPS.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  memset(&v9, 0, sizeof(v9));
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "origin", type: AT_VECTOR3, pMemory: &this->m_vOrigin);
  this->m_vOrigin.m_pAttribute = v4;
  CDmAttribute::SetValue<Vector>(this: v4, value: &v9);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_nStartLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "startLoop",
                                      type: AT_INT,
                                      pMemory: &this->m_nStartLoop);
  this->m_bForceLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "forceLoop",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bForceLoop);
  this->m_bAutoIk.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "autoIk",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bAutoIk);
  value = 0.30000001;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "motionRollback",
         type: AT_FLOAT,
         pMemory: &this->m_flMotionRollback);
  this->m_flMotionRollback.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  v11 = true;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlocks",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlocks);
  this->m_bAnimBlocks.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v11);
  v11 = true;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlockStall",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlockStall);
  this->m_bAnimBlockStall.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v11);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_eAnimationCommandList.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "animationCommandList",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_eAnimationCommandList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationCommandList.m_pAttribute,
    typeSymbol: CDmeAnimCmd::m_classType);
  this->m_eIkRuleList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikRuleList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkRuleList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkRuleList.m_pAttribute, typeSymbol: CDmeIkRule::m_classType);
  this->m_eIkRuleList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneMask",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005119D0
// Name: protected: void CDmeMultiSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::OnConstruction(CDmeMultiSequence *this)
{
  CDmaVar<int> *p_m_nBlendWidth; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nBlendWidth = &this->m_nBlendWidth;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "blendWidth", type: AT_INT, pMemory: &this->m_nBlendWidth);
  p_m_nBlendWidth->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_eBlendRef.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "blendRef",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBlendRef);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendRef.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendRef.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendComp.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendComp",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eBlendComp);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendComp.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendComp.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "blendCenter",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_eBlendCenter);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendCenter.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendCenter.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eSequenceList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "sequenceList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eSequenceList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequenceList.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eSequenceList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eBlendList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBlendList.m_pAttribute,
    typeSymbol: CDmeSequenceBlendBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00511B10
// Name: public: static int CDmeSequenceBase::QSortFunction(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmeSequenceBase::QSortFunction(int *pVoidSeq1, int pVoidSeq2)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  unsigned __int8 (__thiscall *v5)(int, CUtlSymbolLarge::<unnamed_type_u>); // eax
  const CDmeSequence *v6; // ebx
  const CDmeSequence *v7; // eax
  int v9; // ecx
  const CDmeSequence *v10; // ebx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // esi
  const char *m_pAsString; // eax
  const char *v15; // ecx
  int m_Size; // eax
  int v17; // ecx
  const CDmeSequence *pSeq[2]; // [esp+Ch] [ebp-10h]
  const CDmeSequence *pSeq1; // [esp+14h] [ebp-8h]
  const CDmeSequence *pSeq2; // [esp+18h] [ebp-4h]

  v2 = *pVoidSeq1;
  v3 = *(_DWORD *)pVoidSeq2;
  if ( *pVoidSeq1 == 0 || v3 == 0 )
    return 0;
  v4 = (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeSequence::m_classType.u);
  v5 = *(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16);
  v6 = v4 != 0 ? (const CDmeSequence *)v2 : nullptr;
  pSeq1 = v6;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(
         a1: v3,
         a2: (CUtlSymbolLarge::<unnamed_type_u>)CDmeSequence::m_classType.u.m_Id) != 0
     ? (const CDmeSequence *)v3
     : nullptr;
  pSeq2 = v7;
  if ( v6 == nullptr )
    return v7 != nullptr;
  if ( v7 == nullptr )
    return -1;
  v9 = 0;
  LOWORD(pVoidSeq1) = 0;
  pSeq[0] = v6;
  pSeq[1] = v7;
  pVoidSeq2 = 0;
  do
  {
    v10 = pSeq[v9];
    v11 = 0;
    if ( v10->m_eAnimationCommandList.m_Storage.m_Size > 0 )
    {
      while ( 1 )
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v10->m_eAnimationCommandList.m_Storage.m_Memory.m_pMemory[v11]);
        v13 = (_DWORD *)v12;
        if ( v12 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
               a1: v12,
               a2: CDmeAnimCmd::m_classType.u) != 0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdSubtract::m_classType.u) != 0
            && v13[17] == CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
            goto LABEL_19;
          }
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdAlign::m_classType.u) != 0
            && v13[17] == CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            break;
          }
        }
        if ( ++v11 >= v10->m_eAnimationCommandList.m_Storage.m_Size )
          goto LABEL_19;
      }
      *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
LABEL_19:
      v7 = pSeq2;
    }
    v9 = pVoidSeq2 + 1;
    pVoidSeq2 = v9;
  }
  while ( v9 < 2 );
  if ( (_BYTE)pVoidSeq1 != 0 )
  {
    if ( BYTE1(pVoidSeq1) == 0 )
      return 1;
    m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v15 = pSeq1->m_Name.m_Storage.u.m_pAsString;
    if ( v15 == (const char *)-1 )
      v15 = defaultValue;
    _Error(a1: "Animation %s & %s reference each other, circular references are not allowed\n", v15, m_pAsString);
    return 0;
  }
  if ( BYTE1(pVoidSeq1) != 0 )
    return -1;
  m_Size = v7->m_eAnimationCommandList.m_Storage.m_Size;
  v17 = pSeq1->m_eAnimationCommandList.m_Storage.m_Size;
  if ( v17 < m_Size )
    return -1;
  return v17 > m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00511D30
// Name: public: class CDmeChannelsClip __near * CDmeSequence::GetDmeChannelsClip(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetDmeChannelsClip(CDmeSequence *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  v2 = v1;
  if ( v1 == 0 )
    return nullptr;
  v3 = 0;
  if ( *(int *)(v1 + 80) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      break;
    }
    if ( ++v3 >= *(_DWORD *)(v2 + 80) )
      return nullptr;
  }
  return (CDmeChannelsClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00511DB0
// Name: public: void CDmeSequence::UpdateChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::UpdateChannels(
        CDmeSequence *this,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList,
        DmeTime_t nClipTime)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  CDmeChannel *v10; // ecx
  CDmeAnimationList *pDmeAnimationList; // [esp+10h] [ebp-10h]
  int nChannelsCount; // [esp+14h] [ebp-Ch]
  DmeTime_t channelTime; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v3;
  if ( v3 != 0 )
  {
    v4 = 0;
    for ( i = 0; v4 < *(_DWORD *)(v3 + 80); i = v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v4));
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        CDmeClip::ToChildMediaTime(this: (CDmeClip *)v6, result: &channelTime, t: nClipTime, bClamp: 1);
        v7 = 0;
        nChannelsCount = *(_DWORD *)(v6 + 152);
        if ( nChannelsCount > 0 )
        {
          do
          {
            v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v6 + 140) + 4 * v7));
            v9 = v8;
            if ( v8 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                   a1: v8,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v10 = (CDmeChannel *)(v9 - 4);
            }
            else
            {
              v10 = nullptr;
            }
            CDmeChannel::SetCurrentTime(this: v10, time: channelTime);
            ++v7;
          }
          while ( v7 < nChannelsCount );
          v3 = (int)pDmeAnimationList;
        }
      }
      v4 = i + 1;
    }
    LOBYTE(pDmeAnimationList) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: dmeOperatorList);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeAnimationList *))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: pDmeAnimationList);
    g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511F20
// Name: public: class DmeFramerate_t CDmeSequence::GetFrameRate(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
DmeFramerate_t *__thiscall CDmeSequence::GetFrameRate(
        CDmeSequence *this,
        DmeFramerate_t *result,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *DmeChannelsClip; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *p_bForceFallback; // eax
  int m_Storage; // eax
  DmeFramerate_t v9; // ecx
  unsigned __int16 dmeFrameRate; // [esp+4h] [ebp-4h]

  DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this);
  if ( DmeChannelsClip != nullptr )
  {
    dmeFrameRate = fallbackFrameRate.m_num;
    if ( (_BYTE)bForceFallback != 0
      || !CDmElement::HasAttribute(this: DmeChannelsClip, pAttributeName: "frameRate", type: AT_UNKNOWN)
      || ((bForceFallback = 0,
           (Attribute = CDmElement::FindAttribute(this: DmeChannelsClip, pAttributeName: "frameRate")) == nullptr)
        ? (p_bForceFallback = (CDmaVar<int> *)&bForceFallback)
        : (p_bForceFallback = CDmAttribute::GetValue<int>(this: Attribute)),
          (m_Storage = p_bForceFallback->m_Storage) < 0) )
    {
      v9.m_den = fallbackFrameRate.m_den;
    }
    else
    {
      v9 = *DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&bForceFallback, fps: m_Storage);
      dmeFrameRate = v9.m_num;
    }
    result->m_num = dmeFrameRate;
    result->m_den = v9.m_den;
    return result;
  }
  else
  {
    *result = fallbackFrameRate;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00511FD0
// Name: public: int CDmeSequence::GetFrameCount(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetFrameCount(
        CDmeSequence *this,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *result; // eax
  CDmeClip *v5; // esi
  DmeFramerate_t v6; // kr00_4
  int v7; // eax
  DmeTime_t nEndTime; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t nStartTime; // [esp+10h] [ebp-4h] BYREF

  result = CDmeSequence::GetDmeChannelsClip(this);
  v5 = result;
  if ( result != nullptr )
  {
    CDmeSequence::GetFrameRate(this, result: (DmeFramerate_t *)&bForceFallback, fallbackFrameRate, bForceFallback);
    CDmeClip::GetStartTime(this: v5, result: &nStartTime);
    v6 = (DmeFramerate_t)bForceFallback;
    bForceFallback = FrameForTime(t: nStartTime, framerate: (DmeFramerate_t)bForceFallback);
    CDmeClip::GetEndTime(this: v5, result: &nEndTime);
    v7 = FrameForTime(t: nEndTime, framerate: v6);
    return (CDmeChannelsClip *)(v7 - bForceFallback + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00512070
// Name: public: void CDmeSequence::GetDependentOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class CDmeOperator __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::GetDependentOperators(
        CDmeSequence *this,
        CUtlMemory<vgui::TreeNode *,int> *operatorList,
        CDmeOperator *pDmeOperator)
{
  CUtlMemory<vgui::TreeNode *,int> *v3; // edx
  int k; // edi
  vgui::TreeNode *v5; // esi
  vgui::Panel::Panel_RegisterMap *p_m_RegisterClass; // esi
  CDmeOperator *v7; // esi
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // esi
  void (__thiscall *GetOutputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  CDmAttribute **v14; // eax
  int v15; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // edx
  int v18; // eax
  CExpressionCalculator *v19; // esi
  CDmAttribute **v20; // edi
  void (__stdcall *v21)(CUtlSymbolLarge *, const char *); // edx
  int m; // edi
  CDmElement *v23; // esi
  CDmeOperator *v24; // eax
  CUtlSymbolLarge v25; // [esp-Ch] [ebp-64h] BYREF
  BOOL v26; // [esp-8h] [ebp-60h]
  TraversalDepth_t v27; // [esp-4h] [ebp-5Ch]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-38h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-24h] BYREF
  CDmElement *pDmElement; // [esp+48h] [ebp-10h]
  CDmElement *v32; // [esp+4Ch] [ebp-Ch]
  CDmeSequence *v33; // [esp+50h] [ebp-8h]
  int j; // [esp+54h] [ebp-4h]
  int i; // [esp+64h] [ebp+Ch]

  v33 = this;
  if ( pDmeOperator != nullptr )
  {
    v32 = &pDmeOperator->CDmElement;
    if ( pDmeOperator != (CDmeOperator *)-4
      && ((int (__thiscall *)(_DWORD, _DWORD))pDmeOperator->IsA)(
           a1: &pDmeOperator->CDmElement,
           a2: (CUtlSymbolLarge)CDmeOperator::m_classType.u.m_Id) )
    {
      v3 = operatorList;
      for ( k = 0; k < (int)v3[1].m_pMemory; ++k )
      {
        v5 = v3->m_pMemory[k];
        if ( v5 != nullptr )
        {
          p_m_RegisterClass = &v5->vgui::Panel::m_RegisterClass;
          if ( p_m_RegisterClass != nullptr )
          {
            if ( (*(unsigned __int8 (__thiscall **)(vgui::Panel::Panel_RegisterMap *, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)p_m_RegisterClass + 16))(
                   a1: p_m_RegisterClass,
                   a2: CDmeOperator::m_classType.u) != 0 )
            {
              v7 = (CDmeOperator *)&p_m_RegisterClass[-4];
              if ( v7 != nullptr && v7 == pDmeOperator )
                return;
            }
            v3 = operatorList;
          }
        }
      }
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = operatorList;
      }
      ++v3[1].m_pMemory;
      v10 = v3->m_pMemory;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v11 > 0 )
      {
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
        v3 = operatorList;
      }
      v12 = &v3->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = (vgui::TreeNode *)pDmeOperator;
      GetOutputAttributes = pDmeOperator->GetOutputAttributes;
      memset(&outAttrList, 0, sizeof(outAttrList));
      GetOutputAttributes(this: pDmeOperator, a2: &outAttrList);
      v14 = outAttrList.m_Memory.m_pMemory;
      v15 = 0;
      for ( i = 0; v15 < outAttrList.m_Size; i = v15 )
      {
        m_pOwner = v14[v15]->m_pOwner;
        pDmElement = m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner != v32 )
          {
            v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v27 = TD_ALL;
            v26 = false;
            v25.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v17(a1: &v25, a2: "element");
            FindReferringElements<CDmElement>(
              list: (CUtlMemory<vgui::TreeNode *,int> *)&reList0,
              pElement: (CExpressionCalculator *)m_pOwner,
              symAttrName: v25,
              bMustBeInSameFile: v26,
              depth: v27);
            v18 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v19 = (CExpressionCalculator *)reList0.m_Memory.m_pMemory[v18];
                if ( v19 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v19->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v19,
                       a2: CDmeAttributeReference::m_classType.u) != 0 )
                {
                  v20 = &outAttrList.m_Memory.m_pMemory[v15];
                  if ( CDmeAttributeReference::GetReferencedAttribute(this: (CDmeAttributeReference *)v19) == *v20 )
                  {
                    v21 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                    v27 = TD_ALL;
                    v26 = false;
                    v25.u.m_Id = g_pDataModel.u.m_Id;
                    memset(&reList1, 0, sizeof(reList1));
                    v21(a1: &v25, a2: "input");
                    FindReferringElements<CDmElement>(
                      list: (CUtlMemory<vgui::TreeNode *,int> *)&reList1,
                      pElement: v19,
                      symAttrName: v25,
                      bMustBeInSameFile: v26,
                      depth: v27);
                    for ( m = 0; m < reList1.m_Size; ++m )
                    {
                      v23 = reList1.m_Memory.m_pMemory[m];
                      if ( v23 != nullptr
                        && v23->IsA(this: v23, a2: CDmeConnectionOperator::m_classType)
                        && v23 != (CDmElement *)4 )
                      {
                        CDmeSequence::GetDependentOperators(
                          this: v33,
                          (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                          pDmeOperator: (CDmeOperator *)((char *)&v23[-1] + 64));
                      }
                    }
                    if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                  }
                }
                v15 = i;
                v18 = j + 1;
                j = v18;
              }
              while ( v18 < reList0.m_Size );
              m_pOwner = pDmElement;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v24 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v24 = nullptr;
          CDmeSequence::GetDependentOperators(
            this: v33,
            (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
            pDmeOperator: v24);
          v14 = outAttrList.m_Memory.m_pMemory;
        }
        ++v15;
      }
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
          v14 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v14;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00512380
// Name: public: void CDmeSequence::PrepareChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PrepareChannels(CDmeSequence *this, CUtlMemory<vgui::TreeNode *,int> *dmeOperatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeAnimationList *pDmeAnimationList; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  dmeOperatorList[1].m_pMemory = nullptr;
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v2;
  if ( v2 != 0 )
  {
    v3 = 0;
    for ( i = 0; v3 < *(_DWORD *)(v2 + 80); i = v3 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        v6 = 0;
        if ( *(int *)(v5 + 152) > 0 )
        {
          do
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v5 + 140) + 4 * v6));
            v8 = v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v9 = (CDmeChannel *)(v8 - 4);
              if ( v9 != nullptr )
              {
                CDmeChannel::SetMode(this: v9, mode: CM_PLAY);
                CDmeSequence::GetDependentOperators(this, operatorList: dmeOperatorList, pDmeOperator: v9);
              }
            }
            ++v6;
          }
          while ( v6 < *(_DWORD *)(v5 + 152) );
          v2 = (int)pDmeAnimationList;
        }
      }
      v3 = i + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00512520
// Name: public: virtual bool CDmeAnimationEvent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationEvent::IsA(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512550
// Name: public: virtual int CDmeAnimationEvent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::GetInheritanceDepth(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512600
// Name: protected: virtual void CDmeAnimationEvent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationEvent::PerformConstruction(CDmeAnimationEvent *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
  this->m_sDataString.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "dataString",
                                       type: AT_STRING,
                                       pMemory: &this->m_sDataString);
}

//------------------------------------------------------------------------------
// Address: 0x00512730
// Name: public: virtual bool CDmeSequenceBlendBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendBase::IsA(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512760
// Name: public: virtual int CDmeSequenceBlendBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendBase::GetInheritanceDepth(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512800
// Name: protected: virtual void CDmeSequenceBlendBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendBase::PerformConstruction(CDmeSequenceBlendBase *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x005128C0
// Name: public: virtual bool CDmeSequenceBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlend::IsA(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005128F0
// Name: public: virtual int CDmeSequenceBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::GetInheritanceDepth(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512940
// Name: protected: virtual int CDmeSequenceBlend::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::AllocatedSize(CDmeParticleOperator *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x005129D0
// Name: protected: virtual void CDmeSequenceBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlend::PerformConstruction(CDmeSequenceBlend *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_flParamStart.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "paramStart",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flParamStart);
  this->m_flParamEnd.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "paramEnd",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flParamEnd);
}

//------------------------------------------------------------------------------
// Address: 0x00512AB0
// Name: public: virtual bool CDmeSequenceCalcBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceCalcBlend::IsA(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512AE0
// Name: public: virtual int CDmeSequenceCalcBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceCalcBlend::GetInheritanceDepth(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512BA0
// Name: protected: virtual void CDmeSequenceCalcBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceCalcBlend::PerformConstruction(CDmeSequenceCalcBlend *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00512C80
// Name: public: virtual bool CDmeSequenceLayerBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceLayerBase::IsA(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512CB0
// Name: public: virtual int CDmeSequenceLayerBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceLayerBase::GetInheritanceDepth(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512D50
// Name: protected: virtual void CDmeSequenceLayerBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceLayerBase::PerformConstruction(CDmeSequenceAddLayer *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00512E20
// Name: public: virtual bool CDmeSequenceAddLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceAddLayer::IsA(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512E50
// Name: public: virtual int CDmeSequenceAddLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::GetInheritanceDepth(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00512F60
// Name: protected: CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *__thiscall CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(
        CDmeSequenceBlendLayer *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_eAnimation.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimation.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimation.m_pAttribute = nullptr;
  this->__vftable = (CDmeSequenceBlendLayer_vtbl *)&CDmeSequenceBlendLayer::`vftable';
  this->m_flStartFrame = 0;
  this->m_flPeakFrame = 0;
  this->m_flTailFrame = 0;
  this->m_flEndFrame = 0;
  this->m_bSpline.m_pAttribute = nullptr;
  this->m_bSpline.m_Storage = false;
  this->m_bCrossfade.m_pAttribute = nullptr;
  this->m_bCrossfade.m_Storage = false;
  this->m_bNoBlend.m_pAttribute = nullptr;
  this->m_bNoBlend.m_Storage = false;
  this->m_bLocal.m_pAttribute = nullptr;
  this->m_bLocal.m_Storage = false;
  this->m_sPoseParameterName.m_pAttribute = nullptr;
  this->m_sPoseParameterName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00513020
// Name: public: virtual bool CDmeSequenceBlendLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendLayer::IsA(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513050
// Name: public: virtual int CDmeSequenceBlendLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendLayer::GetInheritanceDepth(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005130E0
// Name: protected: virtual void CDmeSequenceBlendLayer::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::PerformConstruction(CDmeSequenceBlendLayer *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  CDmeSequenceBlendLayer::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00513240
// Name: protected: CDmeSequenceBase::CDmeSequenceBase(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBase *__thiscall CDmeSequenceBase::CDmeSequenceBase(
        CDmeSequenceBase *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequenceBase_vtbl *)&CDmeSequenceBase::`vftable';
  this->m_eActivity.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eActivity.m_pAttribute = nullptr;
  this->m_eActivity.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_bHidden.m_pAttribute = nullptr;
  this->m_bHidden.m_Storage = false;
  this->m_bDelta.m_pAttribute = nullptr;
  this->m_bDelta.m_Storage = false;
  this->m_bWorldSpace.m_pAttribute = nullptr;
  this->m_bWorldSpace.m_Storage = false;
  this->m_bPreDelta.m_pAttribute = nullptr;
  this->m_bPreDelta.m_Storage = false;
  this->m_bAutoPlay.m_pAttribute = nullptr;
  this->m_bAutoPlay.m_Storage = false;
  this->m_bRealtime.m_pAttribute = nullptr;
  this->m_bRealtime.m_Storage = false;
  this->m_flFadeIn = 0;
  this->m_flFadeOut = 0;
  this->m_sEntryNode.m_pAttribute = nullptr;
  this->m_sEntryNode.m_Storage.u.m_Id = -1;
  this->m_sExitNode.m_pAttribute = nullptr;
  this->m_sExitNode.m_Storage.u.m_Id = -1;
  this->m_bReverseNodeTransition.m_pAttribute = nullptr;
  this->m_bReverseNodeTransition.m_Storage = false;
  this->m_bSnap.m_pAttribute = nullptr;
  this->m_bSnap.m_Storage = false;
  this->m_bPost.m_pAttribute = nullptr;
  this->m_bPost.m_Storage = false;
  this->m_bLoop.m_pAttribute = nullptr;
  this->m_bLoop.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkLockList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationEventList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eLayerList);
  this->m_sKeyValues.m_Storage.u.m_Id = -1;
  this->m_sKeyValues.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00513340
// Name: public: virtual bool CDmeSequenceBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBase::IsA(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513370
// Name: public: virtual int CDmeSequenceBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::GetInheritanceDepth(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005133B0
// Name: protected: virtual int CDmeSequenceBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::AllocatedSize(CDmeSequenceBase *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x005133C0
// Name: protected: virtual void CDmeSequenceBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::PerformConstruction(CDmeSequenceBase *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSequenceBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00513420
// Name: protected: CDmeSequence::CDmeSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequence *__thiscall CDmeSequence::CDmeSequence(
        CDmeSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequence_vtbl *)&CDmeSequence::`vftable';
  this->m_eSkeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eSkeleton.m_pAttribute = nullptr;
  this->m_eSkeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimationList.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimationList.m_pAttribute = nullptr;
  this->m_eAnimationList.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flFPS = 0;
  this->m_vOrigin.m_pAttribute = nullptr;
  this->m_vOrigin.m_Storage.x = 0.0;
  this->m_vOrigin.m_Storage.y = 0.0;
  this->m_vOrigin.m_Storage.z = 0.0;
  this->m_flScale = 0;
  this->m_nStartLoop.m_pAttribute = nullptr;
  this->m_nStartLoop.m_Storage = 0;
  this->m_bForceLoop.m_pAttribute = nullptr;
  this->m_bForceLoop.m_Storage = false;
  this->m_bAutoIk.m_pAttribute = nullptr;
  this->m_bAutoIk.m_Storage = false;
  this->m_flMotionRollback = 0;
  this->m_bAnimBlocks.m_pAttribute = nullptr;
  this->m_bAnimBlocks.m_Storage = false;
  this->m_bAnimBlockStall.m_pAttribute = nullptr;
  this->m_bAnimBlockStall.m_Storage = false;
  this->m_eMotionControl.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMotionControl.m_pAttribute = nullptr;
  this->m_eMotionControl.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationCommandList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkRuleList);
  this->m_eBoneMask.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBoneMask.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBoneMask.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00513540
// Name: public: virtual bool CDmeSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequence::IsA(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513570
// Name: public: virtual int CDmeSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::GetInheritanceDepth(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005135C0
// Name: protected: virtual int CDmeSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::AllocatedSize(CDmeSequence *this)
{
  return 468;
}

//------------------------------------------------------------------------------
// Address: 0x005135D0
// Name: protected: virtual void CDmeSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PerformConstruction(CDmeSequence *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSequenceBase::OnConstruction(this);
  CDmeSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00513660
// Name: protected: CDmeMultiSequence::CDmeMultiSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMultiSequence *__thiscall CDmeMultiSequence::CDmeMultiSequence(
        CDmeMultiSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMultiSequence_vtbl *)&CDmeMultiSequence::`vftable';
  this->m_nBlendWidth.m_pAttribute = nullptr;
  this->m_nBlendWidth.m_Storage = 0;
  this->m_eBlendRef.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendRef.m_pAttribute = nullptr;
  this->m_eBlendRef.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendComp.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendComp.m_pAttribute = nullptr;
  this->m_eBlendComp.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendCenter.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendCenter.m_pAttribute = nullptr;
  this->m_eBlendCenter.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eSequenceList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eBlendList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005136F0
// Name: public: virtual bool CDmeMultiSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMultiSequence::IsA(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513720
// Name: public: virtual int CDmeMultiSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::GetInheritanceDepth(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513770
// Name: protected: virtual int CDmeMultiSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::AllocatedSize(CDmeMultiSequence *this)
{
  return 384;
}

//------------------------------------------------------------------------------
// Address: 0x00513780
// Name: protected: virtual void CDmeMultiSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::PerformConstruction(CDmeMultiSequence *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSequenceBase::OnConstruction(this);
  CDmeMultiSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005138D0
// Name: public: virtual bool CDmeSequenceActivity::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceActivity::IsA(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513900
// Name: public: virtual int CDmeSequenceActivity::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceActivity::GetInheritanceDepth(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513940
// Name: protected: virtual void CDmeSequenceActivity::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceActivity::PerformConstruction(CDmeSequenceActivity *this)
{
  CDmAttribute *v2; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = 1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_INT, pMemory: &this->m_nWeight);
  this->m_nWeight.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_sModifierList,
    pOwner: this,
    pAttributeName: "modifierList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005E0D20
// Name: protected: virtual int CDmeSequenceAddLayer::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x006ADA00
// Name: _dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationEvent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationEvent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADA60
// Name: _dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceActivity::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceActivity pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADAC0
// Name: _dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendBase::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADB20
// Name: _dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlend::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADB80
// Name: _dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceCalcBlend::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceCalcBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADBE0
// Name: _dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceLayerBase::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceLayerBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADC40
// Name: _dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceAddLayer::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceAddLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADCA0
// Name: _dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendLayer::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADD00
// Name: _dynamic_initializer_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBase::s_Allocator,
    blockSize: 284,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADD60
// Name: _dynamic_initializer_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequence::s_Allocator,
    blockSize: 468,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADDC0
// Name: _dynamic_initializer_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMultiSequence::s_Allocator,
    blockSize: 384,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMultiSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4230
// Name: _dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationEvent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4240
// Name: _dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceActivity::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4250
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4260
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4270
// Name: _dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceCalcBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4280
// Name: _dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceLayerBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4290
// Name: _dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceAddLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B42A0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B42B0
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B42C0
// Name: _dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B42D0
// Name: _dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMultiSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADA30
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationEvent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADA40
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationEvent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationEvent_Helper,
           classname: "DmeAnimationEvent",
           pFactory: &g_CDmeAnimationEvent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADA90
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceActivity_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADAA0
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceActivity_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceActivity_Helper,
           classname: "DmeSequenceActivity",
           pFactory: &g_CDmeSequenceActivity_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADAF0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADB00
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendBase_Helper,
           classname: "DmeSequenceBlendBase",
           pFactory: &g_CDmeSequenceBlendBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADB50
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADB60
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlend_Helper,
           classname: "DmeSequenceBlend",
           pFactory: &g_CDmeSequenceBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADBB0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADBC0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceCalcBlend_Helper,
           classname: "DmeSequenceCalcBlend",
           pFactory: &g_CDmeSequenceCalcBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADC10
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADC20
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceLayerBase_Helper,
           classname: "DmeSequenceLayerBase",
           pFactory: &g_CDmeSequenceLayerBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADC70
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADC80
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceAddLayer_Helper,
           classname: "DmeSequenceAddLayer",
           pFactory: &g_CDmeSequenceAddLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADCD0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADCE0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendLayer_Helper,
           classname: "DmeSequenceBlendLayer",
           pFactory: &g_CDmeSequenceBlendLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADD30
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADD40
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBase_Helper,
           classname: "DmeSequenceBase",
           pFactory: &g_CDmeSequenceBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADD90
// Name: _dynamic_initializer_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADDA0
// Name: _dynamic_initializer_for__g_CDmeSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequence_Helper,
           classname: "DmeSequence",
           pFactory: &g_CDmeSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006ADDF0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMultiSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADE00
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMultiSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMultiSequence_Helper,
           classname: "DmeMultiSequence",
           pFactory: &g_CDmeMultiSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B42E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceActivity_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B42F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceBlendBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4300
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4310
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceCalcBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4320
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceLayerBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4330
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceAddLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4340
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceBlendLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4350
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequenceBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4360
// Name: _dynamic_atexit_destructor_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4370
// Name: _dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMultiSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B4380
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAnimationEvent_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E0D50
// Name: protected: void CDmeSequenceBlendLayer::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::OnConstruction(CDmeSequenceBlendLayer *this)
{
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
  this->m_bSpline.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "spline",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSpline);
  this->m_bCrossfade.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "crossfade",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bCrossfade);
  this->m_bNoBlend.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "noBlend",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bNoBlend);
  this->m_bLocal.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "local",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bLocal);
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004E0EC0
// Name: protected: void CDmeSequenceBase::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::OnConstruction(CDmeSequenceBase *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *v10; // eax
  int v11; // esi
  CUtlSymbolLarge v12; // [esp+Ch] [ebp-8h] BYREF
  bool value; // [esp+13h] [ebp-1h] BYREF

  CDmaElement<CDmeSequenceActivity>::InitAndCreate(
    this: &this->m_eActivity,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"activity",
    pElementName: nullptr,
    flags: 0);
  value = false;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "hidden", type: AT_BOOL, pMemory: &this->m_bHidden);
  this->m_bHidden.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
  value = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "delta", type: AT_BOOL, pMemory: &this->m_bDelta);
  this->m_bDelta.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  value = false;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "worldSpace",
         type: AT_BOOL,
         pMemory: &this->m_bWorldSpace);
  this->m_bWorldSpace.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, &value);
  value = false;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "preDelta", type: AT_BOOL, pMemory: &this->m_bPreDelta);
  this->m_bPreDelta.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  value = false;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "autoPlay", type: AT_BOOL, pMemory: &this->m_bAutoPlay);
  this->m_bAutoPlay.m_pAttribute = v6;
  CDmAttribute::SetValue<bool>(this: v6, &value);
  value = false;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "realtime", type: AT_BOOL, pMemory: &this->m_bRealtime);
  this->m_bRealtime.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
  v12.u.m_Id = 1045220557;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadein", type: AT_FLOAT, pMemory: &this->m_flFadeIn);
  this->m_flFadeIn.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&v12.u.m_Id);
  v12.u.m_Id = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "fadeout", type: AT_FLOAT, pMemory: &this->m_flFadeOut);
  this->m_flFadeOut.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&v12.u.m_Id);
  this->m_sEntryNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "entryNode",
                                      type: AT_STRING,
                                      pMemory: &this->m_sEntryNode);
  this->m_sExitNode.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "exitNode",
                                     type: AT_STRING,
                                     pMemory: &this->m_sExitNode);
  this->m_bReverseNodeTransition.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "reverseNodeTransition",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bReverseNodeTransition);
  this->m_bSnap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "snap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bSnap);
  this->m_bPost.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "post",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bPost);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_eIkLockList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikLockList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkLockList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkLockList.m_pAttribute, typeSymbol: CDmeIkLock::m_classType);
  this->m_eIkLockList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eAnimationEventList.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "animationEventList",
                                               type: AT_FIRST_ARRAY_TYPE,
                                               pMemory: &this->m_eAnimationEventList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationEventList.m_pAttribute,
    typeSymbol: CDmeAnimationEvent::m_classType);
  this->m_eLayerList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "layerList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eLayerList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eLayerList.m_pAttribute,
    typeSymbol: CDmeSequenceLayerBase::m_classType);
  this->m_sKeyValues.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "keyValues",
                                      type: AT_STRING,
                                      pMemory: &this->m_sKeyValues);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eActivity.m_Storage.m_Handle) != 0 )
  {
    v10 = *(const char **)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: this->m_eActivity.m_Storage.m_Handle)
                         + 20);
    if ( v10 == (const char *)-1 )
      v10 = pDeltaStateName;
    if ( _V_strcmp(s1: "unnamed", s2: v10) == 0 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_eActivity.m_Storage.m_Handle);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v12,
        a3: pDeltaStateName);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v11 + 24), value: &v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E11D0
// Name: protected: void CDmeSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::OnConstruction(CDmeSequence *this)
{
  CDmaElement<CDmeDag> *p_m_eSkeleton; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  Vector v9; // [esp+8h] [ebp-14h] BYREF
  float value; // [esp+14h] [ebp-8h] BYREF
  bool v11; // [esp+1Bh] [ebp-1h] BYREF

  p_m_eSkeleton = &this->m_eSkeleton;
  this->m_eSkeleton.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "skeleton",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eSkeleton);
  CDmAttribute::SetElementTypeSymbol(this: p_m_eSkeleton->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_eAnimationList.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "animationList",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_eAnimationList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationList.m_pAttribute,
    typeSymbol: CDmeAnimationList::m_classType);
  value = 30.0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "fps", type: AT_FLOAT, pMemory: &this->m_flFPS);
  this->m_flFPS.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  memset(&v9, 0, sizeof(v9));
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "origin", type: AT_VECTOR3, pMemory: &this->m_vOrigin);
  this->m_vOrigin.m_pAttribute = v4;
  CDmAttribute::SetValue<Vector>(this: v4, value: &v9);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_flScale);
  this->m_flScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_nStartLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "startLoop",
                                      type: AT_INT,
                                      pMemory: &this->m_nStartLoop);
  this->m_bForceLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "forceLoop",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bForceLoop);
  this->m_bAutoIk.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "autoIk",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bAutoIk);
  value = 0.30000001;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "motionRollback",
         type: AT_FLOAT,
         pMemory: &this->m_flMotionRollback);
  this->m_flMotionRollback.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
  v11 = true;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlocks",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlocks);
  this->m_bAnimBlocks.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, value: &v11);
  v11 = true;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "animBlockStall",
         type: AT_BOOL,
         pMemory: &this->m_bAnimBlockStall);
  this->m_bAnimBlockStall.m_pAttribute = v8;
  CDmAttribute::SetValue<bool>(this: v8, value: &v11);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
  this->m_eAnimationCommandList.m_pAttribute = CDmElement::AddExternalAttribute(
                                                 this,
                                                 pAttributeName: "animationCommandList",
                                                 type: AT_FIRST_ARRAY_TYPE,
                                                 pMemory: &this->m_eAnimationCommandList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eAnimationCommandList.m_pAttribute,
    typeSymbol: CDmeAnimCmd::m_classType);
  this->m_eIkRuleList.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "ikRuleList",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_eIkRuleList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eIkRuleList.m_pAttribute, typeSymbol: CDmeIkRule::m_classType);
  this->m_eIkRuleList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneMask",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E1440
// Name: protected: void CDmeMultiSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::OnConstruction(CDmeMultiSequence *this)
{
  CDmaVar<int> *p_m_nBlendWidth; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_nBlendWidth = &this->m_nBlendWidth;
  value = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "blendWidth", type: AT_INT, pMemory: &this->m_nBlendWidth);
  p_m_nBlendWidth->m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_eBlendRef.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "blendRef",
                                     type: AT_FIRST_VALUE_TYPE,
                                     pMemory: &this->m_eBlendRef);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendRef.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendRef.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendComp.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendComp",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eBlendComp);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendComp.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendComp.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendCenter.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "blendCenter",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_eBlendCenter);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eBlendCenter.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eBlendCenter.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eSequenceList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "sequenceList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_eSequenceList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eSequenceList.m_pAttribute, typeSymbol: CDmeSequence::m_classType);
  this->m_eSequenceList.m_pAttribute->m_nFlags |= 0x1000u;
  this->m_eBlendList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "blendList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_eBlendList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_eBlendList.m_pAttribute,
    typeSymbol: CDmeSequenceBlendBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E1580
// Name: public: static int CDmeSequenceBase::QSortFunction(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDmeSequenceBase::QSortFunction(int *pVoidSeq1, int pVoidSeq2)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  unsigned __int8 (__thiscall *v5)(int, CUtlSymbolLarge::<unnamed_type_u>); // eax
  const CDmeSequence *v6; // ebx
  const CDmeSequence *v7; // eax
  int v9; // ecx
  const CDmeSequence *v10; // ebx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // esi
  const char *m_pAsString; // eax
  const char *v15; // ecx
  int m_Size; // eax
  int v17; // ecx
  const CDmeSequence *pSeq[2]; // [esp+Ch] [ebp-10h]
  const CDmeSequence *pSeq1; // [esp+14h] [ebp-8h]
  const CDmeSequence *pSeq2; // [esp+18h] [ebp-4h]

  v2 = *pVoidSeq1;
  v3 = *(_DWORD *)pVoidSeq2;
  if ( *pVoidSeq1 == 0 || v3 == 0 )
    return 0;
  v4 = (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeSequence::m_classType.u);
  v5 = *(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16);
  v6 = v4 != 0 ? (const CDmeSequence *)v2 : nullptr;
  pSeq1 = v6;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(
         a1: v3,
         a2: (CUtlSymbolLarge::<unnamed_type_u>)CDmeSequence::m_classType.u.m_Id) != 0
     ? (const CDmeSequence *)v3
     : nullptr;
  pSeq2 = v7;
  if ( v6 == nullptr )
    return v7 != nullptr;
  if ( v7 == nullptr )
    return -1;
  v9 = 0;
  LOWORD(pVoidSeq1) = 0;
  pSeq[0] = v6;
  pSeq[1] = v7;
  pVoidSeq2 = 0;
  do
  {
    v10 = pSeq[v9];
    v11 = 0;
    if ( v10->m_eAnimationCommandList.m_Storage.m_Size > 0 )
    {
      while ( 1 )
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: v10->m_eAnimationCommandList.m_Storage.m_Memory.m_pMemory[v11]);
        v13 = (_DWORD *)v12;
        if ( v12 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
               a1: v12,
               a2: CDmeAnimCmd::m_classType.u) != 0 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdSubtract::m_classType.u) != 0
            && v13[17] == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
            goto LABEL_19;
          }
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v13 + 16))(
                 a1: v13,
                 a2: CDmeAnimCmdAlign::m_classType.u) != 0
            && v13[17] == CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pSeq[(pVoidSeq2 + 1) % 2]) )
          {
            break;
          }
        }
        if ( ++v11 >= v10->m_eAnimationCommandList.m_Storage.m_Size )
          goto LABEL_19;
      }
      *((_BYTE *)&pVoidSeq1 + pVoidSeq2) = 1;
LABEL_19:
      v7 = pSeq2;
    }
    v9 = pVoidSeq2 + 1;
    pVoidSeq2 = v9;
  }
  while ( v9 < 2 );
  if ( (_BYTE)pVoidSeq1 != 0 )
  {
    if ( BYTE1(pVoidSeq1) == 0 )
      return 1;
    m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    v15 = pSeq1->m_Name.m_Storage.u.m_pAsString;
    if ( v15 == (const char *)-1 )
      v15 = pDeltaStateName;
    _Error(a1: "Animation %s & %s reference each other, circular references are not allowed\n", v15, m_pAsString);
    return 0;
  }
  if ( BYTE1(pVoidSeq1) != 0 )
    return -1;
  m_Size = v7->m_eAnimationCommandList.m_Storage.m_Size;
  v17 = pSeq1->m_eAnimationCommandList.m_Storage.m_Size;
  if ( v17 < m_Size )
    return -1;
  return v17 > m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004E17A0
// Name: public: class CDmeChannelsClip __near * CDmeSequence::GetDmeChannelsClip(void)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetDmeChannelsClip(CDmeSequence *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  int v5; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  v2 = v1;
  if ( v1 == 0 )
    return nullptr;
  v3 = 0;
  if ( *(int *)(v1 + 80) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeChannelsClip::m_classType.u) != 0 )
    {
      break;
    }
    if ( ++v3 >= *(_DWORD *)(v2 + 80) )
      return nullptr;
  }
  return (CDmeChannelsClip *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E1820
// Name: public: void CDmeSequence::UpdateChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::UpdateChannels(
        CDmeSequence *this,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *dmeOperatorList,
        DmeTime_t nClipTime)
{
  int v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  CDmeChannel *v10; // ecx
  CDmeAnimationList *pDmeAnimationList; // [esp+10h] [ebp-10h]
  int nChannelsCount; // [esp+14h] [ebp-Ch]
  DmeTime_t channelTime; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v3;
  if ( v3 != 0 )
  {
    v4 = 0;
    for ( i = 0; v4 < *(_DWORD *)(v3 + 80); i = v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v4));
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        CDmeClip::ToChildMediaTime(this: (CDmeClip *)v6, result: &channelTime, t: nClipTime, bClamp: 1);
        v7 = 0;
        nChannelsCount = *(_DWORD *)(v6 + 152);
        if ( nChannelsCount > 0 )
        {
          do
          {
            v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v6 + 140) + 4 * v7));
            v9 = v8;
            if ( v8 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                   a1: v8,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v10 = (CDmeChannel *)(v9 - 4);
            }
            else
            {
              v10 = nullptr;
            }
            CDmeChannel::SetCurrentTime(this: v10, time: channelTime);
            ++v7;
          }
          while ( v7 < nChannelsCount );
          v3 = (int)pDmeAnimationList;
        }
      }
      v4 = i + 1;
    }
    LOBYTE(pDmeAnimationList) = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 236))(a1: g_pDataModel.u);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: 0);
    g_pDmElementFramework->SetOperators(this: g_pDmElementFramework, a2: dmeOperatorList);
    g_pDmElementFramework->Operate(this: g_pDmElementFramework, a2: true);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeAnimationList *))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: pDmeAnimationList);
    g_pDmElementFramework->BeginEdit(this: g_pDmElementFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E1990
// Name: public: class DmeFramerate_t CDmeSequence::GetFrameRate(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
DmeFramerate_t *__thiscall CDmeSequence::GetFrameRate(
        CDmeSequence *this,
        DmeFramerate_t *result,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *DmeChannelsClip; // esi
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *p_bForceFallback; // eax
  int m_Storage; // eax
  DmeFramerate_t v9; // ecx
  unsigned __int16 dmeFrameRate; // [esp+4h] [ebp-4h]

  DmeChannelsClip = CDmeSequence::GetDmeChannelsClip(this);
  if ( DmeChannelsClip != nullptr )
  {
    dmeFrameRate = fallbackFrameRate.m_num;
    if ( (_BYTE)bForceFallback != 0
      || !CDmElement::HasAttribute(this: DmeChannelsClip, pAttributeName: "frameRate", type: AT_UNKNOWN)
      || ((bForceFallback = 0,
           (Attribute = CDmElement::FindAttribute(this: DmeChannelsClip, pAttributeName: "frameRate")) == nullptr)
        ? (p_bForceFallback = (CDmaVar<int> *)&bForceFallback)
        : (p_bForceFallback = CDmAttribute::GetValue<int>(this: Attribute)),
          (m_Storage = p_bForceFallback->m_Storage) < 0) )
    {
      v9.m_den = fallbackFrameRate.m_den;
    }
    else
    {
      v9 = *DmeFramerate_t::DmeFramerate_t(this: (DmeFramerate_t *)&bForceFallback, fps: m_Storage);
      dmeFrameRate = v9.m_num;
    }
    result->m_num = dmeFrameRate;
    result->m_den = v9.m_den;
    return result;
  }
  else
  {
    *result = fallbackFrameRate;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E1A40
// Name: public: int CDmeSequence::GetFrameCount(class DmeFramerate_t,bool)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannelsClip *__thiscall CDmeSequence::GetFrameCount(
        CDmeSequence *this,
        DmeFramerate_t fallbackFrameRate,
        int bForceFallback)
{
  CDmeChannelsClip *result; // eax
  CDmeClip *v5; // esi
  DmeFramerate_t v6; // kr00_4
  int v7; // eax
  DmeTime_t nEndTime; // [esp+Ch] [ebp-8h] BYREF
  DmeTime_t nStartTime; // [esp+10h] [ebp-4h] BYREF

  result = CDmeSequence::GetDmeChannelsClip(this);
  v5 = result;
  if ( result != nullptr )
  {
    CDmeSequence::GetFrameRate(this, result: (DmeFramerate_t *)&bForceFallback, fallbackFrameRate, bForceFallback);
    CDmeClip::GetStartTime(this: v5, result: &nStartTime);
    v6 = (DmeFramerate_t)bForceFallback;
    bForceFallback = FrameForTime(t: nStartTime, framerate: (DmeFramerate_t)bForceFallback);
    CDmeClip::GetEndTime(this: v5, result: &nEndTime);
    v7 = FrameForTime(t: nEndTime, framerate: v6);
    return (CDmeChannelsClip *)(v7 - bForceFallback + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E1AE0
// Name: public: void CDmeSequence::GetDependentOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &,class CDmeOperator __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::GetDependentOperators(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *operatorList,
        CDmeOperator *pDmeOperator)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v3; // edx
  int k; // edi
  CUtlSymbolTable::StringPool_t *v5; // esi
  int *p_m_SpaceUsed; // esi
  CDmeOperator *v7; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v10; // ecx
  int v11; // eax
  CUtlSymbolTable::StringPool_t **v12; // esi
  void (__thiscall *GetOutputAttributes)(struct CDmeOperator *, CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *); // edx
  CDmAttribute **v14; // eax
  int v15; // edi
  CDmElement *m_pOwner; // esi
  void (__stdcall *v17)(CUtlSymbolLarge *, const char *); // edx
  int v18; // eax
  CExpressionCalculator *v19; // esi
  CDmAttribute **v20; // edi
  void (__stdcall *v21)(CUtlSymbolLarge *, const char *); // edx
  int m; // edi
  CDmElement *v23; // esi
  CDmeOperator *v24; // eax
  CUtlSymbolLarge v25; // [esp-Ch] [ebp-64h] BYREF
  BOOL v26; // [esp-8h] [ebp-60h]
  TraversalDepth_t v27; // [esp-4h] [ebp-5Ch]
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList0; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > reList1; // [esp+20h] [ebp-38h] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > outAttrList; // [esp+34h] [ebp-24h] BYREF
  CDmElement *pDmElement; // [esp+48h] [ebp-10h]
  CDmElement *v32; // [esp+4Ch] [ebp-Ch]
  CDmeSequence *v33; // [esp+50h] [ebp-8h]
  int j; // [esp+54h] [ebp-4h]
  int i; // [esp+64h] [ebp+Ch]

  v33 = this;
  if ( pDmeOperator != nullptr )
  {
    v32 = &pDmeOperator->CDmElement;
    if ( pDmeOperator != (CDmeOperator *)-4
      && ((int (__thiscall *)(_DWORD, _DWORD))pDmeOperator->IsA)(
           a1: &pDmeOperator->CDmElement,
           a2: (CUtlSymbolLarge)CDmeOperator::m_classType.u.m_Id) )
    {
      v3 = operatorList;
      for ( k = 0; k < (int)v3[1].m_pMemory; ++k )
      {
        v5 = v3->m_pMemory[k];
        if ( v5 != nullptr )
        {
          p_m_SpaceUsed = &v5->m_SpaceUsed;
          if ( p_m_SpaceUsed != nullptr )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*p_m_SpaceUsed + 16))(
                   a1: p_m_SpaceUsed,
                   a2: CDmeOperator::m_classType.u) != 0 )
            {
              v7 = (CDmeOperator *)(p_m_SpaceUsed - 1);
              if ( v7 != nullptr && v7 == pDmeOperator )
                return;
            }
            v3 = operatorList;
          }
        }
      }
      m_pMemory = v3[1].m_pMemory;
      m_nAllocationCount = v3->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = operatorList;
      }
      ++v3[1].m_pMemory;
      v10 = v3->m_pMemory;
      v11 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
      v3[1].m_nAllocationCount = (int)v3->m_pMemory;
      if ( v11 > 0 )
      {
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
        v3 = operatorList;
      }
      v12 = &v3->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = (CUtlSymbolTable::StringPool_t *)pDmeOperator;
      GetOutputAttributes = pDmeOperator->GetOutputAttributes;
      memset(&outAttrList, 0, sizeof(outAttrList));
      GetOutputAttributes(this: pDmeOperator, a2: &outAttrList);
      v14 = outAttrList.m_Memory.m_pMemory;
      v15 = 0;
      for ( i = 0; v15 < outAttrList.m_Size; i = v15 )
      {
        m_pOwner = v14[v15]->m_pOwner;
        pDmElement = m_pOwner;
        if ( m_pOwner != nullptr )
        {
          if ( m_pOwner != v32 )
          {
            v17 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
            v27 = TD_ALL;
            v26 = false;
            v25.u.m_Id = g_pDataModel.u.m_Id;
            memset(&reList0, 0, sizeof(reList0));
            v17(a1: &v25, a2: "element");
            FindReferringElements<CDmElement>(
              list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList0,
              pElement: (CExpressionCalculator *)m_pOwner,
              symAttrName: v25,
              bMustBeInSameFile: v26,
              depth: v27);
            v18 = 0;
            j = 0;
            if ( reList0.m_Size > 0 )
            {
              do
              {
                v19 = (CExpressionCalculator *)reList0.m_Memory.m_pMemory[v18];
                if ( v19 != nullptr
                  && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v19->m_expr.m_Storage.m_Memory.m_pMemory
                      + 4))(
                       a1: v19,
                       a2: CDmeAttributeReference::m_classType.u) != 0 )
                {
                  v20 = &outAttrList.m_Memory.m_pMemory[v15];
                  if ( CDmeAttributeReference::GetReferencedAttribute(this: (CDmeAttributeReference *)v19) == *v20 )
                  {
                    v21 = *(void (__stdcall **)(CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
                    v27 = TD_ALL;
                    v26 = false;
                    v25.u.m_Id = g_pDataModel.u.m_Id;
                    memset(&reList1, 0, sizeof(reList1));
                    v21(a1: &v25, a2: "input");
                    FindReferringElements<CDmElement>(
                      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&reList1,
                      pElement: v19,
                      symAttrName: v25,
                      bMustBeInSameFile: v26,
                      depth: v27);
                    for ( m = 0; m < reList1.m_Size; ++m )
                    {
                      v23 = reList1.m_Memory.m_pMemory[m];
                      if ( v23 != nullptr
                        && v23->IsA(this: v23, a2: CDmeConnectionOperator::m_classType)
                        && v23 != (CDmElement *)4 )
                      {
                        CDmeSequence::GetDependentOperators(
                          this: v33,
                          (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
                          pDmeOperator: (CDmeOperator *)((char *)&v23[-1] + 64));
                      }
                    }
                    if ( reList1.m_Memory.m_nGrowSize >= 0 && reList1.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList1.m_Memory.m_pMemory);
                  }
                }
                v15 = i;
                v18 = j + 1;
                j = v18;
              }
              while ( v18 < reList0.m_Size );
              m_pOwner = pDmElement;
            }
            if ( reList0.m_Memory.m_nGrowSize >= 0 && reList0.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: reList0.m_Memory.m_pMemory);
          }
          if ( m_pOwner->IsA(this: m_pOwner, a2: CDmeOperator::m_classType) )
            v24 = (CDmeOperator *)((char *)&m_pOwner[-1] + 64);
          else
            v24 = nullptr;
          CDmeSequence::GetDependentOperators(
            this: v33,
            (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)operatorList,
            pDmeOperator: v24);
          v14 = outAttrList.m_Memory.m_pMemory;
        }
        ++v15;
      }
      outAttrList.m_Size = 0;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
          v14 = nullptr;
          outAttrList.m_Memory.m_pMemory = nullptr;
        }
        outAttrList.m_Memory.m_nAllocationCount = 0;
      }
      outAttrList.m_pElements = v14;
      if ( outAttrList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E1DF0
// Name: public: void CDmeSequence::PrepareChannels(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PrepareChannels(
        CDmeSequence *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *dmeOperatorList)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  CDmeChannel *v9; // esi
  CDmeAnimationList *pDmeAnimationList; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  dmeOperatorList[1].m_pMemory = nullptr;
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_eAnimationList.m_Storage.m_Handle);
  pDmeAnimationList = (CDmeAnimationList *)v2;
  if ( v2 != 0 )
  {
    v3 = 0;
    for ( i = 0; v3 < *(_DWORD *)(v2 + 80); i = v3 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(*(_DWORD *)(v2 + 68) + 4 * v3));
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeChannelsClip::m_classType.u) != 0 )
      {
        v6 = 0;
        if ( *(int *)(v5 + 152) > 0 )
        {
          do
          {
            v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                   a1: g_pDataModel.u,
                   a2: *(_DWORD *)(*(_DWORD *)(v5 + 140) + 4 * v6));
            v8 = v7;
            if ( v7 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                   a1: v7,
                   a2: CDmeChannel::m_classType.u) != 0 )
            {
              v9 = (CDmeChannel *)(v8 - 4);
              if ( v9 != nullptr )
              {
                CDmeChannel::SetMode(this: v9, mode: CM_PLAY);
                CDmeSequence::GetDependentOperators(this, operatorList: dmeOperatorList, pDmeOperator: v9);
              }
            }
            ++v6;
          }
          while ( v6 < *(_DWORD *)(v5 + 152) );
          v2 = (int)pDmeAnimationList;
        }
      }
      v3 = i + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E1F90
// Name: public: virtual bool CDmeAnimationEvent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAnimationEvent::IsA(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1FC0
// Name: public: virtual int CDmeAnimationEvent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::GetInheritanceDepth(CDmeAnimationEvent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAnimationEvent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2070
// Name: protected: virtual void CDmeAnimationEvent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAnimationEvent::PerformConstruction(CDmeAnimationEvent *this)
{
  CDmeFXClip::OnDestruction();
  this->m_nFrame.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frame",
                                  type: AT_INT,
                                  pMemory: &this->m_nFrame);
  this->m_sDataString.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "dataString",
                                       type: AT_STRING,
                                       pMemory: &this->m_sDataString);
}

//------------------------------------------------------------------------------
// Address: 0x004E21A0
// Name: public: virtual bool CDmeSequenceBlendBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendBase::IsA(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E21D0
// Name: public: virtual int CDmeSequenceBlendBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendBase::GetInheritanceDepth(CDmeSequenceBlendBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2270
// Name: protected: virtual void CDmeSequenceBlendBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendBase::PerformConstruction(CDmeSequenceBlendBase *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
}

//------------------------------------------------------------------------------
// Address: 0x004E2330
// Name: public: virtual bool CDmeSequenceBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlend::IsA(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2360
// Name: public: virtual int CDmeSequenceBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::GetInheritanceDepth(CDmeSequenceBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2430
// Name: protected: virtual void CDmeSequenceBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlend::PerformConstruction(CDmeSequenceBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_flParamStart.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "paramStart",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_flParamStart);
  this->m_flParamEnd.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "paramEnd",
                                      type: AT_FLOAT,
                                      pMemory: &this->m_flParamEnd);
}

//------------------------------------------------------------------------------
// Address: 0x004E2510
// Name: public: virtual bool CDmeSequenceCalcBlend::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceCalcBlend::IsA(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2540
// Name: public: virtual int CDmeSequenceCalcBlend::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceCalcBlend::GetInheritanceDepth(CDmeSequenceCalcBlend *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceCalcBlend::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2600
// Name: protected: virtual void CDmeSequenceCalcBlend::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceCalcBlend::PerformConstruction(CDmeSequenceCalcBlend *this)
{
  CDmeFXClip::OnDestruction();
  this->m_sPoseParameterName.m_pAttribute = CDmElement::AddExternalAttribute(
                                              this,
                                              pAttributeName: "poseParameterName",
                                              type: AT_STRING,
                                              pMemory: &this->m_sPoseParameterName);
  this->m_sAttachmentName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "attachmentName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sAttachmentName);
  CDmaElement<CDmeMotionControl>::InitAndCreate(
    this: &this->m_eMotionControl,
    pOwner: this,
    pAttributeName: (DmElementHandle_t)"motionControl",
    pElementName: nullptr,
    flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E26E0
// Name: public: virtual bool CDmeSequenceLayerBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceLayerBase::IsA(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2710
// Name: public: virtual int CDmeSequenceLayerBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceLayerBase::GetInheritanceDepth(CDmeSequenceLayerBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2750
// Name: protected: virtual int CDmeSequenceAddLayer::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x004E27C0
// Name: protected: virtual void CDmeSequenceLayerBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceLayerBase::PerformConstruction(CDmeSequenceAddLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E2890
// Name: public: virtual bool CDmeSequenceAddLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceAddLayer::IsA(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E28C0
// Name: public: virtual int CDmeSequenceAddLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceAddLayer::GetInheritanceDepth(CDmeSequenceAddLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceAddLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E29D0
// Name: protected: CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBlendLayer *__thiscall CDmeSequenceBlendLayer::CDmeSequenceBlendLayer(
        CDmeSequenceBlendLayer *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_eAnimation.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimation.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimation.m_pAttribute = nullptr;
  this->__vftable = (CDmeSequenceBlendLayer_vtbl *)&CDmeSequenceBlendLayer::`vftable';
  this->m_flStartFrame = 0;
  this->m_flPeakFrame = 0;
  this->m_flTailFrame = 0;
  this->m_flEndFrame = 0;
  this->m_bSpline.m_pAttribute = nullptr;
  this->m_bSpline.m_Storage = false;
  this->m_bCrossfade.m_pAttribute = nullptr;
  this->m_bCrossfade.m_Storage = false;
  this->m_bNoBlend.m_pAttribute = nullptr;
  this->m_bNoBlend.m_Storage = false;
  this->m_bLocal.m_pAttribute = nullptr;
  this->m_bLocal.m_Storage = false;
  this->m_sPoseParameterName.m_pAttribute = nullptr;
  this->m_sPoseParameterName.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E2A90
// Name: public: virtual bool CDmeSequenceBlendLayer::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBlendLayer::IsA(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2AC0
// Name: public: virtual int CDmeSequenceBlendLayer::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlendLayer::GetInheritanceDepth(CDmeSequenceBlendLayer *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBlendLayer::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceLayerBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2B60
// Name: protected: virtual void CDmeSequenceBlendLayer::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBlendLayer::PerformConstruction(CDmeSequenceBlendLayer *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eAnimation.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "animation",
                                      type: AT_FIRST_VALUE_TYPE,
                                      pMemory: &this->m_eAnimation);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eAnimation.m_pAttribute, typeSymbol: CDmeSequenceBase::m_classType);
  CDmeSequenceBlendLayer::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E2CC0
// Name: protected: CDmeSequenceBase::CDmeSequenceBase(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceBase *__thiscall CDmeSequenceBase::CDmeSequenceBase(
        CDmeSequenceBase *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequenceBase_vtbl *)&CDmeSequenceBase::`vftable';
  this->m_eActivity.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eActivity.m_pAttribute = nullptr;
  this->m_eActivity.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_bHidden.m_pAttribute = nullptr;
  this->m_bHidden.m_Storage = false;
  this->m_bDelta.m_pAttribute = nullptr;
  this->m_bDelta.m_Storage = false;
  this->m_bWorldSpace.m_pAttribute = nullptr;
  this->m_bWorldSpace.m_Storage = false;
  this->m_bPreDelta.m_pAttribute = nullptr;
  this->m_bPreDelta.m_Storage = false;
  this->m_bAutoPlay.m_pAttribute = nullptr;
  this->m_bAutoPlay.m_Storage = false;
  this->m_bRealtime.m_pAttribute = nullptr;
  this->m_bRealtime.m_Storage = false;
  this->m_flFadeIn = 0;
  this->m_flFadeOut = 0;
  this->m_sEntryNode.m_pAttribute = nullptr;
  this->m_sEntryNode.m_Storage.u.m_Id = -1;
  this->m_sExitNode.m_pAttribute = nullptr;
  this->m_sExitNode.m_Storage.u.m_Id = -1;
  this->m_bReverseNodeTransition.m_pAttribute = nullptr;
  this->m_bReverseNodeTransition.m_Storage = false;
  this->m_bSnap.m_pAttribute = nullptr;
  this->m_bSnap.m_Storage = false;
  this->m_bPost.m_pAttribute = nullptr;
  this->m_bPost.m_Storage = false;
  this->m_bLoop.m_pAttribute = nullptr;
  this->m_bLoop.m_Storage = false;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkLockList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationEventList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eLayerList);
  this->m_sKeyValues.m_Storage.u.m_Id = -1;
  this->m_sKeyValues.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E2DC0
// Name: public: virtual bool CDmeSequenceBase::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceBase::IsA(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2DF0
// Name: public: virtual int CDmeSequenceBase::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::GetInheritanceDepth(CDmeSequenceBase *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2E30
// Name: protected: virtual int CDmeSequenceBase::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBase::AllocatedSize(CDmeSequenceBase *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x004E2E40
// Name: protected: virtual void CDmeSequenceBase::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceBase::PerformConstruction(CDmeSequenceBase *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E2EA0
// Name: protected: CDmeSequence::CDmeSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSequence *__thiscall CDmeSequence::CDmeSequence(
        CDmeSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeSequence_vtbl *)&CDmeSequence::`vftable';
  this->m_eSkeleton.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eSkeleton.m_pAttribute = nullptr;
  this->m_eSkeleton.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eAnimationList.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eAnimationList.m_pAttribute = nullptr;
  this->m_eAnimationList.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_flFPS = 0;
  this->m_vOrigin.m_pAttribute = nullptr;
  this->m_vOrigin.m_Storage.x = 0.0;
  this->m_vOrigin.m_Storage.y = 0.0;
  this->m_vOrigin.m_Storage.z = 0.0;
  this->m_flScale = 0;
  this->m_nStartLoop.m_pAttribute = nullptr;
  this->m_nStartLoop.m_Storage = 0;
  this->m_bForceLoop.m_pAttribute = nullptr;
  this->m_bForceLoop.m_Storage = false;
  this->m_bAutoIk.m_pAttribute = nullptr;
  this->m_bAutoIk.m_Storage = false;
  this->m_flMotionRollback = 0;
  this->m_bAnimBlocks.m_pAttribute = nullptr;
  this->m_bAnimBlocks.m_Storage = false;
  this->m_bAnimBlockStall.m_pAttribute = nullptr;
  this->m_bAnimBlockStall.m_Storage = false;
  this->m_eMotionControl.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eMotionControl.m_pAttribute = nullptr;
  this->m_eMotionControl.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eAnimationCommandList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eIkRuleList);
  this->m_eBoneMask.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBoneMask.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBoneMask.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E2FC0
// Name: public: virtual bool CDmeSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequence::IsA(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2FF0
// Name: public: virtual int CDmeSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::GetInheritanceDepth(CDmeSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3040
// Name: protected: virtual int CDmeSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequence::AllocatedSize(CDmeSequence *this)
{
  return 468;
}

//------------------------------------------------------------------------------
// Address: 0x004E3050
// Name: protected: virtual void CDmeSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequence::PerformConstruction(CDmeSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E30E0
// Name: protected: CDmeMultiSequence::CDmeMultiSequence(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMultiSequence *__thiscall CDmeMultiSequence::CDmeMultiSequence(
        CDmeMultiSequence *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeSequenceBase::CDmeSequenceBase(this, handle, pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMultiSequence_vtbl *)&CDmeMultiSequence::`vftable';
  this->m_nBlendWidth.m_pAttribute = nullptr;
  this->m_nBlendWidth.m_Storage = 0;
  this->m_eBlendRef.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendRef.m_pAttribute = nullptr;
  this->m_eBlendRef.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendComp.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendComp.m_pAttribute = nullptr;
  this->m_eBlendComp.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_eBlendCenter.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_eBlendCenter.m_pAttribute = nullptr;
  this->m_eBlendCenter.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eSequenceList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_eBlendList);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E3170
// Name: public: virtual bool CDmeMultiSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMultiSequence::IsA(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E31A0
// Name: public: virtual int CDmeMultiSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::GetInheritanceDepth(CDmeMultiSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMultiSequence::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSequenceBase::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E31F0
// Name: protected: virtual int CDmeMultiSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMultiSequence::AllocatedSize(CDmeMultiSequence *this)
{
  return 384;
}

//------------------------------------------------------------------------------
// Address: 0x004E3200
// Name: protected: virtual void CDmeMultiSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMultiSequence::PerformConstruction(CDmeMultiSequence *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSequenceBase::OnConstruction(this);
  CDmeMultiSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E3350
// Name: public: virtual bool CDmeSequenceActivity::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSequenceActivity::IsA(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3380
// Name: public: virtual int CDmeSequenceActivity::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceActivity::GetInheritanceDepth(CDmeSequenceActivity *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSequenceActivity::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E33C0
// Name: protected: virtual void CDmeSequenceActivity::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSequenceActivity::PerformConstruction(CDmeSequenceActivity *this)
{
  CDmAttribute *v2; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  value = 1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_INT, pMemory: &this->m_nWeight);
  this->m_nWeight.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_sModifierList,
    pOwner: this,
    pAttributeName: "modifierList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E4250
// Name: protected: virtual int CDmeSequenceBlend::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSequenceBlend::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x004EB4C0
// Name: protected: virtual int CDmeAnimationEvent::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAnimationEvent::AllocatedSize(CDmeSound *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x005E70E0
// Name: _dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAnimationEvent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAnimationEvent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7140
// Name: _dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceActivity::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceActivity pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E71A0
// Name: _dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendBase::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7200
// Name: _dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlend::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7260
// Name: _dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceCalcBlend::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceCalcBlend pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E72C0
// Name: _dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceLayerBase::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceLayerBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7320
// Name: _dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceAddLayer::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceAddLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7380
// Name: _dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBlendLayer::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBlendLayer pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E73E0
// Name: _dynamic_initializer_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequenceBase::s_Allocator,
    blockSize: 284,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequenceBase pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7440
// Name: _dynamic_initializer_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSequence::s_Allocator,
    blockSize: 468,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E74A0
// Name: _dynamic_initializer_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMultiSequence::s_Allocator,
    blockSize: 384,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMultiSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC5F0
// Name: _dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAnimationEvent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAnimationEvent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC600
// Name: _dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceActivity::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceActivity::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC610
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC620
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC630
// Name: _dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceCalcBlend::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceCalcBlend::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC640
// Name: _dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceLayerBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceLayerBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC650
// Name: _dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceAddLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceAddLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC660
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBlendLayer::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBlendLayer::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC670
// Name: _dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequenceBase::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequenceBase::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC680
// Name: _dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EC690
// Name: _dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMultiSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMultiSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7110
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAnimationEvent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7120
// Name: _dynamic_initializer_for__g_CDmeAnimationEvent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAnimationEvent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAnimationEvent_Helper,
           classname: "DmeAnimationEvent",
           pFactory: &g_CDmeAnimationEvent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7170
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceActivity_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7180
// Name: _dynamic_initializer_for__g_CDmeSequenceActivity_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceActivity_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceActivity_Helper,
           classname: "DmeSequenceActivity",
           pFactory: &g_CDmeSequenceActivity_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E71D0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E71E0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendBase_Helper,
           classname: "DmeSequenceBlendBase",
           pFactory: &g_CDmeSequenceBlendBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7230
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7240
// Name: _dynamic_initializer_for__g_CDmeSequenceBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlend_Helper,
           classname: "DmeSequenceBlend",
           pFactory: &g_CDmeSequenceBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7290
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceCalcBlend_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E72A0
// Name: _dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceCalcBlend_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceCalcBlend_Helper,
           classname: "DmeSequenceCalcBlend",
           pFactory: &g_CDmeSequenceCalcBlend_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E72F0
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceLayerBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7300
// Name: _dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceLayerBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceLayerBase_Helper,
           classname: "DmeSequenceLayerBase",
           pFactory: &g_CDmeSequenceLayerBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7350
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceAddLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7360
// Name: _dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceAddLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceAddLayer_Helper,
           classname: "DmeSequenceAddLayer",
           pFactory: &g_CDmeSequenceAddLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E73B0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBlendLayer_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E73C0
// Name: _dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBlendLayer_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBlendLayer_Helper,
           classname: "DmeSequenceBlendLayer",
           pFactory: &g_CDmeSequenceBlendLayer_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7410
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequenceBase_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7420
// Name: _dynamic_initializer_for__g_CDmeSequenceBase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequenceBase_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequenceBase_Helper,
           classname: "DmeSequenceBase",
           pFactory: &g_CDmeSequenceBase_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E7470
// Name: _dynamic_initializer_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7480
// Name: _dynamic_initializer_for__g_CDmeSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSequence_Helper,
           classname: "DmeSequence",
           pFactory: &g_CDmeSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E74D0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMultiSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E74E0
// Name: _dynamic_initializer_for__g_CDmeMultiSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMultiSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMultiSequence_Helper,
           classname: "DmeMultiSequence",
           pFactory: &g_CDmeMultiSequence_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceActivity_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceActivity_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlend_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceCalcBlend_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceCalcBlend_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceLayerBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceLayerBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC6F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceAddLayer_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceAddLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC700
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBlendLayer_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBlendLayer_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC710
// Name: _dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequenceBase_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequenceBase_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC720
// Name: _dynamic_atexit_destructor_for__g_CDmeSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSequence_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC730
// Name: _dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMultiSequence_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMultiSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EC740
// Name: _dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAnimationEvent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAnimationEvent_Factory.m_CallBackList);
}

} // namespace studiomdl
