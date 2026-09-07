// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/serverbenchmark_base.cpp
// Functions: 18
// ============================================================

#include "game\server\serverbenchmark_base.h"

//------------------------------------------------------------------------------
// Address: 0x10211D10
// Name: Benchmark_ValidTime
// Source: json
//------------------------------------------------------------------------------
double __cdecl Benchmark_ValidTime()
{
  double flRet; // [esp+4h] [ebp-Ch]
  char bOld; // [esp+Ch] [ebp-4h]

  bOld = _Plat_IsInBenchmarkMode();
  _Plat_SetBenchmarkMode(a1: 0);
  flRet = _Plat_FloatTime();
  _Plat_SetBenchmarkMode(a1: bOld);
  return flRet;
}

//------------------------------------------------------------------------------
// Address: 0x10211D50
// Name: public: void CServerBenchmark::EndBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::EndBenchmark(CServerBenchmark *this)
{
  void *v2; // esi
  double v3; // [esp+1Ch] [ebp-Ch]
  char flRunTimea; // [esp+24h] [ebp-4h]
  float flRunTime; // [esp+24h] [ebp-4h]

  flRunTimea = _Plat_IsInBenchmarkMode();
  _Plat_SetBenchmarkMode(a1: 0);
  v3 = _Plat_FloatTime();
  _Plat_SetBenchmarkMode(a1: flRunTimea);
  flRunTime = v3 - this->m_fl_ValidTime_BenchmarkStartTime;
  if ( this->m_nBenchmarkMode == 2 )
  {
    v2 = filesystem->Open(
           this: &filesystem->IBaseFileSystem,
           a2: "sv_benchmark_results.txt",
           a3: "wt",
           a4: "DEFAULT_WRITE_PATH");
    if ( v2 != nullptr )
      filesystem->FPrintf(this: filesystem, a2: v2, a3: "sv_benchmark := %.2f\n", flRunTime);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v2);
    engine->ServerCommand(this: engine, a2: "quit\n");
  }
  this->m_BenchmarkState = BENCHMARKSTATE_NOT_RUNNING;
  engine->SetDedicatedServerBenchmarkMode(this: engine, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10211E20
// Name: public: bool CServerBenchmark::InternalStartBenchmark(int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBenchmark::InternalStartBenchmark(CServerBenchmark *this, int nBenchmarkMode, float flCountdown)
{
  const char *v5; // [esp+0h] [ebp-4h]

  if ( nBenchmarkMode != 0 )
  {
    this->m_nBenchmarkMode = nBenchmarkMode;
    if ( CServerBenchmarkHook::s_pBenchmarkHook == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104B6C58, a2: v5);
    this->m_BenchmarkState = BENCHMARKSTATE_START_WAIT;
    this->m_flBenchmarkStartTime = _Plat_FloatTime();
    this->m_flBenchmarkStartWaitTime = flCountdown;
    this->m_nBotsCreated = 0;
    this->m_nStartWaitCounter = -1;
    engine->SetDedicatedServerBenchmarkMode(this: engine, a2: true);
    CServerBenchmarkHook::s_pBenchmarkHook->StartBenchmark(this: CServerBenchmarkHook::s_pBenchmarkHook);
    CServerBenchmarkHook::s_pBenchmarkHook->GetPhysicsModelNames(
      this: CServerBenchmarkHook::s_pBenchmarkHook,
      a2: &this->m_PhysicsModelNames);
    return 1;
  }
  else
  {
    if ( this->m_BenchmarkState != BENCHMARKSTATE_NOT_RUNNING )
      CServerBenchmark::EndBenchmark(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211EC0
// Name: sv_benchmark_force_start
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10211F60
// Name: public: void CServerBenchmark::UpdateStartWaitCounter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::UpdateStartWaitCounter(CServerBenchmark *this)
{
  double v2; // st7
  int v3; // eax
  int v4; // edi
  double m_flBenchmarkStartWaitTime; // [esp+10h] [ebp-8h]

  m_flBenchmarkStartWaitTime = this->m_flBenchmarkStartWaitTime;
  v2 = _Plat_FloatTime();
  v3 = (int)ceil(X: m_flBenchmarkStartWaitTime - (v2 - this->m_flBenchmarkStartTime));
  v4 = v3;
  if ( this->m_nStartWaitCounter != v3 )
  {
    _Msg(a1: "Starting benchmark in %d seconds...\n", v3);
    this->m_nStartWaitCounter = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211FB0
// Name: public: virtual bool CServerBenchmark::IsBenchmarkRunning(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServerBenchmark::IsBenchmarkRunning(CServerBenchmark *this)
{
  return this->m_BenchmarkState == BENCHMARKSTATE_RUNNING;
}

//------------------------------------------------------------------------------
// Address: 0x10211FC0
// Name: public: virtual int CServerBenchmark::GetTickOffset(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerBenchmark::GetTickOffset(CServerBenchmark *this)
{
  if ( this->m_BenchmarkState == BENCHMARKSTATE_RUNNING )
    return gpGlobals->tickcount - this->m_nBenchmarkStartTick;
  else
    return gpGlobals->tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x10211FE0
// Name: public: virtual int CServerBenchmark::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerBenchmark::RandomInt(CServerBenchmark *this, int nMin, int nMax)
{
  return this->m_RandomStream.RandomInt(this: &this->m_RandomStream, a2: nMin, a3: nMax);
}

//------------------------------------------------------------------------------
// Address: 0x10211FF0
// Name: public: virtual float CServerBenchmark::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CServerBenchmark::RandomFloat(CServerBenchmark *this, float nMin, float nMax)
{
  return (double)this->m_RandomStream.RandomInt(this: &this->m_RandomStream, a2: (int)nMin, a3: (int)nMax);
}

//------------------------------------------------------------------------------
// Address: 0x10212020
// Name: public: void CServerBenchmark::StartVProfRecord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::StartVProfRecord(CServerBenchmark *this)
{
  if ( sv_benchmark_autovprofrecord.m_pParent != nullptr
    && sv_benchmark_autovprofrecord.m_pParent->m_Value.m_nValue != 0 )
  {
    engine->ServerCommand(this: engine, a2: "vprof_record_start benchmark\n");
    engine->ServerExecute(this: engine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212060
// Name: public: virtual bool CServerBenchmark::IsLocalBenchmarkPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBenchmark::IsLocalBenchmarkPlayer(CServerBenchmark *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax
  signed int v3; // eax

  if ( this->m_BenchmarkState == BENCHMARKSTATE_NOT_RUNNING
    || engine->IsDedicatedServer(this: engine)
    || (m_pPev = pPlayer->m_Network.m_pPev) == nullptr
    || (v3 = m_pPev - gpGlobals->pEdicts) != 1 )
  {
    LOBYTE(v3) = 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102120B0
// Name: public: void CServerBenchmark::UpdateBenchmarkCounter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::UpdateBenchmarkCounter(CServerBenchmark *this)
{
  double v2; // st7
  int m_nValue; // ecx
  float flCurTime; // [esp+4h] [ebp-4h]

  v2 = _Plat_FloatTime();
  if ( v2 - this->m_flLastBenchmarkCounterUpdate > 3.0 )
  {
    flCurTime = v2;
    this->m_flLastBenchmarkCounterUpdate = flCurTime;
    if ( sv_benchmark_numticks.m_pParent != nullptr )
      m_nValue = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    _Msg(a1: "Benchmark: %d%% complete.\n", 100 * (gpGlobals->tickcount - this->m_nBenchmarkStartTick) / m_nValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212110
// Name: public: virtual bool CServerBenchmark::StartBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBenchmark::StartBenchmark(CServerBenchmark *this)
{
  ICommandLine *v2; // eax
  int v3; // eax

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  v3 = v2->FindParm(this: v2, a2: "-sv_benchmark");
  return CServerBenchmark::InternalStartBenchmark(
           this,
           nBenchmarkMode: v3 != 0,
           flCountdown: s_flBenchmarkStartWaitSeconds);
}

//------------------------------------------------------------------------------
// Address: 0x10212150
// Name: public: int CServerBenchmark::CalculateBenchmarkCRC(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CServerBenchmark::CalculateBenchmarkCRC@<eax>(CServerBenchmark *this@<ecx>, int a2@<ebp>)
{
  int v2; // ebx
  int i; // edi
  CBasePlayer *v4; // eax
  CBaseEntity *v5; // esi
  int v6; // edi
  int v7; // edi

  v2 = 1;
  for ( i = 0; v2 <= gpGlobals->maxClients; ++v2 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: v2);
    v5 = v4;
    if ( v4 != nullptr && (v4->m_fFlags.m_Value & 0x200) != 0 )
    {
      v6 = CBaseEntity::GetTeamNumber(this: v4) + i;
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2);
      v7 = (int)v5->m_vecAbsOrigin.x + v6;
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2);
      i = (int)v5->m_vecAbsOrigin.y + v7;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102121E0
// Name: public: void CServerBenchmark::OutputResults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::OutputResults(CServerBenchmark *this)
{
  int m_nValue; // eax
  int v3; // eax
  int v4; // eax
  double v5; // [esp+10h] [ebp-Ch]
  char flRunTimea; // [esp+18h] [ebp-4h]
  float flRunTime; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  flRunTimea = _Plat_IsInBenchmarkMode();
  _Plat_SetBenchmarkMode(a1: 0);
  v5 = _Plat_FloatTime();
  _Plat_SetBenchmarkMode(a1: flRunTimea);
  flRunTime = v5 - this->m_fl_ValidTime_BenchmarkStartTime;
  _Warning(a1: "------------------ SERVER BENCHMARK RESULTS ------------------\n");
  _Warning(a1: "Total time          : %.2f seconds\n", flRunTime);
  if ( sv_benchmark_numticks.m_pParent != nullptr )
    m_nValue = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  _Warning(a1: "Num ticks simulated : %d\n", m_nValue);
  if ( sv_benchmark_numticks.m_pParent != nullptr )
    v3 = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  _Warning(a1: "Ticks per second    : %.2f\n", (float)((float)v3 / flRunTime));
  v4 = CServerBenchmark::CalculateBenchmarkCRC(this, a2: (int)&savedregs);
  _Warning(a1: "Benchmark CRC       : %d\n", v4);
  _Warning(a1: "--------------------------------------------------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x102122C0
// Name: public: void CServerBenchmark::UpdateVPhysicsObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::UpdateVPhysicsObjects(CServerBenchmark *this)
{
  int m_nValue; // eax
  int v3; // edi
  int m_Size; // eax
  const char *v5; // edi
  CBasePlayer **m_pMemory; // ebx
  CBasePlayer *v7; // eax
  CBasePlayer *v8; // edx
  const char *v9; // ecx
  CBasePlayer **v10; // ecx
  int v11; // eax
  const char *v12; // edx
  CServerBenchmark_vtbl *v13; // eax
  int v14; // edi
  float *v15; // eax
  double v16; // st7
  CPhysicsProp *v17; // eax
  CBaseEntity *v18; // ebx
  const char *m_Index; // ecx
  int m_nAllocationCount; // eax
  CBasePlayer *v21; // ecx
  CHandle<CBaseEntity> *v22; // edx
  int v23; // eax
  float *p_m_Index; // ecx
  double v25; // st7
  int v26; // ecx
  int v27; // edi
  int v28; // ebx
  unsigned int v29; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v31; // edi
  double v32; // st7
  void (__thiscall *dtr_IHandleEntity)(IHandleEntity *); // eax
  void (__thiscall *v34)(IHandleEntity_vtbl *, Vector *); // edx
  CUtlVector<CBasePlayer *,CUtlMemory<CBasePlayer *,int> > curPlayers; // [esp+7Ch] [ebp-44h] BYREF
  Vector vOffset; // [esp+90h] [ebp-30h] BYREF
  Vector vTraceEnd; // [esp+9Ch] [ebp-24h] BYREF
  Vector vSpawnPos; // [esp+A8h] [ebp-18h] BYREF
  CBasePlayer *pPlayer; // [esp+B4h] [ebp-Ch]
  const char *pModelName; // [esp+B8h] [ebp-8h]
  int i; // [esp+BCh] [ebp-4h]
  int savedregs; // [esp+C0h] [ebp+0h] BYREF

  if ( sv_benchmark_numticks.m_pParent != nullptr )
    m_nValue = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = this->m_nLastPhysicsObjectTick + m_nValue / s_nBenchmarkPhysicsObjects;
  if ( ((int (*)(void))this->GetTickOffset)() >= v3 )
  {
    m_Size = this->m_PhysicsObjects.m_Size;
    this->m_nLastPhysicsObjectTick = v3;
    if ( m_Size < s_nBenchmarkPhysicsObjects )
    {
      v5 = nullptr;
      m_pMemory = nullptr;
      memset(&curPlayers, 0, sizeof(curPlayers));
      i = 1;
      if ( gpGlobals->maxClients >= 1 )
      {
        do
        {
          v7 = UTIL_PlayerByIndex(playerIndex: i);
          v8 = v7;
          pPlayer = v7;
          if ( v7 != nullptr && (v7->m_fFlags.m_Value & 0x200) != 0 )
          {
            v9 = v5;
            pModelName = v5;
            if ( (int)(v5 + 1) > curPlayers.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&curPlayers,
                num: (int)&v5[-curPlayers.m_Memory.m_nAllocationCount + 1]);
              v5 = (const char *)curPlayers.m_Size;
              m_pMemory = curPlayers.m_Memory.m_pMemory;
              v9 = pModelName;
              v8 = pPlayer;
            }
            curPlayers.m_Size = (int)++v5;
            curPlayers.m_pElements = m_pMemory;
            if ( v5 - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[(_DWORD)v9 + 1], src: &m_pMemory[(_DWORD)v9], count: 4 * (v5 - v9 - 1));
              v9 = pModelName;
              v8 = pPlayer;
            }
            v10 = &m_pMemory[(_DWORD)v9];
            if ( v10 != nullptr )
              *v10 = v8;
          }
          ++i;
        }
        while ( i <= gpGlobals->maxClients );
        if ( (int)v5 > 0 )
        {
          v11 = this->m_PhysicsModelNames.m_Size;
          if ( v11 > 0 )
          {
            v12 = this->m_PhysicsModelNames.m_Memory.m_pMemory[this->RandomInt(this, a2: 0, a3: v11 - 1)];
            v13 = this->__vftable;
            pModelName = v12;
            v14 = v13->RandomInt(this, a2: 0, a3: (int)(v5 - 1));
            v15 = (float *)m_pMemory[v14]->EyePosition(this: m_pMemory[v14], result: &vOffset);
            vSpawnPos.x = *v15;
            vSpawnPos.y = v15[1];
            vSpawnPos.z = v15[2] + 50.0;
            *(float *)&pPlayer = 0.0;
            while ( 1 )
            {
              vOffset.x = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                            a1: this,
                            a2: -990248960,
                            a3: 1157234688);
              v16 = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                      a1: this,
                      a2: -990248960,
                      a3: 1157234688);
              vTraceEnd.x = vSpawnPos.x + vOffset.x;
              vTraceEnd.z = vSpawnPos.z;
              vTraceEnd.y = v16 + vSpawnPos.y;
              v17 = CreatePhysicsProp(
                      a1: (IHandleEntity_vtbl *)&savedregs,
                      a2: v14,
                      a3: (int)this,
                      pModelName,
                      vTraceStart: &vSpawnPos,
                      &vTraceEnd,
                      pTraceIgnore: m_pMemory[v14],
                      bRequireVCollide: false,
                      pClassName: "prop_physics_multiplayer");
              v18 = v17;
              if ( v17 != nullptr )
                break;
              m_pMemory = curPlayers.m_Memory.m_pMemory;
              pPlayer = (CBasePlayer *)((char *)pPlayer + 1);
              if ( (int)pPlayer >= 15 )
                goto LABEL_29;
            }
            m_Index = (const char *)v17->GetRefEHandle(this: v17)->m_Index;
            m_nAllocationCount = this->m_PhysicsObjects.m_Memory.m_nAllocationCount;
            pModelName = m_Index;
            pPlayer = (CBasePlayer *)this->m_PhysicsObjects.m_Size;
            v21 = pPlayer;
            if ( (int)&pPlayer->__vftable + 1 > m_nAllocationCount )
            {
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PhysicsObjects,
                num: (int)&pPlayer->__vftable - m_nAllocationCount + 1);
              v21 = pPlayer;
            }
            ++this->m_PhysicsObjects.m_Size;
            v22 = this->m_PhysicsObjects.m_Memory.m_pMemory;
            v23 = this->m_PhysicsObjects.m_Size - (_DWORD)v21 - 1;
            this->m_PhysicsObjects.m_pElements = v22;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[(_DWORD)v21 + 1], src: &v22[(_DWORD)v21], count: 4 * v23);
              v21 = pPlayer;
            }
            p_m_Index = (float *)&this->m_PhysicsObjects.m_Memory.m_pMemory[(_DWORD)v21].m_Index;
            if ( p_m_Index != nullptr )
              *p_m_Index = *(float *)&pModelName;
            *(float *)&pPlayer = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                                   a1: this,
                                   a2: -1007026176,
                                   a3: 1140457472);
            *(float *)&pModelName = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                                      a1: this,
                                      a2: -1007026176,
                                      a3: 1140457472);
            v25 = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                    a1: this,
                    a2: -1007026176,
                    a3: 1140457472);
            vOffset.x = *(float *)&pPlayer;
            vOffset.y = *(float *)&pModelName;
            vOffset.z = v25;
            CBaseEntity::SetAbsVelocity(this: v18, vecAbsVelocity: &vOffset);
            m_pMemory = curPlayers.m_Memory.m_pMemory;
          }
        }
      }
LABEL_29:
      if ( curPlayers.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
  if ( sv_benchmark_numticks.m_pParent != nullptr )
    v26 = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
  else
    v26 = 0;
  v27 = this->m_nLastPhysicsForceTick + v26 / 20;
  if ( this->GetTickOffset(this) >= v27 )
  {
    v28 = 0;
    for ( this->m_nLastPhysicsForceTick = v27; v28 < this->m_PhysicsObjects.m_Size; ++v28 )
    {
      v29 = this->m_PhysicsObjects.m_Memory.m_pMemory[v28].m_Index;
      if ( v29 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber == HIWORD(v29) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          v31 = m_pEntity[82].__vftable;
          if ( v31 != nullptr )
          {
            ((void (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
              a1: this,
              a2: -929924096,
              a3: 1217559552);
            ((void (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
              a1: this,
              a2: -929924096,
              a3: 1217559552);
            ((void (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
              a1: this,
              a2: 1217559552,
              a3: 1217559552);
            *(float *)&pPlayer = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                                   a1: this,
                                   a2: -923524096,
                                   a3: 1223959552);
            *(float *)&pModelName = ((double (__thiscall *)(CServerBenchmark *, int, int))this->RandomFloat)(
                                      a1: this,
                                      a2: -923524096,
                                      a3: 1223959552);
            v32 = ((double (__thiscall *)(CServerBenchmark *, _DWORD, int))this->RandomFloat)(
                    a1: this,
                    a2: 0,
                    a3: 1223959552);
            dtr_IHandleEntity = v31->dtr_IHandleEntity;
            vOffset.x = *(float *)&pPlayer;
            v34 = *((void (__thiscall **)(IHandleEntity_vtbl *, Vector *))dtr_IHandleEntity + 60);
            vOffset.y = *(float *)&pModelName;
            vOffset.z = v32;
            v34(a1: v31, a2: &vOffset);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102127B0
// Name: public: virtual void CServerBenchmark::UpdateBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBenchmark::UpdateBenchmark(CServerBenchmark *this)
{
  CServerBenchmark::EBenchmarkState m_BenchmarkState; // eax
  double v3; // st7
  int v4; // edi
  int m_nValue; // eax

  m_BenchmarkState = this->m_BenchmarkState;
  if ( m_BenchmarkState != BENCHMARKSTATE_NOT_RUNNING )
  {
    if ( m_BenchmarkState == BENCHMARKSTATE_START_WAIT )
    {
      if ( this->m_flBenchmarkStartWaitTime > _Plat_FloatTime() - this->m_flBenchmarkStartTime )
      {
        CServerBenchmark::UpdateStartWaitCounter(this);
        return;
      }
      _Msg(a1: "Starting benchmark!\n");
      v3 = _Plat_FloatTime();
      this->m_flBenchmarkStartTime = v3;
      this->m_flLastBenchmarkCounterUpdate = v3;
      this->m_fl_ValidTime_BenchmarkStartTime = Benchmark_ValidTime();
      this->m_nBenchmarkStartTick = gpGlobals->tickcount;
      this->m_nLastPhysicsForceTick = 0;
      this->m_nLastPhysicsObjectTick = 0;
      this->m_BenchmarkState = BENCHMARKSTATE_RUNNING;
      CServerBenchmark::StartVProfRecord(this);
      _RandomSeed(a1: 0);
      this->m_RandomStream.SetSeed(this: &this->m_RandomStream, a2: 0);
    }
    v4 = gpGlobals->tickcount - this->m_nBenchmarkStartTick;
    CServerBenchmark::UpdateBenchmarkCounter(this);
    if ( sv_benchmark_numticks.m_pParent != nullptr )
      m_nValue = sv_benchmark_numticks.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( v4 < m_nValue )
    {
      if ( this->m_nBotsCreated < s_nBenchmarkBotsToCreate
        && (gpGlobals->tickcount - this->m_nBenchmarkStartTick) % s_nBenchmarkBotCreateInterval == 0 )
      {
        CServerBenchmarkHook::s_pBenchmarkHook->CreateBot(this: CServerBenchmarkHook::s_pBenchmarkHook);
        ++this->m_nBotsCreated;
      }
      CServerBenchmark::UpdateVPhysicsObjects(this);
      CServerBenchmarkHook::s_pBenchmarkHook->UpdateBenchmark(this: CServerBenchmarkHook::s_pBenchmarkHook);
    }
    else
    {
      if ( sv_benchmark_autovprofrecord.m_pParent != nullptr
        && sv_benchmark_autovprofrecord.m_pParent->m_Value.m_nValue != 0 )
      {
        engine->ServerCommand(this: engine, a2: "vprof_record_stop\n");
        engine->ServerExecute(this: engine);
      }
      CServerBenchmark::OutputResults(this);
      CServerBenchmark::EndBenchmark(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212900
// Name: __CreateCServerGameTagsIServerGameTags_interface_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_4()
{
  return &_g_CServerGameTags_singleton_4;
}
