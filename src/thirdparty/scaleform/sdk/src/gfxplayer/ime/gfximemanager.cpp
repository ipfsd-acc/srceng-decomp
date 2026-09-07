// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/ime/gfximemanager.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\ime\gfximemanager.h"

//------------------------------------------------------------------------------
// Address: 0x1010A2A0
// Name: public: void GFxIMEManager::DoFinalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxIMEManager::DoFinalize(_DWORD *this)
{
  int v2; // esi
  GRefCountNTSImpl *v3; // ecx

  (*(void (__thiscall **)(_DWORD *))(*this + 104))(a1: this);
  v2 = *(this + 3);
  v3 = *(GRefCountNTSImpl **)(v2 + 4);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  *(_DWORD *)(v2 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010A2D0
// Name: private: void GFxIMEManager::OnMouseDown(class GFxMovieView __near *,int,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxIMEManager::OnMouseDown(
        _DWORD *a1@<ecx>,
        unsigned int pmovie,
        GMemAddressStub *buttonsState,
        int pitemUnderMousePtr,
        const char *a5,
        int a6)
{
  int v7; // eax
  int v8; // esi
  GRefCountNTSImpl *v9; // ecx

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, unsigned int))(*a1 + 72))(a1, a2: pmovie) != 0 )
  {
    v7 = *(_DWORD *)(a1[3] + 4);
    if ( v7 != 0 && pitemUnderMousePtr == v7 )
    {
      (*(void (__thiscall **)(_DWORD *))(*a1 + 104))(a1);
      v8 = a1[3];
      v9 = *(GRefCountNTSImpl **)(v8 + 4);
      if ( v9 != nullptr )
        GRefCountNTSImpl::Release(this: v9);
      *(_DWORD *)(v8 + 4) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A320
// Name: public: bool GFxIMEManager::IsCandidateListLoaded(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxIMEManager::IsCandidateListLoaded(int a1@<ecx>, int a2@<edi>)
{
  _DWORD *v3; // eax
  StringPoolCase_t val; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-Ch]
  double v6; // [esp+10h] [ebp-8h]

  v3 = *(_DWORD **)(a1 + 12);
  if ( *v3 != 0 )
  {
    val = StringPoolCaseInsensitive;
    v5 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, StringPoolCase_t *, const char *))(*(_DWORD *)*v3 + 68))(
           a1: *v3,
           a2: &val,
           a3: "_global.gfx_ime_candidate_list_state") == 0 )
    {
      if ( (v5 & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: (CStringPool *)val,
          a2,
          (StringPoolCase_t)&val,
          pobj: (IShaderAPI *)LODWORD(v6));
        val = StringPoolCaseInsensitive;
      }
      v5 = 3;
      v6 = 0.0;
    }
    GFxMovieRoot::GetLevelMovie(this: **(GFxMovieRoot ***)(a1 + 12), level: 9999);
    if ( (v5 & 0x40) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)val,
        a2,
        (StringPoolCase_t)&val,
        pobj: (IShaderAPI *)LODWORD(v6));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A3D0
// Name: private: class GFxASCharacter __near * GFxIMEManager::HandleFocus(class GFxMovieView __near *,class GFxASCharacter __near *,class GFxASCharacter __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxASCharacter *__userpurge GFxIMEManager::HandleFocus@<eax>(
        GFxMovieRoot ***this@<ecx>,
        CUtlMemory<CImagePacker,int> a2,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a3,
        struct GFxASCharacter *a4,
        struct GFxASCharacter *a5)
{
  GFxMovieRoot ***v5; // esi
  int v6; // ebx
  GFxMovieRoot *v7; // edx
  char v8; // al
  int m_nGrowSize; // edi
  GFxSprite *LevelMovie; // ecx
  struct GFxASCharacter *v11; // edi
  struct GFxASCharacter *v12; // esi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char v17; // al
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  char v21; // dl
  GFxMovieRoot **v22; // eax
  char v23; // cl
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *val; // [esp+20h] [ebp-1Ch] BYREF
  int v26; // [esp+24h] [ebp-18h]
  double v27; // [esp+28h] [ebp-14h]
  GFxIMEManager *v28; // [esp+30h] [ebp-Ch]
  struct GASStringNode *ConstStringNode; // [esp+34h] [ebp-8h] BYREF
  struct GASStringNode *v30; // [esp+38h] [ebp-4h] BYREF

  v5 = this;
  v6 = 0;
  ConstStringNode = nullptr;
  v7 = (*this)[18];
  v28 = (GFxIMEManager *)this;
  v8 = ((int (__stdcall *)(CImagePacker *))v7)(a1: a2.m_pMemory);
  m_nGrowSize = a2.m_nGrowSize;
  if ( v8 == 0 )
    return (struct GFxASCharacter *)m_nGrowSize;
  if ( a2.m_nGrowSize != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)a2.m_nGrowSize + 176))(a1: a2.m_nGrowSize) == 4 )
  {
    a2.m_pMemory = (CImagePacker *)(*(int (__thiscall **)(int))(*(_DWORD *)m_nGrowSize + 448))(a1: m_nGrowSize);
    val = nullptr;
    v26 = 0;
    if ( a2.m_pMemory != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **, const char *))(*(_DWORD *)*v5[3] + 68))(
             a1: *v5[3],
             a2: &val,
             a3: "_global.gfx_ime_candidate_list_state") == 0 )
        GFxValue::SetNumber(this: (GFxValue *)&val, v: 0.0);
      LevelMovie = (GFxSprite *)GFxMovieRoot::GetLevelMovie(this: *v5[3], level: 9999);
      if ( LevelMovie != nullptr && 2.0 == v27 )
        GFxSprite::SetIMECandidateListFont(this: LevelMovie, a2: (int)a2.m_pMemory);
    }
    if ( (v26 & 0x40) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)val,
        a2: m_nGrowSize,
        (StringPoolCase_t)&val,
        pobj: (IShaderAPI *)LODWORD(v27));
  }
  if ( a2.m_nAllocationCount == 0
    || (*(int (__thiscall **)(int))(*(_DWORD *)a2.m_nAllocationCount + 176))(a1: a2.m_nAllocationCount) != 4 )
  {
LABEL_40:
    if ( m_nGrowSize != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)m_nGrowSize + 176))(a1: m_nGrowSize) == 4
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)m_nGrowSize + 404))(a1: m_nGrowSize) != 0 )
    {
      v21 = 1;
LABEL_34:
      v22 = v5[3];
      v23 = *((_BYTE *)v22 + 20);
      LOBYTE(a2.m_nAllocationCount) = v21;
      if ( v23 == v21 )
      {
        *((_BYTE *)v22 + 20) = v23 == 0;
        ((void (__thiscall *)(GFxMovieRoot ***, int))(*v5)[31])(a1: v5, a2: a2.m_nAllocationCount);
      }
      return (struct GFxASCharacter *)m_nGrowSize;
    }
LABEL_33:
    v21 = 0;
    goto LABEL_34;
  }
  if ( m_nGrowSize != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)m_nGrowSize + 176))(a1: m_nGrowSize);
    GFxIMEManager::DoFinalize(this: v5);
    goto LABEL_40;
  }
  if ( a3 == nullptr )
  {
LABEL_32:
    GFxIMEManager::DoFinalize(this: v5);
    goto LABEL_33;
  }
  GString::GString(this: &a2);
  v11 = (struct GFxASCharacter *)a3;
  GFxASCharacter::GetAbsolutePath(this: a3, &a2);
  if ( ((unsigned __int8 (__thiscall *)(GFxMovieRoot ***, unsigned int))(*v5)[21])(
         a1: v5,
         a2: ((int)a2.m_pMemory & 0xFFFFFFFC) + 8) == 0 )
  {
    v12 = v11;
    LOBYTE(val) = 0;
    while ( 1 )
    {
      v6 |= 1u;
      v13 = (*(int (__thiscall **)(struct GFxASCharacter *))(*(_DWORD *)v12 + 112))(a1: v12);
      ConstStringNode = GASStringManager::CreateConstStringNode(
                          this: *(GASStringManager **)(*(_DWORD *)(v13 + 120) + 636),
                          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3E8C.m_pElements,
                          a3: 0xDu,
                          a4: 0);
      ++*((_DWORD *)ConstStringNode + 2);
      v14 = (*(int (__thiscall **)(struct GFxASCharacter *))(*(_DWORD *)v12 + 112))(a1: v12);
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int, struct GASStringNode **, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*((_DWORD *)v12 + 30) + 44))(
             a1: (_DWORD *)v12 + 30,
             a2: v14 + 120,
             a3: &ConstStringNode,
             a4: &val) != 0
        || (v6 |= 2u,
            v15 = (*(int (__thiscall **)(struct GFxASCharacter *))(*(_DWORD *)v12 + 112))(a1: v12),
            v30 = GASStringManager::CreateConstStringNode(
                    this: *(GASStringManager **)(*(_DWORD *)(v15 + 120) + 636),
                    result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A3E8C,
                    a3: 0xEu,
                    a4: 0),
            ++*((_DWORD *)v30 + 2),
            v16 = (*(int (__thiscall **)(struct GFxASCharacter *))(*(_DWORD *)v12 + 112))(a1: v12),
            v17 = (*(int (__thiscall **)(_DWORD *, int, struct GASStringNode **, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*((_DWORD *)v12 + 30) + 44))(
                    a1: (_DWORD *)v12 + 30,
                    a2: v16 + 120,
                    a3: &v30,
                    a4: &val),
            HIBYTE(a3) = 0,
            v17 != 0) )
      {
        HIBYTE(a3) = 1;
      }
      if ( (v6 & 2) != 0 )
      {
        v18 = (int)v30;
        v6 &= ~2u;
        v19 = (*((_DWORD *)v30 + 2))-- == 1;
        if ( v19 )
          GASStringNode::ReleaseNode(a1: v18);
      }
      if ( (v6 & 1) != 0 )
      {
        v20 = (int)ConstStringNode;
        v6 &= ~1u;
        v19 = (*((_DWORD *)ConstStringNode + 2))-- == 1;
        if ( v19 )
          GASStringNode::ReleaseNode(a1: v20);
      }
      if ( HIBYTE(a3) != 0 )
        break;
      v12 = *((struct GFxASCharacter **)v12 + 8);
      if ( v12 == nullptr )
      {
        v5 = (GFxMovieRoot ***)v28;
        if ( (*(unsigned __int8 (__thiscall **)(GFxIMEManager *, unsigned int))(*(_DWORD *)v28 + 88))(
               a1: v28,
               a2: ((int)a2.m_pMemory & 0xFFFFFFFC) + 8) == 0
          && ((unsigned __int8 (__thiscall *)(GFxMovieRoot ***, unsigned int))(*v5)[23])(
               a1: v5,
               a2: ((int)a2.m_pMemory & 0xFFFFFFFC) + 8) == 0 )
        {
          GASValue::~GASValue(this: &val, a2: (int)v11);
          GString::~GString(this: (GString *)&a2);
          m_nGrowSize = a2.m_nGrowSize;
          goto LABEL_32;
        }
        break;
      }
    }
    GASValue::~GASValue(this: &val, a2: (int)v11);
  }
  GString::~GString(this: (GString *)&a2);
  return (struct GFxASCharacter *)a2.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x1010A740
// Name: public: bool GFxIMEManager::IsTextFieldFocused(class GFxASCharacter __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxIMEManager::IsTextFieldFocused(int a1@<ecx>, void *ptextfield, const char *a3, int a4)
{
  int v4; // eax
  _DWORD **v5; // esi
  _DWORD *v6; // eax
  GRefCountNTSImpl *v7; // edi

  v4 = *(_DWORD *)(a1 + 12);
  if ( *(_DWORD *)v4 != 0 )
  {
    v5 = (_DWORD **)(*(_DWORD *)v4 + 52 * (*(unsigned __int8 *)(*(_DWORD *)v4 + 10228) + 181));
    v6 = *v5;
    v7 = nullptr;
    if ( *v5 != nullptr )
    {
      if ( v6[1] != 0 )
      {
        v7 = (GRefCountNTSImpl *)v6[1];
        if ( v7 != nullptr )
        {
          ++v7->RefCount;
          ++v7->RefCount;
          GRefCountNTSImpl::Release(this: v7);
          if ( ((int (__thiscall *)(GRefCountNTSImpl *))v7->__vftable[44].dtr_GRefCountImplCore)(a1: v7) == 4 )
            v7->__vftable[101].dtr_GRefCountImplCore(this: v7);
        }
      }
      else
      {
        if ( (*v6)-- == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
        *v5 = nullptr;
      }
    }
    if ( v7 != nullptr )
      GRefCountNTSImpl::Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A7F0
// Name: public: bool GFxIMEManager::SetCandidateListStyle(class GFxIMECandidateListStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxIMEManager::SetCandidateListStyle(
        GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *this@<ecx>,
        IDirect3DVertexDeclaration9 *st,
        int a3)
{
  _DWORD **v4; // eax
  char v5; // al

  v4 = *((_DWORD ***)this + 3);
  if ( *v4 != nullptr )
    GFxMovieRoot::SetIMECandidateListStyle(ecx0: *v4, this: st);
  GFxIMEManager::IsCandidateListLoaded(a1: (int)this, a2: (int)st);
  if ( v5 != 0 )
    (*((void (__thiscall **)(GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *, IDirect3DVertexDeclaration9 *))this->Data.Data
     + 29))(
      a1: this,
      a2: st);
}

//------------------------------------------------------------------------------
// Address: 0x1010A830
// Name: public: bool GFxIMEManager::GetCandidateListStyle(class GFxIMECandidateListStyle __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxIMEManager::GetCandidateListStyle(
        GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *this@<ecx>,
        int a2@<edi>,
        GAmpRenderer **pst)
{
  char v4; // al
  GFxMovieRoot **v5; // esi

  GFxIMEManager::IsCandidateListLoaded(a1: (int)this, a2);
  if ( v4 != 0 )
  {
    (*((void (__thiscall **)(GArrayBase<GArrayData<GAmpRenderer *,GAllocatorLH<GAmpRenderer *,2>,GArrayDefaultPolicy> > *, GAmpRenderer **))this->Data.Data
     + 30))(
      a1: this,
      a2: pst);
  }
  else
  {
    v5 = *((GFxMovieRoot ***)this + 3);
    if ( *v5 != nullptr )
      GFxMovieRoot::GetIMECandidateListStyle(this: *v5, a2: (struct GFxIMECandidateListStyle *)pst);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A880
// Name: public: virtual enum GASObjectInterface::ObjectType GASMovieClipLoader::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
int GASMovieClipLoader::GetObjectType()
{
  return 25;
}

//------------------------------------------------------------------------------
// Address: 0x1010A890
// Name: protected: virtual void GASMovieClipLoader::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASMovieClipLoader::Finalize_GC(
        CMemberFuncProxyBase<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),CFuncMemPolicyNone> *this)
{
  GHashSetBase<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GASMovieClipLoader::ProgressDesc,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>,GStringLH_HashNode<GASMovieClipLoader::ProgressDesc,GString::NoCaseHashFunctor>::NodeHashF>>::Clear(this: (void **)this + 13);
  GASObject::Finalize_GC((GASObject *)this);
}
