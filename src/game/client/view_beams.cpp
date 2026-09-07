// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/view_beams.cpp
// Functions: 44
// ============================================================

#include "game\client\view_beams.h"

//------------------------------------------------------------------------------
// Address: 0x1018CD20
// Name: void SetBeamCreationAllowed(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetBeamCreationAllowed(bool state)
{
  g_BeamCreationAllowed = state;
}

//------------------------------------------------------------------------------
// Address: 0x1018CD30
// Name: Noise
// Source: json
//------------------------------------------------------------------------------
void __cdecl Noise(float *noise, int divs, float scale)
{
  int v3; // edi
  int v4; // esi
  float *v5; // ebx

  v3 = divs;
  v4 = divs >> 1;
  if ( divs >= 2 )
  {
    while ( 1 )
    {
      v5 = &noise[v4];
      *v5 = CUniformRandomStream::RandomFloat(this: &beamRandom, a2: -1.0, a3: 1.0) * scale + (noise[v3] + *noise) * 0.5;
      if ( v4 <= 1 )
        break;
      Noise(noise: v5, divs: v4, scale: scale * 0.5);
      v3 = v4;
      v4 >>= 1;
      scale = scale * 0.5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CDE0
// Name: public: virtual void CViewRenderBeams::ClearBeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::ClearBeams(CViewRenderBeams *this)
{
  Beam_t *m_pActiveBeams; // ecx
  Beam_t *next; // edi
  Beam_t *m_pFreeBeams; // ecx
  Beam_t *v5; // edi
  int m_nNumBeamTrails; // eax
  int v7; // ecx
  int v8; // edx

  if ( this->m_pActiveBeams != nullptr )
  {
    do
    {
      m_pActiveBeams = this->m_pActiveBeams;
      next = m_pActiveBeams->next;
      if ( m_pActiveBeams != nullptr )
        ((void (__thiscall *)(Beam_t *, int))m_pActiveBeams->dtr_IHandleEntity)(a1: m_pActiveBeams, a2: 1);
      this->m_pActiveBeams = next;
    }
    while ( next != nullptr );
  }
  if ( this->m_pFreeBeams != nullptr )
  {
    do
    {
      m_pFreeBeams = this->m_pFreeBeams;
      v5 = m_pFreeBeams->next;
      if ( m_pFreeBeams != nullptr )
        ((void (__thiscall *)(Beam_t *, int))m_pFreeBeams->dtr_IHandleEntity)(a1: m_pFreeBeams, a2: 1);
      this->m_pFreeBeams = v5;
    }
    while ( v5 != nullptr );
  }
  m_nNumBeamTrails = this->m_nNumBeamTrails;
  this->m_nBeamFreeListLength = 0;
  if ( m_nNumBeamTrails != 0 )
  {
    this->m_pFreeTrails = this->m_pBeamTrails;
    v7 = 0;
    this->m_pActiveTrails = nullptr;
    if ( m_nNumBeamTrails > 0 )
    {
      v8 = 0;
      do
      {
        this->m_pBeamTrails[v8].next = &this->m_pBeamTrails[v8 + 1];
        ++v7;
        ++v8;
      }
      while ( v7 < this->m_nNumBeamTrails );
    }
    this->m_pBeamTrails[this->m_nNumBeamTrails - 1].next = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CE80
// Name: public: virtual void CViewRenderBeams::ShutdownBeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::ShutdownBeams(CViewRenderBeams *this)
{
  if ( this->m_pBeamTrails != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_pBeamTrails);
    this->m_pActiveTrails = nullptr;
    this->m_pBeamTrails = nullptr;
    this->m_pFreeTrails = nullptr;
    this->m_nNumBeamTrails = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CEB0
// Name: private: void CViewRenderBeams::FreeDeadTrails(struct BeamTrail_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::FreeDeadTrails(CViewRenderBeams *this, BeamTrail_t **trail)
{
  BeamTrail_t *i; // eax
  BeamTrail_t *j; // edx
  BeamTrail_t *k; // eax

  for ( i = *trail; *trail != nullptr; i = *trail )
  {
    if ( *(float *)(gpGlobals.m_Index + 12) <= i->die )
      break;
    *trail = i->next;
    i->next = this->m_pFreeTrails;
    this->m_pFreeTrails = i;
  }
  for ( j = *trail; j != nullptr; j = j->next )
  {
    for ( k = j->next; j->next != nullptr; k = j->next )
    {
      if ( *(float *)(gpGlobals.m_Index + 12) <= k->die )
        break;
      j->next = k->next;
      k->next = this->m_pFreeTrails;
      this->m_pFreeTrails = k;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CF30
// Name: private: void CViewRenderBeams::DrawTesla(class Beam_t __near *,int,int,float __near *,struct model_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::DrawTesla(
        CViewRenderBeams *this,
        Beam_t *pbeam,
        int frame,
        int rendermode,
        float *color,
        const struct model_t *sprite,
        float flHDRColorScale)
{
  __int64 v7; // [esp+0h] [ebp-38h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  HIDWORD(v7) = rendermode;
  *(float *)&v7 = (float)frame;
  DrawTeslaSegs(
    a1: (int)&savedregs,
    noise_divisions: 128,
    prgNoise: pbeam->rgNoise,
    spritemodel: sprite,
    frame: v7,
    source: pbeam->attachment,
    delta: &pbeam->delta,
    startWidth: pbeam->width,
    endWidth: pbeam->endWidth,
    scale: pbeam->amplitude,
    freq: pbeam->freq,
    speed: pbeam->speed,
    segments: pbeam->segments,
    flags: pbeam->flags,
    color,
    fadeLength: pbeam->fadeLength,
    flHDRColorScale);
}

//------------------------------------------------------------------------------
// Address: 0x1018CFE0
// Name: bool ComputeBeamEntPosition(class C_BaseEntity __near *,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ComputeBeamEntPosition(
        C_BaseAnimating *pEnt,
        int nAttachment,
        bool bInterpretAttachmentIndexAsHitboxIndex,
        Vector *pt)
{
  C_BaseEntity_vtbl *v6; // eax
  Vector *v7; // esi
  int v8; // eax
  C_BaseAnimating *v9; // esi
  IVModelInfoClient_vtbl *v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // esi
  int v14; // esi
  const Vector *v15; // eax
  matrix3x4_t *hitboxbones[256]; // [esp+4h] [ebp-424h] BYREF
  Vector vecLocalClosestPt; // [esp+404h] [ebp-24h] BYREF
  Vector vecLocalViewPt; // [esp+410h] [ebp-18h] BYREF
  Vector vecViewPt; // [esp+41Ch] [ebp-Ch] BYREF
  C_BaseAnimating *pAnimating; // [esp+430h] [ebp+8h]

  if ( pEnt == nullptr )
    return 0;
  v6 = (C_BaseEntity_vtbl *)pEnt->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( bInterpretAttachmentIndexAsHitboxIndex )
  {
    v8 = (int)v6->GetBaseAnimating(this: pEnt);
    v9 = (C_BaseAnimating *)v8;
    pAnimating = (C_BaseAnimating *)v8;
    if ( v8 != 0 )
    {
      v10 = modelinfo->__vftable;
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)(v8 + 4) + 32))(a1: v8 + 4);
      v12 = (int)v10->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v11);
      if ( v12 != 0 )
      {
        v13 = v12 + *(_DWORD *)(v12 + 176) + 12 * C_BaseAnimating::GetHitboxSet(this: v9);
        if ( v13 != 0
          && *(_DWORD *)(v13 + 4) >= nAttachment
          && nAttachment > 0
          && C_BaseAnimating::HitboxToWorldTransforms(this: pAnimating, pHitboxToWorld: hitboxbones) != 0 )
        {
          v14 = *(_DWORD *)(v13 + 8) + 68 * nAttachment + v13 - 68;
          vecViewPt = *MainViewOrigin(nSlot: 0);
          VectorITransform(in1: &vecViewPt.x, in2: hitboxbones[*(_DWORD *)v14], out: &vecLocalViewPt.x);
          CalcClosestPointOnAABB(
            mins: (const Vector *)(v14 + 8),
            maxs: (const Vector *)(v14 + 20),
            point: &vecLocalViewPt,
            closestOut: &vecLocalClosestPt);
          VectorTransform(in1: &vecLocalClosestPt.x, in2: hitboxbones[*(_DWORD *)v14], out: &pt->x);
          return 1;
        }
      }
    }
    v7 = pt;
  }
  else
  {
    v7 = pt;
    if ( v6->GetAttachment(this: pEnt, a2: nAttachment, a3: pt) )
      return 1;
  }
  if ( pEnt->IsPlayer(this: pEnt) )
    v15 = pEnt->WorldSpaceCenter(this: pEnt);
  else
    v15 = pEnt->GetRenderOrigin(this: &pEnt->IClientRenderable);
  v7->x = v15->x;
  v7->y = v15->y;
  v7->z = v15->z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018D160
// Name: public: virtual class Vector const __near & Beam_t::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall Beam_t::GetRenderOrigin(Beam_t *this)
{
  Beam_t *next; // eax

  next = this->next;
  if ( next != (Beam_t *)5 && next != (Beam_t *)7 )
    return (const Vector *)&this->numAttachments;
  if ( (_S6_46 & 1) == 0 )
    _S6_46 |= 1u;
  org.x = (float)(this->attachment[9].z * 0.5) + *(float *)&this->numAttachments;
  org.y = (float)(this->delta.x * 0.5) + this->attachment[0].x;
  org.z = (float)(this->delta.y * 0.5) + this->attachment[0].y;
  return &org;
}

//------------------------------------------------------------------------------
// Address: 0x1018D1E0
// Name: public: virtual struct matrix3x4_t const __near & Beam_t::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall Beam_t::RenderableToWorldTransform(Beam_t *this)
{
  const Vector *v2; // eax

  if ( (_S7_18 & 1) == 0 )
    _S7_18 |= 1u;
  SetIdentityMatrix(matrix: &mat_1);
  v2 = (const Vector *)((int (__thiscall *)(Beam_t *))this->SetRefEHandle)(a1: this);
  MatrixSetColumn(in: v2, column: 3, out: &mat_1);
  return &mat_1;
}

//------------------------------------------------------------------------------
// Address: 0x1018D230
// Name: public: virtual void Beam_t::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Beam_t::GetRenderBounds(Beam_t *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_hRenderHandle;
  *maxs = *(Vector *)&this->m_Mins.z;
}

//------------------------------------------------------------------------------
// Address: 0x1018D260
// Name: public: void Beam_t::ComputeBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Beam_t::ComputeBounds(Beam_t *this@<ecx>, int a2@<esi>)
{
  int v3; // ecx
  float *p_z; // eax
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float y; // xmm5_4
  float x; // xmm3_4
  float v11; // xmm3_4
  int z; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  int v18; // eax
  __int64 v19; // xmm0_8
  BeamTrail_t *trail; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  __int64 i; // [esp-Ch] [ebp-18h]
  float v29; // [esp-4h] [ebp-10h]

  switch ( this->type )
  {
    case 2:
    case 3:
      z = (int)this->delta.z;
      v13 = (float)-z;
      goto LABEL_19;
    case 5:
    case 7:
      z = (int)(float)(fsqrt(
                         (float)((float)(this->delta.x * this->delta.x) + (float)(this->delta.y * this->delta.y))
                       + (float)(this->delta.z * this->delta.z))
                     * 0.5);
      v13 = (float)-z;
LABEL_19:
      this->m_Mins.x = v13;
      this->m_Mins.y = v13;
      this->m_Mins.z = v13;
      v14 = (float)z;
      this->m_Maxs.x = (float)z;
      this->m_Maxs.y = (float)z;
      goto LABEL_30;
    case 6:
      this->m_Mins.x = 0.0;
      this->m_Mins.y = 0.0;
      this->m_Mins.z = 0.0;
      v3 = 1;
      this->m_Maxs.x = 0.0;
      this->m_Maxs.y = 0.0;
      this->m_Maxs.z = 0.0;
      if ( this->numAttachments > 1 )
      {
        p_z = &this->attachment[1].z;
        do
        {
          v5 = *p_z - this->attachment[0].z;
          v6 = this->m_Mins.z;
          v7 = *(p_z - 2) - this->attachment[0].x;
          v8 = *(p_z - 1) - this->attachment[0].y;
          if ( v5 <= v6 )
            v6 = *p_z - this->attachment[0].z;
          y = this->m_Mins.y;
          if ( v8 <= y )
            y = *(p_z - 1) - this->attachment[0].y;
          x = this->m_Mins.x;
          if ( v7 <= x )
            x = *(p_z - 2) - this->attachment[0].x;
          this->m_Mins.x = x;
          this->m_Mins.y = y;
          this->m_Mins.z = v6;
          if ( this->m_Maxs.z > v5 )
            v5 = this->m_Maxs.z;
          if ( this->m_Maxs.y > v8 )
            v8 = this->m_Maxs.y;
          v11 = this->m_Maxs.x;
          if ( v11 <= v7 )
            v11 = v7;
          ++v3;
          this->m_Maxs.x = v11;
          this->m_Maxs.y = v8;
          this->m_Maxs.z = v5;
          p_z += 3;
        }
        while ( v3 < this->numAttachments );
      }
      goto LABEL_31;
    default:
      v15 = this->delta.x;
      v14 = 0.0;
      if ( v15 <= 0.0 )
      {
        this->m_Mins.x = v15;
        this->m_Maxs.x = 0.0;
      }
      else
      {
        this->m_Mins.x = 0.0;
        this->m_Maxs.x = v15;
      }
      v16 = this->delta.y;
      if ( v16 <= 0.0 )
      {
        this->m_Mins.y = v16;
        this->m_Maxs.y = 0.0;
      }
      else
      {
        this->m_Mins.y = 0.0;
        this->m_Maxs.y = v16;
      }
      v17 = this->delta.z;
      if ( v17 <= 0.0 )
      {
        this->m_Mins.z = v17;
LABEL_30:
        this->m_Maxs.z = v14;
      }
      else
      {
        this->m_Mins.z = 0.0;
        this->m_Maxs.z = v17;
      }
LABEL_31:
      v18 = ((int (__thiscall *)(IClientRenderable *, int))this->GetRenderOrigin)(a1: &this->IClientRenderable, a2);
      v19 = *(_QWORD *)v18;
      v29 = *(float *)(v18 + 8);
      trail = this->trail;
      for ( i = v19; trail != nullptr; this->m_Maxs.z = v23 )
      {
        v21 = this->m_Mins.z;
        v22 = trail->org.x - *(float *)&i;
        v23 = trail->org.z - v29;
        v24 = trail->org.y - *((float *)&i + 1);
        if ( v23 <= v21 )
          v21 = trail->org.z - v29;
        v25 = this->m_Mins.y;
        if ( v24 <= v25 )
          v25 = trail->org.y - *((float *)&v19 + 1);
        v26 = this->m_Mins.x;
        if ( v22 <= v26 )
          v26 = trail->org.x - *(float *)&i;
        this->m_Mins.x = v26;
        this->m_Mins.y = v25;
        this->m_Mins.z = v21;
        if ( this->m_Maxs.z > v23 )
          v23 = this->m_Maxs.z;
        if ( this->m_Maxs.y > v24 )
          v24 = this->m_Maxs.y;
        if ( this->m_Maxs.x > v22 )
          v22 = this->m_Maxs.x;
        trail = trail->next;
        this->m_Maxs.x = v22;
        this->m_Maxs.y = v24;
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D560
// Name: private: void CViewRenderBeams::BeamFree(class Beam_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::BeamFree(CViewRenderBeams *this, Beam_t *pBeam)
{
  int m_nBeamFreeListLength; // eax
  Beam_t *m_pFreeBeams; // edx

  CViewRenderBeams::FreeDeadTrails(this, trail: &pBeam->trail);
  ((void (__stdcall *)(_DWORD))g_pClientLeafSystem->RemoveRenderable)(a1: pBeam->m_hRenderHandle);
  pBeam->m_Mins.x = 0.0;
  pBeam->m_Mins.y = 0.0;
  pBeam->m_Mins.z = 0.0;
  pBeam->m_Maxs.x = 0.0;
  pBeam->m_Maxs.y = 0.0;
  pBeam->m_Maxs.z = 0.0;
  pBeam->type = 0;
  pBeam->flags = 0;
  pBeam->trail = nullptr;
  pBeam->m_hRenderHandle = -1;
  pBeam->m_bCalculatedNoise = false;
  pBeam->m_queryHandleHalo = nullptr;
  pBeam->m_flHDRColorScale = 1.0;
  m_nBeamFreeListLength = this->m_nBeamFreeListLength;
  if ( m_nBeamFreeListLength >= 32 )
  {
    ((void (__thiscall *)(Beam_t *, int))pBeam->dtr_IHandleEntity)(a1: pBeam, a2: 1);
  }
  else
  {
    m_pFreeBeams = this->m_pFreeBeams;
    this->m_nBeamFreeListLength = m_nBeamFreeListLength + 1;
    pBeam->next = m_pFreeBeams;
    this->m_pFreeBeams = pBeam;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D610
// Name: private: void CViewRenderBeams::SetupBeam(class Beam_t __near *,struct BeamInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRenderBeams::SetupBeam(
        CViewRenderBeams *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Beam_t *pBeam,
        const BeamInfo_t *beamInfo)
{
  const struct model_t *v5; // eax
  int m_nSegments; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4

  v5 = (const struct model_t *)((int (__thiscall *)(IVModelInfoClient *, int, int, int))modelinfo->GetModel)(
                                 a1: modelinfo,
                                 a2: beamInfo->m_nModelIndex,
                                 a3: a2,
                                 a4: a3);
  if ( v5 != nullptr )
  {
    pBeam->type = beamInfo->m_nType < 0 ? 0 : beamInfo->m_nType;
    pBeam->modelIndex = beamInfo->m_nModelIndex;
    pBeam->haloIndex = beamInfo->m_nHaloIndex;
    pBeam->haloScale = beamInfo->m_flHaloScale;
    *(_QWORD *)&pBeam->frameRate = 0;
    pBeam->frameCount = modelinfo->GetModelFrameCount(this: modelinfo, a2: v5);
    pBeam->freq = *(float *)(gpGlobals.m_Index + 12) * beamInfo->m_flSpeed;
    pBeam->die = *(float *)(gpGlobals.m_Index + 12) + beamInfo->m_flLife;
    pBeam->width = beamInfo->m_flWidth;
    pBeam->endWidth = beamInfo->m_flEndWidth;
    pBeam->fadeLength = beamInfo->m_flFadeLength;
    pBeam->amplitude = beamInfo->m_flAmplitude;
    pBeam->brightness = beamInfo->m_flBrightness;
    pBeam->speed = beamInfo->m_flSpeed;
    pBeam->life = beamInfo->m_flLife;
    pBeam->flags = beamInfo->m_nFlags;
    qmemcpy((void *)pBeam->attachment, &beamInfo->m_vecStart, 24);
    pBeam->delta.x = beamInfo->m_vecEnd.x - beamInfo->m_vecStart.x;
    pBeam->delta.y = beamInfo->m_vecEnd.y - beamInfo->m_vecStart.y;
    pBeam->delta.z = beamInfo->m_vecEnd.z - beamInfo->m_vecStart.z;
    m_nSegments = beamInfo->m_nSegments;
    if ( m_nSegments == -1 )
    {
      v7 = pBeam->delta.y * pBeam->delta.y;
      v8 = pBeam->delta.x * pBeam->delta.x;
      v9 = pBeam->delta.z * pBeam->delta.z;
      if ( pBeam->amplitude < 0.5 )
        pBeam->segments = (int)(fsqrt((float)(v7 + v9) + v8) * 0.075 + 3.0);
      else
        pBeam->segments = (int)(float)((float)(fsqrt((float)(v8 + v7) + v9) * 0.25) + 3.0);
    }
    else
    {
      pBeam->segments = m_nSegments;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D850
// Name: private: int CViewRenderBeams::CullBeam(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
BOOL __thiscall CViewRenderBeams::CullBeam(CViewRenderBeams *this, const Vector *start, const Vector *end, int pvsOnly)
{
  float x; // xmm0_4
  float v5; // xmm2_4
  float y; // xmm0_4
  float v7; // xmm2_4
  float z; // xmm0_4
  float v9; // xmm2_4
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  x = start->x;
  if ( end->x <= start->x )
  {
    v5 = end->x;
  }
  else
  {
    v5 = start->x;
    x = end->x;
  }
  maxs.x = x;
  mins.x = v5;
  if ( v5 == x )
    maxs.x = x + 1.0;
  y = start->y;
  if ( end->y <= y )
  {
    v7 = end->y;
  }
  else
  {
    v7 = start->y;
    y = end->y;
  }
  maxs.y = y;
  mins.y = v7;
  if ( v7 == y )
    maxs.y = y + 1.0;
  z = start->z;
  if ( end->z <= z )
  {
    v9 = end->z;
  }
  else
  {
    v9 = start->z;
    z = end->z;
  }
  maxs.z = z;
  mins.z = v9;
  if ( v9 == z )
    maxs.z = z + 1.0;
  return engine->IsBoxVisible(this: engine, a2: &mins, a3: &maxs) != 0
      && (pvsOnly != 0 || !engine->CullBox(this: engine, a2: &mins, a3: &maxs));
}

//------------------------------------------------------------------------------
// Address: 0x1018D960
// Name: public: virtual void CViewRenderBeams::CreateBeamEnts(int,int,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamEnts(
        CViewRenderBeams *this,
        int startEnt,
        int endEnt,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b,
        int type)
{
  CViewRenderBeams_vtbl *v20; // eax
  Beam_t *(__thiscall *CreateBeamEnts_2)(struct CViewRenderBeams *, BeamInfo_t *); // edx
  BeamInfo_t beamInfo; // [esp+8h] [ebp-90h] BYREF

  beamInfo.m_nSegments = -1;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nFlags = 0;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nType = type;
  beamInfo.m_nStartAttachment = (startEnt >> 12) & 0xF;
  beamInfo.m_pStartEnt = CClientEntityList::GetBaseEntity(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           entnum: startEnt & 0xFFF);
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_pEndEnt = CClientEntityList::GetBaseEntity(
                         this: (CClientEntityList *)cl_entitylist.m_Index,
                         entnum: endEnt & 0xFFF);
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nHaloIndex = haloIndex;
  beamInfo.m_flRed = r;
  beamInfo.m_nModelIndex = modelIndex;
  v20 = this->__vftable;
  beamInfo.m_nStartFrame = startFrame;
  CreateBeamEnts_2 = v20->CreateBeamEnts_2;
  beamInfo.m_flGreen = g;
  beamInfo.m_nEndAttachment = (endEnt >> 12) & 0xF;
  beamInfo.m_flBlue = b;
  CreateBeamEnts_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018DA90
// Name: public: virtual void CViewRenderBeams::CreateBeamEntPoint(int,class Vector const __near *,int,class Vector const __near *,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamEntPoint(
        CViewRenderBeams *this,
        int nStartEntity,
        const Vector *pStart,
        int nEndEntity,
        const Vector *pEnd,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b)
{
  Vector *v21; // eax
  Vector *v22; // eax
  Beam_t *(__thiscall *CreateBeamEntPoint_2)(struct CViewRenderBeams *, BeamInfo_t *); // edx
  BeamInfo_t beamInfo; // [esp+Ch] [ebp-90h] BYREF

  beamInfo.m_nType = 0;
  beamInfo.m_nSegments = -1;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nModelIndex = -1;
  beamInfo.m_nHaloIndex = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nFlags = 0;
  if ( nStartEntity > 0 )
  {
    beamInfo.m_pStartEnt = CClientEntityList::GetBaseEntity(
                             this: (CClientEntityList *)cl_entitylist.m_Index,
                             entnum: nStartEntity & 0xFFF);
    beamInfo.m_nStartAttachment = (nStartEntity >> 12) & 0xF;
    if ( beamInfo.m_pStartEnt == nullptr )
      return;
  }
  else
  {
    v21 = pStart;
    if ( pStart == nullptr )
      v21 = &vec3_origin;
    beamInfo.m_vecStart = *v21;
    beamInfo.m_pStartEnt = nullptr;
  }
  if ( nEndEntity > 0 )
  {
    beamInfo.m_pEndEnt = CClientEntityList::GetBaseEntity(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           entnum: nEndEntity & 0xFFF);
    beamInfo.m_nEndAttachment = (nEndEntity >> 12) & 0xF;
    if ( beamInfo.m_pEndEnt == nullptr )
      return;
  }
  else
  {
    v22 = pEnd;
    if ( pEnd == nullptr )
      v22 = &vec3_origin;
    beamInfo.m_vecEnd = *v22;
    beamInfo.m_pEndEnt = nullptr;
  }
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nModelIndex = modelIndex;
  CreateBeamEntPoint_2 = this->CreateBeamEntPoint_2;
  beamInfo.m_flRed = r;
  beamInfo.m_nHaloIndex = haloIndex;
  beamInfo.m_nStartFrame = startFrame;
  beamInfo.m_flGreen = g;
  beamInfo.m_flBlue = b;
  CreateBeamEntPoint_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018DC30
// Name: public: virtual void CViewRenderBeams::CreateBeamPoints(class Vector __near &,class Vector __near &,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamPoints(
        CViewRenderBeams *this,
        Vector *start,
        Vector *end,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b)
{
  Beam_t *(__thiscall *CreateBeamPoints_2)(struct CViewRenderBeams *, BeamInfo_t *); // edx
  BeamInfo_t beamInfo; // [esp+0h] [ebp-90h] BYREF

  beamInfo.m_nType = 0;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nFlags = 0;
  beamInfo.m_vecStart = *start;
  beamInfo.m_vecEnd = *end;
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_nModelIndex = modelIndex;
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nHaloIndex = haloIndex;
  CreateBeamPoints_2 = this->CreateBeamPoints_2;
  beamInfo.m_flRed = r;
  beamInfo.m_nStartFrame = startFrame;
  beamInfo.m_flGreen = g;
  beamInfo.m_nSegments = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_flBlue = b;
  CreateBeamPoints_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018DD40
// Name: public: virtual void CViewRenderBeams::CreateBeamCirclePoints(int,class Vector __near &,class Vector __near &,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamCirclePoints(
        CViewRenderBeams *this,
        int type,
        Vector *start,
        Vector *end,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b)
{
  Beam_t *(__thiscall *CreateBeamCirclePoints_2)(struct CViewRenderBeams *, BeamInfo_t *); // eax
  BeamInfo_t beamInfo; // [esp+0h] [ebp-90h] BYREF

  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nFlags = 0;
  beamInfo.m_nType = type;
  beamInfo.m_vecStart = *start;
  beamInfo.m_vecEnd = *end;
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_nModelIndex = modelIndex;
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nHaloIndex = haloIndex;
  CreateBeamCirclePoints_2 = this->CreateBeamCirclePoints_2;
  beamInfo.m_flRed = r;
  beamInfo.m_nStartFrame = startFrame;
  beamInfo.m_flGreen = g;
  beamInfo.m_nSegments = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_flBlue = b;
  CreateBeamCirclePoints_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018DE50
// Name: public: virtual void CViewRenderBeams::CreateBeamFollow(int,int,int,float,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamFollow(
        CViewRenderBeams *this,
        int startEnt,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        unsigned int width,
        float endWidth,
        float fadeLength,
        float r,
        float g,
        float b,
        float brightness)
{
  CViewRenderBeams_vtbl *v14; // eax
  Beam_t *(__thiscall *CreateBeamFollow_2)(struct CViewRenderBeams *, BeamInfo_t *); // edx
  BeamInfo_t beamInfo; // [esp+8h] [ebp-90h] BYREF

  beamInfo.m_nType = 0;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nFlags = 0;
  beamInfo.m_nSegments = -1;
  beamInfo.m_nHaloIndex = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_nModelIndex = modelIndex;
  beamInfo.m_flRed = r;
  beamInfo.m_pStartEnt = CClientEntityList::GetBaseEntity(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           entnum: startEnt & 0xFFF);
  v14 = this->__vftable;
  beamInfo.m_nHaloIndex = haloIndex;
  CreateBeamFollow_2 = v14->CreateBeamFollow_2;
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flGreen = g;
  beamInfo.m_nStartAttachment = (startEnt >> 12) & 0xF;
  *(_QWORD *)&beamInfo.m_flLife = __PAIR64__(width, LODWORD(life));
  beamInfo.m_flBlue = b;
  beamInfo.m_flAmplitude = life;
  CreateBeamFollow_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018DF30
// Name: public: virtual void CViewRenderBeams::CreateBeamRingPoint(class Vector const __near &,float,float,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamRingPoint(
        CViewRenderBeams *this,
        const Vector *center,
        float start_radius,
        float end_radius,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b,
        int nFlags)
{
  float y; // xmm0_4
  Beam_t *(__thiscall *CreateBeamRingPoint_2)(struct CViewRenderBeams *, BeamInfo_t *); // eax
  BeamInfo_t beamInfo; // [esp+0h] [ebp-90h] BYREF

  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nType = 0;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_flRed = r;
  beamInfo.m_nModelIndex = modelIndex;
  beamInfo.m_flGreen = g;
  beamInfo.m_nStartFrame = startFrame;
  beamInfo.m_flBlue = b;
  beamInfo.m_vecCenter.x = center->x;
  y = center->y;
  beamInfo.m_nHaloIndex = haloIndex;
  beamInfo.m_vecCenter.y = y;
  CreateBeamRingPoint_2 = this->CreateBeamRingPoint_2;
  beamInfo.m_vecCenter.z = center->z;
  beamInfo.m_nFlags = nFlags;
  beamInfo.m_flStartRadius = start_radius;
  beamInfo.m_nSegments = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_flEndRadius = end_radius;
  CreateBeamRingPoint_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018E030
// Name: public: virtual void CViewRenderBeams::CreateBeamRing(int,int,int,int,float,float,float,float,float,float,float,float,int,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::CreateBeamRing(
        CViewRenderBeams *this,
        int startEnt,
        int endEnt,
        int modelIndex,
        int haloIndex,
        float haloScale,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float amplitude,
        float brightness,
        float speed,
        int startFrame,
        float framerate,
        float r,
        float g,
        float b,
        int flags)
{
  CViewRenderBeams_vtbl *v20; // eax
  Beam_t *(__thiscall *CreateBeamRing_2)(struct CViewRenderBeams *, BeamInfo_t *); // edx
  BeamInfo_t beamInfo; // [esp+8h] [ebp-90h] BYREF

  beamInfo.m_nType = 0;
  beamInfo.m_pszModelName = nullptr;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nFlags = 0;
  beamInfo.m_nSegments = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nStartAttachment = (startEnt >> 12) & 0xF;
  beamInfo.m_pStartEnt = CClientEntityList::GetBaseEntity(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           entnum: startEnt & 0xFFF);
  beamInfo.m_flHaloScale = haloScale;
  beamInfo.m_flLife = life;
  beamInfo.m_flWidth = width;
  beamInfo.m_flEndWidth = endWidth;
  beamInfo.m_flFadeLength = fadeLength;
  beamInfo.m_flAmplitude = amplitude;
  beamInfo.m_flBrightness = brightness;
  beamInfo.m_flSpeed = speed;
  beamInfo.m_pEndEnt = CClientEntityList::GetBaseEntity(
                         this: (CClientEntityList *)cl_entitylist.m_Index,
                         entnum: endEnt & 0xFFF);
  beamInfo.m_flFrameRate = framerate;
  beamInfo.m_nModelIndex = modelIndex;
  beamInfo.m_nStartFrame = startFrame;
  beamInfo.m_flRed = r;
  beamInfo.m_nHaloIndex = haloIndex;
  v20 = this->__vftable;
  beamInfo.m_flGreen = g;
  beamInfo.m_nFlags = flags;
  CreateBeamRing_2 = v20->CreateBeamRing_2;
  beamInfo.m_nEndAttachment = (endEnt >> 12) & 0xF;
  beamInfo.m_flBlue = b;
  CreateBeamRing_2(this, a2: &beamInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018E160
// Name: private: void CViewRenderBeams::DrawBeamFollow(struct model_t const __near *,class Beam_t __near *,int,int,float,float const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRenderBeams::DrawBeamFollow(
        CViewRenderBeams *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const struct model_t *pSprite,
        Beam_t *pbeam,
        int frame,
        RenderMode_t rendermode,
        float frametime,
        float *color,
        float flHDRColorScale)
{
  int v11; // ecx
  BeamTrail_t *trail; // edi
  BeamTrail_t *v13; // eax
  float v14; // xmm0_4
  float x; // ecx
  float v16; // esi
  float *i; // eax
  Vector v19; // [esp+58h] [ebp-34h] BYREF
  Vector screen; // [esp+64h] [ebp-28h] BYREF
  Vector screenLast; // [esp+70h] [ebp-1Ch] BYREF
  Vector delta; // [esp+7Ch] [ebp-10h]
  int v23; // [esp+88h] [ebp-4h] BYREF
  float retaddr; // [esp+8Ch] [ebp+0h]

  delta.y = a2;
  delta.z = retaddr;
  LODWORD(delta.x) = &pbeam->trail;
  CViewRenderBeams::FreeDeadTrails(this, trail: &pbeam->trail);
  trail = pbeam->trail;
  v13 = nullptr;
  v14 = 0.0;
  if ( (pbeam->flags & 1) != 0 )
  {
    if ( trail == nullptr )
    {
      v13 = *(BeamTrail_t **)(v11 + 24);
      if ( v13 == nullptr )
        return;
      v14 = 0.0;
      goto LABEL_8;
    }
    screenLast.x = trail->org.x - pbeam->attachment[0].x;
    screenLast.y = trail->org.y - pbeam->attachment[0].y;
    screenLast.z = trail->org.z - pbeam->attachment[0].z;
    v14 = fsqrt(
            (float)((float)(screenLast.y * screenLast.y) + (float)(screenLast.z * screenLast.z))
          + (float)(screenLast.x * screenLast.x));
    if ( v14 >= 32.0 && *(_DWORD *)(v11 + 24) != 0 )
    {
      v13 = *(BeamTrail_t **)(v11 + 24);
LABEL_8:
      *(_DWORD *)(v11 + 24) = v13->next;
      v13->org = pbeam->attachment[0];
      x = delta.x;
      v13->die = *(float *)(gpGlobals.m_Index + 12) + pbeam->amplitude;
      v13->vel = vec3_origin;
      pbeam->die = *(float *)(gpGlobals.m_Index + 12) + pbeam->amplitude;
      v13->next = trail;
      *(_DWORD *)LODWORD(x) = v13;
      trail = v13;
    }
  }
  if ( trail == nullptr )
    return;
  if ( v13 != nullptr || v14 == 0.0 )
  {
    if ( trail->next == nullptr )
      return;
    screenLast = trail->org;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int))debugoverlay->ScreenPosition_2)(
      a1: debugoverlay,
      a2: &trail->org,
      a3: &screen,
      a4: a3,
      a5: a4);
  }
  else
  {
    screenLast = pbeam->attachment[0];
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int))debugoverlay->ScreenPosition_2)(
      a1: debugoverlay,
      a2: pbeam->attachment,
      a3: &screen,
      a4: a3,
      a5: a4);
    trail = (BeamTrail_t *)((char *)trail + 8);
  }
  ((void (__thiscall *)(IVDebugOverlay *))debugoverlay->ScreenPosition_2)(a1: debugoverlay);
  v16 = delta.x;
  DrawBeamFollow(
    a1: (int)&v23,
    a2: (int)trail,
    spritemodel: pSprite,
    pHead: *(BeamTrail_t **)LODWORD(delta.x),
    frame,
    rendermode,
    delta: &screenLast,
    screen: &v19,
    screenLast: &screen,
    die: pbeam->die,
    source: pbeam->attachment,
    flags: pbeam->flags,
    width: pbeam->width,
    amplitude: pbeam->amplitude,
    freq: pbeam->freq,
    color,
    flHDRColorScale: 1.0);
  for ( i = *(float **)LODWORD(v16); i != nullptr; i = *(float **)i )
  {
    i[2] = (float)(i[5] * frametime) + i[2];
    i[3] = (float)(i[6] * frametime) + i[3];
    i[4] = (float)(i[7] * frametime) + i[4];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018E430
// Name: private: void CViewRenderBeams::DrawBeamWithHalo(class Beam_t __near *,int,int,float __near *,float __near *,struct model_t const __near *,struct model_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CViewRenderBeams::DrawBeamWithHalo(
        CViewRenderBeams *this@<ecx>,
        int a2@<ebp>,
        Beam_t *pbeam,
        int frame,
        RenderMode_t rendermode,
        float *color,
        float *srcColor,
        const struct model_t *sprite,
        const struct model_t *halosprite,
        float flHDRColorScale)
{
  Vector *attachment; // edi
  const Vector *v11; // eax
  float v12; // xmm3_4
  unsigned int v13; // xmm1_4
  unsigned int v14; // xmm2_4
  const Vector *v15; // eax
  const Vector *v16; // eax
  float startWidth; // xmm2_4
  __int128 v18; // xmm0
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int flags; // eax
  float z; // ecx
  int *m_queryHandleHalo; // edx
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float endWidth; // [esp+14h] [ebp-C0h]
  float endWidtha; // [esp+14h] [ebp-C0h]
  float scale; // [esp+18h] [ebp-BCh]
  float scalea; // [esp+18h] [ebp-BCh]
  float freq; // [esp+1Ch] [ebp-B8h]
  float freqa; // [esp+1Ch] [ebp-B8h]
  float speed; // [esp+20h] [ebp-B4h]
  float speeda; // [esp+20h] [ebp-B4h]
  int segments; // [esp+24h] [ebp-B0h]
  float fadeLength; // [esp+30h] [ebp-A4h]
  _DWORD v40[3]; // [esp+40h] [ebp-94h] BYREF
  pixelvis_queryparams_t params; // [esp+4Ch] [ebp-88h] BYREF
  float scaleColor[4]; // [esp+68h] [ebp-6Ch] BYREF
  __int128 out; // [esp+78h] [ebp-5Ch] OVERLAPPED BYREF
  __int64 haloColor_8; // [esp+90h] [ebp-44h] OVERLAPPED BYREF
  float v45; // [esp+98h] [ebp-3Ch]
  Vector vSource; // [esp+9Ch] [ebp-38h] BYREF
  Vector beamDir; // [esp+A8h] [ebp-2Ch] BYREF
  Vector localDir; // [esp+B4h] [ebp-20h]
  float distThreshold; // [esp+C0h] [ebp-14h]
  float haloFractionVisible; // [esp+C4h] [ebp-10h] BYREF
  int v51; // [esp+C8h] [ebp-Ch] BYREF
  float fade; // [esp+CCh] [ebp-8h]
  float distToLine; // [esp+D0h] [ebp-4h] BYREF
  float retaddr; // [esp+D4h] [ebp+0h]

  v51 = a2;
  fade = retaddr;
  attachment = pbeam->attachment;
  vSource.x = pbeam->attachment[1].x - pbeam->attachment[0].x;
  vSource.y = pbeam->attachment[1].y - pbeam->attachment[0].y;
  vSource.z = pbeam->attachment[1].z - pbeam->attachment[0].z;
  VectorNormalize(vec: &vSource);
  v11 = CurrentViewOrigin();
  beamDir.x = v11->x - pbeam->attachment[0].x;
  beamDir.y = v11->y - pbeam->attachment[0].y;
  beamDir.z = v11->z - pbeam->attachment[0].z;
  VectorNormalize(vec: &beamDir);
  v12 = (float)((float)(beamDir.y * vSource.y) + (float)(beamDir.x * vSource.x)) + (float)(beamDir.z * vSource.z);
  if ( v12 >= 0.0 )
    distThreshold = v12 * 2.0;
  else
    distThreshold = 0.0;
  *(float *)&v13 = (float)(vSource.y * 2.0) + pbeam->attachment[0].y;
  *(float *)&v14 = (float)(vSource.z * 2.0) + pbeam->attachment[0].z;
  *((float *)&out + 1) = (float)(vSource.x * 2.0) + attachment->x;
  *((_QWORD *)&out + 1) = __PAIR64__(v14, v13);
  v15 = CurrentViewOrigin();
  CalcClosestPointOnLine(
    P: v15,
    vLineA: attachment,
    vLineB: (const Vector *)((char *)&out + 4),
    vClosest: (Vector *)&scaleColor[1],
    outT: &haloFractionVisible);
  v16 = CurrentViewOrigin();
  startWidth = pbeam->width;
  v18 = 0;
  *(float *)&v18 = fsqrt(
                     (float)((float)((float)(v16->y - scaleColor[2]) * (float)(v16->y - scaleColor[2]))
                           + (float)((float)(v16->z - scaleColor[3]) * (float)(v16->z - scaleColor[3])))
                   + (float)((float)(v16->x - scaleColor[1]) * (float)(v16->x - scaleColor[1])));
  out = v18;
  haloFractionVisible = *(float *)&v18;
  v19 = startWidth * 4.0;
  v20 = 1.0;
  localDir.x = startWidth * 4.0;
  if ( (float)(startWidth * 4.0) > *(float *)&out )
  {
    if ( v19 == startWidth )
    {
      v21 = 0.0;
      if ( (float)(*(float *)&out - startWidth) < 0.0 )
        goto LABEL_11;
    }
    else
    {
      v21 = 1.0 - (float)((float)(*(float *)&out - v19) / (float)(startWidth - v19));
      if ( v21 >= 0.0 )
      {
        if ( v21 > 1.0 )
LABEL_11:
          v21 = 1.0;
      }
      else
      {
        v21 = 0.0;
      }
    }
    v20 = v21;
  }
  params.proxyAspect = *color * v20;
  params.fadeTime = color[1] * v20;
  *(float *)&params.bSetup = color[2] * v20;
  flags = pbeam->flags;
  scaleColor[0] = color[3] * v20;
  fadeLength = pbeam->fadeLength;
  if ( (flags & 0x8000) != 0 )
  {
    segments = pbeam->segments;
    speed = pbeam->speed;
    freq = pbeam->freq;
    scale = pbeam->amplitude;
    endWidth = pbeam->endWidth;
    localDir.z = (float)frame;
    DrawSegs(
      a1: (int)&v51,
      noise_divisions: 128,
      prgNoise: pbeam->rgNoise,
      spritemodel: sprite,
      (float)frame,
      rendermode,
      source: attachment,
      delta: &pbeam->delta,
      startWidth,
      endWidth,
      scale,
      freq,
      speed,
      segments,
      flags,
      color: &params.proxyAspect,
      fadeLength,
      flHDRColorScale);
  }
  else
  {
    speeda = pbeam->speed;
    freqa = pbeam->freq;
    scalea = pbeam->amplitude;
    endWidtha = pbeam->width;
    localDir.z = (float)frame;
    DrawSegs(
      a1: (int)&v51,
      noise_divisions: 128,
      prgNoise: pbeam->rgNoise,
      spritemodel: sprite,
      (float)frame,
      rendermode,
      source: attachment,
      delta: &pbeam->delta,
      startWidth: endWidtha,
      endWidth: endWidtha,
      scale: scalea,
      freq: freqa,
      speed: speeda,
      segments: 2,
      flags,
      color: &params.proxyAspect,
      fadeLength,
      flHDRColorScale);
  }
  z = pbeam->attachment[0].z;
  m_queryHandleHalo = pbeam->m_queryHandleHalo;
  haloColor_8 = *(_QWORD *)&attachment->x;
  *(_QWORD *)v40 = haloColor_8;
  v45 = z;
  *(float *)&v40[2] = z;
  params.position.x = pbeam->m_haloProxySize;
  params.position.y = 1.0;
  params.position.z = 0.0625;
  LOWORD(params.proxySize) = 1;
  localDir.y = PixelVisibility_FractionVisible(
                 params: (const pixelvis_queryparams_t *)v40,
                 queryHandle: m_queryHandleHalo);
  if ( distThreshold != 0.0 && localDir.y > 0.0 )
  {
    v25 = pbeam->width * 0.5;
    if ( localDir.x == v25 )
    {
      if ( (float)(haloFractionVisible - v25) >= 0.0 )
      {
        v26 = 2.0;
LABEL_25:
        v27 = pbeam->haloScale * v26;
        v28 = distThreshold * distThreshold;
        if ( (float)(distThreshold * distThreshold) >= 0.0 )
        {
          if ( v28 > 1.0 )
            v28 = 1.0;
        }
        else
        {
          v28 = 0.0;
        }
        v29 = v28 * localDir.y;
        *((float *)&out + 1) = *srcColor * v29;
        *((float *)&out + 2) = srcColor[1] * v29;
        *((float *)&out + 3) = srcColor[2] * v29;
        BeamDrawHalo(
          a1: (int)&distToLine,
          spritemodel: halosprite,
          frame: localDir.z,
          rendermode: kRenderGlow,
          source: (const Vector *)&haloColor_8,
          scale: v27,
          color: (float *)&out + 1,
          flHDRColorScale);
        return;
      }
    }
    else
    {
      v26 = (float)((float)(haloFractionVisible - localDir.x) / (float)(v25 - localDir.x)) + 1.0;
      if ( v26 >= 1.0 )
      {
        if ( v26 > 2.0 )
          v26 = 2.0;
        goto LABEL_25;
      }
    }
    v26 = 1.0;
    goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018E930
// Name: private: void CViewRenderBeams::DrawLaser(class Beam_t __near *,int,int,float __near *,struct model_t const __near *,struct model_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRenderBeams::DrawLaser(
        CViewRenderBeams *this@<ecx>,
        float a2@<ebp>,
        Beam_t *pbeam,
        int frame,
        RenderMode_t rendermode,
        float *color,
        const struct model_t *sprite,
        const struct model_t *halosprite,
        float flHDRColorScale)
{
  Vector *attachment; // edi
  const QAngle *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  unsigned int v13; // eax
  const Vector *v14; // eax
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  unsigned int v20; // eax
  float v21; // xmm0_4
  float x; // xmm0_4
  int flags; // eax
  int segments; // ecx
  float startWidth; // [esp+10h] [ebp-84h]
  float endWidth; // [esp+14h] [ebp-80h]
  float scale; // [esp+18h] [ebp-7Ch]
  float freq; // [esp+1Ch] [ebp-78h]
  float speed; // [esp+20h] [ebp-74h]
  float fadeLength; // [esp+30h] [ebp-64h]
  Vector v31; // [esp+5Ch] [ebp-38h] BYREF
  Vector vecForward; // [esp+68h] [ebp-2Ch] BYREF
  Vector color2; // [esp+74h] [ebp-20h] BYREF
  Vector beamDir; // [esp+80h] [ebp-14h] BYREF
  float flFade; // [esp+8Ch] [ebp-8h]
  float retaddr; // [esp+94h] [ebp+0h]

  beamDir.z = a2;
  flFade = retaddr;
  vecForward.x = *color;
  vecForward.y = color[1];
  vecForward.z = color[2];
  attachment = pbeam->attachment;
  color2.x = pbeam->attachment[1].x - pbeam->attachment[0].x;
  color2.y = pbeam->attachment[1].y - pbeam->attachment[0].y;
  color2.z = pbeam->attachment[1].z - pbeam->attachment[0].z;
  VectorNormalize(vec: &color2);
  v10 = CurrentViewAngles();
  AngleVectors(angles: v10, forward: &v31);
  if ( (float)((float)((float)(v31.y * color2.y) + (float)(color2.x * v31.x)) + (float)(v31.z * color2.z)) <= 0.0 )
  {
    v11 = (float)((float)(v31.y * color2.y) + (float)(color2.x * v31.x)) + (float)(v31.z * color2.z);
    v12 = 1.0;
    v13 = 10;
    beamDir.y = 1.0;
    while ( 1 )
    {
      if ( (v13 & 1) != 0 )
        v12 = v12 * v11;
      v13 >>= 1;
      if ( v13 == 0 )
        break;
      v11 = v11 * v11;
    }
    beamDir.y = v12;
    beamDir.x = v12;
    v14 = CurrentViewOrigin();
    v15 = v14->z - pbeam->attachment[0].z;
    v16 = (float)((float)((float)(v14->y - pbeam->attachment[0].y) * color2.y)
                + (float)((float)(v14->x - pbeam->attachment[0].x) * color2.x))
        + (float)(v15 * color2.z);
    v17 = (float)(v14->y - pbeam->attachment[0].y) - (float)(color2.y * v16);
    v18 = fsqrt(
            (float)((float)(v17 * v17)
                  + (float)((float)(v15 - (float)(color2.z * v16)) * (float)(v15 - (float)(color2.z * v16))))
          + (float)((float)((float)(v14->x - attachment->x) - (float)(color2.x * v16))
                  * (float)((float)(v14->x - attachment->x) - (float)(color2.x * v16))));
    if ( v18 <= 30.0 )
    {
      x = beamDir.x;
    }
    else
    {
      if ( (float)(1.0 - (float)((float)(v18 - 30.0) * 0.015625)) <= 0.0 )
        return;
      v19 = 1.0 - (float)((float)(v18 - 30.0) * 0.015625);
      v20 = 3;
      v21 = 1.0;
      while ( 1 )
      {
        if ( (v20 & 1) != 0 )
          v21 = v21 * v19;
        v20 >>= 1;
        if ( v20 == 0 )
          break;
        v19 = v19 * v19;
      }
      x = v21 * beamDir.y;
    }
    if ( x >= 0.0039215689 )
    {
      flags = pbeam->flags;
      segments = pbeam->segments;
      vecForward.x = vecForward.x * x;
      vecForward.y = vecForward.y * x;
      fadeLength = pbeam->fadeLength;
      speed = pbeam->speed;
      freq = pbeam->freq;
      scale = pbeam->amplitude;
      endWidth = pbeam->endWidth;
      startWidth = pbeam->width;
      vecForward.z = vecForward.z * x;
      DrawSegs(
        a1: (int)&beamDir.z,
        noise_divisions: 128,
        prgNoise: pbeam->rgNoise,
        spritemodel: sprite,
        (float)frame,
        rendermode,
        source: attachment,
        delta: &pbeam->delta,
        startWidth,
        endWidth,
        scale,
        freq,
        speed,
        segments,
        flags,
        color: &vecForward.x,
        fadeLength,
        flHDRColorScale: 1.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EC00
// Name: public: virtual void CViewRenderBeams::DrawBeam(class Beam_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRenderBeams::DrawBeam(
        CViewRenderBeams *this@<ecx>,
        const struct model_t *a2@<ebp>,
        Beam_t *pbeam)
{
  __int128 v3; // xmm0
  float r; // xmm1_4
  float g; // xmm3_4
  float b; // xmm4_4
  int v7; // edi
  int flags; // edx
  RenderMode_t v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  int type; // ecx
  float v15; // xmm3_4
  float flHDRColorScale; // xmm0_4
  __int128 v17; // [esp+54h] [ebp-3Ch] BYREF
  float srcColor[3]; // [esp+64h] [ebp-2Ch] BYREF
  float v19; // [esp+70h] [ebp-20h]
  float v20; // [esp+74h] [ebp-1Ch]
  float color[3]; // [esp+78h] [ebp-18h]
  const struct model_t *halosprite; // [esp+84h] [ebp-Ch] BYREF
  void *v23; // [esp+88h] [ebp-8h]
  void *retaddr; // [esp+90h] [ebp+0h]

  halosprite = a2;
  v23 = retaddr;
  LODWORD(color[1]) = this;
  if ( r_DrawBeams.m_pParent != nullptr && r_DrawBeams.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = 0;
    *(float *)&v3 = fsqrt(
                      (float)((float)(pbeam->delta.x * pbeam->delta.x) + (float)(pbeam->delta.y * pbeam->delta.y))
                    + (float)(pbeam->delta.z * pbeam->delta.z));
    v17 = v3;
    if ( *(float *)&v3 >= 0.1 )
    {
      if ( pbeam->modelIndex >= 0 )
      {
        LODWORD(color[2]) = modelinfo->GetModel(this: modelinfo, a2: pbeam->modelIndex);
        if ( LODWORD(color[2]) != 0 )
        {
          LODWORD(color[0]) = modelinfo->GetModel(this: modelinfo, a2: pbeam->haloIndex);
          r = pbeam->r;
          g = pbeam->g;
          b = pbeam->b;
          v7 = (int)(float)((float)(*(float *)(gpGlobals.m_Index + 12) * pbeam->frameRate) + pbeam->frame)
             % pbeam->frameCount;
          flags = pbeam->flags;
          v9 = (flags & 0x20) != 0 ? kRenderNormal : kRenderTransAdd;
          if ( (flags & 4) != 0 )
          {
            v10 = pbeam->t * r;
            v11 = pbeam->t * g;
            v12 = pbeam->t * b;
          }
          else if ( (flags & 8) != 0 )
          {
            v13 = 1.0 - pbeam->t;
            v10 = v13 * r;
            v11 = v13 * g;
            v12 = v13 * b;
          }
          else
          {
            v10 = pbeam->r;
            v11 = pbeam->g;
            v12 = pbeam->b;
          }
          type = pbeam->type;
          v15 = pbeam->brightness * 0.00392156862745098;
          *((float *)&v17 + 1) = v10 * 0.0039215689;
          *((float *)&v17 + 3) = v12 * 0.0039215689;
          *((float *)&v17 + 2) = v11 * 0.0039215689;
          srcColor[2] = v15 * (float)(v10 * 0.0039215689);
          v19 = v15 * (float)(v11 * 0.0039215689);
          v20 = (float)(v12 * 0.0039215689) * v15;
          switch ( type )
          {
            case 0:
              flHDRColorScale = pbeam->m_flHDRColorScale;
              if ( LODWORD(color[0]) != 0 )
                CViewRenderBeams::DrawBeamWithHalo(
                  this: (CViewRenderBeams *)LODWORD(color[1]),
                  a2: (int)&halosprite,
                  pbeam,
                  frame: v7,
                  rendermode: v9,
                  color: &srcColor[2],
                  srcColor: (float *)&v17 + 1,
                  sprite: (const struct model_t *)LODWORD(color[2]),
                  halosprite: (const struct model_t *)LODWORD(color[0]),
                  flHDRColorScale);
              else
                DrawSegs(
                  a1: (int)&halosprite,
                  noise_divisions: 128,
                  prgNoise: pbeam->rgNoise,
                  spritemodel: (const struct model_t *)LODWORD(color[2]),
                  frame: (float)v7,
                  rendermode: v9,
                  source: pbeam->attachment,
                  delta: &pbeam->delta,
                  startWidth: pbeam->width,
                  endWidth: pbeam->endWidth,
                  scale: pbeam->amplitude,
                  freq: pbeam->freq,
                  speed: pbeam->speed,
                  segments: pbeam->segments,
                  flags,
                  color: &srcColor[2],
                  fadeLength: pbeam->fadeLength,
                  flHDRColorScale);
              break;
            case 2:
              DrawDisk(
                a1: COERCE_FLOAT(&halosprite),
                noise_divisions: 128,
                prgNoise: pbeam->rgNoise,
                spritemodel: (const struct model_t *)LODWORD(color[2]),
                frame: (float)v7,
                rendermode: v9,
                source: pbeam->attachment,
                delta: &pbeam->delta,
                width: pbeam->width,
                scale: pbeam->amplitude,
                freq: pbeam->freq,
                speed: pbeam->speed,
                segments: pbeam->segments,
                color: &srcColor[2],
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 3:
              DrawCylinder(
                a1: COERCE_FLOAT(&halosprite),
                a2: v7,
                a3: (int)pbeam->rgNoise,
                noise_divisions: 128,
                prgNoise: pbeam->rgNoise,
                spritemodel: (const struct model_t *)LODWORD(color[2]),
                frame: (float)v7,
                rendermode: v9,
                source: pbeam->attachment,
                delta: &pbeam->delta,
                width: pbeam->width,
                scale: pbeam->amplitude,
                freq: pbeam->freq,
                speed: pbeam->speed,
                segments: pbeam->segments,
                color: &srcColor[2],
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 4:
              CViewRenderBeams::DrawBeamFollow(
                this: (CViewRenderBeams *)LODWORD(color[1]),
                a2: COERCE_FLOAT(&halosprite),
                a3: v7,
                a4: (int)pbeam,
                pSprite: (const struct model_t *)LODWORD(color[2]),
                pbeam,
                frame: v7,
                rendermode: v9,
                frametime: *(float *)(gpGlobals.m_Index + 16),
                color: &srcColor[2],
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 5:
            case 7:
              DrawRing(
                a1: COERCE_FLOAT(&halosprite),
                a2: v7,
                a3: (int)pbeam->rgNoise,
                noise_divisions: 128,
                prgNoise: pbeam->rgNoise,
                pfnNoise: (void (__cdecl *)(float *, int, int))Noise,
                spritemodel: (const struct model_t *)LODWORD(color[2]),
                frame: (float)v7,
                rendermode: v9,
                source: pbeam->attachment,
                delta: &pbeam->delta,
                width: pbeam->width,
                amplitude: pbeam->amplitude,
                freq: pbeam->freq,
                speed: pbeam->speed,
                segments: pbeam->segments,
                color: &srcColor[2],
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 6:
              DrawSplineSegs(
                a1: (int)&halosprite,
                a2: v7,
                a3: (int)pbeam->rgNoise,
                noise_divisions: 128,
                prgNoise: pbeam->rgNoise,
                beammodel: (const struct model_t *)LODWORD(color[2]),
                halomodel: (const struct model_t *)LODWORD(color[0]),
                flHaloScale: pbeam->haloScale,
                frame: (float)v7,
                rendermode: v9,
                numAttachments: pbeam->numAttachments,
                attachment: pbeam->attachment,
                startWidth: pbeam->width,
                endWidth: pbeam->endWidth,
                scale: pbeam->amplitude,
                freq: pbeam->freq,
                speed: pbeam->speed,
                segments: pbeam->segments,
                flags,
                color: &srcColor[2],
                fadeLength: pbeam->fadeLength,
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 8:
              CViewRenderBeams::DrawLaser(
                this: (CViewRenderBeams *)LODWORD(color[1]),
                a2: COERCE_FLOAT(&halosprite),
                pbeam,
                frame: v7,
                rendermode: v9,
                color: &srcColor[2],
                sprite: (const struct model_t *)LODWORD(color[2]),
                halosprite: (const struct model_t *)LODWORD(color[0]),
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            case 9:
              CViewRenderBeams::DrawTesla(
                this: (CViewRenderBeams *)LODWORD(color[1]),
                pbeam,
                frame: v7,
                rendermode: v9,
                color: &srcColor[2],
                sprite: (const struct model_t *)LODWORD(color[2]),
                flHDRColorScale: pbeam->m_flHDRColorScale);
              break;
            default:
              _DevWarning(a1: 1, a2: "CViewRenderBeams::DrawBeam:  Unknown beam type %i\n", type);
              break;
          }
        }
      }
      else
      {
        pbeam->die = *(float *)(gpGlobals.m_Index + 12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F230
// Name: public: virtual void CViewRenderBeams::UpdateBeamInfo(class Beam_t __near *,struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::UpdateBeamInfo(CViewRenderBeams *this, Beam_t *pBeam, BeamInfo_t *beamInfo)
{
  float v4; // xmm1_4
  float v5; // xmm2_4

  qmemcpy((void *)pBeam->attachment, &beamInfo->m_vecStart, 24);
  v4 = beamInfo->m_vecEnd.y - beamInfo->m_vecStart.y;
  v5 = beamInfo->m_vecEnd.z - beamInfo->m_vecStart.z;
  pBeam->delta.x = beamInfo->m_vecEnd.x - beamInfo->m_vecStart.x;
  pBeam->delta.y = v4;
  pBeam->delta.z = v5;
  pBeam->frame = (float)beamInfo->m_nStartFrame;
  pBeam->frameRate = beamInfo->m_flFrameRate;
  pBeam->flags |= beamInfo->m_nFlags;
  pBeam->r = beamInfo->m_flRed;
  pBeam->g = beamInfo->m_flGreen;
  pBeam->b = beamInfo->m_flBlue;
}

//------------------------------------------------------------------------------
// Address: 0x1018F2E0
// Name: private: bool CViewRenderBeams::RecomputeBeamEndpoints(class Beam_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CViewRenderBeams::RecomputeBeamEndpoints(CViewRenderBeams *this, Beam_t *pbeam)
{
  int flags; // eax
  unsigned int m_Index; // edx
  C_BaseAnimating *m_pEntity; // ecx
  int v5; // eax
  unsigned int v6; // edx
  C_BaseAnimating *v7; // ecx
  int v9; // eax

  flags = pbeam->flags;
  if ( (flags & 1) != 0 )
  {
    m_Index = pbeam->entity[0].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ComputeBeamEntPosition(
           pEnt: m_pEntity,
           nAttachment: pbeam->attachmentIndex[0],
           bInterpretAttachmentIndexAsHitboxIndex: (pbeam->flags & 0x400) != 0,
           pt: pbeam->attachment) != 0 )
    {
      pbeam->flags |= 0x800u;
    }
    else
    {
      v5 = pbeam->flags;
      if ( (v5 & 0x4000) == 0 )
        pbeam->flags = v5 & 0xFFFFFFFE;
    }
    flags = pbeam->flags;
    if ( (flags & 0x800) == 0 )
      return false;
  }
  if ( (flags & 2) != 0 )
  {
    v6 = pbeam->entity[1].m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    if ( ComputeBeamEntPosition(
           pEnt: v7,
           nAttachment: pbeam->attachmentIndex[1],
           bInterpretAttachmentIndexAsHitboxIndex: (flags & 0x400) != 0,
           pt: &pbeam->attachment[1]) != 0 )
    {
      pbeam->flags |= 0x1000u;
      return (pbeam->flags & 0x1000) != 0;
    }
    v9 = pbeam->flags;
    if ( (v9 & 0x4000) == 0 )
    {
      pbeam->flags = v9 & 0xFFFFFFFD;
      pbeam->die = *(float *)(gpGlobals.m_Index + 12);
    }
    return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1018F400
// Name: public: virtual void CViewRenderBeams::FreeBeam(class Beam_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::FreeBeam(CViewRenderBeams *this, Beam_t *pBeam)
{
  CViewRenderBeams::BeamFree(this, pBeam);
}

//------------------------------------------------------------------------------
// Address: 0x1018F410
// Name: public: virtual int Beam_t::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge Beam_t::DrawModel@<eax>(
        Beam_t *this@<ecx>,
        const struct model_t *a2@<ebp>,
        int flags,
        const RenderableInstance_t *instance)
{
  int v5; // esi
  int *p_segments; // edi
  unsigned int v7; // ecx
  IHandleEntity *m_pEntity; // eax
  int v9; // eax

  if ( !g_bRenderingScreenshot
    && r_drawviewmodel.m_pParent != nullptr
    && r_drawviewmodel.m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_11:
    CViewRenderBeams::DrawBeam(this: &s_ViewRenderBeams, a2, pbeam: (Beam_t *)((char *)this - 4));
  }
  else
  {
    v5 = 0;
    p_segments = &this->segments;
    while ( 1 )
    {
      v7 = *p_segments;
      if ( *p_segments != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          v9 = (int)m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity);
          if ( v9 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 844))(a1: v9) != 0 )
            break;
        }
      }
      ++v5;
      ++p_segments;
      if ( v5 >= 10 )
        goto LABEL_11;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018F4D0
// Name: public: virtual void CViewRenderBeams::InitBeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::InitBeams(CViewRenderBeams *this)
{
  int v2; // eax
  int v3; // eax

  v2 = _CommandLine(a1: this);
  v3 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v2 + 28))(a1: v2, a2: "-particles", a3: -1);
  if ( v3 < 0 )
  {
    this->m_nNumBeamTrails = 2048;
  }
  else
  {
    if ( v3 <= 512 )
      v3 = 512;
    this->m_nNumBeamTrails = v3;
  }
  this->m_pBeamTrails = (BeamTrail_t *)MemAlloc_Alloc(
                                         nSize: (unsigned __int64)(unsigned int)this->m_nNumBeamTrails >> 27 != 0
                                       ? -1
                                       : 32 * this->m_nNumBeamTrails);
  this->ClearBeams(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018F530
// Name: public: virtual void CViewRenderBeams::KillDeadBeams(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::KillDeadBeams(CViewRenderBeams *this, C_BaseEntity *pDeadEntity)
{
  CViewRenderBeams *v2; // ebx
  Beam_t *m_pActiveBeams; // eax
  Beam_t *v4; // edi
  unsigned int m_Index; // edx
  Beam_t *next; // esi
  C_BaseEntity *m_pEntity; // ecx
  BeamTrail_t *trail; // ecx

  v2 = this;
  m_pActiveBeams = this->m_pActiveBeams;
  v4 = nullptr;
  if ( m_pActiveBeams != nullptr )
  {
    do
    {
      m_Index = m_pActiveBeams->entity[0].m_Index;
      next = m_pActiveBeams->next;
      if ( m_Index == -1
        || (v2 = this, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity != pDeadEntity || (m_pActiveBeams->flags &= 0xFFFFFFFC, m_pActiveBeams->type == 4) )
      {
        m_pActiveBeams->next = v4;
        v4 = m_pActiveBeams;
      }
      else
      {
        trail = m_pActiveBeams->trail;
        for ( m_pActiveBeams->die = *(float *)(gpGlobals.m_Index + 12) - 0.1; trail != nullptr; trail = trail->next )
          trail->die = *(float *)(gpGlobals.m_Index + 12) - 0.1;
        CViewRenderBeams::BeamFree(this: v2, pBeam: m_pActiveBeams);
      }
      m_pActiveBeams = next;
    }
    while ( next != nullptr );
  }
  v2->m_pActiveBeams = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1018F610
// Name: private: void CViewRenderBeams::ClipBeam(class C_Beam __near *,class Beam_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CViewRenderBeams::ClipBeam(
        CViewRenderBeams *this@<ecx>,
        float a2@<ebp>,
        C_Beam *pcbeam,
        Beam_t *pbeam)
{
  float y; // xmm6_4
  float z; // xmm7_4
  float x; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  __int128 v10; // xmm4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  int v17; // [esp+20h] [ebp-84h] BYREF
  _BYTE tr[92]; // [esp+2Ch] [ebp-78h] OVERLAPPED BYREF
  float v19; // [esp+88h] [ebp-1Ch]
  float v20; // [esp+8Ch] [ebp-18h]
  float v21; // [esp+90h] [ebp-14h]
  Vector delta; // [esp+94h] [ebp-10h] BYREF
  float retaddr; // [esp+A4h] [ebp+0h]

  delta.y = a2;
  delta.z = retaddr;
  if ( pcbeam->m_nClipStyle.m_Value == kGEOCLIP )
  {
    LODWORD(delta.x) = 1;
  }
  else
  {
    if ( pcbeam->m_nClipStyle.m_Value != kMODELCLIP )
      return;
    delta.x = 9.4223342e-38;
  }
  y = pbeam->attachment[0].y;
  z = pbeam->attachment[0].z;
  x = pbeam->attachment[0].x;
  v7 = pbeam->attachment[1].y - y;
  v8 = pbeam->attachment[1].z - z;
  v9 = pbeam->attachment[1].x - x;
  v10 = 0;
  *(float *)&v10 = 1.0 / fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9));
  *(_OWORD *)&tr[76] = v10;
  v11 = *(float *)&v10 * 8.0;
  v12 = (float)(*(float *)&v10 * 8.0) * v9;
  v13 = v7 * v11;
  v14 = v8 * v11;
  v19 = v11 * v9;
  v20 = v13;
  v21 = v14;
  if ( cl_beam_test_traces.m_pParent != nullptr && cl_beam_test_traces.m_pParent->m_Value.m_nValue != 0 )
  {
    *(float *)&tr[80] = x + v12;
    *(float *)&tr[84] = y + v13;
    *(float *)&tr[88] = z + v14;
    NDebugOverlay::Line(
      origin: (const Vector *)&tr[80],
      target: &pbeam->attachment[1],
      r: 255,
      g: 255,
      b: 0,
      noDepthTest: 1,
      duration: 0.2);
    v13 = v20;
    v14 = v21;
    v12 = v19;
  }
  *(float *)&tr[80] = pbeam->attachment[0].x + v12;
  v15 = pbeam->attachment[0].y + v13;
  v16 = pbeam->attachment[0].z + v14;
  *(float *)&tr[84] = v15;
  *(float *)&tr[88] = v16;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&delta.y,
    a2: (int)pbeam,
    vecAbsStart: (const Vector *)&tr[80],
    vecAbsEnd: &pbeam->attachment[1],
    mask: LODWORD(delta.x),
    ignore: nullptr,
    collisionGroup: 0,
    ptr: (CGameTrace *)&v17);
  if ( *(float *)&tr[32] < 1.0 )
  {
    if ( cl_beam_test_traces.m_pParent != nullptr && cl_beam_test_traces.m_pParent->m_Value.m_nValue != 0 )
      NDebugOverlay::Cross(
        position: (const Vector *)tr,
        radius: 8.0,
        r: 255,
        g: 255,
        b: 0,
        bNoDepthTest: 0,
        flDuration: 0.2);
    pbeam->attachment[1] = *(Vector *)tr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F800
// Name: public: Beam_t::Beam_t(void)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall Beam_t::Beam_t(Beam_t *this)
{
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
  this->CDefaultClientRenderable::IClientUnknown::IHandleEntity::__vftable = (Beam_t_vtbl *)&Beam_t::`vftable'{for `IClientUnknown'};
  this->CDefaultClientRenderable::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&Beam_t::`vftable'{for `IClientRenderable'};
  this->entity[0].m_Index = -1;
  this->entity[1].m_Index = -1;
  this->entity[2].m_Index = -1;
  this->entity[3].m_Index = -1;
  this->entity[4].m_Index = -1;
  this->entity[5].m_Index = -1;
  this->entity[6].m_Index = -1;
  this->entity[7].m_Index = -1;
  this->entity[8].m_Index = -1;
  this->entity[9].m_Index = -1;
  this->m_Mins.x = 0.0;
  this->m_Mins.y = 0.0;
  this->m_Mins.z = 0.0;
  this->m_Maxs.x = 0.0;
  this->m_Maxs.y = 0.0;
  this->m_Maxs.z = 0.0;
  this->type = 0;
  this->flags = 0;
  this->trail = nullptr;
  this->m_hRenderHandle = -1;
  this->m_bCalculatedNoise = false;
  this->m_queryHandleHalo = nullptr;
  this->m_flHDRColorScale = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018F8B0
// Name: private: class Beam_t __near * CViewRenderBeams::BeamAlloc(bool)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::BeamAlloc(CViewRenderBeams *this, bool bRenderable)
{
  Beam_t *m_pFreeBeams; // esi
  Beam_t *next; // eax
  Beam_t *v5; // eax

  m_pFreeBeams = this->m_pFreeBeams;
  if ( m_pFreeBeams != nullptr )
  {
    next = m_pFreeBeams->next;
    --this->m_nBeamFreeListLength;
    this->m_pFreeBeams = next;
    goto LABEL_6;
  }
  v5 = (Beam_t *)MemAlloc_Alloc(nSize: 0x378u);
  if ( v5 != nullptr )
  {
    m_pFreeBeams = Beam_t::Beam_t(this: v5);
    if ( m_pFreeBeams != nullptr )
      goto LABEL_6;
  }
  else
  {
    m_pFreeBeams = nullptr;
  }
  DevMsg(a1: "ERROR: failed to alloc Beam_t!\n");
LABEL_6:
  m_pFreeBeams->next = this->m_pActiveBeams;
  this->m_pActiveBeams = m_pFreeBeams;
  if ( bRenderable )
    g_pClientLeafSystem->AddRenderable(
      this: g_pClientLeafSystem,
      a2: &m_pFreeBeams->IClientRenderable,
      a3: false,
      a4: RENDERABLE_IS_TRANSLUCENT,
      a5: RENDERABLE_MODEL_ENTITY,
      a6: -1u);
  else
    m_pFreeBeams->m_hRenderHandle = -1;
  return m_pFreeBeams;
}

//------------------------------------------------------------------------------
// Address: 0x1018F940
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamPoints(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamPoints(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *result; // eax
  const char *m_pszModelName; // eax
  Beam_t *v5; // eax
  Beam_t *v6; // edi

  if ( beamInfo->m_flLife == 0.0
    || (result = (Beam_t *)CViewRenderBeams::CullBeam(
                             this,
                             start: &beamInfo->m_vecStart,
                             end: &beamInfo->m_vecEnd,
                             pvsOnly: 1)) != nullptr )
  {
    m_pszModelName = beamInfo->m_pszModelName;
    if ( m_pszModelName != nullptr && beamInfo->m_nModelIndex == -1 )
      beamInfo->m_nModelIndex = modelinfo->GetModelIndex(this: modelinfo, a2: m_pszModelName);
    if ( beamInfo->m_pszHaloName != nullptr && beamInfo->m_nHaloIndex == -1 )
      beamInfo->m_nHaloIndex = modelinfo->GetModelIndex(this: modelinfo, a2: beamInfo->m_pszHaloName);
    v5 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
    v6 = v5;
    if ( v5 != nullptr && (v5->die = *(float *)(gpGlobals.m_Index + 12), beamInfo->m_nModelIndex >= 0) )
    {
      CViewRenderBeams::SetupBeam(this, a2: (int)v5, a3: (int)beamInfo, pBeam: v5, beamInfo);
      v6->frame = (float)beamInfo->m_nStartFrame;
      v6->frameRate = beamInfo->m_flFrameRate;
      v6->flags |= beamInfo->m_nFlags;
      v6->r = beamInfo->m_flRed;
      v6->g = beamInfo->m_flGreen;
      v6->b = beamInfo->m_flBlue;
      if ( beamInfo->m_flLife == 0.0 )
        v6->flags |= 0x4000u;
      return v6;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018FA50
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamCirclePoints(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamCirclePoints(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *v3; // eax
  Beam_t *v4; // esi

  v3 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)beamInfo, a3: (int)v3, pBeam: v3, beamInfo);
  v4->type = beamInfo->m_nType;
  v4->frame = (float)beamInfo->m_nStartFrame;
  v4->frameRate = beamInfo->m_flFrameRate;
  v4->flags |= beamInfo->m_nFlags;
  v4->r = beamInfo->m_flRed;
  v4->g = beamInfo->m_flGreen;
  v4->b = beamInfo->m_flBlue;
  if ( beamInfo->m_flLife == 0.0 )
    v4->flags |= 0x4000u;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1018FB00
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamRingPoint(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamRingPoint(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *v3; // eax
  Beam_t *v4; // edi

  beamInfo->m_vecStart = beamInfo->m_vecCenter;
  beamInfo->m_vecEnd = beamInfo->m_vecCenter;
  v3 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)v3, a3: (int)beamInfo, pBeam: v3, beamInfo);
  v4->type = 7;
  v4->start_radius = beamInfo->m_flStartRadius;
  v4->end_radius = beamInfo->m_flEndRadius;
  v4->attachment[2] = beamInfo->m_vecCenter;
  v4->frame = (float)beamInfo->m_nStartFrame;
  v4->frameRate = beamInfo->m_flFrameRate;
  v4->flags |= beamInfo->m_nFlags;
  v4->r = beamInfo->m_flRed;
  v4->g = beamInfo->m_flGreen;
  v4->b = beamInfo->m_flBlue;
  if ( beamInfo->m_flLife == 0.0 )
    v4->flags |= 0x4000u;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1018FC10
// Name: private: void CViewRenderBeams::UpdateBeam(class Beam_t __near *,float,class C_Beam __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRenderBeams::UpdateBeam(
        CViewRenderBeams *this@<ecx>,
        int a2@<ebp>,
        Beam_t *pbeam,
        float frametime,
        C_Beam *pcbeam)
{
  CViewRenderBeams *v5; // edi
  float v6; // xmm0_4
  __m128 v7; // xmm6
  float amplitude; // xmm0_4
  int flags; // eax
  __m128 v10; // xmm0
  float *rgNoise; // edi
  double v12; // xmm0_8
  bool v13; // zf
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  int type; // eax
  int v18; // eax
  float start_radius; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float life; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float z; // eax
  float v26; // xmm0_4
  float v27; // xmm0_4
  float *p_y; // edi
  unsigned int m_Index; // ecx
  C_BaseAnimating *m_pEntity; // ecx
  float freq; // xmm1_4
  float v32; // xmm0_4
  float v33[3]; // [esp+24h] [ebp-38h]
  int startpos_4; // [esp+48h] [ebp-14h]
  int startpos_4a; // [esp+48h] [ebp-14h]
  float startpos_8; // [esp+4Ch] [ebp-10h]
  CHandle<C_BaseEntity> *startpos_8a; // [esp+4Ch] [ebp-10h]
  int v39; // [esp+50h] [ebp-Ch] BYREF
  int i; // [esp+54h] [ebp-8h]
  int retaddr; // [esp+5Ch] [ebp+0h]

  v39 = a2;
  i = retaddr;
  v5 = this;
  if ( pbeam->modelIndex < 0 )
  {
    pbeam->die = *(float *)(gpGlobals.m_Index + 12);
    return;
  }
  v6 = frametime;
  v7 = 0;
  if ( frametime == 0.0 )
  {
    CUniformRandomStream::SetSeed(this: &beamRandom, a2: (int)*(float *)(gpGlobals.m_Index + 12));
    v6 = frametime;
    v7 = 0;
  }
  if ( (pbeam->flags & 0x100) != 0 )
  {
    v7 = 0;
    pbeam->freq = CUniformRandomStream::RandomFloat(this: &beamRandom, a2: 1.0, a3: 2.0) * frametime + pbeam->freq;
  }
  else
  {
    pbeam->freq = v6 + pbeam->freq;
  }
  amplitude = pbeam->amplitude;
  LODWORD(pbeam->rgNoise[0]) = v7.m128_i32[0];
  LODWORD(pbeam->rgNoise[128]) = v7.m128_i32[0];
  if ( amplitude != v7.m128_f32[0] )
  {
    flags = pbeam->flags;
    if ( (flags & 0x100) == 0 || !pbeam->m_bCalculatedNoise )
    {
      if ( (flags & 0x10) != 0 )
      {
        v10 = v7;
        startpos_8 = v7.m128_f32[0];
        rgNoise = pbeam->rgNoise;
        startpos_4 = 128;
        do
        {
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v10));
          *(float *)&v12 = v12;
          *rgNoise = *(float *)&v12;
          v10 = (__m128)LODWORD(startpos_8);
          v10.m128_f32[0] = startpos_8 + 0.024543693;
          ++rgNoise;
          v13 = startpos_4-- == 1;
          startpos_8 = startpos_8 + 0.024543693;
        }
        while ( !v13 );
        v5 = this;
      }
      else
      {
        Noise(noise: pbeam->rgNoise, divs: 128, scale: 1.0);
      }
      v7.m128_i32[0] = 0;
      pbeam->m_bCalculatedNoise = true;
    }
  }
  if ( (pbeam->flags & 3) != 0 )
  {
    if ( !CViewRenderBeams::RecomputeBeamEndpoints(this: v5, pbeam) )
      return;
    if ( pcbeam != nullptr && pcbeam->m_nClipStyle.m_Value != kNOCLIP )
      CViewRenderBeams::ClipBeam(this: v5, a2: COERCE_FLOAT(&v39), pcbeam, pbeam);
    v7.m128_i32[0] = 0;
    pbeam->delta.x = pbeam->attachment[1].x - pbeam->attachment[0].x;
    pbeam->delta.y = pbeam->attachment[1].y - pbeam->attachment[0].y;
    pbeam->delta.z = pbeam->attachment[1].z - pbeam->attachment[0].z;
    v14 = pbeam->delta.y * pbeam->delta.y;
    v15 = pbeam->delta.x * pbeam->delta.x;
    v16 = pbeam->delta.z * pbeam->delta.z;
    if ( pbeam->amplitude < 0.5 )
      pbeam->segments = (int)(fsqrt((float)(v14 + v16) + v15) * 0.075 + 3.0);
    else
      pbeam->segments = (int)(float)((float)(fsqrt((float)(v15 + v14) + v16) * 0.25) + 3.0);
  }
  type = pbeam->type;
  if ( type == 0 )
  {
    if ( !CViewRenderBeams::CullBeam(this: v5, start: pbeam->attachment, end: &pbeam->attachment[1], pvsOnly: 0) )
      return;
    goto LABEL_49;
  }
  v18 = type - 6;
  if ( v18 != 0 )
  {
    if ( v18 == 1 )
    {
      start_radius = pbeam->start_radius;
      v20 = pbeam->end_radius - start_radius;
      if ( v20 != v7.m128_f32[0] )
      {
        v21 = pbeam->die - *(float *)(gpGlobals.m_Index + 12);
        life = pbeam->life;
        v23 = 1.0;
        if ( life > v21 && life > v7.m128_f32[0] )
        {
          v24 = v21 / life;
          v23 = v24;
          if ( v24 <= 1.0 )
          {
            if ( v7.m128_f32[0] > v24 )
              v23 = v7.m128_f32[0];
          }
          else
          {
            v23 = 1.0;
          }
        }
        z = pbeam->attachment[2].z;
        v26 = (float)((float)((float)(1.0 - v23) * v20) + start_radius) * 0.5;
        *(_QWORD *)v33 = *(_QWORD *)&pbeam->attachment[2].x;
        pbeam->attachment[0].y = v33[1];
        pbeam->attachment[0].x = v33[0] - v26;
        pbeam->attachment[0].z = z;
        pbeam->attachment[1].y = v33[1];
        pbeam->attachment[1].x = v26 + v33[0];
        pbeam->attachment[1].z = z;
        pbeam->delta.x = (float)(v26 + v33[0]) - pbeam->attachment[0].x;
        pbeam->delta.y = pbeam->attachment[1].y - pbeam->attachment[0].y;
        pbeam->delta.z = pbeam->attachment[1].z - pbeam->attachment[0].z;
        v27 = fsqrt(
                (float)((float)(pbeam->delta.y * pbeam->delta.y) + (float)(pbeam->delta.z * pbeam->delta.z))
              + (float)(pbeam->delta.x * pbeam->delta.x));
        if ( pbeam->amplitude < 0.5 )
          pbeam->segments = (int)(v27 * 0.075 + 3.0);
        else
          pbeam->segments = (int)(float)((float)(v27 * 0.25) + 3.0);
      }
    }
    goto LABEL_50;
  }
  startpos_4a = 1;
  if ( pbeam->numAttachments > 1 )
  {
    startpos_8a = &pbeam->entity[1];
    p_y = &pbeam->attachment[1].y;
    do
    {
      m_Index = startpos_8a->m_Index;
      if ( startpos_8a->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( ComputeBeamEntPosition(
             pEnt: m_pEntity,
             nAttachment: startpos_8a[10].m_Index,
             bInterpretAttachmentIndexAsHitboxIndex: (pbeam->flags & 0x400) != 0,
             pt: (Vector *)(p_y - 1)) == 0 )
      {
        *(p_y - 1) = *(p_y - 4);
        *p_y = *(p_y - 3);
        p_y[1] = *(p_y - 2);
      }
      ++startpos_8a;
      p_y += 3;
      ++startpos_4a;
    }
    while ( startpos_4a < pbeam->numAttachments );
LABEL_49:
    v7.m128_i32[0] = 0;
  }
LABEL_50:
  freq = pbeam->freq;
  v32 = (float)(pbeam->die - *(float *)(gpGlobals.m_Index + 12)) + freq;
  pbeam->t = v32;
  if ( v32 == v7.m128_f32[0] )
    pbeam->t = 1.0;
  else
    pbeam->t = freq / v32;
  if ( pbeam->fadeLength == v7.m128_f32[0] )
    pbeam->fadeLength = fsqrt(
                          (float)((float)(pbeam->delta.y * pbeam->delta.y) + (float)(pbeam->delta.z * pbeam->delta.z))
                        + (float)(pbeam->delta.x * pbeam->delta.x));
}

//------------------------------------------------------------------------------
// Address: 0x101901C0
// Name: public: virtual void CViewRenderBeams::UpdateTempEntBeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::UpdateTempEntBeams(CViewRenderBeams *this)
{
  Beam_t *m_pActiveBeams; // esi
  float v3; // xmm0_4
  Beam_t *v4; // eax
  Beam_t *next; // edi
  float frametime; // [esp+14h] [ebp-8h]
  Beam_t *pPrev; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_pActiveBeams = this->m_pActiveBeams;
  if ( m_pActiveBeams != nullptr )
  {
    v3 = *(float *)(gpGlobals.m_Index + 16);
    frametime = v3;
    if ( v3 != 0.0 )
    {
      v4 = nullptr;
      for ( pPrev = nullptr; ; v4 = pPrev )
      {
        next = m_pActiveBeams->next;
        if ( (m_pActiveBeams->flags & 0x4000) != 0 || *(float *)(gpGlobals.m_Index + 12) < m_pActiveBeams->die )
        {
          CViewRenderBeams::UpdateBeam(this, a2: (int)&savedregs, pbeam: m_pActiveBeams, frametime: v3, pcbeam: nullptr);
          Beam_t::ComputeBounds(this: m_pActiveBeams);
          if ( m_pActiveBeams->m_hRenderHandle != 0xFFFF )
            g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_pActiveBeams->m_hRenderHandle);
          pPrev = m_pActiveBeams;
        }
        else
        {
          if ( v4 != nullptr )
            v4->next = next;
          else
            this->m_pActiveBeams = next;
          CViewRenderBeams::BeamFree(this, pBeam: m_pActiveBeams);
        }
        m_pActiveBeams = next;
        if ( next == nullptr )
          break;
        v3 = frametime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190290
// Name: public: virtual void CViewRenderBeams::DrawBeam(class C_Beam __near *,struct RenderableInstance_t const __near &,class ITraceFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRenderBeams::DrawBeam(
        CViewRenderBeams *this,
        C_Beam *pbeam,
        const RenderableInstance_t *instance,
        ITraceFilter *pEntityBeamTraceFilter)
{
  int Type; // edi
  int ModelIndex; // eax
  int m_nAlpha; // edx
  int m_Value; // eax
  float v8; // xmm0_4
  float m_flWidth; // xmm0_4
  int v10; // eax
  float v11; // xmm0_4
  float r; // xmm1_4
  int b; // ecx
  float g; // xmm2_4
  int v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // edx
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // edx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  C_Beam::NetworkVar_m_nAttachIndex *p_m_nAttachIndex; // ecx
  int v27; // ecx
  unsigned int m_Index; // edx
  int v29; // eax
  __int16 BeamFlags; // ax
  IHandleEntity *m_pEntity; // eax
  IClientLeafSystem_vtbl *v32; // edi
  unsigned __int16 *v33; // eax
  CViewRenderBeams *v34; // esi
  Beam_t beam; // [esp+18h] [ebp-418h] BYREF
  BeamInfo_t beamInfo; // [esp+390h] [ebp-A0h] BYREF
  Vector m_vecStart; // [esp+420h] [ebp-10h]
  CViewRenderBeams *v38; // [esp+42Ch] [ebp-4h]
  int savedregs; // [esp+430h] [ebp+0h] BYREF

  v38 = this;
  if ( r_DrawBeams.m_pParent != nullptr && r_DrawBeams.m_pParent->m_Value.m_nValue != 0 )
  {
    Beam_t::Beam_t(this: &beam);
    Type = C_Beam::GetType(this: pbeam);
    beamInfo.m_nType = 0;
    beamInfo.m_nSegments = -1;
    beamInfo.m_pszModelName = nullptr;
    beamInfo.m_pszHaloName = nullptr;
    beamInfo.m_bRenderable = true;
    beamInfo.m_vecStart = *C_Beam::GetAbsStartPos(this: pbeam);
    beamInfo.m_vecEnd = C_Beam::GetAbsEndPos(this: pbeam, a2: (int)&savedregs)->m_Value;
    beamInfo.m_pEndEnt = nullptr;
    beamInfo.m_pStartEnt = nullptr;
    ModelIndex = C_BaseEntity::GetModelIndex(this: pbeam);
    m_nAlpha = instance->m_nAlpha;
    beamInfo.m_flHaloScale = pbeam->m_fHaloScale.m_Value;
    beamInfo.m_flLife = 0.0;
    beamInfo.m_flWidth = pbeam->m_fWidth.m_Value;
    beamInfo.m_flEndWidth = pbeam->m_fEndWidth.m_Value;
    beamInfo.m_flFadeLength = pbeam->m_fFadeLength.m_Value;
    beamInfo.m_flAmplitude = pbeam->m_fAmplitude.m_Value;
    beamInfo.m_nModelIndex = ModelIndex;
    m_Value = pbeam->m_nHaloIndex.m_Value;
    beamInfo.m_flBrightness = (float)m_nAlpha;
    v8 = pbeam->m_fSpeed.m_Value;
    beamInfo.m_nHaloIndex = m_Value;
    beamInfo.m_flSpeed = v8;
    beamInfo.m_nFlags = C_Beam::GetBeamFlags(this: pbeam);
    if ( (C_Beam::GetBeamFlags(this: pbeam) & 0x10000) != 0 )
    {
      m_vecStart = beamInfo.m_vecStart;
      beamInfo.m_vecStart = beamInfo.m_vecEnd;
      beamInfo.m_vecEnd = m_vecStart;
      m_flWidth = beamInfo.m_flWidth;
      beamInfo.m_flWidth = beamInfo.m_flEndWidth;
      beamInfo.m_flEndWidth = m_flWidth;
    }
    CViewRenderBeams::SetupBeam(this: v38, a2: Type, a3: (int)pbeam, pBeam: &beam, &beamInfo);
    v10 = (int)pbeam->m_fStartFrame.m_Value;
    v11 = pbeam->m_flFrameRate.m_Value;
    r = (float)pbeam->m_clrRender.m_Value.r;
    b = pbeam->m_clrRender.m_Value.b;
    g = (float)pbeam->m_clrRender.m_Value.g;
    beam.flags |= beamInfo.m_nFlags;
    beam.frame = (float)v10;
    beam.frameRate = v11;
    beam.r = r;
    beam.g = g;
    beam.b = (float)b;
    if ( pbeam->m_nHaloIndex.m_Value <= 0 )
    {
      beam.m_queryHandleHalo = nullptr;
    }
    else
    {
      *(float *)&v15 = 1.0;
      v16 = (float)((float)(pbeam->m_fWidth.m_Value * pbeam->m_fHaloScale.m_Value) / pbeam->m_fEndWidth.m_Value) + 1.0;
      if ( v16 < 1.0 || (*(float *)&v15 = 8.0, v16 > 8.0) )
        v16 = *(float *)&v15;
      beam.m_queryHandleHalo = &pbeam->m_queryHandleHalo;
      beam.m_haloProxySize = v16;
    }
    switch ( Type )
    {
      case 1:
        v27 = pbeam->m_nAttachIndex.m_Value[0];
        m_Index = pbeam->m_hAttachEntity.m_Value[1].m_Index;
        beam.entity[0].m_Index = pbeam->m_hAttachEntity.m_Value[0].m_Index;
        v29 = pbeam->m_nAttachIndex.m_Value[1];
        beam.attachmentIndex[0] = v27;
        beam.type = 0;
        beam.entity[1].m_Index = m_Index;
        beam.attachmentIndex[1] = v29;
        beam.flags = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)beam.entity) != nullptr;
        if ( CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&beam.entity[1]) != nullptr )
          beam.flags |= 2u;
        goto LABEL_20;
      case 2:
        v17 = pbeam->m_nAttachIndex.m_Value[0];
        v18 = pbeam->m_hAttachEntity.m_Value[1].m_Index;
        beam.entity[0].m_Index = pbeam->m_hAttachEntity.m_Value[0].m_Index;
        v19 = pbeam->m_nAttachIndex.m_Value[1];
        beam.attachmentIndex[0] = v17;
        v20 = pbeam->m_nNumBeamEnts.m_Value;
        beam.type = 0;
        beam.flags = 3;
        beam.entity[1].m_Index = v18;
        beam.attachmentIndex[1] = v19;
        beam.numAttachments = v20;
        break;
      case 4:
        v24 = pbeam->m_nNumBeamEnts.m_Value;
        v25 = 0;
        beam.type = 6;
        beam.flags = 3;
        beam.numAttachments = v24;
        if ( v24 > 0 )
        {
          p_m_nAttachIndex = &pbeam->m_nAttachIndex;
          do
          {
            beam.entity[v25].m_Index = p_m_nAttachIndex[-1].m_Value[0];
            beam.attachmentIndex[v25++] = p_m_nAttachIndex->m_Value[0];
            p_m_nAttachIndex = (C_Beam::NetworkVar_m_nAttachIndex *)((char *)p_m_nAttachIndex + 4);
          }
          while ( v25 < beam.numAttachments );
        }
        break;
      case 5:
        v21 = pbeam->m_nAttachIndex.m_Value[0];
        v22 = pbeam->m_hAttachEntity.m_Value[1].m_Index;
        beam.entity[0].m_Index = pbeam->m_hAttachEntity.m_Value[0].m_Index;
        v23 = pbeam->m_nAttachIndex.m_Value[1];
        beam.type = 8;
        beam.flags = 3;
        beam.attachmentIndex[0] = v21;
        beam.entity[1].m_Index = v22;
        beam.attachmentIndex[1] = v23;
LABEL_20:
        beam.numAttachments = pbeam->m_nNumBeamEnts.m_Value;
        break;
      default:
        break;
    }
    BeamFlags = C_Beam::GetBeamFlags(this: pbeam);
    beam.flags |= BeamFlags & 0x2F0;
    if ( beam.entity[0].m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(beam.entity[0].m_Index)].m_SerialNumber != HIWORD(beam.entity[0].m_Index)
      || g_pEntityList->m_EntPtrArray[LOWORD(beam.entity[0].m_Index)].m_pEntity == nullptr
      || CurrentViewID() != VIEW_REFLECTION
      || (beam.entity[0].m_Index == -1
       || g_pEntityList->m_EntPtrArray[LOWORD(beam.entity[0].m_Index)].m_SerialNumber != HIWORD(beam.entity[0].m_Index)
        ? (m_pEntity = nullptr)
        : (m_pEntity = g_pEntityList->m_EntPtrArray[LOWORD(beam.entity[0].m_Index)].m_pEntity),
          v32 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable,
          v33 = (unsigned __int16 *)((int (__thiscall *)(IHandleEntity *))m_pEntity[1].__vftable[2].SetRefEHandle)(a1: &m_pEntity[1]),
          !v32->IsRenderingWithViewModels(this: g_pClientLeafSystem, a2: *v33)) )
    {
      v34 = v38;
      beam.m_flHDRColorScale = pbeam->m_flHDRColorScale.m_Value;
      CViewRenderBeams::UpdateBeam(
        this: v38,
        a2: (int)&savedregs,
        pbeam: &beam,
        frametime: *(float *)(gpGlobals.m_Index + 16),
        pcbeam: pbeam);
      v34->DrawBeam(this: v34, a2: &beam);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190790
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamEnts(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamEnts(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *v4; // eax
  Beam_t *v5; // edi
  int m_nType; // eax
  BOOL v7; // edx
  C_BaseEntity *m_pStartEnt; // ecx
  C_BaseEntity *m_pEndEnt; // ecx
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( beamInfo->m_flLife != 0.0
    && (beamInfo->m_pStartEnt == nullptr
     || beamInfo->m_pStartEnt->GetModel(this: &beamInfo->m_pStartEnt->IClientRenderable) == nullptr
     || beamInfo->m_pEndEnt == nullptr
     || beamInfo->m_pEndEnt->GetModel(this: &beamInfo->m_pEndEnt->IClientRenderable) == nullptr) )
  {
    return nullptr;
  }
  beamInfo->m_vecStart = vec3_origin;
  beamInfo->m_vecEnd = vec3_origin;
  v4 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  v4->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)v4, a3: (int)beamInfo, pBeam: v4, beamInfo);
  m_nType = beamInfo->m_nType;
  v7 = beamInfo->m_nType < 0;
  v5->flags = 3;
  v5->type = v7 ? 0 : m_nType;
  m_pStartEnt = beamInfo->m_pStartEnt;
  if ( m_pStartEnt != nullptr )
    v5->entity[0].m_Index = m_pStartEnt->GetRefEHandle(this: m_pStartEnt)->m_Index;
  else
    v5->entity[0].m_Index = -1;
  v5->attachmentIndex[0] = beamInfo->m_nStartAttachment;
  m_pEndEnt = beamInfo->m_pEndEnt;
  if ( m_pEndEnt != nullptr )
    v5->entity[1].m_Index = m_pEndEnt->GetRefEHandle(this: m_pEndEnt)->m_Index;
  else
    v5->entity[1].m_Index = -1;
  v5->attachmentIndex[1] = beamInfo->m_nEndAttachment;
  v5->frame = (float)beamInfo->m_nStartFrame;
  v5->frameRate = beamInfo->m_flFrameRate;
  v5->flags |= beamInfo->m_nFlags;
  v5->r = beamInfo->m_flRed;
  v5->g = beamInfo->m_flGreen;
  v5->b = beamInfo->m_flBlue;
  if ( beamInfo->m_flLife == 0.0 )
    v5->flags |= 0x4000u;
  CViewRenderBeams::UpdateBeam(this, a2: (int)&savedregs, pbeam: v5, frametime: 0.0, pcbeam: nullptr);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10190950
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamEntPoint(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamEntPoint(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  C_BaseEntity *m_pStartEnt; // eax
  C_BaseEntity *m_pEndEnt; // eax
  const char *m_pszModelName; // eax
  Beam_t *v7; // eax
  Beam_t *v8; // edi
  C_BaseEntity *v9; // ecx
  C_BaseEntity *v10; // ecx
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( beamInfo->m_flLife != 0.0 )
  {
    m_pStartEnt = beamInfo->m_pStartEnt;
    if ( m_pStartEnt != nullptr && m_pStartEnt->GetModel(this: &m_pStartEnt->IClientRenderable) == nullptr )
      return nullptr;
    m_pEndEnt = beamInfo->m_pEndEnt;
    if ( m_pEndEnt != nullptr && m_pEndEnt->GetModel(this: &m_pEndEnt->IClientRenderable) == nullptr )
      return nullptr;
  }
  m_pszModelName = beamInfo->m_pszModelName;
  if ( m_pszModelName != nullptr && beamInfo->m_nModelIndex == -1 )
    beamInfo->m_nModelIndex = modelinfo->GetModelIndex(this: modelinfo, a2: m_pszModelName);
  if ( beamInfo->m_pszHaloName != nullptr && beamInfo->m_nHaloIndex == -1 )
    beamInfo->m_nHaloIndex = modelinfo->GetModelIndex(this: modelinfo, a2: beamInfo->m_pszHaloName);
  v7 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
  v8 = v7;
  if ( v7 == nullptr )
    return nullptr;
  v7->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)v7, a3: (int)beamInfo, pBeam: v7, beamInfo);
  v8->type = 0;
  v8->flags = 0;
  if ( beamInfo->m_pStartEnt != nullptr )
  {
    v8->flags = 1;
    v9 = beamInfo->m_pStartEnt;
    if ( v9 != nullptr )
      v8->entity[0].m_Index = v9->GetRefEHandle(this: v9)->m_Index;
    else
      v8->entity[0].m_Index = -1;
    v8->attachmentIndex[0] = beamInfo->m_nStartAttachment;
    beamInfo->m_vecStart = vec3_origin;
  }
  if ( beamInfo->m_pEndEnt != nullptr )
  {
    v8->flags |= 2u;
    v10 = beamInfo->m_pEndEnt;
    if ( v10 != nullptr )
      v8->entity[1].m_Index = v10->GetRefEHandle(this: v10)->m_Index;
    else
      v8->entity[1].m_Index = -1;
    v8->attachmentIndex[1] = beamInfo->m_nEndAttachment;
    beamInfo->m_vecEnd = vec3_origin;
  }
  v8->frame = (float)beamInfo->m_nStartFrame;
  v8->frameRate = beamInfo->m_flFrameRate;
  v8->flags |= beamInfo->m_nFlags;
  v8->r = beamInfo->m_flRed;
  v8->g = beamInfo->m_flGreen;
  v8->b = beamInfo->m_flBlue;
  if ( beamInfo->m_flLife == 0.0 )
    v8->flags |= 0x4000u;
  CViewRenderBeams::UpdateBeam(this, a2: (int)&savedregs, pbeam: v8, frametime: 0.0, pcbeam: nullptr);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10190B50
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamFollow(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamFollow(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *v3; // eax
  Beam_t *v4; // edi
  C_BaseEntity *m_pStartEnt; // ecx
  bool m_bRenderable; // [esp+4h] [ebp-10h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  beamInfo->m_vecStart = vec3_origin;
  beamInfo->m_vecEnd = vec3_origin;
  m_bRenderable = beamInfo->m_bRenderable;
  beamInfo->m_flSpeed = 1.0;
  v3 = CViewRenderBeams::BeamAlloc(this, bRenderable: m_bRenderable);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)v3, a3: (int)beamInfo, pBeam: v3, beamInfo);
  v4->type = 4;
  v4->flags = 1;
  m_pStartEnt = beamInfo->m_pStartEnt;
  if ( m_pStartEnt != nullptr )
    v4->entity[0].m_Index = m_pStartEnt->GetRefEHandle(this: m_pStartEnt)->m_Index;
  else
    v4->entity[0].m_Index = -1;
  v4->attachmentIndex[0] = beamInfo->m_nStartAttachment;
  beamInfo->m_flFrameRate = 1.0;
  beamInfo->m_nStartFrame = 0;
  v4->frame = 0.0;
  v4->frameRate = beamInfo->m_flFrameRate;
  v4->flags |= beamInfo->m_nFlags;
  v4->r = beamInfo->m_flRed;
  v4->g = beamInfo->m_flGreen;
  v4->b = beamInfo->m_flBlue;
  CViewRenderBeams::UpdateBeam(this, a2: (int)&savedregs, pbeam: v4, frametime: 0.0, pcbeam: nullptr);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10190C90
// Name: public: virtual class Beam_t __near * CViewRenderBeams::CreateBeamRing(struct BeamInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
Beam_t *__thiscall CViewRenderBeams::CreateBeamRing(CViewRenderBeams *this, BeamInfo_t *beamInfo)
{
  Beam_t *v4; // eax
  Beam_t *v5; // edi
  C_BaseEntity *m_pStartEnt; // ecx
  C_BaseEntity *m_pEndEnt; // ecx
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( beamInfo->m_flLife != 0.0
    && (beamInfo->m_pStartEnt == nullptr
     || beamInfo->m_pStartEnt->GetModel(this: &beamInfo->m_pStartEnt->IClientRenderable) == nullptr
     || beamInfo->m_pEndEnt == nullptr
     || beamInfo->m_pEndEnt->GetModel(this: &beamInfo->m_pEndEnt->IClientRenderable) == nullptr) )
  {
    return nullptr;
  }
  beamInfo->m_vecStart = vec3_origin;
  beamInfo->m_vecEnd = vec3_origin;
  v4 = CViewRenderBeams::BeamAlloc(this, bRenderable: beamInfo->m_bRenderable);
  v5 = v4;
  if ( v4 == nullptr )
    return nullptr;
  v4->die = *(float *)(gpGlobals.m_Index + 12);
  if ( beamInfo->m_nModelIndex < 0 )
    return nullptr;
  CViewRenderBeams::SetupBeam(this, a2: (int)v4, a3: (int)beamInfo, pBeam: v4, beamInfo);
  v5->type = 5;
  v5->flags = 3;
  m_pStartEnt = beamInfo->m_pStartEnt;
  if ( m_pStartEnt != nullptr )
    v5->entity[0].m_Index = m_pStartEnt->GetRefEHandle(this: m_pStartEnt)->m_Index;
  else
    v5->entity[0].m_Index = -1;
  v5->attachmentIndex[0] = beamInfo->m_nStartAttachment;
  m_pEndEnt = beamInfo->m_pEndEnt;
  if ( m_pEndEnt != nullptr )
    v5->entity[1].m_Index = m_pEndEnt->GetRefEHandle(this: m_pEndEnt)->m_Index;
  else
    v5->entity[1].m_Index = -1;
  v5->attachmentIndex[1] = beamInfo->m_nEndAttachment;
  v5->frame = (float)beamInfo->m_nStartFrame;
  v5->frameRate = beamInfo->m_flFrameRate;
  v5->flags |= beamInfo->m_nFlags;
  v5->r = beamInfo->m_flRed;
  v5->g = beamInfo->m_flGreen;
  v5->b = beamInfo->m_flBlue;
  if ( beamInfo->m_flLife == 0.0 )
    v5->flags |= 0x4000u;
  CViewRenderBeams::UpdateBeam(this, a2: (int)&savedregs, pbeam: v5, frametime: 0.0, pcbeam: nullptr);
  return v5;
}
