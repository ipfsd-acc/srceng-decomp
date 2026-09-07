// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_worlddecal.cpp
// Functions: 283
// ============================================================

#include "game\server\te_worlddecal.h"

//------------------------------------------------------------------------------
// Address: 0x10023650
// Name: int ServerClassInit<struct DT_AI_BaseNPC::ignored>(struct DT_AI_BaseNPC::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_AI_BaseNPC::ignored>()
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    SendPropInt(
      result: g_SendProps,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCombatCharacter::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps[2],
      pVarName: "m_lifeState",
      offset: 553,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps[3], pVarName: "m_bPerformAvoidance", offset: 3684, sizeofVar: 1);
    SendPropBool(result: &g_SendProps[4], pVarName: "m_bIsMoving", offset: 3685, sizeofVar: 1);
    SendPropBool(result: &g_SendProps[5], pVarName: "m_bFadeCorpse", offset: 3686, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps[6],
      pVarName: "m_iDeathPose",
      offset: 2588,
      sizeofVar: 4,
      nBits: 12,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps[7],
      pVarName: "m_iDeathFrame",
      offset: 2592,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps[8], pVarName: "m_bSpeedModActive", offset: 3688, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps[9],
      pVarName: "m_iSpeedModRadius",
      offset: 3692,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps[10],
      pVarName: "m_iSpeedModSpeed",
      offset: 3696,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps[11], pVarName: "m_bImportanRagdoll", offset: 3687, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps[12],
      pVarName: "m_flTimePingEffect",
      offset: 3700,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_AI_BaseNPC::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_AI_BaseNPC::g_SendTable,
    pProps: &g_SendProps[1],
    nProps: 12,
    pNetTableName: g_pSendTableName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098070
// Name: int ServerClassInit<struct DT_BaseAnimating::ignored>(struct DT_BaseAnimating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseAnimating::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S4_9 & 1) == 0 )
  {
    _S4_9 |= 1u;
    SendPropInt(
      result: g_SendProps_0,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_0[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[2],
      pVarName: "m_nForceBone",
      offset: 860,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_0[3],
      pVarName: "m_vecForce",
      offset: 1049440,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[4],
      pVarName: "m_nSkin",
      offset: 876,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[5],
      pVarName: "m_nBody",
      offset: 880,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[6],
      pVarName: "m_nHitboxSet",
      offset: 884,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_0[7],
      pVarName: "m_flModelScale",
      offset: 888,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flPoseParameter",
      offset: 948,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_0[8],
      pVarName: "m_flPoseParameter",
      offset: 948,
      sizeofVar: 4,
      elements: 24,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_0[9],
      pVarName: "m_nSequence",
      offset: 944,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_0[10],
      pVarName: "m_flPlaybackRate",
      offset: 892,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: -4.0,
      fHighValue: 12.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flEncodedController",
      offset: 1044,
      sizeofVar: 4,
      nBits: 11,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_0[11],
      pVarName: "m_flEncodedController",
      offset: 1044,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_0[12],
      pVarName: "m_bClientSideAnimation",
      offset: 1060,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[13],
      pVarName: "m_bClientSideFrameReset",
      offset: 1061,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_0[14], pVarName: "m_bClientSideRagdoll", offset: 552, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_0[15], pVarName: "m_bForceRTTShadows", offset: 896, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_0[16],
      pVarName: "m_nNewSequenceParity",
      offset: 1064,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[17],
      pVarName: "m_nResetEventsParity",
      offset: 1068,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[18],
      pVarName: "m_nMuzzleFlashParity",
      offset: 1073,
      sizeofVar: 1,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_0[19],
      pVarName: "m_hLightingOrigin",
      offset: 1076,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropDataTable(
      result: &g_SendProps_0[20],
      pVarName: "serveranimdata",
      offset: 0,
      pTable: &DT_ServerAnimationData::g_SendTable,
      varProxy: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_ClientSideAnimation,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_0[21],
      pVarName: "m_flFrozen",
      offset: 1100,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_0[22],
      pVarName: "m_ScaleType",
      offset: 900,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_0[23], pVarName: "m_bSuppressAnimSounds", offset: 1072, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_BaseAnimating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseAnimating::g_SendTable,
    pProps: &g_SendProps_0[1],
    nProps: 23,
    pNetTableName: g_pSendTableName_0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10098CF0
// Name: int ServerClassInit<struct DT_ServerAnimationData::ignored>(struct DT_ServerAnimationData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ServerAnimationData::ignored>()
{
  if ( (_S3_21 & 1) == 0 )
  {
    _S3_21 |= 1u;
    SendPropInt(
      result: g_SendProps_1,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_1[1],
      pVarName: "m_flCycle",
      offset: 940,
      sizeofVar: 4,
      nBits: 15,
      flags: 262152,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ServerAnimationData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ServerAnimationData::g_SendTable,
    pProps: &g_SendProps_1[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009F050
// Name: int ServerClassInit<struct DT_BaseAnimatingOverlay::ignored>(struct DT_BaseAnimatingOverlay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseAnimatingOverlay::ignored>()
{
  if ( (_S6_3 & 1) == 0 )
  {
    _S6_3 |= 1u;
    SendPropInt(
      result: g_SendProps_2,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_2[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_2[2],
      pVarName: "overlay_vars",
      offset: 0,
      pTable: &DT_OverlayVars::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseAnimatingOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseAnimatingOverlay::g_SendTable,
    pProps: &g_SendProps_2[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009F0F0
// Name: int ServerClassInit<struct DT_Animationlayer::ignored>(struct DT_Animationlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Animationlayer::ignored>()
{
  if ( (_S4_10 & 1) == 0 )
  {
    _S4_10 |= 1u;
    SendPropInt(
      result: g_SendProps_3,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_3[1],
      pVarName: "m_nSequence",
      offset: 8,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_3[2],
      pVarName: "m_flCycle",
      offset: 12,
      sizeofVar: 4,
      nBits: 15,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_3[3],
      pVarName: "m_flPrevCycle",
      offset: 16,
      sizeofVar: 4,
      nBits: 15,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_3[4],
      pVarName: "m_flWeight",
      offset: 20,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_3[5],
      pVarName: "m_nOrder",
      offset: 60,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Animationlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Animationlayer::g_SendTable,
    pProps: &g_SendProps_3[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009F9E0
// Name: int ServerClassInit<struct DT_OverlayVars::ignored>(struct DT_OverlayVars::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_OverlayVars::ignored>()
{
  SendProp v1; // [esp-58h] [ebp-58h] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp-4h] [ebp-4h]

  if ( (_S5_5 & 1) == 0 )
  {
    _S5_5 |= 1u;
    SendPropInt(
      result: g_SendProps_4,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    v2 = SendProxy_DataTableToDataTable;
    SendPropDataTable(
      result: &v1,
      pVarName: nullptr,
      offset: 0,
      pTable: &DT_Animationlayer::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropUtlVector(
      result: &g_SendProps_4[1],
      pVarName: "m_AnimOverlay",
      offset: 1164,
      sizeofVar: 76,
      ensureFn: UtlVectorTemplate<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::EnsureCapacity,
      nMaxElements: 15,
      pArrayProp: v1,
      varProxy: v2);
    atexit(func: ServerClassInit_DT_OverlayVars::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_OverlayVars::g_SendTable,
    pProps: &g_SendProps_4[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A32F0
// Name: int ServerClassInit<struct DT_BCCLocalPlayerExclusive::ignored>(struct DT_BCCLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BCCLocalPlayerExclusive::ignored>()
{
  SendProp v1; // [esp-5Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  if ( (_S4_11 & 1) == 0 )
  {
    _S4_11 |= 1u;
    SendPropInt(
      result: g_SendProps_5,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_5[1], pVarName: "m_flNextAttack", offset: 1668, sizeofVar: 4);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropEHandle(
      result: &v1,
      pVarName: "m_hMyWeapons",
      offset: 1940,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropArray3(
      result: &g_SendProps_5[2],
      pVarName: "m_hMyWeapons",
      offset: 1940,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    atexit(func: ServerClassInit_DT_BCCLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BCCLocalPlayerExclusive::g_SendTable,
    pProps: &g_SendProps_5[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A5BE0
// Name: int ServerClassInit<struct DT_BaseCombatCharacter::ignored>(struct DT_BaseCombatCharacter::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseCombatCharacter::ignored>()
{
  if ( (_S5_6 & 1) == 0 )
  {
    _S5_6 |= 1u;
    SendPropInt(
      result: g_SendProps_6,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_6[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseFlex::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_6[2],
      pVarName: "bcc_localdata",
      offset: 0,
      pTable: &DT_BCCLocalPlayerExclusive::g_SendTable,
      varProxy: SendProxy_SendBaseCombatCharacterLocalDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_6[3],
      pVarName: "m_hActiveWeapon",
      offset: 2196,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_BaseCombatCharacter::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseCombatCharacter::g_SendTable,
    pProps: &g_SendProps_6[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AE2A0
// Name: int ServerClassInit<struct DT_LocalWeaponData::ignored>(struct DT_LocalWeaponData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_LocalWeaponData::ignored>()
{
  if ( (_S5_7 & 1) == 0 )
  {
    _S5_7 |= 1u;
    SendPropInt(
      result: g_SendProps_7,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropIntWithMinusOneFlag(
      result: &g_SendProps_7[1],
      pVarName: "m_iClip1",
      offset: 1200,
      sizeofVar: 4,
      nBits: 8,
      proxyFn: SendProxy_IntAddOne);
    SendPropIntWithMinusOneFlag(
      result: &g_SendProps_7[2],
      pVarName: "m_iClip2",
      offset: 1204,
      sizeofVar: 4,
      nBits: 8,
      proxyFn: SendProxy_IntAddOne);
    SendPropInt(
      result: &g_SendProps_7[3],
      pVarName: "m_iPrimaryAmmoType",
      offset: 1192,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_7[4],
      pVarName: "m_iSecondaryAmmoType",
      offset: 1196,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_7[5],
      pVarName: "m_nViewModelIndex",
      offset: 1168,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_7[6],
      pVarName: "m_bFlipViewModel",
      offset: 1280,
      sizeofVar: 1,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_LocalWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_LocalWeaponData::g_SendTable,
    pProps: &g_SendProps_7[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AE640
// Name: int ServerClassInit<struct DT_LocalActiveWeaponData::ignored>(struct DT_LocalActiveWeaponData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_LocalActiveWeaponData::ignored>()
{
  if ( (_S4_12 & 1) == 0 )
  {
    _S4_12 |= 1u;
    SendPropInt(
      result: g_SendProps_8,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_8[1], pVarName: "m_flNextPrimaryAttack", offset: 1172, sizeofVar: 4);
    SendPropTime(result: &g_SendProps_8[2], pVarName: "m_flNextSecondaryAttack", offset: 1176, sizeofVar: 4);
    SendPropInt(
      result: &g_SendProps_8[3],
      pVarName: "m_nNextThinkTick",
      offset: 160,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_8[4], pVarName: "m_flTimeWeaponIdle", offset: 1208, sizeofVar: 4);
    atexit(func: ServerClassInit_DT_LocalActiveWeaponData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_LocalActiveWeaponData::g_SendTable,
    pProps: &g_SendProps_8[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AF880
// Name: int ServerClassInit<struct DT_BaseCombatWeapon::ignored>(struct DT_BaseCombatWeapon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseCombatWeapon::ignored>()
{
  if ( (_S6_5 & 1) == 0 )
  {
    _S6_5 |= 1u;
    SendPropInt(
      result: g_SendProps_9,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_9[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_9[2],
      pVarName: "LocalWeaponData",
      offset: 0,
      pTable: &DT_LocalWeaponData::g_SendTable,
      varProxy: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendLocalWeaponDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_9[3],
      pVarName: "LocalActiveWeaponData",
      offset: 0,
      pTable: &DT_LocalActiveWeaponData::g_SendTable,
      varProxy: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendLocalWeaponDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_9[4],
      pVarName: "m_iViewModelIndex",
      offset: 1180,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_9[5],
      pVarName: "m_iWorldModelIndex",
      offset: 1184,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_9[6],
      pVarName: "m_iState",
      offset: 1188,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_9[7],
      pVarName: "m_hOwner",
      offset: 1164,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_BaseCombatWeapon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseCombatWeapon::g_SendTable,
    pProps: &g_SendProps_9[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B78D0
// Name: int ServerClassInit<struct DT_AnimTimeMustBeFirst::ignored>(struct DT_AnimTimeMustBeFirst::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_AnimTimeMustBeFirst::ignored>()
{
  if ( (_S2_49 & 1) == 0 )
  {
    _S2_49 |= 1u;
    SendPropInt(
      result: g_SendProps_10,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_10[1],
      pVarName: "m_flAnimTime",
      offset: 100,
      sizeofVar: 4,
      nBits: 8,
      flags: 786433,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_AnimTime,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_AnimTimeMustBeFirst::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_AnimTimeMustBeFirst::g_SendTable,
    pProps: &g_SendProps_10[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B7EE0
// Name: int ServerClassInit<struct DT_BaseEntity::ignored>(struct DT_BaseEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseEntity::ignored>()
{
  if ( (_S3_25 & 1) == 0 )
  {
    _S3_25 |= 1u;
    SendPropInt(
      result: g_SendProps_11,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_11[1],
      pVarName: "AnimTimeMustBeFirst",
      offset: 0,
      pTable: &DT_AnimTimeMustBeFirst::g_SendTable,
      varProxy: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_ClientSideAnimation,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[2],
      pVarName: "m_flSimulationTime",
      offset: 104,
      sizeofVar: 4,
      nBits: 8,
      flags: 786433,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_SimulationTime,
      priority: 0);
    SendPropInt(
      result: &g_SendProps_11[3],
      pVarName: "m_cellbits",
      offset: 684,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x20u);
    SendPropInt(
      result: &g_SendProps_11[4],
      pVarName: "m_cellX",
      offset: 688,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellX,
      priority: 0x20u);
    SendPropInt(
      result: &g_SendProps_11[5],
      pVarName: "m_cellY",
      offset: 692,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellY,
      priority: 0x20u);
    SendPropInt(
      result: &g_SendProps_11[6],
      pVarName: "m_cellZ",
      offset: 696,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellZ,
      priority: 0x20u);
    SendPropVector(
      result: &g_SendProps_11[7],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: 5,
      flags: 294912,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellOrigin,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[8],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_11[9],
      pVarName: "m_Collision",
      offset: 228,
      pTable: &DT_CollisionProperty::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[10],
      pVarName: "m_nRenderFX",
      offset: 180,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[11],
      pVarName: "m_nRenderMode",
      offset: 181,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[12],
      pVarName: "m_fEffects",
      offset: 164,
      sizeofVar: 4,
      nBits: 14,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[13],
      pVarName: "m_clrRender",
      offset: 184,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[14],
      pVarName: "m_iTeamNum",
      offset: 756,
      sizeofVar: 4,
      nBits: 6,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[15],
      pVarName: "m_CollisionGroup",
      offset: 324,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_11[16],
      pVarName: "m_flElasticity",
      offset: 440,
      sizeofVar: 4,
      nBits: 0,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_11[17],
      pVarName: "m_flShadowCastDistance",
      offset: 788,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_11[18],
      pVarName: "m_hOwnerEntity",
      offset: 320,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_11[19],
      pVarName: "m_hEffectEntity",
      offset: 772,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_11[20],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_11[21],
      pVarName: "m_iParentAttachment",
      offset: 213,
      sizeofVar: 1,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropStringT(result: &g_SendProps_11[22], pVarName: "m_iName", offset: 204, sizeofVar: 4);
    SendPropInt(
      result: &g_SendProps_11[23],
      pVarName: "movetype",
      offset: 214,
      sizeofVar: 1,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[24],
      pVarName: "movecollide",
      offset: 215,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_11[25],
      pVarName: "m_angRotation",
      offset: 3146440,
      sizeofVar: 12,
      nBits: 13,
      flags: 0x40000,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Angles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[26],
      pVarName: "m_iTextureFrameIndex",
      offset: 500,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[27],
      pVarName: "m_bSimulatedEveryTick",
      offset: 501,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[28],
      pVarName: "m_bAnimatedEveryTick",
      offset: 502,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_11[29], pVarName: "m_bAlternateSorting", offset: 503, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_11[30],
      pVarName: "m_fadeMinDist",
      offset: 776,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_11[31],
      pVarName: "m_fadeMaxDist",
      offset: 780,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_11[32],
      pVarName: "m_flFadeScale",
      offset: 784,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[33],
      pVarName: "m_nMinCPULevel",
      offset: 504,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[34],
      pVarName: "m_nMaxCPULevel",
      offset: 505,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[35],
      pVarName: "m_nMinGPULevel",
      offset: 506,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_11[36],
      pVarName: "m_nMaxGPULevel",
      offset: 507,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseEntity::g_SendTable,
    pProps: &g_SendProps_11[1],
    nProps: 36,
    pNetTableName: g_pSendTableName_11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CFAB0
// Name: int ServerClassInit<struct DT_BaseFlex::ignored>(struct DT_BaseFlex::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseFlex::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S2_50 & 1) == 0 )
  {
    _S2_50 |= 1u;
    SendPropInt(
      result: g_SendProps_12,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_12[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimatingOverlay::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flexWeight",
      offset: 1184,
      sizeofVar: 4,
      nBits: 12,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_12[2],
      pVarName: "m_flexWeight",
      offset: 1184,
      sizeofVar: 4,
      elements: 96,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_12[3],
      pVarName: "m_blinktoggle",
      offset: 1580,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_12[4],
      pVarName: "m_viewtarget",
      offset: 1050144,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseFlex::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseFlex::g_SendTable,
    pProps: &g_SendProps_12[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5BB0
// Name: int ServerClassInit<struct DT_BaseGrenade::ignored>(struct DT_BaseGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseGrenade::ignored>()
{
  if ( (_S3_27 & 1) == 0 )
  {
    _S3_27 |= 1u;
    SendPropInt(
      result: g_SendProps_13,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_13[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_13[2],
      pVarName: "m_flDamage",
      offset: 1188,
      sizeofVar: 4,
      nBits: 10,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 256.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_13[3],
      pVarName: "m_DmgRadius",
      offset: 1172,
      sizeofVar: 4,
      nBits: 10,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_13[4],
      pVarName: "m_bIsLive",
      offset: 1169,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_13[5],
      pVarName: "m_hThrower",
      offset: 1196,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropVector(
      result: &g_SendProps_13[6],
      pVarName: "m_vecVelocity",
      offset: 3146212,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_13[7],
      pVarName: "m_fFlags",
      offset: 200,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: SendProxy_CropFlagsToPlayerFlagBitsLength,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseGrenade::g_SendTable,
    pProps: &g_SendProps_13[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_13);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D7FC0
// Name: int ServerClassInit<struct DT_BaseParticleEntity::ignored>(struct DT_BaseParticleEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseParticleEntity::ignored>()
{
  if ( (_S2_52 & 1) == 0 )
  {
    _S2_52 |= 1u;
    SendPropInt(
      result: g_SendProps_14,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_14[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseParticleEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseParticleEntity::g_SendTable,
    pProps: &g_SendProps_14[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DD6B0
// Name: int ServerClassInit<struct DT_BaseViewModel::ignored>(struct DT_BaseViewModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseViewModel::ignored>()
{
  if ( (_S2_55 & 1) == 0 )
  {
    _S2_55 |= 1u;
    SendPropInt(
      result: g_SendProps_15,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[1],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_15[2],
      pVarName: "m_hWeapon",
      offset: 1188,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_15[3],
      pVarName: "m_nBody",
      offset: 880,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[4],
      pVarName: "m_nSkin",
      offset: 876,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[5],
      pVarName: "m_nSequence",
      offset: 944,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[6],
      pVarName: "m_nViewModelIndex",
      offset: 1180,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_15[7],
      pVarName: "m_flPlaybackRate",
      offset: 892,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: -4.0,
      fHighValue: 12.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[8],
      pVarName: "m_fEffects",
      offset: 164,
      sizeofVar: 4,
      nBits: 14,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[9],
      pVarName: "m_nAnimationParity",
      offset: 1184,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_15[10],
      pVarName: "m_hOwner",
      offset: 1192,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_15[11],
      pVarName: "m_nNewSequenceParity",
      offset: 1064,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[12],
      pVarName: "m_nResetEventsParity",
      offset: 1068,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_15[13],
      pVarName: "m_nMuzzleFlashParity",
      offset: 1073,
      sizeofVar: 1,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseViewModel::g_SendTable,
    pProps: &g_SendProps_15[1],
    nProps: 13,
    pNetTableName: g_pSendTableName_15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DE680
// Name: int ServerClassInit<struct DT_Beam::ignored>(struct DT_Beam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Beam::ignored>()
{
  unsigned int v0; // eax
  SendProp v2; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v3)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  if ( (_S2_56 & 1) == 0 )
  {
    _S2_56 |= 1u;
    SendPropInt(
      result: g_SendProps_16,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    v0 = Q_log2(val: 6u);
    SendPropInt(
      result: &g_SendProps_16[1],
      pVarName: "m_nBeamType",
      offset: 876,
      sizeofVar: 4,
      nBits: v0 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[2],
      pVarName: "m_nBeamFlags",
      offset: 880,
      sizeofVar: 4,
      nBits: 17,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[3],
      pVarName: "m_nNumBeamEnts",
      offset: 868,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropEHandle(
      result: &v2,
      pVarName: "m_hAttachEntity",
      offset: 884,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropArray3(
      result: &g_SendProps_16[4],
      pVarName: "m_hAttachEntity",
      offset: 884,
      sizeofVar: 4,
      elements: 10,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v2,
      pVarName: "m_nAttachIndex",
      offset: 924,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_16[5],
      pVarName: "m_nAttachIndex",
      offset: 924,
      sizeofVar: 4,
      elements: 10,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    SendPropInt(
      result: &g_SendProps_16[6],
      pVarName: "m_nHaloIndex",
      offset: 872,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[7],
      pVarName: "m_fHaloScale",
      offset: 976,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[8],
      pVarName: "m_fWidth",
      offset: 964,
      sizeofVar: 4,
      nBits: 10,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 102.3,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[9],
      pVarName: "m_fEndWidth",
      offset: 968,
      sizeofVar: 4,
      nBits: 10,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 102.3,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[10],
      pVarName: "m_fFadeLength",
      offset: 972,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[11],
      pVarName: "m_fAmplitude",
      offset: 980,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 64.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[12],
      pVarName: "m_fStartFrame",
      offset: 984,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 256.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[13],
      pVarName: "m_fSpeed",
      offset: 988,
      sizeofVar: 4,
      nBits: 8,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[14],
      pVarName: "m_nRenderFX",
      offset: 180,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[15],
      pVarName: "m_nRenderMode",
      offset: 181,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[16],
      pVarName: "m_flFrameRate",
      offset: 852,
      sizeofVar: 4,
      nBits: 10,
      flags: 16,
      fLowValue: -25.0,
      fHighValue: 25.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[17],
      pVarName: "m_flHDRColorScale",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_16[18],
      pVarName: "m_flFrame",
      offset: 992,
      sizeofVar: 4,
      nBits: 20,
      flags: 262152,
      fLowValue: 0.0,
      fHighValue: 256.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[19],
      pVarName: "m_clrRender",
      offset: 184,
      sizeofVar: 4,
      nBits: 32,
      flags: 262145,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[20],
      pVarName: "m_nClipStyle",
      offset: 996,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_16[21],
      pVarName: "m_vecEndPos",
      offset: 1049576,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_16[22],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_16[23],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: 19,
      flags: 0x40000,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_16[24],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_Beam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Beam::g_SendTable,
    pProps: &g_SendProps_16[1],
    nProps: 24,
    pNetTableName: g_pSendTableName_16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E0280
// Name: int ServerClassInit<struct DT_BeamSpotlight::ignored>(struct DT_BeamSpotlight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BeamSpotlight::ignored>()
{
  if ( (_S3_29 & 1) == 0 )
  {
    _S3_29 |= 1u;
    SendPropInt(
      result: g_SendProps_17,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_17[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_17[2],
      pVarName: "m_nHaloIndex",
      offset: 852,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_17[3], pVarName: "m_bSpotlightOn", offset: 856, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_17[4], pVarName: "m_bHasDynamicLight", offset: 857, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_17[5],
      pVarName: "m_flSpotlightMaxLength",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_17[6],
      pVarName: "m_flSpotlightGoalWidth",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_17[7],
      pVarName: "m_flHDRColorScale",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_17[8],
      pVarName: "m_flRotationSpeed",
      offset: 880,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_17[9],
      pVarName: "m_nRotationAxis",
      offset: 876,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BeamSpotlight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BeamSpotlight::g_SendTable,
    pProps: &g_SendProps_17[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_17);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1360
// Name: int ServerClassInit<struct DT_FuncConveyor::ignored>(struct DT_FuncConveyor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncConveyor::ignored>()
{
  if ( (_S6_8 & 1) == 0 )
  {
    _S6_8 |= 1u;
    SendPropInt(
      result: g_SendProps_18,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_18[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_18[2],
      pVarName: "m_flConveyorSpeed",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncConveyor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncConveyor::g_SendTable,
    pProps: &g_SendProps_18[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1480
// Name: int ServerClassInit<struct DT_FuncRotating::ignored>(struct DT_FuncRotating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncRotating::ignored>()
{
  if ( (_S8_1 & 1) == 0 )
  {
    _S8_1 |= 1u;
    SendPropInt(
      result: g_SendProps_19,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_19[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_19[2], pDataTableName: "DT_BaseEntity", pPropName: "m_angRotation");
    SendPropExclude(result: &g_SendProps_19[3], pDataTableName: "DT_BaseEntity", pPropName: "m_vecOrigin");
    SendPropExclude(result: &g_SendProps_19[4], pDataTableName: "DT_BaseEntity", pPropName: "m_flSimulationTime");
    SendPropVector(
      result: &g_SendProps_19[5],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 262146,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FuncRotatingOrigin,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_19[6],
      pVarName: "m_angRotation[0]",
      offset: 3146440,
      sizeofVar: 4,
      nBits: 13,
      flags: 0x40000,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_19[7],
      pVarName: "m_angRotation[1]",
      offset: 3146444,
      sizeofVar: 4,
      nBits: 13,
      flags: 0x40000,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_19[8],
      pVarName: "m_angRotation[2]",
      offset: 3146448,
      sizeofVar: 4,
      nBits: 13,
      flags: 0x40000,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_19[9],
      pVarName: "m_flSimulationTime",
      offset: 104,
      sizeofVar: 4,
      nBits: 8,
      flags: 786433,
      varProxy: SendProxy_FuncRotatingSimulationTime,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncRotating::g_SendTable,
    pProps: &g_SendProps_19[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_19);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E4200
// Name: int ServerClassInit<struct DT_BaseButton::ignored>(struct DT_BaseButton::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseButton::ignored>()
{
  if ( (_S3_31 & 1) == 0 )
  {
    _S3_31 |= 1u;
    SendPropInt(
      result: g_SendProps_20,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_20[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseToggle::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseButton::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseButton::g_SendTable,
    pProps: &g_SendProps_20[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_20);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EE3F0
// Name: int ServerClassInit<struct DT_CollisionProperty::ignored>(struct DT_CollisionProperty::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CollisionProperty::ignored>()
{
  if ( (_S3_34 & 1) == 0 )
  {
    _S3_34 |= 1u;
    SendPropInt(
      result: g_SendProps_21,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_21[1],
      pVarName: "m_vecMins",
      offset: 1048584,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_21[2],
      pVarName: "m_vecMaxs",
      offset: 1048596,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_21[3],
      pVarName: "m_nSolidType",
      offset: 34,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: SendProxy_Solid,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_21[4],
      pVarName: "m_usSolidFlags",
      offset: 32,
      sizeofVar: 2,
      nBits: 12,
      flags: 1,
      varProxy: SendProxy_SolidFlags,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_21[5],
      pVarName: "m_nSurroundType",
      offset: 42,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_21[6],
      pVarName: "m_triggerBloat",
      offset: 35,
      sizeofVar: 1,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_21[7],
      pVarName: "m_vecSpecifiedSurroundingMins",
      offset: 1048620,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_21[8],
      pVarName: "m_vecSpecifiedSurroundingMaxs",
      offset: 1048632,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CollisionProperty::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CollisionProperty::g_SendTable,
    pProps: &g_SendProps_21[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_21);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F2B40
// Name: int ServerClassInit<struct DT_ColorCorrection::ignored>(struct DT_ColorCorrection::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ColorCorrection::ignored>()
{
  if ( (_S3_35 & 1) == 0 )
  {
    _S3_35 |= 1u;
    SendPropInt(
      result: g_SendProps_22,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_22[1],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Origin,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[2],
      pVarName: "m_MinFalloff",
      offset: 888,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[3],
      pVarName: "m_MaxFalloff",
      offset: 892,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[4],
      pVarName: "m_flCurWeight",
      offset: 896,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[5],
      pVarName: "m_flMaxWeight",
      offset: 876,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[6],
      pVarName: "m_flFadeInDuration",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_22[7],
      pVarName: "m_flFadeOutDuration",
      offset: 856,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_22[8],
      pVarName: "m_netlookupFilename",
      offset: 900,
      bufferLen: 260,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_22[9], pVarName: "m_bEnabled", offset: 881, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_22[10], pVarName: "m_bMaster", offset: 882, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_22[11], pVarName: "m_bClientSide", offset: 883, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_22[12], pVarName: "m_bExclusive", offset: 884, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_ColorCorrection::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ColorCorrection::g_SendTable,
    pProps: &g_SendProps_22[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_22);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F4640
// Name: int ServerClassInit<struct DT_ColorCorrectionVolume::ignored>(struct DT_ColorCorrectionVolume::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ColorCorrectionVolume::ignored>()
{
  if ( (_S3_36 & 1) == 0 )
  {
    _S3_36 |= 1u;
    SendPropInt(
      result: g_SendProps_23,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_23[1],
      pVarName: "m_Weight",
      offset: 1156,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_23[2],
      pVarName: "m_lookupFilename",
      offset: 1164,
      bufferLen: 260,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ColorCorrectionVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ColorCorrectionVolume::g_SendTable,
    pProps: &g_SendProps_23[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_23);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F58F0
// Name: int ServerClassInit<struct DT_PointCommentaryNode::ignored>(struct DT_PointCommentaryNode::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PointCommentaryNode::ignored>()
{
  if ( (_S3_37 & 1) == 0 )
  {
    _S3_37 |= 1u;
    SendPropInt(
      result: g_SendProps_24,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_24[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_24[2], pVarName: "m_bActive", offset: 1312, sizeofVar: 1);
    SendPropStringT(result: &g_SendProps_24[3], pVarName: "m_iszCommentaryFile", offset: 1172, sizeofVar: 4);
    SendPropStringT(result: &g_SendProps_24[4], pVarName: "m_iszCommentaryFileNoHDR", offset: 1176, sizeofVar: 4);
    SendPropTime(result: &g_SendProps_24[5], pVarName: "m_flStartTime", offset: 1316, sizeofVar: 4);
    SendPropStringT(result: &g_SendProps_24[6], pVarName: "m_iszSpeakers", offset: 1320, sizeofVar: 4);
    SendPropInt(
      result: &g_SendProps_24[7],
      pVarName: "m_iNodeNumber",
      offset: 1324,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_24[8],
      pVarName: "m_iNodeNumberMax",
      offset: 1328,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_24[9],
      pVarName: "m_hViewPosition",
      offset: 1196,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_PointCommentaryNode::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PointCommentaryNode::g_SendTable,
    pProps: &g_SendProps_24[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FF5C0
// Name: int ServerClassInit<struct DT_BaseDoor::ignored>(struct DT_BaseDoor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseDoor::ignored>()
{
  if ( (_S3_39 & 1) == 0 )
  {
    _S3_39 |= 1u;
    SendPropInt(
      result: g_SendProps_25,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_25[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseToggle::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_25[2],
      pVarName: "m_flWaveHeight",
      offset: 1060,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 8.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseDoor::g_SendTable,
    pProps: &g_SendProps_25[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_25);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101039D0
// Name: int ServerClassInit<struct DT_DynamicLight::ignored>(struct DT_DynamicLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DynamicLight::ignored>()
{
  if ( (_S3_40 & 1) == 0 )
  {
    _S3_40 |= 1u;
    SendPropInt(
      result: g_SendProps_26,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_26[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_26[2],
      pVarName: "m_Flags",
      offset: 853,
      sizeofVar: 1,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_26[3],
      pVarName: "m_LightStyle",
      offset: 854,
      sizeofVar: 1,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_26[4],
      pVarName: "m_Radius",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_26[5],
      pVarName: "m_Exponent",
      offset: 860,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_26[6],
      pVarName: "m_InnerAngle",
      offset: 864,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 360.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_26[7],
      pVarName: "m_OuterAngle",
      offset: 868,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 360.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_26[8],
      pVarName: "m_SpotRadius",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_DynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DynamicLight::g_SendTable,
    pProps: &g_SendProps_26[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_26);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10104870
// Name: int ServerClassInit<struct DT_EffectData::ignored>(struct DT_EffectData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EffectData::ignored>()
{
  if ( (_S2_72 & 1) == 0 )
  {
    _S2_72 |= 1u;
    SendPropInt(
      result: g_SendProps_27,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[1],
      pVarName: "m_vOrigin.x",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[2],
      pVarName: "m_vOrigin.y",
      offset: 4,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[3],
      pVarName: "m_vOrigin.z",
      offset: 8,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[4],
      pVarName: "m_vStart.x",
      offset: 12,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[5],
      pVarName: "m_vStart.y",
      offset: 16,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[6],
      pVarName: "m_vStart.z",
      offset: 20,
      sizeofVar: 4,
      nBits: -1,
      flags: 0x4000,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_27[7],
      pVarName: "m_vAngles",
      offset: 36,
      sizeofVar: 12,
      nBits: 7,
      flags: 0,
      varProxy: SendProxy_QAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_27[8],
      pVarName: "m_vNormal",
      offset: 24,
      sizeofVar: 12,
      nBits: 0,
      flags: 32,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[9],
      pVarName: "m_fFlags",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[10],
      pVarName: "m_flMagnitude",
      offset: 60,
      sizeofVar: 4,
      nBits: 12,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1023.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[11],
      pVarName: "m_flScale",
      offset: 56,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[12],
      pVarName: "m_nAttachmentIndex",
      offset: 68,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropIntWithMinusOneFlag(
      result: &g_SendProps_27[13],
      pVarName: "m_nSurfaceProp",
      offset: 72,
      sizeofVar: 2,
      nBits: 8,
      proxyFn: SendProxy_ShortAddOne);
    SendPropInt(
      result: &g_SendProps_27[14],
      pVarName: "m_iEffectName",
      offset: 96,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[15],
      pVarName: "m_nMaterial",
      offset: 76,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[16],
      pVarName: "m_nDamageType",
      offset: 80,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[17],
      pVarName: "m_nHitBox",
      offset: 84,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[18],
      pVarName: "entindex",
      offset: 52,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[19],
      pVarName: "m_nOtherEntIndex",
      offset: 88,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_27[20],
      pVarName: "m_nColor",
      offset: 92,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_27[21],
      pVarName: "m_flRadius",
      offset: 64,
      sizeofVar: 4,
      nBits: 10,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1023.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EffectData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EffectData::g_SendTable,
    pProps: &g_SendProps_27[1],
    nProps: 21,
    pNetTableName: g_pSendTableName_27);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105820
// Name: int ServerClassInit<struct DT_PrecipitationBlocker::ignored>(struct DT_PrecipitationBlocker::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PrecipitationBlocker::ignored>()
{
  if ( (_S14 & 1) == 0 )
  {
    _S14 |= 1u;
    SendPropInt(
      result: g_SendProps_28,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_28[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PrecipitationBlocker::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PrecipitationBlocker::g_SendTable,
    pProps: &g_SendProps_28[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_28);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101058A0
// Name: int ServerClassInit<struct DT_EnvWindShared::ignored>(struct DT_EnvWindShared::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvWindShared::ignored>()
{
  if ( (_S17 & 1) == 0 )
  {
    _S17 |= 1u;
    SendPropInt(
      result: g_SendProps_29,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[1],
      pVarName: "m_iMinWind",
      offset: 12,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[2],
      pVarName: "m_iMaxWind",
      offset: 16,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[3],
      pVarName: "m_iMinGust",
      offset: 24,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[4],
      pVarName: "m_iMaxGust",
      offset: 28,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_29[5],
      pVarName: "m_flMinGustDelay",
      offset: 32,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_29[6],
      pVarName: "m_flMaxGustDelay",
      offset: 36,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[7],
      pVarName: "m_iGustDirChange",
      offset: 44,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[8],
      pVarName: "m_iWindSeed",
      offset: 8,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_29[9],
      pVarName: "m_iInitialWindDir",
      offset: 108,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_29[10],
      pVarName: "m_flInitialWindSpeed",
      offset: 112,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_29[11],
      pVarName: "m_flStartTime",
      offset: 4,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_29[12],
      pVarName: "m_flGustDuration",
      offset: 40,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvWindShared::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvWindShared::g_SendTable,
    pProps: &g_SendProps_29[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_29);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105B10
// Name: int ServerClassInit<struct DT_EnvWind::ignored>(struct DT_EnvWind::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvWind::ignored>()
{
  if ( (_S18 & 1) == 0 )
  {
    _S18 |= 1u;
    SendPropInt(
      result: g_SendProps_30,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_30[1],
      pVarName: "m_EnvWindShared",
      offset: 852,
      pTable: &DT_EnvWindShared::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvWind::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvWind::g_SendTable,
    pProps: &g_SendProps_30[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_30);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105B90
// Name: int ServerClassInit<struct DT_Embers::ignored>(struct DT_Embers::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Embers::ignored>()
{
  if ( (_S20 & 1) == 0 )
  {
    _S20 |= 1u;
    SendPropInt(
      result: g_SendProps_31,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_31[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_31[2],
      pVarName: "m_nDensity",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_31[3],
      pVarName: "m_nLifetime",
      offset: 856,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_31[4],
      pVarName: "m_nSpeed",
      offset: 860,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_31[5],
      pVarName: "m_bEmit",
      offset: 864,
      sizeofVar: 1,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Embers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Embers::g_SendTable,
    pProps: &g_SendProps_31[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_31);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105D70
// Name: int ServerClassInit<struct DT_QuadraticBeam::ignored>(struct DT_QuadraticBeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_QuadraticBeam::ignored>()
{
  if ( (_S26 & 1) == 0 )
  {
    _S26 |= 1u;
    SendPropInt(
      result: g_SendProps_32,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_32[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_32[2],
      pVarName: "m_targetPosition",
      offset: 1049428,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_32[3],
      pVarName: "m_controlPosition",
      offset: 1049440,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_32[4],
      pVarName: "m_scrollRate",
      offset: 876,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: -4.0,
      fHighValue: 4.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_32[5],
      pVarName: "m_flWidth",
      offset: 880,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_QuadraticBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_QuadraticBeam::g_SendTable,
    pProps: &g_SendProps_32[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_32);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101066F0
// Name: int ServerClassInit<struct DT_Precipitation::ignored>(struct DT_Precipitation::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Precipitation::ignored>()
{
  unsigned int v0; // eax

  if ( (_S12_0 & 1) == 0 )
  {
    _S12_0 |= 1u;
    SendPropInt(
      result: g_SendProps_33,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_33[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    v0 = Q_log2(val: 8u);
    SendPropInt(
      result: &g_SendProps_33[2],
      pVarName: "m_nPrecipType",
      offset: 852,
      sizeofVar: 4,
      nBits: v0 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Precipitation::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Precipitation::g_SendTable,
    pProps: &g_SendProps_33[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_33);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010B140
// Name: int ServerClassInit<struct DT_EntityDissolve::ignored>(struct DT_EntityDissolve::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EntityDissolve::ignored>()
{
  if ( (_S3_42 & 1) == 0 )
  {
    _S3_42 |= 1u;
    SendPropInt(
      result: g_SendProps_34,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_34[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_34[2], pVarName: "m_flStartTime", offset: 852, sizeofVar: 4);
    SendPropFloat(
      result: &g_SendProps_34[3],
      pVarName: "m_flFadeInStart",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_34[4],
      pVarName: "m_flFadeInLength",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_34[5],
      pVarName: "m_flFadeOutModelStart",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_34[6],
      pVarName: "m_flFadeOutModelLength",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_34[7],
      pVarName: "m_flFadeOutStart",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_34[8],
      pVarName: "m_flFadeOutLength",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_34[9],
      pVarName: "m_nDissolveType",
      offset: 880,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_34[10],
      pVarName: "m_vDissolverOrigin",
      offset: 1049460,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_34[11],
      pVarName: "m_nMagnitude",
      offset: 896,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EntityDissolve::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EntityDissolve::g_SendTable,
    pProps: &g_SendProps_34[1],
    nProps: 11,
    pNetTableName: g_pSendTableName_34);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010C2A0
// Name: int ServerClassInit<struct DT_EntityFlame::ignored>(struct DT_EntityFlame::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EntityFlame::ignored>()
{
  if ( (_S3_43 & 1) == 0 )
  {
    _S3_43 |= 1u;
    SendPropInt(
      result: g_SendProps_35,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_35[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_35[2],
      pVarName: "m_hEntAttached",
      offset: 852,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropBool(result: &g_SendProps_35[3], pVarName: "m_bCheapEffect", offset: 856, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_EntityFlame::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EntityFlame::g_SendTable,
    pProps: &g_SendProps_35[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_35);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010D260
// Name: int ServerClassInit<struct DT_EntityFreezing::ignored>(struct DT_EntityFreezing::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EntityFreezing::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S3_44 & 1) == 0 )
  {
    _S3_44 |= 1u;
    SendPropInt(
      result: g_SendProps_36,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_36[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_36[2],
      pVarName: "m_vFreezingOrigin",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flFrozenPerHitbox",
      offset: 872,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_36[3],
      pVarName: "m_flFrozenPerHitbox",
      offset: 872,
      sizeofVar: 4,
      elements: 50,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropFloat(
      result: &g_SendProps_36[4],
      pVarName: "m_flFrozen",
      offset: 864,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_36[5], pVarName: "m_bFinishFreezing", offset: 868, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_EntityFreezing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EntityFreezing::g_SendTable,
    pProps: &g_SendProps_36[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_36);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10110210
// Name: int ServerClassInit<struct DT_EntityParticleTrail::ignored>(struct DT_EntityParticleTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EntityParticleTrail::ignored>()
{
  if ( (_S3_45 & 1) == 0 )
  {
    _S3_45 |= 1u;
    SendPropInt(
      result: g_SendProps_37,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_37[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_37[2],
      pVarName: "m_iMaterialName",
      offset: 852,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_37[3],
      pVarName: "m_Info",
      offset: 856,
      pTable: &DT_EntityParticleTrailInfo::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_37[4],
      pVarName: "m_hConstraintEntity",
      offset: 876,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_EntityParticleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EntityParticleTrail::g_SendTable,
    pProps: &g_SendProps_37[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_37);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10110850
// Name: int ServerClassInit<struct DT_EntityParticleTrailInfo::ignored>(struct DT_EntityParticleTrailInfo::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EntityParticleTrailInfo::ignored>()
{
  if ( (_S3_46 & 1) == 0 )
  {
    _S3_46 |= 1u;
    SendPropInt(
      result: g_SendProps_38,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_38[1],
      pVarName: "m_flLifetime",
      offset: 8,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_38[2],
      pVarName: "m_flStartSize",
      offset: 12,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_38[3],
      pVarName: "m_flEndSize",
      offset: 16,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EntityParticleTrailInfo::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EntityParticleTrailInfo::g_SendTable,
    pProps: &g_SendProps_38[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_38);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10110AB0
// Name: int ServerClassInit<struct DT_EnvAmbientLight::ignored>(struct DT_EnvAmbientLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvAmbientLight::ignored>()
{
  if ( (_S3_47 & 1) == 0 )
  {
    _S3_47 |= 1u;
    SendPropInt(
      result: g_SendProps_39,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_39[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CSpatialEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_39[2],
      pVarName: "m_vecColor",
      offset: 1049480,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvAmbientLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvAmbientLight::g_SendTable,
    pProps: &g_SendProps_39[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_39);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10111260
// Name: int ServerClassInit<struct DT_DetailController::ignored>(struct DT_DetailController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DetailController::ignored>()
{
  if ( (_S2_81 & 1) == 0 )
  {
    _S2_81 |= 1u;
    SendPropInt(
      result: g_SendProps_40,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_40[1],
      pVarName: "m_flFadeStartDist",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_40[2],
      pVarName: "m_flFadeEndDist",
      offset: 856,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_DetailController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DetailController::g_SendTable,
    pProps: &g_SendProps_40[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_40);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10111510
// Name: int ServerClassInit<struct DT_EnvDOFController::ignored>(struct DT_EnvDOFController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvDOFController::ignored>()
{
  if ( (_S3_48 & 1) == 0 )
  {
    _S3_48 |= 1u;
    SendPropInt(
      result: g_SendProps_41,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_41[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_41[2],
      pVarName: "m_bDOFEnabled",
      offset: 864,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[3],
      pVarName: "m_flNearBlurDepth",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[4],
      pVarName: "m_flNearFocusDepth",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[5],
      pVarName: "m_flFarFocusDepth",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[6],
      pVarName: "m_flFarBlurDepth",
      offset: 880,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[7],
      pVarName: "m_flNearBlurRadius",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_41[8],
      pVarName: "m_flFarBlurRadius",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvDOFController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvDOFController::g_SendTable,
    pProps: &g_SendProps_41[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_41);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10115470
// Name: int ServerClassInit<struct DT_EnvParticleScript::ignored>(struct DT_EnvParticleScript::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvParticleScript::ignored>()
{
  if ( (_S3_50 & 1) == 0 )
  {
    _S3_50 |= 1u;
    SendPropInt(
      result: g_SendProps_42,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_42[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_42[2],
      pVarName: "m_flSequenceScale",
      offset: 1164,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvParticleScript::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvParticleScript::g_SendTable,
    pProps: &g_SendProps_42[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_42);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10115F30
// Name: int ServerClassInit<struct DT_EnvProjectedTexture::ignored>(struct DT_EnvProjectedTexture::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvProjectedTexture::ignored>()
{
  if ( (_S3_51 & 1) == 0 )
  {
    _S3_51 |= 1u;
    SendPropInt(
      result: g_SendProps_43,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_43[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_43[2],
      pVarName: "m_hTargetEntity",
      offset: 852,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropBool(result: &g_SendProps_43[3], pVarName: "m_bState", offset: 856, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_43[4], pVarName: "m_bAlwaysUpdate", offset: 857, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_43[5],
      pVarName: "m_flLightFOV",
      offset: 860,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_43[6], pVarName: "m_bEnableShadows", offset: 864, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_43[7], pVarName: "m_bSimpleProjection", offset: 865, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_43[8], pVarName: "m_bLightOnlyTarget", offset: 866, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_43[9], pVarName: "m_bLightWorld", offset: 867, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_43[10], pVarName: "m_bCameraSpace", offset: 868, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_43[11],
      pVarName: "m_flBrightnessScale",
      offset: 872,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_43[12],
      pVarName: "m_LightColor",
      offset: 876,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[13],
      pVarName: "m_flColorTransitionTime",
      offset: 880,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[14],
      pVarName: "m_flAmbient",
      offset: 884,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_43[15],
      pVarName: "m_SpotlightTextureName",
      offset: 888,
      bufferLen: 260,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_43[16],
      pVarName: "m_nSpotlightTextureFrame",
      offset: 1148,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[17],
      pVarName: "m_flNearZ",
      offset: 1152,
      sizeofVar: 4,
      nBits: 16,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 500.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[18],
      pVarName: "m_flFarZ",
      offset: 1156,
      sizeofVar: 4,
      nBits: 18,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 2500.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_43[19],
      pVarName: "m_nShadowQuality",
      offset: 1160,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[20],
      pVarName: "m_flProjectionSize",
      offset: 1164,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_43[21],
      pVarName: "m_flRotation",
      offset: 1168,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_43[22],
      pVarName: "m_iStyle",
      offset: 1172,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvProjectedTexture::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvProjectedTexture::g_SendTable,
    pProps: &g_SendProps_43[1],
    nProps: 22,
    pNetTableName: g_pSendTableName_43);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117490
// Name: int ServerClassInit<struct DT_EnvScreenEffect::ignored>(struct DT_EnvScreenEffect::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvScreenEffect::ignored>()
{
  if ( (_S5_14 & 1) == 0 )
  {
    _S5_14 |= 1u;
    SendPropInt(
      result: g_SendProps_44,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_44[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_44[2],
      pVarName: "m_flDuration",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_44[3],
      pVarName: "m_nType",
      offset: 856,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvScreenEffect::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvScreenEffect::g_SendTable,
    pProps: &g_SendProps_44[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_44);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117590
// Name: int ServerClassInit<struct DT_EnvScreenOverlay::ignored>(struct DT_EnvScreenOverlay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvScreenOverlay::ignored>()
{
  if ( (_S3_52 & 1) == 0 )
  {
    _S3_52 |= 1u;
    SendPropInt(
      result: g_SendProps_45,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_45[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_45[2],
      pVarName: "m_iszOverlayNames",
      offset: 852,
      bufferLen: 4,
      flags: 0,
      varProxy: SendProxy_StringT_To_String,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_45[3],
      elementCount: 10,
      elementStride: 4,
      pName: "m_iszOverlayNames",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_45[4],
      pVarName: "m_flOverlayTimes",
      offset: 892,
      sizeofVar: 4,
      nBits: 11,
      flags: 8,
      fLowValue: -1.0,
      fHighValue: 63.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_45[5],
      elementCount: 10,
      elementStride: 4,
      pName: "m_flOverlayTimes",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_45[6],
      pVarName: "m_flStartTime",
      offset: 932,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_45[7],
      pVarName: "m_iDesiredOverlay",
      offset: 936,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_45[8], pVarName: "m_bIsActive", offset: 940, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_EnvScreenOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvScreenOverlay::g_SendTable,
    pProps: &g_SendProps_45[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_45);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10118DF0
// Name: int ServerClassInit<struct DT_EnvTonemapController::ignored>(struct DT_EnvTonemapController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_EnvTonemapController::ignored>()
{
  if ( (_S3_53 & 1) == 0 )
  {
    _S3_53 |= 1u;
    SendPropInt(
      result: g_SendProps_46,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_46[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_46[2],
      pVarName: "m_bUseCustomAutoExposureMin",
      offset: 868,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_46[3],
      pVarName: "m_bUseCustomAutoExposureMax",
      offset: 869,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_46[4],
      pVarName: "m_bUseCustomBloomScale",
      offset: 870,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[5],
      pVarName: "m_flCustomAutoExposureMin",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[6],
      pVarName: "m_flCustomAutoExposureMax",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[7],
      pVarName: "m_flCustomBloomScale",
      offset: 880,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[8],
      pVarName: "m_flCustomBloomScaleMinimum",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[9],
      pVarName: "m_flBloomExponent",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[10],
      pVarName: "m_flBloomSaturation",
      offset: 892,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[11],
      pVarName: "m_flTonemapPercentTarget",
      offset: 896,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[12],
      pVarName: "m_flTonemapPercentBrightPixels",
      offset: 900,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_46[13],
      pVarName: "m_flTonemapMinAvgLum",
      offset: 904,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_EnvTonemapController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_EnvTonemapController::g_SendTable,
    pProps: &g_SendProps_46[1],
    nProps: 13,
    pNetTableName: g_pSendTableName_46);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10127430
// Name: int ServerClassInit<struct DT_FireSmoke::ignored>(struct DT_FireSmoke::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FireSmoke::ignored>()
{
  if ( (_S3_58 & 1) == 0 )
  {
    _S3_58 |= 1u;
    SendPropInt(
      result: g_SendProps_47,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_47[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_47[2],
      pVarName: "m_flStartScale",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_47[3],
      pVarName: "m_flScale",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_47[4],
      pVarName: "m_flScaleTime",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_47[5],
      pVarName: "m_nFlags",
      offset: 864,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_47[6],
      pVarName: "m_nFlameModelIndex",
      offset: 868,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_47[7],
      pVarName: "m_nFlameFromAboveModelIndex",
      offset: 872,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FireSmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FireSmoke::g_SendTable,
    pProps: &g_SendProps_47[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_47);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10127E10
// Name: int ServerClassInit<struct DT_CFish::ignored>(struct DT_CFish::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CFish::ignored>()
{
  if ( (_S3_59 & 1) == 0 )
  {
    _S3_59 |= 1u;
    SendPropInt(
      result: g_SendProps_48,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_48[1],
      pVarName: "m_poolOrigin",
      offset: 1049792,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_48[2],
      pVarName: "m_angle",
      offset: 1184,
      sizeofVar: 4,
      nBits: 7,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 360.0,
      varProxy: SendProxy_FishAngle,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_48[3],
      pVarName: "m_x",
      offset: 1172,
      sizeofVar: 4,
      nBits: 7,
      flags: 0,
      fLowValue: -255.0,
      fHighValue: 255.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_48[4],
      pVarName: "m_y",
      offset: 1176,
      sizeofVar: 4,
      nBits: 7,
      flags: 0,
      fLowValue: -255.0,
      fHighValue: 255.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_48[5],
      pVarName: "m_z",
      offset: 1180,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_48[6],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_48[7],
      pVarName: "m_lifeState",
      offset: 553,
      sizeofVar: 1,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_48[8],
      pVarName: "m_waterLevel",
      offset: 1228,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CFish::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CFish::g_SendTable,
    pProps: &g_SendProps_48[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_48);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012B400
// Name: int ServerClassInit<struct DT_FogController::ignored>(struct DT_FogController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FogController::ignored>()
{
  if ( (_S3_60 & 1) == 0 )
  {
    _S3_60 |= 1u;
    SendPropInt(
      result: g_SendProps_49,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[1],
      pVarName: "m_fog.enable",
      offset: 920,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[2],
      pVarName: "m_fog.blend",
      offset: 921,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_49[3],
      pVarName: "m_fog.dirPrimary",
      offset: 1049432,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[4],
      pVarName: "m_fog.colorPrimary",
      offset: 868,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[5],
      pVarName: "m_fog.colorSecondary",
      offset: 872,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[6],
      pVarName: "m_fog.start",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[7],
      pVarName: "m_fog.end",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[8],
      pVarName: "m_fog.maxdensity",
      offset: 896,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[9],
      pVarName: "m_fog.farz",
      offset: 892,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[10],
      pVarName: "m_fog.colorPrimaryLerpTo",
      offset: 876,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_49[11],
      pVarName: "m_fog.colorSecondaryLerpTo",
      offset: 880,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[12],
      pVarName: "m_fog.startLerpTo",
      offset: 900,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[13],
      pVarName: "m_fog.endLerpTo",
      offset: 904,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[14],
      pVarName: "m_fog.maxdensityLerpTo",
      offset: 908,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[15],
      pVarName: "m_fog.lerptime",
      offset: 912,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[16],
      pVarName: "m_fog.duration",
      offset: 916,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_49[17],
      pVarName: "m_fog.HDRColorScale",
      offset: 924,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FogController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FogController::g_SendTable,
    pProps: &g_SendProps_49[1],
    nProps: 17,
    pNetTableName: g_pSendTableName_49);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012D1B0
// Name: int ServerClassInit<struct DT_TEFoundryHelpers::ignored>(struct DT_TEFoundryHelpers::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEFoundryHelpers::ignored>()
{
  if ( (_S2_109 & 1) == 0 )
  {
    _S2_109 |= 1u;
    SendPropInt(
      result: g_SendProps_50,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_50[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_50[2],
      pVarName: "m_iEntity",
      offset: 12,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEFoundryHelpers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEFoundryHelpers::g_SendTable,
    pProps: &g_SendProps_50[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_50);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101312A0
// Name: int ServerClassInit<struct DT_FuncAreaPortalWindow::ignored>(struct DT_FuncAreaPortalWindow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncAreaPortalWindow::ignored>()
{
  if ( (_S2_113 & 1) == 0 )
  {
    _S2_113 |= 1u;
    SendPropInt(
      result: g_SendProps_51,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_51[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_51[2],
      pVarName: "m_flFadeDist",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_51[3],
      pVarName: "m_flFadeStartDist",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_51[4],
      pVarName: "m_flTranslucencyLimit",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_51[5],
      pVarName: "m_iBackgroundModelIndex",
      offset: 880,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncAreaPortalWindow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncAreaPortalWindow::g_SendTable,
    pProps: &g_SendProps_51[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_51);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10134BC0
// Name: int ServerClassInit<struct DT_BreakableSurface::ignored>(struct DT_BreakableSurface::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BreakableSurface::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S4_34 & 1) == 0 )
  {
    _S4_34 |= 1u;
    SendPropInt(
      result: g_SendProps_52,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_52[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_52[2],
      pVarName: "m_nNumWide",
      offset: 1028,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_52[3],
      pVarName: "m_nNumHigh",
      offset: 1032,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_52[4],
      pVarName: "m_flPanelWidth",
      offset: 1036,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_52[5],
      pVarName: "m_flPanelHeight",
      offset: 1040,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_52[6],
      pVarName: "m_vNormal",
      offset: 1049620,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_52[7],
      pVarName: "m_vCorner",
      offset: 1049632,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_52[8],
      pVarName: "m_bIsBroken",
      offset: 1068,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_52[9],
      pVarName: "m_nSurfaceType",
      offset: 1072,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_RawPanelBitVec",
      offset: 2160,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_52[10],
      pVarName: "m_RawPanelBitVec",
      offset: 2160,
      sizeofVar: 1,
      elements: 256,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    atexit(func: ServerClassInit_DT_BreakableSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BreakableSurface::g_SendTable,
    pProps: &g_SendProps_52[1],
    nProps: 10,
    pNetTableName: g_pSendTableName_52);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10137FB0
// Name: int ServerClassInit<struct DT_TEDust::ignored>(struct DT_TEDust::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEDust::ignored>()
{
  if ( (_S4_35 & 1) == 0 )
  {
    _S4_35 |= 1u;
    SendPropInt(
      result: g_SendProps_53,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_53[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_53[2],
      pVarName: "m_flSize",
      offset: 24,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_53[3],
      pVarName: "m_flSpeed",
      offset: 28,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_53[4],
      pVarName: "m_vecDirection",
      offset: 1048608,
      sizeofVar: 12,
      nBits: 4,
      flags: 0,
      fLowValue: -1.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEDust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEDust::g_SendTable,
    pProps: &g_SendProps_53[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_53);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10138180
// Name: int ServerClassInit<struct DT_Func_Dust::ignored>(struct DT_Func_Dust::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Func_Dust::ignored>()
{
  if ( (_S2_116 & 1) == 0 )
  {
    _S2_116 |= 1u;
    SendPropInt(
      result: g_SendProps_54,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[1],
      pVarName: "m_Color",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[2],
      pVarName: "m_SpawnRate",
      offset: 856,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[3],
      pVarName: "m_SpeedMax",
      offset: 868,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_54[4],
      pVarName: "m_flSizeMin",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_54[5],
      pVarName: "m_flSizeMax",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[6],
      pVarName: "m_DistMax",
      offset: 880,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[7],
      pVarName: "m_LifetimeMin",
      offset: 872,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[8],
      pVarName: "m_LifetimeMax",
      offset: 876,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[9],
      pVarName: "m_DustFlags",
      offset: 888,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_54[10],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_54[11],
      pVarName: "m_FallSpeed",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_54[12],
      pVarName: "m_Collision",
      offset: 228,
      pTable: &DT_CollisionProperty::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Func_Dust::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Func_Dust::g_SendTable,
    pProps: &g_SendProps_54[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_54);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013A200
// Name: int ServerClassInit<struct DT_InfoLadderDismount::ignored>(struct DT_InfoLadderDismount::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_InfoLadderDismount::ignored>()
{
  if ( (_S4_36 & 1) == 0 )
  {
    _S4_36 |= 1u;
    SendPropInt(
      result: g_SendProps_55,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_55[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_InfoLadderDismount::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_InfoLadderDismount::g_SendTable,
    pProps: &g_SendProps_55[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_55);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013A290
// Name: int ServerClassInit<struct DT_FuncLadder::ignored>(struct DT_FuncLadder::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncLadder::ignored>()
{
  if ( (_S2_118 & 1) == 0 )
  {
    _S2_118 |= 1u;
    SendPropInt(
      result: g_SendProps_56,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_56[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_56[2],
      pVarName: "m_vecPlayerMountPositionTop",
      offset: 1049460,
      sizeofVar: 12,
      nBits: 2,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_56[3],
      pVarName: "m_vecPlayerMountPositionBottom",
      offset: 1049472,
      sizeofVar: 12,
      nBits: 2,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_56[4],
      pVarName: "m_vecLadderDir",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 2,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_56[5], pVarName: "m_bFakeLadder", offset: 909, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_FuncLadder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncLadder::g_SendTable,
    pProps: &g_SendProps_56[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_56);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013B8E0
// Name: int ServerClassInit<struct DT_Func_LOD::ignored>(struct DT_Func_LOD::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Func_LOD::ignored>()
{
  if ( (_S2_119 & 1) == 0 )
  {
    _S2_119 |= 1u;
    SendPropInt(
      result: g_SendProps_57,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_57[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_57[2],
      pVarName: "m_nDisappearMinDist",
      offset: 852,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_57[3],
      pVarName: "m_nDisappearMaxDist",
      offset: 856,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Func_LOD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Func_LOD::g_SendTable,
    pProps: &g_SendProps_57[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_57);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013BD10
// Name: int ServerClassInit<struct DT_FuncMonitor::ignored>(struct DT_FuncMonitor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncMonitor::ignored>()
{
  if ( (_S3_66 & 1) == 0 )
  {
    _S3_66 |= 1u;
    SendPropInt(
      result: g_SendProps_58,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_58[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CFuncBrush::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncMonitor::g_SendTable,
    pProps: &g_SendProps_58[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_58);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013BFE0
// Name: int ServerClassInit<struct DT_FuncMoveLinear::ignored>(struct DT_FuncMoveLinear::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncMoveLinear::ignored>()
{
  if ( (_S3_67 & 1) == 0 )
  {
    _S3_67 |= 1u;
    SendPropInt(
      result: g_SendProps_59,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_59[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseToggle::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_59[2],
      pVarName: "m_vecVelocity",
      offset: 3146212,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_59[3],
      pVarName: "m_fFlags",
      offset: 200,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncMoveLinear::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncMoveLinear::g_SendTable,
    pProps: &g_SendProps_59[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_59);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013D140
// Name: int ServerClassInit<struct DT_FuncOccluder::ignored>(struct DT_FuncOccluder::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncOccluder::ignored>()
{
  if ( (_S2_122 & 1) == 0 )
  {
    _S2_122 |= 1u;
    SendPropInt(
      result: g_SendProps_60,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_60[1], pVarName: "m_bActive", offset: 852, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_60[2],
      pVarName: "m_nOccluderIndex",
      offset: 856,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncOccluder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncOccluder::g_SendTable,
    pProps: &g_SendProps_60[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_60);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013D440
// Name: int ServerClassInit<struct DT_FuncReflectiveGlass::ignored>(struct DT_FuncReflectiveGlass::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncReflectiveGlass::ignored>()
{
  if ( (_S3_69 & 1) == 0 )
  {
    _S3_69 |= 1u;
    SendPropInt(
      result: g_SendProps_61,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_61[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CFuncBrush::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncReflectiveGlass::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncReflectiveGlass::g_SendTable,
    pProps: &g_SendProps_61[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_61);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013D5A0
// Name: int ServerClassInit<struct DT_FuncSmokeVolume::ignored>(struct DT_FuncSmokeVolume::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncSmokeVolume::ignored>()
{
  if ( (_S3_70 & 1) == 0 )
  {
    _S3_70 |= 1u;
    SendPropInt(
      result: g_SendProps_62,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_62[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_62[2],
      pVarName: "m_Color1",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_62[3],
      pVarName: "m_Color2",
      offset: 856,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_62[4],
      pVarName: "m_MaterialName",
      offset: 860,
      bufferLen: 255,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[5],
      pVarName: "m_ParticleDrawWidth",
      offset: 1120,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[6],
      pVarName: "m_ParticleSpacingDistance",
      offset: 1124,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[7],
      pVarName: "m_DensityRampSpeed",
      offset: 1128,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[8],
      pVarName: "m_RotationSpeed",
      offset: 1132,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[9],
      pVarName: "m_MovementSpeed",
      offset: 1136,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[10],
      pVarName: "m_Density",
      offset: 1140,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_62[11],
      pVarName: "m_maxDrawDistance",
      offset: 1144,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_62[12],
      pVarName: "m_spawnflags",
      offset: 760,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncSmokeVolume::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncSmokeVolume::g_SendTable,
    pProps: &g_SendProps_62[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_62);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014C580
// Name: int ServerClassInit<struct DT_GameRulesProxy::ignored>(struct DT_GameRulesProxy::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_GameRulesProxy::ignored>()
{
  if ( ((int)_S2_127.__vftable & 1) == 0 )
  {
    _S2_127.__vftable = (SendProp_vtbl *)((int)_S2_127.__vftable | 1);
    SendPropInt(
      result: g_SendProps_63,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_GameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_GameRulesProxy::g_SendTable,
    pProps: &_S2_127,
    nProps: 0,
    pNetTableName: g_pSendTableName_63);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015ADD0
// Name: int ServerClassInit<struct DT_WeaponCycler::ignored>(struct DT_WeaponCycler::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponCycler::ignored>()
{
  if ( (_S3_74 & 1) == 0 )
  {
    _S3_74 |= 1u;
    SendPropInt(
      result: g_SendProps_64,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_64[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCombatWeapon::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponCycler::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponCycler::g_SendTable,
    pProps: &g_SendProps_64[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_64);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162510
// Name: int ServerClassInit<struct DT_InfoOverlayAccessor::ignored>(struct DT_InfoOverlayAccessor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_InfoOverlayAccessor::ignored>()
{
  if ( (_S2_137 & 1) == 0 )
  {
    _S2_137 |= 1u;
    SendPropInt(
      result: g_SendProps_65,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_65[1],
      pVarName: "m_iTextureFrameIndex",
      offset: 500,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_65[2],
      pVarName: "m_iOverlayID",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_InfoOverlayAccessor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_InfoOverlayAccessor::g_SendTable,
    pProps: &g_SendProps_65[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_65);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101645F0
// Name: int ServerClassInit<struct DT_LightGlow::ignored>(struct DT_LightGlow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_LightGlow::ignored>()
{
  if ( (_S2_140 & 1) == 0 )
  {
    _S2_140 |= 1u;
    SendPropInt(
      result: g_SendProps_66,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[1],
      pVarName: "m_clrRender",
      offset: 184,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[2],
      pVarName: "m_nHorizontalSize",
      offset: 852,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[3],
      pVarName: "m_nVerticalSize",
      offset: 856,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[4],
      pVarName: "m_nMinDist",
      offset: 860,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[5],
      pVarName: "m_nMaxDist",
      offset: 864,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[6],
      pVarName: "m_nOuterMaxDist",
      offset: 868,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_66[7],
      pVarName: "m_spawnflags",
      offset: 760,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_66[8],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_66[9],
      pVarName: "m_angRotation",
      offset: 3146440,
      sizeofVar: 12,
      nBits: 13,
      flags: 0,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Angles,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_66[10],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropFloat(
      result: &g_SendProps_66[11],
      pVarName: "m_flGlowProxySize",
      offset: 872,
      sizeofVar: 4,
      nBits: 6,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 64.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_66[12],
      pVarName: "HDRColorScale",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_LightGlow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_LightGlow::g_SendTable,
    pProps: &g_SendProps_66[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_66);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101717F0
// Name: int ServerClassInit<struct DT_MaterialModifyControl::ignored>(struct DT_MaterialModifyControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_MaterialModifyControl::ignored>()
{
  if ( (_S3_80 & 1) == 0 )
  {
    _S3_80 |= 1u;
    SendPropInt(
      result: g_SendProps_67,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_67[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_67[2],
      pVarName: "m_szMaterialName",
      offset: 852,
      bufferLen: 255,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_67[3],
      pVarName: "m_szMaterialVar",
      offset: 1107,
      bufferLen: 255,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_67[4],
      pVarName: "m_szMaterialVarValue",
      offset: 1362,
      bufferLen: 255,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_67[5],
      pVarName: "m_iFrameStart",
      offset: 1620,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_67[6],
      pVarName: "m_iFrameEnd",
      offset: 1624,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_67[7],
      pVarName: "m_bWrap",
      offset: 1628,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_67[8],
      pVarName: "m_flFramerate",
      offset: 1632,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_67[9],
      pVarName: "m_bNewAnimCommandsSemaphore",
      offset: 1636,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_67[10],
      pVarName: "m_flFloatLerpStartValue",
      offset: 1640,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_67[11],
      pVarName: "m_flFloatLerpEndValue",
      offset: 1644,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_67[12],
      pVarName: "m_flFloatLerpTransitionTime",
      offset: 1648,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_67[13],
      pVarName: "m_nModifyMode",
      offset: 1652,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_MaterialModifyControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_MaterialModifyControl::g_SendTable,
    pProps: &g_SendProps_67[1],
    nProps: 13,
    pNetTableName: g_pSendTableName_67);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10172A90
// Name: int ServerClassInit<struct DT_FuncBrush::ignored>(struct DT_FuncBrush::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncBrush::ignored>()
{
  if ( (_S3_81 & 1) == 0 )
  {
    _S3_81 |= 1u;
    SendPropInt(
      result: g_SendProps_68,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_68[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncBrush::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncBrush::g_SendTable,
    pProps: &g_SendProps_68[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_68);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174D60
// Name: int ServerClassInit<struct DT_MovieDisplay::ignored>(struct DT_MovieDisplay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_MovieDisplay::ignored>()
{
  if ( (_S3_83 & 1) == 0 )
  {
    _S3_83 |= 1u;
    SendPropInt(
      result: g_SendProps_69,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_69[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_69[2], pVarName: "m_bEnabled", offset: 852, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_69[3], pVarName: "m_bLooping", offset: 853, sizeofVar: 1);
    SendPropString(
      result: &g_SendProps_69[4],
      pVarName: "m_szMovieFilename",
      offset: 1004,
      bufferLen: 128,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_69[5],
      pVarName: "m_szGroupName",
      offset: 1136,
      bufferLen: 128,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_69[6], pVarName: "m_bStretchToFill", offset: 854, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_69[7], pVarName: "m_bForcedSlave", offset: 855, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_69[8], pVarName: "m_bUseCustomUVs", offset: 857, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_69[9],
      pVarName: "m_flUMin",
      offset: 860,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_69[10],
      pVarName: "m_flUMax",
      offset: 864,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_69[11],
      pVarName: "m_flVMin",
      offset: 868,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_69[12],
      pVarName: "m_flVMax",
      offset: 872,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_MovieDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_MovieDisplay::g_SendTable,
    pProps: &g_SendProps_69[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_69);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017C420
// Name: int ServerClassInit<struct DT_ParticleSystem::ignored>(struct DT_ParticleSystem::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ParticleSystem::ignored>()
{
  unsigned int v0; // eax
  SendProp v2; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v3)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v4; // [esp+68h] [ebp-4h]

  if ( (_S3_84 & 1) == 0 )
  {
    _S3_84 |= 1u;
    SendPropInt(
      result: g_SendProps_70,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_70[1],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 262146,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Origin,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_70[2],
      pVarName: "m_fEffects",
      offset: 164,
      sizeofVar: 4,
      nBits: 14,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_70[3],
      pVarName: "m_hOwnerEntity",
      offset: 320,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_70[4],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_70[5],
      pVarName: "m_iParentAttachment",
      offset: 213,
      sizeofVar: 1,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_70[6],
      pVarName: "m_angRotation",
      offset: 3146440,
      sizeofVar: 12,
      nBits: 13,
      flags: 0x40000,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Angles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_70[7],
      pVarName: "m_iEffectIndex",
      offset: 1128,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_70[8], pVarName: "m_bActive", offset: 1120, sizeofVar: 1);
    v0 = Q_log2(val: 3u);
    SendPropInt(
      result: &g_SendProps_70[9],
      pVarName: "m_nStopType",
      offset: 1124,
      sizeofVar: 4,
      nBits: v0 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_70[10],
      pVarName: "m_flStartTime",
      offset: 1132,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_70[11],
      pVarName: "m_szSnapshotFileName",
      offset: 860,
      bufferLen: 260,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropVector(
      result: &v2,
      pVarName: "m_vServerControlPoints",
      offset: 1136,
      sizeofVar: 12,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_70[12],
      pVarName: "m_vServerControlPoints",
      offset: 1136,
      sizeofVar: 12,
      elements: 4,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v2,
      pVarName: "m_iServerControlPointAssignments",
      offset: 1184,
      sizeofVar: 1,
      nBits: -1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_70[13],
      pVarName: "m_iServerControlPointAssignments",
      offset: 1184,
      sizeofVar: 1,
      elements: 4,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropEHandle(
      result: &v2,
      pVarName: "m_hControlPointEnts",
      offset: 1440,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropArray3(
      result: &g_SendProps_70[14],
      pVarName: "m_hControlPointEnts",
      offset: 1440,
      sizeofVar: 4,
      elements: 63,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    v4 = 128;
    v3 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v2,
      pVarName: "m_iControlPointParents",
      offset: 1692,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_70[15],
      pVarName: "m_iControlPointParents",
      offset: 1692,
      sizeofVar: 1,
      elements: 63,
      pArrayProp: v2,
      varProxy: v3,
      priority: v4);
    atexit(func: ServerClassInit_DT_ParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ParticleSystem::g_SendTable,
    pProps: &g_SendProps_70[1],
    nProps: 15,
    pNetTableName: g_pSendTableName_70);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018D350
// Name: int ServerClassInit<struct DT_BoneFollower::ignored>(struct DT_BoneFollower::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BoneFollower::ignored>()
{
  if ( (_S5_22 & 1) == 0 )
  {
    _S5_22 |= 1u;
    SendPropInt(
      result: g_SendProps_71,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_71[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_71[2],
      pVarName: "m_modelIndex",
      offset: 852,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_71[3],
      pVarName: "m_solidIndex",
      offset: 856,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BoneFollower::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BoneFollower::g_SendTable,
    pProps: &g_SendProps_71[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_71);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019CE50
// Name: int ServerClassInit<struct DT_Ragdoll_Attached::ignored>(struct DT_Ragdoll_Attached::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Ragdoll_Attached::ignored>()
{
  if ( (_S5_23 & 1) == 0 )
  {
    _S5_23 |= 1u;
    SendPropInt(
      result: g_SendProps_72,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_72[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CRagdollProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_72[2],
      pVarName: "m_boneIndexAttached",
      offset: 3696,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_72[3],
      pVarName: "m_ragdollAttachedObjectIndex",
      offset: 3700,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_72[4],
      pVarName: "m_attachmentPointBoneSpace",
      offset: 1052280,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_72[5],
      pVarName: "m_attachmentPointRagdollSpace",
      offset: 1052292,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Ragdoll_Attached::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Ragdoll_Attached::g_SendTable,
    pProps: &g_SendProps_72[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_72);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019D140
// Name: int ServerClassInit<struct DT_Ragdoll::ignored>(struct DT_Ragdoll::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Ragdoll::ignored>()
{
  if ( (_S2_167 & 1) == 0 )
  {
    _S2_167 |= 1u;
    SendPropInt(
      result: g_SendProps_73,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_73[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_73[2],
      pVarName: "m_ragAngles",
      offset: 2484,
      sizeofVar: 12,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_QAngles,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_73[3],
      elementCount: 32,
      elementStride: 12,
      pName: "m_ragAngles",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_73[4],
      pVarName: "m_ragPos",
      offset: 2100,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_73[5],
      elementCount: 32,
      elementStride: 12,
      pName: "m_ragPos",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_73[6],
      pVarName: "m_hUnragdoll",
      offset: 2872,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropFloat(
      result: &g_SendProps_73[7],
      pVarName: "m_flBlendWeight",
      offset: 2916,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_73[8],
      pVarName: "m_nOverlaySequence",
      offset: 2920,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Ragdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Ragdoll::g_SendTable,
    pProps: &g_SendProps_73[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_73);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A3070
// Name: int ServerClassInit<struct DT_StatueProp::ignored>(struct DT_StatueProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_StatueProp::ignored>()
{
  if ( (_S2_168 & 1) == 0 )
  {
    _S2_168 |= 1u;
    SendPropInt(
      result: g_SendProps_74,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_74[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CPhysicsProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_74[2],
      pVarName: "m_hInitBaseAnimating",
      offset: 1776,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropBool(result: &g_SendProps_74[3], pVarName: "m_bShatter", offset: 1780, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_74[4],
      pVarName: "m_nShatterFlags",
      offset: 1784,
      sizeofVar: 4,
      nBits: 3,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_74[5],
      pVarName: "m_vShatterPosition",
      offset: 1050364,
      sizeofVar: 12,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_74[6],
      pVarName: "m_vShatterForce",
      offset: 1050376,
      sizeofVar: 12,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_StatueProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_StatueProp::g_SendTable,
    pProps: &g_SendProps_74[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_74);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AF3F0
// Name: int ServerClassInit<struct DT_PhysMagnet::ignored>(struct DT_PhysMagnet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PhysMagnet::ignored>()
{
  if ( (_S10_3 & 1) == 0 )
  {
    _S10_3 |= 1u;
    SendPropInt(
      result: g_SendProps_75,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_75[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PhysMagnet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PhysMagnet::g_SendTable,
    pProps: &g_SendProps_75[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_75);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AF840
// Name: int ServerClassInit<struct DT_PhysBox::ignored>(struct DT_PhysBox::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PhysBox::ignored>()
{
  if ( (_S3_94 & 1) == 0 )
  {
    _S3_94 |= 1u;
    SendPropInt(
      result: g_SendProps_76,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_76[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PhysBox::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PhysBox::g_SendTable,
    pProps: &g_SendProps_76[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_76);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B74E0
// Name: int ServerClassInit<struct DT_LocalPlayerExclusive::ignored>(struct DT_LocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_LocalPlayerExclusive::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S8_9 & 1) == 0 )
  {
    _S8_9 |= 1u;
    SendPropInt(
      result: g_SendProps_77,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_77[1],
      pVarName: "m_Local",
      offset: 2288,
      pTable: &DT_Local::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[2],
      pVarName: "m_vecViewOffset[0]",
      offset: 3146456,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: -32.0,
      fHighValue: 32.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[3],
      pVarName: "m_vecViewOffset[1]",
      offset: 3146460,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: -32.0,
      fHighValue: 32.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[4],
      pVarName: "m_vecViewOffset[2]",
      offset: 3146464,
      sizeofVar: 4,
      nBits: 10,
      flags: 0x40000,
      fLowValue: 0.0,
      fHighValue: 128.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[5],
      pVarName: "m_flFriction",
      offset: 436,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 4.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iAmmo",
      offset: 1812,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_77[6],
      pVarName: "m_iAmmo",
      offset: 1812,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_77[7],
      pVarName: "m_fOnTarget",
      offset: 2976,
      sizeofVar: 1,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_77[8],
      pVarName: "m_nTickBase",
      offset: 3884,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 1u);
    SendPropInt(
      result: &g_SendProps_77[9],
      pVarName: "m_nNextThinkTick",
      offset: 160,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_77[10],
      pVarName: "m_hLastWeapon",
      offset: 3896,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropFloat(
      result: &g_SendProps_77[11],
      pVarName: "m_vecVelocity[0]",
      offset: 3146212,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 5u);
    SendPropFloat(
      result: &g_SendProps_77[12],
      pVarName: "m_vecVelocity[1]",
      offset: 3146216,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 5u);
    SendPropFloat(
      result: &g_SendProps_77[13],
      pVarName: "m_vecVelocity[2]",
      offset: 3146220,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 6u);
    SendPropVector(
      result: &g_SendProps_77[14],
      pVarName: "m_vecBaseVelocity",
      offset: 1048928,
      sizeofVar: 12,
      nBits: 20,
      flags: 0,
      fLowValue: -1000.0,
      fHighValue: 1000.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_77[15],
      pVarName: "m_hConstraintEntity",
      offset: 3940,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropVector(
      result: &g_SendProps_77[16],
      pVarName: "m_vecConstraintCenter",
      offset: 1052520,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[17],
      pVarName: "m_flConstraintRadius",
      offset: 3956,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[18],
      pVarName: "m_flConstraintWidth",
      offset: 3960,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[19],
      pVarName: "m_flConstraintSpeedFactor",
      offset: 3964,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_77[20], pVarName: "m_bConstraintPastRadius", offset: 3968, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_77[21],
      pVarName: "m_flDeathTime",
      offset: 3132,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[22],
      pVarName: "m_fForceTeam",
      offset: 3140,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_77[23],
      pVarName: "m_nWaterLevel",
      offset: 339,
      sizeofVar: 1,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_77[24],
      pVarName: "m_flLaggedMovementValue",
      offset: 4004,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_77[25],
      pVarName: "m_hTonemapController",
      offset: 3232,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_LocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_LocalPlayerExclusive::g_SendTable,
    pProps: &g_SendProps_77[1],
    nProps: 25,
    pNetTableName: g_pSendTableName_77);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B7A70
// Name: int ServerClassInit<struct DT_BasePlayer::ignored>(struct DT_BasePlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BasePlayer::ignored>()
{
  if ( (_S9_6 & 1) == 0 )
  {
    _S9_6 |= 1u;
    SendPropInt(
      result: g_SendProps_78,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_78[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCombatCharacter::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_78[2],
      pVarName: "pl",
      offset: 2900,
      pTable: &DT_PlayerState::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[3],
      pVarName: "m_afPhysicsFlags",
      offset: 3068,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_78[4],
      pVarName: "m_hVehicle",
      offset: 3072,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_78[5],
      pVarName: "m_hUseEntity",
      offset: 3056,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_78[6],
      pVarName: "m_hGroundEntity",
      offset: 344,
      flags: 4,
      sizeofVar: 0x40000,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_78[7],
      pVarName: "m_iHealth",
      offset: 528,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[8],
      pVarName: "m_lifeState",
      offset: 553,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[9],
      pVarName: "m_iBonusProgress",
      offset: 3084,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[10],
      pVarName: "m_iBonusChallenge",
      offset: 3088,
      sizeofVar: 4,
      nBits: 4,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_78[11],
      pVarName: "m_flMaxspeed",
      offset: 3796,
      sizeofVar: 4,
      nBits: 12,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 2048.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[12],
      pVarName: "m_fFlags",
      offset: 200,
      sizeofVar: 4,
      nBits: 11,
      flags: 262145,
      varProxy: SendProxy_CropFlagsToPlayerFlagBitsLength,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[13],
      pVarName: "m_iObserverMode",
      offset: 3144,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_78[14],
      pVarName: "m_hObserverTarget",
      offset: 3168,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_78[15],
      pVarName: "m_iFOV",
      offset: 3148,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[16],
      pVarName: "m_iFOVStart",
      offset: 3156,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_78[17],
      pVarName: "m_flFOVTime",
      offset: 3160,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[18],
      pVarName: "m_iDefaultFOV",
      offset: 3152,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_78[19],
      pVarName: "m_hZoomOwner",
      offset: 3176,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_78[20],
      pVarName: "m_hViewModel",
      offset: 3688,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    InternalSendPropArray(
      result: &g_SendProps_78[21],
      elementCount: 2,
      elementStride: 4,
      pName: "m_hViewModel",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_78[22],
      pVarName: "m_szLastPlaceName",
      offset: 4080,
      bufferLen: 18,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_78[23],
      pVarName: "m_vecLadderNormal",
      offset: 1052380,
      sizeofVar: 12,
      nBits: 0,
      flags: 32,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[24],
      pVarName: "m_ladderSurfaceProps",
      offset: 3800,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_78[25],
      pVarName: "m_ubEFNoInterpParity",
      offset: 4192,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_78[26],
      pVarName: "m_hPostProcessCtrl",
      offset: 2872,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_78[27],
      pVarName: "m_hColorCorrectionCtrl",
      offset: 2876,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_78[28],
      pVarName: "m_PlayerFog.m_hCtrl",
      offset: 2796,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_78[29],
      pVarName: "m_vphysicsCollisionState",
      offset: 3208,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_78[30],
      pVarName: "m_hViewEntity",
      offset: 3932,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropBool(
      result: &g_SendProps_78[31],
      pVarName: "m_bShouldDrawPlayerWhileUsingViewEntity",
      offset: 3936,
      sizeofVar: 1);
    SendPropDataTable(
      result: &g_SendProps_78[32],
      pVarName: "localdata",
      offset: 0,
      pTable: &DT_LocalPlayerExclusive::g_SendTable,
      varProxy: SendProxy_SendLocalDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BasePlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BasePlayer::g_SendTable,
    pProps: &g_SendProps_78[1],
    nProps: 32,
    pNetTableName: g_pSendTableName_78);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BA3B0
// Name: int ServerClassInit<struct DT_PlayerState::ignored>(struct DT_PlayerState::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PlayerState::ignored>()
{
  if ( (_S7_11 & 1) == 0 )
  {
    _S7_11 |= 1u;
    SendPropInt(
      result: g_SendProps_79,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_79[1],
      pVarName: "deadflag",
      offset: 4,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PlayerState::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PlayerState::g_SendTable,
    pProps: &g_SendProps_79[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_79);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CF1F0
// Name: int ServerClassInit<struct DT_PlayerResource::ignored>(struct DT_PlayerResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PlayerResource::ignored>()
{
  SendProp v1; // [esp-5Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  if ( (_S2_172 & 1) == 0 )
  {
    _S2_172 |= 1u;
    SendPropInt(
      result: g_SendProps_80,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iPing",
      offset: 852,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[1],
      pVarName: "m_iPing",
      offset: 852,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iKills",
      offset: 1112,
      sizeofVar: 4,
      nBits: 16,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[2],
      pVarName: "m_iKills",
      offset: 1112,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iDeaths",
      offset: 1372,
      sizeofVar: 4,
      nBits: 12,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[3],
      pVarName: "m_iDeaths",
      offset: 1372,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bConnected",
      offset: 1632,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[4],
      pVarName: "m_bConnected",
      offset: 1632,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeam",
      offset: 1892,
      sizeofVar: 4,
      nBits: 4,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[5],
      pVarName: "m_iTeam",
      offset: 1892,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bAlive",
      offset: 2152,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[6],
      pVarName: "m_bAlive",
      offset: 2152,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iHealth",
      offset: 2412,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_80[7],
      pVarName: "m_iHealth",
      offset: 2412,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    atexit(func: ServerClassInit_DT_PlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PlayerResource::g_SendTable,
    pProps: &g_SendProps_80[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_80);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D0000
// Name: int ServerClassInit<struct DT_Local::ignored>(struct DT_Local::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Local::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S2_173 & 1) == 0 )
  {
    _S2_173 |= 1u;
    SendPropInt(
      result: g_SendProps_81,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_chAreaBits",
      offset: 4,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_81[1],
      pVarName: "m_chAreaBits",
      offset: 4,
      sizeofVar: 1,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_chAreaPortalBits",
      offset: 36,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_81[2],
      pVarName: "m_chAreaPortalBits",
      offset: 36,
      sizeofVar: 1,
      elements: 24,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_81[3],
      pVarName: "m_iHideHUD",
      offset: 60,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[4],
      pVarName: "m_flFOVRate",
      offset: 64,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[5],
      pVarName: "m_bDucked",
      offset: 80,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[6],
      pVarName: "m_bDucking",
      offset: 81,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[7],
      pVarName: "m_bInDuckJump",
      offset: 82,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[8],
      pVarName: "m_nDuckTimeMsecs",
      offset: 84,
      sizeofVar: 4,
      nBits: 10,
      flags: 262145,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[9],
      pVarName: "m_nDuckJumpTimeMsecs",
      offset: 88,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[10],
      pVarName: "m_nJumpTimeMsecs",
      offset: 92,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[11],
      pVarName: "m_flFallVelocity",
      offset: 100,
      sizeofVar: 4,
      nBits: 17,
      flags: 0x40000,
      fLowValue: -4096.0,
      fHighValue: 4096.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[12],
      pVarName: "m_vecPunchAngle",
      offset: 1048688,
      sizeofVar: 12,
      nBits: -1,
      flags: 262146,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[13],
      pVarName: "m_vecPunchAngleVel",
      offset: 1048700,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[14],
      pVarName: "m_bDrawViewmodel",
      offset: 136,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[15],
      pVarName: "m_bWearingSuit",
      offset: 137,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_81[16], pVarName: "m_bPoisoned", offset: 138, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_81[17],
      pVarName: "m_flStepSize",
      offset: 140,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 128.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[18],
      pVarName: "m_bAllowAutoMovement",
      offset: 144,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[19],
      pVarName: "m_skybox3d.scale",
      offset: 152,
      sizeofVar: 4,
      nBits: 12,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[20],
      pVarName: "m_skybox3d.origin",
      offset: 1048732,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[21],
      pVarName: "m_skybox3d.area",
      offset: 168,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[22],
      pVarName: "m_skybox3d.fog.enable",
      offset: 240,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[23],
      pVarName: "m_skybox3d.fog.blend",
      offset: 241,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[24],
      pVarName: "m_skybox3d.fog.dirPrimary",
      offset: 1048752,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[25],
      pVarName: "m_skybox3d.fog.colorPrimary",
      offset: 188,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[26],
      pVarName: "m_skybox3d.fog.colorSecondary",
      offset: 192,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[27],
      pVarName: "m_skybox3d.fog.start",
      offset: 204,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[28],
      pVarName: "m_skybox3d.fog.end",
      offset: 208,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[29],
      pVarName: "m_skybox3d.fog.maxdensity",
      offset: 216,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_81[30],
      pVarName: "m_skybox3d.fog.HDRColorScale",
      offset: 244,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[31],
      pVarName: "m_audio.localSound[0]",
      offset: 388,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[32],
      pVarName: "m_audio.localSound[1]",
      offset: 400,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[33],
      pVarName: "m_audio.localSound[2]",
      offset: 412,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[34],
      pVarName: "m_audio.localSound[3]",
      offset: 424,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[35],
      pVarName: "m_audio.localSound[4]",
      offset: 436,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[36],
      pVarName: "m_audio.localSound[5]",
      offset: 448,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[37],
      pVarName: "m_audio.localSound[6]",
      offset: 460,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_81[38],
      pVarName: "m_audio.localSound[7]",
      offset: 472,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[39],
      pVarName: "m_audio.soundscapeIndex",
      offset: 484,
      sizeofVar: 4,
      nBits: 17,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[40],
      pVarName: "m_audio.localBits",
      offset: 488,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_81[41],
      pVarName: "m_audio.entIndex",
      offset: 492,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Local::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Local::g_SendTable,
    pProps: &g_SendProps_81[1],
    nProps: 41,
    pNetTableName: g_pSendTableName_81);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D1380
// Name: int ServerClassInit<struct DT_PointCamera::ignored>(struct DT_PointCamera::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PointCamera::ignored>()
{
  if ( (_S3_98 & 1) == 0 )
  {
    _S3_98 |= 1u;
    SendPropInt(
      result: g_SendProps_82,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_82[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_82[2],
      pVarName: "m_FOV",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_82[3],
      pVarName: "m_Resolution",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_82[4],
      pVarName: "m_bFogEnable",
      offset: 868,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_82[5],
      pVarName: "m_FogColor",
      offset: 869,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_82[6],
      pVarName: "m_flFogStart",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_82[7],
      pVarName: "m_flFogEnd",
      offset: 880,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_82[8],
      pVarName: "m_flFogMaxDensity",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_82[9],
      pVarName: "m_bActive",
      offset: 888,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_82[10],
      pVarName: "m_bUseScreenAspectRatio",
      offset: 889,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PointCamera::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PointCamera::g_SendTable,
    pProps: &g_SendProps_82[1],
    nProps: 10,
    pNetTableName: g_pSendTableName_82);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D3670
// Name: int ServerClassInit<struct DT_PoseController::ignored>(struct DT_PoseController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PoseController::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S3_99 & 1) == 0 )
  {
    _S3_99 |= 1u;
    SendPropInt(
      result: g_SendProps_83,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_83[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropEHandle(
      result: &v1,
      pVarName: "m_hProps",
      offset: 852,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropArray3(
      result: &g_SendProps_83[2],
      pVarName: "m_hProps",
      offset: 852,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_chPoseIndex",
      offset: 868,
      sizeofVar: 1,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_83[3],
      pVarName: "m_chPoseIndex",
      offset: 868,
      sizeofVar: 1,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropBool(result: &g_SendProps_83[4], pVarName: "m_bPoseValueParity", offset: 873, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_83[5],
      pVarName: "m_fPoseValue",
      offset: 884,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_83[6],
      pVarName: "m_fInterpolationTime",
      offset: 888,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 10.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_83[7], pVarName: "m_bInterpolationWrap", offset: 892, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_83[8],
      pVarName: "m_fCycleFrequency",
      offset: 896,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: -10.0,
      fHighValue: 10.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_83[9],
      pVarName: "m_nFModType",
      offset: 900,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_83[10],
      pVarName: "m_fFModTimeOffset",
      offset: 904,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: -1.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_83[11],
      pVarName: "m_fFModRate",
      offset: 908,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: -10.0,
      fHighValue: 10.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_83[12],
      pVarName: "m_fFModAmplitude",
      offset: 912,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 10.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PoseController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PoseController::g_SendTable,
    pProps: &g_SendProps_83[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_83);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DB790
// Name: int ServerClassInit<struct DT_PostProcessController::ignored>(struct DT_PostProcessController::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PostProcessController::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S3_103 & 1) == 0 )
  {
    _S3_103 |= 1u;
    SendPropInt(
      result: g_SendProps_84,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_84[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flPostProcessParameters",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_84[2],
      pVarName: "m_flPostProcessParameters",
      offset: 852,
      sizeofVar: 4,
      elements: 11,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropBool(result: &g_SendProps_84[3], pVarName: "m_bMaster", offset: 896, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_PostProcessController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PostProcessController::g_SendTable,
    pProps: &g_SendProps_84[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_84);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DD0B0
// Name: int ServerClassInit<struct DT_PredictedViewModel::ignored>(struct DT_PredictedViewModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PredictedViewModel::ignored>()
{
  if ( (_S2_187 & 1) == 0 )
  {
    _S2_187 |= 1u;
    SendPropInt(
      result: g_SendProps_85,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_85[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseViewModel::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PredictedViewModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PredictedViewModel::g_SendTable,
    pProps: &g_SendProps_85[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_85);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DD320
// Name: int ServerClassInit<struct DT_Prop_Hallucination::ignored>(struct DT_Prop_Hallucination::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Prop_Hallucination::ignored>()
{
  if ( (_S3_104 & 1) == 0 )
  {
    _S3_104 |= 1u;
    SendPropInt(
      result: g_SendProps_86,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_86[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_86[2], pVarName: "m_bEnabled", offset: 1164, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_86[3],
      pVarName: "m_fVisibleTime",
      offset: 1172,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_86[4],
      pVarName: "m_fRechargeTime",
      offset: 1176,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Prop_Hallucination::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Prop_Hallucination::g_SendTable,
    pProps: &g_SendProps_86[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_86);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DE920
// Name: int ServerClassInit<struct DT_DynamicProp::ignored>(struct DT_DynamicProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DynamicProp::ignored>()
{
  if ( (_S6_21 & 1) == 0 )
  {
    _S6_21 |= 1u;
    SendPropInt(
      result: g_SendProps_87,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_87[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBreakableProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_87[2], pVarName: "m_bUseHitboxesForRenderBox", offset: 1596, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_DynamicProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DynamicProp::g_SendTable,
    pProps: &g_SendProps_87[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_87);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEA70
// Name: int ServerClassInit<struct DT_PhysicsProp::ignored>(struct DT_PhysicsProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PhysicsProp::ignored>()
{
  if ( (_S9_7 & 1) == 0 )
  {
    _S9_7 |= 1u;
    SendPropInt(
      result: g_SendProps_88,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_88[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBreakableProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_88[2], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPoseParameter");
    SendPropExclude(result: &g_SendProps_88[3], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPlaybackRate");
    SendPropExclude(result: &g_SendProps_88[4], pDataTableName: "DT_BaseAnimating", pPropName: "m_nMuzzleFlashParity");
    SendPropExclude(result: &g_SendProps_88[5], pDataTableName: "DT_BaseAnimatingOverlay", pPropName: "overlay_vars");
    SendPropExclude(result: &g_SendProps_88[6], pDataTableName: "DT_BaseFlex", pPropName: "m_flexWeight");
    SendPropExclude(result: &g_SendProps_88[7], pDataTableName: "DT_BaseFlex", pPropName: "m_blinktoggle");
    SendPropBool(result: &g_SendProps_88[8], pVarName: "m_bAwake", offset: 1772, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_PhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PhysicsProp::g_SendTable,
    pProps: &g_SendProps_88[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_88);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DEC30
// Name: int ServerClassInit<struct DT_BasePropDoor::ignored>(struct DT_BasePropDoor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BasePropDoor::ignored>()
{
  if ( (_S12_2 & 1) == 0 )
  {
    _S12_2 |= 1u;
    SendPropInt(
      result: g_SendProps_89,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_89[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CDynamicProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_89[2], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPoseParameter");
    SendPropExclude(result: &g_SendProps_89[3], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPlaybackRate");
    SendPropExclude(result: &g_SendProps_89[4], pDataTableName: "DT_BaseAnimating", pPropName: "m_nMuzzleFlashParity");
    SendPropExclude(result: &g_SendProps_89[5], pDataTableName: "DT_BaseAnimatingOverlay", pPropName: "overlay_vars");
    SendPropExclude(result: &g_SendProps_89[6], pDataTableName: "DT_BaseFlex", pPropName: "m_flexWeight");
    SendPropExclude(result: &g_SendProps_89[7], pDataTableName: "DT_BaseFlex", pPropName: "m_blinktoggle");
    atexit(func: ServerClassInit_DT_BasePropDoor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BasePropDoor::g_SendTable,
    pProps: &g_SendProps_89[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_89);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DF4B0
// Name: int ServerClassInit<struct DT_PropDoorRotating::ignored>(struct DT_PropDoorRotating::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PropDoorRotating::ignored>()
{
  if ( (_S14_1 & 1) == 0 )
  {
    _S14_1 |= 1u;
    SendPropInt(
      result: g_SendProps_90,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_90[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBasePropDoor::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PropDoorRotating::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PropDoorRotating::g_SendTable,
    pProps: &g_SendProps_90[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_90);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DFAE0
// Name: int ServerClassInit<struct DT_PhysBoxMultiplayer::ignored>(struct DT_PhysBoxMultiplayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PhysBoxMultiplayer::ignored>()
{
  if ( (_S17_1 & 1) == 0 )
  {
    _S17_1 |= 1u;
    SendPropInt(
      result: g_SendProps_91,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_91[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CPhysBox::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_91[2],
      pVarName: "m_iPhysicsMode",
      offset: 1268,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_91[3],
      pVarName: "m_fMass",
      offset: 1272,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PhysBoxMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PhysBoxMultiplayer::g_SendTable,
    pProps: &g_SendProps_91[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_91);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DFBC0
// Name: int ServerClassInit<struct DT_PhysicsPropMultiplayer::ignored>(struct DT_PhysicsPropMultiplayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PhysicsPropMultiplayer::ignored>()
{
  if ( (_S19_0 & 1) == 0 )
  {
    _S19_0 |= 1u;
    SendPropInt(
      result: g_SendProps_92,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_92[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CPhysicsProp::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_92[2],
      pVarName: "m_iPhysicsMode",
      offset: 1780,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_92[3],
      pVarName: "m_fMass",
      offset: 1784,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_92[4],
      pVarName: "m_collisionMins",
      offset: 1050368,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_92[5],
      pVarName: "m_collisionMaxs",
      offset: 1050380,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PhysicsPropMultiplayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PhysicsPropMultiplayer::g_SendTable,
    pProps: &g_SendProps_92[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_92);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E0870
// Name: int ServerClassInit<struct DT_BreakableProp::ignored>(struct DT_BreakableProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BreakableProp::ignored>()
{
  if ( (_S3_105 & 1) == 0 )
  {
    _S3_105 |= 1u;
    SendPropInt(
      result: g_SendProps_93,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_93[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_93[2],
      pVarName: "m_qPreferredPlayerCarryAngles",
      offset: 1050072,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_93[3], pVarName: "m_bClientPhysics", offset: 1508, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_BreakableProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BreakableProp::g_SendTable,
    pProps: &g_SendProps_93[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_93);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F1BC0
// Name: int ServerClassInit<struct DT_RagdollManager::ignored>(struct DT_RagdollManager::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_RagdollManager::ignored>()
{
  if ( (_S2_191 & 1) == 0 )
  {
    _S2_191 |= 1u;
    SendPropInt(
      result: g_SendProps_94,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_94[1],
      pVarName: "m_iCurrentMaxRagdollCount",
      offset: 852,
      sizeofVar: 4,
      nBits: 6,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_RagdollManager::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_RagdollManager::g_SendTable,
    pProps: &g_SendProps_94[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_94);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5730
// Name: int ServerClassInit<struct DT_RopeKeyframe::ignored>(struct DT_RopeKeyframe::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_RopeKeyframe::ignored>()
{
  if ( (_S2_193 & 1) == 0 )
  {
    _S2_193 |= 1u;
    SendPropInt(
      result: g_SendProps_95,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_95[1],
      pVarName: "m_hStartPoint",
      offset: 920,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropEHandle(
      result: &g_SendProps_95[2],
      pVarName: "m_hEndPoint",
      offset: 924,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_95[3],
      pVarName: "m_iStartAttachment",
      offset: 928,
      sizeofVar: 2,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[4],
      pVarName: "m_iEndAttachment",
      offset: 930,
      sizeofVar: 2,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[5],
      pVarName: "m_Slack",
      offset: 864,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[6],
      pVarName: "m_RopeLength",
      offset: 900,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[7],
      pVarName: "m_fLockedPoints",
      offset: 904,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[8],
      pVarName: "m_nChangeCount",
      offset: 896,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[9],
      pVarName: "m_RopeFlags",
      offset: 856,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[10],
      pVarName: "m_nSegments",
      offset: 876,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_95[11], pVarName: "m_bConstrainBetweenEndpoints", offset: 880, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_95[12],
      pVarName: "m_iRopeMaterialModelIndex",
      offset: 888,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[13],
      pVarName: "m_Subdiv",
      offset: 892,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_95[14],
      pVarName: "m_TextureScale",
      offset: 872,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      fLowValue: 0.1,
      fHighValue: 10.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_95[15],
      pVarName: "m_Width",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_95[16],
      pVarName: "m_flScrollSpeed",
      offset: 912,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_95[17],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_95[18],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_95[19],
      pVarName: "m_iParentAttachment",
      offset: 213,
      sizeofVar: 1,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[20],
      pVarName: "m_nMinCPULevel",
      offset: 504,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[21],
      pVarName: "m_nMaxCPULevel",
      offset: 505,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[22],
      pVarName: "m_nMinGPULevel",
      offset: 506,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_95[23],
      pVarName: "m_nMaxGPULevel",
      offset: 507,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_RopeKeyframe::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_RopeKeyframe::g_SendTable,
    pProps: &g_SendProps_95[1],
    nProps: 23,
    pNetTableName: g_pSendTableName_95);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10205E60
// Name: int ServerClassInit<struct DT_SceneEntity::ignored>(struct DT_SceneEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SceneEntity::ignored>()
{
  SendProp v1; // [esp-48h] [ebp-58h] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+Ch] [ebp-4h]

  if ( (_S4_51 & 1) == 0 )
  {
    _S4_51 |= 1u;
    SendPropInt(
      result: g_SendProps_96,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_96[1],
      pVarName: "m_nSceneStringIndex",
      offset: 1024,
      sizeofVar: 4,
      nBits: 13,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_96[2], pVarName: "m_bIsPlayingBack", offset: 936, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_96[3], pVarName: "m_bPaused", offset: 937, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_96[4], pVarName: "m_bMultiplayer", offset: 938, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_96[5],
      pVarName: "m_flForceClientTime",
      offset: 940,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    v2 = SendProxy_DataTableToDataTable;
    SendPropEHandle(result: &v1, pVarName: nullptr, offset: 0, flags: 0, sizeofVar: -1, proxyFn: SendProxy_EHandleToInt);
    SendPropUtlVector(
      result: &g_SendProps_96[6],
      pVarName: "m_hActorList",
      offset: 980,
      sizeofVar: 4,
      ensureFn: UtlVectorTemplate<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>::EnsureCapacity,
      nMaxElements: 16,
      pArrayProp: v1,
      varProxy: v2);
    atexit(func: ServerClassInit_DT_SceneEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SceneEntity::g_SendTable,
    pProps: &g_SendProps_96[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_96);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10212F10
// Name: int ServerClassInit<struct DT_ShadowControl::ignored>(struct DT_ShadowControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ShadowControl::ignored>()
{
  if ( (_S3_112 & 1) == 0 )
  {
    _S3_112 |= 1u;
    SendPropInt(
      result: g_SendProps_97,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_97[1],
      pVarName: "m_shadowDirection",
      offset: 1049428,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_97[2],
      pVarName: "m_shadowColor",
      offset: 864,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_97[3],
      pVarName: "m_flShadowMaxDist",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_97[4], pVarName: "m_bDisableShadows", offset: 872, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_97[5], pVarName: "m_bEnableLocalLightShadows", offset: 873, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_ShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ShadowControl::g_SendTable,
    pProps: &g_SendProps_97[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_97);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10214440
// Name: int ServerClassInit<struct DT_SlideshowDisplay::ignored>(struct DT_SlideshowDisplay::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SlideshowDisplay::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S3_115 & 1) == 0 )
  {
    _S3_115 |= 1u;
    SendPropInt(
      result: g_SendProps_98,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_98[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_98[2], pVarName: "m_bEnabled", offset: 852, sizeofVar: 1);
    SendPropString(
      result: &g_SendProps_98[3],
      pVarName: "m_szDisplayText",
      offset: 853,
      bufferLen: 128,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_98[4],
      pVarName: "m_szSlideshowDirectory",
      offset: 981,
      bufferLen: 128,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_chCurrentSlideLists",
      offset: 1136,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_98[5],
      pVarName: "m_chCurrentSlideLists",
      offset: 1136,
      sizeofVar: 1,
      elements: 16,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropFloat(
      result: &g_SendProps_98[6],
      pVarName: "m_fMinSlideTime",
      offset: 1152,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 20.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_98[7],
      pVarName: "m_fMaxSlideTime",
      offset: 1156,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 20.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_98[8],
      pVarName: "m_iCycleType",
      offset: 1160,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_98[9], pVarName: "m_bNoListRepeats", offset: 1164, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_SlideshowDisplay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SlideshowDisplay::g_SendTable,
    pProps: &g_SendProps_98[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_98);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10221C50
// Name: int ServerClassInit<struct DT_SpatialEntity::ignored>(struct DT_SpatialEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SpatialEntity::ignored>()
{
  if ( (_S3_119 & 1) == 0 )
  {
    _S3_119 |= 1u;
    SendPropInt(
      result: g_SendProps_99,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_99[1],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Origin,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_99[2],
      pVarName: "m_MinFalloff",
      offset: 884,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_99[3],
      pVarName: "m_MaxFalloff",
      offset: 888,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_99[4],
      pVarName: "m_flCurWeight",
      offset: 892,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_99[5], pVarName: "m_bEnabled", offset: 881, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_SpatialEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SpatialEntity::g_SendTable,
    pProps: &g_SendProps_99[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_99);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10222FB0
// Name: int ServerClassInit<struct DT_SpotlightEnd::ignored>(struct DT_SpotlightEnd::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SpotlightEnd::ignored>()
{
  if ( (_S2_209 & 1) == 0 )
  {
    _S2_209 |= 1u;
    SendPropInt(
      result: g_SendProps_100,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_100[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_100[2],
      pVarName: "m_flLightScale",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_100[3],
      pVarName: "m_Radius",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SpotlightEnd::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SpotlightEnd::g_SendTable,
    pProps: &g_SendProps_100[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_100);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102234B0
// Name: int ServerClassInit<struct DT_SpriteOriented::ignored>(struct DT_SpriteOriented::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SpriteOriented::ignored>()
{
  if ( (_S4_57 & 1) == 0 )
  {
    _S4_57 |= 1u;
    SendPropInt(
      result: g_SendProps_101,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_101[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CSprite::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SpriteOriented::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SpriteOriented::g_SendTable,
    pProps: &g_SendProps_101[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_101);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10223540
// Name: int ServerClassInit<struct DT_Sprite::ignored>(struct DT_Sprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Sprite::ignored>()
{
  if ( (_S3_121 & 1) == 0 )
  {
    _S3_121 |= 1u;
    SendPropInt(
      result: g_SendProps_102,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_102[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_102[2],
      pVarName: "m_hAttachedToEntity",
      offset: 852,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_102[3],
      pVarName: "m_nAttachment",
      offset: 856,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[4],
      pVarName: "m_flScaleTime",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[5],
      pVarName: "m_flSpriteScale",
      offset: 880,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 64.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[6],
      pVarName: "m_flGlowProxySize",
      offset: 892,
      sizeofVar: 4,
      nBits: 6,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 64.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[7],
      pVarName: "m_flHDRColorScale",
      offset: 896,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[8],
      pVarName: "m_flSpriteFramerate",
      offset: 860,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 60.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[9],
      pVarName: "m_flFrame",
      offset: 864,
      sizeofVar: 4,
      nBits: 20,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 256.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_102[10],
      pVarName: "m_flBrightnessTime",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_102[11],
      pVarName: "m_nBrightness",
      offset: 872,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_102[12], pVarName: "m_bWorldSpaceScale", offset: 888, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_Sprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Sprite::g_SendTable,
    pProps: &g_SendProps_102[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_102);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10224C00
// Name: int ServerClassInit<struct DT_ParticlePerformanceMonitor::ignored>(struct DT_ParticlePerformanceMonitor::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ParticlePerformanceMonitor::ignored>()
{
  if ( (_S3_122 & 1) == 0 )
  {
    _S3_122 |= 1u;
    SendPropInt(
      result: g_SendProps_103,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_103[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_103[2],
      pVarName: "m_bDisplayPerf",
      offset: 852,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_103[3],
      pVarName: "m_bMeasurePerf",
      offset: 853,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ParticlePerformanceMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ParticlePerformanceMonitor::g_SendTable,
    pProps: &g_SendProps_103[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_103);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022B550
// Name: int ServerClassInit<struct DT_BaseToggle::ignored>(struct DT_BaseToggle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseToggle::ignored>()
{
  if ( (_S4_58 & 1) == 0 )
  {
    _S4_58 |= 1u;
    SendPropInt(
      result: g_SendProps_104,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_104[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_104[2],
      pVarName: "m_vecFinalDest",
      offset: 1049512,
      sizeofVar: 12,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_104[3],
      pVarName: "m_movementType",
      offset: 960,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_104[4],
      pVarName: "m_flMoveTargetTime",
      offset: 964,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseToggle::g_SendTable,
    pProps: &g_SendProps_104[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_104);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022BD70
// Name: int ServerClassInit<struct DT_Sun::ignored>(struct DT_Sun::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Sun::ignored>()
{
  if ( (_S2_213 & 1) == 0 )
  {
    _S2_213 |= 1u;
    SendPropInt(
      result: g_SendProps_105,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[1],
      pVarName: "m_clrRender",
      offset: 184,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[2],
      pVarName: "m_clrOverlay",
      offset: 892,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_105[3],
      pVarName: "m_vDirection",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 0,
      flags: 32,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[4],
      pVarName: "m_bOn",
      offset: 896,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[5],
      pVarName: "m_nSize",
      offset: 884,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[6],
      pVarName: "m_nOverlaySize",
      offset: 888,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[7],
      pVarName: "m_nMaterial",
      offset: 900,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_105[8],
      pVarName: "m_nOverlayMaterial",
      offset: 904,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_105[9],
      pVarName: "HDRColorScale",
      offset: 908,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Sun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Sun::g_SendTable,
    pProps: &g_SendProps_105[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_105);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022C790
// Name: int ServerClassInit<struct DT_SunlightShadowControl::ignored>(struct DT_SunlightShadowControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SunlightShadowControl::ignored>()
{
  if ( (_S3_125 & 1) == 0 )
  {
    _S3_125 |= 1u;
    SendPropInt(
      result: g_SendProps_106,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_106[1],
      pVarName: "m_shadowDirection",
      offset: 1049428,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_106[2], pVarName: "m_bEnabled", offset: 864, sizeofVar: 1);
    SendPropString(
      result: &g_SendProps_106[3],
      pVarName: "m_TextureName",
      offset: 866,
      bufferLen: 260,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_106[4],
      pVarName: "m_LightColor",
      offset: 1126,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_106[5],
      pVarName: "m_flColorTransitionTime",
      offset: 1132,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_106[6],
      pVarName: "m_flSunDistance",
      offset: 1136,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_106[7],
      pVarName: "m_flFOV",
      offset: 1140,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_106[8],
      pVarName: "m_flNearZ",
      offset: 1144,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_106[9],
      pVarName: "m_flNorthOffset",
      offset: 1148,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_106[10], pVarName: "m_bEnableShadows", offset: 1152, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_SunlightShadowControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SunlightShadowControl::g_SendTable,
    pProps: &g_SendProps_106[1],
    nProps: 10,
    pNetTableName: g_pSendTableName_106);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022F3F0
// Name: int ServerClassInit<struct DT_Team::ignored>(struct DT_Team::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Team::ignored>()
{
  if ( (_S2_217 & 1) == 0 )
  {
    _S2_217 |= 1u;
    SendPropInt(
      result: g_SendProps_107,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_107[1],
      pVarName: "m_iTeamNum",
      offset: 940,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_107[2],
      pVarName: "m_iScore",
      offset: 924,
      sizeofVar: 4,
      nBits: 0,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_107[3],
      pVarName: "m_iRoundsWon",
      offset: 928,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropString(
      result: &g_SendProps_107[4],
      pVarName: "m_szTeamname",
      offset: 892,
      bufferLen: 32,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_107[5],
      pVarName: "player_array_element",
      offset: 0,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: SendProxy_PlayerList,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_107[6],
      elementCount: 64,
      elementStride: 0,
      pName: "\"player_array\"",
      arrayLengthFn: SendProxyArrayLength_PlayerArray,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Team::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Team::g_SendTable,
    pProps: &g_SendProps_107[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_107);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022FC90
// Name: int ServerClassInit<struct DT_BaseTeamObjectiveResource::ignored>(struct DT_BaseTeamObjectiveResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseTeamObjectiveResource::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S2_218 & 1) == 0 )
  {
    _S2_218 |= 1u;
    SendPropInt(
      result: g_SendProps_108,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_108[1],
      pVarName: "m_iTimerToShowInHUD",
      offset: 852,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_108[2],
      pVarName: "m_iStopWatchTimer",
      offset: 856,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_108[3],
      pVarName: "m_iNumControlPoints",
      offset: 860,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_108[4], pVarName: "m_bPlayingMiniRounds", offset: 864, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_108[5], pVarName: "m_bControlPointsReset", offset: 865, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_108[6],
      pVarName: "m_iUpdateCapHudParity",
      offset: 868,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_108[7],
      pVarName: "m_vCPPositions",
      offset: 872,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_108[8],
      elementCount: 8,
      elementStride: 12,
      pName: "m_vCPPositions",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bCPIsVisible",
      offset: 968,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[9],
      pVarName: "m_bCPIsVisible",
      offset: 968,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flLazyCapPerc",
      offset: 1000,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[10],
      pVarName: "m_flLazyCapPerc",
      offset: 1000,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeamIcons",
      offset: 1032,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[11],
      pVarName: "m_iTeamIcons",
      offset: 1032,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeamOverlays",
      offset: 1288,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[12],
      pVarName: "m_iTeamOverlays",
      offset: 1288,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeamReqCappers",
      offset: 1544,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[13],
      pVarName: "m_iTeamReqCappers",
      offset: 1544,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropTime(result: &v1, pVarName: "m_flTeamCapTime", offset: 1800, sizeofVar: 4);
    SendPropArray3(
      result: &g_SendProps_108[14],
      pVarName: "m_flTeamCapTime",
      offset: 1800,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iPreviousPoints",
      offset: 2056,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[15],
      pVarName: "m_iPreviousPoints",
      offset: 2056,
      sizeofVar: 4,
      elements: 192,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropBool(result: &v1, pVarName: "m_bTeamCanCap", offset: 2824, sizeofVar: 1);
    SendPropArray3(
      result: &g_SendProps_108[16],
      pVarName: "m_bTeamCanCap",
      offset: 2824,
      sizeofVar: 1,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeamBaseIcons",
      offset: 2888,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[17],
      pVarName: "m_iTeamBaseIcons",
      offset: 2888,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iBaseControlPoints",
      offset: 3016,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[18],
      pVarName: "m_iBaseControlPoints",
      offset: 3016,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropBool(result: &v1, pVarName: "m_bInMiniRound", offset: 3144, sizeofVar: 1);
    SendPropArray3(
      result: &g_SendProps_108[19],
      pVarName: "m_bInMiniRound",
      offset: 3144,
      sizeofVar: 1,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iWarnOnCap",
      offset: 3152,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[20],
      pVarName: "m_iWarnOnCap",
      offset: 3152,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropStringT(result: &g_SendProps_108[21], pVarName: "m_iszWarnSound", offset: 3184, sizeofVar: 4);
    InternalSendPropArray(
      result: &g_SendProps_108[22],
      elementCount: 8,
      elementStride: 4,
      pName: "m_iszWarnSound",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_flPathDistance",
      offset: 3216,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[23],
      pVarName: "m_flPathDistance",
      offset: 3216,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iNumTeamMembers",
      offset: 3248,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[24],
      pVarName: "m_iNumTeamMembers",
      offset: 3248,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iCappingTeam",
      offset: 3504,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[25],
      pVarName: "m_iCappingTeam",
      offset: 3504,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iTeamInZone",
      offset: 3536,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[26],
      pVarName: "m_iTeamInZone",
      offset: 3536,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bBlocked",
      offset: 3568,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[27],
      pVarName: "m_bBlocked",
      offset: 3568,
      sizeofVar: 1,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iOwner",
      offset: 3576,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_108[28],
      pVarName: "m_iOwner",
      offset: 3576,
      sizeofVar: 4,
      elements: 8,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropString(
      result: &g_SendProps_108[29],
      pVarName: "m_pszCapLayoutInHUD",
      offset: 3608,
      bufferLen: 32,
      flags: 0,
      varProxy: SendProxy_StringToString,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseTeamObjectiveResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseTeamObjectiveResource::g_SendTable,
    pProps: &g_SendProps_108[1],
    nProps: 29,
    pNetTableName: g_pSendTableName_108);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10231690
// Name: int ServerClassInit<struct DT_TeamplayRoundBasedRules::ignored>(struct DT_TeamplayRoundBasedRules::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TeamplayRoundBasedRules::ignored>()
{
  SendProp v1; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v3; // [esp+68h] [ebp-4h]

  if ( (_S2_220 & 1) == 0 )
  {
    _S2_220 |= 1u;
    SendPropInt(
      result: g_SendProps_109,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_109[1],
      pVarName: "m_iRoundState",
      offset: 772,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_109[2], pVarName: "m_bInWaitingForPlayers", offset: 788, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_109[3],
      pVarName: "m_iWinningTeam",
      offset: 780,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_109[4], pVarName: "m_bInOvertime", offset: 776, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_109[5], pVarName: "m_bInSetup", offset: 777, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_109[6], pVarName: "m_bSwitchedTeamsThisRound", offset: 778, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_109[7], pVarName: "m_bAwaitingReadyRestart", offset: 789, sizeofVar: 1);
    SendPropTime(result: &g_SendProps_109[8], pVarName: "m_flRestartRoundTime", offset: 792, sizeofVar: 4);
    SendPropTime(result: &g_SendProps_109[9], pVarName: "m_flMapResetTime", offset: 796, sizeofVar: 4);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropTime(result: &v1, pVarName: "m_flNextRespawnWave", offset: 800, sizeofVar: 4);
    SendPropArray3(
      result: &g_SendProps_109[10],
      pVarName: "m_flNextRespawnWave",
      offset: 800,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v1,
      pVarName: "m_TeamRespawnWaveTimes",
      offset: 964,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_109[11],
      pVarName: "m_TeamRespawnWaveTimes",
      offset: 964,
      sizeofVar: 4,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropBool(result: &v1, pVarName: "m_bTeamReady", offset: 928, sizeofVar: 1);
    SendPropArray3(
      result: &g_SendProps_109[12],
      pVarName: "m_bTeamReady",
      offset: 928,
      sizeofVar: 1,
      elements: 32,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropBool(result: &g_SendProps_109[13], pVarName: "m_bStopWatch", offset: 960, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_TeamplayRoundBasedRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TeamplayRoundBasedRules::g_SendTable,
    pProps: &g_SendProps_109[1],
    nProps: 13,
    pNetTableName: g_pSendTableName_109);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10231940
// Name: int ServerClassInit<struct DT_TeamplayRoundBasedRulesProxy::ignored>(struct DT_TeamplayRoundBasedRulesProxy::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TeamplayRoundBasedRulesProxy::ignored>()
{
  if ( (_S3_130 & 1) == 0 )
  {
    _S3_130 |= 1u;
    SendPropInt(
      result: g_SendProps_110,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_110[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CGameRulesProxy::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_110[2],
      pVarName: "teamplayroundbased_gamerules_data",
      offset: 0,
      pTable: &DT_TeamplayRoundBasedRules::g_SendTable,
      varProxy: SendProxy_TeamplayRoundBasedRules,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TeamplayRoundBasedRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TeamplayRoundBasedRulesProxy::g_SendTable,
    pProps: &g_SendProps_110[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_110);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10232B20
// Name: int ServerClassInit<struct DT_Tesla::ignored>(struct DT_Tesla::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Tesla::ignored>()
{
  if ( (_S3_131 & 1) == 0 )
  {
    _S3_131 |= 1u;
    SendPropInt(
      result: g_SendProps_111,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_111[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropStringT(result: &g_SendProps_111[2], pVarName: "m_SoundName", offset: 856, sizeofVar: 4);
    SendPropStringT(result: &g_SendProps_111[3], pVarName: "m_iszSpriteName", offset: 904, sizeofVar: 4);
    atexit(func: ServerClassInit_DT_Tesla::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Tesla::g_SendTable,
    pProps: &g_SendProps_111[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_111);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10232F90
// Name: int ServerClassInit<struct DT_HandleTest::ignored>(struct DT_HandleTest::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_HandleTest::ignored>()
{
  if ( (_S2_223 & 1) == 0 )
  {
    _S2_223 |= 1u;
    SendPropInt(
      result: g_SendProps_112,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_112[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_112[2],
      pVarName: "m_Handle",
      offset: 852,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_112[3],
      pVarName: "m_bSendHandle",
      offset: 856,
      sizeofVar: 1,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_HandleTest::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_HandleTest::g_SendTable,
    pProps: &g_SendProps_112[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_112);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233380
// Name: int ServerClassInit<struct DT_ProxyToggle_ProxiedData::ignored>(struct DT_ProxyToggle_ProxiedData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ProxyToggle_ProxiedData::ignored>()
{
  if ( (_S2_224 & 1) == 0 )
  {
    _S2_224 |= 1u;
    SendPropInt(
      result: g_SendProps_113,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_113[1],
      pVarName: "m_WithProxy",
      offset: 852,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ProxyToggle_ProxiedData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ProxyToggle_ProxiedData::g_SendTable,
    pProps: &g_SendProps_113[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_113);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233430
// Name: int ServerClassInit<struct DT_ProxyToggle::ignored>(struct DT_ProxyToggle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ProxyToggle::ignored>()
{
  if ( (_S3_132 & 1) == 0 )
  {
    _S3_132 |= 1u;
    SendPropInt(
      result: g_SendProps_114,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_114[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_114[2],
      pVarName: "blah",
      offset: 0,
      pTable: &DT_ProxyToggle_ProxiedData::g_SendTable,
      varProxy: SendProxy_TestProxyToggle,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ProxyToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ProxyToggle::g_SendTable,
    pProps: &g_SendProps_114[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_114);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10233BE0
// Name: int ServerClassInit<struct DT_TestTraceline::ignored>(struct DT_TestTraceline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TestTraceline::ignored>()
{
  if ( (_S2_225 & 1) == 0 )
  {
    _S2_225 |= 1u;
    SendPropInt(
      result: g_SendProps_115,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_115[1],
      pVarName: "m_clrRender",
      offset: 184,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_115[2],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: 19,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_115[3],
      pVarName: "m_angRotation[0]",
      offset: 3146440,
      sizeofVar: 4,
      nBits: 19,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_115[4],
      pVarName: "m_angRotation[1]",
      offset: 3146444,
      sizeofVar: 4,
      nBits: 19,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_115[5],
      pVarName: "m_angRotation[2]",
      offset: 3146448,
      sizeofVar: 4,
      nBits: 19,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_115[6],
      pVarName: "moveparent",
      offset: 216,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_TestTraceline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TestTraceline::g_SendTable,
    pProps: &g_SendProps_115[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_115);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10235990
// Name: int ServerClassInit<struct DT_FuncTrackTrain::ignored>(struct DT_FuncTrackTrain::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FuncTrackTrain::ignored>()
{
  if ( (_S7_16 & 1) == 0 )
  {
    _S7_16 |= 1u;
    SendPropInt(
      result: g_SendProps_116,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_116[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FuncTrackTrain::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FuncTrackTrain::g_SendTable,
    pProps: &g_SendProps_116[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_116);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023DB70
// Name: int ServerClassInit<struct DT_TriggerPlayerMovement::ignored>(struct DT_TriggerPlayerMovement::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TriggerPlayerMovement::ignored>()
{
  if ( (_S24_0 & 1) == 0 )
  {
    _S24_0 |= 1u;
    SendPropInt(
      result: g_SendProps_117,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_117[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTrigger::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TriggerPlayerMovement::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TriggerPlayerMovement::g_SendTable,
    pProps: &g_SendProps_117[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_117);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023DBF0
// Name: int ServerClassInit<struct DT_BaseVPhysicsTrigger::ignored>(struct DT_BaseVPhysicsTrigger::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseVPhysicsTrigger::ignored>()
{
  if ( (_S27_0 & 1) == 0 )
  {
    _S27_0 |= 1u;
    SendPropInt(
      result: g_SendProps_118,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_118[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseVPhysicsTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseVPhysicsTrigger::g_SendTable,
    pProps: &g_SendProps_118[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_118);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023E450
// Name: int ServerClassInit<struct DT_BaseTrigger::ignored>(struct DT_BaseTrigger::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseTrigger::ignored>()
{
  if ( (_S3_135 & 1) == 0 )
  {
    _S3_135 |= 1u;
    SendPropInt(
      result: g_SendProps_119,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_119[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseToggle::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_119[2], pVarName: "m_bClientSidePredicted", offset: 1148, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_119[3],
      pVarName: "m_spawnflags",
      offset: 760,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseTrigger::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseTrigger::g_SendTable,
    pProps: &g_SendProps_119[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_119);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251370
// Name: int ServerClassInit<struct DT_CountdownTimer::ignored>(struct DT_CountdownTimer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CountdownTimer::ignored>()
{
  if ( (_S5_34 & 1) == 0 )
  {
    _S5_34 |= 1u;
    SendPropInt(
      result: g_SendProps_120,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_120[1],
      pVarName: "m_duration",
      offset: 4,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_120[2],
      pVarName: "m_timestamp",
      offset: 8,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CountdownTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CountdownTimer::g_SendTable,
    pProps: &g_SendProps_120[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_120);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251450
// Name: int ServerClassInit<struct DT_Timeline::ignored>(struct DT_Timeline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Timeline::ignored>()
{
  int v0; // eax
  int v1; // ecx
  SendProp v3; // [esp+10h] [ebp-5Ch] BYREF
  void *(__cdecl *v4)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+64h] [ebp-8h]
  int v5; // [esp+68h] [ebp-4h]

  if ( (_S7_18 & 1) == 0 )
  {
    _S7_18 |= 1u;
    SendPropInt(
      result: g_SendProps_121,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    v5 = 128;
    v4 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v3,
      pVarName: "m_flValues",
      offset: 8,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_121[1],
      pVarName: "m_flValues",
      offset: 8,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v3,
      varProxy: v4,
      priority: v5);
    v5 = 128;
    v4 = SendProxy_DataTableToDataTable;
    SendPropFloat(
      result: &v3,
      pVarName: "m_nValueCounts",
      offset: 264,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_121[2],
      pVarName: "m_nValueCounts",
      offset: 264,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v3,
      varProxy: v4,
      priority: v5);
    v0 = 64;
    v1 = 0;
    do
    {
      v0 >>= 1;
      ++v1;
    }
    while ( v0 > 0 );
    SendPropInt(
      result: &g_SendProps_121[3],
      pVarName: "m_nBucketCount",
      offset: 520,
      sizeofVar: 4,
      nBits: v1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_121[4],
      pVarName: "m_flInterval",
      offset: 524,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_121[5],
      pVarName: "m_flFinalValue",
      offset: 528,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_121[6],
      pVarName: "m_nCompressionType",
      offset: 532,
      sizeofVar: 4,
      nBits: -1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_121[7], pVarName: "m_bStopped", offset: 536, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_Timeline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Timeline::g_SendTable,
    pProps: &g_SendProps_121[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_121);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251FE0
// Name: int ServerClassInit<struct DT_IntervalTimer::ignored>(struct DT_IntervalTimer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_IntervalTimer::ignored>()
{
  if ( (_S4_64 & 1) == 0 )
  {
    _S4_64 |= 1u;
    SendPropInt(
      result: g_SendProps_122,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_122[1],
      pVarName: "m_timestamp",
      offset: 4,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_IntervalTimer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_IntervalTimer::g_SendTable,
    pProps: &g_SendProps_122[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_122);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102535D0
// Name: int ServerClassInit<struct DT_PropVehicleDriveable::ignored>(struct DT_PropVehicleDriveable::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PropVehicleDriveable::ignored>()
{
  if ( (_S4_65 & 1) == 0 )
  {
    _S4_65 |= 1u;
    SendPropInt(
      result: g_SendProps_123,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_123[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_123[2],
      pVarName: "m_hPlayer",
      offset: 1664,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_123[3],
      pVarName: "m_nSpeed",
      offset: 1668,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[4],
      pVarName: "m_nRPM",
      offset: 1672,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_123[5],
      pVarName: "m_flThrottle",
      offset: 1676,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[6],
      pVarName: "m_nBoostTimeLeft",
      offset: 1680,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[7],
      pVarName: "m_nHasBoost",
      offset: 1684,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[8],
      pVarName: "m_nScannerDisabledWeapons",
      offset: 1714,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[9],
      pVarName: "m_nScannerDisabledVehicle",
      offset: 1715,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[10],
      pVarName: "m_bEnterAnimOn",
      offset: 1732,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[11],
      pVarName: "m_bExitAnimOn",
      offset: 1733,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_123[12],
      pVarName: "m_bUnableToFire",
      offset: 1712,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_123[13],
      pVarName: "m_vecEyeExitEndpoint",
      offset: 1050264,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_123[14], pVarName: "m_bHasGun", offset: 1713, sizeofVar: 1);
    SendPropVector(
      result: &g_SendProps_123[15],
      pVarName: "m_vecGunCrosshair",
      offset: 1050276,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PropVehicleDriveable::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PropVehicleDriveable::g_SendTable,
    pProps: &g_SendProps_123[1],
    nProps: 15,
    pNetTableName: g_pSendTableName_123);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025C240
// Name: int ServerClassInit<struct DT_VGuiScreen::ignored>(struct DT_VGuiScreen::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_VGuiScreen::ignored>()
{
  if ( (_S2_233 & 1) == 0 )
  {
    _S2_233 |= 1u;
    SendPropInt(
      result: g_SendProps_124,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_124[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_124[2],
      pVarName: "m_flWidth",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_124[3],
      pVarName: "m_flHeight",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropIntWithMinusOneFlag(
      result: &g_SendProps_124[4],
      pVarName: "m_nAttachmentIndex",
      offset: 872,
      sizeofVar: 4,
      nBits: 6,
      proxyFn: SendProxy_IntAddOne);
    SendPropInt(
      result: &g_SendProps_124[5],
      pVarName: "m_nPanelName",
      offset: 868,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_124[6],
      pVarName: "m_fScreenFlags",
      offset: 880,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_124[7],
      pVarName: "m_nOverlayMaterial",
      offset: 876,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_124[8],
      pVarName: "m_hPlayerOwner",
      offset: 884,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_VGuiScreen::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_VGuiScreen::g_SendTable,
    pProps: &g_SendProps_124[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_124);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10263610
// Name: int ServerClassInit<struct DT_WaterBullet::ignored>(struct DT_WaterBullet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WaterBullet::ignored>()
{
  if ( (_S3_141 & 1) == 0 )
  {
    _S3_141 |= 1u;
    SendPropInt(
      result: g_SendProps_125,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_125[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WaterBullet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WaterBullet::g_SendTable,
    pProps: &g_SendProps_125[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_125);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102639D0
// Name: int ServerClassInit<struct DT_WaterLODControl::ignored>(struct DT_WaterLODControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WaterLODControl::ignored>()
{
  if ( (_S3_142 & 1) == 0 )
  {
    _S3_142 |= 1u;
    SendPropInt(
      result: g_SendProps_126,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_126[1],
      pVarName: "m_flCheapWaterStartDistance",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_126[2],
      pVarName: "m_flCheapWaterEndDistance",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WaterLODControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WaterLODControl::g_SendTable,
    pProps: &g_SendProps_126[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_126);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10267D00
// Name: int ServerClassInit<struct DT_WORLD::ignored>(struct DT_WORLD::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WORLD::ignored>()
{
  if ( (_S6_28 & 1) == 0 )
  {
    _S6_28 |= 1u;
    SendPropInt(
      result: g_SendProps_127,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_127[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_127[2],
      pVarName: "m_flWaveHeight",
      offset: 856,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 8.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_127[3],
      pVarName: "m_WorldMins",
      offset: 1049436,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_127[4],
      pVarName: "m_WorldMaxs",
      offset: 1049448,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_127[5],
      pVarName: "m_bStartDark",
      offset: 904,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_127[6],
      pVarName: "m_flMaxOccludeeArea",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_127[7],
      pVarName: "m_flMinOccluderArea",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_127[8],
      pVarName: "m_flMaxPropScreenSpaceWidth",
      offset: 896,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_127[9],
      pVarName: "m_flMinPropScreenSpaceWidth",
      offset: 892,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropStringT(result: &g_SendProps_127[10], pVarName: "m_iszDetailSpriteMaterial", offset: 900, sizeofVar: 4);
    SendPropInt(
      result: &g_SendProps_127[11],
      pVarName: "m_bColdWorld",
      offset: 905,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WORLD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WORLD::g_SendTable,
    pProps: &g_SendProps_127[1],
    nProps: 11,
    pNetTableName: g_pSendTableName_127);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10268E20
// Name: int ServerClassInit<struct DT_BaseCSGrenadeProjectile::ignored>(struct DT_BaseCSGrenadeProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseCSGrenadeProjectile::ignored>()
{
  if ( (_S3_144 & 1) == 0 )
  {
    _S3_144 |= 1u;
    SendPropInt(
      result: g_SendProps_128,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_128[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_128[2],
      pVarName: "m_vInitialVelocity",
      offset: 1049780,
      sizeofVar: 12,
      nBits: 20,
      flags: 0,
      fLowValue: -3000.0,
      fHighValue: 3000.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseCSGrenadeProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseCSGrenadeProjectile::g_SendTable,
    pProps: &g_SendProps_128[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_128);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026F0A0
// Name: int ServerClassInit<struct DT_CSGameRulesProxy::ignored>(struct DT_CSGameRulesProxy::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSGameRulesProxy::ignored>()
{
  if ( (_S3_145 & 1) == 0 )
  {
    _S3_145 |= 1u;
    SendPropInt(
      result: g_SendProps_129,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_129[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CGameRulesProxy::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_129[2],
      pVarName: "cs_gamerules_data",
      offset: 0,
      pTable: &DT_CSGameRules::g_SendTable,
      varProxy: SendProxy_CSGameRules,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSGameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSGameRulesProxy::g_SendTable,
    pProps: &g_SendProps_129[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_129);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10270FD0
// Name: int ServerClassInit<struct DT_CSGameRules::ignored>(struct DT_CSGameRules::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSGameRules::ignored>()
{
  if ( (_S2_241 & 1) == 0 )
  {
    _S2_241 |= 1u;
    SendPropInt(
      result: g_SendProps_130,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_130[1], pVarName: "m_bFreezePeriod", offset: 556, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_130[2],
      pVarName: "m_iRoundTime",
      offset: 560,
      sizeofVar: 4,
      nBits: 16,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_130[3],
      pVarName: "m_fRoundStartTime",
      offset: 564,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_130[4],
      pVarName: "m_flGameStartTime",
      offset: 568,
      sizeofVar: 4,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[5],
      pVarName: "m_iHostagesRemaining",
      offset: 572,
      sizeofVar: 4,
      nBits: 4,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_130[6], pVarName: "m_bMapHasBombTarget", offset: 576, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_130[7], pVarName: "m_bMapHasRescueZone", offset: 577, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_130[8], pVarName: "m_bLogoMap", offset: 578, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_130[9], pVarName: "m_bBlackMarket", offset: 579, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_130[10],
      pVarName: "m_iGunGameTRBombCTScore",
      offset: 584,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[11],
      pVarName: "m_iGunGameTRBombTScore",
      offset: 580,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_130[12], pVarName: "m_bGunGameTRBombModeHalftime", offset: 588, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_130[13],
      pVarName: "m_iNumGunGameProgressiveWeaponsCT",
      offset: 592,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[14],
      pVarName: "m_iNumGunGameProgressiveWeaponsT",
      offset: 596,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[15],
      pVarName: "m_iSpectatorSlotCount",
      offset: 600,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[16],
      pVarName: "m_GGProgressiveWeaponOrderCT",
      offset: 604,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_130[17],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponOrderCT",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[18],
      pVarName: "m_GGProgressiveWeaponOrderT",
      offset: 844,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_130[19],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponOrderT",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[20],
      pVarName: "m_GGProgressiveWeaponKillUpgradeOrderCT",
      offset: 1084,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_130[21],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponKillUpgradeOrderCT",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_130[22],
      pVarName: "m_GGProgressiveWeaponKillUpgradeOrderT",
      offset: 1324,
      sizeofVar: 4,
      nBits: 0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_130[23],
      elementCount: 60,
      elementStride: 4,
      pName: "m_GGProgressiveWeaponKillUpgradeOrderT",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSGameRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSGameRules::g_SendTable,
    pProps: &g_SendProps_130[1],
    nProps: 23,
    pNetTableName: g_pSendTableName_130);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E910
// Name: int ServerClassInit<struct DT_TEPlayerAnimEvent::ignored>(struct DT_TEPlayerAnimEvent::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEPlayerAnimEvent::ignored>()
{
  unsigned int v0; // eax

  if ( (_S3_146 & 1) == 0 )
  {
    _S3_146 |= 1u;
    SendPropInt(
      result: g_SendProps_131,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_131[1],
      pVarName: "m_hPlayer",
      offset: 12,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    v0 = Q_log2(val: 9u);
    SendPropInt(
      result: &g_SendProps_131[2],
      pVarName: "m_iEvent",
      offset: 16,
      sizeofVar: 4,
      nBits: v0 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_131[3],
      pVarName: "m_nData",
      offset: 20,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEPlayerAnimEvent::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEPlayerAnimEvent::g_SendTable,
    pProps: &g_SendProps_131[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_131);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E9E0
// Name: int ServerClassInit<struct DT_CSLocalPlayerExclusive::ignored>(struct DT_CSLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSLocalPlayerExclusive::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S4_68 & 1) == 0 )
  {
    _S4_68 |= 1u;
    SendPropInt(
      result: g_SendProps_132,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_132[1],
      pVarName: "m_flStamina",
      offset: 6016,
      sizeofVar: 4,
      nBits: 14,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1400.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_132[2],
      pVarName: "m_iDirection",
      offset: 6020,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_132[3],
      pVarName: "m_iShotsFired",
      offset: 6024,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_132[4],
      pVarName: "m_flVelocityModifier",
      offset: 6028,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVectorXY(
      result: &g_SendProps_132[5],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 262148,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_OriginXY,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_132[6],
      pVarName: "m_vecOrigin[2]",
      offset: 5243588,
      sizeofVar: 4,
      nBits: -1,
      flags: 262148,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_OriginZ,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropBool(result: &v1, pVarName: "m_bPlayerDominated", offset: 6741, sizeofVar: 1);
    SendPropArray3(
      result: &g_SendProps_132[7],
      pVarName: "m_bPlayerDominated",
      offset: 6741,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropBool(result: &v1, pVarName: "m_bPlayerDominatingMe", offset: 6806, sizeofVar: 1);
    SendPropArray3(
      result: &g_SendProps_132[8],
      pVarName: "m_bPlayerDominatingMe",
      offset: 6806,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    atexit(func: ServerClassInit_DT_CSLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSLocalPlayerExclusive::g_SendTable,
    pProps: &g_SendProps_132[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_132);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027EC10
// Name: int ServerClassInit<struct DT_CSNonLocalPlayerExclusive::ignored>(struct DT_CSNonLocalPlayerExclusive::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSNonLocalPlayerExclusive::ignored>()
{
  if ( (_S5_38 & 1) == 0 )
  {
    _S5_38 |= 1u;
    SendPropInt(
      result: g_SendProps_133,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVectorXY(
      result: &g_SendProps_133[1],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: 5,
      flags: 327680,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellOriginXY,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_133[2],
      pVarName: "m_vecOrigin[2]",
      offset: 5243588,
      sizeofVar: 4,
      nBits: 5,
      flags: 327680,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))CBaseEntity::SendProxy_CellOriginZ,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSNonLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSNonLocalPlayerExclusive::g_SendTable,
    pProps: &g_SendProps_133[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_133);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027ED00
// Name: int ServerClassInit<struct DT_CSPlayer::ignored>(struct DT_CSPlayer::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSPlayer::ignored>()
{
  unsigned int v0; // eax
  unsigned int v1; // eax

  if ( (_S6_29 & 1) == 0 )
  {
    _S6_29 |= 1u;
    SendPropInt(
      result: g_SendProps_134,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_134[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBasePlayer::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_134[2], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPoseParameter");
    SendPropExclude(result: &g_SendProps_134[3], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPlaybackRate");
    SendPropExclude(result: &g_SendProps_134[4], pDataTableName: "DT_BaseAnimating", pPropName: "m_nSequence");
    SendPropExclude(result: &g_SendProps_134[5], pDataTableName: "DT_BaseAnimating", pPropName: "m_nNewSequenceParity");
    SendPropExclude(result: &g_SendProps_134[6], pDataTableName: "DT_BaseAnimating", pPropName: "m_nResetEventsParity");
    SendPropExclude(result: &g_SendProps_134[7], pDataTableName: "DT_BaseAnimating", pPropName: "m_nMuzzleFlashParity");
    SendPropExclude(result: &g_SendProps_134[8], pDataTableName: "DT_BaseEntity", pPropName: "m_angRotation");
    SendPropExclude(result: &g_SendProps_134[9], pDataTableName: "DT_BaseAnimatingOverlay", pPropName: "overlay_vars");
    SendPropExclude(result: &g_SendProps_134[10], pDataTableName: "DT_ServerAnimationData", pPropName: "m_flCycle");
    SendPropExclude(result: &g_SendProps_134[11], pDataTableName: "DT_AnimTimeMustBeFirst", pPropName: "m_flAnimTime");
    SendPropExclude(result: &g_SendProps_134[12], pDataTableName: "DT_BaseEntity", pPropName: "m_vecOrigin");
    SendPropDataTable(
      result: &g_SendProps_134[13],
      pVarName: "cslocaldata",
      offset: 0,
      pTable: &DT_CSLocalPlayerExclusive::g_SendTable,
      varProxy: SendProxy_SendLocalDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_134[14],
      pVarName: "csnonlocaldata",
      offset: 0,
      pTable: &DT_CSNonLocalPlayerExclusive::g_SendTable,
      varProxy: SendProxy_SendNonLocalDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[15],
      pVarName: "m_iThrowGrenadeCounter",
      offset: 6100,
      sizeofVar: 4,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[16],
      pVarName: "m_iAddonBits",
      offset: 6388,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[17],
      pVarName: "m_iPrimaryAddon",
      offset: 6392,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[18],
      pVarName: "m_iSecondaryAddon",
      offset: 6396,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    v0 = Q_log2(val: 9u);
    SendPropInt(
      result: &g_SendProps_134[19],
      pVarName: "m_iPlayerState",
      offset: 4824,
      sizeofVar: 4,
      nBits: v0 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[20],
      pVarName: "m_iAccount",
      offset: 6400,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[21],
      pVarName: "m_bInBombZone",
      offset: 6000,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[22],
      pVarName: "m_bInBuyZone",
      offset: 6001,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_134[23], pVarName: "m_bKilledByTaser", offset: 6002, sizeofVar: 1);
    v1 = Q_log2(val: 0xAu);
    SendPropInt(
      result: &g_SendProps_134[24],
      pVarName: "m_iClass",
      offset: 6164,
      sizeofVar: 4,
      nBits: v1 + 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[25],
      pVarName: "m_ArmorValue",
      offset: 3660,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_134[26],
      pVarName: "m_angEyeAngles[0]",
      offset: 1054780,
      sizeofVar: 4,
      nBits: 11,
      flags: 0x40000,
      varProxy: SendProxy_AngleToFloat,
      priority: 3u);
    SendPropAngle(
      result: &g_SendProps_134[27],
      pVarName: "m_angEyeAngles[1]",
      offset: 1054784,
      sizeofVar: 4,
      nBits: 11,
      flags: 0x40000,
      varProxy: SendProxy_AngleToFloat,
      priority: 3u);
    SendPropBool(result: &g_SendProps_134[28], pVarName: "m_bHasDefuser", offset: 4956, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[29], pVarName: "m_bNightVisionOn", offset: 4958, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[30], pVarName: "m_bHasNightVision", offset: 4957, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[31], pVarName: "m_bInHostageRescueZone", offset: 6012, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[32], pVarName: "m_bIsDefusing", offset: 4880, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[33], pVarName: "m_bResumeZoom", offset: 4872, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_134[34],
      pVarName: "m_iLastZoom",
      offset: 4876,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_134[35], pVarName: "m_bGunGameImmunity", offset: 4881, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_134[36],
      pVarName: "m_iGunGameProgressiveWeaponIndex",
      offset: 4884,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[37],
      pVarName: "m_iNumGunGameTRKillPoints",
      offset: 4888,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_134[38],
      pVarName: "m_fMolotovUseTime",
      offset: 4892,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_134[39], pVarName: "m_bHasHelmet", offset: 4900, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_134[40],
      pVarName: "m_flFlashDuration",
      offset: 6084,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_134[41],
      pVarName: "m_flFlashMaxAlpha",
      offset: 6088,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_134[42],
      pVarName: "m_iProgressBarDuration",
      offset: 6096,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_134[43],
      pVarName: "m_flProgressBarStartTime",
      offset: 6092,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_134[44],
      pVarName: "m_hRagdoll",
      offset: 6104,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_134[45],
      pVarName: "m_cycleLatch",
      offset: 6532,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_134[46], pVarName: "m_bIsControllingBot", offset: 7019, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_134[47], pVarName: "m_bCanControlObservedBot", offset: 7020, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_134[48],
      pVarName: "m_iControlledBotEntIndex",
      offset: 7024,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSPlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSPlayer::g_SendTable,
    pProps: &g_SendProps_134[1],
    nProps: 48,
    pNetTableName: g_pSendTableName_134);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10280D30
// Name: int ServerClassInit<struct DT_CSRagdoll::ignored>(struct DT_CSRagdoll::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSRagdoll::ignored>()
{
  if ( (_S2_242 & 1) == 0 )
  {
    _S2_242 |= 1u;
    SendPropInt(
      result: g_SendProps_135,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_135[1],
      pVarName: "m_vecOrigin",
      offset: 5243580,
      sizeofVar: 12,
      nBits: -1,
      flags: 262146,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: (void (__cdecl *)(const SendProp *, const void *, const void *, DVariant *, int, int))SendProxy_Origin,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_135[2],
      pVarName: "m_vecRagdollOrigin",
      offset: 1049776,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_135[3],
      pVarName: "m_hPlayer",
      offset: 1184,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    SendPropInt(
      result: &g_SendProps_135[4],
      pVarName: "m_nModelIndex",
      offset: 182,
      sizeofVar: 2,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_135[5],
      pVarName: "m_nForceBone",
      offset: 860,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_135[6],
      pVarName: "m_vecForce",
      offset: 1049440,
      sizeofVar: 12,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_135[7],
      pVarName: "m_vecRagdollVelocity",
      offset: 1049764,
      sizeofVar: 12,
      nBits: 32,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_135[8],
      pVarName: "m_iDeathPose",
      offset: 1212,
      sizeofVar: 4,
      nBits: 12,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_135[9],
      pVarName: "m_iDeathFrame",
      offset: 1216,
      sizeofVar: 4,
      nBits: 5,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_135[10],
      pVarName: "m_iTeamNum",
      offset: 756,
      sizeofVar: 4,
      nBits: 6,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_135[11],
      pVarName: "m_bClientSideAnimation",
      offset: 1060,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSRagdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSRagdoll::g_SendTable,
    pProps: &g_SendProps_135[1],
    nProps: 11,
    pNetTableName: g_pSendTableName_135);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10292480
// Name: int ServerClassInit<struct DT_CSPlayerResource::ignored>(struct DT_CSPlayerResource::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSPlayerResource::ignored>()
{
  SendProp v1; // [esp-4Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp+8h] [ebp-8h]
  int v3; // [esp+Ch] [ebp-4h]

  if ( (_S2_243 & 1) == 0 )
  {
    _S2_243 |= 1u;
    SendPropInt(
      result: g_SendProps_136,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_136[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CPlayerResource::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_136[2],
      pVarName: "m_iPlayerC4",
      offset: 2676,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_136[3],
      pVarName: "m_iPlayerDefuser",
      offset: 2680,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_136[4],
      pVarName: "m_iPlayerVIP",
      offset: 2684,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_136[5],
      pVarName: "m_vecC4",
      offset: 1051264,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_136[6],
      pVarName: "m_vecDefuser",
      offset: 1051276,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bHostageAlive",
      offset: 2712,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[7],
      pVarName: "m_bHostageAlive",
      offset: 2712,
      sizeofVar: 1,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_isHostageFollowingSomeone",
      offset: 2724,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[8],
      pVarName: "m_isHostageFollowingSomeone",
      offset: 2724,
      sizeofVar: 1,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iHostageEntityIDs",
      offset: 2736,
      sizeofVar: 4,
      nBits: -1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[9],
      pVarName: "m_iHostageEntityIDs",
      offset: 2736,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iHostageY",
      offset: 2832,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[10],
      pVarName: "m_iHostageY",
      offset: 2832,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iHostageX",
      offset: 2784,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[11],
      pVarName: "m_iHostageX",
      offset: 2784,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iHostageZ",
      offset: 2880,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[12],
      pVarName: "m_iHostageZ",
      offset: 2880,
      sizeofVar: 4,
      elements: 12,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropVector(
      result: &g_SendProps_136[13],
      pVarName: "m_bombsiteCenterA",
      offset: 1051504,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_136[14],
      pVarName: "m_bombsiteCenterB",
      offset: 1051516,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_hostageRescueX",
      offset: 2952,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[15],
      pVarName: "m_hostageRescueX",
      offset: 2952,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_hostageRescueY",
      offset: 2968,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[16],
      pVarName: "m_hostageRescueY",
      offset: 2968,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_hostageRescueZ",
      offset: 2984,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[17],
      pVarName: "m_hostageRescueZ",
      offset: 2984,
      sizeofVar: 4,
      elements: 4,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropBool(result: &g_SendProps_136[18], pVarName: "m_bBombSpotted", offset: 3000, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_136[19], pVarName: "m_bDefuserSpotted", offset: 3001, sizeofVar: 1);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bPlayerSpotted",
      offset: 3002,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[20],
      pVarName: "m_bPlayerSpotted",
      offset: 3002,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iMVPs",
      offset: 3068,
      sizeofVar: 4,
      nBits: 15,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[21],
      pVarName: "m_iMVPs",
      offset: 3068,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iArmor",
      offset: 3328,
      sizeofVar: 4,
      nBits: 15,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[22],
      pVarName: "m_iArmor",
      offset: 3328,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bHasDefuser",
      offset: 3588,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[23],
      pVarName: "m_bHasDefuser",
      offset: 3588,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iScore",
      offset: 3656,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[24],
      pVarName: "m_iScore",
      offset: 3656,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bVote",
      offset: 3916,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[25],
      pVarName: "m_bVote",
      offset: 3916,
      sizeofVar: 1,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_bControllingBot",
      offset: 3984,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[26],
      pVarName: "m_bControllingBot",
      offset: 3984,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iControlledPlayer",
      offset: 4244,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[27],
      pVarName: "m_iControlledPlayer",
      offset: 4244,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_iControlledByPlayer",
      offset: 4504,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_136[28],
      pVarName: "m_iControlledByPlayer",
      offset: 4504,
      sizeofVar: 4,
      elements: 65,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    atexit(func: ServerClassInit_DT_CSPlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSPlayerResource::g_SendTable,
    pProps: &g_SendProps_136[1],
    nProps: 28,
    pNetTableName: g_pSendTableName_136);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10294EB0
// Name: int ServerClassInit<struct DT_FootstepControl::ignored>(struct DT_FootstepControl::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FootstepControl::ignored>()
{
  if ( (_S3_148 & 1) == 0 )
  {
    _S3_148 |= 1u;
    SendPropInt(
      result: g_SendProps_137,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_137[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTrigger::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropStringT(result: &g_SendProps_137[2], pVarName: "m_source", offset: 1152, sizeofVar: 4);
    SendPropStringT(result: &g_SendProps_137[3], pVarName: "m_destination", offset: 1156, sizeofVar: 4);
    atexit(func: ServerClassInit_DT_FootstepControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FootstepControl::g_SendTable,
    pProps: &g_SendProps_137[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_137);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10297E60
// Name: int ServerClassInit<struct DT_CSTeam::ignored>(struct DT_CSTeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CSTeam::ignored>()
{
  if ( (_S2_246 & 1) == 0 )
  {
    _S2_246 |= 1u;
    SendPropInt(
      result: g_SendProps_138,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_138[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_CSTeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CSTeam::g_SendTable,
    pProps: &g_SendProps_138[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_138);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10298200
// Name: int ServerClassInit<struct DT_PropJeep::ignored>(struct DT_PropJeep::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PropJeep::ignored>()
{
  if ( (_S4_69 & 1) == 0 )
  {
    _S4_69 |= 1u;
    SendPropInt(
      result: g_SendProps_139,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_139[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CPropVehicleDriveable::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_139[2], pVarName: "m_bHeadlightIsOn", offset: 1961, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_PropJeep::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PropJeep::g_SendTable,
    pProps: &g_SendProps_139[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_139);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10299CC0
// Name: int ServerClassInit<struct DT_DecoyProjectile::ignored>(struct DT_DecoyProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DecoyProjectile::ignored>()
{
  if ( (_S2_248 & 1) == 0 )
  {
    _S2_248 |= 1u;
    SendPropInt(
      result: g_SendProps_140,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_140[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenadeProjectile::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_DecoyProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DecoyProjectile::g_SendTable,
    pProps: &g_SendProps_140[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_140);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A4B30
// Name: int ServerClassInit<struct DT_MolotovProjectile::ignored>(struct DT_MolotovProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_MolotovProjectile::ignored>()
{
  if ( (_S2_256 & 1) == 0 )
  {
    _S2_256 |= 1u;
    SendPropInt(
      result: g_SendProps_141,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_141[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenadeProjectile::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_MolotovProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_MolotovProjectile::g_SendTable,
    pProps: &g_SendProps_141[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_141);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A6330
// Name: int ServerClassInit<struct DT_TERadioIcon::ignored>(struct DT_TERadioIcon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TERadioIcon::ignored>()
{
  if ( (_S2_259 & 1) == 0 )
  {
    _S2_259 |= 1u;
    SendPropInt(
      result: g_SendProps_142,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_142[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_142[2],
      pVarName: "m_iAttachToClient",
      offset: 12,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TERadioIcon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TERadioIcon::g_SendTable,
    pProps: &g_SendProps_142[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_142);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A64A0
// Name: int ServerClassInit<struct DT_TEPlantBomb::ignored>(struct DT_TEPlantBomb::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEPlantBomb::ignored>()
{
  if ( (_S3_151 & 1) == 0 )
  {
    _S3_151 |= 1u;
    SendPropInt(
      result: g_SendProps_143,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_143[1],
      pVarName: "m_vecOrigin",
      offset: 1048592,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_143[2],
      pVarName: "m_iPlayer",
      offset: 12,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_143[3],
      pVarName: "m_option",
      offset: 28,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEPlantBomb::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEPlantBomb::g_SendTable,
    pProps: &g_SendProps_143[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_143);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A6580
// Name: int ServerClassInit<struct DT_TEFireBullets::ignored>(struct DT_TEFireBullets::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEFireBullets::ignored>()
{
  if ( (_S2_260 & 1) == 0 )
  {
    _S2_260 |= 1u;
    SendPropInt(
      result: g_SendProps_144,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_144[1],
      pVarName: "m_vecOrigin",
      offset: 1048592,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_144[2],
      pVarName: "m_vecAngles[0]",
      offset: 1048604,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_144[3],
      pVarName: "m_vecAngles[1]",
      offset: 1048608,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_144[4],
      pVarName: "m_iWeaponID",
      offset: 40,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_144[5],
      pVarName: "m_iMode",
      offset: 44,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_144[6],
      pVarName: "m_iSeed",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_144[7],
      pVarName: "m_iPlayer",
      offset: 12,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_144[8],
      pVarName: "m_fInaccuracy",
      offset: 52,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_144[9],
      pVarName: "m_fSpread",
      offset: 56,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 0.1,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEFireBullets::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEFireBullets::g_SendTable,
    pProps: &g_SendProps_144[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_144);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D8910
// Name: int ServerClassInit<struct DT_FireCrackerBlast::ignored>(struct DT_FireCrackerBlast::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FireCrackerBlast::ignored>()
{
  if ( (_S4_70 & 1) == 0 )
  {
    _S4_70 |= 1u;
    SendPropInt(
      result: g_SendProps_145,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_145[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CInferno::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FireCrackerBlast::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FireCrackerBlast::g_SendTable,
    pProps: &g_SendProps_145[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_145);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D90A0
// Name: int ServerClassInit<struct DT_Inferno::ignored>(struct DT_Inferno::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Inferno::ignored>()
{
  SendProp v1; // [esp-5Ch] [ebp-5Ch] BYREF
  void *(__cdecl *v2)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int); // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  if ( (_S2_264 & 1) == 0 )
  {
    _S2_264 |= 1u;
    SendPropInt(
      result: g_SendProps_146,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_146[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_fireXDelta",
      offset: 852,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_146[2],
      pVarName: "m_fireXDelta",
      offset: 852,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_fireYDelta",
      offset: 1108,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_146[3],
      pVarName: "m_fireYDelta",
      offset: 1108,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    v3 = 128;
    v2 = SendProxy_DataTableToDataTable;
    SendPropInt(
      result: &v1,
      pVarName: "m_fireZDelta",
      offset: 1364,
      sizeofVar: 4,
      nBits: 15,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropArray3(
      result: &g_SendProps_146[4],
      pVarName: "m_fireZDelta",
      offset: 1364,
      sizeofVar: 4,
      elements: 64,
      pArrayProp: v1,
      varProxy: v2,
      priority: v3);
    SendPropInt(
      result: &g_SendProps_146[5],
      pVarName: "m_fireCount",
      offset: 2388,
      sizeofVar: 4,
      nBits: 7,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Inferno::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Inferno::g_SendTable,
    pProps: &g_SendProps_146[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_146);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DC1B0
// Name: int ServerClassInit<struct DT_CHostage::ignored>(struct DT_CHostage::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_CHostage::ignored>()
{
  if ( (_S3_153 & 1) == 0 )
  {
    _S3_153 |= 1u;
    SendPropInt(
      result: g_SendProps_147,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_147[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCombatCharacter::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_147[2], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPoseParameter");
    SendPropExclude(result: &g_SendProps_147[3], pDataTableName: "DT_BaseAnimating", pPropName: "m_flPlaybackRate");
    SendPropExclude(result: &g_SendProps_147[4], pDataTableName: "DT_BaseAnimating", pPropName: "m_nSequence");
    SendPropExclude(result: &g_SendProps_147[5], pDataTableName: "DT_BaseAnimating", pPropName: "m_nNewSequenceParity");
    SendPropExclude(result: &g_SendProps_147[6], pDataTableName: "DT_BaseAnimating", pPropName: "m_nResetEventsParity");
    SendPropExclude(result: &g_SendProps_147[7], pDataTableName: "DT_BaseAnimatingOverlay", pPropName: "overlay_vars");
    SendPropExclude(result: &g_SendProps_147[8], pDataTableName: "DT_ServerAnimationData", pPropName: "m_flCycle");
    SendPropExclude(result: &g_SendProps_147[9], pDataTableName: "DT_AnimTimeMustBeFirst", pPropName: "m_flAnimTime");
    SendPropBool(result: &g_SendProps_147[10], pVarName: "m_isRescued", offset: 2296, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_147[11],
      pVarName: "m_iHealth",
      offset: 528,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_147[12],
      pVarName: "m_iMaxHealth",
      offset: 524,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_147[13],
      pVarName: "m_lifeState",
      offset: 553,
      sizeofVar: 1,
      nBits: 3,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_147[14],
      pVarName: "m_leader",
      offset: 2300,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_CHostage::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_CHostage::g_SendTable,
    pProps: &g_SendProps_147[1],
    nProps: 14,
    pNetTableName: g_pSendTableName_147);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E2AB0
// Name: int ServerClassInit<struct DT_WeaponAK47::ignored>(struct DT_WeaponAK47::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponAK47::ignored>()
{
  if ( (_S2_266 & 1) == 0 )
  {
    _S2_266 |= 1u;
    SendPropInt(
      result: g_SendProps_148,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_148[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponAK47::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponAK47::g_SendTable,
    pProps: &g_SendProps_148[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_148);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E2E70
// Name: int ServerClassInit<struct DT_WeaponAug::ignored>(struct DT_WeaponAug::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponAug::ignored>()
{
  if ( (_S2_267 & 1) == 0 )
  {
    _S2_267 |= 1u;
    SendPropInt(
      result: g_SendProps_149,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_149[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponAug::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponAug::g_SendTable,
    pProps: &g_SendProps_149[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_149);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E33C0
// Name: int ServerClassInit<struct DT_WeaponAWP::ignored>(struct DT_WeaponAWP::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponAWP::ignored>()
{
  if ( (_S2_268 & 1) == 0 )
  {
    _S2_268 |= 1u;
    SendPropInt(
      result: g_SendProps_150,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_150[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponAWP::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponAWP::g_SendTable,
    pProps: &g_SendProps_150[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_150);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E3A00
// Name: int ServerClassInit<struct DT_BaseCSGrenade::ignored>(struct DT_BaseCSGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseCSGrenade::ignored>()
{
  if ( (_S2_269 & 1) == 0 )
  {
    _S2_269 |= 1u;
    SendPropInt(
      result: g_SendProps_151,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_151[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_151[2], pVarName: "m_bRedraw", offset: 1472, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_151[3], pVarName: "m_bPinPulled", offset: 1473, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_151[4],
      pVarName: "m_fThrowTime",
      offset: 1476,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_151[5], pVarName: "m_bLoopingSoundPlaying", offset: 1480, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_BaseCSGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseCSGrenade::g_SendTable,
    pProps: &g_SendProps_151[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_151);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E4C00
// Name: int ServerClassInit<struct DT_WeaponBizon::ignored>(struct DT_WeaponBizon::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponBizon::ignored>()
{
  if ( (_S2_270 & 1) == 0 )
  {
    _S2_270 |= 1u;
    SendPropInt(
      result: g_SendProps_152,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_152[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponBizon::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponBizon::g_SendTable,
    pProps: &g_SendProps_152[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_152);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E5070
// Name: int ServerClassInit<struct DT_WeaponC4::ignored>(struct DT_WeaponC4::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponC4::ignored>()
{
  if ( (_S5_40 & 1) == 0 )
  {
    _S5_40 |= 1u;
    SendPropInt(
      result: g_SendProps_153,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_153[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_153[2], pVarName: "m_bStartedArming", offset: 1472, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_153[3], pVarName: "m_bBombPlacedAnimation", offset: 1480, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_153[4],
      pVarName: "m_fArmedTime",
      offset: 1476,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponC4::g_SendTable,
    pProps: &g_SendProps_153[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_153);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E5340
// Name: int ServerClassInit<struct DT_PlantedC4::ignored>(struct DT_PlantedC4::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_PlantedC4::ignored>()
{
  if ( (_S3_156 & 1) == 0 )
  {
    _S3_156 |= 1u;
    SendPropInt(
      result: g_SendProps_154,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_154[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseAnimating::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_154[2], pVarName: "m_bBombTicking", offset: 1164, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_154[3],
      pVarName: "m_flC4Blow",
      offset: 1168,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_154[4],
      pVarName: "m_flTimerLength",
      offset: 1176,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_154[5],
      pVarName: "m_flDefuseLength",
      offset: 1196,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_154[6],
      pVarName: "m_flDefuseCountDown",
      offset: 1200,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_PlantedC4::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_PlantedC4::g_SendTable,
    pProps: &g_SendProps_154[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_154);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E8A60
// Name: int ServerClassInit<struct DT_WeaponCSBase::ignored>(struct DT_WeaponCSBase::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponCSBase::ignored>()
{
  if ( (_S2_272 & 1) == 0 )
  {
    _S2_272 |= 1u;
    SendPropInt(
      result: g_SendProps_155,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_155[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCombatWeapon::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_155[2],
      pVarName: "m_weaponMode",
      offset: 1404,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_155[3],
      pVarName: "m_fAccuracyPenalty",
      offset: 1408,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_155[4],
      pVarName: "m_bWaitForNoAttack",
      offset: 1453,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropExclude(result: &g_SendProps_155[5], pDataTableName: "DT_AnimTimeMustBeFirst", pPropName: "m_flAnimTime");
    SendPropExclude(result: &g_SendProps_155[6], pDataTableName: "DT_BaseAnimating", pPropName: "m_nSequence");
    atexit(func: ServerClassInit_DT_WeaponCSBase::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponCSBase::g_SendTable,
    pProps: &g_SendProps_155[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_155);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EA7B0
// Name: int ServerClassInit<struct DT_WeaponCSBaseGun::ignored>(struct DT_WeaponCSBaseGun::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponCSBaseGun::ignored>()
{
  if ( (_S2_273 & 1) == 0 )
  {
    _S2_273 |= 1u;
    SendPropInt(
      result: g_SendProps_156,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_156[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponCSBaseGun::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponCSBaseGun::g_SendTable,
    pProps: &g_SendProps_156[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_156);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EAEA0
// Name: int ServerClassInit<struct DT_WeaponDEagle::ignored>(struct DT_WeaponDEagle::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponDEagle::ignored>()
{
  if ( (_S2_274 & 1) == 0 )
  {
    _S2_274 |= 1u;
    SendPropInt(
      result: g_SendProps_157,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_157[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponDEagle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponDEagle::g_SendTable,
    pProps: &g_SendProps_157[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_157);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EB010
// Name: int ServerClassInit<struct DT_DecoyGrenade::ignored>(struct DT_DecoyGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DecoyGrenade::ignored>()
{
  if ( (_S2_275 & 1) == 0 )
  {
    _S2_275 |= 1u;
    SendPropInt(
      result: g_SendProps_158,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_158[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_DecoyGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DecoyGrenade::g_SendTable,
    pProps: &g_SendProps_158[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_158);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EB340
// Name: int ServerClassInit<struct DT_WeaponElite::ignored>(struct DT_WeaponElite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponElite::ignored>()
{
  if ( (_S2_276 & 1) == 0 )
  {
    _S2_276 |= 1u;
    SendPropInt(
      result: g_SendProps_159,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_159[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponElite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponElite::g_SendTable,
    pProps: &g_SendProps_159[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_159);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EB4F0
// Name: int ServerClassInit<struct DT_WeaponFamas::ignored>(struct DT_WeaponFamas::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponFamas::ignored>()
{
  if ( (_S2_277 & 1) == 0 )
  {
    _S2_277 |= 1u;
    SendPropInt(
      result: g_SendProps_160,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_160[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_160[2], pVarName: "m_bBurstMode", offset: 1472, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_160[3],
      pVarName: "m_iBurstShotsRemaining",
      offset: 1476,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponFamas::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponFamas::g_SendTable,
    pProps: &g_SendProps_160[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_160);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE90
// Name: int ServerClassInit<struct DT_WeaponFiveSeven::ignored>(struct DT_WeaponFiveSeven::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponFiveSeven::ignored>()
{
  if ( (_S2_278 & 1) == 0 )
  {
    _S2_278 |= 1u;
    SendPropInt(
      result: g_SendProps_161,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_161[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponFiveSeven::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponFiveSeven::g_SendTable,
    pProps: &g_SendProps_161[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_161);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EC070
// Name: int ServerClassInit<struct DT_Flashbang::ignored>(struct DT_Flashbang::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Flashbang::ignored>()
{
  if ( (_S2_279 & 1) == 0 )
  {
    _S2_279 |= 1u;
    SendPropInt(
      result: g_SendProps_162,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_162[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Flashbang::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Flashbang::g_SendTable,
    pProps: &g_SendProps_162[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_162);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EC1F0
// Name: int ServerClassInit<struct DT_WeaponG3SG1::ignored>(struct DT_WeaponG3SG1::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponG3SG1::ignored>()
{
  if ( (_S2_280 & 1) == 0 )
  {
    _S2_280 |= 1u;
    SendPropInt(
      result: g_SendProps_163,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_163[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponG3SG1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponG3SG1::g_SendTable,
    pProps: &g_SendProps_163[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_163);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EC6A0
// Name: int ServerClassInit<struct DT_WeaponGalil::ignored>(struct DT_WeaponGalil::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponGalil::ignored>()
{
  if ( (_S2_281 & 1) == 0 )
  {
    _S2_281 |= 1u;
    SendPropInt(
      result: g_SendProps_164,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_164[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponGalil::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponGalil::g_SendTable,
    pProps: &g_SendProps_164[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_164);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA90
// Name: int ServerClassInit<struct DT_WeaponGlock::ignored>(struct DT_WeaponGlock::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponGlock::ignored>()
{
  if ( (_S2_282 & 1) == 0 )
  {
    _S2_282 |= 1u;
    SendPropInt(
      result: g_SendProps_165,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_165[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_165[2], pVarName: "m_bBurstMode", offset: 1472, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_165[3],
      pVarName: "m_iBurstShotsRemaining",
      offset: 1476,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponGlock::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponGlock::g_SendTable,
    pProps: &g_SendProps_165[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_165);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED400
// Name: int ServerClassInit<struct DT_HEGrenade::ignored>(struct DT_HEGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_HEGrenade::ignored>()
{
  if ( (_S2_283 & 1) == 0 )
  {
    _S2_283 |= 1u;
    SendPropInt(
      result: g_SendProps_166,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_166[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_HEGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_HEGrenade::g_SendTable,
    pProps: &g_SendProps_166[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_166);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102ED580
// Name: int ServerClassInit<struct DT_WeaponHKP2000::ignored>(struct DT_WeaponHKP2000::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponHKP2000::ignored>()
{
  if ( (_S2_284 & 1) == 0 )
  {
    _S2_284 |= 1u;
    SendPropInt(
      result: g_SendProps_167,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_167[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponHKP2000::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponHKP2000::g_SendTable,
    pProps: &g_SendProps_167[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_167);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EDBC0
// Name: int ServerClassInit<struct DT_LocalActiveWeaponKnifeData::ignored>(struct DT_LocalActiveWeaponKnifeData::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_LocalActiveWeaponKnifeData::ignored>()
{
  if ( (_S2_285 & 1) == 0 )
  {
    _S2_285 |= 1u;
    SendPropInt(
      result: g_SendProps_168,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_168[1], pVarName: "m_flSmackTime", offset: 1560, sizeofVar: 4);
    atexit(func: ServerClassInit_DT_LocalActiveWeaponKnifeData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_LocalActiveWeaponKnifeData::g_SendTable,
    pProps: &g_SendProps_168[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_168);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EDC30
// Name: int ServerClassInit<struct DT_WeaponKnife::ignored>(struct DT_WeaponKnife::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponKnife::ignored>()
{
  if ( (_S3_161 & 1) == 0 )
  {
    _S3_161 |= 1u;
    SendPropInt(
      result: g_SendProps_169,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_169[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_169[2],
      pVarName: "LocalActiveWeaponKnifeData",
      offset: 0,
      pTable: &DT_LocalActiveWeaponKnifeData::g_SendTable,
      varProxy: SendProxy_SendActiveLocalKnifeDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponKnife::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponKnife::g_SendTable,
    pProps: &g_SendProps_169[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_169);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EEB20
// Name: int ServerClassInit<struct DT_WeaponM249::ignored>(struct DT_WeaponM249::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponM249::ignored>()
{
  if ( (_S2_286 & 1) == 0 )
  {
    _S2_286 |= 1u;
    SendPropInt(
      result: g_SendProps_170,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_170[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponM249::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponM249::g_SendTable,
    pProps: &g_SendProps_170[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_170);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EEFD0
// Name: int ServerClassInit<struct DT_WeaponM4A1::ignored>(struct DT_WeaponM4A1::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponM4A1::ignored>()
{
  if ( (_S2_287 & 1) == 0 )
  {
    _S2_287 |= 1u;
    SendPropInt(
      result: g_SendProps_171,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_171[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_171[2], pVarName: "m_bSilencerOn", offset: 1472, sizeofVar: 1);
    SendPropTime(result: &g_SendProps_171[3], pVarName: "m_flDoneSwitchingSilencer", offset: 1476, sizeofVar: 4);
    atexit(func: ServerClassInit_DT_WeaponM4A1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponM4A1::g_SendTable,
    pProps: &g_SendProps_171[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_171);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EFA50
// Name: int ServerClassInit<struct DT_WeaponMAC10::ignored>(struct DT_WeaponMAC10::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponMAC10::ignored>()
{
  if ( (_S2_288 & 1) == 0 )
  {
    _S2_288 |= 1u;
    SendPropInt(
      result: g_SendProps_172,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_172[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponMAC10::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponMAC10::g_SendTable,
    pProps: &g_SendProps_172[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_172);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EFDC0
// Name: int ServerClassInit<struct DT_WeaponMag7::ignored>(struct DT_WeaponMag7::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponMag7::ignored>()
{
  if ( (_S2_289 & 1) == 0 )
  {
    _S2_289 |= 1u;
    SendPropInt(
      result: g_SendProps_173,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_173[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponMag7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponMag7::g_SendTable,
    pProps: &g_SendProps_173[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_173);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EFF00
// Name: int ServerClassInit<struct DT_MolotovGrenade::ignored>(struct DT_MolotovGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_MolotovGrenade::ignored>()
{
  if ( (_S2_290 & 1) == 0 )
  {
    _S2_290 |= 1u;
    SendPropInt(
      result: g_SendProps_174,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_174[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_MolotovGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_MolotovGrenade::g_SendTable,
    pProps: &g_SendProps_174[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_174);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0120
// Name: int ServerClassInit<struct DT_WeaponMP7::ignored>(struct DT_WeaponMP7::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponMP7::ignored>()
{
  if ( (_S2_291 & 1) == 0 )
  {
    _S2_291 |= 1u;
    SendPropInt(
      result: g_SendProps_175,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_175[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponMP7::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponMP7::g_SendTable,
    pProps: &g_SendProps_175[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_175);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0490
// Name: int ServerClassInit<struct DT_WeaponMP9::ignored>(struct DT_WeaponMP9::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponMP9::ignored>()
{
  if ( (_S2_292 & 1) == 0 )
  {
    _S2_292 |= 1u;
    SendPropInt(
      result: g_SendProps_176,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_176[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponMP9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponMP9::g_SendTable,
    pProps: &g_SendProps_176[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_176);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0800
// Name: int ServerClassInit<struct DT_WeaponNegev::ignored>(struct DT_WeaponNegev::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponNegev::ignored>()
{
  if ( (_S2_293 & 1) == 0 )
  {
    _S2_293 |= 1u;
    SendPropInt(
      result: g_SendProps_177,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_177[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponNegev::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponNegev::g_SendTable,
    pProps: &g_SendProps_177[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_177);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F0910
// Name: int ServerClassInit<struct DT_WeaponNOVA::ignored>(struct DT_WeaponNOVA::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponNOVA::ignored>()
{
  if ( (_S2_294 & 1) == 0 )
  {
    _S2_294 |= 1u;
    SendPropInt(
      result: g_SendProps_178,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_178[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_178[2],
      pVarName: "m_reloadState",
      offset: 1476,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponNOVA::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponNOVA::g_SendTable,
    pProps: &g_SendProps_178[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_178);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F1080
// Name: int ServerClassInit<struct DT_WeaponP250::ignored>(struct DT_WeaponP250::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponP250::ignored>()
{
  if ( (_S2_295 & 1) == 0 )
  {
    _S2_295 |= 1u;
    SendPropInt(
      result: g_SendProps_179,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_179[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponP250::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponP250::g_SendTable,
    pProps: &g_SendProps_179[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_179);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F1180
// Name: int ServerClassInit<struct DT_WeaponP90::ignored>(struct DT_WeaponP90::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponP90::ignored>()
{
  if ( (_S2_296 & 1) == 0 )
  {
    _S2_296 |= 1u;
    SendPropInt(
      result: g_SendProps_180,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_180[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponP90::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponP90::g_SendTable,
    pProps: &g_SendProps_180[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_180);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F14D0
// Name: int ServerClassInit<struct DT_WeaponSawedoff::ignored>(struct DT_WeaponSawedoff::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponSawedoff::ignored>()
{
  if ( (_S2_297 & 1) == 0 )
  {
    _S2_297 |= 1u;
    SendPropInt(
      result: g_SendProps_181,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_181[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_181[2],
      pVarName: "m_reloadState",
      offset: 1476,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponSawedoff::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponSawedoff::g_SendTable,
    pProps: &g_SendProps_181[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_181);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F1E70
// Name: int ServerClassInit<struct DT_WeaponSCAR20::ignored>(struct DT_WeaponSCAR20::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponSCAR20::ignored>()
{
  if ( (_S2_298 & 1) == 0 )
  {
    _S2_298 |= 1u;
    SendPropInt(
      result: g_SendProps_182,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_182[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponSCAR20::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponSCAR20::g_SendTable,
    pProps: &g_SendProps_182[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_182);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F23C0
// Name: int ServerClassInit<struct DT_WeaponSG556::ignored>(struct DT_WeaponSG556::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponSG556::ignored>()
{
  if ( (_S2_299 & 1) == 0 )
  {
    _S2_299 |= 1u;
    SendPropInt(
      result: g_SendProps_183,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_183[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponSG556::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponSG556::g_SendTable,
    pProps: &g_SendProps_183[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_183);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F2940
// Name: int ServerClassInit<struct DT_SmokeGrenade::ignored>(struct DT_SmokeGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SmokeGrenade::ignored>()
{
  if ( (_S2_300 & 1) == 0 )
  {
    _S2_300 |= 1u;
    SendPropInt(
      result: g_SendProps_184,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_184[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseCSGrenade::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SmokeGrenade::g_SendTable,
    pProps: &g_SendProps_184[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_184);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F2B00
// Name: int ServerClassInit<struct DT_WeaponSSG08::ignored>(struct DT_WeaponSSG08::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponSSG08::ignored>()
{
  if ( (_S2_301 & 1) == 0 )
  {
    _S2_301 |= 1u;
    SendPropInt(
      result: g_SendProps_185,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_185[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponSSG08::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponSSG08::g_SendTable,
    pProps: &g_SendProps_185[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_185);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F3160
// Name: int ServerClassInit<struct DT_WeaponTaser::ignored>(struct DT_WeaponTaser::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponTaser::ignored>()
{
  if ( (_S2_302 & 1) == 0 )
  {
    _S2_302 |= 1u;
    SendPropInt(
      result: g_SendProps_186,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_186[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponTaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponTaser::g_SendTable,
    pProps: &g_SendProps_186[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_186);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F3290
// Name: int ServerClassInit<struct DT_WeaponTec9::ignored>(struct DT_WeaponTec9::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponTec9::ignored>()
{
  if ( (_S2_303 & 1) == 0 )
  {
    _S2_303 |= 1u;
    SendPropInt(
      result: g_SendProps_187,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_187[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponTec9::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponTec9::g_SendTable,
    pProps: &g_SendProps_187[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_187);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F33A0
// Name: int ServerClassInit<struct DT_WeaponUMP45::ignored>(struct DT_WeaponUMP45::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponUMP45::ignored>()
{
  if ( (_S2_304 & 1) == 0 )
  {
    _S2_304 |= 1u;
    SendPropInt(
      result: g_SendProps_188,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_188[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBaseGun::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponUMP45::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponUMP45::g_SendTable,
    pProps: &g_SendProps_188[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_188);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F3740
// Name: int ServerClassInit<struct DT_WeaponXM1014::ignored>(struct DT_WeaponXM1014::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_WeaponXM1014::ignored>()
{
  if ( (_S2_305 & 1) == 0 )
  {
    _S2_305 |= 1u;
    SendPropInt(
      result: g_SendProps_189,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_189[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CWeaponCSBase::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_189[2],
      pVarName: "m_reloadState",
      offset: 1476,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_WeaponXM1014::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_WeaponXM1014::g_SendTable,
    pProps: &g_SendProps_189[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_189);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103252E0
// Name: int ServerClassInit<struct DT_BaseTempEntity::ignored>(struct DT_BaseTempEntity::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseTempEntity::ignored>()
{
  if ( ((int)_S2_312.__vftable & 1) == 0 )
  {
    _S2_312.__vftable = (SendProp_vtbl *)((int)_S2_312.__vftable | 1);
    SendPropInt(
      result: g_SendProps_190,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseTempEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseTempEntity::g_SendTable,
    pProps: &_S2_312,
    nProps: 0,
    pNetTableName: g_pSendTableName_190);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103255E0
// Name: int ServerClassInit<struct DT_MovieExplosion::ignored>(struct DT_MovieExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_MovieExplosion::ignored>()
{
  if ( (_S2_313 & 1) == 0 )
  {
    _S2_313 |= 1u;
    SendPropInt(
      result: (SendProp *)&_S2_312.m_pMatchingRecvProp,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &pProps,
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_MovieExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_MovieExplosion::g_SendTable,
    pProps: &pProps,
    nProps: 1,
    pNetTableName: g_pSendTableName_191);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103256C0
// Name: int ServerClassInit<struct DT_ParticleFire::ignored>(struct DT_ParticleFire::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ParticleFire::ignored>()
{
  if ( (_S2_314 & 1) == 0 )
  {
    _S2_314 |= 1u;
    SendPropInt(
      result: g_SendProps_192,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_192[1],
      pVarName: "m_vOrigin",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 0,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_192[2],
      pVarName: "m_vDirection",
      offset: 1049440,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ParticleFire::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ParticleFire::g_SendTable,
    pProps: &g_SendProps_192[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_192);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10325920
// Name: int ServerClassInit<struct DT_ParticleSmokeGrenade::ignored>(struct DT_ParticleSmokeGrenade::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_ParticleSmokeGrenade::ignored>()
{
  if ( (_S2_315 & 1) == 0 )
  {
    _S2_315 |= 1u;
    SendPropInt(
      result: g_SendProps_193,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_193[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropTime(result: &g_SendProps_193[2], pVarName: "m_flSpawnTime", offset: 856, sizeofVar: 4);
    SendPropFloat(
      result: &g_SendProps_193[3],
      pVarName: "m_FadeStartTime",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_193[4],
      pVarName: "m_FadeEndTime",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_193[5],
      pVarName: "m_MinColor",
      offset: 868,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_193[6],
      pVarName: "m_MaxColor",
      offset: 880,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_193[7],
      pVarName: "m_CurrentStage",
      offset: 852,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_ParticleSmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_ParticleSmokeGrenade::g_SendTable,
    pProps: &g_SendProps_193[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_193);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10325E50
// Name: int ServerClassInit<struct DT_Plasma::ignored>(struct DT_Plasma::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_Plasma::ignored>()
{
  if ( (_S2_316 & 1) == 0 )
  {
    _S2_316 |= 1u;
    SendPropInt(
      result: g_SendProps_194,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_194[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_194[2],
      pVarName: "m_flScale",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_194[3],
      pVarName: "m_flScaleTime",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_194[4],
      pVarName: "m_nFlags",
      offset: 864,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_194[5],
      pVarName: "m_nPlasmaModelIndex",
      offset: 868,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_194[6],
      pVarName: "m_nPlasmaModelIndex2",
      offset: 872,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_194[7],
      pVarName: "m_nGlowModelIndex",
      offset: 876,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_Plasma::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_Plasma::g_SendTable,
    pProps: &g_SendProps_194[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_194);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103263B0
// Name: int ServerClassInit<struct DT_RocketTrail::ignored>(struct DT_RocketTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_RocketTrail::ignored>()
{
  if ( (_S4_75 & 1) == 0 )
  {
    _S4_75 |= 1u;
    SendPropInt(
      result: g_SendProps_195,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_195[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[2],
      pVarName: "m_SpawnRate",
      offset: 880,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 1.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_195[3],
      pVarName: "m_StartColor",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_195[4],
      pVarName: "m_EndColor",
      offset: 1049440,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[5],
      pVarName: "m_ParticleLifetime",
      offset: 884,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.1,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[6],
      pVarName: "m_StopEmitTime",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[7],
      pVarName: "m_MinSpeed",
      offset: 892,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[8],
      pVarName: "m_MaxSpeed",
      offset: 896,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[9],
      pVarName: "m_StartSize",
      offset: 900,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[10],
      pVarName: "m_EndSize",
      offset: 904,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[11],
      pVarName: "m_SpawnRadius",
      offset: 908,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_195[12], pVarName: "m_bEmit", offset: 912, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_195[13],
      pVarName: "m_nAttachment",
      offset: 916,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[14],
      pVarName: "m_Opacity",
      offset: 876,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_195[15],
      pVarName: "m_bDamaged",
      offset: 920,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_195[16],
      pVarName: "m_flFlareScale",
      offset: 924,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_RocketTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_RocketTrail::g_SendTable,
    pProps: &g_SendProps_195[1],
    nProps: 16,
    pNetTableName: g_pSendTableName_195);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10326790
// Name: int ServerClassInit<struct DT_SporeTrail::ignored>(struct DT_SporeTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SporeTrail::ignored>()
{
  if ( (_S6_31 & 1) == 0 )
  {
    _S6_31 |= 1u;
    SendPropInt(
      result: g_SendProps_196,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_196[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_196[2],
      pVarName: "m_flSpawnRate",
      offset: 864,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 1.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_196[3],
      pVarName: "m_vecEndColor",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_196[4],
      pVarName: "m_flParticleLifetime",
      offset: 868,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.1,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_196[5],
      pVarName: "m_flStartSize",
      offset: 872,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_196[6],
      pVarName: "m_flEndSize",
      offset: 876,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_196[7],
      pVarName: "m_flSpawnRadius",
      offset: 880,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_196[8], pVarName: "m_bEmit", offset: 884, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_SporeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SporeTrail::g_SendTable,
    pProps: &g_SendProps_196[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_196);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103269B0
// Name: int ServerClassInit<struct DT_SporeExplosion::ignored>(struct DT_SporeExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SporeExplosion::ignored>()
{
  if ( (_S8_15 & 1) == 0 )
  {
    _S8_15 |= 1u;
    SendPropInt(
      result: g_SendProps_197,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_197[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_197[2],
      pVarName: "m_flSpawnRate",
      offset: 856,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 1.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_197[3],
      pVarName: "m_flParticleLifetime",
      offset: 860,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.1,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_197[4],
      pVarName: "m_flStartSize",
      offset: 864,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_197[5],
      pVarName: "m_flEndSize",
      offset: 868,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_197[6],
      pVarName: "m_flSpawnRadius",
      offset: 872,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_197[7], pVarName: "m_bEmit", offset: 876, sizeofVar: 1);
    SendPropBool(result: &g_SendProps_197[8], pVarName: "m_bDontRemove", offset: 877, sizeofVar: 1);
    atexit(func: ServerClassInit_DT_SporeExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SporeExplosion::g_SendTable,
    pProps: &g_SendProps_197[1],
    nProps: 8,
    pNetTableName: g_pSendTableName_197);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10326BB0
// Name: int ServerClassInit<struct DT_FireTrail::ignored>(struct DT_FireTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_FireTrail::ignored>()
{
  if ( (_S11_5 & 1) == 0 )
  {
    _S11_5 |= 1u;
    SendPropInt(
      result: g_SendProps_198,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_198[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_198[2],
      pVarName: "m_nAttachment",
      offset: 852,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_198[3],
      pVarName: "m_flLifetime",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_FireTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_FireTrail::g_SendTable,
    pProps: &g_SendProps_198[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_198);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10326C90
// Name: int ServerClassInit<struct DT_DustTrail::ignored>(struct DT_DustTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_DustTrail::ignored>()
{
  if ( (_S12_4 & 1) == 0 )
  {
    _S12_4 |= 1u;
    SendPropInt(
      result: g_SendProps_199,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_199[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[2],
      pVarName: "m_SpawnRate",
      offset: 868,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 1.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_199[3],
      pVarName: "m_Color",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[4],
      pVarName: "m_ParticleLifetime",
      offset: 872,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.1,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[5],
      pVarName: "m_StopEmitTime",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[6],
      pVarName: "m_MinSpeed",
      offset: 880,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[7],
      pVarName: "m_MaxSpeed",
      offset: 884,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[8],
      pVarName: "m_MinDirectedSpeed",
      offset: 900,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[9],
      pVarName: "m_MaxDirectedSpeed",
      offset: 904,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[10],
      pVarName: "m_StartSize",
      offset: 888,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[11],
      pVarName: "m_EndSize",
      offset: 892,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_199[12],
      pVarName: "m_SpawnRadius",
      offset: 896,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_199[13], pVarName: "m_bEmit", offset: 908, sizeofVar: 1);
    SendPropFloat(
      result: &g_SendProps_199[14],
      pVarName: "m_Opacity",
      offset: 864,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_DustTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_DustTrail::g_SendTable,
    pProps: &g_SendProps_199[1],
    nProps: 14,
    pNetTableName: g_pSendTableName_199);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10327040
// Name: int ServerClassInit<struct DT_SmokeTrail::ignored>(struct DT_SmokeTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SmokeTrail::ignored>()
{
  if ( (_S2_317 & 1) == 0 )
  {
    _S2_317 |= 1u;
    SendPropInt(
      result: g_SendProps_200,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_200[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[2],
      pVarName: "m_SpawnRate",
      offset: 880,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 1.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_200[3],
      pVarName: "m_StartColor",
      offset: 1049428,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_200[4],
      pVarName: "m_EndColor",
      offset: 1049440,
      sizeofVar: 12,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 1.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[5],
      pVarName: "m_ParticleLifetime",
      offset: 884,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.1,
      fHighValue: 100.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[6],
      pVarName: "m_StopEmitTime",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[7],
      pVarName: "m_MinSpeed",
      offset: 892,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[8],
      pVarName: "m_MaxSpeed",
      offset: 896,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[9],
      pVarName: "m_MinDirectedSpeed",
      offset: 912,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[10],
      pVarName: "m_MaxDirectedSpeed",
      offset: 916,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[11],
      pVarName: "m_StartSize",
      offset: 900,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[12],
      pVarName: "m_EndSize",
      offset: 904,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[13],
      pVarName: "m_SpawnRadius",
      offset: 908,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropBool(result: &g_SendProps_200[14], pVarName: "m_bEmit", offset: 920, sizeofVar: 1);
    SendPropInt(
      result: &g_SendProps_200[15],
      pVarName: "m_nAttachment",
      offset: 924,
      sizeofVar: 4,
      nBits: 32,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_200[16],
      pVarName: "m_Opacity",
      offset: 876,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SmokeTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SmokeTrail::g_SendTable,
    pProps: &g_SendProps_200[1],
    nProps: 16,
    pNetTableName: g_pSendTableName_200);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10328D80
// Name: int ServerClassInit<struct DT_SmokeStack::ignored>(struct DT_SmokeStack::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SmokeStack::ignored>()
{
  if ( (_S2_318 & 1) == 0 )
  {
    _S2_318 |= 1u;
    SendPropInt(
      result: g_SendProps_201,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_201[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[2],
      pVarName: "m_SpreadSpeed",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[3],
      pVarName: "m_Speed",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[4],
      pVarName: "m_StartSize",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[5],
      pVarName: "m_EndSize",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[6],
      pVarName: "m_Rate",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[7],
      pVarName: "m_JetLength",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_201[8],
      pVarName: "m_bEmit",
      offset: 880,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[9],
      pVarName: "m_flBaseSpread",
      offset: 884,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[10],
      pVarName: "m_flRollSpeed",
      offset: 876,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_201[11],
      pVarName: "m_DirLight.m_vPos",
      offset: 924,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_201[12],
      pVarName: "m_DirLight.m_vColor",
      offset: 936,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[13],
      pVarName: "m_DirLight.m_flIntensity",
      offset: 948,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_201[14],
      pVarName: "m_AmbientLight.m_vPos",
      offset: 892,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_201[15],
      pVarName: "m_AmbientLight.m_vColor",
      offset: 904,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[16],
      pVarName: "m_AmbientLight.m_flIntensity",
      offset: 916,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_201[17],
      pVarName: "m_vWind",
      offset: 1049548,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_201[18],
      pVarName: "m_flTwist",
      offset: 952,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropIntWithMinusOneFlag(
      result: &g_SendProps_201[19],
      pVarName: "m_iMaterialModel",
      offset: 960,
      sizeofVar: 4,
      nBits: 16,
      proxyFn: SendProxy_IntAddOne);
    atexit(func: ServerClassInit_DT_SmokeStack::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SmokeStack::g_SendTable,
    pProps: &g_SendProps_201[1],
    nProps: 19,
    pNetTableName: g_pSendTableName_201);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10329F30
// Name: int ServerClassInit<struct DT_SpriteTrail::ignored>(struct DT_SpriteTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SpriteTrail::ignored>()
{
  if ( (_S3_171 & 1) == 0 )
  {
    _S3_171 |= 1u;
    SendPropInt(
      result: g_SendProps_202,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_202[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CSprite::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[2],
      pVarName: "m_flLifeTime",
      offset: 932,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[3],
      pVarName: "m_flStartWidth",
      offset: 936,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[4],
      pVarName: "m_flEndWidth",
      offset: 940,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[5],
      pVarName: "m_flStartWidthVariance",
      offset: 944,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[6],
      pVarName: "m_flTextureRes",
      offset: 948,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[7],
      pVarName: "m_flMinFadeLength",
      offset: 952,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_202[8],
      pVarName: "m_vecSkyboxOrigin",
      offset: 1049532,
      sizeofVar: 12,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_202[9],
      pVarName: "m_flSkyboxScale",
      offset: 968,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SpriteTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SpriteTrail::g_SendTable,
    pProps: &g_SendProps_202[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_202);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032A5C0
// Name: int ServerClassInit<struct DT_SteamJet::ignored>(struct DT_SteamJet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_SteamJet::ignored>()
{
  if ( (_S2_320 & 1) == 0 )
  {
    _S2_320 |= 1u;
    SendPropInt(
      result: g_SendProps_203,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_203[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseParticleEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[2],
      pVarName: "m_SpreadSpeed",
      offset: 852,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[3],
      pVarName: "m_Speed",
      offset: 856,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[4],
      pVarName: "m_StartSize",
      offset: 860,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[5],
      pVarName: "m_EndSize",
      offset: 864,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[6],
      pVarName: "m_Rate",
      offset: 868,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[7],
      pVarName: "m_JetLength",
      offset: 872,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_203[8],
      pVarName: "m_bEmit",
      offset: 876,
      sizeofVar: 4,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_203[9],
      pVarName: "m_bFaceLeft",
      offset: 880,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_203[10],
      pVarName: "m_nType",
      offset: 884,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_203[11],
      pVarName: "m_spawnflags",
      offset: 760,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_203[12],
      pVarName: "m_flRollSpeed",
      offset: 888,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_SteamJet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_SteamJet::g_SendTable,
    pProps: &g_SendProps_203[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_203);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032BA20
// Name: int ServerClassInit<struct DT_TEArmorRicochet::ignored>(struct DT_TEArmorRicochet::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEArmorRicochet::ignored>()
{
  if ( (_S3_173 & 1) == 0 )
  {
    _S3_173 |= 1u;
    SendPropInt(
      result: g_SendProps_204,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_204[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEMetalSparks::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEArmorRicochet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEArmorRicochet::g_SendTable,
    pProps: &g_SendProps_204[1],
    nProps: 1,
    pNetTableName: g_pSendTableName_204);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032BAA0
// Name: int ServerClassInit<struct DT_TEMetalSparks::ignored>(struct DT_TEMetalSparks::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEMetalSparks::ignored>()
{
  if ( (_S2_321 & 1) == 0 )
  {
    _S2_321 |= 1u;
    SendPropInt(
      result: g_SendProps_205,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_205[1],
      pVarName: "m_vecPos",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_205[2],
      pVarName: "m_vecDir",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEMetalSparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEMetalSparks::g_SendTable,
    pProps: &g_SendProps_205[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_205);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032BF10
// Name: int ServerClassInit<struct DT_BaseBeam::ignored>(struct DT_BaseBeam::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_BaseBeam::ignored>()
{
  if ( (_S2_322 & 1) == 0 )
  {
    _S2_322 |= 1u;
    SendPropInt(
      result: g_SendProps_206,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[1],
      pVarName: "m_nModelIndex",
      offset: 12,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[2],
      pVarName: "m_nHaloIndex",
      offset: 16,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[3],
      pVarName: "m_nStartFrame",
      offset: 20,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[4],
      pVarName: "m_nFrameRate",
      offset: 24,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_206[5],
      pVarName: "m_fLife",
      offset: 28,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_206[6],
      pVarName: "m_fWidth",
      offset: 32,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 128.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_206[7],
      pVarName: "m_fEndWidth",
      offset: 36,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 128.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[8],
      pVarName: "m_nFadeLength",
      offset: 40,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_206[9],
      pVarName: "m_fAmplitude",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 64.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[10],
      pVarName: "m_nSpeed",
      offset: 64,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[11],
      pVarName: "r",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[12],
      pVarName: "g",
      offset: 52,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[13],
      pVarName: "b",
      offset: 56,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[14],
      pVarName: "a",
      offset: 60,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_206[15],
      pVarName: "m_nFlags",
      offset: 68,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_BaseBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_BaseBeam::g_SendTable,
    pProps: &g_SendProps_206[1],
    nProps: 15,
    pNetTableName: g_pSendTableName_206);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032C2D0
// Name: int ServerClassInit<struct DT_TEBeamEntPoint::ignored>(struct DT_TEBeamEntPoint::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamEntPoint::ignored>()
{
  if ( (_S2_323 & 1) == 0 )
  {
    _S2_323 |= 1u;
    SendPropInt(
      result: g_SendProps_207,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_207[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_207[2],
      pVarName: "m_nStartEntity",
      offset: 72,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_207[3],
      pVarName: "m_nEndEntity",
      offset: 88,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_207[4],
      pVarName: "m_vecStartPoint",
      offset: 1048652,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_207[5],
      pVarName: "m_vecEndPoint",
      offset: 1048668,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamEntPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamEntPoint::g_SendTable,
    pProps: &g_SendProps_207[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_207);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032C880
// Name: int ServerClassInit<struct DT_TEBeamEnts::ignored>(struct DT_TEBeamEnts::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamEnts::ignored>()
{
  if ( (_S2_324 & 1) == 0 )
  {
    _S2_324 |= 1u;
    SendPropInt(
      result: g_SendProps_208,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_208[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_208[2],
      pVarName: "m_nStartEntity",
      offset: 72,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_208[3],
      pVarName: "m_nEndEntity",
      offset: 76,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamEnts::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamEnts::g_SendTable,
    pProps: &g_SendProps_208[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_208);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032CAF0
// Name: int ServerClassInit<struct DT_TEBeamFollow::ignored>(struct DT_TEBeamFollow::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamFollow::ignored>()
{
  if ( (_S2_325 & 1) == 0 )
  {
    _S2_325 |= 1u;
    SendPropInt(
      result: g_SendProps_209,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_209[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_209[2],
      pVarName: "m_iEntIndex",
      offset: 72,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamFollow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamFollow::g_SendTable,
    pProps: &g_SendProps_209[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_209);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032CD10
// Name: int ServerClassInit<struct DT_TEBeamLaser::ignored>(struct DT_TEBeamLaser::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamLaser::ignored>()
{
  if ( (_S2_326 & 1) == 0 )
  {
    _S2_326 |= 1u;
    SendPropInt(
      result: g_SendProps_210,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_210[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_210[2],
      pVarName: "m_nStartEntity",
      offset: 72,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_210[3],
      pVarName: "m_nEndEntity",
      offset: 76,
      sizeofVar: 4,
      nBits: 24,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamLaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamLaser::g_SendTable,
    pProps: &g_SendProps_210[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_210);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032D080
// Name: int ServerClassInit<struct DT_TEBeamPoints::ignored>(struct DT_TEBeamPoints::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamPoints::ignored>()
{
  if ( (_S2_327 & 1) == 0 )
  {
    _S2_327 |= 1u;
    SendPropInt(
      result: g_SendProps_211,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_211[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_211[2],
      pVarName: "m_vecStartPoint",
      offset: 1048648,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_211[3],
      pVarName: "m_vecEndPoint",
      offset: 1048660,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamPoints::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamPoints::g_SendTable,
    pProps: &g_SendProps_211[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_211);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032D600
// Name: int ServerClassInit<struct DT_TEBeamRing::ignored>(struct DT_TEBeamRing::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamRing::ignored>()
{
  if ( (_S2_328 & 1) == 0 )
  {
    _S2_328 |= 1u;
    SendPropInt(
      result: g_SendProps_212,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_212[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_212[2],
      pVarName: "m_nStartEntity",
      offset: 72,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_212[3],
      pVarName: "m_nEndEntity",
      offset: 76,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamRing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamRing::g_SendTable,
    pProps: &g_SendProps_212[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_212);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032D990
// Name: int ServerClassInit<struct DT_TEBeamRingPoint::ignored>(struct DT_TEBeamRingPoint::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamRingPoint::ignored>()
{
  if ( (_S2_329 & 1) == 0 )
  {
    _S2_329 |= 1u;
    SendPropInt(
      result: g_SendProps_213,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_213[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEBaseBeam::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_213[2],
      pVarName: "m_vecCenter",
      offset: 1048648,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_213[3],
      pVarName: "m_flStartRadius",
      offset: 84,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 4096.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_213[4],
      pVarName: "m_flEndRadius",
      offset: 88,
      sizeofVar: 4,
      nBits: 16,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 4096.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamRingPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamRingPoint::g_SendTable,
    pProps: &g_SendProps_213[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_213);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032DE60
// Name: int ServerClassInit<struct DT_TEBeamSpline::ignored>(struct DT_TEBeamSpline::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBeamSpline::ignored>()
{
  if ( (_S2_330 & 1) == 0 )
  {
    _S2_330 |= 1u;
    SendPropInt(
      result: g_SendProps_214,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_214[1],
      pVarName: "m_nPoints",
      offset: 204,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_214[2],
      pVarName: "m_vecPoints",
      offset: 12,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    InternalSendPropArray(
      result: &g_SendProps_214[3],
      elementCount: 16,
      elementStride: 12,
      pName: "m_vecPoints",
      arrayLengthFn: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBeamSpline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBeamSpline::g_SendTable,
    pProps: &g_SendProps_214[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_214);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032E280
// Name: int ServerClassInit<struct DT_TEBloodSprite::ignored>(struct DT_TEBloodSprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBloodSprite::ignored>()
{
  if ( (_S2_331 & 1) == 0 )
  {
    _S2_331 |= 1u;
    SendPropInt(
      result: g_SendProps_215,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_215[1],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_215[2],
      pVarName: "m_vecDirection",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[3],
      pVarName: "r",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[4],
      pVarName: "g",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[5],
      pVarName: "b",
      offset: 52,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[6],
      pVarName: "a",
      offset: 56,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[7],
      pVarName: "m_nSprayModel",
      offset: 36,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[8],
      pVarName: "m_nDropModel",
      offset: 40,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_215[9],
      pVarName: "m_nSize",
      offset: 60,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBloodSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBloodSprite::g_SendTable,
    pProps: &g_SendProps_215[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_215);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032E7B0
// Name: int ServerClassInit<struct DT_TEBloodStream::ignored>(struct DT_TEBloodStream::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBloodStream::ignored>()
{
  if ( (_S2_332 & 1) == 0 )
  {
    _S2_332 |= 1u;
    SendPropInt(
      result: g_SendProps_216,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_216[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_216[2],
      pVarName: "m_vecDirection",
      offset: 1048600,
      sizeofVar: 12,
      nBits: 11,
      flags: 0,
      fLowValue: -10.0,
      fHighValue: 10.0,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_216[3],
      pVarName: "r",
      offset: 36,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_216[4],
      pVarName: "g",
      offset: 40,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_216[5],
      pVarName: "b",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_216[6],
      pVarName: "a",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_216[7],
      pVarName: "m_nAmount",
      offset: 52,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBloodStream::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBloodStream::g_SendTable,
    pProps: &g_SendProps_216[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_216);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032EC60
// Name: int ServerClassInit<struct DT_TEBreakModel::ignored>(struct DT_TEBreakModel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBreakModel::ignored>()
{
  if ( (_S2_333 & 1) == 0 )
  {
    _S2_333 |= 1u;
    SendPropInt(
      result: g_SendProps_217,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_217[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_217[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_217[3],
      pVarName: "m_angRotation[0]",
      offset: 1048624,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_217[4],
      pVarName: "m_angRotation[1]",
      offset: 1048628,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_217[5],
      pVarName: "m_angRotation[2]",
      offset: 1048632,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_217[6],
      pVarName: "m_vecSize",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_217[7],
      pVarName: "m_vecVelocity",
      offset: 1048612,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_217[8],
      pVarName: "m_nModelIndex",
      offset: 64,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_217[9],
      pVarName: "m_nRandomization",
      offset: 60,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_217[10],
      pVarName: "m_nCount",
      offset: 68,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_217[11],
      pVarName: "m_fTime",
      offset: 72,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 102.4,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_217[12],
      pVarName: "m_nFlags",
      offset: 76,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBreakModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBreakModel::g_SendTable,
    pProps: &g_SendProps_217[1],
    nProps: 12,
    pNetTableName: g_pSendTableName_217);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032F230
// Name: int ServerClassInit<struct DT_TEBSPDecal::ignored>(struct DT_TEBSPDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBSPDecal::ignored>()
{
  if ( (_S2_334 & 1) == 0 )
  {
    _S2_334 |= 1u;
    SendPropInt(
      result: g_SendProps_218,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_218[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_218[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_218[3],
      pVarName: "m_nEntity",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_218[4],
      pVarName: "m_nIndex",
      offset: 28,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBSPDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBSPDecal::g_SendTable,
    pProps: &g_SendProps_218[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_218);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032F5C0
// Name: int ServerClassInit<struct DT_TEBubbles::ignored>(struct DT_TEBubbles::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBubbles::ignored>()
{
  if ( (_S2_335 & 1) == 0 )
  {
    _S2_335 |= 1u;
    SendPropInt(
      result: g_SendProps_219,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_219[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_219[2],
      pVarName: "m_vecMins",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_219[3],
      pVarName: "m_vecMaxs",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_219[4],
      pVarName: "m_nModelIndex",
      offset: 40,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_219[5],
      pVarName: "m_fHeight",
      offset: 36,
      sizeofVar: 4,
      nBits: 17,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_219[6],
      pVarName: "m_nCount",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_219[7],
      pVarName: "m_fSpeed",
      offset: 48,
      sizeofVar: 4,
      nBits: 17,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBubbles::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBubbles::g_SendTable,
    pProps: &g_SendProps_219[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_219);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032FA90
// Name: int ServerClassInit<struct DT_TEBubbleTrail::ignored>(struct DT_TEBubbleTrail::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEBubbleTrail::ignored>()
{
  if ( (_S2_336 & 1) == 0 )
  {
    _S2_336 |= 1u;
    SendPropInt(
      result: g_SendProps_220,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_220[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_220[2],
      pVarName: "m_vecMins",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_220[3],
      pVarName: "m_vecMaxs",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_220[4],
      pVarName: "m_nModelIndex",
      offset: 40,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_220[5],
      pVarName: "m_flWaterZ",
      offset: 36,
      sizeofVar: 4,
      nBits: 17,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_220[6],
      pVarName: "m_nCount",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_220[7],
      pVarName: "m_fSpeed",
      offset: 48,
      sizeofVar: 4,
      nBits: 17,
      flags: 0,
      fLowValue: -16384.0,
      fHighValue: 16384.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEBubbleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEBubbleTrail::g_SendTable,
    pProps: &g_SendProps_220[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_220);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032FF70
// Name: int ServerClassInit<struct DT_TEClientProjectile::ignored>(struct DT_TEClientProjectile::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEClientProjectile::ignored>()
{
  if ( (_S2_337 & 1) == 0 )
  {
    _S2_337 |= 1u;
    SendPropInt(
      result: g_SendProps_221,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_221[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_221[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_221[3],
      pVarName: "m_vecVelocity",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_221[4],
      pVarName: "m_nModelIndex",
      offset: 36,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_221[5],
      pVarName: "m_nLifeTime",
      offset: 40,
      sizeofVar: 4,
      nBits: 6,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropEHandle(
      result: &g_SendProps_221[6],
      pVarName: "m_hOwner",
      offset: 44,
      flags: 4,
      sizeofVar: -1,
      proxyFn: SendProxy_EHandleToInt);
    atexit(func: ServerClassInit_DT_TEClientProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEClientProjectile::g_SendTable,
    pProps: &g_SendProps_221[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_221);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10330470
// Name: int ServerClassInit<struct DT_TEDecal::ignored>(struct DT_TEDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEDecal::ignored>()
{
  if ( (_S2_338 & 1) == 0 )
  {
    _S2_338 |= 1u;
    SendPropInt(
      result: g_SendProps_222,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_222[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_222[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_222[3],
      pVarName: "m_vecStart",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_222[4],
      pVarName: "m_nEntity",
      offset: 36,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_222[5],
      pVarName: "m_nHitbox",
      offset: 40,
      sizeofVar: 4,
      nBits: 16,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_222[6],
      pVarName: "m_nIndex",
      offset: 44,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEDecal::g_SendTable,
    pProps: &g_SendProps_222[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_222);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103308D0
// Name: int ServerClassInit<struct DT_TEDynamicLight::ignored>(struct DT_TEDynamicLight::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEDynamicLight::ignored>()
{
  if ( (_S2_339 & 1) == 0 )
  {
    _S2_339 |= 1u;
    SendPropInt(
      result: g_SendProps_223,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_223[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_223[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_223[3],
      pVarName: "r",
      offset: 28,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_223[4],
      pVarName: "g",
      offset: 32,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_223[5],
      pVarName: "b",
      offset: 36,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_223[6],
      pVarName: "exponent",
      offset: 40,
      sizeofVar: 4,
      nBits: 8,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_223[7],
      pVarName: "m_fRadius",
      offset: 24,
      sizeofVar: 4,
      nBits: 8,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 2560.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_223[8],
      pVarName: "m_fTime",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_223[9],
      pVarName: "m_fDecay",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 2560.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEDynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEDynamicLight::g_SendTable,
    pProps: &g_SendProps_223[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_223);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10330F50
// Name: int ServerClassInit<struct DT_TEEffectDispatch::ignored>(struct DT_TEEffectDispatch::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEEffectDispatch::ignored>()
{
  if ( (_S2_340 & 1) == 0 )
  {
    _S2_340 |= 1u;
    SendPropInt(
      result: g_SendProps_224,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_224[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_224[2],
      pVarName: "m_EffectData",
      offset: 12,
      pTable: &DT_EffectData::g_SendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEEffectDispatch::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEEffectDispatch::g_SendTable,
    pProps: &g_SendProps_224[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_224);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103310B0
// Name: int ServerClassInit<struct DT_TEEnergySplash::ignored>(struct DT_TEEnergySplash::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEEnergySplash::ignored>()
{
  if ( (_S2_341 & 1) == 0 )
  {
    _S2_341 |= 1u;
    SendPropInt(
      result: g_SendProps_225,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_225[1],
      pVarName: "m_vecPos",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_225[2],
      pVarName: "m_vecDir",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_225[3],
      pVarName: "m_bExplosive",
      offset: 36,
      sizeofVar: 1,
      nBits: 1,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEEnergySplash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEEnergySplash::g_SendTable,
    pProps: &g_SendProps_225[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_225);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103313F0
// Name: int ServerClassInit<struct DT_TEExplosion::ignored>(struct DT_TEExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEExplosion::ignored>()
{
  if ( (_S2_342 & 1) == 0 )
  {
    _S2_342 |= 1u;
    SendPropInt(
      result: g_SendProps_226,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_226[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[2],
      pVarName: "m_nModelIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_226[3],
      pVarName: "m_fScale",
      offset: 28,
      sizeofVar: 4,
      nBits: 9,
      flags: 0,
      fLowValue: 0.0,
      fHighValue: 51.200001,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[4],
      pVarName: "m_nFrameRate",
      offset: 32,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[5],
      pVarName: "m_nFlags",
      offset: 36,
      sizeofVar: 4,
      nBits: 10,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_226[6],
      pVarName: "m_vecNormal",
      offset: 1048616,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[7],
      pVarName: "m_chMaterialType",
      offset: 52,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[8],
      pVarName: "m_nRadius",
      offset: 56,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_226[9],
      pVarName: "m_nMagnitude",
      offset: 60,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEExplosion::g_SendTable,
    pProps: &g_SendProps_226[1],
    nProps: 9,
    pNetTableName: g_pSendTableName_226);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103319B0
// Name: int ServerClassInit<struct DT_TEFizz::ignored>(struct DT_TEFizz::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEFizz::ignored>()
{
  if ( (_S2_343 & 1) == 0 )
  {
    _S2_343 |= 1u;
    SendPropInt(
      result: g_SendProps_227,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_227[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_227[2],
      pVarName: "m_nEntity",
      offset: 12,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_227[3],
      pVarName: "m_nModelIndex",
      offset: 16,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_227[4],
      pVarName: "m_nDensity",
      offset: 20,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_227[5],
      pVarName: "m_nCurrent",
      offset: 24,
      sizeofVar: 4,
      nBits: 16,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEFizz::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEFizz::g_SendTable,
    pProps: &g_SendProps_227[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_227);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10331C00
// Name: int ServerClassInit<struct DT_TEFootprintDecal::ignored>(struct DT_TEFootprintDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEFootprintDecal::ignored>()
{
  if ( (_S2_344 & 1) == 0 )
  {
    _S2_344 |= 1u;
    SendPropInt(
      result: g_SendProps_228,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_228[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_228[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_228[3],
      pVarName: "m_vecDirection",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_228[4],
      pVarName: "m_nEntity",
      offset: 36,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_228[5],
      pVarName: "m_nIndex",
      offset: 40,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_228[6],
      pVarName: "m_chMaterialType",
      offset: 44,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEFootprintDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEFootprintDecal::g_SendTable,
    pProps: &g_SendProps_228[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_228);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10331EB0
// Name: int ServerClassInit<struct DT_TEGaussExplosion::ignored>(struct DT_TEGaussExplosion::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEGaussExplosion::ignored>()
{
  if ( (_S2_345 & 1) == 0 )
  {
    _S2_345 |= 1u;
    SendPropInt(
      result: g_SendProps_229,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_229[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_229[2],
      pVarName: "m_nType",
      offset: 24,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_229[3],
      pVarName: "m_vecDirection",
      offset: 1048604,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEGaussExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEGaussExplosion::g_SendTable,
    pProps: &g_SendProps_229[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_229);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10331FA0
// Name: int ServerClassInit<struct DT_TEShatterSurface::ignored>(struct DT_TEShatterSurface::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEShatterSurface::ignored>()
{
  if ( (_S2_346 & 1) == 0 )
  {
    _S2_346 |= 1u;
    SendPropInt(
      result: g_SendProps_230,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_230[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_230[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_230[3],
      pVarName: "m_vecAngles",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_230[4],
      pVarName: "m_vecForce",
      offset: 1048612,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_230[5],
      pVarName: "m_vecForcePos",
      offset: 1048624,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_230[6],
      pVarName: "m_flWidth",
      offset: 60,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_230[7],
      pVarName: "m_flHeight",
      offset: 64,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_230[8],
      pVarName: "m_flShardSize",
      offset: 68,
      sizeofVar: 4,
      nBits: 0,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[9],
      pVarName: "m_nSurfaceType",
      offset: 72,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[10],
      pVarName: "m_uchFrontColor[0]",
      offset: 76,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[11],
      pVarName: "m_uchFrontColor[1]",
      offset: 77,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[12],
      pVarName: "m_uchFrontColor[2]",
      offset: 78,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[13],
      pVarName: "m_uchBackColor[0]",
      offset: 79,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[14],
      pVarName: "m_uchBackColor[1]",
      offset: 80,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_230[15],
      pVarName: "m_uchBackColor[2]",
      offset: 81,
      sizeofVar: 1,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEShatterSurface::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEShatterSurface::g_SendTable,
    pProps: &g_SendProps_230[1],
    nProps: 15,
    pNetTableName: g_pSendTableName_230);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10332830
// Name: int ServerClassInit<struct DT_TEGlowSprite::ignored>(struct DT_TEGlowSprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEGlowSprite::ignored>()
{
  if ( (_S2_347 & 1) == 0 )
  {
    _S2_347 |= 1u;
    SendPropInt(
      result: g_SendProps_231,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_231[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_231[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_231[3],
      pVarName: "m_nModelIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_231[4],
      pVarName: "m_fScale",
      offset: 28,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_231[5],
      pVarName: "m_fLife",
      offset: 32,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_231[6],
      pVarName: "m_nBrightness",
      offset: 36,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEGlowSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEGlowSprite::g_SendTable,
    pProps: &g_SendProps_231[1],
    nProps: 6,
    pNetTableName: g_pSendTableName_231);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10332C70
// Name: int ServerClassInit<struct DT_TEImpact::ignored>(struct DT_TEImpact::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEImpact::ignored>()
{
  if ( (_S2_348 & 1) == 0 )
  {
    _S2_348 |= 1u;
    SendPropInt(
      result: g_SendProps_232,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_232[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_232[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_232[3],
      pVarName: "m_vecNormal",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_232[4],
      pVarName: "m_iType",
      offset: 36,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEImpact::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEImpact::g_SendTable,
    pProps: &g_SendProps_232[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_232);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10332DD0
// Name: int ServerClassInit<struct DT_TEKillPlayerAttachments::ignored>(struct DT_TEKillPlayerAttachments::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEKillPlayerAttachments::ignored>()
{
  if ( (_S2_349 & 1) == 0 )
  {
    _S2_349 |= 1u;
    SendPropInt(
      result: g_SendProps_233,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_233[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_233[2],
      pVarName: "m_nPlayer",
      offset: 12,
      sizeofVar: 4,
      nBits: 5,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEKillPlayerAttachments::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEKillPlayerAttachments::g_SendTable,
    pProps: &g_SendProps_233[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_233);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10332F40
// Name: int ServerClassInit<struct DT_TELargeFunnel::ignored>(struct DT_TELargeFunnel::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TELargeFunnel::ignored>()
{
  if ( (_S2_350 & 1) == 0 )
  {
    _S2_350 |= 1u;
    SendPropInt(
      result: g_SendProps_234,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_234[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_234[2],
      pVarName: "m_nModelIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_234[3],
      pVarName: "m_nReversed",
      offset: 28,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TELargeFunnel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TELargeFunnel::g_SendTable,
    pProps: &g_SendProps_234[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_234);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10333250
// Name: int ServerClassInit<struct DT_TEMuzzleFlash::ignored>(struct DT_TEMuzzleFlash::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEMuzzleFlash::ignored>()
{
  if ( (_S2_351 & 1) == 0 )
  {
    _S2_351 |= 1u;
    SendPropInt(
      result: g_SendProps_235,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_235[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_235[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_235[3],
      pVarName: "m_vecAngles",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_235[4],
      pVarName: "m_flScale",
      offset: 36,
      sizeofVar: 4,
      nBits: -1,
      flags: 4,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_235[5],
      pVarName: "m_nType",
      offset: 40,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEMuzzleFlash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEMuzzleFlash::g_SendTable,
    pProps: &g_SendProps_235[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_235);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103334B0
// Name: int ServerClassInit<struct DT_TEParticleSystem::ignored>(struct DT_TEParticleSystem::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEParticleSystem::ignored>()
{
  if ( (_S2_352 & 1) == 0 )
  {
    _S2_352 |= 1u;
    SendPropInt(
      result: g_SendProps_236,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_236[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_236[2],
      pVarName: "m_vecOrigin[0]",
      offset: 3145740,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_236[3],
      pVarName: "m_vecOrigin[1]",
      offset: 3145744,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_236[4],
      pVarName: "m_vecOrigin[2]",
      offset: 3145748,
      sizeofVar: 4,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEParticleSystem::g_SendTable,
    pProps: &g_SendProps_236[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_236);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10333630
// Name: int ServerClassInit<struct DT_TEPhysicsProp::ignored>(struct DT_TEPhysicsProp::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEPhysicsProp::ignored>()
{
  if ( (_S2_353 & 1) == 0 )
  {
    _S2_353 |= 1u;
    SendPropInt(
      result: g_SendProps_237,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_237[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_237[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_237[3],
      pVarName: "m_angRotation[0]",
      offset: 1048600,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_237[4],
      pVarName: "m_angRotation[1]",
      offset: 1048604,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropAngle(
      result: &g_SendProps_237[5],
      pVarName: "m_angRotation[2]",
      offset: 1048608,
      sizeofVar: 4,
      nBits: 13,
      flags: 0,
      varProxy: SendProxy_AngleToFloat,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_237[6],
      pVarName: "m_vecVelocity",
      offset: 1048612,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_237[7],
      pVarName: "m_nModelIndex",
      offset: 48,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_237[8],
      pVarName: "m_nSkin",
      offset: 52,
      sizeofVar: 4,
      nBits: 10,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_237[9],
      pVarName: "m_nFlags",
      offset: 56,
      sizeofVar: 4,
      nBits: 2,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_237[10],
      pVarName: "m_nEffects",
      offset: 60,
      sizeofVar: 4,
      nBits: 14,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_237[11],
      pVarName: "m_clrRender",
      offset: 64,
      sizeofVar: 4,
      nBits: 32,
      flags: 1,
      varProxy: SendProxy_Int32ToInt32,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEPhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEPhysicsProp::g_SendTable,
    pProps: &g_SendProps_237[1],
    nProps: 11,
    pNetTableName: g_pSendTableName_237);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10333B30
// Name: int ServerClassInit<struct DT_TEPlayerDecal::ignored>(struct DT_TEPlayerDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEPlayerDecal::ignored>()
{
  int v0; // eax

  if ( (_S2_354 & 1) == 0 )
  {
    _S2_354 |= 1u;
    SendPropInt(
      result: g_SendProps_238,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_238[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_238[2],
      pVarName: "m_vecOrigin",
      offset: 1048592,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_238[3],
      pVarName: "m_nEntity",
      offset: 28,
      sizeofVar: 4,
      nBits: 11,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    v0 = Q_log2(val: 0x40u);
    SendPropInt(
      result: &g_SendProps_238[4],
      pVarName: "m_nPlayer",
      offset: 12,
      sizeofVar: 4,
      nBits: v0,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEPlayerDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEPlayerDecal::g_SendTable,
    pProps: &g_SendProps_238[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_238);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10333ED0
// Name: int ServerClassInit<struct DT_TEProjectedDecal::ignored>(struct DT_TEProjectedDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEProjectedDecal::ignored>()
{
  if ( (_S2_355 & 1) == 0 )
  {
    _S2_355 |= 1u;
    SendPropInt(
      result: g_SendProps_239,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_239[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_239[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropQAngles(
      result: &g_SendProps_239[3],
      pVarName: "m_angRotation",
      offset: 1048608,
      sizeofVar: 12,
      nBits: 10,
      flags: 0,
      varProxy: SendProxy_QAngles,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_239[4],
      pVarName: "m_flDistance",
      offset: 28,
      sizeofVar: 4,
      nBits: 10,
      flags: 16,
      fLowValue: 0.0,
      fHighValue: 1024.0,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_239[5],
      pVarName: "m_nIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEProjectedDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEProjectedDecal::g_SendTable,
    pProps: &g_SendProps_239[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_239);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103342B0
// Name: int ServerClassInit<struct DT_TEShowLine::ignored>(struct DT_TEShowLine::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEShowLine::ignored>()
{
  if ( (_S2_356 & 1) == 0 )
  {
    _S2_356 |= 1u;
    SendPropInt(
      result: g_SendProps_240,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_240[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_240[2],
      pVarName: "m_vecEnd",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEShowLine::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEShowLine::g_SendTable,
    pProps: &g_SendProps_240[1],
    nProps: 2,
    pNetTableName: g_pSendTableName_240);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10334680
// Name: int ServerClassInit<struct DT_TESmoke::ignored>(struct DT_TESmoke::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TESmoke::ignored>()
{
  if ( (_S2_357 & 1) == 0 )
  {
    _S2_357 |= 1u;
    SendPropInt(
      result: g_SendProps_241,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_241[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_241[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_241[3],
      pVarName: "m_nModelIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_241[4],
      pVarName: "m_fScale",
      offset: 28,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_241[5],
      pVarName: "m_nFrameRate",
      offset: 32,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TESmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TESmoke::g_SendTable,
    pProps: &g_SendProps_241[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_241);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10334A40
// Name: int ServerClassInit<struct DT_TESparks::ignored>(struct DT_TESparks::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TESparks::ignored>()
{
  if ( (_S2_358 & 1) == 0 )
  {
    _S2_358 |= 1u;
    SendPropInt(
      result: g_SendProps_242,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_242[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CTEParticleSystem::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_242[2],
      pVarName: "m_nMagnitude",
      offset: 24,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_242[3],
      pVarName: "m_nTrailLength",
      offset: 28,
      sizeofVar: 4,
      nBits: 4,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_242[4],
      pVarName: "m_vecDir",
      offset: 1048608,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TESparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TESparks::g_SendTable,
    pProps: &g_SendProps_242[1],
    nProps: 4,
    pNetTableName: g_pSendTableName_242);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10334E30
// Name: int ServerClassInit<struct DT_TESprite::ignored>(struct DT_TESprite::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TESprite::ignored>()
{
  if ( (_S2_359 & 1) == 0 )
  {
    _S2_359 |= 1u;
    SendPropInt(
      result: g_SendProps_243,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_243[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_243[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_243[3],
      pVarName: "m_nModelIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_243[4],
      pVarName: "m_fScale",
      offset: 28,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 25.6,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_243[5],
      pVarName: "m_nBrightness",
      offset: 32,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TESprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TESprite::g_SendTable,
    pProps: &g_SendProps_243[1],
    nProps: 5,
    pNetTableName: g_pSendTableName_243);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10335200
// Name: int ServerClassInit<struct DT_TESpriteSpray::ignored>(struct DT_TESpriteSpray::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TESpriteSpray::ignored>()
{
  if ( (_S2_360 & 1) == 0 )
  {
    _S2_360 |= 1u;
    SendPropInt(
      result: g_SendProps_244,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_244[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_244[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_244[3],
      pVarName: "m_vecDirection",
      offset: 1048600,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_244[4],
      pVarName: "m_nModelIndex",
      offset: 36,
      sizeofVar: 4,
      nBits: 11,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropFloat(
      result: &g_SendProps_244[5],
      pVarName: "m_fNoise",
      offset: 44,
      sizeofVar: 4,
      nBits: 8,
      flags: 8,
      fLowValue: 0.0,
      fHighValue: 2.5599999,
      varProxy: SendProxy_FloatToFloat,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_244[6],
      pVarName: "m_nSpeed",
      offset: 40,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_244[7],
      pVarName: "m_nCount",
      offset: 48,
      sizeofVar: 4,
      nBits: 8,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TESpriteSpray::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TESpriteSpray::g_SendTable,
    pProps: &g_SendProps_244[1],
    nProps: 7,
    pNetTableName: g_pSendTableName_244);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10335790
// Name: public: virtual class ServerClass __near * CTEWorldDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEWorldDecal::GetServerClass(CTEWorldDecal *this)
{
  return &g_CTEWorldDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103357D0
// Name: int ServerClassInit<struct DT_TEWorldDecal::ignored>(struct DT_TEWorldDecal::ignored __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerClassInit<DT_TEWorldDecal::ignored>()
{
  if ( (_S2_361 & 1) == 0 )
  {
    _S2_361 |= 1u;
    SendPropInt(
      result: g_SendProps_245,
      pVarName: "should_never_see_this",
      offset: 0,
      sizeofVar: 4,
      nBits: -1,
      flags: 0,
      varProxy: nullptr,
      priority: 0x80u);
    SendPropDataTable(
      result: &g_SendProps_245[1],
      pVarName: "baseclass",
      offset: 0,
      pTable: CBaseTempEntity::m_pClassSendTable,
      varProxy: SendProxy_DataTableToDataTable,
      priority: 0x80u);
    SendPropVector(
      result: &g_SendProps_245[2],
      pVarName: "m_vecOrigin",
      offset: 1048588,
      sizeofVar: 12,
      nBits: -1,
      flags: 2,
      fLowValue: 0.0,
      fHighValue: -121121.12,
      varProxy: SendProxy_UnmodifiedQAngles,
      priority: 0x80u);
    SendPropInt(
      result: &g_SendProps_245[3],
      pVarName: "m_nIndex",
      offset: 24,
      sizeofVar: 4,
      nBits: 9,
      flags: 1,
      varProxy: nullptr,
      priority: 0x80u);
    atexit(func: ServerClassInit_DT_TEWorldDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__);
  }
  SendTable::Construct(
    this: &DT_TEWorldDecal::g_SendTable,
    pProps: &g_SendProps_245[1],
    nProps: 3,
    pNetTableName: g_pSendTableName_245);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103358B0
// Name: public: virtual void CTEWorldDecal::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEWorldDecal::Test(CTEWorldDecal *this, const Vector *current_origin, const QAngle *current_angles)
{
  CNetworkVectorBase<Vector,CTEWorldDecal::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  CGameTrace tr; // [esp+Ch] [ebp-8Ch] BYREF
  CBroadcastRecipientFilter filter; // [esp+60h] [ebp-38h] BYREF
  Vector vecEnd; // [esp+80h] [ebp-18h] BYREF
  Vector forward; // [esp+8Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( this->m_nIndex.m_Value != 0 )
    this->m_nIndex.m_Value = 0;
  p_m_vecOrigin = &this->m_vecOrigin;
  if ( current_origin->x != this->m_vecOrigin.m_Value.x
    || current_origin->y != this->m_vecOrigin.m_Value.y
    || current_origin->z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = current_origin->x;
    this->m_vecOrigin.m_Value.y = current_origin->y;
    this->m_vecOrigin.m_Value.z = current_origin->z;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  x = forward.x;
  p_m_vecOrigin->m_Value.x = (float)(forward.x * 50.0) + p_m_vecOrigin->m_Value.x;
  y = forward.y;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  z = forward.z;
  v8 = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  this->m_vecOrigin.m_Value.z = v8;
  v9 = (float)(y * 1024.0) + this->m_vecOrigin.m_Value.y;
  vecEnd.x = (float)(x * 1024.0) + p_m_vecOrigin->m_Value.x;
  vecEnd.y = v9;
  vecEnd.z = (float)(z * 1024.0) + v8;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)p_m_vecOrigin,
    vecAbsStart: &this->m_vecOrigin.m_Value,
    vecAbsEnd: &vecEnd,
    mask: 0x400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  v10 = tr.endpos.z;
  v11 = tr.endpos.y;
  if ( tr.endpos.x != p_m_vecOrigin->m_Value.x
    || tr.endpos.y != this->m_vecOrigin.m_Value.y
    || tr.endpos.z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = tr.endpos.x;
    this->m_vecOrigin.m_Value.y = v11;
    this->m_vecOrigin.m_Value.z = v10;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEWorldDecal *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10335A50
// Name: void TE_WorldDecal(class IRecipientFilter __near &,float,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_WorldDecal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEWorldDecal::NetworkVar_m_vecOrigin> *pos,
        int index)
{
  if ( pos->m_Value.x != g_TEWorldDecal.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEWorldDecal.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEWorldDecal.m_vecOrigin.m_Value.z )
  {
    g_TEWorldDecal.m_vecOrigin = *pos;
  }
  if ( g_TEWorldDecal.m_nIndex.m_Value != index )
    g_TEWorldDecal.m_nIndex.m_Value = index;
  CBaseTempEntity::Create(this: &g_TEWorldDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417A20
// Name: DT_TEWorldDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEWorldDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEWorldDecal::g_SendTable);
  return atexit(func: DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417A40
// Name: DT_TEWorldDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEWorldDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEWorldDecal::ignored>();
  DT_TEWorldDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422A20
// Name: DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEWorldDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEWorldDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102303B0
// Name: struct datamap_t __near * DataMapInit<class CBaseTeamObjectiveResource>(class CBaseTeamObjectiveResource __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseTeamObjectiveResource>()
{
  if ( (_S3_128 & 1) == 0 )
  {
    _S3_128 |= 1u;
    nameHolder_411.m_pszBase = "CBaseTeamObjectiveResource";
    nameHolder_411.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_411.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_411.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_411.m_Names.m_Size = 0;
    nameHolder_411.m_Names.m_pElements = nullptr;
    nameHolder_411.m_nLenBase = 26;
    atexit(func: DataMapInit_CBaseTeamObjectiveResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseTeamObjectiveResource::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_128 & 2) == 0 )
  {
    _S3_128 |= 2u;
    dataDesc_391[28].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_411,
                                   pszIdentifier: "ObjectiveThink");
    dataDesc_391[28].fieldOffset = 0;
    *(_DWORD *)&dataDesc_391[28].fieldSize = 2097153;
    dataDesc_391[28].externalName = nullptr;
    dataDesc_391[28].pSaveRestoreOps = nullptr;
    dataDesc_391[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_BattleLine::`vcall'{776,{flat}};
    *(_QWORD *)&dataDesc_391[28].td = 0;
    *(_QWORD *)&dataDesc_391[28].override_field = 0;
    *(_QWORD *)&dataDesc_391[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_391[28].flatOffset[1] = 0;
  }
  CBaseTeamObjectiveResource::m_DataMap.dataNumFields = 28;
  CBaseTeamObjectiveResource::m_DataMap.dataDesc = &dataDesc_391[1];
  return &CBaseTeamObjectiveResource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102319E0
// Name: struct datamap_t __near * DataMapInit<class CTeamplayRoundBasedRulesProxy>(class CTeamplayRoundBasedRulesProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTeamplayRoundBasedRulesProxy>()
{
  if ( (_S4_60 & 1) == 0 )
  {
    _S4_60 |= 1u;
    nameHolder_414.m_pszBase = "CTeamplayRoundBasedRulesProxy";
    nameHolder_414.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_414.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_414.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_414.m_Names.m_Size = 0;
    nameHolder_414.m_Names.m_pElements = nullptr;
    nameHolder_414.m_nLenBase = 29;
    atexit(func: DataMapInit_CTeamplayRoundBasedRulesProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTeamplayRoundBasedRulesProxy::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTeamplayRoundBasedRulesProxy::m_DataMap.dataNumFields = 1;
  CTeamplayRoundBasedRulesProxy::m_DataMap.dataDesc = &dataDesc_394[1];
  return &CTeamplayRoundBasedRulesProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10417A50
// Name: _dynamic_initializer_for__g_TEWorldDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEWorldDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEWorldDecal, name: "World Decal");
  g_TEWorldDecal.__vftable = (CTEWorldDecal_vtbl *)&CTEWorldDecal::`vftable';
  if ( g_TEWorldDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEWorldDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEWorldDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEWorldDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEWorldDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEWorldDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEWorldDecal.m_nIndex.m_Value != 0 )
    g_TEWorldDecal.m_nIndex.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEWorldDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x10417AD0
// Name: _dynamic_initializer_for__g_UserMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UserMessages__()
{
  RegisterUserMessages();
  return atexit(func: dynamic_atexit_destructor_for__g_UserMessages__);
}

//------------------------------------------------------------------------------
// Address: 0x10417AF0
// Name: _dynamic_initializer_for__g_FoundryEntitySpawnRecords__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FoundryEntitySpawnRecords__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FoundryEntitySpawnRecords__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B00
// Name: _dynamic_initializer_for__g_ServerTools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ServerTools__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ServerTools__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B10
// Name: _dynamic_initializer_for____g_CreateCServerToolsIServerTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerToolsIServerTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerToolsIServerTools_reg,
           fn: (void *(__cdecl *)())_CreateCServerToolsIServerTools_interface,
           pName: "VSERVERTOOLS001");
}

//------------------------------------------------------------------------------
// Address: 0x10417B30
// Name: _dynamic_initializer_for__ent_keyvalue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_keyvalue__()
{
  ConCommand::ConCommand(
    this: &ent_keyvalue,
    pName: "ent_keyvalue",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_Keyvalue,
    pHelpString: "Applies the comma delimited key=value pairs to the entity with the given Hammer ID.\n"
    "\tFormat: ent_keyvalue <entity id> <key1>=<value1>,<key2>=<value2>,...,<keyN>=<valueN>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_keyvalue__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B60
// Name: _dynamic_initializer_for__g_ToolFrameworkServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ToolFrameworkServer__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_ToolFrameworkServer, name: nullptr);
  g_ToolFrameworkServer.CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CToolFrameworkServer_vtbl *)&CToolFrameworkServer::`vftable'{for `CAutoGameSystemPerFrame'};
  g_ToolFrameworkServer.IToolFrameworkServer::__vftable = (IToolFrameworkServer_vtbl *)&CToolFrameworkServer::`vftable'{for `IToolFrameworkServer'};
  return atexit(func: dynamic_atexit_destructor_for__g_ToolFrameworkServer__);
}

//------------------------------------------------------------------------------
// Address: 0x10417B90
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10417BC0
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10417BF0
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10417C20
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C60
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x10417C90
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x10417CC0
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x10422A30
// Name: _dynamic_atexit_destructor_for__g_TEWorldDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEWorldDecal__()
{
  g_TEWorldDecal.__vftable = (CTEWorldDecal_vtbl *)&CTEWorldDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEWorldDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10422A50
// Name: _ServerClassInit_DT_TEWorldDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEWorldDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_361;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10422A70
// Name: _dynamic_atexit_destructor_for__g_UserMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UserMessages__()
{
  CUserMessages::~CUserMessages(this: &g_UserMessages);
}

//------------------------------------------------------------------------------
// Address: 0x10422A80
// Name: _dynamic_atexit_destructor_for__ent_keyvalue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_keyvalue__()
{
  ConCommand::~ConCommand(this: &ent_keyvalue);
}

//------------------------------------------------------------------------------
// Address: 0x10422A90
// Name: _dynamic_atexit_destructor_for__g_ServerTools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerTools__()
{
  g_ServerTools.__vftable = (CServerTools_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10422AA0
// Name: _dynamic_atexit_destructor_for__g_FoundryEntitySpawnRecords__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FoundryEntitySpawnRecords__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_FoundryEntitySpawnRecords);
  if ( g_FoundryEntitySpawnRecords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_FoundryEntitySpawnRecords.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_FoundryEntitySpawnRecords.m_Memory.m_pMemory);
      g_FoundryEntitySpawnRecords.m_Memory.m_pMemory = nullptr;
    }
    g_FoundryEntitySpawnRecords.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10422AF0
// Name: _dynamic_atexit_destructor_for__g_ToolFrameworkServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ToolFrameworkServer__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_ToolFrameworkServer);
}

//------------------------------------------------------------------------------
// Address: 0x10422B00
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x10422B10
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x10422B20
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x10422B30
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
// Address: 0x10422B60
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x10422B70
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x10422B80
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}
