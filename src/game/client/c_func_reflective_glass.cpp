// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_reflective_glass.cpp
// Functions: 10
// ============================================================

#include "game\client\c_func_reflective_glass.h"

//------------------------------------------------------------------------------
// Address: 0x100711D0
// Name: public: virtual class ClientClass __near * C_FuncReflectiveGlass::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncReflectiveGlass::GetClientClass(C_FuncReflectiveGlass *this)
{
  return &__g_C_FuncReflectiveGlassClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10071260
// Name: public: virtual C_FuncReflectiveGlass::~C_FuncReflectiveGlass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncReflectiveGlass::~C_FuncReflectiveGlass(C_FuncReflectiveGlass *this)
{
  C_FuncReflectiveGlass *v1; // eax
  C_FuncReflectiveGlass **p_m_pNext; // edx

  this->C_FuncBrush::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FuncReflectiveGlass_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientUnknown'};
  this->C_FuncBrush::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientRenderable'};
  this->C_FuncBrush::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientNetworkable'};
  this->C_FuncBrush::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientThinkable'};
  this->C_FuncBrush::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FuncReflectiveGlass::`vftable';
  v1 = C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList;
  p_m_pNext = &C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList;
  if ( C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList != nullptr )
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
// Address: 0x100712C0
// Name: bool IsReflectiveGlassInView(class CViewSetup const __near &,struct cplane_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall IsReflectiveGlassInView@<al>(const struct model_t *a1@<ebp>, const CViewSetup *view, cplane_t *plane)
{
  C_FuncReflectiveGlass *v3; // edi
  float v4; // eax
  C_FuncReflectiveGlass *v5; // edi
  matrix3x4_t *p_m_rgflCoordinateFrame; // edi
  float y; // xmm2_4
  float x; // xmm0_4
  float z; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float flZNear; // [esp+0h] [ebp-1E0h]
  float flZFar; // [esp+4h] [ebp-1DCh]
  float flFovX; // [esp+8h] [ebp-1D8h]
  float flAspectRatio; // [esp+Ch] [ebp-1D4h]
  _BYTE v18[12]; // [esp+24h] [ebp-1BCh] BYREF
  Vector v19; // [esp+170h] [ebp-70h] BYREF
  Vector vecForward; // [esp+17Ch] [ebp-64h] BYREF
  cplane_t localPlane; // [esp+188h] [ebp-58h] BYREF
  Vector vecMins; // [esp+19Ch] [ebp-44h] BYREF
  Vector vecMaxs; // [esp+1A8h] [ebp-38h] BYREF
  Vector vecOrigin; // [esp+1B4h] [ebp-2Ch] BYREF
  Vector vecWorld; // [esp+1C0h] [ebp-20h]
  int nCount; // [esp+1CCh] [ebp-14h]
  C_FuncReflectiveGlass *m_pNext; // [esp+1D0h] [ebp-10h]
  const struct model_t *pModel; // [esp+1D4h] [ebp-Ch]
  int i; // [esp+1D8h] [ebp-8h]
  int retaddr; // [esp+1E0h] [ebp+0h]

  pModel = a1;
  i = retaddr;
  v3 = C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList;
  m_pNext = C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList;
  if ( C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList == nullptr )
    return 0;
  Frustum_t::Frustum_t(this: (Frustum_t *)v18);
  flAspectRatio = view->m_flAspectRatio;
  flFovX = view->fov;
  flZFar = view->zFar;
  flZNear = view->zNear;
  LODWORD(vecWorld.y) = &view->origin;
  GeneratePerspectiveFrustum(
    a1: (int)v3,
    a2: (int)&view->angles,
    origin: &view->origin,
    angles: &view->angles,
    flZNear,
    flZFar,
    flFovX,
    flAspectRatio,
    frustum: (Frustum_t *)v18);
  AngleVectors(angles: &view->angles, forward: &v19, right: nullptr, up: nullptr);
  while ( 1 )
  {
    if ( !v3->IsDormant(this: &v3->IClientNetworkable) )
    {
      v3->GetRenderBoundsWorldspace(this: &v3->IClientRenderable, a2: (Vector *)&localPlane.normal.z, a3: &vecMins);
      if ( !Frustum_t::CullBox(this: (Frustum_t *)v18, mins: (const Vector *)&localPlane.normal.z, maxs: &vecMins) )
      {
        v4 = COERCE_FLOAT((int)v3->GetModel(this: &v3->IClientRenderable));
        v5 = m_pNext;
        vecWorld.z = v4;
        C_BaseEntity::CalcAbsolutePosition(this: m_pNext);
        p_m_rgflCoordinateFrame = &v5->m_rgflCoordinateFrame;
        LODWORD(vecWorld.x) = modelinfo->GetBrushModelPlaneCount(
                                this: modelinfo,
                                a2: (const struct model_t *)LODWORD(vecWorld.z));
        nCount = 0;
        if ( SLODWORD(vecWorld.x) > 0 )
          break;
      }
LABEL_10:
      v3 = m_pNext;
    }
    m_pNext = v3->m_pNext;
    if ( m_pNext == nullptr )
      return 0;
    v3 = m_pNext;
  }
  while ( 1 )
  {
    modelinfo->GetBrushModelPlane(
      this: modelinfo,
      a2: (const struct model_t *)LODWORD(vecWorld.z),
      a3: nCount,
      a4: (cplane_t *)&vecForward,
      a5: &vecMaxs);
    VectorRotate(in1: &vecForward.x, in2: p_m_rgflCoordinateFrame, out: &plane->normal.x);
    y = plane->normal.y;
    x = plane->normal.x;
    z = plane->normal.z;
    v10 = (float)((float)((float)(x * x) + (float)(y * y)) + (float)(z * z)) * localPlane.normal.x;
    plane->dist = v10;
    plane->dist = (float)((float)((float)(x * p_m_rgflCoordinateFrame->m_flMatVal[0][3])
                                + (float)(y * p_m_rgflCoordinateFrame->m_flMatVal[1][3]))
                        + (float)(z * p_m_rgflCoordinateFrame->m_flMatVal[2][3]))
                + v10;
    VectorTransform(in1: &vecMaxs.x, in2: p_m_rgflCoordinateFrame, out: &vecOrigin.x);
    v11 = plane->normal.y;
    v12 = plane->normal.z;
    if ( plane->dist < (float)((float)((float)(*(float *)LODWORD(vecWorld.y) * plane->normal.x)
                                     + (float)(*(float *)(LODWORD(vecWorld.y) + 4) * v11))
                             + (float)(*(float *)(LODWORD(vecWorld.y) + 8) * v12))
      && (float)((float)((float)(plane->normal.x * (float)(vecOrigin.x - *(float *)LODWORD(vecWorld.y)))
                       + (float)(v11 * (float)(vecOrigin.y - *(float *)(LODWORD(vecWorld.y) + 4))))
               + (float)(v12 * (float)(vecOrigin.z - *(float *)(LODWORD(vecWorld.y) + 8)))) < 0.0 )
    {
      return 1;
    }
    if ( ++nCount >= SLODWORD(vecWorld.x) )
      goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412330
// Name: DT_FuncReflectiveGlass::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncReflectiveGlass::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncReflectiveGlass::g_RecvTable);
  return atexit(func: DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412350
// Name: DT_FuncReflectiveGlass::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncReflectiveGlass::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncReflectiveGlass::ignored>();
  DT_FuncReflectiveGlass::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430370
// Name: DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncReflectiveGlass::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncReflectiveGlass::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10071540
// Name: _C_FuncReflectiveGlass_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncReflectiveGlass_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_FuncReflectiveGlass *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = (C_FuncReflectiveGlass *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->C_FuncBrush::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FuncReflectiveGlass_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientUnknown'};
  v3->C_FuncBrush::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientRenderable'};
  v3->C_FuncBrush::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientNetworkable'};
  v3->C_FuncBrush::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FuncReflectiveGlass::`vftable'{for `IClientThinkable'};
  v3->C_FuncBrush::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FuncReflectiveGlass::`vftable';
  v3->m_pNext = C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList;
  C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList = v3;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412360
// Name: _dynamic_initializer_for__g_ReflectiveGlassList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ReflectiveGlassList__()
{
  C_BaseEntityClassList::C_BaseEntityClassList(this: &g_ReflectiveGlassList);
  g_ReflectiveGlassList.__vftable = (C_EntityClassList<C_FuncReflectiveGlass>_vtbl *)&C_EntityClassList<C_FuncReflectiveGlass>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_ReflectiveGlassList__);
}

//------------------------------------------------------------------------------
// Address: 0x10412380
// Name: _dynamic_initializer_for____g_C_FuncRotatingClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncRotatingClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncRotatingClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncRotatingClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430380
// Name: _dynamic_atexit_destructor_for__g_ReflectiveGlassList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ReflectiveGlassList__()
{
  C_BaseEntityClassList::~C_BaseEntityClassList(this: &g_ReflectiveGlassList);
}
