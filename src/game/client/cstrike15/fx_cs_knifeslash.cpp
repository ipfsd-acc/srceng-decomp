// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/fx_cs_knifeslash.cpp
// Functions: 2
// ============================================================

#include "game\client\cstrike15\fx_cs_knifeslash.h"

//------------------------------------------------------------------------------
// Address: 0x101CB3E0
// Name: void KnifeSlash(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall KnifeSlash(int a1@<ebx>, int a2@<edi>, const CEffectData *data)
{
  C_BaseEntity *v3; // esi
  IDecalEmitterSystem_vtbl *v4; // ebx
  const char *ImpactDecal; // eax
  int v6; // edi
  ConVar *v7; // eax
  ConVar *m_pParent; // eax
  C_BaseEntity_vtbl *v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  CGameTrace tr; // [esp+4h] [ebp-B4h] BYREF
  Vector vecPerp; // [esp+58h] [ebp-60h] BYREF
  Vector vecShotDir; // [esp+64h] [ebp-54h] BYREF
  Vector traceExt; // [esp+70h] [ebp-48h] BYREF
  IVEfx_vtbl *v20; // [esp+7Ch] [ebp-3Ch]
  __int16 nSurfaceProp; // [esp+80h] [ebp-38h] BYREF
  Vector shotDir; // [esp+84h] [ebp-34h] BYREF
  Vector vecOrigin; // [esp+90h] [ebp-28h] BYREF
  int iDamageType; // [esp+9Ch] [ebp-1Ch] BYREF
  Vector vecStart; // [esp+A0h] [ebp-18h] BYREF
  int iMaterial; // [esp+ACh] [ebp-Ch] BYREF
  int decalNumber; // [esp+B0h] [ebp-8h]
  int iHitbox; // [esp+B4h] [ebp-4h] BYREF
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  v3 = ParseImpactData(data, &vecOrigin, &vecStart, &vecShotDir, &nSurfaceProp, &iMaterial, &iDamageType, &iHitbox);
  if ( v3 != nullptr )
  {
    v4 = decalsystem->__vftable;
    ImpactDecal = GetImpactDecal(pEntity: v3, iMaterial, iDamageType);
    v6 = v4->GetDecalIndexForName(this: decalsystem, a2: ImpactDecal);
    if ( v6 != -1 )
    {
      AngleVectors(angles: &data->m_vAngles, forward: nullptr, right: &vecPerp, up: nullptr);
      v7 = cvar->FindVar_2(this: cvar, a2: "r_decals");
      if ( v7 != nullptr )
      {
        m_pParent = v7->m_pParent;
        if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
        {
          if ( ((int (__thiscall *)(IClientNetworkable *, int, int))v3->entindex)(
                 a1: &v3->IClientNetworkable,
                 a2,
                 a3: a1) != 0
            || iHitbox == 0 )
          {
            v9 = v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
            v20 = effects->__vftable;
            v10 = ((int (__thiscall *)(C_BaseEntity *, Vector *, Vector *))v9->GetAbsAngles)(
                    a1: v3,
                    a2: &vecOrigin,
                    a3: &vecPerp);
            v11 = ((int (__thiscall *)(C_BaseEntity *, int))v3->GetAbsOrigin)(a1: v3, a2: v10);
            v12 = ((int (__thiscall *)(IClientRenderable *, int))v3->GetModel)(a1: &v3->IClientRenderable, a2: v11);
            v13 = ((int (__thiscall *)(IClientNetworkable *, int))v3->entindex)(a1: &v3->IClientNetworkable, a2: v12);
            ((void (__thiscall *)(IVEfx *, int, int))v20->DecalShoot)(a1: effects, a2: v6, a3: v13);
          }
          else
          {
            shotDir.x = vecOrigin.x - vecStart.x;
            shotDir.y = vecOrigin.y - vecStart.y;
            shotDir.z = vecOrigin.z - vecStart.z;
            *(float *)&decalNumber = VectorNormalize(vec: &shotDir) + 8.0;
            traceExt.x = (float)(shotDir.x * *(float *)&decalNumber) + vecStart.x;
            traceExt.y = (float)(shotDir.y * *(float *)&decalNumber) + vecStart.y;
            traceExt.z = (float)(shotDir.z * *(float *)&decalNumber) + vecStart.z;
            ((void (__thiscall *)(IStaticPropMgrClient *, Vector *, Vector *, int, int))staticpropmgr->AddDecalToStaticProp)(
              a1: staticpropmgr,
              a2: &vecStart,
              a3: &traceExt,
              a4: iHitbox - 1,
              a5: v6);
          }
        }
      }
      if ( Impact(
             a1: (int)&savedregs,
             a2: v6,
             a3: (int)v3,
             &vecOrigin,
             &vecStart,
             iMaterial,
             iDamageType,
             iHitbox,
             pEntity: v3,
             &tr,
             nFlags: data->m_fFlags,
             maxLODToDecal: -1) != 0 )
        PerformCustomEffects(&vecOrigin, &tr, shotDir: &vecShotDir, iMaterial, iScale: 1, nFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104236C0
// Name: KnifeSlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int KnifeSlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  KnifeSlashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&KnifeSlashPrecache::s_ResourcePrecacher;
  return result;
}
