// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/item_kevlar.cpp
// Functions: 3
// ============================================================

#include "game\server\cstrike15\item_kevlar.h"

//------------------------------------------------------------------------------
// Address: 0x102A4590
// Name: public: virtual void CItemKevlar::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemKevlar::Precache(CItemAssaultSuit *this)
{
  CBaseEntity::PrecacheScriptSound(soundname: "BaseCombatCharacter.ItemPickup2");
}

//------------------------------------------------------------------------------
// Address: 0x102A45A0
// Name: public: virtual bool CItemKevlar::MyTouch(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CItemKevlar::MyTouch(CItemKevlar *this, CBasePlayer *pBasePlayer)
{
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  edict_t *m_pPev; // eax
  CPASAttenuationFilter filter; // [esp+14h] [ebp-20h] BYREF

  v3 = (CBasePlayer *)__RTDynamicCast(
                        inptr: pBasePlayer,
                        VfDelta: 0,
                        SrcType: &CBasePlayer `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  CBasePlayer::SetArmorValue(this: v3, value: 100);
  if ( !CBasePlayer::IsDead(this: v4) )
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

//------------------------------------------------------------------------------
// Address: 0x102A46A0
// Name: public: virtual void CItemKevlar::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemKevlar::Spawn(CItemAssaultSuit *this)
{
  this->Precache(this);
  CItem::Spawn(this);
}
