// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cbase.cpp
// Functions: 56
// ============================================================

#include "game\server\cbase.h"

//------------------------------------------------------------------------------
// Address: 0x100E7990
// Name: public: static void __near * CEventAction::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CEventAction::operator new(unsigned int stAllocateBlock)
{
  return CUtlMemoryPool::Alloc(this: &g_EntityListPool, amount: stAllocateBlock);
}

//------------------------------------------------------------------------------
// Address: 0x100E79B0
// Name: public: static void CEventAction::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventAction::operator delete(void *pMem)
{
  CUtlMemoryPool::Free(this: &g_EntityListPool, memBlock: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x100E79D0
// Name: public: float CBaseEntityOutput::GetMaxDelay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntityOutput::GetMaxDelay(CBaseEntityOutput *this)
{
  CEventAction *m_ActionList; // eax
  float m_flDelay; // xmm1_4
  float flMaxDelay; // [esp+0h] [ebp-4h]

  m_ActionList = this->m_ActionList;
  m_flDelay = 0.0;
  for ( flMaxDelay = 0.0; m_ActionList != nullptr; m_ActionList = m_ActionList->m_pNext )
  {
    if ( m_ActionList->m_flDelay > m_flDelay )
    {
      m_flDelay = m_ActionList->m_flDelay;
      flMaxDelay = m_flDelay;
    }
  }
  return flMaxDelay;
}

//------------------------------------------------------------------------------
// Address: 0x100E7A10
// Name: public: CBaseEntityOutput::~CBaseEntityOutput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityOutput::~CBaseEntityOutput(CBaseEntityOutput *this)
{
  CEventAction *m_ActionList; // eax
  CEventAction *m_pNext; // esi

  m_ActionList = this->m_ActionList;
  if ( m_ActionList != nullptr )
  {
    do
    {
      m_pNext = m_ActionList->m_pNext;
      CUtlMemoryPool::Free(this: &g_EntityListPool, memBlock: m_ActionList);
      m_ActionList = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7A40
// Name: public: void CBaseEntityOutput::AddEventAction(class CEventAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityOutput::AddEventAction(CBaseEntityOutput *this, CEventAction *pEventAction)
{
  pEventAction->m_pNext = this->m_ActionList;
  this->m_ActionList = pEventAction;
}

//------------------------------------------------------------------------------
// Address: 0x100E7A60
// Name: public: int CBaseEntityOutput::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntityOutput::Save(CBaseEntityOutput *this, ISave *save)
{
  CEventAction *m_ActionList; // esi

  if ( save->WriteFields(
         this: save,
         a2: "Value",
         a3: this,
         a4: nullptr,
         a5: CBaseEntityOutput::m_DataMap.dataDesc,
         a6: CBaseEntityOutput::m_DataMap.dataNumFields) == 0 )
    return 0;
  m_ActionList = this->m_ActionList;
  if ( m_ActionList != nullptr )
  {
    while ( save->WriteFields(
              this: save,
              a2: "EntityOutput",
              a3: m_ActionList,
              a4: nullptr,
              a5: CEventAction::m_DataMap.dataDesc,
              a6: CEventAction::m_DataMap.dataNumFields) != 0 )
    {
      m_ActionList = m_ActionList->m_pNext;
      if ( m_ActionList == nullptr )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E7AE0
// Name: public: int CBaseEntityOutput::NumberOfElements(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntityOutput::NumberOfElements(CBaseEntityOutput *this)
{
  CEventAction *m_ActionList; // ecx
  int result; // eax

  m_ActionList = this->m_ActionList;
  for ( result = 0; m_ActionList != nullptr; ++result )
    m_ActionList = m_ActionList->m_pNext;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E7B00
// Name: class ISaveRestoreBlockHandler __near * GetEventQueueSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CEventQueue_SaveRestoreBlockHandler *__cdecl GetEventQueueSaveRestoreBlockHandler()
{
  return &g_EventQueue_SaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x100E7B10
// Name: public: void CEventQueue::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::Init(CEventQueue *this)
{
  EventQueuePrioritizedEvent_t *m_pNext; // eax
  EventQueuePrioritizedEvent_t *v3; // esi

  m_pNext = this->m_Events.m_pNext;
  if ( m_pNext != nullptr )
  {
    do
    {
      v3 = m_pNext->m_pNext;
      CUtlMemoryPool::Free(this: &EventQueuePrioritizedEvent_t::s_Allocator, memBlock: m_pNext);
      m_pNext = v3;
    }
    while ( v3 != nullptr );
  }
  this->m_Events.m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E7B40
// Name: public: int CEventQueue::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventQueue::Save(CEventQueue *this, ISave *save)
{
  EventQueuePrioritizedEvent_t *m_pNext; // eax
  int v4; // ecx
  EventQueuePrioritizedEvent_t *v6; // esi

  m_pNext = this->m_Events.m_pNext;
  this->m_iListCount = 0;
  if ( m_pNext != nullptr )
  {
    v4 = 0;
    do
    {
      this->m_iListCount = ++v4;
      m_pNext = m_pNext->m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  if ( save->WriteFields(
         this: save,
         a2: "EventQueue",
         a3: this,
         a4: nullptr,
         a5: CEventQueue::m_DataMap.dataDesc,
         a6: CEventQueue::m_DataMap.dataNumFields) == 0 )
    return 0;
  v6 = this->m_Events.m_pNext;
  if ( v6 != nullptr )
  {
    while ( save->WriteFields(
              this: save,
              a2: "PEvent",
              a3: v6,
              a4: nullptr,
              a5: EventQueuePrioritizedEvent_t::m_DataMap.dataDesc,
              a6: EventQueuePrioritizedEvent_t::m_DataMap.dataNumFields) != 0 )
    {
      v6 = v6->m_pNext;
      if ( v6 == nullptr )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E7BE0
// Name: public: CEntityList::CEntityList(void)
// Source: json
//------------------------------------------------------------------------------
CEntityList *__thiscall CEntityList::CEntityList(CEntityList *this)
{
  this->m_pItemList = nullptr;
  this->m_iNumItems = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E7BF0
// Name: public: CEntityList::~CEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityList::~CEntityList(CEntityList *this)
{
  entitem_t *m_pItemList; // eax
  entitem_t *pNext; // esi

  m_pItemList = this->m_pItemList;
  if ( m_pItemList != nullptr )
  {
    do
    {
      pNext = m_pItemList->pNext;
      CUtlMemoryPool::Free(this: &g_EntListMemPool, memBlock: m_pItemList);
      m_pItemList = pNext;
    }
    while ( pNext != nullptr );
  }
  this->m_pItemList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E7C20
// Name: public: CEventAction::CEventAction(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CEventAction *__thiscall CEventAction::CEventAction(CEventAction *this, char *ActionData)
{
  char *v2; // ebx
  int v4; // eax
  char v5; // di
  const char *v6; // ebx
  const char *v7; // ebx
  const char *v8; // ebx
  const char *v9; // ebx
  int v10; // eax
  bool v11; // zf
  CEventAction *result; // eax
  char szToken[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = ActionData;
  this->m_pNext = nullptr;
  this->m_iIDStamp = ++CEventAction::s_iNextIDStamp;
  this->m_flDelay = 0.0;
  this->m_iTarget.pszValue = nullptr;
  this->m_iParameter.pszValue = nullptr;
  this->m_iTargetInput.pszValue = nullptr;
  this->m_nTimesToFire = -1;
  if ( v2 == nullptr )
    return this;
  LOBYTE(ActionData) = 27;
  strchr(string: v2, chr: 0x1Bu);
  if ( v4 == 0 )
    LOBYTE(ActionData) = 44;
  v5 = (char)ActionData;
  v6 = nexttoken(token: szToken, str: v2, sep: (char)ActionData);
  if ( szToken[0] != 0 )
    this->m_iTarget.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&ActionData).pszValue;
  v7 = nexttoken(token: szToken, str: v6, sep: v5);
  this->m_iTargetInput.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&ActionData).pszValue;
  v8 = nexttoken(token: szToken, str: v7, sep: v5);
  if ( szToken[0] != 0 )
    this->m_iParameter.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&ActionData).pszValue;
  v9 = nexttoken(token: szToken, str: v8, sep: v5);
  if ( szToken[0] != 0 )
    this->m_flDelay = atof(nptr: szToken);
  nexttoken(token: szToken, str: v9, sep: v5);
  if ( szToken[0] == 0 )
    return this;
  v10 = atoi(nptr: szToken);
  this->m_nTimesToFire = v10;
  v11 = v10 == 0;
  result = this;
  if ( v11 )
    this->m_nTimesToFire = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E7DB0
// Name: public: void CBaseEntityOutput::RemoveEventAction(class CEventAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityOutput::RemoveEventAction(CBaseEntityOutput *this, CEventAction *pEventAction)
{
  CEventAction *m_ActionList; // eax

  m_ActionList = this->m_ActionList;
  if ( m_ActionList != nullptr )
  {
    while ( m_ActionList != pEventAction )
    {
      m_ActionList = m_ActionList->m_pNext;
      if ( m_ActionList == nullptr )
        return;
    }
    this->m_ActionList = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7DE0
// Name: private: virtual void CEventsSaveDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventsSaveDataOps::Save(
        CEventsSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  CBaseEntityOutput *pField; // esi
  ISave *v4; // edi
  int fieldSize; // ebx
  CEventAction *m_ActionList; // eax
  const SaveRestoreFieldInfo_t *i; // ecx
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx

  pField = (CBaseEntityOutput *)fieldInfo->pField;
  if ( fieldInfo->pTypeDesc->fieldSize != 0 )
  {
    v4 = pSave;
    fieldSize = fieldInfo->pTypeDesc->fieldSize;
    do
    {
      m_ActionList = pField->m_ActionList;
      for ( i = nullptr; m_ActionList != nullptr; i = (const SaveRestoreFieldInfo_t *)((char *)i + 1) )
        m_ActionList = m_ActionList->m_pNext;
      WriteInt_2 = v4->WriteInt_2;
      fieldInfo = i;
      WriteInt_2(this: v4, a2: (const int *)&fieldInfo, a3: 1);
      CBaseEntityOutput::Save(this: pField++, save: v4);
      --fieldSize;
    }
    while ( fieldSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7E40
// Name: private: virtual void CEventsSaveDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventsSaveDataOps::Restore(CEventsSaveDataOps *this, CBaseEntityOutput *fieldInfo, IRestore *pRestore)
{
  CBaseEntityOutput *iVal; // esi
  int v4; // eax
  CEventAction *v5; // ebx
  CEventAction *v6; // eax
  CEventAction *v7; // esi
  bool v8; // zf
  int v9; // [esp+8h] [ebp-Ch]
  int nElements; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]
  CBaseEntityOutput *ev; // [esp+1Ch] [ebp+8h]

  iVal = (CBaseEntityOutput *)fieldInfo->m_Value.iVal;
  v4 = *(unsigned __int16 *)(LODWORD(fieldInfo->m_Value.vecVal[2]) + 12);
  ev = (CBaseEntityOutput *)fieldInfo->m_Value.iVal;
  if ( v4 != 0 )
  {
    v9 = v4;
    do
    {
      nElements = pRestore->ReadInt(this: pRestore);
      if ( pRestore->ReadFields(
             this: pRestore,
             a2: "Value",
             a3: iVal,
             a4: nullptr,
             a5: CBaseEntityOutput::m_DataMap.dataDesc,
             a6: CBaseEntityOutput::m_DataMap.dataNumFields) != 0 )
      {
        v5 = nullptr;
        iVal->m_ActionList = nullptr;
        v11 = 0;
        if ( nElements > 0 )
        {
          do
          {
            v6 = (CEventAction *)CUtlMemoryPool::Alloc(this: &g_EntityListPool, amount: 0x1Cu);
            if ( v6 != nullptr )
            {
              v6->m_pNext = nullptr;
              v6->m_iIDStamp = ++CEventAction::s_iNextIDStamp;
              v6->m_flDelay = 0.0;
              v6->m_iTarget.pszValue = nullptr;
              v6->m_iParameter.pszValue = nullptr;
              v6->m_iTargetInput.pszValue = nullptr;
              v6->m_nTimesToFire = -1;
              v7 = v6;
            }
            else
            {
              v7 = nullptr;
            }
            if ( pRestore->ReadFields(
                   this: pRestore,
                   a2: "EntityOutput",
                   a3: v7,
                   a4: nullptr,
                   a5: CEventAction::m_DataMap.dataDesc,
                   a6: CEventAction::m_DataMap.dataNumFields) == 0 )
              break;
            if ( v5 != nullptr )
              v5->m_pNext = v7;
            else
              ev->m_ActionList = v7;
            v7->m_pNext = nullptr;
            v5 = v7;
            ++v11;
          }
          while ( v11 < nElements );
          iVal = ev;
        }
      }
      ++iVal;
      v8 = v9-- == 1;
      ev = iVal;
    }
    while ( !v8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7F60
// Name: private: virtual bool CEventsSaveDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEventsSaveDataOps::IsEmpty(CEventsSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  typedescription_t *pTypeDesc; // eax
  int fieldSize; // edi
  int v4; // esi
  _DWORD *i; // edx
  int v6; // eax
  int v7; // ecx

  pTypeDesc = fieldInfo->pTypeDesc;
  fieldSize = pTypeDesc->fieldSize;
  v4 = 0;
  if ( pTypeDesc->fieldSize == 0 )
    return 1;
  for ( i = (char *)fieldInfo->pField + 16; ; i += 6 )
  {
    v6 = i[1];
    v7 = 0;
    if ( v6 != 0 )
    {
      do
      {
        v6 = *(_DWORD *)(v6 + 24);
        ++v7;
      }
      while ( v6 != 0 );
      if ( v7 != 0 )
        break;
    }
    if ( *i != 0 )
      break;
    if ( ++v4 >= fieldSize )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E7FC0
// Name: private: virtual bool CEventsSaveDataOps::Parse(struct SaveRestoreFieldInfo_t const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEventsSaveDataOps::Parse(
        CEventsSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        char *szValue)
{
  void *pField; // esi
  CEventAction *v4; // eax
  CEventAction *v5; // eax

  pField = fieldInfo->pField;
  v4 = (CEventAction *)CUtlMemoryPool::Alloc(this: &g_EntityListPool, amount: 0x1Cu);
  if ( v4 != nullptr )
  {
    v5 = CEventAction::CEventAction(this: v4, ActionData: szValue);
    v5->m_pNext = *((CEventAction **)pField + 5);
    *((_DWORD *)pField + 5) = v5;
  }
  else
  {
    MEMORY[0x18] = *((_DWORD *)pField + 5);
    *((_DWORD *)pField + 5) = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E8010
// Name: public: CMultiInputVar::~CMultiInputVar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiInputVar::~CMultiInputVar(CMultiInputVar *this)
{
  CMultiInputVar::inputitem_t **i; // eax
  CMultiInputVar::inputitem_t *v3; // [esp-4h] [ebp-8h]

  if ( this->m_InputList != nullptr )
  {
    for ( i = &this->m_InputList->next; *i != nullptr; i = &this->m_InputList->next )
    {
      v3 = *i;
      *i = (*i)->next;
      CUtlMemoryPool::Free(this: &g_EntityListPool, memBlock: v3);
    }
    CUtlMemoryPool::Free(this: &g_EntityListPool, memBlock: this->m_InputList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8050
// Name: public: void variant_t::Set(enum _fieldtypes,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall variant_t::Set(variant_t *this, _fieldtypes ftype, $3B1CACFA647AB85A7D70EA6016B49717 *data)
{
  this->fieldType = ftype;
  switch ( ftype )
  {
    case FIELD_FLOAT:
      this->flVal = data->flVal;
      break;
    case FIELD_STRING:
    case FIELD_INTEGER:
      this->iVal = data->iVal;
      break;
    case FIELD_VECTOR:
    case FIELD_POSITION_VECTOR:
      this->___u0 = *data;
      break;
    case FIELD_BOOLEAN:
      this->bVal = data->bVal;
      break;
    case FIELD_SHORT:
      this->iVal = SLOWORD(data->iVal);
      break;
    case FIELD_CHARACTER:
      this->iVal = data->bVal;
      break;
    case FIELD_COLOR32:
      this->iVal = data->iVal;
      break;
    case FIELD_CLASSPTR:
      CHandle<CBaseEntity>::operator=(this: &this->eVal, val: (const CBaseEntity *)data->iszVal.pszValue);
      break;
    case FIELD_EHANDLE:
      this->eVal.m_Index = data->iVal;
      break;
    default:
      this->iVal = 0;
      this->fieldType = FIELD_VOID;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8130
// Name: public: void variant_t::SetOther(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall variant_t::SetOther(variant_t *this, float *data)
{
  switch ( this->fieldType )
  {
    case FIELD_FLOAT:
      *data = this->flVal;
      break;
    case FIELD_STRING:
    case FIELD_COLOR32:
      *data = this->flVal;
      break;
    case FIELD_VECTOR:
    case FIELD_POSITION_VECTOR:
      *($3B1CACFA647AB85A7D70EA6016B49717 *)data = this->___u0;
      break;
    case FIELD_INTEGER:
      *data = this->flVal;
      break;
    case FIELD_BOOLEAN:
      *(_BYTE *)data = this->bVal;
      break;
    case FIELD_SHORT:
      *(_WORD *)data = LOWORD(this->flVal);
      break;
    case FIELD_CHARACTER:
      *(_BYTE *)data = this->bVal;
      break;
    case FIELD_CLASSPTR:
      *(_DWORD *)data = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->eVal);
      break;
    case FIELD_EHANDLE:
      *data = *(float *)&this->eVal.m_Index;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8200
// Name: public: void CEntityList::DeleteEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityList::DeleteEntity(CEntityList *this, CBaseEntity *pEnt)
{
  entitem_t *m_pItemList; // edx
  CBaseEntityList *v4; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  entitem_t *prev; // [esp+4h] [ebp-4h]

  m_pItemList = this->m_pItemList;
  prev = nullptr;
  if ( m_pItemList != nullptr )
  {
    v4 = g_pEntityList;
    do
    {
      m_Index = m_pItemList->hEnt.m_Index;
      if ( m_pItemList->hEnt.m_Index == -1
        || v4->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEnt
        || m_Index == -1
        || v4->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || v4->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        if ( prev != nullptr )
          prev->pNext = m_pItemList->pNext;
        else
          this->m_pItemList = m_pItemList->pNext;
        CUtlMemoryPool::Free(this: &g_EntListMemPool, memBlock: m_pItemList);
        --this->m_iNumItems;
        m_pItemList = this->m_pItemList;
        v4 = g_pEntityList;
        prev = nullptr;
      }
      else
      {
        prev = m_pItemList;
        m_pItemList = m_pItemList->pNext;
      }
    }
    while ( m_pItemList != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E82C0
// Name: public: virtual char const __near * CEventQueue_SaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEventQueue_SaveRestoreBlockHandler::GetBlockName(CEventQueue_SaveRestoreBlockHandler *this)
{
  return "EventQueue";
}

//------------------------------------------------------------------------------
// Address: 0x100E82D0
// Name: public: virtual void CEventQueue_SaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue_SaveRestoreBlockHandler::WriteSaveHeaders(
        CEventQueue_SaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &EVENTQUEUE_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100E82F0
// Name: public: virtual void CEventQueue_SaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue_SaveRestoreBlockHandler::ReadRestoreHeaders(
        CEventQueue_SaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)EVENTQUEUE_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x100E8320
// Name: public: virtual void CEventQueue_SaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue_SaveRestoreBlockHandler::Save(CEventQueue_SaveRestoreBlockHandler *this, ISave *pSave)
{
  CEventQueue::Save(this: &g_EventQueue, save: pSave);
}

//------------------------------------------------------------------------------
// Address: 0x100E8330
// Name: public: void CEventQueue::AddEvent(char const __near *,char const __near *,class variant_t,float,class CBaseEntity __near *,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::AddEvent(
        CEventQueue *this,
        const char *target,
        const char *targetInput,
        variant_t Value,
        float fireDelay,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        int outputID)
{
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  CEventQueue *v12; // eax
  EventQueuePrioritizedEvent_t *i; // ecx
  int v14; // eax

  v8 = CUtlMemoryPool::Alloc(this: &EventQueuePrioritizedEvent_t::s_Allocator, amount: 0x38u);
  if ( v8 != nullptr )
  {
    v8[3] = -1;
    v8[4] = -1;
    v8[6] = -1;
    v8[7] = 0;
    v8[10] = -1;
    v8[11] = 0;
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = target;
  *(float *)v9 = gpGlobals->curtime + fireDelay;
  if ( target == nullptr || *target == 0 )
    v10 = nullptr;
  v9[1] = v10;
  v11 = targetInput;
  v9[6] = -1;
  if ( targetInput == nullptr || *targetInput == 0 )
    v11 = nullptr;
  v9[2] = v11;
  if ( pActivator != nullptr )
    v9[3] = pActivator->GetRefEHandle(this: pActivator)->m_Index;
  else
    v9[3] = -1;
  if ( pCaller != nullptr )
    v9[4] = pCaller->GetRefEHandle(this: pCaller)->m_Index;
  else
    v9[4] = -1;
  *(_QWORD *)(v9 + 7) = *(_QWORD *)&Value.bVal;
  *(_QWORD *)(v9 + 9) = *((_QWORD *)&Value.rgbaVal + 1);
  v9[5] = outputID;
  v12 = this;
  v9[11] = Value.fieldType;
  for ( i = this->m_Events.m_pNext; i != nullptr; i = i->m_pNext )
  {
    if ( i->m_flFireTime > *(float *)v9 )
      break;
    v12 = (CEventQueue *)i;
  }
  v9[12] = v12->m_Events.m_pNext;
  v9[13] = v12;
  v12->m_Events.m_pNext = (EventQueuePrioritizedEvent_t *)v9;
  v14 = v9[12];
  if ( v14 != 0 )
    *(_DWORD *)(v14 + 52) = v9;
}

//------------------------------------------------------------------------------
// Address: 0x100E8440
// Name: public: void CEventQueue::AddEvent(class CBaseEntity __near *,char const __near *,class variant_t,float,class CBaseEntity __near *,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::AddEvent(
        CEventQueue *this,
        CBaseEntity *target,
        const char *targetInput,
        variant_t Value,
        float fireDelay,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        int outputID)
{
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  const char *v11; // eax
  EventQueuePrioritizedEvent_t *m_pNext; // ecx
  CEventQueue *i; // eax
  int v14; // eax

  v9 = CUtlMemoryPool::Alloc(this: &EventQueuePrioritizedEvent_t::s_Allocator, amount: 0x38u);
  if ( v9 != nullptr )
  {
    v9[3] = -1;
    v9[4] = -1;
    v9[6] = -1;
    v9[7] = 0;
    v9[10] = -1;
    v9[11] = 0;
    v10 = v9;
  }
  else
  {
    v10 = nullptr;
  }
  *(float *)v10 = gpGlobals->curtime + fireDelay;
  v10[1] = 0;
  if ( target != nullptr )
    v10[6] = target->GetRefEHandle(this: target)->m_Index;
  else
    v10[6] = -1;
  v11 = targetInput;
  if ( targetInput == nullptr || *targetInput == 0 )
    v11 = nullptr;
  v10[2] = v11;
  if ( pActivator != nullptr )
    v10[3] = pActivator->GetRefEHandle(this: pActivator)->m_Index;
  else
    v10[3] = -1;
  if ( pCaller != nullptr )
    v10[4] = pCaller->GetRefEHandle(this: pCaller)->m_Index;
  else
    v10[4] = -1;
  *(_QWORD *)(v10 + 7) = *(_QWORD *)&Value.bVal;
  *(_QWORD *)(v10 + 9) = *((_QWORD *)&Value.rgbaVal + 1);
  v10[5] = outputID;
  v10[11] = Value.fieldType;
  m_pNext = this->m_Events.m_pNext;
  for ( i = this; m_pNext != nullptr; m_pNext = m_pNext->m_pNext )
  {
    if ( m_pNext->m_flFireTime > *(float *)v10 )
      break;
    i = (CEventQueue *)m_pNext;
  }
  v10[12] = i->m_Events.m_pNext;
  v10[13] = i;
  i->m_Events.m_pNext = (EventQueuePrioritizedEvent_t *)v10;
  v14 = v10[12];
  if ( v14 != 0 )
    *(_DWORD *)(v14 + 52) = v10;
}

//------------------------------------------------------------------------------
// Address: 0x100E8540
// Name: public: void CEventQueue::AddEvent(class CBaseEntity __near *,char const __near *,float,class CBaseEntity __near *,class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::AddEvent(
        CEventQueue *this,
        CBaseEntity *target,
        const char *action,
        float fireDelay,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        int outputID)
{
  variant_t v7; // [esp-14h] [ebp-3Ch]
  unsigned int Value_4; // [esp+18h] [ebp-10h]
  float Value_8; // [esp+1Ch] [ebp-Ch]

  v7.vecVal[2] = Value_8;
  *(_QWORD *)&v7.bVal = __PAIR64__(Value_4, 0);
  *(_QWORD *)&v7.eVal.m_Index = 0xFFFFFFFFLL;
  CEventQueue::AddEvent(this, target, targetInput: action, Value: v7, fireDelay, pActivator, pCaller, outputID);
}

//------------------------------------------------------------------------------
// Address: 0x100E85A0
// Name: public: void CEventQueue::ServiceEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::ServiceEvents(CEventQueue *this)
{
  CBaseEntity *EntityByName; // ebx
  EventQueuePrioritizedEvent_t *m_pNext; // esi
  void (*BeginLock)(void); // eax
  unsigned int m_Index; // eax
  CBaseEntityList *v5; // edx
  unsigned int v6; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  const char *pszValue; // eax
  unsigned int v11; // eax
  IHandleEntity *v12; // edi
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  const char *v15; // eax
  unsigned int v16; // ecx
  CBaseEntityList *v17; // edi
  int v18; // eax
  CEntInfo *v19; // edx
  unsigned int v20; // ecx
  int v21; // eax
  bool v22; // zf
  CEntInfo *v23; // eax
  IHandleEntity *v24; // ecx
  unsigned int v25; // eax
  IHandleEntity *v26; // ebx
  unsigned int v27; // eax
  IHandleEntity *v28; // edx
  const char *v29; // eax
  CBaseEntity *EntityByClassname; // edi
  const char *v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // eax
  IHandleEntity *v34; // ecx
  const char *v35; // eax
  unsigned int v36; // ecx
  const char *v37; // ebx
  int v38; // eax
  CEntInfo *v39; // edx
  unsigned int v40; // ecx
  IHandleEntity *v41; // edx
  int v42; // eax
  CEntInfo *v43; // eax
  IHandleEntity *v44; // eax
  const char *v45; // ecx
  const char *v46; // eax
  EventQueuePrioritizedEvent_t *v47; // eax
  const char *v48; // [esp-18h] [ebp-134h]
  float v49; // [esp-14h] [ebp-130h]
  float v50; // [esp-10h] [ebp-12Ch]
  unsigned int v51; // [esp-Ch] [ebp-128h]
  _fieldtypes fieldType; // [esp-8h] [ebp-124h]
  int m_iOutputID; // [esp-4h] [ebp-120h]
  char szBuffer[256]; // [esp+Ch] [ebp-110h] BYREF
  CEventQueue *v55; // [esp+10Ch] [ebp-10h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+110h] [ebp-Ch]
  const char *pClass; // [esp+114h] [ebp-8h]
  bool targetFound; // [esp+11Bh] [ebp-1h]

  EntityByName = nullptr;
  v55 = this;
  if ( !CBaseEntity::m_bDebugPause || CBaseEntity::m_nDebugSteps > 0 )
  {
    m_pNext = this->m_Events.m_pNext;
    if ( m_pNext != nullptr )
    {
      while ( 1 )
      {
        if ( gpGlobals->curtime < m_pNext->m_flFireTime )
          return;
        BeginLock = (void (*)(void))mdlcache->BeginLock;
        cacheCriticalSection.m_pCache = mdlcache;
        BeginLock();
        targetFound = false;
        if ( m_pNext->m_iTarget.pszValue != nullptr )
        {
          m_Index = m_pNext->m_pCaller.m_Index;
          v5 = g_pEntityList;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            pClass = nullptr;
          }
          else
          {
            pClass = (const char *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          while ( 1 )
          {
            v6 = m_pNext->m_pCaller.m_Index;
            if ( v6 == -1 || v5->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
              m_pEntity = nullptr;
            else
              m_pEntity = (CBaseEntity *)v5->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
            v8 = m_pNext->m_pActivator.m_Index;
            if ( v8 == -1 || v5->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
              v9 = nullptr;
            else
              v9 = (CBaseEntity *)v5->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
            pszValue = m_pNext->m_iTarget.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            EntityByName = CGlobalEntityList::FindEntityByName(
                             this: &gEntList,
                             pStartEntity: EntityByName,
                             szName: pszValue,
                             pSearchingEntity: (CBaseEntity *)pClass,
                             pActivator: v9,
                             pCaller: m_pEntity,
                             pFilter: nullptr);
            if ( EntityByName == nullptr )
              break;
            v11 = m_pNext->m_pCaller.m_Index;
            if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
              v12 = nullptr;
            else
              v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
            v13 = m_pNext->m_pActivator.m_Index;
            if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
              v14 = nullptr;
            else
              v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
            v15 = m_pNext->m_iTargetInput.pszValue;
            if ( v15 == nullptr )
              v15 = locale;
            ((void (__thiscall *)(CBaseEntity *, const char *, IHandleEntity *, IHandleEntity *, int, _DWORD, _DWORD, unsigned int, _fieldtypes, int))EntityByName->AcceptInput)(
              a1: EntityByName,
              a2: v15,
              a3: v14,
              a4: v12,
              a5: m_pNext->m_VariantValue.iVal,
              a6: LODWORD(m_pNext->m_VariantValue.vecVal[1]),
              a7: LODWORD(m_pNext->m_VariantValue.vecVal[2]),
              a8: m_pNext->m_VariantValue.eVal.m_Index,
              a9: m_pNext->m_VariantValue.fieldType,
              a10: m_pNext->m_iOutputID);
            v5 = g_pEntityList;
            targetFound = true;
          }
        }
        v16 = m_pNext->m_pEntTarget.m_Index;
        v17 = g_pEntityList;
        if ( v16 != -1 )
        {
          v18 = (unsigned __int16)v16;
          v19 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v16];
          v20 = HIWORD(v16);
          if ( v19->m_SerialNumber == v20 && v19->m_pEntity != nullptr )
          {
            v21 = v18;
            v22 = g_pEntityList->m_EntPtrArray[v21].m_SerialNumber == v20;
            v23 = &g_pEntityList->m_EntPtrArray[v21];
            if ( v22 )
              v24 = v23->m_pEntity;
            else
              v24 = nullptr;
            v25 = m_pNext->m_pCaller.m_Index;
            if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
              v26 = nullptr;
            else
              v26 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
            v27 = m_pNext->m_pActivator.m_Index;
            if ( v27 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_SerialNumber != HIWORD(v27) )
              v28 = nullptr;
            else
              v28 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v27].m_pEntity;
            v29 = m_pNext->m_iTargetInput.pszValue;
            if ( v29 == nullptr )
              v29 = locale;
            ((void (__thiscall *)(IHandleEntity *, const char *, IHandleEntity *, IHandleEntity *, int, _DWORD, _DWORD, unsigned int, _fieldtypes, int))v24->__vftable[13].dtr_IHandleEntity)(
              a1: v24,
              a2: v29,
              a3: v28,
              a4: v26,
              a5: m_pNext->m_VariantValue.iVal,
              a6: LODWORD(m_pNext->m_VariantValue.vecVal[1]),
              a7: LODWORD(m_pNext->m_VariantValue.vecVal[2]),
              a8: m_pNext->m_VariantValue.eVal.m_Index,
              a9: m_pNext->m_VariantValue.fieldType,
              a10: m_pNext->m_iOutputID);
            goto LABEL_88;
          }
        }
        if ( targetFound )
          goto LABEL_88;
        if ( m_pNext->m_iTarget.pszValue == nullptr )
          goto LABEL_70;
        EntityByClassname = nullptr;
        while ( 1 )
        {
          v31 = m_pNext->m_iTarget.pszValue;
          if ( v31 == nullptr )
            v31 = locale;
          EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                                this: &gEntList,
                                pStartEntity: EntityByClassname,
                                szName: v31);
          if ( EntityByClassname == nullptr )
            break;
          m_iOutputID = m_pNext->m_iOutputID;
          v49 = m_pNext->m_VariantValue.vecVal[1];
          v50 = m_pNext->m_VariantValue.vecVal[2];
          v48 = m_pNext->m_VariantValue.iszVal.pszValue;
          v51 = m_pNext->m_VariantValue.eVal.m_Index;
          fieldType = m_pNext->m_VariantValue.fieldType;
          v32 = m_pNext->m_pCaller.m_Index;
          if ( v32 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber != HIWORD(v32) )
            pClass = nullptr;
          else
            pClass = (const char *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
          v33 = m_pNext->m_pActivator.m_Index;
          if ( v33 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_SerialNumber != HIWORD(v33) )
            v34 = nullptr;
          else
            v34 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_pEntity;
          v35 = m_pNext->m_iTargetInput.pszValue;
          if ( v35 == nullptr )
            v35 = locale;
          ((void (__thiscall *)(CBaseEntity *, const char *, IHandleEntity *, const char *, const char *, _DWORD, _DWORD, unsigned int, _fieldtypes, int))EntityByClassname->AcceptInput)(
            a1: EntityByClassname,
            a2: v35,
            a3: v34,
            a4: pClass,
            a5: v48,
            a6: LODWORD(v49),
            a7: LODWORD(v50),
            a8: v51,
            a9: fieldType,
            a10: m_iOutputID);
          targetFound = true;
        }
        if ( !targetFound )
          break;
LABEL_88:
        m_pNext->m_pPrev->m_pNext = m_pNext->m_pNext;
        v47 = m_pNext->m_pNext;
        if ( v47 != nullptr )
          v47->m_pPrev = m_pNext->m_pPrev;
        CUtlMemoryPool::Free(this: &EventQueuePrioritizedEvent_t::s_Allocator, memBlock: m_pNext);
        if ( CBaseEntity::m_bDebugPause )
        {
          if ( CBaseEntity::m_nDebugSteps <= 0 || (--CBaseEntity::m_nDebugSteps, CBaseEntity::m_nDebugSteps <= 0) )
          {
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return;
          }
        }
        m_pNext = v55->m_Events.m_pNext;
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        if ( m_pNext == nullptr )
          return;
        EntityByName = nullptr;
      }
      v17 = g_pEntityList;
LABEL_70:
      v36 = m_pNext->m_pCaller.m_Index;
      v37 = locale;
      pClass = locale;
      if ( v36 != -1 )
      {
        v38 = (unsigned __int16)v36;
        v39 = &v17->m_EntPtrArray[(unsigned __int16)v36];
        v40 = HIWORD(v36);
        if ( v39->m_SerialNumber == v40 && v39->m_pEntity != nullptr )
        {
          if ( v17->m_EntPtrArray[v38].m_SerialNumber == v40 )
            v41 = v17->m_EntPtrArray[v38].m_pEntity;
          else
            v41 = nullptr;
          pClass = (const char *)v41[23].__vftable;
          if ( pClass == nullptr )
            pClass = locale;
          v42 = v38;
          v22 = v17->m_EntPtrArray[v42].m_SerialNumber == v40;
          v43 = &v17->m_EntPtrArray[v42];
          if ( v22 )
            v44 = v43->m_pEntity;
          else
            v44 = nullptr;
          v37 = (const char *)v44[51].__vftable;
          if ( v37 == nullptr )
            v37 = locale;
        }
      }
      v45 = m_pNext->m_iTarget.pszValue;
      if ( v45 == nullptr )
        v45 = locale;
      v46 = m_pNext->m_iTargetInput.pszValue;
      if ( v46 == nullptr )
        v46 = locale;
      V_snprintf(
        pDest: szBuffer,
        maxLen: 256,
        pFormat: "unhandled input: (%s) -> (%s), from (%s,%s); target entity not found\n",
        v46,
        v45,
        pClass,
        v37);
      _DevMsg(a1: 2, a2: szBuffer);
      goto LABEL_88;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8A80
// Name: public: void CEventQueue::CancelEvents(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::CancelEvents(CEventQueue *this, CBaseEntity *pCaller)
{
  CBaseEntity *v2; // edx
  EventQueuePrioritizedEvent_t *m_pNext; // edi
  unsigned int m_Index; // eax
  char v5; // bl
  IHandleEntity *m_pEntity; // ecx
  const char *pszValue; // edx
  IHandleEntity *v8; // ecx
  const char *v9; // ecx
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  const char *v12; // esi
  const char *Classname; // eax
  EventQueuePrioritizedEvent_t **p_m_pNext; // eax
  _DWORD *p_m_flFireTime; // ecx
  EventQueuePrioritizedEvent_t *v16; // eax

  v2 = pCaller;
  if ( pCaller != nullptr )
  {
    m_pNext = this->m_Events.m_pNext;
    if ( m_pNext != nullptr )
    {
      while ( 1 )
      {
        m_Index = m_pNext->m_pCaller.m_Index;
        v5 = 0;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity == v2 )
        {
          pszValue = v2->m_iName.m_Value.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            v8 = nullptr;
          }
          else
          {
            v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          v9 = (const char *)v8[51].__vftable;
          if ( v9 == nullptr )
            v9 = locale;
          if ( _V_stricmp(s1: v9, s2: pszValue) == 0 )
          {
            v10 = m_pNext->m_pCaller.m_Index;
            if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
              v11 = nullptr;
            else
              v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
            v12 = (const char *)v11[23].__vftable;
            if ( v12 == nullptr )
              v12 = locale;
            Classname = CBaseEntity::GetClassname(this: pCaller);
            if ( _V_stricmp(s1: v12, s2: Classname) == 0 )
              v5 = 1;
          }
        }
        p_m_pNext = &m_pNext->m_pNext;
        p_m_flFireTime = (_DWORD *)&m_pNext->m_flFireTime;
        m_pNext = m_pNext->m_pNext;
        if ( v5 != 0 )
        {
          *(_DWORD *)(p_m_flFireTime[13] + 48) = m_pNext;
          v16 = *p_m_pNext;
          if ( v16 != nullptr )
            v16->m_pPrev = (EventQueuePrioritizedEvent_t *)p_m_flFireTime[13];
          CUtlMemoryPool::Free(this: &EventQueuePrioritizedEvent_t::s_Allocator, memBlock: p_m_flFireTime);
        }
        if ( m_pNext == nullptr )
          break;
        v2 = pCaller;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8BC0
// Name: void ServiceEventQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServiceEventQueue()
{
  CEventQueue::ServiceEvents(this: &g_EventQueue);
}

//------------------------------------------------------------------------------
// Address: 0x100E8BD0
// Name: public: int CEventQueue::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventQueue::Restore(CEventQueue *this, IRestore *restore)
{
  EventQueuePrioritizedEvent_t *m_pNext; // eax
  EventQueuePrioritizedEvent_t *v4; // esi
  IRestore *v5; // esi
  int (__thiscall *ReadFields)(IRestore *, const char *, void *, datamap_t *, typedescription_t *, int); // eax
  CBaseEntity *m_pEntity; // esi
  CBaseEntity *v9; // eax
  const char *pszValue; // edx
  CBaseEntity *v11; // esi
  IHandleEntity *v12; // eax
  const char *v13; // ecx
  const char *v14; // eax
  float fireDelay; // [esp+28h] [ebp-58h]
  float fireDelaya; // [esp+28h] [ebp-58h]
  CBaseEntity *v17; // [esp+2Ch] [ebp-54h]
  EventQueuePrioritizedEvent_t tmpEvent; // [esp+44h] [ebp-3Ch] BYREF
  int i; // [esp+7Ch] [ebp-4h]

  m_pNext = this->m_Events.m_pNext;
  if ( m_pNext != nullptr )
  {
    do
    {
      v4 = m_pNext->m_pNext;
      CUtlMemoryPool::Free(this: &EventQueuePrioritizedEvent_t::s_Allocator, memBlock: m_pNext);
      m_pNext = v4;
    }
    while ( v4 != nullptr );
  }
  v5 = restore;
  this->m_Events.m_pNext = nullptr;
  tmpEvent.m_pActivator.m_Index = -1;
  tmpEvent.m_pCaller.m_Index = -1;
  tmpEvent.m_pEntTarget.m_Index = -1;
  tmpEvent.m_VariantValue.eVal.m_Index = -1;
  ReadFields = restore->ReadFields;
  tmpEvent.m_VariantValue.iVal = 0;
  tmpEvent.m_VariantValue.fieldType = FIELD_VOID;
  if ( ReadFields(
         this: restore,
         a2: "EventQueue",
         a3: this,
         a4: nullptr,
         a5: CEventQueue::m_DataMap.dataDesc,
         a6: CEventQueue::m_DataMap.dataNumFields) == 0 )
    return 0;
  i = 0;
  if ( this->m_iListCount > 0 )
  {
    while ( v5->ReadFields(
              this: v5,
              a2: "PEvent",
              a3: &tmpEvent,
              a4: nullptr,
              a5: EventQueuePrioritizedEvent_t::m_DataMap.dataDesc,
              a6: EventQueuePrioritizedEvent_t::m_DataMap.dataNumFields) != 0 )
    {
      if ( tmpEvent.m_pEntTarget.m_Index != -1
        && g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pEntTarget.m_Index)].m_SerialNumber == HIWORD(tmpEvent.m_pEntTarget.m_Index)
        && g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pEntTarget.m_Index)].m_pEntity != nullptr )
      {
        if ( tmpEvent.m_pCaller.m_Index == -1
          || g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pCaller.m_Index)].m_SerialNumber != HIWORD(tmpEvent.m_pCaller.m_Index) )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pCaller.m_Index)].m_pEntity;
        }
        if ( tmpEvent.m_pActivator.m_Index == -1
          || g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pActivator.m_Index)].m_SerialNumber != HIWORD(tmpEvent.m_pActivator.m_Index) )
        {
          v9 = nullptr;
        }
        else
        {
          v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pActivator.m_Index)].m_pEntity;
        }
        fireDelay = tmpEvent.m_flFireTime - gpGlobals->curtime;
        pszValue = tmpEvent.m_iTargetInput.pszValue;
        if ( tmpEvent.m_iTargetInput.pszValue == nullptr )
          pszValue = locale;
        if ( g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pEntTarget.m_Index)].m_SerialNumber == HIWORD(tmpEvent.m_pEntTarget.m_Index) )
          CEventQueue::AddEvent(
            this,
            target: (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pEntTarget.m_Index)].m_pEntity,
            targetInput: pszValue,
            Value: tmpEvent.m_VariantValue,
            fireDelay,
            pActivator: v9,
            pCaller: m_pEntity,
            outputID: tmpEvent.m_iOutputID);
        else
          CEventQueue::AddEvent(
            this,
            target: nullptr,
            targetInput: pszValue,
            Value: tmpEvent.m_VariantValue,
            fireDelay,
            pActivator: v9,
            pCaller: m_pEntity,
            outputID: tmpEvent.m_iOutputID);
      }
      else
      {
        if ( tmpEvent.m_pCaller.m_Index == -1
          || g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pCaller.m_Index)].m_SerialNumber != HIWORD(tmpEvent.m_pCaller.m_Index) )
        {
          v11 = nullptr;
        }
        else
        {
          v11 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pCaller.m_Index)].m_pEntity;
        }
        if ( tmpEvent.m_pActivator.m_Index == -1
          || g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pActivator.m_Index)].m_SerialNumber != HIWORD(tmpEvent.m_pActivator.m_Index) )
        {
          v12 = nullptr;
        }
        else
        {
          v12 = g_pEntityList->m_EntPtrArray[LOWORD(tmpEvent.m_pActivator.m_Index)].m_pEntity;
        }
        v17 = (CBaseEntity *)v12;
        v13 = tmpEvent.m_iTargetInput.pszValue;
        if ( tmpEvent.m_iTargetInput.pszValue == nullptr )
          v13 = locale;
        v14 = tmpEvent.m_iTarget.pszValue;
        if ( tmpEvent.m_iTarget.pszValue == nullptr )
          v14 = locale;
        fireDelaya = tmpEvent.m_flFireTime - gpGlobals->curtime;
        CEventQueue::AddEvent(
          this,
          target: v14,
          targetInput: v13,
          Value: tmpEvent.m_VariantValue,
          fireDelay: fireDelaya,
          pActivator: v17,
          pCaller: v11,
          outputID: tmpEvent.m_iOutputID);
      }
      if ( ++i >= this->m_iListCount )
        return 1;
      v5 = restore;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E8E80
// Name: public: bool variant_t::Convert(enum _fieldtypes)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall variant_t::Convert(variant_t *this, int newType)
{
  _fieldtypes fieldType; // ecx
  bool result; // al
  char *iVal; // eax
  char *v6; // eax
  char *v7; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  CBaseEntity *EntityByName; // eax
  Vector tmpVec; // [esp+4h] [ebp-18h] BYREF
  int nAlpha; // [esp+10h] [ebp-Ch] BYREF
  int nBlue; // [esp+14h] [ebp-8h] BYREF
  int nGreen; // [esp+18h] [ebp-4h] BYREF

  fieldType = this->fieldType;
  if ( newType == fieldType )
    return true;
  if ( newType != 0 )
  {
    if ( newType == 20 )
    {
      return true;
    }
    else
    {
      switch ( fieldType )
      {
        case FIELD_FLOAT:
          if ( newType == 5 )
          {
            this->iVal = (int)this->flVal;
            this->fieldType = FIELD_INTEGER;
            result = true;
          }
          else
          {
            if ( newType != 6 )
              goto LABEL_49;
            this->bVal = this->flVal != 0.0;
            this->fieldType = FIELD_BOOLEAN;
            result = true;
          }
          break;
        case FIELD_STRING:
          switch ( newType )
          {
            case 1:
              if ( this->iVal != 0 )
                this->flVal = atof(nptr: (const char *)this->iVal);
              else
                this->iVal = 0;
              this->fieldType = FIELD_FLOAT;
              result = true;
              break;
            case 3:
              tmpVec.z = vec3_origin.z;
              iVal = (char *)this->iVal;
              *(_QWORD *)&tmpVec.x = *(_QWORD *)&vec3_origin.x;
              if ( iVal == nullptr )
                iVal = (char *)locale;
              if ( sscanf(string: iVal, format: "[%f %f %f]", &tmpVec, &tmpVec.y, &tmpVec.z) == 0 )
              {
                v6 = (char *)this->iVal;
                if ( this->iVal == 0 )
                  v6 = (char *)locale;
                sscanf(string: v6, format: "%f %f %f", &tmpVec, &tmpVec.y, &tmpVec.z);
              }
              this->___u0 = ($3B1CACFA647AB85A7D70EA6016B49717)tmpVec;
              this->fieldType = FIELD_VECTOR;
              result = true;
              break;
            case 5:
              if ( this->iVal != 0 )
                this->iVal = atoi(nptr: this->iszVal.pszValue);
              else
                this->iVal = 0;
              this->fieldType = FIELD_INTEGER;
              result = true;
              break;
            case 6:
              this->bVal = this->iVal != 0 && atoi(nptr: this->iszVal.pszValue) != 0;
              this->fieldType = FIELD_BOOLEAN;
              result = true;
              break;
            case 9:
              v7 = (char *)this->iVal;
              newType = 0;
              nGreen = 0;
              nBlue = 0;
              nAlpha = 255;
              if ( v7 == nullptr )
                v7 = (char *)locale;
              sscanf(string: v7, format: "%d %d %d %d", &newType, &nGreen, &nBlue, &nAlpha);
              v8 = nGreen;
              v9 = nBlue;
              this->bVal = newType;
              this->rgbaVal.a = nAlpha;
              this->rgbaVal.g = v8;
              this->rgbaVal.b = v9;
              this->fieldType = FIELD_COLOR32;
              result = true;
              break;
            case 13:
              EntityByName = nullptr;
              if ( this->iVal != 0 )
                EntityByName = CGlobalEntityList::FindEntityByName(
                                 this: &gEntList,
                                 pStartEntity: nullptr,
                                 szName: this->iszVal.pszValue,
                                 pSearchingEntity: nullptr,
                                 pActivator: nullptr,
                                 pCaller: nullptr,
                                 pFilter: nullptr);
              variant_t::SetEntity(this, val: EntityByName);
              return true;
            default:
              goto LABEL_49;
          }
          break;
        case FIELD_INTEGER:
          if ( newType == 1 )
          {
            this->flVal = (float)this->iVal;
            this->fieldType = FIELD_FLOAT;
            result = true;
          }
          else
          {
            if ( newType != 6 )
              goto LABEL_49;
            this->bVal = this->iVal != 0;
            this->fieldType = FIELD_BOOLEAN;
            result = true;
          }
          break;
        case FIELD_EHANDLE:
          if ( newType != 2 )
            goto LABEL_49;
          if ( CHandle<CBaseEntity>::operator!=(this: &this->eVal, val: nullptr) )
          {
            this->iVal = (int)CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->eVal)->m_iName.m_Value.pszValue;
            this->fieldType = FIELD_STRING;
          }
          result = true;
          break;
        default:
LABEL_49:
          result = false;
          break;
      }
    }
  }
  else
  {
    this->iVal = 0;
    this->fieldType = FIELD_VOID;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E91E0
// Name: protected: char const __near * variant_t::ToString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall variant_t::ToString(variant_t *this)
{
  const char *result; // eax
  CHandle<CBaseEntity> *v3; // eax
  CHandle<CBaseEntity> *v4; // eax
  const char *pszValue; // eax

  switch ( this->fieldType )
  {
    case FIELD_VOID:
      szBuf_0[0] = 0;
      return szBuf_0;
    case FIELD_FLOAT:
      V_snprintf(pDest: szBuf_0, maxLen: 512, pFormat: "%g", this->flVal);
      return szBuf_0;
    case FIELD_STRING:
      result = (const char *)this->iVal;
      if ( this->iVal == 0 )
        return locale;
      return result;
    case FIELD_VECTOR:
      V_snprintf(pDest: szBuf_0, maxLen: 512, pFormat: "[%g %g %g]", this->flVal, this->vecVal[1], this->vecVal[2]);
      return szBuf_0;
    case FIELD_INTEGER:
      V_snprintf(pDest: szBuf_0, maxLen: 512, pFormat: "%i", this->iVal);
      return szBuf_0;
    case FIELD_BOOLEAN:
      if ( this->bVal )
        V_strncpy(pDest: szBuf_0, pSrc: "true", maxLen: 512);
      else
        V_strncpy(pDest: szBuf_0, pSrc: "false", maxLen: 512);
      return szBuf_0;
    case FIELD_COLOR32:
      V_snprintf(
        pDest: szBuf_0,
        maxLen: 512,
        pFormat: "%d %d %d %d",
        this->rgbaVal.r,
        this->rgbaVal.g,
        this->rgbaVal.b,
        this->rgbaVal.a);
      return szBuf_0;
    case FIELD_EHANDLE:
      v3 = (CHandle<CBaseEntity> *)variant_t::Entity(this);
      if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v3) != nullptr )
      {
        v4 = (CHandle<CBaseEntity> *)variant_t::Entity(this);
        pszValue = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v4)->m_iName.m_Value.pszValue;
        if ( pszValue == nullptr )
        {
          V_strncpy(pDest: szBuf_0, pSrc: locale, maxLen: 512);
          return szBuf_0;
        }
      }
      else
      {
        pszValue = "<<null entity>>";
      }
      V_strncpy(pDest: szBuf_0, pSrc: pszValue, maxLen: 512);
      return szBuf_0;
    default:
      return "No conversion to string";
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E93B0
// Name: public: void variant_t::Vector3D(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall variant_t::Vector3D(variant_t *this, Vector *vec)
{
  _fieldtypes fieldType; // eax

  fieldType = this->fieldType;
  if ( fieldType == FIELD_VECTOR || fieldType == FIELD_POSITION_VECTOR )
    *vec = (Vector)this->___u0;
  else
    *vec = vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x100E9410
// Name: private: virtual bool CVariantSaveDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVariantSaveDataOps::IsEmpty(CVariantSaveDataOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  int v2; // eax
  _DWORD *i; // edx

  v2 = 0;
  if ( fieldInfo->pTypeDesc->fieldSize == 0 )
    return 1;
  for ( i = (char *)fieldInfo->pField + 16; *i == 0; i += 5 )
  {
    if ( ++v2 >= fieldInfo->pTypeDesc->fieldSize )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E9450
// Name: private: virtual void CVariantSaveDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVariantSaveDataOps::Save(
        CVariantSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  const SaveRestoreFieldInfo_t *v3; // ebx
  ISave *v4; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  variant_t *pField; // edi
  variant_savevector_t Temp; // [esp+Ch] [ebp-Ch] BYREF

  v3 = fieldInfo;
  v4 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  pField = (variant_t *)fieldInfo->pField;
  fieldInfo = *((const SaveRestoreFieldInfo_t **)fieldInfo->pField + 4);
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  switch ( pField->fieldType )
  {
    case FIELD_VOID:
      return;
    case FIELD_FLOAT:
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveFloat,
        a6: 1);
      break;
    case FIELD_STRING:
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveString,
        a6: 1);
      break;
    case FIELD_VECTOR:
      variant_t::Vector3D(this: pField, vec: &Temp.vecSave);
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: &Temp,
        a4: nullptr,
        a5: variant_t::m_SaveVector,
        a6: 1);
      break;
    case FIELD_INTEGER:
      v4->WriteFields(this: v4, a2: v3->pTypeDesc->fieldName, a3: pField, a4: nullptr, a5: variant_t::m_SaveInt, a6: 1);
      break;
    case FIELD_BOOLEAN:
      v4->WriteFields(this: v4, a2: v3->pTypeDesc->fieldName, a3: pField, a4: nullptr, a5: variant_t::m_SaveBool, a6: 1);
      break;
    case FIELD_COLOR32:
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveColor,
        a6: 1);
      break;
    case FIELD_EHANDLE:
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveEHandle,
        a6: 1);
      break;
    case FIELD_POSITION_VECTOR:
      variant_t::Vector3D(this: pField, vec: &Temp.vecSave);
      v4->WriteFields(
        this: v4,
        a2: v3->pTypeDesc->fieldName,
        a3: &Temp,
        a4: nullptr,
        a5: variant_t::m_SavePositionVector,
        a6: 1);
      break;
    default:
      _Warning(a1: "Bad type %d in saved variant_t\n", pField->fieldType);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E95B0
// Name: private: virtual void CVariantSaveDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVariantSaveDataOps::Restore(
        CVariantSaveDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  _DWORD *pField; // esi
  int v4; // eax
  __int64 v5; // [esp+8h] [ebp-14h]
  variant_savevector_t Temp; // [esp+10h] [ebp-Ch] BYREF

  pField = fieldInfo->pField;
  LODWORD(v5) = 0;
  *(_QWORD *)pField = v5;
  Temp.vecSave.y = NAN;
  *((_QWORD *)pField + 1) = *(_QWORD *)&Temp.vecSave.x;
  pField[4] = 0;
  v4 = pRestore->ReadInt(this: pRestore);
  pField[4] = v4;
  switch ( v4 )
  {
    case 0:
      return;
    case 1:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveFloat,
        a6: 1);
      break;
    case 2:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveString,
        a6: 1);
      break;
    case 3:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: &Temp,
        a4: nullptr,
        a5: variant_t::m_SaveVector,
        a6: 1);
      *(variant_savevector_t *)pField = Temp;
      pField[4] = 3;
      break;
    case 5:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveInt,
        a6: 1);
      break;
    case 6:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveBool,
        a6: 1);
      break;
    case 9:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveColor,
        a6: 1);
      break;
    case 13:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: pField,
        a4: nullptr,
        a5: variant_t::m_SaveEHandle,
        a6: 1);
      break;
    case 15:
      pRestore->ReadFields(
        this: pRestore,
        a2: fieldInfo->pTypeDesc->fieldName,
        a3: &Temp,
        a4: nullptr,
        a5: variant_t::m_SavePositionVector,
        a6: 1);
      *(variant_savevector_t *)pField = Temp;
      pField[4] = 15;
      break;
    default:
      _Warning(a1: "Bad type %d in saved variant_t\n", v4);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9760
// Name: public: void CEntityList::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityList::AddEntity(CEntityList *this, CBaseEntity *pEnt)
{
  entitem_t *m_pItemList; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  entitem_t *v6; // eax
  entitem_t *v7; // esi
  entitem_t *v8; // eax
  entitem_t *v9; // edi

  m_pItemList = this->m_pItemList;
  if ( m_pItemList != nullptr )
  {
    while ( 1 )
    {
      m_Index = m_pItemList->hEnt.m_Index;
      if ( m_pItemList->hEnt.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEnt )
        break;
      if ( m_pItemList->pNext == nullptr )
      {
        v8 = (entitem_t *)CUtlMemoryPool::Alloc(this: &g_EntListMemPool, amount: 8u);
        if ( v8 != nullptr )
        {
          v8->hEnt.m_Index = -1;
          v9 = v8;
        }
        else
        {
          v9 = nullptr;
        }
        m_pItemList->pNext = v9;
        if ( pEnt != nullptr )
          v9->hEnt.m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
        else
          v9->hEnt.m_Index = -1;
        m_pItemList->pNext->pNext = nullptr;
        ++this->m_iNumItems;
        return;
      }
      m_pItemList = m_pItemList->pNext;
    }
  }
  else
  {
    v6 = (entitem_t *)CUtlMemoryPool::Alloc(this: &g_EntListMemPool, amount: 8u);
    if ( v6 != nullptr )
    {
      v6->hEnt.m_Index = -1;
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    this->m_pItemList = v7;
    if ( pEnt != nullptr )
      v7->hEnt.m_Index = pEnt->GetRefEHandle(this: pEnt)->m_Index;
    else
      v7->hEnt.m_Index = -1;
    this->m_pItemList->pNext = nullptr;
    this->m_iNumItems = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9870
// Name: private: virtual int CEventQueueSaveLoadProxy::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventQueueSaveLoadProxy::Save(CEventQueueSaveLoadProxy *this, ISave *save)
{
  int result; // eax

  result = CBaseEntity::Save(this, save);
  if ( result != 0 )
    return CEventQueue::Save(this: &g_EventQueue, save);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E98A0
// Name: public: void CBaseEntityOutput::FireOutput(class variant_t,class CBaseEntity __near *,class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityOutput::FireOutput(
        CBaseEntityOutput *this,
        variant_t Value,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        float fDelay)
{
  CEventAction *m_ActionList; // esi
  const char *pszValue; // ecx
  double m_flDelay; // st7
  CBaseEntity *v8; // edi
  const char *v9; // eax
  const char *v10; // ecx
  const char *v11; // eax
  const char *v12; // ecx
  float v13; // xmm0_4
  const char *v14; // ebx
  const char *v15; // edi
  const char *v16; // edx
  const char *v17; // ecx
  const char *v18; // eax
  const char *v19; // ebx
  const char *v20; // edi
  const char *v21; // edx
  const char *v22; // ecx
  const char *v23; // eax
  int m_nTimesToFire; // eax
  int v25; // eax
  const char *v26; // edi
  const char *v27; // edx
  const char *v28; // ecx
  const char *v29; // eax
  CEventAction *m_pNext; // edi
  variant_t v31; // [esp+0h] [ebp-14Ch]
  float fireDelay; // [esp+14h] [ebp-138h]
  float fireDelaya; // [esp+14h] [ebp-138h]
  int m_iIDStamp; // [esp+20h] [ebp-12Ch]
  char szBuffer[256]; // [esp+30h] [ebp-11Ch] BYREF
  variant_t ValueOverride; // [esp+130h] [ebp-1Ch]
  CBaseEntityOutput *v37; // [esp+144h] [ebp-8h]
  CEventAction *prev; // [esp+148h] [ebp-4h]

  m_ActionList = this->m_ActionList;
  v37 = this;
  prev = nullptr;
  while ( m_ActionList != nullptr )
  {
    pszValue = m_ActionList->m_iParameter.pszValue;
    m_flDelay = m_ActionList->m_flDelay;
    m_iIDStamp = m_ActionList->m_iIDStamp;
    if ( pszValue != nullptr )
    {
      ValueOverride.iVal = (int)m_ActionList->m_iParameter.pszValue;
      v31.vecVal[2] = ValueOverride.vecVal[2];
      *(_QWORD *)&v31.bVal = __PAIR64__(LODWORD(ValueOverride.vecVal[1]), (unsigned int)pszValue);
      *(_QWORD *)&v31.eVal.m_Index = 0x2FFFFFFFFLL;
      v11 = m_ActionList->m_iTargetInput.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      v12 = m_ActionList->m_iTarget.pszValue;
      if ( m_ActionList->m_iTarget.pszValue == nullptr )
        v12 = locale;
      fireDelaya = m_flDelay;
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: v12,
        targetInput: v11,
        Value: v31,
        fireDelay: fireDelaya,
        pActivator,
        pCaller,
        outputID: m_iIDStamp);
      v8 = pCaller;
    }
    else
    {
      v8 = pCaller;
      v9 = m_ActionList->m_iTargetInput.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v10 = m_ActionList->m_iTarget.pszValue;
      if ( m_ActionList->m_iTarget.pszValue == nullptr )
        v10 = locale;
      fireDelay = m_flDelay + fDelay;
      CEventQueue::AddEvent(
        this: &g_EventQueue,
        target: v10,
        targetInput: v9,
        Value,
        fireDelay,
        pActivator,
        pCaller,
        outputID: m_iIDStamp);
    }
    if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    {
      v13 = m_ActionList->m_flDelay;
      if ( v13 == 0.0 )
      {
        if ( v8 != nullptr )
        {
          if ( v8->m_iName.m_Value.pszValue != nullptr )
            v19 = v8->m_iName.m_Value.pszValue;
          else
            v19 = locale;
          if ( v8->m_iClassname.pszValue != nullptr )
            v20 = v8->m_iClassname.pszValue;
          else
            v20 = locale;
        }
        else
        {
          v19 = "NULL";
          v20 = "NULL";
        }
        v21 = m_ActionList->m_iParameter.pszValue;
        if ( v21 == nullptr )
          v21 = locale;
        v22 = m_ActionList->m_iTargetInput.pszValue;
        if ( v22 == nullptr )
          v22 = locale;
        v23 = m_ActionList->m_iTarget.pszValue;
        if ( m_ActionList->m_iTarget.pszValue == nullptr )
          v23 = locale;
        V_snprintf(
          pDest: szBuffer,
          maxLen: 256,
          pFormat: "(%0.2f) output: (%s,%s) -> (%s,%s)(%s)\n",
          gpGlobals->curtime,
          v20,
          v19,
          v23,
          v22,
          v21);
        _DevMsg(a1: 2, a2: szBuffer);
      }
      else
      {
        if ( v8 != nullptr )
        {
          if ( v8->m_iName.m_Value.pszValue != nullptr )
            v14 = v8->m_iName.m_Value.pszValue;
          else
            v14 = locale;
          if ( v8->m_iClassname.pszValue != nullptr )
            v15 = v8->m_iClassname.pszValue;
          else
            v15 = locale;
        }
        else
        {
          v14 = "NULL";
          v15 = "NULL";
        }
        v16 = m_ActionList->m_iParameter.pszValue;
        if ( v16 == nullptr )
          v16 = locale;
        v17 = m_ActionList->m_iTargetInput.pszValue;
        if ( v17 == nullptr )
          v17 = locale;
        v18 = m_ActionList->m_iTarget.pszValue;
        if ( m_ActionList->m_iTarget.pszValue == nullptr )
          v18 = locale;
        V_snprintf(
          pDest: szBuffer,
          maxLen: 256,
          pFormat: "(%0.2f) output: (%s,%s) -> (%s,%s,%.1f)(%s)\n",
          gpGlobals->curtime,
          v15,
          v14,
          v18,
          v17,
          v13,
          v16);
        _DevMsg(a1: 2, a2: szBuffer);
      }
      v8 = pCaller;
    }
    if ( v8 != nullptr && (v8->m_debugOverlays & 0x10) != 0 )
      CBaseEntity::DrawOutputOverlay(this: v8, ev: m_ActionList);
    m_nTimesToFire = m_ActionList->m_nTimesToFire;
    if ( m_nTimesToFire == -1 || (v25 = m_nTimesToFire - 1, m_ActionList->m_nTimesToFire = v25, v25 != 0) )
    {
      prev = m_ActionList;
      m_ActionList = m_ActionList->m_pNext;
    }
    else
    {
      if ( v8 != nullptr )
      {
        if ( v8->m_iName.m_Value.pszValue != nullptr )
          v26 = v8->m_iName.m_Value.pszValue;
        else
          v26 = locale;
        if ( pCaller->m_iClassname.pszValue != nullptr )
          v27 = pCaller->m_iClassname.pszValue;
        else
          v27 = locale;
      }
      else
      {
        v26 = "NULL";
        v27 = "NULL";
      }
      v28 = m_ActionList->m_iTargetInput.pszValue;
      if ( v28 == nullptr )
        v28 = locale;
      v29 = m_ActionList->m_iTarget.pszValue;
      if ( m_ActionList->m_iTarget.pszValue == nullptr )
        v29 = locale;
      V_snprintf(
        pDest: szBuffer,
        maxLen: 256,
        pFormat: "Removing from action list: (%s,%s) -> (%s,%s)\n",
        v27,
        v26,
        v29,
        v28);
      _DevMsg(a1: 2, a2: szBuffer);
      if ( prev != nullptr )
        prev->m_pNext = m_ActionList->m_pNext;
      else
        v37->m_ActionList = m_ActionList->m_pNext;
      m_pNext = m_ActionList->m_pNext;
      CUtlMemoryPool::Free(this: &g_EntityListPool, memBlock: m_ActionList);
      m_ActionList = m_pNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9C00
// Name: public: void COutputEvent::FireOutput(class CBaseEntity __near *,class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COutputEvent::FireOutput(
        COutputEvent *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        float fDelay)
{
  variant_t v4; // [esp-1Ch] [ebp-38h]
  unsigned int Val_4; // [esp+Ch] [ebp-10h]
  float Val_8; // [esp+10h] [ebp-Ch]

  v4.vecVal[2] = Val_8;
  *(_QWORD *)&v4.bVal = __PAIR64__(Val_4, 0);
  *(_QWORD *)&v4.eVal.m_Index = 0xFFFFFFFFLL;
  CBaseEntityOutput::FireOutput(this, Value: v4, pActivator, pCaller, fDelay);
}

//------------------------------------------------------------------------------
// Address: 0x100E9C50
// Name: public: void CMultiInputVar::AddValue(class variant_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiInputVar::AddValue(CMultiInputVar *this, variant_t newVal, int outputID)
{
  CMultiInputVar::inputitem_t *m_InputList; // eax
  CMultiInputVar::inputitem_t *v5; // eax

  m_InputList = this->m_InputList;
  if ( this->m_InputList != nullptr )
  {
    while ( m_InputList->outputID != outputID )
    {
      m_InputList = m_InputList->next;
      if ( m_InputList == nullptr )
        goto LABEL_4;
    }
    m_InputList->value = newVal;
  }
  else
  {
LABEL_4:
    v5 = (CMultiInputVar::inputitem_t *)CUtlMemoryPool::Alloc(this: &g_EntityListPool, amount: 0x1Cu);
    if ( v5 != nullptr )
    {
      v5->value.iVal = 0;
      v5->value.eVal.m_Index = -1;
      v5->value.fieldType = FIELD_VOID;
    }
    else
    {
      v5 = nullptr;
    }
    v5->value = newVal;
    v5->outputID = outputID;
    if ( this->m_InputList != nullptr )
    {
      v5->next = this->m_InputList;
      this->m_InputList = v5;
    }
    else
    {
      this->m_InputList = v5;
      v5->next = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9CF0
// Name: private: virtual int CEventQueueSaveLoadProxy::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEventQueueSaveLoadProxy::Restore(CEventQueueSaveLoadProxy *this, IRestore *restore)
{
  int result; // eax
  int v4; // edi

  result = CBaseEntity::Restore(this, a2: (bool (__cdecl *)(const char *))restore, restore);
  if ( result != 0 )
  {
    v4 = CEventQueue::Restore(this: &g_EventQueue, restore);
    UTIL_Remove(oldObj: this);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E9D30
// Name: public: virtual void CEventQueue_SaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue_SaveRestoreBlockHandler::Restore(
        CEventQueue_SaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  if ( this->m_fDoLoad )
    CEventQueue::Restore(this: &g_EventQueue, restore: pRestore);
}

//------------------------------------------------------------------------------
// Address: 0x100E9D50
// Name: public: void CEventQueue::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventQueue::Dump(CEventQueue *this)
{
  EventQueuePrioritizedEvent_t *m_pNext; // esi
  void (*v2)(const char *, ...); // edi
  CBaseEntityList *v3; // edi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  const char *DebugName; // eax
  const char *v12; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  CEntInfo *v15; // edx
  unsigned int v16; // ecx
  int v17; // eax
  CBaseEntity **v18; // eax
  const char *v19; // edi
  variant_t *p_m_VariantValue; // ecx
  const char *iVal; // eax
  const char *pszValue; // edx
  const char *v23; // ecx
  const char *v24; // [esp+18h] [ebp-14h]
  EventQueuePrioritizedEvent_t *next; // [esp+28h] [ebp-4h]

  m_pNext = this->m_Events.m_pNext;
  v2 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Dumping event queue. Current time is: %.2f\n", gpGlobals->curtime);
  if ( m_pNext != nullptr )
  {
    do
    {
      v3 = g_pEntityList;
      next = m_pNext->m_pNext;
      m_Index = m_pNext->m_pCaller.m_Index;
      if ( m_Index != -1
        && (v5 = (unsigned __int16)m_Index,
            v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
            v7 = HIWORD(m_Index),
            v6->m_SerialNumber == v7)
        && v6->m_pEntity != nullptr )
      {
        v8 = v5;
        v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
        v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
        if ( v9 )
          DebugName = CBaseEntity::GetDebugName(this: *v10);
        else
          DebugName = CBaseEntity::GetDebugName(this: nullptr);
        v3 = g_pEntityList;
        v12 = DebugName;
      }
      else
      {
        v12 = "None";
      }
      v13 = m_pNext->m_pActivator.m_Index;
      if ( v13 != -1
        && (v14 = (unsigned __int16)v13,
            v15 = &v3->m_EntPtrArray[(unsigned __int16)v13],
            v16 = HIWORD(v13),
            v15->m_SerialNumber == v16)
        && v15->m_pEntity != nullptr )
      {
        v17 = v14;
        v9 = v3->m_EntPtrArray[v17].m_SerialNumber == v16;
        v18 = (CBaseEntity **)&v3->m_EntPtrArray[v17];
        if ( v9 )
          v19 = CBaseEntity::GetDebugName(this: *v18);
        else
          v19 = CBaseEntity::GetDebugName(this: nullptr);
      }
      else
      {
        v19 = "None";
      }
      p_m_VariantValue = &m_pNext->m_VariantValue;
      if ( m_pNext->m_VariantValue.fieldType == FIELD_STRING )
      {
        iVal = (const char *)p_m_VariantValue->iVal;
        if ( p_m_VariantValue->iVal == 0 )
          iVal = locale;
      }
      else
      {
        iVal = variant_t::ToString(this: p_m_VariantValue);
      }
      pszValue = m_pNext->m_iTargetInput.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v23 = m_pNext->m_iTarget.pszValue;
      if ( v23 == nullptr )
        v23 = locale;
      v24 = v19;
      v2 = (void (*)(const char *, ...))_Msg;
      _Msg(
        a1: "   (%.2f) Target: '%s', Input: '%s', Parameter '%s'. Activator: '%s', Caller '%s'.  \n",
        m_pNext->m_flFireTime,
        v23,
        pszValue,
        iVal,
        v24,
        v12);
      m_pNext = next;
    }
    while ( next != nullptr );
  }
  v2(a1: "Finished dump.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100E9EC0
// Name: void CC_DumpEventQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DumpEventQueue()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    CEventQueue::Dump(this: &g_EventQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10400B80
// Name: CEventAction_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEventAction_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEventAction>();
  CEventAction_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400BC0
// Name: CBaseEntityOutput_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseEntityOutput_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseEntityOutput>();
  CBaseEntityOutput_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400C60
// Name: CEventQueue_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEventQueue_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEventQueue>();
  CEventQueue_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400C70
// Name: EventQueuePrioritizedEvent_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *EventQueuePrioritizedEvent_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<EventQueuePrioritizedEvent_t>();
  EventQueuePrioritizedEvent_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400B90
// Name: _dynamic_initializer_for__g_EntityListPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityListPool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EntityListPool,
    blockSize: 28,
    numElements: 512,
    growMode: 1,
    pszAllocOwner: "g_EntityListPool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EntityListPool__);
}

//------------------------------------------------------------------------------
// Address: 0x10400BD0
// Name: _dynamic_initializer_for__EventQueuePrioritizedEvent_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__EventQueuePrioritizedEvent_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &EventQueuePrioritizedEvent_t::s_Allocator,
    blockSize: 56,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: "EventQueuePrioritizedEvent_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__EventQueuePrioritizedEvent_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10400C00
// Name: _dynamic_initializer_for__g_EventQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventQueue__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EventQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10400C80
// Name: _dynamic_initializer_for__g_EntListMemPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntListMemPool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EntListMemPool,
    blockSize: 8,
    numElements: 256,
    growMode: 0,
    pszAllocOwner: "g_EntListMemPool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EntListMemPool__);
}
