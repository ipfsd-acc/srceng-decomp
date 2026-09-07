// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_areaportal.cpp
// Functions: 13
// ============================================================

#include "game\server\func_areaportal.h"

//------------------------------------------------------------------------------
// Address: 0x10130B40
// Name: public: virtual struct datamap_t __near * CAreaPortal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAreaPortal::GetDataDescMap(CAreaPortal *this)
{
  return &CAreaPortal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10130B50
// Name: public: virtual void CAreaPortal::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::Spawn(CAreaPortal *this)
{
  CBaseEntity::AddEffects(this, nEffects: 80);
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10130B70
// Name: public: virtual bool CAreaPortal::UpdateVisibility(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,float,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAreaPortal::UpdateVisibility(
        CAreaPortal *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *vecOrigins,
        float fovDistanceAdjustFactor,
        bool *bIsOpenOnClient)
{
  if ( this->m_state != 0 )
    return CFuncAreaPortalBase::UpdateVisibility(this, vecOrigins, fovDistanceAdjustFactor, bIsOpenOnClient);
  *bIsOpenOnClient = false;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10130BB0
// Name: public: virtual int CAreaPortal::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAreaPortal::UpdateTransmitState(CAreaPortal *this)
{
  return CBaseEntity::SetTransmitState(this, nFlag: 16);
}

//------------------------------------------------------------------------------
// Address: 0x10130BF0
// Name: public: virtual void CAreaPortal::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::Precache(CAreaPortal *this)
{
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: this->m_state);
}

//------------------------------------------------------------------------------
// Address: 0x10130C20
// Name: public: void CAreaPortal::InputClose(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::InputClose(CAreaPortal *this, inputdata_t *inputdata)
{
  this->m_state = 0;
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10130C50
// Name: public: void CAreaPortal::InputOpen(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::InputOpen(CAreaPortal *this, inputdata_t *inputdata)
{
  this->m_state = 1;
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10130C80
// Name: public: void CAreaPortal::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::InputToggle(CAreaPortal *this, inputdata_t *inputdata)
{
  BOOL v2; // edx

  v2 = this->m_state != 1;
  this->m_state = v2;
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10130CC0
// Name: public: virtual void CAreaPortal::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAreaPortal::Use(
        CAreaPortal *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( useType == USE_ON )
  {
    this->m_state = 1;
  }
  else
  {
    if ( useType != USE_OFF )
      return;
    this->m_state = 0;
  }
  engine->SetAreaPortalState(this: engine, a2: this->m_portalNumber, a3: this->m_state);
}

//------------------------------------------------------------------------------
// Address: 0x10130D10
// Name: public: virtual bool CAreaPortal::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAreaPortal::KeyValue(CAreaPortal *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "StartOpen" && _V_stricmp(s1: szKeyName, s2: "StartOpen") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_state = atoi(nptr: szValue) != 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1020E8C0
// Name: public: virtual int CFuncAreaPortalBase::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFuncAreaPortalBase::ObjectCaps(CPointEntity *this)
{
  return CBaseEntity::ObjectCaps(this) & 0xFFFFFF7F;
}

//------------------------------------------------------------------------------
// Address: 0x104039E0
// Name: CAreaPortal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAreaPortal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAreaPortal>();
  CAreaPortal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104039F0
// Name: _dynamic_initializer_for__g_AreaPortals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AreaPortals__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AreaPortals__);
}
