// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/heapmh/gmemoryheapmh.cpp
// Functions: 33
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\heapmh\gmemoryheapmh.h"

//------------------------------------------------------------------------------
// Address: 0x1006BD10
// Name: public: static class GMemoryHeap __near * GMemoryHeap::CreateRootHeapMH(struct GMemoryHeap::HeapDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
GMemoryHeap *__stdcall GMemoryHeap::CreateRootHeapMH(const void *desc)
{
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx
  GMemoryHeap *v3; // eax
  _DWORD v4[8]; // [esp+4h] [ebp-20h] BYREF

  if ( GHeapGlobalRootMH == nullptr )
    return nullptr;
  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  if ( GMemory::pGlobalHeap != nullptr )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
    return nullptr;
  }
  qmemcpy(v4, desc, sizeof(v4));
  v4[6] = 1;
  GHeapRootMH::CreateHeap(this: GHeapGlobalRootMH, name: (int)"Global");
  GMemory::pGlobalHeap = v3;
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  return GMemory::pGlobalHeap;
}

//------------------------------------------------------------------------------
// Address: 0x1006BD90
// Name: private: GMemoryHeapMH::GMemoryHeapMH(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *__thiscall GMemoryHeapMH::GMemoryHeapMH(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this)
{
  GMemoryHeap::GMemoryHeap((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(OcclusionQueryObjectHandle_t__ *),CFuncMemPolicyNone> *)this);
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  this->m_Memory.m_pMemory = (CShaderSystem::ShaderDLLInfo_t *)&GMemoryHeapMH::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006BDE0
// Name: public: virtual unsigned int GMemoryHeapMH::GetFootprint(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::GetFootprint(GMemoryHeapMH *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v3 = *(_DWORD *)(*((_DWORD *)this + 26) + 152);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1006BE10
// Name: public: virtual unsigned int GMemoryHeapMH::GetUsedSpace(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::GetUsedSpace(GMemoryHeapMH *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v3 = *(_DWORD *)(*((_DWORD *)this + 26) + 156);
  LeaveCriticalSection(lpCriticalSection: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1006BE40
// Name: public: virtual void GMemoryHeapMH::SetLimitHandler(struct GMemoryHeap::LimitHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::SetLimitHandler(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        ShaderBlendFactor_t handler)
{
  _RTL_CRITICAL_SECTION *v3; // edi

  v3 = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  *(_DWORD *)(*((_DWORD *)this + 26) + 164) = handler;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006BE70
// Name: public: virtual void GMemoryHeapMH::SetLimit(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::SetLimit(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        unsigned int newLimit)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  unsigned int v4; // eax

  v3 = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v4 = newLimit;
  if ( newLimit < *((_DWORD *)this + 12) && newLimit < *(_DWORD *)(*((_DWORD *)this + 26) + 152) )
    v4 = *(_DWORD *)(*((_DWORD *)this + 26) + 152);
  *(_DWORD *)(*((_DWORD *)this + 26) + 160) = v4;
  *((_DWORD *)this + 12) = v4;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006BEC0
// Name: public: virtual void GMemoryHeapMH::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::AddRef(GMemoryHeapMH *this)
{
  _RTL_CRITICAL_SECTION *p_m_Elements; // edi

  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  ++*((_DWORD *)this + 4);
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
}

//------------------------------------------------------------------------------
// Address: 0x1006BEF0
// Name: private: virtual bool GMemoryHeapMH::dumpMemoryLeaks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::dumpMemoryLeaks(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this)
{
  GHeapDebugStorageMH::DumpMemoryLeaks();
}

//------------------------------------------------------------------------------
// Address: 0x1006BF00
// Name: private: void GMemoryHeapMH::freeLocked(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::freeLocked(GMemoryHeapMH *this, void *addr)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx

  v3 = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  GHeapAllocEngineMH::Free(this: *((GHeapAllocEngineMH **)this + 26), addr);
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006BF50
// Name: private: void __near * GMemoryHeapMH::allocMem(struct GHeapPageInfoMH __near *,void const __near *,unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::allocMem(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        struct GHeapPageInfoMH *parentInfo,
        ButtonCode_t thisPtr,
        UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *size,
        const struct GAllocDebugInfo *a5)
{
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v6; // edi
  _BYTE v7[24]; // [esp+Ch] [ebp-18h] BYREF

  v6 = GHeapAllocEngineMH::Alloc(result: size);
  if ( v6 != nullptr
    && *((_BYTE *)this + 101) != 0
    && !GHeapDebugStorageMH::AddAlloc(
          this: *((GHeapDebugStorageMH **)this + 27),
          a2: parentInfo,
          a3: thisPtr,
          a4: (unsigned int)v6,
          a5: (unsigned int)size,
          a6: (struct GHeapPageInfoMH *)v7,
          a7: a5) )
  {
    GMemoryHeapMH::freeLocked((GMemoryHeapMH *)this, addr: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BFC0
// Name: private: void __near * GMemoryHeapMH::allocMem(struct GHeapPageInfoMH __near *,void const __near *,unsigned int,unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMemoryHeapMH::allocMem(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        CShaderSystem::ShaderDLLInfo_t *parentInfo,
        ButtonCode_t thisPtr,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *size,
        unsigned int align,
        const struct GAllocDebugInfo *a6)
{
  unsigned int v7; // eax
  void *v8; // edi
  _BYTE v10[24]; // [esp+Ch] [ebp-18h] BYREF

  LOBYTE(v7) = GHeapAllocEngineMH::Alloc(
                 this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                 + 26),
                 size);
  v8 = (void *)v7;
  if ( v7 != 0 && *((_BYTE *)this + 101) != 0 )
  {
    if ( GHeapDebugStorageMH::AddAlloc(
           this: *((GHeapDebugStorageMH **)this + 27),
           a2: (struct GHeapPageInfoMH *)parentInfo,
           a3: thisPtr,
           a4: v7,
           a5: (unsigned int)size,
           a6: (struct GHeapPageInfoMH *)v10,
           a7: a6) )
    {
      LOBYTE(v7) = (_BYTE)v8;
    }
    else
    {
      GMemoryHeapMH::freeLocked((GMemoryHeapMH *)this, addr: v8);
      LOBYTE(v7) = 0;
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1006C030
// Name: public: virtual void __near * GMemoryHeapMH::Alloc(unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *__thiscall GMemoryHeapMH::Alloc(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *size,
        const struct GAllocDebugInfo *a3)
{
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v6; // edi
  _BYTE v7[24]; // [esp+Ch] [ebp-18h] BYREF

  if ( *((_BYTE *)this + 100) != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
    v4 = GHeapAllocEngineMH::Alloc(result: size);
    if ( v4 != nullptr
      && *((_BYTE *)this + 101) != 0
      && !GHeapDebugStorageMH::AddAlloc(
            this: *((GHeapDebugStorageMH **)this + 27),
            a2: (unsigned int)v4,
            a3: (unsigned int)size,
            a4: (struct GHeapPageInfoMH *)v7,
            a5: a3) )
    {
      GMemoryHeapMH::freeLocked((GMemoryHeapMH *)this, addr: v4);
      v4 = nullptr;
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
    return v4;
  }
  else
  {
    v6 = GHeapAllocEngineMH::Alloc(result: size);
    if ( v6 != nullptr
      && *((_BYTE *)this + 101) != 0
      && !GHeapDebugStorageMH::AddAlloc(
            this: *((GHeapDebugStorageMH **)this + 27),
            a2: (unsigned int)v6,
            a3: (unsigned int)size,
            a4: (struct GHeapPageInfoMH *)v7,
            a5: a3) )
    {
      GMemoryHeapMH::freeLocked((GMemoryHeapMH *)this, addr: v6);
      return nullptr;
    }
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C0F0
// Name: public: virtual void __near * GMemoryHeapMH::Alloc(unsigned int,unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GMemoryHeapMH::Alloc(
        GMemoryHeapMH *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *size,
        unsigned int a3,
        const struct GAllocDebugInfo *a4)
{
  unsigned int v5; // eax
  void *v6; // edi
  unsigned int v8; // eax
  void *v9; // edi
  _BYTE v10[24]; // [esp+Ch] [ebp-18h] BYREF

  if ( *((_BYTE *)this + 100) != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
    LOBYTE(v5) = GHeapAllocEngineMH::Alloc(
                   this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                   + 26),
                   size);
    v6 = (void *)v5;
    if ( v5 != 0
      && *((_BYTE *)this + 101) != 0
      && !GHeapDebugStorageMH::AddAlloc(
            this: *((GHeapDebugStorageMH **)this + 27),
            a2: v5,
            a3: (unsigned int)size,
            a4: (struct GHeapPageInfoMH *)v10,
            a5: a4) )
    {
      GMemoryHeapMH::freeLocked(this, addr: v6);
      v6 = nullptr;
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
    return v6;
  }
  else
  {
    LOBYTE(v8) = GHeapAllocEngineMH::Alloc(
                   this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                   + 26),
                   size);
    v9 = (void *)v8;
    if ( v8 != 0
      && *((_BYTE *)this + 101) != 0
      && !GHeapDebugStorageMH::AddAlloc(
            this: *((GHeapDebugStorageMH **)this + 27),
            a2: v8,
            a3: (unsigned int)size,
            a4: (struct GHeapPageInfoMH *)v10,
            a5: a4) )
    {
      GMemoryHeapMH::freeLocked(this, addr: v9);
      return nullptr;
    }
    return v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C1B0
// Name: private: void __near * GMemoryHeapMH::reallocMem(struct GHeapPageMH __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::reallocMem(GMemoryHeapMH *this, struct GHeapPageMH *page, void *a3, unsigned int a4)
{
  int v5; // eax
  int v6; // esi
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx
  int v8; // eax
  _BYTE v10[20]; // [esp+24h] [ebp-28h] BYREF
  HBITMAP__ v11; // [esp+38h] [ebp-14h]
  unsigned __int16 prenderer[2]; // [esp+3Ch] [ebp-10h] BYREF
  int v13; // [esp+40h] [ebp-Ch]
  int v14; // [esp+44h] [ebp-8h]
  int v15; // [esp+48h] [ebp-4h]

  GHeapAllocEngineMH::GetPageInfoWithSize(this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                                                + 26));
  *(_DWORD *)prenderer = 0;
  v13 = -1;
  v14 = 0;
  v15 = 0;
  if ( *((_BYTE *)this + 101) != 0 )
  {
    GHeapDebugStorageMH::UnlinkAlloc(
      this: *((GHeapDebugStorageMH **)this + 27),
      a2: (unsigned int)a3,
      a3: (struct GHeapPageInfoMH *)v10,
      a4: (struct GHeapDebugStorageMH::DebugDataPtr *)prenderer);
    CMatNullRenderContext::OverrideColorWriteEnable(
      this: *((CUtlDict<ITextureInternal *,unsigned short> **)this + 27),
      (unsigned __int16)prenderer,
      ptext: v11);
  }
  LOBYTE(v5) = GHeapAllocEngineMH::ReallocInPage(
                 this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                 + 26),
                 (unsigned __int16)page);
  v6 = v5;
  if ( v5 != 0
    || (p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements,
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements),
        LOBYTE(v8) = GHeapAllocEngineMH::ReallocGeneral(
                       this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                       + 26),
                       (unsigned __int16)page),
        v6 = v8,
        LeaveCriticalSection(lpCriticalSection: p_m_Elements),
        v6 != 0) )
  {
    if ( *((_BYTE *)this + 101) != 0 && v6 != 0 )
      GHeapDebugStorageMH::RelinkAlloc();
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1006C290
// Name: private: void __near * GMemoryHeapMH::reallocMem(struct GHeapNodeMH __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::reallocMem(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        void *oldPtr,
        unsigned int newSize)
{
  _BYTE v5[20]; // [esp+24h] [ebp-28h] BYREF
  HBITMAP__ v6; // [esp+38h] [ebp-14h]
  _SYSTEM_POWER_STATE debugData; // [esp+3Ch] [ebp-10h] BYREF
  int v8; // [esp+40h] [ebp-Ch]
  int v9; // [esp+44h] [ebp-8h]
  int v10; // [esp+48h] [ebp-4h]

  GHeapAllocEngineMH::GetPageInfoWithSize(this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                                                + 26));
  debugData = PowerSystemUnspecified;
  v8 = -1;
  v9 = 0;
  v10 = 0;
  if ( *((_BYTE *)this + 101) != 0 )
  {
    GHeapDebugStorageMH::UnlinkAlloc(
      this: *((GHeapDebugStorageMH **)this + 27),
      a2: (unsigned int)oldPtr,
      a3: (struct GHeapPageInfoMH *)v5,
      a4: (struct GHeapDebugStorageMH::DebugDataPtr *)&debugData);
    CMatNullRenderContext::OverrideColorWriteEnable(
      this: *((CUtlDict<ITextureInternal *,unsigned short> **)this + 27),
      prenderer: (unsigned __int16)&debugData,
      ptext: v6);
  }
  if ( GHeapAllocEngineMH::ReallocInNode(this: *((CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)this
                                               + 26)) != nullptr
    && *((_BYTE *)this + 101) != 0 )
  {
    GHeapDebugStorageMH::RelinkAlloc();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C330
// Name: public: virtual void __near * GMemoryHeapMH::AllocSysDirect(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::AllocSysDirect(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        unsigned int size)
{
  _RTL_CRITICAL_SECTION *p_m_Elements; // esi
  int v3; // edi

  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  v3 = (*(int (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), unsigned int, int))(*(_DWORD *)GHeapGlobalRootMH->m_LessFunc.m_LessFunc + 12))(
         a1: GHeapGlobalRootMH->m_LessFunc.m_LessFunc,
         a2: size,
         a3: 4);
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1006C370
// Name: public: virtual void GMemoryHeapMH::FreeSysDirect(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::FreeSysDirect(GMemoryHeapMH *this, void *a2, unsigned int a3)
{
  _RTL_CRITICAL_SECTION *p_m_Elements; // esi

  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  (*(void (__thiscall **)(bool (__cdecl *)(const char *const *, const char *const *), void *, unsigned int, int))(*(_DWORD *)GHeapGlobalRootMH->m_LessFunc.m_LessFunc + 16))(
    a1: GHeapGlobalRootMH->m_LessFunc.m_LessFunc,
    a2,
    a3,
    a4: 4);
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
}

//------------------------------------------------------------------------------
// Address: 0x1006C3B0
// Name: public: virtual void GMemoryHeapMH::GetRootStats(struct GMemoryHeap::RootStats __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::GetRootStats(GMemoryHeapMH *this, struct GMemoryHeap::RootStats *a2)
{
  unsigned int v2; // eax

  a2->UserDebugFootprint = 0;
  a2->UserDebugUsedSpace = 0;
  GMemory::pGlobalHeap->getUserDebugStats(this: GMemory::pGlobalHeap, a2);
  a2->SysMemFootprint = a2->UserDebugFootprint + GMemory::pGlobalHeap->GetTotalFootprint(this: GMemory::pGlobalHeap);
  v2 = a2->UserDebugFootprint + GMemory::pGlobalHeap->GetTotalUsedSpace(this: GMemory::pGlobalHeap);
  a2->PageMapFootprint = 0;
  a2->PageMapUsedSpace = 0;
  a2->BookkeepingFootprint = 0;
  a2->BookkeepingUsedSpace = 0;
  a2->DebugInfoFootprint = 0;
  a2->DebugInfoUsedSpace = 0;
  a2->SysMemUsedSpace = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006C410
// Name: protected: virtual bool GSysAlloc::initHeapEngine(void const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GSysAlloc::initHeapEngine(GSysAlloc *this, ButtonCode_t heapDesc)
{
  if ( GHeapGlobalRootMH == nullptr )
    GHeapRootMH::GHeapRootMH(
      this: &GHeapRootMemMH,
      sysAlloc: (const CUtlMap<char const *,IShader *,unsigned short>::CKeyLess *)this);
  return GMemoryHeap::CreateRootHeapMH(desc: (const void *)heapDesc) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006C440
// Name: public: virtual class GMemoryHeap __near * GMemoryHeapMH::CreateHeap(char const __near *,struct GMemoryHeap::HeapDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
const CShaderSystem::ShaderDLLInfo_t *__thiscall GMemoryHeapMH::CreateHeap(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        int name,
        int desc)
{
  _RTL_CRITICAL_SECTION *p_m_Elements; // ebx
  int v5; // eax
  int v6; // esi

  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  GHeapRootMH::CreateHeap(this: GHeapGlobalRootMH, name);
  v6 = v5;
  if ( v5 != 0 )
    ++this->m_pElements;
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  if ( v6 != 0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
    *(_DWORD *)(v6 + 4) = *((_DWORD *)this + 17);
    *(_DWORD *)(v6 + 8) = (char *)this + 64;
    *(_DWORD *)(*((_DWORD *)this + 17) + 8) = v6;
    *((_DWORD *)this + 17) = v6;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  }
  return (const CShaderSystem::ShaderDLLInfo_t *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1006C4B0
// Name: public: virtual unsigned int GMemoryHeapMH::GetTotalFootprint(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::GetTotalFootprint(GMemoryHeapMH *this)
{
  int v2; // ebx
  _DWORD *v3; // edi
  char *v4; // esi
  int v5; // eax
  int v6; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v2 = 0;
  if ( (*((_DWORD *)this + 7) & 0x1000) == 0 )
    v2 = *(_DWORD *)(*((_DWORD *)this + 26) + 152);
  v3 = *((_DWORD **)this + 18);
  v4 = (char *)this + 68;
  while ( 1 )
  {
    v5 = v4 != nullptr ? (int)(v4 - 4) : 0;
    if ( v3 == (_DWORD *)v5 )
      break;
    v6 = (*(int (__thiscall **)(_DWORD *))(*v3 + 84))(a1: v3);
    v3 = (_DWORD *)v3[2];
    v2 += v6;
  }
  LeaveCriticalSection(lpCriticalSection);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006C520
// Name: public: virtual unsigned int GMemoryHeapMH::GetTotalUsedSpace(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GMemoryHeapMH::GetTotalUsedSpace(GMemoryHeapMH *this)
{
  int v2; // ebx
  _DWORD *v3; // edi
  char *v4; // esi
  int v5; // eax
  int v6; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v2 = 0;
  if ( (*((_DWORD *)this + 7) & 0x1000) == 0 )
    v2 = *(_DWORD *)(*((_DWORD *)this + 26) + 156);
  v3 = *((_DWORD **)this + 18);
  v4 = (char *)this + 68;
  while ( 1 )
  {
    v5 = v4 != nullptr ? (int)(v4 - 4) : 0;
    if ( v3 == (_DWORD *)v5 )
      break;
    v6 = (*(int (__thiscall **)(_DWORD *))(*v3 + 92))(a1: v3);
    v3 = (_DWORD *)v3[2];
    v2 += v6;
  }
  LeaveCriticalSection(lpCriticalSection);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006C590
// Name: public: virtual void GMemoryHeapMH::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::Release(GMemoryHeapMH *this)
{
  int v2; // edi
  _RTL_CRITICAL_SECTION *v3; // ebx
  _RTL_CRITICAL_SECTION *p_m_Elements; // edi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 15);
  if ( v2 != 0 )
  {
    v3 = (_RTL_CRITICAL_SECTION *)(v2 + 76);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v2 + 76));
    lpCriticalSection = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    if ( (*((_DWORD *)this + 4))-- == 1 )
    {
      (*(void (__thiscall **)(GMemoryHeapMH *))(*(_DWORD *)this + 128))(a1: this);
      *(_DWORD *)(*((_DWORD *)this + 1) + 8) = *((_DWORD *)this + 2);
      *(_DWORD *)(*((_DWORD *)this + 2) + 4) = *((_DWORD *)this + 1);
      GHeapRootMH::DestroyHeap(this: (GHeapRootMH *)GHeapGlobalRootMH, a2: (struct GMemoryHeapMH *)this);
    }
    else
    {
      v2 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    LeaveCriticalSection(lpCriticalSection: v3);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 32))(a1: v2);
  }
  else
  {
    p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    --*((_DWORD *)this + 4);
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C640
// Name: private: virtual void GMemoryHeapMH::destroyItself(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::destroyItself(GMemoryHeapMH *this)
{
  char *i; // ecx
  char *v3; // eax
  char *v4; // esi

  for ( i = *((char **)this + 18); ; i = v4 )
  {
    v3 = this == (GMemoryHeapMH *)-68 ? nullptr : (char *)this + 64;
    if ( i == v3 )
      break;
    v4 = *((char **)i + 2);
    (*(void (**)(void))(*(_DWORD *)i + 116))();
  }
  GHeapRootMH::DestroyHeap(this: (GHeapRootMH *)GHeapGlobalRootMH, a2: (struct GMemoryHeapMH *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1006C680
// Name: public: virtual bool GMemoryHeapMH::GetStats(class GStatBag __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GMemoryHeapMH::GetStats(
        GMemoryHeapMH *this,
        CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *UsedSpace)
{
  CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // esi
  char *v4; // ebx
  CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // ecx
  char *v6; // eax
  int (__thiscall *v7)(char *); // edx
  int v8; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-Ch]
  CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // [esp+10h] [ebp-8h]
  CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v12; // [esp+14h] [ebp-4h] BYREF

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  v3 = UsedSpace;
  v11 = *(CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(*((_DWORD *)this + 26) + 152);
  v12 = v11;
  GStatBag::Add(
    this: UsedSpace,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x12,
    a3: (int)&v12);
  UsedSpace = *(CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(*((_DWORD *)this + 26) + 156);
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x15,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x1A,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x1C,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x17,
    a3: (int)&UsedSpace);
  UsedSpace = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GHeapDebugStorageMH::GetUsedSpace(this: *((GHeapDebugStorageMH **)this + 27));
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x18,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x19,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x1B,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x16,
    a3: (int)&UsedSpace);
  UsedSpace = nullptr;
  v4 = *((char **)this + 18);
  v5 = nullptr;
  while ( 1 )
  {
    v6 = this == (GMemoryHeapMH *)-68 ? nullptr : (char *)this + 64;
    if ( v4 == v6 )
      break;
    if ( (*((_DWORD *)v4 + 7) & 0x1000) == 0 )
    {
      v7 = *(int (__thiscall **)(char *))(*(_DWORD *)v4 + 84);
      v12 = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((char *)&v5->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable + 1);
      v8 = v7(a1: v4);
      UsedSpace = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((char *)UsedSpace + v8);
      v5 = v12;
    }
    v4 = *((char **)v4 + 2);
  }
  if ( v5 != nullptr )
  {
    v12 = v5;
    GStatBag::Add(
      this: v3,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x14,
      a3: (int)&v12);
    v12 = UsedSpace;
    GStatBag::Add(
      this: v3,
      statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x13,
      a3: (int)&v12);
  }
  UsedSpace = (CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((char *)UsedSpace + (_DWORD)v11);
  GStatBag::Add(
    this: v3,
    statId: (const CMemberFunctor0<IShaderAPI *,void (__thiscall IShaderAPI::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)0x11,
    a3: (int)&UsedSpace);
  GHeapDebugStorageMH::GetStats();
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006C7F0
// Name: private: virtual void GMemoryHeapMH::getUserDebugStats(struct GMemoryHeap::RootStats __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::getUserDebugStats(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *stats)
{
  _DWORD *v3; // edi
  char *v4; // esi
  int v5; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)((char *)this + 76);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 76));
  if ( (*((_DWORD *)this + 7) & 0x1000) != 0 )
  {
    stats[1].m_Size += *(_DWORD *)(*((_DWORD *)this + 26) + 152);
    stats[1].m_pElements = (CShaderSystem::ShaderDLLInfo_t *)((char *)stats[1].m_pElements
                                                            + *(_DWORD *)(*((_DWORD *)this + 26) + 156));
  }
  v3 = *((_DWORD **)this + 18);
  v4 = (char *)this + 68;
  while ( 1 )
  {
    v5 = v4 != nullptr ? (int)(v4 - 4) : 0;
    if ( v3 == (_DWORD *)v5 )
      break;
    (*(void (__thiscall **)(_DWORD *, CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *))(*v3 + 136))(
      a1: v3,
      a2: stats);
    v3 = (_DWORD *)v3[2];
  }
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1006C870
// Name: protected: virtual void GSysAlloc::shutdownHeapEngine(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1006C970
// Name: public: virtual void __near * GMemoryHeapMH::AllocAutoHeap(void const __near *,unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::AllocAutoHeap(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *size,
        const struct GAllocDebugInfo *a4)
{
  int v4; // eax
  struct GHeapPageMH *v5; // ebx
  int v6; // esi
  unsigned int v7; // esi
  int parentInfo[6]; // [esp+Ch] [ebp-20h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+24h] [ebp-8h]
  ApplicationInstantCountersInfo_t *locker2; // [esp+28h] [ebp-4h]

  LOBYTE(v4) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: (unsigned __int16)node);
  v5 = (struct GHeapPageMH *)v4;
  if ( v4 != 0 )
  {
    v6 = *(_DWORD *)(v4 + 8);
    if ( *(_BYTE *)(v6 + 100) != 0 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 76));
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v6 + 104),
        a2: v5,
        a3: (struct GHeapPageInfoMH *)parentInfo);
      GMemoryHeapMH::allocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v6,
        (struct GHeapPageInfoMH *)parentInfo,
        thisPtr: (ButtonCode_t)node,
        size,
        a5: a4);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 76));
    }
    else
    {
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v6 + 104),
        a2: (struct GHeapPageMH *)v4,
        a3: (struct GHeapPageInfoMH *)parentInfo);
      GMemoryHeapMH::allocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v6,
        (struct GHeapPageInfoMH *)parentInfo,
        thisPtr: (ButtonCode_t)node,
        size,
        a5: a4);
    }
  }
  else
  {
    locker2 = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    v7 = *(_DWORD *)(GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: node) + 12) & 0xFFFFFFFC;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2);
    if ( *(_BYTE *)(v7 + 100) != 0 )
    {
      lpCriticalSection = (LPCRITICAL_SECTION)(v7 + 76);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v7 + 76));
      locker2 = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GHeapAllocEngineMH::GetPageInfo(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v7 + 104));
      GMemoryHeapMH::allocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v7,
        (struct GHeapPageInfoMH *)parentInfo,
        thisPtr: (ButtonCode_t)node,
        size,
        a5: a4);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2);
    }
    else
    {
      lpCriticalSection = (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GHeapAllocEngineMH::GetPageInfo(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v7 + 104));
      GMemoryHeapMH::allocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v7,
        (struct GHeapPageInfoMH *)parentInfo,
        thisPtr: (ButtonCode_t)node,
        size,
        a5: a4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CAF0
// Name: public: virtual void __near * GMemoryHeapMH::AllocAutoHeap(void const __near *,unsigned int,unsigned int,struct GAllocDebugInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMemoryHeapMH::AllocAutoHeap(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        ApplicationInstantCountersInfo_t *thisPtr,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *size,
        unsigned int align,
        const struct GAllocDebugInfo *a5)
{
  int v6; // eax
  struct GHeapPageMH *v7; // ebx
  int v8; // esi
  bool v9; // si
  unsigned int v11; // esi
  bool v12; // si
  _BYTE v13[24]; // [esp+Ch] [ebp-1Ch] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+24h] [ebp-4h]
  ApplicationInstantCountersInfo_t *locker2; // [esp+30h] [ebp+8h]
  ApplicationInstantCountersInfo_t *locker2a; // [esp+30h] [ebp+8h]
  ApplicationInstantCountersInfo_t *locker2b; // [esp+30h] [ebp+8h]
  ApplicationInstantCountersInfo_t *locker2c; // [esp+30h] [ebp+8h]

  LOBYTE(v6) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: (unsigned __int16)thisPtr);
  v7 = (struct GHeapPageMH *)v6;
  if ( v6 != 0 )
  {
    v8 = *(_DWORD *)(v6 + 8);
    if ( *(_BYTE *)(v8 + 100) != 0 )
    {
      locker2 = (ApplicationInstantCountersInfo_t *)(v8 + 76);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v8 + 76));
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v8 + 104),
        a2: v7,
        a3: (struct GHeapPageInfoMH *)v13);
      v9 = GMemoryHeapMH::allocMem(
             this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v8,
             parentInfo: (CShaderSystem::ShaderDLLInfo_t *)v13,
             (ButtonCode_t)thisPtr,
             size,
             align,
             a6: a5);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2);
      return v9;
    }
    else
    {
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v8 + 104),
        a2: (struct GHeapPageMH *)v6,
        a3: (struct GHeapPageInfoMH *)v13);
      return GMemoryHeapMH::allocMem(
               this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v8,
               parentInfo: (CShaderSystem::ShaderDLLInfo_t *)v13,
               (ButtonCode_t)thisPtr,
               size,
               align,
               a6: a5);
    }
  }
  else
  {
    locker2a = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    v11 = *(_DWORD *)(GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: thisPtr) + 12) & 0xFFFFFFFC;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2a);
    if ( *(_BYTE *)(v11 + 100) != 0 )
    {
      lpCriticalSection = (LPCRITICAL_SECTION)(v11 + 76);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v11 + 76));
      locker2b = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v11 + 104),
        a2: nullptr,
        a3: (struct GHeapPageInfoMH *)v13);
      v12 = GMemoryHeapMH::allocMem(
              this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v11,
              parentInfo: (CShaderSystem::ShaderDLLInfo_t *)v13,
              (ButtonCode_t)thisPtr,
              size,
              align,
              a6: a5);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2b);
      LeaveCriticalSection(lpCriticalSection);
    }
    else
    {
      locker2c = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GHeapAllocEngineMH::GetPageInfo(
        this: *(GHeapAllocEngineMH **)(v11 + 104),
        a2: nullptr,
        a3: (struct GHeapPageInfoMH *)v13);
      v12 = GMemoryHeapMH::allocMem(
              this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v11,
              parentInfo: (CShaderSystem::ShaderDLLInfo_t *)v13,
              (ButtonCode_t)thisPtr,
              size,
              align,
              a6: a5);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2c);
    }
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CC80
// Name: public: virtual void GMemoryHeapMH::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMemoryHeapMH::Free(GMemoryHeapMH *this, void *addr)
{
  int v3; // eax
  const UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v4; // ebx
  unsigned int v5; // esi
  int GrEq; // ebx
  _BYTE v7[24]; // [esp+4h] [ebp-18h] BYREF
  _RTL_CRITICAL_SECTION *addra; // [esp+24h] [ebp+8h]
  _RTL_CRITICAL_SECTION *addrb; // [esp+24h] [ebp+8h]
  _RTL_CRITICAL_SECTION *addrc; // [esp+24h] [ebp+8h]

  if ( addr != nullptr )
  {
    LOBYTE(v3) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, (unsigned __int16)addr);
    v4 = (const UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *)v3;
    if ( v3 != 0 )
    {
      v5 = *(_DWORD *)(v3 + 8);
      if ( *(_BYTE *)(v5 + 100) != 0 )
      {
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 76));
        GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104));
        GHeapDebugStorageMH::RemoveAlloc(
          this: *(GHeapDebugStorageMH **)(v5 + 108),
          a2: (unsigned int)addr,
          a3: (struct GHeapPageInfoMH *)v7);
        GHeapAllocEngineMH::Free(
          this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104),
          page: v4,
          ptr: (int)addr);
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 76));
      }
      else
      {
        GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104));
        GHeapDebugStorageMH::RemoveAlloc(
          this: *(GHeapDebugStorageMH **)(v5 + 108),
          a2: (unsigned int)addr,
          a3: (struct GHeapPageInfoMH *)v7);
        GHeapAllocEngineMH::Free(
          this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104),
          page: v4,
          ptr: (int)addr);
      }
    }
    else
    {
      addra = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GrEq = GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: addr);
      v5 = *(_DWORD *)(GrEq + 12) & 0xFFFFFFFC;
      LeaveCriticalSection(lpCriticalSection: addra);
      if ( *(_BYTE *)(v5 + 100) != 0 )
      {
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 76));
        addrb = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
        GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104));
        GHeapDebugStorageMH::RemoveAlloc(
          this: *(GHeapDebugStorageMH **)(v5 + 108),
          a2: (unsigned int)addr,
          a3: (struct GHeapPageInfoMH *)v7);
        GHeapAllocEngineMH::Free(this: *(GHeapAllocEngineMH **)(v5 + 104), a2: (struct GHeapNodeMH *)GrEq, a3: addr);
        LeaveCriticalSection(lpCriticalSection: addrb);
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 76));
      }
      else
      {
        addrc = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
        EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
        GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(v5 + 104));
        GHeapDebugStorageMH::RemoveAlloc(
          this: *(GHeapDebugStorageMH **)(v5 + 108),
          a2: (unsigned int)addr,
          a3: (struct GHeapPageInfoMH *)v7);
        GHeapAllocEngineMH::Free(this: *(GHeapAllocEngineMH **)(v5 + 104), a2: (struct GHeapNodeMH *)GrEq, a3: addr);
        LeaveCriticalSection(lpCriticalSection: addrc);
      }
    }
    if ( addr == *(void **)(v5 + 24) )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 32))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CE00
// Name: public: virtual void __near * GMemoryHeapMH::Realloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GMemoryHeapMH::Realloc(
        int (__cdecl *node)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *),
        unsigned int newSize)
{
  int v3; // eax
  struct GHeapPageMH *v4; // ebx
  int v5; // esi
  int v6; // esi
  unsigned int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]
  ApplicationInstantCountersInfo_t *locker2; // [esp+10h] [ebp-4h]
  ApplicationInstantCountersInfo_t *locker2a; // [esp+10h] [ebp-4h]
  int (__cdecl *nodeb)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *); // [esp+1Ch] [ebp+8h]
  int (__cdecl *nodea)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *); // [esp+1Ch] [ebp+8h]

  LOBYTE(v3) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: (unsigned __int16)node);
  v4 = (struct GHeapPageMH *)v3;
  if ( v3 != 0 )
  {
    v5 = *(_DWORD *)(v3 + 8);
    if ( *(_BYTE *)(v5 + 100) != 0 )
    {
      nodeb = (int (__cdecl *)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *))(v5 + 76);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 76));
      v6 = GMemoryHeapMH::reallocMem(this: (GMemoryHeapMH *)v5, page: v4, a3: node, a4: newSize);
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)nodeb);
      return v6;
    }
    else
    {
      return GMemoryHeapMH::reallocMem(this: (GMemoryHeapMH *)v5, page: (struct GHeapPageMH *)v3, a3: node, a4: newSize);
    }
  }
  else
  {
    locker2 = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    nodea = (int (__cdecl *)(const CShaderSystem::ShaderDLLInfo_t *, const CShaderSystem::ShaderDLLInfo_t *))GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: node);
    v8 = *((_DWORD *)nodea + 3) & 0xFFFFFFFC;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2);
    if ( *(_BYTE *)(v8 + 100) != 0 )
    {
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)(v8 + 76);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v8 + 76));
      locker2a = (ApplicationInstantCountersInfo_t *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GMemoryHeapMH::reallocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v8,
        node: nodea,
        oldPtr: node,
        newSize);
      v10 = v9;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)locker2a);
    }
    else
    {
      lpCriticalSection = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
      GMemoryHeapMH::reallocMem(
        this: (CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *)v8,
        node: nodea,
        oldPtr: node,
        newSize);
      v10 = v11;
    }
    LeaveCriticalSection(lpCriticalSection);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CF30
// Name: public: virtual class GMemoryHeap __near * GMemoryHeapMH::GetAllocHeap(void const __near *)
// Source: json
//------------------------------------------------------------------------------
struct GMemoryHeap *__thiscall GMemoryHeapMH::GetAllocHeap(GMemoryHeapMH *this, const void *addr)
{
  int v2; // eax
  _RTL_CRITICAL_SECTION *p_m_Elements; // edi
  unsigned int v5; // esi

  LOBYTE(v2) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, (unsigned __int16)addr);
  if ( v2 != 0 )
    return *(struct GMemoryHeap **)(v2 + 8);
  p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
  v5 = *(_DWORD *)(GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: addr) + 12) & 0xFFFFFFFC;
  LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  return (struct GMemoryHeap *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1006CFA0
// Name: public: virtual unsigned int GMemoryHeapMH::GetUsableSize(void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GMemoryHeapMH::GetUsableSize@<eax>(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this@<ecx>,
        ButtonCode_t ptr,
        const CShaderSystem::ShaderDLLInfo_t *pageInfo)
{
  int v3; // eax
  _RTL_CRITICAL_SECTION *p_m_Elements; // esi
  int GrEq; // [esp-10h] [ebp-2Ch]
  int v7; // [esp+18h] [ebp-4h]

  LOBYTE(v3) = GHeapRootMH::ResolveAddress(this: GHeapGlobalRootMH, addr: ptr);
  if ( v3 != 0 )
  {
    GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)(*(_DWORD *)(v3 + 8) + 104));
  }
  else
  {
    p_m_Elements = (_RTL_CRITICAL_SECTION *)&GHeapGlobalRootMH->m_Elements;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GHeapGlobalRootMH->m_Elements);
    GrEq = GRadixTree<GHeapNodeMH,GHeapTreeNodeAccessor>::FindGrEq(a1: ptr);
    GHeapAllocEngineMH::GetPageInfoWithSize(this: *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> **)((*(_DWORD *)(GrEq + 12) & 0xFFFFFFFC) + 104));
    LeaveCriticalSection(lpCriticalSection: p_m_Elements);
  }
  return v7;
}
