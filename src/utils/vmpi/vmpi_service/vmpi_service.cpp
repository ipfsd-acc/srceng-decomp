// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service/vmpi_service.cpp
// Functions: 77
// ============================================================

#include "utils\vmpi\vmpi_service\vmpi_service.h"

//------------------------------------------------------------------------------
// Address: 0x00402FA0
// Name: public: void CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403000
// Name: protected: int CUtlLinkedList<class CServiceConn __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceConn __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServiceConn *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004031E0
// Name: public: void CUtlLinkedList<class CServiceConn __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceConn __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CServiceConn *m_Element; // edi
  int m_Next; // ebx
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Element = this->m_Memory.m_pMemory[v3].m_Element;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      if ( m_Element != nullptr )
      {
        if ( m_Element->m_pSocket != nullptr )
          m_Element->m_pSocket->Release(this: m_Element->m_pSocket);
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00403F50
// Name: protected: int CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004053B0
// Name: protected: int CUtlLinkedList<class CTCPPacket __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTCPPacket __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal(
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CTCPPacket *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004054E0
// Name: public: void CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServiceConn *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405680
// Name: public: int CUtlLinkedList<class CTCPPacket __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTCPPacket __near *,int>,int>>::AddToTail(class CTCPPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *this,
        CTCPPacket **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CTCPPacket *,int> *v8; // esi

  result = CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405730
// Name: public: class CUtlVector<char,class CUtlMemory<char,int>> __near & CUtlVector<char,class CUtlMemory<char,int>>::operator=(class CUtlVector<char,class CUtlMemory<char,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<char,CUtlMemory<char,int> > *__thiscall CUtlVector<char,CUtlMemory<char,int>>::operator=(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const CUtlVector<char,CUtlMemory<char,int> > *other)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount);
    this->m_Size += m_Size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - m_Size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && m_Size > 0 )
      _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405840
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        const unsigned __int8 *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00405D20
// Name: void __near * VMPIServiceFactoryFn(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl VMPIServiceFactoryFn(const char *pName, int *pReturnCode)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( _V_stricmp(s1: pName, s2: "VBaseFileSystem011") == 0 )
    return g_pBaseFileSystem;
  FactoryThis = Sys_GetFactoryThis();
  return (IBaseFileSystem *)FactoryThis(a1: pName, a2: pReturnCode);
}

//------------------------------------------------------------------------------
// Address: 0x00405D60
// Name: void SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPassword(const char *pPassword)
{
  int v1; // esi

  free(pMem: g_pPassword);
  if ( pPassword != nullptr )
  {
    v1 = _V_strlen(str: pPassword) + 1;
    g_pPassword = (char *)operator new(nSize: v1);
    V_strncpy(pDest: g_pPassword, pSrc: pPassword, maxLen: v1);
  }
  else
  {
    g_pPassword = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405DB0
// Name: void SaveStateToRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __fastcall SaveStateToRegistry(unsigned int a1)
{
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = a1;
  if ( g_hVMPIServiceKey != nullptr )
  {
    val = g_bScreensaverMode;
    RegSetValueExA(
      hKey: g_hVMPIServiceKey,
      lpValueName: "ScreensaverMode",
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&val,
      cbData: 4u);
    val = g_iCurState == 2;
    RegSetValueExA(
      hKey: g_hVMPIServiceKey,
      lpValueName: "Disabled",
      Reserved: 0,
      dwType: 4u,
      lpData: (const BYTE *)&val,
      cbData: 4u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E10
// Name: char __near * FindArg(int,char __near * __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FindArg(int argc, char **argv, const char *pArgName, char *pDefaultValue)
{
  int v4; // esi

  v4 = 0;
  if ( argc <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: argv[v4], s2: pArgName) != 0 )
  {
    if ( ++v4 >= argc )
      return nullptr;
  }
  if ( v4 + 1 < argc )
    return argv[v4 + 1];
  else
    return pDefaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00405E60
// Name: char __near * CopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CopyString(const char *pStr)
{
  int v1; // esi
  char *v2; // edi

  v1 = _V_strlen(str: pStr) + 1;
  v2 = (char *)operator new(nSize: v1);
  V_strncpy(pDest: v2, pSrc: pStr, maxLen: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00405E90
// Name: void SendStartStatus(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendStartStatus(bool bStatus)
{
  int i; // edi
  _BYTE pData[4096]; // [esp+Ch] [ebp-1018h] BYREF
  bf_write v3; // [esp+100Ch] [ebp-18h] BYREF

  for ( i = 3; i != 0; --i )
  {
    bf_write::bf_write(this: &v3, pData, nBytes: 4096, nBits: -1);
    bf_write::WriteByte(this: &v3, val: 5u);
    bf_write::WriteByte(this: &v3, val: 0x50u);
    bf_write::WriteBytes(this: &v3, pBuf: g_CurJobID, nBytes: 16);
    bf_write::WriteByte(this: &v3, val: bStatus);
    g_pSocket->SendTo(this: g_pSocket, a2: &g_CurRespondAddr, a3: pData, a4: (v3.m_iCurBit + 7) >> 3);
    Sleep(dwMilliseconds: 0x32u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F30
// Name: void SendEndStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendEndStatus()
{
  int i; // edi
  _BYTE pData[4096]; // [esp+8h] [ebp-1018h] BYREF
  bf_write v2; // [esp+1008h] [ebp-18h] BYREF

  for ( i = 3; i != 0; --i )
  {
    bf_write::bf_write(this: &v2, pData, nBytes: 4096, nBits: -1);
    bf_write::WriteByte(this: &v2, val: 5u);
    bf_write::WriteByte(this: &v2, val: 0x51u);
    bf_write::WriteBytes(this: &v2, pBuf: g_CurJobID, nBytes: 16);
    g_pSocket->SendTo(this: g_pSocket, a2: &g_CurRespondAddr, a3: pData, a4: (v2.m_iCurBit + 7) >> 3);
    Sleep(dwMilliseconds: 0x32u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405FC0
// Name: void HandleWindowMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleWindowMessages()
{
  tagMSG msg; // [esp+4h] [ebp-1Ch] BYREF

  while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    TranslateMessage(lpMsg: &msg);
    DispatchMessageA(lpMsg: &msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406020
// Name: void GetRunningProcessStats(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetRunningProcessStats(int *processorPercentage, int *memoryUsageMegabytes)
{
  DWORD TickCount; // eax
  IPerfTracker_vtbl *v3; // edx

  if ( g_hRunningProcess != nullptr )
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      lastReturnTime = GetTickCount();
    }
    TickCount = GetTickCount();
    if ( TickCount - lastReturnTime >= 0x3E8 )
    {
      v3 = g_pPerfTracker->__vftable;
      lastReturnTime = TickCount;
      v3->GetPerfData(this: g_pPerfTracker, a2: &lastProcessorPercentage, a3: &lastMemory);
    }
    *processorPercentage = lastProcessorPercentage;
    *memoryUsageMegabytes = lastMemory;
  }
  else
  {
    lastMemory = 0;
    lastProcessorPercentage = 0;
    *processorPercentage = 0;
    *memoryUsageMegabytes = lastMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004060D0
// Name: void StopUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StopUI()
{
  DWORD TickCount; // edi
  char cPacket[2]; // [esp+0h] [ebp-4h] BYREF

  *(_WORD *)cPacket = 769;
  if ( g_pConnMgr != nullptr )
    CServiceConnMgr::SendPacket(this: g_pConnMgr, id: -1, pData: cPacket, len: 2);
  TickCount = GetTickCount();
  while ( GetTickCount() - TickCount < 0x7D0 )
  {
    if ( g_pConnMgr != nullptr )
    {
      CServiceConnMgr::Update(this: g_pConnMgr);
      if ( !CServiceConnMgr::IsConnected(this: g_pConnMgr) )
        return;
      Sleep(dwMilliseconds: 0xAu);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: unsigned int VWatchServiceThreadFunc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl VWatchServiceThreadFunc()
{
  g_pVWatchService->Run(this: g_pVWatchService, a2: (void *(__cdecl *)(const char *, int *))VMPIServiceFactoryFn);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406170
// Name: void StartVWatch(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartVWatch()
{
  if ( Sys_LoadInterface(
         pModuleName: g_pVWatchServiceModuleName,
         pInterfaceVersionName: "VWatchService001",
         pOutModule: &g_pVWatchServiceModule,
         pOutInterface: (void **)&g_pVWatchService) )
  {
    g_hVWatchServiceThread = (ThreadHandle_t__ *)_CreateSimpleThread(a1: VWatchServiceThreadFunc, a2: 0, a3: 0);
  }
  else
  {
    _Msg(
      a1: "Unable to load VWatch service from %s (wanted interface version %s).\n",
      g_pVWatchServiceModuleName,
      "VWatchService001");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004061D0
// Name: void StopVWatch(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StopVWatch()
{
  if ( g_pVWatchService != nullptr )
  {
    g_pVWatchService->Stop(this: g_pVWatchService);
    g_pVWatchService = nullptr;
    _ThreadJoin(a1: g_hVWatchServiceThread, a2: -1);
    _ReleaseThreadHandle(a1: g_hVWatchServiceThread);
    g_hVWatchServiceThread = nullptr;
    Sys_UnloadModule(pModule: g_pVWatchServiceModule);
    g_pVWatchServiceModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406230
// Name: public: void CUtlMemory<char __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char *,int>::Grow(CUtlMemory<char *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (char **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406360
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CJobMemory,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CJobMemory,int> *m_pMemory; // edx

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
        m_nAllocationCount = 2;
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
      this->m_pMemory = (UtlLinkedListElem_t<CJobMemory,int> *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CJobMemory,int> *)_g_pMemAlloc->Alloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406410
// Name: public: int CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
        CUtlVector<char *,CUtlMemory<char *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &(&m_pMemory[elem])[num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00406480
// Name: bool GetDLLFilename(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,char __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetDLLFilename(CUtlVector<char *,CUtlMemory<char *,int> > *newArgv, char *pDLLFilename)
{
  char *v2; // edi
  int v3; // eax
  int v4; // esi
  int v6; // eax
  char baseFilename[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = *newArgv->m_Memory.m_pMemory;
  v3 = strlen(v2);
  v4 = v3;
  if ( v3 <= 4 || _V_stricmp(s1: &v2[v3 - 4], s2: ".exe") != 0 )
    return 0;
  V_strncpy(pDest: baseFilename, pSrc: v2, maxLen: 260);
  v6 = v4 - 4;
  if ( v4 - 4 > 259 )
    v6 = 259;
  baseFilename[v6] = 0;
  V_snprintf(pDest: pDLLFilename, maxLen: 260, pFormat: "%s_dll.dll", baseFilename);
  if ( access(path: pDLLFilename, amode: 0) != 0 )
    V_snprintf(pDest: pDLLFilename, maxLen: 260, pFormat: "%s.dll", baseFilename);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406540
// Name: void BuildCommandLineFromArgs(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildCommandLineFromArgs(
        CUtlVector<char *,CUtlMemory<char *,int> > *newArgv,
        char *pOut,
        unsigned int outLen)
{
  int v3; // edi
  char argStr[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = 0;
  for ( *pOut = 0; v3 < newArgv->m_Size; ++v3 )
  {
    if ( strlen(newArgv->m_Memory.m_pMemory[v3]) != 0
      && newArgv->m_Memory.m_pMemory[v3][strlen(newArgv->m_Memory.m_pMemory[v3]) - 1] == 92 )
    {
      V_snprintf(pDest: argStr, maxLen: 512, pFormat: "\"%s\\\" ", newArgv->m_Memory.m_pMemory[v3]);
    }
    else
    {
      V_snprintf(pDest: argStr, maxLen: 512, pFormat: "\"%s\" ", newArgv->m_Memory.m_pMemory[v3]);
    }
    V_strncat(pDest: pOut, pSrc: argStr, destBufferSize: outLen, max_chars_to_copy: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004065F0
// Name: bool RunProcessFromArgs(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,bool,bool,char const __near *,struct _PROCESS_INFORMATION __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl RunProcessFromArgs(
        CUtlVector<char *,CUtlMemory<char *,int> > *newArgv,
        bool bShowAppWindow,
        bool bCreateSuspended,
        const char *pWorkingDir,
        _PROCESS_INFORMATION *pOut)
{
  int v5; // esi
  BOOL v6; // esi
  char commandLine[2048]; // [esp+Ch] [ebp-844h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+80Ch] [ebp-44h] BYREF
  unsigned int oldMode; // [esp+85Ch] [ebp+Ch]

  BuildCommandLineFromArgs(newArgv, pOut: commandLine, outLen: 0x800u);
  _Msg(a1: "Running '%s'\n", commandLine);
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  v5 = bShowAppWindow ? 16 : 0x8000000;
  *(_QWORD *)&pOut->hProcess = 0;
  StartupInfo.cb = 68;
  *(_QWORD *)&pOut->dwProcessId = 0;
  if ( bCreateSuspended )
    v5 |= 4u;
  oldMode = SetErrorMode(uMode: 0x8001u);
  v6 = CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: commandLine,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: v5 | 0x40,
         lpEnvironment: nullptr,
         lpCurrentDirectory: pWorkingDir,
         lpStartupInfo: &StartupInfo,
         lpProcessInformation: pOut);
  SetErrorMode(uMode: oldMode);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004066C0
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::Purge(CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  bool v2; // sf
  char **m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406710
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406780
// Name: public: void CUtlLinkedList<class CJobMemory,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CJobMemory,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::RemoveAll(
        CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CJobMemory,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004067E0
// Name: protected: int CUtlLinkedList<class CJobMemory,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CJobMemory,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AllocInternal(
        CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CJobMemory,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00406910
// Name: bool FindJobMemory(int __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindJobMemory(int *id)
{
  int m_Head; // eax
  int m_Next; // edi
  unsigned int v3; // edx
  int *v4; // ecx
  int v5; // eax

  m_Head = g_JobMemories.m_Head;
  if ( g_JobMemories.m_Head != -1 )
  {
    while ( 2 )
    {
      m_Next = g_JobMemories.m_Memory.m_pMemory[m_Head].m_Next;
      v3 = 16;
      v4 = id;
      v5 = (char *)&g_JobMemories.m_Memory.m_pMemory[m_Head] - (char *)id;
      while ( 1 )
      {
        if ( v3 < 4 )
          return 1;
        if ( *(int *)((char *)v4 + v5) != *v4 )
          break;
        v3 -= 4;
        ++v4;
      }
      m_Head = m_Next;
      if ( m_Next != -1 )
        continue;
      break;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406980
// Name: void UpdateServicesBrowserIPs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateServicesBrowserIPs()
{
  int m_Size; // edx
  int v1; // ecx
  CServicesBrowserInfo *i; // eax
  double curTime; // [esp+0h] [ebp-8h]

  curTime = _Plat_FloatTime();
  m_Size = g_ServicesBrowsers.m_Size;
  v1 = 0;
  if ( g_ServicesBrowsers.m_Size > 0 )
  {
    for ( i = g_ServicesBrowsers.m_Memory.m_pMemory; curTime - i->m_flLastPingTime < 10.0; ++i )
    {
      if ( ++v1 >= g_ServicesBrowsers.m_Size )
        return;
    }
    if ( g_ServicesBrowsers.m_Size - v1 - 1 > 0 )
    {
      _V_memmove(
        dest: &g_ServicesBrowsers.m_Memory.m_pMemory[v1],
        src: &g_ServicesBrowsers.m_Memory.m_pMemory[v1 + 1],
        count: 12 * (g_ServicesBrowsers.m_Size - v1 - 1));
      m_Size = g_ServicesBrowsers.m_Size;
    }
    g_ServicesBrowsers.m_Size = m_Size - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406A10
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::~CUtlVector<char,class CUtlMemory<char,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(
        CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406A80
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00406B10
// Name: public: void CUtlLinkedList<class CJobMemory,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CJobMemory,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::Unlink(
        CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CJobMemory,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BA0
// Name: void GetArgsFromBuffer(class bf_read __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetArgsFromBuffer(bf_read *buf, CUtlVector<char *,CUtlMemory<char *,int> > *newArgv, bool *bShowAppWindow)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  int v6; // esi
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // esi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v21; // eax
  char **v22; // ebx
  int j; // edi
  char argStr[512]; // [esp+Ch] [ebp-208h] BYREF
  char *v25; // [esp+20Ch] [ebp-8h]
  int i; // [esp+210h] [ebp-4h]
  char bSpewArgs_3; // [esp+21Fh] [ebp+Bh]

  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buf->m_pBufferEnd;
    m_nInBufWord = buf->m_nInBufWord;
    v12 = 16 - m_nBitsAvail;
    m_pDataIn = buf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_15:
        if ( buf->m_bOverflow )
        {
          v14 = 0;
          goto LABEL_20;
        }
        v15 = buf->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v12]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v12;
        v6 = v16 | m_nInBufWord;
        v7 = v15 >> v12;
        goto LABEL_18;
      }
      buf->m_nInBufWord = *m_pDataIn;
    }
    buf->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = buf->m_nInBufWord;
  v6 = (unsigned __int16)v5;
  buf->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v8 = buf->m_pDataIn;
    v9 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      buf->m_nInBufWord = *v8;
      buf->m_pDataIn = v8 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = HIWORD(v5);
LABEL_18:
  buf->m_nInBufWord = v7;
LABEL_19:
  v14 = v6;
LABEL_20:
  bSpewArgs_3 = 0;
  if ( v14 > 0 )
  {
    for ( i = v14; i != 0; --i )
    {
      CBitRead::ReadString(this: buf, pStr: argStr, maxLen: 512, bLine: false, pOutNumChars: nullptr);
      v17 = _V_strlen(str: argStr) + 1;
      v25 = (char *)operator new(nSize: v17);
      V_strncpy(pDest: v25, pSrc: argStr, maxLen: v17);
      m_Size = newArgv->m_Size;
      m_nAllocationCount = newArgv->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<char *,int>::Grow(this: &newArgv->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++newArgv->m_Size;
      m_pMemory = newArgv->m_Memory.m_pMemory;
      v21 = newArgv->m_Size - m_Size - 1;
      newArgv->m_pElements = newArgv->m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v21);
      v22 = &newArgv->m_Memory.m_pMemory[m_Size];
      if ( v22 != nullptr )
        *v22 = v25;
      if ( _V_stricmp(s1: argStr, s2: "-mpi_verbose") == 0 )
        bSpewArgs_3 = 1;
      if ( _V_stricmp(s1: argStr, s2: "-mpi_ShowAppWindow") == 0 )
        *bShowAppWindow = true;
    }
    if ( bSpewArgs_3 != 0 )
    {
      _Msg(a1: "nArgs: %d\n", newArgv->m_Size);
      for ( j = 0; j < newArgv->m_Size; ++j )
        _Msg(a1: "Arg %d: %s\n", j, newArgv->m_Memory.m_pMemory[j]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406DC0
// Name: void AdjustSuperDebugArgs(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AdjustSuperDebugArgs(CUtlVector<char *,CUtlMemory<char *,int> > *args)
{
  HMODULE ModuleHandleA; // eax
  char v2; // al
  char *v3; // edx
  char *i; // ecx
  char **m_pMemory; // ecx
  const char *v6; // eax
  bool v7; // zf
  const char *v8; // ecx
  char v9; // dl
  unsigned int v10; // kr00_4
  char *v11; // ebx
  char *v12; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char **v15; // eax
  int v16; // ecx
  char filename[512]; // [esp+0h] [ebp-204h] BYREF
  const char *pBase; // [esp+200h] [ebp-4h]

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: filename, nSize: 0x200u) != 0 )
  {
    v2 = filename[0];
    v3 = filename;
    for ( i = filename; v2 != 0; ++i )
    {
      if ( v2 == 47 || v2 == 92 )
        v3 = i;
      v2 = i[1];
    }
    m_pMemory = args->m_Memory.m_pMemory;
    *v3 = 0;
    v6 = *m_pMemory;
    v7 = **m_pMemory == 0;
    pBase = v6;
    v8 = v6;
    if ( !v7 )
    {
      do
      {
        v9 = *v8;
        if ( *v8 == 47 || v9 == 92 || v9 == 58 )
        {
          pBase = ++v8;
          v6 = v8;
        }
        ++v8;
      }
      while ( *v8 != 0 );
    }
    v10 = strlen(v6);
    v11 = (char *)operator new(nSize: v10 + 65);
    _snprintf(string: v11, count: v10 + 65, format: "%s\\%s", filename, pBase);
    free(pMem: *(void **)args->m_Memory.m_pMemory);
    *args->m_Memory.m_pMemory = v11;
    v12 = (char *)operator new(nSize: 0xCu);
    strcpy(v12, "-allowdebug");
    m_Size = args->m_Size;
    m_nAllocationCount = args->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<char *,int>::Grow(this: &args->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++args->m_Size;
    v15 = args->m_Memory.m_pMemory;
    v16 = args->m_Size - 2;
    args->m_pElements = args->m_Memory.m_pMemory;
    if ( v16 > 0 )
      _V_memmove(dest: v15 + 2, src: v15 + 1, count: 4 * v16);
    if ( args->m_Memory.m_pMemory != (char **)-4 )
      *((_DWORD *)args->m_Memory.m_pMemory + 1) = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EF0
// Name: bool StartDownloadingAppFiles(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,char __near *,int,bool,void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl StartDownloadingAppFiles(
        CUtlVector<char *,CUtlMemory<char *,int> > *newArgv,
        char *cacheDir,
        int cacheDirLen,
        bool bShowAppWindow,
        void **hProcess,
        bool bPatching)
{
  int v7; // edi
  char *v8; // ebx
  int v9; // esi
  char *v10; // ebx
  CUtlVector<char *,CUtlMemory<char *,int> > *v11; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char **m_pMemory; // eax
  int v15; // ecx
  int v16; // esi
  char *v17; // ebx
  int v18; // eax
  int v19; // ecx
  char **v20; // eax
  int v21; // ecx
  char **v22; // ebx
  int v23; // esi
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // esi
  char **v28; // ecx
  int v29; // ecx
  int v30; // esi
  char **v31; // ecx
  int v32; // ecx
  char **v33; // edx
  int v34; // ecx
  int v35; // esi
  char **v36; // ecx
  int v37; // ecx
  char **v38; // ecx
  char **v39; // edx
  int v40; // ecx
  int v41; // esi
  char **v42; // ecx
  int v43; // ecx
  char **v44; // ecx
  int v45; // ecx
  int v46; // ecx
  bool v47; // sf
  char searchStr[260]; // [esp+4h] [ebp-464h] BYREF
  char fullExeFilename[260]; // [esp+108h] [ebp-360h] BYREF
  char fullFilename[260]; // [esp+20Ch] [ebp-25Ch] BYREF
  _finddata64i32_t findData; // [esp+310h] [ebp-158h] BYREF
  _PROCESS_INFORMATION pi; // [esp+438h] [ebp-30h] BYREF
  char **v53; // [esp+448h] [ebp-20h]
  CUtlVector<char *,CUtlMemory<char *,int> > downloaderArgs; // [esp+44Ch] [ebp-1Ch] BYREF
  char **v55; // [esp+460h] [ebp-8h]
  int i; // [esp+464h] [ebp-4h]

  *hProcess = nullptr;
  V_strncpy(pDest: cacheDir, pSrc: g_FileCachePath, maxLen: cacheDirLen);
  if ( access(path: cacheDir, amode: 0) == 0
    || CreateDirectoryA(lpPathName: cacheDir, lpSecurityAttributes: nullptr)
    || GetLastError() == 183 )
  {
    V_ComposeFileName(path: cacheDir, filename: "*.*", dest: searchStr, destSize: 260);
    v7 = _findfirst64i32(szWild: searchStr, pfd: &findData);
    if ( v7 == -1 )
    {
LABEL_10:
      v8 = (char *)operator new(nSize: 0x400u);
      i = (int)v8;
      if ( bPatching )
      {
        V_ComposeFileName(path: cacheDir, filename: "vmpi_service_install.exe", dest: v8, destSize: 1024);
        v9 = _V_strlen(str: "-DontTouchUI") + 1;
        v10 = (char *)operator new(nSize: v9);
        V_strncpy(pDest: v10, pSrc: "-DontTouchUI", maxLen: v9);
        v11 = newArgv;
        m_Size = newArgv->m_Size;
        m_nAllocationCount = newArgv->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<char *,int>::Grow(this: &newArgv->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++newArgv->m_Size;
        m_pMemory = newArgv->m_Memory.m_pMemory;
        v15 = newArgv->m_Size - 2;
        newArgv->m_pElements = newArgv->m_Memory.m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: m_pMemory + 2, src: m_pMemory + 1, count: 4 * v15);
        if ( newArgv->m_Memory.m_pMemory != (char **)-4 )
          *((_DWORD *)newArgv->m_Memory.m_pMemory + 1) = v10;
        v16 = _V_strlen(str: "-Install_Quiet") + 1;
        v17 = (char *)operator new(nSize: v16);
        V_strncpy(pDest: v17, pSrc: "-Install_Quiet", maxLen: v16);
        v18 = newArgv->m_Size;
        v19 = newArgv->m_Memory.m_nAllocationCount;
        if ( v18 + 1 > v19 )
          CUtlMemory<char *,int>::Grow(this: &newArgv->m_Memory, num: v18 - v19 + 1);
        ++newArgv->m_Size;
        v20 = newArgv->m_Memory.m_pMemory;
        v21 = newArgv->m_Size - 2;
        newArgv->m_pElements = newArgv->m_Memory.m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: v20 + 2, src: v20 + 1, count: 4 * v21);
        if ( newArgv->m_Memory.m_pMemory != (char **)-4 )
          *((_DWORD *)newArgv->m_Memory.m_pMemory + 1) = v17;
        v8 = (char *)i;
      }
      else
      {
        v11 = newArgv;
        V_ComposeFileName(
          path: cacheDir,
          filename: *(const char **)newArgv->m_Memory.m_pMemory,
          dest: v8,
          destSize: 1024);
      }
      free(pMem: *(void **)v11->m_Memory.m_pMemory);
      *v11->m_Memory.m_pMemory = v8;
      V_ComposeFileName(path: g_BaseAppPath, filename: "vmpi_transfer.exe", dest: fullExeFilename, destSize: 260);
      memset(&downloaderArgs, 0, sizeof(downloaderArgs));
      CUtlMemory<char *,int>::Grow(this: &downloaderArgs.m_Memory, num: 1);
      v22 = downloaderArgs.m_Memory.m_pMemory;
      v23 = downloaderArgs.m_Size + 1;
      v24 = downloaderArgs.m_Size++;
      downloaderArgs.m_pElements = downloaderArgs.m_Memory.m_pMemory;
      if ( v24 > 0 )
        _V_memmove(dest: downloaderArgs.m_Memory.m_pMemory + 1, src: downloaderArgs.m_Memory.m_pMemory, count: 4 * v24);
      if ( v22 != nullptr )
        *v22 = fullExeFilename;
      v25 = downloaderArgs.m_Memory.m_nAllocationCount;
      v26 = v23;
      i = v23;
      if ( v23 + 1 > downloaderArgs.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<char *,int>::Grow(
          this: &downloaderArgs.m_Memory,
          num: v23 - downloaderArgs.m_Memory.m_nAllocationCount + 1);
        v23 = downloaderArgs.m_Size;
        v22 = downloaderArgs.m_Memory.m_pMemory;
        v26 = i;
        v25 = downloaderArgs.m_Memory.m_nAllocationCount;
      }
      v27 = v23 + 1;
      downloaderArgs.m_Size = v27;
      downloaderArgs.m_pElements = v22;
      if ( v27 - v26 - 1 > 0 )
      {
        _V_memmove(dest: &v22[v26 + 1], src: &v22[v26], count: 4 * (v27 - v26 - 1));
        v26 = i;
        v25 = downloaderArgs.m_Memory.m_nAllocationCount;
      }
      v28 = &v22[v26];
      if ( v28 != nullptr )
        *v28 = "-CachePath";
      v29 = v27;
      i = v27;
      if ( v27 + 1 > v25 )
      {
        CUtlMemory<char *,int>::Grow(this: &downloaderArgs.m_Memory, num: v27 - v25 + 1);
        v27 = downloaderArgs.m_Size;
        v22 = downloaderArgs.m_Memory.m_pMemory;
        v29 = i;
      }
      v30 = v27 + 1;
      downloaderArgs.m_Size = v30;
      downloaderArgs.m_pElements = v22;
      if ( v30 - v29 - 1 > 0 )
      {
        _V_memmove(dest: &v22[v29 + 1], src: &v22[v29], count: 4 * (v30 - v29 - 1));
        v29 = i;
      }
      v31 = &v22[v29];
      if ( v31 != nullptr )
        *v31 = cacheDir;
      v32 = v11->m_Size - 1;
      i = 1;
      if ( v32 > 1 )
      {
        do
        {
          if ( _V_stricmp(s1: v11->m_Memory.m_pMemory[i], s2: "-mpi_filebase") != 0
            && _V_stricmp(s1: v11->m_Memory.m_pMemory[i], s2: "-mpi_file") != 0 )
          {
            if ( _V_stricmp(s1: v11->m_Memory.m_pMemory[i], s2: "-mpi_worker") == 0 )
            {
              v33 = &v11->m_Memory.m_pMemory[i];
              v34 = v30;
              v53 = v33;
              v55 = (char **)v30;
              if ( v30 + 1 > downloaderArgs.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char *,int>::Grow(
                  this: &downloaderArgs.m_Memory,
                  num: v30 - downloaderArgs.m_Memory.m_nAllocationCount + 1);
                v30 = downloaderArgs.m_Size;
                v22 = downloaderArgs.m_Memory.m_pMemory;
                v33 = v53;
                v34 = (int)v55;
              }
              v35 = v30 + 1;
              downloaderArgs.m_Size = v35;
              downloaderArgs.m_pElements = v22;
              if ( v35 - v34 - 1 > 0 )
              {
                _V_memmove(dest: &v22[v34 + 1], src: &v22[v34], count: 4 * (v35 - v34 - 1));
                v33 = v53;
                v34 = (int)v55;
              }
              v36 = &v22[v34];
              if ( v36 != nullptr )
                *v36 = *v33;
              v53 = &v11->m_Memory.m_pMemory[i + 1];
              v37 = v35;
              v55 = (char **)v35;
              if ( v35 + 1 > downloaderArgs.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<char *,int>::Grow(
                  this: &downloaderArgs.m_Memory,
                  num: v35 - downloaderArgs.m_Memory.m_nAllocationCount + 1);
                v35 = downloaderArgs.m_Size;
                v22 = downloaderArgs.m_Memory.m_pMemory;
                v37 = (int)v55;
              }
              v30 = v35 + 1;
              downloaderArgs.m_Size = v30;
              downloaderArgs.m_pElements = v22;
              if ( v30 - v37 - 1 > 0 )
              {
                _V_memmove(dest: &v22[v37 + 1], src: &v22[v37], count: 4 * (v30 - v37 - 1));
                v37 = (int)v55;
              }
              v38 = &v22[v37];
              if ( v38 != nullptr )
                *v38 = *v53;
              ++i;
            }
          }
          else
          {
            v39 = &v11->m_Memory.m_pMemory[i];
            v40 = v30;
            v55 = v39;
            v53 = (char **)v30;
            if ( v30 + 1 > downloaderArgs.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char *,int>::Grow(
                this: &downloaderArgs.m_Memory,
                num: v30 - downloaderArgs.m_Memory.m_nAllocationCount + 1);
              v30 = downloaderArgs.m_Size;
              v22 = downloaderArgs.m_Memory.m_pMemory;
              v39 = v55;
              v40 = (int)v53;
            }
            v41 = v30 + 1;
            downloaderArgs.m_Size = v41;
            downloaderArgs.m_pElements = v22;
            if ( v41 - v40 - 1 > 0 )
            {
              _V_memmove(dest: &v22[v40 + 1], src: &v22[v40], count: 4 * (v41 - v40 - 1));
              v39 = v55;
              v40 = (int)v53;
            }
            v42 = &v22[v40];
            if ( v42 != nullptr )
              *v42 = *v39;
            v53 = &v11->m_Memory.m_pMemory[i + 1];
            v43 = v41;
            v55 = (char **)v41;
            if ( v41 + 1 > downloaderArgs.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char *,int>::Grow(
                this: &downloaderArgs.m_Memory,
                num: v41 - downloaderArgs.m_Memory.m_nAllocationCount + 1);
              v41 = downloaderArgs.m_Size;
              v22 = downloaderArgs.m_Memory.m_pMemory;
              v43 = (int)v55;
            }
            v30 = v41 + 1;
            downloaderArgs.m_Size = v30;
            downloaderArgs.m_pElements = v22;
            if ( v30 - v43 - 1 > 0 )
            {
              _V_memmove(dest: &v22[v43 + 1], src: &v22[v43], count: 4 * (v30 - v43 - 1));
              v43 = (int)v55;
            }
            v44 = &v22[v43];
            if ( v44 != nullptr )
              *v44 = *v53;
            v45 = i;
            if ( v11->m_Size - i - 1 > 0 )
            {
              _V_memmove(
                dest: &v11->m_Memory.m_pMemory[i],
                src: &v11->m_Memory.m_pMemory[i + 1],
                count: 4 * (v11->m_Size - i - 1));
              v45 = i;
            }
            if ( --v11->m_Size - v45 - 1 > 0 )
            {
              _V_memmove(
                dest: &v11->m_Memory.m_pMemory[v45],
                src: &v11->m_Memory.m_pMemory[v45 + 1],
                count: 4 * (v11->m_Size - v45 - 1));
              v45 = i;
            }
            --v11->m_Size;
            i = v45 - 1;
          }
          v46 = v11->m_Size - 1;
          ++i;
        }
        while ( i < v46 );
      }
      if ( RunProcessFromArgs(
             newArgv: &downloaderArgs,
             bShowAppWindow,
             bCreateSuspended: false,
             pWorkingDir: g_BaseAppPath,
             pOut: &pi) )
      {
        v47 = downloaderArgs.m_Memory.m_nGrowSize < 0;
        *hProcess = pi.hProcess;
        if ( !v47 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        return 1;
      }
      else
      {
        if ( downloaderArgs.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        return 0;
      }
    }
    else
    {
      while ( 1 )
      {
        if ( findData.name[0] != 46 )
        {
          V_ComposeFileName(path: cacheDir, filename: findData.name, dest: fullFilename, destSize: 260);
          if ( _unlink(path: fullFilename) != 0 )
            break;
        }
        if ( _findnext64i32(hFile: v7, pfd: &findData) != 0 )
        {
          _findclose(hFile: v7);
          goto LABEL_10;
        }
      }
      _Warning(a1: "_unlink( %s ) failed.\n", fullFilename);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Unable to create cache directory: %s.\n", cacheDir);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407570
// Name: public: void CVMPIServiceConnMgr::AddConsoleOutput(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceConnMgr::AddConsoleOutput(CVMPIServiceConnMgr *this, const char *pMsg)
{
  char *m_pMemory; // edi
  int m_Size; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // esi
  char *v7; // edi
  CUtlVector<char,CUtlMemory<char,int> > data; // [esp+Ch] [ebp-18h] BYREF
  CServiceConnMgr *v9; // [esp+20h] [ebp-4h]

  v9 = this;
  memset(&data, 0, sizeof(data));
  CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&data, num: 1);
  m_pMemory = data.m_Memory.m_pMemory;
  m_Size = data.m_Size + 1;
  v4 = data.m_Size++;
  data.m_pElements = data.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: data.m_Memory.m_pMemory + 1, src: data.m_Memory.m_pMemory, count: v4);
  if ( m_pMemory != nullptr )
    *m_pMemory = 1;
  v5 = m_Size;
  if ( m_Size + 1 > data.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&data,
      num: m_Size - data.m_Memory.m_nAllocationCount + 1);
    m_Size = data.m_Size;
    m_pMemory = data.m_Memory.m_pMemory;
  }
  v6 = m_Size + 1;
  data.m_Size = v6;
  data.m_pElements = m_pMemory;
  if ( v6 - v5 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: v6 - v5 - 1);
  v7 = &m_pMemory[v5];
  if ( v7 != nullptr )
    *v7 = 0;
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: &data,
    elem: v6,
    num: strlen(pMsg) + 1,
    pToInsert: pMsg);
  CServiceConnMgr::SendPacket(this: v9, id: -1, pData: data.m_Memory.m_pMemory, len: data.m_Size);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &data);
}

//------------------------------------------------------------------------------
// Address: 0x00407650
// Name: public: void CVMPIServiceConnMgr::SendCurStateTo(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceConnMgr::SendCurStateTo(CVMPIServiceConnMgr *this, int id)
{
  char *m_pMemory; // edi
  int m_Size; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // esi
  char *v7; // ebx
  int v8; // ebx
  int v9; // esi
  char *v10; // eax
  _BYTE *v11; // eax
  int m_nAllocationCount; // ecx
  int v13; // ebx
  int v14; // esi
  bool *v15; // ebx
  int v16; // esi
  int v17; // ebx
  CUtlVector<char,CUtlMemory<char,int> > data; // [esp+Ch] [ebp-1Ch] BYREF
  CServiceConnMgr *v19; // [esp+20h] [ebp-8h]
  bool v20; // [esp+27h] [ebp-1h]

  v19 = this;
  memset(&data, 0, sizeof(data));
  CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&data, num: 1);
  m_pMemory = data.m_Memory.m_pMemory;
  m_Size = data.m_Size + 1;
  v4 = data.m_Size++;
  data.m_pElements = data.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: data.m_Memory.m_pMemory + 1, src: data.m_Memory.m_pMemory, count: v4);
  if ( m_pMemory != nullptr )
    *m_pMemory = 1;
  v5 = m_Size;
  if ( m_Size + 1 > data.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&data,
      num: m_Size - data.m_Memory.m_nAllocationCount + 1);
    m_Size = data.m_Size;
    m_pMemory = data.m_Memory.m_pMemory;
  }
  v6 = m_Size + 1;
  data.m_Size = v6;
  data.m_pElements = m_pMemory;
  if ( v6 - v5 - 1 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: v6 - v5 - 1);
  v7 = &m_pMemory[v5];
  if ( v7 != nullptr )
    *v7 = 1;
  v8 = v6;
  if ( v6 + 4 > data.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&data,
      num: v6 - data.m_Memory.m_nAllocationCount + 4);
    v6 = data.m_Size;
    m_pMemory = data.m_Memory.m_pMemory;
  }
  v9 = v6 + 4;
  data.m_Size = v9;
  data.m_pElements = m_pMemory;
  if ( v9 - v8 - 4 > 0 )
    _V_memmove(dest: &m_pMemory[v8 + 4], src: &m_pMemory[v8], count: v9 - v8 - 4);
  v10 = &m_pMemory[v8];
  if ( &m_pMemory[v8] != nullptr )
    *v10 = g_iCurState;
  if ( v10 != (char *)-1 )
    v10[1] = BYTE1(g_iCurState);
  if ( v10 != (char *)-2 )
    v10[2] = BYTE2(g_iCurState);
  v11 = v10 + 3;
  if ( v11 != nullptr )
    *v11 = HIBYTE(g_iCurState);
  m_nAllocationCount = data.m_Memory.m_nAllocationCount;
  v20 = g_bScreensaverMode;
  v13 = v9;
  if ( v9 + 1 > data.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&data,
      num: v9 - data.m_Memory.m_nAllocationCount + 1);
    v9 = data.m_Size;
    m_pMemory = data.m_Memory.m_pMemory;
    m_nAllocationCount = data.m_Memory.m_nAllocationCount;
  }
  v14 = v9 + 1;
  data.m_Size = v14;
  data.m_pElements = m_pMemory;
  if ( v14 - v13 - 1 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: v14 - v13 - 1);
    m_nAllocationCount = data.m_Memory.m_nAllocationCount;
  }
  v15 = (bool *)&m_pMemory[v13];
  if ( v15 != nullptr )
    *v15 = v20;
  if ( g_pPassword != nullptr )
  {
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: &data,
      elem: v14,
      num: strlen(g_pPassword) + 1,
      pToInsert: g_pPassword);
    v16 = data.m_Size;
    m_pMemory = data.m_Memory.m_pMemory;
  }
  else
  {
    v17 = v14;
    if ( v14 + 1 > m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&data, num: v14 - m_nAllocationCount + 1);
      v14 = data.m_Size;
      m_pMemory = data.m_Memory.m_pMemory;
    }
    v16 = v14 + 1;
    data.m_Size = v16;
    data.m_pElements = m_pMemory;
    if ( v16 - v17 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: v16 - v17 - 1);
    if ( &m_pMemory[v17] != nullptr )
      m_pMemory[v17] = 0;
  }
  CServiceConnMgr::SendPacket(this: v19, id: -1, pData: m_pMemory, len: v16);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &data);
}

//------------------------------------------------------------------------------
// Address: 0x00407850
// Name: public: virtual void CVMPIServiceLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceLoggingListener::Log(
        CVMPIServiceLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VMPI_WriteToLogFile(pMsg: "%s", pMessage);
  if ( g_pConnMgr != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ConsoleOutputMutex);
    CVMPIServiceConnMgr::AddConsoleOutput(this: g_pConnMgr, pMsg: pMessage);
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&g_ConsoleOutputMutex);
  }
  OutputDebugStringA(lpOutputString: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x004078A0
// Name: void BuildPingHeader(class CUtlVector<char,class CUtlMemory<char,int>> __near &,char,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildPingHeader(CUtlMemory<unsigned char,int> *data, char packetID, __int16 iState)
{
  CUtlMemory<unsigned char,int> *v3; // esi
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v6; // ecx
  int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edi
  int v10; // eax
  unsigned __int8 *v11; // ecx
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // edi
  int v15; // eax
  unsigned __int8 *v16; // ecx
  int v17; // eax
  unsigned __int8 *v18; // eax
  DWORD TickCount; // eax
  unsigned __int8 *v20; // edi
  CUtlVector<char,CUtlMemory<char,int> > *v21; // ebx
  int v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // eax
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // edi
  unsigned __int8 *v27; // edi
  int v28; // eax
  unsigned __int8 *v29; // ecx
  int v30; // eax
  unsigned __int8 *v31; // eax
  unsigned __int8 *v32; // edi
  unsigned __int8 *v33; // edi
  int v34; // eax
  unsigned __int8 *v35; // ecx
  int v36; // eax
  unsigned __int8 *v37; // eax
  __int16 v38; // bx
  DWORD v39; // eax
  unsigned __int8 *v40; // edi
  int v41; // eax
  unsigned __int8 *v42; // ecx
  int v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // edi
  unsigned __int8 *v46; // edi
  int v47; // eax
  unsigned __int8 *v48; // ecx
  int v49; // eax
  unsigned __int8 *v50; // eax
  int v51; // eax
  unsigned __int8 *v52; // edi
  int v53; // eax
  unsigned __int8 *v54; // ecx
  int v55; // eax
  unsigned __int8 *v56; // eax
  int v57; // eax
  unsigned __int8 *v58; // edi
  int v59; // eax
  unsigned __int8 *v60; // ecx
  int v61; // eax
  unsigned __int8 v62; // ch
  unsigned __int8 *v63; // edi
  int v64; // eax
  char computerName[128]; // [esp+Ch] [ebp-84h] BYREF
  unsigned int computerNameLen; // [esp+8Ch] [ebp-4h] BYREF

  computerNameLen = 128;
  GetComputerNameA(lpBuffer: computerName, nSize: &computerNameLen);
  v3 = data;
  m_pMemory = (int)data[1].m_pMemory;
  m_nAllocationCount = data->m_nAllocationCount;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: data, num: m_pMemory - m_nAllocationCount + 1);
  ++v3[1].m_pMemory;
  v6 = v3->m_pMemory;
  v7 = (int)&v3[1].m_pMemory[-m_pMemory - 1];
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: v7);
  v8 = &v3->m_pMemory[m_pMemory];
  if ( v8 != nullptr )
    *v8 = 5;
  v9 = v3[1].m_pMemory;
  v10 = v3->m_nAllocationCount;
  if ( (int)(v9 + 1) > v10 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v9[-v10 + 1]);
  ++v3[1].m_pMemory;
  v11 = v3->m_pMemory;
  v12 = v3[1].m_pMemory - v9 - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[(_DWORD)v9 + 1], src: &v11[(_DWORD)v9], count: v12);
  v13 = &v9[(unsigned int)v3->m_pMemory];
  if ( v13 != nullptr )
    *v13 = packetID;
  v14 = v3[1].m_pMemory;
  v15 = v3->m_nAllocationCount;
  if ( (int)(v14 + 1) > v15 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v14[-v15 + 1]);
  ++v3[1].m_pMemory;
  v16 = v3->m_pMemory;
  v17 = v3[1].m_pMemory - v14 - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[(_DWORD)v14 + 1], src: &v16[(_DWORD)v14], count: v17);
  v18 = &v14[(unsigned int)v3->m_pMemory];
  if ( v18 != nullptr )
    *v18 = iState;
  TickCount = GetTickCount();
  v20 = v3[1].m_pMemory;
  v21 = (CUtlVector<char,CUtlMemory<char,int> > *)(TickCount - g_AppStartTime);
  v22 = v3->m_nAllocationCount;
  data = (CUtlMemory<unsigned char,int> *)v21;
  if ( (int)(v20 + 4) > v22 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v20[-v22 + 4]);
  v3[1].m_pMemory += 4;
  v23 = v3->m_pMemory;
  v24 = v3[1].m_pMemory - v20 - 4;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[(_DWORD)v20 + 4], src: &v23[(_DWORD)v20], count: v24);
  v25 = &v20[(unsigned int)v3->m_pMemory];
  if ( v25 != nullptr )
    *v25 = (unsigned __int8)v21;
  if ( &v3->m_pMemory[(unsigned int)v20] != (unsigned __int8 *)-1 )
    v3->m_pMemory[(unsigned int)v20 + 1] = BYTE1(v21);
  if ( &v3->m_pMemory[(unsigned int)v20] != (unsigned __int8 *)-2 )
    v3->m_pMemory[(unsigned int)v20 + 2] = BYTE2(data);
  v26 = &v3->m_pMemory[(unsigned int)v20 + 3];
  if ( v26 != nullptr )
    *v26 = HIBYTE(data);
  v27 = v3[1].m_pMemory;
  v28 = v3->m_nAllocationCount;
  if ( (int)(v27 + 4) > v28 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v27[-v28 + 4]);
  v3[1].m_pMemory += 4;
  v29 = v3->m_pMemory;
  v30 = v3[1].m_pMemory - v27 - 4;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v30 > 0 )
    _V_memmove(dest: &v29[(_DWORD)v27 + 4], src: &v29[(_DWORD)v27], count: v30);
  v31 = &v27[(unsigned int)v3->m_pMemory];
  if ( v31 != nullptr )
    *v31 = g_SocketPort;
  if ( &v3->m_pMemory[(unsigned int)v27] != (unsigned __int8 *)-1 )
    v3->m_pMemory[(unsigned int)v27 + 1] = BYTE1(g_SocketPort);
  if ( &v3->m_pMemory[(unsigned int)v27] != (unsigned __int8 *)-2 )
    v3->m_pMemory[(unsigned int)v27 + 2] = BYTE2(g_SocketPort);
  v32 = &v3->m_pMemory[(unsigned int)v27 + 3];
  if ( v32 != nullptr )
    *v32 = HIBYTE(g_SocketPort);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
    elem: (int)v3[1].m_pMemory,
    num: strlen(computerName) + 1,
    pToInsert: computerName);
  if ( g_hRunningProcess != nullptr )
  {
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
      elem: (int)v3[1].m_pMemory,
      num: strlen(g_CurMasterName) + 1,
      pToInsert: g_CurMasterName);
  }
  else
  {
    v33 = v3[1].m_pMemory;
    v34 = v3->m_nAllocationCount;
    if ( (int)(v33 + 1) > v34 )
      CUtlMemory<char,int>::Grow(this: v3, num: (int)&v33[-v34 + 1]);
    ++v3[1].m_pMemory;
    v35 = v3->m_pMemory;
    v36 = v3[1].m_pMemory - v33 - 1;
    v3[1].m_nAllocationCount = (int)v3->m_pMemory;
    if ( v36 > 0 )
      _V_memmove(dest: &v35[(_DWORD)v33 + 1], src: &v35[(_DWORD)v33], count: v36);
    v37 = &v33[(unsigned int)v3->m_pMemory];
    if ( v37 != nullptr )
      *v37 = 0;
  }
  v38 = 0;
  data = nullptr;
  if ( g_hRunningProcess != nullptr )
  {
    v39 = GetTickCount();
    v38 = v39 - g_CreateProcessTime;
    data = (CUtlMemory<unsigned char,int> *)(v39 - g_CreateProcessTime);
  }
  v40 = v3[1].m_pMemory;
  v41 = v3->m_nAllocationCount;
  if ( (int)(v40 + 4) > v41 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v40[-v41 + 4]);
  v3[1].m_pMemory += 4;
  v42 = v3->m_pMemory;
  v43 = v3[1].m_pMemory - v40 - 4;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v43 > 0 )
    _V_memmove(dest: &v42[(_DWORD)v40 + 4], src: &v42[(_DWORD)v40], count: v43);
  v44 = &v40[(unsigned int)v3->m_pMemory];
  if ( v44 != nullptr )
    *v44 = v38;
  if ( &v3->m_pMemory[(unsigned int)v40] != (unsigned __int8 *)-1 )
    v3->m_pMemory[(unsigned int)v40 + 1] = HIBYTE(v38);
  if ( &v3->m_pMemory[(unsigned int)v40] != (unsigned __int8 *)-2 )
    v3->m_pMemory[(unsigned int)v40 + 2] = BYTE2(data);
  v45 = &v3->m_pMemory[(unsigned int)v40 + 3];
  if ( v45 != nullptr )
    *v45 = HIBYTE(data);
  if ( g_pPassword != nullptr )
  {
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
      elem: (int)v3[1].m_pMemory,
      num: strlen(g_pPassword) + 1,
      pToInsert: g_pPassword);
  }
  else
  {
    v46 = v3[1].m_pMemory;
    v47 = v3->m_nAllocationCount;
    if ( (int)(v46 + 1) > v47 )
      CUtlMemory<char,int>::Grow(this: v3, num: (int)&v46[-v47 + 1]);
    ++v3[1].m_pMemory;
    v48 = v3->m_pMemory;
    v49 = v3[1].m_pMemory - v46 - 1;
    v3[1].m_nAllocationCount = (int)v3->m_pMemory;
    if ( v49 > 0 )
      _V_memmove(dest: &v48[(_DWORD)v46 + 1], src: &v48[(_DWORD)v46], count: v49);
    v50 = &v46[(unsigned int)v3->m_pMemory];
    if ( v50 != nullptr )
      *v50 = 0;
  }
  v51 = _V_strlen(str: g_VersionString);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
    elem: (int)v3[1].m_pMemory,
    num: v51 + 1,
    pToInsert: g_VersionString);
  GetRunningProcessStats(processorPercentage: (int *)&data, memoryUsageMegabytes: (int *)&iState);
  v52 = v3[1].m_pMemory;
  v53 = v3->m_nAllocationCount;
  if ( (int)(v52 + 1) > v53 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v52[-v53 + 1]);
  ++v3[1].m_pMemory;
  v54 = v3->m_pMemory;
  v55 = v3[1].m_pMemory - v52 - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v55 > 0 )
    _V_memmove(dest: &v54[(_DWORD)v52 + 1], src: &v54[(_DWORD)v52], count: v55);
  v56 = &v52[(unsigned int)v3->m_pMemory];
  if ( v56 != nullptr )
    *v56 = (unsigned __int8)data;
  v57 = _V_strlen(str: g_RunningProcess_ExeName);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
    elem: (int)v3[1].m_pMemory,
    num: v57 + 1,
    pToInsert: g_RunningProcess_ExeName);
  v58 = v3[1].m_pMemory;
  v59 = v3->m_nAllocationCount;
  if ( (int)(v58 + 2) > v59 )
    CUtlMemory<char,int>::Grow(this: v3, num: (int)&v58[-v59 + 2]);
  v3[1].m_pMemory += 2;
  v60 = v3->m_pMemory;
  v61 = v3[1].m_pMemory - v58 - 2;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v61 > 0 )
    _V_memmove(dest: &v60[(_DWORD)v58 + 2], src: &v60[(_DWORD)v58], count: v61);
  v62 = HIBYTE(iState);
  if ( &v58[(unsigned int)v3->m_pMemory] != nullptr )
    v58[(unsigned int)v3->m_pMemory] = iState;
  v63 = &v3->m_pMemory[(unsigned int)v58 + 1];
  if ( v63 != nullptr )
    *v63 = v62;
  v64 = _V_strlen(str: g_RunningProcess_MapName);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: (CUtlVector<char,CUtlMemory<char,int> > *)v3,
    elem: (int)v3[1].m_pMemory,
    num: v64 + 1,
    pToInsert: g_RunningProcess_MapName);
}

//------------------------------------------------------------------------------
// Address: 0x00407D50
// Name: void AddServicesBrowserIP(class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddServicesBrowserIP(const CIPAddr *ipFrom)
{
  int v1; // esi
  int v2; // edi
  unsigned __int16 port; // cx
  int m_Size; // eax
  int v5; // esi
  CServicesBrowserInfo *m_pMemory; // ecx
  int v7; // eax
  CServicesBrowserInfo *v8; // eax
  CServicesBrowserInfo *v9; // esi
  CServicesBrowserInfo info; // [esp+Ch] [ebp-Ch] BYREF

  v1 = 0;
  if ( g_ServicesBrowsers.m_Size <= 0 )
  {
LABEL_5:
    CIPAddr::CIPAddr(this: &info.m_Addr);
    port = ipFrom->port;
    *(_DWORD *)info.m_Addr.ip = *(_DWORD *)ipFrom->ip;
    info.m_Addr.port = port;
    info.m_flLastPingTime = _Plat_FloatTime();
    m_Size = g_ServicesBrowsers.m_Size;
    v5 = g_ServicesBrowsers.m_Size;
    if ( g_ServicesBrowsers.m_Size + 1 > g_ServicesBrowsers.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *)&g_ServicesBrowsers,
        num: g_ServicesBrowsers.m_Size - g_ServicesBrowsers.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ServicesBrowsers.m_Size;
    }
    m_pMemory = g_ServicesBrowsers.m_Memory.m_pMemory;
    g_ServicesBrowsers.m_Size = m_Size + 1;
    v7 = m_Size - v5;
    g_ServicesBrowsers.m_pElements = g_ServicesBrowsers.m_Memory.m_pMemory;
    if ( v7 > 0 )
    {
      _V_memmove(
        dest: &g_ServicesBrowsers.m_Memory.m_pMemory[v5 + 1],
        src: &g_ServicesBrowsers.m_Memory.m_pMemory[v5],
        count: 12 * v7);
      m_pMemory = g_ServicesBrowsers.m_Memory.m_pMemory;
    }
    v8 = &m_pMemory[v5];
    if ( v8 != nullptr )
      *v8 = info;
  }
  else
  {
    v2 = 0;
    while ( !CIPAddr::operator==(this: &g_ServicesBrowsers.m_Memory.m_pMemory[v2].m_Addr, o: ipFrom) )
    {
      ++v1;
      ++v2;
      if ( v1 >= g_ServicesBrowsers.m_Size )
        goto LABEL_5;
    }
    v9 = &g_ServicesBrowsers.m_Memory.m_pMemory[v1];
    v9->m_flLastPingTime = _Plat_FloatTime();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407E50
// Name: void SendStateToServicesBrowsers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendStateToServicesBrowsers()
{
  int v0; // esi
  __int16 v1; // ax
  char *m_pMemory; // ebx
  int v3; // edi
  CUtlVector<char,CUtlMemory<char,int> > data; // [esp+8h] [ebp-14h] BYREF

  v0 = 0;
  if ( g_hRunningProcess != nullptr )
  {
    v1 = g_Waiting_bPatching + 1;
  }
  else if ( g_Waiting_hProcess != nullptr )
  {
    v1 = g_Waiting_bPatching ? 2 : 5;
  }
  else if ( g_iCurState == 2 )
  {
    v1 = 3;
  }
  else if ( !g_bScreensaverMode || g_bScreensaverRunning )
  {
    v1 = 0;
  }
  else
  {
    v1 = 4;
  }
  memset(&data, 0, sizeof(data));
  BuildPingHeader((CUtlMemory<unsigned char,int> *)&data, packetID: 74, iState: v1);
  m_pMemory = data.m_Memory.m_pMemory;
  if ( g_ServicesBrowsers.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      g_pSocket->SendTo(
        this: g_pSocket,
        a2: &g_ServicesBrowsers.m_Memory.m_pMemory[v3].m_Addr,
        a3: m_pMemory,
        a4: data.m_Size);
      ++v0;
      ++v3;
    }
    while ( v0 < g_ServicesBrowsers.m_Size );
  }
  if ( data.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00407F30
// Name: void SendPatchCommandToUIs(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendPatchCommandToUIs(unsigned int dwInstallerProcessId)
{
  char *m_pMemory; // edi
  int m_Size; // esi
  int v3; // eax
  int m_nAllocationCount; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // esi
  char *v9; // edi
  int v10; // eax
  char *v11; // edi
  int v12; // esi
  int v13; // eax
  int v14; // ebx
  int v15; // esi
  char **v16; // ebx
  int v17; // ebx
  int v18; // esi
  char *v19; // ebx
  int v20; // ebx
  int v21; // esi
  char **v22; // edi
  int v23; // eax
  char pOut[8192]; // [esp+Ch] [ebp-2274h] BYREF
  char dest[260]; // [esp+200Ch] [ebp-274h] BYREF
  char v26[260]; // [esp+2110h] [ebp-170h] BYREF
  char pDest[64]; // [esp+2214h] [ebp-6Ch] BYREF
  CUtlVector<char,CUtlMemory<char,int> > v28; // [esp+2254h] [ebp-2Ch] BYREF
  int v29; // [esp+2268h] [ebp-18h]
  CUtlVector<char,CUtlMemory<char,int> > v30; // [esp+226Ch] [ebp-14h] BYREF

  _Msg(a1: "SendPatchCommandToUIs\n ");
  memset(&v28, 0, sizeof(v28));
  CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v28, num: 1);
  m_pMemory = v28.m_Memory.m_pMemory;
  m_Size = v28.m_Size + 1;
  v3 = v28.m_Size++;
  v28.m_pElements = v28.m_Memory.m_pMemory;
  if ( v3 > 0 )
    _V_memmove(dest: v28.m_Memory.m_pMemory + 1, src: v28.m_Memory.m_pMemory, count: v3);
  if ( m_pMemory != nullptr )
    *m_pMemory = 1;
  m_nAllocationCount = v28.m_Memory.m_nAllocationCount;
  v5 = m_Size;
  v29 = m_Size;
  if ( m_Size + 1 > v28.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: (CUtlMemory<unsigned char,int> *)&v28,
      num: m_Size - v28.m_Memory.m_nAllocationCount + 1);
    m_Size = v28.m_Size;
    m_pMemory = v28.m_Memory.m_pMemory;
    v5 = v29;
    m_nAllocationCount = v28.m_Memory.m_nAllocationCount;
  }
  v6 = m_Size + 1;
  v28.m_Size = v6;
  v28.m_pElements = m_pMemory;
  if ( v6 - v5 - 1 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: v6 - v5 - 1);
    v5 = v29;
    m_nAllocationCount = v28.m_Memory.m_nAllocationCount;
  }
  if ( &m_pMemory[v5] != nullptr )
    m_pMemory[v5] = 2;
  v7 = v6;
  v29 = v6;
  if ( v6 + 1 > m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v28, num: v6 - m_nAllocationCount + 1);
    v6 = v28.m_Size;
    m_pMemory = v28.m_Memory.m_pMemory;
    v7 = v29;
  }
  v8 = v6 + 1;
  v28.m_Size = v8;
  v28.m_pElements = m_pMemory;
  if ( v8 - v7 - 1 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: v8 - v7 - 1);
    v7 = v29;
  }
  v9 = &m_pMemory[v7];
  if ( v9 != nullptr )
    *v9 = 1;
  v10 = _V_strlen(str: g_FileCachePath);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: &v28,
    elem: v8,
    num: v10 + 1,
    pToInsert: g_FileCachePath);
  V_ComposeFileName(path: g_FileCachePath, filename: "WaitAndRestart.exe", dest, destSize: 260);
  V_ComposeFileName(path: g_BaseAppPath, filename: "vmpi_service_ui.exe", dest: v26, destSize: 260);
  V_snprintf(pDest, maxLen: 64, pFormat: "*%lu", dwInstallerProcessId);
  memset(&v30, 0, sizeof(v30));
  CUtlMemory<char *,int>::Grow(this: (CUtlMemory<char *,int> *)&v30, num: 1);
  v11 = v30.m_Memory.m_pMemory;
  v12 = v30.m_Size + 1;
  v13 = v30.m_Size++;
  v30.m_pElements = v30.m_Memory.m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: v30.m_Memory.m_pMemory + 4, src: v30.m_Memory.m_pMemory, count: 4 * v13);
  if ( v11 != nullptr )
    *(_DWORD *)v11 = dest;
  v14 = v12;
  if ( v12 + 1 > v30.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char *,int>::Grow(this: (CUtlMemory<char *,int> *)&v30, num: v12 - v30.m_Memory.m_nAllocationCount + 1);
    v12 = v30.m_Size;
    v11 = v30.m_Memory.m_pMemory;
  }
  v15 = v12 + 1;
  v30.m_Size = v15;
  v30.m_pElements = v11;
  if ( v15 - v14 - 1 > 0 )
    _V_memmove(dest: &v11[4 * v14 + 4], src: &v11[4 * v14], count: 4 * (v15 - v14 - 1));
  v16 = (char **)&v11[4 * v14];
  if ( v16 != nullptr )
    *v16 = pDest;
  v17 = v15;
  if ( v15 + 1 > v30.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char *,int>::Grow(this: (CUtlMemory<char *,int> *)&v30, num: v15 - v30.m_Memory.m_nAllocationCount + 1);
    v15 = v30.m_Size;
    v11 = v30.m_Memory.m_pMemory;
  }
  v18 = v15 + 1;
  v30.m_Size = v18;
  v30.m_pElements = v11;
  if ( v18 - v17 - 1 > 0 )
    _V_memmove(dest: &v11[4 * v17 + 4], src: &v11[4 * v17], count: 4 * (v18 - v17 - 1));
  v19 = &v11[4 * v17];
  if ( v19 != nullptr )
    *(_DWORD *)v19 = g_BaseAppPath;
  v20 = v18;
  if ( v18 + 1 > v30.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char *,int>::Grow(this: (CUtlMemory<char *,int> *)&v30, num: v18 - v30.m_Memory.m_nAllocationCount + 1);
    v18 = v30.m_Size;
    v11 = v30.m_Memory.m_pMemory;
  }
  v30.m_Size = v18 + 1;
  v21 = v18 - v20;
  v30.m_pElements = v11;
  if ( v21 > 0 )
    _V_memmove(dest: &v11[4 * v20 + 4], src: &v11[4 * v20], count: 4 * v21);
  v22 = (char **)&v11[4 * v20];
  if ( v22 != nullptr )
    *v22 = v26;
  BuildCommandLineFromArgs(newArgv: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v30, pOut, outLen: 0x2000u);
  v23 = _V_strlen(str: pOut);
  CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
    this: &v28,
    elem: v28.m_Size,
    num: v23 + 1,
    pToInsert: pOut);
  if ( g_pConnMgr != nullptr )
  {
    CServiceConnMgr::SendPacket(this: g_pConnMgr, id: -1, pData: v28.m_Memory.m_pMemory, len: v28.m_Size);
    Sleep(dwMilliseconds: 0x3E8u);
  }
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &v30);
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &v28);
}

//------------------------------------------------------------------------------
// Address: 0x00408250
// Name: void HandlePacket_STOP_SERVICE(class bf_read __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandlePacket_STOP_SERVICE(bf_read *buf, const CIPAddr *ipFrom)
{
  CWaitTimer timer; // [esp+Ch] [ebp-8h] BYREF

  _Msg(a1: "Got a STOP_SERVICE packet. Shutting down...\n");
  CWaitTimer::CWaitTimer(this: &timer, flSeconds: 1.0);
  AddServicesBrowserIP(ipFrom);
  SendStateToServicesBrowsers();
  while ( CWaitTimer::ShouldKeepWaiting(this: &timer) )
  {
    Sleep(dwMilliseconds: 0xC8u);
    AddServicesBrowserIP(ipFrom);
    SendStateToServicesBrowsers();
  }
  StopUI();
  ServiceHelpers_ExitEarly();
}

//------------------------------------------------------------------------------
// Address: 0x004082E0
// Name: void HandlePacket_FORCE_PASSWORD_CHANGE(class bf_read __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandlePacket_FORCE_PASSWORD_CHANGE(bf_read *buf)
{
  int v1; // esi
  char newPassword[512]; // [esp+4h] [ebp-200h] BYREF

  CBitRead::ReadString(this: buf, pStr: newPassword, maxLen: 512, bLine: false, pOutNumChars: nullptr);
  _Msg(a1: "Got a FORCE_PASSWORD_CHANGE (%s) packet.\n", newPassword);
  free(pMem: g_pPassword);
  v1 = _V_strlen(str: newPassword) + 1;
  g_pPassword = (char *)operator new(nSize: v1);
  V_strncpy(pDest: g_pPassword, pSrc: newPassword, maxLen: v1);
  if ( g_pConnMgr != nullptr )
    CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00408370
// Name: public: class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near & CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::operator=(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<char *,CUtlMemory<char *,int> > *__thiscall CUtlVector<char *,CUtlMemory<char *,int>>::operator=(
        CUtlVector<char *,CUtlMemory<char *,int> > *this,
        const CUtlVector<char *,CUtlMemory<char *,int> > *other)
{
  int m_Size; // edi
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004083B0
// Name: public: virtual void CVMPIServiceConnMgr::OnNewConnection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceConnMgr::OnNewConnection(CVMPIServiceConnMgr *this, int id)
{
  CVMPIServiceConnMgr::SendCurStateTo(this, id);
  _Msg(a1: "vmpi_service version %s connected to the UI.\n", g_VersionString);
}

//------------------------------------------------------------------------------
// Address: 0x004083E0
// Name: void LoadStateFromRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadStateFromRegistry()
{
  unsigned int val; // [esp+0h] [ebp-Ch] BYREF
  unsigned int size; // [esp+4h] [ebp-8h] BYREF
  unsigned int type; // [esp+8h] [ebp-4h] BYREF

  if ( g_hVMPIServiceKey != nullptr )
  {
    val = 0;
    type = 4;
    size = 4;
    if ( RegQueryValueExA(
           hKey: g_hVMPIServiceKey,
           lpValueName: "ScreensaverMode",
           lpReserved: nullptr,
           lpType: &type,
           lpData: (LPBYTE)&val,
           lpcbData: &size) == 0
      && type == 4
      && size == 4 )
    {
      g_bScreensaverMode = val != 0;
    }
    if ( RegQueryValueExA(
           hKey: g_hVMPIServiceKey,
           lpValueName: "Disabled",
           lpReserved: nullptr,
           lpType: &type,
           lpData: (LPBYTE)&val,
           lpcbData: &size) == 0
      && type == 4
      && size == 4
      && val != 0
      && g_pConnMgr != nullptr )
    {
      g_iCurState = 2;
      CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408490
// Name: void KillRunningProcess(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KillRunningProcess(const char *pReason, bool bGoToIdle)
{
  if ( g_Waiting_hProcess != nullptr )
  {
    TerminateProcess(hProcess: g_Waiting_hProcess, uExitCode: 1u);
    CloseHandle(hObject: g_Waiting_hProcess);
    g_Waiting_hProcess = nullptr;
  }
  if ( g_hRunningProcess != nullptr )
  {
    if ( pReason != nullptr )
      _Msg(a1: pReason);
    SendEndStatus();
    TerminateProcess(hProcess: g_hRunningProcess, uExitCode: 1u);
    g_RunningProcess_ExeName[0] = 0;
    g_RunningProcess_MapName[0] = 0;
    CloseHandle(hObject: g_hRunningThread);
    g_hRunningThread = nullptr;
    CloseHandle(hObject: g_hRunningProcess);
    g_hRunningProcess = nullptr;
    g_CurJobPriority = -1;
    if ( bGoToIdle && g_pConnMgr != nullptr )
    {
      g_iCurState = 0;
      CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408540
// Name: void TimeoutJobIDs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeoutJobIDs()
{
  int m_Head; // edi
  UtlLinkedListElem_t<CJobMemory,int> *m_pMemory; // eax
  int m_Next; // ebx
  double flCurTime; // [esp+4h] [ebp-8h]

  flCurTime = _Plat_FloatTime();
  m_Head = g_JobMemories.m_Head;
  if ( g_JobMemories.m_Head != -1 )
  {
    m_pMemory = g_JobMemories.m_Memory.m_pMemory;
    do
    {
      m_Next = m_pMemory[m_Head].m_Next;
      if ( flCurTime - m_pMemory[m_Head].m_Element.m_Time > 60.0 )
      {
        CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::Unlink(
          this: &g_JobMemories,
          elem: m_Head);
        g_JobMemories.m_Memory.m_pMemory[m_Head].m_Next = g_JobMemories.m_FirstFree;
        m_pMemory = g_JobMemories.m_Memory.m_pMemory;
        g_JobMemories.m_FirstFree = m_Head;
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085D0
// Name: bool CheckJobID(class bf_read __near &,int __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CheckJobID(bf_read *buf, int *jobID)
{
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v4; // ecx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  const unsigned int *v7; // edx
  unsigned int v8; // edi
  int v9; // eax
  const unsigned int *v10; // ecx
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  const unsigned int *v19; // edx
  unsigned int v20; // edi
  int v21; // eax
  const unsigned int *v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // ebx
  unsigned int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  const unsigned int *v31; // edx
  unsigned int v32; // edi
  int v33; // eax
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // ebx
  unsigned int v37; // edx
  int v38; // ecx
  unsigned int v39; // eax
  int v40; // ecx
  int v41; // edi
  const unsigned int *v42; // ecx
  const unsigned int *v43; // edx
  const unsigned int *v44; // edx
  unsigned int v45; // edi
  int v46; // eax
  const unsigned int *v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // ebx

  TimeoutJobIDs();
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail >= 32 )
  {
    m_nInBufWord = buf->m_nInBufWord;
    v4 = m_nBitsAvail - 32;
    buf->m_nBitsAvail = v4;
    if ( v4 != 0 )
    {
      buf->m_nInBufWord = 0;
    }
    else
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        buf->m_nInBufWord = *m_pDataIn;
        buf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    goto LABEL_18;
  }
  v7 = buf->m_pBufferEnd;
  v8 = buf->m_nInBufWord;
  v9 = 32 - m_nBitsAvail;
  v10 = buf->m_pDataIn;
  if ( v10 == v7 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
  }
  else
  {
    if ( v10 > v7 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_15;
    }
    buf->m_nInBufWord = *v10;
  }
  buf->m_pDataIn = v10 + 1;
LABEL_15:
  if ( buf->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v11 = buf->m_nInBufWord;
    v12 = (v11 & CBitBuffer::s_nMaskTable[v9]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v9;
    v13 = v11 >> v9;
    m_nInBufWord = v12 | v8;
    buf->m_nInBufWord = v13;
  }
LABEL_18:
  *jobID = m_nInBufWord;
  v14 = buf->m_nBitsAvail;
  if ( v14 >= 32 )
  {
    v15 = buf->m_nInBufWord;
    v16 = v14 - 32;
    buf->m_nBitsAvail = v16;
    if ( v16 != 0 )
    {
      buf->m_nInBufWord = 0;
    }
    else
    {
      v17 = buf->m_pDataIn;
      v18 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v17 == v18 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v17 + 1;
      }
      else if ( v17 <= v18 )
      {
        buf->m_nInBufWord = *v17;
        buf->m_pDataIn = v17 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    goto LABEL_35;
  }
  v19 = buf->m_pBufferEnd;
  v20 = buf->m_nInBufWord;
  v21 = 32 - v14;
  v22 = buf->m_pDataIn;
  if ( v22 == v19 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
  }
  else
  {
    if ( v22 > v19 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_32;
    }
    buf->m_nInBufWord = *v22;
  }
  buf->m_pDataIn = v22 + 1;
LABEL_32:
  if ( buf->m_bOverflow )
  {
    v15 = 0;
  }
  else
  {
    v23 = buf->m_nInBufWord;
    v24 = (v23 & CBitBuffer::s_nMaskTable[v21]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v21;
    v25 = v23 >> v21;
    v15 = v24 | v20;
    buf->m_nInBufWord = v25;
  }
LABEL_35:
  jobID[1] = v15;
  v26 = buf->m_nBitsAvail;
  if ( v26 >= 32 )
  {
    v27 = buf->m_nInBufWord;
    v28 = v26 - 32;
    buf->m_nBitsAvail = v28;
    if ( v28 != 0 )
    {
      buf->m_nInBufWord = 0;
    }
    else
    {
      v29 = buf->m_pDataIn;
      v30 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v29 == v30 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v29 + 1;
      }
      else if ( v29 <= v30 )
      {
        buf->m_nInBufWord = *v29;
        buf->m_pDataIn = v29 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    goto LABEL_52;
  }
  v31 = buf->m_pBufferEnd;
  v32 = buf->m_nInBufWord;
  v33 = 32 - v26;
  v34 = buf->m_pDataIn;
  if ( v34 == v31 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
  }
  else
  {
    if ( v34 > v31 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_49;
    }
    buf->m_nInBufWord = *v34;
  }
  buf->m_pDataIn = v34 + 1;
LABEL_49:
  if ( buf->m_bOverflow )
  {
    v27 = 0;
  }
  else
  {
    v35 = buf->m_nInBufWord;
    v36 = (v35 & CBitBuffer::s_nMaskTable[v33]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v33;
    v37 = v35 >> v33;
    v27 = v36 | v32;
    buf->m_nInBufWord = v37;
  }
LABEL_52:
  jobID[2] = v27;
  v38 = buf->m_nBitsAvail;
  if ( v38 >= 32 )
  {
    v39 = buf->m_nInBufWord;
    v40 = v38 - 32;
    buf->m_nBitsAvail = v40;
    if ( v40 != 0 )
    {
      buf->m_nInBufWord = 0;
      v41 = v39;
    }
    else
    {
      v42 = buf->m_pDataIn;
      v43 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v42 == v43 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v42 + 1;
        v41 = v39;
      }
      else
      {
        if ( v42 <= v43 )
        {
          buf->m_nInBufWord = *v42;
          buf->m_pDataIn = v42 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        v41 = v39;
      }
    }
    goto LABEL_70;
  }
  v44 = buf->m_pBufferEnd;
  v45 = buf->m_nInBufWord;
  v46 = 32 - v38;
  v47 = buf->m_pDataIn;
  if ( v47 == v44 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
  }
  else
  {
    if ( v47 > v44 )
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
      goto LABEL_67;
    }
    buf->m_nInBufWord = *v47;
  }
  buf->m_pDataIn = v47 + 1;
LABEL_67:
  if ( buf->m_bOverflow )
  {
    v41 = 0;
  }
  else
  {
    v48 = buf->m_nInBufWord;
    v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v46;
    v41 = v49 | v45;
    buf->m_nInBufWord = v48 >> v46;
  }
LABEL_70:
  jobID[3] = v41;
  return FindJobMemory(id: jobID) == 0 && !buf->m_bOverflow;
}

//------------------------------------------------------------------------------
// Address: 0x00408950
// Name: void VMPI_Waiter_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Waiter_Term()
{
  CVMPIServiceConnMgr *v0; // esi

  if ( g_Waiting_hProcess != nullptr )
  {
    TerminateProcess(hProcess: g_Waiting_hProcess, uExitCode: 1u);
    CloseHandle(hObject: g_Waiting_hProcess);
    g_Waiting_hProcess = nullptr;
  }
  if ( g_hRunningProcess != nullptr )
  {
    SendEndStatus();
    TerminateProcess(hProcess: g_hRunningProcess, uExitCode: 1u);
    g_RunningProcess_ExeName[0] = 0;
    g_RunningProcess_MapName[0] = 0;
    CloseHandle(hObject: g_hRunningThread);
    g_hRunningThread = nullptr;
    CloseHandle(hObject: g_hRunningProcess);
    g_hRunningProcess = nullptr;
    g_CurJobPriority = -1;
  }
  if ( g_pConnMgr != nullptr )
  {
    CServiceConnMgr::Term(this: g_pConnMgr);
    v0 = g_pConnMgr;
    if ( g_pConnMgr != nullptr )
    {
      CServiceConnMgr::~CServiceConnMgr(this: g_pConnMgr);
      free(pMem: v0);
    }
    g_pConnMgr = nullptr;
  }
  if ( g_pSocket != nullptr )
  {
    g_pSocket->Release(this: g_pSocket);
    g_pSocket = nullptr;
  }
  g_pPerfTracker->Release(this: g_pPerfTracker);
  g_pPerfTracker = nullptr;
  if ( g_pFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFileSystemModule);
    g_pFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A40
// Name: bool VMPI_Waiter_Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VMPI_Waiter_Init()
{
  bool result; // al
  HANDLE CurrentProcess; // eax
  CServiceConnMgr *v2; // eax
  CVMPIServiceConnMgr *v3; // esi
  CVMPIServiceConnMgr *v4; // ecx
  ISocket *IPSocket; // eax
  int v6; // esi
  unsigned int dummyType; // [esp+0h] [ebp-10h] BYREF
  unsigned int dwValLen; // [esp+4h] [ebp-Ch] BYREF
  HKEY__ *hKey; // [esp+8h] [ebp-8h] BYREF
  unsigned int dwVal; // [esp+Ch] [ebp-4h] BYREF

  result = Sys_LoadInterface(
             pModuleName: "filesystem_stdio",
             pInterfaceVersionName: "VBaseFileSystem011",
             pOutModule: &g_pFileSystemModule,
             pOutInterface: (void **)&g_pBaseFileSystem);
  if ( result )
  {
    hKey = nullptr;
    RegCreateKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Valve\\VMPI", phkResult: &hKey);
    dwVal = 0;
    dummyType = 4;
    dwValLen = 4;
    if ( RegQueryValueExA(
           hKey,
           lpValueName: "LowPriority",
           lpReserved: nullptr,
           lpType: &dummyType,
           lpData: (LPBYTE)&dwVal,
           lpcbData: &dwValLen) != 0 )
    {
      RegSetValueExA(
        hKey,
        lpValueName: "LowPriority",
        Reserved: 0,
        dwType: 4u,
        lpData: (const BYTE *)&dwVal,
        cbData: 4u);
    }
    else if ( dwVal != 0 )
    {
      CurrentProcess = GetCurrentProcess();
      SetPriorityClass(hProcess: CurrentProcess, dwPriorityClass: 0x40u);
    }
    v2 = (CServiceConnMgr *)operator new(nSize: 0x38u);
    v3 = (CVMPIServiceConnMgr *)v2;
    if ( v2 != nullptr )
    {
      CServiceConnMgr::CServiceConnMgr(this: v2);
      v3->__vftable = (CVMPIServiceConnMgr_vtbl *)&CVMPIServiceConnMgr::`vftable';
      v4 = v3;
    }
    else
    {
      v4 = nullptr;
    }
    g_pConnMgr = v4;
    if ( CServiceConnMgr::InitServer(this: v4) == 0 )
      _Msg(a1: "ERROR INITIALIZING CONNMGR\n");
    IPSocket = CreateIPSocket();
    g_pSocket = IPSocket;
    if ( IPSocket != nullptr )
    {
      v6 = 23397;
      while ( 1 )
      {
        g_SocketPort = v6;
        if ( IPSocket->BindToAny(this: IPSocket, a2: v6) )
          break;
        if ( ++v6 > 23412 )
          break;
        IPSocket = g_pSocket;
      }
      if ( v6 == 23412 )
      {
        _Msg(a1: "Error binding a socket to port %d.\n", 23397);
        VMPI_Waiter_Term();
        return false;
      }
      else
      {
        g_iBoundPort = v6;
        g_pPerfTracker = CreatePerfTracker();
        return true;
      }
    }
    else
    {
      _Msg(a1: "Error creating a socket.\n");
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408BB0
// Name: void RunInDLL(char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunInDLL(const char *pFilename, CUtlVector<char *,CUtlMemory<char *,int> > *newArgv)
{
  char v2; // bl
  CSysModule *Module; // eax
  CSysModule *v4; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  void (__thiscall ***v6)(_DWORD, int, char **); // edi
  void (__thiscall ***v7)(_DWORD, int, char **); // eax
  CSysModule *pModule; // [esp+0h] [ebp-4h]

  if ( g_pConnMgr != nullptr )
  {
    g_iCurState = 1;
    CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
  }
  v2 = 0;
  Module = Sys_LoadModule(pModuleName: pFilename);
  v4 = Module;
  pModule = Module;
  if ( Module == nullptr )
    goto LABEL_8;
  Factory = Sys_GetFactory(pModule: Module);
  if ( Factory != nullptr )
  {
    v6 = (void (__thiscall ***)(_DWORD, int, char **))Factory(a1: "launchable_dll_1", a2: nullptr);
    if ( v6 != nullptr )
    {
      _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
      v7 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
      (**v7)(a1: v7, a2: newArgv->m_Size, a3: newArgv->m_Memory.m_pMemory);
      (**v6)(a1: v6, a2: newArgv->m_Size, a3: newArgv->m_Memory.m_pMemory);
      v2 = 1;
      _LoggingSystem_PopLoggingState(a1: 0);
      v4 = pModule;
    }
  }
  Sys_UnloadModule(pModule: v4);
  if ( v2 == 0 )
LABEL_8:
    _Msg(a1: "Error running VRAD (or VVIS) out of DLL '%s'\n", pFilename);
  if ( g_pConnMgr != nullptr )
  {
    g_iCurState = 0;
    CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408C90
// Name: void RunProcessAtCommandLine(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunProcessAtCommandLine(
        CUtlVector<char *,CUtlMemory<char *,int> > *newArgv,
        bool bShowAppWindow,
        bool bCreateSuspended,
        int iPriority)
{
  const char *LastErrorString; // eax
  _PROCESS_INFORMATION pi; // [esp+4h] [ebp-10h] BYREF

  if ( RunProcessFromArgs(newArgv, bShowAppWindow, bCreateSuspended, pWorkingDir: g_FileCachePath, pOut: &pi) )
  {
    if ( g_pConnMgr != nullptr )
    {
      g_iCurState = 1;
      CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
    }
    if ( newArgv->m_Size > 0 && *newArgv->m_Memory.m_pMemory != nullptr )
    {
      V_FileBase(in: *(const char **)newArgv->m_Memory.m_pMemory, out: g_RunningProcess_ExeName, maxlen: 260);
      if ( _V_stricmp(s1: g_RunningProcess_ExeName, s2: "vrad") == 0
        || _V_stricmp(s1: g_RunningProcess_ExeName, s2: "vvis") == 0 )
      {
        V_FileBase(in: newArgv->m_Memory.m_pMemory[newArgv->m_Size - 1], out: g_RunningProcess_MapName, maxlen: 260);
      }
    }
    g_hRunningProcess = pi.hProcess;
    g_dwRunningProcessId = pi.dwProcessId;
    g_hRunningThread = pi.hThread;
    g_pPerfTracker->Init(this: g_pPerfTracker, a2: pi.dwProcessId);
    g_CurJobPriority = iPriority;
    g_CreateProcessTime = GetTickCount();
    SendStartStatus(bStatus: true);
  }
  else
  {
    LastErrorString = GetLastErrorString();
    _Msg(a1: " - ERROR in CreateProcess (%s)!\n", LastErrorString);
    SendStartStatus(bStatus: false);
    g_CurJobPriority = -1;
    g_RunningProcess_ExeName[0] = 0;
    g_RunningProcess_MapName[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408DC0
// Name: bool WaitForProcessToExit(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WaitForProcessToExit()
{
  if ( g_hRunningProcess != nullptr )
  {
    if ( WaitForSingleObject(hHandle: g_hRunningProcess, dwMilliseconds: 0) == 258 )
      return 1;
    _Msg(a1: "Finished!\n ");
    SendEndStatus();
    if ( g_pConnMgr != nullptr )
    {
      g_iCurState = 0;
      CVMPIServiceConnMgr::SendCurStateTo(this: g_pConnMgr, id: -1);
    }
    g_CurJobPriority = -1;
    CloseHandle(hObject: g_hRunningThread);
    CloseHandle(hObject: g_hRunningProcess);
    g_hRunningThread = nullptr;
    g_hRunningProcess = nullptr;
    g_RunningProcess_MapName[0] = 0;
    g_RunningProcess_ExeName[0] = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408E60
// Name: bool CheckDownloaderFinished(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckDownloaderFinished()
{
  int i; // esi
  char DLLFilename[260]; // [esp+4h] [ebp-208h] BYREF
  char testFilename[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_Waiting_hProcess == nullptr )
    return 0;
  if ( _Plat_FloatTime() - g_Waiting_StartTime > 30.0 )
  {
    TerminateProcess(hProcess: g_Waiting_hProcess, uExitCode: 1u);
    CloseHandle(hObject: g_Waiting_hProcess);
    g_Waiting_hProcess = nullptr;
    return 0;
  }
  if ( WaitForSingleObject(hHandle: g_Waiting_hProcess, dwMilliseconds: 0) != 0 )
    return 0;
  CloseHandle(hObject: g_Waiting_hProcess);
  g_Waiting_hProcess = nullptr;
  V_ComposeFileName(path: g_FileCachePath, filename: "ReadyToGo.txt", dest: testFilename, destSize: 260);
  if ( access(path: testFilename, amode: 0) != 0 )
    return 0;
  if ( g_bSuperDebugMode )
    AdjustSuperDebugArgs(args: &g_Waiting_Argv);
  V_strncpy(pDest: g_CurMasterName, pSrc: "<unknown>", maxLen: 512);
  for ( i = 1; i < g_Waiting_Argv.m_Size - 1; ++i )
  {
    if ( _V_stricmp(s1: g_Waiting_Argv.m_Memory.m_pMemory[i], s2: "-mpi_MasterName") == 0 )
      V_strncpy(pDest: g_CurMasterName, pSrc: g_Waiting_Argv.m_Memory.m_pMemory[i + 1], maxLen: 512);
  }
  if ( FindArg(argc: __argc, argv: __argv, pArgName: "-TryDLLMode", pDefaultValue: (char *)pDefaultValue) != nullptr
    && g_RunMode == 1
    && GetDLLFilename(newArgv: &g_Waiting_Argv, pDLLFilename: DLLFilename) != 0
    && !g_Waiting_bPatching )
  {
    RunInDLL(pFilename: DLLFilename, newArgv: &g_Waiting_Argv);
LABEL_18:
    CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &g_Waiting_Argv);
    return 0;
  }
  RunProcessAtCommandLine(
    newArgv: &g_Waiting_Argv,
    bShowAppWindow: g_Waiting_bShowAppWindow,
    bCreateSuspended: g_Waiting_bPatching,
    iPriority: g_Waiting_Priority);
  if ( !g_Waiting_bPatching )
    goto LABEL_18;
  SendPatchCommandToUIs(dwInstallerProcessId: g_dwRunningProcessId);
  ResumeThread(hThread: g_hRunningThread);
  CloseHandle(hObject: g_hRunningProcess);
  CloseHandle(hObject: g_hRunningThread);
  g_hRunningThread = nullptr;
  g_hRunningProcess = nullptr;
  g_RunningProcess_ExeName[0] = 0;
  g_RunningProcess_MapName[0] = 0;
  ServiceHelpers_ExitEarly();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409090
// Name: public: int CUtlLinkedList<class CJobMemory,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CJobMemory,int>,int>>::AddToTail(class CJobMemory const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AddToTail(
        CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int> > *this,
        const CJobMemory *src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CJobMemory,int> *m_pMemory; // ecx
  unsigned int v6; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CJobMemory,int> *v8; // esi

  result = CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::Unlink(this, elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409120
// Name: public: virtual void CVMPIServiceConnMgr::HandlePacket(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIServiceConnMgr::HandlePacket(CVMPIServiceConnMgr *this, const char *pData, int len)
{
  const char *v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ecx

  v4 = pData;
  switch ( *pData )
  {
    case 2:
      KillRunningProcess(pReason: "Got a VMPI_SERVICE_DISABLE packet", bGoToIdle: true);
      g_iCurState = 2;
      CVMPIServiceConnMgr::SendCurStateTo(this, id: -1);
      SaveStateToRegistry(a1: v5);
      break;
    case 3:
      if ( g_iCurState == 2 )
      {
        g_iCurState = 0;
        CVMPIServiceConnMgr::SendCurStateTo(this, id: -1);
      }
      SaveStateToRegistry(a1: (unsigned int)v4);
      break;
    case 4:
      SetPassword(pPassword: pData + 1);
      CVMPIServiceConnMgr::SendCurStateTo(this, id: -1);
      break;
    case 5:
      _Msg(a1: "Got a VMPI_SERVICE_EXIT packet.\n ");
      ServiceHelpers_ExitEarly();
      break;
    case 7:
      g_bScreensaverMode = pData[1] != 0;
      CVMPIServiceConnMgr::SendCurStateTo(this, id: -1);
      SaveStateToRegistry(a1: v6);
      break;
    case 0x4E:
      if ( _Plat_FloatTime() - g_flLastKillProcessTime > 5.0 )
      {
        KillRunningProcess(pReason: "Got a KILL_PROCESS packet. Stopping the worker executable.\n", bGoToIdle: true);
        g_flLastKillProcessTime = _Plat_FloatTime();
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004092A0
// Name: void HandlePacket_LOOKING_FOR_WORKERS(class bf_read __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandlePacket_LOOKING_FOR_WORKERS(bf_read *buf, const CIPAddr *ipFrom)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  __int16 v4; // di
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  __int16 v12; // ax
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // ecx
  __int16 v18; // dx
  const unsigned int *v19; // ecx
  unsigned int v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edi
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebx
  unsigned int v26; // edx
  const unsigned int *m_pData; // ebx
  int m_nDataBits; // eax
  int v29; // edi
  int v30; // eax
  int v31; // eax
  const unsigned int *v32; // eax
  const unsigned int *v33; // ecx
  const unsigned int *v34; // edx
  int v35; // ecx
  const unsigned int *v36; // eax
  char *v37; // edx
  signed int v38; // eax
  int v39; // ecx
  unsigned int v40; // eax
  int v41; // ecx
  unsigned int v42; // edx
  __int16 v43; // di
  const unsigned int *v44; // eax
  const unsigned int *v45; // ecx
  const unsigned int *v46; // edx
  unsigned int v47; // edi
  int v48; // eax
  const unsigned int *v49; // ecx
  unsigned int v50; // edx
  unsigned int v51; // ebx
  int v52; // edi
  char *v53; // ebx
  int m_Size; // edi
  int v55; // edi
  int v56; // ebx
  char **m_pMemory; // ebx
  int v58; // edi
  _DWORD *v59; // ebx
  bool v60; // bl
  char **v61; // esi
  char versionString[512]; // [esp+4h] [ebp-434h] BYREF
  char cacheDir[260]; // [esp+204h] [ebp-234h] BYREF
  char strMainIP[128]; // [esp+308h] [ebp-130h] BYREF
  char strDownloaderIP[128]; // [esp+388h] [ebp-B0h] BYREF
  CJobMemory src; // [esp+408h] [ebp-30h] BYREF
  int iPriority; // [esp+41Ch] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > newArgv; // [esp+420h] [ebp-18h] BYREF
  char *bPatching; // [esp+434h] [ebp-4h]

  if ( g_Waiting_hProcess != nullptr )
    return;
  CBitRead::ReadString(this: buf, pStr: versionString, maxLen: 512, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = buf->m_pBufferEnd;
    m_nInBufWord = buf->m_nInBufWord;
    v10 = 16 - m_nBitsAvail;
    m_pDataIn = buf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_16:
        if ( buf->m_bOverflow )
        {
          v12 = 0;
          goto LABEL_21;
        }
        v13 = buf->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v10]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v10;
        v4 = v14 | m_nInBufWord;
        v5 = v13 >> v10;
        goto LABEL_19;
      }
      buf->m_nInBufWord = *m_pDataIn;
    }
    buf->m_pDataIn = m_pDataIn + 1;
    goto LABEL_16;
  }
  v3 = buf->m_nInBufWord;
  v4 = v3;
  buf->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail == 16 )
  {
    v6 = buf->m_pDataIn;
    v7 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      buf->m_nInBufWord = *v6;
      buf->m_pDataIn = v6 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
    goto LABEL_20;
  }
  v5 = HIWORD(v3);
LABEL_19:
  buf->m_nInBufWord = v5;
LABEL_20:
  v12 = v4;
LABEL_21:
  v15 = buf->m_nBitsAvail;
  bPatching = (char *)v12;
  if ( v15 < 16 )
  {
    v21 = buf->m_pBufferEnd;
    v22 = buf->m_nInBufWord;
    v16 = 16 - v15;
    v23 = buf->m_pDataIn;
    if ( v23 == v21 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v21 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_36;
      }
      buf->m_nInBufWord = *v23;
    }
    buf->m_pDataIn = v23 + 1;
LABEL_36:
    if ( buf->m_bOverflow )
    {
      LOWORD(v16) = 0;
    }
    else
    {
      v24 = buf->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v16]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v16;
      v26 = v24 >> v16;
      LOWORD(v16) = v25 | v22;
      buf->m_nInBufWord = v26;
    }
    goto LABEL_39;
  }
  v16 = buf->m_nInBufWord;
  v17 = v15 - 16;
  v18 = v16;
  buf->m_nBitsAvail = v17;
  if ( v17 != 0 )
  {
    buf->m_nInBufWord = HIWORD(v16);
  }
  else
  {
    v16 = (unsigned int)buf->m_pDataIn;
    v19 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( (const unsigned int *)v16 == v19 )
    {
      buf->m_pDataIn = (const unsigned int *)(v16 + 4);
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      LOWORD(v16) = v18;
    }
    else
    {
      if ( v16 <= (unsigned int)v19 )
      {
        v20 = *(_DWORD *)v16;
        buf->m_pDataIn = (const unsigned int *)(v16 + 4);
        buf->m_nInBufWord = v20;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
      LOWORD(v16) = v18;
    }
  }
LABEL_39:
  iPriority = (__int16)v16;
  if ( !CheckJobID(buf, jobID: g_CurJobID) )
    return;
  memset(&newArgv, 0, sizeof(newArgv));
  GetArgsFromBuffer(buf, &newArgv, bShowAppWindow: &g_Waiting_bShowAppWindow);
  m_pData = buf->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( m_nDataBits >= buf->m_nDataBits )
      m_nDataBits = buf->m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  v29 = buf->m_nDataBits;
  if ( (int)((v29 - m_nDataBits) & 0xFFFFFFF8) >= 8 )
  {
    v30 = buf->m_nBitsAvail;
    if ( v30 >= 8 )
    {
      v31 = v30 - 8;
      buf->m_nBitsAvail = v31;
      if ( v31 != 0 )
      {
        buf->m_nInBufWord >>= 8;
      }
      else
      {
        v32 = buf->m_pDataIn;
        v33 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v32 == v33 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v32 + 1;
        }
        else if ( v32 <= v33 )
        {
          buf->m_nInBufWord = *v32;
          buf->m_pDataIn = v32 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      goto LABEL_61;
    }
    v34 = buf->m_pBufferEnd;
    v35 = 8 - v30;
    v36 = buf->m_pDataIn;
    if ( v36 == v34 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v36 > v34 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_59;
      }
      buf->m_nInBufWord = *v36;
    }
    buf->m_pDataIn = v36 + 1;
LABEL_59:
    if ( !buf->m_bOverflow )
    {
      buf->m_nInBufWord >>= v35;
      buf->m_nBitsAvail = 32 - v35;
    }
  }
LABEL_61:
  v37 = bPatching;
  if ( m_pData != nullptr )
  {
    v38 = 32 * (buf->m_pDataIn - m_pData) - buf->m_nBitsAvail + 8 * (buf->m_nDataBytes & 3);
    if ( v38 >= v29 )
      v38 = v29;
  }
  else
  {
    v38 = 0;
  }
  if ( (int)((v29 - v38) & 0xFFFFFFF8) < 16 )
    goto LABEL_85;
  v39 = buf->m_nBitsAvail;
  if ( v39 < 16 )
  {
    v46 = buf->m_pBufferEnd;
    v47 = buf->m_nInBufWord;
    v48 = 16 - v39;
    v49 = buf->m_pDataIn;
    if ( v49 == v46 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v49 > v46 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_80:
        if ( buf->m_bOverflow )
        {
          v43 = 0;
          goto LABEL_84;
        }
        v50 = buf->m_nInBufWord;
        v51 = (v50 & CBitBuffer::s_nMaskTable[v48]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v48;
        v43 = v51 | v47;
        v42 = v50 >> v48;
        goto LABEL_83;
      }
      buf->m_nInBufWord = *v49;
    }
    buf->m_pDataIn = v49 + 1;
    goto LABEL_80;
  }
  v40 = buf->m_nInBufWord;
  v41 = v39 - 16;
  v42 = 0;
  v43 = v40;
  buf->m_nBitsAvail = v41;
  if ( v41 == 0 )
  {
    v44 = buf->m_pDataIn;
    v45 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v44 == v45 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v44 + 1;
      goto LABEL_84;
    }
    if ( v44 <= v45 )
    {
      buf->m_nInBufWord = *v44;
      buf->m_pDataIn = v44 + 1;
      goto LABEL_84;
    }
    buf->m_bOverflow = true;
LABEL_83:
    buf->m_nInBufWord = v42;
    goto LABEL_84;
  }
  buf->m_nInBufWord = HIWORD(v40);
LABEL_84:
  v37 = (char *)v43;
LABEL_85:
  V_snprintf(
    pDest: strDownloaderIP,
    maxLen: 128,
    pFormat: "%d.%d.%d.%d:%d",
    ipFrom->ip[0],
    ipFrom->ip[1],
    ipFrom->ip[2],
    ipFrom->ip[3],
    v37);
  V_snprintf(
    pDest: strMainIP,
    maxLen: 128,
    pFormat: "%d.%d.%d.%d:%d",
    ipFrom->ip[0],
    ipFrom->ip[1],
    ipFrom->ip[2],
    ipFrom->ip[3],
    bPatching);
  v52 = _V_strlen(str: "-mpi_worker") + 1;
  v53 = (char *)operator new(nSize: v52);
  V_strncpy(pDest: v53, pSrc: "-mpi_worker", maxLen: v52);
  m_Size = newArgv.m_Size;
  if ( newArgv.m_Size + 1 > newArgv.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char *,int>::Grow(this: &newArgv.m_Memory, num: newArgv.m_Size - newArgv.m_Memory.m_nAllocationCount + 1);
    m_Size = newArgv.m_Size;
  }
  v55 = m_Size + 1;
  newArgv.m_Size = v55;
  newArgv.m_pElements = newArgv.m_Memory.m_pMemory;
  if ( v55 - 2 > 0 )
    _V_memmove(dest: newArgv.m_Memory.m_pMemory + 2, src: newArgv.m_Memory.m_pMemory + 1, count: 4 * (v55 - 2));
  if ( newArgv.m_Memory.m_pMemory != (char **)-4 )
    *((_DWORD *)newArgv.m_Memory.m_pMemory + 1) = v53;
  v56 = _V_strlen(str: strDownloaderIP) + 1;
  bPatching = (char *)operator new(nSize: v56);
  V_strncpy(pDest: bPatching, pSrc: strDownloaderIP, maxLen: v56);
  if ( v55 + 1 > newArgv.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char *,int>::Grow(this: &newArgv.m_Memory, num: v55 - newArgv.m_Memory.m_nAllocationCount + 1);
    v55 = newArgv.m_Size;
  }
  m_pMemory = newArgv.m_Memory.m_pMemory;
  newArgv.m_Size = v55 + 1;
  v58 = v55 - 2;
  newArgv.m_pElements = newArgv.m_Memory.m_pMemory;
  if ( v58 > 0 )
    _V_memmove(dest: newArgv.m_Memory.m_pMemory + 3, src: newArgv.m_Memory.m_pMemory + 2, count: 4 * v58);
  v59 = m_pMemory + 2;
  if ( v59 != nullptr )
    *v59 = bPatching;
  v60 = false;
  LOBYTE(bPatching) = 0;
  if ( versionString[0] != 0 )
  {
    v60 = true;
    LOBYTE(bPatching) = 1;
    KillRunningProcess(pReason: "Starting a patch..", bGoToIdle: true);
  }
  if ( WaitForProcessToExit() != 0 )
  {
    if ( iPriority <= g_CurJobPriority )
    {
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &newArgv);
      CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&newArgv);
      return;
    }
    KillRunningProcess(pReason: "Interrupted by a higher priority process", bGoToIdle: true);
  }
  g_CurRespondAddr = *ipFrom;
  if ( !g_Waiting_bShowAppWindow )
    g_Waiting_bShowAppWindow = FindArg(
                                 argc: __argc,
                                 argv: __argv,
                                 pArgName: "-mpi_ShowAppWindow",
                                 pDefaultValue: (char *)pDefaultValue) != nullptr;
  if ( StartDownloadingAppFiles(
         &newArgv,
         cacheDir,
         cacheDirLen: 260,
         bShowAppWindow: g_Waiting_bShowAppWindow,
         hProcess: &g_Waiting_hProcess,
         (bool)bPatching) != 0 )
  {
    if ( newArgv.m_Size >= 3 )
    {
      v61 = newArgv.m_Memory.m_pMemory;
      if ( _V_stricmp(s1: *((const char **)newArgv.m_Memory.m_pMemory + 2), s2: strDownloaderIP) == 0 )
      {
        free(pMem: v61[2]);
        v61[2] = CopyString(pStr: strMainIP);
      }
    }
    g_Waiting_StartTime = _Plat_FloatTime();
    CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &g_Waiting_Argv);
    CUtlVector<char *,CUtlMemory<char *,int>>::operator=(this: &g_Waiting_Argv, other: &newArgv);
    g_Waiting_Priority = iPriority;
    g_Waiting_bPatching = v60;
    CUtlVector<char *,CUtlMemory<char *,int>>::Purge(this: &newArgv);
  }
  else
  {
    CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &newArgv);
  }
  TimeoutJobIDs();
  *(_OWORD *)src.m_ID = *(_OWORD *)g_CurJobID;
  src.m_Time = _Plat_FloatTime();
  CUtlLinkedList<CJobMemory,int,0,int,CUtlMemory<UtlLinkedListElem_t<CJobMemory,int>,int>>::AddToTail(
    this: &g_JobMemories,
    &src);
  SendStateToServicesBrowsers();
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: (CUtlVector<char,CUtlMemory<char,int> > *)&newArgv);
}

//------------------------------------------------------------------------------
// Address: 0x004099A0
// Name: void VMPI_Waiter_Update(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_Waiter_Update()
{
  int v0; // eax
  unsigned int m_nInBufWord_low; // edi
  int v2; // eax
  unsigned int v3; // edx
  unsigned int v4; // esi
  int v5; // esi
  unsigned int m_nInBufWord; // edi
  int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // edx
  char data[768]; // [esp+4h] [ebp-42Ch] BYREF
  char pwString[256]; // [esp+304h] [ebp-12Ch] BYREF
  bf_read buf; // [esp+404h] [ebp-2Ch] BYREF
  CIPAddr ipFrom; // [esp+428h] [ebp-8h] BYREF

  if ( g_Waiting_hProcess == nullptr || !g_Waiting_bPatching )
  {
    *(_DWORD *)ipFrom.ip = 0;
    SystemParametersInfoA(uiAction: 0x72u, uiParam: 0, pvParam: &ipFrom, fWinIni: 0);
    g_bScreensaverRunning = *(_DWORD *)ipFrom.ip != 0;
    if ( *(_DWORD *)ipFrom.ip == 0 && g_bScreensaverMode )
      KillRunningProcess(pReason: "Screensaver not running", bGoToIdle: true);
  }
  HandleWindowMessages();
  UpdateServicesBrowserIPs();
  WaitForProcessToExit();
  while ( CheckDownloaderFinished() == 0 )
  {
    CIPAddr::CIPAddr(this: &ipFrom);
    v0 = g_pSocket->RecvFrom(this: g_pSocket, a2: data, a3: 768, a4: &ipFrom);
    if ( v0 <= 0 )
      return;
    buf.m_bOverflow = false;
    buf.m_pDebugName = nullptr;
    buf.m_nDataBits = -1;
    buf.m_nDataBytes = 0;
    CBitRead::StartReading(this: &buf, pData: data, nBytes: v0, iStartBit: 0, nBits: -1);
    if ( buf.m_nBitsAvail < 8 )
    {
      v2 = 8 - buf.m_nBitsAvail;
      if ( buf.m_pDataIn == buf.m_pBufferEnd )
        goto LABEL_60;
      if ( buf.m_pDataIn > buf.m_pBufferEnd )
        goto LABEL_60;
      v3 = *buf.m_pDataIn++;
      if ( buf.m_bOverflow )
        goto LABEL_60;
      v4 = (v3 & CBitBuffer::s_nMaskTable[v2]) << SLOBYTE(buf.m_nBitsAvail);
      buf.m_nBitsAvail = 32 - v2;
      m_nInBufWord_low = v4 | buf.m_nInBufWord;
      buf.m_nInBufWord = v3 >> v2;
    }
    else
    {
      m_nInBufWord_low = LOBYTE(buf.m_nInBufWord);
      buf.m_nBitsAvail -= 8;
      if ( buf.m_nBitsAvail != 0 )
      {
        buf.m_nInBufWord >>= 8;
      }
      else
      {
        buf.m_nBitsAvail = 32;
        if ( buf.m_pDataIn == buf.m_pBufferEnd )
        {
          buf.m_nBitsAvail = 1;
          buf.m_nInBufWord = 0;
          ++buf.m_pDataIn;
        }
        else if ( buf.m_pDataIn <= buf.m_pBufferEnd )
        {
          buf.m_nInBufWord = *buf.m_pDataIn++;
        }
        else
        {
          buf.m_bOverflow = true;
          buf.m_nInBufWord = 0;
        }
      }
    }
    if ( m_nInBufWord_low == 5 )
    {
      CBitRead::ReadString(this: &buf, pStr: pwString, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      if ( buf.m_nBitsAvail < 8 )
      {
        m_nInBufWord = buf.m_nInBufWord;
        v7 = 8 - buf.m_nBitsAvail;
        if ( buf.m_pDataIn == buf.m_pBufferEnd )
        {
          buf.m_nBitsAvail = 1;
          buf.m_nInBufWord = 0;
          ++buf.m_pDataIn;
          buf.m_bOverflow = true;
          v5 = 0;
        }
        else if ( buf.m_pDataIn <= buf.m_pBufferEnd )
        {
          v8 = *buf.m_pDataIn;
          buf.m_nInBufWord = *buf.m_pDataIn++;
          if ( buf.m_bOverflow )
          {
            v5 = 0;
          }
          else
          {
            v9 = (v8 & CBitBuffer::s_nMaskTable[v7]) << SLOBYTE(buf.m_nBitsAvail);
            buf.m_nBitsAvail = 32 - v7;
            buf.m_nInBufWord = v8 >> v7;
            v5 = v9 | m_nInBufWord;
          }
        }
        else
        {
          buf.m_bOverflow = true;
          buf.m_nInBufWord = 0;
          v5 = 0;
        }
      }
      else
      {
        v5 = LOBYTE(buf.m_nInBufWord);
        buf.m_nBitsAvail -= 8;
        if ( buf.m_nBitsAvail != 0 )
        {
          buf.m_nInBufWord >>= 8;
        }
        else
        {
          buf.m_nBitsAvail = 32;
          if ( buf.m_pDataIn == buf.m_pBufferEnd )
          {
            buf.m_nBitsAvail = 1;
            buf.m_nInBufWord = 0;
            ++buf.m_pDataIn;
          }
          else if ( buf.m_pDataIn <= buf.m_pBufferEnd )
          {
            buf.m_nInBufWord = *buf.m_pDataIn++;
          }
          else
          {
            buf.m_bOverflow = true;
            buf.m_nInBufWord = 0;
          }
        }
      }
      if ( pwString[0] == -111 || v5 != 71 )
      {
        switch ( v5 )
        {
          case 'N':
            if ( _Plat_FloatTime() - g_flLastKillProcessTime > 5.0 )
            {
              KillRunningProcess(
                pReason: "Got a KILL_PROCESS packet. Stopping the worker executable.\n",
                bGoToIdle: true);
              AddServicesBrowserIP(&ipFrom);
              SendStateToServicesBrowsers();
              g_flLastKillProcessTime = _Plat_FloatTime();
            }
            break;
          case 'I':
            AddServicesBrowserIP(&ipFrom);
            SendStateToServicesBrowsers();
            break;
          case 'M':
            HandlePacket_STOP_SERVICE(&buf, &ipFrom);
            return;
          case 'O':
            HandlePacket_LOOKING_FOR_WORKERS(&buf, &ipFrom);
            break;
          case 'R':
            HandlePacket_FORCE_PASSWORD_CHANGE(&buf);
            break;
          default:
            break;
        }
LABEL_55:
        if ( g_iCurState != 2 && (!g_bScreensaverMode || g_bScreensaverRunning) && v5 == 71 )
          HandlePacket_LOOKING_FOR_WORKERS(&buf, &ipFrom);
        goto LABEL_60;
      }
      if ( pwString[0] != 0 )
      {
        if ( g_pPassword != nullptr && _V_stricmp(s1: g_pPassword, s2: pwString) == 0 )
          goto LABEL_55;
      }
      else if ( g_pPassword == nullptr || *g_pPassword == 0 )
      {
        goto LABEL_55;
      }
    }
LABEL_60:
    WaitForProcessToExit();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D40
// Name: void RunMainLoop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunMainLoop()
{
  while ( !ServiceHelpers_ShouldExit() )
  {
    VMPI_Waiter_Update();
    CServiceConnMgr::Update(this: g_pConnMgr);
    Sleep(dwMilliseconds: 0x32u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D70
// Name: void ServiceThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServiceThreadFn()
{
  if ( VMPI_Waiter_Init() )
  {
    StartVWatch();
    RunMainLoop();
    StopVWatch();
    VMPI_Waiter_Term();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D90
// Name: void RunService(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunService()
{
  if ( !ServiceHelpers_StartService(
          pServiceName: "VMPI",
          pFn: (void (__cdecl *)(void *))ServiceThreadFn,
          pParam: nullptr) )
  {
    _Msg(a1: "Service manager not started. Running as console app.\n");
    g_RunMode = 1;
    if ( VMPI_Waiter_Init() )
    {
      StartVWatch();
      RunMainLoop();
      StopVWatch();
      VMPI_Waiter_Term();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409DE0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  HMODULE ModuleHandleA; // eax
  const char *Arg; // edi
  int v7; // esi

  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &g_VMPIServiceLoggingListener);
  RegCreateKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Valve\\VMPI", phkResult: &g_hVMPIServiceKey);
  LoadStringA(hInstance, uID: 0x66u, lpBuffer: g_VersionString, cchBufferMax: 64);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: g_BaseAppPath, nSize: 0x104u) == 0 )
  {
    _Warning(a1: "GetModuleFileName failed.\n");
    _LoggingSystem_PopLoggingState(a1: 0);
    return 0;
  }
  V_StripLastDir(dirName: g_BaseAppPath, maxlen: 260);
  V_ComposeFileName(path: g_BaseAppPath, filename: "vmpi_service_cache", dest: g_FileCachePath, destSize: 260);
  Arg = FindArg(argc: __argc, argv: __argv, pArgName: "-mpi_pw", pDefaultValue: nullptr);
  free(pMem: g_pPassword);
  if ( Arg != nullptr )
  {
    v7 = _V_strlen(str: Arg) + 1;
    g_pPassword = (char *)operator new(nSize: v7);
    V_strncpy(pDest: g_pPassword, pSrc: Arg, maxLen: v7);
  }
  else
  {
    g_pPassword = nullptr;
  }
  g_RunMode = 2
            - (FindArg(argc: __argc, argv: __argv, pArgName: "-console", pDefaultValue: (char *)pDefaultValue) != nullptr);
  if ( FindArg(argc: __argc, argv: __argv, pArgName: "-superdebug", pDefaultValue: (char *)pDefaultValue) != nullptr )
    g_bSuperDebugMode = true;
  g_AppStartTime = GetTickCount();
  g_bMinimized = FindArg(argc: __argc, argv: __argv, pArgName: "-minimized", pDefaultValue: (char *)pDefaultValue) != nullptr;
  ServiceHelpers_Init();
  g_hInstance = hInstance;
  LoadStateFromRegistry();
  if ( g_RunMode == 1 )
  {
    if ( VMPI_Waiter_Init() )
    {
      StartVWatch();
      RunMainLoop();
      StopVWatch();
      VMPI_Waiter_Term();
      _LoggingSystem_PopLoggingState(a1: 0);
      return 0;
    }
  }
  else
  {
    RunService();
  }
  _LoggingSystem_PopLoggingState(a1: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409FCC
// Name: PdhOpenQueryA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhOpenQueryA(LPCSTR szDataSource, DWORD_PTR dwUserData, PDH_HQUERY *phQuery)
{
  return __imp__PdhOpenQueryA@12(szDataSource, dwUserData, phQuery);
}

//------------------------------------------------------------------------------
// Address: 0x00409FD2
// Name: PdhCloseQuery(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhCloseQuery(PDH_HQUERY hQuery)
{
  return __imp__PdhCloseQuery@4(hQuery);
}

//------------------------------------------------------------------------------
// Address: 0x00409FD8
// Name: PdhRemoveCounter(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhRemoveCounter(PDH_HCOUNTER hCounter)
{
  return __imp__PdhRemoveCounter@4(hCounter);
}

//------------------------------------------------------------------------------
// Address: 0x00409FDE
// Name: PdhGetFormattedCounterValue(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhGetFormattedCounterValue(
        PDH_HCOUNTER hCounter,
        DWORD dwFormat,
        LPDWORD lpdwType,
        PPDH_FMT_COUNTERVALUE pValue)
{
  return __imp__PdhGetFormattedCounterValue@16(hCounter, dwFormat, lpdwType, pValue);
}

//------------------------------------------------------------------------------
// Address: 0x00409FE4
// Name: PdhCollectQueryData(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhCollectQueryData(PDH_HQUERY hQuery)
{
  return __imp__PdhCollectQueryData@4(hQuery);
}

//------------------------------------------------------------------------------
// Address: 0x00409FEA
// Name: PdhAddCounterA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhAddCounterA(
        PDH_HQUERY hQuery,
        LPCSTR szFullCounterPath,
        DWORD_PTR dwUserData,
        PDH_HCOUNTER *phCounter)
{
  return __imp__PdhAddCounterA@16(hQuery, szFullCounterPath, dwUserData, phCounter);
}

//------------------------------------------------------------------------------
// Address: 0x00409FF0
// Name: PdhEnumObjectItemsA(x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhEnumObjectItemsA(
        LPCSTR szDataSource,
        LPCSTR szMachineName,
        LPCSTR szObjectName,
        PZZSTR mszCounterList,
        LPDWORD pcchCounterListLength,
        PZZSTR mszInstanceList,
        LPDWORD pcchInstanceListLength,
        DWORD dwDetailLevel,
        DWORD dwFlags)
{
  return __imp__PdhEnumObjectItemsA@36(
           szDataSource,
           szMachineName,
           szObjectName,
           mszCounterList,
           pcchCounterListLength,
           mszInstanceList,
           pcchInstanceListLength,
           dwDetailLevel,
           dwFlags);
}

//------------------------------------------------------------------------------
// Address: 0x00409FF6
// Name: PdhEnumObjectsA(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
PDH_STATUS __stdcall PdhEnumObjectsA(
        LPCSTR szDataSource,
        LPCSTR szMachineName,
        PZZSTR mszObjectList,
        LPDWORD pcchBufferSize,
        DWORD dwDetailLevel,
        BOOL bRefresh)
{
  return __imp__PdhEnumObjectsA@24(szDataSource, szMachineName, mszObjectList, pcchBufferSize, dwDetailLevel, bRefresh);
}
