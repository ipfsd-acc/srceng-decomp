// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_lod.cpp
// Functions: 12
// ============================================================

#include "game\server\func_lod.h"

//------------------------------------------------------------------------------
// Address: 0x101317F0
// Name: public: virtual bool CFunc_LOD::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CFunc_LOD::CreateVPhysics@<al>(CFuncVPhysicsClip *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity::VPhysicsInitStatic(this, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013B840
// Name: public: virtual class ServerClass __near * CFunc_LOD::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFunc_LOD::GetServerClass(CFunc_LOD *this)
{
  return &g_CFunc_LOD_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013B850
// Name: private: virtual struct datamap_t __near * CFunc_LOD::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFunc_LOD::GetDataDescMap(CFunc_LOD *this)
{
  return &CFunc_LOD::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013B890
// Name: public: virtual void CFunc_LOD::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunc_LOD::Spawn(CFunc_LOD *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = *(const char **)((int (__thiscall *)(CFunc_LOD *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->CreateVPhysics(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013B9F0
// Name: public: virtual bool CFunc_LOD::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFunc_LOD::KeyValue(CFunc_LOD *this, char *szKeyName, const char *szValue)
{
  int v4; // ebx
  edict_t *m_pPev; // ecx
  int v6; // esi
  edict_t *v8; // ecx

  if ( szKeyName != "DisappearDist" && _V_stricmp(s1: szKeyName, s2: "DisappearDist") != 0 )
  {
    if ( szKeyName != "Solid" && _V_stricmp(s1: szKeyName, s2: "Solid") != 0 )
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    if ( atoi(nptr: szValue) != 0 )
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    return true;
  }
  v4 = atoi(nptr: szValue);
  if ( this->m_nDisappearMinDist.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_nDisappearMinDist.m_Value = v4;
  }
  v6 = this->m_nDisappearMinDist.m_Value + 800;
  if ( this->m_nDisappearMaxDist.m_Value == v6 )
    return true;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_nDisappearMaxDist.m_Value = v6;
    return true;
  }
  else
  {
    v8 = this->m_Network.m_pPev;
    if ( v8 != nullptr )
      CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x358u);
    this->m_nDisappearMaxDist.m_Value = v6;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10403F70
// Name: DT_Func_LOD::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_LOD::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Func_LOD::g_SendTable);
  return atexit(func: DT_Func_LOD::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403F90
// Name: DT_Func_LOD::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_LOD::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Func_LOD::ignored>();
  DT_Func_LOD::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403FC0
// Name: CFunc_LOD_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFunc_LOD_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFunc_LOD>(__formal: nullptr);
  CFunc_LOD_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B840
// Name: DT_Func_LOD::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Func_LOD::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Func_LOD::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1013BB10
// Name: struct datamap_t __near * DataMapInit<class CFunc_LOD>(class CFunc_LOD __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFunc_LOD>()
{
  if ( (_S3_65 & 1) == 0 )
  {
    _S3_65 |= 1u;
    nameHolder_218.m_pszBase = "CFunc_LOD";
    nameHolder_218.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_218.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_218.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_218.m_Names.m_Size = 0;
    nameHolder_218.m_Names.m_pElements = nullptr;
    nameHolder_218.m_nLenBase = 9;
    atexit(func: DataMapInit_CFunc_LOD__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFunc_LOD::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFunc_LOD::m_DataMap.dataNumFields = 2;
  CFunc_LOD::m_DataMap.dataDesc = &dataDesc_207[1];
  return &CFunc_LOD::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041B850
// Name: _ServerClassInit_DT_Func_LOD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Func_LOD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_119;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B870
// Name: _DataMapInit_CFunc_LOD__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFunc_LOD__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_218);
}
