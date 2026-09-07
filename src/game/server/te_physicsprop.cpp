// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_physicsprop.cpp
// Functions: 10
// ============================================================

#include "game\server\te_physicsprop.h"

//------------------------------------------------------------------------------
// Address: 0x103335F0
// Name: public: virtual class ServerClass __near * CTEPhysicsProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEPhysicsProp::GetServerClass(CTEPhysicsProp *this)
{
  return &g_CTEPhysicsProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10333840
// Name: public: CTEPhysicsProp::CTEPhysicsProp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEPhysicsProp *__thiscall CTEPhysicsProp::CTEPhysicsProp(CTEPhysicsProp *this, const char *name)
{
  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEPhysicsProp_vtbl *)&CTEPhysicsProp::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_angRotation.m_Value.x != 0.0
    || this->m_angRotation.m_Value.y != 0.0
    || this->m_angRotation.m_Value.z != 0.0 )
  {
    this->m_angRotation.m_Value.x = 0.0;
    this->m_angRotation.m_Value.y = 0.0;
    this->m_angRotation.m_Value.z = 0.0;
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
  if ( this->m_nSkin.m_Value != 0 )
    this->m_nSkin.m_Value = 0;
  if ( this->m_nFlags.m_Value != 0 )
    this->m_nFlags.m_Value = 0;
  if ( this->m_nEffects.m_Value != 0 )
    this->m_nEffects.m_Value = 0;
  if ( this->m_clrRender.m_Value.r != 0xFF
    || this->m_clrRender.m_Value.g != 0xFF
    || this->m_clrRender.m_Value.b != 0xFF
    || this->m_clrRender.m_Value.a != 0xFF )
  {
    this->m_clrRender = (CNetworkColor32Base<color32_s,CTEPhysicsProp::NetworkVar_m_clrRender>)-1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333930
// Name: void TE_PhysicsProp(class IRecipientFilter __near &,float,int,int,class Vector const __near &,class QAngle const __near &,class Vector const __near &,int,int,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_PhysicsProp(
        IRecipientFilter *filter,
        float delay,
        int modelindex,
        int skin,
        CNetworkVectorBase<Vector,CTEPhysicsProp::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<QAngle,CTEPhysicsProp::NetworkVar_m_angRotation> *angles,
        CNetworkVectorBase<Vector,CTEPhysicsProp::NetworkVar_m_vecVelocity> *vel,
        int flags,
        int effects,
        color24 renderColor)
{
  color32_s clrRenderConverted; // [esp+8h] [ebp-4h]

  *(color24 *)&clrRenderConverted.r = renderColor;
  clrRenderConverted.a = -1;
  if ( pos->m_Value.x != s_TEPhysicsProp.m_vecOrigin.m_Value.x
    || pos->m_Value.y != s_TEPhysicsProp.m_vecOrigin.m_Value.y
    || pos->m_Value.z != s_TEPhysicsProp.m_vecOrigin.m_Value.z )
  {
    s_TEPhysicsProp.m_vecOrigin = *pos;
  }
  if ( angles->m_Value.x != s_TEPhysicsProp.m_angRotation.m_Value.x
    || angles->m_Value.y != s_TEPhysicsProp.m_angRotation.m_Value.y
    || angles->m_Value.z != s_TEPhysicsProp.m_angRotation.m_Value.z )
  {
    s_TEPhysicsProp.m_angRotation = *angles;
  }
  if ( vel->m_Value.x != s_TEPhysicsProp.m_vecVelocity.m_Value.x
    || vel->m_Value.y != s_TEPhysicsProp.m_vecVelocity.m_Value.y
    || vel->m_Value.z != s_TEPhysicsProp.m_vecVelocity.m_Value.z )
  {
    s_TEPhysicsProp.m_vecVelocity = *vel;
  }
  if ( s_TEPhysicsProp.m_nModelIndex.m_Value != modelindex )
    s_TEPhysicsProp.m_nModelIndex.m_Value = modelindex;
  if ( s_TEPhysicsProp.m_nSkin.m_Value != skin )
    s_TEPhysicsProp.m_nSkin.m_Value = skin;
  if ( s_TEPhysicsProp.m_nFlags.m_Value != flags )
    s_TEPhysicsProp.m_nFlags.m_Value = flags;
  if ( s_TEPhysicsProp.m_nEffects.m_Value != effects )
    s_TEPhysicsProp.m_nEffects.m_Value = effects;
  if ( s_TEPhysicsProp.m_clrRender.m_Value.r != renderColor.r
    || s_TEPhysicsProp.m_clrRender.m_Value.g != renderColor.g
    || s_TEPhysicsProp.m_clrRender.m_Value.b != renderColor.b
    || s_TEPhysicsProp.m_clrRender.m_Value.a != 0xFF )
  {
    s_TEPhysicsProp.m_clrRender.m_Value = clrRenderConverted;
  }
  CBaseTempEntity::Create(this: &s_TEPhysicsProp, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104173F0
// Name: DT_TEPhysicsProp::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPhysicsProp::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEPhysicsProp::g_SendTable);
  return atexit(func: DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417410
// Name: DT_TEPhysicsProp::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPhysicsProp::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEPhysicsProp::ignored>();
  DT_TEPhysicsProp::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104227A0
// Name: DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPhysicsProp::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEPhysicsProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417420
// Name: _dynamic_initializer_for__s_TEPhysicsProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TEPhysicsProp__()
{
  CTEPhysicsProp::CTEPhysicsProp(this: &s_TEPhysicsProp, name: "physicsprop");
  return atexit(func: dynamic_atexit_destructor_for__s_TEPhysicsProp__);
}

//------------------------------------------------------------------------------
// Address: 0x10417440
// Name: _dynamic_initializer_for__g_CTEPlayerDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEPlayerDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEPlayerDecal_ClassReg,
           pNetworkName: "CTEPlayerDecal",
           pTable: &DT_TEPlayerDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104227B0
// Name: _dynamic_atexit_destructor_for__s_TEPhysicsProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TEPhysicsProp__()
{
  s_TEPhysicsProp.__vftable = (CTEPhysicsProp_vtbl *)&CTEPhysicsProp::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &s_TEPhysicsProp);
}

//------------------------------------------------------------------------------
// Address: 0x104227D0
// Name: _ServerClassInit_DT_TEPhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEPhysicsProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_353;
  for ( i = 11; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
