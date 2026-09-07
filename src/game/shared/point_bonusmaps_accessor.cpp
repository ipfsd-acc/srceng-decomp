// Original: game/shared/point_bonusmaps_accessor.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "game\shared\point_bonusmaps_accessor.h"

// Stub: dynamic initializer for 'g_GameUI''
void dynamic initializer for 'g_GameUI''() {}

// Stub: dynamic atexit destructor for 'g_GameUI''
void dynamic atexit destructor for 'g_GameUI''() {}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101D1130
// Name: public: virtual struct datamap_t __near * CPointBonusMapsAccessor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointBonusMapsAccessor::GetDataDescMap(CPointBonusMapsAccessor *this)
{
  return &CPointBonusMapsAccessor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D1140
// Name: public: virtual void CPointBonusMapsAccessor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointBonusMapsAccessor::Activate(CPointBonusMapsAccessor *this)
{
  void *(__cdecl *Factory)(const char *, int *); // eax

  CBaseEntity::Activate(this);
  Factory = CDllDemandLoader::GetFactory(this: &g_GameUI);
  if ( Factory != nullptr )
    this->m_pGameUI = (IGameUI *)Factory(a1: "GameUI011", a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D1170
// Name: public: void CPointBonusMapsAccessor::InputComplete(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointBonusMapsAccessor::InputComplete(CPointBonusMapsAccessor *this, inputdata_t *inputdata)
{
  IGameEvent *v2; // esi

  if ( this->m_pGameUI != nullptr )
  {
    v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "advanced_map_complete", a3: 0, a4: 0);
    if ( v2 != nullptr )
    {
      v2->SetInt(this: v2, a2: "numadvanced", a3: 0);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408580
// Name: CPointBonusMapsAccessor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointBonusMapsAccessor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointBonusMapsAccessor>();
  CPointBonusMapsAccessor_DataDescInit::g_DataMapHolder = result;
  return result;
}

} // namespace server
