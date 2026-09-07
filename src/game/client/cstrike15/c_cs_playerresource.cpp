// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_cs_playerresource.cpp
// Functions: 28
// ============================================================

#include "game\client\cstrike15\c_cs_playerresource.h"

//------------------------------------------------------------------------------
// Address: 0x101BE6A0
// Name: public: virtual class ClientClass __near * C_CS_PlayerResource::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CS_PlayerResource::GetClientClass(C_CS_PlayerResource *this)
{
  return &__g_C_CS_PlayerResourceClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101BED30
// Name: public: bool C_CS_PlayerResource::IsVIP(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CS_PlayerResource::IsVIP(C_CS_PlayerResource *this, int iIndex)
{
  return this->m_iPlayerVIP == iIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101BED50
// Name: public: bool C_CS_PlayerResource::HasC4(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CS_PlayerResource::HasC4(C_CS_PlayerResource *this, int iIndex)
{
  return this->m_iPlayerC4 == iIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101BED70
// Name: public: bool C_CS_PlayerResource::IsHostageAlive(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsHostageAlive(C_CS_PlayerResource *this, unsigned int iIndex)
{
  return iIndex <= 0xB && this->m_bHostageAlive[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101BED90
// Name: public: bool C_CS_PlayerResource::IsHostageFollowingSomeone(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsHostageFollowingSomeone(C_CS_PlayerResource *this, unsigned int iIndex)
{
  return iIndex <= 0xB && this->m_isHostageFollowingSomeone[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101BEDB0
// Name: public: int C_CS_PlayerResource::GetHostageEntityID(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CS_PlayerResource::GetHostageEntityID(C_CS_PlayerResource *this, unsigned int iIndex)
{
  if ( iIndex > 0xB )
    return -1;
  else
    return this->m_iHostageEntityIDs[iIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101BEDD0
// Name: public: class Vector const C_CS_PlayerResource::GetC4Postion(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CS_PlayerResource::GetC4Postion(C_CS_PlayerResource *this, const Vector *result)
{
  C_BasePlayer *v3; // eax
  int v4; // eax
  float v5; // edx
  float z; // ecx

  if ( this->m_iPlayerC4 > 0 && (v3 = UTIL_PlayerByIndex(entindex: this->m_iPlayerC4)) != nullptr )
  {
    v4 = (int)v3->GetAbsOrigin(this: v3);
    v5 = *(float *)(v4 + 8);
    *(_QWORD *)&result->x = *(_QWORD *)v4;
    result->z = v5;
    return result;
  }
  else
  {
    z = this->m_vecC4.z;
    *(_QWORD *)&result->x = *(_QWORD *)&this->m_vecC4.x;
    result->z = z;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BEE30
// Name: public: class Vector const C_CS_PlayerResource::GetBombsiteAPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CS_PlayerResource::GetBombsiteAPosition(C_CS_PlayerResource *this, const Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_bombsiteCenterA.x;
  z = this->m_bombsiteCenterA.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE50
// Name: public: class Vector const C_CS_PlayerResource::GetBombsiteBPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CS_PlayerResource::GetBombsiteBPosition(C_CS_PlayerResource *this, const Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_bombsiteCenterB.x;
  z = this->m_bombsiteCenterB.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE70
// Name: public: bool C_CS_PlayerResource::IsBombSpotted(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsBombSpotted(C_CS_PlayerResource *this)
{
  return this->m_bBombSpotted;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE80
// Name: public: bool C_CS_PlayerResource::IsDefuserSpotted(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsDefuserSpotted(C_CS_PlayerResource *this)
{
  return this->m_bDefuserSpotted;
}

//------------------------------------------------------------------------------
// Address: 0x101BEE90
// Name: public: bool C_CS_PlayerResource::IsPlayerSpotted(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsPlayerSpotted(C_CS_PlayerResource *this, int iIndex)
{
  bool result; // al

  result = this->IsConnected(this: &this->IGameResources, a2: iIndex);
  if ( result )
    return this->m_bPlayerSpotted[iIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BEED0
// Name: public: int C_CS_PlayerResource::GetNumMVPs(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CS_PlayerResource::GetNumMVPs(C_CS_PlayerResource *this, int iIndex)
{
  if ( this->IsConnected(this: &this->IGameResources, a2: iIndex) )
    return this->m_iMVPs[iIndex];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BEF10
// Name: public: bool C_CS_PlayerResource::HasDefuser(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::HasDefuser(C_CS_PlayerResource *this, int iIndex)
{
  bool result; // al

  result = this->IsConnected(this: &this->IGameResources, a2: iIndex);
  if ( result )
    return this->m_bHasDefuser[iIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BEF50
// Name: public: bool C_CS_PlayerResource::GetVote(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::GetVote(C_CS_PlayerResource *this, int iIndex)
{
  bool result; // al

  result = this->IsConnected(this: &this->IGameResources, a2: iIndex);
  if ( result )
    return this->m_bVote[iIndex];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BEF90
// Name: public: int C_CS_PlayerResource::GetArmor(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CS_PlayerResource::GetArmor(C_CS_PlayerResource *this, int iIndex)
{
  if ( this->IsConnected(this: &this->IGameResources, a2: iIndex) )
    return this->m_iArmor[iIndex];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BEFD0
// Name: public: int C_CS_PlayerResource::GetScore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CS_PlayerResource::GetScore(C_CS_PlayerResource *this, int iIndex)
{
  if ( this->IsConnected(this: &this->IGameResources, a2: iIndex) )
    return this->m_iScore[iIndex];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BF010
// Name: public: bool C_CS_PlayerResource::IsControllingBot(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CS_PlayerResource::IsControllingBot(C_CS_PlayerResource *this, int index)
{
  return this->m_bControllingBot[index];
}

//------------------------------------------------------------------------------
// Address: 0x101BF030
// Name: public: int C_CS_PlayerResource::GetControlledByPlayer(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CS_PlayerResource::GetControlledByPlayer(C_CS_PlayerResource *this, int index)
{
  return this->m_iControlledByPlayer[index];
}

//------------------------------------------------------------------------------
// Address: 0x101BF050
// Name: public: virtual char const __near * C_CS_PlayerResource::GetPlayerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_CS_PlayerResource::GetPlayerName(C_CS_PlayerResource *this, int index)
{
  return C_PlayerResource::GetPlayerName(this, iIndex: index);
}

//------------------------------------------------------------------------------
// Address: 0x101BF070
// Name: public: C_CS_PlayerResource::C_CS_PlayerResource(void)
// Source: json
//------------------------------------------------------------------------------
C_CS_PlayerResource *__thiscall C_CS_PlayerResource::C_CS_PlayerResource(C_CS_PlayerResource *this)
{
  C_PlayerResource::C_PlayerResource(this);
  this->C_PlayerResource::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CS_PlayerResource_vtbl *)&C_CS_PlayerResource::`vftable'{for `IClientUnknown'};
  this->C_PlayerResource::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CS_PlayerResource::`vftable'{for `IClientRenderable'};
  this->C_PlayerResource::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CS_PlayerResource::`vftable'{for `IClientNetworkable'};
  this->C_PlayerResource::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CS_PlayerResource::`vftable'{for `IClientThinkable'};
  this->C_PlayerResource::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CS_PlayerResource::`vftable'{for `C_BaseEntity'};
  this->C_PlayerResource::IGameResources::__vftable = (IGameResources_vtbl *)&C_CS_PlayerResource::`vftable'{for `IGameResources'};
  this->m_Colors[2] = (Color)-12566273;
  this->m_Colors[3] = (Color)-13159;
  memset(dst: (int)this->m_iMVPs, value: nullptr, count: sizeof(this->m_iMVPs));
  memset(dst: (int)this->m_bHasDefuser, value: nullptr, count: sizeof(this->m_bHasDefuser));
  memset(dst: (int)this->m_iArmor, value: nullptr, count: sizeof(this->m_iArmor));
  memset(dst: (int)this->m_bVote, value: nullptr, count: sizeof(this->m_bVote));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BF170
// Name: public: class Vector const C_CS_PlayerResource::GetHostagePosition(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CS_PlayerResource::GetHostagePosition(
        C_CS_PlayerResource *this,
        const Vector *result,
        unsigned int iIndex)
{
  float v4; // ecx
  __int64 ret; // [esp+0h] [ebp-Ch]

  if ( iIndex > 0xB )
  {
    *result = vec3_origin;
  }
  else
  {
    *(float *)&ret = (float)this->m_iHostageX[iIndex];
    *((float *)&ret + 1) = (float)this->m_iHostageY[iIndex];
    v4 = (float)this->m_iHostageZ[iIndex];
    *(_QWORD *)&result->x = ret;
    result->z = v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BF1F0
// Name: public: class Vector const C_CS_PlayerResource::GetHostageRescuePosition(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CS_PlayerResource::GetHostageRescuePosition(
        C_CS_PlayerResource *this,
        const Vector *result,
        unsigned int iIndex)
{
  float v4; // ecx
  __int64 ret; // [esp+0h] [ebp-Ch]

  if ( iIndex > 3 )
  {
    *result = vec3_origin;
  }
  else
  {
    *(float *)&ret = (float)this->m_hostageRescueX[iIndex];
    *((float *)&ret + 1) = (float)this->m_hostageRescueY[iIndex];
    v4 = (float)this->m_hostageRescueZ[iIndex];
    *(_QWORD *)&result->x = ret;
    result->z = v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104222D0
// Name: DT_CSPlayerResource::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayerResource::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSPlayerResource::g_RecvTable);
  return atexit(func: DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104222F0
// Name: DT_CSPlayerResource::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayerResource::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSPlayerResource::ignored>();
  DT_CSPlayerResource::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104352F0
// Name: DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSPlayerResource::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSPlayerResource::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101BF270
// Name: _C_CS_PlayerResource_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CS_PlayerResource_CreateObject(int entnum, int serialNum)
{
  C_CS_PlayerResource *v2; // eax
  C_CS_PlayerResource *v3; // eax
  C_CS_PlayerResource *v4; // esi

  v2 = (C_CS_PlayerResource *)C_BaseEntity::operator new(stAllocateBlock: 0x2238u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_CS_PlayerResource::C_CS_PlayerResource(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10422300
// Name: _dynamic_initializer_for____g_C_CSTeamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CSTeamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CSTeamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CSTeamClientClass;
  return result;
}
