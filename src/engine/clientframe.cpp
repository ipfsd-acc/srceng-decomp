// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/clientframe.cpp
// Functions: 13
// ============================================================

#include "engine\clientframe.h"

//------------------------------------------------------------------------------
// Address: 0x1009F7D0
// Name: public: void CClientFrame::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::Init(CNetMessage *this, INetChannel *netchan)
{
  this->m_NetChannel = netchan;
}

//------------------------------------------------------------------------------
// Address: 0x1009F7E0
// Name: public: void CClientFrame::SetSnapshot(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::SetSnapshot(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  if ( this->m_pSnapshot != pSnapshot )
  {
    if ( pSnapshot != nullptr )
      CFrameSnapshot::AddReference(this: pSnapshot);
    m_pSnapshot = this->m_pSnapshot;
    if ( m_pSnapshot != nullptr )
      CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = pSnapshot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F820
// Name: public: class CClientFrame __near * CClientFrameManager::GetClientFrame(int,bool)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrameManager::GetClientFrame(CClientFrameManager *this, int nTick, bool bExact)
{
  CClientFrame *result; // eax
  CClientFrame *v4; // ecx

  if ( nTick < 0 )
    return nullptr;
  result = this->m_Frames;
  v4 = result;
  if ( result == nullptr )
    return bExact ? nullptr : v4;
  while ( result->tick_count < nTick )
  {
    v4 = result;
    result = result->m_pNext;
    if ( result == nullptr )
      return bExact ? nullptr : v4;
  }
  if ( result->tick_count != nTick )
    return bExact ? nullptr : v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F870
// Name: public: int CClientFrameManager::AddClientFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientFrameManager::AddClientFrame(CClientFrameManager *this, CClientFrame *frame)
{
  CClientFrame *m_Frames; // eax
  int i; // ecx

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    for ( i = 1; m_Frames->m_pNext != nullptr; ++i )
      m_Frames = m_Frames->m_pNext;
    m_Frames->m_pNext = frame;
    return i + 1;
  }
  else
  {
    this->m_Frames = frame;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F8B0
// Name: public: void CClientFrame::Init(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::Init(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  this->tick_count = pSnapshot->m_nTickCount;
  if ( this->m_pSnapshot != pSnapshot )
  {
    CFrameSnapshot::AddReference(this: pSnapshot);
    m_pSnapshot = this->m_pSnapshot;
    if ( m_pSnapshot != nullptr )
      CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = pSnapshot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F8F0
// Name: public: virtual CClientFrame::~CClientFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::~CClientFrame(CClientFrame *this)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  m_pSnapshot = this->m_pSnapshot;
  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( m_pSnapshot != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = nullptr;
  }
  if ( this->transmit_always != nullptr )
  {
    free(pMem: this->transmit_always);
    this->transmit_always = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F9A0
// Name: public: CClientFrame::CClientFrame(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrame::CClientFrame(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( this != (CClientFrame *)-16 )
    memset(dst: (unsigned __int8 *)&this->transmit_entity, value: 0, count: sizeof(this->transmit_entity));
  this->last_entity = 0;
  this->transmit_always = nullptr;
  this->from_baseline = nullptr;
  this->tick_count = pSnapshot->m_nTickCount;
  this->m_pSnapshot = nullptr;
  CFrameSnapshot::AddReference(this: pSnapshot);
  m_pSnapshot = this->m_pSnapshot;
  if ( m_pSnapshot != nullptr )
    CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
  this->m_pSnapshot = pSnapshot;
  this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009FA10
// Name: public: CClientFrame::CClientFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrame::CClientFrame(CClientFrame *this)
{
  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( this != (CClientFrame *)-16 )
    memset(dst: (unsigned __int8 *)&this->transmit_entity, value: 0, count: sizeof(this->transmit_entity));
  this->last_entity = 0;
  this->transmit_always = nullptr;
  this->from_baseline = nullptr;
  this->tick_count = 0;
  this->m_pSnapshot = nullptr;
  this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009FA60
// Name: public: void CClientFrameManager::RemoveOldestFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrameManager::RemoveOldestFrame(CClientFrameManager *this)
{
  CClientFrame *m_Frames; // esi
  bool v3; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // eax

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    this->m_Frames = m_Frames->m_pNext;
    v3 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
    dtr_CClientFrame = m_Frames->dtr_CClientFrame;
    if ( v3 )
    {
      ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: m_Frames, a2: 1);
    }
    else
    {
      ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: m_Frames, a2: 0);
      CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FAA0
// Name: public: void CClientFrameManager::DeleteClientFrames(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrameManager::DeleteClientFrames(CClientFrameManager *this, int nTick)
{
  CClientFrame *m_Frames; // esi
  CClientFrame *v4; // ebx
  bool v5; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // eax
  void (__thiscall *v7)(CClientFrame *); // eax

  m_Frames = this->m_Frames;
  v4 = nullptr;
  while ( m_Frames != nullptr )
  {
    if ( nTick < 0 || m_Frames->tick_count < nTick )
    {
      if ( v4 != nullptr )
      {
        v4->m_pNext = m_Frames->m_pNext;
        v5 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
        dtr_CClientFrame = m_Frames->dtr_CClientFrame;
        if ( v5 )
        {
          ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: m_Frames, a2: 1);
        }
        else
        {
          ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: m_Frames, a2: 0);
          CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
        }
        m_Frames = v4->m_pNext;
      }
      else
      {
        this->m_Frames = m_Frames->m_pNext;
        v5 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
        v7 = m_Frames->dtr_CClientFrame;
        if ( v5 )
        {
          ((void (__thiscall *)(CClientFrame *, int))v7)(a1: m_Frames, a2: 1);
        }
        else
        {
          ((void (__thiscall *)(CClientFrame *, _DWORD))v7)(a1: m_Frames, a2: 0);
          CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
        }
        m_Frames = this->m_Frames;
      }
    }
    else
    {
      v4 = m_Frames;
      m_Frames = m_Frames->m_pNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FB40
// Name: public: bool CClientFrameManager::DeleteUnusedClientFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientFrameManager::DeleteUnusedClientFrame(CClientFrameManager *this, CClientFrame *pFrameToDelete)
{
  CClientFrame *m_Frames; // eax
  bool v4; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // edx

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    while ( m_Frames != pFrameToDelete )
    {
      m_Frames = m_Frames->m_pNext;
      if ( m_Frames == nullptr )
        goto LABEL_4;
    }
    return 0;
  }
  else
  {
LABEL_4:
    v4 = !pFrameToDelete->IsMemPoolAllocated(this: pFrameToDelete);
    dtr_CClientFrame = pFrameToDelete->dtr_CClientFrame;
    if ( v4 )
    {
      ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: pFrameToDelete, a2: 1);
    }
    else
    {
      ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: pFrameToDelete, a2: 0);
      CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: pFrameToDelete);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FBA0
// Name: public: void CClientFrame::CopyFrame(class CClientFrame __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::CopyFrame(CClientFrame *this, CClientFrame *frame)
{
  CFrameSnapshot *m_pSnapshot; // ebx
  CFrameSnapshot *v4; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ebx
  CBitVec<2048> *v7; // eax

  this->tick_count = frame->tick_count;
  this->last_entity = frame->last_entity;
  m_pSnapshot = frame->m_pSnapshot;
  if ( this->m_pSnapshot != m_pSnapshot )
  {
    if ( m_pSnapshot != nullptr )
      CFrameSnapshot::AddReference(this: frame->m_pSnapshot);
    v4 = this->m_pSnapshot;
    if ( v4 != nullptr )
      CFrameSnapshot::ReleaseReference(this: v4);
    this->m_pSnapshot = m_pSnapshot;
  }
  memcpy(
    dst: (unsigned __int8 *)&this->transmit_entity,
    src: (unsigned __int8 *)&frame->transmit_entity,
    count: sizeof(this->transmit_entity));
  if ( frame->transmit_always != nullptr )
  {
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x100u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      memset(dst: v5, value: 0, count: 0x100u);
      v7 = (CBitVec<2048> *)v6;
    }
    else
    {
      v7 = nullptr;
    }
    this->transmit_always = v7;
    memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)frame->transmit_always, count: sizeof(CBitVec<2048>));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FC50
// Name: public: class CClientFrame __near * CClientFrameManager::AllocateFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrameManager::AllocateFrame(CClientFrameManager *this)
{
  CClientFrame *result; // eax
  CClientFrame *v2; // esi

  result = (CClientFrame *)CUtlMemoryPool::Alloc(this: &this->m_ClientFramePool);
  v2 = result;
  if ( result != nullptr )
  {
    result->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
    if ( result != (CClientFrame *)-16 )
      memset(dst: (unsigned __int8 *)&result->transmit_entity, value: 0, count: sizeof(result->transmit_entity));
    v2->last_entity = 0;
    v2->transmit_always = nullptr;
    v2->from_baseline = nullptr;
    v2->tick_count = 0;
    v2->m_pSnapshot = nullptr;
    v2->m_pNext = nullptr;
    return v2;
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10002090
// Name: public: void CClientFrame::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::Init(CNetMessage *this, INetChannel *netchan)
{
  this->m_NetChannel = netchan;
}

//------------------------------------------------------------------------------
// Address: 0x1009F4B0
// Name: public: void CClientFrame::SetSnapshot(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::SetSnapshot(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  if ( this->m_pSnapshot != pSnapshot )
  {
    if ( pSnapshot != nullptr )
      CFrameSnapshot::AddReference(this: pSnapshot);
    m_pSnapshot = this->m_pSnapshot;
    if ( m_pSnapshot != nullptr )
      CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = pSnapshot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F4F0
// Name: public: class CClientFrame __near * CClientFrameManager::GetClientFrame(int,bool)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrameManager::GetClientFrame(CClientFrameManager *this, int nTick, bool bExact)
{
  CClientFrame *result; // eax
  CClientFrame *v4; // ecx

  if ( nTick < 0 )
    return nullptr;
  result = this->m_Frames;
  v4 = result;
  if ( result == nullptr )
    return bExact ? nullptr : v4;
  while ( result->tick_count < nTick )
  {
    v4 = result;
    result = result->m_pNext;
    if ( result == nullptr )
      return bExact ? nullptr : v4;
  }
  if ( result->tick_count != nTick )
    return bExact ? nullptr : v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F540
// Name: public: int CClientFrameManager::AddClientFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientFrameManager::AddClientFrame(CClientFrameManager *this, CClientFrame *frame)
{
  CClientFrame *m_Frames; // eax
  int i; // ecx

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    for ( i = 1; m_Frames->m_pNext != nullptr; ++i )
      m_Frames = m_Frames->m_pNext;
    m_Frames->m_pNext = frame;
    return i + 1;
  }
  else
  {
    this->m_Frames = frame;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F580
// Name: public: void CClientFrame::Init(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::Init(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  this->tick_count = pSnapshot->m_nTickCount;
  if ( this->m_pSnapshot != pSnapshot )
  {
    CFrameSnapshot::AddReference(this: pSnapshot);
    m_pSnapshot = this->m_pSnapshot;
    if ( m_pSnapshot != nullptr )
      CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = pSnapshot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F5C0
// Name: public: virtual CClientFrame::~CClientFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrame::~CClientFrame(CClientFrame *this)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  m_pSnapshot = this->m_pSnapshot;
  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( m_pSnapshot != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
    this->m_pSnapshot = nullptr;
  }
  if ( this->transmit_always != nullptr )
  {
    free(pMem: this->transmit_always);
    this->transmit_always = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F670
// Name: public: CClientFrame::CClientFrame(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrame::CClientFrame(CClientFrame *this, CFrameSnapshot *pSnapshot)
{
  CFrameSnapshot *m_pSnapshot; // ecx

  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( this != (CClientFrame *)-16 )
    memset(dst: (unsigned __int8 *)&this->transmit_entity, value: 0, count: sizeof(this->transmit_entity));
  this->last_entity = 0;
  this->transmit_always = nullptr;
  this->from_baseline = nullptr;
  this->tick_count = pSnapshot->m_nTickCount;
  this->m_pSnapshot = nullptr;
  CFrameSnapshot::AddReference(this: pSnapshot);
  m_pSnapshot = this->m_pSnapshot;
  if ( m_pSnapshot != nullptr )
    CFrameSnapshot::ReleaseReference(this: m_pSnapshot);
  this->m_pSnapshot = pSnapshot;
  this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009F6E0
// Name: public: CClientFrame::CClientFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrame::CClientFrame(CClientFrame *this)
{
  this->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
  if ( this != (CClientFrame *)-16 )
    memset(dst: (unsigned __int8 *)&this->transmit_entity, value: 0, count: sizeof(this->transmit_entity));
  this->last_entity = 0;
  this->transmit_always = nullptr;
  this->from_baseline = nullptr;
  this->tick_count = 0;
  this->m_pSnapshot = nullptr;
  this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009F730
// Name: public: void CClientFrameManager::RemoveOldestFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrameManager::RemoveOldestFrame(CClientFrameManager *this)
{
  CClientFrame *m_Frames; // esi
  bool v3; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // eax

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    this->m_Frames = m_Frames->m_pNext;
    v3 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
    dtr_CClientFrame = m_Frames->dtr_CClientFrame;
    if ( v3 )
    {
      ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: m_Frames, a2: 1);
    }
    else
    {
      ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: m_Frames, a2: 0);
      CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F770
// Name: public: void CClientFrameManager::DeleteClientFrames(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientFrameManager::DeleteClientFrames(CClientFrameManager *this, int nTick)
{
  CClientFrame *m_Frames; // esi
  CClientFrame *v4; // ebx
  bool v5; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // eax
  void (__thiscall *v7)(CClientFrame *); // eax

  m_Frames = this->m_Frames;
  v4 = nullptr;
  while ( m_Frames != nullptr )
  {
    if ( nTick < 0 || m_Frames->tick_count < nTick )
    {
      if ( v4 != nullptr )
      {
        v4->m_pNext = m_Frames->m_pNext;
        v5 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
        dtr_CClientFrame = m_Frames->dtr_CClientFrame;
        if ( v5 )
        {
          ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: m_Frames, a2: 1);
        }
        else
        {
          ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: m_Frames, a2: 0);
          CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
        }
        m_Frames = v4->m_pNext;
      }
      else
      {
        this->m_Frames = m_Frames->m_pNext;
        v5 = !m_Frames->IsMemPoolAllocated(this: m_Frames);
        v7 = m_Frames->dtr_CClientFrame;
        if ( v5 )
        {
          ((void (__thiscall *)(CClientFrame *, int))v7)(a1: m_Frames, a2: 1);
        }
        else
        {
          ((void (__thiscall *)(CClientFrame *, _DWORD))v7)(a1: m_Frames, a2: 0);
          CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: m_Frames);
        }
        m_Frames = this->m_Frames;
      }
    }
    else
    {
      v4 = m_Frames;
      m_Frames = m_Frames->m_pNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F810
// Name: public: bool CClientFrameManager::DeleteUnusedClientFrame(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientFrameManager::DeleteUnusedClientFrame(CClientFrameManager *this, CClientFrame *pFrameToDelete)
{
  CClientFrame *m_Frames; // eax
  bool v4; // zf
  void (__thiscall *dtr_CClientFrame)(CClientFrame *); // edx

  m_Frames = this->m_Frames;
  if ( m_Frames != nullptr )
  {
    while ( m_Frames != pFrameToDelete )
    {
      m_Frames = m_Frames->m_pNext;
      if ( m_Frames == nullptr )
        goto LABEL_4;
    }
    return 0;
  }
  else
  {
LABEL_4:
    v4 = !pFrameToDelete->IsMemPoolAllocated(this: pFrameToDelete);
    dtr_CClientFrame = pFrameToDelete->dtr_CClientFrame;
    if ( v4 )
    {
      ((void (__thiscall *)(CClientFrame *, int))dtr_CClientFrame)(a1: pFrameToDelete, a2: 1);
    }
    else
    {
      ((void (__thiscall *)(CClientFrame *, _DWORD))dtr_CClientFrame)(a1: pFrameToDelete, a2: 0);
      CUtlMemoryPool::Free(this: &this->m_ClientFramePool, memBlock: pFrameToDelete);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F920
// Name: public: class CClientFrame __near * CClientFrameManager::AllocateFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CClientFrameManager::AllocateFrame(CClientFrameManager *this)
{
  CClientFrame *result; // eax
  CClientFrame *v2; // esi

  result = (CClientFrame *)CUtlMemoryPool::Alloc(this: &this->m_ClientFramePool);
  v2 = result;
  if ( result != nullptr )
  {
    result->__vftable = (CClientFrame_vtbl *)&CClientFrame::`vftable';
    if ( result != (CClientFrame *)-16 )
      memset(dst: (unsigned __int8 *)&result->transmit_entity, value: 0, count: sizeof(result->transmit_entity));
    v2->last_entity = 0;
    v2->transmit_always = nullptr;
    v2->from_baseline = nullptr;
    v2->tick_count = 0;
    v2->m_pSnapshot = nullptr;
    v2->m_pNext = nullptr;
    return v2;
  }
  return result;
}

} // namespace engine_xlsp
