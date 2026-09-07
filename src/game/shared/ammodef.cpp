// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/ammodef.cpp
// Functions: 16
// ============================================================

#include "game\shared\ammodef.h"

//------------------------------------------------------------------------------
// Address: 0x10008600
// Name: public: int CAmmoDef::Index(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::Index(CAmmoDef *this, const char *psz)
{
  int v4; // esi
  Ammo_t *i; // edi

  if ( psz == nullptr )
    return -1;
  v4 = 1;
  if ( this->m_nAmmoIndex <= 1 )
    return -1;
  for ( i = &this->m_AmmoType[1]; _V_stricmp(s1: psz, s2: i->pName) != 0; ++i )
  {
    if ( ++v4 >= this->m_nAmmoIndex )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008660
// Name: public: int CAmmoDef::DamageType(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::DamageType(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].nDamageType;
}

//------------------------------------------------------------------------------
// Address: 0x10008690
// Name: public: int CAmmoDef::Flags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::Flags(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100086C0
// Name: public: int CAmmoDef::MinSplashSize(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MinSplashSize(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 4;
  else
    return this->m_AmmoType[nAmmoIndex].nMinSplashSize;
}

//------------------------------------------------------------------------------
// Address: 0x100086F0
// Name: public: int CAmmoDef::MaxSplashSize(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MaxSplashSize(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 8;
  else
    return this->m_AmmoType[nAmmoIndex].nMaxSplashSize;
}

//------------------------------------------------------------------------------
// Address: 0x10008720
// Name: public: int CAmmoDef::TracerType(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::TracerType(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].eTracerType;
}

//------------------------------------------------------------------------------
// Address: 0x10008750
// Name: public: float CAmmoDef::DamageForce(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAmmoDef::DamageForce(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0.0;
  else
    return this->m_AmmoType[nAmmoIndex].physicsForceImpulse;
}

//------------------------------------------------------------------------------
// Address: 0x10008780
// Name: private: bool CAmmoDef::AddAmmoType(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  unsigned int v9; // kr00_4

  if ( this->m_nAmmoIndex == 32 )
    return 0;
  v9 = strlen(name);
  this->m_AmmoType[this->m_nAmmoIndex].pName = (char *)MemAlloc_Alloc(nSize: v9 + 1);
  V_strncpy(pDest: this->m_AmmoType[this->m_nAmmoIndex].pName, pSrc: name, maxLen: v9 + 1);
  this->m_AmmoType[this->m_nAmmoIndex].nDamageType = damageType;
  this->m_AmmoType[this->m_nAmmoIndex].eTracerType = tracerType;
  this->m_AmmoType[this->m_nAmmoIndex].nMinSplashSize = minSplashSize;
  this->m_AmmoType[this->m_nAmmoIndex].nMaxSplashSize = maxSplashSize;
  this->m_AmmoType[this->m_nAmmoIndex].nFlags = nFlags;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008820
// Name: public: void CAmmoDef::AddAmmoType(char const __near *,int,int,char const __near *,char const __near *,char const __near *,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        const char *plr_cvar,
        const char *npc_cvar,
        const char *carry_cvar,
        float physicsForceImpulse,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  if ( CAmmoDef::AddAmmoType(this, name, damageType, tracerType, nFlags, minSplashSize, maxSplashSize) != 0 )
  {
    if ( plr_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pPlrDmgCVar = cvar->FindVar_2(this: cvar, a2: plr_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pPlrDmgCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, plr_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pPlrDmg = -1;
    }
    if ( npc_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pNPCDmgCVar = cvar->FindVar_2(this: cvar, a2: npc_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pNPCDmgCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, npc_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pNPCDmg = -1;
    }
    if ( carry_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pMaxCarryCVar = cvar->FindVar_2(this: cvar, a2: carry_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pMaxCarryCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, carry_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pMaxCarry = -1;
    }
    this->m_AmmoType[this->m_nAmmoIndex++].physicsForceImpulse = physicsForceImpulse;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008950
// Name: public: void CAmmoDef::AddAmmoType(char const __near *,int,int,int,int,int,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        int plr_dmg,
        int npc_dmg,
        int carry,
        float physicsForceImpulse,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  if ( CAmmoDef::AddAmmoType(this, name, damageType, tracerType, nFlags, minSplashSize, maxSplashSize) != 0 )
  {
    this->m_AmmoType[this->m_nAmmoIndex].pPlrDmg = plr_dmg;
    this->m_AmmoType[this->m_nAmmoIndex].pNPCDmg = npc_dmg;
    this->m_AmmoType[this->m_nAmmoIndex].pMaxCarry = carry;
    this->m_AmmoType[this->m_nAmmoIndex++].physicsForceImpulse = physicsForceImpulse;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100089C0
// Name: public: CAmmoDef::CAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CAmmoDef *__thiscall CAmmoDef::CAmmoDef(CAmmoDef *this)
{
  this->__vftable = (CAmmoDef_vtbl *)&CAmmoDef::`vftable';
  this->m_nAmmoIndex = 1;
  memset(dst: (int)this->m_AmmoType, value: nullptr, count: sizeof(this->m_AmmoType));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100089F0
// Name: public: virtual CAmmoDef::~CAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::~CAmmoDef(CAmmoDef *this)
{
  Ammo_t *v1; // esi
  int i; // edi

  this->__vftable = (CAmmoDef_vtbl *)&CAmmoDef::`vftable';
  v1 = &this->m_AmmoType[1];
  for ( i = 31; i != 0; --i )
  {
    C_BaseEntity::operator delete(pMem: v1->pName);
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008A20
// Name: public: int CAmmoDef::PlrDamage(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::PlrDamage(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v2 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v2 + 9);
  if ( result != -1 )
    return result;
  v4 = *((_DWORD *)v2 + 12);
  if ( v4 != 0 )
    return (int)*(float *)(*(_DWORD *)(v4 + 28) + 44);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008A60
// Name: public: int CAmmoDef::NPCDamage(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::NPCDamage(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v2 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v2 + 10);
  if ( result != -1 )
    return result;
  v4 = *((_DWORD *)v2 + 13);
  if ( v4 != 0 )
    return (int)*(float *)(*(_DWORD *)(v4 + 28) + 44);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008AA0
// Name: public: int CAmmoDef::MaxCarry(int,class C_BaseCombatCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MaxCarry(CAmmoDef *this, int nAmmoIndex, const C_BaseCombatCharacter *owner)
{
  char *v3; // ecx
  int result; // eax
  int v5; // ecx
  int v6; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v3 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v3 + 11);
  if ( result != -1 )
    return result;
  v5 = *((_DWORD *)v3 + 14);
  if ( v5 != 0 && (v6 = *(_DWORD *)(v5 + 28)) != 0 )
    return *(_DWORD *)(v6 + 48);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008AE0
// Name: public: bool CAmmoDef::CanCarryInfiniteAmmo(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAmmoDef::CanCarryInfiniteAmmo(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return false;
  v2 = (char *)this + 52 * nAmmoIndex;
  v3 = *((_DWORD *)v2 + 11);
  if ( v3 == -1 )
  {
    v4 = *((_DWORD *)v2 + 14);
    if ( v4 != 0 )
    {
      v5 = *(_DWORD *)(v4 + 28);
      if ( v5 != 0 )
        return *(_DWORD *)(v5 + 48) == -2;
      v3 = 0;
    }
  }
  return v3 == -2;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10092900
// Name: public: struct Ammo_t __near * CAmmoDef::GetAmmoOfIndex(int)
// Source: json
//------------------------------------------------------------------------------
Ammo_t *__thiscall CAmmoDef::GetAmmoOfIndex(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < this->m_nAmmoIndex )
    return &this->m_AmmoType[nAmmoIndex];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10092920
// Name: public: int CAmmoDef::Index(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::Index(CAmmoDef *this, const char *psz)
{
  int v4; // esi
  Ammo_t *i; // edi

  if ( psz == nullptr )
    return -1;
  v4 = 1;
  if ( this->m_nAmmoIndex <= 1 )
    return -1;
  for ( i = &this->m_AmmoType[1]; _V_stricmp(s1: psz, s2: i->pName) != 0; ++i )
  {
    if ( ++v4 >= this->m_nAmmoIndex )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10092980
// Name: public: int CAmmoDef::DamageType(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::DamageType(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].nDamageType;
}

//------------------------------------------------------------------------------
// Address: 0x100929B0
// Name: public: int CAmmoDef::Flags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::Flags(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100929E0
// Name: public: int CAmmoDef::MinSplashSize(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MinSplashSize(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 4;
  else
    return this->m_AmmoType[nAmmoIndex].nMinSplashSize;
}

//------------------------------------------------------------------------------
// Address: 0x10092A10
// Name: public: int CAmmoDef::MaxSplashSize(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MaxSplashSize(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 8;
  else
    return this->m_AmmoType[nAmmoIndex].nMaxSplashSize;
}

//------------------------------------------------------------------------------
// Address: 0x10092A40
// Name: public: int CAmmoDef::TracerType(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::TracerType(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_AmmoType[nAmmoIndex].eTracerType;
}

//------------------------------------------------------------------------------
// Address: 0x10092A70
// Name: public: float CAmmoDef::DamageForce(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAmmoDef::DamageForce(CAmmoDef *this, int nAmmoIndex)
{
  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0.0;
  else
    return this->m_AmmoType[nAmmoIndex].physicsForceImpulse;
}

//------------------------------------------------------------------------------
// Address: 0x10092AA0
// Name: private: bool CAmmoDef::AddAmmoType(char const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  unsigned int v9; // kr00_4

  if ( this->m_nAmmoIndex == 32 )
    return 0;
  v9 = strlen(name);
  this->m_AmmoType[this->m_nAmmoIndex].pName = (char *)operator new(nSize: v9 + 1);
  V_strncpy(pDest: this->m_AmmoType[this->m_nAmmoIndex].pName, pSrc: name, maxLen: v9 + 1);
  this->m_AmmoType[this->m_nAmmoIndex].nDamageType = damageType;
  this->m_AmmoType[this->m_nAmmoIndex].eTracerType = tracerType;
  this->m_AmmoType[this->m_nAmmoIndex].nMinSplashSize = minSplashSize;
  this->m_AmmoType[this->m_nAmmoIndex].nMaxSplashSize = maxSplashSize;
  this->m_AmmoType[this->m_nAmmoIndex].nFlags = nFlags;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092B40
// Name: public: void CAmmoDef::AddAmmoType(char const __near *,int,int,char const __near *,char const __near *,char const __near *,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        const char *plr_cvar,
        const char *npc_cvar,
        const char *carry_cvar,
        float physicsForceImpulse,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  if ( CAmmoDef::AddAmmoType(this, name, damageType, tracerType, nFlags, minSplashSize, maxSplashSize) != 0 )
  {
    if ( plr_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pPlrDmgCVar = cvar->FindVar_2(this: cvar, a2: plr_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pPlrDmgCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, plr_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pPlrDmg = -1;
    }
    if ( npc_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pNPCDmgCVar = cvar->FindVar_2(this: cvar, a2: npc_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pNPCDmgCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, npc_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pNPCDmg = -1;
    }
    if ( carry_cvar != nullptr )
    {
      this->m_AmmoType[this->m_nAmmoIndex].pMaxCarryCVar = cvar->FindVar_2(this: cvar, a2: carry_cvar);
      if ( this->m_AmmoType[this->m_nAmmoIndex].pMaxCarryCVar == nullptr )
        _Msg(a1: "ERROR: Ammo (%s) found no CVar named (%s)\n", name, carry_cvar);
      this->m_AmmoType[this->m_nAmmoIndex].pMaxCarry = -1;
    }
    this->m_AmmoType[this->m_nAmmoIndex++].physicsForceImpulse = physicsForceImpulse;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092C70
// Name: public: void CAmmoDef::AddAmmoType(char const __near *,int,int,int,int,int,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::AddAmmoType(
        CAmmoDef *this,
        const char *name,
        int damageType,
        int tracerType,
        int plr_dmg,
        int npc_dmg,
        int carry,
        float physicsForceImpulse,
        int nFlags,
        int minSplashSize,
        int maxSplashSize)
{
  if ( CAmmoDef::AddAmmoType(this, name, damageType, tracerType, nFlags, minSplashSize, maxSplashSize) != 0 )
  {
    this->m_AmmoType[this->m_nAmmoIndex].pPlrDmg = plr_dmg;
    this->m_AmmoType[this->m_nAmmoIndex].pNPCDmg = npc_dmg;
    this->m_AmmoType[this->m_nAmmoIndex].pMaxCarry = carry;
    this->m_AmmoType[this->m_nAmmoIndex++].physicsForceImpulse = physicsForceImpulse;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092CE0
// Name: public: CAmmoDef::CAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CAmmoDef *__thiscall CAmmoDef::CAmmoDef(CAmmoDef *this)
{
  this->__vftable = (CAmmoDef_vtbl *)&CAmmoDef::`vftable';
  this->m_nAmmoIndex = 1;
  memset(dst: (int)this->m_AmmoType, value: nullptr, count: sizeof(this->m_AmmoType));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092D10
// Name: public: virtual CAmmoDef::~CAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmmoDef::~CAmmoDef(CAmmoDef *this)
{
  Ammo_t *v1; // esi
  int i; // edi

  this->__vftable = (CAmmoDef_vtbl *)&CAmmoDef::`vftable';
  v1 = &this->m_AmmoType[1];
  for ( i = 31; i != 0; --i )
  {
    free(pMem: v1->pName);
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092D40
// Name: public: int CAmmoDef::PlrDamage(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::PlrDamage(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v2 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v2 + 9);
  if ( result != -1 )
    return result;
  v4 = *((_DWORD *)v2 + 12);
  if ( v4 != 0 )
    return (int)*(float *)(*(_DWORD *)(v4 + 28) + 44);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092D80
// Name: public: int CAmmoDef::NPCDamage(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::NPCDamage(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v2 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v2 + 10);
  if ( result != -1 )
    return result;
  v4 = *((_DWORD *)v2 + 13);
  if ( v4 != 0 )
    return (int)*(float *)(*(_DWORD *)(v4 + 28) + 44);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092DC0
// Name: public: int CAmmoDef::MaxCarry(int,class CBaseCombatCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAmmoDef::MaxCarry(CAmmoDef *this, int nAmmoIndex, const CBaseCombatCharacter *owner)
{
  char *v3; // ecx
  int result; // eax
  int v5; // ecx
  int v6; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return 0;
  v3 = (char *)this + 52 * nAmmoIndex;
  result = *((_DWORD *)v3 + 11);
  if ( result != -1 )
    return result;
  v5 = *((_DWORD *)v3 + 14);
  if ( v5 != 0 && (v6 = *(_DWORD *)(v5 + 28)) != 0 )
    return *(_DWORD *)(v6 + 48);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092E00
// Name: public: bool CAmmoDef::CanCarryInfiniteAmmo(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAmmoDef::CanCarryInfiniteAmmo(CAmmoDef *this, int nAmmoIndex)
{
  char *v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // ecx

  if ( nAmmoIndex < 1 || nAmmoIndex >= this->m_nAmmoIndex )
    return false;
  v2 = (char *)this + 52 * nAmmoIndex;
  v3 = *((_DWORD *)v2 + 11);
  if ( v3 == -1 )
  {
    v4 = *((_DWORD *)v2 + 14);
    if ( v4 != 0 )
    {
      v5 = *(_DWORD *)(v4 + 28);
      if ( v5 != 0 )
        return *(_DWORD *)(v5 + 48) == -2;
      v3 = 0;
    }
  }
  return v3 == -2;
}

//------------------------------------------------------------------------------
// Address: 0x1040EAD0
// Name: _dynamic_initializer_for__ammoDef__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammoDef__()
{
  CCSAmmoDef::CCSAmmoDef(this: &ammoDef);
  return atexit(func: dynamic_atexit_destructor_for__ammoDef__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA60
// Name: _dynamic_atexit_destructor_for__ammoDef__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammoDef__()
{
  CCSAmmoDef::~CCSAmmoDef(this: &ammoDef);
}

//------------------------------------------------------------------------------
// Address: 0x1040EAF0
// Name: _dynamic_initializer_for__map_showspawnpoints_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_showspawnpoints_command__()
{
  ConCommand::ConCommand(
    this: &map_showspawnpoints_command,
    pName: "map_showspawnpoints",
    callback: map_showspawnpoints,
    pHelpString: "Shows player spawn points (red=invalid)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__map_showspawnpoints_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EB20
// Name: _dynamic_initializer_for__map_showbombradius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_showbombradius_command__()
{
  ConCommand::ConCommand(
    this: &map_showbombradius_command,
    pName: "map_showbombradius",
    callback: map_showbombradius,
    pHelpString: "Shows bomb radius from the center of each bomb site and planted bomb.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__map_showbombradius_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EB50
// Name: _dynamic_initializer_for__map_setbombradius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_setbombradius_command__()
{
  ConCommand::ConCommand(
    this: &map_setbombradius_command,
    pName: "map_setbombradius",
    callback: map_setbombradius,
    pHelpString: "Sets the bomb radius for the map.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__map_setbombradius_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EB80
// Name: _dynamic_initializer_for__sv_nonemesis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_nonemesis__()
{
  ConVar::ConVar(
    this: &sv_nonemesis,
    pName: "sv_nonemesis",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable nemesis and revenge.",
    callback: SvNoNemesisChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_nonemesis__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EBB0
// Name: _dynamic_initializer_for__sv_dumpmatchweaponmetrics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_dumpmatchweaponmetrics__()
{
  ConVar::ConVar(
    this: &sv_dumpmatchweaponmetrics,
    pName: "sv_dumpmatchweaponmetrics",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Turn on the exporting of weapon metrics at the end of a level.");
  return atexit(func: dynamic_atexit_destructor_for__sv_dumpmatchweaponmetrics__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EBE0
// Name: _dynamic_initializer_for__CCS_GameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CCS_GameStats__()
{
  CCSGameStats::CCSGameStats(this: &CCS_GameStats);
  return atexit(func: dynamic_atexit_destructor_for__CCS_GameStats__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA70
// Name: _dynamic_atexit_destructor_for__map_showspawnpoints_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_showspawnpoints_command__()
{
  ConCommand::~ConCommand(this: &map_showspawnpoints_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA80
// Name: _dynamic_atexit_destructor_for__map_showbombradius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_showbombradius_command__()
{
  ConCommand::~ConCommand(this: &map_showbombradius_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA90
// Name: _dynamic_atexit_destructor_for__map_setbombradius_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_setbombradius_command__()
{
  ConCommand::~ConCommand(this: &map_setbombradius_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAA0
// Name: _ServerClassInit_DT_CSGameRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSGameRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_241;
  for ( i = 23; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAC0
// Name: _dynamic_atexit_destructor_for__g_VoiceGameMgrHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VoiceGameMgrHelper__()
{
  g_VoiceGameMgrHelper.__vftable = (CVoiceGameMgrHelper_vtbl *)&IVoiceGameMgrHelper::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1041FAD0
// Name: _dynamic_atexit_destructor_for__sv_nonemesis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_nonemesis__()
{
  ConVar::~ConVar(this: &sv_nonemesis);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAE0
// Name: _dynamic_atexit_destructor_for__sv_dumpmatchweaponmetrics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_dumpmatchweaponmetrics__()
{
  ConVar::~ConVar(this: &sv_dumpmatchweaponmetrics);
}

//------------------------------------------------------------------------------
// Address: 0x1041FAF0
// Name: _dynamic_atexit_destructor_for__CCS_GameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CCS_GameStats__()
{
  CCSGameStats::~CCSGameStats(this: &CCS_GameStats);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB00
// Name: _dynamic_atexit_destructor_for__s_HLTVDirector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_HLTVDirector__()
{
  CHLTVDirector::~CHLTVDirector(this: &s_HLTVDirector);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB10
// Name: _dynamic_atexit_destructor_for__cs_ShowStateTransitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cs_ShowStateTransitions__()
{
  ConVar::~ConVar(this: &cs_ShowStateTransitions);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB20
// Name: _dynamic_atexit_destructor_for__sv_max_usercmd_future_ticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_max_usercmd_future_ticks__()
{
  ConVar::~ConVar(this: &sv_max_usercmd_future_ticks);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB30
// Name: _dynamic_atexit_destructor_for__cs_AssistDamageThreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cs_AssistDamageThreshold__()
{
  ConVar::~ConVar(this: &cs_AssistDamageThreshold);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB40
// Name: _dynamic_atexit_destructor_for__sv_nomvp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_nomvp__()
{
  ConVar::~ConVar(this: &sv_nomvp);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB50
// Name: _dynamic_atexit_destructor_for__sv_disablefreezecam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_disablefreezecam__()
{
  ConVar::~ConVar(this: &sv_disablefreezecam);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB60
// Name: _dynamic_atexit_destructor_for__sv_nowinpanel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_nowinpanel__()
{
  ConVar::~ConVar(this: &sv_nowinpanel);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB70
// Name: _dynamic_atexit_destructor_for__bot_mimic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_mimic__()
{
  ConVar::~ConVar(this: &bot_mimic);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB80
// Name: _dynamic_atexit_destructor_for__bot_freeze__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_freeze__()
{
  ConVar::~ConVar(this: &bot_freeze);
}

//------------------------------------------------------------------------------
// Address: 0x1041FB90
// Name: _dynamic_atexit_destructor_for__bot_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_crouch__()
{
  ConVar::~ConVar(this: &bot_crouch);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBA0
// Name: _dynamic_atexit_destructor_for__bot_mimic_yaw_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_mimic_yaw_offset__()
{
  ConVar::~ConVar(this: &bot_mimic_yaw_offset);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBB0
// Name: _dynamic_atexit_destructor_for__sv_autobuyammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_autobuyammo__()
{
  ConVar::~ConVar(this: &sv_autobuyammo);
}

} // namespace server
