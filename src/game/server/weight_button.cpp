// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/weight_button.cpp
// Functions: 5
// ============================================================

#include "game\server\weight_button.h"

//------------------------------------------------------------------------------
// Address: 0x10266D20
// Name: public: virtual struct datamap_t __near * CWeightButton::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWeightButton::GetDataDescMap(CWeightButton *this)
{
  return &CWeightButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10266D30
// Name: public: void CWeightButton::TriggerThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeightButton::TriggerThink(CWeightButton *this@<ecx>, int a2@<edi>)
{
  IPhysicsObject *m_pPhysicsObject; // eax
  float m_fStressToActivate; // xmm0_4
  vphysics_objectstress_t vpobj_StressOut; // [esp+Ch] [ebp-10h] BYREF
  float fStress; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    fStress = CalculateObjectStress(
                a1: COERCE_FLOAT(&savedregs),
                a2,
                a3: (int)this,
                pObject: m_pPhysicsObject,
                pInputOwnerEntity: this,
                pOutput: &vpobj_StressOut);
    m_fStressToActivate = this->m_fStressToActivate;
    if ( fStress <= m_fStressToActivate || this->m_bHasBeenPressed )
    {
      if ( m_fStressToActivate > fStress && this->m_bHasBeenPressed )
      {
        COutputEvent::FireOutput(this: &this->m_OnReleased, pActivator: this, pCaller: this, fDelay: 0.0);
        this->m_bHasBeenPressed = false;
      }
    }
    else
    {
      COutputEvent::FireOutput(this: &this->m_OnPressed, pActivator: this, pCaller: this, fDelay: 0.0);
      this->m_bHasBeenPressed = true;
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10266E00
// Name: public: virtual void CWeightButton::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeightButton::Spawn(CWeightButton *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+14h] [ebp-4h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  v2 = *(const char **)((int (__thiscall *)(CWeightButton *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  this->CreateVPhysics(this);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CWeightButton::TriggerThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime, szContext: nullptr);
  this->m_bHasBeenPressed = false;
}

//------------------------------------------------------------------------------
// Address: 0x1040D090
// Name: CWeightButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWeightButton_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWeightButton>();
  CWeightButton_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10266EA0
// Name: class CWeightButton __near * _CreateEntityTemplate<class CWeightButton>(class CWeightButton __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWeightButton *__cdecl _CreateEntityTemplate<CWeightButton>(CWeightButton *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CWeightButton::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CWeightButton *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
