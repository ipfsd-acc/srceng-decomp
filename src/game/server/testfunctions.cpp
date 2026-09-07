// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/testfunctions.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10233A90
// Name: void Test_CreateEntity(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_CreateEntity(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // [esp+0h] [ebp-8h]

  if ( args->m_nArgc < 2 )
    _Error(this: (ISceneTokenProcessor *)&stru_104C1C10, a2: v2);
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  else
    v1 = locale;
  if ( CreateEntityByName(className: v1, iForceEdictIndex: -1, bNotify: true) == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_104C1BF0, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10233AE0
// Name: void Test_RandomPlayerPosition(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __cdecl Test_RandomPlayerPosition()
{
  CBasePlayer *LocalPlayer; // edi
  CWorld *WorldEntity; // eax
  IUniformRandomStream *v2; // ecx
  CWorld *v3; // esi
  float y; // xmm2_4
  float x; // xmm0_4
  float v6; // xmm1_4
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  const char *v9; // [esp+8h] [ebp-2Ch]
  Vector vecOrigin; // [esp+10h] [ebp-24h] BYREF
  Vector vMin; // [esp+1Ch] [ebp-18h]
  Vector vMax; // [esp+28h] [ebp-Ch]

  LocalPlayer = UTIL_GetLocalPlayer();
  WorldEntity = GetWorldEntity();
  v3 = WorldEntity;
  if ( LocalPlayer != nullptr )
  {
    if ( WorldEntity == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104C1C48, a2: v9);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)"Test_RandomPlayerPosition: no local player entity.", a2: v9);
  }
  y = v3->m_WorldMaxs.m_Value.y;
  x = v3->m_WorldMins.m_Value.x;
  vMin.y = v3->m_WorldMins.m_Value.y;
  vMin.z = v3->m_WorldMins.m_Value.z;
  v6 = v3->m_WorldMaxs.m_Value.x;
  vMax.y = y;
  vMax.z = v3->m_WorldMaxs.m_Value.z;
  _RandomFloat(this: v2, a2: x, a3: v6);
  _RandomFloat(this: v7, a2: vMin.y, a3: y);
  _RandomFloat(this: v8, a2: vMin.z, a3: vMax.z);
  CBasePlayer::ForceOrigin(this: LocalPlayer, &vecOrigin);
}
