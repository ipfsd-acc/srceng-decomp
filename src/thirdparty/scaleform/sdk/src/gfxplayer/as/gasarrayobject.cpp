// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasarrayobject.cpp
// Functions: 58
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasarrayobject.h"

//------------------------------------------------------------------------------
// Address: 0x100A6080
// Name: GAS_ParseNumber
// Source: json
//------------------------------------------------------------------------------
bool __usercall GAS_ParseNumber@<al>(char *a1@<ecx>, double a2@<st0>, double *a3)
{
  char v3; // al
  char *v4; // eax
  bool result; // al
  char *v6; // [esp+0h] [ebp-4h] BYREF

  v6 = a1;
  result = false;
  if ( a1 != nullptr )
  {
    v3 = *a1;
    if ( *a1 != 0 && (v3 >= 48 && v3 <= 57 || v3 == 43 || v3 == 45 || v3 == 46) )
    {
      G_strtod(_Src: a1, endptr: &v6);
      v4 = v6;
      *a3 = a2;
      if ( v4 == nullptr || *v4 == 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A60D0
// Name: public: static int GASArrayObject::ParseIndex(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GASArrayObject::ParseIndex(const char ***a1)
{
  char *v1; // ecx
  char v2; // al

  v1 = (char *)**a1;
  v2 = *v1;
  if ( *v1 == 0 )
    return atoi(nptr: **a1);
  while ( v2 >= 48 && v2 <= 57 )
  {
    v2 = *++v1;
    if ( v2 == 0 )
      return atoi(nptr: **a1);
  }
  if ( *v1 != 0 )
    return -1;
  else
    return atoi(nptr: **a1);
}

//------------------------------------------------------------------------------
// Address: 0x100A6110
// Name: public: virtual enum GASObjectInterface::ObjectType GASArrayObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASArrayObject::GetObjectType()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100A6120
// Name: protected: void GASArrayObject::InitArray(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::InitArray(int a1@<ecx>, int fn, GMemoryHeap *IndexNumber, int fn_8)
{
  int v4; // edi
  int v5; // ebx
  int v6; // esi
  struct GASValue *v7; // eax
  int v8; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v10; // [esp-10h] [ebp-30h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *IndexNumbera; // [esp+8h] [ebp-18h] BYREF
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+18h] [ebp-8h] BYREF
  int *v14; // [esp+1Ch] [ebp-4h]

  v4 = fn;
  v5 = 0;
  LOBYTE(IndexNumbera) = 0;
  if ( *(int *)(fn + 28) > 0 )
  {
    v14 = (int *)(a1 + 16);
    do
    {
      if ( (unsigned __int8)IndexNumbera >= 5u )
        GASValue::DropRefs(this: &IndexNumbera, a2: v4);
      v10 = *(tagRID_DEVICE_INFO_KEYBOARD **)(v4 + 24);
      LOBYTE(IndexNumbera) = 4;
      v12 = v5;
      HIBYTE(fn) = 0;
      GASValue::ToStringImpl(this: (unsigned __int8 *)&IndexNumbera, a2: &v13, a3: v10, precision: -1, debug: false);
      v6 = *v14;
      v7 = GASFnCall::Arg(this: (GASFnCall *)v4, a2: v5);
      (*(void (__thiscall **)(int *, _DWORD, int *, struct GASValue *, char *))(v6 + 12))(
        a1: v14,
        a2: *(_DWORD *)(v4 + 24),
        a3: &v13,
        a4: v7,
        a5: (char *)&fn + 3);
      v8 = v13;
      if ( (*(_DWORD *)(v13 + 8))-- == 1 )
        GASStringNode::ReleaseNode(a1: v8);
      ++v5;
    }
    while ( v5 < *(_DWORD *)(v4 + 28) );
  }
  GASValue::~GASValue(this: &IndexNumbera, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A61C0
// Name: protected: void GASArrayObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(ISteamUserStats *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  int *v5; // ecx

  LOBYTE(v2) = GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
  v3 = *((_DWORD *)this + 15);
  for ( i = 0; i < v3; ++i )
  {
    v2 = *((_DWORD *)this + 14);
    v5 = *(int **)(v2 + 4 * i);
    if ( v5 != nullptr )
      LOBYTE(v2) = GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(a1: v5, a2: (int)this);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100A61F0
// Name: protected: void GASArrayObject::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int *v4; // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(int **)(*((_DWORD *)this + 14) + 4 * i);
    if ( v4 != nullptr )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6220
// Name: protected: void GASArrayObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int *v4; // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(int **)(*((_DWORD *)this + 14) + 4 * i);
    if ( v4 != nullptr )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6250
// Name: protected: void GASArrayObject::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(ISteamUserStats *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int i; // esi
  _DWORD *v5; // ecx

  LOBYTE(v2) = GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
  v3 = *((_DWORD *)this + 15);
  for ( i = 0; i < v3; ++i )
  {
    v2 = *((_DWORD *)this + 14);
    v5 = *(_DWORD **)(v2 + 4 * i);
    if ( v5 != nullptr )
      LOBYTE(v2) = GASValue::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this: v5);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100A6280
// Name: protected: void GASArrayObject::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(ISteamUserStats *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  int *v4; // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(int **)(*((_DWORD *)this + 14) + 4 * i);
    if ( v4 != nullptr )
      GASValue::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A62B0
// Name: public: void GASArrayObject::MakeDeepCopy(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
const ISteamApps *__thiscall GASArrayObject::MakeDeepCopy(_DWORD *this, const ISteamApps *result)
{
  const ISteamApps *v3; // eax
  unsigned int v4; // ebx
  bool (__thiscall *BIsSubscribed)(ISteamApps *); // edx
  GASValue *v6; // eax
  GASValue *v7; // eax
  const ISteamApps *n; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v3 = (const ISteamApps *)*(this + 15);
  v4 = 0;
  n = v3;
  if ( v3 != nullptr )
  {
    do
    {
      if ( *(_DWORD *)(4 * v4 + *(this + 14)) != 0 )
      {
        BIsSubscribed = result->__vftable[1].BIsSubscribed;
        v9 = 323;
        v6 = (GASValue *)((int (__thiscall *)(const ISteamApps *, int, int *))BIsSubscribed)(
                           a1: result,
                           a2: 16,
                           a3: &v9);
        if ( v6 != nullptr )
          v7 = GASValue::GASValue(this: v6, v: *(tagWNDCLASSW **)(*(this + 14) + 4 * v4));
        else
          v7 = nullptr;
        *(_DWORD *)(4 * v4 + *(this + 14)) = v7;
        v3 = n;
      }
      ++v4;
    }
    while ( v4 < (unsigned int)v3 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A6330
// Name: public: void GASArrayObject::JoinToString(class GASEnvironment __near *,class GStringBuffer __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::JoinToString(
        ISteamApps *this,
        char **pEnv,
        const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *pbuffer,
        unsigned int putf8str)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *v4; // esi
  tagRID_DEVICE_INFO_KEYBOARD *v5; // edi
  ISteamApps_vtbl *v6; // ebx
  unsigned __int8 **v7; // eax
  const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v8; // eax
  GASValue undefined[4]; // [esp+Ch] [ebp-14h] BYREF
  ISteamApps *v11; // [esp+1Ch] [ebp-4h]

  v4 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)pbuffer;
  v5 = (tagRID_DEVICE_INFO_KEYBOARD *)this;
  v11 = this;
  GStringBuffer::Clear(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)pbuffer);
  v6 = nullptr;
  LOBYTE(undefined[0]) = 0;
  if ( v5[2].dwNumberOfFunctionKeys != 0 )
  {
    v5 = (tagRID_DEVICE_INFO_KEYBOARD *)pEnv;
    do
    {
      if ( v6 != nullptr )
        GStringBuffer::AppendString(this: v4, (char *)putf8str, utf8StrSz: -1);
      v7 = (unsigned __int8 **)(&v11[14].BIsSubscribed + (_DWORD)v6);
      if ( *v7 != nullptr )
      {
        GASValue::ToStringImpl(this: *v7, a2: (int *)&pbuffer, a3: v5, precision: -1, debug: false);
        GStringBuffer::AppendString(this: v4, putf8str: (char *)pbuffer->m_LessFunc.m_LessFunc, utf8StrSz: -1);
        v8 = pbuffer;
      }
      else
      {
        GASValue::ToStringImpl(
          this: (unsigned __int8 *)undefined,
          a2: (int *)&pEnv,
          a3: v5,
          precision: -1,
          debug: false);
        GStringBuffer::AppendString(this: v4, putf8str: *pEnv, utf8StrSz: -1);
        v8 = (const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)pEnv;
      }
      if ( v8->m_Elements.m_nAllocationCount-- == 1 )
        GASStringNode::ReleaseNode(a1: (int)v8);
      v6 = (ISteamApps_vtbl *)((char *)v6 + 1);
    }
    while ( v6 < v11[15].__vftable );
  }
  GASValue::~GASValue(this: undefined, a2: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x100A63E0
// Name: public: void GASArrayObject::SetElement(int,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::SetElement(GASArrayObject *this, int a2, tagWNDCLASSW *v)
{
  int v3; // edi
  _BYTE *v5; // eax

  v3 = a2;
  if ( a2 >= 0 && a2 < *((_DWORD *)this + 15) )
  {
    if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * a2) == 0 )
    {
      a2 = 323;
      v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 16, a4: &a2);
      if ( v5 != nullptr )
        *v5 = 0;
      else
        v5 = nullptr;
      *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v3) = v5;
    }
    GASValue::operator=(this: *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v3), v);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6440
// Name: void GAS_ArrayJoin(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ArrayJoin(const struct GASFnCall *fn)
{
  int v1; // ebx
  ISteamApps *v2; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v3; // edi
  unsigned __int8 *v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v7; // eax
  struct GASStringNode *StringNode; // edi
  int v9; // esi
  std::bad_exception *sbuffer; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int length; // [esp+8h] [ebp-18h]
  unsigned int *v12; // [esp+1Ch] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v1 = *((_DWORD *)fn + 2);
    if ( v1 != 0 )
      v2 = (ISteamApps *)(v1 - 16);
    else
      v2 = nullptr;
    GStringBuffer::GStringBuffer(
      this: &sbuffer,
      result: *(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656));
    if ( *((_DWORD *)fn + 7) != 0 )
    {
      v3 = *((tagRID_DEVICE_INFO_KEYBOARD **)fn + 6);
      v4 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      GASValue::ToStringImpl(this: v4, a2: (int *)&v12, a3: v3, precision: -1, debug: false);
      GASArrayObject::JoinToString(
        this: v2,
        pEnv: *((char ***)fn + 6),
        pbuffer: (const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&sbuffer,
        putf8str: *v12);
      v5 = (int)v12;
      v6 = v12[2]-- == 1;
      if ( v6 )
        GASStringNode::ReleaseNode(a1: v5);
    }
    else
    {
      GASArrayObject::JoinToString(
        this: v2,
        pEnv: *((char ***)fn + 6),
        pbuffer: (const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&sbuffer,
        putf8str: (unsigned int)",");
    }
    v7 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)sbuffer;
    if ( sbuffer == nullptr )
      v7 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
    StringNode = GASStringManager::CreateStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 636),
                   result: v7,
                   length);
    ++*((_DWORD *)StringNode + 2);
    v9 = *((_DWORD *)fn + 1);
    if ( *(_BYTE *)v9 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v9, a2: (int)StringNode);
    *(_BYTE *)v9 = 5;
    *(_DWORD *)(v9 + 4) = StringNode;
    v6 = ++*((_DWORD *)StringNode + 2) == 1;
    --*((_DWORD *)StringNode + 2);
    if ( v6 )
      GASStringNode::ReleaseNode(a1: (int)StringNode);
    GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)&sbuffer);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6550
// Name: void GAS_ArrayReverse(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ArrayReverse(const struct GASFnCall *fn)
{
  const struct GASFnCall *v1; // esi
  int v2; // edi
  struct GASObject *v3; // edi
  int v4; // eax
  int v5; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  int v7; // esi

  v1 = fn;
  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v2 = *((_DWORD *)fn + 2);
    if ( v2 != 0 )
      v3 = (struct GASObject *)(v2 - 16);
    else
      v3 = nullptr;
    v4 = v3[7].sequence - 1;
    v5 = 0;
    if ( v4 > 0 )
    {
      do
      {
        pNode = v3[7].pNode;
        v7 = *((_DWORD *)&pNode->pNext + v5);
        *((_DWORD *)&pNode->pNext + v5) = *((_DWORD *)&pNode->pNext + v4);
        *((_DWORD *)&pNode->pNext + v4) = v7;
        ++v5;
        --v4;
      }
      while ( v5 < v4 );
      v1 = fn;
    }
    GASValue::SetAsObject(this: *((GASValue **)v1 + 1), a2: v3);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A65C0
// Name: public: virtual bool GASArrayObject::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::GetMemberRaw(
        CTSQueue<CFunctor *,0,1> *a1@<ecx>,
        int a2@<edi>,
        _IMAGE_SYMBOL_EX *psc,
        _EXIT_THREAD_DEBUG_INFO *name,
        int val,
        const char *a6,
        int a7)
{
  char *v8; // ecx
  char v9; // al
  int v10; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  tagWNDCLASSW **v12; // eax
  _IMAGE_SYMBOL_EX *v13; // edx
  unsigned int Short; // edi
  bool v15; // zf
  int sequence; // esi

  v8 = *(char **)name->dwExitCode;
  v9 = *v8;
  if ( *v8 == 0 )
    goto LABEL_7;
  while ( v9 >= 48 && v9 <= 57 )
  {
    v9 = *++v8;
    if ( v9 == 0 )
      goto LABEL_7;
  }
  if ( *v8 == 0 )
  {
LABEL_7:
    v10 = atoi(nptr: *(const char **)name->dwExitCode);
    if ( v10 >= 0 )
    {
      if ( v10 >= a1[1].m_Tail.value.sequence
        || (pNode = a1[1].m_Tail.value.pNode,
            v15 = *((_DWORD *)&pNode->pNext + v10) == 0,
            v12 = (tagWNDCLASSW **)pNode + v10,
            v15) )
      {
        GASValue::DropRefs(this: (GASValue *)val, a2);
        *(_BYTE *)val = 0;
      }
      else
      {
        GASValue::operator=(this: val, v: *v12);
      }
      return;
    }
  }
  v13 = psc;
  Short = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( *(_DWORD *)(name->dwExitCode + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->dwExitCode);
      v13 = psc;
    }
    v15 = *(_DWORD *)(*(_DWORD *)(Short + 632) + 4) == *(_DWORD *)(name->dwExitCode + 4);
  }
  else
  {
    v15 = *(_DWORD *)(Short + 632) == name->dwExitCode;
  }
  if ( !v15 )
  {
LABEL_24:
    GASObject::GetMemberRaw(this: a1, psc: v13, ikey: name, a4: (GASValue *)val);
    return;
  }
  if ( a1[1].m_Tail.value.sequence == 0
    && ((unsigned __int8 (__thiscall *)(CTSQueue<CFunctor *,0,1> *, _IMAGE_SYMBOL_EX *, _EXIT_THREAD_DEBUG_INFO *, _DWORD))a1->m_Head.value.pNode[4].elem)(
         a1,
         a2: v13,
         a3: name,
         a4: 0) != 0 )
  {
    v13 = psc;
    goto LABEL_24;
  }
  sequence = a1[1].m_Tail.value.sequence;
  if ( *(_BYTE *)val >= 5u )
    GASValue::DropRefs(this: (GASValue *)val, a2: val);
  *(_DWORD *)(val + 4) = sequence;
  *(_BYTE *)val = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100A66C0
// Name: public: virtual bool GASArrayObject::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::DeleteMember(
        GASObject *a1@<ecx>,
        _IMAGE_SYMBOL_EX *psc,
        const char ***name,
        const char *a4,
        int a5)
{
  int v6; // eax
  GASValue v7[4]; // [esp+8h] [ebp-10h] BYREF

  if ( (*name)[4] != nullptr && isdigit(c: ***name) != 0 )
  {
    v6 = GASArrayObject::ParseIndex(a1: name);
    if ( v6 >= 0 )
    {
      LOBYTE(v7[0]) = 0;
      GASArrayObject::SetElement(this: (GASArrayObject *)&a1[-2], a2: v6, v: (tagWNDCLASSW *)v7);
      GASValue::~GASValue(this: v7, a2: (int)a1);
    }
  }
  else
  {
    GASObject::DeleteMember(this: a1, name: psc, a3: (_IMAGE_SYMBOL_EX *)name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6740
// Name: public: virtual void GASArrayObject::VisitMembers(class GASStringContext __near *,struct GASObjectInterface::MemberVisitor __near *,unsigned int,class GASObjectInterface const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::VisitMembers(
        GASObject *this,
        struct GASStringContext *psc,
        GMemAddressStub *pvisitor,
        unsigned int visitFlags,
        struct GASObjectInterface *a5)
{
  GASObject *v5; // esi
  unsigned int sequence; // ecx
  unsigned int i; // edi
  CTSQueue<CFunctor *,0,1>::Node_t **v8; // eax
  CTSQueue<CFunctor *,0,1>::Node_t **v9; // esi
  unsigned int v10; // eax
  const char *const *v12; // [esp+0h] [ebp-78h]
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *result[2]; // [esp+Ch] [ebp-6Ch] BYREF
  GASObject *v14; // [esp+14h] [ebp-64h]
  struct GASStringContext *v15; // [esp+18h] [ebp-60h]
  unsigned int n; // [esp+1Ch] [ebp-5Ch]
  unsigned int n1; // [esp+20h] [ebp-58h] BYREF
  _DWORD v18[20]; // [esp+24h] [ebp-54h] BYREF

  v5 = this;
  v14 = this;
  v15 = psc;
  GASObject::VisitMembers(this, a2: psc, a3: (struct GASObjectInterface::MemberVisitor *)pvisitor, a4: visitFlags, a5);
  sequence = v5[5].sequence;
  n = sequence;
  n1 = 8;
  if ( sequence <= 7 )
    n1 = sequence;
  for ( i = 0; i < n1; ++i )
  {
    v8 = &v5[5].pNode->pNext + i;
    if ( *v8 != nullptr )
    {
      (*(void (__thiscall **)(GMemAddressStub *, unsigned int, CTSQueue<CFunctor *,0,1>::Node_t *, _DWORD))(*(_DWORD *)pvisitor + 4))(
        a1: pvisitor,
        a2: *(_DWORD *)v15 + 4 * i + 580,
        a3: *v8,
        a4: 0);
      sequence = n;
    }
  }
  for ( ; i < sequence; ++i )
  {
    if ( *((_DWORD *)&v5[5].pNode->pNext + i) != 0 )
    {
      GLongFormatter::GLongFormatter(a1: (int)v18, v: (const char *const *)i, a3: v12);
      GLongFormatter::Convert(this: (GLongFormatter *)v18);
      GDoubleFormatter::GetResult(this: v18, a2: result);
      v9 = &v5[5].pNode->pNext + i;
      n1 = (unsigned int)GASStringManager::CreateStringNode(
                           this: *(GASStringManager **)(*(_DWORD *)v15 + 636),
                           result: result[0],
                           length: (unsigned int)result[1]);
      ++*(_DWORD *)(n1 + 8);
      (*(void (__thiscall **)(GMemAddressStub *, unsigned int *, CTSQueue<CFunctor *,0,1>::Node_t *, _DWORD))(*(_DWORD *)pvisitor + 4))(
        a1: pvisitor,
        a2: &n1,
        a3: *v9,
        a4: 0);
      v10 = n1;
      if ( (*(_DWORD *)(n1 + 8))-- == 1 )
        GASStringNode::ReleaseNode(a1: v10);
      v18[3] = &GString::InitStruct::`vftable';
      GFormatter::~GFormatter(this: (CMeshReader *)v18);
      v5 = v14;
      sequence = n;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6880
// Name: public: virtual bool GASArrayObject::HasMember(class GASStringContext __near *,class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::HasMember(
        CTSQueue<CFunctor *,0,1> *this,
        _IMAGE_SYMBOL_EX *psc,
        CTSQueue<CFunctor *,0,1>::NodeLink_t *a3,
        bool inclPrototypes)
{
  char *pNext; // ecx
  char v6; // al

  pNext = (char *)a3->value.pNode->pNext;
  v6 = *pNext;
  if ( *pNext == 0 )
    goto LABEL_7;
  while ( v6 >= 48 && v6 <= 57 )
  {
    v6 = *++pNext;
    if ( v6 == 0 )
      goto LABEL_7;
  }
  if ( *pNext == 0 )
  {
LABEL_7:
    if ( atoi(nptr: (const char *)a3->value.pNode->pNext) >= 0 )
      return;
  }
  GASObject::HasMember(this, psc, name: a3, inclPrototypes);
}

//------------------------------------------------------------------------------
// Address: 0x100A6910
// Name: protected: virtual void GASArrayObject::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::ExecuteForEachChild_GC(ISteamUserStats *this, int operation)
{
  switch ( operation )
  {
    case 0:
      GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1:
      GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2:
      GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3:
      GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4:
      GASArrayObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6970
// Name: void GAS_ArrayToString(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArrayToString(int a1@<esi>, const struct GASFnCall *fn)
{
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  int v3; // eax
  ISteamApps *v4; // ebx
  int v5; // edi
  int v6; // esi
  int v7; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v8; // eax
  struct GASStringNode *StringNode; // esi
  int v10; // edi
  bool v11; // zf
  std::bad_exception *sbuffer; // [esp+4h] [ebp-18h] BYREF
  unsigned int length; // [esp+8h] [ebp-14h]

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v3 = *((_DWORD *)fn + 2);
    if ( v3 != 0 )
      v4 = (ISteamApps *)(v3 - 16);
    else
      v4 = nullptr;
    if ( (int)++v4[18].__vftable < 255 )
    {
      GStringBuffer::GStringBuffer(
        this: &sbuffer,
        result: *(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656));
      GASArrayObject::JoinToString(
        this: v4,
        pEnv: *((char ***)fn + 6),
        pbuffer: (const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&sbuffer,
        putf8str: (unsigned int)",");
      v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)sbuffer;
      if ( sbuffer == nullptr )
        v8 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 636),
                     result: v8,
                     length);
      ++*((_DWORD *)StringNode + 2);
      v10 = *((_DWORD *)fn + 1);
      if ( *(_BYTE *)v10 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v10, a2: v10);
      *(_BYTE *)v10 = 5;
      *(_DWORD *)(v10 + 4) = StringNode;
      v11 = ++*((_DWORD *)StringNode + 2) == 1;
      --*((_DWORD *)StringNode + 2);
      if ( v11 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)&sbuffer);
      --v4[18].__vftable;
    }
    else
    {
      GFxLogBase<GFxLog>::LogScriptError(
        this: v2,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&v4[13].BIsVACBanned,
        this_4: (int)"256 levels of recursion is reached\n",
        this_8: a1);
      v5 = *((_DWORD *)fn + 1);
      v6 = *(_DWORD *)(*((_DWORD *)fn + 6) + 120);
      if ( *(_BYTE *)v5 >= 5u )
        GASValue::DropRefs(this: (GASValue *)v5, a2: v5);
      *(_BYTE *)v5 = 5;
      v7 = *(_DWORD *)(v6 + 8);
      *(_DWORD *)(v5 + 4) = v7;
      ++*(_DWORD *)(v7 + 8);
      --v4[18].__vftable;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6A80
// Name: void GAS_ArrayValueOf(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArrayValueOf(int a1@<esi>, const struct GASFnCall *fn)
{
  GAS_ArrayToString(a1, fn);
}

//------------------------------------------------------------------------------
// Address: 0x100A6A90
// Name: public: virtual char const __near * GASArrayObject::GetTextValue(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::GetTextValue(
        int a1@<ecx>,
        int a2@<edi>,
        char **pEnv,
        GMemoryHeap *sbuffer,
        int a5,
        const char *a6,
        int a7)
{
  int v8; // [esp+0h] [ebp-20h]
  std::bad_exception *sbuffera; // [esp+8h] [ebp-18h] BYREF

  if ( (int)++*(_DWORD *)(a1 + 56) < 255 )
  {
    GStringBuffer::GStringBuffer(
      this: &sbuffera,
      result: *((const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> **)pEnv[30]
      + 164));
    GASArrayObject::JoinToString(
      this: (ISteamApps *)(a1 - 16),
      pEnv,
      pbuffer: (const CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&sbuffera,
      putf8str: (unsigned int)",");
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(a1 + 52),
      src: (void (__cdecl **)(int))&sbuffera,
      polddata: a2,
      src_8: v8);
    GStringBuffer::~GStringBuffer(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)&sbuffera);
  }
  else
  {
    GFxLogBase<GFxLog>::LogScriptError(
      this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)a1,
      pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*(_DWORD *)(a1 + 36) + 12),
      this_4: (int)"256 levels of recursion is reached\n",
      this_8: v8);
  }
  --*(_DWORD *)(a1 + 56);
}

//------------------------------------------------------------------------------
// Address: 0x100A6B20
// Name: public: void GASArrayObject::Resize(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::Resize(GRenderer::CachedData *a1@<ecx>, signed int size, GMemoryHeap *a3)
{
  unsigned int v3; // esi
  unsigned int hData; // eax
  unsigned int i; // ebx
  GRenderer *pRenderer; // edx
  void *v7; // edi
  GRenderer::CachedData *v8; // edi
  GRenderer::CachedData *v9; // [esp+8h] [ebp-4h]
  unsigned int oldSize; // [esp+14h] [ebp+8h]

  v3 = size;
  v9 = a1;
  if ( size < 0 )
    v3 = 0;
  hData = (unsigned int)a1[7].hData;
  oldSize = hData;
  for ( i = v3; i < hData; ++i )
  {
    pRenderer = a1[7].pRenderer;
    v7 = *((void **)&pRenderer->__vftable + i);
    if ( v7 != nullptr )
    {
      GASValue::~GASValue(this: *((GASValue **)&pRenderer->__vftable + i), a2: (int)v7);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
      hData = oldSize;
      a1 = v9;
    }
  }
  v8 = a1 + 7;
  if ( (void *)v3 >= a1[7].hData )
  {
    if ( (GRenderer *)v3 < a1[8].pRenderer )
      goto LABEL_13;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v8,
      pheapAddr: v8,
      newCapacity: v3 + (v3 >> 2));
  }
  else
  {
    if ( v3 >= (unsigned int)a1[8].pRenderer >> 1 )
      goto LABEL_13;
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v8,
      pheapAddr: v8,
      newCapacity: v3);
  }
  hData = oldSize;
LABEL_13:
  for ( v8->hData = (void *)v3; hData < v3; ++hData )
    *((_DWORD *)&v8->pRenderer->__vftable + hData) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A6BC0
// Name: public: void GASArrayObject::ShallowCopyFrom(class GASArrayObject const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::ShallowCopyFrom(GASArrayObject *this, const struct GASArrayObject *a2)
{
  unsigned int v3; // edi
  GRenderer::CachedData *v4; // esi
  unsigned int v5; // ecx
  unsigned int i; // eax

  v3 = *((_DWORD *)a2 + 15);
  v4 = (GRenderer::CachedData *)((char *)this + 56);
  if ( v3 >= *((_DWORD *)this + 15) )
  {
    if ( v3 >= *((_DWORD *)this + 16) )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: v4,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < *((_DWORD *)this + 16) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: v4,
      newCapacity: *((_DWORD *)a2 + 15));
  }
  v4->hData = (void *)v3;
  v5 = *((_DWORD *)this + 15);
  for ( i = 0; i < v5; ++i )
    *((_DWORD *)&v4->pRenderer->__vftable + i) = *(_DWORD *)(*((_DWORD *)a2 + 14) + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x100A6C20
// Name: public: void GASArrayObject::MakeDeepCopyFrom(class GMemoryHeap __near *,class GASArrayObject const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::MakeDeepCopyFrom(ISteamApps *this, int pheap, int a3)
{
  unsigned int v3; // esi
  GRenderer::CachedData *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  const ISteamApps *v8; // ebx
  int v9; // esi
  bool (__thiscall *BIsSubscribed)(ISteamApps *); // edx
  GASValue *v11; // eax
  GASValue *v12; // eax
  unsigned int n; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)(a3 + 60);
  v5 = (GRenderer::CachedData *)(this + 14);
  if ( v3 >= *((_DWORD *)this + 15) )
  {
    if ( v3 >= *((_DWORD *)this + 16) )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v5,
        pheapAddr: v5,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < *((_DWORD *)this + 16) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v5,
      pheapAddr: v5,
      newCapacity: *(_DWORD *)(a3 + 60));
  }
  v5->hData = (void *)v3;
  v6 = *((_DWORD *)this + 15);
  v7 = 0;
  i = 0;
  n = v6;
  if ( v6 != 0 )
  {
    v8 = (const ISteamApps *)pheap;
    do
    {
      v9 = 4 * v7;
      if ( *(_DWORD *)(4 * v7 + *(_DWORD *)(a3 + 56)) != 0 )
      {
        BIsSubscribed = v8->__vftable[1].BIsSubscribed;
        pheap = 323;
        v11 = (GASValue *)((int (__thiscall *)(const ISteamApps *, int, int *))BIsSubscribed)(
                            a1: v8,
                            a2: 16,
                            a3: &pheap);
        if ( v11 != nullptr )
          v12 = GASValue::GASValue(this: v11, v: *(tagWNDCLASSW **)(*(_DWORD *)(a3 + 56) + v9));
        else
          v12 = nullptr;
        *(GRenderer_vtbl **)((char *)&v5->pRenderer->__vftable + v9) = (GRenderer_vtbl *)v12;
        v7 = i;
        v6 = n;
      }
      i = ++v7;
    }
    while ( v7 < v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6CD0
// Name: public: void GASArrayObject::DetachAll(void)
// Source: json
//------------------------------------------------------------------------------
GRenderer *__thiscall GASArrayObject::DetachAll(GRenderer::CachedData *this)
{
  GRenderer **v1; // esi
  GRenderer *result; // eax

  v1 = (GRenderer **)(this + 7);
  if ( *((_DWORD *)this + 15) == 0 )
  {
    if ( *((_DWORD *)this + 16) == 0 )
      result = GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                 this: this + 7,
                 pheapAddr: this + 7,
                 newCapacity: 0);
  }
  else if ( (*(_DWORD *)(this + 8) & 0xFFFFFFFE) != 0 )
  {
    result = *v1;
    if ( *v1 != nullptr )
    {
      result = (GRenderer *)((int (__thiscall *)(GMemoryHeap *, GRenderer *))GMemory::pGlobalHeap->Free)(
                              a1: GMemory::pGlobalHeap,
                              a2: *v1);
      *v1 = nullptr;
    }
    v1[2] = nullptr;
    v1[1] = nullptr;
    return result;
  }
  v1[1] = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A6D20
// Name: public: void GASArrayObject::Concat(class GASEnvironment __near *,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::Concat(
        ISteamApps *this@<ecx>,
        GMemoryHeap *a2@<esi>,
        unsigned int penv,
        tagWNDCLASSW *val)
{
  GRenderer::CachedData *v4; // edi
  unsigned int v5; // ebx
  struct GASObject *v6; // eax
  struct GASObject *v7; // esi
  int sequence; // eax
  void *v9; // ebx
  unsigned int v10; // edi
  int v11; // ebx
  int (__thiscall *v12)(unsigned int, int, tagWNDCLASSW **); // edx
  GASValue *v13; // eax
  GASValue *v14; // eax
  int (__thiscall *v15)(unsigned int, int, unsigned int *); // edx
  GASValue *v16; // eax
  GASValue *v17; // ebx
  unsigned int hData; // eax
  GRenderer::CachedData *v19; // esi
  unsigned int v20; // edi
  GRenderer *pRenderer; // ecx
  GASValue **v22; // edi
  const struct GASEnvironment *v23; // [esp-Ch] [ebp-14h]
  int v25; // [esp+0h] [ebp-8h]

  v4 = (GRenderer::CachedData *)this;
  if ( (int)++*((_DWORD *)this + 18) >= 255 )
  {
    GFxLogBase<GFxLog>::LogScriptError(
      (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
      pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*((_DWORD *)this + 13) + 12),
      this_4: (int)"256 levels of recursion is reached\n",
      this_8: v25);
    --v4[9].pRenderer;
    return;
  }
  v5 = *(_DWORD *)(*(_DWORD *)(penv + 120) + 656);
  v23 = (const struct GASEnvironment *)penv;
  penv = v5;
  v6 = GASValue::ToObject(this: (GASValue *)val, a2: (int)this, a3: v23);
  v7 = v6;
  if ( v6 == nullptr || ((int (__thiscall *)(struct GASObject *))v6[2].pNode[1].pNext)(a1: &v6[2]) != 7 )
  {
    v15 = *(int (__thiscall **)(unsigned int, int, unsigned int *))(*(_DWORD *)v5 + 40);
    penv = 323;
    v16 = (GASValue *)v15(a1: v5, a2: 16, a3: &penv);
    if ( v16 != nullptr )
      v17 = GASValue::GASValue(this: v16, v: val);
    else
      v17 = nullptr;
    hData = (unsigned int)v4[7].hData;
    v19 = v4 + 7;
    v20 = hData + 1;
    if ( hData + 1 >= hData )
    {
      if ( (GRenderer *)v20 >= v19[1].pRenderer )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v19,
          pheapAddr: v19,
          newCapacity: v20 + (v20 >> 2));
    }
    else if ( v20 < (unsigned int)v19[1].pRenderer >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v19,
        pheapAddr: v19,
        newCapacity: hData + 1);
    }
    pRenderer = v19->pRenderer;
    v19->hData = (void *)v20;
    v22 = (GASValue **)((char *)pRenderer + 4 * v20 - 4);
    if ( v22 != nullptr )
      *v22 = v17;
    goto LABEL_23;
  }
  sequence = v7[7].sequence;
  if ( sequence == 0 )
  {
LABEL_24:
    --v4[9].pRenderer;
    return;
  }
  v9 = v4[7].hData;
  GASArrayObject::Resize(a1: v4, size: (signed int)v9 + sequence, a3: a2);
  v10 = 0;
  if ( v7[7].sequence == 0 )
  {
LABEL_23:
    v4 = (GRenderer::CachedData *)this;
    goto LABEL_24;
  }
  v11 = 4 * (_DWORD)v9;
  do
  {
    v12 = *(int (__thiscall **)(unsigned int, int, tagWNDCLASSW **))(*(_DWORD *)penv + 40);
    val = (tagWNDCLASSW *)323;
    v13 = (GASValue *)v12(a1: penv, a2: 16, a3: &val);
    if ( v13 != nullptr )
      v14 = GASValue::GASValue(this: v13, v: *((tagWNDCLASSW **)&v7[7].pNode->pNext + v10));
    else
      v14 = nullptr;
    *(_DWORD *)(v11 + *((_DWORD *)this + 14)) = v14;
    ++v10;
    v11 += 4;
  }
  while ( v10 < v7[7].sequence );
  --*((_DWORD *)this + 18);
}

//------------------------------------------------------------------------------
// Address: 0x100A6E80
// Name: public: void GASArrayObject::PushBack(class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::PushBack(GASArrayObject *this, tagWNDCLASSW *val)
{
  GASValue *v3; // eax
  GASValue *v4; // ebx
  GRenderer::CachedData *v5; // edi
  unsigned int v6; // esi
  GASValue **v7; // eax
  int v8; // [esp+8h] [ebp-4h] BYREF

  v8 = 323;
  v3 = (GASValue *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 16, a4: &v8);
  if ( v3 != nullptr )
    v4 = GASValue::GASValue(this: v3, v: val);
  else
    v4 = nullptr;
  v5 = (GRenderer::CachedData *)((char *)this + 56);
  v6 = *((_DWORD *)this + 15) + 1;
  if ( (void *)v6 >= v5->hData )
  {
    if ( (GRenderer *)v6 >= v5[1].pRenderer )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v5,
        pheapAddr: v5,
        newCapacity: v6 + (v6 >> 2));
  }
  else if ( v6 < (unsigned int)v5[1].pRenderer >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v5,
      pheapAddr: v5,
      newCapacity: v6);
  }
  v7 = (GASValue **)((char *)v5->pRenderer + 4 * v6 - 4);
  v5->hData = (void *)v6;
  if ( v7 != nullptr )
    *v7 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A6F00
// Name: public: void GASArrayObject::RemoveElements(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::RemoveElements(ISteamApps *this, int start, int count)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  void *v7; // edi
  int v8; // eax
  int v9; // edx
  unsigned int v10; // edi
  GRenderer::CachedData *v11; // esi
  int i; // [esp+4h] [ebp-4h]

  if ( *((_DWORD *)this + 15) != 0 )
  {
    v4 = count;
    if ( count > 0 )
    {
      v5 = 4 * start;
      for ( i = count; i != 0; --i )
      {
        v6 = *((_DWORD *)this + 14);
        v7 = *(void **)(v5 + v6);
        if ( v7 != nullptr )
        {
          GASValue::~GASValue(this: *(GASValue **)(v5 + v6), a2: (int)v7);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
          v4 = count;
        }
        v5 += 4;
      }
    }
    v8 = v4 + start;
    if ( v4 + start < *((_DWORD *)this + 15) )
    {
      v9 = 4 * start;
      do
      {
        *(_DWORD *)(v9 + *((_DWORD *)this + 14)) = *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v8);
        *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v8++) = 0;
        v9 += 4;
      }
      while ( v8 < *((_DWORD *)this + 15) );
      v4 = count;
    }
    v10 = *((_DWORD *)this + 15) - v4;
    v11 = (GRenderer::CachedData *)(this + 14);
    if ( (void *)v10 >= v11->hData )
    {
      if ( (GRenderer *)v10 >= v11[1].pRenderer )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v11,
          pheapAddr: v11,
          newCapacity: v10 + (v10 >> 2));
    }
    else if ( v10 < (unsigned int)v11[1].pRenderer >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v11,
        pheapAddr: v11,
        newCapacity: v10);
      v11->hData = (void *)v10;
      return;
    }
    v11->hData = (void *)v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6FD0
// Name: public: void GASArrayObject::InsertEmpty(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::InsertEmpty(ISteamApps *this, int start, int count)
{
  int v4; // ecx
  unsigned int v5; // edi
  ISteamApps *v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  unsigned int oldSize; // [esp+Ch] [ebp-4h]

  v4 = count;
  oldSize = *((_DWORD *)this + 15);
  v5 = count + oldSize;
  v6 = this + 14;
  if ( count + oldSize >= oldSize )
  {
    if ( v5 >= *((_DWORD *)this + 16) )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)this + 7,
        pheapAddr: this + 14,
        newCapacity: v5 + (v5 >> 2));
      goto LABEL_6;
    }
  }
  else if ( v5 < *((_DWORD *)this + 16) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: (GRenderer::CachedData *)this + 7,
      pheapAddr: this + 14,
      newCapacity: count + oldSize);
LABEL_6:
    v4 = count;
  }
  *((_DWORD *)this + 15) = v5;
  if ( oldSize != 0 )
  {
    v7 = *((_DWORD *)this + 15) - 1;
    if ( v7 >= v4 + start )
    {
      v8 = 4 * (v7 - v4);
      do
      {
        *((_DWORD *)&v6->BIsSubscribed + v7--) = *(bool (__thiscall **)(ISteamApps *))((char *)&v6->BIsSubscribed + v8);
        v8 -= 4;
      }
      while ( v7 >= v4 + start );
      v4 = count;
    }
  }
  if ( v4 > 0 )
  {
    v9 = 4 * start;
    do
    {
      *(bool (__thiscall **)(ISteamApps *))((char *)&v6->BIsSubscribed + v9) = nullptr;
      v9 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7070
// Name: public: void GASArrayObject::PopFront(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::PopFront(int this)
{
  GASValue *v2; // ebx
  GRenderer::CachedData *v3; // esi
  unsigned int i; // eax
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // edi

  if ( *(_DWORD *)(this + 60) != 0 )
  {
    v2 = **(GASValue ***)(this + 56);
    v3 = (GRenderer::CachedData *)(this + 56);
    if ( v2 != nullptr )
    {
      GASValue::~GASValue(this: v2, a2: this);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
    }
    for ( i = 1; i < *(_DWORD *)(this + 60); *(_DWORD *)(v6 - 4) = v5 )
    {
      v5 = *((_DWORD *)&v3->pRenderer->__vftable + i);
      v6 = (int)v3->pRenderer + 4 * i++;
    }
    *((_DWORD *)v3->pRenderer + *(_DWORD *)(this + 60) - 1) = 0;
    v7 = *(_DWORD *)(this + 60) - 1;
    if ( (void *)v7 >= v3->hData )
    {
      if ( (GRenderer *)v7 >= v3[1].pRenderer )
        GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
          this: v3,
          pheapAddr: v3,
          newCapacity: v7 + (v7 >> 2));
    }
    else if ( v7 < (unsigned int)v3[1].pRenderer >> 1 )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v3,
        pheapAddr: v3,
        newCapacity: v7);
      v3->hData = (void *)v7;
      return;
    }
    v3->hData = (void *)v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7110
// Name: public: void GASArrayObject::SetElementSafe(int,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::SetElementSafe(GRenderer::CachedData *this, int a2, tagWNDCLASSW *v)
{
  int v3; // edi
  _BYTE *v5; // eax
  GMemoryHeap *v6; // [esp+0h] [ebp-8h]

  v3 = a2;
  if ( a2 >= *((_DWORD *)this + 15) )
    GASArrayObject::Resize(a1: this, size: a2 + 1, a3: v6);
  if ( *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v3) == 0 )
  {
    a2 = 323;
    v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 16, a4: &a2);
    if ( v5 != nullptr )
      *v5 = 0;
    else
      v5 = nullptr;
    *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v3) = v5;
  }
  GASValue::operator=(this: *(_DWORD *)(*((_DWORD *)this + 14) + 4 * v3), v);
}

//------------------------------------------------------------------------------
// Address: 0x100A7180
// Name: void GAS_ArrayPop(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArrayPop(GMemoryHeap *a1@<esi>, const struct GASFnCall *fn)
{
  int v2; // eax
  GRenderer::CachedData *v3; // esi
  void *hData; // eax
  tagWNDCLASSW *v5; // eax
  GASValue *v6; // edi
  void *v7; // eax
  GASValue *v8; // esi

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v2 = *((_DWORD *)fn + 2);
    if ( v2 != 0 )
      v3 = (GRenderer::CachedData *)(v2 - 16);
    else
      v3 = nullptr;
    hData = v3[7].hData;
    if ( hData != nullptr )
    {
      v5 = *((tagWNDCLASSW **)v3[7].pRenderer + (_DWORD)hData - 1);
      if ( v5 != nullptr )
      {
        GASValue::operator=(this: *((_DWORD *)fn + 1), v: v5);
      }
      else
      {
        v6 = *((GASValue **)fn + 1);
        GASValue::DropRefs(this: v6, a2: (int)v6);
        *(_BYTE *)v6 = 0;
      }
      v7 = v3[7].hData;
      if ( v7 != nullptr )
        GASArrayObject::Resize(a1: v3, size: (signed int)v7 - 1, a3: a1);
    }
    else
    {
      v8 = *((GASValue **)fn + 1);
      GASValue::DropRefs(this: v8, a2: (int)fn);
      *(_BYTE *)v8 = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7210
// Name: void GAS_ArrayPush(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ArrayPush(const struct GASFnCall *fn)
{
  int v1; // eax
  GASArrayObject *v2; // ebx
  int i; // esi
  tagWNDCLASSW *v4; // eax
  int v5; // edi
  int v6; // ebx

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v1 = *((_DWORD *)fn + 2);
    if ( v1 != 0 )
      v2 = (GASArrayObject *)(v1 - 16);
    else
      v2 = nullptr;
    for ( i = 0; i < *((_DWORD *)fn + 7); ++i )
    {
      v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: i);
      GASArrayObject::PushBack(this: v2, val: v4);
    }
    v5 = *((_DWORD *)fn + 1);
    v6 = *((_DWORD *)v2 + 15);
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: (GASValue *)v5, a2: v5);
    *(_DWORD *)(v5 + 4) = v6;
    *(_BYTE *)v5 = 4;
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7290
// Name: void GAS_ArrayShift(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ArrayShift(const struct GASFnCall *fn)
{
  int v1; // eax
  int v2; // edi
  GASValue *v3; // esi
  GASValue *v4; // esi

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v1 = *((_DWORD *)fn + 2);
    if ( v1 != 0 )
      v2 = v1 - 16;
    else
      v2 = 0;
    if ( *(_DWORD *)(v2 + 60) != 0 )
    {
      if ( **(_DWORD **)(v2 + 56) != 0 )
      {
        GASValue::operator=(this: *((_DWORD *)fn + 1), v: **(tagWNDCLASSW ***)(v2 + 56));
      }
      else
      {
        v4 = *((GASValue **)fn + 1);
        GASValue::DropRefs(this: v4, a2: v2);
        *(_BYTE *)v4 = 0;
      }
      GASArrayObject::PopFront(this: v2);
    }
    else
    {
      v3 = *((GASValue **)fn + 1);
      GASValue::DropRefs(this: v3, a2: v2);
      *(_BYTE *)v3 = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7310
// Name: void GAS_ArrayUnshift(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GAS_ArrayUnshift(const struct GASFnCall *fn)
{
  int v1; // eax
  ISteamApps *v2; // edi
  int i; // esi
  _BYTE *v4; // eax
  int v5; // esi
  int v6; // edi
  tagWNDCLASSW *v; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v1 = *((_DWORD *)fn + 2);
    if ( v1 != 0 )
      v2 = (ISteamApps *)(v1 - 16);
    else
      v2 = nullptr;
    if ( *((int *)fn + 7) > 0 )
    {
      GASArrayObject::InsertEmpty(this: v2, start: 0, count: *((_DWORD *)fn + 7));
      for ( i = 0; i < *((_DWORD *)fn + 7); ++i )
      {
        v = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: i);
        if ( i >= 0 && i < (int)v2[15].__vftable )
        {
          if ( *((_DWORD *)&v2[14].BIsSubscribed + i) == 0 )
          {
            v8 = 323;
            v4 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 16, a4: &v8);
            if ( v4 != nullptr )
              *v4 = 0;
            else
              v4 = nullptr;
            *((_DWORD *)&v2[14].BIsSubscribed + i) = v4;
          }
          GASValue::operator=(this: *((_DWORD *)&v2[14].BIsSubscribed + i), v);
        }
      }
    }
    v5 = *((_DWORD *)fn + 1);
    v6 = (int)v2[15].__vftable;
    if ( *(_BYTE *)v5 >= 5u )
      GASValue::DropRefs(this: *((GASValue **)fn + 1), a2: v6);
    *(_DWORD *)(v5 + 4) = v6;
    *(_BYTE *)v5 = 4;
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A73F0
// Name: public: virtual bool GASArrayObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASArrayObject::SetMember(
        CTSQueue<CFunctor *,0,1> *this@<ecx>,
        long double a2@<st0>,
        int a3,
        int **a4,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v,
        const struct GASPropFlags *a6)
{
  _IMAGE_SYMBOL_EX *v6; // ebx
  int v7; // esi
  int *Short; // eax
  bool v10; // zf
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v11; // esi
  int v12; // eax
  const char *v13; // edx
  _BYTE *v14; // ecx
  char v15; // al
  int v16; // eax
  int v17; // esi
  int v18; // ecx
  int (__thiscall *v19)(int, int, int *); // edx
  _BYTE *v20; // eax
  GMemoryHeap *v21; // [esp+0h] [ebp-Ch]

  v6 = (_IMAGE_SYMBOL_EX *)a4;
  v7 = *(_DWORD *)(a3 + 120);
  if ( *(_BYTE *)(a3 + 124) <= 6u )
  {
    if ( (*a4)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *a4);
    Short = (int *)v6->N.Name.Short;
    v10 = *(_DWORD *)(*(_DWORD *)(v7 + 632) + 4) == *(_DWORD *)(v6->N.Name.Short + 4);
  }
  else
  {
    Short = *a4;
    v10 = *(_DWORD *)(v7 + 632) == (_DWORD)*a4;
  }
  if ( v10 )
  {
    v11 = v;
    v12 = (int)GASValue::ToNumber(this: v, a2: (int)this, a3: a2, result: nullptr);
    GASArrayObject::Resize(a1: (GRenderer::CachedData *)this - 2, size: v12 < 0 ? 0 : v12, a3: v21);
    GASObject::SetMember(this, a2: (GASEnvironment *)a3, name: v6, pval: v11, pmember: (char *)a6);
    return;
  }
  v13 = (const char *)*Short;
  v14 = (_BYTE *)*Short;
  v15 = *(_BYTE *)*Short;
  if ( v15 != 0 )
  {
    while ( v15 >= 48 && v15 <= 57 )
    {
      v15 = *++v14;
      if ( v15 == 0 )
        goto LABEL_14;
    }
    if ( *v14 != 0 )
      goto LABEL_23;
  }
LABEL_14:
  v16 = atoi(nptr: v13);
  v17 = v16;
  if ( v16 < 0 )
  {
LABEL_23:
    GASObject::SetMember(this, a2: (GASEnvironment *)a3, name: v6, pval: v, pmember: (char *)a6);
    return;
  }
  if ( v16 >= *((_DWORD *)this + 11) )
    GASArrayObject::Resize(a1: (GRenderer::CachedData *)this - 2, size: v16 + 1, a3: v21);
  if ( *(_DWORD *)(*((_DWORD *)this + 10) + 4 * v17) == 0 )
  {
    v18 = *(_DWORD *)(*(_DWORD *)(a3 + 120) + 656);
    v19 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v18 + 40);
    a3 = 323;
    v20 = (_BYTE *)v19(a1: v18, a2: 16, &a3);
    if ( v20 != nullptr )
      *v20 = 0;
    else
      v20 = nullptr;
    *(_DWORD *)(*((_DWORD *)this + 10) + 4 * v17) = v20;
  }
  GASValue::operator=(this: *(_DWORD *)(*((_DWORD *)this + 10) + 4 * v17), (tagWNDCLASSW *)v);
}

//------------------------------------------------------------------------------
// Address: 0x100A7580
// Name: public: GASArraySortFunctor::GASArraySortFunctor(class GASObjectInterface __near *,int,class GASFunctionRef const __near &,class GASEnvironment __near *,class GFxLog const __near *)
// Source: json
//------------------------------------------------------------------------------
int *__userpurge GASArraySortFunctor::GASArraySortFunctor@<eax>(
        int *a1@<ecx>,
        int a2@<edi>,
        int flags,
        int a4,
        int *a5,
        int a6,
        const IMaterialSystemHardwareConfig *log)
{
  int v8; // ecx
  int v9; // eax
  tagIMECHARPOSITION *v10; // eax

  a1[1] = a4;
  *a1 = flags;
  v8 = (int)(a1 + 2);
  *(_BYTE *)(v8 + 8) = 0;
  v9 = *a5;
  *(_DWORD *)v8 = *a5;
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 8) = (*(_DWORD *)(v9 + 8) + 1) & 0x8FFFFFFF;
  *(_DWORD *)(v8 + 4) = 0;
  v10 = (tagIMECHARPOSITION *)a5[1];
  if ( v10 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: v8, a2, result: v10, internal: a5[2] & 1);
  a1[5] = a6;
  a1[6] = (int)log;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100A75F0
// Name: public: GASArrayObject::GASArrayObject(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASArrayObject::GASArrayObject@<eax>(
        int a1@<ecx>,
        unsigned int penv,
        GMemoryHeap *a3,
        const char *a4,
        int a5)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject(this: (GASObject *)a1, a2: (struct GASEnvironment *)penv);
  *(_DWORD *)a1 = &GASArrayObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(a1 + 16) = &GASArrayObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(a1 + 52) = GASEnvironment::GetLog(this: (GASEnvironment *)penv);
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(a1 + 68));
  *(_DWORD *)(a1 + 72) = 0;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *(vc_attributes::PreRangeAttribute **)(penv + 120),
                                                    result: (vc_attributes::InvalidCheckAttribute *)2);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(a1 + 16),
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)(penv + 120),
    psc_4: Prototype);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7670
// Name: public: GASArrayObject::GASArrayObject(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASArrayObject::GASArrayObject@<eax>(
        int a1@<ecx>,
        GASGlobalContext **psc,
        GMemAddressStub *psc_4,
        const char *psc_8,
        int psc_12)
{
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  GASObject::GASObject(this: (GASObject *)a1, a2: (int)psc, psc);
  *(_DWORD *)a1 = &GASArrayObject::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(a1 + 16) = &GASArrayObject::`vftable'{for `GASObjectInterface'};
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)(a1 + 68));
  *(_DWORD *)(a1 + 72) = 0;
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: (vc_attributes::PreRangeAttribute *)*psc,
                                                    result: (vc_attributes::InvalidCheckAttribute *)2);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)(a1 + 16),
    (CTSQueue<CFunctor *,0,1>::Node_t *)psc,
    psc_4: Prototype);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100A76D0
// Name: protected: virtual void GASArrayObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArrayObject::Finalize_GC(GASObject *this)
{
  unsigned int v2; // ebx
  unsigned int i; // esi
  GASValue *v4; // ecx
  volatile LONG *v5; // esi

  v2 = *((_DWORD *)this + 15);
  for ( i = 0; i < v2; ++i )
  {
    v4 = *(GASValue **)(*((_DWORD *)this + 14) + 4 * i);
    if ( v4 != nullptr )
      GASValue::Finalize_GC(this: v4, a2: (int)this);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(*((_DWORD *)this + 14) + 4 * i));
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 14));
  v5 = (volatile LONG *)(*((_DWORD *)this + 17) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v5 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v5);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A7750
// Name: void GAS_ArrayConcat(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArrayConcat(int a1@<edi>, const struct GASFnCall *fn)
{
  int v2; // eax
  struct GASObject *v3; // ebx
  ISteamApps *v4; // edi
  int i; // ebx
  tagWNDCLASSW *v6; // eax
  GASValue v7[4]; // [esp+4h] [ebp-10h] BYREF

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v2 = *((_DWORD *)fn + 2);
    if ( v2 != 0 )
      v3 = (struct GASObject *)(v2 - 16);
    else
      v3 = nullptr;
    v4 = (ISteamApps *)GASEnvironment::OperatorNew(
                         this: *((__vc_attributes::idl_quoteAttribute **)fn + 6),
                         a2: a1,
                         a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 680),
                         a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 16),
                         nargs: 0,
                         argsTopOff: -1);
    if ( v4 != nullptr )
    {
      GASValue::GASValue(this: v7, a2: v3);
      GASArrayObject::Concat(this: v4, a2: (GMemoryHeap *)fn, penv: *((_DWORD *)fn + 6), val: (tagWNDCLASSW *)v7);
      GASValue::~GASValue(this: v7, a2: (int)v4);
      for ( i = 0; i < *((_DWORD *)fn + 7); ++i )
      {
        v6 = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: i);
        GASArrayObject::Concat(this: v4, a2: (GMemoryHeap *)fn, penv: *((_DWORD *)fn + 6), val: v6);
      }
    }
    GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: (struct GASObject *)v4);
    if ( v4 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v4, a2: (int)v4);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7810
// Name: void GAS_ArraySlice(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArraySlice(double a1@<st0>, const struct GASFnCall *fn)
{
  const struct GASFnCall *v2; // edi
  int v3; // ebx
  int v4; // esi
  int v5; // ebx
  GASValue *v6; // eax
  GASValue *v7; // eax
  int v8; // eax
  bool v9; // sf
  int v10; // ebx
  struct GASObject *v11; // ebx
  int v12; // ecx
  GRenderer::CachedData *v13; // edi
  unsigned int v14; // esi
  GRenderer *v15; // eax
  _SERVICE_STATUS *v16; // [esp-Ch] [ebp-1Ch]
  _SERVICE_STATUS *v17; // [esp-Ch] [ebp-1Ch]
  int i; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h]
  int end; // [esp+Ch] [ebp-4h]

  v2 = fn;
  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v3 = *((_DWORD *)fn + 2);
    v4 = 0;
    if ( v3 != 0 )
    {
      v5 = v3 - 16;
      v19 = v5;
    }
    else
    {
      v19 = 0;
      v5 = 0;
    }
    end = *(_DWORD *)(v5 + 60);
    if ( *((int *)fn + 7) >= 1 )
    {
      v16 = *((_SERVICE_STATUS **)fn + 6);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      a1 = GASValue::ToNumber(this: v6, a2: (int)fn, a3: a1, result: v16);
      v4 = (int)a1;
      if ( (int)a1 < 0 )
      {
        v4 = *(_DWORD *)(v5 + 60) + (int)a1;
        if ( v4 < 0 )
          v4 = 0;
      }
      if ( v4 > *(_DWORD *)(v5 + 60) )
        v4 = *(_DWORD *)(v5 + 60);
    }
    if ( *((int *)fn + 7) >= 2 )
    {
      v17 = *((_SERVICE_STATUS **)fn + 6);
      v7 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
      v8 = (int)GASValue::ToNumber(this: v7, a2: (int)fn, a3: a1, result: v17);
      end = v8;
      if ( v8 < 0 )
      {
        v9 = *(_DWORD *)(v5 + 60) + v8 < 0;
        v8 += *(_DWORD *)(v5 + 60);
        end = v8;
        if ( v9 )
        {
          end = 0;
          v8 = 0;
        }
      }
      v10 = *(_DWORD *)(v5 + 60);
      if ( v8 > v10 )
        end = v10;
    }
    v11 = GASEnvironment::OperatorNew(
            this: *((__vc_attributes::idl_quoteAttribute **)fn + 6),
            a2: (int)fn,
            a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 680),
            a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 16),
            nargs: 0,
            argsTopOff: -1);
    if ( v11 != nullptr )
    {
      for ( i = v4; i < end; ++i )
      {
        v12 = *(_DWORD *)(v19 + 56);
        if ( *(_DWORD *)(v12 + 4 * i) != 0 )
        {
          GASArrayObject::PushBack(this: (GASArrayObject *)v11, val: *(tagWNDCLASSW **)(v12 + 4 * i));
        }
        else
        {
          v13 = (GRenderer::CachedData *)&v11[7];
          v14 = v11[7].sequence + 1;
          if ( v14 >= v11[7].sequence )
          {
            if ( (CTSQueue<CFunctor *,0,1>::Node_t *)v14 >= v11[8].pNode )
              GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                this: v13,
                pheapAddr: v13,
                newCapacity: v14 + (v14 >> 2));
          }
          else if ( v14 < (unsigned int)v11[8].pNode >> 1 )
          {
            GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
              this: v13,
              pheapAddr: v13,
              newCapacity: v11[7].sequence + 1);
          }
          v15 = (GRenderer *)((char *)v13->pRenderer + 4 * v14 - 4);
          v11[7].sequence = v14;
          v2 = fn;
          if ( v15 != nullptr )
            v15->__vftable = nullptr;
        }
      }
    }
    GASValue::SetAsObject(this: *((GASValue **)v2 + 1), a2: v11);
    if ( v11 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v11, a2: (int)v2);
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7990
// Name: void GAS_ArraySplice(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArraySplice(long double a1@<st0>, const struct GASFnCall *fn)
{
  const struct GASFnCall *v2; // edi
  int v3; // eax
  int v4; // ebx
  GASValue *v5; // esi
  GASValue *v6; // eax
  double v7; // st7
  int v8; // eax
  int v9; // esi
  bool v10; // sf
  int v11; // eax
  int v12; // ebx
  GASValue *v13; // eax
  ISteamApps_vtbl *v14; // eax
  struct GASObject *v15; // ecx
  GRenderer::CachedData *v16; // edi
  unsigned int v17; // esi
  GRenderer *v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // esi
  int v22; // eax
  ISteamApps *v23; // ebx
  _BYTE *v24; // eax
  _SERVICE_STATUS *v25; // [esp-Ch] [ebp-24h]
  _SERVICE_STATUS *v26; // [esp-Ch] [ebp-24h]
  int v27; // [esp+4h] [ebp-14h] BYREF
  struct GASObject *v28; // [esp+8h] [ebp-10h]
  tagWNDCLASSW *v; // [esp+Ch] [ebp-Ch]
  ISteamApps *v30; // [esp+10h] [ebp-8h]
  int start; // [esp+14h] [ebp-4h]

  v2 = fn;
  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v3 = *((_DWORD *)fn + 2);
    if ( v3 != 0 )
    {
      v4 = v3 - 16;
      v30 = (ISteamApps *)(v3 - 16);
    }
    else
    {
      v30 = nullptr;
      v4 = 0;
    }
    if ( *((_DWORD *)fn + 7) != 0 )
    {
      v25 = *((_SERVICE_STATUS **)fn + 6);
      v6 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v7 = GASValue::ToNumber(this: v6, a2: (int)fn, a3: a1, result: v25);
      v8 = (int)v7;
      v9 = (int)v7;
      start = (int)v7;
      if ( (int)v7 < 0 )
      {
        v10 = *(_DWORD *)(v4 + 60) + v8 < 0;
        v9 = *(_DWORD *)(v4 + 60) + v8;
        start = v9;
        if ( v10 )
        {
          start = 0;
          v9 = 0;
        }
      }
      v11 = *(_DWORD *)(v4 + 60);
      if ( v9 > v11 )
      {
        start = *(_DWORD *)(v4 + 60);
        v9 = v11;
      }
      v12 = v11 - v9;
      if ( *((int *)fn + 7) >= 2 )
      {
        v26 = *((_SERVICE_STATUS **)fn + 6);
        v13 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        v12 = (int)GASValue::ToNumber(this: v13, a2: (int)fn, a3: v7, result: v26);
        if ( v12 < 0 )
          v12 = 0;
        v14 = v30[15].__vftable;
        if ( v12 + v9 >= (int)v14 )
          v12 = (int)v14 - v9;
      }
      v15 = GASEnvironment::OperatorNew(
              this: *((__vc_attributes::idl_quoteAttribute **)fn + 6),
              a2: (int)fn,
              a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 680),
              a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 16),
              nargs: 0,
              argsTopOff: -1);
      v28 = v15;
      if ( v15 != nullptr )
      {
        if ( v12 > 0 )
        {
          v = (tagWNDCLASSW *)(4 * v9);
          v27 = v12;
          do
          {
            if ( *(unsigned int *)((char *)&v->style + (unsigned int)v30[14].__vftable) != 0 )
            {
              GASArrayObject::PushBack(
                this: (GASArrayObject *)v15,
                val: *(tagWNDCLASSW **)((char *)&v->style + (unsigned int)v30[14].__vftable));
            }
            else
            {
              v16 = (GRenderer::CachedData *)&v15[7];
              v17 = v15[7].sequence + 1;
              if ( v17 >= v15[7].sequence )
              {
                if ( (CTSQueue<CFunctor *,0,1>::Node_t *)v17 >= v15[8].pNode )
                  GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                    this: v16,
                    pheapAddr: v16,
                    newCapacity: v17 + (v17 >> 2));
              }
              else if ( v17 < (unsigned int)v15[8].pNode >> 1 )
              {
                GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
                  this: v16,
                  pheapAddr: v16,
                  newCapacity: v15[7].sequence + 1);
              }
              v18 = (GRenderer *)((char *)v16->pRenderer + 4 * v17 - 4);
              v16->hData = (void *)v17;
              v2 = fn;
              v9 = start;
              if ( v18 != nullptr )
                v18->__vftable = nullptr;
            }
            v = (tagWNDCLASSW *)((char *)v + 4);
            v19 = v27-- == 1;
            v15 = v28;
          }
          while ( !v19 );
        }
        GASValue::SetAsObject(this: *((GASValue **)v2 + 1), a2: v15);
        if ( v12 != 0 )
          GASArrayObject::RemoveElements(this: v30, start: v9, count: v12);
        v20 = *((_DWORD *)v2 + 7);
        if ( v20 >= 3 )
        {
          GASArrayObject::InsertEmpty(this: v30, start: v9, count: v20 - 2);
          v21 = 2;
          if ( *((int *)v2 + 7) > 2 )
          {
            v2 = (const struct GASFnCall *)(4 * start);
            do
            {
              v = (tagWNDCLASSW *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: v21);
              v22 = start + v21 - 2;
              if ( v22 >= 0 )
              {
                v23 = v30;
                if ( v22 < (int)v30[15].__vftable )
                {
                  if ( *(_DWORD *)((char *)v2 + (unsigned int)v30[14].__vftable) == 0 )
                  {
                    v27 = 323;
                    v24 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v30, a3: 16, a4: &v27);
                    if ( v24 != nullptr )
                      *v24 = 0;
                    else
                      v24 = nullptr;
                    *(_DWORD *)((char *)v2 + (unsigned int)v23[14].__vftable) = v24;
                  }
                  GASValue::operator=(this: *(_DWORD *)((char *)v2 + (unsigned int)v23[14].__vftable), v);
                }
              }
              ++v21;
              v2 = (const struct GASFnCall *)((char *)v2 + 4);
            }
            while ( v21 < *((_DWORD *)fn + 7) );
          }
        }
        GRefCountBaseGC<323>::Release(a1: (int)v28, a2: (int)v2);
      }
    }
    else
    {
      v5 = *((GASValue **)fn + 1);
      GASValue::DropRefs(this: v5, a2: (int)fn);
      *(_BYTE *)v5 = 0;
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7BD0
// Name: public: static void GASArrayCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall GASArrayCtorFunction::GlobalCtor@<al>(long double a1@<st0>, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  int v4; // eax
  GRenderer::CachedData *v5; // edi
  int v6; // ecx
  int (__thiscall *v7)(int, int, _CONNECTDLGSTRUCTW *); // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  GRenderer *pRenderer; // edx
  int v12; // eax
  char v13; // al
  GASValue *v14; // eax
  double v15; // st7
  _SERVICE_STATUS *v17; // [esp-4h] [ebp-1Ch]
  GMemoryHeap *v18; // [esp+0h] [ebp-18h]
  const char *v19; // [esp+4h] [ebp-14h]
  GASValue v20[4]; // [esp+8h] [ebp-10h] BYREF

  cbStructure = fna.cbStructure;
  if ( *(_DWORD *)(fna.cbStructure + 8) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fna.cbStructure + 8) + 8))(a1: *(_DWORD *)(fna.cbStructure + 8)) == 7
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(cbStructure + 8) + 64))(a1: *(_DWORD *)(cbStructure + 8)) == 0 )
  {
    v4 = *(_DWORD *)(cbStructure + 8);
    if ( v4 != 0 )
    {
      v5 = (GRenderer::CachedData *)(v4 - 16);
      if ( v4 != 16 )
        v5[1].pRenderer = (GRenderer *)(((int)&v5[1].pRenderer->__vftable + 1) & 0x8FFFFFFF);
    }
    else
    {
      v5 = nullptr;
    }
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120) + 656);
    v7 = *(int (__thiscall **)(int, int, _CONNECTDLGSTRUCTW *))(*(_DWORD *)v6 + 40);
    fna.cbStructure = 323;
    v8 = v7(a1: v6, a2: 76, a3: &fna);
    if ( v8 != 0 )
      v9 = GASArrayObject::GASArrayObject(
             a1: v8,
             penv: *(_DWORD *)(cbStructure + 24),
             a3: v18,
             a4: v19,
             a5: (int)v20[0]);
    else
      v9 = 0;
    v5 = (GRenderer::CachedData *)v9;
  }
  v10 = *(_DWORD *)(cbStructure + 24);
  pRenderer = v5[2].pRenderer;
  HIBYTE(fna.cbStructure) = 1;
  LOBYTE(v20[0]) = 4;
  v20[1] = nullptr;
  ((void (__thiscall *)(GRenderer::CachedData *, int, int, GASValue *, char *))pRenderer->Handlers.Root.pNext)(
    a1: v5 + 2,
    a2: v10,
    a3: *(_DWORD *)(v10 + 120) + 632,
    a4: v20,
    a5: (char *)&fna.cbStructure + 3);
  GASValue::~GASValue(this: v20, a2: (int)v5);
  v12 = *(_DWORD *)(cbStructure + 28);
  if ( v12 != 0 )
  {
    if ( v12 == 1 && ((v13 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0)) == 3 || v13 == 4) )
    {
      v17 = *(_SERVICE_STATUS **)(cbStructure + 24);
      v14 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)cbStructure, a2: 0);
      v15 = GASValue::ToNumber(this: v14, a2: (int)v5, a3: a1, result: v17);
      GASArrayObject::Resize(a1: v5, size: (int)v15, a3: v18);
    }
    else
    {
      GASArrayObject::InitArray(a1: (int)v5, fn: cbStructure, IndexNumber: v18, fn_8: (int)v19);
    }
  }
  GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: (struct GASObject *)v5);
  return GRefCountBaseGC<323>::Release(a1: (int)v5, a2: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x100A7CF0
// Name: public: static void GASArrayCtorFunction::DeclareArray(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASArrayCtorFunction::DeclareArray(const IMatchEventsSink *fn, _CONNECTDLGSTRUCTW fna)
{
  unsigned int cbStructure; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, _CONNECTDLGSTRUCTW *); // edx
  int v5; // eax
  int v6; // eax
  struct GASObject *v7; // edi
  CFunctor *elem; // edx
  _DWORD *v9; // ebx
  GMemoryHeap *v11; // [esp+0h] [ebp-2Ch]
  const char *v12; // [esp+4h] [ebp-28h]
  int v13; // [esp+8h] [ebp-24h]
  GASValue v14[4]; // [esp+Ch] [ebp-20h] BYREF
  char className[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v16; // [esp+20h] [ebp-Ch]
  char v17; // [esp+24h] [ebp-8h]
  struct GASObject *v18; // [esp+28h] [ebp-4h]

  cbStructure = fna.cbStructure;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fna.cbStructure + 24) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, _CONNECTDLGSTRUCTW *))(*(_DWORD *)v3 + 40);
  fna.cbStructure = 323;
  v5 = v4(a1: v3, a2: 76, a3: &fna);
  if ( v5 != 0 )
    v18 = (struct GASObject *)GASArrayObject::GASArrayObject(
                                a1: v5,
                                penv: *(_DWORD *)(cbStructure + 24),
                                a3: v11,
                                a4: v12,
                                a5: v13);
  else
    v18 = nullptr;
  v6 = *(_DWORD *)(cbStructure + 24);
  v7 = v18;
  elem = v18[2].pNode[1].elem;
  HIBYTE(fna.cbStructure) = 1;
  LOBYTE(v14[0]) = 4;
  v14[1] = nullptr;
  ((void (__thiscall *)(struct GASObject *, int, int, GASValue *, char *))elem)(
    a1: &v18[2],
    a2: v6,
    a3: *(_DWORD *)(v6 + 120) + 632,
    a4: v14,
    a5: (char *)&fna.cbStructure + 3);
  GASValue::~GASValue(this: v14, a2: (int)v7);
  GASEnvironment::GetConstructor(this: *(__vc_attributes::async_uuidAttribute **)(cbStructure + 24), className, a3: 2);
  v9 = (_DWORD *)(*(_DWORD *)(cbStructure + 24) + 120);
  HIBYTE(fna.cbStructure) = 3;
  GASValue::GASValue(this: v14, a2: (int)v7, a3: (const struct GASFunctionRef *)className);
  ((void (__thiscall *)(struct GASObject *, _DWORD *, int, GASValue *, char *))v7[2].pNode[5].pNext)(
    a1: &v7[2],
    a2: v9,
    a3: *v9 + 324,
    a4: v14,
    a5: (char *)&fna.cbStructure + 3);
  GASValue::~GASValue(this: v14, a2: (int)v7);
  if ( *(_DWORD *)(cbStructure + 28) != 0 )
    GASArrayObject::InitArray(a1: (int)v7, fn: cbStructure, IndexNumber: v11, fn_8: (int)v12);
  GASValue::SetAsObject(this: *(GASValue **)(cbStructure + 4), a2: v7);
  if ( (v17 & 2) == 0 && *(_DWORD *)className != 0 )
    GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: (int)v7);
  *(_DWORD *)className = 0;
  if ( (v17 & 1) == 0 && v16 != 0 )
    GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v7);
  v16 = 0;
  return GRefCountBaseGC<323>::Release(a1: (int)v7, a2: (int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x100A7E10
// Name: public: virtual class GASObject __near * GASArrayCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100A8370
// Name: public: GASArraySortFunctor::GASArraySortFunctor(class GASArraySortFunctor const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GASArraySortFunctor::GASArraySortFunctor(_DWORD *this, int __that)
{
  int v3; // ecx
  int v4; // eax
  tagIMECHARPOSITION *v5; // eax

  *this = *(_DWORD *)__that;
  *(this + 1) = *(_DWORD *)(__that + 4);
  v3 = (int)(this + 2);
  *(_BYTE *)(v3 + 8) = 0;
  v4 = *(_DWORD *)(__that + 8);
  *(_DWORD *)v3 = v4;
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  *(_DWORD *)(v3 + 4) = 0;
  v5 = *(tagIMECHARPOSITION **)(__that + 12);
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: v3, a2: (int)this, result: v5, internal: *(_BYTE *)(__that + 16) & 1);
  *(this + 5) = *(_DWORD *)(__that + 20);
  *(this + 6) = *(_DWORD *)(__that + 24);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A83E0
// Name: public: int GASArraySortFunctor::Compare(class GASValue const __near *,class GASValue const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASArraySortFunctor::Compare@<eax>(
        GASArraySortFunctor *this@<ecx>,
        long double a2@<st0>,
        char **a,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **b)
{
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **p_dummy; // ebx
  int v6; // edi
  __vc_attributes::iid_isAttribute *v7; // edi
  GASValue *limited_expression; // edi
  __vc_attributes::iid_isAttribute *v9; // edi
  GASValue *v10; // edi
  _DWORD *v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  int v18; // esi
  bool v20; // zf
  double v21; // st7
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v22; // eax
  double v23; // st7
  bool v24; // bl
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v25; // eax
  int v26; // eax
  char *v27; // ebx
  unsigned int Length; // eax
  int v29; // eax
  const struct GASValue *v30; // ebx
  int v31; // esi
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v32; // eax
  char v33; // [esp-4h] [ebp-64h]
  tagALTTABINFO *fn; // [esp+Ch] [ebp-54h] BYREF
  GASValue *p_retVal; // [esp+10h] [ebp-50h]
  int v36; // [esp+14h] [ebp-4Ch]
  int v37; // [esp+18h] [ebp-48h]
  int v38; // [esp+1Ch] [ebp-44h]
  char v39; // [esp+20h] [ebp-40h]
  _DWORD *v40; // [esp+24h] [ebp-3Ch]
  int v41; // [esp+28h] [ebp-38h]
  int v42; // [esp+2Ch] [ebp-34h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *dummy; // [esp+30h] [ebp-30h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *retVal; // [esp+40h] [ebp-20h] BYREF
  double valA; // [esp+48h] [ebp-18h] BYREF
  double valB; // [esp+50h] [ebp-10h] BYREF
  CUtlMap<char const *,int,unsigned short>::CKeyLess *v47; // [esp+58h] [ebp-8h] BYREF
  bool numericA; // [esp+5Fh] [ebp-1h]

  p_dummy = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)a;
  LOBYTE(dummy) = 0;
  if ( a == nullptr )
  {
    a = (char **)&dummy;
    p_dummy = &dummy;
  }
  if ( b == nullptr )
    b = &dummy;
  v6 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v7 = *((__vc_attributes::iid_isAttribute **)this + 5);
    LOBYTE(retVal) = 0;
    v7[2].limited_expression += 16;
    if ( v7[2].limited_expression >= v7[4].limited_expression )
      GASPagedStack<GASValue,32>::PushPage(this: v7 + 2);
    limited_expression = (GASValue *)v7[2].limited_expression;
    if ( limited_expression != nullptr )
      GASValue::GASValue(this: limited_expression, v: (tagWNDCLASSW *)b);
    v9 = *((__vc_attributes::iid_isAttribute **)this + 5);
    v9[2].limited_expression += 16;
    if ( v9[2].limited_expression >= v9[4].limited_expression )
      GASPagedStack<GASValue,32>::PushPage(this: v9 + 2);
    v10 = (GASValue *)v9[2].limited_expression;
    if ( v10 != nullptr )
      GASValue::GASValue(this: v10, v: (tagWNDCLASSW *)p_dummy);
    v11 = *((_DWORD **)this + 5);
    v12 = ((v11[2] - v11[3]) >> 4) + 32 * v11[7] - 32;
    p_retVal = &retVal;
    v36 = *(_DWORD *)this;
    v37 = 0;
    v38 = 0;
    v13 = *((_DWORD *)this + 3);
    v42 = v12;
    v14 = *((_DWORD *)this + 2);
    v40 = v11;
    v15 = 2;
    fn = (tagALTTABINFO *)&GASFnCall::`vftable';
    v39 = 0;
    v41 = 2;
    (*(void (__thiscall **)(int, tagALTTABINFO **, int, _DWORD))(*(_DWORD *)v14 + 40))(a1: v14, a2: &fn, a3: v13, a4: 0);
    v16 = *((_DWORD *)this + 5);
    do
    {
      GASValue::~GASValue(this: *(GASValue **)(v16 + 8), a2: v16);
      *(_DWORD *)(v16 + 8) -= 16;
      if ( *(_DWORD *)(v16 + 8) < *(_DWORD *)(v16 + 12) )
        GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v16 + 8));
      --v15;
    }
    while ( v15 != 0 );
    if ( p_retVal != nullptr )
    {
      v17 = (int)GASValue::ToNumber(this: p_retVal, a2: 0, a3: a2, result: (_SERVICE_STATUS *)*((_DWORD *)this + 5));
      if ( (*((_BYTE *)this + 4) & 2) != 0 )
        v17 = -v17;
      v18 = v17;
      fn = (tagALTTABINFO *)&GASFnCall::`vftable';
      if ( (v39 & 2) == 0 && v37 != 0 )
        GRefCountBaseGC<323>::Release(a1: v37, a2: 0);
      v37 = 0;
      if ( (v39 & 1) == 0 && v38 != 0 )
        GRefCountBaseGC<323>::Release(a1: v38, a2: 0);
      v38 = 0;
      fn = (tagALTTABINFO *)&GFxLogBase<GFxLoadProcess>::`vftable';
      GASValue::~GASValue(this: &retVal, a2: 0);
      GASValue::~GASValue(this: &dummy, a2: 0);
      return v18;
    }
    else
    {
      fn = (tagALTTABINFO *)&GASFnCall::`vftable';
      if ( (v39 & 2) == 0 && v37 != 0 )
        GRefCountBaseGC<323>::Release(a1: v37, a2: 0);
      v37 = 0;
      if ( (v39 & 1) == 0 && v38 != 0 )
        GRefCountBaseGC<323>::Release(a1: v38, a2: 0);
      v38 = 0;
      fn = (tagALTTABINFO *)&GFxLogBase<GFxLoadProcess>::`vftable';
      GASValue::~GASValue(this: &retVal, a2: 0);
      GASValue::~GASValue(this: &dummy, a2: 0);
      return 0;
    }
  }
  v20 = (*((_BYTE *)this + 4) & 0x10) == 0;
  valA = 0.0;
  valB = 0.0;
  if ( !v20 )
  {
    if ( *(_BYTE *)p_dummy == 3 || *(_BYTE *)p_dummy == 4 )
    {
      v21 = GASValue::ToNumber(this: p_dummy, a2: 0, a3: 0.0, result: (_SERVICE_STATUS *)*((_DWORD *)this + 5));
      valA = v21;
      numericA = true;
    }
    else
    {
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)p_dummy,
        a2: (int *)&v47,
        a3: *((tagRID_DEVICE_INFO_KEYBOARD **)this + 5),
        precision: -1,
        debug: false);
      numericA = GAS_ParseNumber(a1: (char *)v47->m_LessFunc, a2: 0.0, a3: &valA);
      v22 = v47;
      v20 = v47[2].m_LessFunc-- == (bool (__cdecl *)(const char *const *, const char *const *))1;
      if ( v20 )
        GASStringNode::ReleaseNode(a1: (int)v22);
    }
    if ( *(_BYTE *)b == 3 || *(_BYTE *)b == 4 )
    {
      v23 = GASValue::ToNumber(this: b, a2: 0, a3: v21, result: (_SERVICE_STATUS *)*((_DWORD *)this + 5));
      v24 = true;
    }
    else
    {
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)b,
        a2: (int *)&v47,
        a3: *((tagRID_DEVICE_INFO_KEYBOARD **)this + 5),
        precision: -1,
        debug: false);
      v24 = GAS_ParseNumber(a1: (char *)v47->m_LessFunc, a2: v21, a3: &valB);
      v25 = v47;
      v20 = v47[2].m_LessFunc-- == (bool (__cdecl *)(const char *const *, const char *const *))1;
      if ( v20 )
        GASStringNode::ReleaseNode(a1: (int)v25);
      v23 = valB;
    }
    if ( numericA && v24 )
    {
      if ( valA < v23 )
        v6 = -1;
      if ( valA > v23 )
        v6 = 1;
      if ( (*((_BYTE *)this + 4) & 2) != 0 )
        v6 = -v6;
      GASValue::~GASValue(this: &dummy, a2: v6);
      return v6;
    }
    p_dummy = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)a;
  }
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)p_dummy,
    a2: (int *)&v47,
    a3: *((tagRID_DEVICE_INFO_KEYBOARD **)this + 5),
    precision: -1,
    debug: false);
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)b,
    a2: (int *)&a,
    a3: *((tagRID_DEVICE_INFO_KEYBOARD **)this + 5),
    precision: -1,
    debug: false);
  v26 = *((_DWORD *)this + 1);
  if ( (v26 & 0x400) != 0 )
  {
    v27 = *a;
    LOBYTE(b) = (v26 & 1) == 0;
    v33 = (char)b;
    Length = GASString::GetLength(this: (const char ***)&a);
    v29 = GASString::LocaleCompare_CaseCheck(
            this: &v47,
            a2: (bool (__cdecl *)(const char *const *, const char *const *))v27,
            len: Length,
            caseSensitive: v33);
    v30 = (const struct GASValue *)a;
  }
  else if ( (v26 & 1) != 0 )
  {
    v29 = GString::CompareNoCase(a1: (char *)v47->m_LessFunc, a2: *a);
    v30 = (const struct GASValue *)a;
  }
  else
  {
    v30 = (const struct GASValue *)a;
    v29 = G_strcmp(s1: (const char *)v47->m_LessFunc, s2: *a);
  }
  if ( (*((_BYTE *)this + 4) & 2) != 0 )
    v29 = -v29;
  v20 = (*((_DWORD *)v30 + 2))-- == 1;
  v31 = v29;
  if ( v20 )
    GASStringNode::ReleaseNode(a1: (int)v30);
  v32 = v47;
  v20 = v47[2].m_LessFunc-- == (bool (__cdecl *)(const char *const *, const char *const *))1;
  if ( v20 )
    GASStringNode::ReleaseNode(a1: (int)v32);
  GASValue::~GASValue(this: &dummy, a2: -1);
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x100A8770
// Name: public: int GASArraySortOnFunctor::Compare(class GASValue const __near *,class GASValue const __near *)const
// Source: json
//------------------------------------------------------------------------------
_SERVICE_STATUS *__userpurge GASArraySortOnFunctor::Compare@<eax>(
        GASArraySortOnFunctor *this@<ecx>,
        _SERVICE_STATUS *a2@<edi>,
        long double a3@<st0>,
        GASValue *a4,
        GASValue *a5)
{
  unsigned int v5; // ebx
  _SERVICE_STATUS *v7; // eax
  _DWORD *v8; // ecx
  unsigned __int8 (__thiscall *v9)(_SERVICE_STATUS *, int, int, GASValue *); // eax
  int v10; // ebx
  GASValue v12[4]; // [esp+Ch] [ebp-40h] BYREF
  GASValue v13[4]; // [esp+1Ch] [ebp-30h] BYREF
  GASValue v14[4]; // [esp+2Ch] [ebp-20h] BYREF
  _SERVICE_STATUS *v15; // [esp+3Ch] [ebp-10h]
  int v16; // [esp+40h] [ebp-Ch]
  int v17; // [esp+44h] [ebp-8h]
  int v18; // [esp+48h] [ebp-4h]

  v5 = 0;
  LOBYTE(v12[0]) = 0;
  if ( a4 == nullptr )
    a4 = v12;
  if ( a5 == nullptr )
    a5 = v12;
  v17 = *((_DWORD *)this + 2) + 120;
  v16 = 0;
  if ( *((_DWORD *)this + 5) == 0 )
  {
LABEL_14:
    GASValue::~GASValue(this: v12, (int)a2);
    return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    a2 = GASValue::ToObjectInterface(a1: (int)a4, (int)a2, result: *((_SERVICE_STATUS **)this + 2));
    v7 = GASValue::ToObjectInterface(a1: (int)a5, (int)a2, result: *((_SERVICE_STATUS **)this + 2));
    v15 = v7;
    if ( a2 != nullptr && v7 != nullptr )
    {
      v8 = *((_DWORD **)this + 1);
      v9 = *(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, int, int, GASValue *))(a2->dwServiceType + 44);
      LOBYTE(v13[0]) = 0;
      LOBYTE(v14[0]) = 0;
      v10 = *v8 + 4 * v5;
      if ( v9(a1: a2, a2: v17, a3: v10, a4: v13) != 0
        && (*(unsigned __int8 (__thiscall **)(_SERVICE_STATUS *, int, int, GASValue *))(v15->dwServiceType + 44))(
             a1: v15,
             a2: v17,
             a3: v10,
             a4: v14) != 0 )
      {
        a2 = (_SERVICE_STATUS *)GASArraySortFunctor::Compare(
                                  this: (GASArraySortFunctor *)(v18 + *((_DWORD *)this + 4)),
                                  a2: a3,
                                  a: (char **)v13,
                                  b: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)v14);
        if ( a2 != nullptr )
          break;
      }
      GASValue::~GASValue(this: v14, (int)a2);
      GASValue::~GASValue(this: v13, (int)a2);
      v5 = v16;
    }
    v18 += 28;
    v16 = ++v5;
    if ( v5 >= *((_DWORD *)this + 5) )
      goto LABEL_14;
  }
  GASValue::~GASValue(this: v14, (int)a2);
  GASValue::~GASValue(this: v13, (int)a2);
  GASValue::~GASValue(this: v12, (int)a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100A8920
// Name: public: GASArrayCtorFunction::GASArrayCtorFunction(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASArrayCtorFunction *__thiscall GASArrayCtorFunction::GASArrayCtorFunction(
        GASArrayCtorFunction *this,
        _REASON_CONTEXT *func)
{
  int v3; // eax
  char **v4; // ecx
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v5; // edx
  unsigned int Version; // ecx
  int v7; // edi
  int v8; // eax
  GASValue v11[4]; // [esp+8h] [ebp-20h] BYREF
  GASArrayCtorFunction *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+20h] [ebp-8h] BYREF
  char v15; // [esp+27h] [ebp-1h] BYREF

  v12 = this;
  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASArrayCtorFunction::GlobalCtor);
  v3 = 0;
  *(_DWORD *)this = &GASArrayCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  *((_DWORD *)this + 4) = &GASBlurFilterCtorFunction::`vftable'{for `GASObjectInterface'};
  v13 = 0;
  if ( "CASEINSENSITIVE" == nullptr )
    return this;
  v4 = &GASArrayConstTable;
  do
  {
    v11[1] = (GASValue)dword_1029FEDC[v3];
    v5 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)*v4;
    Version = func->Version;
    v15 = 3;
    LOBYTE(v11[0]) = 4;
    v7 = (int)&v5->m_Memory.m_pMemory + 1;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(Version + 636),
                        result: v5,
                        a3: strlen((const char *)v5),
                        a4: 0);
    ++*((_DWORD *)ConstStringNode + 2);
    (*(void (__thiscall **)(char *, _REASON_CONTEXT *, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)this + 4) + 40))(
      a1: (char *)this + 16,
      a2: func,
      a3: &ConstStringNode,
      a4: v11,
      a5: &v15);
    v8 = (int)ConstStringNode;
    if ( (*((_DWORD *)ConstStringNode + 2))-- == 1 )
      GASStringNode::ReleaseNode(a1: v8);
    GASValue::~GASValue(this: v11, a2: v7);
    ++v13;
    v3 = 2 * v13;
    v4 = &(&GASArrayConstTable)[2 * v13];
  }
  while ( *v4 != nullptr );
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x100A9090
// Name: void GAS_ArraySort(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArraySort(double a1@<st0>, const struct GASFnCall *fn)
{
  int v2; // eax
  float x; // edi
  bool v4; // cc
  char v5; // al
  struct GASValue *v6; // eax
  const struct GASFunctionRefBase *v7; // eax
  GASValue *v8; // eax
  GASValue *v9; // eax
  struct GASObject *v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // esi
  bool v14; // zf
  int v15[6]; // [esp-1Ch] [ebp-64h] BYREF
  float v16; // [esp-4h] [ebp-4Ch]
  int v17[2]; // [esp+Ch] [ebp-3Ch] BYREF
  int v18; // [esp+14h] [ebp-34h]
  int v19; // [esp+18h] [ebp-30h]
  char v20; // [esp+1Ch] [ebp-2Ch]
  char v21[4]; // [esp+28h] [ebp-20h] BYREF
  int v22; // [esp+2Ch] [ebp-1Ch]
  char v23; // [esp+30h] [ebp-18h]
  _D3DVECTOR pThis; // [esp+34h] [ebp-14h] BYREF
  int i; // [esp+40h] [ebp-8h]
  int flags; // [esp+44h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    v2 = *((_DWORD *)fn + 2);
    if ( v2 != 0 )
    {
      LODWORD(x) = v2 - 16;
      LODWORD(pThis.x) = v2 - 16;
    }
    else
    {
      pThis.x = 0.0;
      x = 0.0;
    }
    v4 = *((_DWORD *)fn + 7) < 1;
    v23 = 0;
    *(_DWORD *)v21 = 0;
    v22 = 0;
    flags = 0;
    if ( !v4 )
    {
      v5 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      if ( v5 == 8 || v5 == 11 )
      {
        v16 = *((float *)fn + 6);
        v6 = GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
        v7 = (const struct GASFunctionRefBase *)GASValue::ToFunction(
                                                  a1: (int)v6,
                                                  a2: SLODWORD(x),
                                                  a3: (int)&pThis.y,
                                                  a4: SLODWORD(v16));
        GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)v21, orig: v7);
        if ( (i & 2) == 0 && LODWORD(pThis.y) != 0 )
          GRefCountBaseGC<323>::Release(a1: SLODWORD(pThis.y), a2: SLODWORD(x));
        pThis.y = 0.0;
        if ( (i & 1) == 0 && LODWORD(pThis.z) != 0 )
          GRefCountBaseGC<323>::Release(a1: SLODWORD(pThis.z), a2: SLODWORD(x));
      }
      else
      {
        v16 = *((float *)fn + 6);
        v8 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
        a1 = GASValue::ToNumber(this: v8, a2: SLODWORD(x), a3: a1, result: (_SERVICE_STATUS *)LODWORD(v16));
        flags = (int)a1;
      }
      if ( *(_DWORD *)v21 != 0 && *((int *)fn + 7) >= 2 )
      {
        v16 = *((float *)fn + 6);
        v9 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        a1 = GASValue::ToNumber(this: v9, a2: SLODWORD(x), a3: a1, result: (_SERVICE_STATUS *)LODWORD(v16));
        flags = (int)a1;
      }
    }
    v10 = GASEnvironment::OperatorNew(
            this: *((__vc_attributes::idl_quoteAttribute **)fn + 6),
            a2: SLODWORD(x),
            a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 680),
            a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 16),
            nargs: 0,
            argsTopOff: -1);
    v11 = (int)v10;
    if ( v10 != nullptr )
    {
      GASArrayObject::ShallowCopyFrom(this: (GASArrayObject *)v10, a2: (const struct GASArrayObject *)LODWORD(x));
      GASArraySortFunctor::GASArraySortFunctor(
        a1: v17,
        a2: SLODWORD(x),
        flags: v11 + 16,
        a4: flags,
        a5: (int *)v21,
        a6: *((_DWORD *)fn + 6),
        log: *(const IMaterialSystemHardwareConfig **)(LODWORD(x) + 52));
      v12 = *(_DWORD *)(v11 + 60);
      if ( v12 != 0 )
      {
        pThis.z = *(float *)(v11 + 56);
        i = v12;
        GASArraySortFunctor::GASArraySortFunctor(this: v15, __that: (int)v17);
        if ( G_QuickSortSafe<GArrayAdaptor<GASValue *>,GASArraySortFunctor>(
               a1: (int *)&pThis.z,
               a2: v15[0],
               a3: v15[1],
               a4: v15[2],
               result: (tagIMECHARPOSITION *)v15[3],
               a6: v15[4]) == 0 )
          GASEnvironment::LogScriptError(
            this: *((GASEnvironment **)fn + 6),
            a2: "Error at Array.sort: sorting failed, check your sort functor\n");
      }
      if ( (flags & 4) != 0 && (i = 1, *(int *)(v11 + 60) > 1) )
      {
        LODWORD(x) = v11 + 56;
        while ( GASArraySortFunctor::Compare(
                  this: (GASArraySortFunctor *)v17,
                  a2: a1,
                  a: *(char ***)(*(_DWORD *)LODWORD(x) + 4 * i - 4),
                  b: *(CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> ***)(*(_DWORD *)LODWORD(x)
                                                                                               + 4 * i)) != 0 )
        {
          if ( ++i >= *(_DWORD *)(v11 + 60) )
          {
            x = pThis.x;
            goto LABEL_29;
          }
        }
        v13 = *((_DWORD *)fn + 1);
        if ( *(_BYTE *)v13 >= 5u )
          GASValue::DropRefs(this: (GASValue *)v13, a2: SLODWORD(x));
        *(_BYTE *)v13 = 4;
        *(_DWORD *)(v13 + 4) = 0;
        if ( *(_DWORD *)(v11 + 60) != 0 )
        {
          if ( (*(_DWORD *)(v11 + 64) & 0xFFFFFFFE) != 0 )
          {
            if ( *(_DWORD *)LODWORD(x) != 0 )
            {
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)LODWORD(x));
              *(_DWORD *)LODWORD(x) = 0;
            }
            *(_DWORD *)(v11 + 64) = 0;
          }
        }
        else if ( *(_DWORD *)(v11 + 64) == 0 )
        {
          GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
            this: (GRenderer::CachedData *)(v11 + 56),
            pheapAddr: (const void *)(v11 + 56),
            newCapacity: 0);
        }
        v14 = (v20 & 2) == 0;
        *(_DWORD *)(v11 + 60) = 0;
        if ( v14 && v18 != 0 )
          GRefCountBaseGC<323>::Release(a1: v18, a2: SLODWORD(x));
        v18 = 0;
        if ( (v20 & 1) == 0 && v19 != 0 )
          GRefCountBaseGC<323>::Release(a1: v19, a2: SLODWORD(x));
        v19 = 0;
      }
      else
      {
LABEL_29:
        if ( (flags & 8) != 0 )
        {
          GASArrayObject::MakeDeepCopy(
            this: (_DWORD *)v11,
            result: *(const ISteamApps **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656));
          v16 = *(float *)&v11;
        }
        else
        {
          GASArrayObject::ShallowCopyFrom(this: (GASArrayObject *)LODWORD(x), a2: (const struct GASArrayObject *)v11);
          GASArrayObject::DetachAll(this: (GRenderer::CachedData *)v11);
          v16 = x;
        }
        GASValue::SetAsObject(this: *((GASValue **)fn + 1), a2: (struct GASObject *)LODWORD(v16));
        if ( (v20 & 2) == 0 && v18 != 0 )
          GRefCountBaseGC<323>::Release(a1: v18, a2: SLODWORD(x));
        v18 = 0;
        if ( (v20 & 1) == 0 && v19 != 0 )
          GRefCountBaseGC<323>::Release(a1: v19, a2: SLODWORD(x));
      }
      GRefCountBaseGC<323>::Release(a1: v11, a2: SLODWORD(x));
    }
    if ( (v23 & 2) == 0 && *(_DWORD *)v21 != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)v21, a2: SLODWORD(x));
    *(_DWORD *)v21 = 0;
    if ( (v23 & 1) == 0 && v22 != 0 )
      GRefCountBaseGC<323>::Release(a1: v22, a2: SLODWORD(x));
  }
  else
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A96E0
// Name: public: GASArraySortOnFunctor::GASArraySortOnFunctor(class GASObjectInterface __near *,class GArrayCC<class GASString,323,struct GArrayDefaultPolicy> const __near &,class GArray<int,2,struct GArrayDefaultPolicy> const __near &,class GASEnvironment __near *,class GFxLog const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASArraySortOnFunctor::GASArraySortOnFunctor(
        CCallbackBase *this,
        CCallbackBase_vtbl *pThis,
        unsigned int i,
        _DWORD *a4,
        int a5,
        const IMaterialSystemHardwareConfig *log)
{
  CCallbackBase *v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // esi
  int v10; // ecx
  int v11; // eax
  CCallbackBase_vtbl **v12; // esi
  CCallbackBase_vtbl *v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h] BYREF
  int v15; // [esp+18h] [ebp-14h]
  char v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  const IMaterialSystemHardwareConfig *v18; // [esp+24h] [ebp-8h]
  int v19; // [esp+28h] [ebp-4h]
  unsigned int ia; // [esp+38h] [ebp+Ch]
  unsigned int ib; // [esp+38h] [ebp+Ch]

  this->__vftable = pThis;
  *((_DWORD *)this + 3) = log;
  *(_DWORD *)&this->m_nCallbackFlags = i;
  v7 = (CCallbackBase *)((char *)this + 16);
  this->m_iCallback = a5;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v8 = a4[1];
  ia = *((_DWORD *)this + 5);
  GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (IGameEventListener *)this + 4,
    pheapAddr: (ButtonCode_t)((char *)this + 16),
    newSize: v8);
  if ( v8 > ia )
  {
    v9 = v8 - ia;
    v10 = (int)v7->__vftable + 28 * ia;
    if ( v9 != 0 )
    {
      v11 = v10 + 12;
      do
      {
        if ( v10 != 0 )
        {
          *(_BYTE *)(v11 + 4) = 0;
          *(_DWORD *)(v11 - 4) = 0;
          *(_DWORD *)v11 = 0;
        }
        v10 += 28;
        v11 += 28;
        --v9;
      }
      while ( v9 != 0 );
    }
  }
  ib = 0;
  if ( *((_DWORD *)this + 5) != 0 )
  {
    v19 = 0;
    do
    {
      v12 = (CCallbackBase_vtbl **)((char *)v7->__vftable + v19);
      v13 = *(CCallbackBase_vtbl **)(*a4 + 4 * ib);
      v14 = 0;
      v15 = 0;
      v17 = a5;
      v16 = 0;
      v18 = log;
      *v12 = pThis;
      v12[1] = v13;
      GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(v12 + 2), orig: (const struct GASFunctionRefBase *)&v14);
      v12[5] = (CCallbackBase_vtbl *)v17;
      v12[6] = (CCallbackBase_vtbl *)v18;
      if ( (v16 & 2) == 0 && v14 != 0 )
        GRefCountBaseGC<323>::Release(a1: v14, a2: (int)v7);
      v14 = 0;
      if ( (v16 & 1) == 0 && v15 != 0 )
        GRefCountBaseGC<323>::Release(a1: v15, a2: (int)v7);
      v19 += 28;
      ++ib;
    }
    while ( ib < *((_DWORD *)this + 5) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9810
// Name: public: GASArraySortOnFunctor::GASArraySortOnFunctor(class GASArraySortOnFunctor const __near &)
// Source: json
//------------------------------------------------------------------------------
GASArraySortOnFunctor *__thiscall GASArraySortOnFunctor::GASArraySortOnFunctor(GASArraySortOnFunctor *this, const struct GASArraySortOnFunctor *a2)
{
  _DWORD *v3; // esi
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-4h]
  const struct GASArraySortOnFunctor *v7; // [esp+18h] [ebp+8h]

  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  v3 = (_DWORD *)((char *)this + 16);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  v4 = *((_DWORD *)a2 + 5);
  v7 = *((const struct GASArraySortOnFunctor **)a2 + 4);
  if ( v4 != 0 )
  {
    v6 = *((_DWORD *)this + 5);
    GArrayDataBase<GASArraySortFunctor,GAllocatorGH<GASArraySortFunctor,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (IGameEventListener *)this + 4,
      pheapAddr: (ButtonCode_t)((char *)this + 16),
      newSize: v4 + v6);
    GConstructorMov<GASArraySortFunctor>::ConstructArray(a1: *v3 + 28 * v6, a2: v4, a3: (int)v7);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9890
// Name: public: void GASGlobalContext::SetPrototype(enum GASBuiltinType,class GPtr<class GASObject>)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASGlobalContext::SetPrototype@<al>(GArrayDefaultPolicy *a1@<ecx>, int a2@<edi>, char a3, int a4)
{
  GArrayDefaultPolicy *v4; // ecx
  int v5; // edx
  int i; // eax
  int v7; // esi
  char result; // al
  int *v9[2]; // [esp+4h] [ebp-8h] BYREF
  _UNKNOWN *retaddr; // [esp+10h] [ebp+4h]

  v9[0] = (int *)&a3;
  v9[1] = &a4;
  v4 = a1 + 160;
  v5 = 5381;
  for ( i = 4; i != 0; --i )
  {
    v7 = *((unsigned __int8 *)&retaddr + i + 3);
    v5 = v7 + 65599 * v5;
  }
  result = GHashSetBase<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeAltHashF,GAllocatorLH<enum GASBuiltinType,2>,GHashsetNodeEntry<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>,GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeHashF>>::add<GHashNode<enum GASBuiltinType,GPtr<GASObject>,GFixedSizeHash<enum GASBuiltinType>>::NodeRef>(
             this: v4,
             result: (LeaderboardEntry_t *)v4,
             a3: v9,
             blankIndex: v5);
  if ( a4 != 0 )
    return GRefCountBaseGC<323>::Release(a1: a4, a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A98F0
// Name: public: static class GASFunctionRef GASArrayCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASArrayCtorFunction::Register(struct GASFunctionRef *a1, _KCRM_MARSHAL_HEADER *pgc)
{
  vc_attributes::PreRangeAttribute *v2; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v4)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASArrayCtorFunction *v5; // eax
  GASArrayCtorFunction *v6; // eax
  struct GASFunctionRef *v7; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v9)(const char *, int, struct GASFunctionRef **); // edx
  GASPrototypeBase *v10; // esi
  IDirect3DDevice9 **Prototype; // eax
  GASValue *v12; // eax
  int p_MinVal; // edi
  GASValue v15[4]; // [esp+Ch] [ebp-20h] BYREF
  IDirect3DVertexShader9 v16; // [esp+1Ch] [ebp-10h] BYREF
  char v17; // [esp+20h] [ebp-Ch]
  void (__thiscall **v18)(_DWORD *, IDirect3DVertexShader9 *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v19; // [esp+28h] [ebp-4h]

  v2 = (vc_attributes::PreRangeAttribute *)pgc;
  VersionMajor = pgc[41].VersionMajor;
  v16.__vftable = (IDirect3DVertexShader9_vtbl *)pgc;
  v17 = 8;
  v4 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgc = (_KCRM_MARSHAL_HEADER *)323;
  v5 = (GASArrayCtorFunction *)v4(a1: VersionMajor, a2: 56, a3: &pgc);
  if ( v5 != nullptr )
    v6 = GASArrayCtorFunction::GASArrayCtorFunction(this: v5, func: (_REASON_CONTEXT *)&v16);
  else
    v6 = nullptr;
  v7 = a1;
  *(_DWORD *)a1 = v6;
  *((_BYTE *)v7 + 8) = 0;
  *((_DWORD *)v7 + 1) = 0;
  MaxVal = v2[54].MaxVal;
  v9 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a1 = (struct GASFunctionRef *)323;
  v10 = (GASPrototypeBase *)v9(a1: MaxVal, a2: 108, a3: &a1);
  if ( v10 != nullptr )
  {
    Prototype = (IDirect3DDevice9 **)GASGlobalContext::GetPrototype(
                                       this: v2,
                                       result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASArrayObject,GASEnvironment>::GASPrototype<GASArrayObject,GASEnvironment>(
      this: &v16,
      psc: Prototype,
      psc_8: (unsigned int)v7);
    v10->__vftable = (IUnknown_vtbl *)&GASArrayProto::`vftable'{for `GASRefCountBase<GASObject>'};
    v10[4].__vftable = (IUnknown_vtbl *)&GASArrayProto::`vftable'{for `GASObjectInterface'};
    v10[19].__vftable = (IUnknown_vtbl *)&GASArrayProto::`vftable';
    HIBYTE(pgc) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: v10 + 19,
      a2: (int)v10,
      flags: (vc_attributes::PreRangeAttribute **)&v16,
      flags_4: (const struct GASNameFunction *)&GASArrayFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgc + 3));
  }
  else
  {
    v10 = nullptr;
  }
  if ( v10 != nullptr )
    v10[2].__vftable = (IUnknown_vtbl *)(((int)&v10[2].QueryInterface + 1) & 0x8FFFFFFF);
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: (int)v2, a3: 2, a4: (int)v10);
  v19 = v2[56].MaxVal + 16;
  HIBYTE(pgc) = 0;
  v18 = (void (__thiscall **)(_DWORD *, IDirect3DVertexShader9 *, int, GASValue *, char *))(*v19 + 40);
  v12 = GASValue::GASValue(this: v15, a2: (int)v2, a3: v7);
  p_MinVal = (int)&v2[1].MinVal;
  (*v18)(a1: v19, a2: &v16, a3: p_MinVal, a4: v12, a5: (char *)&pgc + 3);
  GASValue::~GASValue(this: v15, a2: p_MinVal);
  if ( v10 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v10, a2: p_MinVal);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100A9A20
// Name: void GAS_ArraySortOn(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GAS_ArraySortOn(double a1@<st0>, const struct GASFnCall *fn)
{
  int v2; // eax
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  _DWORD *v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  GASValue *v9; // ebx
  int v10; // eax
  GASValue *v11; // eax
  struct GASObject *v12; // eax
  struct GASObject *v13; // esi
  bool v14; // cc
  unsigned __int8 *v15; // ecx
  tagRID_DEVICE_INFO_KEYBOARD *v16; // edx
  int *v17; // esi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  bool v22; // zf
  int v23; // eax
  tagRID_DEVICE_INFO_KEYBOARD *v24; // esi
  unsigned __int8 *v25; // eax
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // esi
  _DWORD *v30; // esi
  GASValue *v31; // eax
  struct GASObject *v32; // eax
  struct GASObject *v33; // eax
  int j; // esi
  GASValue *v35; // ecx
  GASValue *v36; // eax
  int v37; // eax
  _DWORD *v38; // ecx
  struct GASObject *v39; // ebx
  unsigned int sequence; // edi
  void **p_pNode; // esi
  unsigned int v42; // ecx
  unsigned int k; // eax
  unsigned int v44; // eax
  GASValue *v45; // ecx
  int v46; // esi
  int v47; // edx
  void *v48; // esi
  int v49; // ecx
  int v50; // ecx
  int v51; // eax
  int v52; // esi
  int v53; // ebx
  int v54; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v55; // eax
  struct GASObject *v56; // edx
  unsigned int v57; // eax
  _SERVICE_STATUS *v58; // ecx
  void *v59; // esi
  int v60; // ecx
  int v61; // ecx
  int v62; // eax
  int v63; // ebx
  int v64; // esi
  int v65; // ecx
  _DWORD v66[5]; // [esp-1Ch] [ebp-98h] BYREF
  void **v67; // [esp-8h] [ebp-84h]
  _SERVICE_STATUS *v68; // [esp-4h] [ebp-80h]
  _BYTE v69[16]; // [esp+Ch] [ebp-70h] BYREF
  void *v70; // [esp+1Ch] [ebp-60h]
  int v71; // [esp+20h] [ebp-5Ch]
  CCallbackBase v72; // [esp+28h] [ebp-54h] BYREF
  void *v73; // [esp+38h] [ebp-44h]
  int v74; // [esp+3Ch] [ebp-40h]
  _DWORD *v75; // [esp+44h] [ebp-38h] BYREF
  unsigned int v76; // [esp+48h] [ebp-34h]
  unsigned int v77; // [esp+4Ch] [ebp-30h]
  int v78; // [esp+50h] [ebp-2Ch] BYREF
  void *v79; // [esp+54h] [ebp-28h] BYREF
  struct GASObject *v80; // [esp+58h] [ebp-24h]
  int v81; // [esp+5Ch] [ebp-20h] BYREF
  int v82; // [esp+60h] [ebp-1Ch]
  int v83; // [esp+64h] [ebp-18h] BYREF
  _DWORD *v84; // [esp+68h] [ebp-14h]
  int commonFlags; // [esp+6Ch] [ebp-10h]
  int i; // [esp+70h] [ebp-Ch]
  struct GASObject *v87; // [esp+74h] [ebp-8h]
  int v88; // [esp+78h] [ebp-4h]

  v88 = 0;
  if ( !GASFnCall::CheckThisPtr(this: fn, type: 7u) )
  {
    GASFnCall::ThisPtrError(this: (GASFnCall *)fn, a2: "Array", a3: nullptr, a4: 0);
    return;
  }
  v2 = *((_DWORD *)fn + 2);
  if ( v2 != 0 )
    v87 = (struct GASObject *)(v2 - 16);
  else
    v87 = nullptr;
  v3 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v78 = 323;
  v5 = (_DWORD *)v4(a1: v3, a2: 16, a3: &v78);
  if ( v5 != nullptr )
  {
    v6 = *(_DWORD *)(*((_DWORD *)fn + 6) + 120);
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v7 = *(_DWORD *)(v6 + 8);
    v5[3] = v7;
    ++*(_DWORD *)(v7 + 8);
    v8 = (int)v5;
    v84 = v5;
  }
  else
  {
    v8 = 0;
    v84 = nullptr;
  }
  v75 = nullptr;
  v76 = 0;
  v77 = 0;
  commonFlags = 0;
  if ( *((_DWORD *)fn + 7) != 0 )
  {
    v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 200);
    ++*(_DWORD *)(v10 + 8);
    v82 = v10;
    if ( *((int *)fn + 7) >= 1 )
    {
      v68 = *((_SERVICE_STATUS **)fn + 6);
      v11 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
      v12 = GASValue::ToObject(this: v11, a2: v8, a3: (const struct GASEnvironment *)v68);
      v13 = v12;
      v80 = v12;
      if ( v12 != nullptr && ((int (__thiscall *)(struct GASObject *))v12[2].pNode[1].pNext)(a1: &v12[2]) == 7 )
      {
        v14 = v13[7].sequence <= 0;
        i = 0;
        if ( !v14 )
        {
          do
          {
            v15 = *((unsigned __int8 **)&v80[7].pNode->pNext + i);
            if ( v15 != nullptr )
            {
              v16 = *((tagRID_DEVICE_INFO_KEYBOARD **)fn + 6);
              v88 |= 1u;
              GASValue::ToStringImpl(this: v15, a2: &v81, a3: v16, precision: -1, debug: false);
              v17 = &v81;
            }
            else
            {
              v18 = v82;
              v88 |= 2u;
              ++*(_DWORD *)(v82 + 8);
              v83 = v18;
              v17 = &v83;
            }
            GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
              this: (GStatBag *)v8,
              pheapAddr: (const void *)v8,
              newSize: *(_DWORD *)(v8 + 4) + 1);
            v19 = *(_DWORD *)(v8 + 4);
            if ( *(_DWORD *)v8 + 4 * v19 != 4 )
            {
              v20 = *v17;
              *(_DWORD *)(*(_DWORD *)v8 + 4 * v19 - 4) = *v17;
              ++*(_DWORD *)(v20 + 8);
            }
            if ( (v88 & 2) != 0 )
            {
              v21 = v83;
              v88 &= ~2u;
              v22 = (*(_DWORD *)(v83 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v21);
            }
            if ( (v88 & 1) != 0 )
            {
              v23 = v81;
              v88 &= ~1u;
              v22 = (*(_DWORD *)(v81 + 8))-- == 1;
              if ( v22 )
                GASStringNode::ReleaseNode(a1: v23);
            }
            ++i;
          }
          while ( i < v80[7].sequence );
        }
      }
      else
      {
        v24 = *((tagRID_DEVICE_INFO_KEYBOARD **)fn + 6);
        v25 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 0);
        GASValue::ToStringImpl(this: v25, a2: &v83, a3: v24, precision: -1, debug: false);
        GArrayDataBase<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: (GStatBag *)v8,
          pheapAddr: (const void *)v8,
          newSize: *(_DWORD *)(v8 + 4) + 1);
        v26 = *(_DWORD *)(v8 + 4);
        if ( *(_DWORD *)v8 + 4 * v26 != 4 )
        {
          *(_DWORD *)(*(_DWORD *)v8 + 4 * v26 - 4) = v83;
          ++*(_DWORD *)(v83 + 8);
        }
        v27 = v83;
        v22 = (*(_DWORD *)(v83 + 8))-- == 1;
        if ( v22 )
          GASStringNode::ReleaseNode(a1: v27);
      }
    }
    v14 = *(_DWORD *)(v8 + 4) <= 0;
    i = 0;
    if ( !v14 )
    {
      v28 = v76;
      do
      {
        v29 = v28 + 1;
        if ( v28 + 1 >= v28 )
        {
          if ( v29 >= v77 )
          {
            v68 = (_SERVICE_STATUS *)(v29 + (v29 >> 2));
            v67 = (void **)&v75;
            goto LABEL_40;
          }
        }
        else if ( v29 < v77 >> 1 )
        {
          v68 = (_SERVICE_STATUS *)(v28 + 1);
          v67 = (void **)&v75;
LABEL_40:
          GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
            this: (CVertexBuilder *)&v75,
            pheapAddr: (ButtonCode_t)v67,
            newCapacity: (unsigned int)v68);
        }
        v28 = v29;
        v30 = &v75[v29 - 1];
        v76 = v28;
        if ( v30 != nullptr )
          *v30 = 0;
        ++i;
      }
      while ( i < *(_DWORD *)(v8 + 4) );
    }
    if ( *((int *)fn + 7) >= 2 )
    {
      v68 = *((_SERVICE_STATUS **)fn + 6);
      v31 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
      v32 = GASValue::ToObject(this: v31, a2: v8, a3: (const struct GASEnvironment *)v68);
      v80 = v32;
      if ( v32 != nullptr && ((int (__thiscall *)(struct GASObject *))v32[2].pNode[1].pNext)(a1: &v32[2]) == 7 )
      {
        v33 = v80;
        for ( j = 0; j < v33[7].sequence; ++j )
        {
          if ( j >= *(_DWORD *)(v8 + 4) )
            break;
          v35 = *((GASValue **)&v33[7].pNode->pNext + j);
          if ( v35 != nullptr )
          {
            a1 = GASValue::ToNumber(this: v35, a2: v8, a3: a1, result: (_SERVICE_STATUS *)*((_DWORD *)fn + 6));
            v75[j] = (int)a1;
            v33 = v80;
          }
        }
      }
      else
      {
        v68 = *((_SERVICE_STATUS **)fn + 6);
        v36 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)fn, a2: 1);
        a1 = GASValue::ToNumber(this: v36, a2: v8, a3: a1, result: v68);
        commonFlags = (int)a1;
        v37 = 0;
        if ( *(int *)(v8 + 4) > 0 )
        {
          v38 = v75;
          do
            v38[v37++] = commonFlags;
          while ( v37 < *(_DWORD *)(v8 + 4) );
        }
      }
    }
    v39 = GASEnvironment::OperatorNew(
            this: *((__vc_attributes::idl_quoteAttribute **)fn + 6),
            a2: v8,
            a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 680),
            a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 16),
            nargs: 0,
            argsTopOff: -1);
    if ( v39 == nullptr )
      goto LABEL_102;
    sequence = v87[7].sequence;
    p_pNode = (void **)&v39[7].pNode;
    if ( sequence >= v39[7].sequence )
    {
      if ( (CTSQueue<CFunctor *,0,1>::Node_t *)sequence < v39[8].pNode )
        goto LABEL_63;
      v68 = (_SERVICE_STATUS *)(sequence + (sequence >> 2));
    }
    else
    {
      if ( sequence >= (unsigned int)v39[8].pNode >> 1 )
        goto LABEL_63;
      v68 = (_SERVICE_STATUS *)v87[7].sequence;
    }
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: (GRenderer::CachedData *)&v39[7],
      pheapAddr: &v39[7],
      newCapacity: (unsigned int)v68);
LABEL_63:
    v39[7].sequence = sequence;
    v42 = v39[7].sequence;
    for ( k = 0; k < v42; ++k )
    {
      sequence = (unsigned int)*p_pNode;
      *((_DWORD *)*p_pNode + k) = *((_DWORD *)&v87[7].pNode->pNext + k);
    }
    GASArraySortOnFunctor::GASArraySortOnFunctor(
      this: &v72,
      pThis: (CCallbackBase_vtbl *)&v39[2],
      i: (unsigned int)v84,
      a4: &v75,
      a5: *((_DWORD *)fn + 6),
      log: (const IMaterialSystemHardwareConfig *)v87[6].sequence);
    v44 = v39[7].sequence;
    if ( v44 != 0 )
    {
      v79 = *p_pNode;
      sequence = v44;
      v80 = (struct GASObject *)v44;
      GASArraySortOnFunctor::GASArraySortOnFunctor(
        this: (GASArraySortOnFunctor *)v69,
        a2: (const struct GASArraySortOnFunctor *)&v72);
      GASArraySortOnFunctor::GASArraySortOnFunctor(
        this: (GASArraySortOnFunctor *)v66,
        a2: (const struct GASArraySortOnFunctor *)v69);
      G_QuickSortSlicedSafe<GArrayAdaptor<GASValue *>,GASArraySortOnFunctor>(
        a1: &v79,
        a2: 0,
        a3: sequence,
        a4: v66[0],
        a5: v66[1],
        a6: v66[2],
        a7: v66[3],
        a8: v66[4],
        a9: v67);
      GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)v70, a2: v71);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v70);
    }
    if ( (commonFlags & 4) != 0 )
    {
      sequence = 1;
      if ( v39[7].sequence > 1 )
      {
        while ( GASArraySortOnFunctor::Compare(
                  this: (GASArraySortOnFunctor *)&v72,
                  a2: (_SERVICE_STATUS *)sequence,
                  a3: a1,
                  a4: *((GASValue **)*p_pNode + sequence - 1),
                  a5: *((GASValue **)*p_pNode + sequence)) != nullptr )
        {
          if ( (signed int)++sequence >= v39[7].sequence )
            goto LABEL_71;
        }
        v46 = *((_DWORD *)fn + 1);
        if ( *(_BYTE *)v46 >= 5u )
          GASValue::DropRefs(this: *((GASValue **)fn + 1), a2: sequence);
        v47 = v74;
        *(_BYTE *)v46 = 4;
        *(_DWORD *)(v46 + 4) = 0;
        v48 = v73;
        GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)v73, a2: v47);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v48);
        GRefCountBaseGC<323>::Release(a1: (int)v39, a2: sequence);
        v49 = v82;
        v22 = (*(_DWORD *)(v82 + 8))-- == 1;
        if ( v22 )
          GASStringNode::ReleaseNode(a1: v49);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v75);
        v8 = (int)v84;
        v50 = v84[3];
        v22 = (*(_DWORD *)(v50 + 8))-- == 1;
        if ( v22 )
          GASStringNode::ReleaseNode(a1: v50);
        v51 = *(_DWORD *)(v8 + 4);
        v52 = *(_DWORD *)v8 + 4 * v51 - 4;
        if ( v51 != 0 )
        {
          v53 = *(_DWORD *)(v8 + 4);
          do
          {
            v54 = *(_DWORD *)v52;
            v22 = (*(_DWORD *)(*(_DWORD *)v52 + 8))-- == 1;
            if ( v22 )
              GASStringNode::ReleaseNode(a1: v54);
            v52 -= 4;
            --v53;
          }
          while ( v53 != 0 );
        }
        goto LABEL_111;
      }
    }
LABEL_71:
    if ( (commonFlags & 8) != 0 )
    {
      GASArrayObject::MakeDeepCopy(
        this: v39,
        result: *(const ISteamApps **)(*(_DWORD *)(*((_DWORD *)fn + 6) + 120) + 656));
      v45 = *((GASValue **)fn + 1);
      v68 = (_SERVICE_STATUS *)v39;
LABEL_101:
      GASValue::SetAsObject(this: v45, a2: (struct GASObject *)v68);
      v59 = v73;
      GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)v73, a2: v74);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v59);
      GRefCountBaseGC<323>::Release(a1: (int)v39, a2: sequence);
      v8 = (int)v84;
LABEL_102:
      v60 = v82;
      v22 = (*(_DWORD *)(v82 + 8))-- == 1;
      if ( v22 )
        GASStringNode::ReleaseNode(a1: v60);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v75);
      v61 = *(_DWORD *)(v8 + 12);
      v22 = (*(_DWORD *)(v61 + 8))-- == 1;
      if ( v22 )
        GASStringNode::ReleaseNode(a1: v61);
      v62 = *(_DWORD *)(v8 + 4);
      v63 = *(_DWORD *)v8 + 4 * v62 - 4;
      if ( v62 != 0 )
      {
        v64 = *(_DWORD *)(v8 + 4);
        do
        {
          v65 = *(_DWORD *)v63;
          v22 = (*(_DWORD *)(*(_DWORD *)v63 + 8))-- == 1;
          if ( v22 )
            GASStringNode::ReleaseNode(a1: v65);
          v63 -= 4;
          --v64;
        }
        while ( v64 != 0 );
      }
LABEL_111:
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v8);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v8);
      return;
    }
    v55 = (CTSQueue<CFunctor *,0,1>::Node_t *)v39[7].sequence;
    sequence = (unsigned int)&v87[7];
    commonFlags = (int)v55;
    if ( (unsigned int)v55 >= v87[7].sequence )
    {
      if ( v55 >= v87[8].pNode )
      {
        v68 = (_SERVICE_STATUS *)(commonFlags + ((unsigned int)commonFlags >> 2));
        goto LABEL_90;
      }
    }
    else if ( (unsigned int)v55 < (unsigned int)v87[8].pNode >> 1 )
    {
      v68 = (_SERVICE_STATUS *)v55;
LABEL_90:
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)&v87[7],
        pheapAddr: &v87[7],
        newCapacity: (unsigned int)v68);
      v55 = (CTSQueue<CFunctor *,0,1>::Node_t *)commonFlags;
    }
    v56 = v87;
    *(_DWORD *)(sequence + 4) = v55;
    v57 = 0;
    v80 = (struct GASObject *)v56[7].sequence;
    if ( v80 != nullptr )
    {
      do
      {
        *(_DWORD *)(*(_DWORD *)sequence + 4 * v57) = *((_DWORD *)*p_pNode + v57);
        ++v57;
      }
      while ( v57 < (unsigned int)v80 );
    }
    if ( v39[7].sequence != 0 )
    {
      if ( ((int)v39[8].pNode & 0xFFFFFFFE) != 0 )
      {
        if ( *p_pNode != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_pNode);
          *p_pNode = nullptr;
        }
        v39[8].pNode = nullptr;
      }
    }
    else if ( v39[8].pNode == nullptr )
    {
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: (GRenderer::CachedData *)&v39[7],
        pheapAddr: &v39[7],
        newCapacity: 0);
    }
    v58 = (_SERVICE_STATUS *)v87;
    v39[7].sequence = 0;
    v68 = v58;
    v45 = *((GASValue **)fn + 1);
    goto LABEL_101;
  }
  v9 = *((GASValue **)fn + 1);
  GASValue::DropRefs(this: v9, a2: v8);
  *(_BYTE *)v9 = 0;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
  if ( v8 != 0 )
  {
    GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>::~GArrayDataCC<GASString,GAllocatorLH<GASString,323>,GArrayDefaultPolicy>(this: (_DWORD *)v8);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9390
// Name: bool G_QuickSortSlicedSafe<class GArrayAdaptor<class GASValue __near *>,class GASArraySortOnFunctor>(class GArrayAdaptor<class GASValue __near *> __near &,unsigned int,unsigned int,class GASArraySortOnFunctor)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall G_QuickSortSlicedSafe<GArrayAdaptor<GASValue *>,GASArraySortOnFunctor>@<al>(
        long double a1@<st0>,
        int *a2,
        _SERVICE_STATUS *a3,
        int a4,
        char a5,
        int a6,
        int a7,
        int a8,
        void *a9,
        int a10)
{
  int v10; // ebx
  _BYTE *v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  _DWORD *v16; // eax
  GASValue *v17; // ecx
  int v18; // edi
  int v19; // ebx
  long double v20; // st7
  int v21; // eax
  int v22; // edx
  long double v23; // st7
  int v24; // eax
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int *v31; // ecx
  int *v32; // eax
  int v33; // edx
  int v34; // edi
  _DWORD *v35; // eax
  int v36; // ecx
  _SERVICE_STATUS *v37; // eax
  int v38; // edx
  int v39; // [esp+8h] [ebp-154h]
  int v40; // [esp+8h] [ebp-154h]
  _BYTE *v41; // [esp+Ch] [ebp-150h]
  int v42; // [esp+10h] [ebp-14Ch]
  int v43; // [esp+14h] [ebp-148h]
  _BYTE v44[320]; // [esp+18h] [ebp-144h] BYREF

  v10 = (int)a3;
  if ( (unsigned int)(a4 - (_DWORD)a3) >= 2 )
  {
    v12 = v44;
    v43 = (int)a3;
    v42 = a4;
    while ( 1 )
    {
      v41 = v12;
LABEL_5:
      if ( v42 - v10 > 9 )
        break;
      v34 = v10;
      v43 = v10 + 1;
      if ( v10 + 1 < v42 )
      {
        do
        {
          for ( ;
                (int)GASArraySortOnFunctor::Compare(
                       this: (GASArraySortOnFunctor *)&a5,
                       a2: (_SERVICE_STATUS *)v34,
                       a3: a1,
                       a4: *(GASValue **)(*a2 + 4 * v34 + 4),
                       a5: *(GASValue **)(*a2 + 4 * v34)) < 0;
                --v34 )
          {
            v35 = (_DWORD *)(*a2 + 4 * v34);
            v36 = v35[1];
            v35[1] = *v35;
            *v35 = v36;
            if ( v34 == v10 )
              break;
          }
          v34 = v43++;
        }
        while ( v43 < v42 );
        v12 = v41;
      }
      if ( v12 <= v44 )
      {
        GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)a9, a2: a10);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: a9);
        return 1;
      }
      v37 = *((_SERVICE_STATUS **)v12 - 2);
      v38 = *((_DWORD *)v12 - 1);
      v12 -= 8;
      v43 = (int)v37;
      v42 = v38;
      v10 = (int)v37;
    }
    v13 = *(_DWORD *)(*a2 + 4 * v10);
    v14 = v10 + (v42 - v10) / 2;
    v15 = *(_DWORD *)(*a2 + 4 * v14);
    v16 = (_DWORD *)(*a2 + 4 * v14);
    *(_DWORD *)(*a2 + 4 * v10) = v15;
    *v16 = v13;
    v17 = *(GASValue **)(*a2 + 4 * v10 + 4);
    v18 = v10 + 1;
    v19 = v42 - 1;
    if ( (int)GASArraySortOnFunctor::Compare(
                this: (GASArraySortOnFunctor *)&a5,
                a2: (_SERVICE_STATUS *)v18,
                a3: a1,
                a4: *(GASValue **)(*a2 + 4 * v42 - 4),
                a5: v17) < 0 )
    {
      v21 = *a2;
      v22 = *(_DWORD *)(*a2 + 4 * v19);
      *(_DWORD *)(v21 + 4 * v19) = *(_DWORD *)(*a2 + 4 * v18);
      *(_DWORD *)(v21 + 4 * v18) = v22;
    }
    if ( (int)GASArraySortOnFunctor::Compare(
                this: (GASArraySortOnFunctor *)&a5,
                a2: (_SERVICE_STATUS *)v18,
                a3: v20,
                a4: *(GASValue **)(*a2 + 4 * v43),
                a5: *(GASValue **)(*a2 + 4 * v18)) < 0 )
    {
      v24 = *a2;
      v39 = *(_DWORD *)(*a2 + 4 * v43);
      *(_DWORD *)(v24 + 4 * v43) = *(_DWORD *)(v24 + 4 * v18);
      *(_DWORD *)(v24 + 4 * v18) = v39;
    }
    if ( (int)GASArraySortOnFunctor::Compare(
                this: (GASArraySortOnFunctor *)&a5,
                a2: (_SERVICE_STATUS *)v18,
                a3: v23,
                a4: *(GASValue **)(*a2 + 4 * v19),
                a5: *(GASValue **)(*a2 + 4 * v43)) < 0 )
    {
      v25 = *a2;
      v26 = *(_DWORD *)(*a2 + 4 * v19);
      *(_DWORD *)(v25 + 4 * v19) = *(_DWORD *)(v25 + 4 * v43);
      *(_DWORD *)(v25 + 4 * v43) = v26;
    }
LABEL_12:
    while ( ++v18 < v42 )
    {
      if ( (int)GASArraySortOnFunctor::Compare(
                  this: (GASArraySortOnFunctor *)&a5,
                  a2: (_SERVICE_STATUS *)v18,
                  a3: a1,
                  a4: *(GASValue **)(*a2 + 4 * v18),
                  a5: *(GASValue **)(*a2 + 4 * v43)) >= 0 )
      {
        while ( --v19 >= 0 )
        {
          if ( (int)GASArraySortOnFunctor::Compare(
                      this: (GASArraySortOnFunctor *)&a5,
                      a2: (_SERVICE_STATUS *)v18,
                      a3: a1,
                      a4: *(GASValue **)(*a2 + 4 * v43),
                      a5: *(GASValue **)(*a2 + 4 * v19)) >= 0 )
          {
            v27 = *a2;
            if ( v18 <= v19 )
            {
              v28 = *(_DWORD *)(v27 + 4 * v18);
              *(_DWORD *)(v27 + 4 * v18) = *(_DWORD *)(v27 + 4 * v19);
              *(_DWORD *)(v27 + 4 * v19) = v28;
              goto LABEL_12;
            }
            v40 = *(_DWORD *)(v27 + 4 * v43);
            *(_DWORD *)(v27 + 4 * v43) = *(_DWORD *)(v27 + 4 * v19);
            v29 = v42;
            *(_DWORD *)(v27 + 4 * v19) = v40;
            v30 = v43;
            if ( v19 - v43 <= v29 - v18 )
            {
              v32 = (int *)v41;
              v33 = v42;
              v41 += 8;
              v12 = v41;
              v42 = v19;
              v10 = v43;
              *v32 = v18;
              v32[1] = v33;
            }
            else
            {
              v31 = (int *)v41;
              v41 += 8;
              v31[1] = v19;
              *v31 = v30;
              v12 = v41;
              v43 = v18;
              v10 = v18;
            }
            goto LABEL_5;
          }
        }
        break;
      }
    }
    GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)a9, a2: a10);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: a9);
    return 0;
  }
  else
  {
    GConstructorMov<GASArraySortFunctor>::DestructArray(a1: (int)a9, a2: a10);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: a9);
    return 1;
  }
}
