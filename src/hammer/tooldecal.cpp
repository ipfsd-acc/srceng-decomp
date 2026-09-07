// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/tooldecal.cpp
// Functions: 9
// ============================================================

#include "hammer\tooldecal.h"

//------------------------------------------------------------------------------
// Address: 0x10059210
// Name: public: class CMapInstance __near * CMapEntity::GetChildOfType<class CMapInstance>(class CMapInstance __near *)
// Source: json
//------------------------------------------------------------------------------
CMapInstance *__thiscall CMapEntity::GetChildOfType<CMapInstance>(CMapEntity *this, CMapInstance *ignoredArg)
{
  int v3; // esi
  CMapInstance *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapInstance *)__RTDynamicCast(
                               inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory
                                                                                            + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapInstance `RTTI Type Descriptor',
                               isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5EC0
// Name: public: class CMapStudioModel __near * CMapEntity::GetChildOfType<class CMapStudioModel>(class CMapStudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
CMapStudioModel *__thiscall CMapEntity::GetChildOfType<CMapStudioModel>(CMapEntity *this, CMapStudioModel *ignoredArg)
{
  int v3; // esi
  CMapStudioModel *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapStudioModel *)__RTDynamicCast(
                                  inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory
                                                                                               + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                                  VfDelta: 0,
                                  SrcType: &CMapClass `RTTI Type Descriptor',
                                  TargetType: &CMapStudioModel `RTTI Type Descriptor',
                                  isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D0D0
// Name: public: class CMapKeyFrame __near * CMapEntity::GetChildOfType<class CMapKeyFrame>(class CMapKeyFrame __near *)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__thiscall CMapEntity::GetChildOfType<CMapKeyFrame>(CMapEntity *this, CMapKeyFrame *ignoredArg)
{
  int v3; // esi
  CMapKeyFrame *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapKeyFrame *)__RTDynamicCast(
                               inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory
                                                                                            + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapKeyFrame `RTTI Type Descriptor',
                               isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122BE0
// Name: public: class CMapSweptPlayerHull __near * CMapEntity::GetChildOfType<class CMapSweptPlayerHull>(class CMapSweptPlayerHull __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSweptPlayerHull *__thiscall CMapEntity::GetChildOfType<CMapSweptPlayerHull>(
        CMapEntity *this,
        CMapSweptPlayerHull *ignoredArg)
{
  int v3; // esi
  CMapSweptPlayerHull *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapSweptPlayerHull *)__RTDynamicCast(
                                      inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                                      VfDelta: 0,
                                      SrcType: &CMapClass `RTTI Type Descriptor',
                                      TargetType: &CMapSweptPlayerHull `RTTI Type Descriptor',
                                      isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013DEB0
// Name: public: class CMapSolid __near * CMapEntity::GetChildOfType<class CMapSolid>(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CMapEntity::GetChildOfType<CMapSolid>(CMapEntity *this, CMapSolid *ignoredArg)
{
  int v3; // esi
  CMapSolid *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapSolid *)__RTDynamicCast(
                            inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory
                                                                                         + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                            VfDelta: 0,
                            SrcType: &CMapClass `RTTI Type Descriptor',
                            TargetType: &CMapSolid `RTTI Type Descriptor',
                            isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B0B0
// Name: public: virtual bool CToolDecal::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolDecal::OnKeyDown3D(
        CToolDecal *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v5; // eax

  if ( nChar == 27 )
  {
    v5 = ToolManager();
    CToolManager::SetTool(this: v5, eNewTool: TOOL_POINTER);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1015B0D0
// Name: public: virtual bool CToolDecal::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDecal::OnMouseMove3D(
        CToolDecal *this,
        CMapView3D *pView,
        CMapView3D *nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  CursorA = hCursor;
  if ( hCursor == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0xEF);
    hCursor = CursorA;
  }
  SetCursor(hCursor: CursorA);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015B100
// Name: public: class CMapDecal __near * CMapEntity::GetChildOfType<class CMapDecal>(class CMapDecal __near *)
// Source: json
//------------------------------------------------------------------------------
CMapDecal *__thiscall CMapEntity::GetChildOfType<CMapDecal>(CMapEntity *this, CMapDecal *ignoredArg)
{
  int v3; // esi
  CMapDecal *result; // eax

  v3 = 0;
  if ( this->m_Children.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CMapDecal *)__RTDynamicCast(
                            inptr: this->m_Children.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory
                                                                                         + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject,
                            VfDelta: 0,
                            SrcType: &CMapClass `RTTI Type Descriptor',
                            TargetType: &CMapDecal `RTTI Type Descriptor',
                            isReference: 0);
    if ( result != nullptr )
      break;
    if ( ++v3 >= this->m_Children.m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B160
// Name: public: virtual bool CToolDecal::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDecal::OnLMouseDown3D(
        CToolDecal *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView3D *v4; // esi
  CMapDoc *v5; // eax
  const Vector2D *v6; // ebx
  CMapClass *v7; // eax
  CMapSolid *v8; // edi
  CMapFace *Face; // eax
  CMapEntity *v10; // esi
  CHistory *History; // eax
  Vector2D *v12; // eax
  CEditGameClass_vtbl *v13; // ebx
  const char *DefaultTextureName; // eax
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  CMapDoc *v16; // edi
  CMapWorld *m_pWorld; // ebx
  CMapDecal *ChildOf; // eax
  CHistory *v19; // eax
  Vector HitNormal; // [esp+Ch] [ebp-40h] BYREF
  Vector HitPos; // [esp+18h] [ebp-34h] BYREF
  Vector Start; // [esp+24h] [ebp-28h] BYREF
  Vector End; // [esp+30h] [ebp-1Ch] BYREF
  CMapDoc *pDoc; // [esp+3Ch] [ebp-10h]
  int v26; // [esp+48h] [ebp-4h]

  v4 = pView;
  v5 = pView->GetMapDoc(this: &pView->CMapView);
  v6 = vPoint;
  pDoc = v5;
  v7 = CMapView3D::NearestObjectAt(this: v4, vPoint, ulFace: (unsigned int *)&pView, nFlags: 0, pLocalMatrix: nullptr);
  if ( v7 != nullptr )
  {
    v8 = (CMapSolid *)__RTDynamicCast(
                        inptr: v7,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapSolid `RTTI Type Descriptor',
                        isReference: 0);
    if ( v8 != nullptr )
    {
      CCamera::BuildRay(this: v4->m_pCamera, vView: v6, vStart: &Start, vEnd: &End);
      Face = CMapSolid::GetFace(this: v8, nFace: (int)pView);
      if ( CMapFace::TraceLine(this: Face, &HitPos, &HitNormal, &Start, &End) )
      {
        v10 = nullptr;
        History = GetHistory();
        CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Create decal", bFromOpposite: 0);
        v12 = (Vector2D *)operator new(nSize: 0x184u);
        vPoint = v12;
        v26 = 0;
        if ( v12 != nullptr )
          v10 = CMapEntity::CMapEntity(this: (CMapEntity *)v12);
        v26 = -1;
        v13 = v10->CEditGameClass::__vftable;
        DefaultTextureName = GetDefaultTextureName();
        v13->SetKeyValue(this: &v10->CEditGameClass, a2: "texture", a3: DefaultTextureName);
        SetOrigin = v10->SetOrigin;
        v10->flags |= 1u;
        SetOrigin(this: v10, a2: &HitPos);
        v10->SetClass(this: &v10->CEditGameClass, a2: "infodecal", a3: false);
        v16 = pDoc;
        m_pWorld = pDoc->m_pWorld;
        ChildOf = CMapEntity::GetChildOfType<CMapDecal>(this: v10, ignoredArg: nullptr);
        if ( ChildOf != nullptr )
          CMapDecal::DecalAllSolids(this: ChildOf, pWorld: m_pWorld);
        v10->CalcBounds(this: v10, a2: 1);
        v16->AddObjectToWorld(this: v16, a2: v10, a3: nullptr);
        v19 = GetHistory();
        CHistory::KeepNew(this: v19, pObject: v10, bKeepChildren: true);
        v16->SetModifiedFlag(this: v16, a2: 1);
      }
    }
  }
  return 1;
}
