// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ndebugoverlay.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10177800
// Name: void UTIL_DrawOverlayLines(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DrawOverlayLines()
{
  const Vector **v0; // esi

  if ( m_nDebugOverlayIndex != -1 )
  {
    v0 = (const Vector **)m_debugOverlayLine;
    do
    {
      if ( BYTE1((*v0)[3].x) != 0 )
        NDebugOverlay::Line(
          origin: *v0,
          target: *v0 + 1,
          r: LODWORD((*v0)[2].x),
          g: LODWORD((*v0)[2].y),
          b: LODWORD((*v0)[2].z),
          noDepthTest: LOBYTE((*v0)[3].x),
          duration: 0.0);
      ++v0;
    }
    while ( (int)v0 < (int)&clear_debug_overlays_command );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10177850
// Name: void DebugDrawLine(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugDrawLine(
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        int r,
        int g,
        int b,
        int test,
        float duration)
{
  float v7; // xmm1_4
  float y; // xmm0_4
  float v9; // xmm1_4
  Vector origin; // [esp+4h] [ebp-18h] BYREF
  Vector target; // [esp+10h] [ebp-Ch] BYREF

  v7 = vecAbsEnd->z + 0.1;
  target.x = vecAbsEnd->x;
  y = vecAbsEnd->y;
  target.z = v7;
  origin.x = vecAbsStart->x;
  origin.y = vecAbsStart->y;
  v9 = vecAbsStart->z + 0.1;
  target.y = y;
  origin.z = v9;
  NDebugOverlay::Line(&origin, &target, r, g, b, noDepthTest: test, duration);
}

//------------------------------------------------------------------------------
// Address: 0x101778E0
// Name: clear_debug_overlays
// Source: json
//------------------------------------------------------------------------------
void __cdecl clear_debug_overlays()
{
  CBaseEntity *i; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          i != nullptr;
          i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
    {
      i->m_debugOverlays = 0;
    }
    if ( debugoverlay != nullptr )
      debugoverlay->ClearAllOverlays(this: debugoverlay);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10177930
// Name: struct OverlayLine_t __near * GetDebugOverlayLine(void)
// Source: json
//------------------------------------------------------------------------------
OverlayLine_t *__cdecl GetDebugOverlayLine()
{
  int v0; // eax
  OverlayLine_t **v1; // esi
  OverlayLine_t *v2; // eax
  int v3; // eax
  int v4; // eax

  v0 = m_nDebugOverlayIndex;
  if ( m_nDebugOverlayIndex == -1 )
  {
    v1 = m_debugOverlayLine;
    do
    {
      v2 = (OverlayLine_t *)operator new(nSize: 0x28u);
      *v1 = v2;
      v2->noDepthTest = true;
      v3 = (int)*v1++;
      *(_BYTE *)(v3 + 37) = 0;
    }
    while ( (int)v1 < (int)&clear_debug_overlays_command );
    v0 = 0;
  }
  v4 = v0 + 1;
  m_nDebugOverlayIndex = v4;
  if ( v4 != 20 )
    return (OverlayLine_t *)dword_1062BD04[v4];
  m_nDebugOverlayIndex = 0;
  return (OverlayLine_t *)unk_1062BD54;
}

//------------------------------------------------------------------------------
// Address: 0x10177990
// Name: void UTIL_AddDebugLine(class Vector const __near &,class Vector const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_AddDebugLine(const Vector *startPos, const Vector *endPos, bool noDepthTest, bool testLOS)
{
  OverlayLine_t *DebugOverlayLine; // esi
  CGameTrace tr; // [esp+4h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+58h] [ebp+0h] BYREF

  DebugOverlayLine = GetDebugOverlayLine();
  DebugOverlayLine->origin = *startPos;
  DebugOverlayLine->dest = *endPos;
  DebugOverlayLine->noDepthTest = noDepthTest;
  DebugOverlayLine->draw = true;
  if ( testLOS
    && ((UTIL_TraceLine(
           a1: &savedregs,
           a2: (int)DebugOverlayLine,
           vecAbsStart: &DebugOverlayLine->origin,
           vecAbsEnd: &DebugOverlayLine->dest,
           mask: 0x4041u,
           ignore: nullptr,
           collisionGroup: 0,
           ptr: &tr),
         tr.startsolid)
     || tr.fraction < 1.0) )
  {
    DebugOverlayLine->r = 255;
    DebugOverlayLine->g = 0;
    DebugOverlayLine->b = 0;
  }
  else
  {
    DebugOverlayLine->r = 255;
    DebugOverlayLine->g = 255;
    DebugOverlayLine->b = 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10177A30
// Name: float GetLongFloorZ(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetLongFloorZ(const Vector *origin)
{
  CGameTrace trEnt; // [esp+4h] [ebp-B4h] BYREF
  CGameTrace tr; // [esp+58h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+ACh] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+B8h] [ebp+0h] BYREF

  vecAbsEnd.x = origin->x;
  vecAbsEnd.y = origin->y;
  vecAbsEnd.z = origin->z - 2048.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)origin,
    vecAbsStart: origin,
    &vecAbsEnd,
    mask: 0x2400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  vecAbsEnd.x = origin->x;
  vecAbsEnd.y = origin->y;
  vecAbsEnd.z = origin->z - 2048.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)origin,
    vecAbsStart: origin,
    &vecAbsEnd,
    mask: 0x202400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &trEnt);
  if ( tr.fraction > trEnt.fraction && trEnt.m_pEnt != nullptr && (trEnt.m_pEnt->m_fFlags.m_Value & 0x2000000) != 0 )
    tr.endpos.z = trEnt.endpos.z;
  return tr.endpos.z;
}

//------------------------------------------------------------------------------
// Address: 0x10177B00
// Name: void UTIL_DrawPositioningOverlay(float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall UTIL_DrawPositioningOverlay(float a1@<ebp>)
{
  CBasePlayer *v1; // eax
  const IHandleEntity *v2; // esi
  const Vector *v3; // eax
  __int128 v4; // xmm1
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  _BYTE v7[12]; // [esp+30h] [ebp-BCh] BYREF
  _BYTE tr_32[60]; // [esp+5Ch] [ebp-90h] OVERLAPPED BYREF
  Vector bottomPos; // [esp+98h] [ebp-54h] BYREF
  Vector endPos; // [esp+A4h] [ebp-48h] BYREF
  __int128 pRight; // [esp+B0h] [ebp-3Ch] OVERLAPPED BYREF
  Vector v12; // [esp+C8h] [ebp-24h] BYREF
  Vector upTrace; // [esp+D4h] [ebp-18h] BYREF
  Vector topPos; // [esp+E0h] [ebp-Ch] BYREF
  float retaddr; // [esp+ECh] [ebp+0h]

  topPos.x = a1;
  topPos.y = retaddr;
  v1 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
  v2 = v1;
  if ( v1 != nullptr )
  {
    CBasePlayer::EyeVectors(this: v1, pForward: nullptr, pRight: &endPos, pUp: nullptr);
    NWCEdit::AirNodePlacementPosition(result: &upTrace);
    *(Vector *)&tr_32[48] = upTrace;
    *(float *)&tr_32[56] = GetLongFloorZ(origin: (const Vector *)&tr_32[48]);
    v3 = (const Vector *)((int (__thiscall *)(const IHandleEntity *, char *))v2->__vftable[42].dtr_IHandleEntity)(
                           a1: v2,
                           a2: (char *)&pRight + 4);
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&topPos,
      a2: (int)v2,
      vecAbsStart: v3,
      vecAbsEnd: &upTrace,
      mask: 0x2400Bu,
      ignore: v2,
      collisionGroup: 0,
      ptr: (CGameTrace *)v7);
    if ( *(float *)tr_32 == 1.0 )
    {
      v4 = 0;
      *(float *)&v4 = fsqrt(
                        (float)((float)((float)(upTrace.y - (float)(upTrace.y + (float)(endPos.y * 400.0)))
                                      * (float)(upTrace.y - (float)(upTrace.y + (float)(endPos.y * 400.0))))
                              + (float)((float)(upTrace.z - (float)(upTrace.z + (float)(endPos.z * 400.0)))
                                      * (float)(upTrace.z - (float)(upTrace.z + (float)(endPos.z * 400.0)))))
                      + (float)((float)(upTrace.x - (float)(upTrace.x + (float)(endPos.x * 400.0)))
                              * (float)(upTrace.x - (float)(upTrace.x + (float)(endPos.x * 400.0)))));
      v12.x = upTrace.x + (float)(endPos.x * 400.0);
      v12.y = upTrace.y + (float)(endPos.y * 400.0);
      v12.z = upTrace.z + (float)(endPos.z * 400.0);
      pRight = v4;
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&topPos,
        a2: (int)v2,
        vecAbsStart: &upTrace,
        vecAbsEnd: &v12,
        mask: 0x2400Bu,
        ignore: v2,
        collisionGroup: 0,
        ptr: (CGameTrace *)v7);
      bottomPos.x = (float)((float)(*(float *)&pRight * endPos.x) * *(float *)tr_32) + upTrace.x;
      bottomPos.y = (float)((float)(endPos.y * *(float *)&pRight) * *(float *)tr_32) + upTrace.y;
      bottomPos.z = (float)((float)(endPos.z * *(float *)&pRight) * *(float *)tr_32) + upTrace.z;
      NDebugOverlay::DrawTickMarkedLine(
        startPos: &upTrace,
        endPos: &bottomPos,
        tickDist: 24.0,
        tickTextDist: 5,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 0,
        duration: 0.0);
      v5 = 0;
      *(float *)&v5 = fsqrt(
                        (float)((float)((float)(upTrace.y - (float)(upTrace.y - (float)(endPos.y * 400.0)))
                                      * (float)(upTrace.y - (float)(upTrace.y - (float)(endPos.y * 400.0))))
                              + (float)((float)(upTrace.z - (float)(upTrace.z - (float)(endPos.z * 400.0)))
                                      * (float)(upTrace.z - (float)(upTrace.z - (float)(endPos.z * 400.0)))))
                      + (float)((float)(upTrace.x - (float)(upTrace.x - (float)(endPos.x * 400.0)))
                              * (float)(upTrace.x - (float)(upTrace.x - (float)(endPos.x * 400.0)))));
      v12.x = upTrace.x - (float)(endPos.x * 400.0);
      v12.y = upTrace.y - (float)(endPos.y * 400.0);
      v12.z = upTrace.z - (float)(endPos.z * 400.0);
      pRight = v5;
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&topPos,
        a2: (int)v2,
        vecAbsStart: &upTrace,
        vecAbsEnd: &v12,
        mask: 0x2400Bu,
        ignore: v2,
        collisionGroup: 0,
        ptr: (CGameTrace *)v7);
      bottomPos.y = upTrace.y - (float)((float)(endPos.y * *(float *)&pRight) * *(float *)tr_32);
      bottomPos.x = upTrace.x - (float)((float)(*(float *)&pRight * endPos.x) * *(float *)tr_32);
      bottomPos.z = upTrace.z - (float)((float)(endPos.z * *(float *)&pRight) * *(float *)tr_32);
      NDebugOverlay::DrawTickMarkedLine(
        startPos: &upTrace,
        endPos: &bottomPos,
        tickDist: 24.0,
        tickTextDist: 5,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 0,
        duration: 0.0);
      v12.y = upTrace.y;
      v12.x = upTrace.x;
      v12.z = upTrace.z + 400.0;
      v6 = 0;
      *(float *)&v6 = fsqrt(
                        (float)((float)((float)(v12.y - v12.y) * (float)(v12.y - v12.y))
                              + (float)((float)(upTrace.z - v12.z) * (float)(upTrace.z - v12.z)))
                      + (float)((float)(v12.x - v12.x) * (float)(v12.x - v12.x)));
      pRight = v6;
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&topPos,
        a2: (int)v2,
        vecAbsStart: &upTrace,
        vecAbsEnd: &v12,
        mask: 0x2400Bu,
        ignore: v2,
        collisionGroup: 0,
        ptr: (CGameTrace *)v7);
      bottomPos.y = (float)((float)(*(float *)&pRight * 0.0) * *(float *)tr_32) + upTrace.y;
      bottomPos.x = (float)((float)(*(float *)&pRight * 0.0) * *(float *)tr_32) + upTrace.x;
      bottomPos.z = (float)(*(float *)&pRight * *(float *)tr_32) + upTrace.z;
      NDebugOverlay::DrawTickMarkedLine(
        startPos: (const Vector *)&tr_32[48],
        endPos: &bottomPos,
        tickDist: 24.0,
        tickTextDist: 5,
        r: 255,
        g: 0,
        b: 0,
        noDepthTest: 0,
        duration: 0.0);
      v12.x = 2.0;
      v12.y = 2.0;
      v12.z = 2.0;
      *(_QWORD *)((char *)&pRight + 4) = 0xC0000000C0000000uLL;
      HIDWORD(pRight) = -1073741824;
      NDebugOverlay::Cross3D(
        position: &upTrace,
        mins: (const Vector *)((char *)&pRight + 4),
        maxs: &v12,
        r: 255,
        g: 255,
        b: 255,
        noDepthTest: 1,
        fDuration: 0.0);
    }
    else
    {
      *(_QWORD *)((char *)&pRight + 4) = 0x4000000040000000LL;
      HIDWORD(pRight) = 0x40000000;
      v12.x = -2.0;
      v12.y = -2.0;
      v12.z = -2.0;
      NDebugOverlay::Cross3D(
        position: &upTrace,
        mins: &v12,
        maxs: (const Vector *)((char *)&pRight + 4),
        r: 255,
        g: 100,
        b: 100,
        noDepthTest: 1,
        fDuration: 0.0);
    }
  }
}
