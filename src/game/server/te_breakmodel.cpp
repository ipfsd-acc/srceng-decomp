// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_breakmodel.cpp
// Functions: 10
// ============================================================

#include "game\server\te_breakmodel.h"

//------------------------------------------------------------------------------
// Address: 0x1032EC20
// Name: public: virtual class ServerClass __near * CTEBreakModel::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBreakModel::GetServerClass(CTEBreakModel *this)
{
  return &g_CTEBreakModel_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032EED0
// Name: public: CTEBreakModel::CTEBreakModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEBreakModel *__thiscall CTEBreakModel::CTEBreakModel(CTEBreakModel *this, const char *name)
{
  CTEBreakModel *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEBreakModel_vtbl *)&CTEBreakModel::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_vecSize.m_Value.x != 0.0 || this->m_vecSize.m_Value.y != 0.0 || this->m_vecSize.m_Value.z != 0.0 )
  {
    this->m_vecSize.m_Value.x = 0.0;
    this->m_vecSize.m_Value.y = 0.0;
    this->m_vecSize.m_Value.z = 0.0;
  }
  if ( this->m_vecVelocity.m_Value.x != 0.0
    || this->m_vecVelocity.m_Value.y != 0.0
    || this->m_vecVelocity.m_Value.z != 0.0 )
  {
    this->m_vecVelocity.m_Value.x = 0.0;
    this->m_vecVelocity.m_Value.y = 0.0;
    this->m_vecVelocity.m_Value.z = 0.0;
  }
  if ( this->m_angRotation.m_Value.x != 0.0
    || this->m_angRotation.m_Value.y != 0.0
    || this->m_angRotation.m_Value.z != 0.0 )
  {
    this->m_angRotation.m_Value.x = 0.0;
    this->m_angRotation.m_Value.y = 0.0;
    this->m_angRotation.m_Value.z = 0.0;
  }
  if ( this->m_nModelIndex.m_Value != 0 )
    this->m_nModelIndex.m_Value = 0;
  if ( this->m_nRandomization.m_Value != 0 )
    this->m_nRandomization.m_Value = 0;
  if ( this->m_nCount.m_Value != 0 )
    this->m_nCount.m_Value = 0;
  if ( this->m_fTime.m_Value != 0.0 )
    this->m_fTime.m_Value = 0.0;
  result = this;
  if ( this->m_nFlags.m_Value != 0 )
    this->m_nFlags.m_Value = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1032F000
// Name: void TE_BreakModel(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BreakModel(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBreakModel::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<QAngle,CTEBreakModel::NetworkVar_m_angRotation> *angles,
        CNetworkVectorBase<Vector,CTEBreakModel::NetworkVar_m_vecSize> *size,
        CNetworkVectorBase<Vector,CTEBreakModel::NetworkVar_m_vecVelocity> *vel,
        int modelindex,
        int randomization,
        int count,
        float time,
        int flags)
{
  if ( pos->m_Value.x != g_TEBreakModel.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEBreakModel.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEBreakModel.m_vecOrigin.m_Value.z )
  {
    g_TEBreakModel.m_vecOrigin = *pos;
  }
  if ( angles->m_Value.x != g_TEBreakModel.m_angRotation.m_Value.x
    || angles->m_Value.y != g_TEBreakModel.m_angRotation.m_Value.y
    || angles->m_Value.z != g_TEBreakModel.m_angRotation.m_Value.z )
  {
    g_TEBreakModel.m_angRotation = *angles;
  }
  if ( size->m_Value.x != g_TEBreakModel.m_vecSize.m_Value.x
    || size->m_Value.y != g_TEBreakModel.m_vecSize.m_Value.y
    || size->m_Value.z != g_TEBreakModel.m_vecSize.m_Value.z )
  {
    g_TEBreakModel.m_vecSize = *size;
  }
  if ( vel->m_Value.x != g_TEBreakModel.m_vecVelocity.m_Value.x
    || vel->m_Value.y != g_TEBreakModel.m_vecVelocity.m_Value.y
    || vel->m_Value.z != g_TEBreakModel.m_vecVelocity.m_Value.z )
  {
    g_TEBreakModel.m_vecVelocity = *vel;
  }
  if ( g_TEBreakModel.m_nModelIndex.m_Value != modelindex )
    g_TEBreakModel.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBreakModel.m_nRandomization.m_Value != randomization )
    g_TEBreakModel.m_nRandomization.m_Value = randomization;
  if ( g_TEBreakModel.m_nCount.m_Value != count )
    g_TEBreakModel.m_nCount.m_Value = count;
  if ( g_TEBreakModel.m_fTime.m_Value != time )
    g_TEBreakModel.m_fTime.m_Value = time;
  if ( g_TEBreakModel.m_nFlags.m_Value != flags )
    g_TEBreakModel.m_nFlags.m_Value = flags;
  CBaseTempEntity::Create(this: &g_TEBreakModel, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104163C0
// Name: DT_TEBreakModel::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBreakModel::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBreakModel::g_SendTable);
  return atexit(func: DT_TEBreakModel::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104163E0
// Name: DT_TEBreakModel::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBreakModel::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBreakModel::ignored>();
  DT_TEBreakModel::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422190
// Name: DT_TEBreakModel::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBreakModel::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBreakModel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104163F0
// Name: _dynamic_initializer_for__g_TEBreakModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBreakModel__()
{
  CTEBreakModel::CTEBreakModel(this: &g_TEBreakModel, name: "breakmodel");
  return atexit(func: dynamic_atexit_destructor_for__g_TEBreakModel__);
}

//------------------------------------------------------------------------------
// Address: 0x10416410
// Name: _dynamic_initializer_for__g_CTEBSPDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBSPDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBSPDecal_ClassReg,
           pNetworkName: "CTEBSPDecal",
           pTable: &DT_TEBSPDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104221A0
// Name: _dynamic_atexit_destructor_for__g_TEBreakModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBreakModel__()
{
  g_TEBreakModel.__vftable = (CTEBreakModel_vtbl *)&CTEBreakModel::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBreakModel);
}

//------------------------------------------------------------------------------
// Address: 0x104221C0
// Name: _ServerClassInit_DT_TEBreakModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBreakModel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_333;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
