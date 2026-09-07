// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_effect_dispatch.cpp
// Functions: 11
// ============================================================

#include "game\server\te_effect_dispatch.h"

//------------------------------------------------------------------------------
// Address: 0x10330E10
// Name: public: virtual class ServerClass __near * CTEEffectDispatch::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEEffectDispatch::GetServerClass(CTEEffectDispatch *this)
{
  return &g_CTEEffectDispatch_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10330E50
// Name: public: class CEffectData __near & CEffectData::operator=(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
CEffectData *__thiscall CEffectData::operator=(CEffectData *this, const CEffectData *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10330F00
// Name: void DispatchEffect(class IRecipientFilter __near &,float,char const __near *,class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchEffect(IRecipientFilter *filter, float flDelay, const char *pName, const CEffectData *data)
{
  if ( !te->SuppressTE(this: te, a2: filter) )
  {
    CEffectData::operator=(this: &g_TEEffectDispatch.m_EffectData, __that: data);
    g_TEEffectDispatch.m_EffectData.m_iEffectName = GetEffectIndex(pEffectName: pName);
    CBaseTempEntity::Create(this: &g_TEEffectDispatch, filter, delay: flDelay);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10330FF0
// Name: void DispatchEffect(char const __near *,class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispatchEffect(const char *pName, const CEffectData *data)
{
  CPASFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &data->m_vOrigin);
  if ( !te->SuppressTE(this: te, a2: &filter) )
  {
    CEffectData::operator=(this: &g_TEEffectDispatch.m_EffectData, __that: data);
    g_TEEffectDispatch.m_EffectData.m_iEffectName = GetEffectIndex(pEffectName: pName);
    CBaseTempEntity::Create(this: &g_TEEffectDispatch, &filter, delay: 0.0);
  }
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10416970
// Name: DT_TEEffectDispatch::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEffectDispatch::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEEffectDispatch::g_SendTable);
  return atexit(func: DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416990
// Name: DT_TEEffectDispatch::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEffectDispatch::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEEffectDispatch::ignored>();
  DT_TEEffectDispatch::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104223C0
// Name: DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEEffectDispatch::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEEffectDispatch::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104169A0
// Name: _dynamic_initializer_for__g_TEEffectDispatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEEffectDispatch__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEEffectDispatch, name: "EffectDispatch");
  g_TEEffectDispatch.__vftable = (CTEEffectDispatch_vtbl *)&CTEEffectDispatch::`vftable';
  g_TEEffectDispatch.m_EffectData.m_vOrigin.x = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vOrigin.y = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vOrigin.z = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vStart.x = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vStart.y = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vStart.z = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vNormal.x = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vNormal.y = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vNormal.z = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vAngles.x = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vAngles.y = 0.0;
  g_TEEffectDispatch.m_EffectData.m_vAngles.z = 0.0;
  g_TEEffectDispatch.m_EffectData.m_fFlags = 0;
  g_TEEffectDispatch.m_EffectData.m_nEntIndex = 0;
  g_TEEffectDispatch.m_EffectData.m_flScale = 1.0;
  g_TEEffectDispatch.m_EffectData.m_nAttachmentIndex = 0;
  g_TEEffectDispatch.m_EffectData.m_nSurfaceProp = 0;
  g_TEEffectDispatch.m_EffectData.m_flMagnitude = 0.0;
  g_TEEffectDispatch.m_EffectData.m_flRadius = 0.0;
  g_TEEffectDispatch.m_EffectData.m_nMaterial = 0;
  g_TEEffectDispatch.m_EffectData.m_nDamageType = 0;
  g_TEEffectDispatch.m_EffectData.m_nHitBox = 0;
  g_TEEffectDispatch.m_EffectData.m_nColor = 0;
  g_TEEffectDispatch.m_EffectData.m_nOtherEntIndex = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEEffectDispatch__);
}

//------------------------------------------------------------------------------
// Address: 0x10416A80
// Name: _dynamic_initializer_for__g_CTEEnergySplash_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEEnergySplash_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEEnergySplash_ClassReg,
           pNetworkName: "CTEEnergySplash",
           pTable: &DT_TEEnergySplash::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104223D0
// Name: _dynamic_atexit_destructor_for__g_TEEffectDispatch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEEffectDispatch__()
{
  g_TEEffectDispatch.__vftable = (CTEEffectDispatch_vtbl *)&CTEEffectDispatch::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEEffectDispatch);
}

//------------------------------------------------------------------------------
// Address: 0x104223F0
// Name: _ServerClassInit_DT_TEEffectDispatch::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEEffectDispatch::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_340;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
