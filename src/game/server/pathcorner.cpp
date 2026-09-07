// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pathcorner.cpp
// Functions: 9
// ============================================================

#include "game\server\pathcorner.h"

//------------------------------------------------------------------------------
// Address: 0x1017D180
// Name: public: virtual struct datamap_t __near * CPathCorner::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPathCorner::GetDataDescMap(CPathCorner *this)
{
  return &CPathCorner::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017D190
// Name: public: void CPathCorner::InputInPass(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathCorner::InputInPass(CPathCorner *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnPass,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1017D1C0
// Name: public: void CPathCorner::InputSetNextPathCorner(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathCorner::InputSetNextPathCorner(CPathCorner *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_STRING )
    this->m_target.pszValue = inputdata->value.iszVal.pszValue;
  else
    this->m_target.pszValue = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017D1F0
// Name: public: virtual int CPathCorner::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPathCorner::DrawDebugTextOverlays(CPathCorner *this)
{
  int result; // eax
  int v3; // esi
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    if ( this->m_target.pszValue != nullptr )
      V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Target: %s", this->m_target.pszValue);
    else
      V_strncpy(pDest: tempstr, pSrc: "Target:   -  ", maxLen: 255);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D290
// Name: public: virtual void CPathCorner::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathCorner::DrawDebugGeometryOverlays(CPathCorner *this)
{
  unsigned int v2; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // edi
  Vector mins; // [esp+10h] [ebp-18h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 0x24) != 0 )
  {
    v2 = (unsigned int)this->m_iEFlags >> 11;
    maxs.x = 10.0;
    maxs.y = 10.0;
    maxs.z = 10.0;
    mins.x = -10.0;
    mins.y = -10.0;
    mins.z = -10.0;
    if ( (v2 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 255, g: 100, b: 100, a: 0, flDuration: 0.0);
    pszValue = this->m_target.pszValue;
    if ( pszValue != nullptr )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
      {
        if ( (EntityByName->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        NDebugOverlay::Line(
          origin: &this->m_vecAbsOrigin,
          target: &EntityByName->m_vecAbsOrigin,
          r: 255,
          g: 100,
          b: 100,
          noDepthTest: 1,
          duration: 0.0);
      }
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10406BC0
// Name: _dynamic_initializer_for__path_corner__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__path_corner__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPathCorner> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &path_corner,
           a3: "path_corner");
}

//------------------------------------------------------------------------------
// Address: 0x10406BE0
// Name: _dynamic_initializer_for__path_corner_crash__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__path_corner_crash__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPathCornerCrash> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &path_corner_crash,
           a3: "path_corner_crash");
}

//------------------------------------------------------------------------------
// Address: 0x10406C00
// Name: CPathCorner_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPathCorner_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPathCorner>();
  CPathCorner_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406C20
// Name: _dynamic_initializer_for__path_track__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__path_track__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPathTrack> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &path_track,
           a3: "path_track");
}
