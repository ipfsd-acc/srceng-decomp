// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/brushops.cpp
// Functions: 121
// ============================================================

#include "hammer\brushops.h"

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: float fabs(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl fabs(float _X)
{
  return fabs(_X);
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const Vector *a, const Vector *b, Vector *result)
{
  result->x = (float)(b->z * a->y) - (float)(a->z * b->y);
  result->y = (float)(a->z * b->x) - (float)(a->x * b->z);
  result->z = (float)(a->x * b->y) - (float)(b->x * a->y);
}

//------------------------------------------------------------------------------
// Address: 0x10001C40
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001C80
// Name: int AfxCrtErrorCheck(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AfxCrtErrorCheck(int error)
{
  int result; // eax

  result = error;
  switch ( error )
  {
    case 0:
    case 80:
      return result;
    case 12:
      AfxThrowMemoryException();
    default:
      AfxThrowInvalidArgException();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D10
// Name: void ATL::Checked::memcpy_s(void __near *,unsigned int,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::Checked::memcpy_s(void *_S1, unsigned int _S1max, const void *_S2, unsigned int _N)
{
  switch ( memcpy_s(dst: _S1, sizeInBytes: _S1max, src: _S2, count: _N) )
  {
    case 0:
    case 80:
      return;
    case 12:
      AfxThrowMemoryException();
    default:
      AfxThrowInvalidArgException();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DB0
// Name: void FreeWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeWinding(winding_t *w)
{
  Vector *p; // eax
  const char *v2; // [esp+0h] [ebp-4h]

  if ( w->numpoints == -559030611 )
    _Error(this: (ISceneTokenProcessor *)&stru_105D72A0, a2: v2);
  p = w->p;
  w->numpoints = -559030611;
  if ( p != nullptr )
  {
    free(pMem: p);
    w->p = nullptr;
  }
  free(pMem: w);
}

//------------------------------------------------------------------------------
// Address: 0x10001E00
// Name: void RemoveDuplicateWindingPoints(struct winding_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveDuplicateWindingPoints(winding_t *pWinding, float fMinDist)
{
  int v2; // edx
  int v3; // edi
  Vector *p; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // [esp-10h] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-4h] [ebp-10h]

  if ( pWinding->numpoints > 0 )
  {
    v2 = 1;
    v3 = 0;
    v8 = 1;
    do
    {
      v11 = v2;
      if ( v2 < pWinding->numpoints )
      {
        v9 = v3 * 12 + 12;
        v10 = v2 + 1;
        do
        {
          p = pWinding->p;
          v5 = p[v3].x - *(float *)((char *)&p->x + v9);
          v6 = p[v3].y - *(float *)((char *)&p->y + v9);
          v7 = p[v3].z - *(float *)((char *)&p->z + v9);
          if ( fMinDist > fsqrt((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v5 * v5)) )
          {
            if ( v10 < pWinding->numpoints )
              memmove(
                dst: (unsigned __int8 *)p + v9,
                src: (unsigned __int8 *)&p[1] + v9,
                count: 12 * (pWinding->numpoints - v11) - 12);
            --pWinding->numpoints;
            v2 = v8;
          }
          ++v10;
          v9 += 12;
          ++v11;
        }
        while ( v11 < pWinding->numpoints );
      }
      ++v2;
      ++v3;
      v8 = v2;
    }
    while ( v2 - 1 < pWinding->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F00
// Name: struct winding_t __near * ClipWinding(struct winding_t __near *,struct PLANE __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl ClipWinding(winding_t *in, PLANE *split)
{
  winding_t *v2; // ebx
  int v3; // eax
  int numpoints; // edi
  int v5; // edx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float dist; // xmm4_4
  Vector *p; // edx
  float v11; // xmm0_4
  bool v12; // zf
  float v13; // xmm0_4
  int v15; // edi
  int *v16; // esi
  void *v17; // eax
  int v18; // edi
  float *p_x; // ecx
  float *v20; // edx
  int v21; // eax
  int v22; // ebx
  Vector *v23; // eax
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  Vector *v29; // eax
  const char *v30; // [esp+0h] [ebp-424h]
  float dists[128]; // [esp+Ch] [ebp-418h]
  int sides[128]; // [esp+20Ch] [ebp-218h]
  int counts[3]; // [esp+40Ch] [ebp-18h] BYREF
  int maxpts; // [esp+418h] [ebp-Ch]
  unsigned int v35; // [esp+41Ch] [ebp-8h]
  Vector *p2; // [esp+420h] [ebp-4h]

  v2 = in;
  v3 = 0;
  numpoints = in->numpoints;
  v5 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = split->normal.y;
    x = split->normal.x;
    z = split->normal.z;
    dist = split->dist;
    p = in->p;
    do
    {
      v11 = (float)((float)((float)(p->y * y) + (float)(x * p->x)) + (float)(p->z * z)) - dist;
      dists[v3] = v11;
      if ( v11 <= 0.01 )
      {
        if ( v11 >= -0.01 )
          sides[v3] = 2;
        else
          sides[v3] = 1;
      }
      else
      {
        sides[v3] = 0;
      }
      ++counts[sides[v3++]];
      ++p;
    }
    while ( v3 < numpoints );
    v5 = counts[1];
  }
  v12 = counts[0] == 0;
  v13 = dists[0];
  sides[v3] = sides[0];
  dists[v3] = v13;
  if ( !v12 )
  {
    if ( v5 == 0 )
      return in;
    v15 = numpoints + 4;
    maxpts = v15;
    if ( v15 > 128 )
      _Error(this: (ISceneTokenProcessor *)&stru_105D7288, a2: (const char *)v15);
    v16 = (int *)MemAlloc_Alloc(nSize: 8u);
    *v16 = 0;
    v17 = calloc(count: v15, size: 0xCu);
    v18 = 0;
    v16[1] = (int)v17;
    if ( in->numpoints <= 0 )
    {
LABEL_43:
      if ( *v16 > maxpts )
        _Error(this: (ISceneTokenProcessor *)&stru_105D72C4, a2: v30);
      if ( v2->numpoints == -559030611 )
        _Error(this: (ISceneTokenProcessor *)&stru_105D72A0, a2: v30);
      v29 = v2->p;
      v2->numpoints = -559030611;
      if ( v29 != nullptr )
      {
        free(pMem: v29);
        v2->p = nullptr;
      }
      free(pMem: v2);
      return (winding_t *)v16;
    }
    v35 = 0;
    while ( 1 )
    {
      p_x = &v2->p[v35 / 0xC].x;
      v20 = (float *)(v16[1] + 12 * *v16);
      v21 = sides[v18];
      if ( v21 != 0 && v21 != 2 )
        goto LABEL_23;
      *v20 = *p_x;
      v20[1] = p_x[1];
      v20[2] = p_x[2];
      ++*v16;
      if ( v21 != 2 )
        break;
LABEL_42:
      v35 += 12;
      if ( ++v18 >= v2->numpoints )
        goto LABEL_43;
    }
    v20 = (float *)(v16[1] + 12 * *v16);
LABEL_23:
    v22 = sides[v18 + 1];
    if ( v22 != 2 && v22 != v21 )
    {
      if ( v18 == in->numpoints - 1 )
        v23 = in->p;
      else
        v23 = (Vector *)(p_x + 3);
      v24 = dists[v18];
      ++*v16;
      v25 = v24 / (float)(v24 - dists[v18 + 1]);
      v26 = split->normal.x;
      v12 = split->normal.x == 1.0;
      p2 = v23;
      if ( v12 )
      {
        *v20 = split->dist;
      }
      else if ( v26 == -1.0 )
      {
        *v20 = -split->dist;
      }
      *v20 = (float)((float)(p2->x - *p_x) * v25) + *p_x;
      v27 = split->normal.y;
      if ( v27 == 1.0 )
      {
        v20[1] = split->dist;
      }
      else if ( v27 == -1.0 )
      {
        v20[1] = -split->dist;
      }
      v20[1] = (float)((float)(p2->y - p_x[1]) * v25) + p_x[1];
      v28 = split->normal.z;
      if ( v28 == 1.0 )
      {
        v20[2] = split->dist;
      }
      else if ( v28 == -1.0 )
      {
        v20[2] = -split->dist;
      }
      v20[2] = (float)((float)(p2->z - p_x[2]) * v25) + p_x[2];
    }
    v2 = in;
    goto LABEL_42;
  }
  if ( v5 == 0 )
    return in;
  free(pMem: in);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002250
// Name: struct winding_t __near * CreateWindingFromPlane(struct PLANE __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__usercall CreateWindingFromPlane@<eax>(const char *a1@<edi>, PLANE *pPlane)
{
  float v2; // xmm1_4
  int v3; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float dist; // xmm1_4
  float v12; // xmm4_4
  float y; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  _DWORD *v17; // esi
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  float *v23; // eax
  float *v24; // eax
  float *v25; // eax
  float v28; // [esp+Ch] [ebp-18h]
  float v29; // [esp+10h] [ebp-14h]
  float v30; // [esp+14h] [ebp-10h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v2 = -65536.0;
  v3 = -1;
  v4 = fabs(pPlane->normal.x);
  if ( v4 > -65536.0 )
  {
    v3 = 0;
    v2 = v4;
  }
  v5 = fabs(pPlane->normal.y);
  if ( v5 > v2 )
  {
    v3 = 1;
    v2 = v5;
  }
  if ( fabs(pPlane->normal.z) <= v2 )
  {
    if ( v3 == -1 )
      _Error(this: (ISceneTokenProcessor *)&stru_105D7314, a2: a1);
  }
  else
  {
    v3 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v3 >= 0 )
  {
    if ( v3 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v8) = COERCE_UNSIGNED_INT(
                  (float)((float)(pPlane->normal.y * vec3_origin.y) + (float)(pPlane->normal.x * x))
                + (float)(pPlane->normal.z * z))
              ^ _mask__NegFloat_;
  v9 = (float)(pPlane->normal.y * v8) + vec3_origin.y;
  v10 = (float)(pPlane->normal.z * v8) + z;
  vup.x = (float)(pPlane->normal.x * v8) + x;
  vup.y = v9;
  vup.z = v10;
  VectorNormalize(vec: &vup);
  dist = pPlane->dist;
  v12 = pPlane->normal.z;
  v28 = pPlane->normal.x * dist;
  y = pPlane->normal.y;
  v29 = y * dist;
  v30 = v12 * dist;
  v14 = (float)(v12 * vup.y) - (float)(y * vup.z);
  v15 = (float)(y * vup.x) - (float)(pPlane->normal.x * vup.y);
  v16 = (float)((float)(pPlane->normal.x * vup.z) - (float)(v12 * vup.x)) * 56755.84;
  vup.x = vup.x * 56755.84;
  vup.y = vup.y * 56755.84;
  vup.z = vup.z * 56755.84;
  v17 = MemAlloc_Alloc(nSize: 8u);
  v18 = (float *)calloc(count: 4u, size: 0xCu);
  v17[1] = v18;
  *v17 = 4;
  *v18 = v28 - (float)(v14 * 56755.84);
  v18[1] = v29 - v16;
  v18[2] = v30 - (float)(v15 * 56755.84);
  v19 = (float *)v17[1];
  *v19 = *v19 + vup.x;
  v19[1] = v19[1] + vup.y;
  v19[2] = v19[2] + vup.z;
  v20 = (float *)v17[1];
  v20[3] = (float)(v14 * 56755.84) + v28;
  v20[4] = v16 + v29;
  v20[5] = (float)(v15 * 56755.84) + v30;
  v21 = (float *)v17[1];
  v21[3] = vup.x + v21[3];
  v21[4] = v21[4] + vup.y;
  v21[5] = v21[5] + vup.z;
  v22 = (float *)v17[1];
  v22[6] = (float)(v14 * 56755.84) + v28;
  v22[7] = v16 + v29;
  v22[8] = (float)(v15 * 56755.84) + v30;
  v23 = (float *)v17[1];
  v23[6] = v23[6] - vup.x;
  v23[7] = v23[7] - vup.y;
  v23[8] = v23[8] - vup.z;
  v24 = (float *)v17[1];
  v24[9] = v28 - (float)(v14 * 56755.84);
  v24[10] = v29 - v16;
  v24[11] = v30 - (float)(v15 * 56755.84);
  v25 = (float *)v17[1];
  v25[9] = v25[9] - vup.x;
  v25[10] = v25[10] - vup.y;
  v25[11] = v25[11] - vup.z;
  return (winding_t *)v17;
}

//------------------------------------------------------------------------------
// Address: 0x10002570
// Name: public: static void CObject::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObject::operator delete(CDmAttributeOp<VMatrix> *this, void *pData)
{
  operator delete(p: pData);
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: public: void CArchive::EnsureRead(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::EnsureRead(CArchive *this, void *lpBuf, unsigned int nCount)
{
  if ( CArchive::Read(this, lpBuf, nMax: nCount) != nCount )
    AfxThrowArchiveException(cause: 3, lpszArchiveName: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10002820
// Name: struct error3d __near * Enum3dErrors(int)
// Source: json
//------------------------------------------------------------------------------
error3d *__cdecl Enum3dErrors(int bStart)
{
  int v1; // ecx

  if ( bStart != 0 )
  {
    v1 = 0;
    iCurrent = 0;
  }
  else
  {
    v1 = iCurrent;
  }
  if ( v1 == nErrors )
    return nullptr;
  iCurrent = v1 + 1;
  return &Errors.m_pData[v1];
}

//------------------------------------------------------------------------------
// Address: 0x10333694
// Name: public: void CArchive::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::Abort(CArchive *this)
{
  CMapPtrToPtr *m_pSchemaMap; // ecx
  CMapPtrToPtr *v3; // ecx
  CPtrArray *m_pLoadArray; // ecx
  void *pTemp; // [esp+8h] [ebp-4h] BYREF

  this->m_pFile = nullptr;
  if ( this->m_bUserBuf == 0 )
  {
    operator delete(p: this->m_lpBufStart);
    this->m_lpBufStart = nullptr;
    this->m_lpBufCur = nullptr;
  }
  m_pSchemaMap = this->m_pSchemaMap;
  if ( m_pSchemaMap != nullptr
    && CMapPtrToPtr::Lookup(this: m_pSchemaMap, key: (void *)1, rValue: &pTemp) != 0
    && pTemp != nullptr )
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)pTemp + 4))(a1: pTemp, a2: 1);
  }
  v3 = this->m_pSchemaMap;
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMapPtrToPtr *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  m_pLoadArray = this->m_pLoadArray;
  this->m_pSchemaMap = nullptr;
  if ( m_pLoadArray != nullptr )
    ((void (__thiscall *)(CPtrArray *, int))m_pLoadArray->dtr_CObject)(a1: m_pLoadArray, a2: 1);
  this->m_pLoadArray = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1033371D
// Name: public: unsigned int CArchive::Read(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CArchive::Read(CArchive *this, char *lpBuf, unsigned int nMax)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned __int8 *m_lpBufStart; // eax
  unsigned int v13; // edi
  unsigned __int8 *lpTemp; // [esp+8h] [ebp-8h]
  unsigned __int8 *lpTempa; // [esp+8h] [ebp-8h]
  unsigned int nLastLeft; // [esp+Ch] [ebp-4h]
  unsigned int nLastLefta; // [esp+Ch] [ebp-4h]
  char *lpBufa; // [esp+18h] [ebp+8h]

  if ( nMax == 0 || lpBuf == nullptr )
    return 0;
  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  m_lpBufCur = this->m_lpBufCur;
  v6 = this->m_lpBufMax - m_lpBufCur;
  if ( nMax < v6 )
    v6 = nMax;
  ATL::Checked::memcpy_s(_S1: lpBuf, _S1max: nMax, _S2: m_lpBufCur, _N: v6);
  this->m_lpBufCur += v6;
  lpBufa = &lpBuf[v6];
  v7 = nMax - v6;
  if ( nMax != v6 )
  {
    v8 = (unsigned __int8 *)(v7 - v7 % this->m_nBufSize);
    lpTemp = nullptr;
    nLastLeft = (unsigned int)v8;
    do
    {
      v9 = this->m_pFile->Read(this: this->m_pFile, a2: lpBufa, a3: nLastLeft);
      lpBufa += v9;
      lpTemp += v9;
      nLastLeft -= v9;
    }
    while ( v9 != 0 && nLastLeft != 0 );
    v7 -= (unsigned int)lpTemp;
    if ( v7 != 0 && lpTemp == v8 )
    {
      v10 = 0;
      if ( this->m_bDirectBuffer != 0 )
      {
        this->m_pFile->GetBufferPtr(
          this: this->m_pFile,
          a2: 0,
          a3: this->m_nBufSize,
          a4: (void **)&this->m_lpBufStart,
          a5: (void **)&this->m_lpBufMax);
        m_lpBufStart = this->m_lpBufStart;
      }
      else
      {
        if ( this->m_bBlocking != 0 || (nLastLefta = this->m_nBufSize, v7 > nLastLefta) )
          nLastLefta = v7;
        lpTempa = this->m_lpBufStart;
        do
        {
          v11 = this->m_pFile->Read(this: this->m_pFile, a2: lpTempa, a3: nLastLefta);
          lpTempa += v11;
          nLastLefta -= v11;
          v10 += v11;
        }
        while ( v11 != 0 && nLastLefta != 0 && v10 < v7 );
        m_lpBufStart = this->m_lpBufStart;
        this->m_lpBufMax = &m_lpBufStart[v10];
      }
      v13 = this->m_lpBufMax - m_lpBufStart;
      this->m_lpBufCur = m_lpBufStart;
      if ( v7 < v13 )
        v13 = v7;
      ATL::Checked::memcpy_s(_S1: lpBufa, _S1max: v7, _S2: m_lpBufStart, _N: v13);
      this->m_lpBufCur += v13;
      v7 -= v13;
    }
  }
  return nMax - v7;
}

//------------------------------------------------------------------------------
// Address: 0x1033384E
// Name: public: void CArchive::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::Flush(CArchive *this)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned __int8 *m_lpBufMax; // edx
  unsigned __int8 *v4; // eax
  unsigned __int8 **p_m_lpBufStart; // edi
  unsigned __int8 *m_lpBufStart; // edx

  m_lpBufCur = this->m_lpBufCur;
  if ( (this->m_nMode & 1) != 0 )
  {
    m_lpBufMax = this->m_lpBufMax;
    if ( m_lpBufMax != m_lpBufCur )
      ((void (__thiscall *)(CFile *, int, int, int))this->m_pFile->Seek)(
        a1: this->m_pFile,
        a2: m_lpBufCur - m_lpBufMax,
        a3: (m_lpBufCur - m_lpBufMax) >> 31,
        a4: 1);
    v4 = this->m_lpBufMax;
  }
  else
  {
    p_m_lpBufStart = &this->m_lpBufStart;
    m_lpBufStart = this->m_lpBufStart;
    if ( this->m_bDirectBuffer != 0 )
    {
      if ( m_lpBufCur != m_lpBufStart )
        this->m_pFile->GetBufferPtr(
          this: this->m_pFile,
          a2: 2u,
          a3: m_lpBufCur - m_lpBufStart,
          a4: nullptr,
          a5: nullptr);
      this->m_pFile->GetBufferPtr(
        this: this->m_pFile,
        a2: 1u,
        a3: this->m_nBufSize,
        a4: (void **)&this->m_lpBufStart,
        a5: (void **)&this->m_lpBufMax);
    }
    else if ( m_lpBufCur != m_lpBufStart )
    {
      this->m_pFile->Write(this: this->m_pFile, a2: m_lpBufStart, a3: m_lpBufCur - m_lpBufStart);
    }
    v4 = *p_m_lpBufStart;
  }
  this->m_lpBufCur = v4;
}

//------------------------------------------------------------------------------
// Address: 0x103338C6
// Name: public: void CArchive::FillBuffer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::FillBuffer(CArchive *this, unsigned int nAdditionalBytesNeeded)
{
  unsigned __int8 *m_lpBufCur; // edx
  unsigned __int8 **p_m_lpBufMax; // ebx
  unsigned __int8 *m_lpBufMax; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *m_lpBufStart; // eax
  unsigned __int8 *v8; // edi
  int v9; // eax
  unsigned __int8 *v10; // eax
  __int64 v11; // [esp-Ch] [ebp-20h]
  unsigned int m_pszData; // [esp-4h] [ebp-18h]
  unsigned int nTotalSizeWanted; // [esp+Ch] [ebp-8h]
  unsigned int nTotalInBuffer; // [esp+10h] [ebp-4h]

  if ( (this->m_nMode & 1) == 0 )
  {
    m_pszData = (unsigned int)this->m_strFileName.m_pszData;
    HIDWORD(v11) = 4;
    goto LABEL_3;
  }
  m_lpBufCur = this->m_lpBufCur;
  p_m_lpBufMax = &this->m_lpBufMax;
  m_lpBufMax = this->m_lpBufMax;
  v6 = (unsigned __int8 *)(this->m_lpBufMax - m_lpBufCur);
  nTotalSizeWanted = (unsigned int)&v6[nAdditionalBytesNeeded];
  if ( this->m_bDirectBuffer != 0 )
  {
    if ( v6 != nullptr )
    {
      m_pszData = 1;
      v11 = m_lpBufCur - this->m_lpBufMax;
      ((void (__thiscall *)(CFile *, _DWORD))this->m_pFile->Seek)(a1: this->m_pFile, a2: v11);
    }
    this->m_pFile->GetBufferPtr(
      this: this->m_pFile,
      a2: 0,
      a3: this->m_nBufSize,
      a4: (void **)&this->m_lpBufStart,
      a5: (void **)&this->m_lpBufMax);
    this->m_lpBufCur = this->m_lpBufStart;
  }
  else
  {
    m_lpBufStart = this->m_lpBufStart;
    if ( m_lpBufCur > m_lpBufStart )
    {
      if ( (int)v6 > 0 )
      {
        ATL::Checked::memmove_s(
          _S1: m_lpBufStart,
          _S1max: m_lpBufMax - m_lpBufStart,
          _S2: m_lpBufCur,
          _N: (unsigned int)v6);
        m_lpBufStart = this->m_lpBufStart;
        this->m_lpBufCur = m_lpBufStart;
        *p_m_lpBufMax = &v6[(_DWORD)m_lpBufStart];
      }
      nTotalInBuffer = (unsigned int)v6;
      if ( this->m_bBlocking == 0 || nAdditionalBytesNeeded >= this->m_nBufSize - (int)v6 )
        nAdditionalBytesNeeded = this->m_nBufSize - (_DWORD)v6;
      v8 = &v6[(_DWORD)m_lpBufStart];
      do
      {
        m_pszData = nAdditionalBytesNeeded;
        HIDWORD(v11) = v8;
        v9 = ((int (__thiscall *)(CFile *))this->m_pFile->Read)(a1: this->m_pFile);
        nTotalInBuffer += v9;
        nAdditionalBytesNeeded -= v9;
        v8 += v9;
      }
      while ( v9 != 0 && nAdditionalBytesNeeded != 0 && nTotalInBuffer < nTotalSizeWanted );
      v10 = this->m_lpBufStart;
      this->m_lpBufCur = v10;
      *p_m_lpBufMax = &v10[nTotalInBuffer];
    }
  }
  if ( this->m_nBufSize < nTotalSizeWanted )
LABEL_3:
    AfxThrowArchiveException(cause: SHIDWORD(v11), lpszArchiveName: (const char *)m_pszData);
  if ( *p_m_lpBufMax - this->m_lpBufCur < nTotalSizeWanted )
    AfxThrowArchiveException(cause: SHIDWORD(v11), lpszArchiveName: (const char *)3);
}

//------------------------------------------------------------------------------
// Address: 0x103339CA
// Name: public: class CArchive __near & CArchive::operator<<(unsigned char)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator<<(CArchive *this, unsigned __int8 by)
{
  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( this->m_lpBufCur + 1 > this->m_lpBufMax )
    CArchive::Flush(this);
  *this->m_lpBufCur++ = by;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333A05
// Name: public: class CArchive __near & CArchive::operator<<(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator<<(CArchive *this, unsigned __int64 dwdw)
{
  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( this->m_lpBufCur + 8 > this->m_lpBufMax )
    CArchive::Flush(this);
  *(_QWORD *)this->m_lpBufCur = dwdw;
  this->m_lpBufCur += 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333A49
// Name: public: class CArchive __near & CArchive::operator<<(unsigned short)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator<<(CArchive *this, unsigned __int16 w)
{
  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( this->m_lpBufCur + 2 > this->m_lpBufMax )
    CArchive::Flush(this);
  *(_WORD *)this->m_lpBufCur = w;
  this->m_lpBufCur += 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333A89
// Name: public: class CArchive __near & CArchive::operator<<(long)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator<<(CArchive *this, unsigned int dw)
{
  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( this->m_lpBufCur + 4 > this->m_lpBufMax )
    CArchive::Flush(this);
  *(_DWORD *)this->m_lpBufCur = dw;
  this->m_lpBufCur += 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333AC7
// Name: public: class CArchive __near & CArchive::operator>>(unsigned char __near &)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator>>(CArchive *this, unsigned __int8 *by)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned __int8 *m_lpBufMax; // ecx

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  m_lpBufCur = this->m_lpBufCur;
  m_lpBufMax = this->m_lpBufMax;
  if ( m_lpBufCur + 1 > m_lpBufMax )
    CArchive::FillBuffer(this, nAdditionalBytesNeeded: m_lpBufCur - m_lpBufMax + 1);
  *by = *this->m_lpBufCur++;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333B0B
// Name: public: class CArchive __near & CArchive::operator>>(unsigned __int64 __near &)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator>>(CArchive *this, unsigned __int64 *dwdw)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned __int8 *m_lpBufMax; // ecx

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  m_lpBufCur = this->m_lpBufCur;
  m_lpBufMax = this->m_lpBufMax;
  if ( m_lpBufCur + 8 > m_lpBufMax )
    CArchive::FillBuffer(this, nAdditionalBytesNeeded: m_lpBufCur - m_lpBufMax + 8);
  *dwdw = *(_QWORD *)this->m_lpBufCur;
  this->m_lpBufCur += 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333B58
// Name: public: class CArchive __near & CArchive::operator>>(unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator>>(CArchive *this, unsigned __int16 *w)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned __int8 *m_lpBufMax; // ecx

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  m_lpBufCur = this->m_lpBufCur;
  m_lpBufMax = this->m_lpBufMax;
  if ( m_lpBufCur + 2 > m_lpBufMax )
    CArchive::FillBuffer(this, nAdditionalBytesNeeded: m_lpBufCur - m_lpBufMax + 2);
  *w = *(_WORD *)this->m_lpBufCur;
  this->m_lpBufCur += 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333BA1
// Name: public: class CArchive __near & CArchive::operator>>(unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::operator>>(CArchive *this, unsigned int *dw)
{
  unsigned __int8 *m_lpBufCur; // eax
  unsigned __int8 *m_lpBufMax; // ecx

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  m_lpBufCur = this->m_lpBufCur;
  m_lpBufMax = this->m_lpBufMax;
  if ( m_lpBufCur + 4 > m_lpBufMax )
    CArchive::FillBuffer(this, nAdditionalBytesNeeded: m_lpBufCur - m_lpBufMax + 4);
  *dw = *(_DWORD *)this->m_lpBufCur;
  this->m_lpBufCur += 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10333DE6
// Name: public: void CArchive::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::Close(CArchive *this)
{
  CArchive::Flush(this);
  this->m_pFile = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10333DF6
// Name: public: void CArchive::Write(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::Write(CArchive *this, char *lpBuf, unsigned int nMax)
{
  unsigned __int8 *m_lpBufCur; // ecx
  unsigned __int8 *v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned __int8 *v10; // eax
  char *lpBufa; // [esp+10h] [ebp+8h]
  char *lpBufb; // [esp+10h] [ebp+8h]

  if ( nMax != 0 && lpBuf != nullptr )
  {
    if ( (this->m_nMode & 1) != 0 )
      AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
    m_lpBufCur = this->m_lpBufCur;
    v5 = (unsigned __int8 *)(this->m_lpBufMax - m_lpBufCur);
    v6 = nMax;
    if ( nMax >= (unsigned int)v5 )
      v6 = this->m_lpBufMax - m_lpBufCur;
    ATL::Checked::memcpy_s(_S1: m_lpBufCur, _S1max: (unsigned int)v5, _S2: lpBuf, _N: v6);
    this->m_lpBufCur += v6;
    lpBufa = &lpBuf[v6];
    v7 = nMax - v6;
    if ( nMax != v6 )
    {
      CArchive::Flush(this);
      v8 = v7 - v7 % this->m_nBufSize;
      this->m_pFile->Write(this: this->m_pFile, a2: lpBufa, a3: v8);
      lpBufb = &lpBufa[v8];
      v9 = v7 - v8;
      if ( this->m_bDirectBuffer != 0 )
      {
        this->m_pFile->GetBufferPtr(
          this: this->m_pFile,
          a2: 1u,
          a3: this->m_nBufSize,
          a4: (void **)&this->m_lpBufStart,
          a5: (void **)&this->m_lpBufMax);
        this->m_lpBufCur = this->m_lpBufStart;
      }
      if ( v9 >= this->m_nBufSize || (v10 = this->m_lpBufCur) != this->m_lpBufStart )
        AfxThrowInvalidArgException();
      ATL::Checked::memcpy_s(_S1: v10, _S1max: v9, _S2: lpBufb, _N: v9);
      this->m_lpBufCur += v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10333EBD
// Name: public: void CArchive::WriteCount(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::WriteCount(CArchive *this, unsigned int dwCount)
{
  if ( dwCount >= 0xFFFF )
  {
    CArchive::operator<<(this, w: 0xFFFFu);
    CArchive::operator<<(this, dw: dwCount);
  }
  else
  {
    CArchive::operator<<(this, w: dwCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10333EEE
// Name: public: unsigned long CArchive::ReadCount(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CArchive::ReadCount(CArchive *this)
{
  unsigned int dwCount; // [esp+4h] [ebp-4h] BYREF

  CArchive::operator>>(this, w: (unsigned __int16 *)&dwCount);
  if ( (_WORD)dwCount != 0xFFFF )
    return (unsigned __int16)dwCount;
  CArchive::operator>>(this, dw: &dwCount);
  return dwCount;
}

//------------------------------------------------------------------------------
// Address: 0x10333F5C
// Name: public: CArchive::~CArchive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::~CArchive(CArchive *this)
{
  if ( this->m_pFile != nullptr && (this->m_nMode & 2) == 0 )
  {
    CArchive::Flush(this);
    this->m_pFile = nullptr;
  }
  CArchive::Abort(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1033405F
// Name: public: CArchive::CArchive(class CFile __near *,unsigned int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
CArchive *__thiscall CArchive::CArchive(
        CArchive *this,
        CFile *pFile,
        unsigned int nMode,
        int nBufSize,
        unsigned __int8 *lpBuf)
{
  ATL::IAtlStringMgr *StringManager; // eax
  CFile *v7; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // eax
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  int m_nBufSize; // edi
  unsigned int v13; // eax
  bool v14; // zf
  unsigned __int8 *m_lpBufStart; // eax

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  v7 = pFile;
  if ( pFile == nullptr )
    AfxThrowInvalidArgException();
  v8 = pFile->GetFilePath(this: pFile, result: &pFile);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strFileName, strSrc: v8);
  ATL::CStringData::Release(this: (ATL::CStringData *)&pFile[-1].m_hFile);
  v9 = nMode;
  this->m_nObjectSchema = -1;
  this->m_nMode = v9;
  this->m_nGrowSize = (v9 & 1) == 0 ? 16 : 64;
  this->m_lpBufStart = lpBuf;
  this->m_pFile = v7;
  this->m_pSchemaMap = nullptr;
  this->m_pLoadArray = nullptr;
  this->m_pDocument = nullptr;
  this->m_bForceFlat = 1;
  this->m_nHashSize = 137;
  this->m_bUserBuf = 1;
  this->m_bDirectBuffer = 0;
  v10 = v7->GetBufferPtr(this: v7, a2: 3u, a3: 0, a4: nullptr, a5: nullptr);
  v11 = nBufSize;
  this->m_bBlocking = v10 & 2;
  if ( v11 >= 128 )
  {
    this->m_nBufSize = v11;
  }
  else
  {
    this->m_nBufSize = 128;
    this->m_lpBufStart = nullptr;
  }
  m_nBufSize = this->m_nBufSize;
  if ( this->m_lpBufStart == nullptr )
  {
    v13 = this->m_pFile->GetBufferPtr(this: this->m_pFile, a2: 3u, a3: 0, a4: nullptr, a5: nullptr) & 1;
    this->m_bDirectBuffer = v13;
    if ( v13 != 0 )
    {
      m_nBufSize = 0;
    }
    else
    {
      this->m_lpBufStart = (unsigned __int8 *)operator new(nSize: this->m_nBufSize);
      this->m_bUserBuf = 0;
    }
  }
  v14 = (this->m_nMode & 1) == 0;
  m_lpBufStart = this->m_lpBufStart;
  this->m_lpBufMax = &m_lpBufStart[m_nBufSize];
  if ( !v14 )
    m_lpBufStart += m_nBufSize;
  this->m_lpBufCur = m_lpBufStart;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10339D78
// Name: public: static void CObject::operator delete(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CObject::operator delete(void *p, void *__formal)
{
  operator delete(p);
}

//------------------------------------------------------------------------------
// Address: 0x1036C1D9
// Name: public: void CArchive::CheckCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::CheckCount(CArchive *this)
{
  if ( this->m_nMapCount >= 0x3FFFFFFE )
    AfxThrowArchiveException(cause: 5, lpszArchiveName: this->m_strFileName.m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x1036C2C1
// Name: public: void CArchive::EnsureSchemaMapExists(class CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const __near &> __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::EnsureSchemaMapExists(
        CArchive *this,
        CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> **ppObjTypeArray)
{
  CMapPtrToPtr *m_pSchemaMap; // esi
  CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *v4; // edi
  CMapPtrToPtr *v5; // eax
  CMapPtrToPtr *v6; // eax
  CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *v7; // eax
  unsigned int m_nGrowSize; // [esp-4h] [ebp-3Ch]
  void *pTemp; // [esp+20h] [ebp-18h] BYREF
  CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *pObjTypeArray; // [esp+24h] [ebp-14h]
  int v11; // [esp+34h] [ebp-4h]

  m_pSchemaMap = this->m_pSchemaMap;
  v4 = nullptr;
  pTemp = nullptr;
  if ( m_pSchemaMap == nullptr )
  {
    v5 = (CMapPtrToPtr *)operator new(nSize: 0x1Cu);
    v11 = 0;
    if ( v5 != nullptr )
      v6 = CMapPtrToPtr::CMapPtrToPtr(this: v5, nBlockSize: 10);
    else
      v6 = nullptr;
    v11 = -1;
    m_pSchemaMap = v6;
  }
  if ( CMapPtrToPtr::Lookup(this: m_pSchemaMap, key: (void *)1, rValue: &pTemp) != 0 )
  {
    pObjTypeArray = (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *)pTemp;
  }
  else
  {
    v7 = (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *)operator new(nSize: 0x14u);
    if ( v7 != nullptr )
    {
      v7->m_pData = nullptr;
      v7->m_nGrowBy = 0;
      v7->m_nMaxSize = 0;
      v7->m_nSize = 0;
      v7->__vftable = (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>_vtbl *)&CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::`vftable';
      v4 = v7;
    }
    m_nGrowSize = this->m_nGrowSize;
    pObjTypeArray = v4;
    v11 = 1;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)v4,
      nNewSize: 1,
      nGrowBy: m_nGrowSize);
    *CMapPtrToPtr::operator[](this: m_pSchemaMap, key: (void *)1) = v4;
  }
  this->m_pSchemaMap = m_pSchemaMap;
  if ( ppObjTypeArray != nullptr )
    *ppObjTypeArray = pObjTypeArray;
}

//------------------------------------------------------------------------------
// Address: 0x1036C3A0
// Name: public: void CArchive::MapObject(class CObject const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::MapObject(CArchive *this, int pOb)
{
  CMapPtrToPtr *v3; // ecx
  CPtrArray *v4; // eax
  CPtrArray *v5; // ecx
  CPtrArray *v6; // eax
  CPtrArray *m_pLoadArray; // eax
  CMapPtrToPtr *m_pSchemaMap; // ecx
  unsigned int m_nMapCount; // [esp-Ch] [ebp-34h]
  unsigned int m_nHashSize; // [esp-8h] [ebp-30h]
  unsigned int m_nGrowSize; // [esp-4h] [ebp-2Ch]
  CArchive::LoadArrayObjType newElement; // [esp+10h] [ebp-18h] BYREF
  void *pTemp; // [esp+14h] [ebp-14h] BYREF
  CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *pObjTypeArray; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+24h] [ebp-4h]

  if ( (this->m_nMode & 1) != 0 )
  {
    if ( this->m_pLoadArray == nullptr )
    {
      v5 = (CPtrArray *)operator new(nSize: 0x14u);
      newElement = (CArchive::LoadArrayObjType)v5;
      v15 = 1;
      if ( v5 != nullptr )
        v6 = CPtrArray::CPtrArray(this: v5);
      else
        v6 = nullptr;
      m_nGrowSize = this->m_nGrowSize;
      v15 = -1;
      this->m_pLoadArray = v6;
      CUIntArray::SetSize(this: v6, nNewSize: 1, nGrowBy: m_nGrowSize);
      m_pLoadArray = this->m_pLoadArray;
      if ( m_pLoadArray->m_nSize <= 0 )
        goto LABEL_14;
      *m_pLoadArray->m_pData = nullptr;
      this->m_nMapCount = 1;
      pObjTypeArray = nullptr;
      CArchive::EnsureSchemaMapExists(this, ppObjTypeArray: &pObjTypeArray);
      newElement = typeUndefined;
      CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::InsertAt(
        this: pObjTypeArray,
        nIndex: 0,
        &newElement,
        nCount: 1);
    }
    if ( pOb == 0 )
      return;
    CArchive::CheckCount(this);
    CPtrArray::InsertAt(this: this->m_pLoadArray, nIndex: this->m_nMapCount, newElement: (void *)pOb, nCount: 1);
    m_pSchemaMap = this->m_pSchemaMap;
    pTemp = nullptr;
    CMapPtrToPtr::Lookup(this: m_pSchemaMap, key: (void *)1, rValue: &pTemp);
    if ( pTemp != nullptr )
    {
      m_nMapCount = this->m_nMapCount;
      pOb = 2;
      CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::InsertAt(
        this: (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *)pTemp,
        nIndex: m_nMapCount,
        newElement: (const CArchive::LoadArrayObjType *)&pOb,
        nCount: 1);
      goto LABEL_19;
    }
LABEL_14:
    AfxThrowInvalidArgException();
  }
  if ( this->m_pLoadArray == nullptr )
  {
    v3 = (CMapPtrToPtr *)operator new(nSize: 0x1Cu);
    newElement = (CArchive::LoadArrayObjType)v3;
    v15 = 0;
    if ( v3 != nullptr )
      v4 = (CPtrArray *)CMapPtrToPtr::CMapPtrToPtr(this: v3, nBlockSize: this->m_nGrowSize);
    else
      v4 = nullptr;
    v15 = -1;
    m_nHashSize = this->m_nHashSize;
    this->m_pLoadArray = v4;
    CMapStringToPtr::InitHashTable(this: (CMapPtrToPtr *)v4, nHashSize: m_nHashSize, bAllocNow: 1);
    *CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: nullptr) = nullptr;
    this->m_nMapCount = 1;
  }
  if ( pOb != 0 )
  {
    CArchive::CheckCount(this);
    *CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: (void *)pOb) = (void *)this->m_nMapCount;
LABEL_19:
    ++this->m_nMapCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036C4DF
// Name: public: void CArchive::WriteClass(struct CRuntimeClass const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::WriteClass(CArchive *this, CRuntimeClass *pClassRef)
{
  unsigned int v3; // edi

  if ( pClassRef == nullptr )
    AfxThrowArchiveException(cause: 6, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 1, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( pClassRef->m_wSchema == 0xFFFF )
    AfxThrowNotSupportedException();
  CArchive::MapObject(this, pOb: 0);
  v3 = (unsigned int)*CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: pClassRef);
  if ( v3 != 0 )
  {
    if ( v3 >= 0x7FFF )
    {
      CArchive::operator<<(this, w: 0x7FFFu);
      CArchive::operator<<(this, dw: v3 | 0x80000000);
    }
    else
    {
      CArchive::operator<<(this, w: v3 | 0x8000);
    }
  }
  else
  {
    CArchive::operator<<(this, w: 0xFFFFu);
    CRuntimeClass::Store(this: pClassRef, ar: this);
    CArchive::CheckCount(this);
    *CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: pClassRef) = (void *)this->m_nMapCount;
    ++this->m_nMapCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036C58E
// Name: public: struct CRuntimeClass __near * CArchive::ReadClass(struct CRuntimeClass const __near *,unsigned int __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CArchive::ReadClass(
        CArchive *this,
        const CRuntimeClass *pClassRefRequested,
        unsigned int *pSchema,
        unsigned int *pObTag)
{
  signed int v5; // ecx
  CRuntimeClass *v7; // eax
  CRuntimeClass *v8; // edi
  unsigned int m_wSchema; // eax
  void *v10; // ebx
  CMapPtrToPtr *m_pSchemaMap; // ecx
  unsigned int v12; // eax
  int v13; // edi
  CMapPtrToPtr *v14; // ecx
  CPtrArray *m_pLoadArray; // eax
  CMapPtrToPtr *v16; // ecx
  unsigned int m_nMapCount; // [esp-Ch] [ebp-28h]
  void *pTemp; // [esp+Ch] [ebp-10h] BYREF
  unsigned int obTag; // [esp+10h] [ebp-Ch] BYREF
  unsigned int nSchema; // [esp+14h] [ebp-8h] BYREF
  int wTag; // [esp+18h] [ebp-4h] BYREF

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 1, lpszArchiveName: this->m_strFileName.m_pszData);
  if ( pClassRefRequested != nullptr && pClassRefRequested->m_wSchema == 0xFFFF )
    AfxThrowNotSupportedException();
  CArchive::MapObject(this, pOb: 0);
  CArchive::operator>>(this, w: (unsigned __int16 *)&wTag);
  if ( (_WORD)wTag == 0x7FFF )
  {
    CArchive::operator>>(this, dw: &obTag);
    v5 = obTag;
  }
  else
  {
    v5 = __PAIR32__(wTag, wTag) & 0x80007FFF;
    obTag = __PAIR32__(wTag, wTag) & 0x80007FFF;
  }
  if ( v5 < 0 )
  {
    if ( (_WORD)wTag == 0xFFFF )
    {
      v7 = CRuntimeClass::Load(ar: this, pwSchemaNum: &nSchema);
      v8 = v7;
      if ( v7 == nullptr )
        goto LABEL_15;
      m_wSchema = v7->m_wSchema;
      if ( (v8->m_wSchema & 0x7FFFFFFF) != nSchema )
      {
        if ( (m_wSchema & 0x80000000) == 0 )
          AfxThrowArchiveException(cause: 7, lpszArchiveName: this->m_strFileName.m_pszData);
        CArchive::EnsureSchemaMapExists(this, ppObjTypeArray: nullptr);
        v10 = (void *)nSchema;
        *CMapPtrToPtr::operator[](this: this->m_pSchemaMap, key: v8) = v10;
      }
      CArchive::CheckCount(this);
      CPtrArray::InsertAt(this: this->m_pLoadArray, nIndex: this->m_nMapCount, newElement: v8, nCount: 1);
      m_pSchemaMap = this->m_pSchemaMap;
      pTemp = nullptr;
      CMapPtrToPtr::Lookup(this: m_pSchemaMap, key: (void *)1, rValue: &pTemp);
      if ( pTemp == nullptr )
LABEL_21:
        AfxThrowInvalidArgException();
      m_nMapCount = this->m_nMapCount;
      wTag = 1;
      CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::InsertAt(
        this: (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *)pTemp,
        nIndex: m_nMapCount,
        newElement: (const CArchive::LoadArrayObjType *)&wTag,
        nCount: 1);
      ++this->m_nMapCount;
      v12 = nSchema;
    }
    else
    {
      v13 = v5 & 0x7FFFFFFF;
      if ( (v5 & 0x7FFFFFFF) == 0 || v13 > (unsigned int)(this->m_pLoadArray->m_nSize - 1) )
        goto LABEL_11;
      v14 = this->m_pSchemaMap;
      wTag = 0;
      CMapPtrToPtr::Lookup(this: v14, key: (void *)1, rValue: (void **)&wTag);
      if ( wTag == 0 || v13 >= *(_DWORD *)(wTag + 8) )
        goto LABEL_21;
      if ( *(_DWORD *)(*(_DWORD *)(wTag + 4) + 4 * v13) == 2 )
LABEL_11:
        AfxThrowArchiveException(cause: 5, lpszArchiveName: this->m_strFileName.m_pszData);
      m_pLoadArray = this->m_pLoadArray;
      if ( v13 >= m_pLoadArray->m_nSize )
        goto LABEL_21;
      v8 = (CRuntimeClass *)m_pLoadArray->m_pData[v13];
      v16 = this->m_pSchemaMap;
      nSchema = 0;
      if ( v16 != nullptr && CMapPtrToPtr::Lookup(this: v16, key: v8, rValue: (void **)&wTag) != 0 )
        v12 = wTag;
      else
        v12 = v8->m_wSchema & 0x7FFFFFFF;
      nSchema = v12;
    }
    if ( pClassRefRequested != nullptr )
    {
      if ( CRuntimeClass::IsDerivedFrom(this: v8, pBaseClass: pClassRefRequested) == 0 )
LABEL_15:
        AfxThrowArchiveException(cause: 6, lpszArchiveName: this->m_strFileName.m_pszData);
      v12 = nSchema;
    }
    if ( pSchema != nullptr )
      *pSchema = v12;
    else
      this->m_nObjectSchema = v12;
    if ( pObTag != nullptr )
      *pObTag = obTag;
    return v8;
  }
  if ( pObTag == nullptr )
    goto LABEL_11;
  *pObTag = v5;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1036C7D3
// Name: public: void CArchive::WriteObject(class CObject const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchive::WriteObject(CArchive *this, CObject *pOb)
{
  unsigned int v3; // ebx
  CRuntimeClass *v4; // eax

  if ( (this->m_nMode & 1) != 0 )
    AfxThrowArchiveException(cause: 2, lpszArchiveName: this->m_strFileName.m_pszData);
  CArchive::MapObject(this, pOb: 0);
  if ( pOb != nullptr )
  {
    v3 = (unsigned int)*CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: pOb);
    if ( v3 != 0 )
    {
      if ( v3 >= 0x7FFF )
      {
        CArchive::operator<<(this, w: 0x7FFFu);
        CArchive::operator<<(this, dw: v3);
      }
      else
      {
        CArchive::operator<<(this, w: v3);
      }
    }
    else
    {
      v4 = (CRuntimeClass *)pOb->GetRuntimeClass(this: pOb);
      CArchive::WriteClass(this, pClassRef: v4);
      CArchive::CheckCount(this);
      *CMapPtrToPtr::operator[](this: this->m_pStoreMap, key: pOb) = (void *)this->m_nMapCount;
      ++this->m_nMapCount;
      pOb->Serialize(this: pOb, a2: this);
    }
  }
  else
  {
    CArchive::operator<<(this, w: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036C86F
// Name: public: class CObject __near * CArchive::ReadObject(struct CRuntimeClass const __near *)
// Source: json
//------------------------------------------------------------------------------
CObject *__thiscall CArchive::ReadObject(CArchive *this, CRuntimeClass *pClassRefRequested)
{
  CRuntimeClass *v3; // eax
  signed int v4; // edi
  CMapPtrToPtr *v5; // ecx
  signed int v6; // eax
  CPtrArray *m_pLoadArray; // eax
  CObject *Object; // edi
  CMapPtrToPtr *m_pSchemaMap; // ecx
  unsigned int v10; // eax
  unsigned int m_nObjectSchema; // ebx
  unsigned int m_nMapCount; // [esp-Ch] [ebp-3Ch]
  unsigned int nSchema; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int obTag; // [esp+18h] [ebp-18h] BYREF
  void *pTemp; // [esp+1Ch] [ebp-14h] BYREF
  int v17; // [esp+2Ch] [ebp-4h]

  if ( (this->m_nMode & 1) == 0 )
    AfxThrowArchiveException(cause: 4, lpszArchiveName: this->m_strFileName.m_pszData);
  v3 = CArchive::ReadClass(this, pClassRefRequested, pSchema: &nSchema, pObTag: &obTag);
  pTemp = nullptr;
  if ( v3 != nullptr )
  {
    v17 = 0;
    Object = CRuntimeClass::CreateObject(this: v3);
    pTemp = Object;
    if ( Object == nullptr )
      AfxThrowMemoryException();
    CArchive::CheckCount(this);
    CPtrArray::InsertAt(this: this->m_pLoadArray, nIndex: this->m_nMapCount, newElement: Object, nCount: 1);
    m_pSchemaMap = this->m_pSchemaMap;
    pClassRefRequested = nullptr;
    CMapPtrToPtr::Lookup(this: m_pSchemaMap, key: (void *)1, rValue: (void **)&pClassRefRequested);
    if ( pClassRefRequested != nullptr )
    {
      m_nMapCount = this->m_nMapCount;
      obTag = 2;
      CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &>::InsertAt(
        this: (CArray<enum CArchive::LoadArrayObjType,enum CArchive::LoadArrayObjType const &> *)pClassRefRequested,
        nIndex: m_nMapCount,
        newElement: (const CArchive::LoadArrayObjType *)&obTag,
        nCount: 1);
      v10 = nSchema;
      m_nObjectSchema = this->m_nObjectSchema;
      ++this->m_nMapCount;
      this->m_nObjectSchema = v10;
      Object->Serialize(this: Object, a2: this);
      this->m_nObjectSchema = m_nObjectSchema;
      return Object;
    }
    goto LABEL_8;
  }
  v4 = obTag;
  if ( obTag > this->m_pLoadArray->m_nSize - 1 )
    goto LABEL_5;
  v5 = this->m_pSchemaMap;
  pTemp = nullptr;
  if ( CMapPtrToPtr::Lookup(this: v5, key: (void *)1, rValue: &pTemp) != 0 )
  {
    if ( pTemp == nullptr )
      goto LABEL_8;
    v6 = *((_DWORD *)pTemp + 2);
    if ( v4 <= (unsigned int)(v6 - 1) )
    {
      if ( v4 >= 0 && v4 < v6 )
      {
        if ( *(_DWORD *)(*((_DWORD *)pTemp + 1) + 4 * v4) == 1 )
LABEL_5:
          AfxThrowArchiveException(cause: 5, lpszArchiveName: this->m_strFileName.m_pszData);
        goto LABEL_13;
      }
LABEL_8:
      AfxThrowInvalidArgException();
    }
  }
LABEL_13:
  m_pLoadArray = this->m_pLoadArray;
  if ( v4 < 0 || v4 >= m_pLoadArray->m_nSize )
    goto LABEL_8;
  Object = (CObject *)m_pLoadArray->m_pData[v4];
  if ( Object != nullptr
    && pClassRefRequested != nullptr
    && CObject::IsKindOf(this: Object, pClass: pClassRefRequested) == 0 )
  {
    AfxThrowArchiveException(cause: 6, lpszArchiveName: this->m_strFileName.m_pszData);
  }
  return Object;
}

//------------------------------------------------------------------------------
// Address: 0x104373DB
// Name: _memcpy_s
// Source: json
//------------------------------------------------------------------------------
int __cdecl memcpy_s(unsigned __int8 *dst, unsigned int sizeInBytes, unsigned __int8 *src, unsigned int count)
{
  int v5; // esi

  if ( count == 0 )
    return 0;
  if ( dst != nullptr )
  {
    if ( src != nullptr && sizeInBytes >= count )
    {
      memcpy(dst, src, count);
      return 0;
    }
    memset(dst, value: 0, count: sizeInBytes);
    if ( src != nullptr )
    {
      if ( sizeInBytes < count )
      {
        *_errno() = 34;
        v5 = 34;
        goto LABEL_5;
      }
      return 22;
    }
  }
  v5 = 22;
  *_errno() = 22;
LABEL_5:
  _invalid_parameter_noinfo();
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10333BE8
// Name: unsigned int AfxReadStringLength(class CArchive __near &,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__stdcall AfxReadStringLength(CArchive *ar, int *nCharSize)
{
  int *v2; // esi
  CArchive *v3; // edi
  CArchive *v4; // ecx
  int *result; // eax
  unsigned __int64 qwLength; // [esp+8h] [ebp-8h] BYREF

  v2 = nCharSize;
  v3 = ar;
  v4 = ar;
  *nCharSize = 1;
  CArchive::operator>>(this: v4, by: (unsigned __int8 *)&nCharSize + 3);
  if ( HIBYTE(nCharSize) != 0xFF )
    return (int *)HIBYTE(nCharSize);
  CArchive::operator>>(this: v3, w: (unsigned __int16 *)&ar);
  if ( (_WORD)ar == 0xFFFE )
  {
    *v2 = 2;
    CArchive::operator>>(this: v3, by: (unsigned __int8 *)&nCharSize + 3);
    if ( HIBYTE(nCharSize) != 0xFF )
      return (int *)HIBYTE(nCharSize);
    CArchive::operator>>(this: v3, w: (unsigned __int16 *)&ar);
  }
  if ( (_WORD)ar != 0xFFFF )
    return (int *)(unsigned __int16)ar;
  CArchive::operator>>(this: v3, dw: (unsigned int *)&nCharSize);
  result = nCharSize;
  if ( nCharSize == (int *)-1 )
  {
    CArchive::operator>>(this: v3, dwdw: &qwLength);
    if ( HIDWORD(qwLength) != 0 || (result = (int *)qwLength, (unsigned int)qwLength > 0x7FFFFFFF) )
      AfxThrowArchiveException(cause: 1, lpszArchiveName: nullptr);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10333C99
// Name: void AfxWriteStringLength(class CArchive __near &,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxWriteStringLength(CArchive *ar, unsigned int nLength, int bUnicode)
{
  if ( bUnicode != 0 )
  {
    CArchive::operator<<(this: ar, by: 0xFFu);
    CArchive::operator<<(this: ar, w: 0xFFFEu);
  }
  if ( nLength >= 0xFF )
  {
    CArchive::operator<<(this: ar, by: 0xFFu);
    if ( nLength >= 0xFFFE )
    {
      CArchive::operator<<(this: ar, w: 0xFFFFu);
      if ( nLength == -1 )
      {
        CArchive::operator<<(this: ar, dw: 0xFFFFFFFF);
        CArchive::operator<<(this: ar, dwdw: 0xFFFFFFFF);
      }
      else
      {
        CArchive::operator<<(this: ar, dw: nLength);
      }
    }
    else
    {
      CArchive::operator<<(this: ar, w: nLength);
    }
  }
  else
  {
    CArchive::operator<<(this: ar, by: nLength);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10333D1D
// Name: public: static struct CRuntimeClass __near * CRuntimeClass::FromName(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__stdcall CRuntimeClass::FromName(const char *lpszClassName)
{
  AFX_MODULE_STATE *ModuleState; // esi
  LPCSTR *i; // esi

  if ( lpszClassName == nullptr )
    AfxThrowInvalidArgException();
  ModuleState = AfxGetModuleState();
  AfxLockGlobals(nLockType: 0);
  for ( i = (LPCSTR *)ModuleState->m_classList.m_pHead; ; i = (LPCSTR *)i[5] )
  {
    if ( i == nullptr )
    {
      AfxUnlockGlobals(nLockType: 0);
      return nullptr;
    }
    if ( lstrcmpA(lpString1: lpszClassName, lpString2: *i) == 0 )
      break;
  }
  AfxUnlockGlobals(nLockType: 0);
  return (CRuntimeClass *)i;
}

//------------------------------------------------------------------------------
// Address: 0x10333D6F
// Name: public: static struct CRuntimeClass __near * CRuntimeClass::Load(class CArchive __near &,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__stdcall CRuntimeClass::Load(CArchive *ar, unsigned int *pwSchemaNum)
{
  int v2; // esi
  unsigned __int16 nLen; // [esp+8h] [ebp-48h] BYREF
  char szClassName[64]; // [esp+Ch] [ebp-44h] BYREF

  if ( pwSchemaNum == nullptr )
    return nullptr;
  CArchive::operator>>(this: ar, w: &nLen);
  *pwSchemaNum = nLen;
  CArchive::operator>>(this: ar, w: &nLen);
  if ( nLen >= 0x40u )
    return nullptr;
  v2 = nLen;
  if ( CArchive::Read(this: ar, lpBuf: szClassName, nMax: nLen) != v2 )
    return nullptr;
  szClassName[v2] = 0;
  return CRuntimeClass::FromName(lpszClassName: szClassName);
}

//------------------------------------------------------------------------------
// Address: 0x10333F22
// Name: public: void CRuntimeClass::Store(class CArchive __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRuntimeClass::Store(CRuntimeClass *this, CArchive *ar)
{
  unsigned __int16 v3; // ax
  unsigned int v4; // edi
  CArchive *v5; // eax
  unsigned __int16 v6; // [esp-4h] [ebp-Ch]

  v3 = lstrlenA(lpString: this->m_lpszClassName);
  v4 = v3;
  v6 = v3;
  v5 = CArchive::operator<<(this: ar, w: this->m_wSchema);
  CArchive::operator<<(this: v5, w: v6);
  CArchive::Write(this: ar, lpBuf: (char *)this->m_lpszClassName, nMax: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10339D8A
// Name: public: virtual long CWnd::XAccessible::get_accHelp(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accHelp(CWnd::XAccessible *this, tagVARIANT varChild, wchar_t **pszHelp)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 184))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszHelp);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10339DDB
// Name: public: virtual long CWnd::XAccessible::get_accHelpTopic(wchar_t __near * __near *,struct tagVARIANT,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accHelpTopic(
        CWnd::XAccessible *this,
        wchar_t **pszHelpFile,
        tagVARIANT varChild,
        int *pidTopic)
{
  int v4; // eax
  int v5; // eax
  int v6; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v4 = *((_DWORD *)this - 12);
  v9 = 0;
  v5 = (*(int (__thiscall **)(CWnd::XAccessible *, wchar_t **, _DWORD, unsigned int, unsigned int, unsigned int, int *))(v4 + 188))(
         a1: this - 12,
         a2: pszHelpFile,
         a3: *(_DWORD *)&varChild.vt,
         a4: varChild.decVal.Hi32,
         a5: varChild.decVal.Lo32,
         a6: varChild.decVal.Mid32,
         a7: pidTopic);
  v9 = -1;
  v6 = v5;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10339E2F
// Name: public: virtual long CWnd::XAccessible::get_accKeyboardShortcut(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accKeyboardShortcut(
        CWnd::XAccessible *this,
        tagVARIANT varChild,
        wchar_t **pszKeyboardShortcut)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 192))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszKeyboardShortcut);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10339E80
// Name: public: virtual long CWnd::XAccessible::get_accFocus(struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accFocus(CWnd::XAccessible *this, tagVARIANT *pvarChild)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v2 = *((_DWORD *)this - 12);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessible *, tagVARIANT *))(v2 + 196))(a1: this - 12, a2: pvarChild);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10339EC5
// Name: public: virtual long CWnd::XAccessible::get_accSelection(struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accSelection(CWnd::XAccessible *this, tagVARIANT *pvarChildren)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v2 = *((_DWORD *)this - 12);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessible *, tagVARIANT *))(v2 + 200))(a1: this - 12, a2: pvarChildren);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10339F0A
// Name: public: virtual long CWnd::XAccessible::get_accDefaultAction(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::get_accDefaultAction(
        CWnd::XAccessible *this,
        tagVARIANT varChild,
        wchar_t **pszDefaultAction)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t **))(v3 + 204))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: pszDefaultAction);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10339F5B
// Name: public: virtual long CWnd::XAccessible::accSelect(long,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::accSelect(CWnd::XAccessible *this, int flagsSelect, tagVARIANT varChild)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int))(v3 + 208))(
         a1: this - 12,
         a2: flagsSelect,
         a3: *(_DWORD *)&varChild.vt,
         a4: varChild.decVal.Hi32,
         a5: varChild.decVal.Lo32,
         a6: varChild.decVal.Mid32);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10339FAC
// Name: public: virtual long CWnd::XAccessible::accLocation(long __near *,long __near *,long __near *,long __near *,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::accLocation(
        CWnd::XAccessible *this,
        int *pxLeft,
        int *pyTop,
        int *pcxWidth,
        int *pcyHeight,
        tagVARIANT varChild)
{
  int v6; // eax
  int v7; // eax
  int v8; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v6 = *((_DWORD *)this - 12);
  v11 = 0;
  v7 = (*(int (__thiscall **)(CWnd::XAccessible *, int *, int *, int *, int *, _DWORD, unsigned int, unsigned int, unsigned int))(v6 + 212))(
         a1: this - 12,
         a2: pxLeft,
         a3: pyTop,
         a4: pcxWidth,
         a5: pcyHeight,
         a6: *(_DWORD *)&varChild.vt,
         a7: varChild.decVal.Hi32,
         a8: varChild.decVal.Lo32,
         a9: varChild.decVal.Mid32);
  v11 = -1;
  v8 = v7;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1033A006
// Name: public: virtual long CWnd::XAccessible::accNavigate(long,struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::accNavigate(
        CWnd::XAccessible *this,
        int navDir,
        tagVARIANT varStart,
        tagVARIANT *pvarEndUpAt)
{
  int v4; // eax
  int v5; // eax
  int v6; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v4 = *((_DWORD *)this - 12);
  v9 = 0;
  v5 = (*(int (__thiscall **)(CWnd::XAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))(v4 + 216))(
         a1: this - 12,
         a2: navDir,
         a3: *(_DWORD *)&varStart.vt,
         a4: varStart.decVal.Hi32,
         a5: varStart.decVal.Lo32,
         a6: varStart.decVal.Mid32,
         a7: pvarEndUpAt);
  v9 = -1;
  v6 = v5;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1033A05A
// Name: public: virtual long CWnd::XAccessible::accHitTest(long,long,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::accHitTest(CWnd::XAccessible *this, int xLeft, int yTop, tagVARIANT *pvarChild)
{
  int v4; // eax
  int v5; // eax
  int v6; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v4 = *((_DWORD *)this - 12);
  v9 = 0;
  v5 = (*(int (__thiscall **)(CWnd::XAccessible *, int, int, tagVARIANT *))(v4 + 220))(
         a1: this - 12,
         a2: xLeft,
         a3: yTop,
         a4: pvarChild);
  v9 = -1;
  v6 = v5;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1033A0A5
// Name: public: virtual long CWnd::XAccessible::accDoDefaultAction(struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::accDoDefaultAction(CWnd::XAccessible *this, tagVARIANT varChild)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v2 = *((_DWORD *)this - 12);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int))(v2 + 224))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033A0F3
// Name: public: virtual long CWnd::XAccessible::put_accName(struct tagVARIANT,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::put_accName(CWnd::XAccessible *this, tagVARIANT varChild, wchar_t *szName)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t *))(v3 + 228))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: szName);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033A144
// Name: public: virtual long CWnd::XAccessible::put_accValue(struct tagVARIANT,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessible::put_accValue(CWnd::XAccessible *this, tagVARIANT varChild, wchar_t *szValue)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 5));
  v3 = *((_DWORD *)this - 12);
  v8 = 0;
  v4 = (*(int (__thiscall **)(CWnd::XAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, wchar_t *))(v3 + 232))(
         a1: this - 12,
         a2: *(_DWORD *)&varChild.vt,
         a3: varChild.decVal.Hi32,
         a4: varChild.decVal.Lo32,
         a5: varChild.decVal.Mid32,
         a6: szValue);
  v8 = -1;
  v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1033A195
// Name: public: virtual unsigned long CWnd::XAccessibleServer::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CWnd::XAccessibleServer::AddRef(CWnd::XAccessibleServer *this)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v5 = 0;
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 13));
  v5 = -1;
  v2 = v1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033A1D3
// Name: public: virtual unsigned long CWnd::XAccessibleServer::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CWnd::XAccessibleServer::Release(CWnd::XAccessibleServer *this)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v5 = 0;
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 13));
  v5 = -1;
  v2 = v1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1033A211
// Name: public: virtual long CWnd::XAccessibleServer::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CWnd::XAccessibleServer::QueryInterface(
        CWnd::XAccessibleServer *this,
        const _GUID *iid,
        void **ppvObj)
{
  unsigned int Interface; // eax
  unsigned int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v7 = 0;
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 13), iid, ppvObj);
  v7 = -1;
  v4 = Interface;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033A255
// Name: public: virtual long CWnd::XAccessibleServer::SetProxy(struct IAccessibleProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessibleServer::SetProxy(CWnd::XAccessibleServer *this, IAccessibleProxy *pProxy)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  v2 = *((_DWORD *)this - 13);
  v7 = 0;
  v3 = (*(int (__thiscall **)(CWnd::XAccessibleServer *, IAccessibleProxy *))(v2 + 236))(a1: this - 13, a2: pProxy);
  v7 = -1;
  v4 = v3;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1033A29A
// Name: public: virtual long CWnd::XAccessibleServer::GetHWND(struct HWND__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessibleServer::GetHWND(CWnd::XAccessibleServer *this, HWND__ **phWnd)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  if ( phWnd == nullptr )
    return -2147467261;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 6));
  *phWnd = *((HWND__ **)this - 5);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1033A2D4
// Name: public: virtual long CWnd::XAccessibleServer::GetEnumVariant(struct IEnumVARIANT __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CWnd::XAccessibleServer::GetEnumVariant(CWnd::XAccessibleServer *this, IEnumVARIANT **ppEnumVariant)
{
  if ( ppEnumVariant == nullptr )
    return -2147467261;
  *ppEnumVariant = nullptr;
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x1036C9DA
// Name: void _AfxAbbreviateName(char __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxAbbreviateName(char *lpszCanon, int cchMax, int bAtLeastName)
{
  signed int v4; // ebx
  int v5; // esi
  char *v6; // eax
  int v7; // esi
  int v8; // eax
  char *lpszFileName; // [esp+Ch] [ebp-8h]
  int cchFullPath; // [esp+10h] [ebp-4h]
  const unsigned __int8 *lpszCur; // [esp+1Ch] [ebp+8h]

  if ( AfxIsValidString(psz: lpszCanon, nLength: -1) == 0 )
    AfxThrowInvalidArgException();
  cchFullPath = lstrlenA(lpString: lpszCanon);
  v4 = AfxGetFileName(lpszPathName: lpszCanon, lpszTitle: nullptr, nMax: 0) - 1;
  v5 = cchFullPath - v4;
  lpszFileName = &lpszCanon[cchFullPath - v4];
  if ( cchMax < cchFullPath )
  {
    if ( cchMax >= v4 )
    {
      v6 = lpszCanon + 2;
      lpszCur = (const unsigned __int8 *)(lpszCanon + 2);
      if ( *lpszCanon == 92 && lpszCanon[1] == 92 )
      {
        while ( *v6 != 92 )
        {
          v6 = (char *)_mbsinc(current: lpszCur);
          lpszCur = (const unsigned __int8 *)v6;
        }
      }
      if ( v5 > 3 )
      {
        do
          lpszCur = _mbsinc(current: lpszCur);
        while ( *lpszCur != 92 );
      }
      v7 = lpszCur - (const unsigned __int8 *)lpszCanon;
      if ( cchMax >= lpszCur - (const unsigned __int8 *)lpszCanon + v4 + 5 )
      {
        while ( lstrlenA(lpString: (LPCSTR)lpszCur) + v7 + 4 > cchMax )
        {
          do
            lpszCur = _mbsinc(current: lpszCur);
          while ( *lpszCur != 92 );
        }
        if ( v7 < 0 || v7 >= cchMax )
          v7 = cchMax;
        v8 = memcpy_s(
               dst: (unsigned __int8 *)&lpszCanon[v7],
               sizeInBytes: cchFullPath - v7 + 1,
               src: "\\...",
               count: 5u);
        AfxCrtErrorCheck(error: v8);
        ATL::Checked::tcscat_s(_Dst: lpszCanon, _SizeInChars: cchFullPath + 1, _Src: (const char *)lpszCur);
      }
      else
      {
        ATL::Checked::tcscpy_s(_Dst: lpszCanon, _SizeInChars: cchFullPath + 1, _Src: lpszFileName);
      }
    }
    else if ( bAtLeastName != 0 )
    {
      ATL::Checked::tcscpy_s(_Dst: lpszCanon, _SizeInChars: cchFullPath + 1, _Src: &lpszCanon[v5]);
    }
    else
    {
      *lpszCanon = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036CB52
// Name: public: virtual CRecentFileList::~CRecentFileList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::~CRecentFileList(CRecentFileList *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_arrNames; // ecx

  m_arrNames = this->m_arrNames;
  this->__vftable = (CRecentFileList_vtbl *)&CRecentFileList::`vftable';
  if ( m_arrNames != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::`vector deleting destructor'(this: m_arrNames, a2: 3u);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strOriginal.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strEntryFormat.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strSectionName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1036CB8D
// Name: public: virtual void CRecentFileList::WriteList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::WriteList(CRecentFileList *this)
{
  unsigned int v2; // ebx
  int v3; // edi
  char *m_pszData; // edi
  int v5; // [esp+Ch] [ebp-Ch]
  CWinApp *pApp; // [esp+10h] [ebp-8h]
  char *pszEntry; // [esp+14h] [ebp-4h]

  v2 = *((_DWORD *)this->m_strEntryFormat.m_pszData - 3) + 10;
  pszEntry = (char *)operator new(nSize: v2);
  v3 = 0;
  pApp = AfxGetModuleState()->m_pCurrentWinApp;
  pApp->WriteProfileStringA(this: pApp, a2: this->m_strSectionName.m_pszData, a3: nullptr, a4: nullptr);
  if ( this->m_nSize > 0 )
  {
    do
    {
      v5 = v3 + 1;
      sprintf_s(string: pszEntry, sizeInBytes: v2, format: this->m_strEntryFormat.m_pszData, v3 + 1);
      m_pszData = this->m_arrNames[v3].m_pszData;
      if ( *((_DWORD *)m_pszData - 3) != 0 )
        pApp->WriteProfileStringA(this: pApp, a2: this->m_strSectionName.m_pszData, a3: pszEntry, a4: m_pszData);
      v3 = v5;
    }
    while ( v5 < this->m_nSize );
  }
  operator delete(p: pszEntry);
}

//------------------------------------------------------------------------------
// Address: 0x1036CC39
// Name: public: virtual int CRecentFileList::GetDisplayName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,int,char const __near *,int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRecentFileList::GetDisplayName(
        CRecentFileList *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strName,
        int nIndex,
        const char *lpszCurDir,
        int nCurDir,
        int bAtLeastName)
{
  int v7; // ebx
  unsigned __int8 *v8; // edi
  int v9; // eax
  unsigned int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int _Arg2; // [esp+Ch] [ebp-120h]
  char chSave; // [esp+23h] [ebp-109h]
  char szTemp[260]; // [esp+24h] [ebp-108h] BYREF

  if ( lpszCurDir != nullptr && AfxIsValidString(psz: lpszCurDir, nLength: nCurDir) == 0 || nIndex >= this->m_nSize )
    AfxThrowInvalidArgException();
  if ( lpszCurDir == nullptr )
    return 0;
  v7 = *((_DWORD *)this->m_arrNames[nIndex].m_pszData - 3);
  if ( v7 == 0 )
    return 0;
  _Arg2 = v7 + 1;
  v8 = (unsigned __int8 *)ATL::CSimpleStringT<char,0>::PrepareWrite(this: strName, nLength: v7 + 1);
  if ( v8 == nullptr )
    AfxThrowMemoryException();
  v9 = _mbsnbcpy_s(
         _Arg1: v8,
         _Arg2,
         _Arg3: (const unsigned __int8 *)this->m_arrNames[nIndex].m_pszData,
         _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v9);
  v10 = v7 - AfxGetFileName(lpszPathName: (const char *)v8, lpszTitle: nullptr, nMax: 0) + 1;
  if ( v10 == nCurDir
    && (chSave = v8[v10],
        v8[nCurDir] = 0,
        v11 = AfxComparePath(lpszPath1: lpszCurDir, lpszPath2: (const char *)v8),
        v8[v10] = chSave,
        v11 != 0) )
  {
    AfxGetFileTitle(lpszPathName: (const char *)&v8[nCurDir], lpszTitle: szTemp, nMax: 0x104u);
    v12 = _mbsnbcpy_s(_Arg1: v8, _Arg2, _Arg3: (const unsigned __int8 *)szTemp, _Arg4: 0xFFFFFFFF);
    AfxCrtErrorCheck(error: v12);
  }
  else if ( this->m_nMaxDisplayLength != -1 )
  {
    AfxGetFileTitle(lpszPathName: (const char *)&v8[v10], lpszTitle: szTemp, nMax: 0x104u);
    v13 = _mbsnbcpy_s(_Arg1: &v8[v10], _Arg2: v7 - v10 + 1, _Arg3: (const unsigned __int8 *)szTemp, _Arg4: 0xFFFFFFFF);
    AfxCrtErrorCheck(error: v13);
    _AfxAbbreviateName(lpszCanon: (char *)v8, cchMax: this->m_nMaxDisplayLength, bAtLeastName);
  }
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: strName, nNewLength: -1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036CDE9
// Name: public: virtual void CRecentFileList::Remove(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::Remove(CRecentFileList *this, int nIndex)
{
  int v2; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // ecx

  v2 = nIndex;
  if ( nIndex < 0 || nIndex >= this->m_nSize )
    AfxThrowInvalidArgException();
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_arrNames[nIndex]);
  while ( 1 )
  {
    v4 = &this->m_arrNames[v2];
    if ( v2 >= this->m_nSize - 1 )
      break;
    ATL::CSimpleStringT<char,0>::operator=(this: v4, strSrc: v4 + 1);
    ++v2;
  }
  ATL::CSimpleStringT<char,0>::Empty(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1036CE33
// Name: public: virtual void CRecentFileList::ReadList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::ReadList(CRecentFileList *this)
{
  CWinApp *m_pCurrentWinApp; // ebx
  int i; // edi
  const ATL::CSimpleStringT<char,0> *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_arrNames; // ecx
  int v6; // [esp+14h] [ebp-18h] BYREF
  int nLen; // [esp+18h] [ebp-14h]
  char *pszEntry; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  nLen = *((_DWORD *)this->m_strEntryFormat.m_pszData - 3) + 10;
  pszEntry = (char *)operator new(nSize: nLen);
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  for ( i = 0; i < this->m_nSize; ++i )
  {
    sprintf_s(string: pszEntry, sizeInBytes: nLen, format: this->m_strEntryFormat.m_pszData, i + 1);
    v4 = m_pCurrentWinApp->GetProfileStringA(
           this: m_pCurrentWinApp,
           result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v6,
           a3: this->m_strSectionName.m_pszData,
           a4: pszEntry,
           a5: &szGroupName);
    m_arrNames = this->m_arrNames;
    v9 = 0;
    ATL::CSimpleStringT<char,0>::operator=(this: &m_arrNames[i], strSrc: v4);
    v9 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)(v6 - 16));
  }
  operator delete(p: pszEntry);
}

//------------------------------------------------------------------------------
// Address: 0x1036CECF
// Name: public: CRecentFileList::CRecentFileList(unsigned int,char const __near *,char const __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentFileList *__thiscall CRecentFileList::CRecentFileList(
        CRecentFileList *this,
        unsigned int nStart,
        const char *lpszSection,
        const char *lpszEntryFormat,
        int nSize,
        int nMaxDispLen)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // ebx
  ATL::IAtlStringMgr *v9; // eax
  ATL::IAtlStringMgr *v10; // eax
  int v11; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v12; // eax

  this->__vftable = (CRecentFileList_vtbl *)&CRecentFileList::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strSectionName, pStringMgr: StringManager);
  v8 = nullptr;
  v9 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strEntryFormat, pStringMgr: v9);
  v10 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strOriginal, pStringMgr: v10);
  if ( nSize >= 0 )
  {
    v11 = (unsigned __int64)(unsigned int)nSize >> 30 != 0 ? -1 : 4 * nSize;
    v12 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)operator new(nSize: __CFADD__(v11, 4) ? -1 : v11 + 4);
    if ( v12 != nullptr )
    {
      v8 = v12 + 1;
      v12->m_pszData = (char *)nSize;
      `eh vector constructor iterator'(
        ptr: &v12[1],
        size: 4u,
        count: nSize,
        pCtor: (void (__thiscall *)(void *))ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,
        pDtor: (void (__thiscall *)(void *))ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>);
    }
    this->m_arrNames = v8;
    if ( v8 != nullptr )
    {
      this->m_nSize = nSize;
      this->m_nStart = nStart;
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strSectionName, pszSrc: lpszSection);
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strEntryFormat, pszSrc: lpszEntryFormat);
      this->m_nMaxDisplayLength = nMaxDispLen;
      return this;
    }
  }
  AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x1036CF9E
// Name: public: virtual void CRecentFileList::Add(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::Add(CRecentFileList *this, const char *lpszPathName)
{
  int v2; // edi
  char szTemp[260]; // [esp+Ch] [ebp-108h] BYREF

  v2 = 0;
  if ( lpszPathName == nullptr || lstrlenA(lpString: lpszPathName) >= 260 )
    AfxThrowFileException(cause: 3, lOsError: -1, lpszFileName: nullptr);
  AfxFullPath(lpszPathOut: szTemp, lpszFileIn: lpszPathName);
  if ( this->m_nSize - 1 > 0 )
  {
    do
    {
      if ( AfxComparePath(lpszPath1: this->m_arrNames[v2].m_pszData, lpszPath2: szTemp) != 0 )
        break;
      ++v2;
    }
    while ( v2 < this->m_nSize - 1 );
    while ( v2 > 0 )
    {
      ATL::CSimpleStringT<char,0>::operator=(this: &this->m_arrNames[v2], strSrc: &this->m_arrNames[v2 - 1]);
      --v2;
    }
  }
  ATL::CSimpleStringT<char,0>::SetString(this: this->m_arrNames, pszSrc: szTemp);
  SHAddToRecentDocs(uFlags: 2u, pv: lpszPathName);
}

//------------------------------------------------------------------------------
// Address: 0x1036D052
// Name: public: void CRecentFileList::Add(struct IShellItem __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::Add(CRecentFileList *this, IShellItem *pItem, const char *lpszAppID)
{
  const char *v3; // eax
  char *m_pszData; // edi
  int v5; // esi
  void *v6; // esp
  wchar_t v7[4]; // [esp+0h] [ebp-18h] BYREF
  SHARDAPPIDINFO info; // [esp+8h] [ebp-10h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strAppID; // [esp+10h] [ebp-8h] BYREF

  if ( afxGlobalData.bIsWindows7 != 0 && pItem != nullptr )
  {
    v3 = lpszAppID;
    if ( lpszAppID == nullptr )
      v3 = &szGroupName;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strAppID,
      pszSrc: v3);
    m_pszData = strAppID.m_pszData;
    if ( strAppID.m_pszData != nullptr && (v5 = lstrlenA(lpString: strAppID.m_pszData) + 1) <= 0x3FFFFFFF )
    {
      v6 = alloca(2 * v5);
      info.pszAppID = AtlA2WHelper(lpw: v7, lpa: m_pszData, nChars: v5, acp: 3u);
    }
    else
    {
      info.pszAppID = nullptr;
    }
    info.psi = pItem;
    SHAddToRecentDocs(uFlags: 4u, pv: &info);
    ATL::CStringData::Release(this: (ATL::CStringData *)strAppID.m_pszData - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D0F0
// Name: public: virtual void CRecentFileList::UpdateMenu(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::UpdateMenu(CRecentFileList *this, CCmdUI *pCmdUI)
{
  CMenu *m_pMenu; // ecx
  char *v4; // ebx
  int i; // ebx
  DWORD CurrentDirectoryA; // eax
  int v7; // eax
  int v8; // ebx
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v10; // eax
  bool v11; // cc
  char *m_pszData; // ebx
  _BYTE *v13; // eax
  char v14; // al
  char *v15; // ecx
  char v16; // al
  char *v17; // ecx
  int v18; // eax
  UINT_PTR m_nID; // ebx
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v20; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v21; // eax
  CMenu *v22; // eax
  unsigned int MenuItemCount; // eax
  ATL::CStringData *v24; // ecx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v25; // [esp+10h] [ebp-13Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+14h] [ebp-138h] BYREF
  int v27; // [esp+18h] [ebp-134h]
  ATL::CSimpleStringT<char,0> v28; // [esp+1Ch] [ebp-130h] BYREF
  ATL::CSimpleStringT<char,0> v29; // [esp+20h] [ebp-12Ch] BYREF
  int v30; // [esp+24h] [ebp-128h]
  UINT uPosition; // [esp+28h] [ebp-124h]
  CHAR Buffer[260]; // [esp+2Ch] [ebp-120h] BYREF
  char _Dst[24]; // [esp+130h] [ebp-1Ch] BYREF
  int v34; // [esp+148h] [ebp-4h]

  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  m_pMenu = pCmdUI->m_pMenu;
  if ( *((_DWORD *)this->m_strOriginal.m_pszData - 3) == 0 && m_pMenu != nullptr )
    CMenu::GetMenuStringA(this: m_pMenu, nIDItem: pCmdUI->m_nID, rString: &this->m_strOriginal, nFlags: 0);
  if ( *((_DWORD *)this->m_arrNames->m_pszData - 3) != 0 )
  {
    if ( pCmdUI->m_pMenu != nullptr )
    {
      for ( i = 0; i < this->m_nSize; ++i )
        DeleteMenu(hMenu: pCmdUI->m_pMenu->m_hMenu, uPosition: i + pCmdUI->m_nID, uFlags: 0);
      CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: Buffer);
      if ( CurrentDirectoryA != 0 && CurrentDirectoryA < 0x104 )
      {
        v7 = lstrlenA(lpString: Buffer);
        Buffer[v7] = 92;
        v8 = v7 + 1;
        v27 = v8;
        Buffer[v8] = 0;
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v28, pStringMgr: StringManager);
        v34 = 0;
        v10 = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v29, pStringMgr: v10);
        v30 = 0;
        v11 = this->m_nSize <= 0;
        LOBYTE(v34) = 1;
        if ( !v11 )
        {
          while ( this->GetDisplayName(
                    this,
                    a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v28,
                    a3: v30,
                    a4: Buffer,
                    a5: v8,
                    a6: 1) != 0 )
          {
            m_pszData = v28.m_pszData;
            uPosition = (UINT)ATL::CSimpleStringT<char,0>::PrepareWrite(
                                this: &v29,
                                nLength: 2 * *((_DWORD *)v28.m_pszData - 3));
            while ( *m_pszData != 0 )
            {
              if ( *m_pszData == 38 )
              {
                v13 = (_BYTE *)uPosition++;
                *v13 = 38;
              }
              if ( _ismbblead(tst: *m_pszData) != 0 )
              {
                v14 = *m_pszData;
                v15 = (char *)uPosition++;
                *v15 = v14;
                ++m_pszData;
              }
              v16 = *m_pszData;
              v17 = (char *)uPosition++;
              *v17 = v16;
              ++m_pszData;
            }
            *(_BYTE *)uPosition = 0;
            ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &v29, nNewLength: -1);
            if ( (((_BYTE)v30 + (unsigned __int8)this->m_nStart) & 0xFu) + 1 <= 0xA )
            {
              if ( (((_BYTE)v30 + (unsigned __int8)this->m_nStart) & 0xF) == 9 )
              {
                v18 = strcpy_s(_Dst, _SizeInBytes: 0xAu, _Src: "1&0 ");
                AfxCrtErrorCheck(error: v18);
              }
              else
              {
                sprintf_s(
                  string: _Dst,
                  sizeInBytes: 0xAu,
                  format: "&%d ",
                  (((_BYTE)v30 + (unsigned __int8)this->m_nStart) & 0xF) + 1);
              }
            }
            else
            {
              sprintf_s(
                string: _Dst,
                sizeInBytes: 0xAu,
                format: "%d ",
                (((_BYTE)v30 + (unsigned __int8)this->m_nStart) & 0xF) + 1);
            }
            m_nID = pCmdUI->m_nID;
            uPosition = pCmdUI->m_nIndex;
            pCmdUI->m_nIndex = uPosition + 1;
            pCmdUI->m_nID = m_nID + 1;
            v20 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                    this: &v25,
                    pszSrc: _Dst);
            LOBYTE(v34) = 2;
            v21 = ATL::operator+(
                    &result,
                    str1: v20,
                    str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v29);
            InsertMenuA(
              hMenu: pCmdUI->m_pMenu->m_hMenu,
              uPosition,
              uFlags: 0x400u,
              uIDNewItem: m_nID,
              lpNewItem: v21->m_pszData);
            ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
            LOBYTE(v34) = 1;
            ATL::CStringData::Release(this: (ATL::CStringData *)v25.m_pszData - 1);
            if ( ++v30 >= this->m_nSize )
              break;
            v8 = v27;
          }
        }
        v22 = pCmdUI->m_pMenu;
        --pCmdUI->m_nIndex;
        MenuItemCount = GetMenuItemCount(hMenu: v22->m_hMenu);
        v24 = (ATL::CStringData *)(v29.m_pszData - 16);
        pCmdUI->m_nIndexMax = MenuItemCount;
        pCmdUI->m_bEnableChanged = 1;
        ATL::CStringData::Release(this: v24);
        ATL::CStringData::Release(this: (ATL::CStringData *)v28.m_pszData - 1);
      }
    }
  }
  else
  {
    v4 = this->m_strOriginal.m_pszData;
    if ( *((_DWORD *)v4 - 3) != 0 )
      pCmdUI->SetText(this: pCmdUI, a2: v4);
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D3C8
// Name: public: virtual void CRecentFileList::Add(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentFileList::Add(CRecentFileList *this, const char *lpszPathName, char *lpszAppID)
{
  CRecentFileList *v3; // esi
  const char *v4; // eax
  CRecentFileList_vtbl *v5; // eax
  const wchar_t *v6; // eax
  int v7; // esi
  void *v8; // esp
  wchar_t v9[8]; // [esp+0h] [ebp-2Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v10; // [esp+10h] [ebp-1Ch] BYREF
  CRecentFileList *v11; // [esp+14h] [ebp-18h]
  void *ppv; // [esp+18h] [ebp-14h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  v3 = this;
  v11 = this;
  if ( afxGlobalData.bIsWindows7 != 0 )
  {
    v4 = lpszAppID;
    if ( lpszAppID == nullptr )
      v4 = &szGroupName;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &v10,
      pszSrc: v4);
    v5 = v3->__vftable;
    v13 = 0;
    v5->Add_2(this: v3, a2: lpszPathName);
    ppv = nullptr;
    LOBYTE(v13) = 1;
    if ( lpszPathName != nullptr )
    {
      v7 = lstrlenA(lpString: lpszPathName) + 1;
      if ( v7 <= 0x3FFFFFFF )
      {
        v8 = alloca(2 * v7);
        v6 = AtlA2WHelper(lpw: v9, lpa: lpszPathName, nChars: v7, acp: 3u);
      }
      else
      {
        v6 = nullptr;
      }
      v3 = v11;
    }
    else
    {
      v6 = nullptr;
    }
    if ( AFX_GLOBAL_DATA::ShellCreateItemFromParsingName(
           this: &afxGlobalData,
           pszPath: v6,
           pbc: nullptr,
           riid: &IID_IShellItem,
           &ppv) < 0 )
      AfxThrowInvalidArgException();
    CRecentFileList::Add(this: v3, pItem: (IShellItem *)ppv, lpszAppID: v10.m_pszData);
    LOBYTE(v13) = 0;
    if ( ppv != nullptr )
      (*(void (__stdcall **)(void *))(*(_DWORD *)ppv + 8))(a1: ppv);
    ATL::CStringData::Release(this: (ATL::CStringData *)v10.m_pszData - 1);
  }
  else
  {
    this->Add_2(this, a2: lpszPathName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036D4A7
// Name: public: long ATL::CRegKey::DeleteSubKey(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::DeleteSubKey(ATL::CRegKey *this, const char *lpszSubKey)
{
  ATL::CAtlTransactionManager *m_pTM; // ecx
  HMODULE ModuleHandleA; // eax

  m_pTM = this->m_pTM;
  if ( m_pTM != nullptr )
    return ATL::CAtlTransactionManager::RegDeleteKeyA(this: m_pTM, hKey: this->m_hKey, lpSubKey: lpszSubKey);
  if ( !`ATL::CRegKey::DeleteSubKey'::`9'::bInitialized )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
      `ATL::CRegKey::DeleteSubKey'::`9'::pfnRegDeleteKeyEx = (int (__stdcall *)(HKEY__ *, const char *, unsigned int, unsigned int))GetProcAddress(hModule: ModuleHandleA, lpProcName: "RegDeleteKeyExA");
    `ATL::CRegKey::DeleteSubKey'::`9'::bInitialized = true;
  }
  if ( `ATL::CRegKey::DeleteSubKey'::`9'::pfnRegDeleteKeyEx != nullptr )
    return `ATL::CRegKey::DeleteSubKey'::`9'::pfnRegDeleteKeyEx(
             a1: this->m_hKey,
             a2: lpszSubKey,
             a3: this->m_samWOW64,
             a4: 0);
  else
    return RegDeleteKeyA(hKey: this->m_hKey, lpSubKey: lpszSubKey);
}

//------------------------------------------------------------------------------
// Address: 0x1036D519
// Name: public: long ATL::CRegKey::Open(struct HKEY__ __near *,char const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::Open(
        ATL::CRegKey *this,
        HKEY__ *hKeyParent,
        const char *lpszKeyName,
        unsigned int samDesired)
{
  ATL::CAtlTransactionManager *m_pTM; // ecx
  LSTATUS result; // eax
  HKEY__ *hKey; // [esp+8h] [ebp-4h] BYREF

  hKey = nullptr;
  m_pTM = this->m_pTM;
  if ( m_pTM != nullptr )
    result = ATL::CAtlTransactionManager::RegOpenKeyExA(
               this: m_pTM,
               hKey: hKeyParent,
               lpSubKey: lpszKeyName,
               ulOptions: 0,
               samDesired,
               phkResult: &hKey);
  else
    result = RegOpenKeyExA(hKey: hKeyParent, lpSubKey: lpszKeyName, ulOptions: 0, samDesired, phkResult: &hKey);
  if ( result == 0 )
  {
    result = ATL::CRegKey::Close(this);
    this->m_hKey = hKey;
    this->m_samWOW64 = samDesired & 0x300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036D56A
// Name: public: long ATL::CRegKey::QueryStringValue(char const __near *,char __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::QueryStringValue(
        ATL::CRegKey *this,
        const char *pszValueName,
        char *pszValue,
        unsigned int *pnChars)
{
  unsigned int *v4; // esi
  unsigned int v5; // eax
  LSTATUS result; // eax
  unsigned int v7; // eax
  unsigned int nBytes; // [esp+8h] [ebp-4h] BYREF

  v4 = pnChars;
  v5 = *pnChars;
  *pnChars = 0;
  nBytes = v5;
  result = RegQueryValueExA(
             hKey: this->m_hKey,
             lpValueName: pszValueName,
             lpReserved: nullptr,
             lpType: (LPDWORD)&pnChars,
             lpData: (LPBYTE)pszValue,
             lpcbData: &nBytes);
  if ( result == 0 )
  {
    if ( pnChars != (unsigned int *)1 && pnChars != (unsigned int *)2 )
      return 13;
    v7 = nBytes;
    if ( pszValue != nullptr )
    {
      if ( nBytes != 0 )
      {
        if ( pszValue[nBytes - 1] != 0 )
          return 13;
      }
      else
      {
        *pszValue = 0;
      }
    }
    *v4 = v7;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10437450
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104374D4
// Name: _sprintf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf_s(char *string, unsigned int sizeInBytes, const char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vsprintf_s_l(string, sizeInBytes, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x104374F2
// Name: __snprintf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf_s(char *string, unsigned int sizeInBytes, unsigned int count, const char *format, ...)
{
  va_list ap; // [esp+18h] [ebp+18h] BYREF

  va_start(ap, format);
  return _vsnprintf_s_l(string, sizeInBytes, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10437520
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 10437579 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10437890
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 104378E9 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10437C00
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10437D9D
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10437DE0
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x10437E0B
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x10437E21
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x10437E30
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x1044B968);
  }
  JUMPOUT(0x10437EBF);
}

//------------------------------------------------------------------------------
// Address: 0x10437E70
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v2 = _mm_getcsr() & 0x7F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIasin_pentium4(a1);
  else
__CIasin:
    _CIasin_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x10437EAB
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10437F76
// Name: ___libm_sse2_tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_tan@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask & X.m128i_i64[0] ^ X.m128i_i64[0]) != *(double *)INF )
  {
    return tan(X: *(double *)X.m128i_i64);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104381CB
// Name: ___libm_sse2_asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_asin()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10438614
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10438B2A
// Name: FindCompleteObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__thiscall FindCompleteObject(void **inptr)
{
  int v1; // edx
  _BYTE *result; // eax
  int v3; // edx

  v1 = *((_DWORD *)*inptr - 1);
  result = (char *)inptr - *(_DWORD *)(v1 + 4);
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    result -= *(unsigned int *)((char *)inptr - v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10438B40
// Name: PMDtoOffset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall PMDtoOffset@<eax>(const PMD *pmd@<eax>, char *pThis)
{
  int pdisp; // edx
  int v3; // ecx

  pdisp = pmd->pdisp;
  v3 = 0;
  if ( pdisp >= 0 )
    v3 = *(_DWORD *)(*(_DWORD *)&pThis[pdisp] + pmd->vdisp) + pmd->pdisp;
  return v3 + pmd->mdisp;
}

//------------------------------------------------------------------------------
// Address: 0x10438B64
// Name: FindMITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindMITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassArray *pBaseClassArray; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  const _s_RTTIBaseClassDescriptor *pSourceBCD; // [esp+Ch] [ebp-14h]
  const _s_RTTIBaseClassDescriptor *pTargetBCD; // [esp+10h] [ebp-10h]
  unsigned int nTargetBases; // [esp+14h] [ebp-Ch]
  unsigned int iTarget; // [esp+18h] [ebp-8h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  pTargetBCD = nullptr;
  pSourceBCD = nullptr;
  nTargetBases = 0;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( pSourceBCD != nullptr )
        {
          if ( (v8->attributes & 3) == 0 && (pSourceBCD->attributes & 1) == 0 )
            return v8;
          return nullptr;
        }
        iTarget = i;
        pTargetBCD = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
        break;
    }
LABEL_12:
    if ( ++i >= numBaseClasses )
      return nullptr;
  }
  if ( pTargetBCD == nullptr )
  {
    pSourceBCD = v8;
    goto LABEL_12;
  }
  if ( i - iTarget > nTargetBases )
  {
    if ( (pTargetBCD->attributes & 3) == 0 )
      goto LABEL_20;
    return nullptr;
  }
  if ( (pTargetBCD->attributes & 0x40) == 0 )
  {
    if ( iTarget == 0 )
    {
LABEL_20:
      if ( (v8->attributes & 1) != 0 )
        return nullptr;
    }
    return pTargetBCD;
  }
  return (pTargetBCD->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) == 0
       ? pTargetBCD
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10438C6C
// Name: FindVITargetTypeInstance
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _s_RTTIBaseClassDescriptor *__usercall FindVITargetTypeInstance@<eax>(
        const _s_RTTICompleteObjectLocator *pCOLocator@<eax>,
        char *pCompleteObject,
        TypeDescriptor *pSrcTypeID,
        int SrcOffset,
        TypeDescriptor *pTargetTypeID)
{
  const _s_RTTIClassHierarchyDescriptor *pClassDescriptor; // eax
  unsigned int numBaseClasses; // ebx
  const _s_RTTIBaseClassDescriptor *v7; // edi
  const _s_RTTIBaseClassDescriptor *v8; // esi
  int v9; // eax
  int v10; // eax
  bool v11; // al
  int v12; // eax
  const _s_RTTIBaseClassDescriptor *result; // eax
  const _s_RTTIBaseClassArray *pBaseClassArray; // [esp+Ch] [ebp-24h]
  const _s_RTTIBaseClassDescriptor *pCrossCastTargetBCD; // [esp+10h] [ebp-20h]
  const _s_RTTIBaseClassDescriptor *pCrossCastSourceBCD; // [esp+14h] [ebp-1Ch]
  int offsetDownCastResult; // [esp+18h] [ebp-18h]
  const _s_RTTIBaseClassDescriptor *pDownCastResultBCD; // [esp+1Ch] [ebp-14h]
  unsigned int nTargetBases; // [esp+20h] [ebp-10h]
  unsigned int iTarget; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+28h] [ebp-8h]
  bool fDownCastAllowed; // [esp+2Fh] [ebp-1h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  iTarget = -1;
  offsetDownCastResult = -1;
  numBaseClasses = pClassDescriptor->numBaseClasses;
  v7 = nullptr;
  pDownCastResultBCD = nullptr;
  pCrossCastSourceBCD = nullptr;
  pCrossCastTargetBCD = nullptr;
  pBaseClassArray = pClassDescriptor->pBaseClassArray;
  nTargetBases = 0;
  fDownCastAllowed = true;
  i = 0;
  if ( numBaseClasses == 0 )
    return nullptr;
  do
  {
    v8 = pBaseClassArray->arrayOfBaseClassDescriptors[i];
    if ( i - iTarget > nTargetBases )
    {
      if ( v8->pTypeDescriptor == pTargetTypeID
        || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pTargetTypeID->name),
            v9 == 0) )
      {
        if ( (v8->attributes & 3) == 0 )
          pCrossCastTargetBCD = v8;
        iTarget = i;
        v7 = v8;
        nTargetBases = v8->numContainedBases;
      }
    }
    if ( v8->pTypeDescriptor == pSrcTypeID
      || (strcmp(str1: (unsigned __int8 *)v8->pTypeDescriptor->name, str2: (unsigned __int8 *)pSrcTypeID->name), v10 == 0) )
    {
      if ( PMDtoOffset(pmd: &v8->where, pThis: pCompleteObject) == SrcOffset )
      {
        if ( i - iTarget > nTargetBases )
        {
          if ( (v8->attributes & 5) == 0 )
            pCrossCastSourceBCD = v8;
        }
        else if ( fDownCastAllowed )
        {
          if ( (v7->attributes & 0x40) != 0 )
          {
            if ( (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = (v7->pClassDescriptor->pBaseClassArray->arrayOfBaseClassDescriptors[i - iTarget]->attributes & 4) == 0;
          }
          else
          {
            if ( iTarget == 0 && (v8->attributes & 1) != 0 )
              fDownCastAllowed = false;
            v11 = true;
          }
          if ( fDownCastAllowed && v11 )
          {
            v12 = PMDtoOffset(pmd: &v7->where, pThis: pCompleteObject);
            if ( pDownCastResultBCD != nullptr && offsetDownCastResult != v12 )
              return nullptr;
            pDownCastResultBCD = v7;
            offsetDownCastResult = v12;
          }
        }
      }
    }
    ++i;
  }
  while ( i < numBaseClasses );
  if ( !fDownCastAllowed || (result = pDownCastResultBCD, pDownCastResultBCD == nullptr) )
  {
    if ( pCrossCastSourceBCD == nullptr )
      return nullptr;
    result = pCrossCastTargetBCD;
    if ( pCrossCastTargetBCD == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10438F02
// Name: $LN35_32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _LN35_32@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10438F70
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_32(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x10438F92
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf_s(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return _LN35_32(string, inputfn: _input_s_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x10438FB4
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10439021
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10439095
// Name: __get_sys_err_msg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}

//------------------------------------------------------------------------------
// Address: 0x104390BD
// Name: _strerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  char *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( v1 == nullptr )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( v1->_errmsg == nullptr )
  {
    v4 = (char *)calloc(count: 0x86u, size: 1u);
    v2->_errmsg = v4;
    if ( v4 == nullptr )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(m: errnum);
  if ( strcpy_s(_Dst: errmsg, _SizeInBytes: 0x86u, _Src: sys_err_msg) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return errmsg;
}

//------------------------------------------------------------------------------
// Address: 0x10439127
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10439169
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1043917C
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1043918F
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x104391B2
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1043926E
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10439285
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1043930C
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104393B7
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104393CA
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: (char)*data, str: stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = _fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x10439521
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1043959B
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x104397C6
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104397F1
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1043981D
// Name: __mbsinc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _mbsinc(const unsigned __int8 *current)
{
  const unsigned __int8 *v2; // esi

  if ( current != nullptr )
  {
    v2 = current + 1;
    if ( _ismbblead(tst: *current) != 0 && *v2 != 0 )
      return (unsigned __int8 *)(current + 2);
    return (unsigned __int8 *)v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10439858
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10439919
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}
