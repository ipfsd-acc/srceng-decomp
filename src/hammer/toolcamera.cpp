// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolcamera.cpp
// Functions: 27
// ============================================================

#include "hammer\toolcamera.h"

//------------------------------------------------------------------------------
// Address: 0x101581C0
// Name: protected: virtual bool Camera3D::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::UpdateTranslation(Camera3D *this, const Vector *vUpdate, char uFlags)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float x; // xmm0_4
  float v8; // xmm4_4
  float *p_x; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  Vector vNewPos; // [esp+Ch] [ebp-Ch] BYREF

  v4 = this->m_MoveCamera.position[1].x - this->m_MoveCamera.position[0].x;
  v5 = this->m_MoveCamera.position[1].y - this->m_MoveCamera.position[0].y;
  v6 = this->m_MoveCamera.position[1].z - this->m_MoveCamera.position[0].z;
  x = vUpdate->x + this->m_vOrgPos.x;
  vNewPos.y = this->m_vOrgPos.y + vUpdate->y;
  v8 = this->m_vOrgPos.z + vUpdate->z;
  vNewPos.x = x;
  vNewPos.z = v8;
  if ( (uFlags & 4) != 0 )
  {
    CMapDoc::Snap(this: this->m_pDocument, pt: &vNewPos, nFlags: uFlags);
    x = vNewPos.x;
  }
  p_x = &this->m_MoveCamera.position[this->m_nMovePositionIndex].x;
  *p_x = x;
  p_x[1] = vNewPos.y;
  p_x[2] = vNewPos.z;
  if ( (uFlags & 0x40) != 0 )
  {
    v10 = vNewPos.x + v4;
    v11 = vNewPos.y + v5;
    v12 = vNewPos.z + v6;
    v13 = &this->m_MoveCamera.position[(this->m_nMovePositionIndex + 1) % 2].x;
    *v13 = v10;
    v13[1] = v11;
    v13[2] = v12;
  }
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158300
// Name: private: static enum ChunkFileResult_t Camera3D::LoadCameraKeyCallback(char const __near *,char const __near *,struct CAMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl Camera3D::LoadCameraKeyCallback(const char *szKey, const char *szValue, CAMSTRUCT *pCam)
{
  if ( _V_stricmp(s1: szKey, s2: "look") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "position") == 0 )
      CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: pCam->position);
    return ChunkFile_Ok;
  }
  else
  {
    CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pCam->position[1]);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158360
// Name: private: static enum ChunkFileResult_t Camera3D::LoadCamerasKeyCallback(char const __near *,char const __near *,class Camera3D __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl Camera3D::LoadCamerasKeyCallback(const char *szKey, const char *szValue, Camera3D *pCameras)
{
  if ( _V_stricmp(s1: szKey, s2: "activecamera") == 0 )
    pCameras->m_iActiveCamera = atoi(nptr: szValue);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x101583A0
// Name: public: virtual bool Camera3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall Camera3D::OnMouseMove2D(Camera3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  CMapView *v5; // edi
  unsigned int (__thiscall *GetConstraints)(struct Camera3D *, unsigned int); // edx
  bool v9; // zf
  unsigned int v10; // eax
  char string[32]; // [esp+18h] [ebp-94h] BYREF
  __int128 szBuf_100; // [esp+9Ch] [ebp-10h] OVERLAPPED BYREF
  int szBuf_124; // [esp+B4h] [ebp+8h]

  v5 = &pView->CMapView;
  if ( pView->GetMapDoc(this: &pView->CMapView) != nullptr )
  {
    GetConstraints = this->GetConstraints;
    HIDWORD(szBuf_100) = 2;
    szBuf_124 = GetConstraints(this, a2: nFlags);
    CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
    v5->ClientToWorld(this: v5, a2: (Vector *)&szBuf_100, a3: vPoint);
    CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&szBuf_100, nFlags: szBuf_124);
    sprintf(
      string: &string[4],
      format: " @%.0f, %.0f ",
      *((float *)&szBuf_100 + pView->axHorz),
      *((float *)&szBuf_100 + pView->axVert));
    SetStatusText(nIndex: 2, pszText: &string[4]);
    if ( this->IsTranslating(this) )
    {
      Tool3D::UpdateTranslation(this, pView: v5, vPoint, nFlags: szBuf_124);
      return 1;
    }
    if ( this->IsEmpty(this) || (v9 = this->HitTest(this, a2: v5, a3: vPoint, a4: true) == 0, v10 = 6, v9) )
      v10 = HIDWORD(szBuf_100);
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: v10);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101584D0
// Name: public: virtual bool Camera3D::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnLMouseDown3D(
        Camera3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView3D::EnableRotating(this: pView, bEnable: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101584F0
// Name: public: virtual bool Camera3D::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnLMouseUp3D(Camera3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  CMapView3D::EnableRotating(this: pView, bEnable: false);
  CMapView3D::UpdateCameraVariables(this: pView);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158510
// Name: public: virtual bool Camera3D::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnRMouseDown3D(
        Camera3D *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView3D::EnableStrafing(this: pView, bEnable: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158530
// Name: public: virtual bool Camera3D::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnRMouseUp3D(Camera3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  CMapView3D::EnableStrafing(this: pView, bEnable: false);
  CMapView3D::UpdateCameraVariables(this: pView);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101585F0
// Name: public: virtual bool Camera3D::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Camera3D::IsEmpty(Camera3D *this)
{
  return this->Cameras.m_Size == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10158600
// Name: protected: virtual int Camera3D::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Camera3D::HitTest(Camera3D *this, CMapView *pView, const Vector2D *ptClient, bool bTestHandles)
{
  int v4; // ebx
  int v6; // esi
  int i; // [esp+Ch] [ebp-8h]
  unsigned __int16 j; // [esp+10h] [ebp-4h]

  v4 = 0;
  i = 0;
  if ( this->Cameras.m_Size > 0 )
  {
    while ( 2 )
    {
      v6 = 0;
      j = 0;
      do
      {
        if ( Tool3D::HitRect(
               this,
               pView,
               vPoint: ptClient,
               vCenter: &this->Cameras.m_Memory.m_pMemory[v4].position[v6],
               extent: 4) )
        {
          return (unsigned __int16)(i + 1) | (j << 16);
        }
        ++j;
        ++v6;
      }
      while ( v6 < 2 );
      ++v4;
      if ( ++i < this->Cameras.m_Size )
        continue;
      break;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10158680
// Name: public: void Camera3D::GetCameraPos(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::GetCameraPos(Camera3D *this, Vector *vViewPos, Vector *vLookAt)
{
  int m_iActiveCamera; // eax
  CAMSTRUCT *m_pMemory; // edx
  int v5; // eax
  double x; // st7
  CAMSTRUCT *v7; // eax
  int v8; // eax
  CAMSTRUCT *v9; // ecx
  double v10; // st7
  int v11; // eax

  m_iActiveCamera = this->m_iActiveCamera;
  if ( m_iActiveCamera < 0 || m_iActiveCamera > this->Cameras.m_Size )
  {
    vViewPos->x = 0.0;
    vViewPos->y = 0.0;
    vViewPos->z = 0.0;
    vLookAt->x = 0.0;
    vLookAt->y = 0.0;
    vLookAt->z = 0.0;
  }
  else
  {
    m_pMemory = this->Cameras.m_Memory.m_pMemory;
    v5 = m_iActiveCamera;
    x = m_pMemory[v5].position[0].x;
    v7 = &m_pMemory[v5];
    vViewPos->x = x;
    vViewPos->y = v7->position[0].y;
    vViewPos->z = v7->position[0].z;
    v8 = this->m_iActiveCamera;
    v9 = this->Cameras.m_Memory.m_pMemory;
    v8 *= 3;
    v10 = *(&v9->position[1].x + 2 * v8);
    v11 = (int)&v9->position[1] + 8 * v8;
    vLookAt->x = v10;
    vLookAt->y = *(float *)(v11 + 4);
    vLookAt->z = *(float *)(v11 + 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158710
// Name: public: virtual void Camera3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::RenderTool2D(Camera3D *this, CRender2D *pRender)
{
  CAMSTRUCT *p_m_MoveCamera; // edi
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  i = 0;
  if ( this->Cameras.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      p_m_MoveCamera = &this->Cameras.m_Memory.m_pMemory[v4];
      if ( this->IsTranslating(this) && i == this->m_iActiveCamera )
        p_m_MoveCamera = &this->m_MoveCamera;
      if ( i == this->m_iActiveCamera )
        CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
      else
        CRender::SetDrawColor(this: pRender, r: 0, g: 0xFFu, b: 0xFFu);
      CRender::DrawLine(
        this: pRender,
        a2: (int)p_m_MoveCamera,
        a3: (int)pRender,
        vStart: p_m_MoveCamera->position,
        vEnd: &p_m_MoveCamera->position[1]);
      CRender::SetHandleStyle(this: pRender, size: 4, type: 2);
      CRender::SetHandleColor(this: pRender, r: 0, g: 0xFFu, b: 0xFFu);
      CRender::DrawHandle(this: pRender, vCenter: p_m_MoveCamera->position, vOffset: nullptr);
      ++v4;
      ++i;
    }
    while ( i < this->Cameras.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101587E0
// Name: public: void Camera3D::UpdateActiveCamera(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge Camera3D::UpdateActiveCamera(Camera3D *this@<ecx>, int a2@<ebp>, Vector *vViewPos, Vector *vDir)
{
  int m_iActiveCamera; // eax
  CAMSTRUCT *m_pMemory; // ecx
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *position; // eax
  float v12; // xmm2_4
  __int128 v13; // xmm0
  float z; // xmm0_4
  CMapDoc *m_pDocument; // ecx
  _BYTE v16[20]; // [esp-Ch] [ebp-2Ch] OVERLAPPED BYREF
  int v17; // [esp+14h] [ebp-Ch]
  void *v18; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  m_iActiveCamera = this->m_iActiveCamera;
  if ( m_iActiveCamera >= 0 && m_iActiveCamera <= this->Cameras.m_Size )
  {
    m_pMemory = this->Cameras.m_Memory.m_pMemory;
    v7 = m_iActiveCamera;
    v8 = m_pMemory[v7].position[0].x - m_pMemory[v7].position[1].x;
    v9 = m_pMemory[v7].position[0].y - m_pMemory[v7].position[1].y;
    v10 = m_pMemory[v7].position[0].z - m_pMemory[v7].position[1].z;
    position = m_pMemory[v7].position;
    v12 = (float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v8 * v8);
    v13 = 0;
    *(float *)&v13 = fsqrt(v12);
    *(_OWORD *)v16 = v13;
    if ( *(float *)&v13 < 1.0 )
      LODWORD(v13) = 1065353216;
    *position = *vViewPos;
    position[1].x = (float)(vDir->x * *(float *)&v13) + position->x;
    position[1].y = (float)(vDir->y * *(float *)&v13) + position->y;
    position[1].z = (float)(vDir->z * *(float *)&v13) + position->z;
    if ( this->m_bActiveTool )
    {
      if ( Options.view2d.bCenteroncamera != 0 )
      {
        *(float *)&v16[8] = vViewPos->x;
        *(float *)&v16[12] = vViewPos->y;
        z = vViewPos->z;
        m_pDocument = this->m_pDocument;
        *(_WORD *)v16 = 2;
        *(float *)&v16[16] = z;
        CMapDoc::SetView2dInfo(this: m_pDocument, vi: (VIEW2DINFO *)v16);
      }
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158920
// Name: public: virtual enum ChunkFileResult_t Camera3D::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall Camera3D::SaveVMF(Camera3D *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  const char *v4; // eax
  ChunkFileResult_t result; // eax
  int v7; // ebx
  int i; // [esp+14h] [ebp+8h]

  v4 = this->GetVMFChunkName(this);
  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: v4);
  v7 = 0;
  if ( result == ChunkFile_Ok )
  {
    result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "activecamera", nValue: this->m_iActiveCamera);
    if ( result == ChunkFile_Ok )
    {
      i = 0;
      if ( this->Cameras.m_Size <= 0 )
      {
        return CChunkFile::EndChunk(this: pFile);
      }
      else
      {
        while ( 1 )
        {
          result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "camera");
          if ( result != ChunkFile_Ok )
            break;
          result = CChunkFile::WriteKeyValueVector3(
                     this: pFile,
                     pszKey: "position",
                     vec: this->Cameras.m_Memory.m_pMemory[v7].position);
          if ( result != ChunkFile_Ok )
            break;
          result = CChunkFile::WriteKeyValueVector3(
                     this: pFile,
                     pszKey: "look",
                     vec: &this->Cameras.m_Memory.m_pMemory[v7].position[1]);
          if ( result != ChunkFile_Ok )
            break;
          result = CChunkFile::EndChunk(this: pFile);
          if ( result != ChunkFile_Ok )
            break;
          ++v7;
          if ( ++i >= this->Cameras.m_Size )
            return CChunkFile::EndChunk(this: pFile);
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101589E0
// Name: public: virtual bool Camera3D::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge Camera3D::OnLMouseUp2D@<al>(
        Camera3D *this@<ecx>,
        int a2@<edi>,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  Vector viewPos; // [esp+4h] [ebp-18h] BYREF
  Vector lookAt; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  ReleaseCapture();
  if ( this->IsTranslating(this) )
  {
    this->FinishTranslation(this, a2: true);
    Camera3D::GetCameraPos(this, vViewPos: &viewPos, vLookAt: &lookAt);
    CMapDoc::UpdateAllCameras(
      this: this->m_pDocument,
      a2,
      vecViewPos: &viewPos,
      vecLookAt: (__POSITION *)&lookAt,
      fZoom: nullptr);
  }
  CMapDoc::UpdateStatusbar(this: this->m_pDocument, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158A40
// Name: public: virtual void Camera3D::SetEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::SetEmpty(Camera3D *this)
{
  this->Cameras.m_Size = 0;
  this->m_iActiveCamera = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10158A60
// Name: private: void Camera3D::EnsureMaxCameras(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::EnsureMaxCameras(Camera3D *this)
{
  int nMaxCameras; // eax
  int v3; // edi

  nMaxCameras = Options.general.nMaxCameras;
  if ( Options.general.nMaxCameras <= 1 )
    nMaxCameras = 1;
  v3 = this->Cameras.m_Size - nMaxCameras;
  if ( v3 > 0 )
  {
    this->m_iActiveCamera = this->m_iActiveCamera - v3 <= 0 ? 0 : this->m_iActiveCamera - v3;
    do
    {
      --v3;
      if ( this->Cameras.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->Cameras.m_Memory.m_pMemory,
          src: &this->Cameras.m_Memory.m_pMemory[1],
          count: 24 * (this->Cameras.m_Size - 1));
      --this->Cameras.m_Size;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158AD0
// Name: private: void Camera3D::DeleteActiveCamera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::DeleteActiveCamera(Camera3D *this)
{
  int m_iActiveCamera; // ecx
  int v3; // eax

  m_iActiveCamera = this->m_iActiveCamera;
  if ( m_iActiveCamera >= 0 && m_iActiveCamera <= this->Cameras.m_Size )
  {
    if ( this->Cameras.m_Size - m_iActiveCamera - 1 > 0 )
      _V_memmove(
        dest: &this->Cameras.m_Memory.m_pMemory[m_iActiveCamera],
        src: &this->Cameras.m_Memory.m_pMemory[m_iActiveCamera + 1],
        count: 24 * (this->Cameras.m_Size - m_iActiveCamera - 1));
    v3 = --this->Cameras.m_Size;
    if ( this->m_iActiveCamera >= v3 )
      this->m_iActiveCamera = v3 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158B30
// Name: public: virtual bool Camera3D::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnKeyDown2D(
        Camera3D *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMapDoc *v7; // ebx
  int m_Size; // eax
  Vector viewPos; // [esp+8h] [ebp-18h] BYREF
  Vector lookAt; // [esp+14h] [ebp-Ch] BYREF

  if ( nChar == 46 || nChar == 34 || nChar == 33 )
  {
    v7 = pView->GetMapDoc(this: &pView->CMapView);
    if ( nChar == 46 )
    {
      Camera3D::DeleteActiveCamera(this);
    }
    else
    {
      m_Size = this->Cameras.m_Size;
      if ( nChar == 34 )
      {
        if ( m_Size != 0 )
        {
          if ( ++this->m_iActiveCamera >= m_Size )
            this->m_iActiveCamera = 0;
          goto LABEL_17;
        }
      }
      else if ( m_Size != 0 )
      {
        if ( --this->m_iActiveCamera < 0 )
          this->m_iActiveCamera = m_Size - 1;
        goto LABEL_17;
      }
      this->m_iActiveCamera = -1;
    }
LABEL_17:
    Camera3D::GetCameraPos(this, vViewPos: &viewPos, vLookAt: &lookAt);
    CMapDoc::UpdateAllCameras(
      this: v7,
      a2: nChar,
      vecViewPos: &viewPos,
      vecLookAt: (__POSITION *)&lookAt,
      fZoom: nullptr);
    return 1;
  }
  if ( nChar != 27 )
    return 0;
  CToolManager::SetTool(this: this->m_pDocument->m_pToolManager, eNewTool: TOOL_POINTER);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158DA0
// Name: public: Camera3D::Camera3D(void)
// Source: json
//------------------------------------------------------------------------------
Camera3D *__thiscall Camera3D::Camera3D(Camera3D *this)
{
  CAMSTRUCT *m_pMemory; // ecx

  Tool3D::Tool3D(this);
  this->__vftable = (Camera3D_vtbl *)&Camera3D::`vftable';
  this->Cameras.m_Memory.m_pMemory = nullptr;
  this->Cameras.m_Memory.m_nAllocationCount = 0;
  this->Cameras.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->Cameras.m_Memory.m_pMemory;
  this->Cameras.m_Size = 0;
  this->Cameras.m_pElements = m_pMemory;
  CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::EnsureCapacity(
    this: (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&this->Cameras,
    num: 16);
  this->Cameras.m_Size = 0;
  this->m_iActiveCamera = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10158E20
// Name: public: virtual char const __near * Camera3D::GetVMFChunkName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall Camera3D::GetVMFChunkName(Camera3D *this)
{
  return "cameras";
}

//------------------------------------------------------------------------------
// Address: 0x10158E30
// Name: public: virtual Camera3D::~Camera3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::~Camera3D(Camera3D *this)
{
  CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int> > *p_Cameras; // esi

  p_Cameras = &this->Cameras;
  this->Cameras.m_Size = 0;
  if ( this->Cameras.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Cameras->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Cameras->m_Memory.m_pMemory);
      p_Cameras->m_Memory.m_pMemory = nullptr;
    }
    p_Cameras->m_Memory.m_nAllocationCount = 0;
  }
  p_Cameras->m_pElements = p_Cameras->m_Memory.m_pMemory;
  if ( p_Cameras->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Cameras->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Cameras->m_Memory.m_pMemory);
      p_Cameras->m_Memory.m_pMemory = nullptr;
    }
    p_Cameras->m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (Camera3D_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10158EF0
// Name: protected: virtual void Camera3D::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::FinishTranslation(Camera3D *this, bool bSave)
{
  CAMSTRUCT *m_pMemory; // ecx
  int m_iActiveCamera; // eax
  float *v5; // eax

  if ( bSave )
  {
    if ( this->m_iActiveCamera == this->Cameras.m_Size )
    {
      CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::InsertBefore(this: &this->Cameras, elem: this->Cameras.m_Size);
      Camera3D::EnsureMaxCameras(this);
    }
    m_pMemory = this->Cameras.m_Memory.m_pMemory;
    m_iActiveCamera = this->m_iActiveCamera;
    m_pMemory[m_iActiveCamera].position[0].x = this->m_MoveCamera.position[0].x;
    v5 = (float *)&m_pMemory[m_iActiveCamera];
    v5[1] = this->m_MoveCamera.position[0].y;
    v5[2] = this->m_MoveCamera.position[0].z;
    v5[3] = this->m_MoveCamera.position[1].x;
    v5[4] = this->m_MoveCamera.position[1].y;
    v5[5] = this->m_MoveCamera.position[1].z;
  }
  Tool3D::FinishTranslation(this, bSave);
}

//------------------------------------------------------------------------------
// Address: 0x10158F80
// Name: private: static enum ChunkFileResult_t Camera3D::LoadCameraCallback(class CChunkFile __near *,class Camera3D __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl Camera3D::LoadCameraCallback(CChunkFile *pFile, Camera3D *pCameras)
{
  ChunkFileResult_t result; // eax
  CAMSTRUCT Cam; // [esp+4h] [ebp-18h] BYREF

  memset(&Cam, 0, sizeof(Cam));
  result = CChunkFile::ReadChunk(
             this: pFile,
             pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))Camera3D::LoadCameraKeyCallback,
             pData: &Cam);
  if ( result == ChunkFile_Ok )
  {
    CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
      this: (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&pCameras->Cameras,
      elem: pCameras->Cameras.m_Size,
      src: (const CTrackEntry *)&Cam);
    Camera3D::EnsureMaxCameras(this: pCameras);
    return ChunkFile_Ok;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158FE0
// Name: public: virtual enum ChunkFileResult_t Camera3D::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall Camera3D::LoadVMF(Camera3D *this, CChunkFile *pFile)
{
  ChunkFileResult_t Chunk; // ebx
  int m_Size; // ecx
  int m_iActiveCamera; // eax
  CChunkHandlerMap Handlers; // [esp+Ch] [ebp-18h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v8 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "camera",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))Camera3D::LoadCameraCallback,
    pData: this);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))Camera3D::LoadCamerasKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  if ( Chunk == ChunkFile_Ok )
  {
    m_Size = this->Cameras.m_Size;
    if ( m_Size != 0 )
    {
      m_iActiveCamera = this->m_iActiveCamera;
      if ( m_iActiveCamera < 0 || m_iActiveCamera > m_Size )
        this->m_iActiveCamera = 0;
    }
    else
    {
      this->m_iActiveCamera = -1;
    }
  }
  v8 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x101590A0
// Name: public: virtual bool Camera3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Camera3D::OnLMouseDown2D(Camera3D *this, CMapView2D *pView, char nFlags, const Vector2D *vPoint)
{
  CMapView *v4; // edi
  HWND v6; // eax
  unsigned int v7; // eax
  CAMSTRUCT *m_pMemory; // edx
  int v9; // ecx
  float *v10; // ecx
  int v11; // eax
  double v12; // st7
  float *v13; // eax
  CMapDoc *v14; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector vecCenter; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecWorld; // [esp+18h] [ebp-10h] BYREF
  CMapDoc *pDoc; // [esp+24h] [ebp-4h]

  v4 = &pView->CMapView;
  pDoc = pView->GetMapDoc(this: &pView->CMapView);
  v6 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  v4->ClientToWorld(this: v4, a2: &vecWorld, a3: vPoint);
  if ( this->IsEmpty(this) || (nFlags & 4) != 0 )
  {
    if ( CSelection::IsEmpty(this: pDoc->m_pSelection) )
    {
      v14 = pDoc;
      *((_DWORD *)&vecWorld.x + pView->axThird) = 1203982208;
      CMapDoc::GetBestVisiblePoint(this: v14, ptOrg: &vecWorld);
    }
    else
    {
      CSelection::GetBoundsCenter(this: pDoc->m_pSelection, &vecCenter);
      *(&vecWorld.x + pView->axThird) = *(&vecCenter.x + pView->axThird);
    }
    x = vecWorld.x;
    y = vecWorld.y;
    z = vecWorld.z;
    this->m_vOrgPos = vecWorld;
    this->m_MoveCamera.position[0].x = x;
    this->m_MoveCamera.position[0].y = y;
    this->m_MoveCamera.position[0].z = z;
    this->m_MoveCamera.position[1].x = x;
    this->m_MoveCamera.position[1].y = y;
    this->m_MoveCamera.position[1].z = z;
    this->m_nMovePositionIndex = 1;
    this->m_iActiveCamera = CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
                              this: (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&this->Cameras,
                              elem: this->Cameras.m_Size,
                              src: (const CTrackEntry *)&this->m_MoveCamera);
    Camera3D::EnsureMaxCameras(this);
    goto LABEL_9;
  }
  v7 = this->HitTest(this, a2: v4, a3: vPoint, a4: false);
  if ( v7 != 0 )
  {
    m_pMemory = this->Cameras.m_Memory.m_pMemory;
    v9 = (unsigned __int16)v7 - 1;
    this->m_iActiveCamera = v9;
    v10 = (float *)&m_pMemory[v9];
    v11 = HIWORD(v7);
    this->m_MoveCamera.position[0].x = *v10;
    this->m_MoveCamera.position[0].y = v10[1];
    this->m_MoveCamera.position[0].z = v10[2];
    this->m_MoveCamera.position[1].x = v10[3];
    this->m_MoveCamera.position[1].y = v10[4];
    this->m_MoveCamera.position[1].z = v10[5];
    this->m_nMovePositionIndex = v11;
    v11 *= 3;
    v12 = *(&this->m_MoveCamera.position[0].x + v11);
    v13 = (float *)((char *)&this->m_MoveCamera + 4 * v11);
    this->m_vOrgPos.x = v12;
    this->m_vOrgPos.y = v13[1];
    this->m_vOrgPos.z = v13[2];
LABEL_9:
    Tool3D::StartTranslation(this, pView: v4, vClickPoint: vPoint, bUseDefaultPlane: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10159280
// Name: public: void Camera3D::SerializeRMF(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Camera3D::SerializeRMF(Camera3D *this, std::fstream *file, int fIsStoring)
{
  int m_Size; // eax
  std::ostream *v5; // esi
  int v6; // edi
  int v7; // ebx
  std::fstream *v8; // ebx
  int v9; // edi
  Camera3D *v10; // esi
  CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *p_Cameras; // ecx
  int v12; // [esp-10h] [ebp-34h]
  CAMSTRUCT cam; // [esp+0h] [ebp-24h] BYREF
  float fVersion; // [esp+18h] [ebp-Ch] BYREF
  Camera3D *v15; // [esp+1Ch] [ebp-8h]
  int nCameras; // [esp+20h] [ebp-4h] BYREF

  m_Size = this->Cameras.m_Size;
  v15 = this;
  fVersion = 0.2;
  nCameras = m_Size;
  if ( fIsStoring != 0 )
  {
    v5 = (std::ostream *)file->gap10;
    std::ostream::write(this: (std::ostream *)file->gap10, _Str: (const char *)&fVersion, _Count: 4);
    std::ostream::write(this: v5, _Str: (const char *)&this->m_iActiveCamera, _Count: 4);
    std::ostream::write(this: v5, _Str: (const char *)&nCameras, _Count: 4);
    v6 = 0;
    if ( nCameras > 0 )
    {
      v7 = 0;
      do
      {
        std::ostream::write(this: v5, _Str: (const char *)&v15->Cameras.m_Memory.m_pMemory[v7], _Count: 24);
        ++v6;
        ++v7;
      }
      while ( v6 < nCameras );
    }
  }
  else
  {
    v8 = file;
    std::istream::read(this: file, _Str: (char *)&file, _Count: 4);
    if ( *(float *)&file >= 0.2 )
      std::istream::read(this: v8, _Str: (char *)&this->m_iActiveCamera, _Count: 4);
    v9 = 0;
    std::istream::read(this: v8, _Str: (char *)&nCameras, _Count: 4);
    v10 = v15;
    v12 = nCameras;
    p_Cameras = (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&v15->Cameras;
    v15->Cameras.m_Size = 0;
    CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::EnsureCapacity(this: p_Cameras, num: v12);
    if ( nCameras > 0 )
    {
      do
      {
        std::istream::read(this: v8, _Str: (char *)&cam, _Count: 24);
        CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
          this: (CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int> > *)&v10->Cameras,
          elem: v10->Cameras.m_Size,
          src: (const CTrackEntry *)&cam);
        ++v9;
      }
      while ( v9 < nCameras );
    }
    Camera3D::EnsureMaxCameras(this: v10);
  }
}
