// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/renderutils.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1009C8B0
// Name: void DrawBoundsText(class CRender2D __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl DrawBoundsText(CRender2D *pRender, const Vector *Mins, CRender2D *Maxs, char nFlags)
{
  CMapView *m_pView; // eax
  bool *p_m_bActive; // ebx
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float x; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // edx
  wchar_t string[4]; // [esp+8h] [ebp-50h] BYREF
  __int64 extentText_24; // [esp+28h] [ebp-30h] OVERLAPPED BYREF
  Vector Center; // [esp+30h] [ebp-28h]
  Vector Extents; // [esp+3Ch] [ebp-1Ch] BYREF
  Vector2D projCenter; // [esp+48h] [ebp-10h] BYREF
  Vector2D projMaxs; // [esp+50h] [ebp-8h] BYREF

  m_pView = pRender->m_pView;
  if ( m_pView != nullptr )
    p_m_bActive = &m_pView[-4].m_bActive;
  else
    p_m_bActive = nullptr;
  y = Mins->y;
  z = Mins->z;
  v8 = *(float *)&Maxs->__vftable - Mins->x;
  v9 = *(float *)&Maxs->m_pView - y;
  v10 = y + *(float *)&Maxs->m_pView;
  v11 = *(float *)&Maxs->m_DefaultFont - z;
  v12 = z + *(float *)&Maxs->m_DefaultFont;
  *(float *)&extentText_24 = (float)(Mins->x + *(float *)&Maxs->__vftable) * 0.5;
  *((float *)&extentText_24 + 1) = v10 * 0.5;
  Center.x = v12 * 0.5;
  Center.y = fabs(v8);
  Center.z = fabs(v9);
  Extents.x = fabs(v11);
  CRender::TransformPoint(this: pRender, vClient: &projMaxs, vWorld: Mins);
  CRender::TransformPoint(this: pRender, vClient: &projCenter, vWorld: (const Vector *)Maxs);
  CRender::TransformPoint(this: pRender, vClient: (Vector2D *)&Extents.y, vWorld: (const Vector *)&extentText_24);
  x = projMaxs.x;
  if ( projMaxs.x > projCenter.x )
  {
    projMaxs.x = projCenter.x;
    projCenter.x = x;
  }
  v14 = projMaxs.y;
  if ( projMaxs.y > projCenter.y )
  {
    projMaxs.y = projCenter.y;
    projCenter.y = v14;
  }
  CRender::SetTextColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu, a: 0xFFu);
  sprintf((char *)string, format: "%.1f", *(&Center.y + *((_DWORD *)p_m_bActive + 46)));
  if ( (nFlags & 1) != 0 )
  {
    v15 = projMaxs.y - 12.0;
    v16 = 72;
  }
  else
  {
    v15 = projCenter.y + 12.0;
    v16 = 68;
  }
  CRender::DrawTextA(this: pRender, text: string, x: (int)Extents.y, y: (int)v15, nFlags: v16);
  sprintf((char *)string, format: "%.1f", *(&Center.y + *((_DWORD *)p_m_bActive + 47)));
  if ( (nFlags & 4) != 0 )
  {
    v17 = projMaxs.x - 12.0;
    v18 = 160;
  }
  else
  {
    v17 = projCenter.x + 12.0;
    v18 = 144;
  }
  CRender::DrawTextA(this: pRender, text: string, x: (int)v17, y: (int)Extents.z, nFlags: v18);
}
