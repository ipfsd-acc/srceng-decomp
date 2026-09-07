// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/world.cpp
// Functions: 15
// ============================================================

#include "engine\world.h"

//------------------------------------------------------------------------------
// Address: 0x101F5AC0
// Name: void SV_ClearWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ClearWorld()
{
  IMDLCache *v0; // edi
  CStaticPropMgr *v1; // eax
  model_t *worldmodel; // eax
  int i; // esi
  CSpatialPartition *v4; // eax
  CStaticPropMgr *v5; // eax

  v0 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
  v1 = StaticPropMgr();
  v1->LevelShutdown(this: v1);
  worldmodel = host_state.worldmodel;
  for ( i = 292; i < 304; i += 4 )
  {
    if ( *(float *)((char *)worldmodel + i - 12) < -16384.0 || *(float *)((char *)&worldmodel->fnHandle + i) > 16384.0 )
    {
      Host_EndGame(bShowMainMenu: true, message: "Map coordinate extents are too large!!\nCheck for errors!\n");
      worldmodel = host_state.worldmodel;
    }
  }
  v4 = SpatialPartition();
  v4->Init(this: v4, a2: &host_state.worldmodel->mins, a3: &host_state.worldmodel->maxs);
  v5 = StaticPropMgr();
  v5->LevelInit(this: v5);
  g_pShadowMgr->LevelInit(this: g_pShadowMgr, a2: host_state.worldbrush->numsurfaces);
  v0->EndCoarseLock(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x101F5BA0
// Name: CM_GetCollideableTriggerTestBox
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_GetCollideableTriggerTestBox(
        Vector *pMins@<edi>,
        Vector *pMaxs@<esi>,
        ICollideable *pCollide,
        bool bUseAccurateBbox)
{
  const Vector *v4; // eax
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // edx
  const Vector *vecStart; // [esp+10h] [ebp+Ch]

  if ( bUseAccurateBbox && pCollide->GetSolid(this: pCollide) == SOLID_BBOX )
  {
    v4 = pCollide->OBBMins(this: pCollide);
    pMins->x = v4->x;
    pMins->y = v4->y;
    OBBMaxs = pCollide->OBBMaxs;
    pMins->z = v4->z;
    *pMaxs = *OBBMaxs(this: pCollide);
  }
  else
  {
    vecStart = pCollide->GetCollisionOrigin(this: pCollide);
    pCollide->WorldSpaceSurroundingBounds(this: pCollide, a2: pMins, a3: pMaxs);
    pMins->x = pMins->x - vecStart->x;
    pMins->y = pMins->y - vecStart->y;
    pMins->z = pMins->z - vecStart->z;
    pMaxs->x = pMaxs->x - vecStart->x;
    pMaxs->y = pMaxs->y - vecStart->y;
    pMaxs->z = pMaxs->z - vecStart->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5C70
// Name: public: void CTriggerMoved::TriggerMoved(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMoved::TriggerMoved(CTriggerMoved *this, edict_t *pTriggerEntity)
{
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v4; // eax
  int v5; // eax
  ICollideable *m_pTrigger; // edi
  ISpatialPartitionInternal *v7; // eax
  Vector vecAbsMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->m_pTriggerEntity = pTriggerEntity;
  if ( (pTriggerEntity->m_fStateFlags & 4) != 0 && (m_pUnk = pTriggerEntity->m_pUnk) != nullptr )
    v4 = m_pUnk->GetCollideable(this: m_pUnk);
  else
    v4 = nullptr;
  this->m_pTrigger = v4;
  v5 = v4->GetSolidFlags(this: v4);
  m_pTrigger = this->m_pTrigger;
  this->m_triggerSolidFlags = v5;
  if ( (m_pTrigger->GetSolidFlags(this: m_pTrigger) & 0x80u) == 0 )
    CM_WorldSpaceBounds(pCollideable: m_pTrigger, pMins: &vecAbsMins, pMaxs: &vecAbsMaxs);
  else
    m_pTrigger->WorldSpaceTriggerBounds(this: m_pTrigger, a2: &vecAbsMins, a3: &vecAbsMaxs);
  v7 = SpatialPartition();
  v7->EnumerateElementsInBox(this: v7, a2: 1, a3: &vecAbsMins, a4: &vecAbsMaxs, a5: false, a6: this);
}

//------------------------------------------------------------------------------
// Address: 0x101F5D00
// Name: public: void CTriggerMoved_ClientSide::TriggerMoved(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMoved_ClientSide::TriggerMoved(CTriggerMoved_ClientSide *this, IClientEntity *pTriggerEntity)
{
  ICollideable *v3; // eax
  int v4; // eax
  ICollideable *m_pTrigger; // edi
  ISpatialPartitionInternal *v6; // eax
  Vector vecAbsMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->m_pTriggerEntity = pTriggerEntity;
  v3 = pTriggerEntity->GetCollideable(this: pTriggerEntity);
  this->m_pTrigger = v3;
  v4 = v3->GetSolidFlags(this: v3);
  m_pTrigger = this->m_pTrigger;
  this->m_triggerSolidFlags = v4;
  if ( (m_pTrigger->GetSolidFlags(this: m_pTrigger) & 0x80u) == 0 )
    CM_WorldSpaceBounds(pCollideable: m_pTrigger, pMins: &vecAbsMins, pMaxs: &vecAbsMaxs);
  else
    m_pTrigger->WorldSpaceTriggerBounds(this: m_pTrigger, a2: &vecAbsMins, a3: &vecAbsMaxs);
  v6 = SpatialPartition();
  v6->EnumerateElementsInBox(this: v6, a2: 4, a3: &vecAbsMins, a4: &vecAbsMaxs, a5: false, a6: this);
}

//------------------------------------------------------------------------------
// Address: 0x101F5D80
// Name: public: CTouchLinks::CTouchLinks(struct edict_t __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CTouchLinks *__thiscall CTouchLinks::CTouchLinks(
        CTouchLinks *this,
        edict_t *pEnt,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  edict_t **v5; // eax
  IServerUnknown *m_pUnk; // eax
  ICollideable *v7; // eax
  unsigned int v8; // eax
  const Vector *v9; // eax
  ICollideable *m_pCollide; // [esp-Ch] [ebp-2Ch]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->__vftable = (CTouchLinks_vtbl *)&CTouchLinks::`vftable';
  this->m_Ray.m_pWorldAxisTransform = nullptr;
  this->m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  this->m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  this->m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v5 = (edict_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_TouchedEntities.m_Memory.m_pMemory = v5;
  this->m_TouchedEntities.m_pElements = v5;
  this->m_TouchedEntities.m_Size = 0;
  this->m_pEnt = pEnt;
  if ( (pEnt->m_fStateFlags & 4) != 0 && (m_pUnk = pEnt->m_pUnk) != nullptr )
    v7 = m_pUnk->GetCollideable(this: m_pUnk);
  else
    v7 = nullptr;
  this->m_pCollide = v7;
  v8 = v7->GetRequiredTriggerFlags(this: v7);
  m_pCollide = this->m_pCollide;
  this->m_nRequiredTriggerFlags = v8;
  CM_GetCollideableTriggerTestBox(
    pCollide: m_pCollide,
    pMins: &vecMins,
    pMaxs: &vecMaxs,
    bUseAccurateBbox: accurateBboxTriggerChecks);
  v9 = this->m_pCollide->GetCollisionOrigin(this: this->m_pCollide);
  if ( pPrevAbsOrigin != nullptr )
    Ray_t::Init(this: &this->m_Ray, start: pPrevAbsOrigin, end: v9, mins: &vecMins, maxs: &vecMaxs);
  else
    Ray_t::Init(this: &this->m_Ray, start: v9, end: v9, mins: &vecMins, maxs: &vecMaxs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F5E50
// Name: public: CTouchLinks_ClientSide::CTouchLinks_ClientSide(class IClientEntity __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CTouchLinks_ClientSide *__thiscall CTouchLinks_ClientSide::CTouchLinks_ClientSide(
        CTouchLinks_ClientSide *this,
        IClientEntity *pEnt,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  IClientEntity **v5; // eax
  ICollideable *v6; // eax
  unsigned int v7; // eax
  const Vector *v8; // eax
  ICollideable *m_pCollide; // [esp-8h] [ebp-2Ch]
  Vector vecMins; // [esp+Ch] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-Ch] BYREF

  this->__vftable = (CTouchLinks_ClientSide_vtbl *)&CTouchLinks_ClientSide::`vftable';
  this->m_Ray.m_pWorldAxisTransform = nullptr;
  this->m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  this->m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  this->m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v5 = (IClientEntity **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_TouchedEntities.m_Memory.m_pMemory = v5;
  this->m_TouchedEntities.m_pElements = v5;
  this->m_TouchedEntities.m_Size = 0;
  this->m_pEnt = pEnt;
  v6 = pEnt->GetCollideable(this: pEnt);
  this->m_pCollide = v6;
  v7 = v6->GetRequiredTriggerFlags(this: v6);
  m_pCollide = this->m_pCollide;
  this->m_nRequiredTriggerFlags = v7;
  CM_GetCollideableTriggerTestBox(
    pCollide: m_pCollide,
    pMins: &vecMins,
    pMaxs: &vecMaxs,
    bUseAccurateBbox: accurateBboxTriggerChecks);
  v8 = this->m_pCollide->GetCollisionOrigin(this: this->m_pCollide);
  if ( pPrevAbsOrigin != nullptr )
    Ray_t::Init(this: &this->m_Ray, start: pPrevAbsOrigin, end: v8, mins: &vecMins, maxs: &vecMaxs);
  else
    Ray_t::Init(this: &this->m_Ray, start: v8, end: v8, mins: &vecMins, maxs: &vecMaxs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F5F10
// Name: public: virtual enum IterationRetval_t CTouchLinks::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IterationRetval_t __userpurge CTouchLinks::EnumElement@<eax>(
        CTouchLinks *this@<ecx>,
        int a2@<ebp>,
        IHandleEntity *pHandleEntity)
{
  int v4; // eax
  edict_t *v5; // eax
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v7; // esi
  int v8; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_TouchedEntities; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v14; // eax
  S3RGBA *v15; // edi
  int v16; // [esp-Ch] [ebp-C4h] BYREF
  _BYTE tr_36[72]; // [esp+24h] [ebp-94h] OVERLAPPED BYREF
  _BYTE v18[32]; // [esp+6Ch] [ebp-4Ch] OVERLAPPED BYREF
  __m128 v19; // [esp+8Ch] [ebp-2Ch] BYREF
  edict_t *v20; // [esp+A8h] [ebp-10h]
  int v21; // [esp+ACh] [ebp-Ch]
  void *v22; // [esp+B0h] [ebp-8h]
  void *retaddr; // [esp+B8h] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  if ( this->m_nRequiredTriggerFlags != 0 )
  {
    v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
    v5 = (edict_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    v20 = v5;
    if ( v5 != this->m_pEnt && (v5->m_fStateFlags & 4) != 0 )
    {
      m_pUnk = v5->m_pUnk;
      if ( m_pUnk != nullptr )
      {
        v7 = m_pUnk->GetCollideable(this: m_pUnk);
        v8 = v7->GetSolidFlags(this: v7);
        if ( (v8 & this->m_nRequiredTriggerFlags) == this->m_nRequiredTriggerFlags )
        {
          if ( (v8 & 0x80u) != 0 )
          {
            v7->WorldSpaceTriggerBounds(this: v7, a2: (Vector *)v18, a3: (Vector *)&tr_36[40]);
            v19 = Four_Zeros;
            *(_OWORD *)&v18[16] = *(_OWORD *)&tr_36[40];
            *(_OWORD *)&tr_36[56] = *(_OWORD *)v18;
            if ( !IsBoxIntersectingRay(
                    boxMin: (const __m128 *)&tr_36[56],
                    boxMax: (const __m128 *)&v18[16],
                    ray: &this->m_Ray,
                    fl4Tolerance: &v19) )
              return ITERATION_CONTINUE;
            goto LABEL_10;
          }
          g_pEngineTraceServer->ClipRayToCollideable(
            this: g_pEngineTraceServer,
            a2: &this->m_Ray,
            a3: 33570827u,
            a4: v7,
            a5: (CGameTrace *)&v16);
          if ( (*(_DWORD *)tr_36 & 0x200400B) != 0 )
          {
LABEL_10:
            m_nAllocationCount = this->m_TouchedEntities.m_Memory.m_nAllocationCount;
            p_m_TouchedEntities = (CUtlMemory<S3RGBA,int> *)&this->m_TouchedEntities;
            m_Size = this->m_TouchedEntities.m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<INetMessage *,int>::Grow(this: p_m_TouchedEntities, num: m_Size - m_nAllocationCount + 1);
            ++p_m_TouchedEntities[1].m_pMemory;
            m_pMemory = p_m_TouchedEntities->m_pMemory;
            v14 = (int)p_m_TouchedEntities[1].m_pMemory - m_Size - 1;
            p_m_TouchedEntities[1].m_nAllocationCount = (int)p_m_TouchedEntities->m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
            v15 = &p_m_TouchedEntities->m_pMemory[m_Size];
            if ( v15 != nullptr )
              *v15 = (S3RGBA)v20;
          }
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6070
// Name: public: virtual enum IterationRetval_t CTouchLinks_ClientSide::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IterationRetval_t __userpurge CTouchLinks_ClientSide::EnumElement@<eax>(
        CTouchLinks_ClientSide *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IClientEntity *v6; // eax
  int v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_TouchedEntities; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v13; // eax
  S3RGBA *v14; // edi
  _BYTE tr_36[72]; // [esp+24h] [ebp-94h] OVERLAPPED BYREF
  _BYTE v18[32]; // [esp+6Ch] [ebp-4Ch] OVERLAPPED BYREF
  __m128 v19; // [esp+8Ch] [ebp-2Ch] BYREF
  IClientEntity *v20; // [esp+A8h] [ebp-10h]
  int v21; // [esp+ACh] [ebp-Ch]
  void *v22; // [esp+B0h] [ebp-8h]
  void *retaddr; // [esp+B8h] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  if ( this->m_nRequiredTriggerFlags != 0 )
  {
    v6 = (IClientEntity *)((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].dtr_IHandleEntity)(a1: pHandleEntity);
    v20 = v6;
    if ( v6 != this->m_pEnt )
    {
      v7 = (int)v6->GetCollideable(this: v6);
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 48))(a1: v7) & this->m_nRequiredTriggerFlags) != this->m_nRequiredTriggerFlags )
        goto LABEL_8;
      if ( (*(char (__thiscall **)(int, int, int))(*(_DWORD *)v7 + 48))(a1: v7, a2: a3, a3: a4) < 0 )
      {
        (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)v7 + 12))(a1: v7, a2: v18, a3: &tr_36[40]);
        v19 = Four_Zeros;
        *(_OWORD *)&v18[16] = *(_OWORD *)&tr_36[40];
        *(_OWORD *)&tr_36[56] = *(_OWORD *)v18;
        if ( !IsBoxIntersectingRay(
                boxMin: (const __m128 *)&tr_36[56],
                boxMax: (const __m128 *)&v18[16],
                ray: &this->m_Ray,
                fl4Tolerance: &v19) )
          return ITERATION_CONTINUE;
        goto LABEL_8;
      }
      ((void (__thiscall *)(IEngineTrace *, Ray_t *, int))g_pEngineTraceClient->ClipRayToCollideable)(
        a1: g_pEngineTraceClient,
        a2: &this->m_Ray,
        a3: 33570827);
      if ( (*(_DWORD *)tr_36 & 0x200400B) != 0 )
      {
LABEL_8:
        m_nAllocationCount = this->m_TouchedEntities.m_Memory.m_nAllocationCount;
        p_m_TouchedEntities = (CUtlMemory<S3RGBA,int> *)&this->m_TouchedEntities;
        m_Size = this->m_TouchedEntities.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: p_m_TouchedEntities, num: m_Size - m_nAllocationCount + 1);
        ++p_m_TouchedEntities[1].m_pMemory;
        m_pMemory = p_m_TouchedEntities->m_pMemory;
        v13 = (int)p_m_TouchedEntities[1].m_pMemory - m_Size - 1;
        p_m_TouchedEntities[1].m_nAllocationCount = (int)p_m_TouchedEntities->m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
        v14 = &p_m_TouchedEntities->m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = (S3RGBA)v20;
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F61C0
// Name: public: virtual enum IterationRetval_t CTriggerMoved::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IterationRetval_t __userpurge CTriggerMoved::EnumElement@<eax>(
        CTriggerMoved *this@<ecx>,
        ICollideable *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v6; // eax
  int v7; // eax
  float v8; // eax
  IHandleEntity_vtbl *v9; // edx
  ICollideable *v10; // eax
  ICollideable *v11; // esi
  int v12; // eax
  const Vector *v13; // eax
  float y; // esi
  int v15; // ecx
  void (__thiscall *v16)(int, _BYTE *); // eax
  void (__thiscall *ClipRayToCollideable)(IEngineTrace *, const Ray_t *, unsigned int, ICollideable *, CGameTrace *); // eax
  int v19; // edi
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  float *v23; // edi
  int v25; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-128h] BYREF
  _BYTE ray_52[48]; // [esp+8Ch] [ebp-9Ch] OVERLAPPED BYREF
  __m128 v28; // [esp+BCh] [ebp-6Ch] BYREF
  __m128 v29; // [esp+CCh] [ebp-5Ch] BYREF
  _BYTE v30[17]; // [esp+E8h] [ebp-40h] OVERLAPPED BYREF
  Vector vecMins; // [esp+104h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+110h] [ebp-18h]
  ICollideable *pTouchCollide; // [esp+11Ch] [ebp-Ch]
  void *v34; // [esp+120h] [ebp-8h]
  void *retaddr; // [esp+128h] [ebp+0h]

  pTouchCollide = a2;
  v34 = retaddr;
  LODWORD(vecMaxs.y) = this;
  v6 = StaticPropMgr();
  if ( ((unsigned __int8 (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, int, int))v6->IsStaticProp_2)(
         a1: v6,
         a2: pHandleEntity,
         a3,
         a4) == 0 )
  {
    v7 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
    v8 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7));
    v9 = pHandleEntity->__vftable;
    vecMaxs.z = v8;
    v10 = (ICollideable *)((int (__thiscall *)(IHandleEntity *))v9[1].dtr_IHandleEntity)(a1: pHandleEntity);
    v11 = v10;
    LODWORD(vecMaxs.x) = v10;
    if ( v10 != this->m_pTrigger )
    {
      v12 = v10->GetRequiredTriggerFlags(this: v10);
      if ( v12 != 0
        && (v12 & this->m_triggerSolidFlags) == v12
        && (*(_BYTE *)LODWORD(vecMaxs.z) & 4) != 0
        && *(_DWORD *)(LODWORD(vecMaxs.z) + 12) != 0 )
      {
        CM_GetCollideableTriggerTestBox(
          pCollide: v11,
          pMins: (Vector *)&v30[16],
          pMaxs: &vecMins,
          bUseAccurateBbox: this->m_bAccurateBBoxCheck);
        v13 = (const Vector *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(vecMaxs.x) + 32))(
                                a1: LODWORD(vecMaxs.x),
                                a2: LODWORD(vecMaxs.z));
        *(_DWORD *)ray_52 = 0;
        Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: v13, end: v13, mins: (const Vector *)&v30[16], maxs: &vecMins);
        y = vecMaxs.y;
        if ( (*(char (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(vecMaxs.y) + 8) + 48))(a1: *(_DWORD *)(LODWORD(vecMaxs.y) + 8)) < 0 )
        {
          v15 = *(_DWORD *)(LODWORD(y) + 8);
          v16 = *(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v15 + 12);
          LODWORD(vecMaxs.z) = v30;
          v16(a1: v15, a2: &ray_52[16]);
          *(__m128 *)&ray_52[32] = Four_Zeros;
          v29 = *(__m128 *)v30;
          v28 = *(__m128 *)&ray_52[16];
          if ( !IsBoxIntersectingRay(
                  boxMin: &v28,
                  boxMax: &v29,
                  ray: (const Ray_t *)&tr.m_pEnt,
                  fl4Tolerance: (const __m128 *)&ray_52[32]) )
            return ITERATION_CONTINUE;
          goto LABEL_11;
        }
        ClipRayToCollideable = g_pEngineTraceServer->ClipRayToCollideable;
        LODWORD(vecMaxs.z) = &v25;
        ((void (__thiscall *)(IEngineTrace *, struct CBaseEntity **, int, _DWORD))ClipRayToCollideable)(
          a1: g_pEngineTraceServer,
          a2: &tr.m_pEnt,
          a3: 33570827,
          a4: *(_DWORD *)(LODWORD(y) + 8));
        if ( (LODWORD(tr.plane.dist) & 0x200400B) != 0 )
        {
LABEL_11:
          v19 = *(_DWORD *)(LODWORD(y) + 40);
          v20 = *(_DWORD *)(LODWORD(y) + 32);
          if ( v19 + 1 > v20 )
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(LODWORD(y) + 28), num: v19 - v20 + 1);
          ++*(_DWORD *)(LODWORD(y) + 40);
          v21 = *(_DWORD *)(LODWORD(y) + 28);
          v22 = *(_DWORD *)(LODWORD(y) + 40) - v19 - 1;
          *(_DWORD *)(LODWORD(y) + 44) = v21;
          if ( v22 > 0 )
            _V_memmove(dest: (void *)(v21 + 4 * v19 + 4), src: (const void *)(v21 + 4 * v19), count: 4 * v22);
          v23 = (float *)(*(_DWORD *)(LODWORD(y) + 28) + 4 * v19);
          if ( v23 != nullptr )
            *v23 = vecMaxs.z;
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6390
// Name: public: virtual enum IterationRetval_t CTriggerMoved_ClientSide::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IterationRetval_t __userpurge CTriggerMoved_ClientSide::EnumElement@<eax>(
        CTriggerMoved_ClientSide *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v6; // eax
  int v7; // eax
  ICollideable *v8; // eax
  ICollideable *v9; // esi
  int v10; // eax
  const Vector *v11; // eax
  float x; // esi
  int v13; // ecx
  void (__thiscall *v14)(int, _BYTE *); // eax
  void (__thiscall *ClipRayToCollideable)(IEngineTrace *, const Ray_t *, unsigned int, ICollideable *, CGameTrace *); // eax
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  float *v21; // edi
  int v23; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-128h] BYREF
  _BYTE ray_52[48]; // [esp+8Ch] [ebp-9Ch] OVERLAPPED BYREF
  __m128 v26; // [esp+BCh] [ebp-6Ch] BYREF
  __m128 v27; // [esp+CCh] [ebp-5Ch] BYREF
  _BYTE v28[17]; // [esp+E8h] [ebp-40h] OVERLAPPED BYREF
  Vector vecMins; // [esp+104h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+110h] [ebp-18h]
  int v31; // [esp+11Ch] [ebp-Ch]
  ICollideable *pTouchCollide; // [esp+120h] [ebp-8h]
  ICollideable *retaddr; // [esp+128h] [ebp+0h]

  v31 = a2;
  pTouchCollide = retaddr;
  LODWORD(vecMaxs.x) = this;
  v6 = StaticPropMgr();
  if ( ((unsigned __int8 (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, int, int))v6->IsStaticProp_2)(
         a1: v6,
         a2: pHandleEntity,
         a3,
         a4) == 0 )
  {
    v7 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].dtr_IHandleEntity)(a1: pHandleEntity);
    v8 = (ICollideable *)((int (__thiscall *)(IHandleEntity *, int))pHandleEntity->__vftable[1].dtr_IHandleEntity)(
                           a1: pHandleEntity,
                           a2: v7);
    v9 = v8;
    LODWORD(vecMaxs.y) = v8;
    if ( v8 != this->m_pTrigger )
    {
      v10 = v8->GetRequiredTriggerFlags(this: v8);
      if ( v10 != 0 && (v10 & this->m_triggerSolidFlags) == v10 )
      {
        CM_GetCollideableTriggerTestBox(
          pCollide: v9,
          pMins: (Vector *)&v28[16],
          pMaxs: &vecMins,
          bUseAccurateBbox: this->m_bAccurateBBoxCheck);
        v11 = (const Vector *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(vecMaxs.y) + 32))(
                                a1: LODWORD(vecMaxs.y),
                                a2: LODWORD(vecMaxs.z));
        *(_DWORD *)ray_52 = 0;
        Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: v11, end: v11, mins: (const Vector *)&v28[16], maxs: &vecMins);
        x = vecMaxs.x;
        if ( (*(char (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(vecMaxs.x) + 8) + 48))(a1: *(_DWORD *)(LODWORD(vecMaxs.x) + 8)) < 0 )
        {
          v13 = *(_DWORD *)(LODWORD(x) + 8);
          v14 = *(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 12);
          LODWORD(vecMaxs.z) = v28;
          v14(a1: v13, a2: &ray_52[16]);
          *(__m128 *)&ray_52[32] = Four_Zeros;
          v27 = *(__m128 *)v28;
          v26 = *(__m128 *)&ray_52[16];
          if ( !IsBoxIntersectingRay(
                  boxMin: &v26,
                  boxMax: &v27,
                  ray: (const Ray_t *)&tr.m_pEnt,
                  fl4Tolerance: (const __m128 *)&ray_52[32]) )
            return ITERATION_CONTINUE;
          goto LABEL_9;
        }
        ClipRayToCollideable = g_pEngineTraceClient->ClipRayToCollideable;
        LODWORD(vecMaxs.z) = &v23;
        ((void (__thiscall *)(IEngineTrace *, struct CBaseEntity **, int, _DWORD))ClipRayToCollideable)(
          a1: g_pEngineTraceClient,
          a2: &tr.m_pEnt,
          a3: 33570827,
          a4: *(_DWORD *)(LODWORD(x) + 8));
        if ( (LODWORD(tr.plane.dist) & 0x200400B) != 0 )
        {
LABEL_9:
          v17 = *(_DWORD *)(LODWORD(x) + 40);
          v18 = *(_DWORD *)(LODWORD(x) + 32);
          if ( v17 + 1 > v18 )
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(LODWORD(x) + 28), num: v17 - v18 + 1);
          ++*(_DWORD *)(LODWORD(x) + 40);
          v19 = *(_DWORD *)(LODWORD(x) + 28);
          v20 = *(_DWORD *)(LODWORD(x) + 40) - v17 - 1;
          *(_DWORD *)(LODWORD(x) + 44) = v19;
          if ( v20 > 0 )
            _V_memmove(dest: (void *)(v19 + 4 * v17 + 4), src: (const void *)(v19 + 4 * v17), count: 4 * v20);
          v21 = (float *)(*(_DWORD *)(LODWORD(x) + 28) + 4 * v17);
          if ( v21 != nullptr )
            *v21 = vecMaxs.z;
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6540
// Name: void SV_TriggerMoved(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_TriggerMoved(edict_t *pTriggerEnt, bool accurateBboxTriggerChecks)
{
  int v2; // esi
  edict_t **v3; // eax
  CTriggerMoved triggerEnum; // [esp+4h] [ebp-34h] BYREF

  triggerEnum.m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  triggerEnum.m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  triggerEnum.__vftable = (CTriggerMoved_vtbl *)&CTriggerMoved::`vftable';
  v2 = 0;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v3 = (edict_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  triggerEnum.m_bAccurateBBoxCheck = accurateBboxTriggerChecks;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = v3;
  triggerEnum.m_TouchedEntities.m_Size = 0;
  triggerEnum.m_TouchedEntities.m_pElements = v3;
  CTriggerMoved::TriggerMoved(this: &triggerEnum, pTriggerEntity: pTriggerEnt);
  if ( triggerEnum.m_TouchedEntities.m_Size > 0 )
  {
    do
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: triggerEnum.m_TouchedEntities.m_Memory.m_pMemory[v2++],
        a3: triggerEnum.m_pTriggerEntity);
    while ( v2 < triggerEnum.m_TouchedEntities.m_Size );
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&triggerEnum.m_TouchedEntities);
}

//------------------------------------------------------------------------------
// Address: 0x101F65C0
// Name: void CL_TriggerMoved(class IClientEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TriggerMoved(IClientEntity *pTriggerEnt, bool accurateBboxTriggerChecks)
{
  int v2; // esi
  IClientEntity **v3; // eax
  CTriggerMoved_ClientSide triggerEnum; // [esp+4h] [ebp-34h] BYREF

  triggerEnum.m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  triggerEnum.m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  triggerEnum.__vftable = (CTriggerMoved_ClientSide_vtbl *)&CTriggerMoved_ClientSide::`vftable';
  v2 = 0;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v3 = (IClientEntity **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  triggerEnum.m_bAccurateBBoxCheck = accurateBboxTriggerChecks;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = v3;
  triggerEnum.m_TouchedEntities.m_Size = 0;
  triggerEnum.m_TouchedEntities.m_pElements = v3;
  CTriggerMoved_ClientSide::TriggerMoved(this: &triggerEnum, pTriggerEntity: pTriggerEnt);
  if ( triggerEnum.m_TouchedEntities.m_Size > 0 )
  {
    do
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: triggerEnum.m_TouchedEntities.m_Memory.m_pMemory[v2++],
        a3: triggerEnum.m_pTriggerEntity);
    while ( v2 < triggerEnum.m_TouchedEntities.m_Size );
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&triggerEnum.m_TouchedEntities);
}

//------------------------------------------------------------------------------
// Address: 0x101F6640
// Name: void SV_SolidMoved(struct edict_t __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall SV_SolidMoved(
        float a1@<ebp>,
        int a2@<esi>,
        edict_t *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  CSpatialPartition *v6; // eax
  void (__thiscall *EnumerateElementsInBox)(struct CSpatialPartition *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // edx
  int j; // esi
  CSpatialPartition *v9; // eax
  int i; // esi
  _BYTE v11[12]; // [esp-Ch] [ebp-ACh] BYREF
  CTouchLinks touchEnumerator; // [esp+0h] [ebp-A0h] BYREF
  Vector vecWorldMaxs; // [esp+88h] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+94h] [ebp-Ch]
  float retaddr; // [esp+A0h] [ebp+0h]

  vecWorldMins.x = a1;
  vecWorldMins.y = retaddr;
  if ( pPrevAbsOrigin != nullptr )
  {
    CTouchLinks::CTouchLinks(this: (CTouchLinks *)v11, pEnt: pSolidEnt, pPrevAbsOrigin, accurateBboxTriggerChecks);
    v9 = SpatialPartition();
    ((void (__thiscall *)(CSpatialPartition *, int, IPartitionEnumerator *, _DWORD, _BYTE *, int))v9->EnumerateElementsAlongRay)(
      a1: v9,
      a2: 2,
      a3: &touchEnumerator.IPartitionEnumerator + 1,
      a4: 0,
      a5: v11,
      a6: a2);
    for ( i = 0; i < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++i )
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: *((edict_t **)&touchEnumerator.m_pEnt->m_fStateFlags + i),
        a3: *(edict_t **)&touchEnumerator.m_Ray.m_IsRay);
  }
  else
  {
    CTouchLinks::CTouchLinks(
      this: (CTouchLinks *)v11,
      pEnt: pSolidEnt,
      pPrevAbsOrigin: nullptr,
      accurateBboxTriggerChecks);
    ((void (__thiscall *)(ICollideable *, Vector *, edict_t ***, int))pSolidCollide->WorldSpaceSurroundingBounds)(
      a1: pSolidCollide,
      a2: &vecWorldMaxs,
      a3: &touchEnumerator.m_TouchedEntities.m_pElements,
      a4: a2);
    v6 = SpatialPartition();
    EnumerateElementsInBox = v6->EnumerateElementsInBox;
    LODWORD(vecWorldMaxs.z) = v11;
    vecWorldMaxs.y = 0.0;
    LODWORD(vecWorldMaxs.x) = &touchEnumerator.m_TouchedEntities.m_pElements;
    ((void (__thiscall *)(CSpatialPartition *, int, Vector *))EnumerateElementsInBox)(a1: v6, a2: 2, a3: &vecWorldMaxs);
    for ( j = 0; j < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++j )
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: *((edict_t **)&touchEnumerator.m_pEnt->m_fStateFlags + j),
        a3: *(edict_t **)&touchEnumerator.m_Ray.m_IsRay);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&touchEnumerator.m_pEnt);
}

//------------------------------------------------------------------------------
// Address: 0x101F6760
// Name: void CL_SolidMoved(class IClientEntity __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CL_SolidMoved(
        float a1@<ebp>,
        int a2@<esi>,
        IClientEntity *pTriggerEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  CSpatialPartition *v6; // eax
  void (__thiscall *EnumerateElementsInBox)(struct CSpatialPartition *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // edx
  int j; // esi
  CSpatialPartition *v9; // eax
  int i; // esi
  _BYTE v11[12]; // [esp-Ch] [ebp-ACh] BYREF
  CTouchLinks_ClientSide touchEnumerator; // [esp+0h] [ebp-A0h] BYREF
  Vector vecWorldMaxs; // [esp+88h] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+94h] [ebp-Ch]
  float retaddr; // [esp+A0h] [ebp+0h]

  vecWorldMins.x = a1;
  vecWorldMins.y = retaddr;
  if ( pPrevAbsOrigin != nullptr )
  {
    CTouchLinks_ClientSide::CTouchLinks_ClientSide(
      this: (CTouchLinks_ClientSide *)v11,
      pEnt: pTriggerEnt,
      pPrevAbsOrigin,
      accurateBboxTriggerChecks);
    v9 = SpatialPartition();
    ((void (__thiscall *)(CSpatialPartition *, int, IPartitionEnumerator *, _DWORD, _BYTE *, int))v9->EnumerateElementsAlongRay)(
      a1: v9,
      a2: 256,
      a3: &touchEnumerator.IPartitionEnumerator + 1,
      a4: 0,
      a5: v11,
      a6: a2);
    for ( i = 0; i < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++i )
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: *((IClientEntity **)&touchEnumerator.m_pEnt->__vftable + i),
        a3: *(IClientEntity **)&touchEnumerator.m_Ray.m_IsRay);
  }
  else
  {
    CTouchLinks_ClientSide::CTouchLinks_ClientSide(
      this: (CTouchLinks_ClientSide *)v11,
      pEnt: pTriggerEnt,
      pPrevAbsOrigin: nullptr,
      accurateBboxTriggerChecks);
    ((void (__thiscall *)(ICollideable *, Vector *, IClientEntity ***, int))pSolidCollide->WorldSpaceSurroundingBounds)(
      a1: pSolidCollide,
      a2: &vecWorldMaxs,
      a3: &touchEnumerator.m_TouchedEntities.m_pElements,
      a4: a2);
    v6 = SpatialPartition();
    EnumerateElementsInBox = v6->EnumerateElementsInBox;
    LODWORD(vecWorldMaxs.z) = v11;
    vecWorldMaxs.y = 0.0;
    LODWORD(vecWorldMaxs.x) = &touchEnumerator.m_TouchedEntities.m_pElements;
    ((void (__thiscall *)(CSpatialPartition *, int, Vector *))EnumerateElementsInBox)(
      a1: v6,
      a2: 256,
      a3: &vecWorldMaxs);
    for ( j = 0; j < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++j )
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: *((IClientEntity **)&touchEnumerator.m_pEnt->__vftable + j),
        a3: *(IClientEntity **)&touchEnumerator.m_Ray.m_IsRay);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&touchEnumerator.m_pEnt);
}

//------------------------------------------------------------------------------
// Address: 0x101F6890
// Name: __CreateCXboxSystemIXboxSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CXboxSystem *__cdecl _CreateCXboxSystemIXboxSystem_interface()
{
  return &s_XboxSystem;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101F5D60
// Name: void SV_ClearWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ClearWorld()
{
  IMDLCache *v0; // edi
  IStaticPropMgrEngine *v1; // eax
  model_t *worldmodel; // eax
  int i; // esi
  ISpatialPartitionInternal *v4; // eax
  IStaticPropMgrEngine *v5; // eax

  v0 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
  v1 = StaticPropMgr();
  v1->LevelShutdown(this: v1);
  worldmodel = host_state.worldmodel;
  for ( i = 292; i < 304; i += 4 )
  {
    if ( *(float *)((char *)worldmodel + i - 12) < -16384.0 || *(float *)((char *)&worldmodel->fnHandle + i) > 16384.0 )
    {
      Host_EndGame(bShowMainMenu: true, message: "Map coordinate extents are too large!!\nCheck for errors!\n");
      worldmodel = host_state.worldmodel;
    }
  }
  v4 = SpatialPartition();
  v4->Init(this: v4, a2: &host_state.worldmodel->mins, a3: &host_state.worldmodel->maxs);
  v5 = StaticPropMgr();
  v5->LevelInit(this: v5);
  g_pShadowMgr->LevelInit(this: g_pShadowMgr, a2: host_state.worldbrush->numsurfaces);
  v0->EndCoarseLock(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x101F5E40
// Name: CM_GetCollideableTriggerTestBox
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_GetCollideableTriggerTestBox(
        Vector *pMins@<edi>,
        Vector *pMaxs@<esi>,
        ICollideable *pCollide,
        bool bUseAccurateBbox)
{
  const Vector *v4; // eax
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // edx
  const Vector *vecStart; // [esp+10h] [ebp+Ch]

  if ( bUseAccurateBbox && pCollide->GetSolid(this: pCollide) == SOLID_BBOX )
  {
    v4 = pCollide->OBBMins(this: pCollide);
    pMins->x = v4->x;
    pMins->y = v4->y;
    OBBMaxs = pCollide->OBBMaxs;
    pMins->z = v4->z;
    *pMaxs = *OBBMaxs(this: pCollide);
  }
  else
  {
    vecStart = pCollide->GetCollisionOrigin(this: pCollide);
    pCollide->WorldSpaceSurroundingBounds(this: pCollide, a2: pMins, a3: pMaxs);
    pMins->x = pMins->x - vecStart->x;
    pMins->y = pMins->y - vecStart->y;
    pMins->z = pMins->z - vecStart->z;
    pMaxs->x = pMaxs->x - vecStart->x;
    pMaxs->y = pMaxs->y - vecStart->y;
    pMaxs->z = pMaxs->z - vecStart->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5FA0
// Name: public: void CTriggerMoved_ClientSide::TriggerMoved(class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTriggerMoved_ClientSide::TriggerMoved(CTriggerMoved_ClientSide *this, IClientEntity *pTriggerEntity)
{
  ICollideable *v3; // eax
  int v4; // eax
  ICollideable *m_pTrigger; // edi
  ISpatialPartitionInternal *v6; // eax
  Vector vecAbsMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->m_pTriggerEntity = pTriggerEntity;
  v3 = pTriggerEntity->GetCollideable(this: pTriggerEntity);
  this->m_pTrigger = v3;
  v4 = v3->GetSolidFlags(this: v3);
  m_pTrigger = this->m_pTrigger;
  this->m_triggerSolidFlags = v4;
  if ( (m_pTrigger->GetSolidFlags(this: m_pTrigger) & 0x80u) == 0 )
    CM_WorldSpaceBounds(pCollideable: m_pTrigger, pMins: &vecAbsMins, pMaxs: &vecAbsMaxs);
  else
    m_pTrigger->WorldSpaceTriggerBounds(this: m_pTrigger, a2: &vecAbsMins, a3: &vecAbsMaxs);
  v6 = SpatialPartition();
  v6->EnumerateElementsInBox(this: v6, a2: 4, a3: &vecAbsMins, a4: &vecAbsMaxs, a5: false, a6: this);
}

//------------------------------------------------------------------------------
// Address: 0x101F6020
// Name: public: CTouchLinks::CTouchLinks(struct edict_t __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CTouchLinks *__thiscall CTouchLinks::CTouchLinks(
        CTouchLinks *this,
        edict_t *pEnt,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  edict_t **v5; // eax
  IServerUnknown *m_pUnk; // eax
  ICollideable *v7; // eax
  unsigned int v8; // eax
  const Vector *v9; // eax
  ICollideable *m_pCollide; // [esp-Ch] [ebp-2Ch]
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->__vftable = (CTouchLinks_vtbl *)&CTouchLinks::`vftable';
  this->m_Ray.m_pWorldAxisTransform = nullptr;
  this->m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  this->m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  this->m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v5 = (edict_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_TouchedEntities.m_Memory.m_pMemory = v5;
  this->m_TouchedEntities.m_pElements = v5;
  this->m_TouchedEntities.m_Size = 0;
  this->m_pEnt = pEnt;
  if ( (pEnt->m_fStateFlags & 4) != 0 && (m_pUnk = pEnt->m_pUnk) != nullptr )
    v7 = m_pUnk->GetCollideable(this: m_pUnk);
  else
    v7 = nullptr;
  this->m_pCollide = v7;
  v8 = v7->GetRequiredTriggerFlags(this: v7);
  m_pCollide = this->m_pCollide;
  this->m_nRequiredTriggerFlags = v8;
  CM_GetCollideableTriggerTestBox(
    pMins: &vecMins,
    pMaxs: &vecMaxs,
    pCollide: m_pCollide,
    bUseAccurateBbox: accurateBboxTriggerChecks);
  v9 = this->m_pCollide->GetCollisionOrigin(this: this->m_pCollide);
  if ( pPrevAbsOrigin != nullptr )
    Ray_t::Init(this: &this->m_Ray, start: pPrevAbsOrigin, end: v9, mins: &vecMins, maxs: &vecMaxs);
  else
    Ray_t::Init(this: &this->m_Ray, start: v9, end: v9, mins: &vecMins, maxs: &vecMaxs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F60F0
// Name: public: CTouchLinks_ClientSide::CTouchLinks_ClientSide(class IClientEntity __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CTouchLinks_ClientSide *__thiscall CTouchLinks_ClientSide::CTouchLinks_ClientSide(
        CTouchLinks_ClientSide *this,
        IClientEntity *pEnt,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  IClientEntity **v5; // eax
  ICollideable *v6; // eax
  unsigned int v7; // eax
  const Vector *v8; // eax
  ICollideable *m_pCollide; // [esp-8h] [ebp-2Ch]
  Vector vecMins; // [esp+Ch] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-Ch] BYREF

  this->__vftable = (CTouchLinks_ClientSide_vtbl *)&CTouchLinks_ClientSide::`vftable';
  this->m_Ray.m_pWorldAxisTransform = nullptr;
  this->m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  this->m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  this->m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v5 = (IClientEntity **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  this->m_TouchedEntities.m_Memory.m_pMemory = v5;
  this->m_TouchedEntities.m_pElements = v5;
  this->m_TouchedEntities.m_Size = 0;
  this->m_pEnt = pEnt;
  v6 = pEnt->GetCollideable(this: pEnt);
  this->m_pCollide = v6;
  v7 = v6->GetRequiredTriggerFlags(this: v6);
  m_pCollide = this->m_pCollide;
  this->m_nRequiredTriggerFlags = v7;
  CM_GetCollideableTriggerTestBox(
    pMins: &vecMins,
    pMaxs: &vecMaxs,
    pCollide: m_pCollide,
    bUseAccurateBbox: accurateBboxTriggerChecks);
  v8 = this->m_pCollide->GetCollisionOrigin(this: this->m_pCollide);
  if ( pPrevAbsOrigin != nullptr )
    Ray_t::Init(this: &this->m_Ray, start: pPrevAbsOrigin, end: v8, mins: &vecMins, maxs: &vecMaxs);
  else
    Ray_t::Init(this: &this->m_Ray, start: v8, end: v8, mins: &vecMins, maxs: &vecMaxs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F61B0
// Name: public: virtual enum IterationRetval_t CTouchLinks::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IterationRetval_t __userpurge CTouchLinks::EnumElement@<eax>(
        CTouchLinks *this@<ecx>,
        int a2@<ebp>,
        IHandleEntity *pHandleEntity)
{
  int v4; // eax
  edict_t *v5; // eax
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v7; // esi
  int v8; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_TouchedEntities; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v14; // eax
  S3RGBA *v15; // edi
  int v16; // [esp-Ch] [ebp-C4h] BYREF
  _BYTE tr_36[72]; // [esp+24h] [ebp-94h] OVERLAPPED BYREF
  _BYTE v18[32]; // [esp+6Ch] [ebp-4Ch] OVERLAPPED BYREF
  __m128 v19; // [esp+8Ch] [ebp-2Ch] BYREF
  edict_t *v20; // [esp+A8h] [ebp-10h]
  _DWORD v21[2]; // [esp+ACh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+B8h] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  if ( this->m_nRequiredTriggerFlags != 0 )
  {
    v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
    v5 = (edict_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    v20 = v5;
    if ( v5 != this->m_pEnt && (v5->m_fStateFlags & 4) != 0 )
    {
      m_pUnk = v5->m_pUnk;
      if ( m_pUnk != nullptr )
      {
        v7 = m_pUnk->GetCollideable(this: m_pUnk);
        v8 = v7->GetSolidFlags(this: v7);
        if ( (v8 & this->m_nRequiredTriggerFlags) == this->m_nRequiredTriggerFlags )
        {
          if ( (v8 & 0x80u) != 0 )
          {
            v7->WorldSpaceTriggerBounds(this: v7, a2: (Vector *)v18, a3: (Vector *)&tr_36[40]);
            v19 = Four_Zeros;
            *(_OWORD *)&v18[16] = *(_OWORD *)&tr_36[40];
            *(_OWORD *)&tr_36[56] = *(_OWORD *)v18;
            if ( !IsBoxIntersectingRay(
                    boxMin: (const __m128 *)&tr_36[56],
                    boxMax: (const __m128 *)&v18[16],
                    a3: (int)v21,
                    ray: &this->m_Ray,
                    fl4Tolerance: &v19) )
              return ITERATION_CONTINUE;
            goto LABEL_10;
          }
          g_pEngineTraceServer->ClipRayToCollideable(
            this: g_pEngineTraceServer,
            a2: &this->m_Ray,
            a3: 33570827u,
            a4: v7,
            a5: (CGameTrace *)&v16);
          if ( (*(_DWORD *)tr_36 & 0x200400B) != 0 )
          {
LABEL_10:
            m_nAllocationCount = this->m_TouchedEntities.m_Memory.m_nAllocationCount;
            p_m_TouchedEntities = (CUtlMemory<S3RGBA,int> *)&this->m_TouchedEntities;
            m_Size = this->m_TouchedEntities.m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<INetMessage *,int>::Grow(this: p_m_TouchedEntities, num: m_Size - m_nAllocationCount + 1);
            ++p_m_TouchedEntities[1].m_pMemory;
            m_pMemory = p_m_TouchedEntities->m_pMemory;
            v14 = (int)p_m_TouchedEntities[1].m_pMemory - m_Size - 1;
            p_m_TouchedEntities[1].m_nAllocationCount = (int)p_m_TouchedEntities->m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
            v15 = &p_m_TouchedEntities->m_pMemory[m_Size];
            if ( v15 != nullptr )
              *v15 = (S3RGBA)v20;
          }
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6310
// Name: public: virtual enum IterationRetval_t CTouchLinks_ClientSide::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IterationRetval_t __userpurge CTouchLinks_ClientSide::EnumElement@<eax>(
        CTouchLinks_ClientSide *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IClientEntity *v6; // eax
  int v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_TouchedEntities; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v13; // eax
  S3RGBA *v14; // edi
  _BYTE tr_36[72]; // [esp+24h] [ebp-94h] OVERLAPPED BYREF
  _BYTE v18[32]; // [esp+6Ch] [ebp-4Ch] OVERLAPPED BYREF
  __m128 v19; // [esp+8Ch] [ebp-2Ch] BYREF
  IClientEntity *v20; // [esp+A8h] [ebp-10h]
  _DWORD v21[2]; // [esp+ACh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+B8h] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  if ( this->m_nRequiredTriggerFlags != 0 )
  {
    v6 = (IClientEntity *)((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].dtr_IHandleEntity)(a1: pHandleEntity);
    v20 = v6;
    if ( v6 != this->m_pEnt )
    {
      v7 = (int)v6->GetCollideable(this: v6);
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 48))(a1: v7) & this->m_nRequiredTriggerFlags) != this->m_nRequiredTriggerFlags )
        goto LABEL_8;
      if ( (*(char (__thiscall **)(int, int, int))(*(_DWORD *)v7 + 48))(a1: v7, a2: a3, a3: a4) < 0 )
      {
        (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)v7 + 12))(a1: v7, a2: v18, a3: &tr_36[40]);
        v19 = Four_Zeros;
        *(_OWORD *)&v18[16] = *(_OWORD *)&tr_36[40];
        *(_OWORD *)&tr_36[56] = *(_OWORD *)v18;
        if ( !IsBoxIntersectingRay(
                boxMin: (const __m128 *)&tr_36[56],
                boxMax: (const __m128 *)&v18[16],
                a3: (int)v21,
                ray: &this->m_Ray,
                fl4Tolerance: &v19) )
          return ITERATION_CONTINUE;
        goto LABEL_8;
      }
      ((void (__thiscall *)(IEngineTrace *, Ray_t *, int))g_pEngineTraceClient->ClipRayToCollideable)(
        a1: g_pEngineTraceClient,
        a2: &this->m_Ray,
        a3: 33570827);
      if ( (*(_DWORD *)tr_36 & 0x200400B) != 0 )
      {
LABEL_8:
        m_nAllocationCount = this->m_TouchedEntities.m_Memory.m_nAllocationCount;
        p_m_TouchedEntities = (CUtlMemory<S3RGBA,int> *)&this->m_TouchedEntities;
        m_Size = this->m_TouchedEntities.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: p_m_TouchedEntities, num: m_Size - m_nAllocationCount + 1);
        ++p_m_TouchedEntities[1].m_pMemory;
        m_pMemory = p_m_TouchedEntities->m_pMemory;
        v13 = (int)p_m_TouchedEntities[1].m_pMemory - m_Size - 1;
        p_m_TouchedEntities[1].m_nAllocationCount = (int)p_m_TouchedEntities->m_pMemory;
        if ( v13 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
        v14 = &p_m_TouchedEntities->m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = (S3RGBA)v20;
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6460
// Name: public: virtual enum IterationRetval_t CTriggerMoved::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IterationRetval_t __userpurge CTriggerMoved::EnumElement@<eax>(
        CTriggerMoved *this@<ecx>,
        ICollideable *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v6; // eax
  int v7; // eax
  float v8; // eax
  IHandleEntity_vtbl *v9; // edx
  ICollideable *v10; // eax
  ICollideable *v11; // esi
  int v12; // eax
  const Vector *v13; // eax
  float y; // esi
  int v15; // ecx
  void (__thiscall *v16)(int, _BYTE *); // eax
  void (__thiscall *ClipRayToCollideable)(IEngineTrace *, const Ray_t *, unsigned int, ICollideable *, CGameTrace *); // eax
  int v19; // edi
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  float *v23; // edi
  int v25; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-128h] BYREF
  _BYTE ray_52[48]; // [esp+8Ch] [ebp-9Ch] OVERLAPPED BYREF
  __m128 v28; // [esp+BCh] [ebp-6Ch] BYREF
  __m128 v29; // [esp+CCh] [ebp-5Ch] BYREF
  _BYTE v30[17]; // [esp+E8h] [ebp-40h] OVERLAPPED BYREF
  Vector vecMins; // [esp+104h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+110h] [ebp-18h]
  ICollideable *pTouchCollide; // [esp+11Ch] [ebp-Ch] BYREF
  void *v34; // [esp+120h] [ebp-8h]
  void *retaddr; // [esp+128h] [ebp+0h]

  pTouchCollide = a2;
  v34 = retaddr;
  LODWORD(vecMaxs.y) = this;
  v6 = StaticPropMgr();
  if ( ((unsigned __int8 (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, int, int))v6->IsStaticProp_2)(
         a1: v6,
         a2: pHandleEntity,
         a3,
         a4) == 0 )
  {
    v7 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
    v8 = COERCE_FLOAT((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7));
    v9 = pHandleEntity->__vftable;
    vecMaxs.z = v8;
    v10 = (ICollideable *)((int (__thiscall *)(IHandleEntity *))v9[1].dtr_IHandleEntity)(a1: pHandleEntity);
    v11 = v10;
    LODWORD(vecMaxs.x) = v10;
    if ( v10 != this->m_pTrigger )
    {
      v12 = v10->GetRequiredTriggerFlags(this: v10);
      if ( v12 != 0
        && (v12 & this->m_triggerSolidFlags) == v12
        && (*(_BYTE *)LODWORD(vecMaxs.z) & 4) != 0
        && *(_DWORD *)(LODWORD(vecMaxs.z) + 12) != 0 )
      {
        CM_GetCollideableTriggerTestBox(
          pMins: (Vector *)&v30[16],
          pMaxs: &vecMins,
          pCollide: v11,
          bUseAccurateBbox: this->m_bAccurateBBoxCheck);
        v13 = (const Vector *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(vecMaxs.x) + 32))(
                                a1: LODWORD(vecMaxs.x),
                                a2: LODWORD(vecMaxs.z));
        *(_DWORD *)ray_52 = 0;
        Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: v13, end: v13, mins: (const Vector *)&v30[16], maxs: &vecMins);
        y = vecMaxs.y;
        if ( (*(char (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(vecMaxs.y) + 8) + 48))(a1: *(_DWORD *)(LODWORD(vecMaxs.y) + 8)) < 0 )
        {
          v15 = *(_DWORD *)(LODWORD(y) + 8);
          v16 = *(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v15 + 12);
          LODWORD(vecMaxs.z) = v30;
          v16(a1: v15, a2: &ray_52[16]);
          *(__m128 *)&ray_52[32] = Four_Zeros;
          v29 = *(__m128 *)v30;
          v28 = *(__m128 *)&ray_52[16];
          if ( !IsBoxIntersectingRay(
                  boxMin: &v28,
                  boxMax: &v29,
                  a3: (int)&pTouchCollide,
                  ray: (const Ray_t *)&tr.m_pEnt,
                  fl4Tolerance: (const __m128 *)&ray_52[32]) )
            return ITERATION_CONTINUE;
          goto LABEL_11;
        }
        ClipRayToCollideable = g_pEngineTraceServer->ClipRayToCollideable;
        LODWORD(vecMaxs.z) = &v25;
        ((void (__thiscall *)(IEngineTrace *, struct CBaseEntity **, int, _DWORD))ClipRayToCollideable)(
          a1: g_pEngineTraceServer,
          a2: &tr.m_pEnt,
          a3: 33570827,
          a4: *(_DWORD *)(LODWORD(y) + 8));
        if ( (LODWORD(tr.plane.dist) & 0x200400B) != 0 )
        {
LABEL_11:
          v19 = *(_DWORD *)(LODWORD(y) + 40);
          v20 = *(_DWORD *)(LODWORD(y) + 32);
          if ( v19 + 1 > v20 )
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(LODWORD(y) + 28), num: v19 - v20 + 1);
          ++*(_DWORD *)(LODWORD(y) + 40);
          v21 = *(_DWORD *)(LODWORD(y) + 28);
          v22 = *(_DWORD *)(LODWORD(y) + 40) - v19 - 1;
          *(_DWORD *)(LODWORD(y) + 44) = v21;
          if ( v22 > 0 )
            _V_memmove(dest: (void *)(v21 + 4 * v19 + 4), src: (const void *)(v21 + 4 * v19), count: 4 * v22);
          v23 = (float *)(*(_DWORD *)(LODWORD(y) + 28) + 4 * v19);
          if ( v23 != nullptr )
            *v23 = vecMaxs.z;
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F6630
// Name: public: virtual enum IterationRetval_t CTriggerMoved_ClientSide::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IterationRetval_t __userpurge CTriggerMoved_ClientSide::EnumElement@<eax>(
        CTriggerMoved_ClientSide *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v6; // eax
  int v7; // eax
  ICollideable *v8; // eax
  ICollideable *v9; // esi
  int v10; // eax
  const Vector *v11; // eax
  float x; // esi
  int v13; // ecx
  void (__thiscall *v14)(int, _BYTE *); // eax
  void (__thiscall *ClipRayToCollideable)(IEngineTrace *, const Ray_t *, unsigned int, ICollideable *, CGameTrace *); // eax
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  float *v21; // edi
  int v23; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-128h] BYREF
  _BYTE ray_52[48]; // [esp+8Ch] [ebp-9Ch] OVERLAPPED BYREF
  __m128 v26; // [esp+BCh] [ebp-6Ch] BYREF
  __m128 v27; // [esp+CCh] [ebp-5Ch] BYREF
  _BYTE v28[17]; // [esp+E8h] [ebp-40h] OVERLAPPED BYREF
  Vector vecMins; // [esp+104h] [ebp-24h] BYREF
  Vector vecMaxs; // [esp+110h] [ebp-18h]
  int v31; // [esp+11Ch] [ebp-Ch] BYREF
  ICollideable *pTouchCollide; // [esp+120h] [ebp-8h]
  ICollideable *retaddr; // [esp+128h] [ebp+0h]

  v31 = a2;
  pTouchCollide = retaddr;
  LODWORD(vecMaxs.x) = this;
  v6 = StaticPropMgr();
  if ( ((unsigned __int8 (__thiscall *)(IStaticPropMgrEngine *, IHandleEntity *, int, int))v6->IsStaticProp_2)(
         a1: v6,
         a2: pHandleEntity,
         a3,
         a4) == 0 )
  {
    v7 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[2].dtr_IHandleEntity)(a1: pHandleEntity);
    v8 = (ICollideable *)((int (__thiscall *)(IHandleEntity *, int))pHandleEntity->__vftable[1].dtr_IHandleEntity)(
                           a1: pHandleEntity,
                           a2: v7);
    v9 = v8;
    LODWORD(vecMaxs.y) = v8;
    if ( v8 != this->m_pTrigger )
    {
      v10 = v8->GetRequiredTriggerFlags(this: v8);
      if ( v10 != 0 && (v10 & this->m_triggerSolidFlags) == v10 )
      {
        CM_GetCollideableTriggerTestBox(
          pMins: (Vector *)&v28[16],
          pMaxs: &vecMins,
          pCollide: v9,
          bUseAccurateBbox: this->m_bAccurateBBoxCheck);
        v11 = (const Vector *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(vecMaxs.y) + 32))(
                                a1: LODWORD(vecMaxs.y),
                                a2: LODWORD(vecMaxs.z));
        *(_DWORD *)ray_52 = 0;
        Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: v11, end: v11, mins: (const Vector *)&v28[16], maxs: &vecMins);
        x = vecMaxs.x;
        if ( (*(char (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(vecMaxs.x) + 8) + 48))(a1: *(_DWORD *)(LODWORD(vecMaxs.x) + 8)) < 0 )
        {
          v13 = *(_DWORD *)(LODWORD(x) + 8);
          v14 = *(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 12);
          LODWORD(vecMaxs.z) = v28;
          v14(a1: v13, a2: &ray_52[16]);
          *(__m128 *)&ray_52[32] = Four_Zeros;
          v27 = *(__m128 *)v28;
          v26 = *(__m128 *)&ray_52[16];
          if ( !IsBoxIntersectingRay(
                  boxMin: &v26,
                  boxMax: &v27,
                  a3: (int)&v31,
                  ray: (const Ray_t *)&tr.m_pEnt,
                  fl4Tolerance: (const __m128 *)&ray_52[32]) )
            return ITERATION_CONTINUE;
          goto LABEL_9;
        }
        ClipRayToCollideable = g_pEngineTraceClient->ClipRayToCollideable;
        LODWORD(vecMaxs.z) = &v23;
        ((void (__thiscall *)(IEngineTrace *, struct CBaseEntity **, int, _DWORD))ClipRayToCollideable)(
          a1: g_pEngineTraceClient,
          a2: &tr.m_pEnt,
          a3: 33570827,
          a4: *(_DWORD *)(LODWORD(x) + 8));
        if ( (LODWORD(tr.plane.dist) & 0x200400B) != 0 )
        {
LABEL_9:
          v17 = *(_DWORD *)(LODWORD(x) + 40);
          v18 = *(_DWORD *)(LODWORD(x) + 32);
          if ( v17 + 1 > v18 )
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(LODWORD(x) + 28), num: v17 - v18 + 1);
          ++*(_DWORD *)(LODWORD(x) + 40);
          v19 = *(_DWORD *)(LODWORD(x) + 28);
          v20 = *(_DWORD *)(LODWORD(x) + 40) - v17 - 1;
          *(_DWORD *)(LODWORD(x) + 44) = v19;
          if ( v20 > 0 )
            _V_memmove(dest: (void *)(v19 + 4 * v17 + 4), src: (const void *)(v19 + 4 * v17), count: 4 * v20);
          v21 = (float *)(*(_DWORD *)(LODWORD(x) + 28) + 4 * v17);
          if ( v21 != nullptr )
            *v21 = vecMaxs.z;
        }
      }
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101F67E0
// Name: void SV_TriggerMoved(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_TriggerMoved(edict_t *pTriggerEnt, bool accurateBboxTriggerChecks)
{
  int v2; // esi
  edict_t **v3; // eax
  CTriggerMoved triggerEnum; // [esp+4h] [ebp-34h] BYREF

  triggerEnum.m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  triggerEnum.m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  triggerEnum.__vftable = (CTriggerMoved_vtbl *)&CTriggerMoved::`vftable';
  v2 = 0;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v3 = (edict_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  triggerEnum.m_bAccurateBBoxCheck = accurateBboxTriggerChecks;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = v3;
  triggerEnum.m_TouchedEntities.m_Size = 0;
  triggerEnum.m_TouchedEntities.m_pElements = v3;
  CTriggerMoved::TriggerMoved(this: &triggerEnum, pTriggerEntity: pTriggerEnt);
  if ( triggerEnum.m_TouchedEntities.m_Size > 0 )
  {
    do
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: triggerEnum.m_TouchedEntities.m_Memory.m_pMemory[v2++],
        a3: triggerEnum.m_pTriggerEntity);
    while ( v2 < triggerEnum.m_TouchedEntities.m_Size );
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&triggerEnum.m_TouchedEntities);
}

//------------------------------------------------------------------------------
// Address: 0x101F6860
// Name: void CL_TriggerMoved(class IClientEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TriggerMoved(IClientEntity *pTriggerEnt, bool accurateBboxTriggerChecks)
{
  int v2; // esi
  IClientEntity **v3; // eax
  CTriggerMoved_ClientSide triggerEnum; // [esp+4h] [ebp-34h] BYREF

  triggerEnum.m_TouchedEntities.m_Memory.m_nAllocationCount = 8;
  triggerEnum.m_TouchedEntities.m_Memory.m_nGrowSize = 8;
  triggerEnum.__vftable = (CTriggerMoved_ClientSide_vtbl *)&CTriggerMoved_ClientSide::`vftable';
  v2 = 0;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = nullptr;
  v3 = (IClientEntity **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  triggerEnum.m_bAccurateBBoxCheck = accurateBboxTriggerChecks;
  triggerEnum.m_TouchedEntities.m_Memory.m_pMemory = v3;
  triggerEnum.m_TouchedEntities.m_Size = 0;
  triggerEnum.m_TouchedEntities.m_pElements = v3;
  CTriggerMoved_ClientSide::TriggerMoved(this: &triggerEnum, pTriggerEntity: pTriggerEnt);
  if ( triggerEnum.m_TouchedEntities.m_Size > 0 )
  {
    do
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: triggerEnum.m_TouchedEntities.m_Memory.m_pMemory[v2++],
        a3: triggerEnum.m_pTriggerEntity);
    while ( v2 < triggerEnum.m_TouchedEntities.m_Size );
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&triggerEnum.m_TouchedEntities);
}

//------------------------------------------------------------------------------
// Address: 0x101F68E0
// Name: void SV_SolidMoved(struct edict_t __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall SV_SolidMoved(
        float a1@<ebp>,
        int a2@<esi>,
        edict_t *pSolidEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  ISpatialPartitionInternal *v6; // eax
  void (__thiscall *EnumerateElementsInBox)(struct ISpatialPartitionInternal *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // edx
  int j; // esi
  ISpatialPartitionInternal *v9; // eax
  int i; // esi
  _BYTE v11[12]; // [esp-Ch] [ebp-ACh] BYREF
  CTouchLinks touchEnumerator; // [esp+0h] [ebp-A0h] BYREF
  Vector vecWorldMaxs; // [esp+88h] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+94h] [ebp-Ch]
  float retaddr; // [esp+A0h] [ebp+0h]

  vecWorldMins.x = a1;
  vecWorldMins.y = retaddr;
  if ( pPrevAbsOrigin != nullptr )
  {
    CTouchLinks::CTouchLinks(this: (CTouchLinks *)v11, pEnt: pSolidEnt, pPrevAbsOrigin, accurateBboxTriggerChecks);
    v9 = SpatialPartition();
    ((void (__thiscall *)(ISpatialPartitionInternal *, int, IPartitionEnumerator *, _DWORD, _BYTE *, int))v9->EnumerateElementsAlongRay)(
      a1: v9,
      a2: 2,
      a3: &touchEnumerator.IPartitionEnumerator + 1,
      a4: 0,
      a5: v11,
      a6: a2);
    for ( i = 0; i < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++i )
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: *((edict_t **)&touchEnumerator.m_pEnt->m_fStateFlags + i),
        a3: *(edict_t **)&touchEnumerator.m_Ray.m_IsRay);
  }
  else
  {
    CTouchLinks::CTouchLinks(
      this: (CTouchLinks *)v11,
      pEnt: pSolidEnt,
      pPrevAbsOrigin: nullptr,
      accurateBboxTriggerChecks);
    ((void (__thiscall *)(ICollideable *, Vector *, edict_t ***, int))pSolidCollide->WorldSpaceSurroundingBounds)(
      a1: pSolidCollide,
      a2: &vecWorldMaxs,
      a3: &touchEnumerator.m_TouchedEntities.m_pElements,
      a4: a2);
    v6 = SpatialPartition();
    EnumerateElementsInBox = v6->EnumerateElementsInBox;
    LODWORD(vecWorldMaxs.z) = v11;
    vecWorldMaxs.y = 0.0;
    LODWORD(vecWorldMaxs.x) = &touchEnumerator.m_TouchedEntities.m_pElements;
    ((void (__thiscall *)(ISpatialPartitionInternal *, int, Vector *))EnumerateElementsInBox)(
      a1: v6,
      a2: 2,
      a3: &vecWorldMaxs);
    for ( j = 0; j < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++j )
      serverGameEnts->MarkEntitiesAsTouching(
        this: serverGameEnts,
        a2: *((edict_t **)&touchEnumerator.m_pEnt->m_fStateFlags + j),
        a3: *(edict_t **)&touchEnumerator.m_Ray.m_IsRay);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&touchEnumerator.m_pEnt);
}

//------------------------------------------------------------------------------
// Address: 0x101F6A00
// Name: void CL_SolidMoved(class IClientEntity __near *,class ICollideable __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CL_SolidMoved(
        float a1@<ebp>,
        int a2@<esi>,
        IClientEntity *pTriggerEnt,
        ICollideable *pSolidCollide,
        const Vector *pPrevAbsOrigin,
        bool accurateBboxTriggerChecks)
{
  ISpatialPartitionInternal *v6; // eax
  void (__thiscall *EnumerateElementsInBox)(struct ISpatialPartitionInternal *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // edx
  int j; // esi
  ISpatialPartitionInternal *v9; // eax
  int i; // esi
  _BYTE v11[12]; // [esp-Ch] [ebp-ACh] BYREF
  CTouchLinks_ClientSide touchEnumerator; // [esp+0h] [ebp-A0h] BYREF
  Vector vecWorldMaxs; // [esp+88h] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+94h] [ebp-Ch]
  float retaddr; // [esp+A0h] [ebp+0h]

  vecWorldMins.x = a1;
  vecWorldMins.y = retaddr;
  if ( pPrevAbsOrigin != nullptr )
  {
    CTouchLinks_ClientSide::CTouchLinks_ClientSide(
      this: (CTouchLinks_ClientSide *)v11,
      pEnt: pTriggerEnt,
      pPrevAbsOrigin,
      accurateBboxTriggerChecks);
    v9 = SpatialPartition();
    ((void (__thiscall *)(ISpatialPartitionInternal *, int, IPartitionEnumerator *, _DWORD, _BYTE *, int))v9->EnumerateElementsAlongRay)(
      a1: v9,
      a2: 256,
      a3: &touchEnumerator.IPartitionEnumerator + 1,
      a4: 0,
      a5: v11,
      a6: a2);
    for ( i = 0; i < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++i )
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: *((IClientEntity **)&touchEnumerator.m_pEnt->__vftable + i),
        a3: *(IClientEntity **)&touchEnumerator.m_Ray.m_IsRay);
  }
  else
  {
    CTouchLinks_ClientSide::CTouchLinks_ClientSide(
      this: (CTouchLinks_ClientSide *)v11,
      pEnt: pTriggerEnt,
      pPrevAbsOrigin: nullptr,
      accurateBboxTriggerChecks);
    ((void (__thiscall *)(ICollideable *, Vector *, IClientEntity ***, int))pSolidCollide->WorldSpaceSurroundingBounds)(
      a1: pSolidCollide,
      a2: &vecWorldMaxs,
      a3: &touchEnumerator.m_TouchedEntities.m_pElements,
      a4: a2);
    v6 = SpatialPartition();
    EnumerateElementsInBox = v6->EnumerateElementsInBox;
    LODWORD(vecWorldMaxs.z) = v11;
    vecWorldMaxs.y = 0.0;
    LODWORD(vecWorldMaxs.x) = &touchEnumerator.m_TouchedEntities.m_pElements;
    ((void (__thiscall *)(ISpatialPartitionInternal *, int, Vector *))EnumerateElementsInBox)(
      a1: v6,
      a2: 256,
      a3: &vecWorldMaxs);
    for ( j = 0; j < (int)touchEnumerator.m_TouchedEntities.m_Memory.m_pMemory; ++j )
      g_ClientDLL->MarkEntitiesAsTouching(
        this: g_ClientDLL,
        a2: *((IClientEntity **)&touchEnumerator.m_pEnt->__vftable + j),
        a3: *(IClientEntity **)&touchEnumerator.m_Ray.m_IsRay);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&touchEnumerator.m_pEnt);
}

//------------------------------------------------------------------------------
// Address: 0x101F6B30
// Name: __CreateCXboxSystemIXboxSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CXboxSystem *__cdecl _CreateCXboxSystemIXboxSystem_interface()
{
  return &s_XboxSystem;
}

} // namespace engine_xlsp
