// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapaxishandle.cpp
// Functions: 24
// ============================================================

#include "hammer\mapaxishandle.h"

//------------------------------------------------------------------------------
// Address: 0x1010D4B0
// Name: public: void CMapAtom::Transform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::Transform(CMapAtom *this, const VMatrix *matrix)
{
  this->DoTransform(this, a2: matrix);
  this->PostUpdate(this, a2: Notify_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x1010D4E0
// Name: public: virtual char const __near * CMapAxisHandle::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapAxisHandle::GetType(CMapAxisHandle *this)
{
  return CMapAxisHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010D4F0
// Name: public: virtual int CMapAxisHandle::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapAxisHandle::IsMapClass(CMapAxisHandle *this, const char *Type)
{
  return Type == CMapAxisHandle::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010D510
// Name: public: virtual char const __near * CMapAxisHandle::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapAxisHandle::GetDescription(CMapAxisHandle *this)
{
  return "Axis helper";
}

//------------------------------------------------------------------------------
// Address: 0x1010D520
// Name: public: virtual class CMapClass __near * CMapAxisHandle::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__thiscall CMapAxisHandle::CopyFrom(CMapAxisHandle *this, CMapClass *pObject, BOOL bUpdateDependencies)
{
  Vector *p_bmins; // eax
  char x_low; // cl

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObject, bUpdateDependencies);
  this->m_Point[0].CopyFrom(this: this->m_Point, a2: &pObject[1], a3: bUpdateDependencies);
  this->m_Point[1].CopyFrom(this: &this->m_Point[1], a2: (CMapClass *)&pObject[2].___u2, a3: bUpdateDependencies);
  p_bmins = &pObject[3].m_BoundingBox.bmins;
  do
  {
    x_low = LOBYTE(p_bmins->x);
    *((_BYTE *)&p_bmins->x + (char *)this - (char *)pObject) = LOBYTE(p_bmins->x);
    p_bmins = (Vector *)((char *)p_bmins + 1);
  }
  while ( x_low != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010D5A0
// Name: public: virtual class CBaseTool __near * CMapAxisHandle::GetToolObject(int,bool)
// Source: json
//------------------------------------------------------------------------------
CToolAxisHandle *__thiscall CMapAxisHandle::GetToolObject(CMapAxisHandle *this, int nHitData, bool bAttachObject)
{
  CToolManager *v4; // eax
  CToolAxisHandle *result; // eax
  CToolAxisHandle *v6; // esi

  v4 = ToolManager();
  result = (CToolAxisHandle *)CToolManager::GetToolForID(this: v4, eToolID: TOOL_AXIS_HANDLE);
  v6 = result;
  if ( bAttachObject )
  {
    CToolAxisHandle::Attach(this: result, pAxis: this, nPointIndex: nHitData);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D5E0
// Name: public: virtual bool CMapAxisHandle::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapAxisHandle::HitTest2D(
        CMapAxisHandle *this,
        CMapView2D *pView,
        const Vector2D *point,
        HitInfo_s *HitData)
{
  unsigned int v4; // edi
  CMapPointHandle *i; // esi

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  v4 = 0;
  for ( i = this->m_Point; !i->HitTest2D(this: i, a2: pView, a3: point, a4: HitData); ++i )
  {
    if ( (int)++v4 >= 2 )
      return 0;
  }
  HitData->uData = v4;
  HitData->pObject = this;
  HitData->nDepth = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010D650
// Name: public: virtual void CMapAxisHandle::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapAxisHandle::Render2D(CMapAxisHandle *this@<ecx>, int a2@<edi>, int a3@<esi>, CRender2D *pRender)
{
  Vector vecOrigin1; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecOrigin2; // [esp+10h] [ebp-10h] BYREF
  SelectionState_t eState; // [esp+1Ch] [ebp-4h]

  eState = this->GetSelectionState(this);
  if ( eState != SELECT_NONE )
  {
    ((void (__thiscall *)(CMapPointHandle *, CRender2D *, int, int))this->m_Point[0].Render2D)(
      a1: this->m_Point,
      a2: pRender,
      a3: a2,
      a4: a3);
    this->m_Point[1].Render2D(this: &this->m_Point[1], a2: pRender);
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
    this->m_Point[0].GetOrigin(this: this->m_Point, a2: &vecOrigin1);
    this->m_Point[1].GetOrigin(this: &this->m_Point[1], a2: &vecOrigin2);
    CRender::DrawLine(this: pRender, a2, a3: (int)pRender, vStart: &vecOrigin1, vEnd: &vecOrigin2);
    CRender::PopRenderMode(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D720
// Name: public: virtual void CMapAxisHandle::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::Render3D(CMapAxisHandle *this, CRender3D *pRender)
{
  SelectionState_t (__thiscall *GetSelectionState)(CMapAtom *); // edx
  CMapPointHandle *m_Point; // esi
  int i; // ebx
  Vector vec1; // [esp+4h] [ebp-1Ch] BYREF
  Vector vec2; // [esp+10h] [ebp-10h] BYREF
  CMapAxisHandle *v8; // [esp+1Ch] [ebp-4h]

  GetSelectionState = this->GetSelectionState;
  v8 = this;
  if ( ((int (__fastcall *)(CMapAxisHandle *))GetSelectionState)(a1: this) != 0 )
  {
    m_Point = this->m_Point;
    for ( i = 2; i != 0; --i )
    {
      m_Point->Render3D(this: m_Point, a2: pRender);
      ++m_Point;
    }
    v8->m_Point[0].GetOrigin(this: &v8->m_Point[0], a2: &vec1);
    v8->m_Point[1].GetOrigin(this: &v8->m_Point[1], a2: &vec2);
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu);
    CRender::DrawLine(this: pRender, a2: (int)pRender, a3: (int)m_Point, vStart: &vec1, vEnd: &vec2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D7C0
// Name: public: virtual void CMapAxisHandle::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::SetOrigin(CMapAxisHandle *this, Vector *vecOrigin)
{
  CMapClass::SetOrigin(this, origin: vecOrigin);
  this->m_Point[0].SetOrigin(this: this->m_Point, a2: vecOrigin);
  this->m_Point[1].SetOrigin(this: &this->m_Point[1], a2: vecOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x1010D800
// Name: public: virtual enum SelectionState_t CMapAxisHandle::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapAxisHandle::SetSelectionState(CMapAxisHandle *this, SelectionState_t eSelectionState)
{
  SelectionState_t v3; // ebx

  v3 = CMapClass::SetSelectionState(this, eSelectionState);
  this->m_Point[0].SetSelectionState(this: this->m_Point, a2: eSelectionState);
  this->m_Point[1].SetSelectionState(this: &this->m_Point[1], a2: eSelectionState);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1010D840
// Name: protected: enum SelectionState_t CMapAxisHandle::SetSelectionState(enum SelectionState_t,int)
// Source: json
//------------------------------------------------------------------------------
SelectionState_t __thiscall CMapAxisHandle::SetSelectionState(
        CMapAxisHandle *this,
        SelectionState_t eSelectionState,
        int nHandle)
{
  SelectionState_t v4; // ebx

  v4 = CMapClass::SetSelectionState(this, eSelectionState);
  this->m_Point[nHandle].SetSelectionState(this: &this->m_Point[nHandle], a2: eSelectionState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1010D890
// Name: public: virtual void CMapAxisHandle::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::OnParentKeyChanged(CMapAxisHandle *this, const char *szKey, const char *szValue)
{
  Vector vecOrigin2; // [esp+4h] [ebp-18h] BYREF
  Vector vecOrigin1; // [esp+10h] [ebp-Ch] BYREF

  if ( _V_stricmp(s1: szKey, s2: this->m_szKeyName) == 0 )
  {
    sscanf(
      string: szValue,
      format: "%f %f %f, %f %f %f",
      &vecOrigin1,
      &vecOrigin1.y,
      &vecOrigin1.z,
      &vecOrigin2,
      &vecOrigin2.y,
      &vecOrigin2.z);
    this->m_Point[0].SetOrigin(this: this->m_Point, a2: &vecOrigin1);
    this->m_Point[1].SetOrigin(this: &this->m_Point[1], a2: &vecOrigin2);
    this->CalcBounds(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D920
// Name: protected: void CMapAxisHandle::UpdateParentKey(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapAxisHandle::UpdateParentKey(CMapAxisHandle *this)
{
  char *m_szKeyName; // ebx
  CMapEntity *v3; // edi
  char string[64]; // [esp+3Ch] [ebp-218h] BYREF
  _BYTE szValue_448[24]; // [esp+23Ch] [ebp-18h] OVERLAPPED BYREF

  m_szKeyName = this->m_szKeyName;
  if ( this->m_szKeyName[0] != 0 )
  {
    v3 = (CMapEntity *)__RTDynamicCast(
                         inptr: this->m_pParent,
                         VfDelta: 0,
                         SrcType: &CMapAtom `RTTI Type Descriptor',
                         TargetType: &CMapEntity `RTTI Type Descriptor',
                         isReference: 0);
    if ( v3 != nullptr )
    {
      this->m_Point[0].GetOrigin(this: this->m_Point, a2: (Vector *)&szValue_448[12]);
      this->m_Point[1].GetOrigin(this: &this->m_Point[1], a2: (Vector *)szValue_448);
      this->CalcBounds(this, a2: 0);
      sprintf(
        string,
        format: "%g %g %g, %g %g %g",
        *(float *)&szValue_448[12],
        *(float *)&szValue_448[16],
        *(float *)&szValue_448[20],
        *(float *)szValue_448,
        *(float *)&szValue_448[4],
        *(float *)&szValue_448[8]);
      CMapEntity::NotifyChildKeyChanged(this: v3, pChild: this, szKey: m_szKeyName, szValue: string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010DA20
// Name: public: virtual void CMapAxisHandle::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::OnAddToWorld(CMapAxisHandle *this, CMapWorld *pWorld)
{
  CMapClass::OnAddToWorld(this, pWorld);
  CMapAxisHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010DA40
// Name: public: virtual void CMapAxisHandle::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::PostloadWorld(CMapAxisHandle *this, CMapWorld *pWorld)
{
  CMapClass::PostloadWorld(this, pWorld);
  CMapAxisHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010DA60
// Name: public: CMapAxisHandle::CMapAxisHandle(void)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__thiscall CMapAxisHandle::CMapAxisHandle(CMapAxisHandle *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapAxisHandle_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapAxisHandle_vtbl *)&CMapAxisHandle::`vftable';
  `eh vector constructor iterator'(
    ptr: this->m_Point,
    size: 0xFCu,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CMapPointHandle::CMapPointHandle,
    pDtor: (void (__thiscall *)(void *))CMapPointHandle::~CMapPointHandle);
  this->m_szKeyName[0] = 0;
  *(_WORD *)&this->r = -1;
  this->b = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010DB70
// Name: public: CMapAxisHandle::CMapAxisHandle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__thiscall CMapAxisHandle::CMapAxisHandle(CMapAxisHandle *this, const char *pszKey)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapAxisHandle_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapAxisHandle_vtbl *)&CMapAxisHandle::`vftable';
  `eh vector constructor iterator'(
    ptr: this->m_Point,
    size: 0xFCu,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CMapPointHandle::CMapPointHandle,
    pDtor: (void (__thiscall *)(void *))CMapPointHandle::~CMapPointHandle);
  this->b = -1;
  this->m_szKeyName[0] = 0;
  *(_WORD *)&this->r = -1;
  strcpy(this->m_szKeyName, pszKey);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010DC10
// Name: public: virtual void CMapAxisHandle::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::CalcBounds(CMapAxisHandle *this, int bFullUpdate)
{
  CMapPointHandle *m_Point; // esi
  Vector vecMins; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-4h]

  CMapClass::CalcBounds(this, bFullUpdate);
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  m_Point = this->m_Point;
  for ( i = 2; i != 0; --i )
  {
    m_Point->CalcBounds(this: m_Point, a2: bFullUpdate);
    CMapClass::GetCullBox(this: m_Point, mins: &vecMins, maxs: &vecMaxs);
    BoundBox::UpdateBounds(this: &this->m_CullBox, mins: &vecMins, maxs: &vecMaxs);
    ++m_Point;
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x1010DCB0
// Name: public: virtual class CMapClass __near * CMapAxisHandle::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__thiscall CMapAxisHandle::Copy(CMapAxisHandle *this, BOOL bUpdateDependencies)
{
  CMapAxisHandle *v3; // eax
  CMapAxisHandle *v4; // esi

  v3 = (CMapAxisHandle *)operator new(nSize: 0x2F0u);
  if ( v3 != nullptr )
    v4 = CMapAxisHandle::CMapAxisHandle(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1010DD30
// Name: public: void CMapAxisHandle::UpdateEndPoint(class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::UpdateEndPoint(CMapAxisHandle *this, Vector *vecPos, int nPointIndex)
{
  CMapAxisHandle_vtbl *v4; // edx

  v4 = this->__vftable;
  this->m_Point[nPointIndex].m_Origin = *vecPos;
  v4->CalcBounds(this, a2: 0);
  CMapAxisHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010DD80
// Name: protected: virtual void CMapAxisHandle::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAxisHandle::DoTransform(CMapAxisHandle *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  this->m_Point[0].DoTransform(this: this->m_Point, a2: matrix);
  this->m_Point[0].PostUpdate(this: this->m_Point, a2: Notify_Transform);
  this->m_Point[1].DoTransform(this: &this->m_Point[1], a2: matrix);
  this->m_Point[1].PostUpdate(this: &this->m_Point[1], a2: Notify_Transform);
  CMapAxisHandle::UpdateParentKey(this);
}

//------------------------------------------------------------------------------
// Address: 0x1010DDF0
// Name: class CMapClass __near * CMapAxisHandle_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__cdecl CMapAxisHandle_CreateObject()
{
  CMapAxisHandle *v0; // eax

  v0 = (CMapAxisHandle *)operator new(nSize: 0x2F0u);
  if ( v0 != nullptr )
    return CMapAxisHandle::CMapAxisHandle(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010DE50
// Name: public: static class CMapClass __near * CMapAxisHandle::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapAxisHandle *__cdecl CMapAxisHandle::Create(CHelperInfo *pHelperInfo)
{
  char *v1; // esi
  CMapAxisHandle *v2; // eax
  CMapAxisHandle *v3; // esi

  if ( pHelperInfo->m_Parameters.m_Size <= 0 || (v1 = *pHelperInfo->m_Parameters.m_Memory.m_pMemory) == nullptr )
    v1 = pszDefaultKeyName;
  v2 = (CMapAxisHandle *)operator new(nSize: 0x2F0u);
  if ( v2 != nullptr )
    v3 = CMapAxisHandle::CMapAxisHandle(this: v2, pszKey: v1);
  else
    v3 = nullptr;
  v3->SetRenderColor_2(this: v3, a2: 255u, a3: 255u, a4: 255u);
  return v3;
}
