// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_movie_display.cpp
// Functions: 7
// ============================================================

#include "game\client\c_movie_display.h"

//------------------------------------------------------------------------------
// Address: 0x100788A0
// Name: public: virtual class ClientClass __near * C_MovieDisplay::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_MovieDisplay::GetClientClass(C_MovieDisplay *this)
{
  return &__g_C_MovieDisplayClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10078A50
// Name: public: virtual void C_MovieDisplay::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MovieDisplay::ReceiveMessage(C_MovieDisplay *this, int classID, bf_read *msg)
{
  if ( classID == this->GetRefEHandle(this)[5].m_Index )
    this->m_szGroupName[123] = 1;
  else
    C_BaseEntity::ReceiveMessage(this, classID, msg);
}

//------------------------------------------------------------------------------
// Address: 0x10412960
// Name: DT_MovieDisplay::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieDisplay::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_MovieDisplay::g_RecvTable);
  return atexit(func: DT_MovieDisplay::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412980
// Name: DT_MovieDisplay::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieDisplay::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_MovieDisplay::ignored>();
  DT_MovieDisplay::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430700
// Name: DT_MovieDisplay::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MovieDisplay::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_MovieDisplay::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10078A90
// Name: _C_MovieDisplay_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_MovieDisplay_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xA98u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_MovieDisplay::`vftable'{for `IClientUnknown'};
  v3[1] = &C_MovieDisplay::`vftable'{for `IClientRenderable'};
  v3[2] = &C_MovieDisplay::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_MovieDisplay::`vftable'{for `IClientThinkable'};
  v3[4] = &C_MovieDisplay::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412990
// Name: _dynamic_initializer_for____g_C_ParticleSystemClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ParticleSystemClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ParticleSystemClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ParticleSystemClientClass;
  return result;
}
