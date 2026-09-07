// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/tier0/afxmem_override.cpp
// Functions: 6
// ============================================================

#include "public\tier0\afxmem_override.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: int AfxNewHandler(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl __noreturn AfxNewHandler()
{
  AfxThrowMemoryException();
}

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: int (*AfxSetNewHandler(int (*)(unsigned int)))(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__stdcall AfxSetNewHandler(int (__cdecl *pfnNewHandler)(unsigned int)))(unsigned int)
{
  int (__cdecl *result)(unsigned int); // eax

  result = _afxNewHandler;
  _afxNewHandler = pfnNewHandler;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025B4B
// Name: public: static void __near * CNoTrackObject::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HLOCAL __stdcall CNoTrackObject::operator new(SIZE_T nSize)
{
  HLOCAL result; // eax

  result = LocalAlloc(uFlags: 0x40u, uBytes: nSize);
  if ( result == nullptr )
    AfxThrowMemoryException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  void *v1; // esi

  v1 = _malloc_crt(size: nSize);
  if ( v1 == nullptr && _afxNewHandler != nullptr )
    _afxNewHandler(a1: nSize);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: void __near * operator new[](unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new[](unsigned int nSize)
{
  return operator new(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10001080
// Name: void operator delete(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete(void *p)
{
  free(pMem: p);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1035F2DA
// Name: public: static void __near * CNoTrackObject::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HLOCAL __stdcall CNoTrackObject::operator new(SIZE_T nSize)
{
  HLOCAL result; // eax

  result = LocalAlloc(uFlags: 0x40u, uBytes: nSize);
  if ( result == nullptr )
    AfxThrowMemoryException();
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from vsoundedit (Missing functions)
// ============================================================
namespace vsoundedit {

//------------------------------------------------------------------------------
// Address: 0x00410580
// Name: int AfxNewHandler(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl __noreturn AfxNewHandler()
{
  AfxThrowMemoryException();
}

//------------------------------------------------------------------------------
// Address: 0x00410590
// Name: int (*AfxSetNewHandler(int (*)(unsigned int)))(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__stdcall AfxSetNewHandler(int (__cdecl *pfnNewHandler)(unsigned int)))(unsigned int)
{
  int (__cdecl *result)(unsigned int); // eax

  result = _afxNewHandler;
  _afxNewHandler = pfnNewHandler;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427FE5
// Name: public: static void __near * CNoTrackObject::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HLOCAL __stdcall CNoTrackObject::operator new(SIZE_T nSize)
{
  HLOCAL result; // eax

  result = LocalAlloc(uFlags: 0x40u, uBytes: nSize);
  if ( result == nullptr )
    AfxThrowMemoryException();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428002
// Name: public: static void CNoTrackObject::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall CNoTrackObject::operator delete(void *p)
{
  if ( p != nullptr )
    LocalFree(hMem: p);
}

//------------------------------------------------------------------------------
// Address: 0x004105B0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  void *v1; // esi

  v1 = _malloc_crt(size: nSize);
  if ( v1 == nullptr && _afxNewHandler != nullptr )
    _afxNewHandler(a1: nSize);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004105F0
// Name: void operator delete(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete(void *p)
{
  free(pMem: p);
}

//------------------------------------------------------------------------------
// Address: 0x00410600
// Name: void __near * operator new[](unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new[](unsigned int nSize)
{
  return operator new(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x00428018
// Name: public: void __near * CThreadSlotData::GetThreadValue(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CThreadSlotData::GetThreadValue(CThreadSlotData *this, int nSlot)
{
  _RTL_CRITICAL_SECTION *p_m_sect; // ebx
  _DWORD *Value; // eax
  int v5; // edi

  p_m_sect = &this->m_sect;
  EnterCriticalSection(lpCriticalSection: &this->m_sect);
  if ( nSlot > 0
    && nSlot < this->m_nMax
    && (Value = TlsGetValue(dwTlsIndex: this->m_tlsIndex)) != nullptr
    && nSlot < Value[2] )
  {
    v5 = *(_DWORD *)(Value[3] + 4 * nSlot);
    LeaveCriticalSection(lpCriticalSection: p_m_sect);
    return v5;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: p_m_sect);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042806A
// Name: public: class CNoTrackObject __near * CThreadLocalObject::GetDataNA(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNoTrackObject *__thiscall CThreadLocalObject::GetDataNA(CThreadLocalObject *this)
{
  if ( this->m_nSlot != 0 && _afxThreadData != nullptr )
    return (CNoTrackObject *)CThreadSlotData::GetThreadValue(this: _afxThreadData, nSlot: this->m_nSlot);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00428084
// Name: public: class CNoTrackObject __near * CProcessLocalObject::GetData(class CNoTrackObject __near * (*)(void))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNoTrackObject *__thiscall CProcessLocalObject::GetData(
        CProcessLocalObject *this,
        CNoTrackObject *(__stdcall *pfnCreateObject)())
{
  if ( this->m_pObject == nullptr )
  {
    AfxLockGlobals(nLockType: 0x10u);
    if ( this->m_pObject == nullptr )
      this->m_pObject = pfnCreateObject();
    AfxUnlockGlobals(nLockType: 0x10u);
  }
  return this->m_pObject;
}

//------------------------------------------------------------------------------
// Address: 0x004280D4
// Name: public: CProcessLocalObject::~CProcessLocalObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CProcessLocalObject::~CProcessLocalObject(CProcessLocalObject *this)
{
  if ( this->m_pObject != nullptr )
    ((void (__thiscall *)(CNoTrackObject *volatile, int))this->m_pObject->dtr_CNoTrackObject)(
      a1: this->m_pObject,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004280FD
// Name: public: void CSimpleList::AddHead(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSimpleList::AddHead(CSimpleList *this, char *p)
{
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  *(_DWORD *)&p[this->m_nNextOffset] = this->m_pHead;
  this->m_pHead = p;
}

} // namespace vsoundedit
