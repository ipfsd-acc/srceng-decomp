// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gassharedobject.cpp
// Functions: 102
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gassharedobject.h"

//------------------------------------------------------------------------------
// Address: 0x10120AA0
// Name: public: virtual void GASSharedObjectLoader::PopArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::PopArray(GASSharedObjectLoader *this)
{
  (*(void (__thiscall **)(GASSharedObjectLoader *))(*(_DWORD *)this + 20))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10120AB0
// Name: public: bool GASSharedObject::SetNameAndLocalPath(class GString const __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASSharedObject::SetNameAndLocalPath(
        GASSharedObject *this,
        CUtlMemory<CImagePacker,int> *a2,
        struct GString *src)
{
  CUtlMemory<CImagePacker,int> *v3; // esi
  unsigned int FirstCharAt; // eax
  int v6; // edx
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+0h] [ebp-10h]

  v3 = a2;
  FirstCharAt = GString::GetFirstCharAt(
                  this: a2,
                  index: nullptr,
                  offset: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&a2);
  if ( FirstCharAt == 0 )
  {
LABEL_7:
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 13),
      src: v3,
      a3: v8);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 14),
      src,
      a3: v9);
    return 1;
  }
  while ( 2 )
  {
    switch ( FirstCharAt )
    {
      case '"':
      case '#':
      case '%':
      case '&':
      case '\'':
      case ',':
      case ':':
      case ';':
      case '<':
      case '>':
      case '?':
      case '\\':
      case '~':
        return 0;
      default:
        v6 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + BYTE1(FirstCharAt));
        if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + BYTE1(FirstCharAt)) == 0
          || v6 != 1
          && (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable
              + v6
              + ((unsigned __int8)FirstCharAt >> 4))
            & (1 << (FirstCharAt & 0xF))) == 0 )
        {
          FirstCharAt = (unsigned int)GString::GetNextChar(
                                        this: v3,
                                        offset: (CUtlMap<char const *,int,unsigned short>::CKeyLess)&a2);
          if ( FirstCharAt == 0 )
            goto LABEL_7;
          continue;
        }
        return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120BD0
// Name: public: virtual bool GASSharedObject::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObject::SetMember(
        GASSharedObject *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *a3,
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **a4,
        const struct GASPropFlags *a5)
{
  if ( strcmp(*(const char **)a3->N.Name.Short, (const char *)&stru_10290234) != 0 )
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      (GASEnvironment *)a2,
      name: a3,
      pval: a4,
      pmember: (char *)a5);
}

//------------------------------------------------------------------------------
// Address: 0x10120C30
// Name: _GASSharedObject::ComputeSizeInBytes_::_2_::DataSizeEstimator::Visit
// Source: json
//------------------------------------------------------------------------------
_DWORD *__userpurge GASSharedObject::ComputeSizeInBytes_::_2_::DataSizeEstimator::Visit@<eax>(
        int a1@<ecx>,
        int a2@<edi>,
        _DWORD *a3,
        GASValue *a4,
        int a5)
{
  _DWORD *result; // eax
  struct GASObject *v8; // eax

  *(_DWORD *)(a1 + 8) += *(_DWORD *)(*a3 + 16);
  result = (_DWORD *)(*(unsigned __int8 *)a4 - 3);
  switch ( *(_BYTE *)a4 )
  {
    case 3:
    case 4:
      *(_DWORD *)(a1 + 8) += 4;
      break;
    case 5:
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)a4,
        a2: (int *)&a3,
        a3: *(tagRID_DEVICE_INFO_KEYBOARD **)(a1 + 4),
        precision: -1,
        debug: false);
      result = a3;
      *(_DWORD *)(a1 + 8) += a3[4];
      if ( result[2]-- == 1 )
        result = GASStringNode::ReleaseNode(a1: (int)result);
      break;
    case 6:
      v8 = GASValue::ToObject(this: a4, a2, a3: *(const struct GASEnvironment **)(a1 + 4));
      result = (_DWORD *)((int (__thiscall *)(struct GASObject *, int, int, _DWORD, _DWORD))v8[2].pNode[4].pNext)(
                           a1: &v8[2],
                           a2: *(_DWORD *)(a1 + 4) + 120,
                           a3: a1,
                           a4: 0,
                           a5: 0);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120D20
// Name: public: void GASSharedObject::SetDataObject(class GASEnvironment __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSharedObject::SetDataObject(GFxAmpAppControlInterface *this@<ecx>, _IMAGE_SYMBOL_EX penv)
{
  GASEnvironment *Short; // edi
  int v3; // eax
  struct GASStringNode *ConstStringNode; // eax
  struct GASObject *Long; // edx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **v7; // eax
  unsigned int v8; // eax
  int v10; // [esp+0h] [ebp-1Ch]
  GASValue v11[4]; // [esp+8h] [ebp-14h] BYREF
  char v12; // [esp+1Bh] [ebp-1h] BYREF

  Short = (GASEnvironment *)penv.N.Name.Short;
  v3 = *(_DWORD *)(penv.N.Name.Short + 120);
  v12 = 0;
  ConstStringNode = GASStringManager::CreateConstStringNode(
                      this: *(GASStringManager **)(v3 + 636),
                      result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_10290234,
                      a3: 4u,
                      a4: 0);
  Long = (struct GASObject *)penv.N.Name.Long;
  penv.N.Name.Short = (unsigned int)ConstStringNode;
  ++*((_DWORD *)ConstStringNode + 2);
  v7 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)GASValue::GASValue(
                                                                                     this: v11,
                                                                                     a2: Long);
  GASObject::SetMember(this: (CTSQueue<CFunctor *,0,1> *)(this + 4), a2: Short, name: &penv, pval: v7, pmember: &v12);
  v8 = penv.N.Name.Short;
  if ( (*(_DWORD *)(penv.N.Name.Short + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v8);
  GASValue::~GASValue(this: v11, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10120E00
// Name: public: virtual enum GASObjectInterface::ObjectType GASSharedObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASSharedObject::GetObjectType()
{
  return 44;
}

//------------------------------------------------------------------------------
// Address: 0x10120EC0
// Name: public: virtual void GASSharedObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObject::Finalize_GC(GASSharedObject *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)((int)*(this + 13) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)((int)*(this + 14) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10120F20
// Name: public: virtual void GASSharedObjectLoader::AddProperty(class GString const __near &,class GString const __near &,enum GFxValue::ValueType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSharedObjectLoader::AddProperty(
        GASSharedObjectLoader *this@<ecx>,
        struct GASStringNode *StringNode@<edi>,
        const struct GString *a3,
        const struct GString *a4,
        struct GASStringNode *a5)
{
  GASArrayObject *v6; // ebx
  bool v7; // zf
  int v8; // eax
  enum GFxValue::ValueType v9; // eax
  GASValue v10; // [esp+Ch] [ebp-18h] BYREF
  long double v11; // [esp+10h] [ebp-14h]
  long double v12; // [esp+1Ch] [ebp-8h]

  v6 = *(GASArrayObject **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
  LOBYTE(v10) = 0;
  switch ( (unsigned int)a5 )
  {
    case 0u:
      GASValue::DropRefs(this: &v10, a2: (int)StringNode);
      LOBYTE(v10) = 0;
      break;
    case 1u:
      GASValue::DropRefs(this: &v10, a2: (int)StringNode);
      LOBYTE(v10) = 1;
      break;
    case 2u:
      LOBYTE(a4) = strncmp(first: (const char *)((a4->HeapTypeBits & 0xFFFFFFFC) + 8), last: "true", count: 4u) == 0;
      GASValue::DropRefs(this: &v10, a2: (int)StringNode);
      LOBYTE(v10) = 2;
      LOBYTE(v11) = (_BYTE)a4;
      break;
    case 3u:
      v12 = atof(nptr: (const char *)((a4->HeapTypeBits & 0xFFFFFFFC) + 8));
      LOBYTE(v10) = 3;
      v11 = v12;
      break;
    case 4u:
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(*((_DWORD *)this + 2) + 120) + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a4->HeapTypeBits
                                                                                               & 0xFFFFFFFC)
                                                                                              + 8),
                     length: *(_DWORD *)(a4->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)StringNode + 2);
      if ( (unsigned __int8)v10 >= 5u )
        GASValue::DropRefs(this: &v10, a2: (int)StringNode);
      LOBYTE(v10) = 5;
      LODWORD(v11) = StringNode;
      v7 = ++*((_DWORD *)StringNode + 2) == 1;
      --*((_DWORD *)StringNode + 2);
      if ( v7 )
        GASStringNode::ReleaseNode(a1: (int)StringNode);
      break;
    default:
      break;
  }
  if ( *((_BYTE *)this + 28) != 0 )
  {
    GASArrayObject::PushBack(this: v6, val: (tagWNDCLASSW *)&v10);
    GASValue::~GASValue(this: &v10, a2: (int)StringNode);
  }
  else
  {
    v8 = *((_DWORD *)this + 2);
    HIBYTE(a4) = 0;
    a5 = GASStringManager::CreateStringNode(
           this: *(GASStringManager **)(*(_DWORD *)(v8 + 120) + 636),
           result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a3->HeapTypeBits & 0xFFFFFFFC) + 8),
           length: *(_DWORD *)(a3->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++*((_DWORD *)a5 + 2);
    (*(void (__thiscall **)(_DWORD *, _DWORD, struct GASStringNode **, GASValue *, char *))(*((_DWORD *)v6 + 4) + 12))(
      a1: (_DWORD *)v6 + 4,
      a2: *((_DWORD *)this + 2),
      a3: &a5,
      a4: &v10,
      a5: (char *)&a4 + 3);
    v9 = (enum GFxValue::ValueType)a5;
    v7 = (*((_DWORD *)a5 + 2))-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode(a1: v9);
    GASValue::~GASValue(this: &v10, a2: (int)StringNode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101210D0
// Name: public: unsigned int GASSharedObject::ComputeSizeInBytes(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
GFxAmpAppControlInterface *__userpurge GASSharedObject::ComputeSizeInBytes@<eax>(
        D3DXQUATERNION *a1@<ecx>,
        _IMAGE_SYMBOL_EX result)
{
  ID3DXFont *Short; // esi
  int v3; // eax
  int v4; // edi
  unsigned int v6; // eax
  struct GASObject *v8; // eax
  int v9; // esi
  GASValue val[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v12[2]; // [esp+1Ch] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-4h]

  Short = (ID3DXFont *)result.N.Name.Short;
  v3 = *(_DWORD *)(result.N.Name.Short + 120);
  v4 = result.N.Name.Short + 120;
  LOBYTE(val[0]) = 0;
  result.N.Name.Short = (unsigned int)GASStringManager::CreateConstStringNode(
                                        this: *(GASStringManager **)(v3 + 636),
                                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_10290234,
                                        a3: 4u,
                                        a4: 0);
  ++*(_DWORD *)(result.N.Name.Short + 8);
  GASObject::GetMember(this: a1 + 1, result: Short, penv: &result, (int *)val);
  v6 = result.N.Name.Short;
  if ( (*(_DWORD *)(result.N.Name.Short + 8))-- == 1 )
    GASStringNode::ReleaseNode(a1: v6);
  v8 = GASValue::ToObject(this: val, a2: v4, a3: (const struct GASEnvironment *)Short);
  v12[0] = &`GASSharedObject::ComputeSizeInBytes'::`2'::DataSizeEstimator::`vftable';
  v12[1] = Short;
  v13 = 0;
  ((void (__thiscall *)(struct GASObject *, int, _DWORD *, _DWORD, _DWORD))v8[2].pNode[4].pNext)(
    a1: &v8[2],
    a2: v4,
    a3: v12,
    a4: 0,
    a5: 0);
  v9 = v13;
  v12[0] = &GString::InitStruct::`vftable';
  GASValue::~GASValue(this: val, a2: v4);
  return (GFxAmpAppControlInterface *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10121170
// Name: public: static void GASSharedObjectProto::GetSize(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101215E0
// Name: public: virtual GASSharedObjectLoader::~GASSharedObjectLoader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::~GASSharedObjectLoader(IShaderAPI *this)
{
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 4));
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x10121870
// Name: public: virtual void GASSharedObjectLoader::Begin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::Begin(GASSharedObjectLoader *this)
{
  CVertexBuilder *v1; // esi
  unsigned int m_VertexSize_BoneWeight; // eax
  unsigned int v3; // edi
  int m_VertexSize_Position; // eax
  _DWORD *v5; // eax

  v1 = (CVertexBuilder *)((char *)this + 16);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    if ( (*((_DWORD *)this + 6) & 0xFFFFFFFE) != 0 )
    {
      if ( v1->m_VertexSize_Position != 0 )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v1->m_VertexSize_Position);
        v1->m_VertexSize_Position = 0;
      }
      v1->m_VertexSize_BoneMatrixIndex = 0;
    }
  }
  else if ( *((_DWORD *)this + 6) == 0 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: (CVertexBuilder *)((char *)this + 16),
      pheapAddr: (ButtonCode_t)((char *)this + 16),
      newCapacity: 0);
  }
  v1->m_VertexSize_BoneWeight = 0;
  m_VertexSize_BoneWeight = v1->m_VertexSize_BoneWeight;
  v3 = m_VertexSize_BoneWeight + 1;
  if ( m_VertexSize_BoneWeight + 1 >= m_VertexSize_BoneWeight )
  {
    if ( v3 >= v1->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v1,
        pheapAddr: (ButtonCode_t)v1,
        newCapacity: v3 + (v3 >> 2));
  }
  else if ( v3 < (unsigned int)v1->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v1,
      pheapAddr: (ButtonCode_t)v1,
      newCapacity: m_VertexSize_BoneWeight + 1);
  }
  m_VertexSize_Position = v1->m_VertexSize_Position;
  v1->m_VertexSize_BoneWeight = v3;
  v5 = (_DWORD *)(m_VertexSize_Position + 4 * v3 - 4);
  if ( v5 != nullptr )
    *v5 = *((_DWORD *)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10121910
// Name: public: virtual void GASSharedObjectLoader::PushObject(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::PushObject(GASSharedObjectLoader *this, const struct GString *a2)
{
  GASArrayObject *v3; // ebx
  CVertexBuilder *v4; // edi
  struct GASObject *v5; // eax
  bool v6; // zf
  tagWNDCLASSW *v7; // eax
  int v8; // eax
  const struct GString *StringNode; // eax
  struct GASObject *v10; // ecx
  _DWORD *v11; // eax
  int v12; // ebx
  GASValue *v13; // eax
  const struct GString *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // esi
  int m_VertexSize_Position; // edx
  struct GASObject *v18; // ecx
  struct GASObject **v19; // esi
  GASValue v20[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v21; // [esp+1Ch] [ebp-Ch]
  struct GASObject *v22; // [esp+20h] [ebp-8h]
  char v23; // [esp+27h] [ebp-1h] BYREF

  v3 = *(GASArrayObject **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
  v4 = (CVertexBuilder *)((char *)this + 16);
  v5 = GASEnvironment::OperatorNew(
         this: *((__vc_attributes::idl_quoteAttribute **)this + 2),
         a2: (int)this + 16,
         a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)this + 2) + 120) + 680),
         a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)this + 2) + 120) + 12),
         nargs: 0,
         argsTopOff: -1);
  v6 = *((_BYTE *)this + 28) == 0;
  v22 = v5;
  if ( v6 )
  {
    v8 = *((_DWORD *)this + 2);
    v23 = 0;
    StringNode = (const struct GString *)GASStringManager::CreateStringNode(
                                           this: *(GASStringManager **)(*(_DWORD *)(v8 + 120) + 636),
                                           result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2->HeapTypeBits & 0xFFFFFFFC) + 8),
                                           length: *(_DWORD *)(a2->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    v10 = v22;
    a2 = StringNode;
    ++StringNode[2].HeapTypeBits;
    v11 = (_DWORD *)((char *)v3 + 16);
    v12 = *((_DWORD *)v3 + 4);
    v21 = v11;
    v13 = GASValue::GASValue(this: v20, a2: v10);
    (*(void (__thiscall **)(_DWORD *, _DWORD, const struct GString **, GASValue *, char *))(v12 + 12))(
      a1: v21,
      a2: *((_DWORD *)this + 2),
      a3: &a2,
      a4: v13,
      a5: &v23);
    v14 = a2;
    v6 = a2[2].HeapTypeBits-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: (int)v14);
  }
  else
  {
    v7 = (tagWNDCLASSW *)GASValue::GASValue(this: v20, a2: v5);
    GASArrayObject::PushBack(this: v3, val: v7);
  }
  GASValue::~GASValue(this: v20, a2: (int)v4);
  *((_BYTE *)this + 28) = 0;
  v15 = *((_DWORD *)this + 5);
  v16 = v15 + 1;
  if ( v15 + 1 >= v15 )
  {
    if ( v16 >= v4->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: (ButtonCode_t)v4,
        newCapacity: v16 + (v16 >> 2));
  }
  else if ( v16 < (unsigned int)v4->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: (ButtonCode_t)v4,
      newCapacity: v16);
  }
  m_VertexSize_Position = v4->m_VertexSize_Position;
  v18 = v22;
  v4->m_VertexSize_BoneWeight = v16;
  v19 = (struct GASObject **)(m_VertexSize_Position + 4 * v16 - 4);
  if ( v19 != nullptr )
    *v19 = v18;
  if ( v18 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v18, a2: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10121A30
// Name: public: virtual void GASSharedObjectLoader::PushArray(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::PushArray(GASSharedObjectLoader *this, const struct GString *a2)
{
  GASArrayObject *v3; // ebx
  CVertexBuilder *v4; // edi
  struct GASObject *v5; // eax
  bool v6; // zf
  tagWNDCLASSW *v7; // eax
  int v8; // eax
  const struct GString *StringNode; // eax
  struct GASObject *v10; // ecx
  _DWORD *v11; // eax
  int v12; // ebx
  GASValue *v13; // eax
  const struct GString *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // esi
  int m_VertexSize_Position; // edx
  struct GASObject *v18; // ecx
  struct GASObject **v19; // esi
  GASValue v20[4]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v21; // [esp+1Ch] [ebp-Ch]
  struct GASObject *v22; // [esp+20h] [ebp-8h]
  char v23; // [esp+27h] [ebp-1h] BYREF

  v3 = *(GASArrayObject **)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 5) - 4);
  v4 = (CVertexBuilder *)((char *)this + 16);
  v5 = GASEnvironment::OperatorNew(
         this: *((__vc_attributes::idl_quoteAttribute **)this + 2),
         a2: (int)this + 16,
         a3: *(struct GASObject **)(*(_DWORD *)(*((_DWORD *)this + 2) + 120) + 680),
         a4: (const struct GASString *)(*(_DWORD *)(*((_DWORD *)this + 2) + 120) + 16),
         nargs: 0,
         argsTopOff: -1);
  v6 = *((_BYTE *)this + 28) == 0;
  v22 = v5;
  if ( v6 )
  {
    v8 = *((_DWORD *)this + 2);
    v23 = 0;
    StringNode = (const struct GString *)GASStringManager::CreateStringNode(
                                           this: *(GASStringManager **)(*(_DWORD *)(v8 + 120) + 636),
                                           result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2->HeapTypeBits & 0xFFFFFFFC) + 8),
                                           length: *(_DWORD *)(a2->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    v10 = v22;
    a2 = StringNode;
    ++StringNode[2].HeapTypeBits;
    v11 = (_DWORD *)((char *)v3 + 16);
    v12 = *((_DWORD *)v3 + 4);
    v21 = v11;
    v13 = GASValue::GASValue(this: v20, a2: v10);
    (*(void (__thiscall **)(_DWORD *, _DWORD, const struct GString **, GASValue *, char *))(v12 + 12))(
      a1: v21,
      a2: *((_DWORD *)this + 2),
      a3: &a2,
      a4: v13,
      a5: &v23);
    v14 = a2;
    v6 = a2[2].HeapTypeBits-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: (int)v14);
  }
  else
  {
    v7 = (tagWNDCLASSW *)GASValue::GASValue(this: v20, a2: v5);
    GASArrayObject::PushBack(this: v3, val: v7);
  }
  GASValue::~GASValue(this: v20, a2: (int)v4);
  *((_BYTE *)this + 28) = 1;
  v15 = *((_DWORD *)this + 5);
  v16 = v15 + 1;
  if ( v15 + 1 >= v15 )
  {
    if ( v16 >= v4->m_VertexSize_BoneMatrixIndex )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        pheapAddr: (ButtonCode_t)v4,
        newCapacity: v16 + (v16 >> 2));
  }
  else if ( v16 < (unsigned int)v4->m_VertexSize_BoneMatrixIndex >> 1 )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      pheapAddr: (ButtonCode_t)v4,
      newCapacity: v16);
  }
  m_VertexSize_Position = v4->m_VertexSize_Position;
  v18 = v22;
  v4->m_VertexSize_BoneWeight = v16;
  v19 = (struct GASObject **)(m_VertexSize_Position + 4 * v16 - 4);
  if ( v19 != nullptr )
    *v19 = v18;
  if ( v18 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v18, a2: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10121B50
// Name: public: virtual void GASSharedObjectLoader::PopObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectLoader::PopObject(GASSharedObjectLoader *this)
{
  int v2; // eax
  CVertexBuilder *v3; // esi
  unsigned int v4; // edi
  int v5; // ecx

  v2 = *((_DWORD *)this + 5);
  v3 = (CVertexBuilder *)((char *)this + 16);
  v4 = v2 - 1;
  if ( v2 != 0 )
  {
    if ( v4 < *((_DWORD *)this + 6) >> 1 )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v3,
        pheapAddr: (ButtonCode_t)v3,
        newCapacity: v4);
  }
  else if ( v4 >= *((_DWORD *)this + 6) )
  {
    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
      this: v3,
      pheapAddr: (ButtonCode_t)v3,
      newCapacity: v4 + (v4 >> 2));
  }
  v3->m_VertexSize_BoneWeight = v4;
  v5 = *(_DWORD *)(v3->m_VertexSize_Position + 4 * v4 - 4);
  *((_BYTE *)this + 28) = (*(int (__thiscall **)(int))(*(_DWORD *)(v5 + 16) + 8))(a1: v5 + 16) == 7;
}

//------------------------------------------------------------------------------
// Address: 0x10121BB0
// Name: public: virtual class GASObject __near * GASSharedObjectCtorFunction::CreateNewObject(class GASEnvironment __near *)const
// Source: json
//------------------------------------------------------------------------------
struct GASObject *__thiscall GASSharedObjectCtorFunction::CreateNewObject(GASSharedObjectCtorFunction *this, int a2)
{
  struct GASEnvironment *v2; // ebx
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  vc_attributes::PreRangeAttribute **v5; // edi
  GASObject *v6; // eax
  GASObject *v7; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax

  v2 = (struct GASEnvironment *)a2;
  v3 = *(_DWORD *)(*(_DWORD *)(a2 + 120) + 656);
  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
  v5 = (vc_attributes::PreRangeAttribute **)(a2 + 120);
  a2 = 323;
  v6 = (GASObject *)v4(a1: v3, a2: 60, a3: &a2);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  GASObject::GASObject(this: v6, a2: v2);
  v7->pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASSharedObject::`vftable'{for `GASRefCountBase<GASObject>'};
  v7[2].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)&GASSharedObject::`vftable'{for `GASObjectInterface'};
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v7[6].sequence);
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v7[7]);
  Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                    this: *v5,
                                                    result: (vc_attributes::InvalidCheckAttribute *)0x2C);
  GASObject::Set__proto__(
    this: (CTSQueue<CFunctor *,0,1> *)&v7[2],
    psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v5,
    psc_4: Prototype);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10121C30
// Name: public: static void GASSharedObjectCtorFunction::GlobalCtor(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GASSharedObjectCtorFunction::GlobalCtor(ID3D11UnorderedAccessView *result)
{
  ID3D11UnorderedAccessView *v1; // edi
  int v2; // ecx
  int (__thiscall *v3)(int, int, int *); // edx
  GASObject *v4; // eax
  int v5; // esi
  ID3D11UnorderedAccessView_vtbl *v6; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  int v8; // [esp+8h] [ebp-4h] BYREF

  v1 = result;
  v2 = *((_DWORD *)result[6].__vftable[3].GetDevice + 164);
  v3 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v2 + 40);
  v8 = 323;
  v4 = (GASObject *)v3(a1: v2, a2: 60, a3: &v8);
  v5 = (int)v4;
  if ( v4 != nullptr )
  {
    v6 = result[6].__vftable;
    GASObject::GASObject(this: v4, a2: (struct GASEnvironment *)v6);
    *(_DWORD *)v5 = &GASSharedObject::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v5 + 16) = &GASSharedObject::`vftable'{for `GASObjectInterface'};
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v5 + 52));
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)(v5 + 56));
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: (vc_attributes::PreRangeAttribute *)v6[3].GetDevice,
                                                      result: (vc_attributes::InvalidCheckAttribute *)0x2C);
    GASObject::Set__proto__(
      this: (CTSQueue<CFunctor *,0,1> *)(v5 + 16),
      psc: (CTSQueue<CFunctor *,0,1>::Node_t *)&v6[3].GetDevice,
      psc_4: Prototype);
    v1 = result;
  }
  else
  {
    v5 = 0;
  }
  GASValue::SetAsObject(this: (GASValue *)v1[1].__vftable, a2: (struct GASObject *)v5);
  if ( v5 != 0 )
    GRefCountBaseGC<323>::Release(a1: v5, a2: (int)v1);
}

//------------------------------------------------------------------------------
// Address: 0x10121D60
// Name: protected: void GASSharedObjectCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::ReleaseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(
        ISteamUserStats *this)
{
  ISteamUserStats *v2; // ecx
  unsigned int result; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  int v6; // edi
  signed int v7; // esi
  _DWORD *v8; // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
  v2 = *((ISteamUserStats **)this + 14);
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    result = 0;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      ++result;
      v5 += 4;
    }
    while ( result <= (unsigned int)v4 );
    v2 = this + 14;
  }
  else
  {
    result = 0;
  }
  v6 = (int)v2;
  v7 = result;
  while ( v6 != 0 )
  {
    result = *(_DWORD *)v6;
    if ( *(_DWORD *)v6 == 0 || v7 > *(_DWORD *)(result + 4) )
      break;
    GRefCountBaseGC<323>::Release(a1: *(_DWORD *)(result + 16 * v7 + 20), a2: v6);
    result = *(_DWORD *)(*(_DWORD *)v6 + 4);
    if ( v7 <= (int)result && ++v7 <= result )
    {
      v8 = (_DWORD *)(*(_DWORD *)v6 + 16 * v7 + 8);
      do
      {
        if ( *v8 != -2 )
          break;
        ++v7;
        v8 += 4;
      }
      while ( v7 <= result );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121DE0
// Name: protected: void GASSharedObjectCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::MarkInCycleFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
ISteamUserStats_vtbl *__thiscall GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(
        ISteamUserStats *this)
{
  ISteamUserStats *v2; // ecx
  ISteamUserStats_vtbl *result; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  int v8; // ecx
  bool (__thiscall **v9)(ISteamUserStats *, const char *, int *); // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
  v2 = *((ISteamUserStats **)this + 14);
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    result = nullptr;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      result = (ISteamUserStats_vtbl *)((char *)result + 1);
      v5 += 4;
    }
    while ( result <= v4 );
    v2 = this + 14;
  }
  else
  {
    result = nullptr;
  }
  v6 = v2;
  v7 = (signed int)result;
  while ( v6 != nullptr )
  {
    result = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)result->GetStat )
      break;
    v8 = *((_DWORD *)&result->UpdateAvgRateStat + 4 * v7);
    if ( (--*(_DWORD *)(v8 + 8) & 0x70000000) != 0x10000000 )
    {
      *(_DWORD *)(v8 + 8) = *(_DWORD *)(v8 + 8) & 0x8FFFFFFF | 0x10000000;
      (**(void (__thiscall ***)(int, int))v8)(a1: v8, a2: 1);
    }
    result = (ISteamUserStats_vtbl *)v6->GetStat;
    if ( v7 <= (int)result && ++v7 <= (unsigned int)result )
    {
      v9 = &v6->GetStat_2 + 4 * v7;
      do
      {
        if ( *v9 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v9 += 4;
      }
      while ( v7 <= (unsigned int)result );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121E90
// Name: protected: void GASSharedObjectCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanInUseFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
ISteamUserStats_vtbl *__thiscall GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(
        ISteamUserStats *this)
{
  ISteamUserStats *v2; // ecx
  ISteamUserStats_vtbl *result; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  int v8; // ecx
  int v9; // eax
  void (__stdcall **v10)(int); // edx
  bool (__thiscall **v11)(ISteamUserStats *, const char *, int *); // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
  v2 = *((ISteamUserStats **)this + 14);
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    result = nullptr;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      result = (ISteamUserStats_vtbl *)((char *)result + 1);
      v5 += 4;
    }
    while ( result <= v4 );
    v2 = this + 14;
  }
  else
  {
    result = nullptr;
  }
  v6 = v2;
  v7 = (signed int)result;
  while ( v6 != nullptr )
  {
    result = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)result->GetStat )
      break;
    v8 = *((_DWORD *)&result->UpdateAvgRateStat + 4 * v7);
    v9 = ++*(_DWORD *)(v8 + 8);
    if ( (v9 & 0x70000000) != 0 )
    {
      v10 = *(void (__stdcall ***)(int))v8;
      *(_DWORD *)(v8 + 8) = v9 & 0x8FFFFFFF;
      (*v10)(a1: 2);
    }
    result = (ISteamUserStats_vtbl *)v6->GetStat;
    if ( v7 <= (int)result && ++v7 <= (unsigned int)result )
    {
      v11 = &v6->GetStat_2 + 4 * v7;
      do
      {
        if ( *v11 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v11 += 4;
      }
      while ( v7 <= (unsigned int)result );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121F30
// Name: protected: void GASSharedObjectCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::CollectGarbageFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
ISteamUserStats_vtbl *__thiscall GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(
        ISteamUserStats *this)
{
  ISteamUserStats *v2; // ecx
  ISteamUserStats_vtbl *result; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // ebx
  signed int v7; // edi
  int v8; // esi
  int v9; // eax
  void (__thiscall **v10)(int, int); // edx
  int v11; // eax
  bool (__thiscall **v12)(ISteamUserStats *, const char *, int *); // ecx

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
  v2 = *((ISteamUserStats **)this + 14);
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    result = nullptr;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      result = (ISteamUserStats_vtbl *)((char *)result + 1);
      v5 += 4;
    }
    while ( result <= v4 );
    v2 = this + 14;
  }
  else
  {
    result = nullptr;
  }
  v6 = v2;
  v7 = (signed int)result;
  while ( v6 != nullptr )
  {
    result = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)result->GetStat )
      break;
    v8 = *((_DWORD *)&result->UpdateAvgRateStat + 4 * v7);
    v9 = *(_DWORD *)(v8 + 8);
    if ( (v9 & 0x70000000) == 0x20000000 && v9 >= 0 )
    {
      v10 = *(void (__thiscall ***)(int, int))v8;
      *(_DWORD *)(v8 + 8) = v9 & 0x8FFFFFFF;
      (*v10)(a1: v8, a2: 3);
      v11 = *(_DWORD *)(v8 + 4);
      if ( (*(_DWORD *)(v8 + 8) & 0x70000000) != 0x40000000 )
      {
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(v11 + 28);
        *(_DWORD *)(v11 + 28) = v8;
        *(_DWORD *)(v8 + 8) = *(_DWORD *)(v8 + 8) & 0x8FFFFFFF | 0x40000000;
      }
    }
    result = (ISteamUserStats_vtbl *)v6->GetStat;
    if ( v7 <= (int)result && ++v7 <= (unsigned int)result )
    {
      v12 = &v6->GetStat_2 + 4 * v7;
      do
      {
        if ( *v12 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v12 += 4;
      }
      while ( v7 <= (unsigned int)result );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122020
// Name: protected: void GASSharedObjectCtorFunction::ForEachChild_GC<struct GRefCountBaseGC<323>::ScanFunctor>(void)const
// Source: json
//------------------------------------------------------------------------------
ISteamUserStats_vtbl *__thiscall GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(
        ISteamUserStats *this)
{
  ISteamUserStats *v2; // ecx
  ISteamUserStats_vtbl *result; // eax
  ISteamUserStats_vtbl *v4; // edx
  ISteamUserStats *v5; // ecx
  ISteamUserStats *v6; // edi
  signed int v7; // esi
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  bool (__thiscall **v11)(ISteamUserStats *, const char *, int *); // ecx
  int v12; // [esp-4h] [ebp-Ch]

  GASObject::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
  v2 = *((ISteamUserStats **)this + 14);
  if ( v2 != nullptr )
  {
    v4 = v2[1].__vftable;
    result = nullptr;
    v5 = v2 + 2;
    do
    {
      if ( v5->__vftable != (ISteamUserStats_vtbl *)-2 )
        break;
      result = (ISteamUserStats_vtbl *)((char *)result + 1);
      v5 += 4;
    }
    while ( result <= v4 );
    v2 = this + 14;
  }
  else
  {
    result = nullptr;
  }
  v6 = v2;
  v7 = (signed int)result;
  while ( v6 != nullptr )
  {
    result = v6->__vftable;
    if ( v6->__vftable == nullptr || v7 > (int)result->GetStat )
      break;
    v8 = *((_DWORD *)&result->UpdateAvgRateStat + 4 * v7);
    v9 = *(_DWORD *)(v8 + 8);
    if ( (v9 & 0x70000000) == 0x10000000 )
    {
      if ( (v9 & 0xFFFFFFF) != 0 )
      {
        v10 = v9 & 0x8FFFFFFF;
        v12 = 2;
      }
      else
      {
        v10 = v9 & 0x8FFFFFFF | 0x20000000;
        v12 = 4;
      }
      *(_DWORD *)(v8 + 8) = v10;
      (**(void (__thiscall ***)(int, int))v8)(a1: v8, a2: v12);
    }
    result = (ISteamUserStats_vtbl *)v6->GetStat;
    if ( v7 <= (int)result && ++v7 <= (unsigned int)result )
    {
      v11 = &v6->GetStat_2 + 4 * v7;
      do
      {
        if ( *v11 != (bool (__thiscall *)(ISteamUserStats *, const char *, int *))-2 )
          break;
        ++v7;
        v11 += 4;
      }
      while ( v7 <= (unsigned int)result );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122160
// Name: protected: virtual void GASSharedObjectCtorFunction::ExecuteForEachChild_GC(enum GRefCountBaseGC<323>::OperationGC)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GASSharedObjectCtorFunction::ExecuteForEachChild_GC(
        ISteamUserStats *this,
        unsigned int operation)
{
  unsigned int result; // eax

  result = operation;
  switch ( operation )
  {
    case 0u:
      result = GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ReleaseFunctor>(this);
      break;
    case 1u:
      result = (unsigned int)GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::MarkInCycleFunctor>(this);
      break;
    case 2u:
      result = (unsigned int)GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanInUseFunctor>(this);
      break;
    case 3u:
      result = (unsigned int)GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::CollectGarbageFunctor>(this);
      break;
    case 4u:
      result = (unsigned int)GASSharedObjectCtorFunction::ForEachChild_GC<GRefCountBaseGC<323>::ScanFunctor>(this);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101222C0
// Name: protected: virtual void GASSharedObjectCtorFunction::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectCtorFunction::Finalize_GC(GASObject *this)
{
  GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>(this: (_DWORD *)this + 14);
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10122360
// Name: public: void GASSharedObject::Flush(class GASEnvironment __near *,class GFxSharedObjectVisitor __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASSharedObject::Flush(GFxAmpAppControlInterface *this@<ecx>, ID3DXFont *penv, _IMAGE_SYMBOL_EX a3)
{
  unsigned int Short; // esi
  ID3DXFont_vtbl *v4; // eax
  struct GASStringNode *ConstStringNode; // eax
  D3DXQUATERNION *v6; // ecx
  unsigned int v7; // eax
  void (__thiscall *v9)(unsigned int); // edx
  GASValue val[4]; // [esp+4h] [ebp-24h] BYREF
  void **v11; // [esp+14h] [ebp-14h] BYREF
  CInternalFileSystemPassThru<IBaseFileSystem> v12; // [esp+18h] [ebp-10h] BYREF
  unsigned int v13; // [esp+20h] [ebp-8h]
  GFxAmpAppControlInterface *v14; // [esp+24h] [ebp-4h]

  Short = a3.N.Name.Short;
  v14 = this;
  if ( a3.N.Name.Short != 0 )
  {
    v4 = penv[30].__vftable;
    LOBYTE(val[0]) = 0;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: (GASStringManager *)v4[8].DrawTextW,
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_10290234,
                        a3: 4u,
                        a4: 0);
    v6 = (D3DXQUATERNION *)v14;
    a3.N.Name.Short = (unsigned int)ConstStringNode;
    ++*((_DWORD *)ConstStringNode + 2);
    GASObject::GetMember(this: v6 + 1, result: penv, penv: &a3, (int *)val);
    v7 = a3.N.Name.Short;
    if ( (*(_DWORD *)(a3.N.Name.Short + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: v7);
    a3.N.Name.Short = (unsigned int)GASValue::ToObject(
                                      this: val,
                                      a2: (int)penv,
                                      a3: (const struct GASEnvironment *)penv);
    v9 = *(void (__thiscall **)(unsigned int))(*(_DWORD *)Short + 4);
    v11 = (void **)&`GASSharedObject::Flush'::`4'::DataWriter::`vftable';
    v12.__vftable = nullptr;
    v12.m_pBaseFileSystemPassThru = (IBaseFileSystem *)penv;
    v13 = Short;
    v9(a1: Short);
    (*(void (__thiscall **)(unsigned int, ID3DXFont *, void ***, _DWORD, _DWORD))(*(_DWORD *)(a3.N.Name.Short + 16) + 32))(
      a1: a3.N.Name.Short + 16,
      a2: penv + 30,
      a3: &v11,
      a4: 0,
      a5: 0);
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)Short + 28))(a1: Short);
    GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(this: &v12);
    v11 = &GString::InitStruct::`vftable';
    GASValue::~GASValue(this: val, a2: (int)penv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122430
// Name: _GASSharedObject::Flush_::_4_::DataWriter::Visit
// Source: json
//------------------------------------------------------------------------------
int __userpurge GASSharedObject::Flush_::_4_::DataWriter::Visit@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        long double a3@<st0>,
        char ***a4,
        char *a5,
        int a6)
{
  double v7; // st7
  unsigned int Renderer; // eax
  int v9; // eax
  bool v10; // zf
  const char *v11; // eax
  GString::DataDesc *v12; // ebx
  int v13; // eax
  void (*v14)(void); // edx
  unsigned int v15; // esi
  int result; // eax
  int v18; // [esp+Ch] [ebp-1B0h]
  _DWORD *v19[2]; // [esp+10h] [ebp-1ACh] BYREF
  GString v20; // [esp+18h] [ebp-1A4h] BYREF
  int *v21; // [esp+1Ch] [ebp-1A0h] BYREF
  GString v22; // [esp+20h] [ebp-19Ch] BYREF
  GString v23; // [esp+24h] [ebp-198h] BYREF
  GString v24; // [esp+28h] [ebp-194h] BYREF
  GString v25; // [esp+2Ch] [ebp-190h] BYREF
  CMeshReader v26[2]; // [esp+30h] [ebp-18Ch] BYREF

  GString::GString(this: &v24, src: **a4, count: (unsigned int)(*a4)[4]);
  switch ( *a5 )
  {
    case 0:
      GString::GString(this: &v23, src: (int)&pMem);
      (*(void (__thiscall **)(_DWORD, GString *, GString *, _DWORD))(**(_DWORD **)(a1 + 12) + 16))(
        a1: *(_DWORD *)(a1 + 12),
        a2: &v24,
        a3: &v23,
        a4: 0);
      GString::~GString(this: &v23);
      break;
    case 1:
      GString::GString(this: &v22, src: (int)&pMem);
      (*(void (__thiscall **)(_DWORD, GString *, GString *, int))(**(_DWORD **)(a1 + 12) + 16))(
        a1: *(_DWORD *)(a1 + 12),
        a2: &v24,
        a3: &v22,
        a4: 1);
      GString::~GString(this: &v22);
      break;
    case 2:
      v10 = GASValue::ToBool(a1: a5, a2: a3, result: *(tagPOLYTEXTW **)(a1 + 8)) == 0;
      v11 = "true";
      if ( v10 )
        v11 = "false";
      GString::GString(this: &v20, src: (int)v11);
      (*(void (__thiscall **)(_DWORD, GString *, GString *, int))(**(_DWORD **)(a1 + 12) + 16))(
        a1: *(_DWORD *)(a1 + 12),
        a2: &v24,
        a3: &v20,
        a4: 2);
      GString::~GString(this: &v20);
      break;
    case 3:
    case 4:
      v7 = GASValue::ToNumber(this: (GASValue *)a5, a2: (int)a5, a3, result: (_SERVICE_STATUS *)*(_DWORD *)(a1 + 8));
      GDoubleFormatter::GDoubleFormatter(this: (GDoubleFormatter *)v26, v: v7);
      GDoubleFormatter::Convert(this: (type_info *)v26);
      Renderer = ScaleformTexture::GetRenderer(this: (CBitRead *)v26);
      GString::GString(this: &v25, a2: (struct GString::InitStruct *)&v26[0].m_VertexSize_Normal, size: Renderer);
      (*(void (__thiscall **)(_DWORD, GString *, GString *, int))(**(_DWORD **)(a1 + 12) + 16))(
        a1: *(_DWORD *)(a1 + 12),
        a2: &v24,
        a3: &v25,
        a4: 3);
      GString::~GString(this: &v25);
      v26[0].m_VertexSize_Normal = (int)&GString::InitStruct::`vftable';
      GFormatter::~GFormatter(this: v26);
      break;
    case 5:
      GASValue::ToStringImpl(
        this: (unsigned __int8 *)a5,
        a2: (int *)&v21,
        a3: *(tagRID_DEVICE_INFO_KEYBOARD **)(a1 + 8),
        precision: -1,
        debug: false);
      GString::GString(this: &v25, src: *v21);
      v9 = (int)v21;
      v10 = v21[2]-- == 1;
      if ( v10 )
        GASStringNode::ReleaseNode(a1: v9);
      (*(void (__thiscall **)(_DWORD, GString *, GString *, int))(**(_DWORD **)(a1 + 12) + 16))(
        a1: *(_DWORD *)(a1 + 12),
        a2: &v24,
        a3: &v25,
        a4: 4);
      GString::~GString(this: &v25);
      break;
    case 6:
      v12 = (GString::DataDesc *)GASValue::ToObject(
                                   this: (GASValue *)a5,
                                   a2: (int)a5,
                                   a3: *(const struct GASEnvironment **)(a1 + 8));
      v25.pData = v12;
      if ( GHash<GASObject *,GASObject *,GIdentityHash<GASObject *>,GAllocatorGH<GASObject *,2>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>,GHashSet<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeAltHashF,GAllocatorGH<GASObject *,2>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>>>::Get(a1: &v25) == 0 )
      {
        v19[1] = &v25;
        v19[0] = &v25;
        GHashSetBase<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeAltHashF,GAllocatorGH<GASObject *,2>,GHashsetNodeEntry<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>,GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeHashF>>::add<GHashNode<GASObject *,GASObject *,GIdentityHash<GASObject *>>::NodeRef>(
          this: (CInternalFileSystemPassThru<IBaseFileSystem> *)(a1 + 4),
          a2: a1 + 4,
          a3: v19,
          a4: (int)v12);
        v10 = (*(int (__thiscall **)(volatile int *, int))(v25.pData[1].RefCount + 8))(a1: &v25.pData[1].RefCount, a2) == 7;
        v13 = **(_DWORD **)(a1 + 12);
        if ( v10 )
        {
          (*(void (__stdcall **)(GString *, int, _DWORD *))(v13 + 12))(a1: &v24, a2: v18, a3: v19[0]);
          (*(void (__thiscall **)(volatile int *, int, int, _DWORD, _DWORD))(v25.pData[1].RefCount + 32))(
            a1: &v25.pData[1].RefCount,
            a2: *(_DWORD *)(a1 + 8) + 120,
            a3: a1,
            a4: 0,
            a5: 0);
          v14 = *(void (**)(void))(**(_DWORD **)(a1 + 12) + 24);
        }
        else
        {
          (*(void (__stdcall **)(GString *, int, _DWORD *))(v13 + 8))(a1: &v24, a2: v18, a3: v19[0]);
          (*(void (__thiscall **)(volatile int *, int, int, _DWORD, _DWORD))(v25.pData[1].RefCount + 32))(
            a1: &v25.pData[1].RefCount,
            a2: *(_DWORD *)(a1 + 8) + 120,
            a3: a1,
            a4: 0,
            a5: 0);
          v14 = *(void (**)(void))(**(_DWORD **)(a1 + 12) + 20);
        }
        v14();
      }
      break;
    default:
      break;
  }
  v15 = v24.HeapTypeBits & 0xFFFFFFFC;
  result = InterlockedExchangeAdd(Addend: (volatile LONG *)((v24.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) - 1;
  if ( result == 0 )
    return ((int (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v15);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122750
// Name: public: static void GASSharedObjectProto::Clear(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSharedObjectProto::Clear(unsigned int a1@<ebx>, int a2@<edi>, GASFnCall *a3)
{
  GASFnCall v3; // edi
  GFxAmpAppControlInterface *p_cxItem; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v6; // ebx
  struct GFxMovieRoot *v7; // eax
  _IMAGE_SYMBOL_EX v8; // [esp-10h] [ebp-20h]
  _BYTE v9[24]; // [esp-10h] [ebp-20h]
  IShaderAPI *v10; // [esp+8h] [ebp-8h]
  GRefCountNTSImpl *v11; // [esp+Ch] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Cu) )
  {
    v8.SectionNumber = a2;
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GFxAmpAppControlInterface *)&v3[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        v8.Value = a1;
        v8.N.Name.Long = (unsigned int)GASEnvironment::OperatorNew(
                                         this: (__vc_attributes::idl_quoteAttribute *)a3[6],
                                         a2: (int)p_cxItem,
                                         a3: *(struct GASObject **)(a3[6][3].cbSize + 680),
                                         a4: (const struct GASString *)(a3[6][3].cbSize + 12),
                                         nargs: 0,
                                         argsTopOff: -1);
        *(_DWORD *)&v9[20] = v8.N.Name.Long;
        v8.N.Name.Short = (unsigned int)a3[6];
        GASSharedObject::SetDataObject(this: p_cxItem, penv: v8);
        MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a3[6]);
        v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                             a1: (int)MovieRoot + 8,
                             a2: 37);
        if ( v6 != nullptr )
        {
          v7 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a3[6]);
          v10 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v7 + 2) + 12))(a1: (int)v7 + 8, a2: 10);
          v11 = (GRefCountNTSImpl *)((int (__thiscall *)(IShaderAPI *, GFxAmpAppControlInterface *, GFxAmpAppControlInterface *, IShaderAPI *))v6->GetSceneFogMode)(
                                      a1: v6,
                                      a2: &p_cxItem[13],
                                      a3: &p_cxItem[14],
                                      a4: v10);
          if ( v10 != nullptr )
            GRefCountImpl::Release(this: v10);
          *(_DWORD *)&v9[4] = v11;
          GASSharedObject::Flush(this: p_cxItem, penv: (ID3DXFont *)a3[6], a3: *(_IMAGE_SYMBOL_EX *)&v9[4]);
          if ( v11 != nullptr )
            GRefCountNTSImpl::Release(this: v11);
          GRefCountImpl::Release(this: v6);
        }
        if ( *(_DWORD *)&v9[20] != 0 )
          GRefCountBaseGC<323>::Release(a1: *(int *)&v9[20], a2: (int)p_cxItem);
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "SharedObject", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122850
// Name: public: static void GASSharedObjectProto::Flush(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASSharedObjectProto::Flush(unsigned int a1@<ebx>, unsigned int a2@<edi>, GASFnCall *a3)
{
  GASFnCall v3; // ebx
  GFxAmpAppControlInterface *p_cxItem; // ebx
  struct GFxMovieRoot *MovieRoot; // eax
  IShaderAPI *v6; // edi
  struct GFxMovieRoot *v7; // eax
  IShaderAPI *v8; // esi
  _IMAGE_SYMBOL_EX v9; // [esp-Ch] [ebp-14h]
  GRefCountNTSImpl *v10; // [esp+4h] [ebp-4h]

  if ( GASFnCall::CheckThisPtr(this: a3, type: 0x2Cu) )
  {
    v9.Value = a1;
    v3 = a3[2];
    if ( v3 != nullptr )
    {
      p_cxItem = (GFxAmpAppControlInterface *)&v3[-1].cxItem;
      if ( p_cxItem != nullptr )
      {
        v9.N.Name.Long = a2;
        MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a3[6]);
        v6 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(
                             a1: (int)MovieRoot + 8,
                             a2: 37);
        if ( v6 != nullptr )
        {
          v7 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a3[6]);
          v8 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v7 + 2) + 12))(a1: (int)v7 + 8, a2: 10);
          *(_DWORD *)&v9.Type = ((int (__thiscall *)(IShaderAPI *, GFxAmpAppControlInterface *, GFxAmpAppControlInterface *, IShaderAPI *))v6->GetSceneFogMode)(
                                  a1: v6,
                                  a2: &p_cxItem[13],
                                  a3: &p_cxItem[14],
                                  a4: v8);
          if ( v8 != nullptr )
            GRefCountImpl::Release(this: v8);
          v9.N.Name.Short = *(_DWORD *)&v9.Type;
          GASSharedObject::Flush(this: p_cxItem, penv: (ID3DXFont *)a3[6], a3: v9);
          if ( v10 != nullptr )
            GRefCountNTSImpl::Release(this: v10);
          GRefCountImpl::Release(this: v6);
        }
      }
    }
  }
  else
  {
    GASFnCall::ThisPtrError(this: a3, a2: "SharedObject", a3: nullptr, a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122CE0
// Name: public: static class GASFunctionRef GASSharedObjectCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASSharedObjectCtorFunction::Register(
        const ID3D11BlendState *pgc,
        struct GASFunctionRef *a2,
        _KCRM_MARSHAL_HEADER *pgca)
{
  vc_attributes::PreRangeAttribute *v3; // edi
  unsigned int VersionMajor; // ecx
  int (__thiscall *v5)(unsigned int, int, _KCRM_MARSHAL_HEADER **); // eax
  GASCFunctionObject *v6; // eax
  GASCFunctionObject *v7; // ebx
  void *v8; // ecx
  GASCFunctionObject *v9; // eax
  struct GASFunctionRef *v10; // ebx
  const char *MaxVal; // ecx
  int (__thiscall *v12)(const char *, int, struct GASFunctionRef **); // eax
  int v13; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v15; // eax
  int p_MinVal; // edi
  GASValue v17[4]; // [esp+Ch] [ebp-20h] BYREF
  D3DXVECTOR2 result; // [esp+1Ch] [ebp-10h] BYREF
  void (__thiscall **v19)(_DWORD *, D3DXVECTOR2 *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v20; // [esp+28h] [ebp-4h]

  v3 = (vc_attributes::PreRangeAttribute *)pgca;
  VersionMajor = pgca[41].VersionMajor;
  LODWORD(result.x) = pgca;
  LOBYTE(result.y) = 8;
  v5 = *(int (__thiscall **)(unsigned int, int, _KCRM_MARSHAL_HEADER **))(*(_DWORD *)VersionMajor + 40);
  pgca = (_KCRM_MARSHAL_HEADER *)323;
  v6 = (GASCFunctionObject *)v5(a1: VersionMajor, a2: 60, a3: &pgca);
  v7 = v6;
  if ( v6 != nullptr )
  {
    GASCFunctionObject::GASCFunctionObject(
      this: v6,
      func: (_REASON_CONTEXT *)&result,
      a3: (void (__cdecl *)(const struct GASFnCall *))GASSharedObjectCtorFunction::GlobalCtor);
    v7->dwSize = (unsigned int)&GASSharedObjectCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
    v7->cLineHeight = (unsigned int)&GASSharedObjectCtorFunction::`vftable'{for `GASObjectInterface'};
    v7[1].rcDocument.left = 0;
    GASNameFunction::AddConstMembers(
      pobj: v8,
      psc: (int)&v7->cLineHeight,
      psca: (CTSQueue<CFunctor *,0,1>::Node_t *)&result,
      a4: (struct GASObject **)GASSharedObjectCtorFunction::StaticFunctionTable,
      a5: 7);
    v9 = v7;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = a2;
  *(_DWORD *)a2 = v9;
  *((_BYTE *)v10 + 8) = 0;
  *((_DWORD *)v10 + 1) = 0;
  MaxVal = v3[54].MaxVal;
  v12 = *(int (__thiscall **)(const char *, int, struct GASFunctionRef **))(*(_DWORD *)MaxVal + 40);
  a2 = (struct GASFunctionRef *)323;
  v13 = v12(a1: MaxVal, a2: 92, a3: &a2);
  if ( v13 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: v3,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASSharedObject,GASEnvironment>::GASPrototype<GASSharedObject,GASEnvironment>(
      this: (D3DXVECTOR2 *)v13,
      &result,
      psc: Prototype,
      psc_8: (unsigned int)v10);
    *(_DWORD *)v13 = &GASSharedObjectProto::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v13 + 16) = &GASPrototype<GASSharedObject,GASEnvironment>::`vftable'{for `GASObjectInterface'};
    *(_DWORD *)(v13 + 60) = &GASSharedObjectProto::`vftable';
    HIBYTE(pgca) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v13 + 60),
      a2: v13,
      flags: (vc_attributes::PreRangeAttribute **)&result,
      flags_4: (const struct GASNameFunction *)&GASSharedObjectProto::FunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&pgca + 3));
  }
  else
  {
    v13 = 0;
  }
  if ( v13 != 0 )
    *(_DWORD *)(v13 + 8) = (*(_DWORD *)(v13 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v3, a2: (int)v3, a3: 44, a4: v13);
  v20 = v3[56].MaxVal + 16;
  HIBYTE(pgca) = 0;
  v19 = (void (__thiscall **)(_DWORD *, D3DXVECTOR2 *, int, GASValue *, char *))(*v20 + 40);
  v15 = GASValue::GASValue(this: v17, a2: (int)v3, a3: v10);
  p_MinVal = (int)&v3[15].MinVal;
  (*v19)(a1: v20, a2: &result, a3: p_MinVal, a4: v15, a5: (char *)&pgca + 3);
  GASValue::~GASValue(this: v17, a2: p_MinVal);
  if ( v13 != 0 )
    GRefCountBaseGC<323>::Release(a1: v13, a2: p_MinVal);
}

//------------------------------------------------------------------------------
// Address: 0x10122E70
// Name: private: static void GASSharedObjectCtorFunction::GetLocal(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSharedObjectCtorFunction::GetLocal(unsigned int a1@<ebx>, GASFnCall *result)
{
  tagRID_DEVICE_INFO_KEYBOARD *v3; // ebx
  unsigned __int8 *v4; // eax
  int *ConstStringNode; // ebx
  tagRID_DEVICE_INFO_KEYBOARD *v6; // edi
  unsigned __int8 *v7; // eax
  int v8; // eax
  int *v9; // edi
  int v10; // eax
  int v11; // edi
  int Index; // eax
  int m_nGrowSize; // eax
  LONG (__stdcall *v14)(volatile LONG *, LONG); // edi
  void *v15; // esi
  void *v16; // esi
  int v17; // eax
  GFxAmpAppControlInterface *v18; // edi
  GASValue *v19; // esi
  int v20; // eax
  void *v21; // esi
  struct GASObject *v22; // eax
  GASEnvironment *v23; // ecx
  int v24; // edi
  struct GFxMovieRoot *MovieRoot; // eax
  struct GFxMovieRoot *v26; // eax
  IShaderAPI *v27; // eax
  IShaderAPI *v28; // ebx
  struct GASObject *v29; // ebx
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  bool v33; // zf
  GASValue *v34; // esi
  int v35; // eax
  void *v36; // esi
  void *v37; // esi
  int v38; // ecx
  _IMAGE_SYMBOL_EX v39; // [esp-Ch] [ebp-6Ch]
  unsigned int v40; // [esp-8h] [ebp-68h]
  IShaderAPI v41; // [esp+8h] [ebp-58h] BYREF
  int v42; // [esp+Ch] [ebp-54h]
  GASEnvironment *v43; // [esp+10h] [ebp-50h]
  struct GASObject *v44; // [esp+14h] [ebp-4Ch]
  void *v45; // [esp+18h] [ebp-48h]
  int v46; // [esp+1Ch] [ebp-44h]
  int v47; // [esp+20h] [ebp-40h]
  char v48; // [esp+24h] [ebp-3Ch]
  char className[4]; // [esp+28h] [ebp-38h] BYREF
  int v50; // [esp+2Ch] [ebp-34h]
  char v51; // [esp+30h] [ebp-30h]
  int v52; // [esp+34h] [ebp-2Ch] BYREF
  struct GASObject *v53; // [esp+38h] [ebp-28h]
  CD3D10_BUFFER_DESC *v54; // [esp+3Ch] [ebp-24h]
  GFxAmpAppControlInterface *v55; // [esp+40h] [ebp-20h]
  int v56; // [esp+44h] [ebp-1Ch] BYREF
  int *v57; // [esp+48h] [ebp-18h] BYREF
  int *v58; // [esp+4Ch] [ebp-14h]
  CUtlMemory<CImagePacker,int> v59; // [esp+50h] [ebp-10h] BYREF
  char v60; // [esp+5Fh] [ebp-1h]
  IShaderAPI *fn; // [esp+68h] [ebp+8h]

  if ( (int)result[7] < 1 )
    return;
  v39.Value = a1;
  v3 = (tagRID_DEVICE_INFO_KEYBOARD *)result[6];
  v4 = (unsigned __int8 *)GASFnCall::Arg(this: result, a2: 0);
  GASValue::ToStringImpl(this: v4, a2: (int *)&v57, a3: v3, precision: -1, debug: false);
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(result[6][3].cbSize + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem,
                             a3: 0,
                             a4: 0);
  ++ConstStringNode[2];
  v58 = ConstStringNode;
  if ( (int)result[7] > 1 )
  {
    v6 = (tagRID_DEVICE_INFO_KEYBOARD *)result[6];
    v7 = (unsigned __int8 *)GASFnCall::Arg(this: result, a2: 1);
    GASValue::ToStringImpl(this: v7, a2: &v56, a3: v6, precision: -1, debug: false);
    v8 = v56;
    ++*(_DWORD *)(v56 + 8);
    v33 = ConstStringNode[2]-- == 1;
    v9 = (int *)v8;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
    v10 = v56;
    v33 = (*(_DWORD *)(v56 + 8))-- == 1;
    v58 = v9;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v10);
    ConstStringNode = v9;
  }
  GString::GString(this: (GString *)&v59, src: *v57);
  GString::GString(this: (GString *)&v59.m_nAllocationCount, src: *ConstStringNode);
  v59.m_nGrowSize = (int)GASStringManager::CreateStringNode(
                           this: *(GASStringManager **)(result[6][3].cbSize + 636),
                           result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v59.m_nAllocationCount & 0xFFFFFFFC) + 8),
                           length: *(_DWORD *)(v59.m_nAllocationCount & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++*(_DWORD *)(v59.m_nGrowSize + 8);
  GASString::operator+=(this: (char ***)&v59.m_nGrowSize, a2: ":");
  GASString::operator+=(this: (char ***)&v59.m_nGrowSize, a2: (char *)(((int)v59.m_pMemory & 0xFFFFFFFC) + 8));
  GASEnvironment::GetConstructor(this: (__vc_attributes::async_uuidAttribute *)result[6], className, a3: 44);
  v11 = *(_DWORD *)(*(_DWORD *)className + 56);
  v54 = (CD3D10_BUFFER_DESC *)(*(_DWORD *)className + 56);
  if ( v11 != 0 )
  {
    v40 = *(_DWORD *)(v59.m_nGrowSize + 12) & *(_DWORD *)(v11 + 4);
    v60 = 0;
    Index = GHashSetBase<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>::findIndexCore<GASString>(
              this: (unsigned int *)(*(_DWORD *)className + 56),
              key: (_IMAGE_SYMBOL_EX *)&v59.m_nGrowSize,
              hashValue: v40);
    if ( Index >= 0 )
    {
      v11 += 16 * Index + 12;
      if ( v11 != 0 && v11 != -4 )
      {
        GASValue::SetAsObject(this: (GASValue *)result[1], a2: *(struct GASObject **)(v11 + 8));
        if ( (v51 & 2) == 0 && *(_DWORD *)className != 0 )
          GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: v11);
        *(_DWORD *)className = 0;
        if ( (v51 & 1) == 0 && v50 != 0 )
          GRefCountBaseGC<323>::Release(a1: v50, a2: v11);
        m_nGrowSize = v59.m_nGrowSize;
        v50 = 0;
        v33 = (*(_DWORD *)(v59.m_nGrowSize + 8))-- == 1;
        if ( v33 )
          GASStringNode::ReleaseNode(a1: m_nGrowSize);
        v14 = InterlockedExchangeAdd;
        v15 = (void *)(v59.m_nAllocationCount & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v59.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
LABEL_22:
        v16 = (void *)((int)v59.m_pMemory & 0xFFFFFFFC);
        if ( v14(Addend: (volatile LONG *)(((int)v59.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
        v33 = ConstStringNode[2]-- == 1;
        if ( v33 )
          GASStringNode::ReleaseNode(a1: (int)ConstStringNode);
        v17 = (int)v57;
        v33 = v57[2]-- == 1;
        if ( v33 )
          GASStringNode::ReleaseNode(a1: v17);
        return;
      }
    }
  }
  v18 = (GFxAmpAppControlInterface *)GASEnvironment::OperatorNew(
                                       this: (__vc_attributes::idl_quoteAttribute *)result[6],
                                       a2: v11,
                                       a3: *(struct GASObject **)(result[6][3].cbSize + 680),
                                       a4: (const struct GASString *)(result[6][3].cbSize + 184),
                                       nargs: 0,
                                       argsTopOff: -1);
  v55 = v18;
  if ( GASSharedObject::SetNameAndLocalPath(
         this: (GASSharedObject *)v18,
         a2: &v59,
         src: (struct GString *)&v59.m_nAllocationCount) == 0 )
  {
    v19 = (GASValue *)result[1];
    GASValue::DropRefs(this: v19, a2: (int)v18);
    *(_BYTE *)v19 = 1;
    if ( v18 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v18, a2: (int)v18);
    if ( (v51 & 2) == 0 && *(_DWORD *)className != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: (int)v18);
    *(_DWORD *)className = 0;
    if ( (v51 & 1) == 0 && v50 != 0 )
      GRefCountBaseGC<323>::Release(a1: v50, a2: (int)v18);
    v20 = v59.m_nGrowSize;
    v50 = 0;
    v33 = (*(_DWORD *)(v59.m_nGrowSize + 8))-- == 1;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v20);
    v14 = InterlockedExchangeAdd;
    v21 = (void *)(v59.m_nAllocationCount & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v59.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
    goto LABEL_22;
  }
  v22 = GASEnvironment::OperatorNew(
          this: (__vc_attributes::idl_quoteAttribute *)result[6],
          a2: (int)v18,
          a3: *(struct GASObject **)(result[6][3].cbSize + 680),
          a4: (const struct GASString *)(result[6][3].cbSize + 12),
          nargs: 0,
          argsTopOff: -1);
  v23 = (GASEnvironment *)result[6];
  v24 = (int)v22;
  v42 = 1;
  v41.__vftable = (IShaderAPI_vtbl *)&GASSharedObjectLoader::`vftable';
  v43 = v23;
  v44 = v22;
  v45 = nullptr;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  MovieRoot = GASEnvironment::GetMovieRoot(this: v23);
  fn = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)MovieRoot + 2) + 12))(a1: (int)MovieRoot + 8, a2: 37);
  v26 = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)result[6]);
  v27 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v26 + 2) + 12))(a1: (int)v26 + 8, a2: 10);
  v28 = v27;
  if ( v27 != nullptr )
    GRefCountImpl::Release(this: v27);
  if ( fn != nullptr
    && ((unsigned __int8 (__thiscall *)(IShaderAPI *, CUtlMemory<CImagePacker,int> *, int *, IShaderAPI *, IShaderAPI *))fn->GetLightmapDimensions)(
         a1: fn,
         a2: &v59,
         a3: &v59.m_nAllocationCount,
         a4: &v41,
         a5: v28) != 0 )
  {
    v29 = (struct GASObject *)v55;
    v39.N.Name.Long = v24;
    v39.N.Name.Short = (unsigned int)result[6];
    GASSharedObject::SetDataObject(this: v55, penv: v39);
    GASValue::SetAsObject(this: (GASValue *)result[1], a2: v29);
    if ( v29 != nullptr )
      v29[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&v29[1].pNode->pNext + 1) & 0x8FFFFFFF);
    v53 = v29;
    v52 = (int)&GASSharedObjectPtr::`vftable';
    GHash<GASString,GASSharedObjectPtr,GASStringHashFunctor,GAllocatorLH<GASString,323>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>,GHashSet<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry_GC<GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>,GHashNode<GASString,GASSharedObjectPtr,GASStringHashFunctor>::NodeHashF>>>::Add(
      result: v54,
      key: (_IMAGE_SYMBOL_EX *)&v59.m_nGrowSize,
      a3: (int)&v52);
    v52 = (int)&GASSharedObjectPtr::`vftable';
    if ( v53 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v53, a2: v24);
    GRefCountImpl::Release(this: fn);
    GASSharedObjectLoader::~GASSharedObjectLoader(this: &v41);
    if ( v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: v24);
    if ( v29 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v29, a2: v24);
    if ( (v51 & 2) == 0 && *(_DWORD *)className != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: v24);
    *(_DWORD *)className = 0;
    if ( (v51 & 1) == 0 && v50 != 0 )
      GRefCountBaseGC<323>::Release(a1: v50, a2: v24);
    v30 = v59.m_nGrowSize;
    v50 = 0;
    v33 = (*(_DWORD *)(v59.m_nGrowSize + 8))-- == 1;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v30);
    GString::~GString(this: (GString *)&v59.m_nAllocationCount);
    GString::~GString(this: (GString *)&v59);
    v31 = (int)v58;
    v33 = v58[2]-- == 1;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v31);
    v32 = (int)v57;
    v33 = v57[2]-- == 1;
  }
  else
  {
    v34 = (GASValue *)result[1];
    GASValue::DropRefs(this: v34, a2: v24);
    *(_BYTE *)v34 = 1;
    if ( fn != nullptr )
      GRefCountImpl::Release(this: fn);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v45);
    GRefCountImplCore::~GRefCountImplCore(this: &v41);
    if ( v24 != 0 )
      GRefCountBaseGC<323>::Release(a1: v24, a2: v24);
    if ( v55 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v55, a2: v24);
    if ( (v51 & 2) == 0 && *(_DWORD *)className != 0 )
      GRefCountBaseGC<323>::Release(a1: *(int *)className, a2: v24);
    *(_DWORD *)className = 0;
    if ( (v51 & 1) == 0 && v50 != 0 )
      GRefCountBaseGC<323>::Release(a1: v50, a2: v24);
    v35 = v59.m_nGrowSize;
    v50 = 0;
    v33 = (*(_DWORD *)(v59.m_nGrowSize + 8))-- == 1;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v35);
    v36 = (void *)(v59.m_nAllocationCount & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v59.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v36);
    v37 = (void *)((int)v59.m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v59.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v37);
    v38 = (int)v58;
    v33 = v58[2]-- == 1;
    if ( v33 )
      GASStringNode::ReleaseNode(a1: v38);
    v32 = (int)v57;
    v33 = v57[2]-- == 1;
  }
  if ( v33 )
    GASStringNode::ReleaseNode(a1: v32);
}

//------------------------------------------------------------------------------
// Address: 0x101C41AE
// Name: public: long D3DXShader::CPreProcessor::End(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::End(D3DXShader::CPreProcessor *this)
{
  int result; // eax
  D3DXShader::CPPBlock *v3; // ecx
  int *v4; // eax
  int v5; // eax
  _DWORD v6[8]; // [esp+4h] [ebp-20h] BYREF

  if ( *((_DWORD *)this + 26) == 0 )
    return -2005530516;
  while ( 1 )
  {
    result = D3DXShader::CPreProcessor::GetToken(this, a2: (struct D3DXShader::D3DXTOKEN *)v6);
    if ( result < 0 )
      break;
    if ( v6[0] == 13 )
    {
      v3 = *((D3DXShader::CPPBlock **)this + 26);
      *((_DWORD *)this + 26) = *((_DWORD *)v3 + 1);
      *((_DWORD *)v3 + 1) = 0;
      D3DXShader::CPPBlock::`scalar deleting destructor'(this: v3, a2: 1);
      v4 = *((int **)this + 26);
      if ( v4 != nullptr )
        v5 = *v4;
      else
        v5 = 1;
      *((_DWORD *)this + 166) = v5;
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E54CF
// Name: protected: long D3DXShader::CProgram::CompactPool_End(struct D3DXShader::_D3DXCP_DATA __near *)
// Source: semantic_flat_class
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactPool_End(D3DXShader::CProgram *this, void **a2)
{
  free(pMem: a2[2]);
  free(pMem: a2[3]);
  free(pMem: a2[4]);
  free(pMem: a2[5]);
  free(pMem: a2[6]);
  free(pMem: a2[7]);
  free(pMem: a2[8]);
  free(pMem: a2[12]);
  free(pMem: a2[13]);
  free(pMem: a2[14]);
  free(pMem: a2[15]);
  free(pMem: a2[16]);
  free(pMem: a2[17]);
  free(pMem: a2[19]);
  free(pMem: a2[20]);
  free(pMem: a2[21]);
  free(pMem: a2[22]);
  memset(a2, 0, 0x64u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C420A
// Name: public: D3DXShader::CTErrors::CTErrors(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CTErrors *__thiscall D3DXShader::CTErrors::CTErrors(D3DXShader::CTErrors *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C422A
// Name: public: D3DXShader::CTErrors::~CTErrors(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CTErrors::~CTErrors(void **this)
{
  void *v2; // edi

  if ( *this != nullptr )
  {
    do
    {
      v2 = *(void **)*this;
      free(pMem: *this);
      *this = v2;
    }
    while ( v2 != nullptr );
  }
  free(pMem: *(this + 6));
  free(pMem: *(this + 7));
}

//------------------------------------------------------------------------------
// Address: 0x101C425B
// Name: protected: long D3DXShader::CTErrors::Push(unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTErrors::Push(D3DXShader::CTErrors *this, unsigned int a2, unsigned int *a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  int v9; // edx
  void *v10; // eax
  int v11; // eax
  int v12; // eax
  void *v13; // edi
  unsigned int i; // edx
  int v15; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  void *v18; // [esp+10h] [ebp-8h]
  unsigned int v19; // [esp+14h] [ebp-4h]

  v4 = *((_DWORD *)this + 5);
  v5 = v4;
  v6 = 0;
  v7 = v4 >> 1;
  v17 = 0;
  v19 = v4 >> 1;
  if ( v4 == 0 )
    goto LABEL_8;
  do
  {
    v8 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v7);
    if ( a2 <= v8 )
    {
      if ( a2 >= v8 )
        break;
      v5 = v7;
    }
    else
    {
      v6 = v7 + 1;
    }
    v7 = (v5 + v6) >> 1;
    v19 = v7;
  }
  while ( v6 < v5 );
  if ( v6 >= v5 )
  {
LABEL_8:
    if ( v4 == (v4 & -v4) )
    {
      if ( v4 != 0 )
        v9 = 2 * v4;
      else
        v9 = 1;
      v10 = MemAlloc_Alloc(nSize: 4 * v9);
      v18 = v10;
      if ( v10 == nullptr
        || ((qmemcpy(v10, *((const void **)this + 7), 4 * *((_DWORD *)this + 5)),
             free(pMem: *((void **)this + 7)),
             *((_DWORD *)this + 7) = v18,
             (v11 = *((_DWORD *)this + 5)) == 0)
          ? (v12 = 1)
          : (v12 = 2 * v11),
            (v13 = MemAlloc_Alloc(nSize: 4 * v12)) == nullptr) )
      {
        v17 = -2147024882;
        goto LABEL_25;
      }
      qmemcpy(v13, *((const void **)this + 6), 4 * *((_DWORD *)this + 5));
      free(pMem: *((void **)this + 6));
      *((_DWORD *)this + 6) = v13;
      v7 = v19;
    }
    for ( i = *((_DWORD *)this + 5); ; --i )
    {
      v15 = *((_DWORD *)this + 6);
      if ( i <= v7 )
        break;
      *(_DWORD *)(v15 + 4 * i) = *(_DWORD *)(v15 + 4 * i - 4);
      *(_DWORD *)(*((_DWORD *)this + 7) + 4 * i) = *(_DWORD *)(*((_DWORD *)this + 7) + 4 * i - 4);
    }
    *(_DWORD *)(v15 + 4 * v7) = a2;
    *(_DWORD *)(*((_DWORD *)this + 7) + 4 * v7) = 1;
    ++*((_DWORD *)this + 5);
  }
  if ( a3 != nullptr )
    *a3 = v7;
LABEL_25:
  free(pMem: nullptr);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x101C439E
// Name: public: long D3DXShader::CTErrors::PreformattedError(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTErrors::PreformattedError(D3DXShader::CTErrors *this, const char *a2)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v3 = strlen(a2);
  v4 = v3 + 1;
  v5 = MemAlloc_Alloc(nSize: v3 + 5);
  if ( v5 == nullptr )
    return -2147024882;
  *v5 = *(_DWORD *)this;
  *((_DWORD *)this + 1) += v4 - 1;
  *(_DWORD *)this = v5;
  qmemcpy(v5 + 1, a2, v4);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C43F8
// Name: public: long D3DXShader::CTErrors::GetErrorBuffer(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTErrors::GetErrorBuffer(D3DXShader::CTErrors *this, struct ID3DXBuffer **a2)
{
  int v3; // eax
  int result; // eax
  _BYTE *v5; // eax
  const char *i; // edx
  unsigned int v7; // ecx

  if ( a2 != nullptr )
  {
    v3 = *((_DWORD *)this + 1);
    if ( v3 != 0 )
    {
      result = D3DXCore::CBuffer::Create(a1: v3 + 1, (struct D3DXCore::CBuffer **)a2);
      if ( result < 0 )
        return result;
      v5 = (char *)(*a2)->GetBufferPointer(this: *a2) + *((_DWORD *)this + 1);
      *v5 = 0;
      for ( i = *(const char **)this; i != nullptr; i = *(const char **)i )
      {
        v7 = strlen(i + 4);
        v5 -= v7;
        qmemcpy(v5, i + 4, v7);
      }
    }
    else
    {
      *a2 = nullptr;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C4466
// Name: public: unsigned int D3DXShader::CTErrors::GetErrorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTErrors::GetErrorCount(D3DXShader::CTErrors *this)
{
  return *((_DWORD *)this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101C446A
// Name: public: D3DXShader::CTokenize::CTokenize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CTokenize *__thiscall D3DXShader::CTokenize::CTokenize(D3DXShader::CTokenize *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 1;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C4484
// Name: public: long D3DXShader::CTokenize::Initialize(void const __near *,unsigned int,char const __near *,unsigned int,class D3DXCore::CAlloc __near *,class D3DXShader::CTErrors __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::Initialize(
        D3DXShader::CTokenize *this,
        const char *a2,
        unsigned int a3,
        const char *a4,
        unsigned int a5,
        struct D3DXCore::CAlloc *a6,
        struct D3DXShader::CTErrors *a7)
{
  unsigned int v7; // eax

  if ( a6 == nullptr || a7 == nullptr )
    return -2147467259;
  v7 = a3;
  if ( a3 == -1 )
  {
    if ( a2 != nullptr )
      v7 = strlen(a2);
    else
      v7 = 0;
  }
  if ( a2 == nullptr && v7 != 0 )
    return -2147467259;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 6) = a4;
  *((_DWORD *)this + 7) = a5;
  *((_DWORD *)this + 11) = a6;
  *((_DWORD *)this + 1) = &a2[v7];
  *((_DWORD *)this + 12) = a7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C44EE
// Name: public: int D3DXShader::CTokenize::SkipToEOL(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::SkipToEOL(char **this)
{
  unsigned int v1; // esi
  char *v2; // eax
  char v3; // bl
  unsigned int v4; // eax

  v1 = (unsigned int)*(this + 1);
  if ( (unsigned int)*this >= v1 )
    return 0;
  while ( 1 )
  {
    v2 = *this;
    v3 = **this;
    if ( v3 == 10 )
      return 1;
    if ( v3 != 92 )
      goto LABEL_12;
    if ( (unsigned int)(v2 + 1) < v1 && v2[1] == 10 )
    {
      v4 = (unsigned int)(v2 + 2);
    }
    else
    {
      if ( (unsigned int)(v2 + 2) >= v1 || v2[1] != 13 || v2[2] != 10 )
      {
LABEL_12:
        v4 = (unsigned int)(v2 + 1);
        goto LABEL_13;
      }
      v4 = (unsigned int)(v2 + 3);
    }
    ++*(this + 7);
LABEL_13:
    *this = (char *)v4;
    if ( v4 >= (unsigned int)*(this + 1) )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C4549
// Name: protected: unsigned int D3DXShader::CTokenize::LexFloat(char const __near *,double __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexFloat(D3DXShader::CTokenize *this, const char *a2, double *a3)
{
  const char *i; // ebx
  unsigned int v5; // eax
  _BYTE *v6; // esi
  void *v7; // esp
  char v9[12]; // [esp+0h] [ebp-10h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  v10 = 0;
  i = a2;
  if ( (unsigned int)a2 < *((_DWORD *)this + 1) && isdigit(c: *a2) != 0 )
  {
    do
      ++i;
    while ( (unsigned int)i < *((_DWORD *)this + 1) && isdigit(c: *i) != 0 );
    v5 = *((_DWORD *)this + 1);
    if ( (unsigned int)i < v5 && *i == 46 )
    {
      if ( (unsigned int)++i < v5 )
      {
        do
        {
          if ( isdigit(c: *i) == 0 )
            break;
          ++i;
        }
        while ( (unsigned int)i < *((_DWORD *)this + 1) );
      }
    }
    else
    {
      v10 = 1;
    }
  }
  else
  {
    if ( (unsigned int)(a2 + 1) >= *((_DWORD *)this + 1) || *a2 != 46 || isdigit(c: a2[1]) == 0 )
      return 0;
    for ( i = a2 + 2; (unsigned int)i < *((_DWORD *)this + 1) && isdigit(c: *i) != 0; ++i )
      ;
  }
  v6 = i + 1;
  if ( (unsigned int)(i + 1) < *((_DWORD *)this + 1) && tolower(c: *i) == 101 && isdigit(c: (char)*v6) != 0 )
  {
    for ( i += 2; (unsigned int)i < *((_DWORD *)this + 1) && isdigit(c: *i) != 0; ++i )
      ;
    goto LABEL_37;
  }
  if ( (unsigned int)(i + 2) < *((_DWORD *)this + 1) && tolower(c: *i) == 101 && *v6 == 45 && isdigit(c: i[2]) != 0 )
  {
    for ( i += 3; (unsigned int)i < *((_DWORD *)this + 1) && isdigit(c: *i) != 0; ++i )
      ;
    goto LABEL_37;
  }
  if ( v10 != 0 )
    return 0;
LABEL_37:
  if ( a3 != nullptr )
  {
    v10 = i - a2;
    v7 = alloca(i - a2 + 1);
    qmemcpy(v9, a2, i - a2);
    v9[i - a2] = 0;
    *a3 = atof(nptr: v9);
  }
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x101C46D4
// Name: protected: unsigned int D3DXShader::CTokenize::LexIdentifier(char const __near *,char const __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexIdentifier(
        D3DXShader::CTokenize *this,
        const char *a2,
        const char **a3)
{
  const char *i; // edi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax

  if ( (unsigned int)a2 >= *((_DWORD *)this + 1) || isalpha(c: *a2) == 0 && *a2 != 95 )
    return 0;
  for ( i = a2 + 1; (unsigned int)i < *((_DWORD *)this + 1) && (isalnum(c: *i) != 0 || *i == 95); ++i )
    ;
  v5 = i - a2;
  v6 = D3DXCore::CAlloc::Alloc(this: *((D3DXCore::CAlloc **)this + 11), a2: v5 + 1, dwSize: 1u);
  if ( v6 == nullptr )
    return 0;
  qmemcpy(v6, a2, v5);
  v6[v5] = 0;
  *a3 = (const char *)v6;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101C4758
// Name: protected: unsigned int D3DXShader::CTokenize::LexOperator(char const __near *,char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexOperator(D3DXShader::CTokenize *this, const char *a2, char *a3)
{
  const char *v4; // edx
  char v5; // bl
  char v6; // cl
  char v7; // dl
  char *v8; // ecx
  char *v12; // [esp+1Ch] [ebp+Ch]

  *(_DWORD *)a3 = 0;
  *a3 = *a2;
  v4 = a2 + 1;
  v12 = *((char **)this + 1);
  if ( a2 + 1 >= v12 )
    return 1;
  v5 = *a2;
  if ( *a2 == 35 )
  {
    v6 = *v4;
    if ( *v4 == 35 || v6 == 64 )
    {
      a3[1] = v6;
      return 2;
    }
  }
  v7 = *v4;
  if ( v5 != v7 )
  {
    if ( v7 == 61 )
    {
      if ( v5 > 47 )
      {
        if ( v5 != 60 && v5 != 62 && v5 != 94 && v5 != 124 )
          return 1;
      }
      else if ( v5 != 47 && v5 != 33 && (v5 <= 36 || v5 > 38 && (v5 <= 41 || v5 > 43 && v5 != 45)) )
      {
        return 1;
      }
      a3[1] = 61;
      return 2;
    }
    if ( v5 == 45 && v7 == 62 )
    {
      a3[1] = 62;
      return 2;
    }
    return 1;
  }
  if ( v5 <= 58 )
  {
    if ( v5 != 58 && v5 != 38 && v5 != 43 && v5 != 45 )
    {
      if ( v5 == 46 )
      {
        v8 = (char *)(a2 + 2);
        if ( a2 + 2 < v12 && *v8 == 46 )
        {
          a3[1] = v7;
          a3[2] = *v8;
          return 3;
        }
      }
      return 1;
    }
LABEL_20:
    a3[1] = v7;
    return 2;
  }
  if ( v5 != 60 )
  {
    if ( v5 == 61 )
      goto LABEL_20;
    if ( v5 != 62 )
    {
      if ( v5 != 124 )
        return 1;
      goto LABEL_20;
    }
  }
  a3[1] = v7;
  if ( (unsigned int)(a2 + 2) >= *((_DWORD *)this + 1) || a2[2] != 61 )
    return 2;
  a3[2] = 61;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x101C4866
// Name: protected: unsigned int D3DXShader::CTokenize::LexFloatSuffix(char const __near *,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexFloatSuffix(
        D3DXShader::CTokenize *this,
        const char *a2,
        struct D3DXShader::D3DXTOKEN *a3)
{
  const char *v3; // edi
  int v4; // ebx
  int v6; // eax
  int v7; // [esp-4h] [ebp-10h]

  v3 = a2;
  v4 = 5;
  if ( (unsigned int)a2 >= *((_DWORD *)this + 1) )
    return 0;
  v6 = tolower(c: *a2) - 102;
  if ( v6 == 0 )
  {
    v7 = 7;
    goto LABEL_7;
  }
  if ( v6 == 2 )
  {
    v7 = 6;
LABEL_7:
    v4 = v7;
    v3 = a2 + 1;
  }
  if ( a3 != nullptr )
    *(_DWORD *)a3 = v4;
  return v3 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x101C48B0
// Name: protected: unsigned int D3DXShader::CTokenize::LexIntegerSuffix(char const __near *,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexIntegerSuffix(
        D3DXShader::CTokenize *this,
        const char *a2,
        struct D3DXShader::D3DXTOKEN *a3)
{
  const char *i; // edi
  int v7; // [esp+Ch] [ebp-4h]
  int v8; // [esp+18h] [ebp+8h]

  v7 = 0;
  v8 = 0;
  for ( i = a2; (unsigned int)i < *((_DWORD *)this + 1); ++i )
  {
    if ( v8 != 0 || tolower(c: *i) != 117 )
    {
      if ( v7 != 0 || tolower(c: *i) != 108 )
        break;
      v7 = 1;
    }
    else
    {
      v8 = 1;
    }
  }
  if ( a3 != nullptr )
  {
    if ( v8 != 0 )
    {
      *(_DWORD *)a3 = 4;
    }
    else if ( v7 != 0 )
    {
      *(_DWORD *)a3 = 3;
    }
  }
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x101C4939
// Name: public: long D3DXShader::CTErrors::SetWarningSpecifier(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTErrors::SetWarningSpecifier(D3DXShader::CTErrors *this, unsigned int a2, unsigned int a3)
{
  int result; // eax
  char v5; // cl
  unsigned int v6; // ecx
  unsigned int v7; // edx

  result = D3DXShader::CTErrors::Push(this, a2, a3: &a2);
  if ( result >= 0 )
  {
    v5 = a3;
    if ( a3 == 255 )
    {
      v6 = 4 * a2;
      *(_DWORD *)(4 * a2 + *((_DWORD *)this + 7)) &= 0x20u;
      *(_DWORD *)(*((_DWORD *)this + 7) + v6) |= 1u;
    }
    else if ( a3 == 16 )
    {
      *(_DWORD *)(*((_DWORD *)this + 7) + 4 * a2) |= 0x10u;
    }
    else
    {
      v7 = 4 * a2;
      *(_DWORD *)(v7 + *((_DWORD *)this + 7)) &= 0xFFFFFFF0;
      *(_DWORD *)(*((_DWORD *)this + 7) + v7) |= v5 & 0xF;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C49A3
// Name: public: long D3DXShader::CTErrors::Error(struct D3DXShader::D3DXTOKEN __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CTErrors::Error(D3DXShader::CTErrors *this, const char **a2, unsigned int a3, char *format, ...)
{
  char *v4; // esi
  unsigned int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char *v11; // esi
  char string[4096]; // [esp+Ch] [ebp-1004h] BYREF
  va_list ap; // [esp+1028h] [ebp+18h] BYREF

  va_start(ap, format);
  v4 = string;
  v5 = 4094;
  if ( a2 != nullptr )
  {
    if ( a2[4] != nullptr )
    {
      v6 = _snprintf(string, count: 0xFFEu, format: "%s", a2[4]);
      if ( v6 < 0 )
        v6 = 4094;
      v4 = &string[v6];
      v5 = 4094 - v6;
    }
    v7 = (int)a2[5];
    if ( v7 == 0 )
      v7 = 1;
    v8 = _snprintf(string: v4, count: v5, format: "(%u): ", v7);
    if ( v8 < 0 )
      v8 = v5;
    v4 += v8;
    v5 -= v8;
  }
  if ( a3 != 0 )
  {
    v9 = _snprintf(string: v4, count: v5, format: "error X%u: ", a3);
    if ( v9 < 0 )
      v9 = v5;
    v4 += v9;
    v5 -= v9;
  }
  v10 = _vsnprintf(string: v4, count: v5, format, ap);
  if ( v10 < 0 )
    v10 = v5;
  v11 = &v4[v10];
  *v11 = 10;
  v11[1] = 0;
  ++*((_DWORD *)this + 2);
  return D3DXShader::CTErrors::PreformattedError(this, a2: string);
}

//------------------------------------------------------------------------------
// Address: 0x101C4A7A
// Name: public: long D3DXShader::CTErrors::Warning(struct D3DXShader::D3DXTOKEN __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CTErrors::Warning(D3DXShader::CTErrors *this, const char **a2, unsigned int a3, char *format, ...)
{
  char *v4; // esi
  unsigned int v5; // edi
  int result; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  char *v14; // esi
  _DWORD *v15; // eax
  int v16; // [esp+8h] [ebp-1010h]
  const char *v17; // [esp+Ch] [ebp-100Ch]
  unsigned int v18; // [esp+10h] [ebp-1008h] BYREF
  char string[4096]; // [esp+14h] [ebp-1004h] BYREF
  va_list ap; // [esp+1030h] [ebp+18h] BYREF

  va_start(ap, format);
  v4 = string;
  v5 = 4094;
  result = D3DXShader::CTErrors::Push(this, a2: a3, a3: &v18);
  if ( result >= 0 )
  {
    v7 = 4 * v18;
    v16 = *(_DWORD *)(4 * v18 + *((_DWORD *)this + 7));
    if ( (v16 & 0xF) == 0xF )
    {
      v17 = "error";
      v18 = (unsigned int)this + 8;
    }
    else
    {
      v18 = (unsigned int)this + 12;
      v8 = *((_DWORD *)this + 4);
      v17 = "warning";
      if ( v8 == 0 || (v16 & 0xF) == 0 || v8 < (v16 & 0xFu) || (v16 & 0x10) != 0 && (v16 & 0x20) != 0 )
        return 0;
      *(_DWORD *)(v7 + *((_DWORD *)this + 7)) |= 0x20u;
    }
    if ( a2 != nullptr )
    {
      if ( a2[4] != nullptr )
      {
        v9 = _snprintf(string, count: 0xFFEu, format: "%s", a2[4]);
        if ( v9 < 0 )
          v9 = 4094;
        v4 = &string[v9];
        v5 = 4094 - v9;
      }
      v10 = (int)a2[5];
      if ( v10 == 0 )
        v10 = 1;
      v11 = _snprintf(string: v4, count: v5, format: "(%u): ", v10);
      if ( v11 < 0 )
        v11 = v5;
      v4 += v11;
      v5 -= v11;
    }
    if ( a3 != 0 )
    {
      v12 = _snprintf(string: v4, count: v5, format: "%s X%u: ", v17, a3);
      if ( v12 < 0 )
        v12 = v5;
      v4 += v12;
      v5 -= v12;
    }
    v13 = _vsnprintf(string: v4, count: v5, format, ap);
    if ( v13 < 0 )
      v13 = v5;
    v14 = &v4[v13];
    v15 = (_DWORD *)v18;
    *v14 = 10;
    v14[1] = 0;
    ++*v15;
    return D3DXShader::CTErrors::PreformattedError(this, a2: string);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C4C08
// Name: public: long D3DXShader::CTErrors::SyntaxError(unsigned int,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTErrors::SyntaxError(
        D3DXShader::CTErrors *this,
        unsigned int a2,
        struct D3DXShader::D3DXTOKEN *a3)
{
  char *v5; // [esp+4h] [ebp-110h]
  char string[256]; // [esp+10h] [ebp-104h] BYREF

  switch ( *(_DWORD *)a3 )
  {
    case 0:
      _snprintf(string, count: 0x100u, format: "version token");
      break;
    case 1:
      v5 = (char *)a3 + 8;
      goto LABEL_13;
    case 2:
      _snprintf(string, count: 0x100u, format: "integer '%u'", *((_DWORD *)a3 + 2));
      break;
    case 3:
      _snprintf(string, count: 0x100u, format: "integer '%dl'", *((_DWORD *)a3 + 2));
      break;
    case 4:
      _snprintf(string, count: 0x100u, format: "integer '%uul'", *((_DWORD *)a3 + 2));
      break;
    case 5:
      _snprintf(string, count: 0x100u, format: "float '%g'", *((double *)a3 + 1));
      break;
    case 6:
      _snprintf(string, count: 0x100u, format: "float '%gh'", *((double *)a3 + 1));
      break;
    case 7:
      _snprintf(string, count: 0x100u, format: "float '%gf'", *((double *)a3 + 1));
      break;
    case 8:
      _snprintf(string, count: 0x100u, format: "float '%gl'", *((double *)a3 + 1));
      break;
    case 9:
      v5 = *((char **)a3 + 2);
LABEL_13:
      _snprintf(string, count: 0x100u, format: "token '%s'", v5);
      break;
    case 0xA:
      _snprintf(string, count: 0x100u, format: "string constant");
      break;
    case 0xC:
      _snprintf(string, count: 0x100u, format: "end of line");
      break;
    case 0xD:
      _snprintf(string, count: 0x100u, format: "end of file");
      break;
    default:
      _snprintf(string, count: 0x100u, format: "token");
      break;
  }
  return D3DXShader::CTErrors::Error(
           this,
           a2: (const char **)a3,
           a3: a2,
           format: "syntax error : unexpected %s",
           string);
}

//------------------------------------------------------------------------------
// Address: 0x101C4D5D
// Name: public: int D3DXShader::CTokenize::SkipWhitespace(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::SkipWhitespace(char **this)
{
  char *v2; // eax
  char v3; // dl
  int v4; // eax
  unsigned int v5; // edi
  char *v6; // eax
  char *v7; // eax
  char v8; // dl
  char *v9; // eax
  int v11; // [esp+4h] [ebp-4h]

  v11 = 0;
  if ( *this < *(this + 1) )
  {
    while ( 1 )
    {
      v2 = *this;
      v3 = **this;
      if ( v3 == 10 )
      {
        v4 = (int)(v2 + 1);
        ++*(this + 7);
        v11 = 1;
LABEL_35:
        *this = (char *)v4;
        goto LABEL_36;
      }
      if ( v3 == 32 || v3 >= 9 && v3 <= 13 )
      {
        v4 = (int)(v2 + 1);
        goto LABEL_35;
      }
      if ( v3 != 47 )
        break;
      if ( v2 + 1 < *(this + 1) && v2[1] == 47 )
        goto LABEL_10;
      v5 = (unsigned int)*(this + 1);
      if ( (unsigned int)(v2 + 1) >= v5 || v2[1] != 42 )
        break;
      v6 = v2 + 2;
      *this = v6;
      if ( (unsigned int)v6 < v5 )
      {
        do
        {
          v7 = *this;
          v8 = **this;
          if ( v8 == 42 && (unsigned int)(v7 + 1) < v5 && v7[1] == 47 )
            break;
          if ( v8 == 10 )
            ++*(this + 7);
          v9 = v7 + 1;
          *this = v9;
        }
        while ( v9 < *(this + 1) );
      }
      if ( (unsigned int)*this < v5 )
      {
        v4 = (int)(*this + 2);
        goto LABEL_35;
      }
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CTErrors *)*(this + 12),
        a2: (const char **)this + 2,
        a3: 0x3E9u,
        format: "comment continues past end of file");
LABEL_36:
      if ( *this >= *(this + 1) )
        return v11;
    }
    if ( (*(_BYTE *)(this + 10) & 2) == 0 || v3 != 59 )
    {
      if ( v3 != 92 )
        return v11;
      if ( v2 + 1 < *(this + 1) && v2[1] == 10 )
      {
        v4 = (int)(v2 + 2);
      }
      else
      {
        if ( v2 + 2 >= *(this + 1) || v2[1] != 13 || v2[2] != 10 )
          return v11;
        v4 = (int)(v2 + 3);
      }
      ++*(this + 7);
      goto LABEL_35;
    }
LABEL_10:
    D3DXShader::CTokenize::SkipToEOL(this);
    goto LABEL_36;
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x101C4E86
// Name: protected: unsigned int D3DXShader::CTokenize::LexHex(char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::LexHex(D3DXShader::CTokenize *this, const char *a2, unsigned int *a3)
{
  const char *v4; // edi
  int v5; // esi
  char v6; // al
  int v7; // esi
  int v8; // edi

  v4 = a2 + 2;
  if ( (unsigned int)(a2 + 2) >= *((_DWORD *)this + 1) || *a2 != 48 || a2[1] != 120 || isxdigit(c: *v4) == 0 )
    return 0;
  v5 = 0;
  while ( (unsigned int)v4 < *((_DWORD *)this + 1) && isxdigit(c: *v4) != 0 )
  {
    v6 = *v4;
    v7 = 16 * v5;
    if ( *v4 < 97 )
    {
      if ( v6 < 65 )
        v5 = v7 + v6 - 48;
      else
        v5 = v7 + v6 - 55;
    }
    else
    {
      v5 = v7 + v6 - 87;
    }
    ++v4;
  }
  if ( a3 != nullptr )
    *a3 = v5;
  v8 = v4 - a2;
  if ( v8 > 10 )
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)this + 12),
      a2: (const char **)this + 2,
      a3: 0x3EAu,
      format: "hex value truncated to 32bits");
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101C4F2A
// Name: protected: unsigned int D3DXShader::CTokenize::LexOctal(char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexOctal(D3DXShader::CTokenize *this, const char *a2, unsigned int *a3)
{
  unsigned int v3; // edi
  int v4; // eax
  int v5; // ecx
  const char *i; // esi
  char v7; // dl

  v3 = *((_DWORD *)this + 1);
  if ( (unsigned int)a2 >= v3 || *a2 != 48 )
    return 0;
  v4 = 0;
  v5 = 0;
  for ( i = a2 + 1; (unsigned int)i < v3; ++i )
  {
    v7 = *i;
    if ( *i < 48 || v7 > 55 )
      break;
    if ( (v4 & 0xE0000000) != 0 )
      v5 = 1;
    v4 = v7 + 8 * v4 - 48;
  }
  if ( a3 != nullptr )
    *a3 = v4;
  if ( v5 != 0 )
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)this + 12),
      a2: (const char **)this + 2,
      a3: 0x3EBu,
      format: "octal value truncated to 32bits");
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x101C4FA8
// Name: protected: unsigned int D3DXShader::CTokenize::LexDecimal(char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexDecimal(
        D3DXShader::CTokenize *this,
        const char *a2,
        unsigned int *a3)
{
  const char *v3; // ebx
  unsigned int v5; // esi
  unsigned int v6; // eax
  int v8; // [esp+8h] [ebp-4h]

  v3 = a2;
  if ( (unsigned int)a2 >= *((_DWORD *)this + 1) || isdigit(c: *a2) == 0 )
    return 0;
  v5 = 0;
  v8 = 0;
  if ( (unsigned int)a2 < *((_DWORD *)this + 1) )
  {
    do
    {
      if ( isdigit(c: *v3) == 0 )
        break;
      if ( v5 > 0x19999999 )
        v8 = 1;
      v6 = 10 * v5;
      v5 = *v3 + 10 * v5 - 48;
      if ( v5 < v6 )
        v8 = 1;
      ++v3;
    }
    while ( (unsigned int)v3 < *((_DWORD *)this + 1) );
  }
  if ( a3 != nullptr )
    *a3 = v5;
  if ( v8 != 0 )
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)this + 12),
      a2: (const char **)this + 2,
      a3: 0x3ECu,
      format: "decimal value truncated to 32bits");
  return v3 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x101C504B
// Name: protected: unsigned int D3DXShader::CTokenize::LexStringChar(char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::LexStringChar(D3DXShader::CTokenize *this, const char *a2, unsigned int *a3)
{
  unsigned int v4; // eax
  const char *v5; // edi
  const char *v7; // esi
  char v8; // cl
  const char *v9; // ebx
  int v10; // ecx
  char v11; // al
  int v12; // edi
  char v13; // al
  int v14; // edi
  unsigned int v15; // eax

  v4 = *((_DWORD *)this + 1);
  v5 = a2;
  if ( (unsigned int)a2 >= v4 )
    return 0;
  if ( *a2 != 92 || (*((_BYTE *)this + 40) & 4) != 0 )
  {
    v15 = *a2;
    v7 = a2 + 1;
LABEL_48:
    *a3 = v15;
    return v7 - v5;
  }
  v7 = a2 + 1;
  if ( (unsigned int)(a2 + 1) >= v4 )
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)this + 12),
      a2: (const char **)this + 2,
      a3: 0x3EFu,
      format: "character continues past end of file");
  v8 = *v7;
  switch ( *v7 )
  {
    case 'a':
      *a3 = 7;
      break;
    case 'b':
      *a3 = 8;
      break;
    case 'f':
      *a3 = 12;
      break;
    case 'n':
      *a3 = 10;
      break;
    case 'r':
      *a3 = 13;
      break;
    case 't':
      *a3 = 9;
      break;
    case 'v':
      *a3 = 11;
      break;
    default:
      if ( v8 >= 48 && v8 <= 55 )
      {
        v9 = *((const char **)this + 1);
        if ( a2 + 4 < v9 )
          v9 = a2 + 4;
        v10 = 0;
        while ( v7 < v9 )
        {
          v11 = *v7;
          if ( *v7 < 48 || v11 > 55 )
            break;
          v10 = v11 + 8 * v10 - 48;
          ++v7;
        }
        *a3 = v10;
        return v7 - v5;
      }
      if ( v8 == 120 )
      {
        if ( (unsigned int)(a2 + 2) < *((_DWORD *)this + 1) && isxdigit(c: a2[2]) != 0 )
        {
          v7 = a2 + 2;
          v12 = 0;
          while ( (unsigned int)v7 < *((_DWORD *)this + 1) && isxdigit(c: *v7) != 0 )
          {
            v13 = *v7;
            v14 = 16 * v12;
            if ( *v7 < 97 )
            {
              if ( v13 < 65 )
                v12 = v14 + v13 - 48;
              else
                v12 = v14 + v13 - 55;
            }
            else
            {
              v12 = v14 + v13 - 87;
            }
            ++v7;
          }
          *a3 = v12;
          v5 = a2;
          return v7 - v5;
        }
        v5 = a2;
      }
      v15 = *v7;
      v7 = a2 + 2;
      goto LABEL_48;
  }
  v7 = a2 + 2;
  return v7 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x101C51E4
// Name: protected: unsigned int D3DXShader::CTokenize::LexVersion(char const __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexVersion(
        D3DXShader::CTokenize *this,
        const char *a2,
        unsigned int *a3)
{
  bool v4; // zf
  unsigned int v6; // eax
  const char *v7; // edi
  const char *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  _DWORD v11[3]; // [esp+8h] [ebp-3Ch] BYREF
  _BYTE *v12; // [esp+14h] [ebp-30h]
  unsigned int *v13; // [esp+18h] [ebp-2Ch]
  char *v14; // [esp+1Ch] [ebp-28h] BYREF
  char v15[32]; // [esp+20h] [ebp-24h] BYREF

  v4 = (*((_BYTE *)this + 40) & 2) == 0;
  v12 = a2;
  v13 = a3;
  if ( v4 )
    return 0;
  if ( (unsigned int)(a2 + 1) >= *((_DWORD *)this + 1) )
    return 0;
  if ( isalpha(c: *a2) == 0 )
    return 0;
  if ( isalpha(c: a2[1]) == 0 )
    return 0;
  if ( (unsigned int)(a2 + 2) >= *((_DWORD *)this + 1) )
    return 0;
  if ( a2[2] != 46 )
    return 0;
  v6 = D3DXShader::CTokenize::LexDecimal(this, a2: a2 + 3, a3: (unsigned int *)&v14);
  if ( v6 == 0 )
    return 0;
  if ( (unsigned int)v14 > 0xFF )
    return 0;
  v7 = &a2[v6 + 3];
  if ( (unsigned int)v7 >= *((_DWORD *)this + 1) || *v7 != 46 )
    return 0;
  v8 = v7 + 1;
  v9 = D3DXShader::CTokenize::LexDecimal(this, a2: v8, a3: (unsigned int *)&v14);
  if ( v9 == 0 )
  {
    v9 = D3DXShader::CTokenize::LexIdentifier(this, a2: v8, a3: (const char **)&v14);
    if ( v9 == 0 )
      return 0;
    v14 = nullptr;
  }
  if ( (unsigned int)v14 <= 0xFF )
  {
    v10 = &v8[v9] - v12;
    if ( v10 < 0x20 )
    {
      qmemcpy(v15, v12, v10);
      v15[v10] = 0;
      if ( D3DXGetTargetDescByName(a1: v15, a2: 1, a3: v11) >= 0 )
      {
        *v13 = v11[1];
        return v10;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C5302
// Name: protected: unsigned int D3DXShader::CTokenize::LexChar(char const __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::LexChar(D3DXShader::CTokenize *this, const char *a2, unsigned int *a3)
{
  int v4; // eax
  const char *v5; // esi

  if ( (unsigned int)a2 < *((_DWORD *)this + 1)
    && *a2 == 39
    && (v4 = D3DXShader::CTokenize::LexStringChar(this, a2: a2 + 1, a3)) != 0
    && (unsigned int)(v5 = &a2[v4 + 1]) < *((_DWORD *)this + 1)
    && *v5 == 39 )
  {
    return v4 + 2;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5345
// Name: protected: unsigned int D3DXShader::CTokenize::LexString(char const __near *,char const __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CTokenize::LexString(D3DXShader::CTokenize *this, const char *a2, const char **a3)
{
  unsigned int v5; // ecx
  const char *v6; // esi
  const char *v7; // ecx
  char v8; // al
  unsigned int v9; // edx
  unsigned __int8 *v10; // ebx
  const char *v11; // esi
  const char *v12; // edx
  const char *v13; // eax
  int v15; // [esp+Ch] [ebp-8h]
  char *v16; // [esp+10h] [ebp-4h]
  const char *v17; // [esp+1Ch] [ebp+8h]
  char v18; // [esp+1Fh] [ebp+Bh]

  v5 = *((_DWORD *)this + 1);
  if ( (unsigned int)a2 >= v5 )
    return 0;
  if ( *a2 == 34 )
  {
    v18 = 34;
    goto LABEL_7;
  }
  if ( *a2 != 60 || (*((_BYTE *)this + 40) & 8) == 0 )
    return 0;
  v18 = 62;
LABEL_7:
  v6 = a2 + 1;
  v16 = (char *)(a2 + 1);
  if ( (unsigned int)(a2 + 1) < v5 )
  {
    v7 = a2 + 2;
    do
    {
      v8 = *v6;
      if ( v18 == *v6 || v8 == 10 )
        break;
      if ( v8 == 92 && (*((_BYTE *)this + 40) & 4) == 0 )
      {
        v9 = *((_DWORD *)this + 1);
        ++v6;
        ++v7;
        if ( (unsigned int)v6 < v9 )
        {
          if ( *v6 != 10 )
          {
            if ( *v6 != 13 || (unsigned int)v7 >= v9 || *v7 != 10 )
              goto LABEL_20;
            ++v6;
            ++v7;
          }
          ++*((_DWORD *)this + 7);
        }
      }
LABEL_20:
      ++v6;
      ++v7;
    }
    while ( (unsigned int)v6 < *((_DWORD *)this + 1) );
  }
  if ( (unsigned int)v6 < *((_DWORD *)this + 1) )
  {
    if ( *v6 == 10 )
      D3DXShader::CTErrors::Error(
        this: *((D3DXShader::CTErrors **)this + 12),
        a2: (const char **)this + 2,
        a3: 0x3EDu,
        format: "string continues past end of line");
  }
  else
  {
    v6 = *((const char **)this + 1);
    D3DXShader::CTErrors::Error(
      this: *((D3DXShader::CTErrors **)this + 12),
      a2: (const char **)this + 2,
      a3: 0x3EEu,
      format: "string continues past end of file");
  }
  v17 = v6;
  v15 = v6 - a2;
  v10 = D3DXCore::CAlloc::Alloc(this: *((D3DXCore::CAlloc **)this + 11), a2: v6 - a2, dwSize: 1u);
  if ( v10 == nullptr )
    return 0;
  v11 = v16;
  *a3 = (const char *)v10;
  while ( 1 )
  {
    if ( v11 + 1 < v17 )
    {
      v12 = v11 + 1;
      v13 = v11 + 2;
      while ( *v11 == 92 && (*((_BYTE *)this + 40) & 4) == 0 )
      {
        if ( *v12 == 10 )
        {
          v11 += 2;
          v13 += 2;
          v12 += 2;
        }
        else
        {
          if ( *v12 != 13 || v13 >= v17 || *v13 != 10 )
            break;
          v11 += 3;
          v13 += 3;
          v12 += 3;
        }
        if ( v12 >= v17 )
          break;
      }
    }
    if ( v11 >= v17 )
      break;
    v11 += D3DXShader::CTokenize::LexStringChar(this, a2: v11, (unsigned int *)&a3);
    *v10++ = (unsigned __int8)a3;
  }
  *v10 = 0;
  return v15 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C548F
// Name: public: long D3DXShader::CTokenize::GetToken(unsigned long,struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CTokenize::GetToken(
        D3DXShader::CTokenize *this,
        unsigned int a2,
        struct D3DXShader::D3DXTOKEN *a3)
{
  int v4; // ebx
  const char *v5; // eax
  char v6; // cl
  int v7; // ebx
  unsigned int v8; // eax
  D3DXShader::CTokenize *v9; // ecx

  *((_DWORD *)this + 10) = a2;
  *((_DWORD *)a3 + 4) = *((_DWORD *)this + 6);
  v4 = 0;
  *((_DWORD *)a3 + 5) = *((_DWORD *)this + 7);
  if ( D3DXShader::CTokenize::SkipWhitespace((char **)this) == 0 )
  {
    *((_DWORD *)a3 + 4) = *((_DWORD *)this + 6);
    *((_DWORD *)a3 + 5) = *((_DWORD *)this + 7);
    v5 = *(const char **)this;
    if ( *(_DWORD *)this >= *((_DWORD *)this + 1) )
    {
      *(_DWORD *)a3 = 13;
      goto LABEL_34;
    }
    v6 = *v5;
    if ( *v5 >= 48 && v6 <= 57 || v6 == 46 )
    {
      v7 = D3DXShader::CTokenize::LexFloat(this, a2: v5, a3: (double *)a3 + 1);
      if ( v7 != 0 )
      {
        *(_DWORD *)a3 = 5;
        v8 = D3DXShader::CTokenize::LexFloatSuffix(this, a2: (const char *)(v7 + *(_DWORD *)this), a3);
LABEL_10:
        v4 = v8 + v7;
        goto LABEL_34;
      }
      v7 = D3DXShader::CTokenize::LexHex(this, a2: *(const char **)this, a3: (unsigned int *)a3 + 2);
      v9 = this;
      if ( v7 != 0
        || (v7 = D3DXShader::CTokenize::LexOctal(this, a2: *(const char **)this, a3: (unsigned int *)a3 + 2),
            v9 = this,
            v7 != 0) )
      {
LABEL_15:
        *(_DWORD *)a3 = 2;
        v8 = D3DXShader::CTokenize::LexIntegerSuffix(this: v9, a2: (const char *)(v7 + *(_DWORD *)this), a3);
        goto LABEL_10;
      }
      v7 = D3DXShader::CTokenize::LexDecimal(this, a2: *(const char **)this, a3: (unsigned int *)a3 + 2);
      if ( v7 != 0 )
      {
        v9 = this;
        goto LABEL_15;
      }
    }
    else if ( v6 == 39 )
    {
      v4 = D3DXShader::CTokenize::LexChar(this, a2: v5, a3: (unsigned int *)a3 + 2);
      if ( v4 != 0 )
      {
        *(_DWORD *)a3 = 2;
        goto LABEL_34;
      }
    }
    else if ( v6 == 34 )
    {
      v4 = D3DXShader::CTokenize::LexString(this, a2: v5, a3: (const char **)a3 + 2);
      if ( v4 != 0 )
      {
        *(_DWORD *)a3 = 10;
        goto LABEL_34;
      }
    }
    else if ( (*((_BYTE *)this + 40) & 4) != 0 && v6 == 60 )
    {
      v4 = D3DXShader::CTokenize::LexString(this, a2: v5, a3: (const char **)a3 + 2);
      if ( v4 != 0 )
      {
        *(_DWORD *)a3 = 11;
        goto LABEL_34;
      }
    }
    else if ( isalpha(c: v6) != 0 || **(_BYTE **)this == 95 )
    {
      if ( (*((_BYTE *)this + 40) & 2) != 0 )
      {
        v4 = D3DXShader::CTokenize::LexVersion(this, a2: *(const char **)this, a3: (unsigned int *)a3 + 2);
        if ( v4 != 0 )
        {
          *(_DWORD *)a3 = 0;
          goto LABEL_34;
        }
      }
      v4 = D3DXShader::CTokenize::LexIdentifier(this, a2: *(const char **)this, a3: (const char **)a3 + 2);
      if ( v4 != 0 )
      {
        *(_DWORD *)a3 = 9;
        goto LABEL_34;
      }
    }
    v4 = D3DXShader::CTokenize::LexOperator(this, a2: *(const char **)this, a3: (char *)a3 + 8);
    *(_DWORD *)a3 = 1;
    goto LABEL_34;
  }
  *(_DWORD *)a3 = 12;
LABEL_34:
  *((_DWORD *)a3 + 6) = *(_DWORD *)this;
  *((_DWORD *)a3 + 7) = v4;
  *(_DWORD *)this += v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C5652
// Name: long D3DXShader::GetUsageAndIndex(char const __near *,unsigned char __near *,unsigned char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::GetUsageAndIndex(D3DXShader *this, char *a2, unsigned __int8 *a3, unsigned __int8 *a4)
{
  const char *i; // esi
  unsigned int v6; // ebx
  char v7; // al
  D3DXShader *v8; // esi
  char v9; // al
  unsigned int v10; // [esp+10h] [ebp-28h]
  unsigned __int8 v11; // [esp+1Bh] [ebp-1Dh]
  char v12[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  for ( i = (const char *)this; *i != 0; ++i )
  {
    if ( isalpha(c: *i) == 0 )
      break;
  }
  if ( *i != 0 )
    v11 = atoi(nptr: i);
  else
    v11 = 0;
  if ( v11 > 0xFu )
  {
    *a2 = 0;
    *a3 = -1;
    return -2147467259;
  }
  v6 = i - (const char *)this;
  v10 = i - (const char *)this;
  if ( i == (const char *)this || v6 > 0x14 )
    return -2147467259;
  v7 = *i;
  if ( *i != 0 )
  {
    do
    {
      if ( isdigit(c: v7) == 0 )
        break;
      v7 = *++i;
    }
    while ( *i != 0 );
    if ( *i != 0 )
      return -2147467259;
  }
  v8 = this;
  if ( *(_BYTE *)this != 0 )
  {
    do
    {
      if ( isalpha(c: *(char *)v8) == 0 )
        break;
      *((_BYTE *)v8 + v12 - (char *)this) = toupper(c: *(char *)v8);
      v8 = (D3DXShader *)((char *)v8 + 1);
    }
    while ( *(_BYTE *)v8 != 0 );
    v6 = v10;
  }
  v12[v6] = 0;
  if ( strcmp(v12, "POSITION") == 0 )
  {
    v9 = 0;
  }
  else if ( strcmp(v12, "BLENDWEIGHT") == 0 )
  {
    v9 = 1;
  }
  else if ( strcmp(v12, "BLENDINDICES") == 0 )
  {
    v9 = 2;
  }
  else if ( strcmp(v12, "NORMAL") == 0 )
  {
    v9 = 3;
  }
  else
  {
    v9 = 6;
    if ( strcmp(v12, "PSIZE") == 0 )
    {
      v9 = 4;
    }
    else if ( strcmp(v12, "TEXCOORD") == 0 )
    {
      v9 = 5;
    }
    else if ( strcmp(v12, "TANGENT") != 0 )
    {
      if ( strcmp(v12, "BINORMAL") == 0 )
      {
        v9 = 7;
      }
      else
      {
        v9 = 11;
        if ( strcmp(v12, "TESSFACTOR") == 0 )
        {
          v9 = 8;
        }
        else
        {
          if ( strcmp(v12, "POSITIONT") != 0 )
          {
            if ( strcmp(v12, "COLOR") != 0 )
            {
              if ( strcmp(v12, "FOG") == 0 )
                goto LABEL_50;
              if ( strcmp(v12, "DEPTH") == 0 )
              {
                v9 = 12;
                goto LABEL_50;
              }
              if ( strcmp(v12, "SAMPLE") == 0 )
              {
                v9 = 13;
                goto LABEL_50;
              }
              if ( strcmp(v12, "DIFFUSE") == 0 )
              {
                v11 = 0;
              }
              else
              {
                if ( strcmp(v12, "SPECULAR") != 0 )
                  return -2147467259;
                v11 = 1;
              }
            }
            v9 = 10;
            goto LABEL_50;
          }
          v9 = 9;
        }
      }
    }
  }
LABEL_50:
  *a2 = v9;
  *a3 = v11;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C58A8
// Name: unsigned int D3DXShader::RegisterHash(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::RegisterHash(D3DXShader *this, const char *a2)
{
  D3DXShader *v2; // esi
  unsigned int v3; // edi
  char v4; // al

  v2 = this;
  v3 = 0;
  if ( this == nullptr )
    return 0;
  v4 = *(_BYTE *)this;
  if ( *(_BYTE *)this == 0 )
    return 0;
  do
  {
    v3 = toupper(c: v4) + 19 * v3;
    v2 = (D3DXShader *)((char *)v2 + 1);
    v4 = *(_BYTE *)v2;
  }
  while ( *(_BYTE *)v2 != 0 );
  return v3 % 7;
}

//------------------------------------------------------------------------------
// Address: 0x101E5570
// Name: private: long D3DXShader::CProgram::SwizzleParameter(unsigned int __near *,unsigned int __near *,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SwizzleParameter(
        D3DXShader::CProgram *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        int a5)
{
  unsigned int v5; // edx
  unsigned int i; // eax
  unsigned int v8; // eax
  int v9; // ebx
  unsigned int *v10; // edx
  unsigned int v11; // esi
  unsigned int *v12; // edi
  unsigned int *v13; // eax
  unsigned int *v14; // ebx
  unsigned int v15; // eax
  int v16; // ecx
  _DWORD v18[4]; // [esp+8h] [ebp-20h] BYREF
  unsigned int v19; // [esp+18h] [ebp-10h]
  unsigned int *v20; // [esp+1Ch] [ebp-Ch]
  D3DXShader::CProgram *v21; // [esp+20h] [ebp-8h]
  unsigned int v22; // [esp+24h] [ebp-4h]
  unsigned int *v23; // [esp+34h] [ebp+Ch]
  unsigned int v24; // [esp+3Ch] [ebp+14h]

  v5 = a4;
  v21 = this;
  if ( a5 == 0 )
    goto LABEL_14;
  for ( i = 0; i < a4; ++i )
    a3[i] = i;
  v8 = 0;
  if ( a4 == 0 )
    goto LABEL_14;
  do
  {
    v9 = *((_DWORD *)v21 + 5);
    v10 = &a3[v8];
    v11 = *v10;
    v12 = *(unsigned int **)(*(_DWORD *)(v9 + 4 * a2[*v10]) + 16);
    v22 = v8++;
    v23 = v12;
    v19 = v8;
    v24 = v8;
    if ( v8 < a4 )
    {
      do
      {
        v20 = *(unsigned int **)(*(_DWORD *)(v9 + 4 * a2[a3[v24]]) + 16);
        v13 = v20;
        if ( v20 < v23 )
          goto LABEL_10;
        if ( v20 == v23 && v24 < v22 )
        {
          v13 = v20;
LABEL_10:
          v22 = v24;
          v23 = v13;
        }
        ++v24;
      }
      while ( v24 < a4 );
      v8 = v19;
    }
    v14 = &a3[v22];
    *v10 = *v14;
    v5 = a4;
    *v14 = v11;
  }
  while ( v8 < a4 );
LABEL_14:
  v15 = 0;
  if ( v5 != 0 )
  {
    v16 = (char *)a3 - (char *)v18;
    do
    {
      v18[v15] = a2[*(_DWORD *)((char *)&v18[v15] + v16)];
      ++v15;
    }
    while ( v15 < v5 );
    qmemcpy(a2, v18, 4 * v5);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5651
// Name: private: void D3DXShader::CProgram::ReadWriteInfo_ReadInfo(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::ReadWriteInfo_ReadInfo(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  int v4; // edx
  _DWORD *v5; // eax
  int v6; // edi
  _DWORD *v7; // edx

  while ( 1 )
  {
    v4 = *((_DWORD *)this + 5);
    v5 = *(_DWORD **)(v4 + 4 * a2);
    v6 = v5[14];
    if ( v6 != -1 )
      v5 = *(_DWORD **)(v4 + 4 * v6);
    v7 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * v5[1]);
    if ( v5[21] > a3 )
      v5[21] = a3;
    if ( v5[22] < a3 )
      v5[22] = a3;
    ++v5[23];
    if ( v5[2] == -1 )
      break;
    if ( v7[10] > a3 )
      v7[10] = a3;
    if ( v7[11] < a3 )
      v7[11] = a3;
    ++v7[12];
    a2 = v5[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E56AF
// Name: private: void D3DXShader::CProgram::ReadWriteInfo_WriteInfo(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::ReadWriteInfo_WriteInfo(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  _DWORD *v3; // eax
  int v4; // edx
  int v5; // edx
  _DWORD *v6; // edx
  unsigned int v7; // eax

  v3 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a2);
  v4 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v3[1]);
  v3[18] = a3;
  v5 = *(_DWORD *)(v4 + 32);
  if ( v5 != 0 )
  {
    v6 = (_DWORD *)(v5 + 4 * (v3[4] + 4 * v3[3]));
    if ( *v6 != -1 )
    {
      v3[19] = *v6;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6) + 80) = a2;
    }
    *v6 = a2;
  }
  v7 = v3[5];
  if ( v7 != -1 )
    D3DXShader::CProgram::ReadWriteInfo_ReadInfo(this, a2: v7, a3);
}

//------------------------------------------------------------------------------
// Address: 0x101E5711
// Name: private: long D3DXShader::CProgram::ReadWriteInfo_CommitOrigin(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::ReadWriteInfo_CommitOrigin(D3DXShader::CProgram *this)
{
  unsigned int v1; // ebx
  int v2; // edi
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // esi
  _DWORD *v6; // edx
  unsigned int v7; // esi
  unsigned int v8; // esi
  unsigned int i; // edi
  int v10; // eax
  int v11; // edx
  int v12; // esi

  v1 = 0;
  v2 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v3 = *((_DWORD *)this + 5);
      v4 = *(_DWORD **)(v3 + 4 * v1);
      v5 = v4[14];
      if ( v5 != -1 )
      {
        v6 = *(_DWORD **)(v3 + 4 * v5);
        v4[1] = v6[1];
        v4[2] = v6[2];
        v4[3] = v6[3];
        v4[4] = v6[4];
        v4[18] = v6[18];
        v4[19] = v6[19];
        v4[20] = v6[20];
        v7 = v6[21];
        if ( v7 == -1 )
        {
          v6[21] = v4[21];
          v6[22] = v4[22];
          v6[23] = v4[23];
        }
        else
        {
          if ( v7 >= v4[21] )
            v7 = v4[21];
          v4[21] = v7;
          v6[21] = v7;
          v8 = v6[22];
          if ( v8 <= v4[22] )
            v8 = v4[22];
          v4[22] = v8;
          v6[22] = v8;
          v6[23] += v4[23];
        }
        v2 = 1;
      }
      ++v1;
    }
    while ( v1 < *((_DWORD *)this + 2) );
    if ( v2 != 0 )
    {
      for ( i = 0; i < *((_DWORD *)this + 2); ++i )
      {
        v10 = *((_DWORD *)this + 5);
        v11 = *(_DWORD *)(v10 + 4 * i);
        v12 = *(_DWORD *)(v11 + 56);
        if ( v12 != -1 )
          *(_DWORD *)(v11 + 84) = *(_DWORD *)(*(_DWORD *)(v10 + 4 * v12) + 84);
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E57DC
// Name: protected: long D3DXShader::CProgram::ReadWriteInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::ReadWriteInfo(D3DXShader::CProgram *this)
{
  unsigned int v2; // ebx
  unsigned int i; // ecx
  _DWORD *v4; // eax
  unsigned int j; // ecx
  _DWORD *v6; // eax
  unsigned int k; // eax
  int v8; // ecx
  unsigned int m; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // edi
  char *v18; // eax
  int v20; // ecx
  unsigned int v21; // edx
  int v22; // eax
  int v23; // edi
  unsigned int ii; // ebx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  unsigned int kk; // edi
  _DWORD *v31; // eax
  int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int mm; // edi
  int v36; // ecx
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  unsigned int v40; // edx
  unsigned int v41; // ecx
  int v42; // ecx
  int v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // ecx
  char *pMem; // [esp+Ch] [ebp-Ch]
  unsigned int jj; // [esp+10h] [ebp-8h]
  unsigned int n; // [esp+14h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < *((_DWORD *)this + 1); v4[8] = 0 )
  {
    v4 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * i);
    v4[10] = -1;
    ++i;
    v4[11] = 0;
    v4[12] = 0;
  }
  for ( j = 0; j < *((_DWORD *)this + 2); v6[20] = -1 )
  {
    v6 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * j);
    v6[13] = j++;
    v6[21] = -1;
    v6[22] = 0;
    v6[23] = 0;
    v6[18] = -1;
    v6[19] = -1;
  }
  pMem = nullptr;
  if ( *((_DWORD *)this + 55) != 0 )
  {
    for ( k = 0; k < *((_DWORD *)this + 1); *(_DWORD *)(v8 + 16) = 0 )
      v8 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * k++);
    for ( m = 0; m < *((_DWORD *)this + 2); ++m )
    {
      v10 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * m);
      v11 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v10 + 4));
      v12 = *(_DWORD *)(v11 + 4);
      if ( (v12 & 0x40) == 0 && (v12 & 2) != 0 )
      {
        v13 = *(_DWORD *)(v10 + 12) + 1;
        if ( *(_DWORD *)(v11 + 16) < v13 )
          *(_DWORD *)(v11 + 16) = v13;
      }
    }
    v14 = *((_DWORD *)this + 1);
    v15 = 0;
    if ( v14 != 0 )
    {
      v16 = *((_DWORD *)this + 4);
      do
      {
        v15 += *(_DWORD *)(*(_DWORD *)v16 + 16);
        v16 += 4;
        --v14;
      }
      while ( v14 != 0 );
    }
    v17 = 16 * v15;
    v18 = (char *)MemAlloc_Alloc(nSize: 16 * v15);
    pMem = v18;
    if ( v18 == nullptr )
      return -2147024882;
    memset(v18, 0xFFu, v17);
    v20 = 0;
    v21 = 0;
    if ( *((_DWORD *)this + 1) != 0 )
    {
      v22 = *((_DWORD *)this + 4);
      do
      {
        *(_DWORD *)(*(_DWORD *)(v22 + 4 * v21) + 32) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v21) + 16) != 0
                                                     ? &pMem[16 * v20]
                                                     : nullptr;
        v22 = *((_DWORD *)this + 4);
        v20 += *(_DWORD *)(*(_DWORD *)(v22 + 4 * v21++) + 16);
      }
      while ( v21 < *((_DWORD *)this + 1) );
      v2 = 0;
    }
  }
  for ( n = 0; n < *((_DWORD *)this + 3); ++n )
  {
    v23 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * n);
    if ( v23 != 0 && (*(_WORD *)(v23 + 2) & 0xFFF0) != 0 )
    {
      if ( *(_DWORD *)(v23 + 4) != 0 )
      {
        do
          D3DXShader::CProgram::ReadWriteInfo_ReadInfo(this, a2: *(_DWORD *)(*(_DWORD *)(v23 + 8) + 4 * v2++), a3: n);
        while ( v2 < *(_DWORD *)(v23 + 4) );
      }
      for ( ii = 0; ii < *(_DWORD *)(v23 + 12); ++ii )
        D3DXShader::CProgram::ReadWriteInfo_WriteInfo(this, a2: *(_DWORD *)(*(_DWORD *)(v23 + 16) + 4 * ii), a3: n);
      if ( (*(_DWORD *)v23 & 0xFFF00000) == 0x10000000 && (*((_BYTE *)this + 204) & 4) == 0 )
      {
        for ( jj = 0; jj < *(_DWORD *)(v23 + 12); ++jj )
        {
          v25 = *((_DWORD *)this + 5);
          v26 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(4 * jj + *(_DWORD *)(v23 + 16)));
          v27 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(4 * jj + *(_DWORD *)(v23 + 8)));
          v28 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v26 + 4)) + 4);
          if ( (v28 & 0x1020) == 0 && (v28 & 1) != 0 && *(_DWORD *)(v27 + 60) == 0 )
          {
            v29 = *(_DWORD *)(v26 + 52);
            *(_DWORD *)(v26 + 52) = *(_DWORD *)(v27 + 52);
            *(_DWORD *)(v27 + 52) = v29;
          }
        }
      }
      v2 = 0;
    }
  }
  for ( kk = 0; kk < *((_DWORD *)this + 2); ++kk )
  {
    v31 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * kk);
    v32 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v31[1]);
    v33 = *(_DWORD *)(v32 + 40);
    if ( v31[21] > v33 )
      v31[21] = v33;
    v34 = *(_DWORD *)(v32 + 44);
    if ( v31[22] < v34 )
      v31[22] = v34;
  }
  if ( *((_DWORD *)this + 55) != 0 )
  {
    for ( mm = 0; mm < *((_DWORD *)this + 2); ++mm )
    {
      v36 = *((_DWORD *)this + 5);
      v37 = *(_DWORD *)(v36 + 4 * mm);
      v38 = *(_DWORD *)(v37 + 76);
      if ( v38 == -1 )
      {
        *(_DWORD *)(v37 + 76) = 0;
      }
      else
      {
        v39 = *(_DWORD *)(v36 + 4 * v38);
        v40 = *(_DWORD *)(v39 + 88);
        *(_DWORD *)(v37 + 76) = v40;
        v41 = *(_DWORD *)(v39 + 72);
        if ( v40 <= v41 )
          *(_DWORD *)(v37 + 76) = v41 + 1;
      }
      v42 = *(_DWORD *)(v37 + 80);
      if ( v42 == -1 )
      {
        *(_DWORD *)(v37 + 80) = -1;
      }
      else
      {
        v43 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v42);
        v44 = *(_DWORD *)(v43 + 84);
        *(_DWORD *)(v37 + 80) = v44;
        v45 = *(_DWORD *)(v43 + 72);
        if ( v44 > v45 )
          *(_DWORD *)(v37 + 80) = v45;
      }
    }
  }
  if ( *((_DWORD *)this + 54) != 0 )
    D3DXShader::CProgram::ReadWriteInfo_CommitOrigin(this);
  free(pMem);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5AA9
// Name: private: void D3DXShader::CProgram::ParentChildInfo_ParentInfo(unsigned int,unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::ParentChildInfo_ParentInfo(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3,
        int a4)
{
  unsigned int v4; // ebx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // esi

  v4 = a3;
  while ( 1 )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v4);
    v8 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a2);
    if ( a4 != 0 && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v8[1]) + 4) & 2) != 0 )
    {
      v9 = *(_DWORD *)(v7 + 24);
      if ( v9 != 0 )
      {
        *(_DWORD *)(v9 + 4 * *(_DWORD *)(v7 + 20)) = v8[18];
        v4 = a3;
      }
      ++*(_DWORD *)(v7 + 20);
      v10 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v8[18]);
      v11 = *(_DWORD *)(v10 + 32);
      if ( v11 != 0 )
        *(_DWORD *)(v11 + 4 * *(_DWORD *)(v10 + 28)) = v4;
      ++*(_DWORD *)(v10 + 28);
    }
    v12 = v8[2];
    if ( v12 != -1 )
      D3DXShader::CProgram::ParentChildInfo_ParentInfo(this, a2: v12, a3: v4, a4: 1);
    v13 = v8[5];
    if ( v13 == -1 )
      break;
    a4 = 1;
    a2 = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5B36
// Name: protected: long D3DXShader::CProgram::ParentChildInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::ParentChildInfo(D3DXShader::CProgram *this)
{
  unsigned int i; // ecx
  _DWORD *v3; // eax
  int v4; // esi
  unsigned int k; // ebx
  unsigned int m; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int *v9; // esi
  unsigned int *v10; // eax
  unsigned int *v11; // eax
  int v12; // esi
  unsigned int ii; // ebx
  unsigned int jj; // ebx
  unsigned int v15; // eax
  int v17; // esi
  unsigned int *v18; // eax
  unsigned int mm; // edx
  int v20; // eax
  int v21; // ecx
  unsigned int v22; // ebx
  unsigned int *v23; // eax
  unsigned int nn; // edx
  int v25; // eax
  int v26; // ecx
  unsigned int v27; // ebx
  const void *v28; // [esp+0h] [ebp-14h]
  unsigned int kk; // [esp+Ch] [ebp-8h]
  unsigned int j; // [esp+10h] [ebp-4h]
  unsigned int n; // [esp+10h] [ebp-4h]
  unsigned int v32; // [esp+10h] [ebp-4h]
  unsigned int v33; // [esp+10h] [ebp-4h]

  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 3); v3[7] = 0 )
  {
    v3 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * i++);
    v3[6] = 0;
    v3[8] = 0;
    v3[5] = 0;
  }
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * j);
    if ( (*(_WORD *)(v4 + 2) & 0xFFF0) != 0 )
    {
      for ( k = 0; k < *(_DWORD *)(v4 + 12); ++k )
        D3DXShader::CProgram::ParentChildInfo_ParentInfo(
          this,
          a2: *(_DWORD *)(*(_DWORD *)(v4 + 16) + 4 * k),
          a3: j,
          a4: 0);
      for ( m = 0; m < *(_DWORD *)(v4 + 4); ++m )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(v4 + 8) + 4 * m);
        if ( v7 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v7) + 56) != -1 )
          v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v7) + 56);
        D3DXShader::CProgram::ParentChildInfo_ParentInfo(this, a2: v7, a3: j, a4: 1);
      }
    }
  }
  v8 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    while ( 1 )
    {
      v9 = *(unsigned int **)(*((_DWORD *)this + 6) + 4 * v8);
      if ( v9[5] != 0 )
      {
        v10 = D3DXShader::CInstruction::Alloc(a1: v9[5]);
        v9[6] = (unsigned int)v10;
        if ( v10 == nullptr )
          return -2147024882;
      }
      if ( v9[7] != 0 )
      {
        v11 = D3DXShader::CInstruction::Alloc(a1: v9[7]);
        v9[8] = (unsigned int)v11;
        if ( v11 == nullptr )
          return -2147024882;
      }
      ++v8;
      v9[5] = 0;
      v9[7] = 0;
      if ( v8 >= *((_DWORD *)this + 3) )
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    for ( n = 0; n < *((_DWORD *)this + 3); ++n )
    {
      v12 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * n);
      if ( (*(_WORD *)(v12 + 2) & 0xFFF0) != 0 )
      {
        for ( ii = 0; ii < *(_DWORD *)(v12 + 12); ++ii )
          D3DXShader::CProgram::ParentChildInfo_ParentInfo(
            this,
            a2: *(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * ii),
            a3: n,
            a4: 0);
        for ( jj = 0; jj < *(_DWORD *)(v12 + 4); ++jj )
        {
          v15 = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 4 * jj);
          if ( v15 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v15) + 56) != -1 )
            v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v15) + 56);
          D3DXShader::CProgram::ParentChildInfo_ParentInfo(this, a2: v15, a3: n, a4: 1);
        }
      }
    }
    for ( kk = 0; kk < *((_DWORD *)this + 3); ++kk )
    {
      v17 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * kk);
      v18 = *(unsigned int **)(v17 + 20);
      if ( v18 != nullptr )
      {
        D3DXShader::HeapSort(
          this: (D3DXShader *)D3DXShader::CTReorderInstructions::CompareIndex,
          a2: *(int (__stdcall **)(unsigned int, unsigned int, const void *))(v17 + 24),
          a3: v18,
          a4: 0,
          a5: v28);
        v32 = 1;
        for ( mm = 1; mm < *(_DWORD *)(v17 + 20); ++mm )
        {
          v20 = *(_DWORD *)(v17 + 24);
          v21 = *(_DWORD *)(v20 + 4 * mm);
          if ( v21 != *(_DWORD *)(v20 + 4 * mm - 4) )
          {
            v22 = v32++;
            *(_DWORD *)(v20 + 4 * v22) = v21;
          }
        }
        *(_DWORD *)(v17 + 20) = v32;
      }
      v23 = *(unsigned int **)(v17 + 28);
      if ( v23 != nullptr )
      {
        D3DXShader::HeapSort(
          this: (D3DXShader *)D3DXShader::CTReorderInstructions::CompareIndex,
          a2: *(int (__stdcall **)(unsigned int, unsigned int, const void *))(v17 + 32),
          a3: v23,
          a4: 0,
          a5: v28);
        v33 = 1;
        for ( nn = 1; nn < *(_DWORD *)(v17 + 28); ++nn )
        {
          v25 = *(_DWORD *)(v17 + 32);
          v26 = *(_DWORD *)(v25 + 4 * nn);
          if ( v26 != *(_DWORD *)(v25 + 4 * nn - 4) )
          {
            v27 = v33++;
            *(_DWORD *)(v25 + 4 * v27) = v26;
          }
        }
        *(_DWORD *)(v17 + 28) = v33;
      }
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5D6E
// Name: protected: long D3DXShader::CProgram::IdentityRemap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::IdentityRemap(D3DXShader::CProgram *this)
{
  unsigned int i; // eax

  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * i) + 48) = i;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5D87
// Name: protected: long D3DXShader::CProgram::RemapArguments(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::RemapArguments(D3DXShader::CProgram *this)
{
  unsigned int i; // edi
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  _DWORD *v10; // eax
  unsigned int v11; // esi
  int *v12; // edx
  int v13; // edi
  unsigned int k; // esi
  int *v15; // edx
  int v16; // edi
  unsigned int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *((_DWORD *)this + 2); v3[14] = v9 )
  {
    v2 = *((_DWORD *)this + 5);
    v3 = *(_DWORD **)(v2 + 4 * i);
    v4 = v3[2];
    if ( v4 == -1 )
      v5 = -1;
    else
      v5 = *(_DWORD *)(*(_DWORD *)(v2 + 4 * v4) + 48);
    v3[2] = v5;
    v6 = v3[5];
    if ( v6 == -1 )
      v7 = -1;
    else
      v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v6) + 48);
    v3[5] = v7;
    v8 = v3[14];
    if ( v8 == -1 )
      v9 = -1;
    else
      v9 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v8) + 48);
    ++i;
  }
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v10 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * j);
    v11 = 0;
    if ( *v10 != 0 )
    {
      if ( v10[1] != 0 )
      {
        do
        {
          v12 = (int *)(v10[2] + 4 * v11);
          if ( *v12 == -1 )
            v13 = -1;
          else
            v13 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v12) + 48);
          ++v11;
          *v12 = v13;
        }
        while ( v11 < v10[1] );
      }
      for ( k = 0; k < v10[3]; *v15 = v16 )
      {
        v15 = (int *)(v10[4] + 4 * k);
        if ( *v15 == -1 )
          v16 = -1;
        else
          v16 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v15) + 48);
        ++k;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5E67
// Name: protected: virtual void D3DXShader::CProgram::GetArgumentName(class D3DXShader::CArgument __near *,char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::GetArgumentName(
        D3DXShader::CProgram *this,
        struct D3DXShader::CArgument *a2,
        char *string,
        unsigned int count)
{
  int v4; // esi
  int v5; // edx
  struct D3DXShader::CArgument *v6; // ebx
  int v7; // eax
  const char *v8; // [esp-8h] [ebp-14h]
  _BYTE *v9; // [esp-4h] [ebp-10h]

  v4 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)a2 + 1));
  v5 = *((_DWORD *)a2 + 14);
  if ( v5 == -1 )
    v6 = a2;
  else
    v6 = *(struct D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v5);
  if ( **(_BYTE **)v4 == 0 || *(_BYTE *)(*(_DWORD *)v4 + 1) != 0 )
  {
    v9 = *(_BYTE **)v4;
    v8 = "%s_";
  }
  else
  {
    v9 = *(_BYTE **)v4;
    v8 = "%s";
  }
  v7 = _snprintf(string, count, format: v8, v9);
  if ( *((_DWORD *)v6 + 3) == -1 )
    _snprintf(string: &string[v7], count: count - v7, format: "?");
  else
    _snprintf(string: &string[v7], count: count - v7, format: "%u", *((_DWORD *)v6 + 3));
  string[count - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5EF9
// Name: protected: long D3DXShader::CProgram::Error(class D3DXShader::CNode __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CProgram::Error(
        D3DXShader::CTErrors **this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        char *format,
        ...)
{
  const char **v4; // eax
  int v5; // edx
  char string[256]; // [esp+0h] [ebp-104h] BYREF
  va_list ap; // [esp+11Ch] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  v4 = nullptr;
  string[255] = 0;
  if ( a2 != nullptr )
  {
    v5 = *((_DWORD *)a2 + 1);
    switch ( v5 )
    {
      case 3:
        v4 = (const char **)((char *)a2 + 16);
        break;
      case 6:
        v4 = (const char **)(*((_DWORD *)a2 + 5) + 16);
        break;
      case 13:
        v4 = (const char **)((char *)a2 + 48);
        break;
      default:
        break;
    }
  }
  D3DXShader::CTErrors::Error(this: *(this + 49), a2: v4, a3, format: "%s", string);
  *(this + 53) = (D3DXShader::CTErrors *)1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E5F8E
// Name: protected: long D3DXShader::CProgram::Warning(class D3DXShader::CNode __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CProgram::Warning(
        D3DXShader::CTErrors **this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        char *format,
        ...)
{
  const char **v4; // eax
  int v5; // edx
  char string[256]; // [esp+0h] [ebp-104h] BYREF
  va_list ap; // [esp+11Ch] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  v4 = nullptr;
  string[255] = 0;
  if ( a2 != nullptr )
  {
    v5 = *((_DWORD *)a2 + 1);
    switch ( v5 )
    {
      case 3:
        v4 = (const char **)((char *)a2 + 16);
        break;
      case 6:
        v4 = (const char **)(*((_DWORD *)a2 + 5) + 16);
        break;
      case 13:
        v4 = (const char **)((char *)a2 + 48);
        break;
      default:
        break;
    }
  }
  D3DXShader::CTErrors::Warning(this: *(this + 49), a2: v4, a3, format: "%s", string);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E6017
// Name: sub_101E6017
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall sub_101E6017(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  D3DXShader::CInstruction *v6; // esi
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // ecx
  int v20; // esi
  unsigned int v21; // ebx
  unsigned int v22; // edi
  unsigned int v23; // edi
  unsigned int v24; // edx
  unsigned int v26; // edx
  int v27; // ebx
  _DWORD *v28; // eax
  int v29; // esi
  unsigned int v30; // ecx
  unsigned int v31; // edi
  unsigned int v32; // [esp+Ch] [ebp-14h]
  unsigned int v33; // [esp+10h] [ebp-10h]
  unsigned int v34; // [esp+14h] [ebp-Ch]
  unsigned int v35; // [esp+18h] [ebp-8h]
  unsigned int v36; // [esp+1Ch] [ebp-4h]
  _DWORD *v37; // [esp+1Ch] [ebp-4h]
  _DWORD *v38; // [esp+28h] [ebp+8h]
  unsigned int v39; // [esp+28h] [ebp+8h]
  unsigned int v40; // [esp+2Ch] [ebp+Ch]
  unsigned int v41; // [esp+2Ch] [ebp+Ch]

  v4 = a4;
  v5 = *(_DWORD *)(a4 + 24);
  v6 = *(D3DXShader::CInstruction **)(v5 + 4 * a1);
  v7 = *(_DWORD **)(v5 + 4 * a3);
  if ( *(_DWORD *)v6 < *v7 )
    return -1;
  if ( *(_DWORD *)v6 <= *v7 )
  {
    v36 = 0;
    if ( *((_DWORD *)v6 + 3) != 0 )
    {
      v8 = *((_DWORD *)v6 + 4) - v7[4];
      v38 = (_DWORD *)v7[4];
      while ( 1 )
      {
        v9 = *(_DWORD *)(v4 + 20);
        v10 = *(_DWORD **)(v9 + 4 * *(_DWORD *)((char *)v38 + v8));
        v11 = *(_DWORD **)(v9 + 4 * *v38);
        v12 = v10[1];
        v13 = v11[1];
        if ( v12 < v13 )
          return -1;
        if ( v12 > v13 )
          return 1;
        v14 = v10[5];
        v15 = v11[5];
        if ( v14 < v15 )
          return -1;
        if ( v14 > v15 )
          return 1;
        v16 = v10[6];
        v17 = v11[6];
        if ( v16 < v17 )
          return -1;
        if ( v16 > v17 )
          return 1;
        ++v36;
        ++v38;
        v4 = a4;
        if ( v36 >= *((_DWORD *)v6 + 3) )
          break;
        v8 = *((_DWORD *)v6 + 4) - v7[4];
      }
    }
    if ( D3DXShader::CInstruction::IsSymetric(this: v6) != 0 )
    {
      v32 = *(_DWORD *)v6 & 0xFFFFF;
      v35 = 0;
      if ( v32 != 0 )
      {
        v18 = *(_DWORD *)(v4 + 20);
        v37 = (_DWORD *)v7[2];
        v19 = &v37[*(_DWORD *)v6 & 0xFFFFF];
        v20 = *((_DWORD *)v6 + 2) - (_DWORD)v37;
        while ( 1 )
        {
          v21 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v37 + v20)) + 48);
          v22 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48);
          v34 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v37) + 48);
          v33 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48);
          v40 = v21;
          if ( v21 < v22
            || (v40 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48),
                v39 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v37 + v20)) + 48),
                v21 <= v22) )
          {
            v39 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *(_DWORD *)((char *)v19 + v20)) + 48);
          }
          v23 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v37) + 48);
          v24 = v23;
          if ( v34 < v33 || (v24 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48), v34 <= v33) )
            v23 = *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v19) + 48);
          if ( v40 < v24 )
            break;
          if ( v40 > v24 )
            return 1;
          if ( v39 < v23 )
            break;
          if ( v39 > v23 )
            return 1;
          ++v35;
          ++v37;
          ++v19;
          if ( v35 >= v32 )
            return 0;
        }
        return -1;
      }
    }
    else
    {
      v26 = *((_DWORD *)v6 + 1);
      v41 = 0;
      if ( v26 != 0 )
      {
        v27 = *(_DWORD *)(v4 + 20);
        v28 = (_DWORD *)v7[2];
        v29 = *((_DWORD *)v6 + 2) - (_DWORD)v28;
        while ( 1 )
        {
          v30 = *(_DWORD *)(*(_DWORD *)(v27 + 4 * *(_DWORD *)((char *)v28 + v29)) + 48);
          v31 = *(_DWORD *)(*(_DWORD *)(v27 + 4 * *v28) + 48);
          if ( v30 < v31 )
            break;
          if ( v30 > v31 )
            return 1;
          ++v41;
          ++v28;
          if ( v41 >= v26 )
            return 0;
        }
        return -1;
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E61B6
// Name: sub_101E61B6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall sub_101E61B6(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int result; // eax

  result = sub_101E6017(a1: a3, a2, a3: a4, a4: a5);
  if ( result == 0 )
  {
    if ( a4 <= a3 )
      return a4 < a3;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6203
// Name: public: long D3DXShader::CProgram::Initialize(class D3DXShader::CNode __near *,class D3DXShader::CTErrors __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Initialize(
        D3DXShader::CProgram *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CTErrors *a3,
        unsigned int a4,
        unsigned int a5)
{
  int result; // eax
  unsigned int v7; // eax
  bool v8; // zf

  if ( a3 == nullptr )
    return -2147467259;
  *((_DWORD *)this + 49) = a3;
  *((_DWORD *)this + 50) = a4;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 48) = a2;
  *((_DWORD *)this + 51) = a5;
  *((_DWORD *)this + 29) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_1029F018.m_Memory.m_nGrowSize,
                             a3: 0,
                             a4: 0xFFFFFFFF,
                             a5: 4u);
  *((_DWORD *)this + 30) = D3DXShader::CBaseProgram::AddPool(this, a2: "l", a3: 0x311u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 31) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                             a3: 0x251u,
                             a4: 0xFFFFFFFF,
                             a5: 4u);
  *((_DWORD *)this + 32) = D3DXShader::CBaseProgram::AddPool(this, a2: "v", a3: 0x51u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 33) = D3DXShader::CBaseProgram::AddPool(this, a2: "o", a3: 0x62u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 34) = D3DXShader::CBaseProgram::AddPool(this, a2: "r", a3: 3u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 35) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_102A0968.m_Size,
                             a3: 6u,
                             a4: 0xFFFFFFFF,
                             a5: 4u);
  *((_DWORD *)this + 36) = D3DXShader::CBaseProgram::AddPool(this, a2: "p", a3: 0xAu, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 37) = D3DXShader::CBaseProgram::AddPool(this, a2: "s", a3: 0x2D1u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 38) = D3DXShader::CBaseProgram::AddPool(this, a2: "i", a3: 0x1003u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 39) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_102A6BD8.m_Memory.m_nGrowSize,
                             a3: 0x2251u,
                             a4: 0xFFFFFFFF,
                             a5: 4u);
  *((_DWORD *)this + 40) = D3DXShader::CBaseProgram::AddPool(this, a2: "p", a3: 0x400Au, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 41) = D3DXShader::CBaseProgram::AddPool(this, a2: "q", a3: 0xC00Au, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 42) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_102A0968.m_Memory.m_nGrowSize,
                             a3: 0x10042u,
                             a4: 0,
                             a5: 4u);
  *((_DWORD *)this + 43) = D3DXShader::CBaseProgram::AddPool(
                             this,
                             a2: (char *)&stru_1029F018.m_Memory.m_nAllocationCount,
                             a3: 0x20003u,
                             a4: 0xFFFFFFFF,
                             a5: 4u);
  *((_DWORD *)this + 44) = D3DXShader::CBaseProgram::AddPool(this, a2: "i", a3: 0x40211u, a4: 0xFFFFFFFF, a5: 4u);
  *((_DWORD *)this + 45) = D3DXShader::CBaseProgram::AddPool(this, a2: "k", a3: 0x2062u, a4: 0xFFFFFFFF, a5: 4u);
  v7 = D3DXShader::CBaseProgram::AddPool(this, a2: "j", a3: 0x40062u, a4: 0xFFFFFFFF, a5: 4u);
  v8 = *((_DWORD *)this + 1) == 18;
  *((_DWORD *)this + 46) = v7;
  if ( !v8 )
    return -2147024882;
  memset((char *)this + 40, 0, 0x4Cu);
  result = (*(int (__thiscall **)(D3DXShader::CProgram *))(*(_DWORD *)this + 12))(a1: this);
  if ( result >= 0 )
  {
    result = D3DXShader::CProgram::SetName((void **)this, a2: nullptr);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6438
// Name: public: long D3DXShader::CProgram::Initialize(class D3DXShader::CProgram __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Initialize(
        D3DXShader::CProgram *this,
        struct D3DXShader::CProgram *a2,
        unsigned int a3,
        unsigned int a4)
{
  int result; // eax
  int v6; // eax

  result = D3DXShader::CBaseProgram::Initialize(this, a2);
  if ( result >= 0 )
  {
    *((_DWORD *)this + 48) = *((_DWORD *)a2 + 48);
    v6 = *((_DWORD *)a2 + 49);
    *((_DWORD *)this + 53) = 0;
    *((_DWORD *)this + 54) = 0;
    *((_DWORD *)this + 55) = 0;
    *((_DWORD *)this + 49) = v6;
    *((_DWORD *)this + 50) = a3;
    *((_DWORD *)this + 51) = a4;
    *((_DWORD *)this + 29) = *((_DWORD *)a2 + 29);
    *((_DWORD *)this + 30) = *((_DWORD *)a2 + 30);
    *((_DWORD *)this + 31) = *((_DWORD *)a2 + 31);
    *((_DWORD *)this + 32) = *((_DWORD *)a2 + 32);
    *((_DWORD *)this + 33) = *((_DWORD *)a2 + 33);
    *((_DWORD *)this + 34) = *((_DWORD *)a2 + 34);
    *((_DWORD *)this + 35) = *((_DWORD *)a2 + 35);
    *((_DWORD *)this + 36) = *((_DWORD *)a2 + 36);
    *((_DWORD *)this + 37) = *((_DWORD *)a2 + 37);
    *((_DWORD *)this + 38) = *((_DWORD *)a2 + 38);
    *((_DWORD *)this + 39) = *((_DWORD *)a2 + 39);
    *((_DWORD *)this + 40) = *((_DWORD *)a2 + 40);
    *((_DWORD *)this + 41) = *((_DWORD *)a2 + 41);
    *((_DWORD *)this + 42) = *((_DWORD *)a2 + 42);
    *((_DWORD *)this + 43) = *((_DWORD *)a2 + 43);
    *((_DWORD *)this + 44) = *((_DWORD *)a2 + 44);
    *((_DWORD *)this + 45) = *((_DWORD *)a2 + 45);
    *((_DWORD *)this + 46) = *((_DWORD *)a2 + 46);
    memset((char *)this + 40, 0, 0x4Cu);
    result = (*(int (__thiscall **)(D3DXShader::CProgram *))(*(_DWORD *)this + 12))(a1: this);
    if ( result >= 0 )
    {
      result = D3DXShader::CProgram::SetName((void **)this, a2: nullptr);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6581
// Name: protected: long D3DXShader::CProgram::Validate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::Validate(D3DXShader::CProgram *this)
{
  unsigned int v2; // ecx
  int v3; // eax
  unsigned int j; // ecx
  int v5; // eax
  unsigned int k; // eax
  int v7; // ebx
  _DWORD *v8; // edi
  _DWORD *v9; // edx
  _DWORD *v10; // ecx
  int v11; // ecx
  _DWORD *n; // ecx
  int v13; // ecx
  _DWORD *v14; // edx
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edi
  _DWORD *v18; // edx
  _DWORD *v19; // edi
  _DWORD *v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  int v23; // eax
  unsigned int v24; // ecx
  _DWORD *v25; // edi
  int v26; // eax
  int v27; // eax
  int v28; // edi
  int v30; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  unsigned int m; // [esp+14h] [ebp-4h]
  unsigned int ii; // [esp+14h] [ebp-4h]
  unsigned int v34; // [esp+14h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < *((_DWORD *)this + 1); *(_DWORD *)(v3 + 36) = -1 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v2++);
    *(_DWORD *)(v3 + 40) = -1;
  }
  for ( j = 0; j < *((_DWORD *)this + 2); *(_DWORD *)(v5 + 72) = -1 )
  {
    v5 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * j++);
    *(_DWORD *)(v5 + 84) = -1;
  }
  for ( k = 0; k < *((_DWORD *)this + 3); ++k )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * k);
    v30 = v7;
    if ( (*(_WORD *)(v7 + 2) & 0xFFF0) != 0 )
    {
      for ( m = 0; m < *(_DWORD *)(v7 + 4); ++m )
      {
        v8 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 8) + 4 * m));
        if ( k < v8[21] )
          v8[21] = k;
        v9 = v8 + 2;
        v10 = v8;
        if ( v8[2] != -1 )
        {
          do
          {
            v11 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v10[1]);
            if ( k < *(_DWORD *)(v11 + 40) )
              *(_DWORD *)(v11 + 40) = k;
            v10 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v9);
            if ( k < v10[21] )
              v10[21] = k;
            v9 = v10 + 2;
          }
          while ( v10[2] != -1 );
          v7 = v30;
        }
        for ( n = v8 + 5; *n != -1; n = (_DWORD *)(v13 + 20) )
        {
          v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *n);
          if ( k < *(_DWORD *)(v13 + 84) )
            *(_DWORD *)(v13 + 84) = k;
        }
      }
      for ( ii = 0; ii < *(_DWORD *)(v7 + 12); ++ii )
      {
        v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * ii));
        if ( k < v14[18] )
          v14[18] = k;
        v15 = v14;
        if ( v14[2] != -1 )
        {
          v16 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v14[1]);
          if ( k < *(_DWORD *)(v16 + 36) )
            *(_DWORD *)(v16 + 36) = k;
          v15 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v14[2]);
          if ( k < v15[21] )
            v15[21] = k;
        }
        if ( v15[2] != -1 )
        {
          do
          {
            v17 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v15[1]);
            if ( k < *(_DWORD *)(v17 + 40) )
              *(_DWORD *)(v17 + 40) = k;
            v15 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v15[2]);
            if ( k < v15[21] )
              v15[21] = k;
          }
          while ( v15[2] != -1 );
          v7 = v30;
        }
        while ( 1 )
        {
          v18 = v14 + 5;
          if ( *v18 == -1 )
            break;
          v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *v18);
          if ( k < v14[21] )
            v14[21] = k;
        }
      }
    }
  }
  D3DXShader::CProgram::ReadWriteInfo_CommitOrigin(this);
  v34 = 0;
  if ( *((_DWORD *)this + 2) == 0 )
    return 0;
  do
  {
    v19 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v34);
    v20 = *(_DWORD **)(*((_DWORD *)this + 4) + 4 * v19[1]);
    v21 = v20[10];
    if ( v21 < v19[21] )
      v19[21] = v21;
    v22 = v20[9];
    if ( v22 < v19[18] )
      v19[18] = v22;
    v23 = v20[1];
    if ( (v23 & 0x10) == 0 )
    {
      v24 = v19[21];
      if ( v24 != -1 && v24 <= v19[18] )
      {
        v25 = (_DWORD *)v19[24];
        if ( v25 != nullptr && v25[1] == 6 && (v26 = v25[5]) != 0 && *(_DWORD *)(v26 + 4) == 3 )
        {
          if ( v25[10] == 0 )
          {
            D3DXShader::CProgram::Error(
              (D3DXShader::CTErrors **)this,
              a2: *(struct D3DXShader::CNode **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * v24) + 60),
              a3: 0xFA0u,
              format: "variable '%s' used without having been completely initialized",
              *(const char **)(v26 + 24));
            v25[10] = 1;
          }
        }
        else
        {
          D3DXShader::CProgram::Error(
            (D3DXShader::CTErrors **)this,
            a2: nullptr,
            a3: 0,
            format: "internal error: argument used without having been initialized (A%u, I%u)",
            v34,
            v24);
        }
        goto LABEL_77;
      }
    }
    if ( (v23 & 0x20) != 0 && v19[18] == -1 )
    {
      D3DXShader::CProgram::Error(
        (D3DXShader::CTErrors **)this,
        a2: nullptr,
        a3: 0,
        format: "internal error: output argument was never initialized (A%u)",
        v34);
LABEL_77:
      i = 1;
      goto LABEL_78;
    }
    if ( (v23 & 2) == 0 && v19[18] != -1 )
    {
      D3DXShader::CProgram::Error(
        (D3DXShader::CTErrors **)this,
        a2: nullptr,
        a3: 0,
        format: "internal error: cannot write to argument pool (A%u, I%u)",
        v34,
        v19[18]);
      goto LABEL_77;
    }
    if ( (v23 & 0xD) == 0 && v19[21] != -1 )
    {
      D3DXShader::CProgram::Error(
        (D3DXShader::CTErrors **)this,
        a2: nullptr,
        a3: 0,
        format: "internal error: cannot read from argument pool (A%u)",
        v34);
      goto LABEL_77;
    }
    if ( *((_DWORD *)this + 54) != 0
      && (v23 & 0x10120) == 0
      && v19[21] == -1
      && ((v23 & 0x10) != 0
       || (v27 = v19[18]) != -1
       && D3DXShader::CInstruction::IsSpecial(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v27)) == 0
       && (**(_DWORD **)(*((_DWORD *)this + 6) + 4 * v19[18]) & 0xFFF00000) != 0x20900000) )
    {
      v28 = v19[18];
      if ( v28 == -1 )
        D3DXShader::CProgram::Error(
          (D3DXShader::CTErrors **)this,
          a2: nullptr,
          a3: 0,
          format: "internal error: argument was never used (A%u)",
          v34);
      else
        D3DXShader::CProgram::Error(
          (D3DXShader::CTErrors **)this,
          a2: nullptr,
          a3: 0,
          format: "internal error: argument was never used (A%u, I%u)",
          v34,
          v28);
      goto LABEL_77;
    }
LABEL_78:
    ++v34;
  }
  while ( v34 < *((_DWORD *)this + 2) );
  if ( i != 0 )
    return -2147467259;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E68AC
// Name: private: long D3DXShader::CProgram::DeadLinkRemove(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::DeadLinkRemove(D3DXShader::CProgram *this)
{
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // edx
  struct D3DXShader::CInstruction *v5; // edi
  unsigned int v6; // eax
  _DWORD *v7; // edx
  int v8; // ecx
  unsigned int v9; // eax
  _DWORD *v10; // ebx
  unsigned int v11; // eax
  int result; // eax
  unsigned int j; // ecx
  _DWORD *v14; // eax
  int v15; // [esp+14h] [ebp-18h]
  int v16; // [esp+18h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-10h]
  D3DXShader::CInstruction *v18; // [esp+1Ch] [ebp-10h]
  unsigned int i; // [esp+20h] [ebp-Ch]
  unsigned int v20; // [esp+24h] [ebp-8h]
  unsigned int v21; // [esp+28h] [ebp-4h]
  unsigned int v22; // [esp+28h] [ebp-4h]

  v2 = *((_DWORD *)this + 2);
  v21 = 0;
  if ( v2 != 0 )
  {
    v3 = *((_DWORD *)this + 5);
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v3 + 12);
      if ( v4 > v21 && v4 != -1 )
        v21 = *(_DWORD *)(*(_DWORD *)v3 + 12);
      v3 += 4;
      --v2;
    }
    while ( v2 != 0 );
  }
  v22 = v21 + 1;
  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v5 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * i);
    v6 = *((_DWORD *)v5 + 3);
    if ( v6 != 0 )
    {
      v7 = *((_DWORD **)v5 + 4);
      v17 = *((_DWORD *)v5 + 3);
      do
      {
        v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v7);
        if ( *(_DWORD *)(v8 + 68) == -1
          && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v8 + 4)) + 4) & 0x20) != 0 )
        {
          --v6;
        }
        ++v7;
        --v17;
      }
      while ( v17 != 0 );
    }
    if ( v6 != *((_DWORD *)v5 + 3) )
    {
      v18 = nullptr;
      if ( v6 != 0 )
      {
        v9 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v6 & 0xFFFFF | 0x10000000, a3: v6, a4: v6);
        if ( v9 == -1 )
          return -2147024882;
        v18 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v9);
        D3DXShader::CInstruction::Instance(this: v18, a2: v5);
      }
      v20 = 0;
      if ( *((_DWORD *)v5 + 3) != 0 )
      {
        v16 = 0;
        do
        {
          v10 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v20));
          v15 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v10[1]);
          v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: v22, a4: v10[4], a5: 0.0);
          if ( v10[17] != -1 || (*(_BYTE *)(v15 + 4) & 0x20) == 0 )
          {
            *(_DWORD *)(v16 + *((_DWORD *)v18 + 4)) = *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v20);
            *(_DWORD *)(v16 + *((_DWORD *)v18 + 2)) = v11;
            v16 += 4;
          }
          *(_DWORD *)(*((_DWORD *)v5 + 4) + 4 * v20++) = v11;
        }
        while ( v20 < *((_DWORD *)v5 + 3) );
      }
      ++v22;
    }
  }
  result = D3DXShader::CProgram::ReadWriteInfo(this);
  if ( result >= 0 )
  {
    for ( j = 0; j < *((_DWORD *)this + 2); ++j )
    {
      v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * j);
      if ( v14[18] == -1 && v14[21] == -1 )
        v14[1] = *((_DWORD *)this + 29);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A42
// Name: protected: long D3DXShader::CProgram::DelayOutputs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::DelayOutputs(D3DXShader::CProgram *this)
{
  unsigned int v1; // ebx
  _DWORD *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int *v6; // edx
  unsigned int v7; // edx
  _DWORD *v9; // edi
  int v10; // eax
  _DWORD *v11; // ecx
  D3DXShader::CInstruction *v12; // edx
  _DWORD *v13; // edx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  struct D3DXShader::CInstruction *v18; // edi
  unsigned int v19; // ecx
  unsigned int v20; // eax
  _DWORD *v21; // edx
  unsigned int v22; // edx
  _DWORD *v23; // eax
  const void *v24; // [esp+8h] [ebp-30h]
  _DWORD *v25; // [esp+14h] [ebp-24h]
  unsigned int v26; // [esp+18h] [ebp-20h]
  _DWORD *v27; // [esp+1Ch] [ebp-1Ch]
  int v28; // [esp+20h] [ebp-18h]
  _DWORD *v29; // [esp+20h] [ebp-18h]
  unsigned int v30; // [esp+24h] [ebp-14h]
  D3DXShader::CInstruction *v31; // [esp+28h] [ebp-10h]
  D3DXShader::CInstruction *v32; // [esp+28h] [ebp-10h]
  int (__stdcall *pMem)(unsigned int, unsigned int, const void *); // [esp+2Ch] [ebp-Ch]
  unsigned int v34; // [esp+30h] [ebp-8h]
  unsigned int *v35; // [esp+34h] [ebp-4h]
  unsigned int *i; // [esp+34h] [ebp-4h]

  v1 = 0;
  pMem = nullptr;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v35 = nullptr;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v3 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v1);
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v3[1]) + 4) & 0x20) != 0 )
      {
        v4 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 34), a3: 0, a4: 0, a5: 0.0);
        v3[12] = v4;
        if ( v4 == -1 )
          goto LABEL_43;
        v35 = (unsigned int *)((char *)v35 + 1);
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v4) + 20) = v3[5];
        *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v3[12]) + 24) = v3[6];
      }
      else
      {
        v3[12] = v1;
      }
      ++v1;
    }
    while ( v1 < *((_DWORD *)this + 2) );
    if ( v35 == nullptr )
      goto LABEL_14;
    D3DXShader::CProgram::RemapArguments(this);
    pMem = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * (_DWORD)v35);
    if ( pMem != nullptr )
    {
      v5 = 0;
      for ( i = nullptr; v5 < *((_DWORD *)this + 2); ++v5 )
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v5) + 4))
                       + 4)
            & 0x20) != 0 )
        {
          v6 = i;
          i = (unsigned int *)((char *)i + 1);
          *((_DWORD *)pMem + (_DWORD)v6) = v5;
        }
      }
      D3DXShader::HeapSort(this: (D3DXShader *)sub_101E15F0, a2: pMem, a3: i, a4: (unsigned int)this, a5: v24);
      v7 = 0;
      v30 = 0;
      if ( i == nullptr )
        goto LABEL_14;
      while ( 1 )
      {
        v9 = (_DWORD *)((char *)pMem + 4 * v7);
        v10 = *((_DWORD *)this + 5);
        v11 = *(_DWORD **)(v10 + 4 * *v9);
        v12 = (D3DXShader::CInstruction *)(v7 + 1);
        v25 = v9;
        v34 = 1;
        if ( v12 < (D3DXShader::CInstruction *)i )
        {
          v31 = v12;
          v29 = v9 + 1;
          do
          {
            v13 = *(_DWORD **)(v10 + 4 * *v29);
            if ( v11[1] != v13[1] )
              break;
            if ( v11[2] != v13[2] )
              break;
            if ( v11[3] != v13[3] )
              break;
            ++v34;
            v31 = (D3DXShader::CInstruction *)((char *)v31 + 1);
            ++v29;
          }
          while ( v31 < (D3DXShader::CInstruction *)i );
        }
        v14 = D3DXShader::CBaseProgram::AddInstruction(
                this,
                a2: v34 & 0xFFFFF | 0x10000000,
                a3: 0xFFFFFFFF,
                a4: 0xFFFFFFFF);
        if ( v14 == -1 )
          break;
        v26 = 0;
        v32 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v14);
        if ( v34 != 0 )
        {
          v27 = v9;
          while ( 1 )
          {
            v15 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v27);
            v16 = *(_DWORD *)(v15 + 48);
            v17 = *(_DWORD *)(v15 + 72);
            if ( v17 != -1 )
              break;
LABEL_36:
            if ( *((_DWORD *)v32 + 15) == 0 )
            {
              ++v26;
              ++v27;
              if ( v26 < v34 )
                continue;
            }
            goto LABEL_38;
          }
          while ( 1 )
          {
            v18 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v17);
            if ( *((_DWORD *)v18 + 15) != 0 )
            {
              v28 = D3DXShader::CInstruction::Instance(this: v32, a2: v18);
              if ( v28 < 0 )
                goto LABEL_15;
            }
            if ( (*(_DWORD *)v18 & 0xFFF00000) == 0x10000000 )
            {
              v19 = *((_DWORD *)v18 + 3);
              v20 = 0;
              if ( v19 != 0 )
              {
                v21 = *((_DWORD **)v18 + 4);
                do
                {
                  if ( v16 == *v21 )
                    break;
                  ++v20;
                  ++v21;
                }
                while ( v20 < v19 );
              }
              v16 = *(_DWORD *)(*((_DWORD *)v18 + 2) + 4 * v20);
              v17 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v16) + 72);
              if ( v17 != -1 )
                continue;
            }
            v9 = v25;
            goto LABEL_36;
          }
        }
LABEL_38:
        v22 = 0;
        if ( v34 != 0 )
        {
          v23 = v9;
          do
          {
            *(_DWORD *)(*((_DWORD *)v32 + 2) + 4 * v22) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v23) + 48);
            *(_DWORD *)(*((_DWORD *)v32 + 4) + 4 * v22++) = *v23++;
          }
          while ( v22 < v34 );
        }
        v30 += v34;
        if ( v30 >= (unsigned int)i )
          goto LABEL_14;
        v7 = v30;
      }
    }
LABEL_43:
    v28 = -2147024882;
    goto LABEL_15;
  }
LABEL_14:
  v28 = 0;
LABEL_15:
  free(pMem);
  return v28;
}

//------------------------------------------------------------------------------
// Address: 0x101E6CCA
// Name: private: void D3DXShader::CProgram::RemoveDeadCode_Reference(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::RemoveDeadCode_Reference(
        D3DXShader::CProgram *this,
        unsigned int a2,
        unsigned int a3)
{
  unsigned int i; // eax
  _DWORD *v6; // esi
  unsigned int v7; // eax

  for ( i = a3; i != 0; i = v6[21] )
  {
    if ( a2 != -1 && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2) + 56) != -1 )
      a2 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a2) + 56);
    v6 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a2);
    if ( v6[21] < i )
      v6[21] = i;
    v7 = v6[2];
    if ( v7 != -1 )
      D3DXShader::CProgram::RemoveDeadCode_Reference(this, a2: v7, a3: v6[21]);
    a2 = v6[5];
    if ( a2 == -1 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6D28
// Name: protected: long D3DXShader::CProgram::RemoveDeadCode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::RemoveDeadCode(D3DXShader::CProgram *this)
{
  unsigned int v1; // esi
  unsigned int i; // ecx
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  int v7; // ecx
  int *v8; // esi
  int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // ebx
  unsigned int j; // ebx
  _DWORD *v17; // edx
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // ecx
  _DWORD *v21; // ecx
  _DWORD *ii; // esi
  int v23; // ecx
  int v24; // eax
  int *v25; // ecx
  int v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // esi
  bool v29; // zf
  int v30; // eax
  int v31; // edx
  int v32; // edx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // ebx
  int v37; // eax
  unsigned int v38; // esi
  bool v39; // zf
  _DWORD *v40; // eax
  unsigned int kk; // esi
  int v42; // ecx
  _DWORD *v43; // eax
  unsigned int v44; // edx
  int v45; // edx
  int v46; // ecx
  int v47; // ecx
  int v49; // [esp+Ch] [ebp-20h]
  unsigned int k; // [esp+14h] [ebp-18h]
  int v51; // [esp+14h] [ebp-18h]
  int v52; // [esp+14h] [ebp-18h]
  int v53; // [esp+18h] [ebp-14h]
  int v54; // [esp+18h] [ebp-14h]
  int v55; // [esp+1Ch] [ebp-10h]
  int v56; // [esp+1Ch] [ebp-10h]
  unsigned int jj; // [esp+1Ch] [ebp-10h]
  int v58; // [esp+20h] [ebp-Ch]
  int v59; // [esp+20h] [ebp-Ch]
  unsigned int v60; // [esp+20h] [ebp-Ch]
  unsigned int v61; // [esp+20h] [ebp-Ch]
  unsigned int m; // [esp+24h] [ebp-8h]
  unsigned int v63; // [esp+24h] [ebp-8h]
  unsigned int v64; // [esp+24h] [ebp-8h]
  unsigned int v65; // [esp+28h] [ebp-4h]
  unsigned int v66; // [esp+28h] [ebp-4h]
  unsigned int n; // [esp+28h] [ebp-4h]
  unsigned int v68; // [esp+28h] [ebp-4h]
  unsigned int v69; // [esp+28h] [ebp-4h]

  v1 = 0;
  v53 = 0;
  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0;
        i < *((_DWORD *)this + 2);
        *(_DWORD *)(v4 + 84) = (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v4 + 4)) + 4) & 0x10020) != 0
                             ? 2
                             : 0 )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * i++);
  }
  v5 = *((_DWORD *)this + 3);
  while ( v5 != 0 )
  {
    --v5;
    v6 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v5);
    if ( (*v6 & 0xFFF00000) == 0x20900000 && v6[3] != 0 )
    {
      do
      {
        v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * v1));
        if ( *(_DWORD *)(v7 + 84) != 2 )
          *(_DWORD *)(v7 + 84) = 1;
        ++v1;
      }
      while ( v1 < v6[3] );
    }
    v1 = 0;
  }
  do
  {
    v55 = 0;
    v58 = *((_DWORD *)this + 3);
    if ( v58 == 0 )
      break;
    do
    {
      --v58;
      v8 = *(int **)(*((_DWORD *)this + 6) + 4 * v58);
      v9 = *v8;
      if ( (*v8 & 0xFFF00000) != 0 )
      {
        if ( (v9 & 0xF0000000) < 0x10000000 || (v9 & 0xF0000000) > 0x40000000 )
        {
          v12 = v8[3];
          v66 = 0;
          if ( v12 != 0 )
          {
            v13 = *((_DWORD *)this + 5);
            v14 = (_DWORD *)v8[4];
            v51 = v8[3];
            do
            {
              if ( v66 < *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v14) + 84) )
                v66 = *(_DWORD *)(*(_DWORD *)(v13 + 4 * *v14) + 84);
              ++v14;
              --v51;
            }
            while ( v51 != 0 );
            if ( v66 == 1 )
              v55 = 1;
          }
          v15 = 0;
          if ( v12 != 0 )
          {
            do
              D3DXShader::CProgram::RemoveDeadCode_Reference(this, a2: *(_DWORD *)(v8[4] + 4 * v15++), a3: v66);
            while ( v15 < v8[3] );
          }
          for ( j = 0; j < v8[1]; ++j )
            D3DXShader::CProgram::RemoveDeadCode_Reference(this, a2: *(_DWORD *)(v8[2] + 4 * j), a3: v66);
        }
        else
        {
          v65 = 0;
          for ( k = v8[1] / (v9 & 0xFFFFFu); v65 < v8[3]; ++v65 )
          {
            v10 = *(_DWORD *)(v8[4] + 4 * v65);
            v11 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v10) + 84);
            if ( v11 == 1 )
              v55 = 1;
            D3DXShader::CProgram::RemoveDeadCode_Reference(this, a2: v10, a3: v11);
            for ( m = 0; m < k; ++m )
              D3DXShader::CProgram::RemoveDeadCode_Reference(
                this,
                a2: *(_DWORD *)(v8[2] + 4 * (v65 + m * v8[3])),
                a3: v11);
          }
        }
      }
    }
    while ( v58 != 0 );
    if ( v55 == 0 )
      break;
    v56 = 0;
    v63 = 0;
    if ( *((_DWORD *)this + 3) == 0 )
      break;
    do
    {
      v17 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v63);
      if ( (*v17 & 0xFFF00000) == 0x20900000 )
      {
        v18 = v17[3];
        for ( n = 0; n < v18; v18 = v17[3] )
        {
          v19 = *((_DWORD *)this + 5);
          v49 = *(_DWORD *)(v19 + 4 * *(_DWORD *)(v17[4] + 4 * n));
          if ( *(_DWORD *)(v49 + 84) == 1 )
          {
            v20 = *(_DWORD *)(v17[2] + 4 * (n + v18));
            if ( v20 != -1 && *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 56) != -1 )
              v20 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 56);
            v59 = 0;
            v52 = v20;
            v21 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(*(_DWORD *)(v19 + 4 * v20) + 72));
            if ( v21[3] != 0 )
            {
              for ( ii = (_DWORD *)v21[4]; *ii != v52; ++ii )
              {
                if ( (unsigned int)++v59 >= v21[3] )
                  break;
              }
            }
            v23 = *(_DWORD *)(v21[2] + 4 * v59);
            if ( v23 != -1 && *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 56) != -1 )
              v23 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 56);
            v24 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * v23) + 84);
            if ( v24 != 1 )
            {
              *(_DWORD *)(v49 + 84) = v24;
              v56 = 1;
            }
          }
          ++n;
        }
      }
      ++v63;
    }
    while ( v63 < *((_DWORD *)this + 3) );
  }
  while ( v56 != 0 );
  for ( jj = 0; jj < *((_DWORD *)this + 3); ++jj )
  {
    v25 = *(int **)(*((_DWORD *)this + 6) + 4 * jj);
    v26 = *v25;
    if ( (*v25 & 0xFFF00000) != 0 )
    {
      if ( (v26 & 0xF0000000) < 0x10000000 || (v26 & 0xF0000000) > 0x40000000 )
      {
        v38 = 0;
        v39 = v25[3] == 0;
        if ( v25[3] != 0 )
        {
          v40 = (_DWORD *)v25[4];
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v40) + 84) == 2 )
              break;
            ++v38;
            ++v40;
          }
          while ( v38 < v25[3] );
          v39 = v38 == v25[3];
        }
        if ( !v39 )
          continue;
        v37 = 0;
        *v25 = 0;
        v25[3] = 0;
      }
      else
      {
        v27 = v25[1] / (v26 & 0xFFFFFu);
        v28 = 0;
        v29 = v25[3] == 0;
        v68 = 0;
        v64 = v27;
        if ( v25[3] != 0 )
        {
          do
          {
            v30 = v25[4];
            v31 = *(_DWORD *)(v30 + 4 * v68);
            if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v31) + 84) == 2 )
            {
              v60 = 0;
              for ( *(_DWORD *)(v30 + 4 * v28) = v31;
                    v60 < v64;
                    *(_DWORD *)(v25[2] + 4 * (v28 + v32)) = *(_DWORD *)(v25[2] + 4 * (v32 + v68)) )
              {
                v32 = v60 * v25[3];
                ++v60;
              }
              ++v28;
            }
            ++v68;
          }
          while ( v68 < v25[3] );
          v29 = v28 == v25[3];
        }
        if ( v29 )
          continue;
        if ( v28 != 0 )
          v33 = *v25 ^ (v28 ^ *v25) & 0xFFFFF;
        else
          v33 = 0;
        *v25 = v33;
        v69 = 1;
        if ( v64 > 1 )
        {
          v54 = 4 * v28;
          do
          {
            v61 = 0;
            if ( v28 != 0 )
            {
              v34 = v54;
              do
              {
                v35 = v25[2];
                v36 = *(_DWORD *)(v35 + 4 * (v61 + v69 * v25[3]));
                ++v61;
                *(_DWORD *)(v34 + v35) = v36;
                v34 += 4;
              }
              while ( v61 < v28 );
            }
            ++v69;
            v54 += 4 * v28;
          }
          while ( v69 < v64 );
        }
        v37 = v64 * v28;
        v25[3] = v28;
      }
      v25[1] = v37;
      v53 = 1;
    }
  }
  for ( kk = 0; kk < *((_DWORD *)this + 2); ++kk )
  {
    v42 = *((_DWORD *)this + 5);
    v43 = *(_DWORD **)(v42 + 4 * kk);
    if ( kk == -1 || (v44 = v43[14]) == -1 )
      v44 = kk;
    if ( *(_DWORD *)(*(_DWORD *)(v42 + 4 * v44) + 84) != 2 )
    {
      v45 = *((_DWORD *)this + 29);
      v46 = v43[1];
      if ( v45 != v46 && (v43[2] != -1 || (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v46) + 5) & 4) == 0) )
      {
        v47 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v46) + 4);
        if ( (v47 & 0x100) == 0 || (v47 & 0x800) == 0 )
        {
          v43[1] = v45;
          v53 = 1;
        }
      }
    }
  }
  return v53 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E71DA
// Name: protected: long D3DXShader::CProgram::MergeInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXShader::CProgram::MergeInstructions@<eax>(D3DXShader::CProgram *this@<ecx>, const void *a2@<ebx>)
{
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // eax
  D3DXShader::CInstruction *v7; // edi
  int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ebx
  bool v11; // zf
  _DWORD *v12; // edx
  unsigned int *v13; // edx
  _DWORD *v14; // eax
  D3DXShader::CInstruction *v15; // edi
  unsigned int v16; // ecx
  int v17; // edx
  _DWORD *v18; // ecx
  int v19; // edx
  _DWORD *v20; // eax
  unsigned int v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // eax
  struct D3DXShader::CInstruction *v25; // edi
  struct D3DXShader::CInstruction *v26; // ebx
  unsigned int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edi
  int v30; // eax
  int v31; // ecx
  const void *v33; // [esp-4h] [ebp-60h]
  unsigned int v34; // [esp+8h] [ebp-54h]
  int v35; // [esp+Ch] [ebp-50h]
  int ii; // [esp+10h] [ebp-4Ch]
  int j; // [esp+10h] [ebp-4Ch]
  _DWORD *v38; // [esp+14h] [ebp-48h]
  D3DXShader::CInstruction *v39; // [esp+14h] [ebp-48h]
  unsigned int v40; // [esp+18h] [ebp-44h]
  _DWORD *v41; // [esp+1Ch] [ebp-40h]
  int i; // [esp+20h] [ebp-3Ch]
  unsigned int v43; // [esp+24h] [ebp-38h]
  int v44; // [esp+24h] [ebp-38h]
  int (__stdcall *v45)(unsigned int, unsigned int, const void *); // [esp+28h] [ebp-34h]
  _DWORD *v46; // [esp+2Ch] [ebp-30h]
  int (__stdcall *pMem)(unsigned int, unsigned int, const void *); // [esp+30h] [ebp-2Ch]
  int k; // [esp+34h] [ebp-28h]
  _DWORD *v49; // [esp+38h] [ebp-24h]
  int IsSymetric; // [esp+3Ch] [ebp-20h]
  unsigned int v51; // [esp+40h] [ebp-1Ch]
  unsigned int v52; // [esp+40h] [ebp-1Ch]
  unsigned int n; // [esp+40h] [ebp-1Ch]
  unsigned int v54; // [esp+44h] [ebp-18h]
  unsigned int v55; // [esp+44h] [ebp-18h]
  unsigned int m; // [esp+44h] [ebp-18h]
  unsigned int v57; // [esp+48h] [ebp-14h]
  unsigned int *v58; // [esp+4Ch] [ebp-10h]
  unsigned int v59; // [esp+50h] [ebp-Ch]
  struct D3DXShader::CInstruction *v60; // [esp+54h] [ebp-8h]
  unsigned int v61; // [esp+58h] [ebp-4h]
  unsigned int v62; // [esp+58h] [ebp-4h]
  unsigned int v63; // [esp+58h] [ebp-4h]

  pMem = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 2));
  if ( pMem != nullptr )
  {
    v33 = a2;
    for ( i = 0; ; ++i )
    {
      v35 = 0;
      v58 = nullptr;
      D3DXShader::CProgram::ReadWriteInfo(this);
      D3DXShader::CProgram::IdentityRemap(this);
      v61 = 0;
      if ( *((_DWORD *)this + 2) != 0 )
        break;
LABEL_30:
      D3DXShader::HeapSort(this: (D3DXShader *)sub_101E19AA, a2: pMem, a3: v58, a4: (unsigned int)this, a5: v33);
      if ( v58 == nullptr )
        goto LABEL_88;
      v44 = 1;
      v45 = pMem;
      for ( j = (int)v58; j != 0; --j )
      {
        v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)v45);
        v15 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v14[18]);
        v49 = v14;
        v39 = v15;
        if ( v14[12] == *(_DWORD *)v45 )
        {
          v16 = v44;
          for ( k = v44; v16 < (unsigned int)v58; v16 = k )
          {
            v17 = *((_DWORD *)pMem + k);
            v18 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v17);
            v41 = v18;
            if ( v14[16] != v18[16] )
              break;
            if ( v18[12] == v17 )
            {
              v19 = v18[18];
              if ( v14[18] != v19
                && v14[1] == v18[1]
                && v14[5] == v18[5]
                && v14[6] == v18[6]
                && ((*(_DWORD *)v15 ^ **(_DWORD **)(*((_DWORD *)this + 6) + 4 * v19)) & 0xFFF00000) == 0 )
              {
                v59 = *((_DWORD *)v15 + 1) / (*(_DWORD *)v15 & 0xFFFFFu);
                v52 = 0;
                IsSymetric = D3DXShader::CInstruction::IsSymetric(this: v15);
                while ( 1 )
                {
                  v20 = v41;
                  if ( v52 == 0 )
                    v20 = v49;
                  v21 = v20[18];
                  v22 = v49;
                  v40 = v21;
                  if ( v52 == 0 )
                    v22 = v41;
                  v23 = v22[18];
                  v24 = *((_DWORD *)this + 6);
                  v25 = *(struct D3DXShader::CInstruction **)(v24 + 4 * v23);
                  v26 = *(struct D3DXShader::CInstruction **)(v24 + 4 * v21);
                  v55 = 0;
                  v60 = v26;
                  if ( *((_DWORD *)v25 + 3) != 0 )
                  {
                    v46 = *((_DWORD **)v25 + 4);
                    do
                    {
                      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v46) + 84) <= v21 )
                        break;
                      v57 = 0;
                      if ( *((_DWORD *)v26 + 3) != 0 )
                      {
                        do
                        {
                          v62 = 0;
                          if ( v59 != 0 )
                          {
                            while ( 1 )
                            {
                              v34 = D3DXShader::CProgram::MergeInstructions_Input(
                                      this,
                                      a2: v25,
                                      a3: v62,
                                      a4: v55,
                                      a5: IsSymetric);
                              if ( D3DXShader::CProgram::MergeInstructions_Input(
                                     this,
                                     a2: v26,
                                     a3: v62,
                                     a4: v57,
                                     a5: IsSymetric) != v34 )
                                break;
                              if ( ++v62 >= v59 )
                                break;
                              v26 = v60;
                            }
                            v26 = v60;
                          }
                          if ( v62 == v59 )
                            break;
                          ++v57;
                        }
                        while ( v57 < *((_DWORD *)v26 + 3) );
                        v21 = v40;
                      }
                      if ( v57 == *((_DWORD *)v26 + 3) )
                        break;
                      ++v55;
                      ++v46;
                    }
                    while ( v55 < *((_DWORD *)v25 + 3) );
                  }
                  if ( v55 >= *((_DWORD *)v25 + 3) )
                    break;
                  if ( ++v52 >= 2 )
                    goto LABEL_76;
                }
                for ( m = 0; m < *((_DWORD *)v25 + 3); *(_DWORD *)(v28 + 48) = *(_DWORD *)(*((_DWORD *)v26 + 4) + 4 * n) )
                {
                  for ( n = 0; n < *((_DWORD *)v26 + 3); ++n )
                  {
                    v63 = 0;
                    if ( v59 != 0 )
                    {
                      while ( 1 )
                      {
                        v27 = D3DXShader::CProgram::MergeInstructions_Input(
                                this,
                                a2: v26,
                                a3: v63,
                                a4: n,
                                a5: IsSymetric);
                        if ( v27 != D3DXShader::CProgram::MergeInstructions_Input(
                                      this,
                                      a2: v25,
                                      a3: v63,
                                      a4: m,
                                      a5: IsSymetric) )
                          break;
                        if ( ++v63 >= v59 )
                          break;
                        v26 = v60;
                      }
                      v26 = v60;
                    }
                    if ( v63 == v59 )
                      break;
                  }
                  v28 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*((_DWORD *)v25 + 4) + 4 * m++));
                }
                *(_DWORD *)v25 = 0;
                v35 = 1;
LABEL_76:
                v14 = v49;
                v15 = v39;
              }
            }
            ++k;
          }
        }
        v45 = (int (__stdcall *)(unsigned int, unsigned int, const void *))((char *)v45 + 4);
        ++v44;
      }
      if ( v35 == 0 )
      {
LABEL_88:
        v3 = i == 0;
        goto LABEL_89;
      }
      v29 = 0;
      if ( *((_DWORD *)this + 2) != 0 )
      {
        v30 = *((_DWORD *)this + 5);
        do
        {
          v31 = *(_DWORD *)(v30 + 4 * v29);
          while ( *(_DWORD *)(v31 + 48) != *(_DWORD *)(*(_DWORD *)(v30 + 4 * *(_DWORD *)(v31 + 48)) + 48) )
          {
            *(_DWORD *)(v31 + 48) = *(_DWORD *)(*(_DWORD *)(v30 + 4 * *(_DWORD *)(v31 + 48)) + 48);
            v30 = *((_DWORD *)this + 5);
          }
          ++v29;
        }
        while ( v29 < *((_DWORD *)this + 2) );
      }
      D3DXShader::CProgram::RemapArguments(this);
    }
    while ( 1 )
    {
      v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v61);
      v38 = v4;
      if ( v4[2] == -1 )
      {
        v5 = v4[18];
        if ( v5 != -1 )
        {
          v6 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v4[1]) + 4);
          if ( (v6 & 2) != 0 && (v6 & 0x20) == 0 )
          {
            v7 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v5);
            v8 = *(_DWORD *)v7;
            v9 = *(_DWORD *)v7 & 0xF0000000;
            if ( v9 >= 0x10000000 && v9 <= 0x40000000 )
            {
              v10 = v8 & 0xFFF00000;
              if ( (v8 & 0xFFF00000) > 0x11400000 )
              {
                if ( v10 != 290455552 && v10 != 544210944 && v10 != 545259520 )
                {
                  v11 = v10 == 546308096;
LABEL_21:
                  if ( !v11 )
                  {
                    v51 = 0;
                    if ( *((_DWORD *)v7 + 3) != 0 )
                    {
                      v12 = *((_DWORD **)v7 + 4);
                      do
                      {
                        if ( v61 == *v12 )
                          break;
                        ++v51;
                        ++v12;
                      }
                      while ( v51 < *((_DWORD *)v7 + 3) );
                    }
                    v43 = *((_DWORD *)v7 + 1) / (v8 & 0xFFFFFu);
                    v54 = 0;
                    for ( ii = D3DXShader::CInstruction::IsSymetric(this: v7); v54 < v43; ++v54 )
                      v10 = D3DXShader::CProgram::MergeInstructions_Input(this, a2: v7, a3: v54, a4: v51, a5: ii)
                          + 2111 * v10;
                    v13 = v58;
                    v58 = (unsigned int *)((char *)v58 + 1);
                    v38[16] = v10;
                    *((_DWORD *)pMem + (_DWORD)v13) = v61;
                  }
                }
              }
              else if ( (v8 & 0xFFF00000) != 0x11400000 && v10 != 284164096 && v10 != 286261248 && v10 != 287309824 )
              {
                v11 = v10 == 288358400;
                goto LABEL_21;
              }
            }
          }
        }
      }
      if ( ++v61 >= *((_DWORD *)this + 2) )
        goto LABEL_30;
    }
  }
  v3 = -2147024882;
LABEL_89:
  free(pMem);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101E7689
// Name: protected: long D3DXShader::CProgram::SimplifyAddresses(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SimplifyAddresses(D3DXShader::CProgram *this)
{
  int v2; // ebx
  _DWORD *v3; // edi
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  int v7; // edx
  int v8; // eax
  double v9; // st7
  int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // edi
  _DWORD *v13; // eax
  int v14; // eax
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  _DWORD *v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // eax
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // ecx
  int v32; // [esp+14h] [ebp-1Ch]
  int v33; // [esp+18h] [ebp-18h]
  int v34; // [esp+18h] [ebp-18h]
  int v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+20h] [ebp-10h]
  int v37; // [esp+24h] [ebp-Ch]
  int v38; // [esp+24h] [ebp-Ch]
  int v39; // [esp+24h] [ebp-Ch]
  unsigned int v40; // [esp+28h] [ebp-8h]
  unsigned int v41; // [esp+2Ch] [ebp-4h]
  _DWORD *v42; // [esp+2Ch] [ebp-4h]
  unsigned int v43; // [esp+2Ch] [ebp-4h]

  v37 = 0;
  v36 = 0;
  v35 = 0;
  v40 = 0;
  if ( *((_DWORD *)this + 2) == 0 )
    return 1;
  do
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v40);
    if ( *((_DWORD *)this + 29) != *(_DWORD *)(v2 + 4) )
    {
      v3 = (_DWORD *)(v2 + 8);
      if ( *(_DWORD *)(v2 + 8) != -1 )
      {
        if ( v35 == 0 )
        {
          D3DXShader::CProgram::ReadWriteInfo(this);
          v35 = 1;
        }
        v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3) + 72);
        v32 = *v3;
        if ( v4 != -1 )
        {
          v5 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v4);
          if ( (*v5 & 0xFFF00000) == 0x10000000 )
          {
            v41 = 0;
            if ( v5[3] != 0 )
            {
              v6 = (_DWORD *)v5[4];
              do
              {
                if ( *v6 == *v3 )
                  break;
                ++v41;
                ++v6;
              }
              while ( v41 < v5[3] );
            }
            v3 = (_DWORD *)(v5[2] + 4 * v41);
          }
        }
        v7 = *v3;
        v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v3);
        v42 = v3;
        if ( (*((_BYTE *)this + 111) & 1) != 0 )
          v9 = 0.0;
        else
          v9 = 0.5;
        v10 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v8 + 4)) + 4);
        if ( (v10 & 0x100) != 0 && *(_DWORD *)(v8 + 8) == -1 )
        {
          v11 = *((_DWORD *)this + 2);
          v43 = 0;
          v12 = *(_DWORD *)(v2 + 12) + (__int64)(v9 + *(double *)(v8 + 32));
          if ( v11 != 0 )
          {
            v38 = *((_DWORD *)this + 5);
            while ( 1 )
            {
              if ( v43 != v40 )
              {
                v13 = *(_DWORD **)v38;
                if ( *(_DWORD *)(*(_DWORD *)v38 + 4) == *(_DWORD *)(v2 + 4)
                  && v13[2] == -1
                  && v13[3] == v12
                  && v13[4] == *(_DWORD *)(v2 + 16)
                  && v13[5] == *(_DWORD *)(v2 + 20)
                  && v13[6] == *(_DWORD *)(v2 + 24) )
                {
                  break;
                }
              }
              ++v43;
              v38 += 4;
              if ( v43 >= v11 )
                goto LABEL_32;
            }
            if ( v36 == 0 )
            {
              D3DXShader::CProgram::IdentityRemap(this);
              v36 = 1;
            }
            *(_DWORD *)(v2 + 48) = v43;
          }
LABEL_32:
          if ( v43 == *((_DWORD *)this + 2) )
          {
            *(_DWORD *)(v2 + 8) = -1;
            v14 = *(_DWORD *)(v2 + 4);
            *(_DWORD *)(v2 + 12) = v12;
            if ( v12 >= *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v14) + 8) )
            {
              D3DXShader::CProgram::Error(
                (D3DXShader::CTErrors **)this,
                a2: *(struct D3DXShader::CNode **)(v2 + 96),
                a3: 0xFA7u,
                format: "array index out of bounds");
              return -2147467259;
            }
          }
          goto LABEL_65;
        }
        if ( (v10 & 2) != 0 )
        {
          v16 = *(_DWORD *)(v8 + 72);
          if ( v16 != -1 )
          {
            v17 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v16);
            if ( (*v17 & 0xFFF00000) == 0x20400000 )
            {
              v18 = v17[3];
              v19 = 0;
              if ( v18 != 0 )
              {
                v20 = (_DWORD *)v17[4];
                do
                {
                  if ( *v20 == v7 )
                    break;
                  ++v19;
                  ++v20;
                }
                while ( v19 < v18 );
              }
              v21 = v17[2];
              v22 = *(_DWORD *)(v21 + 4 * v19);
              v23 = *((_DWORD *)this + 5);
              v24 = *(_DWORD *)(v21 + 4 * (v19 + v18));
              v25 = *((_DWORD *)this + 4);
              v33 = v22;
              v26 = *(_DWORD *)(v23 + 4 * v22);
              v27 = *(_DWORD *)(v23 + 4 * v24);
              if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v26 + 8) == -1
                && (*(_DWORD *)v26 & 4) != 0
                && ((*(_DWORD *)v26 & 2) != 0 || (*(_BYTE *)v27 & 2) != 0) )
              {
                v39 = (__int64)(v9 + *(double *)(v26 + 32));
                v28 = v24;
                goto LABEL_54;
              }
              if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v27 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v27 + 8) == -1
                && (*(_DWORD *)v27 & 4) != 0
                && ((*(_BYTE *)v26 & 2) != 0 || (*(_DWORD *)v27 & 2) != 0) )
              {
                v39 = (__int64)(v9 + *(double *)(v27 + 32));
                v28 = v33;
LABEL_54:
                v29 = 0;
                v34 = v28;
                if ( *v42 == v32 )
                {
                  if ( *((_DWORD *)this + 2) != 0 )
                  {
                    do
                    {
                      v30 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v29);
                      if ( v32 == *(_DWORD *)(v30 + 8) )
                      {
                        *(_DWORD *)(v30 + 12) += v39;
                        *(_DWORD *)(v30 + 8) = v28;
                      }
                      ++v29;
                    }
                    while ( v29 < *((_DWORD *)this + 2) );
                  }
                }
                else
                {
                  if ( *((_DWORD *)this + 2) != 0 )
                  {
                    do
                    {
                      v31 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v29);
                      if ( v32 == *(_DWORD *)(v31 + 8) )
                      {
                        *(_DWORD *)(v31 + 12) += v39;
                        v28 = v34;
                      }
                      ++v29;
                    }
                    while ( v29 < *((_DWORD *)this + 2) );
                  }
                  *v42 = v28;
                }
LABEL_65:
                v37 = 1;
              }
            }
          }
        }
      }
    }
    ++v40;
  }
  while ( v40 < *((_DWORD *)this + 2) );
  if ( v37 == 0 )
    return 1;
  if ( v36 != 0 )
    D3DXShader::CProgram::RemapArguments(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E798D
// Name: protected: long D3DXShader::CProgram::SimplifyPredicates(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::SimplifyPredicates(D3DXShader::CProgram *this)
{
  D3DXShader::CProgram *v1; // esi
  unsigned int v2; // edi
  int *v3; // ebx
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  _DWORD *v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  unsigned int v18; // eax
  int *v19; // ebx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // edx
  int v29; // edi
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // edi
  _DWORD *v34; // ecx
  int v35; // edi
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  _DWORD *v39; // eax
  int v40; // edx
  int v41; // edx
  _DWORD *v42; // edi
  int v43; // ecx
  int v44; // ecx
  unsigned int v45; // edx
  int v46; // eax
  void *v47; // edi
  int v48; // edi
  bool v49; // zf
  int v50; // eax
  int v51; // ecx
  int *v52; // eax
  double *v53; // edx
  double v54; // st7
  int v55; // eax
  int v56; // edi
  unsigned int v58; // [esp+14h] [ebp-38h]
  unsigned int k; // [esp+14h] [ebp-38h]
  int v60; // [esp+14h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-30h]
  unsigned int v63; // [esp+1Ch] [ebp-30h]
  int v64; // [esp+1Ch] [ebp-30h]
  unsigned int v65; // [esp+1Ch] [ebp-30h]
  _DWORD *v66; // [esp+1Ch] [ebp-30h]
  int v67; // [esp+20h] [ebp-2Ch]
  int v68; // [esp+20h] [ebp-2Ch]
  int v69; // [esp+24h] [ebp-28h]
  int v70; // [esp+28h] [ebp-24h]
  unsigned int v71; // [esp+2Ch] [ebp-20h]
  unsigned int v72; // [esp+2Ch] [ebp-20h]
  int v73; // [esp+30h] [ebp-1Ch]
  int v74; // [esp+30h] [ebp-1Ch]
  int v75; // [esp+30h] [ebp-1Ch]
  unsigned int v76; // [esp+30h] [ebp-1Ch]
  int v77; // [esp+30h] [ebp-1Ch]
  double *v78; // [esp+30h] [ebp-1Ch]
  _DWORD *v79; // [esp+34h] [ebp-18h]
  unsigned int v80; // [esp+34h] [ebp-18h]
  unsigned int i; // [esp+38h] [ebp-14h]
  int v82; // [esp+38h] [ebp-14h]
  unsigned int v83; // [esp+38h] [ebp-14h]
  unsigned int v84; // [esp+38h] [ebp-14h]
  unsigned int v85; // [esp+38h] [ebp-14h]
  unsigned int v86; // [esp+38h] [ebp-14h]
  unsigned int v87; // [esp+38h] [ebp-14h]
  unsigned int v88; // [esp+3Ch] [ebp-10h]
  unsigned int j; // [esp+3Ch] [ebp-10h]
  unsigned int v90; // [esp+40h] [ebp-Ch]
  unsigned int v91; // [esp+40h] [ebp-Ch]
  int v92; // [esp+40h] [ebp-Ch]
  unsigned int v93; // [esp+44h] [ebp-8h]
  int v94; // [esp+44h] [ebp-8h]
  int v95; // [esp+44h] [ebp-8h]
  int v96; // [esp+48h] [ebp-4h]

  v1 = this;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v67 = -1;
  v62 = -1;
  v2 = 0;
  v96 = 0;
  for ( i = 0; i < *((_DWORD *)v1 + 3); ++i )
  {
    v3 = *(int **)(*((_DWORD *)v1 + 6) + 4 * i);
    v4 = *v3;
    if ( (*v3 & 0xFFF00000) != 0 && (v4 & 0xF0000000) >= 0x10000000 && (v4 & 0xF0000000) <= 0x40000000 )
    {
      v93 = 0;
      v58 = v3[1] / (v4 & 0xFFFFFu);
      if ( v58 != 0 )
      {
        do
        {
          v5 = v3[3];
          v73 = 0;
          v88 = 0;
          if ( v5 != 0 )
          {
            do
            {
              v6 = *(_DWORD *)(v3[2] + 4 * (v88 + v93 * v5));
              v7 = *((_DWORD *)v1 + 5);
              v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(v3[4] + 4 * v88));
              v71 = v6;
              v69 = v8;
              if ( (**(_BYTE **)(v7 + 4 * v6) & 1) != 0 )
              {
                v9 = *(_DWORD *)(v8 + 20);
                v70 = *(_DWORD *)(v8 + 24);
                while ( v9 != -1 )
                {
                  v90 = 0;
                  v10 = 4 * v9;
                  v11 = *(_DWORD **)(*((_DWORD *)v1 + 6)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * v9) + 72));
                  if ( v11[3] != 0 )
                  {
                    v79 = (_DWORD *)v11[4];
                    do
                    {
                      if ( *v79 == v9 )
                        break;
                      ++v90;
                      ++v79;
                    }
                    while ( v90 < v11[3] );
                  }
                  v12 = v11[2];
                  if ( v70 != 0 )
                  {
                    if ( D3DXShader::CProgram::MulSequence(this: v1, a2: v71, a3: *(_DWORD *)(v12 + 4 * v90)) != 0 )
                    {
                      *(_DWORD *)(v69 + 64) = 1;
LABEL_21:
                      ++v73;
                      break;
                    }
                  }
                  else if ( D3DXShader::CProgram::MulSequence(this: v1, a2: *(_DWORD *)(v12 + 4 * v90), a3: v71) != 0 )
                  {
                    *(_DWORD *)(v69 + 64) = 0;
                    goto LABEL_21;
                  }
                  v13 = *(_DWORD *)(v10 + *((_DWORD *)v1 + 5));
                  v70 = *(_DWORD *)(v13 + 24);
                  v9 = *(_DWORD *)(v13 + 20);
                }
              }
              ++v88;
              v5 = v3[3];
            }
            while ( v88 < v5 );
            v2 = 0;
          }
          v14 = v3[3];
          if ( v73 == v14 )
          {
            if ( v14 != 0 )
            {
              do
              {
                v15 = *((_DWORD *)v1 + 5);
                v16 = *(_DWORD *)(v15 + 4 * *(_DWORD *)(v3[2] + 4 * (v2 + v93 * v14)));
                v49 = *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)(v3[4] + 4 * v2)) + 64) == 0;
                v17 = *(_DWORD *)(*((_DWORD *)v1 + 4) + 4 * *(_DWORD *)(v16 + 4));
                if ( v49 )
                {
                  if ( (*(_BYTE *)(v17 + 5) & 1) != 0 && 0.0 == *(double *)(v16 + 32) )
                    goto LABEL_36;
                  v18 = v62;
                  if ( v62 == -1 )
                  {
                    v18 = D3DXShader::CBaseProgram::AddArgument(
                            this: v1,
                            a2: *((_DWORD *)v1 + 30),
                            a3: 0,
                            a4: 0,
                            a5: 0.0);
                    v62 = v18;
                  }
                }
                else
                {
                  if ( (*(_BYTE *)(v17 + 5) & 1) != 0 && 1.0 == *(double *)(v16 + 32) )
                    goto LABEL_36;
                  v18 = v67;
                  if ( v67 == -1 )
                  {
                    v18 = D3DXShader::CBaseProgram::AddArgument(
                            this: v1,
                            a2: *((_DWORD *)v1 + 30),
                            a3: 0,
                            a4: 0,
                            a5: 1.0);
                    v67 = v18;
                  }
                }
                *(_DWORD *)(v3[2] + 4 * (v2 + v93 * v3[3])) = v18;
                v96 = 1;
LABEL_36:
                v14 = v3[3];
                ++v2;
              }
              while ( v2 < v14 );
            }
            v2 = 0;
          }
          ++v93;
        }
        while ( v93 < v58 );
      }
    }
  }
  v72 = 0;
  D3DXShader::CProgram::IdentityRemap(this: v1);
  v80 = 0;
  if ( *((_DWORD *)v1 + 3) == 0 )
    return v96 == 0;
  do
  {
    v19 = *(int **)(*((_DWORD *)v1 + 6) + 4 * v80);
    if ( (*((_WORD *)v19 + 1) & 0xFFF0) == 0 )
      goto LABEL_123;
    for ( j = 0; j < v19[3]; *(_DWORD *)(v21 + 24) = v82 )
    {
      v20 = *((_DWORD *)v1 + 5);
      v21 = *(_DWORD *)(v20 + 4 * *(_DWORD *)(v19[4] + 4 * j));
      v22 = *(_DWORD *)(v21 + 20);
      v82 = *(_DWORD *)(v21 + 24);
      while ( v22 != -1 )
      {
        v23 = *(_DWORD *)(v20 + 4 * v22);
        if ( *(char *)v23 >= 0 )
          break;
        if ( v82 != 0 )
        {
          if ( 0.0 == *(double *)(v23 + 32) )
          {
LABEL_47:
            v82 = 0;
            v22 = -1;
            goto LABEL_48;
          }
        }
        else if ( 0.0 != *(double *)(v23 + 32) )
        {
          goto LABEL_47;
        }
        v32 = *(_DWORD *)(4 * v22 + *((_DWORD *)v1 + 5));
        v33 = *(_DWORD *)(v32 + 24);
        v22 = *(_DWORD *)(v32 + 20);
        v82 = v33;
LABEL_48:
        v96 = 1;
      }
      ++j;
      *(_DWORD *)(v21 + 20) = v22;
    }
    v24 = *v19;
    v25 = *v19 & 0xFFF00000;
    if ( v25 != 284164096 && v25 != 289406976 )
    {
      if ( v25 != 544210944 && v25 != 545259520 )
      {
        if ( (v24 & 0xF0000000) < 0x10000000 || (v24 & 0xF0000000) > 0x40000000 )
        {
          if ( v19[3] != 0 )
          {
            v75 = 0;
            v34 = (_DWORD *)v19[4];
            v35 = v19[3];
            do
            {
              v36 = *(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * *v34);
              if ( *(_DWORD *)(v36 + 20) != -1 || *(_DWORD *)(v36 + 24) != 0 )
                ++v75;
              ++v34;
              --v35;
            }
            while ( v35 != 0 );
            if ( v75 == 0 )
            {
              v37 = 0;
              v19[1] = 0;
              v19[3] = 0;
              goto LABEL_121;
            }
          }
          goto LABEL_123;
        }
        v26 = v19[1] / (v24 & 0xFFFFFu);
        v94 = 0;
        v91 = 0;
        for ( k = v26; v91 < v19[3]; ++v91 )
        {
          v27 = v19[4];
          v28 = *(_DWORD *)(v27 + 4 * v91);
          v29 = *(_DWORD *)(*((_DWORD *)v1 + 5) + 4 * v28);
          if ( *(_DWORD *)(v29 + 20) != -1 || *(_DWORD *)(v29 + 24) != 0 )
          {
            v83 = 0;
            *(_DWORD *)(v27 + 4 * v94) = v28;
            if ( v26 != 0 )
            {
              do
              {
                v30 = v83 * v19[3];
                ++v83;
                *(_DWORD *)(v19[2] + 4 * (v94 + v30)) = *(_DWORD *)(v19[2] + 4 * (v30 + v91));
                v26 = k;
              }
              while ( v83 < k );
            }
            ++v94;
          }
        }
        if ( v94 == v19[3] )
          goto LABEL_123;
        v84 = 0;
        if ( v26 != 0 )
        {
          v74 = 0;
          v63 = 4 * v94;
          do
          {
            qmemcpy((void *)(v19[2] + v74), (const void *)(v19[2] + 4 * v84 * v19[3]), v63);
            ++v84;
            v74 += v63;
          }
          while ( v84 < v26 );
        }
        if ( v94 != 0 )
          v31 = *v19 ^ (v94 ^ *v19) & 0xFFFFF;
        else
          v31 = 0;
        v1 = this;
        *v19 = v31;
        v19[3] = v94;
        v19[1] = v94 * v26;
LABEL_122:
        v96 = 1;
        goto LABEL_123;
      }
      v92 = 0;
      v95 = 0;
      v76 = v19[1] / (v24 & 0xFFFFFu);
      if ( v19[3] == 0 )
      {
LABEL_96:
        if ( v92 == v19[3] )
          goto LABEL_123;
        v45 = v76;
        v86 = 0;
        if ( v76 != 0 )
        {
          v77 = 0;
          v65 = 4 * v92;
          do
          {
            v46 = v19[2];
            v47 = (void *)(v46 + v77);
            v77 += v65;
            qmemcpy(v47, (const void *)(v46 + 4 * v86 * v19[3]), v65);
            ++v86;
          }
          while ( v86 < v45 );
        }
        if ( v92 != 0 )
          v37 = *v19 ^ (v92 ^ *v19) & 0xFFFFF;
        else
          v37 = 0;
        v1 = this;
        v19[3] = v92;
        v19[1] = v92 * v45;
LABEL_121:
        *v19 = v37;
        goto LABEL_122;
      }
      while ( 1 )
      {
        v38 = *((_DWORD *)v1 + 5);
        v60 = *(_DWORD *)(4 * v95 + v19[4]);
        v39 = *(_DWORD **)(v38 + 4 * v60);
        if ( v39[5] != -1 || v39[6] != 0 )
        {
          v40 = v19[2];
          v64 = *(_DWORD *)(4 * v95 + v40);
          v41 = *(_DWORD *)(v40 + 4 * (v95 + v19[3]));
          v42 = *(_DWORD **)(v38 + 4 * v64);
          if ( v42[5] != -1 || v42[6] != 0 )
          {
            v43 = *(_DWORD *)(v38 + 4 * v41);
            if ( *(_DWORD *)(v43 + 20) != -1 || *(_DWORD *)(v43 + 24) != 0 )
            {
              v85 = 0;
              for ( *(_DWORD *)(v19[4] + 4 * v92) = v60;
                    v85 < v76;
                    *(_DWORD *)(v19[2] + 4 * (v92 + v44)) = *(_DWORD *)(v19[2] + 4 * (v44 + v95)) )
              {
                v44 = v85 * v19[3];
                ++v85;
              }
              ++v92;
              goto LABEL_95;
            }
            v42[1] = *((_DWORD *)v1 + 34);
            v39[12] = v64;
          }
          else
          {
            *(_DWORD *)(*(_DWORD *)(v38 + 4 * v41) + 4) = *((_DWORD *)v1 + 34);
            v39[12] = v41;
          }
          v72 = 1;
        }
LABEL_95:
        if ( ++v95 >= (unsigned int)v19[3] )
          goto LABEL_96;
      }
    }
    v48 = 0;
    v49 = v19[3] == 0;
    v68 = 0;
    v87 = 0;
    if ( v19[3] == 0 )
      goto LABEL_119;
    do
    {
      v50 = *((_DWORD *)v1 + 5);
      v51 = 4 * v87;
      v78 = *(double **)(v50 + 4 * *(_DWORD *)(4 * v87 + v19[4]));
      v52 = *(int **)(v50 + 4 * *(_DWORD *)(4 * v87 + v19[2]));
      v66 = v52;
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v1 + 4) + 4 * v52[1]) + 5) & 1) != 0 && v52[2] == -1 )
      {
        v53 = v78;
        *(_BYTE *)v78 |= 0x80u;
        if ( 0.0 != *((double *)v52 + 4) )
        {
          v54 = 1.0;
LABEL_110:
          v53[4] = v54;
          goto LABEL_115;
        }
LABEL_109:
        v54 = 0.0;
        goto LABEL_110;
      }
      v55 = *v52;
      if ( (*v66 & 4) != 0 && (v55 & 8) != 0 )
      {
        v53 = v78;
        *(_BYTE *)v78 |= 0x80u;
        goto LABEL_109;
      }
      v53 = v78;
      *(_BYTE *)v78 &= ~0x80u;
LABEL_115:
      if ( *(char *)v53 >= 0 )
      {
        v56 = 4 * v48;
        *(_DWORD *)(v56 + v19[4]) = *(_DWORD *)(v51 + v19[4]);
        *(_DWORD *)(v56 + v19[2]) = *(_DWORD *)(v51 + v19[2]);
        v48 = ++v68;
      }
      ++v87;
    }
    while ( v87 < v19[3] );
    v49 = v48 == v19[3];
LABEL_119:
    if ( !v49 )
    {
      v37 = v48 != 0 ? v48 & 0xFFFFF | 0x10F00000 : 0;
      v19[1] = v48;
      v19[3] = v48;
      goto LABEL_121;
    }
LABEL_123:
    ++v80;
  }
  while ( v80 < *((_DWORD *)v1 + 3) );
  if ( v72 != 0 )
    D3DXShader::CProgram::RemapArguments(this: v1);
  return v96 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E80AF
// Name: protected: long D3DXShader::CProgram::CompactOutputs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::CompactOutputs(D3DXShader::CProgram *this)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // esi
  unsigned int v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  D3DXShader::CInstruction *v10; // ebx
  unsigned int v11; // eax
  _DWORD *v12; // ebx
  int v13; // edx
  int v14; // ecx
  _DWORD *v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  bool v18; // zf
  int IsSpecial; // [esp+4h] [ebp-2Ch]
  unsigned int v21; // [esp+4h] [ebp-2Ch]
  int v22; // [esp+8h] [ebp-28h]
  int v23; // [esp+Ch] [ebp-24h]
  _DWORD *v24; // [esp+10h] [ebp-20h]
  unsigned int v25; // [esp+10h] [ebp-20h]
  unsigned int v26; // [esp+14h] [ebp-1Ch]
  int v27; // [esp+18h] [ebp-18h]
  int v28; // [esp+18h] [ebp-18h]
  int v29; // [esp+1Ch] [ebp-14h]
  unsigned int j; // [esp+1Ch] [ebp-14h]
  unsigned int v31; // [esp+20h] [ebp-10h]
  unsigned int v32; // [esp+24h] [ebp-Ch]
  unsigned int i; // [esp+24h] [ebp-Ch]
  unsigned int v34; // [esp+28h] [ebp-8h]
  unsigned int v35; // [esp+28h] [ebp-8h]
  unsigned int v36; // [esp+28h] [ebp-8h]
  unsigned int v37; // [esp+2Ch] [ebp-4h]

  if ( (*((_BYTE *)this + 108) & 1) != 0 )
    return true;
  v22 = 0;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v2 = *((_DWORD *)this + 3);
  if ( v2 == 0 )
    return true;
  do
  {
    v3 = v2 - 1;
    v4 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * v3);
    v23 = v3;
    v5 = *v4 & 0xFFF00000;
    if ( v5 != 0x10000000 && v5 != 544210944 )
      goto LABEL_42;
    v34 = 0;
    if ( v4[3] != 0 )
    {
      v6 = (_DWORD *)v4[4];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v6) + 4))
                       + 4)
            & 0x20) == 0 )
          break;
        ++v34;
        ++v6;
      }
      while ( v34 < v4[3] );
    }
    if ( v34 < v4[3] )
      goto LABEL_42;
    v35 = 0;
    if ( v4[1] != 0 )
    {
      v7 = (_DWORD *)v4[2];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v7) + 4))
                       + 4)
            & 2) == 0 )
          break;
        ++v35;
        ++v7;
      }
      while ( v35 < v4[1] );
    }
    v8 = v4[1];
    if ( v35 < v8 )
      goto LABEL_42;
    v9 = *v4 & 0xFFFFF;
    v32 = 0;
    v31 = v9;
    v26 = v8 / v9;
    if ( v8 / v9 == 0 )
      goto LABEL_32;
    v27 = 0;
    while ( 1 )
    {
      v36 = 0;
      if ( v9 != 0 )
        break;
LABEL_30:
      ++v32;
      v27 += 4 * v9;
      if ( v32 >= v26 )
        goto LABEL_31;
    }
    v29 = v27;
    do
    {
      v10 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6)
                                         + 4
                                         * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v29 + v4[2]))
                                                     + 72));
      v37 = 0;
      IsSpecial = D3DXShader::CInstruction::IsSpecial(this: v10);
      v11 = *((_DWORD *)v10 + 3);
      if ( v11 != 0 )
      {
        v12 = *((_DWORD **)v10 + 4);
        v13 = *((_DWORD *)this + 5);
        v24 = v12;
        do
        {
          v14 = *(_DWORD *)(v13 + 4 * *v12);
          if ( *(_DWORD *)(v14 + 92) > 1u
            || *(_DWORD *)(v14 + 84) != v23
            || IsSpecial != 0 && v37 != *(_DWORD *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v4[4] + 4 * v36)) + 16) )
          {
            break;
          }
          ++v37;
          v12 = ++v24;
        }
        while ( v37 < v11 );
      }
      if ( v37 < v11 )
        break;
      ++v36;
      v29 += 4;
    }
    while ( v36 < v31 );
    if ( v36 >= v31 )
    {
      v9 = v31;
      goto LABEL_30;
    }
LABEL_31:
    if ( v32 >= v26 )
    {
LABEL_32:
      for ( i = 0; i < v4[3]; v15[1] = *((_DWORD *)this + 29) )
      {
        v15 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * i + v4[4]));
        if ( v26 != 0 )
        {
          v28 = 4 * i;
          for ( j = v26; j != 0; --j )
          {
            v16 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v28 + v4[2]));
            v25 = *v16 & 0xE000000;
            v17 = *v15 & 0xE000000;
            v21 = *v16 & 0xF1FFFFFF;
            *v16 = v21;
            if ( v17 <= v25 )
              v17 = v25;
            v18 = v16[24] == 0;
            *v16 = v17 | v21;
            v16[1] = v15[1];
            v16[2] = v15[2];
            v16[3] = v15[3];
            v16[4] = v15[4];
            if ( v18 )
            {
              v16[24] = v15[24];
              v16[25] = v15[25];
            }
            v16[26] = v15[26];
            v16[27] = v15[27];
            v16[28] = v15[28];
            v28 += 4 * v31;
          }
        }
        ++i;
      }
      v22 = 1;
      *v4 = 0;
      v4[1] = 0;
      v4[3] = 0;
    }
LABEL_42:
    v2 = v23;
  }
  while ( v23 != 0 );
  return v22 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E8367
// Name: protected: long D3DXShader::CProgram::CompactArguments(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::CompactArguments(D3DXShader::CProgram *this)
{
  int v1; // ebx
  unsigned int i; // edx
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  _DWORD *v8; // eax
  int v9; // ecx
  unsigned int j; // edi
  int v12; // eax
  D3DXShader::CArgument *v13; // ecx
  int v14; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v14 = 0;
  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * i);
    v5 = *(_DWORD *)(v4 + 4);
    if ( (v5 & 0x400) != 0 && *(_DWORD *)(v4 + 40) == -1 )
    {
      *(_DWORD *)(v4 + 4) = v5 & 0xFFFFFBFF;
      v14 = 1;
    }
  }
  v6 = 0;
  v7 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    do
    {
      v8 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v7);
      v9 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v8[1]) + 4);
      if ( (v9 & 0x100) != 0 && (v9 & 0x800) != 0 )
        v8[21] = 1;
      if ( v8[21] == -1 && v8[18] == -1 )
        v8[12] = -1;
      else
        v8[12] = v6++;
      ++v7;
    }
    while ( v7 < *((_DWORD *)this + 2) );
    v1 = 0;
  }
  if ( v6 == *((_DWORD *)this + 2) )
    return v14 == 0;
  D3DXShader::CProgram::RemapArguments(this);
  for ( j = 0; j < *((_DWORD *)this + 2); ++j )
  {
    v12 = *((_DWORD *)this + 5);
    v13 = *(D3DXShader::CArgument **)(v12 + 4 * j);
    if ( *((_DWORD *)v13 + 21) == -1 && *((_DWORD *)v13 + 18) == -1 )
      D3DXShader::CArgument::`scalar deleting destructor'(this: v13, a2: 1);
    else
      *(_DWORD *)(v12 + 4 * v1++) = v13;
  }
  memset((void *)(*((_DWORD *)this + 5) + 4 * v1), 0, 4 * (*((_DWORD *)this + 2) - v1));
  *((_DWORD *)this + 2) = v1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101E8460
// Name: private: long D3DXShader::CProgram::MarkVarying(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::MarkVarying(D3DXShader::CProgram *this)
{
  unsigned int i; // ebx
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned int n; // ebx
  int v9; // eax
  _DWORD *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int *v13; // ebx
  _DWORD *v14; // eax
  unsigned int *v15; // ebx
  unsigned int ii; // ecx
  _DWORD *v17; // eax
  unsigned int m; // ecx
  _DWORD *v19; // eax
  unsigned int k; // ecx
  _DWORD *v21; // eax
  unsigned int jj; // ecx
  _DWORD *v23; // eax
  int v25; // [esp+Ch] [ebp-14h]
  unsigned int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+14h] [ebp-Ch]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v30; // [esp+1Ch] [ebp-4h]

  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v3 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i);
    v4 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v3[1]);
    *v3 &= ~0x20u;
    v5 = *(_DWORD *)(v4 + 4);
    if ( (v5 & 0x10) != 0 && (v5 & 0x200) == 0 )
      *v3 |= 0x20u;
    if ( (*(_BYTE *)(v4 + 5) & 8) != 0 )
      *v3 |= 0x20u;
  }
  for ( j = 0; j < *((_DWORD *)this + 3); ++j )
  {
    v6 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * j);
    v7 = *v6 & 0xFFF00000;
    if ( v7 != 0 )
    {
      if ( v7 == 1343225856 || v7 == 285212672 || v7 == 287309824 || (*v6 & 0xF0000000) == 0x60000000 )
      {
        for ( k = 0; k < v6[3]; ++k )
        {
          v21 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * k));
          *v21 |= 0x20u;
        }
      }
      else if ( v7 == 284164096 || v7 == 286261248 || v7 == 289406976 )
      {
        for ( m = 0; m < v6[3]; ++m )
        {
          v19 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * m));
          *v19 |= 0x20u;
        }
      }
      else
      {
        for ( n = 0; n < v6[3]; ++n )
        {
          v9 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * n));
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v9 + 4)) + 5) & 0x10) != 0
            && D3DXShader::CProgram::IsVarying(this, a2: *(_DWORD *)(v9 + 20)) != 0 )
          {
            v10 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * n));
            *v10 |= 0x20u;
          }
        }
        v11 = *v6 & 0xF0000000;
        if ( v11 < 0x10000000 || v11 > 0x40000000 )
        {
          v28 = 0;
          if ( v6[1] != 0 )
          {
            v15 = (unsigned int *)v6[2];
            while ( D3DXShader::CProgram::IsVarying(this, a2: *v15) == 0 )
            {
              ++v28;
              ++v15;
              if ( v28 >= v6[1] )
                goto LABEL_46;
            }
            for ( ii = 0; ii < v6[3]; ++ii )
            {
              v17 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v6[4] + 4 * ii));
              *v17 |= 0x20u;
            }
          }
        }
        else
        {
          v30 = 0;
          v26 = v6[1] / (*v6 & 0xFFFFFu);
          v12 = v6[3];
          if ( v12 != 0 )
          {
            do
            {
              v27 = 0;
              if ( v26 != 0 )
              {
                v25 = 4 * v12;
                v13 = (unsigned int *)(4 * v30 + v6[2]);
                while ( D3DXShader::CProgram::IsVarying(this, a2: *v13) == 0 )
                {
                  ++v27;
                  v13 = (unsigned int *)((char *)v13 + v25);
                  if ( v27 >= v26 )
                    goto LABEL_31;
                }
                v14 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * v30 + v6[4]));
                *v14 |= 0x20u;
              }
LABEL_31:
              ++v30;
              v12 = v6[3];
            }
            while ( v30 < v12 );
          }
        }
      }
    }
LABEL_46:
    ;
  }
  for ( jj = 0; jj < *((_DWORD *)this + 2); ++jj )
  {
    v23 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * jj);
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v23[1]) + 4) & 0x20) != 0 )
      *v23 |= 0x20u;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E86C6
// Name: private: long D3DXShader::CProgram::MergePredicates(class D3DXShader::CArgument __near *,class D3DXShader::CArgument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::MergePredicates(
        D3DXShader::CProgram *this,
        struct D3DXShader::CArgument *a2,
        struct D3DXShader::CArgument *a3)
{
  struct D3DXShader::CArgument *v5; // ecx
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // eax
  struct D3DXShader::CArgument *IsLoop; // [esp+14h] [ebp+8h]

  if ( *((_DWORD *)a2 + 18) != -1 )
  {
    v5 = a3;
    v6 = *((_DWORD *)a3 + 5);
    if ( v6 == -1 )
      return D3DXShader::CProgram::MergePredicates(
               this,
               a2: (unsigned int *)a2 + 5,
               a3: (int *)a2 + 6,
               a4: *((_DWORD *)v5 + 5),
               a5: *((_DWORD *)v5 + 6));
    v7 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v6);
    v8 = v7[18];
    IsLoop = nullptr;
    if ( v8 != -1 )
      IsLoop = (struct D3DXShader::CArgument *)D3DXShader::CInstruction::IsLoop(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v8));
    if ( D3DXShader::CInstruction::IsGradient(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6)
                                                                                 + 4 * *((_DWORD *)a2 + 18))) != 0
      && IsLoop == nullptr )
    {
      do
      {
        *((_DWORD *)a2 + 5) = v7[5];
        *((_DWORD *)a2 + 6) = v7[6];
        if ( v7[5] == -1 )
          break;
        v7 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v7[5]);
        v9 = v7[18];
        if ( v9 == -1 )
          break;
      }
      while ( D3DXShader::CInstruction::IsLoop(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v9)) == 0 );
      return 0;
    }
  }
  v5 = a3;
  return D3DXShader::CProgram::MergePredicates(
           this,
           a2: (unsigned int *)a2 + 5,
           a3: (int *)a2 + 6,
           a4: *((_DWORD *)v5 + 5),
           a5: *((_DWORD *)v5 + 6));
}

//------------------------------------------------------------------------------
// Address: 0x101E8771
// Name: private: long D3DXShader::CProgram::MergeArguments(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::MergeArguments(D3DXShader::CProgram *this, unsigned int a2, unsigned int a3)
{
  int v3; // eax
  unsigned int *v4; // esi
  struct D3DXShader::CArgument *v5; // edi
  int result; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  bool v10; // zf

  v3 = *((_DWORD *)this + 5);
  v4 = *(unsigned int **)(v3 + 4 * a2);
  v5 = *(struct D3DXShader::CArgument **)(v3 + 4 * a3);
  *((_DWORD *)v5 + 12) = a2;
  result = D3DXShader::CProgram::MergePredicates(this, a2: (struct D3DXShader::CArgument *)v4, a3: v5);
  if ( result >= 0 )
  {
    v7 = *v4 & 0xE000000;
    v8 = *(_DWORD *)v5 & 0xE000000;
    v9 = *v4 & 0xF1FFFFFF;
    *v4 = v9;
    if ( v7 > v8 )
      v8 = v7;
    v10 = v4[24] == 0;
    *v4 = v8 | v9;
    if ( v10 )
    {
      v4[24] = *((_DWORD *)v5 + 24);
      v4[25] = *((_DWORD *)v5 + 25);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E87D2
// Name: private: long D3DXShader::CProgram::SimplifyUnary(class D3DXShader::CInstruction __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SimplifyUnary(
        D3DXShader::CProgram *this,
        struct D3DXShader::CNode **a2,
        unsigned int a3,
        unsigned int a4)
{
  int v5; // eax
  _DWORD *v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  void *v10; // edx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  double v15; // st7
  _DWORD *v16; // eax
  _DWORD *i; // ecx
  _DWORD *v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // edx
  _DWORD *v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edi
  _DWORD *v25; // ebx
  _DWORD *v26; // ecx
  _DWORD *v27; // eax
  _DWORD *v28; // ecx
  _DWORD *v29; // eax
  unsigned int v30; // ecx
  int v31; // edi
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  _DWORD *j; // ecx
  int v35; // eax
  int v37; // [esp+14h] [ebp-24h]
  int v38; // [esp+18h] [ebp-20h]
  int v39; // [esp+18h] [ebp-20h]
  int v40; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v41; // [esp+20h] [ebp-18h]
  int v42; // [esp+24h] [ebp-14h]
  int v43; // [esp+28h] [ebp-10h]
  _DWORD *v44; // [esp+2Ch] [ebp-Ch]
  void *v45; // [esp+30h] [ebp-8h]
  int v46; // [esp+34h] [ebp-4h]
  _DWORD *v47; // [esp+34h] [ebp-4h]
  struct D3DXShader::CInstruction *v48; // [esp+40h] [ebp+8h]
  struct D3DXShader::CInstruction *v49; // [esp+40h] [ebp+8h]
  struct D3DXShader::CInstruction *v50; // [esp+40h] [ebp+8h]
  struct D3DXShader::CInstruction *v51; // [esp+40h] [ebp+8h]
  struct D3DXShader::CInstruction *v52; // [esp+40h] [ebp+8h]
  struct D3DXShader::CInstruction *v53; // [esp+40h] [ebp+8h]
  unsigned int v54; // [esp+44h] [ebp+Ch]
  unsigned int v55; // [esp+44h] [ebp+Ch]
  _DWORD *v56; // [esp+44h] [ebp+Ch]
  unsigned int v57; // [esp+44h] [ebp+Ch]
  unsigned int v58; // [esp+48h] [ebp+10h]
  _DWORD *v59; // [esp+48h] [ebp+10h]

  v5 = *((_DWORD *)this + 5);
  v6 = *(_DWORD **)(v5 + 4 * a3);
  v7 = *(_DWORD *)(v5 + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * a4) + 48));
  v58 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * a4) + 48);
  v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v6[1]) + 4);
  v41 = v6;
  v37 = v7;
  if ( (v8 & 1) == 0 || (v8 & 0x1000) != 0 )
    return 0;
  v54 = *(_DWORD *)v7 & 0x1F;
  v9 = *v6;
  v46 = *v6 & 0x40;
  v10 = (void *)((unsigned int)*a2 & 0xFFF00000);
  v45 = v10;
  if ( v10 == (void *)0x10000000 )
  {
    v11 = v58;
    *v6 = v54 | v9;
LABEL_140:
    v6[12] = v11;
    return 0;
  }
  v12 = v9 | *(_DWORD *)v7 & 0x40;
  *v6 = v12;
  if ( (v12 & 0xE000000) == 0
    && (v10 == &loc_10100000
     || v10 == &unk_10300000
     || v10 == (void *)272629760
     || v10 == (void *)282066944
     || v10 == (void *)283115520) )
  {
    *v6 = v12 | *(_DWORD *)v7 & 0xE000000;
  }
  v13 = 4;
  if ( v10 == &loc_10100000 )
  {
    *v6 |= v54 & 0xFFFFFFF3 | (2 * (v54 & 4)) | (v54 >> 1) & 4;
    goto LABEL_23;
  }
  if ( v10 == &unk_10300000 )
  {
    if ( (v54 & 4) == 0 || (v54 & 8) == 0 )
      v13 = v54 & 0xC;
  }
  else if ( v10 != (void *)272629760 && v10 != (void *)273678336 && v10 != (void *)275775488 )
  {
LABEL_23:
    v14 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v7 + 4)) + 4);
    if ( (v14 & 0x100) == 0 || *(_DWORD *)(v7 + 8) != -1 )
    {
      if ( ((v54 & 1) == 0 || v10 != (void *)272629760) && ((v54 & 2) == 0 || v10 != (void *)272629760) )
      {
        if ( (v54 & 8) != 0 )
        {
          if ( v10 == (void *)274726912 )
          {
            if ( v46 == 0 && (v54 & 4) == 0 )
              D3DXShader::CProgram::Error(
                (D3DXShader::CTErrors **)this,
                a2: a2[15],
                a3: 0xFA2u,
                format: "indefinite logarithm");
            return 0;
          }
          if ( v10 == (void *)275775488 )
          {
            if ( v46 == 0 )
            {
              D3DXShader::CProgram::Error(
                (D3DXShader::CTErrors **)this,
                a2: a2[15],
                a3: 0xFA3u,
                format: "imaginary square root");
              v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
              goto LABEL_140;
            }
            return 0;
          }
        }
        if ( (v14 & 0x200) == 0 || v10 != (void *)282066944 && v10 != (void *)283115520 )
        {
          if ( v46 != 0 || (v14 & 2) == 0 )
            return 0;
          if ( v10 == &loc_10100000
            && (_UNKNOWN *)(*(v16 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72))) & 0xFFF00000) == &loc_10100000
            || v10 == &unk_10300000
            && (_UNKNOWN *)(*(v16 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72))) & 0xFFF00000) == &unk_10300000
            || v10 == (void *)273678336
            && (*(v16 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72))) & 0xFFF00000) == 0x10600000
            || v10 == (void *)274726912
            && (*(v16 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72))) & 0xFFF00000) == 0x10500000 )
          {
            v48 = nullptr;
            if ( v16[3] != 0 )
            {
              for ( i = (_DWORD *)v16[4]; *i != v58; ++i )
              {
                v48 = (struct D3DXShader::CInstruction *)((char *)v48 + 1);
                if ( (unsigned int)v48 >= v16[3] )
                  break;
              }
            }
            if ( (unsigned int)v48 < v16[3] )
            {
              v11 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v16[2] + 4 * (_DWORD)v48)) + 48);
              goto LABEL_140;
            }
          }
          if ( v10 == &unk_10300000 )
          {
            v18 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72));
            if ( (*v18 & 0xFFF00000) == 0x20500000 )
            {
              v19 = v18[3];
              v20 = 0;
              if ( v19 != 0 )
              {
                v21 = (_DWORD *)v18[4];
                do
                {
                  if ( *v21 == v58 )
                    break;
                  ++v20;
                  ++v21;
                }
                while ( v20 < v19 );
              }
              v22 = v18[3];
              v23 = v18[2];
              v55 = 0;
              v43 = *((_DWORD *)this + 5);
              v38 = 4 * v22;
              v24 = -1 * v22;
              v25 = (_DWORD *)(v23 + 4 * v20);
              v26 = (_DWORD *)(v23 + 4 * (v20 + v22));
              v47 = v25;
              v44 = v26;
              while ( 1 )
              {
                v40 = *v26;
                v42 = *v25;
                v49 = *(struct D3DXShader::CInstruction **)(v43 + 4 * *v25);
                if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)v49 + 1)) + 4) & 2) != 0 )
                {
                  v27 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v49 + 18));
                  if ( (*v27 & 0xFFF00000) == 0x10700000 )
                  {
                    v50 = nullptr;
                    if ( v27[3] != 0 )
                    {
                      v28 = (_DWORD *)v27[4];
                      do
                      {
                        if ( *v28 == v42 )
                          break;
                        v50 = (struct D3DXShader::CInstruction *)((char *)v50 + 1);
                        ++v28;
                      }
                      while ( (unsigned int)v50 < v27[3] );
                    }
                    if ( *(_DWORD *)(v27[2] + 4 * (_DWORD)v50) == v40 )
                    {
                      v41[12] = *(_DWORD *)(*(_DWORD *)(v43 + 4 * v42) + 48);
                      return 0;
                    }
                    v25 = v47;
                  }
                }
                v25 = (_DWORD *)((char *)v25 + v38);
                ++v55;
                v26 = &v44[v24];
                v47 = v25;
                v44 = (_DWORD *)((char *)v44 + v24 * 4);
                if ( v55 >= 2 )
                {
                  v6 = v41;
                  v7 = v37;
                  break;
                }
              }
            }
          }
          if ( v45 != (void *)273678336 )
            return 0;
          v29 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7 + 72));
          if ( (*v29 & 0xFFF00000) != 0x20500000 )
            return 0;
          v30 = v29[3];
          v51 = nullptr;
          if ( v30 != 0 )
          {
            v56 = (_DWORD *)v29[4];
            do
            {
              if ( *v56 == v58 )
                break;
              v51 = (struct D3DXShader::CInstruction *)((char *)v51 + 1);
              ++v56;
            }
            while ( (unsigned int)v51 < v30 );
          }
          v57 = 0;
          v31 = *((_DWORD *)this + 5);
          v39 = v30;
          v32 = (_DWORD *)(v29[2] + 4 * (_DWORD)v51);
          v59 = v32;
          while ( 1 )
          {
            v52 = *(struct D3DXShader::CInstruction **)(v31 + 4 * *v32);
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)v52 + 1)) + 4) & 2) != 0 )
            {
              v33 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v52 + 18));
              if ( (*v33 & 0xFFF00000) == 0x10600000 )
              {
                v53 = nullptr;
                if ( v33[3] != 0 )
                {
                  for ( j = (_DWORD *)v33[4]; *j != *v59; ++j )
                  {
                    v53 = (struct D3DXShader::CInstruction *)((char *)v53 + 1);
                    if ( (unsigned int)v53 >= v33[3] )
                      break;
                  }
                }
                v31 = *((_DWORD *)this + 5);
                v35 = **(_DWORD **)(v31 + 4 * *(_DWORD *)(v33[2] + 4 * (_DWORD)v53));
                if ( (v35 & 4) != 0 && (v35 & 8) != 0 )
                  break;
              }
            }
            v32 = &v59[v39];
            ++v57;
            v59 = (_DWORD *)((char *)v59 + v39 * 4);
            if ( v57 >= 2 )
              return 0;
          }
        }
      }
      v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: 0.0);
      goto LABEL_140;
    }
    if ( (unsigned int)v10 > 0x10800000 )
    {
      if ( v10 == (void *)277872640 )
      {
        v15 = cos(*(double *)(v7 + 32));
        goto LABEL_70;
      }
      if ( v10 == (void *)278921216 )
      {
        if ( v46 != 0 || *(double *)(v7 + 32) >= -1.0 && *(double *)(v7 + 32) <= 1.0 )
        {
          v15 = asin(*(double *)(v7 + 32));
          goto LABEL_70;
        }
        D3DXShader::CProgram::Error((D3DXShader::CTErrors **)this, a2: a2[15], a3: 0xFA5u, format: "indefinite arcsine");
        goto LABEL_67;
      }
      if ( v10 == (void *)279969792 )
      {
        if ( v46 == 0 && (*(double *)(v7 + 32) < -1.0 || *(double *)(v7 + 32) > 1.0) )
        {
          D3DXShader::CProgram::Error(
            (D3DXShader::CTErrors **)this,
            a2: a2[15],
            a3: 0xFA6u,
            format: "indefinite arccosine");
          goto LABEL_67;
        }
        v15 = acos(*(double *)(v7 + 32));
        goto LABEL_70;
      }
      if ( v10 == (void *)281018368 )
      {
        v15 = atan2(*(double *)(v7 + 32), 1.0);
        goto LABEL_70;
      }
      if ( v10 == (void *)282066944 || v10 == (void *)283115520 )
        goto LABEL_67;
    }
    else
    {
      if ( v10 == (void *)276824064 )
      {
        v15 = sin(*(double *)(v7 + 32));
        goto LABEL_70;
      }
      if ( v10 == &loc_10100000 )
      {
        v15 = -*(double *)(v7 + 32);
        goto LABEL_70;
      }
      if ( v10 == &unk_10300000 )
      {
        if ( v46 == 0 && 0.0 == *(double *)(v7 + 32) )
          goto LABEL_67;
        v15 = 1.0 / *(double *)(v7 + 32);
        goto LABEL_70;
      }
      if ( v10 == (void *)272629760 )
      {
        if ( _finite(x: *(double *)(v7 + 32)) == 0 )
          goto LABEL_67;
        v15 = *(double *)(v7 + 32) - floor(X: *(double *)(v7 + 32));
        goto LABEL_70;
      }
      if ( v10 == (void *)273678336 )
      {
        v15 = pow(2.0, *(double *)(v7 + 32));
        goto LABEL_70;
      }
      if ( v10 == (void *)274726912 )
      {
        if ( v46 != 0 || *(double *)(v7 + 32) != 0.0 )
        {
          if ( *(double *)(v7 + 32) < 0.0 )
          {
            D3DXShader::CProgram::Error(
              (D3DXShader::CTErrors **)this,
              a2: a2[15],
              a3: 0xFA2u,
              format: "indefinite logarithm");
            goto LABEL_67;
          }
          v15 = __FYL2X__(*(double *)(v7 + 32), 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
LABEL_70:
          v11 = D3DXShader::CBaseProgram::AddArgument(this, a2: *((_DWORD *)this + 30), a3: 0, a4: 0, a5: v15);
          goto LABEL_140;
        }
      }
      else if ( v10 == (void *)275775488 )
      {
        if ( v46 == 0 && *(double *)(v7 + 32) < 0.0 )
        {
          D3DXShader::CProgram::Error(
            (D3DXShader::CTErrors **)this,
            a2: a2[15],
            a3: 0xFA3u,
            format: "imaginary square root");
LABEL_67:
          v15 = 0.0;
          goto LABEL_70;
        }
        v15 = 1.0 / sqrt(*(double *)(v7 + 32));
        goto LABEL_70;
      }
    }
    return 0;
  }
  *v6 |= v13;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x101E8F03
// Name: private: long D3DXShader::CProgram::SimplifyBinary(class D3DXShader::CInstruction __near *,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SimplifyBinary(
        D3DXShader::CProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  D3DXShader::CProgram *v5; // ebx
  int v6; // eax
  int *v7; // esi
  _DWORD *v8; // ecx
  _DWORD *v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int *v14; // edi
  int v15; // eax
  unsigned int v16; // esi
  int v17; // edx
  int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  char v22; // dl
  int v23; // eax
  _DWORD *v24; // eax
  int v25; // ecx
  _DWORD *v26; // eax
  unsigned int v27; // ecx
  _DWORD *v28; // edx
  bool v29; // zf
  _DWORD *v30; // eax
  unsigned int v31; // ecx
  _DWORD *v32; // edx
  double v33; // st7
  unsigned int v34; // eax
  int v35; // esi
  long double v36; // st7
  _DWORD *v37; // edx
  _DWORD *v38; // eax
  unsigned int v39; // edx
  char v40; // cl
  int v41; // eax
  _DWORD *v42; // eax
  unsigned int v43; // edi
  unsigned int v44; // esi
  _DWORD *v45; // ecx
  int v46; // ecx
  int v47; // eax
  int v48; // ecx
  unsigned int v49; // eax
  bool v50; // zf
  double v51; // st6
  bool v52; // zf
  unsigned int v53; // ecx
  _DWORD *v54; // eax
  _DWORD *v55; // edx
  _DWORD *v56; // eax
  unsigned int v57; // ecx
  _DWORD *v58; // edx
  double v59; // st7
  unsigned int v60; // eax
  unsigned int v61; // ecx
  int v62; // ecx
  int v63; // eax
  _DWORD *v64; // eax
  _DWORD *j; // edx
  int v66; // eax
  _DWORD *v67; // eax
  unsigned int v68; // esi
  unsigned int v69; // ecx
  _DWORD *v70; // edx
  int v71; // eax
  int v72; // edx
  int v73; // ecx
  int v74; // eax
  unsigned int v75; // edx
  unsigned int v76; // eax
  int v77; // eax
  _DWORD *v78; // eax
  unsigned int v79; // ecx
  _DWORD *v80; // edx
  unsigned int v81; // edi
  unsigned int v82; // ecx
  _DWORD *v83; // esi
  void *v84; // eax
  char *v85; // eax
  unsigned int v86; // eax
  _DWORD *k; // edx
  int v88; // eax
  double v89; // st7
  unsigned int v91; // edi
  int v92; // eax
  _DWORD *v93; // eax
  unsigned int v94; // edx
  unsigned int v95; // ecx
  _DWORD *v96; // esi
  int v97; // edx
  int v98; // eax
  int v99; // esi
  int v100; // eax
  int v101; // ecx
  _DWORD *v102; // edx
  _DWORD *v103; // ecx
  unsigned int v104; // esi
  _DWORD *v105; // eax
  unsigned int v106; // edi
  _DWORD *v107; // eax
  unsigned int v108; // esi
  _DWORD *v109; // eax
  int v110; // eax
  int v111; // ecx
  unsigned int v112; // edx
  int v113; // edx
  _DWORD *v114; // ecx
  void *v115; // eax
  unsigned int v116; // eax
  _DWORD *v117; // esi
  int v118; // esi
  _DWORD *v119; // eax
  _DWORD *v120; // eax
  void *v121; // edx
  int v122; // edx
  int v123; // edi
  int v124; // eax
  int v125; // ecx
  _DWORD *v126; // esi
  unsigned int v127; // ecx
  unsigned int v128; // ebx
  _DWORD *v129; // edx
  unsigned int v130; // ebx
  D3DXShader::CProgram *v131; // esi
  int v132; // eax
  double v133; // st7
  double v134; // [esp+0h] [ebp-60h]
  long double v135; // [esp+14h] [ebp-4Ch]
  unsigned int v136; // [esp+18h] [ebp-48h]
  int v137; // [esp+18h] [ebp-48h]
  unsigned int v138; // [esp+1Ch] [ebp-44h]
  unsigned int v139; // [esp+20h] [ebp-40h]
  int v140; // [esp+24h] [ebp-3Ch] BYREF
  int v141; // [esp+28h] [ebp-38h]
  unsigned int v142; // [esp+2Ch] [ebp-34h]
  int v143; // [esp+30h] [ebp-30h] BYREF
  unsigned int v144; // [esp+34h] [ebp-2Ch]
  unsigned int v145; // [esp+38h] [ebp-28h]
  unsigned int v146; // [esp+3Ch] [ebp-24h]
  int v147; // [esp+40h] [ebp-20h]
  _DWORD *v148; // [esp+44h] [ebp-1Ch]
  D3DXShader::CProgram *v149; // [esp+48h] [ebp-18h]
  _DWORD *v150; // [esp+4Ch] [ebp-14h]
  int *v151; // [esp+50h] [ebp-10h]
  unsigned int v152; // [esp+54h] [ebp-Ch]
  int v153; // [esp+58h] [ebp-8h]
  unsigned int i; // [esp+5Ch] [ebp-4h]
  int v155; // [esp+68h] [ebp+8h]
  unsigned int v156; // [esp+6Ch] [ebp+Ch]
  unsigned int v157; // [esp+70h] [ebp+10h]
  unsigned int v158; // [esp+74h] [ebp+14h]
  unsigned int v159; // [esp+74h] [ebp+14h]

  v5 = this;
  v149 = this;
  v145 = *(_DWORD *)a2;
  v6 = *((_DWORD *)this + 5);
  v7 = *(int **)(v6 + 4 * a3);
  v157 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a4) + 48);
  v8 = *(_DWORD **)(v6 + 4 * v157);
  v158 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a5) + 48);
  v9 = *(_DWORD **)(v6 + 4 * v158);
  v10 = v7[1];
  v151 = v7;
  v11 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v149 + 4) + 4 * v10) + 4);
  v148 = v8;
  v150 = v9;
  if ( (v11 & 1) == 0 || (v11 & 0x1000) != 0 )
    return 0;
  v12 = *v8;
  v13 = *v9;
  v14 = v151;
  i = v12 & 0x1F;
  v15 = *v151;
  v153 = v13 & 0x1F;
  v146 = v15 & 0x40;
  if ( (v15 & 0xE000000) == 0 )
  {
    v16 = v145 & 0xFFF00000;
    if ( (v145 & 0xFFF00000) == 0x20000000
      || v16 == 537919488
      || v16 == 541065216
      || v16 == 544210944
      || v16 == 545259520
      || v16 == 546308096 )
    {
      v17 = v12 | v13;
      v18 = 0x8000000;
      if ( (v17 & 0x8000000) != 0
        || (v18 = 0x4000000, (v17 & 0x4000000) != 0)
        || (v18 = 0x2000000, (v17 & 0x2000000) != 0) )
      {
        *v151 = v18 | v15;
      }
    }
  }
  if ( ((*(_BYTE *)v148 | *(_BYTE *)v150) & 0x40) != 0 )
  {
    v19 = v145 & 0xFFF00000;
    if ( (v145 & 0xFFF00000) <= 0x20600000 )
    {
      if ( (v145 & 0xFFF00000) != 0x20600000
        && v19 != 0x20000000
        && v19 != 537919488
        && v19 != 541065216
        && v19 != 542113792 )
      {
        goto LABEL_26;
      }
LABEL_25:
      *v14 |= 0x40u;
      goto LABEL_26;
    }
    if ( v19 == 544210944 || v19 == 545259520 || v19 == 546308096 )
      goto LABEL_25;
  }
LABEL_26:
  v20 = v145 & 0xFFF00000;
  v152 = v145 & 0xFFF00000;
  if ( (v145 & 0xFFF00000) <= 0x20400000 )
  {
    if ( (v145 & 0xFFF00000) == 0x20400000 )
    {
      v21 = (unsigned __int8)i & (unsigned __int8)v153 & 0xE;
    }
    else if ( v20 == 0x20000000 )
    {
      v21 = i & 8 | v153 & (i | 8);
    }
    else
    {
      if ( v20 != 537919488 )
      {
        if ( v20 == 538968064 || v20 == 540016640 )
          *v14 |= 0x17u;
        goto LABEL_73;
      }
      v21 = i & 4 | v153 & (i | 4);
    }
LABEL_41:
    *v14 |= v21;
    goto LABEL_73;
  }
  if ( v20 != 542113792 )
  {
    if ( v20 != 544210944 && v20 != 545259520 && v20 != 546308096 )
      goto LABEL_73;
    v21 = i & v153;
    goto LABEL_41;
  }
  v22 = i;
  *v14 |= (unsigned __int8)i & (unsigned __int8)v153 & 3;
  v23 = *v14;
  v142 = v22 & 4;
  if ( (v22 & 4) != 0 && (v153 & 4) != 0 || (i & 8) != 0 && (v153 & 8) != 0 )
    *v14 = v23 | 4;
  if ( v142 != 0 && (v153 & 8) != 0 || (i & 8) != 0 && (v153 & 4) != 0 )
    *v14 |= 8u;
  v24 = v150;
  if ( v148 == v150 )
  {
    *v14 |= 4u;
    goto LABEL_73;
  }
  v25 = *((_DWORD *)v5 + 4);
  if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * v148[1]) + 4) & 2) == 0 )
    goto LABEL_63;
  v26 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * v148[18]);
  if ( (_UNKNOWN *)(*v26 & 0xFFF00000) != &loc_10100000 )
  {
    v24 = v150;
LABEL_63:
    if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * v24[1]) + 4) & 2) == 0 )
      goto LABEL_73;
    v30 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * v24[18]);
    if ( (_UNKNOWN *)(*v30 & 0xFFF00000) != &loc_10100000 )
      goto LABEL_73;
    v31 = 0;
    if ( v30[3] == 0 )
      goto LABEL_73;
    v32 = (_DWORD *)v30[4];
    do
    {
      if ( *v32 == v158 )
        break;
      ++v31;
      ++v32;
    }
    while ( v31 < v30[3] );
    if ( v31 >= v30[3] )
      goto LABEL_73;
    v29 = *(_DWORD *)(v30[2] + 4 * v31) == v157;
    goto LABEL_71;
  }
  v27 = 0;
  if ( v26[3] != 0 )
  {
    v28 = (_DWORD *)v26[4];
    do
    {
      if ( *v28 == v157 )
        break;
      ++v27;
      ++v28;
    }
    while ( v27 < v26[3] );
    if ( v27 >= v26[3] )
      goto LABEL_73;
    v29 = *(_DWORD *)(v26[2] + 4 * v27) == v158;
LABEL_71:
    if ( v29 )
      *v14 |= 8u;
  }
LABEL_73:
  if ( v146 != 0 )
    goto LABEL_89;
  if ( (i & 4) != 0 && (v153 & 8) != 0 )
  {
    switch ( v152 )
    {
      case 0x20000000u:
        goto LABEL_84;
      case 0x20100000u:
        goto LABEL_83;
      case 0x20200000u:
        v33 = 0.0;
        goto LABEL_81;
      case 0x20300000u:
        v33 = 1.0;
LABEL_81:
        v34 = D3DXShader::CBaseProgram::AddArgument(this: v5, a2: *((_DWORD *)v5 + 30), a3: 0, a4: 0, a5: v33);
        goto LABEL_267;
      default:
        break;
    }
  }
  if ( (i & 8) != 0 && (v153 & 4) != 0 )
  {
    if ( v152 == 0x20000000 )
      goto LABEL_83;
    if ( v152 == 537919488 )
    {
LABEL_84:
      v34 = v158;
      goto LABEL_267;
    }
  }
LABEL_89:
  v35 = *((_DWORD *)v5 + 4);
  v142 = *(_DWORD *)(*(_DWORD *)(v35 + 4 * v148[1]) + 4);
  v147 = v35;
  if ( (v142 & 0x100) != 0
    && v148[2] == -1
    && (*(_DWORD *)(*(_DWORD *)(v35 + 4 * v150[1]) + 4) & 0x100) != 0
    && v150[2] == -1 )
  {
    v36 = *((double *)v148 + 4);
    v135 = *((double *)v150 + 4);
    switch ( v152 )
    {
      case 0x20000000u:
        if ( v36 >= v135 )
LABEL_110:
          v36 = v135;
        break;
      case 0x20100000u:
        if ( v36 < v135 )
          goto LABEL_110;
        break;
      case 0x20200000u:
        if ( v36 < v135 )
          goto LABEL_156;
        goto LABEL_132;
      case 0x20300000u:
        if ( v36 < v135 )
          goto LABEL_132;
LABEL_156:
        v36 = 1.0;
        break;
      default:
        switch ( v152 )
        {
          case 0x20400000u:
            v36 = v36 + v135;
            break;
          case 0x20500000u:
            v36 = v36 * v135;
            break;
          case 0x20600000u:
            v36 = atan2(v36, v135);
            break;
          default:
            return 0;
        }
        break;
    }
LABEL_111:
    v134 = v36;
LABEL_221:
    v34 = D3DXShader::CBaseProgram::AddArgument(this: v5, a2: *((_DWORD *)v5 + 30), a3: 0, a4: 0, a5: v134);
    goto LABEL_267;
  }
  if ( v146 != 0 )
  {
    v38 = v150;
  }
  else
  {
    if ( (v142 & 0x100) != 0 )
    {
      v37 = v148;
      if ( v148[2] == -1 )
      {
        v38 = v150;
        goto LABEL_118;
      }
    }
    v38 = v150;
    if ( (*(_DWORD *)(*(_DWORD *)(v35 + 4 * v150[1]) + 4) & 0x100) != 0 && v150[2] == -1 )
    {
      v37 = v148;
LABEL_118:
      if ( (v142 & 0x100) != 0 && v37[2] == -1 )
      {
        v36 = *((double *)v37 + 4);
        v39 = v158;
        v40 = v153;
      }
      else
      {
        v36 = *((double *)v38 + 4);
        v39 = v157;
        v40 = i;
      }
      if ( v152 == 0x20000000 )
      {
        if ( v36 < 1.0 || (v40 & 1) == 0 )
        {
          if ( v36 > 0.0 || (v40 & 4) == 0 )
            return 0;
          goto LABEL_111;
        }
        goto LABEL_189;
      }
      if ( v152 == 537919488 )
      {
        if ( v36 >= 1.0 && (v40 & 1) != 0 )
          goto LABEL_111;
        if ( v36 > 0.0 )
          return 0;
        v52 = (v40 & 4) == 0;
      }
      else
      {
        if ( v152 == 538968064 )
        {
          if ( v39 != v158 )
          {
            if ( v36 <= 0.0 && (v40 & 4) != 0 )
              goto LABEL_132;
            if ( v36 > 0.0 && (v40 & 8) != 0 )
              goto LABEL_156;
            v50 = v36 > 1.0;
            goto LABEL_180;
          }
          if ( v36 < 0.0 && (v40 & 4) != 0 )
            goto LABEL_156;
          if ( v36 >= 0.0 && (v40 & 8) != 0 || v36 >= 1.0 && (v40 & 1) != 0 )
            goto LABEL_132;
          v51 = 0.0;
        }
        else
        {
          if ( v152 != 540016640 )
          {
            if ( v152 == 541065216 )
            {
              if ( v36 != 0.0 )
                return 0;
            }
            else
            {
              if ( v152 != 542113792 )
              {
                if ( v152 != 543162368 || v36 != 0.0 || v39 != v157 )
                  return 0;
                goto LABEL_132;
              }
              if ( v36 == 0.0 )
              {
LABEL_132:
                v36 = 0.0;
                goto LABEL_111;
              }
              if ( v36 != 1.0 )
              {
                if ( v36 != 0.5 )
                  return 0;
                v41 = *(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v39);
                if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * *(_DWORD *)(v41 + 4)) + 4) & 2) == 0 )
                  return 0;
                v42 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v41 + 72));
                if ( (*v42 & 0xFFF00000) != 0x20400000 )
                  return 0;
                v43 = v42[3];
                v44 = 0;
                if ( v43 != 0 )
                {
                  v45 = (_DWORD *)v42[4];
                  do
                  {
                    if ( *v45 == v39 )
                      break;
                    ++v44;
                    ++v45;
                  }
                  while ( v44 < v43 );
                }
                if ( v44 >= v43 )
                  return 0;
                v46 = v42[2];
                if ( *(_DWORD *)(v46 + 4 * v44) != *(_DWORD *)(v46 + 4 * (v44 + v43)) )
                  return 0;
                v47 = *(_DWORD *)(4 * v44 + v46);
                v48 = *((_DWORD *)v5 + 5);
                goto LABEL_145;
              }
            }
LABEL_189:
            v14[12] = v39;
            return 0;
          }
          if ( v39 == v158 )
          {
            if ( v36 < 0.0 && (v40 & 4) != 0 )
              goto LABEL_132;
            if ( v36 >= 0.0 && (v40 & 8) != 0 )
              goto LABEL_156;
            v50 = v36 >= 1.0;
LABEL_180:
            if ( !v50 || (v40 & 1) == 0 )
              return 0;
            goto LABEL_156;
          }
          if ( v36 <= 0.0 && (v40 & 4) != 0 )
            goto LABEL_156;
          if ( v36 > 0.0 && (v40 & 8) != 0 || v36 > 1.0 && (v40 & 1) != 0 )
            goto LABEL_132;
          v51 = 1.0;
        }
        if ( v36 != v51 )
          return 0;
        v52 = (v40 & 1) == 0;
      }
      if ( v52 )
        return 0;
      goto LABEL_189;
    }
  }
  if ( v148 == v38 )
  {
    switch ( v152 )
    {
      case 0x20000000u:
      case 0x20100000u:
        goto LABEL_83;
      case 0x20200000u:
        if ( v146 != 0 )
          return 0;
        goto LABEL_219;
      case 0x20300000u:
        if ( v146 != 0 )
          return 0;
        v59 = 1.0;
        goto LABEL_220;
      default:
        break;
    }
    if ( v152 == 542113792 && (i & 1) != 0 )
    {
LABEL_83:
      v34 = v157;
      goto LABEL_267;
    }
  }
  v53 = 0;
  if ( v146 != 0 )
    return 0;
  if ( v152 == 541065216 )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * v38[1]) + 4) & 2) != 0 )
    {
      v54 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * v38[18]);
      if ( (_UNKNOWN *)(*v54 & 0xFFF00000) == &loc_10100000 && v54[3] != 0 )
      {
        v55 = (_DWORD *)v54[4];
        do
        {
          if ( *v55 == v158 )
            break;
          ++v53;
          ++v55;
        }
        while ( v53 < v54[3] );
        if ( v53 < v54[3] && v157 == *(_DWORD *)(v54[2] + 4 * v53) )
          goto LABEL_219;
      }
    }
    if ( (v142 & 2) != 0 )
    {
      v56 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * v148[18]);
      if ( (_UNKNOWN *)(*v56 & 0xFFF00000) == &loc_10100000 )
      {
        v57 = 0;
        if ( v56[3] != 0 )
        {
          v58 = (_DWORD *)v56[4];
          do
          {
            if ( *v58 == v157 )
              break;
            ++v57;
            ++v58;
          }
          while ( v57 < v56[3] );
          if ( v57 < v56[3] && v158 == *(_DWORD *)(v56[2] + 4 * v57) )
          {
LABEL_219:
            v59 = 0.0;
LABEL_220:
            v134 = v59;
            goto LABEL_221;
          }
        }
      }
    }
    for ( i = 0; i < 8; ++i )
    {
      if ( (i & 4) != 0 )
      {
        v60 = v157;
        v61 = v158;
      }
      else
      {
        v60 = v158;
        v61 = v157;
      }
      v144 = v61;
      v145 = v60;
      v139 = i & 2;
      if ( (i & 2) != 0 )
      {
        v62 = *((_DWORD *)v5 + 5);
        v63 = *(_DWORD *)(v62 + 4 * v60);
        if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v63 + 4)) + 4) & 2) == 0 )
          continue;
        v64 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v63 + 72));
        if ( (_UNKNOWN *)(*v64 & 0xFFF00000) != &loc_10100000 )
          continue;
        v146 = 0;
        if ( v64[3] != 0 )
        {
          for ( j = (_DWORD *)v64[4]; v145 != *j; j = (_DWORD *)v141 )
          {
            ++v146;
            v141 = (int)(j + 1);
            if ( v146 >= v64[3] )
              goto LABEL_240;
          }
          v145 = *(_DWORD *)(*(_DWORD *)(v62 + 4 * *(_DWORD *)(v64[2] + 4 * v146)) + 48);
        }
      }
LABEL_240:
      v66 = *(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v144);
      if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v66 + 4)) + 4) & 2) != 0 )
      {
        v67 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v66 + 72));
        if ( (*v67 & 0xFFF00000) == 0x20400000 )
        {
          v68 = v67[3];
          v69 = 0;
          if ( v68 != 0 )
          {
            v70 = (_DWORD *)v67[4];
            while ( v144 != *v70 )
            {
              ++v69;
              ++v70;
              if ( v69 >= v68 )
                goto LABEL_251;
            }
            v71 = v67[2];
            if ( (i & 1) != 0 )
            {
              v72 = *(_DWORD *)(v71 + 4 * v69);
              v69 += v68;
            }
            else
            {
              v72 = *(_DWORD *)(v71 + 4 * (v69 + v68));
            }
            v73 = *(_DWORD *)(v71 + 4 * v69);
            v74 = *((_DWORD *)v5 + 5);
            v75 = *(_DWORD *)(*(_DWORD *)(v74 + 4 * v72) + 48);
            v76 = *(_DWORD *)(*(_DWORD *)(v74 + 4 * v73) + 48);
            v142 = v75;
            v136 = v76;
LABEL_251:
            v14 = v151;
          }
          if ( v139 == 0 )
          {
            v77 = *(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v142);
            if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v77 + 4)) + 4) & 2) == 0 )
              continue;
            v78 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v77 + 72));
            if ( (_UNKNOWN *)(*v78 & 0xFFF00000) != &loc_10100000 )
              continue;
            v79 = 0;
            if ( v78[3] != 0 )
            {
              v80 = (_DWORD *)v78[4];
              while ( v142 != *v80 )
              {
                ++v79;
                ++v80;
                if ( v79 >= v78[3] )
                  goto LABEL_261;
              }
              v142 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * *(_DWORD *)(v78[2] + 4 * v79)) + 48);
            }
          }
LABEL_261:
          if ( v145 == v142 )
          {
            v34 = v136;
LABEL_267:
            v14[12] = v34;
            return 0;
          }
        }
      }
    }
  }
  if ( v152 == 542113792 )
  {
    v81 = 0;
    v138 = v157;
    v139 = v158;
    v144 = 0;
    v143 = 0;
    v141 = 0;
    v140 = 0;
    while ( 2 )
    {
      v82 = *(unsigned int *)((char *)&v138 + v81);
      while ( 1 )
      {
        v88 = *(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v82);
        if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v88 + 4)) + 4) & 2) == 0 )
          break;
        v83 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v88 + 72));
        v84 = (void *)(*v83 & 0xFFF00000);
        if ( v84 == &loc_10100000 )
        {
          v85 = (char *)&v143 + v81;
        }
        else
        {
          if ( v84 != &unk_10300000 )
            break;
          v85 = (char *)&v140 + v81;
        }
        *(_DWORD *)v85 = *(_DWORD *)v85 == 0;
        v86 = 0;
        v142 = v83[3];
        if ( v142 != 0 )
        {
          for ( k = (_DWORD *)v83[4]; *k != v82; ++k )
          {
            if ( ++v86 >= v142 )
              goto LABEL_279;
          }
          v82 = *(_DWORD *)(v83[2] + 4 * v86);
        }
LABEL_279:
        if ( v86 >= v142 )
          return -2147467259;
      }
      *(unsigned int *)((char *)&v138 + v81) = v82;
      v81 += 4;
      if ( v81 < 8 )
        continue;
      break;
    }
    if ( v138 == v139 && v140 != v141 )
    {
      if ( v143 == v144 )
        v89 = 1.0;
      else
        v89 = -1.0;
      v49 = D3DXShader::CBaseProgram::AddArgument(this: v5, a2: *((_DWORD *)v5 + 30), a3: 0, a4: 0, a5: v89);
      goto LABEL_383;
    }
  }
  v91 = v157;
  if ( v152 == 538968064 )
  {
    v92 = *(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v157);
    if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v92 + 4)) + 4) & 2) != 0 && (v153 & 1) != 0 )
    {
      v93 = *(_DWORD **)(*((_DWORD *)v5 + 6) + 4 * *(_DWORD *)(v92 + 72));
      if ( (_UNKNOWN *)(*v93 & 0xFFF00000) == &loc_10100000 )
      {
        v94 = v93[3];
        v95 = 0;
        if ( v94 != 0 )
        {
          v96 = (_DWORD *)v93[4];
          do
          {
            if ( *v96 == v157 )
              break;
            ++v95;
            ++v96;
          }
          while ( v95 < v94 );
        }
        v97 = v93[2];
        v49 = v158;
        if ( *(_DWORD *)(v97 + 4 * v95) == v158 )
          goto LABEL_383;
      }
    }
  }
  v98 = *((_DWORD *)v5 + 5);
  v99 = *(_DWORD *)(v98 + 4 * v157);
  if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(v99 + 4)) + 4) & 2) != 0
    && (*(_BYTE *)(*(_DWORD *)(v147 + 4 * *(_DWORD *)(*(_DWORD *)(v98 + 4 * v158) + 4)) + 4) & 2) != 0 )
  {
    if ( v152 == 542113792 || v152 == 538968064 || v152 == 540016640 )
    {
      v100 = *((_DWORD *)v5 + 5);
      v101 = *((_DWORD *)v5 + 6);
      v102 = *(_DWORD **)(v101 + 4 * *(_DWORD *)(*(_DWORD *)(v100 + 4 * v157) + 72));
      v103 = *(_DWORD **)(v101 + 4 * *(_DWORD *)(*(_DWORD *)(v100 + 4 * v158) + 72));
      if ( (_UNKNOWN *)(*v102 & 0xFFF00000) == &loc_10100000 && (_UNKNOWN *)(*v103 & 0xFFF00000) == &loc_10100000 )
      {
        v104 = *((_DWORD *)a2 + 3);
        v145 = 0;
        if ( v104 != 0 )
        {
          v105 = *((_DWORD **)a2 + 4);
          do
          {
            if ( a3 == *v105 )
              break;
            ++v145;
            ++v105;
          }
          while ( v145 < v104 );
        }
        v106 = 0;
        if ( v102[3] != 0 )
        {
          v107 = (_DWORD *)v102[4];
          do
          {
            if ( v157 == *v107 )
              break;
            ++v106;
            ++v107;
          }
          while ( v106 < v102[3] );
        }
        v108 = 0;
        if ( v103[3] != 0 )
        {
          v109 = (_DWORD *)v103[4];
          do
          {
            if ( v158 == *v109 )
              break;
            ++v108;
            ++v109;
          }
          while ( v108 < v103[3] );
          v5 = v149;
        }
        if ( v152 == 542113792 )
        {
          v110 = *(_DWORD *)(v102[2] + 4 * v106);
          v111 = *(_DWORD *)(v103[2] + 4 * v108);
        }
        else
        {
          v110 = *(_DWORD *)(v103[2] + 4 * v108);
          v111 = *(_DWORD *)(v102[2] + 4 * v106);
        }
        v112 = v145;
        *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * v145) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v110) + 48);
        *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * (v112 + *((_DWORD *)a2 + 3))) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v5 + 5) + 4 * v111)
                                                                                        + 48);
        return 0;
      }
      v91 = v157;
    }
    if ( v152 == 542113792 )
    {
      if ( v91 == v158 )
      {
        v113 = *((_DWORD *)v5 + 6);
        v114 = *(_DWORD **)(v113 + 4 * *(_DWORD *)(v99 + 72));
        v115 = (void *)(*v114 & 0xFFF00000);
        if ( v115 == &unk_10300000 || v115 == (void *)275775488 )
        {
          v116 = 0;
          if ( v114[3] != 0 )
          {
            v117 = (_DWORD *)v114[4];
            do
            {
              if ( *v117 == v91 )
                break;
              ++v116;
              ++v117;
            }
            while ( v116 < v114[3] );
          }
          v118 = 4 * v116;
          v119 = *(_DWORD **)(*((_DWORD *)v5 + 5) + 4 * *(_DWORD *)(4 * v116 + v114[2]));
          if ( (*(_BYTE *)(*(_DWORD *)(v147 + 4 * v119[1]) + 4) & 2) != 0 && v119[2] == -1 )
          {
            v120 = *(_DWORD **)(v113 + 4 * v119[18]);
            v121 = (void *)(*v120 & 0xFFF00000);
            if ( (v121 == &unk_10300000 || v121 == (void *)275775488) && (void *)(*v114 & 0xFFF00000) != v121 )
            {
              v159 = 0;
              if ( v120[3] != 0 )
              {
                v122 = v120[4];
                do
                {
                  *(_DWORD *)(v122 + 4 * v159) = *(_DWORD *)(v118 + v114[2]);
                  v122 = v120[4];
                  if ( *(_DWORD *)(v122 + 4 * v159) != 0 )
                    break;
                  ++v159;
                }
                while ( v159 < v120[3] );
              }
              v47 = *(_DWORD *)(v120[2] + 4 * v159);
              v48 = *((_DWORD *)v149 + 5);
LABEL_145:
              v49 = *(_DWORD *)(*(_DWORD *)(v48 + 4 * v47) + 48);
              goto LABEL_383;
            }
          }
          v91 = v157;
          v5 = v149;
        }
      }
      v137 = *v148 & 1;
      if ( v137 != 0 && D3DXShader::CProgram::MulSequence(this: v5, a2: v91, a3: v158) != 0 )
      {
        v49 = v158;
        goto LABEL_383;
      }
      v141 = *v150 & 1;
      if ( v141 != 0 && D3DXShader::CProgram::MulSequence(this: v5, a2: v158, a3: v91) != 0 )
      {
        v151[12] = v91;
        return 0;
      }
      v156 = 0;
      v155 = 0;
      v145 = 1;
      v146 = 1;
      v123 = v151[6];
      v124 = v151[5];
      if ( v124 == -1 )
        return 0;
      do
      {
        v125 = *(_DWORD *)(4 * v124 + *((_DWORD *)v149 + 5));
        v142 = 4 * v124;
        v126 = *(_DWORD **)(*((_DWORD *)v149 + 6) + 4 * *(_DWORD *)(v125 + 72));
        v127 = v126[3];
        v128 = 0;
        if ( v127 != 0 )
        {
          v129 = (_DWORD *)v126[4];
          do
          {
            if ( *v129 == v124 )
              break;
            ++v128;
            ++v129;
          }
          while ( v128 < v127 );
        }
        if ( v137 != 0 )
        {
          v139 = *(_DWORD *)(v126[2] + 4 * v128);
          if ( (D3DXShader::CProgram::MulSequence(this: v149, a2: v157, a3: v139) & v123) != 0 )
            v156 = 1;
          if ( v123 == 0 && D3DXShader::CProgram::MulSequence(this: v149, a2: v139, a3: v157) != 0 )
          {
            v145 = 0;
            v156 = 1;
          }
        }
        if ( v141 != 0 )
        {
          v130 = *(_DWORD *)(v126[2] + 4 * v128);
          if ( (D3DXShader::CProgram::MulSequence(this: v149, a2: v158, a3: v130) & v123) != 0 )
            v155 = 1;
          v131 = v149;
          if ( v123 == 0 && D3DXShader::CProgram::MulSequence(this: v149, a2: v130, a3: v158) != 0 )
          {
            v146 = 0;
            v155 = 1;
          }
        }
        else
        {
          v131 = v149;
        }
        v132 = *(_DWORD *)(*((_DWORD *)v131 + 5) + v142);
        v123 = *(_DWORD *)(v132 + 24);
        v124 = *(_DWORD *)(v132 + 20);
      }
      while ( v124 != -1 );
      if ( v156 == 0 )
        goto LABEL_373;
      if ( v155 != 0 )
      {
        if ( v145 == 0 )
          goto LABEL_375;
        if ( v146 != 0 )
        {
          v133 = 1.0;
LABEL_376:
          v49 = D3DXShader::CBaseProgram::AddArgument(this: v131, a2: *((_DWORD *)v131 + 30), a3: 0, a4: 0, a5: v133);
          goto LABEL_383;
        }
      }
      if ( v145 != 0 )
      {
LABEL_373:
        if ( v155 == 0 || v146 != 0 )
        {
          if ( v156 != 0 && v145 != 0 )
          {
            v151[12] = v158;
            return 0;
          }
          if ( v155 == 0 || v146 == 0 )
            return 0;
          v49 = v157;
LABEL_383:
          v151[12] = v49;
          return 0;
        }
      }
LABEL_375:
      v133 = 0.0;
      goto LABEL_376;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E9E80
// Name: private: long D3DXShader::CProgram::SimplifyTernary(class D3DXShader::CInstruction __near *,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SimplifyTernary(
        D3DXShader::CProgram *this,
        struct D3DXShader::CInstruction *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  D3DXShader::CProgram *v6; // ebx
  int v7; // eax
  unsigned int v8; // esi
  int v9; // ecx
  unsigned int v10; // edi
  int *v11; // ecx
  int v12; // esi
  int v13; // eax
  int v14; // edx
  _DWORD *v15; // edi
  int v16; // edx
  int v17; // eax
  int v18; // edi
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // edx
  int v22; // eax
  int v23; // edx
  _DWORD *v25; // edx
  unsigned int v26; // esi
  _DWORD *v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // edx
  int v31; // edi
  _DWORD *v32; // edx
  D3DXShader::CProgram *v33; // edx
  bool v34; // zf
  _DWORD *v35; // ecx
  unsigned int v36; // esi
  unsigned int v37; // edx
  _DWORD *v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // esi
  _DWORD *v42; // edi
  _DWORD *v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  _DWORD *v47; // eax
  _DWORD *v48; // eax
  int v49; // ecx
  _DWORD *i; // edi
  bool v51; // cf
  unsigned int v52; // edi
  int v53; // eax
  int v54; // esi
  unsigned int v55; // [esp-8h] [ebp-B4h]
  _BYTE v56[8]; // [esp+Ch] [ebp-A0h] BYREF
  unsigned int *v57; // [esp+14h] [ebp-98h]
  _DWORD *v58; // [esp+1Ch] [ebp-90h]
  int v59; // [esp+80h] [ebp-2Ch]
  unsigned int v60; // [esp+84h] [ebp-28h]
  int v61; // [esp+88h] [ebp-24h]
  D3DXShader::CProgram *v62; // [esp+8Ch] [ebp-20h]
  int v63; // [esp+90h] [ebp-1Ch]
  _DWORD *v64; // [esp+94h] [ebp-18h]
  unsigned int v65; // [esp+98h] [ebp-14h]
  unsigned int v66; // [esp+9Ch] [ebp-10h]
  int v67; // [esp+A0h] [ebp-Ch]
  unsigned int v68; // [esp+A4h] [ebp-8h]
  unsigned int v69; // [esp+A8h] [ebp-4h]
  unsigned int v70; // [esp+BCh] [ebp+10h]
  unsigned int v71; // [esp+BCh] [ebp+10h]
  unsigned int v72; // [esp+C0h] [ebp+14h]
  unsigned int v73; // [esp+C4h] [ebp+18h]

  v6 = this;
  v62 = this;
  v7 = *((_DWORD *)this + 5);
  v8 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * a5) + 48);
  v9 = *(_DWORD *)(v7 + 4 * a6);
  v70 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * a4) + 48);
  v63 = *(_DWORD *)(v7 + 4 * v70);
  v10 = *(_DWORD *)(v9 + 48);
  v11 = *(int **)(v7 + 4 * a3);
  v67 = *(_DWORD *)(v7 + 4 * v8);
  v72 = v8;
  v12 = *(_DWORD *)(v7 + 4 * v10);
  v13 = *v11;
  v68 = *v11 & 0x40;
  v73 = v10;
  v14 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v62 + 4) + 4 * v11[1]) + 4);
  v61 = v12;
  if ( (v14 & 1) == 0 || (v14 & 0x1000) != 0 )
    return 0;
  if ( (v13 & 0xE000000) == 0 && (*(_DWORD *)a2 & 0xFFF00000) == 0x30000000 )
  {
    v15 = (_DWORD *)v67;
    v16 = *(_DWORD *)v67 | *(_DWORD *)v12;
    if ( (v16 & 0x8000000) != 0 )
    {
      v17 = v13 | 0x8000000;
    }
    else if ( (v16 & 0x4000000) != 0 )
    {
      v17 = v13 | 0x4000000;
    }
    else
    {
      if ( (v16 & 0x2000000) == 0 )
      {
LABEL_12:
        *v11 |= *v15 & *(_DWORD *)v12 & 0x1F;
        goto LABEL_14;
      }
      v17 = v13 | 0x2000000;
    }
    *v11 = v17;
    goto LABEL_12;
  }
  v15 = (_DWORD *)v67;
LABEL_14:
  if ( ((*(_BYTE *)v15 | *(_BYTE *)v12) & 0x40) != 0 && (*(_DWORD *)a2 & 0xFFF00000) == 0x30000000 )
    *v11 |= 0x40u;
  if ( (*(_DWORD *)a2 & 0xFFF00000) == 0x30000000 )
  {
    *v11 |= *v15 & *(_DWORD *)v12 & 0x1F;
    if ( v70 == v72 && (*(_BYTE *)v12 & 4) != 0 )
      *v11 |= 4u;
    if ( v70 == v73 && (*(_BYTE *)v15 & 8) != 0 )
      *v11 |= 8u;
  }
  if ( (*(_DWORD *)a2 & 0xFFF00000) != 0x30000000 )
    return 0;
  v18 = v63;
  if ( v68 != 0 || (*(_BYTE *)v63 & 4) == 0 )
  {
    v66 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *(_DWORD *)(v63 + 4)) + 4);
    if ( (v66 & 0x100) != 0 && *(_DWORD *)(v63 + 8) == -1 )
    {
      v19 = v72;
      if ( *(double *)(v63 + 32) < 0.0 )
        v19 = v73;
      goto LABEL_88;
    }
    v19 = v72;
    if ( v72 == v73 )
    {
LABEL_88:
      v11[12] = v19;
      return 0;
    }
    v20 = *((_DWORD *)v6 + 4);
    v65 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v67 + 4)) + 4) & 0x100;
    if ( v65 == 0
      || *(_DWORD *)(v67 + 8) != -1
      || (*(_BYTE *)(*(_DWORD *)(v20 + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) == 0
      || *(_DWORD *)(v12 + 8) != -1
      || *(double *)(v67 + 32) != *(double *)(v12 + 32) )
    {
      if ( v68 != 0 )
        return 0;
      if ( *(_DWORD *)(v63 + 8) == -1 && (v66 & 2) != 0 )
      {
        v68 = *(_DWORD *)(*((_DWORD *)v6 + 6) + 4 * *(_DWORD *)(v63 + 72));
        if ( (_UNKNOWN *)(*(_DWORD *)v68 & 0xFFF00000) == &loc_10100000
          && v65 != 0
          && *(_DWORD *)(v67 + 8) == -1
          && 0.0 == *(double *)(v67 + 32)
          && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
          && *(_DWORD *)(v12 + 8) == -1
          && 1.0 == *(double *)(v12 + 32) )
        {
          v21 = 0;
          if ( *(_DWORD *)(v68 + 12) != 0 )
          {
            v69 = *(_DWORD *)(v68 + 16);
            do
            {
              if ( *(_DWORD *)v69 == v70 )
                break;
              v69 += 4;
              ++v21;
            }
            while ( v21 < *(_DWORD *)(v68 + 12) );
          }
          v22 = *((_DWORD *)v6 + 5);
          v23 = *(_DWORD *)(*(_DWORD *)(v22 + 4 * *(_DWORD *)(*(_DWORD *)(v68 + 8) + 4 * v21)) + 48);
          if ( (**(_BYTE **)(v22 + 4 * v23) & 1) != 0 )
          {
            v11[12] = v23;
            return 0;
          }
          v18 = v63;
        }
      }
      if ( *(_DWORD *)(v18 + 8) != -1 )
        return 0;
      if ( (v66 & 2) != 0 )
      {
        v25 = *(_DWORD **)(*((_DWORD *)v6 + 6) + 4 * *(_DWORD *)(v18 + 72));
        if ( (*v25 & 0xFFF00000) == 0x20500000 && v65 != 0 && *(_DWORD *)(v67 + 8) == -1 && 0.0 == *(double *)(v67 + 32) )
        {
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
            && *(_DWORD *)(v12 + 8) == -1
            && 1.0 == *(double *)(v12 + 32) )
          {
            v26 = v25[3];
            v69 = 0;
            if ( v26 != 0 )
            {
              v27 = (_DWORD *)v25[4];
              do
              {
                if ( *v27 == v70 )
                  break;
                ++v69;
                ++v27;
              }
              while ( v69 < v26 );
            }
            v28 = v25[3];
            v29 = *((_DWORD *)v6 + 5);
            v30 = v25[2];
            v68 = 0;
            v59 = 4 * v28;
            v64 = (_DWORD *)(v30 + 4 * v69);
            v31 = -4 * v28;
            v6 = v62;
            v32 = (_DWORD *)(v30 + 4 * (v69 + v28));
            v69 = (unsigned int)v32;
            while ( 1 )
            {
              v33 = *(D3DXShader::CProgram **)(v29 + 4 * *(_DWORD *)(*(_DWORD *)(v29 + 4 * *v32) + 48));
              v60 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * *v64) + 48);
              v34 = (**(_BYTE **)(v29 + 4 * v60) & 1) == 0;
              v62 = v33;
              if ( !v34
                && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *((_DWORD *)v33 + 1)) + 5) & 1) != 0
                && *((_DWORD *)v62 + 2) == -1
                && *((double *)v62 + 4) < 0.0 )
              {
                break;
              }
              ++v68;
              v64 = (_DWORD *)((char *)v64 + v59);
              v32 = (_DWORD *)(v31 + v69);
              v69 += v31;
              if ( v68 >= 2 )
              {
                v12 = v61;
                goto LABEL_76;
              }
            }
            v19 = v60;
            goto LABEL_88;
          }
LABEL_76:
          v18 = v63;
        }
      }
      if ( *(_DWORD *)(v18 + 8) != -1 )
        return 0;
      if ( (v66 & 2) == 0 )
        return 0;
      v35 = *(_DWORD **)(*((_DWORD *)v6 + 6) + 4 * *(_DWORD *)(v18 + 72));
      if ( (*v35 & 0xFFF00000) != 0x20400000 )
        return 0;
      v66 = -1;
      if ( v65 != 0
        && *(_DWORD *)(v67 + 8) == -1
        && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * *(_DWORD *)(v12 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(v12 + 8) == -1 )
      {
        if ( 0.0 == *(double *)(v67 + 32) && 1.0 == *(double *)(v12 + 32) )
        {
          v66 = 538968065;
        }
        else if ( 1.0 == *(double *)(v67 + 32) && 0.0 == *(double *)(v12 + 32) )
        {
          v66 = 540016641;
        }
      }
      v36 = v35[3];
      v37 = 0;
      if ( v36 != 0 )
      {
        v38 = (_DWORD *)v35[4];
        do
        {
          if ( *v38 == v70 )
            break;
          ++v37;
          ++v38;
        }
        while ( v37 < v36 );
      }
      v39 = v35[3];
      v40 = v35[2];
      v71 = 0;
      v61 = 4 * v39;
      v41 = -4 * v39;
      v42 = (_DWORD *)(v40 + 4 * v37);
      v43 = (_DWORD *)(v40 + 4 * (v37 + v39));
      v64 = v42;
      v69 = (unsigned int)v43;
      while ( 1 )
      {
        v44 = *((_DWORD *)v6 + 5);
        v45 = *(_DWORD *)(v44 + 4 * *v43);
        v68 = *(_DWORD *)(*(_DWORD *)(v44 + 4 * *v42) + 48);
        v46 = *(_DWORD *)(v45 + 48);
        v47 = *(_DWORD **)(v44 + 4 * v46);
        if ( v47[2] == -1 && (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * v47[1]) + 4) & 2) != 0 )
        {
          v48 = *(_DWORD **)(*((_DWORD *)v6 + 6) + 4 * v47[18]);
          if ( (_UNKNOWN *)(*v48 & 0xFFF00000) == &loc_10100000 )
          {
            v49 = 0;
            if ( v48[3] != 0 )
            {
              for ( i = (_DWORD *)v48[4]; *i != v46; i = (_DWORD *)v60 )
              {
                v51 = (unsigned int)++v49 < v48[3];
                v60 = (unsigned int)(i + 1);
                if ( !v51 )
                  break;
              }
            }
            v52 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v6 + 5) + 4 * *(_DWORD *)(v48[2] + 4 * v49)) + 48);
            v65 = v66;
            if ( v66 != -1 )
              goto LABEL_114;
            if ( v72 == v52 && v73 == v68 )
            {
              v65 = 536870913;
              goto LABEL_114;
            }
            if ( v72 == v68 && v73 == v52 )
              break;
          }
        }
        v42 = (_DWORD *)((char *)v64 + v61);
        ++v71;
        v43 = (_DWORD *)(v41 + v69);
        v64 = (_DWORD *)((char *)v64 + v61);
        v69 += v41;
        if ( v71 >= 2 )
          return 0;
      }
      v65 = 537919489;
LABEL_114:
      D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v56);
      v53 = D3DXShader::CInstruction::Initialize(this: (D3DXShader::CInstruction *)v56, a2: v65, a3: 2u, a4: 1u, a5: 0);
      if ( v53 >= 0 )
      {
        v53 = D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v56, a2);
        if ( v53 >= 0 )
        {
          *v58 = a3;
          v55 = v68;
          *v57 = v68;
          v57[1] = v52;
          v53 = D3DXShader::CProgram::SimplifyBinary(
                  this: v6,
                  a2: (struct D3DXShader::CInstruction *)v56,
                  a3,
                  a4: v55,
                  a5: v52);
        }
      }
      v54 = v53;
      D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v56);
      return v54;
    }
  }
  v19 = v72;
  goto LABEL_88;
}

//------------------------------------------------------------------------------
// Address: 0x101EA4D3
// Name: protected: long D3DXShader::CProgram::VectorizeLeft(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::VectorizeLeft(D3DXShader::CProgram *this)
{
  unsigned int i; // edx
  _DWORD *v3; // eax
  int v4; // ecx
  unsigned int j; // eax
  int v6; // ecx
  int v7; // eax
  struct D3DXShader::CInstruction *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // ecx
  int result; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ecx
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  unsigned int v18; // edx
  int v19; // ecx
  int v20; // eax
  int *v21; // ecx
  int v22; // edi
  int v23; // eax
  unsigned int k; // eax
  _DWORD *v25; // ecx
  unsigned int m; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // edi
  unsigned int v30; // ecx
  int v31; // edx
  int v32; // ebx
  int v33; // [esp+Ch] [ebp-Ch]
  int v34; // [esp+Ch] [ebp-Ch]
  unsigned int v35; // [esp+10h] [ebp-8h]
  unsigned int v36; // [esp+14h] [ebp-4h]
  unsigned int ii; // [esp+14h] [ebp-4h]
  unsigned int v38; // [esp+14h] [ebp-4h]
  unsigned int n; // [esp+14h] [ebp-4h]

  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 2); ++i )
  {
    v3 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i);
    v4 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v3[1]);
    v3[16] = 0;
    if ( (*(_BYTE *)(v4 + 4) & 0x40) == 0 )
    {
      v3[3] = -1;
      v3[4] = -1;
    }
  }
  for ( j = 0; j < *((_DWORD *)this + 3); *(_DWORD *)(v6 + 40) = 0 )
  {
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * j) + 36) = 0;
    v6 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * j++);
  }
  D3DXShader::CProgram::ReadWriteInfo(this);
  v7 = *((_DWORD *)this + 3);
  v35 = v7;
  if ( v7 == 0 )
  {
LABEL_24:
    v18 = (unsigned int)(*((_DWORD *)this + 3) - v7) >> 1;
    v38 = 0;
    if ( v18 != 0 )
    {
      v19 = 4 * v7;
      v34 = 4 * v7;
      do
      {
        v20 = *((_DWORD *)this + 6);
        v21 = (int *)(v20 + v19);
        v22 = *v21;
        *v21 = *(_DWORD *)(v20 + 4 * (*((_DWORD *)this + 3) - v38) - 4);
        v23 = *((_DWORD *)this + 3) - v38++;
        *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v23 - 4) = v22;
        v19 = v34 + 4;
        v34 += 4;
      }
      while ( v38 < v18 );
    }
    for ( k = 0; k < v35; *v25 = 0 )
      v25 = *(_DWORD **)(*((_DWORD *)this + 6) + 4 * k++);
    result = D3DXShader::CProgram::CompactInstructions(this);
    if ( result >= 0 )
    {
      for ( m = 0; m < *((_DWORD *)this + 1); ++m )
      {
        v27 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * m);
        if ( (*(_BYTE *)(v27 + 4) & 0x40) == 0 )
          *(_DWORD *)(v27 + 16) = 0;
      }
      for ( n = 0; n < *((_DWORD *)this + 3); ++n )
      {
        v28 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * n);
        if ( (*(_WORD *)(v28 + 2) & 0xFFF0) != 0 && *(_DWORD *)(v28 + 12) != 0 )
        {
          v29 = *(_DWORD *)(*((_DWORD *)this + 4)
                          + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v28 + 16)) + 4));
          if ( (*(_BYTE *)(v29 + 4) & 0x40) == 0 )
          {
            v30 = 0;
            do
            {
              v31 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v28 + 16) + 4 * v30));
              v32 = *(_DWORD *)(v29 + 16);
              *(_DWORD *)(v31 + 16) = v30++;
              *(_DWORD *)(v31 + 12) = v32;
            }
            while ( v30 < *(_DWORD *)(v28 + 12) );
            ++*(_DWORD *)(v29 + 16);
          }
        }
      }
      return 0;
    }
    return result;
  }
  while ( 1 )
  {
    v33 = v7 - 1;
    v8 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * (v7 - 1));
    if ( (*(_DWORD *)v8 & 0xFFF00000) != 0 )
      break;
LABEL_22:
    v7 = v33;
    if ( v33 == 0 )
    {
      v7 = v35;
      goto LABEL_24;
    }
  }
  v9 = *((_DWORD *)this + 3);
  v10 = *(_DWORD *)v8 & 0xF0000000;
  if ( v10 < 0x10000000 || v10 > 0x40000000 )
  {
    if ( (*(_DWORD *)v8 & 0xFFF00000) == 0x50000000 )
      result = D3DXShader::CProgram::VectorizeLeft_DotProduct(this, a2: v8);
    else
      result = D3DXShader::CProgram::VectorizeLeft_Special(this, a2: (unsigned int **)v8);
  }
  else
  {
    result = D3DXShader::CProgram::VectorizeLeft_PerComponent(this, a2: v8);
  }
  if ( result < 0 )
    return result;
  v12 = *((_DWORD *)this + 3);
  v36 = v9;
  if ( v9 >= v12 )
  {
LABEL_19:
    v13 = (v12 - v9) >> 1;
    if ( v13 != 0 )
    {
      v14 = 4 * v9;
      v15 = 4 * v12;
      for ( ii = v13; ii != 0; --ii )
      {
        v16 = *((_DWORD *)this + 6);
        v17 = *(_DWORD *)(v14 + v16);
        *(_DWORD *)(v14 + v16) = *(_DWORD *)(v15 + v16 - 4);
        *(_DWORD *)(v15 + *((_DWORD *)this + 6) - 4) = v17;
        v14 += 4;
        v15 -= 4;
      }
    }
    goto LABEL_22;
  }
  while ( 1 )
  {
    result = D3DXShader::CProgram::VectorizeLeft_UpdateLinks(
               this,
               a2: *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v36));
    if ( result < 0 )
      return result;
    if ( ++v36 >= v12 )
      goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA70C
// Name: protected: long D3DXShader::CProgram::PropagateSwizzles(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CInstruction *__thiscall D3DXShader::CProgram::PropagateSwizzles(D3DXShader::CProgram *this)
{
  bool v2; // cc
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  int v9; // ecx
  D3DXShader::CInstruction *v10; // eax
  _DWORD *v11; // edi
  _DWORD *v12; // esi
  struct D3DXShader::CInstruction *v13; // eax
  D3DXShader::CInstruction *v14; // ecx
  unsigned int *v15; // edi
  int v16; // esi
  unsigned int v17; // eax
  D3DXShader::CInstruction *v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  bool v22; // cf
  int v23; // ecx
  D3DXShader::CInstruction *v24; // eax
  D3DXShader::CInstruction *v25; // edx
  char *v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // ecx
  unsigned int v30; // edx
  bool v31; // zf
  unsigned int v32; // eax
  int v33; // eax
  D3DXShader::CInstruction *v34; // ecx
  unsigned int v35; // eax
  int v36; // esi
  D3DXShader::CInstruction *v37; // eax
  D3DXShader::CInstruction *v38; // ecx
  int v39; // eax
  D3DXShader::CInstruction *v40; // ecx
  unsigned int v41; // eax
  unsigned int i; // eax
  unsigned int j; // ecx
  int v44; // esi
  int v45; // eax
  D3DXShader::CInstruction *v46; // edi
  unsigned int v47; // eax
  _DWORD *v48; // edx
  int v49; // eax
  int v50; // esi
  void **v51; // edx
  void *v52; // ecx
  int v53; // esi
  unsigned int m; // eax
  D3DXShader::CInstruction *v55; // esi
  unsigned int v56; // eax
  int v57; // ecx
  D3DXShader::CInstruction *v58; // esi
  unsigned int v59; // edi
  D3DXShader::CInstruction *v60; // eax
  int v61; // ecx
  int v62; // edx
  int v63; // edi
  unsigned int v64; // eax
  D3DXShader::CInstruction *v65; // edx
  int v66; // eax
  int v67; // ecx
  D3DXShader::CInstruction *v68; // edx
  int v69; // eax
  unsigned int v70; // eax
  D3DXShader::CInstruction *v71; // edx
  int v72; // eax
  int v73; // ecx
  int v74; // eax
  int v75; // ecx
  D3DXShader::CInstruction *v76; // edx
  int v77; // eax
  D3DXShader::CInstruction *v78; // ecx
  struct D3DXShader::CInstruction *v79; // edi
  int v80; // eax
  D3DXShader::CInstruction *v81; // ecx
  struct D3DXShader::CInstruction *v82; // edi
  int v83; // eax
  D3DXShader::CInstruction *v84; // edi
  unsigned int v85; // eax
  int v86; // eax
  _DWORD *v87; // ecx
  int v88; // edx
  unsigned int v89; // eax
  D3DXShader::CInstruction *v90; // esi
  int v91; // ecx
  int v92; // edx
  unsigned int v93; // eax
  D3DXShader::CInstruction *v94; // esi
  int v95; // eax
  int v96; // ecx
  unsigned int *v97; // ecx
  unsigned int v98; // eax
  int v99; // edx
  D3DXShader::CInstruction *v100; // esi
  int v101; // eax
  int v102; // ecx
  void *v103; // edx
  D3DXShader::CInstruction *v104; // eax
  D3DXShader::CInstruction *v105; // edi
  unsigned int v106; // eax
  char *v107; // edx
  int v108; // eax
  D3DXShader::CInstruction *v109; // ecx
  unsigned int v110; // esi
  char *v111; // ecx
  _DWORD *v112; // ecx
  int v113; // edx
  unsigned int v114; // eax
  int v115; // eax
  int v116; // ecx
  unsigned int v117; // edx
  unsigned int v118; // eax
  D3DXShader::CInstruction *v119; // esi
  int v120; // ecx
  int v121; // edx
  unsigned int v122; // eax
  D3DXShader::CInstruction *v123; // esi
  int v124; // eax
  int v125; // ecx
  unsigned int *v126; // ecx
  unsigned int v127; // eax
  int v128; // edx
  unsigned int v129; // eax
  int v130; // ecx
  D3DXShader::CInstruction *v131; // eax
  D3DXShader::CInstruction *v132; // ecx
  unsigned int v133; // esi
  char *v134; // edx
  char *v135; // edi
  unsigned int v136; // ecx
  unsigned int v137; // esi
  _DWORD *v138; // eax
  int v139; // ecx
  unsigned int v140; // eax
  char *v141; // ecx
  unsigned int *v142; // eax
  int v144; // ecx
  D3DXShader::CInstruction *v145; // eax
  int v146; // ecx
  D3DXShader::CInstruction *v147; // esi
  unsigned int v148; // eax
  unsigned int v149; // ecx
  unsigned int kk; // edi
  int v151; // ecx
  int v152; // edx
  int v153; // eax
  char *v154; // edx
  unsigned int v155; // eax
  int v156; // edi
  int v157; // eax
  int v158; // edx
  struct D3DXShader::CInstruction *v159; // edi
  int v160; // edx
  int v161; // eax
  D3DXShader::CInstruction *v162; // eax
  _DWORD *v163; // edx
  int v164; // eax
  unsigned int v165; // eax
  unsigned int v166; // eax
  int v167; // ecx
  int v168; // eax
  struct D3DXShader::CInstruction *v169; // edx
  unsigned int mm; // eax
  unsigned int Inputs; // eax
  int v172; // ecx
  struct D3DXShader::CInstruction *v173; // edx
  _DWORD *v174; // esi
  int v175; // ecx
  D3DXShader::CInstruction *v176; // ecx
  int v177; // edi
  unsigned int v178; // eax
  int v179; // eax
  unsigned int v180; // eax
  int v181; // edi
  int v182; // edx
  int v183; // edx
  _DWORD *i2; // edi
  int v185; // eax
  int v186; // eax
  unsigned int v187; // esi
  D3DXShader::CInstruction *v188; // ecx
  _DWORD *v189; // edx
  void *v190; // edi
  int v191; // eax
  void *v192; // eax
  unsigned int *v193; // edi
  unsigned int v194; // eax
  int v195; // esi
  unsigned int v196; // esi
  D3DXShader::CInstruction *v197; // edx
  unsigned int v198; // eax
  int v199; // ecx
  D3DXShader::CInstruction *v200; // edi
  struct D3DXShader::CInstruction *v201; // esi
  unsigned int v202; // eax
  unsigned int v203; // edx
  D3DXShader::CInstruction *v204; // edi
  unsigned int v205; // ecx
  _DWORD *v206; // eax
  unsigned __int8 *v207; // eax
  D3DXShader::CInstruction *v208; // edi
  int v209; // ecx
  struct D3DXShader::CInstruction *v210; // eax
  int v211; // eax
  int v212; // edx
  D3DXShader::CInstruction *v213; // ecx
  _DWORD *v214; // eax
  int v215; // ecx
  unsigned int v216; // eax
  int v217; // ecx
  D3DXShader::CInstruction *v218; // eax
  unsigned int v219; // esi
  int v220; // edx
  int v221; // esi
  int v222; // ecx
  unsigned int v223; // [esp+0h] [ebp-DCh]
  unsigned int v224; // [esp+0h] [ebp-DCh]
  D3DXShader::CInstruction *v225; // [esp+4h] [ebp-D8h]
  D3DXShader::CInstruction *v226; // [esp+4h] [ebp-D8h]
  unsigned int v227[12]; // [esp+1Ch] [ebp-C0h]
  unsigned int v228[4]; // [esp+4Ch] [ebp-90h] BYREF
  unsigned int v229[4]; // [esp+5Ch] [ebp-80h] BYREF
  _DWORD v230[4]; // [esp+6Ch] [ebp-70h] BYREF
  int v231; // [esp+7Ch] [ebp-60h] BYREF
  int v232; // [esp+80h] [ebp-5Ch]
  int v233; // [esp+84h] [ebp-58h]
  int v234; // [esp+88h] [ebp-54h]
  void *v235[4]; // [esp+8Ch] [ebp-50h] BYREF
  void *pMem; // [esp+9Ch] [ebp-40h]
  _DWORD *v237; // [esp+A0h] [ebp-3Ch]
  _DWORD *v238; // [esp+A4h] [ebp-38h]
  unsigned int nn; // [esp+A8h] [ebp-34h]
  unsigned int v240; // [esp+ACh] [ebp-30h]
  D3DXShader::CInstruction *v241; // [esp+B0h] [ebp-2Ch]
  unsigned int v242; // [esp+B4h] [ebp-28h]
  unsigned int v243; // [esp+B8h] [ebp-24h] BYREF
  D3DXShader::CInstruction *v244; // [esp+BCh] [ebp-20h]
  unsigned int *k; // [esp+C0h] [ebp-1Ch] BYREF
  D3DXShader::CInstruction *ii; // [esp+C4h] [ebp-18h] BYREF
  D3DXShader::CInstruction *v247[2]; // [esp+C8h] [ebp-14h]
  struct D3DXShader::CInstruction *i1; // [esp+D0h] [ebp-Ch]
  D3DXShader::CInstruction *n; // [esp+D4h] [ebp-8h]
  D3DXShader::CInstruction *jj; // [esp+D8h] [ebp-4h]

  jj = nullptr;
  D3DXShader::CProgram::ReadWriteInfo(this);
  v2 = *((_DWORD *)this + 2) == 0;
  v243 = 0;
  pMem = nullptr;
  if ( !v2 )
  {
    v3 = *((_DWORD *)this + 34);
    v4 = *((_DWORD *)this + 5);
    v5 = *((_DWORD *)this + 2);
    do
    {
      if ( v3 == *(_DWORD *)(*(_DWORD *)v4 + 4) )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v4 + 12);
        if ( v243 <= v6 )
          v243 = v6 + 1;
      }
      v4 += 4;
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( (*((_BYTE *)this + 108) & 0x20) == 0 )
  {
    v2 = *((_DWORD *)this + 3) == 0;
    ii = nullptr;
    if ( !v2 )
    {
      do
      {
        v31 = **(_DWORD **)(*((_DWORD *)this + 6) + 4 * (_DWORD)ii) == 1342177282;
        i1 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * (_DWORD)ii);
        if ( v31 )
        {
          v7 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x20500002u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
          if ( v7 == -1 )
            goto LABEL_341;
          v8 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x20400001u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
          if ( v8 == -1 )
            goto LABEL_341;
          v9 = *((_DWORD *)this + 6);
          v10 = *(D3DXShader::CInstruction **)(v9 + 4 * v8);
          k = *(unsigned int **)(v9 + 4 * v7);
          jj = v10;
          D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)k, a2: i1);
          D3DXShader::CInstruction::Instance(this: jj, a2: i1);
          v11 = (_DWORD *)k[2];
          v12 = *((_DWORD **)i1 + 2);
          v13 = i1;
          v14 = jj;
          v247[1] = nullptr;
          *v11 = *v12++;
          *++v11 = *v12++;
          *++v11 = *v12;
          v11[1] = v12[1];
          v15 = k;
          **((_DWORD **)v14 + 4) = **((_DWORD **)v13 + 4);
          do
          {
            v16 = 4 * (int)v247[1];
            v17 = D3DXShader::CBaseProgram::AddArgument(
                    this,
                    a2: *((_DWORD *)this + 34),
                    a3: v243,
                    a4: (unsigned int)v247[1],
                    a5: 0.0);
            v18 = jj;
            *(_DWORD *)(v16 + *((_DWORD *)jj + 2)) = v17;
            *(_DWORD *)(v16 + v15[4]) = *(_DWORD *)(v16 + *((_DWORD *)v18 + 2));
            if ( *(_DWORD *)(v16 + v15[4]) == -1 )
              goto LABEL_341;
            v19 = *((_DWORD *)this + 5);
            v15 = k;
            v20 = *(_DWORD *)(*(_DWORD *)(v19 + 4 * **((_DWORD **)i1 + 4)) + 24);
            v21 = *(_DWORD *)(v19 + 4 * *(_DWORD *)(v16 + k[4]));
            v22 = ++v247[1] < (D3DXShader::CInstruction *)2;
            *(_DWORD *)(v21 + 24) = v20;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v16 + v15[4])) + 20) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)i1 + 4)) + 20);
          }
          while ( v22 );
          v23 = *((_DWORD *)this + 3);
          v24 = ii;
          while ( --v23 > (unsigned int)v24 )
            *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v23) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v23 - 4);
          v25 = jj;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v24) = v15;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v24 + 4) = v25;
          D3DXShader::CInstruction::`scalar deleting destructor'(this: i1, a2: 1);
          --*((_DWORD *)this + 3);
          ++v243;
          jj = (D3DXShader::CInstruction *)1;
        }
        ii = (D3DXShader::CInstruction *)((char *)ii + 1);
      }
      while ( (unsigned int)ii < *((_DWORD *)this + 3) );
      if ( jj != nullptr )
        D3DXShader::CProgram::ReadWriteInfo(this);
    }
  }
  if ( (*((_BYTE *)this + 108) & 1) == 0 || (v26 = nullptr, v242 = *((_DWORD *)this + 3), k = nullptr, v242 == 0) )
  {
LABEL_39:
    if ( *((_DWORD *)this + 19) != 0 && (*((_BYTE *)this + 112) & 0x20) == 0 )
    {
      v2 = *((_DWORD *)this + 3) == 0;
      ii = nullptr;
      if ( !v2 )
      {
        do
        {
          v40 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * (_DWORD)ii);
          v41 = *(_DWORD *)v40 & 0xF0000000;
          v241 = v40;
          if ( v41 == 1610612736 )
          {
            v247[0] = (D3DXShader::CInstruction *)1;
            for ( i = D3DXShader::CInstruction::GetInputs(this: v40, a2: 1u, a3: &k);
                  i != 0;
                  i = D3DXShader::CInstruction::GetInputs(this: v241, a2: (unsigned int)v247[0], a3: &k) )
            {
              for ( j = 0; j < i; ++j )
              {
                if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * k[j]) + 16) != j )
                  break;
              }
              if ( j != i )
              {
                v44 = *((_DWORD *)this + 3);
                i1 = (struct D3DXShader::CInstruction *)D3DXShader::CProgram::PropagateSwizzles_Unswizzle(
                                                          this,
                                                          a2: (unsigned int)ii,
                                                          a3: (char *)k,
                                                          a4: i,
                                                          a5: &v243);
                if ( (int)i1 < 0 )
                  goto LABEL_178;
                v45 = *((_DWORD *)this + 3);
                if ( v45 != v44 )
                {
                  ii = (D3DXShader::CInstruction *)((char *)ii + v45 - v44);
                  D3DXShader::CProgram::ReadWriteInfo(this);
                }
                jj = (D3DXShader::CInstruction *)1;
              }
              ++v247[0];
            }
          }
          ii = (D3DXShader::CInstruction *)((char *)ii + 1);
        }
        while ( (unsigned int)ii < *((_DWORD *)this + 3) );
      }
    }
    if ( *((_DWORD *)this + 19) != 0 )
    {
      v2 = *((_DWORD *)this + 3) == 0;
      i1 = nullptr;
      if ( !v2 )
      {
        do
        {
          v46 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * (_DWORD)i1);
          v47 = *(_DWORD *)v46 & 0xFFF00000;
          ii = v46;
          if ( v47 == 285212672 )
          {
            if ( *((_DWORD *)v46 + 1) != 4 )
              goto LABEL_68;
            v48 = *((_DWORD **)v46 + 2);
            v49 = *((_DWORD *)this + 5);
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)(v49 + 4 * *v48) + 4)) + 5)
                & 2) != 0 )
              goto LABEL_68;
            v247[0] = nullptr;
            for ( k = (unsigned int *)4; k != nullptr; k = (unsigned int *)((char *)k - 1) )
            {
              v50 = 1 << *(_DWORD *)(*(_DWORD *)(v49 + 4 * *v48++) + 16);
              v247[0] = (D3DXShader::CInstruction *)((int)v247[0] | v50);
            }
            if ( v247[0] == (D3DXShader::CInstruction *)15 )
            {
              v51 = *((void ***)v46 + 2);
              k = (unsigned int *)4;
              do
              {
                v52 = *v51;
                v53 = *(_DWORD *)(*(_DWORD *)(v49 + 4 * (_DWORD)*v51++) + 16);
                v31 = k == (unsigned int *)1;
                k = (unsigned int *)((char *)k - 1);
                v235[v53] = v52;
              }
              while ( !v31 );
              for ( m = 0; m < 4; ++m )
                *(_DWORD *)(m * 4 + *((_DWORD *)v46 + 2)) = v235[m];
            }
            else
            {
LABEL_68:
              v55 = (D3DXShader::CInstruction *)D3DXShader::CBaseProgram::AddInstruction(
                                                  this,
                                                  a2: 0x10000004u,
                                                  a3: 0xFFFFFFFF,
                                                  a4: 0xFFFFFFFF);
              v241 = v55;
              v56 = D3DXShader::CBaseProgram::AddInstruction(this, a2: 0x11000004u, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
              if ( v55 == (D3DXShader::CInstruction *)-1 || v56 == -1 )
                goto LABEL_341;
              v57 = *((_DWORD *)this + 6);
              v58 = *(D3DXShader::CInstruction **)(v57 + 4 * (_DWORD)v55);
              n = *(D3DXShader::CInstruction **)(v57 + 4 * v56);
              D3DXShader::CInstruction::Instance(this: v58, a2: v46);
              D3DXShader::CInstruction::Instance(this: n, a2: v46);
              jj = nullptr;
              while ( 1 )
              {
                v59 = *((_DWORD *)v46 + 1);
                v60 = jj;
                if ( (unsigned int)jj >= v59 )
                  v60 = (D3DXShader::CInstruction *)(v59 - 1);
                v61 = *((_DWORD *)ii + 2);
                v62 = *((_DWORD *)v58 + 2);
                v226 = jj;
                v224 = v243;
                v247[1] = (D3DXShader::CInstruction *)(4 * (_DWORD)v60);
                v63 = 4 * (_DWORD)jj;
                *(_DWORD *)(4 * (_DWORD)jj + v62) = *(_DWORD *)(4 * (_DWORD)v60 + v61);
                v64 = D3DXShader::CBaseProgram::AddArgument(
                        this,
                        a2: *((_DWORD *)this + 34),
                        a3: v224,
                        a4: (unsigned int)v226,
                        a5: 0.0);
                v65 = v247[1];
                *(_DWORD *)(v63 + *((_DWORD *)v58 + 4)) = v64;
                v66 = *((_DWORD *)this + 5);
                v67 = *(_DWORD *)(v66 + 4 * *(_DWORD *)((char *)v65 + *((_DWORD *)ii + 4)));
                v68 = v247[1];
                *(_DWORD *)(*(_DWORD *)(v66 + 4 * *(_DWORD *)(v63 + *((_DWORD *)v58 + 4))) + 20) = *(_DWORD *)(v67 + 20);
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v63 + *((_DWORD *)v58 + 4))) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)((char *)v68 + *((_DWORD *)ii + 4))) + 24);
                v69 = *((_DWORD *)v58 + 4);
                if ( *(_DWORD *)(v63 + v69) == -1 )
                  goto LABEL_341;
                *(_DWORD *)(v63 + *((_DWORD *)n + 2)) = *(_DWORD *)(v63 + v69);
                v70 = D3DXShader::CBaseProgram::AddArgument(
                        this,
                        a2: *((_DWORD *)this + 42),
                        a3: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 42)) + 8),
                        a4: (unsigned int)jj,
                        a5: 0.0);
                v71 = v247[1];
                *(_DWORD *)(v63 + *((_DWORD *)n + 4)) = v70;
                v72 = *((_DWORD *)this + 5);
                v73 = *(_DWORD *)(v72 + 4 * *(_DWORD *)((char *)v71 + *((_DWORD *)ii + 4)));
                v74 = *(_DWORD *)(v72 + 4 * *(_DWORD *)(v63 + *((_DWORD *)n + 4)));
                v75 = *(_DWORD *)(v73 + 20);
                v76 = v247[1];
                jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                v22 = (unsigned int)jj < 4;
                *(_DWORD *)(v74 + 20) = v75;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v63 + *((_DWORD *)n + 4))) + 24) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)((char *)v76 + *((_DWORD *)ii + 4))) + 24);
                if ( !v22 )
                  break;
                v46 = ii;
              }
              v77 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * *((_DWORD *)this + 42));
              ++*(_DWORD *)(v77 + 8);
              v78 = v241;
              v79 = i1;
              while ( 1 )
              {
                v80 = *((_DWORD *)this + 6);
                if ( v78 <= v79 )
                  break;
                *(_DWORD *)(v80 + 4 * (_DWORD)v78) = *(_DWORD *)(v80 + 4 * (_DWORD)v78 - 4);
                v78 = (D3DXShader::CInstruction *)((char *)v78 - 1);
              }
              v81 = ii;
              *(_DWORD *)(v80 + 4 * (_DWORD)v79) = v58;
              v82 = (struct D3DXShader::CInstruction *)((char *)v79 + 1);
              i1 = v82;
              D3DXShader::CInstruction::`scalar deleting destructor'(this: v81, a2: 1);
              --*((_DWORD *)this + 3);
              v83 = *((_DWORD *)this + 6);
              ++v243;
              *(_DWORD *)(v83 + 4 * (_DWORD)v82) = n;
              jj = (D3DXShader::CInstruction *)1;
            }
          }
          i1 = (struct D3DXShader::CInstruction *)((char *)i1 + 1);
        }
        while ( (unsigned int)i1 < *((_DWORD *)this + 3) );
      }
    }
    if ( (*((_BYTE *)this + 108) & 6) != 0 )
    {
      for ( n = nullptr; (unsigned int)n < *((_DWORD *)this + 3); n = (D3DXShader::CInstruction *)((char *)n + 1) )
      {
        v84 = *(D3DXShader::CInstruction **)(4 * (_DWORD)n + *((_DWORD *)this + 6));
        v85 = *(_DWORD *)v84 & 0xFFF00000;
        v241 = v84;
        if ( v85 == 0x10000000 )
        {
          v86 = *((_DWORD *)this + 5);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                     + 4 * *(_DWORD *)(*(_DWORD *)(v86 + 4 * **((_DWORD **)v84 + 4)) + 4))
                         + 4)
              & 0x20) == 0 )
          {
            v247[1] = nullptr;
            if ( *((_DWORD *)v84 + 3) != 0 )
            {
              v87 = *((_DWORD **)v84 + 2);
              v88 = *(_DWORD *)(*(_DWORD *)(v86 + 4 * *v87) + 72);
              do
              {
                if ( v88 != *(_DWORD *)(*(_DWORD *)(v86 + 4 * *v87) + 72) )
                  break;
                ++v247[1];
                ++v87;
              }
              while ( v247[1] < (D3DXShader::CInstruction *)*((_DWORD *)v84 + 3) );
            }
            if ( v247[1] != *((D3DXShader::CInstruction **)v84 + 3) )
            {
              v89 = *((_DWORD *)v84 + 1);
              ii = nullptr;
              jj = nullptr;
              if ( v89 != 0 )
              {
                do
                {
                  v90 = (D3DXShader::CInstruction *)(*((_DWORD *)v84 + 2) + 4 * (_DWORD)jj);
                  if ( *(_DWORD *)v90 != -1 )
                  {
                    v91 = *((_DWORD *)this + 5);
                    v242 = *(_DWORD *)(*(_DWORD *)(v91 + 4 * *(_DWORD *)v90) + 72);
                    v92 = 0;
                    if ( (unsigned int)jj < v89 )
                    {
                      v247[0] = v90;
                      k = (unsigned int *)(v89 - (_DWORD)jj);
                      do
                      {
                        if ( *(_DWORD *)v247[0] != -1
                          && v242 == *(_DWORD *)(*(_DWORD *)(v91 + 4 * *(_DWORD *)v247[0]) + 72) )
                        {
                          ++v92;
                        }
                        v247[0] = (D3DXShader::CInstruction *)((char *)v247[0] + 4);
                        k = (unsigned int *)((char *)k - 1);
                      }
                      while ( k != nullptr );
                    }
                    v93 = D3DXShader::CBaseProgram::AddInstruction(
                            this,
                            a2: v92 & 0xFFFFF | 0x10000000,
                            a3: 0xFFFFFFFF,
                            a4: 0xFFFFFFFF);
                    if ( v93 == -1 )
                      goto LABEL_341;
                    v244 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v93);
                    v94 = v244;
                    D3DXShader::CInstruction::Instance(this: v244, a2: v84);
                    ii = (D3DXShader::CInstruction *)((char *)ii + 1);
                    v22 = (unsigned int)jj < *((_DWORD *)v84 + 1);
                    v247[1] = jj;
                    if ( v22 )
                    {
                      k = nullptr;
                      do
                      {
                        v95 = 4 * (int)v247[1];
                        v96 = *(_DWORD *)(4 * (int)v247[1] + *((_DWORD *)v84 + 2));
                        if ( v96 != -1 && v242 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v96) + 72) )
                        {
                          v97 = k;
                          *(unsigned int *)((char *)k + *((_DWORD *)v94 + 2)) = *(_DWORD *)(v95 + *((_DWORD *)v84 + 2));
                          *(unsigned int *)((char *)v97 + *((_DWORD *)v244 + 4)) = *(_DWORD *)(v95 + *((_DWORD *)v84 + 4));
                          *(_DWORD *)(v95 + *((_DWORD *)v84 + 2)) = -1;
                          v94 = v244;
                          k = v97 + 1;
                        }
                        ++v247[1];
                      }
                      while ( v247[1] < (D3DXShader::CInstruction *)*((_DWORD *)v84 + 1) );
                    }
                  }
                  jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                  v89 = *((_DWORD *)v84 + 1);
                }
                while ( (unsigned int)jj < v89 );
                if ( ii != nullptr )
                {
                  qmemcpy(
                    v235,
                    (const void *)(*((_DWORD *)this + 6) + 4 * (*((_DWORD *)this + 3) - (_DWORD)ii)),
                    4 * (_DWORD)ii);
                  v84 = v241;
                }
              }
              v98 = *((_DWORD *)this + 3) - (_DWORD)ii - 1;
              if ( v98 > (unsigned int)n )
              {
                v99 = 4 * (*((_DWORD *)this + 3) - 1);
                do
                {
                  *(_DWORD *)(*((_DWORD *)this + 6) + v99 - 4) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v98--);
                  v99 -= 4;
                }
                while ( v98 > (unsigned int)n );
              }
              v100 = ii;
              v247[1] = nullptr;
              if ( ii != nullptr )
              {
                v101 = 4 * (_DWORD)n;
                do
                {
                  v102 = *((_DWORD *)this + 6);
                  v103 = v235[(int)v247[1]++];
                  *(_DWORD *)(v101 + v102) = v103;
                  v101 += 4;
                }
                while ( v247[1] < v100 );
              }
              D3DXShader::CInstruction::`scalar deleting destructor'(this: v84, a2: 1);
              v104 = n;
              --*((_DWORD *)this + 3);
              n = (D3DXShader::CInstruction *)((char *)v100 + (_DWORD)v104 - 1);
              jj = (D3DXShader::CInstruction *)1;
            }
          }
        }
      }
      for ( ii = nullptr; (unsigned int)ii < *((_DWORD *)this + 3); ii = (D3DXShader::CInstruction *)((char *)ii + 1) )
      {
        v105 = *(D3DXShader::CInstruction **)(4 * (_DWORD)ii + *((_DWORD *)this + 6));
        v106 = *(_DWORD *)v105 & 0xFFF00000;
        v241 = v105;
        if ( v106 == 0x10000000 )
        {
          v107 = *((char **)v105 + 4);
          v108 = *((_DWORD *)this + 5);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                     + 4 * *(_DWORD *)(*(_DWORD *)(v108 + 4 * *(_DWORD *)v107) + 4))
                         + 4)
              & 0x20) == 0 )
          {
            v109 = *((D3DXShader::CInstruction **)v105 + 3);
            v110 = 0;
            v244 = nullptr;
            v247[1] = nullptr;
            v240 = 0;
            if ( v109 != nullptr )
            {
              v111 = *((char **)v105 + 2);
              n = nullptr;
              v247[0] = (D3DXShader::CInstruction *)(v107 - v111);
              v238 = v111;
              do
              {
                if ( *(_DWORD *)(*(_DWORD *)(v108 + 4 * *(_DWORD *)((char *)v247[0] + (unsigned int)v238)) + 16) == *(_DWORD *)(*(_DWORD *)(v108 + 4 * *v238) + 16) )
                  ++v240;
                i1 = nullptr;
                if ( n != nullptr )
                {
                  v112 = *((_DWORD **)v105 + 2);
                  v113 = *(_DWORD *)(*(_DWORD *)(v108 + 4 * *(_DWORD *)((char *)v112 + (_DWORD)n)) + 16);
                  while ( *(_DWORD *)(*(_DWORD *)(v108 + 4 * *v112) + 16) != v113 )
                  {
                    i1 = (struct D3DXShader::CInstruction *)((char *)i1 + 1);
                    ++v112;
                    if ( i1 >= v247[1] )
                      goto LABEL_129;
                  }
                  v244 = (D3DXShader::CInstruction *)((char *)v244 + 1);
                }
LABEL_129:
                ++v247[1];
                v109 = *((D3DXShader::CInstruction **)v105 + 3);
                n = (D3DXShader::CInstruction *)((char *)n + 4);
                ++v238;
              }
              while ( v247[1] < v109 );
              v110 = v240;
            }
            if ( (D3DXShader::CInstruction *)v110 != v109
              && (D3DXShader::CInstruction *)((char *)v244 + 1) != v109
              && (v110 > 1 || v244 != nullptr) )
            {
              n = nullptr;
              if ( v110 > 1 )
              {
                v114 = D3DXShader::CBaseProgram::AddInstruction(
                         this,
                         a2: v110 & 0xFFFFF | 0x10000000,
                         a3: 0xFFFFFFFF,
                         a4: 0xFFFFFFFF);
                if ( v114 == -1 )
                  goto LABEL_341;
                k = *(unsigned int **)(*((_DWORD *)this + 6) + 4 * v114);
                D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)k, a2: v105);
                v31 = *((_DWORD *)v105 + 3) == 0;
                n = (D3DXShader::CInstruction *)1;
                v247[1] = nullptr;
                if ( !v31 )
                {
                  v242 = 0;
                  do
                  {
                    v115 = 4 * (int)v247[1];
                    v116 = *(_DWORD *)(4 * (int)v247[1] + *((_DWORD *)v105 + 4));
                    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v116) + 16) == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(4 * (int)v247[1] + *((_DWORD *)v105 + 2))) + 16) )
                    {
                      v117 = v242;
                      *(_DWORD *)(v242 + k[4]) = v116;
                      *(_DWORD *)(v117 + k[2]) = *(_DWORD *)(v115 + *((_DWORD *)v105 + 2));
                      *(_DWORD *)(v115 + *((_DWORD *)v105 + 2)) = -1;
                      v242 = v117 + 4;
                    }
                    ++v247[1];
                  }
                  while ( v247[1] < (D3DXShader::CInstruction *)*((_DWORD *)v105 + 3) );
                }
              }
              v118 = *((_DWORD *)v105 + 1);
              for ( jj = nullptr; (unsigned int)jj < v118; v118 = *((_DWORD *)v105 + 1) )
              {
                v119 = (D3DXShader::CInstruction *)(*((_DWORD *)v105 + 2) + 4 * (_DWORD)jj);
                if ( *(_DWORD *)v119 != -1 )
                {
                  v120 = *((_DWORD *)this + 5);
                  v242 = *(_DWORD *)(*(_DWORD *)(v120 + 4 * *(_DWORD *)v119) + 16);
                  v121 = 0;
                  if ( (unsigned int)jj < v118 )
                  {
                    v244 = v119;
                    k = (unsigned int *)(v118 - (_DWORD)jj);
                    do
                    {
                      if ( *(_DWORD *)v244 != -1 && v242 == *(_DWORD *)(*(_DWORD *)(v120 + 4 * *(_DWORD *)v244) + 16) )
                        ++v121;
                      v244 = (D3DXShader::CInstruction *)((char *)v244 + 4);
                      k = (unsigned int *)((char *)k - 1);
                    }
                    while ( k != nullptr );
                  }
                  v122 = D3DXShader::CBaseProgram::AddInstruction(
                           this,
                           a2: v121 & 0xFFFFF | 0x10000000,
                           a3: 0xFFFFFFFF,
                           a4: 0xFFFFFFFF);
                  if ( v122 == -1 )
                    goto LABEL_341;
                  v244 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v122);
                  v123 = v244;
                  D3DXShader::CInstruction::Instance(this: v244, a2: v105);
                  n = (D3DXShader::CInstruction *)((char *)n + 1);
                  v22 = (unsigned int)jj < *((_DWORD *)v105 + 1);
                  v247[1] = jj;
                  if ( v22 )
                  {
                    k = nullptr;
                    do
                    {
                      v124 = 4 * (int)v247[1];
                      v125 = *(_DWORD *)(4 * (int)v247[1] + *((_DWORD *)v105 + 2));
                      if ( v125 != -1 && v242 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v125) + 16) )
                      {
                        v126 = k;
                        *(unsigned int *)((char *)k + *((_DWORD *)v123 + 4)) = *(_DWORD *)(v124 + *((_DWORD *)v105 + 4));
                        *(unsigned int *)((char *)v126 + *((_DWORD *)v244 + 2)) = *(_DWORD *)(v124
                                                                                            + *((_DWORD *)v105 + 2));
                        *(_DWORD *)(v124 + *((_DWORD *)v105 + 2)) = -1;
                        v123 = v244;
                        k = v126 + 1;
                      }
                      ++v247[1];
                    }
                    while ( v247[1] < (D3DXShader::CInstruction *)*((_DWORD *)v105 + 1) );
                  }
                }
                jj = (D3DXShader::CInstruction *)((char *)jj + 1);
              }
              if ( n != nullptr )
              {
                qmemcpy(
                  v235,
                  (const void *)(*((_DWORD *)this + 6) + 4 * (*((_DWORD *)this + 3) - (_DWORD)n)),
                  4 * (_DWORD)n);
                v105 = v241;
              }
              v127 = *((_DWORD *)this + 3) - (_DWORD)n - 1;
              if ( v127 > (unsigned int)ii )
              {
                v128 = 4 * (*((_DWORD *)this + 3) - 1);
                do
                {
                  *(_DWORD *)(*((_DWORD *)this + 6) + v128 - 4) = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v127--);
                  v128 -= 4;
                }
                while ( v127 > (unsigned int)ii );
              }
              v129 = 0;
              if ( n != nullptr )
              {
                v130 = 4 * (_DWORD)ii;
                do
                {
                  *(_DWORD *)(v130 + *((_DWORD *)this + 6)) = v235[v129++];
                  v130 += 4;
                }
                while ( v129 < (unsigned int)n );
              }
              D3DXShader::CInstruction::`scalar deleting destructor'(this: v105, a2: 1);
              v131 = ii;
              v132 = n;
              --*((_DWORD *)this + 3);
              ii = (D3DXShader::CInstruction *)((char *)v132 + (_DWORD)v131 - 1);
              jj = (D3DXShader::CInstruction *)1;
            }
          }
        }
      }
    }
    if ( jj != nullptr )
      D3DXShader::CProgram::ReadWriteInfo(this);
    v133 = 4 * v243;
    v134 = (char *)MemAlloc_Alloc(nSize: 4 * v243);
    pMem = v134;
    if ( v134 == nullptr )
      goto LABEL_341;
    memset(v134, 0, 4 * (v133 >> 2));
    v135 = &v134[4 * (v133 >> 2)];
    v136 = v133 & 3;
    v137 = 0;
    memset(v135, 0, v136);
    if ( *((_DWORD *)this + 2) != 0 )
    {
      do
      {
        v138 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v137);
        v138[23] = 0;
        if ( *((_DWORD *)this + 34) == v138[1] )
        {
          v139 = v138[3];
          v140 = v138[4];
          v141 = &v134[4 * v139];
          if ( v140 >= *(_DWORD *)v141 )
            *(_DWORD *)v141 = v140 + 1;
        }
        ++v137;
      }
      while ( v137 < *((_DWORD *)this + 2) );
    }
    v142 = *((unsigned int **)this + 3);
    if ( v142 == nullptr )
    {
LABEL_177:
      i1 = nullptr;
      goto LABEL_178;
    }
    while ( 1 )
    {
      v144 = *((_DWORD *)this + 6);
      k = (unsigned int *)((char *)v142 - 1);
      v145 = *(D3DXShader::CInstruction **)(v144 + 4 * ((_DWORD)v142 - 1));
      v146 = *(_DWORD *)v145;
      v31 = (*(_DWORD *)v145 & 0xFFF00000) == 0;
      v247[1] = v145;
      if ( v31 )
        goto LABEL_339;
      v147 = v145;
      v148 = *((_DWORD *)v145 + 1);
      i1 = (struct D3DXShader::CInstruction *)(v146 & 0xFFFFF);
      v31 = *((_DWORD *)v147 + 3) == 0;
      v242 = v148 / (v146 & 0xFFFFFu);
      if ( !v31 )
      {
        v149 = v146 & 0xF0000000;
        if ( v149 >= 0x10000000 && v149 <= 0x40000000 )
        {
          D3DXShader::CProgram::SwizzleParameter(
            this,
            a2: *((unsigned int **)v147 + 4),
            a3: v228,
            a4: (unsigned int)i1,
            a5: 1);
          for ( kk = 0; kk < v242; ++kk )
            D3DXShader::CProgram::SwizzleParameter(
              this,
              a2: (unsigned int *)(*((_DWORD *)v147 + 2) + 4 * kk * *((_DWORD *)v147 + 3)),
              a3: v228,
              a4: (unsigned int)i1,
              a5: 0);
        }
      }
      v231 = 0;
      v232 = 0;
      v233 = 0;
      v234 = 0;
      if ( (*(_DWORD *)v147 & 0xFFF00000) == 0x10000000 )
      {
        v151 = *((_DWORD *)this + 5);
        v152 = *((_DWORD *)this + 4);
        v240 = *(_DWORD *)(v151 + 4 * **((_DWORD **)v147 + 4));
        v153 = *(_DWORD *)(*(_DWORD *)(v152 + 4 * *(_DWORD *)(v240 + 4)) + 4);
        if ( (v153 & 4) == 0 && ((*((_BYTE *)this + 108) & 1) == 0 || (v153 & 0x20) == 0) )
        {
          v154 = *((char **)v147 + 2);
          if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)(v151 + 4 * *(_DWORD *)v154) + 4) )
          {
            v155 = 0;
            v31 = *((_DWORD *)v147 + 1) == 0;
            v242 = 0;
            if ( !v31 )
            {
              v156 = *((_DWORD *)this + 51);
              v244 = (D3DXShader::CInstruction *)(v154 - (char *)&v231);
              v241 = (D3DXShader::CInstruction *)(v156 & 4);
              do
              {
                v157 = *(_DWORD *)(v151 + 4 * *(int *)((char *)&v231 + (_DWORD)v244 + 4 * v155));
                v158 = *((_DWORD *)this + 6);
                v247[0] = *(D3DXShader::CInstruction **)(v157 + 72);
                v159 = *(struct D3DXShader::CInstruction **)(v158 + 4 * (int)v247[0]);
                i1 = v159;
                if ( v241 != nullptr )
                {
                  nn = *(_DWORD *)(v240 + 96);
                  if ( nn != 0 )
                  {
                    v160 = *(_DWORD *)(v157 + 96);
                    if ( v160 != 0 && nn != v160 )
                      break;
                  }
                }
                if ( *(_DWORD *)(v240 + 24) != *(_DWORD *)(v157 + 24)
                  || *(_DWORD *)(v240 + 20) != *(_DWORD *)(v157 + 20) )
                {
                  break;
                }
                jj = nullptr;
                if ( *((_DWORD *)v159 + 3) != 0 )
                {
                  v238 = *((_DWORD **)v159 + 4);
                  do
                  {
                    v161 = *(_DWORD *)(v151 + 4 * *v238);
                    if ( k != *(unsigned int **)(v161 + 84) )
                      break;
                    if ( k != *(unsigned int **)(v161 + 88) )
                      break;
                    jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                    ++v238;
                  }
                  while ( (unsigned int)jj < *((_DWORD *)v159 + 3) );
                }
                v162 = *((D3DXShader::CInstruction **)v159 + 3);
                if ( jj != v162 )
                  break;
                jj = nullptr;
                if ( v162 != nullptr )
                {
                  v163 = *((_DWORD **)v159 + 4);
                  do
                  {
                    v164 = *(_DWORD *)(*(_DWORD *)(v151 + 4 * *v163) + 20);
                    if ( v164 != -1 )
                    {
                      v159 = i1;
                      if ( (D3DXShader::CInstruction *)*(_DWORD *)(*(_DWORD *)(v151 + 4 * v164) + 72) >= v247[0] )
                        break;
                    }
                    jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                    ++v163;
                    v22 = (unsigned int)jj < *((_DWORD *)v159 + 3);
                    v159 = i1;
                  }
                  while ( v22 );
                }
                if ( jj != *((D3DXShader::CInstruction **)v159 + 3) )
                  break;
                if ( (*(_DWORD *)v159 & 0xFFF00000) == 0x20700000 )
                  break;
                v165 = v242;
                *(&v231 + v242) = 1;
                v155 = v165 + 1;
                v22 = v155 < *((_DWORD *)v147 + 1);
                v242 = v155;
              }
              while ( v22 );
            }
          }
        }
      }
      v166 = *(_DWORD *)v147 & 0xF0000000;
      if ( v166 < 0x10000000 || v166 > 0x40000000 )
      {
        for ( mm = 0; mm < 4; ++mm )
          v229[mm] = mm;
      }
      else
      {
        i1 = nullptr;
        if ( *((_DWORD *)v147 + 3) != 0 )
        {
          v167 = *((_DWORD *)this + 5);
          v168 = *((_DWORD *)v147 + 4) - (_DWORD)v229;
          do
          {
            v169 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i1);
            i1 = (struct D3DXShader::CInstruction *)((char *)i1 + 1);
            *(unsigned int *)((char *)v229 + (_DWORD)v169) = *(_DWORD *)(*(_DWORD *)(v167
                                                                                   + 4
                                                                                   * *(unsigned int *)((char *)v229 + (_DWORD)v169 + v168))
                                                                       + 16);
          }
          while ( (unsigned int)i1 < *((_DWORD *)v147 + 3) );
        }
      }
      v242 = 0;
      Inputs = D3DXShader::CInstruction::GetInputs(this: v147, a2: 0, a3: (unsigned int **)&ii);
LABEL_330:
      v243 = Inputs;
      if ( Inputs != 0 )
        break;
      v218 = v247[1];
      if ( (*(_DWORD *)v247[1] & 0xFFF00000) == 0x10000000 )
      {
        v219 = 0;
        v220 = 0;
        v31 = *((_DWORD *)v247[1] + 3) == 0;
        v242 = 0;
        if ( !v31 )
        {
          do
          {
            if ( *(&v231 + v219) != 0 )
            {
              v221 = *((_DWORD *)this + 5);
              v222 = 4 * v220;
              v31 = *(_DWORD *)(*(_DWORD *)(v221 + 4 * *(_DWORD *)(4 * v220 + *((_DWORD *)v218 + 4))) + 96) == 0;
              v237 = *(_DWORD **)(v221 + 4 * *(_DWORD *)(4 * v220 + *((_DWORD *)v218 + 4)));
              if ( v31 )
              {
                v237[24] = *(_DWORD *)(*(_DWORD *)(v221 + 4 * *(_DWORD *)(v222 + *((_DWORD *)v218 + 2))) + 96);
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v222 + *((_DWORD *)v218 + 4))) + 100) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v222 + *((_DWORD *)v218 + 2))) + 100);
              }
            }
            else
            {
              *(_DWORD *)(*((_DWORD *)v218 + 4) + 4 * v220) = *(_DWORD *)(*((_DWORD *)v218 + 4) + 4 * v219);
              *(_DWORD *)(*((_DWORD *)v218 + 2) + 4 * v220++) = *(_DWORD *)(*((_DWORD *)v218 + 2) + 4 * v242);
            }
            v219 = v242 + 1;
            v22 = ++v242 < *((_DWORD *)v218 + 3);
          }
          while ( v22 );
        }
        *(_DWORD *)v218 = v220 != 0 ? v220 & 0xFFFFF | 0x10000000 : 0;
        *((_DWORD *)v218 + 1) = v220;
        *((_DWORD *)v218 + 3) = v220;
      }
LABEL_339:
      if ( k == nullptr )
        goto LABEL_177;
      v142 = k;
    }
    memset(v230, 0, sizeof(v230));
    n = nullptr;
    v238 = nullptr;
    i1 = nullptr;
    while ( 1 )
    {
      v172 = *((_DWORD *)this + 5);
      v173 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i1);
      v241 = (D3DXShader::CInstruction *)((char *)ii + 4 * (_DWORD)i1);
      v174 = *(_DWORD **)(v172 + 4 * *(_DWORD *)v241);
      if ( *((_DWORD *)this + 34) != v174[1] || (v175 = v174[18]) == -1 )
      {
LABEL_260:
        if ( (unsigned int)i1 < v243 )
          n = (D3DXShader::CInstruction *)1;
        if ( n != nullptr )
          goto LABEL_277;
        if ( (*(_DWORD *)v247[1] & 0xFFF00000) != 0x10000000 )
        {
          v185 = 0;
          while ( v230[v185] != v243 )
          {
            if ( (unsigned int)++v185 >= 4 )
              goto LABEL_269;
          }
          n = (D3DXShader::CInstruction *)1;
LABEL_269:
          if ( n != nullptr )
            goto LABEL_277;
        }
        if ( v238 == *((_DWORD **)pMem + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)ii) + 12)) )
          goto LABEL_278;
        v186 = 0;
        if ( *((_DWORD *)v247[1] + 3) == 0 )
          goto LABEL_278;
        while ( *(&v231 + v186) != 0 )
        {
          if ( (unsigned int)++v186 >= *((_DWORD *)v247[1] + 3) )
            goto LABEL_276;
        }
        n = (D3DXShader::CInstruction *)1;
LABEL_276:
        if ( n != nullptr )
        {
LABEL_277:
          v231 = 0;
          v232 = 0;
          v233 = 0;
          v234 = 0;
        }
        else
        {
LABEL_278:
          for ( v247[0] = nullptr; v247[0] < (D3DXShader::CInstruction *)v243; ++v247[0] )
          {
            v187 = 4 * (int)v247[0];
            if ( *(&v231 + (int)v247[0]) != 0 )
            {
              v188 = v247[1];
              v189 = (_DWORD *)(*((_DWORD *)v247[1] + 4) + v187);
              v190 = (void *)*v189;
              v191 = *((_DWORD *)this + 5);
              v235[(int)v247[0]] = (void *)*v189;
              if ( *(_DWORD *)(*(_DWORD *)(v191 + 4 * (_DWORD)v190) + 96) == 0 )
              {
                *(_DWORD *)(*(_DWORD *)(v191 + 4 * *v189) + 96) = *(_DWORD *)(*(_DWORD *)(v191
                                                                                        + 4
                                                                                        * *(_DWORD *)(v187 + *((_DWORD *)v188 + 2)))
                                                                            + 96);
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v187 + *((_DWORD *)v188 + 4))) + 100) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v187 + *((_DWORD *)v188 + 2))) + 100);
              }
            }
            else
            {
              v192 = *((void **)ii + (int)v247[0]);
              v193 = *(unsigned int **)(*((_DWORD *)this + 5) + 4 * (_DWORD)v192);
              if ( v230[v193[4]] == 1 )
              {
                v235[(int)v247[0]] = v192;
                v193[4] = v229[v187 / 4];
              }
              else
              {
                v194 = D3DXShader::CBaseProgram::AddArgument(
                         this,
                         a2: v193[1],
                         a3: v193[3],
                         a4: v229[(int)v247[0]],
                         a5: 0.0);
                v235[v187 / 4] = (void *)v194;
                if ( v194 == -1 )
                  goto LABEL_341;
                v195 = 4 * v194;
                D3DXShader::CArgument::Instance(
                  this: *(D3DXShader::CArgument **)(*((_DWORD *)this + 5) + 4 * v194),
                  a2: (struct D3DXShader::CArgument *)v193);
                **(_DWORD **)(v195 + *((_DWORD *)this + 5)) = *v193;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v195) + 24) = v193[6];
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + v195) + 20) = v193[5];
                ++*((_DWORD *)pMem + v193[3]);
                --v230[v193[4]];
              }
            }
          }
          v196 = 0;
          for ( nn = 0; nn < v243; v196 = ++nn )
          {
            v197 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 5) + 4 * *((_DWORD *)ii + v196));
            v31 = *((_DWORD *)v197 + 23) == 0;
            v241 = v197;
            if ( v31 )
            {
              n = nullptr;
              while ( v196 < v243 )
              {
                v198 = *((_DWORD *)ii + v196);
                v199 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v198);
                if ( *((_DWORD *)v197 + 18) == *(_DWORD *)(v199 + 72) )
                {
                  v200 = (D3DXShader::CInstruction *)(4 * (_DWORD)n);
                  n = (D3DXShader::CInstruction *)((char *)n + 1);
                  *(unsigned int *)((char *)&v227[4] + (_DWORD)v200) = v198;
                  *(unsigned int *)((char *)&v227[8] + (_DWORD)v200) = (unsigned int)v235[v196];
                  *(_DWORD *)(v199 + 92) = 1;
                }
                ++v196;
              }
              v201 = *(struct D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v197 + 18));
              v202 = *(_DWORD *)v201 & 0xF0000000;
              if ( v202 < 0x10000000 || v202 > 0x40000000 )
              {
                for ( v247[0] = nullptr; v247[0] < (D3DXShader::CInstruction *)*((_DWORD *)v201 + 3); ++v247[0] )
                {
                  v214 = (_DWORD *)(*((_DWORD *)v201 + 4) + 4 * (int)v247[0]);
                  v215 = 0;
                  while ( *v214 != *((_DWORD *)ii + v215) )
                  {
                    if ( ++v215 >= v243 )
                      goto LABEL_325;
                  }
                  *v214 = v235[v215];
LABEL_325:
                  ;
                }
              }
              else
              {
                v203 = 0;
                v240 = *((_DWORD *)v201 + 1) / (*(_DWORD *)v201 & 0xFFFFFu);
                if ( n != nullptr )
                {
                  v204 = *((D3DXShader::CInstruction **)v201 + 3);
                  do
                  {
                    v247[0] = nullptr;
                    if ( v204 != nullptr )
                    {
                      v205 = v227[v203 + 4];
                      v206 = *((_DWORD **)v201 + 4);
                      while ( *v206 != v205 )
                      {
                        ++v247[0];
                        v204 = *((D3DXShader::CInstruction **)v201 + 3);
                        ++v206;
                        if ( v247[0] >= v204 )
                          goto LABEL_304;
                      }
                      v227[v203] = (unsigned int)v247[0];
                    }
LABEL_304:
                    ++v203;
                  }
                  while ( v203 < (unsigned int)n );
                }
                v207 = D3DXShader::CInstruction::operator new(a1: 0x74u);
                if ( v207 != nullptr )
                  v208 = (D3DXShader::CInstruction *)D3DXShader::CInstruction::CInstruction(this: (D3DXShader::CInstruction *)v207);
                else
                  v208 = nullptr;
                if ( v208 == nullptr )
                  goto LABEL_341;
                i1 = (struct D3DXShader::CInstruction *)D3DXShader::CInstruction::Initialize(
                                                          this: v208,
                                                          a2: *(_DWORD *)v201
                                                        ^ ((unsigned int)n
                                                         ^ *(_DWORD *)v201)
                                                        & 0xFFFFF,
                                                          a3: (_DWORD)n * v240,
                                                          a4: (unsigned int)n,
                                                          a5: 0);
                if ( (int)i1 < 0
                  || (int)(i1 = (struct D3DXShader::CInstruction *)D3DXShader::CInstruction::Instance(
                                                                     this: v208,
                                                                     a2: v201)) < 0 )
                {
                  D3DXShader::CInstruction::`scalar deleting destructor'(this: v208, a2: 1);
                  goto LABEL_178;
                }
                for ( i1 = nullptr; i1 < n; i1 = (struct D3DXShader::CInstruction *)((char *)i1 + 1) )
                {
                  v209 = *((_DWORD *)v208 + 4);
                  v247[0] = nullptr;
                  v210 = (struct D3DXShader::CInstruction *)(4 * (_DWORD)i1);
                  v31 = v240 == 0;
                  *(_DWORD *)(4 * (_DWORD)i1 + v209) = v227[(_DWORD)i1 + 8];
                  if ( !v31 )
                  {
                    v237 = *(_DWORD **)((char *)v227 + (_DWORD)v210);
                    v244 = v210;
                    do
                    {
                      v211 = *(_DWORD *)(*((_DWORD *)v201 + 2)
                                       + 4 * ((_DWORD)v237 + (int)v247[0] * *((_DWORD *)v201 + 3)));
                      v212 = *((_DWORD *)v208 + 2);
                      ++v247[0];
                      *(_DWORD *)((char *)v244 + v212) = v211;
                      v244 = (D3DXShader::CInstruction *)((char *)v244 + 4 * (_DWORD)n);
                    }
                    while ( v247[0] < (D3DXShader::CInstruction *)v240 );
                  }
                }
                v213 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v241 + 18));
                if ( v213 != nullptr )
                  D3DXShader::CInstruction::`scalar deleting destructor'(this: v213, a2: 1);
                *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v241 + 18)) = v208;
              }
            }
          }
          v216 = 0;
          if ( v243 != 0 )
          {
            do
            {
              *((_DWORD *)ii + v216) = v235[v216];
              v217 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *((_DWORD *)ii + v216++));
              v22 = v216 < v243;
              *(_DWORD *)(v217 + 92) = 1;
            }
            while ( v22 );
          }
        }
        Inputs = D3DXShader::CInstruction::GetInputs(this: v247[1], a2: ++v242, a3: (unsigned int **)&ii);
        goto LABEL_330;
      }
      if ( v174[23] != 0 )
        n = (D3DXShader::CInstruction *)1;
      nn = v174[4];
      v31 = v230[nn] == 0;
      v237 = &v230[nn];
      if ( v31 )
        v238 = (_DWORD *)((char *)v238 + 1);
      ++v230[v174[4]];
      v176 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v175);
      v177 = *(_DWORD *)v176;
      v178 = *(_DWORD *)v176 & 0xFFF00000;
      if ( v178 == 544210944 || v178 == 545259520 || v178 == 546308096 )
        goto LABEL_258;
      if ( (v177 & 0xF0000000) >= 0x10000000 && (v177 & 0xF0000000) <= 0x40000000 )
      {
        if ( v174[23] != 0 )
        {
          v237 = *(_DWORD **)((char *)v229 + (_DWORD)v173);
          if ( v237 != (_DWORD *)nn )
          {
            v240 = -1;
            v247[0] = (D3DXShader::CInstruction *)-1;
            jj = nullptr;
            if ( *((_DWORD *)v176 + 3) != 0 )
            {
              v244 = *((D3DXShader::CInstruction **)v176 + 4);
              do
              {
                v179 = *(_DWORD *)v244;
                if ( *(_DWORD *)v241 == *(_DWORD *)v244 )
                  v240 = (unsigned int)jj;
                if ( v237 == *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v179) + 16) )
                  v247[0] = jj;
                jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                v244 = (D3DXShader::CInstruction *)((char *)v244 + 4);
              }
              while ( (unsigned int)jj < *((_DWORD *)v176 + 3) );
              if ( v240 != -1 && v247[0] != (D3DXShader::CInstruction *)-1 )
              {
                v180 = *((_DWORD *)v176 + 1) / (v177 & 0xFFFFFu);
                jj = nullptr;
                nn = v180;
                if ( v180 != 0 )
                {
                  v181 = *((_DWORD *)v176 + 2);
                  v182 = *((_DWORD *)v176 + 3);
                  v244 = (D3DXShader::CInstruction *)(v181 + 4 * v240);
                  v183 = v182;
                  for ( i2 = (_DWORD *)(v181 + 4 * (int)v247[0]); *(_DWORD *)v244 == *i2; i2 = v237 )
                  {
                    jj = (D3DXShader::CInstruction *)((char *)jj + 1);
                    v244 = (D3DXShader::CInstruction *)((char *)v244 + v183 * 4);
                    v237 = &i2[v183];
                    if ( (unsigned int)jj >= nn )
                      break;
                  }
                }
                if ( jj == (D3DXShader::CInstruction *)nn )
                  *(_DWORD *)v241 = *(_DWORD *)(*((_DWORD *)v176 + 4) + 4 * (int)v247[0]);
              }
            }
          }
        }
        if ( D3DXShader::CInstruction::IsScalar(this: v176) != 0 && v230[v174[4]] > 1u )
          n = (D3DXShader::CInstruction *)1;
        goto LABEL_259;
      }
      if ( *((_DWORD *)v176 + 3) > 1u && i1 != (struct D3DXShader::CInstruction *)nn || *v237 > 1u )
LABEL_258:
        n = (D3DXShader::CInstruction *)1;
LABEL_259:
      i1 = (struct D3DXShader::CInstruction *)((char *)i1 + 1);
      if ( (unsigned int)i1 >= v243 )
        goto LABEL_260;
    }
  }
  while ( 1 )
  {
    v27 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v26);
    if ( (*(_WORD *)(v27 + 2) & 0xFFF0) == 0 )
      goto LABEL_38;
    v28 = *(_DWORD *)(v27 + 12);
    if ( v28 == 0 )
      goto LABEL_38;
    v29 = *((_DWORD *)this + 5);
    if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                               + 4 * *(_DWORD *)(*(_DWORD *)(v29 + 4 * **(_DWORD **)(v27 + 16)) + 4))
                   + 4)
        & 0x20) == 0 )
      goto LABEL_38;
    v30 = 0;
    v31 = *(_DWORD *)(v27 + 4) == 0;
    if ( *(_DWORD *)(v27 + 4) != 0 )
    {
      v247[0] = *(D3DXShader::CInstruction **)(v27 + 8);
      do
      {
        if ( v30 != *(_DWORD *)(*(_DWORD *)(v29 + 4 * *(_DWORD *)v247[0]) + 16) )
          break;
        v247[0] = (D3DXShader::CInstruction *)((char *)v247[0] + 4);
        ++v30;
      }
      while ( v30 < *(_DWORD *)(v27 + 4) );
      v31 = v30 == *(_DWORD *)(v27 + 4);
    }
    if ( v31 )
      goto LABEL_38;
    v32 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v28 & 0xFFFFF | 0x10000000, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
    if ( v32 == -1 )
      goto LABEL_341;
    v247[0] = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * v32);
    D3DXShader::CInstruction::Instance(this: v247[0], a2: (struct D3DXShader::CInstruction *)v27);
    v33 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **(_DWORD **)(v27 + 16));
    v34 = *(D3DXShader::CInstruction **)(v33 + 24);
    v35 = *(_DWORD *)(v33 + 20);
    v247[1] = nullptr;
    v31 = *(_DWORD *)(v27 + 12) == 0;
    v241 = v34;
    nn = v35;
    if ( !v31 )
      break;
LABEL_37:
    ++v243;
    jj = (D3DXShader::CInstruction *)1;
LABEL_38:
    v26 = (char *)k + 1;
    k = (unsigned int *)((char *)k + 1);
    if ( (unsigned int)k >= v242 )
      goto LABEL_39;
  }
  while ( 1 )
  {
    v36 = 4 * (int)v247[1];
    v225 = v247[1];
    v223 = v243;
    *(_DWORD *)(4 * (int)v247[1] + *((_DWORD *)v247[0] + 4)) = *(_DWORD *)(4 * (int)v247[1] + *(_DWORD *)(v27 + 16));
    *(_DWORD *)(v36 + *(_DWORD *)(v27 + 16)) = D3DXShader::CBaseProgram::AddArgument(
                                                 this,
                                                 a2: *((_DWORD *)this + 34),
                                                 a3: v223,
                                                 a4: (unsigned int)v225,
                                                 a5: 0.0);
    v37 = v247[0];
    *(_DWORD *)(v36 + *((_DWORD *)v247[0] + 2)) = *(_DWORD *)(v36 + *(_DWORD *)(v27 + 16));
    if ( *(_DWORD *)(v36 + *((_DWORD *)v37 + 2)) == -1 )
      break;
    v38 = v247[0];
    v39 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v36 + *((_DWORD *)v247[0] + 2)));
    ++v247[1];
    *(_DWORD *)(v39 + 24) = v241;
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v36 + *((_DWORD *)v38 + 2))) + 20) = nn;
    **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v36 + *((_DWORD *)v38 + 2))) = **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(v36 + *((_DWORD *)v38 + 4)));
    if ( v247[1] >= (D3DXShader::CInstruction *)*(_DWORD *)(v27 + 12) )
      goto LABEL_37;
  }
LABEL_341:
  i1 = (struct D3DXShader::CInstruction *)-2147024882;
LABEL_178:
  free(pMem);
  return i1;
}

//------------------------------------------------------------------------------
// Address: 0x101EBD01
// Name: protected: long D3DXShader::CProgram::SplitRegisters(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CProgram::SplitRegisters(D3DXShader::CProgram *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // ecx
  D3DXShader::CInstruction *v7; // ebx
  unsigned int v8; // eax
  unsigned int Inputs; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  unsigned int k; // ecx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // ebx
  int v18; // edi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  int v23; // edx
  unsigned int j; // [esp+Ch] [ebp-24h]
  int v26; // [esp+10h] [ebp-20h]
  D3DXShader::CInstruction *v27; // [esp+14h] [ebp-1Ch]
  unsigned int *v28; // [esp+18h] [ebp-18h] BYREF
  unsigned int i; // [esp+1Ch] [ebp-14h]
  unsigned int m; // [esp+20h] [ebp-10h]
  unsigned int v31; // [esp+24h] [ebp-Ch]
  unsigned int v32; // [esp+28h] [ebp-8h]
  unsigned int v33; // [esp+2Ch] [ebp-4h]

  v26 = 0;
  v33 = 0;
  v3 = *((_DWORD *)this + 2);
  if ( v3 != 0 )
  {
    v4 = *((_DWORD *)this + 34);
    v5 = *((_DWORD *)this + 5);
    do
    {
      if ( v4 == *(_DWORD *)(*(_DWORD *)v5 + 4) )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 12);
        if ( v33 <= v6 )
          v33 = v6 + 1;
      }
      v5 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v7 = *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6) + 4 * i);
    v27 = v7;
    if ( (*(_DWORD *)v7 & 0xFFF00000) != 0 )
    {
      v8 = *((_DWORD *)v7 + 1) / (*(_DWORD *)v7 & 0xFFFFFu);
      *((_DWORD *)v7 + 9) = 0;
      m = 0;
      for ( j = v8; m < j; ++m )
      {
        Inputs = D3DXShader::CInstruction::GetInputs(this: v7, a2: m, a3: &v28);
        v10 = *((_DWORD *)this + 5);
        v11 = *((_DWORD *)this + 34);
        v31 = Inputs;
        v12 = *(_DWORD *)(v10 + 4 * *v28);
        if ( v11 == *(_DWORD *)(v12 + 4) )
        {
          v32 = 1;
          if ( v31 > 1 )
          {
            do
            {
              v13 = *(_DWORD *)(v10 + 4 * v28[v32]);
              if ( v11 == *(_DWORD *)(v13 + 4) && *(_DWORD *)(v13 + 72) != *(_DWORD *)(v12 + 72) )
                break;
              ++v32;
            }
            while ( v32 < v31 );
            v7 = v27;
          }
          if ( v32 != v31 )
          {
            for ( k = 0; k < v31; ++k )
            {
              v15 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v28[k]);
              if ( *((_DWORD *)this + 34) == *(_DWORD *)(v15 + 4) )
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v15 + 72)) + 36) = 1;
            }
          }
        }
      }
    }
  }
  for ( m = 0; m < *((_DWORD *)this + 3); ++m )
  {
    v16 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * m);
    if ( (*(_WORD *)(v16 + 2) & 0xFFF0) != 0 && *(_DWORD *)(v16 + 36) == 0 )
    {
      v17 = *(_DWORD **)(v16 + 16);
      v18 = *((_DWORD *)this + 5);
      if ( *((_DWORD *)this + 34) == *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v17) + 4) )
      {
        v19 = *(_DWORD *)(v16 + 12);
        v20 = 0;
        if ( a2 != 0 )
        {
          if ( v19 != 0 )
          {
            v28 = *(unsigned int **)(v16 + 16);
            do
            {
              if ( v20 != *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v28) + 16) )
                break;
              ++v28;
              ++v20;
            }
            while ( v20 < v19 );
          }
          if ( v20 == v19 )
            continue;
          v21 = 0;
          if ( v19 != 0 )
          {
            do
            {
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v21)) + 12) = v33;
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v21)) + 16) = v21;
              ++v21;
            }
            while ( v21 < *(_DWORD *)(v16 + 12) );
          }
        }
        else
        {
          for ( i = 0; i < v19; ++v17 )
          {
            if ( *(_DWORD *)(*(_DWORD *)(v18 + 4 * *v17) + 16) == 0 )
              break;
            ++i;
          }
          if ( i < v19 )
            continue;
          v22 = 0;
          if ( v19 != 0 )
          {
            do
            {
              v23 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *(_DWORD *)(*(_DWORD *)(v16 + 16) + 4 * v22++));
              *(_DWORD *)(v23 + 12) = v33;
            }
            while ( v22 < *(_DWORD *)(v16 + 12) );
          }
        }
        ++v33;
        v26 = 1;
      }
    }
  }
  return v26 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EBF4B
// Name: protected: long D3DXShader::CProgram::ReorderInstructions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::ReorderInstructions(D3DXShader::CProgram *this)
{
  int v1; // edi
  int v3; // esi
  unsigned int i; // eax
  int v5; // ecx
  int v6; // edi
  int *v7; // eax
  int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // edx
  unsigned int v11; // esi
  int v12; // ecx
  bool v13; // zf
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  unsigned int v18; // ecx
  unsigned int j; // eax
  unsigned int v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  unsigned int k; // ecx
  int v25; // eax
  int v26; // edx
  unsigned int v27; // edx
  _DWORD *v28; // eax
  int v29; // ecx
  unsigned int v30; // [esp-4h] [ebp-80h]
  const void *v31; // [esp+0h] [ebp-7Ch]
  _DWORD v32[21]; // [esp+Ch] [ebp-70h] BYREF
  unsigned int v33; // [esp+60h] [ebp-1Ch] BYREF
  int v34; // [esp+64h] [ebp-18h]
  unsigned int v35; // [esp+68h] [ebp-14h]
  void *pMem; // [esp+6Ch] [ebp-10h]
  unsigned int v37; // [esp+70h] [ebp-Ch]
  void *v38; // [esp+74h] [ebp-8h]
  int (__stdcall *v39)(unsigned int, unsigned int, const void *); // [esp+78h] [ebp-4h]

  v1 = 0;
  pMem = nullptr;
  v39 = nullptr;
  v38 = nullptr;
  v3 = D3DXShader::CProgram::CompactInstructions(this);
  if ( v3 < 0 )
    goto LABEL_61;
  v3 = D3DXShader::CProgram::ParentChildInfo(this);
  if ( v3 < 0 )
    goto LABEL_61;
  if ( (*((_DWORD *)this + 27) & 0xC000000) != 0 )
  {
    for ( i = 0; i < *((_DWORD *)this + 3); *(_DWORD *)(v5 + 44) = 0 )
      v5 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * i++);
    v6 = *((_DWORD *)this + 3);
    while ( v6 != 0 )
    {
      --v6;
      v7 = *(int **)(*((_DWORD *)this + 6) + 4 * v6);
      v8 = *v7;
      v9 = *v7 & 0xFFF00000;
      v34 = v6;
      if ( v9 != 0 )
      {
        v10 = v7[11];
        if ( (v8 & 0xF0000000) == 0x60000000 || v9 == 285212672 )
        {
          v7[11] = v10 + 1;
          v10 += 2;
        }
        v11 = 0;
        if ( v7[5] != 0 )
        {
          do
          {
            v12 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v7[6] + 4 * v11));
            if ( *(_DWORD *)(v12 + 44) < v10 )
              *(_DWORD *)(v12 + 44) = v10;
            ++v11;
          }
          while ( v11 < v7[5] );
          v6 = v34;
        }
      }
    }
    v1 = 0;
  }
  v13 = *((_DWORD *)this + 3) == 0;
  v34 = 0;
  v37 = 0;
  if ( !v13 )
  {
    do
    {
      v14 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v37);
      v35 = *(_DWORD *)v14 & 0xFFF00000;
      if ( v35 != 0 )
      {
        v15 = **(_DWORD **)(v14 + 16);
        v16 = *((_DWORD *)this + 5);
        v17 = *((_DWORD *)this + 4);
        v33 = *(_DWORD *)(v16 + 4 * v15);
        if ( (*(_BYTE *)(*(_DWORD *)(v17 + 4 * *(_DWORD *)(v33 + 4)) + 4) & 8) == 0 )
        {
          if ( v35 == 544210944 || v35 == 545259520 || v35 == 290455552 )
            v18 = *(_DWORD *)(v16 + 4 * **(_DWORD **)(v14 + 8));
          else
            v18 = v33;
          v15 = *(_DWORD *)(v18 + 20);
        }
        v1 = 0;
        *(_DWORD *)(v14 + 52) = v15;
        if ( v15 != -1 )
          v34 = 1;
      }
      ++v37;
    }
    while ( v37 < *((_DWORD *)this + 3) );
  }
  if ( (*((_BYTE *)this + 204) & 4) != 0 )
    return 1;
  v30 = 4 * *((_DWORD *)this + 3);
  if ( v34 != 0 )
  {
    v39 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: v30);
    if ( v39 != nullptr )
    {
      v38 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
      if ( v38 != nullptr )
      {
        v3 = D3DXShader::CProgram::ReadWriteInfo(this);
        if ( v3 < 0 )
          goto LABEL_61;
        for ( j = 0; j < *((_DWORD *)this + 3); ++j )
          *((_DWORD *)v39 + j) = j;
        D3DXShader::HeapSort(
          this: (D3DXShader *)sub_101E16D3,
          a2: v39,
          a3: *((unsigned int **)this + 3),
          a4: (unsigned int)this,
          a5: v31);
        v21 = 0;
        if ( *((_DWORD *)this + 3) != 0 )
        {
          v22 = v38;
          v23 = (char *)v39 - (char *)v38;
          do
          {
            *v22 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)((char *)v22 + v23));
            ++v21;
            ++v22;
          }
          while ( v21 < *((_DWORD *)this + 3) );
        }
        qmemcpy(*((void **)this + 6), v38, 4 * *((_DWORD *)this + 3));
        v3 = D3DXShader::CProgram::ParentChildInfo(this);
        if ( v3 < 0 )
          goto LABEL_61;
        v32[1] = this;
        v32[0] = &D3DXShader::CTReorderInstructions::`vftable';
        v3 = D3DXShader::CTReorderInstructions::Apply(this: (D3DXShader::CTReorderInstructions *)v32, a2: 1);
        if ( v3 < 0 )
          goto LABEL_61;
        goto LABEL_59;
      }
    }
LABEL_60:
    v3 = -2147024882;
    goto LABEL_61;
  }
  v37 = 0;
  pMem = MemAlloc_Alloc(nSize: v30);
  if ( pMem == nullptr )
    goto LABEL_60;
  v39 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
  if ( v39 == nullptr )
    goto LABEL_60;
  v38 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)this + 3));
  if ( v38 == nullptr )
    goto LABEL_60;
  for ( k = 0; k < *((_DWORD *)this + 3); ++k )
  {
    v25 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * k);
    *(_DWORD *)(v25 + 56) = -1;
    v13 = (*(_WORD *)(v25 + 2) & 0xFFF0) == 0;
    *(_DWORD *)(v25 + 36) = 0;
    if ( !v13 && *(_DWORD *)(v25 + 28) == 0 )
    {
      v26 = v37++;
      *((_DWORD *)pMem + v26) = k;
    }
  }
  v33 = 0;
  if ( v37 != 0 )
  {
    do
    {
      v3 = D3DXShader::CProgram::ReorderInstructions(
             this,
             a2: *((_DWORD *)pMem + v1),
             a3: (unsigned int *)v39,
             a4: &v33);
      if ( v3 < 0 )
        goto LABEL_61;
    }
    while ( ++v1 < v37 );
  }
  v27 = 0;
  if ( *((_DWORD *)this + 3) != 0 )
  {
    v28 = v38;
    v29 = (char *)v39 - (char *)v38;
    do
    {
      *v28 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)((char *)v28 + v29));
      ++v27;
      ++v28;
    }
    while ( v27 < *((_DWORD *)this + 3) );
  }
  qmemcpy(*((void **)this + 6), v38, 4 * *((_DWORD *)this + 3));
LABEL_59:
  v3 = 0;
LABEL_61:
  free(pMem);
  free(pMem: v39);
  free(pMem: v38);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101EC287
// Name: protected: long D3DXShader::CProgram::SwizzleRegisters(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::SwizzleRegisters(D3DXShader::CProgram *this)
{
  int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  int *v17; // ecx
  int v18; // edx
  unsigned int v20[4]; // [esp+4h] [ebp-30h] BYREF
  int v21; // [esp+14h] [ebp-20h]
  int k; // [esp+18h] [ebp-1Ch]
  unsigned int v23; // [esp+1Ch] [ebp-18h]
  unsigned int v24; // [esp+20h] [ebp-14h]
  _DWORD *v25; // [esp+24h] [ebp-10h]
  _DWORD *v26; // [esp+28h] [ebp-Ch]
  unsigned int i; // [esp+2Ch] [ebp-8h]
  unsigned int j; // [esp+30h] [ebp-4h]

  D3DXShader::CProgram::ReadWriteInfo(this);
  for ( i = 0; i < *((_DWORD *)this + 3); ++i )
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * i);
    v3 = *(_DWORD *)v2;
    j = *(_DWORD *)v2;
    j &= 0xFFF00000;
    if ( j == 0 )
      continue;
    v4 = v3 & 0xFFFFF;
    v23 = *(_DWORD *)(v2 + 4) / (v3 & 0xFFFFF);
    if ( j == 1342177280 )
    {
      D3DXShader::CProgram::SwizzleParameter(
        this,
        a2: (unsigned int *)(*(_DWORD *)(v2 + 8) + 4 * v4),
        a3: v20,
        a4: v3 & 0xFFFFF,
        a5: 1);
      D3DXShader::CProgram::SwizzleParameter(this, a2: *(unsigned int **)(v2 + 8), a3: v20, a4: v4, a5: 0);
    }
    else
    {
      v5 = v3 & 0xF0000000;
      if ( v5 >= 0x10000000 && v5 <= 0x40000000 )
      {
        D3DXShader::CProgram::SwizzleParameter(this, a2: *(unsigned int **)(v2 + 16), a3: v20, a4: v4, a5: 1);
        for ( j = 0; j < v23; ++j )
          D3DXShader::CProgram::SwizzleParameter(
            this,
            a2: (unsigned int *)(*(_DWORD *)(v2 + 8) + 4 * j * *(_DWORD *)(v2 + 12)),
            a3: v20,
            a4: v4,
            a5: 0);
      }
    }
    if ( (*(_DWORD *)v2 & 0xF0000000) != 0x20000000
      || D3DXShader::CInstruction::IsSymetric(this: (D3DXShader::CInstruction *)v2) == 0 )
    {
      continue;
    }
    v6 = *(_DWORD **)(v2 + 8);
    v7 = *((_DWORD *)this + 5);
    v8 = *(_DWORD *)(v7 + 4 * *v6);
    v9 = *(_DWORD *)(v7 + 4 * v6[v4]);
    v24 = -1;
    j = -1;
    v21 = v8;
    v23 = v9;
    if ( v4 != 0 )
    {
      v26 = *(_DWORD **)(v2 + 8);
      v25 = &v26[v4];
      for ( k = v4; k != 0; --k )
      {
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v26) + 72) < v24 )
          v24 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v26) + 72);
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v25) + 72) < j )
          j = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v25) + 72);
        ++v26;
        ++v25;
      }
      if ( v24 < j )
        continue;
      if ( v24 != j )
        goto LABEL_25;
    }
    v10 = *(_DWORD *)(v23 + 4);
    v11 = *((_DWORD *)this + 4);
    k = 4 * *(_DWORD *)(v21 + 4);
    v12 = 4 * v10;
    if ( *(_DWORD *)(*(_DWORD *)(k + v11) + 4) >= *(_DWORD *)(*(_DWORD *)(v11 + v12) + 4) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + k) + 4) != *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + v12)
                                                                                + 4)
        || (v13 = *(_DWORD *)(v23 + 4), (v14 = *(_DWORD *)(v21 + 4)) >= v13)
        && (v14 != v13 || *(_DWORD *)(v21 + 12) >= *(_DWORD *)(v23 + 12)) )
      {
LABEL_25:
        j = 0;
        if ( v4 != 0 )
        {
          v21 = 4 * v4;
          do
          {
            v15 = *(_DWORD *)(v2 + 8);
            v16 = j++;
            v17 = (int *)(v15 + 4 * v16);
            k = *v17;
            v18 = v21;
            *v17 = *(_DWORD *)(v21 + v15);
            *(_DWORD *)(v18 + *(_DWORD *)(v2 + 8)) = k;
            v21 = v18 + 4;
          }
          while ( j < v4 );
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EC49F
// Name: private: int D3DXShader::CProgram::CanVectorize(unsigned int __near *,unsigned int,unsigned int __near *,unsigned int __near *,class D3DXShader::CInstruction __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CanVectorize(
        D3DXShader::CProgram *this,
        unsigned int *a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int *a5,
        struct D3DXShader::CInstruction *a6,
        __int64 a7)
{
  unsigned int i; // esi
  unsigned int v10; // eax
  unsigned int *v11; // esi
  unsigned int j; // edi
  unsigned int CanVectorize_TraceMulAdd; // ecx
  unsigned int v14; // edi
  int v15; // eax
  int v16; // eax
  bool v17; // zf
  double v18; // st7
  int v19; // eax
  int v20; // eax
  int v21; // esi
  unsigned int v22; // ecx
  int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edi
  unsigned int v26; // esi
  int v27; // eax
  int v28; // eax
  double v29; // st7
  int v30; // eax
  unsigned int *v31; // edi
  unsigned int v32; // eax
  unsigned int v33; // esi
  int v34; // eax
  unsigned int v35; // esi
  int v36; // edi
  unsigned int v37; // eax
  int v38; // edx
  unsigned int v39; // ecx
  int v40; // esi
  int v41; // eax
  _DWORD *v42; // edi
  unsigned int v43; // eax
  unsigned int v44; // esi
  int v45; // ecx
  int v46; // edx
  unsigned int kk; // edi
  int v48; // eax
  unsigned int v49; // eax
  int v50; // edx
  _DWORD *v51; // eax
  int v52; // ecx
  _DWORD *v53; // edi
  unsigned int v54; // eax
  unsigned int v55; // edx
  int v56; // eax
  _DWORD *v57; // ecx
  unsigned int *v58; // eax
  unsigned int nn; // ecx
  int v60; // eax
  unsigned int v61; // eax
  unsigned int v62; // eax
  unsigned int v63; // esi
  int v64; // edi
  int v65; // ecx
  unsigned int i2; // edi
  _DWORD *v67; // esi
  int v68; // eax
  unsigned int i3; // edx
  _DWORD *v70; // eax
  unsigned int *v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // eax
  unsigned int *v74; // edi
  unsigned int v75; // esi
  int v76; // eax
  unsigned int *v77; // eax
  int v78; // edx
  double v79; // st7
  double *v80; // eax
  unsigned int v81; // esi
  unsigned int v82; // edi
  double *v83; // ecx
  unsigned int v84; // eax
  unsigned int v85; // esi
  D3DXShader::CInstruction *v86; // edi
  unsigned int v87; // esi
  D3DXShader::CInstruction *v88; // edi
  unsigned int v89; // eax
  int v90; // esi
  unsigned int v91; // edi
  unsigned int v92; // eax
  unsigned int v93; // edi
  int v94; // ecx
  unsigned int v95; // eax
  unsigned int v96; // ecx
  unsigned int v97; // edx
  unsigned int v98; // ecx
  unsigned int *v99; // ecx
  unsigned int v100; // edi
  int *v101; // eax
  unsigned int v102; // ecx
  bool v103; // zf
  int *v104; // edx
  int v105; // eax
  unsigned int v106; // eax
  unsigned int v107; // edx
  unsigned int *v108; // ecx
  unsigned int v109; // edi
  _DWORD *v110; // eax
  unsigned int *v111; // edx
  unsigned int *v112; // ecx
  unsigned int *v113; // eax
  unsigned int i4; // edx
  int v115; // eax
  unsigned int v116; // [esp-4h] [ebp-E4h]
  unsigned int v117; // [esp-4h] [ebp-E4h]
  unsigned int v118; // [esp+4h] [ebp-DCh]
  unsigned int v119[20]; // [esp+14h] [ebp-CCh] BYREF
  unsigned int v120[2]; // [esp+64h] [ebp-7Ch]
  double v121; // [esp+6Ch] [ebp-74h]
  unsigned int v122; // [esp+74h] [ebp-6Ch]
  _DWORD v123[4]; // [esp+78h] [ebp-68h] BYREF
  unsigned int *v124; // [esp+88h] [ebp-58h]
  _DWORD *v125; // [esp+8Ch] [ebp-54h]
  double n; // [esp+90h] [ebp-50h] BYREF
  double jj; // [esp+98h] [ebp-48h] BYREF
  unsigned int *v128; // [esp+A0h] [ebp-40h]
  unsigned int v129[4]; // [esp+A4h] [ebp-3Ch] BYREF
  unsigned int v130; // [esp+B4h] [ebp-2Ch]
  unsigned int ii; // [esp+B8h] [ebp-28h]
  unsigned int v132; // [esp+BCh] [ebp-24h]
  unsigned int v133; // [esp+C0h] [ebp-20h]
  int v134; // [esp+C4h] [ebp-1Ch]
  unsigned int v135; // [esp+C8h] [ebp-18h]
  unsigned int v136; // [esp+CCh] [ebp-14h]
  unsigned int v137; // [esp+D0h] [ebp-10h]
  unsigned int m; // [esp+D4h] [ebp-Ch]
  unsigned int k; // [esp+D8h] [ebp-8h]
  unsigned int v140; // [esp+DCh] [ebp-4h]
  int v141; // [esp+FCh] [ebp+1Ch]
  __int64 v142; // [esp+FCh] [ebp+1Ch]
  int v143; // [esp+FCh] [ebp+1Ch]
  unsigned int i1; // [esp+FCh] [ebp+1Ch]
  __int64 v145; // [esp+FCh] [ebp+1Ch]
  int v146; // [esp+FCh] [ebp+1Ch]
  unsigned int mm; // [esp+100h] [ebp+20h]
  unsigned int *v148; // [esp+100h] [ebp+20h]
  int v149; // [esp+100h] [ebp+20h]
  unsigned int *v150; // [esp+100h] [ebp+20h]
  unsigned int *v151; // [esp+100h] [ebp+20h]
  _DWORD *v152; // [esp+100h] [ebp+20h]

  if ( a3 == 0 )
    return 1;
  if ( a3 > 4 )
    return 0;
  for ( i = 1; i < a3; ++i )
  {
    if ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: *a2, a3: a2[i]) == 0 )
      break;
  }
  if ( i == a3 )
    return 1;
  qmemcpy(v129, a2, 4 * ((4 * a3) >> 2));
  v130 = 4 * a3;
  memset(v123, 0, 4 * ((4 * a3) >> 2));
  if ( a4 == nullptr || (v10 = *(_DWORD *)a6 & 0xFFF00000, v134 = 0, v10 == 287309824) )
    v134 = 1;
  m = 0;
  v140 = 0;
  v11 = v129;
  v135 = (unsigned int)v129;
  do
  {
    for ( j = *v11; ; j = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v133) + 52) )
    {
      v133 = j;
      if ( D3DXShader::CProgram::CanVectorize_CanRead(this, a2: j, a3: a6, a4: a7, a5: HIDWORD(a7)) != 0 )
      {
        n = 1.0;
        CanVectorize_TraceMulAdd = j;
        jj = 0.0;
        if ( j != -1 )
        {
          v14 = *((_DWORD *)this + 5);
          while ( 1 )
          {
            v15 = *(_DWORD *)(v14 + 4 * CanVectorize_TraceMulAdd);
            if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v15 + 4)) + 4) & 0x100) != 0
              && *(_DWORD *)(v15 + 8) == -1 )
            {
              break;
            }
            CanVectorize_TraceMulAdd = D3DXShader::CProgram::CanVectorize_TraceMulAdd(
                                         this,
                                         a2: CanVectorize_TraceMulAdd,
                                         a3: &n,
                                         a4: &jj);
            if ( CanVectorize_TraceMulAdd == -1 )
            {
              v11 = (unsigned int *)v135;
              goto LABEL_34;
            }
          }
          if ( 1.0 != n || 0.0 != jj )
          {
            v16 = *(_DWORD *)(v14 + 4 * CanVectorize_TraceMulAdd);
            CanVectorize_TraceMulAdd = 0;
            v17 = *((_DWORD *)this + 2) == 0;
            v18 = n * *(double *)(v16 + 32) + jj;
            if ( *((_DWORD *)this + 2) != 0 )
            {
              v137 = v14;
              do
              {
                v19 = *(_DWORD *)v137;
                if ( (*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(*(_DWORD *)v137 + 4)) + 4) & 0x100) != 0
                  && *(_DWORD *)(v19 + 8) == -1
                  && v18 == *(double *)(v19 + 32) )
                {
                  break;
                }
                v137 += 4;
                ++CanVectorize_TraceMulAdd;
              }
              while ( CanVectorize_TraceMulAdd < *((_DWORD *)this + 2) );
              v17 = CanVectorize_TraceMulAdd == *((_DWORD *)this + 2);
            }
            if ( v17 )
            {
              CanVectorize_TraceMulAdd = D3DXShader::CBaseProgram::AddArgument(
                                           this,
                                           a2: *((_DWORD *)this + 30),
                                           a3: 0,
                                           a4: 0,
                                           a5: v18);
              if ( CanVectorize_TraceMulAdd == -1 )
                return 0;
            }
          }
          v11 = (unsigned int *)v135;
          v20 = 2 * v140;
          ++m;
          *(double *)&v119[v20 + 4] = 1.0;
          *(double *)&v119[v20 + 12] = 0.0;
          *v11 = CanVectorize_TraceMulAdd;
          if ( CanVectorize_TraceMulAdd != -1 )
            break;
        }
      }
LABEL_34:
      if ( *v11 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v133) + 52) )
        break;
    }
    ++v140;
    v135 = (unsigned int)++v11;
  }
  while ( v140 < a3 );
  if ( m != a3 )
  {
    for ( k = 0; k < a3; ++k )
    {
      v17 = v123[k] == 0;
      v125 = &v123[k];
      if ( v17 )
      {
        v21 = *((_DWORD *)this + 4);
        v22 = v129[k];
        v124 = &v129[k];
        v23 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v22);
        if ( (*(_BYTE *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4)) + 5) & 1) == 0 || *(_DWORD *)(v23 + 8) != -1 )
        {
          v136 = -1;
          v135 = 0;
          v133 = 0;
          for ( m = v22; ; m = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * m) + 52) )
          {
            if ( D3DXShader::CProgram::CanVectorize_CanRead(this, a2: m, a3: a6, a4: a7, a5: HIDWORD(a7)) != 0 )
            {
              v24 = m;
              jj = 1.0;
              for ( n = 0.0; ; v24 = D3DXShader::CProgram::CanVectorize_TraceMulAdd(this, a2: v132, a3: &jj, a4: &n) )
              {
                v132 = v24;
                if ( v24 == -1 )
                  break;
                v17 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v132) + 72) == -1;
                v137 = 0;
                v140 = 0;
                if ( v17 )
                  v140 = -1;
                for ( ii = 0; ii < a3; ++ii )
                {
                  if ( v123[ii] == 0 )
                  {
                    v25 = v129[ii];
                    v128 = (unsigned int *)v25;
                    while ( v25 != -1 )
                    {
                      if ( D3DXShader::CProgram::CanVectorize_CanRead(this, a2: v25, a3: a6, a4: a7, a5: HIDWORD(a7)) != 0 )
                      {
                        v26 = v25;
                        while ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v132, a3: v26) == 0 )
                        {
                          if ( v134 != 0 )
                          {
                            v26 = -1;
                            goto LABEL_59;
                          }
                          v26 = D3DXShader::CProgram::CanVectorize_TraceMulAdd(this, a2: v26, a3: nullptr, a4: nullptr);
                          if ( v26 == -1 )
                            goto LABEL_60;
                        }
                        v27 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v26);
                        ++v137;
                        if ( *(_DWORD *)(v27 + 72) != -1 )
                        {
                          v28 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v26) + 72) - a7;
                          v140 += v28 * v28;
                        }
LABEL_59:
                        if ( v26 != -1 )
                          break;
                      }
LABEL_60:
                      if ( v128 == *(unsigned int **)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v25) + 52) )
                        break;
                      v25 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v25) + 52);
                    }
                  }
                }
                if ( v135 < v137 || v135 == v137 && v133 < v140 )
                {
                  v121 = jj;
                  v135 = v137;
                  *(double *)v120 = n;
                  v136 = v132;
                  v133 = v140;
                }
                if ( v134 != 0 )
                  break;
              }
            }
            if ( *v124 == *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * m) + 52) )
              break;
          }
          if ( v136 == -1 )
            return 0;
          v29 = v121;
          *v124 = v136;
          v30 = 2 * k;
          v140 = 0;
          *(double *)&v119[v30 + 4] = v29;
          *(double *)&v119[v30 + 12] = *(double *)v120;
          *v125 = 1;
          do
          {
            v17 = v123[v140] == 0;
            v128 = &v123[v140];
            if ( v17 )
            {
              v31 = &v129[v140];
              v32 = *v31;
              do
              {
                m = v32;
                if ( v32 == -1 )
                  break;
                if ( D3DXShader::CProgram::CanVectorize_CanRead(this, a2: m, a3: a6, a4: a7, a5: HIDWORD(a7)) != 0 )
                {
                  v33 = m;
                  n = 1.0;
                  for ( jj = 0.0; ; v33 = D3DXShader::CProgram::CanVectorize_TraceMulAdd(this, a2: v33, a3: &n, a4: &jj) )
                  {
                    if ( v33 == -1 )
                      goto LABEL_87;
                    if ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v136, a3: v33) != 0 )
                      break;
                    if ( v134 != 0 )
                    {
                      v33 = -1;
LABEL_86:
                      if ( v33 != -1 )
                        goto LABEL_89;
                      goto LABEL_87;
                    }
                  }
                  v34 = 2 * v140;
                  *(double *)&v119[v34 + 4] = n;
                  *v31 = v33;
                  *(double *)&v119[v34 + 12] = jj;
                  *v128 = 1;
                  goto LABEL_86;
                }
LABEL_87:
                v32 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * m) + 52);
              }
              while ( *v31 != v32 );
            }
LABEL_89:
            ++v140;
          }
          while ( v140 < a3 );
        }
      }
    }
    v35 = 0;
    v141 = 0;
    v137 = 0;
    v135 = 0;
    ii = 0;
    do
    {
      v36 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[v35]);
      if ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v129[v35], a3: v129[0]) == 0 )
        v141 = 1;
      if ( 1.0 != *(double *)&v119[2 * v35 + 4] )
        v137 = 1;
      if ( 0.0 != *(double *)&v119[2 * v35 + 12] )
        v135 = 1;
      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v36 + 4)) + 5) & 1) != 0
        && *(_DWORD *)(v36 + 8) == -1 )
      {
        ii = 1;
      }
      ++v35;
    }
    while ( v35 < a3 );
    if ( v137 != 0 || v135 != 0 || v141 != 0 )
    {
      if ( v134 != 0 )
        return 0;
      v37 = (int)(*((_DWORD *)this + 27) << 29) >> 31;
      k = 0;
      m = v37;
      v142 = 0;
      do
      {
        v38 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[k]);
        v39 = 0;
        if ( m != 0 || (*((_BYTE *)this + 108) & 2) != 0 )
        {
          v39 = k;
        }
        else
        {
          v40 = *(_DWORD *)(v38 + 4);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v40) + 5) & 1) != 0 && *(_DWORD *)(v38 + 8) == -1 )
          {
            if ( (_DWORD)v142 != 0 )
            {
              do
              {
                v41 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[v39]);
                if ( v40 == *(_DWORD *)(v41 + 4)
                  && *(_DWORD *)(v41 + 8) == -1
                  && *(double *)(v38 + 32) == *(double *)(v41 + 32) )
                {
                  break;
                }
                ++v39;
              }
              while ( v39 < k );
            }
          }
          else if ( (_DWORD)v142 != 0 )
          {
            do
            {
              v42 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v129[v39]);
              if ( *(double *)((char *)&v119[4] + v142) == *(double *)&v119[2 * v39 + 4]
                && *(double *)((char *)&v119[12] + v142) == *(double *)&v119[2 * v39 + 12]
                && v40 == v42[1]
                && *(_DWORD *)(v38 + 8) == v42[2]
                && *(_DWORD *)(v38 + 12) == v42[3]
                && *(_DWORD *)(v38 + 16) == v42[4] )
              {
                break;
              }
              ++v39;
            }
            while ( v39 < k );
          }
        }
        v43 = k;
        v17 = k == v39;
        v119[k] = v39;
        if ( v17 )
          ++HIDWORD(v142);
        LODWORD(v142) = v142 + 8;
        k = v43 + 1;
      }
      while ( v43 + 1 < a3 );
      v133 = -1;
      v44 = 0;
      v143 = 1;
      v140 = 0;
      k = 0;
      do
      {
        if ( v44 == v119[v44] )
        {
          v45 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[v44]);
          v46 = *((_DWORD *)this + 34);
          if ( v46 == *(_DWORD *)(v45 + 4) )
          {
            v136 = HIDWORD(v142);
            for ( kk = 0; kk < a3; ++kk )
            {
              if ( kk == v119[kk] )
              {
                v48 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[kk]);
                if ( v46 == *(_DWORD *)(v48 + 4)
                  && *(_DWORD *)(v45 + 12) == *(_DWORD *)(v48 + 12)
                  && 1.0 == *(double *)&v119[2 * kk + 4]
                  && 0.0 == *(double *)&v119[2 * kk + 12] )
                {
                  --v136;
                }
                v44 = k;
              }
            }
            if ( v136 + a4[*(_DWORD *)(v45 + 12)] <= 4 && v136 < v133 )
            {
              v143 = 0;
              v133 = v136;
              v140 = v44;
            }
          }
        }
        k = ++v44;
      }
      while ( v44 < a3 );
      if ( m != 0 || (*((_BYTE *)this + 108) & 2) != 0 )
      {
        v49 = *(_DWORD *)a6 & 0xF0000000;
        if ( v49 >= 0x10000000 && v49 <= 0x40000000 )
        {
          for ( m = 0; m < a3; ++m )
          {
            if ( v143 != 0 )
              break;
            v50 = *((_DWORD *)this + 5);
            v51 = *(_DWORD **)(v50 + 4 * v129[m]);
            v52 = v51[1];
            if ( ((*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v52) + 5) & 1) == 0 || v51[2] == -1)
              && v51[4] != *(_DWORD *)(*(_DWORD *)(v50 + 4 * *(_DWORD *)(4 * m + *((_DWORD *)a6 + 4))) + 16) )
            {
              v136 = 0;
              for ( mm = 0; mm < a3; ++mm )
              {
                v53 = *(_DWORD **)(v50 + 4 * v129[mm]);
                if ( v53[1] == v52 && v53[3] == v51[3] && v53[2] == v51[2] )
                  ++v136;
              }
              if ( v136 > 1 )
                v143 = 1;
            }
          }
        }
      }
      v54 = *(_DWORD *)a6 & 0xFFF00000;
      if ( (v54 != 0x10000000
         || (*((_BYTE *)this + 108) & 8) != 0
         || (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                  + 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a6 + 4)) + 4))
                      + 4)
           & 0x20) == 0)
        && v54 == 0x10000000
        && v137 == 0
        && v135 == 0
        && ii == 0 )
      {
        qmemcpy(a2, v129, v130);
        return 0;
      }
      v122 = -1;
      if ( v143 != 0 )
        v55 = (*a5)++;
      else
        v55 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[v140]) + 12);
      v56 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * **((_DWORD **)a6 + 4));
      v57 = *(_DWORD **)(v56 + 20);
      v58 = *(unsigned int **)(v56 + 24);
      v125 = v57;
      v124 = v58;
      memset(v123, 0, v130);
      v135 = v55;
      for ( nn = 0; nn < a3; ++nn )
      {
        if ( nn == v119[nn] )
        {
          v60 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[nn]);
          if ( *((_DWORD *)this + 34) != *(_DWORD *)(v60 + 4)
            || v55 != *(_DWORD *)(v60 + 12)
            || 1.0 != *(double *)&v119[2 * nn + 4]
            || 0.0 != *(double *)&v119[2 * nn + 12] )
          {
            continue;
          }
        }
        v123[nn] = 1;
      }
      if ( v143 == 0 )
      {
        v61 = 0;
        for ( k = 0; k < a3; ++k )
        {
          v62 = v61;
          if ( v123[v62] == 0 )
          {
            v63 = v129[v62];
            v64 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v63);
            if ( *((_DWORD *)this + 34) == *(_DWORD *)(v64 + 4) )
            {
              v137 = 0;
              v136 = 0;
              for ( i1 = 0; i1 < a3; ++i1 )
              {
                if ( v123[i1] == 0 )
                {
                  v118 = v129[i1];
                  ++v137;
                  if ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v63, a3: v118) != 0 )
                  {
                    ++v136;
                    if ( 1.0 != *(double *)&v119[2 * i1 + 4] || 0.0 != *(double *)&v119[2 * i1 + 12] )
                      break;
                  }
                }
              }
              if ( i1 >= a3 )
              {
                v65 = *(_DWORD *)(v64 + 12);
                v148 = &a4[v135];
                if ( v137 + *v148 + a4[v65] - v136 <= 4 )
                {
                  for ( i2 = 0; i2 < a3; ++i2 )
                  {
                    v67 = &v123[i2];
                    if ( *v67 == 0 )
                    {
                      v68 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v129[i2]);
                      if ( *((_DWORD *)this + 34) == *(_DWORD *)(v68 + 4) && v65 == *(_DWORD *)(v68 + 12) )
                        *v67 = 1;
                    }
                  }
                  for ( i3 = 0; i3 < *((_DWORD *)this + 2); ++i3 )
                  {
                    v70 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * i3);
                    if ( *((_DWORD *)this + 34) == v70[1] && v65 == v70[3] )
                    {
                      v70[3] = v135;
                      v70[4] += *v148;
                    }
                  }
                  v71 = &a4[v65];
                  *v148 += *v71;
                  *v71 = 0;
                }
              }
            }
          }
          v61 = k + 1;
        }
      }
      if ( (*((_BYTE *)this + 108) & 6) == 0 )
      {
        v72 = 0;
        for ( k = 0; k < a3; ++k )
        {
          v73 = v72;
          if ( v123[v73] == 0 )
          {
            v74 = &v129[v73];
            v75 = v129[v73];
            v76 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v75);
            if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v76 + 4)) + 5) & 1) == 0
              || *(_DWORD *)(v76 + 8) != -1 )
            {
              v145 = 0;
              do
              {
                if ( v123[HIDWORD(v145)] == 0
                  && D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v75, a3: v129[HIDWORD(v145)]) != 0 )
                {
                  LODWORD(v145) = v145 + 1;
                }
                ++HIDWORD(v145);
              }
              while ( HIDWORD(v145) < a3 );
              HIDWORD(v145) = 0;
              do
              {
                if ( (unsigned int)v145 >= 4 )
                  break;
                if ( v123[HIDWORD(v145)] == 0 )
                {
                  v77 = &v129[HIDWORD(v145)];
                  v78 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v77);
                  if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * *(_DWORD *)(v78 + 4)) + 5) & 1) != 0
                    && *(_DWORD *)(v78 + 8) == -1 )
                  {
                    v79 = *(double *)(v78 + 32);
                    *v77 = *v74;
                    LODWORD(v145) = v145 + 1;
                    v80 = (double *)&v119[2 * HIDWORD(v145) + 4];
                    *(double *)&v119[2 * HIDWORD(v145) + 12] = v79 * *v80 + *(double *)&v119[2 * HIDWORD(v145) + 12];
                    *v80 = 0.0;
                  }
                }
                ++HIDWORD(v145);
              }
              while ( HIDWORD(v145) < a3 );
            }
          }
          v72 = k + 1;
        }
      }
      for ( k = 0; k < a3; ++k )
      {
        v81 = 0;
        if ( v123[k] == 0 )
        {
          v82 = v129[k];
          v120[1] = v82;
          v149 = 0;
          v132 = 0;
          v136 = 1;
          v134 = 0;
          v130 = 1;
          do
          {
            if ( v123[v81] == 0 && D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v82, a3: v129[v81]) != 0 )
            {
              ++v149;
              v83 = (double *)&v119[2 * v81 + 4];
              if ( 1.0 != *v83 )
                v132 = 1;
              if ( -1.0 != *v83 )
                v136 = 0;
              if ( 0.0 != *(double *)&v119[2 * v81 + 12] )
                v134 = 1;
              if ( 0.0 != *v83 )
                v130 = 0;
            }
            ++v81;
          }
          while ( v81 < a3 );
          if ( v130 != 0 )
          {
            v132 = 0;
            v134 = 0;
          }
          if ( v132 != 0 )
          {
            if ( v136 != 0 )
              v84 = (unsigned int)&loc_10100000 | v149 & 0xFFFFF;
            else
              v84 = v149 & 0xFFFFF | 0x20500000;
            v85 = D3DXShader::CBaseProgram::AddInstruction(this, a2: v84, a3: 0xFFFFFFFF, a4: 0xFFFFFFFF);
            m = v85;
            if ( v85 == -1 )
              return 0;
            ii = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v85);
            v86 = (D3DXShader::CInstruction *)ii;
            D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)ii, a2: a6);
            if ( v134 != 0 )
            {
LABEL_252:
              v87 = D3DXShader::CBaseProgram::AddInstruction(
                      this,
                      a2: v149 & 0xFFFFF | 0x20400000,
                      a3: 0xFFFFFFFF,
                      a4: 0xFFFFFFFF);
              v133 = v87;
              if ( v87 == -1 )
                return 0;
              v140 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v87);
              v88 = (D3DXShader::CInstruction *)v140;
              D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v140, a2: a6);
              if ( v132 != 0 )
              {
LABEL_259:
                v137 = 4 * v149;
                v90 = 0;
                v146 = 0;
                HIDWORD(jj) = (char *)a2 - (char *)v129;
                while ( 1 )
                {
                  v17 = v123[v146] == 0;
                  HIDWORD(n) = &v123[v146];
                  if ( v17 )
                  {
                    v91 = v129[v146];
                    v128 = &v129[v146];
                    if ( D3DXShader::CProgram::CanVectorize_IsSameRegister(this, a2: v120[1], a3: v91) != 0 )
                      break;
                  }
LABEL_294:
                  if ( ++v146 >= a3 )
                    goto LABEL_295;
                }
                if ( v130 != 0 )
                  v92 = D3DXShader::CBaseProgram::AddArgument(
                          this,
                          a2: *((_DWORD *)this + 30),
                          a3: 0,
                          a4: 0,
                          a5: *(double *)&v119[2 * v146 + 12]);
                else
                  v92 = v91;
                if ( v92 == -1 )
                  return 0;
                v93 = ii;
                v94 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v92);
                *(_DWORD *)(v90 + *(_DWORD *)(ii + 8)) = v92;
                HIDWORD(v121) = v94;
                if ( v130 != 0 )
                  *(_DWORD *)(v94 + 52) = v92;
                if ( v132 != 0 )
                {
                  if ( v136 == 0 )
                  {
                    v95 = D3DXShader::CBaseProgram::AddArgument(
                            this,
                            a2: *((_DWORD *)this + 30),
                            a3: 0,
                            a4: 0,
                            a5: *(double *)&v119[2 * v146 + 4]);
                    v96 = v137;
                    *(_DWORD *)(v137 + *(_DWORD *)(v93 + 8)) = v95;
                    if ( *(_DWORD *)(v96 + *(_DWORD *)(v93 + 8)) == -1 )
                      return 0;
                  }
                  if ( v134 == 0 )
                    goto LABEL_290;
                  v97 = v122;
                  if ( v122 == -1 )
                  {
                    v97 = *a5;
                    v98 = *a5 + 1;
                    v122 = *a5;
                    *a5 = v98;
                  }
                  v99 = &a4[v97];
                  v116 = (*v99)++;
                  v150 = v99;
                  v100 = D3DXShader::CBaseProgram::AddArgument(
                           this,
                           a2: *((_DWORD *)this + 34),
                           a3: v97,
                           a4: v116,
                           a5: 0.0);
                  if ( v100 == -1 )
                    return 0;
                  if ( *v150 > 4 )
                    D3DXShader::CProgram::Error(
                      (D3DXShader::CTErrors **)this,
                      a2: nullptr,
                      a3: 0,
                      format: "internal error: component out of range");
                  v101 = *(int **)(*((_DWORD *)this + 5) + 4 * v100);
                  v101[5] = (int)v125;
                  v101[6] = (int)v124;
                  *v101 = *(_DWORD *)HIDWORD(v121) & 0xE000000;
                  v101[18] = m;
                  *(_DWORD *)(v90 + *(_DWORD *)(v140 + 8)) = v100;
                  *(_DWORD *)(v90 + *(_DWORD *)(ii + 16)) = v100;
                }
                v102 = 0;
                if ( v134 != 0 )
                {
                  v103 = *((_DWORD *)this + 2) == 0;
                  if ( *((_DWORD *)this + 2) != 0 )
                  {
                    v104 = *((int **)this + 5);
                    do
                    {
                      v105 = *v104;
                      if ( *((_DWORD *)this + 30) == *(_DWORD *)(*v104 + 4)
                        && *(_DWORD *)(v105 + 8) == -1
                        && *(double *)(v105 + 32) == *(double *)&v119[2 * v146 + 12] )
                      {
                        break;
                      }
                      ++v102;
                      ++v104;
                    }
                    while ( v102 < *((_DWORD *)this + 2) );
                    v103 = v102 == *((_DWORD *)this + 2);
                  }
                  if ( v103 )
                  {
                    v106 = D3DXShader::CBaseProgram::AddArgument(
                             this,
                             a2: *((_DWORD *)this + 30),
                             a3: 0,
                             a4: 0,
                             a5: *(double *)&v119[2 * v146 + 12]);
                    v102 = v106;
                    if ( v106 == -1 )
                      return 0;
                    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v106) + 52) = v106;
                  }
                  *(_DWORD *)(v137 + *(_DWORD *)(v140 + 8)) = v102;
                }
LABEL_290:
                v107 = v135;
                v108 = &a4[v135];
                v117 = (*v108)++;
                v151 = v108;
                v109 = D3DXShader::CBaseProgram::AddArgument(
                         this,
                         a2: *((_DWORD *)this + 34),
                         a3: v107,
                         a4: v117,
                         a5: 0.0);
                if ( v109 == -1 )
                  return 0;
                if ( *v151 > 4 )
                  D3DXShader::CProgram::Error(
                    (D3DXShader::CTErrors **)this,
                    a2: nullptr,
                    a3: 0,
                    format: "internal error: component out of range");
                v110 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v109);
                v111 = v128;
                v110[5] = v125;
                v110[6] = v124;
                v152 = (unsigned int *)((char *)v111 + HIDWORD(jj));
                *v110 = **(_DWORD **)(*((_DWORD *)this + 5) + 4 * *(unsigned int *)((char *)v111 + HIDWORD(jj)));
                v110[18] = v133;
                *(_DWORD *)(v90 + *(_DWORD *)(v140 + 16)) = v109;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * v109) + 52) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v152)
                                                                                            + 52);
                v112 = v128;
                *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * *v152) + 52) = v109;
                *v112 = *(_DWORD *)(v90 + *(_DWORD *)(v140 + 16));
                v90 += 4;
                v137 += 4;
                *(_DWORD *)HIDWORD(n) = 1;
                goto LABEL_294;
              }
              m = v87;
              ii = (unsigned int)v88;
LABEL_255:
              if ( v132 == 0 && v134 == 0 )
              {
                v89 = D3DXShader::CBaseProgram::AddInstruction(
                        this,
                        a2: v149 & 0xFFFFF | 0x10000000,
                        a3: 0xFFFFFFFF,
                        a4: 0xFFFFFFFF);
                v133 = v89;
                m = v89;
                if ( v89 == -1 )
                  return 0;
                v140 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v89);
                ii = v140;
                D3DXShader::CInstruction::Instance(this: (D3DXShader::CInstruction *)v140, a2: a6);
              }
              goto LABEL_259;
            }
            v133 = v85;
            v140 = (unsigned int)v86;
          }
          if ( v134 == 0 )
            goto LABEL_255;
          goto LABEL_252;
        }
LABEL_295:
        ;
      }
      v113 = a2;
      for ( i4 = a3; i4 != 0; --i4 )
      {
        *v113 = v129[*(unsigned int *)((char *)v113 + (char *)v119 - (char *)a2)];
        ++v113;
      }
      v115 = 0;
      while ( v123[v115] != 0 )
      {
        if ( ++v115 >= a3 )
          return 1;
      }
      return 0;
    }
  }
  qmemcpy(a2, v129, v130);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED517
// Name: private: long D3DXShader::CProgram::CompactPool_Read(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactPool_Read(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned int a6)
{
  int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _DWORD *v10; // esi
  bool v11; // zf
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  unsigned int v19; // esi
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // eax
  unsigned int v23; // eax
  int result; // eax
  unsigned int v25; // edx
  unsigned int v26; // edi
  _DWORD *v27; // ecx
  unsigned int v28; // eax
  _DWORD *v29; // ecx
  int v30; // eax
  int v31; // ecx
  int *v32; // eax
  int v33; // ecx
  unsigned int v34; // esi
  __int128 v35; // [esp+0h] [ebp-3Ch] BYREF
  _QWORD v36[2]; // [esp+10h] [ebp-2Ch] BYREF
  int v37; // [esp+20h] [ebp-1Ch]
  unsigned int v38; // [esp+24h] [ebp-18h]
  _DWORD *v39; // [esp+28h] [ebp-14h]
  unsigned int v40; // [esp+2Ch] [ebp-10h]
  unsigned int v41; // [esp+30h] [ebp-Ch]
  unsigned int v42; // [esp+34h] [ebp-8h]
  D3DXShader::CProgram *v43; // [esp+38h] [ebp-4h]
  struct D3DXShader::_D3DXCP_DATA *v44; // [esp+44h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v45; // [esp+44h] [ebp+8h]
  unsigned int i; // [esp+48h] [ebp+Ch]
  int v47; // [esp+4Ch] [ebp+10h]
  unsigned int v48; // [esp+54h] [ebp+18h]

  v6 = *((_DWORD *)this + 5);
  v7 = a3;
  v43 = this;
  v8 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
  if ( v8 != -1 )
  {
    a3 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
    v7 = v8;
  }
  v10 = *(_DWORD **)(v6 + 4 * v7);
  v11 = *(_DWORD *)a2 == v10[1];
  v39 = v10;
  if ( !v11 )
    goto LABEL_47;
  v12 = 4 * v10[3];
  if ( *(_DWORD *)(v12 + *((_DWORD *)a2 + 4)) != -1 )
    goto LABEL_47;
  v13 = *((_DWORD *)a2 + 1);
  if ( *(_DWORD *)(v12 + *((_DWORD *)a2 + 2)) < v13 && *(_DWORD *)(v12 + *((_DWORD *)a2 + 3)) < v13 )
    goto LABEL_47;
  v41 = -1;
  v42 = -1;
  if ( a6 != -1 )
  {
    v41 = *(_DWORD *)(*((_DWORD *)a2 + 8) + 4 * a6);
    v42 = D3DXShader::CProgram::CompactPool_Score(
            this: v43,
            a2,
            a3: v7,
            a4: v41,
            a5: a4,
            a6: (unsigned int *)v36,
            a7: 0xFFFFFFFF);
    goto LABEL_27;
  }
  v48 = 0;
  if ( *((_DWORD *)a2 + 11) == 0 )
  {
LABEL_28:
    if ( (*((_BYTE *)a2 + 96) & 2) != 0 )
      D3DXShader::CProgram::Error(
        this: (D3DXShader::CTErrors **)v43,
        a2: *(struct D3DXShader::CNode **)(*((_DWORD *)a2 + 23) + 60),
        a3: 0xFA4u,
        format: "program too complex; there are more active values than registers");
    return -2147467259;
  }
  while ( 1 )
  {
    v14 = *((_DWORD *)a2 + 15);
    v15 = *((_DWORD *)a2 + 16);
    v44 = nullptr;
    v40 = *(_DWORD *)(*((_DWORD *)a2 + 8) + 4 * v48);
    v16 = 4 * v10[3];
    v17 = *(_DWORD *)(v14 + v16);
    v18 = *((_DWORD *)a2 + 17) + 4 * *(_DWORD *)(v15 + v16);
    v38 = v17;
    v37 = v18;
    if ( v17 != 0 )
    {
      while ( 1 )
      {
        v19 = v40;
        if ( v40 == *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * *(_DWORD *)(v37 + 4 * (_DWORD)v44)) )
          break;
        v44 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v44 + 1);
        if ( (unsigned int)v44 >= v38 )
        {
          v19 = v40;
          break;
        }
      }
      if ( (unsigned int)v44 < v38 )
        goto LABEL_23;
    }
    else
    {
      v19 = v40;
    }
    if ( a5 == -1 )
      goto LABEL_52;
    v45 = nullptr;
    v20 = 4 * *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v43 + 5) + 4 * a5) + 12);
    v21 = *(_DWORD *)(v20 + v14);
    v22 = *((_DWORD *)a2 + 17) + 4 * *(_DWORD *)(v20 + v15);
    if ( v21 == 0 )
      goto LABEL_52;
    do
    {
      if ( v19 == *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * *(_DWORD *)(v22 + 4 * (_DWORD)v45)) )
        break;
      v45 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v45 + 1);
    }
    while ( (unsigned int)v45 < v21 );
    if ( (unsigned int)v45 >= v21 )
    {
LABEL_52:
      v23 = D3DXShader::CProgram::CompactPool_Score(
              this: v43,
              a2,
              a3,
              a4: v19,
              a5: a4,
              a6: (unsigned int *)&v35,
              a7: v42);
      if ( v23 < v42 )
      {
        v41 = v19;
        *(_OWORD *)v36 = v35;
        v42 = v23;
        if ( v23 == 0 )
          break;
      }
    }
LABEL_23:
    ++v48;
    v10 = v39;
    if ( v48 >= *((_DWORD *)a2 + 11) )
      goto LABEL_27;
  }
  v10 = v39;
LABEL_27:
  if ( v42 == -1 )
    goto LABEL_28;
  v25 = v41;
  *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * v10[3]) = v41;
  if ( (*((_BYTE *)v43 + 204) & 4) != 0 )
  {
    v26 = *((_DWORD *)a2 + 9);
    if ( v25 < v26 )
    {
      v27 = *((_DWORD **)a2 + 8);
      v28 = 0;
      while ( 1 )
      {
        ++v28;
        if ( *v27 == v25 )
          break;
        ++v27;
      }
      if ( v28 < v26 )
      {
        do
        {
          v29 = (_DWORD *)(*((_DWORD *)a2 + 8) + 4 * v28++);
          *(v29 - 1) = *v29;
        }
        while ( v28 < *((_DWORD *)a2 + 9) );
      }
      *(_DWORD *)(*((_DWORD *)a2 + 8) + 4 * *((_DWORD *)a2 + 9) - 4) = v25;
    }
  }
  for ( i = 0; i < 4; ++i )
  {
    v30 = 4 * (i + 4 * v10[3]);
    v47 = *(_DWORD *)(v30 + *((_DWORD *)a2 + 6));
    if ( v47 != -1 )
    {
      v31 = *((_DWORD *)v36 + i);
      *(_DWORD *)(v30 + *((_DWORD *)a2 + 5)) = v31;
      v32 = (int *)(*((_DWORD *)a2 + 7) + 4 * (v31 + 4 * v25));
      if ( *v32 != -1 )
      {
        do
        {
          v33 = 4 * *v32;
          if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v43 + 5) + v33) + 88) <= *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v43 + 5)
                                                                                                  + 4 * v47)
                                                                                      + 88) )
            break;
          v32 = (int *)(*(_DWORD *)(v33 + *((_DWORD *)v43 + 5)) + 48);
        }
        while ( *v32 != -1 );
        v25 = v41;
      }
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v43 + 5) + 4 * v47) + 48) = *v32;
      *v32 = v47;
    }
  }
LABEL_47:
  v34 = v10[2];
  if ( v34 == -1 )
    return 0;
  result = D3DXShader::CProgram::CompactPool_Read(this: v43, a2, a3: v34, a4: 0, a5: 0xFFFFFFFF, a6: 0xFFFFFFFF);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED7DF
// Name: private: long D3DXShader::CProgram::CompactPool_Write(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactPool_Write(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3)
{
  unsigned int v3; // eax
  int result; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3) + 20);
  if ( v3 == -1 )
    return 0;
  result = D3DXShader::CProgram::CompactPool_Read(this, a2, a3: v3, a4: 0, a5: 0xFFFFFFFF, a6: 0xFFFFFFFF);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED80E
// Name: protected: long D3DXShader::CProgram::CompactPool_Begin(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CProgram::CompactPool_Begin(D3DXShader::CProgram *this, void **a2, void *a3, void *a4)
{
  D3DXShader::CProgram *v4; // ebx
  unsigned int v7; // edi
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  void *v13; // eax
  void *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  void *v18; // eax
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  unsigned int *v23; // edi
  unsigned int v24; // ecx
  int v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  int v29; // edx
  int v30; // eax
  unsigned int v31; // edi
  _DWORD *v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int k; // ecx
  void *v37; // eax
  int v38; // edi
  unsigned int v39; // ecx
  int v40; // edx
  int v41; // edi
  int v42; // eax
  int v43; // eax
  _DWORD *v44; // eax
  bool v45; // zf
  unsigned int v46; // ecx
  int v47; // eax
  void *v48; // eax
  int v49; // edi
  unsigned int v50; // eax
  int v51; // edi
  void *v52; // eax
  void *v53; // eax
  int v55; // [esp+8h] [ebp-24h]
  unsigned int v56; // [esp+Ch] [ebp-20h]
  int v57; // [esp+Ch] [ebp-20h]
  int v58; // [esp+10h] [ebp-1Ch]
  int v59; // [esp+10h] [ebp-1Ch]
  int v60; // [esp+14h] [ebp-18h]
  int v61; // [esp+14h] [ebp-18h]
  int v62; // [esp+18h] [ebp-14h]
  int v63; // [esp+18h] [ebp-14h]
  unsigned int i; // [esp+1Ch] [ebp-10h]
  D3DXShader::CInstruction *v65; // [esp+20h] [ebp-Ch]
  int v66; // [esp+20h] [ebp-Ch]
  int v67; // [esp+24h] [ebp-8h]
  unsigned int *v68; // [esp+28h] [ebp-4h]
  unsigned int v69; // [esp+34h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *v70; // [esp+34h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *n; // [esp+34h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *ii; // [esp+34h] [ebp+8h]
  struct D3DXShader::_D3DXCP_DATA *jj; // [esp+34h] [ebp+8h]
  unsigned int v74; // [esp+38h] [ebp+Ch]
  unsigned int v75; // [esp+3Ch] [ebp+10h]
  unsigned int v76; // [esp+3Ch] [ebp+10h]
  unsigned int j; // [esp+3Ch] [ebp+10h]
  unsigned int m; // [esp+3Ch] [ebp+10h]

  v4 = this;
  D3DXShader::CProgram::ReadWriteInfo(this);
  if ( a2 == nullptr )
    return -2147467259;
  memset(a2, 0, 0x64u);
  a2[11] = a4;
  *a2 = a3;
  v7 = 0;
  for ( a2[24] = (void *)(((unsigned int)a2[24] ^ ((2 * *((_DWORD *)v4 + 27)) >> 31)) & 1 ^ (unsigned int)a2[24]);
        v7 < *((_DWORD *)v4 + 2);
        ++v7 )
  {
    v8 = *(_DWORD **)(*((_DWORD *)v4 + 5) + 4 * v7);
    if ( a3 == (void *)v8[1] && v8[14] == -1 )
    {
      v9 = v8[3];
      if ( v9 >= (unsigned int)a2[10] )
        a2[10] = (void *)(v9 + 1);
      v8[29] = a2[18];
      a2[18] = (char *)a2[18] + 1;
    }
  }
  v10 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[10]);
  a2[4] = v10;
  if ( v10 != nullptr )
  {
    v11 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2[10]);
    a2[5] = v11;
    if ( v11 != nullptr )
    {
      v12 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2[10]);
      a2[6] = v12;
      if ( v12 != nullptr )
      {
        v13 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[10]);
        a2[2] = v13;
        if ( v13 != nullptr )
        {
          v14 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[10]);
          a2[3] = v14;
          if ( v14 != nullptr )
          {
            v15 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2[11]);
            a2[7] = v15;
            if ( v15 != nullptr )
            {
              v16 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[11]);
              a2[8] = v16;
              if ( v16 != nullptr )
              {
                v17 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2[10]);
                a2[12] = v17;
                if ( v17 != nullptr )
                {
                  v18 = MemAlloc_Alloc(nSize: 16 * (_DWORD)a2[10]);
                  a2[13] = v18;
                  if ( v18 != nullptr )
                  {
                    v19 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[10]);
                    a2[15] = v19;
                    if ( v19 != nullptr )
                    {
                      v20 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[10]);
                      a2[16] = v20;
                      if ( v20 != nullptr )
                      {
                        v21 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[18]);
                        a2[19] = v21;
                        if ( v21 != nullptr )
                        {
                          v22 = MemAlloc_Alloc(nSize: 4 * (_DWORD)a2[18]);
                          a2[20] = v22;
                          if ( v22 != nullptr )
                          {
                            v67 = 0;
                            while ( 1 )
                            {
                              memset(a2[12], 0, 16 * (_DWORD)a2[10]);
                              v58 = 0;
                              for ( i = 0; i < *((_DWORD *)v4 + 3); ++i )
                              {
                                v65 = *(D3DXShader::CInstruction **)(*((_DWORD *)v4 + 6) + 4 * i);
                                if ( D3DXShader::CInstruction::IsCopy(this: v65) != 0
                                  && a3 == *(void **)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * **((_DWORD **)v65 + 4)) + 4) )
                                {
                                  v69 = *(_DWORD *)v65 & 0xFFFFF;
                                  if ( *((_DWORD *)v65 + 1) / v69 != 0 )
                                  {
                                    v60 = 0;
                                    v56 = *((_DWORD *)v65 + 1) / (*(_DWORD *)v65 & 0xFFFFFu);
                                    do
                                    {
                                      v23 = (unsigned int *)(v60 + *((_DWORD *)v65 + 2));
                                      v68 = v23;
                                      v75 = *v23;
                                      if ( *v23 == -1
                                        || (v24 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * *v23) + 56)) == -1 )
                                      {
                                        v24 = *v23;
                                      }
                                      v25 = *((_DWORD *)v4 + 5);
                                      if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)v4 + 4)
                                                                 + 4 * *(_DWORD *)(*(_DWORD *)(v25 + 4 * v24) + 4))
                                                     + 6)
                                          & 2) != 0 )
                                      {
                                        if ( v75 == -1 || (v26 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v75) + 56)) == -1 )
                                          v26 = *v23;
                                        v23 = *(unsigned int **)(*(_DWORD *)(*((_DWORD *)v4 + 6)
                                                                           + 4
                                                                           * *(_DWORD *)(*(_DWORD *)(v25 + 4 * v26) + 72))
                                                               + 8);
                                        v68 = v23;
                                      }
                                      v27 = *v23;
                                      if ( *v23 != -1 && *(_DWORD *)(*(_DWORD *)(v25 + 4 * v27) + 56) != -1 )
                                        v27 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v27) + 56);
                                      if ( a3 == *(void **)(*(_DWORD *)(v25 + 4 * v27) + 4) )
                                      {
                                        v62 = 0;
                                        v76 = 0;
                                        if ( v69 == 0 )
                                          goto LABEL_48;
                                        do
                                        {
                                          v28 = v23[v76];
                                          if ( v28 != -1 && *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 56) != -1 )
                                            v28 = *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 56);
                                          v29 = 1 << *(_DWORD *)(*(_DWORD *)(v25 + 4 * v28) + 16);
                                          if ( (v29 & v62) != 0 )
                                            break;
                                          v62 |= v29;
                                          ++v76;
                                        }
                                        while ( v76 < v69 );
                                        if ( v76 >= v69 )
                                        {
LABEL_48:
                                          for ( j = 0; j < v69; v23 = v68 )
                                          {
                                            v30 = *((_DWORD *)v4 + 5);
                                            v31 = v23[j];
                                            v32 = *(_DWORD **)(v30 + 4 * *(_DWORD *)(4 * j + *((_DWORD *)v65 + 4)));
                                            if ( v31 != -1 && *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 56) != -1 )
                                              v31 = *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 56);
                                            v33 = v32[4] + 4 * v32[3];
                                            v34 = *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 16)
                                                + 4 * *(_DWORD *)(*(_DWORD *)(v30 + 4 * v31) + 12);
                                            if ( v33 != v34 && v32[15] == 0 )
                                            {
                                              if ( v67 == 1 )
                                              {
                                                v4 = this;
                                                *((_DWORD *)a2[14]
                                                + *((_DWORD *)a2[13] + v33)
                                                + *((_DWORD *)a2[12] + v33)) = v34;
                                                *((_DWORD *)a2[14]
                                                + *((_DWORD *)a2[13] + v34)
                                                + *((_DWORD *)a2[12] + v34)) = v33;
                                              }
                                              ++*((_DWORD *)a2[12] + v33);
                                              ++*((_DWORD *)a2[12] + v34);
                                              v58 += 2;
                                            }
                                            ++j;
                                          }
                                        }
                                      }
                                      v60 += 4 * v69;
                                      --v56;
                                    }
                                    while ( v56 != 0 );
                                  }
                                }
                              }
                              if ( v67 == 0 )
                              {
                                v35 = 0;
                                for ( k = 0; k < 4 * (int)a2[10]; ++k )
                                {
                                  *((_DWORD *)a2[13] + k) = v35;
                                  v35 += *((_DWORD *)a2[12] + k);
                                }
                                v37 = MemAlloc_Alloc(nSize: 4 * v58);
                                a2[14] = v37;
                                if ( v37 == nullptr )
                                  break;
                              }
                              if ( (unsigned int)++v67 >= 2 )
                              {
                                v70 = nullptr;
                                while ( 1 )
                                {
                                  memset(a2[15], 0, 4 * (_DWORD)a2[10]);
                                  v61 = 0;
                                  for ( m = 0; m < *((_DWORD *)v4 + 3); ++m )
                                  {
                                    v59 = *(_DWORD *)(*((_DWORD *)v4 + 6) + 4 * m);
                                    if ( D3DXShader::CInstruction::IsMacro(this: (D3DXShader::CInstruction *)v59) != 0
                                      || *((char *)v4 + 111) < 0 )
                                    {
                                      v38 = *(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * **(_DWORD **)(v59 + 16));
                                      if ( a3 == *(void **)(v38 + 4) )
                                      {
                                        v39 = *(_DWORD *)v59 & 0xFFFFF;
                                        v40 = *(_DWORD *)(v38 + 12);
                                        v55 = v40;
                                        if ( *(_DWORD *)(v59 + 4) / v39 != 0 )
                                        {
                                          v41 = 0;
                                          v57 = 0;
                                          v66 = 4 * v39;
                                          v63 = *(_DWORD *)(v59 + 4) / v39;
                                          do
                                          {
                                            v42 = *(_DWORD *)(v41 + *(_DWORD *)(v59 + 8));
                                            if ( v42 != -1
                                              && *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42) + 56) != -1 )
                                            {
                                              v42 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42) + 56);
                                            }
                                            v43 = *(_DWORD *)(*((_DWORD *)v4 + 5) + 4 * v42);
                                            if ( a3 == *(void **)(v43 + 4) && v40 != *(_DWORD *)(v43 + 12) )
                                            {
                                              if ( v70 == (struct D3DXShader::_D3DXCP_DATA *)1 )
                                              {
                                                *((_DWORD *)a2[17]
                                                + *((_DWORD *)a2[15] + v40)
                                                + *((_DWORD *)a2[16] + v40)) = *(_DWORD *)(v43 + 12);
                                                v40 = v55;
                                                *((_DWORD *)a2[17]
                                                + *((_DWORD *)a2[15] + *(_DWORD *)(v43 + 12))
                                                + *((_DWORD *)a2[16] + *(_DWORD *)(v43 + 12))) = v55;
                                              }
                                              ++*((_DWORD *)a2[15] + v40);
                                              v44 = (char *)a2[15] + 4 * *(_DWORD *)(v43 + 12);
                                              ++*v44;
                                              v61 += 2;
                                            }
                                            v41 = v66 + v57;
                                            v45 = v63-- == 1;
                                            v57 += v66;
                                          }
                                          while ( !v45 );
                                        }
                                      }
                                    }
                                  }
                                  v46 = 0;
                                  if ( v70 == nullptr )
                                  {
                                    v47 = 0;
                                    if ( a2[10] != nullptr )
                                    {
                                      do
                                      {
                                        *((_DWORD *)a2[16] + v46) = v47;
                                        v47 += *((_DWORD *)a2[15] + v46++);
                                      }
                                      while ( v46 < (unsigned int)a2[10] );
                                    }
                                    v48 = MemAlloc_Alloc(nSize: 4 * v61);
                                    a2[17] = v48;
                                    if ( v48 == nullptr )
                                      break;
                                  }
                                  v70 = (struct D3DXShader::_D3DXCP_DATA *)((char *)v70 + 1);
                                  if ( (unsigned int)v70 >= 2 )
                                  {
                                    v74 = 0;
                                    memset(a2[19], 0, 4 * (_DWORD)a2[18]);
                                    if ( *((_DWORD *)v4 + 3) != 0 )
                                    {
                                      do
                                      {
                                        v49 = *(_DWORD *)(*((_DWORD *)v4 + 6) + 4 * v74);
                                        if ( (*(_WORD *)(v49 + 2) & 0xFFF0) != 0 )
                                        {
                                          for ( n = nullptr;
                                                (unsigned int)n < *(_DWORD *)(v49 + 12);
                                                n = (struct D3DXShader::_D3DXCP_DATA *)((char *)n + 1) )
                                          {
                                            D3DXShader::CProgram::CompactPool_WriteCount(
                                              this: v4,
                                              (struct D3DXShader::_D3DXCP_DATA *)a2,
                                              a3: *(_DWORD *)(*(_DWORD *)(v49 + 16) + 4 * (_DWORD)n),
                                              a4: v74);
                                          }
                                          for ( ii = nullptr;
                                                (unsigned int)ii < *(_DWORD *)(v49 + 4);
                                                ii = (struct D3DXShader::_D3DXCP_DATA *)((char *)ii + 1) )
                                          {
                                            D3DXShader::CProgram::CompactPool_ReadCount(
                                              this: v4,
                                              (struct D3DXShader::_D3DXCP_DATA *)a2,
                                              a3: *(_DWORD *)(*(_DWORD *)(v49 + 8) + 4 * (_DWORD)ii),
                                              a4: v74);
                                          }
                                          if ( D3DXShader::CInstruction::IsSpecial(this: (D3DXShader::CInstruction *)v49) != 0 )
                                          {
                                            for ( jj = nullptr;
                                                  (unsigned int)jj < *(_DWORD *)(v49 + 12);
                                                  jj = (struct D3DXShader::_D3DXCP_DATA *)((char *)jj + 1) )
                                            {
                                              D3DXShader::CProgram::CompactPool_ReadCount(
                                                this: v4,
                                                (struct D3DXShader::_D3DXCP_DATA *)a2,
                                                a3: *(_DWORD *)(*(_DWORD *)(v49 + 16) + 4 * (_DWORD)jj),
                                                a4: v74);
                                            }
                                          }
                                        }
                                        ++v74;
                                      }
                                      while ( v74 < *((_DWORD *)v4 + 3) );
                                    }
                                    v50 = 0;
                                    v51 = 0;
                                    if ( a2[18] != nullptr )
                                    {
                                      do
                                      {
                                        *((_DWORD *)a2[20] + v50) = v51;
                                        v51 += *((_DWORD *)a2[19] + v50++);
                                      }
                                      while ( v50 < (unsigned int)a2[18] );
                                    }
                                    v52 = MemAlloc_Alloc(nSize: 4 * v51);
                                    a2[21] = v52;
                                    if ( v52 != nullptr )
                                    {
                                      v53 = MemAlloc_Alloc(nSize: 12 * v51);
                                      a2[22] = v53;
                                      if ( v53 != nullptr )
                                        return 0;
                                    }
                                    return -2147024882;
                                  }
                                }
                                return -2147024882;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -2147024882;
}
