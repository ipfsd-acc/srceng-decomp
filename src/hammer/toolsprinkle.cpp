// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolsprinkle.cpp
// Functions: 27
// ============================================================

#include "hammer\toolsprinkle.h"

//------------------------------------------------------------------------------
// Address: 0x10163DC0
// Name: protected: virtual bool CToolEntitySprinkle::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::UpdateTranslation(CMapAtom *this, CRender3D *pRender, bool bNewContext)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A250
// Name: public: virtual void CToolEntitySprinkle::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::OnDeactivate(CToolEntitySprinkle *this)
{
  CWnd::ShowWindow(this: this->pSprinkleDlg, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1016A260
// Name: protected: virtual int CToolEntitySprinkle::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CToolEntitySprinkle::HitTest(
        CToolEntity *this,
        CMapView *pView,
        const Vector2D *ptClient,
        bool bTestHandles)
{
  return Tool3D::HitRect(this, pView, vPoint: ptClient, vCenter: &this->m_vecPos, extent: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1016A290
// Name: protected: virtual void CToolEntitySprinkle::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::FinishTranslation(CToolEntitySprinkle *this, bool bSave)
{
  Tool3D::FinishTranslation(this, bSave);
}

//------------------------------------------------------------------------------
// Address: 0x1016A2A0
// Name: public: virtual bool CToolEntitySprinkle::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnLMouseDown2D(
        CToolEntitySprinkle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A2C0
// Name: public: virtual bool CToolEntitySprinkle::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnLMouseUp2D(
        CToolEntitySprinkle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  Tool3D::OnLMouseUp3D(this, (CMapView3D *)pView, nFlags, vPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A2E0
// Name: public: virtual bool CToolEntitySprinkle::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnMouseMove2D(
        CToolEntitySprinkle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A300
// Name: public: virtual bool CToolEntitySprinkle::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnLMouseUp3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  AsyncKeyState = GetAsyncKeyState(vKey: 17);
  this->m_InDrawMode = false;
  this->m_bCtrlDown = AsyncKeyState < 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A330
// Name: public: virtual bool CToolEntitySprinkle::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnRMouseUp3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax

  AsyncKeyState = GetAsyncKeyState(vKey: 17);
  this->m_InSizingMode = false;
  this->m_bCtrlDown = AsyncKeyState < 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A360
// Name: private: void CToolEntitySprinkle::PopulateEntity(class CMapEntity __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::PopulateEntity(CToolEntitySprinkle *this, CMapEntity *pEntity, KeyValues *pFields)
{
  KeyValues *i; // ebx
  int v4; // esi
  const char **v5; // eax
  const char *Name; // eax
  CEditGameClass_vtbl *v7; // esi
  const char *v8; // eax
  const char *v9; // [esp-10h] [ebp-10h]
  const char *String; // [esp-10h] [ebp-10h]

  if ( pFields != nullptr )
  {
    for ( i = KeyValues::GetFirstSubKey(this: pFields); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v4 = 0;
      if ( pszReserved[0] != nullptr )
      {
        v5 = pszReserved;
        do
        {
          v9 = *v5;
          Name = KeyValues::GetName(this: i);
          if ( _V_stricmp(s1: Name, s2: v9) == 0 )
            break;
          v5 = &pszReserved[++v4];
        }
        while ( *v5 != nullptr );
      }
      if ( pszReserved[v4] == nullptr )
      {
        v7 = pEntity->CEditGameClass::__vftable;
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &var);
        v8 = KeyValues::GetName(this: i);
        v7->SetKeyValue(this: &pEntity->CEditGameClass, a2: v8, a3: String);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A410
// Name: private: bool CToolEntitySprinkle::FindWorldSpot(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::FindWorldSpot(CToolEntitySprinkle *this, Vector *vOrigin)
{
  float v3; // xmm3_4
  float x; // xmm5_4
  float y; // xmm6_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  float v19; // xmm7_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  CMapFace *m_pHitFace; // ecx
  float v23; // xmm2_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  Vector vHitNormal; // [esp+0h] [ebp-50h] BYREF
  Vector vHitPos; // [esp+Ch] [ebp-44h] BYREF
  Vector vFinalStart; // [esp+18h] [ebp-38h] BYREF
  Vector vFinalEnd; // [esp+24h] [ebp-2Ch] BYREF
  float v32; // [esp+30h] [ebp-20h]
  float v33; // [esp+34h] [ebp-1Ch]
  float v34; // [esp+38h] [ebp-18h]
  float v35; // [esp+3Ch] [ebp-14h]
  float v36; // [esp+40h] [ebp-10h]
  float v37; // [esp+44h] [ebp-Ch]
  float v38; // [esp+48h] [ebp-8h]
  float v39; // [esp+4Ch] [ebp-4h]
  float vOrigina; // [esp+58h] [ebp+8h]

  v3 = this->m_LocalMatrixNeg.m[3][0];
  x = vOrigin->x;
  y = vOrigin->y;
  z = vOrigin->z;
  v8 = z + 600.0;
  v9 = z - 600.0;
  v34 = this->m_LocalMatrixNeg.m[3][2];
  vFinalEnd.z = v8;
  v35 = this->m_LocalMatrixNeg.m[3][1];
  v10 = this->m_LocalMatrixNeg.m[0][0];
  v11 = 1.0
      / (float)((float)((float)((float)(v3 * x) + (float)(v35 * y)) + (float)(v34 * v9)) + this->m_LocalMatrixNeg.m[3][3]);
  vOrigina = this->m_LocalMatrixNeg.m[0][2];
  v33 = this->m_LocalMatrixNeg.m[0][1];
  v12 = this->m_LocalMatrixNeg.m[1][1];
  vFinalStart.x = (float)((float)((float)((float)(v10 * x) + (float)(v33 * y)) + (float)(vOrigina * v9))
                        + this->m_LocalMatrixNeg.m[0][3])
                * v11;
  v38 = this->m_LocalMatrixNeg.m[1][2];
  vHitPos.x = x;
  vFinalEnd.x = x;
  v39 = v12;
  v13 = this->m_LocalMatrixNeg.m[1][0];
  v14 = (float)((float)((float)(v13 * x) + (float)(v39 * y)) + (float)(v38 * v9)) + this->m_LocalMatrixNeg.m[1][3];
  v15 = this->m_LocalMatrixNeg.m[2][1];
  vFinalStart.y = v14 * v11;
  v37 = this->m_LocalMatrixNeg.m[2][2];
  v36 = v11;
  v16 = this->m_LocalMatrixNeg.m[2][0];
  v32 = v15;
  v17 = (float)((float)(v16 * vHitPos.x) + (float)(v15 * y)) + (float)(v37 * v9);
  v18 = vFinalEnd.x;
  v19 = (float)(v17 + this->m_LocalMatrixNeg.m[2][3]) * v36;
  vFinalEnd.y = y;
  vFinalStart.z = v19;
  v20 = 1.0
      / (float)((float)((float)((float)(v3 * vFinalEnd.x) + (float)(v35 * y)) + (float)(v34 * vFinalEnd.z))
              + this->m_LocalMatrixNeg.m[3][3]);
  vFinalEnd.x = (float)((float)((float)((float)(v10 * vFinalEnd.x) + (float)(v33 * y)) + (float)(vOrigina * vFinalEnd.z))
                      + this->m_LocalMatrixNeg.m[0][3])
              * v20;
  v21 = (float)((float)((float)(v13 * v18) + (float)(v39 * y)) + (float)(v38 * vFinalEnd.z))
      + this->m_LocalMatrixNeg.m[1][3];
  m_pHitFace = this->m_pHitFace;
  v23 = (float)((float)((float)((float)(v16 * v18) + (float)(v32 * y)) + (float)(v37 * vFinalEnd.z))
              + this->m_LocalMatrixNeg.m[2][3])
      * v20;
  vFinalEnd.y = v21 * v20;
  vFinalEnd.z = v23;
  if ( CMapFace::TraceLineInside(
         this: m_pHitFace,
         HitPos: &vHitPos,
         HitNormal: &vHitNormal,
         Start: &vFinalStart,
         End: &vFinalEnd,
         bNoDisp: false) == 0 )
    return 0;
  v24 = 1.0
      / (float)((float)((float)((float)(this->m_LocalMatrix.m[3][1] * vHitPos.y)
                              + (float)(this->m_LocalMatrix.m[3][0] * vHitPos.x))
                      + (float)(this->m_LocalMatrix.m[3][2] * vHitPos.z))
              + this->m_LocalMatrix.m[3][3]);
  v25 = (float)((float)((float)((float)(this->m_LocalMatrix.m[1][1] * vHitPos.y)
                              + (float)(this->m_LocalMatrix.m[1][0] * vHitPos.x))
                      + (float)(this->m_LocalMatrix.m[1][2] * vHitPos.z))
              + this->m_LocalMatrix.m[1][3])
      * v24;
  v26 = (float)((float)((float)((float)(this->m_LocalMatrix.m[2][1] * vHitPos.y)
                              + (float)(this->m_LocalMatrix.m[2][0] * vHitPos.x))
                      + (float)(this->m_LocalMatrix.m[2][2] * vHitPos.z))
              + this->m_LocalMatrix.m[2][3])
      * v24;
  vOrigin->x = (float)((float)((float)((float)(this->m_LocalMatrix.m[0][1] * vHitPos.y)
                                     + (float)(vHitPos.x * this->m_LocalMatrix.m[0][0]))
                             + (float)(this->m_LocalMatrix.m[0][2] * vHitPos.z))
                     + this->m_LocalMatrix.m[0][3])
             * v24;
  vOrigin->y = v25;
  vOrigin->z = v26;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A7A0
// Name: private: bool CToolEntitySprinkle::IsInSprinkle(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::IsInSprinkle(
        CToolEntitySprinkle *this,
        KeyValues *pSprinkleType,
        const char *pszClassname)
{
  KeyValues *Key; // eax
  KeyValues *v4; // eax
  const char *String; // eax
  KeyValues *FirstSubKey; // esi
  KeyValues *v8; // eax
  const char *v9; // eax

  Key = KeyValues::FindKey(this: pSprinkleType, keyName: "base", bCreate: false);
  if ( Key != nullptr )
  {
    v4 = KeyValues::FindKey(this: Key, keyName: "classname", bCreate: false);
    if ( v4 != nullptr )
    {
      String = KeyValues::GetString(this: v4, keyName: nullptr, defaultValue: &var);
      if ( _V_stricmp(s1: String, s2: pszClassname) == 0 )
        return 1;
    }
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: pSprinkleType);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      v8 = KeyValues::FindKey(this: FirstSubKey, keyName: "classname", bCreate: false);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::GetString(this: v8, keyName: nullptr, defaultValue: &var);
        if ( _V_stricmp(s1: v9, s2: pszClassname) == 0 )
          break;
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016A850
// Name: private: bool CToolEntitySprinkle::DoSizing(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::DoSizing(CToolEntitySprinkle *this, const Vector2D *vPoint)
{
  float v3; // xmm0_4

  if ( this->m_InSizingMode )
  {
    v3 = (float)(vPoint->x - this->m_StartSizingPoint.x) + this->m_OrigBrushSize;
    this->m_BrushSize = v3;
    if ( v3 < 1.0 )
      this->m_BrushSize = 1.0;
    return 1;
  }
  else
  {
    this->m_InSizingMode = true;
    this->m_StartSizingPoint = *vPoint;
    this->m_OrigBrushSize = this->m_BrushSize;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A8C0
// Name: private: void CToolEntitySprinkle::CalcGridInfo(class KeyValues __near *,float __near &,float __near &,float __near &,float __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::CalcGridInfo(
        CToolEntitySprinkle *this,
        KeyValues *pSprinkleType,
        float *flGridXSize,
        float *flGridYSize,
        float *flXSize,
        float *flYSize,
        Vector *vCenter)
{
  KeyValues *Key; // eax
  KeyValues *v9; // eax
  const char *String; // eax

  *flGridXSize = 64.0;
  *flGridYSize = 64.0;
  if ( CEntitySprinkleDlg::UseDefinitionGridSize(this: this->pSprinkleDlg) )
  {
    Key = KeyValues::FindKey(this: pSprinkleType, keyName: "base", bCreate: false);
    if ( Key != nullptr )
    {
      v9 = KeyValues::FindKey(this: Key, keyName: "grid", bCreate: false);
      if ( v9 != nullptr )
      {
        String = KeyValues::GetString(this: v9, keyName: nullptr, defaultValue: &var);
        sscanf(string: String, format: "%g %g", flGridXSize, flGridYSize);
      }
    }
  }
  else
  {
    CEntitySprinkleDlg::GetGridSize(this: this->pSprinkleDlg, flGridXSize, flGridYSize);
  }
  *flXSize = ceil(X: (float)(this->m_BrushSize / *flGridXSize)) * *flGridXSize;
  *flYSize = ceil(X: (float)(this->m_BrushSize / *flGridYSize)) * *flGridXSize;
  *vCenter = this->m_vWorldMousePoint;
  vCenter->x = vCenter->x - fmod(vCenter->x, *flGridXSize);
  vCenter->y = vCenter->y - fmod(vCenter->y, *flGridYSize);
}

//------------------------------------------------------------------------------
// Address: 0x1016A9D0
// Name: public: CToolEntitySprinkle::CToolEntitySprinkle(void)
// Source: json
//------------------------------------------------------------------------------
CToolEntitySprinkle *__thiscall CToolEntitySprinkle::CToolEntitySprinkle(CToolEntitySprinkle *this)
{
  Tool3D::Tool3D(this);
  this->__vftable = (CToolEntitySprinkle_vtbl *)&CToolEntitySprinkle::`vftable';
  this->m_bEmpty = true;
  this->m_vecPos.x = 0.0;
  this->m_vecPos.y = 0.0;
  this->m_vecPos.z = 0.0;
  this->pSprinkleDlg = nullptr;
  this->m_pSprinkleInfo = nullptr;
  this->m_BrushSize = 256.0;
  this->m_OrigBrushSize = 256.0;
  this->m_vMousePoint.x = 0.0;
  this->m_vMousePoint.y = 0.0;
  this->m_bWorldValid = false;
  this->m_vWorldMousePoint.x = 0.0;
  this->m_vWorldMousePoint.y = 0.0;
  this->m_vWorldMousePoint.z = 0.0;
  *(_WORD *)&this->m_InSizingMode = 0;
  this->m_bCtrlDown = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016AAF0
// Name: public: virtual bool CToolEntitySprinkle::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnKeyDown2D(
        CToolEntitySprinkle *this,
        CMapView2D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v6; // eax

  if ( nChar != 13 )
  {
    if ( nChar != 27 )
      return 0;
    v6 = ToolManager();
    CToolManager::SetTool(this: v6, eNewTool: TOOL_PICK_ENTITY);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016AB20
// Name: public: virtual bool CToolEntitySprinkle::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnKeyDown3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v6; // eax

  if ( pView->GetMapDoc(this: &pView->CMapView) == nullptr )
    return 0;
  if ( nChar != 13 )
  {
    if ( nChar != 27 )
      return 0;
    v6 = ToolManager();
    CToolManager::SetTool(this: v6, eNewTool: TOOL_PICK_ENTITY);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016AB60
// Name: public: virtual void CToolEntitySprinkle::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::RenderTool3D(CToolEntitySprinkle *this, CRender3D *pRender)
{
  float m_BrushSize; // xmm0_4
  Vector *p_m_vWorldMousePoint; // edi
  KeyValues *SprinkleType; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  bool v12; // cf
  Vector flRadius; // [esp+24h] [ebp-44h] BYREF
  Vector v14; // [esp+30h] [ebp-38h] BYREF
  Vector vStart; // [esp+3Ch] [ebp-2Ch] BYREF
  float v16; // [esp+48h] [ebp-20h] BYREF
  float v17; // [esp+4Ch] [ebp-1Ch]
  Vector vCenter; // [esp+50h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+5Ch] [ebp-Ch] BYREF
  float flGridYSize; // [esp+70h] [ebp+8h]

  if ( this->m_bWorldValid )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    m_BrushSize = this->m_BrushSize;
    if ( this->m_InSizingMode )
    {
      CRender3D::RenderWireframeSphere(
        this: pRender,
        vCenter: &this->m_vWorldMousePoint,
        flRadius: m_BrushSize,
        nTheta: 12,
        nPhi: 12,
        chRed: 0xFFu,
        chGreen: 0xFFu,
        chBlue: 0);
      CRender::PopRenderMode(this: pRender);
    }
    else
    {
      p_m_vWorldMousePoint = &this->m_vWorldMousePoint;
      if ( this->m_bCtrlDown )
        CRender3D::RenderWireframeSphere(
          this: pRender,
          vCenter: &this->m_vWorldMousePoint,
          flRadius: m_BrushSize,
          nTheta: 12,
          nPhi: 12,
          chRed: 0xFFu,
          chGreen: 0,
          chBlue: 0);
      else
        CRender3D::RenderWireframeSphere(
          this: pRender,
          vCenter: &this->m_vWorldMousePoint,
          flRadius: m_BrushSize,
          nTheta: 12,
          nPhi: 12,
          chRed: 0,
          chGreen: 0xFFu,
          chBlue: 0);
      SprinkleType = CEntitySprinkleDlg::GetSprinkleType(this: this->pSprinkleDlg);
      if ( SprinkleType != nullptr )
      {
        vCenter.y = this->m_BrushSize * this->m_BrushSize;
        CToolEntitySprinkle::CalcGridInfo(
          this,
          pSprinkleType: SprinkleType,
          flGridXSize: &v16,
          flGridYSize: &vCenter.x,
          flXSize: &vOrigin.y,
          flYSize: &vOrigin.z,
          vCenter: &v14);
        CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
        y = vOrigin.y;
        x = -vOrigin.y;
        vOrigin.x = -vOrigin.y;
        if ( vOrigin.y >= (float)-vOrigin.y )
        {
          z = vOrigin.z;
          v10 = -vOrigin.z;
          v17 = -vOrigin.z;
          do
          {
            flGridYSize = v10;
            if ( z >= v10 )
            {
              v11 = v14.x + x;
              for ( vCenter.z = v14.x + x; ; v11 = vCenter.z )
              {
                vStart.x = v11;
                vStart.y = v14.y + v10;
                vStart.z = v14.z;
                if ( CToolEntitySprinkle::FindWorldSpot(this, vOrigin: &vStart) == 1
                  && (float)((float)((float)((float)(vStart.y - this->m_vWorldMousePoint.y)
                                           * (float)(vStart.y - this->m_vWorldMousePoint.y))
                                   + (float)((float)(vStart.x - p_m_vWorldMousePoint->x)
                                           * (float)(vStart.x - p_m_vWorldMousePoint->x)))
                           + (float)((float)(vStart.z - this->m_vWorldMousePoint.z)
                                   * (float)(vStart.z - this->m_vWorldMousePoint.z))) <= vCenter.y )
                {
                  flRadius.x = vStart.x;
                  flRadius.y = vStart.y;
                  flRadius.z = vStart.z + 64.0;
                  CRender::DrawLine(
                    this: pRender,
                    a2: (int)p_m_vWorldMousePoint,
                    a3: (int)this,
                    &vStart,
                    vEnd: &flRadius);
                }
                v10 = flGridYSize + vCenter.x;
                z = vOrigin.z;
                v12 = vOrigin.z < (float)(flGridYSize + vCenter.x);
                flGridYSize = flGridYSize + vCenter.x;
                if ( v12 )
                  break;
              }
              v10 = v17;
              y = vOrigin.y;
              x = vOrigin.x;
            }
            x = x + v16;
            vOrigin.x = x;
          }
          while ( y >= x );
        }
      }
      CRender::PopRenderMode(this: pRender);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016AD90
// Name: private: bool CToolEntitySprinkle::FindWorldMousePoint(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::FindWorldMousePoint(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        const Vector2D *vPoint)
{
  CMapClass *v4; // eax
  CMapFace *Face; // eax
  float x; // xmm5_4
  float y; // xmm6_4
  float z; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm7_4
  float v20; // xmm5_4
  float v21; // xmm7_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm6_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  Vector HitNormal; // [esp+8h] [ebp-64h] BYREF
  Vector HitPos; // [esp+14h] [ebp-58h] BYREF
  Vector vFinalStart; // [esp+20h] [ebp-4Ch] BYREF
  Vector vFinalEnd; // [esp+2Ch] [ebp-40h] BYREF
  Vector Start; // [esp+38h] [ebp-34h] BYREF
  Vector End; // [esp+44h] [ebp-28h] BYREF
  float v34; // [esp+50h] [ebp-1Ch]
  float v35; // [esp+54h] [ebp-18h]
  float v36; // [esp+58h] [ebp-14h]
  float v37; // [esp+5Ch] [ebp-10h]
  unsigned int ulFace; // [esp+60h] [ebp-Ch] BYREF
  CMapSolid *pSolid; // [esp+64h] [ebp-8h]
  float v40; // [esp+68h] [ebp-4h]
  CMapView3D *pViewa; // [esp+74h] [ebp+8h]
  float vPointa; // [esp+78h] [ebp+Ch]

  this->m_vMousePoint = *vPoint;
  v4 = CMapView3D::NearestObjectAt(
         this: pView,
         vPoint: &this->m_vMousePoint,
         &ulFace,
         nFlags: 3u,
         pLocalMatrix: &this->m_LocalMatrix);
  this->m_bWorldValid = false;
  if ( v4 == nullptr )
    return 0;
  *(float *)&pSolid = COERCE_FLOAT(
                        __RTDynamicCast(
                          inptr: v4,
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CMapSolid `RTTI Type Descriptor',
                          isReference: 0));
  if ( *(float *)&pSolid == 0.0 )
    return 0;
  VMatrix::InverseTR(this: &this->m_LocalMatrix, ret: &this->m_LocalMatrixNeg);
  CCamera::BuildRay(this: pView->m_pCamera, vView: vPoint, vStart: &Start, vEnd: &End);
  Face = CMapSolid::GetFace(this: pSolid, nFace: ulFace);
  x = Start.x;
  y = Start.y;
  z = Start.z;
  this->m_pHitFace = Face;
  v9 = this->m_LocalMatrixNeg.m[3][1];
  v10 = this->m_LocalMatrixNeg.m[3][0];
  v36 = this->m_LocalMatrixNeg.m[3][2];
  v37 = v9;
  v11 = (float)((float)((float)(v10 * x) + (float)(v9 * y)) + (float)(v36 * z)) + this->m_LocalMatrixNeg.m[3][3];
  v12 = this->m_LocalMatrixNeg.m[0][0];
  v13 = 1.0 / v11;
  vPointa = this->m_LocalMatrixNeg.m[0][2];
  v35 = this->m_LocalMatrixNeg.m[0][1];
  v14 = this->m_LocalMatrixNeg.m[1][1];
  vFinalStart.x = (float)((float)((float)((float)(v35 * y) + (float)(v12 * x)) + (float)(vPointa * z))
                        + this->m_LocalMatrixNeg.m[0][3])
                * (float)(1.0 / v11);
  v40 = this->m_LocalMatrixNeg.m[1][2];
  *(float *)&pViewa = v14;
  v15 = this->m_LocalMatrixNeg.m[1][0];
  v16 = (float)(v15 * x) + (float)(*(float *)&pViewa * y);
  v17 = v40 * z;
  v18 = this->m_LocalMatrixNeg.m[2][0];
  v19 = (float)(v16 + v17) + this->m_LocalMatrixNeg.m[1][3];
  v20 = this->m_LocalMatrixNeg.m[2][1];
  vFinalStart.y = v19 * v13;
  pSolid = (CMapSolid *)LODWORD(this->m_LocalMatrixNeg.m[2][2]);
  v34 = v20;
  v21 = (float)((float)((float)((float)(v18 * Start.x) + (float)(v20 * y)) + (float)(*(float *)&pSolid * Start.z))
              + this->m_LocalMatrixNeg.m[2][3])
      * v13;
  v22 = 1.0
      / (float)((float)((float)((float)(v10 * End.x) + (float)(v37 * End.y)) + (float)(v36 * End.z))
              + this->m_LocalMatrixNeg.m[3][3]);
  vFinalStart.z = v21;
  vFinalEnd.x = (float)((float)((float)((float)(v12 * End.x) + (float)(v35 * End.y)) + (float)(vPointa * End.z))
                      + this->m_LocalMatrixNeg.m[0][3])
              * v22;
  v23 = (float)((float)((float)((float)(v18 * End.x) + (float)(v20 * End.y)) + (float)(*(float *)&pSolid * End.z))
              + this->m_LocalMatrixNeg.m[2][3])
      * v22;
  vFinalEnd.y = (float)((float)((float)((float)(v15 * End.x) + (float)(*(float *)&pViewa * End.y)) + (float)(v40 * End.z))
                      + this->m_LocalMatrixNeg.m[1][3])
              * v22;
  vFinalEnd.z = v23;
  if ( CMapFace::TraceLineInside(this: Face, &HitPos, &HitNormal, Start: &vFinalStart, End: &vFinalEnd, bNoDisp: false) == 0 )
    return 0;
  v24 = 1.0
      / (float)((float)((float)((float)(this->m_LocalMatrix.m[3][1] * HitPos.y)
                              + (float)(this->m_LocalMatrix.m[3][0] * HitPos.x))
                      + (float)(this->m_LocalMatrix.m[3][2] * HitPos.z))
              + this->m_LocalMatrix.m[3][3]);
  v25 = (float)((float)((float)((float)(this->m_LocalMatrix.m[1][1] * HitPos.y)
                              + (float)(this->m_LocalMatrix.m[1][0] * HitPos.x))
                      + (float)(this->m_LocalMatrix.m[1][2] * HitPos.z))
              + this->m_LocalMatrix.m[1][3])
      * v24;
  v26 = (float)((float)((float)((float)(this->m_LocalMatrix.m[2][1] * HitPos.y)
                              + (float)(this->m_LocalMatrix.m[2][0] * HitPos.x))
                      + (float)(this->m_LocalMatrix.m[2][2] * HitPos.z))
              + this->m_LocalMatrix.m[2][3])
      * v24;
  this->m_vWorldMousePoint.x = (float)((float)((float)((float)(this->m_LocalMatrix.m[0][1] * HitPos.y)
                                                     + (float)(this->m_LocalMatrix.m[0][0] * HitPos.x))
                                             + (float)(this->m_LocalMatrix.m[0][2] * HitPos.z))
                                     + this->m_LocalMatrix.m[0][3])
                             * v24;
  this->m_vWorldMousePoint.y = v25;
  this->m_vWorldMousePoint.z = v26;
  this->m_bWorldValid = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016B130
// Name: public: virtual bool CToolEntitySprinkle::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnRMouseDown3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  if ( CToolEntitySprinkle::FindWorldMousePoint(this, pView, vPoint) == 1 )
  {
    this->m_InDrawMode = false;
    CToolEntitySprinkle::DoSizing(this, vPoint);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016B180
// Name: private: void CToolEntitySprinkle::RemoveMapObjects(class Vector __near &,class KeyValues __near *,int,int,class CUtlVector<class CMapEntity __near *,class CUtlMemory<class CMapEntity __near *,int>> __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::RemoveMapObjects(
        CToolEntitySprinkle *this,
        Vector *vOrigin,
        KeyValues *pSprinkleType,
        int nMode,
        int nDensity,
        CUtlMemory<CCullTreeNode *,int> *pRemovedEntities,
        CMapEntity *pTouchedEntity)
{
  KeyValues *Key; // esi
  CMapWorld *m_pWorld; // eax
  int m_nGrowSize; // edi
  float v10; // xmm0_4
  CMapWorld *v11; // esi
  int v12; // edx
  __int64 v13; // kr00_8
  CUtlReference<CMapEntity> *v14; // ecx
  int v15; // edx
  CMapEntity *m_pObject; // eax
  CUtlReference<CMapEntity> *v17; // ecx
  CMapEntity *v18; // edi
  char v19; // bl
  char *v20; // eax
  IUniformRandomStream *v21; // ecx
  KeyValues *FirstSubKey; // esi
  KeyValues *v23; // eax
  char *String; // eax
  int m_Size; // eax
  int v26; // esi
  CMapEntity **m_pMemory; // ebx
  int v28; // eax
  CMapEntity **v29; // eax
  int v30; // esi
  int m_nAllocationCount; // eax
  CMapEntity **v32; // ecx
  int v33; // eax
  CMapEntity **v34; // eax
  int i; // esi
  CHistory *History; // eax
  CMapEntity *v37; // [esp-4h] [ebp-6Ch]
  CUtlVector<CMapEntity *,CUtlMemory<CMapEntity *,int> > RemoveList; // [esp+Ch] [ebp-5Ch] BYREF
  float v39; // [esp+20h] [ebp-48h] BYREF
  float v40; // [esp+24h] [ebp-44h]
  float v41; // [esp+28h] [ebp-40h]
  Vector m_CheckOrigin; // [esp+2Ch] [ebp-3Ch] BYREF
  CUtlReference<CMapEntity> *m_pHead; // [esp+38h] [ebp-30h] BYREF
  CUtlReference<CMapEntity> *v44; // [esp+3Ch] [ebp-2Ch]
  CMapEntity *v45; // [esp+40h] [ebp-28h]
  CMapDoc *pDoc; // [esp+44h] [ebp-24h]
  CMapWorld *pWorld; // [esp+48h] [ebp-20h]
  int pos; // [esp+4Ch] [ebp-1Ch]
  KeyValues *pBaseClass; // [esp+50h] [ebp-18h]
  CToolEntitySprinkle *v50; // [esp+54h] [ebp-14h]
  float flCheckSizeSq; // [esp+58h] [ebp-10h]
  int v52; // [esp+64h] [ebp-4h]

  v50 = this;
  Key = KeyValues::FindKey(this: pSprinkleType, keyName: "base", bCreate: false);
  pDoc = CMapDoc::m_pMapDoc;
  m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
  m_nGrowSize = 0;
  pBaseClass = nullptr;
  pWorld = m_pWorld;
  memset(&RemoveList, 0, sizeof(RemoveList));
  v52 = 1;
  if ( pTouchedEntity != nullptr )
  {
    pTouchedEntity->GetOrigin(this: pTouchedEntity, a2: &m_CheckOrigin);
    v10 = 1024.0;
  }
  else
  {
    m_CheckOrigin = v50->m_vWorldMousePoint;
    v10 = v50->m_BrushSize * v50->m_BrushSize;
  }
  flCheckSizeSq = v10;
  if ( Key != nullptr )
    pBaseClass = KeyValues::FindKey(this: Key, keyName: "classname", bCreate: false);
  v11 = pWorld;
  v12 = 0;
  pos = 0;
  if ( pWorld->m_EntityList.m_Size > 0 )
  {
    while ( 1 )
    {
      v13 = 32LL * *((int *)&v11->m_EntityList.m_Memory + 2);
      v14 = v11->m_EntityList.m_Memory.m_pMemory[v12 >> SBYTE4(v13)];
      v15 = v12 & ((int)v13 >> 5);
      m_pObject = v14[v15].m_pObject;
      if ( m_pObject != nullptr )
      {
        v45 = v14[v15].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v17 = m_pObject->m_References.m_pHead;
        if ( v17 != nullptr )
          v17->m_pPrev = (CUtlReference<CMapEntity> *)&m_pHead;
        v44 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapEntity> *)&m_pHead;
      }
      v18 = v45;
      LOBYTE(v52) = 1;
      if ( v45 != nullptr )
      {
        if ( v44 != nullptr )
        {
          v44->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v44;
        }
        else if ( (CUtlReference<CMapEntity> **)v45->m_References.m_pHead == &m_pHead )
        {
          v45->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v44 = nullptr;
        m_pHead = nullptr;
        v45 = nullptr;
      }
      if ( v18 == nullptr )
        goto LABEL_49;
      if ( v18 == pTouchedEntity )
        goto LABEL_49;
      if ( (*((_BYTE *)&v18->CMapClass + 180) & 2) == 0 )
        goto LABEL_49;
      v18->GetOrigin(this: v18, a2: (Vector *)&v39);
      if ( (float)((float)((float)((float)(v40 - m_CheckOrigin.y) * (float)(v40 - m_CheckOrigin.y))
                         + (float)((float)(v39 - m_CheckOrigin.x) * (float)(v39 - m_CheckOrigin.x)))
                 + (float)((float)(v41 - m_CheckOrigin.z) * (float)(v41 - m_CheckOrigin.z))) > flCheckSizeSq
        || CToolEntitySprinkle::IsInSprinkle(this: v50, pSprinkleType, pszClassname: v18->m_szClass) == 0 )
      {
        goto LABEL_49;
      }
      v19 = 0;
      if ( pBaseClass == nullptr
        || (v20 = (char *)KeyValues::GetString(this: pBaseClass, keyName: nullptr, defaultValue: &var),
            !CMapEntity::ClassNameMatches(this: v18, szName: v20)) )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: pSprinkleType);
        if ( FirstSubKey == nullptr )
          goto LABEL_32;
        while ( 1 )
        {
          v23 = KeyValues::FindKey(this: FirstSubKey, keyName: "classname", bCreate: false);
          if ( v23 != nullptr )
          {
            String = (char *)KeyValues::GetString(this: v23, keyName: nullptr, defaultValue: &var);
            if ( CMapEntity::ClassNameMatches(this: v18, szName: String) )
              break;
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          if ( FirstSubKey == nullptr )
            goto LABEL_32;
        }
      }
      v19 = 1;
LABEL_32:
      if ( (nMode != 1 || pTouchedEntity != nullptr || _RandomInt(this: v21, a2: 1, a3: 100) <= nDensity) && v19 == 1 )
      {
        m_Size = RemoveList.m_Size;
        v26 = RemoveList.m_Size;
        if ( RemoveList.m_Size + 1 > RemoveList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&RemoveList,
            num: RemoveList.m_Size - RemoveList.m_Memory.m_nAllocationCount + 1);
          m_Size = RemoveList.m_Size;
        }
        RemoveList.m_Size = m_Size + 1;
        m_pMemory = RemoveList.m_Memory.m_pMemory;
        v28 = m_Size - v26;
        RemoveList.m_pElements = RemoveList.m_Memory.m_pMemory;
        if ( v28 > 0 )
          _V_memmove(
            dest: &RemoveList.m_Memory.m_pMemory[v26 + 1],
            src: &RemoveList.m_Memory.m_pMemory[v26],
            count: 4 * v28);
        v29 = &m_pMemory[v26];
        if ( v29 != nullptr )
          *v29 = v18;
        if ( pRemovedEntities != nullptr )
        {
          v30 = (int)pRemovedEntities[1].m_pMemory;
          m_nAllocationCount = pRemovedEntities->m_nAllocationCount;
          if ( v30 + 1 > m_nAllocationCount )
            CUtlMemory<CVisGroup *,int>::Grow(this: pRemovedEntities, num: v30 - m_nAllocationCount + 1);
          ++pRemovedEntities[1].m_pMemory;
          v32 = (CMapEntity **)pRemovedEntities->m_pMemory;
          v33 = (int)pRemovedEntities[1].m_pMemory - v30 - 1;
          pRemovedEntities[1].m_nAllocationCount = (int)pRemovedEntities->m_pMemory;
          if ( v33 > 0 )
            _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
          v34 = (CMapEntity **)&pRemovedEntities->m_pMemory[v30];
          if ( v34 != nullptr )
            *v34 = v18;
        }
      }
LABEL_49:
      v11 = pWorld;
      v12 = pos + 1;
      pos = v12;
      if ( v12 >= pWorld->m_EntityList.m_Size )
      {
        m_nGrowSize = RemoveList.m_Memory.m_nGrowSize;
        break;
      }
    }
  }
  if ( nMode != 3 )
  {
    for ( i = 0; i < RemoveList.m_Size; ++i )
    {
      v37 = RemoveList.m_Memory.m_pMemory[i];
      History = GetHistory();
      CHistory::KeepForDestruction(this: History, pObject: v37);
      CMapDoc::RemoveObjectFromWorld(this: pDoc, pObject: RemoveList.m_Memory.m_pMemory[i], bRemoveChildren: true);
    }
  }
  v52 = 3;
  RemoveList.m_Size = 0;
  if ( m_nGrowSize >= 0 )
  {
    if ( RemoveList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: RemoveList.m_Memory.m_pMemory);
      RemoveList.m_Memory.m_pMemory = nullptr;
    }
    RemoveList.m_Memory.m_nAllocationCount = 0;
  }
  RemoveList.m_pElements = RemoveList.m_Memory.m_pMemory;
  v52 = -1;
  if ( m_nGrowSize >= 0 && RemoveList.m_Memory.m_pMemory != nullptr )
    free(pMem: RemoveList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1016B580
// Name: private: void CToolEntitySprinkle::CreateMapObject(class Vector __near &,class KeyValues __near *,int,bool,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::CreateMapObject(
        CToolEntitySprinkle *this,
        Vector *vOrigin,
        KeyValues *pSprinkleType,
        int nMode,
        bool bRandomYaw,
        CMapEntity *pExisting)
{
  int v6; // edi
  IUniformRandomStream *v7; // ecx
  KeyValues *i; // esi
  const char *Name; // eax
  int v10; // ebx
  int v11; // esi
  KeyValues *FirstSubKey; // edi
  const char *v13; // eax
  KeyValues *Key; // esi
  CMapEntity *v15; // esi
  CMapEntity *v16; // eax
  CMapEntity *v17; // eax
  const char *String; // eax
  CToolEntitySprinkle *v19; // edi
  IUniformRandomStream *v20; // ecx
  float v21; // xmm0_4
  void (__thiscall *SetAngles)(CEditGameClass *, const QAngle *); // edx
  CHistory *History; // eax
  KeyValues *v24; // [esp-8h] [ebp-3Ch]
  QAngle vAngles; // [esp+Ch] [ebp-28h] BYREF
  KeyValues *pBaseInfo; // [esp+18h] [ebp-1Ch]
  void (__thiscall **v27)(CEditGameClass *, const char *, _DWORD); // [esp+1Ch] [ebp-18h]
  CToolEntitySprinkle *v28; // [esp+20h] [ebp-14h]
  KeyValues *pClass; // [esp+24h] [ebp-10h]
  int v30; // [esp+30h] [ebp-4h]

  v28 = this;
  v6 = 0;
  for ( i = KeyValues::GetFirstSubKey(this: pSprinkleType); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    v6 += atoi(nptr: Name);
  }
  v10 = _RandomInt(this: v7, a2: 1, a3: v6);
  v11 = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pSprinkleType);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      v13 = KeyValues::GetName(this: FirstSubKey);
      v11 += atoi(nptr: v13);
      if ( v10 <= v11 )
        break;
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        return;
    }
    Key = KeyValues::FindKey(this: pSprinkleType, keyName: "base", bCreate: false);
    pBaseInfo = Key;
    pClass = KeyValues::FindKey(this: FirstSubKey, keyName: "classname", bCreate: false);
    if ( pClass != nullptr
      || Key != nullptr && (pClass = KeyValues::FindKey(this: Key, keyName: "classname", bCreate: false)) != nullptr )
    {
      v15 = pExisting;
      if ( pExisting == nullptr )
      {
        v16 = (CMapEntity *)operator new(nSize: 0x184u);
        v27 = (void (__thiscall **)(CEditGameClass *, const char *, _DWORD))v16;
        v30 = 0;
        if ( v16 != nullptr )
          v17 = CMapEntity::CMapEntity(this: v16);
        else
          v17 = nullptr;
        v30 = -1;
        v15 = v17;
      }
      v15->SetOrigin(this: v15, a2: vOrigin);
      v27 = (void (__thiscall **)(CEditGameClass *, const char *, _DWORD))v15->CEditGameClass::__vftable;
      String = KeyValues::GetString(this: pClass, keyName: nullptr, defaultValue: &var);
      (*v27)(a1: &v15->CEditGameClass, a2: String, a3: 0);
      CToolEntitySprinkle::PopulateEntity(this: v28, pEntity: v15, pFields: pBaseInfo);
      v24 = FirstSubKey;
      v19 = v28;
      CToolEntitySprinkle::PopulateEntity(this: v28, pEntity: v15, pFields: v24);
      if ( bRandomYaw )
      {
        v15->GetAngles(this: &v15->CEditGameClass, a2: &vAngles);
        v21 = (float)_RandomInt(this: v20, a2: 0, a3: 360);
        SetAngles = v15->SetAngles;
        vAngles.y = v21;
        SetAngles(this: &v15->CEditGameClass, a2: &vAngles);
      }
      if ( pExisting == nullptr )
      {
        v19->m_pDocument->AddObjectToWorld(this: v19->m_pDocument, a2: v15, a3: nullptr);
        History = GetHistory();
        CHistory::KeepNew(this: History, pObject: v15, bKeepChildren: true);
        CToolEntitySprinkle::RemoveMapObjects(
          this: v19,
          vOrigin,
          pSprinkleType,
          nMode,
          nDensity: 0,
          pRemovedEntities: nullptr,
          pTouchedEntity: v15);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B7A0
// Name: private: void CToolEntitySprinkle::PerformSprinkle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::PerformSprinkle(CToolEntitySprinkle *this, bool bInitial)
{
  KeyValues *SprinkleType; // ebx
  LRESULT SprinkleDensity; // eax
  CEntitySprinkleDlg *pSprinkleDlg; // ecx
  LRESULT SprinkleMode; // edi
  bool v7; // al
  float m_BrushSize; // xmm0_4
  CHistory *History; // eax
  IUniformRandomStream *v10; // ecx
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int v15; // eax
  bool v16; // cf
  CMapEntity **m_pMemory; // eax
  int i; // edi
  const CUtlReferenceVector<CMapClass> *List; // [esp-14h] [ebp-74h]
  CUtlVector<CMapEntity *,CUtlMemory<CMapEntity *,int> > ReplacedEntities; // [esp+4h] [ebp-5Ch] BYREF
  Vector vOrigin; // [esp+18h] [ebp-48h] BYREF
  Vector vCenter; // [esp+24h] [ebp-3Ch] BYREF
  float flGridXSize; // [esp+30h] [ebp-30h] BYREF
  float v24; // [esp+34h] [ebp-2Ch]
  float flGridYSize; // [esp+38h] [ebp-28h] BYREF
  float flBrushSizeSq; // [esp+3Ch] [ebp-24h]
  BOOL bRandomYaw; // [esp+40h] [ebp-20h]
  float flXSize; // [esp+44h] [ebp-1Ch] BYREF
  float flYSize; // [esp+48h] [ebp-18h] BYREF
  int nDensity; // [esp+4Ch] [ebp-14h]
  float x; // [esp+50h] [ebp-10h]
  int v32; // [esp+5Ch] [ebp-4h]
  float y; // [esp+68h] [ebp+8h]

  if ( !this->m_bWorldValid )
    return;
  SprinkleType = CEntitySprinkleDlg::GetSprinkleType(this: this->pSprinkleDlg);
  if ( SprinkleType == nullptr )
    return;
  SprinkleDensity = CEntitySprinkleDlg::GetSprinkleDensity(this: this->pSprinkleDlg);
  pSprinkleDlg = this->pSprinkleDlg;
  nDensity = SprinkleDensity;
  SprinkleMode = CEntitySprinkleDlg::GetSprinkleMode(this: pSprinkleDlg);
  v7 = CEntitySprinkleDlg::UseRandomYaw(this: this->pSprinkleDlg);
  m_BrushSize = this->m_BrushSize;
  LOBYTE(bRandomYaw) = v7;
  vCenter.z = this->m_vWorldMousePoint.z;
  flBrushSizeSq = m_BrushSize * m_BrushSize;
  *(_QWORD *)&vCenter.x = *(_QWORD *)&this->m_vWorldMousePoint.x;
  memset(&ReplacedEntities, 0, sizeof(ReplacedEntities));
  v32 = 1;
  if ( bInitial )
  {
    List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Sprinkle", bFromOpposite: 0);
  }
  else if ( this->m_vLastDrawPoint.x == vCenter.x && this->m_vLastDrawPoint.y == vCenter.y )
  {
    v32 = -1;
    CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&ReplacedEntities);
    return;
  }
  CToolEntitySprinkle::CalcGridInfo(
    this,
    pSprinkleType: SprinkleType,
    &flGridXSize,
    &flGridYSize,
    &flXSize,
    &flYSize,
    &vCenter);
  if ( this->m_bCtrlDown )
    SprinkleMode = 1;
  this->m_vLastDrawPoint = vCenter;
  if ( SprinkleMode == 2 || SprinkleMode == 3 )
    CToolEntitySprinkle::RemoveMapObjects(
      this,
      vOrigin: &this->m_vWorldMousePoint,
      pSprinkleType: SprinkleType,
      nMode: SprinkleMode,
      nDensity,
      pRemovedEntities: (CUtlMemory<CCullTreeNode *,int> *)&ReplacedEntities,
      pTouchedEntity: nullptr);
  if ( SprinkleMode != 1 )
  {
    if ( SprinkleMode == 3 )
    {
      for ( i = 0; i < ReplacedEntities.m_Size; ++i )
      {
        ReplacedEntities.m_Memory.m_pMemory[i]->GetOrigin(this: ReplacedEntities.m_Memory.m_pMemory[i], a2: &vOrigin);
        CToolEntitySprinkle::CreateMapObject(
          this,
          &vOrigin,
          pSprinkleType: SprinkleType,
          nMode: 3,
          bRandomYaw,
          pExisting: ReplacedEntities.m_Memory.m_pMemory[i]);
      }
      goto LABEL_24;
    }
    v11 = flXSize;
    v12 = -flXSize;
    x = -flXSize;
    if ( flXSize >= (float)-flXSize )
    {
      v13 = flYSize;
      v14 = -flYSize;
      v24 = -flYSize;
      do
      {
        y = v14;
        if ( v13 >= v14 )
        {
          do
          {
            v15 = _RandomInt(this: v10, a2: 1, a3: 100);
            if ( v15 <= nDensity )
            {
              vOrigin.x = x + vCenter.x;
              vOrigin.y = y + vCenter.y;
              vOrigin.z = vCenter.z;
              if ( CToolEntitySprinkle::FindWorldSpot(this, &vOrigin) == 1
                && (float)((float)((float)((float)(vOrigin.y - this->m_vWorldMousePoint.y)
                                         * (float)(vOrigin.y - this->m_vWorldMousePoint.y))
                                 + (float)((float)(vOrigin.x - this->m_vWorldMousePoint.x)
                                         * (float)(vOrigin.x - this->m_vWorldMousePoint.x)))
                         + (float)((float)(vOrigin.z - this->m_vWorldMousePoint.z)
                                 * (float)(vOrigin.z - this->m_vWorldMousePoint.z))) <= flBrushSizeSq )
              {
                CToolEntitySprinkle::CreateMapObject(
                  this,
                  &vOrigin,
                  pSprinkleType: SprinkleType,
                  nMode: SprinkleMode,
                  bRandomYaw,
                  pExisting: nullptr);
              }
            }
            v13 = flYSize;
            v16 = flYSize < (float)(y + flGridYSize);
            y = y + flGridYSize;
          }
          while ( !v16 );
          v14 = v24;
          v12 = x;
          v11 = flXSize;
        }
        v12 = v12 + flGridXSize;
        x = v12;
      }
      while ( v11 >= v12 );
    }
  }
  if ( SprinkleMode == 1 )
    CToolEntitySprinkle::RemoveMapObjects(
      this,
      vOrigin: &this->m_vWorldMousePoint,
      pSprinkleType: SprinkleType,
      nMode: 1,
      nDensity,
      pRemovedEntities: nullptr,
      pTouchedEntity: nullptr);
LABEL_24:
  this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  v32 = 2;
  m_pMemory = ReplacedEntities.m_Memory.m_pMemory;
  ReplacedEntities.m_Size = 0;
  if ( ReplacedEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( ReplacedEntities.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: ReplacedEntities.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      ReplacedEntities.m_Memory.m_pMemory = nullptr;
    }
    ReplacedEntities.m_Memory.m_nAllocationCount = 0;
  }
  ReplacedEntities.m_pElements = m_pMemory;
  v32 = -1;
  if ( ReplacedEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( ReplacedEntities.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: ReplacedEntities.m_Memory.m_pMemory);
      ReplacedEntities.m_Memory.m_pMemory = nullptr;
    }
    ReplacedEntities.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BB50
// Name: public: virtual bool CToolEntitySprinkle::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnMouseMove3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  SHORT AsyncKeyState; // ax
  bool m_InSizingMode; // zf

  AsyncKeyState = GetAsyncKeyState(vKey: 17);
  m_InSizingMode = this->m_InSizingMode;
  this->m_bCtrlDown = AsyncKeyState < 0;
  if ( m_InSizingMode )
  {
    CToolEntitySprinkle::DoSizing(this, vPoint);
    return 1;
  }
  else
  {
    if ( CToolEntitySprinkle::FindWorldMousePoint(this, pView, vPoint) == 1 && this->m_InDrawMode )
      CToolEntitySprinkle::PerformSprinkle(this, bInitial: false);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BBB0
// Name: public: virtual bool CToolEntitySprinkle::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolEntitySprinkle::OnLMouseDown3D(
        CToolEntitySprinkle *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  this->m_bCtrlDown = GetAsyncKeyState(vKey: 17) < 0;
  if ( CToolEntitySprinkle::FindWorldMousePoint(this, pView, vPoint) == 1 && !this->m_InSizingMode )
  {
    this->m_InDrawMode = true;
    CToolEntitySprinkle::PerformSprinkle(this, bInitial: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016BC00
// Name: public: virtual void CToolEntitySprinkle::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::OnActivate(CToolEntitySprinkle *this)
{
  char *v2; // eax
  CEntitySprinkleDlg *v3; // eax
  KeyValues *m_pSprinkleInfo; // ecx
  char *v5; // eax
  KeyValues *v6; // eax
  char *v7; // esi
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  char *m_pszData; // edi
  int findHandle; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > FullPath; // [esp+14h] [ebp-10h] BYREF
  int v15; // [esp+20h] [ebp-4h]

  if ( this->pSprinkleDlg == nullptr )
  {
    v2 = (char *)operator new(nSize: 0x51Cu);
    FullPath.m_pszData = v2;
    v15 = 0;
    if ( v2 != nullptr )
      v3 = CEntitySprinkleDlg::CEntitySprinkleDlg(this: (CEntitySprinkleDlg *)v2);
    else
      v3 = nullptr;
    v15 = -1;
    this->pSprinkleDlg = v3;
    v3->Create(this: v3, a2: 357u, a3: nullptr);
  }
  m_pSprinkleInfo = this->m_pSprinkleInfo;
  if ( m_pSprinkleInfo != nullptr )
  {
    KeyValues::deleteThis(this: m_pSprinkleInfo);
    this->m_pSprinkleInfo = nullptr;
  }
  v5 = (char *)KeyValues::operator new(iAllocSize: 0x24u);
  FullPath.m_pszData = v5;
  v15 = 1;
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: (KeyValues *)v5, setName: "Sprinkles");
  else
    v6 = nullptr;
  v15 = -1;
  this->m_pSprinkleInfo = v6;
  v7 = (char *)g_pFullFileSystem->FindFirstEx(
                 this: g_pFullFileSystem,
                 a2: "scripts/hammer/sprinkle/*.txt",
                 a3: "GAME",
                 a4: &findHandle);
  while ( v7 != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    FullPath.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v15 = 2;
    if ( ((unsigned int)"scripts/hammer/sprinkle/" & 0xFFFF0000) != 0 )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: &FullPath, pszSrc: "scripts/hammer/sprinkle/", nLength: 24);
    }
    else
    {
      StringResourceHandle = AfxFindStringResourceHandle(__formal: (unsigned __int16)"scripts/hammer/sprinkle/");
      if ( StringResourceHandle != nullptr )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
          this: &FullPath,
          hInstance: StringResourceHandle,
          nID: (unsigned __int16)"scripts/hammer/sprinkle/");
    }
    v15 = 3;
    ATL::CSimpleStringT<char,0>::Append(this: &FullPath, pszSrc: v7, nLength: strlen(v7));
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    LOBYTE(v15) = 4;
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "loading");
    else
      v11 = nullptr;
    LOBYTE(v15) = 3;
    m_pszData = FullPath.m_pszData;
    if ( !KeyValues::LoadFromFile(
            this: v11,
            filesystem: g_pFileSystem,
            resourceName: FullPath.m_pszData,
            pathID: "GAME",
            pfnEvaluateSymbolProc: nullptr) )
      KeyValues::deleteThis(this: v11);
    KeyValues::AddSubKey(this: this->m_pSprinkleInfo, pSubkey: v11);
    v7 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findHandle);
    v15 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
  CEntitySprinkleDlg::SetSprinkleTypes(this: this->pSprinkleDlg, pSprinkleInfo: this->m_pSprinkleInfo);
  CWnd::ShowWindow(this: this->pSprinkleDlg, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x102EDA70
// Name: public: virtual void CToolEntitySprinkle::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEntitySprinkle::RenderTool2D(vgui::TreeView *this, int itemIndex)
{
  ;
}
