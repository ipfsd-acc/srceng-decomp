// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapsphere.cpp
// Functions: 16
// ============================================================

#include "hammer\mapsphere.h"

//------------------------------------------------------------------------------
// Address: 0x10133990
// Name: public: virtual class CMapClass __near * CMapSphere::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapOccluder *__thiscall CMapSphere::CopyFrom(CMapOccluder *this, CMapClass *pObject, bool bUpdateDependencies)
{
  CMapClass *v4; // eax
  char v5; // cl

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  v4 = pObject + 1;
  this->m_flRadius = pObject[1].m_BoundingBox.bmins.z;
  do
  {
    v5 = (char)v4->__vftable;
    *((_BYTE *)&v4->__vftable + (char *)this - (char *)pObject) = v4->__vftable;
    v4 = (CMapClass *)((char *)v4 + 1);
  }
  while ( v5 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101446B0
// Name: public: virtual char const __near * CMapSphere::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSphere::GetType(CMapSphere *this)
{
  return CMapSphere::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101446C0
// Name: public: virtual int CMapSphere::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapSphere::IsMapClass(CMapSphere *this, const char *Type)
{
  return Type == CMapSphere::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101446E0
// Name: public: virtual CMapSphere::~CMapSphere(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::~CMapSphere(CMapSphere *this)
{
  this->__vftable = (CMapSphere_vtbl *)&CMapSphere::`vftable';
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x10144720
// Name: public: virtual char const __near * CMapSphere::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapSphere::GetDescription(CMapSphere *this)
{
  return "Sphere helper";
}

//------------------------------------------------------------------------------
// Address: 0x10144730
// Name: public: virtual void CMapSphere::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::CalcBounds(CMapSphere *this, int bFullUpdate)
{
  float m_flRadius; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, pt: &this->m_Origin);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  m_flRadius = this->m_flRadius;
  x = this->m_Origin.x;
  mins.x = x - m_flRadius;
  y = this->m_Origin.y;
  z = this->m_Origin.z;
  mins.y = y - m_flRadius;
  mins.z = z - m_flRadius;
  maxs.x = x + m_flRadius;
  maxs.y = y + m_flRadius;
  maxs.z = z + m_flRadius;
  BoundBox::UpdateBounds(this: &this->m_CullBox, &mins, &maxs);
  BoundBox::ResetBounds(this: &this->m_BoundingBox);
}

//------------------------------------------------------------------------------
// Address: 0x101447E0
// Name: protected: virtual void CMapSphere::SetRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::SetRadius(CMapSphere *this, float flRadius)
{
  CMapEntity *v3; // edi
  char string[4]; // [esp+10h] [ebp-50h] BYREF

  this->m_flRadius = rint(f: flRadius);
  v3 = (CMapEntity *)__RTDynamicCast(
                       inptr: this->m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 != nullptr )
  {
    sprintf(string, format: "%g", this->m_flRadius);
    CMapEntity::NotifyChildKeyChanged(this: v3, pChild: this, szKey: this->m_szKeyName, szValue: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144860
// Name: public: virtual void CMapSphere::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::OnParentKeyChanged(CMapSphere *this, const char *szKey, const char *szValue)
{
  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    this->m_flRadius = atof(nptr: szValue);
    this->PostUpdate(this, a2: Notify_Changed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101448A0
// Name: public: virtual void CMapSphere::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::Render2D(CMapSphere *this, CRender2D *pRender)
{
  Vector *p_m_Origin; // edi
  float x; // ebx
  float m_flRadius; // [esp-Ch] [ebp-34h]
  Vector v7; // [esp+4h] [ebp-24h] BYREF
  Vector vWorld; // [esp+10h] [ebp-18h] BYREF
  Vector2D ptClientRadius; // [esp+1Ch] [ebp-Ch]
  Vector2D offset; // [esp+24h] [ebp-4h]
  char radius_3; // [esp+33h] [ebp+Bh]

  if ( this->m_pParent->IsSelected(this: this->m_pParent) && this->m_flRadius > 0.0 )
  {
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
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
    CRender::SetHandleColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu);
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
    if ( radius_3 != 0 )
      CRender::EndClientSpace(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144A10
// Name: public: virtual void CMapSphere::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSphere::Render3D(CMapSphere *this, CRender3D *pRender)
{
  float m_flRadius; // xmm0_4

  if ( this->m_pParent->IsSelected(this: this->m_pParent) )
  {
    m_flRadius = this->m_flRadius;
    if ( m_flRadius > 0.0 )
      CRender3D::RenderWireframeSphere(
        this: pRender,
        vCenter: &this->m_Origin,
        flRadius: m_flRadius,
        nTheta: 12,
        nPhi: 12,
        chRed: 0xFFu,
        chGreen: 0xFFu,
        chBlue: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10144A60
// Name: public: CMapSphere::CMapSphere(void)
// Source: json
//------------------------------------------------------------------------------
CMapSphere *__thiscall CMapSphere::CMapSphere(CMapSphere *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapSphere_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapSphere_vtbl *)&CMapSphere::`vftable';
  this->m_szKeyName[0] = 0;
  this->m_flRadius = 0.0;
  *(_WORD *)&this->r = -1;
  this->b = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10144B30
// Name: public: virtual class CMapClass __near * CMapSphere::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapSphere::Copy(CMapSphere *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0x12Cu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapSphere::`vftable';
    LOBYTE(v4[1].__vftable) = 0;
    v4[1].m_BoundingBox.bmins.z = 0.0;
    *(_WORD *)&v4->r = -1;
    v4->b = 0;
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10144BE0
// Name: public: virtual bool CMapSphere::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSphere::HitTest2D(CMapSphere *this, CMapView2D *pView, const Vector2D *point, HitInfo_s *HitData)
{
  bool v5; // zf
  Vector *p_m_Origin; // ebx
  float z; // eax
  __int64 v8; // xmm0_8
  float y; // ebx
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // edx
  int axHorz; // eax
  float x; // xmm1_4
  float v13; // xmm2_4
  signed int v14; // eax
  HCURSOR CursorA; // eax
  Vector vecRadius; // [esp+4h] [ebp-34h] BYREF
  Vector2D vecClientMin; // [esp+10h] [ebp-28h]
  Vector2D vecClientRadius; // [esp+18h] [ebp-20h] BYREF
  Vector2D vecClientOrigin; // [esp+20h] [ebp-18h] BYREF
  Vector2D vecTemp; // [esp+28h] [ebp-10h] BYREF
  Vector2D vecClientMax; // [esp+30h] [ebp-8h]

  v5 = (*((_BYTE *)&this->CMapClass + 180) & 2) == 0;
  LODWORD(vecClientMax.y) = this;
  if ( v5 || this->m_flRadius <= 0.0 || !this->IsSelected(this) )
    return 0;
  p_m_Origin = &this->m_Origin;
  pView->WorldToClient(this: &pView->CMapView, a2: &vecClientOrigin, a3: p_m_Origin);
  z = p_m_Origin->z;
  v8 = *(_QWORD *)&p_m_Origin->x;
  y = vecClientMax.y;
  WorldToClient = pView->WorldToClient;
  vecRadius.z = z;
  axHorz = pView->axHorz;
  *(_QWORD *)&vecRadius.x = v8;
  *(&vecRadius.x + axHorz) = *(float *)(LODWORD(vecClientMax.y) + 296) + *(&vecRadius.x + axHorz);
  WorldToClient(this: &pView->CMapView, a2: &vecClientRadius, a3: &vecRadius);
  x = vecClientOrigin.x;
  v13 = vecClientOrigin.y;
  v14 = (int)COERCE_FLOAT(COERCE_UNSIGNED_INT(vecClientRadius.x - vecClientOrigin.x) & _mask__AbsFloat_);
  HitData->uData = v14;
  vecClientMin.x = x - (float)v14;
  *(float *)&HitData->pObject = y;
  vecClientRadius.x = (float)v14;
  vecClientRadius.y = (float)v14;
  HitData->nDepth = 0;
  vecClientMax.x = x + (float)v14;
  vecClientMax.y = v13 + (float)v14;
  vecTemp.x = x;
  vecTemp.y = (float)(v13 - (float)v14) - 6.0;
  if ( CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 6)
    || (vecTemp.x = vecClientOrigin.x,
        vecTemp.y = vecClientMax.y + 6.0,
        CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecTemp, nDist: 4)) )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
LABEL_10:
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
    goto LABEL_10;
  }
  HitData->pObject = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144DE0
// Name: class CMapClass __near * CMapSphere_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapSphere_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0x12Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapSphere::`vftable';
  LOBYTE(v1[1].__vftable) = 0;
  v1[1].m_BoundingBox.bmins.z = 0.0;
  *(_WORD *)&v1->r = -1;
  v1->b = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10144E80
// Name: public: static class CMapClass __near * CMapSphere::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapSphere::Create(CHelperInfo *pHelperInfo)
{
  CMapClass *v1; // eax
  CMapClass *v2; // esi
  char *v3; // eax
  int v4; // edx
  char v5; // cl
  char **m_pMemory; // ecx
  char **v7; // edx
  CMapClass *chRed; // [esp+8h] [ebp-18h]
  char chGreen; // [esp+Ch] [ebp-14h]
  char chBlue; // [esp+10h] [ebp-10h]

  v1 = (CMapClass *)operator new(nSize: 0x12Cu);
  v2 = v1;
  chRed = v1;
  if ( v1 != nullptr )
  {
    CMapClass::CMapClass(this: v1);
    v2->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v2->__vftable = (CMapClass_vtbl *)&CMapSphere::`vftable';
    LOBYTE(v2[1].__vftable) = 0;
    v2[1].m_BoundingBox.bmins.z = 0.0;
    *(_WORD *)&v2->r = -1;
    v2->b = 0;
  }
  else
  {
    v2 = nullptr;
  }
  if ( v2 != nullptr )
  {
    if ( pHelperInfo->m_Parameters.m_Size > 0 && (v3 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) != nullptr )
    {
      v4 = (char *)&v2[1] - v3;
      do
      {
        v5 = *v3;
        v3[v4] = *v3;
        ++v3;
      }
      while ( v5 != 0 );
    }
    else
    {
      strcpy((char *)&v2[1], "radius");
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
    if ( pHelperInfo->m_Parameters.m_Size > 2 )
    {
      v7 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
      if ( v7[2] != nullptr )
        chGreen = atoi(nptr: v7[2]);
    }
    if ( pHelperInfo->m_Parameters.m_Size > 3 && *((_DWORD *)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3) != 0 )
      chBlue = atoi(nptr: *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3));
    v2->SetRenderColor_2(this: v2, a2: (unsigned __int8)chRed, a3: chGreen, a4: chBlue);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x104DB670
// Name: public: virtual bool CMapSphere::IsVisualElement(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapSphere::IsVisualElement(vgui::ToggleButton *this)
{
  return false;
}
