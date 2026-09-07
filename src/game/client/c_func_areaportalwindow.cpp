// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_areaportalwindow.cpp
// Functions: 6
// ============================================================

#include "game\client\c_func_areaportalwindow.h"

//------------------------------------------------------------------------------
// Address: 0x1006BAE0
// Name: public: virtual class ClientClass __near * C_FuncAreaPortalWindow::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncAreaPortalWindow::GetClientClass(C_FuncAreaPortalWindow *this)
{
  return &__g_C_FuncAreaPortalWindowClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006BC40
// Name: private: float C_FuncAreaPortalWindow::GetDistanceBlend(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_FuncAreaPortalWindow::GetDistanceBlend(C_FuncAreaPortalWindow *this)
{
  const Vector *v2; // eax
  C_BasePlayer *LocalPlayer; // eax
  float m_flFadeStartDist; // xmm2_4
  float m_flFadeDist; // xmm1_4
  float m_flTranslucencyLimit; // xmm3_4
  float v8; // xmm0_4
  float flDist; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v2 = CurrentViewOrigin();
  flDist = CCollisionProperty::CalcDistanceFromPoint(
             this: &this->m_Collision,
             a2: COERCE_FLOAT(&savedregs),
             vecWorldPt: v2);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    flDist = C_BasePlayer::GetFOVDistanceAdjustFactor(this: LocalPlayer) * flDist;
  m_flFadeStartDist = this->m_flFadeStartDist;
  m_flFadeDist = this->m_flFadeDist;
  m_flTranslucencyLimit = this->m_flTranslucencyLimit;
  if ( m_flFadeStartDist == m_flFadeDist )
  {
    if ( (float)(flDist - m_flFadeDist) < 0.0 )
      return m_flTranslucencyLimit;
    else
      return 1.0;
  }
  else
  {
    v8 = (float)(flDist - m_flFadeStartDist) / (float)(m_flFadeDist - m_flFadeStartDist);
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    return (float)((float)((float)(1.0 - m_flTranslucencyLimit) * v8) + m_flTranslucencyLimit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BD10
// Name: public: virtual int C_FuncAreaPortalWindow::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_FuncAreaPortalWindow::DrawModel@<eax>(
        C_FuncAreaPortalWindow *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  IVModelInfoClient_vtbl *v7; // esi
  IClientThinkable *v8; // eax
  char *v9; // esi
  double DistanceBlend; // st7
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const struct model_t *v15; // edi
  int v16; // eax
  int v17; // eax
  float flBlendAlpha; // [esp+2Ch] [ebp-4h]
  IVRenderView_vtbl *flagsa; // [esp+38h] [ebp+8h]
  IVRenderView_vtbl *flagsb; // [esp+38h] [ebp+8h]

  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0 || this->GetClientThinkable(this) == nullptr )
    return 0;
  v7 = modelinfo->__vftable;
  v8 = this->GetClientThinkable(this);
  if ( v7->GetModelType(this: modelinfo, a2: (const struct model_t *)v8) != 1 )
    return 0;
  v9 = (char *)this - 4;
  DistanceBlend = C_FuncAreaPortalWindow::GetDistanceBlend(this: (C_FuncAreaPortalWindow *)((char *)this - 4));
  if ( DistanceBlend == 0.0 )
    return 0;
  flBlendAlpha = DistanceBlend;
  ((void (__stdcall *)(_DWORD, int, int))render->SetBlend)(a1: LODWORD(flBlendAlpha), a2, a3);
  v11 = 0;
  if ( (flags & 8) != 0 )
    v11 = (flags < 0) + 1;
  flagsa = render->__vftable;
  v12 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 44))(a1: (char *)this - 4, a2: v11);
  v13 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 40))(a1: (char *)this - 4, a2: v12);
  v14 = ((int (__thiscall *)(C_FuncAreaPortalWindow *, int))this->GetClientThinkable)(a1: this, a2: v13);
  ((void (__thiscall *)(IVRenderView *, char *, int))flagsa->DrawBrushModelEx)(
    a1: render,
    a2: (char *)this - 4,
    a3: v14);
  if ( this->m_flTranslucencyLimit >= 0.0 )
  {
    ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
    v15 = modelinfo->GetModel(this: modelinfo, a2: LODWORD(this->m_flTranslucencyLimit));
    if ( v15 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v15) == 1 )
    {
      flagsb = render->__vftable;
      v16 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 44))(a1: v9, a2: v11);
      v17 = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 40))(a1: v9, a2: v16);
      ((void (__thiscall *)(IVRenderView *, char *, const struct model_t *, int))flagsb->DrawBrushModelEx)(
        a1: render,
        a2: v9,
        a3: v15,
        a4: v17);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10411F90
// Name: DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncAreaPortalWindow::g_RecvTable);
  return atexit(func: DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411FB0
// Name: DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncAreaPortalWindow::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncAreaPortalWindow::ignored>();
  DT_FuncAreaPortalWindow::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104302A0
// Name: DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncAreaPortalWindow::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncAreaPortalWindow::g_RecvTable);
}
