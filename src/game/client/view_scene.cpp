// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/view_scene.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10192E20
// Name: int ScreenTransform(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ScreenTransform(const Vector *point, Vector *screen)
{
  float *v2; // eax
  float v3; // xmm1_4
  float v5; // xmm0_4

  v2 = (float *)engine->WorldToScreenMatrix(this: engine);
  screen->x = (float)((float)((float)(v2[1] * point->y) + (float)(*v2 * point->x)) + (float)(v2[2] * point->z)) + v2[3];
  screen->y = (float)((float)((float)(v2[5] * point->y) + (float)(v2[4] * point->x)) + (float)(v2[6] * point->z))
            + v2[7];
  v3 = (float)((float)((float)(v2[13] * point->y) + (float)(v2[12] * point->x)) + (float)(v2[14] * point->z)) + v2[15];
  screen->z = 0.0;
  if ( v3 >= 0.001 )
  {
    v5 = (float)(1.0 / v3) * screen->y;
    screen->x = screen->x * (float)(1.0 / v3);
    screen->y = v5;
    return 0;
  }
  else
  {
    screen->x = screen->x * 100000.0;
    screen->y = screen->y * 100000.0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192F30
// Name: void UpdateFullScreenDepthTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateFullScreenDepthTexture(int a1@<edi>, int a2@<esi>)
{
  ITexture *FullFrameDepthTexture; // edi
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v4; // esi
  IMaterial *v5; // edi
  int v6; // ebx
  int v7; // eax
  Rect_t viewportRect; // [esp+0h] [ebp-14h] BYREF
  ITexture *pDepthTex; // [esp+10h] [ebp-4h]

  if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) > 90 )
  {
    FullFrameDepthTexture = GetFullFrameDepthTexture();
    GetRenderContext = materials->GetRenderContext;
    pDepthTex = FullFrameDepthTexture;
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int))GetRenderContext)(a1: materials, a2: a1, a3: a2);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, Rect_t *, int *))(*(_DWORD *)v4 + 156))(a1: v4, a2: &viewportRect, a3: &viewportRect.y);
    (*(void (__thiscall **)(int, ITexture *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 452))(
      a1: v4,
      a2: FullFrameDepthTexture,
      a3: 0,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 692))(a1: v4, a2: 1);
    if ( r_depthoverlay.m_pParent != nullptr && r_depthoverlay.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = materials->FindMaterial(this: materials, a2: "debug/showz", a3: "Other textures", a4: 1, a5: 0);
      v6 = (int)v5->FindVar(this: v5, a2: "$basetexture", a3: nullptr, a4: false);
      v7 = (int)v5->FindVar(this: v5, a2: "$ALPHADEPTH", a3: nullptr, a4: false);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: 1);
      (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v6 + 60))(a1: v6, a2: pDepthTex);
      (*(void (__thiscall **)(int, int, _DWORD, int))(*(_DWORD *)v4 + 300))(a1: v4, a2: 1, a3: 0, a4: 1);
      (*(void (__thiscall **)(int, IMaterial *))(*(_DWORD *)v4 + 304))(a1: v4, a2: v5);
      (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v4 + 300))(a1: v4, a2: 0, a3: 1, a4: 1);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}
