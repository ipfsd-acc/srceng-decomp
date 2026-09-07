// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapplayerhullhandle.cpp
// Functions: 19
// ============================================================

#include "hammer\mapplayerhullhandle.h"

//------------------------------------------------------------------------------
// Address: 0x1013C8D0
// Name: public: virtual char const __near * CMapPlayerHullHandle::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapPlayerHullHandle::GetType(CMapPlayerHullHandle *this)
{
  return CMapPlayerHullHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013C8E0
// Name: public: virtual int CMapPlayerHullHandle::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapPlayerHullHandle::IsMapClass(CMapPlayerHullHandle *this, const char *Type)
{
  return Type == CMapPlayerHullHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013C900
// Name: public: virtual char const __near * CMapPlayerHullHandle::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapPlayerHullHandle::GetDescription(CMapPlayerHullHandle *this)
{
  return "Player hull handle";
}

//------------------------------------------------------------------------------
// Address: 0x1013C910
// Name: public: void CMapPlayerHullHandle::Attach(class CMapSweptPlayerHull __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::Attach(CMapPlayerHullHandle *this, CMapSweptPlayerHull *pOwner)
{
  this->m_pOwner = pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x1013C920
// Name: public: virtual class CMapClass __near * CMapPlayerHullHandle::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapPlayerHullHandle *__thiscall CMapPlayerHullHandle::CopyFrom(
        CMapPlayerHullHandle *this,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  int *p_m_nObjectID; // eax
  char v5; // cl

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  p_m_nObjectID = &pObject[1].m_nObjectID;
  do
  {
    v5 = *(_BYTE *)p_m_nObjectID;
    *((_BYTE *)p_m_nObjectID + (char *)this - (char *)pObject) = *(_BYTE *)p_m_nObjectID;
    p_m_nObjectID = (int *)((char *)p_m_nObjectID + 1);
  }
  while ( v5 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C960
// Name: public: virtual bool CMapPlayerHullHandle::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapPlayerHullHandle::HitTest2D(
        CMapPlayerHullHandle *this,
        CMapView2D *pView,
        const Vector2D *point,
        HitInfo_s *HitData)
{
  Vector2D vecClient; // [esp+4h] [ebp-8h] BYREF

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  pView->WorldToClient(this: &pView->CMapView, a2: &vecClient, a3: &this->m_Origin);
  if ( !CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecClient, nDist: 4) )
    return 0;
  HitData->pObject = this;
  HitData->uData = 0;
  HitData->nDepth = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013C9C0
// Name: public: virtual void CMapPlayerHullHandle::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::Render2D(CMapPlayerHullHandle *this, CRender2D *pRender)
{
  SelectionState_t v3; // ebx
  Vector vCenter; // [esp+Ch] [ebp-2Ch] BYREF
  Vector vecMins; // [esp+18h] [ebp-20h] BYREF
  Vector vecMaxs; // [esp+24h] [ebp-14h] BYREF
  color32_s rgbColor; // [esp+30h] [ebp-8h] BYREF

  v3 = this->GetSelectionState(this);
  if ( v3 == SELECT_MODIFY )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_DOTTED);
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrSelection,
      g: BYTE1(Options.colors.clrSelection),
      b: BYTE2(Options.colors.clrSelection));
  }
  else
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_FLAT);
    CRender::SetDrawColor(
      this: pRender,
      r: Options.colors.clrToolHandle,
      g: BYTE1(Options.colors.clrToolHandle),
      b: BYTE2(Options.colors.clrToolHandle));
  }
  CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
  pRender->DrawBox(this: pRender, a2: &vecMins, a3: &vecMaxs, a4: false);
  CRender::PopRenderMode(this: pRender);
  ((void (__thiscall *)(CMapPlayerHullHandle *, color32_s *))this->GetRenderColor)(a1: this, a2: &rgbColor);
  CRender::SetDrawColor(this: pRender, r: rgbColor.r, g: rgbColor.g, b: rgbColor.b);
  if ( v3 != SELECT_NONE )
    CRender::SetHandleStyle(this: pRender, size: 4, type: 2);
  else
    CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
  vCenter.x = (float)(vecMaxs.x + vecMins.x) * 0.5;
  vCenter.y = (float)(vecMins.y + vecMaxs.y) * 0.5;
  vCenter.z = (float)(vecMaxs.z + vecMins.z) * 0.5;
  CRender::DrawHandle(this: pRender, &vCenter, vOffset: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1013CAD0
// Name: public: virtual void CMapPlayerHullHandle::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::Render3D(CMapPlayerHullHandle *this, CRender3D *pRender)
{
  CMapClass *v3; // eax
  Vector vecOrigin; // [esp+8h] [ebp-24h] BYREF
  Vector Mins; // [esp+14h] [ebp-18h] BYREF
  Vector Maxs; // [esp+20h] [ebp-Ch] BYREF

  if ( this->GetSelectionState(this) != SELECT_NONE )
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
  else
    CRender::SetDrawColor(this: pRender, r: 0xC8u, g: 0xB4u, b: 0);
  Mins = this->m_Render2DBox.bmins;
  Maxs = this->m_Render2DBox.bmaxs;
  CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
  CRender3D::RenderBox(
    this: pRender,
    &Mins,
    &Maxs,
    chRed: 0xC8u,
    chGreen: 0xB4u,
    chBlue: 0,
    eBoxSelectionState: SELECT_NONE);
  CRender3D::EndRenderHitTarget(this: pRender, a2: (int)pRender);
  if ( this->m_pParent != nullptr && this->m_bDrawLineToParent )
  {
    v3 = this->GetParent(this);
    v3->GetOrigin(this: v3, a2: &vecOrigin);
    CRender::DrawLine(
      this: pRender,
      a2: (int)pRender,
      a3: (int)&this->m_Origin,
      vStart: &this->m_Origin,
      vEnd: &vecOrigin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CBB0
// Name: public: virtual void CMapPlayerHullHandle::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::OnParentKeyChanged(
        CMapPlayerHullHandle *this,
        const char *szKey,
        const char *szValue)
{
  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Origin, &this->m_Origin.y, &this->m_Origin.z);
    this->CalcBounds(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CC00
// Name: private: void CMapPlayerHullHandle::UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::UpdateParentKey(CMapPlayerHullHandle *this)
{
  Vector *p_m_Origin; // esi
  int i; // ebx
  double v4; // st7
  CMapEntity *v5; // esi
  char string[12]; // [esp+10h] [ebp-204h] BYREF

  p_m_Origin = &this->m_Origin;
  for ( i = 3; i != 0; --i )
  {
    v4 = rint(f: p_m_Origin->x * 100.0);
    p_m_Origin = (Vector *)((char *)p_m_Origin + 4);
    p_m_Origin[-1].z = v4 * 0.0099999998;
  }
  if ( this->m_szKeyName[0] != 0 )
  {
    v5 = (CMapEntity *)__RTDynamicCast(
                         inptr: this->m_pParent,
                         VfDelta: 0,
                         SrcType: &CMapAtom `RTTI Type Descriptor',
                         TargetType: &CMapEntity `RTTI Type Descriptor',
                         isReference: 0);
    if ( v5 != nullptr )
    {
      sprintf(string: &string[4], format: "%g %g %g", this->m_Origin.x, this->m_Origin.y, this->m_Origin.z);
      CMapEntity::NotifyChildKeyChanged(this: v5, pChild: this, szKey: this->m_szKeyName, szValue: &string[4]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CCD0
// Name: protected: virtual void CMapPlayerHullHandle::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::DoTransform(CMapPlayerHullHandle *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  CMapPlayerHullHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013CCF0
// Name: public: virtual void CMapPlayerHullHandle::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::OnAddToWorld(CMapPlayerHullHandle *this, CMapWorld *pWorld)
{
  CMapClass::OnAddToWorld(this, pWorld);
  CMapPlayerHullHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013CD10
// Name: public: virtual void CMapPlayerHullHandle::OnUndoRedo(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMapPlayerHullHandle::OnUndoRedo(CMapPlayerHullHandle *this)
{
  CMapPlayerHullHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013CD20
// Name: public: virtual void CMapPlayerHullHandle::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::PostloadWorld(CMapPlayerHullHandle *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapPlayerHullHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013CD40
// Name: public: virtual class CMapClass __near * CMapPlayerHullHandle::PrepareSelection(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapPlayerHullHandle::PrepareSelection(CMapPlayerHullHandle *this, SelectMode_t eSelectMode)
{
  return this->m_pOwner->PrepareSelection(this: this->m_pOwner, a2: eSelectMode);
}

//------------------------------------------------------------------------------
// Address: 0x1013CD60
// Name: public: CMapPlayerHullHandle::CMapPlayerHullHandle(void)
// Source: json
//------------------------------------------------------------------------------
CMapPlayerHullHandle *__thiscall CMapPlayerHullHandle::CMapPlayerHullHandle(CMapPlayerHullHandle *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapPlayerHullHandle_vtbl *)&CMapHelper::`vftable';
  this->m_szKeyName[0] = 0;
  this->m_bDrawLineToParent = false;
  this->__vftable = (CMapPlayerHullHandle_vtbl *)&CMapPlayerHullHandle::`vftable';
  *(_WORD *)&this->r = -1;
  this->b = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013CE30
// Name: public: virtual void CMapPlayerHullHandle::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPlayerHullHandle::CalcBounds(CMapPlayerHullHandle *this, int bFullUpdate)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm5_4
  Vector Mins; // [esp+8h] [ebp-18h] BYREF
  Vector Maxs; // [esp+14h] [ebp-Ch] BYREF

  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  x = this->m_Origin.x;
  Mins.x = x - 16.0;
  y = this->m_Origin.y;
  Mins.y = y - 16.0;
  z = this->m_Origin.z;
  Mins.z = z - 36.0;
  Maxs.x = x + 16.0;
  Maxs.y = y + 16.0;
  Maxs.z = z + 36.0;
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &Mins, maxs: &Maxs);
  this->m_CullBox.bmins = this->m_Render2DBox.bmins;
  this->m_CullBox.bmaxs = this->m_Render2DBox.bmaxs;
  this->m_BoundingBox.bmins = this->m_CullBox.bmins;
  this->m_BoundingBox.bmaxs = this->m_CullBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1013CF00
// Name: public: virtual class CMapClass __near * CMapPlayerHullHandle::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapPlayerHullHandle::Copy(CMapPlayerHullHandle *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0x100u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapPlayerHullHandle::`vftable';
    LOBYTE(v4[1].m_nObjectID) = 0;
    *(_BYTE *)&v4[1].Kept = 0;
    *(_WORD *)&v4->r = -1;
    v4->b = -1;
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
// Address: 0x1013CFC0
// Name: class CMapClass __near * CMapPlayerHullHandle_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapPlayerHullHandle_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0x100u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapPlayerHullHandle::`vftable';
  LOBYTE(v1[1].m_nObjectID) = 0;
  *(_BYTE *)&v1[1].Kept = 0;
  *(_WORD *)&v1->r = -1;
  v1->b = -1;
  return v1;
}
