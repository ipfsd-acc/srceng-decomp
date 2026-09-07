// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_plantedc4.cpp
// Functions: 16
// ============================================================

#include "game\client\cstrike15\c_plantedc4.h"

//------------------------------------------------------------------------------
// Address: 0x101BF520
// Name: public: virtual class ClientClass __near * C_PlantedC4::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PlantedC4::GetClientClass(C_PlantedC4 *this)
{
  return &__g_C_PlantedC4ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101BF630
// Name: public: virtual void C_PlantedC4::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlantedC4::Spawn(C_PlantedC4 *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  ((void (__thiscall *)(C_PlantedC4 *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x101BF660
// Name: public: void C_PlantedC4::Explode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlantedC4::Explode(C_PlantedC4 *this)
{
  if ( !C_CSGameRules::IsPlayingTraining(this: (C_CSGameRules *)g_pGameRules) )
    C_BaseEntity::AddEffects(this, nEffects: 32);
  this->SetDormant(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101BF690
// Name: public: float C_PlantedC4::GetDetonationProgress(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PlantedC4::GetDetonationProgress(C_PlantedC4 *this)
{
  float m_flTimerLength; // xmm0_4
  float fComplete; // [esp+0h] [ebp-4h]

  m_flTimerLength = this->m_flTimerLength;
  fComplete = 0.0;
  if ( m_flTimerLength > 0.0 )
    return (float)((float)(this->m_flC4Blow - *(float *)(gpGlobals.m_Index + 12)) / m_flTimerLength);
  return fComplete;
}

//------------------------------------------------------------------------------
// Address: 0x101BF6D0
// Name: public: C_PlantedC4::C_PlantedC4(void)
// Source: json
//------------------------------------------------------------------------------
C_PlantedC4 *__thiscall C_PlantedC4::C_PlantedC4(C_PlantedC4 *this)
{
  int m_Size; // eax
  int v3; // edi
  C_PlantedC4 **m_pMemory; // ecx
  int v5; // eax
  C_PlantedC4 **v6; // eax
  double v7; // st7

  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PlantedC4_vtbl *)&C_PlantedC4::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PlantedC4::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PlantedC4::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PlantedC4::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PlantedC4::`vftable';
  m_Size = g_PlantedC4s.m_Size;
  v3 = g_PlantedC4s.m_Size;
  if ( g_PlantedC4s.m_Size + 1 > g_PlantedC4s.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PlantedC4s,
      num: g_PlantedC4s.m_Size - g_PlantedC4s.m_Memory.m_nAllocationCount + 1);
    m_Size = g_PlantedC4s.m_Size;
  }
  m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
  g_PlantedC4s.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_PlantedC4s.m_pElements = g_PlantedC4s.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_PlantedC4s.m_Memory.m_pMemory[v3 + 1],
      src: (unsigned __int8 *)&g_PlantedC4s.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  v7 = *(float *)(gpGlobals.m_Index + 12);
  this->m_bRadarFlash = true;
  this->m_flNextRadarFlashTime = v7;
  this->m_pC4Explosion = nullptr;
  this->m_flNextGlow = *(float *)(gpGlobals.m_Index + 12) + 1.0;
  this->m_flNextBeep = *(float *)(gpGlobals.m_Index + 12) + 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BF830
// Name: public: virtual void C_PlantedC4::SetDormant(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PlantedC4::SetDormant(C_PlantedC4 *this, C_PlantedC4 *bDormant)
{
  char v2; // bl
  int m_Size; // eax
  C_PlantedC4 **m_pMemory; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  C_PlantedC4 **v9; // eax

  v2 = (char)bDormant;
  C_BaseEntity::SetDormant(this, (BOOL)bDormant);
  if ( v2 != 0 )
  {
    bDormant = this;
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_PlantedC4s,
      src: (vgui::TreeNode **)&bDormant);
  }
  else
  {
    m_Size = g_PlantedC4s.m_Size;
    m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
    v6 = 0;
    if ( g_PlantedC4s.m_Size <= 0 )
      goto LABEL_8;
    while ( g_PlantedC4s.m_Memory.m_pMemory[v6] != this )
    {
      if ( ++v6 >= g_PlantedC4s.m_Size )
        goto LABEL_8;
    }
    if ( v6 == -1 )
    {
LABEL_8:
      v7 = g_PlantedC4s.m_Size;
      if ( g_PlantedC4s.m_Size + 1 > g_PlantedC4s.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PlantedC4s,
          num: g_PlantedC4s.m_Size - g_PlantedC4s.m_Memory.m_nAllocationCount + 1);
        m_Size = g_PlantedC4s.m_Size;
        m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
      }
      g_PlantedC4s.m_Size = m_Size + 1;
      v8 = m_Size - v7;
      g_PlantedC4s.m_pElements = m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v7 + 1], src: (unsigned __int8 *)&m_pMemory[v7], count: 4 * v8);
        m_pMemory = g_PlantedC4s.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v7];
      if ( v9 != nullptr )
        *v9 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF8F0
// Name: public: virtual void C_PlantedC4::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall C_PlantedC4::ClientThink(C_PlantedC4 *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  float y; // esi
  unsigned __int8 (__cdecl *v5)(int, int); // edx
  float v6; // xmm0_4
  int v7; // xmm1_4
  double v8; // xmm0_8
  float v9; // xmm0_4
  int (__thiscall *v10)(int); // eax
  double v11; // xmm0_8
  float v12; // xmm0_4
  float v13; // eax
  int v14; // edx
  const IHandleEntity *v15; // edi
  int (__thiscall *v16)(int); // eax
  int v17; // eax
  C_CSPlayer *LocalOrInEyeCSPlayer; // esi
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  __int128 v22; // xmm0
  __int128 v23; // xmm0
  float v24; // xmm0_4
  float x; // eax
  IVEfx_vtbl *v26; // esi
  int v27; // eax
  int v28; // esi
  int v29; // eax
  int v30; // xmm1_4
  int v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  _BYTE v35[12]; // [esp+38h] [ebp-1D4h] BYREF
  CSoundParameters params; // [esp+44h] [ebp-1C8h] BYREF
  CGameTrace waterTrace; // [esp+FCh] [ebp-110h] BYREF
  float v38[3]; // [esp+150h] [ebp-BCh] BYREF
  EmitSound_t ep; // [esp+15Ch] [ebp-B0h] BYREF
  CLocalPlayerFilter filter; // [esp+1ACh] [ebp-60h]
  int v41; // [esp+1CCh] [ebp-40h]
  __int128 v42; // [esp+1D0h] [ebp-3Ch] BYREF
  float v43; // [esp+1E8h] [ebp-24h]
  unsigned __int64 v44; // [esp+1ECh] [ebp-20h] BYREF
  float scale; // [esp+1F4h] [ebp-18h]
  Vector vPos; // [esp+1F8h] [ebp-14h] BYREF
  int modelindex; // [esp+204h] [ebp-8h]
  int retaddr; // [esp+20Ch] [ebp+0h]

  vPos.z = a2;
  modelindex = retaddr;
  y = *(float *)&this;
  LODWORD(vPos.y) = this;
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v5 = *(unsigned __int8 (__cdecl **)(int, int))(*(_DWORD *)(LODWORD(y) - 4) + 36);
  v41 = LODWORD(y) - 4;
  if ( v5(a1: a3, a2: a4) == 0 && *(_BYTE *)(LODWORD(y) + 3244) != 0 )
  {
    if ( *(float *)(gpGlobals.m_Index + 12) > *(float *)(LODWORD(y) + 3252) )
    {
      CLocalPlayerFilter::CLocalPlayerFilter(this: (CLocalPlayerFilter *)&ep.m_nSoundEntryVersion);
      v6 = (float)(*(float *)(LODWORD(y) + 3256) - *(float *)(gpGlobals.m_Index + 12)) / *(float *)(LODWORD(y) + 3260);
      *(float *)&v7 = 0.0;
      if ( v6 < 0.0 || (*(float *)&v7 = 1.0, v6 > 1.0) )
        v6 = *(float *)&v7;
      vPos.x = v6;
      v8 = v6 * 0.6 + 0.3;
      if ( v8 >= 1.0 )
        v8 = 1.0;
      v43 = v8;
      CSoundParameters::CSoundParameters(this: (CSoundParameters *)v35);
      if ( C_BaseEntity::GetParametersForSound(
             soundname: "C4.PlantSound",
             params: (CSoundParameters *)v35,
             actormodel: nullptr) )
      {
        EmitSound_t::EmitSound_t(this: (EmitSound_t *)v38, src: (const CSoundParameters *)v35);
        v9 = 0.0;
        if ( v43 != 0.0 )
          v9 = (float)(20.0 / v43) + 50.0;
        v10 = *(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(y) - 12) + 40);
        ep.m_nChannel = (int)v9;
        ep.m_SoundLevel = v10(a1: LODWORD(y) - 12);
        C_BaseEntity::EmitSound(
          filter: (IRecipientFilter *)&ep.m_nSoundEntryVersion,
          iEntIndex: 0,
          params: (const EmitSound_t *)v38);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_pflSoundDuration);
      }
      v11 = vPos.x * 0.9 + 0.1;
      if ( v11 <= 0.15 )
        v11 = 0.15;
      v12 = v11;
      *(float *)(LODWORD(y) + 3252) = v12 + *(float *)(gpGlobals.m_Index + 12);
      C_RecipientFilter::~C_RecipientFilter(this: (C_RecipientFilter *)&ep.m_nSoundEntryVersion);
    }
    if ( *(float *)(gpGlobals.m_Index + 12) > *(float *)(LODWORD(y) + 3248) )
    {
      v13 = COERCE_FLOAT(
              ((int (__thiscall *)(IVModelInfoClient *, const char *, _DWORD))modelinfo->GetModelIndex)(
                a1: modelinfo,
                a2: "sprites/ledglow.vmt",
                a3: LODWORD(vPos.y)));
      v14 = *(_DWORD *)(LODWORD(y) - 12);
      v15 = (const IHandleEntity *)(LODWORD(y) - 12);
      vPos.x = v13;
      v16 = *(int (__thiscall **)(int))(v14 + 40);
      v43 = 0.80000001;
      v17 = v16(a1: LODWORD(y) - 12);
      v44 = *(_QWORD *)v17;
      scale = *(float *)(v17 + 8);
      if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)&v44, a3: 16432, a4: nullptr) & 0x30) != 0 )
      {
        LocalOrInEyeCSPlayer = GetLocalOrInEyeCSPlayer();
        if ( LocalOrInEyeCSPlayer != nullptr )
        {
          LocalOrInEyeCSPlayer->EyePosition(this: LocalOrInEyeCSPlayer, result: (Vector *)((char *)&v42 + 4));
          if ( (enginetrace->GetPointContents(
                  this: enginetrace,
                  a2: (const Vector *)((char *)&v42 + 4),
                  a3: 16432,
                  a4: nullptr)
              & 0x30) == 0 )
          {
            UTIL_TraceLine(
              a1: (const IHandleEntity *)&vPos.z,
              a2: (int)LocalOrInEyeCSPlayer,
              vecAbsStart: (const Vector *)((char *)&v42 + 4),
              vecAbsEnd: (const Vector *)&v44,
              mask: 0x30u,
              ignore: LocalOrInEyeCSPlayer,
              collisionGroup: 0,
              ptr: (CGameTrace *)&params.m_pOperatorsKV);
            if ( waterTrace.plane.pad[0] != 1 )
            {
              UTIL_TraceLine(
                a1: (const IHandleEntity *)&vPos.z,
                a2: (int)LocalOrInEyeCSPlayer,
                vecAbsStart: (const Vector *)&v44,
                vecAbsEnd: &waterTrace.startpos,
                mask: 0x200400Bu,
                ignore: v15,
                collisionGroup: 0,
                ptr: (CGameTrace *)&waterTrace.m_pEnt);
              if ( BYTE2(ep.m_pflSoundDuration) != 1 )
              {
                v19 = v38[2];
                v20 = *(float *)&ep.m_nChannel;
                v21 = v38[1];
                y = vPos.y;
                v22 = 0;
                *(float *)&v22 = fsqrt(
                                   (float)((float)((float)(v38[2] - *((float *)&v44 + 1))
                                                 * (float)(v38[2] - *((float *)&v44 + 1)))
                                         + (float)((float)(*(float *)&ep.m_nChannel - scale)
                                                 * (float)(*(float *)&ep.m_nChannel - scale)))
                                 + (float)((float)(v38[1] - *(float *)&v44) * (float)(v38[1] - *(float *)&v44)));
                *(_OWORD *)&filter.m_bReliable = v22;
                v23 = 0;
                *(float *)&v23 = fsqrt(
                                   (float)((float)((float)(v19 - *((float *)&v42 + 2))
                                                 * (float)(v19 - *((float *)&v42 + 2)))
                                         + (float)((float)(v20 - *((float *)&v42 + 3))
                                                 * (float)(v20 - *((float *)&v42 + 3))))
                                 + (float)((float)(v21 - *((float *)&v42 + 1)) * (float)(v21 - *((float *)&v42 + 1))));
                v42 = v23;
                v24 = (float)(*(float *)&v23 * 0.80000001) / (float)(*(float *)&v23 + *(float *)&filter.m_bReliable);
                goto LABEL_25;
              }
            }
          }
        }
        y = vPos.y;
      }
      v20 = scale;
      v19 = *((float *)&v44 + 1);
      LODWORD(v21) = v44;
      v24 = v43;
LABEL_25:
      x = vPos.x;
      LODWORD(vPos.y) = &vec3_origin;
      LODWORD(vPos.x) = 65792;
      v44 = __PAIR64__(LODWORD(v19), LODWORD(v21));
      scale = v20 + 8.0;
      ((void (__thiscall *)(ITempEnts *, unsigned __int64 *, Vector *, _DWORD, _DWORD, int))tempents->TempSprite)(
        a1: tempents,
        a2: &v44,
        a3: &vec3_origin,
        a4: LODWORD(v24),
        a5: LODWORD(x),
        a6: 5);
      if ( cl_c4dynamiclight.m_pParent != nullptr && cl_c4dynamiclight.m_pParent->m_Value.m_nValue != 0 )
      {
        v26 = effects->__vftable;
        v27 = (*(int (__thiscall **)(int))(*(_DWORD *)v41 + 40))(a1: v41);
        v28 = (int)v26->CL_AllocDlight(this: effects, a2: v27);
        if ( v28 != 0 )
        {
          v29 = ((int (__thiscall *)(const IHandleEntity *))v15->__vftable[3].SetRefEHandle)(a1: v15);
          v30 = *(_DWORD *)v29;
          v31 = *(_DWORD *)(v29 + 4);
          *(float *)(v28 + 12) = *(float *)(v29 + 8) + 8.0;
          *(_DWORD *)(v28 + 4) = v30;
          *(_DWORD *)(v28 + 8) = v31;
          *(_DWORD *)(v28 + 16) = 1115684864;
          *(_WORD *)(v28 + 20) = 255;
          *(_BYTE *)(v28 + 22) = 0;
          *(float *)(v28 + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.01;
        }
        y = vPos.y;
      }
      v32 = *(float *)(gpGlobals.m_Index + 12);
      v33 = (float)((float)(*(float *)(LODWORD(y) + 3256) - v32) / *(float *)(LODWORD(y) + 3260)) * 0.9 + 0.1;
      if ( v33 < 0.15 )
        v33 = 0.15000001;
      *(float *)(LODWORD(y) + 3248) = v32 + v33;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104223A0
// Name: DT_PlantedC4::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlantedC4::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PlantedC4::g_RecvTable);
  return atexit(func: DT_PlantedC4::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104223C0
// Name: DT_PlantedC4::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlantedC4::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PlantedC4::ignored>();
  DT_PlantedC4::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435320
// Name: DT_PlantedC4::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlantedC4::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PlantedC4::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101BFDE0
// Name: _C_PlantedC4_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PlantedC4_CreateObject(int entnum, int serialNum)
{
  C_PlantedC4 *v2; // eax
  C_PlantedC4 *v3; // eax
  C_PlantedC4 *v4; // esi

  v2 = (C_PlantedC4 *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PlantedC4::C_PlantedC4(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104223D0
// Name: _dynamic_initializer_for__g_PlantedC4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PlantedC4s__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PlantedC4s__);
}

//------------------------------------------------------------------------------
// Address: 0x104223E0
// Name: _dynamic_initializer_for____g_C_TERadioIcon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TERadioIcon__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TERadioIcon);
  _g_C_TERadioIcon.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TERadioIcon_vtbl *)&C_TERadioIcon::`vftable'{for `IClientUnknown'};
  _g_C_TERadioIcon.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TERadioIcon::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TERadioIcon__);
}

//------------------------------------------------------------------------------
// Address: 0x10422410
// Name: _dynamic_initializer_for____g_C_TERadioIconClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TERadioIconClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TERadioIconClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TERadioIconClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435330
// Name: _dynamic_atexit_destructor_for__g_PlantedC4s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlantedC4s__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PlantedC4s);
}

//------------------------------------------------------------------------------
// Address: 0x10435340
// Name: _dynamic_atexit_destructor_for____g_C_TERadioIcon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TERadioIcon__()
{
  _g_C_TERadioIcon.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TERadioIcon_vtbl *)&C_TERadioIcon::`vftable'{for `IClientUnknown'};
  _g_C_TERadioIcon.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TERadioIcon::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TERadioIcon);
}
