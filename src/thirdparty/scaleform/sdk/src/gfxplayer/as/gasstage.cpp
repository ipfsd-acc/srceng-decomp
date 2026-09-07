// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/as/gasstage.cpp
// Functions: 11
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\as\gasstage.h"

//------------------------------------------------------------------------------
// Address: 0x10113D30
// Name: public: virtual bool GASStageCtorFunction::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStageCtorFunction::SetMemberRaw(
        GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *this,
        _IMAGE_SYMBOL_EX *name,
        _EXIT_THREAD_DEBUG_INFO *a3,
        tagWNDCLASSW *val,
        const struct GASPropFlags *flags)
{
  unsigned int Short; // esi
  int *dwExitCode; // ecx
  bool v7; // zf
  unsigned int v8; // esi
  bool v9; // zf

  Short = name->N.Name.Short;
  dwExitCode = (int *)a3->dwExitCode;
  if ( name->N.ShortName[4] <= 6u )
  {
    if ( dwExitCode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: dwExitCode);
    dwExitCode = (int *)a3->dwExitCode;
    v7 = *(_DWORD *)(*(_DWORD *)(Short + 512) + 4) == *(_DWORD *)(a3->dwExitCode + 4);
  }
  else
  {
    v7 = *(_DWORD *)(Short + 512) == (_DWORD)dwExitCode;
  }
  if ( !v7 )
  {
    v8 = name->N.Name.Short;
    if ( name->N.ShortName[4] <= 6u )
    {
      if ( dwExitCode[1] == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: dwExitCode);
      v9 = *(_DWORD *)(*(_DWORD *)(v8 + 516) + 4) == *(_DWORD *)(a3->dwExitCode + 4);
    }
    else
    {
      v9 = *(_DWORD *)(v8 + 516) == (_DWORD)dwExitCode;
    }
    if ( !v9 )
      GASObject::SetMemberRaw(
        (GASObject *)this,
        a2: (struct GASStringContext *)name,
        a3,
        a4: (GASValue *)val,
        a5: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113DD0
// Name: public: virtual bool GASStageCtorFunction::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStageCtorFunction::GetMemberRaw(
        GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *this,
        _IMAGE_SYMBOL_EX *psc,
        int **a3,
        GASValue *a4)
{
  unsigned int Short; // esi
  int *v5; // ecx
  bool v6; // zf
  double v7; // st7
  int v8; // edi
  unsigned int v9; // esi
  bool v10; // zf
  bool v11; // bl
  int *ConstStringNode; // eax
  int v13; // esi
  bool v14; // zf
  bool v15; // bl
  int v16; // eax
  int v17; // eax
  char *p_m_Size; // edx
  struct GASStringNode *v19; // esi
  bool v20; // bl
  int *v21; // eax
  int v22; // esi
  bool v23; // zf
  bool v24; // bl
  float v26; // [esp+1Ch] [ebp+Ch]
  float v27; // [esp+1Ch] [ebp+Ch]
  float v28; // [esp+1Ch] [ebp+Ch]
  float v29; // [esp+1Ch] [ebp+Ch]

  Short = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( (*a3)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *a3);
    v5 = *a3;
    v6 = *(_DWORD *)(*(_DWORD *)(Short + 512) + 4) == (*a3)[1];
  }
  else
  {
    v5 = *a3;
    v6 = *(_DWORD *)(Short + 512) == (_DWORD)*a3;
  }
  if ( v6 )
  {
    v26 = *(float *)(*((_DWORD *)this + 10) + 152) - *(float *)(*((_DWORD *)this + 10) + 144);
    v27 = v26 / 20.0;
    v7 = v27;
LABEL_8:
    v8 = (int)v7;
    if ( *(_BYTE *)a4 >= 5u )
      GASValue::DropRefs(this: a4, a2: v8);
    *((_DWORD *)a4 + 1) = v8;
    *(_BYTE *)a4 = 4;
    return;
  }
  v9 = psc->N.Name.Short;
  if ( psc->N.ShortName[4] <= 6u )
  {
    if ( v5[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v5);
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 516) + 4) == (*a3)[1];
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 516) == (_DWORD)v5;
  }
  if ( v10 )
  {
    v28 = *(float *)(*((_DWORD *)this + 10) + 156) - *(float *)(*((_DWORD *)this + 10) + 148);
    v29 = v28 / 20.0;
    v7 = v29;
    goto LABEL_8;
  }
  v11 = psc->N.ShortName[4] > 6u;
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(psc->N.Name.Short + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"scaleMode",
                             a3: 9u,
                             a4: 0);
  v13 = (int)ConstStringNode;
  ++ConstStringNode[2];
  if ( v11 )
  {
    v14 = ConstStringNode == *a3;
  }
  else
  {
    if ( ConstStringNode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    if ( (*a3)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *a3);
    v14 = *(_DWORD *)(v13 + 4) == (*a3)[1];
  }
  v15 = v14;
  v6 = (*(_DWORD *)(v13 + 8))-- == 1;
  if ( v6 )
    GASStringNode::ReleaseNode(a1: v13);
  if ( v15 )
  {
    v16 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 112))(a1: *((_DWORD *)this + 10));
    if ( v16 != 0 )
    {
      v17 = v16 - 2;
      if ( v17 != 0 )
      {
        if ( v17 == 1 )
          p_m_Size = (char *)&stru_102A53F4;
        else
          p_m_Size = (char *)&stru_102A53F4.m_Size;
      }
      else
      {
        p_m_Size = (char *)&stru_102A53D8.m_pElements;
      }
    }
    else
    {
      p_m_Size = (char *)&stru_102A53D8.m_Memory.m_nGrowSize;
    }
  }
  else
  {
    v20 = psc->N.ShortName[4] > 6u;
    v21 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(psc->N.Name.Short + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
                   a3: 5u,
                   a4: 0);
    v22 = (int)v21;
    ++v21[2];
    if ( v20 )
    {
      v23 = v21 == *a3;
    }
    else
    {
      if ( v21[1] == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: v21);
      if ( (*a3)[1] == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: *a3);
      v23 = *(_DWORD *)(v22 + 4) == (*a3)[1];
    }
    v24 = v23;
    v6 = (*(_DWORD *)(v22 + 8))-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode(a1: v22);
    if ( !v24 )
    {
      GASObject::GetMemberRaw((CTSQueue<CFunctor *,0,1> *)this, psc, ikey: (_EXIT_THREAD_DEBUG_INFO *)a3, a4);
      return;
    }
    switch ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 120))(a1: *((_DWORD *)this + 10)) )
    {
      case 1:
        p_m_Size = "T";
        break;
      case 2:
        p_m_Size = "B";
        break;
      case 3:
        p_m_Size = "L";
        break;
      case 4:
        p_m_Size = "R";
        break;
      case 5:
        p_m_Size = "LT";
        break;
      case 6:
        p_m_Size = "TR";
        break;
      case 7:
        p_m_Size = "LB";
        break;
      case 8:
        p_m_Size = "RB";
        break;
      default:
        p_m_Size = (char *)&pMem;
        break;
    }
  }
  v19 = GASStringManager::CreateConstStringNode(
          this: *(GASStringManager **)(psc->N.Name.Short + 636),
          result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)p_m_Size,
          a3: strlen(p_m_Size),
          a4: 0);
  ++*((_DWORD *)v19 + 2);
  if ( *(_BYTE *)a4 >= 5u )
    GASValue::DropRefs(this: a4, a2: (int)a4);
  *(_BYTE *)a4 = 5;
  *((_DWORD *)a4 + 1) = v19;
  v6 = ++*((_DWORD *)v19 + 2) == 1;
  --*((_DWORD *)v19 + 2);
  if ( v6 )
    GASStringNode::ReleaseNode(a1: (int)v19);
}

//------------------------------------------------------------------------------
// Address: 0x101140D0
// Name: public: GASStageCtorFunction::GASStageCtorFunction(class GASStringContext __near *,class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *__thiscall GASStageCtorFunction::GASStageCtorFunction(
        int this,
        _REASON_CONTEXT *result,
        struct GASStringNode *psc_4)
{
  struct GASStringContext *v3; // esi
  struct GASStringNode *v5; // eax
  int v6; // edi
  _EXIT_THREAD_DEBUG_INFO *v7; // ecx
  int v8; // eax
  bool v9; // zf
  _EXIT_THREAD_DEBUG_INFO *v10; // eax
  int v11; // eax
  _EXIT_THREAD_DEBUG_INFO *v12; // eax
  int v13; // eax
  void *v14; // ecx
  _EXIT_THREAD_DEBUG_INFO *v16; // [esp-Ch] [ebp-28h]
  _EXIT_THREAD_DEBUG_INFO *v17; // [esp-Ch] [ebp-28h]
  tagMSG v18; // [esp-8h] [ebp-24h] BYREF
  struct GASObjectInterface *v19; // [esp+14h] [ebp-8h]

  v3 = (struct GASStringContext *)result;
  GASCFunctionObject::GASCFunctionObject(
    (GASCFunctionObject *)this,
    func: result,
    a3: (void (__cdecl *)(const struct GASFnCall *))GASMouseCtorFunction::GlobalCtor);
  v5 = psc_4;
  v6 = this + 16;
  v18.message = this + 16;
  v18.hwnd = (HWND__ *)v3;
  *(_DWORD *)this = &GASStageCtorFunction::`vftable'{for `GASRefCountBase<GASObject>'};
  *(_DWORD *)(this + 16) = &stru_102A5414.m_Size;
  *(_DWORD *)(this + 56) = v5;
  GASAsBroadcaster::Initialize(pobj: v18, a2: v19);
  v16 = (_EXIT_THREAD_DEBUG_INFO *)(*(_DWORD *)v3 + 512);
  HIBYTE(result) = 0;
  LOBYTE(v18.pt.x) = 10;
  GASObject::SetMemberRaw(
    this: (GASObject *)(this + 16),
    a2: v3,
    a3: v16,
    a4: (GASValue *)&v18.pt,
    a5: (const struct GASPropFlags *)((char *)&result + 3));
  GASValue::~GASValue(this: (GASValue *)&v18.pt, a2: this + 16);
  v17 = (_EXIT_THREAD_DEBUG_INFO *)(*(_DWORD *)v3 + 516);
  HIBYTE(result) = 0;
  LOBYTE(v18.pt.x) = 10;
  GASObject::SetMemberRaw(
    this: (GASObject *)(this + 16),
    a2: v3,
    a3: v17,
    a4: (GASValue *)&v18.pt,
    a5: (const struct GASPropFlags *)((char *)&result + 3));
  GASValue::~GASValue(this: (GASValue *)&v18.pt, a2: this + 16);
  v7 = *(_EXIT_THREAD_DEBUG_INFO **)v3;
  LOBYTE(v18.pt.x) = 10;
  HIBYTE(result) = 0;
  psc_4 = GASStringManager::CreateConstStringNode(
            this: (GASStringManager *)v7[159].dwExitCode,
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"scaleMode",
            a3: 9u,
            a4: 0);
  ++*((_DWORD *)psc_4 + 2);
  (*(void (__thiscall **)(int, struct GASStringContext *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)(this + 16) + 40))(
    a1: this + 16,
    a2: v3,
    a3: &psc_4,
    a4: &v18.pt,
    a5: (char *)&result + 3);
  v8 = (int)psc_4;
  v9 = (*((_DWORD *)psc_4 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  GASValue::~GASValue(this: (GASValue *)&v18.pt, a2: v6);
  v10 = *(_EXIT_THREAD_DEBUG_INFO **)v3;
  LOBYTE(v18.pt.x) = 10;
  HIBYTE(result) = 0;
  psc_4 = GASStringManager::CreateConstStringNode(
            this: (GASStringManager *)v10[159].dwExitCode,
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
            a3: 5u,
            a4: 0);
  ++*((_DWORD *)psc_4 + 2);
  (*(void (__thiscall **)(int, struct GASStringContext *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v6 + 40))(
    a1: this + 16,
    a2: v3,
    a3: &psc_4,
    a4: &v18.pt,
    a5: (char *)&result + 3);
  v11 = (int)psc_4;
  v9 = (*((_DWORD *)psc_4 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v11);
  GASValue::~GASValue(this: (GASValue *)&v18.pt, a2: v6);
  v12 = *(_EXIT_THREAD_DEBUG_INFO **)v3;
  LOBYTE(v18.pt.x) = 2;
  LOBYTE(v18.pt.y) = 1;
  HIBYTE(result) = 0;
  psc_4 = GASStringManager::CreateConstStringNode(
            this: (GASStringManager *)v12[159].dwExitCode,
            result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5414,
            a3: 8u,
            a4: 0);
  ++*((_DWORD *)psc_4 + 2);
  (*(void (__thiscall **)(int, struct GASStringContext *, struct GASStringNode **, tagPOINT *, char *))(*(_DWORD *)v6 + 40))(
    a1: this + 16,
    a2: v3,
    a3: &psc_4,
    a4: &v18.pt,
    a5: (char *)&result + 3);
  v13 = (int)psc_4;
  v9 = (*((_DWORD *)psc_4 + 2))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v13);
  GASValue::~GASValue(this: (GASValue *)&v18.pt, a2: v6);
  GASNameFunction::AddConstMembers(
    pobj: v14,
    psc: this + 16,
    psca: (CTSQueue<CFunctor *,0,1>::Node_t *)v3,
    a4: (struct GASObject **)GASStageCtorFunction::StaticFunctionTable,
    a5: 7);
  return (const GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10114270
// Name: private: virtual void GASStageCtorFunction::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStageCtorFunction::Finalize_GC(GArrayLH<GPtr<GFxAmpServer::ViewStats>,2,GArrayDefaultPolicy> *this)
{
  *((_DWORD *)this + 14) = 0;
  GASObject::Finalize_GC((GASObject *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10114280
// Name: private: static void GASStageCtorFunction::TranslateToScreen(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStageCtorFunction::TranslateToScreen(GASFnCall *a1)
{
  GASFnCall v2; // esi
  struct GASObject *v3; // edi
  tagWNDCLASSW *v4; // eax
  struct GASObject *v5; // eax
  int v6; // edi
  long double v7; // st7
  double v8; // st7
  GASEnvironment *v9; // ecx
  struct GFxMovieRoot *MovieRoot; // eax
  struct GASObject *v11; // eax
  double v12[2]; // [esp+Ch] [ebp-54h] BYREF
  GASValue v13[4]; // [esp+1Ch] [ebp-44h] BYREF
  GASValue v14[4]; // [esp+2Ch] [ebp-34h] BYREF
  GASValue v15[4]; // [esp+3Ch] [ebp-24h] BYREF
  float v16[2]; // [esp+4Ch] [ebp-14h] BYREF
  float v17[2]; // [esp+54h] [ebp-Ch] BYREF
  float v18; // [esp+5Ch] [ebp-4h]
  float v19; // [esp+68h] [ebp+8h]

  v2 = a1[6];
  v3 = nullptr;
  if ( (int)a1[7] >= 0 )
  {
    LOBYTE(v14[0]) = 4;
    v14[1] = nullptr;
    LOBYTE(v15[0]) = 4;
    v15[1] = nullptr;
    v4 = (tagWNDCLASSW *)GASFnCall::Arg(this: a1, a2: 0);
    GASValue::GASValue(this: v13, v: v4);
    v5 = GASValue::ToObject(this: v13, a2: 0, a3: (const struct GASEnvironment *)v2);
    if ( v5 != nullptr )
    {
      v6 = (int)&v5[2];
      ((void (__thiscall *)(struct GASObject *, GASFnCall, unsigned int, GASValue *))v5[2].pNode[2].pNext)(
        a1: &v5[2],
        a2: v2,
        a3: v2[3].cbSize + 524,
        a4: v14);
      v7 = ((double (__thiscall *)(int, GASFnCall, unsigned int, GASValue *))*(_DWORD *)(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: v2,
             a3: v2[3].cbSize + 528,
             a4: v15);
      v8 = GASValue::ToNumber(this: v14, a2: v6, a3: v7, result: (_SERVICE_STATUS *)v2);
      v19 = v8;
      v18 = GASValue::ToNumber(this: v15, a2: v6, a3: v8, result: (_SERVICE_STATUS *)v2);
      v9 = (GASEnvironment *)a1[6];
      v17[0] = v19;
      v17[1] = v18;
      MovieRoot = GASEnvironment::GetMovieRoot(this: v9);
      (*(void (__thiscall **)(struct GFxMovieRoot *, float *, float *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)MovieRoot + 256))(
        a1: MovieRoot,
        a2: v16,
        a3: v17,
        a4: LODWORD(GMatrix2D::Identity.M_[0][0]),
        a5: LODWORD(GMatrix2D::Identity.M_[0][1]),
        a6: LODWORD(GMatrix2D::Identity.M_[0][2]),
        a7: LODWORD(GMatrix2D::Identity.M_[1][0]),
        a8: LODWORD(GMatrix2D::Identity.M_[1][1]),
        a9: LODWORD(GMatrix2D::Identity.M_[1][2]));
      v11 = GASEnvironment::OperatorNew(
              this: (__vc_attributes::idl_quoteAttribute *)a1[6],
              a2: v6,
              a3: *(struct GASObject **)(v2[3].cbSize + 660),
              a4: (const struct GASString *)(a1[6][3].cbSize + 64),
              nargs: 0,
              argsTopOff: -1);
      v12[0] = v16[0];
      v3 = v11;
      v12[1] = v16[1];
      GASPointObject::SetProperties(a1: v2, a2: v12);
      GASValue::SetAsObject(this: (GASValue *)a1[1], a2: v3);
      if ( v3 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v3, a2: (int)v3);
    }
    GASValue::~GASValue(this: v13, a2: (int)v3);
    GASValue::~GASValue(this: v15, a2: (int)v3);
    GASValue::~GASValue(this: v14, a2: (int)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101143E0
// Name: private: static class GASValue GASStageCtorFunction::CreateRectangleObject(class GASEnvironment __near *,class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
GASValue *__thiscall GASStageCtorFunction::CreateRectangleObject(
        void *penv,
        GASValue *a2,
        __vc_attributes::idl_quoteAttribute *penva,
        float *rect)
{
  struct GASObject *v4; // esi
  double v5; // st6
  double v6; // st5
  double v7; // st7
  int v9; // [esp+0h] [ebp-2Ch]
  double v10[4]; // [esp+Ch] [ebp-20h] BYREF

  *(_BYTE *)a2 = 0;
  v4 = GASEnvironment::OperatorNew(
         this: penva,
         a2: (int)penva,
         a3: *((struct GASObject **)penva[30].text + 165),
         a4: (const struct GASString *)(penva[30].text + 68),
         nargs: 0,
         argsTopOff: -1);
  v5 = rect[1];
  v6 = rect[2];
  v7 = rect[3];
  v10[0] = *rect;
  v10[1] = v5;
  v10[2] = v6;
  v10[3] = v7;
  GASRectangleObject::SetProperties(penv: (unsigned int)penva, r: (GMemoryHeap *)v10, a3: v9);
  GASValue::SetAsObject(this: a2, a2: v4);
  if ( v4 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v4, a2: (int)penva);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10114460
// Name: public: virtual bool GASStageCtorFunction::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStageCtorFunction::GetMember(
        GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *this,
        GASEnvironment *penv,
        int **name,
        int *a4)
{
  unsigned __int64 *v5; // eax
  bool v6; // bl
  int *ConstStringNode; // eax
  int v8; // edi
  bool v9; // zf
  bool v10; // bl
  struct GFxMovieRoot *MovieRoot; // eax
  tagWNDCLASSW *v12; // eax
  bool v13; // bl
  int *v14; // eax
  bool v15; // zf
  bool v16; // bl
  struct GFxMovieRoot *v17; // eax
  struct GFxMovieRoot *v18; // eax
  int v19; // eax
  bool v20; // bl
  int *v21; // eax
  int v22; // edi
  bool v23; // zf
  bool v24; // bl
  struct GFxMovieRoot *v25; // eax
  int v26; // eax
  tagWNDCLASSW *v27; // eax
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> origRect; // [esp+Ch] [ebp-24h] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> safeRect; // [esp+1Ch] [ebp-14h] BYREF
  D3DXQUATERNION *v30; // [esp+28h] [ebp-8h]
  D3DXQUATERNION *v31; // [esp+2Ch] [ebp-4h]
  int penva; // [esp+38h] [ebp+8h]
  int namea; // [esp+3Ch] [ebp+Ch]

  v5 = *((unsigned __int64 **)penv + 30);
  v9 = *((_BYTE *)v5 + 684) == 1;
  v31 = (D3DXQUATERNION *)this;
  if ( !v9 )
    goto LABEL_38;
  v6 = *((_BYTE *)penv + 124) > 6u;
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *((GASStringManager **)v5 + 159),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"visibleRect",
                             a3: 0xBu,
                             a4: 0);
  v8 = (int)ConstStringNode;
  ++ConstStringNode[2];
  if ( v6 )
  {
    v9 = ConstStringNode == *name;
  }
  else
  {
    if ( ConstStringNode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    if ( (*name)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *name);
    v9 = *(_DWORD *)(v8 + 4) == (*name)[1];
  }
  v10 = v9;
  v9 = (*(_DWORD *)(v8 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  if ( v10 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: penv);
    (*(void (__thiscall **)(struct GFxMovieRoot *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)MovieRoot + 124))(
      a1: MovieRoot,
      a2: &safeRect);
LABEL_13:
    v12 = (tagWNDCLASSW *)GASStageCtorFunction::CreateRectangleObject(
                            penv: &origRect,
                            a2: (GASValue *)&origRect,
                            penva: (__vc_attributes::idl_quoteAttribute *)penv,
                            rect: (float *)&safeRect);
    GASValue::operator=(this: (int)a4, v: v12);
    GASValue::~GASValue(this: (GASValue *)&origRect, a2: v8);
    return;
  }
  v13 = *((_BYTE *)penv + 124) > 6u;
  v14 = (int *)GASStringManager::CreateConstStringNode(
                 this: *(GASStringManager **)(*((_DWORD *)penv + 30) + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5514.m_pElements,
                 a3: 8u,
                 a4: 0);
  v8 = (int)v14;
  ++v14[2];
  if ( v13 )
  {
    v15 = v14 == *name;
  }
  else
  {
    if ( v14[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v14);
    if ( (*name)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *name);
    v15 = *(_DWORD *)(v8 + 4) == (*name)[1];
  }
  v16 = v15;
  v9 = (*(_DWORD *)(v8 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v8);
  if ( v16 )
  {
    v17 = GASEnvironment::GetMovieRoot(this: penv);
    (*(void (__thiscall **)(struct GFxMovieRoot *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v17 + 136))(
      a1: v17,
      a2: &safeRect);
    if ( *(float *)&safeRect.m_nGrowSize <= (double)*(float *)&safeRect.m_pMemory
      || *(float *)&v30 <= (double)*(float *)&safeRect.m_nAllocationCount )
    {
      v18 = GASEnvironment::GetMovieRoot(this: penv);
      v19 = (*(int (__thiscall **)(struct GFxMovieRoot *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v18 + 124))(
              a1: v18,
              a2: &origRect);
      namea = *(int *)(v19 + 4);
      penva = *(int *)(v19 + 8);
      v31 = *(D3DXQUATERNION **)(v19 + 12);
      safeRect.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v19;
      safeRect.m_nAllocationCount = namea;
      safeRect.m_nGrowSize = penva;
      v30 = v31;
    }
    goto LABEL_13;
  }
  v20 = *((_BYTE *)penv + 124) > 6u;
  v21 = (int *)GASStringManager::CreateConstStringNode(
                 this: *(GASStringManager **)(*((_DWORD *)penv + 30) + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5514,
                 a3: 0xCu,
                 a4: 0);
  v22 = (int)v21;
  ++v21[2];
  if ( v20 )
  {
    v23 = v21 == *name;
  }
  else
  {
    if ( v21[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v21);
    if ( (*name)[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: *name);
    v23 = *(_DWORD *)(v22 + 4) == (*name)[1];
  }
  v24 = v23;
  v9 = (*(_DWORD *)(v22 + 8))-- == 1;
  if ( v9 )
    GASStringNode::ReleaseNode(a1: v22);
  if ( v24 )
  {
    v25 = GASEnvironment::GetMovieRoot(this: penv);
    v26 = (*(int (__thiscall **)(struct GFxMovieRoot *))(*(_DWORD *)v25 + 4))(a1: v25);
    (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v26 + 40))(
      a1: v26,
      a2: &origRect);
    v27 = (tagWNDCLASSW *)GASStageCtorFunction::CreateRectangleObject(
                            penv: &safeRect,
                            a2: (GASValue *)&safeRect,
                            penva: (__vc_attributes::idl_quoteAttribute *)penv,
                            rect: (float *)&origRect);
    GASValue::operator=(this: (int)a4, v: v27);
    GASValue::~GASValue(this: (GASValue *)&safeRect, a2: v22);
  }
  else
  {
LABEL_38:
    GASObject::GetMember(this: v31, result: (ID3DXFont *)penv, penv: (_IMAGE_SYMBOL_EX *)name, val: a4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114760
// Name: public: void GASStageCtorFunction::NotifyOnResize(class GASEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASStageCtorFunction::NotifyOnResize(GASStageCtorFunction *this, struct GASEnvironment *a2)
{
  struct GASEnvironment *v2; // edi
  int v3; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  GASValue *v6; // ecx
  int v7; // ebx
  struct GASStringNode *ConstStringNode; // eax
  _IMAGE_SYMBOL_EX *v9; // ecx
  int v10; // eax
  bool v11; // zf
  _IMAGE_SYMBOL_EX *v12; // esi
  struct GASEnvironment *v13; // eax
  float v14[4]; // [esp+Ch] [ebp-24h] BYREF
  unsigned int penv[4]; // [esp+1Ch] [ebp-14h] BYREF
  struct GASStringNode *v16; // [esp+2Ch] [ebp-4h] BYREF

  v2 = a2;
  v3 = *((_DWORD *)a2 + 30);
  if ( *(_BYTE *)(v3 + 684) == 1 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)a2);
    (*(void (__thiscall **)(struct GFxMovieRoot *, float *))(*(_DWORD *)MovieRoot + 124))(a1: MovieRoot, a2: v14);
    GASStageCtorFunction::CreateRectangleObject(
      penv,
      a2: (GASValue *)penv,
      penva: (__vc_attributes::idl_quoteAttribute *)v2,
      rect: v14);
    *((_DWORD *)v2 + 2) += 16;
    if ( *((_DWORD *)v2 + 2) >= *((_DWORD *)v2 + 4) )
      GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)v2 + 2);
    v6 = *((GASValue **)v2 + 2);
    if ( v6 != nullptr )
      GASValue::GASValue(this: v6, v: (tagWNDCLASSW *)penv);
    if ( this != nullptr )
      a2 = (struct GASEnvironment *)(this + 4);
    else
      a2 = nullptr;
    v7 = ((*((_DWORD *)v2 + 2) - *((_DWORD *)v2 + 3)) >> 4) + 32 * *((_DWORD *)v2 + 7) - 32;
    ConstStringNode = GASStringManager::CreateConstStringNode(
                        this: *(GASStringManager **)(*((_DWORD *)v2 + 30) + 636),
                        result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5594,
                        a3: 8u,
                        a4: 0);
    v9 = (_IMAGE_SYMBOL_EX *)a2;
    v16 = ConstStringNode;
    ++*((_DWORD *)ConstStringNode + 2);
    GASAsBroadcaster::BroadcastMessage(
      a1: v2,
      eventName: v9,
      a3: (const struct GASString *)&v16,
      nArgs: 1,
      firstArgBottomIndex: v7);
    v10 = (int)v16;
    v11 = (*((_DWORD *)v16 + 2))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: v10);
    GASValue::~GASValue(this: *((GASValue **)v2 + 2), a2: (int)v2);
    *((_DWORD *)v2 + 2) -= 16;
    if ( *((_DWORD *)v2 + 2) < *((_DWORD *)v2 + 3) )
      GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v2 + 2);
    GASValue::~GASValue(this: (GASValue *)penv, a2: (int)v2);
  }
  else
  {
    if ( this != nullptr )
      v12 = (_IMAGE_SYMBOL_EX *)(this + 4);
    else
      v12 = nullptr;
    a2 = GASStringManager::CreateConstStringNode(
           this: *(GASStringManager **)(v3 + 636),
           result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A5594,
           a3: 8u,
           a4: 0);
    ++*((_DWORD *)a2 + 2);
    GASAsBroadcaster::BroadcastMessage(
      a1: v2,
      eventName: v12,
      a3: (const struct GASString *)&a2,
      nArgs: 0,
      firstArgBottomIndex: 0);
    v13 = a2;
    v11 = (*((_DWORD *)a2 + 2))-- == 1;
    if ( v11 )
      GASStringNode::ReleaseNode(a1: (int)v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101148B0
// Name: public: static void GASStageCtorFunction::NotifyOnResize(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GASStageCtorFunction::NotifyOnResize(const struct GASFnCall *a1)
{
  int v1; // eax
  int v2; // ecx
  int v3; // edi
  struct GASObject *v4; // eax
  struct GASObject *v5; // eax
  GASValue v6[4]; // [esp+Ch] [ebp-10h] BYREF

  v1 = *((_DWORD *)a1 + 6) + 120;
  LOBYTE(v6[0]) = 0;
  v2 = *(_DWORD *)(*(_DWORD *)v1 + 680);
  v3 = *(_DWORD *)(v2 + 16);
  if ( (*(unsigned __int8 (__thiscall **)(int, int, int, GASValue *))(v3 + 44))(
         a1: v2 + 16,
         a2: v1,
         a3: *(_DWORD *)v1 + 80,
         a4: v6) != 0
    && LOBYTE(v6[0]) != 11 )
  {
    v4 = GASValue::ToObject(this: v6, a2: v3, a3: *((const struct GASEnvironment **)a1 + 6));
    if ( v4 != nullptr )
    {
      v5 = v4 + 2;
      if ( v5 != nullptr )
        GASStageCtorFunction::NotifyOnResize(
          this: (GASStageCtorFunction *)&v5[-2],
          a2: *((struct GASEnvironment **)a1 + 6));
    }
  }
  GASValue::~GASValue(this: v6, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10114920
// Name: public: virtual bool GASStageCtorFunction::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GASStageCtorFunction::SetMember(
        GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *this@<ecx>,
        int penv,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        _MODEMSETTINGS flags)
{
  bool v5; // bl
  int *ConstStringNode; // eax
  int v7; // esi
  bool v8; // zf
  _IMAGE_SYMBOL_EX *v9; // ebx
  bool v10; // bl
  int *v11; // eax
  int v12; // esi
  _IMAGE_SYMBOL_EX *v13; // ecx
  bool v14; // bl
  int v15; // esi
  int *v16; // eax
  int v17; // esi
  _IMAGE_SYMBOL_EX *v18; // ecx
  bool v19; // bl
  int *v20; // eax
  int v21; // esi
  _IMAGE_SYMBOL_EX *v22; // ecx
  bool v23; // bl
  _IMAGE_SYMBOL_EX *v24; // eax
  bool v25; // bl
  int *v26; // eax
  int v27; // esi
  bool v28; // zf
  _IMAGE_SYMBOL_EX *v29; // ebx
  bool v30; // bl
  tagWNDCLASSW *v31; // eax
  unsigned int v32; // esi
  unsigned int Length; // edi
  unsigned int CharAt; // ebx

  v5 = *(_BYTE *)(penv + 124) > 6u;
  ConstStringNode = (int *)GASStringManager::CreateConstStringNode(
                             this: *(GASStringManager **)(*(_DWORD *)(penv + 120) + 636),
                             result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)"scaleMode",
                             a3: 9u,
                             a4: 0);
  v7 = (int)ConstStringNode;
  ++ConstStringNode[2];
  if ( v5 )
  {
    v8 = ConstStringNode == (int *)name->N.Name.Short;
  }
  else
  {
    if ( ConstStringNode[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: ConstStringNode);
    v9 = name;
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    v8 = *(_DWORD *)(v7 + 4) == *(_DWORD *)(v9->N.Name.Short + 4);
  }
  v10 = v8;
  v8 = (*(_DWORD *)(v7 + 8))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v7);
  if ( v10 )
  {
    GASValue::ToStringImpl(
      this: (unsigned __int8 *)val,
      a2: (int *)&name,
      a3: (tagRID_DEVICE_INFO_KEYBOARD *)penv,
      precision: -1,
      debug: false);
    val = (tagWNDCLASSW *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 112))(a1: *((_DWORD *)this + 10));
    v11 = (int *)GASStringManager::CreateConstStringNode(
                   this: *(GASStringManager **)(*(_DWORD *)(penv + 120) + 636),
                   result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8.m_Memory.m_nGrowSize,
                   a3: 7u,
                   a4: 0);
    v12 = (int)v11;
    ++v11[2];
    if ( v11[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v11);
    v13 = name;
    if ( name->N.Name.Long == 0 )
    {
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name);
      v13 = name;
    }
    v14 = *(_DWORD *)(v12 + 4) == v13->N.Name.Long;
    v8 = (*(_DWORD *)(v12 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode(a1: v12);
    if ( v14 )
    {
      v15 = 0;
    }
    else
    {
      v16 = (int *)GASStringManager::CreateConstStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(penv + 120) + 636),
                     result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8.m_pElements,
                     a3: 8u,
                     a4: 0);
      v17 = (int)v16;
      ++v16[2];
      if ( v16[1] == 0 )
        GASStringNode::ResolveLowercase_Impl(a1: v16);
      v18 = name;
      if ( name->N.Name.Long == 0 )
      {
        GASStringNode::ResolveLowercase_Impl(a1: (int *)name);
        v18 = name;
      }
      v19 = *(_DWORD *)(v17 + 4) == v18->N.Name.Long;
      v8 = (*(_DWORD *)(v17 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode(a1: v17);
      if ( v19 )
      {
        v15 = 2;
      }
      else
      {
        v20 = (int *)GASStringManager::CreateConstStringNode(
                       this: *(GASStringManager **)(*(_DWORD *)(penv + 120) + 636),
                       result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53F4,
                       a3: 8u,
                       a4: 0);
        v21 = (int)v20;
        ++v20[2];
        if ( v20[1] == 0 )
          GASStringNode::ResolveLowercase_Impl(a1: v20);
        v22 = name;
        if ( name->N.Name.Long == 0 )
        {
          GASStringNode::ResolveLowercase_Impl(a1: (int *)name);
          v22 = name;
        }
        v23 = *(_DWORD *)(v21 + 4) == v22->N.Name.Long;
        v8 = (*(_DWORD *)(v21 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode(a1: v21);
        v15 = 2 * v23 + 1;
      }
    }
    (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 108))(a1: *((_DWORD *)this + 10), a2: v15);
    if ( val != (tagWNDCLASSW *)v15 && v15 == 0 )
      GASStageCtorFunction::NotifyOnResize(this: (GASStageCtorFunction *)this - 4, a2: (struct GASEnvironment *)penv);
    goto LABEL_37;
  }
  v25 = *(_BYTE *)(penv + 124) > 6u;
  v26 = (int *)GASStringManager::CreateConstStringNode(
                 this: *(GASStringManager **)(*(_DWORD *)(penv + 120) + 636),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&stru_102A53D8,
                 a3: 5u,
                 a4: 0);
  v27 = (int)v26;
  ++v26[2];
  if ( v25 )
  {
    v28 = v26 == (int *)name->N.Name.Short;
  }
  else
  {
    if ( v26[1] == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: v26);
    v29 = name;
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
      GASStringNode::ResolveLowercase_Impl(a1: (int *)name->N.Name.Short);
    v28 = *(_DWORD *)(v27 + 4) == *(_DWORD *)(v29->N.Name.Short + 4);
  }
  v30 = v28;
  v8 = (*(_DWORD *)(v27 + 8))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: v27);
  if ( !v30 )
  {
    GASObject::SetMember(
      (CTSQueue<CFunctor *,0,1> *)this,
      a2: (GASEnvironment *)penv,
      name,
      pval: (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **)val,
      pmember: (char *)flags.dwActualSize);
    return;
  }
  GASValue::ToStringImpl(
    this: (unsigned __int8 *)val,
    a2: (int *)&val,
    a3: (tagRID_DEVICE_INFO_KEYBOARD *)penv,
    precision: -1,
    debug: false);
  GASString::ToUpper(this: (int **)&val, a2: (struct GASStringNode **)&name);
  v31 = val;
  v8 = val->cbClsExtra-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v31);
  v32 = 0;
  Length = GASString::GetLength(this: (const char ***)&name);
  if ( Length == 0 )
    goto LABEL_75;
  CharAt = GASString::GetCharAt(this: (unsigned int **)&name, index: 0);
  if ( Length >= 2 )
    v32 = GASString::GetCharAt(this: (unsigned int **)&name, index: 1u);
  if ( CharAt == 84 )
  {
    if ( v32 != 76 )
    {
      if ( v32 != 82 )
      {
        (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 1);
        goto LABEL_37;
      }
      goto LABEL_64;
    }
LABEL_61:
    (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 5);
    goto LABEL_37;
  }
  if ( CharAt != 76 )
  {
    if ( CharAt == 82 )
    {
      if ( v32 == 84 )
      {
LABEL_64:
        (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 6);
        goto LABEL_37;
      }
      if ( v32 != 66 )
      {
        (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 4);
        goto LABEL_37;
      }
LABEL_72:
      (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 8);
      goto LABEL_37;
    }
    if ( CharAt == 66 )
    {
      if ( v32 == 76 )
      {
LABEL_70:
        (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 7);
        goto LABEL_37;
      }
      if ( v32 != 82 )
      {
        (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 2);
        goto LABEL_37;
      }
      goto LABEL_72;
    }
LABEL_75:
    (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 0);
    goto LABEL_37;
  }
  if ( v32 == 84 )
    goto LABEL_61;
  if ( v32 == 66 )
    goto LABEL_70;
  (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 10) + 116))(a1: *((_DWORD *)this + 10), a2: 3);
LABEL_37:
  v24 = name;
  v8 = name->Value-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode(a1: (int)v24);
}

//------------------------------------------------------------------------------
// Address: 0x10114D00
// Name: public: static class GASFunctionRef GASStageCtorFunction::Register(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASFunctionRef *__cdecl GASStageCtorFunction::Register(struct GASFunctionRef *a1, int a2)
{
  int v2; // edi
  void (__thiscall *v3)(vgui::IHTMLEvents *, int, int); // ecx
  int (__thiscall *v4)(_DWORD, int, int *); // eax
  int v5; // eax
  const GArrayLH<unsigned __int64,2,GArrayDefaultPolicy> *v6; // eax
  struct GASFunctionRef *v7; // ebx
  int v8; // ecx
  int (__thiscall *v9)(int, int, struct GASFunctionRef **); // edx
  int v10; // esi
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  GASValue *v12; // eax
  int v13; // edi
  GASValue v15[4]; // [esp+Ch] [ebp-20h] BYREF
  vgui::IHTMLEvents v16; // [esp+1Ch] [ebp-10h] BYREF
  char result_4; // [esp+20h] [ebp-Ch]
  void (__thiscall **result_8)(_DWORD *, vgui::IHTMLEvents *, int, GASValue *, char *); // [esp+24h] [ebp-8h]
  _DWORD *v19; // [esp+28h] [ebp-4h]

  v2 = a2;
  v3 = *(void (__thiscall **)(vgui::IHTMLEvents *, int, int))(a2 + 656);
  v16.__vftable = (vgui::IHTMLEvents_vtbl *)a2;
  result_4 = 8;
  v4 = *(int (__thiscall **)(_DWORD, int, int *))(*(_DWORD *)v3 + 40);
  a2 = 323;
  v5 = v4(a1: v3, a2: 60, a3: &a2);
  if ( v5 != 0 )
    v6 = GASStageCtorFunction::GASStageCtorFunction(
           this: v5,
           result: (_REASON_CONTEXT *)&v16,
           psc_4: *(struct GASStringNode **)(v2 + 652));
  else
    v6 = nullptr;
  v7 = a1;
  *(_DWORD *)a1 = v6;
  *((_BYTE *)v7 + 8) = 0;
  *((_DWORD *)v7 + 1) = 0;
  v8 = *(_DWORD *)(v2 + 656);
  v9 = *(int (__thiscall **)(int, int, struct GASFunctionRef **))(*(_DWORD *)v8 + 40);
  a1 = (struct GASFunctionRef *)323;
  v10 = v9(a1: v8, a2: 84, a3: &a1);
  if ( v10 != 0 )
  {
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(
                                                      this: (vc_attributes::PreRangeAttribute *)v2,
                                                      result: (vc_attributes::InvalidCheckAttribute *)1);
    GASPrototype<GASStageObject,GASEnvironment>::GASPrototype<GASStageObject,GASEnvironment>(
      this: (vgui::IHTMLEvents *)v10,
      psc: &v16,
      psc_4: Prototype,
      psc_8: (unsigned int)v7);
    *(_DWORD *)v10 = &GASPrototype<GASStageObject,GASEnvironment>::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v10 + 16) = &off_102A5540;
    *(_DWORD *)(v10 + 52) = &GASPrototype<GASStageObject,GASEnvironment>::`vftable';
    HIBYTE(a2) = 1;
    GASPrototypeBase::InitFunctionMembers(
      this: (GASPrototypeBase *)(v10 + 52),
      a2: v10,
      flags: (vc_attributes::PreRangeAttribute **)&v16,
      flags_4: (const struct GASNameFunction *)&GFx_StageFunctionTable,
      flags_8: (const struct GASPropFlags *)((char *)&a2 + 3));
  }
  else
  {
    v10 = 0;
  }
  if ( v10 != 0 )
    *(_DWORD *)(v10 + 8) = (*(_DWORD *)(v10 + 8) + 1) & 0x8FFFFFFF;
  GASGlobalContext::SetPrototype(a1: (GArrayDefaultPolicy *)v2, a2: v2, a3: 18, a4: v10);
  v19 = (_DWORD *)(*(_DWORD *)(v2 + 680) + 16);
  HIBYTE(a2) = 0;
  result_8 = (void (__thiscall **)(_DWORD *, vgui::IHTMLEvents *, int, GASValue *, char *))(*v19 + 40);
  v12 = GASValue::GASValue(this: v15, a2: v2, a3: v7);
  v13 = v2 + 80;
  (*result_8)(a1: v19, a2: &v16, a3: v13, a4: v12, a5: (char *)&a2 + 3);
  GASValue::~GASValue(this: v15, a2: v13);
  if ( v10 != 0 )
    GRefCountBaseGC<323>::Release(a1: v10, a2: v13);
  return v7;
}
