// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_showline.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_showline.h"

//------------------------------------------------------------------------------
// Address: 0x10264FF0
// Name: public: virtual class ClientClass __near * C_TEShowLine::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEShowLine::GetClientClass(C_TEShowLine *this)
{
  return &__g_C_TEShowLineClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102650C0
// Name: public: virtual void C_TEShowLine::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEShowLine::PostDataUpdate(C_TEShowLine *this, DataUpdateType_t updateType)
{
  const Vector *p_m_pNextDynamic; // esi
  CTEParticleRenderer *m_pObj; // ecx
  float i; // xmm1_4
  StandardParticle_t *v5; // eax
  Vector vec; // [esp+0h] [ebp-14h] BYREF
  CSmartPtr<CTEParticleRenderer,CRefCountAccessor> pRen; // [esp+Ch] [ebp-8h] BYREF
  float len; // [esp+10h] [ebp-4h]

  p_m_pNextDynamic = (const Vector *)&this->m_pNextDynamic;
  vec.x = this->m_vecOrigin.z - *(float *)&this->m_pNextDynamic;
  vec.y = this->m_vecEnd.x - this->m_vecOrigin.x;
  vec.z = this->m_vecEnd.y - this->m_vecOrigin.y;
  len = VectorNormalize(&vec);
  vec.x = vec.x * 3.0;
  vec.y = vec.y * 3.0;
  vec.z = vec.z * 3.0;
  CTEParticleRenderer::Create(result: &pRen, pDebugName: "TEShowLine", vOrigin: p_m_pNextDynamic);
  m_pObj = pRen.m_pObj;
  if ( pRen.m_pObj != nullptr )
  {
    for ( i = len; len > 0.0; m_pObj = pRen.m_pObj )
    {
      len = i - 3.0;
      v5 = CTEParticleRenderer::AddParticle(this: m_pObj);
      if ( v5 != nullptr )
      {
        v5->m_Velocity.x = 0.0;
        v5->m_Velocity.y = 0.0;
        v5->m_Velocity.z = 0.0;
        v5->m_Lifetime = 30.0;
        v5->m_Color[0] = 0;
        v5->m_Color[1] = -1;
        v5->m_Color[2] = -1;
        v5->m_Color[3] = -1;
        v5->m_EffectData = 0;
        v5->m_Pos.x = p_m_pNextDynamic->x;
        v5->m_Pos.y = p_m_pNextDynamic->y;
        v5->m_Pos.z = p_m_pNextDynamic->z;
        p_m_pNextDynamic->x = vec.x + p_m_pNextDynamic->x;
        p_m_pNextDynamic->y = p_m_pNextDynamic->y + vec.y;
        p_m_pNextDynamic->z = p_m_pNextDynamic->z + vec.z;
      }
      i = len;
    }
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10265220
// Name: void TE_ShowLine(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ShowLine(IRecipientFilter *filter, float delay, const Vector *start, const Vector *end)
{
  _g_C_TEShowLine.m_vecOrigin = *start;
  _g_C_TEShowLine.m_vecEnd = *end;
  C_TEShowLine::PostDataUpdate(
    this: (C_TEShowLine *)&_g_C_TEShowLine.IClientNetworkable,
    updateType: DATA_UPDATE_CREATED);
}

//------------------------------------------------------------------------------
// Address: 0x1042CB40
// Name: DT_TEShowLine::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShowLine::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEShowLine::g_RecvTable);
  return atexit(func: DT_TEShowLine::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CB60
// Name: DT_TEShowLine::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShowLine::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEShowLine::ignored>();
  DT_TEShowLine::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436E30
// Name: DT_TEShowLine::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEShowLine::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEShowLine::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10265000
// Name: _C_TEShowLine_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEShowLine_CreateObject()
{
  return &_g_C_TEShowLine.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042CB70
// Name: _dynamic_initializer_for____g_C_TESmoke__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TESmoke__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TESmoke);
  _g_C_TESmoke.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESmoke_vtbl *)&C_TESmoke::`vftable'{for `IClientUnknown'};
  _g_C_TESmoke.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESmoke::`vftable'{for `IClientNetworkable'};
  _g_C_TESmoke.m_vecOrigin.x = 0.0;
  _g_C_TESmoke.m_vecOrigin.y = 0.0;
  _g_C_TESmoke.m_vecOrigin.z = 0.0;
  _g_C_TESmoke.m_nModelIndex = 0;
  _g_C_TESmoke.m_fScale = 0.0;
  _g_C_TESmoke.m_nFrameRate = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TESmoke__);
}

//------------------------------------------------------------------------------
// Address: 0x1042CBD0
// Name: _dynamic_initializer_for____g_C_TESmokeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TESmokeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TESmokeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TESmokeClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436E40
// Name: _dynamic_atexit_destructor_for____g_C_TESmoke__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TESmoke__()
{
  _g_C_TESmoke.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TESmoke_vtbl *)&C_TESmoke::`vftable'{for `IClientUnknown'};
  _g_C_TESmoke.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TESmoke::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TESmoke);
}
