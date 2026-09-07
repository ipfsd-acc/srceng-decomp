// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_spatialentity.cpp
// Functions: 10
// ============================================================

#include "game\client\c_spatialentity.h"

//------------------------------------------------------------------------------
// Address: 0x1008DEE0
// Name: public: virtual class ClientClass __near * C_SpatialEntity::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SpatialEntity::GetClientClass(C_SpatialEntity *this)
{
  return &__g_C_SpatialEntityClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1008DFF0
// Name: public: virtual void C_SpatialEntity::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntity::OnDataChanged(C_SpatialEntity *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 688))(a1: (char *)this - 8);
}

//------------------------------------------------------------------------------
// Address: 0x1008E020
// Name: public: virtual void C_SpatialEntity::InitSpatialEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntity::InitSpatialEntity(C_SpatialEntity *this)
{
  ((void (__stdcall *)(int))this->SetNextClientThink)(a1: -996040704);
  this->AddToPersonalSpatialEntityMgr(this);
  this->m_flWeight = 0.0;
  this->m_flInfluence = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E060
// Name: public: virtual void C_SpatialEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntity::UpdateOnRemove(C_SpatialEntity *this)
{
  C_BaseEntity::UpdateOnRemove(this);
  this->RemoveFromPersonalSpatialEntityMgr(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008E080
// Name: public: virtual void C_SpatialEntity::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpatialEntity::ClientThink(C_SpatialEntity *this)
{
  C_BasePlayer *LocalPlayer; // eax
  int v3; // eax
  float v4; // ecx
  float x; // xmm4_4
  float y; // xmm3_4
  float v7; // xmm0_4
  double v8; // xmm0_8
  float v9; // xmm0_4
  double v10; // xmm0_8
  float v11; // xmm0_4
  double v12; // xmm0_8
  float v13; // [esp-10h] [ebp-1Ch]
  __int64 v14; // [esp-Ch] [ebp-18h]

  if ( this->m_netLookupFilename[248] != 0 || this->m_vecOrigin.z != 0.0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: 0);
    if ( LocalPlayer != nullptr )
    {
      v3 = (int)LocalPlayer->GetAbsOrigin(this: LocalPlayer);
      v4 = *(float *)(v3 + 8);
      x = this->m_vecOrigin.x;
      v14 = *(_QWORD *)v3;
      *(_DWORD *)&this->m_netLookupFilename[252] = 0;
      if ( x != -1.0 )
      {
        y = this->m_vecOrigin.y;
        if ( y != -1.0 && x != y )
        {
          v13 = fsqrt(
                  (float)((float)((float)(*((float *)&v14 + 1) - *(float *)&this->m_bIsBlurred)
                                * (float)(*((float *)&v14 + 1) - *(float *)&this->m_bIsBlurred))
                        + (float)((float)(v4 - *((float *)&this->m_bIsBlurred + 1))
                                * (float)(v4 - *((float *)&this->m_bIsBlurred + 1))))
                + (float)((float)(*(float *)&v14 - *(float *)&this->m_CalcAbsoluteVelocityMutex.m_depth)
                        * (float)(*(float *)&v14 - *(float *)&this->m_CalcAbsoluteVelocityMutex.m_depth)));
          v7 = (float)(v13 - x) / (float)(y - x);
          *(float *)&this->m_netLookupFilename[252] = v7;
          v8 = v7;
          if ( v8 <= 0.0 )
            v8 = 0.0;
          v9 = v8;
          *(float *)&this->m_netLookupFilename[252] = v9;
          v10 = v9;
          if ( v10 >= 1.0 )
            v10 = 1.0;
          v11 = v10;
          *(float *)&this->m_netLookupFilename[252] = v11;
          v12 = (float)(x - v13);
          if ( v12 <= 0.0 )
            v12 = 0.0;
          *(float *)&this->m_netLookupFilename[256] = v12;
        }
      }
      *(float *)&this->m_netLookupFilename[252] = (float)(1.0 - *(float *)&this->m_netLookupFilename[252])
                                                * this->m_vecOrigin.z;
      C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
    }
  }
  else
  {
    *(_DWORD *)&this->m_netLookupFilename[252] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104139C0
// Name: DT_SpatialEntity::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpatialEntity::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SpatialEntity::g_RecvTable);
  return atexit(func: DT_SpatialEntity::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104139E0
// Name: DT_SpatialEntity::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpatialEntity::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SpatialEntity::ignored>();
  DT_SpatialEntity::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430BB0
// Name: DT_SpatialEntity::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpatialEntity::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SpatialEntity::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1008E230
// Name: _C_SpatialEntity_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SpatialEntity_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xAA8u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_SpatialEntity::`vftable'{for `IClientUnknown'};
  v3[1] = &C_SpatialEntity::`vftable'{for `IClientRenderable'};
  v3[2] = &C_SpatialEntity::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_SpatialEntity::`vftable'{for `IClientThinkable'};
  v3[4] = &C_SpatialEntity::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104139F0
// Name: _dynamic_initializer_for____g_C_SpotlightEndClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SpotlightEndClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SpotlightEndClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SpotlightEndClientClass;
  return result;
}
