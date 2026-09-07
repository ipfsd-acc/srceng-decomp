// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_prop_hallucination.cpp
// Functions: 10
// ============================================================

#include "game\client\c_prop_hallucination.h"

//------------------------------------------------------------------------------
// Address: 0x1001C140
// Name: public: virtual void C_Prop_Hallucination::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_Prop_Hallucination::UpdateOnRemove(C_BaseViewModel *this)
{
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080DF0
// Name: public: virtual class ClientClass __near * C_Prop_Hallucination::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Prop_Hallucination::GetClientClass(C_Prop_Hallucination *this)
{
  return &__g_C_Prop_HallucinationClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10080EC0
// Name: public: virtual void C_Prop_Hallucination::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Prop_Hallucination::OnDataChanged(C_Prop_Hallucination *this, DataUpdateType_t type)
{
  int v3; // [esp+0h] [ebp-4h]

  if ( BYTE1(this->m_fLastStateChangeTime) == 0 )
  {
    if ( LOBYTE(this->m_fLastStateChangeTime) != 0 && *(double *)&this->m_bVisibleInAnyViewLastFrame != 0.0 )
      *(double *)&this->m_bVisibleInAnyViewLastFrame = _Plat_FloatTime(a1: v3);
    LOBYTE(this->m_fLastStateChangeTime) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080FB0
// Name: public: virtual void C_Prop_Hallucination::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Prop_Hallucination::Spawn(C_Prop_Hallucination *this)
{
  if ( C_Prop_Hallucination::sm_OcclusionProxyMaterial.m_pMaterial == nullptr )
    CMaterialReference::Init(
      this: &C_Prop_Hallucination::sm_OcclusionProxyMaterial,
      pMaterialName: "engine/occlusionproxy",
      pTextureGroupName: "ClientEffect textures",
      bComplain: true);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10080FE0
// Name: public: virtual int C_Prop_Hallucination::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_Prop_Hallucination::DrawModel@<eax>(
        C_Prop_Hallucination *this@<ecx>,
        int a2@<edi>,
        int flags,
        const RenderableInstance_t *instance)
{
  view_id_t v6; // eax
  char *m_pManagedData; // eax
  char *v8; // ecx
  double v9; // xmm0_8
  bool v10; // bl
  int v11; // ebx

  if ( CurrentViewID() == VIEW_SHADOW_DEPTH_TEXTURE && BYTE4(this->m_fLastStateChangeTime) != 0 )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  v6 = CurrentViewID();
  if ( !IsMainView(id: v6) )
    return 0;
  if ( (flags & 1) != 0 )
  {
    m_pManagedData = (char *)this->m_OcclusionSet.m_pManagedData;
    v8 = *(char **)(gpGlobals.m_Index + 4);
    if ( m_pManagedData != v8 )
    {
      v9 = *(double *)(&this->m_bVisibleInAnyViewLastFrame + 4);
      v10 = m_pManagedData == v8 - 1;
      if ( BYTE4(this->m_fLastStateChangeTime) != 0 )
      {
        if ( v9 == 0.0 )
        {
          if ( m_pManagedData == v8 - 1
            && COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(this: (COcclusionQuerySet *)&this->m_vecRenderOriginOverride + 3) > 0 )
          {
            *(double *)(&this->m_bVisibleInAnyViewLastFrame + 4) = _Plat_FloatTime(a1: a2);
          }
        }
        else if ( _Plat_FloatTime(a1: a2) - *(double *)(&this->m_bVisibleInAnyViewLastFrame + 4) > *(float *)&this->m_bVisibleEligible )
        {
          BYTE4(this->m_fLastStateChangeTime) = 0;
        }
      }
      else if ( (v9 == 0.0
              || _Plat_FloatTime(a1: a2) - *(double *)(&this->m_bVisibleInAnyViewLastFrame + 4) > this->m_fVisibleTime)
             && (COcclusionQuerySet::QueryNumPixelsRenderedForAllViewsLastFrame(this: (COcclusionQuerySet *)&this->m_vecRenderOriginOverride + 3) == 0
              || !v10) )
      {
        BYTE4(this->m_fLastStateChangeTime) = 1;
        *(_QWORD *)(&this->m_bVisibleInAnyViewLastFrame + 4) = 0;
      }
    }
  }
  if ( (flags & 1) == 0 )
    return C_BaseAnimating::DrawModel(this, flags, instance);
  if ( BYTE4(this->m_fLastStateChangeTime) == 0 )
    modelrender->ForcedMaterialOverride(
      this: modelrender,
      a2: C_Prop_Hallucination::sm_OcclusionProxyMaterial.m_pMaterial,
      a3: OVERRIDE_NORMAL);
  this->m_OcclusionSet.m_pManagedData = *(void **)(gpGlobals.m_Index + 4);
  COcclusionQuerySet::BeginQueryDrawing(this: (COcclusionQuerySet *)&this->m_vecRenderOriginOverride + 3);
  v11 = C_BaseAnimating::DrawModel(this, flags, instance);
  COcclusionQuerySet::EndQueryDrawing(this: (COcclusionQuerySet *)&this->m_vecRenderOriginOverride + 3);
  if ( BYTE4(this->m_fLastStateChangeTime) == 0 )
    modelrender->ForcedMaterialOverride(this: modelrender, a2: nullptr, a3: OVERRIDE_NORMAL);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10412FC0
// Name: DT_Prop_Hallucination::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Prop_Hallucination::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Prop_Hallucination::g_RecvTable);
  return atexit(func: DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412FE0
// Name: DT_Prop_Hallucination::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Prop_Hallucination::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Prop_Hallucination::ignored>();
  DT_Prop_Hallucination::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104308A0
// Name: DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Prop_Hallucination::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10080F10
// Name: _C_Prop_Hallucination_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COcclusionQuerySet *__cdecl C_Prop_Hallucination_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimating *v2; // eax
  COcclusionQuerySet *v3; // esi

  v2 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
  v3 = (COcclusionQuerySet *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseAnimating::C_BaseAnimating(this: v2);
  v3->m_pManagedData = &C_Prop_Hallucination::`vftable'{for `IClientUnknown'};
  v3[1].m_pManagedData = &C_Prop_Hallucination::`vftable'{for `IClientRenderable'};
  v3[2].m_pManagedData = &C_Prop_Hallucination::`vftable'{for `IClientNetworkable'};
  v3[3].m_pManagedData = &C_Prop_Hallucination::`vftable'{for `IClientThinkable'};
  v3[4].m_pManagedData = &C_Prop_Hallucination::`vftable';
  COcclusionQuerySet::COcclusionQuerySet(this: v3 + 814);
  (*((void (__thiscall **)(COcclusionQuerySet *, int, int))v3->m_pManagedData + 43))(a1: v3, a2: entnum, a3: serialNum);
  return v3 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x10412FF0
// Name: _dynamic_initializer_for____g_C_DynamicPropClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DynamicPropClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DynamicPropClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DynamicPropClientClass;
  return result;
}
