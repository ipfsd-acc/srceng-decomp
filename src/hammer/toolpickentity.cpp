// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolpickentity.cpp
// Functions: 13
// ============================================================

#include "hammer\toolpickentity.h"

//------------------------------------------------------------------------------
// Address: 0x101652D0
// Name: public: virtual bool CToolPickEntity::OnRMouseUpLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickEntity::OnRMouseUpLogical(
        CBaseToolSystem *this,
        int iUserData,
        int guid,
        struct SpatializationInfo_t *info)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101652E0
// Name: public: virtual bool CToolPickEntity::OnMouseMoveLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickEntity::OnMouseMoveLogical(
        CToolPickEntity *this,
        CMapViewLogical *pView,
        CMapViewLogical *nFlags,
        const Vector2D *vPoint)
{
  HCURSOR CursorA; // eax
  AFX_MODULE_STATE *ModuleState; // eax

  CursorA = dword_107B37EC;
  if ( dword_107B37EC == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: ModuleState->m_hCurrentInstanceHandle, lpCursorName: (LPCSTR)0x138);
    dword_107B37EC = CursorA;
  }
  SetCursor(hCursor: CursorA);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165310
// Name: protected: void CToolPickEntity::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::DeselectAll(CToolPickEntity *this)
{
  int v2; // ebx
  int v3; // edi

  v2 = 0;
  v3 = 0;
  if ( this->m_Entities.m_Size <= 0 )
  {
    this->m_Entities.m_Size = 0;
  }
  else
  {
    do
    {
      this->m_Entities.m_Memory.m_pMemory[v2].pEntity->SetSelectionState(
        this: this->m_Entities.m_Memory.m_pMemory[v2].pEntity,
        a2: SELECT_NONE);
      ++v3;
      ++v2;
    }
    while ( v3 < this->m_Entities.m_Size );
    this->m_Entities.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165350
// Name: protected: void CToolPickEntity::RemoveFromList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::RemoveFromList(CToolPickEntity *this, int nIndex)
{
  int m_Size; // eax
  SelectedEntity_t *m_pMemory; // edx
  __int64 v4; // xmm0_8
  int v5; // eax
  SelectedEntity_t *v6; // edx

  if ( nIndex >= 0 && nIndex < this->m_Entities.m_Size )
  {
    m_Size = this->m_Entities.m_Size;
    if ( m_Size > 0 )
    {
      if ( nIndex != m_Size - 1 )
      {
        m_pMemory = this->m_Entities.m_Memory.m_pMemory;
        v4 = *(_QWORD *)&m_pMemory[m_Size - 1].pEntity;
        v5 = (int)&m_pMemory[m_Size - 1];
        v6 = &m_pMemory[nIndex];
        *(_QWORD *)&v6->pEntity = v4;
        v6->eOriginalState = *(_DWORD *)(v5 + 8);
      }
      --this->m_Entities.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101653A0
// Name: public: CToolPickEntity::CToolPickEntity(void)
// Source: json
//------------------------------------------------------------------------------
CToolPickEntity *__thiscall CToolPickEntity::CToolPickEntity(CToolPickEntity *this)
{
  SelectedEntity_t *m_pMemory; // esi

  this->__vftable = (CToolPickEntity_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolPickEntity_vtbl *)&CToolPickEntity::`vftable';
  this->m_Entities.m_Memory.m_pMemory = nullptr;
  this->m_Entities.m_Memory.m_nAllocationCount = 0;
  this->m_Entities.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  this->m_Entities.m_Size = 0;
  this->m_Entities.m_pElements = m_pMemory;
  this->m_pNotifyTarget = nullptr;
  this->m_bAllowMultiSelect = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10165420
// Name: public: virtual CToolPickEntity::~CToolPickEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::~CToolPickEntity(CToolPickEntity *this)
{
  CUtlVector<SelectedEntity_t,CUtlMemory<SelectedEntity_t,int> > *p_m_Entities; // esi

  this->__vftable = (CToolPickEntity_vtbl *)&CToolPickEntity::`vftable';
  p_m_Entities = &this->m_Entities;
  this->m_Entities.m_Size = 0;
  if ( this->m_Entities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Entities->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Entities->m_Memory.m_pMemory);
      p_m_Entities->m_Memory.m_pMemory = nullptr;
    }
    p_m_Entities->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Entities->m_pElements = p_m_Entities->m_Memory.m_pMemory;
  if ( p_m_Entities->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Entities->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Entities->m_Memory.m_pMemory);
      p_m_Entities->m_Memory.m_pMemory = nullptr;
    }
    p_m_Entities->m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CToolPickEntity_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101654C0
// Name: protected: void CToolPickEntity::DeselectEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::DeselectEntity(CToolPickEntity *this, int nIndex)
{
  SelectedEntity_t *m_pMemory; // eax
  bool v4; // zf
  CMapEntity *pEntity; // ecx
  SelectionState_t (__thiscall *SetSelectionState)(CMapAtom *, SelectionState_t); // eax

  if ( nIndex >= 0 && nIndex < this->m_Entities.m_Size )
  {
    m_pMemory = this->m_Entities.m_Memory.m_pMemory;
    v4 = m_pMemory[nIndex].eOriginalState == EntityState_Partial;
    pEntity = m_pMemory[nIndex].pEntity;
    SetSelectionState = pEntity->SetSelectionState;
    if ( v4 )
    {
      SetSelectionState(this: pEntity, a2: SELECT_NONE);
      this->m_Entities.m_Memory.m_pMemory[nIndex].eState = EntityState_None;
    }
    else
    {
      SetSelectionState(this: pEntity, a2: SELECT_NONE);
      CToolPickEntity::RemoveFromList(this, nIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165550
// Name: protected: void CToolPickEntity::AddToList(class CMapEntity __near *,enum EntityState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::AddToList(CToolPickEntity *this, CMapEntity *pEntity, float eState)
{
  int m_nAllocationCount; // eax
  CUtlMemory<Vector,int> *p_m_Entities; // esi
  int m_Size; // edi
  Vector *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Entities.m_Memory.m_nAllocationCount;
  p_m_Entities = (CUtlMemory<Vector,int> *)&this->m_Entities;
  m_Size = this->m_Entities.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CheckListItem,int>::Grow(this: p_m_Entities, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Entities[1].m_pMemory;
  m_pMemory = p_m_Entities->m_pMemory;
  v7 = (int)p_m_Entities[1].m_pMemory - m_Size - 1;
  p_m_Entities[1].m_nAllocationCount = (int)p_m_Entities->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v7);
  v8 = m_Size;
  LODWORD(p_m_Entities->m_pMemory[v8].x) = pEntity;
  p_m_Entities->m_pMemory[v8].y = eState;
  p_m_Entities->m_pMemory[v8].z = eState;
}

//------------------------------------------------------------------------------
// Address: 0x101655D0
// Name: protected: void CToolPickEntity::CycleSelectEntity(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::CycleSelectEntity(CToolPickEntity *this, CMapEntity *pEntity)
{
  int m_Size; // esi
  int v3; // eax
  SelectedEntity_t *m_pMemory; // edi
  CMapEntity **p_pEntity; // edx
  EntityState_t eState; // esi
  SelectedEntity_t *v7; // edx

  m_Size = this->m_Entities.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  p_pEntity = &m_pMemory->pEntity;
  while ( *p_pEntity != pEntity )
  {
    ++v3;
    p_pEntity += 3;
    if ( v3 >= m_Size )
      goto LABEL_5;
  }
  if ( v3 == -1 )
  {
LABEL_5:
    CToolPickEntity::AddToList(this, pEntity, eState: 0.0);
  }
  else
  {
    eState = m_pMemory[v3].eState;
    v7 = &m_pMemory[v3];
    switch ( eState )
    {
      case EntityState_Partial:
LABEL_12:
        CToolPickEntity::DeselectEntity(this, nIndex: v3);
        return;
      case EntityState_Select:
        if ( v7->eOriginalState == EntityState_Partial )
        {
          v7->eState = EntityState_Partial;
          return;
        }
        goto LABEL_12;
      case EntityState_None:
        v7->eState = EntityState_Select;
        break;
      default:
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165650
// Name: protected: void CToolPickEntity::SelectEntity(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::SelectEntity(CToolPickEntity *this, CMapEntity *pEntity)
{
  int m_Size; // edx
  int v3; // eax
  SelectedEntity_t *m_pMemory; // edi

  m_Size = this->m_Entities.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  while ( m_pMemory->pEntity != pEntity )
  {
    ++v3;
    ++m_pMemory;
    if ( v3 >= m_Size )
      goto LABEL_5;
  }
  if ( v3 == -1 )
  {
LABEL_5:
    CToolPickEntity::AddToList(this, pEntity, eState: 0.0);
    pEntity->SetSelectionState(this: pEntity, a2: SELECT_NORMAL);
  }
  else
  {
    this->m_Entities.m_Memory.m_pMemory[v3].eState = EntityState_Select;
    pEntity->SetSelectionState(this: pEntity, a2: SELECT_NORMAL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101656B0
// Name: public: virtual bool CToolPickEntity::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickEntity::OnLMouseDown3D(
        CToolPickEntity *this,
        CMapView3D *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  CMapClass *v5; // eax
  CMapClass *v6; // eax
  CMapEntity *v7; // eax
  CMapEntity *v8; // edi

  v5 = CMapView3D::NearestObjectAt(
         this: pView,
         vPoint,
         ulFace: (unsigned int *)&vPoint,
         nFlags: 0,
         pLocalMatrix: nullptr);
  if ( v5 == nullptr )
    return 1;
  v6 = v5->PrepareSelection(this: v5, a2: selectObjects);
  v7 = (CMapEntity *)__RTDynamicCast(
                       inptr: v6,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v8 = v7;
  if ( v7 != nullptr )
  {
    if ( this->m_bAllowMultiSelect && (nFlags & 8) != 0 )
    {
      CToolPickEntity::CycleSelectEntity(this, pEntity: v7);
    }
    else
    {
      CToolPickEntity::DeselectAll(this);
      CToolPickEntity::SelectEntity(this, pEntity: v8);
    }
    if ( this->m_pNotifyTarget != nullptr )
      this->m_pNotifyTarget->OnNotifyPickEntity(this: this->m_pNotifyTarget, a2: this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165750
// Name: public: virtual bool CToolPickEntity::OnLMouseDownLogical(class CMapViewLogical __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPickEntity::OnLMouseDownLogical(
        CToolPickEntity *this,
        CMapViewLogical *pView,
        char nFlags,
        const Vector2D *vPoint)
{
  CMapClass *v5; // eax
  CMapEntity *v6; // eax
  CMapEntity *v7; // edi
  HitInfo_s hitData; // [esp+4h] [ebp-4Ch] BYREF

  if ( pView->ObjectsAt(this: &pView->CMapView, a2: vPoint, a3: &hitData, a4: 1, a5: 0) <= 0
    || hitData.pObject == nullptr )
  {
    return 1;
  }
  v5 = hitData.pObject->PrepareSelection(this: hitData.pObject, a2: 1);
  v6 = (CMapEntity *)__RTDynamicCast(
                       inptr: v5,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    if ( this->m_bAllowMultiSelect && (nFlags & 8) != 0 )
    {
      CToolPickEntity::CycleSelectEntity(this, pEntity: v6);
    }
    else
    {
      CToolPickEntity::DeselectAll(this);
      CToolPickEntity::SelectEntity(this, pEntity: v7);
    }
    if ( this->m_pNotifyTarget != nullptr )
      this->m_pNotifyTarget->OnNotifyPickEntity(this: this->m_pNotifyTarget, a2: this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165800
// Name: public: void CToolPickEntity::GetSelectedEntities(class CUtlReferenceVector<class CMapEntity> __near &,class CUtlReferenceVector<class CMapEntity> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPickEntity::GetSelectedEntities(
        CToolPickEntity *this,
        CUtlReferenceVector<CMapEntity> *EntityListFull,
        CUtlReferenceVector<CMapEntity> *EntityListPartial)
{
  int v4; // ebx
  SelectedEntity_t *m_pMemory; // eax
  EntityState_t eState; // ecx
  CMapEntity *v7; // eax
  CUtlReference<CMapEntity> *v8; // ecx
  CMapEntity *pEntity; // eax
  CUtlReference<CMapEntity> *m_pHead; // ecx
  CUtlReference<CMapEntity> v11; // [esp+8h] [ebp-28h] BYREF
  CUtlReference<CMapEntity> src; // [esp+14h] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-10h]
  int v14; // [esp+2Ch] [ebp-4h]

  CUtlReferenceVector<CMapEntity>::RemoveAll(this: EntityListFull);
  CUtlReferenceVector<CMapEntity>::RemoveAll(this: EntityListPartial);
  i = 0;
  if ( this->m_Entities.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->m_Entities.m_Memory.m_pMemory;
      eState = m_pMemory[v4].eState;
      if ( eState != EntityState_Select )
      {
        if ( eState == EntityState_Partial )
        {
          pEntity = m_pMemory[v4].pEntity;
          v11.m_pPrev = nullptr;
          v11.m_pNext = nullptr;
          v11.m_pObject = pEntity;
          if ( pEntity != nullptr )
          {
            v11.m_pNext = pEntity->m_References.m_pHead;
            m_pHead = pEntity->m_References.m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &v11;
            v11.m_pPrev = nullptr;
            pEntity->m_References.m_pHead = &v11;
          }
          v14 = 1;
          CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
            this: EntityListPartial,
            elem: EntityListPartial->m_Size,
            src: &v11);
          v14 = -1;
          if ( v11.m_pObject != nullptr )
          {
            if ( v11.m_pPrev != nullptr )
            {
              v11.m_pPrev->m_pNext = v11.m_pNext;
              if ( v11.m_pNext != nullptr )
                v11.m_pNext->m_pPrev = v11.m_pPrev;
            }
            else if ( v11.m_pObject->m_References.m_pHead == &v11 )
            {
              v11.m_pObject->m_References.m_pHead = v11.m_pNext;
              if ( v11.m_pNext != nullptr )
                v11.m_pNext->m_pPrev = nullptr;
            }
            memset(&v11, 0, sizeof(v11));
          }
        }
        goto LABEL_29;
      }
      v7 = m_pMemory[v4].pEntity;
      src.m_pPrev = nullptr;
      src.m_pNext = nullptr;
      src.m_pObject = v7;
      if ( v7 != nullptr )
      {
        src.m_pNext = v7->m_References.m_pHead;
        v8 = v7->m_References.m_pHead;
        if ( v8 != nullptr )
          v8->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v7->m_References.m_pHead = &src;
      }
      v14 = 0;
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
        this: EntityListFull,
        elem: EntityListFull->m_Size,
        &src);
      v14 = -1;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev == nullptr )
        {
          if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
LABEL_15:
          memset(&src, 0, sizeof(src));
          goto LABEL_29;
        }
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext == nullptr )
          goto LABEL_15;
        src.m_pNext->m_pPrev = src.m_pPrev;
        memset(&src, 0, sizeof(src));
      }
LABEL_29:
      ++v4;
      ++i;
    }
    while ( i < this->m_Entities.m_Size );
  }
}
