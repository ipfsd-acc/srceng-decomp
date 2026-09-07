// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/skycamera.cpp
// Functions: 12
// ============================================================

#include "game\server\skycamera.h"

//------------------------------------------------------------------------------
// Address: 0x1019B610
// Name: public: virtual void CEntityClassList<class CPhysicsNPCSolver>::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityClassList<CPhysicsNPCSolver>::LevelShutdownPostEntity(CEntityClassList<CPhysicsNPCSolver> *this)
{
  CEntityClassList<CPhysicsNPCSolver>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D12D0
// Name: public: virtual void CEntityClassList<class CPointCamera>::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityClassList<CPointCamera>::LevelShutdownPostEntity(CEntityClassList<CPointCamera> *this)
{
  CEntityClassList<CPointCamera>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10213EF0
// Name: class CSkyCamera __near * GetSkyCameraList(void)
// Source: json
//------------------------------------------------------------------------------
CSkyCamera *__cdecl GetSkyCameraList()
{
  return CEntityClassList<CSkyCamera>::m_pClassList;
}

//------------------------------------------------------------------------------
// Address: 0x10213F00
// Name: public: virtual struct datamap_t __near * CSkyCamera::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSkyCamera::GetDataDescMap(CSkyCamera *this)
{
  return &CSkyCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213F10
// Name: public: virtual void CEntityClassList<class CSkyCamera>::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityClassList<CSkyCamera>::LevelShutdownPostEntity(CEntityClassList<CSkyCamera> *this)
{
  CEntityClassList<CSkyCamera>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10213F80
// Name: public: virtual void CSkyCamera::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSkyCamera::Activate(CSkyCamera *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  CBaseEntity::Activate(this);
  if ( this->m_bUseAngles )
  {
    ((void (__thiscall *)(sky3dparams_t::NetworkVar_fog *, CNetworkVectorBase<Vector,fogparams_t::NetworkVar_dirPrimary> *, int))this->m_skyboxData.fog.NetworkStateChanged)(
      a1: &this->m_skyboxData.fog,
      a2: &this->m_skyboxData.fog.dirPrimary,
      a3);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    AngleVectors(angles: &this->m_angAbsRotation, forward: &this->m_skyboxData.fog.dirPrimary.m_Value);
    this->m_skyboxData.fog.NetworkStateChanged(this: &this->m_skyboxData.fog, a2: &this->m_skyboxData.fog.dirPrimary);
    this->m_skyboxData.fog.dirPrimary.m_Value.x = this->m_skyboxData.fog.dirPrimary.m_Value.x * -1.0;
    this->m_skyboxData.fog.dirPrimary.m_Value.y = this->m_skyboxData.fog.dirPrimary.m_Value.y * -1.0;
    this->m_skyboxData.fog.dirPrimary.m_Value.z = this->m_skyboxData.fog.dirPrimary.m_Value.z * -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214010
// Name: class CSkyCamera __near * GetCurrentSkyCamera(void)
// Source: json
//------------------------------------------------------------------------------
CSkyCamera *__cdecl GetCurrentSkyCamera()
{
  unsigned int m_Index; // eax

  m_Index = g_hActiveSkybox.m_Index;
  if ( g_hActiveSkybox.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(g_hActiveSkybox.m_Index)].m_SerialNumber != HIWORD(g_hActiveSkybox.m_Index)
    || g_pEntityList->m_EntPtrArray[LOWORD(g_hActiveSkybox.m_Index)].m_pEntity == nullptr )
  {
    if ( CEntityClassList<CSkyCamera>::m_pClassList == nullptr )
    {
      g_hActiveSkybox.m_Index = -1;
      return nullptr;
    }
    m_Index = CEntityClassList<CSkyCamera>::m_pClassList->GetRefEHandle(this: CEntityClassList<CSkyCamera>::m_pClassList)->m_Index;
    g_hActiveSkybox.m_Index = m_Index;
  }
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    return (CSkyCamera *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10214090
// Name: public: void CSkyCamera::InputActivateSkybox(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyCamera::InputActivateSkybox(CSkyCamera *this, inputdata_t *inputdata)
{
  if ( this != nullptr )
    g_hActiveSkybox.m_Index = this->GetRefEHandle(this)->m_Index;
  else
    g_hActiveSkybox.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102140C0
// Name: public: virtual void CSkyCamera::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyCamera::Spawn(CSkyCamera *this)
{
  CNetworkVectorBase<Vector,sky3dparams_t::NetworkVar_origin> *p_origin; // esi
  int v3; // ebx

  p_origin = &this->m_skyboxData.origin;
  if ( this->m_vecOrigin.m_Value.x != this->m_skyboxData.origin.m_Value.x
    || this->m_vecOrigin.m_Value.y != this->m_skyboxData.origin.m_Value.y
    || this->m_vecOrigin.m_Value.z != this->m_skyboxData.origin.m_Value.z )
  {
    this->m_skyboxData.NetworkStateChanged(this: &this->m_skyboxData, a2: p_origin);
    p_origin->m_Value.x = this->m_vecOrigin.m_Value.x;
    p_origin->m_Value.y = this->m_vecOrigin.m_Value.y;
    p_origin->m_Value.z = this->m_vecOrigin.m_Value.z;
  }
  v3 = engine->GetArea(this: engine, a2: (const Vector *)p_origin);
  if ( this->m_skyboxData.area.m_Value != v3 )
  {
    this->m_skyboxData.NetworkStateChanged(this: &this->m_skyboxData, a2: &this->m_skyboxData.area);
    this->m_skyboxData.area.m_Value = v3;
  }
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102141F0
// Name: public: CSkyCamera::CSkyCamera(void)
// Source: json
//------------------------------------------------------------------------------
CSkyCamera *__thiscall CSkyCamera::CSkyCamera(CSkyCamera *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CSkyCamera_vtbl *)&CSkyCamera::`vftable';
  this->m_skyboxData.__vftable = (sky3dparams_t_vtbl *)&sky3dparams_t::`vftable';
  this->m_skyboxData.fog.__vftable = (sky3dparams_t::NetworkVar_fog_vtbl *)&sky3dparams_t::NetworkVar_fog::`vftable';
  this->m_pNext = CEntityClassList<CSkyCamera>::m_pClassList;
  CEntityClassList<CSkyCamera>::m_pClassList = this;
  if ( this->m_skyboxData.fog.maxdensity.m_Value != 1.0 )
  {
    this->m_skyboxData.fog.NetworkStateChanged(this: &this->m_skyboxData.fog, a2: &this->m_skyboxData.fog.maxdensity);
    this->m_skyboxData.fog.maxdensity.m_Value = 1.0;
  }
  if ( this->m_skyboxData.fog.HDRColorScale.m_Value != 1.0 )
  {
    this->m_skyboxData.fog.NetworkStateChanged(this: &this->m_skyboxData.fog, a2: &this->m_skyboxData.fog.HDRColorScale);
    this->m_skyboxData.fog.HDRColorScale.m_Value = 1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10409E00
// Name: CSkyCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSkyCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSkyCamera>(__formal: nullptr);
  CSkyCamera_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10214170
// Name: struct datamap_t __near * DataMapInit<class CSkyCamera>(class CSkyCamera __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSkyCamera>()
{
  if ( (_S2_202 & 1) == 0 )
  {
    _S2_202 |= 1u;
    nameHolder_385.m_pszBase = "CSkyCamera";
    nameHolder_385.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_385.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_385.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_385.m_Names.m_Size = 0;
    nameHolder_385.m_Names.m_pElements = nullptr;
    nameHolder_385.m_nLenBase = 10;
    atexit(func: DataMapInit_CSkyCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSkyCamera::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSkyCamera::m_DataMap.dataNumFields = 14;
  CSkyCamera::m_DataMap.dataDesc = &dataDesc_368[1];
  return &CSkyCamera::m_DataMap;
}
