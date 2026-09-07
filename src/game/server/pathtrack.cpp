// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/pathtrack.cpp
// Functions: 31
// ============================================================

#include "game\server\pathtrack.h"

//------------------------------------------------------------------------------
// Address: 0x1017D5D0
// Name: private: virtual struct datamap_t __near * CPathTrack::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPathTrack::GetDataDescMap(CPathTrack *this)
{
  return &CPathTrack::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017D5E0
// Name: public: static void CPathTrack::BeginIteration(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPathTrack::BeginIteration()
{
  ++CPathTrack::s_nCurrIterVal;
  CPathTrack::s_bIsIterating = true;
}

//------------------------------------------------------------------------------
// Address: 0x1017D600
// Name: public: static void CPathTrack::EndIteration(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CPathTrack::EndIteration()
{
  CPathTrack::s_bIsIterating = false;
}

//------------------------------------------------------------------------------
// Address: 0x1017D610
// Name: public: void CPathTrack::Visit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::Visit(CPathTrack *this)
{
  this->m_nIterVal = CPathTrack::s_nCurrIterVal;
}

//------------------------------------------------------------------------------
// Address: 0x1017D620
// Name: public: bool CPathTrack::HasBeenVisited(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPathTrack::HasBeenVisited(CPathTrack *this)
{
  return this->m_nIterVal == CPathTrack::s_nCurrIterVal;
}

//------------------------------------------------------------------------------
// Address: 0x1017D640
// Name: public: enum TrackOrientationType_t CPathTrack::GetOrientationType(void)
// Source: json
//------------------------------------------------------------------------------
TrackOrientationType_t __thiscall CPathTrack::GetOrientationType(CPathTrack *this)
{
  return this->m_eOrientationType;
}

//------------------------------------------------------------------------------
// Address: 0x1017D650
// Name: private: void CPathTrack::InputPass(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputPass(CPathTrack *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnPass, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1017D680
// Name: public: virtual void CPathTrack::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::Spawn(CPathTrack *this)
{
  Vector vecMin; // [esp+4h] [ebp-18h] BYREF
  Vector vecMax; // [esp+10h] [ebp-Ch] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  vecMax.x = 8.0;
  vecMax.y = 8.0;
  vecMax.z = 8.0;
  vecMin.x = -8.0;
  vecMin.y = -8.0;
  vecMin.z = -8.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  this->m_pnext = nullptr;
  this->m_pprevious = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017D6F0
// Name: public: virtual void CPathTrack::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPathTrack::DrawDebugGeometryOverlays(CPathTrack *this@<ecx>, int a2@<ebp>)
{
  CPathTrack *m_pnext; // edi

  if ( (this->m_debugOverlays & 0x24) != 0 )
  {
    m_pnext = this->m_pnext;
    if ( m_pnext != nullptr )
    {
      if ( (m_pnext->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->m_pnext, a2);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2);
      NDebugOverlay::Line(
        origin: &this->m_vecAbsOrigin,
        target: &m_pnext->m_vecAbsOrigin,
        r: 255,
        g: 100,
        b: 100,
        noDepthTest: 1,
        duration: 0.0);
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017D770
// Name: public: static class CPathTrack __near * CPathTrack::ValidPath(class CPathTrack __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__cdecl CPathTrack::ValidPath(CPathTrack *ppath, int testFlag)
{
  CPathTrack *result; // eax

  result = ppath;
  if ( ppath == nullptr || testFlag != 0 && (ppath->m_spawnflags.m_Value & 1) != 0 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D790
// Name: public: class CPathTrack __near * CPathTrack::GetNext(void)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CPathTrack::GetNext(CPathTrack *this)
{
  CPathTrack *result; // eax
  int m_Value; // edx

  result = this->m_paltpath;
  if ( result == nullptr )
    return this->m_pnext;
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x8000) == 0 || (m_Value & 4) != 0 )
    return this->m_pnext;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D7C0
// Name: public: class CPathTrack __near * CPathTrack::GetPrevious(void)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CPathTrack::GetPrevious(CPathTrack *this)
{
  CPathTrack *result; // eax
  int m_Value; // edx

  result = this->m_paltpath;
  if ( result == nullptr )
    return this->m_pprevious;
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x8000) == 0 || (m_Value & 4) == 0 )
    return this->m_pprevious;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D7F0
// Name: public: class CPathTrack __near * CPathTrack::GetNextInDir(bool)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CPathTrack::GetNextInDir(CPathTrack *this, bool bForward)
{
  CPathTrack *result; // eax
  int m_Value; // edx
  int v4; // edx

  result = this->m_paltpath;
  if ( bForward )
  {
    if ( result == nullptr )
      return this->m_pnext;
    m_Value = this->m_spawnflags.m_Value;
    if ( (m_Value & 0x8000) == 0 || (m_Value & 4) != 0 )
      return this->m_pnext;
  }
  else
  {
    if ( result == nullptr )
      return this->m_pprevious;
    v4 = this->m_spawnflags.m_Value;
    if ( (v4 & 0x8000) == 0 || (v4 & 4) == 0 )
      return this->m_pprevious;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D850
// Name: private: void CPathTrack::Project(class CPathTrack __near *,class CPathTrack __near *,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::Project(CPathTrack *this, CPathTrack *pstart, CPathTrack *pend, Vector *origin, float dist)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  Vector dir; // [esp+0h] [ebp-Ch] BYREF

  if ( pstart != nullptr && pend != nullptr )
  {
    dir.x = pend->m_vecOrigin.m_Value.x - pstart->m_vecOrigin.m_Value.x;
    dir.y = pend->m_vecOrigin.m_Value.y - pstart->m_vecOrigin.m_Value.y;
    dir.z = pend->m_vecOrigin.m_Value.z - pstart->m_vecOrigin.m_Value.z;
    VectorNormalize(vec: &dir);
    v5 = pend->m_vecOrigin.m_Value.y + (float)(dir.y * dist);
    v6 = pend->m_vecOrigin.m_Value.z + (float)(dir.z * dist);
    origin->x = pend->m_vecOrigin.m_Value.x + (float)(dir.x * dist);
    origin->y = v5;
    origin->z = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D920
// Name: private: void CPathTrack::SetPrevious(class CPathTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::SetPrevious(CPathTrack *this, CPathTrack *pprev)
{
  const char *pszValue; // eax
  const char *v4; // ecx

  if ( pprev != nullptr )
  {
    pszValue = this->m_altName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v4 = pprev->m_iName.m_Value.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    if ( v4 != pszValue && _V_stricmp(s1: v4, s2: pszValue) != 0 )
      this->m_pprevious = pprev;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D970
// Name: public: class CPathTrack __near * CPathTrack::LookAhead(class Vector __near &,float,int,class CPathTrack __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CPathTrack::LookAhead(
        CPathTrack *this,
        Vector *origin,
        float dist,
        int move,
        CPathTrack **pNextNext)
{
  float v5; // xmm2_4
  CPathTrack *v6; // esi
  char v7; // cl
  float z; // xmm4_4
  float y; // xmm6_4
  float x; // xmm5_4
  CPathTrack *m_paltpath; // edx
  int m_Value; // eax
  bool v13; // zf
  CPathTrack *m_pnext; // eax
  int v15; // eax
  int v16; // eax
  float *m_pprevious; // eax
  int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // eax
  float *v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  CPathTrack **v34; // edi
  CPathTrack *NextInDir; // eax
  float v37; // xmm2_4
  float v38; // [esp+14h] [ebp-3Ch]
  bool currentPos_8; // [esp+40h] [ebp-10h]
  Vector v42; // 0:^38.12

  v5 = dist;
  v6 = this;
  v42 = *origin;
  v7 = 1;
  currentPos_8 = true;
  if ( dist < 0.0 )
  {
    LODWORD(v5) = LODWORD(dist) ^ _mask__NegFloat_;
    currentPos_8 = false;
    v7 = 0;
  }
  if ( v5 <= 0.0 )
  {
LABEL_75:
    v34 = pNextNext;
    if ( pNextNext == nullptr )
      return v6;
LABEL_76:
    *v34 = CPathTrack::GetNextInDir(this: v6, bForward: currentPos_8);
    return v6;
  }
  z = origin->z;
  y = v42.y;
  x = v42.x;
  while ( 1 )
  {
    m_paltpath = v6->m_paltpath;
    if ( v7 != 0 )
    {
      if ( m_paltpath == nullptr
        || ((m_Value = v6->m_spawnflags.m_Value) & 0x8000) == 0
        || (v13 = (m_Value & 4) == 0, m_pnext = v6->m_paltpath, !v13) )
      {
        m_pnext = v6->m_pnext;
      }
    }
    else if ( m_paltpath == nullptr
           || ((v15 = v6->m_spawnflags.m_Value) & 0x8000) == 0
           || (v13 = (v15 & 4) == 0, m_pnext = v6->m_paltpath, v13) )
    {
      m_pnext = v6->m_pprevious;
    }
    if ( m_pnext == nullptr || move != 0 && (m_pnext->m_spawnflags.m_Value & 1) != 0 )
    {
      if ( move == 0 )
      {
        NextInDir = CPathTrack::GetNextInDir(this: v6, bForward: v7 == 0);
        CPathTrack::Project(this, pstart: NextInDir, pend: v6, origin, dist: v5);
      }
      return nullptr;
    }
    if ( v7 != 0 )
    {
      if ( m_paltpath == nullptr
        || ((v16 = v6->m_spawnflags.m_Value) & 0x8000) == 0
        || (v13 = (v16 & 4) == 0, m_pprevious = (float *)v6->m_paltpath, !v13) )
      {
        m_pprevious = (float *)v6->m_pnext;
      }
    }
    else if ( m_paltpath == nullptr
           || ((v18 = v6->m_spawnflags.m_Value) & 0x8000) == 0
           || (v13 = (v18 & 4) == 0, m_pprevious = (float *)v6->m_paltpath, v13) )
    {
      m_pprevious = (float *)v6->m_pprevious;
    }
    v19 = m_pprevious[177] - z;
    v20 = m_pprevious[176] - y;
    v21 = m_pprevious[175] - x;
    v38 = fsqrt((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21));
    if ( v38 == 0.0 )
      break;
LABEL_53:
    if ( v38 > v5 )
    {
      v37 = v5 / v38;
      v34 = pNextNext;
      origin->x = (float)(v37 * v21) + x;
      origin->y = (float)(v20 * v37) + y;
      origin->z = (float)(v19 * v37) + v42.z;
      if ( pNextNext == nullptr )
        return v6;
      goto LABEL_76;
    }
    v5 = v5 - v38;
    if ( v7 != 0 )
    {
      if ( m_paltpath == nullptr
        || ((v29 = v6->m_spawnflags.m_Value) & 0x8000) == 0
        || (v13 = (v29 & 4) == 0, v30 = (float *)v6->m_paltpath, !v13) )
      {
        v30 = (float *)v6->m_pnext;
      }
    }
    else if ( m_paltpath == nullptr
           || ((v31 = v6->m_spawnflags.m_Value) & 0x8000) == 0
           || (v13 = (v31 & 4) == 0, v30 = (float *)v6->m_paltpath, v13) )
    {
      v30 = (float *)v6->m_pprevious;
    }
    z = v30[177];
    x = v30[175];
    y = v30[176];
    v42.z = z;
    if ( v7 != 0 )
    {
      if ( m_paltpath != nullptr && ((v32 = v6->m_spawnflags.m_Value) & 0x8000) != 0 && (v32 & 4) == 0 )
        v6 = v6->m_paltpath;
      else
        v6 = v6->m_pnext;
    }
    else if ( m_paltpath != nullptr && ((v33 = v6->m_spawnflags.m_Value) & 0x8000) != 0 && (v33 & 4) != 0 )
    {
      v6 = v6->m_paltpath;
    }
    else
    {
      v6 = v6->m_pprevious;
    }
    origin->x = x;
    origin->y = y;
    origin->z = z;
    if ( v5 <= 0.0 )
      goto LABEL_75;
  }
  if ( v7 == 0 )
  {
    if ( m_paltpath != nullptr && ((v26 = v6->m_spawnflags.m_Value) & 0x8000) != 0 && (v26 & 4) != 0 )
      v27 = &v6->m_paltpath->__vftable;
    else
      v27 = &v6->m_pprevious->__vftable;
    if ( v27[215] != 0 )
    {
      v28 = v27[190];
      if ( (v28 & 0x8000) != 0 && (v28 & 4) != 0 )
      {
        v7 = currentPos_8;
        v25 = v27[215];
        goto LABEL_50;
      }
      v7 = currentPos_8;
    }
    v25 = v27[214];
    goto LABEL_50;
  }
  if ( m_paltpath != nullptr && ((v22 = v6->m_spawnflags.m_Value) & 0x8000) != 0 && (v22 & 4) == 0 )
    v23 = &v6->m_paltpath->__vftable;
  else
    v23 = &v6->m_pnext->__vftable;
  if ( v23[215] == 0 )
  {
LABEL_47:
    v25 = v23[213];
    goto LABEL_50;
  }
  v24 = v23[190];
  if ( (v24 & 0x8000) == 0 || (v24 & 4) != 0 )
  {
    v7 = currentPos_8;
    goto LABEL_47;
  }
  v7 = currentPos_8;
  v25 = v23[215];
LABEL_50:
  if ( v25 != 0 && (move == 0 || (*(_BYTE *)(v25 + 760) & 1) == 0) )
    goto LABEL_53;
  if ( pNextNext != nullptr )
    *pNextNext = nullptr;
  if ( v5 == dist )
    return nullptr;
  return CPathTrack::GetNextInDir(this: v6, bForward: currentPos_8);
}

//------------------------------------------------------------------------------
// Address: 0x1017DD40
// Name: public: class CPathTrack __near * CPathTrack::Nearest(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPathTrack *__thiscall CPathTrack::Nearest(CPathTrack *this, const Vector *origin)
{
  float y; // xmm3_4
  float x; // xmm2_4
  CPathTrack *m_paltpath; // edx
  float v6; // xmm5_4
  int m_Value; // ecx
  int v8; // eax
  float v9; // xmm0_4
  int v10; // ecx
  const char *DebugName; // eax
  CPathTrack *v13; // [esp-4h] [ebp-10h]

  y = origin->y;
  x = origin->x;
  m_paltpath = this->m_paltpath;
  v6 = fsqrt(
         (float)((float)((float)(y - this->m_vecOrigin.m_Value.y) * (float)(y - this->m_vecOrigin.m_Value.y))
               + (float)(0.0 * 0.0))
       + (float)((float)(x - this->m_vecOrigin.m_Value.x) * (float)(x - this->m_vecOrigin.m_Value.x)));
  v13 = this;
  if ( m_paltpath == nullptr || ((m_Value = this->m_spawnflags.m_Value) & 0x8000) == 0 || (m_Value & 4) != 0 )
    m_paltpath = this->m_pnext;
  v8 = 0;
  if ( m_paltpath != nullptr )
  {
    while ( m_paltpath != this )
    {
      if ( ++v8 > 9999 )
      {
        DebugName = CBaseEntity::GetDebugName(this);
        _Warning(a1: "Bad sequence of path_tracks from %s\n", DebugName);
        return nullptr;
      }
      v9 = fsqrt(
             (float)((float)((float)(y - m_paltpath->m_vecOrigin.m_Value.y)
                           * (float)(y - m_paltpath->m_vecOrigin.m_Value.y))
                   + (float)((float)(x - m_paltpath->m_vecOrigin.m_Value.x)
                           * (float)(x - m_paltpath->m_vecOrigin.m_Value.x)))
           + (float)(0.0 * 0.0));
      if ( v6 > v9 )
      {
        v6 = v9;
        v13 = m_paltpath;
      }
      if ( m_paltpath->m_paltpath != nullptr
        && ((v10 = m_paltpath->m_spawnflags.m_Value) & 0x8000) != 0
        && (v10 & 4) == 0 )
      {
        m_paltpath = m_paltpath->m_paltpath;
      }
      else
      {
        m_paltpath = m_paltpath->m_pnext;
      }
      if ( m_paltpath == nullptr )
        return v13;
    }
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1017DE90
// Name: public: class QAngle CPathTrack::GetOrientation(bool)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CPathTrack::GetOrientation(CPathTrack *this, QAngle *result, bool bForwardDir)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  CPathTrack *m_paltpath; // edx
  CPathTrack *NextInDir; // esi
  int m_Value; // eax
  int v9; // eax
  CPathTrack *v10; // ecx
  QAngle angDir; // [esp+0h] [ebp-18h] BYREF
  Vector vecDir; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->m_eOrientationType == TrackOrientation_FacePathAngles )
  {
    v3 = *(_QWORD *)&this->m_angRotation.m_Value.x;
    z = this->m_angRotation.m_Value.z;
    *(_QWORD *)&result->x = v3;
    result->z = z;
    return result;
  }
  else
  {
    m_paltpath = this->m_paltpath;
    NextInDir = this;
    if ( bForwardDir )
    {
      if ( m_paltpath == nullptr || ((m_Value = this->m_spawnflags.m_Value) & 0x8000) == 0 || (m_Value & 4) != 0 )
        m_paltpath = this->m_pnext;
    }
    else if ( m_paltpath == nullptr || ((v9 = this->m_spawnflags.m_Value) & 0x8000) == 0 || (v9 & 4) == 0 )
    {
      m_paltpath = this->m_pprevious;
    }
    if ( m_paltpath == nullptr )
    {
      NextInDir = CPathTrack::GetNextInDir(this, bForward: !bForwardDir);
      m_paltpath = v10;
    }
    vecDir.x = m_paltpath->m_vecOrigin.m_Value.x - NextInDir->m_vecOrigin.m_Value.x;
    vecDir.y = m_paltpath->m_vecOrigin.m_Value.y - NextInDir->m_vecOrigin.m_Value.y;
    vecDir.z = m_paltpath->m_vecOrigin.m_Value.z - NextInDir->m_vecOrigin.m_Value.z;
    VectorAngles(forward: &vecDir, angles: &angDir);
    *result = angDir;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017DFC0
// Name: private: void CPathTrack::Link(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::Link(CPathTrack *this)
{
  const char *pszValue; // eax
  CPathTrack *EntityByName; // eax
  CPathTrack *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  CBasePlayer *v7; // eax
  CPathTrack *v8; // edi
  const char *v9; // eax
  const char *v10; // ecx
  const char *DebugName; // [esp-4h] [ebp-8h]

  pszValue = this->m_target.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = (CPathTrack *)CGlobalEntityList::FindEntityByName(
                                   this: &gEntList,
                                   pStartEntity: nullptr,
                                   szName: pszValue,
                                   pSearchingEntity: nullptr,
                                   pActivator: nullptr,
                                   pCaller: nullptr,
                                   pFilter: nullptr);
    if ( EntityByName == this )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(a1: "ERROR: path_track (%s) refers to itself as a target!\n", DebugName);
    }
    else if ( EntityByName != nullptr )
    {
      v4 = (CPathTrack *)__RTDynamicCast(
                           inptr: EntityByName,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CPathTrack `RTTI Type Descriptor',
                           isReference: 0);
      this->m_pnext = v4;
      if ( v4 != nullptr )
        CPathTrack::SetPrevious(this: v4, pprev: this);
    }
    else
    {
      v5 = this->m_target.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      _Warning(a1: "Dead end link: %s\n", v5);
    }
  }
  v6 = this->m_altName.pszValue;
  if ( v6 != nullptr )
  {
    v7 = CGlobalEntityList::FindEntityByName(
           this: &gEntList,
           pStartEntity: nullptr,
           szName: v6,
           pSearchingEntity: nullptr,
           pActivator: nullptr,
           pCaller: nullptr,
           pFilter: nullptr);
    if ( v7 != nullptr )
    {
      v8 = (CPathTrack *)__RTDynamicCast(
                           inptr: v7,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CPathTrack `RTTI Type Descriptor',
                           isReference: 0);
      this->m_paltpath = v8;
      v9 = v8->m_altName.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v10 = this->m_iName.m_Value.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      if ( v10 != v9 && _V_stricmp(s1: v10, s2: v9) != 0 )
        v8->m_pprevious = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E140
// Name: public: virtual void CPathTrack::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::Activate(CPathTrack *this)
{
  CBaseEntity::Activate(this);
  if ( this->m_iName.m_Value.pszValue != nullptr )
    CPathTrack::Link(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017E160
// Name: public: void CPathTrack::EnableAlternatePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::EnableAlternatePath(CPathTrack *this)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  if ( this->m_paltpath != nullptr )
  {
    m_Value = this->m_spawnflags.m_Value;
    p_m_spawnflags = &this->m_spawnflags;
    v3 = m_Value | 0x8000;
    if ( m_Value != (m_Value | 0x8000) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_spawnflags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E1C0
// Name: public: void CPathTrack::DisableAlternatePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::DisableAlternatePath(CPathTrack *this)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  if ( this->m_paltpath != nullptr )
  {
    m_Value = this->m_spawnflags.m_Value;
    p_m_spawnflags = &this->m_spawnflags;
    v3 = m_Value & 0xFFFF7FFF;
    if ( m_Value != (m_Value & 0xFFFF7FFF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_spawnflags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E220
// Name: private: void CPathTrack::InputEnableAlternatePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputEnableAlternatePath(CPathTrack *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  int v4; // edi
  edict_t *m_pPev; // ecx

  if ( this->m_paltpath != nullptr )
  {
    m_Value = this->m_spawnflags.m_Value;
    p_m_spawnflags = &this->m_spawnflags;
    v4 = m_Value | 0x8000;
    if ( m_Value != (m_Value | 0x8000) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_spawnflags->m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E280
// Name: private: void CPathTrack::InputDisableAlternatePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputDisableAlternatePath(CPathTrack *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  if ( this->m_paltpath != nullptr )
  {
    m_Value = this->m_spawnflags.m_Value;
    p_m_spawnflags = &this->m_spawnflags;
    v4 = m_Value & 0xFFFF7FFF;
    if ( m_Value != (m_Value & 0xFFFF7FFF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_spawnflags->m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E2E0
// Name: private: void CPathTrack::InputEnablePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputEnablePath(CPathTrack *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E330
// Name: private: void CPathTrack::InputDisablePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputDisablePath(CPathTrack *this, inputdata_t *inputdata)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  int v3; // esi
  edict_t *m_pPev; // ecx

  p_m_spawnflags = &this->m_spawnflags;
  v3 = this->m_spawnflags.m_Value | 1;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E3A0
// Name: private: void CPathTrack::InputToggleAlternatePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputToggleAlternatePath(CPathTrack *this, inputdata_t *inputdata)
{
  if ( this->m_paltpath != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 0x8000) != 0 )
      CPathTrack::DisableAlternatePath(this);
    else
      CPathTrack::EnableAlternatePath(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E3D0
// Name: private: void CPathTrack::InputTogglePath(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPathTrack::InputTogglePath(CPathTrack *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // esi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  m_Value = this->m_spawnflags.m_Value;
  p_m_spawnflags = &this->m_spawnflags;
  if ( (m_Value & 1) != 0 )
    v4 = m_Value & 0xFFFFFFFE;
  else
    v4 = m_Value | 1;
  if ( m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_spawnflags->m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      p_m_spawnflags->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10406C10
// Name: CPathTrack_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPathTrack_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPathTrack>(__formal: nullptr);
  CPathTrack_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E0C0
// Name: class CPathTrack __near * _CreateEntityTemplate<class CPathTrack>(class CPathTrack __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPathTrack *__cdecl _CreateEntityTemplate<CPathTrack>(CPathTrack *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPathTrack::`vftable';
    v3[221] = 0;
    v3[224] = -1;
    v3[225] = 0;
    v3[219] = -1;
    v3[220] = 1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPathTrack *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E430
// Name: struct datamap_t __near * DataMapInit<class CPathTrack>(class CPathTrack __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPathTrack>()
{
  if ( (_S2_160 & 1) == 0 )
  {
    _S2_160 |= 1u;
    nameHolder_288.m_pszBase = "CPathTrack";
    nameHolder_288.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_288.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_288.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_288.m_Names.m_Size = 0;
    nameHolder_288.m_Names.m_pElements = nullptr;
    nameHolder_288.m_nLenBase = 10;
    atexit(func: DataMapInit_CPathTrack__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPathTrack::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_160 & 2) == 0 )
  {
    _S2_160 |= 2u;
    dataDesc_275[15].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_275[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_275[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_275[15].override_count = 0;
    *(_QWORD *)dataDesc_275[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_275[15].flatGroup = 0;
  }
  CPathTrack::m_DataMap.dataNumFields = 15;
  CPathTrack::m_DataMap.dataDesc = &dataDesc_275[1];
  return &CPathTrack::m_DataMap;
}
