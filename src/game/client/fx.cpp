// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx.cpp
// Functions: 35
// ============================================================

#include "game\client\fx.h"

//------------------------------------------------------------------------------
// Address: 0x102679C0
// Name: public: virtual void PrecacheMuzzleFlashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheMuzzleFlashPrecache::CResourcePrecacher::Cache(
        PrecacheMuzzleFlashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash3",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10267A30
// Name: void FX_RicochetSound(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_RicochetSound(const Vector *pos)
{
  float z; // eax
  CLocalPlayerFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector org; // [esp+28h] [ebp-Ch] BYREF

  z = pos->z;
  *(_QWORD *)&org.x = *(_QWORD *)&pos->x;
  org.z = z;
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: 0,
    soundname: "FX_RicochetSound.Ricochet",
    pOrigin: &org,
    soundtime: 0.0,
    duration: nullptr);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10267A80
// Name: bool FX_GetAttachmentTransform(class CBaseHandle,int,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FX_GetAttachmentTransform(CBaseHandle hEntity, int attachmentIndex, Vector *origin, QAngle *angles)
{
  IClientRenderable *ClientRenderableFromHandle; // eax
  QAngle attachAngles; // [esp+4h] [ebp-18h] BYREF
  Vector attachOrigin; // [esp+10h] [ebp-Ch] BYREF

  if ( hEntity.m_Index == -1 || attachmentIndex < 1 )
  {
    if ( origin != nullptr )
      *origin = vec3_origin;
    if ( angles != nullptr )
    {
      angles->x = 0.0;
      angles->y = 0.0;
      angles->z = 0.0;
    }
    return 0;
  }
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: hEntity);
  if ( ClientRenderableFromHandle == nullptr )
    return 0;
  ClientRenderableFromHandle->GetAttachment_2(
    this: ClientRenderableFromHandle,
    a2: attachmentIndex,
    a3: &attachOrigin,
    a4: &attachAngles);
  if ( origin != nullptr )
    *origin = attachOrigin;
  if ( angles != nullptr )
    *angles = attachAngles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10267B70
// Name: bool FX_GetAttachmentTransform(class CBaseHandle,int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FX_GetAttachmentTransform(CBaseHandle hEntity, int attachmentIndex, matrix3x4_t *transform)
{
  QAngle angles; // [esp+0h] [ebp-18h] BYREF
  Vector origin; // [esp+Ch] [ebp-Ch] BYREF

  if ( FX_GetAttachmentTransform(hEntity, attachmentIndex, &origin, &angles) != 0 )
  {
    AngleMatrix(&angles, position: &origin, matrix: transform);
    return 1;
  }
  else
  {
    SetIdentityMatrix(matrix: transform);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10267BC0
// Name: void MuzzleFlashCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MuzzleFlashCallback(const CEffectData *data)
{
  float z; // ecx
  float v2; // eax
  IClientRenderable *Renderable; // esi
  int m_nAttachmentIndex; // eax
  Vector vecOrigin; // [esp+8h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+14h] [ebp-Ch] BYREF

  z = data->m_vAngles.z;
  v2 = data->m_vOrigin.z;
  *(_QWORD *)&vecOrigin.x = *(_QWORD *)&data->m_vOrigin.x;
  vecAngles.z = z;
  vecOrigin.z = v2;
  *(_QWORD *)&vecAngles.x = *(_QWORD *)&data->m_vAngles.x;
  if ( CEffectData::entindex(this: data) > 0 )
  {
    Renderable = CEffectData::GetRenderable(this: data);
    if ( Renderable == nullptr )
      return;
    m_nAttachmentIndex = data->m_nAttachmentIndex;
    if ( m_nAttachmentIndex != 0 )
    {
      Renderable->GetAttachment_2(this: Renderable, a2: m_nAttachmentIndex, a3: &vecOrigin, a4: &vecAngles);
    }
    else
    {
      vecOrigin = *Renderable->GetRenderOrigin(this: Renderable);
      vecAngles = *Renderable->GetRenderAngles(this: Renderable);
    }
  }
  ((void (__stdcall *)(Vector *, QAngle *, unsigned int, unsigned int, int))tempents->MuzzleFlash)(
    a1: &vecOrigin,
    a2: &vecAngles,
    a3: data->m_fFlags & 0xFFFFFEFF,
    a4: data->m_hEntity.m_Index,
    a5: BYTE1(data->m_fFlags) & 1);
}

//------------------------------------------------------------------------------
// Address: 0x10267CB0
// Name: public: void CSmokeEmitter::CreateSpurtParticles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeEmitter::CreateSpurtParticles(CSmokeEmitter *this)
{
  float z; // eax
  __int64 v3; // xmm0_8
  unsigned int m_Index; // ecx
  IClientRenderable *ClientRenderableFromHandle; // eax
  IUniformRandomStream *m_nAttachmentIndex; // ecx
  int v7; // ebx
  Particle *v8; // eax
  IUniformRandomStream *v9; // ecx
  Particle *v10; // esi
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  int v15; // eax
  Vector4D *p_m_SpurtColor; // ecx
  float v17; // xmm1_4
  float v18; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  char v20; // al
  int v21; // edx
  IUniformRandomStream *w; // ecx
  char v23; // al
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  int color[3][2]; // [esp+18h] [ebp-38h]
  Vector vecOrigin; // [esp+30h] [ebp-20h] BYREF
  Vector vecVelocity; // [esp+3Ch] [ebp-14h] BYREF
  int numParticles; // [esp+48h] [ebp-8h]
  float v30; // [esp+4Ch] [ebp-4h]

  z = this->m_vSortOrigin.z;
  v3 = *(_QWORD *)&this->m_vSortOrigin.x;
  m_Index = this->m_hEntity.m_Index;
  vecOrigin.z = z;
  *(_QWORD *)&vecOrigin.x = v3;
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: (CBaseHandle)m_Index);
  if ( ClientRenderableFromHandle != nullptr )
  {
    m_nAttachmentIndex = (IUniformRandomStream *)this->m_nAttachmentIndex;
    if ( m_nAttachmentIndex != nullptr )
    {
      ClientRenderableFromHandle->GetAttachment_2(
        this: ClientRenderableFromHandle,
        a2: (int)m_nAttachmentIndex,
        a3: &vecOrigin,
        a4: (QAngle *)&vecVelocity);
      CParticleEffect::SetSortOrigin(this, vSortOrigin: &vecOrigin);
    }
  }
  v7 = 0;
  numParticles = _RandomInt(this: m_nAttachmentIndex, a2: 1, a3: 2);
  if ( numParticles > 0 )
  {
    do
    {
      v8 = CParticleEffect::AddParticle(this, particleSize: 0x3Cu, material: g_Mat_DustPuff[0], origin: &vecOrigin);
      v10 = v8;
      if ( v8 == nullptr )
        break;
      v8[1].m_Pos.z = 0.0;
      v8[1].m_Pos.y = _RandomFloat(this: v9, a2: 0.5, a3: 1.0);
      vecVelocity.x = _RandomFloat(this: v11, a2: -0.1, a3: 0.1);
      vecVelocity.y = _RandomFloat(this: v12, a2: -0.1, a3: 0.1);
      vecVelocity.z = _RandomFloat(this: v13, a2: -0.1, a3: 0.1);
      vecVelocity.x = this->m_vecSpurtForward.x + vecVelocity.x;
      vecVelocity.y = this->m_vecSpurtForward.y + vecVelocity.y;
      vecVelocity.z = this->m_vecSpurtForward.z + vecVelocity.z;
      VectorNormalize(vec: &vecVelocity);
      v30 = _RandomFloat(this: v14, a2: 160.0, a3: 640.0);
      vecVelocity.y = vecVelocity.y * v30;
      vecVelocity.x = vecVelocity.x * v30;
      vecVelocity.z = vecVelocity.z * v30;
      *(Vector *)&v10[1].m_pPrev = vecVelocity;
      v15 = 0;
      p_m_SpurtColor = &this->m_SpurtColor;
      do
      {
        v17 = p_m_SpurtColor->x - 64.0;
        if ( v17 < 0.0 )
          v17 = 0.0;
        v18 = p_m_SpurtColor->x + 64.0;
        color[v15][0] = (int)v17;
        if ( v18 > 255.0 )
          v18 = 255.0;
        color[v15++][1] = (int)v18;
        p_m_SpurtColor = (Vector4D *)((char *)p_m_SpurtColor + 4);
      }
      while ( v15 < 3 );
      RandomInt = random->RandomInt;
      *(_QWORD *)&color[2][0] = *(_QWORD *)&color[0][0];
      LOBYTE(v10[2].m_pPrev) = ((int (__thiscall *)(IUniformRandomStream *))RandomInt)(a1: random);
      v20 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
      v21 = color[2][1];
      BYTE1(v10[2].m_pPrev) = v20;
      BYTE2(v10[2].m_pPrev) = random->RandomInt(this: random, a2: color[2][0], a3: v21);
      w = (IUniformRandomStream *)(int)this->m_SpurtColor.w;
      *(_WORD *)((char *)&v10[2].m_pPrev + 3) = (unsigned __int8)w;
      v23 = _RandomInt(this: w, a2: 50, a3: 60);
      BYTE1(v10[2].m_pNext) = v23;
      color[0][1] = 1135869952;
      BYTE2(v10[2].m_pNext) = 3 * v23;
      v10[1].m_Pos.x = _RandomFloat(this: v24, a2: 0.0, a3: *(float *)&color[0][1]);
      *(float *)&v10[2].m_pSubTexture = _RandomFloat(this: v25, a2: -4.0, a3: 4.0);
      ++v7;
    }
    while ( v7 < numParticles );
  }
  this->m_flLastParticleSpawnTime = *(float *)(gpGlobals.m_Index + 12) + this->m_flSpawnRate;
}

//------------------------------------------------------------------------------
// Address: 0x10267FE0
// Name: public: virtual void CSmokeEmitter::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeEmitter::SimulateParticles(CSmokeEmitter *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  CEffectMaterial *m_pNext; // ecx
  Particle *i; // eax
  float m_flDeathTime; // xmm1_4
  float v7; // xmm0_4
  CEffectMaterial *m_pNextParticle; // eax

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = (CEffectMaterial *)m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != (CEffectMaterial *)&m_pMaterial->m_Particles )
  {
    for ( i = m_pNext->m_Particles.m_pPrev; ; i = m_pNextParticle->m_Particles.m_pPrev )
    {
      m_flDeathTime = this->m_flDeathTime;
      pIterator->m_pNextParticle = i;
      v7 = *(float *)(gpGlobals.m_Index + 12);
      if ( m_flDeathTime > v7 && v7 >= this->m_flLastParticleSpawnTime )
        CSmokeEmitter::CreateSpurtParticles(this);
      m_pNextParticle = (CEffectMaterial *)pIterator->m_pNextParticle;
      if ( m_pNextParticle == (CEffectMaterial *)&pIterator->m_pMaterial->m_Particles )
        break;
    }
  }
  CSimpleEmitter::SimulateParticles((CLocalSpaceEmitter *)this, pIterator);
}

//------------------------------------------------------------------------------
// Address: 0x10268050
// Name: public: virtual bool CImpactOverlay::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImpactOverlay::Update(CImpactOverlay *this)
{
  float v1; // xmm0_4
  int v2; // esi
  float v3; // xmm3_4
  float *p_z; // eax
  float *v5; // edx
  float v6; // xmm1_4
  float v7; // xmm2_4

  v1 = *(float *)(gpGlobals.m_Index + 16) + this->m_flLifetime;
  this->m_flLifetime = v1;
  if ( v1 >= 0.1 )
    return 0;
  v2 = 0;
  v3 = 1.0 - (float)(v1 * 10.0);
  if ( this->m_nSprites > 0 )
  {
    p_z = &this->m_Sprites[0].m_vColor.z;
    v5 = &this->m_vBaseColors[0].z;
    do
    {
      v6 = *(v5 - 1);
      v7 = *v5;
      *(p_z - 2) = *(v5 - 2) * v3;
      *(p_z - 1) = v6 * v3;
      *p_z = v7 * v3;
      p_z[1] = *(float *)(gpGlobals.m_Index + 16) + p_z[1];
      p_z[2] = *(float *)(gpGlobals.m_Index + 16) + p_z[2];
      ++v2;
      v5 += 3;
      p_z += 6;
    }
    while ( v2 < this->m_nSprites );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10268120
// Name: void FX_StriderMuzzleEffect(class Vector const __near &,class QAngle const __near &,float,class CBaseHandle,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_StriderMuzzleEffect(const Vector *origin, const QAngle *angles)
{
  float velocity; // xmm0_4
  int i; // edi
  Vector vecDir; // [esp+20h] [ebp-10h] BYREF
  float speed; // [esp+2Ch] [ebp-4h]

  AngleVectors(angles, forward: &vecDir);
  velocity = 100.0;
  speed = 100.0;
  for ( i = 5; i != 0; --i )
  {
    FX_AddDiscreetLine(
      start: origin,
      direction: &vecDir,
      velocity,
      length: 32.0,
      clipLength: velocity * 0.30000001,
      scale: 5.0,
      life: 0.30000001,
      shader: "effects/bluespark");
    velocity = speed * 1.5;
    speed = speed * 1.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102681C0
// Name: void FX_BuildTeslaZap(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_BuildTeslaZap(const CEffectData *data)
{
  C_BaseEntity *Entity; // eax
  float m_flScale; // xmm2_4
  int m_nAttachmentIndex; // eax
  BeamInfo_t beamInfo; // [esp+4h] [ebp-90h] BYREF

  Entity = CEffectData::GetEntity(this: data);
  if ( Entity != nullptr )
  {
    m_flScale = data->m_flScale;
    beamInfo.m_vecEnd = data->m_vOrigin;
    beamInfo.m_flLife = 0.30000001;
    beamInfo.m_flFadeLength = 0.30000001;
    beamInfo.m_pStartEnt = Entity;
    m_nAttachmentIndex = data->m_nAttachmentIndex;
    beamInfo.m_pszHaloName = nullptr;
    beamInfo.m_pEndEnt = nullptr;
    beamInfo.m_flHaloScale = 0.0;
    beamInfo.m_flWidth = m_flScale;
    beamInfo.m_flAmplitude = 16.0;
    beamInfo.m_flSpeed = 0.0;
    beamInfo.m_nStartFrame = 0;
    beamInfo.m_nFlags = 0;
    beamInfo.m_nModelIndex = -1;
    beamInfo.m_nHaloIndex = -1;
    beamInfo.m_nStartAttachment = m_nAttachmentIndex;
    beamInfo.m_nType = 9;
    beamInfo.m_pszModelName = "sprites/physbeam.vmt";
    beamInfo.m_flEndWidth = 1.0;
    beamInfo.m_flBrightness = 200.0;
    beamInfo.m_flFrameRate = 1.0;
    beamInfo.m_flRed = 255.0;
    beamInfo.m_flGreen = 255.0;
    beamInfo.m_flBlue = 255.0;
    beamInfo.m_nSegments = 20;
    beamInfo.m_bRenderable = true;
    beams->CreateBeamEntPoint_2(this: beams, a2: &beamInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102682D0
// Name: void FX_MuzzleEffect(class Vector const __near &,class QAngle const __near &,float,class CBaseHandle,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_MuzzleEffect(
        const Vector *origin,
        const QAngle *angles,
        float scale,
        CBaseHandle hEntity,
        unsigned __int8 *pFlashColor)
{
  double v5; // st7
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  CSimpleEmitter *m_pObj; // esi
  CSimpleEmitter *v11; // ebx
  int v12; // eax
  const char *v13; // eax
  CParticleSubTexture *PMaterial; // eax
  Particle *v15; // esi
  double v16; // st7
  char v17; // al
  int v18; // eax
  float v19; // xmm0_4
  int v20; // eax
  Vector offset; // [esp+38h] [ebp-30h] BYREF
  Vector forward; // [esp+44h] [ebp-24h] BYREF
  int v23; // [esp+50h] [ebp-18h]
  int v24; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+5Ch] [ebp-Ch] BYREF
  float flScale; // [esp+60h] [ebp-8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_MuzzleEffect",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash");
  CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: origin);
  AngleVectors(angles, &forward);
  v5 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
         a1: random,
         a2: scale - 0.25,
         a3: scale + 0.25);
  flScale = v5;
  if ( v5 < 0.5 )
  {
    v6 = 0.5;
LABEL_4:
    flScale = v6;
    goto LABEL_5;
  }
  v6 = 8.0;
  if ( flScale > 8.0 )
    goto LABEL_4;
LABEL_5:
  i = 1;
  v24 = 11;
  do
  {
    v7 = (float)((float)i * 2.0) * scale;
    v8 = (float)(forward.y * v7) + origin->y;
    v9 = (float)(forward.z * v7) + origin->z;
    m_pObj = pSimple.m_pObj;
    v11 = pSimple.m_pObj;
    offset.x = origin->x + (float)(forward.x * v7);
    offset.y = v8;
    offset.z = v9;
    v12 = random->RandomInt(this: random, a2: 1, a3: 4);
    v13 = VarArgs(format: "effects/muzzleflash%d", v12);
    PMaterial = CParticleEffect::GetPMaterial(this: m_pObj, name: v13);
    v15 = CParticleEffect::AddParticle(this: v11, particleSize: 0x3Cu, material: PMaterial, origin: &offset);
    if ( v15 == nullptr )
      break;
    *(_QWORD *)&v15[1].m_Pos.y = 1036831949;
    v15[1].m_pPrev = nullptr;
    v15[1].m_pNext = nullptr;
    v15[1].m_pSubTexture = nullptr;
    if ( pFlashColor != nullptr )
    {
      LOBYTE(v15[2].m_pPrev) = *pFlashColor;
      BYTE1(v15[2].m_pPrev) = pFlashColor[1];
      BYTE2(v15[2].m_pPrev) = pFlashColor[2];
    }
    else
    {
      LOWORD(v15[2].m_pPrev) = -1;
      BYTE2(v15[2].m_pPrev) = -1;
    }
    *(_WORD *)((char *)&v15[2].m_pPrev + 3) = -32513;
    v16 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1086324736,
            a3: 1091567616);
    v23 = (int)(v16 * (double)v24 * 0.11111111 * flScale);
    v17 = v23;
    BYTE1(v15[2].m_pNext) = v23;
    BYTE2(v15[2].m_pNext) = v17;
    v18 = random->RandomInt(this: random, a2: 0, a3: 360);
    ++i;
    v19 = (float)v18;
    v20 = v24 - 1;
    v15[1].m_Pos.x = v19;
    v15[2].m_pSubTexture = nullptr;
    v24 = v20;
  }
  while ( v20 > 3 );
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10268530
// Name: void FX_MuzzleEffectAttached(float,class CBaseHandle,int,unsigned char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_MuzzleEffectAttached(
        float scale,
        CBaseHandle hEntity,
        int attachmentIndex,
        unsigned __int8 *pFlashColor,
        bool bOneFrame)
{
  double v5; // st7
  float v6; // xmm0_4
  int v7; // edi
  int v8; // ebx
  CLocalSpaceEmitter *m_pObj; // esi
  int v10; // eax
  Particle *v11; // eax
  Particle *v12; // esi
  int v13; // xmm0_4
  double v14; // st7
  char v15; // al
  C_BaseEntity *BaseEntityFromHandle; // eax
  CLocalSpaceEmitter *v17; // edi
  CParticleMgr *v18; // eax
  int value; // esi
  KeyValues *v20; // eax
  KeyValues *v21; // ebx
  KeyValues *Key; // esi
  KeyValues *v23; // esi
  KeyValues *v24; // edi
  void *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // edi
  float v28; // xmm0_4
  float v29; // xmm0_4
  KeyValues *v30; // edi
  KeyValues *v31; // edi
  KeyValues *v32; // edi
  KeyValues *v33; // edi
  unsigned __int8 v34; // dl
  unsigned __int8 v35; // cl
  unsigned __int8 v36; // al
  KeyValues *v37; // edi
  KeyValues *v38; // eax
  KeyValues *v39; // esi
  Vector offset; // [esp+44h] [ebp-34h] BYREF
  Vector bbMin; // [esp+50h] [ebp-28h] BYREF
  Vector bbMax; // [esp+5Ch] [ebp-1Ch] BYREF
  int v43; // [esp+68h] [ebp-10h]
  float flScale; // [esp+6Ch] [ebp-Ch]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pSimple; // [esp+70h] [ebp-8h] BYREF
  int v46; // [esp+74h] [ebp-4h]
  Color color; // [esp+88h] [ebp+10h]
  float colora; // [esp+88h] [ebp+10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_MuzzleEffect",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CLocalSpaceEmitter::Create(
    result: &pSimple,
    pDebugName: "MuzzleFlash",
    hEntity,
    nAttachment: attachmentIndex,
    fFlags: 0);
  if ( pSimple.m_pObj == nullptr )
    goto LABEL_34;
  bbMax.x = scale * 16.0;
  bbMax.y = scale * 16.0;
  bbMax.z = scale * 16.0;
  bbMin.x = -(float)(scale * 16.0);
  bbMin.y = bbMin.x;
  bbMin.z = bbMin.x;
  CParticleEffectBinding::SetBBox(this: &pSimple.m_pObj->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
  v5 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
         a1: random,
         a2: scale - 0.25,
         a3: scale + 0.25);
  flScale = v5;
  if ( v5 >= 0.5 )
  {
    v6 = 8.0;
    if ( flScale <= 8.0 )
      goto LABEL_6;
  }
  else
  {
    v6 = 0.5;
  }
  flScale = v6;
LABEL_6:
  v7 = 11;
  v8 = 1;
  v46 = 11;
  while ( 1 )
  {
    m_pObj = pSimple.m_pObj;
    offset.x = (float)((float)v8 * 2.0) * scale;
    offset.y = offset.x * 0.0;
    offset.z = offset.x * 0.0;
    v10 = random->RandomInt(this: random, a2: 0, a3: 3);
    v11 = CParticleEffect::AddParticle(
            this: m_pObj,
            particleSize: 0x3Cu,
            material: g_Mat_SMG_Muzzleflash[v10],
            origin: &offset);
    v12 = v11;
    if ( v11 == nullptr )
      break;
    v11[1].m_Pos.z = 0.0;
    if ( bOneFrame )
      v13 = 953267991;
    else
      v13 = 1036831949;
    LODWORD(v11[1].m_Pos.y) = v13;
    v11[1].m_pPrev = nullptr;
    v11[1].m_pNext = nullptr;
    v11[1].m_pSubTexture = nullptr;
    if ( pFlashColor != nullptr )
    {
      LOBYTE(v11[2].m_pPrev) = *pFlashColor;
      BYTE1(v11[2].m_pPrev) = pFlashColor[1];
      BYTE2(v11[2].m_pPrev) = pFlashColor[2];
    }
    else
    {
      LOWORD(v11[2].m_pPrev) = -1;
      BYTE2(v11[2].m_pPrev) = -1;
    }
    *(_WORD *)((char *)&v11[2].m_pPrev + 3) = -32513;
    v14 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1086324736,
            a3: 1091567616);
    v43 = (int)(v14 * (double)v46 * 0.11111111 * flScale);
    v15 = v43;
    BYTE1(v12[2].m_pNext) = v43;
    BYTE2(v12[2].m_pNext) = v15;
    --v7;
    ++v8;
    v12[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    v12[2].m_pSubTexture = nullptr;
    v46 = v7;
    if ( v7 <= 3 )
    {
      if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
      {
        BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: hEntity);
        v43 = (int)BaseEntityFromHandle;
        if ( BaseEntityFromHandle != nullptr )
          BaseEntityFromHandle->RecordToolMessage(this: &BaseEntityFromHandle->IClientRenderable);
        v17 = pSimple.m_pObj;
        v18 = ParticleMgr();
        value = v18->m_nToolParticleEffectId;
        v18->m_nToolParticleEffectId = value + 1;
        v17->m_nToolParticleEffectId = value;
        v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v20 != nullptr )
          v21 = KeyValues::KeyValues(this: v20, setName: "OldParticleSystem_Create");
        else
          v21 = nullptr;
        KeyValues::SetString(this: v21, keyName: "name", value: "FX_MuzzleEffectAttached");
        KeyValues::SetInt(this: v21, keyName: "id", value);
        KeyValues::SetFloat(this: v21, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
        Key = KeyValues::FindKey(this: v21, keyName: "DmeSpriteEmitter", bCreate: true);
        KeyValues::SetInt(this: Key, keyName: "count", value: 9);
        KeyValues::SetFloat(this: Key, keyName: "duration", value: 0.0);
        KeyValues::SetString(this: Key, keyName: "material", value: "effects/muzzleflash2");
        KeyValues::SetInt(this: Key, keyName: "active", value: 1);
        v23 = KeyValues::FindKey(this: Key, keyName: "initializers", bCreate: true);
        v24 = KeyValues::FindKey(this: v23, keyName: "DmeLinearAttachedPositionInitializer", bCreate: true);
        v25 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)(v43 + 8) + 40))(a1: v43 + 8);
        KeyValues::SetPtr(this: v24, keyName: "entindex", value: v25);
        KeyValues::SetInt(this: v24, keyName: "attachmentIndex", value: attachmentIndex);
        KeyValues::SetFloat(this: v24, keyName: "linearOffsetX", value: scale * 2.0);
        v26 = KeyValues::FindKey(this: v23, keyName: "DmeRandomLifetimeInitializer", bCreate: true);
        v27 = v26;
        if ( bOneFrame )
          v28 = 0.041666668;
        else
          v28 = 0.1;
        KeyValues::SetFloat(this: v26, keyName: "minLifetime", value: v28);
        if ( bOneFrame )
          v29 = 0.041666668;
        else
          v29 = 0.1;
        KeyValues::SetFloat(this: v27, keyName: "maxLifetime", value: v29);
        v30 = KeyValues::FindKey(this: v23, keyName: "DmeConstantVelocityInitializer", bCreate: true);
        KeyValues::SetFloat(this: v30, keyName: "velocityX", value: 0.0);
        KeyValues::SetFloat(this: v30, keyName: "velocityY", value: 0.0);
        KeyValues::SetFloat(this: v30, keyName: "velocityZ", value: 0.0);
        v31 = KeyValues::FindKey(this: v23, keyName: "DmeRandomRollInitializer", bCreate: true);
        KeyValues::SetFloat(this: v31, keyName: "minRoll", value: 0.0);
        KeyValues::SetFloat(this: v31, keyName: "maxRoll", value: 360.0);
        v32 = KeyValues::FindKey(this: v23, keyName: "DmeRandomRollSpeedInitializer", bCreate: true);
        KeyValues::SetFloat(this: v32, keyName: "minRollSpeed", value: 0.0);
        KeyValues::SetFloat(this: v32, keyName: "maxRollSpeed", value: 0.0);
        v33 = KeyValues::FindKey(this: v23, keyName: "DmeRandomInterpolatedColorInitializer", bCreate: true);
        if ( pFlashColor != nullptr )
        {
          v34 = pFlashColor[2];
          v35 = pFlashColor[1];
          v36 = *pFlashColor;
        }
        else
        {
          v34 = -1;
          v35 = -1;
          v36 = -1;
        }
        color._color[1] = v35;
        color._color[0] = v36;
        color._color[2] = v34;
        color._color[3] = -1;
        KeyValues::SetColor(this: v33, keyName: "color1", value: color);
        KeyValues::SetColor(this: v33, keyName: "color2", value: color);
        v37 = KeyValues::FindKey(this: v23, keyName: "DmeRandomAlphaInitializer", bCreate: true);
        KeyValues::SetInt(this: v37, keyName: "minStartAlpha", value: 255);
        KeyValues::SetInt(this: v37, keyName: "maxStartAlpha", value: 255);
        KeyValues::SetInt(this: v37, keyName: "minEndAlpha", value: 128);
        KeyValues::SetInt(this: v37, keyName: "maxEndAlpha", value: 128);
        v38 = KeyValues::FindKey(this: v23, keyName: "DmeMuzzleFlashSizeInitializer", bCreate: true);
        colora = flScale * 0.11111111;
        v39 = v38;
        KeyValues::SetFloat(this: v38, keyName: "indexedBase", value: (float)(flScale * 0.11111111) * 4.0);
        KeyValues::SetFloat(this: v39, keyName: "indexedDelta", value: colora);
        KeyValues::SetFloat(this: v39, keyName: "minRandomFactor", value: 6.0);
        KeyValues::SetFloat(this: v39, keyName: "maxRandomFactor", value: 9.0);
        ToolFramework_PostToolMessage(hEntity: 0, msg: v21);
        KeyValues::deleteThis(this: v21);
      }
      break;
    }
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
LABEL_34:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10268BB0
// Name: void FX_GunshipImpact(class Vector const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshipImpact(const Vector *pos, const Vector *normal, float r, float g, float b)
{
  CGlowOverlay *v5; // eax
  CGlowOverlay *v6; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_GunshipImpact",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v5 = (CGlowOverlay *)MemAlloc_Alloc(nSize: 0xD8u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    CGlowOverlay::CGlowOverlay(this: v5);
    v6->__vftable = (CGlowOverlay_vtbl *)&CImpactOverlay::`vftable';
    v6[1].__vftable = nullptr;
    v6->m_vPos.x = pos->x + normal->x;
    v6->m_vPos.y = pos->y + normal->y;
    v6->m_vPos.z = pos->z + normal->z;
    v6->m_nSprites = 1;
    v6[1].m_vPos.x = r;
    v6[1].m_vPos.y = g;
    v6[1].m_vPos.z = b;
    v6->m_Sprites[0].m_flHorzSize = 0.0099999998;
    v6->m_Sprites[0].m_flVertSize = 0.0099999998;
    CGlowOverlay::Activate(this: v6);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10268C90
// Name: void GunshipImpactCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GunshipImpactCallback(const CEffectData *data)
{
  Vector vecPosition; // [esp+Ch] [ebp-18h] BYREF
  Vector normal; // [esp+18h] [ebp-Ch] BYREF

  vecPosition = data->m_vOrigin;
  normal.z = 1.0;
  normal.x = 0.0;
  normal.y = 0.0;
  FX_GunshipImpact(pos: &vecPosition, &normal, r: 100.0, g: 0.0, b: 200.0);
}

//------------------------------------------------------------------------------
// Address: 0x10268D10
// Name: void CommandPointerCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandPointerCallback(const CEffectData *data)
{
  int v1; // eax
  CGlowOverlay *v2; // eax
  CGlowOverlay *v3; // esi
  float b; // [esp+4h] [ebp-Ch]
  float g; // [esp+8h] [ebp-8h]
  float r; // [esp+Ch] [ebp-4h]

  v1 = 0;
  while ( commandercolors_0[v1].index != data->m_nColor )
  {
    if ( ++v1 >= 4 )
      return;
  }
  r = (float)commandercolors_0[v1].r;
  g = (float)commandercolors_0[v1].g;
  b = (float)commandercolors_0[v1].b;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_GunshipImpact",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v2 = (CGlowOverlay *)MemAlloc_Alloc(nSize: 0xD8u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CGlowOverlay::CGlowOverlay(this: v2);
    v3->__vftable = (CGlowOverlay_vtbl *)&CImpactOverlay::`vftable';
    v3[1].__vftable = nullptr;
    v3->m_vPos.x = data->m_vOrigin.x;
    v3->m_vPos.y = data->m_vOrigin.y;
    v3->m_vPos.z = data->m_vOrigin.z + 1.0;
    v3->m_nSprites = 1;
    v3[1].m_vPos.x = r;
    v3[1].m_vPos.y = g;
    v3[1].m_vPos.z = b;
    v3->m_Sprites[0].m_flHorzSize = 0.0099999998;
    v3->m_Sprites[0].m_flVertSize = 0.0099999998;
    CGlowOverlay::Activate(this: v3);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10268E40
// Name: void FX_GunshipMuzzleEffect(class Vector const __near &,class QAngle const __near &,float,class CBaseHandle,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshipMuzzleEffect(const Vector *origin, const QAngle *angles)
{
  CSimpleEmitter *m_pObj; // esi
  CParticleSubTexture *PMaterial; // eax
  Particle *v4; // eax
  Particle *v5; // esi
  char v6; // al
  Vector forward; // [esp+20h] [ebp-20h] BYREF
  Vector offset; // [esp+2Ch] [ebp-14h] BYREF
  int v9; // [esp+38h] [ebp-8h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+3Ch] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_GunshipMuzzleEffect",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash");
  CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: origin);
  AngleVectors(angles, &forward);
  offset = *origin;
  m_pObj = pSimple.m_pObj;
  PMaterial = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: "effects/gunshipmuzzle");
  v4 = CParticleEffect::AddParticle(this: m_pObj, particleSize: 0x3Cu, material: PMaterial, origin: &offset);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_QWORD *)&v4[1].m_Pos.y = 1041865114;
    v4[1].m_pPrev = nullptr;
    v4[1].m_pNext = nullptr;
    v4[1].m_pSubTexture = nullptr;
    v9 = (int)((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1109393408,
                a3: 1112014848);
    v6 = v9;
    BYTE1(v5[2].m_pNext) = v9;
    BYTE2(v5[2].m_pNext) = v6;
    v5[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    v5[2].m_pSubTexture = (CParticleSubTexture *)1041865114;
    v5[2].m_pPrev = (Particle *)-1;
    LOBYTE(v5[2].m_pNext) = -1;
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10268FA0
// Name: void FX_Tesla(class CTeslaInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_Tesla(int a1@<ebp>, const CTeslaInfo *teslaInfo)
{
  IUniformRandomStream *v2; // ecx
  int v3; // edi
  IUniformRandomStream *v4; // ecx
  double v5; // st7
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  float m_flRadius; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v12; // xmm1_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  const QAngle *v14; // eax
  float v15; // edi
  CParticleSubTexture *PMaterial; // eax
  Particle *v17; // eax
  IUniformRandomStream *v18; // ecx
  Particle *v19; // edi
  IUniformRandomStream *v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm1_4
  IUniformRandomStream *v23; // ecx
  float v24; // xmm1_4
  double v25; // st7
  char v26; // al
  IUniformRandomStream *v27; // ecx
  float m_flTimeVisible; // xmm2_4
  char *m_pszSpriteName; // edx
  float v30; // xmm1_4
  double v31; // xmm1_8
  Vector v32; // [esp+1Ch] [ebp-1C4h] BYREF
  CGameTrace tr; // [esp+28h] [ebp-1B8h] BYREF
  int v34[5]; // [esp+84h] [ebp-15Ch] BYREF
  Vector m_vPos; // [esp+98h] [ebp-148h]
  float v36; // [esp+A4h] [ebp-13Ch]
  float v37; // [esp+A8h] [ebp-138h]
  float v38; // [esp+ACh] [ebp-134h]
  int v39; // [esp+B0h] [ebp-130h]
  char *v40; // [esp+B4h] [ebp-12Ch]
  int v41; // [esp+B8h] [ebp-128h]
  int v42; // [esp+BCh] [ebp-124h]
  int v43; // [esp+C0h] [ebp-120h]
  float v44; // [esp+C4h] [ebp-11Ch]
  float m_flBeamWidth; // [esp+C8h] [ebp-118h]
  int v46; // [esp+CCh] [ebp-114h]
  int v47; // [esp+D0h] [ebp-110h]
  int v48; // [esp+D4h] [ebp-10Ch]
  int v49; // [esp+D8h] [ebp-108h]
  int v50; // [esp+DCh] [ebp-104h]
  int v51; // [esp+E0h] [ebp-100h]
  int v52; // [esp+E4h] [ebp-FCh]
  float v53; // [esp+E8h] [ebp-F8h]
  int v54; // [esp+ECh] [ebp-F4h]
  float v55; // [esp+F0h] [ebp-F0h]
  char v56; // [esp+F4h] [ebp-ECh]
  int v57; // [esp+F8h] [ebp-E8h]
  int v58; // [esp+FCh] [ebp-E4h]
  _DWORD v59[5]; // [esp+114h] [ebp-CCh] BYREF
  float v60; // [esp+128h] [ebp-B8h]
  float v61; // [esp+12Ch] [ebp-B4h]
  int v62; // [esp+134h] [ebp-ACh]
  int v63; // [esp+138h] [ebp-A8h]
  int v64; // [esp+13Ch] [ebp-A4h]
  int v65; // [esp+144h] [ebp-9Ch]
  int v66; // [esp+148h] [ebp-98h]
  int v67; // [esp+14Ch] [ebp-94h]
  int v68; // [esp+154h] [ebp-8Ch]
  char v69; // [esp+158h] [ebp-88h]
  bool v70; // [esp+159h] [ebp-87h]
  Vector v71; // [esp+16Ch] [ebp-74h] BYREF
  float v72[3]; // [esp+178h] [ebp-68h] BYREF
  float v73; // [esp+184h] [ebp-5Ch]
  int v74; // [esp+188h] [ebp-58h]
  QAngle m_vAngles; // [esp+190h] [ebp-50h] BYREF
  QAngle vecTemp; // [esp+19Ch] [ebp-44h]
  C_BaseEntity *pEntity; // [esp+1A8h] [ebp-38h] BYREF
  int iNumBeamsAround; // [esp+1ACh] [ebp-34h]
  float flYawOffset; // [esp+1B0h] [ebp-30h]
  Vector vecForward; // [esp+1B4h] [ebp-2Ch] BYREF
  Vector vecFlash; // [esp+1C0h] [ebp-20h] BYREF
  int j; // [esp+1CCh] [ebp-14h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+1D0h] [ebp-10h]
  int v84; // [esp+1D4h] [ebp-Ch]
  int i; // [esp+1D8h] [ebp-8h]
  int retaddr; // [esp+1E0h] [ebp+0h]

  v84 = a1;
  i = retaddr;
  LODWORD(vecTemp.x) = CClientEntityList::GetBaseEntity(
                         this: (CClientEntityList *)cl_entitylist.m_Index,
                         entnum: teslaInfo->m_nEntIndex);
  LODWORD(vecFlash.z) = teslaInfo->m_nBeams;
  LODWORD(vecTemp.y) = 2 * LODWORD(vecFlash.z) / 3;
  vecTemp.z = _RandomFloat(this: (IUniformRandomStream *)(2 * LODWORD(vecFlash.z)), a2: 0.0, a3: 360.0);
  v3 = 0;
  for ( j = 0; v3 < SLODWORD(vecFlash.z); j = v3 )
  {
    *(float *)&pSimple.m_pObj = NAN;
    do
    {
      ++pSimple.m_pObj;
      if ( v3 >= SLODWORD(vecTemp.y) )
      {
        v73 = _RandomFloat(this: v2, a2: -1.0, a3: 1.0);
        *(float *)&v74 = _RandomFloat(this: v6, a2: -1.0, a3: 1.0);
        v5 = _RandomFloat(this: v7, a2: -1.0, a3: 1.0);
        *(float *)&pEntity = v73;
        iNumBeamsAround = v74;
      }
      else
      {
        m_vAngles = teslaInfo->m_vAngles;
        m_vAngles.y = (float)((float)(unsigned __int16)(int)(float)((float)((float)(v3 * (360 / SLODWORD(vecFlash.z)))
                                                                          + vecTemp.z)
                                                                  * 182.04445)
                            * 0.0054931641)
                    + m_vAngles.y;
        AngleVectors(angles: &m_vAngles, forward: (Vector *)&pEntity);
        v5 = _RandomFloat(this: v4, a2: -1.0, a3: 1.0);
      }
      flYawOffset = v5;
      VectorNormalize(vec: (Vector *)&pEntity);
      m_flRadius = teslaInfo->m_flRadius;
      x = teslaInfo->m_vPos.x;
      y = teslaInfo->m_vPos.y;
      z = teslaInfo->m_vPos.z;
      v12 = (float)(teslaInfo->m_vPos.x + (float)(m_flRadius * *(float *)&pEntity)) - teslaInfo->m_vPos.x;
      v60 = (float)(y + (float)(*(float *)&iNumBeamsAround * m_flRadius)) - y;
      *(float *)&v59[4] = v12;
      v61 = (float)(z + (float)(m_flRadius * flYawOffset)) - z;
      v70 = (float)((float)((float)(v60 * v60) + (float)(v12 * v12)) + (float)(v61 * v61)) != 0.0;
      v67 = 0;
      v66 = 0;
      v65 = 0;
      v68 = 0;
      v69 = 1;
      v64 = 0;
      v63 = 0;
      v62 = 0;
      *(float *)v59 = x;
      *(float *)&v59[1] = y;
      *(float *)&v59[2] = z;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)&tr.m_pEnt,
        passedict: (const IHandleEntity *)LODWORD(vecTemp.x),
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      TraceRay = enginetrace->TraceRay;
      LODWORD(v32.y) = &v32;
      ((void (__thiscall *)(IEngineTrace *, _DWORD *, int, struct CBaseEntity **))TraceRay)(
        a1: enginetrace,
        a2: v59,
        a3: 1174421507,
        a4: &tr.m_pEnt);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v32, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
    }
    while ( tr.plane.normal.z >= 1.0 && (int)pSimple.m_pObj < 3 );
    if ( tr.plane.normal.z < 1.0 && EffectOccluded(pos: &tr.startpos, queryHandle: nullptr) == 0 )
    {
      vecForward = tr.startpos;
      v14 = MainViewAngles(nSlot: 0);
      AngleVectors(angles: v14, forward: &v71);
      vecForward.y = vecForward.y - (float)(v71.y * 8.0);
      vecForward.z = vecForward.z - (float)(v71.z * 8.0);
      vecForward.x = vecForward.x - (float)(v71.x * 8.0);
      v72[0] = -v71.x;
      v72[1] = -v71.y;
      v72[2] = -v71.z;
      g_pEffects->EnergySplash(this: g_pEffects, a2: &vecForward, a3: (const Vector *)v72, a4: false);
      CSimpleEmitter::Create(result: (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&vecFlash.y, pDebugName: "dust");
      CParticleEffect::SetSortOrigin(this: (CParticleEffect *)LODWORD(vecFlash.y), vSortOrigin: &vecForward);
      v15 = vecFlash.y;
      PMaterial = CParticleEffect::GetPMaterial(
                    this: (CParticleEffect *)LODWORD(vecFlash.y),
                    name: "effects/tesla_glow_noz");
      v17 = CParticleEffect::AddParticle(
              this: (CParticleEffect *)LODWORD(v15),
              particleSize: 0x3Cu,
              material: PMaterial,
              origin: &vecForward);
      v19 = v17;
      if ( v17 != nullptr )
      {
        v17[1].m_Pos.z = 0.0;
        v17[1].m_Pos.y = _RandomFloat(this: v18, a2: 0.5, a3: 1.0);
        *(Vector *)&v19[1].m_pPrev = vec3_origin;
        *(float *)&pSimple.m_pObj = _RandomFloat(this: v20, a2: 0.75, a3: 1.25);
        v21 = *(float *)&pSimple.m_pObj;
        if ( *(float *)&pSimple.m_pObj <= 1.0 )
          v22 = *(float *)&pSimple.m_pObj;
        else
          v22 = 1.0;
        v23 = (IUniformRandomStream *)(int)(float)(v22 * 255.0);
        LOBYTE(v19[2].m_pPrev) = (_BYTE)v23;
        if ( v21 <= 1.0 )
          v24 = v21;
        else
          v24 = 1.0;
        BYTE1(v19[2].m_pPrev) = (int)(float)(v24 * 255.0);
        if ( v21 > 1.0 )
          v21 = 1.0;
        BYTE2(v19[2].m_pPrev) = (int)(float)(v21 * 255.0);
        v25 = _RandomFloat(this: v23, a2: 6.0, a3: 13.0);
        v32.x = 360.0;
        LODWORD(vecFlash.x) = (int)v25;
        v26 = (int)v25;
        BYTE1(v19[2].m_pNext) = v26;
        BYTE2(v19[2].m_pNext) = v26 - 2;
        *(_WORD *)((char *)&v19[2].m_pPrev + 3) = 2815;
        v19[1].m_Pos.x = _RandomFloat(this: v27, a2: 0.0, a3: v32.x);
        v19[2].m_pSubTexture = nullptr;
      }
      if ( LODWORD(vecFlash.y) != 0 )
        CParticleEffect::Release(this: (CParticleEffect *)LODWORD(vecFlash.y));
      v3 = j;
    }
    m_vPos = teslaInfo->m_vPos;
    m_flTimeVisible = teslaInfo->m_flTimeVisible;
    v36 = tr.startpos.x;
    v37 = tr.startpos.y;
    m_pszSpriteName = teslaInfo->m_pszSpriteName;
    v38 = tr.startpos.z;
    v43 = 0;
    v50 = 0;
    v46 = 1065353216;
    v52 = 1065353216;
    v30 = teslaInfo->m_vColor.x * 255.0;
    v53 = v30;
    v31 = teslaInfo->m_vColor.y * 255.0;
    v44 = m_flTimeVisible;
    *(float *)&v31 = v31;
    m_flBeamWidth = teslaInfo->m_flBeamWidth;
    v54 = LODWORD(v31);
    *(float *)&v31 = teslaInfo->m_vColor.z;
    v47 = 1050253722;
    v42 = 0;
    v48 = 1098907648;
    v51 = 0;
    v39 = -1;
    v41 = -1;
    v40 = m_pszSpriteName;
    v34[0] = 9;
    v49 = 1128792064;
    v55 = *(float *)&v31 * 255.0;
    v57 = 20;
    v56 = 1;
    v58 = 256;
    beams->CreateBeamPoints_2(this: beams, a2: (BeamInfo_t *)v34);
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102696D0
// Name: void FX_BuildTeslaHitbox(class C_BaseEntity __near *,int,int,float,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_BuildTeslaHitbox(
        C_BaseEntity *pEntity,
        int nStartAttachment,
        int nEndAttachment,
        float flBeamWidth,
        const Vector *vColor)
{
  float v5; // xmm1_4
  float v6; // xmm1_4
  double z; // xmm1_8
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  const Vector *(__thiscall *WorldSpaceCenter)(C_BaseEntity *); // eax
  float *v12; // eax
  const Vector *(__thiscall *v13)(C_BaseEntity *); // edx
  const Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm1_4
  double v17; // xmm1_8
  IVEfx_vtbl *v18; // edi
  int v19; // eax
  int v20; // edi
  IUniformRandomStream *v21; // ecx
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  const Vector *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  int v27; // eax
  CGameTrace tr; // [esp+28h] [ebp-108h] BYREF
  Vector vecAbsEnd; // [esp+7Ch] [ebp-B4h] BYREF
  BeamInfo_t beamInfo; // [esp+88h] [ebp-A8h] BYREF
  Vector randomDir; // [esp+118h] [ebp-18h] BYREF
  Vector v32; // [esp+124h] [ebp-Ch]

  beamInfo.m_vecStart = vec3_origin;
  beamInfo.m_vecEnd = vec3_origin;
  beamInfo.m_flHaloScale = 8.0;
  beamInfo.m_flLife = 0.0099999998;
  beamInfo.m_nSegments = -1;
  beamInfo.m_pszHaloName = nullptr;
  beamInfo.m_nModelIndex = -1;
  beamInfo.m_nHaloIndex = -1;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nFlags = 0;
  beamInfo.m_nType = 9;
  beamInfo.m_pszModelName = "sprites/lgtning.vmt";
  beamInfo.m_flWidth = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(
                         a1: random,
                         a2: 1077936128);
  beamInfo.m_flEndWidth = 0.0;
  beamInfo.m_flFadeLength = 0.0;
  beamInfo.m_flAmplitude = (float)random->RandomInt(this: random, a2: 16, a3: 32);
  beamInfo.m_flBrightness = 255.0;
  beamInfo.m_flSpeed = 32.0;
  beamInfo.m_flFrameRate = 30.0;
  v5 = vColor->x * 255.0;
  beamInfo.m_flRed = v5;
  v6 = vColor->y * 255.0;
  beamInfo.m_flGreen = v6;
  z = vColor->z;
  beamInfo.m_nStartFrame = 0;
  beamInfo.m_flBlue = z * 255.0;
  beamInfo.m_nSegments = 32;
  beamInfo.m_bRenderable = true;
  beamInfo.m_nFlags = 1024;
  beamInfo.m_pStartEnt = pEntity;
  beamInfo.m_nStartAttachment = nStartAttachment;
  beamInfo.m_pEndEnt = pEntity;
  beamInfo.m_nEndAttachment = nEndAttachment;
  beams->CreateBeamEntPoint_2(this: beams, a2: &beamInfo);
  v32.x = _RandomFloat(this: v8, a2: -1.0, a3: 1.0);
  v32.y = _RandomFloat(this: v9, a2: -1.0, a3: 1.0);
  v32.z = _RandomFloat(this: v10, a2: -1.0, a3: 1.0);
  randomDir = v32;
  VectorNormalize(vec: &randomDir);
  WorldSpaceCenter = pEntity->WorldSpaceCenter;
  v32.x = randomDir.x * 100.0;
  v32.y = randomDir.y * 100.0;
  v32.z = randomDir.z * 100.0;
  v12 = (float *)WorldSpaceCenter(this: pEntity);
  vecAbsEnd.x = *v12 + v32.x;
  vecAbsEnd.y = v12[1] + v32.y;
  v13 = pEntity->WorldSpaceCenter;
  vecAbsEnd.z = v12[2] + v32.z;
  v14 = v13(this: pEntity);
  UTIL_TraceLine(vecAbsStart: v14, &vecAbsEnd, mask: 0x400Bu, ignore: pEntity, collisionGroup: 0, ptr: &tr);
  if ( tr.fraction < 1.0 )
  {
    beamInfo.m_vecStart = vec3_origin;
    beamInfo.m_vecEnd = tr.endpos;
    beamInfo.m_flHaloScale = 8.0;
    beamInfo.m_flLife = 0.050000001;
    beamInfo.m_nType = 9;
    beamInfo.m_pszModelName = "sprites/lgtning.vmt";
    beamInfo.m_flWidth = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 0x40000000,
                           a3: 1086324736);
    beamInfo.m_flEndWidth = 0.0;
    beamInfo.m_flFadeLength = 0.0;
    beamInfo.m_flAmplitude = (float)random->RandomInt(this: random, a2: 16, a3: 32);
    beamInfo.m_flBrightness = 255.0;
    beamInfo.m_flSpeed = 32.0;
    beamInfo.m_flFrameRate = 30.0;
    v15 = vColor->x * 255.0;
    beamInfo.m_flRed = v15;
    v16 = vColor->y * 255.0;
    beamInfo.m_flGreen = v16;
    v17 = vColor->z;
    beamInfo.m_nStartAttachment = nStartAttachment;
    beamInfo.m_nStartFrame = 0;
    beamInfo.m_flBlue = v17 * 255.0;
    beamInfo.m_nSegments = 32;
    beamInfo.m_bRenderable = true;
    beamInfo.m_pEndEnt = nullptr;
    beamInfo.m_pStartEnt = pEntity;
    beams->CreateBeamEntPoint_2(this: beams, a2: &beamInfo);
  }
  v18 = effects->__vftable;
  v19 = ((int (__thiscall *)(IClientNetworkable *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, _DWORD, _DWORD, _DWORD, int, C_BaseEntity *, int, C_BaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, const char *, int, const char *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD))pEntity->entindex)(
          a1: &pEntity->IClientNetworkable,
          a2: LODWORD(tr.startpos.x),
          a3: LODWORD(tr.startpos.y),
          a4: LODWORD(tr.startpos.z),
          a5: LODWORD(tr.endpos.x),
          a6: LODWORD(tr.endpos.y),
          a7: LODWORD(tr.endpos.z),
          a8: LODWORD(tr.plane.normal.x),
          a9: LODWORD(tr.plane.normal.y),
          a10: LODWORD(tr.plane.normal.z),
          a11: LODWORD(tr.plane.dist),
          a12: *(_DWORD *)&tr.plane.type,
          a13: LODWORD(tr.fraction),
          a14: tr.contents,
          a15: *(_DWORD *)&tr.dispFlags,
          a16: LODWORD(tr.fractionleftsolid),
          a17: tr.surface.name,
          a18: *(_DWORD *)&tr.surface.surfaceProps,
          a19: tr.hitgroup,
          a20: *(_DWORD *)&tr.physicsbone,
          a21: tr.m_pEnt,
          a22: tr.hitbox,
          a23: LODWORD(vecAbsEnd.x),
          a24: LODWORD(vecAbsEnd.y),
          a25: LODWORD(vecAbsEnd.z),
          a26: beamInfo.m_nType,
          a27: beamInfo.m_pStartEnt,
          a28: beamInfo.m_nStartAttachment,
          a29: beamInfo.m_pEndEnt,
          a30: beamInfo.m_nEndAttachment,
          a31: LODWORD(beamInfo.m_vecStart.x),
          a32: LODWORD(beamInfo.m_vecStart.y),
          a33: LODWORD(beamInfo.m_vecStart.z),
          a34: LODWORD(beamInfo.m_vecEnd.x),
          a35: LODWORD(beamInfo.m_vecEnd.y),
          a36: LODWORD(beamInfo.m_vecEnd.z),
          a37: beamInfo.m_nModelIndex,
          a38: beamInfo.m_pszModelName,
          a39: beamInfo.m_nHaloIndex,
          a40: beamInfo.m_pszHaloName,
          a41: LODWORD(beamInfo.m_flHaloScale),
          a42: LODWORD(beamInfo.m_flLife),
          a43: LODWORD(beamInfo.m_flWidth),
          a44: LODWORD(beamInfo.m_flEndWidth),
          a45: LODWORD(beamInfo.m_flFadeLength),
          a46: LODWORD(beamInfo.m_flAmplitude),
          a47: LODWORD(beamInfo.m_flBrightness),
          a48: LODWORD(beamInfo.m_flSpeed),
          a49: beamInfo.m_nStartFrame,
          a50: LODWORD(beamInfo.m_flFrameRate),
          a51: LODWORD(beamInfo.m_flRed),
          a52: LODWORD(beamInfo.m_flGreen),
          a53: LODWORD(beamInfo.m_flBlue),
          a54: *(_DWORD *)&beamInfo.m_bRenderable,
          a55: beamInfo.m_nSegments,
          a56: beamInfo.m_nFlags,
          a57: LODWORD(beamInfo.m_vecCenter.x),
          a58: LODWORD(beamInfo.m_vecCenter.y));
  v20 = (int)v18->CL_AllocElight(this: effects, a2: v19 + 0x10000000);
  v32.x = _RandomFloat(this: v21, a2: -32.0, a3: 32.0);
  v32.y = _RandomFloat(this: v22, a2: -32.0, a3: 32.0);
  v32.z = _RandomFloat(this: v23, a2: -32.0, a3: 32.0);
  v24 = pEntity->WorldSpaceCenter(this: pEntity);
  v25 = v24->y + v32.y;
  v26 = v24->z + v32.z;
  *(float *)(v20 + 4) = v32.x + v24->x;
  *(float *)(v20 + 8) = v25;
  *(float *)(v20 + 12) = v26;
  *(_DWORD *)(v20 + 20) = 83880939;
  v27 = random->RandomInt(this: random, a2: 32, a3: 128);
  *(float *)(v20 + 16) = (float)v27;
  *(float *)(v20 + 28) = (float)v27 * 10.0;
  *(float *)(v20 + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x10269C70
// Name: void FX_BuildTeslaHitbox(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_BuildTeslaHitbox(const CEffectData *data)
{
  CClientEntityList *m_Index; // esi
  int v2; // eax
  C_BaseEntity *BaseEntity; // eax
  int v4; // eax
  C_BaseAnimating *v5; // ebx
  IVModelInfoClient_vtbl *v6; // esi
  int v7; // eax
  int v8; // edi
  int v9; // esi
  float v10; // xmm0_4
  int v11; // edi
  int v12; // ebx
  matrix3x4_t *hitboxbones[256]; // [esp+34h] [ebp-414h] BYREF
  Vector vColor; // [esp+434h] [ebp-14h] BYREF
  C_BaseEntity *pEntity; // [esp+440h] [ebp-8h]
  int v16; // [esp+444h] [ebp-4h]

  m_Index = (CClientEntityList *)cl_entitylist.m_Index;
  vColor.x = 1.0;
  vColor.y = 1.0;
  vColor.z = 1.0;
  v2 = CEffectData::entindex(this: data);
  BaseEntity = CClientEntityList::GetBaseEntity(this: m_Index, entnum: v2);
  pEntity = BaseEntity;
  if ( BaseEntity != nullptr )
  {
    v4 = (int)BaseEntity->GetBaseAnimating(this: BaseEntity);
    v5 = (C_BaseAnimating *)v4;
    if ( v4 != 0 )
    {
      v6 = modelinfo->__vftable;
      v7 = (*(int (__thiscall **)(int))(*(_DWORD *)(v4 + 4) + 32))(a1: v4 + 4);
      v8 = (int)v6->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v7);
      if ( v8 != 0 )
      {
        v9 = v8 + *(_DWORD *)(v8 + 176) + 12 * C_BaseAnimating::GetHitboxSet(this: v5);
        if ( v9 != 0 && C_BaseAnimating::HitboxToWorldTransforms(this: v5, pHitboxToWorld: hitboxbones) != 0 )
        {
          v10 = data->m_flMagnitude + 0.5;
          if ( (int)v10 > 0 )
          {
            v16 = (int)v10;
            do
            {
              v11 = random->RandomInt(this: random, a2: 1, a3: *(_DWORD *)(v9 + 4));
              v12 = random->RandomInt(this: random, a2: 1, a3: *(_DWORD *)(v9 + 4));
              ((void (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1028443341,
                a3: 1045220557);
              FX_BuildTeslaHitbox(
                pEntity,
                nStartAttachment: v11,
                nEndAttachment: v12,
                flBeamWidth: data->m_flScale,
                &vColor);
              --v16;
            }
            while ( v16 != 0 );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269DD0
// Name: void FX_BuildSmoke(class Vector __near &,class QAngle __near &,class CBaseHandle,int,float,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_BuildSmoke(
        Vector *vecOrigin,
        QAngle *vecAngles,
        CBaseHandle hEntity,
        int nAttachment,
        float flLifeTime,
        const Vector4D *pColor)
{
  CSimpleEmitter *v6; // eax
  CSimpleEmitter *v7; // esi
  CSimpleEmitter *v8; // edi

  v6 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x138u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v6, pDebugName: "FX_Smoke");
    v7->__vftable = (CSimpleEmitter_vtbl *)&CSmokeEmitter::`vftable';
    v7[1].m_ParticleEffect.m_LocalSpaceTransform.m[1][1] = NAN;
    LODWORD(v7[1].m_ParticleEffect.m_LocalSpaceTransform.m[1][1]) = (CBaseHandle)hEntity.m_Index;
    LODWORD(v7[1].m_ParticleEffect.m_LocalSpaceTransform.m[1][2]) = nAttachment;
    v7[1].__vftable = nullptr;
    v7[1].m_pDebugName = nullptr;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = nullptr;
  if ( v7 != nullptr )
  {
    CParticleEffect::AddRef(this: v7);
    v8 = v7;
  }
  CParticleEffect::SetSortOrigin(this: v8, vSortOrigin: vecOrigin);
  *(float *)&v8[1].__vftable = *(float *)(gpGlobals.m_Index + 12) + flLifeTime;
  AngleVectors(angles: vecAngles, forward: (Vector *)&v8[1].m_ParticleEffect.IClientRenderable);
  *(Vector4D *)&v8[1].m_ParticleEffect.m_LocalSpaceTransform.m[0][1] = *pColor;
  v8[1].m_ParticleEffect.CParticleEffect::__vftable = (CParticleEffectBinding_vtbl *)1022739087;
  CSmokeEmitter::CreateSpurtParticles(this: (CSmokeEmitter *)v8);
  CParticleEffect::Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10269EC0
// Name: void SmokeCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmokeCallback(const CEffectData *data)
{
  float z; // edx
  __int64 v2; // xmm0_8
  unsigned int m_Index; // eax
  int m_nAttachmentIndex; // [esp-4h] [ebp-34h]
  Vector4D color; // [esp+8h] [ebp-28h] BYREF
  Vector vecOrigin; // [esp+18h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+24h] [ebp-Ch] BYREF

  z = data->m_vAngles.z;
  v2 = *(_QWORD *)&data->m_vOrigin.x;
  vecOrigin.z = data->m_vOrigin.z;
  vecAngles.z = z;
  m_nAttachmentIndex = data->m_nAttachmentIndex;
  *(_QWORD *)&vecOrigin.x = v2;
  m_Index = data->m_hEntity.m_Index;
  *(_QWORD *)&vecAngles.x = *(_QWORD *)&data->m_vAngles.x;
  color.x = 50.0;
  color.y = 50.0;
  color.z = 50.0;
  color.w = 255.0;
  FX_BuildSmoke(
    &vecOrigin,
    &vecAngles,
    hEntity: (CBaseHandle)m_Index,
    nAttachment: m_nAttachmentIndex,
    flLifeTime: 100.0,
    pColor: &color);
}

//------------------------------------------------------------------------------
// Address: 0x1026A070
// Name: void FX_Smoke(class Vector const __near &,class QAngle const __near &,float,int,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_Smoke(
        const Vector *origin,
        const QAngle *angles,
        float scale,
        int numParticles,
        unsigned __int8 *pColor,
        int iAlpha)
{
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  float (__thiscall *v10)(IUniformRandomStream *, float, float); // edx
  double v11; // st7
  unsigned __int8 v12; // al
  unsigned __int8 v13; // dl
  int v14; // edi
  int v15; // esi
  float v16; // xmm0_4
  float (__thiscall *v17)(IUniformRandomStream *, float, float); // eax
  float flDietime; // [esp+3Ch] [ebp-4Ch]
  Vector vecForward; // [esp+60h] [ebp-28h] BYREF
  Vector vecVelocity; // [esp+6Ch] [ebp-1Ch] BYREF
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> result; // [esp+78h] [ebp-10h] BYREF
  float flRoll; // [esp+7Ch] [ebp-Ch]
  float flRollDelta; // [esp+80h] [ebp-8h]
  int i; // [esp+84h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Smoke",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( numParticles > 0 )
  {
    for ( i = numParticles; i != 0; --i )
    {
      AngleVectors(angles, forward: &vecForward);
      vecVelocity.x = _RandomFloat(this: v6, a2: -0.5, a3: 0.5);
      vecVelocity.y = _RandomFloat(this: v7, a2: -0.5, a3: 0.5);
      vecVelocity.z = _RandomFloat(this: v8, a2: -0.5, a3: 0.5);
      vecVelocity.x = vecVelocity.x + vecForward.x;
      vecVelocity.y = vecForward.y + vecVelocity.y;
      vecVelocity.z = vecForward.z + vecVelocity.z;
      VectorNormalize(vec: &vecVelocity);
      RandomFloat = random->RandomFloat;
      vecForward.z = 32.0;
      flRollDelta = ((double (__thiscall *)(IUniformRandomStream *, int))RandomFloat)(a1: random, a2: 1098907648);
      vecVelocity.x = vecVelocity.x * flRollDelta;
      vecVelocity.z = flRollDelta * vecVelocity.z;
      vecVelocity.y = vecVelocity.y * flRollDelta;
      v10 = random->RandomFloat;
      vecForward.y = 16.0;
      v11 = ((double (__thiscall *)(IUniformRandomStream *, int))v10)(a1: random, a2: 1082130432);
      vecVelocity.z = v11 + vecVelocity.z;
      if ( pColor != nullptr )
      {
        v13 = pColor[1];
        v12 = pColor[2];
        LOBYTE(numParticles) = *pColor;
        BYTE1(numParticles) = v13;
      }
      else
      {
        v12 = random->RandomInt(this: random, a2: 64, a3: 164);
        LOBYTE(numParticles) = v12;
        BYTE1(numParticles) = v12;
      }
      v14 = iAlpha;
      BYTE2(numParticles) = v12;
      if ( iAlpha == -1 )
        v14 = random->RandomInt(this: random, a2: 10, a3: 25);
      v15 = (int)(float)((float)((int (__thiscall *)(IUniformRandomStream *, int))random->RandomInt)(a1: random, a2: 4)
                       * scale);
      v16 = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      v17 = random->RandomFloat;
      flRoll = v16;
      flRollDelta = ((double (__thiscall *)(IUniformRandomStream *, int, int))v17)(
                      a1: random,
                      a2: -1065353216,
                      a3: 1082130432);
      flDietime = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
      FX_Smoke(
        &result,
        origin,
        velocity: &vecVelocity,
        scale: (float)v15,
        numParticles: 1,
        flDietime,
        pColor: (unsigned __int8 *)0x3F000000,
        iAlpha: 0,
        pMaterial: (const char *)&numParticles,
        flRoll: *(float *)&v14,
        flRollDelta: (CParticleSubTexture *)"particle/particle_smokegrenade");
      if ( result.m_pObj != nullptr )
        CParticleEffect::Release(this: result.m_pObj);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1042CF10
// Name: PrecacheMuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheMuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheMuzzleFlashPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheMuzzleFlashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042CF80
// Name: MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int MuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  MuzzleFlashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&MuzzleFlashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042CFC0
// Name: SmokePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int SmokePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  SmokePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&SmokePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D000
// Name: GunshipImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int GunshipImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  GunshipImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&GunshipImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D040
// Name: CommandPointerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int CommandPointerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  CommandPointerPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&CommandPointerPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D080
// Name: TeslaHitboxesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int TeslaHitboxesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  TeslaHitboxesPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&TeslaHitboxesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D0C0
// Name: TeslaZapPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int TeslaZapPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  TeslaZapPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&TeslaZapPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10269F40
// Name: class CSmartPtr<class CSimpleEmitter,class CRefCountAccessor> FX_Smoke(class Vector const __near &,class Vector const __near &,float,int,float,unsigned char __near *,int,char const __near *,float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CSimpleEmitter,CRefCountAccessor> *__cdecl FX_Smoke(
        CSmartPtr<CSimpleEmitter,CRefCountAccessor> *result,
        const Vector *origin,
        const Vector *velocity,
        float scale,
        int numParticles,
        float flDietime,
        unsigned __int8 *pColor,
        char iAlpha,
        const char *pMaterial,
        float flRoll,
        CParticleSubTexture *flRollDelta)
{
  int v11; // ebx
  CParticleSubTexture *v12; // eax
  Particle *v13; // eax
  CSimpleEmitter *m_pObj; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v15; // esi
  CSimpleEmitter *v16; // edi
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+Ch] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Smoke",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "FX_Smoke");
  CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: origin);
  v11 = 0;
  if ( numParticles <= 0 )
  {
LABEL_4:
    m_pObj = pSimple.m_pObj;
    v15 = result;
    result->m_pObj = nullptr;
    v16 = m_pObj;
    if ( m_pObj == nullptr )
      goto LABEL_10;
    CParticleEffect::AddRef(this: m_pObj);
    if ( result->m_pObj != nullptr )
      CParticleEffect::Release(this: result->m_pObj);
    result->m_pObj = v16;
  }
  else
  {
    while ( 1 )
    {
      v12 = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: pMaterial);
      v13 = CParticleEffect::AddParticle(this: pSimple.m_pObj, particleSize: 0x3Cu, material: v12, origin);
      if ( v13 == nullptr )
        break;
      v13[1].m_Pos.z = 0.0;
      v13[1].m_Pos.y = flDietime;
      *(Vector *)&v13[1].m_pPrev = *velocity;
      ++v11;
      LOBYTE(v13[2].m_pPrev) = *pColor;
      BYTE1(v13[2].m_pPrev) = pColor[1];
      BYTE2(v13[2].m_pPrev) = pColor[2];
      HIBYTE(v13[2].m_pPrev) = iAlpha;
      BYTE1(v13[2].m_pNext) = (int)scale;
      v13[1].m_Pos.x = flRoll;
      LOBYTE(v13[2].m_pNext) = 0;
      BYTE2(v13[2].m_pNext) = 2 * (int)scale;
      v13[2].m_pSubTexture = flRollDelta;
      if ( v11 >= numParticles )
        goto LABEL_4;
    }
    v15 = result;
    result->m_pObj = nullptr;
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
LABEL_10:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x1042CFA0
// Name: _dynamic_initializer_for__ClientEffectReg_SmokeCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_SmokeCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_SmokeCallback,
           pEffectName: "Smoke",
           fn: SmokeCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042CFE0
// Name: _dynamic_initializer_for__ClientEffectReg_GunshipImpactCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_GunshipImpactCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_GunshipImpactCallback,
           pEffectName: "GunshipImpact",
           fn: GunshipImpactCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042D020
// Name: _dynamic_initializer_for__ClientEffectReg_CommandPointerCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CommandPointerCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CommandPointerCallback,
           pEffectName: "CommandPointer",
           fn: CommandPointerCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042D060
// Name: _dynamic_initializer_for__ClientEffectReg_FX_BuildTeslaHitbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_FX_BuildTeslaHitbox__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_FX_BuildTeslaHitbox,
           pEffectName: "TeslaHitboxes",
           fn: FX_BuildTeslaHitbox);
}

//------------------------------------------------------------------------------
// Address: 0x1042D0A0
// Name: _dynamic_initializer_for__ClientEffectReg_FX_BuildTeslaZap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_FX_BuildTeslaZap__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_FX_BuildTeslaZap,
           pEffectName: "TeslaZap",
           fn: FX_BuildTeslaZap);
}
