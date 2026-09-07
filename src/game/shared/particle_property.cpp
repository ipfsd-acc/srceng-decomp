// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/particle_property.cpp
// Functions: 33
// ============================================================

#include "game\shared\particle_property.h"

//------------------------------------------------------------------------------
// Address: 0x1012E1F0
// Name: public: virtual struct datamap_t __near * CParticleProperty::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticleProperty::GetDataDescMap(CParticleProperty *this)
{
  return &CParticleProperty::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012E200
// Name: public: virtual struct datamap_t __near * CParticleProperty::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticleProperty::GetPredDescMap(CParticleProperty *this)
{
  return &CParticleProperty::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012E210
// Name: private: int CParticleProperty::GetParticleAttachment(class C_BaseEntity __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleProperty::GetParticleAttachment(
        CParticleProperty *this,
        C_BaseEntity *pEntity,
        const char *pszAttachmentName,
        const char *pszParticleName)
{
  C_BaseAnimating *v4; // eax
  int v5; // edi
  C_BaseEntity *v6; // eax
  const char *ModelName; // eax
  const char *v9; // [esp-10h] [ebp-14h]
  const char *v10; // [esp-Ch] [ebp-10h]

  if ( pEntity == nullptr || pEntity->GetBaseAnimating(this: pEntity) == nullptr )
    return -1;
  v4 = pEntity->GetBaseAnimating(this: pEntity);
  v5 = v4->LookupAttachment(this: &v4->IClientRenderable, a2: pszAttachmentName);
  if ( v5 == -1 )
  {
    v6 = (C_BaseEntity *)((int (__thiscall *)(C_BaseEntity *, const char *, const char *))pEntity->GetBaseAnimating)(
                           a1: pEntity,
                           a2: pszAttachmentName,
                           a3: pszParticleName);
    ModelName = C_BaseEntity::GetModelName(this: v6);
    _Warning(a1: "Model '%s' doesn't have attachment '%s' to attach particle system '%s' to.\n", ModelName, v9, v10);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1012E290
// Name: public: ParticleControlPoint_t::ParticleControlPoint_t(void)
// Source: json
//------------------------------------------------------------------------------
ParticleControlPoint_t *__thiscall ParticleControlPoint_t::ParticleControlPoint_t(ParticleControlPoint_t *this)
{
  ParticleControlPoint_t *result; // eax
  float *v2; // edx
  int i; // ecx

  result = this;
  this->hEntity.m_Index = -1;
  this->iControlPoint = 0;
  this->iAttachType = PATTACH_ABSORIGIN_FOLLOW;
  this->iAttachmentPoint = 0;
  this->vecOriginOffset = vec3_origin;
  v2 = &this->matOffset.m_flMatVal[0][1];
  for ( i = 3; i != 0; --i )
  {
    *(v2 - 1) = NAN;
    *v2 = NAN;
    v2[1] = NAN;
    v2[2] = NAN;
    v2 += 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E310
// Name: public: void CParticleProperty::StopParticlesNamed(char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::StopParticlesNamed(
        CParticleProperty *this,
        CParticleSystemDefinition *pszEffectName,
        bool bForceRemoveInstantly,
        int nSplitScreenPlayerSlot)
{
  CParticleSystemDefinition *ParticleSystem; // ecx
  int v6; // edi
  CNewParticleEffect *m_pObj; // esi
  bool bRemoveInstantly; // [esp+4h] [ebp-4h]
  CParticleSystemDefinition *pDef; // [esp+10h] [ebp+8h]
  int bForceRemoveInstantlya; // [esp+14h] [ebp+Ch]

  ParticleSystem = CParticleSystemMgr::FindParticleSystem(
                     this: g_pParticleSystemMgr,
                     pName: (const char *)pszEffectName);
  pDef = ParticleSystem;
  if ( ParticleSystem != nullptr )
  {
    bRemoveInstantly = bForceRemoveInstantly || this->m_iDormancyChangedAtFrame == *(_DWORD *)(gpGlobals.m_Index + 4);
    if ( this->m_ParticleEffects.m_Size > 0 )
    {
      v6 = 0;
      bForceRemoveInstantlya = this->m_ParticleEffects.m_Size;
      while ( 1 )
      {
        m_pObj = this->m_ParticleEffects.m_Memory.m_pMemory[v6].pParticleEffect.m_pObj;
        if ( m_pObj->m_pDef.m_pObject == ParticleSystem
          && (nSplitScreenPlayerSlot == -1
           || m_pObj->ShouldDrawForSplitScreenUser(this: &m_pObj->IClientRenderable, a2: nSplitScreenPlayerSlot)) )
        {
          CNewParticleEffect::StopEmission(
            this: m_pObj,
            bInfiniteOnly: false,
            bRemoveAllParticles: bRemoveInstantly,
            bWakeOnStop: false,
            bPlayEndCap: false);
        }
        ++v6;
        if ( --bForceRemoveInstantlya == 0 )
          break;
        ParticleSystem = pDef;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E3A0
// Name: public: void CParticleProperty::OwnerSetDormantTo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::OwnerSetDormantTo(CParticleProperty *this, bool bDormant)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_ParticleEffects.m_Size;
  this->m_iDormancyChangedAtFrame = *(_DWORD *)(gpGlobals.m_Index + 4);
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      CNewParticleEffect::SetDormant(
        this: this->m_ParticleEffects.m_Memory.m_pMemory[v4++].pParticleEffect.m_pObj,
        bDormant);
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E3E0
// Name: public: int CParticleProperty::FindEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleProperty::FindEffect(CParticleProperty *this, const char *pEffectName)
{
  int v3; // ebx
  int i; // edi
  const char *Name; // eax

  v3 = 0;
  if ( this->m_ParticleEffects.m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    Name = CParticleCollection::GetName(this: &this->m_ParticleEffects.m_Memory.m_pMemory[i].pParticleEffect.m_pObj->CParticleCollection);
    if ( _V_stricmp(s1: Name, s2: pEffectName) == 0 )
      break;
    if ( ++v3 >= this->m_ParticleEffects.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1012E430
// Name: private: void CParticleProperty::UpdateControlPoint(struct ParticleEffectList_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleProperty::UpdateControlPoint(
        CParticleProperty *this@<ecx>,
        int a2@<ebx>,
        ParticleEffectList_t *pEffect,
        int iPoint,
        bool bInitializing)
{
  CNewParticleEffect *m_pObj; // ecx
  ParticleControlPoint_t *v6; // esi
  ParticleAttachment_t v7; // eax
  ParticleAttachment_t iAttachType; // eax
  C_BaseCombatWeapon *v9; // eax
  int v10; // eax
  C_BaseEntity *v11; // ebx
  C_BaseEntity *v12; // eax
  CNewParticleEffect *v13; // ecx
  CNewParticleEffect *v14; // ecx
  char *Classname; // eax
  const char *Name; // eax
  C_BasePlayer *v17; // ebx
  float *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm2_4
  C_BaseCombatWeapon *v21; // eax
  const matrix3x4_t *v22; // eax
  C_BaseCombatWeapon *v23; // eax
  CNewParticleEffect *v24; // ecx
  C_BaseCombatWeapon *v25; // eax
  float *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm2_4
  C_BaseCombatWeapon *v29; // eax
  C_BaseCombatWeapon *v30; // eax
  int iControlPoint; // [esp-14h] [ebp-ACh]
  int v32; // [esp-10h] [ebp-A8h]
  const char *v33; // [esp-8h] [ebp-A0h]
  Vector v35; // [esp+8h] [ebp-90h] BYREF
  matrix3x4_t mat; // [esp+14h] [ebp-84h] BYREF
  Vector vecForward; // [esp+44h] [ebp-54h] BYREF
  Vector vecUp; // [esp+50h] [ebp-48h] BYREF
  Vector vecRight; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector forward; // [esp+68h] [ebp-30h] BYREF
  Vector right; // [esp+74h] [ebp-24h] BYREF
  Vector up; // [esp+80h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+8Ch] [ebp-Ch] BYREF
  C_CSPlayer *pPlayer; // [esp+A8h] [ebp+10h]

  m_pObj = pEffect->pParticleEffect.m_pObj;
  v6 = &pEffect->pControlPoints.m_Memory.m_pMemory[iPoint];
  if ( !m_pObj->m_pDef.m_pObject->m_bScreenSpaceEffect || iPoint != 0 )
  {
    if ( v6->hEntity.m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6->hEntity.m_Index].m_SerialNumber == HIWORD(v6->hEntity.m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6->hEntity.m_Index].m_pEntity != nullptr )
    {
      if ( bInitializing || (v7 = v6->iAttachType) != PATTACH_ABSORIGIN && v7 != PATTACH_POINT )
      {
        iAttachType = v6->iAttachType;
        if ( iAttachType != PATTACH_CUSTOMORIGIN )
        {
          switch ( iAttachType )
          {
            case PATTACH_CUSTOMORIGIN_FOLLOW:
              v21 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              v22 = v21->RenderableToWorldTransform(this: &v21->IClientRenderable);
              ConcatTransforms(in1: v22, in2: &v6->matOffset, out: &mat);
              MatrixVectors(matrix: &mat, pForward: &up, pRight: &right, pUp: &forward);
              vecOrigin.x = mat.m_flMatVal[0][3];
              vecOrigin.y = mat.m_flMatVal[1][3];
              vecOrigin.z = mat.m_flMatVal[2][3];
              v23 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              CNewParticleEffect::SetControlPointEntity(
                this: pEffect->pParticleEffect.m_pObj,
                nWhichPoint: v6->iControlPoint,
                pEntity: v23);
              CNewParticleEffect::SetControlPoint(
                this: pEffect->pParticleEffect.m_pObj,
                nWhichPoint: v6->iControlPoint,
                v: &vecOrigin);
              v24 = pEffect->pParticleEffect.m_pObj;
              v24->m_vSortOrigin = vecOrigin;
              CNewParticleEffect::SetControlPointOrientation(
                this: v24,
                nWhichPoint: v6->iControlPoint,
                forward: &up,
                &right,
                up: &forward);
              break;
            case PATTACH_POINT:
            case PATTACH_POINT_FOLLOW:
              v9 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              v10 = (int)v9->GetBaseAnimating(this: v9);
              v11 = (C_BaseEntity *)v10;
              if ( v10 != 0 )
              {
                if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v10 + 844))(a1: v10, a2) != 0 )
                {
                  v12 = (C_BaseEntity *)v11->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetEFlags(this: v11);
                  pPlayer = ToBasePlayer(pEntity: v12);
                  if ( v11->GetAttachment(this: &v11->IClientRenderable, a2: v6->iAttachmentPoint, a3: &mat) )
                  {
                    MatrixVectors(matrix: &mat, pForward: &vecForward, pRight: &vecRight, pUp: &vecUp);
                    v13 = pEffect->pParticleEffect.m_pObj;
                    vecOrigin.x = mat.m_flMatVal[0][3];
                    vecOrigin.y = mat.m_flMatVal[1][3];
                    vecOrigin.z = mat.m_flMatVal[2][3];
                    if ( v13->m_pDef.m_pObject->m_bViewModelEffect )
                      FormatViewModelAttachment(pPlayer, vOrigin: &vecOrigin, bInverse: true);
                    goto LABEL_33;
                  }
                }
                else if ( ((unsigned __int8 (__thiscall *)(IClientRenderable *, int))v11->GetAttachment)(
                            a1: &v11->IClientRenderable,
                            a2: v6->iAttachmentPoint) != 0 )
                {
                  MatrixVectors(matrix: &mat, pForward: &vecForward, pRight: &vecRight, pUp: &vecUp);
                  v14 = pEffect->pParticleEffect.m_pObj;
                  vecOrigin.x = mat.m_flMatVal[0][3];
                  vecOrigin.y = mat.m_flMatVal[1][3];
                  vecOrigin.z = mat.m_flMatVal[2][3];
                  if ( v14->m_pDef.m_pObject->m_bViewModelEffect )
                    FormatViewModelAttachment(pPlayer: nullptr, vOrigin: &vecOrigin, bInverse: true);
                  goto LABEL_33;
                }
              }
              if ( LOBYTE(_S6_32.m_RecvType) == 0 )
              {
                LOBYTE(_S6_32.m_RecvType) = 1;
                if ( v11 != nullptr )
                  Classname = C_BaseEntity::GetClassname(this: v11);
                else
                  Classname = "(null)";
                v33 = Classname;
                Name = CParticleSystemDefinition::GetName(this: pEffect->pParticleEffect.m_pObj->m_pDef.m_pObject);
                DevWarning(
                  a1: "Attempted to attach particle effect %s to an unknown attachment on entity %s\n",
                  Name,
                  v33);
              }
              break;
            case PATTACH_EYES_FOLLOW:
              v17 = (C_BasePlayer *)CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              if ( v17->IsPlayer(this: v17) )
              {
                v18 = (float *)v17->EyePosition(this: v17, result: &v35);
                v19 = v6->vecOriginOffset.y + v18[1];
                v20 = v6->vecOriginOffset.z + v18[2];
                vecOrigin.x = *v18 + v6->vecOriginOffset.x;
                vecOrigin.y = v19;
                vecOrigin.z = v20;
                C_BasePlayer::EyeVectors(this: v17, pForward: &vecForward, pRight: &vecRight, pUp: &vecUp);
                goto LABEL_33;
              }
              break;
            default:
              v25 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              v26 = (float *)v25->GetAbsOrigin(this: v25);
              v27 = v6->vecOriginOffset.y + v26[1];
              v28 = v6->vecOriginOffset.z + v26[2];
              vecOrigin.x = v6->vecOriginOffset.x + *v26;
              vecOrigin.y = v27;
              vecOrigin.z = v28;
              v29 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              C_BaseEntity::GetVectors(this: v29, pForward: &vecForward, pRight: &vecRight, pUp: &vecUp);
LABEL_33:
              CNewParticleEffect::SetControlPointOrientation(
                this: pEffect->pParticleEffect.m_pObj,
                nWhichPoint: v6->iControlPoint,
                forward: &vecForward,
                right: &vecRight,
                up: &vecUp);
              v30 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v6->hEntity);
              CNewParticleEffect::SetControlPointEntity(
                this: pEffect->pParticleEffect.m_pObj,
                nWhichPoint: v6->iControlPoint,
                pEntity: v30);
              CNewParticleEffect::SetControlPoint(
                this: pEffect->pParticleEffect.m_pObj,
                nWhichPoint: v6->iControlPoint,
                v: &vecOrigin);
              pEffect->pParticleEffect.m_pObj->m_vSortOrigin = vecOrigin;
              break;
          }
        }
      }
    }
    else
    {
      if ( v6->iAttachType == PATTACH_WORLDORIGIN && bInitializing )
      {
        iControlPoint = v6->iControlPoint;
        forward.x = 0.0;
        forward.y = 0.0;
        forward.z = 1.0;
        right.x = 0.0;
        right.y = 1.0;
        right.z = 0.0;
        up.x = 1.0;
        up.y = 0.0;
        up.z = 0.0;
        CNewParticleEffect::SetControlPointOrientation(
          this: m_pObj,
          nWhichPoint: iControlPoint,
          forward: &up,
          &right,
          up: &forward);
        CNewParticleEffect::SetControlPoint(
          this: pEffect->pParticleEffect.m_pObj,
          nWhichPoint: v6->iControlPoint,
          v: &v6->vecOriginOffset);
        m_pObj = pEffect->pParticleEffect.m_pObj;
        m_pObj->m_vSortOrigin = v6->vecOriginOffset;
      }
      CNewParticleEffect::SetControlPointEntity(this: m_pObj, nWhichPoint: v6->iControlPoint, pEntity: nullptr);
    }
  }
  else
  {
    v32 = v6->iControlPoint;
    up.x = 0.0;
    up.y = 0.0;
    up.z = 1.0;
    right.x = 0.0;
    right.y = 1.0;
    right.z = 0.0;
    forward.x = 1.0;
    forward.y = 0.0;
    forward.z = 0.0;
    CNewParticleEffect::SetControlPointOrientation(this: m_pObj, nWhichPoint: v32, &forward, &right, &up);
    CNewParticleEffect::SetControlPoint(
      this: pEffect->pParticleEffect.m_pObj,
      nWhichPoint: v6->iControlPoint,
      v: &vec3_origin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E970
// Name: public: bool CParticleProperty::IsValidEffect(class CNewParticleEffect const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleProperty::IsValidEffect(CParticleProperty *this, const CNewParticleEffect *pEffect)
{
  int m_Size; // edx
  int v3; // eax
  CSmartPtr<CNewParticleEffect,CRefCountAccessor> *i; // ecx

  if ( pEffect == nullptr )
    return 0;
  m_Size = this->m_ParticleEffects.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = &this->m_ParticleEffects.m_Memory.m_pMemory->pParticleEffect; pEffect != i->m_pObj; i += 6 )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012EA20
// Name: public: void CParticleProperty::ReplaceParticleEffect(class CNewParticleEffect __near *,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::ReplaceParticleEffect(
        CParticleProperty *this,
        CNewParticleEffect *pOldEffect,
        CNewParticleEffect *pNewEffect)
{
  int v4; // esi
  ParticleEffectList_t *m_pMemory; // eax
  bool v6; // zf
  CNewParticleEffect **v7; // esi
  CNewParticleEffect *v8; // eax
  ParticleEffectList_t *v9; // esi
  int i; // edi
  int m_Size; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  if ( this->m_ParticleEffects.m_Size > 0 )
  {
    v4 = 0;
    v12 = 0;
    m_Size = this->m_ParticleEffects.m_Size;
    do
    {
      m_pMemory = this->m_ParticleEffects.m_Memory.m_pMemory;
      v6 = pOldEffect == *(CNewParticleEffect **)((char *)&m_pMemory->pParticleEffect.m_pObj + v4);
      v7 = (CNewParticleEffect **)((char *)&m_pMemory->pParticleEffect.m_pObj + v4);
      if ( v6 )
      {
        v8 = pNewEffect;
        if ( pNewEffect != *v7 )
        {
          if ( pNewEffect != nullptr )
          {
            CNewParticleEffect::AddRef(this: pNewEffect);
            v8 = pNewEffect;
          }
          if ( *v7 != nullptr )
          {
            CNewParticleEffect::Release(this: *v7);
            v8 = pNewEffect;
          }
          *v7 = v8;
        }
        v9 = &this->m_ParticleEffects.m_Memory.m_pMemory[v12];
        for ( i = 0; i < v9->pControlPoints.m_Size; ++i )
          CParticleProperty::UpdateControlPoint(this, a2: (int)this, pEffect: v9, iPoint: i, bInitializing: true);
      }
      v4 = v12 * 24 + 24;
      v6 = m_Size-- == 1;
      ++v12;
    }
    while ( !v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EAB0
// Name: public: void CParticleProperty::OnParticleSystemUpdated(class CNewParticleEffect __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::OnParticleSystemUpdated(
        CParticleProperty *this,
        CNewParticleEffect *pEffect,
        float flTimeDelta)
{
  int m_Size; // edx
  int v5; // eax
  ParticleEffectList_t *m_pMemory; // edi
  CNewParticleEffect **i; // ecx
  ParticleEffectList_t *v8; // edi
  int j; // esi

  m_Size = this->m_ParticleEffects.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ParticleEffects.m_Memory.m_pMemory;
    for ( i = &m_pMemory->pParticleEffect.m_pObj; *i != pEffect; i += 6 )
    {
      if ( ++v5 >= m_Size )
        return;
    }
    if ( v5 != -1 )
    {
      v8 = &m_pMemory[v5];
      for ( j = 0; j < v8->pControlPoints.m_Size; ++j )
        CParticleProperty::UpdateControlPoint(this, a2: (int)this, pEffect: v8, iPoint: j, bInitializing: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EB10
// Name: public: void CParticleProperty::AddControlPoint(int,int,class C_BaseEntity __near *,enum ParticleAttachment_t,int,class Vector,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::AddControlPoint(
        CParticleProperty *this,
        int iEffectIndex,
        int iPoint,
        C_BaseEntity *pEntity,
        ParticleAttachment_t iAttachType,
        int iAttachmentPoint,
        Vector vecOriginOffset,
        matrix3x4_t *matOffset)
{
  ParticleEffectList_t *v9; // edi
  int v10; // eax
  int v11; // esi
  unsigned int m_Index; // ecx
  int i; // esi
  int iIndex; // [esp+14h] [ebp+8h]

  v9 = &this->m_ParticleEffects.m_Memory.m_pMemory[iEffectIndex];
  v10 = CUtlVector<ParticleControlPoint_t,CUtlMemory<ParticleControlPoint_t,int>>::InsertBefore(
          this: &v9->pControlPoints,
          elem: v9->pControlPoints.m_Size);
  v11 = (int)&v9->pControlPoints.m_Memory.m_pMemory[v10];
  iIndex = v10;
  *(_DWORD *)v11 = iPoint;
  if ( pEntity != nullptr )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    v10 = iIndex;
    *(_DWORD *)(v11 + 72) = m_Index;
  }
  else
  {
    *(_DWORD *)(v11 + 72) = -1;
  }
  *(_DWORD *)(v11 + 8) = iAttachmentPoint;
  *(_DWORD *)(v11 + 4) = iAttachType;
  *(Vector *)(v11 + 12) = vecOriginOffset;
  if ( matOffset != nullptr )
  {
    *(matrix3x4_t *)(v11 + 24) = *matOffset;
  }
  else
  {
    *(_DWORD *)(v11 + 24) = 1065353216;
    *(_DWORD *)(v11 + 28) = 0;
    *(_DWORD *)(v11 + 32) = 0;
    *(_DWORD *)(v11 + 36) = 0;
    *(_DWORD *)(v11 + 40) = 0;
    *(_DWORD *)(v11 + 44) = 1065353216;
    *(_DWORD *)(v11 + 48) = 0;
    *(_DWORD *)(v11 + 52) = 0;
    *(_DWORD *)(v11 + 56) = 0;
    *(_DWORD *)(v11 + 60) = 0;
    *(_DWORD *)(v11 + 64) = 1065353216;
    *(_DWORD *)(v11 + 68) = 0;
  }
  if ( v10 == -1 )
  {
    for ( i = 0; i < v9->pControlPoints.m_Size; ++i )
      CParticleProperty::UpdateControlPoint(this, a2: (int)this, pEffect: v9, iPoint: i, bInitializing: true);
  }
  else
  {
    CParticleProperty::UpdateControlPoint(this, a2: (int)this, pEffect: v9, iPoint: v10, bInitializing: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012ECD0
// Name: public: void CParticleProperty::AddControlPoint(class CNewParticleEffect __near *,int,class C_BaseEntity __near *,enum ParticleAttachment_t,char const __near *,class Vector,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::AddControlPoint(
        CParticleProperty *this,
        CNewParticleEffect *pEffect,
        int iPoint,
        C_BaseEntity *pEntity,
        ParticleAttachment_t iAttachType,
        const char *pszAttachmentName,
        Vector vecOriginOffset,
        matrix3x4_t *matOffset)
{
  int ParticleAttachment; // ebx
  const char *v10; // eax
  int v11; // edi
  const char *pszAttachmentNamea; // [esp+24h] [ebp+18h]

  if ( pEffect != nullptr )
  {
    ParticleAttachment = -1;
    if ( pszAttachmentName != nullptr )
    {
      v10 = (const char *)((int (*)(void))pEffect->GetEffectName)();
      ParticleAttachment = CParticleProperty::GetParticleAttachment(
                             this,
                             pEntity,
                             pszAttachmentName,
                             pszParticleName: v10);
    }
    v11 = 0;
    if ( this->m_ParticleEffects.m_Size > 0 )
    {
      pszAttachmentNamea = nullptr;
      do
      {
        if ( *(CNewParticleEffect **)&pszAttachmentNamea[(unsigned int)this->m_ParticleEffects.m_Memory.m_pMemory + 20] == pEffect )
          CParticleProperty::AddControlPoint(
            this,
            iEffectIndex: v11,
            iPoint,
            pEntity,
            iAttachType,
            iAttachmentPoint: ParticleAttachment,
            vecOriginOffset,
            matOffset);
        pszAttachmentNamea += 24;
        ++v11;
      }
      while ( v11 < this->m_ParticleEffects.m_Size );
    }
  }
  else
  {
    DevWarning(a1: "Attempted to add control point to NULL particle effect!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EF20
// Name: private: class CNewParticleEffect __near * CParticleProperty::Create(class CParticleSystemDefinition __near *,enum ParticleAttachment_t,int,class Vector,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__thiscall CParticleProperty::Create(
        CParticleProperty *this,
        CParticleSystemDefinition *pDef,
        ParticleAttachment_t iAttachType,
        int iAttachmentPoint,
        Vector vecOriginOffset,
        matrix3x4_t *matOffset)
{
  int m_nValue; // eax
  bool v8; // al
  const char *v9; // eax
  int Effect; // eax
  CNewParticleEffect *m_pObj; // esi
  int v13; // ebx
  const char *Name; // eax
  C_BaseEntity *m_pOuter; // esi
  CNewParticleEffect *v16; // eax
  CNewParticleEffect *v17; // esi
  CNewParticleEffect *v18; // ecx
  CParticleMgr *v19; // eax
  C_BaseEntity *v20; // eax
  C_BaseEntity_vtbl *v21; // esi
  const char *v22; // eax
  CNewParticleEffect *v23; // [esp-4h] [ebp-18h]
  CNewParticleEffect *v24; // [esp-4h] [ebp-18h]
  const char *v25; // [esp+Ch] [ebp-8h]
  ParticleEffectList_t *newEffect; // [esp+10h] [ebp-4h]

  v8 = false;
  if ( cl_particle_batch_mode.m_pParent != nullptr )
  {
    m_nValue = cl_particle_batch_mode.m_pParent->m_Value.m_nValue;
    if ( m_nValue == 2 || m_nValue == 1 && pDef != nullptr && pDef->m_bShouldBatch )
      v8 = true;
  }
  if ( iAttachType == PATTACH_CUSTOMORIGIN
    && v8
    && (v9 = CParticleSystemDefinition::GetName(this: pDef),
        (Effect = CParticleProperty::FindEffect(this, pEffectName: v9)) >= 0) )
  {
    m_pObj = this->m_ParticleEffects.m_Memory.m_pMemory[Effect].pParticleEffect.m_pObj;
    CParticleCollection::Restart(this: &m_pObj->CParticleCollection, eMode: RESTART_NORMAL);
    return m_pObj;
  }
  else
  {
    v13 = CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::InsertBefore(
            this: &this->m_ParticleEffects,
            elem: this->m_ParticleEffects.m_Size);
    newEffect = &this->m_ParticleEffects.m_Memory.m_pMemory[v13];
    Name = CParticleSystemDefinition::GetName(this: pDef);
    m_pOuter = this->m_pOuter;
    v25 = Name;
    v16 = (CNewParticleEffect *)CParticleOperatorInstance::operator new(nSize: 0x530u);
    if ( v16 != nullptr )
      v17 = CNewParticleEffect::CNewParticleEffect(this: v16, a2: v13, pOwner: m_pOuter, pEffect: pDef);
    else
      v17 = nullptr;
    *((_BYTE *)v17 + 944) |= 0x40u;
    v17->m_pDebugName = v25;
    if ( v17 != newEffect->pParticleEffect.m_pObj )
    {
      CNewParticleEffect::AddRef(this: v17);
      v18 = newEffect->pParticleEffect.m_pObj;
      if ( v18 != nullptr )
        CNewParticleEffect::Release(this: v18);
      newEffect->pParticleEffect.m_pObj = v17;
    }
    if ( newEffect->pParticleEffect.m_pObj->m_pDef.m_pObject != nullptr )
    {
      CParticleProperty::AddControlPoint(
        this,
        iEffectIndex: v13,
        iPoint: 0,
        pEntity: this->m_pOuter,
        iAttachType,
        iAttachmentPoint,
        vecOriginOffset,
        matOffset);
      v20 = this->m_pOuter;
      if ( v20 != nullptr )
      {
        v21 = v20->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        v24 = newEffect->pParticleEffect.m_pObj;
        v22 = CParticleSystemDefinition::GetName(this: pDef);
        v21->OnNewParticleEffect(this: this->m_pOuter, a2: v22, a3: v24);
      }
      return newEffect->pParticleEffect.m_pObj;
    }
    else
    {
      v23 = newEffect->pParticleEffect.m_pObj;
      v19 = ParticleMgr();
      CParticleMgr::RemoveEffect(this: v19, pEffect: v23);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F0A0
// Name: public: class CNewParticleEffect __near * CParticleProperty::CreatePrecached(int,enum ParticleAttachment_t,int,class Vector,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSystemDefinition *__thiscall CParticleProperty::CreatePrecached(
        CParticleProperty *this,
        int nPrecacheIndex,
        ParticleAttachment_t iAttachType,
        int iAttachmentPoint,
        Vector vecOriginOffset,
        matrix3x4_t *matOffset)
{
  CParticleSystemDefinition *result; // eax

  result = CParticleSystemMgr::FindPrecachedParticleSystem(this: g_pParticleSystemMgr, nPrecacheIndex);
  if ( result != nullptr )
    return (CParticleSystemDefinition *)CParticleProperty::Create(
                                          this,
                                          pDef: result,
                                          iAttachType,
                                          iAttachmentPoint,
                                          vecOriginOffset,
                                          matOffset);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012F0F0
// Name: public: class CNewParticleEffect __near * CParticleProperty::Create(char const __near *,enum ParticleAttachment_t,int,class Vector,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
CNewParticleEffect *__thiscall CParticleProperty::Create(
        CParticleProperty *this,
        const char *pszParticleName,
        ParticleAttachment_t iAttachType,
        int iAttachmentPoint,
        Vector vecOriginOffset,
        matrix3x4_t *matOffset)
{
  CParticleSystemDefinition *ParticleSystem; // eax

  ParticleSystem = CParticleSystemMgr::FindParticleSystem(this: g_pParticleSystemMgr, pName: pszParticleName);
  if ( ParticleSystem != nullptr )
    return CParticleProperty::Create(
             this,
             pDef: ParticleSystem,
             iAttachType,
             iAttachmentPoint,
             vecOriginOffset,
             matOffset);
  _Warning(a1: "Attempting to create unknown particle system '%s' \n", pszParticleName);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012F150
// Name: public: void CParticleProperty::StopEmission(class CNewParticleEffect __near *,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::StopEmission(
        CParticleProperty *this,
        CNewParticleEffect *pEffect,
        bool bWakeOnStop,
        bool bDestroyAsleepSystems,
        bool bForceRemoveInstantly,
        bool bPlayEndCap)
{
  int m_Size; // edx
  int v8; // eax
  CSmartPtr<CNewParticleEffect,CRefCountAccessor> *k; // edi
  int v10; // ebx
  int j; // ebx
  ParticleEffectList_t *m_pMemory; // eax
  CNewParticleEffect *m_pObj; // ecx
  bool v14; // al
  CNewParticleEffect *v15; // ecx
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *v16; // esi
  float flNow; // [esp+4h] [ebp-Ch]
  bool bRemoveSystem; // [esp+8h] [ebp-8h]
  bool bRemoveInstantly; // [esp+Ch] [ebp-4h]
  CNewParticleEffect *pTmp; // [esp+18h] [ebp+8h]
  int i; // [esp+24h] [ebp+14h]

  bRemoveInstantly = bForceRemoveInstantly || this->m_iDormancyChangedAtFrame == *(_DWORD *)(gpGlobals.m_Index + 4);
  if ( pEffect == nullptr )
  {
    flNow = CParticleSystemMgr::GetLastSimulationTime(this: g_pParticleSystemMgr);
    v10 = this->m_ParticleEffects.m_Size - 1;
    i = v10;
    if ( v10 < 0 )
      return;
    for ( j = v10; ; --j )
    {
      m_pMemory = this->m_ParticleEffects.m_Memory.m_pMemory;
      m_pObj = m_pMemory[j].pParticleEffect.m_pObj;
      pTmp = m_pObj;
      if ( bRemoveInstantly || bDestroyAsleepSystems && flNow >= m_pObj->m_flNextSleepTime )
        break;
      bRemoveSystem = false;
      if ( !bWakeOnStop )
        goto LABEL_21;
      v14 = true;
LABEL_22:
      CNewParticleEffect::StopEmission(
        this: m_pObj,
        bInfiniteOnly: false,
        bRemoveAllParticles: bRemoveSystem,
        bWakeOnStop: v14,
        bPlayEndCap);
      if ( --i < 0 )
        return;
    }
    v15 = m_pMemory[j].pParticleEffect.m_pObj;
    v16 = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pMemory[j];
    bRemoveSystem = true;
    if ( v15 != nullptr )
      CNewParticleEffect::Release(this: v15);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: v16);
    if ( this->m_ParticleEffects.m_Size - i - 1 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[j],
        src: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[j + 1],
        count: 24 * (this->m_ParticleEffects.m_Size - i - 1));
    --this->m_ParticleEffects.m_Size;
    CNewParticleEffect::SetOwner(this: pTmp, pOwner: nullptr);
    m_pObj = pTmp;
LABEL_21:
    v14 = false;
    goto LABEL_22;
  }
  m_Size = this->m_ParticleEffects.m_Size;
  v8 = 0;
  if ( m_Size > 0 )
  {
    for ( k = &this->m_ParticleEffects.m_Memory.m_pMemory->pParticleEffect; k->m_pObj != pEffect; k += 6 )
    {
      if ( ++v8 >= m_Size )
        return;
    }
    if ( v8 != -1 )
      CNewParticleEffect::StopEmission(
        this: pEffect,
        bInfiniteOnly: false,
        bRemoveAllParticles: bRemoveInstantly,
        bWakeOnStop,
        bPlayEndCap);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F2A0
// Name: public: void CParticleProperty::StopEmissionAndDestroyImmediately(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::StopEmissionAndDestroyImmediately(
        CParticleProperty *this,
        CNewParticleEffect *pEffect)
{
  int m_Size; // esi
  int v4; // eax
  ParticleEffectList_t *m_pMemory; // edx
  CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int> > *p_m_ParticleEffects; // ecx
  CNewParticleEffect **j; // edx
  int v8; // ebx
  int v9; // ebx
  ParticleEffectList_t *v10; // esi
  bool v11; // sf
  ParticleControlPoint_t *v12; // eax
  CNewParticleEffect *pTmp; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  if ( pEffect != nullptr )
  {
    m_Size = this->m_ParticleEffects.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ParticleEffects.m_Memory.m_pMemory;
      p_m_ParticleEffects = &this->m_ParticleEffects;
      for ( j = &m_pMemory->pParticleEffect.m_pObj; *j != pEffect; j += 6 )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      if ( v4 != -1 )
      {
        CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::Remove(
          this: p_m_ParticleEffects,
          elem: v4);
        CNewParticleEffect::SetOwner(this: pEffect, pOwner: nullptr);
        CNewParticleEffect::StopEmission(
          this: pEffect,
          bInfiniteOnly: false,
          bRemoveAllParticles: true,
          bWakeOnStop: false,
          bPlayEndCap: false);
      }
    }
  }
  else
  {
    v8 = this->m_ParticleEffects.m_Size - 1;
    i = v8;
    if ( v8 >= 0 )
    {
      v9 = v8;
      do
      {
        v10 = &this->m_ParticleEffects.m_Memory.m_pMemory[v9];
        pTmp = v10->pParticleEffect.m_pObj;
        if ( pTmp != nullptr )
          CNewParticleEffect::Release(this: pTmp);
        v11 = v10->pControlPoints.m_Memory.m_nGrowSize < 0;
        v10->pControlPoints.m_Size = 0;
        if ( !v11 )
        {
          if ( v10->pControlPoints.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->pControlPoints.m_Memory.m_pMemory);
            v10->pControlPoints.m_Memory.m_pMemory = nullptr;
          }
          v10->pControlPoints.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->pControlPoints.m_Memory.m_nGrowSize < 0;
        v12 = v10->pControlPoints.m_Memory.m_pMemory;
        v10->pControlPoints.m_pElements = v10->pControlPoints.m_Memory.m_pMemory;
        if ( !v11 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v10->pControlPoints.m_Memory.m_pMemory = nullptr;
          }
          v10->pControlPoints.m_Memory.m_nAllocationCount = 0;
        }
        if ( this->m_ParticleEffects.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[v9],
            src: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[v9 + 1],
            count: 24 * (this->m_ParticleEffects.m_Size - i - 1));
        --this->m_ParticleEffects.m_Size;
        CNewParticleEffect::SetOwner(this: pTmp, pOwner: nullptr);
        CNewParticleEffect::StopEmission(
          this: pTmp,
          bInfiniteOnly: false,
          bRemoveAllParticles: true,
          bWakeOnStop: false,
          bPlayEndCap: false);
        --v9;
        --i;
      }
      while ( i >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F400
// Name: public: void CParticleProperty::OnParticleSystemDeleted(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::OnParticleSystemDeleted(CParticleProperty *this, CNewParticleEffect *pEffect)
{
  int m_Size; // ecx
  int v4; // esi
  CSmartPtr<CNewParticleEffect,CRefCountAccessor> *i; // eax
  ParticleEffectList_t *m_pMemory; // eax
  CNewParticleEffect *m_pObj; // ecx
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *v8; // eax
  CNewParticleEffect *pEffecta; // [esp+10h] [ebp+8h]

  m_Size = this->m_ParticleEffects.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = &this->m_ParticleEffects.m_Memory.m_pMemory->pParticleEffect; i->m_pObj != pEffect; i += 6 )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( this->m_pOuter != nullptr )
        this->m_pOuter->OnParticleEffectDeleted(this: this->m_pOuter, a2: pEffect);
      this->m_ParticleEffects.m_Memory.m_pMemory[v4].pParticleEffect.m_pObj = nullptr;
      m_pMemory = this->m_ParticleEffects.m_Memory.m_pMemory;
      m_pObj = m_pMemory[v4].pParticleEffect.m_pObj;
      v8 = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pMemory[v4];
      pEffecta = (CNewParticleEffect *)v8;
      if ( m_pObj != nullptr )
      {
        CNewParticleEffect::Release(this: m_pObj);
        v8 = (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)pEffecta;
      }
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: v8);
      if ( this->m_ParticleEffects.m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[v4],
          src: (unsigned __int8 *)&this->m_ParticleEffects.m_Memory.m_pMemory[v4 + 1],
          count: 24 * (this->m_ParticleEffects.m_Size - v4 - 1));
      --this->m_ParticleEffects.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F510
// Name: public: CParticleProperty::CParticleProperty(void)
// Source: json
//------------------------------------------------------------------------------
CParticleProperty *__thiscall CParticleProperty::CParticleProperty(CParticleProperty *this)
{
  this->__vftable = (CParticleProperty_vtbl *)&CParticleProperty::`vftable';
  this->m_ParticleEffects.m_Memory.m_pMemory = nullptr;
  this->m_ParticleEffects.m_Memory.m_nAllocationCount = 0;
  this->m_ParticleEffects.m_Memory.m_nGrowSize = 0;
  this->m_ParticleEffects.m_Size = 0;
  this->m_ParticleEffects.m_pElements = nullptr;
  this->m_pOuter = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012F530
// Name: public: CParticleProperty::~CParticleProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleProperty::~CParticleProperty(CParticleProperty *this)
{
  this->__vftable = (CParticleProperty_vtbl *)&CParticleProperty::`vftable';
  CParticleProperty::StopEmission(
    this,
    pEffect: nullptr,
    bWakeOnStop: false,
    bDestroyAsleepSystems: true,
    bForceRemoveInstantly: false,
    bPlayEndCap: false);
  CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>::~CUtlVector<ParticleEffectList_t,CUtlMemory<ParticleEffectList_t,int>>(this: &this->m_ParticleEffects);
}

//------------------------------------------------------------------------------
// Address: 0x1041ABF0
// Name: CParticleProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CParticleProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CParticleProperty>();
  CParticleProperty_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AC00
// Name: CParticleProperty_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void CParticleProperty_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  CParticleProperty::m_PredMap.dataNumFields = 1;
  CParticleProperty::m_PredMap.dataDesc = (typedescription_t *)&unk_1064CFCC;
}

//------------------------------------------------------------------------------
// Address: 0x1041AC20
// Name: DT_ParticleProperty::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleProperty::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ParticleProperty::g_RecvTable);
  return atexit(func: DT_ParticleProperty::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AC40
// Name: DT_ParticleProperty::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
void DT_ParticleProperty::_dynamic_initializer_for__g_RecvTableInit__()
{
  if ( ((int)_S6_32.m_pVarName & 1) == 0 )
  {
    _S6_32.m_pVarName = (char *)((int)_S6_32.m_pVarName | 1);
    RecvPropInt(
      result: &stru_1064D008,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_ParticleProperty::g_RecvTable,
    pProps: &_S6_32,
    nProps: 0,
    pNetTableName: "DT_ParticleProperty");
  DT_ParticleProperty::g_RecvTableInit = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10432FC0
// Name: DT_ParticleProperty::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleProperty::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ParticleProperty::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1012EC50
// Name: struct datamap_t __near * DataMapInit<class CParticleProperty>(class CParticleProperty __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CParticleProperty>()
{
  if ( (_S5_106 & 1) == 0 )
  {
    _S5_106 |= 1u;
    nameHolder_13.m_pszBase = "CParticleProperty";
    nameHolder_13.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_13.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_13.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_13.m_Names.m_Size = 0;
    nameHolder_13.m_Names.m_pElements = nullptr;
    nameHolder_13.m_nLenBase = 17;
    atexit(func: DataMapInit_CParticleProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CParticleProperty::m_DataMap.baseMap = nullptr;
  CParticleProperty::m_DataMap.dataNumFields = 1;
  CParticleProperty::m_DataMap.dataDesc = (typedescription_t *)&_S6_32.m_Flags;
  return &CParticleProperty::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041AC90
// Name: _dynamic_initializer_for__cl_particle_batch_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_batch_mode__()
{
  ConVar::ConVar(this: &cl_particle_batch_mode, pName: "cl_particle_batch_mode", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_batch_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ACC0
// Name: _dynamic_initializer_for__g_CParticleSphereProxyFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CParticleSphereProxyFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)(), CMaterialProxyDict *))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "ParticleSphereProxy",
           a3: CParticleSphereProxyFactory,
           a4: MaterialProxyDict);
}

//------------------------------------------------------------------------------
// Address: 0x1041ACF0
// Name: _dynamic_initializer_for__r_DrawParticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_DrawParticles__()
{
  ConVar::ConVar(
    this: &r_DrawParticles,
    pName: "r_drawparticles",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable particle rendering");
  return atexit(func: dynamic_atexit_destructor_for__r_DrawParticles__);
}

//------------------------------------------------------------------------------
// Address: 0x10432FD0
// Name: _dynamic_atexit_destructor_for__cl_particle_batch_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_batch_mode__()
{
  ConVar::~ConVar(this: &cl_particle_batch_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10432FE0
// Name: _DataMapInit_CParticleProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CParticleProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_13);
}

//------------------------------------------------------------------------------
// Address: 0x10432FF0
// Name: _dynamic_atexit_destructor_for__r_DrawParticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_DrawParticles__()
{
  ConVar::~ConVar(this: &r_DrawParticles);
}
