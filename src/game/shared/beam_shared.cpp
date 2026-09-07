// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/beam_shared.cpp
// Functions: 42
// ============================================================

#include "game\shared\beam_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1001CB40
// Name: public: virtual class ClientClass __near * C_Beam::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Beam::GetClientClass(C_Beam *this)
{
  return &__g_C_BeamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB50
// Name: public: virtual struct datamap_t __near * C_Beam::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_Beam::GetPredDescMap(C_Beam *this)
{
  return &C_Beam::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB60
// Name: public: virtual void C_Beam::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::SetModel(C_Beam *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 2 )
    _Msg(a1: "Setting CBeam to non-sprite model %s\n", szModelName);
  C_BaseEntity::SetModel(this, pModelName: szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x1001CBC0
// Name: void VectorMin(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMin(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x > b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y > b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z > b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x1001CC40
// Name: void VectorMax(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMax(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x < b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y < b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z < b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x1001CCC0
// Name: class C_BaseViewModel __near * ToBaseViewModel(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseViewModel *__cdecl ToBaseViewModel(C_BaseEntity *pEntity)
{
  C_BaseAnimating *v2; // esi

  if ( pEntity == nullptr )
    return nullptr;
  v2 = pEntity->GetBaseAnimating(this: pEntity);
  if ( v2 != nullptr && v2->IsViewModel(this: v2) )
    return (C_BaseViewModel *)v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD00
// Name: public: virtual void C_Beam::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::Spawn(C_Beam *this)
{
  C_BaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderTransTexture, bForceUpdate: false);
  C_BaseEntity::AddEffects(this, nEffects: 1104);
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001CD40
// Name: public: int C_Beam::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Beam::GetType(C_Beam *this)
{
  return this->m_nBeamType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD50
// Name: public: int C_Beam::GetBeamFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Beam::GetBeamFlags(C_Beam *this)
{
  return this->m_nBeamFlags.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD60
// Name: public: class Vector const __near & C_Beam::GetAbsStartPos(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_Beam::GetAbsStartPos(C_Beam *this)
{
  int m_Value; // eax
  unsigned int m_Index; // ecx
  C_BaseAnimating *m_pEntity; // eax

  if ( (_S7_0 & 1) == 0 )
    _S7_0 |= 1u;
  m_Value = this->m_nBeamType.m_Value;
  if ( m_Value != 0
    && m_Value != 3
    && ((m_Index = this->m_hAttachEntity.m_Value[0].m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      ? (m_pEntity = nullptr)
      : (m_pEntity = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
        ComputeBeamEntPosition(
          pEnt: m_pEntity,
          nAttachment: this->m_nAttachIndex.m_Value[0],
          bInterpretAttachmentIndexAsHitboxIndex: false,
          pt: &vecStartAbsPosition) != 0) )
  {
    return &vecStartAbsPosition;
  }
  else
  {
    return this->GetAbsOrigin(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CDE0
// Name: public: virtual bool C_Beam::OnPredictedEntityRemove(bool,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Beam::OnPredictedEntityRemove(C_Beam *this, bool isbeingremoved, C_BaseEntity *predicted)
{
  _BYTE *v4; // eax

  CCollisionEvent::ShouldFreezeContacts(this, isbeingremoved, predicted);
  v4 = __RTDynamicCast(
         inptr: predicted,
         VfDelta: 0,
         SrcType: &C_BaseEntity `RTTI Type Descriptor',
         TargetType: &C_Beam `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 == nullptr )
    return 1;
  if ( (v4[224] & 1) == 0 )
    return 1;
  this->m_iEFlags |= 1u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE40
// Name: public: void C_Beam::SetAbsStartPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::SetAbsStartPos(C_Beam *this, const Vector *pos)
{
  unsigned int m_Index; // ecx
  matrix3x4_t worldToBeam; // [esp+4h] [ebp-3Ch] BYREF
  Vector vecLocalPos; // [esp+34h] [ebp-Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    C_BaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &worldToBeam);
    VectorTransform(in1: &pos->x, in2: &worldToBeam, out: &vecLocalPos.x);
    C_BaseEntity::SetNetworkOrigin(this, org: &vecLocalPos);
    C_BaseEntity::SetLocalOrigin(this, origin: &vecLocalPos);
  }
  else
  {
    C_BaseEntity::SetNetworkOrigin(this, org: pos);
    C_BaseEntity::SetLocalOrigin(this, origin: pos);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CEE0
// Name: public: class Vector const __near & C_Beam::GetAbsEndPos(void)const
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *__usercall C_Beam::GetAbsEndPos@<eax>(
        C_Beam *this@<ecx>,
        int a2@<ebp>)
{
  int m_Value; // eax
  int v4; // edx
  unsigned int v5; // ecx
  C_BaseAnimating *m_pEntity; // eax
  unsigned int m_Index; // ecx

  if ( (_S8_0 & 1) == 0 )
    _S8_0 |= 1u;
  m_Value = this->m_nBeamType.m_Value;
  if ( m_Value == 0
    || m_Value == 3
    || ((v4 = this->m_nNumBeamEnts.m_Value, (v5 = *(&this->m_nBeamFlags.m_Value + v4)) == -1)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
      ? (m_pEntity = nullptr)
      : (m_pEntity = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity),
        ComputeBeamEntPosition(
          pEnt: m_pEntity,
          nAttachment: this->m_hAttachEntity.m_Value[v4 + 9].m_Index,
          bInterpretAttachmentIndexAsHitboxIndex: false,
          pt: &vecEndAbsPosition) == 0) )
  {
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      return &this->m_vecEndPos;
    }
    C_BaseEntity::CalcAbsolutePosition(this, a2);
    VectorTransform(in1: &this->m_vecEndPos.m_Value.x, in2: &this->m_rgflCoordinateFrame, out: &vecEndAbsPosition.x);
  }
  return (CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *)&vecEndAbsPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1001CFC0
// Name: public: void C_Beam::RelinkBeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::RelinkBeam(C_Beam *this)
{
  const Vector *AbsStartPos; // eax
  __int64 v3; // xmm0_8
  float z; // eax
  CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *AbsEndPos; // eax
  float v6; // ecx
  double x; // xmm0_8
  float v8; // xmm0_4
  double y; // xmm0_8
  float v10; // xmm0_4
  double v11; // xmm0_8
  float v12; // xmm0_4
  double v13; // xmm0_8
  float v14; // xmm0_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float *v19; // eax
  C_Beam_vtbl *v20; // edx
  float v21; // xmm0_4
  const Vector *(__thiscall *v22)(IClientEntity *); // eax
  float *v23; // eax
  Vector mins; // [esp+4h] [ebp-30h] BYREF
  Vector endPos; // [esp+10h] [ebp-24h] BYREF
  Vector vecBeamMin; // [esp+1Ch] [ebp-18h]
  Vector startPos; // [esp+28h] [ebp-Ch]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  AbsStartPos = C_Beam::GetAbsStartPos(this);
  v3 = *(_QWORD *)&AbsStartPos->x;
  z = AbsStartPos->z;
  *(_QWORD *)&startPos.x = v3;
  startPos.z = z;
  AbsEndPos = C_Beam::GetAbsEndPos(this, a2: (int)&savedregs);
  v6 = AbsEndPos->m_Value.z;
  *(_QWORD *)&endPos.x = *(_QWORD *)&AbsEndPos->m_Value.x;
  x = *(float *)&v3;
  endPos.z = v6;
  if ( startPos.x > (double)endPos.x )
    x = endPos.x;
  v8 = x;
  vecBeamMin.x = v8;
  y = startPos.y;
  if ( startPos.y > (double)endPos.y )
    y = endPos.y;
  v10 = y;
  vecBeamMin.y = v10;
  v11 = startPos.z;
  if ( startPos.z > (double)endPos.z )
    v11 = endPos.z;
  v12 = v11;
  vecBeamMin.z = v12;
  v13 = startPos.x;
  if ( startPos.x < (double)endPos.x )
    v13 = endPos.x;
  v14 = v13;
  startPos.x = v14;
  v15 = startPos.y;
  if ( startPos.y < (double)endPos.y )
    v15 = endPos.y;
  v16 = v15;
  startPos.y = v16;
  v17 = startPos.z;
  if ( startPos.z < (double)endPos.z )
    v17 = endPos.z;
  GetAbsOrigin = this->GetAbsOrigin;
  startPos.z = v17;
  v19 = (float *)GetAbsOrigin(this);
  v20 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  endPos.x = startPos.x - *v19;
  endPos.y = startPos.y - v19[1];
  v21 = startPos.z - v19[2];
  v22 = v20->GetAbsOrigin;
  endPos.z = v21;
  v23 = (float *)v22(this);
  mins.x = vecBeamMin.x - *v23;
  mins.y = vecBeamMin.y - v23[1];
  mins.z = vecBeamMin.z - v23[2];
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, maxs: &endPos);
}

//------------------------------------------------------------------------------
// Address: 0x1001D150
// Name: public: virtual int C_Beam::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Beam::DrawModel(C_Beam *this, int flags, const RenderableInstance_t *instance)
{
  int v4; // esi
  CNetworkVarBase<int,C_Beam::NetworkVar_m_nBeamFlags> *p_m_nBeamFlags; // edi
  unsigned int m_Value; // ecx
  IHandleEntity *m_pEntity; // eax
  int v8; // eax

  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0
    && (LOBYTE(this->m_flProxyRandomValue) & 1) == 0
    && CurrentViewID() != VIEW_SHADOW_DEPTH_TEXTURE )
  {
    if ( !g_bRenderingScreenshot
      && r_drawviewmodel.m_pParent != nullptr
      && r_drawviewmodel.m_pParent->m_Value.m_nValue != 0 )
    {
LABEL_14:
      beams->DrawBeam_2(this: beams, a2: (C_Beam *)((char *)this - 4), a3: instance, a4: nullptr);
    }
    else
    {
      v4 = 0;
      p_m_nBeamFlags = &this->m_nBeamFlags;
      while ( 1 )
      {
        m_Value = p_m_nBeamFlags->m_Value;
        if ( p_m_nBeamFlags->m_Value != -1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Value].m_SerialNumber == HIWORD(m_Value) )
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Value].m_pEntity;
          if ( m_pEntity != nullptr )
          {
            v8 = (int)m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity);
            if ( v8 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 844))(a1: v8) != 0 )
              break;
          }
        }
        ++v4;
        ++p_m_nBeamFlags;
        if ( v4 >= 10 )
          goto LABEL_14;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D220
// Name: private: void C_Beam::ComputeBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::ComputeBounds(C_Beam *this, Vector *mins, Vector *maxs)
{
  C_Beam *v3; // ebx
  const Vector *AbsStartPos; // eax
  __int64 v5; // xmm0_8
  float z; // eax
  CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *AbsEndPos; // eax
  __int64 v8; // xmm0_8
  float v9; // ecx
  int m_Value; // eax
  float x; // xmm0_4
  float v12; // xmm1_4
  Vector *v13; // edi
  Vector *v14; // esi
  float y; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  int v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  unsigned int m_Index; // ecx
  int v24; // eax
  CEntInfo *v25; // edx
  unsigned int v26; // ecx
  C_Beam *m_pEntity; // edx
  float *v28; // eax
  int v29; // eax
  bool v30; // zf
  CEntInfo *v31; // eax
  IHandleEntity *v32; // eax
  float v33; // xmm1_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  bool v39; // cc
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm5_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // eax
  float v52; // ecx
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  float v58; // xmm0_4
  Vector attMaxs; // [esp+Ch] [ebp-40h] BYREF
  Vector attMins; // [esp+18h] [ebp-34h] BYREF
  Vector vecAbsEnd; // [esp+24h] [ebp-28h]
  Vector vecAbsStart; // [esp+30h] [ebp-1Ch]
  Vector attachmentPoint; // [esp+3Ch] [ebp-10h] BYREF
  C_Beam *v64; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF
  int i; // [esp+54h] [ebp+8h]

  v3 = this;
  v64 = this;
  AbsStartPos = C_Beam::GetAbsStartPos(this);
  v5 = *(_QWORD *)&AbsStartPos->x;
  z = AbsStartPos->z;
  *(_QWORD *)&vecAbsStart.x = v5;
  vecAbsStart.z = z;
  AbsEndPos = C_Beam::GetAbsEndPos(this: v3, a2: (int)&savedregs);
  v8 = *(_QWORD *)&AbsEndPos->m_Value.x;
  v9 = AbsEndPos->m_Value.z;
  m_Value = v3->m_nBeamType.m_Value;
  *(_QWORD *)&vecAbsEnd.x = v8;
  vecAbsEnd.z = v9;
  if ( m_Value != 2 && (m_Value <= 3 || m_Value > 5) )
  {
    x = vecAbsEnd.x;
    v12 = vecAbsStart.x;
    v13 = mins;
    v14 = maxs;
    if ( vecAbsEnd.x <= vecAbsStart.x )
    {
      mins->x = vecAbsEnd.x;
      maxs->x = v12;
    }
    else
    {
      mins->x = vecAbsStart.x;
      maxs->x = x;
    }
    y = vecAbsEnd.y;
    v16 = vecAbsStart.y;
    if ( vecAbsEnd.y <= vecAbsStart.y )
    {
      mins->y = vecAbsEnd.y;
      maxs->y = v16;
    }
    else
    {
      mins->y = vecAbsStart.y;
      maxs->y = y;
    }
    v17 = vecAbsEnd.z;
    v18 = vecAbsStart.z;
    if ( vecAbsEnd.z <= vecAbsStart.z )
    {
      mins->z = vecAbsEnd.z;
      maxs->z = v18;
    }
    else
    {
      mins->z = vecAbsStart.z;
      maxs->z = v17;
    }
    goto LABEL_69;
  }
  v13 = mins;
  v14 = maxs;
  v19 = 0.0;
  mins->x = 99999.0;
  mins->y = 99999.0;
  mins->z = 99999.0;
  v20 = 0;
  maxs->x = -99999.0;
  maxs->y = -99999.0;
  maxs->z = -99999.0;
  v21 = 0.0;
  v22 = 0.0;
  memset((void *)&attachmentPoint, 0, sizeof(attachmentPoint));
  i = 0;
  if ( v3->m_nNumBeamEnts.m_Value > 0 )
  {
    while ( 1 )
    {
      m_Index = v3->m_hAttachEntity.m_Value[v20].m_Index;
      if ( m_Index == -1 )
        break;
      v24 = (unsigned __int16)m_Index;
      v25 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v3 = v64;
      v26 = HIWORD(m_Index);
      if ( v25->m_SerialNumber != v26 )
        break;
      m_pEntity = (C_Beam *)v25->m_pEntity;
      if ( m_pEntity == nullptr )
        break;
      if ( m_pEntity != v64 )
      {
        v29 = v24;
        v30 = g_pEntityList->m_EntPtrArray[v29].m_SerialNumber == v26;
        v31 = &g_pEntityList->m_EntPtrArray[v29];
        if ( v30 )
          v32 = v31->m_pEntity;
        else
          v32 = nullptr;
        ((void (__thiscall *)(IHandleEntity *, Vector *, Vector *))v32[1].__vftable[6].dtr_IHandleEntity)(
          a1: &v32[1],
          a2: &attMins,
          a3: &attMaxs);
        v33 = v13->z;
        v34 = attMins.z;
        if ( attMins.z <= v33 )
          v33 = attMins.z;
        v35 = v13->y;
        v36 = attMins.y;
        if ( attMins.y <= v35 )
          v35 = attMins.y;
        v37 = v13->x;
        if ( attMins.x <= v13->x )
          v37 = attMins.x;
        v38 = attMaxs.z;
        v39 = attMaxs.z <= v33;
        v13->x = v37;
        v13->y = v35;
        v13->z = v33;
        if ( v39 )
          v33 = v38;
        v40 = attMaxs.y;
        if ( attMaxs.y <= v35 )
          v35 = attMaxs.y;
        v41 = attMaxs.x;
        if ( attMaxs.x <= v37 )
          v37 = attMaxs.x;
        v13->x = v37;
        v13->y = v35;
        v13->z = v33;
        v42 = maxs->z;
        if ( v42 <= v34 )
          v42 = v34;
        if ( maxs->y > v36 )
          v36 = maxs->y;
        v43 = maxs->x;
        if ( maxs->x <= attMins.x )
          v43 = attMins.x;
        maxs->x = v43;
        maxs->y = v36;
        maxs->z = v42;
        if ( v42 <= v38 )
          v42 = v38;
        if ( v36 <= v40 )
          v36 = v40;
        if ( v43 <= v41 )
          v43 = v41;
        v21 = attachmentPoint.x;
        v22 = attachmentPoint.y;
        maxs->x = v43;
        v19 = attachmentPoint.z;
        maxs->y = v36;
LABEL_67:
        maxs->z = v42;
        goto LABEL_68;
      }
      v28 = (float *)v64->GetAbsOrigin(this: v64);
      v21 = attachmentPoint.x;
      maxs->x = *v28;
      v22 = attachmentPoint.y;
      v19 = attachmentPoint.z;
      maxs->y = v28[1];
      maxs->z = v28[2];
      *v13 = *maxs;
LABEL_68:
      v20 = i + 1;
      i = v20;
      if ( v20 >= v3->m_nNumBeamEnts.m_Value )
        goto LABEL_69;
    }
    if ( i != 0 )
    {
      if ( i != 1 )
      {
LABEL_52:
        if ( v19 <= v13->z )
          v44 = v19;
        else
          v44 = v13->z;
        v45 = v13->y;
        if ( v22 <= v45 )
          v45 = v22;
        v46 = v13->x;
        if ( v21 <= v13->x )
          v46 = v21;
        v13->x = v46;
        v13->y = v45;
        v13->z = v44;
        v42 = maxs->z;
        if ( v42 <= v19 )
          v42 = v19;
        if ( maxs->y <= v22 )
          v47 = v22;
        else
          v47 = maxs->y;
        v48 = maxs->x;
        if ( maxs->x <= v21 )
          v48 = v21;
        maxs->x = v48;
        maxs->y = v47;
        goto LABEL_67;
      }
      v21 = vecAbsEnd.x;
      v22 = vecAbsEnd.y;
      v19 = vecAbsEnd.z;
    }
    else
    {
      v21 = vecAbsStart.x;
      v22 = vecAbsStart.y;
      v19 = vecAbsStart.z;
    }
    attachmentPoint.z = v19;
    attachmentPoint.y = v22;
    attachmentPoint.x = v21;
    goto LABEL_52;
  }
LABEL_69:
  v49 = v3->m_fWidth.m_Value;
  if ( v49 <= v3->m_fEndWidth.m_Value )
    v49 = v3->m_fEndWidth.m_Value;
  v50 = v49 * 0.5;
  v13->x = v13->x - v50;
  v13->y = v13->y - v50;
  v13->z = v13->z - v50;
  v14->x = v14->x + v50;
  v14->y = v14->y + v50;
  v14->z = v14->z + v50;
  v51 = (int)v3->GetAbsOrigin(this: v3);
  v52 = *(float *)(v51 + 8);
  v53 = v13->x;
  v54 = v13->y;
  v55 = v13->z;
  *(_QWORD *)&attMins.x = *(_QWORD *)v51;
  v56 = v54 - attMins.y;
  v13->x = v53 - attMins.x;
  v13->y = v56;
  attMins.z = v52;
  v13->z = v55 - v52;
  v57 = v14->x - attMins.x;
  v14->y = v14->y - attMins.y;
  v58 = v14->z - attMins.z;
  v14->x = v57;
  v14->z = v58;
}

//------------------------------------------------------------------------------
// Address: 0x1001D690
// Name: public: virtual void C_Beam::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::GetToolRecordingState(C_Beam *this, KeyValues *msg)
{
  KeyValues *NonConformantKeyValues; // esi
  const char *HandlerIDKeyString; // eax
  int value; // eax
  const Vector *AbsStartPos; // eax
  CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *AbsEndPos; // eax
  int ModelIndex; // eax
  unsigned __int8 RenderAlpha; // al
  float vTemp_4; // [esp+10h] [ebp-8h]
  float vTemp_4a; // [esp+10h] [ebp-8h]
  float vTemp_8; // [esp+14h] [ebp-4h]
  float vTemp_8a; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  C_BaseEntity::GetToolRecordingState(this, msg);
  NonConformantKeyValues = CIFM_EntityKeyValuesHandler_AutoRegister::FindOrCreateNonConformantKeyValues(pParentKV: msg);
  HandlerIDKeyString = CIFM_EntityKeyValuesHandler_AutoRegister::GetHandlerIDKeyString();
  KeyValues::SetString(this: NonConformantKeyValues, keyName: HandlerIDKeyString, value: "C_Beam");
  value = this->index;
  if ( value == -1 )
    value = HIWORD(this->GetRefEHandle(this)->m_Index);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "entIndex", value);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "beamType", value: 0);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "beamEnts", value: this->m_nNumBeamEnts.m_Value);
  AbsStartPos = C_Beam::GetAbsStartPos(this);
  vTemp_4 = AbsStartPos->y;
  vTemp_8 = AbsStartPos->z;
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "start_x", value: AbsStartPos->x);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "start_y", value: vTemp_4);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "start_z", value: vTemp_8);
  AbsEndPos = C_Beam::GetAbsEndPos(this, a2: (int)&savedregs);
  vTemp_4a = AbsEndPos->m_Value.y;
  vTemp_8a = AbsEndPos->m_Value.z;
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "end_x", value: AbsEndPos->m_Value.x);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "end_y", value: vTemp_4a);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "end_z", value: vTemp_8a);
  ModelIndex = C_BaseEntity::GetModelIndex(this);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "ModelIndex", value: ModelIndex);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "HaloIndex", value: this->m_nHaloIndex.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "HaloScale", value: this->m_fHaloScale.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "Width", value: this->m_fWidth.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "EndWidth", value: this->m_fEndWidth.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "FadeLength", value: this->m_fFadeLength.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "Noise", value: this->m_fAmplitude.m_Value);
  RenderAlpha = C_BaseEntity::GetRenderAlpha(this);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "Brightness", value: RenderAlpha);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "ScrollRate", value: this->m_fSpeed.m_Value);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "beamFlags", value: this->m_nBeamFlags.m_Value);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "color_r", value: this->m_clrRender.m_Value.r);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "color_g", value: this->m_clrRender.m_Value.g);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "color_b", value: this->m_clrRender.m_Value.b);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "color_hdrscale", value: this->m_flHDRColorScale.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "startframe", value: this->m_fStartFrame.m_Value);
  KeyValues::SetFloat(this: NonConformantKeyValues, keyName: "framerate", value: this->m_flFrameRate.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x1001D940
// Name: public: void C_Beam::SetEndEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::SetEndEntity(C_Beam *this, C_BaseEntity *pEntity)
{
  unsigned int m_Index; // ecx
  int m_Value; // eax

  if ( pEntity != nullptr )
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    m_Index = -1;
  m_Value = this->m_nNumBeamEnts.m_Value;
  if ( *(&this->m_nBeamFlags.m_Value + m_Value) != m_Index )
    *(&this->m_nBeamFlags.m_Value + m_Value) = m_Index;
  if ( pEntity != nullptr )
    this->m_hEndEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    this->m_hEndEntity.m_Index = -1;
  C_Beam::RelinkBeam(this);
  if ( pEntity != nullptr )
    pEntity->m_iEFlags |= 0x80u;
}

//------------------------------------------------------------------------------
// Address: 0x1001D9B0
// Name: public: virtual void C_Beam::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::OnDataChanged(C_Beam *this, DataUpdateType_t updateType)
{
  IVModelInfoClient_vtbl *v3; // esi
  int ModelIndex; // eax
  const struct model_t *v5; // eax
  CNetworkVarBase<int,C_Beam::NetworkVar_m_nBeamType> *p_m_nBeamType; // edi
  unsigned int m_Value; // ecx
  IHandleEntity *m_pEntity; // eax
  int v9; // eax
  C_BaseCombatWeapon *v10; // esi
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v12; // esi
  C_BaseViewModel *ViewModel; // eax
  int m_Index; // eax
  Vector mins; // [esp+Ch] [ebp-24h] BYREF
  Vector maxs; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]

  C_BaseEntity::MarkMessageReceived(this: (C_Beam *)((char *)this - 8));
  v3 = modelinfo->__vftable;
  ModelIndex = C_BaseEntity::GetModelIndex(this: (C_Beam *)((char *)this - 8));
  v5 = v3->GetModel(this: modelinfo, a2: ModelIndex);
  C_BaseEntity::SetModelPointer(this: (C_Beam *)((char *)this - 8), pModel: v5);
  p_m_nBeamType = &this->m_nBeamType;
  v17 = -2460 - (_DWORD)this;
  for ( i = 10; i != 0; --i )
  {
    m_Value = p_m_nBeamType->m_Value;
    if ( p_m_nBeamType->m_Value != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Value].m_SerialNumber == HIWORD(m_Value) )
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Value].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[51].SetRefEHandle)(a1: m_pEntity);
        v10 = (C_BaseCombatWeapon *)v9;
        if ( v9 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 1400))(a1: v9) != 0 )
        {
          Owner = C_BaseCombatWeapon::GetOwner(this: v10);
          v12 = (C_BasePlayer *)Owner;
          if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
          {
            ViewModel = C_BasePlayer::GetViewModel(this: v12, index: 0);
            if ( ViewModel != nullptr )
            {
              m_Index = ViewModel->GetRefEHandle(this: ViewModel)->m_Index;
              if ( *(int *)((char *)&this->m_nBeamType.m_Value + (_DWORD)p_m_nBeamType + v17) != m_Index )
                *(int *)((char *)&this->m_nBeamType.m_Value + (_DWORD)p_m_nBeamType + v17) = m_Index;
            }
          }
        }
      }
    }
    ++p_m_nBeamType;
  }
  C_Beam::ComputeBounds(this: (C_Beam *)((char *)this - 8), &mins, &maxs);
  CCollisionProperty::SetCollisionBounds(this: (CCollisionProperty *)&this->m_hOldMoveParent, &mins, &maxs);
  C_BaseEntity::AddToEntityList(this: (C_Beam *)((char *)this - 8), listId: ENTITY_LIST_SIMULATE);
}

//------------------------------------------------------------------------------
// Address: 0x1001DAE0
// Name: public: virtual bool C_Beam::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Beam::Simulate(C_Beam *this)
{
  char v2; // bl
  unsigned int m_Index; // ecx
  unsigned int v4; // ecx
  Vector mins; // [esp+8h] [ebp-18h] BYREF
  Vector maxs; // [esp+14h] [ebp-Ch] BYREF

  v2 = 0;
  if ( this->ShouldDraw(this: &this->IClientRenderable) )
  {
    m_Index = this->m_hAttachEntity.m_Value[0].m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      || (v4 = this->m_hAttachEntity.m_Value[1].m_Index) != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity != nullptr )
    {
      C_Beam::ComputeBounds(this, &mins, &maxs);
      CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, &mins, &maxs);
      v2 = 1;
    }
    C_BaseEntity::MoveToLastReceivedPosition(this, force: false);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB80
// Name: void RecvProxy_Beam_ScrollSpeed(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Beam_ScrollSpeed(const CRecvProxyData *pData, float *pStruct)
{
  float v2; // xmm0_4

  v2 = pData->m_Value.m_Float * 0.1;
  if ( pStruct[643] != v2 )
    pStruct[643] = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF20
// Name: public: C_Beam::C_Beam(void)
// Source: json
//------------------------------------------------------------------------------
C_Beam *__thiscall C_Beam::C_Beam(C_Beam *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Beam_vtbl *)&C_Beam::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Beam::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Beam::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Beam::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Beam::`vftable';
  this->m_hAttachEntity.m_Value[0].m_Index = -1;
  this->m_hAttachEntity.m_Value[1].m_Index = -1;
  this->m_hAttachEntity.m_Value[2].m_Index = -1;
  this->m_hAttachEntity.m_Value[3].m_Index = -1;
  this->m_hAttachEntity.m_Value[4].m_Index = -1;
  this->m_hAttachEntity.m_Value[5].m_Index = -1;
  this->m_hAttachEntity.m_Value[6].m_Index = -1;
  this->m_hAttachEntity.m_Value[7].m_Index = -1;
  this->m_hAttachEntity.m_Value[8].m_Index = -1;
  this->m_hAttachEntity.m_Value[9].m_Index = -1;
  this->m_hEndEntity.m_Index = -1;
  if ( this->m_flHDRColorScale.m_Value != 1.0 )
    this->m_flHDRColorScale.m_Value = 1.0;
  this->m_queryHandleHalo = 0;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001DFD0
// Name: public: virtual char const __near * C_Beam::GetDecalName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_Beam::GetDecalName(C_Beam *this)
{
  return "BigShot";
}

//------------------------------------------------------------------------------
// Address: 0x1001DFE0
// Name: public: virtual class Vector const __near & C_Beam::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall C_Beam::WorldSpaceCenter@<eax>(C_Beam *this@<ecx>, int a2@<ebp>)
{
  Vector *v3; // esi
  CNetworkVectorBase<Vector,C_Beam::NetworkVar_m_vecEndPos> *AbsEndPos; // edi
  const Vector *AbsStartPos; // eax
  float x; // xmm1_4

  v3 = AllocTempVector();
  AbsEndPos = C_Beam::GetAbsEndPos(this, a2);
  AbsStartPos = C_Beam::GetAbsStartPos(this);
  v3->x = AbsStartPos->x + AbsEndPos->m_Value.x;
  x = v3->x;
  v3->y = AbsStartPos->y + AbsEndPos->m_Value.y;
  v3->z = AbsStartPos->z + AbsEndPos->m_Value.z;
  v3->x = x * 0.5;
  v3->y = v3->y * 0.5;
  v3->z = v3->z * 0.5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001E060
// Name: public: virtual void C_Beam::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::Precache(C_Beam *this)
{
  unsigned int m_Index; // ecx
  CBaseEntityList *v3; // edx
  int v4; // eax
  CEntInfo *v5; // esi
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  C_BaseEntity **v9; // eax
  C_BaseEntity *v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  CEntInfo *v14; // esi
  unsigned int v15; // ecx
  int v16; // eax
  C_BaseEntity **v17; // eax

  m_Index = this->m_hOwnerEntity.m_Index;
  if ( m_Index == -1 )
  {
LABEL_13:
    v3 = g_pEntityList;
    goto LABEL_14;
  }
  v3 = g_pEntityList;
  v4 = (unsigned __int16)m_Index;
  v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v6 = HIWORD(m_Index);
  if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
  {
    v7 = v4;
    v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
    v9 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
    if ( v8 )
    {
      v10 = *v9;
      if ( *v9 != nullptr )
      {
        v11 = v10->GetRefEHandle(this: v10)->m_Index;
LABEL_9:
        if ( this->m_hAttachEntity.m_Value[0].m_Index != v11 )
          this->m_hAttachEntity.m_Value[0].m_Index = v11;
        C_BaseEntity::SetOwnerEntity(this, pOwner: v10);
        C_Beam::RelinkBeam(this);
        if ( v10 != nullptr )
          v10->m_iEFlags |= 0x80u;
        goto LABEL_13;
      }
    }
    else
    {
      v10 = nullptr;
    }
    v11 = -1;
    goto LABEL_9;
  }
LABEL_14:
  v12 = this->m_hEndEntity.m_Index;
  if ( v12 != -1 )
  {
    v13 = (unsigned __int16)v12;
    v14 = &v3->m_EntPtrArray[(unsigned __int16)v12];
    v15 = HIWORD(v12);
    if ( v14->m_SerialNumber == v15 && v14->m_pEntity != nullptr )
    {
      v16 = v13;
      v8 = v3->m_EntPtrArray[v16].m_SerialNumber == v15;
      v17 = (C_BaseEntity **)&v3->m_EntPtrArray[v16];
      if ( v8 )
        C_Beam::SetEndEntity(this, pEntity: *v17);
      else
        C_Beam::SetEndEntity(this, pEntity: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E140
// Name: public: void C_Beam::SetBeamFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::SetBeamFlags(C_Beam *this, int flags)
{
  if ( this->m_nBeamFlags.m_Value != flags )
    this->m_nBeamFlags.m_Value = flags;
}

//------------------------------------------------------------------------------
// Address: 0x1001E160
// Name: public: void C_Beam::SetAbsEndPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::SetAbsEndPos(C_Beam *this, const Vector *pos)
{
  unsigned int m_Index; // ecx
  float z; // xmm1_4
  float y; // xmm2_4
  matrix3x4_t worldToBeam; // [esp+4h] [ebp-3Ch] BYREF
  Vector vecLocalPos; // [esp+34h] [ebp-Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    C_BaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &worldToBeam);
    VectorTransform(in1: &pos->x, in2: &worldToBeam, out: &vecLocalPos.x);
    z = vecLocalPos.z;
    y = vecLocalPos.y;
    if ( vecLocalPos.x != this->m_vecEndPos.m_Value.x
      || vecLocalPos.y != this->m_vecEndPos.m_Value.y
      || vecLocalPos.z != this->m_vecEndPos.m_Value.z )
    {
      this->m_vecEndPos.m_Value.x = vecLocalPos.x;
      this->m_vecEndPos.m_Value.y = y;
      this->m_vecEndPos.m_Value.z = z;
    }
  }
  else if ( pos->x != this->m_vecEndPos.m_Value.x
         || pos->y != this->m_vecEndPos.m_Value.y
         || pos->z != this->m_vecEndPos.m_Value.z )
  {
    this->m_vecEndPos.m_Value = *pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E280
// Name: public: void C_Beam::BeamInit(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::BeamInit(C_Beam *this, const char *pSpriteName, float width)
{
  __int16 v4; // ax
  float v5; // xmm0_4
  float v6; // xmm1_4
  CHandle<C_BaseEntity> *v7; // edi
  int *v8; // eax
  int pSpriteNamea; // [esp+Ch] [ebp+8h]

  if ( this->m_clrRender.m_Value.r != 0xFF )
    this->m_clrRender.m_Value.r = -1;
  if ( this->m_clrRender.m_Value.g != 0xFF )
    this->m_clrRender.m_Value.g = -1;
  if ( this->m_clrRender.m_Value.b != 0xFF )
    this->m_clrRender.m_Value.b = -1;
  C_BaseEntity::SetRenderAlpha(this, a: 255);
  if ( this->m_fAmplitude.m_Value != 0.0 )
    this->m_fAmplitude.m_Value = 0.0;
  if ( this->m_fStartFrame.m_Value != 0.0 )
    this->m_fStartFrame.m_Value = 0.0;
  if ( this->m_fSpeed.m_Value != 0.0 )
    this->m_fSpeed.m_Value = 0.0;
  C_BaseEntity::SetModelName(this, name: pSpriteName);
  C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderTransTexture, bForceUpdate: false);
  v4 = C_BaseEntity::PrecacheModel(name: pSpriteName);
  C_BaseEntity::SetModelIndex(this, index: v4);
  v5 = width;
  if ( width <= 102.3 )
    v6 = width;
  else
    v6 = 102.3;
  if ( this->m_fWidth.m_Value != v6 )
    this->m_fWidth.m_Value = v6;
  if ( width > 102.3 )
    v5 = 102.3;
  if ( this->m_fEndWidth.m_Value != v5 )
    this->m_fEndWidth.m_Value = v5;
  if ( this->m_fFadeLength.m_Value != 0.0 )
    this->m_fFadeLength.m_Value = 0.0;
  this->Spawn(this);
  v7 = &this->m_hAttachEntity.m_Value[3];
  v8 = &this->m_nAttachIndex.m_Value[1];
  for ( pSpriteNamea = 2; pSpriteNamea != 0; --pSpriteNamea )
  {
    if ( v7[-3].m_Index != -1 )
      v7[-3].m_Index = -1;
    if ( *(v8 - 1) != 0 )
      *(v8 - 1) = 0;
    if ( *(v8 - 10) != -1 )
      *(v8 - 10) = -1;
    if ( *v8 != 0 )
      *v8 = 0;
    if ( v7[-1].m_Index != -1 )
      v7[-1].m_Index = -1;
    if ( v8[1] != 0 )
      v8[1] = 0;
    if ( v7->m_Index != -1 )
      v7->m_Index = -1;
    if ( v8[2] != 0 )
      v8[2] = 0;
    if ( v7[1].m_Index != -1 )
      v7[1].m_Index = -1;
    if ( v8[3] != 0 )
      v8[3] = 0;
    v8 += 5;
    v7 += 5;
  }
  if ( this->m_nHaloIndex.m_Value != 0 )
    this->m_nHaloIndex.m_Value = 0;
  if ( this->m_fHaloScale.m_Value != 10.0 )
    this->m_fHaloScale.m_Value = 10.0;
  if ( this->m_nBeamType.m_Value != 0 )
    this->m_nBeamType.m_Value = 0;
  if ( this->m_nBeamFlags.m_Value != 0 )
    this->m_nBeamFlags.m_Value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E470
// Name: public: void C_Beam::PointsInit(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::PointsInit(C_Beam *this, const Vector *start, const Vector *end)
{
  int m_Value; // eax

  if ( this->m_nBeamType.m_Value != 0 )
    this->m_nBeamType.m_Value = 0;
  if ( this->m_nNumBeamEnts.m_Value != 2 )
    this->m_nNumBeamEnts.m_Value = 2;
  C_BaseEntity::SetNetworkOrigin(this, org: start);
  C_BaseEntity::SetLocalOrigin(this, origin: start);
  if ( end->x != this->m_vecEndPos.m_Value.x
    || end->y != this->m_vecEndPos.m_Value.y
    || end->z != this->m_vecEndPos.m_Value.z )
  {
    this->m_vecEndPos.m_Value = *end;
  }
  if ( this->m_nAttachIndex.m_Value[0] != 0 )
    this->m_nAttachIndex.m_Value[0] = 0;
  m_Value = this->m_nNumBeamEnts.m_Value;
  if ( this->m_hAttachEntity.m_Value[m_Value + 9].m_Index != 0 )
    this->m_hAttachEntity.m_Value[m_Value + 9].m_Index = 0;
  C_Beam::RelinkBeam(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001E540
// Name: public: void C_Beam::RestoreToToolRecordedState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam::RestoreToToolRecordedState(C_Beam *this, KeyValues *pKV)
{
  int Int; // eax
  int v5; // eax
  __int16 v6; // ax
  int v7; // eax
  double Float; // st7
  double v9; // st7
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm0_4
  double v13; // st7
  double v14; // st7
  int v15; // eax
  float v16; // xmm0_4
  int v17; // eax
  unsigned __int8 v18; // al
  unsigned __int8 v19; // al
  unsigned __int8 v20; // al
  double v21; // st7
  double v22; // st7
  double v23; // st7
  CHandle<C_BaseEntity> *v24; // ecx
  int *v25; // eax
  int i; // ebx
  Vector vecMin; // [esp+Ch] [ebp-24h] BYREF
  Vector vecMax; // [esp+18h] [ebp-18h] BYREF
  Vector vTemp; // [esp+24h] [ebp-Ch] BYREF
  float pKVa; // [esp+38h] [ebp+8h]
  float pKVb; // [esp+38h] [ebp+8h]
  float pKVc; // [esp+38h] [ebp+8h]
  float pKVd; // [esp+38h] [ebp+8h]
  float pKVe; // [esp+38h] [ebp+8h]
  float pKVf; // [esp+38h] [ebp+8h]
  float pKVg; // [esp+38h] [ebp+8h]
  float pKVh; // [esp+38h] [ebp+8h]

  Int = KeyValues::GetInt(this: pKV, keyName: "beamType", defaultValue: 0);
  if ( this->m_nBeamType.m_Value != Int )
    this->m_nBeamType.m_Value = Int;
  v5 = KeyValues::GetInt(this: pKV, keyName: "beamEnts", defaultValue: 0);
  if ( this->m_nNumBeamEnts.m_Value != v5 )
    this->m_nNumBeamEnts.m_Value = v5;
  vTemp.x = KeyValues::GetFloat(this: pKV, keyName: "start_x", defaultValue: 0.0);
  vTemp.y = KeyValues::GetFloat(this: pKV, keyName: "start_y", defaultValue: 0.0);
  vTemp.z = KeyValues::GetFloat(this: pKV, keyName: "start_z", defaultValue: 0.0);
  C_Beam::SetAbsStartPos(this, pos: &vTemp);
  vTemp.x = KeyValues::GetFloat(this: pKV, keyName: "end_x", defaultValue: 0.0);
  vTemp.y = KeyValues::GetFloat(this: pKV, keyName: "end_y", defaultValue: 0.0);
  vTemp.z = KeyValues::GetFloat(this: pKV, keyName: "end_z", defaultValue: 0.0);
  C_Beam::SetAbsEndPos(this, pos: &vTemp);
  v6 = KeyValues::GetInt(this: pKV, keyName: "ModelIndex", defaultValue: 0);
  C_BaseEntity::SetModelIndex(this, index: v6);
  v7 = KeyValues::GetInt(this: pKV, keyName: "HaloIndex", defaultValue: 0);
  if ( this->m_nHaloIndex.m_Value != v7 )
    this->m_nHaloIndex.m_Value = v7;
  Float = KeyValues::GetFloat(this: pKV, keyName: "HaloScale", defaultValue: 0.0);
  if ( this->m_fHaloScale.m_Value != Float )
  {
    pKVa = Float;
    this->m_fHaloScale.m_Value = pKVa;
  }
  v9 = KeyValues::GetFloat(this: pKV, keyName: "Width", defaultValue: 0.0);
  if ( v9 <= 102.3 )
  {
    pKVb = v9;
    v10 = pKVb;
  }
  else
  {
    v10 = 102.3;
  }
  if ( this->m_fWidth.m_Value != v10 )
    this->m_fWidth.m_Value = v10;
  v11 = KeyValues::GetFloat(this: pKV, keyName: "EndWidth", defaultValue: 0.0);
  if ( v11 <= 102.3 )
  {
    pKVc = v11;
    v12 = pKVc;
  }
  else
  {
    v12 = 102.3;
  }
  if ( this->m_fEndWidth.m_Value != v12 )
    this->m_fEndWidth.m_Value = v12;
  v13 = KeyValues::GetFloat(this: pKV, keyName: "FadeLength", defaultValue: 0.0);
  if ( this->m_fFadeLength.m_Value != v13 )
  {
    pKVd = v13;
    this->m_fFadeLength.m_Value = pKVd;
  }
  v14 = KeyValues::GetFloat(this: pKV, keyName: "Noise", defaultValue: 0.0);
  if ( this->m_fAmplitude.m_Value != v14 )
  {
    pKVe = v14;
    this->m_fAmplitude.m_Value = pKVe;
  }
  v15 = KeyValues::GetInt(this: pKV, keyName: "Brightness", defaultValue: 255);
  if ( v15 >= 255 )
    v15 = 255;
  C_BaseEntity::SetRenderAlpha(this, a: (unsigned __int8)v15 & (unsigned __int8)((v15 <= 0) - 1));
  v16 = (float)(int)KeyValues::GetFloat(this: pKV, keyName: "ScrollRate", defaultValue: 0.0);
  if ( this->m_fSpeed.m_Value != v16 )
    this->m_fSpeed.m_Value = v16;
  v17 = KeyValues::GetInt(this: pKV, keyName: "beamFlags", defaultValue: 0);
  if ( this->m_nBeamFlags.m_Value != v17 )
    this->m_nBeamFlags.m_Value = v17;
  v18 = KeyValues::GetInt(this: pKV, keyName: "color_r", defaultValue: 0);
  if ( this->m_clrRender.m_Value.r != v18 )
    this->m_clrRender.m_Value.r = v18;
  v19 = KeyValues::GetInt(this: pKV, keyName: "color_g", defaultValue: 0);
  if ( this->m_clrRender.m_Value.g != v19 )
    this->m_clrRender.m_Value.g = v19;
  v20 = KeyValues::GetInt(this: pKV, keyName: "color_b", defaultValue: 0);
  if ( this->m_clrRender.m_Value.b != v20 )
    this->m_clrRender.m_Value.b = v20;
  v21 = KeyValues::GetFloat(this: pKV, keyName: "color_hdrscale", defaultValue: 0.0);
  if ( this->m_flHDRColorScale.m_Value != v21 )
  {
    pKVf = v21;
    this->m_flHDRColorScale.m_Value = pKVf;
  }
  v22 = KeyValues::GetFloat(this: pKV, keyName: "startframe", defaultValue: 0.0);
  if ( this->m_fStartFrame.m_Value != v22 )
  {
    pKVg = v22;
    this->m_fStartFrame.m_Value = pKVg;
  }
  v23 = KeyValues::GetFloat(this: pKV, keyName: "framerate", defaultValue: 0.0);
  if ( this->m_flFrameRate.m_Value != v23 )
  {
    pKVh = v23;
    this->m_flFrameRate.m_Value = pKVh;
  }
  v24 = &this->m_hAttachEntity.m_Value[3];
  v25 = &this->m_nAttachIndex.m_Value[1];
  for ( i = 2; i != 0; --i )
  {
    if ( v24[-3].m_Index != -1 )
      v24[-3].m_Index = -1;
    if ( *(v25 - 1) != 0 )
      *(v25 - 1) = 0;
    if ( *(v25 - 10) != -1 )
      *(v25 - 10) = -1;
    if ( *v25 != 0 )
      *v25 = 0;
    if ( v24[-1].m_Index != -1 )
      v24[-1].m_Index = -1;
    if ( v25[1] != 0 )
      v25[1] = 0;
    if ( v24->m_Index != -1 )
      v24->m_Index = -1;
    if ( v25[2] != 0 )
      v25[2] = 0;
    if ( v24[1].m_Index != -1 )
      v24[1].m_Index = -1;
    if ( v25[3] != 0 )
      v25[3] = 0;
    v25 += 5;
    v24 += 5;
  }
  vecMax.x = 16384.0;
  vecMax.y = 16384.0;
  vecMax.z = 16384.0;
  vecMin.x = -16384.0;
  vecMin.y = -16384.0;
  vecMin.z = -16384.0;
  C_BaseEntity::SetSize(this, &vecMin, &vecMax);
  if ( this != (C_Beam *)-616 )
    this->m_VisibilityBits.m_Ints[0] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA30
// Name: public: virtual void __near * C_Beam_NonConformantDataHandler::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
C_Beam *__thiscall C_Beam_NonConformantDataHandler::CreateInstance(C_Beam_NonConformantDataHandler *this)
{
  C_Beam *v1; // eax

  v1 = (C_Beam *)C_BaseEntity::operator new(stAllocateBlock: 0xA28u);
  if ( v1 != nullptr )
    return C_Beam::C_Beam(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA50
// Name: public: static class C_Beam __near * C_Beam::BeamCreate(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
C_Beam *__cdecl C_Beam::BeamCreate(const char *pSpriteName, float width)
{
  C_BaseEntity *EntityByName; // eax
  C_Beam *v3; // esi

  EntityByName = CreateEntityByName(className: "beam");
  v3 = (C_Beam *)__RTDynamicCast(
                   inptr: EntityByName,
                   VfDelta: 0,
                   SrcType: &C_BaseEntity `RTTI Type Descriptor',
                   TargetType: &C_Beam `RTTI Type Descriptor',
                   isReference: 0);
  if ( v3 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "beam");
  C_Beam::BeamInit(this: v3, pSpriteName, width);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAB0
// Name: public: virtual void C_Beam_NonConformantDataHandler::DestroyInstance(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam_NonConformantDataHandler::DestroyInstance(C_Beam_NonConformantDataHandler *this, char *pEntity)
{
  IClientRenderable *v2; // eax

  if ( pEntity != nullptr )
    v2 = (IClientRenderable *)(pEntity + 4);
  else
    v2 = nullptr;
  clienttools->RemoveClientRenderable(this: clienttools, a2: v2);
  if ( pEntity != nullptr )
    (**(void (__thiscall ***)(char *, int))pEntity)(a1: pEntity, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001EAF0
// Name: public: virtual void C_Beam_NonConformantDataHandler::HandleInstance(void __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Beam_NonConformantDataHandler::HandleInstance(
        C_Beam_NonConformantDataHandler *this,
        C_Beam *pEntity,
        KeyValues *pKeyValues)
{
  IClientRenderable *v3; // esi

  C_Beam::RestoreToToolRecordedState(this: pEntity, pKV: pKeyValues);
  v3 = &pEntity->IClientRenderable;
  if ( *pEntity->RenderHandle(this: &pEntity->IClientRenderable) == 0xFFFF )
    clienttools->AddClientRenderable(
      this: clienttools,
      a2: v3,
      a3: false,
      a4: RENDERABLE_IS_TRANSLUCENT,
      a5: RENDERABLE_MODEL_UNKNOWN_TYPE);
  clienttools->MarkClientRenderableDirty(this: clienttools, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10410270
// Name: DT_Beam::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Beam::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Beam::g_RecvTable);
  return atexit(func: DT_Beam::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410290
// Name: DT_Beam::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Beam::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Beam::ignored>();
  DT_Beam::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104102A0
// Name: C_Beam_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_Beam_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_Beam::m_PredMap.dataNumFields = 20;
  C_Beam::m_PredMap.dataDesc = (typedescription_t *)&unk_105986F4;
}

//------------------------------------------------------------------------------
// Address: 0x1042F980
// Name: DT_Beam::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Beam::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Beam::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1001E9E0
// Name: _C_Beam_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Beam_CreateObject(int entnum, int serialNum)
{
  C_Beam *v2; // eax
  C_Beam *v3; // eax
  C_Beam *v4; // esi

  v2 = (C_Beam *)C_BaseEntity::operator new(stAllocateBlock: 0xA28u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Beam::C_Beam(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104102C0
// Name: _dynamic_initializer_for__s_BeamEntityIFMHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BeamEntityIFMHandler__()
{
  CIFM_EntityKeyValuesHandler_RecreateEntities::CIFM_EntityKeyValuesHandler_RecreateEntities(
    this: &s_BeamEntityIFMHandler,
    szHandlerID: "C_Beam");
  s_BeamEntityIFMHandler.__vftable = (C_Beam_NonConformantDataHandler_vtbl *)&C_Beam_NonConformantDataHandler::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__s_BeamEntityIFMHandler__);
}

//------------------------------------------------------------------------------
// Address: 0x104102F0
// Name: _dynamic_initializer_for____g_C_AI_BaseNPCClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_AI_BaseNPCClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_AI_BaseNPCClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_AI_BaseNPCClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F990
// Name: _dynamic_atexit_destructor_for__s_BeamEntityIFMHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_BeamEntityIFMHandler__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_BeamEntityIFMHandler.m_PlaybackEntities);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100DE180
// Name: public: virtual class ServerClass __near * CBeam::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBeam::GetServerClass(CBeam *this)
{
  return &g_CBeam_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100DE190
// Name: public: virtual struct datamap_t __near * CBeam::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBeam::GetDataDescMap(CBeam *this)
{
  return &CBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100DE1A0
// Name: public: virtual void CBeam::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetModel(CBeam *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 2 )
    _Msg(a1: "Setting CBeam to non-sprite model %s\n", szModelName);
  UTIL_SetModel(pEntity: this, pModelName: szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x100DE200
// Name: public: class CBaseEntity __near * CBeam::RandomTargetname(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBeam::RandomTargetname(CBeam *this, const char *szName)
{
  CBaseEntity *EntityByName; // esi
  int v3; // edi
  CBaseEntity *pEntity; // [esp+Ch] [ebp-4h]

  pEntity = nullptr;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return nullptr;
  v3 = -1;
  do
  {
    if ( random->RandomInt(this: random, a2: 0, a3: ++v3) < 1 )
      pEntity = EntityByName;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
  }
  while ( EntityByName != nullptr );
  return pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100DE280
// Name: public: int CBeam::GetStartEntity(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeam::GetStartEntity(CBeam *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v3; // eax

  m_Index = this->m_hAttachEntity.m_Value[0].m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
    && (v3 = m_pEntity[6].__vftable) != nullptr )
  {
    return ((char *)v3 - (char *)gpGlobals->pEdicts) >> 4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE2D0
// Name: public: int CBeam::GetEndEntity(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeam::GetEndEntity(CBeam *this)
{
  unsigned int v1; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v3; // eax

  v1 = *(&this->m_nBeamFlags.m_Value + this->m_nNumBeamEnts.m_Value);
  if ( v1 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_SerialNumber == HIWORD(v1)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_pEntity) != nullptr
    && (v3 = m_pEntity[6].__vftable) != nullptr )
  {
    return ((char *)v3 - (char *)gpGlobals->pEdicts) >> 4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE320
// Name: public: class Vector const __near & CBeam::GetAbsStartPos(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CBeam::GetAbsStartPos@<eax>(CBeam *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v5; // eax
  edict_t *pEdicts; // esi
  int StartEntity; // eax
  int v8; // ecx
  edict_t *v9; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v11; // eax
  CBaseEntity *v12; // esi
  bool v13; // zf

  if ( this->m_nBeamType.m_Value != 2
    || (m_Index = this->m_hAttachEntity.m_Value[0].m_Index) == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
    || (v5 = m_pEntity[6].__vftable) == nullptr
    || (pEdicts = gpGlobals->pEdicts, ((char *)v5 - (char *)pEdicts) >> 4 == 0) )
  {
    v13 = (this->m_iEFlags & 0x800) == 0;
    goto LABEL_20;
  }
  if ( pEdicts != nullptr )
  {
    StartEntity = CBeam::GetStartEntity(this);
    v8 = (pEdicts[StartEntity].m_fStateFlags & 2) == 0 ? (unsigned int)&pEdicts[StartEntity] : 0;
  }
  else
  {
    v8 = 0;
  }
  v9 = (edict_t *)v8;
  if ( v8 == 0 && (pEdicts == nullptr || (v9 = pEdicts, (pEdicts->m_fStateFlags & 2) != 0))
    || (m_pUnk = v9->m_pUnk) == nullptr
    || (v11 = m_pUnk->GetBaseEntity(this: m_pUnk), v12 = v11, v11 == nullptr) )
  {
    v13 = (this->m_iEFlags & 0x800) == 0;
LABEL_20:
    if ( !v13 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    return &this->m_vecAbsOrigin;
  }
  if ( (v11->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v11, a2);
  return &v12->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x100DE430
// Name: public: virtual int CBeam::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeam::DrawDebugTextOverlays(CBeam *this)
{
  int result; // eax
  int v3; // edi
  int v4; // edi
  char tempstr[512]; // [esp+20h] [ebp-200h] BYREF
  int savedregs; // [esp+220h] [ebp+0h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "start: (%.2f,%.2f,%.2f)",
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v4 = v3 + 1;
    V_snprintf(
      pDest: tempstr,
      maxLen: 512,
      pFormat: "end  : (%.2f,%.2f,%.2f)",
      this->m_vecEndPos.m_Value.x,
      this->m_vecEndPos.m_Value.y,
      this->m_vecEndPos.m_Value.z);
    CBaseEntity::EntityText(this, text_offset: v4, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DE5A0
// Name: public: virtual void CInfoTarget::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoTarget::Spawn(CInfoTarget *this)
{
  CPointEntity::Spawn(this);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_iEFlags = 128;
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DE5D0
// Name: public: virtual int CInfoTarget::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInfoTarget::UpdateTransmitState(CInfoTarget *this)
{
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  else
    return CBaseEntity::UpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DE5F0
// Name: bool IsStaticPointEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsStaticPointEntity(CBaseEntity *pEnt)
{
  unsigned int m_Index; // eax

  m_Index = pEnt->m_hMoveParent.m_Value.m_Index;
  return (m_Index == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr)
      && (pEnt->GetModelIndex(this: pEnt) == 0
       || pEnt->m_iClassname.pszValue == "info_target"
       || CBaseEntity::ClassMatchesComplex(this: pEnt, pszClassOrWildcard: "info_target") != 0
       || pEnt->m_iClassname.pszValue == "info_landmark"
       || CBaseEntity::ClassMatchesComplex(this: pEnt, pszClassOrWildcard: "info_landmark") != 0
       || FClassnameIs(pEntity: pEnt, szClassname: "path_corner"));
}

//------------------------------------------------------------------------------
// Address: 0x100DEBF0
// Name: public: void CBeam::SetAbsStartPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetAbsStartPos(CBeam *this, const Vector *pos)
{
  unsigned int m_Index; // ecx
  matrix3x4_t worldToBeam; // [esp+4h] [ebp-3Ch] BYREF
  Vector vecLocalPos; // [esp+34h] [ebp-Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &worldToBeam);
    VectorTransform(in1: &pos->x, in2: &worldToBeam, out: &vecLocalPos.x);
    CBaseEntity::SetLocalOrigin(this, origin: &vecLocalPos);
  }
  else
  {
    CBaseEntity::SetLocalOrigin(this, origin: pos);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEC90
// Name: public: class Vector const __near & CBeam::GetAbsEndPos(void)const
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *__usercall CBeam::GetAbsEndPos@<eax>(
        CBeam *this@<ecx>,
        int a2@<ebp>)
{
  int m_Value; // eax
  CGlobalVars *v4; // edi
  int EndEntity; // eax
  edict_t *v6; // ecx
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // edi
  unsigned int m_Index; // ecx

  m_Value = this->m_nBeamType.m_Value;
  if ( m_Value != 0
    && m_Value != 3
    && CBeam::GetEndEntity(this) != 0
    && ((v4 = gpGlobals, gpGlobals->pEdicts == nullptr)
      ? (v6 = nullptr)
      : (EndEntity = CBeam::GetEndEntity(this),
         v6 = (v4->pEdicts[EndEntity].m_fStateFlags & 2) == 0 ? &v4->pEdicts[EndEntity] : nullptr),
        v7 = CBaseEntity::Instance(pent: v6),
        v8 = v7,
        v7 != nullptr) )
  {
    if ( (v7->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v7, a2);
    return (CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *)&v8->m_vecAbsOrigin;
  }
  else
  {
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( (_S4_15 & 1) == 0 )
        _S4_15 |= 1u;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      VectorTransform(in1: &this->m_vecEndPos.m_Value.x, in2: &this->m_rgflCoordinateFrame, out: &vecAbsPos.x);
      return (CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *)&vecAbsPos;
    }
    else
    {
      return &this->m_vecEndPos;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DED90
// Name: public: void CBeam::RelinkBeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::RelinkBeam(CBeam *this)
{
  const Vector *AbsStartPos; // eax
  __int64 v3; // xmm0_8
  float z; // eax
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *AbsEndPos; // eax
  float v6; // ecx
  double x; // xmm0_8
  float v8; // xmm0_4
  double y; // xmm0_8
  float v10; // xmm0_4
  double v11; // xmm0_8
  float v12; // xmm4_4
  double v13; // xmm0_8
  float v14; // xmm3_4
  double v15; // xmm0_8
  float v16; // xmm2_4
  double v17; // xmm0_8
  unsigned int v18; // edx
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  unsigned int v22; // eax
  float v23; // xmm4_4
  Vector mins; // [esp+4h] [ebp-30h] BYREF
  Vector startPos; // [esp+10h] [ebp-24h] BYREF
  Vector vecBeamMax; // [esp+1Ch] [ebp-18h]
  Vector vecBeamMin; // [esp+28h] [ebp-Ch]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  AbsStartPos = CBeam::GetAbsStartPos(this, a2: (int)&savedregs);
  v3 = *(_QWORD *)&AbsStartPos->x;
  z = AbsStartPos->z;
  *(_QWORD *)&startPos.x = v3;
  startPos.z = z;
  AbsEndPos = CBeam::GetAbsEndPos(this, a2: (int)&savedregs);
  v6 = AbsEndPos->m_Value.z;
  *(_QWORD *)&vecBeamMax.x = *(_QWORD *)&AbsEndPos->m_Value.x;
  x = *(float *)&v3;
  vecBeamMax.z = v6;
  if ( startPos.x > (double)vecBeamMax.x )
    x = vecBeamMax.x;
  v8 = x;
  vecBeamMin.x = v8;
  y = startPos.y;
  if ( startPos.y > (double)vecBeamMax.y )
    y = vecBeamMax.y;
  v10 = y;
  vecBeamMin.y = v10;
  v11 = startPos.z;
  if ( startPos.z > (double)vecBeamMax.z )
    v11 = vecBeamMax.z;
  v12 = v11;
  v13 = startPos.x;
  vecBeamMin.z = v12;
  if ( startPos.x < (double)vecBeamMax.x )
    v13 = vecBeamMax.x;
  v14 = v13;
  v15 = startPos.y;
  vecBeamMax.x = v14;
  if ( startPos.y < (double)vecBeamMax.y )
    v15 = vecBeamMax.y;
  v16 = v15;
  v17 = startPos.z;
  vecBeamMax.y = v16;
  if ( startPos.z < (double)vecBeamMax.z )
    v17 = vecBeamMax.z;
  v18 = (unsigned int)this->m_iEFlags >> 11;
  v19 = v17;
  vecBeamMax.z = v19;
  if ( (v18 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v14 = vecBeamMax.x;
    v12 = vecBeamMin.z;
    v16 = vecBeamMax.y;
    v19 = vecBeamMax.z;
  }
  v20 = v16 - this->m_vecAbsOrigin.y;
  v21 = v19 - this->m_vecAbsOrigin.z;
  v22 = (unsigned int)this->m_iEFlags >> 11;
  startPos.x = v14 - this->m_vecAbsOrigin.x;
  startPos.y = v20;
  startPos.z = v21;
  if ( (v22 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v12 = vecBeamMin.z;
  }
  v23 = v12 - this->m_vecAbsOrigin.z;
  mins.x = vecBeamMin.x - this->m_vecAbsOrigin.x;
  mins.y = vecBeamMin.y - this->m_vecAbsOrigin.y;
  mins.z = v23;
  CBaseEntity::SetCollisionBounds(this, &mins, maxs: &startPos);
}

//------------------------------------------------------------------------------
// Address: 0x100DEF60
// Name: public: void CBeam::DoSparks(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::DoSparks(CBeam *this, const Vector *start, const Vector *end)
{
  int m_Value; // eax

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x30) != 0 )
  {
    if ( (m_Value & 0x10) != 0 )
      g_pEffects->Sparks(this: g_pEffects, a2: start, a3: 1, a4: 1, a5: nullptr);
    if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
      g_pEffects->Sparks(this: g_pEffects, a2: end, a3: 1, a4: 1, a5: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEFC0
// Name: public: void CBeam::BeamDamage(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::BeamDamage(CBeam *this, CGameTrace *ptr)
{
  int m_nDissolveType; // ecx
  int v5; // eax
  const char *v6; // eax
  CTakeDamageInfo info; // [esp+1Ch] [ebp-68h] BYREF
  Vector dir; // [esp+78h] [ebp-Ch] BYREF
  int savedregs; // [esp+84h] [ebp+0h] BYREF
  CBaseEntity *ptra; // [esp+8Ch] [ebp+8h]

  CBeam::RelinkBeam(this);
  if ( ptr->fraction != 1.0 )
  {
    ptra = ptr->m_pEnt;
    if ( ptra != nullptr )
    {
      ClearMultiDamage();
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      dir.x = ptr->endpos.x - this->m_vecAbsOrigin.x;
      dir.y = ptr->endpos.y - this->m_vecAbsOrigin.y;
      dir.z = ptr->endpos.z - this->m_vecAbsOrigin.z;
      VectorNormalize(vec: &dir);
      m_nDissolveType = this->m_nDissolveType;
      v5 = 1024;
      if ( m_nDissolveType != 0 )
      {
        if ( m_nDissolveType > 0 )
          v5 = 67109120;
      }
      else
      {
        v5 = 0x4000000;
      }
      CTakeDamageInfo::CTakeDamageInfo(
        this: &info,
        pInflictor: this,
        pAttacker: this,
        flDamage: (float)(gpGlobals->curtime - this->m_flFireTime) * this->m_flDamage,
        bitsDamageType: v5,
        iKillType: 0,
        iObjectsPenetrated: 0);
      CalculateMeleeDamageForce(&info, vecMeleeDir: &dir, vecForceOrigin: &ptr->endpos, flScale: 1.0);
      CBaseEntity::DispatchTraceAttack(this: ptra, &info, vecDir: &dir, ptr);
      ApplyMultiDamage();
      if ( (this->m_spawnflags.m_Value & 0x40) != 0 && CBaseEntity::IsBSPModel(this: ptra) )
      {
        v6 = this->GetDecalName(this);
        UTIL_DecalTrace(pTrace: ptr, decalName: v6);
      }
    }
  }
  this->m_flFireTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x100DF130
// Name: public: virtual int CBeam::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeam::UpdateTransmitState(CBeam *this)
{
  unsigned int m_Index; // edx

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  }
  else
  {
    return CBaseEntity::UpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF170
// Name: public: virtual void CBeam::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetTransmit(CBeam *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  CBeam::NetworkVar_m_hAttachEntity *p_m_hAttachEntity; // edi
  CBaseEntityList *v7; // esi
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CEntInfo *v14; // eax
  IHandleEntity *m_pEntity; // ecx
  int pInfoa; // [esp+14h] [ebp+8h]

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    p_m_hAttachEntity = &this->m_hAttachEntity;
    v7 = g_pEntityList;
    for ( pInfoa = 10; pInfoa != 0; --pInfoa )
    {
      m_Index = p_m_hAttachEntity->m_Value[0].m_Index;
      if ( p_m_hAttachEntity->m_Value[0].m_Index != -1 )
      {
        v9 = (unsigned __int16)m_Index;
        v10 = &v7->m_EntPtrArray[(unsigned __int16)m_Index];
        v11 = HIWORD(m_Index);
        if ( v10->m_SerialNumber == v11 && v10->m_pEntity != nullptr )
        {
          v12 = v9;
          v13 = v7->m_EntPtrArray[v12].m_SerialNumber == v11;
          v14 = &v7->m_EntPtrArray[v12];
          if ( v13 )
            m_pEntity = v14->m_pEntity;
          else
            m_pEntity = nullptr;
          ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))m_pEntity->__vftable[7].SetRefEHandle)(
            a1: m_pEntity,
            a2: pInfo,
            a3: bAlways);
          v7 = g_pEntityList;
        }
      }
      p_m_hAttachEntity = (CBeam::NetworkVar_m_hAttachEntity *)((char *)p_m_hAttachEntity + 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF230
// Name: public: virtual int CBeam::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBeam::ShouldTransmit(CBeam *this, const CCheckTransmitInfo *pInfo)
{
  unsigned int m_Index; // edx
  int v4; // eax
  CEntInfo *v5; // esi
  unsigned int v6; // edx
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
    return 16;
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 )
    return CBaseEntity::ShouldTransmit(this, pInfo);
  v4 = (unsigned __int16)m_Index;
  v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v6 = HIWORD(m_Index);
  if ( v5->m_SerialNumber != v6 || v5->m_pEntity == nullptr )
    return CBaseEntity::ShouldTransmit(this, pInfo);
  v7 = g_pEntityList->m_EntPtrArray[v4].m_SerialNumber == v6;
  v8 = &g_pEntityList->m_EntPtrArray[v4];
  if ( v7 )
    m_pEntity = v8->m_pEntity;
  else
    m_pEntity = nullptr;
  return ((int (__thiscall *)(IHandleEntity *, const CCheckTransmitInfo *))m_pEntity->__vftable[6].GetRefEHandle)(
           a1: m_pEntity,
           a2: pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x100DF2A0
// Name: public: void CBeam::SetStartEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetStartEntity(CBeam *this, CBaseEntity *pEntity)
{
  edict_t *m_pPev; // ecx
  unsigned int pEntitya; // [esp+14h] [ebp+8h]

  if ( pEntity != nullptr )
    pEntitya = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    pEntitya = -1;
  if ( this->m_hAttachEntity.m_Value[0].m_Index != pEntitya )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
    }
    this->m_hAttachEntity.m_Value[0].m_Index = pEntitya;
  }
  this->SetOwnerEntity(this, a2: pEntity);
  CBeam::RelinkBeam(this);
  if ( pEntity != nullptr )
  {
    pEntity->m_iEFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this: pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF330
// Name: public: void CBeam::SetEndEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetEndEntity(CBeam *this, CBaseEntity *pEntity)
{
  int m_Value; // esi
  CBeam::NetworkVar_m_hAttachEntity *p_m_hAttachEntity; // edi
  CHandle<CBaseEntity> *v6; // eax
  CBaseEdict *m_Index; // ecx
  unsigned int pEntitya; // [esp+14h] [ebp+8h]

  if ( pEntity != nullptr )
    pEntitya = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    pEntitya = -1;
  m_Value = this->m_nNumBeamEnts.m_Value;
  p_m_hAttachEntity = &this->m_hAttachEntity;
  if ( p_m_hAttachEntity->m_Value[m_Value - 1].m_Index != pEntitya )
  {
    v6 = &p_m_hAttachEntity[-23].m_Value[9];
    if ( LOBYTE(p_m_hAttachEntity[-20].m_Value[0].m_Index) != 0 )
    {
      LOBYTE(v6[22].m_Index) |= 1u;
    }
    else
    {
      m_Index = (CBaseEdict *)v6[6].m_Index;
      if ( m_Index != nullptr )
        CBaseEdict::StateChanged(this: m_Index, offset: 4 * m_Value - 4 + 884);
    }
    p_m_hAttachEntity->m_Value[m_Value - 1].m_Index = pEntitya;
  }
  if ( pEntity != nullptr )
    this->m_hEndEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    this->m_hEndEntity.m_Index = -1;
  CBeam::RelinkBeam(this);
  if ( pEntity != nullptr )
  {
    pEntity->m_iEFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this: pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF430
// Name: public: void CBeam::SetEndPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetEndPos(CBeam *this, const Vector *pos)
{
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *p_m_vecEndPos; // esi
  edict_t *m_pPev; // ecx

  p_m_vecEndPos = &this->m_vecEndPos;
  if ( pos->x != this->m_vecEndPos.m_Value.x
    || pos->y != this->m_vecEndPos.m_Value.y
    || pos->z != this->m_vecEndPos.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3E8u);
    }
    p_m_vecEndPos->m_Value = *pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF4B0
// Name: public: void CBeam::SetScrollRate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetScrollRate(CBeam *this, int speed)
{
  CNetworkVarBase<float,CBeam::NetworkVar_m_fSpeed> *p_m_fSpeed; // esi
  float v3; // xmm0_4
  edict_t *m_pPev; // ecx
  float speeda; // [esp+8h] [ebp+8h]

  p_m_fSpeed = &this->m_fSpeed;
  v3 = (float)speed;
  speeda = (float)speed;
  if ( this->m_fSpeed.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fSpeed->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3DCu);
        v3 = speeda;
      }
      p_m_fSpeed->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF520
// Name: public: CBeam::CBeam(void)
// Source: json
//------------------------------------------------------------------------------
CBeam *__thiscall CBeam::CBeam(CBeam *this)
{
  CBeam *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBeam_vtbl *)&CBeam::`vftable';
  this->m_hAttachEntity.m_Value[0].m_Index = -1;
  this->m_hAttachEntity.m_Value[1].m_Index = -1;
  this->m_hAttachEntity.m_Value[2].m_Index = -1;
  this->m_hAttachEntity.m_Value[3].m_Index = -1;
  this->m_hAttachEntity.m_Value[4].m_Index = -1;
  this->m_hAttachEntity.m_Value[5].m_Index = -1;
  this->m_hAttachEntity.m_Value[6].m_Index = -1;
  this->m_hAttachEntity.m_Value[7].m_Index = -1;
  this->m_hAttachEntity.m_Value[8].m_Index = -1;
  this->m_hAttachEntity.m_Value[9].m_Index = -1;
  this->m_hEndEntity.m_Index = -1;
  result = this;
  if ( this->m_flHDRColorScale.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
    }
    this->m_flHDRColorScale.m_Value = 1.0;
    result = this;
  }
  this->m_nDissolveType = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DF5D0
// Name: public: virtual char const __near * CBeam::GetDecalName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBeam::GetDecalName(CBeam *this)
{
  return "BigShot";
}

//------------------------------------------------------------------------------
// Address: 0x100DF610
// Name: public: virtual class Vector const __near & CBeam::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CBeam::WorldSpaceCenter@<eax>(CBeam *this@<ecx>, int a2@<ebp>)
{
  Vector *v3; // esi
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *AbsEndPos; // edi
  const Vector *AbsStartPos; // eax
  float x; // xmm1_4

  v3 = AllocTempVector();
  AbsEndPos = CBeam::GetAbsEndPos(this, a2);
  AbsStartPos = CBeam::GetAbsStartPos(this, a2);
  v3->x = AbsStartPos->x + AbsEndPos->m_Value.x;
  x = v3->x;
  v3->y = AbsStartPos->y + AbsEndPos->m_Value.y;
  v3->z = AbsStartPos->z + AbsEndPos->m_Value.z;
  v3->x = x * 0.5;
  v3->y = v3->y * 0.5;
  v3->z = v3->z * 0.5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100DF690
// Name: public: virtual void CBeam::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::Precache(CBeam *this)
{
  CBaseEntityList *v1; // edx
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // esi
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBaseEntity **v9; // eax
  CBaseEntity *v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  CEntInfo *v13; // esi
  unsigned int v14; // ecx
  int v15; // eax
  CBaseEntity **v16; // eax

  v1 = g_pEntityList;
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CBeam::SetStartEntity(this, pEntity: v10);
      v1 = g_pEntityList;
    }
  }
  v11 = this->m_hEndEntity.m_Index;
  if ( v11 != -1 )
  {
    v12 = (unsigned __int16)v11;
    v13 = &v1->m_EntPtrArray[(unsigned __int16)v11];
    v14 = HIWORD(v11);
    if ( v13->m_SerialNumber == v14 && v13->m_pEntity != nullptr )
    {
      v15 = v12;
      v8 = v1->m_EntPtrArray[v15].m_SerialNumber == v14;
      v16 = (CBaseEntity **)&v1->m_EntPtrArray[v15];
      if ( v8 )
        CBeam::SetEndEntity(this, pEntity: *v16);
      else
        CBeam::SetEndEntity(this, pEntity: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF730
// Name: public: void CBeam::SetType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetType(CBeam *this, int type)
{
  CNetworkVarBase<int,CBeam::NetworkVar_m_nBeamType> *p_m_nBeamType; // esi
  edict_t *m_pPev; // ecx

  p_m_nBeamType = &this->m_nBeamType;
  if ( this->m_nBeamType.m_Value != type )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nBeamType->m_Value = type;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      p_m_nBeamType->m_Value = type;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF780
// Name: public: void CBeam::SetAbsEndPos(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetAbsEndPos(CBeam *this, const Vector *pos)
{
  unsigned int m_Index; // ecx
  matrix3x4_t worldToBeam; // [esp+4h] [ebp-3Ch] BYREF
  Vector vecLocalPos; // [esp+34h] [ebp-Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &worldToBeam);
    VectorTransform(in1: &pos->x, in2: &worldToBeam, out: &vecLocalPos.x);
    CBeam::SetEndPos(this, pos: &vecLocalPos);
  }
  else
  {
    CBeam::SetEndPos(this, pos);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF820
// Name: public: void CBeam::PointsInit(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::PointsInit(CBeam *this, const Vector *start, const Vector *end)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  CBeam::NetworkVar_m_nAttachIndex *p_m_nAttachIndex; // esi
  edict_t *v7; // ecx
  int m_Value; // edi
  edict_t *v9; // ecx

  if ( this->m_nBeamType.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_nBeamType.m_Value = 0;
  }
  if ( this->m_nNumBeamEnts.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
    }
    this->m_nNumBeamEnts.m_Value = 2;
  }
  CBaseEntity::SetLocalOrigin(this, origin: start);
  CBeam::SetEndPos(this, pos: end);
  p_m_nAttachIndex = &this->m_nAttachIndex;
  if ( this->m_nAttachIndex.m_Value[0] != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x39Cu);
    }
    p_m_nAttachIndex->m_Value[0] = 0;
  }
  m_Value = this->m_nNumBeamEnts.m_Value;
  if ( p_m_nAttachIndex->m_Value[m_Value - 1] != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 4 * m_Value - 4 + 924);
    }
    p_m_nAttachIndex->m_Value[m_Value - 1] = 0;
  }
  CBeam::RelinkBeam(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DF940
// Name: public: void CBeam::EntsInit(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::EntsInit(CBeam *this, CBaseEntity *pStartEntity, CBaseEntity *pEndEntity)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  CBeam::NetworkVar_m_nAttachIndex *p_m_nAttachIndex; // esi
  edict_t *v7; // ecx
  int m_Value; // edi
  edict_t *v9; // ecx

  if ( this->m_nBeamType.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_nBeamType.m_Value = 2;
  }
  if ( this->m_nNumBeamEnts.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
    }
    this->m_nNumBeamEnts.m_Value = 2;
  }
  CBeam::SetStartEntity(this, pEntity: pStartEntity);
  CBeam::SetEndEntity(this, pEntity: pEndEntity);
  p_m_nAttachIndex = &this->m_nAttachIndex;
  if ( this->m_nAttachIndex.m_Value[0] != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x39Cu);
    }
    p_m_nAttachIndex->m_Value[0] = 0;
  }
  m_Value = this->m_nNumBeamEnts.m_Value;
  if ( p_m_nAttachIndex->m_Value[m_Value - 1] != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 4 * m_Value - 4 + 924);
    }
    p_m_nAttachIndex->m_Value[m_Value - 1] = 0;
  }
  CBeam::RelinkBeam(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DFA60
// Name: private: void CBeam::InputWidth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::InputWidth(CBeam *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  float v5; // xmm0_4
  edict_t *v6; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    if ( flVal > 102.3 )
      flVal = 102.3;
  }
  else
  {
    flVal = 0.0;
  }
  if ( this->m_fWidth.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C4u);
    }
    this->m_fWidth.m_Value = flVal;
  }
  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    v5 = inputdata->value.flVal;
    if ( v5 > 102.3 )
      v5 = 102.3;
  }
  else
  {
    v5 = 0.0;
  }
  if ( this->m_fEndWidth.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fEndWidth.m_Value = v5;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3C8u);
      this->m_fEndWidth.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFB50
// Name: private: void CBeam::InputNoise(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::InputNoise(CBeam *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CBeam::NetworkVar_m_fAmplitude> *p_m_fAmplitude; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_fAmplitude = &this->m_fAmplitude;
  if ( this->m_fAmplitude.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fAmplitude->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3D4u);
      p_m_fAmplitude->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFBD0
// Name: public: virtual void CBeam::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::Spawn(CBeam *this)
{
  edict_t *m_pPev; // ecx

  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  CBaseEntity::AddEffects(this, nEffects: 1104);
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DFC90
// Name: public: void CBeam::BeamInit(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::BeamInit(CBeam *this, const char *pSpriteName, float width)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  const char *v8; // eax
  edict_t *v9; // ecx
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  edict_t *v15; // ecx
  CBeam *v16; // ebx
  int v17; // esi
  CBeam::NetworkVar_m_hAttachEntity *p_m_hAttachEntity; // edi
  CBeam::NetworkVar_m_nAttachIndex *p_m_nAttachIndex; // ebx
  CHandle<CBaseEntity> *v20; // eax
  CBaseEdict *m_Index; // ecx
  int *v22; // eax
  CBaseEdict *v23; // ecx
  edict_t *v24; // ecx
  edict_t *v25; // ecx
  edict_t *v26; // ecx
  edict_t *v27; // ecx

  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  if ( this->m_fAmplitude.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3D4u);
    }
    this->m_fAmplitude.m_Value = 0.0;
  }
  if ( this->m_fStartFrame.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3D8u);
    }
    this->m_fStartFrame.m_Value = 0.0;
  }
  if ( this->m_fSpeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x3DCu);
    }
    this->m_fSpeed.m_Value = 0.0;
  }
  if ( pSpriteName != nullptr && *pSpriteName != 0 )
    v8 = pSpriteName;
  else
    v8 = nullptr;
  this->m_ModelName.pszValue = v8;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  v10 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this, name: pSpriteName, bPreload: true);
  this->SetModelIndex(this, a2: v10);
  v11 = width;
  if ( width <= 102.3 )
    v12 = width;
  else
    v12 = 102.3;
  if ( this->m_fWidth.m_Value != v12 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x3C4u);
        v11 = width;
      }
    }
    this->m_fWidth.m_Value = v12;
  }
  if ( v11 > 102.3 )
    v11 = 102.3;
  if ( this->m_fEndWidth.m_Value != v11 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x3C8u);
    }
    this->m_fEndWidth.m_Value = v11;
  }
  if ( this->m_fFadeLength.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x3CCu);
    }
    this->m_fFadeLength.m_Value = 0.0;
  }
  v16 = this;
  this->Spawn(this);
  v17 = 0;
  p_m_hAttachEntity = &this->m_hAttachEntity;
  p_m_nAttachIndex = &v16->m_nAttachIndex;
  do
  {
    if ( p_m_hAttachEntity->m_Value[v17].m_Index != -1 )
    {
      v20 = &p_m_hAttachEntity[-23].m_Value[9];
      if ( LOBYTE(p_m_hAttachEntity[-20].m_Value[0].m_Index) != 0 )
      {
        LOBYTE(v20[22].m_Index) |= 1u;
      }
      else
      {
        m_Index = (CBaseEdict *)v20[6].m_Index;
        if ( m_Index != nullptr )
          CBaseEdict::StateChanged(this: m_Index, offset: 4 * v17 + 884);
      }
      p_m_hAttachEntity->m_Value[v17].m_Index = -1;
    }
    if ( p_m_nAttachIndex->m_Value[v17] != 0 )
    {
      v22 = &p_m_nAttachIndex[-24].m_Value[9];
      if ( LOBYTE(p_m_nAttachIndex[-21].m_Value[0]) != 0 )
      {
        *((_BYTE *)v22 + 88) |= 1u;
      }
      else
      {
        v23 = (CBaseEdict *)v22[6];
        if ( v23 != nullptr )
          CBaseEdict::StateChanged(this: v23, offset: 4 * v17 + 924);
      }
      p_m_nAttachIndex->m_Value[v17] = 0;
    }
    ++v17;
  }
  while ( v17 < 10 );
  if ( this->m_nHaloIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v24 = this->m_Network.m_pPev;
      if ( v24 != nullptr )
        CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 0x368u);
    }
    this->m_nHaloIndex.m_Value = 0;
  }
  if ( this->m_fHaloScale.m_Value != 10.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v25 = this->m_Network.m_pPev;
      if ( v25 != nullptr )
        CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x3D0u);
    }
    this->m_fHaloScale.m_Value = 10.0;
  }
  if ( this->m_nBeamType.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v26 = this->m_Network.m_pPev;
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: &v26->CBaseEdict, offset: 0x36Cu);
    }
    this->m_nBeamType.m_Value = 0;
  }
  if ( this->m_nBeamFlags.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nBeamFlags.m_Value = 0;
    }
    else
    {
      v27 = this->m_Network.m_pPev;
      if ( v27 != nullptr )
        CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x370u);
      this->m_nBeamFlags.m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E00B0
// Name: private: void CBeam::InputColorRedValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::InputColorRedValue(CBeam *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int v3; // xmm1_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    v3 = 0;
    if ( flVal < 0.0 || (v3 = 1132396544, flVal > 255.0) )
      flVal = *(float *)&v3;
  }
  else
  {
    flVal = 0.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: (int)flVal,
    gVal: this->m_clrRender.m_Value.g,
    bVal: this->m_clrRender.m_Value.b);
}

//------------------------------------------------------------------------------
// Address: 0x100E01F0
// Name: public: static class CBeam __near * CBeam::BeamCreate(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
CBeam *__cdecl CBeam::BeamCreate(const char *pSpriteName, float width)
{
  CBaseEntity *EntityByName; // eax
  CBeam *v3; // esi

  EntityByName = CreateEntityByName(className: "beam", iForceEdictIndex: -1, bNotify: true);
  v3 = (CBeam *)__RTDynamicCast(
                  inptr: EntityByName,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CBeam `RTTI Type Descriptor',
                  isReference: 0);
  if ( v3 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "beam");
  CBeam::BeamInit(this: v3, pSpriteName, width);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101F33D0
// Name: public: void CBeam::SetBeamFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeam::SetBeamFlags(CBeam *this, int flags)
{
  CNetworkVarBase<int,CBeam::NetworkVar_m_nBeamFlags> *p_m_nBeamFlags; // esi
  edict_t *m_pPev; // ecx

  p_m_nBeamFlags = &this->m_nBeamFlags;
  if ( this->m_nBeamFlags.m_Value != flags )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nBeamFlags->m_Value = flags;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_nBeamFlags->m_Value = flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400810
// Name: DT_Beam::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Beam::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Beam::g_SendTable);
  return atexit(func: DT_Beam::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10400830
// Name: DT_Beam::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Beam::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Beam::ignored>();
  DT_Beam::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400840
// Name: CBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBeam>(__formal: nullptr);
  CBeam_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A000
// Name: DT_Beam::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Beam::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Beam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A010
// Name: _ServerClassInit_DT_Beam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Beam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_56;
  for ( i = 24; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A030
// Name: _DataMapInit_CBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_99);
}

} // namespace server
