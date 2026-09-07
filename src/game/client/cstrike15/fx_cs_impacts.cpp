// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/fx_cs_impacts.cpp
// Functions: 3
// ============================================================

#include "game\client\cstrike15\fx_cs_impacts.h"

//------------------------------------------------------------------------------
// Address: 0x101CB330
// Name: void ImpactCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall ImpactCallback(int a1@<edi>, const CEffectData *data)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi
  CGameTrace tr; // [esp+4h] [ebp-88h] BYREF
  Vector vecShotDir; // [esp+58h] [ebp-34h] BYREF
  Vector vecStart; // [esp+64h] [ebp-28h] BYREF
  Vector vecOrigin; // [esp+70h] [ebp-1Ch] BYREF
  int iDamageType; // [esp+7Ch] [ebp-10h] BYREF
  int iHitbox; // [esp+80h] [ebp-Ch] BYREF
  int iMaterial; // [esp+84h] [ebp-8h] BYREF
  __int16 nSurfaceProp; // [esp+88h] [ebp-4h] BYREF
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  v2 = ParseImpactData(data, &vecOrigin, &vecStart, &vecShotDir, &nSurfaceProp, &iMaterial, &iDamageType, &iHitbox);
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( Impact(
           a1: (int)&savedregs,
           a2: a1,
           a3: (int)v2,
           &vecOrigin,
           &vecStart,
           iMaterial,
           iDamageType,
           iHitbox,
           pEntity: v2,
           &tr,
           nFlags: (iDamageType & 0x100) != 0,
           maxLODToDecal: -1) != 0 )
      PerformCustomEffects(&vecOrigin, &tr, shotDir: &vecShotDir, iMaterial, iScale: 1, nFlags: 0);
    PlayImpactSound(pEntity: v3, &tr, vecServerOrigin: &vecOrigin, nServerSurfaceProp: nSurfaceProp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10423680
// Name: ImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104236A0
// Name: _dynamic_initializer_for__ClientEffectReg_KnifeSlash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_KnifeSlash__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_KnifeSlash,
           pEffectName: "KnifeSlash",
           fn: (void (__cdecl *)(const CEffectData *))KnifeSlash);
}
