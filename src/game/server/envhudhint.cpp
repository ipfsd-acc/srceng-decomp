// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envhudhint.cpp
// Functions: 6
// ============================================================

#include "game\server\envhudhint.h"

//------------------------------------------------------------------------------
// Address: 0x1011D3D0
// Name: private: virtual struct datamap_t __near * CEnvHudHint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvHudHint::GetDataDescMap(CEnvHudHint *this)
{
  return &CEnvHudHint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011D3E0
// Name: public: virtual void CEnvHudHint::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvHudHint::Spawn(CEnvHudHint *this)
{
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1011D410
// Name: private: void CEnvHudHint::InputShowHudHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvHudHint::InputShowHudHint(CEnvHudHint *this, inputdata_t *inputdata)
{
  CBasePlayer *pActivator; // esi
  const char *pszValue; // eax
  CSingleUserRecipientFilter user; // [esp+8h] [ebp-20h] BYREF

  if ( inputdata->pActivator != nullptr && inputdata->pActivator->IsPlayer(this: inputdata->pActivator) )
    pActivator = (CBasePlayer *)inputdata->pActivator;
  else
    pActivator = UTIL_GetLocalPlayer();
  if ( pActivator != nullptr && pActivator->IsNetClient(this: pActivator) )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: pActivator);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "KeyHintText");
    MessageWriteByte(iValue: 1u);
    pszValue = this->m_iszMessage.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    MessageWriteString(sz: pszValue);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D4C0
// Name: private: void CEnvHudHint::InputHideHudHint(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvHudHint::InputHideHudHint(CEnvHudHint *this, inputdata_t *inputdata)
{
  CBasePlayer *pActivator; // esi
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( inputdata->pActivator != nullptr && inputdata->pActivator->IsPlayer(this: inputdata->pActivator) )
    pActivator = (CBasePlayer *)inputdata->pActivator;
  else
    pActivator = UTIL_GetLocalPlayer();
  if ( pActivator != nullptr && pActivator->IsNetClient(this: pActivator) )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: pActivator);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "KeyHintText");
    MessageWriteByte(iValue: 1u);
    MessageWriteString(sz: locale);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402D00
// Name: CEnvHudHint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvHudHint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvHudHint>();
  CEnvHudHint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402D10
// Name: _dynamic_initializer_for__env_laser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_laser__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvLaser> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_laser,
           a3: "env_laser");
}
