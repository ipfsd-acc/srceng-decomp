// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/physics_saverestore.cpp
// Functions: 37
// ============================================================

#include "game\shared\physics_saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x10143360
// Name: class ISaveRestoreBlockHandler __near * GetPhysSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler *__cdecl GetPhysSaveRestoreBlockHandler()
{
  return &g_PhysSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10143370
// Name: class ISaveRestoreOps __near * GetPhysObjSaveRestoreOps(enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
CPhysObjSaveRestoreOps *__cdecl GetPhysObjSaveRestoreOps(PhysInterfaceId_t type)
{
  PhysInterfaceId_t i; // eax

  if ( !inited )
  {
    inited = true;
    for ( i = PIID_UNKNOWN; i < PIID_NUM_TYPES; ++i )
      g_PhysObjSaveRestoreOps[i].m_type = i;
  }
  return &g_PhysObjSaveRestoreOps[type];
}

//------------------------------------------------------------------------------
// Address: 0x101433A0
// Name: private: static bool CPhysSaveRestoreBlockHandler::SaveQueueFunc(struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &,struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CPhysSaveRestoreBlockHandler::SaveQueueFunc(
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *left,
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *right)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v4; // esi
  unsigned int v5; // ecx
  IHandleEntity *v6; // eax
  int v7; // edi

  if ( left->header.type != right->header.type )
    return left->header.type > right->header.type;
  m_Index = left->header.hEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = m_pEntity + 2;
  v5 = right->header.hEntity.m_Index;
  if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
    v6 = nullptr;
  else
    v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  v7 = ((int (__thiscall *)(IHandleEntity *))v6[2].__vftable[3].SetRefEHandle)(a1: &v6[2]);
  return ((int (__thiscall *)(IHandleEntity *))v4->__vftable[3].SetRefEHandle)(a1: v4) > v7;
}

//------------------------------------------------------------------------------
// Address: 0x10143430
// Name: public: struct BBox_t __near & BBox_t::operator=(struct BBox_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BBox_t *__thiscall BBox_t::operator=(BBox_t *this, const BBox_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10143460
// Name: IsValidEntityPointer
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsValidEntityPointer(C_BaseEntity *ptr)
{
  int v1; // edi
  int v2; // esi
  C_BaseEntity *BaseEntity; // eax

  v1 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 24))(a1: cl_entitylist.m_Index + 131092);
  v2 = 0;
  if ( v1 < 0 )
    return 0;
  while ( 1 )
  {
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v2);
    if ( BaseEntity != nullptr && BaseEntity == ptr )
      break;
    if ( ++v2 > v1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10144CB0
// Name: public: char const __near * CPhysSaveRestoreBlockHandler::GetModelName(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysSaveRestoreBlockHandler::GetModelName(
        CPhysSaveRestoreBlockHandler *this,
        IPhysicsObject *pObject)
{
  unsigned __int16 v3; // ax
  int v5; // edx
  UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  IVModelInfoClient_vtbl *v7; // esi
  const struct model_t *v8; // eax
  const char *v9; // eax
  CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = pObject;
  v3 = CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysObjectModels.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  v5 = v3;
  m_pMemory = this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory;
  v7 = modelinfo->__vftable;
  v8 = modelinfo->GetModel(this: modelinfo, a2: m_pMemory[v5].m_Data.elem);
  v9 = v7->GetModelName(this: modelinfo, a2: v8);
  return AllocPooledString(pszValue: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10144D20
// Name: public: struct BBox_t __near * CPhysSaveRestoreBlockHandler::GetBBox(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
BBox_t *__thiscall CPhysSaveRestoreBlockHandler::GetBBox(CPhysSaveRestoreBlockHandler *this, IPhysicsObject *pObject)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v5; // ax
  CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t v6; // [esp+4h] [ebp-24h] BYREF
  CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t search; // [esp+20h] [ebp-8h] BYREF

  search.key = pObject;
  v3 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysObjectCustomModels.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  v6.key = this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  v5 = CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysCollideBBoxModels.m_Tree,
         search: &v6);
  if ( v5 == 0xFFFF )
    return nullptr;
  else
    return &this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10144D90
// Name: public: int CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(class C_BaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(
        CPhysSaveRestoreBlockHandler::CEntityRestoreSet *this,
        C_BaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        PhysInterfaceId_t type)
{
  int v6; // edi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v7; // esi

  v6 = CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
         this,
         elem: this->m_Size);
  v7 = &this->m_Memory.m_pMemory[v6];
  v7->ppPhysObj = ppPhysObj;
  if ( pOwner != nullptr )
    v7->header.hEntity.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    v7->header.hEntity.m_Index = -1;
  v7->header.type = type;
  v7->header.nObjects = pTypeDesc->fieldSize;
  v7->header.fieldName = AllocPooledString(pszValue: pTypeDesc->fieldName);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10144F00
// Name: public: CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler *__thiscall CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(
        CPhysSaveRestoreBlockHandler *this)
{
  CPhysSaveRestoreBlockHandler *result; // eax

  result = this;
  this->IPhysSaveRestoreManager::__vftable = (IPhysSaveRestoreManager_vtbl *)&IPhysSaveRestoreManager::`vftable';
  this->CDefSaveRestoreBlockHandler::ISaveRestoreBlockHandler::__vftable = (CPhysSaveRestoreBlockHandler_vtbl *)&CPhysSaveRestoreBlockHandler::`vftable'{for `CDefSaveRestoreBlockHandler'};
  this->IPhysSaveRestoreManager::__vftable = (IPhysSaveRestoreManager_vtbl *)&CPhysSaveRestoreBlockHandler::`vftable'{for `IPhysSaveRestoreManager'};
  this->m_QueuedSaves.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_QueuedSaves.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedSaves.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_QueuedSaves.m_heap.m_Size = 0;
  this->m_QueuedSaves.m_heap.m_pElements = nullptr;
  this->m_QueuedSaves.m_LessFunc = nullptr;
  this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_QueuedRestores.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_QueuedRestores.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_QueuedRestores.m_Tree.m_Root = -1;
  this->m_QueuedRestores.m_Tree.m_NumElements = 0;
  this->m_QueuedRestores.m_Tree.m_FirstFree = -1;
  this->m_QueuedRestores.m_Tree.m_LastAlloc.index = -1;
  this->m_QueuedRestores.m_Tree.m_pElements = this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory;
  this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysObjectModels.m_Tree.m_Root = -1;
  this->m_PhysObjectModels.m_Tree.m_NumElements = 0;
  this->m_PhysObjectModels.m_Tree.m_FirstFree = -1;
  this->m_PhysObjectModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysObjectModels.m_Tree.m_pElements = this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory;
  this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_Root = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_NumElements = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_FirstFree = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_pElements = this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory;
  this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_Root = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_NumElements = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_FirstFree = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_pElements = this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory;
  this->m_QueuedSaves.m_LessFunc = CPhysSaveRestoreBlockHandler::SaveQueueFunc;
  if ( this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(C_BaseEntity *const *, C_BaseEntity *const *))CDefOps<C_BaseEntity *>::LessFunc;
  if ( this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(IPhysicsObject *const *, IPhysicsObject *const *))CDefOps<C_BaseEntity *>::LessFunc;
  if ( this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(IPhysicsObject *const *, IPhysicsObject *const *))CDefOps<C_BaseEntity *>::LessFunc;
  if ( this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CPhysCollide *const *, const CPhysCollide *const *))CDefOps<C_BaseEntity *>::LessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10145030
// Name: public: virtual char const __near * CPhysSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysSaveRestoreBlockHandler::GetBlockName(CPhysSaveRestoreBlockHandler *this)
{
  return "Physics";
}

//------------------------------------------------------------------------------
// Address: 0x10145040
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PreSave(CPhysSaveRestoreBlockHandler *this, CSaveRestoreData *__formal)
{
  this->m_blockHeader.nSaved = 0;
  this->m_blockHeader.pWorldObject = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10145060
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PreRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PreRestore(CPhysSaveRestoreBlockHandler *this)
{
  physprerestoreparams_t params; // [esp+0h] [ebp-Ch] BYREF

  if ( physenv != nullptr )
  {
    params.recreatedObjectCount = 0;
    physenv->PreRestore(this: physenv, a2: &params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145090
// Name: public: virtual void CPhysSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::WriteSaveHeaders(CPhysSaveRestoreBlockHandler *this, ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &PHYS_SAVE_RESTORE_VERSION, a3: 1);
  pSave->WriteAll(this: pSave, a2: &this->m_blockHeader, a3: &PhysBlockHeader_t::m_DataMap);
}

//------------------------------------------------------------------------------
// Address: 0x101450D0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ReadRestoreHeaders(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  this->m_fDoLoad = pRestore->ReadShort_2(this: pRestore) == PHYS_SAVE_RESTORE_VERSION;
  pRestore->ReadAll(this: pRestore, a2: &this->m_blockHeader, a3: &PhysBlockHeader_t::m_DataMap);
}

//------------------------------------------------------------------------------
// Address: 0x10145110
// Name: public: void CPhysSaveRestoreBlockHandler::RestorePhysicsObject(class IRestore __near *,struct PhysObjectHeader_t const __near &,void __near * __near *,class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header,
        void **ppObject,
        const struct CPhysCollide *pCollide)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax
  const char *modelName; // edx
  physrestoreparams_t params; // [esp+0h] [ebp-20h] BYREF

  if ( physenv != nullptr )
  {
    params.ppObject = ppObject;
    m_Index = header->hEntity.m_Index;
    params.pRestore = pRestore;
    params.type = header->type;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    modelName = header->modelName;
    params.pGameData = m_pEntity;
    params.pName = modelName;
    params.pCollisionModel = pCollide;
    params.pGameTrace = physgametrace;
    params.pEnvironment = physenv;
    ((void (__stdcall *)(physrestoreparams_t *))physenv->Restore)(a1: &params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145430
// Name: public: void CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(class IRestore __near *,struct PhysObjectHeader_t const __near &,struct CPhysSaveRestoreBlockHandler::QueuedItem_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header,
        CPhysSaveRestoreBlockHandler::QueuedItem_t *pItem,
        int nObjects)
{
  const char *modelName; // eax
  int v7; // eax
  vcollide_t *v8; // eax
  __int16 v9; // cx
  struct CPhysCollide **solids; // eax
  int iCollide; // edx
  const struct CPhysCollide *Bbox; // edi
  void **v13; // eax
  void **ppPhysObj; // eax
  void **v15; // eax
  IPhysicsObject *v16; // eax
  IPhysSaveRestoreManager_vtbl *v17; // edx
  IPhysSaveRestoreManager *v18; // ecx
  int modelIndex; // [esp+Ch] [ebp-4h]

  if ( nObjects == 1 )
  {
    pRestore->StartBlock(this: pRestore);
    modelName = header->modelName;
    modelIndex = -1;
    if ( modelName != nullptr )
    {
      v7 = modelinfo->GetModelIndex(this: modelinfo, a2: modelName);
      modelIndex = v7;
      if ( v7 == -1 )
        goto LABEL_29;
      v8 = modelinfo->GetVCollide(this: modelinfo, a2: v7);
      if ( v8 == nullptr )
        goto LABEL_29;
      v9 = *(_WORD *)v8;
      if ( (*(_WORD *)v8 & 0x7FFF) == 0 )
        goto LABEL_29;
      solids = v8->solids;
      if ( solids == nullptr )
        goto LABEL_29;
      iCollide = header->iCollide;
      if ( iCollide >= (v9 & 0x7FFF) )
        goto LABEL_29;
      Bbox = solids[iCollide];
      goto LABEL_20;
    }
    if ( vec3_origin.x != header->bbox.mins.x
      || vec3_origin.y != header->bbox.mins.y
      || vec3_origin.z != header->bbox.mins.z
      || vec3_origin.x != header->bbox.maxs.x
      || vec3_origin.y != header->bbox.maxs.y
      || vec3_origin.z != header->bbox.maxs.z )
    {
      Bbox = PhysCreateBbox(minsIn: &header->bbox.mins, maxsIn: &header->bbox.maxs);
      HIBYTE(nObjects) = 1;
LABEL_20:
      if ( Bbox != nullptr )
      {
        ppPhysObj = pItem->ppPhysObj;
        if ( *ppPhysObj != nullptr )
        {
          DevMsg(
            a1: "Physics object pointer unexpectedly non-null before restore. Should be creating physics object in CreatePhysics()?\n");
        }
        else
        {
          CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
            this,
            pRestore,
            header,
            ppObject: ppPhysObj,
            pCollide: Bbox);
          v15 = pItem->ppPhysObj;
          if ( *v15 != nullptr )
          {
            v16 = (IPhysicsObject *)*v15;
            v17 = this->IPhysSaveRestoreManager::__vftable;
            v18 = &this->IPhysSaveRestoreManager;
            if ( HIBYTE(nObjects) != 0 )
              v17->AssociateModel(this: v18, a2: v16, a3: Bbox);
            else
              v17->AssociateModel_2(this: v18, a2: v16, a3: modelIndex);
          }
          else
          {
            DevMsg(a1: "Failed to restore physics object\n");
          }
        }
        goto LABEL_25;
      }
LABEL_29:
      DevMsg(a1: "Failed to reestablish collision model for object\n");
LABEL_25:
      pRestore->EndBlock(this: pRestore);
      return;
    }
    if ( header->sphere.radius == 0.0 )
      goto LABEL_29;
    v13 = pItem->ppPhysObj;
    if ( *v13 == nullptr )
      CPhysSaveRestoreBlockHandler::RestorePhysicsObject(this, pRestore, header, ppObject: v13, pCollide: nullptr);
  }
  else
  {
    DevMsg(a1: "Don't know how to reconsitite models for physobj array \n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145630
// Name: public: struct CPhysSaveRestoreBlockHandler::QueuedItem_t __near * CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler::QueuedItem_t *__thiscall CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(
        CPhysSaveRestoreBlockHandler::CEntityRestoreSet *this,
        const char *itemFieldName)
{
  int m_Size; // edx
  int v3; // eax
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // esi
  const char **i; // ecx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = &this->m_Memory.m_pMemory->header.fieldName; *i != itemFieldName; i += 14 )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return &m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x101491B0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::Save(CPhysSaveRestoreBlockHandler *this, ISave *pSave)
{
  CPhysSaveRestoreBlockHandler *v2; // ebx
  int m_Size; // eax
  CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *p_m_QueuedSaves; // edi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // edi
  unsigned int m_Index; // ecx
  int nObjects; // eax
  int v8; // ebx
  PhysInterfaceId_t type; // edx
  _DWORD v10[3]; // [esp+4h] [ebp-10h] BYREF
  CPhysSaveRestoreBlockHandler *v11; // [esp+10h] [ebp-4h]

  v2 = this;
  this->m_blockHeader.pWorldObject = g_PhysWorldObject;
  m_Size = this->m_QueuedSaves.m_heap.m_Size;
  v11 = this;
  this->m_blockHeader.nSaved = m_Size;
  if ( m_Size != 0 )
  {
    p_m_QueuedSaves = &this->m_QueuedSaves;
    do
    {
      m_pMemory = p_m_QueuedSaves->m_heap.m_Memory.m_pMemory;
      m_Index = m_pMemory->header.hEntity.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        pSave->WriteAll(this: pSave, a2: m_pMemory, a3: &PhysObjectHeader_t::m_DataMap);
        pSave->StartBlock(this: pSave);
        nObjects = m_pMemory->header.nObjects;
        if ( nObjects != 0 )
        {
          v8 = 0;
          if ( nObjects > 0 )
          {
            do
            {
              pSave->StartBlock(this: pSave);
              if ( physenv != nullptr && m_pMemory->ppPhysObj[v8] != nullptr )
              {
                type = m_pMemory->header.type;
                v10[1] = m_pMemory->ppPhysObj[v8];
                v10[2] = type;
                v10[0] = pSave;
                ((void (__stdcall *)(_DWORD *))physenv->Save)(a1: v10);
              }
              pSave->EndBlock(this: pSave);
              ++v8;
            }
            while ( v8 < m_pMemory->header.nObjects );
          }
          v2 = v11;
        }
        pSave->EndBlock(this: pSave);
      }
      p_m_QueuedSaves = &v2->m_QueuedSaves;
      CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(this: &v2->m_QueuedSaves);
    }
    while ( v2->m_QueuedSaves.m_heap.m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101492B0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PostSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PostSave(CPhysSaveRestoreBlockHandler *this)
{
  bool v2; // sf
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // ecx

  v2 = this->m_QueuedSaves.m_heap.m_Memory.m_nGrowSize < 0;
  this->m_QueuedSaves.m_heap.m_Size = 0;
  if ( v2 )
  {
    this->m_QueuedSaves.m_heap.m_pElements = this->m_QueuedSaves.m_heap.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_QueuedSaves.m_heap.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_QueuedSaves.m_heap.m_Memory.m_pMemory);
      this->m_QueuedSaves.m_heap.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_QueuedSaves.m_heap.m_Memory.m_pMemory;
    this->m_QueuedSaves.m_heap.m_Memory.m_nAllocationCount = 0;
    this->m_QueuedSaves.m_heap.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149300
// Name: public: void CPhysSaveRestoreBlockHandler::RestoreBlock(class IRestore __near *,struct PhysObjectHeader_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestoreBlock(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header)
{
  const PhysObjectHeader_t *v3; // ebx
  unsigned int m_Index; // ecx
  C_BaseEntity *v6; // edi
  unsigned __int16 v7; // ax
  int v8; // esi
  int v9; // ecx
  CPhysSaveRestoreBlockHandler *v10; // esi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *Item; // eax
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *nObjects; // ecx
  void **ppPhysObj; // eax
  void **v14; // edi
  void *v15; // ebx
  void *v16; // eax
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-14h]
  CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t search; // [esp+10h] [ebp-10h] BYREF
  CPhysSaveRestoreBlockHandler *v19; // [esp+18h] [ebp-8h]
  void *inptr; // [esp+1Ch] [ebp-4h]

  v3 = header;
  m_Index = header->hEntity.m_Index;
  v19 = this;
  if ( m_Index == -1 )
  {
    v6 = nullptr;
    inptr = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    inptr = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v6 = (C_BaseEntity *)inptr;
  }
  else
  {
    inptr = nullptr;
    v6 = nullptr;
  }
  search.key = v6;
  v7 = CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_QueuedRestores.m_Tree,
         &search);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    if ( v6->ShouldSavePhysics(this: v6) && header->nObjects > 0 )
    {
      v9 = v8;
      v10 = v19;
      Item = CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(
               this: v19->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem,
               itemFieldName: header->fieldName);
      if ( Item != nullptr )
      {
        nObjects = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)header->nObjects;
        if ( (int)nObjects >= Item->header.nObjects )
          nObjects = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)Item->header.nObjects;
        if ( Item->header.type == PIID_IPHYSICSOBJECT
          && nObjects == (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)1 )
        {
          CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(
            this: v10,
            pRestore,
            header,
            pItem: Item,
            nObjects: 1);
          cacheCriticalSection->EndLock(this: cacheCriticalSection);
          return;
        }
        ppPhysObj = Item->ppPhysObj;
        if ( (int)nObjects > 0 )
        {
          v14 = ppPhysObj;
          search.elem = nObjects;
          do
          {
            pRestore->StartBlock(this: pRestore);
            CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
              this: v19,
              pRestore,
              header: v3,
              ppObject: v14,
              pCollide: nullptr);
            pRestore->EndBlock(this: pRestore);
            if ( v3->type == PIID_IPHYSICSMOTIONCONTROLLER )
            {
              v15 = *v14;
              if ( *v14 != nullptr )
              {
                v16 = __RTDynamicCast(
                        inptr,
                        VfDelta: 0,
                        SrcType: &C_BaseEntity `RTTI Type Descriptor',
                        TargetType: &IMotionEvent `RTTI Type Descriptor',
                        isReference: 0);
                if ( v16 != nullptr )
                  (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v15 + 4))(a1: v15, a2: v16);
              }
              v3 = header;
            }
            ++v14;
            --search.elem;
          }
          while ( search.elem != nullptr );
        }
      }
    }
    else
    {
      v6->CreateVPhysics(this: v6);
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101494A0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ForgetAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ForgetAllModels(CPhysSaveRestoreBlockHandler *this)
{
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_fDoLoad);
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectModels.m_Tree.m_pElements);
  CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectCustomModels.m_Tree.m_pElements);
}

//------------------------------------------------------------------------------
// Address: 0x101494C0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::Restore(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool __formal)
{
  IPhysicsObject *pWorldObject; // edx
  PhysObjectHeader_t header; // [esp+4h] [ebp-40h] BYREF
  physprerestoreparams_t params; // [esp+38h] [ebp-Ch] BYREF

  if ( this->m_fDoLoad )
  {
    if ( physenv != nullptr )
    {
      pWorldObject = this->m_blockHeader.pWorldObject;
      params.recreatedObjectList[0].pNewObject = g_PhysWorldObject;
      params.recreatedObjectList[0].pOldObject = pWorldObject;
      params.recreatedObjectCount = 1;
      physenv->PreRestore(this: physenv, a2: &params);
    }
    memset(dst: (int)&header, value: nullptr, count: sizeof(header));
    while ( this->m_blockHeader.nSaved != 0 )
    {
      --this->m_blockHeader.nSaved;
      pRestore->ReadAll(this: pRestore, a2: &header, a3: &PhysObjectHeader_t::m_DataMap);
      pRestore->StartBlock(this: pRestore);
      if ( header.hEntity.m_Index != -1
        && g_pEntityList->m_EntPtrArray[LOWORD(header.hEntity.m_Index)].m_SerialNumber == HIWORD(header.hEntity.m_Index)
        && g_pEntityList->m_EntPtrArray[LOWORD(header.hEntity.m_Index)].m_pEntity != nullptr )
      {
        CPhysSaveRestoreBlockHandler::RestoreBlock(this, pRestore, &header);
      }
      pRestore->EndBlock(this: pRestore);
    }
    --this->m_blockHeader.nSaved;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101495A0
// Name: public: void CPhysSaveRestoreBlockHandler::QueueSave(class C_BaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::QueueSave(
        CPhysSaveRestoreBlockHandler *this,
        C_BaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        PhysInterfaceId_t type)
{
  bool v5; // bl
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct IClientUnknown *); // eax
  IPhysicsObject *v7; // esi
  const char *ModelName; // ebx
  const struct CPhysCollide *(__thiscall *GetCollide)(IPhysicsObject *); // eax
  int v10; // eax
  const BBox_t *BBox; // eax
  char *Classname; // eax
  CPhysSaveRestoreBlockHandler::QueuedItem_t item; // [esp+4h] [ebp-3Ch] BYREF
  CPhysSaveRestoreBlockHandler *v14; // [esp+3Ch] [ebp-4h]
  IPhysicsCollision_vtbl *typea; // [esp+54h] [ebp+14h]

  v14 = this;
  if ( pOwner != nullptr )
  {
    v5 = !pOwner->ShouldSavePhysics(this: pOwner);
    memset(dst: (int)&item, value: nullptr, count: 0x34u);
    GetRefEHandle = pOwner->GetRefEHandle;
    item.ppPhysObj = ppPhysObj;
    item.header.hEntity.m_Index = GetRefEHandle(this: pOwner)->m_Index;
    item.header.type = type;
    if ( v5 )
      item.header.nObjects = 0;
    else
      item.header.nObjects = pTypeDesc->fieldSize;
    item.header.fieldName = AllocPooledString(pszValue: pTypeDesc->fieldName);
    memset(&item.header.modelName, 0, 32);
    if ( !v5 && type == PIID_IPHYSICSOBJECT )
    {
      v7 = (IPhysicsObject *)*ppPhysObj;
      if ( *ppPhysObj != nullptr )
      {
        ModelName = CPhysSaveRestoreBlockHandler::GetModelName(this: v14, pObject: v7);
        GetCollide = v7->GetCollide;
        typea = physcollision->__vftable;
        item.header.modelName = ModelName;
        v10 = (int)GetCollide(this: v7);
        item.header.iCollide = typea->CollideIndex(this: physcollision, a2: (const struct CPhysCollide *)v10);
        if ( ModelName == nullptr )
        {
          BBox = CPhysSaveRestoreBlockHandler::GetBBox(this: v14, pObject: v7);
          if ( BBox != nullptr )
          {
            BBox_t::operator=(this: &item.header.bbox, __that: BBox);
          }
          else if ( ((double (__thiscall *)(IPhysicsObject *))v7->GetSphereRadius)(a1: v7) == 0.0 )
          {
            Classname = C_BaseEntity::GetClassname(this: pOwner);
            DevMsg(a1: "Don't know how to save model for physics object (class \"%s\")\n", Classname);
          }
          else
          {
            item.header.sphere.radius = v7->GetSphereRadius(this: v7);
          }
        }
      }
    }
    CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(
      this: &v14->m_QueuedSaves,
      element: &item);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149710
// Name: public: virtual void CPhysObjSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::Save(
        CPhysObjSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  C_BaseEntity *m_pCurrentEntity; // esi
  CBaseHandle *v5; // eax

  m_pCurrentEntity = pSave->GetGameSaveRestoreInfo(this: pSave)->m_pCurrentEntity;
  if ( IsValidEntityPointer(ptr: m_pCurrentEntity) == 0 )
  {
    v5 = m_pCurrentEntity->GetRefEHandle(this: m_pCurrentEntity);
    m_pCurrentEntity = CClientEntityList::GetBaseEntityFromHandle(
                         this: (CClientEntityList *)cl_entitylist.m_Index,
                         hEnt: (CBaseHandle)v5->m_Index);
  }
  if ( this->m_type != PIID_UNKNOWN )
    CPhysSaveRestoreBlockHandler::QueueSave(
      this: &g_PhysSaveRestoreBlockHandler,
      pOwner: m_pCurrentEntity,
      pTypeDesc: fieldInfo->pTypeDesc,
      ppPhysObj: (void **)fieldInfo->pField,
      type: this->m_type);
}

//------------------------------------------------------------------------------
// Address: 0x10149960
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PostRestore(CPhysSaveRestoreBlockHandler *this)
{
  CPhysSaveRestoreBlockHandler *v1; // esi
  unsigned __int16 Inorder; // di
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *elem; // esi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // eax
  CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( physenv != nullptr )
    physenv->PostRestore(this: physenv);
  p_m_Tree = &v1->m_QueuedRestores.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_QueuedRestores.m_Tree);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      elem = v1->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( elem != nullptr )
      {
        elem->m_Size = 0;
        if ( elem->m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_Memory.m_pMemory);
            elem->m_Memory.m_pMemory = nullptr;
          }
          elem->m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = elem->m_Memory.m_pMemory;
        elem->m_pElements = elem->m_Memory.m_pMemory;
        if ( elem->m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            elem->m_Memory.m_pMemory = nullptr;
          }
          elem->m_Memory.m_nAllocationCount = 0;
        }
        C_BaseEntity::operator delete(pMem: elem);
      }
      Inorder = CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                  this: p_m_Tree,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v1 = this;
    }
  }
  CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10149B10
// Name: public: void CPhysSaveRestoreBlockHandler::QueueRestore(class C_BaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::QueueRestore(
        CPhysSaveRestoreBlockHandler *this,
        C_BaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        PhysInterfaceId_t type)
{
  CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short> *p_m_QueuedRestores; // edi
  unsigned __int16 v7; // ax
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *elem; // esi
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *v9; // eax
  CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_QueuedRestores = &this->m_QueuedRestores;
  search.key = pOwner;
  v7 = CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_QueuedRestores.m_Tree,
         &search);
  if ( v7 == 0xFFFF )
  {
    v9 = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)MemAlloc_Alloc(nSize: 0x14u);
    elem = nullptr;
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      elem = v9;
    }
    search.key = pOwner;
    search.elem = elem;
    CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &p_m_QueuedRestores->m_Tree,
      a2: (const char *)p_m_QueuedRestores,
      insert: &search);
  }
  else
  {
    elem = this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
  }
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(this: elem, pOwner, pTypeDesc, ppPhysObj, type);
  memset(dst: (int)ppPhysObj, value: nullptr, count: 4 * pTypeDesc->fieldSize);
}

//------------------------------------------------------------------------------
// Address: 0x10149BB0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::NoteBBox(class Vector const __near &,class Vector const __near &,class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::NoteBBox(
        CPhysSaveRestoreBlockHandler *this,
        const Vector *mins,
        const Vector *maxs,
        struct CPhysCollide *pCollide)
{
  UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short> **p_m_pElements; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t search; // [esp+4h] [ebp-1Ch] BYREF

  if ( pCollide != nullptr )
  {
    p_m_pElements = &this->m_PhysObjectCustomModels.m_Tree.m_pElements;
    search.key = pCollide;
    if ( CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectCustomModels.m_Tree.m_pElements,
           &search) == 0xFFFF )
    {
      x = mins->x;
      y = mins->y;
      z = mins->z;
      v8 = maxs->x;
      v9 = maxs->y;
      v10 = maxs->z;
      search.key = pCollide;
      search.elem.mins.x = x;
      search.elem.mins.y = y;
      search.elem.mins.z = z;
      search.elem.maxs.x = v8;
      search.elem.maxs.y = v9;
      search.elem.maxs.z = v10;
      CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)p_m_pElements,
        a2: (const char *)pCollide,
        insert: &search);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149C30
// Name: public: virtual void CPhysSaveRestoreBlockHandler::AssociateModel(class IPhysicsObject __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysSaveRestoreBlockHandler::AssociateModel(
        CPhysSaveRestoreBlockHandler *this@<ecx>,
        const char *a2@<edi>,
        IPhysicsObject *pObject,
        int modelIndex)
{
  CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t insert; // [esp+0h] [ebp-8h] BYREF

  insert.key = pObject;
  insert.elem = modelIndex;
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: (CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_fDoLoad,
    a2,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10149C60
// Name: public: virtual void CPhysSaveRestoreBlockHandler::AssociateModel(class IPhysicsObject __near *,class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysSaveRestoreBlockHandler::AssociateModel(
        CPhysSaveRestoreBlockHandler *this@<ecx>,
        const char *a2@<edi>,
        IPhysicsObject *pObject,
        const struct CPhysCollide *pModel)
{
  CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t insert; // [esp+0h] [ebp-8h] BYREF

  insert.key = pObject;
  insert.elem = pModel;
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: (CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectModels.m_Tree.m_pElements,
    a2,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10149C90
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ForgetModel(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ForgetModel(CPhysSaveRestoreBlockHandler *this, IPhysicsObject *pObject)
{
  if ( CUtlMap<IPhysicsObject *,int,unsigned short>::Remove(
         this: (CUtlMap<IPhysicsObject *,int,unsigned short> *)&this->m_fDoLoad,
         key: &pObject) == 0 )
    CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Remove(
      this: (CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short> *)&this->m_PhysObjectModels.m_Tree.m_pElements,
      key: &pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10149CC0
// Name: public: virtual void CPhysObjSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::Restore(
        CPhysObjSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  C_BaseEntity *m_pCurrentEntity; // esi
  CBaseHandle *v5; // eax

  m_pCurrentEntity = pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity;
  if ( IsValidEntityPointer(ptr: m_pCurrentEntity) == 0 )
  {
    v5 = m_pCurrentEntity->GetRefEHandle(this: m_pCurrentEntity);
    m_pCurrentEntity = CClientEntityList::GetBaseEntityFromHandle(
                         this: (CClientEntityList *)cl_entitylist.m_Index,
                         hEnt: (CBaseHandle)v5->m_Index);
  }
  if ( this->m_type != PIID_UNKNOWN )
    CPhysSaveRestoreBlockHandler::QueueRestore(
      this: &g_PhysSaveRestoreBlockHandler,
      pOwner: m_pCurrentEntity,
      pTypeDesc: fieldInfo->pTypeDesc,
      ppPhysObj: (void **)fieldInfo->pField,
      type: this->m_type);
}

//------------------------------------------------------------------------------
// Address: 0x1016D010
// Name: public: virtual void CPhysObjSaveRestoreOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::MakeEmpty(
        CPhysObjSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  memset(dst: (int)fieldInfo->pField, value: nullptr, count: 4 * fieldInfo->pTypeDesc->fieldSize);
}

//------------------------------------------------------------------------------
// Address: 0x101B4300
// Name: public: void CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
        CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPhysSaveRestoreBlockHandler::QueuedItem_t *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CPhysSaveRestoreBlockHandler::QueuedItem_t *)_g_pMemAlloc->Alloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041B5B0
// Name: PhysBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *PhysBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<PhysBlockHeader_t>();
  PhysBlockHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B5C0
// Name: PhysObjectHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *PhysObjectHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<PhysObjectHeader_t>();
  PhysObjectHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B5D0
// Name: _dynamic_initializer_for__g_PhysSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysSaveRestoreBlockHandler__()
{
  CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(this: &g_PhysSaveRestoreBlockHandler);
  return atexit(func: dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5F0
// Name: _dynamic_initializer_for__g_PhysObjSaveRestoreOps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysObjSaveRestoreOps *dynamic_initializer_for__g_PhysObjSaveRestoreOps__()
{
  CPhysObjSaveRestoreOps *result; // eax
  int i; // ecx

  result = g_PhysObjSaveRestoreOps;
  for ( i = 10; i >= 0; --i )
  {
    result->__vftable = (CPhysObjSaveRestoreOps_vtbl *)&CPhysObjSaveRestoreOps::`vftable';
    ++result;
  }
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10098CC0
// Name: public: virtual void CPhysObjSaveRestoreOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::MakeEmpty(
        CClassPtrSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  memset(dst: (int)fieldInfo->pField, value: nullptr, count: 4 * fieldInfo->pTypeDesc->fieldSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A4F40
// Name: class ISaveRestoreBlockHandler __near * GetPhysSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler *__cdecl GetPhysSaveRestoreBlockHandler()
{
  return &g_PhysSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x101A4F50
// Name: class ISaveRestoreOps __near * GetPhysObjSaveRestoreOps(enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
CPhysObjSaveRestoreOps *__cdecl GetPhysObjSaveRestoreOps(PhysInterfaceId_t type)
{
  PhysInterfaceId_t i; // eax

  if ( !inited )
  {
    inited = true;
    for ( i = PIID_UNKNOWN; i < PIID_NUM_TYPES; ++i )
      g_PhysObjSaveRestoreOps[i].m_type = i;
  }
  return &g_PhysObjSaveRestoreOps[type];
}

//------------------------------------------------------------------------------
// Address: 0x101A4F80
// Name: private: static bool CPhysSaveRestoreBlockHandler::SaveQueueFunc(struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &,struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CPhysSaveRestoreBlockHandler::SaveQueueFunc(
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *left,
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *right)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v4; // eax
  signed int v5; // edi
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  IHandleEntity_vtbl *v8; // eax

  if ( left->header.type != right->header.type )
    return left->header.type > right->header.type;
  m_Index = left->header.hEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = m_pEntity[6].__vftable;
  if ( v4 != nullptr )
    v5 = ((char *)v4 - (char *)gpGlobals->pEdicts) >> 4;
  else
    v5 = 0;
  v6 = right->header.hEntity.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  v8 = v7[6].__vftable;
  if ( v8 != nullptr )
    return v5 > ((char *)v8 - (char *)gpGlobals->pEdicts) >> 4;
  else
    return v5 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5030
// Name: public: struct BBox_t __near & BBox_t::operator=(struct BBox_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BBox_t *__thiscall BBox_t::operator=(BBox_t *this, const BBox_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A50C0
// Name: public: void CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>::Grow(
        CUtlMemory<CAI_BlendedMotor::AI_Movementscript_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CAI_BlendedMotor::AI_Movementscript_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CAI_BlendedMotor::AI_Movementscript_t *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: m_pMemory,
                                                                   a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CAI_BlendedMotor::AI_Movementscript_t *)_g_pMemAlloc->Alloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6970
// Name: public: struct string_t CPhysSaveRestoreBlockHandler::GetModelName(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CPhysSaveRestoreBlockHandler::GetModelName(
        CPhysSaveRestoreBlockHandler *this,
        IPhysicsObject *pObject,
        IPhysicsObject *pObjecta)
{
  unsigned __int16 v4; // ax
  int v6; // edx
  UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  IVModelInfo_vtbl *v8; // esi
  const struct model_t *v9; // eax
  CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = pObjecta;
  v4 = CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysObjectModels.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
  {
    pObject->__vftable = nullptr;
    return (string_t)pObject;
  }
  else
  {
    v6 = v4;
    m_pMemory = this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory;
    v8 = modelinfo->__vftable;
    v9 = modelinfo->GetModel(this: modelinfo, a2: m_pMemory[v6].m_Data.elem);
    v8->GetModelName(this: modelinfo, a2: v9);
    AllocPooledString(pszValue: (const char *)pObject);
    return (string_t)pObject;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A69F0
// Name: public: struct BBox_t __near * CPhysSaveRestoreBlockHandler::GetBBox(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
BBox_t *__thiscall CPhysSaveRestoreBlockHandler::GetBBox(CPhysSaveRestoreBlockHandler *this, IPhysicsObject *pObject)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v5; // ax
  CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t v6; // [esp+4h] [ebp-24h] BYREF
  CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t search; // [esp+20h] [ebp-8h] BYREF

  search.key = pObject;
  v3 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysObjectCustomModels.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  v6.key = this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  v5 = CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_PhysCollideBBoxModels.m_Tree,
         search: &v6);
  if ( v5 == 0xFFFF )
    return nullptr;
  else
    return &this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101A6A60
// Name: public: int CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(class CBaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(
        CPhysSaveRestoreBlockHandler::CEntityRestoreSet *this,
        CBaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        PhysInterfaceId_t type)
{
  int v6; // edi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v7; // esi

  v6 = CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
         this,
         elem: this->m_Size);
  v7 = &this->m_Memory.m_pMemory[v6];
  v7->ppPhysObj = ppPhysObj;
  if ( pOwner != nullptr )
    v7->header.hEntity.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    v7->header.hEntity.m_Index = -1;
  v7->header.type = type;
  v7->header.nObjects = pTypeDesc->fieldSize;
  v7->header.fieldName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&ppPhysObj).pszValue;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101A6C40
// Name: public: CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler *__thiscall CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(
        CPhysSaveRestoreBlockHandler *this)
{
  CPhysSaveRestoreBlockHandler *result; // eax

  result = this;
  this->IPhysSaveRestoreManager::__vftable = (IPhysSaveRestoreManager_vtbl *)&IPhysSaveRestoreManager::`vftable';
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&IEntityListener::`vftable';
  this->CDefSaveRestoreBlockHandler::ISaveRestoreBlockHandler::__vftable = (CPhysSaveRestoreBlockHandler_vtbl *)&CPhysSaveRestoreBlockHandler::`vftable'{for `CDefSaveRestoreBlockHandler'};
  this->IPhysSaveRestoreManager::__vftable = (IPhysSaveRestoreManager_vtbl *)&CPhysSaveRestoreBlockHandler::`vftable'{for `IPhysSaveRestoreManager'};
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&CPhysSaveRestoreBlockHandler::`vftable'{for `IEntityListener'};
  this->m_QueuedSaves.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_QueuedSaves.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedSaves.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_QueuedSaves.m_heap.m_Size = 0;
  this->m_QueuedSaves.m_heap.m_pElements = nullptr;
  this->m_QueuedSaves.m_LessFunc = nullptr;
  this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_QueuedRestores.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_QueuedRestores.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_QueuedRestores.m_Tree.m_Root = -1;
  this->m_QueuedRestores.m_Tree.m_NumElements = 0;
  this->m_QueuedRestores.m_Tree.m_FirstFree = -1;
  this->m_QueuedRestores.m_Tree.m_LastAlloc.index = -1;
  this->m_QueuedRestores.m_Tree.m_pElements = this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory;
  this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysObjectModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysObjectModels.m_Tree.m_Root = -1;
  this->m_PhysObjectModels.m_Tree.m_NumElements = 0;
  this->m_PhysObjectModels.m_Tree.m_FirstFree = -1;
  this->m_PhysObjectModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysObjectModels.m_Tree.m_pElements = this->m_PhysObjectModels.m_Tree.m_Elements.m_pMemory;
  this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_Root = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_NumElements = 0;
  this->m_PhysObjectCustomModels.m_Tree.m_FirstFree = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysObjectCustomModels.m_Tree.m_pElements = this->m_PhysObjectCustomModels.m_Tree.m_Elements.m_pMemory;
  this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_Root = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_NumElements = 0;
  this->m_PhysCollideBBoxModels.m_Tree.m_FirstFree = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_LastAlloc.index = -1;
  this->m_PhysCollideBBoxModels.m_Tree.m_pElements = this->m_PhysCollideBBoxModels.m_Tree.m_Elements.m_pMemory;
  this->m_QueuedSaves.m_LessFunc = CPhysSaveRestoreBlockHandler::SaveQueueFunc;
  if ( this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_QueuedRestores.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
  if ( this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysObjectModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(IPhysicsObject *const *, IPhysicsObject *const *))CDefOps<CChoreoActor *>::LessFunc;
  if ( this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysObjectCustomModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(IPhysicsObject *const *, IPhysicsObject *const *))CDefOps<CChoreoActor *>::LessFunc;
  if ( this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PhysCollideBBoxModels.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CPhysCollide *const *, const CPhysCollide *const *))CDefOps<CChoreoActor *>::LessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6D80
// Name: public: virtual char const __near * CPhysSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysSaveRestoreBlockHandler::GetBlockName(CPhysSaveRestoreBlockHandler *this)
{
  return "Physics";
}

//------------------------------------------------------------------------------
// Address: 0x101A6D90
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PreSave(CPhysSaveRestoreBlockHandler *this, CSaveRestoreData *__formal)
{
  this->m_blockHeader.nSaved = 0;
  this->m_blockHeader.pWorldObject = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A6DB0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PreRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PreRestore(CPhysSaveRestoreBlockHandler *this)
{
  IEntityListener *v1; // eax
  physprerestoreparams_t params; // [esp+0h] [ebp-Ch] BYREF

  if ( this != nullptr )
    v1 = &this->IEntityListener;
  else
    v1 = nullptr;
  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: v1);
  if ( physenv != nullptr )
  {
    params.recreatedObjectCount = 0;
    physenv->PreRestore(this: physenv, a2: &params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6DF0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::WriteSaveHeaders(CPhysSaveRestoreBlockHandler *this, ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &PHYS_SAVE_RESTORE_VERSION, a3: 1);
  pSave->WriteAll(this: pSave, a2: &this->m_blockHeader, a3: &PhysBlockHeader_t::m_DataMap);
}

//------------------------------------------------------------------------------
// Address: 0x101A6E30
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ReadRestoreHeaders(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  this->m_fDoLoad = pRestore->ReadShort_2(this: pRestore) == PHYS_SAVE_RESTORE_VERSION;
  pRestore->ReadAll(this: pRestore, a2: &this->m_blockHeader, a3: &PhysBlockHeader_t::m_DataMap);
}

//------------------------------------------------------------------------------
// Address: 0x101A6E70
// Name: public: void CPhysSaveRestoreBlockHandler::RestorePhysicsObject(class IRestore __near *,struct PhysObjectHeader_t const __near &,void __near * __near *,class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header,
        void **ppObject,
        const struct CPhysCollide *pCollide)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax
  physrestoreparams_t params; // [esp+0h] [ebp-20h] BYREF

  if ( physenv != nullptr )
  {
    params.ppObject = ppObject;
    m_Index = header->hEntity.m_Index;
    params.pRestore = pRestore;
    params.type = header->type;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    params.pGameData = m_pEntity;
    params.pName = header->modelName.pszValue;
    if ( params.pName == nullptr )
      params.pName = locale;
    params.pCollisionModel = pCollide;
    params.pGameTrace = physgametrace;
    params.pEnvironment = physenv;
    ((void (__stdcall *)(physrestoreparams_t *))physenv->Restore)(a1: &params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A70F0
// Name: public: void CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(class IRestore __near *,struct PhysObjectHeader_t const __near &,struct CPhysSaveRestoreBlockHandler::QueuedItem_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header,
        CPhysSaveRestoreBlockHandler::QueuedItem_t *pItem,
        int nObjects)
{
  const char *pszValue; // edx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v9; // eax
  vcollide_t *v10; // eax
  __int16 v11; // cx
  struct CPhysCollide **solids; // eax
  int iCollide; // edx
  const struct CPhysCollide *Bbox; // edi
  void **v15; // eax
  void **ppPhysObj; // eax
  void **v17; // eax
  IPhysicsObject *v18; // eax
  IPhysSaveRestoreManager_vtbl *v19; // edx
  IPhysSaveRestoreManager *v20; // ecx
  int modelIndex; // [esp+Ch] [ebp-4h]

  if ( nObjects == 1 )
  {
    pRestore->StartBlock(this: pRestore);
    pszValue = header->modelName.pszValue;
    modelIndex = -1;
    if ( pszValue != nullptr )
    {
      m_Index = header->hEntity.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity[127].__vftable != nullptr )
        v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[2].dtr_IHandleEntity)(a1: m_pEntity);
      else
        v9 = modelinfo->GetModelIndex(this: modelinfo, a2: pszValue);
      modelIndex = v9;
      if ( v9 == -1 )
        goto LABEL_36;
      v10 = modelinfo->GetVCollide(this: modelinfo, a2: v9);
      if ( v10 == nullptr )
        goto LABEL_36;
      v11 = *(_WORD *)v10;
      if ( (*(_WORD *)v10 & 0x7FFF) == 0 )
        goto LABEL_36;
      solids = v10->solids;
      if ( solids == nullptr )
        goto LABEL_36;
      iCollide = header->iCollide;
      if ( iCollide >= (v11 & 0x7FFF) )
        goto LABEL_36;
      Bbox = solids[iCollide];
      goto LABEL_27;
    }
    if ( vec3_origin.x != header->bbox.mins.x
      || vec3_origin.y != header->bbox.mins.y
      || vec3_origin.z != header->bbox.mins.z
      || vec3_origin.x != header->bbox.maxs.x
      || vec3_origin.y != header->bbox.maxs.y
      || vec3_origin.z != header->bbox.maxs.z )
    {
      Bbox = PhysCreateBbox(minsIn: &header->bbox.mins, maxsIn: &header->bbox.maxs);
      HIBYTE(nObjects) = 1;
LABEL_27:
      if ( Bbox != nullptr )
      {
        ppPhysObj = pItem->ppPhysObj;
        if ( *ppPhysObj != nullptr )
        {
          DevMsg(
            a1: "Physics object pointer unexpectedly non-null before restore. Should be creating physics object in CreatePhysics()?\n");
        }
        else
        {
          CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
            this,
            pRestore,
            header,
            ppObject: ppPhysObj,
            pCollide: Bbox);
          v17 = pItem->ppPhysObj;
          if ( *v17 != nullptr )
          {
            v18 = (IPhysicsObject *)*v17;
            v19 = this->IPhysSaveRestoreManager::__vftable;
            v20 = &this->IPhysSaveRestoreManager;
            if ( HIBYTE(nObjects) != 0 )
              v19->AssociateModel(this: v20, a2: v18, a3: Bbox);
            else
              v19->AssociateModel_2(this: v20, a2: v18, a3: modelIndex);
          }
          else
          {
            DevMsg(a1: "Failed to restore physics object\n");
          }
        }
        goto LABEL_32;
      }
LABEL_36:
      DevMsg(a1: "Failed to reestablish collision model for object\n");
LABEL_32:
      pRestore->EndBlock(this: pRestore);
      return;
    }
    if ( header->sphere.radius == 0.0 )
      goto LABEL_36;
    v15 = pItem->ppPhysObj;
    if ( *v15 == nullptr )
      CPhysSaveRestoreBlockHandler::RestorePhysicsObject(this, pRestore, header, ppObject: v15, pCollide: nullptr);
  }
  else
  {
    DevMsg(a1: "Don't know how to reconsitite models for physobj array \n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7330
// Name: public: struct CPhysSaveRestoreBlockHandler::QueuedItem_t __near * CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(struct string_t)
// Source: json
//------------------------------------------------------------------------------
CPhysSaveRestoreBlockHandler::QueuedItem_t *__thiscall CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(
        CPhysSaveRestoreBlockHandler::CEntityRestoreSet *this,
        string_t itemFieldName)
{
  int m_Size; // edx
  int v3; // eax
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // edi
  string_t *i; // ecx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = &this->m_Memory.m_pMemory->header.fieldName; i->pszValue != itemFieldName.pszValue; i += 14 )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return &m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x101ABC20
// Name: public: virtual void CPhysSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::Save(CPhysSaveRestoreBlockHandler *this, ISave *pSave)
{
  CPhysSaveRestoreBlockHandler *v2; // ebx
  int m_Size; // eax
  CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *p_m_QueuedSaves; // edi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // edi
  unsigned int m_Index; // eax
  int nObjects; // eax
  int v8; // ebx
  PhysInterfaceId_t type; // edx
  _DWORD v10[3]; // [esp+4h] [ebp-10h] BYREF
  CPhysSaveRestoreBlockHandler *v11; // [esp+10h] [ebp-4h]

  v2 = this;
  this->m_blockHeader.pWorldObject = g_PhysWorldObject;
  m_Size = this->m_QueuedSaves.m_heap.m_Size;
  v11 = this;
  this->m_blockHeader.nSaved = m_Size;
  if ( m_Size != 0 )
  {
    p_m_QueuedSaves = &this->m_QueuedSaves;
    do
    {
      m_pMemory = p_m_QueuedSaves->m_heap.m_Memory.m_pMemory;
      m_Index = m_pMemory->header.hEntity.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        pSave->WriteAll(this: pSave, a2: m_pMemory, a3: &PhysObjectHeader_t::m_DataMap);
        pSave->StartBlock(this: pSave);
        nObjects = m_pMemory->header.nObjects;
        if ( nObjects != 0 )
        {
          v8 = 0;
          if ( nObjects > 0 )
          {
            do
            {
              pSave->StartBlock(this: pSave);
              if ( physenv != nullptr && m_pMemory->ppPhysObj[v8] != nullptr )
              {
                type = m_pMemory->header.type;
                v10[1] = m_pMemory->ppPhysObj[v8];
                v10[2] = type;
                v10[0] = pSave;
                ((void (__stdcall *)(_DWORD *))physenv->Save)(a1: v10);
              }
              pSave->EndBlock(this: pSave);
              ++v8;
            }
            while ( v8 < m_pMemory->header.nObjects );
          }
          v2 = v11;
        }
        pSave->EndBlock(this: pSave);
      }
      p_m_QueuedSaves = &v2->m_QueuedSaves;
      CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(this: &v2->m_QueuedSaves);
    }
    while ( v2->m_QueuedSaves.m_heap.m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ABD20
// Name: public: void CPhysSaveRestoreBlockHandler::RestoreBlock(class IRestore __near *,struct PhysObjectHeader_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::RestoreBlock(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        const PhysObjectHeader_t *header)
{
  const PhysObjectHeader_t *v3; // ebx
  unsigned int m_Index; // eax
  CBaseEntity *v5; // edi
  unsigned __int16 v6; // ax
  int v7; // esi
  int v8; // ecx
  CPhysSaveRestoreBlockHandler *v9; // esi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *Item; // eax
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *nObjects; // ecx
  void **ppPhysObj; // eax
  void **v13; // edi
  void *v14; // ebx
  void *v15; // eax
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-14h]
  CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t search; // [esp+10h] [ebp-10h] BYREF
  CPhysSaveRestoreBlockHandler *v18; // [esp+18h] [ebp-8h]
  void *inptr; // [esp+1Ch] [ebp-4h]

  v3 = header;
  m_Index = header->hEntity.m_Index;
  v18 = this;
  if ( m_Index == -1 )
  {
    v5 = nullptr;
    inptr = nullptr;
  }
  else if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    inptr = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v5 = (CBaseEntity *)inptr;
  }
  else
  {
    inptr = nullptr;
    v5 = nullptr;
  }
  search.key = v5;
  v6 = CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_QueuedRestores.m_Tree,
         &search);
  v7 = v6;
  if ( v6 != 0xFFFF )
  {
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    if ( v5->ShouldSavePhysics(this: v5) && header->nObjects > 0 )
    {
      v8 = v7;
      v9 = v18;
      Item = CPhysSaveRestoreBlockHandler::CEntityRestoreSet::FindItem(
               this: v18->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem,
               itemFieldName: header->fieldName);
      if ( Item != nullptr )
      {
        nObjects = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)header->nObjects;
        if ( (int)nObjects >= Item->header.nObjects )
          nObjects = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)Item->header.nObjects;
        if ( Item->header.type == PIID_IPHYSICSOBJECT
          && nObjects == (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)1 )
        {
          CPhysSaveRestoreBlockHandler::RestorePhysicsObjectAndModel(
            this: v9,
            pRestore,
            header,
            pItem: Item,
            nObjects: 1);
          cacheCriticalSection->EndLock(this: cacheCriticalSection);
          return;
        }
        ppPhysObj = Item->ppPhysObj;
        if ( (int)nObjects > 0 )
        {
          v13 = ppPhysObj;
          search.elem = nObjects;
          do
          {
            pRestore->StartBlock(this: pRestore);
            CPhysSaveRestoreBlockHandler::RestorePhysicsObject(
              this: v18,
              pRestore,
              header: v3,
              ppObject: v13,
              pCollide: nullptr);
            pRestore->EndBlock(this: pRestore);
            if ( v3->type == PIID_IPHYSICSMOTIONCONTROLLER )
            {
              v14 = *v13;
              if ( *v13 != nullptr )
              {
                v15 = __RTDynamicCast(
                        inptr,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &IMotionEvent `RTTI Type Descriptor',
                        isReference: 0);
                if ( v15 != nullptr )
                  (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v14 + 4))(a1: v14, a2: v15);
              }
              v3 = header;
            }
            ++v13;
            --search.elem;
          }
          while ( search.elem != nullptr );
        }
      }
    }
    else
    {
      v5->CreateVPhysics(this: v5);
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ABEC0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ForgetAllModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ForgetAllModels(CPhysSaveRestoreBlockHandler *this)
{
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_fDoLoad);
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectModels.m_Tree.m_pElements);
  CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectCustomModels.m_Tree.m_pElements);
}

//------------------------------------------------------------------------------
// Address: 0x101ABEE0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::Restore(
        CPhysSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool __formal)
{
  IPhysicsObject *pWorldObject; // edx
  PhysObjectHeader_t header; // [esp+4h] [ebp-40h] BYREF
  physprerestoreparams_t params; // [esp+38h] [ebp-Ch] BYREF

  if ( this->m_fDoLoad )
  {
    if ( physenv != nullptr )
    {
      pWorldObject = this->m_blockHeader.pWorldObject;
      params.recreatedObjectList[0].pNewObject = g_PhysWorldObject;
      params.recreatedObjectList[0].pOldObject = pWorldObject;
      params.recreatedObjectCount = 1;
      physenv->PreRestore(this: physenv, a2: &params);
    }
    memset(dst: (int)&header, value: nullptr, count: sizeof(header));
    while ( this->m_blockHeader.nSaved != 0 )
    {
      --this->m_blockHeader.nSaved;
      pRestore->ReadAll(this: pRestore, a2: &header, a3: &PhysObjectHeader_t::m_DataMap);
      pRestore->StartBlock(this: pRestore);
      if ( header.hEntity.m_Index != -1
        && g_pEntityList->m_EntPtrArray[LOWORD(header.hEntity.m_Index)].m_SerialNumber == HIWORD(header.hEntity.m_Index)
        && g_pEntityList->m_EntPtrArray[LOWORD(header.hEntity.m_Index)].m_pEntity != nullptr )
      {
        CPhysSaveRestoreBlockHandler::RestoreBlock(this, pRestore, &header);
      }
      pRestore->EndBlock(this: pRestore);
    }
    --this->m_blockHeader.nSaved;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ABFC0
// Name: public: void CPhysSaveRestoreBlockHandler::QueueSave(class CBaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::QueueSave(
        CPhysSaveRestoreBlockHandler *this,
        CBaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        IPhysicsCollision_vtbl *type)
{
  CBaseEntity *v5; // edi
  bool v6; // bl
  IPhysicsObject **v7; // esi
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  IPhysicsObject *v9; // esi
  const char *v10; // ebx
  const struct CPhysCollide *(__thiscall *GetCollide)(IPhysicsObject *); // eax
  int v12; // eax
  const BBox_t *BBox; // eax
  const char *pszValue; // edi
  CPhysSaveRestoreBlockHandler::QueuedItem_t item; // [esp+4h] [ebp-3Ch] BYREF
  CPhysSaveRestoreBlockHandler *v16; // [esp+3Ch] [ebp-4h]

  v5 = pOwner;
  v16 = this;
  if ( pOwner != nullptr )
  {
    v6 = !pOwner->ShouldSavePhysics(this: pOwner);
    memset(dst: (int)&item, value: nullptr, count: 0x34u);
    v7 = (IPhysicsObject **)ppPhysObj;
    GetRefEHandle = v5->GetRefEHandle;
    item.ppPhysObj = ppPhysObj;
    item.header.hEntity.m_Index = GetRefEHandle(this: v5)->m_Index;
    item.header.type = (PhysInterfaceId_t)type;
    if ( v6 )
      item.header.nObjects = 0;
    else
      item.header.nObjects = pTypeDesc->fieldSize;
    item.header.fieldName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&pOwner).pszValue;
    memset(&item.header.modelName, 0, 32);
    if ( !v6 && type == (IPhysicsCollision_vtbl *)1 )
    {
      v9 = *v7;
      if ( v9 != nullptr )
      {
        v10 = *(const char **)CPhysSaveRestoreBlockHandler::GetModelName(
                                this: v16,
                                pObject: (IPhysicsObject *)&type,
                                pObjecta: v9).pszValue;
        GetCollide = v9->GetCollide;
        type = physcollision->__vftable;
        item.header.modelName.pszValue = v10;
        v12 = (int)GetCollide(this: v9);
        item.header.iCollide = type->CollideIndex(this: physcollision, a2: (const struct CPhysCollide *)v12);
        if ( v10 == nullptr )
        {
          BBox = CPhysSaveRestoreBlockHandler::GetBBox(this: v16, pObject: v9);
          if ( BBox != nullptr )
          {
            BBox_t::operator=(this: &item.header.bbox, __that: BBox);
          }
          else if ( ((double (__thiscall *)(IPhysicsObject *))v9->GetSphereRadius)(a1: v9) == 0.0 )
          {
            pszValue = v5->m_iClassname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            DevMsg(a1: "Don't know how to save model for physics object (class \"%s\")\n", pszValue);
          }
          else
          {
            item.header.sphere.radius = v9->GetSphereRadius(this: v9);
          }
        }
      }
    }
    CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(
      this: &v16->m_QueuedSaves,
      element: &item);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AC130
// Name: public: virtual void CPhysObjSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::Save(
        CPhysObjSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CBaseEntity *m_pCurrentEntity; // esi

  m_pCurrentEntity = pSave->GetGameSaveRestoreInfo(this: pSave)->m_pCurrentEntity;
  CGlobalEntityList::IsEntityPtr(this: &gEntList, pTest: m_pCurrentEntity);
  if ( this->m_type != PIID_UNKNOWN )
    CPhysSaveRestoreBlockHandler::QueueSave(
      this: &g_PhysSaveRestoreBlockHandler,
      pOwner: m_pCurrentEntity,
      pTypeDesc: fieldInfo->pTypeDesc,
      ppPhysObj: (void **)fieldInfo->pField,
      type: (IPhysicsCollision_vtbl *)this->m_type);
}

//------------------------------------------------------------------------------
// Address: 0x101AC2F0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::PostRestore(CPhysSaveRestoreBlockHandler *this)
{
  CPhysSaveRestoreBlockHandler *v1; // esi
  unsigned __int16 i; // di
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *elem; // esi
  CPhysSaveRestoreBlockHandler::QueuedItem_t *m_pMemory; // eax

  v1 = this;
  if ( physenv != nullptr )
    physenv->PostRestore(this: physenv);
  for ( i = CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_QueuedRestores.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_QueuedRestores.m_Tree,
              i) )
  {
    elem = v1->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
    {
      elem->m_Size = 0;
      if ( elem->m_Memory.m_nGrowSize >= 0 )
      {
        if ( elem->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_Memory.m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elem->m_Memory.m_pMemory;
      elem->m_pElements = elem->m_Memory.m_pMemory;
      if ( elem->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: elem);
    }
    v1 = this;
  }
  CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_QueuedRestores.m_Tree);
  if ( v1 != nullptr )
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: &v1->IEntityListener);
  else
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101AC3E0
// Name: public: void CPhysSaveRestoreBlockHandler::QueueRestore(class CBaseEntity __near *,struct typedescription_t __near *,void __near * __near *,enum PhysInterfaceId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::QueueRestore(
        CPhysSaveRestoreBlockHandler *this,
        CBaseEntity *pOwner,
        typedescription_t *pTypeDesc,
        void **ppPhysObj,
        PhysInterfaceId_t type)
{
  CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short> *p_m_QueuedRestores; // edi
  unsigned __int16 v7; // ax
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *elem; // esi
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet *v9; // eax
  CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_QueuedRestores = &this->m_QueuedRestores;
  search.key = pOwner;
  v7 = CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_QueuedRestores.m_Tree,
         &search);
  if ( v7 == 0xFFFF )
  {
    v9 = (CPhysSaveRestoreBlockHandler::CEntityRestoreSet *)operator new(nSize: 0x14u);
    elem = nullptr;
    if ( v9 != nullptr )
    {
      v9->m_Memory.m_pMemory = nullptr;
      v9->m_Memory.m_nAllocationCount = 0;
      v9->m_Memory.m_nGrowSize = 0;
      v9->m_Size = 0;
      v9->m_pElements = nullptr;
      elem = v9;
    }
    search.key = pOwner;
    search.elem = elem;
    CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &p_m_QueuedRestores->m_Tree,
      insert: &search);
  }
  else
  {
    elem = this->m_QueuedRestores.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
  }
  CPhysSaveRestoreBlockHandler::CEntityRestoreSet::Add(this: elem, pOwner, pTypeDesc, ppPhysObj, type);
  memset(dst: (int)ppPhysObj, value: nullptr, count: 4 * pTypeDesc->fieldSize);
}

//------------------------------------------------------------------------------
// Address: 0x101AC480
// Name: public: virtual void CPhysSaveRestoreBlockHandler::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::OnEntityDeleted(CPhysSaveRestoreBlockHandler *this, CBaseEntity *pEntity)
{
  CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_pElements; // esi
  unsigned __int16 v3; // ax
  int v4; // ebx
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *v5; // ecx
  CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  CPhysSaveRestoreBlockHandler *v7; // [esp+10h] [ebp-4h]
  CBaseEntity *pEntitya; // [esp+1Ch] [ebp+8h]

  v7 = this;
  p_m_pElements = (CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_QueuedSaves.m_heap.m_pElements;
  search.key = pEntity;
  v3 = CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_QueuedSaves.m_heap.m_pElements,
         &search);
  v4 = v3;
  if ( v3 != 0xFFFF )
  {
    v5 = *((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > **)v7->m_QueuedSaves.m_LessFunc
         + 4 * v3
         + 3);
    pEntitya = (CBaseEntity *)v5;
    if ( v5 != nullptr )
    {
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: v5);
      free(pMem: pEntitya);
    }
    CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_pElements,
      elem: v4);
    p_m_pElements->m_Elements.m_pMemory[v4].m_Left = v4;
    p_m_pElements->m_Elements.m_pMemory[v4].m_Right = p_m_pElements->m_FirstFree;
    --p_m_pElements->m_NumElements;
    p_m_pElements->m_FirstFree = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AC510
// Name: public: virtual void CPhysObjSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysObjSaveRestoreOps::Restore(
        CPhysObjSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CBaseEntity *m_pCurrentEntity; // esi

  m_pCurrentEntity = pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity;
  CGlobalEntityList::IsEntityPtr(this: &gEntList, pTest: m_pCurrentEntity);
  if ( this->m_type != PIID_UNKNOWN )
    CPhysSaveRestoreBlockHandler::QueueRestore(
      this: &g_PhysSaveRestoreBlockHandler,
      pOwner: m_pCurrentEntity,
      pTypeDesc: fieldInfo->pTypeDesc,
      ppPhysObj: (void **)fieldInfo->pField,
      type: this->m_type);
}

//------------------------------------------------------------------------------
// Address: 0x101AC640
// Name: public: virtual void CPhysSaveRestoreBlockHandler::NoteBBox(class Vector const __near &,class Vector const __near &,class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::NoteBBox(
        CPhysSaveRestoreBlockHandler *this,
        const Vector *mins,
        const Vector *maxs,
        struct CPhysCollide *pCollide)
{
  UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short> **p_m_pElements; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t search; // [esp+4h] [ebp-1Ch] BYREF

  if ( pCollide != nullptr )
  {
    p_m_pElements = &this->m_PhysObjectCustomModels.m_Tree.m_pElements;
    search.key = pCollide;
    if ( CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectCustomModels.m_Tree.m_pElements,
           &search) == 0xFFFF )
    {
      x = mins->x;
      y = mins->y;
      z = mins->z;
      v8 = maxs->x;
      v9 = maxs->y;
      v10 = maxs->z;
      search.key = pCollide;
      search.elem.mins.x = x;
      search.elem.mins.y = y;
      search.elem.mins.z = z;
      search.elem.maxs.x = v8;
      search.elem.maxs.y = v9;
      search.elem.maxs.z = v10;
      CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: (CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)p_m_pElements,
        a2: (const char *)pCollide,
        insert: &search);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AC6C0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::AssociateModel(class IPhysicsObject __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::AssociateModel(
        CPhysSaveRestoreBlockHandler *this,
        IPhysicsObject *pObject,
        int modelIndex)
{
  CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t insert; // [esp+0h] [ebp-8h] BYREF

  insert.key = pObject;
  insert.elem = modelIndex;
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: (CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_fDoLoad,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101AC6F0
// Name: public: virtual void CPhysSaveRestoreBlockHandler::AssociateModel(class IPhysicsObject __near *,class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::AssociateModel(
        CPhysSaveRestoreBlockHandler *this,
        IPhysicsObject *pObject,
        const struct CPhysCollide *pModel)
{
  CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t insert; // [esp+0h] [ebp-8h] BYREF

  insert.key = pObject;
  insert.elem = pModel;
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: (CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_PhysObjectModels.m_Tree.m_pElements,
    &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101AC720
// Name: public: virtual void CPhysSaveRestoreBlockHandler::ForgetModel(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSaveRestoreBlockHandler::ForgetModel(CPhysSaveRestoreBlockHandler *this, IPhysicsObject *pObject)
{
  if ( CUtlMap<IPhysicsObject *,int,unsigned short>::Remove(
         this: (CUtlMap<IPhysicsObject *,int,unsigned short> *)&this->m_fDoLoad,
         key: &pObject) == 0 )
    CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Remove(
      this: (CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short> *)&this->m_PhysObjectModels.m_Tree.m_pElements,
      key: &pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10407820
// Name: PhysBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *PhysBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<PhysBlockHeader_t>();
  PhysBlockHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407830
// Name: PhysObjectHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *PhysObjectHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<PhysObjectHeader_t>();
  PhysObjectHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407840
// Name: _dynamic_initializer_for__g_PhysSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysSaveRestoreBlockHandler__()
{
  CPhysSaveRestoreBlockHandler::CPhysSaveRestoreBlockHandler(this: &g_PhysSaveRestoreBlockHandler);
  return atexit(func: dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__);
}

//------------------------------------------------------------------------------
// Address: 0x10407860
// Name: _dynamic_initializer_for__g_PhysObjSaveRestoreOps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysObjSaveRestoreOps *dynamic_initializer_for__g_PhysObjSaveRestoreOps__()
{
  CPhysObjSaveRestoreOps *result; // eax
  int i; // ecx

  result = g_PhysObjSaveRestoreOps;
  for ( i = 10; i >= 0; --i )
  {
    result->__vftable = (CPhysObjSaveRestoreOps_vtbl *)&CPhysObjSaveRestoreOps::`vftable';
    ++result;
  }
  return result;
}

} // namespace server
