// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gmemoryheap.cpp
// Functions: 5
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gmemoryheap.h"

//------------------------------------------------------------------------------
// Address: 0x100614D0
// Name: public: void GMemoryHeap::GetHeapInfo(struct GMemoryHeap::HeapInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeap::GetHeapInfo(int this, void *a2)
{
  qmemcpy(a2, (const void *)(this + 28), 0x28u);
}

//------------------------------------------------------------------------------
// Address: 0x100614F0
// Name: public: void GMemoryHeap::ReleaseOnFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GMemoryHeap::ReleaseOnFree(_DWORD *this, void *ptr)
{
  *(this + 6) = ptr;
  return ptr;
}

//------------------------------------------------------------------------------
// Address: 0x10061500
// Name: protected: GMemoryHeap::GMemoryHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeap::GMemoryHeap(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),CFuncMemPolicyNone> *this)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),CFuncMemPolicyNone> *v2; // eax
  char *v3; // ecx

  LODWORD(this->m_pfnProxied) = &GMemoryHeap::`vftable';
  HIDWORD(this->m_pfnProxied) = 0;
  this->m_pObject = (CMatRenderContextBase *)1;
  *((_DWORD *)&this->m_pObject + 1) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 9) = 0x2000;
  *((_DWORD *)this + 10) = 0x2000;
  v2 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),CFuncMemPolicyNone> *)((char *)this + 68);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 16;
  *((_DWORD *)this + 11) = -1;
  *((_QWORD *)this + 6) = 0;
  *((_DWORD *)this + 14) = 0;
  if ( this == (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),CFuncMemPolicyNone> *)-68 )
    v3 = nullptr;
  else
    v3 = (char *)this + 64;
  LODWORD(v2->m_pfnProxied) = v3;
  DWORD1(v2->m_pfnProxied) = v3;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76), spinCount: 0);
  *((_WORD *)this + 50) = 257;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10061590
// Name: public: void GMemoryHeap::VisitChildHeaps(struct GMemoryHeap::HeapVisitor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeap::VisitChildHeaps(GMemoryHeap *this, struct GMemoryHeap::HeapVisitor *a2)
{
  GMemoryHeap *i; // esi
  char **v4; // eax
  GLock *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = &this->HeapLock;
  EnterCriticalSection(lpCriticalSection: &this->HeapLock.cs);
  for ( i = this->ChildHeaps.Root.pNext; ; i = i->pNext )
  {
    v4 = this == (GMemoryHeap *)-68 ? nullptr : &this->Info.pName;
    if ( i == (GMemoryHeap *)v4 )
      break;
    a2->Visit(this: a2, a2: this, a3: i);
  }
  LeaveCriticalSection(lpCriticalSection: &lpCriticalSection->cs);
}

//------------------------------------------------------------------------------
// Address: 0x100D4350
// Name: public: class GMemoryHeap __near * GFxMovieDataDef::LoadTaskData::GetImageHeap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::GetImageHeap(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  _DWORD v6[8]; // [esp+4h] [ebp-20h] BYREF

  if ( *((_DWORD *)this + 8) == 0 )
  {
    v2 = *((_DWORD *)this + 7);
    v6[7] = 0;
    v6[0] = 4;
    v6[1] = 32;
    v6[2] = 4096;
    v6[3] = 0;
    v6[4] = -1;
    v6[5] = 0;
    v6[6] = 7;
    v3 = (*(int (__thiscall **)(int, const char *, _DWORD *))(*(_DWORD *)v2 + 16))(a1: v2, a2: "_Images", a3: v6);
    v4 = *((_DWORD *)this + 8);
    v5 = v3;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 32))(a1: v4);
    *((_DWORD *)this + 8) = v5;
  }
}
