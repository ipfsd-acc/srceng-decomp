// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapsweptplayerhull.cpp
// Functions: 23
// ============================================================

#include "hammer\mapsweptplayerhull.h"

//------------------------------------------------------------------------------
// Address: 0x10147F20
// Name: public: virtual char const __near * CMapSweptPlayerHull::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSweptPlayerHull::GetType(CMapSweptPlayerHull *this)
{
  return CMapSweptPlayerHull::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10147F30
// Name: public: virtual int CMapSweptPlayerHull::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapSweptPlayerHull::IsMapClass(CMapSweptPlayerHull *this, const char *Type)
{
  return Type == CMapSweptPlayerHull::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10147F50
// Name: protected: void CMapSweptPlayerHull::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::Initialize(CMapSweptPlayerHull *this)
{
  CMapPlayerHullHandle *v2; // eax
  CMapPlayerHullHandle *v3; // eax
  CMapPlayerHullHandle *v4; // eax
  CMapPlayerHullHandle *v5; // eax

  *(_WORD *)&this->r = -1;
  this->b = -1;
  v2 = (CMapPlayerHullHandle *)operator new(nSize: 0x100u);
  if ( v2 != nullptr )
    v3 = CMapPlayerHullHandle::CMapPlayerHullHandle(this: v2);
  else
    v3 = nullptr;
  this->m_Point[0] = v3;
  CMapPlayerHullHandle::Attach(this: v3, pOwner: this);
  v4 = (CMapPlayerHullHandle *)operator new(nSize: 0x100u);
  if ( v4 != nullptr )
    v5 = CMapPlayerHullHandle::CMapPlayerHullHandle(this: v4);
  else
    v5 = nullptr;
  this->m_Point[1] = v5;
  CMapPlayerHullHandle::Attach(this: v5, pOwner: this);
}

//------------------------------------------------------------------------------
// Address: 0x10148000
// Name: public: virtual char const __near * CMapSweptPlayerHull::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapSweptPlayerHull::GetDescription(CMapSweptPlayerHull *this)
{
  return "Swept player hull helper";
}

//------------------------------------------------------------------------------
// Address: 0x10148010
// Name: public: virtual class CMapClass __near * CMapSweptPlayerHull::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapSweptPlayerHull *__thiscall CMapSweptPlayerHull::CopyFrom(
        CMapSweptPlayerHull *this,
        CMapClass *pObject,
        BOOL bUpdateDependencies)
{
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  this->m_Point[0]->CopyFrom(this: this->m_Point[0], a2: (CMapClass *)pObject[1].__vftable, a3: bUpdateDependencies);
  this->m_Point[1]->CopyFrom(this: this->m_Point[1], a2: (CMapClass *)pObject[1].m_nObjectID, a3: bUpdateDependencies);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10148060
// Name: public: virtual class CBaseTool __near * CMapSweptPlayerHull::GetToolObject(int,bool)
// Source: json
//------------------------------------------------------------------------------
CToolAxisHandle *__thiscall CMapSweptPlayerHull::GetToolObject(
        CMapSweptPlayerHull *this,
        int nHitData,
        bool bAttachObject)
{
  CToolManager *v4; // eax
  CToolAxisHandle *result; // eax
  CToolAxisHandle *v6; // esi

  v4 = ToolManager();
  result = (CToolAxisHandle *)CToolManager::GetToolForID(this: v4, eToolID: TOOL_SWEPT_HULL);
  v6 = result;
  if ( bAttachObject )
  {
    CToolAxisHandle::Attach(this: result, pAxis: (CMapAxisHandle *)this, nPointIndex: nHitData);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101480A0
// Name: public: virtual bool CMapSweptPlayerHull::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSweptPlayerHull::HitTest2D(
        CMapSweptPlayerHull *this,
        CMapView2D *pView,
        const Vector2D *point,
        HitInfo_s *HitData)
{
  unsigned int v4; // esi
  CMapPlayerHullHandle **i; // edi

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  v4 = 0;
  for ( i = this->m_Point; !(*i)->HitTest2D(this: *i, a2: pView, a3: point, a4: HitData); ++i )
  {
    if ( ++v4 >= 2 )
      return 0;
  }
  HitData->uData = v4;
  HitData->pObject = this;
  HitData->nDepth = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10148110
// Name: public: virtual void CMapSweptPlayerHull::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::Render2D(CMapSweptPlayerHull *this, CRender2D *pRender)
{
  SelectionState_t v3; // eax
  CMapView *m_pView; // ebx
  bool *p_m_bActive; // ebx
  CMapPlayerHullHandle *v6; // eax
  float z; // xmm0_4
  CMapPlayerHullHandle *v8; // eax
  int v9; // esi
  int v10; // edi
  float v11; // xmm2_4
  double v12; // st7
  Vector vecOrigin2; // [esp+Ch] [ebp-90h] BYREF
  Vector vecOrigin1; // [esp+18h] [ebp-84h] BYREF
  SelectionState_t eState; // [esp+24h] [ebp-78h]
  float v16; // [esp+28h] [ebp-74h]
  Vector dir; // [esp+2Ch] [ebp-70h] BYREF
  float dy; // [esp+38h] [ebp-64h]
  Vector maxs1; // [esp+3Ch] [ebp-60h]
  Vector mins2; // [esp+48h] [ebp-54h]
  Vector mins1; // [esp+54h] [ebp-48h]
  Vector maxs2; // [esp+60h] [ebp-3Ch]
  Vector line1[2]; // [esp+6Ch] [ebp-30h] BYREF
  Vector line2[2]; // [esp+84h] [ebp-18h] BYREF

  v3 = this->GetSelectionState(this);
  m_pView = pRender->m_pView;
  eState = v3;
  if ( m_pView != nullptr )
    p_m_bActive = &m_pView[-4].m_bActive;
  else
    p_m_bActive = nullptr;
  this->m_Point[0]->Render2D(this: this->m_Point[0], a2: pRender);
  this->m_Point[1]->Render2D(this: this->m_Point[1], a2: pRender);
  this->m_Point[0]->GetOrigin(this: this->m_Point[0], a2: &vecOrigin1);
  this->m_Point[1]->GetOrigin(this: this->m_Point[1], a2: &vecOrigin2);
  v6 = this->m_Point[0];
  mins1 = v6->m_CullBox.bmins;
  maxs1.x = v6->m_CullBox.bmaxs.x;
  maxs1.y = v6->m_CullBox.bmaxs.y;
  z = v6->m_CullBox.bmaxs.z;
  v8 = this->m_Point[1];
  maxs1.z = z;
  mins2 = v8->m_CullBox.bmins;
  maxs2 = v8->m_CullBox.bmaxs;
  dir.x = vecOrigin2.x - vecOrigin1.x;
  dir.y = vecOrigin2.y - vecOrigin1.y;
  dir.z = vecOrigin2.z - vecOrigin1.z;
  v9 = *((_DWORD *)p_m_bActive + 46);
  v10 = *((_DWORD *)p_m_bActive + 47);
  *((_DWORD *)&dir.x + *((_DWORD *)p_m_bActive + 48)) = 0;
  VectorNormalize(vec: &dir);
  v11 = *(&dir.x + v10);
  v16 = *(&dir.x + v9);
  dy = v11;
  if ( v16 != 0.0 || v11 != 0.0 )
  {
    if ( eState == SELECT_MODIFY )
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
    memset(line1, 0, sizeof(line1));
    memset(line2, 0, sizeof(line2));
    if ( v16 <= 0.0 )
    {
      if ( dy > 0.0 )
        goto LABEL_11;
    }
    else if ( dy <= 0.0 )
    {
LABEL_11:
      *(&line1[0].x + v9) = *(&maxs1.x + v9);
      *(&line1[0].x + v10) = *(&maxs1.x + v10);
      *(&line1[1].x + v9) = *(&maxs2.x + v9);
      *(&line1[1].x + v10) = *(&maxs2.x + v10);
      *(&line2[0].x + v9) = *(&mins1.x + v9);
      *(&line2[0].x + v10) = *(&mins1.x + v10);
      v12 = *(&mins2.x + v9);
LABEL_14:
      *(&line2[1].x + v9) = v12;
      *(&line2[1].x + v10) = *(&mins2.x + v10);
      CRender::DrawLine(this: pRender, a2: v10, a3: v9, vStart: line1, vEnd: &line1[1]);
      CRender::DrawLine(this: pRender, a2: v10, a3: v9, vStart: line2, vEnd: &line2[1]);
      CRender::PopRenderMode(this: pRender);
      return;
    }
    *(&line1[0].x + v9) = *(&mins1.x + v9);
    *(&line1[0].x + v10) = *(&maxs1.x + v10);
    *(&line1[1].x + v9) = *(&mins2.x + v9);
    *(&line1[1].x + v10) = *(&maxs2.x + v10);
    *(&line2[0].x + v9) = *(&maxs1.x + v9);
    *(&line2[0].x + v10) = *(&mins1.x + v10);
    v12 = *(&maxs2.x + v9);
    goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101483E0
// Name: public: virtual void CMapSweptPlayerHull::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::Render3D(CMapSweptPlayerHull *this, CRender3D *pRender)
{
  CMapPlayerHullHandle **m_Point; // esi
  int i; // ebx
  int v4; // esi
  Vector vec1; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vec2; // [esp+18h] [ebp-10h] BYREF
  CMapSweptPlayerHull *v7; // [esp+24h] [ebp-4h]

  v7 = this;
  m_Point = this->m_Point;
  for ( i = 2; i != 0; --i )
  {
    (*m_Point)->Render3D(this: *m_Point, a2: pRender);
    ++m_Point;
  }
  v4 = (int)v7;
  if ( v7->GetSelectionState(this: v7) != SELECT_NONE )
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
  else
    CRender::SetDrawColor(this: pRender, r: 0xC8u, g: 0xB4u, b: 0);
  v7->m_Point[0]->GetOrigin(this: v7->m_Point[0], a2: &vec1);
  (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)(v4 + 220) + 80))(a1: *(_DWORD *)(v4 + 220), a2: &vec2);
  CRender::DrawLine(this: pRender, a2: (int)pRender, a3: v4, vStart: &vec1, vEnd: &vec2);
}

//------------------------------------------------------------------------------
// Address: 0x10148480
// Name: public: virtual void CMapSweptPlayerHull::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::SetOrigin(CMapSweptPlayerHull *this, Vector *vecOrigin)
{
  CMapClass::SetOrigin(this, origin: vecOrigin);
  this->m_Point[0]->SetOrigin(this: this->m_Point[0], a2: vecOrigin);
  this->m_Point[1]->SetOrigin(this: this->m_Point[1], a2: vecOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x101484C0
// Name: public: virtual enum SelectionState_t CMapSweptPlayerHull::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapSweptPlayerHull::SetSelectionState(
        CMapSweptPlayerHull *this,
        SelectionState_t eSelectionState)
{
  SelectionState_t v3; // ebx

  v3 = CMapClass::SetSelectionState(this, eSelectionState);
  this->m_Point[0]->SetSelectionState(this: this->m_Point[0], a2: eSelectionState);
  this->m_Point[1]->SetSelectionState(this: this->m_Point[1], a2: eSelectionState);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10148500
// Name: protected: enum SelectionState_t CMapSweptPlayerHull::SetSelectionState(enum SelectionState_t,int)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapSweptPlayerHull::SetSelectionState(
        CMapSweptPlayerHull *this,
        SelectionState_t eSelectionState,
        int nHandle)
{
  SelectionState_t v4; // ebx

  v4 = CMapClass::SetSelectionState(this, eSelectionState);
  this->m_Point[nHandle]->SetSelectionState(this: this->m_Point[nHandle], a2: eSelectionState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10148530
// Name: public: virtual void CMapSweptPlayerHull::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::OnParentKeyChanged(
        CMapSweptPlayerHull *this,
        const char *szKey,
        const char *szValue)
{
  CMapPlayerHullHandle *v4; // ecx
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  Vector vecOrigin; // [esp+8h] [ebp-Ch] BYREF

  if ( _V_stricmp(s1: szKey, s2: "point0") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "point1") != 0 )
      return;
    sscanf(string: szValue, format: "%f %f %f, %f %f %f", &vecOrigin, &vecOrigin.y, &vecOrigin.z, v5, v6);
    v4 = this->m_Point[1];
  }
  else
  {
    sscanf(string: szValue, format: "%f %f %f, %f %f %f", &vecOrigin, &vecOrigin.y, &vecOrigin.z, v5, v6);
    v4 = this->m_Point[0];
  }
  vecOrigin.x = playerFixup.x + vecOrigin.x;
  vecOrigin.y = playerFixup.y + vecOrigin.y;
  vecOrigin.z = playerFixup.z + vecOrigin.z;
  v4->SetOrigin(this: v4, a2: &vecOrigin);
  this->PostUpdate(this, a2: Notify_Changed);
}

//------------------------------------------------------------------------------
// Address: 0x10148600
// Name: protected: void CMapSweptPlayerHull::UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapSweptPlayerHull::UpdateParentKey(CMapSweptPlayerHull *this)
{
  CMapEntity *v2; // edi
  void (__thiscall *PostUpdate)(CMapAtom *, Notify_Dependent_t); // eax
  char string[36]; // [esp+20h] [ebp-218h] BYREF
  _BYTE szValue_476[24]; // [esp+220h] [ebp-18h] OVERLAPPED BYREF

  v2 = (CMapEntity *)__RTDynamicCast(
                       inptr: this->m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v2 != nullptr )
  {
    this->m_Point[0]->GetOrigin(this: this->m_Point[0], a2: (Vector *)szValue_476);
    this->m_Point[1]->GetOrigin(this: this->m_Point[1], a2: (Vector *)&szValue_476[12]);
    PostUpdate = this->PostUpdate;
    *(float *)&szValue_476[8] = *(float *)&szValue_476[8] - playerFixup.z;
    *(float *)&szValue_476[16] = *(float *)&szValue_476[16] - playerFixup.y;
    *(float *)szValue_476 = *(float *)szValue_476 - playerFixup.x;
    *(float *)&szValue_476[4] = *(float *)&szValue_476[4] - playerFixup.y;
    *(float *)&szValue_476[12] = *(float *)&szValue_476[12] - playerFixup.x;
    *(float *)&szValue_476[20] = *(float *)&szValue_476[20] - playerFixup.z;
    PostUpdate(this, a2: Notify_Changed);
    sprintf(string, format: "%g %g %g", *(float *)szValue_476, *(float *)&szValue_476[4], *(float *)&szValue_476[8]);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "point0", szValue: string);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "origin", szValue: string);
    sprintf(
      string,
      format: "%g %g %g",
      *(float *)&szValue_476[12],
      *(float *)&szValue_476[16],
      *(float *)&szValue_476[20]);
    CMapEntity::NotifyChildKeyChanged(this: v2, pChild: this, szKey: "point1", szValue: string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148790
// Name: public: virtual void CMapSweptPlayerHull::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::OnAddToWorld(CMapSweptPlayerHull *this, CMapWorld *pWorld)
{
  CMapClass::OnAddToWorld(this, pWorld);
  CMapSweptPlayerHull::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x101487B0
// Name: public: virtual void CMapSweptPlayerHull::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::PostloadWorld(CMapSweptPlayerHull *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapSweptPlayerHull::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x101487D0
// Name: public: void CMapSweptPlayerHull::GetEndPoint(class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::GetEndPoint(CMapSweptPlayerHull *this, Vector *vecPos, int nPointIndex)
{
  this->m_Point[nPointIndex]->GetOrigin(this: this->m_Point[nPointIndex], a2: vecPos);
}

//------------------------------------------------------------------------------
// Address: 0x10148850
// Name: public: virtual void CMapSweptPlayerHull::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::CalcBounds(CMapSweptPlayerHull *this, int bFullUpdate)
{
  CMapClass **m_Point; // edi
  float *v4; // eax
  Vector vecMins; // [esp+Ch] [ebp-20h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-14h] BYREF
  BoundBox *p_m_Render2DBox; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  CMapClass::CalcBounds(this, bFullUpdate);
  p_m_Render2DBox = &this->m_Render2DBox;
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  m_Point = this->m_Point;
  for ( i = 2; i != 0; --i )
  {
    (*m_Point)->CalcBounds(this: *m_Point, a2: bFullUpdate);
    CMapClass::GetCullBox(this: *m_Point, mins: &vecMins, maxs: &vecMaxs);
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecMins, maxs: &vecMaxs);
    ++m_Point;
  }
  v4 = (float *)p_m_Render2DBox;
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  v4[1] = this->m_CullBox.bmins.x;
  v4[2] = this->m_CullBox.bmins.y;
  v4[3] = this->m_CullBox.bmins.z;
  v4[4] = this->m_CullBox.bmaxs.x;
  v4[5] = this->m_CullBox.bmaxs.y;
  v4[6] = this->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x10148910
// Name: public: virtual class CMapClass __near * CMapSweptPlayerHull::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSweptPlayerHull *__thiscall CMapSweptPlayerHull::Copy(CMapSweptPlayerHull *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapSweptPlayerHull *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0xE0u);
  v4 = (CMapSweptPlayerHull *)v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapSweptPlayerHull::`vftable';
    CMapSweptPlayerHull::Initialize(this: v4);
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
// Address: 0x101489B0
// Name: public: void CMapSweptPlayerHull::UpdateEndPoint(class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::UpdateEndPoint(CMapSweptPlayerHull *this, Vector *vecPos, int nPointIndex)
{
  this->m_Point[nPointIndex]->SetOrigin(this: this->m_Point[nPointIndex], a2: vecPos);
  this->PostUpdate(this, a2: Notify_Changed);
  CMapSweptPlayerHull::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x101489F0
// Name: protected: virtual void CMapSweptPlayerHull::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSweptPlayerHull::DoTransform(CMapSweptPlayerHull *this, const VMatrix *matrix)
{
  CMapPlayerHullHandle *v3; // edi
  CMapPlayerHullHandle *v4; // edi

  CMapClass::DoTransform(this, matrix);
  v3 = this->m_Point[0];
  v3->DoTransform(this: v3, a2: matrix);
  v3->PostUpdate(this: v3, a2: Notify_Transform);
  v4 = this->m_Point[1];
  v4->DoTransform(this: v4, a2: matrix);
  v4->PostUpdate(this: v4, a2: Notify_Transform);
  CMapSweptPlayerHull::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x10148A50
// Name: class CMapClass __near * CMapSweptPlayerHull_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSweptPlayerHull *__cdecl CMapSweptPlayerHull_CreateObject()
{
  CMapClass *v0; // eax
  CMapSweptPlayerHull *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xE0u);
  v1 = (CMapSweptPlayerHull *)v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapSweptPlayerHull::`vftable';
  CMapSweptPlayerHull::Initialize(this: v1);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10148AE0
// Name: public: static class CMapClass __near * CMapSweptPlayerHull::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSweptPlayerHull *__cdecl CMapSweptPlayerHull::Create()
{
  CMapClass *v0; // eax
  CMapSweptPlayerHull *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xE0u);
  v1 = (CMapSweptPlayerHull *)v0;
  if ( v0 != nullptr )
  {
    CMapClass::CMapClass(this: v0);
    v1->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapHelper::`vftable';
    v1->__vftable = (CMapSweptPlayerHull_vtbl *)&CMapSweptPlayerHull::`vftable';
    CMapSweptPlayerHull::Initialize(this: v1);
  }
  else
  {
    v1 = nullptr;
  }
  v1->SetRenderColor_2(this: v1, a2: 255u, a3: 255u, a4: 255u);
  return v1;
}
