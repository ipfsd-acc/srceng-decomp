// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_point_camera.cpp
// Functions: 20
// ============================================================

#include "game\client\c_point_camera.h"

//------------------------------------------------------------------------------
// Address: 0x1007EB40
// Name: public: virtual class ClientClass __near * C_PointCamera::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PointCamera::GetClientClass(C_PointCamera *this)
{
  return &__g_C_PointCameraClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECC0
// Name: class C_PointCamera __near * GetPointCameraList(void)
// Source: json
//------------------------------------------------------------------------------
C_PointCamera *__cdecl GetPointCameraList()
{
  return C_EntityClassList<C_PointCamera>::m_pClassList;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECD0
// Name: public: float C_PointCamera::GetFOV(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PointCamera::GetFOV(C_PointCamera *this)
{
  return this->m_FOV;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECE0
// Name: public: bool C_PointCamera::IsFogEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PointCamera::IsFogEnabled(C_PointCamera *this)
{
  return this->m_bFogEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECF0
// Name: public: void C_PointCamera::GetFogColor(unsigned char __near &,unsigned char __near &,unsigned char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCamera::GetFogColor(
        C_PointCamera *this,
        unsigned __int8 *r,
        unsigned __int8 *g,
        unsigned __int8 *b)
{
  *r = this->m_FogColor.r;
  *g = this->m_FogColor.g;
  *b = this->m_FogColor.b;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED20
// Name: public: float C_PointCamera::GetFogStart(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PointCamera::GetFogStart(C_PointCamera *this)
{
  return this->m_flFogStart;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED30
// Name: public: float C_PointCamera::GetFogEnd(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PointCamera::GetFogEnd(C_PointCamera *this)
{
  return this->m_flFogEnd;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED40
// Name: public: float C_PointCamera::GetFogMaxDensity(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_PointCamera::GetFogMaxDensity(C_PointCamera *this)
{
  return this->m_flFogMaxDensity;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED50
// Name: public: bool C_PointCamera::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PointCamera::IsActive(C_PointCamera *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED70
// Name: public: C_PointCamera::C_PointCamera(void)
// Source: json
//------------------------------------------------------------------------------
C_PointCamera *__thiscall C_PointCamera::C_PointCamera(C_PointCamera *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->m_bActive = false;
  this->m_bFogEnable = false;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PointCamera_vtbl *)&C_PointCamera::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PointCamera::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PointCamera::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PointCamera::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PointCamera::`vftable';
  this->m_pNext = C_EntityClassList<C_PointCamera>::m_pClassList;
  C_EntityClassList<C_PointCamera>::m_pClassList = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007EDC0
// Name: public: virtual C_PointCamera::~C_PointCamera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCamera::~C_PointCamera(C_PointCamera *this)
{
  C_PointCamera *v1; // eax
  C_PointCamera **p_m_pNext; // edx

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PointCamera_vtbl *)&C_PointCamera::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PointCamera::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PointCamera::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PointCamera::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PointCamera::`vftable';
  v1 = C_EntityClassList<C_PointCamera>::m_pClassList;
  p_m_pNext = &C_EntityClassList<C_PointCamera>::m_pClassList;
  if ( C_EntityClassList<C_PointCamera>::m_pClassList != nullptr )
  {
    while ( v1 != this )
    {
      p_m_pNext = &v1->m_pNext;
      v1 = v1->m_pNext;
      if ( v1 == nullptr )
        goto LABEL_4;
    }
    *p_m_pNext = v1->m_pNext;
  }
LABEL_4:
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007EEA0
// Name: public: virtual void C_PointCamera::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCamera::GetToolRecordingState(C_PointCamera *this, KeyValues *msg)
{
  bool v3; // al
  unsigned __int8 b; // al
  unsigned __int8 r; // dl

  C_BaseEntity::GetToolRecordingState(this, msg);
  if ( (_S6_17 & 1) == 0 )
  {
    _S6_17 |= 1u;
    state_3.m_FogColor = 0;
  }
  if ( !this->m_bActive || (v3 = this->IsDormant(this: &this->IClientNetworkable), state_3.m_bActive = true, v3) )
    state_3.m_bActive = false;
  state_3.m_flFOV = this->m_FOV;
  state_3.m_bFogEnabled = this->m_bFogEnable;
  state_3.m_flFogStart = this->m_flFogStart;
  state_3.m_flFogEnd = this->m_flFogEnd;
  b = this->m_FogColor.b;
  r = this->m_FogColor.r;
  state_3.m_FogColor._color[1] = this->m_FogColor.g;
  state_3.m_FogColor._color[0] = r;
  state_3.m_FogColor._color[2] = b;
  state_3.m_FogColor._color[3] = -1;
  KeyValues::SetPtr(this: msg, keyName: "monitor", value: &state_3);
}

//------------------------------------------------------------------------------
// Address: 0x10412E50
// Name: DT_PointCamera::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCamera::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PointCamera::g_RecvTable);
  return atexit(func: DT_PointCamera::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412E70
// Name: DT_PointCamera::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCamera::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PointCamera::ignored>();
  DT_PointCamera::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430830
// Name: DT_PointCamera::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PointCamera::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PointCamera::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1007EE20
// Name: _C_PointCamera_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PointCamera_CreateObject(int entnum, int serialNum)
{
  C_PointCamera *v2; // eax
  C_PointCamera *v3; // eax
  C_PointCamera *v4; // esi

  v2 = (C_PointCamera *)C_BaseEntity::operator new(stAllocateBlock: 0x9A8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PointCamera::C_PointCamera(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412E80
// Name: _dynamic_initializer_for__g_PointCameraList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PointCameraList__()
{
  C_BaseEntityClassList::C_BaseEntityClassList(this: &g_PointCameraList);
  g_PointCameraList.__vftable = (C_EntityClassList<C_PointCamera>_vtbl *)&C_EntityClassList<C_PointCamera>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_PointCameraList__);
}

//------------------------------------------------------------------------------
// Address: 0x10412EA0
// Name: _dynamic_initializer_for__g_CommentaryNodes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CommentaryNodes__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CommentaryNodes__);
}

//------------------------------------------------------------------------------
// Address: 0x10412EB0
// Name: _dynamic_initializer_for____g_C_PointCommentaryNodeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PointCommentaryNodeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PointCommentaryNodeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PointCommentaryNodeClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430840
// Name: _dynamic_atexit_destructor_for__g_PointCameraList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PointCameraList__()
{
  C_BaseEntityClassList::~C_BaseEntityClassList(this: &g_PointCameraList);
}
