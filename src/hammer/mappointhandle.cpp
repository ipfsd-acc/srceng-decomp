// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mappointhandle.cpp
// Functions: 22
// ============================================================

#include "hammer\mappointhandle.h"

//------------------------------------------------------------------------------
// Address: 0x1013D1E0
// Name: public: virtual char const __near * CMapPointHandle::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapPointHandle::GetType(CMapPointHandle *this)
{
  return CMapPointHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013D1F0
// Name: public: virtual int CMapPointHandle::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapPointHandle::IsMapClass(CMapPointHandle *this, const char *Type)
{
  return Type == CMapPointHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013D210
// Name: public: virtual CMapPointHandle::~CMapPointHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::~CMapPointHandle(CMapPointHandle *this)
{
  this->__vftable = (CMapPointHandle_vtbl *)&CMapPointHandle::`vftable';
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D250
// Name: public: virtual char const __near * CMapPointHandle::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapPointHandle::GetDescription(CMapPointHandle *this)
{
  return "Point helper";
}

//------------------------------------------------------------------------------
// Address: 0x1013D260
// Name: public: virtual class CMapClass __near * CMapPointHandle::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapPointHandle *__thiscall CMapPointHandle::CopyFrom(
        CMapPointHandle *this,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  CMapClass *v4; // eax
  char v5; // cl

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  v4 = pObject + 1;
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
// Address: 0x1013D2A0
// Name: public: virtual class CBaseTool __near * CMapPointHandle::GetToolObject(int,bool)
// Source: json
//------------------------------------------------------------------------------
CToolPointHandle *__thiscall CMapPointHandle::GetToolObject(CMapPointHandle *this, int nHitData, bool bAttachObject)
{
  CToolManager *v4; // eax
  CToolPointHandle *result; // eax
  CToolPointHandle *v6; // esi

  v4 = ToolManager();
  result = (CToolPointHandle *)CToolManager::GetToolForID(this: v4, eToolID: TOOL_POINT_HANDLE);
  v6 = result;
  if ( bAttachObject )
  {
    CToolSphere::Attach(this: result, pPoint: this);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D2D0
// Name: public: virtual bool CMapPointHandle::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapPointHandle::HitTest2D(
        CMapPointHandle *this,
        CMapView2D *pView,
        const Vector2D *point,
        HitInfo_s *HitData)
{
  Vector2D vecClient; // [esp+4h] [ebp-8h] BYREF

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  if ( !this->IsSelected(this) )
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
// Address: 0x1013D340
// Name: public: virtual void CMapPointHandle::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapPointHandle::Render2D(CMapPointHandle *this, CRender2D *pRender)
{
  SelectionState_t v3; // eax
  CMapClass *v4; // eax
  wchar_t string[20]; // [esp+20h] [ebp-7Ch] BYREF
  _BYTE szText_64[20]; // [esp+88h] [ebp-14h] OVERLAPPED BYREF

  v3 = this->GetSelectionState(this);
  *(_DWORD *)&szText_64[16] = v3;
  if ( v3 != SELECT_NONE )
  {
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
    CRender::SetHandleStyle(this: pRender, size: 4, type: 2);
    CRender::DrawHandle(this: pRender, vCenter: &this->m_Origin, vOffset: nullptr);
    if ( this->m_pParent != nullptr )
    {
      if ( this->m_bDrawLineToParent )
      {
        if ( *(_DWORD *)&szText_64[16] != 4 )
        {
          CRender::SetDrawColor(
            this: pRender,
            r: Options.colors.clrToolHandle,
            g: BYTE1(Options.colors.clrToolHandle),
            b: BYTE2(Options.colors.clrToolHandle));
          goto LABEL_11;
        }
      }
      else if ( *(_DWORD *)&szText_64[16] != 4 )
      {
        goto LABEL_12;
      }
      CRender::SetDrawColor(
        this: pRender,
        r: Options.colors.clrSelection,
        g: BYTE1(Options.colors.clrSelection),
        b: BYTE2(Options.colors.clrSelection));
LABEL_11:
      v4 = this->GetParent(this);
      v4->GetOrigin(this: v4, a2: (Vector *)szText_64);
      CRender::DrawLine(
        this: pRender,
        a2: (int)this,
        a3: (int)pRender,
        vStart: &this->m_Origin,
        vEnd: (const Vector *)szText_64);
    }
LABEL_12:
    CRender::PopRenderMode(this: pRender);
    if ( *(_DWORD *)&szText_64[16] == 4 )
    {
      CRender::TransformPoint(this: pRender, vClient: (Vector2D *)&szText_64[12], vWorld: &this->m_Origin);
      *(float *)&szText_64[16] = *(float *)&szText_64[16] + 8.0;
      CRender::SetTextColor(
        this: pRender,
        r: Options.colors.clrToolHandle,
        g: BYTE1(Options.colors.clrToolHandle),
        b: BYTE2(Options.colors.clrToolHandle),
        a: 0xFFu);
      sprintf(
        string: (char *)&string[2],
        format: "(%0.f, %0.f, %0.f)",
        this->m_Origin.x,
        this->m_Origin.y,
        this->m_Origin.z);
      CRender::DrawTextA(
        this: pRender,
        text: &string[2],
        x: (int)*(float *)&szText_64[12],
        y: (int)*(float *)&szText_64[16],
        nFlags: 32);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D4E0
// Name: public: virtual void CMapPointHandle::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CMapPointHandle::Render3D(
        CMapPointHandle *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CRender3D *pRender)
{
  CCamera *Camera; // eax
  CMapClass *v7; // eax
  Vector v9; // [esp+0h] [ebp-28h] BYREF
  float v10; // [esp+10h] [ebp-18h] BYREF
  float v11; // [esp+14h] [ebp-14h]
  float v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  int vars0; // [esp+28h] [ebp+0h]

  v13 = a2;
  v14 = vars0;
  if ( ((int (__thiscall *)(CMapPointHandle *, int, int))this->GetSelectionState)(a1: this, a2: a3, a3: a4) != 0 )
  {
    v11 = COERCE_FLOAT(&v10);
    Camera = CRender::GetCamera(this: pRender);
    CCamera::GetViewPoint(this: Camera, ViewPoint: (Vector *)LODWORD(v11));
    CRender3D::RenderSphere(
      this: pRender,
      vCenter: &this->m_Origin,
      flRadius: fsqrt(
        (float)((float)((float)(this->m_Origin.y - v11) * (float)(this->m_Origin.y - v11))
              + (float)((float)(this->m_Origin.z - v12) * (float)(this->m_Origin.z - v12)))
      + (float)((float)(this->m_Origin.x - v10) * (float)(this->m_Origin.x - v10)))
    * 0.04,
      nTheta: 12,
      nPhi: 12,
      chRed: 128,
      chGreen: 0x80u,
      chBlue: 0xFFu);
    if ( this->m_pParent != nullptr && this->m_bDrawLineToParent )
    {
      v7 = this->GetParent(this);
      v7->GetOrigin(this: v7, a2: &v9);
      CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu);
      CRender::DrawLine(this: pRender, a2: (int)pRender, a3: (int)&this->m_Origin, vStart: &this->m_Origin, vEnd: &v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D5F0
// Name: public: virtual void CMapPointHandle::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::OnParentKeyChanged(CMapPointHandle *this, const char *szKey, const char *szValue)
{
  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    sscanf(string: szValue, format: "%f %f %f", &this->m_Origin, &this->m_Origin.y, &this->m_Origin.z);
    this->CalcBounds(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D640
// Name: private: void CMapPointHandle::UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::UpdateParentKey(CMapPointHandle *this)
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
// Address: 0x1013D710
// Name: protected: virtual void CMapPointHandle::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::DoTransform(CMapPointHandle *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  CMapPointHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D730
// Name: public: virtual void CMapPointHandle::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::OnAddToWorld(CMapPointHandle *this, CMapWorld *pWorld)
{
  CMapClass::OnAddToWorld(this, pWorld);
  CMapPointHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D750
// Name: public: virtual void CMapPointHandle::OnUndoRedo(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMapPointHandle::OnUndoRedo(CMapPointHandle *this)
{
  CMapPointHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D760
// Name: public: virtual void CMapPointHandle::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::PostloadWorld(CMapPointHandle *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapPointHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013D780
// Name: public: CMapPointHandle::CMapPointHandle(void)
// Source: json
//------------------------------------------------------------------------------
CMapPointHandle *__thiscall CMapPointHandle::CMapPointHandle(CMapPointHandle *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapPointHandle_vtbl *)&CMapHelper::`vftable';
  this->m_szKeyName[0] = 0;
  this->m_bDrawLineToParent = false;
  this->__vftable = (CMapPointHandle_vtbl *)&CMapPointHandle::`vftable';
  *(_WORD *)&this->r = -1;
  this->b = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013D850
// Name: public: CMapPointHandle::CMapPointHandle(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapPointHandle *__thiscall CMapPointHandle::CMapPointHandle(
        CMapPointHandle *this,
        const char *pszKey,
        bool bDrawLineToParent)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapPointHandle_vtbl *)&CMapHelper::`vftable';
  this->b = -1;
  this->m_szKeyName[0] = 0;
  this->__vftable = (CMapPointHandle_vtbl *)&CMapPointHandle::`vftable';
  this->m_bDrawLineToParent = false;
  *(_WORD *)&this->r = -1;
  strcpy(this->m_szKeyName, pszKey);
  this->m_bDrawLineToParent = bDrawLineToParent;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013D8E0
// Name: public: virtual void CMapPointHandle::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::CalcBounds(CMapPointHandle *this, int bFullUpdate)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  v3 = this->m_Origin.x + 2.0;
  v4 = this->m_Origin.y + 2.0;
  v5 = this->m_Origin.z + 2.0;
  this->m_CullBox.bmins.x = v3;
  this->m_CullBox.bmins.y = v4;
  this->m_CullBox.bmins.z = v5;
  this->m_CullBox.bmaxs.x = v3;
  this->m_CullBox.bmaxs.y = v4;
  this->m_CullBox.bmaxs.z = v5;
  this->m_BoundingBox.bmins = this->m_CullBox.bmins;
  this->m_BoundingBox.bmaxs = this->m_CullBox.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x1013D960
// Name: public: virtual class CMapClass __near * CMapPointHandle::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapPointHandle::Copy(CMapPointHandle *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0xFCu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapPointHandle::`vftable';
    LOBYTE(v4[1].__vftable) = 0;
    LOBYTE(v4[1].m_References.m_pHead) = 0;
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
// Address: 0x1013DA10
// Name: protected: void CMapPointHandle::UpdateOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPointHandle::UpdateOrigin(CMapPointHandle *this, const Vector *vecOrigin)
{
  void (__thiscall *CalcBounds)(CMapClass *, int); // edx

  this->m_Origin.x = vecOrigin->x;
  this->m_Origin.y = vecOrigin->y;
  CalcBounds = this->CalcBounds;
  this->m_Origin.z = vecOrigin->z;
  ((void (__stdcall *)(_DWORD))CalcBounds)(a1: 0);
  CMapPointHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013DA50
// Name: class CMapClass __near * CMapPointHandle_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapPointHandle_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xFCu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapPointHandle::`vftable';
  LOBYTE(v1[1].__vftable) = 0;
  LOBYTE(v1[1].m_References.m_pHead) = 0;
  *(_WORD *)&v1->r = -1;
  v1->b = -1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1013DAF0
// Name: public: static class CMapClass __near * CMapPointHandle::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapPointHandle *__cdecl CMapPointHandle::Create(CHelperInfo *pHelperInfo)
{
  char *v2; // esi
  CMapPointHandle *v3; // eax
  CMapPointHandle *v4; // esi
  bool bDrawLineToParent; // [esp+1Ch] [ebp+8h]

  bDrawLineToParent = _V_stricmp(s1: pHelperInfo->m_szName, s2: "vecline") == 0;
  if ( pHelperInfo->m_Parameters.m_Size <= 0 || (v2 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) == nullptr )
    v2 = pszDefaultKeyName_0;
  v3 = (CMapPointHandle *)operator new(nSize: 0xFCu);
  if ( v3 != nullptr )
    v4 = CMapPointHandle::CMapPointHandle(this: v3, pszKey: v2, bDrawLineToParent);
  else
    v4 = nullptr;
  v4->SetRenderColor_2(this: v4, a2: 255u, a3: 255u, a4: 255u);
  return v4;
}
