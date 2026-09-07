// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_sparks.cpp
// Functions: 12
// ============================================================

#include "game\server\te_sparks.h"

//------------------------------------------------------------------------------
// Address: 0x10334A00
// Name: public: virtual class ServerClass __near * CTESparks::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTESparks::GetServerClass(CTESparks *this)
{
  return &g_CTESparks_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10334B40
// Name: public: virtual void CTESparks::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTESparks::Test(CTESparks *this, const Vector *current_origin, const QAngle *current_angles)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( this->m_vecOrigin.m_Value.x != current_origin->x )
    this->m_vecOrigin.m_Value.x = current_origin->x;
  y = current_origin->y;
  if ( this->m_vecOrigin.m_Value.y != y )
    this->m_vecOrigin.m_Value.y = y;
  z = current_origin->z;
  if ( this->m_vecOrigin.m_Value.z != z )
    this->m_vecOrigin.m_Value.z = z;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  v6 = (float)(forward.x * 100.0) + this->m_vecOrigin.m_Value.x;
  v7 = this->m_vecOrigin.m_Value.y + (float)(forward.y * 100.0);
  v8 = this->m_vecOrigin.m_Value.z + (float)(forward.z * 100.0);
  if ( this->m_vecOrigin.m_Value.x != v6 )
    this->m_vecOrigin.m_Value.x = v6;
  if ( this->m_vecOrigin.m_Value.y != v7 )
    this->m_vecOrigin.m_Value.y = v7;
  if ( this->m_vecOrigin.m_Value.z != v8 )
    this->m_vecOrigin.m_Value.z = v8;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTESparks *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10334C80
// Name: void TE_Sparks(class IRecipientFilter __near &,float,class Vector const __near *,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Sparks(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        int nMagnitude,
        int nTrailLength,
        CNetworkVectorBase<Vector,CTESparks::NetworkVar_m_vecDir> *pDir)
{
  if ( g_TESparks.m_vecOrigin.m_Value.x != pos->x )
    g_TESparks.m_vecOrigin.m_Value.x = pos->x;
  if ( g_TESparks.m_vecOrigin.m_Value.y != pos->y )
    g_TESparks.m_vecOrigin.m_Value.y = pos->y;
  if ( g_TESparks.m_vecOrigin.m_Value.z != pos->z )
    g_TESparks.m_vecOrigin.m_Value.z = pos->z;
  if ( g_TESparks.m_nMagnitude.m_Value != nMagnitude )
    g_TESparks.m_nMagnitude.m_Value = nMagnitude;
  if ( g_TESparks.m_nTrailLength.m_Value != nTrailLength )
    g_TESparks.m_nTrailLength.m_Value = nTrailLength;
  if ( pDir != nullptr )
  {
    if ( pDir->m_Value.x != g_TESparks.m_vecDir.m_Value.x
      || pDir->m_Value.y != g_TESparks.m_vecDir.m_Value.y
      || pDir->m_Value.z != g_TESparks.m_vecDir.m_Value.z )
    {
      g_TESparks.m_vecDir = *pDir;
    }
  }
  else if ( vec3_origin.x != g_TESparks.m_vecDir.m_Value.x
         || vec3_origin.y != g_TESparks.m_vecDir.m_Value.y
         || vec3_origin.z != g_TESparks.m_vecDir.m_Value.z )
  {
    g_TESparks.m_vecDir.m_Value = vec3_origin;
  }
  CBaseTempEntity::Create(this: &g_TESparks, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10402FA0
// Name: _dynamic_initializer_for__spark_shower__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spark_shower__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CShower> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &spark_shower,
           a3: "spark_shower");
}

//------------------------------------------------------------------------------
// Address: 0x10417830
// Name: DT_TESparks::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESparks::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TESparks::g_SendTable);
  return atexit(func: DT_TESparks::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417850
// Name: DT_TESparks::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESparks::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TESparks::ignored>();
  DT_TESparks::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422930
// Name: DT_TESparks::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESparks::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TESparks::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10402FC0
// Name: _dynamic_initializer_for__env_explosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_explosion__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CEnvExplosion> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_explosion,
           a3: "env_explosion");
}

//------------------------------------------------------------------------------
// Address: 0x10417860
// Name: _dynamic_initializer_for__g_TESparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TESparks__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TESparks, name: "Sparks");
  g_TESparks.m_vecOrigin.m_Value.x = 0.0;
  g_TESparks.m_vecOrigin.m_Value.y = 0.0;
  g_TESparks.m_vecOrigin.m_Value.z = 0.0;
  g_TESparks.__vftable = (CTESparks_vtbl *)&CTESparks::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TESparks__);
}

//------------------------------------------------------------------------------
// Address: 0x104178A0
// Name: _dynamic_initializer_for__g_CTESprite_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTESprite_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTESprite_ClassReg,
           pNetworkName: "CTESprite",
           pTable: &DT_TESprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422940
// Name: _dynamic_atexit_destructor_for__g_TESparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESparks__()
{
  g_TESparks.__vftable = (CTESparks_vtbl *)&CTESparks::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TESparks);
}

//------------------------------------------------------------------------------
// Address: 0x10422960
// Name: _ServerClassInit_DT_TESparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TESparks::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_358;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
