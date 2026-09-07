// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_footprintdecal.cpp
// Functions: 9
// ============================================================

#include "game\server\te_footprintdecal.h"

//------------------------------------------------------------------------------
// Address: 0x10331BC0
// Name: public: virtual class ServerClass __near * CTEFootprintDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEFootprintDecal::GetServerClass(CTEFootprintDecal *this)
{
  return &g_CTEFootprintDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10331D60
// Name: void TE_FootprintDecal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_FootprintDecal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEFootprintDecal::NetworkVar_m_vecOrigin> *origin,
        CNetworkVectorBase<Vector,CTEFootprintDecal::NetworkVar_m_vecDirection> *right,
        int entity,
        int index,
        unsigned __int8 materialType)
{
  if ( origin->m_Value.x != g_TEFootprintDecal.m_vecOrigin.m_Value.x
    || origin->m_Value.y != g_TEFootprintDecal.m_vecOrigin.m_Value.y
    || origin->m_Value.z != g_TEFootprintDecal.m_vecOrigin.m_Value.z )
  {
    g_TEFootprintDecal.m_vecOrigin = *origin;
  }
  if ( right->m_Value.x != g_TEFootprintDecal.m_vecDirection.m_Value.x
    || right->m_Value.y != g_TEFootprintDecal.m_vecDirection.m_Value.y
    || right->m_Value.z != g_TEFootprintDecal.m_vecDirection.m_Value.z )
  {
    g_TEFootprintDecal.m_vecDirection = *right;
  }
  if ( g_TEFootprintDecal.m_nEntity.m_Value != entity )
    g_TEFootprintDecal.m_nEntity.m_Value = entity;
  if ( g_TEFootprintDecal.m_nIndex.m_Value != index )
    g_TEFootprintDecal.m_nIndex.m_Value = index;
  if ( g_TEFootprintDecal.m_chMaterialType.m_Value != materialType )
    g_TEFootprintDecal.m_chMaterialType.m_Value = materialType;
  VectorNormalize(vec: &g_TEFootprintDecal.m_vecDirection.m_Value);
  CBaseTempEntity::Create(this: &g_TEFootprintDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416CD0
// Name: DT_TEFootprintDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFootprintDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEFootprintDecal::g_SendTable);
  return atexit(func: DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416CF0
// Name: DT_TEFootprintDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFootprintDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEFootprintDecal::ignored>();
  DT_TEFootprintDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422500
// Name: DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFootprintDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEFootprintDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416D00
// Name: _dynamic_initializer_for__g_TEFootprintDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEFootprintDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEFootprintDecal, name: "Footprint Decal");
  g_TEFootprintDecal.__vftable = (CTEFootprintDecal_vtbl *)&CTEFootprintDecal::`vftable';
  if ( g_TEFootprintDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEFootprintDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEFootprintDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEFootprintDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEFootprintDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEFootprintDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEFootprintDecal.m_nEntity.m_Value != 0 )
    g_TEFootprintDecal.m_nEntity.m_Value = 0;
  if ( g_TEFootprintDecal.m_nIndex.m_Value != 0 )
    g_TEFootprintDecal.m_nIndex.m_Value = 0;
  if ( g_TEFootprintDecal.m_chMaterialType.m_Value != 67 )
    g_TEFootprintDecal.m_chMaterialType.m_Value = 67;
  return atexit(func: dynamic_atexit_destructor_for__g_TEFootprintDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x10416DA0
// Name: _dynamic_initializer_for__g_CTEGaussExplosion_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEGaussExplosion_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEGaussExplosion_ClassReg,
           pNetworkName: "CTEGaussExplosion",
           pTable: &DT_TEGaussExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422510
// Name: _ServerClassInit_DT_TEFootprintDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEFootprintDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_344;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10422530
// Name: _dynamic_atexit_destructor_for__g_TEFootprintDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEFootprintDecal__()
{
  g_TEFootprintDecal.__vftable = (CTEFootprintDecal_vtbl *)&CTEFootprintDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEFootprintDecal);
}
