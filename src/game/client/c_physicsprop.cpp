// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_physicsprop.cpp
// Functions: 16
// ============================================================

#include "game\client\c_physicsprop.h"

//------------------------------------------------------------------------------
// Address: 0x10079D20
// Name: public: virtual class ClientClass __near * C_PhysicsProp::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PhysicsProp::GetClientClass(C_PhysicsProp *this)
{
  return &__g_C_PhysicsPropClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10079DD0
// Name: public: virtual C_PhysicsProp::~C_PhysicsProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysicsProp::~C_PhysicsProp(C_PhysicsProp *this)
{
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysicsProp_vtbl *)&C_PhysicsProp::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysicsProp::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PhysicsProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079E10
// Name: public: virtual void C_PhysicsProp::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PhysicsProp::OnDataChanged(C_PhysicsProp *this, DataUpdateType_t type)
{
  IVModelInfoClient_vtbl *v3; // ebx
  int v4; // eax
  bool v5; // al

  C_BreakableProp::OnDataChanged(this, type);
  v3 = modelinfo->__vftable;
  v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 32))(a1: (char *)this - 4);
  v5 = v3->UsesStaticLighting(this: modelinfo, a2: (const struct model_t *)v4);
  *(&this->m_bClientPhysics + 2) = v5;
  if ( v5 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 120))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x10079E60
// Name: public: C_PhysicsProp::C_PhysicsProp(void)
// Source: json
//------------------------------------------------------------------------------
C_PhysicsProp *__thiscall C_PhysicsProp::C_PhysicsProp(C_PhysicsProp *this)
{
  C_BreakableProp::C_BreakableProp(this);
  this->m_pPhysicsObject = nullptr;
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PhysicsProp_vtbl *)&C_PhysicsProp::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PhysicsProp::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PhysicsProp::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PhysicsProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_takedamage = 2;
  *(_WORD *)&this->m_bAwakeLastTime = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079F50
// Name: public: virtual class IClientModelRenderable __near * C_PhysicsProp::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall C_PhysicsProp::GetClientModelRenderable(C_PhysicsProp *this)
{
  if ( C_BaseAnimating::GetClientModelRenderable(this, a2: (int)this) == nullptr
    || *(&this->m_bClientPhysics + 5) != *(&this->m_bClientPhysics + 4)
    && r_visualizeproplightcaching.m_pParent != nullptr
    && r_visualizeproplightcaching.m_pParent->m_Value.m_nValue != 0
    || this == (C_PhysicsProp *)4 )
  {
    return nullptr;
  }
  else
  {
    return &this->IClientThinkable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079F90
// Name: public: virtual bool C_PhysicsProp::GetRenderData(void __near *,enum ModelDataCategory_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PhysicsProp::GetRenderData(C_PhysicsProp *this, _DWORD *pData, ModelDataCategory_t nCategory)
{
  IVModelRender_vtbl *v5; // edi
  unsigned __int16 v6; // ax

  if ( nCategory != MODEL_DATA_LIGHTING_MODEL )
    return C_BaseAnimating::GetRenderData(this, pData, nCategory);
  if ( BYTE2(this->m_qPreferredPlayerCarryAngles.y) != 0
    && r_PhysPropStaticLighting.m_pParent != nullptr
    && r_PhysPropStaticLighting.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( BYTE1(this->m_qPreferredPlayerCarryAngles.y) == 0
      || LOBYTE(this->m_qPreferredPlayerCarryAngles.y) != 0
      || (v5 = modelrender->__vftable,
          v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 3) + 124))(a1: (char *)this - 12),
          v5->RecomputeStaticLighting(this: modelrender, a2: v6)) )
    {
      *pData = LOBYTE(this->m_qPreferredPlayerCarryAngles.y) != 0 ? 0 : 2;
      BYTE1(this->m_qPreferredPlayerCarryAngles.y) = LOBYTE(this->m_qPreferredPlayerCarryAngles.y);
      return true;
    }
    else
    {
      *pData = 0;
      return true;
    }
  }
  else
  {
    *pData = 0;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A050
// Name: public: virtual bool C_PhysicsProp::OnInternalDrawModel(struct ClientModelRenderInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_PhysicsProp::OnInternalDrawModel(C_PhysicsProp *this, ClientModelRenderInfo_t *pInfo)
{
  char m_bAwakeLastTime; // al
  char m_bAwake; // cl
  IVModelRender_vtbl *v5; // esi
  unsigned __int16 v6; // ax
  char result; // al
  float color[4]; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_bCanUseStaticLighting
    && r_PhysPropStaticLighting.m_pParent != nullptr
    && r_PhysPropStaticLighting.m_pParent->m_Value.m_nValue != 0 )
  {
    m_bAwakeLastTime = this->m_bAwakeLastTime;
    m_bAwake = this->m_bAwake;
    if ( m_bAwakeLastTime != m_bAwake )
    {
      if ( m_bAwakeLastTime == 0 || m_bAwake != 0 )
      {
        if ( r_visualizeproplightcaching.m_pParent != nullptr
          && r_visualizeproplightcaching.m_pParent->m_Value.m_nValue != 0 )
        {
          color[0] = 1.0;
          color[1] = 0.0;
          color[2] = 0.0;
          color[3] = 1.0;
          render->SetColorModulation(this: render, a2: color);
        }
      }
      else
      {
        v5 = modelrender->__vftable;
        v6 = this->GetModelInstance(this: &this->IClientRenderable);
        result = v5->RecomputeStaticLighting(this: modelrender, a2: v6);
        if ( result == 0 )
          return result;
        if ( r_visualizeproplightcaching.m_pParent != nullptr
          && r_visualizeproplightcaching.m_pParent->m_Value.m_nValue != 0 )
        {
          color[0] = 0.0;
          color[1] = 1.0;
          color[2] = 0.0;
          color[3] = 1.0;
          render->SetColorModulation(this: render, a2: color);
        }
      }
    }
    if ( !this->m_bAwake )
      pInfo->flags |= 0x10u;
    this->m_bAwakeLastTime = this->m_bAwake;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10412B20
// Name: DT_PhysicsProp::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsProp::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PhysicsProp::g_RecvTable);
  return atexit(func: DT_PhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412B40
// Name: DT_PhysicsProp::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsProp::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PhysicsProp::ignored>();
  DT_PhysicsProp::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430740
// Name: DT_PhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysicsProp::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PhysicsProp::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10079F00
// Name: _C_PhysicsProp_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PhysicsProp_CreateObject(int entnum, int serialNum)
{
  C_PhysicsProp *v2; // eax
  C_PhysicsProp *v3; // eax
  C_PhysicsProp *v4; // esi

  v2 = (C_PhysicsProp *)C_BaseEntity::operator new(stAllocateBlock: 0xCF0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PhysicsProp::C_PhysicsProp(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412B50
// Name: _dynamic_initializer_for__r_PhysPropStaticLighting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_PhysPropStaticLighting__()
{
  ConVar::ConVar(this: &r_PhysPropStaticLighting, pName: "r_PhysPropStaticLighting", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_PhysPropStaticLighting__);
}

//------------------------------------------------------------------------------
// Address: 0x10412B80
// Name: _dynamic_initializer_for__r_visualizeproplightcaching__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_visualizeproplightcaching__()
{
  ConVar::ConVar(this: &r_visualizeproplightcaching, pName: "r_visualizeproplightcaching", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_visualizeproplightcaching__);
}

//------------------------------------------------------------------------------
// Address: 0x10412BB0
// Name: _dynamic_initializer_for____g_C_PhysMagnetClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PhysMagnetClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PhysMagnetClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PhysMagnetClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430750
// Name: _dynamic_atexit_destructor_for__r_PhysPropStaticLighting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_PhysPropStaticLighting__()
{
  ConVar::~ConVar(this: &r_PhysPropStaticLighting);
}

//------------------------------------------------------------------------------
// Address: 0x10430760
// Name: _dynamic_atexit_destructor_for__r_visualizeproplightcaching__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_visualizeproplightcaching__()
{
  ConVar::~ConVar(this: &r_visualizeproplightcaching);
}
