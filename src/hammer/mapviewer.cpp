// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapviewer.cpp
// Functions: 16
// ============================================================

#include "hammer\mapviewer.h"

//------------------------------------------------------------------------------
// Address: 0x10133790
// Name: public: virtual char const __near * CMapViewer::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapViewer::GetDescription(CMapOccluder *this)
{
  return "FoW Viewer helper";
}

//------------------------------------------------------------------------------
// Address: 0x101337A0
// Name: public: virtual void CMapViewer::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::CalcBounds(CMapOccluder *this, int bFullUpdate)
{
  float m_flRadius; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, pt: &this->m_Origin);
  m_flRadius = this->m_flRadius;
  x = this->m_Origin.x;
  y = this->m_Origin.y;
  z = this->m_Origin.z;
  mins.x = x - m_flRadius;
  mins.y = y - m_flRadius;
  mins.z = z - m_flRadius;
  maxs.x = x + m_flRadius;
  maxs.y = y + m_flRadius;
  maxs.z = z + m_flRadius;
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, &mins, &maxs);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  v7 = this->m_flRadius;
  v8 = this->m_Origin.x;
  v9 = this->m_Origin.y;
  v10 = this->m_Origin.z;
  mins.x = v8 - v7;
  mins.y = v9 - v7;
  mins.z = v10 - v7;
  maxs.x = v8 + v7;
  maxs.y = v9 + v7;
  maxs.z = v10 + v7;
  BoundBox::UpdateBounds(this: &this->m_CullBox, &mins, &maxs);
  BoundBox::ResetBounds(this: &this->m_BoundingBox);
}

//------------------------------------------------------------------------------
// Address: 0x10148B80
// Name: public: virtual char const __near * CMapViewer::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapViewer::GetType(CMapViewer *this)
{
  return CMapViewer::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10148B90
// Name: public: virtual int CMapViewer::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapViewer::IsMapClass(CMapViewer *this, const char *Type)
{
  return Type == CMapViewer::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10148BB0
// Name: public: virtual class CMapClass __near * CMapViewer::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__thiscall CMapViewer::Copy(CMapViewer *this, BOOL bUpdateDependencies)
{
  CMapSphere *v2; // eax
  CMapSphere *v3; // esi

  v2 = (CMapSphere *)operator new(nSize: 0x130u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CMapSphere::CMapSphere(this: v2);
    v3->__vftable = (CMapSphere_vtbl *)&CMapViewer::`vftable';
    v3->m_szKeyName[0] = 0;
    v3->m_flRadius = 0.0;
    *(_WORD *)&v3->r = -256;
    v3->b = 0;
    CMapClass::SetVisible(this: v3, bVisible: true);
    *((_BYTE *)&v3->CMapClass + 180) |= 1u;
    v3[1].__vftable = (CMapSphere_vtbl *)-1;
  }
  else
  {
    v3 = nullptr;
  }
  if ( v3 != nullptr )
    v3->CopyFrom(this: v3, a2: this, a3: bUpdateDependencies);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10148C70
// Name: public: virtual class CBaseTool __near * CMapViewer::GetToolObject(int,bool)
// Source: json
//------------------------------------------------------------------------------
CToolPointHandle *__thiscall CMapViewer::GetToolObject(CMapOccluder *this, int nHitData, bool bAttachObject)
{
  CToolManager *v4; // eax
  CToolPointHandle *result; // eax
  CToolPointHandle *v6; // esi

  v4 = ToolManager();
  result = (CToolPointHandle *)CToolManager::GetToolForID(this: v4, eToolID: TOOL_SPHERE);
  v6 = result;
  if ( bAttachObject )
  {
    CToolSphere::Attach(this: result, pPoint: (CMapPointHandle *)this);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10148CA0
// Name: public: virtual void CMapViewer::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::OnParentKeyChanged(CMapViewer *this, const char *szKey, const char *szValue)
{
  CFoW *m_pFoW; // ecx

  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    this->m_flRadius = atof(nptr: szValue);
    this->PostUpdate(this, a2: Notify_Changed);
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr )
      CFoW::UpdateViewerSize(this: m_pFoW, nID: this->m_FoWHandle, flRadius: this->m_flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148D10
// Name: public: virtual void CMapViewer::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::OnRemoveFromWorld(CMapViewer *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CFoW *m_pFoW; // ecx

  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr && this->m_FoWHandle != -1 )
    CFoW::RemoveViewer(this: m_pFoW, nID: this->m_FoWHandle);
  this->m_FoWHandle = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10148D50
// Name: public: virtual void CMapViewer::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::Render2D(CMapViewer *this, CRender2D *pRender)
{
  Vector *p_m_Origin; // edi
  float x; // ebx
  float m_flRadius; // [esp-Ch] [ebp-34h]
  Vector v7; // [esp+4h] [ebp-24h] BYREF
  Vector vWorld; // [esp+10h] [ebp-18h] BYREF
  Vector2D ptClientRadius; // [esp+1Ch] [ebp-Ch]
  Vector2D offset; // [esp+24h] [ebp-4h]
  char radius_3; // [esp+33h] [ebp+Bh]

  if ( this->m_flRadius > 0.0 )
  {
    CRender::SetDrawColor(this: pRender, r: 0, g: 0xFFu, b: 0);
    v7.x = this->m_flRadius;
    v7.y = v7.x;
    v7.z = v7.x;
    CRender::TransformNormal(this: pRender, vClient: (Vector2D *)&vWorld, vWorld: &v7);
    p_m_Origin = &this->m_Origin;
    m_flRadius = this->m_flRadius;
    LODWORD(offset.x) = (int)vWorld.x;
    CRender2D::DrawCircle(
      this: pRender,
      a2: (unsigned int)this,
      a3: (unsigned int)&this->m_Origin,
      vCenter: &this->m_Origin,
      fRadius: m_flRadius);
    radius_3 = CRender::BeginClientSpace(this: pRender, a2: (int)pRender);
    CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
    CRender::SetHandleColor(this: pRender, r: 0, g: 0xFFu, b: 0);
    x = offset.x;
    vWorld.z = 0.0;
    offset.x = (float)(-6 - LODWORD(offset.x));
    ptClientRadius.x = offset.x;
    CRender::DrawHandle(this: pRender, vCenter: p_m_Origin, vOffset: (const Vector2D *)&vWorld.z);
    vWorld.z = 0.0;
    ptClientRadius.y = (float)(LODWORD(x) + 6);
    ptClientRadius.x = ptClientRadius.y;
    CRender::DrawHandle(this: pRender, vCenter: p_m_Origin, vOffset: (const Vector2D *)&vWorld.z);
    vWorld.z = offset.x;
    ptClientRadius.x = 0.0;
    CRender::DrawHandle(this: pRender, vCenter: p_m_Origin, vOffset: (const Vector2D *)&vWorld.z);
    vWorld.z = ptClientRadius.y;
    ptClientRadius.x = 0.0;
    CRender::DrawHandle(this: pRender, vCenter: p_m_Origin, vOffset: (const Vector2D *)&vWorld.z);
    vWorld.z = 0.0;
    ptClientRadius.x = 0.0;
    CRender::DrawHandle(this: pRender, vCenter: p_m_Origin, vOffset: (const Vector2D *)&vWorld.z);
    if ( radius_3 != 0 )
      CRender::EndClientSpace(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148EC0
// Name: public: virtual void CMapViewer::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::Render3D(CMapViewer *this, CRender3D *pRender)
{
  float m_flRadius; // xmm0_4

  m_flRadius = this->m_flRadius;
  if ( m_flRadius > 0.0 )
    CRender3D::RenderWireframeSphere(
      this: pRender,
      vCenter: &this->m_Origin,
      flRadius: m_flRadius,
      nTheta: 12,
      nPhi: 12,
      chRed: 0,
      chGreen: 0xFFu,
      chBlue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10148F00
// Name: public: virtual void CMapViewer::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::SetOrigin(CMapViewer *this, Vector *vecOrigin)
{
  CFoW *m_pFoW; // ecx

  CMapClass::SetOrigin(this, origin: vecOrigin);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateViewerLocation(this: m_pFoW, nID: this->m_FoWHandle, vLocation: vecOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x10148F40
// Name: protected: virtual void CMapViewer::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::DoTransform(CMapViewer *this, const VMatrix *matrix)
{
  CFoW *m_pFoW; // ecx

  CMapClass::DoTransform(this, matrix);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateViewerLocation(this: m_pFoW, nID: this->m_FoWHandle, vLocation: &this->m_Origin);
}

//------------------------------------------------------------------------------
// Address: 0x10148F80
// Name: protected: virtual void CMapViewer::SetRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapViewer::SetRadius(CMapViewer *this, float flRadius)
{
  CFoW *m_pFoW; // ecx

  CMapSphere::SetRadius(this, flRadius);
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    CFoW::UpdateViewerSize(this: m_pFoW, nID: this->m_FoWHandle, flRadius: this->m_flRadius);
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10148FE0
// Name: class CMapClass __near * CMapViewer_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__cdecl CMapViewer_CreateObject()
{
  CMapSphere *v0; // eax
  CMapSphere *v1; // esi
  CFoW *m_pFoW; // ecx

  v0 = (CMapSphere *)operator new(nSize: 0x130u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapSphere::CMapSphere(this: v0);
  v1->__vftable = (CMapSphere_vtbl *)&CMapViewer::`vftable';
  v1->m_szKeyName[0] = 0;
  v1->m_flRadius = 0.0;
  *(_WORD *)&v1->r = -256;
  v1->b = 0;
  CMapClass::SetVisible(this: v1, bVisible: true);
  *((_BYTE *)&v1->CMapClass + 180) |= 1u;
  v1[1].__vftable = (CMapSphere_vtbl *)-1;
  m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
  if ( m_pFoW != nullptr )
    v1[1].__vftable = (CMapSphere_vtbl *)CFoW::AddViewer(this: m_pFoW, nViewerTeam: 0);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10149140
// Name: public: virtual bool CMapViewer::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CMapViewer::HitTest2D@<al>(
        CMapOccluder *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CMapView2D *pView,
        const Vector2D *point,
        HitInfo_s *HitData)
{
  bool v7; // cf
  Vector *p_m_Origin; // ebx
  float z; // eax
  __int64 v11; // xmm0_8
  float y; // ebx
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // edx
  int axHorz; // eax
  float x; // xmm1_4
  float v16; // xmm2_4
  signed int v17; // eax
  HCURSOR CursorA; // eax
  Vector vecRadius; // [esp+0h] [ebp-34h] BYREF
  Vector2D vecClientMin; // [esp+Ch] [ebp-28h]
  Vector2D vecClientRadius; // [esp+14h] [ebp-20h] BYREF
  Vector2D vecClientOrigin; // [esp+1Ch] [ebp-18h] BYREF
  Vector2D vecTemp; // [esp+24h] [ebp-10h] BYREF
  Vector2D vecClientMax; // [esp+2Ch] [ebp-8h]

  v7 = this->m_flRadius > 0.0;
  LODWORD(vecClientMax.y) = this;
  if ( !v7 )
    return 0;
  p_m_Origin = &this->m_Origin;
  ((void (__thiscall *)(CMapView *, Vector2D *, Vector *, int, int, int))pView->WorldToClient)(
    a1: &pView->CMapView,
    a2: &vecClientOrigin,
    a3: &this->m_Origin,
    a4: a3,
    a5: a4,
    a6: a2);
  z = p_m_Origin->z;
  v11 = *(_QWORD *)&p_m_Origin->x;
  y = vecClientMax.y;
  WorldToClient = pView->WorldToClient;
  vecRadius.z = z;
  axHorz = pView->axHorz;
  *(_QWORD *)&vecRadius.x = v11;
  *(&vecRadius.x + axHorz) = *(float *)(LODWORD(vecClientMax.y) + 296) + *(&vecRadius.x + axHorz);
  WorldToClient(this: &pView->CMapView, a2: &vecClientRadius, a3: &vecRadius);
  x = vecClientOrigin.x;
  v16 = vecClientOrigin.y;
  v17 = (int)COERCE_FLOAT(COERCE_UNSIGNED_INT(vecClientRadius.x - vecClientOrigin.x) & _mask__AbsFloat_);
  HitData->uData = v17;
  vecClientMin.x = x - (float)v17;
  *(float *)&HitData->pObject = y;
  vecClientRadius.x = (float)v17;
  vecClientRadius.y = (float)v17;
  HitData->nDepth = 0;
  vecClientMax.x = x + (float)v17;
  vecClientMax.y = v16 + (float)v17;
  vecTemp.x = x;
  vecTemp.y = (float)(v16 - (float)v17) - 6.0;
  if ( CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 6)
    || (vecTemp.x = vecClientOrigin.x,
        vecTemp.y = vecClientMax.y + 6.0,
        CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 4)) )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
LABEL_9:
    SetCursor(hCursor: CursorA);
    return 1;
  }
  vecTemp.x = vecClientMin.x - 6.0;
  vecTemp.y = vecClientOrigin.y;
  if ( CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 4)
    || (vecTemp.x = vecClientMax.x + 6.0,
        vecTemp.y = vecClientOrigin.y,
        CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 4)) )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
    goto LABEL_9;
  }
  HitData->pObject = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10149320
// Name: public: static class CMapClass __near * CMapViewer::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__cdecl CMapViewer::Create(CHelperInfo *pHelperInfo)
{
  CMapSphere *v1; // eax
  CMapSphere *v2; // esi
  CFoW *m_pFoW; // ecx
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  char **m_pMemory; // edx
  char **v8; // ecx
  CMapSphere *chRed; // [esp+Ch] [ebp-18h]
  char chGreen; // [esp+10h] [ebp-14h]
  char chBlue; // [esp+14h] [ebp-10h]

  v1 = (CMapSphere *)operator new(nSize: 0x130u);
  v2 = v1;
  chRed = v1;
  if ( v1 != nullptr )
  {
    CMapSphere::CMapSphere(this: v1);
    v2->__vftable = (CMapSphere_vtbl *)&CMapViewer::`vftable';
    v2->m_szKeyName[0] = 0;
    v2->m_flRadius = 0.0;
    *(_WORD *)&v2->r = -256;
    v2->b = 0;
    CMapClass::SetVisible(this: v2, bVisible: true);
    *((_BYTE *)&v2->CMapClass + 180) |= 1u;
    v2[1].__vftable = (CMapSphere_vtbl *)-1;
    m_pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( m_pFoW != nullptr )
      v2[1].__vftable = (CMapSphere_vtbl *)CFoW::AddViewer(this: m_pFoW, nViewerTeam: 0);
  }
  else
  {
    v2 = nullptr;
  }
  if ( v2 != nullptr )
  {
    if ( pHelperInfo->m_Parameters.m_Size > 0 && (v4 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr )
    {
      v5 = v2->m_szKeyName - v4;
      do
      {
        v6 = *v4;
        v4[v5] = *v4;
        ++v4;
      }
      while ( v6 != 0 );
    }
    else
    {
      strcpy(v2->m_szKeyName, "radius");
    }
    LOBYTE(chRed) = -1;
    chGreen = -1;
    chBlue = -1;
    if ( pHelperInfo->m_Parameters.m_Size > 1 )
    {
      m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( m_pMemory[1] != nullptr )
        LOBYTE(chRed) = atoi(nptr: m_pMemory[1]);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 2 && *((_DWORD *)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 2) != 0 )
      chGreen = atoi(nptr: *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 2));
    if ( pHelperInfo->m_Parameters.m_Size > 3 )
    {
      v8 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( v8[3] != nullptr )
        chBlue = atoi(nptr: v8[3]);
    }
    v2->SetRenderColor_2(this: v2, a2: (unsigned __int8)chRed, a3: chGreen, a4: chBlue);
  }
  return v2;
}
