// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfontmanager.cpp
// Functions: 28
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfontmanager.h"

//------------------------------------------------------------------------------
// Address: 0x100AE120
// Name: public: GFxFontHandle::GFxFontHandle(class GFxFontManager __near *,class GFxFontResource __near *,char const __near *,unsigned int,class GFxMovieDef __near *)
// Source: json
//------------------------------------------------------------------------------
GFxFontHandle *__thiscall GFxFontHandle::GFxFontHandle(
        GFxFontHandle *this,
        const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pmanager,
        IShaderDevice *a3,
        char *a4,
        unsigned int overridenFontFlags,
        IShaderDevice *a6)
{
  char *v7; // eax

  *((_DWORD *)this + 2) = overridenFontFlags;
  *(_DWORD *)this = 1;
  *((_DWORD *)this + 1) = pmanager;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 12));
  *((float *)this + 4) = 1.0;
  if ( a3 != nullptr )
    GRefCountImpl::AddRef(this: a3);
  *((_DWORD *)this + 7) = a3;
  if ( a6 != nullptr )
    GRefCountImpl::AddRef(this: a6);
  *((_DWORD *)this + 8) = a6;
  *((float *)this + 6) = 0.0;
  *((float *)this + 5) = 0.0;
  if ( a4 != nullptr )
  {
    v7 = (char *)(*((int (__thiscall **)(IShaderDevice_vtbl *))a3[3].ReleaseResources + 15))(a1: a3[3].__vftable);
    if ( GString::CompareNoCase(a1: v7, a2: a4) != 0 )
      GString::operator=(
        this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 12),
        a2: (unsigned __int8 *)a4);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10119150
// Name: public: class GFxFontHandle __near * GFxFontManager::CreateFontHandle(char const __near *,bool,bool,bool,bool,struct GFxFontManager::FontSearchPathInfo __near *)
// Source: json
//------------------------------------------------------------------------------
const CDefaultClientRenderable *__thiscall GFxFontManager::CreateFontHandle(
        CDefaultClientRenderable *this,
        const CDefaultClientRenderable *result,
        int bold,
        int italic,
        int device,
        int allowListOfFonts,
        IScaleformUIFunctionHandlerDefinitionTable searchInfo)
{
  return (const CDefaultClientRenderable *)GFxFontManager::CreateFontHandle(this);
}

//------------------------------------------------------------------------------
// Address: 0x10135590
// Name: FontFlagsToString
// Source: json
//------------------------------------------------------------------------------
GMemoryHeap *__usercall FontFlagsToString@<eax>(int a1@<eax>)
{
  GMemoryHeap *result; // eax
  bool v2; // zf

  if ( a1 != 0 )
  {
    if ( (a1 & 0x10) != 0 )
    {
      if ( (a1 & 3) == 3 )
        return (GMemoryHeap *)GFxRectangle_DefaultParams.HeapLock.cs.LockSemaphore;
      if ( (a1 & 2) != 0 )
        return (GMemoryHeap *)GFxRectangle_DefaultParams.HeapLock.cs.RecursionCount;
      if ( (a1 & 1) != 0 )
        return (GMemoryHeap *)GFxRectangle_DefaultParams.HeapLock.cs.OwningThread;
      return (GMemoryHeap *)GFxRectangle_DefaultParams.HeapLock.cs.LockCount;
    }
    if ( (a1 & 3) == 3 )
      return (GMemoryHeap *)GFxRectangle_DefaultParams.HeapLock.cs.DebugInfo;
    if ( (a1 & 2) != 0 )
      return GFxRectangle_DefaultParams.ChildHeaps.Root.pPrev;
    v2 = (a1 & 1) == 0;
    result = GFxRectangle_DefaultParams.ChildHeaps.Root.pNext;
    if ( !v2 )
      return result;
  }
  return (GMemoryHeap *)GFxRectangle_DefaultParams.Info.pName;
}

//------------------------------------------------------------------------------
// Address: 0x101355F0
// Name: public: bool GFxFontManager::NodePtr::operator==(struct GFxFontManager::NodePtr const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxFontManager::NodePtr::operator==(int *this, _DWORD *a2)
{
  _DWORD *v2; // eax
  int v4; // ecx
  _DWORD *v6; // ecx
  char *v7; // edi
  _DWORD *v8; // eax
  char *v9; // eax

  v2 = (_DWORD *)*a2;
  v4 = *this;
  if ( v4 == *a2 )
    return true;
  if ( (((*(_DWORD *)(v4 + 8) | *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 28) + 12) + 20))
       ^ (v2[2] | *(_DWORD *)(*(_DWORD *)(v2[7] + 12) + 20)))
      & 0x313) != 0 )
    return false;
  v6 = (_DWORD *)(v2[3] & 0xFFFFFFFC);
  v7 = (*v6 & 0x7FFFFFFF) != 0
     ? (char *)(v6 + 2)
     : (char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v2[7] + 12) + 60))(a1: *(_DWORD *)(v2[7] + 12));
  v8 = (_DWORD *)(*(_DWORD *)(*this + 12) & 0xFFFFFFFC);
  v9 = (*v8 & 0x7FFFFFFF) != 0
     ? (char *)(v8 + 2)
     : (char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(*this + 28) + 12) + 60))(a1: *(_DWORD *)(*(_DWORD *)(*this + 28) + 12));
  return GString::CompareNoCase(a1: v9, a2: v7) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135690
// Name: public: bool GFxFontManager::NodePtr::operator==(struct GFxFontManager::FontKey const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxFontManager::NodePtr::operator==(bf_write *this, int key)
{
  unsigned __int8 *m_pData; // ecx
  _DWORD *v3; // eax
  char *v4; // eax
  BOOL result; // eax

  m_pData = this->m_pData;
  result = false;
  if ( ((*((_DWORD *)m_pData + 2) | *(_DWORD *)(*(_DWORD *)(*((_DWORD *)m_pData + 7) + 12) + 20))
      & (*(_DWORD *)(key + 4) & 0x10 | ((*(_DWORD *)(key + 4) & 0x300) != 0 ? 0x300 : 0) | 3)) == (*(_DWORD *)(key + 4)
                                                                                                 & 0x313) )
  {
    v3 = (_DWORD *)(*((_DWORD *)m_pData + 3) & 0xFFFFFFFC);
    v4 = (*v3 & 0x7FFFFFFF) != 0
       ? (char *)(v3 + 2)
       : (char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)m_pData + 7) + 12) + 60))(a1: *(_DWORD *)(*((_DWORD *)m_pData + 7) + 12));
    if ( GString::CompareNoCase(a1: v4, a2: *(char **)key) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10135710
// Name: public: unsigned int GFxFontManager::NodePtrHashOp::operator()(class GFxFontHandle const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontManager::NodePtrHashOp::operator()(SoundInfo_t *this, int a2)
{
  _DWORD *v2; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v3; // eax

  v2 = (_DWORD *)(*(_DWORD *)(a2 + 12) & 0xFFFFFFFC);
  if ( (*v2 & 0x7FFFFFFF) != 0 )
    v3 = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v2 + 2);
  else
    v3 = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 28) + 12) + 60))(a1: *(_DWORD *)(*(_DWORD *)(a2 + 28) + 12));
  GString::BernsteinHashFunctionCIS(
    result: v3,
    size: strlen((const char *)v3),
    seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
}

//------------------------------------------------------------------------------
// Address: 0x10135780
// Name: public: virtual class GFxState __near * GFxFontManagerStates::GetStateAddRef(enum GFxState::StateType)const
// Source: json
//------------------------------------------------------------------------------
struct GFxState *__thiscall GFxFontManagerStates::GetStateAddRef(
        GFxFontManagerStates *this,
        enum GFxState::StateType a2)
{
  IShaderDevice *v3; // ecx
  IShaderDevice *v5; // ecx
  IShaderDevice *v6; // ecx
  IShaderDevice *v7; // ecx

  switch ( a2 )
  {
    case State_FontLib:
      v3 = *((IShaderDevice **)this + 1);
      if ( v3 != nullptr )
        GRefCountImpl::AddRef(this: v3);
      return *((struct GFxState **)this + 1);
    case State_FontMap:
      v5 = *((IShaderDevice **)this + 2);
      if ( v5 != nullptr )
        GRefCountImpl::AddRef(this: v5);
      return *((struct GFxState **)this + 2);
    case State_FontProvider:
      v6 = *((IShaderDevice **)this + 3);
      if ( v6 != nullptr )
        GRefCountImpl::AddRef(this: v6);
      return *((struct GFxState **)this + 3);
    case State_Translator:
      v7 = *((IShaderDevice **)this + 4);
      if ( v7 != nullptr )
        GRefCountImpl::AddRef(this: v7);
      return *((struct GFxState **)this + 4);
    default:
      return (*(struct GFxState *(__thiscall **)(_DWORD, enum GFxState::StateType))(**((_DWORD **)this + 5) + 12))(
               a1: *((_DWORD *)this + 5),
               a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135800
// Name: public: unsigned char GFxFontManagerStates::CheckStateChange(class GFxFontLib __near *,class GFxFontMap __near *,class GFxFontProvider __near *,class GFxTranslator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFontManagerStates::CheckStateChange(
        IShaderAPI **this,
        CMemberFuncProxy2<CMaterialVar *,void (__thiscall CMaterialVar::*)(float,int),float,int,CFuncMemPolicyNone> *result,
        IShaderDevice *pfontLib_4,
        IShaderDevice *pfontLib_8,
        IShaderDevice *pfontLib_12)
{
  char v6; // bl
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx
  IShaderAPI *v9; // ecx
  IShaderAPI *v10; // ecx

  v6 = 0;
  if ( *(this + 3) != (IShaderAPI *)result )
  {
    if ( result != nullptr )
      GRefCountImpl::AddRef(this: (IShaderDevice *)result);
    v7 = *(this + 3);
    if ( v7 != nullptr )
      GRefCountImpl::Release(this: v7);
    *(this + 3) = (IShaderAPI *)result;
  }
  if ( *(this + 4) != (IShaderAPI *)pfontLib_4 )
  {
    v6 = 1;
    if ( pfontLib_4 != nullptr )
      GRefCountImpl::AddRef(this: pfontLib_4);
    v8 = *(this + 4);
    if ( v8 != nullptr )
      GRefCountImpl::Release(this: v8);
    *(this + 4) = (IShaderAPI *)pfontLib_4;
  }
  if ( *(this + 5) != (IShaderAPI *)pfontLib_8 )
  {
    v6 |= 2u;
    if ( pfontLib_8 != nullptr )
      GRefCountImpl::AddRef(this: pfontLib_8);
    v9 = *(this + 5);
    if ( v9 != nullptr )
      GRefCountImpl::Release(this: v9);
    *(this + 5) = (IShaderAPI *)pfontLib_8;
  }
  if ( *(this + 6) != (IShaderAPI *)pfontLib_12 )
  {
    v6 |= 3u;
    if ( pfontLib_12 != nullptr )
      GRefCountImpl::AddRef(this: pfontLib_12);
    v10 = *(this + 6);
    if ( v10 != nullptr )
      GRefCountImpl::Release(this: v10);
    *(this + 6) = (IShaderAPI *)pfontLib_12;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101358B0
// Name: AddSearchInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall AddSearchInfo(GString::DataDesc *a1@<ecx>, int a2@<edi>, char *putf8str)
{
  int i; // esi
  void *v4; // esi
  GString v5; // [esp+0h] [ebp-4h] BYREF

  v5.pData = a1;
  if ( a2 != 0 )
  {
    GString::GString(this: &v5, src: (int)"   ");
    for ( i = 0; i < *(_DWORD *)a2; ++i )
      GStringBuffer::AppendString(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)(a2 + 4),
        putf8str: (char *)((v5.HeapTypeBits & 0xFFFFFFFC) + 8),
        utf8StrSz: *(_DWORD *)(v5.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    GStringBuffer::AppendString(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)(a2 + 4),
      putf8str,
      utf8StrSz: -1);
    GStringBuffer::AppendString(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)(a2 + 4),
      putf8str: "\n",
      utf8StrSz: -1);
    v4 = (void *)(v5.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v5.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135940
// Name: AddSearchInfo_0
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSearchInfo_0@<al>(int a1@<eax>, char *putf8str, char *a3, char *a4)
{
  int v4; // edi
  GString::DataDesc *v5; // ecx
  char *m_pfnProxied; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v8; // [esp+4h] [ebp-18h] BYREF

  v4 = a1;
  if ( a1 != 0 )
  {
    GStringBuffer::GStringBuffer(
      this: &v8,
      result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
    GStringBuffer::AppendString(this: &v8, putf8str, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v8, putf8str: a3, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v8, putf8str: a4, utf8StrSz: -1);
    m_pfnProxied = (char *)v8.m_pfnProxied;
    if ( LODWORD(v8.m_pfnProxied) == 0 )
      m_pfnProxied = (char *)&pMem;
    AddSearchInfo(a1: v5, a2: v4, putf8str: m_pfnProxied);
    LOBYTE(a1) = GStringBuffer::~GStringBuffer(this: &v8);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101359B0
// Name: AddSearchInfo_1
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSearchInfo_1@<al>(int a1@<eax>, char *putf8str, char *a3, char *a4, int a5, char *a6)
{
  int v6; // edi
  char *v7; // eax
  GString::DataDesc *v8; // ecx
  char *m_pfnProxied; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v11; // [esp+4h] [ebp-18h] BYREF

  v6 = a1;
  if ( a1 != 0 )
  {
    GStringBuffer::GStringBuffer(
      this: &v11,
      result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
    GStringBuffer::AppendString(this: &v11, putf8str, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v11, putf8str: a3, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v11, putf8str: a4, utf8StrSz: -1);
    v7 = (char *)FontFlagsToString(a1: a5);
    GStringBuffer::AppendString(this: &v11, putf8str: v7, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v11, putf8str: a6, utf8StrSz: -1);
    m_pfnProxied = (char *)v11.m_pfnProxied;
    if ( LODWORD(v11.m_pfnProxied) == 0 )
      m_pfnProxied = (char *)&pMem;
    AddSearchInfo(a1: v8, a2: v6, putf8str: m_pfnProxied);
    LOBYTE(a1) = GStringBuffer::~GStringBuffer(this: &v11);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10135A40
// Name: AddSearchInfo_2
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSearchInfo_2@<al>(
        int a1@<eax>,
        char *putf8str,
        char *a3,
        char *a4,
        int a5,
        char *a6,
        char *a7,
        char *a8,
        int a9)
{
  int v9; // edi
  char *v10; // eax
  char *v11; // eax
  GString::DataDesc *v12; // ecx
  char *m_pfnProxied; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v15; // [esp+4h] [ebp-18h] BYREF

  v9 = a1;
  if ( a1 != 0 )
  {
    GStringBuffer::GStringBuffer(
      this: &v15,
      result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
    GStringBuffer::AppendString(this: &v15, putf8str, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v15, putf8str: a3, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v15, putf8str: a4, utf8StrSz: -1);
    v10 = (char *)FontFlagsToString(a1: a5);
    GStringBuffer::AppendString(this: &v15, putf8str: v10, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v15, putf8str: a6, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v15, putf8str: a7, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v15, putf8str: a8, utf8StrSz: -1);
    v11 = (char *)FontFlagsToString(a1: a9);
    GStringBuffer::AppendString(this: &v15, putf8str: v11, utf8StrSz: -1);
    m_pfnProxied = (char *)v15.m_pfnProxied;
    if ( LODWORD(v15.m_pfnProxied) == 0 )
      m_pfnProxied = (char *)&pMem;
    AddSearchInfo(a1: v12, a2: v9, putf8str: m_pfnProxied);
    LOBYTE(a1) = GStringBuffer::~GStringBuffer(this: &v15);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10135B00
// Name: AddSearchInfo_3
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSearchInfo_3@<al>(int a1@<eax>, char *putf8str, char *a3, char *a4, char *a5, char *a6, int a7)
{
  int v7; // edi
  char *v8; // eax
  GString::DataDesc *v9; // ecx
  char *m_pfnProxied; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v12; // [esp+4h] [ebp-18h] BYREF

  v7 = a1;
  if ( a1 != 0 )
  {
    GStringBuffer::GStringBuffer(
      this: &v12,
      result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
    GStringBuffer::AppendString(this: &v12, putf8str, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v12, putf8str: a3, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v12, putf8str: a4, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v12, putf8str: a5, utf8StrSz: -1);
    GStringBuffer::AppendString(this: &v12, putf8str: a6, utf8StrSz: -1);
    v8 = (char *)FontFlagsToString(a1: a7);
    GStringBuffer::AppendString(this: &v12, putf8str: v8, utf8StrSz: -1);
    m_pfnProxied = (char *)v12.m_pfnProxied;
    if ( LODWORD(v12.m_pfnProxied) == 0 )
      m_pfnProxied = (char *)&pMem;
    AddSearchInfo(a1: v9, a2: v7, putf8str: m_pfnProxied);
    LOBYTE(a1) = GStringBuffer::~GStringBuffer(this: &v12);
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10135BA0
// Name: public: class GFxFontHandle __near * GFxFontManager::GetEmptyFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxFontManager::GetEmptyFont(CDefaultClientRenderable *this)
{
  ++**((_DWORD **)this + 6);
  return *((_DWORD *)this + 6);
}

//------------------------------------------------------------------------------
// Address: 0x10135D50
// Name: public: GFxFontHandle::GFxFontHandle(class GFxFontHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxFontHandle *__thiscall GFxFontHandle::GFxFontHandle(GFxFontHandle *this, const struct GFxFontHandle *a2)
{
  IShaderDevice *v3; // ecx
  IShaderDevice *v4; // ecx

  *(_DWORD *)this = 1;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  GStringLH::CopyConstructHelper(
    this: (CCountedStringPoolBase<unsigned int> *)((char *)this + 12),
    result: (const CFixedBitVecBase<128> *)((char *)a2 + 12));
  *((float *)this + 4) = *((float *)a2 + 4);
  *((float *)this + 5) = *((float *)a2 + 5);
  *((float *)this + 6) = *((float *)a2 + 6);
  v3 = *((IShaderDevice **)a2 + 7);
  if ( v3 != nullptr )
    GRefCountImpl::AddRef(this: v3);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 7);
  v4 = *((IShaderDevice **)a2 + 8);
  if ( v4 != nullptr )
    GRefCountImpl::AddRef(this: v4);
  *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10135FD0
// Name: protected: void GFxFontManager::RemoveFontHandle(class GFxFontHandle __near *)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10135FF0
// Name: public: void GFxFontManager::CleanCache(void)
// Source: json
//------------------------------------------------------------------------------
const CDefaultClientRenderable *__thiscall GFxFontManager::CleanCache(_DWORD *this)
{
  _DWORD *v1; // edi
  int v2; // ecx
  _DWORD *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  int v7; // ecx
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  const CDefaultClientRenderable *v10; // eax
  int v11; // ecx
  char *v12; // edx

  v1 = this + 2;
  v2 = *(this + 2);
  if ( v2 != 0 )
  {
    v5 = *(_DWORD *)(v2 + 4);
    v4 = 0;
    v6 = (_DWORD *)(v2 + 8);
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 3;
    }
    while ( v4 <= v5 );
    v3 = v1;
  }
  else
  {
    v3 = nullptr;
    v4 = 0;
  }
  while ( v3 != nullptr )
  {
    v7 = *v3;
    if ( *v3 == 0 || (signed int)v4 > *(_DWORD *)(v7 + 4) )
      break;
    *(_DWORD *)(*(_DWORD *)(v7 + 12 * v4 + 16) + 4) = 0;
    v8 = *(_DWORD *)(*v3 + 4);
    if ( (int)v4 <= (int)v8 && ++v4 <= v8 )
    {
      v9 = (_DWORD *)(*v3 + 12 * v4 + 8);
      do
      {
        if ( *v9 != -2 )
          break;
        ++v4;
        v9 += 3;
      }
      while ( v4 <= v8 );
    }
  }
  v10 = (const CDefaultClientRenderable *)*v1;
  if ( *v1 != 0 )
  {
    v11 = 0;
    v12 = (char *)&v10->GetIClientUnknown + 1;
    do
    {
      if ( *(_DWORD *)(v11 + *v1 + 8) != -2 )
        *(_DWORD *)(v11 + *v1 + 8) = -2;
      v11 += 12;
      --v12;
    }
    while ( v12 != nullptr );
    v10 = (const CDefaultClientRenderable *)((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                                              a1: GMemory::pGlobalHeap,
                                              a2: *v1);
    *v1 = 0;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10136250
// Name: unsigned int G_Format<char const __near *,char const __near *>(class GMsgFormat::Sink const __near &,char const __near *,char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Format<char const *,char const *>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        CMatQueuedRenderContext::CCallQueueExternal *v,
        CMatQueuedRenderContext::CCallQueueExternal *a4)
{
  int m_nGrowSize; // esi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v6[27]; // [esp+Ch] [ebp-304h] BYREF

  GMsgFormat::GMsgFormat(this: (GMsgFormat *)v6, a2: a1);
  GMsgFormat::Parse(this: v6, result: a2);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v6, v);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v6, v: a4);
  GMsgFormat::FinishFormatD(this: v6);
  m_nGrowSize = v6[0].m_Elements.m_nGrowSize;
  GMsgFormat::~GMsgFormat(this: v6);
  return m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x10136480
// Name: AddSearchInfo_4
// Source: json
//------------------------------------------------------------------------------
void __usercall AddSearchInfo_4(
        GPtr<GWaitable::HandlerArray> *a1@<edx>,
        int a2@<ecx>,
        int a3@<esi>,
        unsigned int a4,
        char a5)
{
  GWaitable::HandlerArray *pObject; // eax
  GString::DataDesc *v8; // ecx
  GMemoryHeap *v9; // eax
  GString::DataDesc *v10; // ecx
  GString::DataDesc *v11; // ecx
  GString::DataDesc *v12; // ecx
  GWaitable::HandlerArray *v13; // eax
  int *v14; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v15; // eax
  CImagePacker *v16; // eax
  int *v17; // eax
  GMemoryHeap *v18; // eax
  bool v19; // zf
  GString::DataDesc *v20; // ecx
  char *v21; // [esp-Ch] [ebp-448h]
  char *v22; // [esp-Ch] [ebp-448h]
  int *v23; // [esp-Ch] [ebp-448h]
  CMatQueuedRenderContext::CCallQueueExternal *p_OwningThread; // [esp-4h] [ebp-440h]
  int v25; // [esp+0h] [ebp-43Ch]
  CUtlMemory<CImagePacker,int> v26; // [esp+8h] [ebp-434h] BYREF
  int v27; // [esp+14h] [ebp-428h]
  GWaitable::HandlerArray v28; // [esp+18h] [ebp-424h] BYREF

  v28.Handlers.Data.Policy.Capacity = a4;
  if ( a2 != 0 )
  {
    pObject = a1->pObject;
    if ( a1->pObject == (GWaitable::HandlerArray *)1 )
    {
      v28.HandlersLock.cs.OwningThread = FontFlagsToString(a1: a3);
      p_OwningThread = (CMatQueuedRenderContext::CCallQueueExternal *)&v28.HandlersLock.cs.OwningThread;
      v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
      v28.HandlersLock.cs.RecursionCount = 1024;
      v21 = "Movie resource: \"{0}\" {1} found.";
LABEL_4:
      v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
      G_Format<char const *,char const *>(
        a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
        a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v21,
        v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
        a4: p_OwningThread);
      AddSearchInfo(a1: v8, a2, putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
      return;
    }
    if ( pObject == (GWaitable::HandlerArray *)3 )
    {
      v9 = FontFlagsToString(a1: a3);
      v22 = "Movie resource: \"{0}\" {1} found, requires faux";
LABEL_7:
      v28.HandlersLock.cs.OwningThread = v9;
      v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
      v28.HandlersLock.cs.RecursionCount = 1024;
      v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
      G_Format<char const *,char const *>(
        a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
        a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v22,
        v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
        a4: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.HandlersLock.cs.OwningThread);
      AddSearchInfo(
        a1: (GString::DataDesc *)&v28.HandlersLock.cs.LockSemaphore,
        a2,
        putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
      return;
    }
    if ( pObject == (GWaitable::HandlerArray *)2 )
    {
      v28.HandlersLock.cs.OwningThread = FontFlagsToString(a1: a3);
      v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
      v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
      v28.HandlersLock.cs.RecursionCount = 1024;
      G_Format<char const *,char const *>(
        a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
        a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"Movie resource: \"{0}\" {1} ref found, requires FontLib/Map/Provider.",
        v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
        a4: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.HandlersLock.cs.OwningThread);
      AddSearchInfo(a1: v10, a2, putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
      return;
    }
    v28.HandlersLock.cs.OwningThread = FontFlagsToString(a1: a3);
    v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
    v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
    v28.HandlersLock.cs.RecursionCount = 1024;
    G_Format<char const *,char const *>(
      a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
      a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"Movie resource: \"{0}\" {1} not found.",
      v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
      a4: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.HandlersLock.cs.OwningThread);
    AddSearchInfo(a1: v11, a2, putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
    if ( a1->pObject == (GWaitable::HandlerArray *)4 )
    {
LABEL_26:
      v28.Handlers.Data.Size = (unsigned int)FontFlagsToString(a1: a3);
      v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
      v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
      v28.HandlersLock.cs.RecursionCount = 1024;
      G_Format<char const *,char const *,GString>(
        a1: &v28.HandlersLock,
        a2: "Imports       : \"{0}\" {1} found in \"{2}\".",
        a3: &v28.Handlers.Data.Policy,
        a4: &v28.Handlers.Data.Size,
        a5: &a1[2]);
      AddSearchInfo(
        a1: (GString::DataDesc *)&v28.HandlersLock.cs.LockSemaphore,
        a2,
        putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
      return;
    }
    if ( a1->pObject == (GWaitable::HandlerArray *)5 )
    {
      if ( a5 != 0 )
      {
        v9 = FontFlagsToString(a1: a3);
        v22 = "Imports       : \"{0}\" {1} import delegates to font library.";
        goto LABEL_7;
      }
      goto LABEL_26;
    }
    v28.HandlersLock.cs.OwningThread = FontFlagsToString(a1: a3);
    v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
    v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
    v28.HandlersLock.cs.RecursionCount = 1024;
    G_Format<char const *,char const *>(
      a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
      a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"Imports       : \"{0}\" {1} not found.",
      v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
      a4: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.HandlersLock.cs.OwningThread);
    AddSearchInfo(a1: v12, a2, putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
    v13 = a1[1].pObject;
    if ( v13 != nullptr && v13->RefCount.Value != 0 )
    {
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v28.HandlersLock.cs.OwningThread);
      GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::Begin(
        this: a1 + 1,
        a2: &v28);
      v27 = 0;
      v26.m_nGrowSize = 0;
      if ( GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::ConstIterator::operator!=(
             this: (int *)&v28.RefCount.Value,
             a2: &v26.m_nGrowSize) )
      {
        v26.m_nGrowSize = 0;
        v27 = 0;
        do
        {
          GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::Begin(
            this: a1 + 1,
            a2: (GWaitable::HandlerArray *)&v28.HandlersLock.cs.LockCount);
          if ( GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::ConstIterator::operator!=(
                 this: (int *)&v28.RefCount.Value,
                 a2: v14) )
          {
            GString::AppendString(
              this: (CUtlMemory<CImagePacker,int> *)&v28.HandlersLock.cs.OwningThread,
              putf8str: (CImagePacker *)", ",
              utf8StrSz: -1);
          }
          v23 = (int *)(*(_DWORD *)v28.RefCount.Value + 12 * (int)v28.Handlers.Data.Data + 16);
          v15 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)GString::GString(
                                                                                            this: (GString *)&v28.Handlers.Data.Size,
                                                                                            src: (int)"\"");
          v16 = (CImagePacker *)GString::operator+(
                                  this: v15,
                                  src: (CCountedStringPoolBase<unsigned int> *)&v26.m_nAllocationCount,
                                  a3: v23);
          v17 = (int *)GString::operator+(result: v16, a2: &v26, putf8str: (CImagePacker *)"\"");
          GString::operator+=(
            this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&v28.HandlersLock.cs.OwningThread,
            src: v17,
            srcSize: v25);
          GString::~GString(this: (GString *)&v26);
          GString::~GString(this: (GString *)&v26.m_nAllocationCount);
          GString::~GString(this: (GString *)&v28.Handlers.Data.Size);
          GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::ConstIterator::operator++(this: (unsigned int *)&v28);
        }
        while ( GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::ConstIterator::operator!=(
                  this: (int *)&v28.RefCount.Value,
                  a2: &v26.m_nGrowSize) );
      }
      v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
      v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
      v28.HandlersLock.cs.RecursionCount = 1024;
      G_Format<GString>(
        a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
        a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"              : {0}.",
        a3: (struct GString *)&v28.HandlersLock.cs.OwningThread);
      AddSearchInfo(
        a1: (GString::DataDesc *)&v28.HandlersLock.cs.LockSemaphore,
        a2,
        putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
      GString::~GString(this: (GString *)&v28.HandlersLock.cs.OwningThread);
    }
    v18 = FontFlagsToString(a1: a3);
    v19 = a1->pObject == (GWaitable::HandlerArray *)6;
    v28.Handlers.Data.Size = (unsigned int)v18;
    v28.HandlersLock.cs.DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)2;
    v28.HandlersLock.cs.RecursionCount = 1024;
    if ( !v19 )
    {
      p_OwningThread = (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Size;
      v21 = "Exported      : \"{0}\" {1} not found.";
      goto LABEL_4;
    }
    v28.HandlersLock.cs.LockCount = (int)&v28.HandlersLock.cs.LockSemaphore;
    G_Format<char const *,char const *>(
      a1: (struct GMsgFormat::Sink *)&v28.HandlersLock,
      a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"Exported      : \"{0}\" {1} found.",
      v: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Policy,
      a4: (CMatQueuedRenderContext::CCallQueueExternal *)&v28.Handlers.Data.Size);
    AddSearchInfo(a1: v20, a2, putf8str: (char *)&v28.HandlersLock.cs.LockSemaphore);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136960
// Name: public: GFxMovieDefImpl::SearchInfo::~SearchInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::SearchInfo::~SearchInfo(GFxTranslator *this, unsigned int a2)
{
  volatile LONG *v2; // esi

  v2 = (volatile LONG *)(this->SType & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  JUMPOUT(0x100D5E60);
}

//------------------------------------------------------------------------------
// Address: 0x101369A0
// Name: private: void GFxFontManager::commonInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontManager::commonInit(
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **this)
{
  CMorph *v2; // eax
  IShaderDevice *v3; // edi
  IShaderAPI *v4; // eax
  GFxFontResource *v5; // eax
  char *v6; // esi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v7; // esi
  int v9; // [esp+Ch] [ebp-8h] BYREF
  IShaderAPI *v10; // [esp+10h] [ebp-4h]

  v9 = 261;
  v2 = (CMorph *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 64, a4: &v9);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    GFxFontData::GFxFontData(this: v2);
    v10 = v4;
  }
  else
  {
    v10 = nullptr;
  }
  v9 = 2;
  v5 = (GFxFontResource *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 44, a4: &v9);
  if ( v5 != nullptr )
    v3 = (IShaderDevice *)GFxFontResource::GFxFontResource(this: v5, a2: (IShaderDevice *)v10, pbinding: nullptr);
  v9 = 326;
  v6 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 36, a4: &v9);
  if ( v6 != nullptr )
  {
    *(_DWORD *)v6 = 1;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
    GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v6 + 12));
    *((float *)v6 + 4) = 1.0;
    if ( v3 != nullptr )
      GRefCountImpl::AddRef(this: v3);
    *((_DWORD *)v6 + 7) = v3;
    *((_DWORD *)v6 + 8) = 0;
    *((float *)v6 + 6) = 0.0;
    *((float *)v6 + 5) = 0.0;
    v9 = (int)v6;
  }
  else
  {
    v9 = 0;
  }
  v7 = *(this + 6);
  if ( v7 != nullptr && LODWORD(v7->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v7);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
  *(this + 6) = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v9;
  if ( v3 != nullptr )
    GFxResource::Release(this: v3);
  if ( v10 != nullptr )
    GRefCountImpl::Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10136AB0
// Name: public: virtual GFxFontManager::~GFxFontManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontManager::~GFxFontManager(int this)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v2; // esi
  bool v3; // zf
  volatile LONG *v4; // esi
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v5; // esi

  *(_DWORD *)this = &GFxFontManager::`vftable';
  v2 = *(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)(this + 48);
  if ( v2 != nullptr )
  {
    v3 = LODWORD(v2->m_pfnProxied)-- == 1;
    if ( v3 )
    {
      GFxFontHandle::~GFxFontHandle(this: v2);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v2);
    }
  }
  v4 = (volatile LONG *)(*(_DWORD *)(this + 28) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  v5 = *(CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)(this + 24);
  if ( v5 != nullptr )
  {
    v3 = LODWORD(v5->m_pfnProxied)-- == 1;
    if ( v3 )
    {
      GFxFontHandle::~GFxFontHandle(this: v5);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    }
  }
  GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this: (CInternalFileSystemPassThru<IBaseFileSystem> *)(this + 8));
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10136B30
// Name: protected: class GFxFontHandle __near * GFxFontManager::FindOrCreateHandle(char const __near *,unsigned int,class GFxFontResource __near * __near *,struct GFxFontManager::FontSearchPathInfo __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxFontHandle *__thiscall GFxFontManager::FindOrCreateHandle(
        GFxFontManager *this,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result,
        unsigned int matchFontFlags,
        struct GFxFontResource **a4,
        IScaleformUIFunctionHandlerDefinitionTable searchInfo)
{
  _DWORD *v6; // eax
  int v7; // ecx
  unsigned int v8; // edx
  GFxFontMap *v9; // eax
  char *v10; // esi
  GFxFontHandle *v11; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  char *v14; // eax
  int v15; // ebx
  void *v16; // esi
  int v18; // eax
  int v19; // eax
  _DWORD **v20; // eax
  struct GFxFontResource *v21; // esi
  _DWORD *v22; // ecx
  int v23; // eax
  int v24; // esi
  IShaderDevice *v25; // ecx
  bool v26; // zf
  float v27; // edx
  char *v28; // eax
  GString::DataDesc *v29; // ecx
  int v30; // eax
  int v31; // ecx
  IScaleformUIFunctionHandlerDefinitionTable_vtbl *v32; // esi
  int v33; // eax
  GFxFontHandle *v34; // eax
  int v35; // eax
  GFxFontHandle *v36; // eax
  _DWORD **v37; // eax
  GFxFontHandle *v38; // eax
  IVModelInfo_vtbl *v39; // edx
  char *v40; // eax
  GFxFontHandle *v41; // eax
  unsigned int v42; // eax
  char *v43; // ecx
  int v44; // eax
  int v45; // eax
  IScaleformUIFunctionHandlerDefinitionTable_vtbl *v46; // edi
  char *v47; // eax
  char *v48; // esi
  IShaderDevice *v49; // edi
  char *v50; // eax
  IShaderDevice *v51; // ecx
  int v52; // eax
  int v53; // eax
  GFxFontHandle *v54; // eax
  unsigned int v55; // eax
  char *v56; // ecx
  _DWORD *v57; // esi
  _DWORD *v58; // esi
  _DWORD *v59; // esi
  _DWORD *v60; // esi
  int v61; // eax
  char *v62; // [esp-7Ch] [ebp-FCh]
  char *v63; // [esp-78h] [ebp-F8h]
  int v64; // [esp-74h] [ebp-F4h]
  const char *v65; // [esp-6Ch] [ebp-ECh]
  char *v66; // [esp-40h] [ebp-C0h]
  GFxFontManager *v67; // [esp-24h] [ebp-A4h]
  GFxFontManager *v68; // [esp-18h] [ebp-98h]
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v69; // [esp-Ch] [ebp-8Ch]
  unsigned int v70; // [esp+0h] [ebp-80h]
  GFxTranslator v71; // [esp+Ch] [ebp-74h] BYREF
  IVModelInfo_vtbl *v72; // [esp+1Ch] [ebp-64h]
  int v73[2]; // [esp+20h] [ebp-60h] BYREF
  int v74[2]; // [esp+28h] [ebp-58h] BYREF
  int key; // [esp+30h] [ebp-50h] BYREF
  unsigned int v76; // [esp+34h] [ebp-4Ch]
  GFxFontLib::FontResult v77; // [esp+38h] [ebp-48h] BYREF
  GFxFontLib::FontResult v78; // [esp+40h] [ebp-40h] BYREF
  GFxFontMap *v79; // [esp+48h] [ebp-38h]
  GFxTranslator *v80; // [esp+4Ch] [ebp-34h]
  int indentDif; // [esp+50h] [ebp-30h]
  unsigned int lf; // [esp+54h] [ebp-2Ch]
  IVModelInfo pfont; // [esp+58h] [ebp-28h] BYREF
  int v84; // [esp+5Ch] [ebp-24h] BYREF
  int v85; // [esp+60h] [ebp-20h]
  float offy; // [esp+64h] [ebp-1Ch]
  float offx; // [esp+68h] [ebp-18h]
  float scaleFactor; // [esp+6Ch] [ebp-14h]
  void *pname; // [esp+70h] [ebp-10h]
  unsigned int lookupFlags; // [esp+74h] [ebp-Ch]
  int v91; // [esp+78h] [ebp-8h] BYREF
  bool secondLoop; // [esp+7Fh] [ebp-1h]

  v76 = matchFontFlags;
  v6 = *((_DWORD **)this + 5);
  v7 = v6[3];
  v8 = v6[5];
  v9 = (GFxFontMap *)v6[4];
  v10 = (char *)result;
  v11 = nullptr;
  v85 = v7;
  key = (int)result;
  v91 = 0;
  lf = v8;
  v79 = v9;
  indentDif = 0;
  v71.RefCount = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v71.SType);
  v12 = *((_DWORD *)this + 12);
  v80 = nullptr;
  secondLoop = false;
  if ( v12 != 0 )
  {
    v13 = (_DWORD *)(*(_DWORD *)(v12 + 12) & 0xFFFFFFFC);
    v14 = (*v13 & 0x7FFFFFFF) != 0
        ? (char *)(v13 + 2)
        : (char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(v12 + 28) + 12) + 60))(a1: *(_DWORD *)(*(_DWORD *)(v12 + 28) + 12));
    if ( GString::CompareNoCase(a1: v14, a2: v10) == 0 )
    {
      ++**((_DWORD **)this + 12);
      v15 = *((_DWORD *)this + 12);
      v16 = (void *)(v71.SType & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v71.SType & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
      GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::Clear(this: &v71.RefCount);
      return (struct GFxFontHandle *)v15;
    }
  }
  while ( 1 )
  {
    if ( searchInfo.__vftable != nullptr )
    {
      ++indentDif;
      ++searchInfo.GetTable;
      v80 = &v71;
    }
    else if ( *((_DWORD *)this + 2) != 0 )
    {
      v18 = GString::BernsteinHashFunctionCIS(
              result,
              size: strlen((const char *)result),
              seed: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)0x1505);
      v19 = GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::findIndexCore<GFxFontManager::FontKey>(
              this: (_DWORD *)this + 2,
              (int)&key,
              a3: *(_DWORD *)(*((_DWORD *)this + 2) + 4) & (v18 ^ matchFontFlags & 3));
      if ( v19 >= 0 )
      {
        v20 = (_DWORD **)(*((_DWORD *)this + 2) + 12 * v19 + 16);
        if ( v20 != nullptr )
        {
          ++**v20;
          v57 = *v20;
          GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: v70);
          return (struct GFxFontHandle *)v57;
        }
      }
    }
    if ( *((_DWORD *)this + 3) != 0 )
    {
      v69 = result;
      offy = COERCE_FLOAT((*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 3) + 112))(a1: *((_DWORD *)this + 3)));
    }
    else
    {
      offy = 0.0;
    }
    AddSearchInfo_4(
      a1: (GPtr<GWaitable::HandlerArray> *)&v71,
      a2: (int)searchInfo.__vftable,
      a3: matchFontFlags,
      a4: (unsigned int)result,
      a5: *(_DWORD *)(*((_DWORD *)this + 5) + 12) != 0);
    if ( offy != 0.0 )
    {
      v21 = (struct GFxFontResource *)LODWORD(offy);
      v22 = *(_DWORD **)(LODWORD(offy) + 12);
      if ( (v22[5] & 0x40) == 0 )
      {
        if ( (matchFontFlags & 3) != 0 && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v22 + 64))(a1: v22) == 0 )
        {
          if ( a4 != nullptr )
          {
            *a4 = v21;
            GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)v69);
            return nullptr;
          }
          goto LABEL_122;
        }
        pfont.__vftable = (IVModelInfo_vtbl *)326;
        v68 = this;
        v23 = ((int (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->AllocAutoHeap_2)(a1: GMemory::pGlobalHeap);
        v24 = v23;
        if ( v23 != 0 )
        {
          *(_DWORD *)(v23 + 4) = searchInfo.__vftable == nullptr ? this : nullptr;
          *(_DWORD *)v23 = 1;
          *(_DWORD *)(v23 + 8) = 0;
          GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v23 + 12));
          v25 = (IShaderDevice *)LODWORD(offy);
          *(float *)(v24 + 16) = 1.0;
          GRefCountImpl::AddRef(this: v25);
          v26 = result == nullptr;
          v27 = offy;
          *(float *)(v24 + 28) = offy;
          *(_DWORD *)(v24 + 32) = 0;
          *(float *)(v24 + 24) = 0.0;
          *(float *)(v24 + 20) = 0.0;
          if ( !v26 )
          {
            v28 = (char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v27) + 12) + 60))(a1: *(_DWORD *)(LODWORD(v27) + 12));
            if ( GString::CompareNoCase(a1: v28, a2: (char *)result) != 0 )
              GString::operator=(
                this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v24 + 12),
                a2: (unsigned __int8 *)result);
          }
          v11 = (GFxFontHandle *)v24;
        }
        else
        {
          v11 = nullptr;
        }
        v91 = (int)v11;
      }
    }
    v29 = (GString::DataDesc *)matchFontFlags;
    scaleFactor = 1.0;
    pname = result;
    offx = 0.0;
    lookupFlags = matchFontFlags;
    offy = 0.0;
    pfont.__vftable = nullptr;
    if ( v11 != nullptr )
    {
      v32 = searchInfo.__vftable;
      goto LABEL_69;
    }
    if ( v79 != nullptr
      && GFxFontMap::GetFontMapping(
           this: v79,
           a2: 0,
           pentry: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 28),
           a4: (GString)result) != 0 )
    {
      pname = (void *)((*((_DWORD *)this + 7) & 0xFFFFFFFC) + 8);
      v30 = *((_DWORD *)this + 11);
      lookupFlags = v30 == 16 ? matchFontFlags : matchFontFlags & 0xFFFFFFFC | v30 & 0xFFFFFFF3;
      scaleFactor = *((float *)this + 8);
      offx = *((float *)this + 9);
      offy = *((float *)this + 10);
      if ( (v30 & 0xC) != 0 )
        v31 = v30 >> 2;
      else
        LOBYTE(v31) = 0;
      v32 = searchInfo.__vftable;
      pfont.__vftable = (IVModelInfo_vtbl *)(v30 & 0x20 | v31 & 3);
      if ( searchInfo.__vftable != nullptr )
      {
        AddSearchInfo_3(
          a1: (int)searchInfo.__vftable,
          putf8str: "Applying GFxFontMap: \"",
          a3: (char *)result,
          a4: "\"  mapped to \"",
          a5: (char *)pname,
          a6: "\"",
          a7: lookupFlags);
      }
      else
      {
        v74[1] = lookupFlags;
        v74[0] = (int)pname;
        v33 = GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::Get<GFxFontManager::FontKey>(
                this: (_DWORD *)this + 2,
                key: (int)v74);
        v84 = v33;
        if ( v33 != 0 )
        {
          if ( scaleFactor == *(float *)(*(_DWORD *)v33 + 16) )
          {
            ++**(_DWORD **)v33;
            v58 = *(_DWORD **)v33;
            GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)v68);
            return (struct GFxFontHandle *)v58;
          }
          v91 = 326;
          v67 = this;
          v34 = (GFxFontHandle *)((int (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->AllocAutoHeap_2)(a1: GMemory::pGlobalHeap);
          if ( v34 != nullptr )
            v11 = GFxFontHandle::GFxFontHandle(
                    this: v34,
                    pmanager: (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
                    a3: *(IShaderDevice **)(*(_DWORD *)v84 + 28),
                    a4: (char *)result,
                    overridenFontFlags: matchFontFlags,
                    a6: *(IShaderDevice **)(*(_DWORD *)v84 + 32));
          else
            v11 = nullptr;
          v91 = (int)v11;
          *((float *)v11 + 4) = scaleFactor;
          *((float *)v11 + 5) = offx;
          *((float *)v11 + 6) = offy;
        }
        v73[0] = (int)result;
        v73[1] = lookupFlags;
        v35 = GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::Get<GFxFontManager::FontKey>(
                this: (_DWORD *)this + 2,
                key: (int)v73);
        v84 = v35;
        if ( v35 != 0 )
        {
          if ( scaleFactor == *(float *)(*(_DWORD *)v35 + 16) )
          {
            ++**(_DWORD **)v35;
            v59 = *(_DWORD **)v35;
            GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)v67);
            return (struct GFxFontHandle *)v59;
          }
          v91 = 326;
          v36 = (GFxFontHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                   this: GMemory::pGlobalHeap,
                                   a2: this,
                                   a3: 36,
                                   a4: &v91);
          if ( v36 != nullptr )
            v11 = GFxFontHandle::GFxFontHandle(
                    this: v36,
                    pmanager: (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
                    a3: *(IShaderDevice **)(*(_DWORD *)v84 + 28),
                    a4: (char *)result,
                    overridenFontFlags: matchFontFlags,
                    a6: *(IShaderDevice **)(*(_DWORD *)v84 + 32));
          else
            v11 = nullptr;
          v91 = (int)v11;
          *((float *)v11 + 4) = scaleFactor;
          *((float *)v11 + 5) = offx;
          *((float *)v11 + 6) = offy;
        }
        if ( v11 != nullptr )
          goto LABEL_69;
      }
    }
    else
    {
      v32 = searchInfo.__vftable;
    }
    v29 = nullptr;
    if ( v85 != 0 )
    {
      v78.pMovieDef = nullptr;
      v78.pFontResource = nullptr;
      v67 = *((GFxFontManager **)this + 3);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v85 + 4))(a1: v85) != 0 )
      {
        if ( pfont.__vftable != nullptr )
        {
          v71.WWMode = (unsigned int)result;
          v72 = pfont.__vftable;
          v37 = (_DWORD **)GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::Get<GFxFontManager::FontKey>(
                             this: (_DWORD *)this + 2,
                             key: (int)&v71.WWMode);
          if ( v37 != nullptr )
          {
            ++**v37;
            v60 = *v37;
            GFxFontLib::FontResult::~FontResult(this: &v78);
            GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)&v78);
            return (struct GFxFontHandle *)v60;
          }
          v84 = 326;
          v38 = (GFxFontHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                   this: GMemory::pGlobalHeap,
                                   a2: this,
                                   a3: 36,
                                   a4: &v84);
          if ( v38 != nullptr )
            v11 = GFxFontHandle::GFxFontHandle(
                    this: v38,
                    pmanager: v32 == nullptr
                  ? (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this
                  : nullptr,
                    a3: (IShaderDevice *)v78.pFontResource,
                    a4: (char *)result,
                    overridenFontFlags: (unsigned int)pfont.__vftable,
                    a6: (IShaderDevice *)v78.pMovieDef);
          else
            v11 = nullptr;
          v39 = pfont.__vftable;
          v40 = (char *)result;
          *((float *)v11 + 4) = scaleFactor;
          v91 = (int)v11;
          *((float *)v11 + 5) = offx;
          *((float *)v11 + 6) = offy;
          AddSearchInfo_1(
            a1: (int)v32,
            putf8str: "Searching GFxFontLib: \"",
            a3: v40,
            a4: "\" ",
            a5: (int)v39,
            a6: " found.");
        }
        else
        {
          pfont.__vftable = (IVModelInfo_vtbl *)326;
          v41 = (GFxFontHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                   this: GMemory::pGlobalHeap,
                                   a2: this,
                                   a3: 36,
                                   a4: &pfont);
          if ( v41 != nullptr )
            v11 = GFxFontHandle::GFxFontHandle(
                    this: v41,
                    pmanager: v32 == nullptr
                  ? (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this
                  : nullptr,
                    a3: (IShaderDevice *)v78.pFontResource,
                    a4: (char *)result,
                    overridenFontFlags: 0,
                    a6: (IShaderDevice *)v78.pMovieDef);
          else
            v11 = nullptr;
          v42 = lookupFlags;
          v43 = (char *)pname;
          *((float *)v11 + 4) = scaleFactor;
          *((float *)v11 + 5) = offx;
          *((float *)v11 + 6) = offy;
          v91 = (int)v11;
          AddSearchInfo_1(
            a1: (int)v32,
            putf8str: "Searching GFxFontLib: \"",
            a3: v43,
            a4: "\" ",
            a5: v42,
            a6: " found.");
        }
      }
      else
      {
        AddSearchInfo_1(
          a1: (int)v32,
          putf8str: "Searching GFxFontLib: \"",
          a3: (char *)pname,
          a4: "\" ",
          a5: lookupFlags,
          a6: v66);
      }
      GFxFontLib::FontResult::~FontResult(this: &v78);
    }
LABEL_69:
    if ( secondLoop || v32 == nullptr )
    {
      if ( v11 != nullptr )
        goto LABEL_88;
      goto LABEL_76;
    }
    if ( v11 == nullptr )
    {
      if ( v85 == 0 && v71.__vftable == (GFxTranslator_vtbl *)2 )
      {
        AddSearchInfo(a1: v29, a2: (int)v32, putf8str: "GFxFontLib not installed.");
        v11 = (GFxFontHandle *)v91;
      }
LABEL_76:
      if ( lf != 0 )
      {
        v44 = *((_DWORD *)this + 3);
        if ( v44 != 0 )
          v45 = *(_DWORD *)(*(_DWORD *)(v44 + 20) + 24);
        else
          v45 = *((_DWORD *)this + 4);
        pfont.__vftable = (IVModelInfo_vtbl *)GFxFontResource::CreateFontResource(
                                                (char *)pname,
                                                fontFlags: lookupFlags,
                                                pprovider: (unsigned int *)lf,
                                                a4: v45);
        if ( pfont.__vftable != nullptr )
        {
          v46 = searchInfo.__vftable;
          AddSearchInfo_1(
            a1: (int)searchInfo.__vftable,
            putf8str: "Searching GFxFontProvider: \"",
            a3: (char *)pname,
            a4: "\" ",
            a5: lookupFlags,
            a6: " found.");
          v84 = 326;
          v47 = (char *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 36, a4: &v84);
          v48 = v47;
          if ( v47 != nullptr )
          {
            *(_DWORD *)v47 = 1;
            *((_DWORD *)v47 + 1) = v46 == nullptr ? this : nullptr;
            *((_DWORD *)v47 + 2) = 0;
            GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(v47 + 12));
            v49 = (IShaderDevice *)pfont.__vftable;
            *((float *)v48 + 4) = 1.0;
            GRefCountImpl::AddRef(this: v49);
            v26 = result == nullptr;
            *((_DWORD *)v48 + 7) = v49;
            *((_DWORD *)v48 + 8) = 0;
            *((float *)v48 + 6) = 0.0;
            *((float *)v48 + 5) = 0.0;
            if ( !v26 )
            {
              v50 = (char *)(*((int (__thiscall **)(IShaderDevice_vtbl *))v49[3].ReleaseResources + 15))(a1: v49[3].__vftable);
              if ( GString::CompareNoCase(a1: v50, a2: (char *)result) != 0 )
                GString::operator=(
                  this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v48 + 12),
                  a2: (unsigned __int8 *)result);
            }
            v11 = (GFxFontHandle *)v48;
          }
          else
          {
            v11 = nullptr;
          }
          v51 = (IShaderDevice *)pfont.__vftable;
          *((float *)v11 + 4) = scaleFactor;
          v91 = (int)v11;
          *((float *)v11 + 5) = offx;
          *((float *)v11 + 6) = offy;
          GFxResource::Release(this: v51);
          v32 = searchInfo.__vftable;
        }
        else
        {
          AddSearchInfo_1(
            a1: (int)v32,
            putf8str: "Searching GFxFontProvider: \"",
            a3: (char *)pname,
            a4: "\" ",
            a5: lookupFlags,
            a6: " not found.");
        }
      }
LABEL_88:
      if ( secondLoop )
        goto LABEL_95;
    }
    if ( v32 != nullptr )
    {
      if ( v11 != nullptr )
        break;
      if ( lf == 0 && v71.__vftable == (GFxTranslator_vtbl *)2 )
      {
        AddSearchInfo(a1: v29, a2: (int)v32, putf8str: "GFxFontProvider not installed.");
        v11 = (GFxFontHandle *)v91;
      }
      goto LABEL_96;
    }
LABEL_95:
    if ( v11 != nullptr )
      break;
LABEL_96:
    if ( v85 != 0 && (lookupFlags & 0x10) != 0 )
    {
      lf = lookupFlags & 0xFFFFFFEF;
      v52 = *((_DWORD *)this + 5);
      v77.pMovieDef = nullptr;
      v77.pFontResource = nullptr;
      v53 = v52 != 0 ? v52 + 8 : 0;
      if ( (*(unsigned __int8 (__thiscall **)(int, GFxFontLib::FontResult *, void *, unsigned int, _DWORD, int, _DWORD))(*(_DWORD *)v85 + 4))(
             a1: v85,
             a2: &v77,
             a3: pname,
             a4: lf,
             a5: *((_DWORD *)this + 3),
             a6: v53,
             a7: 0) != 0 )
      {
        pfont.__vftable = (IVModelInfo_vtbl *)326;
        v65 = (const char *)this;
        v54 = (GFxFontHandle *)((int (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->AllocAutoHeap_2)(a1: GMemory::pGlobalHeap);
        v11 = v54 != nullptr
            ? GFxFontHandle::GFxFontHandle(
                this: v54,
                pmanager: v32 == nullptr
              ? (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this
              : nullptr,
                a3: (IShaderDevice *)v77.pFontResource,
                a4: (char *)result,
                overridenFontFlags: 0x10u,
                a6: (IShaderDevice *)v77.pMovieDef)
            : nullptr;
        v55 = lf;
        v56 = (char *)pname;
        *((float *)v11 + 4) = scaleFactor;
        *((float *)v11 + 5) = offx;
        *((float *)v11 + 6) = offy;
        v91 = (int)v11;
        AddSearchInfo_1(
          a1: (int)v32,
          putf8str: "Searching GFxFontLib without [Device] flag: \"",
          a3: v56,
          a4: "\" ",
          a5: v55,
          a6: " found.");
      }
      else
      {
        v65 = "\" ";
        AddSearchInfo_1(
          a1: (int)v32,
          putf8str: "Searching GFxFontLib without [Device] flag: \"",
          a3: v62,
          a4: v63,
          a5: v64,
          a6: (char *)pname);
      }
      GFxFontLib::FontResult::~FontResult(this: &v77);
      if ( v11 != nullptr )
        break;
    }
    if ( (matchFontFlags & 0x10) == 0 )
    {
      if ( v32 != nullptr )
        v32->GetTable = (const ScaleformUIFunctionHandlerDefinition *(__thiscall *)(IScaleformUIFunctionHandlerDefinitionTable *))((char *)v32->GetTable - indentDif);
LABEL_122:
      GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)v65);
      return nullptr;
    }
    AddSearchInfo(a1: v29, a2: (int)v32, putf8str: "Searching again without [Device] flag:");
    v11 = (GFxFontHandle *)v91;
    matchFontFlags &= ~0x10u;
    v76 = matchFontFlags;
    lf = 0;
    v85 = 0;
    secondLoop = true;
  }
  if ( v32 != nullptr )
  {
    v32->GetTable = (const ScaleformUIFunctionHandlerDefinition *(__thiscall *)(IScaleformUIFunctionHandlerDefinitionTable *))((char *)v32->GetTable - indentDif);
  }
  else
  {
    GFxFontManager::NodePtrHashOp::operator()(this: (SoundInfo_t *)((char *)&result + 3), a2: (int)v11);
    GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::add<GFxFontHandle *>(
      this: (CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short> *)((char *)this + 8),
      a2: (char *)this + 8,
      a3: &v91,
      a4: v61);
  }
  GFxMovieDefImpl::SearchInfo::~SearchInfo(this: &v71, a2: (unsigned int)v65);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101374A0
// Name: protected: class GFxFontHandle __near * GFxFontManager::CreateFontHandleFromName(char const __near *,unsigned int,struct GFxFontManager::FontSearchPathInfo __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxFontHandle *__thiscall GFxFontManager::CreateFontHandleFromName(
        GFxFontManager *this,
        CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *a2,
        unsigned int matchFontFlags,
        IScaleformUIFunctionHandlerDefinitionTable searchInfo)
{
  IScaleformUIFunctionHandlerDefinitionTable_vtbl *v5; // edi
  GString::DataDesc *v7; // ecx
  GFxFontHandle *v8; // esi
  unsigned int v9; // eax
  GFxFontHandle *v10; // eax
  int v11; // eax
  GFxFontManager *v13; // esi
  GFxFontHandle *v14; // eax
  CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short> *v15; // ebx
  int v16; // eax
  GString::DataDesc *v18; // [esp+Ch] [ebp-14h]
  const ScaleformUIFunctionHandlerDefinition *(__thiscall *saveIndent)(IScaleformUIFunctionHandlerDefinitionTable *); // [esp+10h] [ebp-10h]
  int newMatchFontFlags; // [esp+14h] [ebp-Ch]
  struct GFxFontResource *v21; // [esp+18h] [ebp-8h] BYREF
  GFxFontManager *v22; // [esp+1Ch] [ebp-4h]
  const struct GFxFontHandle *Handle; // [esp+28h] [ebp+8h]

  v5 = searchInfo.__vftable;
  v22 = this;
  saveIndent = nullptr;
  if ( searchInfo.__vftable != nullptr )
  {
    saveIndent = searchInfo.GetTable;
    AddSearchInfo_1(
      a1: (int)searchInfo.__vftable,
      putf8str: "Searching for font: \"",
      a3: (char *)a2,
      a4: "\" ",
      a5: matchFontFlags,
      a6: (char *)&pMem);
  }
  v21 = nullptr;
  v8 = GFxFontManager::FindOrCreateHandle(
         this,
         result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)a2,
         matchFontFlags,
         a4: &v21,
         searchInfo: (IScaleformUIFunctionHandlerDefinitionTable)v5);
  if ( v8 == nullptr )
  {
    v7 = (GString::DataDesc *)(matchFontFlags & 3);
    v18 = v7;
    if ( (matchFontFlags & 3) != 0 )
    {
      v9 = matchFontFlags & 0xFFFFFFFC;
      newMatchFontFlags = matchFontFlags & 0xFFFFFFFC;
      if ( v5 != nullptr )
      {
        ++v5->GetTable;
        AddSearchInfo_1(
          a1: (int)v5,
          putf8str: "Searching for font: \"",
          a3: (char *)a2,
          a4: "\" ",
          a5: v9,
          a6: (char *)&pMem);
        v9 = newMatchFontFlags;
      }
      Handle = GFxFontManager::FindOrCreateHandle(
                 this: v22,
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)a2,
                 matchFontFlags: v9,
                 a4: nullptr,
                 searchInfo: (IScaleformUIFunctionHandlerDefinitionTable)v5);
      if ( Handle != nullptr )
      {
        searchInfo.__vftable = (IScaleformUIFunctionHandlerDefinitionTable_vtbl *)326;
        v10 = (GFxFontHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: v22,
                                 a3: 36,
                                 a4: &searchInfo);
        v8 = v10 != nullptr ? GFxFontHandle::GFxFontHandle(this: v10, a2: Handle) : nullptr;
        *((_DWORD *)v8 + 2) |= (unsigned int)v18;
        searchInfo.__vftable = (IScaleformUIFunctionHandlerDefinitionTable_vtbl *)v8;
        if ( v5 != nullptr )
        {
          AddSearchInfo_2(
            a1: (int)v5,
            putf8str: "Font \"",
            a3: (char *)a2,
            a4: "\" ",
            a5: matchFontFlags,
            a6: " will be generated from \"",
            a7: (char *)a2,
            a8: "\"",
            a9: newMatchFontFlags);
        }
        else
        {
          GFxFontManager::NodePtrHashOp::operator()(this: (SoundInfo_t *)((char *)&matchFontFlags + 3), a2: (int)v8);
          GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::add<GFxFontHandle *>(
            this: (CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short> *)((char *)v22 + 8),
            a2: (char *)v22 + 8,
            a3: (int *)&searchInfo,
            a4: v11);
        }
        v7 = (GString::DataDesc *)Handle;
        if ( (*(_DWORD *)Handle)-- == 1 )
        {
          GFxFontHandle::~GFxFontHandle(this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)Handle);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: Handle);
        }
      }
    }
  }
  if ( v5 != nullptr )
  {
    v7 = (GString::DataDesc *)saveIndent;
    v5->GetTable = saveIndent;
  }
  if ( v8 == nullptr )
  {
    if ( v21 == nullptr )
      goto LABEL_26;
    AddSearchInfo_0(a1: (int)v5, putf8str: "Empty font: \"", a3: (char *)a2, a4: "\" is created");
    v13 = v22;
    matchFontFlags = 326;
    v14 = (GFxFontHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                             this: GMemory::pGlobalHeap,
                             a2: v22,
                             a3: 36,
                             a4: &matchFontFlags);
    v8 = v14 != nullptr
       ? GFxFontHandle::GFxFontHandle(
           this: v14,
           pmanager: v5 == nullptr
         ? (const CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v13
         : nullptr,
           a3: (IShaderDevice *)v21,
           a4: (char *)a2,
           overridenFontFlags: 0,
           a6: nullptr)
       : nullptr;
    searchInfo.__vftable = (IScaleformUIFunctionHandlerDefinitionTable_vtbl *)v8;
    if ( v5 == nullptr )
    {
      v15 = (CUtlMap<unsigned __int64,ScaleformUIAvatarImage *,unsigned short> *)((char *)v22 + 8);
      GFxFontManager::NodePtrHashOp::operator()(this: (SoundInfo_t *)((char *)&matchFontFlags + 3), a2: (int)v8);
      GHashSetBase<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp,GFxFontManager::NodePtrHashOp,GAllocatorLH<GFxFontManager::NodePtr,2>,GHashsetCachedEntry<GFxFontManager::NodePtr,GFxFontManager::NodePtrHashOp>>::add<GFxFontHandle *>(
        this: v15,
        a2: v15,
        a3: (int *)&searchInfo,
        a4: v16);
    }
    if ( v8 == nullptr )
LABEL_26:
      AddSearchInfo(a1: v7, a2: (int)v5, putf8str: "Font not found.");
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101376B0
// Name: public: void GFxFontManager::SetIMECandidateFont(class GFxFontHandle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFontManager::SetIMECandidateFont(GFxFontManager *this, struct GFxFontHandle *a2)
{
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v3; // esi

  if ( a2 != nullptr )
    ++*(_DWORD *)a2;
  v3 = *((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this
       + 12);
  if ( v3 != nullptr && LODWORD(v3->m_pfnProxied)-- == 1 )
  {
    GFxFontHandle::~GFxFontHandle(this: v3);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  *((_DWORD *)this + 12) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x101376F0
// Name: public: GFxFontManager::GFxFontManager(class GFxMovieDefImpl __near *,class GFxFontManagerStates __near *)
// Source: json
//------------------------------------------------------------------------------
CDefaultClientRenderable *__thiscall GFxFontManager::GFxFontManager(
        CDefaultClientRenderable *this,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pdefImpl,
        int a3)
{
  this->IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&GRefCountImplCore::`vftable';
  this->IClientRenderable::__vftable = (IClientRenderable_vtbl *)1;
  this->IClientUnknown::IHandleEntity::__vftable = (CDefaultClientRenderable_vtbl *)&GFxFontManager::`vftable';
  *(_DWORD *)&this->m_hRenderHandle = 0;
  *((_DWORD *)this + 6) = 0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 28));
  *((float *)this + 8) = 1.0;
  *((_DWORD *)this + 11) = 16;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 5) = a3;
  *((_IMAGE_SECTION_HEADER::<unnamed_type_Misc> *)this + 3) = pdefImpl;
  *((_DWORD *)this + 4) = 0;
  GFxFontManager::commonInit((CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> **)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10137780
// Name: public: class GFxFontHandle __near * GFxFontManager::CreateFontHandle(char const __near *,unsigned int,bool,struct GFxFontManager::FontSearchPathInfo __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxFontHandle *__thiscall GFxFontManager::CreateFontHandle(
        CDefaultClientRenderable *this,
        unsigned __int8 *string,
        unsigned int matchFontFlags,
        bool allowListOfFonts,
        IScaleformUIFunctionHandlerDefinitionTable searchInfo)
{
  unsigned __int8 *v5; // edi
  struct GFxFontHandle *FontHandleFromName; // ebx
  int v8; // eax
  int v9; // esi
  char *v10; // eax
  int v11; // [esp+Ch] [ebp-8Ch]
  char _Dst[128]; // [esp+14h] [ebp-84h] BYREF

  v5 = string;
  if ( !allowListOfFonts )
    return GFxFontManager::CreateFontHandleFromName(
             (GFxFontManager *)this,
             a2: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)string,
             matchFontFlags,
             searchInfo);
  FontHandleFromName = nullptr;
  do
  {
    strchr(string: v5, chr: 0x2Cu);
    v11 = v8;
    if ( v8 != 0 )
    {
      v9 = v8 - (_DWORD)v5;
      if ( (unsigned int)(v8 - (_DWORD)v5) > 0x7F )
        continue;
      strncpy_s(_Dst, _SizeInBytes: 0x7Fu, _Src: (const char *)v5, _Count: v8 - (_DWORD)v5);
      _Dst[v9] = 0;
      v10 = _Dst;
      v5 += v9 + 1;
    }
    else
    {
      v10 = (char *)v5;
    }
    FontHandleFromName = GFxFontManager::CreateFontHandleFromName(
                           (GFxFontManager *)this,
                           a2: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v10,
                           matchFontFlags,
                           searchInfo);
    if ( FontHandleFromName != nullptr )
      return FontHandleFromName;
    v8 = v11;
  }
  while ( v8 != 0 );
  return FontHandleFromName;
}

//------------------------------------------------------------------------------
// Address: 0x101362E0
// Name: unsigned int G_Format<char const __near *,char const __near *,class GString>(class GMsgFormat::Sink const __near &,char const __near *,char const __near * const __near &,char const __near * const __near &,class GString const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl G_Format<char const *,char const *,GString>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        CMatQueuedRenderContext::CCallQueueExternal *v,
        CMatQueuedRenderContext::CCallQueueExternal *a4,
        struct GString *a5)
{
  int m_nGrowSize; // esi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v7[27]; // [esp+10h] [ebp-304h] BYREF

  GMsgFormat::GMsgFormat(this: (GMsgFormat *)v7, a2: a1);
  GMsgFormat::Parse(this: v7, result: a2);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v7, v);
  GMsgFormat::FormatD1<char const *>(this: (CMatQueuedRenderContext::CCallQueueExternal *)v7, v: a4);
  GMsgFormat::FormatD1<GStringLH>(this: (GMsgFormat *)v7, a2: a5);
  GMsgFormat::FinishFormatD(this: v7);
  m_nGrowSize = v7[0].m_Elements.m_nGrowSize;
  GMsgFormat::~GMsgFormat(this: v7);
  return m_nGrowSize;
}
