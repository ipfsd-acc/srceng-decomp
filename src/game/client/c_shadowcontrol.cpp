// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_shadowcontrol.cpp
// Functions: 8
// ============================================================

#include "game\client\c_shadowcontrol.h"

//------------------------------------------------------------------------------
// Address: 0x10089DF0
// Name: public: virtual class ClientClass __near * C_ShadowControl::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ShadowControl::GetClientClass(C_ShadowControl *this)
{
  return &__g_C_ShadowControlClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10089F00
// Name: public: virtual void C_ShadowControl::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ShadowControl::OnDataChanged(C_ShadowControl *this, DataUpdateType_t updateType)
{
  g_pClientShadowMgr->SetShadowDirection(this: g_pClientShadowMgr, a2: (const Vector *)&this->m_bIsBlurred);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))g_pClientShadowMgr->SetShadowColor)(
    a1: LOBYTE(this->m_shadowDirection.y),
    a2: BYTE1(this->m_shadowDirection.y),
    a3: BYTE2(this->m_shadowDirection.y));
  ((void (__stdcall *)(_DWORD))g_pClientShadowMgr->SetShadowDistance)(a1: LODWORD(this->m_shadowDirection.z));
  ((void (__stdcall *)(_DWORD))g_pClientShadowMgr->SetShadowsDisabled)(a1: this->m_shadowColor.r);
  ((void (__stdcall *)(_DWORD))g_pClientShadowMgr->SetShadowFromWorldLightsEnabled)(a1: this->m_shadowColor.g);
}

//------------------------------------------------------------------------------
// Address: 0x10413770
// Name: DT_ShadowControl::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ShadowControl::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ShadowControl::g_RecvTable);
  return atexit(func: DT_ShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413790
// Name: DT_ShadowControl::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ShadowControl::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ShadowControl::ignored>();
  DT_ShadowControl::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430AF0
// Name: DT_ShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ShadowControl::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ShadowControl::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10089FA0
// Name: _C_ShadowControl_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ShadowControl_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x998u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_ShadowControl::`vftable'{for `IClientUnknown'};
  v3[1] = &C_ShadowControl::`vftable'{for `IClientRenderable'};
  v3[2] = &C_ShadowControl::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_ShadowControl::`vftable'{for `IClientThinkable'};
  v3[4] = &C_ShadowControl::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104137A0
// Name: _dynamic_initializer_for__g_SlideshowDisplays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SlideshowDisplays__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SlideshowDisplays__);
}

//------------------------------------------------------------------------------
// Address: 0x104137B0
// Name: _dynamic_initializer_for____g_C_SlideshowDisplayClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SlideshowDisplayClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SlideshowDisplayClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SlideshowDisplayClientClass;
  return result;
}
