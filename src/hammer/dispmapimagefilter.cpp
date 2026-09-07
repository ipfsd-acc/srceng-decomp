// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispmapimagefilter.cpp
// Functions: 48
// ============================================================

#include "hammer\dispmapimagefilter.h"

//------------------------------------------------------------------------------
// Address: 0x1001E640
// Name: public: void CMapDisp::GetSubdivNormal(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::GetSubdivNormal(CMapDisp *this, int ndx, Vector *v)
{
  *v = this->m_CoreDispInfo.m_pVerts[ndx].m_SubdivNormal;
}

//------------------------------------------------------------------------------
// Address: 0x1001E670
// Name: private: static enum ChunkFileResult_t CDispMapImageFilter::LoadImageKeyCallback(char const __near *,char const __near *,class CDispMapImageFilter __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDispMapImageFilter::LoadImageKeyCallback(
        const char *szKey,
        const char *szValue,
        CDispMapImageFilter *pFilter)
{
  float *v3; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( bInitMemory )
  {
    v3 = (float *)operator new[](nSize: 4 * (pFilter->m_Height * pFilter->m_Width + 1));
    pFilter->m_pImage = v3;
    if ( v3 == nullptr )
      return 1;
    bInitMemory = false;
  }
  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) == 0 )
  {
    strcpy(szBuf, szValue);
    v5 = atoi(nptr: szKey + 3);
    v6 = strtok(string: szBuf, control: " ");
    if ( v6 != nullptr )
    {
      v7 = v5 * pFilter->m_Height;
      do
      {
        pFilter->m_pImage[v7] = atof(nptr: v6);
        v6 = strtok(string: nullptr, control: " ");
        ++v7;
      }
      while ( v6 != nullptr );
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E750
// Name: public: CDispMapImageFilterManager::CDispMapImageFilterManager(void)
// Source: json
//------------------------------------------------------------------------------
CDispMapImageFilterManager *__thiscall CDispMapImageFilterManager::CDispMapImageFilterManager(
        CDispMapImageFilterManager *this)
{
  this->m_FilterCount = 0;
  this->m_ActiveFilter = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001E760
// Name: public: void CDispMapImageFilterManager::Add(class CDispMapImageFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::Add(CDispMapImageFilterManager *this, CDispMapImageFilter *pFilter)
{
  int m_FilterCount; // eax

  m_FilterCount = this->m_FilterCount;
  if ( m_FilterCount < 64 )
  {
    this->m_pFilterList[m_FilterCount] = pFilter;
    ++this->m_FilterCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E780
// Name: private: void CDispMapImageFilterManager::GetImageValue(class CMapDisp __near *,class CDispMapImageFilter __near *,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::GetImageValue(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        CDispMapImageFilter *pFilter,
        int ndxDisp,
        Vector *vPaintValue)
{
  int m_DataType; // eax

  m_DataType = pFilter->m_DataType;
  if ( m_DataType != 0 )
  {
    if ( m_DataType == 1 )
    {
      vPaintValue->x = pDisp->m_CoreDispInfo.m_pVerts[ndxDisp].m_Alpha;
      vPaintValue->y = 0.0;
      vPaintValue->z = 0.0;
    }
  }
  else
  {
    *vPaintValue = pDisp->m_CoreDispInfo.m_pVerts[ndxDisp].m_Vert;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E7F0
// Name: private: void CDispMapImageFilterManager::GetImageFlatSubdivValue(class CMapDisp __near *,class CDispMapImageFilter __near *,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::GetImageFlatSubdivValue(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        CDispMapImageFilter *pFilter,
        int ndxDisp,
        Vector *vPaintValue)
{
  int m_DataType; // eax
  CoreDispVert_t *v6; // ecx
  float x; // xmm3_4
  float y; // xmm0_4
  float z; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4

  m_DataType = pFilter->m_DataType;
  if ( m_DataType != 0 )
  {
    if ( m_DataType == 1 )
    {
      vPaintValue->x = 0.0;
      vPaintValue->y = 0.0;
      vPaintValue->z = 0.0;
    }
  }
  else
  {
    v6 = &pDisp->m_CoreDispInfo.m_pVerts[ndxDisp];
    vPaintValue->x = v6->m_FlatVert.x;
    x = vPaintValue->x;
    vPaintValue->y = v6->m_FlatVert.y;
    y = vPaintValue->y;
    vPaintValue->z = v6->m_FlatVert.z;
    z = v6->m_SubdivPos.z;
    v10 = x + v6->m_SubdivPos.x;
    vPaintValue->y = y + v6->m_SubdivPos.y;
    v11 = vPaintValue->z + z;
    vPaintValue->x = v10;
    vPaintValue->z = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E880
// Name: private: void CDispMapImageFilterManager::GetImageFieldData(class CMapDisp __near *,class CDispMapImageFilter __near *,int,class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::GetImageFieldData(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        CDispMapImageFilter *pFilter,
        int ndxDisp,
        Vector *vNormal,
        float *dist)
{
  int m_DataType; // eax
  CoreDispVert_t *v7; // eax

  m_DataType = pFilter->m_DataType;
  if ( m_DataType != 0 )
  {
    if ( m_DataType == 1 )
    {
      vNormal->x = 0.0;
      vNormal->y = 0.0;
      vNormal->z = 0.0;
    }
  }
  else
  {
    v7 = &pDisp->m_CoreDispInfo.m_pVerts[ndxDisp];
    *vNormal = v7->m_FieldVector;
    *dist = v7->m_FieldDistance;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E8E0
// Name: private: bool CDispMapImageFilterManager::PreApply(class CDispMapImageFilter __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispMapImageFilterManager::PreApply(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        int nPaintDirType,
        const Vector *vecPaintDir)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v5; // esi
  int v7; // ebx
  int i; // edi
  CMapDisp *v9; // eax

  this->m_PaintType = nPaintDirType;
  this->m_PaintDir = *vecPaintDir;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v5 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  v7 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
  for ( i = 0; i < v7; ++i )
  {
    v9 = v5->GetFromSelect(this: v5, a2: i);
    if ( v9 != nullptr )
      CMapDisp::Paint_Init(this: v9, nType: pFilter->m_DataType);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E960
// Name: private: bool CDispMapImageFilterManager::IsNeighborInSelectionSet(class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispMapImageFilterManager::IsNeighborInSelectionSet(
        CDispMapImageFilterManager *this,
        CMapDisp *pNeighborDisp)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  int v4; // ebx
  int v5; // esi

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  v4 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: v5) != pNeighborDisp )
  {
    if ( ++v5 >= v4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E9C0
// Name: private: void CDispMapImageFilterManager::HitData_Setup(struct CDispMapImageFilterManager::PosHitData_t __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::HitData_Setup(
        CDispMapImageFilterManager *this,
        CDispMapImageFilterManager::PosHitData_t *hitData,
        int ndxHgt,
        int ndxWid,
        int imgHgt,
        int imgWid)
{
  float v6; // xmm1_4
  int v7; // ecx

  v6 = (float)ndxHgt;
  hitData->m_CornerCount = 0;
  hitData->m_ndxCorners[1] = -1;
  hitData->m_ndxCorners[0] = -1;
  hitData->m_EdgeCount = 0;
  hitData->m_ndxEdges[1] = -1;
  hitData->m_ndxEdges[0] = -1;
  hitData->m_bMain = false;
  if ( (float)ndxHgt <= 0.0 && (float)ndxWid <= 0.0 )
  {
    hitData->m_ndxCorners[0] = 0;
    ++hitData->m_CornerCount;
  }
  v7 = imgHgt - 1;
  if ( ndxHgt >= imgHgt - 1 && (float)ndxWid <= 0.0 )
    hitData->m_ndxCorners[hitData->m_CornerCount++] = 2;
  if ( ndxHgt >= v7 && ndxWid >= imgWid - 1 )
    hitData->m_ndxCorners[hitData->m_CornerCount++] = 4;
  if ( v6 <= 0.0 && ndxWid >= imgWid - 1 )
    hitData->m_ndxCorners[hitData->m_CornerCount++] = 6;
  if ( v6 < 0.0 )
  {
LABEL_17:
    if ( ndxHgt < v7 )
      goto LABEL_21;
    goto LABEL_18;
  }
  if ( ndxHgt <= v7 )
  {
    if ( (float)ndxWid <= 0.0 )
      hitData->m_ndxEdges[hitData->m_EdgeCount++] = 1;
    goto LABEL_17;
  }
LABEL_18:
  if ( (float)ndxWid >= 0.0 && ndxWid <= imgWid - 1 )
    hitData->m_ndxEdges[hitData->m_EdgeCount++] = 3;
LABEL_21:
  if ( v6 >= 0.0 && ndxHgt <= v7 && ndxWid >= imgWid - 1 )
    hitData->m_ndxEdges[hitData->m_EdgeCount++] = 5;
  if ( v6 <= 0.0 && (float)ndxWid >= 0.0 && ndxWid <= imgWid - 1 )
    hitData->m_ndxEdges[hitData->m_EdgeCount++] = 7;
  if ( v6 >= 0.0 && ndxHgt < imgHgt && (float)ndxWid >= 0.0 && ndxWid < imgWid )
    hitData->m_bMain = true;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB20
// Name: private: class CMapDisp __near * CDispMapImageFilterManager::GetImage(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CDispMapImageFilterManager::GetImage(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        int *orient)
{
  int v8; // edi
  int v9; // edx
  int v10; // eax
  CMapDisp *v12; // esi
  int v13; // ecx
  CEditDispMgr *v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax

  v8 = 0;
  switch ( ndxImg )
  {
    case 0:
      v9 = pDisp->m_CornerNeighborCounts[0];
      if ( v9 == 0 )
        return nullptr;
      v10 = 0;
      if ( v9 <= 0 )
        return nullptr;
      while ( v10 != imgCount )
      {
        if ( ++v10 >= v9 )
          return nullptr;
      }
      CMapDisp::GetCornerNeighbor(
        this: pDisp,
        direction: 0,
        cornerIndex: v10,
        handle: (unsigned __int16 *)&pDisp,
        orient);
      v12 = pDisp;
      goto LABEL_10;
    case 1:
      v12 = (CMapDisp *)pDisp->m_EdgeNeighbors[0];
      v13 = pDisp->m_EdgeNeighborOrientations[0];
      goto LABEL_9;
    case 2:
      v15 = pDisp->m_CornerNeighborCounts[2];
      if ( v15 == 0 )
        return nullptr;
      v16 = 0;
      if ( v15 <= 0 )
        return nullptr;
      while ( v16 != imgCount )
      {
        if ( ++v16 >= v15 )
          return nullptr;
      }
      CMapDisp::GetCornerNeighbor(
        this: pDisp,
        direction: 2,
        cornerIndex: v16,
        handle: (unsigned __int16 *)&pDisp,
        orient);
      v12 = pDisp;
      goto LABEL_10;
    case 3:
      v12 = (CMapDisp *)pDisp->m_EdgeNeighbors[1];
      v13 = pDisp->m_EdgeNeighborOrientations[1];
      goto LABEL_9;
    case 4:
      v17 = pDisp->m_CornerNeighborCounts[3];
      if ( v17 == 0 )
        return nullptr;
      v18 = 0;
      if ( v17 <= 0 )
        return nullptr;
      while ( v18 != imgCount )
      {
        if ( ++v18 >= v17 )
          return nullptr;
      }
      CMapDisp::GetCornerNeighbor(
        this: pDisp,
        direction: 3,
        cornerIndex: v18,
        handle: (unsigned __int16 *)&pDisp,
        orient);
      v12 = pDisp;
      goto LABEL_10;
    case 5:
      v12 = (CMapDisp *)pDisp->m_EdgeNeighbors[2];
      v13 = pDisp->m_EdgeNeighborOrientations[2];
      goto LABEL_9;
    case 6:
      v19 = pDisp->m_CornerNeighborCounts[1];
      if ( v19 == 0 )
        return nullptr;
      v20 = 0;
      if ( v19 <= 0 )
        return nullptr;
      break;
    case 7:
      v12 = (CMapDisp *)pDisp->m_EdgeNeighbors[3];
      v13 = pDisp->m_EdgeNeighborOrientations[3];
LABEL_9:
      *orient = v13;
      goto LABEL_10;
    case 8:
      return pDisp;
    default:
      return nullptr;
  }
  while ( v20 != imgCount )
  {
    if ( ++v20 >= v19 )
      return nullptr;
  }
  CMapDisp::GetCornerNeighbor(this: pDisp, direction: 1, cornerIndex: v20, handle: (unsigned __int16 *)&pDisp, orient);
  v12 = pDisp;
LABEL_10:
  if ( (_WORD)v12 != 0xFFFF )
  {
    v14 = EditDispMgr();
    return v14->GetDisp(this: v14, a2: (unsigned __int16)v12);
  }
  return (CMapDisp *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x1001ECF0
// Name: private: int CDispMapImageFilterManager::GetSWImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetSWImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = ndxWid;
      v8 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v8 = -ndxWid;
      v9 = (1 << m_Power) + ndxHgt;
      goto LABEL_4;
    case 2:
      v7 = ndxHgt;
      v8 = v6 + ndxWid - 1;
LABEL_3:
      v9 = -v7;
      goto LABEL_4;
    case 3:
      v8 = (1 << m_Power) + ndxHgt;
      v9 = (1 << m_Power) + ndxWid;
LABEL_4:
      if ( v8 < 0 )
        v8 = 0;
      if ( v9 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v8 = 0;
LABEL_7:
      v9 = 0;
LABEL_8:
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      if ( v9 > v6 - 1 )
        v9 = v6 - 1;
      return v9 + v6 * v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ED80
// Name: private: void CDispMapImageFilterManager::SWImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::SWImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = ndxWid;
      v12 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v12 = -ndxWid;
      v13 = (1 << m_Power) + ndxHgt;
      goto LABEL_4;
    case 2:
      v11 = ndxHgt;
      v12 = v10 + ndxWid - 1;
LABEL_3:
      v13 = -v11;
      goto LABEL_4;
    case 3:
      v12 = (1 << m_Power) + ndxHgt;
      v13 = (1 << m_Power) + ndxWid;
LABEL_4:
      if ( v12 < 0 )
        v12 = 0;
      if ( v13 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v12 = 0;
LABEL_7:
      v13 = 0;
LABEL_8:
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      if ( v13 > v10 - 1 )
        v13 = v10 - 1;
      v14 = v13 + v10 * v12;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v14, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v14, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EE40
// Name: private: int CDispMapImageFilterManager::GetWImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetWImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = (1 << m_Power) - ndxHgt;
      v8 = -ndxWid;
      goto LABEL_3;
    case 1:
      v7 = (1 << m_Power) + ndxWid;
      v8 = (1 << m_Power) - ndxHgt;
      goto LABEL_3;
    case 2:
      v7 = ndxHgt;
      v8 = (1 << m_Power) + ndxWid;
      goto LABEL_3;
    case 3:
      v8 = ndxHgt;
      v7 = -ndxWid;
LABEL_3:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v7 = 0;
LABEL_6:
      v8 = 0;
LABEL_7:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EED0
// Name: private: void CDispMapImageFilterManager::WImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::WImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = (1 << m_Power) - ndxHgt;
      v12 = -ndxWid;
      goto LABEL_3;
    case 1:
      v11 = (1 << m_Power) + ndxWid;
      v12 = (1 << m_Power) - ndxHgt;
      goto LABEL_3;
    case 2:
      v11 = ndxHgt;
      v12 = (1 << m_Power) + ndxWid;
      goto LABEL_3;
    case 3:
      v12 = ndxHgt;
      v11 = -ndxWid;
LABEL_3:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v11 = 0;
LABEL_6:
      v12 = 0;
LABEL_7:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EF90
// Name: private: int CDispMapImageFilterManager::GetNWImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetNWImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = ndxHgt - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v7 = ndxHgt - (1 << m_Power);
      v8 = (1 << m_Power) + ndxWid;
      goto LABEL_4;
    case 2:
      v7 = 2 * v6 - ndxHgt - 2;
LABEL_3:
      v8 = -ndxWid;
      goto LABEL_4;
    case 3:
      v7 = (1 << m_Power) + ndxWid;
      v8 = 2 * v6 - ndxHgt - 2;
LABEL_4:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v7 = 0;
LABEL_7:
      v8 = 0;
LABEL_8:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F030
// Name: private: void CDispMapImageFilterManager::NWImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::NWImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = ndxHgt - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v11 = ndxHgt - (1 << m_Power);
      v12 = (1 << m_Power) + ndxWid;
      goto LABEL_4;
    case 2:
      v11 = 2 * v10 - ndxHgt - 2;
LABEL_3:
      v12 = -ndxWid;
      goto LABEL_4;
    case 3:
      v11 = (1 << m_Power) + ndxWid;
      v12 = 2 * v10 - ndxHgt - 2;
LABEL_4:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v11 = 0;
LABEL_7:
      v12 = 0;
LABEL_8:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F100
// Name: private: int CDispMapImageFilterManager::GetNImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetNImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = (1 << m_Power) - ndxWid;
      v8 = ndxHgt - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v7 = 2 * v6 - ndxHgt - 2;
      v8 = (1 << m_Power) - ndxWid;
      goto LABEL_3;
    case 2:
      v7 = ndxWid;
      v8 = 2 * v6 - ndxHgt - 2;
      goto LABEL_3;
    case 3:
      v8 = ndxWid;
      v7 = ndxHgt - v6 + 1;
LABEL_3:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v7 = 0;
LABEL_6:
      v8 = 0;
LABEL_7:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F1A0
// Name: private: void CDispMapImageFilterManager::NImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::NImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = (1 << m_Power) - ndxWid;
      v12 = ndxHgt - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v11 = 2 * v10 - ndxHgt - 2;
      v12 = (1 << m_Power) - ndxWid;
      goto LABEL_3;
    case 2:
      v11 = ndxWid;
      v12 = 2 * v10 - ndxHgt - 2;
      goto LABEL_3;
    case 3:
      v12 = ndxWid;
      v11 = ndxHgt - v10 + 1;
LABEL_3:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v11 = 0;
LABEL_6:
      v12 = 0;
LABEL_7:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F260
// Name: private: int CDispMapImageFilterManager::GetNEImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetNEImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // ecx

  v5 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v6 = ndxWid;
      v7 = ndxHgt - (1 << pDisp->m_CoreDispInfo.m_Power);
      goto LABEL_3;
    case 1:
      v7 = ndxWid - (1 << pDisp->m_CoreDispInfo.m_Power);
      v8 = 2 * v5 - ndxHgt - 2;
      goto LABEL_4;
    case 2:
      v6 = ndxHgt;
      v7 = 2 * v5 - ndxWid - 2;
LABEL_3:
      v8 = v6 - (1 << pDisp->m_CoreDispInfo.m_Power);
      goto LABEL_4;
    case 3:
      v7 = 2 * v5 - ndxHgt - 2;
      v8 = 2 * v5 - ndxWid - 2;
LABEL_4:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v7 = 0;
LABEL_7:
      v8 = 0;
LABEL_8:
      if ( v7 > 1 << pDisp->m_CoreDispInfo.m_Power )
        v7 = 1 << pDisp->m_CoreDispInfo.m_Power;
      if ( v8 > 1 << pDisp->m_CoreDispInfo.m_Power )
        v8 = 1 << pDisp->m_CoreDispInfo.m_Power;
      return v8 + v5 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F300
// Name: private: void CDispMapImageFilterManager::NEImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::NEImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  v9 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v10 = ndxWid;
      v11 = ndxHgt - (1 << pDisp->m_CoreDispInfo.m_Power);
      goto LABEL_3;
    case 1:
      v11 = ndxWid - (1 << pDisp->m_CoreDispInfo.m_Power);
      v12 = 2 * v9 - ndxHgt - 2;
      goto LABEL_4;
    case 2:
      v10 = ndxHgt;
      v11 = 2 * v9 - ndxWid - 2;
LABEL_3:
      v12 = v10 - (1 << pDisp->m_CoreDispInfo.m_Power);
      goto LABEL_4;
    case 3:
      v11 = 2 * v9 - ndxHgt - 2;
      v12 = 2 * v9 - ndxWid - 2;
LABEL_4:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_7;
      goto LABEL_8;
    default:
      v11 = 0;
LABEL_7:
      v12 = 0;
LABEL_8:
      if ( v11 > 1 << pDisp->m_CoreDispInfo.m_Power )
        v11 = 1 << pDisp->m_CoreDispInfo.m_Power;
      if ( v12 > 1 << pDisp->m_CoreDispInfo.m_Power )
        v12 = 1 << pDisp->m_CoreDispInfo.m_Power;
      v13 = v12 + v9 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F3D0
// Name: private: int CDispMapImageFilterManager::GetEImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetEImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = ndxHgt;
      v8 = ndxWid - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v8 = ndxHgt;
      v7 = 2 * v6 - ndxWid - 2;
      goto LABEL_3;
    case 2:
      v7 = (1 << m_Power) - ndxHgt;
      v8 = 2 * v6 - ndxWid - 2;
      goto LABEL_3;
    case 3:
      v7 = ndxWid - (1 << m_Power);
      v8 = (1 << m_Power) - ndxHgt;
LABEL_3:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v7 = 0;
LABEL_6:
      v8 = 0;
LABEL_7:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F470
// Name: private: void CDispMapImageFilterManager::EImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::EImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = ndxHgt;
      v12 = ndxWid - (1 << m_Power);
      goto LABEL_3;
    case 1:
      v12 = ndxHgt;
      v11 = 2 * v10 - ndxWid - 2;
      goto LABEL_3;
    case 2:
      v11 = (1 << m_Power) - ndxHgt;
      v12 = 2 * v10 - ndxWid - 2;
      goto LABEL_3;
    case 3:
      v11 = ndxWid - (1 << m_Power);
      v12 = (1 << m_Power) - ndxHgt;
LABEL_3:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v11 = 0;
LABEL_6:
      v12 = 0;
LABEL_7:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F530
// Name: private: int CDispMapImageFilterManager::GetSEImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetSEImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = ndxWid - (1 << m_Power);
      v8 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v7 = -ndxHgt;
      v8 = 2 * v6 - ndxWid - 2;
      goto LABEL_3;
    case 2:
      v7 = (1 << m_Power) + ndxHgt;
      v8 = ndxWid - (1 << m_Power);
      goto LABEL_3;
    case 3:
      v8 = (1 << m_Power) + ndxHgt;
      v7 = 2 * v6 - ndxWid - 2;
LABEL_3:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v7 = 0;
LABEL_6:
      v8 = 0;
LABEL_7:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F5D0
// Name: private: void CDispMapImageFilterManager::SEImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::SEImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = ndxWid - (1 << m_Power);
      v12 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v11 = -ndxHgt;
      v12 = 2 * v10 - ndxWid - 2;
      goto LABEL_3;
    case 2:
      v11 = (1 << m_Power) + ndxHgt;
      v12 = ndxWid - (1 << m_Power);
      goto LABEL_3;
    case 3:
      v12 = (1 << m_Power) + ndxHgt;
      v11 = 2 * v10 - ndxWid - 2;
LABEL_3:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v11 = 0;
LABEL_6:
      v12 = 0;
LABEL_7:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F6A0
// Name: private: int CDispMapImageFilterManager::GetSImageIndex(class CMapDisp __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetSImageIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid)
{
  int m_Power; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v6 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v7 = ndxWid;
      v8 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v7 = (1 << m_Power) + ndxHgt;
      v8 = ndxWid;
      goto LABEL_3;
    case 2:
      v8 = (1 << m_Power) + ndxHgt;
      v7 = v6 - ndxWid - 1;
      goto LABEL_3;
    case 3:
      v7 = -ndxHgt;
      v8 = (1 << m_Power) - ndxWid;
LABEL_3:
      if ( v7 < 0 )
        v7 = 0;
      if ( v8 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v7 = 0;
LABEL_6:
      v8 = 0;
LABEL_7:
      if ( v7 > v6 - 1 )
        v7 = v6 - 1;
      if ( v8 > v6 - 1 )
        v8 = v6 - 1;
      return v8 + v6 * v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F730
// Name: private: void CDispMapImageFilterManager::SImageValue(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,bool,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::SImageValue(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        bool bSet,
        Vector *value)
{
  int m_Power; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // eax

  m_Power = pDisp->m_CoreDispInfo.m_Power;
  v10 = (1 << m_Power) + 1;
  switch ( orient )
  {
    case 0:
      v11 = ndxWid;
      v12 = -ndxHgt;
      goto LABEL_3;
    case 1:
      v12 = ndxWid;
      v11 = v10 + ndxHgt - 1;
      goto LABEL_3;
    case 2:
      v12 = (1 << m_Power) + ndxHgt;
      v11 = v10 - ndxWid - 1;
      goto LABEL_3;
    case 3:
      v11 = -ndxHgt;
      v12 = (1 << m_Power) - ndxWid;
LABEL_3:
      if ( v11 < 0 )
        v11 = 0;
      if ( v12 < 0 )
        goto LABEL_6;
      goto LABEL_7;
    default:
      v11 = 0;
LABEL_6:
      v12 = 0;
LABEL_7:
      if ( v11 > v10 - 1 )
        v11 = v10 - 1;
      if ( v12 > v10 - 1 )
        v12 = v10 - 1;
      v13 = v12 + v10 * v11;
      if ( bSet )
        CMapDisp::Paint_SetValue(this: pDisp, iVert: v13, vPaint: value);
      else
        CDispMapImageFilterManager::GetImageValue(this, pDisp, pFilter, ndxDisp: v13, vPaintValue: value);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F7F0
// Name: private: bool CDispMapImageFilterManager::GetFilterVector(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispMapImageFilterManager::GetFilterVector(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        int ndxFilter,
        Vector *vFilterDir)
{
  Vector *v10; // eax
  CMapDisp *Image; // esi
  bool v13; // zf
  int SWImageIndex; // eax
  float v15; // xmm0_4
  Vector *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  Vector normal; // [esp+4h] [ebp-Ch] BYREF

  if ( pFilter->m_DataType == 1 )
  {
    v10 = vFilterDir;
    vFilterDir->x = pFilter->m_pImage[ndxFilter] * pFilter->m_Scale;
    v10->y = 0.0;
    v10->z = 0.0;
    return 1;
  }
  else
  {
    Image = CDispMapImageFilterManager::GetImage(
              this,
              pFilter,
              pDisp,
              ndxHgt,
              ndxWid,
              ndxImg,
              imgCount,
              orient: &imgCount);
    if ( Image != nullptr )
    {
      v13 = this->m_PaintType == 3;
      normal = this->m_PaintDir;
      if ( v13 )
      {
        switch ( ndxImg )
        {
          case 0:
            SWImageIndex = CDispMapImageFilterManager::GetSWImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 1:
            SWImageIndex = CDispMapImageFilterManager::GetWImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 2:
            SWImageIndex = CDispMapImageFilterManager::GetNWImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 3:
            SWImageIndex = CDispMapImageFilterManager::GetNImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 4:
            SWImageIndex = CDispMapImageFilterManager::GetNEImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 5:
            SWImageIndex = CDispMapImageFilterManager::GetEImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 6:
            SWImageIndex = CDispMapImageFilterManager::GetSEImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 7:
            SWImageIndex = CDispMapImageFilterManager::GetSImageIndex(
                             this,
                             pDisp: Image,
                             orient: imgCount,
                             ndxHgt,
                             ndxWid);
            break;
          case 8:
            CMapDisp::GetSubdivNormal(
              this: pDisp,
              ndx: ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1),
              v: &normal);
            goto LABEL_8;
          default:
            return 0;
        }
        CMapDisp::GetSubdivNormal(this: Image, ndx: SWImageIndex, v: &normal);
      }
LABEL_8:
      v15 = pFilter->m_pImage[ndxFilter] * pFilter->m_Scale;
      v16 = vFilterDir;
      v17 = v15 * normal.x;
      v18 = v15 * normal.y;
      v19 = v15 * normal.z;
      vFilterDir->x = v17;
      v16->y = v18;
      v16->z = v19;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FA00
// Name: private: static enum ChunkFileResult_t CDispMapImageFilter::LoadImageCallback(class CChunkFile __near *,class CDispMapImageFilter __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CDispMapImageFilter::LoadImageCallback(CChunkFile *pFile, CDispMapImageFilter *pFilter)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CDispMapImageFilter::LoadImageKeyCallback,
           pData: pFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1001FA20
// Name: private: bool CDispMapImageFilterManager::GetImageFieldValues(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispMapImageFilterManager::GetImageFieldValues(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        Vector *vNormal,
        float *dist)
{
  CMapDisp *Image; // edi
  int SWImageIndex; // eax
  bool result; // al
  int WImageIndex; // eax
  int NWImageIndex; // eax
  int NImageIndex; // eax
  int NEImageIndex; // eax
  int EImageIndex; // eax
  int SEImageIndex; // eax
  int SImageIndex; // eax
  Vector *v20; // [esp-8h] [ebp-14h]
  Vector *v21; // [esp-8h] [ebp-14h]
  Vector *v22; // [esp-8h] [ebp-14h]
  Vector *v23; // [esp-8h] [ebp-14h]
  Vector *v24; // [esp-8h] [ebp-14h]
  Vector *v25; // [esp-8h] [ebp-14h]
  Vector *v26; // [esp-8h] [ebp-14h]
  Vector *v27; // [esp-8h] [ebp-14h]
  float *v28; // [esp-4h] [ebp-10h]
  float *v29; // [esp-4h] [ebp-10h]
  float *v30; // [esp-4h] [ebp-10h]
  float *v31; // [esp-4h] [ebp-10h]
  float *v32; // [esp-4h] [ebp-10h]
  float *v33; // [esp-4h] [ebp-10h]
  float *v34; // [esp-4h] [ebp-10h]
  float *v35; // [esp-4h] [ebp-10h]

  Image = CDispMapImageFilterManager::GetImage(
            this,
            pFilter,
            pDisp,
            ndxHgt,
            ndxWid,
            ndxImg,
            imgCount,
            orient: &imgCount);
  if ( Image == nullptr )
    return false;
  switch ( ndxImg )
  {
    case 0:
      v28 = dist;
      v20 = vNormal;
      SWImageIndex = CDispMapImageFilterManager::GetSWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SWImageIndex,
        vNormal: v20,
        dist: v28);
      result = true;
      break;
    case 1:
      v29 = dist;
      v21 = vNormal;
      WImageIndex = CDispMapImageFilterManager::GetWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: WImageIndex,
        vNormal: v21,
        dist: v29);
      result = true;
      break;
    case 2:
      v30 = dist;
      v22 = vNormal;
      NWImageIndex = CDispMapImageFilterManager::GetNWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NWImageIndex,
        vNormal: v22,
        dist: v30);
      result = true;
      break;
    case 3:
      v31 = dist;
      v23 = vNormal;
      NImageIndex = CDispMapImageFilterManager::GetNImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NImageIndex,
        vNormal: v23,
        dist: v31);
      result = true;
      break;
    case 4:
      v32 = dist;
      v24 = vNormal;
      NEImageIndex = CDispMapImageFilterManager::GetNEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NEImageIndex,
        vNormal: v24,
        dist: v32);
      result = true;
      break;
    case 5:
      v33 = dist;
      v25 = vNormal;
      EImageIndex = CDispMapImageFilterManager::GetEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: EImageIndex,
        vNormal: v25,
        dist: v33);
      result = true;
      break;
    case 6:
      v34 = dist;
      v26 = vNormal;
      SEImageIndex = CDispMapImageFilterManager::GetSEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SEImageIndex,
        vNormal: v26,
        dist: v34);
      result = true;
      break;
    case 7:
      v35 = dist;
      v27 = vNormal;
      SImageIndex = CDispMapImageFilterManager::GetSImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SImageIndex,
        vNormal: v27,
        dist: v35);
      result = true;
      break;
    case 8:
      CDispMapImageFilterManager::GetImageFieldData(
        this,
        pDisp,
        pFilter,
        ndxDisp: ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1),
        vNormal,
        dist);
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FC40
// Name: private: bool CDispMapImageFilterManager::GetImageFlatSubdivValues(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispMapImageFilterManager::GetImageFlatSubdivValues(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        Vector *value)
{
  CMapDisp *Image; // edi
  int SWImageIndex; // eax
  bool result; // al
  int WImageIndex; // eax
  int NWImageIndex; // eax
  int NImageIndex; // eax
  int NEImageIndex; // eax
  int EImageIndex; // eax
  int SEImageIndex; // eax
  int SImageIndex; // eax
  Vector *v19; // [esp-4h] [ebp-10h]
  Vector *v20; // [esp-4h] [ebp-10h]
  Vector *v21; // [esp-4h] [ebp-10h]
  Vector *v22; // [esp-4h] [ebp-10h]
  Vector *v23; // [esp-4h] [ebp-10h]
  Vector *v24; // [esp-4h] [ebp-10h]
  Vector *v25; // [esp-4h] [ebp-10h]
  Vector *v26; // [esp-4h] [ebp-10h]

  Image = CDispMapImageFilterManager::GetImage(
            this,
            pFilter,
            pDisp,
            ndxHgt,
            ndxWid,
            ndxImg,
            imgCount,
            orient: &imgCount);
  if ( Image == nullptr )
    return false;
  switch ( ndxImg )
  {
    case 0:
      v19 = value;
      SWImageIndex = CDispMapImageFilterManager::GetSWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SWImageIndex,
        vPaintValue: v19);
      result = true;
      break;
    case 1:
      v20 = value;
      WImageIndex = CDispMapImageFilterManager::GetWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: WImageIndex,
        vPaintValue: v20);
      result = true;
      break;
    case 2:
      v21 = value;
      NWImageIndex = CDispMapImageFilterManager::GetNWImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NWImageIndex,
        vPaintValue: v21);
      result = true;
      break;
    case 3:
      v22 = value;
      NImageIndex = CDispMapImageFilterManager::GetNImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NImageIndex,
        vPaintValue: v22);
      result = true;
      break;
    case 4:
      v23 = value;
      NEImageIndex = CDispMapImageFilterManager::GetNEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: NEImageIndex,
        vPaintValue: v23);
      result = true;
      break;
    case 5:
      v24 = value;
      EImageIndex = CDispMapImageFilterManager::GetEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: EImageIndex,
        vPaintValue: v24);
      result = true;
      break;
    case 6:
      v25 = value;
      SEImageIndex = CDispMapImageFilterManager::GetSEImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SEImageIndex,
        vPaintValue: v25);
      result = true;
      break;
    case 7:
      v26 = value;
      SImageIndex = CDispMapImageFilterManager::GetSImageIndex(this, pDisp: Image, orient: imgCount, ndxHgt, ndxWid);
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp: Image,
        pFilter,
        ndxDisp: SImageIndex,
        vPaintValue: v26);
      result = true;
      break;
    case 8:
      CDispMapImageFilterManager::GetImageFlatSubdivValue(
        this,
        pDisp,
        pFilter,
        ndxDisp: ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1),
        vPaintValue: value);
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FE40
// Name: private: bool CDispMapImageFilterManager::GetImageValues(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispMapImageFilterManager::GetImageValues(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        Vector *value)
{
  CMapDisp *Image; // eax
  CMapDisp *v10; // edi
  bool result; // al

  Image = CDispMapImageFilterManager::GetImage(
            this,
            pFilter,
            pDisp,
            ndxHgt,
            ndxWid,
            ndxImg,
            imgCount,
            orient: &imgCount);
  v10 = Image;
  if ( Image == nullptr || CDispMapImageFilterManager::IsNeighborInSelectionSet(this, pNeighborDisp: Image) == 0 )
    return false;
  switch ( ndxImg )
  {
    case 0:
      CDispMapImageFilterManager::SWImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 1:
      CDispMapImageFilterManager::WImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 2:
      CDispMapImageFilterManager::NWImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 3:
      CDispMapImageFilterManager::NImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 4:
      CDispMapImageFilterManager::NEImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 5:
      CDispMapImageFilterManager::EImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 6:
      CDispMapImageFilterManager::SEImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 7:
      CDispMapImageFilterManager::SImageValue(
        this,
        pFilter,
        pDisp: v10,
        orient: imgCount,
        ndxHgt,
        ndxWid,
        bSet: false,
        value);
      result = true;
      break;
    case 8:
      CDispMapImageFilterManager::GetImageValue(
        this,
        pDisp,
        pFilter,
        ndxDisp: ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1),
        vPaintValue: value);
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020020
// Name: private: int CDispMapImageFilterManager::GetAdjustedIndex(class CMapDisp __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispMapImageFilterManager::GetAdjustedIndex(
        CDispMapImageFilterManager *this,
        CMapDisp *pDisp,
        int orient,
        int ndxHgt,
        int ndxWid,
        int ndxImg)
{
  int result; // eax

  switch ( ndxImg )
  {
    case 0:
      result = CDispMapImageFilterManager::GetSWImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 1:
      result = CDispMapImageFilterManager::GetWImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 2:
      result = CDispMapImageFilterManager::GetNWImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 3:
      result = CDispMapImageFilterManager::GetNImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 4:
      result = CDispMapImageFilterManager::GetNEImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 5:
      result = CDispMapImageFilterManager::GetEImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 6:
      result = CDispMapImageFilterManager::GetSEImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 7:
      result = CDispMapImageFilterManager::GetSImageIndex(this, pDisp, orient, ndxHgt, ndxWid);
      break;
    case 8:
      result = ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1);
      break;
    default:
      result = -1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020150
// Name: private: void CDispMapImageFilterManager::SetImageValues(class CDispMapImageFilter __near *,class CMapDisp __near *,int,int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::SetImageValues(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxHgt,
        int ndxWid,
        int ndxImg,
        int imgCount,
        Vector *value)
{
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // edi
  CEditDispMgr *v13; // eax
  CMapDisp *v14; // eax
  int v15; // esi
  int v16; // edi
  CEditDispMgr *v17; // eax
  CMapDisp *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // esi
  int v22; // edi
  CEditDispMgr *v23; // eax
  CMapDisp *v24; // eax
  int v25; // esi
  int v26; // edi
  CEditDispMgr *v27; // eax
  CMapDisp *v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // esi
  int v32; // edi
  CEditDispMgr *v33; // eax
  CMapDisp *v34; // eax
  int v35; // esi
  int v36; // edi
  CEditDispMgr *v37; // eax
  CMapDisp *v38; // eax
  int v39; // ecx
  int v40; // eax
  int v41; // esi
  int v42; // edi
  CEditDispMgr *v43; // eax
  CMapDisp *v44; // eax
  int v45; // esi
  int v46; // edi
  CEditDispMgr *v47; // eax
  CMapDisp *v48; // eax

  switch ( ndxImg )
  {
    case 0:
      v9 = pDisp->m_CornerNeighborCounts[0];
      if ( v9 != 0 )
      {
        v10 = 0;
        if ( v9 > 0 )
        {
          while ( v10 != imgCount )
          {
            if ( ++v10 >= v9 )
              return;
          }
          if ( v10 < v9 )
          {
            v11 = pDisp->m_CornerNeighbors[0][v10];
            v12 = pDisp->m_CornerNeighborOrientations[0][v10];
            if ( (_WORD)v11 != 0xFFFF )
            {
              v13 = EditDispMgr();
              v14 = v13->GetDisp(this: v13, a2: v11);
              CDispMapImageFilterManager::SWImageValue(
                this,
                pFilter,
                pDisp: v14,
                orient: v12,
                ndxHgt,
                ndxWid,
                bSet: true,
                value);
            }
          }
        }
      }
      break;
    case 1:
      v15 = pDisp->m_EdgeNeighbors[0];
      v16 = pDisp->m_EdgeNeighborOrientations[0];
      if ( (_WORD)v15 != 0xFFFF )
      {
        v17 = EditDispMgr();
        v18 = v17->GetDisp(this: v17, a2: v15);
        CDispMapImageFilterManager::WImageValue(
          this,
          pFilter,
          pDisp: v18,
          orient: v16,
          ndxHgt,
          ndxWid,
          bSet: true,
          value);
      }
      break;
    case 2:
      v19 = pDisp->m_CornerNeighborCounts[2];
      if ( v19 != 0 )
      {
        v20 = 0;
        if ( v19 > 0 )
        {
          while ( v20 != imgCount )
          {
            if ( ++v20 >= v19 )
              return;
          }
          if ( v20 < v19 )
          {
            v21 = pDisp->m_CornerNeighbors[2][v20];
            v22 = pDisp->m_CornerNeighborOrientations[2][v20];
            if ( (_WORD)v21 != 0xFFFF )
            {
              v23 = EditDispMgr();
              v24 = v23->GetDisp(this: v23, a2: v21);
              CDispMapImageFilterManager::NWImageValue(
                this,
                pFilter,
                pDisp: v24,
                orient: v22,
                ndxHgt,
                ndxWid,
                bSet: true,
                value);
            }
          }
        }
      }
      break;
    case 3:
      v25 = pDisp->m_EdgeNeighbors[1];
      v26 = pDisp->m_EdgeNeighborOrientations[1];
      if ( (_WORD)v25 != 0xFFFF )
      {
        v27 = EditDispMgr();
        v28 = v27->GetDisp(this: v27, a2: v25);
        CDispMapImageFilterManager::NImageValue(
          this,
          pFilter,
          pDisp: v28,
          orient: v26,
          ndxHgt,
          ndxWid,
          bSet: true,
          value);
      }
      break;
    case 4:
      v29 = pDisp->m_CornerNeighborCounts[3];
      if ( v29 != 0 )
      {
        v30 = 0;
        if ( v29 > 0 )
        {
          while ( v30 != imgCount )
          {
            if ( ++v30 >= v29 )
              return;
          }
          if ( v30 < v29 )
          {
            v31 = pDisp->m_CornerNeighbors[3][v30];
            v32 = pDisp->m_CornerNeighborOrientations[3][v30];
            if ( (_WORD)v31 != 0xFFFF )
            {
              v33 = EditDispMgr();
              v34 = v33->GetDisp(this: v33, a2: v31);
              CDispMapImageFilterManager::NEImageValue(
                this,
                pFilter,
                pDisp: v34,
                orient: v32,
                ndxHgt,
                ndxWid,
                bSet: true,
                value);
            }
          }
        }
      }
      break;
    case 5:
      v35 = pDisp->m_EdgeNeighbors[2];
      v36 = pDisp->m_EdgeNeighborOrientations[2];
      if ( (_WORD)v35 != 0xFFFF )
      {
        v37 = EditDispMgr();
        v38 = v37->GetDisp(this: v37, a2: v35);
        CDispMapImageFilterManager::EImageValue(
          this,
          pFilter,
          pDisp: v38,
          orient: v36,
          ndxHgt,
          ndxWid,
          bSet: true,
          value);
      }
      break;
    case 6:
      v39 = pDisp->m_CornerNeighborCounts[1];
      if ( v39 != 0 )
      {
        v40 = 0;
        if ( v39 > 0 )
        {
          while ( v40 != imgCount )
          {
            if ( ++v40 >= v39 )
              return;
          }
          if ( v40 < v39 )
          {
            v41 = pDisp->m_CornerNeighbors[1][v40];
            v42 = pDisp->m_CornerNeighborOrientations[1][v40];
            if ( (_WORD)v41 != 0xFFFF )
            {
              v43 = EditDispMgr();
              v44 = v43->GetDisp(this: v43, a2: v41);
              CDispMapImageFilterManager::SEImageValue(
                this,
                pFilter,
                pDisp: v44,
                orient: v42,
                ndxHgt,
                ndxWid,
                bSet: true,
                value);
            }
          }
        }
      }
      break;
    case 7:
      v45 = pDisp->m_EdgeNeighbors[3];
      v46 = pDisp->m_EdgeNeighborOrientations[3];
      if ( (_WORD)v45 != 0xFFFF )
      {
        v47 = EditDispMgr();
        v48 = v47->GetDisp(this: v47, a2: v45);
        CDispMapImageFilterManager::SImageValue(
          this,
          pFilter,
          pDisp: v48,
          orient: v46,
          ndxHgt,
          ndxWid,
          bSet: true,
          value);
      }
      break;
    case 8:
      CMapDisp::Paint_SetValue(
        this: pDisp,
        iVert: ndxWid + ndxHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1),
        vPaint: value);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020510
// Name: private: void CDispMapImageFilterManager::ApplyAddFilter(class CDispMapImageFilter __near *,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::ApplyAddFilter(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int iVert)
{
  int m_Height; // ebx
  int m_Width; // edx
  int v8; // eax
  int v9; // ecx
  int i; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  bool v16; // zf
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int v22; // ebx
  int v23; // ecx
  int m_DataType; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float x; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  CoreDispVert_t *m_pVerts; // edx
  float v33; // xmm1_4
  float v34; // xmm1_4
  CDispMapImageFilterManager::PosHitData_t hitData; // [esp+Ch] [ebp-74h] BYREF
  Vector vFilterDir; // [esp+28h] [ebp-58h] BYREF
  Vector vecFilter; // [esp+34h] [ebp-4Ch] BYREF
  Vector vecImage; // [esp+40h] [ebp-40h] BYREF
  int nFilterHeight; // [esp+4Ch] [ebp-34h]
  int j; // [esp+50h] [ebp-30h]
  int nFilterMidWidth; // [esp+54h] [ebp-2Ch]
  int iVertWidth; // [esp+58h] [ebp-28h]
  int v43; // [esp+5Ch] [ebp-24h]
  int v44; // [esp+60h] [ebp-20h]
  int iCorner; // [esp+64h] [ebp-1Ch]
  int iHgt; // [esp+68h] [ebp-18h]
  int nFilterWidth; // [esp+6Ch] [ebp-14h]
  int ndxImg; // [esp+70h] [ebp-10h]
  int v49; // [esp+74h] [ebp-Ch]
  int iCurCorner; // [esp+78h] [ebp-8h]
  CDispMapImageFilterManager *v51; // [esp+7Ch] [ebp-4h]
  int iWid; // [esp+88h] [ebp+8h]
  int iEdge; // [esp+8Ch] [ebp+Ch]
  int iEdgea; // [esp+8Ch] [ebp+Ch]
  int iEdgeb; // [esp+8Ch] [ebp+Ch]
  int nAdjHeight; // [esp+90h] [ebp+10h]

  m_Height = pFilter->m_Height;
  m_Width = pFilter->m_Width;
  v51 = this;
  v8 = 1 << pDisp->m_CoreDispInfo.m_Power;
  nFilterWidth = m_Width;
  nFilterHeight = m_Height;
  v9 = v8 + 1;
  nFilterMidWidth = (m_Width - 1) / 2;
  v44 = v8 + 1;
  iHgt = 0;
  iVertWidth = iVert % (v8 + 1);
  if ( m_Height > 0 )
  {
    v49 = 0;
    v43 = iVert / (v8 + 1) - (m_Height - 1) / 2;
    for ( i = iHgt; i < m_Height; iHgt = i )
    {
      iWid = 0;
      if ( nFilterWidth > 0 )
      {
        v11 = i + v43;
        v12 = iVertWidth - nFilterMidWidth;
        nAdjHeight = v11;
        for ( j = iVertWidth - nFilterMidWidth; ; v12 = j )
        {
          v13 = v12 + iWid;
          CDispMapImageFilterManager::HitData_Setup(
            this: v51,
            &hitData,
            ndxHgt: nAdjHeight,
            ndxWid: v12 + iWid,
            imgHgt: v9,
            imgWid: v9);
          if ( hitData.m_CornerCount != 0 )
          {
            v14 = 0;
            for ( iCorner = 0; v14 < hitData.m_CornerCount; iCorner = v14 )
            {
              ndxImg = hitData.m_ndxCorners[v14];
              v15 = ndxImg;
              switch ( ndxImg )
              {
                case 0:
                  iEdge = pDisp->m_CornerNeighborCounts[0];
                  break;
                case 2:
                  iEdge = pDisp->m_CornerNeighborCounts[2];
                  break;
                case 4:
                  iEdge = pDisp->m_CornerNeighborCounts[3];
                  break;
                case 6:
                  iEdge = pDisp->m_CornerNeighborCounts[1];
                  break;
                default:
                  iEdge = -1;
                  break;
              }
              iCurCorner = 0;
              if ( iEdge > 0 )
              {
                while ( 1 )
                {
                  if ( CDispMapImageFilterManager::GetImageValues(
                         this: v51,
                         pFilter,
                         pDisp,
                         ndxHgt: nAdjHeight,
                         ndxWid: v13,
                         ndxImg: v15,
                         imgCount: iCurCorner,
                         value: &vecImage) )
                  {
                    CDispMapImageFilterManager::GetFilterVector(
                      this: v51,
                      pFilter,
                      pDisp,
                      ndxHgt: nAdjHeight,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: iCurCorner,
                      ndxFilter: iWid + v49,
                      vFilterDir: &vecFilter);
                    v16 = pFilter->m_DataType == 1;
                    v17 = vecFilter.x + vecImage.x;
                    vecImage.y = vecImage.y + vecFilter.y;
                    vecImage.x = vecFilter.x + vecImage.x;
                    vecImage.z = vecImage.z + vecFilter.z;
                    if ( v16 )
                    {
                      v18 = 0.0;
                      if ( v17 < 0.0 || (v18 = 255.0, v17 > 255.0) )
                        vecImage.x = v18;
                    }
                    CDispMapImageFilterManager::SetImageValues(
                      this: v51,
                      pFilter,
                      pDisp,
                      ndxHgt: nAdjHeight,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: iCurCorner,
                      value: &vecImage);
                  }
                  if ( ++iCurCorner >= iEdge )
                    break;
                  v15 = ndxImg;
                }
                v14 = iCorner;
              }
              ++v14;
            }
          }
          if ( hitData.m_EdgeCount != 0 )
          {
            for ( iEdgea = 0; iEdgea < hitData.m_EdgeCount; ++iEdgea )
            {
              if ( CDispMapImageFilterManager::GetImageValues(
                     this: v51,
                     pFilter,
                     pDisp,
                     ndxHgt: nAdjHeight,
                     ndxWid: v13,
                     ndxImg: hitData.m_ndxEdges[iEdgea],
                     imgCount: 0,
                     value: &vecImage) )
              {
                CDispMapImageFilterManager::GetFilterVector(
                  this: v51,
                  pFilter,
                  pDisp,
                  ndxHgt: nAdjHeight,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[iEdgea],
                  imgCount: 0,
                  ndxFilter: iWid + v49,
                  &vFilterDir);
                v16 = pFilter->m_DataType == 1;
                v19 = vFilterDir.x + vecImage.x;
                vecImage.y = vFilterDir.y + vecImage.y;
                vecImage.x = vFilterDir.x + vecImage.x;
                vecImage.z = vFilterDir.z + vecImage.z;
                if ( v16 )
                {
                  v20 = 0.0;
                  if ( v19 < 0.0 || (v20 = 255.0, v19 > 255.0) )
                    vecImage.x = v20;
                }
                CDispMapImageFilterManager::SetImageValues(
                  this: v51,
                  pFilter,
                  pDisp,
                  ndxHgt: nAdjHeight,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[iEdgea],
                  imgCount: 0,
                  value: &vecImage);
              }
            }
          }
          if ( hitData.m_bMain )
          {
            ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
            iCorner = (int)ActiveWorldEditDispManager;
            if ( ActiveWorldEditDispManager != nullptr )
            {
              ndxImg = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
              iEdgeb = 0;
              if ( ndxImg > 0 )
              {
                while ( (CMapDisp *)(*(int (__thiscall **)(int, int))(*(_DWORD *)iCorner + 36))(a1: iCorner, a2: iEdgeb) != pDisp )
                {
                  if ( ++iEdgeb >= ndxImg )
                    goto LABEL_51;
                }
                v22 = nAdjHeight * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1) + v13;
                CDispMapImageFilterManager::GetImageValue(
                  this: v51,
                  pDisp,
                  pFilter,
                  ndxDisp: v22,
                  vPaintValue: &vecImage);
                v23 = iWid + v49;
                m_DataType = pFilter->m_DataType;
                if ( m_DataType == 1 )
                {
                  v25 = 0.0;
                  v26 = pFilter->m_pImage[v23] * pFilter->m_Scale;
                  v27 = 0.0;
                  v28 = 0.0;
                }
                else
                {
                  x = v51->m_PaintDir.x;
                  y = v51->m_PaintDir.y;
                  z = v51->m_PaintDir.z;
                  if ( v51->m_PaintType == 3 )
                  {
                    m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
                    x = m_pVerts[v22].m_SubdivNormal.x;
                    y = m_pVerts[v22].m_SubdivNormal.y;
                    z = m_pVerts[v22].m_SubdivNormal.z;
                    v23 = iWid + v49;
                  }
                  v33 = pFilter->m_pImage[v23] * pFilter->m_Scale;
                  v27 = y * v33;
                  v28 = z * v33;
                  v25 = 0.0;
                  v26 = v33 * x;
                }
                v34 = v26 + vecImage.x;
                vecImage.x = v34;
                vecImage.y = vecImage.y + v27;
                vecImage.z = vecImage.z + v28;
                if ( m_DataType == 1 )
                {
                  if ( v34 < 0.0 || (v25 = 255.0, v34 > 255.0) )
                    vecImage.x = v25;
                }
                CMapDisp::Paint_SetValue(this: pDisp, iVert: v22, vPaint: &vecImage);
              }
            }
          }
LABEL_51:
          v9 = v44;
          if ( ++iWid >= nFilterWidth )
            break;
        }
        m_Height = nFilterHeight;
        i = iHgt;
      }
      v49 += m_Height;
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100209A0
// Name: private: void CDispMapImageFilterManager::ApplyMultFilter(class CDispMapImageFilter __near *,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::ApplyMultFilter(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxVert)
{
  int m_Height; // ebx
  int m_Width; // edx
  int v8; // eax
  int v9; // ecx
  int k; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  bool v16; // zf
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int v22; // ebx
  int v23; // ecx
  int m_DataType; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float x; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  CoreDispVert_t *m_pVerts; // edx
  float v33; // xmm1_4
  float v34; // xmm1_4
  CDispMapImageFilterManager::PosHitData_t hitData; // [esp+Ch] [ebp-74h] BYREF
  Vector vFilterDir; // [esp+28h] [ebp-58h] BYREF
  Vector vFilter; // [esp+34h] [ebp-4Ch] BYREF
  Vector vImg; // [esp+40h] [ebp-40h] BYREF
  int filterHgt; // [esp+4Ch] [ebp-34h]
  int m; // [esp+50h] [ebp-30h]
  int filterMidWid; // [esp+54h] [ebp-2Ch]
  int ndxVertWid; // [esp+58h] [ebp-28h]
  int v43; // [esp+5Ch] [ebp-24h]
  int v44; // [esp+60h] [ebp-20h]
  int i; // [esp+64h] [ebp-1Ch]
  int ndxHgt; // [esp+68h] [ebp-18h]
  int filterWid; // [esp+6Ch] [ebp-14h]
  int ndxImg; // [esp+70h] [ebp-10h]
  int v49; // [esp+74h] [ebp-Ch]
  int j; // [esp+78h] [ebp-8h]
  CDispMapImageFilterManager *v51; // [esp+7Ch] [ebp-4h]
  int ndxWid; // [esp+88h] [ebp+8h]
  int count; // [esp+8Ch] [ebp+Ch]
  int counta; // [esp+8Ch] [ebp+Ch]
  int countb; // [esp+8Ch] [ebp+Ch]
  int adjHgt; // [esp+90h] [ebp+10h]

  m_Height = pFilter->m_Height;
  m_Width = pFilter->m_Width;
  v51 = this;
  v8 = 1 << pDisp->m_CoreDispInfo.m_Power;
  filterWid = m_Width;
  filterHgt = m_Height;
  v9 = v8 + 1;
  filterMidWid = (m_Width - 1) / 2;
  v44 = v8 + 1;
  ndxHgt = 0;
  ndxVertWid = ndxVert % (v8 + 1);
  if ( m_Height > 0 )
  {
    v49 = 0;
    v43 = ndxVert / (v8 + 1) - (m_Height - 1) / 2;
    for ( k = ndxHgt; k < m_Height; ndxHgt = k )
    {
      ndxWid = 0;
      if ( filterWid > 0 )
      {
        v11 = k + v43;
        v12 = ndxVertWid - filterMidWid;
        adjHgt = v11;
        for ( m = ndxVertWid - filterMidWid; ; v12 = m )
        {
          v13 = v12 + ndxWid;
          CDispMapImageFilterManager::HitData_Setup(
            this: v51,
            &hitData,
            ndxHgt: adjHgt,
            ndxWid: v12 + ndxWid,
            imgHgt: v9,
            imgWid: v9);
          if ( hitData.m_CornerCount != 0 )
          {
            v14 = 0;
            for ( i = 0; v14 < hitData.m_CornerCount; i = v14 )
            {
              ndxImg = hitData.m_ndxCorners[v14];
              v15 = ndxImg;
              switch ( ndxImg )
              {
                case 0:
                  count = pDisp->m_CornerNeighborCounts[0];
                  break;
                case 2:
                  count = pDisp->m_CornerNeighborCounts[2];
                  break;
                case 4:
                  count = pDisp->m_CornerNeighborCounts[3];
                  break;
                case 6:
                  count = pDisp->m_CornerNeighborCounts[1];
                  break;
                default:
                  count = -1;
                  break;
              }
              j = 0;
              if ( count > 0 )
              {
                while ( 1 )
                {
                  if ( CDispMapImageFilterManager::GetImageValues(
                         this: v51,
                         pFilter,
                         pDisp,
                         ndxHgt: adjHgt,
                         ndxWid: v13,
                         ndxImg: v15,
                         imgCount: j,
                         value: &vImg) )
                  {
                    CDispMapImageFilterManager::GetFilterVector(
                      this: v51,
                      pFilter,
                      pDisp,
                      ndxHgt: adjHgt,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: j,
                      ndxFilter: ndxWid + v49,
                      vFilterDir: &vFilter);
                    v16 = pFilter->m_DataType == 1;
                    v17 = vFilter.x * vImg.x;
                    vImg.y = vImg.y * vFilter.y;
                    vImg.x = vFilter.x * vImg.x;
                    vImg.z = vImg.z * vFilter.z;
                    if ( v16 )
                    {
                      v18 = 0.0;
                      if ( v17 < 0.0 || (v18 = 255.0, v17 > 255.0) )
                        vImg.x = v18;
                    }
                    CDispMapImageFilterManager::SetImageValues(
                      this: v51,
                      pFilter,
                      pDisp,
                      ndxHgt: adjHgt,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: j,
                      value: &vImg);
                  }
                  if ( ++j >= count )
                    break;
                  v15 = ndxImg;
                }
                v14 = i;
              }
              ++v14;
            }
          }
          if ( hitData.m_EdgeCount != 0 )
          {
            for ( counta = 0; counta < hitData.m_EdgeCount; ++counta )
            {
              if ( CDispMapImageFilterManager::GetImageValues(
                     this: v51,
                     pFilter,
                     pDisp,
                     ndxHgt: adjHgt,
                     ndxWid: v13,
                     ndxImg: hitData.m_ndxEdges[counta],
                     imgCount: 0,
                     value: &vImg) )
              {
                CDispMapImageFilterManager::GetFilterVector(
                  this: v51,
                  pFilter,
                  pDisp,
                  ndxHgt: adjHgt,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[counta],
                  imgCount: 0,
                  ndxFilter: ndxWid + v49,
                  &vFilterDir);
                v16 = pFilter->m_DataType == 1;
                v19 = vFilterDir.x + vImg.x;
                vImg.y = vFilterDir.y + vImg.y;
                vImg.x = vFilterDir.x + vImg.x;
                vImg.z = vFilterDir.z + vImg.z;
                if ( v16 )
                {
                  v20 = 0.0;
                  if ( v19 < 0.0 || (v20 = 255.0, v19 > 255.0) )
                    vImg.x = v20;
                }
                CDispMapImageFilterManager::SetImageValues(
                  this: v51,
                  pFilter,
                  pDisp,
                  ndxHgt: adjHgt,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[counta],
                  imgCount: 0,
                  value: &vImg);
              }
            }
          }
          if ( hitData.m_bMain )
          {
            ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
            i = (int)ActiveWorldEditDispManager;
            if ( ActiveWorldEditDispManager != nullptr )
            {
              ndxImg = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
              countb = 0;
              if ( ndxImg > 0 )
              {
                while ( (CMapDisp *)(*(int (__thiscall **)(int, int))(*(_DWORD *)i + 36))(a1: i, a2: countb) != pDisp )
                {
                  if ( ++countb >= ndxImg )
                    goto LABEL_51;
                }
                v22 = adjHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1) + v13;
                CDispMapImageFilterManager::GetImageValue(this: v51, pDisp, pFilter, ndxDisp: v22, vPaintValue: &vImg);
                v23 = ndxWid + v49;
                m_DataType = pFilter->m_DataType;
                if ( m_DataType == 1 )
                {
                  v25 = 0.0;
                  v26 = pFilter->m_pImage[v23] * pFilter->m_Scale;
                  v27 = 0.0;
                  v28 = 0.0;
                }
                else
                {
                  x = v51->m_PaintDir.x;
                  y = v51->m_PaintDir.y;
                  z = v51->m_PaintDir.z;
                  if ( v51->m_PaintType == 3 )
                  {
                    m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
                    x = m_pVerts[v22].m_SubdivNormal.x;
                    y = m_pVerts[v22].m_SubdivNormal.y;
                    z = m_pVerts[v22].m_SubdivNormal.z;
                    v23 = ndxWid + v49;
                  }
                  v33 = pFilter->m_pImage[v23] * pFilter->m_Scale;
                  v27 = y * v33;
                  v28 = z * v33;
                  v25 = 0.0;
                  v26 = v33 * x;
                }
                v34 = v26 + vImg.x;
                vImg.x = v34;
                vImg.y = vImg.y + v27;
                vImg.z = vImg.z + v28;
                if ( m_DataType == 1 )
                {
                  if ( v34 < 0.0 || (v25 = 255.0, v34 > 255.0) )
                    vImg.x = v25;
                }
                CMapDisp::Paint_SetValue(this: pDisp, iVert: v22, vPaint: &vImg);
              }
            }
          }
LABEL_51:
          v9 = v44;
          if ( ++ndxWid >= filterWid )
            break;
        }
        m_Height = filterHgt;
        k = ndxHgt;
      }
      v49 += m_Height;
      ++k;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020E30
// Name: private: void CDispMapImageFilterManager::Apply3x3SmoothFilter(class CDispMapImageFilter __near *,class CMapDisp __near *,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::Apply3x3SmoothFilter(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxVert,
        Vector *vPos)
{
  int m_Width; // esi
  int v8; // esi
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  float z; // xmm6_4
  float y; // xmm5_4
  float x; // xmm4_4
  float m_FieldDistance; // xmm7_4
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // eax
  int m_CornerCount; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // esi
  bool ImageFieldValues; // al
  float *m_pImage; // ecx
  float v26; // xmm3_4
  float v27; // xmm1_4
  int k; // esi
  bool v29; // al
  float *v30; // eax
  float v31; // xmm3_4
  float v32; // xmm1_4
  int m_DataType; // ecx
  CoreDispVert_t *v34; // eax
  int v35; // ecx
  float *v36; // eax
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  CDispMapImageFilterManager::PosHitData_t hitData; // [esp+Ch] [ebp-74h] BYREF
  Vector vNormal; // [esp+28h] [ebp-58h] BYREF
  Vector vNormals; // [esp+34h] [ebp-4Ch] BYREF
  int v44; // [esp+40h] [ebp-40h]
  int j; // [esp+44h] [ebp-3Ch]
  int filterMidWid; // [esp+48h] [ebp-38h]
  int ndxVertWid; // [esp+4Ch] [ebp-34h]
  int v48; // [esp+50h] [ebp-30h]
  int m_Height; // [esp+54h] [ebp-2Ch]
  int ndxHgt; // [esp+58h] [ebp-28h]
  int v51; // [esp+5Ch] [ebp-24h]
  int i; // [esp+60h] [ebp-20h]
  int imgHgt; // [esp+64h] [ebp-1Ch]
  int v54; // [esp+68h] [ebp-18h]
  CDispMapImageFilterManager *v55; // [esp+6Ch] [ebp-14h]
  int adjHgt; // [esp+70h] [ebp-10h]
  int v57; // [esp+74h] [ebp-Ch]
  int ndxWid; // [esp+78h] [ebp-8h]
  float dist; // [esp+7Ch] [ebp-4h] BYREF
  int count; // [esp+88h] [ebp+8h]
  int counta; // [esp+88h] [ebp+8h]
  float totalFrac; // [esp+8Ch] [ebp+Ch]
  float dists; // [esp+90h] [ebp+10h]

  v55 = this;
  m_Width = pFilter->m_Width;
  imgHgt = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  m_Height = pFilter->m_Height;
  filterMidWid = (m_Width - 1) / 2;
  v51 = m_Width;
  v8 = imgHgt;
  v9 = (m_Height - 1) / 2;
  memset(&vNormals, 0, sizeof(vNormals));
  totalFrac = 0.0;
  count = ndxVert / imgHgt;
  v10 = ndxVert % imgHgt;
  v11 = 0;
  dists = 0.0;
  ndxHgt = 0;
  ndxVertWid = v10;
  if ( m_Height <= 0 )
    goto LABEL_39;
  z = vNormal.z;
  y = vNormal.y;
  x = vNormal.x;
  m_FieldDistance = dist;
  v16 = count - v9;
  v57 = 0;
  v48 = count - v9;
  while ( 2 )
  {
    v17 = 0;
    ndxWid = 0;
    if ( v51 <= 0 )
      goto LABEL_38;
    v18 = v11 + v16;
    v19 = ndxVertWid - filterMidWid;
    adjHgt = v18;
    for ( j = ndxVertWid - filterMidWid; ; v19 = j )
    {
      v54 = v17 + v19;
      CDispMapImageFilterManager::HitData_Setup(
        this: v55,
        &hitData,
        ndxHgt: adjHgt,
        ndxWid: v17 + v19,
        imgHgt: v8,
        imgWid: v8);
      m_CornerCount = hitData.m_CornerCount;
      if ( hitData.m_CornerCount != 0 )
      {
        v21 = 0;
        i = 0;
        if ( hitData.m_CornerCount > 0 )
        {
          do
          {
            v44 = hitData.m_ndxCorners[v21];
            v22 = v44;
            switch ( v44 )
            {
              case 0:
                counta = pDisp->m_CornerNeighborCounts[0];
                break;
              case 2:
                counta = pDisp->m_CornerNeighborCounts[2];
                break;
              case 4:
                counta = pDisp->m_CornerNeighborCounts[3];
                break;
              case 6:
                counta = pDisp->m_CornerNeighborCounts[1];
                break;
              default:
                counta = -1;
                break;
            }
            v23 = 0;
            if ( counta > 0 )
            {
              while ( 1 )
              {
                ImageFieldValues = CDispMapImageFilterManager::GetImageFieldValues(
                                     this: v55,
                                     pFilter,
                                     pDisp,
                                     ndxHgt: adjHgt,
                                     ndxWid: v54,
                                     ndxImg: v22,
                                     imgCount: v23,
                                     &vNormal,
                                     &dist);
                z = vNormal.z;
                y = vNormal.y;
                x = vNormal.x;
                m_FieldDistance = dist;
                if ( ImageFieldValues )
                {
                  m_pImage = pFilter->m_pImage;
                  v26 = m_pImage[ndxWid + v57];
                  vNormals.y = (float)(vNormal.y * v26) + vNormals.y;
                  vNormals.x = (float)(vNormal.x * v26) + vNormals.x;
                  vNormals.z = (float)(vNormal.z * v26) + vNormals.z;
                  v27 = m_pImage[ndxWid + v57];
                  dists = (float)(v27 * dist) + dists;
                  totalFrac = v27 + totalFrac;
                }
                if ( ++v23 >= counta )
                  break;
                v22 = v44;
              }
              v21 = i;
              m_CornerCount = hitData.m_CornerCount;
            }
            i = ++v21;
          }
          while ( v21 < m_CornerCount );
        }
      }
      if ( hitData.m_EdgeCount != 0 )
      {
        for ( k = 0; k < hitData.m_EdgeCount; ++k )
        {
          v29 = CDispMapImageFilterManager::GetImageFieldValues(
                  this: v55,
                  pFilter,
                  pDisp,
                  ndxHgt: adjHgt,
                  ndxWid: v54,
                  ndxImg: hitData.m_ndxEdges[k],
                  imgCount: 0,
                  &vNormal,
                  &dist);
          z = vNormal.z;
          y = vNormal.y;
          x = vNormal.x;
          m_FieldDistance = dist;
          if ( v29 )
          {
            v30 = pFilter->m_pImage;
            v31 = v30[ndxWid + v57];
            vNormals.y = (float)(vNormal.y * v31) + vNormals.y;
            vNormals.x = (float)(vNormal.x * v31) + vNormals.x;
            vNormals.z = (float)(vNormal.z * v31) + vNormals.z;
            v32 = v30[ndxWid + v57];
            dists = (float)(v32 * dist) + dists;
            totalFrac = v32 + totalFrac;
          }
        }
      }
      if ( hitData.m_bMain )
      {
        m_DataType = pFilter->m_DataType;
        if ( m_DataType != 0 )
        {
          if ( m_DataType != 1 )
          {
LABEL_34:
            v35 = ndxWid;
            v36 = pFilter->m_pImage;
            v37 = v36[ndxWid + v57];
            vNormals.z = (float)(z * v37) + vNormals.z;
            vNormals.y = (float)(v37 * y) + vNormals.y;
            vNormals.x = vNormals.x + (float)(v37 * x);
            v38 = v36[ndxWid + v57];
            dists = (float)(v38 * m_FieldDistance) + dists;
            totalFrac = v38 + totalFrac;
            goto LABEL_36;
          }
          x = 0.0;
          y = 0.0;
          z = 0.0;
        }
        else
        {
          v34 = &pDisp->m_CoreDispInfo.m_pVerts[v54 + adjHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1)];
          m_FieldDistance = v34->m_FieldDistance;
          x = v34->m_FieldVector.x;
          y = v34->m_FieldVector.y;
          z = v34->m_FieldVector.z;
          dist = m_FieldDistance;
        }
        vNormal.z = z;
        vNormal.y = y;
        vNormal.x = x;
        goto LABEL_34;
      }
      v35 = ndxWid;
LABEL_36:
      v8 = imgHgt;
      v17 = v35 + 1;
      ndxWid = v17;
      if ( v17 >= v51 )
        break;
    }
    v11 = ndxHgt;
LABEL_38:
    v57 += m_Height;
    ndxHgt = ++v11;
    if ( v11 < m_Height )
    {
      v16 = v48;
      continue;
    }
    break;
  }
LABEL_39:
  VectorNormalize(vec: &vNormals);
  v39 = vNormals.y * (float)(dists / totalFrac);
  v40 = vNormals.z * (float)(dists / totalFrac);
  vPos->x = vNormals.x * (float)(dists / totalFrac);
  vPos->y = v39;
  vPos->z = v40;
}

//------------------------------------------------------------------------------
// Address: 0x10021250
// Name: private: void CDispMapImageFilterManager::ApplySmoothFilter(class CDispMapImageFilter __near *,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::ApplySmoothFilter(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxVert)
{
  CMapDisp *v4; // esi
  int v6; // ecx
  int m_AreaHeight; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  int v12; // ecx
  int v13; // eax
  CMapDisp *Image; // esi
  int AdjustedIndex; // ebx
  CoreDispVert_t *m_pVerts; // eax
  float v17; // xmm3_4
  float v18; // xmm0_4
  CMapDisp *v19; // esi
  CoreDispVert_t *v20; // eax
  float v21; // xmm4_4
  float v22; // xmm5_4
  int v23; // esi
  CoreDispVert_t *v24; // eax
  float v25; // xmm3_4
  float v26; // xmm4_4
  bool v27; // zf
  CDispMapImageFilterManager::PosHitData_t hitData; // [esp+Ch] [ebp-64h] BYREF
  Vector vPos; // [esp+28h] [ebp-48h] BYREF
  int v30; // [esp+34h] [ebp-3Ch]
  int v31; // [esp+38h] [ebp-38h] BYREF
  int orient; // [esp+3Ch] [ebp-34h] BYREF
  int areaMidWid; // [esp+40h] [ebp-30h]
  int ndxVertWid; // [esp+44h] [ebp-2Ch]
  int areaHgt; // [esp+48h] [ebp-28h]
  int ndxHgt; // [esp+4Ch] [ebp-24h]
  int v37; // [esp+50h] [ebp-20h]
  int ndxVertHgt; // [esp+54h] [ebp-1Ch]
  int adjIndex; // [esp+58h] [ebp-18h]
  int i; // [esp+5Ch] [ebp-14h]
  int ndxImg; // [esp+60h] [ebp-10h]
  int j; // [esp+64h] [ebp-Ch]
  int areaWid; // [esp+68h] [ebp-8h]
  int adjHgt; // [esp+6Ch] [ebp-4h]
  int count; // [esp+80h] [ebp+10h]
  int counta; // [esp+80h] [ebp+10h]

  v4 = pDisp;
  v6 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  m_AreaHeight = pFilter->m_AreaHeight;
  areaWid = pFilter->m_AreaWidth;
  areaHgt = m_AreaHeight;
  areaMidWid = (areaWid - 1) / 2;
  v8 = (m_AreaHeight - 1) / 2;
  v37 = v6;
  ndxVertHgt = ndxVert / v6;
  v9 = 0;
  ndxHgt = 0;
  ndxVertWid = ndxVert % v6;
  if ( m_AreaHeight > 0 )
  {
    v10 = ndxVertHgt - v8;
    v30 = ndxVertHgt - v8;
    do
    {
      if ( areaWid > 0 )
      {
        v11 = ndxVertWid - areaMidWid;
        adjHgt = v9 + v10;
        adjIndex = ndxVertWid - areaMidWid;
        ndxVertHgt = areaWid;
        do
        {
          CDispMapImageFilterManager::HitData_Setup(this, &hitData, ndxHgt: adjHgt, ndxWid: v11, imgHgt: v6, imgWid: v6);
          if ( hitData.m_CornerCount != 0 )
          {
            v12 = 0;
            for ( i = 0; v12 < hitData.m_CornerCount; i = v12 )
            {
              ndxImg = hitData.m_ndxCorners[v12];
              v13 = ndxImg;
              switch ( ndxImg )
              {
                case 0:
                  count = v4->m_CornerNeighborCounts[0];
                  break;
                case 2:
                  count = v4->m_CornerNeighborCounts[2];
                  break;
                case 4:
                  count = v4->m_CornerNeighborCounts[3];
                  break;
                case 6:
                  count = v4->m_CornerNeighborCounts[1];
                  break;
                default:
                  count = -1;
                  break;
              }
              j = 0;
              if ( count > 0 )
              {
                while ( 1 )
                {
                  Image = CDispMapImageFilterManager::GetImage(
                            this,
                            pFilter,
                            pDisp: v4,
                            ndxHgt: adjHgt,
                            ndxWid: v11,
                            ndxImg: v13,
                            imgCount: j,
                            &orient);
                  if ( Image != nullptr )
                  {
                    AdjustedIndex = CDispMapImageFilterManager::GetAdjustedIndex(
                                      this,
                                      pDisp: Image,
                                      orient,
                                      ndxHgt: adjHgt,
                                      ndxWid: v11,
                                      ndxImg);
                    CDispMapImageFilterManager::Apply3x3SmoothFilter(
                      this,
                      pFilter,
                      pDisp: Image,
                      ndxVert: AdjustedIndex,
                      &vPos);
                    m_pVerts = Image->m_CoreDispInfo.m_pVerts;
                    v17 = m_pVerts[AdjustedIndex].m_SubdivPos.y + (float)(m_pVerts[AdjustedIndex].m_FlatVert.y + vPos.y);
                    v18 = (float)(vPos.z + m_pVerts[AdjustedIndex].m_FlatVert.z) + m_pVerts[AdjustedIndex].m_SubdivPos.z;
                    vPos.x = m_pVerts[AdjustedIndex].m_SubdivPos.x
                           + (float)(m_pVerts[AdjustedIndex].m_FlatVert.x + vPos.x);
                    vPos.y = v17;
                    vPos.z = v18;
                    CMapDisp::Paint_SetValue(this: Image, iVert: AdjustedIndex, vPaint: &vPos);
                    v11 = adjIndex;
                  }
                  v4 = pDisp;
                  if ( ++j >= count )
                    break;
                  v13 = ndxImg;
                }
                v12 = i;
              }
              ++v12;
            }
          }
          if ( hitData.m_EdgeCount != 0 )
          {
            for ( counta = 0; counta < hitData.m_EdgeCount; ++counta )
            {
              v19 = CDispMapImageFilterManager::GetImage(
                      this,
                      pFilter,
                      pDisp: v4,
                      ndxHgt: adjHgt,
                      ndxWid: v11,
                      ndxImg: hitData.m_ndxEdges[counta],
                      imgCount: 0,
                      orient: &v31);
              if ( v19 != nullptr )
              {
                adjIndex = CDispMapImageFilterManager::GetAdjustedIndex(
                             this,
                             pDisp: v19,
                             orient: v31,
                             ndxHgt: adjHgt,
                             ndxWid: v11,
                             ndxImg: hitData.m_ndxEdges[counta]);
                CDispMapImageFilterManager::Apply3x3SmoothFilter(this, pFilter, pDisp: v19, ndxVert: adjIndex, &vPos);
                v20 = v19->m_CoreDispInfo.m_pVerts;
                v21 = v20[adjIndex].m_SubdivPos.y + (float)(v20[adjIndex].m_FlatVert.y + vPos.y);
                v22 = v20[adjIndex].m_SubdivPos.z + (float)(v20[adjIndex].m_FlatVert.z + vPos.z);
                vPos.x = v20[adjIndex].m_SubdivPos.x + (float)(v20[adjIndex].m_FlatVert.x + vPos.x);
                vPos.y = v21;
                vPos.z = v22;
                CMapDisp::Paint_SetValue(this: v19, iVert: adjIndex, vPaint: &vPos);
              }
              v4 = pDisp;
            }
          }
          if ( hitData.m_bMain )
          {
            v23 = v11 + adjHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1);
            CDispMapImageFilterManager::Apply3x3SmoothFilter(this, pFilter, pDisp, ndxVert: v23, &vPos);
            v24 = &pDisp->m_CoreDispInfo.m_pVerts[v23];
            v25 = v24->m_SubdivPos.y + (float)(v24->m_FlatVert.y + vPos.y);
            v26 = v24->m_SubdivPos.z + (float)(v24->m_FlatVert.z + vPos.z);
            vPos.x = v24->m_SubdivPos.x + (float)(vPos.x + v24->m_FlatVert.x);
            vPos.y = v25;
            vPos.z = v26;
            CMapDisp::Paint_SetValue(this: pDisp, iVert: v23, vPaint: &vPos);
            v4 = pDisp;
          }
          v6 = v37;
          ++v11;
          v27 = ndxVertHgt-- == 1;
          adjIndex = v11;
        }
        while ( !v27 );
        v9 = ndxHgt;
        v10 = v30;
      }
      ndxHgt = ++v9;
    }
    while ( v9 < areaHgt );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021630
// Name: private: void CDispMapImageFilterManager::ApplyEqualFilter(class CDispMapImageFilter __near *,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::ApplyEqualFilter(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxVert)
{
  int m_Height; // ebx
  int m_Width; // edx
  int v8; // eax
  int v9; // ecx
  int k; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  bool v16; // zf
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  int m_DataType; // ecx
  int v22; // ebx
  CoreDispVert_t *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float x; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  CoreDispVert_t *m_pVerts; // edx
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  CDispMapImageFilterManager::PosHitData_t hitData; // [esp+Ch] [ebp-74h] BYREF
  Vector vFilterDir; // [esp+28h] [ebp-58h] BYREF
  Vector vFilter; // [esp+34h] [ebp-4Ch] BYREF
  Vector vImg; // [esp+40h] [ebp-40h] BYREF
  int filterHgt; // [esp+4Ch] [ebp-34h]
  int m; // [esp+50h] [ebp-30h]
  int filterMidWid; // [esp+54h] [ebp-2Ch]
  int ndxVertWid; // [esp+58h] [ebp-28h]
  int v46; // [esp+5Ch] [ebp-24h]
  int v47; // [esp+60h] [ebp-20h]
  int i; // [esp+64h] [ebp-1Ch]
  int ndxHgt; // [esp+68h] [ebp-18h]
  int filterWid; // [esp+6Ch] [ebp-14h]
  int ndxImg; // [esp+70h] [ebp-10h]
  int v52; // [esp+74h] [ebp-Ch]
  int j; // [esp+78h] [ebp-8h]
  CDispMapImageFilterManager *v54; // [esp+7Ch] [ebp-4h]
  int ndxWid; // [esp+88h] [ebp+8h]
  int count; // [esp+8Ch] [ebp+Ch]
  int counta; // [esp+8Ch] [ebp+Ch]
  int adjHgt; // [esp+90h] [ebp+10h]

  m_Height = pFilter->m_Height;
  m_Width = pFilter->m_Width;
  v54 = this;
  v8 = 1 << pDisp->m_CoreDispInfo.m_Power;
  filterWid = m_Width;
  filterHgt = m_Height;
  v9 = v8 + 1;
  filterMidWid = (m_Width - 1) / 2;
  v47 = v8 + 1;
  ndxHgt = 0;
  ndxVertWid = ndxVert % (v8 + 1);
  if ( m_Height > 0 )
  {
    v52 = 0;
    v46 = ndxVert / (v8 + 1) - (m_Height - 1) / 2;
    for ( k = ndxHgt; k < m_Height; ndxHgt = k )
    {
      ndxWid = 0;
      if ( filterWid > 0 )
      {
        v11 = k + v46;
        v12 = ndxVertWid - filterMidWid;
        adjHgt = v11;
        for ( m = ndxVertWid - filterMidWid; ; v12 = m )
        {
          v13 = v12 + ndxWid;
          CDispMapImageFilterManager::HitData_Setup(
            this: v54,
            &hitData,
            ndxHgt: adjHgt,
            ndxWid: v12 + ndxWid,
            imgHgt: v9,
            imgWid: v9);
          if ( hitData.m_CornerCount != 0 )
          {
            v14 = 0;
            for ( i = 0; v14 < hitData.m_CornerCount; i = v14 )
            {
              ndxImg = hitData.m_ndxCorners[v14];
              v15 = ndxImg;
              switch ( ndxImg )
              {
                case 0:
                  count = pDisp->m_CornerNeighborCounts[0];
                  break;
                case 2:
                  count = pDisp->m_CornerNeighborCounts[2];
                  break;
                case 4:
                  count = pDisp->m_CornerNeighborCounts[3];
                  break;
                case 6:
                  count = pDisp->m_CornerNeighborCounts[1];
                  break;
                default:
                  count = -1;
                  break;
              }
              j = 0;
              if ( count > 0 )
              {
                while ( 1 )
                {
                  if ( CDispMapImageFilterManager::GetImageFlatSubdivValues(
                         this: v54,
                         pFilter,
                         pDisp,
                         ndxHgt: adjHgt,
                         ndxWid: v13,
                         ndxImg: v15,
                         imgCount: j,
                         value: &vImg)
                    && pFilter->m_pImage[ndxWid + v52] != -99999.0 )
                  {
                    CDispMapImageFilterManager::GetFilterVector(
                      this: v54,
                      pFilter,
                      pDisp,
                      ndxHgt: adjHgt,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: j,
                      ndxFilter: ndxWid + v52,
                      vFilterDir: &vFilter);
                    v16 = pFilter->m_DataType == 1;
                    v17 = vFilter.x + vImg.x;
                    vImg.y = vImg.y + vFilter.y;
                    vImg.x = vFilter.x + vImg.x;
                    vImg.z = vFilter.z + vImg.z;
                    if ( v16 )
                    {
                      v18 = 0.0;
                      if ( v17 < 0.0 || (v18 = 255.0, v17 > 255.0) )
                        vImg.x = v18;
                    }
                    CDispMapImageFilterManager::SetImageValues(
                      this: v54,
                      pFilter,
                      pDisp,
                      ndxHgt: adjHgt,
                      ndxWid: v13,
                      ndxImg,
                      imgCount: j,
                      value: &vImg);
                  }
                  if ( ++j >= count )
                    break;
                  v15 = ndxImg;
                }
                v14 = i;
              }
              ++v14;
            }
          }
          if ( hitData.m_EdgeCount != 0 )
          {
            for ( counta = 0; counta < hitData.m_EdgeCount; ++counta )
            {
              if ( CDispMapImageFilterManager::GetImageFlatSubdivValues(
                     this: v54,
                     pFilter,
                     pDisp,
                     ndxHgt: adjHgt,
                     ndxWid: v13,
                     ndxImg: hitData.m_ndxEdges[counta],
                     imgCount: 0,
                     value: &vImg)
                && pFilter->m_pImage[ndxWid + v52] != -99999.0 )
              {
                CDispMapImageFilterManager::GetFilterVector(
                  this: v54,
                  pFilter,
                  pDisp,
                  ndxHgt: adjHgt,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[counta],
                  imgCount: 0,
                  ndxFilter: ndxWid + v52,
                  &vFilterDir);
                v16 = pFilter->m_DataType == 1;
                v19 = vFilterDir.x + vImg.x;
                vImg.y = vFilterDir.y + vImg.y;
                vImg.x = vFilterDir.x + vImg.x;
                vImg.z = vFilterDir.z + vImg.z;
                if ( v16 )
                {
                  v20 = 0.0;
                  if ( v19 < 0.0 || (v20 = 255.0, v19 > 255.0) )
                    vImg.x = v20;
                }
                CDispMapImageFilterManager::SetImageValues(
                  this: v54,
                  pFilter,
                  pDisp,
                  ndxHgt: adjHgt,
                  ndxWid: v13,
                  ndxImg: hitData.m_ndxEdges[counta],
                  imgCount: 0,
                  value: &vImg);
              }
            }
          }
          if ( hitData.m_bMain )
          {
            m_DataType = pFilter->m_DataType;
            v22 = adjHgt * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1) + v13;
            if ( m_DataType != 0 )
            {
              if ( m_DataType == 1 )
                memset(&vImg, 0, sizeof(vImg));
            }
            else
            {
              v23 = &pDisp->m_CoreDispInfo.m_pVerts[v22];
              vImg = v23->m_FlatVert;
              v24 = v23->m_SubdivPos.y + vImg.y;
              v25 = v23->m_SubdivPos.z + vImg.z;
              vImg.x = v23->m_SubdivPos.x + vImg.x;
              vImg.y = v24;
              vImg.z = v25;
            }
            v26 = pFilter->m_pImage[ndxWid + v52];
            if ( v26 != -99999.0 )
            {
              if ( m_DataType == 1 )
              {
                v27 = pFilter->m_Scale * v26;
                v28 = 0.0;
                v29 = 0.0;
              }
              else
              {
                x = v54->m_PaintDir.x;
                y = v54->m_PaintDir.y;
                z = v54->m_PaintDir.z;
                if ( v54->m_PaintType == 3 )
                {
                  m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
                  x = m_pVerts[v22].m_SubdivNormal.x;
                  y = m_pVerts[v22].m_SubdivNormal.y;
                  z = m_pVerts[v22].m_SubdivNormal.z;
                }
                v34 = pFilter->m_Scale * v26;
                v35 = y * v34;
                v36 = z * v34;
                v27 = v34 * x;
                v28 = v35;
                v29 = v36;
              }
              v37 = v27 + vImg.x;
              vImg.x = v37;
              vImg.y = v28 + vImg.y;
              vImg.z = v29 + vImg.z;
              if ( m_DataType == 1 )
              {
                if ( v37 >= 0.0 )
                {
                  if ( v37 > 255.0 )
                    vImg.x = 255.0;
                }
                else
                {
                  vImg.x = 0.0;
                }
              }
              CMapDisp::Paint_SetValue(this: pDisp, iVert: v22, vPaint: &vImg);
            }
          }
          v9 = v47;
          if ( ++ndxWid >= filterWid )
            break;
        }
        k = ndxHgt;
        m_Height = filterHgt;
      }
      v52 += m_Height;
      ++k;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021B50
// Name: private: void CDispMapImageFilterManager::ApplyAt(class CDispMapImageFilter __near *,class CMapDisp __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::ApplyAt(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int ndxVert)
{
  switch ( pFilter->m_Type )
  {
    case 0u:
      CDispMapImageFilterManager::ApplyAddFilter(this, pFilter, pDisp, iVert: ndxVert);
      break;
    case 1u:
      CDispMapImageFilterManager::ApplyEqualFilter(this, pFilter, pDisp, ndxVert);
      break;
    case 2u:
      CDispMapImageFilterManager::ApplySmoothFilter(this, pFilter, pDisp, ndxVert);
      break;
    case 3u:
      CDispMapImageFilterManager::ApplyMultFilter(this, pFilter, pDisp, ndxVert);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021BC0
// Name: public: CDispMapImageFilter::CDispMapImageFilter(void)
// Source: json
//------------------------------------------------------------------------------
CDispMapImageFilter *__thiscall CDispMapImageFilter::CDispMapImageFilter(CDispMapImageFilter *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_Name; // ebx
  ATL::IAtlStringMgr *StringManager; // eax

  p_m_Name = &this->m_Name;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  p_m_Name->m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->m_Type = -1;
  this->m_DataType = -1;
  this->m_Height = 0;
  this->m_Width = 0;
  this->m_pImage = nullptr;
  this->m_Scale = 1.0;
  this->m_AreaHeight = 0;
  this->m_AreaWidth = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021C60
// Name: private: static int CDispMapImageFilter::GetFilterType(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDispMapImageFilter::GetFilterType(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > type)
{
  char *v1; // eax
  char *v3; // eax
  char *v4; // eax

  if ( _mbscmp(s1: (const unsigned __int8 *)type.m_pszData, s2: "FILTER_ADD") != 0 )
  {
    if ( _mbscmp(s1: (const unsigned __int8 *)type.m_pszData, s2: "FILTER_MULT") != 0 )
    {
      if ( _mbscmp(s1: (const unsigned __int8 *)type.m_pszData, s2: "FILTER_CONVATTEN") != 0 )
      {
        if ( _mbscmp(s1: (const unsigned __int8 *)type.m_pszData, s2: "FILTER_EQUAL") != 0 )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &type);
          return -1;
        }
        else
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &type);
          return 1;
        }
      }
      else
      {
        v4 = type.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)type.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
        return 2;
      }
    }
    else
    {
      v3 = type.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)type.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
      return 3;
    }
  }
  else
  {
    v1 = type.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)type.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v1 + 4))(a1: v1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021DE0
// Name: public: class CDispMapImageFilter __near * CDispMapImageFilterManager::Create(void)
// Source: json
//------------------------------------------------------------------------------
CDispMapImageFilter *__thiscall CDispMapImageFilterManager::Create(CDispMapImageFilterManager *this)
{
  CDispMapImageFilter *v2; // eax
  CDispMapImageFilter *result; // eax
  int m_FilterCount; // ecx

  v2 = (CDispMapImageFilter *)operator new(nSize: 0x24u);
  if ( v2 != nullptr )
    result = CDispMapImageFilter::CDispMapImageFilter(this: v2);
  else
    result = nullptr;
  if ( result != nullptr )
  {
    m_FilterCount = this->m_FilterCount;
    if ( m_FilterCount < 64 )
    {
      this->m_pFilterList[m_FilterCount] = result;
      ++this->m_FilterCount;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021E60
// Name: public: bool CDispMapImageFilterManager::Apply(class CDispMapImageFilter __near *,class CMapDisp __near *,int,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispMapImageFilterManager::Apply(
        CDispMapImageFilterManager *this,
        CDispMapImageFilter *pFilter,
        CMapDisp *pDisp,
        int paintDirType,
        const Vector *vPaintDir,
        bool bSew)
{
  int m_HitTexelIndex; // edi
  char result; // al

  m_HitTexelIndex = pDisp->m_HitTexelIndex;
  if ( m_HitTexelIndex == -1 )
    return 0;
  result = CDispMapImageFilterManager::PreApply(this, pFilter, nPaintDirType: paintDirType, vecPaintDir: vPaintDir);
  if ( result != 0 )
  {
    CDispMapImageFilterManager::ApplyAt(this, pFilter, pDisp, ndxVert: m_HitTexelIndex);
    return CDispMapImageFilterManager::PostApply(this, bSew);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021EC0
// Name: public: void CDispMapImageFilterManager::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispMapImageFilterManager::Destroy(CDispMapImageFilterManager *this)
{
  int m_FilterCount; // eax
  int v2; // edi
  CDispMapImageFilter **m_pFilterList; // ebx
  CDispMapImageFilter *v4; // esi
  volatile signed __int32 *v5; // eax
  CDispMapImageFilterManager *v6; // [esp+8h] [ebp-10h]

  m_FilterCount = this->m_FilterCount;
  v2 = 0;
  v6 = this;
  if ( m_FilterCount > 0 )
  {
    m_pFilterList = this->m_pFilterList;
    do
    {
      if ( v2 >= 0 && v2 < m_FilterCount )
      {
        v4 = *m_pFilterList;
        if ( *m_pFilterList != nullptr )
        {
          if ( v4->m_pImage != nullptr )
          {
            operator delete(p: v4->m_pImage);
            v4->m_pImage = nullptr;
          }
          v5 = (volatile signed __int32 *)(v4->m_Name.m_pszData - 16);
          if ( _InterlockedDecrement(v5 + 3) <= 0 )
            (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(a1: v5);
          operator delete(p: v4);
          this = v6;
        }
      }
      m_FilterCount = this->m_FilterCount;
      ++v2;
      ++m_pFilterList;
    }
    while ( v2 < m_FilterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021F80
// Name: private: static enum ChunkFileResult_t CDispMapImageFilter::LoadFilterKeyCallback(char const __near *,char const __near *,class CDispMapImageFilter __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CDispMapImageFilter::LoadFilterKeyCallback(
        const char *szKey,
        const char *szValue,
        CDispMapImageFilter *pFilter)
{
  int m_Height; // esi
  int m_Width; // esi
  int v6; // ecx
  ATL::CStringData *v7; // eax
  char *v8; // eax
  _DWORD v9[4]; // [esp-4h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFilterType; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+18h] [ebp-4h]

  if ( _V_stricmp(s1: szKey, s2: "Height") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "Width") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "FilterType") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "IconName") == 0 )
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
            this: &pFilter->m_Name,
            pszSrc: szValue);
      }
      else
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strFilterType,
          pszSrc: szValue);
        v11 = 0;
        v9[0] = v6;
        v9[3] = v9;
        v9[2] = v9;
        v7 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strFilterType.m_pszData - 1);
        LOBYTE(v11) = 0;
        pFilter->m_Type = CDispMapImageFilter::GetFilterType(type: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)&v7[1]);
        v11 = -1;
        v8 = strFilterType.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)strFilterType.m_pszData - 1) <= 0 )
        {
          (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
          return ChunkFile_Ok;
        }
      }
    }
    else
    {
      CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pFilter->m_Width);
      m_Width = pFilter->m_Width;
      if ( m_Width < 1 || m_Width > 9 )
      {
        Msg(type: 1, fmt: "Filter width is out of range - %d\n", m_Width);
        return ChunkFile_Ok;
      }
    }
  }
  else
  {
    CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pFilter->m_Height);
    m_Height = pFilter->m_Height;
    if ( m_Height < 1 || m_Height > 9 )
    {
      Msg(type: 1, fmt: "Filter height is out of range - %d\n", m_Height);
      return ChunkFile_Ok;
    }
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10022110
// Name: public: enum ChunkFileResult_t CDispMapImageFilter::LoadFilter(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CDispMapImageFilter::LoadFilter(CDispMapImageFilter *this, CChunkFile *pFile)
{
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  bInitMemory = true;
  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v6 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "Image",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CDispMapImageFilter::LoadImageCallback,
    pData: this);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CDispMapImageFilter::LoadFilterKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  v6 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x100F6D90
// Name: private: bool CDispMapImageFilterManager::PostApply(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispMapImageFilterManager::PostApply(CDispMapImageFilterManager *this, bool bSew)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // esi
  int v4; // ebx
  int i; // edi
  CMapDisp *v6; // eax

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  v4 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
  for ( i = 0; i < v4; ++i )
  {
    v6 = ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: i);
    if ( v6 != nullptr )
      CMapDisp::Paint_Update(this: v6, bSplit: false);
  }
  if ( bSew )
    FaceListSewEdges();
  return 1;
}
