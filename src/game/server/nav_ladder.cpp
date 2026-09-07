// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_ladder.cpp
// Functions: 17
// ============================================================

#include "game\server\nav_ladder.h"

//------------------------------------------------------------------------------
// Address: 0x1031B170
// Name: public: void CNavLadder::OnSplit(class CNavArea __near *,class CNavArea __near *,class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::OnSplit(CNavLadder *this, CNavArea *original, CNavArea *alpha, CNavArea *beta)
{
  int i; // ebx
  CNavArea **p_m_topForwardArea; // esi
  float alphaDistance; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    switch ( i )
    {
      case 0:
        p_m_topForwardArea = &this->m_topForwardArea;
        goto LABEL_8;
      case 1:
        p_m_topForwardArea = &this->m_topLeftArea;
        goto LABEL_8;
      case 2:
        p_m_topForwardArea = &this->m_topRightArea;
        goto LABEL_8;
      case 3:
        p_m_topForwardArea = &this->m_topBehindArea;
        goto LABEL_8;
      case 4:
        p_m_topForwardArea = &this->m_bottomArea;
LABEL_8:
        if ( p_m_topForwardArea != nullptr && *p_m_topForwardArea == original )
        {
          alphaDistance = CNavArea::GetDistanceSquaredToPoint(this: alpha, pos: &this->m_top);
          if ( CNavArea::GetDistanceSquaredToPoint(this: beta, pos: &this->m_top) <= alphaDistance )
            *p_m_topForwardArea = beta;
          else
            *p_m_topForwardArea = alpha;
        }
        break;
      default:
        continue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B200
// Name: public: bool CNavLadder::IsConnected(class CNavArea const __near *,enum CNavLadder::LadderDirectionType)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNavLadder::IsConnected(CNavLadder *this, const CNavArea *area, CNavLadder::LadderDirectionType dir)
{
  if ( dir == LADDER_DOWN )
    return area == this->m_bottomArea;
  return dir != LADDER_UP && area == this->m_bottomArea
      || area == this->m_topForwardArea
      || area == this->m_topLeftArea
      || area == this->m_topRightArea
      || area == this->m_topBehindArea;
}

//------------------------------------------------------------------------------
// Address: 0x1031B250
// Name: public: void CNavLadder::Shift(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::Shift(CNavLadder *this, const Vector *shift)
{
  this->m_top.x = shift->x + this->m_top.x;
  this->m_top.y = this->m_top.y + shift->y;
  this->m_top.z = this->m_top.z + shift->z;
  this->m_bottom.x = this->m_bottom.x + shift->x;
  this->m_bottom.y = this->m_bottom.y + shift->y;
  this->m_bottom.z = this->m_bottom.z + shift->z;
}

//------------------------------------------------------------------------------
// Address: 0x1031B2B0
// Name: public: void CNavLadder::ConnectTo(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::ConnectTo(CNavLadder *this, CNavArea *area)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  int v4; // edi
  NavDirType m_dir; // edx
  int v6; // eax
  int v7; // eax

  if ( area->m_center.z <= (float)((float)(this->m_bottom.z + this->m_top.z) * 0.5) )
  {
    this->m_bottomArea = area;
  }
  else
  {
    v2 = area->m_center.x - this->m_top.x;
    v3 = area->m_center.y - this->m_top.y;
    if ( COERCE_FLOAT(LODWORD(v2) & _mask__AbsFloat_) <= COERCE_FLOAT(LODWORD(v3) & _mask__AbsFloat_) )
    {
      if ( v3 <= 0.0 )
        v4 = 0;
      else
        v4 = 2;
    }
    else if ( v2 <= 0.0 )
    {
      v4 = 3;
    }
    else
    {
      v4 = 1;
    }
    m_dir = this->m_dir;
    if ( m_dir == v4 )
    {
      this->m_topBehindArea = area;
    }
    else
    {
      switch ( m_dir )
      {
        case NORTH:
          v6 = 2;
          break;
        case EAST:
          v6 = 3;
          break;
        case WEST:
          v6 = 1;
          break;
        default:
          v6 = 0;
          break;
      }
      if ( v6 == v4 )
      {
        this->m_topForwardArea = area;
      }
      else
      {
        switch ( m_dir )
        {
          case NORTH:
            v7 = 3;
            break;
          case SOUTH:
            v7 = 1;
            break;
          case WEST:
            v7 = 2;
            break;
          default:
            v7 = 0;
            break;
        }
        if ( v7 == v4 )
          this->m_topLeftArea = area;
        else
          this->m_topRightArea = area;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B3D0
// Name: public: void CNavLadder::OnDestroyNotify(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::OnDestroyNotify(CNavLadder *this, CNavArea *dead)
{
  if ( this->m_topForwardArea == dead )
  {
    this->m_topForwardArea = nullptr;
  }
  else if ( this->m_topLeftArea == dead )
  {
    this->m_topLeftArea = nullptr;
  }
  else if ( this->m_topRightArea == dead )
  {
    this->m_topRightArea = nullptr;
  }
  else if ( this->m_topBehindArea == dead )
  {
    this->m_topBehindArea = nullptr;
  }
  else if ( this->m_bottomArea == dead )
  {
    this->m_bottomArea = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B430
// Name: public: bool IsLadderFreeFunctor::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IsLadderFreeFunctor::operator()(IsLadderFreeFunctor *this, CBasePlayer *player)
{
  const CNavLadder *m_ladder; // eax
  float z; // xmm0_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( player == this->m_ignore || !CBasePlayer::IsOnLadder(this: player) )
    return true;
  if ( (player->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
  m_ladder = this->m_ladder;
  z = player->m_vecAbsOrigin.z;
  return z > (float)(this->m_ladder->m_top.z + 35.5)
      || (float)(m_ladder->m_bottom.z - 35.5) > (float)(z + 71.0)
      || (float)((float)((float)(m_ladder->m_bottom.y - player->m_vecAbsOrigin.y)
                       * (float)(m_ladder->m_bottom.y - player->m_vecAbsOrigin.y))
               + (float)((float)(m_ladder->m_bottom.x - player->m_vecAbsOrigin.x)
                       * (float)(m_ladder->m_bottom.x - player->m_vecAbsOrigin.x))) > 2500.0;
}

//------------------------------------------------------------------------------
// Address: 0x1031B4E0
// Name: public: class Vector CNavLadder::GetPosAtHeight(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CNavLadder::GetPosAtHeight(CNavLadder *this, Vector *result, float height)
{
  float z; // xmm1_4
  __int64 v4; // xmm0_8
  Vector *v5; // eax
  float v6; // ecx
  float v7; // xmm0_4
  float v8; // edx
  __int64 v9; // xmm0_8
  float v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  z = this->m_bottom.z;
  if ( z <= height )
  {
    v7 = this->m_top.z;
    if ( height <= v7 )
    {
      v5 = result;
      if ( v7 == z )
      {
        v9 = *(_QWORD *)&this->m_top.x;
        v10 = this->m_top.z;
        *(_QWORD *)&result->x = v9;
        result->z = v10;
      }
      else
      {
        v11 = (float)(height - this->m_bottom.z) / (float)(this->m_top.z - this->m_bottom.z);
        v12 = (float)(this->m_bottom.y * (float)(1.0 - v11)) + (float)(this->m_top.y * v11);
        v13 = (float)(this->m_top.z * v11) + (float)(this->m_bottom.z * (float)(1.0 - v11));
        result->x = (float)(this->m_top.x * v11) + (float)((float)(1.0 - v11) * this->m_bottom.x);
        result->y = v12;
        result->z = v13;
      }
    }
    else
    {
      v8 = this->m_top.z;
      *(_QWORD *)&result->x = *(_QWORD *)&this->m_top.x;
      result->z = v8;
      return result;
    }
  }
  else
  {
    v4 = *(_QWORD *)&this->m_bottom.x;
    v6 = this->m_bottom.z;
    *(_QWORD *)&result->x = v4;
    result->z = v6;
    return result;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1031B5C0
// Name: public: static void CNavLadder::CompressIDs(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CNavLadder::CompressIDs()
{
  CNavMesh *v0; // ecx
  int i; // eax

  v0 = TheNavMesh;
  CNavLadder::m_nextID = 1;
  if ( TheNavMesh != nullptr )
  {
    for ( i = 0; i < TheNavMesh->m_ladders.m_Size; ++i )
    {
      v0->m_ladders.m_Memory.m_pMemory[i]->m_id = CNavLadder::m_nextID;
      v0 = TheNavMesh;
      ++CNavLadder::m_nextID;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B610
// Name: public: CNavLadder::~CNavLadder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::~CNavLadder(CNavLadder *this)
{
  int i; // esi

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
    TheNavAreas.m_Memory.m_pMemory[i]->OnDestroyNotify(this: TheNavAreas.m_Memory.m_pMemory[i], a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1031B640
// Name: public: void CNavLadder::SetDir(enum NavDirType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::SetDir(CNavLadder *this, NavDirType dir)
{
  float v3; // xmm1_4
  float y; // xmm4_4
  float x; // xmm3_4
  float z; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  CGameTrace result; // [esp+0h] [ebp-6Ch] BYREF
  Vector from; // [esp+54h] [ebp-18h] BYREF
  Vector to; // [esp+60h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+6Ch] [ebp+0h] BYREF

  this->m_dir = dir;
  this->m_normal.x = 0.0;
  this->m_normal.y = 0.0;
  this->m_normal.z = 0.0;
  switch ( this->m_dir )
  {
    case NORTH:
      this->m_normal.y = this->m_normal.y - 1.0;
      break;
    case EAST:
      v3 = this->m_normal.x + 1.0;
      goto LABEL_6;
    case SOUTH:
      this->m_normal.y = this->m_normal.y + 1.0;
      break;
    case WEST:
      v3 = this->m_normal.x - 1.0;
LABEL_6:
      this->m_normal.x = v3;
      break;
    default:
      break;
  }
  y = this->m_normal.y;
  x = this->m_normal.x;
  z = this->m_normal.z;
  v7 = this->m_bottom.z + this->m_top.z;
  to.y = y * 5.0;
  v8 = this->m_bottom.x + this->m_top.x;
  to.z = z * 5.0;
  v9 = this->m_bottom.y + this->m_top.y;
  from.x = (float)(v8 * 0.5) + (float)(x * 5.0);
  from.y = (float)(v9 * 0.5) + (float)(y * 5.0);
  from.z = (float)(v7 * 0.5) + (float)(z * 5.0);
  to.x = from.x - (float)(x * 32.0);
  to.y = from.y - (float)(y * 32.0);
  to.z = from.z - (float)(z * 32.0);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &from,
    vecAbsEnd: &to,
    mask: 0x2400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &result);
  if ( result.fraction != 1.0
    && (physprops->GetSurfaceData(this: physprops, a2: result.surface.surfaceProps)->game.climbable != 0
     || (result.contents & 0x20000000) != 0) )
  {
    this->m_normal = result.plane.normal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031B7F0
// Name: public: void CNavLadder::DrawLadder(void)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CNavLadder::DrawLadder(CNavLadder *this@<ecx>, float a2@<ebp>)
{
  CBasePlayer *ListenServerHost; // edi
  float *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm0_4
  __int128 v7; // xmm3
  float v8; // xmm3_4
  float v9; // xmm0_4
  float y; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  float v15; // xmm3_4
  float v16; // xmm5_4
  float z; // xmm6_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float x; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  char *m_pszString; // eax
  int v27; // eax
  int v28; // eax
  int v29; // edi
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  float v33; // xmm0_4
  NavDirType m_dir; // eax
  float v35; // xmm1_4
  int v36; // eax
  float v37; // edi
  __int64 v38; // xmm0_8
  float v39; // ecx
  CNavArea *m_bottomArea; // ecx
  float v41; // xmm1_4
  const Vector *p_m_center; // edi
  char IsConnected; // al
  CNavArea *m_topForwardArea; // ecx
  const Vector *v45; // edi
  char v46; // al
  CNavArea *m_topLeftArea; // ecx
  const Vector *v48; // edi
  char v49; // al
  CNavArea *m_topRightArea; // ecx
  const Vector *v51; // edi
  char v52; // al
  CNavArea *m_topBehindArea; // ecx
  const Vector *v54; // edi
  char v55; // al
  Vector v56; // [esp+14h] [ebp-C0h] BYREF
  Vector dir; // [esp+20h] [ebp-B4h] BYREF
  Vector v58; // [esp+2Ch] [ebp-A8h] BYREF
  Vector v59; // [esp+38h] [ebp-9Ch] BYREF
  Vector topRight; // [esp+44h] [ebp-90h] BYREF
  Vector right; // [esp+50h] [ebp-84h] BYREF
  Vector topLeft; // [esp+5Ch] [ebp-78h] BYREF
  __int128 up; // [esp+68h] [ebp-6Ch] OVERLAPPED BYREF
  int v64; // [esp+80h] [ebp-54h] BYREF
  int v65; // [esp+84h] [ebp-50h] BYREF
  int v66; // [esp+88h] [ebp-4Ch] BYREF
  int bgcolor[4]; // [esp+8Ch] [ebp-48h] BYREF
  Vector bottomLeft; // [esp+9Ch] [ebp-38h] BYREF
  Vector top; // [esp+A8h] [ebp-2Ch] BYREF
  Vector bottomRight; // [esp+B4h] [ebp-20h] BYREF
  Vector bottom; // [esp+C0h] [ebp-14h]
  NavEditColor ladderColor; // [esp+CCh] [ebp-8h]
  NavEditColor retaddr; // [esp+D4h] [ebp+0h]

  bottom.z = a2;
  ladderColor = retaddr;
  ListenServerHost = UTIL_GetListenServerHost();
  if ( ListenServerHost != nullptr )
  {
    ListenServerHost->EyePosition(this: ListenServerHost, result: &dir);
    LODWORD(bottom.x) = CBasePlayer::GetPunchAngle(this: ListenServerHost);
    v4 = (float *)ListenServerHost->EyeAngles(this: ListenServerHost);
    bottomRight.x = *(float *)LODWORD(bottom.x) + *v4;
    bottomRight.y = *(float *)(LODWORD(bottom.x) + 4) + v4[1];
    bottomRight.z = *(float *)(LODWORD(bottom.x) + 8) + v4[2];
    AngleVectors(angles: (const QAngle *)&bottomRight, forward: &v56);
    v5 = dir.x - this->m_bottom.x;
    v6 = dir.y - this->m_bottom.y;
    v7 = 0;
    *(float *)&v7 = fsqrt((float)(v5 * v5) + (float)(v6 * v6));
    up = v7;
    if ( *(float *)&v7 == 0.0 )
    {
      v9 = 0.0;
      v8 = 0.0;
    }
    else
    {
      v8 = (float)(1.0 / *(float *)&up) * v5;
      v9 = v6 * (float)(1.0 / *(float *)&up);
    }
    y = this->m_normal.y;
    BYTE1(bottom.y) = this == TheNavMesh->m_selectedLadder;
    v11 = y * v9;
    v12 = this->m_normal.x * v8;
    HIBYTE(bottom.y) = this == TheNavMesh->m_markedLadder;
    BYTE2(bottom.y) = (float)(v11 + v12) > 0.0;
    if ( TheNavMesh->m_editMode == PLACE_PAINTING )
    {
      BYTE1(bottom.y) = 0;
      HIWORD(bottom.y) = 1;
    }
    m_Index = this->m_ladderEntity.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        CBaseEntity::DrawAbsBoxOverlay(this: m_pEntity);
    }
    LODWORD(bottom.x) = 7;
    if ( BYTE2(bottom.y) != 0 )
    {
      if ( HIBYTE(bottom.y) != 0 )
        LODWORD(bottom.x) = 6;
      else
        LODWORD(bottom.x) = BYTE1(bottom.y) != 0 ? 5 : 2;
    }
    else if ( HIBYTE(bottom.y) != 0 )
    {
      LODWORD(bottom.x) = 6;
    }
    else if ( BYTE1(bottom.y) != 0 )
    {
      LODWORD(bottom.x) = 5;
    }
    memset((void *)&topRight, 0, sizeof(topRight));
    memset((void *)&topLeft, 0, sizeof(topLeft));
    VectorVectors(forward: &this->m_normal, right: &topRight, up: &topLeft);
    if ( topLeft.z <= 0.0 )
    {
      topLeft.x = 0.0;
      topLeft.y = 0.0;
      topLeft.z = 1.0;
    }
    v15 = this->m_width * 0.5;
    v16 = this->m_bottom.y;
    z = this->m_bottom.z;
    v18 = topRight.y * v15;
    v19 = topRight.z * v15;
    v20 = topRight.x * v15;
    x = this->m_bottom.x;
    top.x = x + (float)(topRight.x * v15);
    top.y = (float)(topRight.y * v15) + this->m_bottom.y;
    *(float *)&bgcolor[1] = x - (float)(topRight.x * v15);
    top.z = (float)(topRight.z * v15) + this->m_bottom.z;
    v22 = this->m_top.x;
    v23 = this->m_top.x - v20;
    *(float *)&bgcolor[2] = v16 - v18;
    right.x = v23;
    v24 = this->m_top.y;
    right.y = v24 - v18;
    v25 = this->m_top.z;
    *(float *)&bgcolor[3] = z - v19;
    topRight.x = v20;
    topRight.y = v18;
    topRight.z = v19;
    right.z = v25 - v19;
    v59.x = v22 + v20;
    v59.y = v24 + v18;
    v59.z = v25 + v19;
    if ( (nav_area_bgcolor.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = nav_area_bgcolor.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)locale;
    }
    if ( sscanf(string: m_pszString, format: "%d %d %d %d", &v64, &v65, &v66, bgcolor) == 4 )
    {
      v27 = v64;
      if ( v64 >= 0 )
      {
        if ( v64 > 255 )
          v27 = 255;
      }
      else
      {
        v27 = 0;
      }
      v64 = v27;
      v28 = v65;
      if ( v65 >= 0 )
      {
        if ( v65 > 255 )
          v28 = 255;
      }
      else
      {
        v28 = 0;
      }
      v29 = v28;
      v30 = v66;
      v65 = v29;
      if ( v66 >= 0 )
      {
        if ( v66 > 255 )
          v30 = 255;
      }
      else
      {
        v30 = 0;
      }
      v31 = v30;
      v66 = v30;
      if ( bgcolor[0] >= 0 )
      {
        v32 = 255;
        if ( bgcolor[0] <= 255 )
          v32 = bgcolor[0];
      }
      else
      {
        v32 = 0;
      }
      bgcolor[0] = v32;
      if ( v32 > 0 )
      {
        v33 = 0.0;
        m_dir = this->m_dir;
        v35 = 0.0;
        bottomLeft.x = 0.0;
        bottomLeft.y = 0.0;
        switch ( m_dir )
        {
          case NORTH:
            v36 = 2;
            break;
          case EAST:
            v36 = 3;
            break;
          case WEST:
            v36 = 1;
            break;
          default:
            v36 = 0;
            break;
        }
        switch ( v36 )
        {
          case 0:
            v35 = -1.0;
            bottomLeft.y = -1.0;
            break;
          case 1:
            v33 = 1.0;
            goto LABEL_53;
          case 2:
            v35 = 1.0;
            bottomLeft.y = 1.0;
            break;
          case 3:
            v33 = -1.0;
LABEL_53:
            bottomLeft.x = v33;
            break;
        }
        bottomRight.x = v33 + top.x;
        bottomRight.y = v35 + top.y;
        bottomRight.z = top.z;
        *((float *)&up + 1) = v33 + right.x;
        HIDWORD(up) = LODWORD(right.z);
        v58.x = v33 + v59.x;
        v58.y = v35 + v59.y;
        v58.z = v59.z;
        *((float *)&up + 2) = v35 + right.y;
        NDebugOverlay::Triangle(
          p1: (const Vector *)((char *)&up + 4),
          p2: &v58,
          p3: &bottomRight,
          r: v64,
          g: v29,
          b: v31,
          a: v32,
          noDepthTest: 1,
          duration: 0.15000001);
        *((float *)&up + 1) = bottomLeft.x + right.x;
        *((float *)&up + 2) = bottomLeft.y + right.y;
        HIDWORD(up) = LODWORD(right.z);
        bottomRight.x = bottomLeft.x + top.x;
        bottomRight.z = top.z;
        v58.x = bottomLeft.x + *(float *)&bgcolor[1];
        v58.y = bottomLeft.y + *(float *)&bgcolor[2];
        LODWORD(v58.z) = bgcolor[3];
        bottomRight.y = bottomLeft.y + top.y;
        NDebugOverlay::Triangle(
          p1: &bottomRight,
          p2: &v58,
          p3: (const Vector *)((char *)&up + 4),
          r: v64,
          g: v65,
          b: v66,
          a: bgcolor[0],
          noDepthTest: 1,
          duration: 0.15000001);
      }
    }
    v37 = bottom.x;
    NavDrawLine(from: &right, to: (const Vector *)&bgcolor[1], navColor: LODWORD(bottom.x));
    NavDrawLine(from: &v59, to: &top, navColor: LODWORD(v37));
    for ( ; v59.z > top.z; *(float *)&bgcolor[3] = (float)(topLeft.z * 12.5) + *(float *)&bgcolor[3] )
    {
      NavDrawLine(from: &top, to: (const Vector *)&bgcolor[1], navColor: LODWORD(v37));
      *(float *)&bgcolor[1] = (float)(topLeft.x * 12.5) + *(float *)&bgcolor[1];
      top.x = (float)(topLeft.x * 12.5) + top.x;
      top.y = (float)(topLeft.y * 12.5) + top.y;
      top.z = (float)(topLeft.z * 12.5) + top.z;
      *(float *)&bgcolor[2] = (float)(topLeft.y * 12.5) + *(float *)&bgcolor[2];
    }
    if ( TheNavMesh->m_editMode != PLACE_PAINTING )
    {
      v38 = *(_QWORD *)&this->m_bottom.x;
      v39 = this->m_top.z;
      bottomRight.z = this->m_bottom.z;
      *(_QWORD *)&bottomRight.x = v38;
      *(_QWORD *)&bottomLeft.x = *(_QWORD *)&this->m_top.x;
      bottomLeft.z = v39;
      NavDrawLine(from: &bottomLeft, to: &bottomRight, navColor: (Color)16);
      m_bottomArea = this->m_bottomArea;
      if ( m_bottomArea != nullptr )
      {
        v41 = 25.0;
        p_m_center = &m_bottomArea->m_center;
        if ( (float)(bottomLeft.z - bottomRight.z) < 37.5 )
          v41 = 0.0;
        if ( (float)(bottomRight.z - m_bottomArea->m_center.z) > 37.5 )
          v41 = 0.0;
        *(_QWORD *)((char *)&up + 4) = *(_QWORD *)&bottomRight.x;
        *((float *)&up + 3) = bottomRight.z + v41;
        IsConnected = CNavArea::IsConnected(this: m_bottomArea, ladder: this, dir: LADDER_UP);
        NavDrawLine(from: (const Vector *)((char *)&up + 4), to: p_m_center, navColor: (Color)(17 - (IsConnected != 0)));
      }
      if ( this->m_topForwardArea != nullptr )
      {
        m_topForwardArea = this->m_topForwardArea;
        v45 = &m_topForwardArea->m_center;
        v46 = CNavArea::IsConnected(this: m_topForwardArea, ladder: this, dir: LADDER_DOWN);
        NavDrawLine(from: &bottomLeft, to: v45, navColor: (Color)(17 - (v46 != 0)));
      }
      if ( this->m_topLeftArea != nullptr )
      {
        m_topLeftArea = this->m_topLeftArea;
        v48 = &m_topLeftArea->m_center;
        v49 = CNavArea::IsConnected(this: m_topLeftArea, ladder: this, dir: LADDER_DOWN);
        NavDrawLine(from: &bottomLeft, to: v48, navColor: (Color)(17 - (v49 != 0)));
      }
      if ( this->m_topRightArea != nullptr )
      {
        m_topRightArea = this->m_topRightArea;
        v51 = &m_topRightArea->m_center;
        v52 = CNavArea::IsConnected(this: m_topRightArea, ladder: this, dir: LADDER_DOWN);
        NavDrawLine(from: &bottomLeft, to: v51, navColor: (Color)(17 - (v52 != 0)));
      }
      if ( this->m_topBehindArea != nullptr )
      {
        m_topBehindArea = this->m_topBehindArea;
        v54 = &m_topBehindArea->m_center;
        v55 = CNavArea::IsConnected(this: m_topBehindArea, ladder: this, dir: LADDER_DOWN);
        NavDrawLine(from: &bottomLeft, to: v54, navColor: (Color)(17 - (v55 != 0)));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031BFF0
// Name: public: void CNavLadder::OnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::OnRoundRestart(CNavLadder *this)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  CBaseEntity *EntityByClassnameNearest; // eax
  Vector vecSrc; // [esp+8h] [ebp-Ch] BYREF

  v2 = this->m_bottom.y + this->m_top.y;
  v3 = this->m_bottom.z + this->m_top.z;
  vecSrc.x = (float)(this->m_bottom.x + this->m_top.x) * 0.5;
  vecSrc.y = v2 * 0.5;
  vecSrc.z = v3 * 0.5;
  EntityByClassnameNearest = CGlobalEntityList::FindEntityByClassnameNearest(
                               this: &gEntList,
                               szName: "func_simpleladder",
                               &vecSrc,
                               flRadius: 16.0);
  if ( EntityByClassnameNearest != nullptr )
    this->m_ladderEntity.m_Index = EntityByClassnameNearest->GetRefEHandle(this: EntityByClassnameNearest)->m_Index;
  else
    this->m_ladderEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1031C100
// Name: public: bool CNavLadder::IsInUse(class CBasePlayer const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavLadder::IsInUse(CNavLadder *this, const CBasePlayer *ignore)
{
  IsLadderFreeFunctor isLadderFree; // [esp+0h] [ebp-8h] BYREF

  isLadderFree.m_ladder = this;
  isLadderFree.m_ignore = ignore;
  return !ForEachPlayer<IsLadderFreeFunctor>(func: &isLadderFree);
}

//------------------------------------------------------------------------------
// Address: 0x1031C130
// Name: public: void CNavLadder::Save(class CUtlBuffer __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::Save(CNavLadder *this, CUtlBuffer *fileBuffer, unsigned int version)
{
  float m_width; // xmm0_4
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float m_length; // xmm0_4
  CNavArea *m_topForwardArea; // eax
  int m_id; // eax
  CNavArea *m_topLeftArea; // eax
  int v15; // eax
  CNavArea *m_topRightArea; // eax
  int v17; // eax
  CNavArea *m_topBehindArea; // eax
  int v19; // eax
  CNavArea *m_bottomArea; // edi
  int v21; // eax
  unsigned int src; // [esp+4h] [ebp-10h]
  NavDirType srca; // [esp+4h] [ebp-10h]

  src = this->m_id;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", src);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src);
  m_width = this->m_width;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", m_width);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: m_width);
  x = this->m_top.x;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", x);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: x);
  y = this->m_top.y;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", y);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: y);
  z = this->m_top.z;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", z);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: z);
  v8 = this->m_bottom.x;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", v8);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: v8);
  v9 = this->m_bottom.y;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", v9);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: v9);
  v10 = this->m_bottom.z;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", v10);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: v10);
  m_length = this->m_length;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%f", m_length);
  else
    CUtlBuffer::PutTypeBin<float>(this: fileBuffer, src: m_length);
  srca = this->m_dir;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", srca);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: srca);
  m_topForwardArea = this->m_topForwardArea;
  if ( m_topForwardArea != nullptr )
    m_id = m_topForwardArea->m_id;
  else
    m_id = 0;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", m_id);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: m_id);
  m_topLeftArea = this->m_topLeftArea;
  if ( m_topLeftArea != nullptr )
    v15 = m_topLeftArea->m_id;
  else
    v15 = 0;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", v15);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: v15);
  m_topRightArea = this->m_topRightArea;
  if ( m_topRightArea != nullptr )
    v17 = m_topRightArea->m_id;
  else
    v17 = 0;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", v17);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: v17);
  m_topBehindArea = this->m_topBehindArea;
  if ( m_topBehindArea != nullptr )
    v19 = m_topBehindArea->m_id;
  else
    v19 = 0;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", v19);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: v19);
  m_bottomArea = this->m_bottomArea;
  if ( m_bottomArea != nullptr )
    v21 = m_bottomArea->m_id;
  else
    v21 = 0;
  if ( (fileBuffer->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: fileBuffer, pFmt: "%u", v21);
  else
    CUtlBuffer::PutTypeBin<int>(this: fileBuffer, src: v21);
}

//------------------------------------------------------------------------------
// Address: 0x1031C400
// Name: public: void CNavLadder::Load(class CUtlBuffer __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::Load(CNavLadder *this, CUtlBuffer *fileBuffer, unsigned int version)
{
  CUtlBuffer *v3; // edi
  unsigned int UnsignedInt; // eax
  NavDirType v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  CNavArea *NavAreaByID; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  CBaseEntity *EntityByClassnameNearest; // eax
  Vector vecSrc; // [esp+20h] [ebp-Ch] BYREF

  v3 = fileBuffer;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: fileBuffer);
  this->m_id = UnsignedInt;
  if ( UnsignedInt >= CNavLadder::m_nextID )
    CNavLadder::m_nextID = UnsignedInt + 1;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_width) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_top.x) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_top.y) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_top.z) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_bottom.x) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_bottom.y) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_bottom.z) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v3, dest: (float *)&fileBuffer);
  LODWORD(this->m_length) = fileBuffer;
  v6 = CUtlBuffer::GetUnsignedInt(this: v3);
  this->m_dir = v6;
  CNavLadder::SetDir(this, dir: v6);
  if ( version == 6 )
    CUtlBuffer::Get(this: v3, pMem: (char *)&fileBuffer + 3, size: 1);
  v7 = CUtlBuffer::GetUnsignedInt(this: v3);
  this->m_topForwardArea = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v7);
  v8 = CUtlBuffer::GetUnsignedInt(this: v3);
  this->m_topLeftArea = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v8);
  v9 = CUtlBuffer::GetUnsignedInt(this: v3);
  this->m_topRightArea = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v9);
  v10 = CUtlBuffer::GetUnsignedInt(this: v3);
  this->m_topBehindArea = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v10);
  v11 = CUtlBuffer::GetUnsignedInt(this: v3);
  NavAreaByID = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v11);
  this->m_bottomArea = NavAreaByID;
  if ( NavAreaByID != nullptr )
  {
    if ( this->m_topForwardArea == nullptr && this->m_topLeftArea == nullptr && this->m_topRightArea == nullptr )
    {
      DevMsg(
        a1: "ERROR: Unconnected ladder #%d top at ( %g, %g, %g )\n",
        this->m_id,
        this->m_top.x,
        this->m_top.y,
        this->m_top.z);
      DevWarning(a1: "nav_unmark; nav_mark ladder %d; nav_warp_to_mark\n", this->m_id);
    }
  }
  else
  {
    DevMsg(
      a1: "ERROR: Unconnected ladder #%d bottom at ( %g, %g, %g )\n",
      this->m_id,
      this->m_bottom.x,
      this->m_bottom.y,
      this->m_bottom.z);
    DevWarning(a1: "nav_unmark; nav_mark ladder %d; nav_warp_to_mark\n", this->m_id);
  }
  v13 = this->m_bottom.y + this->m_top.y;
  v14 = this->m_bottom.z + this->m_top.z;
  vecSrc.x = (float)(this->m_top.x + this->m_bottom.x) * 0.5;
  vecSrc.y = v13 * 0.5;
  vecSrc.z = v14 * 0.5;
  EntityByClassnameNearest = CGlobalEntityList::FindEntityByClassnameNearest(
                               this: &gEntList,
                               szName: "func_simpleladder",
                               &vecSrc,
                               flRadius: 16.0);
  if ( EntityByClassnameNearest != nullptr )
    this->m_ladderEntity.m_Index = EntityByClassnameNearest->GetRefEHandle(this: EntityByClassnameNearest)->m_Index;
  else
    this->m_ladderEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1031C690
// Name: public: void CNavLadder::DrawConnectedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavLadder::DrawConnectedAreas(CNavLadder *this)
{
  int m_Size; // esi
  CNavArea **m_pMemory; // edi
  int v4; // eax
  int v5; // ebx
  CNavArea **v6; // ebx
  int v7; // ebx
  CNavArea **v8; // ebx
  int v9; // ebx
  CNavArea **v10; // ebx
  int v11; // ebx
  CNavArea **v12; // ebx
  CNavArea *v13; // ebx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > areas; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+20h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  i = (int)this;
  memset(&areas, 0, sizeof(areas));
  if ( this->m_topForwardArea != nullptr )
  {
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&areas, num: 1);
    m_pMemory = areas.m_Memory.m_pMemory;
    m_Size = areas.m_Size + 1;
    v4 = areas.m_Size++;
    areas.m_pElements = areas.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(dest: areas.m_Memory.m_pMemory + 1, src: areas.m_Memory.m_pMemory, count: 4 * v4);
    if ( m_pMemory != nullptr )
      *m_pMemory = this->m_topForwardArea;
  }
  if ( this->m_topLeftArea != nullptr )
  {
    v5 = m_Size;
    if ( m_Size + 1 > areas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&areas,
        num: m_Size - areas.m_Memory.m_nAllocationCount + 1);
      m_Size = areas.m_Size;
      m_pMemory = areas.m_Memory.m_pMemory;
    }
    areas.m_Size = ++m_Size;
    areas.m_pElements = m_pMemory;
    if ( m_Size - v5 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * (m_Size - v5 - 1));
    v6 = &m_pMemory[v5];
    if ( v6 != nullptr )
      *v6 = *(CNavArea **)(i + 36);
  }
  if ( *(_DWORD *)(i + 40) != 0 )
  {
    v7 = m_Size;
    if ( m_Size + 1 > areas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&areas,
        num: m_Size - areas.m_Memory.m_nAllocationCount + 1);
      m_Size = areas.m_Size;
      m_pMemory = areas.m_Memory.m_pMemory;
    }
    areas.m_Size = ++m_Size;
    areas.m_pElements = m_pMemory;
    if ( m_Size - v7 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
    v8 = &m_pMemory[v7];
    if ( v8 != nullptr )
      *v8 = *(CNavArea **)(i + 40);
  }
  if ( *(_DWORD *)(i + 44) != 0 )
  {
    v9 = m_Size;
    if ( m_Size + 1 > areas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&areas,
        num: m_Size - areas.m_Memory.m_nAllocationCount + 1);
      m_Size = areas.m_Size;
      m_pMemory = areas.m_Memory.m_pMemory;
    }
    areas.m_Size = ++m_Size;
    areas.m_pElements = m_pMemory;
    if ( m_Size - v9 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
    v10 = &m_pMemory[v9];
    if ( v10 != nullptr )
      *v10 = *(CNavArea **)(i + 44);
  }
  if ( *(_DWORD *)(i + 48) != 0 )
  {
    v11 = m_Size;
    if ( m_Size + 1 > areas.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&areas,
        num: m_Size - areas.m_Memory.m_nAllocationCount + 1);
      m_Size = areas.m_Size;
      m_pMemory = areas.m_Memory.m_pMemory;
    }
    if ( ++m_Size - v11 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * (m_Size - v11 - 1));
    v12 = &m_pMemory[v11];
    if ( v12 != nullptr )
      *v12 = *(CNavArea **)(i + 48);
  }
  for ( i = 0; i < m_Size; ++i )
  {
    v13 = m_pMemory[i];
    v13->Draw(this: v13);
    if ( TheNavMesh->m_editMode != PLACE_PAINTING )
      CNavArea::DrawHidingSpots(this: v13);
  }
  if ( areas.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1031C080
// Name: bool ForEachPlayer<class IsLadderFreeFunctor>(class IsLadderFreeFunctor __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<IsLadderFreeFunctor>(IsLadderFreeFunctor *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && !IsLadderFreeFunctor::operator()(this: func, player: v3) )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}
