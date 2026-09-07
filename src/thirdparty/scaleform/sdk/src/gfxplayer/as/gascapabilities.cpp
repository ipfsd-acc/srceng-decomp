// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gascapabilities.cpp
// Functions: 5
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gascapabilities.h"

//------------------------------------------------------------------------------
// Address: 0x1008FF70
// Name: public: virtual bool GASCapabilitiesCtorFunction::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASCapabilitiesCtorFunction::SetMemberRaw(
        GFxAmpMessageAppControl *this,
        int a2,
        int psc,
        _IMAGE_SYMBOL_EX *prop,
        tagWNDCLASSW *val)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1012C7B0
// Name: class GASString GFxCapabilities_ServerString(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__cdecl GFxCapabilities_ServerString(struct GASStringNode **a1, CUtlMemory<CImagePacker,int> a2)
{
  CImagePacker *m_pMemory; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  int v4; // eax
  IShaderAPI *v5; // esi
  int v6; // esi
  struct GFxMovieRoot *v7; // eax
  IShaderAPI *v8; // eax
  int *ConstStringNode; // esi
  bool v10; // zf
  int *v11; // esi
  struct GFxMovieRoot *v12; // eax
  int v13; // eax
  int v14; // eax
  int *v15; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // eax
  struct GASStringNode *StringNode; // eax
  GString::DataDesc *pData; // esi
  volatile LONG *v19; // esi
  void *v20; // esi
  void *v21; // esi
  void *v22; // esi
  int v24; // [esp+Ch] [ebp-70h] BYREF
  int v25; // [esp+10h] [ebp-6Ch]
  int v26; // [esp+14h] [ebp-68h]
  int v27; // [esp+18h] [ebp-64h]
  int v28; // [esp+1Ch] [ebp-60h]
  int v29; // [esp+20h] [ebp-5Ch]
  int v30; // [esp+24h] [ebp-58h]
  int v31; // [esp+28h] [ebp-54h]
  int v32; // [esp+2Ch] [ebp-50h]
  int v33; // [esp+30h] [ebp-4Ch]
  float v34; // [esp+34h] [ebp-48h]
  float v35; // [esp+38h] [ebp-44h]
  int v36; // [esp+3Ch] [ebp-40h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v37; // [esp+40h] [ebp-3Ch] BYREF
  GASValue v38; // [esp+58h] [ebp-24h] BYREF
  int v39; // [esp+5Ch] [ebp-20h]
  GString v40; // [esp+68h] [ebp-14h] BYREF
  GString v41; // [esp+6Ch] [ebp-10h] BYREF
  GString v42; // [esp+70h] [ebp-Ch] BYREF
  int v43; // [esp+74h] [ebp-8h] BYREF
  int v44; // [esp+78h] [ebp-4h] BYREF

  m_pMemory = a2.m_pMemory;
  GStringBuffer::GStringBuffer(
    this: &v37,
    result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)m_pMemory);
  v4 = (*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 34);
  v5 = (IShaderAPI *)v4;
  if ( v4 != 0 )
  {
    v43 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    GRefCountImpl::Release(this: v5);
    v6 = v43;
  }
  else
  {
    v6 = 0;
  }
  v44 = 0;
  if ( v6 == 0 )
  {
    GStringBuffer::AppendString(this: &v37, putf8str: "A=t", utf8StrSz: -1);
    goto LABEL_8;
  }
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v6 + 4))(a1: v6, a2: &v44);
  GStringBuffer::AppendString(this: &v37, putf8str: "A=t", utf8StrSz: -1);
  if ( (v44 & 1) != 0 )
  {
LABEL_8:
    GStringBuffer::AppendString(this: &v37, putf8str: "&MP3=f", utf8StrSz: -1);
    goto LABEL_9;
  }
  GStringBuffer::AppendString(this: &v37, putf8str: "&MP3=t", utf8StrSz: -1);
LABEL_9:
  if ( v6 == 0 || (v44 & 4) != 0 )
    GStringBuffer::AppendString(this: &v37, putf8str: "&SA=f", utf8StrSz: -1);
  else
    GStringBuffer::AppendString(this: &v37, putf8str: "&SA=t", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&SV=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&EV=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&IME=", utf8StrSz: -1);
  v7 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)m_pMemory);
  v8 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v7 + 2) + 12))(a1: (int)v7 + 8, a2: 27);
  if ( v8 != nullptr )
  {
    GRefCountImpl::Release(this: v8);
    GStringBuffer::AppendString(this: &v37, putf8str: "t", utf8StrSz: -1);
  }
  else
  {
    GStringBuffer::AppendString(this: &v37, putf8str: "f", utf8StrSz: -1);
  }
  GStringBuffer::AppendString(this: &v37, putf8str: "&AE=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&VE=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&ACC=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&PR=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&SP=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&SB=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&DEB=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&V=", utf8StrSz: -1);
  GString::GString(this: &a2);
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(m_pMemory->m_pLightmapWavefront[28] + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0AD0,
                             a3: 0xBu,
                             a4: 0);
  ++ConstStringNode[2];
  v10 = ++ConstStringNode[2] == 1;
  --ConstStringNode[2];
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
  GString::GString(this: &v40, src: *ConstStringNode);
  v10 = ConstStringNode[2]-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
  GASGlobalContext::Escape(
    a1: (const char *)((v40.HeapTypeBits & 0xFFFFFFFC) + 8),
    a2: *(_DWORD *)(v40.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    a3: &a2);
  GStringBuffer::AppendString(
    this: &v37,
    putf8str: (char *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8),
    utf8StrSz: *(_DWORD *)((int)a2.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
  GStringBuffer::AppendString(this: &v37, putf8str: "&M=", utf8StrSz: -1);
  GString::Clear(this: (GString *)&a2);
  v11 = (int *)GASStringManager::CreateConstStringNode(
                 this: *(GASStringManager **)(m_pMemory->m_pLightmapWavefront[28] + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7348,
                 a3: 0x11u,
                 a4: 0);
  ++v11[2];
  v10 = ++v11[2] == 1;
  --v11[2];
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  GString::GString(this: &v41, src: *v11);
  v10 = v11[2]-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v11);
  GASGlobalContext::Escape(
    a1: (const char *)((v41.HeapTypeBits & 0xFFFFFFFC) + 8),
    a2: *(_DWORD *)(v41.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    a3: &a2);
  GStringBuffer::AppendString(
    this: &v37,
    putf8str: (char *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8),
    utf8StrSz: *(_DWORD *)((int)a2.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
  v35 = 1.0;
  v34 = 1.0;
  v24 = 0;
  v25 = 0;
  v27 = 0;
  v26 = 0;
  v29 = 1;
  v28 = 1;
  v33 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  v36 = 0;
  v12 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)m_pMemory);
  (*(void (__thiscall **)(struct GFxMovieRoot *, int *))(*(_DWORD *)v12 + 104))(a1: v12, a2: &v24);
  GStringBuffer::AppendString(this: &v37, putf8str: "&R=", utf8StrSz: -1);
  LOBYTE(v38) = 4;
  v39 = v24;
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)&v38,
    a2: &v43,
    a3: (tagRID_DEVICE_INFO_KEYBOARD *)m_pMemory,
    precision: -1,
    debug: false);
  GStringBuffer::AppendString(this: &v37, putf8str: *(char **)v43, utf8StrSz: -1);
  v13 = v43;
  v10 = (*(_DWORD *)(v43 + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v13);
  GASValue::~GASValue(this: &v38, a2: (int)m_pMemory);
  GStringBuffer::AppendString(this: &v37, putf8str: (char *)&stru_1029F018.m_Memory.m_nGrowSize, utf8StrSz: -1);
  v39 = v25;
  LOBYTE(v38) = 4;
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)&v38,
    a2: &v43,
    a3: (tagRID_DEVICE_INFO_KEYBOARD *)m_pMemory,
    precision: -1,
    debug: false);
  GStringBuffer::AppendString(this: &v37, putf8str: *(char **)v43, utf8StrSz: -1);
  v14 = v43;
  v10 = (*(_DWORD *)(v43 + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: v14);
  GASValue::~GASValue(this: &v38, a2: (int)m_pMemory);
  GStringBuffer::AppendString(this: &v37, putf8str: "&DP=72", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&COL=color", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&AR=1.0", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&OS=", utf8StrSz: -1);
  GString::Clear(this: (GString *)&a2);
  v15 = (int *)GASStringManager::CreateConstStringNode(
                 this: *(GASStringManager **)(m_pMemory->m_pLightmapWavefront[28] + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A735C,
                 a3: 7u,
                 a4: 0);
  ++v15[2];
  v10 = ++v15[2] == 1;
  --v15[2];
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v15);
  GString::GString(this: &v42, src: *v15);
  v10 = v15[2]-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode(a1: (int)v15);
  GASGlobalContext::Escape(
    a1: (const char *)((v42.HeapTypeBits & 0xFFFFFFFC) + 8),
    a2: *(_DWORD *)(v42.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    a3: &a2);
  GStringBuffer::AppendString(
    this: &v37,
    putf8str: (char *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8),
    utf8StrSz: *(_DWORD *)((int)a2.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
  GStringBuffer::AppendString(this: &v37, putf8str: "&L=en", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&PT=External", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: "&AVD=f", utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: (char *)&stru_102A735C.m_pElements, utf8StrSz: -1);
  GStringBuffer::AppendString(this: &v37, putf8str: (char *)&stru_102A735C.m_Memory.m_nGrowSize, utf8StrSz: -1);
  m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v37.m_pfnProxied;
  if ( LODWORD(v37.m_pfnProxied) == 0 )
    m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)(m_pMemory->m_pLightmapWavefront[28] + 636),
                 result: m_pfnProxied,
                 length: DWORD1(v37.m_pfnProxied));
  ++*((_DWORD *)StringNode + 2);
  pData = v42.pData;
  *a1 = StringNode;
  v19 = (volatile LONG *)((unsigned int)pData & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v19 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v19);
  v20 = (void *)(v41.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v41.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v20);
  v21 = (void *)(v40.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v40.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
  v22 = (void *)((int)a2.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
  GStringBuffer::~GStringBuffer(this: &v37);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1012CD20
// Name: public: GASCapabilitiesCtorFunction::GASCapabilitiesCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASCapabilitiesCtorFunction::GASCapabilitiesCtorFunction(
        GFxAmpMessageAppControl *this,
        struct GASStringContext *psc)
{
  struct GASStringContext *v2; // esi
  GASObject *p_MsgType; // edi
  int v5; // eax
  unsigned int dwExitCode; // eax
  bool v7; // zf
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  struct GASStringNode *ConstStringNode; // eax
  GASStringManager *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // ecx
  struct GASStringNode *v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // ecx
  struct GASStringNode *v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // ecx
  int v32; // eax
  unsigned int v33; // eax
  struct GASStringNode *v34; // eax
  GASStringManager *v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // ecx
  struct GASStringNode *v38; // eax
  GASStringManager *v39; // ecx
  unsigned int v40; // eax
  unsigned int v41; // ecx
  int v42; // edx
  unsigned int v43; // eax
  struct GASStringNode *v44; // eax
  unsigned int v45; // eax
  unsigned int v46; // ecx
  unsigned int v47; // eax
  int v48; // eax
  unsigned int v49; // eax
  int v50; // ecx
  unsigned int v51; // eax
  int v52; // edx
  unsigned int v53; // eax
  int v54; // [esp+0h] [ebp-38h]
  GASValue v55; // [esp+Ch] [ebp-2Ch] BYREF
  int v56; // [esp+10h] [ebp-28h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *falseVal; // [esp+1Ch] [ebp-1Ch] BYREF
  char v58; // [esp+20h] [ebp-18h]
  GFxAmpMessageAppControl *v59; // [esp+2Ch] [ebp-Ch]
  _EXIT_THREAD_DEBUG_INFO v60; // [esp+30h] [ebp-8h] BYREF
  _EXIT_THREAD_DEBUG_INFO v61; // [esp+34h] [ebp-4h] BYREF

  v2 = psc;
  v59 = this;
  GASCFunctionObject::GASCFunctionObject((GASCFunctionObject *)this, psc);
  this->__vftable = (GFxAmpMessageAppControl_vtbl *)&GASSelectionCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  p_MsgType = (GASObject *)&this->MsgType;
  p_MsgType->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASCapabilitiesCtorFunction::`vftable'{for `GASObjectInterface'};
  v5 = *(_DWORD *)v2;
  HIBYTE(psc) = 6;
  LOBYTE(falseVal) = 2;
  v58 = 0;
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v5 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A75E0,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  dwExitCode = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: dwExitCode);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"hasAccessibility",
                                   a3: 0x10u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v8 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v8);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A75B0.m_pElements,
                                   a3: 8u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v9 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v9);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A75B0,
                                   a3: 0xFu,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v10 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v10);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"hasEmbeddedVideo",
                                   a3: 0x10u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v11 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v11);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"hasIME",
                                   a3: 6u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v12 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v12);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7580.m_Size,
                                   a3: 6u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v13 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v13);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7580,
                                   a3: 0xBu,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v14 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v14);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A756C,
                                   a3: 0x12u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v15 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v15);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7558,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v16 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v16);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7544,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v17 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v17);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"hasStreamingVideo",
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v18 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v18);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7514.m_Size,
                                   a3: 0xFu,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v19 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v19);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7514,
                                   a3: 0xAu,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v20 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v20);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"localFileReadDisable",
                                   a3: 0x14u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v21 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v21);
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&unk_102A74F8,
                      a3: 2u,
                      a4: 0);
  ++*((_DWORD *)ConstStringNode + 2);
  LOBYTE(v55) = 5;
  v56 = (int)ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  v23 = *(GASStringManager **)(*(_DWORD *)v2 + 636);
  v60.dwExitCode = (unsigned int)ConstStringNode;
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: v23,
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"language",
                                   a3: 8u,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v24 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v24);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v25 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v25);
  v26 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7348,
          a3: 0x11u,
          a4: 0);
  ++*((_DWORD *)v26 + 2);
  v7 = ++*((_DWORD *)v26 + 2) == 1;
  --*((_DWORD *)v26 + 2);
  v60.dwExitCode = (unsigned int)v26;
  if ( v7 )
  {
    GASStringNode::ReleaseNode(a1: (int)v26);
    v26 = (struct GASStringNode *)v60.dwExitCode;
  }
  v56 = (int)v26;
  LOBYTE(v55) = 5;
  ++*((_DWORD *)v26 + 2);
  v61.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A74D8.m_Memory.m_nAllocationCount,
                                   a3: 0xCu,
                                   a4: 0);
  ++*(_DWORD *)(v61.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v61,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v27 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v27);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v28 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v28);
  v29 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A735C,
          a3: 7u,
          a4: 0);
  ++*((_DWORD *)v29 + 2);
  v7 = ++*((_DWORD *)v29 + 2) == 1;
  --*((_DWORD *)v29 + 2);
  v61.dwExitCode = (unsigned int)v29;
  if ( v7 )
  {
    GASStringNode::ReleaseNode(a1: (int)v29);
    v29 = (struct GASStringNode *)v61.dwExitCode;
  }
  LOBYTE(v55) = 5;
  v56 = (int)v29;
  ++*((_DWORD *)v29 + 2);
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A74D8,
                                   a3: 2u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v30 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v30);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v31 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v31);
  v32 = *(_DWORD *)v2;
  LOBYTE(v55) = 4;
  v56 = 1;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v32 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"pixelAspectRatio",
                                   a3: 0x10u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v33 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v33);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v34 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"External",
          a3: 8u,
          a4: 0);
  ++*((_DWORD *)v34 + 2);
  LOBYTE(v55) = 5;
  v56 = (int)v34;
  ++*((_DWORD *)v34 + 2);
  v35 = *(GASStringManager **)(*(_DWORD *)v2 + 636);
  v61.dwExitCode = (unsigned int)v34;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: v35,
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"playerType",
                                   a3: 0xAu,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v36 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v36);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v37 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v37);
  v38 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"color",
          a3: 5u,
          a4: 0);
  ++*((_DWORD *)v38 + 2);
  LOBYTE(v55) = 5;
  v56 = (int)v38;
  ++*((_DWORD *)v38 + 2);
  v39 = *(GASStringManager **)(*(_DWORD *)v2 + 636);
  v61.dwExitCode = (unsigned int)v38;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: v39,
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"screenColor",
                                   a3: 0xBu,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v40 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v40);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v41 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v41);
  v42 = *(_DWORD *)v2;
  LOBYTE(v55) = 4;
  v56 = 72;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v42 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A748C.m_Memory.m_nGrowSize,
                                   a3: 9u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v43 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v43);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v44 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A0AD0,
          a3: 0xBu,
          a4: 0);
  ++*((_DWORD *)v44 + 2);
  v7 = ++*((_DWORD *)v44 + 2) == 1;
  --*((_DWORD *)v44 + 2);
  v61.dwExitCode = (unsigned int)v44;
  if ( v7 )
  {
    GASStringNode::ReleaseNode(a1: (int)v44);
    v44 = (struct GASStringNode *)v61.dwExitCode;
  }
  LOBYTE(v55) = 5;
  v56 = (int)v44;
  ++*((_DWORD *)v44 + 2);
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A748C,
                                   a3: 7u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v45 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v45);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v46 = v61.dwExitCode;
  v7 = (*(_DWORD *)(v61.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v46);
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(*(_DWORD *)v2 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7478,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &falseVal,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v47 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v47);
  v48 = *(_DWORD *)v2;
  LOBYTE(v55) = 10;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v48 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7464,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v49 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v49);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v50 = *(_DWORD *)v2;
  LOBYTE(v55) = 10;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v50 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7440.m_pElements,
                                   a3: 0x11u,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v51 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v51);
  GASValue::~GASValue(this: &v55, a2: (int)p_MsgType);
  v52 = *(_DWORD *)v2;
  LOBYTE(v55) = 10;
  v60.dwExitCode = (unsigned int)GASStringManager::CreateConstStringNode(
                                   this: *(GASStringManager **)(v52 + 636),
                                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7440,
                                   a3: 0xCu,
                                   a4: 0);
  ++*(_DWORD *)(v60.dwExitCode + 8);
  GASObject::SetMemberRaw(
    this: p_MsgType,
    a2: v2,
    a3: &v60,
    a4: &v55,
    a5: (const struct GASPropFlags *)((char *)&psc + 3));
  v53 = v60.dwExitCode;
  v7 = (*(_DWORD *)(v60.dwExitCode + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode(a1: v53);
  GASValue::~GASValue(this: &v55, a2: v54);
  GASValue::~GASValue(this: &falseVal, a2: v54);
}

//------------------------------------------------------------------------------
// Address: 0x1012D5F0
// Name: public: virtual bool GASCapabilitiesCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GASCapabilitiesCtorFunction::GetMember(
        D3DXQUATERNION *this,
        GASEnvironment *result,
        _IMAGE_SYMBOL_EX *name,
        int *a4)
{
  struct GFxMovieRoot *MovieRoot; // eax
  int v6; // eax
  IShaderAPI *v7; // esi
  char v8; // bl
  int v9; // ecx
  struct GFxMovieRoot *v10; // eax
  int v11; // eax
  struct GFxMovieRoot *v13; // eax
  const char ***v14; // esi
  struct GFxMovieRoot *v15; // eax
  IShaderAPI *v16; // eax
  IShaderAPI *v17; // esi
  bool v18; // zf
  struct GASStringNode **v19; // eax
  int *v20; // ecx
  _IMAGE_SYMBOL_EX *v21; // eax
  int *ConstStringNode; // eax
  int v23; // esi
  int *v24; // eax
  int v25; // esi
  int *v26; // eax
  int v27; // esi
  int *v28; // eax
  int v29; // esi
  int *v30; // eax
  int v31; // esi
  int *v32; // eax
  int v33; // esi
  int *v34; // eax
  int v35; // esi
  struct GFxMovieRoot *v36; // eax
  CUtlMemory<CImagePacker,int> v37; // [esp-4h] [ebp-60h]
  int v38; // [esp+Ch] [ebp-50h] BYREF
  int v39; // [esp+10h] [ebp-4Ch]
  int v40; // [esp+14h] [ebp-48h]
  int v41; // [esp+18h] [ebp-44h]
  int v42; // [esp+1Ch] [ebp-40h]
  int v43; // [esp+20h] [ebp-3Ch]
  int v44; // [esp+24h] [ebp-38h]
  int v45; // [esp+28h] [ebp-34h]
  int v46; // [esp+2Ch] [ebp-30h]
  int v47; // [esp+30h] [ebp-2Ch]
  float v48; // [esp+34h] [ebp-28h]
  float v49; // [esp+38h] [ebp-24h]
  int v50; // [esp+3Ch] [ebp-20h]
  GASValue v51; // [esp+40h] [ebp-1Ch] BYREF
  struct GASStringNode *v52; // [esp+44h] [ebp-18h]
  D3DXQUATERNION *v53; // [esp+50h] [ebp-Ch]
  unsigned int cap_bits; // [esp+54h] [ebp-8h] BYREF
  int v55; // [esp+58h] [ebp-4h]
  bool result_3; // [esp+67h] [ebp+Bh]
  bool result_3a; // [esp+67h] [ebp+Bh]
  bool result_3b; // [esp+67h] [ebp+Bh]
  bool result_3c; // [esp+67h] [ebp+Bh]
  bool result_3d; // [esp+67h] [ebp+Bh]
  bool result_3e; // [esp+67h] [ebp+Bh]
  bool result_3f; // [esp+67h] [ebp+Bh]

  v53 = this;
  MovieRoot = GASEnvironment::GetMovieRoot(this: result);
  v6 = (*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 34);
  v7 = (IShaderAPI *)v6;
  v8 = 0;
  if ( v6 != 0 )
  {
    v55 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    GRefCountImpl::Release(this: v7);
    v9 = v55;
  }
  else
  {
    v9 = 0;
    v55 = 0;
  }
  cap_bits = 0;
  if ( v9 != 0 )
    (*(void (__thiscall **)(int, unsigned int *))(*(_DWORD *)v9 + 4))(a1: v9, a2: &cap_bits);
  if ( *((_BYTE *)result + 124) <= 6u )
  {
    ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                               this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                               result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7464,
                               a3: 0x11u,
                               a4: 0);
    v23 = (int)ConstStringNode;
    ++ConstStringNode[2];
    if ( ConstStringNode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3 = *(_DWORD *)(v23 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v23 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v23);
    if ( result_3 )
      goto LABEL_9;
    v24 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7440.m_pElements,
                   a3: 0x11u,
                   a4: 0);
    v25 = (int)v24;
    ++v24[2];
    if ( v24[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v24);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3a = *(_DWORD *)(v25 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v25 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v25);
    if ( result_3a )
      goto LABEL_15;
    v26 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"hasIME",
                   a3: 6u,
                   a4: 0);
    v27 = (int)v26;
    ++v26[2];
    if ( v26[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v26);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3b = *(_DWORD *)(v27 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v27 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v27);
    if ( result_3b )
      goto LABEL_17;
    v28 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A75B0.m_pElements,
                   a3: 8u,
                   a4: 0);
    v29 = (int)v28;
    ++v28[2];
    if ( v28[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v28);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3c = *(_DWORD *)(v29 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v29 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v29);
    if ( result_3c )
    {
      LOBYTE(v51) = 2;
      LOBYTE(v52) = v55 != 0;
      GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v51);
      goto LABEL_12;
    }
    v30 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7580.m_Size,
                   a3: 6u,
                   a4: 0);
    v31 = (int)v30;
    ++v30[2];
    if ( v30[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v30);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3d = *(_DWORD *)(v31 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v31 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v31);
    if ( result_3d )
    {
      if ( v55 != 0 )
      {
        v18 = (cap_bits & 1) == 0;
LABEL_30:
        if ( v18 )
          v8 = 1;
      }
LABEL_26:
      LOBYTE(v51) = 2;
      LOBYTE(v52) = v8;
      GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v51);
      goto LABEL_12;
    }
    v32 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7544,
                   a3: 0x11u,
                   a4: 0);
    v33 = (int)v32;
    ++v32[2];
    if ( v32[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v32);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3e = *(_DWORD *)(v33 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v33 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v33);
    if ( result_3e )
    {
LABEL_28:
      if ( v55 != 0 )
      {
        v18 = (cap_bits & 4) == 0;
        goto LABEL_30;
      }
      goto LABEL_26;
    }
    v34 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*((_DWORD *)result + 30) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A7440,
                   a3: 0xCu,
                   a4: 0);
    v35 = (int)v34;
    ++v34[2];
    if ( v34[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v34);
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    result_3f = *(_DWORD *)(v35 + 4) == *(_DWORD *)(name->N.Name.Short + 4);
    v18 = (*(_DWORD *)(v35 + 8))-- == 1;
    if ( v18 )
      GASStringNode::ReleaseNode(a1: v35);
    if ( result_3f )
      goto LABEL_34;
  }
  else
  {
    if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A7464) == 0 )
    {
LABEL_9:
      v49 = 1.0;
      v48 = 1.0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
      v40 = 0;
      v43 = 1;
      v42 = 1;
      v47 = 0;
      v46 = 0;
      v45 = 0;
      v44 = 0;
      v50 = 0;
      v10 = GASEnvironment::GetMovieRoot(this: result);
      (*(void (__thiscall **)(struct GFxMovieRoot *, int *))(*(_DWORD *)v10 + 104))(a1: v10, a2: &v38);
      v11 = v38;
LABEL_10:
      LOBYTE(v51) = 4;
      v52 = (struct GASStringNode *)v11;
LABEL_11:
      GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v51);
LABEL_12:
      GASValue::~GASValue(this: &v51, a2: (int)result);
      return 1;
    }
    if ( strcmp(*(const char **)name->N.Name.Short, (const char *)&stru_102A7440.m_pElements) == 0 )
    {
LABEL_15:
      v49 = 1.0;
      v48 = 1.0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
      v40 = 0;
      v43 = 1;
      v42 = 1;
      v47 = 0;
      v46 = 0;
      v45 = 0;
      v44 = 0;
      v50 = 0;
      v13 = GASEnvironment::GetMovieRoot(this: result);
      (*(void (__thiscall **)(struct GFxMovieRoot *, int *))(*(_DWORD *)v13 + 104))(a1: v13, a2: &v38);
      v11 = v39;
      goto LABEL_10;
    }
    v14 = (const char ***)name;
    if ( GASString::operator==(this: (const char ***)name, a2: "hasIME") )
    {
LABEL_17:
      v15 = GASEnvironment::GetMovieRoot(this: result);
      v16 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v15 + 2) + 12))(a1: (int)v15 + 8, a2: 27);
      v17 = v16;
      if ( v16 != nullptr )
        GRefCountImpl::Release(this: v16);
      LOBYTE(v51) = 2;
      LOBYTE(v52) = v17 != nullptr;
      GASValue::operator=(this: (int)a4, v: (tagWNDCLASSW *)&v51);
      goto LABEL_12;
    }
    if ( GASString::operator==(this: v14, a2: (const char *)&stru_102A75B0.m_pElements) )
    {
      LOBYTE(v51) = 2;
      LOBYTE(v52) = v55 != 0;
      goto LABEL_11;
    }
    if ( GASString::operator==(this: v14, a2: (const char *)&stru_102A7580.m_Size) )
    {
      if ( v55 != 0 && (cap_bits & 1) == 0 )
        v8 = 1;
      goto LABEL_26;
    }
    if ( GASString::operator==(this: v14, a2: (const char *)&stru_102A7544) )
      goto LABEL_28;
    if ( GASString::operator==(this: v14, a2: (const char *)&stru_102A7440) )
    {
LABEL_34:
      v37.m_pMemory = (CImagePacker *)result;
      v19 = GFxCapabilities_ServerString(a1: (struct GASStringNode **)&name, a2: v37);
      v20 = a4;
      LOBYTE(v51) = 5;
      v52 = *v19;
      ++*((_DWORD *)v52 + 2);
      GASValue::operator=(this: (int)v20, v: (tagWNDCLASSW *)&v51);
      GASValue::~GASValue(this: &v51, a2: (int)result);
      v21 = name;
      v18 = name->Value-- == 1;
      if ( !v18 )
        return 1;
      GASStringNode::ReleaseNode(a1: (int)v21);
      return 1;
    }
  }
  if ( *(_BYTE *)(*((_DWORD *)result + 30) + 684) == 1
    && GASString::operator==(this: (const char ***)name, a2: "numControllers") )
  {
    v36 = GASEnvironment::GetMovieRoot(this: result);
    v11 = (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)v36 + 236))(a1: v36);
    goto LABEL_10;
  }
  return (unsigned __int8)GASObject::GetMember(this: v53, (ID3DXFont *)result, penv: name, val: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1012DB90
// Name: public: static class GASFunctionRef GASCapabilitiesCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASCapabilitiesCtorFunction::Register(
        struct GFxAmpStream *pgc,
        struct GASFunctionRef *a2,
        _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v3; // esi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GFxAmpMessageAppControl *v6; // eax
  int v7; // eax
  const char *MaxVal; // ecx
  int (__thiscall *v10)(const char *, int, _KCRM_MARSHAL_HEADER **); // edx
  GASObjectProto *v11; // ebx
  GASObjectProto *v12; // ebx
  const char *MinVal; // edx
  GASValue *v14; // eax
  __int64 v15; // [esp-Ch] [ebp-30h]
  GASValue v16[4]; // [esp+Ch] [ebp-18h] BYREF
  unsigned int psc; // [esp+1Ch] [ebp-8h] BYREF
  char v18; // [esp+20h] [ebp-4h]
  struct GASFunctionRef *v19; // [esp+2Ch] [ebp+8h]

  v3 = (vc_attributes::PreRangeAttribute *)pgca;
  VersionMajor = pgca[41].VersionMajor;
  psc = (unsigned int)pgca;
  v18 = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GFxAmpMessageAppControl *)v5(a1: VersionMajor, a2: 56, a3: &pgca);
  if ( v6 != nullptr )
    GASCapabilitiesCtorFunction::GASCapabilitiesCtorFunction(this: v6, (struct GASStringContext *)&psc);
  else
    v7 = 0;
  *(_DWORD *)a2 = v7;
  *((_BYTE *)a2 + 8) = 0;
  *((_DWORD *)a2 + 1) = 0;
  MaxVal = v3[54].MaxVal;
  v10 = *(int (__thiscall **)(const char *, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)MaxVal + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v11 = (GASObjectProto *)v10(a1: MaxVal, a2: 84, a3: &pgca);
  if ( v11 != nullptr )
  {
    HIDWORD(v15) = GASGlobalContext::GetPrototype(this: v3, result: (vc_attributes::InvalidCheckAttribute *)1);
    LODWORD(v15) = &psc;
    v12 = GASObjectProto::GASObjectProto(this: v11, psc: v15, psc_8: a2);
  }
  else
  {
    v12 = nullptr;
  }
  if ( v12 != nullptr )
    *((_DWORD *)v12 + 2) = (*((_DWORD *)v12 + 2) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: 17, a2: v12);
  MinVal = v3[55].MinVal;
  HIBYTE(pgca) = 0;
  v19 = *((struct GASFunctionRef **)MinVal + 4);
  v14 = GASValue::GASValue(this: v16, (int)a2, a3: a2);
  (*((void (__thiscall **)(const char *, unsigned int *, const char **, GASValue *, char *))v19 + 10))(
    a1: v3[55].MinVal + 16,
    a2: &psc,
    a3: &v3[6].MinVal,
    a4: v14,
    a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: v16, (int)a2);
  if ( v12 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v12, (int)a2);
}
