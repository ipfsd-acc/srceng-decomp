// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolpickangles.cpp
// Functions: 4
// ============================================================

#include "hammer\toolpickangles.h"

//------------------------------------------------------------------------------
// Address: 0x101650E0
// Name: public: CToolPickAngles::CToolPickAngles(void)
// Source: json
//------------------------------------------------------------------------------
CToolPickAngles *__thiscall CToolPickAngles::CToolPickAngles(CToolPickAngles *this)
{
  this->__vftable = (CToolPickAngles_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolPickAngles_vtbl *)&CToolPickAngles::`vftable';
  this->m_pNotifyTarget = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10165130
// Name: public: virtual enum ToolID_t CToolPickAngles::GetToolID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolPickAngles::GetToolID(CToolPickAngles *this)
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x101651A0
// Name: public: virtual bool CToolPickAngles::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickAngles::OnMouseMove3D(
        CToolPickAngles *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  CursorA = dword_107B37D0;
  if ( dword_107B37D0 == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0x144);
    dword_107B37D0 = CursorA;
  }
  SetCursor(hCursor: CursorA);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101651D0
// Name: public: virtual bool CToolPickAngles::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickAngles::OnLMouseDown3D(
        CToolPickAngles *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  const Vector2D *v4; // ebx
  CMapClass *v6; // eax
  CMapClass *v7; // esi
  CMapClass *v8; // eax
  char *v9; // eax
  CMapSolid *v11; // esi
  CMapFace *Face; // eax
  Vector HitNormal; // [esp+Ch] [ebp-30h] BYREF
  Vector HitPos; // [esp+18h] [ebp-24h] BYREF
  Vector Start; // [esp+24h] [ebp-18h] BYREF
  Vector End; // [esp+30h] [ebp-Ch] BYREF

  v4 = vPoint;
  v6 = CMapView3D::NearestObjectAt(
         this: pView,
         vPoint,
         ulFace: (unsigned int *)&vPoint,
         nFlags: 0,
         pLocalMatrix: nullptr);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = v6->PrepareSelection(this: v6, a2: selectObjects);
    v9 = (char *)__RTDynamicCast(
                   inptr: v8,
                   VfDelta: 0,
                   SrcType: &CMapClass `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    if ( v9 != nullptr )
    {
      if ( this->m_pNotifyTarget != nullptr )
      {
        BoundBox::GetBoundsCenter(this: (BoundBox *)(v9 + 96), ptdest: &End);
        this->m_pNotifyTarget->OnNotifyPickAngles(this: this->m_pNotifyTarget, a2: &End);
        return 1;
      }
    }
    else
    {
      v11 = (CMapSolid *)__RTDynamicCast(
                           inptr: v7,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapSolid `RTTI Type Descriptor',
                           isReference: 0);
      if ( v11 != nullptr )
      {
        CCamera::BuildRay(this: pView->m_pCamera, vView: v4, vStart: &Start, vEnd: &End);
        Face = CMapSolid::GetFace(this: v11, nFace: (int)vPoint);
        if ( CMapFace::TraceLine(this: Face, &HitPos, &HitNormal, &Start, &End) != 0 && this->m_pNotifyTarget != nullptr )
          this->m_pNotifyTarget->OnNotifyPickAngles(this: this->m_pNotifyTarget, a2: &HitPos);
      }
    }
  }
  return 1;
}
