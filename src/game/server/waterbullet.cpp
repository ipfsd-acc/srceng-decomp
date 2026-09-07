// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/waterbullet.cpp
// Functions: 14
// ============================================================

#include "game\server\waterbullet.h"

//------------------------------------------------------------------------------
// Address: 0x10263530
// Name: public: virtual struct datamap_t __near * CWaterBullet::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWaterBullet::GetDataDescMap(CWaterBullet *this)
{
  return &CWaterBullet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10263540
// Name: public: virtual class ServerClass __near * CWaterBullet::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWaterBullet::GetServerClass(CWaterBullet *this)
{
  return &g_CWaterBullet_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10263550
// Name: public: virtual void CWaterBullet::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWaterBullet::Precache(CWaterBullet *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_bullet.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10263570
// Name: public: void CWaterBullet::BulletThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaterBullet::BulletThink(CWaterBullet *this)
{
  float thinkTime; // [esp+0h] [ebp-24h]
  Vector vecAbsVelocity; // [esp+Ch] [ebp-18h] BYREF
  Vector forward; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  thinkTime = gpGlobals->curtime + 0.05;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, &forward);
  vecAbsVelocity.x = forward.x * 1500.0;
  vecAbsVelocity.y = forward.y * 1500.0;
  vecAbsVelocity.z = forward.z * 1500.0;
  CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x10263690
// Name: public: virtual void CWaterBullet::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaterBullet::Touch(CWaterBullet *this, CBaseEntity *pOther)
{
  float z; // ecx
  float x; // xmm2_4
  float y; // xmm1_4
  float v6; // xmm0_4
  unsigned int v7; // eax
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  int m_iEFlags; // ecx
  float v12; // xmm6_4
  CGameTrace tr; // [esp+4h] [ebp-88h] BYREF
  Vector vecStart; // [esp+58h] [ebp-34h] BYREF
  Vector vecEnd; // [esp+64h] [ebp-28h] BYREF
  float speed; // [esp+70h] [ebp-1Ch]
  Vector vecDir; // [esp+74h] [ebp-18h] BYREF
  float v18; // [esp+80h] [ebp-Ch]
  float v19; // [esp+84h] [ebp-8h]
  float v20; // [esp+88h] [ebp-4h]
  int savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecDir.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
  vecDir.z = z;
  speed = VectorNormalize(vec: &vecDir);
  x = vecDir.x;
  y = vecDir.y;
  v6 = vecDir.z;
  v7 = (unsigned int)this->m_iEFlags >> 11;
  v8 = vecDir.x * 8.0;
  v9 = vecDir.y * 8.0;
  v10 = vecDir.z * 8.0;
  v18 = vecDir.x * 8.0;
  v19 = vecDir.y * 8.0;
  v20 = vecDir.z * 8.0;
  if ( (v7 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v6 = vecDir.z;
    y = vecDir.y;
    x = vecDir.x;
    v10 = v20;
    v9 = v19;
    v8 = v18;
  }
  m_iEFlags = this->m_iEFlags;
  v12 = this->m_vecAbsOrigin.x - v8;
  vecStart.y = this->m_vecAbsOrigin.y - v9;
  vecStart.z = this->m_vecAbsOrigin.z - v10;
  vecStart.x = v12;
  v18 = x * speed;
  v19 = y * speed;
  v20 = v6 * speed;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  vecEnd.x = this->m_vecAbsOrigin.x + v18;
  vecEnd.y = this->m_vecAbsOrigin.y + v19;
  vecEnd.z = this->m_vecAbsOrigin.z + v20;
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)this,
    vecAbsStart: &vecStart,
    vecAbsEnd: &vecEnd,
    mask: 0x46004003u,
    pFilter: nullptr,
    ptr: &tr);
  UTIL_ImpactTrace(pTrace: &tr, iDamageType: 2, pCustomImpactName: nullptr);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1040CD60
// Name: CWaterBullet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWaterBullet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWaterBullet>();
  CWaterBullet_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CD70
// Name: _dynamic_initializer_for__waterbullet__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__waterbullet__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWaterBullet> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &waterbullet,
           a3: "waterbullet");
}

//------------------------------------------------------------------------------
// Address: 0x1040CDB0
// Name: DT_WaterBullet::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterBullet::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WaterBullet::g_SendTable);
  return atexit(func: DT_WaterBullet::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040CDD0
// Name: DT_WaterBullet::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WaterBullet::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WaterBullet::ignored>();
  DT_WaterBullet::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040CDE0
// Name: _dynamic_initializer_for__water_lod_control__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__water_lod_control__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWaterLODControl> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &water_lod_control,
           a3: "water_lod_control");
}

//------------------------------------------------------------------------------
// Address: 0x1041F1B0
// Name: DT_WaterBullet::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WaterBullet::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WaterBullet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040CD90
// Name: _dynamic_initializer_for__g_CWaterBullet_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWaterBullet_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWaterBullet_ClassReg,
           pNetworkName: "CWaterBullet",
           pTable: &DT_WaterBullet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041F1C0
// Name: _ServerClassInit_DT_WaterBullet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WaterBullet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_141;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041F1E0
// Name: _DataMapInit_CWaterBullet__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWaterBullet__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_463);
}
