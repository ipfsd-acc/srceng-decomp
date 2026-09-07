// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_testtraceline.cpp
// Functions: 267
// ============================================================

#include "game\client\c_testtraceline.h"

//------------------------------------------------------------------------------
// Address: 0x10010420
// Name: int ClientClassInit<struct DT_LocalActiveWeaponData::ignored>(struct DT_LocalActiveWeaponData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_LocalActiveWeaponData::ignored>()
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    RecvPropInt(
      result: RecvProps,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropTime(result: &RecvProps[1], pVarName: "m_flNextPrimaryAttack", offset: 3264, sizeofVar: 4);
    RecvPropTime(result: &RecvProps[2], pVarName: "m_flNextSecondaryAttack", offset: 3268, sizeofVar: 4);
    RecvPropInt(
      result: &RecvProps[3],
      pVarName: "m_nNextThinkTick",
      offset: 240,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropTime(result: &RecvProps[4], pVarName: "m_flTimeWeaponIdle", offset: 3300, sizeofVar: 4);
  }
  RecvTable::Construct(
    this: &DT_LocalActiveWeaponData::g_RecvTable,
    pProps: &RecvProps[1],
    nProps: 4,
    pNetTableName: "DT_LocalActiveWeaponData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100104D0
// Name: int ClientClassInit<struct DT_LocalWeaponData::ignored>(struct DT_LocalWeaponData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_LocalWeaponData::ignored>()
{
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    RecvPropInt(
      result: RecvProps_0,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_0[1],
      pVarName: "m_iClip1",
      offset: 3292,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntSubOne);
    RecvPropEHandle(
      result: &RecvProps_0[2],
      pVarName: "m_iClip2",
      offset: 3296,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntSubOne);
    RecvPropInt(
      result: &RecvProps_0[3],
      pVarName: "m_iPrimaryAmmoType",
      offset: 3284,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_0[4],
      pVarName: "m_iSecondaryAmmoType",
      offset: 3288,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_0[5],
      pVarName: "m_nViewModelIndex",
      offset: 3260,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_0[6], pVarName: "m_bFlipViewModel", offset: 3372, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_LocalWeaponData::g_RecvTable,
    pProps: &RecvProps_0[1],
    nProps: 6,
    pNetTableName: "DT_LocalWeaponData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100105C0
// Name: int ClientClassInit<struct DT_BaseCombatWeapon::ignored>(struct DT_BaseCombatWeapon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseCombatWeapon::ignored>()
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    RecvPropInt(
      result: RecvProps_1,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_1[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_1[2],
      pVarName: "LocalWeaponData",
      offset: 0,
      flags: 0,
      pTable: &DT_LocalWeaponData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_1[3],
      pVarName: "LocalActiveWeaponData",
      offset: 0,
      flags: 0,
      pTable: &DT_LocalActiveWeaponData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_1[4],
      pVarName: "m_iViewModelIndex",
      offset: 3272,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_1[5],
      pVarName: "m_iWorldModelIndex",
      offset: 3276,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_1[6], pVarName: "m_iState", offset: 3280, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_1[7],
      pVarName: "m_hOwner",
      offset: 3256,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_BaseCombatWeapon::g_RecvTable,
    pProps: &RecvProps_1[1],
    nProps: 7,
    pNetTableName: "DT_BaseCombatWeapon");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017670
// Name: int ClientClassInit<struct DT_BaseGrenade::ignored>(struct DT_BaseGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseGrenade::ignored>()
{
  if ( (_S5_3 & 1) == 0 )
  {
    _S5_3 |= 1u;
    RecvPropInt(
      result: RecvProps_2,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_2[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_2[2],
      pVarName: "m_flDamage",
      offset: 3276,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_2[3],
      pVarName: "m_DmgRadius",
      offset: 3260,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_2[4], pVarName: "m_bIsLive", offset: 3257, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_2[5],
      pVarName: "m_hThrower",
      offset: 3284,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropVector(
      result: &RecvProps_2[6],
      pVarName: "m_vecVelocity",
      offset: 264,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_LocalVelocity);
    RecvPropInt(result: &RecvProps_2[7], pVarName: "m_fFlags", offset: 248, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseGrenade::g_RecvTable,
    pProps: &RecvProps_2[1],
    nProps: 7,
    pNetTableName: "DT_BaseGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017CC0
// Name: int ClientClassInit<struct DT_BaseParticleEntity::ignored>(struct DT_BaseParticleEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseParticleEntity::ignored>()
{
  if ( (_S5_4 & 1) == 0 )
  {
    _S5_4 |= 1u;
    RecvPropInt(
      result: RecvProps_3,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_3[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BaseParticleEntity::g_RecvTable,
    pProps: &RecvProps_3[1],
    nProps: 1,
    pNetTableName: "DT_BaseParticleEntity");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF80
// Name: int ClientClassInit<struct DT_BaseViewModel::ignored>(struct DT_BaseViewModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseViewModel::ignored>()
{
  if ( (_S5_6 & 1) == 0 )
  {
    _S5_6 |= 1u;
    RecvPropInt(
      result: RecvProps_4,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_4[1],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_4[2],
      pVarName: "m_hWeapon",
      offset: 3292,
      sizeofVar: 4,
      proxyFn: RecvProxy_Weapon);
    RecvPropInt(result: &RecvProps_4[3], pVarName: "m_nSkin", offset: 2476, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_4[4], pVarName: "m_nBody", offset: 2480, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_4[5],
      pVarName: "m_nSequence",
      offset: 3060,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_4[6],
      pVarName: "m_nViewModelIndex",
      offset: 3284,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_4[7],
      pVarName: "m_flPlaybackRate",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_4[8],
      pVarName: "m_fEffects",
      offset: 232,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_EffectFlags);
    RecvPropInt(
      result: &RecvProps_4[9],
      pVarName: "m_nAnimationParity",
      offset: 3288,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_4[10],
      pVarName: "m_hOwner",
      offset: 3296,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_4[11],
      pVarName: "m_nNewSequenceParity",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_4[12],
      pVarName: "m_nResetEventsParity",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_4[13],
      pVarName: "m_nMuzzleFlashParity",
      offset: 2516,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseViewModel::g_RecvTable,
    pProps: &RecvProps_4[1],
    nProps: 13,
    pNetTableName: "DT_BaseViewModel");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBC0
// Name: int ClientClassInit<struct DT_Beam::ignored>(struct DT_Beam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Beam::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60

  if ( (_S6_3 & 1) == 0 )
  {
    _S6_3 |= 1u;
    RecvPropInt(
      result: RecvProps_5,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_5[1],
      pVarName: "m_nBeamType",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_5[2],
      pVarName: "m_nBeamFlags",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_5[3],
      pVarName: "m_nNumBeamEnts",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropEHandle(
            result: &v1,
            pVarName: "m_hAttachEntity[0]",
            offset: 2468,
            sizeofVar: 4,
            proxyFn: RecvProxy_IntToEHandle);
    RecvPropArray3(
      result: &RecvProps_5[4],
      pVarName: "m_hAttachEntity",
      offset: 2468,
      sizeofVar: 4,
      elements: 10,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(
            result: &v1,
            pVarName: "m_nAttachIndex[0]",
            offset: 2508,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_5[5],
      pVarName: "m_nAttachIndex",
      offset: 2508,
      sizeofVar: 4,
      elements: 10,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_5[6],
      pVarName: "m_nHaloIndex",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_5[7],
      pVarName: "m_fHaloScale",
      offset: 2560,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[8],
      pVarName: "m_fWidth",
      offset: 2548,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[9],
      pVarName: "m_fEndWidth",
      offset: 2552,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[10],
      pVarName: "m_fFadeLength",
      offset: 2556,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[11],
      pVarName: "m_fAmplitude",
      offset: 2564,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[12],
      pVarName: "m_fStartFrame",
      offset: 2568,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[13],
      pVarName: "m_fSpeed",
      offset: 2572,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Beam_ScrollSpeed);
    RecvPropFloat(
      result: &RecvProps_5[14],
      pVarName: "m_flFrameRate",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_5[15],
      pVarName: "m_flHDRColorScale",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_5[16],
      pVarName: "m_clrRender",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_5[17],
      pVarName: "m_nRenderFX",
      offset: 590,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_5[18],
      pVarName: "m_nRenderMode",
      offset: 591,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_5[19],
      pVarName: "m_flFrame",
      offset: 2576,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_5[20],
      pVarName: "m_nClipStyle",
      offset: 2580,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_5[21],
      pVarName: "m_vecEndPos",
      offset: 2584,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_5[22],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_5[23],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_5[24],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(this: &DT_Beam::g_RecvTable, pProps: &RecvProps_5[1], nProps: 24, pNetTableName: "DT_Beam");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100243C0
// Name: int ClientClassInit<struct DT_AI_BaseNPC::ignored>(struct DT_AI_BaseNPC::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_AI_BaseNPC::ignored>()
{
  if ( (_S5_9 & 1) == 0 )
  {
    _S5_9 |= 1u;
    RecvPropInt(
      result: RecvProps_6,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_6[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatCharacter::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_6[2],
      pVarName: "m_lifeState",
      offset: 595,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_6[3], pVarName: "m_bPerformAvoidance", offset: 4676, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_6[4], pVarName: "m_bIsMoving", offset: 4677, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_6[5], pVarName: "m_bFadeCorpse", offset: 4678, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_6[6],
      pVarName: "m_iDeathPose",
      offset: 4660,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_6[7],
      pVarName: "m_iDeathFrame",
      offset: 4664,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_6[8],
      pVarName: "m_iSpeedModRadius",
      offset: 4668,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_6[9],
      pVarName: "m_iSpeedModSpeed",
      offset: 4672,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_6[10],
      pVarName: "m_bSpeedModActive",
      offset: 4679,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_6[11], pVarName: "m_bImportanRagdoll", offset: 4680, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_6[12],
      pVarName: "m_flTimePingEffect",
      offset: 4656,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_AI_BaseNPC::g_RecvTable,
    pProps: &RecvProps_6[1],
    nProps: 12,
    pNetTableName: "DT_AI_BaseNPC");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100248F0
// Name: int ClientClassInit<struct DT_ServerAnimationData::ignored>(struct DT_ServerAnimationData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ServerAnimationData::ignored>()
{
  if ( (_S5_10 & 1) == 0 )
  {
    _S5_10 |= 1u;
    RecvPropInt(
      result: RecvProps_7,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_7[1],
      pVarName: "m_flCycle",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_ServerAnimationData::g_RecvTable,
    pProps: &RecvProps_7[1],
    nProps: 1,
    pNetTableName: "DT_ServerAnimationData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025450
// Name: int ClientClassInit<struct DT_BoneFollower::ignored>(struct DT_BoneFollower::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BoneFollower::ignored>()
{
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    RecvPropInt(
      result: RecvProps_8,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_8[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_8[2],
      pVarName: "m_modelIndex",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_8[3],
      pVarName: "m_solidIndex",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BoneFollower::g_RecvTable,
    pProps: &RecvProps_8[1],
    nProps: 3,
    pNetTableName: "DT_BoneFollower");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100259D0
// Name: int ClientClassInit<struct DT_BaseAnimating::ignored>(struct DT_BaseAnimating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseAnimating::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60

  if ( (_S6_4 & 1) == 0 )
  {
    _S6_4 |= 1u;
    RecvPropInt(
      result: RecvProps_9,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_9[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_9[2],
      pVarName: "m_nSequence",
      offset: 3060,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Sequence);
    RecvPropInt(
      result: &RecvProps_9[3],
      pVarName: "m_nForceBone",
      offset: 2548,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_9[4],
      pVarName: "m_vecForce",
      offset: 2536,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_9[5], pVarName: "m_nSkin", offset: 2476, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_9[6], pVarName: "m_nBody", offset: 2480, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_9[7],
      pVarName: "m_nHitboxSet",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_9[8],
      pVarName: "m_flModelScale",
      offset: 2684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    v3 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flPoseParameter[0]",
            offset: 2732,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_9[9],
      pVarName: "m_flPoseParameter",
      offset: 2732,
      sizeofVar: 4,
      elements: 24,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_9[10],
      pVarName: "m_flPlaybackRate",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    v4 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flEncodedController[0]",
            offset: 2500,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_9[11],
      pVarName: "m_flEncodedController",
      offset: 2500,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_9[12],
      pVarName: "m_bClientSideAnimation",
      offset: 3028,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_9[13],
      pVarName: "m_bClientSideFrameReset",
      offset: 2600,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_9[14], pVarName: "m_bClientSideRagdoll", offset: 621, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_9[15], pVarName: "m_bForceRTTShadows", offset: 3144, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_9[16],
      pVarName: "m_nNewSequenceParity",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_9[17],
      pVarName: "m_nResetEventsParity",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_9[18],
      pVarName: "m_nMuzzleFlashParity",
      offset: 2516,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_9[19],
      pVarName: "m_hLightingOrigin",
      offset: 3200,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropDataTable(
      result: &RecvProps_9[20],
      pVarName: "serveranimdata",
      offset: 0,
      flags: 0,
      pTable: &DT_ServerAnimationData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_9[21],
      pVarName: "m_flFrozen",
      offset: 2604,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_9[22],
      pVarName: "m_ScaleType",
      offset: 2688,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_9[23], pVarName: "m_bSuppressAnimSounds", offset: 3206, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_BaseAnimating::g_RecvTable,
    pProps: &RecvProps_9[1],
    nProps: 23,
    pNetTableName: "DT_BaseAnimating");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100337B0
// Name: int ClientClassInit<struct DT_BaseAnimatingOverlay::ignored>(struct DT_BaseAnimatingOverlay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseAnimatingOverlay::ignored>()
{
  if ( (_S7_2 & 1) == 0 )
  {
    _S7_2 |= 1u;
    RecvPropInt(
      result: RecvProps_10,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_10[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_10[2],
      pVarName: "overlay_vars",
      offset: 0,
      flags: 0,
      pTable: &DT_OverlayVars::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BaseAnimatingOverlay::g_RecvTable,
    pProps: &RecvProps_10[1],
    nProps: 2,
    pNetTableName: "DT_BaseAnimatingOverlay");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033B30
// Name: int ClientClassInit<struct DT_Animationlayer::ignored>(struct DT_Animationlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Animationlayer::ignored>()
{
  if ( (_S5_11 & 1) == 0 )
  {
    _S5_11 |= 1u;
    RecvPropInt(
      result: RecvProps_11,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_11[1],
      pVarName: "m_nSequence",
      offset: 12,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_SequenceChanged);
    RecvPropFloat(
      result: &RecvProps_11[2],
      pVarName: "m_flCycle",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_CycleChanged);
    RecvPropFloat(
      result: &RecvProps_11[3],
      pVarName: "m_flPrevCycle",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_11[4],
      pVarName: "m_flWeight",
      offset: 20,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_WeightChanged);
    RecvPropInt(
      result: &RecvProps_11[5],
      pVarName: "m_nOrder",
      offset: 8,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_OrderChanged);
  }
  RecvTable::Construct(
    this: &DT_Animationlayer::g_RecvTable,
    pProps: &RecvProps_11[1],
    nProps: 5,
    pNetTableName: "DT_Animationlayer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100369C0
// Name: int ClientClassInit<struct DT_OverlayVars::ignored>(struct DT_OverlayVars::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_OverlayVars::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^1C.60

  if ( (_S6_5 & 1) == 0 )
  {
    _S6_5 |= 1u;
    RecvPropInt(
      result: RecvProps_12,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropDataTable(
            result: &v1,
            pVarName: nullptr,
            offset: 0,
            flags: 0,
            pTable: &DT_Animationlayer::g_RecvTable,
            varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropUtlVector(
      result: &RecvProps_12[1],
      pVarName: "m_AnimOverlay",
      offset: 3256,
      sizeofVar: 40,
      fn: ResizeAnimationLayerCallback,
      ensureFn: UtlVectorTemplate<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::EnsureCapacity,
      nMaxElements: 15,
      pArrayProp: v3);
  }
  RecvTable::Construct(
    this: &DT_OverlayVars::g_RecvTable,
    pProps: &RecvProps_12[1],
    nProps: 1,
    pNetTableName: "DT_OverlayVars");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10036AD0
// Name: int ClientClassInit<struct DT_BCCLocalPlayerExclusive::ignored>(struct DT_BCCLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BCCLocalPlayerExclusive::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^14.60

  if ( (_S5_12 & 1) == 0 )
  {
    _S5_12 |= 1u;
    RecvPropInt(
      result: RecvProps_13,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropTime(result: &RecvProps_13[1], pVarName: "m_flNextAttack", offset: 4256, sizeofVar: 4);
    v3 = *RecvPropEHandle(
            result: &v1,
            pVarName: "m_hMyWeapons[0]",
            offset: 4388,
            sizeofVar: 4,
            proxyFn: RecvProxy_IntToEHandle);
    RecvPropArray3(
      result: &RecvProps_13[2],
      pVarName: "m_hMyWeapons",
      offset: 4388,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BCCLocalPlayerExclusive::g_RecvTable,
    pProps: &RecvProps_13[1],
    nProps: 2,
    pNetTableName: "DT_BCCLocalPlayerExclusive");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10036B90
// Name: int ClientClassInit<struct DT_BaseCombatCharacter::ignored>(struct DT_BaseCombatCharacter::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseCombatCharacter::ignored>()
{
  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    RecvPropInt(
      result: RecvProps_14,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_14[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseFlex::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_14[2],
      pVarName: "bcc_localdata",
      offset: 0,
      flags: 0,
      pTable: &DT_BCCLocalPlayerExclusive::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_14[3],
      pVarName: "m_hActiveWeapon",
      offset: 4644,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_BaseCombatCharacter::g_RecvTable,
    pProps: &RecvProps_14[1],
    nProps: 3,
    pNetTableName: "DT_BaseCombatCharacter");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10037810
// Name: int ClientClassInit<struct DT_BaseDoor::ignored>(struct DT_BaseDoor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseDoor::ignored>()
{
  if ( (_S5_13 & 1) == 0 )
  {
    _S5_13 |= 1u;
    RecvPropInt(
      result: RecvProps_15,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_15[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseToggle::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_15[2],
      pVarName: "m_flWaveHeight",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_BaseDoor::g_RecvTable,
    pProps: &RecvProps_15[1],
    nProps: 2,
    pNetTableName: "DT_BaseDoor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039A20
// Name: int ClientClassInit<struct DT_AnimTimeMustBeFirst::ignored>(struct DT_AnimTimeMustBeFirst::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_AnimTimeMustBeFirst::ignored>()
{
  if ( (_S5_14 & 1) == 0 )
  {
    _S5_14 |= 1u;
    RecvPropInt(
      result: RecvProps_16,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_16[1],
      pVarName: "m_flAnimTime",
      offset: 596,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_AnimTime);
  }
  RecvTable::Construct(
    this: &DT_AnimTimeMustBeFirst::g_RecvTable,
    pProps: &RecvProps_16[1],
    nProps: 1,
    pNetTableName: "DT_AnimTimeMustBeFirst");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10040C60
// Name: int ClientClassInit<struct DT_BaseEntity::ignored>(struct DT_BaseEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseEntity::ignored>()
{
  if ( (_S6_7 & 1) == 0 )
  {
    _S6_7 |= 1u;
    RecvPropInt(
      result: RecvProps_17,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_17[1],
      pVarName: "AnimTimeMustBeFirst",
      offset: 0,
      flags: 0,
      pTable: &DT_AnimTimeMustBeFirst::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_17[2],
      pVarName: "m_flSimulationTime",
      offset: 604,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_SimulationTime);
    RecvPropInt(
      result: &RecvProps_17[3],
      pVarName: "m_cellbits",
      offset: 112,
      sizeofVar: 4,
      flags: 0,
      varProxy: C_BaseEntity::RecvProxy_CellBits);
    RecvPropInt(
      result: &RecvProps_17[4],
      pVarName: "m_cellX",
      offset: 120,
      sizeofVar: 4,
      flags: 0,
      varProxy: C_BaseEntity::RecvProxy_CellX);
    RecvPropInt(
      result: &RecvProps_17[5],
      pVarName: "m_cellY",
      offset: 124,
      sizeofVar: 4,
      flags: 0,
      varProxy: C_BaseEntity::RecvProxy_CellY);
    RecvPropInt(
      result: &RecvProps_17[6],
      pVarName: "m_cellZ",
      offset: 128,
      sizeofVar: 4,
      flags: 0,
      varProxy: C_BaseEntity::RecvProxy_CellZ);
    RecvPropVector(
      result: &RecvProps_17[7],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: C_BaseEntity::RecvProxy_CellOrigin);
    RecvPropVector(
      result: &RecvProps_17[8],
      pVarName: "m_angRotation",
      offset: 288,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_17[9],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[10],
      pVarName: "m_fEffects",
      offset: 232,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_EffectFlags);
    RecvPropInt(
      result: &RecvProps_17[11],
      pVarName: "m_nRenderMode",
      offset: 591,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[12],
      pVarName: "m_nRenderFX",
      offset: 590,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[13],
      pVarName: "m_clrRender",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_ClrRender);
    RecvPropInt(
      result: &RecvProps_17[14],
      pVarName: "m_iTeamNum",
      offset: 236,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[15],
      pVarName: "m_CollisionGroup",
      offset: 1124,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_17[16],
      pVarName: "m_flElasticity",
      offset: 908,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_17[17],
      pVarName: "m_flShadowCastDistance",
      offset: 912,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropEHandle(
      result: &RecvProps_17[18],
      pVarName: "m_hOwnerEntity",
      offset: 320,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_17[19],
      pVarName: "m_hEffectEntity",
      offset: 2364,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_17[20],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_17[21],
      pVarName: "m_iParentAttachment",
      offset: 744,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropString(
      result: &RecvProps_17[22],
      pVarName: "m_iName",
      offset: 328,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_17[23],
      pVarName: "movetype",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_MoveType);
    RecvPropInt(
      result: &RecvProps_17[24],
      pVarName: "movecollide",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_MoveCollide);
    RecvPropDataTable(
      result: &RecvProps_17[25],
      pVarName: "m_Collision",
      offset: 780,
      flags: 0,
      pTable: &DT_CollisionProperty::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_17[26],
      pVarName: "m_iTextureFrameIndex",
      offset: 2353,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[27],
      pVarName: "m_bSimulatedEveryTick",
      offset: 2346,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_InterpolationAmountChanged);
    RecvPropInt(
      result: &RecvProps_17[28],
      pVarName: "m_bAnimatedEveryTick",
      offset: 2347,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_InterpolationAmountChanged);
    RecvPropBool(result: &RecvProps_17[29], pVarName: "m_bAlternateSorting", offset: 2348, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_17[30],
      pVarName: "m_fadeMinDist",
      offset: 728,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_17[31],
      pVarName: "m_fadeMaxDist",
      offset: 732,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_17[32],
      pVarName: "m_flFadeScale",
      offset: 736,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_17[33],
      pVarName: "m_nMinCPULevel",
      offset: 2349,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[34],
      pVarName: "m_nMaxCPULevel",
      offset: 2350,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[35],
      pVarName: "m_nMinGPULevel",
      offset: 2351,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_17[36],
      pVarName: "m_nMaxGPULevel",
      offset: 2352,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseEntity::g_RecvTable,
    pProps: &RecvProps_17[1],
    nProps: 36,
    pNetTableName: "DT_BaseEntity");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10044DD0
// Name: int ClientClassInit<struct DT_BaseFlex::ignored>(struct DT_BaseFlex::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseFlex::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60

  if ( (_S5_15 & 1) == 0 )
  {
    _S5_15 |= 1u;
    RecvPropInt(
      result: RecvProps_18,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_18[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimatingOverlay::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v3 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flexWeight[0]",
            offset: 3416,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_18[2],
      pVarName: "m_flexWeight",
      offset: 3416,
      sizeofVar: 4,
      elements: 96,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_18[3],
      pVarName: "m_blinktoggle",
      offset: 3844,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_18[4],
      pVarName: "m_viewtarget",
      offset: 3360,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_BaseFlex::g_RecvTable,
    pProps: &RecvProps_18[1],
    nProps: 4,
    pNetTableName: "DT_BaseFlex");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10058100
// Name: int ClientClassInit<struct DT_PlayerState::ignored>(struct DT_PlayerState::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PlayerState::ignored>()
{
  if ( (_S5_17 & 1) == 0 )
  {
    _S5_17 |= 1u;
    RecvPropInt(
      result: RecvProps_19,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_19[1], pVarName: "deadflag", offset: 4, sizeofVar: 1, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_PlayerState::g_RecvTable,
    pProps: &RecvProps_19[1],
    nProps: 1,
    pNetTableName: "DT_PlayerState");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10059780
// Name: int ClientClassInit<struct DT_Local::ignored>(struct DT_Local::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Local::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60

  if ( (_S6_10 & 1) == 0 )
  {
    _S6_10 |= 1u;
    RecvPropInt(
      result: RecvProps_20,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropInt(result: &v1, pVarName: "m_chAreaBits[0]", offset: 4, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_20[1],
      pVarName: "m_chAreaBits",
      offset: 4,
      sizeofVar: 1,
      elements: 32,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(
            result: &v1,
            pVarName: "m_chAreaPortalBits[0]",
            offset: 36,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_20[2],
      pVarName: "m_chAreaPortalBits",
      offset: 36,
      sizeofVar: 1,
      elements: 24,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_20[3], pVarName: "m_iHideHUD", offset: 72, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_20[4],
      pVarName: "m_flFOVRate",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_20[5], pVarName: "m_bDucked", offset: 124, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[6],
      pVarName: "m_bDucking",
      offset: 125,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[7],
      pVarName: "m_bInDuckJump",
      offset: 126,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[8],
      pVarName: "m_nDuckTimeMsecs",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[9],
      pVarName: "m_nDuckJumpTimeMsecs",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[10],
      pVarName: "m_nJumpTimeMsecs",
      offset: 84,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_20[11],
      pVarName: "m_flFallVelocity",
      offset: 88,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_20[12],
      pVarName: "m_vecPunchAngle",
      offset: 100,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[13],
      pVarName: "m_vecPunchAngleVel",
      offset: 112,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_20[14],
      pVarName: "m_bDrawViewmodel",
      offset: 127,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[15],
      pVarName: "m_bWearingSuit",
      offset: 128,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_20[16], pVarName: "m_bPoisoned", offset: 129, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_20[17],
      pVarName: "m_flStepSize",
      offset: 96,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_20[18],
      pVarName: "m_bAllowAutoMovement",
      offset: 130,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[19],
      pVarName: "m_skybox3d.scale",
      offset: 244,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_20[20],
      pVarName: "m_skybox3d.origin",
      offset: 248,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_20[21],
      pVarName: "m_skybox3d.area",
      offset: 260,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[22],
      pVarName: "m_skybox3d.fog.enable",
      offset: 332,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[23],
      pVarName: "m_skybox3d.fog.blend",
      offset: 333,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_20[24],
      pVarName: "m_skybox3d.fog.dirPrimary",
      offset: 268,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_20[25],
      pVarName: "m_skybox3d.fog.colorPrimary",
      offset: 280,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_20[26],
      pVarName: "m_skybox3d.fog.colorSecondary",
      offset: 284,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_20[27],
      pVarName: "m_skybox3d.fog.start",
      offset: 296,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_20[28],
      pVarName: "m_skybox3d.fog.end",
      offset: 300,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_20[29],
      pVarName: "m_skybox3d.fog.maxdensity",
      offset: 308,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_20[30],
      pVarName: "m_skybox3d.fog.HDRColorScale",
      offset: 336,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_20[31],
      pVarName: "m_audio.localSound[0]",
      offset: 344,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[32],
      pVarName: "m_audio.localSound[1]",
      offset: 356,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[33],
      pVarName: "m_audio.localSound[2]",
      offset: 368,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[34],
      pVarName: "m_audio.localSound[3]",
      offset: 380,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[35],
      pVarName: "m_audio.localSound[4]",
      offset: 392,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[36],
      pVarName: "m_audio.localSound[5]",
      offset: 404,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[37],
      pVarName: "m_audio.localSound[6]",
      offset: 416,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_20[38],
      pVarName: "m_audio.localSound[7]",
      offset: 428,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_20[39],
      pVarName: "m_audio.soundscapeIndex",
      offset: 440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[40],
      pVarName: "m_audio.localBits",
      offset: 444,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_20[41],
      pVarName: "m_audio.entIndex",
      offset: 448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(this: &DT_Local::g_RecvTable, pProps: &RecvProps_20[1], nProps: 41, pNetTableName: "DT_Local");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10059C90
// Name: int ClientClassInit<struct DT_LocalPlayerExclusive::ignored>(struct DT_LocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_LocalPlayerExclusive::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60

  if ( (_S7_5 & 1) == 0 )
  {
    _S7_5 |= 1u;
    RecvPropInt(
      result: RecvProps_21,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_21[1],
      pVarName: "m_Local",
      offset: 4800,
      flags: 0,
      pTable: &DT_Local::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_21[2],
      pVarName: "m_vecViewOffset[0]",
      offset: 252,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[3],
      pVarName: "m_vecViewOffset[1]",
      offset: 256,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[4],
      pVarName: "m_vecViewOffset[2]",
      offset: 260,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[5],
      pVarName: "m_flFriction",
      offset: 312,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    v3 = *RecvPropInt(result: &v1, pVarName: "m_iAmmo[0]", offset: 4260, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_21[6],
      pVarName: "m_iAmmo",
      offset: 4260,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_21[7],
      pVarName: "m_fOnTarget",
      offset: 5580,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_21[8],
      pVarName: "m_nTickBase",
      offset: 5788,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_21[9],
      pVarName: "m_nNextThinkTick",
      offset: 240,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_21[10],
      pVarName: "m_hLastWeapon",
      offset: 5556,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropFloat(
      result: &RecvProps_21[11],
      pVarName: "m_vecVelocity[0]",
      offset: 264,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalVelocityX);
    RecvPropFloat(
      result: &RecvProps_21[12],
      pVarName: "m_vecVelocity[1]",
      offset: 268,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalVelocityY);
    RecvPropFloat(
      result: &RecvProps_21[13],
      pVarName: "m_vecVelocity[2]",
      offset: 272,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalVelocityZ);
    RecvPropVector(
      result: &RecvProps_21[14],
      pVarName: "m_vecBaseVelocity",
      offset: 276,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropEHandle(
      result: &RecvProps_21[15],
      pVarName: "m_hConstraintEntity",
      offset: 5608,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropVector(
      result: &RecvProps_21[16],
      pVarName: "m_vecConstraintCenter",
      offset: 5612,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_21[17],
      pVarName: "m_flConstraintRadius",
      offset: 5624,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[18],
      pVarName: "m_flConstraintWidth",
      offset: 5628,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[19],
      pVarName: "m_flConstraintSpeedFactor",
      offset: 5632,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_21[20], pVarName: "m_bConstraintPastRadius", offset: 5636, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_21[21],
      pVarName: "m_flDeathTime",
      offset: 5684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_21[22],
      pVarName: "m_fForceTeam",
      offset: 5688,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_21[23],
      pVarName: "m_nWaterLevel",
      offset: 594,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_21[24],
      pVarName: "m_flLaggedMovementValue",
      offset: 6132,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropEHandle(
      result: &RecvProps_21[25],
      pVarName: "m_hTonemapController",
      offset: 5260,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_LocalPlayerExclusive::g_RecvTable,
    pProps: &RecvProps_21[1],
    nProps: 25,
    pNetTableName: "DT_LocalPlayerExclusive");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005CCF0
// Name: int ClientClassInit<struct DT_BasePlayer::ignored>(struct DT_BasePlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BasePlayer::ignored>()
{
  if ( (_S8_4 & 1) == 0 )
  {
    _S8_4 |= 1u;
    RecvPropInt(
      result: RecvProps_22,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_22[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatCharacter::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_22[2],
      pVarName: "localdata",
      offset: 0,
      flags: 0,
      pTable: &DT_LocalPlayerExclusive::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_22[3],
      pVarName: "pl",
      offset: 5264,
      flags: 0,
      pTable: &DT_PlayerState::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_22[4], pVarName: "m_iFOV", offset: 5284, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[5],
      pVarName: "m_iFOVStart",
      offset: 5288,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_22[6],
      pVarName: "m_flFOVTime",
      offset: 5320,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_22[7],
      pVarName: "m_iDefaultFOV",
      offset: 5588,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_22[8],
      pVarName: "m_hZoomOwner",
      offset: 5400,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_22[9],
      pVarName: "m_afPhysicsFlags",
      offset: 5548,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_22[10],
      pVarName: "m_hVehicle",
      offset: 5552,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_22[11],
      pVarName: "m_hUseEntity",
      offset: 5584,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_22[12],
      pVarName: "m_hGroundEntity",
      offset: 324,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_22[13],
      pVarName: "m_iHealth",
      offset: 244,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[14],
      pVarName: "m_lifeState",
      offset: 595,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[15],
      pVarName: "m_iBonusProgress",
      offset: 5388,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[16],
      pVarName: "m_iBonusChallenge",
      offset: 5392,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_22[17],
      pVarName: "m_flMaxspeed",
      offset: 5396,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_22[18], pVarName: "m_fFlags", offset: 248, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[19],
      pVarName: "m_iObserverMode",
      offset: 5640,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_ObserverMode);
    RecvPropEHandle(
      result: &RecvProps_22[20],
      pVarName: "m_hObserverTarget",
      offset: 5644,
      sizeofVar: 4,
      proxyFn: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_ObserverTarget);
    RecvPropEHandle(
      result: &RecvProps_22[21],
      pVarName: "m_hViewModel[0]",
      offset: 5560,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    InternalRecvPropArray(
      result: &RecvProps_22[22],
      elementCount: 2,
      elementStride: 4,
      pName: "m_hViewModel",
      proxy: nullptr);
    RecvPropString(
      result: &RecvProps_22[23],
      pVarName: "m_szLastPlaceName",
      offset: 6164,
      bufferSize: 18,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropVector(
      result: &RecvProps_22[24],
      pVarName: "m_vecLadderNormal",
      offset: 5340,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_22[25],
      pVarName: "m_ladderSurfaceProps",
      offset: 5312,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_22[26],
      pVarName: "m_ubEFNoInterpParity",
      offset: 6200,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_22[27],
      pVarName: "m_hPostProcessCtrl",
      offset: 6648,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_22[28],
      pVarName: "m_hColorCorrectionCtrl",
      offset: 6652,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_22[29],
      pVarName: "m_PlayerFog.m_hCtrl",
      offset: 6660,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_22[30],
      pVarName: "m_vphysicsCollisionState",
      offset: 5416,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_22[31],
      pVarName: "m_hViewEntity",
      offset: 5600,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropBool(
      result: &RecvProps_22[32],
      pVarName: "m_bShouldDrawPlayerWhileUsingViewEntity",
      offset: 5604,
      sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_BasePlayer::g_RecvTable,
    pProps: &RecvProps_22[1],
    nProps: 32,
    pNetTableName: "DT_BasePlayer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005ECE0
// Name: int ClientClassInit<struct DT_BaseToggle::ignored>(struct DT_BaseToggle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseToggle::ignored>()
{
  if ( (_S5_18 & 1) == 0 )
  {
    _S5_18 |= 1u;
    RecvPropInt(
      result: RecvProps_23,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_23[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_23[2],
      pVarName: "m_vecFinalDest",
      offset: 2452,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_23[3],
      pVarName: "m_movementType",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_23[4],
      pVarName: "m_flMoveTargetTime",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_BaseToggle::g_RecvTable,
    pProps: &RecvProps_23[1],
    nProps: 4,
    pNetTableName: "DT_BaseToggle");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005EDD0
// Name: int ClientClassInit<struct DT_BaseButton::ignored>(struct DT_BaseButton::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseButton::ignored>()
{
  if ( (_S6_11 & 1) == 0 )
  {
    _S6_11 |= 1u;
    RecvPropInt(
      result: RecvProps_24,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_24[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseToggle::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_24[2], pVarName: "m_usable", offset: 2480, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_BaseButton::g_RecvTable,
    pProps: &RecvProps_24[1],
    nProps: 2,
    pNetTableName: "DT_BaseButton");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100608D0
// Name: int ClientClassInit<struct DT_BeamSpotlight::ignored>(struct DT_BeamSpotlight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BeamSpotlight::ignored>()
{
  if ( (_S5_19 & 1) == 0 )
  {
    _S5_19 |= 1u;
    RecvPropInt(
      result: RecvProps_25,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_25[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_25[2],
      pVarName: "m_nHaloIndex",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_25[3], pVarName: "m_bSpotlightOn", offset: 2444, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_25[4], pVarName: "m_bHasDynamicLight", offset: 2445, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_25[5],
      pVarName: "m_flSpotlightMaxLength",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_25[6],
      pVarName: "m_flSpotlightGoalWidth",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_25[7],
      pVarName: "m_flHDRColorScale",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_25[8],
      pVarName: "m_nRotationAxis",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_25[9],
      pVarName: "m_flRotationSpeed",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_BeamSpotlight::g_RecvTable,
    pProps: &RecvProps_25[1],
    nProps: 9,
    pNetTableName: "DT_BeamSpotlight");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061900
// Name: int ClientClassInit<struct DT_BreakableProp::ignored>(struct DT_BreakableProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BreakableProp::ignored>()
{
  if ( (_S5_20 & 1) == 0 )
  {
    _S5_20 |= 1u;
    RecvPropInt(
      result: RecvProps_26,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_26[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_26[2],
      pVarName: "m_qPreferredPlayerCarryAngles",
      offset: 3260,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropBool(result: &RecvProps_26[3], pVarName: "m_bClientPhysics", offset: 3272, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_BreakableProp::g_RecvTable,
    pProps: &RecvProps_26[1],
    nProps: 3,
    pNetTableName: "DT_BreakableProp");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061C40
// Name: int ClientClassInit<struct DT_ColorCorrection::ignored>(struct DT_ColorCorrection::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ColorCorrection::ignored>()
{
  if ( (_S5_21 & 1) == 0 )
  {
    _S5_21 |= 1u;
    RecvPropInt(
      result: RecvProps_27,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_27[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_27[2],
      pVarName: "m_vecOrigin",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_27[3],
      pVarName: "m_minFalloff",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_27[4],
      pVarName: "m_maxFalloff",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_27[5],
      pVarName: "m_flCurWeight",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_27[6],
      pVarName: "m_flMaxWeight",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_27[7],
      pVarName: "m_flFadeInDuration",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_27[8],
      pVarName: "m_flFadeOutDuration",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropString(
      result: &RecvProps_27[9],
      pVarName: "m_netLookupFilename",
      offset: 2468,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropBool(result: &RecvProps_27[10], pVarName: "m_bEnabled", offset: 2728, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_27[11], pVarName: "m_bMaster", offset: 2729, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_27[12], pVarName: "m_bClientSide", offset: 2730, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_27[13], pVarName: "m_bExclusive", offset: 2731, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_ColorCorrection::g_RecvTable,
    pProps: &RecvProps_27[1],
    nProps: 13,
    pNetTableName: "DT_ColorCorrection");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100623F0
// Name: int ClientClassInit<struct DT_ColorCorrectionVolume::ignored>(struct DT_ColorCorrectionVolume::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ColorCorrectionVolume::ignored>()
{
  if ( (_S5_22 & 1) == 0 )
  {
    _S5_22 |= 1u;
    RecvPropInt(
      result: RecvProps_28,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_28[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTrigger::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_28[2], pVarName: "m_bEnabled", offset: 2504, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_28[3],
      pVarName: "m_MaxWeight",
      offset: 2508,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_28[4],
      pVarName: "m_FadeDuration",
      offset: 2512,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_28[5],
      pVarName: "m_Weight",
      offset: 2516,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropString(
      result: &RecvProps_28[6],
      pVarName: "m_lookupFilename",
      offset: 2520,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
  }
  RecvTable::Construct(
    this: &DT_ColorCorrectionVolume::g_RecvTable,
    pProps: &RecvProps_28[1],
    nProps: 6,
    pNetTableName: "DT_ColorCorrectionVolume");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10062E00
// Name: int ClientClassInit<struct DT_DynamicLight::ignored>(struct DT_DynamicLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DynamicLight::ignored>()
{
  if ( (_S5_24 & 1) == 0 )
  {
    _S5_24 |= 1u;
    RecvPropInt(
      result: RecvProps_29,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_29[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_29[2], pVarName: "m_Flags", offset: 2432, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_29[3],
      pVarName: "m_LightStyle",
      offset: 2433,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_29[4],
      pVarName: "m_Radius",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_29[5],
      pVarName: "m_Exponent",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_29[6],
      pVarName: "m_InnerAngle",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_29[7],
      pVarName: "m_OuterAngle",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_29[8],
      pVarName: "m_SpotRadius",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_DynamicLight::g_RecvTable,
    pProps: &RecvProps_29[1],
    nProps: 8,
    pNetTableName: "DT_DynamicLight");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100634E0
// Name: int ClientClassInit<struct DT_EntityDissolve::ignored>(struct DT_EntityDissolve::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EntityDissolve::ignored>()
{
  if ( (_S5_25 & 1) == 0 )
  {
    _S5_25 |= 1u;
    RecvPropInt(
      result: RecvProps_30,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_30[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropTime(result: &RecvProps_30[2], pVarName: "m_flStartTime", offset: 2436, sizeofVar: 4);
    RecvPropFloat(
      result: &RecvProps_30[3],
      pVarName: "m_flFadeOutStart",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_30[4],
      pVarName: "m_flFadeOutLength",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_30[5],
      pVarName: "m_flFadeOutModelStart",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_30[6],
      pVarName: "m_flFadeOutModelLength",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_30[7],
      pVarName: "m_flFadeInStart",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_30[8],
      pVarName: "m_flFadeInLength",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_30[9],
      pVarName: "m_nDissolveType",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_30[10],
      pVarName: "m_vDissolverOrigin",
      offset: 2472,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_30[11],
      pVarName: "m_nMagnitude",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_EntityDissolve::g_RecvTable,
    pProps: &RecvProps_30[1],
    nProps: 11,
    pNetTableName: "DT_EntityDissolve");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065710
// Name: int ClientClassInit<struct DT_EntityFlame::ignored>(struct DT_EntityFlame::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EntityFlame::ignored>()
{
  if ( (_S5_26 & 1) == 0 )
  {
    _S5_26 |= 1u;
    RecvPropInt(
      result: RecvProps_31,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_31[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_31[2],
      pVarName: "m_hEntAttached",
      offset: 2432,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropBool(result: &RecvProps_31[3], pVarName: "m_bCheapEffect", offset: 2452, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_EntityFlame::g_RecvTable,
    pProps: &RecvProps_31[1],
    nProps: 3,
    pNetTableName: "DT_EntityFlame");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065CE0
// Name: int ClientClassInit<struct DT_EntityFreezing::ignored>(struct DT_EntityFreezing::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EntityFreezing::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60

  if ( (_S5_27 & 1) == 0 )
  {
    _S5_27 |= 1u;
    RecvPropInt(
      result: RecvProps_32,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_32[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_32[2],
      pVarName: "m_vFreezingOrigin",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    v3 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flFrozenPerHitbox[0]",
            offset: 2444,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_32[3],
      pVarName: "m_flFrozenPerHitbox",
      offset: 2444,
      sizeofVar: 4,
      elements: 50,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_32[4],
      pVarName: "m_flFrozen",
      offset: 2644,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_32[5], pVarName: "m_bFinishFreezing", offset: 2648, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_EntityFreezing::g_RecvTable,
    pProps: &RecvProps_32[1],
    nProps: 5,
    pNetTableName: "DT_EntityFreezing");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065FC0
// Name: int ClientClassInit<struct DT_EntityParticleTrail::ignored>(struct DT_EntityParticleTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EntityParticleTrail::ignored>()
{
  if ( (_S5_28 & 1) == 0 )
  {
    _S5_28 |= 1u;
    RecvPropInt(
      result: RecvProps_33,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_33[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_33[2],
      pVarName: "m_iMaterialName",
      offset: 2664,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_33[3],
      pVarName: "m_Info",
      offset: 2668,
      flags: 0,
      pTable: &DT_EntityParticleTrailInfo::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_33[4],
      pVarName: "m_hConstraintEntity",
      offset: 2688,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_EntityParticleTrail::g_RecvTable,
    pProps: &RecvProps_33[1],
    nProps: 4,
    pNetTableName: "DT_EntityParticleTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10066E20
// Name: int ClientClassInit<struct DT_EnvAmbientLight::ignored>(struct DT_EnvAmbientLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvAmbientLight::ignored>()
{
  if ( (_S5_29 & 1) == 0 )
  {
    _S5_29 |= 1u;
    RecvPropInt(
      result: RecvProps_34,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_34[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_SpatialEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_34[2],
      pVarName: "m_vecColor",
      offset: 2728,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_EnvAmbientLight::g_RecvTable,
    pProps: &RecvProps_34[1],
    nProps: 2,
    pNetTableName: "DT_EnvAmbientLight");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100674A0
// Name: int ClientClassInit<struct DT_EnvDOFController::ignored>(struct DT_EnvDOFController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvDOFController::ignored>()
{
  if ( (_S5_30 & 1) == 0 )
  {
    _S5_30 |= 1u;
    RecvPropInt(
      result: RecvProps_35,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_35[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_35[2],
      pVarName: "m_bDOFEnabled",
      offset: 2432,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_35[3],
      pVarName: "m_flNearBlurDepth",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_35[4],
      pVarName: "m_flNearFocusDepth",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_35[5],
      pVarName: "m_flFarFocusDepth",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_35[6],
      pVarName: "m_flFarBlurDepth",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_35[7],
      pVarName: "m_flNearBlurRadius",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_35[8],
      pVarName: "m_flFarBlurRadius",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EnvDOFController::g_RecvTable,
    pProps: &RecvProps_35[1],
    nProps: 8,
    pNetTableName: "DT_EnvDOFController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10067830
// Name: int ClientClassInit<struct DT_FogController::ignored>(struct DT_FogController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FogController::ignored>()
{
  if ( (_S5_31 & 1) == 0 )
  {
    _S5_31 |= 1u;
    RecvPropInt(
      result: RecvProps_36,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_36[1],
      pVarName: "m_fog.enable",
      offset: 2500,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_36[2],
      pVarName: "m_fog.blend",
      offset: 2501,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_36[3],
      pVarName: "m_fog.dirPrimary",
      offset: 2436,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_36[4],
      pVarName: "m_fog.colorPrimary",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_36[5],
      pVarName: "m_fog.colorSecondary",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_36[6],
      pVarName: "m_fog.start",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[7],
      pVarName: "m_fog.end",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[8],
      pVarName: "m_fog.farz",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[9],
      pVarName: "m_fog.maxdensity",
      offset: 2476,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_36[10],
      pVarName: "m_fog.colorPrimaryLerpTo",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_36[11],
      pVarName: "m_fog.colorSecondaryLerpTo",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_36[12],
      pVarName: "m_fog.startLerpTo",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[13],
      pVarName: "m_fog.endLerpTo",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[14],
      pVarName: "m_fog.maxdensityLerpTo",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[15],
      pVarName: "m_fog.lerptime",
      offset: 2492,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[16],
      pVarName: "m_fog.duration",
      offset: 2496,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_36[17],
      pVarName: "m_fog.HDRColorScale",
      offset: 2504,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_FogController::g_RecvTable,
    pProps: &RecvProps_36[1],
    nProps: 17,
    pNetTableName: "DT_FogController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10067B90
// Name: int ClientClassInit<struct DT_EnvParticleScript::ignored>(struct DT_EnvParticleScript::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvParticleScript::ignored>()
{
  if ( (_S5_32 & 1) == 0 )
  {
    _S5_32 |= 1u;
    RecvPropInt(
      result: RecvProps_37,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_37[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_37[2],
      pVarName: "m_flSequenceScale",
      offset: 3484,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EnvParticleScript::g_RecvTable,
    pProps: &RecvProps_37[1],
    nProps: 2,
    pNetTableName: "DT_EnvParticleScript");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068400
// Name: int ClientClassInit<struct DT_EnvProjectedTexture::ignored>(struct DT_EnvProjectedTexture::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvProjectedTexture::ignored>()
{
  if ( (_S5_33 & 1) == 0 )
  {
    _S5_33 |= 1u;
    RecvPropInt(
      result: RecvProps_38,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_38[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_38[2],
      pVarName: "m_hTargetEntity",
      offset: 2436,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropBool(result: &RecvProps_38[3], pVarName: "m_bState", offset: 2440, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_38[4], pVarName: "m_bAlwaysUpdate", offset: 2441, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_38[5],
      pVarName: "m_flLightFOV",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_38[6], pVarName: "m_bEnableShadows", offset: 2448, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_38[7], pVarName: "m_bSimpleProjection", offset: 2449, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_38[8], pVarName: "m_bLightOnlyTarget", offset: 2450, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_38[9], pVarName: "m_bLightWorld", offset: 2451, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_38[10], pVarName: "m_bCameraSpace", offset: 2452, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_38[11],
      pVarName: "m_flBrightnessScale",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_38[12],
      pVarName: "m_LightColor",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_38[13],
      pVarName: "m_flColorTransitionTime",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_38[14],
      pVarName: "m_flAmbient",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropString(
      result: &RecvProps_38[15],
      pVarName: "m_SpotlightTextureName",
      offset: 2496,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_38[16],
      pVarName: "m_nSpotlightTextureFrame",
      offset: 2764,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_38[17],
      pVarName: "m_flNearZ",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_38[18],
      pVarName: "m_flFarZ",
      offset: 2492,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_38[19],
      pVarName: "m_nShadowQuality",
      offset: 2768,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_38[20],
      pVarName: "m_flProjectionSize",
      offset: 2784,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_38[21],
      pVarName: "m_flRotation",
      offset: 2788,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_38[22],
      pVarName: "m_iStyle",
      offset: 2772,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_EnvProjectedTexture::g_RecvTable,
    pProps: &RecvProps_38[1],
    nProps: 22,
    pNetTableName: "DT_EnvProjectedTexture");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10069A40
// Name: int ClientClassInit<struct DT_EnvScreenOverlay::ignored>(struct DT_EnvScreenOverlay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvScreenOverlay::ignored>()
{
  if ( (_S5_34 & 1) == 0 )
  {
    _S5_34 |= 1u;
    RecvPropInt(
      result: RecvProps_39,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_39[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_39[2],
      pVarName: "m_iszOverlayNames[0]",
      offset: 2432,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    InternalRecvPropArray(
      result: &RecvProps_39[3],
      elementCount: 10,
      elementStride: 255,
      pName: "m_iszOverlayNames",
      proxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_39[4],
      pVarName: "m_flOverlayTimes[0]",
      offset: 4984,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    InternalRecvPropArray(
      result: &RecvProps_39[5],
      elementCount: 10,
      elementStride: 4,
      pName: "m_flOverlayTimes",
      proxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_39[6],
      pVarName: "m_flStartTime",
      offset: 5024,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_39[7],
      pVarName: "m_iDesiredOverlay",
      offset: 5028,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_39[8], pVarName: "m_bIsActive", offset: 5032, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_EnvScreenOverlay::g_RecvTable,
    pProps: &RecvProps_39[1],
    nProps: 8,
    pNetTableName: "DT_EnvScreenOverlay");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10069BE0
// Name: int ClientClassInit<struct DT_EnvScreenEffect::ignored>(struct DT_EnvScreenEffect::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvScreenEffect::ignored>()
{
  if ( (_S6_13 & 1) == 0 )
  {
    _S6_13 |= 1u;
    RecvPropInt(
      result: RecvProps_40,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_40[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_40[2],
      pVarName: "m_flDuration",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_40[3], pVarName: "m_nType", offset: 2436, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_EnvScreenEffect::g_RecvTable,
    pProps: &RecvProps_40[1],
    nProps: 3,
    pNetTableName: "DT_EnvScreenEffect");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A390
// Name: int ClientClassInit<struct DT_EnvTonemapController::ignored>(struct DT_EnvTonemapController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvTonemapController::ignored>()
{
  if ( (_S5_35 & 1) == 0 )
  {
    _S5_35 |= 1u;
    RecvPropInt(
      result: RecvProps_41,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_41[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_41[2],
      pVarName: "m_bUseCustomAutoExposureMin",
      offset: 2432,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_41[3],
      pVarName: "m_bUseCustomAutoExposureMax",
      offset: 2433,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_41[4],
      pVarName: "m_bUseCustomBloomScale",
      offset: 2434,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_41[5],
      pVarName: "m_flCustomAutoExposureMin",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[6],
      pVarName: "m_flCustomAutoExposureMax",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[7],
      pVarName: "m_flCustomBloomScale",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[8],
      pVarName: "m_flCustomBloomScaleMinimum",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[9],
      pVarName: "m_flBloomExponent",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[10],
      pVarName: "m_flBloomSaturation",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[11],
      pVarName: "m_flTonemapPercentTarget",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[12],
      pVarName: "m_flTonemapPercentBrightPixels",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_41[13],
      pVarName: "m_flTonemapMinAvgLum",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EnvTonemapController::g_RecvTable,
    pProps: &RecvProps_41[1],
    nProps: 13,
    pNetTableName: "DT_EnvTonemapController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A900
// Name: int ClientClassInit<struct DT_FireSmoke::ignored>(struct DT_FireSmoke::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FireSmoke::ignored>()
{
  if ( (_S5_36 & 1) == 0 )
  {
    _S5_36 |= 1u;
    RecvPropInt(
      result: RecvProps_42,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_42[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_42[2],
      pVarName: "m_flStartScale",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_42[3],
      pVarName: "m_flScale",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Scale);
    RecvPropFloat(
      result: &RecvProps_42[4],
      pVarName: "m_flScaleTime",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_ScaleTime);
    RecvPropInt(result: &RecvProps_42[5], pVarName: "m_nFlags", offset: 2444, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_42[6],
      pVarName: "m_nFlameModelIndex",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_42[7],
      pVarName: "m_nFlameFromAboveModelIndex",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_FireSmoke::g_RecvTable,
    pProps: &RecvProps_42[1],
    nProps: 7,
    pNetTableName: "DT_FireSmoke");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006B090
// Name: int ClientClassInit<struct DT_CFish::ignored>(struct DT_CFish::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CFish::ignored>()
{
  if ( (_S5_37 & 1) == 0 )
  {
    _S5_37 |= 1u;
    RecvPropInt(
      result: RecvProps_43,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_43[1],
      pVarName: "m_poolOrigin",
      offset: 3352,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_43[2],
      pVarName: "m_x",
      offset: 3328,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_FishOriginX);
    RecvPropFloat(
      result: &RecvProps_43[3],
      pVarName: "m_y",
      offset: 3332,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_FishOriginY);
    RecvPropFloat(
      result: &RecvProps_43[4],
      pVarName: "m_z",
      offset: 3336,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_43[5],
      pVarName: "m_angle",
      offset: 3344,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_43[6],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_43[7],
      pVarName: "m_lifeState",
      offset: 595,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_43[8],
      pVarName: "m_waterLevel",
      offset: 3364,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(this: &DT_CFish::g_RecvTable, pProps: &RecvProps_43[1], nProps: 8, pNetTableName: "DT_CFish");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006BAF0
// Name: int ClientClassInit<struct DT_FuncAreaPortalWindow::ignored>(struct DT_FuncAreaPortalWindow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncAreaPortalWindow::ignored>()
{
  if ( (_S5_38 & 1) == 0 )
  {
    _S5_38 |= 1u;
    RecvPropInt(
      result: RecvProps_44,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_44[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_44[2],
      pVarName: "m_flFadeStartDist",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_44[3],
      pVarName: "m_flFadeDist",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_44[4],
      pVarName: "m_flTranslucencyLimit",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_44[5],
      pVarName: "m_iBackgroundModelIndex",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_FuncAreaPortalWindow::g_RecvTable,
    pProps: &RecvProps_44[1],
    nProps: 5,
    pNetTableName: "DT_FuncAreaPortalWindow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006C0C0
// Name: int ClientClassInit<struct DT_BreakableSurface::ignored>(struct DT_BreakableSurface::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BreakableSurface::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^14.60

  if ( (_S6_14 & 1) == 0 )
  {
    _S6_14 |= 1u;
    RecvPropInt(
      result: RecvProps_45,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_45[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_45[2],
      pVarName: "m_nNumWide",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_45[3],
      pVarName: "m_nNumHigh",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_45[4],
      pVarName: "m_flPanelWidth",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_45[5],
      pVarName: "m_flPanelHeight",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_45[6],
      pVarName: "m_vNormal",
      offset: 2452,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_45[7],
      pVarName: "m_vCorner",
      offset: 2464,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_45[8],
      pVarName: "m_bIsBroken",
      offset: 2476,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_45[9],
      pVarName: "m_nSurfaceType",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropInt(
            result: &v1,
            pVarName: "m_RawPanelBitVec[ 0 ]",
            offset: 2516,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_45[10],
      pVarName: "m_RawPanelBitVec",
      offset: 2516,
      sizeofVar: 1,
      elements: 256,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BreakableSurface::g_RecvTable,
    pProps: &RecvProps_45[1],
    nProps: 10,
    pNetTableName: "DT_BreakableSurface");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F270
// Name: int ClientClassInit<struct DT_FuncBrush::ignored>(struct DT_FuncBrush::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncBrush::ignored>()
{
  if ( (_S5_40 & 1) == 0 )
  {
    _S5_40 |= 1u;
    RecvPropInt(
      result: RecvProps_46,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_46[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FuncBrush::g_RecvTable,
    pProps: &RecvProps_46[1],
    nProps: 1,
    pNetTableName: "DT_FuncBrush");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F390
// Name: int ClientClassInit<struct DT_FuncConveyor::ignored>(struct DT_FuncConveyor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncConveyor::ignored>()
{
  if ( (_S5_41 & 1) == 0 )
  {
    _S5_41 |= 1u;
    RecvPropInt(
      result: RecvProps_47,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_47[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_47[2],
      pVarName: "m_flConveyorSpeed",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_FuncConveyor::g_RecvTable,
    pProps: &RecvProps_47[1],
    nProps: 2,
    pNetTableName: "DT_FuncConveyor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F6E0
// Name: int ClientClassInit<struct DT_Func_Dust::ignored>(struct DT_Func_Dust::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Func_Dust::ignored>()
{
  if ( (_S5_42 & 1) == 0 )
  {
    _S5_42 |= 1u;
    RecvPropInt(
      result: RecvProps_48,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[1],
      pVarName: "m_Color",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_48[2],
      pVarName: "m_SpawnRate",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_48[3],
      pVarName: "m_flSizeMin",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_48[4],
      pVarName: "m_flSizeMax",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_48[5],
      pVarName: "m_LifetimeMin",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[6],
      pVarName: "m_LifetimeMax",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[7],
      pVarName: "m_DustFlags",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[8],
      pVarName: "m_SpeedMax",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[9],
      pVarName: "m_DistMax",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_48[10],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_48[11],
      pVarName: "m_FallSpeed",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropDataTable(
      result: &RecvProps_48[12],
      pVarName: "m_Collision",
      offset: 780,
      flags: 0,
      pTable: &DT_CollisionProperty::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_Func_Dust::g_RecvTable,
    pProps: &RecvProps_48[1],
    nProps: 12,
    pNetTableName: "DT_Func_Dust");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006F8A0
// Name: int ClientClassInit<struct DT_TEDust::ignored>(struct DT_TEDust::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEDust::ignored>()
{
  if ( (_S6_15 & 1) == 0 )
  {
    _S6_15 |= 1u;
    RecvPropInt(
      result: RecvProps_49,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_49[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_49[2],
      pVarName: "m_flSize",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_49[3],
      pVarName: "m_flSpeed",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_49[4],
      pVarName: "m_vecDirection",
      offset: 36,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(this: &DT_TEDust::g_RecvTable, pProps: &RecvProps_49[1], nProps: 4, pNetTableName: "DT_TEDust");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070C90
// Name: int ClientClassInit<struct DT_Func_LOD::ignored>(struct DT_Func_LOD::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Func_LOD::ignored>()
{
  if ( (_S5_43 & 1) == 0 )
  {
    _S5_43 |= 1u;
    RecvPropInt(
      result: RecvProps_50,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_50[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_50[2],
      pVarName: "m_nDisappearMinDist",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_50[3],
      pVarName: "m_nDisappearMaxDist",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_Func_LOD::g_RecvTable,
    pProps: &RecvProps_50[1],
    nProps: 3,
    pNetTableName: "DT_Func_LOD");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070E30
// Name: int ClientClassInit<struct DT_FuncMonitor::ignored>(struct DT_FuncMonitor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncMonitor::ignored>()
{
  if ( (_S5_44 & 1) == 0 )
  {
    _S5_44 |= 1u;
    RecvPropInt(
      result: RecvProps_51,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_51[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_FuncBrush::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FuncMonitor::g_RecvTable,
    pProps: &RecvProps_51[1],
    nProps: 1,
    pNetTableName: "DT_FuncMonitor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070F20
// Name: int ClientClassInit<struct DT_FuncMoveLinear::ignored>(struct DT_FuncMoveLinear::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncMoveLinear::ignored>()
{
  if ( (_S5_45 & 1) == 0 )
  {
    _S5_45 |= 1u;
    RecvPropInt(
      result: RecvProps_52,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_52[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseToggle::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_52[2],
      pVarName: "m_vecVelocity",
      offset: 264,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_LocalVelocity);
    RecvPropInt(result: &RecvProps_52[3], pVarName: "m_fFlags", offset: 248, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_FuncMoveLinear::g_RecvTable,
    pProps: &RecvProps_52[1],
    nProps: 3,
    pNetTableName: "DT_FuncMoveLinear");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10071080
// Name: int ClientClassInit<struct DT_FuncOccluder::ignored>(struct DT_FuncOccluder::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncOccluder::ignored>()
{
  if ( (_S5_46 & 1) == 0 )
  {
    _S5_46 |= 1u;
    RecvPropInt(
      result: RecvProps_53,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_53[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_53[2], pVarName: "m_bActive", offset: 2436, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_53[3],
      pVarName: "m_nOccluderIndex",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_FuncOccluder::g_RecvTable,
    pProps: &RecvProps_53[1],
    nProps: 3,
    pNetTableName: "DT_FuncOccluder");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100711E0
// Name: int ClientClassInit<struct DT_FuncReflectiveGlass::ignored>(struct DT_FuncReflectiveGlass::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncReflectiveGlass::ignored>()
{
  if ( (_S5_47 & 1) == 0 )
  {
    _S5_47 |= 1u;
    RecvPropInt(
      result: RecvProps_54,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_54[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_FuncBrush::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FuncReflectiveGlass::g_RecvTable,
    pProps: &RecvProps_54[1],
    nProps: 1,
    pNetTableName: "DT_FuncReflectiveGlass");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10071670
// Name: int ClientClassInit<struct DT_FuncRotating::ignored>(struct DT_FuncRotating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncRotating::ignored>()
{
  if ( (_S5_48 & 1) == 0 )
  {
    _S5_48 |= 1u;
    RecvPropInt(
      result: RecvProps_55,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_55[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_55[2],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_55[3],
      pVarName: "m_angRotation[0]",
      offset: 288,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_55[4],
      pVarName: "m_angRotation[1]",
      offset: 292,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_55[5],
      pVarName: "m_angRotation[2]",
      offset: 296,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_55[6],
      pVarName: "m_flSimulationTime",
      offset: 604,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_SimulationTime);
  }
  RecvTable::Construct(
    this: &DT_FuncRotating::g_RecvTable,
    pProps: &RecvProps_55[1],
    nProps: 6,
    pNetTableName: "DT_FuncRotating");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100717B0
// Name: int ClientClassInit<struct DT_FuncSmokeVolume::ignored>(struct DT_FuncSmokeVolume::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncSmokeVolume::ignored>()
{
  if ( (_S5_49 & 1) == 0 )
  {
    _S5_49 |= 1u;
    RecvPropInt(
      result: RecvProps_56,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_56[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_56[2],
      pVarName: "m_Color1",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_56[3],
      pVarName: "m_Color2",
      offset: 2672,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropString(
      result: &RecvProps_56[4],
      pVarName: "m_MaterialName",
      offset: 2676,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropFloat(
      result: &RecvProps_56[5],
      pVarName: "m_ParticleDrawWidth",
      offset: 2932,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[6],
      pVarName: "m_ParticleSpacingDistance",
      offset: 2936,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[7],
      pVarName: "m_DensityRampSpeed",
      offset: 2940,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[8],
      pVarName: "m_RotationSpeed",
      offset: 2944,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[9],
      pVarName: "m_MovementSpeed",
      offset: 2948,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[10],
      pVarName: "m_Density",
      offset: 2952,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_56[11],
      pVarName: "m_maxDrawDistance",
      offset: 2956,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_56[12],
      pVarName: "m_spawnflags",
      offset: 2960,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_56[13],
      pVarName: "m_Collision",
      offset: 780,
      flags: 0,
      pTable: &DT_CollisionProperty::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FuncSmokeVolume::g_RecvTable,
    pProps: &RecvProps_56[1],
    nProps: 13,
    pNetTableName: "DT_FuncSmokeVolume");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10073260
// Name: int ClientClassInit<struct DT_FuncTrackTrain::ignored>(struct DT_FuncTrackTrain::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncTrackTrain::ignored>()
{
  if ( (_S5_50 & 1) == 0 )
  {
    _S5_50 |= 1u;
    RecvPropInt(
      result: RecvProps_57,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_57[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FuncTrackTrain::g_RecvTable,
    pProps: &RecvProps_57[1],
    nProps: 1,
    pNetTableName: "DT_FuncTrackTrain");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10076D90
// Name: int ClientClassInit<struct DT_InfoOverlayAccessor::ignored>(struct DT_InfoOverlayAccessor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_InfoOverlayAccessor::ignored>()
{
  if ( (_S5_52 & 1) == 0 )
  {
    _S5_52 |= 1u;
    RecvPropInt(
      result: RecvProps_58,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_58[1],
      pVarName: "m_iTextureFrameIndex",
      offset: 2353,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_58[2],
      pVarName: "m_iOverlayID",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_InfoOverlayAccessor::g_RecvTable,
    pProps: &RecvProps_58[1],
    nProps: 2,
    pNetTableName: "DT_InfoOverlayAccessor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100775F0
// Name: int ClientClassInit<struct DT_LightGlow::ignored>(struct DT_LightGlow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_LightGlow::ignored>()
{
  if ( (_S5_53 & 1) == 0 )
  {
    _S5_53 |= 1u;
    RecvPropInt(
      result: RecvProps_59,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[1],
      pVarName: "m_clrRender",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_59[2],
      pVarName: "m_nHorizontalSize",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[3],
      pVarName: "m_nVerticalSize",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[4],
      pVarName: "m_nMinDist",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[5],
      pVarName: "m_nMaxDist",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[6],
      pVarName: "m_nOuterMaxDist",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_59[7],
      pVarName: "m_spawnflags",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_59[8],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_59[9],
      pVarName: "m_angRotation",
      offset: 288,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_59[10],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
    RecvPropFloat(
      result: &RecvProps_59[11],
      pVarName: "m_flGlowProxySize",
      offset: 2660,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_59[12],
      pVarName: "HDRColorScale",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_HDRColorScale);
  }
  RecvTable::Construct(
    this: &DT_LightGlow::g_RecvTable,
    pProps: &RecvProps_59[1],
    nProps: 12,
    pNetTableName: "DT_LightGlow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10077D70
// Name: int ClientClassInit<struct DT_MaterialModifyControl::ignored>(struct DT_MaterialModifyControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_MaterialModifyControl::ignored>()
{
  if ( (_S5_54 & 1) == 0 )
  {
    _S5_54 |= 1u;
    RecvPropInt(
      result: RecvProps_60,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_60[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_60[2],
      pVarName: "m_szMaterialName",
      offset: 2432,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_60[3],
      pVarName: "m_szMaterialVar",
      offset: 2687,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_60[4],
      pVarName: "m_szMaterialVarValue",
      offset: 2942,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_60[5],
      pVarName: "m_iFrameStart",
      offset: 3208,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_60[6],
      pVarName: "m_iFrameEnd",
      offset: 3212,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_60[7], pVarName: "m_bWrap", offset: 3216, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_60[8],
      pVarName: "m_flFramerate",
      offset: 3220,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_60[9],
      pVarName: "m_bNewAnimCommandsSemaphore",
      offset: 3224,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_60[10],
      pVarName: "m_flFloatLerpStartValue",
      offset: 3228,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_60[11],
      pVarName: "m_flFloatLerpEndValue",
      offset: 3232,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_60[12],
      pVarName: "m_flFloatLerpTransitionTime",
      offset: 3236,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_60[13],
      pVarName: "m_bFloatLerpWrap",
      offset: 3240,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_60[14],
      pVarName: "m_nModifyMode",
      offset: 3248,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_MaterialModifyControl::g_RecvTable,
    pProps: &RecvProps_60[1],
    nProps: 14,
    pNetTableName: "DT_MaterialModifyControl");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100788B0
// Name: int ClientClassInit<struct DT_MovieDisplay::ignored>(struct DT_MovieDisplay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_MovieDisplay::ignored>()
{
  if ( (_S5_55 & 1) == 0 )
  {
    _S5_55 |= 1u;
    RecvPropInt(
      result: RecvProps_61,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_61[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_61[2], pVarName: "m_bEnabled", offset: 2432, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_61[3], pVarName: "m_bLooping", offset: 2433, sizeofVar: 1);
    RecvPropString(
      result: &RecvProps_61[4],
      pVarName: "m_szMovieFilename",
      offset: 2434,
      bufferSize: 128,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_61[5],
      pVarName: "m_szGroupName",
      offset: 2562,
      bufferSize: 128,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropBool(result: &RecvProps_61[6], pVarName: "m_bStretchToFill", offset: 2690, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_61[7], pVarName: "m_bForcedSlave", offset: 2691, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_61[8], pVarName: "m_bUseCustomUVs", offset: 2692, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_61[9],
      pVarName: "m_flUMin",
      offset: 2696,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_61[10],
      pVarName: "m_flUMax",
      offset: 2700,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_61[11],
      pVarName: "m_flVMin",
      offset: 2704,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_61[12],
      pVarName: "m_flVMax",
      offset: 2708,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_MovieDisplay::g_RecvTable,
    pProps: &RecvProps_61[1],
    nProps: 12,
    pNetTableName: "DT_MovieDisplay");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078B60
// Name: int ClientClassInit<struct DT_ParticleSystem::ignored>(struct DT_ParticleSystem::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ParticleSystem::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60
  RecvProp v6; // 0:^2C.60

  if ( (_S5_56 & 1) == 0 )
  {
    _S5_56 |= 1u;
    RecvPropInt(
      result: RecvProps_62,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_62[1],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_62[2],
      pVarName: "m_fEffects",
      offset: 232,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_EffectFlags);
    RecvPropEHandle(
      result: &RecvProps_62[3],
      pVarName: "m_hOwnerEntity",
      offset: 320,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_62[4],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_62[5],
      pVarName: "m_iParentAttachment",
      offset: 744,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_62[6],
      pVarName: "m_angRotation",
      offset: 288,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_62[7],
      pVarName: "m_iEffectIndex",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_62[8], pVarName: "m_bActive", offset: 2440, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_62[9],
      pVarName: "m_nStopType",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_62[10],
      pVarName: "m_flStartTime",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropString(
      result: &RecvProps_62[11],
      pVarName: "m_szSnapshotFileName",
      offset: 2448,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    v3 = *RecvPropVector(
            result: &v1,
            pVarName: "m_vServerControlPoints[0]",
            offset: 2708,
            sizeofVar: 12,
            flags: 0,
            varProxy: RecvProxy_VectorToVector);
    RecvPropArray3(
      result: &RecvProps_62[12],
      pVarName: "m_vServerControlPoints",
      offset: 2708,
      sizeofVar: 12,
      elements: 4,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iServerControlPointAssignments[0]",
            offset: 2756,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_62[13],
      pVarName: "m_iServerControlPointAssignments",
      offset: 2756,
      sizeofVar: 1,
      elements: 4,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropEHandle(
            result: &v1,
            pVarName: "m_hControlPointEnts[0]",
            offset: 2776,
            sizeofVar: 4,
            proxyFn: RecvProxy_IntToEHandle);
    RecvPropArray3(
      result: &RecvProps_62[14],
      pVarName: "m_hControlPointEnts",
      offset: 2776,
      sizeofVar: 4,
      elements: 63,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v6 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iControlPointParents[0]",
            offset: 3028,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_62[15],
      pVarName: "m_iControlPointParents",
      offset: 3028,
      sizeofVar: 1,
      elements: 63,
      pArrayProp: v6,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_ParticleSystem::g_RecvTable,
    pProps: &RecvProps_62[1],
    nProps: 15,
    pNetTableName: "DT_ParticleSystem");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10079900
// Name: int ClientClassInit<struct DT_PhysBox::ignored>(struct DT_PhysBox::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PhysBox::ignored>()
{
  if ( (_S5_57 & 1) == 0 )
  {
    _S5_57 |= 1u;
    RecvPropInt(
      result: RecvProps_63,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_63[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_63[2],
      pVarName: "m_mass",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(this: &DT_PhysBox::g_RecvTable, pProps: &RecvProps_63[1], nProps: 2, pNetTableName: "DT_PhysBox");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10079AE0
// Name: int ClientClassInit<struct DT_StatueProp::ignored>(struct DT_StatueProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_StatueProp::ignored>()
{
  if ( (_S5_58 & 1) == 0 )
  {
    _S5_58 |= 1u;
    RecvPropInt(
      result: RecvProps_64,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_64[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_PhysicsProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_64[2],
      pVarName: "m_hInitBaseAnimating",
      offset: 3312,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropBool(result: &RecvProps_64[3], pVarName: "m_bShatter", offset: 3316, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_64[4],
      pVarName: "m_nShatterFlags",
      offset: 3320,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_64[5],
      pVarName: "m_vShatterPosition",
      offset: 3324,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_64[6],
      pVarName: "m_vShatterForce",
      offset: 3336,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_StatueProp::g_RecvTable,
    pProps: &RecvProps_64[1],
    nProps: 6,
    pNetTableName: "DT_StatueProp");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10079D30
// Name: int ClientClassInit<struct DT_PhysicsProp::ignored>(struct DT_PhysicsProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PhysicsProp::ignored>()
{
  if ( (_S5_59 & 1) == 0 )
  {
    _S5_59 |= 1u;
    RecvPropInt(
      result: RecvProps_65,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_65[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BreakableProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_65[2], pVarName: "m_bAwake", offset: 3280, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_65[3],
      pVarName: "m_spawnflags",
      offset: 700,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_PhysicsProp::g_RecvTable,
    pProps: &RecvProps_65[1],
    nProps: 3,
    pNetTableName: "DT_PhysicsProp");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007A180
// Name: int ClientClassInit<struct DT_PhysMagnet::ignored>(struct DT_PhysMagnet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PhysMagnet::ignored>()
{
  if ( (_S5_60 & 1) == 0 )
  {
    _S5_60 |= 1u;
    RecvPropInt(
      result: RecvProps_66,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_66[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_PhysMagnet::g_RecvTable,
    pProps: &RecvProps_66[1],
    nProps: 1,
    pNetTableName: "DT_PhysMagnet");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007D230
// Name: int ClientClassInit<struct DT_Plasma::ignored>(struct DT_Plasma::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Plasma::ignored>()
{
  if ( (_S5_61 & 1) == 0 )
  {
    _S5_61 |= 1u;
    RecvPropInt(
      result: RecvProps_67,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_67[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_67[2],
      pVarName: "m_flStartScale",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_67[3],
      pVarName: "m_flScale",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_PlasmaScale);
    RecvPropFloat(
      result: &RecvProps_67[4],
      pVarName: "m_flScaleTime",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_PlasmaScaleTime);
    RecvPropInt(result: &RecvProps_67[5], pVarName: "m_nFlags", offset: 2444, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_67[6],
      pVarName: "m_nPlasmaModelIndex",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_67[7],
      pVarName: "m_nPlasmaModelIndex2",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_67[8],
      pVarName: "m_nGlowModelIndex",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(this: &DT_Plasma::g_RecvTable, pProps: &RecvProps_67[1], nProps: 8, pNetTableName: "DT_Plasma");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007DFA0
// Name: int ClientClassInit<struct DT_PlayerResource::ignored>(struct DT_PlayerResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PlayerResource::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60
  RecvProp v6; // 0:^2C.60
  RecvProp v7; // 0:^2C.60
  RecvProp v8; // 0:^2C.60
  RecvProp v9; // 0:^2C.60

  if ( (_S5_62 & 1) == 0 )
  {
    _S5_62 |= 1u;
    RecvPropInt(
      result: RecvProps_68,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropInt(result: &v1, pVarName: "m_iPing[0]", offset: 2696, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[1],
      pVarName: "m_iPing",
      offset: 2696,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(result: &v1, pVarName: "m_iKills[0]", offset: 2956, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[2],
      pVarName: "m_iKills",
      offset: 2956,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropInt(result: &v1, pVarName: "m_iDeaths[0]", offset: 3216, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[3],
      pVarName: "m_iDeaths",
      offset: 3216,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v6 = *RecvPropInt(result: &v1, pVarName: "m_bConnected[0]", offset: 3476, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[4],
      pVarName: "m_bConnected",
      offset: 3476,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v6,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v7 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iTeam[0]",
            offset: 3544,
            sizeofVar: 4,
            flags: 0,
            varProxy: RecvProxy_ChangedTeam);
    RecvPropArray3(
      result: &RecvProps_68[5],
      pVarName: "m_iTeam",
      offset: 3544,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v7,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v8 = *RecvPropInt(result: &v1, pVarName: "m_bAlive[0]", offset: 3804, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[6],
      pVarName: "m_bAlive",
      offset: 3804,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v8,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v9 = *RecvPropInt(result: &v1, pVarName: "m_iHealth[0]", offset: 3872, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_68[7],
      pVarName: "m_iHealth",
      offset: 3872,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v9,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_PlayerResource::g_RecvTable,
    pProps: &RecvProps_68[1],
    nProps: 7,
    pNetTableName: "DT_PlayerResource");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB50
// Name: int ClientClassInit<struct DT_PointCamera::ignored>(struct DT_PointCamera::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PointCamera::ignored>()
{
  if ( (_S5_63 & 1) == 0 )
  {
    _S5_63 |= 1u;
    RecvPropInt(
      result: RecvProps_69,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_69[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_69[2],
      pVarName: "m_FOV",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_69[3],
      pVarName: "m_Resolution",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_69[4],
      pVarName: "m_bFogEnable",
      offset: 2440,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_69[5],
      pVarName: "m_FogColor",
      offset: 2441,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_69[6],
      pVarName: "m_flFogStart",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_69[7],
      pVarName: "m_flFogEnd",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_69[8],
      pVarName: "m_flFogMaxDensity",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_69[9],
      pVarName: "m_bActive",
      offset: 2460,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_69[10],
      pVarName: "m_bUseScreenAspectRatio",
      offset: 2461,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_PointCamera::g_RecvTable,
    pProps: &RecvProps_69[1],
    nProps: 10,
    pNetTableName: "DT_PointCamera");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007F190
// Name: int ClientClassInit<struct DT_PointCommentaryNode::ignored>(struct DT_PointCommentaryNode::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PointCommentaryNode::ignored>()
{
  if ( (_S5_64 & 1) == 0 )
  {
    _S5_64 |= 1u;
    RecvPropInt(
      result: RecvProps_70,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_70[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_70[2], pVarName: "m_bActive", offset: 3256, sizeofVar: 1);
    RecvPropTime(result: &RecvProps_70[3], pVarName: "m_flStartTime", offset: 3260, sizeofVar: 4);
    RecvPropString(
      result: &RecvProps_70[4],
      pVarName: "m_iszCommentaryFile",
      offset: 3264,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_70[5],
      pVarName: "m_iszCommentaryFileNoHDR",
      offset: 3524,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_70[6],
      pVarName: "m_iszSpeakers",
      offset: 3784,
      bufferSize: 256,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_70[7],
      pVarName: "m_iNodeNumber",
      offset: 4040,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_70[8],
      pVarName: "m_iNodeNumberMax",
      offset: 4044,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_70[9],
      pVarName: "m_hViewPosition",
      offset: 4052,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_PointCommentaryNode::g_RecvTable,
    pProps: &RecvProps_70[1],
    nProps: 9,
    pNetTableName: "DT_PointCommentaryNode");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10080BB0
// Name: int ClientClassInit<struct DT_PostProcessController::ignored>(struct DT_PostProcessController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PostProcessController::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^24.60

  if ( (_S5_65 & 1) == 0 )
  {
    _S5_65 |= 1u;
    RecvPropInt(
      result: RecvProps_71,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_71[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v3 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flPostProcessParameters[0]",
            offset: 2432,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_71[2],
      pVarName: "m_flPostProcessParameters",
      offset: 2432,
      sizeofVar: 4,
      elements: 11,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_71[3], pVarName: "m_bMaster", offset: 2476, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_PostProcessController::g_RecvTable,
    pProps: &RecvProps_71[1],
    nProps: 3,
    pNetTableName: "DT_PostProcessController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10080E00
// Name: int ClientClassInit<struct DT_Prop_Hallucination::ignored>(struct DT_Prop_Hallucination::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Prop_Hallucination::ignored>()
{
  if ( (_S6_19 & 1) == 0 )
  {
    _S6_19 |= 1u;
    RecvPropInt(
      result: RecvProps_72,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_72[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_72[2], pVarName: "m_bEnabled", offset: 3281, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_72[3],
      pVarName: "m_fVisibleTime",
      offset: 3284,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_72[4],
      pVarName: "m_fRechargeTime",
      offset: 3288,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_Prop_Hallucination::g_RecvTable,
    pProps: &RecvProps_72[1],
    nProps: 4,
    pNetTableName: "DT_Prop_Hallucination");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100811B0
// Name: int ClientClassInit<struct DT_DynamicProp::ignored>(struct DT_DynamicProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DynamicProp::ignored>()
{
  if ( (_S5_66 & 1) == 0 )
  {
    _S5_66 |= 1u;
    RecvPropInt(
      result: RecvProps_73,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_73[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BreakableProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_73[2], pVarName: "m_bUseHitboxesForRenderBox", offset: 3280, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_DynamicProp::g_RecvTable,
    pProps: &RecvProps_73[1],
    nProps: 2,
    pNetTableName: "DT_DynamicProp");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081280
// Name: int ClientClassInit<struct DT_BasePropDoor::ignored>(struct DT_BasePropDoor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BasePropDoor::ignored>()
{
  if ( (_S6_20 & 1) == 0 )
  {
    _S6_20 |= 1u;
    RecvPropInt(
      result: RecvProps_74,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_74[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_DynamicProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BasePropDoor::g_RecvTable,
    pProps: &RecvProps_74[1],
    nProps: 1,
    pNetTableName: "DT_BasePropDoor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081350
// Name: int ClientClassInit<struct DT_PropDoorRotating::ignored>(struct DT_PropDoorRotating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PropDoorRotating::ignored>()
{
  if ( (_S7_6 & 1) == 0 )
  {
    _S7_6 |= 1u;
    RecvPropInt(
      result: RecvProps_75,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_75[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BasePropDoor::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_PropDoorRotating::g_RecvTable,
    pProps: &RecvProps_75[1],
    nProps: 1,
    pNetTableName: "DT_PropDoorRotating");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100813D0
// Name: int ClientClassInit<struct DT_PhysBoxMultiplayer::ignored>(struct DT_PhysBoxMultiplayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PhysBoxMultiplayer::ignored>()
{
  if ( (_S8_5 & 1) == 0 )
  {
    _S8_5 |= 1u;
    RecvPropInt(
      result: RecvProps_76,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_76[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_PhysBox::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_76[2],
      pVarName: "m_iPhysicsMode",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_76[3],
      pVarName: "m_fMass",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_PhysBoxMultiplayer::g_RecvTable,
    pProps: &RecvProps_76[1],
    nProps: 3,
    pNetTableName: "DT_PhysBoxMultiplayer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081480
// Name: int ClientClassInit<struct DT_PhysicsPropMultiplayer::ignored>(struct DT_PhysicsPropMultiplayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PhysicsPropMultiplayer::ignored>()
{
  if ( (_S9_3 & 1) == 0 )
  {
    _S9_3 |= 1u;
    RecvPropInt(
      result: RecvProps_77,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_77[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_PhysicsProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_77[2],
      pVarName: "m_iPhysicsMode",
      offset: 3316,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_77[3],
      pVarName: "m_fMass",
      offset: 3320,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_77[4],
      pVarName: "m_collisionMins",
      offset: 3324,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_77[5],
      pVarName: "m_collisionMaxs",
      offset: 3336,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_PhysicsPropMultiplayer::g_RecvTable,
    pProps: &RecvProps_77[1],
    nProps: 5,
    pNetTableName: "DT_PhysicsPropMultiplayer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081D90
// Name: int ClientClassInit<struct DT_RagdollManager::ignored>(struct DT_RagdollManager::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_RagdollManager::ignored>()
{
  if ( (_S5_67 & 1) == 0 )
  {
    _S5_67 |= 1u;
    RecvPropInt(
      result: RecvProps_78,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_78[1],
      pVarName: "m_iCurrentMaxRagdollCount",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_RagdollManager::g_RecvTable,
    pProps: &RecvProps_78[1],
    nProps: 1,
    pNetTableName: "DT_RagdollManager");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081FA0
// Name: int ClientClassInit<struct DT_RopeKeyframe::ignored>(struct DT_RopeKeyframe::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_RopeKeyframe::ignored>()
{
  if ( (_S5_68 & 1) == 0 )
  {
    _S5_68 |= 1u;
    RecvPropInt(
      result: RecvProps_79,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[1],
      pVarName: "m_nChangeCount",
      offset: 3180,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[2],
      pVarName: "m_iRopeMaterialModelIndex",
      offset: 2492,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_79[3],
      pVarName: "m_hStartPoint",
      offset: 3148,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropEHandle(
      result: &RecvProps_79[4],
      pVarName: "m_hEndPoint",
      offset: 3152,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_79[5],
      pVarName: "m_iStartAttachment",
      offset: 3156,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[6],
      pVarName: "m_iEndAttachment",
      offset: 3158,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[7],
      pVarName: "m_fLockedPoints",
      offset: 3176,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[8],
      pVarName: "m_Slack",
      offset: 3168,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_RecomputeSprings);
    RecvPropInt(
      result: &RecvProps_79[9],
      pVarName: "m_RopeLength",
      offset: 3164,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_RecomputeSprings);
    RecvPropInt(
      result: &RecvProps_79[10],
      pVarName: "m_RopeFlags",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_79[11],
      pVarName: "m_TextureScale",
      offset: 3172,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_79[12],
      pVarName: "m_nSegments",
      offset: 3144,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_79[13], pVarName: "m_bConstrainBetweenEndpoints", offset: 3312, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_79[14],
      pVarName: "m_Subdiv",
      offset: 3160,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_79[15],
      pVarName: "m_Width",
      offset: 3184,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_79[16],
      pVarName: "m_flScrollSpeed",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_79[17],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_79[18],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_79[19],
      pVarName: "m_iParentAttachment",
      offset: 744,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[20],
      pVarName: "m_nMinCPULevel",
      offset: 2349,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[21],
      pVarName: "m_nMaxCPULevel",
      offset: 2350,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[22],
      pVarName: "m_nMinGPULevel",
      offset: 2351,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_79[23],
      pVarName: "m_nMaxGPULevel",
      offset: 2352,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_RopeKeyframe::g_RecvTable,
    pProps: &RecvProps_79[1],
    nProps: 23,
    pNetTableName: "DT_RopeKeyframe");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10089320
// Name: int ClientClassInit<struct DT_SceneEntity::ignored>(struct DT_SceneEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SceneEntity::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^1C.60

  if ( (_S5_69 & 1) == 0 )
  {
    _S5_69 |= 1u;
    RecvPropInt(
      result: RecvProps_80,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_80[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_80[2],
      pVarName: "m_nSceneStringIndex",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_80[3], pVarName: "m_bIsPlayingBack", offset: 2436, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_80[4], pVarName: "m_bPaused", offset: 2437, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_80[5], pVarName: "m_bMultiplayer", offset: 2438, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_80[6],
      pVarName: "m_flForceClientTime",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_ForcedClientTime);
    v3 = *RecvPropEHandle(result: &v1, pVarName: nullptr, offset: 0, sizeofVar: 0, proxyFn: RecvProxy_IntToEHandle);
    RecvPropUtlVector(
      result: &RecvProps_80[7],
      pVarName: "m_hActorList",
      offset: 2460,
      sizeofVar: 4,
      fn: UtlVectorTemplate<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::ResizeUtlVector,
      ensureFn: UtlVectorTemplate<CHandle<C_BaseFlex>,CUtlMemory<CHandle<C_BaseFlex>,int>>::EnsureCapacity,
      nMaxElements: 16,
      pArrayProp: v3);
  }
  RecvTable::Construct(
    this: &DT_SceneEntity::g_RecvTable,
    pProps: &RecvProps_80[1],
    nProps: 7,
    pNetTableName: "DT_SceneEntity");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10089E00
// Name: int ClientClassInit<struct DT_ShadowControl::ignored>(struct DT_ShadowControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ShadowControl::ignored>()
{
  if ( (_S5_70 & 1) == 0 )
  {
    _S5_70 |= 1u;
    RecvPropInt(
      result: RecvProps_81,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_81[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_81[2],
      pVarName: "m_shadowDirection",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_81[3],
      pVarName: "m_shadowColor",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_81[4],
      pVarName: "m_flShadowMaxDist",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_81[5], pVarName: "m_bDisableShadows", offset: 2452, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_81[6], pVarName: "m_bEnableLocalLightShadows", offset: 2453, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_ShadowControl::g_RecvTable,
    pProps: &RecvProps_81[1],
    nProps: 6,
    pNetTableName: "DT_ShadowControl");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008A020
// Name: int ClientClassInit<struct DT_SlideshowDisplay::ignored>(struct DT_SlideshowDisplay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SlideshowDisplay::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60

  if ( (_S5_71 & 1) == 0 )
  {
    _S5_71 |= 1u;
    RecvPropInt(
      result: RecvProps_82,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_82[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_82[2], pVarName: "m_bEnabled", offset: 2432, sizeofVar: 1);
    RecvPropString(
      result: &RecvProps_82[3],
      pVarName: "m_szDisplayText",
      offset: 2433,
      bufferSize: 128,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_82[4],
      pVarName: "m_szSlideshowDirectory",
      offset: 2561,
      bufferSize: 128,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    v3 = *RecvPropInt(
            result: &v1,
            pVarName: "m_chCurrentSlideLists[0]",
            offset: 2712,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_82[5],
      pVarName: "m_chCurrentSlideLists",
      offset: 2712,
      sizeofVar: 1,
      elements: 16,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_82[6],
      pVarName: "m_fMinSlideTime",
      offset: 2736,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_82[7],
      pVarName: "m_fMaxSlideTime",
      offset: 2740,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_82[8],
      pVarName: "m_iCycleType",
      offset: 2748,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_82[9], pVarName: "m_bNoListRepeats", offset: 2752, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_SlideshowDisplay::g_RecvTable,
    pProps: &RecvProps_82[1],
    nProps: 9,
    pNetTableName: "DT_SlideshowDisplay");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008DEF0
// Name: int ClientClassInit<struct DT_SpatialEntity::ignored>(struct DT_SpatialEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SpatialEntity::ignored>()
{
  if ( (_S5_72 & 1) == 0 )
  {
    _S5_72 |= 1u;
    RecvPropInt(
      result: RecvProps_83,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_83[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_83[2],
      pVarName: "m_vecOrigin",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_83[3],
      pVarName: "m_minFalloff",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_83[4],
      pVarName: "m_maxFalloff",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_83[5],
      pVarName: "m_flCurWeight",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_83[6], pVarName: "m_bEnabled", offset: 2716, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_SpatialEntity::g_RecvTable,
    pProps: &RecvProps_83[1],
    nProps: 6,
    pNetTableName: "DT_SpatialEntity");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008E360
// Name: int ClientClassInit<struct DT_SpotlightEnd::ignored>(struct DT_SpotlightEnd::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SpotlightEnd::ignored>()
{
  if ( (_S5_73 & 1) == 0 )
  {
    _S5_73 |= 1u;
    RecvPropInt(
      result: RecvProps_84,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_84[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_84[2],
      pVarName: "m_flLightScale",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_84[3],
      pVarName: "m_Radius",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_SpotlightEnd::g_RecvTable,
    pProps: &RecvProps_84[1],
    nProps: 3,
    pNetTableName: "DT_SpotlightEnd");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008F9B0
// Name: int ClientClassInit<struct DT_ParticlePerformanceMonitor::ignored>(struct DT_ParticlePerformanceMonitor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ParticlePerformanceMonitor::ignored>()
{
  if ( (_S5_74 & 1) == 0 )
  {
    _S5_74 |= 1u;
    RecvPropInt(
      result: RecvProps_85,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_85[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_85[2],
      pVarName: "m_bMeasurePerf",
      offset: 2433,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_85[3],
      pVarName: "m_bDisplayPerf",
      offset: 2432,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_ParticlePerformanceMonitor::g_RecvTable,
    pProps: &RecvProps_85[1],
    nProps: 3,
    pNetTableName: "DT_ParticlePerformanceMonitor");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FBC0
// Name: int ClientClassInit<struct DT_Sun::ignored>(struct DT_Sun::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Sun::ignored>()
{
  if ( (_S5_75 & 1) == 0 )
  {
    _S5_75 |= 1u;
    RecvPropInt(
      result: RecvProps_86,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_86[1],
      pVarName: "m_clrRender",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropInt(
      result: &RecvProps_86[2],
      pVarName: "m_clrOverlay",
      offset: 2768,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropVector(
      result: &RecvProps_86[3],
      pVarName: "m_vDirection",
      offset: 2780,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_86[4], pVarName: "m_bOn", offset: 2792, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_86[5], pVarName: "m_nSize", offset: 2772, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_86[6],
      pVarName: "m_nOverlaySize",
      offset: 2776,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_86[7],
      pVarName: "m_nMaterial",
      offset: 2796,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_86[8],
      pVarName: "m_nOverlayMaterial",
      offset: 2800,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_86[9],
      pVarName: "HDRColorScale",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_HDRColorScale_0);
  }
  RecvTable::Construct(this: &DT_Sun::g_RecvTable, pProps: &RecvProps_86[1], nProps: 9, pNetTableName: "DT_Sun");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090240
// Name: int ClientClassInit<struct DT_SunlightShadowControl::ignored>(struct DT_SunlightShadowControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SunlightShadowControl::ignored>()
{
  if ( (_S5_76 & 1) == 0 )
  {
    _S5_76 |= 1u;
    RecvPropInt(
      result: RecvProps_87,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_87[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_87[2],
      pVarName: "m_shadowDirection",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropBool(result: &RecvProps_87[3], pVarName: "m_bEnabled", offset: 2444, sizeofVar: 1);
    RecvPropString(
      result: &RecvProps_87[4],
      pVarName: "m_TextureName",
      offset: 2445,
      bufferSize: 260,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_87[5],
      pVarName: "m_LightColor",
      offset: 2712,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropFloat(
      result: &RecvProps_87[6],
      pVarName: "m_flColorTransitionTime",
      offset: 2732,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_87[7],
      pVarName: "m_flSunDistance",
      offset: 2736,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_87[8],
      pVarName: "m_flFOV",
      offset: 2740,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_87[9],
      pVarName: "m_flNearZ",
      offset: 2744,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_87[10],
      pVarName: "m_flNorthOffset",
      offset: 2748,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_87[11], pVarName: "m_bEnableShadows", offset: 2752, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_SunlightShadowControl::g_RecvTable,
    pProps: &RecvProps_87[1],
    nProps: 11,
    pNetTableName: "DT_SunlightShadowControl");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090F00
// Name: int ClientClassInit<struct DT_Team::ignored>(struct DT_Team::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Team::ignored>()
{
  if ( (_S5_77 & 1) == 0 )
  {
    _S5_77 |= 1u;
    RecvPropInt(
      result: RecvProps_88,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_88[1],
      pVarName: "m_iTeamNum",
      offset: 2504,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_88[2], pVarName: "m_iScore", offset: 2484, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_88[3],
      pVarName: "m_iRoundsWon",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropString(
      result: &RecvProps_88[4],
      pVarName: "m_szTeamname",
      offset: 2452,
      bufferSize: 32,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_88[5],
      pVarName: "player_array_element",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_PlayerList);
    InternalRecvPropArray(
      result: &RecvProps_88[6],
      elementCount: 64,
      elementStride: 0,
      pName: "\"player_array\"",
      proxy: RecvProxyArrayLength_PlayerArray);
  }
  RecvTable::Construct(this: &DT_Team::g_RecvTable, pProps: &RecvProps_88[1], nProps: 6, pNetTableName: "DT_Team");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091260
// Name: int ClientClassInit<struct DT_BaseTeamObjectiveResource::ignored>(struct DT_BaseTeamObjectiveResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseTeamObjectiveResource::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60
  RecvProp v6; // 0:^2C.60
  RecvProp v7; // 0:^2C.60
  RecvProp v8; // 0:^2C.60
  RecvProp v9; // 0:^2C.60
  RecvProp v10; // 0:^2C.60
  RecvProp v11; // 0:^2C.60
  RecvProp v12; // 0:^2C.60
  RecvProp v13; // 0:^2C.60
  RecvProp v14; // 0:^2C.60
  RecvProp v15; // 0:^2C.60
  RecvProp v16; // 0:^2C.60
  RecvProp v17; // 0:^2C.60
  RecvProp v18; // 0:^2C.60
  RecvProp v19; // 0:^2C.60
  RecvProp v20; // 0:^2C.60

  if ( (_S5_78 & 1) == 0 )
  {
    _S5_78 |= 1u;
    RecvPropInt(
      result: RecvProps_89,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_89[1],
      pVarName: "m_iTimerToShowInHUD",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_89[2],
      pVarName: "m_iStopWatchTimer",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_89[3],
      pVarName: "m_iNumControlPoints",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_89[4], pVarName: "m_bPlayingMiniRounds", offset: 2448, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_89[5], pVarName: "m_bControlPointsReset", offset: 2449, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_89[6],
      pVarName: "m_iUpdateCapHudParity",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_89[7],
      pVarName: "m_vCPPositions[0]",
      offset: 2460,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    InternalRecvPropArray(
      result: &RecvProps_89[8],
      elementCount: 8,
      elementStride: 12,
      pName: "m_vCPPositions",
      proxy: nullptr);
    v3 = *RecvPropInt(
            result: &v1,
            pVarName: "m_bCPIsVisible[0]",
            offset: 2556,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[9],
      pVarName: "m_bCPIsVisible",
      offset: 2556,
      sizeofVar: 1,
      elements: 8,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flLazyCapPerc[0]",
            offset: 2564,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_89[10],
      pVarName: "m_flLazyCapPerc",
      offset: 2564,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropInt(result: &v1, pVarName: "m_iTeamIcons[0]", offset: 2628, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[11],
      pVarName: "m_iTeamIcons",
      offset: 2628,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v6 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iTeamOverlays[0]",
            offset: 2884,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[12],
      pVarName: "m_iTeamOverlays",
      offset: 2884,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v6,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v7 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iTeamReqCappers[0]",
            offset: 3140,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[13],
      pVarName: "m_iTeamReqCappers",
      offset: 3140,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v7,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v8 = *RecvPropTime(result: &v1, pVarName: "m_flTeamCapTime[0]", offset: 3396, sizeofVar: 4);
    RecvPropArray3(
      result: &RecvProps_89[14],
      pVarName: "m_flTeamCapTime",
      offset: 3396,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v8,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v9 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iPreviousPoints[0]",
            offset: 3652,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[15],
      pVarName: "m_iPreviousPoints",
      offset: 3652,
      sizeofVar: 4,
      elements: 192,
      pArrayProp: v9,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v10 = *RecvPropBool(result: &v1, pVarName: "m_bTeamCanCap[0]", offset: 4420, sizeofVar: 1);
    RecvPropArray3(
      result: &RecvProps_89[16],
      pVarName: "m_bTeamCanCap",
      offset: 4420,
      sizeofVar: 1,
      elements: 64,
      pArrayProp: v10,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v11 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iTeamBaseIcons[0]",
             offset: 4484,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[17],
      pVarName: "m_iTeamBaseIcons",
      offset: 4484,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v11,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v12 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iBaseControlPoints[0]",
             offset: 4612,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[18],
      pVarName: "m_iBaseControlPoints",
      offset: 4612,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v12,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v13 = *RecvPropBool(result: &v1, pVarName: "m_bInMiniRound[0]", offset: 4740, sizeofVar: 1);
    RecvPropArray3(
      result: &RecvProps_89[19],
      pVarName: "m_bInMiniRound",
      offset: 4740,
      sizeofVar: 1,
      elements: 8,
      pArrayProp: v13,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v14 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iWarnOnCap[0]",
             offset: 4748,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[20],
      pVarName: "m_iWarnOnCap",
      offset: 4748,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v14,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_89[21],
      pVarName: "m_iszWarnSound[0]",
      offset: 4780,
      bufferSize: 255,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    InternalRecvPropArray(
      result: &RecvProps_89[22],
      elementCount: 8,
      elementStride: 255,
      pName: "m_iszWarnSound",
      proxy: nullptr);
    v15 = *RecvPropFloat(
             result: &v1,
             pVarName: "m_flPathDistance[0]",
             offset: 6820,
             sizeofVar: 4,
             flags: 0,
             varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_89[23],
      pVarName: "m_flPathDistance",
      offset: 6820,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v15,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v16 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iNumTeamMembers[0]",
             offset: 6852,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[24],
      pVarName: "m_iNumTeamMembers",
      offset: 6852,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v16,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v17 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iCappingTeam[0]",
             offset: 7108,
             sizeofVar: 4,
             flags: 0,
             varProxy: RecvProxy_CappingTeam);
    RecvPropArray3(
      result: &RecvProps_89[25],
      pVarName: "m_iCappingTeam",
      offset: 7108,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v17,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v18 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iTeamInZone[0]",
             offset: 7140,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[26],
      pVarName: "m_iTeamInZone",
      offset: 7140,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v18,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v19 = *RecvPropInt(result: &v1, pVarName: "m_bBlocked[0]", offset: 7172, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_89[27],
      pVarName: "m_bBlocked",
      offset: 7172,
      sizeofVar: 1,
      elements: 8,
      pArrayProp: v19,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v20 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iOwner[0]",
             offset: 7180,
             sizeofVar: 4,
             flags: 0,
             varProxy: RecvProxy_Owner);
    RecvPropArray3(
      result: &RecvProps_89[28],
      pVarName: "m_iOwner",
      offset: 7180,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v20,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_89[29],
      pVarName: "m_pszCapLayoutInHUD",
      offset: 7316,
      bufferSize: 32,
      flags: 0,
      varProxy: RecvProxy_CapLayout);
  }
  RecvTable::Construct(
    this: &DT_BaseTeamObjectiveResource::g_RecvTable,
    pProps: &RecvProps_89[1],
    nProps: 29,
    pNetTableName: "DT_BaseTeamObjectiveResource");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091F40
// Name: int ClientClassInit<struct DT_Tesla::ignored>(struct DT_Tesla::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Tesla::ignored>()
{
  if ( (_S5_79 & 1) == 0 )
  {
    _S5_79 |= 1u;
    RecvPropInt(
      result: RecvProps_90,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_90[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_90[2],
      pVarName: "m_SoundName",
      offset: 2472,
      bufferSize: 64,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_90[3],
      pVarName: "m_iszSpriteName",
      offset: 2536,
      bufferSize: 256,
      flags: 0,
      varProxy: RecvProxy_StringToString);
  }
  RecvTable::Construct(this: &DT_Tesla::g_RecvTable, pProps: &RecvProps_90[1], nProps: 3, pNetTableName: "DT_Tesla");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092DE0
// Name: int ClientClassInit<struct DT_ProxyToggle_ProxiedData::ignored>(struct DT_ProxyToggle_ProxiedData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ProxyToggle_ProxiedData::ignored>()
{
  if ( (_S5_80 & 1) == 0 )
  {
    _S5_80 |= 1u;
    RecvPropInt(
      result: RecvProps_91,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_91[1],
      pVarName: "m_WithProxy",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_ProxyToggle_ProxiedData::g_RecvTable,
    pProps: &RecvProps_91[1],
    nProps: 1,
    pNetTableName: "DT_ProxyToggle_ProxiedData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092EC0
// Name: int ClientClassInit<struct DT_ProxyToggle::ignored>(struct DT_ProxyToggle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ProxyToggle::ignored>()
{
  if ( (_S6_22 & 1) == 0 )
  {
    _S6_22 |= 1u;
    RecvPropInt(
      result: RecvProps_92,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_92[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_92[2],
      pVarName: "blah",
      offset: 0,
      flags: 0,
      pTable: &DT_ProxyToggle_ProxiedData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_ProxyToggle::g_RecvTable,
    pProps: &RecvProps_92[1],
    nProps: 2,
    pNetTableName: "DT_ProxyToggle");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092FF0
// Name: int ClientClassInit<struct DT_BaseTrigger::ignored>(struct DT_BaseTrigger::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseTrigger::ignored>()
{
  if ( (_S5_81 & 1) == 0 )
  {
    _S5_81 |= 1u;
    RecvPropInt(
      result: RecvProps_93,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_93[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseToggle::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_93[2], pVarName: "m_bClientSidePredicted", offset: 2480, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_93[3],
      pVarName: "m_spawnflags",
      offset: 700,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseTrigger::g_RecvTable,
    pProps: &RecvProps_93[1],
    nProps: 3,
    pNetTableName: "DT_BaseTrigger");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100930A0
// Name: int ClientClassInit<struct DT_TriggerPlayerMovement::ignored>(struct DT_TriggerPlayerMovement::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TriggerPlayerMovement::ignored>()
{
  if ( (_S6_23 & 1) == 0 )
  {
    _S6_23 |= 1u;
    RecvPropInt(
      result: RecvProps_94,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_94[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTrigger::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_TriggerPlayerMovement::g_RecvTable,
    pProps: &RecvProps_94[1],
    nProps: 1,
    pNetTableName: "DT_TriggerPlayerMovement");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10093120
// Name: int ClientClassInit<struct DT_BaseVPhysicsTrigger::ignored>(struct DT_BaseVPhysicsTrigger::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseVPhysicsTrigger::ignored>()
{
  if ( (_S7_7 & 1) == 0 )
  {
    _S7_7 |= 1u;
    RecvPropInt(
      result: RecvProps_95,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_95[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_BaseVPhysicsTrigger::g_RecvTable,
    pProps: &RecvProps_95[1],
    nProps: 1,
    pNetTableName: "DT_BaseVPhysicsTrigger");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100937D0
// Name: int ClientClassInit<struct DT_PropVehicleChoreoGeneric::ignored>(struct DT_PropVehicleChoreoGeneric::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PropVehicleChoreoGeneric::ignored>()
{
  if ( (_S5_82 & 1) == 0 )
  {
    _S5_82 |= 1u;
    RecvPropInt(
      result: RecvProps_96,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_96[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_DynamicProp::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_96[2],
      pVarName: "m_hPlayer",
      offset: 3332,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropBool(result: &RecvProps_96[3], pVarName: "m_bEnterAnimOn", offset: 3340, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_96[4], pVarName: "m_bExitAnimOn", offset: 3341, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_96[5], pVarName: "m_bForceEyesToAttachment", offset: 3356, sizeofVar: 1);
    RecvPropVector(
      result: &RecvProps_96[6],
      pVarName: "m_vecEyeExitEndpoint",
      offset: 3344,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropBool(result: &RecvProps_96[7], pVarName: "m_vehicleView.bClampEyeAngles", offset: 3488, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_96[8],
      pVarName: "m_vehicleView.flPitchCurveZero",
      offset: 3492,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[9],
      pVarName: "m_vehicleView.flPitchCurveLinear",
      offset: 3496,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[10],
      pVarName: "m_vehicleView.flRollCurveZero",
      offset: 3500,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[11],
      pVarName: "m_vehicleView.flRollCurveLinear",
      offset: 3504,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[12],
      pVarName: "m_vehicleView.flFOV",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[13],
      pVarName: "m_vehicleView.flYawMin",
      offset: 3512,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[14],
      pVarName: "m_vehicleView.flYawMax",
      offset: 3516,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[15],
      pVarName: "m_vehicleView.flPitchMin",
      offset: 3520,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_96[16],
      pVarName: "m_vehicleView.flPitchMax",
      offset: 3524,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_PropVehicleChoreoGeneric::g_RecvTable,
    pProps: &RecvProps_96[1],
    nProps: 16,
    pNetTableName: "DT_PropVehicleChoreoGeneric");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094100
// Name: int ClientClassInit<struct DT_PropJeep::ignored>(struct DT_PropJeep::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PropJeep::ignored>()
{
  if ( (_S5_83 & 1) == 0 )
  {
    _S5_83 |= 1u;
    RecvPropInt(
      result: RecvProps_97,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_97[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_PropVehicleDriveable::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_97[2], pVarName: "m_bHeadlightIsOn", offset: 3588, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_PropJeep::g_RecvTable,
    pProps: &RecvProps_97[1],
    nProps: 2,
    pNetTableName: "DT_PropJeep");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094920
// Name: int ClientClassInit<struct DT_VGuiScreen::ignored>(struct DT_VGuiScreen::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_VGuiScreen::ignored>()
{
  if ( (_S5_84 & 1) == 0 )
  {
    _S5_84 |= 1u;
    RecvPropInt(
      result: RecvProps_98,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_98[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_98[2],
      pVarName: "m_flWidth",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_98[3],
      pVarName: "m_flHeight",
      offset: 2444,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_98[4],
      pVarName: "m_fScreenFlags",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_98[5],
      pVarName: "m_nPanelName",
      offset: 2448,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_98[6],
      pVarName: "m_nAttachmentIndex",
      offset: 2476,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntSubOne);
    RecvPropInt(
      result: &RecvProps_98[7],
      pVarName: "m_nOverlayMaterial",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_98[8],
      pVarName: "m_hPlayerOwner",
      offset: 2576,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_VGuiScreen::g_RecvTable,
    pProps: &RecvProps_98[1],
    nProps: 8,
    pNetTableName: "DT_VGuiScreen");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100972E0
// Name: int ClientClassInit<struct DT_WaterBullet::ignored>(struct DT_WaterBullet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WaterBullet::ignored>()
{
  if ( (_S5_85 & 1) == 0 )
  {
    _S5_85 |= 1u;
    RecvPropInt(
      result: RecvProps_99,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_99[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WaterBullet::g_RecvTable,
    pProps: &RecvProps_99[1],
    nProps: 1,
    pNetTableName: "DT_WaterBullet");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10097880
// Name: int ClientClassInit<struct DT_WaterLODControl::ignored>(struct DT_WaterLODControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WaterLODControl::ignored>()
{
  if ( (_S5_86 & 1) == 0 )
  {
    _S5_86 |= 1u;
    RecvPropInt(
      result: RecvProps_100,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_100[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_100[2],
      pVarName: "m_flCheapWaterStartDistance",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_100[3],
      pVarName: "m_flCheapWaterEndDistance",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_WaterLODControl::g_RecvTable,
    pProps: &RecvProps_100[1],
    nProps: 3,
    pNetTableName: "DT_WaterLODControl");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10097A40
// Name: int ClientClassInit<struct DT_World::ignored>(struct DT_World::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_World::ignored>()
{
  if ( (_S5_87 & 1) == 0 )
  {
    _S5_87 |= 1u;
    RecvPropInt(
      result: RecvProps_101,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_101[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_101[2],
      pVarName: "m_flWaveHeight",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_101[3],
      pVarName: "m_WorldMins",
      offset: 2436,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_101[4],
      pVarName: "m_WorldMaxs",
      offset: 2448,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_101[5],
      pVarName: "m_bStartDark",
      offset: 2460,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_101[6],
      pVarName: "m_flMaxOccludeeArea",
      offset: 2464,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_101[7],
      pVarName: "m_flMinOccluderArea",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_101[8],
      pVarName: "m_flMaxPropScreenSpaceWidth",
      offset: 2476,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_101[9],
      pVarName: "m_flMinPropScreenSpaceWidth",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropString(
      result: &RecvProps_101[10],
      pVarName: "m_iszDetailSpriteMaterial",
      offset: 2488,
      bufferSize: 256,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropInt(
      result: &RecvProps_101[11],
      pVarName: "m_bColdWorld",
      offset: 2480,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_101[12],
      pVarName: "m_iTimeOfDay",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(this: &DT_World::g_RecvTable, pProps: &RecvProps_101[1], nProps: 12, pNetTableName: "DT_World");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C1B00
// Name: int ClientClassInit<struct DT_CollisionProperty::ignored>(struct DT_CollisionProperty::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CollisionProperty::ignored>()
{
  if ( (_S5_91 & 1) == 0 )
  {
    _S5_91 |= 1u;
    RecvPropInt(
      result: RecvProps_102,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_102[1],
      pVarName: "m_vecMins",
      offset: 8,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_OBBMins);
    RecvPropVector(
      result: &RecvProps_102[2],
      pVarName: "m_vecMaxs",
      offset: 20,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_OBBMaxs);
    RecvPropInt(
      result: &RecvProps_102[3],
      pVarName: "m_nSolidType",
      offset: 34,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_Solid);
    RecvPropInt(
      result: &RecvProps_102[4],
      pVarName: "m_usSolidFlags",
      offset: 32,
      sizeofVar: 2,
      flags: 0,
      varProxy: RecvProxy_SolidFlags);
    RecvPropInt(
      result: &RecvProps_102[5],
      pVarName: "m_nSurroundType",
      offset: 42,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_IntDirtySurround);
    RecvPropInt(
      result: &RecvProps_102[6],
      pVarName: "m_triggerBloat",
      offset: 35,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_IntDirtySurround);
    RecvPropVector(
      result: &RecvProps_102[7],
      pVarName: "m_vecSpecifiedSurroundingMins",
      offset: 44,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorDirtySurround);
    RecvPropVector(
      result: &RecvProps_102[8],
      pVarName: "m_vecSpecifiedSurroundingMaxs",
      offset: 56,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorDirtySurround);
  }
  RecvTable::Construct(
    this: &DT_CollisionProperty::g_RecvTable,
    pProps: &RecvProps_102[1],
    nProps: 8,
    pNetTableName: "DT_CollisionProperty");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0A10
// Name: int ClientClassInit<struct DT_EffectData::ignored>(struct DT_EffectData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EffectData::ignored>()
{
  if ( (_S5_93 & 1) == 0 )
  {
    _S5_93 |= 1u;
    RecvPropInt(
      result: RecvProps_103,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_103[1],
      pVarName: "m_vOrigin.x",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[2],
      pVarName: "m_vOrigin.y",
      offset: 4,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[3],
      pVarName: "m_vOrigin.z",
      offset: 8,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[4],
      pVarName: "m_vStart.x",
      offset: 12,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[5],
      pVarName: "m_vStart.y",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[6],
      pVarName: "m_vStart.z",
      offset: 20,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_103[7],
      pVarName: "m_vAngles",
      offset: 36,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_103[8],
      pVarName: "m_vNormal",
      offset: 24,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_103[9], pVarName: "m_fFlags", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_103[10],
      pVarName: "m_flMagnitude",
      offset: 60,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_103[11],
      pVarName: "m_flScale",
      offset: 56,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_103[12],
      pVarName: "m_nAttachmentIndex",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_103[13],
      pVarName: "m_nSurfaceProp",
      offset: 72,
      sizeofVar: 2,
      proxyFn: RecvProxy_ShortSubOne);
    RecvPropInt(
      result: &RecvProps_103[14],
      pVarName: "m_iEffectName",
      offset: 96,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_103[15],
      pVarName: "m_nMaterial",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_103[16],
      pVarName: "m_nDamageType",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_103[17],
      pVarName: "m_nHitBox",
      offset: 84,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_103[18],
      pVarName: "entindex",
      offset: 0,
      sizeofVar: -1,
      flags: 0,
      varProxy: RecvProxy_EntIndex);
    RecvPropInt(
      result: &RecvProps_103[19],
      pVarName: "m_nOtherEntIndex",
      offset: 88,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_103[20], pVarName: "m_nColor", offset: 92, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_103[21],
      pVarName: "m_flRadius",
      offset: 64,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EffectData::g_RecvTable,
    pProps: &RecvProps_103[1],
    nProps: 21,
    pNetTableName: "DT_EffectData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1810
// Name: int ClientClassInit<struct DT_EntityParticleTrailInfo::ignored>(struct DT_EntityParticleTrailInfo::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EntityParticleTrailInfo::ignored>()
{
  if ( (_S5_94 & 1) == 0 )
  {
    _S5_94 |= 1u;
    RecvPropInt(
      result: RecvProps_104,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_104[1],
      pVarName: "m_flLifetime",
      offset: 8,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_104[2],
      pVarName: "m_flStartSize",
      offset: 12,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_104[3],
      pVarName: "m_flEndSize",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EntityParticleTrailInfo::g_RecvTable,
    pProps: &RecvProps_104[1],
    nProps: 3,
    pNetTableName: "DT_EntityParticleTrailInfo");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D1960
// Name: int ClientClassInit<struct DT_DetailController::ignored>(struct DT_DetailController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DetailController::ignored>()
{
  if ( (_S5_95 & 1) == 0 )
  {
    _S5_95 |= 1u;
    RecvPropInt(
      result: RecvProps_105,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_105[1],
      pVarName: "m_flFadeStartDist",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_105[2],
      pVarName: "m_flFadeEndDist",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_DetailController::g_RecvTable,
    pProps: &RecvProps_105[1],
    nProps: 2,
    pNetTableName: "DT_DetailController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D4A60
// Name: int ClientClassInit<struct DT_TEFoundryHelpers::ignored>(struct DT_TEFoundryHelpers::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEFoundryHelpers::ignored>()
{
  if ( (_S5_97 & 1) == 0 )
  {
    _S5_97 |= 1u;
    RecvPropInt(
      result: RecvProps_106,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_106[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_106[2], pVarName: "m_iEntity", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEFoundryHelpers::g_RecvTable,
    pProps: &RecvProps_106[1],
    nProps: 2,
    pNetTableName: "DT_TEFoundryHelpers");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5590
// Name: int ClientClassInit<struct DT_FuncLadder::ignored>(struct DT_FuncLadder::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FuncLadder::ignored>()
{
  if ( (_S5_98 & 1) == 0 )
  {
    _S5_98 |= 1u;
    RecvPropInt(
      result: RecvProps_107,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_107[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_107[2],
      pVarName: "m_vecPlayerMountPositionTop",
      offset: 2464,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_107[3],
      pVarName: "m_vecPlayerMountPositionBottom",
      offset: 2476,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_107[4],
      pVarName: "m_vecLadderDir",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropBool(result: &RecvProps_107[5], pVarName: "m_bFakeLadder", offset: 2489, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_FuncLadder::g_RecvTable,
    pProps: &RecvProps_107[1],
    nProps: 5,
    pNetTableName: "DT_FuncLadder");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5690
// Name: int ClientClassInit<struct DT_InfoLadderDismount::ignored>(struct DT_InfoLadderDismount::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_InfoLadderDismount::ignored>()
{
  if ( (_S7_9 & 1) == 0 )
  {
    _S7_9 |= 1u;
    RecvPropInt(
      result: RecvProps_108,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_108[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_InfoLadderDismount::g_RecvTable,
    pProps: &RecvProps_108[1],
    nProps: 1,
    pNetTableName: "DT_InfoLadderDismount");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D1C0
// Name: int ClientClassInit<struct DT_PoseController::ignored>(struct DT_PoseController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PoseController::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60

  if ( (_S5_110 & 1) == 0 )
  {
    _S5_110 |= 1u;
    RecvPropInt(
      result: RecvProps_109,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_109[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v3 = *RecvPropEHandle(
            result: &v1,
            pVarName: "m_hProps[0]",
            offset: 2432,
            sizeofVar: 4,
            proxyFn: RecvProxy_IntToEHandle);
    RecvPropArray3(
      result: &RecvProps_109[2],
      pVarName: "m_hProps",
      offset: 2432,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(
            result: &v1,
            pVarName: "m_chPoseIndex[0]",
            offset: 2448,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_109[3],
      pVarName: "m_chPoseIndex",
      offset: 2448,
      sizeofVar: 1,
      elements: 4,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_109[4], pVarName: "m_bPoseValueParity", offset: 2452, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_109[5],
      pVarName: "m_fPoseValue",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_109[6],
      pVarName: "m_fInterpolationTime",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_109[7], pVarName: "m_bInterpolationWrap", offset: 2464, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_109[8],
      pVarName: "m_fCycleFrequency",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_109[9],
      pVarName: "m_nFModType",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_109[10],
      pVarName: "m_fFModTimeOffset",
      offset: 2476,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_109[11],
      pVarName: "m_fFModRate",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_109[12],
      pVarName: "m_fFModAmplitude",
      offset: 2484,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_PoseController::g_RecvTable,
    pProps: &RecvProps_109[1],
    nProps: 12,
    pNetTableName: "DT_PoseController");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10150690
// Name: int ClientClassInit<struct DT_PredictedViewModel::ignored>(struct DT_PredictedViewModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PredictedViewModel::ignored>()
{
  if ( (_S5_111 & 1) == 0 )
  {
    _S5_111 |= 1u;
    RecvPropInt(
      result: RecvProps_110,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_110[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseViewModel::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_PredictedViewModel::g_RecvTable,
    pProps: &RecvProps_110[1],
    nProps: 1,
    pNetTableName: "DT_PredictedViewModel");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A3A0
// Name: int ClientClassInit<struct DT_Ragdoll::ignored>(struct DT_Ragdoll::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Ragdoll::ignored>()
{
  if ( (_S6_36 & 1) == 0 )
  {
    _S6_36 |= 1u;
    RecvPropInt(
      result: RecvProps_111,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_111[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_111[2],
      pVarName: "m_ragAngles[0]",
      offset: 3640,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    InternalRecvPropArray(
      result: &RecvProps_111[3],
      elementCount: 32,
      elementStride: 12,
      pName: "m_ragAngles",
      proxy: nullptr);
    RecvPropVector(
      result: &RecvProps_111[4],
      pVarName: "m_ragPos[0]",
      offset: 3256,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    InternalRecvPropArray(
      result: &RecvProps_111[5],
      elementCount: 32,
      elementStride: 12,
      pName: "m_ragPos",
      proxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_111[6],
      pVarName: "m_hUnragdoll",
      offset: 4244,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropFloat(
      result: &RecvProps_111[7],
      pVarName: "m_flBlendWeight",
      offset: 4248,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_111[8],
      pVarName: "m_nOverlaySequence",
      offset: 4256,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_Ragdoll::g_RecvTable,
    pProps: &RecvProps_111[1],
    nProps: 8,
    pNetTableName: "DT_Ragdoll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A510
// Name: int ClientClassInit<struct DT_Ragdoll_Attached::ignored>(struct DT_Ragdoll_Attached::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Ragdoll_Attached::ignored>()
{
  if ( (_S7_12 & 1) == 0 )
  {
    _S7_12 |= 1u;
    RecvPropInt(
      result: RecvProps_112,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_112[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_ServerRagdoll::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_112[2],
      pVarName: "m_boneIndexAttached",
      offset: 4304,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_112[3],
      pVarName: "m_ragdollAttachedObjectIndex",
      offset: 4300,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_112[4],
      pVarName: "m_attachmentPointBoneSpace",
      offset: 4264,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_112[5],
      pVarName: "m_attachmentPointRagdollSpace",
      offset: 4288,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_Ragdoll_Attached::g_RecvTable,
    pProps: &RecvProps_112[1],
    nProps: 5,
    pNetTableName: "DT_Ragdoll_Attached");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016F380
// Name: int ClientClassInit<struct DT_SpriteOriented::ignored>(struct DT_SpriteOriented::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SpriteOriented::ignored>()
{
  if ( (_S7_15 & 1) == 0 )
  {
    _S7_15 |= 1u;
    RecvPropInt(
      result: RecvProps_113,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_113[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_Sprite::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_SpriteOriented::g_RecvTable,
    pProps: &RecvProps_113[1],
    nProps: 1,
    pNetTableName: "DT_SpriteOriented");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016FE30
// Name: int ClientClassInit<struct DT_Sprite::ignored>(struct DT_Sprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Sprite::ignored>()
{
  if ( (_S5_118 & 1) == 0 )
  {
    _S5_118 |= 1u;
    RecvPropInt(
      result: RecvProps_114,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_114[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_114[2],
      pVarName: "m_hAttachedToEntity",
      offset: 2448,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_114[3],
      pVarName: "m_nAttachment",
      offset: 2452,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_114[4],
      pVarName: "m_flScaleTime",
      offset: 2480,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_114[5],
      pVarName: "m_flSpriteScale",
      offset: 2476,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_SpriteScale);
    RecvPropFloat(
      result: &RecvProps_114[6],
      pVarName: "m_flSpriteFramerate",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_114[7],
      pVarName: "m_flGlowProxySize",
      offset: 2488,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_114[8],
      pVarName: "m_flHDRColorScale",
      offset: 2492,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_114[9],
      pVarName: "m_flFrame",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_114[10],
      pVarName: "m_flBrightnessTime",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_114[11],
      pVarName: "m_nBrightness",
      offset: 2468,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_114[12], pVarName: "m_bWorldSpaceScale", offset: 2484, sizeofVar: 1);
  }
  RecvTable::Construct(this: &DT_Sprite::g_RecvTable, pProps: &RecvProps_114[1], nProps: 12, pNetTableName: "DT_Sprite");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10170BC0
// Name: int ClientClassInit<struct DT_SpriteTrail::ignored>(struct DT_SpriteTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SpriteTrail::ignored>()
{
  if ( (_S7_16 & 1) == 0 )
  {
    _S7_16 |= 1u;
    RecvPropInt(
      result: RecvProps_115,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_115[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_Sprite::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_115[2],
      pVarName: "m_flLifeTime",
      offset: 4124,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_115[3],
      pVarName: "m_flStartWidth",
      offset: 4128,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_115[4],
      pVarName: "m_flEndWidth",
      offset: 4132,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_115[5],
      pVarName: "m_flStartWidthVariance",
      offset: 4136,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_115[6],
      pVarName: "m_flTextureRes",
      offset: 4140,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_115[7],
      pVarName: "m_flMinFadeLength",
      offset: 4144,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_115[8],
      pVarName: "m_vecSkyboxOrigin",
      offset: 4148,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_115[9],
      pVarName: "m_flSkyboxScale",
      offset: 4160,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_SpriteTrail::g_RecvTable,
    pProps: &RecvProps_115[1],
    nProps: 9,
    pNetTableName: "DT_SpriteTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10179AA0
// Name: int ClientClassInit<struct DT_TeamplayRoundBasedRulesProxy::ignored>(struct DT_TeamplayRoundBasedRulesProxy::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TeamplayRoundBasedRulesProxy::ignored>()
{
  if ( (_S6_43 & 1) == 0 )
  {
    _S6_43 |= 1u;
    RecvPropInt(
      result: RecvProps_116,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_116[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_GameRulesProxy::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_116[2],
      pVarName: "teamplayroundbased_gamerules_data",
      offset: 0,
      flags: 0,
      pTable: &DT_TeamplayRoundBasedRules::g_RecvTable,
      varProxy: RecvProxy_TeamplayRoundBasedRules);
  }
  RecvTable::Construct(
    this: &DT_TeamplayRoundBasedRulesProxy::g_RecvTable,
    pProps: &RecvProps_116[1],
    nProps: 2,
    pNetTableName: "DT_TeamplayRoundBasedRulesProxy");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10179BF0
// Name: int ClientClassInit<struct DT_TeamplayRoundBasedRules::ignored>(struct DT_TeamplayRoundBasedRules::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TeamplayRoundBasedRules::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60

  if ( (_S5_121 & 1) == 0 )
  {
    _S5_121 |= 1u;
    RecvPropInt(
      result: RecvProps_117,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_117[1],
      pVarName: "m_iRoundState",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_TeamplayRoundState);
    RecvPropBool(result: &RecvProps_117[2], pVarName: "m_bInWaitingForPlayers", offset: 56, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_117[3],
      pVarName: "m_iWinningTeam",
      offset: 48,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_117[4],
      pVarName: "m_bInOvertime",
      offset: 44,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_117[5],
      pVarName: "m_bInSetup",
      offset: 45,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_117[6],
      pVarName: "m_bSwitchedTeamsThisRound",
      offset: 46,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_117[7], pVarName: "m_bAwaitingReadyRestart", offset: 57, sizeofVar: 1);
    RecvPropTime(result: &RecvProps_117[8], pVarName: "m_flRestartRoundTime", offset: 60, sizeofVar: 4);
    RecvPropTime(result: &RecvProps_117[9], pVarName: "m_flMapResetTime", offset: 64, sizeofVar: 4);
    v3 = *RecvPropTime(result: &v1, pVarName: "m_flNextRespawnWave[0]", offset: 68, sizeofVar: 4);
    RecvPropArray3(
      result: &RecvProps_117[10],
      pVarName: "m_flNextRespawnWave",
      offset: 68,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_TeamRespawnWaveTimes[0]",
            offset: 232,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_117[11],
      pVarName: "m_TeamRespawnWaveTimes",
      offset: 232,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropBool(result: &v1, pVarName: "m_bTeamReady[0]", offset: 196, sizeofVar: 1);
    RecvPropArray3(
      result: &RecvProps_117[12],
      pVarName: "m_bTeamReady",
      offset: 196,
      sizeofVar: 1,
      elements: 32,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_117[13], pVarName: "m_bStopWatch", offset: 228, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_TeamplayRoundBasedRules::g_RecvTable,
    pProps: &RecvProps_117[1],
    nProps: 13,
    pNetTableName: "DT_TeamplayRoundBasedRules");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10179E30
// Name: int ClientClassInit<struct DT_HandleTest::ignored>(struct DT_HandleTest::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_HandleTest::ignored>()
{
  if ( (_S5_122 & 1) == 0 )
  {
    _S5_122 |= 1u;
    RecvPropInt(
      result: RecvProps_118,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_118[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_118[2],
      pVarName: "m_Handle",
      offset: 2432,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_118[3],
      pVarName: "m_bSendHandle",
      offset: 2436,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_HandleTest::g_RecvTable,
    pProps: &RecvProps_118[1],
    nProps: 3,
    pNetTableName: "DT_HandleTest");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D6C0
// Name: int ClientClassInit<struct DT_IntervalTimer::ignored>(struct DT_IntervalTimer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_IntervalTimer::ignored>()
{
  if ( (_S7_17 & 1) == 0 )
  {
    _S7_17 |= 1u;
    RecvPropInt(
      result: RecvProps_119,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_119[1],
      pVarName: "m_timestamp",
      offset: 4,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_IntervalTimer::g_RecvTable,
    pProps: &RecvProps_119[1],
    nProps: 1,
    pNetTableName: "DT_IntervalTimer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D720
// Name: int ClientClassInit<struct DT_CountdownTimer::ignored>(struct DT_CountdownTimer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CountdownTimer::ignored>()
{
  if ( (_S8_11 & 1) == 0 )
  {
    _S8_11 |= 1u;
    RecvPropInt(
      result: RecvProps_120,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_120[1],
      pVarName: "m_duration",
      offset: 4,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_120[2],
      pVarName: "m_timestamp",
      offset: 8,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_CountdownTimer::g_RecvTable,
    pProps: &RecvProps_120[1],
    nProps: 2,
    pNetTableName: "DT_CountdownTimer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017E410
// Name: int ClientClassInit<struct DT_Timeline::ignored>(struct DT_Timeline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Timeline::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60

  if ( (_S10_2 & 1) == 0 )
  {
    _S10_2 |= 1u;
    RecvPropInt(
      result: RecvProps_121,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    v3 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_flValues[0]",
            offset: 8,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_121[1],
      pVarName: "m_flValues",
      offset: 8,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropFloat(
            result: &v1,
            pVarName: "m_nValueCounts[0]",
            offset: 264,
            sizeofVar: 4,
            flags: 0,
            varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropArray3(
      result: &RecvProps_121[2],
      pVarName: "m_nValueCounts",
      offset: 264,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_121[3],
      pVarName: "m_nBucketCount",
      offset: 520,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_121[4],
      pVarName: "m_flInterval",
      offset: 524,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_121[5],
      pVarName: "m_flFinalValue",
      offset: 528,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_121[6],
      pVarName: "m_nCompressionType",
      offset: 532,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_121[7], pVarName: "m_bStopped", offset: 536, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_Timeline::g_RecvTable,
    pProps: &RecvProps_121[1],
    nProps: 7,
    pNetTableName: "DT_Timeline");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B3AD0
// Name: int ClientClassInit<struct DT_BaseCSGrenadeProjectile::ignored>(struct DT_BaseCSGrenadeProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseCSGrenadeProjectile::ignored>()
{
  if ( (_S5_129 & 1) == 0 )
  {
    _S5_129 |= 1u;
    RecvPropInt(
      result: RecvProps_122,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_122[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_122[2],
      pVarName: "m_vInitialVelocity",
      offset: 3296,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_BaseCSGrenadeProjectile::g_RecvTable,
    pProps: &RecvProps_122[1],
    nProps: 2,
    pNetTableName: "DT_BaseCSGrenadeProjectile");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B7910
// Name: int ClientClassInit<struct DT_CHostage::ignored>(struct DT_CHostage::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CHostage::ignored>()
{
  if ( (_S5_130 & 1) == 0 )
  {
    _S5_130 |= 1u;
    RecvPropInt(
      result: RecvProps_123,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_123[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatCharacter::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_123[2],
      pVarName: "m_isRescued",
      offset: 4676,
      sizeofVar: 1,
      flags: 0,
      varProxy: C_CHostage::RecvProxy_Rescued);
    RecvPropInt(
      result: &RecvProps_123[3],
      pVarName: "m_iHealth",
      offset: 244,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_123[4],
      pVarName: "m_iMaxHealth",
      offset: 4664,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_123[5],
      pVarName: "m_lifeState",
      offset: 595,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_123[6],
      pVarName: "m_leader",
      offset: 4672,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_CHostage::g_RecvTable,
    pProps: &RecvProps_123[1],
    nProps: 6,
    pNetTableName: "DT_CHostage");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B81B0
// Name: int ClientClassInit<struct DT_TEPlayerAnimEvent::ignored>(struct DT_TEPlayerAnimEvent::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEPlayerAnimEvent::ignored>()
{
  if ( (_S5_131 & 1) == 0 )
  {
    _S5_131 |= 1u;
    RecvPropInt(
      result: RecvProps_124,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_124[1],
      pVarName: "m_hPlayer",
      offset: 16,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(result: &RecvProps_124[2], pVarName: "m_iEvent", offset: 20, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_124[3], pVarName: "m_nData", offset: 24, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEPlayerAnimEvent::g_RecvTable,
    pProps: &RecvProps_124[1],
    nProps: 3,
    pNetTableName: "DT_TEPlayerAnimEvent");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B8260
// Name: int ClientClassInit<struct DT_CSRagdoll::ignored>(struct DT_CSRagdoll::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSRagdoll::ignored>()
{
  if ( (_S6_51 & 1) == 0 )
  {
    _S6_51 |= 1u;
    RecvPropInt(
      result: RecvProps_125,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_125[1],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_125[2],
      pVarName: "m_vecRagdollOrigin",
      offset: 3376,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropEHandle(
      result: &RecvProps_125[3],
      pVarName: "m_hPlayer",
      offset: 3360,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_125[4],
      pVarName: "m_nModelIndex",
      offset: 588,
      sizeofVar: 2,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_125[5],
      pVarName: "m_nForceBone",
      offset: 2548,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_125[6],
      pVarName: "m_vecForce",
      offset: 2536,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_125[7],
      pVarName: "m_vecRagdollVelocity",
      offset: 3364,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_125[8],
      pVarName: "m_iDeathPose",
      offset: 3388,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_125[9],
      pVarName: "m_iDeathFrame",
      offset: 3392,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_125[10],
      pVarName: "m_iTeamNum",
      offset: 236,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_125[11],
      pVarName: "m_bClientSideAnimation",
      offset: 3028,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_CSRagdoll::g_RecvTable,
    pProps: &RecvProps_125[1],
    nProps: 11,
    pNetTableName: "DT_CSRagdoll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B83F0
// Name: int ClientClassInit<struct DT_CSNonLocalPlayerExclusive::ignored>(struct DT_CSNonLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSNonLocalPlayerExclusive::ignored>()
{
  if ( (_S8_14 & 1) == 0 )
  {
    _S8_14 |= 1u;
    RecvPropInt(
      result: RecvProps_126,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVectorXY(
      result: &RecvProps_126[1],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_NonLocalCellOriginXY);
    RecvPropFloat(
      result: &RecvProps_126[2],
      pVarName: "m_vecOrigin[2]",
      offset: 308,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_NonLocalCellOriginZ);
  }
  RecvTable::Construct(
    this: &DT_CSNonLocalPlayerExclusive::g_RecvTable,
    pProps: &RecvProps_126[1],
    nProps: 2,
    pNetTableName: "DT_CSNonLocalPlayerExclusive");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B9000
// Name: int ClientClassInit<struct DT_CSLocalPlayerExclusive::ignored>(struct DT_CSLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSLocalPlayerExclusive::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^24.60
  RecvProp v4; // 0:^24.60

  if ( (_S7_21 & 1) == 0 )
  {
    _S7_21 |= 1u;
    RecvPropInt(
      result: RecvProps_127,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_127[1],
      pVarName: "m_flStamina",
      offset: 6824,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_127[2],
      pVarName: "m_iDirection",
      offset: 6828,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_127[3],
      pVarName: "m_iShotsFired",
      offset: 6832,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_127[4],
      pVarName: "m_flVelocityModifier",
      offset: 6840,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVectorXY(
      result: &RecvProps_127[5],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginXY);
    RecvPropFloat(
      result: &RecvProps_127[6],
      pVarName: "m_vecOrigin[2]",
      offset: 308,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    v3 = *RecvPropBool(result: &v1, pVarName: "m_bPlayerDominated[0]", offset: 7188, sizeofVar: 1);
    RecvPropArray3(
      result: &RecvProps_127[7],
      pVarName: "m_bPlayerDominated",
      offset: 7188,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropBool(result: &v1, pVarName: "m_bPlayerDominatingMe[0]", offset: 7253, sizeofVar: 1);
    RecvPropArray3(
      result: &RecvProps_127[8],
      pVarName: "m_bPlayerDominatingMe",
      offset: 7253,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_CSLocalPlayerExclusive::g_RecvTable,
    pProps: &RecvProps_127[1],
    nProps: 8,
    pNetTableName: "DT_CSLocalPlayerExclusive");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BBFC0
// Name: int ClientClassInit<struct DT_CSPlayer::ignored>(struct DT_CSPlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSPlayer::ignored>()
{
  if ( (_S9_6 & 1) == 0 )
  {
    _S9_6 |= 1u;
    RecvPropInt(
      result: RecvProps_128,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_128[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BasePlayer::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_128[2],
      pVarName: "cslocaldata",
      offset: 0,
      flags: 0,
      pTable: &DT_CSLocalPlayerExclusive::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_128[3],
      pVarName: "csnonlocaldata",
      offset: 0,
      flags: 0,
      pTable: &DT_CSNonLocalPlayerExclusive::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_128[4],
      pVarName: "m_iAddonBits",
      offset: 6804,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[5],
      pVarName: "m_iPrimaryAddon",
      offset: 6808,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[6],
      pVarName: "m_iSecondaryAddon",
      offset: 6812,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[7],
      pVarName: "m_iThrowGrenadeCounter",
      offset: 6796,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[8],
      pVarName: "m_iPlayerState",
      offset: 6772,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[9],
      pVarName: "m_iAccount",
      offset: 6924,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[10],
      pVarName: "m_bInBombZone",
      offset: 6792,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[11],
      pVarName: "m_bInBuyZone",
      offset: 6793,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_128[12], pVarName: "m_bKilledByTaser", offset: 6800, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_128[13],
      pVarName: "m_iClass",
      offset: 6932,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[14],
      pVarName: "m_ArmorValue",
      offset: 6936,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_128[15],
      pVarName: "m_angEyeAngles[0]",
      offset: 6940,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_128[16],
      pVarName: "m_angEyeAngles[1]",
      offset: 6944,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_128[17],
      pVarName: "m_flStamina",
      offset: 6824,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_128[18],
      pVarName: "m_bHasDefuser",
      offset: 6952,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_HasDefuser);
    RecvPropInt(
      result: &RecvProps_128[19],
      pVarName: "m_bNightVisionOn",
      offset: 6836,
      sizeofVar: 1,
      flags: 0,
      varProxy: RecvProxy_NightVision);
    RecvPropBool(result: &RecvProps_128[20], pVarName: "m_bHasNightVision", offset: 6837, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_128[21], pVarName: "m_bInHostageRescueZone", offset: 6953, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_128[22],
      pVarName: "m_ArmorValue",
      offset: 6936,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_128[23], pVarName: "m_bIsDefusing", offset: 6776, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_128[24], pVarName: "m_bResumeZoom", offset: 6764, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_128[25],
      pVarName: "m_iLastZoom",
      offset: 6768,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_128[26], pVarName: "m_bGunGameImmunity", offset: 6777, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_128[27],
      pVarName: "m_iGunGameProgressiveWeaponIndex",
      offset: 6780,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_128[28],
      pVarName: "m_iNumGunGameTRKillPoints",
      offset: 6784,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_128[29],
      pVarName: "m_fMolotovUseTime",
      offset: 6788,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_128[30],
      pVarName: "m_bHasHelmet",
      offset: 6928,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_128[31],
      pVarName: "m_vecRagdollVelocity",
      offset: 6964,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_128[32],
      pVarName: "m_flFlashDuration",
      offset: 6868,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_FlashTime);
    RecvPropFloat(
      result: &RecvProps_128[33],
      pVarName: "m_flFlashMaxAlpha",
      offset: 6864,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_128[34],
      pVarName: "m_iProgressBarDuration",
      offset: 6816,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_128[35],
      pVarName: "m_flProgressBarStartTime",
      offset: 6820,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropEHandle(
      result: &RecvProps_128[36],
      pVarName: "m_hRagdoll",
      offset: 6848,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_128[37],
      pVarName: "m_cycleLatch",
      offset: 7180,
      sizeofVar: 4,
      flags: 0,
      varProxy: C_CSPlayer::RecvProxy_CycleLatch);
    RecvPropBool(result: &RecvProps_128[38], pVarName: "m_bIsControllingBot", offset: 7340, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_128[39], pVarName: "m_bCanControlObservedBot", offset: 7341, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_128[40],
      pVarName: "m_iControlledBotEntIndex",
      offset: 7344,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_CSPlayer::g_RecvTable,
    pProps: &RecvProps_128[1],
    nProps: 40,
    pNetTableName: "DT_CSPlayer");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BE6B0
// Name: int ClientClassInit<struct DT_CSPlayerResource::ignored>(struct DT_CSPlayerResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSPlayerResource::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60
  RecvProp v6; // 0:^2C.60
  RecvProp v7; // 0:^2C.60
  RecvProp v8; // 0:^2C.60
  RecvProp v9; // 0:^2C.60
  RecvProp v10; // 0:^2C.60
  RecvProp v11; // 0:^2C.60
  RecvProp v12; // 0:^2C.60
  RecvProp v13; // 0:^2C.60
  RecvProp v14; // 0:^2C.60
  RecvProp v15; // 0:^2C.60
  RecvProp v16; // 0:^2C.60
  RecvProp v17; // 0:^2C.60
  RecvProp v18; // 0:^2C.60
  RecvProp v19; // 0:^2C.60
  RecvProp v20; // 0:^2C.60

  if ( (_S5_132 & 1) == 0 )
  {
    _S5_132 |= 1u;
    RecvPropInt(
      result: RecvProps_129,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_129[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_PlayerResource::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_129[2],
      pVarName: "m_iPlayerC4",
      offset: 4784,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_129[3],
      pVarName: "m_iPlayerDefuser",
      offset: 4788,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_129[4],
      pVarName: "m_iPlayerVIP",
      offset: 4792,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_129[5],
      pVarName: "m_vecC4",
      offset: 4796,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_129[6],
      pVarName: "m_vecDefuser",
      offset: 4808,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    v3 = *RecvPropInt(
            result: &v1,
            pVarName: "m_bHostageAlive[0]",
            offset: 4844,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[7],
      pVarName: "m_bHostageAlive",
      offset: 4844,
      sizeofVar: 1,
      elements: 12,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(
            result: &v1,
            pVarName: "m_isHostageFollowingSomeone[0]",
            offset: 4856,
            sizeofVar: 1,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[8],
      pVarName: "m_isHostageFollowingSomeone",
      offset: 4856,
      sizeofVar: 1,
      elements: 12,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropInt(
            result: &v1,
            pVarName: "m_iHostageEntityIDs[0]",
            offset: 4868,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[9],
      pVarName: "m_iHostageEntityIDs",
      offset: 4868,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v6 = *RecvPropInt(result: &v1, pVarName: "m_iHostageX[0]", offset: 4916, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[10],
      pVarName: "m_iHostageX",
      offset: 4916,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v6,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v7 = *RecvPropInt(result: &v1, pVarName: "m_iHostageY[0]", offset: 4964, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[11],
      pVarName: "m_iHostageY",
      offset: 4964,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v7,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v8 = *RecvPropInt(result: &v1, pVarName: "m_iHostageZ[0]", offset: 5012, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[12],
      pVarName: "m_iHostageZ",
      offset: 5012,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v8,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_129[13],
      pVarName: "m_bombsiteCenterA",
      offset: 4820,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_129[14],
      pVarName: "m_bombsiteCenterB",
      offset: 4832,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    v9 = *RecvPropInt(
            result: &v1,
            pVarName: "m_hostageRescueX[0]",
            offset: 5060,
            sizeofVar: 4,
            flags: 0,
            varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[15],
      pVarName: "m_hostageRescueX",
      offset: 5060,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v9,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v10 = *RecvPropInt(
             result: &v1,
             pVarName: "m_hostageRescueY[0]",
             offset: 5076,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[16],
      pVarName: "m_hostageRescueY",
      offset: 5076,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v10,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v11 = *RecvPropInt(
             result: &v1,
             pVarName: "m_hostageRescueZ[0]",
             offset: 5092,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[17],
      pVarName: "m_hostageRescueZ",
      offset: 5092,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v11,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_129[18],
      pVarName: "m_bBombSpotted",
      offset: 5108,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_129[19],
      pVarName: "m_bDefuserSpotted",
      offset: 5109,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    v12 = *RecvPropInt(
             result: &v1,
             pVarName: "m_bPlayerSpotted[0]",
             offset: 5110,
             sizeofVar: 1,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[20],
      pVarName: "m_bPlayerSpotted",
      offset: 5110,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v12,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v13 = *RecvPropInt(result: &v1, pVarName: "m_iMVPs[0]", offset: 5176, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[21],
      pVarName: "m_iMVPs",
      offset: 5176,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v13,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v14 = *RecvPropInt(result: &v1, pVarName: "m_iArmor[0]", offset: 5504, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[22],
      pVarName: "m_iArmor",
      offset: 5504,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v14,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v15 = *RecvPropInt(
             result: &v1,
             pVarName: "m_bHasDefuser[0]",
             offset: 5436,
             sizeofVar: 1,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[23],
      pVarName: "m_bHasDefuser",
      offset: 5436,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v15,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v16 = *RecvPropInt(result: &v1, pVarName: "m_iScore[0]", offset: 5764, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[24],
      pVarName: "m_iScore",
      offset: 5764,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v16,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v17 = *RecvPropInt(result: &v1, pVarName: "m_bVote[0]", offset: 6024, sizeofVar: 1, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[25],
      pVarName: "m_bVote",
      offset: 6024,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v17,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v18 = *RecvPropInt(
             result: &v1,
             pVarName: "m_bControllingBot[0]",
             offset: 6089,
             sizeofVar: 1,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[26],
      pVarName: "m_bControllingBot",
      offset: 6089,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v18,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v19 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iControlledPlayer[0]",
             offset: 6156,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[27],
      pVarName: "m_iControlledPlayer",
      offset: 6156,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v19,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v20 = *RecvPropInt(
             result: &v1,
             pVarName: "m_iControlledByPlayer[0]",
             offset: 6416,
             sizeofVar: 4,
             flags: 0,
             varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_129[28],
      pVarName: "m_iControlledByPlayer",
      offset: 6416,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v20,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_CSPlayerResource::g_RecvTable,
    pProps: &RecvProps_129[1],
    nProps: 28,
    pNetTableName: "DT_CSPlayerResource");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BF2D0
// Name: int ClientClassInit<struct DT_CSTeam::ignored>(struct DT_CSTeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSTeam::ignored>()
{
  if ( (_S5_133 & 1) == 0 )
  {
    _S5_133 |= 1u;
    RecvPropInt(
      result: RecvProps_130,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_130[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_Team::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(this: &DT_CSTeam::g_RecvTable, pProps: &RecvProps_130[1], nProps: 1, pNetTableName: "DT_CSTeam");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BF530
// Name: int ClientClassInit<struct DT_PlantedC4::ignored>(struct DT_PlantedC4::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PlantedC4::ignored>()
{
  if ( (_S5_134 & 1) == 0 )
  {
    _S5_134 |= 1u;
    RecvPropInt(
      result: RecvProps_131,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_131[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_131[2], pVarName: "m_bBombTicking", offset: 3256, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_131[3],
      pVarName: "m_flC4Blow",
      offset: 3268,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_131[4],
      pVarName: "m_flTimerLength",
      offset: 3272,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_131[5],
      pVarName: "m_flDefuseLength",
      offset: 3276,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_131[6],
      pVarName: "m_flDefuseCountDown",
      offset: 3280,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_PlantedC4::g_RecvTable,
    pProps: &RecvProps_131[1],
    nProps: 6,
    pNetTableName: "DT_PlantedC4");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BFE50
// Name: int ClientClassInit<struct DT_TERadioIcon::ignored>(struct DT_TERadioIcon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TERadioIcon::ignored>()
{
  if ( (_S5_135 & 1) == 0 )
  {
    _S5_135 |= 1u;
    RecvPropInt(
      result: RecvProps_132,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_132[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_132[2],
      pVarName: "m_iAttachToClient",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TERadioIcon::g_RecvTable,
    pProps: &RecvProps_132[1],
    nProps: 2,
    pNetTableName: "DT_TERadioIcon");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C0000
// Name: int ClientClassInit<struct DT_TEPlantBomb::ignored>(struct DT_TEPlantBomb::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEPlantBomb::ignored>()
{
  if ( (_S6_52 & 1) == 0 )
  {
    _S6_52 |= 1u;
    RecvPropInt(
      result: RecvProps_133,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_133[1],
      pVarName: "m_vecOrigin",
      offset: 20,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_133[2], pVarName: "m_iPlayer", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_133[3], pVarName: "m_option", offset: 32, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEPlantBomb::g_RecvTable,
    pProps: &RecvProps_133[1],
    nProps: 3,
    pNetTableName: "DT_TEPlantBomb");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C00D0
// Name: int ClientClassInit<struct DT_TEFireBullets::ignored>(struct DT_TEFireBullets::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEFireBullets::ignored>()
{
  if ( (_S5_136 & 1) == 0 )
  {
    _S5_136 |= 1u;
    RecvPropInt(
      result: RecvProps_134,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_134[1],
      pVarName: "m_vecOrigin",
      offset: 20,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_134[2],
      pVarName: "m_vecAngles[0]",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_134[3],
      pVarName: "m_vecAngles[1]",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_134[4],
      pVarName: "m_iWeaponID",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_134[5], pVarName: "m_iMode", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_134[6], pVarName: "m_iSeed", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_134[7], pVarName: "m_iPlayer", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_134[8],
      pVarName: "m_fInaccuracy",
      offset: 56,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_134[9],
      pVarName: "m_fSpread",
      offset: 60,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEFireBullets::g_RecvTable,
    pProps: &RecvProps_134[1],
    nProps: 9,
    pNetTableName: "DT_TEFireBullets");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C0320
// Name: int ClientClassInit<struct DT_WeaponCycler::ignored>(struct DT_WeaponCycler::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponCycler::ignored>()
{
  if ( (_S5_137 & 1) == 0 )
  {
    _S5_137 |= 1u;
    RecvPropInt(
      result: RecvProps_135,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_135[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatWeapon::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponCycler::g_RecvTable,
    pProps: &RecvProps_135[1],
    nProps: 1,
    pNetTableName: "DT_WeaponCycler");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C0470
// Name: int ClientClassInit<struct DT_WeaponCubemap::ignored>(struct DT_WeaponCubemap::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponCubemap::ignored>()
{
  if ( (_S6_53 & 1) == 0 )
  {
    _S6_53 |= 1u;
    RecvPropInt(
      result: RecvProps_136,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_136[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatWeapon::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponCubemap::g_RecvTable,
    pProps: &RecvProps_136[1],
    nProps: 1,
    pNetTableName: "DT_WeaponCubemap");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C5C80
// Name: int ClientClassInit<struct DT_CSGameRulesProxy::ignored>(struct DT_CSGameRulesProxy::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSGameRulesProxy::ignored>()
{
  if ( (_S6_54 & 1) == 0 )
  {
    _S6_54 |= 1u;
    RecvPropInt(
      result: RecvProps_137,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_137[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_GameRulesProxy::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_137[2],
      pVarName: "cs_gamerules_data",
      offset: 0,
      flags: 0,
      pTable: &DT_CSGameRules::g_RecvTable,
      varProxy: RecvProxy_CSGameRules);
  }
  RecvTable::Construct(
    this: &DT_CSGameRulesProxy::g_RecvTable,
    pProps: &RecvProps_137[1],
    nProps: 2,
    pNetTableName: "DT_CSGameRulesProxy");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6380
// Name: int ClientClassInit<struct DT_CSGameRules::ignored>(struct DT_CSGameRules::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_CSGameRules::ignored>()
{
  if ( (_S5_138 & 1) == 0 )
  {
    _S5_138 |= 1u;
    RecvPropInt(
      result: RecvProps_138,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_138[1], pVarName: "m_bFreezePeriod", offset: 32, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_138[2],
      pVarName: "m_iRoundTime",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_138[3],
      pVarName: "m_fRoundStartTime",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_138[4],
      pVarName: "m_flGameStartTime",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_138[5],
      pVarName: "m_iHostagesRemaining",
      offset: 48,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_138[6], pVarName: "m_bMapHasBombTarget", offset: 52, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_138[7], pVarName: "m_bMapHasRescueZone", offset: 53, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_138[8], pVarName: "m_bLogoMap", offset: 54, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_138[9], pVarName: "m_bBlackMarket", offset: 55, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_138[10],
      pVarName: "m_iGunGameTRBombCTScore",
      offset: 60,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[11],
      pVarName: "m_iGunGameTRBombTScore",
      offset: 56,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropBool(result: &RecvProps_138[12], pVarName: "m_bGunGameTRBombModeHalftime", offset: 64, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_138[13],
      pVarName: "m_iNumGunGameProgressiveWeaponsCT",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[14],
      pVarName: "m_iNumGunGameProgressiveWeaponsT",
      offset: 72,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[15],
      pVarName: "m_iSpectatorSlotCount",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[16],
      pVarName: "m_GGProgressiveWeaponOrderCT[0]",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    InternalRecvPropArray(
      result: &RecvProps_138[17],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponOrderCT",
      proxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[18],
      pVarName: "m_GGProgressiveWeaponOrderT[0]",
      offset: 320,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    InternalRecvPropArray(
      result: &RecvProps_138[19],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponOrderT",
      proxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[20],
      pVarName: "m_GGProgressiveWeaponKillUpgradeOrderCT[0]",
      offset: 560,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    InternalRecvPropArray(
      result: &RecvProps_138[21],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponKillUpgradeOrderCT",
      proxy: nullptr);
    RecvPropInt(
      result: &RecvProps_138[22],
      pVarName: "m_GGProgressiveWeaponKillUpgradeOrderT[0]",
      offset: 800,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    InternalRecvPropArray(
      result: &RecvProps_138[23],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponKillUpgradeOrderT",
      proxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_CSGameRules::g_RecvTable,
    pProps: &RecvProps_138[1],
    nProps: 23,
    pNetTableName: "DT_CSGameRules");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6FC0
// Name: int ClientClassInit<struct DT_FootstepControl::ignored>(struct DT_FootstepControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FootstepControl::ignored>()
{
  if ( (_S5_139 & 1) == 0 )
  {
    _S5_139 |= 1u;
    RecvPropInt(
      result: RecvProps_139,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_139[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTrigger::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropString(
      result: &RecvProps_139[2],
      pVarName: "m_source",
      offset: 2488,
      bufferSize: 16,
      flags: 0,
      varProxy: RecvProxy_StringToString);
    RecvPropString(
      result: &RecvProps_139[3],
      pVarName: "m_destination",
      offset: 2504,
      bufferSize: 16,
      flags: 0,
      varProxy: RecvProxy_StringToString);
  }
  RecvTable::Construct(
    this: &DT_FootstepControl::g_RecvTable,
    pProps: &RecvProps_139[1],
    nProps: 3,
    pNetTableName: "DT_FootstepControl");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CEB70
// Name: int ClientClassInit<struct DT_Inferno::ignored>(struct DT_Inferno::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Inferno::ignored>()
{
  RecvProp v1; // [esp+8h] [ebp-3Ch] BYREF
  RecvProp v3; // 0:^2C.60
  RecvProp v4; // 0:^2C.60
  RecvProp v5; // 0:^2C.60

  if ( (_S5_142 & 1) == 0 )
  {
    _S5_142 |= 1u;
    RecvPropInt(
      result: RecvProps_140,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_140[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v3 = *RecvPropInt(result: &v1, pVarName: "m_fireXDelta[0]", offset: 2444, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_140[2],
      pVarName: "m_fireXDelta",
      offset: 2444,
      sizeofVar: 4,
      elements: 100,
      pArrayProp: v3,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v4 = *RecvPropInt(result: &v1, pVarName: "m_fireYDelta[0]", offset: 2844, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_140[3],
      pVarName: "m_fireYDelta",
      offset: 2844,
      sizeofVar: 4,
      elements: 100,
      pArrayProp: v4,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    v5 = *RecvPropInt(result: &v1, pVarName: "m_fireZDelta[0]", offset: 3244, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropArray3(
      result: &RecvProps_140[4],
      pVarName: "m_fireZDelta",
      offset: 3244,
      sizeofVar: 4,
      elements: 100,
      pArrayProp: v5,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_140[5],
      pVarName: "m_fireCount",
      offset: 5244,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_Inferno::g_RecvTable,
    pProps: &RecvProps_140[1],
    nProps: 5,
    pNetTableName: "DT_Inferno");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CECF0
// Name: int ClientClassInit<struct DT_FireCrackerBlast::ignored>(struct DT_FireCrackerBlast::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FireCrackerBlast::ignored>()
{
  if ( (_S7_23 & 1) == 0 )
  {
    _S7_23 |= 1u;
    RecvPropInt(
      result: RecvProps_141,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_141[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_Inferno::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_FireCrackerBlast::g_RecvTable,
    pProps: &RecvProps_141[1],
    nProps: 1,
    pNetTableName: "DT_FireCrackerBlast");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102284E0
// Name: int ClientClassInit<struct DT_DecoyProjectile::ignored>(struct DT_DecoyProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DecoyProjectile::ignored>()
{
  if ( (_S5_146 & 1) == 0 )
  {
    _S5_146 |= 1u;
    RecvPropInt(
      result: RecvProps_142,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_142[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenadeProjectile::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_DecoyProjectile::g_RecvTable,
    pProps: &RecvProps_142[1],
    nProps: 1,
    pNetTableName: "DT_DecoyProjectile");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102287A0
// Name: int ClientClassInit<struct DT_MolotovProjectile::ignored>(struct DT_MolotovProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_MolotovProjectile::ignored>()
{
  if ( (_S5_147 & 1) == 0 )
  {
    _S5_147 |= 1u;
    RecvPropInt(
      result: RecvProps_143,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_143[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenadeProjectile::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_MolotovProjectile::g_RecvTable,
    pProps: &RecvProps_143[1],
    nProps: 1,
    pNetTableName: "DT_MolotovProjectile");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102289D0
// Name: int ClientClassInit<struct DT_WeaponAK47::ignored>(struct DT_WeaponAK47::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponAK47::ignored>()
{
  if ( (_S5_148 & 1) == 0 )
  {
    _S5_148 |= 1u;
    RecvPropInt(
      result: RecvProps_144,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_144[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponAK47::g_RecvTable,
    pProps: &RecvProps_144[1],
    nProps: 1,
    pNetTableName: "DT_WeaponAK47");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10228E00
// Name: int ClientClassInit<struct DT_WeaponAug::ignored>(struct DT_WeaponAug::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponAug::ignored>()
{
  if ( (_S5_149 & 1) == 0 )
  {
    _S5_149 |= 1u;
    RecvPropInt(
      result: RecvProps_145,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_145[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponAug::g_RecvTable,
    pProps: &RecvProps_145[1],
    nProps: 1,
    pNetTableName: "DT_WeaponAug");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102292D0
// Name: int ClientClassInit<struct DT_WeaponAWP::ignored>(struct DT_WeaponAWP::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponAWP::ignored>()
{
  if ( (_S5_150 & 1) == 0 )
  {
    _S5_150 |= 1u;
    RecvPropInt(
      result: RecvProps_146,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_146[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponAWP::g_RecvTable,
    pProps: &RecvProps_146[1],
    nProps: 1,
    pNetTableName: "DT_WeaponAWP");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10229790
// Name: int ClientClassInit<struct DT_BaseCSGrenade::ignored>(struct DT_BaseCSGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseCSGrenade::ignored>()
{
  if ( (_S5_151 & 1) == 0 )
  {
    _S5_151 |= 1u;
    RecvPropInt(
      result: RecvProps_147,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_147[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_147[2], pVarName: "m_bRedraw", offset: 3504, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_147[3], pVarName: "m_bPinPulled", offset: 3505, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_147[4],
      pVarName: "m_fThrowTime",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_147[5], pVarName: "m_bLoopingSoundPlaying", offset: 3512, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_BaseCSGrenade::g_RecvTable,
    pProps: &RecvProps_147[1],
    nProps: 5,
    pNetTableName: "DT_BaseCSGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10229E20
// Name: int ClientClassInit<struct DT_WeaponBizon::ignored>(struct DT_WeaponBizon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponBizon::ignored>()
{
  if ( (_S5_152 & 1) == 0 )
  {
    _S5_152 |= 1u;
    RecvPropInt(
      result: RecvProps_148,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_148[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponBizon::g_RecvTable,
    pProps: &RecvProps_148[1],
    nProps: 1,
    pNetTableName: "DT_WeaponBizon");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022A000
// Name: int ClientClassInit<struct DT_WeaponC4::ignored>(struct DT_WeaponC4::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponC4::ignored>()
{
  if ( (_S5_153 & 1) == 0 )
  {
    _S5_153 |= 1u;
    RecvPropInt(
      result: RecvProps_149,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_149[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_149[2], pVarName: "m_bStartedArming", offset: 3536, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_149[3], pVarName: "m_bBombPlacedAnimation", offset: 3544, sizeofVar: 1);
    RecvPropFloat(
      result: &RecvProps_149[4],
      pVarName: "m_fArmedTime",
      offset: 3540,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_WeaponC4::g_RecvTable,
    pProps: &RecvProps_149[1],
    nProps: 4,
    pNetTableName: "DT_WeaponC4");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022A990
// Name: int ClientClassInit<struct DT_WeaponCSBase::ignored>(struct DT_WeaponCSBase::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponCSBase::ignored>()
{
  if ( (_S5_154 & 1) == 0 )
  {
    _S5_154 |= 1u;
    RecvPropInt(
      result: RecvProps_150,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_150[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatWeapon::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_150[2],
      pVarName: "m_weaponMode",
      offset: 3436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_150[3],
      pVarName: "m_fAccuracyPenalty",
      offset: 3440,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_150[4],
      pVarName: "m_bWaitForNoAttack",
      offset: 3485,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponCSBase::g_RecvTable,
    pProps: &RecvProps_150[1],
    nProps: 4,
    pNetTableName: "DT_WeaponCSBase");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D460
// Name: int ClientClassInit<struct DT_WeaponCSBaseGun::ignored>(struct DT_WeaponCSBaseGun::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponCSBaseGun::ignored>()
{
  if ( (_S5_155 & 1) == 0 )
  {
    _S5_155 |= 1u;
    RecvPropInt(
      result: RecvProps_151,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_151[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponCSBaseGun::g_RecvTable,
    pProps: &RecvProps_151[1],
    nProps: 1,
    pNetTableName: "DT_WeaponCSBaseGun");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022DAA0
// Name: int ClientClassInit<struct DT_WeaponDEagle::ignored>(struct DT_WeaponDEagle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponDEagle::ignored>()
{
  if ( (_S5_156 & 1) == 0 )
  {
    _S5_156 |= 1u;
    RecvPropInt(
      result: RecvProps_152,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_152[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponDEagle::g_RecvTable,
    pProps: &RecvProps_152[1],
    nProps: 1,
    pNetTableName: "DT_WeaponDEagle");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022DC50
// Name: int ClientClassInit<struct DT_DecoyGrenade::ignored>(struct DT_DecoyGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DecoyGrenade::ignored>()
{
  if ( (_S5_157 & 1) == 0 )
  {
    _S5_157 |= 1u;
    RecvPropInt(
      result: RecvProps_153,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_153[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_DecoyGrenade::g_RecvTable,
    pProps: &RecvProps_153[1],
    nProps: 1,
    pNetTableName: "DT_DecoyGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022DDE0
// Name: int ClientClassInit<struct DT_WeaponElite::ignored>(struct DT_WeaponElite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponElite::ignored>()
{
  if ( (_S5_158 & 1) == 0 )
  {
    _S5_158 |= 1u;
    RecvPropInt(
      result: RecvProps_154,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_154[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponElite::g_RecvTable,
    pProps: &RecvProps_154[1],
    nProps: 1,
    pNetTableName: "DT_WeaponElite");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022E200
// Name: int ClientClassInit<struct DT_WeaponFamas::ignored>(struct DT_WeaponFamas::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponFamas::ignored>()
{
  if ( (_S5_159 & 1) == 0 )
  {
    _S5_159 |= 1u;
    RecvPropInt(
      result: RecvProps_155,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_155[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_155[2], pVarName: "m_bBurstMode", offset: 3504, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_155[3],
      pVarName: "m_iBurstShotsRemaining",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponFamas::g_RecvTable,
    pProps: &RecvProps_155[1],
    nProps: 3,
    pNetTableName: "DT_WeaponFamas");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022E9F0
// Name: int ClientClassInit<struct DT_WeaponFiveSeven::ignored>(struct DT_WeaponFiveSeven::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponFiveSeven::ignored>()
{
  if ( (_S5_160 & 1) == 0 )
  {
    _S5_160 |= 1u;
    RecvPropInt(
      result: RecvProps_156,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_156[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponFiveSeven::g_RecvTable,
    pProps: &RecvProps_156[1],
    nProps: 1,
    pNetTableName: "DT_WeaponFiveSeven");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022EC00
// Name: int ClientClassInit<struct DT_Flashbang::ignored>(struct DT_Flashbang::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Flashbang::ignored>()
{
  if ( (_S5_161 & 1) == 0 )
  {
    _S5_161 |= 1u;
    RecvPropInt(
      result: RecvProps_157,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_157[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_Flashbang::g_RecvTable,
    pProps: &RecvProps_157[1],
    nProps: 1,
    pNetTableName: "DT_Flashbang");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022ED90
// Name: int ClientClassInit<struct DT_WeaponG3SG1::ignored>(struct DT_WeaponG3SG1::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponG3SG1::ignored>()
{
  if ( (_S5_162 & 1) == 0 )
  {
    _S5_162 |= 1u;
    RecvPropInt(
      result: RecvProps_158,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_158[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponG3SG1::g_RecvTable,
    pProps: &RecvProps_158[1],
    nProps: 1,
    pNetTableName: "DT_WeaponG3SG1");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022F1F0
// Name: int ClientClassInit<struct DT_WeaponGalil::ignored>(struct DT_WeaponGalil::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponGalil::ignored>()
{
  if ( (_S5_163 & 1) == 0 )
  {
    _S5_163 |= 1u;
    RecvPropInt(
      result: RecvProps_159,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_159[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponGalil::g_RecvTable,
    pProps: &RecvProps_159[1],
    nProps: 1,
    pNetTableName: "DT_WeaponGalil");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022F630
// Name: int ClientClassInit<struct DT_WeaponGlock::ignored>(struct DT_WeaponGlock::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponGlock::ignored>()
{
  if ( (_S5_164 & 1) == 0 )
  {
    _S5_164 |= 1u;
    RecvPropInt(
      result: RecvProps_160,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_160[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_160[2], pVarName: "m_bBurstMode", offset: 3504, sizeofVar: 1);
    RecvPropInt(
      result: &RecvProps_160[3],
      pVarName: "m_iBurstShotsRemaining",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponGlock::g_RecvTable,
    pProps: &RecvProps_160[1],
    nProps: 3,
    pNetTableName: "DT_WeaponGlock");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022FC30
// Name: int ClientClassInit<struct DT_HEGrenade::ignored>(struct DT_HEGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_HEGrenade::ignored>()
{
  if ( (_S5_165 & 1) == 0 )
  {
    _S5_165 |= 1u;
    RecvPropInt(
      result: RecvProps_161,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_161[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_HEGrenade::g_RecvTable,
    pProps: &RecvProps_161[1],
    nProps: 1,
    pNetTableName: "DT_HEGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022FDC0
// Name: int ClientClassInit<struct DT_WeaponHKP2000::ignored>(struct DT_WeaponHKP2000::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponHKP2000::ignored>()
{
  if ( (_S5_166 & 1) == 0 )
  {
    _S5_166 |= 1u;
    RecvPropInt(
      result: RecvProps_162,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_162[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponHKP2000::g_RecvTable,
    pProps: &RecvProps_162[1],
    nProps: 1,
    pNetTableName: "DT_WeaponHKP2000");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022FFF0
// Name: int ClientClassInit<struct DT_LocalActiveWeaponKnifeData::ignored>(struct DT_LocalActiveWeaponKnifeData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_LocalActiveWeaponKnifeData::ignored>()
{
  if ( (_S5_167 & 1) == 0 )
  {
    _S5_167 |= 1u;
    RecvPropInt(
      result: RecvProps_163,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropTime(result: &RecvProps_163[1], pVarName: "m_flSmackTime", offset: 3592, sizeofVar: 4);
  }
  RecvTable::Construct(
    this: &DT_LocalActiveWeaponKnifeData::g_RecvTable,
    pProps: &RecvProps_163[1],
    nProps: 1,
    pNetTableName: "DT_LocalActiveWeaponKnifeData");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10230050
// Name: int ClientClassInit<struct DT_WeaponKnife::ignored>(struct DT_WeaponKnife::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponKnife::ignored>()
{
  if ( (_S6_55 & 1) == 0 )
  {
    _S6_55 |= 1u;
    RecvPropInt(
      result: RecvProps_164,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_164[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_164[2],
      pVarName: "LocalActiveWeaponKnifeData",
      offset: 0,
      flags: 0,
      pTable: &DT_LocalActiveWeaponKnifeData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponKnife::g_RecvTable,
    pProps: &RecvProps_164[1],
    nProps: 2,
    pNetTableName: "DT_WeaponKnife");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10230EE0
// Name: int ClientClassInit<struct DT_WeaponM249::ignored>(struct DT_WeaponM249::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponM249::ignored>()
{
  if ( (_S5_168 & 1) == 0 )
  {
    _S5_168 |= 1u;
    RecvPropInt(
      result: RecvProps_165,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_165[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponM249::g_RecvTable,
    pProps: &RecvProps_165[1],
    nProps: 1,
    pNetTableName: "DT_WeaponM249");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102312D0
// Name: int ClientClassInit<struct DT_WeaponM4A1::ignored>(struct DT_WeaponM4A1::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponM4A1::ignored>()
{
  if ( (_S5_169 & 1) == 0 )
  {
    _S5_169 |= 1u;
    RecvPropInt(
      result: RecvProps_166,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_166[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropBool(result: &RecvProps_166[2], pVarName: "m_bSilencerOn", offset: 3504, sizeofVar: 1);
    RecvPropTime(result: &RecvProps_166[3], pVarName: "m_flDoneSwitchingSilencer", offset: 3508, sizeofVar: 4);
  }
  RecvTable::Construct(
    this: &DT_WeaponM4A1::g_RecvTable,
    pProps: &RecvProps_166[1],
    nProps: 3,
    pNetTableName: "DT_WeaponM4A1");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10231C10
// Name: int ClientClassInit<struct DT_WeaponMAC10::ignored>(struct DT_WeaponMAC10::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponMAC10::ignored>()
{
  if ( (_S5_170 & 1) == 0 )
  {
    _S5_170 |= 1u;
    RecvPropInt(
      result: RecvProps_167,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_167[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponMAC10::g_RecvTable,
    pProps: &RecvProps_167[1],
    nProps: 1,
    pNetTableName: "DT_WeaponMAC10");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10232010
// Name: int ClientClassInit<struct DT_WeaponMag7::ignored>(struct DT_WeaponMag7::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponMag7::ignored>()
{
  if ( (_S5_171 & 1) == 0 )
  {
    _S5_171 |= 1u;
    RecvPropInt(
      result: RecvProps_168,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_168[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponMag7::g_RecvTable,
    pProps: &RecvProps_168[1],
    nProps: 1,
    pNetTableName: "DT_WeaponMag7");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102321A0
// Name: int ClientClassInit<struct DT_MolotovGrenade::ignored>(struct DT_MolotovGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_MolotovGrenade::ignored>()
{
  if ( (_S5_172 & 1) == 0 )
  {
    _S5_172 |= 1u;
    RecvPropInt(
      result: RecvProps_169,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_169[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_MolotovGrenade::g_RecvTable,
    pProps: &RecvProps_169[1],
    nProps: 1,
    pNetTableName: "DT_MolotovGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102326A0
// Name: int ClientClassInit<struct DT_WeaponMP7::ignored>(struct DT_WeaponMP7::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponMP7::ignored>()
{
  if ( (_S5_173 & 1) == 0 )
  {
    _S5_173 |= 1u;
    RecvPropInt(
      result: RecvProps_170,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_170[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponMP7::g_RecvTable,
    pProps: &RecvProps_170[1],
    nProps: 1,
    pNetTableName: "DT_WeaponMP7");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10232AC0
// Name: int ClientClassInit<struct DT_WeaponMP9::ignored>(struct DT_WeaponMP9::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponMP9::ignored>()
{
  if ( (_S5_174 & 1) == 0 )
  {
    _S5_174 |= 1u;
    RecvPropInt(
      result: RecvProps_171,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_171[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponMP9::g_RecvTable,
    pProps: &RecvProps_171[1],
    nProps: 1,
    pNetTableName: "DT_WeaponMP9");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10232EC0
// Name: int ClientClassInit<struct DT_WeaponNegev::ignored>(struct DT_WeaponNegev::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponNegev::ignored>()
{
  if ( (_S5_175 & 1) == 0 )
  {
    _S5_175 |= 1u;
    RecvPropInt(
      result: RecvProps_172,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_172[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponNegev::g_RecvTable,
    pProps: &RecvProps_172[1],
    nProps: 1,
    pNetTableName: "DT_WeaponNegev");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233050
// Name: int ClientClassInit<struct DT_WeaponNOVA::ignored>(struct DT_WeaponNOVA::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponNOVA::ignored>()
{
  if ( (_S5_176 & 1) == 0 )
  {
    _S5_176 |= 1u;
    RecvPropInt(
      result: RecvProps_173,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_173[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_173[2],
      pVarName: "m_reloadState",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponNOVA::g_RecvTable,
    pProps: &RecvProps_173[1],
    nProps: 2,
    pNetTableName: "DT_WeaponNOVA");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233580
// Name: int ClientClassInit<struct DT_WeaponP250::ignored>(struct DT_WeaponP250::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponP250::ignored>()
{
  if ( (_S5_177 & 1) == 0 )
  {
    _S5_177 |= 1u;
    RecvPropInt(
      result: RecvProps_174,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_174[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponP250::g_RecvTable,
    pProps: &RecvProps_174[1],
    nProps: 1,
    pNetTableName: "DT_WeaponP250");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233710
// Name: int ClientClassInit<struct DT_WeaponP90::ignored>(struct DT_WeaponP90::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponP90::ignored>()
{
  if ( (_S5_178 & 1) == 0 )
  {
    _S5_178 |= 1u;
    RecvPropInt(
      result: RecvProps_175,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_175[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponP90::g_RecvTable,
    pProps: &RecvProps_175[1],
    nProps: 1,
    pNetTableName: "DT_WeaponP90");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233AE0
// Name: int ClientClassInit<struct DT_WeaponSawedoff::ignored>(struct DT_WeaponSawedoff::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponSawedoff::ignored>()
{
  if ( (_S5_179 & 1) == 0 )
  {
    _S5_179 |= 1u;
    RecvPropInt(
      result: RecvProps_176,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_176[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_176[2],
      pVarName: "m_reloadState",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponSawedoff::g_RecvTable,
    pProps: &RecvProps_176[1],
    nProps: 2,
    pNetTableName: "DT_WeaponSawedoff");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10234300
// Name: int ClientClassInit<struct DT_WeaponSCAR20::ignored>(struct DT_WeaponSCAR20::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponSCAR20::ignored>()
{
  if ( (_S5_180 & 1) == 0 )
  {
    _S5_180 |= 1u;
    RecvPropInt(
      result: RecvProps_177,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_177[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponSCAR20::g_RecvTable,
    pProps: &RecvProps_177[1],
    nProps: 1,
    pNetTableName: "DT_WeaponSCAR20");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10234590
// Name: int ClientClassInit<struct DT_WeaponSG556::ignored>(struct DT_WeaponSG556::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponSG556::ignored>()
{
  if ( (_S5_181 & 1) == 0 )
  {
    _S5_181 |= 1u;
    RecvPropInt(
      result: RecvProps_178,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_178[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponSG556::g_RecvTable,
    pProps: &RecvProps_178[1],
    nProps: 1,
    pNetTableName: "DT_WeaponSG556");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10234B30
// Name: int ClientClassInit<struct DT_SmokeGrenade::ignored>(struct DT_SmokeGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SmokeGrenade::ignored>()
{
  if ( (_S5_182 & 1) == 0 )
  {
    _S5_182 |= 1u;
    RecvPropInt(
      result: RecvProps_179,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_179[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCSGrenade::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_SmokeGrenade::g_RecvTable,
    pProps: &RecvProps_179[1],
    nProps: 1,
    pNetTableName: "DT_SmokeGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10234CC0
// Name: int ClientClassInit<struct DT_WeaponSSG08::ignored>(struct DT_WeaponSSG08::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponSSG08::ignored>()
{
  if ( (_S5_183 & 1) == 0 )
  {
    _S5_183 |= 1u;
    RecvPropInt(
      result: RecvProps_180,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_180[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponSSG08::g_RecvTable,
    pProps: &RecvProps_180[1],
    nProps: 1,
    pNetTableName: "DT_WeaponSSG08");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10235000
// Name: int ClientClassInit<struct DT_WeaponTaser::ignored>(struct DT_WeaponTaser::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponTaser::ignored>()
{
  if ( (_S5_184 & 1) == 0 )
  {
    _S5_184 |= 1u;
    RecvPropInt(
      result: RecvProps_181,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_181[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponTaser::g_RecvTable,
    pProps: &RecvProps_181[1],
    nProps: 1,
    pNetTableName: "DT_WeaponTaser");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102351D0
// Name: int ClientClassInit<struct DT_WeaponTec9::ignored>(struct DT_WeaponTec9::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponTec9::ignored>()
{
  if ( (_S5_185 & 1) == 0 )
  {
    _S5_185 |= 1u;
    RecvPropInt(
      result: RecvProps_182,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_182[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponTec9::g_RecvTable,
    pProps: &RecvProps_182[1],
    nProps: 1,
    pNetTableName: "DT_WeaponTec9");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10235360
// Name: int ClientClassInit<struct DT_WeaponUMP45::ignored>(struct DT_WeaponUMP45::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponUMP45::ignored>()
{
  if ( (_S5_186 & 1) == 0 )
  {
    _S5_186 |= 1u;
    RecvPropInt(
      result: RecvProps_183,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_183[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBaseGun::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_WeaponUMP45::g_RecvTable,
    pProps: &RecvProps_183[1],
    nProps: 1,
    pNetTableName: "DT_WeaponUMP45");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10235750
// Name: int ClientClassInit<struct DT_WeaponXM1014::ignored>(struct DT_WeaponXM1014::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_WeaponXM1014::ignored>()
{
  if ( (_S5_187 & 1) == 0 )
  {
    _S5_187 |= 1u;
    RecvPropInt(
      result: RecvProps_184,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_184[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_WeaponCSBase::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_184[2],
      pVarName: "m_reloadState",
      offset: 3508,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_WeaponXM1014::g_RecvTable,
    pProps: &RecvProps_184[1],
    nProps: 2,
    pNetTableName: "DT_WeaponXM1014");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023D960
// Name: int ClientClassInit<struct DT_NextBot::ignored>(struct DT_NextBot::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_NextBot::ignored>()
{
  if ( (_S6_56 & 1) == 0 )
  {
    _S6_56 |= 1u;
    RecvPropInt(
      result: RecvProps_185,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_185[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseCombatCharacter::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_NextBot::g_RecvTable,
    pProps: &RecvProps_185[1],
    nProps: 1,
    pNetTableName: "DT_NextBot");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E030
// Name: int ClientClassInit<struct DT_PrecipitationBlocker::ignored>(struct DT_PrecipitationBlocker::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PrecipitationBlocker::ignored>()
{
  if ( (_S6_57 & 1) == 0 )
  {
    _S6_57 |= 1u;
    RecvPropInt(
      result: (RecvProp *)&_S5_188.m_Flags,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &stru_1066CE7C,
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_PrecipitationBlocker::g_RecvTable,
    pProps: &stru_1066CE7C,
    nProps: 1,
    pNetTableName: "DT_PrecipitationBlocker");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E0B0
// Name: int ClientClassInit<struct DT_Precipitation::ignored>(struct DT_Precipitation::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Precipitation::ignored>()
{
  if ( (_S7_25 & 1) == 0 )
  {
    _S7_25 |= 1u;
    RecvPropInt(
      result: RecvProps_187,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_187[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_187[2],
      pVarName: "m_nPrecipType",
      offset: 2472,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_Precipitation::g_RecvTable,
    pProps: &RecvProps_187[1],
    nProps: 2,
    pNetTableName: "DT_Precipitation");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E260
// Name: int ClientClassInit<struct DT_EnvWindShared::ignored>(struct DT_EnvWindShared::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvWindShared::ignored>()
{
  if ( (_S8_15 & 1) == 0 )
  {
    _S8_15 |= 1u;
    RecvPropInt(
      result: RecvProps_188,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[1],
      pVarName: "m_iMinWind",
      offset: 12,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[2],
      pVarName: "m_iMaxWind",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[3],
      pVarName: "m_iMinGust",
      offset: 24,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[4],
      pVarName: "m_iMaxGust",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_188[5],
      pVarName: "m_flMinGustDelay",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_188[6],
      pVarName: "m_flMaxGustDelay",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_188[7],
      pVarName: "m_iGustDirChange",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[8],
      pVarName: "m_iWindSeed",
      offset: 8,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_188[9],
      pVarName: "m_iInitialWindDir",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_188[10],
      pVarName: "m_flInitialWindSpeed",
      offset: 112,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_188[11],
      pVarName: "m_flStartTime",
      offset: 4,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_188[12],
      pVarName: "m_flGustDuration",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_EnvWindShared::g_RecvTable,
    pProps: &RecvProps_188[1],
    nProps: 12,
    pNetTableName: "DT_EnvWindShared");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E3F0
// Name: int ClientClassInit<struct DT_EnvWind::ignored>(struct DT_EnvWind::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_EnvWind::ignored>()
{
  if ( (_S9_7 & 1) == 0 )
  {
    _S9_7 |= 1u;
    RecvPropInt(
      result: RecvProps_189,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_189[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_189[2],
      pVarName: "m_EnvWindShared",
      offset: 2432,
      flags: 0,
      pTable: &DT_EnvWindShared::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_EnvWind::g_RecvTable,
    pProps: &RecvProps_189[1],
    nProps: 2,
    pNetTableName: "DT_EnvWind");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E4E0
// Name: int ClientClassInit<struct DT_Embers::ignored>(struct DT_Embers::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_Embers::ignored>()
{
  if ( (_S10_4 & 1) == 0 )
  {
    _S10_4 |= 1u;
    RecvPropInt(
      result: RecvProps_190,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_190[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_190[2],
      pVarName: "m_nDensity",
      offset: 2432,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_190[3],
      pVarName: "m_nLifetime",
      offset: 2436,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_190[4],
      pVarName: "m_nSpeed",
      offset: 2440,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_190[5], pVarName: "m_bEmit", offset: 2444, sizeofVar: 1, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(this: &DT_Embers::g_RecvTable, pProps: &RecvProps_190[1], nProps: 5, pNetTableName: "DT_Embers");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E5D0
// Name: int ClientClassInit<struct DT_QuadraticBeam::ignored>(struct DT_QuadraticBeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_QuadraticBeam::ignored>()
{
  if ( (_S11_0 & 1) == 0 )
  {
    _S11_0 |= 1u;
    RecvPropInt(
      result: RecvProps_191,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_191[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_191[2],
      pVarName: "m_targetPosition",
      offset: 2432,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_191[3],
      pVarName: "m_controlPosition",
      offset: 2444,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_191[4],
      pVarName: "m_scrollRate",
      offset: 2456,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_191[5],
      pVarName: "m_flWidth",
      offset: 2460,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_QuadraticBeam::g_RecvTable,
    pProps: &RecvProps_191[1],
    nProps: 5,
    pNetTableName: "DT_QuadraticBeam");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10244620
// Name: int ClientClassInit<struct DT_TEGaussExplosion::ignored>(struct DT_TEGaussExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEGaussExplosion::ignored>()
{
  if ( (_S5_189 & 1) == 0 )
  {
    _S5_189 |= 1u;
    RecvPropInt(
      result: RecvProps_192,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_192[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_192[2], pVarName: "m_nType", offset: 28, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_192[3],
      pVarName: "m_vecDirection",
      offset: 32,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TEGaussExplosion::g_RecvTable,
    pProps: &RecvProps_192[1],
    nProps: 3,
    pNetTableName: "DT_TEGaussExplosion");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10245AD0
// Name: int ClientClassInit<struct DT_MovieExplosion::ignored>(struct DT_MovieExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_MovieExplosion::ignored>()
{
  if ( (_S5_190 & 1) == 0 )
  {
    _S5_190 |= 1u;
    RecvPropInt(
      result: RecvProps_193,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_193[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_MovieExplosion::g_RecvTable,
    pProps: &RecvProps_193[1],
    nProps: 1,
    pNetTableName: "DT_MovieExplosion");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102462A0
// Name: int ClientClassInit<struct DT_ParticleFire::ignored>(struct DT_ParticleFire::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ParticleFire::ignored>()
{
  if ( (_S5_191 & 1) == 0 )
  {
    _S5_191 |= 1u;
    RecvPropInt(
      result: RecvProps_194,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_194[1],
      pVarName: "m_vOrigin",
      offset: 2676,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_194[2],
      pVarName: "m_vDirection",
      offset: 2688,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_ParticleFire::g_RecvTable,
    pProps: &RecvProps_194[1],
    nProps: 2,
    pNetTableName: "DT_ParticleFire");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10248BB0
// Name: int ClientClassInit<struct DT_ParticleSmokeGrenade::ignored>(struct DT_ParticleSmokeGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_ParticleSmokeGrenade::ignored>()
{
  if ( (_S5_192 & 1) == 0 )
  {
    _S5_192 |= 1u;
    RecvPropInt(
      result: RecvProps_195,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_195[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropTime(result: &RecvProps_195[2], pVarName: "m_flSpawnTime", offset: 2684, sizeofVar: 4);
    RecvPropFloat(
      result: &RecvProps_195[3],
      pVarName: "m_FadeStartTime",
      offset: 2688,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_195[4],
      pVarName: "m_FadeEndTime",
      offset: 2692,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_195[5],
      pVarName: "m_MinColor",
      offset: 2700,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_195[6],
      pVarName: "m_MaxColor",
      offset: 2712,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_195[7],
      pVarName: "m_CurrentStage",
      offset: 2668,
      sizeofVar: 1,
      flags: 0,
      varProxy: C_ParticleSmokeGrenade::RecvProxy_CurrentStage);
  }
  RecvTable::Construct(
    this: &DT_ParticleSmokeGrenade::g_RecvTable,
    pProps: &RecvProps_195[1],
    nProps: 7,
    pNetTableName: "DT_ParticleSmokeGrenade");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10248EF0
// Name: int ClientClassInit<struct DT_PropVehicleDriveable::ignored>(struct DT_PropVehicleDriveable::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_PropVehicleDriveable::ignored>()
{
  if ( (_S5_193 & 1) == 0 )
  {
    _S5_193 |= 1u;
    RecvPropInt(
      result: RecvProps_196,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_196[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseAnimating::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropEHandle(
      result: &RecvProps_196[2],
      pVarName: "m_hPlayer",
      offset: 3260,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
    RecvPropInt(
      result: &RecvProps_196[3],
      pVarName: "m_nSpeed",
      offset: 3264,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_196[4], pVarName: "m_nRPM", offset: 3268, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_196[5],
      pVarName: "m_flThrottle",
      offset: 3272,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_196[6],
      pVarName: "m_nBoostTimeLeft",
      offset: 3276,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[7],
      pVarName: "m_nHasBoost",
      offset: 3280,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[8],
      pVarName: "m_nScannerDisabledWeapons",
      offset: 3284,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[9],
      pVarName: "m_nScannerDisabledVehicle",
      offset: 3288,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[10],
      pVarName: "m_bEnterAnimOn",
      offset: 3320,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[11],
      pVarName: "m_bExitAnimOn",
      offset: 3321,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_196[12],
      pVarName: "m_bUnableToFire",
      offset: 3397,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_196[13],
      pVarName: "m_vecEyeExitEndpoint",
      offset: 3384,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropBool(result: &RecvProps_196[14], pVarName: "m_bHasGun", offset: 3396, sizeofVar: 1);
    RecvPropVector(
      result: &RecvProps_196[15],
      pVarName: "m_vecGunCrosshair",
      offset: 3328,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_PropVehicleDriveable::g_RecvTable,
    pProps: &RecvProps_196[1],
    nProps: 15,
    pNetTableName: "DT_PropVehicleDriveable");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024A150
// Name: int ClientClassInit<struct DT_SmokeTrail::ignored>(struct DT_SmokeTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SmokeTrail::ignored>()
{
  if ( (_S5_194 & 1) == 0 )
  {
    _S5_194 |= 1u;
    RecvPropInt(
      result: RecvProps_197,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_197[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_197[2],
      pVarName: "m_SpawnRate",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_197[3],
      pVarName: "m_StartColor",
      offset: 2672,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_197[4],
      pVarName: "m_EndColor",
      offset: 2684,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_197[5],
      pVarName: "m_ParticleLifetime",
      offset: 2700,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[6],
      pVarName: "m_StopEmitTime",
      offset: 2704,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[7],
      pVarName: "m_MinSpeed",
      offset: 2708,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[8],
      pVarName: "m_MaxSpeed",
      offset: 2712,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[9],
      pVarName: "m_MinDirectedSpeed",
      offset: 2716,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[10],
      pVarName: "m_MaxDirectedSpeed",
      offset: 2720,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[11],
      pVarName: "m_StartSize",
      offset: 2724,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[12],
      pVarName: "m_EndSize",
      offset: 2728,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_197[13],
      pVarName: "m_SpawnRadius",
      offset: 2732,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_197[14],
      pVarName: "m_bEmit",
      offset: 2748,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_197[15],
      pVarName: "m_nAttachment",
      offset: 2752,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_197[16],
      pVarName: "m_Opacity",
      offset: 2696,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_SmokeTrail::g_RecvTable,
    pProps: &RecvProps_197[1],
    nProps: 16,
    pNetTableName: "DT_SmokeTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024A400
// Name: int ClientClassInit<struct DT_RocketTrail::ignored>(struct DT_RocketTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_RocketTrail::ignored>()
{
  if ( (_S6_59 & 1) == 0 )
  {
    _S6_59 |= 1u;
    RecvPropInt(
      result: RecvProps_198,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_198[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_198[2],
      pVarName: "m_SpawnRate",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_198[3],
      pVarName: "m_StartColor",
      offset: 2672,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_198[4],
      pVarName: "m_EndColor",
      offset: 2684,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_198[5],
      pVarName: "m_ParticleLifetime",
      offset: 2700,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[6],
      pVarName: "m_StopEmitTime",
      offset: 2704,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[7],
      pVarName: "m_MinSpeed",
      offset: 2708,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[8],
      pVarName: "m_MaxSpeed",
      offset: 2712,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[9],
      pVarName: "m_StartSize",
      offset: 2716,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[10],
      pVarName: "m_EndSize",
      offset: 2720,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_198[11],
      pVarName: "m_SpawnRadius",
      offset: 2724,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_198[12],
      pVarName: "m_bEmit",
      offset: 2740,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_198[13],
      pVarName: "m_nAttachment",
      offset: 2744,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_198[14],
      pVarName: "m_Opacity",
      offset: 2696,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_198[15],
      pVarName: "m_bDamaged",
      offset: 2741,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_198[16],
      pVarName: "m_flFlareScale",
      offset: 2760,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_RocketTrail::g_RecvTable,
    pProps: &RecvProps_198[1],
    nProps: 16,
    pNetTableName: "DT_RocketTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024A6A0
// Name: int ClientClassInit<struct DT_SporeExplosion::ignored>(struct DT_SporeExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SporeExplosion::ignored>()
{
  if ( (_S7_26 & 1) == 0 )
  {
    _S7_26 |= 1u;
    RecvPropInt(
      result: RecvProps_199,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_199[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_199[2],
      pVarName: "m_flSpawnRate",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_199[3],
      pVarName: "m_flParticleLifetime",
      offset: 2672,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_199[4],
      pVarName: "m_flStartSize",
      offset: 2676,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_199[5],
      pVarName: "m_flEndSize",
      offset: 2680,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_199[6],
      pVarName: "m_flSpawnRadius",
      offset: 2684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropBool(result: &RecvProps_199[7], pVarName: "m_bEmit", offset: 2692, sizeofVar: 1);
    RecvPropBool(result: &RecvProps_199[8], pVarName: "m_bDontRemove", offset: 2693, sizeofVar: 1);
  }
  RecvTable::Construct(
    this: &DT_SporeExplosion::g_RecvTable,
    pProps: &RecvProps_199[1],
    nProps: 8,
    pNetTableName: "DT_SporeExplosion");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024A940
// Name: int ClientClassInit<struct DT_SporeTrail::ignored>(struct DT_SporeTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SporeTrail::ignored>()
{
  if ( (_S8_16 & 1) == 0 )
  {
    _S8_16 |= 1u;
    RecvPropInt(
      result: RecvProps_200,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_200[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_200[2],
      pVarName: "m_flSpawnRate",
      offset: 2676,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_200[3],
      pVarName: "m_vecEndColor",
      offset: 2664,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_200[4],
      pVarName: "m_flParticleLifetime",
      offset: 2680,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_200[5],
      pVarName: "m_flStartSize",
      offset: 2684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_200[6],
      pVarName: "m_flEndSize",
      offset: 2688,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_200[7],
      pVarName: "m_flSpawnRadius",
      offset: 2692,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_200[8], pVarName: "m_bEmit", offset: 2708, sizeofVar: 1, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_SporeTrail::g_RecvTable,
    pProps: &RecvProps_200[1],
    nProps: 8,
    pNetTableName: "DT_SporeTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024AAF0
// Name: int ClientClassInit<struct DT_FireTrail::ignored>(struct DT_FireTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_FireTrail::ignored>()
{
  if ( (_S9_8 & 1) == 0 )
  {
    _S9_8 |= 1u;
    RecvPropInt(
      result: RecvProps_201,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_201[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_201[2],
      pVarName: "m_nAttachment",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_201[3],
      pVarName: "m_flLifetime",
      offset: 2672,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_FireTrail::g_RecvTable,
    pProps: &RecvProps_201[1],
    nProps: 3,
    pNetTableName: "DT_FireTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024ABA0
// Name: int ClientClassInit<struct DT_DustTrail::ignored>(struct DT_DustTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_DustTrail::ignored>()
{
  if ( (_S10_5 & 1) == 0 )
  {
    _S10_5 |= 1u;
    RecvPropInt(
      result: RecvProps_202,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_202[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_202[2],
      pVarName: "m_SpawnRate",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_202[3],
      pVarName: "m_Color",
      offset: 2672,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_202[4],
      pVarName: "m_ParticleLifetime",
      offset: 2688,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[5],
      pVarName: "m_StopEmitTime",
      offset: 2696,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[6],
      pVarName: "m_MinSpeed",
      offset: 2700,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[7],
      pVarName: "m_MaxSpeed",
      offset: 2704,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[8],
      pVarName: "m_MinDirectedSpeed",
      offset: 2708,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[9],
      pVarName: "m_MaxDirectedSpeed",
      offset: 2712,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[10],
      pVarName: "m_StartSize",
      offset: 2716,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[11],
      pVarName: "m_EndSize",
      offset: 2720,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_202[12],
      pVarName: "m_SpawnRadius",
      offset: 2724,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_202[13],
      pVarName: "m_bEmit",
      offset: 2740,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_202[14],
      pVarName: "m_Opacity",
      offset: 2684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_DustTrail::g_RecvTable,
    pProps: &RecvProps_202[1],
    nProps: 14,
    pNetTableName: "DT_DustTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FBB0
// Name: int ClientClassInit<struct DT_SmokeStack::ignored>(struct DT_SmokeStack::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SmokeStack::ignored>()
{
  if ( (_S5_195 & 1) == 0 )
  {
    _S5_195 |= 1u;
    RecvPropInt(
      result: RecvProps_203,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_203[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_203[2],
      pVarName: "m_SpreadSpeed",
      offset: 2748,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[3],
      pVarName: "m_Speed",
      offset: 2752,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[4],
      pVarName: "m_StartSize",
      offset: 2756,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[5],
      pVarName: "m_EndSize",
      offset: 2760,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[6],
      pVarName: "m_Rate",
      offset: 2764,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[7],
      pVarName: "m_JetLength",
      offset: 2768,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_203[8], pVarName: "m_bEmit", offset: 2772, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_203[9],
      pVarName: "m_flBaseSpread",
      offset: 2776,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[10],
      pVarName: "m_flTwist",
      offset: 2860,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_203[11],
      pVarName: "m_flRollSpeed",
      offset: 2920,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropEHandle(
      result: &RecvProps_203[12],
      pVarName: "m_iMaterialModel",
      offset: 2864,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntSubOne);
    RecvPropVector(
      result: &RecvProps_203[13],
      pVarName: "m_AmbientLight.m_vPos",
      offset: 2780,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_203[14],
      pVarName: "m_AmbientLight.m_vColor",
      offset: 2792,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_203[15],
      pVarName: "m_AmbientLight.m_flIntensity",
      offset: 2804,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_203[16],
      pVarName: "m_DirLight.m_vPos",
      offset: 2808,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_203[17],
      pVarName: "m_DirLight.m_vColor",
      offset: 2820,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_203[18],
      pVarName: "m_DirLight.m_flIntensity",
      offset: 2832,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_203[19],
      pVarName: "m_vWind",
      offset: 2848,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_SmokeStack::g_RecvTable,
    pProps: &RecvProps_203[1],
    nProps: 19,
    pNetTableName: "DT_SmokeStack");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251170
// Name: int ClientClassInit<struct DT_SteamJet::ignored>(struct DT_SteamJet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_SteamJet::ignored>()
{
  if ( (_S5_196 & 1) == 0 )
  {
    _S5_196 |= 1u;
    RecvPropInt(
      result: RecvProps_204,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_204[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseParticleEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_204[2],
      pVarName: "m_SpreadSpeed",
      offset: 2668,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_204[3],
      pVarName: "m_Speed",
      offset: 2672,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_204[4],
      pVarName: "m_StartSize",
      offset: 2676,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_204[5],
      pVarName: "m_EndSize",
      offset: 2680,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_204[6],
      pVarName: "m_Rate",
      offset: 2684,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_204[7],
      pVarName: "m_JetLength",
      offset: 2688,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_204[8], pVarName: "m_bEmit", offset: 2692, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_204[9],
      pVarName: "m_bFaceLeft",
      offset: 2700,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_204[10],
      pVarName: "m_nType",
      offset: 2696,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_204[11],
      pVarName: "m_spawnflags",
      offset: 2704,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_204[12],
      pVarName: "m_flRollSpeed",
      offset: 2708,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_SteamJet::g_RecvTable,
    pProps: &RecvProps_204[1],
    nProps: 12,
    pNetTableName: "DT_SteamJet");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254280
// Name: int ClientClassInit<struct DT_TEMetalSparks::ignored>(struct DT_TEMetalSparks::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEMetalSparks::ignored>()
{
  if ( (_S5_197 & 1) == 0 )
  {
    _S5_197 |= 1u;
    RecvPropInt(
      result: RecvProps_205,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_205[1],
      pVarName: "m_vecPos",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_205[2],
      pVarName: "m_vecDir",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TEMetalSparks::g_RecvTable,
    pProps: &RecvProps_205[1],
    nProps: 2,
    pNetTableName: "DT_TEMetalSparks");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254320
// Name: int ClientClassInit<struct DT_TEArmorRicochet::ignored>(struct DT_TEArmorRicochet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEArmorRicochet::ignored>()
{
  if ( (_S6_60 & 1) == 0 )
  {
    _S6_60 |= 1u;
    RecvPropInt(
      result: RecvProps_206,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_206[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEMetalSparks::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_TEArmorRicochet::g_RecvTable,
    pProps: &RecvProps_206[1],
    nProps: 1,
    pNetTableName: "DT_TEArmorRicochet");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102544E0
// Name: int ClientClassInit<struct DT_BaseBeam::ignored>(struct DT_BaseBeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_BaseBeam::ignored>()
{
  if ( (_S5_198 & 1) == 0 )
  {
    _S5_198 |= 1u;
    RecvPropInt(
      result: RecvProps_207,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_207[1],
      pVarName: "m_nModelIndex",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_207[2],
      pVarName: "m_nHaloIndex",
      offset: 20,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_207[3],
      pVarName: "m_nStartFrame",
      offset: 24,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_207[4],
      pVarName: "m_nFrameRate",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_207[5],
      pVarName: "m_fLife",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_207[6],
      pVarName: "m_fWidth",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_207[7],
      pVarName: "m_fEndWidth",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_207[8],
      pVarName: "m_nFadeLength",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_207[9],
      pVarName: "m_fAmplitude",
      offset: 48,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_207[10], pVarName: "m_nSpeed", offset: 68, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_207[11], pVarName: "r", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_207[12], pVarName: "g", offset: 56, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_207[13], pVarName: "b", offset: 60, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_207[14], pVarName: "a", offset: 64, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_207[15], pVarName: "m_nFlags", offset: 72, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_BaseBeam::g_RecvTable,
    pProps: &RecvProps_207[1],
    nProps: 15,
    pNetTableName: "DT_BaseBeam");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102548D0
// Name: int ClientClassInit<struct DT_TEBeamEntPoint::ignored>(struct DT_TEBeamEntPoint::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamEntPoint::ignored>()
{
  if ( (_S5_199 & 1) == 0 )
  {
    _S5_199 |= 1u;
    RecvPropInt(
      result: RecvProps_208,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_208[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_208[2],
      pVarName: "m_nStartEntity",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_208[3],
      pVarName: "m_nEndEntity",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_208[4],
      pVarName: "m_vecStartPoint",
      offset: 84,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_208[5],
      pVarName: "m_vecEndPoint",
      offset: 96,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TEBeamEntPoint::g_RecvTable,
    pProps: &RecvProps_208[1],
    nProps: 5,
    pNetTableName: "DT_TEBeamEntPoint");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254BD0
// Name: int ClientClassInit<struct DT_TEBeamEnts::ignored>(struct DT_TEBeamEnts::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamEnts::ignored>()
{
  if ( (_S5_200 & 1) == 0 )
  {
    _S5_200 |= 1u;
    RecvPropInt(
      result: RecvProps_209,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_209[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_209[2],
      pVarName: "m_nStartEntity",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_209[3],
      pVarName: "m_nEndEntity",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBeamEnts::g_RecvTable,
    pProps: &RecvProps_209[1],
    nProps: 3,
    pNetTableName: "DT_TEBeamEnts");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10254D60
// Name: int ClientClassInit<struct DT_TEBeamFollow::ignored>(struct DT_TEBeamFollow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamFollow::ignored>()
{
  if ( (_S5_201 & 1) == 0 )
  {
    _S5_201 |= 1u;
    RecvPropInt(
      result: RecvProps_210,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_210[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_210[2],
      pVarName: "m_iEntIndex",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBeamFollow::g_RecvTable,
    pProps: &RecvProps_210[1],
    nProps: 2,
    pNetTableName: "DT_TEBeamFollow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255090
// Name: int ClientClassInit<struct DT_TEBeamLaser::ignored>(struct DT_TEBeamLaser::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamLaser::ignored>()
{
  if ( (_S5_202 & 1) == 0 )
  {
    _S5_202 |= 1u;
    RecvPropInt(
      result: RecvProps_211,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_211[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_211[2],
      pVarName: "m_nStartEntity",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_211[3],
      pVarName: "m_nEndEntity",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBeamLaser::g_RecvTable,
    pProps: &RecvProps_211[1],
    nProps: 3,
    pNetTableName: "DT_TEBeamLaser");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255350
// Name: int ClientClassInit<struct DT_TEBeamPoints::ignored>(struct DT_TEBeamPoints::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamPoints::ignored>()
{
  if ( (_S5_203 & 1) == 0 )
  {
    _S5_203 |= 1u;
    RecvPropInt(
      result: RecvProps_212,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_212[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_212[2],
      pVarName: "m_vecStartPoint",
      offset: 76,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_212[3],
      pVarName: "m_vecEndPoint",
      offset: 88,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TEBeamPoints::g_RecvTable,
    pProps: &RecvProps_212[1],
    nProps: 3,
    pNetTableName: "DT_TEBeamPoints");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255620
// Name: int ClientClassInit<struct DT_TEBeamRing::ignored>(struct DT_TEBeamRing::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamRing::ignored>()
{
  if ( (_S5_204 & 1) == 0 )
  {
    _S5_204 |= 1u;
    RecvPropInt(
      result: RecvProps_213,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_213[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_213[2],
      pVarName: "m_nStartEntity",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_213[3],
      pVarName: "m_nEndEntity",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBeamRing::g_RecvTable,
    pProps: &RecvProps_213[1],
    nProps: 3,
    pNetTableName: "DT_TEBeamRing");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255910
// Name: int ClientClassInit<struct DT_TEBeamRingPoint::ignored>(struct DT_TEBeamRingPoint::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamRingPoint::ignored>()
{
  if ( (_S5_205 & 1) == 0 )
  {
    _S5_205 |= 1u;
    RecvPropInt(
      result: RecvProps_214,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_214[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEBaseBeam::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_214[2],
      pVarName: "m_vecCenter",
      offset: 76,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_214[3],
      pVarName: "m_flStartRadius",
      offset: 88,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_214[4],
      pVarName: "m_flEndRadius",
      offset: 92,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEBeamRingPoint::g_RecvTable,
    pProps: &RecvProps_214[1],
    nProps: 4,
    pNetTableName: "DT_TEBeamRingPoint");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255A60
// Name: int ClientClassInit<struct DT_TEBeamSpline::ignored>(struct DT_TEBeamSpline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBeamSpline::ignored>()
{
  if ( (_S5_206 & 1) == 0 )
  {
    _S5_206 |= 1u;
    RecvPropInt(
      result: RecvProps_215,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_215[1],
      pVarName: "m_nPoints",
      offset: 208,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_215[2],
      pVarName: "m_vecPoints[0]",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    InternalRecvPropArray(
      result: &RecvProps_215[3],
      elementCount: 16,
      elementStride: 12,
      pName: "m_vecPoints",
      proxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBeamSpline::g_RecvTable,
    pProps: &RecvProps_215[1],
    nProps: 3,
    pNetTableName: "DT_TEBeamSpline");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10255B50
// Name: int ClientClassInit<struct DT_TEBloodSprite::ignored>(struct DT_TEBloodSprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBloodSprite::ignored>()
{
  if ( (_S5_207 & 1) == 0 )
  {
    _S5_207 |= 1u;
    RecvPropInt(
      result: RecvProps_216,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_216[1],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_216[2],
      pVarName: "m_vecDirection",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_216[3], pVarName: "r", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_216[4], pVarName: "g", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_216[5], pVarName: "b", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_216[6], pVarName: "a", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_216[7],
      pVarName: "m_nSprayModel",
      offset: 60,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_216[8],
      pVarName: "m_nDropModel",
      offset: 56,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_216[9], pVarName: "m_nSize", offset: 64, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBloodSprite::g_RecvTable,
    pProps: &RecvProps_216[1],
    nProps: 9,
    pNetTableName: "DT_TEBloodSprite");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102562C0
// Name: int ClientClassInit<struct DT_TEBloodStream::ignored>(struct DT_TEBloodStream::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBloodStream::ignored>()
{
  if ( (_S5_208 & 1) == 0 )
  {
    _S5_208 |= 1u;
    RecvPropInt(
      result: RecvProps_217,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_217[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_217[2],
      pVarName: "m_vecDirection",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_217[3], pVarName: "r", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_217[4], pVarName: "g", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_217[5], pVarName: "b", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_217[6], pVarName: "a", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_217[7], pVarName: "m_nAmount", offset: 56, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBloodStream::g_RecvTable,
    pProps: &RecvProps_217[1],
    nProps: 7,
    pNetTableName: "DT_TEBloodStream");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10256FA0
// Name: int ClientClassInit<struct DT_TEBreakModel::ignored>(struct DT_TEBreakModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBreakModel::ignored>()
{
  if ( (_S5_209 & 1) == 0 )
  {
    _S5_209 |= 1u;
    RecvPropInt(
      result: RecvProps_218,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_218[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_218[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_218[3],
      pVarName: "m_angRotation[0]",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_218[4],
      pVarName: "m_angRotation[1]",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_218[5],
      pVarName: "m_angRotation[2]",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_218[6],
      pVarName: "m_vecSize",
      offset: 40,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_218[7],
      pVarName: "m_vecVelocity",
      offset: 52,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_218[8],
      pVarName: "m_nModelIndex",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_218[9],
      pVarName: "m_nRandomization",
      offset: 64,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_218[10], pVarName: "m_nCount", offset: 72, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_218[11],
      pVarName: "m_fTime",
      offset: 76,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_218[12], pVarName: "m_nFlags", offset: 80, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBreakModel::g_RecvTable,
    pProps: &RecvProps_218[1],
    nProps: 12,
    pNetTableName: "DT_TEBreakModel");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102573C0
// Name: int ClientClassInit<struct DT_TEBSPDecal::ignored>(struct DT_TEBSPDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBSPDecal::ignored>()
{
  if ( (_S5_210 & 1) == 0 )
  {
    _S5_210 |= 1u;
    RecvPropInt(
      result: RecvProps_219,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_219[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_219[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_219[3], pVarName: "m_nEntity", offset: 28, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_219[4], pVarName: "m_nIndex", offset: 32, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEBSPDecal::g_RecvTable,
    pProps: &RecvProps_219[1],
    nProps: 4,
    pNetTableName: "DT_TEBSPDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10257680
// Name: int ClientClassInit<struct DT_TEBubbles::ignored>(struct DT_TEBubbles::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBubbles::ignored>()
{
  if ( (_S5_211 & 1) == 0 )
  {
    _S5_211 |= 1u;
    RecvPropInt(
      result: RecvProps_220,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_220[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_220[2],
      pVarName: "m_vecMins",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_220[3],
      pVarName: "m_vecMaxs",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_220[4],
      pVarName: "m_nModelIndex",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_220[5],
      pVarName: "m_fHeight",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_220[6], pVarName: "m_nCount", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_220[7],
      pVarName: "m_fSpeed",
      offset: 52,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEBubbles::g_RecvTable,
    pProps: &RecvProps_220[1],
    nProps: 7,
    pNetTableName: "DT_TEBubbles");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10257860
// Name: int ClientClassInit<struct DT_TEBubbleTrail::ignored>(struct DT_TEBubbleTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEBubbleTrail::ignored>()
{
  if ( (_S5_212 & 1) == 0 )
  {
    _S5_212 |= 1u;
    RecvPropInt(
      result: RecvProps_221,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_221[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_221[2],
      pVarName: "m_vecMins",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_221[3],
      pVarName: "m_vecMaxs",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_221[4],
      pVarName: "m_nModelIndex",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_221[5],
      pVarName: "m_flWaterZ",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_221[6], pVarName: "m_nCount", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_221[7],
      pVarName: "m_fSpeed",
      offset: 52,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEBubbleTrail::g_RecvTable,
    pProps: &RecvProps_221[1],
    nProps: 7,
    pNetTableName: "DT_TEBubbleTrail");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102579F0
// Name: int ClientClassInit<struct DT_TEClientProjectile::ignored>(struct DT_TEClientProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEClientProjectile::ignored>()
{
  if ( (_S5_213 & 1) == 0 )
  {
    _S5_213 |= 1u;
    RecvPropInt(
      result: RecvProps_222,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_222[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_222[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_222[3],
      pVarName: "m_vecVelocity",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_222[4],
      pVarName: "m_nModelIndex",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_222[5],
      pVarName: "m_nLifeTime",
      offset: 44,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropEHandle(
      result: &RecvProps_222[6],
      pVarName: "m_hOwner",
      offset: 48,
      sizeofVar: 4,
      proxyFn: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_TEClientProjectile::g_RecvTable,
    pProps: &RecvProps_222[1],
    nProps: 6,
    pNetTableName: "DT_TEClientProjectile");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10257B90
// Name: int ClientClassInit<struct DT_TEDecal::ignored>(struct DT_TEDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEDecal::ignored>()
{
  if ( (_S5_214 & 1) == 0 )
  {
    _S5_214 |= 1u;
    RecvPropInt(
      result: RecvProps_223,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_223[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_223[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_223[3],
      pVarName: "m_vecStart",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_223[4], pVarName: "m_nEntity", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_223[5], pVarName: "m_nHitbox", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_223[6], pVarName: "m_nIndex", offset: 48, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEDecal::g_RecvTable,
    pProps: &RecvProps_223[1],
    nProps: 6,
    pNetTableName: "DT_TEDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102580A0
// Name: int ClientClassInit<struct DT_TEDynamicLight::ignored>(struct DT_TEDynamicLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEDynamicLight::ignored>()
{
  if ( (_S5_215 & 1) == 0 )
  {
    _S5_215 |= 1u;
    RecvPropInt(
      result: RecvProps_224,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_224[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_224[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_224[3], pVarName: "r", offset: 32, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_224[4], pVarName: "g", offset: 36, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_224[5], pVarName: "b", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_224[6], pVarName: "exponent", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_224[7],
      pVarName: "m_fRadius",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_224[8],
      pVarName: "m_fTime",
      offset: 48,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_224[9],
      pVarName: "m_fDecay",
      offset: 52,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEDynamicLight::g_RecvTable,
    pProps: &RecvProps_224[1],
    nProps: 9,
    pNetTableName: "DT_TEDynamicLight");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102588B0
// Name: int ClientClassInit<struct DT_TEEffectDispatch::ignored>(struct DT_TEEffectDispatch::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEEffectDispatch::ignored>()
{
  if ( (_S6_61 & 1) == 0 )
  {
    _S6_61 |= 1u;
    RecvPropInt(
      result: RecvProps_225,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_225[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropDataTable(
      result: &RecvProps_225[2],
      pVarName: "m_EffectData",
      offset: 16,
      flags: 0,
      pTable: &DT_EffectData::g_RecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
  }
  RecvTable::Construct(
    this: &DT_TEEffectDispatch::g_RecvTable,
    pProps: &RecvProps_225[1],
    nProps: 2,
    pNetTableName: "DT_TEEffectDispatch");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10258FF0
// Name: int ClientClassInit<struct DT_TEEnergySplash::ignored>(struct DT_TEEnergySplash::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEEnergySplash::ignored>()
{
  if ( (_S5_217 & 1) == 0 )
  {
    _S5_217 |= 1u;
    RecvPropInt(
      result: RecvProps_226,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_226[1],
      pVarName: "m_vecPos",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_226[2],
      pVarName: "m_vecDir",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_226[3],
      pVarName: "m_bExplosive",
      offset: 40,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEEnergySplash::g_RecvTable,
    pProps: &RecvProps_226[1],
    nProps: 3,
    pNetTableName: "DT_TEEnergySplash");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102590E0
// Name: int ClientClassInit<struct DT_TEExplosion::ignored>(struct DT_TEExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEExplosion::ignored>()
{
  if ( (_S5_218 & 1) == 0 )
  {
    _S5_218 |= 1u;
    RecvPropInt(
      result: RecvProps_227,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_227[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_227[2],
      pVarName: "m_nModelIndex",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_227[3],
      pVarName: "m_fScale",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_227[4],
      pVarName: "m_nFrameRate",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_227[5], pVarName: "m_nFlags", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_227[6],
      pVarName: "m_vecNormal",
      offset: 44,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_227[7],
      pVarName: "m_chMaterialType",
      offset: 56,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_227[8], pVarName: "m_nRadius", offset: 60, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_227[9],
      pVarName: "m_nMagnitude",
      offset: 64,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEExplosion::g_RecvTable,
    pProps: &RecvProps_227[1],
    nProps: 9,
    pNetTableName: "DT_TEExplosion");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10259C30
// Name: int ClientClassInit<struct DT_TEFizz::ignored>(struct DT_TEFizz::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEFizz::ignored>()
{
  if ( (_S5_219 & 1) == 0 )
  {
    _S5_219 |= 1u;
    RecvPropInt(
      result: RecvProps_228,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_228[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_228[2], pVarName: "m_nEntity", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_228[3],
      pVarName: "m_nModelIndex",
      offset: 20,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_228[4],
      pVarName: "m_nDensity",
      offset: 24,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_228[5],
      pVarName: "m_nCurrent",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(this: &DT_TEFizz::g_RecvTable, pProps: &RecvProps_228[1], nProps: 5, pNetTableName: "DT_TEFizz");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10259D90
// Name: int ClientClassInit<struct DT_TEFootprintDecal::ignored>(struct DT_TEFootprintDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEFootprintDecal::ignored>()
{
  if ( (_S5_220 & 1) == 0 )
  {
    _S5_220 |= 1u;
    RecvPropInt(
      result: RecvProps_229,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_229[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_229[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_229[3],
      pVarName: "m_vecDirection",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_229[4], pVarName: "m_nEntity", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_229[5], pVarName: "m_nIndex", offset: 56, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_229[6],
      pVarName: "m_chMaterialType",
      offset: 60,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEFootprintDecal::g_RecvTable,
    pProps: &RecvProps_229[1],
    nProps: 6,
    pNetTableName: "DT_TEFootprintDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025A060
// Name: int ClientClassInit<struct DT_TEShatterSurface::ignored>(struct DT_TEShatterSurface::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEShatterSurface::ignored>()
{
  if ( (_S5_221 & 1) == 0 )
  {
    _S5_221 |= 1u;
    RecvPropInt(
      result: RecvProps_230,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_230[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_230[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_230[3],
      pVarName: "m_vecAngles",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_230[4],
      pVarName: "m_vecForce",
      offset: 40,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_230[5],
      pVarName: "m_vecForcePos",
      offset: 52,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_230[6],
      pVarName: "m_flWidth",
      offset: 64,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_230[7],
      pVarName: "m_flHeight",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_230[8],
      pVarName: "m_flShardSize",
      offset: 72,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_230[9],
      pVarName: "m_nSurfaceType",
      offset: 80,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[10],
      pVarName: "m_uchFrontColor[0]",
      offset: 84,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[11],
      pVarName: "m_uchFrontColor[1]",
      offset: 85,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[12],
      pVarName: "m_uchFrontColor[2]",
      offset: 86,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[13],
      pVarName: "m_uchBackColor[0]",
      offset: 87,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[14],
      pVarName: "m_uchBackColor[1]",
      offset: 88,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_230[15],
      pVarName: "m_uchBackColor[2]",
      offset: 89,
      sizeofVar: 1,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEShatterSurface::g_RecvTable,
    pProps: &RecvProps_230[1],
    nProps: 15,
    pNetTableName: "DT_TEShatterSurface");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025AED0
// Name: int ClientClassInit<struct DT_TEGlowSprite::ignored>(struct DT_TEGlowSprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEGlowSprite::ignored>()
{
  if ( (_S5_222 & 1) == 0 )
  {
    _S5_222 |= 1u;
    RecvPropInt(
      result: RecvProps_231,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_231[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_231[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_231[3],
      pVarName: "m_nModelIndex",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_231[4],
      pVarName: "m_fScale",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_231[5],
      pVarName: "m_fLife",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_231[6],
      pVarName: "m_nBrightness",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEGlowSprite::g_RecvTable,
    pProps: &RecvProps_231[1],
    nProps: 6,
    pNetTableName: "DT_TEGlowSprite");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025B410
// Name: int ClientClassInit<struct DT_TEImpact::ignored>(struct DT_TEImpact::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEImpact::ignored>()
{
  if ( (_S5_223 & 1) == 0 )
  {
    _S5_223 |= 1u;
    RecvPropInt(
      result: RecvProps_232,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_232[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_232[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_232[3],
      pVarName: "m_vecNormal",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_232[4], pVarName: "m_iType", offset: 40, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_232[5], pVarName: "m_ucFlags", offset: 44, sizeofVar: 1, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEImpact::g_RecvTable,
    pProps: &RecvProps_232[1],
    nProps: 5,
    pNetTableName: "DT_TEImpact");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025B570
// Name: int ClientClassInit<struct DT_TEKillPlayerAttachments::ignored>(struct DT_TEKillPlayerAttachments::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEKillPlayerAttachments::ignored>()
{
  if ( (_S5_224 & 1) == 0 )
  {
    _S5_224 |= 1u;
    RecvPropInt(
      result: RecvProps_233,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_233[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(result: &RecvProps_233[2], pVarName: "m_nPlayer", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEKillPlayerAttachments::g_RecvTable,
    pProps: &RecvProps_233[1],
    nProps: 2,
    pNetTableName: "DT_TEKillPlayerAttachments");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025B640
// Name: int ClientClassInit<struct DT_TELargeFunnel::ignored>(struct DT_TELargeFunnel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TELargeFunnel::ignored>()
{
  if ( (_S5_225 & 1) == 0 )
  {
    _S5_225 |= 1u;
    RecvPropInt(
      result: RecvProps_234,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_234[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_234[2],
      pVarName: "m_nModelIndex",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_234[3],
      pVarName: "m_nReversed",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TELargeFunnel::g_RecvTable,
    pProps: &RecvProps_234[1],
    nProps: 3,
    pNetTableName: "DT_TELargeFunnel");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102630C0
// Name: int ClientClassInit<struct DT_TEMuzzleFlash::ignored>(struct DT_TEMuzzleFlash::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEMuzzleFlash::ignored>()
{
  if ( (_S5_226 & 1) == 0 )
  {
    _S5_226 |= 1u;
    RecvPropInt(
      result: RecvProps_235,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_235[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_235[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_235[3],
      pVarName: "m_vecAngles",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_235[4],
      pVarName: "m_flScale",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_235[5], pVarName: "m_nType", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEMuzzleFlash::g_RecvTable,
    pProps: &RecvProps_235[1],
    nProps: 5,
    pNetTableName: "DT_TEMuzzleFlash");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10263220
// Name: int ClientClassInit<struct DT_TEParticleSystem::ignored>(struct DT_TEParticleSystem::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEParticleSystem::ignored>()
{
  if ( (_S5_227 & 1) == 0 )
  {
    _S5_227 |= 1u;
    RecvPropInt(
      result: RecvProps_236,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_236[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropFloat(
      result: &RecvProps_236[2],
      pVarName: "m_vecOrigin[0]",
      offset: 16,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_236[3],
      pVarName: "m_vecOrigin[1]",
      offset: 20,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_236[4],
      pVarName: "m_vecOrigin[2]",
      offset: 24,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
  }
  RecvTable::Construct(
    this: &DT_TEParticleSystem::g_RecvTable,
    pProps: &RecvProps_236[1],
    nProps: 4,
    pNetTableName: "DT_TEParticleSystem");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10263AE0
// Name: int ClientClassInit<struct DT_TEPhysicsProp::ignored>(struct DT_TEPhysicsProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEPhysicsProp::ignored>()
{
  if ( (_S5_228 & 1) == 0 )
  {
    _S5_228 |= 1u;
    RecvPropInt(
      result: RecvProps_237,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_237[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_237[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_237[3],
      pVarName: "m_angRotation[0]",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_237[4],
      pVarName: "m_angRotation[1]",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_237[5],
      pVarName: "m_angRotation[2]",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropVector(
      result: &RecvProps_237[6],
      pVarName: "m_vecVelocity",
      offset: 40,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_237[7],
      pVarName: "m_nModelIndex",
      offset: 52,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(result: &RecvProps_237[8], pVarName: "m_nFlags", offset: 60, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_237[9], pVarName: "m_nSkin", offset: 56, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_237[10],
      pVarName: "m_nEffects",
      offset: 64,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_237[11],
      pVarName: "m_clrRender",
      offset: 68,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
  }
  RecvTable::Construct(
    this: &DT_TEPhysicsProp::g_RecvTable,
    pProps: &RecvProps_237[1],
    nProps: 11,
    pNetTableName: "DT_TEPhysicsProp");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10264740
// Name: int ClientClassInit<struct DT_TEPlayerDecal::ignored>(struct DT_TEPlayerDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEPlayerDecal::ignored>()
{
  if ( (_S5_229 & 1) == 0 )
  {
    _S5_229 |= 1u;
    RecvPropInt(
      result: RecvProps_238,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_238[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_238[2],
      pVarName: "m_vecOrigin",
      offset: 20,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_238[3], pVarName: "m_nEntity", offset: 32, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_238[4], pVarName: "m_nPlayer", offset: 16, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEPlayerDecal::g_RecvTable,
    pProps: &RecvProps_238[1],
    nProps: 4,
    pNetTableName: "DT_TEPlayerDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10264B40
// Name: int ClientClassInit<struct DT_TEProjectedDecal::ignored>(struct DT_TEProjectedDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEProjectedDecal::ignored>()
{
  if ( (_S5_230 & 1) == 0 )
  {
    _S5_230 |= 1u;
    RecvPropInt(
      result: RecvProps_239,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_239[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_239[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_239[3],
      pVarName: "m_angRotation",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_239[4],
      pVarName: "m_flDistance",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_239[5], pVarName: "m_nIndex", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEProjectedDecal::g_RecvTable,
    pProps: &RecvProps_239[1],
    nProps: 5,
    pNetTableName: "DT_TEProjectedDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10265010
// Name: int ClientClassInit<struct DT_TEShowLine::ignored>(struct DT_TEShowLine::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEShowLine::ignored>()
{
  if ( (_S5_231 & 1) == 0 )
  {
    _S5_231 |= 1u;
    RecvPropInt(
      result: RecvProps_240,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_240[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_240[2],
      pVarName: "m_vecEnd",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TEShowLine::g_RecvTable,
    pProps: &RecvProps_240[1],
    nProps: 2,
    pNetTableName: "DT_TEShowLine");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10265480
// Name: int ClientClassInit<struct DT_TESmoke::ignored>(struct DT_TESmoke::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TESmoke::ignored>()
{
  if ( (_S5_232 & 1) == 0 )
  {
    _S5_232 |= 1u;
    RecvPropInt(
      result: RecvProps_241,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_241[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_241[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_241[3],
      pVarName: "m_nModelIndex",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_241[4],
      pVarName: "m_fScale",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_241[5],
      pVarName: "m_nFrameRate",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TESmoke::g_RecvTable,
    pProps: &RecvProps_241[1],
    nProps: 5,
    pNetTableName: "DT_TESmoke");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10265770
// Name: int ClientClassInit<struct DT_TESparks::ignored>(struct DT_TESparks::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TESparks::ignored>()
{
  if ( (_S5_233 & 1) == 0 )
  {
    _S5_233 |= 1u;
    RecvPropInt(
      result: RecvProps_242,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_242[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_TEParticleSystem::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropInt(
      result: &RecvProps_242[2],
      pVarName: "m_nMagnitude",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_242[3],
      pVarName: "m_nTrailLength",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropVector(
      result: &RecvProps_242[4],
      pVarName: "m_vecDir",
      offset: 36,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
  }
  RecvTable::Construct(
    this: &DT_TESparks::g_RecvTable,
    pProps: &RecvProps_242[1],
    nProps: 4,
    pNetTableName: "DT_TESparks");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10265880
// Name: int ClientClassInit<struct DT_TESprite::ignored>(struct DT_TESprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TESprite::ignored>()
{
  if ( (_S5_234 & 1) == 0 )
  {
    _S5_234 |= 1u;
    RecvPropInt(
      result: RecvProps_243,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_243[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_243[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_243[3],
      pVarName: "m_nModelIndex",
      offset: 28,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_243[4],
      pVarName: "m_fScale",
      offset: 32,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_243[5],
      pVarName: "m_nBrightness",
      offset: 36,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TESprite::g_RecvTable,
    pProps: &RecvProps_243[1],
    nProps: 5,
    pNetTableName: "DT_TESprite");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10265D10
// Name: int ClientClassInit<struct DT_TESpriteSpray::ignored>(struct DT_TESpriteSpray::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TESpriteSpray::ignored>()
{
  if ( (_S5_235 & 1) == 0 )
  {
    _S5_235 |= 1u;
    RecvPropInt(
      result: RecvProps_244,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_244[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_244[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropVector(
      result: &RecvProps_244[3],
      pVarName: "m_vecDirection",
      offset: 28,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(
      result: &RecvProps_244[4],
      pVarName: "m_nModelIndex",
      offset: 40,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropFloat(
      result: &RecvProps_244[5],
      pVarName: "m_fNoise",
      offset: 48,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(result: &RecvProps_244[6], pVarName: "m_nCount", offset: 52, sizeofVar: 4, flags: 0, varProxy: nullptr);
    RecvPropInt(result: &RecvProps_244[7], pVarName: "m_nSpeed", offset: 44, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TESpriteSpray::g_RecvTable,
    pProps: &RecvProps_244[1],
    nProps: 7,
    pNetTableName: "DT_TESpriteSpray");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10266290
// Name: int ClientClassInit<struct DT_TEWorldDecal::ignored>(struct DT_TEWorldDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TEWorldDecal::ignored>()
{
  if ( (_S5_236 & 1) == 0 )
  {
    _S5_236 |= 1u;
    RecvPropInt(
      result: RecvProps_245,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropDataTable(
      result: &RecvProps_245[1],
      pVarName: "baseclass",
      offset: 0,
      flags: 0,
      pTable: C_BaseTempEntity::m_pClassRecvTable,
      varProxy: (void (__cdecl *)(const RecvProp *, void **, void *, int))DataTableRecvProxy_StaticDataTable);
    RecvPropVector(
      result: &RecvProps_245[2],
      pVarName: "m_vecOrigin",
      offset: 16,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropInt(result: &RecvProps_245[3], pVarName: "m_nIndex", offset: 28, sizeofVar: 4, flags: 0, varProxy: nullptr);
  }
  RecvTable::Construct(
    this: &DT_TEWorldDecal::g_RecvTable,
    pProps: &RecvProps_245[1],
    nProps: 3,
    pNetTableName: "DT_TEWorldDecal");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10266600
// Name: public: virtual class ClientClass __near * C_TestTraceline::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TestTraceline::GetClientClass(C_TestTraceline *this)
{
  return &__g_C_TestTracelineClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10266610
// Name: public: C_TestTraceline::C_TestTraceline(void)
// Source: json
//------------------------------------------------------------------------------
C_TestTraceline *__thiscall C_TestTraceline::C_TestTraceline(C_TestTraceline *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_TestTraceline_vtbl *)&C_TestTraceline::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_TestTraceline::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TestTraceline::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_TestTraceline::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_TestTraceline::`vftable';
  this->m_pWireframe = materials->FindMaterial(
                         this: materials,
                         a2: "debug/debugwireframevertexcolor",
                         a3: "Other textures",
                         a4: 1,
                         a5: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102666C0
// Name: int ClientClassInit<struct DT_TestTraceline::ignored>(struct DT_TestTraceline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClientClassInit<DT_TestTraceline::ignored>()
{
  if ( (_S5_237 & 1) == 0 )
  {
    _S5_237 |= 1u;
    RecvPropInt(
      result: RecvProps_246,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      flags: 0,
      varProxy: nullptr);
    RecvPropInt(
      result: &RecvProps_246[1],
      pVarName: "m_clrRender",
      offset: 108,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_Int32ToInt32);
    RecvPropVector(
      result: &RecvProps_246[2],
      pVarName: "m_vecOrigin",
      offset: 300,
      sizeofVar: 12,
      flags: 0,
      varProxy: RecvProxy_VectorToVector);
    RecvPropFloat(
      result: &RecvProps_246[3],
      pVarName: "m_angRotation[0]",
      offset: 288,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_246[4],
      pVarName: "m_angRotation[1]",
      offset: 292,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropFloat(
      result: &RecvProps_246[5],
      pVarName: "m_angRotation[2]",
      offset: 296,
      sizeofVar: 4,
      flags: 0,
      varProxy: (void (__cdecl *)(const CRecvProxyData *, void *, void *))C_BasePlayer::RecvProxy_LocalOriginZ);
    RecvPropInt(
      result: &RecvProps_246[6],
      pVarName: "moveparent",
      offset: 316,
      sizeofVar: 4,
      flags: 0,
      varProxy: RecvProxy_IntToEHandle);
  }
  RecvTable::Construct(
    this: &DT_TestTraceline::g_RecvTable,
    pProps: &RecvProps_246[1],
    nProps: 6,
    pNetTableName: "DT_TestTraceline");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10266810
// Name: public: void CMeshBuilder::DrawQuad(class IMesh __near *,float const __near *,float const __near *,float const __near *,float const __near *,unsigned char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::DrawQuad(
        CMeshBuilder *this,
        IMesh *pMesh,
        float *v1,
        float *v2,
        float *v3,
        float *v4,
        const unsigned __int8 *pColor,
        bool wireframe)
{
  unsigned int m_nIndexSize; // edx
  CVertexBuilder *p_m_VertexBuilder; // esi
  float *v11; // eax
  int v12; // ecx
  float *v13; // ecx
  int v14; // ecx
  float *v15; // ecx
  int v16; // ecx
  float *v17; // ecx
  int v18; // eax
  float *m_pCurrPosition; // eax
  int v20; // ecx
  float *v21; // ecx
  int v22; // ecx
  float *v23; // ecx
  int v24; // ecx
  float *v25; // ecx
  int v26; // eax
  int v27; // eax

  if ( wireframe )
  {
    CMeshBuilder::Begin(this, pMesh, type: 5, numPrimitives: 4);
    m_pCurrPosition = this->m_VertexBuilder.m_pCurrPosition;
    p_m_VertexBuilder = &this->m_VertexBuilder;
    *m_pCurrPosition = *v1;
    m_pCurrPosition[1] = v1[1];
    m_pCurrPosition[2] = v1[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v20 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v20 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v20;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v21 = this->m_VertexBuilder.m_pCurrPosition;
    *v21 = *v2;
    v21[1] = v2[1];
    v21[2] = v2[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v22 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v22 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v22;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v23 = this->m_VertexBuilder.m_pCurrPosition;
    *v23 = *v3;
    v23[1] = v3[1];
    v23[2] = v3[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v24 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v24 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v24;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v25 = this->m_VertexBuilder.m_pCurrPosition;
    *v25 = *v4;
    v25[1] = v4[1];
    v25[2] = v4[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v26 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v26 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v26;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
  }
  else
  {
    this->m_pMesh = pMesh;
    this->m_bGenerateIndices = true;
    this->m_Type = MATERIAL_TRIANGLE_STRIP;
    pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLE_STRIP);
    this->m_pMesh->LockMesh(this: this->m_pMesh, a2: 4, a3: 4, a4: this, a5: nullptr);
    this->m_IndexBuilder.m_nIndexCount = 0;
    this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
    this->m_IndexBuilder.m_nMaxIndexCount = 4;
    this->m_IndexBuilder.m_bModify = false;
    this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
    this->m_IndexBuilder.m_pIndices = this->m_pIndices;
    m_nIndexSize = this->m_nIndexSize;
    this->m_IndexBuilder.m_nCurrentIndex = 0;
    p_m_VertexBuilder = &this->m_VertexBuilder;
    this->m_IndexBuilder.m_nIndexSize = m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: this);
    this->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &this->m_VertexBuilder);
    v11 = this->m_VertexBuilder.m_pCurrPosition;
    *v11 = *v1;
    v11[1] = v1[1];
    v11[2] = v1[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v12 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v12 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v12;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v13 = this->m_VertexBuilder.m_pCurrPosition;
    *v13 = *v2;
    v13[1] = v2[1];
    v13[2] = v2[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v14 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v14 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v14;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v15 = this->m_VertexBuilder.m_pCurrPosition;
    *v15 = *v4;
    v15[1] = v4[1];
    v15[2] = v4[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v16 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v16 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v16;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
    v17 = this->m_VertexBuilder.m_pCurrPosition;
    *v17 = *v3;
    v17[1] = v3[1];
    v17[2] = v3[2];
    *(_DWORD *)this->m_VertexBuilder.m_pCurrColor = pColor[2] | ((pColor[1] | ((*pColor | (pColor[3] << 8)) << 8)) << 8);
    v18 = ++this->m_VertexBuilder.m_nCurrentVertex;
    if ( v18 > this->m_VertexBuilder.m_nVertexCount )
      this->m_VertexBuilder.m_nVertexCount = v18;
    this->m_VertexBuilder.m_pCurrPosition = (float *)((char *)this->m_VertexBuilder.m_pCurrPosition
                                                    + this->m_VertexBuilder.m_VertexSize_Position);
    this->m_VertexBuilder.m_pCurrColor += this->m_VertexBuilder.m_VertexSize_Color;
  }
  if ( this->m_bGenerateIndices )
  {
    v27 = CMeshBuilder::IndicesFromVertices(
            this,
            type: this->m_Type,
            nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: this->m_Type, nIndexCount: v27);
  }
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  p_m_VertexBuilder->m_nMaxVertexCount = 0;
  p_m_VertexBuilder->m_pVertexBuffer = nullptr;
  p_m_VertexBuilder->m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10266CC0
// Name: private: void C_TestTraceline::DrawCube(class Vector __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TestTraceline::DrawCube(
        C_TestTraceline *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *center,
        unsigned __int8 *pColor)
{
  float x; // xmm4_4
  float y; // xmm1_4
  float z; // xmm2_4
  int *v9; // edi
  int v10; // esi
  IMesh *v11; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-2A8h] BYREF
  int nFaces[6][4]; // [esp+1E8h] [ebp-C0h] BYREF
  Vector facePoints[8]; // [esp+248h] [ebp-60h] BYREF
  int centera; // [esp+2B0h] [ebp+8h]

  x = center->x;
  y = center->y;
  z = center->z;
  *(_QWORD *)&nFaces[0][2] = 0x100000003LL;
  facePoints[0].x = x - 5.0;
  facePoints[0].y = y - 5.0;
  facePoints[0].z = z - 5.0;
  facePoints[1].x = x - 5.0;
  facePoints[1].y = y - 5.0;
  facePoints[1].z = z + 5.0;
  facePoints[2].x = x - 5.0;
  facePoints[2].y = y + 5.0;
  facePoints[2].z = z - 5.0;
  facePoints[3].x = x - 5.0;
  facePoints[3].y = y + 5.0;
  facePoints[3].z = z + 5.0;
  facePoints[4].x = x + 5.0;
  facePoints[4].y = y - 5.0;
  facePoints[4].z = z - 5.0;
  facePoints[5].x = x + 5.0;
  facePoints[5].y = y - 5.0;
  facePoints[5].z = z + 5.0;
  facePoints[6].x = x + 5.0;
  facePoints[6].y = y + 5.0;
  facePoints[6].z = z - 5.0;
  facePoints[7].x = x + 5.0;
  facePoints[7].y = y + 5.0;
  facePoints[7].z = z + 5.0;
  *(_QWORD *)&nFaces[0][0] = 0x200000000LL;
  *(_QWORD *)&nFaces[1][0] = 0x100000000LL;
  *(_QWORD *)&nFaces[1][2] = 0x400000005LL;
  *(_QWORD *)&nFaces[2][0] = 0x500000004LL;
  *(_QWORD *)&nFaces[2][2] = 0x600000007LL;
  *(_QWORD *)&nFaces[3][0] = 0x600000002LL;
  *(_QWORD *)&nFaces[3][2] = 0x300000007LL;
  *(_QWORD *)&nFaces[4][0] = 0x300000001LL;
  *(_QWORD *)&nFaces[4][2] = 0x500000007LL;
  *(_QWORD *)&nFaces[5][0] = 0x400000000LL;
  *(_QWORD *)&nFaces[5][2] = 0x200000006LL;
  v9 = &nFaces[0][1];
  for ( centera = 6; centera != 0; --centera )
  {
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v10 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
            a1: materials,
            a2: a3,
            a3: a4,
            a4: a2);
    if ( v10 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
    a2 = 0;
    a4 = 0;
    a3 = 0;
    v11 = (IMesh *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v10 + 228))(a1: v10, a2: 1);
    CMeshBuilder::DrawQuad(
      this: &meshBuilder,
      pMesh: v11,
      v1: &facePoints[*(v9 - 1)].x,
      v2: &facePoints[*v9].x,
      v3: &facePoints[v9[1]].x,
      v4: &facePoints[v9[2]].x,
      pColor,
      wireframe: true);
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    v9 += 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10266F80
// Name: public: virtual int C_TestTraceline::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_TestTraceline::DrawModel@<eax>(
        C_TestTraceline *this@<ecx>,
        int a2@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  C_TestTraceline *v4; // edi
  const QAngle *v5; // eax
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  const Vector *(__thiscall *v11)(IClientEntity *); // eax
  const Vector *v12; // eax
  IMatRenderContext *v13; // eax
  IMatRenderContext *v14; // esi
  IMesh *v15; // esi
  float *v16; // eax
  float *m_pCurrPosition; // ecx
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  Vector up; // [esp+Ch] [ebp-274h] BYREF
  Vector right; // [esp+18h] [ebp-268h] BYREF
  CMeshBuilder meshBuilder; // [esp+24h] [ebp-25Ch] BYREF
  CGameTrace tr; // [esp+20Ch] [ebp-74h] BYREF
  Vector forward; // [esp+260h] [ebp-20h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+26Ch] [ebp-14h]
  Vector endpos; // [esp+270h] [ebp-10h] BYREF
  C_TestTraceline *color; // [esp+27Ch] [ebp-4h] BYREF
  IHandleEntity savedregs; // [esp+280h] [ebp+0h] BYREF

  v4 = (C_TestTraceline *)((char *)this - 4);
  color = this;
  v5 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 44))(a1: (char *)this - 4);
  AngleVectors(angles: v5, &forward, &right, &up);
  GetAbsOrigin = v4->GetAbsOrigin;
  endpos.x = forward.x * 56755.84;
  endpos.y = forward.y * 56755.84;
  endpos.z = forward.z * 56755.84;
  v7 = (float *)GetAbsOrigin(this: v4);
  v8 = v7[2] + endpos.z;
  v9 = endpos.x + *v7;
  v10 = v7[1] + endpos.y;
  v11 = v4->GetAbsOrigin;
  endpos.x = v9;
  endpos.y = v10;
  endpos.z = v8;
  v12 = v11(this: v4);
  UTIL_TraceLine(
    a1: &savedregs,
    a2,
    vecAbsStart: v12,
    vecAbsEnd: &endpos,
    mask: 0x400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  v13 = materials->GetRenderContext(this: materials);
  v14 = v13;
  pRenderContext.m_pObject = v13;
  if ( v13 != nullptr )
    v13->BeginRender(this: v13);
  v15 = v14->GetDynamicMesh(
          this: v14,
          a2: true,
          a3: nullptr,
          a4: nullptr,
          a5: *((IMaterial **)&color->m_bIsBlurred + 1));
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v15;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_LINES;
  v15->SetPrimitiveType(this: v15, a2: MATERIAL_LINES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 2, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v16 = (float *)v4->GetAbsOrigin(this: v4);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v16;
  m_pCurrPosition[1] = v16[1];
  m_pCurrPosition[2] = v16[2];
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = tr.endpos;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v15->Draw_2(this: v15, a2: -1, a3: 0);
  if ( tr.fraction != 1.0 )
  {
    LOWORD(color) = -256;
    BYTE2(color) = 0;
    C_TestTraceline::DrawCube(
      this: v4,
      a2: 0,
      a3: (int)v4,
      a4: (int)v15,
      center: &tr.endpos,
      pColor: (unsigned __int8 *)&color);
  }
  if ( !tr.allsolid && tr.fractionleftsolid != 0.0 )
  {
    LOWORD(color) = 255;
    BYTE2(color) = 0;
    C_TestTraceline::DrawCube(
      this: v4,
      a2: 0,
      a3: (int)v4,
      a4: (int)v15,
      center: &tr.startpos,
      pColor: (unsigned __int8 *)&color);
  }
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042CEE0
// Name: DT_TestTraceline::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TestTraceline::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TestTraceline::g_RecvTable);
  return atexit(func: DT_TestTraceline::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CF00
// Name: DT_TestTraceline::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TestTraceline::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TestTraceline::ignored>();
  DT_TestTraceline::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436F30
// Name: DT_TestTraceline::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TestTraceline::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TestTraceline::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100378F0
// Name: _C_BaseDoor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseDoor_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9B8u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3[608] = -1;
  *v3 = &C_BaseDoor::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseDoor::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseDoor::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseDoor::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseDoor::`vftable';
  v3[620] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1005EE50
// Name: _C_BaseToggle_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseToggle_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9B0u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_BaseToggle::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseToggle::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseToggle::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseToggle::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseToggle::`vftable';
  v3[608] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10069C80
// Name: _C_EnvScreenOverlay_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvScreenOverlay_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x13B8u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_EnvScreenOverlay::`vftable'{for `IClientUnknown'};
  v3[1] = &C_EnvScreenOverlay::`vftable'{for `IClientRenderable'};
  v3[2] = &C_EnvScreenOverlay::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_EnvScreenOverlay::`vftable'{for `IClientThinkable'};
  v3[4] = &C_EnvScreenOverlay::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1006BBD0
// Name: _C_FuncAreaPortalWindow_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncAreaPortalWindow_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x990u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncAreaPortalWindow::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncAreaPortalWindow::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncAreaPortalWindow::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncAreaPortalWindow::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncAreaPortalWindow::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10070D30
// Name: _C_Func_LOD_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Func_LOD_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_Func_LOD::`vftable'{for `IClientUnknown'};
  v3[1] = &C_Func_LOD::`vftable'{for `IClientRenderable'};
  v3[2] = &C_Func_LOD::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_Func_LOD::`vftable'{for `IClientThinkable'};
  v3[4] = &C_Func_LOD::`vftable';
  v3[608] = 5000;
  v3[609] = 5800;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10070EA0
// Name: _C_FuncMonitor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncMonitor_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncMonitor::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncMonitor::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncMonitor::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncMonitor::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncMonitor::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100732D0
// Name: _C_FuncTrackTrain_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncTrackTrain_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x990u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncTrackTrain::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncTrackTrain::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncTrackTrain::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncTrackTrain::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncTrackTrain::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10081DF0
// Name: _C_RagdollManager_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_RagdollManager_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_RagdollManager::`vftable'{for `IClientUnknown'};
  v3[1] = &C_RagdollManager::`vftable'{for `IClientRenderable'};
  v3[2] = &C_RagdollManager::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_RagdollManager::`vftable'{for `IClientThinkable'};
  v3[4] = &C_RagdollManager::`vftable';
  v3[608] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101BF340
// Name: _C_CSTeam_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CSTeam_CreateObject(int entnum, int serialNum)
{
  C_Team *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_Team *)C_BaseEntity::operator new(stAllocateBlock: 0x9D0u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_Team::C_Team(this: v2);
  *v3 = &C_CSTeam::`vftable'{for `IClientUnknown'};
  v3[1] = &C_CSTeam::`vftable'{for `IClientRenderable'};
  v3[2] = &C_CSTeam::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_CSTeam::`vftable'{for `IClientThinkable'};
  v3[4] = &C_CSTeam::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101C65E0
// Name: _C_CSGameRulesProxy_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CSGameRulesProxy_CreateObject(int entnum, int serialNum)
{
  C_GameRulesProxy *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_GameRulesProxy *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_GameRulesProxy::C_GameRulesProxy(this: v2);
  *v3 = &C_CSGameRulesProxy::`vftable'{for `IClientUnknown'};
  v3[1] = &C_CSGameRulesProxy::`vftable'{for `IClientRenderable'};
  v3[2] = &C_CSGameRulesProxy::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_CSGameRulesProxy::`vftable'{for `IClientThinkable'};
  v3[4] = &C_CSGameRulesProxy::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10266670
// Name: _C_TestTraceline_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TestTraceline_CreateObject(int entnum, int serialNum)
{
  C_TestTraceline *v2; // eax
  C_TestTraceline *v3; // eax
  C_TestTraceline *v4; // esi

  v2 = (C_TestTraceline *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_TestTraceline::C_TestTraceline(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}
