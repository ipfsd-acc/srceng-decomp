// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_texturetoggle.cpp
// Functions: 7
// ============================================================

#include "game\server\env_texturetoggle.h"

//------------------------------------------------------------------------------
// Address: 0x10118960
// Name: private: virtual struct datamap_t __near * CTextureToggle::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTextureToggle::GetDataDescMap(CTextureToggle *this)
{
  return &CTextureToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101189B0
// Name: public: void CTextureToggle::InputIncrementBrushTexIndex(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureToggle::InputIncrementBrushTexIndex(CTextureToggle *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CBasePlayer *i; // edi
  unsigned __int8 v4; // bl
  CBaseEdict *v5; // ecx
  const char *v6; // eax

  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: pszValue,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName: v6,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr) )
  {
    v4 = i->m_iTextureFrameIndex.m_Value + 1;
    if ( i->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&i->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &i->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x1F4u);
    }
    i->m_iTextureFrameIndex.m_Value = v4;
    v6 = this->m_target.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118A60
// Name: public: void CTextureToggle::InputSetBrushTexIndex(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureToggle::InputSetBrushTexIndex(CTextureToggle *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  CBasePlayer *i; // edi
  const char *v4; // ebx
  CBaseEdict *v5; // ecx
  const char *v6; // eax

  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: pszValue,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName: v6,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr) )
  {
    if ( inputdata->value.fieldType == FIELD_INTEGER )
      v4 = inputdata->value.iszVal.pszValue;
    else
      LOBYTE(v4) = 0;
    if ( i->m_iTextureFrameIndex.m_Value != (_BYTE)v4 )
    {
      if ( i->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&i->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = &i->m_Network.m_pPev->CBaseEdict;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: v5, offset: 0x1F4u);
      }
      i->m_iTextureFrameIndex.m_Value = (unsigned __int8)v4;
    }
    v6 = this->m_target.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402AC0
// Name: CTextureToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTextureToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTextureToggle>(__formal: nullptr);
  CTextureToggle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10118B10
// Name: struct datamap_t __near * DataMapInit<class CTextureToggle>(class CTextureToggle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTextureToggle>()
{
  if ( (_S2_90 & 1) == 0 )
  {
    _S2_90 |= 1u;
    nameHolder_169.m_pszBase = "CTextureToggle";
    nameHolder_169.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_169.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_169.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_169.m_Names.m_Size = 0;
    nameHolder_169.m_Names.m_pElements = nullptr;
    nameHolder_169.m_nLenBase = 14;
    atexit(func: DataMapInit_CTextureToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTextureToggle::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTextureToggle::m_DataMap.dataNumFields = 2;
  CTextureToggle::m_DataMap.dataDesc = &dataDesc_159[1];
  return &CTextureToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402AD0
// Name: _dynamic_initializer_for__mat_hdr_tonemapscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_tonemapscale__()
{
  ConVar::ConVar(
    this: &mat_hdr_tonemapscale,
    pName: "mat_hdr_tonemapscale",
    pDefaultValue: "1.0",
    flags: 0x4000,
    pHelpString: "The HDR tonemap scale. 1 = Use autoexposure, 0 = eyes fully closed, 16 = eyes wide open.");
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_tonemapscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10402B00
// Name: _dynamic_initializer_for__env_tonemap_controller__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_tonemap_controller__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvTonemapController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_tonemap_controller,
           a3: "env_tonemap_controller");
}
