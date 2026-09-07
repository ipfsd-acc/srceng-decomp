// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/entitylist_base.cpp
// Functions: 7
// ============================================================

#include "game\shared\entitylist_base.h"

//------------------------------------------------------------------------------
// Address: 0x100D1190
// Name: public: void CBaseEntityList::CEntInfoList::AddToTail(class CEntInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::CEntInfoList::AddToTail(CBaseEntityList::CEntInfoList *this, CEntInfo *pElement)
{
  CEntInfo *m_pPrev; // edx
  CEntInfo *m_pNext; // edx
  CEntInfo *v4; // edx

  m_pPrev = pElement->m_pPrev;
  if ( m_pPrev != pElement )
  {
    if ( m_pPrev != nullptr )
      m_pPrev->m_pNext = pElement->m_pNext;
    else
      this->m_pHead = pElement->m_pNext;
    m_pNext = pElement->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = pElement->m_pPrev;
    else
      this->m_pTail = pElement->m_pPrev;
    pElement->m_pNext = pElement;
    pElement->m_pPrev = pElement;
  }
  pElement->m_pNext = nullptr;
  pElement->m_pPrev = this->m_pTail;
  this->m_pTail = pElement;
  v4 = pElement->m_pPrev;
  if ( v4 != nullptr )
    v4->m_pNext = pElement;
  else
    this->m_pHead = pElement;
}

//------------------------------------------------------------------------------
// Address: 0x100D11F0
// Name: public: CBaseEntityList::CBaseEntityList(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntityList *__thiscall CBaseEntityList::CBaseEntityList(CBaseEntityList *this)
{
  CEntInfo *m_EntPtrArray; // esi
  int i; // ebx
  CEntInfo **p_m_pPrev; // eax
  int j; // esi
  CEntInfo *v6; // ecx
  CEntInfo *v7; // ecx
  CEntInfo *v8; // ecx

  this->__vftable = (CBaseEntityList_vtbl *)&CBaseEntityList::`vftable';
  this->m_activeList.m_pHead = nullptr;
  this->m_activeList.m_pTail = nullptr;
  this->m_freeNonNetworkableList.m_pHead = nullptr;
  this->m_freeNonNetworkableList.m_pTail = nullptr;
  m_EntPtrArray = this->m_EntPtrArray;
  for ( i = 0x2000; i != 0; --i )
  {
    m_EntPtrArray->m_pNext = m_EntPtrArray;
    m_EntPtrArray->m_pPrev = m_EntPtrArray;
    m_EntPtrArray->m_SerialNumber = rand((IUniformRandomStream *)this) & 0x7FFF;
    m_EntPtrArray->m_pEntity = nullptr;
    ++m_EntPtrArray;
  }
  p_m_pPrev = &this->m_EntPtrArray[2049].m_pPrev;
  for ( j = 6143; j != 0; --j )
  {
    v6 = *p_m_pPrev;
    if ( *p_m_pPrev != (CEntInfo *)(p_m_pPrev - 2) )
    {
      if ( v6 != nullptr )
        v6->m_pNext = p_m_pPrev[1];
      else
        this->m_freeNonNetworkableList.m_pHead = p_m_pPrev[1];
      v7 = p_m_pPrev[1];
      if ( v7 != nullptr )
        v7->m_pPrev = *p_m_pPrev;
      else
        this->m_freeNonNetworkableList.m_pTail = *p_m_pPrev;
      p_m_pPrev[1] = (CEntInfo *)(p_m_pPrev - 2);
      *p_m_pPrev = (CEntInfo *)(p_m_pPrev - 2);
    }
    p_m_pPrev[1] = nullptr;
    *p_m_pPrev = this->m_freeNonNetworkableList.m_pTail;
    v8 = (CEntInfo *)(p_m_pPrev - 2);
    this->m_freeNonNetworkableList.m_pTail = (CEntInfo *)(p_m_pPrev - 2);
    if ( *p_m_pPrev != nullptr )
      (*p_m_pPrev)->m_pNext = v8;
    else
      this->m_freeNonNetworkableList.m_pHead = v8;
    p_m_pPrev += 4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D12D0
// Name: private: void CBaseEntityList::RemoveEntityAtSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::RemoveEntityAtSlot(CBaseEntityList *this, int iSlot)
{
  int v2; // ebx
  IHandleEntity *m_pEntity; // ecx
  CEntInfo *v5; // esi
  CEntInfo *m_pPrev; // eax
  CEntInfo *m_pNext; // eax

  v2 = iSlot;
  m_pEntity = this->m_EntPtrArray[iSlot].m_pEntity;
  v5 = &this->m_EntPtrArray[iSlot];
  if ( m_pEntity != nullptr )
  {
    iSlot = -1;
    m_pEntity->SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)&iSlot);
    ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, int))this->OnRemoveEntity)(
      a1: this,
      a2: v5->m_pEntity,
      a3: v2 | (v5->m_SerialNumber << 16));
    v5->m_SerialNumber = ((unsigned __int16)v5->m_SerialNumber + 1) & 0x7FFF;
    m_pPrev = v5->m_pPrev;
    v5->m_pEntity = nullptr;
    if ( m_pPrev != v5 )
    {
      if ( m_pPrev != nullptr )
        m_pPrev->m_pNext = v5->m_pNext;
      else
        this->m_activeList.m_pHead = v5->m_pNext;
      m_pNext = v5->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = v5->m_pPrev;
      else
        this->m_activeList.m_pTail = v5->m_pPrev;
      v5->m_pNext = v5;
      v5->m_pPrev = v5;
    }
    if ( v2 >= 2048 )
      CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_freeNonNetworkableList, pElement: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1390
// Name: public: CBaseEntityList::~CBaseEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::~CBaseEntityList(CBaseEntityList *this)
{
  CEntInfo *m_pHead; // eax
  int v3; // ebx
  CEntInfo *v4; // esi
  IHandleEntity *m_pEntity; // ecx
  CEntInfo *m_pPrev; // eax
  CEntInfo *m_pNext; // eax
  CEntInfo *v8; // eax
  CEntInfo *v9; // eax
  CEntInfo *v10; // eax
  CEntInfo *pNext; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h] BYREF

  m_pHead = this->m_activeList.m_pHead;
  this->__vftable = (CBaseEntityList_vtbl *)&CBaseEntityList::`vftable';
  if ( m_pHead != nullptr )
  {
    do
    {
      v3 = ((char *)m_pHead - (char *)this - 4) >> 4;
      v4 = &this->m_EntPtrArray[v3];
      pNext = m_pHead->m_pNext;
      m_pEntity = v4->m_pEntity;
      if ( v4->m_pEntity != nullptr )
      {
        v12 = -1;
        m_pEntity->SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)&v12);
        ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, int))this->OnRemoveEntity)(
          a1: this,
          a2: this->m_EntPtrArray[v3].m_pEntity,
          a3: v3 | (this->m_EntPtrArray[v3].m_SerialNumber << 16));
        this->m_EntPtrArray[v3].m_SerialNumber = ((unsigned __int16)this->m_EntPtrArray[v3].m_SerialNumber + 1) & 0x7FFF;
        m_pPrev = this->m_EntPtrArray[v3].m_pPrev;
        v4->m_pEntity = nullptr;
        if ( m_pPrev != v4 )
        {
          if ( m_pPrev != nullptr )
            m_pPrev->m_pNext = this->m_EntPtrArray[v3].m_pNext;
          else
            this->m_activeList.m_pHead = this->m_EntPtrArray[v3].m_pNext;
          m_pNext = this->m_EntPtrArray[v3].m_pNext;
          if ( m_pNext != nullptr )
            m_pNext->m_pPrev = this->m_EntPtrArray[v3].m_pPrev;
          else
            this->m_activeList.m_pTail = this->m_EntPtrArray[v3].m_pPrev;
          this->m_EntPtrArray[v3].m_pNext = &this->m_EntPtrArray[v3];
          this->m_EntPtrArray[v3].m_pPrev = &this->m_EntPtrArray[v3];
        }
        if ( v3 >= 2048 )
        {
          v8 = this->m_EntPtrArray[v3].m_pPrev;
          if ( v8 != v4 )
          {
            if ( v8 != nullptr )
              v8->m_pNext = this->m_EntPtrArray[v3].m_pNext;
            else
              this->m_freeNonNetworkableList.m_pHead = this->m_EntPtrArray[v3].m_pNext;
            v9 = this->m_EntPtrArray[v3].m_pNext;
            if ( v9 != nullptr )
              v9->m_pPrev = this->m_EntPtrArray[v3].m_pPrev;
            else
              this->m_freeNonNetworkableList.m_pTail = this->m_EntPtrArray[v3].m_pPrev;
            this->m_EntPtrArray[v3].m_pNext = &this->m_EntPtrArray[v3];
            this->m_EntPtrArray[v3].m_pPrev = &this->m_EntPtrArray[v3];
          }
          this->m_EntPtrArray[v3].m_pNext = nullptr;
          this->m_EntPtrArray[v3].m_pPrev = this->m_freeNonNetworkableList.m_pTail;
          this->m_freeNonNetworkableList.m_pTail = v4;
          v10 = this->m_EntPtrArray[v3].m_pPrev;
          if ( v10 != nullptr )
            v10->m_pNext = v4;
          else
            this->m_freeNonNetworkableList.m_pHead = v4;
        }
      }
      m_pHead = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D14D0
// Name: public: class CBaseHandle CBaseEntityList::AddNetworkableEntity(class IHandleEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CBaseEntityList::AddNetworkableEntity(
        CBaseEntityList *this,
        CBaseHandle *result,
        IHandleEntity *pEnt,
        int index,
        int iForcedSerialNum)
{
  CEntInfo *v6; // edi

  v6 = &this->m_EntPtrArray[index];
  v6->m_pEntity = pEnt;
  if ( iForcedSerialNum != -1 )
    this->m_EntPtrArray[index].m_SerialNumber = iForcedSerialNum;
  CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_activeList, pElement: v6);
  result->m_Index = index | (v6->m_SerialNumber << 16);
  pEnt->SetRefEHandle(this: pEnt, a2: result);
  ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, unsigned int))this->OnAddEntity)(
    a1: this,
    a2: pEnt,
    a3: result->m_Index);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D1530
// Name: public: class CBaseHandle CBaseEntityList::AddNonNetworkableEntity(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CBaseEntityList::AddNonNetworkableEntity(
        CBaseEntityList *this,
        CBaseHandle *result,
        IHandleEntity *pEnt)
{
  CEntInfo *m_pHead; // eax
  CEntInfo *m_pPrev; // ecx
  CEntInfo *m_pNext; // ecx
  CEntInfo *v8; // edi
  int iSlot; // [esp+Ch] [ebp-4h]

  m_pHead = this->m_freeNonNetworkableList.m_pHead;
  if ( m_pHead != nullptr )
  {
    m_pPrev = m_pHead->m_pPrev;
    if ( m_pPrev != m_pHead )
    {
      if ( m_pPrev != nullptr )
        m_pPrev->m_pNext = m_pHead->m_pNext;
      else
        this->m_freeNonNetworkableList.m_pHead = m_pHead->m_pNext;
      m_pNext = m_pHead->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = m_pHead->m_pPrev;
      else
        this->m_freeNonNetworkableList.m_pTail = m_pHead->m_pPrev;
      m_pHead->m_pNext = m_pHead;
      m_pHead->m_pPrev = m_pHead;
    }
    iSlot = ((char *)m_pHead - (char *)this - 4) >> 4;
    v8 = &this->m_EntPtrArray[iSlot];
    v8->m_pEntity = pEnt;
    CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_activeList, pElement: v8);
    result->m_Index = iSlot | (this->m_EntPtrArray[iSlot].m_SerialNumber << 16);
    pEnt->SetRefEHandle(this: pEnt, a2: result);
    ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, unsigned int))this->OnAddEntity)(
      a1: this,
      a2: pEnt,
      a3: result->m_Index);
    return result;
  }
  else
  {
    _Warning(a1: "CBaseEntityList::AddNonNetworkableEntity: no free slots!\n");
    result->m_Index = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1600
// Name: public: void CBaseEntityList::RemoveEntity(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::RemoveEntity(CBaseEntityList *this, CBaseHandle handle)
{
  if ( handle.m_Index == -1 )
    CBaseEntityList::RemoveEntityAtSlot(this, iSlot: 0x1FFF);
  else
    CBaseEntityList::RemoveEntityAtSlot(this, iSlot: LOWORD(handle.m_Index));
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1010FD90
// Name: public: void CBaseEntityList::CEntInfoList::AddToTail(class CEntInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::CEntInfoList::AddToTail(CBaseEntityList::CEntInfoList *this, CEntInfo *pElement)
{
  CEntInfo *m_pPrev; // edx
  CEntInfo *m_pNext; // edx
  CEntInfo *v4; // edx

  m_pPrev = pElement->m_pPrev;
  if ( m_pPrev != pElement )
  {
    if ( m_pPrev != nullptr )
      m_pPrev->m_pNext = pElement->m_pNext;
    else
      this->m_pHead = pElement->m_pNext;
    m_pNext = pElement->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = pElement->m_pPrev;
    else
      this->m_pTail = pElement->m_pPrev;
    pElement->m_pNext = pElement;
    pElement->m_pPrev = pElement;
  }
  pElement->m_pNext = nullptr;
  pElement->m_pPrev = this->m_pTail;
  this->m_pTail = pElement;
  v4 = pElement->m_pPrev;
  if ( v4 != nullptr )
    v4->m_pNext = pElement;
  else
    this->m_pHead = pElement;
}

//------------------------------------------------------------------------------
// Address: 0x1010FDF0
// Name: public: CBaseEntityList::CBaseEntityList(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntityList *__thiscall CBaseEntityList::CBaseEntityList(CBaseEntityList *this)
{
  CEntInfo *m_EntPtrArray; // esi
  int i; // ebx
  CEntInfo **p_m_pPrev; // eax
  int j; // esi
  CEntInfo *v6; // ecx
  CEntInfo *v7; // ecx
  CEntInfo *v8; // ecx

  this->__vftable = (CBaseEntityList_vtbl *)&CBaseEntityList::`vftable';
  this->m_activeList.m_pHead = nullptr;
  this->m_activeList.m_pTail = nullptr;
  this->m_freeNonNetworkableList.m_pHead = nullptr;
  this->m_freeNonNetworkableList.m_pTail = nullptr;
  m_EntPtrArray = this->m_EntPtrArray;
  for ( i = 0x2000; i != 0; --i )
  {
    m_EntPtrArray->m_pNext = m_EntPtrArray;
    m_EntPtrArray->m_pPrev = m_EntPtrArray;
    m_EntPtrArray->m_SerialNumber = rand() & 0x7FFF;
    m_EntPtrArray->m_pEntity = nullptr;
    ++m_EntPtrArray;
  }
  p_m_pPrev = &this->m_EntPtrArray[2049].m_pPrev;
  for ( j = 6143; j != 0; --j )
  {
    v6 = *p_m_pPrev;
    if ( *p_m_pPrev != (CEntInfo *)(p_m_pPrev - 2) )
    {
      if ( v6 != nullptr )
        v6->m_pNext = p_m_pPrev[1];
      else
        this->m_freeNonNetworkableList.m_pHead = p_m_pPrev[1];
      v7 = p_m_pPrev[1];
      if ( v7 != nullptr )
        v7->m_pPrev = *p_m_pPrev;
      else
        this->m_freeNonNetworkableList.m_pTail = *p_m_pPrev;
      p_m_pPrev[1] = (CEntInfo *)(p_m_pPrev - 2);
      *p_m_pPrev = (CEntInfo *)(p_m_pPrev - 2);
    }
    p_m_pPrev[1] = nullptr;
    *p_m_pPrev = this->m_freeNonNetworkableList.m_pTail;
    v8 = (CEntInfo *)(p_m_pPrev - 2);
    this->m_freeNonNetworkableList.m_pTail = (CEntInfo *)(p_m_pPrev - 2);
    if ( *p_m_pPrev != nullptr )
      (*p_m_pPrev)->m_pNext = v8;
    else
      this->m_freeNonNetworkableList.m_pHead = v8;
    p_m_pPrev += 6;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010FED0
// Name: private: void CBaseEntityList::RemoveEntityAtSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::RemoveEntityAtSlot(CBaseEntityList *this, int iSlot)
{
  int v2; // ebx
  IHandleEntity *m_pEntity; // ecx
  CEntInfo *v5; // esi
  CEntInfo *m_pPrev; // eax
  CEntInfo *m_pNext; // eax

  v2 = iSlot;
  m_pEntity = this->m_EntPtrArray[iSlot].m_pEntity;
  v5 = &this->m_EntPtrArray[iSlot];
  if ( m_pEntity != nullptr )
  {
    iSlot = -1;
    m_pEntity->SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)&iSlot);
    ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, int))this->OnRemoveEntity)(
      a1: this,
      a2: v5->m_pEntity,
      a3: v2 | (v5->m_SerialNumber << 16));
    v5->m_SerialNumber = ((unsigned __int16)v5->m_SerialNumber + 1) & 0x7FFF;
    m_pPrev = v5->m_pPrev;
    v5->m_pEntity = nullptr;
    if ( m_pPrev != v5 )
    {
      if ( m_pPrev != nullptr )
        m_pPrev->m_pNext = v5->m_pNext;
      else
        this->m_activeList.m_pHead = v5->m_pNext;
      m_pNext = v5->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = v5->m_pPrev;
      else
        this->m_activeList.m_pTail = v5->m_pPrev;
      v5->m_pNext = v5;
      v5->m_pPrev = v5;
    }
    if ( v2 >= 2048 )
      CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_freeNonNetworkableList, pElement: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FF80
// Name: public: CBaseEntityList::~CBaseEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::~CBaseEntityList(CBaseEntityList *this)
{
  CEntInfo *m_pHead; // ecx
  CEntInfo *m_pNext; // esi

  m_pHead = this->m_activeList.m_pHead;
  this->__vftable = (CBaseEntityList_vtbl *)&CBaseEntityList::`vftable';
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      CBaseEntityList::RemoveEntityAtSlot(this, iSlot: ((char *)m_pHead - (char *)this - 4) / 24);
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FFC0
// Name: public: class CBaseHandle CBaseEntityList::AddNetworkableEntity(class IHandleEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CBaseEntityList::AddNetworkableEntity(
        CBaseEntityList *this,
        CBaseHandle *result,
        IHandleEntity *pEnt,
        int index,
        int iForcedSerialNum)
{
  CEntInfo *v6; // edi

  v6 = &this->m_EntPtrArray[index];
  v6->m_pEntity = pEnt;
  if ( iForcedSerialNum != -1 )
    this->m_EntPtrArray[index].m_SerialNumber = iForcedSerialNum;
  CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_activeList, pElement: v6);
  result->m_Index = index | (v6->m_SerialNumber << 16);
  pEnt->SetRefEHandle(this: pEnt, a2: result);
  ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, unsigned int))this->OnAddEntity)(
    a1: this,
    a2: pEnt,
    a3: result->m_Index);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110020
// Name: public: class CBaseHandle CBaseEntityList::AddNonNetworkableEntity(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHandle *__thiscall CBaseEntityList::AddNonNetworkableEntity(
        CBaseEntityList *this,
        CBaseHandle *result,
        IHandleEntity *pEnt)
{
  CEntInfo *m_pHead; // eax
  CEntInfo *m_pPrev; // ecx
  CEntInfo *m_pNext; // ecx
  int v8; // esi
  CEntInfo *v9; // [esp-4h] [ebp-10h]

  m_pHead = this->m_freeNonNetworkableList.m_pHead;
  if ( m_pHead != nullptr )
  {
    m_pPrev = m_pHead->m_pPrev;
    if ( m_pPrev != m_pHead )
    {
      if ( m_pPrev != nullptr )
        m_pPrev->m_pNext = m_pHead->m_pNext;
      else
        this->m_freeNonNetworkableList.m_pHead = m_pHead->m_pNext;
      m_pNext = m_pHead->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = m_pHead->m_pPrev;
      else
        this->m_freeNonNetworkableList.m_pTail = m_pHead->m_pPrev;
      m_pHead->m_pNext = m_pHead;
      m_pHead->m_pPrev = m_pHead;
    }
    v8 = ((char *)m_pHead - (char *)this - 4) / 24;
    v9 = &this->m_EntPtrArray[v8];
    v9->m_pEntity = pEnt;
    CBaseEntityList::CEntInfoList::AddToTail(this: &this->m_activeList, pElement: v9);
    result->m_Index = v8 | (this->m_EntPtrArray[v8].m_SerialNumber << 16);
    pEnt->SetRefEHandle(this: pEnt, a2: result);
    ((void (__thiscall *)(CBaseEntityList *, IHandleEntity *, unsigned int))this->OnAddEntity)(
      a1: this,
      a2: pEnt,
      a3: result->m_Index);
    return result;
  }
  else
  {
    _Warning(a1: "CBaseEntityList::AddNonNetworkableEntity: no free slots!\n");
    result->m_Index = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101100F0
// Name: public: void CBaseEntityList::RemoveEntity(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityList::RemoveEntity(CBaseEntityList *this, CBaseHandle handle)
{
  if ( handle.m_Index == -1 )
    CBaseEntityList::RemoveEntityAtSlot(this, iSlot: 0x1FFF);
  else
    CBaseEntityList::RemoveEntityAtSlot(this, iSlot: LOWORD(handle.m_Index));
}

} // namespace server
