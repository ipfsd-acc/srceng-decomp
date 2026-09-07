// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_bubbles.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_bubbles.h"

//------------------------------------------------------------------------------
// Address: 0x102575E0
// Name: void TE_Bubbles(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Bubbles(
        IRecipientFilter *filter,
        float delay,
        const Vector *mins,
        const Vector *maxs,
        float height,
        int modelindex,
        int count,
        float speed)
{
  ((void (__stdcall *)(const Vector *, const Vector *, _DWORD, int, int, _DWORD))tempents->Bubbles)(
    a1: mins,
    a2: maxs,
    a3: LODWORD(height),
    a4: modelindex,
    a5: count,
    a6: LODWORD(speed));
}

//------------------------------------------------------------------------------
// Address: 0x10257620
// Name: public: virtual void C_TEBubbles::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBubbles::PostDataUpdate(C_TEBubbles *this, DataUpdateType_t updateType)
{
  ((void (__thiscall *)(ITempEnts *, C_BaseTempEntity **, float *, _DWORD, _DWORD, int, int))tempents->Bubbles)(
    a1: tempents,
    a2: &this->m_pNextDynamic,
    a3: &this->m_vecMins.z,
    a4: LODWORD(this->m_vecMaxs.z),
    a5: LODWORD(this->m_fHeight),
    a6: this->m_nModelIndex,
    a7: this->m_nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10257660
// Name: public: virtual class ClientClass __near * C_TEBubbles::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBubbles::GetClientClass(C_TEBubbles *this)
{
  return &__g_C_TEBubblesClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042BA10
// Name: DT_TEBubbles::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbles::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBubbles::g_RecvTable);
  return atexit(func: DT_TEBubbles::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BA30
// Name: DT_TEBubbles::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbles::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBubbles::ignored>();
  DT_TEBubbles::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104369D0
// Name: DT_TEBubbles::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBubbles::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBubbles::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10257670
// Name: _C_TEBubbles_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBubbles_CreateObject()
{
  return &_g_C_TEBubbles.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BA40
// Name: _dynamic_initializer_for____g_C_TEBubbleTrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBubbleTrail__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBubbleTrail);
  _g_C_TEBubbleTrail.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBubbleTrail_vtbl *)&C_TEBubbleTrail::`vftable'{for `IClientUnknown'};
  _g_C_TEBubbleTrail.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBubbleTrail::`vftable'{for `IClientNetworkable'};
  _g_C_TEBubbleTrail.m_vecMins.x = 0.0;
  _g_C_TEBubbleTrail.m_vecMins.y = 0.0;
  _g_C_TEBubbleTrail.m_vecMins.z = 0.0;
  _g_C_TEBubbleTrail.m_vecMaxs.x = 0.0;
  _g_C_TEBubbleTrail.m_vecMaxs.y = 0.0;
  _g_C_TEBubbleTrail.m_vecMaxs.z = 0.0;
  _g_C_TEBubbleTrail.m_flWaterZ = 0.0;
  _g_C_TEBubbleTrail.m_nModelIndex = 0;
  _g_C_TEBubbleTrail.m_nCount = 0;
  _g_C_TEBubbleTrail.m_fSpeed = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBubbleTrail__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BAC0
// Name: _dynamic_initializer_for____g_C_TEBubbleTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBubbleTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBubbleTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBubbleTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104369E0
// Name: _dynamic_atexit_destructor_for____g_C_TEBubbleTrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBubbleTrail__()
{
  _g_C_TEBubbleTrail.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBubbleTrail_vtbl *)&C_TEBubbleTrail::`vftable'{for `IClientUnknown'};
  _g_C_TEBubbleTrail.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBubbleTrail::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBubbleTrail);
}
