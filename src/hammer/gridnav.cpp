// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/gridnav.cpp
// Functions: 10
// ============================================================

#include "hammer\gridnav.h"

//------------------------------------------------------------------------------
// Address: 0x1003B870
// Name: public: int CGridNav::CoordToGridPosX(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGridNav::CoordToGridPosX(CGridNav *this, unsigned int flCoordX)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm2
  __m128 v4; // xmm3
  __m128 v5; // xmm1
  __m128 v6; // xmm2

  v2 = (__m128)flCoordX;
  v2.m128_f32[0] = (float)((float)(*(float *)&flCoordX - CGridNav::sm_flOffsetX) + (float)(CGridNav::sm_flEdgeSize * 0.5))
                 / CGridNav::sm_flEdgeSize;
  v3.m128_i32[0] = 1258291200;
  v4 = _mm_and_ps((__m128)0x80000000, v2);
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v2, v4), v3).m128_f32[0]) & 0x4B000000 | v4.m128_i32[0];
  v5 = v2;
  v5.m128_f32[0] = (float)(v2.m128_f32[0] + v3.m128_f32[0]) - v3.m128_f32[0];
  v6 = v5;
  v6.m128_f32[0] = v5.m128_f32[0] - v2.m128_f32[0];
  return (int)(float)(v5.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v6, v4).m128_u32[0] & 0x3F800000));
}

//------------------------------------------------------------------------------
// Address: 0x1003B900
// Name: public: int CGridNav::CoordToGridPosY(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGridNav::CoordToGridPosY(CGridNav *this, unsigned int flCoordY)
{
  __m128 v2; // xmm0
  __m128 v3; // xmm2
  __m128 v4; // xmm3
  __m128 v5; // xmm1
  __m128 v6; // xmm2

  v2 = (__m128)flCoordY;
  v2.m128_f32[0] = (float)((float)(*(float *)&flCoordY - CGridNav::sm_flOffsetY) + (float)(CGridNav::sm_flEdgeSize * 0.5))
                 / CGridNav::sm_flEdgeSize;
  v3.m128_i32[0] = 1258291200;
  v4 = _mm_and_ps((__m128)0x80000000, v2);
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v2, v4), v3).m128_f32[0]) & 0x4B000000 | v4.m128_i32[0];
  v5 = v2;
  v5.m128_f32[0] = (float)(v2.m128_f32[0] + v3.m128_f32[0]) - v3.m128_f32[0];
  v6 = v5;
  v6.m128_f32[0] = v5.m128_f32[0] - v2.m128_f32[0];
  return (int)(float)(v5.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v6, v4).m128_u32[0] & 0x3F800000));
}

//------------------------------------------------------------------------------
// Address: 0x1003B990
// Name: public: static void CGridNav::Init(bool,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CGridNav::Init(bool bEnabled, float flEdgeSize, float flOffsetX, float flOffsetY, float flTraceHeight)
{
  CGridNav::sm_flEdgeSize = flEdgeSize;
  CGridNav::sm_flOffsetX = flOffsetX;
  CGridNav::sm_flOffsetY = flOffsetY;
  CGridNav::sm_bEnabled = bEnabled;
  CGridNav::sm_flTraceHeight = flTraceHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1003B9E0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BA80
// Name: protected: void CUtlBuffer::PutTypeBin<float>(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<float>(CUtlBuffer *this, float src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: (float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(float *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BAF0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BC00
// Name: public: void CGridNav::Render(class CRender3D __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGridNav::Render(
        CGridNav *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CRender3D *pRender,
        const Vector *vViewPos,
        const Vector *vViewDir)
{
  CRender3D *v7; // esi
  EditorRenderMode_t m_eCurrentRenderMode; // eax
  int v10; // ebx
  CGridNavCell *v11; // eax
  Color *p_pRender; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Vector p4; // [esp+0h] [ebp-48h] BYREF
  Vector p1; // [esp+Ch] [ebp-3Ch] BYREF
  Vector p3; // [esp+18h] [ebp-30h] BYREF
  Vector p2; // [esp+24h] [ebp-24h] BYREF
  EditorRenderMode_t oldRenderMode; // [esp+30h] [ebp-18h]
  Color drawColor; // [esp+34h] [ebp-14h] BYREF
  float flHalfEdgeSizeBuffered; // [esp+38h] [ebp-10h]
  Color oldDrawColor; // [esp+3Ch] [ebp-Ch] BYREF
  unsigned int v27; // [esp+40h] [ebp-8h]
  int v28; // [esp+44h] [ebp-4h] BYREF

  v7 = pRender;
  m_eCurrentRenderMode = pRender->m_eCurrentRenderMode;
  v10 = 0;
  flHalfEdgeSizeBuffered = (float)(CGridNav::sm_flEdgeSize * 0.5) * 0.94999999;
  oldRenderMode = m_eCurrentRenderMode;
  oldDrawColor = 0;
  CRender::GetDrawColor(this: pRender, color: &oldDrawColor);
  ((void (__thiscall *)(CRender3D *, int, _DWORD, int, int, int))v7->SetRenderMode)(
    a1: v7,
    a2: 4,
    a3: 0,
    a4: a3,
    a5: a4,
    a6: a2);
  if ( this->m_CurrentCells.m_Size > 0 )
  {
    v27 = 0;
    do
    {
      v11 = &this->m_CurrentCells.m_Memory.m_pMemory[v27 / 0x10];
      if ( v11->m_bTraversable )
      {
        pRender = (CRender3D *)65280;
        p_pRender = (Color *)&pRender;
      }
      else
      {
        v28 = 255;
        p_pRender = (Color *)&v28;
      }
      drawColor = *p_pRender;
      v13 = v11->m_flHeight + 5.0;
      v14 = (float)((float)v11->m_nGridPosX * CGridNav::sm_flEdgeSize) + CGridNav::sm_flOffsetX;
      v15 = (float)((float)v11->m_nGridPosY * CGridNav::sm_flEdgeSize) + CGridNav::sm_flOffsetY;
      p1.x = v14 - flHalfEdgeSizeBuffered;
      p1.y = v15 - flHalfEdgeSizeBuffered;
      p1.z = v13;
      p2.x = v14 + flHalfEdgeSizeBuffered;
      p2.y = v15 - flHalfEdgeSizeBuffered;
      p2.z = v13;
      p3.x = v14 + flHalfEdgeSizeBuffered;
      p3.y = v15 + flHalfEdgeSizeBuffered;
      p3.z = v13;
      p4.x = v14 - flHalfEdgeSizeBuffered;
      p4.y = v15 + flHalfEdgeSizeBuffered;
      p4.z = v13;
      CRender::SetDrawColor(this: v7, color: &drawColor);
      CRender::DrawLine(this: v7, vStart: &p1, vEnd: &p2);
      CRender::DrawLine(this: v7, vStart: &p2, vEnd: &p3);
      CRender::DrawLine(this: v7, vStart: &p3, vEnd: &p4);
      CRender::DrawLine(this: v7, vStart: &p4, vEnd: &p1);
      v27 += 16;
      ++v10;
    }
    while ( v10 < this->m_CurrentCells.m_Size );
  }
  ((void (__thiscall *)(CRender3D *, EditorRenderMode_t, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, EditorRenderMode_t, Color, _DWORD))v7->SetRenderMode)(
    a1: v7,
    a2: oldRenderMode,
    a3: 0,
    a4: LODWORD(p4.x),
    a5: LODWORD(p4.y),
    a6: LODWORD(p4.z),
    a7: LODWORD(p1.x),
    a8: LODWORD(p1.y),
    a9: LODWORD(p1.z),
    a10: LODWORD(p3.x),
    a11: LODWORD(p3.y),
    a12: LODWORD(p3.z),
    a13: LODWORD(p2.x),
    a14: LODWORD(p2.y),
    a15: LODWORD(p2.z),
    a16: oldRenderMode,
    a17: drawColor,
    a18: LODWORD(flHalfEdgeSizeBuffered));
  CRender::SetDrawColor(this: v7, color: &oldDrawColor);
}

//------------------------------------------------------------------------------
// Address: 0x1003BE20
// Name: public: CGridNav::CGridNav(void)
// Source: json
//------------------------------------------------------------------------------
CGridNav *__thiscall CGridNav::CGridNav(CGridNav *this)
{
  CGridNavCell *m_pMemory; // esi

  this->m_vLatestCameraPos.x = 0.0;
  this->m_vLatestCameraPos.y = 0.0;
  this->m_vLatestCameraPos.z = 0.0;
  this->m_vLatestCameraDir.x = 0.0;
  this->m_vLatestCameraDir.y = 0.0;
  this->m_vLatestCameraDir.z = 0.0;
  this->m_bNeedsCameraRecompute = true;
  this->m_flTimeCameraLastMoved = 0.0;
  this->m_nTicksCameraStill = 0;
  this->m_CurrentCells.m_Memory.m_pMemory = nullptr;
  this->m_CurrentCells.m_Memory.m_nAllocationCount = 0;
  this->m_CurrentCells.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_CurrentCells.m_Memory.m_pMemory;
  this->m_CurrentCells.m_Size = 0;
  this->m_CurrentCells.m_pElements = m_pMemory;
  this->m_bPreviewActive = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003BEB0
// Name: public: void CGridNav::Update(class CMapDoc __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CGridNav::Update(CGridNav *this, CMapDoc *pMapDoc, const Vector *vViewPos, const Vector *vViewDir)
{
  const Vector *v5; // ebx
  char v6; // al
  int v7; // edi
  int v8; // eax
  float y; // xmm0_4
  int v10; // xmm1_4
  char v11; // bl
  int v12; // esi
  Vector *p_vPosition; // edi
  bool v14; // al
  float z; // xmm1_4
  bool v16; // zf
  int v17; // [esp-4h] [ebp-CCh]
  Vector flCoordX; // [esp+10h] [ebp-B8h] BYREF
  Vector pHitPosition; // [esp+1Ch] [ebp-ACh] BYREF
  Vector vPosition; // [esp+28h] [ebp-A0h] BYREF
  float v21; // [esp+34h] [ebp-94h]
  Vector cornerTracePoints[4]; // [esp+38h] [ebp-90h] BYREF
  Vector vTraceHitPos; // [esp+68h] [ebp-60h]
  CGridNavCell newCell; // [esp+74h] [ebp-54h]
  Vector vViewToCenter; // [esp+84h] [ebp-44h]
  float flHalfEdgeSize; // [esp+90h] [ebp-38h]
  __int64 flCenterToCornerLen; // [esp+94h] [ebp-34h] OVERLAPPED BYREF
  int m_nGridPosY; // [esp+9Ch] [ebp-2Ch]
  CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int> > *y_low; // [esp+A0h] [ebp-28h]
  Vector vViewToCenterDir; // [esp+A4h] [ebp-24h] BYREF
  float centerHeight; // [esp+B0h] [ebp-18h]
  Vector vTracePos; // [esp+B4h] [ebp-14h]
  float maxHeight; // [esp+C0h] [ebp-8h]
  bool pHitClip[4]; // [esp+C4h] [ebp-4h] BYREF

  if ( this->m_vLatestCameraPos.x == vViewPos->x
    && this->m_vLatestCameraPos.y == vViewPos->y
    && this->m_vLatestCameraPos.z == vViewPos->z )
  {
    v5 = vViewDir;
    if ( this->m_vLatestCameraDir.x == vViewDir->x
      && this->m_vLatestCameraDir.y == vViewDir->y
      && this->m_vLatestCameraDir.z == vViewDir->z )
    {
      v6 = 0;
      goto LABEL_10;
    }
  }
  else
  {
    v5 = vViewDir;
  }
  v6 = 1;
LABEL_10:
  this->m_vLatestCameraPos = *vViewPos;
  this->m_vLatestCameraDir = *v5;
  if ( v6 != 0 )
  {
    this->m_bNeedsCameraRecompute = true;
    this->m_flTimeCameraLastMoved = pMapDoc->m_flCurrentTime;
    this->m_nTicksCameraStill = 0;
  }
  else if ( this->m_bNeedsCameraRecompute )
  {
    ++this->m_nTicksCameraStill;
    if ( (float)(pMapDoc->m_flCurrentTime - this->m_flTimeCameraLastMoved) >= 0.2 && this->m_nTicksCameraStill >= 10 )
    {
      this->m_bNeedsCameraRecompute = false;
      if ( CMapDoc::PickTrace(this: pMapDoc, vPosition: vViewPos, vDirection: v5, &pHitPosition) != 0 )
      {
        this->m_CurrentCells.m_Size = 0;
        newCell.m_flHeight = CGridNav::sm_flEdgeSize * 0.5;
        LODWORD(flHalfEdgeSize) = &this->m_CurrentCells;
        vViewToCenter.x = (float)sqrt(2.0) * (float)(CGridNav::sm_flEdgeSize * 0.5);
        v7 = CGridNav::CoordToGridPosX(this, flCoordX: LODWORD(pHitPosition.x));
        v8 = CGridNav::CoordToGridPosY(this, flCoordY: LODWORD(pHitPosition.y)) - 15;
        LODWORD(vViewToCenter.z) = v7 - 15;
        LODWORD(vTracePos.z) = v8;
        LODWORD(vTracePos.x) = 31;
        do
        {
          y = (float)((float)v8 * CGridNav::sm_flEdgeSize) + CGridNav::sm_flOffsetY;
          vViewToCenter.y = y;
          maxHeight = vViewToCenter.z;
          LODWORD(vTracePos.y) = 31;
          while ( 1 )
          {
            vViewToCenterDir.y = y;
            vViewToCenterDir.x = (float)((float)SLODWORD(maxHeight) * CGridNav::sm_flEdgeSize) + CGridNav::sm_flOffsetX;
            vViewToCenterDir.z = CGridNav::sm_flTraceHeight;
            pHitClip[3] = false;
            if ( CMapDoc::DropTraceOnDisplacementsAndClips(
                   this: pMapDoc,
                   vPosition: &vViewToCenterDir,
                   pHitPosition: (Vector *)&cornerTracePoints[2].z,
                   pHitClip: &pHitClip[3]) )
            {
              *(float *)&newCell.m_bTraversable = cornerTracePoints[2].z - vViewPos->x;
              *(float *)&v10 = cornerTracePoints[3].x - vViewPos->y;
              y_low = (CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int> > *)LODWORD(cornerTracePoints[3].y);
              centerHeight = cornerTracePoints[3].y;
              *(float *)&newCell.m_nGridPosY = cornerTracePoints[3].y - vViewPos->z;
              newCell.m_nGridPosX = v10;
              flCenterToCornerLen = *(_QWORD *)&newCell.m_bTraversable;
              m_nGridPosY = newCell.m_nGridPosY;
              VectorNormalize(vec: (Vector *)&flCenterToCornerLen);
              if ( (float)((float)((float)(v5->x * *(float *)&flCenterToCornerLen)
                                 + (float)(v5->y * *((float *)&flCenterToCornerLen + 1)))
                         + (float)(v5->z * *(float *)&m_nGridPosY)) >= 0.80000001 )
              {
                vPosition.x = vViewToCenterDir.x - newCell.m_flHeight;
                vPosition.y = vViewToCenterDir.y + newCell.m_flHeight;
                vPosition.z = vViewToCenterDir.z;
                v21 = vViewToCenterDir.x - newCell.m_flHeight;
                cornerTracePoints[0].x = vViewToCenterDir.y - newCell.m_flHeight;
                cornerTracePoints[0].y = vViewToCenterDir.z;
                cornerTracePoints[0].z = vViewToCenterDir.x + newCell.m_flHeight;
                cornerTracePoints[1].x = vViewToCenterDir.y + newCell.m_flHeight;
                cornerTracePoints[1].y = vViewToCenterDir.z;
                cornerTracePoints[1].z = vViewToCenterDir.x + newCell.m_flHeight;
                cornerTracePoints[2].x = vViewToCenterDir.y - newCell.m_flHeight;
                cornerTracePoints[2].y = vViewToCenterDir.z;
                v11 = 1;
                v12 = 0;
                p_vPosition = &vPosition;
                while ( CMapDoc::DropTraceOnDisplacementsAndClips(
                          this: pMapDoc,
                          vPosition: p_vPosition,
                          pHitPosition: &flCoordX,
                          pHitClip: &pHitClip[2]) )
                {
                  v14 = pHitClip[3] || pHitClip[2];
                  z = centerHeight;
                  pHitClip[3] = v14;
                  if ( flCoordX.z > centerHeight )
                  {
                    z = flCoordX.z;
                    centerHeight = flCoordX.z;
                  }
                  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(flCoordX.z - *(float *)&y_low) & _mask__AbsFloat_) > vViewToCenter.x )
                    v11 = 0;
                  ++v12;
                  ++p_vPosition;
                  if ( v12 >= 4 )
                  {
                    vTraceHitPos.x = maxHeight;
                    vTraceHitPos.y = vTracePos.z;
                    if ( v14 || (LOBYTE(cornerTracePoints[3].z) = 1, v11 == 0) )
                      LOBYTE(cornerTracePoints[3].z) = 0;
                    v17 = *(_DWORD *)(LODWORD(flHalfEdgeSize) + 12);
                    vTraceHitPos.z = z;
                    CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int>>::InsertBefore(
                      this: (CUtlVector<CGridNavCell,CUtlMemory<CGridNavCell,int> > *)LODWORD(flHalfEdgeSize),
                      elem: v17,
                      src: (const CGridNavCell *)&cornerTracePoints[3].z);
                    break;
                  }
                }
                v5 = vViewDir;
              }
            }
            ++LODWORD(maxHeight);
            if ( --LODWORD(vTracePos.y) == 0 )
              break;
            y = vViewToCenter.y;
          }
          v8 = LODWORD(vTracePos.z) + 1;
          v16 = LODWORD(vTracePos.x)-- == 1;
          ++LODWORD(vTracePos.z);
        }
        while ( !v16 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C2A0
// Name: public: void CGridNav::GenerateGridNavFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CGridNav::GenerateGridNavFile(CGridNav *this@<ecx>, int a2@<ebx>, const char *pFileFullPath)
{
  int v3; // edi
  CProgressDlg *v4; // eax
  CProgressDlg *v5; // esi
  float v6; // xmm1_4
  int v7; // esi
  bool (__thiscall *m_nTab)(CUtlBuffer *, int); // xmm0_4
  float v9; // xmm1_4
  __m128 v10; // xmm2
  bool v11; // cc
  float v12; // xmm0_4
  __m128 v13; // xmm1
  float v14; // xmm0_4
  _DWORD *v15; // edx
  __m128 v16; // xmm3
  float v17; // xmm1_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  int v20; // edi
  int v21; // esi
  float v22; // xmm1_4
  CMapDoc *v23; // edi
  int v24; // esi
  bool (__thiscall *m_GetOverflowFunc)(CUtlBuffer *, int); // eax
  char v26; // bl
  int v27; // esi
  float v28; // xmm0_4
  unsigned __int8 m_nOffset_high; // al
  bool v30; // al
  float z; // esi
  Vector v33; // [esp+14h] [ebp-F4h] BYREF
  float v34; // [esp+20h] [ebp-E8h]
  float v35; // [esp+24h] [ebp-E4h]
  int v36; // [esp+28h] [ebp-E0h]
  Vector cornerTracePoints[4]; // [esp+2Ch] [ebp-DCh] BYREF
  Vector vTraceHitPos; // [esp+5Ch] [ebp-ACh] BYREF
  float v39; // [esp+68h] [ebp-A0h]
  int v40; // [esp+6Ch] [ebp-9Ch]
  float flHalfEdgeSize; // [esp+70h] [ebp-98h]
  int nGridMaxX; // [esp+74h] [ebp-94h]
  int nGridMaxY; // [esp+78h] [ebp-90h]
  float flCenterY; // [esp+7Ch] [ebp-8Ch] BYREF
  float flCenterToCornerLen; // [esp+80h] [ebp-88h]
  int nMaxProgressVal; // [esp+84h] [ebp-84h]
  float prevHeights[2]; // [esp+88h] [ebp-80h] BYREF
  float centerHeight; // [esp+90h] [ebp-78h]
  Vector vPosition; // [esp+94h] [ebp-74h]
  Vector vCornerTraceHitPos; // [esp+A0h] [ebp-68h] BYREF
  int v51; // [esp+ACh] [ebp-5Ch]
  int nGridHeight; // [esp+B0h] [ebp-58h]
  CProgressDlg *v53; // [esp+B4h] [ebp-54h]
  int nGridMinX; // [esp+B8h] [ebp-50h] BYREF
  int inputBuffer; // [esp+BCh] [ebp-4Ch]
  int nGridMinY; // [esp+C0h] [ebp-48h]
  int i; // [esp+C8h] [ebp-40h]
  int j; // [esp+CCh] [ebp-3Ch]
  CUtlBuffer fileBuffer; // [esp+D0h] [ebp-38h] BYREF
  float flSign; // [esp+104h] [ebp-4h]

  v3 = 0;
  nGridHeight = (int)CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileFullPath, a3: nullptr)
      && !g_pFullFileSystem->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileFullPath, a3: nullptr) )
    {
      AfxMessageBox(
        lpszText: "Grid nav file already exists and is not writable. Unable to generate grid nav.",
        nType: 0,
        nIDHelp: 0);
      return;
    }
    v4 = (CProgressDlg *)operator new(nSize: 0x120u);
    LODWORD(vPosition.y) = v4;
    flSign = 0.0;
    if ( v4 != nullptr )
    {
      v5 = CProgressDlg::CProgressDlg(this: v4, nCaptionID: 0);
      LODWORD(vPosition.z) = v5;
    }
    else
    {
      v5 = nullptr;
      vPosition.z = 0.0;
    }
    flSign = NAN;
    CProgressDlg::Create(this: v5, pParent: nullptr);
    CProgressDlg::SetStep(this: v5, nStep: 1);
    CWnd::SetWindowTextA(this: v5, lpszString: "Constructing Navigation Grid...");
    CProgressDlg::SetRange(this: v5, nLower: 0, nUpper: 100);
    LODWORD(cornerTracePoints[2].x) = &vTraceHitPos.y;
    LODWORD(cornerTracePoints[2].y) = &vTraceHitPos;
    LODWORD(cornerTracePoints[2].z) = &vCornerTraceHitPos.z;
    LODWORD(cornerTracePoints[3].x) = &vCornerTraceHitPos;
    do
    {
      v6 = 50000.0;
      v7 = (v3 + 1) % 2;
      if ( v3 > 1 )
        fileBuffer.m_nMaxPut = -1082130432;
      else
        fileBuffer.m_nMaxPut = 1065353216;
      *(float *)&v53 = 50000.0;
      fileBuffer.m_nTab = 1195593728;
      fileBuffer.m_GetOverflowFunc = nullptr;
      *((_DWORD *)&vPosition.x + 1 - v7) = 0;
      do
      {
        *(&vPosition.x + v7) = v6 * *(float *)&fileBuffer.m_nMaxPut;
        *(_QWORD *)prevHeights = *(_QWORD *)&vPosition.x;
        centerHeight = CGridNav::sm_flTraceHeight;
        *(float *)&v51 = -1.0;
        if ( CMapDoc::DropTraceOnDisplacementsAndClips(
               this: (CMapDoc *)nGridHeight,
               vPosition: (const Vector *)prevHeights,
               pHitPosition: nullptr,
               pHitClip: nullptr) )
        {
          m_nTab = (bool (__thiscall *)(CUtlBuffer *, int))fileBuffer.m_nTab;
          v9 = 1.0;
          fileBuffer.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))fileBuffer.m_nTab;
        }
        else
        {
          m_nTab = fileBuffer.m_GetOverflowFunc;
          v9 = *(float *)&v51;
        }
        v10 = (__m128)0x3F000000u;
        v11 = (float)(*(float *)&v53 * 0.5) <= 1.0;
        v6 = (float)(v9 * (float)(*(float *)&v53 * 0.5)) + *(float *)&fileBuffer.m_nTab;
        *(float *)&v53 = *(float *)&v53 * 0.5;
        *(float *)&fileBuffer.m_nTab = v6;
      }
      while ( !v11 );
      v12 = *(float *)&m_nTab * *(float *)&fileBuffer.m_nMaxPut;
      v13.m128_i32[0] = 1258291200;
      if ( v7 != 0 )
        v14 = v12 - CGridNav::sm_flOffsetY;
      else
        v14 = v12 - CGridNav::sm_flOffsetX;
      v15 = *((_DWORD **)&cornerTracePoints[2].x + v3);
      v10.m128_f32[0] = (float)((float)(0.5 * CGridNav::sm_flEdgeSize) + v14) / CGridNav::sm_flEdgeSize;
      v16 = _mm_and_ps((__m128)0x80000000, v10);
      LODWORD(v17) = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v16), v13).m128_f32[0]) & 0x4B000000
                   | v16.m128_i32[0];
      v18 = v10;
      v18.m128_f32[0] = (float)(v10.m128_f32[0] + v17) - v17;
      v19 = v18;
      v19.m128_f32[0] = v18.m128_f32[0] - v10.m128_f32[0];
      ++v3;
      *v15 = (int)(float)(v18.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v19, v16).m128_u32[0] & 0x3F800000));
    }
    while ( v3 < 4 );
    v20 = LODWORD(vTraceHitPos.x) - LODWORD(vCornerTraceHitPos.x) + 1;
    v21 = LODWORD(vTraceHitPos.y) - LODWORD(vCornerTraceHitPos.z) + 1;
    v51 = v20;
    LODWORD(vPosition.y) = v21;
    HIBYTE(fileBuffer.m_PutOverflowFunc) = 0;
    fileBuffer.m_nMaxPut = 0;
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&nGridMinX, growSize: 1024, initSize: 1024, nFlags: 0);
    LODWORD(flSign) = 1;
    if ( (j & 0x100) != 0 )
    {
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%d", -86065491);
    }
    else
    {
      vCornerTraceHitPos.y = -5.7827863e35;
      if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 4) )
      {
        if ( (fileBuffer.m_Error & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<int>(
            this: (CByteswap *)&fileBuffer.m_Error,
            outputBuffer: (int *)(nGridMinX + i - fileBuffer.m_Memory.m_nGrowSize),
            inputBuffer: (int *)&vCornerTraceHitPos.y,
            count: 1);
        else
          *(_DWORD *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = -86065491;
        i += 4;
        CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: i);
      }
    }
    if ( (j & 0x100) != 0 )
    {
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%f", CGridNav::sm_flEdgeSize);
    }
    else
    {
      *(float *)&fileBuffer.m_GetOverflowFunc = CGridNav::sm_flEdgeSize;
      if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 4) )
      {
        if ( (fileBuffer.m_Error & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: (CByteswap *)&fileBuffer.m_Error,
            outputBuffer: (float *)(nGridMinX + i - fileBuffer.m_Memory.m_nGrowSize),
            inputBuffer: (float *)&fileBuffer.m_GetOverflowFunc,
            count: 1);
        else
          *(_DWORD *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = fileBuffer.m_GetOverflowFunc;
        i += 4;
        CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: i);
      }
    }
    if ( (j & 0x100) != 0 )
    {
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%f", CGridNav::sm_flOffsetX);
    }
    else
    {
      *(float *)&fileBuffer.m_GetOverflowFunc = CGridNav::sm_flOffsetX;
      if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 4) )
      {
        if ( (fileBuffer.m_Error & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: (CByteswap *)&fileBuffer.m_Error,
            outputBuffer: (float *)(nGridMinX + i - fileBuffer.m_Memory.m_nGrowSize),
            inputBuffer: (float *)&fileBuffer.m_GetOverflowFunc,
            count: 1);
        else
          *(_DWORD *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = fileBuffer.m_GetOverflowFunc;
        i += 4;
        CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: i);
      }
    }
    if ( (j & 0x100) != 0 )
    {
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%f", CGridNav::sm_flOffsetY);
    }
    else
    {
      *(float *)&fileBuffer.m_GetOverflowFunc = CGridNav::sm_flOffsetY;
      if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 4) )
      {
        if ( (fileBuffer.m_Error & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: (CByteswap *)&fileBuffer.m_Error,
            outputBuffer: (float *)(nGridMinX + i - fileBuffer.m_Memory.m_nGrowSize),
            inputBuffer: (float *)&fileBuffer.m_GetOverflowFunc,
            count: 1);
        else
          *(_DWORD *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = fileBuffer.m_GetOverflowFunc;
        i += 4;
        CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: i);
      }
    }
    if ( (j & 0x100) != 0 )
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%d", v20);
    else
      CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&nGridMinX, src: v20);
    if ( (j & 0x100) != 0 )
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%d", v21);
    else
      CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&nGridMinX, src: v21);
    if ( (j & 0x100) != 0 )
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%d", vCornerTraceHitPos.x);
    else
      CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&nGridMinX, src: SLODWORD(vCornerTraceHitPos.x));
    if ( (j & 0x100) != 0 )
      CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%d", vCornerTraceHitPos.z);
    else
      CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&nGridMinX, src: SLODWORD(vCornerTraceHitPos.z));
    v22 = sqrt(2.0);
    v40 = v20 * v21 - 1;
    cornerTracePoints[3].z = CGridNav::sm_flEdgeSize * 0.5;
    v39 = v22 * (float)(CGridNav::sm_flEdgeSize * 0.5);
    *(float *)&v53 = 0.0;
    if ( v21 > 0 )
    {
      LODWORD(cornerTracePoints[3].y) = 100 * v20;
      v23 = (CMapDoc *)nGridHeight;
      fileBuffer.m_GetOverflowFunc = nullptr;
      while ( 1 )
      {
        v24 = 0;
        vTraceHitPos.z = (float)((float)((int)v53 + LODWORD(vCornerTraceHitPos.z)) * CGridNav::sm_flEdgeSize)
                       + CGridNav::sm_flOffsetY;
        flHalfEdgeSize = 0.0;
        nGridMaxX = 0;
        LOWORD(fileBuffer.m_nTab) = 0;
        BYTE1(fileBuffer.m_PutOverflowFunc) = 0;
        nGridHeight = 0;
        if ( v51 > 0 )
          break;
LABEL_99:
        fileBuffer.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))((char *)fileBuffer.m_GetOverflowFunc
                                                                              + LODWORD(cornerTracePoints[3].y));
        v53 = (CProgressDlg *)((char *)v53 + 1);
        if ( (int)v53 >= SLODWORD(vPosition.y) )
        {
          if ( fileBuffer.m_nMaxPut != 0 )
          {
            if ( (j & 0x100) != 0 )
            {
              CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%hu", HIBYTE(fileBuffer.m_PutOverflowFunc));
            }
            else if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 1) )
            {
              *(_BYTE *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = HIBYTE(fileBuffer.m_PutOverflowFunc);
              CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: ++i);
            }
          }
          goto LABEL_105;
        }
      }
      m_GetOverflowFunc = fileBuffer.m_GetOverflowFunc;
      LODWORD(vCornerTraceHitPos.y) = fileBuffer.m_GetOverflowFunc;
      while ( 1 )
      {
        CProgressDlg::SetPos(this: (CProgressDlg *)LODWORD(vPosition.z), nPos: (int)m_GetOverflowFunc / v40);
        flCenterY = (float)((float)(v24 + LODWORD(vCornerTraceHitPos.x)) * CGridNav::sm_flEdgeSize)
                  + CGridNav::sm_flOffsetX;
        flCenterToCornerLen = vTraceHitPos.z;
        BYTE2(fileBuffer.m_nOffset) = 1;
        v26 = 1;
        nMaxProgressVal = LODWORD(CGridNav::sm_flTraceHeight);
        BYTE2(fileBuffer.m_PutOverflowFunc) = 0;
        if ( CMapDoc::DropTraceOnDisplacementsAndClips(
               this: v23,
               vPosition: (const Vector *)&flCenterY,
               pHitPosition: (Vector *)&cornerTracePoints[2].y,
               pHitClip: (bool *)&fileBuffer.m_PutOverflowFunc + 2) )
        {
          break;
        }
LABEL_83:
        v26 = 0;
LABEL_84:
        v30 = BYTE2(fileBuffer.m_PutOverflowFunc) == 0 && BYTE2(fileBuffer.m_nOffset) != 0;
        if ( v26 != 0 )
        {
          if ( v30 )
            HIBYTE(fileBuffer.m_PutOverflowFunc) |= 1 << SLOBYTE(fileBuffer.m_nMaxPut);
        }
        else
        {
          BYTE1(fileBuffer.m_PutOverflowFunc) = 0;
        }
        if ( ++fileBuffer.m_nMaxPut >= 8 )
        {
          if ( (j & 0x100) != 0 )
          {
            CUtlBuffer::Printf(this: (CUtlBuffer *)&nGridMinX, pFmt: "%hu", HIBYTE(fileBuffer.m_PutOverflowFunc));
          }
          else if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&nGridMinX, nSize: 1) )
          {
            *(_BYTE *)(i - fileBuffer.m_Memory.m_nGrowSize + nGridMinX) = HIBYTE(fileBuffer.m_PutOverflowFunc);
            CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&nGridMinX, nPut: ++i);
          }
          HIBYTE(fileBuffer.m_PutOverflowFunc) = 0;
          fileBuffer.m_nMaxPut = 0;
        }
        v24 = nGridHeight + 1;
        m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))(LODWORD(vCornerTraceHitPos.y) + 100);
        nGridHeight = v24;
        LODWORD(vCornerTraceHitPos.y) += 100;
        if ( v24 >= v51 )
          goto LABEL_99;
      }
      nGridMaxY = SLODWORD(cornerTracePoints[3].x);
      v33.x = flCenterY - cornerTracePoints[3].z;
      v34 = flCenterY - cornerTracePoints[3].z;
      v33.y = flCenterToCornerLen + cornerTracePoints[3].z;
      LODWORD(v33.z) = nMaxProgressVal;
      v35 = flCenterToCornerLen - cornerTracePoints[3].z;
      v36 = nMaxProgressVal;
      cornerTracePoints[0].x = flCenterY + cornerTracePoints[3].z;
      cornerTracePoints[0].y = flCenterToCornerLen + cornerTracePoints[3].z;
      LODWORD(cornerTracePoints[0].z) = nMaxProgressVal;
      cornerTracePoints[1].x = flCenterY + cornerTracePoints[3].z;
      cornerTracePoints[1].y = flCenterToCornerLen - cornerTracePoints[3].z;
      LODWORD(cornerTracePoints[1].z) = nMaxProgressVal;
      v27 = 0;
      while ( v27 != 2 )
      {
        if ( v27 > 1 || BYTE1(fileBuffer.m_PutOverflowFunc) == 0 )
          goto LABEL_69;
        prevHeights[0] = *(&v33.x + 3 * v27);
        m_nOffset_high = *((_BYTE *)&fileBuffer.m_nTab + v27);
        prevHeights[1] = *(&v33.y + 3 * v27);
        v28 = *(&flHalfEdgeSize + v27);
        centerHeight = v28;
        HIBYTE(fileBuffer.m_nOffset) = m_nOffset_high;
LABEL_71:
        if ( v27 >= 2 )
        {
          *(&v39 + v27) = v28;
          *(&fileBuffer.m_Reserved + v27) = m_nOffset_high;
        }
        if ( BYTE2(fileBuffer.m_PutOverflowFunc) != 0 || (BYTE2(fileBuffer.m_PutOverflowFunc) = 0, m_nOffset_high != 0) )
          BYTE2(fileBuffer.m_PutOverflowFunc) = 1;
        if ( fabs(v28 - *(float *)&nGridMaxY) > v39 )
          BYTE2(fileBuffer.m_nOffset) = 0;
        if ( ++v27 >= 4 )
          goto LABEL_84;
      }
      BYTE1(fileBuffer.m_PutOverflowFunc) = 1;
LABEL_69:
      if ( !CMapDoc::DropTraceOnDisplacementsAndClips(
              this: v23,
              vPosition: &v33 + v27,
              pHitPosition: (Vector *)prevHeights,
              pHitClip: (bool *)&fileBuffer.m_nOffset + 3) )
        goto LABEL_83;
      v28 = centerHeight;
      m_nOffset_high = HIBYTE(fileBuffer.m_nOffset);
      goto LABEL_71;
    }
LABEL_105:
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, _DWORD, int *, int))g_pFullFileSystem->WriteFile)(
           a1: &g_pFullFileSystem->IBaseFileSystem,
           a2: pFileFullPath,
           a3: 0,
           a4: &nGridMinX,
           a5: a2) == 0 )
      _Warning(a1: "Unable to save %d bytes to %s\n", inputBuffer, pFileFullPath);
    z = vPosition.z;
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vPosition.z) + 96))(a1: LODWORD(vPosition.z));
    (*(void (__thiscall **)(float, int))(*(_DWORD *)LODWORD(z) + 4))(a1: COERCE_FLOAT(LODWORD(z)), a2: 1);
    flSign = NAN;
    if ( nGridMinY >= 0 && nGridMinX != 0 )
      free(pMem: (void *)nGridMinX);
  }
}
