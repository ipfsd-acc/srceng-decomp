// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_zoom.cpp
// Functions: 7
// ============================================================

#include "game\server\env_zoom.h"

//------------------------------------------------------------------------------
// Address: 0x1011ACB0
// Name: private: virtual struct datamap_t __near * CEnvZoom::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvZoom::GetDataDescMap(CEnvZoom *this)
{
  return &CEnvZoom::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011ACC0
// Name: public: void CEnvZoom::InputUnZoom(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvZoom::InputUnZoom(CEnvZoom *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // eax

  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    CBasePlayer::SetFOV(this: LocalPlayer, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011ACF0
// Name: public: class CBaseEntity __near * CBasePlayer::GetFOVOwner(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GetFOVOwner(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hZoomOwner.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1011AD20
// Name: bool CanOverrideEnvZoomOwner(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CanOverrideEnvZoomOwner(CBaseEntity *pZoomOwner)
{
  _BYTE *v1; // eax

  v1 = __RTDynamicCast(
         inptr: pZoomOwner,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CEnvZoom `RTTI Type Descriptor',
         isReference: 0);
  return v1 != nullptr && (v1[760] & 1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011AD60
// Name: public: void CEnvZoom::InputZoom(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvZoom::InputZoom(CEnvZoom *this, inputdata_t *inputdata)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v4; // edi
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CBaseEntity **v11; // eax
  CBaseEntity *v12; // ecx

  LocalPlayer = UTIL_GetLocalPlayer();
  v4 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    m_Index = LocalPlayer->m_hZoomOwner.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        v9 = v6;
        v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v9];
        if ( v10 )
        {
          v12 = *v11;
          if ( *v11 != nullptr
            && (v12->m_iClassname.pszValue == "env_zoom"
             || CBaseEntity::ClassMatchesComplex(this: v12, pszClassOrWildcard: "env_zoom") != 0) )
          {
            CBasePlayer::ClearZoomOwner(this: v4);
          }
        }
      }
    }
    CBasePlayer::SetFOV(this: v4, pRequester: this, FOV: this->m_nFOV, zoomRate: this->m_flSpeed, iZoomStart: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402C10
// Name: CEnvZoom_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvZoom_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvZoom>();
  CEnvZoom_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402C20
// Name: _dynamic_initializer_for__env_beam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_beam__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvBeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_beam,
           a3: "env_beam");
}
