// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_colors.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102FFF50
// Name: void NavDrawLine(class Vector const __near &,class Vector const __near &,enum NavEditColor)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavDrawLine(const Vector *from, const Vector *to, Color navColor)
{
  Color v3; // ebx
  float v4; // xmm1_4
  float v5; // xmm1_4
  Vector origin; // [esp+10h] [ebp-18h] BYREF
  Vector target; // [esp+1Ch] [ebp-Ch] BYREF

  v3 = NavColors[*(_DWORD *)&navColor];
  v4 = to->z + 1.0;
  target.x = to->x;
  target.y = to->y;
  target.z = v4;
  origin.x = from->x;
  origin.y = from->y;
  origin.z = from->z + 1.0;
  NDebugOverlay::Line(
    &origin,
    &target,
    r: v3._color[0] >> 1,
    g: v3._color[1] >> 1,
    b: v3._color[2] >> 1,
    noDepthTest: 1,
    duration: 0.1);
  v5 = to->z + 1.0;
  origin.x = to->x;
  origin.y = to->y;
  origin.z = v5;
  target.x = from->x;
  target.y = from->y;
  target.z = from->z + 1.0;
  NDebugOverlay::Line(
    origin: &target,
    target: &origin,
    r: v3._color[0],
    g: v3._color[1],
    b: v3._color[2],
    noDepthTest: 0,
    duration: 0.15000001);
}

//------------------------------------------------------------------------------
// Address: 0x10300080
// Name: void NavDrawTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,enum NavEditColor)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavDrawTriangle(const Vector *point1, const Vector *point2, const Vector *point3, NavEditColor navColor)
{
  NavDrawLine(from: point1, to: point2, (Color)navColor);
  NavDrawLine(from: point2, to: point3, (Color)navColor);
  NavDrawLine(from: point1, to: point3, (Color)navColor);
}

//------------------------------------------------------------------------------
// Address: 0x103000C0
// Name: void NavDrawHorizontalArrow(class Vector const __near &,class Vector const __near &,float,enum NavEditColor)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavDrawHorizontalArrow(const Vector *from, const Vector *to, float width, Color navColor)
{
  Color v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm1_4
  Vector startPos; // [esp+28h] [ebp-18h] BYREF
  Vector endPos; // [esp+34h] [ebp-Ch] BYREF

  v4 = NavColors[*(_DWORD *)&navColor];
  v5 = to->z + 1.0;
  endPos.x = to->x;
  endPos.y = to->y;
  endPos.z = v5;
  startPos.x = from->x;
  startPos.y = from->y;
  startPos.z = from->z + 1.0;
  NDebugOverlay::HorzArrow(
    &startPos,
    &endPos,
    width,
    r: v4._color[0] >> 1,
    g: v4._color[1] >> 1,
    b: v4._color[2] >> 1,
    a: 255,
    noDepthTest: 1,
    flDuration: 0.01023);
  v6 = to->z + 1.0;
  startPos.x = to->x;
  startPos.y = to->y;
  startPos.z = v6;
  endPos.x = from->x;
  endPos.y = from->y;
  endPos.z = from->z + 1.0;
  NDebugOverlay::HorzArrow(
    startPos: &endPos,
    endPos: &startPos,
    width,
    r: v4._color[0],
    g: v4._color[1],
    b: v4._color[2],
    a: 255,
    noDepthTest: 0,
    flDuration: 0.01023);
}

//------------------------------------------------------------------------------
// Address: 0x10300210
// Name: void NavDrawDashedLine(class Vector const __near &,class Vector const __near &,enum NavEditColor)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavDrawDashedLine(const Vector *from, const Vector *to, Color navColor)
{
  Color v3; // ebx
  double v4; // st7
  float v5; // xmm2_4
  int v6; // esi
  unsigned int v7; // ebx
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  float x; // xmm3_4
  float z; // xmm5_4
  float y; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  Vector v16; // [esp+1Ch] [ebp-6Ch] BYREF
  Vector v17; // [esp+28h] [ebp-60h] BYREF
  Vector origin; // [esp+34h] [ebp-54h] BYREF
  Vector target; // [esp+40h] [ebp-48h] BYREF
  Vector start; // [esp+4Ch] [ebp-3Ch]
  Vector unit; // [esp+58h] [ebp-30h] BYREF
  float distance; // [esp+64h] [ebp-24h]
  int r; // [esp+68h] [ebp-20h]
  float v24; // [esp+6Ch] [ebp-1Ch]
  float v25; // [esp+70h] [ebp-18h]
  float v26; // [esp+74h] [ebp-14h]
  float v27; // [esp+78h] [ebp-10h]
  float v28; // [esp+7Ch] [ebp-Ch]
  float v29; // [esp+80h] [ebp-8h]
  unsigned int v30; // [esp+84h] [ebp-4h]
  float totalDistance; // [esp+94h] [ebp+Ch]
  Color color; // [esp+98h] [ebp+10h]
  Color colora; // [esp+98h] [ebp+10h]

  v3 = NavColors[*(_DWORD *)&navColor];
  unit.x = to->x - from->x;
  unit.y = to->y - from->y;
  color = v3;
  unit.z = to->z - from->z;
  v4 = VectorNormalize(vec: &unit);
  totalDistance = v4;
  v5 = 0.0;
  if ( v4 > 0.0 )
  {
    v6 = v3._color[2];
    v7 = v3._color[1];
    v8 = v7 >> 1;
    v9 = color._color[2] >> 1;
    r = color._color[0];
    v10 = color._color[0] >> 1;
    v30 = v7 >> 1;
    for ( colora = (Color)v10; ; v10 = (int)colora )
    {
      x = from->x;
      z = from->z;
      start.x = from->x + (float)(unit.x * v5);
      y = from->y;
      start.y = y + (float)(unit.y * v5);
      v14 = z + (float)(unit.z * v5);
      v15 = v5 + 7.0;
      if ( totalDistance <= (float)(v5 + 7.0) )
        v15 = v4;
      v26 = start.x;
      origin.x = start.x;
      v25 = start.y;
      origin.y = start.y;
      distance = v5 + 10.0;
      v29 = x + (float)(unit.x * v15);
      target.x = v29;
      v28 = y + (float)(unit.y * v15);
      target.y = v28;
      v27 = (float)(z + (float)(unit.z * v15)) + 1.0;
      target.z = v27;
      v24 = v14 + 1.0;
      origin.z = v14 + 1.0;
      NDebugOverlay::Line(&origin, &target, r: v10, g: v8, b: v9, noDepthTest: 1, duration: 0.01023);
      v17.x = v29;
      v17.y = v28;
      v17.z = v27;
      v16.x = v26;
      v16.y = v25;
      v16.z = v24;
      NDebugOverlay::Line(origin: &v16, target: &v17, r, g: v7, b: v6, noDepthTest: 0, duration: 0.01023);
      v5 = distance;
      if ( totalDistance <= distance )
        break;
      v8 = v30;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300430
// Name: void NavDrawVolume(class Vector const __near &,class Vector const __near &,int,enum NavEditColor)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NavDrawVolume(const Vector *vMin, const Vector *vMax, int zMidline, NavEditColor navColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float z; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  Vector from; // [esp+8h] [ebp-18h] BYREF
  Vector to; // [esp+14h] [ebp-Ch] BYREF

  y = vMax->y;
  x = vMax->x;
  to.x = vMin->x;
  to.y = y;
  to.z = (float)zMidline;
  from.x = x;
  from.y = y;
  from.z = (float)zMidline;
  NavDrawLine(&from, &to, (Color)navColor);
  v6 = vMax->y;
  from.x = vMin->x;
  from.y = v6;
  to.x = from.x;
  v7 = vMin->y;
  from.z = (float)zMidline;
  to.y = v7;
  to.z = (float)zMidline;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v8 = vMin->x;
  from.x = vMax->x;
  from.y = vMin->y;
  from.z = (float)zMidline;
  to.x = v8;
  to.y = from.y;
  to.z = (float)zMidline;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v9 = vMin->y;
  from.x = vMax->x;
  from.y = v9;
  to.x = from.x;
  v10 = vMax->y;
  from.z = (float)zMidline;
  to.y = v10;
  to.z = (float)zMidline;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  z = vMin->z;
  v12 = vMax->x;
  from.x = vMin->x;
  from.y = vMax->y;
  from.z = z;
  to.x = v12;
  to.y = from.y;
  to.z = z;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v13 = vMax->y;
  from.x = vMin->x;
  from.y = v13;
  v14 = vMin->z;
  to.x = from.x;
  v15 = vMin->y;
  from.z = v14;
  to.y = v15;
  to.z = v14;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v16 = vMin->z;
  v17 = vMin->x;
  from.x = vMax->x;
  from.y = vMin->y;
  from.z = v16;
  to.x = v17;
  to.y = from.y;
  to.z = v16;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v18 = vMin->y;
  from.x = vMax->x;
  from.y = v18;
  v19 = vMin->z;
  to.x = from.x;
  v20 = vMax->y;
  from.z = v19;
  to.y = v20;
  to.z = v19;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v21 = vMax->z;
  v22 = vMax->x;
  from.x = vMin->x;
  from.y = vMax->y;
  from.z = v21;
  to.x = v22;
  to.y = from.y;
  to.z = v21;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v23 = vMax->y;
  from.x = vMin->x;
  from.y = v23;
  v24 = vMax->z;
  to.x = from.x;
  v25 = vMin->y;
  from.z = v24;
  to.y = v25;
  to.z = v24;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v26 = vMax->z;
  v27 = vMin->x;
  from.x = vMax->x;
  from.y = vMin->y;
  from.z = v26;
  to.x = v27;
  to.y = from.y;
  to.z = v26;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v28 = vMin->y;
  from.x = vMax->x;
  from.y = v28;
  v29 = vMax->z;
  to.x = from.x;
  v30 = vMax->y;
  from.z = v29;
  to.y = v30;
  to.z = v29;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v31 = vMax->y;
  v32 = vMax->z;
  from.x = vMax->x;
  to.x = from.x;
  v33 = vMin->z;
  from.y = v31;
  from.z = v32;
  to.y = v31;
  to.z = v33;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v34 = vMin->y;
  v35 = vMax->z;
  from.x = vMin->x;
  to.x = from.x;
  v36 = vMin->z;
  from.y = v34;
  from.z = v35;
  to.y = v34;
  to.z = v36;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v37 = vMin->y;
  v38 = vMax->z;
  from.x = vMax->x;
  to.x = from.x;
  v39 = vMin->z;
  from.y = v37;
  from.z = v38;
  to.y = v37;
  to.z = v39;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
  v40 = vMax->y;
  v41 = vMax->z;
  from.x = vMin->x;
  to.x = from.x;
  v42 = vMin->z;
  from.y = v40;
  from.z = v41;
  to.y = v40;
  to.z = v42;
  NavDrawLine(from: &to, to: &from, (Color)navColor);
}
