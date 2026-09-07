// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_clientprojectile.cpp
// Functions: 11
// ============================================================

#include "game\server\te_clientprojectile.h"

//------------------------------------------------------------------------------
// Address: 0x1032FF30
// Name: public: virtual class ServerClass __near * CTEClientProjectile::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEClientProjectile::GetServerClass(CTEClientProjectile *this)
{
  return &g_CTEClientProjectile_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103300D0
// Name: public: CTEClientProjectile::CTEClientProjectile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEClientProjectile *__thiscall CTEClientProjectile::CTEClientProjectile(CTEClientProjectile *this, const char *name)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  CTEClientProjectile *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEClientProjectile_vtbl *)&CTEClientProjectile::`vftable';
  this->m_hOwner.m_Value.m_Index = -1;
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_vecVelocity.m_Value.x != 0.0
    || this->m_vecVelocity.m_Value.y != 0.0
    || this->m_vecVelocity.m_Value.z != 0.0 )
  {
    this->m_vecVelocity.m_Value.x = 0.0;
    this->m_vecVelocity.m_Value.y = 0.0;
    this->m_vecVelocity.m_Value.z = 0.0;
  }
  if ( this->m_nModelIndex.m_Value != 0 )
    this->m_nModelIndex.m_Value = 0;
  if ( this->m_nLifeTime.m_Value != 0 )
    this->m_nLifeTime.m_Value = 0;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 )
    return this;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return this;
  result = this;
  if ( v4->m_pEntity != nullptr )
    this->m_hOwner.m_Value.m_Index = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103301A0
// Name: public: virtual void CTEClientProjectile::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEClientProjectile::Test(
        CTEClientProjectile *this,
        CNetworkVectorBase<Vector,CTEClientProjectile::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  unsigned int m_Index; // eax
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( current_origin->m_Value.x != this->m_vecOrigin.m_Value.x
    || current_origin->m_Value.y != this->m_vecOrigin.m_Value.y
    || current_origin->m_Value.z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin = *current_origin;
  }
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  v4 = forward.y * 2048.0;
  v5 = forward.z * 2048.0;
  if ( (float)(forward.x * 2048.0) != this->m_vecVelocity.m_Value.x
    || v4 != this->m_vecVelocity.m_Value.y
    || v5 != this->m_vecVelocity.m_Value.z )
  {
    this->m_vecVelocity.m_Value.x = forward.x * 2048.0;
    this->m_vecVelocity.m_Value.y = v4;
    this->m_vecVelocity.m_Value.z = v5;
  }
  if ( this->m_nLifeTime.m_Value != 5 )
    this->m_nLifeTime.m_Value = 5;
  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->m_hOwner.m_Value.m_Index = -1;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEClientProjectile *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x103302E0
// Name: void TE_ClientProjectile(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ClientProjectile(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEClientProjectile::NetworkVar_m_vecOrigin> *vecOrigin,
        CNetworkVectorBase<Vector,CTEClientProjectile::NetworkVar_m_vecVelocity> *vecVelocity,
        int modelindex,
        int lifetime,
        CBaseEntity *pOwner)
{
  CBaseEntity *m_pEntity; // eax

  if ( vecOrigin->m_Value.x != g_TEClientProjectile.m_vecOrigin.m_Value.x
    || vecOrigin->m_Value.y != g_TEClientProjectile.m_vecOrigin.m_Value.y
    || vecOrigin->m_Value.z != g_TEClientProjectile.m_vecOrigin.m_Value.z )
  {
    g_TEClientProjectile.m_vecOrigin = *vecOrigin;
  }
  if ( vecVelocity->m_Value.x != g_TEClientProjectile.m_vecVelocity.m_Value.x
    || vecVelocity->m_Value.y != g_TEClientProjectile.m_vecVelocity.m_Value.y
    || vecVelocity->m_Value.z != g_TEClientProjectile.m_vecVelocity.m_Value.z )
  {
    g_TEClientProjectile.m_vecVelocity = *vecVelocity;
  }
  if ( g_TEClientProjectile.m_nModelIndex.m_Value != modelindex )
    g_TEClientProjectile.m_nModelIndex.m_Value = modelindex;
  if ( g_TEClientProjectile.m_nLifeTime.m_Value != lifetime )
    g_TEClientProjectile.m_nLifeTime.m_Value = lifetime;
  if ( g_TEClientProjectile.m_hOwner.m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(g_TEClientProjectile.m_hOwner.m_Value.m_Index)].m_SerialNumber != HIWORD(g_TEClientProjectile.m_hOwner.m_Value.m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_TEClientProjectile.m_hOwner.m_Value.m_Index)].m_pEntity;
  }
  if ( m_pEntity != pOwner )
  {
    if ( pOwner != nullptr )
      g_TEClientProjectile.m_hOwner.m_Value.m_Index = *(_DWORD *)((int (*)(void))pOwner->GetRefEHandle)();
    else
      g_TEClientProjectile.m_hOwner.m_Value.m_Index = -1;
  }
  CBaseTempEntity::Create(this: &g_TEClientProjectile, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104167B0
// Name: DT_TEClientProjectile::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEClientProjectile::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEClientProjectile::g_SendTable);
  return atexit(func: DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104167D0
// Name: DT_TEClientProjectile::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEClientProjectile::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEClientProjectile::ignored>();
  DT_TEClientProjectile::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104222D0
// Name: DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEClientProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104167E0
// Name: _dynamic_initializer_for__g_TEClientProjectile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEClientProjectile__()
{
  CTEClientProjectile::CTEClientProjectile(this: &g_TEClientProjectile, name: "Client Projectile");
  return atexit(func: dynamic_atexit_destructor_for__g_TEClientProjectile__);
}

//------------------------------------------------------------------------------
// Address: 0x10416800
// Name: _dynamic_initializer_for__g_CTEDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEDecal_ClassReg,
           pNetworkName: "CTEDecal",
           pTable: &DT_TEDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104222E0
// Name: _dynamic_atexit_destructor_for__g_TEClientProjectile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEClientProjectile__()
{
  g_TEClientProjectile.__vftable = (CTEClientProjectile_vtbl *)&CTEClientProjectile::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEClientProjectile);
}

//------------------------------------------------------------------------------
// Address: 0x10422300
// Name: _ServerClassInit_DT_TEClientProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEClientProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_337;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
