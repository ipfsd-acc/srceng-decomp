// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gastimers.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gastimers.h"

//------------------------------------------------------------------------------
// Address: 0x10108030
// Name: private: unsigned __int64 GASIntervalTimer::GetNextInterval(unsigned __int64,unsigned __int64)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASIntervalTimer::GetNextInterval(
        GASIntervalTimer *this,
        unsigned __int64 currentTime,
        unsigned __int64 frameTime)
{
  unsigned __int64 v3; // rax

  v3 = frameTime / 0xA;
  if ( *((unsigned int *)this + 9) >= frameTime / 0xA )
    LODWORD(v3) = *((_DWORD *)this + 9);
  if ( (_DWORD)v3 != 0 )
    return (currentTime + (int)v3 - *((_QWORD *)this + 5)) / (int)v3 * v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101080A0
// Name: public: void GASIntervalTimer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASIntervalTimer::Clear(GASIntervalTimer *this)
{
  *((_BYTE *)this + 56) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101080B0
// Name: public: static void GASIntervalTimer::ClearInterval(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASIntervalTimer::ClearInterval(
        GMemAddressStub *a1@<edi>,
        long double a2@<st0>,
        GASEnvironment **a3)
{
  struct GFxMovieRoot *MovieRoot; // edi
  GASValue *v4; // eax
  double v5; // st7
  _SERVICE_STATUS *v6; // [esp-8h] [ebp-14h]
  double v8; // [esp+4h] [ebp-8h]

  if ( (int)a3[7] >= 1 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: a3[6]);
    v6 = (_SERVICE_STATUS *)a3[6];
    v4 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)a3, a2: 0);
    v5 = GASValue::ToNumber(this: v4, a2: (int)MovieRoot, a3: a2, result: v6);
    v8 = v5;
    if ( (HIDWORD(v8) & 0x7FF00000) != 0x7FF00000 || (HIDWORD(v8) & 0xFFFFF | LODWORD(v8)) == 0 )
      GFxMovieRoot::ClearIntervalTimer(a1: (int)MovieRoot, timerId: (int)v5, a3: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108120
// Name: public: static void GASIntervalTimer::ClearTimeout(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASIntervalTimer::ClearTimeout(
        GMemAddressStub *a1@<edi>,
        long double a2@<st0>,
        GASEnvironment **a3)
{
  GASIntervalTimer::ClearInterval(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10108130
// Name: public: GASIntervalTimer::GASIntervalTimer(class GASFunctionRef const __near &,class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
GASIntervalTimer *__thiscall GASIntervalTimer::GASIntervalTimer(GASIntervalTimer *this, const struct GASFunctionRef *a2, struct GASStringContext *psc)
{
  int v4; // eax
  tagIMECHARPOSITION *v5; // eax
  int v6; // eax

  *((_BYTE *)this + 8) = 0;
  v4 = *(_DWORD *)a2;
  *(_DWORD *)this = *(_DWORD *)a2;
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  *((_DWORD *)this + 1) = 0;
  v5 = *((tagIMECHARPOSITION **)a2 + 1);
  if ( v5 != nullptr )
    GASFunctionRefBase::SetLocalFrame(a1: (int)this, (int)a2, result: v5, internal: *((_BYTE *)a2 + 8) & 1);
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  v6 = *(_DWORD *)(*(_DWORD *)psc + 8);
  *((_DWORD *)this + 5) = v6;
  ++*(_DWORD *)(v6 + 8);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 28) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101081B0
// Name: public: GASIntervalTimer::GASIntervalTimer(class GASObject __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxAmpMessageSourceFile *__thiscall GASIntervalTimer::GASIntervalTimer(
        GFxAmpMessageSourceFile *this,
        GFxAmpMessage *object,
        _IMAGE_SYMBOL_EX *methodName)
{
  GFxAmpMessageSourceFile *result; // eax
  unsigned int Short; // edx

  result = this;
  LOBYTE(this->pPrev) = 0;
  this->__vftable = nullptr;
  this->RefCount = 0;
  if ( object != nullptr )
    object->pPrev = (GFxAmpMessage *)(((int)&object->pPrev->GListNode<GFxAmpMessage>::__vftable + 1) & 0x8FFFFFFF);
  this->pNext = object;
  this->MsgType = Msg_None;
  Short = methodName->N.Name.Short;
  this->Version = methodName->N.Name.Short;
  ++*(_DWORD *)(Short + 8);
  this->FileHandle = 0;
  this->FileData.Data.Data = nullptr;
  this->FileData.Data.Size = 0;
  this->FileData.Data.Policy.Capacity = 0;
  this->Filename.HeapTypeBits = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 28) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108210
// Name: public: GASIntervalTimer::GASIntervalTimer(class GFxASCharacter __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxAmpMessageSourceFile *__thiscall GASIntervalTimer::GASIntervalTimer(
        _BYTE *this,
        GRefCountWeakSupportImpl *result,
        _IMAGE_SYMBOL_EX *methodName)
{
  struct GWeakPtrProxy *WeakProxy; // eax
  unsigned int Short; // eax

  *(this + 8) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 3) = 0;
  if ( result != nullptr )
    WeakProxy = GRefCountWeakSupportImpl::CreateWeakProxy(this: result);
  else
    WeakProxy = nullptr;
  *((_DWORD *)this + 4) = WeakProxy;
  Short = methodName->N.Name.Short;
  *((_DWORD *)this + 5) = methodName->N.Name.Short;
  ++*(_DWORD *)(Short + 8);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 28) = 1;
  return (GFxAmpMessageSourceFile *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10108270
// Name: public: bool GASIntervalTimer::Invoke(class GFxMovieRoot __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GASIntervalTimer::Invoke@<al>(
        GASIntervalTimer *this@<ecx>,
        int a2@<ebx>,
        GMemoryHeap *a3@<esi>,
        struct GFxMovieRoot *i,
        float frameTime)
{
  GASIntervalTimer *v5; // edi
  bool v6; // zf
  unsigned int v8; // eax
  char v9; // bl
  __vc_attributes::iid_isAttribute *v10; // ebx
  int v11; // eax
  int v12; // esi
  GStat::StatValue *v13; // esi
  int (__thiscall *v14)(GStat::StatValue *); // eax
  struct GFxSprite *v15; // eax
  int v16; // eax
  const struct GASFunctionRefBase *v17; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v18; // ecx
  GRefCountNTSImpl *v19; // eax
  GRefCountNTSImpl *v20; // esi
  struct GFxSprite *LevelMovie; // eax
  int v22; // ebx
  __vc_attributes::iid_isAttribute *v23; // esi
  int v24; // ebx
  int v25; // edi
  tagWNDCLASSW *v26; // edi
  GASValue *limited_expression; // ecx
  __vc_attributes::iid_isAttribute *v28; // esi
  int v29; // eax
  int v30; // esi
  __int64 v31; // rax
  int v32; // edx
  const char *v35; // [esp+0h] [ebp-80h]
  int v36[3]; // [esp+4h] [ebp-7Ch] BYREF
  int v37; // [esp+10h] [ebp-70h]
  int v38; // [esp+14h] [ebp-6Ch]
  char v39; // [esp+18h] [ebp-68h]
  __vc_attributes::iid_isAttribute *v40; // [esp+1Ch] [ebp-64h]
  int v41; // [esp+20h] [ebp-60h]
  int v42; // [esp+24h] [ebp-5Ch]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v43; // [esp+28h] [ebp-58h] BYREF
  GASValue methodVal[4]; // [esp+38h] [ebp-48h] BYREF
  int v45; // [esp+48h] [ebp-38h] BYREF
  int v46; // [esp+4Ch] [ebp-34h]
  char v47; // [esp+50h] [ebp-30h]
  int v48; // [esp+54h] [ebp-2Ch] BYREF
  int v49; // [esp+58h] [ebp-28h]
  char v50; // [esp+5Ch] [ebp-24h]
  unsigned __int64 currentTime; // [esp+60h] [ebp-20h]
  int v52; // [esp+68h] [ebp-18h]
  GStat::StatValue *targetHolder; // [esp+6Ch] [ebp-14h]
  GASIntervalTimer *v54; // [esp+70h] [ebp-10h]
  int nArgs; // [esp+74h] [ebp-Ch] BYREF
  int v56; // [esp+78h] [ebp-8h]
  __vc_attributes::iid_isAttribute *v57; // [esp+7Ch] [ebp-4h]
  struct GFxMovieRoot *ia; // [esp+88h] [ebp+8h]

  v5 = this;
  v6 = *((_BYTE *)this + 56) == 0;
  v54 = this;
  if ( v6 )
    return 0;
  v8 = *((_DWORD *)i + 73);
  v9 = 0;
  LODWORD(currentTime) = *((_DWORD *)i + 72);
  HIDWORD(currentTime) = v8;
  if ( __PAIR64__(v8, currentTime) >= *((_QWORD *)this + 5) )
  {
    v10 = nullptr;
    v50 = 0;
    v48 = 0;
    v49 = 0;
    v56 = 0;
    v52 = 0;
    targetHolder = nullptr;
    v57 = nullptr;
    if ( *(_DWORD *)this != 0 )
    {
      GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v48, orig: (const struct GASFunctionRefBase *)this);
LABEL_27:
      if ( v48 != 0 )
      {
        LOBYTE(v43) = 0;
        if ( v57 == nullptr )
        {
          v18 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)v5
                + 13);
          if ( v18 == nullptr
            || (GFxCharacterHandle::ResolveCharacter(this: v18, a2: (GFxMovieRoot *)i), v20 = v19, v19 == nullptr)
            || (++v19->RefCount,
                v10 = (__vc_attributes::iid_isAttribute *)((int (__thiscall *)(GRefCountNTSImpl *))v19->__vftable[28].dtr_GRefCountImplCore)(a1: v19),
                v57 = v10,
                GRefCountNTSImpl::Release(this: v20),
                v10 == nullptr) )
          {
            LevelMovie = GFxMovieRoot::GetLevelMovie(this: (GFxMovieRoot *)i, level: (int)v10);
            v57 = (__vc_attributes::iid_isAttribute *)(*(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)LevelMovie
                                                                                                + 112))(a1: LevelMovie);
          }
        }
        v22 = *((_DWORD *)v5 + 7);
        nArgs = v22;
        if ( v22 > 0 )
        {
          ia = (struct GFxMovieRoot *)(v22 - 1);
          v23 = v57;
          v24 = 16 * (v22 - 1);
          do
          {
            v25 = *((_DWORD *)v5 + 6);
            v23[2].limited_expression += 16;
            v26 = (tagWNDCLASSW *)(v24 + v25);
            if ( v23[2].limited_expression >= v23[4].limited_expression )
              GASPagedStack<GASValue,32>::PushPage(this: v23 + 2);
            limited_expression = (GASValue *)v23[2].limited_expression;
            if ( limited_expression != nullptr )
              GASValue::GASValue(this: limited_expression, v: v26);
            v5 = v54;
            v24 -= 16;
            ia = (struct GFxMovieRoot *)((char *)ia - 1);
          }
          while ( (int)ia >= 0 );
          v22 = nArgs;
        }
        v28 = v57 + 2;
        v29 = ((v57[2].limited_expression - v57[3].limited_expression) >> 4) + 32 * (int)v57[7].limited_expression - 32;
        v36[1] = (int)&v43;
        v36[2] = v56;
        v37 = 0;
        v38 = 0;
        v40 = v57;
        v42 = v29;
        v36[0] = (int)&GASFnCall::`vftable';
        v39 = 0;
        v41 = v22;
        (*(void (__thiscall **)(int, int *, int, _DWORD))(*(_DWORD *)v48 + 40))(a1: v48, a2: v36, a3: v49, a4: 0);
        v36[0] = (int)&GASFnCall::`vftable';
        if ( (v39 & 2) == 0 && v37 != 0 )
          GRefCountBaseGC<323>::Release(a1: v37, a2: (int)v5);
        v37 = 0;
        if ( (v39 & 1) == 0 && v38 != 0 )
          GRefCountBaseGC<323>::Release(a1: v38, a2: (int)v5);
        if ( v22 > 0 )
        {
          do
          {
            GASValue::~GASValue(this: (GASValue *)v28->limited_expression, a2: (int)v5);
            v28->limited_expression -= 16;
            if ( v28->limited_expression < v28[1].limited_expression )
              GASPagedStack<GASValue,32>::PopPage(this: v28);
            --v22;
          }
          while ( v22 != 0 );
        }
        GASValue::~GASValue(this: &v43, a2: (int)v5);
      }
      if ( *((_BYTE *)v5 + 57) != 0 )
      {
        *((_BYTE *)v5 + 56) = 0;
      }
      else
      {
        v30 = currentTime;
        LODWORD(v31) = GASIntervalTimer::GetNextInterval(
                         this: v5,
                         currentTime,
                         frameTime: (unsigned __int64)(frameTime * 1000.0));
        if ( v31 != 0 )
        {
          *((_QWORD *)v5 + 5) += v31;
        }
        else
        {
          v32 = HIDWORD(currentTime);
          *((_DWORD *)v5 + 10) = v30;
          *((_DWORD *)v5 + 11) = v32;
        }
      }
      v9 = 1;
      if ( targetHolder != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)targetHolder);
      if ( v52 != 0 )
        GRefCountBaseGC<323>::Release(a1: v52, a2: (int)v5);
      if ( (v50 & 2) == 0 && v48 != 0 )
        GRefCountBaseGC<323>::Release(a1: v48, a2: (int)v5);
      v48 = 0;
      if ( (v50 & 1) == 0 && v49 != 0 )
        GRefCountBaseGC<323>::Release(a1: v49, a2: (int)v5);
      return v9;
    }
    v11 = *((_DWORD *)this + 3);
    if ( v11 != 0 )
      *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
    v12 = *((_DWORD *)this + 3);
    if ( v12 != 0 )
      *(_DWORD *)(v12 + 8) = (*(_DWORD *)(v12 + 8) + 1) & 0x8FFFFFFF;
    v52 = v12;
    if ( v12 != 0 )
    {
      GRefCountBaseGC<323>::Release(a1: v12, a2: (int)this);
      v56 = v12 + 16;
    }
    else
    {
      GWeakPtr<GFxASCharacter>::operator GPtr<GFxASCharacter>(
        a1: (_DWORD **)this + 4,
        a2: &nArgs,
        a3,
        a4: a2,
        a5: v35,
        a6: v36[0]);
      v13 = (GStat::StatValue *)nArgs;
      if ( nArgs != 0 )
      {
        ++*(_DWORD *)(nArgs + 4);
        ++v13->pName;
        v13 = (GStat::StatValue *)nArgs;
      }
      targetHolder = v13;
      if ( v13 == nullptr )
      {
LABEL_26:
        *((_BYTE *)v5 + 56) = 0;
        goto LABEL_27;
      }
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v13);
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v13);
      v14 = *(int (__thiscall **)(GStat::StatValue *))(v13->Type + 112);
      v56 = (int)&v13[7].___u2;
      v57 = (__vc_attributes::iid_isAttribute *)v14(a1: v13);
    }
    if ( v56 != 0 )
    {
      LOBYTE(methodVal[0]) = 0;
      v15 = GFxMovieRoot::GetLevelMovie(this: (GFxMovieRoot *)i, level: 0);
      v16 = (*(int (__thiscall **)(struct GFxSprite *))(*(_DWORD *)v15 + 112))(a1: v15);
      if ( (*(unsigned __int8 (__thiscall **)(int, int, int, GASValue *))(*(_DWORD *)v56 + 44))(
             a1: v56,
             a2: v16 + 120,
             a3: (int)v5 + 20,
             a4: methodVal) != 0 )
      {
        v17 = (const struct GASFunctionRefBase *)GASValue::ToFunction(
                                                   a1: (int)methodVal,
                                                   a2: (int)v5,
                                                   a3: (int)&v45,
                                                   a4: (int)v57);
        GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)&v48, orig: v17);
        if ( (v47 & 2) == 0 && v45 != 0 )
          GRefCountBaseGC<323>::Release(a1: v45, a2: (int)v5);
        v45 = 0;
        if ( (v47 & 1) == 0 && v46 != 0 )
          GRefCountBaseGC<323>::Release(a1: v46, a2: (int)v5);
        v46 = 0;
      }
      GASValue::~GASValue(this: methodVal, a2: (int)v5);
      goto LABEL_27;
    }
    goto LABEL_26;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101085E0
// Name: private: static void GASIntervalTimer::Set(class GASFnCall const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASIntervalTimer::Set(long double a1@<st0>, int a2, bool a3)
{
  char v3; // bl
  int v4; // esi
  GASValue *v5; // edi
  int v6; // edi
  char v7; // al
  int (__thiscall *v8)(int, int, _IMAGE_SYMBOL_EX *); // edx
  GASIntervalTimer *v9; // edi
  struct GASValue *v10; // eax
  const struct GASFunctionRef *v11; // eax
  GASIntervalTimer *v12; // edi
  int (__thiscall *v13)(int, int, int *); // edx
  tagRID_DEVICE_INFO_KEYBOARD *v14; // edi
  unsigned __int8 *v15; // eax
  GASValue *v16; // eax
  GFxAmpMessage *v17; // eax
  unsigned int Short; // eax
  int (__thiscall *v19)(int, int, int *); // edx
  tagRID_DEVICE_INFO_KEYBOARD *v20; // edi
  unsigned __int8 *v21; // eax
  GASValue *v22; // eax
  GRefCountWeakSupportImpl *v23; // eax
  int v25; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v26; // eax
  _DWORD *v27; // ecx
  _DWORD *SectionNumber; // eax
  GFxCharacterHandle *v29; // ebx
  int v30; // ebx
  GASValue *v31; // eax
  double v32; // st7
  int v33; // ebx
  GPtr<IDirect3DPixelShader9> *v34; // edi
  const struct GASFnCall *v35; // eax
  struct GFxMovieRoot *MovieRoot; // ebx
  const struct GASFnCall *v37; // eax
  int v38; // esi
  bool v39; // cf
  double v40; // st7
  int v41; // [esp-8h] [ebp-34h]
  const struct GASEnvironment *v42; // [esp-8h] [ebp-34h]
  const struct GASEnvironment *v43; // [esp-8h] [ebp-34h]
  struct GASStringContext *v44; // [esp-4h] [ebp-30h]
  unsigned int v45; // [esp-4h] [ebp-30h]
  const char *v46; // [esp+0h] [ebp-2Ch]
  int v47; // [esp+4h] [ebp-28h]
  int v48; // [esp+Ch] [ebp-20h] BYREF
  int v49; // [esp+10h] [ebp-1Ch]
  char v50; // [esp+14h] [ebp-18h]
  _IMAGE_SYMBOL_EX v51; // [esp+18h] [ebp-14h] BYREF

  v3 = 0;
  v51.N.Name.Short = 0;
  v4 = a2;
  v5 = *(GASValue **)(a2 + 4);
  GASValue::DropRefs(this: v5, a2: (int)v5);
  *(_BYTE *)v5 = 0;
  if ( *(int *)(v4 + 28) < 2 )
    return;
  v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 24) + 120) + 656);
  a2 = 1;
  v7 = *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0);
  if ( v7 == 8 || v7 == 11 )
  {
    v8 = *(int (__thiscall **)(int, int, _IMAGE_SYMBOL_EX *))(*(_DWORD *)v6 + 40);
    v51.N.Name.Short = 323;
    v9 = (GASIntervalTimer *)v8(a1: v6, a2: 64, a3: &v51);
    if ( v9 != nullptr )
    {
      v44 = (struct GASStringContext *)(*(_DWORD *)(v4 + 24) + 120);
      v41 = *(_DWORD *)(v4 + 24);
      v3 = 1;
      v10 = GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0);
      v11 = (const struct GASFunctionRef *)GASValue::ToFunction(a1: (int)v10, a2: (int)v9, a3: (int)&v48, a4: v41);
      v12 = GASIntervalTimer::GASIntervalTimer(this: v9, a2: v11, psc: v44);
      *(_DWORD *)&v51.Type = v12;
    }
    else
    {
      *(_DWORD *)&v51.Type = 0;
      v12 = nullptr;
    }
    if ( (v3 & 1) != 0 )
    {
      if ( (v50 & 2) == 0 && v48 != 0 )
        GRefCountBaseGC<323>::Release(a1: v48, a2: (int)v12);
      v48 = 0;
      if ( (v50 & 1) == 0 && v49 != 0 )
        GRefCountBaseGC<323>::Release(a1: v49, a2: (int)v12);
      v49 = 0;
    }
    goto LABEL_30;
  }
  if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0) != 6 )
  {
    if ( *(_BYTE *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0) != 7 )
      return;
    v19 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
    a2 = 323;
    v51.N.Name.Long = v19(a1: v6, a2: 64, a3: &a2);
    if ( v51.N.Name.Long != 0 )
    {
      v20 = *(tagRID_DEVICE_INFO_KEYBOARD **)(v4 + 24);
      v3 = 4;
      v21 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 1);
      GASValue::ToStringImpl(this: v21, a2: (int *)&v51, a3: v20, precision: -1, debug: false);
      v43 = *(const struct GASEnvironment **)(v4 + 24);
      v22 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0);
      GASValue::ToASCharacter(this: v22, penv: v43);
      *(_DWORD *)&v51.Type = GASIntervalTimer::GASIntervalTimer(
                               this: (_BYTE *)v51.N.Name.Long,
                               result: v23,
                               methodName: &v51);
    }
    else
    {
      *(_DWORD *)&v51.Type = 0;
    }
    if ( (v3 & 4) == 0 )
      goto LABEL_29;
    Short = v51.N.Name.Short;
    goto LABEL_27;
  }
  v13 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v6 + 40);
  a2 = 323;
  v51.N.Name.Short = v13(a1: v6, a2: 64, a3: &a2);
  if ( v51.N.Name.Short != 0 )
  {
    v14 = *(tagRID_DEVICE_INFO_KEYBOARD **)(v4 + 24);
    v3 = 2;
    v15 = (unsigned __int8 *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 1);
    GASValue::ToStringImpl(this: v15, a2: (int *)&v51.N.Name.Long, a3: v14, precision: -1, debug: false);
    v42 = *(const struct GASEnvironment **)(v4 + 24);
    v16 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v4, a2: 0);
    v17 = (GFxAmpMessage *)GASValue::ToObject(this: v16, a2: (int)v14, a3: v42);
    *(_DWORD *)&v51.Type = GASIntervalTimer::GASIntervalTimer(
                             this: (GFxAmpMessageSourceFile *)v51.N.Name.Short,
                             object: v17,
                             methodName: (_IMAGE_SYMBOL_EX *)&v51.N.LongName[1]);
  }
  else
  {
    *(_DWORD *)&v51.Type = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    Short = v51.N.Name.Long;
LABEL_27:
    if ( (*(_DWORD *)(Short + 8))-- == 1 )
      GASStringNode::ReleaseNode(a1: Short);
  }
LABEL_29:
  v12 = *(GASIntervalTimer **)&v51.Type;
  a2 = 2;
LABEL_30:
  if ( *(_DWORD *)(v4 + 28) > a2 )
  {
    v25 = *(_DWORD *)(*(_DWORD *)(v4 + 24) + 116);
    if ( v25 != 0 )
    {
      v26 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)(*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v25 + 104))(a1: v25, a2: 0);
      v27 = (_DWORD *)DWORD1(v26[6].m_pfnProxied);
      if ( v27 != nullptr )
      {
        v51.SectionNumber = DWORD1(v26[6].m_pfnProxied);
        SectionNumber = v27;
      }
      else
      {
        GFxASCharacter::CreateCharacterHandle(this: v26);
        v51.SectionNumber = (int)SectionNumber;
      }
      if ( SectionNumber != nullptr )
        ++*SectionNumber;
      v29 = *((GFxCharacterHandle **)v12 + 13);
      if ( v29 != nullptr )
      {
        *v29 = (GFxCharacterHandle)((char *)*v29 - 1);
        if ( (int)*v29 <= 0 )
        {
          GFxCharacterHandle::~GFxCharacterHandle(this: v29);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v29);
          SectionNumber = (_DWORD *)v51.SectionNumber;
        }
      }
      *((_DWORD *)v12 + 13) = SectionNumber;
    }
    v30 = a2;
    v31 = (GASValue *)GASFnCall::Arg(this: (GASFnCall *)v4, a2);
    v32 = GASValue::ToNumber(this: v31, a2: (int)v12, a3: a1, result: (_SERVICE_STATUS *)*(_DWORD *)(v4 + 24));
    v33 = v30 + 1;
    *((_BYTE *)v12 + 57) = a3;
    *(_QWORD *)&v51.Value = (__int64)v32;
    *((_DWORD *)v12 + 9) = (__int64)v32;
    if ( v33 < *(_DWORD *)(v4 + 28) )
    {
      v34 = (GPtr<IDirect3DPixelShader9> *)((char *)v12 + 24);
      do
      {
        v35 = GASFnCall::Arg(this: (GASFnCall *)v4, a2: v33);
        v45 = (unsigned int)&v34[1].pObject->__vftable + 1;
        a2 = (int)v35;
        GArrayDataBase<GASValue,GAllocatorGH<GASValue,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
          this: v34,
          pheapAddr: (ButtonCode_t)v34,
          newSize: v45);
        if ( &v34->pObject[4 * (int)v34[1].pObject] != (IDirect3DPixelShader9 *)16 )
          GASValue::GASValue(this: (GASValue *)&v34->pObject[4 * (int)v34[1].pObject - 4], v: (tagWNDCLASSW *)a2);
        ++v33;
      }
      while ( v33 < *(_DWORD *)(v4 + 28) );
      v12 = *(GASIntervalTimer **)&v51.Type;
    }
    MovieRoot = GASEnvironment::GetMovieRoot(this: *(GASEnvironment **)(v4 + 24));
    v37 = (const struct GASFnCall *)GFxMovieRoot::AddIntervalTimer(
                                      a1: MovieRoot,
                                      timer: (unsigned int)v12,
                                      a3: v46,
                                      a4: v47);
    v38 = *(_DWORD *)(v4 + 4);
    v39 = *(_BYTE *)v38 < 5u;
    a2 = (int)v37;
    if ( !v39 )
      GASValue::DropRefs(this: (GASValue *)v38, a2: (int)v12);
    v40 = (double)a2;
    *(_BYTE *)v38 = 3;
    *(double *)(v38 + 4) = v40;
    *((_QWORD *)v12 + 5) = *((_QWORD *)MovieRoot + 36) + *((unsigned int *)v12 + 9);
  }
  else if ( v12 != nullptr )
  {
    GASIntervalTimer::~GASIntervalTimer(this: v12);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108940
// Name: public: static void GASIntervalTimer::SetInterval(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASIntervalTimer::SetInterval(long double a1@<st0>, const struct GASFnCall *a2)
{
  GASIntervalTimer::Set(a1, (int)a2, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10108960
// Name: public: static void GASIntervalTimer::SetTimeout(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __usercall GASIntervalTimer::SetTimeout(long double a1@<st0>, const struct GASFnCall *a2)
{
  GASIntervalTimer::Set(a1, (int)a2, a3: true);
}
