// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/compiledcaptionswap.cpp
// Functions: 7
// ============================================================

#include "common\compiledcaptionswap.h"

//------------------------------------------------------------------------------
// Address: 0x0041C740
// Name: bool SwapClosecaptionFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SwapClosecaptionFile(_DWORD *pData)
{
  int v1; // ebx
  char *i; // esi
  CByteswap swap; // [esp+8h] [ebp-4h] BYREF

  swap = (CByteswap)(*(_DWORD *)&swap | 3);
  if ( *pData != 1145258838 || pData[1] != 1 )
    return 0;
  v1 = pData[4];
  for ( i = (char *)(pData + 6); v1 != 0; --v1 )
  {
    CByteswap::SwapFieldsToTargetEndian(
      this: &swap,
      pOutputBuffer: i,
      pBaseData: i,
      pDataMap: &CaptionLookup_t::m_DataMap);
    i += 12;
  }
  CByteswap::SwapBufferToTargetEndian<unsigned short>(
    this: &swap,
    outputBuffer: (unsigned __int8 *)pData + pData[5],
    inputBuffer: (unsigned __int8 *)pData + pData[5],
    count: (unsigned int)(pData[2] * pData[3]) >> 1);
  CByteswap::SwapFieldsToTargetEndian(
    this: &swap,
    pOutputBuffer: pData,
    pBaseData: pData,
    pDataMap: &CompiledCaptionHeader_t::m_DataMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C7C0
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00589D20
// Name: CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CompiledCaptionHeader_t>(__formal: nullptr);
  CompiledCaptionHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00589D30
// Name: CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CaptionLookup_t>(__formal: nullptr);
  CaptionLookup_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C840
// Name: struct datamap_t __near * DataMapInit<struct CompiledCaptionHeader_t>(struct CompiledCaptionHeader_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CompiledCaptionHeader_t>()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    nameHolder.m_pszBase = "CompiledCaptionHeader_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 23;
    atexit(func: DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CompiledCaptionHeader_t::m_DataMap.baseMap = nullptr;
  CompiledCaptionHeader_t::m_DataMap.dataNumFields = 6;
  CompiledCaptionHeader_t::m_DataMap.dataDesc = &dataDesc[1];
  return &CompiledCaptionHeader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x0041C8C0
// Name: struct datamap_t __near * DataMapInit<struct CaptionLookup_t>(struct CaptionLookup_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CaptionLookup_t>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder_0.m_pszBase = "CaptionLookup_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 15;
    atexit(func: DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CaptionLookup_t::m_DataMap.baseMap = nullptr;
  CaptionLookup_t::m_DataMap.dataNumFields = 4;
  CaptionLookup_t::m_DataMap.dataDesc = &dataDesc_0[1];
  return &CaptionLookup_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x00589D40
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10415190
// Name: CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CompiledCaptionHeader_t>();
  CompiledCaptionHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104151A0
// Name: CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CaptionLookup_t>();
  CaptionLookup_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104151B0
// Name: _dynamic_initializer_for__g_CConVarFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CConVarFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, ConVarRef *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "ConVar",
           a3: CCConVarMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x104151D0
// Name: _dynamic_initializer_for__g_CCycleFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CCycleFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Cycle",
           a3: CCCycleMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x104151F0
// Name: _dynamic_initializer_for__g_DecalSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DecalSystem__()
{
  CDecalEmitterSystem::CDecalEmitterSystem(this: &g_DecalSystem, name: "CDecalEmitterSystem");
  return atexit(func: dynamic_atexit_destructor_for__g_DecalSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10415210
// Name: _dynamic_initializer_for__cl_detail_max_sway__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detail_max_sway__()
{
  ConVar::ConVar(
    this: &cl_detail_max_sway,
    pName: "cl_detail_max_sway",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Amplitude of the detail prop sway");
  return atexit(func: dynamic_atexit_destructor_for__cl_detail_max_sway__);
}

//------------------------------------------------------------------------------
// Address: 0x10415240
// Name: _dynamic_initializer_for__cl_detail_avoid_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detail_avoid_radius__()
{
  ConVar::ConVar(
    this: &cl_detail_avoid_radius,
    pName: "cl_detail_avoid_radius",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "radius around detail sprite to avoid players");
  return atexit(func: dynamic_atexit_destructor_for__cl_detail_avoid_radius__);
}

//------------------------------------------------------------------------------
// Address: 0x10415270
// Name: _dynamic_initializer_for__cl_detail_avoid_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detail_avoid_force__()
{
  ConVar::ConVar(
    this: &cl_detail_avoid_force,
    pName: "cl_detail_avoid_force",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "force with which to avoid players ( in units, percentage of the width of the detail sprite )");
  return atexit(func: dynamic_atexit_destructor_for__cl_detail_avoid_force__);
}

//------------------------------------------------------------------------------
// Address: 0x104152A0
// Name: _dynamic_initializer_for__cl_detail_avoid_recover_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detail_avoid_recover_speed__()
{
  ConVar::ConVar(
    this: &cl_detail_avoid_recover_speed,
    pName: "cl_detail_avoid_recover_speed",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "how fast to recover position after avoiding players");
  return atexit(func: dynamic_atexit_destructor_for__cl_detail_avoid_recover_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x104152D0
// Name: _dynamic_initializer_for__r_FlashlightDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_FlashlightDetailProps__()
{
  ConVar::ConVar(
    this: &r_FlashlightDetailProps,
    pName: "r_FlashlightDetailProps",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable a flashlight drawing pass on detail props. 0 = off, 1 = single pass, 2 = multipass (multipass is PC ONLY)");
  return atexit(func: dynamic_atexit_destructor_for__r_FlashlightDetailProps__);
}

//------------------------------------------------------------------------------
// Address: 0x10415300
// Name: _dynamic_initializer_for__r_ThreadedDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_ThreadedDetailProps__()
{
  ConVar::ConVar(
    this: &r_ThreadedDetailProps,
    pName: "r_threadeddetailprops",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "enable threading of detail prop drawing");
  return atexit(func: dynamic_atexit_destructor_for__r_ThreadedDetailProps__);
}

//------------------------------------------------------------------------------
// Address: 0x10415330
// Name: _dynamic_initializer_for__mat_fullbright___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_fullbright___0()
{
  ConVar::ConVar(this: &mat_fullbright_0, pName: "mat_fullbright", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_fullbright___0);
}

//------------------------------------------------------------------------------
// Address: 0x10415360
// Name: _dynamic_initializer_for__s_DetailObjectSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailObjectSystem__()
{
  CDetailObjectSystem::CDetailObjectSystem(this: &s_DetailObjectSystem);
  return atexit(func: dynamic_atexit_destructor_for__s_DetailObjectSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10415380
// Name: _dynamic_initializer_for__cl_detaildist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detaildist__()
{
  ConVar::ConVar(
    this: &cl_detaildist,
    pName: "cl_detaildist",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Distance at which detail props are no longer visible",
    callback: (void (__cdecl *)(IConVar *, const char *, float))DetailFadeCallback);
  return atexit(func: dynamic_atexit_destructor_for__cl_detaildist__);
}

//------------------------------------------------------------------------------
// Address: 0x104153B0
// Name: _dynamic_initializer_for__cl_detailfade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_detailfade__()
{
  ConVar::ConVar(
    this: &cl_detailfade,
    pName: "cl_detailfade",
    pDefaultValue: "400",
    flags: 0,
    pHelpString: "Distance across which detail props fade in",
    callback: (void (__cdecl *)(IConVar *, const char *, float))DetailFadeCallback);
  return atexit(func: dynamic_atexit_destructor_for__cl_detailfade__);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10401700
// Name: CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CompiledCaptionHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CompiledCaptionHeader_t>();
  CompiledCaptionHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401710
// Name: CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CaptionLookup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CaptionLookup_t>();
  CaptionLookup_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

} // namespace server
