// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/faceedit_materialpage.cpp
// Functions: 43
// ============================================================

#include "hammer\faceedit_materialpage.h"

//------------------------------------------------------------------------------
// Address: 0x100CB410
// Name: public: virtual struct CRuntimeClass __near * CFaceEditMaterialPage::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFaceEditMaterialPage::GetRuntimeClass(CFaceEditMaterialPage *this)
{
  return &CFaceEditMaterialPage::classCFaceEditMaterialPage;
}

//------------------------------------------------------------------------------
// Address: 0x100CB420
// Name: public: virtual CFaceEditMaterialPage::~CFaceEditMaterialPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::~CFaceEditMaterialPage(CFaceEditMaterialPage *this)
{
  this->__vftable = (CFaceEditMaterialPage_vtbl *)&CFaceEditMaterialPage::`vftable';
  CFaceSmoothingDlg::~CFaceSmoothingDlg(this: &this->m_FaceSmoothDlg);
  CComboBox::~CComboBox(this: &this->m_TextureGroupList);
  CTextureBox::~CTextureBox(this: &this->m_TextureList);
  CStatic::~CStatic(this: &this->m_TexturePic);
  CStatic::~CStatic(this: &this->m_texture);
  CButton::~CButton(this: &this->m_cExpand);
  CButton::~CButton(this: &this->m_cHideMask);
  CEdit::~CEdit(this: &this->m_cLightmapScale);
  CEdit::~CEdit(this: &this->m_rotate);
  CEdit::~CEdit(this: &this->m_scaleY);
  CEdit::~CEdit(this: &this->m_scaleX);
  CEdit::~CEdit(this: &this->m_shiftY);
  CEdit::~CEdit(this: &this->m_shiftX);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CB540
// Name: protected: void CFaceEditMaterialPage::AlignToView(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::AlignToView(CFaceEditMaterialPage *this, CMapFace *pFace)
{
  CMainFrame *MainWnd; // eax
  CFrameWnd *v3; // eax
  CView *ActiveView; // eax
  CView *v5; // esi
  void *v6; // eax
  CCamera *v7; // esi
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  CGameConfig *v19; // eax
  Vector vView; // [esp+0h] [ebp-24h] BYREF
  Vector right; // [esp+Ch] [ebp-18h] BYREF
  Vector up; // [esp+18h] [ebp-Ch] BYREF

  MainWnd = GetMainWnd();
  v3 = MainWnd->GetActiveFrame(this: MainWnd);
  if ( v3 != nullptr )
  {
    ActiveView = CFrameWnd::GetActiveView(this: v3);
    v5 = ActiveView;
    if ( ActiveView != nullptr && CObject::IsKindOf(this: ActiveView, pClass: &CMapView3D::classCMapView3D) != 0 )
    {
      v6 = __RTDynamicCast(
             inptr: v5,
             VfDelta: 0,
             SrcType: &CView `RTTI Type Descriptor',
             TargetType: &CMapView3D `RTTI Type Descriptor',
             isReference: 0);
      if ( v6 != nullptr )
      {
        v7 = *((CCamera **)v6 + 35);
        if ( v7 != nullptr )
        {
          CCamera::GetViewRight(this: v7, ViewRight: &right);
          CMapPoint::GetOrigin(this: v7, ViewUp: &up);
          CCamera::GetViewPoint(this: v7, ViewPoint: &vView);
          x = right.x;
          y = right.y;
          z = right.z;
          v11 = up.z;
          v12 = up.x;
          v13 = up.y;
          pFace->texture.UAxis.x = right.x;
          pFace->texture.UAxis.y = y;
          pFace->texture.UAxis.z = z;
          pFace->texture.VAxis.z = v11;
          v14 = (float)(vView.y * y) + (float)(vView.x * x);
          v15 = vView.z;
          v16 = vView.z * up.z;
          v17 = vView.y * v13;
          v18 = vView.x * v12;
          pFace->texture.VAxis.x = v12;
          pFace->texture.VAxis.y = v13;
          pFace->texture.UAxis.w = v14 + (float)(v15 * z);
          pFace->texture.VAxis.w = (float)(v17 + v18) + v16;
          CMapFace::NormalizeTextureShifts(this: pFace);
          pFace->texture.rotate = 0.0;
          v19 = g_pGameConfig;
          pFace->texture.scale[0] = g_pGameConfig->m_fDefaultTextureScale;
          pFace->texture.scale[1] = v19->m_fDefaultTextureScale;
          CMapFace::CalcTextureCoords(this: pFace);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB6C0
// Name: protected: void CFaceEditMaterialPage::CopyTCoordSystem(class CMapFace const __near *,class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CFaceEditMaterialPage::CopyTCoordSystem(
        CFaceEditMaterialPage *this@<ecx>,
        int a2@<edi>,
        const CMapFace *pFrom,
        CMapFace *pTo)
{
  float z; // xmm7_4
  float y; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  bool v11; // al
  float x; // xmm7_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float w; // xmm3_4
  float v18; // xmm6_4
  bool v19; // bl
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm5_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  const VMatrix *v37; // eax
  float v38; // xmm0_4
  float v39; // xmm2_4
  unsigned int v40; // xmm1_4
  unsigned int v41; // xmm2_4
  const VMatrix *v42; // eax
  VMatrix *v43; // eax
  const VMatrix *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float m_Dist; // xmm6_4
  float v50; // xmm3_4
  float v51; // xmm7_4
  float v52; // xmm4_4
  float v53; // xmm3_4
  float v54; // xmm7_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  long double v57; // [esp-4h] [ebp-200h]
  VMatrix v58; // [esp+8h] [ebp-1F4h] BYREF
  VMatrix v59; // [esp+48h] [ebp-1B4h] BYREF
  VMatrix vm; // [esp+88h] [ebp-174h] BYREF
  _BYTE v61[8]; // [esp+C8h] [ebp-134h] BYREF
  VMatrix result; // [esp+D0h] [ebp-12Ch] BYREF
  Vector vEdgePt; // [esp+110h] [ebp-ECh] BYREF
  VMatrix mOriginRotation; // [esp+11Ch] [ebp-E0h] BYREF
  VMatrix mEdgeRotation; // [esp+15Ch] [ebp-A0h] BYREF
  Vector vProjTexNormal; // [esp+19Ch] [ebp-60h] BYREF
  Vector vTextureNormal; // [esp+1A8h] [ebp-54h] BYREF
  Vector vProjPolyNormal; // [esp+1B4h] [ebp-48h] BYREF
  VPlane vp2; // [esp+1C0h] [ebp-3Ch] BYREF
  Vector vEdge; // [esp+1D0h] [ebp-2Ch] BYREF
  VPlane vp3; // [esp+1DCh] [ebp-20h]
  __int128 axis; // [esp+1ECh] [ebp-10h] OVERLAPPED BYREF
  float v73; // [esp+208h] [ebp+Ch]

  z = pFrom->plane.normal.z;
  y = pFrom->plane.normal.y;
  LODWORD(v57) = a2;
  v7 = pTo->plane.normal.z;
  v8 = pTo->plane.normal.y;
  v9 = (float)(pTo->plane.normal.x * z) - (float)(pFrom->plane.normal.x * v7);
  v10 = (float)(pFrom->plane.normal.x * v8) - (float)(pTo->plane.normal.x * y);
  vp2.m_Normal.z = (float)(y * v7) - (float)(z * v8);
  vp2.m_Dist = v9;
  vEdge.x = v10;
  VectorNormalize(vec: (Vector *)&vp2.m_Normal.z);
  vEdge.y = vp2.m_Normal.z;
  vEdge.z = vp2.m_Dist;
  vp3.m_Normal.x = vEdge.x;
  vp3.m_Normal.y = 0.0;
  vProjPolyNormal.y = pTo->plane.normal.x;
  vProjPolyNormal.z = pTo->plane.normal.y;
  vp2.m_Normal.x = pTo->plane.normal.z;
  vp2.m_Normal.y = pTo->plane.dist;
  axis = *(_OWORD *)&pFrom->plane.normal.x;
  v11 = PlaneIntersection(
          vp1: (const VPlane *)&axis,
          vp2: (const VPlane *)&vProjPolyNormal.y,
          vp3: (const VPlane *)&vEdge.y,
          vOut: (Vector *)&result.m[3][2]);
  x = pFrom->texture.UAxis.x;
  v13 = pFrom->texture.UAxis.y;
  v14 = pFrom->texture.UAxis.z;
  v15 = pFrom->texture.VAxis.y;
  v16 = pFrom->texture.VAxis.z;
  w = pFrom->texture.VAxis.w;
  v18 = pFrom->texture.UAxis.w;
  DWORD1(axis) = LODWORD(pFrom->texture.VAxis.x);
  v19 = v11;
  vp3.m_Normal.z = x;
  vp3.m_Dist = v13;
  *(float *)&axis = v14;
  *((_QWORD *)&axis + 1) = __PAIR64__(LODWORD(v16), LODWORD(v15));
  v20 = *((float *)&axis + 1) * w;
  v21 = v15 * w;
  v22 = v16 * w;
  v23 = pFrom->texture.scale[1];
  v24 = v21 * v23;
  v25 = v22 * v23;
  v26 = v20 * v23;
  v27 = v14 * v18;
  v28 = v13 * v18;
  v29 = x * v18;
  v30 = pFrom->texture.scale[0];
  vp2.m_Normal.y = (float)(v27 * v30) + v25;
  vp3.m_Normal.y = vp2.m_Normal.y;
  vProjPolyNormal.z = (float)(v29 * v30) + v26;
  vp2.m_Normal.x = (float)(v28 * v30) + v24;
  vEdge.z = vProjPolyNormal.z;
  vp3.m_Normal.x = vp2.m_Normal.x;
  vProjTexNormal.y = (float)(*((float *)&axis + 3) * vp3.m_Dist) - (float)(*((float *)&axis + 2) * *(float *)&axis);
  vProjTexNormal.z = (float)(*((float *)&axis + 1) * *(float *)&axis) - (float)(*((float *)&axis + 3) * x);
  vTextureNormal.x = (float)(*((float *)&axis + 2) * x) - (float)(*((float *)&axis + 1) * vp3.m_Dist);
  VectorNormalize(vec: (Vector *)&vProjTexNormal.y);
  if ( v19 )
  {
    v31 = (float)((float)(vProjTexNormal.z * vp2.m_Dist) + (float)(vProjTexNormal.y * vp2.m_Normal.z))
        + (float)(vTextureNormal.x * vEdge.x);
    vEdge.z = v31 * vp2.m_Normal.z;
    vp3.m_Normal.x = vp2.m_Dist * v31;
    mEdgeRotation.m[3][2] = vProjTexNormal.y - (float)(v31 * vp2.m_Normal.z);
    v32 = pTo->plane.normal.x;
    mEdgeRotation.m[3][3] = vProjTexNormal.z - (float)(vp2.m_Dist * v31);
    v33 = pTo->plane.normal.y;
    vProjTexNormal.x = vTextureNormal.x - (float)(vEdge.x * v31);
    v34 = pTo->plane.normal.z;
    v35 = (float)((float)(vp2.m_Dist * v33) + (float)(v32 * vp2.m_Normal.z)) + (float)(vEdge.x * v34);
    vTextureNormal.y = v32 - (float)(v35 * vp2.m_Normal.z);
    vTextureNormal.z = v33 - (float)(vp2.m_Dist * v35);
    vProjPolyNormal.x = v34 - (float)(vEdge.x * v35);
    VectorNormalize(vec: (Vector *)&mEdgeRotation.m[3][2]);
    VectorNormalize(vec: (Vector *)&vTextureNormal.y);
    v73 = (float)((float)(vTextureNormal.y * mEdgeRotation.m[3][2]) + (float)(vTextureNormal.z * mEdgeRotation.m[3][3]))
        + (float)(vProjPolyNormal.x * vProjTexNormal.x);
    __libm_sse2_acos(x: v57);
    v36 = v73 * 57.29577951308232;
    if ( v73 < 0.0 )
      v36 = 180.0 - v36;
    v37 = SetupMatrixAxisRot(result: (VMatrix *)v61, vAxis: (const Vector *)&vp2.m_Normal.z, fDegrees: v36);
    VMatrix::operator=(this: (VMatrix *)&mOriginRotation.m[3][2], mOther: v37);
    v38 = (float)((float)(mOriginRotation.m[3][2] * vp3.m_Normal.z) + (float)(mOriginRotation.m[3][3] * vp3.m_Dist))
        + (float)(mEdgeRotation.m[0][0] * *(float *)&axis);
    v39 = (float)((float)(mEdgeRotation.m[1][2] * vp3.m_Normal.z) + (float)(mEdgeRotation.m[1][3] * vp3.m_Dist))
        + (float)(mEdgeRotation.m[2][0] * *(float *)&axis);
    vp3.m_Dist = (float)((float)(mEdgeRotation.m[0][2] * vp3.m_Normal.z) + (float)(mEdgeRotation.m[0][3] * vp3.m_Dist))
               + (float)(mEdgeRotation.m[1][0] * *(float *)&axis);
    *(float *)&axis = v39;
    vp3.m_Normal.z = v38;
    *(float *)&v40 = (float)((float)(*((float *)&axis + 2) * mEdgeRotation.m[0][3])
                           + (float)(*((float *)&axis + 1) * mEdgeRotation.m[0][2]))
                   + (float)(*((float *)&axis + 3) * mEdgeRotation.m[1][0]);
    *(float *)&v41 = (float)((float)(*((float *)&axis + 2) * mEdgeRotation.m[1][3])
                           + (float)(*((float *)&axis + 1) * mEdgeRotation.m[1][2]))
                   + (float)(*((float *)&axis + 3) * mEdgeRotation.m[2][0]);
    *((float *)&axis + 1) = (float)((float)(*((float *)&axis + 1) * mOriginRotation.m[3][2])
                                  + (float)(*((float *)&axis + 2) * mOriginRotation.m[3][3]))
                          + (float)(*((float *)&axis + 3) * mEdgeRotation.m[0][0]);
    *((_QWORD *)&axis + 1) = __PAIR64__(v41, v40);
    v42 = SetupMatrixTranslation(result: (VMatrix *)v61, vTranslation: (const Vector *)&result.m[3][2]);
    VMatrix::operator=(this: &vm, mOther: v42);
    VMatrix::InverseGeneral(this: &vm, vInverse: (VMatrix *)v61);
    v43 = VMatrix::operator*(this: (VMatrix *)v61, result: &v58, vm: (VMatrix *)&mOriginRotation.m[3][2]);
    v44 = VMatrix::operator*(this: v43, result: &v59, &vm);
    VMatrix::operator=(this: (VMatrix *)&vEdgePt.y, mOther: v44);
    v45 = (float)((float)((float)(vEdgePt.y * vProjPolyNormal.z) + (float)(vEdgePt.z * vp2.m_Normal.x))
                + (float)(mOriginRotation.m[0][0] * vp2.m_Normal.y))
        + mOriginRotation.m[0][1];
    v46 = (float)((float)((float)(mOriginRotation.m[0][2] * vProjPolyNormal.z)
                        + (float)(mOriginRotation.m[0][3] * vp2.m_Normal.x))
                + (float)(mOriginRotation.m[1][0] * vp2.m_Normal.y))
        + mOriginRotation.m[1][1];
    v47 = (float)((float)((float)(mOriginRotation.m[1][2] * vProjPolyNormal.z)
                        + (float)(mOriginRotation.m[1][3] * vp2.m_Normal.x))
                + (float)(mOriginRotation.m[2][0] * vp2.m_Normal.y))
        + mOriginRotation.m[2][1];
  }
  else
  {
    v47 = vp3.m_Normal.y;
    v46 = vp3.m_Normal.x;
    v45 = vEdge.z;
  }
  v48 = vp3.m_Normal.z;
  m_Dist = vp3.m_Dist;
  v50 = *(float *)&axis;
  v51 = *((float *)&axis + 3);
  v52 = *((float *)&axis + 2);
  pTo->texture.UAxis.x = vp3.m_Normal.z;
  pTo->texture.UAxis.z = v50;
  v53 = *((float *)&axis + 1);
  pTo->texture.UAxis.y = m_Dist;
  pTo->texture.VAxis.z = v51;
  pTo->texture.VAxis.x = v53;
  pTo->texture.VAxis.y = v52;
  v54 = (float)(v45 * v48) + (float)(v46 * m_Dist);
  v55 = v53 * v45;
  v56 = *((float *)&axis + 3) * v47;
  pTo->texture.UAxis.w = (float)(v54 + (float)(v47 * *(float *)&axis)) / pFrom->texture.scale[0];
  pTo->texture.VAxis.w = (float)((float)(v55 + (float)(v52 * v46)) + v56) / pFrom->texture.scale[1];
  CMapFace::NormalizeTextureShifts(this: pTo);
  *(_QWORD *)pTo->texture.scale = *(_QWORD *)pFrom->texture.scale;
  pTo->texture.rotate = 0.0;
  CMapFace::CalcTextureCoords(this: pTo);
}

//------------------------------------------------------------------------------
// Address: 0x100CBDD0
// Name: public: void CFaceEditMaterialPage::SetMaterialPageTool(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::SetMaterialPageTool(CFaceEditMaterialPage *this, unsigned __int16 iMaterialTool)
{
  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = iMaterialTool;
}

//------------------------------------------------------------------------------
// Address: 0x100CBE20
// Name: protected: void CFaceEditMaterialPage::SetReadOnly(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::SetReadOnly(CFaceEditMaterialPage *this, bool bIsReadOnly)
{
  BOOL v3; // edi
  HWND DlgItem; // eax
  HWND v5; // eax
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax

  v3 = !bIsReadOnly;
  CWnd::EnableWindow(this: &this->m_shiftX, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_shiftY, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_scaleX, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_scaleY, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_rotate, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cLightmapScale, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cHideMask, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_cExpand, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_TextureList, bEnable: v3);
  CWnd::EnableWindow(this: &this->m_TextureGroupList, bEnable: v3);
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1404);
  EnableWindow(hWnd: DlgItem, bEnable: v3);
  v5 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1407);
  EnableWindow(hWnd: v5, bEnable: v3);
  v6 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1406);
  EnableWindow(hWnd: v6, bEnable: v3);
  v7 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1403);
  EnableWindow(hWnd: v7, bEnable: v3);
  v8 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1411);
  EnableWindow(hWnd: v8, bEnable: v3);
  v9 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1405);
  EnableWindow(hWnd: v9, bEnable: v3);
  v10 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1410);
  EnableWindow(hWnd: v10, bEnable: v3);
  v11 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1408);
  EnableWindow(hWnd: v11, bEnable: v3);
  v12 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1409);
  EnableWindow(hWnd: v12, bEnable: v3);
  v13 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1010);
  EnableWindow(hWnd: v13, bEnable: v3);
  v14 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1257);
  EnableWindow(hWnd: v14, bEnable: v3);
  v15 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1015);
  EnableWindow(hWnd: v15, bEnable: v3);
  v16 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1274);
  EnableWindow(hWnd: v16, bEnable: v3);
  v17 = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1582);
  EnableWindow(hWnd: v17, bEnable: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CBFD0
// Name: public: class CWnd __near * CSpinButtonCtrl::GetBuddy(void)const
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall CSpinButtonCtrl::GetBuddy(CSpinButtonCtrl *this)
{
  HWND__ *v1; // eax

  v1 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x46Au, wParam: 0, lParam: 0);
  return CWnd::FromHandle(hWnd: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100CBFF0
// Name: public: CFaceEditMaterialPage::CFaceEditMaterialPage(void)
// Source: json
//------------------------------------------------------------------------------
CFaceEditMaterialPage *__thiscall CFaceEditMaterialPage::CFaceEditMaterialPage(CFaceEditMaterialPage *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xC2u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CFaceEditMaterialPage_vtbl *)&CFaceEditMaterialPage::`vftable';
  CWnd::CWnd(this: &this->m_shiftX);
  this->m_shiftX.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_shiftY);
  this->m_shiftY.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_scaleX);
  this->m_scaleX.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_scaleY);
  this->m_scaleY.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_rotate);
  this->m_rotate.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cLightmapScale);
  this->m_cLightmapScale.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cHideMask);
  this->m_cHideMask.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_cExpand);
  this->m_cExpand.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_texture);
  this->m_texture.__vftable = (wndTex_vtbl *)&CStatic::`vftable';
  this->m_texture.__vftable = (wndTex_vtbl *)&wndTex::`vftable';
  this->m_texture.m_pTexture = nullptr;
  CWnd::CWnd(this: &this->m_TexturePic);
  this->m_TexturePic.__vftable = (wndTex_vtbl *)&CStatic::`vftable';
  this->m_TexturePic.__vftable = (wndTex_vtbl *)&wndTex::`vftable';
  this->m_TexturePic.m_pTexture = nullptr;
  CTextureBox::CTextureBox(this: &this->m_TextureList);
  CWnd::CWnd(this: &this->m_TextureGroupList);
  this->m_TextureGroupList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CFaceSmoothingDlg::CFaceSmoothingDlg(this: &this->m_FaceSmoothDlg, pParent: nullptr);
  this->m_bHideMask = 0;
  this->m_bInitialized = 0;
  this->m_bIgnoreResize = 0;
  this->m_bTreatAsOneFace = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CC210
// Name: void FloatToSpin(float,class CSpinButtonCtrl __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloatToSpin(float fValue, CSpinButtonCtrl *pSpin, int bMantissa)
{
  HWND__ *v3; // eax
  CWnd *v4; // ebx
  unsigned __int16 v5; // ax
  double v6; // [esp-8h] [ebp-114h]
  char szString[8]; // [esp+Ch] [ebp-100h] BYREF
  char szCurrent[128]; // [esp+14h] [ebp-F8h] BYREF

  v3 = (HWND__ *)SendMessageA(hWnd: pSpin->m_hWnd, Msg: 0x46Au, wParam: 0, lParam: 0);
  v4 = CWnd::FromHandle(hWnd: v3);
  if ( fValue == -99999.0 )
  {
    szCurrent[120] = 0;
  }
  else
  {
    v6 = fValue;
    if ( bMantissa != 0 )
      sprintf(string: &szCurrent[120], format: "%.2f", v6);
    else
      sprintf(string: &szCurrent[120], format: "%.0f", v6);
  }
  v5 = atoi(nptr: &szCurrent[120]);
  SendMessageA(hWnd: pSpin->m_hWnd, Msg: 0x467u, wParam: 0, lParam: v5);
  CWnd::GetWindowTextA(this: v4, lpszString: szString, nMaxCount: 128);
  if ( strcmp(&szCurrent[120], szString) != 0 )
    CWnd::SetWindowTextA(this: v4, lpszString: &szCurrent[120]);
}

//------------------------------------------------------------------------------
// Address: 0x100CC300
// Name: void IntegerToSpin(int,class CSpinButtonCtrl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IntegerToSpin(int nValue, CSpinButtonCtrl *pSpin)
{
  HWND__ *v2; // eax
  CWnd *v3; // ebx
  unsigned __int16 v4; // ax
  char szCurrent[128]; // [esp+Ch] [ebp-100h] BYREF
  char szNew[128]; // [esp+8Ch] [ebp-80h] BYREF

  v2 = (HWND__ *)SendMessageA(hWnd: pSpin->m_hWnd, Msg: 0x46Au, wParam: 0, lParam: 0);
  v3 = CWnd::FromHandle(hWnd: v2);
  if ( nValue == -99999 )
    szNew[0] = 0;
  else
    sprintf(string: szNew, format: "%d", abs32(nValue));
  v4 = atoi(nptr: szNew);
  SendMessageA(hWnd: pSpin->m_hWnd, Msg: 0x467u, wParam: 0, lParam: v4);
  CWnd::GetWindowTextA(this: v3, lpszString: szCurrent, nMaxCount: 128);
  if ( strcmp(szNew, szCurrent) != 0 )
    CWnd::SetWindowTextA(this: v3, lpszString: szNew);
}

//------------------------------------------------------------------------------
// Address: 0x100CC3D0
// Name: protected: void CFaceEditMaterialPage::OnHideMask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnHideMask(CFaceEditMaterialPage *this)
{
  LRESULT v2; // eax

  v2 = SendMessageA(hWnd: this->m_cHideMask.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  this->m_bHideMask = v2;
  CMapFace::SetShowSelection(bShowSelection: v2 == 0);
  CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 69, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100CC420
// Name: protected: int CFaceEditMaterialPage::OnSwitchMode(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditMaterialPage::OnSwitchMode(CFaceEditMaterialPage *this, unsigned int id)
{
  CWnd *DlgItem; // edi
  HWND Parent; // eax
  int result; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1274);
  Parent = GetParent(hWnd: this->m_hWnd);
  HIDWORD(CWnd::FromHandle(hWnd: Parent)[49].m_ulGestureArg) = id;
  switch ( id )
  {
    case 0x101u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Mode: Lift+Select");
      result = 1;
      break;
    case 0x102u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Mode: Lift");
      result = 1;
      break;
    case 0x103u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Mode: Select");
      result = 1;
      break;
    case 0x104u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Mode: Apply (texture)");
      result = 1;
      break;
    case 0x105u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Mode: Apply (all)");
      result = 1;
      break;
    case 0x107u:
      CWnd::SetWindowTextA(this: DlgItem, lpszString: "Align To View");
      goto LABEL_8;
    default:
LABEL_8:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CC510
// Name: protected: void CFaceEditMaterialPage::OnMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnMode(CFaceEditMaterialPage *this)
{
  HMENU PopupMenu; // eax
  CWnd *DlgItem; // eax
  CRect r; // [esp+Ch] [ebp-24h] BYREF
  CMenu menu; // [esp+1Ch] [ebp-14h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = 1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  menu.m_hMenu = nullptr;
  v6 = 0;
  PopupMenu = CreatePopupMenu();
  CMenu::Attach(this: &menu, hMenu: PopupMenu);
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x101u, lpNewItem: "Lift+Select");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x102u, lpNewItem: "Lift");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x103u, lpNewItem: "Select");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x104u, lpNewItem: "Apply (texture only)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x105u, lpNewItem: "Apply (texture + values)");
  AppendMenuA(hMenu: menu.m_hMenu, uFlags: 0, uIDNewItem: 0x107u, lpNewItem: "Align To View");
  DlgItem = CWnd::GetDlgItem(this, nID: 1274);
  memset(&r, 0, sizeof(r));
  GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
  CMenu::TrackPopupMenu(this: &menu, nFlags: 0, x: r.left, y: r.bottom, pWnd: this, lpRect: nullptr);
  v6 = -1;
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
}

//------------------------------------------------------------------------------
// Address: 0x100CC650
// Name: protected: void CFaceEditMaterialPage::OnTreatAsOne(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnTreatAsOne(CFaceEditMaterialPage *this)
{
  CWnd *DlgItem; // eax

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = 1;
  DlgItem = CWnd::GetDlgItem(this, nID: 1410);
  this->m_bTreatAsOneFace = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100CC6B0
// Name: protected: void CFaceEditMaterialPage::UpdateTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::UpdateTexture(CFaceEditMaterialPage *this)
{
  WPARAM v2; // eax
  IEditorTexture *v3; // eax
  IEditorTexture *m_pCurTex; // edi
  int v5; // eax
  int v6; // eax
  CWnd *DlgItem; // eax
  int v8; // [esp-4h] [ebp-10Ch]
  char szTexName[128]; // [esp+8h] [ebp-100h] BYREF
  char szBuf[128]; // [esp+88h] [ebp-80h] BYREF

  v2 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
  {
    wndTex::SetTexture(this: &this->m_TexturePic, pTex: nullptr);
    this->m_pCurTex = nullptr;
  }
  else
  {
    v3 = (IEditorTexture *)SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    this->m_pCurTex = v3;
    wndTex::SetTexture(this: &this->m_TexturePic, pTex: v3);
    if ( this->m_pCurTex != nullptr )
    {
      m_pCurTex = this->m_pCurTex;
      v5 = m_pCurTex->GetHeight(this: m_pCurTex);
      v6 = ((int (__thiscall *)(IEditorTexture *, int))m_pCurTex->GetWidth)(a1: m_pCurTex, a2: v5);
      sprintf(string: szBuf, format: "%dx%d", v6, v8);
      DlgItem = CWnd::GetDlgItem(this, nID: 1027);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: szBuf);
      this->m_pCurTex->GetShortName(this: this->m_pCurTex, a2: szTexName);
      SetDefaultTextureName(szTexName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC790
// Name: protected: void CFaceEditMaterialPage::SelectTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::SelectTexture(CFaceEditMaterialPage *this, const char *pszTextureName)
{
  WPARAM v3; // edi
  IEditorTexture *v4; // eax
  IEditorTexture *pTex; // [esp+Ch] [ebp-4h]

  v3 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)pszTextureName);
  if ( v3 == -1 )
  {
    pTex = CTextureSystem::FindActiveTexture(
             this: &g_Textures,
             pszInputName: pszTextureName,
             piIndex: nullptr,
             bDummy: 1);
    if ( pTex != nullptr )
    {
      v3 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)pszTextureName);
      SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x151u, wParam: v3, lParam: (LPARAM)pTex);
      SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x14Eu, wParam: v3, lParam: 0);
    }
  }
  CFaceEditMaterialPage::UpdateTexture(this);
  if ( v3 != -1 )
  {
    v4 = (IEditorTexture *)SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
    CTextureBox::AddMRU(this: &this->m_TextureList, pTex: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC840
// Name: protected: void CFaceEditMaterialPage::OnBrowse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnBrowse(CFaceEditMaterialPage *this)
{
  CTextureBrowser *pTextureBrowser; // edi
  WPARAM v3; // eax
  LRESULT v4; // eax
  WPARAM v5; // edi
  IEditorTexture *v6; // eax
  char sz[128]; // [esp+Ch] [ebp-88h] BYREF
  int iCount; // [esp+8Ch] [ebp-8h]
  IEditorTexture *pTex; // [esp+90h] [ebp-4h]

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = 1;
  pTextureBrowser = GetMainWnd()->pTextureBrowser;
  v3 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(LRESULT, char *))(*(_DWORD *)v4 + 36))(a1: v4, a2: sz);
      CTextureBrowser::SetInitialTexture(this: pTextureBrowser, pszTexture: sz);
    }
  }
  if ( pTextureBrowser->DoModal(this: pTextureBrowser) == 1 )
  {
    pTex = CTextureSystem::FindActiveTexture(
             this: &g_Textures,
             pszInputName: pTextureBrowser->m_cTextureWindow.szCurTexture,
             piIndex: nullptr,
             bDummy: 1);
    if ( pTex != nullptr )
    {
      v5 = 0;
      iCount = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
      if ( iCount > 0 )
      {
        while ( 1 )
        {
          v6 = (IEditorTexture *)SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v5, lParam: 0);
          if ( pTex == v6 )
            break;
          if ( (int)++v5 >= iCount )
            return;
        }
        SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x14Eu, wParam: v5, lParam: 0);
        CFaceEditMaterialPage::UpdateTexture(this);
        CTextureBox::AddMRU(this: &this->m_TextureList, pTex);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CC980
// Name: protected: void CFaceEditMaterialPage::OnChangeTextureGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnChangeTextureGroup(CFaceEditMaterialPage *this)
{
  WPARAM v2; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-11Ch]
  char szName[260]; // [esp+8h] [ebp-104h] BYREF

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  m_hWnd = this->m_TextureGroupList.m_hWnd;
  this->m_iMaterialTool = 1;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x148u, wParam: v2, lParam: (LPARAM)szName);
  CTextureSystem::SetActiveGroup(this: &g_Textures, pcszName: szName);
  CTextureBox::LoadGraphicList(this: &this->m_TextureList);
}

//------------------------------------------------------------------------------
// Address: 0x100CCA10
// Name: public: virtual int CFaceEditMaterialPage::OnSetActive(void)
// Source: json
//------------------------------------------------------------------------------
CMainFrame *__thiscall CFaceEditMaterialPage::OnSetActive(CFaceEditMaterialPage *this)
{
  CMainFrame *result; // eax
  CToolManager *v3; // eax

  result = GetMainWnd();
  if ( result != nullptr )
  {
    v3 = ToolManager();
    CToolManager::SetTool(this: v3, eNewTool: TOOL_FACEEDIT_MATERIAL);
    if ( this->m_iMaterialTool == 2 )
      this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
    this->m_iMaterialTool = 1;
    return (CMainFrame *)CPropertyPage::OnSetActive(this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CCA60
// Name: protected: void CFaceEditMaterialPage::OnButtonSmoothingGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnButtonSmoothingGroups(CFaceEditMaterialPage *this)
{
  if ( this->m_FaceSmoothDlg.Create(this: &this->m_FaceSmoothDlg, a2: 318u, a3: this) != 0 )
  {
    CWnd::ShowWindow(this: &this->m_FaceSmoothDlg, nCmdShow: 5);
    if ( this->m_iMaterialTool == 2 )
      this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
    this->m_iMaterialTool = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CCAC0
// Name: public: void CFaceEditMaterialPage::NotifyNewMaterial(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::NotifyNewMaterial(CFaceEditMaterialPage *this, IEditorTexture *pTex)
{
  CTextureBox::LoadGraphicList(this: &this->m_TextureList);
  CFaceEditMaterialPage::UpdateTexture(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CCAE0
// Name: public: void CFaceEditMaterialPage::OnBnClickedFaceMarkButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnBnClickedFaceMarkButton(CFaceEditMaterialPage *this)
{
  CMapDoc *v1; // ebx
  WPARAM v3; // eax
  LRESULT v4; // eax
  char sz[128]; // [esp+8h] [ebp-80h] BYREF

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      v4 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(LRESULT, char *))(*(_DWORD *)v4 + 36))(a1: v4, a2: sz);
        CMapDoc::ReplaceTextures(
          this: v1,
          pszFind: sz,
          pszReplace: &var,
          bEverything: 1,
          iAction: 0x100u,
          bHidden: 0,
          bRescaleTextureCoordinates: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CCB60
// Name: protected: void CFaceEditMaterialPage::GetAllFaceExtents(class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::GetAllFaceExtents(CFaceEditMaterialPage *this, Vector *Extents)
{
  int v2; // edi
  HWND Parent; // eax
  CFaceEditSheet *v4; // ecx
  int m_Size; // eax
  int v7; // ebx
  float x; // xmm1_4
  float z; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  Vector FaceExtents[6]; // [esp+4h] [ebp-4Ch] BYREF
  CFaceEditSheet *pSheet; // [esp+4Ch] [ebp-4h]
  Vector *Extentsa; // [esp+58h] [ebp+8h]

  v2 = 1;
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = (CFaceEditSheet *)CWnd::FromHandle(hWnd: Parent);
  m_Size = v4->m_Faces.m_Size;
  pSheet = v4;
  if ( m_Size > 0 )
  {
    v7 = 0;
    Extentsa = (Vector *)m_Size;
    while ( 1 )
    {
      CMapFace::GetFaceExtents(this: v4->m_Faces.m_Memory.m_pMemory[v7].pMapFace, Extents: FaceExtents);
      if ( Extents->x > FaceExtents[0].x || v2 != 0 )
        *Extents = FaceExtents[0];
      if ( FaceExtents[1].x > Extents[1].x || v2 != 0 )
        Extents[1] = FaceExtents[1];
      if ( Extents[2].y > FaceExtents[2].y || v2 != 0 )
      {
        x = FaceExtents[2].x;
        Extents[2].y = FaceExtents[2].y;
        z = FaceExtents[2].z;
        Extents[2].x = x;
        Extents[2].z = z;
      }
      if ( FaceExtents[3].y > Extents[3].y || v2 != 0 )
      {
        v10 = FaceExtents[3].x;
        Extents[3].y = FaceExtents[3].y;
        v11 = FaceExtents[3].z;
        Extents[3].x = v10;
        Extents[3].z = v11;
      }
      v12 = FaceExtents[4].z;
      if ( Extents[4].z > FaceExtents[4].z || v2 != 0 )
      {
        Extents[4].x = FaceExtents[4].x;
        Extents[4].y = FaceExtents[4].y;
        Extents[4].z = v12;
      }
      v13 = FaceExtents[5].z;
      if ( FaceExtents[5].z > Extents[5].z || v2 != 0 )
      {
        Extents[5].x = FaceExtents[5].x;
        Extents[5].y = FaceExtents[5].y;
        Extents[5].z = v13;
      }
      v2 = 0;
      ++v7;
      Extentsa = (Vector *)((char *)Extentsa - 1);
      if ( Extentsa == nullptr )
        break;
      v4 = pSheet;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CCCD0
// Name: protected: void CFaceEditMaterialPage::OnSelChangeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnSelChangeTexture(CFaceEditMaterialPage *this)
{
  bool v2; // zf

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  v2 = this->m_bInitialized == 0;
  this->m_iMaterialTool = 1;
  if ( !v2 )
  {
    CFaceEditMaterialPage::UpdateTexture(this);
    if ( this->m_pCurTex != nullptr )
      CTextureBox::AddMRU(this: &this->m_TextureList, pTex: this->m_pCurTex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CCD30
// Name: void TransferToFloat(class CWnd __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferToFloat(CWnd *pWnd, float *fValue)
{
  CAfxStringMgr *StringManager; // eax
  char *v3; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v5 = 1;
  CWnd::GetWindowTextA(this: pWnd, rString: &str);
  if ( *((_DWORD *)str.m_pszData - 3) != 0 )
    *fValue = atof(nptr: str.m_pszData);
  v5 = -1;
  v3 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CCDD0
// Name: void TransferToInteger(class CWnd __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferToInteger(CWnd *pWnd, int *nValue)
{
  CAfxStringMgr *StringManager; // eax
  char *v3; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v5 = 1;
  CWnd::GetWindowTextA(this: pWnd, rString: &str);
  if ( *((_DWORD *)str.m_pszData - 3) != 0 )
    *nValue = abs32(atoi(nptr: str.m_pszData));
  v5 = -1;
  v3 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CCE80
// Name: public: void CFaceEditMaterialPage::NotifyGraphicsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::NotifyGraphicsChanged(CFaceEditMaterialPage *this)
{
  CAfxStringMgr *StringManager; // eax
  LRESULT v3; // eax
  int v4; // ebx
  TextureContext_t *m_pActiveContext; // eax
  int v6; // ecx
  CTextureGroup *v7; // ebx
  int v8; // eax
  LPARAM v9; // eax
  WPARAM v10; // eax
  char *v11; // eax
  char szName[260]; // [esp+4h] [ebp-120h] BYREF
  int iCurSel; // [esp+108h] [ebp-1Ch]
  int nCount; // [esp+10Ch] [ebp-18h]
  int i; // [esp+110h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+114h] [ebp-10h] BYREF
  int v17; // [esp+120h] [ebp-4h]

  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v17 = 1;
    v3 = SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    v4 = v3;
    iCurSel = v3;
    if ( v3 != -1 )
      CComboBox::GetLBText(this: &this->m_TextureGroupList, nIndex: v3, rString: &str);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"All Textures");
    m_pActiveContext = g_Textures.m_pActiveContext;
    if ( g_Textures.m_pActiveContext != nullptr )
    {
      nCount = g_Textures.m_pActiveContext->Groups.m_Size;
      if ( nCount > 1 )
      {
        v6 = 1;
        i = 1;
        do
        {
          if ( m_pActiveContext != nullptr )
            v7 = m_pActiveContext->Groups.m_Memory.m_pMemory[v6];
          else
            v7 = nullptr;
          if ( v7->m_eTextureFormat == g_pGameConfig->textureformat )
          {
            strstr(str1: (unsigned __int8 *)v7, str2: "textures\\");
            if ( v8 != 0 )
              v9 = v8 + 9;
            else
              v9 = (LPARAM)v7;
            SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: v9);
            v6 = i;
          }
          m_pActiveContext = g_Textures.m_pActiveContext;
          i = ++v6;
        }
        while ( v6 < nCount );
        v4 = iCurSel;
      }
    }
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    if ( v4 == -1
      || SendMessageA(
           hWnd: this->m_TextureGroupList.m_hWnd,
           Msg: 0x14Du,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)str.m_pszData) == -1 )
    {
      SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
    InvalidateRect(hWnd: this->m_TextureGroupList.m_hWnd, lpRect: nullptr, bErase: true);
    v10 = SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x148u, wParam: v10, lParam: (LPARAM)szName);
    CTextureSystem::SetActiveGroup(this: &g_Textures, pcszName: szName);
    CTextureBox::LoadGraphicList(this: &this->m_TextureList);
    CFaceEditMaterialPage::UpdateTexture(this);
    v17 = -1;
    v11 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD0B0
// Name: public: void CFaceEditMaterialPage::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::Init(CFaceEditMaterialPage *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  CWnd *v8; // edi
  HWND Parent; // eax

  CWnd::SubclassDlgItem(this: &this->m_shiftX, nID: 0x47Du, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_shiftY, nID: 0x478u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_scaleX, nID: 0x3F1u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_scaleY, nID: 0x47Eu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_rotate, nID: 0x3FFu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cHideMask, nID: 0x50Eu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cExpand, nID: 0x54Eu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cLightmapScale, nID: 0x56Du, pParent: this);
  DlgItem = CWnd::GetDlgItem(this, nID: 1008);
  PostMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x465u, wParam: 0, lParam: -67107840);
  v3 = CWnd::GetDlgItem(this, nID: 1184);
  PostMessageA(hWnd: v3->m_hWnd, Msg: 0x465u, wParam: 0, lParam: -67107840);
  v4 = CWnd::GetDlgItem(this, nID: 1185);
  PostMessageA(hWnd: v4->m_hWnd, Msg: 0x465u, wParam: 0, lParam: -23527065);
  v5 = CWnd::GetDlgItem(this, nID: 1355);
  PostMessageA(hWnd: v5->m_hWnd, Msg: 0x465u, wParam: 0, lParam: -2147385345);
  v6 = CWnd::GetDlgItem(this, nID: 1356);
  PostMessageA(hWnd: v6->m_hWnd, Msg: 0x465u, wParam: 0, lParam: -2147385345);
  v7 = CWnd::GetDlgItem(this, nID: 1011);
  PostMessageA(hWnd: v7->m_hWnd, Msg: 0x465u, wParam: 0, lParam: 98303);
  v8 = CWnd::GetDlgItem(this, nID: 1274);
  Parent = GetParent(hWnd: this->m_hWnd);
  HIDWORD(CWnd::FromHandle(hWnd: Parent)[49].m_ulGestureArg) = 257;
  CWnd::SetWindowTextA(this: v8, lpszString: "Mode: Lift+Select");
  CWnd::SubclassDlgItem(this: &this->m_TextureGroupList, nID: 0x486u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_TextureList, nID: 0x3EFu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_TexturePic, nID: 0x455u, pParent: this);
  this->m_pCurTex = nullptr;
  CFaceEditMaterialPage::NotifyGraphicsChanged(this);
  CFaceEditMaterialPage::UpdateTexture(this);
  this->m_bInitialized = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CD290
// Name: public: void CFaceEditMaterialPage::Apply(class CMapFace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::Apply(CFaceEditMaterialPage *this, CMapFace *pOnlyFace, char flags)
{
  CFaceEditMaterialPage *v3; // ebx
  CAfxStringMgr *StringManager; // eax
  int m_nGrowSize; // esi
  IEditorTexture *m_pTexture; // ecx
  CMapFace *v7; // edi
  CHistory *History; // eax
  int v9; // edi
  int m_nAllocationCount; // ebx
  HWND Parent; // eax
  float v12; // ecx
  char *v13; // edx
  int v14; // eax
  CHistory *v15; // eax
  int v16; // ebx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v17; // ebx
  HWND v18; // eax
  CWnd *v19; // eax
  int y; // esi
  int v21; // eax
  int v22; // eax
  CMapAtom *v23; // eax
  CMapClass *v24; // eax
  CMapClass *v25; // esi
  unsigned int j; // esi
  CWnd *DlgItem; // eax
  LRESULT v28; // eax
  CMapClass *v29; // [esp+0h] [ebp-270h]
  char pszName[4]; // [esp+10h] [ebp-260h] BYREF
  char szCurrentTexName[260]; // [esp+14h] [ebp-25Ch] BYREF
  char szNewTexName[260]; // [esp+118h] [ebp-158h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+21Ch] [ebp-54h]
  CMapSolid *pSolid; // [esp+220h] [ebp-50h] BYREF
  float fshiftX; // [esp+224h] [ebp-4Ch] BYREF
  IEditorTexture *fscaleY; // [esp+228h] [ebp-48h]
  IEditorTexture *pTex; // [esp+22Ch] [ebp-44h] BYREF
  int fshiftY; // [esp+230h] [ebp-40h] BYREF
  int nLightmapScale; // [esp+234h] [ebp-3Ch] BYREF
  int fscaleX; // [esp+238h] [ebp-38h] BYREF
  CUtlVector<CMapSolid *,CUtlMemory<CMapSolid *,int> > kept; // [esp+23Ch] [ebp-34h] BYREF
  CMapDoc *pMapDoc; // [esp+250h] [ebp-20h] BYREF
  float frotate; // [esp+254h] [ebp-1Ch]
  CFaceEditSheet *pSheet; // [esp+258h] [ebp-18h]
  int i; // [esp+25Ch] [ebp-14h]
  int faceCount; // [esp+260h] [ebp-10h]
  int v47; // [esp+26Ch] [ebp-4h]

  v3 = this;
  i = (int)this;
  StringManager = AfxGetStringManager();
  m_nGrowSize = 0;
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  *(_DWORD *)&szNewTexName[256] = StringManager->GetNilString(this: StringManager) + 1;
  v47 = 1;
  m_pTexture = v3->m_TexturePic.m_pTexture;
  *(float *)&pSolid = -99999.0;
  *(float *)&pTex = -99999.0;
  *(float *)&nLightmapScale = -99999.0;
  fshiftX = -99999.0;
  *(float *)&pMapDoc = -99999.0;
  fshiftY = -99999;
  fscaleY = m_pTexture;
  kept.m_pElements = (CMapSolid **)CMapDoc::m_pMapDoc;
  if ( (flags & 2) != 0 )
  {
    TransferToFloat(pWnd: &v3->m_shiftX, fValue: (float *)&pSolid);
    TransferToFloat(pWnd: &v3->m_shiftY, fValue: (float *)&pTex);
    TransferToFloat(pWnd: &v3->m_scaleX, fValue: (float *)&nLightmapScale);
    TransferToFloat(pWnd: &v3->m_scaleY, fValue: &fshiftX);
    TransferToFloat(pWnd: &v3->m_rotate, fValue: (float *)&pMapDoc);
  }
  if ( (flags & 4) != 0 )
    TransferToInteger(pWnd: &v3->m_cLightmapScale, nValue: &fshiftY);
  v7 = pOnlyFace;
  if ( pOnlyFace == nullptr )
  {
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Apply Face Attributes", bFromOpposite: 0);
    flags |= 7u;
    v9 = 0;
    fscaleX = 0;
    m_nAllocationCount = 0;
    memset(&kept, 0, 16);
    LOBYTE(v47) = 3;
    Parent = GetParent(hWnd: *(HWND *)(i + 32));
    v12 = COERCE_FLOAT(CWnd::FromHandle(hWnd: Parent));
    frotate = v12;
    pSheet = nullptr;
    if ( *(int *)(LODWORD(v12) + 5748) > 0 )
    {
      faceCount = 0;
      do
      {
        v13 = *(char **)(faceCount + *(_DWORD *)(LODWORD(v12) + 5736) + 8);
        v14 = 0;
        str.m_pszData = v13;
        if ( m_nGrowSize <= 0 )
          goto LABEL_15;
        while ( *(char **)(v9 + 4 * v14) != v13 )
        {
          if ( ++v14 >= m_nGrowSize )
            goto LABEL_15;
        }
        if ( v14 == -1 )
        {
LABEL_15:
          v29 = (CMapClass *)v13;
          v15 = GetHistory();
          CHistory::Keep(this: v15, pObject: v29);
          v16 = m_nGrowSize;
          if ( m_nGrowSize + 1 > (int)kept.m_Memory.m_pMemory )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&fscaleX,
              num: m_nGrowSize - (unsigned int)kept.m_Memory.m_pMemory + 1);
            m_nGrowSize = kept.m_Memory.m_nGrowSize;
            v9 = fscaleX;
          }
          kept.m_Memory.m_nGrowSize = ++m_nGrowSize;
          kept.m_Size = v9;
          if ( m_nGrowSize - v16 - 1 > 0 )
            _V_memmove(
              dest: (void *)(v9 + 4 * v16 + 4),
              src: (const void *)(v9 + 4 * v16),
              count: 4 * (m_nGrowSize - v16 - 1));
          v12 = frotate;
          v17 = (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)(v9 + 4 * v16);
          if ( v17 != nullptr )
            v17->m_pszData = str.m_pszData;
        }
        faceCount += 12;
        pSheet = (CFaceEditSheet *)((char *)pSheet + 1);
      }
      while ( (int)pSheet < *(_DWORD *)(LODWORD(v12) + 5748) );
      m_nAllocationCount = kept.m_Memory.m_nAllocationCount;
    }
    LOBYTE(v47) = 4;
    kept.m_Memory.m_nGrowSize = 0;
    if ( m_nAllocationCount >= 0 )
    {
      if ( v9 != 0 )
      {
        free(pMem: (void *)v9);
        v9 = 0;
        fscaleX = 0;
      }
      kept.m_Memory.m_pMemory = nullptr;
    }
    kept.m_Size = v9;
    LOBYTE(v47) = 1;
    if ( m_nAllocationCount >= 0 )
    {
      if ( v9 != 0 )
      {
        free(pMem: (void *)v9);
        fscaleX = 0;
      }
      kept.m_Memory.m_pMemory = nullptr;
    }
    v7 = nullptr;
    v3 = (CFaceEditMaterialPage *)i;
  }
  v18 = GetParent(hWnd: v3->m_hWnd);
  v19 = CWnd::FromHandle(hWnd: v18);
  y = v19[49].m_ptGestureFrom.y;
  LODWORD(frotate) = v19;
  i = y;
  pSheet = nullptr;
  faceCount = 0;
  while ( 1 )
  {
    if ( (int)pSheet < y )
    {
      if ( v7 == nullptr )
        v7 = *(CMapFace **)(*(_DWORD *)(LODWORD(frotate) + 5736) + faceCount + 4);
    }
    else if ( v7 == nullptr )
    {
      break;
    }
    if ( (flags & 2) != 0 && (flags & 8) == 0 )
    {
      if ( *(float *)&pSolid != -99999.0 )
        v7->texture.UAxis.w = *(float *)&pSolid;
      if ( *(float *)&pTex != -99999.0 )
        v7->texture.VAxis.w = *(float *)&pTex;
      if ( *(float *)&nLightmapScale != -99999.0 )
        v7->texture.scale[0] = *(float *)&nLightmapScale;
      if ( fshiftX != -99999.0 )
        v7->texture.scale[1] = fshiftX;
      if ( *(float *)&pMapDoc != -99999.0 )
      {
        CMapFace::RotateTextureAxes(this: v7, fDegrees: *(float *)&pMapDoc - v7->texture.rotate);
        v7->texture.rotate = *(float *)&pMapDoc;
      }
    }
    if ( (flags & 4) != 0 )
    {
      v22 = fshiftY;
      if ( fshiftY != -99999 )
      {
        if ( fshiftY <= 1 )
          v22 = 1;
        v7->texture.nLightmapScale = v22;
      }
    }
    if ( (flags & 1) != 0 && fscaleY != nullptr )
    {
      CMapFace::GetTextureName(this: v7, pszName);
      fscaleY->GetShortName(this: fscaleY, a2: &szCurrentTexName[256]);
      if ( _V_stricmp(s1: pszName, s2: &szCurrentTexName[256]) != 0 )
      {
        CMapFace::SetTexture(this: v7, pszNewTex: &szCurrentTexName[256], bRescaleTextureCoordinates: false);
        v23 = v7->GetParent(this: v7);
        v24 = (CMapClass *)__RTDynamicCast(
                             inptr: v23,
                             VfDelta: 0,
                             SrcType: &CMapAtom `RTTI Type Descriptor',
                             TargetType: &CMapClass `RTTI Type Descriptor',
                             isReference: 0);
        v25 = v24;
        if ( v24 != nullptr )
        {
          CMapDoc::RemoveFromAutoVisGroups(this: (CMapDoc *)kept.m_pElements, pObject: v24);
          CMapDoc::AddToAutoVisGroup(this: (CMapDoc *)kept.m_pElements, pObject: v25);
        }
        y = i;
      }
    }
    if ( (flags & 8) != 0 && y >= 1 )
      CFaceEditMaterialPage::CopyTCoordSystem(
        this: v3,
        a2: (int)v7,
        pFrom: *(const CMapFace **)(*(_DWORD *)(LODWORD(frotate) + 5736) + 12 * y - 8),
        pTo: v7);
    CMapFace::CalcTextureCoords(this: v7);
    if ( (flags & 0x10) != 0 )
    {
      CFaceEditMaterialPage::m_FaceContents = v7->texture.q2contents;
      CFaceEditMaterialPage::m_FaceSurface = v7->texture.q2surface;
      for ( j = 0; j < 30; j += 3 )
      {
        DlgItem = CWnd::GetDlgItem(this: v3, nID: FaceAttributes[j / 3].uControlID);
        if ( DlgItem != nullptr )
        {
          v28 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
          if ( v28 != 0 )
          {
            if ( v28 == 1 )
              *(&off_1072F7DC)[j] |= dword_1072F7E0[j];
          }
          else
          {
            *(&off_1072F7DC)[j] &= ~dword_1072F7E0[j];
          }
        }
      }
      y = i;
      v7->texture.q2contents = CFaceEditMaterialPage::m_FaceContents;
      v7->texture.q2surface = CFaceEditMaterialPage::m_FaceSurface;
    }
    if ( pOnlyFace != nullptr )
      break;
    pSheet = (CFaceEditSheet *)((char *)pSheet + 1);
    faceCount += 12;
    v7 = nullptr;
  }
  ((void (__thiscall *)(CMapSolid **, int))LODWORD((*kept.m_pElements)->m_Render2DBox.bmins.x))(
    a1: kept.m_pElements,
    a2: 1);
  v47 = -1;
  v21 = *(_DWORD *)&szNewTexName[256] - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(*(_DWORD *)&szNewTexName[256] - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v21 + 4))(a1: v21);
}

//------------------------------------------------------------------------------
// Address: 0x100CD7B0
// Name: protected: void CFaceEditMaterialPage::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnVScroll(
        CFaceEditMaterialPage *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CFaceEditMaterialPage::Apply(this, pOnlyFace: nullptr, flags: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100CD7C0
// Name: protected: void CFaceEditMaterialPage::OnDeltaPosFloatSpin(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnDeltaPosFloatSpin(CFaceEditMaterialPage *this, tagNMHDR *pNMHDR, int *pResult)
{
  tagNMHDR *v3; // edi
  CEdit *p_m_scaleX; // esi
  CAfxStringMgr *StringManager; // eax
  unsigned int *p_code; // eax
  float v7; // [esp+10h] [ebp-10h]

  v3 = pNMHDR;
  if ( pNMHDR->idFrom == 1355 )
  {
    p_m_scaleX = &this->m_scaleX;
  }
  else
  {
    if ( pNMHDR->idFrom != 1356 )
      return;
    p_m_scaleX = &this->m_scaleY;
  }
  if ( p_m_scaleX != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pNMHDR = (tagNMHDR *)&StringManager->GetNilString(this: StringManager)[1];
    CWnd::GetWindowTextA(
      this: p_m_scaleX,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR);
    v7 = atof(nptr: (const char *)pNMHDR);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR,
      pszFormat: "%.2f",
      (float)((float)((float)(int)v3[1].idFrom * 0.1) + v7));
    CWnd::SetWindowTextA(this: p_m_scaleX, lpszString: (const char *)pNMHDR);
    *pResult = 0;
    p_code = &pNMHDR[-2].code;
    if ( _InterlockedDecrement((volatile signed __int32 *)&pNMHDR[-1].code) <= 0 )
      (*(void (__stdcall **)(unsigned int *))(*(_DWORD *)*p_code + 4))(a1: p_code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CD8D0
// Name: protected: void CFaceEditMaterialPage::OnCheckUnCheck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnCheckUnCheck(CFaceEditMaterialPage *this)
{
  CFaceEditMaterialPage::Apply(this, pOnlyFace: nullptr, flags: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100CD8E0
// Name: protected: void CFaceEditMaterialPage::OnButtonApply(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnButtonApply(CFaceEditMaterialPage *this)
{
  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = 1;
  CFaceEditMaterialPage::Apply(this, pOnlyFace: nullptr, flags: 7);
}

//------------------------------------------------------------------------------
// Address: 0x100CD920
// Name: protected: void CFaceEditMaterialPage::OnReplace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::OnReplace(CFaceEditMaterialPage *this)
{
  CMapDoc *v2; // esi
  int ActiveTool; // eax
  const char *DefaultTextureName; // eax
  int v5; // ecx
  CHistory *History; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-2A8h]
  CReplaceTexDlg dlg; // [esp+4h] [ebp-298h] BYREF
  int v9; // [esp+298h] [ebp-4h]

  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  this->m_iMaterialTool = 1;
  v2 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: CMapDoc::m_pMapDoc->m_pSelection);
    CReplaceTexDlg::CReplaceTexDlg(this: &dlg, nSelected: ActiveTool, pParent: nullptr);
    v9 = 0;
    DefaultTextureName = GetDefaultTextureName();
    if ( DefaultTextureName != nullptr )
      v5 = strlen(DefaultTextureName);
    else
      v5 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &dlg.m_strFind, pszSrc: DefaultTextureName, nLength: v5);
    if ( CDialog::DoModal(this: &dlg) == 1 )
    {
      List = CSelection::GetList(this: v2->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Replace Textures", bFromOpposite: 0);
      if ( dlg.m_bMarkOnly != 0 )
        CMapDoc::SelectObject(this: v2, pObj: nullptr, cmd: 16);
      CReplaceTexDlg::DoReplaceTextures(this: &dlg);
    }
    v9 = -1;
    CReplaceTexDlg::~CReplaceTexDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CDA30
// Name: public: void CFaceEditMaterialPage::UpdateDialogData(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::UpdateDialogData(CFaceEditMaterialPage *this, CMapFace *pOnlyFace)
{
  CFaceEditMaterialPage *v2; // ebx
  CAfxStringMgr *StringManager; // eax
  HWND Parent; // eax
  CWnd *v5; // eax
  int y; // edx
  CMapFace *v7; // edi
  char TextureAlignment; // al
  CWnd *v9; // ecx
  unsigned int k; // edi
  WPARAM v11; // esi
  CWnd *v12; // eax
  CWnd *v13; // eax
  unsigned int j; // ebx
  int v15; // esi
  CWnd *DlgItem; // eax
  CWnd *v17; // edi
  CWnd *v18; // eax
  CSpinButtonCtrl *v19; // eax
  CSpinButtonCtrl *v20; // eax
  CSpinButtonCtrl *v21; // eax
  CSpinButtonCtrl *v22; // eax
  char *m_pszData; // esi
  const char *DefaultTextureName; // eax
  Vector2D **p_m_pLightmapCoords; // eax
  HWND v26; // [esp-4h] [ebp-168h]
  WPARAM v27; // [esp+4h] [ebp-160h]
  HWND m_hWnd; // [esp+8h] [ebp-15Ch]
  char fValue[24]; // [esp+18h] [ebp-14Ch] BYREF
  char v30[24]; // [esp+98h] [ebp-CCh] BYREF
  CWnd *v31; // [esp+118h] [ebp-4Ch]
  CWnd *v32; // [esp+11Ch] [ebp-48h]
  int v33; // [esp+120h] [ebp-44h]
  int v34; // [esp+124h] [ebp-40h]
  int v35; // [esp+128h] [ebp-3Ch]
  int v36; // [esp+12Ch] [ebp-38h]
  CFaceEditSheet *pSheet; // [esp+130h] [ebp-34h]
  CWnd *v38; // [esp+134h] [ebp-30h]
  int bFirst; // [esp+138h] [ebp-2Ch]
  int nWorldAlignCount; // [esp+13Ch] [ebp-28h]
  int i; // [esp+140h] [ebp-24h]
  int nFaceAlignCount; // [esp+144h] [ebp-20h]
  float v43; // [esp+148h] [ebp-1Ch]
  int material; // [esp+14Ch] [ebp-18h]
  int faceCount; // [esp+150h] [ebp-14h]
  ATL::CSimpleStringT<char,0> fshiftY; // [esp+154h] [ebp-10h] BYREF
  int fscaleY; // [esp+160h] [ebp-4h]

  v2 = this;
  v32 = this;
  *(float *)&nFaceAlignCount = -99999.0;
  *(float *)&nWorldAlignCount = -99999.0;
  *(float *)&material = -99999.0;
  v43 = -99999.0;
  *(float *)&i = -99999.0;
  v38 = (CWnd *)-99999;
  faceCount = -99999;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  fshiftY.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  fscaleY = 1;
  m_hWnd = v2->m_hWnd;
  v33 = 1;
  v36 = 0;
  v34 = 0;
  Parent = GetParent(hWnd: m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  y = v5[49].m_ptGestureFrom.y;
  v31 = v5;
  bFirst = y;
  v35 = 0;
  pSheet = nullptr;
  while ( 1 )
  {
    v7 = pOnlyFace;
    if ( v35 < bFirst )
    {
      if ( pOnlyFace == nullptr )
        v7 = *(CMapFace **)((char *)&v5[49].m_xAccessibleServer.Release + (unsigned int)pSheet);
    }
    else if ( pOnlyFace == nullptr )
    {
      goto LABEL_19;
    }
    TextureAlignment = CMapFace::GetTextureAlignment(this: v7);
    if ( (TextureAlignment & 2) != 0 )
      ++v36;
    if ( (TextureAlignment & 1) != 0 )
      ++v34;
    if ( v33 != 0 )
      break;
    if ( v7->texture.UAxis.w != *(float *)&nFaceAlignCount )
      *(float *)&nFaceAlignCount = -99999.0;
    if ( v7->texture.VAxis.w != *(float *)&nWorldAlignCount )
      *(float *)&nWorldAlignCount = -99999.0;
    if ( v7->texture.scale[0] != *(float *)&material )
      *(float *)&material = -99999.0;
    if ( v7->texture.scale[1] != v43 )
      v43 = -99999.0;
    if ( v7->texture.rotate != *(float *)&i )
      *(float *)&i = -99999.0;
    if ( (CWnd *)v7->texture.material != v38 )
      v38 = (CWnd *)-99999;
    if ( v7->texture.nLightmapScale != faceCount )
      faceCount = -99999;
    if ( *((_DWORD *)fshiftY.m_pszData - 3) != 0
      && _mbscmp(s1: (const unsigned __int8 *)fshiftY.m_pszData, s2: (const unsigned __int8 *)&v7->texture) != 0 )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: &fshiftY, pszSrc: &var, nLength: 0);
    }
    CFaceEditMaterialPage::m_FaceContents = v7->texture.q2contents;
    CFaceEditMaterialPage::m_FaceSurface = v7->texture.q2surface;
    for ( j = 0; j < 0x78; j += 12 )
    {
      v15 = (dword_1072F7E0[j / 4] & *(&off_1072F7DC)[j / 4]) != 0;
      DlgItem = CWnd::GetDlgItem(this: v32, nID: FaceAttributes[j / 0xC].uControlID);
      v17 = DlgItem;
      if ( DlgItem != nullptr && SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != v15 )
      {
        SendMessageA(hWnd: v17->m_hWnd, Msg: 0xF4u, wParam: 6u, lParam: 1);
        SendMessageA(hWnd: v17->m_hWnd, Msg: 0xF1u, wParam: 2u, lParam: 0);
      }
    }
LABEL_43:
    ++v35;
    pSheet = (CFaceEditSheet *)((char *)pSheet + 12);
    v2 = (CFaceEditMaterialPage *)v32;
    v5 = v31;
  }
  v9 = (CWnd *)v7->texture.material;
  nFaceAlignCount = SLODWORD(v7->texture.UAxis.w);
  nWorldAlignCount = SLODWORD(v7->texture.VAxis.w);
  material = SLODWORD(v7->texture.scale[0]);
  v43 = v7->texture.scale[1];
  i = SLODWORD(v7->texture.rotate);
  v38 = v9;
  ATL::CSimpleStringT<char,0>::SetString(
    this: &fshiftY,
    pszSrc: v7->texture.texture,
    nLength: strlen(v7->texture.texture));
  faceCount = v7->texture.nLightmapScale;
  v2->m_eOrientation = CMapFace::GetOrientation(this: v7);
  CFaceEditMaterialPage::m_FaceContents = v7->texture.q2contents;
  CFaceEditMaterialPage::m_FaceSurface = v7->texture.q2surface;
  for ( k = 0; k < 0x78; k += 12 )
  {
    v11 = (dword_1072F7E0[k / 4] & *(&off_1072F7DC)[k / 4]) != 0;
    v12 = CWnd::GetDlgItem(this: v2, nID: FaceAttributes[k / 0xC].uControlID);
    if ( v12 != nullptr )
      SendMessageA(hWnd: v12->m_hWnd, Msg: 0xF1u, wParam: v11, lParam: 0);
  }
  v33 = 0;
  if ( pOnlyFace == nullptr )
    goto LABEL_43;
LABEL_19:
  v13 = CWnd::GetDlgItem(this: v2, nID: 1409);
  if ( v36 != 0 )
  {
    if ( v36 == bFirst )
      v27 = 1;
    else
      v27 = 2;
    v26 = v13->m_hWnd;
  }
  else
  {
    v27 = 0;
    v26 = v13->m_hWnd;
  }
  SendMessageA(hWnd: v26, Msg: 0xF1u, wParam: v27, lParam: 0);
  v18 = CWnd::GetDlgItem(this: v2, nID: 1408);
  if ( v34 != 0 )
  {
    if ( v34 == bFirst )
      SendMessageA(hWnd: v18->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    else
      SendMessageA(hWnd: v18->m_hWnd, Msg: 0xF1u, wParam: 2u, lParam: 0);
  }
  else
  {
    SendMessageA(hWnd: v18->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
  v19 = (CSpinButtonCtrl *)CWnd::GetDlgItem(this: v2, nID: 1008);
  FloatToSpin(fValue: *(float *)&nFaceAlignCount, pSpin: v19, bMantissa: 0);
  v20 = (CSpinButtonCtrl *)CWnd::GetDlgItem(this: v2, nID: 1184);
  FloatToSpin(fValue: *(float *)&nWorldAlignCount, pSpin: v20, bMantissa: 0);
  v21 = (CSpinButtonCtrl *)CWnd::GetDlgItem(this: v2, nID: 1011);
  IntegerToSpin(nValue: faceCount, pSpin: v21);
  if ( *(float *)&material == -99999.0 )
    v30[0] = 0;
  else
    sprintf(string: v30, format: "%.2f", *(float *)&material);
  CWnd::GetWindowTextA(this: &v2->m_scaleX, lpszString: fValue, nMaxCount: 128);
  if ( strcmp(v30, fValue) != 0 )
    CWnd::SetWindowTextA(this: &v2->m_scaleX, lpszString: v30);
  if ( v43 == -99999.0 )
    v30[0] = 0;
  else
    sprintf(string: v30, format: "%.2f", v43);
  CWnd::GetWindowTextA(this: &v2->m_scaleY, lpszString: fValue, nMaxCount: 128);
  if ( strcmp(v30, fValue) != 0 )
    CWnd::SetWindowTextA(this: &v2->m_scaleY, lpszString: v30);
  v22 = (CSpinButtonCtrl *)CWnd::GetDlgItem(this: v2, nID: 1185);
  FloatToSpin(fValue: *(float *)&i, pSpin: v22, bMantissa: 1);
  m_pszData = fshiftY.m_pszData;
  if ( *((_DWORD *)fshiftY.m_pszData - 3) != 0 )
    CFaceEditMaterialPage::SelectTexture(this: v2, pszTextureName: fshiftY.m_pszData);
  else
    SendMessageA(hWnd: v2->m_TextureList.m_hWnd, Msg: 0x14Eu, wParam: 0xFFFFFFFF, lParam: 0);
  if ( bFirst == 0 )
  {
    DefaultTextureName = GetDefaultTextureName();
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOnlyFace,
      pszSrc: DefaultTextureName);
    LOBYTE(fscaleY) = 2;
    CFaceEditMaterialPage::SelectTexture(this: v2, pszTextureName: (const char *)pOnlyFace);
    LOBYTE(fscaleY) = 1;
    p_m_pLightmapCoords = &pOnlyFace[-1].m_pLightmapCoords;
    if ( _InterlockedDecrement((volatile signed __int32 *)&pOnlyFace[-1].m_fSmoothingGroups) <= 0 )
      (*(void (__stdcall **)(Vector2D **))(LODWORD((*p_m_pLightmapCoords)->x) + 4))(a1: p_m_pLightmapCoords);
  }
  CFaceEditMaterialPage::UpdateTexture(this: v2);
  if ( v2->m_iMaterialTool == 2 )
    CFaceSmoothingDlg::UpdateControls(this: &v2->m_FaceSmoothDlg);
  fscaleY = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(a1: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100CE070
// Name: protected: int CFaceEditMaterialPage::OnAlign(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditMaterialPage::OnAlign(CFaceEditMaterialPage *this, unsigned int uCmd)
{
  CFaceEditMaterialPage *v2; // esi
  CHistory *History; // eax
  HWND Parent; // eax
  CWnd *v5; // ebx
  int v6; // edi
  CWnd::XAccessibleServer_vtbl *v7; // eax
  CMapFace *v8; // esi
  CHistory *v9; // eax
  CMapClass *v11; // [esp-8h] [ebp-18h]
  int y; // [esp+Ch] [ebp-4h]

  v2 = this;
  if ( this->m_iMaterialTool == 2 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  v2->m_iMaterialTool = 1;
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Align texture", bFromOpposite: 0);
  Parent = GetParent(hWnd: v2->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  if ( v5[49].m_ptGestureFrom.y > 0 )
  {
    v6 = 0;
    y = v5[49].m_ptGestureFrom.y;
    do
    {
      v7 = v5[49].m_xAccessibleServer.__vftable;
      v8 = *(CMapFace **)((char *)&v7->Release + v6);
      v11 = *(CMapClass **)((char *)&v7->QueryInterface + v6);
      v9 = GetHistory();
      CHistory::Keep(this: v9, pObject: v11);
      if ( uCmd == 1408 )
      {
        CMapFace::InitializeTextureAxes(this: v8, eAlignment: TEXTURE_ALIGN_WORLD, dwFlags: 3u);
      }
      else if ( uCmd == 1409 )
      {
        CMapFace::InitializeTextureAxes(this: v8, eAlignment: TEXTURE_ALIGN_FACE, dwFlags: 3u);
      }
      v6 += 12;
      --y;
    }
    while ( y != 0 );
    v2 = this;
  }
  CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditMaterialPage::UpdateDialogData(this: v2, pOnlyFace: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CE150
// Name: protected: int CFaceEditMaterialPage::OnJustify(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFaceEditMaterialPage::OnJustify(CFaceEditMaterialPage *this, unsigned int uCmd)
{
  CFaceEditMaterialPage *v2; // edi
  bool v3; // zf
  CHistory *History; // eax
  HWND Parent; // eax
  CFaceEditSheet *v6; // eax
  int m_Size; // esi
  int m_bTreatAsOneFace; // ebx
  int v9; // edi
  CFaceEditSheet::StoredFace_t *m_pMemory; // edx
  CMapFace *pMapFace; // esi
  CHistory *v12; // eax
  CMapClass *pMapSolid; // [esp-4h] [ebp-64h]
  Vector Extents[6]; // [esp+Ch] [ebp-54h] BYREF
  CFaceEditMaterialPage *v16; // [esp+54h] [ebp-Ch]
  int v17; // [esp+58h] [ebp-8h]
  CFaceEditSheet *pSheet; // [esp+5Ch] [ebp-4h]
  unsigned int uCmda; // [esp+68h] [ebp+8h]

  v2 = this;
  v3 = this->m_iMaterialTool == 2;
  v16 = this;
  if ( v3 )
    this->m_FaceSmoothDlg.DestroyWindow(this: &this->m_FaceSmoothDlg);
  v2->m_iMaterialTool = 1;
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Justify texture", bFromOpposite: 0);
  Parent = GetParent(hWnd: v2->m_hWnd);
  v6 = (CFaceEditSheet *)CWnd::FromHandle(hWnd: Parent);
  m_Size = v6->m_Faces.m_Size;
  pSheet = v6;
  if ( m_Size <= 1 )
  {
    m_bTreatAsOneFace = 0;
  }
  else
  {
    m_bTreatAsOneFace = v2->m_bTreatAsOneFace;
    if ( m_bTreatAsOneFace != 0 )
      CFaceEditMaterialPage::GetAllFaceExtents(this: v2, Extents);
  }
  if ( m_Size > 0 )
  {
    v17 = uCmd - 1403;
    v9 = 0;
    for ( uCmda = m_Size; uCmda != 0; --uCmda )
    {
      m_pMemory = pSheet->m_Faces.m_Memory.m_pMemory;
      pMapFace = m_pMemory[v9].pMapFace;
      pMapSolid = m_pMemory[v9].pMapSolid;
      v12 = GetHistory();
      CHistory::Keep(this: v12, pObject: pMapSolid);
      if ( m_bTreatAsOneFace == 0 )
        CMapFace::GetFaceExtents(this: pMapFace, Extents);
      switch ( v17 )
      {
        case 0:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_TOP, Extents);
          break;
        case 1:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_LEFT, Extents);
          break;
        case 2:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_CENTER, Extents);
          break;
        case 3:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_FIT, Extents);
          break;
        case 4:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_RIGHT, Extents);
          break;
        case 8:
          CMapFace::JustifyTextureUsingExtents(this: pMapFace, eJustification: TEXTURE_JUSTIFY_BOTTOM, Extents);
          break;
        default:
          break;
      }
      ++v9;
    }
    v2 = v16;
  }
  CMapDoc::m_pMapDoc->SetModifiedFlag(this: CMapDoc::m_pMapDoc, a2: 1);
  CFaceEditMaterialPage::UpdateDialogData(this: v2, pOnlyFace: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CE2C0
// Name: public: void CFaceEditMaterialPage::ClickFace(class CMapSolid __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFaceEditMaterialPage::ClickFace(
        CFaceEditMaterialPage *this,
        CMapSolid *pSolid,
        int faceIndex,
        char cmd,
        int clickMode)
{
  CMapFace *v6; // esi
  bool v7; // bl
  HWND Parent; // eax
  char v9; // al
  char bEnableUpdate_3; // [esp+17h] [ebp+Bh]

  if ( faceIndex >= pSolid->Faces.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)faceIndex, pSolid->Faces.nCount);
    BlockArray<CMapFace,6,86>::SetCount(this: &pSolid->Faces, nObjects: faceIndex + 1);
  }
  v6 = &pSolid->Faces.Blocks[faceIndex / 6][faceIndex % 6];
  v7 = pSolid->IsEditable(this: pSolid);
  Parent = GetParent(hWnd: this->m_hWnd);
  bEnableUpdate_3 = CWnd::FromHandle(hWnd: Parent)[49].m_bGestureInited;
  CFaceEditMaterialPage::SetReadOnly(this, bIsReadOnly: !v7);
  switch ( clickMode )
  {
    case 257:
      if ( bEnableUpdate_3 != 0 )
        CFaceEditMaterialPage::UpdateDialogData(this, pOnlyFace: nullptr);
      break;
    case 258:
      if ( bEnableUpdate_3 != 0 )
        CFaceEditMaterialPage::UpdateDialogData(this, pOnlyFace: v6);
      break;
    case 260:
    case 261:
      if ( v7 )
      {
        v9 = 0;
        if ( (cmd & 0x10) != 0 )
          v9 = 8;
        if ( clickMode == 261 )
          CFaceEditMaterialPage::Apply(this, pOnlyFace: v6, flags: v9 | 7);
        else
          CFaceEditMaterialPage::Apply(this, pOnlyFace: v6, flags: v9 | 1);
      }
      break;
    case 262:
      if ( v7 )
        CFaceEditMaterialPage::Apply(this, pOnlyFace: v6, flags: 4);
      break;
    case 263:
      if ( v7 )
        CFaceEditMaterialPage::AlignToView(this, pFace: v6);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CE420
// Name: protected: virtual struct AFX_MSGMAP const __near * CFaceEditMaterialPage::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFaceEditMaterialPage::GetMessageMap(CFaceEditMaterialPage *this)
{
  return (const AFX_MSGMAP *)&off_105EB5C4;
}

//------------------------------------------------------------------------------
// Address: 0x1034A916
// Name: public: virtual int CSpinButtonCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSpinButtonCtrl::Create(
        CSpinButtonCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 64);
  return this->Create(
           this,
           a2: "msctls_updown32",
           a3: nullptr,
           a4: dwStyle,
           a5: rect,
           a6: pParentWnd,
           a7: nID,
           a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034A97E
// Name: public: virtual CSpinButtonCtrl::~CSpinButtonCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpinButtonCtrl::~CSpinButtonCtrl(CSpinButtonCtrl *this)
{
  this->__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABCC
// Name: public: virtual struct CRuntimeClass __near * CSpinButtonCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSpinButtonCtrl::GetRuntimeClass(CSpinButtonCtrl *this)
{
  return &CSpinButtonCtrl::classCSpinButtonCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034A946
// Name: public: virtual int CHeaderCtrl::CreateEx(unsigned long,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CHeaderCtrl::CreateEx(
        CTabCtrl *this,
        unsigned int dwExStyle,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  int result; // eax

  result = this->Create_2(this, a2: dwStyle, a3: rect, a4: pParentWnd, a5: nID);
  if ( result != 0 && dwExStyle != 0 )
    return CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: dwExStyle, nFlags: 0);
  return result;
}
