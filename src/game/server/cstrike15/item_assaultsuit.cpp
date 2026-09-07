// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/item_assaultsuit.cpp
// Functions: 1
// ============================================================

#include "game\server\cstrike15\item_assaultsuit.h"

//------------------------------------------------------------------------------
// Address: 0x102A4010
// Name: private: virtual bool CItemAssaultSuit::MyTouch(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CItemAssaultSuit::MyTouch(CItemAssaultSuit *this, CBasePlayer *pBasePlayer)
{
  CBaseEdict **v3; // eax
  CBaseEdict **v4; // edi
  CBaseEdict *v6; // ecx
  edict_t *m_pPev; // eax
  CPASAttenuationFilter filter; // [esp+10h] [ebp-20h] BYREF

  v3 = (CBaseEdict **)__RTDynamicCast(
                        inptr: pBasePlayer,
                        VfDelta: 0,
                        SrcType: &CBasePlayer `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  if ( *((_BYTE *)v3 + 4900) != 1 )
  {
    if ( *((_BYTE *)v3 + 84) != 0 )
    {
      *((_BYTE *)v3 + 88) |= 1u;
    }
    else
    {
      v6 = v3[6];
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1324u);
    }
    *((_BYTE *)v4 + 4900) = 1;
  }
  CBasePlayer::SetArmorValue(this: (CBasePlayer *)v4, value: 100);
  if ( !CBasePlayer::IsDead(this: (CBasePlayer *)v4) )
  {
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: pBasePlayer, attenuation: 0.80000001);
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: (int)m_pPev,
      soundname: "BaseCombatCharacter.ItemPickup2",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  return 1;
}
