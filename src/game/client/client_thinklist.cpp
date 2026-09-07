// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/client_thinklist.cpp
// Functions: 24
// ============================================================

#include "game\client\client_thinklist.h"

//------------------------------------------------------------------------------
// Address: 0x100A26F0
// Name: public: virtual bool CClientThinkList::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientThinkList::Init(CClientThinkList *this)
{
  this->m_nIterEnum = 0;
  this->m_bInThinkLoop = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2700
// Name: public: virtual void CClientThinkList::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::LevelInitPreEntity(CClientThinkList *this)
{
  this->m_nIterEnum = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2810
// Name: private: void CClientThinkList::AddEntityToFrameThinkList(struct CClientThinkList::ThinkEntry_t __near *,bool,int __near &,struct CClientThinkList::ThinkEntry_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::AddEntityToFrameThinkList(
        CClientThinkList *this,
        CClientThinkList::ThinkEntry_t *pEntry,
        bool bAlwaysChain,
        int *nCount,
        CClientThinkList::ThinkEntry_t **ppFrameThinkList)
{
  CClientThinkList::ThinkEntry_t *v5; // esi
  float m_flNextClientThink; // xmm0_4
  C_BaseEntity *BaseEntityFromHandle; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v11; // esi
  unsigned __int16 v12; // ax
  bool bThinkThisInterval; // [esp+Fh] [ebp-1h]

  v5 = pEntry;
  if ( pEntry->m_nIterEnum != this->m_nIterEnum )
  {
    m_flNextClientThink = pEntry->m_flNextClientThink;
    if ( m_flNextClientThink == -1293.0 || *(float *)(gpGlobals.m_Index + 12) >= m_flNextClientThink )
    {
      bThinkThisInterval = true;
    }
    else
    {
      bThinkThisInterval = false;
      if ( !bAlwaysChain )
        return;
    }
    BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                             this: (CClientEntityList *)cl_entitylist.m_Index,
                             hEnt: pEntry->m_hEnt);
    if ( BaseEntityFromHandle != nullptr )
    {
      m_Index = BaseEntityFromHandle->m_pMoveParent.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          v11 = m_pEntity + 3;
          if ( m_pEntity[3].GetRefEHandle(this: m_pEntity + 3) != (const CBaseHandle *)0xFFFF )
          {
            v12 = (unsigned __int16)v11->GetRefEHandle(this: v11);
            CClientThinkList::AddEntityToFrameThinkList(
              this,
              pEntry: &this->m_ThinkEntries.m_Memory.m_pMemory[v12].m_Element,
              bAlwaysChain: true,
              nCount,
              ppFrameThinkList);
          }
          v5 = pEntry;
        }
      }
    }
    if ( bThinkThisInterval )
    {
      v5->m_nIterEnum = this->m_nIterEnum;
      ppFrameThinkList[(*nCount)++] = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2910
// Name: private: void CClientThinkList::CleanUpDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::CleanUpDeleteList(CClientThinkList *this)
{
  int v2; // edi
  unsigned int m_Index; // esi
  C_BaseEntity *BaseEntityFromHandle; // eax
  IClientThinkable *ClientThinkableFromHandle; // eax
  int nThinkCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nThinkCount = this->m_aDeleteList.m_Size;
  if ( nThinkCount <= 0 )
  {
    this->m_aDeleteList.m_Size = 0;
  }
  else
  {
    do
    {
      m_Index = this->m_aDeleteList.m_Memory.m_pMemory[v2].m_Index;
      if ( m_Index != -1 )
      {
        BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: (CBaseHandle)m_Index);
        if ( BaseEntityFromHandle != nullptr )
          C_BaseEntity::SetRemovalFlag(this: BaseEntityFromHandle, bRemove: false);
        ClientThinkableFromHandle = CClientEntityList::GetClientThinkableFromHandle(
                                      this: (CClientEntityList *)cl_entitylist.m_Index,
                                      hEnt: (CBaseHandle)m_Index);
        if ( ClientThinkableFromHandle != nullptr )
          ClientThinkableFromHandle->Release(this: ClientThinkableFromHandle);
      }
      ++v2;
    }
    while ( v2 < nThinkCount );
    this->m_aDeleteList.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2C10
// Name: public: virtual char const __near * CClientThinkList::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientThinkList::Name(CClientThinkList *this)
{
  return "CClientThinkList";
}

//------------------------------------------------------------------------------
// Address: 0x100A2C90
// Name: private: void CClientThinkList::RemoveThinkable(class CClientThinkHandlePtr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::RemoveThinkable(CClientThinkList *this, struct CClientThinkHandlePtr *hThink)
{
  CUtlVector<CClientThinkList::ThinkListChanges_t,CUtlMemory<CClientThinkList::ThinkListChanges_t,int> > *p_m_aChangeList; // esi
  int v3; // eax
  CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *p_m_ThinkEntries; // edi
  int v5; // esi
  IClientThinkable *ClientThinkableFromHandle; // eax

  if ( hThink != (struct CClientThinkHandlePtr *)0xFFFF )
  {
    if ( this->m_bInThinkLoop )
    {
      p_m_aChangeList = &this->m_aChangeList;
      v3 = CUtlVector<CClientThinkList::ThinkListChanges_t,CUtlMemory<CClientThinkList::ThinkListChanges_t,int>>::InsertBefore(
             this: &this->m_aChangeList,
             elem: this->m_aChangeList.m_Size);
      p_m_aChangeList->m_Memory.m_pMemory[v3].m_hEnt.m_Index = -1;
      p_m_aChangeList->m_Memory.m_pMemory[v3].m_hThink = hThink;
      p_m_aChangeList->m_Memory.m_pMemory[v3].m_flNextTime = -1.0;
    }
    else
    {
      p_m_ThinkEntries = &this->m_ThinkEntries;
      v5 = (unsigned __int16)hThink;
      ClientThinkableFromHandle = CClientEntityList::GetClientThinkableFromHandle(
                                    this: (CClientEntityList *)cl_entitylist.m_Index,
                                    hEnt: this->m_ThinkEntries.m_Memory.m_pMemory[v5].m_Element.m_hEnt);
      if ( ClientThinkableFromHandle != nullptr )
        ClientThinkableFromHandle->SetThinkHandle(
          this: ClientThinkableFromHandle,
          a2: (struct CClientThinkHandlePtr *)0xFFFF);
      CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_ThinkEntries,
        elem: (unsigned __int16)hThink);
      p_m_ThinkEntries->m_Memory.m_pMemory[v5].m_Next = p_m_ThinkEntries->m_FirstFree;
      p_m_ThinkEntries->m_FirstFree = (unsigned __int16)hThink;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2D40
// Name: public: void CClientThinkList::RemoveThinkable(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::RemoveThinkable(CClientThinkList *this, CBaseHandle hEnt)
{
  IClientThinkable *ClientThinkableFromHandle; // eax
  struct CClientThinkHandlePtr *v4; // eax

  ClientThinkableFromHandle = CClientEntityList::GetClientThinkableFromHandle(
                                this: (CClientEntityList *)cl_entitylist.m_Index,
                                hEnt);
  if ( ClientThinkableFromHandle != nullptr )
  {
    v4 = ClientThinkableFromHandle->GetThinkHandle(this: ClientThinkableFromHandle);
    if ( v4 != (struct CClientThinkHandlePtr *)0xFFFF )
      CClientThinkList::RemoveThinkable(this, hThink: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2D80
// Name: private: void CClientThinkList::PerformThinkFunction(struct CClientThinkList::ThinkEntry_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::PerformThinkFunction(
        CClientThinkList *this,
        CClientThinkList::ThinkEntry_t *pEntry,
        float flCurtime)
{
  IClientThinkable *ClientThinkableFromHandle; // ecx
  IClientThinkable *v5; // eax
  struct CClientThinkHandlePtr *v6; // eax
  float m_flNextClientThink; // xmm0_4

  ClientThinkableFromHandle = CClientEntityList::GetClientThinkableFromHandle(
                                this: (CClientEntityList *)cl_entitylist.m_Index,
                                hEnt: pEntry->m_hEnt);
  if ( ClientThinkableFromHandle != nullptr )
  {
    m_flNextClientThink = pEntry->m_flNextClientThink;
    if ( m_flNextClientThink != -1293.0 )
    {
      if ( m_flNextClientThink == 3.4028235e38 )
      {
        CClientThinkList::RemoveThinkable(this, hEnt: pEntry->m_hEnt);
        pEntry->m_flLastClientThink = flCurtime;
        return;
      }
      pEntry->m_flNextClientThink = 3.4028235e38;
    }
    ClientThinkableFromHandle->ClientThink(this: ClientThinkableFromHandle);
    pEntry->m_flLastClientThink = flCurtime;
  }
  else
  {
    v5 = CClientEntityList::GetClientThinkableFromHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           hEnt: pEntry->m_hEnt);
    if ( v5 != nullptr )
    {
      v6 = v5->GetThinkHandle(this: v5);
      if ( v6 != (struct CClientThinkHandlePtr *)0xFFFF )
        CClientThinkList::RemoveThinkable(this, hThink: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2E80
// Name: public: void CClientThinkList::SetNextClientThink(class CBaseHandle,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::SetNextClientThink(CClientThinkList *this, CBaseHandle hEnt, float flNextTime)
{
  IClientThinkable *ClientThinkableFromHandle; // eax
  struct CClientThinkHandlePtr *v5; // eax
  IClientThinkable *v6; // eax
  IClientThinkable *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  CBaseHandle *p_m_hEnt; // eax

  if ( flNextTime == -1.0 )
  {
    ClientThinkableFromHandle = CClientEntityList::GetClientThinkableFromHandle(
                                  this: (CClientEntityList *)cl_entitylist.m_Index,
                                  hEnt);
    if ( ClientThinkableFromHandle != nullptr )
    {
      v5 = ClientThinkableFromHandle->GetThinkHandle(this: ClientThinkableFromHandle);
      if ( v5 != (struct CClientThinkHandlePtr *)0xFFFF )
        CClientThinkList::RemoveThinkable(this, hThink: v5);
    }
  }
  else
  {
    v6 = CClientEntityList::GetClientThinkableFromHandle(this: (CClientEntityList *)cl_entitylist.m_Index, hEnt);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = (int)v6->GetThinkHandle(this: v6);
      v9 = v8;
      if ( this->m_bInThinkLoop )
      {
        v10 = CUtlVector<CClientThinkList::ThinkListChanges_t,CUtlMemory<CClientThinkList::ThinkListChanges_t,int>>::InsertBefore(
                this: &this->m_aChangeList,
                elem: this->m_aChangeList.m_Size);
        this->m_aChangeList.m_Memory.m_pMemory[v10].m_hEnt = hEnt;
        this->m_aChangeList.m_Memory.m_pMemory[v10].m_hThink = (struct CClientThinkHandlePtr *)v9;
        this->m_aChangeList.m_Memory.m_pMemory[v10].m_flNextTime = flNextTime;
      }
      else
      {
        if ( v8 == 0xFFFF )
        {
          v9 = (unsigned __int16)CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_ThinkEntries);
          v7->SetThinkHandle(this: v7, a2: (struct CClientThinkHandlePtr *)v9);
          p_m_hEnt = &this->m_ThinkEntries.m_Memory.m_pMemory[v9].m_Element.m_hEnt;
          p_m_hEnt->m_Index = hEnt.m_Index;
          p_m_hEnt[3].m_Index = -1;
          p_m_hEnt[2].m_Index = 0;
        }
        this->m_ThinkEntries.m_Memory.m_pMemory[(unsigned __int16)v9].m_Element.m_flNextClientThink = flNextTime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2F90
// Name: public: void CClientThinkList::PerformThinkFunctions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientThinkList::PerformThinkFunctions(CClientThinkList *this)
{
  int m_ElementCount; // eax
  void *v3; // esp
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *m_pMemory; // edi
  int m_Int64_high; // ebx
  int v7; // edx
  CClientThinkList::ThinkEntry_t *v8; // edi
  float m_flNextClientThink; // xmm0_4
  C_BaseEntity *BaseEntityFromHandle; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v13; // ebx
  unsigned __int16 v14; // ax
  CClientThinkList::ThinkEntry_t **v15; // ecx
  int i; // edi
  int v17; // ebx
  CClientThinkList::ThinkEntry_t **v18; // edi
  C_BaseEntity *v19; // eax
  IClientNetworkable *v20; // edi
  char *DebugName; // eax
  int v22; // eax
  int m_Size; // eax
  char *v24; // eax
  struct CClientThinkHandlePtr *v25; // edx
  int v26; // ecx
  bool v27; // zf
  float v28; // xmm0_4
  int v29; // ebx
  int m_nAllocationCount; // eax
  CClientThinkList::ThinkListChanges_t *v31; // ecx
  int v32; // eax
  int v33; // ebx
  CClientThinkList::ThinkListChanges_t *v34; // eax
  const char *v35; // [esp-4h] [ebp-50h]
  double v36; // [esp+0h] [ebp-4Ch]
  double v37; // [esp+0h] [ebp-4Ch]
  int v38; // [esp+8h] [ebp-44h] BYREF
  CBaseHandle hEnt[2]; // [esp+14h] [ebp-38h]
  unsigned __int64 v40; // [esp+1Ch] [ebp-30h]
  unsigned __int64 v41; // [esp+24h] [ebp-28h]
  __int64 v42; // [esp+2Ch] [ebp-20h] BYREF
  CFastTimer *p_fastTimer; // [esp+34h] [ebp-18h]
  struct CClientThinkHandlePtr *hThink; // [esp+38h] [ebp-14h]
  CFastTimer fastTimer; // [esp+3Ch] [ebp-10h] BYREF
  CClientThinkList::ThinkEntry_t **ppThinkEntryList; // [esp+44h] [ebp-8h]
  int nThinkCount; // [esp+48h] [ebp-4h] BYREF

  m_ElementCount = this->m_ThinkEntries.m_ElementCount;
  if ( this->m_ThinkEntries.m_ElementCount != 0 )
  {
    ++this->m_nIterEnum;
    v3 = alloca(4 * m_ElementCount);
    m_Head = this->m_ThinkEntries.m_Head;
    ppThinkEntryList = (CClientThinkList::ThinkEntry_t **)&v38;
    for ( nThinkCount = 0;
          m_Head != 0xFFFF;
          m_Head = *(unsigned __int16 *)((char *)&this->m_ThinkEntries.m_Memory.m_pMemory->m_Next + m_Int64_high) )
    {
      m_pMemory = this->m_ThinkEntries.m_Memory.m_pMemory;
      m_Int64_high = 20 * m_Head;
      v7 = *(int *)((char *)&m_pMemory->m_Element.m_nIterEnum + m_Int64_high);
      v8 = (CClientThinkList::ThinkEntry_t *)((char *)&m_pMemory->m_Element + m_Int64_high);
      HIDWORD(fastTimer.m_Duration.m_Int64) = m_Int64_high;
      if ( v7 != this->m_nIterEnum )
      {
        m_flNextClientThink = v8->m_flNextClientThink;
        if ( m_flNextClientThink == -1293.0 || *(float *)(gpGlobals.m_Index + 12) >= m_flNextClientThink )
        {
          BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                   this: (CClientEntityList *)cl_entitylist.m_Index,
                                   hEnt: v8->m_hEnt);
          if ( BaseEntityFromHandle != nullptr )
          {
            m_Index = BaseEntityFromHandle->m_pMoveParent.m_Index;
            if ( m_Index != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
              if ( m_pEntity != nullptr )
              {
                v13 = m_pEntity + 3;
                if ( m_pEntity[3].GetRefEHandle(this: m_pEntity + 3) != (const CBaseHandle *)0xFFFF )
                {
                  v14 = (unsigned __int16)v13->GetRefEHandle(this: v13);
                  CClientThinkList::AddEntityToFrameThinkList(
                    this,
                    pEntry: &this->m_ThinkEntries.m_Memory.m_pMemory[v14].m_Element,
                    bAlwaysChain: true,
                    nCount: &nThinkCount,
                    ppFrameThinkList: ppThinkEntryList);
                }
                m_Int64_high = HIDWORD(fastTimer.m_Duration.m_Int64);
              }
            }
          }
          v15 = ppThinkEntryList;
          v8->m_nIterEnum = this->m_nIterEnum;
          v15[nThinkCount++] = v8;
        }
      }
    }
    this->m_bInThinkLoop = true;
    if ( report_clientthinklist.m_pParent != nullptr && report_clientthinklist.m_pParent->m_Value.m_nValue != 0 )
    {
      v17 = 0;
      fastTimer.m_Duration.m_Int64 = 0;
      if ( nThinkCount > 0 )
      {
        p_fastTimer = &fastTimer;
        hThink = (struct CClientThinkHandlePtr *)&v42;
        do
        {
          p_fastTimer->m_Duration.m_Int64 = __rdtsc();
          v18 = ppThinkEntryList;
          CClientThinkList::PerformThinkFunction(
            this,
            pEntry: ppThinkEntryList[v17],
            flCurtime: *(float *)(gpGlobals.m_Index + 12));
          v42 = 0;
          *(_QWORD *)hThink = __rdtsc();
          fastTimer.m_Duration.m_Int64 = v42 - fastTimer.m_Duration.m_Int64;
          v19 = CClientEntityList::GetBaseEntityFromHandle(
                  this: (CClientEntityList *)cl_entitylist.m_Index,
                  hEnt: v18[v17]->m_hEnt);
          if ( v19 != nullptr )
          {
            v41 = fastTimer.m_Duration.m_Int64 & 0x7FFFFFFFFFFFFFFFLL;
            v40 = fastTimer.m_Duration.m_Int64 & 0x8000000000000000uLL;
            v20 = &v19->IClientNetworkable;
            *(double *)&hEnt[0].m_Index = (double)fastTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
            v36 = *(double *)&hEnt[0].m_Index;
            DebugName = C_BaseEntity::GetDebugName(this: v19);
            v22 = ((int (__thiscall *)(IClientNetworkable *, char *, _DWORD, _DWORD))v20->entindex)(
                    a1: v20,
                    a2: DebugName,
                    a3: LODWORD(v36),
                    a4: HIDWORD(v36));
            _Msg(a1: "Entity(%d): %s - %f\n", v22, v35, v37);
          }
          ++v17;
        }
        while ( v17 < nThinkCount );
      }
      ConVar::SetValue(this: (ConVar *)&report_clientthinklist.IConVar, value: 0);
    }
    else
    {
      for ( i = 0; i < nThinkCount; ++i )
        CClientThinkList::PerformThinkFunction(
          this,
          pEntry: ppThinkEntryList[i],
          flCurtime: *(float *)(gpGlobals.m_Index + 12));
    }
    m_Size = this->m_aChangeList.m_Size;
    this->m_bInThinkLoop = false;
    if ( m_Size > 0 )
    {
      ppThinkEntryList = nullptr;
      for ( p_fastTimer = (CFastTimer *)m_Size;
            p_fastTimer != nullptr;
            p_fastTimer = (CFastTimer *)((char *)p_fastTimer - 1) )
      {
        v24 = (char *)ppThinkEntryList + (unsigned int)this->m_aChangeList.m_Memory.m_pMemory;
        v25 = *((struct CClientThinkHandlePtr **)v24 + 1);
        hThink = v25;
        if ( v25 == (struct CClientThinkHandlePtr *)0xFFFF )
        {
          CClientThinkList::SetNextClientThink(this, hEnt: *(CBaseHandle *)v24, flNextTime: *((float *)v24 + 2));
        }
        else if ( (unsigned __int16)v25 < this->m_ThinkEntries.m_Memory.m_nAllocationCount
               && (unsigned __int16)v25 <= this->m_ThinkEntries.m_LastAlloc.index )
        {
          v26 = (unsigned __int16)v25;
          if ( this->m_ThinkEntries.m_Memory.m_pMemory[v26].m_Previous != (_WORD)v25 )
          {
            v27 = !this->m_bInThinkLoop;
            v28 = *((float *)v24 + 2);
            *((float *)&fastTimer.m_Duration.m_Int64 + 1) = v28;
            if ( v27 )
            {
              if ( v28 == -1.0 )
                CClientThinkList::RemoveThinkable(this, hThink: v25);
              else
                this->m_ThinkEntries.m_Memory.m_pMemory[v26].m_Element.m_flNextClientThink = v28;
            }
            else
            {
              v29 = this->m_aChangeList.m_Size;
              m_nAllocationCount = this->m_aChangeList.m_Memory.m_nAllocationCount;
              if ( v29 + 1 > m_nAllocationCount )
              {
                CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
                  this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_aChangeList,
                  num: v29 - m_nAllocationCount + 1);
                v28 = *((float *)&fastTimer.m_Duration.m_Int64 + 1);
                v25 = hThink;
              }
              ++this->m_aChangeList.m_Size;
              v31 = this->m_aChangeList.m_Memory.m_pMemory;
              v32 = this->m_aChangeList.m_Size - v29 - 1;
              this->m_aChangeList.m_pElements = v31;
              if ( v32 > 0 )
              {
                _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 12 * v32);
                v28 = *((float *)&fastTimer.m_Duration.m_Int64 + 1);
                v25 = hThink;
              }
              v33 = v29;
              v34 = &this->m_aChangeList.m_Memory.m_pMemory[v33];
              if ( v34 != nullptr )
                v34->m_hEnt.m_Index = -1;
              this->m_aChangeList.m_Memory.m_pMemory[v33].m_hEnt.m_Index = -1;
              this->m_aChangeList.m_Memory.m_pMemory[v33].m_hThink = v25;
              this->m_aChangeList.m_Memory.m_pMemory[v33].m_flNextTime = v28;
            }
          }
        }
        ppThinkEntryList += 3;
      }
    }
    this->m_aChangeList.m_Size = 0;
    CClientThinkList::CleanUpDeleteList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041B510
// Name: _dynamic_initializer_for__think_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__think_limit__()
{
  ConVar::ConVar(
    this: &think_limit,
    pName: "think_limit",
    pDefaultValue: "10",
    flags: 532480,
    pHelpString: "Maximum think time in milliseconds, warning is printed if this is exceeded.");
  return atexit(func: dynamic_atexit_destructor_for__think_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10433430
// Name: _dynamic_atexit_destructor_for__think_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__think_limit__()
{
  ConVar::~ConVar(this: &think_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041B540
// Name: _dynamic_initializer_for__CPortalTouchScope::m_CallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CPortalTouchScope::m_CallQueue__()
{
  CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(this: &CPortalTouchScope::m_CallQueue.m_queue);
  CPortalTouchScope::m_CallQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B560
// Name: _dynamic_initializer_for__g_DataObjectAccessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataObjectAccessSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_DataObjectAccessSystem, name: nullptr);
  g_DataObjectAccessSystem.__vftable = (CDataObjectAccessSystem_vtbl *)&CDataObjectAccessSystem::`vftable';
  _V_memset(dest: (int)g_DataObjectAccessSystem.m_Accessors, fill: nullptr, count: 0x80u);
  return atexit(func: dynamic_atexit_destructor_for__g_DataObjectAccessSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5A0
// Name: _dynamic_initializer_for__g_ThinkChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ThinkChecker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ThinkChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x10433440
// Name: _dynamic_atexit_destructor_for__g_DataObjectAccessSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataObjectAccessSystem__()
{
  IGameSystem::~IGameSystem(this: &g_DataObjectAccessSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10433450
// Name: _dynamic_atexit_destructor_for__g_WatcherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WatcherList__()
{
  CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(this: (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)&g_WatcherList);
}

//------------------------------------------------------------------------------
// Address: 0x10433460
// Name: _dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CPortalTouchScope::m_CallQueue__()
{
  CTSQueue<CFunctor *,0,1>::Purge(this: &CPortalTouchScope::m_CallQueue.m_queue);
  C_BaseEntity::operator delete(pMem: CPortalTouchScope::m_CallQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &CPortalTouchScope::m_CallQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x10433490
// Name: _dynamic_atexit_destructor_for__g_ThinkChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ThinkChecker__()
{
  CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::~CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>(this: &g_ThinkChecker.m_Thinkers);
}

//------------------------------------------------------------------------------
// Address: 0x104334A0
// Name: _DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_14);
}

//------------------------------------------------------------------------------
// Address: 0x104334B0
// Name: _DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_15);
}

//------------------------------------------------------------------------------
// Address: 0x104334C0
// Name: _dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__()
{
  CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysCollideBBoxModels.m_Tree);
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysObjectCustomModels.m_Tree);
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysObjectModels.m_Tree);
  CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<C_BaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_QueuedRestores.m_Tree);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysSaveRestoreBlockHandler.m_QueuedSaves);
}

//------------------------------------------------------------------------------
// Address: 0x10433500
// Name: _dynamic_atexit_destructor_for__r_propsmaxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_propsmaxdist__()
{
  ConVar::~ConVar(this: &r_propsmaxdist);
}

//------------------------------------------------------------------------------
// Address: 0x10433510
// Name: _dynamic_atexit_destructor_for__g_GameUI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameUI__()
{
  CDllDemandLoader::~CDllDemandLoader(this: &g_GameUI_0);
}
