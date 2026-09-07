// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/matsyswin.cpp
// Functions: 17
// ============================================================

#include "utils\hlfaceposer\matsyswin.h"

//------------------------------------------------------------------------------
// Address: 0x0045E750
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045E810
// Name: ReleaseMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseMaterialSystemObjects()
{
  StudioModel::ReleaseStudioModel();
  models->ReleaseModels(this: models);
}

//------------------------------------------------------------------------------
// Address: 0x0045E830
// Name: RestoreMaterialSystemObjects
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreMaterialSystemObjects()
{
  StudioModel::RestoreStudioModel();
  models->RestoreModels(this: models);
}

//------------------------------------------------------------------------------
// Address: 0x0045E850
// Name: void InitMaterialSystemConfig(struct MaterialSystem_Config_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMaterialSystemConfig(MaterialSystem_Config_t *pConfig)
{
  pConfig->m_Flags |= 0x8000u;
}

//------------------------------------------------------------------------------
// Address: 0x0045E860
// Name: public: virtual void MatSysWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::redraw(MatSysWindow *this)
{
  if ( !bInRedraw )
  {
    bInRedraw = true;
    mxMatSysWindow::redraw(this);
    bInRedraw = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E880
// Name: public: void MatSysWindow::SuppressBufferSwap(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::SuppressBufferSwap(MatSysWindow *this, bool bSuppress)
{
  *((_BYTE *)this + 645) = bSuppress;
}

//------------------------------------------------------------------------------
// Address: 0x0045E890
// Name: public: void MatSysWindow::EnableStickySnapshotMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::EnableStickySnapshotMode(MatSysWindow *this)
{
  ++*((_DWORD *)this + 162);
}

//------------------------------------------------------------------------------
// Address: 0x0045E960
// Name: public: void MatSysWindow::Frame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::Frame(MatSysWindow *this)
{
  double v2; // xmm2_8
  double v3; // xmm0_8
  float v4; // xmm0_4
  double dt; // [esp+10h] [ebp-8h]

  v2 = (double)(int)mx::getTickCount() * 0.001;
  v3 = v2 - prev;
  dt = v2 - prev;
  if ( !recursion_guard )
  {
    recursion_guard = true;
    if ( v3 < 0.0 || v3 >= 0.004 )
    {
      if ( prev != 0.0 )
      {
        if ( v3 > 0.1 )
        {
          v3 = 0.1;
          dt = 0.1;
        }
        v4 = v3;
        MDLViewer::Think(this: g_MDLViewer, dt: v4);
        realtime = realtime + dt;
      }
      prev = v2;
      if ( !g_viewerSettings.pause )
        this->redraw(this);
      recursion_guard = false;
    }
    else
    {
      Sleep(dwMilliseconds: (int)((0.004 - v3) * 1000.0) < 0 ? 0 : (int)((0.004 - v3) * 1000.0));
      recursion_guard = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EA80
// Name: public: virtual int MatSysWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall MatSysWindow::handleEvent(MatSysWindow *this, float event)
{
  IMDLCache *m_pCache; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  float v5; // esi
  unsigned __int8 (__thiscall *v6)(void **, _DWORD); // edx
  StudioModel *v8; // eax
  int v9; // ecx
  float z; // xmm0_4
  int v11; // eax
  int v12; // ebx
  mxEvent *v13; // eax
  int v14; // ebx
  int v15; // eax
  float v16; // xmm1_4
  StudioModel *v17; // ebx
  int v18; // eax
  int v19; // eax
  void (__thiscall *redraw)(struct MatSysWindow *); // edx
  float v21; // xmm1_4
  int v22; // eax
  int v23; // esi
  float v24; // xmm1_4
  int v25; // eax
  int v26; // esi
  int v27; // edx
  float v28; // xmm0_4
  float v29; // xmm0_4
  double v30; // xmm0_8
  int v31; // ecx
  QAngle *p_m_angles; // ebx
  float v33; // xmm0_4
  float *p_x; // ebx
  int v35; // esi
  StudioModel *v36; // eax
  int Sequence; // esi
  StudioModel *v38; // eax
  long double v39; // [esp+0h] [ebp-C8h]
  long double v40; // [esp+0h] [ebp-C8h]
  long double v41; // [esp+8h] [ebp-C0h] OVERLAPPED BYREF
  matrix3x4_t tmp3; // [esp+3Ch] [ebp-8Ch] BYREF
  matrix3x4_t tmp2; // [esp+6Ch] [ebp-5Ch] BYREF
  QAngle angles; // [esp+9Ch] [ebp-2Ch] BYREF
  double v45; // [esp+A8h] [ebp-20h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+B0h] [ebp-18h]
  QAngle movement; // [esp+B4h] [ebp-14h] BYREF
  double v48; // [esp+C0h] [ebp-8h] OVERLAPPED BYREF

  m_pCache = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  v5 = event;
  v6 = *((unsigned __int8 (__thiscall **)(void **, _DWORD))this->m_hWnd + 7);
  HIDWORD(v48) = 0;
  if ( v6(a1: &this->m_hWnd, a2: LODWORD(event)) != 0 )
  {
    m_pCache->EndLock(this: m_pCache);
    return 0;
  }
  else
  {
    switch ( *(_DWORD *)(LODWORD(v5) + 4) )
    {
      case 3:
        HIDWORD(v48) = 1;
        MatSysWindow::Frame(this);
        break;
      case 7:
        v8 = models->GetActiveStudioModel(this: models);
        if ( v8 != nullptr )
        {
          v9 = *(__int16 *)(LODWORD(v5) + 28);
          oldrx = v8->m_angles.x;
          oldry = v8->m_angles.y;
          oldtx = v8->m_origin.x;
          oldty = v8->m_origin.y;
          z = v8->m_origin.z;
          v11 = *(__int16 *)(LODWORD(v5) + 24);
          oldtz = z;
          oldy = v9;
          oldlrx = g_viewerSettings.lightrot.x;
          oldx = v11;
          oldlry = g_viewerSettings.lightrot.y;
          g_viewerSettings.pause = false;
          v12 = mxWidget::w(this);
          if ( v12 >= mxWidget::h(this) )
            v13 = (mxEvent *)mxWidget::h(this);
          else
            v13 = (mxEvent *)mxWidget::w(this);
          event = *(float *)&v13;
          HIDWORD(v48) = *(_DWORD *)(LODWORD(v5) + 28) - mxWidget::h(this) / 2;
          v14 = HIDWORD(v48) * (*(_DWORD *)(LODWORD(v5) + 28) - mxWidget::h(this) / 2);
          HIDWORD(v48) = *(_DWORD *)(LODWORD(v5) + 24) - mxWidget::w(this) / 2;
          v15 = mxWidget::w(this);
          v16 = (double)SLODWORD(event) * 0.3333333333333333;
          g_viewerSettings.rotating = v16 <= fsqrt((float)(v14 + HIDWORD(v48)
                                                               * (*(_DWORD *)(LODWORD(v5) + 24) - v15 / 2)));
          goto LABEL_10;
        }
        break;
      case 9:
        v17 = models->GetActiveStudioModel(this: models);
        if ( v17 != nullptr )
        {
          v18 = *(_DWORD *)(LODWORD(v5) + 32);
          if ( (v18 & 1) != 0 )
          {
            v19 = *(_DWORD *)(LODWORD(v5) + 40);
            if ( (v19 & 2) != 0 )
            {
              redraw = this->redraw;
              v21 = oldty - (float)(*(__int16 *)(LODWORD(v5) + 24) - oldx) * 0.1;
              v17->m_origin.y = v21;
              v17->m_origin.z = (float)(*(__int16 *)(LODWORD(v5) + 28) - oldy) * 0.1 + oldtz;
              redraw(this);
            }
            else if ( (v19 & 1) != 0 )
            {
              v22 = *(_DWORD *)(LODWORD(v5) + 28);
              v23 = *(_DWORD *)(LODWORD(v5) + 24);
              movement.x = (float)(v22 - oldy);
              v24 = (float)(v23 - oldx);
              oldx = v23;
              oldy = v22;
              movement.y = v24;
              movement.z = 0.0;
              AngleMatrix(angles: &g_viewerSettings.lightrot, matrix: (matrix3x4_t *)((char *)&v41 + 4));
              AngleMatrix(angles: &movement, matrix: &tmp2);
              ConcatTransforms(in1: &tmp2, in2: (const matrix3x4_t *)((char *)&v41 + 4), out: &tmp3);
              MatrixAngles(matrix: &tmp3, angles: &g_viewerSettings.lightrot.x);
              this->redraw(this);
            }
            else
            {
              if ( g_viewerSettings.rotating )
              {
                v48 = (double)oldx;
                v45 = (double)oldy;
                v48 = v48 - (double)mxWidget::w(this) * 0.5;
                mxWidget::h(this);
                __libm_sse2_atan2(y: v39, x: v41);
                v29 = v48 * 57.29746936176985;
                *((float *)&v48 + 1) = v29;
                v45 = (double)*(int *)(LODWORD(v5) + 24);
                v30 = (double)*(int *)(LODWORD(v5) + 28);
                LODWORD(event) = LODWORD(v5) + 24;
                *(double *)&movement.y = v30;
                v45 = v45 - (double)mxWidget::w(this) * 0.5;
                mxWidget::h(this);
                __libm_sse2_atan2(y: v40, x: v41);
                v31 = *(_DWORD *)(LODWORD(v5) + 28);
                *(float *)&v30 = v45 * 57.29746936176985;
                p_m_angles = &v17->m_angles;
                oldx = *(_DWORD *)LODWORD(event);
                oldy = v31;
                angles.x = 0.0;
                angles.y = 0.0;
                angles.z = *(float *)&v30 - *((float *)&v48 + 1);
                AngleMatrix(angles: p_m_angles, matrix: (matrix3x4_t *)((char *)&v41 + 4));
                AngleMatrix(&angles, matrix: &tmp2);
                ConcatTransforms(in1: &tmp2, in2: (const matrix3x4_t *)((char *)&v41 + 4), out: &tmp3);
                MatrixAngles(matrix: &tmp3, angles: &p_m_angles->x);
              }
              else
              {
                v25 = *(_DWORD *)(LODWORD(v5) + 28);
                v26 = *(_DWORD *)(LODWORD(v5) + 24);
                v27 = v26 - oldx;
                v28 = (float)(v25 - oldy);
                oldy = v25;
                event = v28;
                oldx = v26;
                movement.x = 0.0;
                movement.y = (float)v27;
                movement.z = 0.0;
                AngleMatrix(angles: &v17->m_angles, matrix: &tmp3);
                AngleMatrix(angles: &movement, matrix: &tmp2);
                ConcatTransforms(in1: &tmp3, in2: &tmp2, out: (matrix3x4_t *)((char *)&v41 + 4));
                MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v41 + 4), angles: &v17->m_angles.x);
                movement.x = event;
                movement.y = 0.0;
                movement.z = 0.0;
                AngleMatrix(angles: &v17->m_angles, matrix: &tmp3);
                AngleMatrix(angles: &movement, matrix: &tmp2);
                ConcatTransforms(in1: &tmp2, in2: &tmp3, out: (matrix3x4_t *)((char *)&v41 + 4));
                MatrixAngles(matrix: (const matrix3x4_t *)((char *)&v41 + 4), angles: &v17->m_angles.x);
              }
              this->redraw(this);
            }
          }
          else
          {
            if ( (v18 & 2) != 0 )
            {
              v33 = (float)(*(__int16 *)(LODWORD(v5) + 28) - oldy) * 0.1 + oldtx;
              p_x = &v17->m_origin.x;
              *p_x = v33;
              event = 2048.0;
              HIDWORD(v48) = 1090519040;
              *p_x = clamp<float,float,float>(val: p_x, minVal: (const float *)&v48 + 1, maxVal: &event);
            }
            this->redraw(this);
          }
LABEL_10:
          HIDWORD(v48) = 1;
        }
        m_pCache = cacheCriticalSection.m_pCache;
        break;
      case 0xB:
        v35 = *(_DWORD *)(LODWORD(v5) + 36);
        HIDWORD(v48) = 1;
        switch ( v35 )
        {
          case 27:
            if ( mxWidget::getParent(this) == nullptr )
              mx::quit();
            break;
          case 32:
            v36 = models->GetActiveStudioModel(this: models);
            Sequence = StudioModel::GetSequence(this: v36);
            v38 = models->GetActiveStudioModel(this: models);
            if ( Sequence == StudioModel::SetSequence(this: v38, iSequence: Sequence + 1) )
              ControlPanel::setSequence(this: g_pControlPanel, index: 0);
            else
              ControlPanel::setSequence(this: g_pControlPanel, index: Sequence + 1);
            break;
          case 43:
            g_viewerSettings.speedScale = g_viewerSettings.speedScale + 0.1;
            if ( g_viewerSettings.speedScale > 5.0 )
              g_viewerSettings.speedScale = 5.0;
            break;
          case 45:
            g_viewerSettings.speedScale = g_viewerSettings.speedScale - 0.1;
            if ( g_viewerSettings.speedScale < 0.0 )
              g_viewerSettings.speedScale = 0.0;
            break;
          case 49:
          case 50:
          case 51:
          case 52:
            g_viewerSettings.renderMode = v35 - 49;
            break;
          case 98:
            g_viewerSettings.showBackground = !g_viewerSettings.showBackground;
            break;
          case 103:
            g_viewerSettings.showGround = !g_viewerSettings.showGround;
            break;
          case 104:
            g_viewerSettings.showHitBoxes = !g_viewerSettings.showHitBoxes;
            break;
          case 109:
            g_viewerSettings.showMovement = !g_viewerSettings.showMovement;
            break;
          case 111:
            g_viewerSettings.showBones = !g_viewerSettings.showBones;
            break;
          case 116:
            MDLViewer::Refresh(this: g_MDLViewer);
            break;
          default:
            HIDWORD(v48) = 0;
            break;
        }
        break;
      default:
        break;
    }
    m_pCache->EndLock(this: m_pCache);
    return HIDWORD(v48);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F2B0
// Name: public: void MatSysWindow::DisableStickySnapshotMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::DisableStickySnapshotMode(MatSysWindow *this)
{
  HWND Handle; // eax
  HCURSOR v4; // [esp-4h] [ebp-8h]

  if ( (*((_DWORD *)this + 162))-- == 1 && *((_BYTE *)this + 652) != 0 )
  {
    *((_BYTE *)this + 652) = 0;
    Handle = (HWND)mxWidget::getHandle(this);
    SetWindowPlacement(hWnd: Handle, lpwndpl: (const WINDOWPLACEMENT *)this + 15);
    v4 = *((HCURSOR *)this + 176);
    *((_BYTE *)this + 644) = 0;
    SetCursor(hCursor: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F300
// Name: public: void MatSysWindow::PushSnapshotMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::PushSnapshotMode(MatSysWindow *this, int nSnapShotSize)
{
  int v3; // eax
  HCURSOR CursorA; // eax
  HWND Handle; // edi
  tagRECT rcClient; // [esp+4h] [ebp-10h] BYREF

  v3 = *((_DWORD *)this + 164);
  *((_DWORD *)this + 164) = v3 + 1;
  if ( v3 == 0 )
  {
    if ( *((_DWORD *)this + 162) != 0 )
    {
      if ( *((_BYTE *)this + 652) != 0 )
        return;
      *((_BYTE *)this + 652) = 1;
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F02);
      *((_DWORD *)this + 176) = SetCursor(hCursor: CursorA);
    }
    *((_BYTE *)this + 644) = 1;
    Handle = (HWND)mxWidget::getHandle(this);
    GetWindowPlacement(hWnd: Handle, lpwndpl: (WINDOWPLACEMENT *)this + 15);
    GetClientRect(hWnd: Handle, lpRect: &rcClient);
    MoveWindow(hWnd: Handle, X: 0, Y: 0, nWidth: nSnapShotSize + 16, nHeight: nSnapShotSize + 16, bRepaint: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F3A0
// Name: public: void MatSysWindow::PopSnapshotMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::PopSnapshotMode(MatSysWindow *this)
{
  HWND Handle; // eax

  if ( (*((_DWORD *)this + 164))-- == 1 && *((_DWORD *)this + 162) == 0 )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    SetWindowPlacement(hWnd: Handle, lpwndpl: (const WINDOWPLACEMENT *)this + 15);
    *((_BYTE *)this + 644) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F3D0
// Name: public: void MatSysWindow::TakeScreenShot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::TakeScreenShot(MatSysWindow *this, const char *filename)
{
  int v3; // esi
  mxImage *v4; // eax
  mxImage *v5; // edi
  void *v6; // eax
  HWND Handle; // eax
  HDC DC; // eax
  _BYTE *data; // ebx
  int v10; // esi
  int i; // edi
  COLORREF Pixel; // eax
  HWND v13; // eax
  HDC__ *hdc; // [esp+10h] [ebp-14h]
  int h; // [esp+14h] [ebp-10h]
  mxImage *image; // [esp+18h] [ebp-Ch]
  int y; // [esp+1Ch] [ebp-8h]
  int w; // [esp+20h] [ebp-4h]

  ((void (__fastcall *)(MatSysWindow *))this->redraw)(a1: this);
  w = mxWidget::w2(this);
  v3 = mxWidget::h2(this);
  h = v3;
  v4 = (mxImage *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
  {
    v5 = v4;
    v4->__vftable = (mxImage_vtbl *)&mxImage::`vftable';
    v4->width = 0;
    v4->height = 0;
    v4->bpp = 0;
    v4->data = nullptr;
    v4->palette = nullptr;
    image = v4;
  }
  else
  {
    image = nullptr;
    v5 = nullptr;
  }
  if ( v5->data != nullptr )
    free(pMem: v5->data);
  if ( v5->palette != nullptr )
    free(pMem: v5->palette);
  v6 = operator new(nSize: 24 * w * v3 / 8);
  v5->data = v6;
  if ( v6 != nullptr )
  {
    v5->palette = nullptr;
    v5->width = w;
    v5->height = v3;
    v5->bpp = 24;
    Handle = (HWND)mxWidget::getHandle(this);
    DC = GetDC(hWnd: Handle);
    data = v5->data;
    v10 = 0;
    hdc = DC;
    y = 0;
    if ( h > 0 )
    {
      do
      {
        for ( i = 0; i < w; v10 += 3 )
        {
          Pixel = GetPixel(hdc, x: i, y);
          *(_WORD *)&data[v10] = Pixel;
          data[v10 + 2] = BYTE2(Pixel);
          ++i;
        }
        ++y;
      }
      while ( y < h );
      v5 = image;
    }
    v13 = (HWND)mxWidget::getHandle(this);
    ReleaseDC(hWnd: v13, hDC: hdc);
    if ( !mxTgaWrite(filename, image: v5) )
      mxMessageBox(parent: this, msg: "Error writing screenshot.", title: g_appTitle, style: 8);
    ((void (__thiscall *)(mxImage *, int))v5->dtr_mxImage)(a1: v5, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F550
// Name: public: MatSysWindow::MatSysWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MatSysWindow *__thiscall MatSysWindow::MatSysWindow(
        MatSysWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  Color v9; // ecx
  Color v10; // ecx
  ITexture *v11; // edi
  IMatRenderContext *v12; // eax
  IMatRenderContext *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // edi
  MaterialSystem_Config_t config; // [esp+Ch] [ebp-64h] BYREF

  mxMatSysWindow::mxMatSysWindow(this, parent, x, y, w, h, label, style);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: (IFacePoserToolWindow *)&this->m_hWnd,
    toolname: "3D View",
    displaynameroot: "3D View");
  this->__vftable = (MatSysWindow_vtbl *)&MatSysWindow::`vftable'{for `mxMatSysWindow'};
  this->m_hWnd = &MatSysWindow::`vftable'{for `IFacePoserToolWindow'};
  g_pMaterialSystem->SetMaterialProxyFactory(this: g_pMaterialSystem, a2: &g_DummyMaterialProxyFactory);
  IFacePoserToolWindow::SetAutoProcess(this: (IFacePoserToolWindow *)&this->m_hWnd, autoprocess: true);
  mxWidget::setLabel(this, format: "3D View");
  *((_BYTE *)this + 645) = 0;
  *((_DWORD *)this + 160) = mxWidget::getHandle(this);
  Con_Printf(a1: v9, fmt: "Setting material system video mode\n");
  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  config = *g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
  config.m_Flags |= 0x8000u;
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
  config.m_Flags |= 3u;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: *((void **)this + 160), a3: &config) )
  {
    g_pMaterialSystem->AddReleaseFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))ReleaseMaterialSystemObjects);
    g_pMaterialSystem->AddRestoreFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))RestoreMaterialSystemObjects);
    Con_Printf(a1: v10, fmt: "Loading debug materials\n");
    v11 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "hlmv/cubemap", a3: 0, a4: 1, a5: 0);
    v11->IncrementReferenceCount(this: v11);
    v12 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v13 = v12;
    if ( v12 != nullptr )
      v12->BeginRender(this: v12);
    v13->BindLocalCubemap(this: v13, a2: v11);
    g_materialBackground = g_pMaterialSystem->FindMaterial(
                             this: g_pMaterialSystem,
                             a2: "particle/particleapp_background",
                             a3: "Other textures",
                             a4: 1,
                             a5: 0);
    g_materialWireframe = g_pMaterialSystem->FindMaterial(
                            this: g_pMaterialSystem,
                            a2: "debug/debugmrmwireframe",
                            a3: "Other textures",
                            a4: 1,
                            a5: 0);
    g_materialWireframeVertexColor = g_pMaterialSystem->FindMaterial(
                                       this: g_pMaterialSystem,
                                       a2: "debug/debugwireframevertexcolor",
                                       a3: "Other textures",
                                       a4: 1,
                                       a5: 0);
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
      v15 = KeyValues::KeyValues(this: v14, setName: "Wireframe");
    else
      v15 = nullptr;
    KeyValues::SetInt(this: v15, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v15, keyName: "$nocull", value: 1);
    KeyValues::SetInt(this: v15, keyName: "$vertexcolor", value: 1);
    KeyValues::SetInt(this: v15, keyName: "$decal", value: 1);
    g_materialWireframeVertexColorNoCull = g_pMaterialSystem->CreateMaterial(
                                             this: g_pMaterialSystem,
                                             a2: "debug/wireframenocull",
                                             a3: v15);
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
      v17 = KeyValues::KeyValues(this: v16, setName: "UnlitGeneric");
    else
      v17 = nullptr;
    KeyValues::SetString(this: v17, keyName: "$basetexture", value: "vgui/white");
    g_materialDebugCopyBaseTexture = g_pMaterialSystem->CreateMaterial(
                                       this: g_pMaterialSystem,
                                       a2: "debug/copybasetexture",
                                       a3: v17);
    g_materialFlatshaded = g_pMaterialSystem->FindMaterial(
                             this: g_pMaterialSystem,
                             a2: "debug/debugdrawflatpolygons",
                             a3: "Other textures",
                             a4: 1,
                             a5: 0);
    g_materialSmoothshaded = g_pMaterialSystem->FindMaterial(
                               this: g_pMaterialSystem,
                               a2: "debug/debugmrmfullbright2",
                               a3: "Other textures",
                               a4: 1,
                               a5: 0);
    g_materialBones = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "debug/debugmrmwireframe",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialLines = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "debug/debugwireframevertexcolor",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialFloor = g_pMaterialSystem->FindMaterial(
                        this: g_pMaterialSystem,
                        a2: "hlmv/floor",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
    g_materialVertexColor = g_pMaterialSystem->FindMaterial(
                              this: g_pMaterialSystem,
                              a2: "debug/debugvertexcolor",
                              a3: "Other textures",
                              a4: 1,
                              a5: 0);
    g_materialShadow = g_pMaterialSystem->FindMaterial(
                         this: g_pMaterialSystem,
                         a2: "hlmv/shadow",
                         a3: "Other textures",
                         a4: 1,
                         a5: 0);
    if ( parent != nullptr )
      mx::setIdleWindow(window: this);
    else
      mxWidget::setVisible(this, b: true);
    *((_BYTE *)this + 644) = 0;
    *((_DWORD *)this + 162) = 0;
    *((_BYTE *)this + 652) = 0;
    *((_DWORD *)this + 164) = 0;
    v13->EndRender(this: v13);
    v13->Release(this: v13);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045F940
// Name: void drawFloor(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall drawFloor(int a1@<edi>)
{
  IMatRenderContext *v1; // esi
  IMesh *v2; // edi
  float *m_pCurrPosition; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1E8h] BYREF

  v1 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))v1->Bind)(
    a1: v1,
    a2: g_materialFloor,
    a3: 0,
    a4: a1);
  v1->MatrixMode(this: v1, a2: MATERIAL_MODEL);
  v1->PushMatrix(this: v1);
  v1->LoadIdentity(this: v1);
  v1->MatrixMode(this: v1, a2: MATERIAL_VIEW);
  v1->PushMatrix(this: v1);
  v1->LoadIdentity(this: v1);
  v2 = v1->GetDynamicMesh(this: v1, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v2;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  v2->SetPrimitiveType(this: v2, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v2->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v2, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 15000.0;
  m_pCurrPosition[1] = -15000.0;
  m_pCurrPosition[2] = -15000.0;
  v4 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v4[1] = 1.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v5 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -15000.0;
  v5[1] = -15000.0;
  v5[2] = -15000.0;
  v6 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v6[1] = 1.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v7 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -15000.0;
  v7[1] = 15000.0;
  v7[2] = -15000.0;
  v8 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v8[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 15000.0;
  v9[1] = 15000.0;
  v9[2] = -15000.0;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v10[1] = 0.0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v2->Draw_2(this: v2, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  v1->MatrixMode(this: v1, a2: MATERIAL_MODEL);
  v1->PopMatrix(this: v1);
  v1->MatrixMode(this: v1, a2: MATERIAL_VIEW);
  v1->PopMatrix(this: v1);
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0045FCE0
// Name: public: void MatSysWindow::TakeSnapshotRect(char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatSysWindow::TakeSnapshotRect(
        MatSysWindow *this,
        const char *pFilename,
        int x,
        int y,
        unsigned __int8 *w,
        int h)
{
  unsigned int v7; // esi
  int v8; // ebx
  HANDLE FileA; // eax
  IMatRenderContext *v10; // eax
  IMatRenderContext *m_pObject; // ecx
  int v12; // eax
  char *v13; // edx
  int v14; // ecx
  int v15; // ebx
  unsigned __int8 *v16; // edi
  char *v17; // eax
  int v18; // ecx
  int i; // esi
  char v20; // dl
  bool v21; // zf
  unsigned __int8 *v22; // eax
  int j; // esi
  unsigned __int8 v24; // cl
  void *v25; // esi
  IMatRenderContext *v26; // esi
  const char *v27; // [esp+0h] [ebp-58h]
  tagBITMAPINFOHEADER bi; // [esp+Ch] [ebp-4Ch] BYREF
  tagBITMAPFILEHEADER hdr; // [esp+34h] [ebp-24h] BYREF
  int v30; // [esp+44h] [ebp-14h]
  int v31; // [esp+48h] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+4Ch] [ebp-Ch]
  void *hf; // [esp+50h] [ebp-8h]
  unsigned int dwTmp; // [esp+54h] [ebp-4h] BYREF
  const char *pFilenamea; // [esp+60h] [ebp+8h]
  int xa; // [esp+64h] [ebp+Ch]
  int ya; // [esp+68h] [ebp+10h]
  unsigned __int8 *hp; // [esp+6Ch] [ebp+14h]
  int imageSize; // [esp+70h] [ebp+18h]

  v7 = (unsigned int)(w + 3) & 0xFFFFFFFC;
  v8 = h * v7;
  v30 = h * v7;
  imageSize = 3 * h * v7;
  FileA = CreateFileA(
            lpFileName: pFilename,
            dwDesiredAccess: 0xC0000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  hf = FileA;
  if ( FileA != (HANDLE)-1 )
  {
    hdr.bfType = 19778;
    *(_DWORD *)&hdr.bfReserved1 = 0;
    hdr.bfSize = imageSize + 54;
    hdr.bfOffBits = 54;
    if ( !WriteFile(
            hFile: FileA,
            lpBuffer: &hdr,
            nNumberOfBytesToWrite: 0xEu,
            lpNumberOfBytesWritten: &dwTmp,
            lpOverlapped: nullptr) )
      _Error(this: (ISceneTokenProcessor *)&stru_4F4374, a2: v27);
    memset(&bi.biCompression, 0, 24);
    bi.biSize = 40;
    bi.biWidth = (unsigned int)(w + 3) & 0xFFFFFFFC;
    bi.biHeight = h;
    *(_DWORD *)&bi.biPlanes = 1572865;
    if ( !WriteFile(
            hFile: hf,
            lpBuffer: &bi,
            nNumberOfBytesToWrite: 0x28u,
            lpNumberOfBytesWritten: &dwTmp,
            lpOverlapped: nullptr) )
      _Error(this: (ISceneTokenProcessor *)&stru_4F4348, a2: v27);
    hp = (unsigned __int8 *)operator new(nSize: imageSize);
    if ( hp == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_4F4318, a2: v27);
    v10 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    m_pObject = v10;
    pRenderContext.m_pObject = v10;
    if ( v10 != nullptr )
    {
      v10->BeginRender(this: v10);
      m_pObject = pRenderContext.m_pObject;
    }
    m_pObject->ReadPixels(this: m_pObject, a2: x, a3: y, a4: v7, a5: h, a6: hp, a7: IMAGE_FORMAT_RGB888);
    v12 = h / 2;
    if ( h / 2 > 0 )
    {
      v13 = (char *)hp;
      v14 = -3 * v7;
      v15 = 3 * v7;
      xa = 3 * v7;
      pFilenamea = (const char *)hp;
      v31 = -3 * v7;
      v16 = &hp[v7 * (3 * h - 3)];
      ya = v12;
      do
      {
        v17 = v13;
        if ( v15 > 0 )
        {
          v18 = v16 - (unsigned __int8 *)v13;
          for ( i = v15; i != 0; --i )
          {
            v20 = *v17;
            *v17 = v17[v18];
            (v17++)[v18] = v20;
          }
          v15 = xa;
          v13 = (char *)pFilenamea;
          v14 = v31;
        }
        v13 += v15;
        v16 += v14;
        v21 = ya-- == 1;
        pFilenamea = v13;
      }
      while ( !v21 );
      v8 = v30;
    }
    v22 = hp;
    if ( v8 > 0 )
    {
      for ( j = v8; j != 0; --j )
      {
        v24 = *v22;
        *v22 = v22[2];
        v22[2] = v24;
        v22 += 3;
      }
    }
    v25 = hf;
    if ( !WriteFile(
            hFile: hf,
            lpBuffer: hp,
            nNumberOfBytesToWrite: imageSize,
            lpNumberOfBytesWritten: &dwTmp,
            lpOverlapped: nullptr) )
      _Error(this: (ISceneTokenProcessor *)&stru_4F42F0, a2: v27);
    free(pMem: hp);
    if ( !CloseHandle(hObject: v25) )
      _Error(this: (ISceneTokenProcessor *)&stru_4F42CC, a2: v27);
    v26 = pRenderContext.m_pObject;
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    v26->Release(this: v26);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FF00
// Name: public: virtual void MatSysWindow::draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall MatSysWindow::draw(MatSysWindow *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int v4; // eax
  StudioModel *(__thiscall *GetActiveStudioModel)(IFaceposerModels *); // eax
  int v6; // edi
  int v7; // esi
  StudioModel **m_pMemory; // ebx
  int (__thiscall *Count)(IFaceposerModels *); // edx
  int m_Size; // eax
  int v11; // esi
  int v12; // eax
  int *v13; // eax
  IMatRenderContext *v14; // eax
  IMatRenderContext *v15; // esi
  mxWidget *v16; // edi
  int v17; // eax
  int v18; // edi
  void *Handle; // eax
  int v20; // eax
  int v21; // eax
  int ModelGap; // ecx
  int v23; // edi
  int v24; // eax
  StudioModel *v25; // edx
  __int64 v26; // xmm0_8
  float z; // edx
  CUtlVector<StudioModel *,CUtlMemory<StudioModel *,int> > modellist; // [esp+84h] [ebp-2Ch] BYREF
  Vector oldtrans; // [esp+98h] [ebp-18h]
  int ydelta; // [esp+A4h] [ebp-Ch]
  int captiony; // [esp+A8h] [ebp-8h]
  mxWidget *v32; // [esp+ACh] [ebp-4h]

  v32 = this;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-noshaderapi") == 0 )
  {
    ((void (__stdcall *)(_DWORD, int, int, int))g_pMaterialSystem->BeginFrame)(a1: 0, a2: a3, a3: a4, a4: a2);
    GetActiveStudioModel = models->GetActiveStudioModel;
    v6 = 0;
    memset(&modellist, 0, sizeof(modellist));
    v7 = (int)GetActiveStudioModel(this: models);
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&modellist,
      num: 1);
    m_pMemory = modellist.m_Memory.m_pMemory;
    ++modellist.m_Size;
    modellist.m_pElements = modellist.m_Memory.m_pMemory;
    if ( modellist.m_Size - 1 > 0 )
      _V_memmove(
        dest: modellist.m_Memory.m_pMemory + 1,
        src: modellist.m_Memory.m_pMemory,
        count: 4 * (modellist.m_Size - 1));
    if ( m_pMemory != nullptr )
      *m_pMemory = (StudioModel *)v7;
    if ( models->CountVisibleModels(this: models) > 0 )
    {
      Count = models->Count;
      modellist.m_Size = 0;
      if ( Count(this: models) > 0 )
      {
        do
        {
          if ( models->IsModelShownIn3DView(this: models, a2: v6) )
          {
            captiony = (int)models->GetStudioModel(this: models, a2: v6);
            m_Size = modellist.m_Size;
            v11 = modellist.m_Size;
            if ( modellist.m_Size + 1 > modellist.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&modellist,
                num: modellist.m_Size - modellist.m_Memory.m_nAllocationCount + 1);
              m_Size = modellist.m_Size;
              m_pMemory = modellist.m_Memory.m_pMemory;
            }
            modellist.m_Size = m_Size + 1;
            v12 = m_Size - v11;
            modellist.m_pElements = m_pMemory;
            if ( v12 > 0 )
              _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v12);
            v13 = (int *)&m_pMemory[v11];
            if ( v13 != nullptr )
              *v13 = captiony;
          }
          ++v6;
        }
        while ( v6 < models->Count(this: models) );
      }
    }
    v14 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v15 = v14;
    if ( v14 != nullptr )
      v14->BeginRender(this: v14);
    v15->ClearBuffers(this: v15, a2: true, a3: true, a4: false);
    v16 = v32;
    captiony = ((int (__thiscall *)(mxWidget_i **))v32[2].d_this[2].d_hwnd)(a1: &v32[2].d_this);
    v17 = mxWidget::h2(this: v16);
    v18 = v17 - captiony;
    ydelta = (int)&g_pMaterialSystem->SetView;
    Handle = mxWidget::getHandle(this: v32);
    (*(void (__thiscall **)(IMaterialSystem *, void *))ydelta)(a1: g_pMaterialSystem, a2: Handle);
    ydelta = (int)&v15->Viewport;
    v20 = mxWidget::w2(this: v32);
    (*(void (__thiscall **)(IMatRenderContext *, _DWORD, int, int, int))ydelta)(
      a1: v15,
      a2: 0,
      a3: captiony,
      a4: v20,
      a5: v18);
    v15->MatrixMode(this: v15, a2: MATERIAL_PROJECTION);
    v15->LoadIdentity(this: v15);
    ydelta = (int)&v15->PerspectiveX;
    v21 = mxWidget::w2(this: v32);
    (*(void (__thiscall **)(IMatRenderContext *, _DWORD, int, _DWORD, _DWORD, _DWORD, int, _DWORD, int))ydelta)(
      a1: v15,
      a2: 0,
      a3: 1077149696,
      a4: COERCE_UNSIGNED_INT64((float)((float)v21 / (float)v18)),
      a5: HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v21 / (float)v18))),
      a6: 0,
      a7: 1072693248,
      a8: 0,
      a9: 1087604736);
    v15->MatrixMode(this: v15, a2: MATERIAL_VIEW);
    v15->LoadIdentity(this: v15);
    ((void (__thiscall *)(IMatRenderContext *, int, int, _DWORD, _DWORD))v15->Rotate)(
      a1: v15,
      a2: -1028390912,
      a3: 1065353216,
      a4: 0,
      a5: 0);
    ((void (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, int))v15->Rotate)(
      a1: v15,
      a2: -1028390912,
      a3: 0,
      a4: 0,
      a5: 1065353216);
    ModelGap = (int)ControlPanel::GetModelGap(this: g_pControlPanel);
    v23 = 0;
    v24 = ModelGap * (modellist.m_Size / -2);
    ydelta = ModelGap;
    if ( modellist.m_Size > 0 )
    {
      while ( 1 )
      {
        ++m_pMemory[v23]->m_iFramecounter;
        v25 = m_pMemory[v23];
        v26 = *(_QWORD *)&v25->m_origin.x;
        z = v25->m_origin.z;
        *(_QWORD *)&oldtrans.x = v26;
        oldtrans.z = z;
        m_pMemory[v23]->m_origin.y = (float)v24 + *((float *)&v26 + 1);
        captiony = ModelGap + v24;
        g_pStudioRender->BeginFrame(this: g_pStudioRender);
        m_pMemory[v23]->DrawModel(this: m_pMemory[v23], a2: false);
        g_pStudioRender->EndFrame(this: g_pStudioRender);
        m_pMemory[v23++]->m_origin = oldtrans;
        if ( v23 >= modellist.m_Size )
          break;
        v24 = captiony;
        ModelGap = ydelta;
      }
    }
    if ( g_viewerSettings.showGround )
      drawFloor(a1: v23);
    if ( BYTE1(v32[80].d_this) == 0 )
      g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
    g_pMaterialSystem->EndFrame(this: g_pMaterialSystem);
    v15->EndRender(this: v15);
    v15->Release(this: v15);
    if ( modellist.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}
