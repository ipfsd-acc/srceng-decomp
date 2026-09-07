// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_tracer.cpp
// Functions: 23
// ============================================================

#include "game\client\fx_tracer.h"

//------------------------------------------------------------------------------
// Address: 0x100DEAF0
// Name: public: virtual void TracerPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TracerPrecache::CResourcePrecacher::Cache(
        TracerPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/spark",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bullets.DefaultNearmiss",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DEB30
// Name: public: virtual void ParticleTracerPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleTracerPrecache::CResourcePrecacher::Cache(
        ParticleTracerPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "weapon_tracers",
    a4: bPrecache,
    a5: hResourceList,
    a6: &s_nWeaponTracerIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100DEB60
// Name: class Vector GetTracerOrigin(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl GetTracerOrigin(Vector *result, const CEffectData *data)
{
  Vector *v2; // edi
  bool v3; // zf
  IClientRenderable *Renderable; // ebx
  C_BaseEntity *Entity; // edi
  int v6; // eax
  C_BaseCombatWeapon *v7; // esi
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v9; // esi
  C_BaseViewModel *ViewModel; // eax
  int v11; // edi
  IVModelInfoClient_vtbl *v12; // esi
  int v13; // eax
  const char *v14; // eax
  QAngle vecAngles; // [esp+8h] [ebp-10h] BYREF
  int iAttachment; // [esp+14h] [ebp-4h]
  int hh; // [esp+24h] [ebp+Ch]

  v2 = result;
  *result = data->m_vStart;
  v3 = (data->m_fFlags & 2) == 0;
  iAttachment = data->m_nAttachmentIndex;
  if ( !v3 )
  {
    Renderable = CEffectData::GetRenderable(this: data);
    if ( Renderable != nullptr )
    {
      Entity = CEffectData::GetEntity(this: data);
      hh = 0;
      while ( 1 )
      {
        if ( Entity != nullptr )
        {
          v6 = (int)Entity->MyCombatWeaponPointer(this: Entity);
          v7 = (C_BaseCombatWeapon *)v6;
          if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 1400))(a1: v6) != 0 )
          {
            Owner = C_BaseCombatWeapon::GetOwner(this: v7);
            v9 = (C_BasePlayer *)Owner;
            if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
            {
              ViewModel = C_BasePlayer::GetViewModel(this: v9, index: 0);
              if ( ViewModel != nullptr )
                break;
            }
          }
        }
        if ( ++hh != 0 )
          goto LABEL_13;
      }
      Renderable = &ViewModel->IClientRenderable;
LABEL_13:
      v11 = iAttachment;
      if ( !Renderable->GetAttachment_2(this: Renderable, a2: iAttachment, a3: result, a4: &vecAngles) )
      {
        v12 = modelinfo->__vftable;
        v13 = (int)Renderable->GetModel(this: Renderable);
        v14 = v12->GetModelName(this: modelinfo, a2: (const struct model_t *)v13);
        DevMsg(a1: "GetTracerOrigin: Couldn't find attachment %d on model %s\n", v11, v14);
      }
      return result;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100DEC60
// Name: void TracerSoundCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TracerSoundCallback(const CEffectData *data)
{
  Vector vecStart; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  GetTracerOrigin(result: &vecStart, data);
  FX_TracerSound(a1: COERCE_FLOAT(&savedregs), start: &vecStart, end: &data->m_vOrigin, iTracerType: data->m_fFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100DEC90
// Name: void TracerCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TracerCallback(const CEffectData *data)
{
  C_BaseEntity *Entity; // eax
  float m_flScale; // xmm0_4
  int v3; // edi
  const C_BaseEntity *v4; // eax
  __int64 v5; // xmm0_8
  float v6; // xmm0_4
  Vector vforward; // [esp+0h] [ebp-50h] BYREF
  Vector vup; // [esp+Ch] [ebp-44h] BYREF
  Vector vecStart; // [esp+18h] [ebp-38h] BYREF
  QAngle vangles; // [esp+24h] [ebp-2Ch] BYREF
  Vector vright; // [esp+30h] [ebp-20h] BYREF
  Vector foo; // [esp+3Ch] [ebp-14h] BYREF
  BOOL bWhiz; // [esp+48h] [ebp-8h]
  float flVelocity; // [esp+4Ch] [ebp-4h]

  if ( C_BasePlayer::HasAnyLocalPlayer()
    && r_drawtracers.m_pParent != nullptr
    && r_drawtracers.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( r_drawtracers_firstperson.m_pParent != nullptr && r_drawtracers_firstperson.m_pParent->m_Value.m_nValue != 0
      || (Entity = CEffectData::GetEntity(this: data), ToBaseViewModel(pEntity: Entity) == nullptr) )
    {
      GetTracerOrigin(result: &vecStart, data);
      m_flScale = data->m_flScale;
      LOBYTE(bWhiz) = data->m_fFlags & 1;
      flVelocity = m_flScale;
      v3 = CEffectData::entindex(this: data);
      if ( IsPlayerIndex(index: v3) && (v4 = C_BaseEntity::Instance(iEnt: v3), C_BasePlayer::IsLocalPlayer(pEntity: v4)) )
      {
        v5 = *(_QWORD *)&data->m_vStart.x;
        foo.z = data->m_vStart.z;
        *(_QWORD *)&foo.x = v5;
        engine->GetViewAngles(this: engine, a2: &vangles);
        AngleVectors(angles: &vangles, forward: &vforward, right: &vright, up: &vup);
        foo.x = (float)(vright.x * 4.0) + data->m_vStart.x;
        foo.y = (float)(vright.y * 4.0) + data->m_vStart.y;
        foo.z = (float)((float)(vright.z * 4.0) + data->m_vStart.z) - 0.5;
        FX_PlayerTracer(start: &foo, end: &data->m_vOrigin);
      }
      else
      {
        v6 = flVelocity;
        if ( flVelocity == 0.0 )
          v6 = 5000.0;
        FX_Tracer(start: &vecStart, end: &data->m_vOrigin, velocity: (int)v6, makeWhiz: bWhiz);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DEE00
// Name: void ParticleTracerCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleTracerCallback(const CEffectData *data)
{
  C_BaseEntity *v1; // eax
  int m_nHitBox; // eax
  C_BaseEntity *Entity; // eax
  C_BaseEntity *v4; // edi
  int v5; // eax
  int v6; // ebx
  float v7; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  C_BaseEntity *v10; // eax
  C_CSPlayer *v11; // eax
  float z; // ecx
  Vector vforward; // [esp+Ch] [ebp-64h] BYREF
  Vector vup; // [esp+18h] [ebp-58h] BYREF
  QAngle dummy; // [esp+24h] [ebp-4Ch] BYREF
  QAngle vecAngles; // [esp+30h] [ebp-40h] BYREF
  Vector vright; // [esp+3Ch] [ebp-34h] BYREF
  Vector vecToEnd; // [esp+48h] [ebp-28h] BYREF
  Vector vecStart; // [esp+54h] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+60h] [ebp-10h] BYREF
  int nParticleIndex; // [esp+6Ch] [ebp-4h]
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  if ( C_BasePlayer::HasAnyLocalPlayer() != 0
    && r_drawtracers.m_pParent != nullptr
    && r_drawtracers.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( r_drawtracers_firstperson.m_pParent != nullptr && r_drawtracers_firstperson.m_pParent->m_Value.m_nValue != 0
      || (v1 = CEffectData::GetEntity(this: data), ToBaseViewModel(pEntity: v1) == nullptr) )
    {
      m_nHitBox = data->m_nHitBox;
      if ( m_nHitBox <= 1 )
        m_nHitBox = s_nWeaponTracerIndex;
      nParticleIndex = m_nHitBox;
      Entity = CEffectData::GetEntity(this: data);
      v4 = Entity;
      if ( Entity == nullptr )
        goto LABEL_15;
      v5 = (int)Entity->GetBaseAnimating(this: Entity);
      v6 = v5;
      if ( v5 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 844))(a1: v5) == 0 )
        v6 = 0;
      if ( v4->MyCombatWeaponPointer(this: v4) != nullptr || v6 != 0 )
      {
        GetTracerOrigin(result: &vright, data);
        vecEnd = data->m_vOrigin;
        if ( v6 != 0 )
        {
          v10 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 908))(a1: v6);
          v11 = ToBasePlayer(pEntity: v10);
          FormatViewModelAttachment(pPlayer: v11, vOrigin: &vright, bInverse: true);
        }
        DispatchParticleEffect(
          iEffectIndex: nParticleIndex,
          vecOrigin: vright,
          vecStart: vecEnd,
          vecAngles: dummy,
          pEntity: nullptr,
          nSplitScreenPlayerSlot: -1);
      }
      else
      {
LABEL_15:
        GetTracerOrigin(result: &vecStart, data);
        vecEnd = data->m_vOrigin;
        if ( CEffectData::entindex(this: data) != 0 && C_BasePlayer::IsLocalPlayer(pEntity: v4) )
        {
          engine->GetViewAngles(this: engine, a2: &dummy);
          AngleVectors(angles: &dummy, forward: &vforward, right: &vright, up: &vup);
          v7 = (float)((float)(vright.z * 4.0) + data->m_vStart.z) - 0.5;
          x = (float)(vright.x * 4.0) + data->m_vStart.x;
          y = (float)(vright.y * 4.0) + data->m_vStart.y;
          vecStart.x = x;
          vecStart.y = y;
          vecStart.z = v7;
        }
        else
        {
          y = vecStart.y;
          x = vecStart.x;
        }
        vecToEnd.x = vecEnd.x - x;
        vecToEnd.y = vecEnd.y - y;
        vecToEnd.z = vecEnd.z - vecStart.z;
        VectorNormalize(vec: &vecToEnd);
        VectorAngles(forward: &vecToEnd, angles: &vecAngles);
        DispatchParticleEffect(
          iEffectIndex: nParticleIndex,
          vecOrigin: vecStart,
          vecStart: vecEnd,
          vecAngles,
          pEntity: nullptr,
          nSplitScreenPlayerSlot: -1);
      }
      if ( (data->m_fFlags & 1) != 0 )
      {
        z = data->m_vStart.z;
        *(_QWORD *)&vecAngles.x = *(_QWORD *)&data->m_vStart.x;
        vecAngles.z = z;
        FX_TracerSound(a1: COERCE_FLOAT(&savedregs), start: (const Vector *)&vecAngles, end: &vecEnd, iTracerType: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10416020
// Name: TracerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int TracerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  TracerPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&TracerPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416060
// Name: ParticleTracerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ParticleTracerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ParticleTracerPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ParticleTracerPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104160A0
// Name: TracerSoundPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int TracerSoundPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  TracerSoundPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&TracerSoundPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D0E0
// Name: _dynamic_initializer_for__tracer_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__tracer_extra__()
{
  ConVar::ConVar(this: &tracer_extra, pName: "tracer_extra", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__tracer_extra__);
}

//------------------------------------------------------------------------------
// Address: 0x10436F50
// Name: _dynamic_atexit_destructor_for__tracer_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tracer_extra__()
{
  ConVar::~ConVar(this: &tracer_extra);
}

//------------------------------------------------------------------------------
// Address: 0x10416040
// Name: _dynamic_initializer_for__ClientEffectReg_ParticleTracerCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ParticleTracerCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ParticleTracerCallback,
           pEffectName: "ParticleTracer",
           fn: ParticleTracerCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10416080
// Name: _dynamic_initializer_for__ClientEffectReg_TracerSoundCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_TracerSoundCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_TracerSoundCallback,
           pEffectName: "TracerSound",
           fn: TracerSoundCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10436F60
// Name: _dynamic_atexit_destructor_for__fx_drawmetalspark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fx_drawmetalspark__()
{
  ConVar::~ConVar(this: &fx_drawmetalspark);
}

//------------------------------------------------------------------------------
// Address: 0x10436F70
// Name: _dynamic_atexit_destructor_for__s_ClientTools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ClientTools__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_ClientTools.m_ActiveHandles);
  CUtlRBTree<CClientTools::HToolEntry_t,unsigned short,bool (__cdecl *)(CClientTools::HToolEntry_t const &,CClientTools::HToolEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CClientTools::HToolEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<CClientTools::HToolEntry_t,unsigned short,bool (__cdecl *)(CClientTools::HToolEntry_t const &,CClientTools::HToolEntry_t const &),CUtlMemory<UtlRBTreeNode_t<CClientTools::HToolEntry_t,unsigned short>,unsigned short>>(this: &s_ClientTools.m_Handles);
  s_ClientTools.IClientTools::IBaseInterface::__vftable = (CClientTools_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10436F90
// Name: _dynamic_atexit_destructor_for__g_ToolFrameworkClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ToolFrameworkClient__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_ToolFrameworkClient);
}

//------------------------------------------------------------------------------
// Address: 0x10436FA0
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x10436FB0
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x10436FC0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x10436FD0
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x10437000
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x10437010
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x10437020
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}
