// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxvalueimpl.cpp
// Functions: 156
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxvalueimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10065F10
// Name: public: GASString::~GASString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASString::~GASString(GASString *this)
{
  int v1; // ecx

  v1 = *(_DWORD *)this;
  if ( (*(_DWORD *)(v1 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x10065F20
// Name: public: static bool GASNumberUtil::IsNaN(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsNaN(GViewport *v, int u, int u_4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10065F60
// Name: public: static bool GASNumberUtil::IsPOSITIVE_INFINITY(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsPOSITIVE_INFINITY(GViewport *v, int va, int v_4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10065F90
// Name: public: static bool GASNumberUtil::IsNEGATIVE_INFINITY(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASNumberUtil::IsNEGATIVE_INFINITY(GViewport *v, int u, int u_4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10065FC0
// Name: public: void GASValue::SetString(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetString(GASValue *this, _IMAGE_SYMBOL_EX *str)
{
  GASValue Short; // eax

  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs(this);
  *(_BYTE *)this = 5;
  Short = (GASValue)str->N.Name.Short;
  *(this + 1) = (GASValue)str->N.Name.Short;
  ++Short->m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x10065FF0
// Name: public: void GASValue::SetNumber(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetNumber(GASValue *this, double a2)
{
  if ( *(_BYTE *)this >= 5u )
    GASValue::DropRefs(this);
  *(_BYTE *)this = 3;
  *(double *)(this + 1) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x10066010
// Name: public: void GASValue::SetBool(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASValue::SetBool(GASValue *this, bool val)
{
  GASValue::DropRefs(this);
  *(_BYTE *)this = 2;
  *((_BYTE *)this + 4) = val;
}

//------------------------------------------------------------------------------
// Address: 0x10066030
// Name: public: void GFxCharacter::SetMatrix(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxCharacter::SetMatrix(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *m,
        __int128 a3)
{
  *((float *)this + 17) = *(float *)&m->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
  *((float *)this + 18) = *(float *)&m->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable;
  *((float *)this + 19) = *(float *)&m->m_iRefs;
  *((float *)this + 20) = *(float *)&m->m_pCurrentMaterial;
  *((float *)this + 21) = *(float *)&m->m_pCurrentProxyData;
  *((float *)this + 22) = *(float *)&m->m_lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x10066060
// Name: public: void GFxCharacter::SetMatrix3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetMatrix3D(GFxCharacter *this, const struct GMatrix3D *a2)
{
  GFxCharacter::CreateMatrix3D(
    (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this,
    pmat: 0);
  qmemcpy(*((void **)this + 23), a2, 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x10066090
// Name: public: void GFxCharacter::SetPerspective3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetPerspective3D(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *this,
        const struct GMatrix3D *a2)
{
  void **v2; // edi

  v2 = (void **)(this + 4);
  GFxCharacter::CreateMatrix3D(this, pmat: (unsigned int)(this + 4));
  qmemcpy(*v2, a2, 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x100660B0
// Name: public: void GFxCharacter::SetView3D(class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetView3D(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *this,
        const struct GMatrix3D *a2)
{
  void **v2; // edi

  v2 = (void **)((char *)this + 100);
  GFxCharacter::CreateMatrix3D(this, pmat: (unsigned int)this + 100);
  qmemcpy(*v2, a2, 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x100660D0
// Name: public: void GFxCharacter::SetCxform(class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetCxform(GFxCharacter *this, const struct GRenderer::Cxform *a2)
{
  int v2; // edx

  v2 = *(_DWORD *)this;
  qmemcpy((char *)this + 36, a2, 0x20u);
  (*(void (__thiscall **)(GFxCharacter *))(v2 + 4))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10066140
// Name: public: ScopeFunctionTimer::ScopeFunctionTimer(class GFxAmpViewStats __near *,unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ScopeFunctionTimer *__thiscall ScopeFunctionTimer::ScopeFunctionTimer(ScopeFunctionTimer *this, struct GFxAmpViewStats *a2, unsigned int swdHandle, unsigned int a4)
{
  float v5; // ecx
  int v6; // eax
  int v7; // edx
  float v9; // [esp+0h] [ebp-4h]
  float *savedregs; // [esp+4h] [ebp+0h]

  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = swdHandle;
  *((_DWORD *)this + 4) = a4;
  if ( a2 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: a2, swdHandle, a3: a4);
    GTimer::GetRawTicks(li: v5, a2: v9, a3: savedregs);
    *(_DWORD *)this = v6;
    *((_DWORD *)this + 1) = v7;
  }
  else
  {
    *(_DWORD *)this = 0;
    *((_DWORD *)this + 1) = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066190
// Name: public: ScopeFunctionTimer::~ScopeFunctionTimer(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100661C0
// Name: public: GFxValue::DisplayInfo::DisplayInfo(class GFxValue::DisplayInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
_FILE_RENAME_INFO *__thiscall GFxValue::DisplayInfo::DisplayInfo(
        _FILE_RENAME_INFO *this,
        tagCOLORMATCHTOTARGET *result)
{
  *this = *(_FILE_RENAME_INFO *)&result->emr.iType;
  *(this + 1) = *(_FILE_RENAME_INFO *)&result->cbName;
  *(this + 2) = *(_FILE_RENAME_INFO *)&result[1].emr.nSize;
  *((_BYTE *)this + 48) = result[1].cbData;
  *((double *)this + 7) = *(double *)&result[2].emr;
  *(this + 4) = *(_FILE_RENAME_INFO *)&result[2].dwAction;
  *(this + 5) = *(_FILE_RENAME_INFO *)result[2].Data;
  qmemcpy(this + 6, &result[3].dwFlags, 0x40u);
  qmemcpy(this + 10, &result[5].cbData, 0x42u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066250
// Name: public: void GFxValue::ObjectInterface::SetUserData(void __near *,class GFxASUserData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ObjectInterface::SetUserData(
        GFxValue::ObjectInterface *this,
        GASObjectInterface *pdata,
        struct GFxASUserData *puserdata)
{
  GASObjectInterface::SetUserData(this: pdata, a2: (struct GFxMovieView *)this->pMovieRoot, a3: puserdata);
}

//------------------------------------------------------------------------------
// Address: 0x10066270
// Name: public: void GFxASUserData::SetLastObjectValue(class GFxValue::ObjectInterface __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASUserData::SetLastObjectValue(
        GFxASUserData *this,
        struct GFxValue::ObjectInterface *a2,
        void *pdata)
{
  this->pObjectInterface = a2;
  this->pData = pdata;
}

//------------------------------------------------------------------------------
// Address: 0x10066360
// Name: public: class GASString GASStringBuiltinManager::CreateString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GASStringBuiltinManager::CreateString(const char **this, _DWORD *a2, int a3)
{
  int v3; // eax

  GASStringManager::CreateStringNode(this: *(this + 157));
  ++*(_DWORD *)(v3 + 8);
  *a2 = v3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10066380
// Name: public: class GASString GASStringBuiltinManager::CreateString(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
struct GASStringNode **__thiscall GASStringBuiltinManager::CreateString(
        GASStringManager **this,
        struct GASStringNode **a2,
        const wchar_t *pwstr)
{
  struct GASStringNode *StringNode; // eax

  StringNode = GASStringManager::CreateStringNode(this: *(this + 157), a2: pwstr);
  ++*((_DWORD *)StringNode + 2);
  *a2 = StringNode;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100663A0
// Name: public: void GFxMovieRoot::GFxValue2ASValue(class GFxValue const __near &,class GASValue __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GFxValue2ASValue(GFxMovieRoot *this@<ecx>, _IMAGE_SYMBOL_EX a2)
{
  int v2; // esi
  _BYTE *Long; // esi
  _BYTE *v4; // esi
  char v5; // bl
  _BYTE *v6; // esi
  unsigned int v7; // esi
  unsigned int v8; // esi
  GASValue *v9; // ecx
  bool v10; // zf
  int v11; // esi
  const char *String; // eax
  _IMAGE_SYMBOL_EX *v13; // eax
  struct GASStringNode *v14; // eax
  const wchar_t *v15; // eax
  struct GASStringNode **v16; // eax
  int v17; // eax
  double v18; // [esp+4h] [ebp-10h]
  struct GASStringNode *v19; // [esp+Ch] [ebp-8h] BYREF
  struct GASStringNode *v20; // [esp+10h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a2.N.Name.Short + 4);
  switch ( v2 & 0x8F )
  {
    case 0:
      Long = (_BYTE *)a2.N.Name.Long;
      GASValue::DropRefs(this: (GASValue *)a2.N.Name.Long);
      *Long = 0;
      break;
    case 1:
      v6 = (_BYTE *)a2.N.Name.Long;
      GASValue::DropRefs(this: (GASValue *)a2.N.Name.Long);
      *v6 = 1;
      break;
    case 2:
      v4 = (_BYTE *)a2.N.Name.Long;
      v5 = *(_BYTE *)(a2.N.Name.Short + 8);
      GASValue::DropRefs(this: (GASValue *)a2.N.Name.Long);
      v4[4] = v5;
      *v4 = 2;
      break;
    case 3:
      v7 = a2.N.Name.Long;
      v18 = *(double *)(a2.N.Name.Short + 8);
      if ( *(_BYTE *)a2.N.Name.Long >= 5u )
        GASValue::DropRefs(this: (GASValue *)a2.N.Name.Long);
      *(_BYTE *)v7 = 3;
      *(double *)(v7 + 4) = v18;
      break;
    case 4:
      if ( (v2 & 0x40) != 0 )
      {
        v8 = *(_DWORD *)(a2.N.Name.Short + 8);
        goto LABEL_10;
      }
      v11 = *((_DWORD *)this + 2289);
      String = GFxValue::GetString(this: (GFxValue *)a2.N.Name.Short);
      v13 = (_IMAGE_SYMBOL_EX *)GASStringBuiltinManager::CreateString(
                                  this: (const char **)(v11 + 8),
                                  a2: &v20,
                                  a3: (int)String);
      GASValue::SetString(this: (GASValue *)a2.N.Name.Long, str: v13);
      v14 = v20;
      goto LABEL_13;
    case 5:
      v15 = *(const wchar_t **)(a2.N.Name.Short + 8);
      if ( (v2 & 0x40) != 0 )
      {
        v8 = *((_DWORD *)v15 - 1);
LABEL_10:
        v9 = (GASValue *)a2.N.Name.Long;
        ++*(_DWORD *)(v8 + 8);
        a2.N.Name.Short = v8;
        GASValue::SetString(this: v9, str: &a2);
        v10 = (*(_DWORD *)(v8 + 8))-- == 1;
        if ( v10 )
          GASStringNode::ReleaseNode();
      }
      else
      {
        v16 = GASStringBuiltinManager::CreateString(
                this: (GASStringManager **)(*((_DWORD *)this + 2289) + 8),
                a2: &v19,
                pwstr: v15);
        GASValue::SetString(this: (GASValue *)a2.N.Name.Long, str: (_IMAGE_SYMBOL_EX *)v16);
        v14 = v19;
LABEL_13:
        v10 = (*((_DWORD *)v14 + 2))-- == 1;
        if ( v10 )
          GASStringNode::ReleaseNode();
      }
      break;
    case 6:
    case 7:
      v17 = *(_DWORD *)(a2.N.Name.Short + 8);
      if ( v17 != 0 )
        GASValue::SetAsObject(this: (GASValue *)a2.N.Name.Long, a2: (struct GASObject *)(v17 - 16));
      else
        GASValue::SetAsObject(this: (GASValue *)a2.N.Name.Long, a2: nullptr);
      break;
    case 8:
      GASValue::SetAsCharacterHandle(
        this: (GASValue *)a2.N.Name.Long,
        a2: *(struct GFxCharacterHandle **)(a2.N.Name.Short + 8));
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066540
// Name: public: bool GFxValue::ObjectInterface::HasMember(void __near *,char const __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::HasMember(
        CStringPool *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pdata,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a3,
        struct GASStringNode *isdobj)
{
  GFxAmpViewStats *v5; // edi
  float v6; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v7; // esi
  int v8; // eax
  float v9; // ecx
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  int v12; // edi
  GASStringManager *v13; // ecx
  bool v14; // bl
  float v16; // ecx
  float v17; // [esp+0h] [ebp-44h]
  float *v18; // [esp+4h] [ebp-40h]
  GFxAmpViewStats *v19; // [esp+14h] [ebp-30h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *asval; // [esp+24h] [ebp-20h] BYREF
  GASValue member[4]; // [esp+34h] [ebp-10h] BYREF

  v5 = *((GFxAmpViewStats **)this->m_Strings.m_LessFunc + 2577);
  v19 = v5;
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0x24u);
    GTimer::GetRawTicks(li: v6, a2: v17, a3: v18);
  }
  v7 = pdata;
  if ( (_BYTE)isdobj != 0
    && ((GFxCharacterHandle::ResolveCharacter(this: pdata, a2: (GFxMovieRoot *)this->m_Strings.m_LessFunc), v8 == 0)
     || (v7 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v8 + 120),
         v8 == -120)) )
  {
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v9, a2: v17, a3: v18);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  else
  {
    m_LessFunc = this->m_Strings.m_LessFunc;
    LOBYTE(asval) = 0;
    v12 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)m_LessFunc + 12) + 112))(a1: *((_DWORD *)m_LessFunc + 12));
    LOBYTE(member[0]) = 0;
    v13 = *(GASStringManager **)(*(_DWORD *)(v12 + 120) + 636);
    isdobj = (struct GASStringNode *)((char *)&a3->m_Memory.m_pMemory + 1);
    isdobj = GASStringManager::CreateConstStringNode(this: v13, result: a3, a3: strlen((const char *)a3), a4: 0);
    ++*((_DWORD *)isdobj + 2);
    v14 = ((unsigned __int8 (__thiscall *)(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int, struct GASStringNode **, GASValue *))v7->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[1].AddRef)(
            a1: v7,
            a2: v12,
            a3: &isdobj,
            a4: member) == 0;
    if ( (*((_DWORD *)isdobj + 2))-- == 1 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: member);
    GASValue::~GASValue(this: &asval);
    if ( v14 )
    {
      if ( v19 != nullptr )
      {
        GTimer::GetRawTicks(li: v16, a2: v17, a3: v18);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 0;
    }
    else
    {
      if ( v19 != nullptr )
      {
        GTimer::GetRawTicks(li: v16, a2: v17, a3: v18);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066690
// Name: public: bool GFxValue::ObjectInterface::SetMember(void __near *,char const __near *,class GFxValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall GFxValue::ObjectInterface::SetMember(
        CStringPool *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pdata,
        int a3,
        GFxValue *a4,
        int isdobj)
{
  GFxAmpViewStats *v6; // esi
  float v7; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v8; // edi
  int v9; // eax
  float v10; // ecx
  int v12; // eax
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // ecx
  int v14; // esi
  int v15; // eax
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v16; // eax
  char v17; // bl
  float v19; // ecx
  _IMAGE_SYMBOL_EX v20; // [esp-8h] [ebp-3Ch]
  float v21; // [esp+0h] [ebp-34h]
  float *v22; // [esp+4h] [ebp-30h]
  GFxAmpViewStats *v23; // [esp+14h] [ebp-20h]
  GASValue asval[4]; // [esp+24h] [ebp-10h] BYREF

  v6 = *((GFxAmpViewStats **)this->m_Strings.m_LessFunc + 2577);
  v23 = v6;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x26u);
    GTimer::GetRawTicks(li: v7, a2: *(float *)&v20.Value, a3: (float *)v20.SectionNumber);
  }
  v8 = pdata;
  if ( (_BYTE)isdobj != 0
    && ((GFxCharacterHandle::ResolveCharacter(this: pdata, a2: (GFxMovieRoot *)this->m_Strings.m_LessFunc), v9 == 0)
     || (v8 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v9 + 120),
         v9 == -120)) )
  {
    if ( v6 != nullptr )
    {
      GTimer::GetRawTicks(li: v10, a2: *(float *)&v20.Value, a3: (float *)v20.SectionNumber);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  else
  {
    v12 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->m_Strings.m_LessFunc + 12) + 112))(a1: *((_DWORD *)this->m_Strings.m_LessFunc + 12));
    v20.N.Name.Long = (unsigned int)asval;
    m_LessFunc = this->m_Strings.m_LessFunc;
    v20.N.Name.Short = (unsigned int)a4;
    v14 = v12;
    LOBYTE(asval[0]) = 0;
    GFxMovieRoot::GFxValue2ASValue(this: (GFxMovieRoot *)m_LessFunc, a2: v20);
    v15 = *(_DWORD *)(v14 + 120);
    HIBYTE(isdobj) = 0;
    GASStringManager::CreateStringNode(this: *(const char **)(v15 + 636));
    pdata = v16;
    ++v16->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
    v17 = ((int (__thiscall *)(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int, CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **, GASValue *, char *))v8->operator())(
            a1: v8,
            a2: v14,
            a3: &pdata,
            a4: asval,
            a5: (char *)&isdobj + 3);
    if ( pdata->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable-- == (CRefCountServiceDestruct<CRefST>_vtbl *)1 )
      GASStringNode::ReleaseNode();
    GASValue::~GASValue(this: asval);
    if ( v23 != nullptr )
    {
      GTimer::GetRawTicks(li: v19, a2: v21, a3: v22);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100667B0
// Name: public: unsigned int GFxValue::ObjectInterface::GetArraySize(void __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxValue::ObjectInterface::GetArraySize(GFxValue::ObjectInterface *this, char *pdata)
{
  GFxAmpViewStats *v2; // esi
  float v3; // ecx
  char *v4; // eax
  int v5; // edi
  float v7; // [esp+0h] [ebp-24h]
  float *v8; // [esp+4h] [ebp-20h]

  v2 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v2 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v2, swdHandle: 1u, a3: 0x2Au);
    GTimer::GetRawTicks(li: v3, a2: v7, a3: v8);
  }
  if ( pdata != nullptr )
    v4 = pdata - 16;
  else
    v4 = nullptr;
  v5 = *((_DWORD *)v4 + 15);
  if ( v2 != nullptr )
  {
    GTimer::GetRawTicks(li: *(float *)&this, a2: v7, a3: v8);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10066820
// Name: public: bool GFxValue::ObjectInterface::SetArraySize(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetArraySize(GFxValue::ObjectInterface *this, void *pdata, void *sz)
{
  GFxAmpViewStats *v3; // esi
  float v4; // ecx
  float v5; // ecx
  GMemoryHeap *v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+0h] [ebp-Ch]
  float *v9; // [esp+4h] [ebp-8h]

  v3 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v3 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v3, swdHandle: 1u, a3: 0x2Bu);
    GTimer::GetRawTicks(li: v4, a2: *(float *)&v7, a3: v9);
  }
  GASArrayObject::Resize(size: sz, a2: v7);
  if ( v3 != nullptr )
  {
    GTimer::GetRawTicks(li: v5, a2: v8, a3: v9);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10066890
// Name: public: bool GFxValue::ObjectInterface::SetElement(void __near *,unsigned int,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetElement(
        GFxValue::ObjectInterface *this,
        char *pdata,
        unsigned int idx,
        const struct GFxValue *a4)
{
  GFxAmpViewStats *v4; // esi
  GASArrayObject *v5; // edi
  float v6; // ecx
  GFxMovieRoot *pMovieRoot; // ecx
  float v8; // ecx
  _IMAGE_SYMBOL_EX v10; // [esp-8h] [ebp-40h]
  float v11; // [esp+0h] [ebp-38h]
  float *v12; // [esp+4h] [ebp-34h]
  GASValue asval[4]; // [esp+24h] [ebp-14h] BYREF
  GFxValue::ObjectInterface *v14; // [esp+34h] [ebp-4h]

  v4 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v5 = nullptr;
  v14 = this;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x2Du);
    GTimer::GetRawTicks(li: v6, a2: *(float *)&v10.Value, a3: (float *)v10.SectionNumber);
  }
  if ( pdata != nullptr )
    v5 = (GASArrayObject *)(pdata - 16);
  v10.N.Name.Long = (unsigned int)asval;
  pMovieRoot = (GFxMovieRoot *)v14->pMovieRoot;
  v10.N.Name.Short = (unsigned int)a4;
  LOBYTE(asval[0]) = 0;
  GFxMovieRoot::GFxValue2ASValue(this: pMovieRoot, a2: v10);
  GASArrayObject::SetElementSafe(this: v5, a2: idx, a3: (const struct GASValue *)asval);
  GASValue::~GASValue(this: asval);
  if ( v4 != nullptr )
  {
    GTimer::GetRawTicks(li: v8, a2: v11, a3: v12);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10066930
// Name: public: bool GFxValue::ObjectInterface::RemoveElements(void __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::RemoveElements(
        void *this,
        std::_Init_locks *result,
        unsigned int idx,
        int count)
{
  GFxAmpViewStats *v4; // esi
  float v5; // ecx
  ISteamApps *v6; // ecx
  ISteamApps_vtbl *v7; // eax
  float v9; // ecx
  float v10; // [esp+0h] [ebp-20h]
  float *v11; // [esp+4h] [ebp-1Ch]

  v4 = *(GFxAmpViewStats **)(*(_DWORD *)this + 10308);
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x31u);
    GTimer::GetRawTicks(li: v5, a2: v10, a3: v11);
  }
  if ( result != nullptr )
    v6 = (ISteamApps *)&result[-16];
  else
    v6 = nullptr;
  v7 = v6[15].__vftable;
  if ( idx < (unsigned int)v7 )
  {
    GASArrayObject::RemoveElements(this: v6);
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v9, a2: v10, a3: v11);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: *(float *)&v6, a2: v10, a3: v11);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100669E0
// Name: public: bool GFxValue::ObjectInterface::GetDisplayInfo(void __near *,class GFxValue::DisplayInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::GetDisplayInfo(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *a2,
        struct GFxValue::DisplayInfo *a3)
{
  GFxAmpViewStats *v4; // esi
  float v5; // ecx
  float v6; // ecx
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v7; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v8; // edi
  int v10; // eax
  int m_pfnProxied; // edx
  float v12; // ecx
  char v13; // al
  const void *Perspective3D; // eax
  const void *View3D; // eax
  float v16; // [esp+0h] [ebp-B4h]
  float *v17; // [esp+4h] [ebp-B0h]
  long double v18; // [esp+Ch] [ebp-A8h]
  long double v19; // [esp+14h] [ebp-A0h]
  long double v20; // [esp+1Ch] [ebp-98h]
  long double v21; // [esp+24h] [ebp-90h]
  long double v22; // [esp+2Ch] [ebp-88h]
  long double v23; // [esp+34h] [ebp-80h]
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v24; // [esp+54h] [ebp-60h]
  int v25; // [esp+58h] [ebp-5Ch] BYREF
  int v26; // [esp+5Ch] [ebp-58h]
  long double v27; // [esp+60h] [ebp-54h]
  long double v28; // [esp+68h] [ebp-4Ch]
  long double v29; // [esp+70h] [ebp-44h]
  float v30[6]; // [esp+78h] [ebp-3Ch] BYREF
  long double v31; // [esp+90h] [ebp-24h]
  long double v32; // [esp+98h] [ebp-1Ch]
  long double v33; // [esp+A0h] [ebp-14h]
  long double v34; // [esp+A8h] [ebp-Ch]

  v4 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x37u);
    GTimer::GetRawTicks(li: v5, a2: v16, a3: v17);
  }
  GFxCharacterHandle::ResolveCharacter(this: a2, a2: (GFxMovieRoot *)this->pMovieRoot);
  v8 = v7;
  v24 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v7;
  if ( v7 != nullptr )
  {
    GMatrix2D::SetIdentity(this: v30);
    v29 = 0.0;
    v26 = 0;
    v28 = 100.0;
    v25 = 0;
    v27 = 100.0;
    v32 = 100.0;
    v34 = 0.0;
    v33 = 0.0;
    v31 = 0.0;
    GFxASCharacter::GetGeomData(this: v8, a2: 0.0, fX: &v25);
    v10 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v8->m_pfnProxied) + 176))(a1: v8);
    m_pfnProxied = v8->m_pfnProxied;
    if ( v10 == 4 )
    {
      (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, struct GFxValue::DisplayInfo *))(m_pfnProxied + 360))(
        a1: v8,
        a2: a3);
    }
    else
    {
      v21 = (double)v25 / 20.0;
      v20 = (double)v26 / 20.0;
      v18 = v29;
      v23 = v27;
      v19 = v28;
      v22 = *((float *)&v8[2].m_pfnProxied + 3) * 100.0;
      v13 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(m_pfnProxied + 16))(a1: v8);
      a3->X = v21;
      a3->VarsSet |= 0x7FFu;
      a3->Y = v20;
      a3->Visible = v13;
      a3->Rotation = v18;
      a3->XScale = v23;
      a3->YScale = v19;
      a3->Alpha = v22;
      a3->Z = v31;
      a3->XRotation = v33;
      a3->YRotation = v34;
      a3->ZScale = v32;
      a3->PerspFOV = GFxCharacter::GetPerspectiveFOV(this: (GFxCharacter *)v8, a2: false);
      a3->VarsSet |= 0x800u;
      Perspective3D = (const void *)GFxCharacter::GetPerspective3D(this: v8, checkAncestors: false);
      if ( Perspective3D != nullptr )
      {
        a3->VarsSet |= 0x1000u;
        qmemcpy((void *)&a3->PerspectiveMatrix3D, Perspective3D, sizeof(a3->PerspectiveMatrix3D));
        v8 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v24;
      }
      else
      {
        a3->VarsSet &= ~0x1000u;
      }
      View3D = (const void *)GFxCharacter::GetView3D(this: v8, checkAncestors: false);
      if ( View3D != nullptr )
      {
        a3->VarsSet |= 0x2000u;
        qmemcpy((void *)&a3->ViewMatrix3D, View3D, sizeof(a3->ViewMatrix3D));
        v12 = 0.0;
      }
      else
      {
        a3->VarsSet &= ~0x2000u;
      }
    }
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v12, a2: v16, a3: v17);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v6, a2: v16, a3: v17);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066C30
// Name: public: bool GFxValue::ObjectInterface::SetDisplayInfo(void __near *,class GFxValue::DisplayInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetDisplayInfo(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pdata,
        tagCOLORMATCHTOTARGET *cinfo)
{
  GFxAmpViewStats *v4; // ecx
  float v5; // ecx
  int v6; // eax
  float v7; // ecx
  int v8; // ebx
  unsigned int v10; // eax
  void (__thiscall *v11)(int); // eax
  double v12; // st6
  int v13; // eax
  GViewport *v14; // ecx
  char v15; // al
  long double v16; // st7
  int v17; // eax
  long double v18; // st7
  int v19; // eax
  _DWORD *v20; // ecx
  char v21; // dl
  float *v22; // eax
  double *v23; // eax
  long double v24; // st7
  long double v25; // st7
  long double v26; // st6
  double v27; // st7
  long double v28; // st6
  bool v29; // c0
  bool v30; // c3
  double v31; // st7
  double v32; // st6
  double v33; // st7
  double v34; // st6
  double v35; // st7
  double v36; // st7
  char v37; // al
  double v38; // st6
  double v39; // st6
  double v40; // st6
  float X_4; // [esp+10h] [ebp-36Ch]
  float X_8; // [esp+14h] [ebp-368h]
  float v43; // [esp+18h] [ebp-364h]
  float *v44; // [esp+1Ch] [ebp-360h]
  double origRotation; // [esp+24h] [ebp-358h]
  double newYScale; // [esp+2Ch] [ebp-350h]
  GFxAmpViewStats *v47; // [esp+3Ch] [ebp-340h]
  double newXScale; // [esp+4Ch] [ebp-330h]
  double origYScale; // [esp+54h] [ebp-328h]
  double origYScalea; // [esp+54h] [ebp-328h]
  double origYScaleb; // [esp+54h] [ebp-328h]
  double origYScalec; // [esp+54h] [ebp-328h]
  double origXScale; // [esp+5Ch] [ebp-320h]
  double origXScalea; // [esp+5Ch] [ebp-320h]
  double origXScaleb; // [esp+5Ch] [ebp-320h]
  double origXScalec; // [esp+5Ch] [ebp-320h]
  double newRotation; // [esp+64h] [ebp-318h]
  double newRotationa; // [esp+64h] [ebp-318h]
  double newRotationb; // [esp+64h] [ebp-318h]
  double newRotationc; // [esp+64h] [ebp-318h]
  double newRotationd; // [esp+64h] [ebp-318h]
  double newRotatione; // [esp+64h] [ebp-318h]
  bool istf; // [esp+6Fh] [ebp-30Dh]
  double zval; // [esp+70h] [ebp-30Ch]
  double zvala; // [esp+70h] [ebp-30Ch]
  double zvalb; // [esp+70h] [ebp-30Ch]
  double zvalc; // [esp+70h] [ebp-30Ch]
  float zval_4; // [esp+74h] [ebp-308h]
  float zval_4a; // [esp+74h] [ebp-308h]
  float zval_4b; // [esp+74h] [ebp-308h]
  float zval_4c; // [esp+74h] [ebp-308h]
  float zval_4d; // [esp+74h] [ebp-308h]
  float zval_4e; // [esp+74h] [ebp-308h]
  float zval_4f; // [esp+74h] [ebp-308h]
  float zval_4g; // [esp+74h] [ebp-308h]
  float zval_4h; // [esp+74h] [ebp-308h]
  float zval_4i; // [esp+74h] [ebp-308h]
  float zval_4j; // [esp+74h] [ebp-308h]
  GMatrix3D v79; // [esp+78h] [ebp-304h] BYREF
  GMatrix3D v80; // [esp+B8h] [ebp-2C4h] BYREF
  GMatrix3D v81; // [esp+F8h] [ebp-284h] BYREF
  GMatrix3D v82; // [esp+138h] [ebp-244h] BYREF
  GMatrix3D v83; // [esp+178h] [ebp-204h] BYREF
  GMatrix3D v84; // [esp+1B8h] [ebp-1C4h] BYREF
  GMatrix3D v85; // [esp+1F8h] [ebp-184h] BYREF
  _FILE_RENAME_INFO v86; // [esp+238h] [ebp-144h] BYREF
  long double v87; // [esp+248h] [ebp-134h]
  double v88; // [esp+250h] [ebp-12Ch]
  double v89; // [esp+258h] [ebp-124h]
  double v90; // [esp+260h] [ebp-11Ch]
  int v91; // [esp+268h] [ebp-114h]
  double v92; // [esp+270h] [ebp-10Ch]
  double v93; // [esp+278h] [ebp-104h]
  double v94; // [esp+280h] [ebp-FCh]
  double v95; // [esp+288h] [ebp-F4h]
  double v96; // [esp+290h] [ebp-ECh]
  _BYTE v97[128]; // [esp+298h] [ebp-E4h]
  unsigned int v98; // [esp+318h] [ebp-64h]
  GMatrix3D v99; // [esp+320h] [ebp-5Ch] BYREF
  CMaterialDict::MaterialLookup_t v100; // [esp+360h] [ebp-1Ch] BYREF
  float v101; // [esp+368h] [ebp-14h]
  float v102; // [esp+36Ch] [ebp-10h]
  float v103; // [esp+370h] [ebp-Ch]
  float v104; // [esp+374h] [ebp-8h]

  v4 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v47 = v4;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x38u);
    GTimer::GetRawTicks(li: v5, a2: v43, a3: v44);
  }
  GFxCharacterHandle::ResolveCharacter(this: pdata, a2: (GFxMovieRoot *)this->pMovieRoot);
  v8 = v6;
  if ( v6 == 0 )
  {
    if ( v47 != nullptr )
    {
      GTimer::GetRawTicks(li: v7, a2: v43, a3: v44);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  istf = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 176))(a1: v6) == 4;
  GFxValue::DisplayInfo::DisplayInfo(this: &v86, result: cinfo);
  v10 = v98;
  if ( (v98 & 0x20) != 0 )
  {
    origXScale = v90;
    if ( (HIDWORD(origXScale) & 0x7FF00000) != 0x7FF00000 || (HIDWORD(origXScale) & 0xFFFFF | LODWORD(origXScale)) == 0 )
    {
      v11 = *(void (__thiscall **)(int))(*(_DWORD *)v8 + 4);
      qmemcpy(v99.M_[2], (const void *)(v8 + 36), 0x20u);
      v99.M_[3][2] = v90 / 100.0;
      qmemcpy((void *)(v8 + 36), v99.M_[2], 32);
      v11(a1: v8);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 32))(a1: v8, a2: 0);
      v10 = v98;
    }
  }
  if ( (v10 & 0x40) != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 204))(a1: v8, a2: v91);
    v10 = v98;
  }
  if ( (v10 & 0x80u) != 0 )
  {
    zval = v92;
    v12 = v92;
    origXScalea = v92;
    if ( (HIDWORD(origXScalea) & 0x7FF00000) == 0x7FF00000
      && (HIDWORD(origXScalea) & 0xFFFFF | LODWORD(origXScalea)) != 0 )
    {
      v12 = 0.0;
      zval = 0.0;
    }
    if ( v12 == -INFINITY || v12 == INFINITY )
      zval = 0.0;
    GFxASCharacter::EnsureGeomDataCreated(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v8);
    if ( *(double *)(*(_DWORD *)(v8 + 152) + 56) != zval )
    {
      GFxCharacter::CreateMatrix3D(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
        pmat: 0);
      v13 = *(_DWORD *)(v8 + 152);
      v99 = *(GMatrix3D *)*(_DWORD *)(v8 + 92);
      *(double *)(v13 + 56) = zval;
      v99.M_[3][2] = *(double *)(*(_DWORD *)(v8 + 152) + 56);
      if ( GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v99) )
      {
        GFxCharacter::CreateMatrix3D(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
          pmat: 0);
        *(GMatrix3D *)*(_DWORD *)(v8 + 92) = v99;
      }
    }
    v10 = v98;
  }
  if ( (v10 & 0x400) != 0 )
  {
    origYScale = v95;
    origXScaleb = v95;
    v14 = (GViewport *)HIDWORD(origXScaleb);
    if ( (HIDWORD(origXScaleb) & 0x7FF00000) == 0x7FF00000
      && (v14 = (GViewport *)(HIDWORD(origXScaleb) & 0xFFFFF),
          (HIDWORD(origXScaleb) & 0xFFFFF | LODWORD(origXScaleb)) != 0)
      || v95 == -INFINITY
      || (GASNumberUtil::IsPOSITIVE_INFINITY(v: v14, va: SLODWORD(v95), v_4: SHIDWORD(v95)), v15 != 0) )
    {
      origYScale = 100.0;
    }
    GFxASCharacter::EnsureGeomDataCreated(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v8);
    if ( origYScale != *(double *)(*(_DWORD *)(v8 + 152) + 64) )
    {
      GFxCharacter::CreateMatrix3D(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
        pmat: 0);
      v83 = *(GMatrix3D *)*(_DWORD *)(v8 + 92);
      GMatrix3D::SetIdentity(this: &v99);
      GMatrix3D::SetIdentity(this: &v99);
      v99.M_[0][0] = 1.0;
      v99.M_[1][1] = 1.0;
      v85 = v83;
      zval_4 = origYScale;
      v82 = v83;
      v99.M_[2][2] = zval_4 / 100.0;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v85, a2: (float *)&v82, a3: (float *)&v99);
      *(double *)(*(_DWORD *)(v8 + 152) + 64) = origYScale;
      if ( GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v85) )
      {
        GFxCharacter::CreateMatrix3D(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
          pmat: 0);
        *(GMatrix3D *)*(_DWORD *)(v8 + 92) = v85;
      }
    }
    v10 = v98;
  }
  if ( (v10 & 0x100) != 0 )
  {
    newRotation = v93;
    GFxASCharacter::EnsureGeomDataCreated(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v8);
    if ( *(double *)(*(_DWORD *)(v8 + 152) + 72) != newRotation )
    {
      v16 = fmod(newRotation, 360.0);
      origYScalea = v16;
      if ( v16 <= 180.0 )
      {
        if ( v16 < -180.0 )
          origYScalea = v16 + 360.0;
      }
      else
      {
        origYScalea = v16 - 360.0;
      }
      GFxCharacter::CreateMatrix3D(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
        pmat: 0);
      GMatrix3D::SetIdentity(this: &v81);
      GMatrix3D::SetIdentity(this: &v85);
      GMatrix3D::SetIdentity(this: &v83);
      GMatrix3D::SetIdentity(this: &v82);
      v17 = *(_DWORD *)(v8 + 152);
      v85.M_[3][2] = *(double *)(v17 + 56);
      zval_4a = *(double *)(v17 + 64);
      v83.M_[2][2] = zval_4a / 100.0;
      zval_4b = origYScalea * 3.141592653589793 / 180.0;
      GMatrix3D::RotateX(this: &v81, a2: zval_4b);
      zval_4c = *(double *)(*(_DWORD *)(v8 + 152) + 80) * 3.141592653589793 / 180.0;
      GMatrix3D::RotateY(this: &v82, a2: zval_4c);
      *(double *)(*(_DWORD *)(v8 + 152) + 72) = origYScalea;
      v99 = v85;
      v84 = v85;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v83);
      v84 = v99;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v81);
      v84 = v99;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v82);
      if ( GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v99) )
      {
        GFxCharacter::CreateMatrix3D(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
          pmat: 0);
        *(GMatrix3D *)*(_DWORD *)(v8 + 92) = v99;
      }
    }
    v10 = v98;
  }
  if ( (v10 & 0x200) != 0 )
  {
    newRotationa = v94;
    GFxASCharacter::EnsureGeomDataCreated(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)v8);
    if ( *(double *)(*(_DWORD *)(v8 + 152) + 80) != newRotationa )
    {
      v18 = fmod(newRotationa, 360.0);
      origYScaleb = v18;
      if ( v18 <= 180.0 )
      {
        if ( v18 < -180.0 )
          origYScaleb = v18 + 360.0;
      }
      else
      {
        origYScaleb = v18 - 360.0;
      }
      GMatrix3D::SetIdentity(this: &v79);
      GMatrix3D::SetIdentity(this: &v80);
      GFxCharacter::CreateMatrix3D(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
        pmat: 0);
      GMatrix3D::SetIdentity(this: &v81);
      GMatrix3D::SetIdentity(this: &v85);
      GMatrix3D::SetIdentity(this: &v82);
      GMatrix3D::SetIdentity(this: &v83);
      v19 = *(_DWORD *)(v8 + 152);
      v85.M_[3][2] = *(double *)(v19 + 56);
      zval_4d = *(double *)(v19 + 64);
      v82.M_[2][2] = zval_4d / 100.0;
      zval_4e = origYScaleb * 3.141592653589793 / 180.0;
      GMatrix3D::RotateY(this: &v83, a2: zval_4e);
      zval_4f = *(double *)(*(_DWORD *)(v8 + 152) + 72) * 3.141592653589793 / 180.0;
      GMatrix3D::RotateX(this: &v81, a2: zval_4f);
      *(double *)(*(_DWORD *)(v8 + 152) + 80) = origYScaleb;
      v99 = v85;
      v84 = v85;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v82);
      v84 = v99;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v81);
      v84 = v99;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v99, a2: (float *)&v84, a3: (float *)&v83);
      if ( GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v99) )
      {
        GFxCharacter::CreateMatrix3D(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
          pmat: 0);
        *(GMatrix3D *)*(_DWORD *)(v8 + 92) = v99;
      }
    }
    v10 = v98;
  }
  if ( (v10 & 0x800) != 0 )
  {
    newRotationb = v96;
    if ( newRotationb != GFxCharacter::GetPerspectiveFOV(this: (GFxCharacter *)v8, a2: false) )
    {
      zval_4g = fmod(newRotationb, 180.0);
      GFxCharacter::SetPerspectiveFOV(this: (GFxCharacter *)v8, fov: zval_4g);
    }
    v10 = v98;
  }
  if ( (v10 & 0x1000) != 0 )
  {
    GFxCharacter::CreateMatrix3D(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
      pmat: v8 + 96);
    qmemcpy(*(void **)(v8 + 96), &v97[64], 64);
    v10 = v98;
  }
  v20 = (_DWORD *)(v10 >> 13);
  if ( (v10 & 0x2000) != 0 )
  {
    GFxCharacter::CreateMatrix3D(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)v8,
      pmat: v8 + 100);
    qmemcpy(*(void **)(v8 + 100), v97, 64);
    v20 = nullptr;
    LOBYTE(v10) = v98;
  }
  if ( (v10 & 1) != 0
    || (v10 & 2) != 0
    || (v10 & 4) != 0
    || (v10 & 8) != 0
    || (LOBYTE(v20) = (unsigned __int8)v10 >> 4, (v10 & 0x10) != 0) )
  {
    if ( istf && ((v10 & 8) != 0 || (v10 & 0x10) != 0 || (v10 & 4) != 0) )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 352))(a1: v8);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 32))(a1: v8, a2: 0);
    v100.m_pMaterial = *(IMaterialInternal **)(v8 + 68);
    v21 = v98;
    *(float *)&v100.m_Name.m_Id = *(float *)(v8 + 72);
    v101 = *(float *)(v8 + 76);
    v102 = *(float *)(v8 + 80);
    v103 = *(float *)(v8 + 84);
    v104 = *(float *)(v8 + 88);
    if ( istf && ((v98 & 1) != 0 || (v98 & 2) != 0) )
    {
      (*(void (__thiscall **)(int, _FILE_RENAME_INFO *))(*(_DWORD *)v8 + 356))(a1: v8, a2: &v86);
      v21 = v98;
    }
    if ( (v21 & 4) == 0 && (v21 & 8) == 0 && (v21 & 0x10) == 0 )
      goto LABEL_115;
    v22 = *(float **)(v8 + 152);
    v99.M_[2][2] = v22[8];
    v99.M_[2][3] = v22[9];
    v99.M_[3][0] = v22[10];
    v99.M_[3][1] = v22[11];
    v99.M_[3][2] = v22[12];
    v99.M_[3][0] = v101;
    v99.M_[3][3] = v104;
    origRotation = GMatrix2D::GetRotation(this: (GMatrix2D *)&v99.M_[2][2]);
    origXScalec = GMatrix2D::GetXScale(this: (GMatrix2D *)&v99.M_[2][2]);
    origYScalec = GMatrix2D::GetYScale(this: (GMatrix2D *)&v99.M_[2][2]);
    v23 = *(double **)(v8 + 152);
    newXScale = v23[1] / 100.0;
    newYScale = v23[2] / 100.0;
    newRotationc = v23[3] * 3.141592653589793 / 180.0;
    if ( (v98 & 4) != 0 )
      v24 = v87;
    else
      v24 = GASNumberUtil::NaN();
    zvala = v24;
    if ( (HIDWORD(zvala) & 0x7FF00000) != 0x7FF00000 || (HIDWORD(zvala) & 0xFFFFF | LODWORD(zvala)) == 0 )
    {
      v25 = fmod(v24, 360.0);
      if ( v25 <= 180.0 )
      {
        v29 = v25 > -180.0;
        v30 = -180.0 == v25;
        v28 = v25;
        v27 = 180.0;
        if ( !v29 && !v30 )
          v28 = v28 + 360.0;
      }
      else
      {
        v26 = v25;
        v27 = 180.0;
        v28 = v26 - 360.0;
      }
      *(long double *)(*(_DWORD *)(v8 + 152) + 24) = v28;
      newRotationc = v28 * 3.141592653589793 / v27;
    }
    if ( (v98 & 8) != 0 )
      v31 = v88 / 100.0;
    else
      v31 = GASNumberUtil::NaN();
    zvalb = v31;
    if ( (HIDWORD(zvalb) & 0x7FF00000) == 0x7FF00000 && (HIDWORD(zvalb) & 0xFFFFF | LODWORD(zvalb)) != 0
      || v31 == -INFINITY
      || v31 == INFINITY
      || newXScale == v31 )
    {
      v33 = 0.0;
    }
    else
    {
      *(double *)(*(_DWORD *)(v8 + 152) + 8) = v88;
      if ( 0.0 == origXScalec || v31 > 1.0e16 )
      {
        origXScalec = 1.0;
        v31 = 0.0;
      }
      v32 = v31;
      v33 = 0.0;
      newXScale = v32;
    }
    if ( (v98 & 0x10) != 0 )
    {
      v34 = v89 / 100.0;
    }
    else
    {
      v34 = GASNumberUtil::NaN();
      v33 = 0.0;
    }
    zvalc = v34;
    if ( (HIDWORD(zvalc) & 0x7FF00000) == 0x7FF00000 && (HIDWORD(zvalc) & 0xFFFFF | LODWORD(zvalc)) != 0
      || v34 == -INFINITY
      || v34 == INFINITY )
    {
      v33 = newYScale;
      goto LABEL_114;
    }
    if ( newYScale == v34 )
    {
      v34 = newYScale;
    }
    else
    {
      *(double *)(*(_DWORD *)(v8 + 152) + 16) = v89;
      if ( v33 == origYScalec || v34 > 1.0e16 )
      {
        origYScalec = 1.0;
LABEL_114:
        zval_4h = newRotationc - origRotation;
        X_8 = zval_4h;
        zval_4i = v33 / origYScalec;
        X_4 = zval_4i;
        zval_4j = newXScale / origXScalec;
        GFxASCharacter_MatrixScaleAndRotate2x2(x11: &v99.M_[2][2], sx: zval_4j, sy: X_4, x01: X_8);
        v21 = v98;
        *(float *)&v100.m_pMaterial = v99.M_[2][2];
        *(float *)&v100.m_Name.m_Id = v99.M_[2][3];
        v101 = v99.M_[3][0];
        v102 = v99.M_[3][1];
        v103 = v99.M_[3][2];
        v104 = v99.M_[3][3];
LABEL_115:
        if ( (v21 & 1) != 0 )
        {
          v35 = *(double *)&v86.ReplaceIfExists;
        }
        else
        {
          v35 = GASNumberUtil::NaN();
          v21 = v98;
        }
        newRotationd = v35;
        if ( (HIDWORD(newRotationd) & 0x7FF00000) != 0x7FF00000
          || (HIDWORD(newRotationd) & 0xFFFFF | LODWORD(newRotationd)) == 0 )
        {
          if ( v35 == -INFINITY || v35 == INFINITY )
            v35 = 0.0;
          **(_DWORD **)(v8 + 152) = (int)floor(X: v35 * 20.0);
          v21 = v98;
          v101 = (float)**(int **)(v8 + 152);
        }
        if ( (v21 & 2) != 0 )
          v36 = *(double *)&v86.FileNameLength;
        else
          v36 = GASNumberUtil::NaN();
        newRotatione = v36;
        if ( (HIDWORD(newRotatione) & 0x7FF00000) != 0x7FF00000
          || (HIDWORD(newRotatione) & 0xFFFFF | LODWORD(newRotatione)) == 0 )
        {
          if ( v36 == -INFINITY || v36 == INFINITY )
            v36 = 0.0;
          *(_DWORD *)(*(_DWORD *)(v8 + 152) + 4) = (int)floor(X: v36 * 20.0);
          v104 = (float)*(int *)(*(_DWORD *)(v8 + 152) + 4);
        }
        GMatrix2D::IsValid(this: &v100);
        if ( v37 != 0 )
        {
          *(CMaterialDict::MaterialLookup_t *)(v8 + 68) = v100;
          *(float *)(v8 + 76) = v101;
          *(float *)(v8 + 80) = v102;
          *(float *)(v8 + 84) = v103;
          *(float *)(v8 + 88) = v104;
        }
        if ( istf )
        {
          if ( (v98 & 1) != 0 )
          {
            v38 = *(double *)&v86.ReplaceIfExists * 20.0;
            if ( *(double *)&v86.ReplaceIfExists * 20.0 <= 0.0 )
              v39 = v38 - 0.5;
            else
              v39 = v38 + 0.5;
            v20 = *(_DWORD **)(v8 + 152);
            *v20 = (int)v39;
          }
          if ( (v98 & 2) != 0 )
          {
            v40 = *(double *)&v86.FileNameLength * 20.0;
            v20 = *(_DWORD **)(v8 + 152);
            if ( *(double *)&v86.FileNameLength * 20.0 <= 0.0 )
              v20[1] = (int)(v40 - 0.5);
            else
              v20[1] = (int)(v40 + 0.5);
          }
        }
        goto LABEL_145;
      }
    }
    v33 = v34;
    goto LABEL_114;
  }
LABEL_145:
  if ( v47 != nullptr )
  {
    GTimer::GetRawTicks(li: *(float *)&v20, a2: v43, a3: v44);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10067B70
// Name: public: bool GFxValue::ObjectInterface::SetCxform(void __near *,class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetCxform(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *a2,
        const struct GRenderer::Cxform *a3)
{
  GFxAmpViewStats *v4; // ebx
  float v5; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v6; // eax
  float v7; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v9; // edx
  float v10; // ecx
  float v11; // [esp+0h] [ebp-24h]
  float *v12; // [esp+4h] [ebp-20h]
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v13; // [esp+2Ch] [ebp+8h]

  v4 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x3Du);
    GTimer::GetRawTicks(li: v5, a2: v11, a3: v12);
  }
  GFxCharacterHandle::ResolveCharacter(this: a2, a2: (GFxMovieRoot *)this->pMovieRoot);
  v13 = v6;
  if ( v6 != nullptr )
  {
    v9 = v6->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
    qmemcpy(&v6->m_Proxy.m_pObject + 1, a3, 0x20u);
    v9->Release(this: v6);
    ((void (__thiscall *)(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, _DWORD))v13->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[2].AddRef)(
      a1: v13,
      a2: 0);
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v10, a2: v11, a3: v12);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v7, a2: v11, a3: v12);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067D30
// Name: public: bool GASObjectInterface::GetConstMemberRaw(class GASStringContext __near *,char const __near *,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASObjectInterface::GetConstMemberRaw(
        GASObjectInterface *this,
        struct GASStringContext *psc,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *psc_4,
        struct GASValue *psc_8)
{
  struct GASStringContext *v4; // edi
  GASStringManager *v6; // ecx
  char v7; // bl

  v4 = psc;
  v6 = *(GASStringManager **)(*(_DWORD *)psc + 636);
  psc = (struct GASStringContext *)((char *)&psc_4->m_Memory.m_pMemory + 1);
  psc = GASStringManager::CreateConstStringNode(this: v6, result: psc_4, a3: strlen((const char *)psc_4), a4: 0);
  ++*((_DWORD *)psc + 2);
  v7 = (*(int (__thiscall **)(GASObjectInterface *, struct GASStringContext *, struct GASStringContext **, struct GASValue *))(*(_DWORD *)this + 44))(
         a1: this,
         a2: v4,
         a3: &psc,
         a4: psc_8);
  if ( (*((_DWORD *)psc + 2))-- == 1 )
    GASStringNode::ReleaseNode();
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10067DA0
// Name: public: void GFxValue::ObjectInterface::ObjectAddRef(class GFxValue __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ObjectInterface::ObjectAddRef(CStringPool *this, StringPoolCase_t val, IShaderDevice *pobj)
{
  PROCESSOR_IDLESTATE_POLICY *v3; // eax
  PROCESSOR_IDLESTATE_POLICY *savedregs; // [esp+0h] [ebp+0h]

  switch ( *(_DWORD *)(val + 4) & 0x8F )
  {
    case 4:
      ++pobj[2].__vftable;
      break;
    case 5:
      GRefCountImpl::AddRef(this: pobj - 3);
      break;
    case 6:
    case 7:
      v3 = GASObjectInterface::ToASObject(result: savedregs);
      v3->Policy[0].TimeCheck = (v3->Policy[0].TimeCheck + 1) & 0x8FFFFFFF;
      break;
    case 8:
      ++pobj->__vftable;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067E10
// Name: public: void GFxValue::ObjectInterface::VisitMembers(void __near *,class GFxValue::ObjectInterface::ObjVisitor __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ObjectInterface::VisitMembers(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *a2,
        struct GFxValue::ObjectInterface::ObjVisitor *a3,
        bool a4)
{
  GFxAmpViewStats *v5; // edi
  float v6; // ecx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v7; // ebx
  int v8; // eax
  float v9; // ecx
  int v10; // esi
  struct GFxMovieRoot *pMovieRoot; // eax
  float v12; // [esp+0h] [ebp-38h]
  float *v13; // [esp+4h] [ebp-34h]
  _DWORD v14[4]; // [esp+24h] [ebp-14h] BYREF
  GFxValue::ObjectInterface *v15; // [esp+34h] [ebp-4h]

  v5 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v15 = this;
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0x29u);
    GTimer::GetRawTicks(li: v6, a2: v12, a3: v13);
  }
  v7 = a2;
  if ( !a4
    || (GFxCharacterHandle::ResolveCharacter(this: a2, a2: (GFxMovieRoot *)this->pMovieRoot), v8 != 0)
    && (v7 = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v8 + 120),
        v8 != -120) )
  {
    v10 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->pMovieRoot + 12) + 112))(a1: *((_DWORD *)this->pMovieRoot
                                                                                           + 12))
        + 120;
    pMovieRoot = v15->pMovieRoot;
    v14[3] = a3;
    v14[0] = &`GFxValue::ObjectInterface::VisitMembers'::`7'::VisitorProxy::`vftable';
    v14[1] = pMovieRoot;
    v14[2] = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)pMovieRoot + 12) + 112))(a1: *((_DWORD *)pMovieRoot + 12));
    ((void (__thiscall *)(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int, _DWORD *, int, _DWORD))v7->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[2].AddRef)(
      a1: v7,
      a2: v10,
      a3: v14,
      a4: 3,
      a5: 0);
    v14[0] = &GString::InitStruct::`vftable';
  }
  if ( v5 != nullptr )
  {
    GTimer::GetRawTicks(li: v9, a2: v12, a3: v13);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067F30
// Name: protected: bool GRefCountBaseGC<323>::CollectGarbage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GRefCountBaseGC<323>::CollectGarbage(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = *(this + 2);
  if ( (v2 & 0x70000000) != 0x20000000 || v2 < 0 )
    return 0;
  *(this + 2) = v2 & 0x8FFFFFFF;
  (*(void (__thiscall **)(_DWORD *, int))*this)(a1: this, a2: 3);
  v3 = *(this + 1);
  if ( (*(this + 2) & 0x70000000) != 0x40000000 )
  {
    *(this + 1) = *(_DWORD *)(v3 + 28);
    *(_DWORD *)(v3 + 28) = this;
    *(this + 2) = *(this + 2) & 0x8FFFFFFF | 0x40000000;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10067FA0
// Name: public: GFxMovieRoot::WideStringStorage::WideStringStorage(struct GASStringNode __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxMovieRoot::WideStringStorage *__thiscall GFxMovieRoot::WideStringStorage::WideStringStorage(
        GFxMovieRoot::WideStringStorage *this,
        GColor *a2,
        unsigned int a3)
{
  *this = (GFxMovieRoot::WideStringStorage)&GRefCountImplCore::`vftable';
  *(this + 2) = a2;
  *(this + 1) = (GFxMovieRoot::WideStringStorage)1;
  *this = (GFxMovieRoot::WideStringStorage)&GFxMovieRoot::WideStringStorage::`vftable';
  ++a2[2].Raw;
  GUTF8Util::DecodeString(
    pbegin: (wchar_t *)this + 6,
    putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)**(this + 2),
    length: a3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068020
// Name: public: bool GRefCountCollector<323>::Collect(struct GRefCountCollector<323>::Stats __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GRefCountCollector<323>::Collect@<al>(IDataCacheSection *this@<ecx>, int a2@<esi>, unsigned int *a3)
{
  IDataCacheSection_vtbl *v3; // eax
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  IDataCacheSection *v13; // edi
  unsigned int i; // ebx
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // eax
  unsigned int j; // ebx
  int v19; // esi
  int v20; // eax
  int v21; // eax
  _DWORD *v22; // esi
  int v23; // ebx
  _DWORD *v24; // edi
  unsigned int v25; // eax
  int v27; // [esp-Ch] [ebp-24h]
  int v28; // [esp-8h] [ebp-20h]
  int v29; // [esp-8h] [ebp-20h]
  unsigned int totalKillListSize; // [esp+4h] [ebp-14h]
  unsigned int initialNRoots; // [esp+8h] [ebp-10h]
  IDataCacheSection_vtbl *v32; // [esp+Ch] [ebp-Ch]
  unsigned int lastSize; // [esp+14h] [ebp-4h]

  if ( (*(_BYTE *)(this + 8) & 1) != 0 || (v3 = *((IDataCacheSection_vtbl **)this + 2), v32 = v3, v3 == nullptr) )
  {
    if ( a3 != nullptr )
    {
      *a3 = 0;
      a3[1] = 0;
    }
    return 0;
  }
  else
  {
    v28 = a2;
    initialNRoots = 0;
    totalKillListSize = 0;
    do
    {
      initialNRoots += (unsigned int)v3;
      v4 = 0;
      lastSize = 0;
      do
      {
        v5 = 4 * (v4 >> 10);
        v6 = 4 * (v4 & 0x3FF);
        v7 = *(_DWORD *)(v6 + *(_DWORD *)(*((_DWORD *)this + 5) + v5));
        if ( (v7 & 1) == 0 )
        {
          v8 = *(_DWORD *)(v7 + 8);
          if ( (v8 & 0x70000000) == 0x30000000 )
          {
            *(_DWORD *)(v7 + 8) = v8 & 0x8FFFFFFF | 0x10000000;
            (**(void (__thiscall ***)(int, int))v7)(a1: v7, a2: 1);
          }
          else
          {
            *(_DWORD *)(v7 + 8) = v8 & 0x7FFFFFFF;
            *(_DWORD *)(v7 + 12) = -1;
          }
          v9 = *((_DWORD *)this + 5);
          v10 = *(_DWORD *)(v6 + *(_DWORD *)(v9 + v5));
          v11 = *(_DWORD *)(v9 + 4 * (lastSize >> 10));
          v12 = lastSize++ & 0x3FF;
          *(_DWORD *)(v11 + 4 * v12) = v10;
          v3 = v32;
        }
        ++v4;
      }
      while ( v4 < (unsigned int)v3 );
      v13 = this;
      GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::Resize(
        this: (GAtomicValueBase<long> *)this + 2,
        newSize: lastSize,
        newNumPages: v28);
      for ( i = 0; i < lastSize; ++i )
      {
        v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * (i >> 10)) + 4 * (i & 0x3FF));
        if ( v15 != 0 )
        {
          v16 = *(_DWORD *)(v15 + 8);
          if ( (v16 & 0x70000000) == 0x10000000 )
          {
            if ( (v16 & 0xFFFFFFF) != 0 )
            {
              v17 = v16 & 0x8FFFFFFF;
              v27 = 2;
            }
            else
            {
              v17 = v16 & 0x8FFFFFFF | 0x20000000;
              v27 = 4;
            }
            *(_DWORD *)(v15 + 8) = v17;
            (**(void (__thiscall ***)(int, int))v15)(a1: v15, a2: v27);
          }
        }
      }
      for ( j = 0; j < lastSize; ++j )
      {
        v19 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * (j >> 10)) + 4 * (j & 0x3FF));
        if ( v19 != 0 )
        {
          *(_DWORD *)(v19 + 8) &= ~0x80000000;
          v20 = *(_DWORD *)(v19 + 8);
          *(_DWORD *)(v19 + 12) = -1;
          if ( (v20 & 0x70000000) == 0x20000000 && v20 >= 0 )
          {
            *(_DWORD *)(v19 + 8) = v20 & 0x8FFFFFFF;
            (**(void (__thiscall ***)(int, int))v19)(a1: v19, a2: 3);
            v21 = *(_DWORD *)(v19 + 4);
            if ( (*(_DWORD *)(v19 + 8) & 0x70000000) != 0x40000000 )
            {
              *(_DWORD *)(v19 + 4) = *(_DWORD *)(v21 + 28);
              *(_DWORD *)(v21 + 28) = v19;
              *(_DWORD *)(v19 + 8) = *(_DWORD *)(v19 + 8) & 0x8FFFFFFF | 0x40000000;
            }
          }
        }
      }
      GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::Resize(
        this: (GAtomicValueBase<long> *)this + 2,
        newSize: 0,
        newNumPages: v29);
      v22 = *((_DWORD **)this + 7);
      v23 = 0;
      *((_DWORD *)this + 6) = -1;
      if ( v22 != nullptr )
      {
        do
        {
          v24 = (_DWORD *)v22[1];
          (*(void (__thiscall **)(_DWORD *))(*v22 + 4))(a1: v22);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
          ++v23;
          v22 = v24;
        }
        while ( v24 != nullptr );
        v13 = this;
      }
      v3 = v13[2].__vftable;
      totalKillListSize += v23;
      v13[7].__vftable = nullptr;
      v32 = v3;
    }
    while ( v3 != nullptr );
    if ( a3 != nullptr )
    {
      v25 = initialNRoots;
      *a3 = initialNRoots;
      if ( initialNRoots >= totalKillListSize )
        v25 = totalKillListSize;
      a3[1] = v25;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068290
// Name: public: void GRefCountBaseGC<323>::Release(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall GRefCountBaseGC<323>::Release@<al>(int a1@<ecx>, int a2@<edi>)
{
  signed int v3; // eax
  GAtomicValueBase<long> *v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v12; // [esp+0h] [ebp-8h]

  v3 = *(_DWORD *)(a1 + 8);
  if ( (v3 & 0xFFFFFFF) != 0 )
  {
    *(_DWORD *)(a1 + 8) = --v3;
    if ( (v3 & 0xFFFFFFF) != 0 )
    {
      if ( (v3 & 0x70000000) != 0x30000000 )
      {
        v3 = v3 & 0x8FFFFFFF | 0x30000000;
        *(_DWORD *)(a1 + 8) = v3;
        if ( v3 >= 0 )
        {
          v5 = *(_DWORD *)(a1 + 4);
          v6 = v3 | 0x80000000;
          if ( *(_DWORD *)(v5 + 24) == -1 )
          {
            v10 = *(_DWORD *)(v5 + 8);
            *(_DWORD *)(a1 + 8) = v6;
            *(_DWORD *)(a1 + 12) = v10;
            *(_BYTE *)(v5 + 32) |= 1u;
            LOBYTE(v3) = GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::PushBackSafe(this: (GAtomicValueBase<long> *)(*(_DWORD *)(a1 + 4) + 8));
            if ( (_BYTE)v3 == 0 )
            {
              *(_BYTE *)(*(_DWORD *)(a1 + 4) + 32) &= ~1u;
              LOBYTE(v3) = GRefCountCollector<323>::Collect(this: *(IDataCacheSection **)(a1 + 4), a2: a1, a3: nullptr);
              *(_BYTE *)(*(_DWORD *)(a1 + 4) + 32) |= 1u;
              if ( (_BYTE)v3 == 0
                || (LOBYTE(v3) = GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::PushBackSafe(this: (GAtomicValueBase<long> *)(*(_DWORD *)(a1 + 4) + 8)),
                    (_BYTE)v3 == 0) )
              {
                *(_DWORD *)(a1 + 8) &= 0xFFFFFFFu;
                *(_DWORD *)(a1 + 12) = -1;
              }
            }
            *(_BYTE *)(*(_DWORD *)(a1 + 4) + 32) &= ~1u;
          }
          else
          {
            *(_DWORD *)(a1 + 12) = *(_DWORD *)(v5 + 24);
            *(_DWORD *)(a1 + 8) = v6;
            v7 = *(_DWORD *)(v5 + 24);
            v8 = *(_DWORD *)(v5 + 20);
            v9 = *(int *)(*(_DWORD *)(v8 + 4 * (v7 >> 10)) + 4 * (v7 & 0x3FF)) >> 1;
            *(_DWORD *)(*(_DWORD *)(v8 + 4 * (v7 >> 10)) + 4 * (v7 & 0x3FF)) = a1;
            v3 = *(_DWORD *)(a1 + 4);
            *(_DWORD *)(v3 + 24) = v9;
          }
        }
      }
    }
    else
    {
      (**(void (__thiscall ***)(int, _DWORD, int))a1)(a1, a2: 0, a3: a2);
      *(_DWORD *)(a1 + 8) &= 0x8FFFFFFF;
      if ( *(int *)(a1 + 8) < 0 )
      {
        v4 = *(GAtomicValueBase<long> **)(a1 + 4);
        if ( *(_DWORD *)(a1 + 12) + 1 == v4[2].Value )
        {
          GArrayPagedBase<GRefCountBaseGC<323> *,10,5,GAllocatorPagedLH_POD<GRefCountBaseGC<323> *,2>>::Resize(
            this: v4 + 2,
            newSize: *(_DWORD *)(a1 + 12),
            newNumPages: v12);
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)(v4[5].Value + 4 * (*(_DWORD *)(a1 + 12) >> 10)) + 4 * (*(_DWORD *)(a1 + 12) & 0x3FF)) = (2 * v4[6].Value) | 1;
          *(_DWORD *)(*(_DWORD *)(a1 + 4) + 24) = *(_DWORD *)(a1 + 12);
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 4))(a1);
      LOBYTE(v3) = ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(
                     a1: GMemory::pGlobalHeap,
                     a2: a1);
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100684C0
// Name: public: void GFxValue::ObjectInterface::ObjectRelease(class GFxValue __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxValue::ObjectInterface::ObjectRelease(
        CStringPool *this@<ecx>,
        int a2@<edi>,
        StringPoolCase_t val,
        IShaderAPI *pobj)
{
  PROCESSOR_IDLESTATE_POLICY *v5; // eax
  PROCESSOR_IDLESTATE_POLICY *savedregs; // [esp+0h] [ebp+0h]

  switch ( *(_DWORD *)(val + 4) & 0x8F )
  {
    case 4:
      if ( pobj[2].__vftable-- == (IShaderAPI_vtbl *)1 )
        GASStringNode::ReleaseNode();
      break;
    case 5:
      GRefCountImpl::Release(this: pobj - 3);
      break;
    case 6:
    case 7:
      v5 = GASObjectInterface::ToASObject(result: savedregs);
      GRefCountBaseGC<323>::Release(a1: (int)v5, a2);
      break;
    case 8:
      if ( (int)--pobj->__vftable <= 0 )
      {
        GFxCharacterHandle::~GFxCharacterHandle(this: (GFxCharacterHandle *)pobj);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: pobj);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068630
// Name: public: virtual GASFnCall::~GASFnCall(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GASFnCall::~GASFnCall(_DWORD *this)
{
  int v2; // ecx
  char v3; // al
  bool v4; // zf
  int v5; // ecx

  *this = &GASFnCall::`vftable';
  if ( (*(_BYTE *)(this + 5) & 2) == 0 )
  {
    v2 = *(this + 3);
    if ( v2 != 0 )
      v3 = GRefCountBaseGC<323>::Release(a1: v2, a2: 0);
  }
  v4 = (*(_BYTE *)(this + 5) & 1) == 0;
  *(this + 3) = 0;
  if ( v4 )
  {
    v5 = *(this + 4);
    if ( v5 != 0 )
      v3 = GRefCountBaseGC<323>::Release(a1: v5, a2: 0);
  }
  *(this + 4) = 0;
  *this = &GFxLogBase<GFxLoadProcess>::`vftable';
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100686D0
// Name: public: virtual void GASObject::Set__proto__(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASObject::Set__proto__(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *psc,
        CTSQueue<CFunctor *,0,1>::Node_t *psc_4)
{
  CTSQueue<CFunctor *,0,1>::Node_t *pNext; // edx
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *v6; // [esp-Ch] [ebp-28h]
  GASValue v7[4]; // [esp+8h] [ebp-14h] BYREF
  char v8; // [esp+1Bh] [ebp-1h] BYREF

  if ( this->m_Tail.value.pNode == nullptr )
  {
    pNext = this->m_Head.value.pNode[5].pNext;
    v6 = psc->pNext + 40;
    v8 = 3;
    LOBYTE(v7[0]) = 10;
    ((void (__thiscall *)(CTSQueue<CFunctor *,0,1> *, CTSQueue<CFunctor *,0,1>::Node_t *, CTSQueue<CFunctor *,0,1>::Node_t *, GASValue *, char *))pNext)(
      a1: this,
      a2: psc,
      a3: v6,
      a4: v7,
      a5: &v8);
    GASValue::~GASValue(this: v7);
  }
  if ( psc_4 != nullptr )
    psc_4[1].pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)(((int)&psc_4[1].pNext->pNext + 1) & 0x8FFFFFFF);
  pNode = this->m_Tail.value.pNode;
  if ( pNode != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)pNode, a2: (int)psc_4);
  this->m_Tail.value.pNode = psc_4;
}

//------------------------------------------------------------------------------
// Address: 0x100687D0
// Name: public: void GASSuperObject::ResetAltProto(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GASSuperObject::ResetAltProto(GASSuperObject *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // ecx

  v3 = *((_DWORD *)this + 14);
  if ( v3 != 0 )
  {
    *(_DWORD *)(v3 + 8) = (*(_DWORD *)(v3 + 8) + 1) & 0x8FFFFFFF;
    v4 = *((_DWORD *)this + 13);
    if ( v4 != 0 )
      GRefCountBaseGC<323>::Release(a1: v4, a2);
    *((_DWORD *)this + 13) = *((_DWORD *)this + 14);
    v5 = *((_DWORD *)this + 14);
    if ( v5 != 0 )
      GRefCountBaseGC<323>::Release(a1: v5, a2);
    *((_DWORD *)this + 14) = 0;
    v6 = *((_DWORD *)this + 13);
    if ( v6 != 0 )
      *(_DWORD *)(v6 + 8) = (*(_DWORD *)(v6 + 8) + 1) & 0x8FFFFFFF;
    v7 = *((_DWORD *)this + 6);
    if ( v7 != 0 )
      GRefCountBaseGC<323>::Release(a1: v7, a2);
    *((_DWORD *)this + 6) = *((_DWORD *)this + 13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068840
// Name: public: virtual bool GASObject::DoesImplement(class GASEnvironment __near *,class GASObject const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GASObject::DoesImplement(
        CTSQueue<CFunctor *,0,1> *this,
        CFunctor **__formal,
        CTSQueue<CFunctor *,0,1> *prototype)
{
  return this == prototype;
}

//------------------------------------------------------------------------------
// Address: 0x10068850
// Name: public: virtual enum GASObjectInterface::ObjectType GASFunctionObject::GetObjectType(void)const
// Source: json
//------------------------------------------------------------------------------
_MENU_EVENT_RECORD GASFunctionObject::GetObjectType()
{
  return (_MENU_EVENT_RECORD)23;
}

//------------------------------------------------------------------------------
// Address: 0x10068870
// Name: protected: virtual void GASUserDefinedFunctionObject::Finalize_GC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASUserDefinedFunctionObject::Finalize_GC(GASObject *this)
{
  IShaderAPI *v2; // ecx

  v2 = *((IShaderAPI **)this + 13);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  *((_DWORD *)this + 13) = 0;
  GASObject::Finalize_GC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10068890
// Name: public: virtual bool GASUserDefinedFunctionObject::IsNull(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GASUserDefinedFunctionObject::IsNull(GASUserDefinedFunctionObject *this)
{
  return *((_DWORD *)this + 13) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100688F0
// Name: public: virtual class GASFunctionRef GASObjectInterface::Get__constructor__(class GASStringContext __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASObjectInterface::Get__constructor__(void *this, int a2, _DWORD *psc)
{
  unsigned __int8 (__thiscall *v3)(void *, _DWORD *, int, GASValue *); // eax
  int v5; // [esp-8h] [ebp-20h]
  GASValue val[4]; // [esp+8h] [ebp-10h] BYREF

  v5 = *psc + 328;
  v3 = *(unsigned __int8 (__thiscall **)(void *, _DWORD *, int, GASValue *))(*(_DWORD *)this + 44);
  LOBYTE(val[0]) = 0;
  if ( v3(a1: this, a2: psc, a3: v5, a4: val) != 0 )
  {
    GASValue::ToFunction(a1: a2, a2: 0);
  }
  else
  {
    *(_BYTE *)(a2 + 8) = 0;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
  }
  GASValue::~GASValue(this: val);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10068960
// Name: public: void GFxMovieRoot::ASValue2GFxValue(class GASEnvironment __near *,class GASValue const __near &,class GFxValue __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::ASValue2GFxValue(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *this,
        tagPOLYTEXTW *result,
        tagWNDCLASSW *value,
        int toType)
{
  StringPoolCase_t v4; // esi
  int v5; // eax
  tagWNDCLASSW *v6; // edi
  IShaderDevice *v8; // eax
  bool v9; // zf
  unsigned int Length; // eax
  int v11; // ecx
  unsigned int v12; // edi
  GFxMovieRoot::WideStringStorage *v13; // eax
  GFxMovieRoot::WideStringStorage *v14; // edi
  _SERVICE_STATUS *v15; // edi
  PROCESSOR_IDLESTATE_POLICY *v16; // eax
  int v17; // eax
  GASObjectInterface *v18; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v19; // eax
  IShaderDevice *v20; // eax
  tagPOLYTEXTW *v21; // [esp-4h] [ebp-10h]
  tagPOLYTEXTW *v22; // [esp-4h] [ebp-10h]
  IShaderDevice *v23; // [esp-4h] [ebp-10h]
  PROCESSOR_IDLESTATE_POLICY *v24; // [esp+0h] [ebp-Ch]

  v4 = toType;
  v5 = *(_DWORD *)(toType + 4);
  v6 = value;
  if ( (v5 & 0x80u) == 0 )
  {
    switch ( LOBYTE(value->style) )
    {
      case 0:
      case 0xA:
        toType = 0;
        break;
      case 1:
        toType = 1;
        break;
      case 2:
        toType = 2;
        break;
      case 3:
      case 4:
        toType = 3;
        break;
      case 6:
      case 8:
        toType = 6;
        break;
      case 7:
        toType = 8;
        break;
      default:
        toType = 4;
        break;
    }
  }
  else
  {
    toType = *(_DWORD *)(toType + 4) & 0xF;
  }
  if ( (v5 & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: *(CStringPool **)v4,
      a2: (int)value,
      val: v4,
      pobj: *(IShaderAPI **)(v4 + 8));
    *(_DWORD *)v4 = 0;
  }
  switch ( toType )
  {
    case 0:
    case 1:
      *(_DWORD *)(v4 + 4) = toType;
      return;
    case 2:
      v21 = result;
      *(_DWORD *)(v4 + 4) = 2;
      *(_BYTE *)(v4 + 8) = (unsigned __int8)GASValue::ToBool(result: v21);
      return;
    case 3:
      v22 = result;
      *(_DWORD *)(v4 + 4) = 3;
      *(double *)(v4 + 8) = GASValue::ToNumber(this: (GASValue *)v6, a2: (struct GASEnvironment *)v22);
      return;
    case 4:
      GASValue::ToStringImpl(a1: v6, a2: &result, a3: result, a4: -1, a5: 0);
      v8 = (IShaderDevice *)result;
      *(_DWORD *)(v4 + 4) = 68;
      *(_DWORD *)(v4 + 8) = v8;
      *(_DWORD *)v4 = *((_DWORD *)this + 4);
      GFxValue::ObjectInterface::ObjectAddRef(this: *((CStringPool **)this + 4), val: v4, pobj: v8);
      goto LABEL_18;
    case 5:
      GASValue::ToStringImpl(a1: v6, a2: &result, a3: result, a4: -1, a5: 0);
      value = (tagWNDCLASSW *)result;
      Length = GASString::GetLength(this: (GASString *)&result);
      v11 = *((_DWORD *)this + 8);
      v12 = Length + 1;
      toType = 326;
      v13 = (GFxMovieRoot::WideStringStorage *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v11 + 40))(
                                                 a1: v11,
                                                 a2: 2 * (Length + 1) + 15,
                                                 a3: &toType);
      *(_DWORD *)(v4 + 4) = 69;
      if ( v13 != nullptr )
        v14 = GFxMovieRoot::WideStringStorage::WideStringStorage(this: v13, a2: (GColor *)value, a3: v12);
      else
        v14 = nullptr;
      *(_DWORD *)(v4 + 8) = v14 + 3;
      *(_DWORD *)v4 = *((_DWORD *)this + 4);
      GFxValue::ObjectInterface::ObjectAddRef(
        this: *((CStringPool **)this + 4),
        val: v4,
        pobj: (IShaderDevice *)v14 + 3);
      if ( v14 != nullptr )
        GRefCountImpl::Release(this: (IShaderAPI *)v14);
LABEL_18:
      v9 = result->n-- == 1;
      if ( v9 )
        GASStringNode::ReleaseNode();
      return;
    case 6:
      value = (tagWNDCLASSW *)6;
      v15 = GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
      if ( (unsigned int)((*(int (__thiscall **)(_SERVICE_STATUS *))(v15->dwServiceType + 8))(a1: v15) - 6) > 0x26
        || (v16 = GASObjectInterface::ToASObject(result: v24),
            v9 = (*(int (__thiscall **)(PROCESSOR_IDLESTATE_INFO *))(v16->Policy[1].TimeCheck + 8))(a1: &v16->Policy[1]) == 7,
            v17 = 7,
            !v9) )
      {
        v17 = (int)value;
      }
      *(_DWORD *)(v4 + 4) = v17 | 0x40;
      *(_DWORD *)(v4 + 8) = v15;
      v23 = (IShaderDevice *)v15;
      goto LABEL_33;
    case 8:
      v18 = (GASObjectInterface *)GASValue::ToObjectInterface((_SERVICE_STATUS *)result);
      v19 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToASCharacter(this: v18);
      *(_DWORD *)(v4 + 4) = 72;
      if ( DWORD1(v19[6].m_pfnProxied) != 0 )
        v20 = (IShaderDevice *)DWORD1(v19[6].m_pfnProxied);
      else
        GFxASCharacter::CreateCharacterHandle(this: v19);
      *(_DWORD *)(v4 + 8) = v20;
      v23 = v20;
LABEL_33:
      *(_DWORD *)v4 = *((_DWORD *)this + 4);
      GFxValue::ObjectInterface::ObjectAddRef(this: *((CStringPool **)this + 4), val: v4, pobj: v23);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068BF0
// Name: public: virtual void GFxMovieRoot::CreateString(class GFxValue __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::CreateString(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *a1@<ecx>,
        void *pvalue,
        GMemoryHeap *pstring,
        int a4,
        const char *a5,
        int a6)
{
  tagPOLYTEXTW *v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v8; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v9; // esi
  GASValue v11[4]; // [esp+Ch] [ebp-10h] BYREF

  v7 = (tagPOLYTEXTW *)(*((int (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *))a1[6].dtr_GSysAllocBase
                        + 28))(a1: a1[6].__vftable);
  GASStringManager::CreateStringNode(this: *(const char **)(v7[3].x + 636));
  v9 = v8;
  ++v8->m_nGrowSize;
  LOBYTE(v11[0]) = 5;
  v11[1] = v8;
  ++v8->m_nGrowSize;
  GFxMovieRoot::ASValue2GFxValue(this: a1, result: v7, value: (tagWNDCLASSW *)v11, toType: (int)pvalue);
  GASValue::~GASValue(this: v11);
  if ( v9->m_nGrowSize-- == 1 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x10068C60
// Name: public: virtual void GFxMovieRoot::CreateArray(class GFxValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::CreateArray(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *a1@<ecx>,
        void *pvalue,
        GMemoryHeap *a3)
{
  int v4; // esi
  struct GASObject *v5; // edi
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *asval; // [esp+Ch] [ebp-10h] BYREF

  v4 = (*((int (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *))a1[6].dtr_GSysAllocBase
        + 28))(a1: a1[6].__vftable);
  v5 = GASEnvironment::OperatorNew(
         this: (GASEnvironment *)v4,
         a2: *(struct GASObject **)(*(_DWORD *)(v4 + 120) + 680),
         a3: (const struct GASString *)(*(_DWORD *)(v4 + 120) + 16),
         nargs: 0,
         argsTopOff: -1);
  GASValue::GASValue(this: &asval, a2: v5);
  GFxMovieRoot::ASValue2GFxValue(
    this: a1,
    result: (tagPOLYTEXTW *)v4,
    value: (tagWNDCLASSW *)&asval,
    toType: (int)pvalue);
  GASValue::~GASValue(this: &asval);
  if ( v5 != nullptr )
    GRefCountBaseGC<323>::Release(a1: (int)v5, a2: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10068CD0
// Name: public: virtual void GFxMovieRoot::CreateFunction(class GFxValue __near *,class GFxFunctionHandler __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::CreateFunction(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *a1@<ecx>,
        void *pvalue,
        IShaderDevice *pfc,
        const char *puserData,
        int a5)
{
  tagPOLYTEXTW *v6; // eax
  struct GASStringContext *v7; // edi
  int v8; // ecx
  int (__thiscall *v9)(int, int, int *); // edx
  GASFunctionObject *v10; // eax
  int v11; // esi
  IShaderDevice *v12; // ecx
  CTSQueue<CFunctor *,0,1>::Node_t *Prototype; // eax
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *asval; // [esp+Ch] [ebp-28h] BYREF
  int v15; // [esp+1Ch] [ebp-18h] BYREF
  int v16; // [esp+20h] [ebp-14h]
  char v17; // [esp+24h] [ebp-10h]
  tagPOLYTEXTW *v18; // [esp+28h] [ebp-Ch]
  int v19; // [esp+30h] [ebp-4h] BYREF

  v6 = (tagPOLYTEXTW *)(*((int (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *))a1[6].dtr_GSysAllocBase
                        + 28))(a1: a1[6].__vftable);
  v7 = (struct GASStringContext *)&v6[3];
  LOBYTE(asval) = 0;
  v18 = v6;
  v8 = *(_DWORD *)(v6[3].x + 656);
  v9 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v8 + 40);
  v19 = 323;
  v10 = (GASFunctionObject *)v9(a1: v8, a2: 60, a3: &v19);
  v11 = (int)v10;
  if ( v10 != nullptr )
  {
    GASFunctionObject::GASFunctionObject(this: v10, a2: v7);
    v12 = pfc;
    *(_DWORD *)v11 = &GASUserDefinedFunctionObject::`vftable'{for `GASRefCountBase<GASObject>'};
    *(_DWORD *)(v11 + 16) = &GASUserDefinedFunctionObject::`vftable'{for `GASObjectInterface'};
    if ( pfc != nullptr )
    {
      GRefCountImpl::AddRef(this: pfc);
      v12 = pfc;
    }
    *(_DWORD *)(v11 + 52) = v12;
    *(_DWORD *)(v11 + 56) = puserData;
    Prototype = (CTSQueue<CFunctor *,0,1>::Node_t *)GASGlobalContext::GetPrototype(result: (vc_attributes::InvalidCheckAttribute *)7);
    GASObject::Set__proto__(
      this: (CTSQueue<CFunctor *,0,1> *)(v11 + 16),
      psc: (CTSQueue<CFunctor *,0,1>::Node_t *)v7,
      psc_4: Prototype);
  }
  else
  {
    v11 = 0;
  }
  v17 = 0;
  v15 = v11;
  if ( v11 != 0 )
    *(_DWORD *)(v11 + 8) = (*(_DWORD *)(v11 + 8) + 1) & 0x8FFFFFFF;
  v16 = 0;
  GASValue::SetAsFunction(this: &asval, a2: (const struct GASFunctionRefBase *)&v15);
  if ( (v17 & 2) == 0 && v15 != 0 )
    GRefCountBaseGC<323>::Release(a1: v15, a2: (int)v7);
  v15 = 0;
  if ( (v17 & 1) == 0 && v16 != 0 )
    GRefCountBaseGC<323>::Release(a1: v16, a2: (int)v7);
  GFxMovieRoot::ASValue2GFxValue(this: a1, result: v18, value: (tagWNDCLASSW *)&asval, toType: (int)pvalue);
  if ( v11 != 0 )
    GRefCountBaseGC<323>::Release(a1: v11, a2: (int)v7);
  GASValue::~GASValue(this: &asval);
}

//------------------------------------------------------------------------------
// Address: 0x10068E20
// Name: public: bool GFxValue::ObjectInterface::Invoke(void __near *,class GFxValue __near *,char const __near *,class GFxValue const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxValue::ObjectInterface::Invoke(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pthis,
        struct GFxValue *a3,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a4,
        const struct GFxValue *a5,
        struct GASStringNode *nargs,
        struct GASStringNode *isdobj)
{
  GFxAmpViewStats *v8; // edi
  float v9; // ecx
  int v10; // eax
  float v11; // ecx
  tagPOLYTEXTW *v13; // eax
  tagPOLYTEXTW *v14; // esi
  GASStringManager *v15; // ecx
  char v16; // bl
  float v18; // ecx
  unsigned int v19; // ebx
  __vc_attributes::iid_isAttribute *v20; // esi
  const struct GFxValue *v21; // edi
  GASValue *limited_expression; // ecx
  unsigned int *p_n; // esi
  float v24; // ecx
  _IMAGE_SYMBOL_EX v25; // [esp-8h] [ebp-64h]
  GFxAmpViewStats *v26; // [esp+14h] [ebp-48h]
  GASValue asArg[4]; // [esp+24h] [ebp-38h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *member; // [esp+34h] [ebp-28h] BYREF
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v29; // [esp+44h] [ebp-18h] BYREF
  GFxMovieRoot **v30; // [esp+54h] [ebp-8h]
  tagPOLYTEXTW *v31; // [esp+58h] [ebp-4h]

  v8 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v30 = (GFxMovieRoot **)this;
  v26 = v8;
  if ( v8 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 0x27u);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v25.Value, a3: (float *)v25.SectionNumber);
  }
  if ( (_BYTE)isdobj != 0
    && ((GFxCharacterHandle::ResolveCharacter(this: pthis, a2: (GFxMovieRoot *)this->pMovieRoot), v10 == 0)
     || (pthis = (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v10 + 120),
         v10 == -120)) )
  {
    if ( v8 != nullptr )
    {
      GTimer::GetRawTicks(li: v11, a2: *(float *)&v25.Value, a3: (float *)v25.SectionNumber);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return false;
  }
  else
  {
    v13 = (tagPOLYTEXTW *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->pMovieRoot + 12) + 112))(a1: *((_DWORD *)this->pMovieRoot + 12));
    v14 = v13 + 3;
    LOBYTE(member) = 0;
    LOBYTE(v29) = 0;
    v15 = *(GASStringManager **)(v13[3].x + 636);
    v31 = v13;
    isdobj = GASStringManager::CreateConstStringNode(this: v15, result: a4, a3: strlen((const char *)a4), a4: 0);
    ++*((_DWORD *)isdobj + 2);
    v16 = ((int (__thiscall *)(CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, tagPOLYTEXTW *, struct GASStringNode **, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))pthis->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[2].operator())(
            a1: pthis,
            a2: v14,
            a3: &isdobj,
            a4: &member);
    if ( (*((_DWORD *)isdobj + 2))-- == 1 )
      GASStringNode::ReleaseNode();
    if ( v16 != 0 )
    {
      v19 = (unsigned int)nargs;
      LOBYTE(asArg[0]) = 0;
      if ( (int)nargs - 1 > -1 )
      {
        v20 = (__vc_attributes::iid_isAttribute *)v31;
        v21 = &a5[(int)nargs - 1];
        for ( isdobj = nargs; isdobj != nullptr; isdobj = (struct GASStringNode *)((char *)isdobj - 1) )
        {
          v25.N.Name.Long = (unsigned int)asArg;
          v25.N.Name.Short = (unsigned int)v21;
          GFxMovieRoot::GFxValue2ASValue(this: *v30, a2: v25);
          v20[2].limited_expression += 16;
          if ( v20[2].limited_expression >= v20[4].limited_expression )
            GASPagedStack<GASValue,32>::PushPage(this: v20 + 2, a2: (const char *)v25.Value);
          limited_expression = (GASValue *)v20[2].limited_expression;
          if ( limited_expression != nullptr )
            GASValue::GASValue(this: limited_expression, a2: (const struct GASValue *)asArg);
          --v21;
        }
      }
      p_n = &v31->n;
      HIBYTE(isdobj) = (unsigned __int8)GAS_Invoke(result: (_LOAD_DLL_DEBUG_INFO *)&member);
      if ( nargs != nullptr )
      {
        do
        {
          GASValue::~GASValue(this: (GASValue *)*p_n);
          *p_n -= 16;
          if ( *p_n < p_n[1] )
            GASPagedStack<GASValue,32>::PopPage(
              this: (__vc_attributes::iid_isAttribute *)p_n,
              a2: (const char *)v25.Value);
          --v19;
        }
        while ( v19 != 0 );
      }
      if ( a3 != nullptr )
        GFxMovieRoot::ASValue2GFxValue(
          this: (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)*v30,
          result: v31,
          value: (tagWNDCLASSW *)&v29,
          toType: (int)a3);
      GASValue::~GASValue(this: asArg);
      GASValue::~GASValue(this: &v29);
      GASValue::~GASValue(this: &member);
      if ( v26 != nullptr )
      {
        GTimer::GetRawTicks(li: v24, a2: *(float *)&v25.Value, a3: (float *)v25.SectionNumber);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return HIBYTE(isdobj);
    }
    else
    {
      GASValue::~GASValue(this: &v29);
      GASValue::~GASValue(this: &member);
      if ( v8 != nullptr )
      {
        GTimer::GetRawTicks(li: v18, a2: *(float *)&v25.Value, a3: (float *)v25.SectionNumber);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100690C0
// Name: public: bool GFxValue::ObjectInterface::SetText(void __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetText(
        GFxMovieRoot **this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result,
        const char *a3,
        int reqHtml)
{
  GFxAmpViewStats *v5; // esi
  float v6; // ecx
  int v7; // eax
  float v8; // ecx
  int v9; // edi
  int *p_m_nGrowSize; // eax
  float v12; // ecx
  char v13; // bl
  float v14; // ecx
  float v15; // [esp+0h] [ebp-34h]
  float *v16; // [esp+4h] [ebp-30h]
  GFxValue v17; // [esp+24h] [ebp-10h] BYREF

  v5 = *((GFxAmpViewStats **)*this + 2577);
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0x39u);
    GTimer::GetRawTicks(li: v6, a2: v15, a3: v16);
  }
  GFxCharacterHandle::ResolveCharacter(this: result, a2: *this);
  v9 = v7;
  if ( v7 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 176))(a1: v7) == 4 )
    {
      (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 372))(a1: v9, a2: a3, a3: reqHtml);
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v14, a2: v15, a3: v16);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 1;
    }
    else
    {
      v17.pObjectInterface = nullptr;
      v17.Type = VT_String;
      v17.Value.pString = a3;
      p_m_nGrowSize = &stru_10299FCC.m_Memory.m_nGrowSize;
      if ( (_BYTE)reqHtml == 0 )
        p_m_nGrowSize = (int *)&stru_10299FCC;
      v13 = GFxValue::ObjectInterface::SetMember(
              (CStringPool *)this,
              pdata: result,
              a3: (int)p_m_nGrowSize,
              a4: &v17,
              isdobj: 1);
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v12, a2: v15, a3: v16);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return v13;
    }
  }
  else
  {
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v8, a2: v15, a3: v16);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100691E0
// Name: public: bool GFxValue::ObjectInterface::SetText(void __near *,wchar_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::SetText(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *a2,
        const wchar_t *a3,
        int a4)
{
  GFxAmpViewStats *v5; // esi
  float v6; // ecx
  int v7; // eax
  float v8; // ecx
  int v9; // edi
  int *p_m_nGrowSize; // eax
  float v12; // ecx
  char v13; // bl
  float v14; // ecx
  float v15; // [esp+0h] [ebp-34h]
  float *v16; // [esp+4h] [ebp-30h]
  GFxValue v17; // [esp+24h] [ebp-10h] BYREF

  v5 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0x39u);
    GTimer::GetRawTicks(li: v6, a2: v15, a3: v16);
  }
  GFxCharacterHandle::ResolveCharacter(this: a2, a2: (GFxMovieRoot *)this->pMovieRoot);
  v9 = v7;
  if ( v7 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 176))(a1: v7) == 4 )
    {
      (*(void (__thiscall **)(int, const wchar_t *, int))(*(_DWORD *)v9 + 368))(a1: v9, a2: a3, a3: a4);
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v14, a2: v15, a3: v16);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 1;
    }
    else
    {
      v17.pObjectInterface = nullptr;
      v17.Type = VT_StringW;
      v17.Value.pString = (const char *)a3;
      p_m_nGrowSize = &stru_10299FCC.m_Memory.m_nGrowSize;
      if ( (_BYTE)a4 == 0 )
        p_m_nGrowSize = (int *)&stru_10299FCC;
      v13 = GFxValue::ObjectInterface::SetMember(
              (CStringPool *)this,
              pdata: a2,
              a3: (int)p_m_nGrowSize,
              a4: &v17,
              isdobj: 1);
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v12, a2: v15, a3: v16);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return v13;
    }
  }
  else
  {
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v8, a2: v15, a3: v16);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069300
// Name: public: void GFxValue::SetUndefined(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxValue::SetUndefined(StringPoolCase_t a1@<ecx>, int a2@<edi>)
{
  if ( (*(_DWORD *)(a1 + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)a1, a2, val: a1, pobj: *(IShaderAPI **)(a1 + 8));
    *(_DWORD *)a1 = 0;
  }
  *(_DWORD *)(a1 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10069330
// Name: public: virtual void GFxMovieRoot::CreateStringW(class GFxValue __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::CreateStringW(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *a1@<ecx>,
        void *pvalue,
        GMemoryHeap *pstring,
        const char *penv,
        int pstring_8)
{
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *StringNode; // esi
  tagPOLYTEXTW *v7; // eax
  GASValue v9[4]; // [esp+Ch] [ebp-14h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  v10 = (*((int (__thiscall **)(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl *))a1[6].dtr_GSysAllocBase
         + 28))(a1: a1[6].__vftable);
  StringNode = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)GASStringManager::CreateStringNode(
                                                                                            this: *(GASStringManager **)(*(_DWORD *)(v10 + 120) + 636),
                                                                                            a2: (const wchar_t *)pstring);
  ++StringNode->m_nGrowSize;
  if ( (*((_DWORD *)pvalue + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: *(CStringPool **)pvalue,
      a2: (int)pvalue,
      val: (StringPoolCase_t)pvalue,
      pobj: *((IShaderAPI **)pvalue + 2));
    *(_DWORD *)pvalue = 0;
  }
  v7 = (tagPOLYTEXTW *)v10;
  *((_DWORD *)pvalue + 1) = 133;
  LOBYTE(v9[0]) = 5;
  v9[1] = StringNode;
  ++StringNode->m_nGrowSize;
  GFxMovieRoot::ASValue2GFxValue(this: a1, result: v7, value: (tagWNDCLASSW *)v9, toType: (int)pvalue);
  GASValue::~GASValue(this: v9);
  if ( StringNode->m_nGrowSize-- == 1 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x100693C0
// Name: public: virtual void GFxMovieRoot::CreateObject(class GFxValue __near *,char const __near *,class GFxValue const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::CreateObject(
        GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *this,
        void *pvalue,
        GMemoryHeap *className,
        int a4,
        unsigned int nargs)
{
  int v5; // esi
  int *v6; // ecx
  int v7; // eax
  struct GASObject *v8; // edi
  int (__thiscall *v9)(int *); // edx
  int v10; // eax
  GASEnvironment *v11; // ebx
  unsigned int v12; // edi
  GASValue *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // esi
  int v19; // ebx
  int v20; // eax
  GASEnvironment *v21; // esi
  struct GASObject *v22; // ecx
  unsigned int v23; // eax
  struct GASObject *v24; // eax
  struct GASObject *v25; // esi
  bool v26; // zf
  struct GASObject *v27; // esi
  int v28; // eax
  tagWNDCLASSW *v29; // eax
  _DWORD *v30; // esi
  unsigned int v31; // eax
  struct GASObject *v32; // ecx
  unsigned int v33; // eax
  StringPoolCase_t v34; // eax
  struct GASObject *v35; // eax
  tagWNDCLASSW *v36; // eax
  _IMAGE_SYMBOL_EX v37; // [esp-8h] [ebp-144h]
  StringPoolCase_t v38; // [esp-4h] [ebp-140h]
  StringPoolCase_t v39; // [esp-4h] [ebp-140h]
  GASValue pkgObjVal[4]; // [esp+Ch] [ebp-130h] BYREF
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *v41; // [esp+1Ch] [ebp-120h]
  int v42; // [esp+20h] [ebp-11Ch] BYREF
  int v43; // [esp+24h] [ebp-118h]
  GASEnvironment *v44; // [esp+28h] [ebp-114h]
  StringPoolCase_t val; // [esp+2Ch] [ebp-110h]
  struct GASObject *v46; // [esp+30h] [ebp-10Ch]
  unsigned int i; // [esp+34h] [ebp-108h] BYREF
  unsigned __int8 dst[256]; // [esp+38h] [ebp-104h] BYREF

  v5 = nargs;
  v41 = this;
  v6 = *((int **)this + 12);
  val = (StringPoolCase_t)pvalue;
  v7 = *v6;
  v8 = (struct GASObject *)className;
  v42 = a4;
  v9 = *(int (__thiscall **)(int *))(v7 + 112);
  v46 = (struct GASObject *)className;
  v43 = nargs;
  v10 = v9(a1: v6);
  v11 = (GASEnvironment *)v10;
  v44 = (GASEnvironment *)v10;
  if ( className == nullptr )
  {
    v35 = GASEnvironment::OperatorNew(
            this: (GASEnvironment *)v10,
            a2: *(struct GASObject **)(*(_DWORD *)(v10 + 120) + 680),
            a3: (const struct GASString *)(*(_DWORD *)(v10 + 120) + 12),
            nargs: 0,
            argsTopOff: -1);
    v39 = val;
    v8 = v35;
    v36 = (tagWNDCLASSW *)GASValue::GASValue(this: pkgObjVal, a2: v35);
    GFxMovieRoot::ASValue2GFxValue(this: v41, result: (tagPOLYTEXTW *)v11, value: v36, toType: v39);
    GASValue::~GASValue(this: pkgObjVal);
LABEL_50:
    if ( v8 == nullptr )
      return;
    v32 = v8;
    goto LABEL_52;
  }
  if ( nargs != 0 && (int)(nargs - 1) > -1 )
  {
    v12 = v42 + 16 * (nargs - 1);
    for ( i = nargs; i != 0; --i )
    {
      v37.N.Name.Long = (unsigned int)pkgObjVal;
      v37.N.Name.Short = v12;
      LOBYTE(pkgObjVal[0]) = 0;
      GFxMovieRoot::GFxValue2ASValue(this: (GFxMovieRoot *)v41, a2: v37);
      *((_DWORD *)v11 + 2) += 16;
      if ( *((_DWORD *)v11 + 2) >= *((_DWORD *)v11 + 4) )
        GASPagedStack<GASValue,32>::PushPage(
          this: (__vc_attributes::iid_isAttribute *)v11 + 2,
          a2: (const char *)v37.Value);
      v13 = *((GASValue **)v11 + 2);
      if ( v13 != nullptr )
        GASValue::GASValue(this: v13, a2: (const struct GASValue *)pkgObjVal);
      GASValue::~GASValue(this: pkgObjVal);
      v12 -= 16;
    }
    v8 = v46;
  }
  strchr(string: (unsigned __int8 *)v8, chr: 0x2Eu);
  if ( v14 == 0 )
  {
    GASStringManager::CreateStringNode(this: *(const char **)(*((_DWORD *)v11 + 30) + 636));
    i = v33;
    ++*(_DWORD *)(v33 + 8);
    v8 = GASEnvironment::OperatorNew(
           this: v11,
           a2: *(struct GASObject **)(*((_DWORD *)v11 + 30) + 680),
           a3: (const struct GASString *)&i,
           nargs,
           argsTopOff: -1);
    v26 = (*(_DWORD *)(i + 8))-- == 1;
    if ( v26 )
      GASStringNode::ReleaseNode();
LABEL_31:
    if ( v8 != nullptr )
    {
      v38 = val;
      v29 = (tagWNDCLASSW *)GASValue::GASValue(this: pkgObjVal, a2: v8);
      GFxMovieRoot::ASValue2GFxValue(this: v41, result: (tagPOLYTEXTW *)v11, value: v29, toType: v38);
      GASValue::~GASValue(this: pkgObjVal);
    }
    else
    {
      v34 = val;
      if ( (*(_DWORD *)(val + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: *(CStringPool **)val,
          a2: 0,
          val,
          pobj: *(IShaderAPI **)(val + 8));
        v34 = val;
        *(_DWORD *)val = 0;
      }
      *(_DWORD *)(v34 + 4) = 0;
    }
    for ( ; v5 != 0; --v5 )
    {
      GASValue::~GASValue(this: *((GASValue **)v11 + 2));
      *((_DWORD *)v11 + 2) -= 16;
      if ( *((_DWORD *)v11 + 2) < *((_DWORD *)v11 + 3) )
        GASPagedStack<GASValue,32>::PopPage(
          this: (__vc_attributes::iid_isAttribute *)v11 + 2,
          a2: (const char *)v37.Value);
    }
    goto LABEL_50;
  }
  v15 = *((_DWORD *)v11 + 30);
  v16 = *(_DWORD *)(v15 + 680);
  if ( v16 != 0 )
    *(_DWORD *)(v16 + 8) = (*(_DWORD *)(v16 + 8) + 1) & 0x8FFFFFFF;
  v46 = *(struct GASObject **)(v15 + 680);
  while ( 1 )
  {
    strchr(string: (unsigned __int8 *)v8, chr: 0x2Eu);
    if ( v17 == 0 )
    {
LABEL_26:
      GASStringManager::CreateStringNode(this: *(const char **)(*((_DWORD *)v44 + 30) + 636));
      v27 = v46;
      v42 = v28;
      ++*(_DWORD *)(v28 + 8);
      v8 = GASEnvironment::OperatorNew(
             this: v44,
             a2: v27,
             a3: (const struct GASString *)&v42,
             nargs: v43,
             argsTopOff: -1);
      v26 = (*(_DWORD *)(v42 + 8))-- == 1;
      if ( v26 )
        GASStringNode::ReleaseNode();
      if ( v27 != nullptr )
        GRefCountBaseGC<323>::Release(a1: (int)v27, a2: (int)v8);
      v5 = v43;
      v11 = v44;
      goto LABEL_31;
    }
    v18 = v17 - (_DWORD)v8 + 1;
    v19 = v17 + 1;
    if ( v18 > 0x100 )
      v18 = 256;
    memcpy(dst, src: (unsigned __int8 *)v8, count: v18 - 1);
    dst[v18 - 1] = 0;
    v20 = *((_DWORD *)v44 + 30);
    v21 = v44 + 30;
    LOBYTE(pkgObjVal[0]) = 0;
    v8 = (struct GASObject *)v19;
    GASStringManager::CreateStringNode(this: *(const char **)(v20 + 636));
    v22 = v46;
    i = v23;
    ++*(_DWORD *)(v23 + 8);
    if ( ((unsigned __int8 (__thiscall *)(struct GASObject *, GASEnvironment *, unsigned int *, GASValue *))v22[2].pNode[5].elem)(
           a1: &v22[2],
           a2: v21,
           a3: &i,
           a4: pkgObjVal) == 0 )
      break;
    v24 = GASValue::ToObject(this: pkgObjVal, a2: nullptr);
    v25 = v24;
    if ( v24 != nullptr )
      v24[1].pNode = (CTSQueue<CFunctor *,0,1>::Node_t *)(((((int)&v24[1].pNode->pNext + 1) & 0x8FFFFFFF) + 1)
                                                        & 0x8FFFFFFF);
    GRefCountBaseGC<323>::Release(a1: (int)v46, a2: v19);
    v26 = (*(_DWORD *)(i + 8))-- == 1;
    v46 = v25;
    if ( v26 )
      GASStringNode::ReleaseNode();
    if ( v25 != nullptr )
      GRefCountBaseGC<323>::Release(a1: (int)v25, a2: v19);
    GASValue::~GASValue(this: pkgObjVal);
    if ( v19 == 0 )
      goto LABEL_26;
  }
  v30 = (_DWORD *)val;
  if ( (*(_DWORD *)(val + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)val, a2: v19, val, pobj: *(IShaderAPI **)(val + 8));
    *v30 = 0;
  }
  v31 = i;
  v30[1] = 0;
  v26 = (*(_DWORD *)(v31 + 8))-- == 1;
  if ( v26 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: pkgObjVal);
  v32 = v46;
  if ( v46 != nullptr )
LABEL_52:
    GRefCountBaseGC<323>::Release(a1: (int)v32, a2: (int)v8);
}

//------------------------------------------------------------------------------
// Address: 0x100697F0
// Name: public: bool GFxValue::ObjectInterface::GetMember(void __near *,char const __near *,class GFxValue __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::GetMember(
        GFxMovieRoot **this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result,
        int a3,
        StringPoolCase_t val,
        int isdobj)
{
  GFxAmpViewStats *v6; // ebx
  float v7; // ecx
  GASObjectInterface *v8; // esi
  int v9; // eax
  float v10; // ecx
  GFxMovieRoot *v12; // edx
  int v13; // edi
  int v14; // eax
  bool v15; // bl
  float v17; // ecx
  struct GASObjectInterface *v18; // ebx
  PROCESSOR_IDLESTATE_POLICY *v19; // eax
  struct GFxASCharacter *v20; // eax
  float v21; // ecx
  PROCESSOR_IDLESTATE_POLICY *v22; // [esp+0h] [ebp-38h]
  float *v23; // [esp+4h] [ebp-34h]
  GFxAmpViewStats *v24; // [esp+14h] [ebp-24h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *asval; // [esp+24h] [ebp-14h] BYREF
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> **v26; // [esp+34h] [ebp-4h]

  v6 = *((GFxAmpViewStats **)*this + 2577);
  v26 = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> **)this;
  v24 = v6;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x25u);
    GTimer::GetRawTicks(li: v7, a2: *(float *)&v22, a3: v23);
  }
  v8 = (GASObjectInterface *)result;
  if ( (_BYTE)isdobj != 0
    && ((GFxCharacterHandle::ResolveCharacter(this: result, a2: *this), v9 == 0)
     || (v8 = (GASObjectInterface *)(v9 + 120), v9 == -120)) )
  {
    if ( val != StringPoolCaseInsensitive )
    {
      if ( (*(_DWORD *)(val + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: *(CStringPool **)val,
          a2: (int)this,
          val,
          pobj: *(IShaderAPI **)(val + 8));
        *(_DWORD *)val = 0;
      }
      *(_DWORD *)(val + 4) = 0;
    }
    if ( v6 != nullptr )
    {
      GTimer::GetRawTicks(li: v10, a2: *(float *)&v22, a3: v23);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
  else
  {
    v12 = *this;
    LOBYTE(asval) = 0;
    v13 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v12 + 12) + 112))(a1: *((_DWORD *)v12 + 12));
    GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v13 + 120) + 636));
    isdobj = v14;
    ++*(_DWORD *)(v14 + 8);
    v15 = (*(unsigned __int8 (__thiscall **)(GASObjectInterface *, int, int *, CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> **))(*(_DWORD *)v8 + 16))(
            a1: v8,
            a2: v13,
            a3: &isdobj,
            a4: &asval) == 0;
    if ( (*(_DWORD *)(isdobj + 8))-- == 1 )
      GASStringNode::ReleaseNode();
    if ( v15 )
    {
      if ( val != StringPoolCaseInsensitive )
      {
        if ( (*(_DWORD *)(val + 4) & 0x40) != 0 )
        {
          GFxValue::ObjectInterface::ObjectRelease(
            this: *(CStringPool **)val,
            a2: v13,
            val,
            pobj: *(IShaderAPI **)(val + 8));
          *(_DWORD *)val = 0;
        }
        *(_DWORD *)(val + 4) = 0;
      }
      GASValue::~GASValue(this: &asval);
      if ( v24 != nullptr )
      {
        GTimer::GetRawTicks(li: v17, a2: *(float *)&v22, a3: v23);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 0;
    }
    else
    {
      if ( (_BYTE)asval == 9 )
      {
        v18 = nullptr;
        if ( (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v8 + 8))(a1: v8) - 6) <= 0x26 )
        {
          v19 = GASObjectInterface::ToASObject(result: v22);
          if ( v19 != nullptr )
            v18 = (struct GASObjectInterface *)&v19->Policy[1];
          else
            v18 = nullptr;
        }
        if ( (unsigned int)((*(int (__thiscall **)(GASObjectInterface *))(*(_DWORD *)v8 + 8))(a1: v8) - 2) <= 3 )
        {
          v20 = GASObjectInterface::ToASCharacter(this: v8);
          if ( v20 != nullptr )
            v18 = (struct GFxASCharacter *)((char *)v20 + 120);
        }
        GASValue::GetPropertyValue(
          this: &asval,
          a2: (struct GASEnvironment *)v13,
          a3: v18,
          a4: (struct GASValue *)&asval);
      }
      GFxMovieRoot::ASValue2GFxValue(
        this: *v26,
        result: (tagPOLYTEXTW *)v13,
        value: (tagWNDCLASSW *)&asval,
        toType: val);
      GASValue::~GASValue(this: &asval);
      if ( v24 != nullptr )
      {
        GTimer::GetRawTicks(li: v21, a2: *(float *)&v22, a3: v23);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100699F0
// Name: public: bool GFxValue::ObjectInterface::GetElement(void __near *,unsigned int,class GFxValue __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::GetElement(
        GFxValue::ObjectInterface *this,
        char *a2,
        unsigned int a3,
        struct GFxValue *val)
{
  GFxAmpViewStats *v4; // esi
  char *v5; // ebx
  float v6; // ecx
  float v7; // ecx
  tagWNDCLASSW *v9; // ebx
  tagPOLYTEXTW *v10; // eax
  float v11; // ecx
  float v12; // [esp+0h] [ebp-28h]
  float *v13; // [esp+4h] [ebp-24h]

  v4 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, a3: 0x2Cu);
    GTimer::GetRawTicks(li: v6, a2: v12, a3: v13);
  }
  if ( a2 != nullptr )
    v5 = a2 - 16;
  LODWORD(v7) = (unsigned int)val->Type >> 6;
  if ( (val->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)val->pObjectInterface,
      a2: (int)val,
      (StringPoolCase_t)val,
      pobj: (IShaderAPI *)val->Value.pString);
    val->pObjectInterface = nullptr;
  }
  val->Type = VT_Undefined;
  if ( a3 < *((_DWORD *)v5 + 15)
    && (v7 = *((float *)v5 + 14), (v9 = *(tagWNDCLASSW **)(LODWORD(v7) + 4 * a3)) != nullptr) )
  {
    v10 = (tagPOLYTEXTW *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->pMovieRoot + 12) + 112))(a1: *((_DWORD *)this->pMovieRoot + 12));
    GFxMovieRoot::ASValue2GFxValue(
      this: (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)this->pMovieRoot,
      result: v10,
      value: v9,
      toType: (int)val);
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v11, a2: v12, a3: v13);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      GTimer::GetRawTicks(li: v7, a2: v12, a3: v13);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069AE0
// Name: public: void GFxValue::ObjectInterface::VisitElements(void __near *,class GFxValue::ObjectInterface::ArrVisitor __near *,unsigned int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ObjectInterface::VisitElements(
        GFxValue::ObjectInterface *this,
        char *parr,
        struct GFxValue::ObjectInterface::ArrVisitor *idx,
        unsigned int a4,
        int count)
{
  GFxAmpViewStats *v6; // edi
  float v7; // ecx
  tagPOLYTEXTW *v8; // eax
  float v9; // ecx
  unsigned int v10; // esi
  unsigned int v11; // eax
  bool v12; // zf
  int v13; // ecx
  unsigned int v14; // ebx
  tagWNDCLASSW *v15; // eax
  float v16; // [esp+0h] [ebp-3Ch]
  float *v17; // [esp+4h] [ebp-38h]
  StringPoolCase_t val; // [esp+24h] [ebp-18h] BYREF
  int v19; // [esp+28h] [ebp-14h]
  IShaderAPI *v20; // [esp+2Ch] [ebp-10h]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> **v21; // [esp+34h] [ebp-8h]
  tagPOLYTEXTW *v22; // [esp+38h] [ebp-4h]
  char *parra; // [esp+44h] [ebp+8h]

  v6 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  v21 = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> **)this;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, a3: 0x2Eu);
    GTimer::GetRawTicks(li: v7, a2: v16, a3: v17);
  }
  if ( parr != nullptr )
    parra = parr - 16;
  else
    parra = nullptr;
  v8 = (tagPOLYTEXTW *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->pMovieRoot + 12) + 112))(a1: *((_DWORD *)this->pMovieRoot + 12));
  v9 = *(float *)&parra;
  v10 = a4;
  v22 = v8;
  v11 = *((_DWORD *)parra + 15);
  val = StringPoolCaseInsensitive;
  v19 = 0;
  if ( a4 < v11 )
  {
    v13 = count;
    if ( count < 0 )
      v13 = v11 - a4;
    LODWORD(v9) = a4 + v13;
    v14 = v11;
    if ( v11 >= LODWORD(v9) )
      v14 = LODWORD(v9);
    if ( a4 < v14 )
    {
      do
      {
        v15 = *(tagWNDCLASSW **)(*((_DWORD *)parra + 14) + 4 * v10);
        if ( v15 != nullptr )
        {
          GFxMovieRoot::ASValue2GFxValue(this: *v21, result: v22, value: v15, toType: (int)&val);
        }
        else
        {
          if ( (v19 & 0x40) != 0 )
          {
            GFxValue::ObjectInterface::ObjectRelease(
              this: (CStringPool *)val,
              a2: (int)idx,
              (StringPoolCase_t)&val,
              pobj: v20);
            val = StringPoolCaseInsensitive;
          }
          v19 = 0;
        }
        idx->Visit(this: idx, a2: v10++, a3: (const GFxValue *)&val);
      }
      while ( v10 < v14 );
    }
    if ( (v19 & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)val, a2: (int)v6, (StringPoolCase_t)&val, pobj: v20);
      val = StringPoolCaseInsensitive;
    }
    v12 = v6 == nullptr;
  }
  else
  {
    v12 = v6 == nullptr;
  }
  if ( !v12 )
  {
    GTimer::GetRawTicks(li: v9, a2: v16, a3: v17);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C20
// Name: public: bool GFxValue::ObjectInterface::GetText(void __near *,class GFxValue __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxValue::ObjectInterface::GetText(
        GFxValue::ObjectInterface *this,
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pdata,
        struct GFxValue *a3,
        int reqHtml)
{
  GFxAmpViewStats *v5; // edi
  float v6; // ecx
  int v7; // eax
  float v8; // ecx
  int v9; // ebx
  int *p_m_nGrowSize; // eax
  float v12; // ecx
  char Member; // bl
  int v14; // eax
  void (__thiscall *v15)(int, CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **, int, int); // edx
  tagPOLYTEXTW *v16; // edx
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v17; // eax
  bool v18; // zf
  float v19; // ecx
  float v20; // [esp+0h] [ebp-38h]
  float *v21; // [esp+4h] [ebp-34h]
  GASValue v22[4]; // [esp+24h] [ebp-14h] BYREF
  tagPOLYTEXTW *v23; // [esp+34h] [ebp-4h]

  v5 = *((GFxAmpViewStats **)this->pMovieRoot + 2577);
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 0x3Au);
    GTimer::GetRawTicks(li: v6, a2: v20, a3: v21);
  }
  GFxCharacterHandle::ResolveCharacter(this: pdata, a2: (GFxMovieRoot *)this->pMovieRoot);
  v9 = v7;
  if ( v7 != 0 )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 176))(a1: v7) == 4 )
    {
      v14 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this->pMovieRoot + 12) + 112))(a1: *((_DWORD *)this->pMovieRoot
                                                                                             + 12));
      v15 = *(void (__thiscall **)(int, CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **, int, int))(*(_DWORD *)v9 + 364);
      v23 = (tagPOLYTEXTW *)v14;
      v15(a1: v9, a2: &pdata, a3: v14, a4: reqHtml);
      v16 = v23;
      v22[1] = (GASValue)pdata;
      LOBYTE(v22[0]) = 5;
      ++pdata->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
      GFxMovieRoot::ASValue2GFxValue(
        this: (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)this->pMovieRoot,
        result: v16,
        value: (tagWNDCLASSW *)v22,
        toType: (int)a3);
      GASValue::~GASValue(this: v22);
      v17 = pdata;
      v18 = pdata->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable-- == (CRefCountServiceDestruct<CRefST>_vtbl *)1;
      v19 = *(float *)&v17;
      if ( v18 )
        GASStringNode::ReleaseNode();
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v19, a2: v20, a3: v21);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return 1;
    }
    else
    {
      p_m_nGrowSize = &stru_10299FCC.m_Memory.m_nGrowSize;
      if ( (_BYTE)reqHtml == 0 )
        p_m_nGrowSize = (int *)&stru_10299FCC;
      Member = GFxValue::ObjectInterface::GetMember(
                 (GFxMovieRoot **)this,
                 result: pdata,
                 a3: (int)p_m_nGrowSize,
                 val: (StringPoolCase_t)a3,
                 isdobj: 1);
      if ( v5 != nullptr )
      {
        GTimer::GetRawTicks(li: v12, a2: v20, a3: v21);
        GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
      }
      return Member;
    }
  }
  else
  {
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v8, a2: v20, a3: v21);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069D70
// Name: public: static void GConstructorCPP<class GFxValue>::DestructArray(class GFxValue __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorCPP<GFxValue>::DestructArray(int a1, int a2)
{
  StringPoolCase_t v2; // esi
  int i; // edi

  v2 = a1 + 16 * a2 - 16;
  if ( a2 != 0 )
  {
    for ( i = a2; i != 0; --i )
    {
      if ( (*(_DWORD *)(v2 + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: *(CStringPool **)v2,
          a2: i,
          val: v2,
          pobj: *(IShaderAPI **)(v2 + 8));
        *(_DWORD *)v2 = 0;
      }
      v2 -= 16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069F90
// Name: private: void GASUserDefinedFunctionObject::InvokeImpl(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASUserDefinedFunctionObject::InvokeImpl(GASUserDefinedFunctionObject *this, GASFnCall *a2)
{
  int v2; // ebx
  struct GASObjectInterface *v3; // eax
  GASEnvironment *v4; // edi
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *MovieRoot; // eax
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *v6; // eax
  struct GFxMovieRoot *v7; // eax
  bool v8; // cc
  int v9; // ebx
  int v10; // ecx
  GFxMovieRoot *v11; // eax
  char *i; // edi
  int v13; // eax
  int v14; // esi
  PROCESSOR_IDLESTATE_POLICY *v16; // eax
  _IMAGE_SYMBOL_EX v17; // [esp-8h] [ebp-80h]
  tagWNDCLASSW *v18; // [esp-8h] [ebp-80h]
  _DWORD v19[4]; // [esp+Ch] [ebp-6Ch] BYREF
  char *v20; // [esp+1Ch] [ebp-5Ch]
  int v21; // [esp+20h] [ebp-58h]
  int v22; // [esp+24h] [ebp-54h]
  tagWNDCLASSW v23; // [esp+28h] [ebp-50h] BYREF
  IShaderAPI *v24; // [esp+50h] [ebp-28h]
  StringPoolCase_t v25; // [esp+58h] [ebp-20h] BYREF
  int v26; // [esp+5Ch] [ebp-1Ch]
  IShaderAPI *v27; // [esp+60h] [ebp-18h]
  char *v28; // [esp+68h] [ebp-10h] BYREF
  int v29; // [esp+6Ch] [ebp-Ch]
  int v30; // [esp+70h] [ebp-8h]
  GASUserDefinedFunctionObject *v31; // [esp+74h] [ebp-4h]

  v2 = 0;
  v3 = (struct GASObjectInterface *)a2[2];
  v4 = (GASEnvironment *)a2[6];
  v31 = this;
  v28 = nullptr;
  v29 = 0;
  v30 = 0;
  v23.lpszMenuName = nullptr;
  v23.lpszClassName = nullptr;
  v25 = StringPoolCaseInsensitive;
  v26 = 0;
  LOBYTE(v23.style) = 0;
  if ( v3 != nullptr )
  {
    GASValue::SetAsObjectInterface(this: (GASValue *)&v23, a2: v3);
  }
  else
  {
    GASValue::DropRefs(this: (GASValue *)&v23);
    LOBYTE(v23.style) = 1;
  }
  MovieRoot = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)GASEnvironment::GetMovieRoot(this: v4);
  GFxMovieRoot::ASValue2GFxValue(
    this: MovieRoot,
    result: (tagPOLYTEXTW *)v4,
    value: &v23,
    toType: (int)&v23.lpszMenuName);
  GArrayData<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::PushBack(
    this: (unsigned int *)&v28,
    src: (GFxValue *)&v23.lpszMenuName);
  if ( (int)a2[7] > 0 )
  {
    do
    {
      v23.hInstance = nullptr;
      v23.hIcon = nullptr;
      v18 = (tagWNDCLASSW *)GASFnCall::Arg(this: a2, a2: v2);
      v6 = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> *)GASEnvironment::GetMovieRoot(this: v4);
      GFxMovieRoot::ASValue2GFxValue(this: v6, result: (tagPOLYTEXTW *)v4, value: v18, toType: (int)&v23.hInstance);
      GArrayData<GFxValue,GAllocatorGH_CPP<GFxValue,2>,GArrayDefaultPolicy>::PushBack(
        this: (unsigned int *)&v28,
        src: (GFxValue *)&v23.hInstance);
      if ( ((int)v23.hIcon & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: (CStringPool *)v23.hInstance,
          a2: (int)v4,
          val: (StringPoolCase_t)&v23.hInstance,
          pobj: (IShaderAPI *)v23.hCursor);
        v23.hInstance = nullptr;
      }
      ++v2;
    }
    while ( v2 < (int)a2[7] );
  }
  v7 = GASEnvironment::GetMovieRoot(this: v4);
  v8 = (int)a2[7] <= 0;
  v19[1] = v7;
  v19[0] = &v25;
  v19[2] = &v23.lpszMenuName;
  if ( v8 )
    v20 = nullptr;
  else
    v20 = v28 + 16;
  v9 = v29;
  v21 = v29 - 1;
  v22 = *((_DWORD *)v31 + 14);
  v10 = *((_DWORD *)v31 + 13);
  v19[3] = v28;
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v10 + 4))(a1: v10, a2: v19);
  if ( (v26 & 0x8F) != 0 )
  {
    v17.N.Name.Long = (unsigned int)a2[1];
    v17.N.Name.Short = (unsigned int)&v25;
    v11 = (GFxMovieRoot *)GASEnvironment::GetMovieRoot(this: v4);
    GFxMovieRoot::GFxValue2ASValue(this: v11, a2: v17);
  }
  GASValue::~GASValue(this: (GASValue *)&v23);
  if ( (v26 & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)v25,
      a2: (int)v4,
      val: (StringPoolCase_t)&v25,
      pobj: v27);
    v25 = StringPoolCaseInsensitive;
  }
  if ( ((int)v23.lpszClassName & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)v23.lpszMenuName,
      a2: (int)v4,
      val: (StringPoolCase_t)&v23.lpszMenuName,
      pobj: v24);
    v23.lpszMenuName = nullptr;
  }
  for ( i = &v28[16 * v9 - 16]; v9 != 0; --v9 )
  {
    v13 = *((_DWORD *)i + 1);
    if ( (v13 & 0x40) != 0 )
    {
      v14 = *((_DWORD *)i + 2);
      switch ( v13 & 0x8F )
      {
        case 4:
          if ( (*(_DWORD *)(v14 + 8))-- == 1 )
            GASStringNode::ReleaseNode();
          break;
        case 5:
          GRefCountImpl::Release(this: (IShaderAPI *)(v14 - 12));
          break;
        case 6:
        case 7:
          v16 = GASObjectInterface::ToASObject(result: (PROCESSOR_IDLESTATE_POLICY *)v17.Value);
          GRefCountBaseGC<323>::Release(a1: (int)v16, a2: (int)i);
          break;
        case 8:
          if ( (int)--*(_DWORD *)v14 <= 0 )
          {
            GFxCharacterHandle::~GFxCharacterHandle(this: (GFxCharacterHandle *)v14);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v14);
          }
          break;
        default:
          break;
      }
      *(_DWORD *)i = 0;
    }
    i -= 16;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v28);
}

//------------------------------------------------------------------------------
// Address: 0x1006A1D0
// Name: public: virtual void GASUserDefinedFunctionObject::Invoke(class GASFnCall const __near &,class GASLocalFrame __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GASUserDefinedFunctionObject::Invoke(
        GASUserDefinedFunctionObject *this,
        const struct GASFnCall *a2,
        struct GASLocalFrame *a3,
        const char *a4)
{
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  tagALTTABINFO *v9; // esi
  GASFnCall v10[5]; // [esp+4h] [ebp-24h] BYREF
  char v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+20h] [ebp-8h]
  int v14; // [esp+24h] [ebp-4h]

  if ( *((_DWORD *)this + 13) != 0 )
  {
    v5 = *((_DWORD **)a2 + 2);
    if ( v5 != nullptr && (*(unsigned __int8 (__thiscall **)(_DWORD))(*v5 + 60))(a1: *((_DWORD *)a2 + 2)) != 0 )
    {
      v6 = *((_DWORD *)a2 + 8);
      v7 = *((_DWORD *)a2 + 7);
      v8 = *((_DWORD *)a2 + 6);
      v10[1] = *((GASFnCall *)a2 + 1);
      v9 = (tagALTTABINFO *)v5[11];
      v14 = v6;
      v10[2] = v9;
      v13 = v7;
      v10[0] = (GASFnCall)&GASFnCall::`vftable';
      v11 = 0;
      v10[3] = nullptr;
      v10[4] = nullptr;
      v12 = v8;
      GASUserDefinedFunctionObject::InvokeImpl(this, a2: v10);
      GASSuperObject::ResetAltProto(this: (GASSuperObject *)(v5 - 4), a2: (int)v5);
      GASFnCall::~GASFnCall(this: v10);
    }
    else
    {
      GASUserDefinedFunctionObject::InvokeImpl(this, (GASFnCall *)a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB810
// Name: public: virtual class GASEnvironment __near * GASUserDefinedFunctionObject::GetEnvironment(class GASFnCall const __near &,class GPtr<class GFxASCharacter> __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GASUserDefinedFunctionObject::GetEnvironment(int __formal, int __formal_4)
{
  return *(_DWORD *)(__formal + 24);
}

//------------------------------------------------------------------------------
// Address: 0x100AD7C0
// Name: public: virtual int GASUserDefinedFunctionObject::GetNumArgs(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GASUserDefinedFunctionObject::GetNumArgs(HDC__ *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C58E9
// Name: public: class D3DXShader::CRegisterEntryNode __near * D3DXShader::CFragmentRegisterAllocator::GetElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CRegisterEntryNode *__thiscall D3DXShader::CFragmentRegisterAllocator::GetElement(
        D3DXShader::CFragmentRegisterAllocator *this,
        D3DXShader *lpString2)
{
  int i; // esi
  const char *v4; // [esp+0h] [ebp-4h]

  for ( i = *((_DWORD *)this + D3DXShader::RegisterHash(this: lpString2, a2: v4)); ; i = *(_DWORD *)(i + 32) )
  {
    if ( i == 0 )
      return nullptr;
    if ( lstrcmpiA(lpString1: *(LPCSTR *)i, (LPCSTR)lpString2) == 0 )
      break;
  }
  return (struct D3DXShader::CRegisterEntryNode *)i;
}

//------------------------------------------------------------------------------
// Address: 0x101DDA46
// Name: public: virtual long D3DXShader::CConstantTable::SetBool(struct IDirect3DDevice9 __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetBool(
        D3DXShader::CConstantTable *this,
        struct IDirect3DDevice9 *a2,
        int a3,
        float a4)
{
  int v4; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v4 = -a3;
    goto LABEL_6;
  }
  result = D3DXShader::CConstantTable::FindConstantByName(
             this,
             a2: (const char *)a3,
             (struct D3DXShader::CConstant **)&a3);
  if ( result >= 0 )
  {
    v4 = a3;
LABEL_6:
    while ( 1 )
    {
      result = D3DXShader::SetTyped<0,1,1,1,0>::Set(a1: v4, (int)a2, a3: &a4, a4: 1u, a5: 0);
      if ( result < 0 )
        break;
      v4 = *(_DWORD *)(v4 + 36);
      if ( v4 == 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028CA90
// Name: _GASObject::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__
// Source: json
//------------------------------------------------------------------------------
void GASObject::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__()
{
  GASValue::~GASValue(this: &notsetVal_0);
}

//------------------------------------------------------------------------------
// Address: 0x101C591F
// Name: public: void D3DXShader::CFragmentRegisterAllocator::GetElements(class D3DXShader::CRegisterEntryNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CFragmentRegisterAllocator::GetElements(
        D3DXShader::CFragmentRegisterAllocator *this,
        struct D3DXShader::CRegisterEntryNode **a2)
{
  int v2; // edx
  unsigned int i; // esi
  struct D3DXShader::CRegisterEntryNode *v4; // eax

  v2 = 0;
  for ( i = 0; i < 7; ++i )
  {
    v4 = *((struct D3DXShader::CRegisterEntryNode **)this + i);
    while ( v4 != nullptr )
    {
      a2[v2] = v4;
      v4 = *((struct D3DXShader::CRegisterEntryNode **)v4 + 8);
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5949
// Name: public: D3DXShader::CAssembler::CAssembler(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CAssembler *__thiscall D3DXShader::CAssembler::CAssembler(D3DXShader::CAssembler *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 30) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C5965
// Name: protected: void D3DXShader::CAssembler::Error(char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CAssembler::Error(D3DXShader::CAssembler *this, char *format, ...)
{
  D3DXShader::CTErrors *v2; // [esp-24h] [ebp-1034h]
  char string[4096]; // [esp+Ch] [ebp-1004h] BYREF
  va_list ap; // [esp+1020h] [ebp+10h] BYREF

  va_start(ap, format);
  *((_DWORD *)this + 19) = 1;
  if ( strcmp(format, "syntax error") == 0 )
  {
    D3DXShader::CTErrors::SyntaxError(
      this: *(D3DXShader::CTErrors **)this,
      a2: 0x7D0u,
      a3: (D3DXShader::CAssembler *)((char *)this + 16));
    if ( *((_DWORD *)this + 4) == 9 )
    {
      if ( *((_DWORD *)this + 21) == 2023 )
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)this,
          a2: (D3DXShader::CAssembler *)((char *)this + 16),
          a3: 0x7E7u,
          format: "'%s' is not a valid instruction in this shader version",
          *((const char **)this + 6));
      if ( *((_DWORD *)this + 21) == 2024 )
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)this,
          a2: (D3DXShader::CAssembler *)((char *)this + 16),
          a3: 0x7E8u,
          format: "invalid instruction modifiers '%s'",
          *((const char **)this + 6));
    }
  }
  else
  {
    _vsnprintf(string, count: 0x1000u, format, ap);
    v2 = *(D3DXShader::CTErrors **)this;
    string[255] = 0;
    D3DXShader::CTErrors::Error(
      this: v2,
      a2: (D3DXShader::CAssembler *)((char *)this + 16),
      a3: 0,
      format: "%s",
      string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5A35
// Name: protected: static long D3DXShader::CAssembler::ValidationError(char const __near *,unsigned int,unsigned long,unsigned int,char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CAssembler::ValidationError(
        const char *a1,
        unsigned int a2,
        __int16 a3,
        unsigned int a4,
        const char *a5,
        D3DXShader::CTErrors **a6)
{
  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
LABEL_5:
      D3DXShader::CTErrors::Error(this: *a6, a2: a6[12], a3: a4 + 5000, format: "%s", a5);
      a6[19] = (D3DXShader::CTErrors *)1;
      return 0;
    }
    if ( a3 != 5 )
    {
      if ( a3 == 6 )
        goto LABEL_5;
      return 0;
    }
  }
  D3DXShader::CTErrors::Warning(this: *a6, a2: a6[12], a3: a4 + 5000, format: "%s", a5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C5AA3
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CAssembler::NonNull(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CAssembler::NonNull(
        D3DXShader::CTErrors **this,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax

  result = a2;
  if ( a2 == nullptr )
  {
    if ( *(this + 19) == nullptr )
    {
      D3DXShader::CTErrors::Error(
        this: *this,
        a2: (struct D3DXShader::D3DXTOKEN *)(this + 4),
        a3: 0,
        format: "internal error: production failed");
      *(this + 19) = (D3DXShader::CTErrors *)1;
    }
    *(this + 20) = (D3DXShader::CTErrors *)1;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C5ADD
// Name: protected: int D3DXShader::CAssembler::DecodeOpcode(struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::DecodeOpcode(D3DXShader::CAssembler *this, struct D3DXShader::D3DXTOKEN *a2)
{
  _BYTE *v2; // eax
  int v4; // ecx
  _BYTE *i; // ecx
  unsigned int v6; // eax
  int v7; // edx
  unsigned int j; // edi
  int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // edx
  int v16; // eax
  char *v17; // esi
  unsigned int v18; // ebx
  char v19; // al
  char v20; // al
  char *v21; // esi
  unsigned int v22; // ebx
  char v23; // al
  char v24; // al
  char v26; // [esp-4h] [ebp-6Ch]
  char v27; // [esp-4h] [ebp-6Ch]
  char *v28; // [esp+Ch] [ebp-5Ch]
  int v29; // [esp+10h] [ebp-58h]
  int v30; // [esp+14h] [ebp-54h]
  _BYTE *v31; // [esp+18h] [ebp-50h]
  int v32; // [esp+1Ch] [ebp-4Ch]
  int v33; // [esp+20h] [ebp-48h]
  int v34; // [esp+24h] [ebp-44h]
  int v35; // [esp+28h] [ebp-40h]
  int v36; // [esp+2Ch] [ebp-3Ch]
  int v37; // [esp+30h] [ebp-38h]
  int v38; // [esp+34h] [ebp-34h]
  int v39; // [esp+38h] [ebp-30h]
  char v40; // [esp+3Fh] [ebp-29h]
  _BYTE *v41; // [esp+40h] [ebp-28h]
  D3DXShader::CAssembler *v42; // [esp+44h] [ebp-24h]
  int v43; // [esp+48h] [ebp-20h]
  int v44; // [esp+4Ch] [ebp-1Ch]
  int v45; // [esp+50h] [ebp-18h]
  char nptr[16]; // [esp+54h] [ebp-14h] BYREF

  v2 = *((_BYTE **)a2 + 2);
  v4 = 0;
  *((_DWORD *)this + 21) = 0;
  v42 = this;
  v45 = 269;
  v29 = 0;
  v44 = 0;
  v43 = 0;
  v30 = 1;
  v36 = 0;
  v32 = 0;
  v34 = 0;
  v38 = 0;
  v35 = 0;
  v37 = 0;
  v39 = 0;
  v33 = 0;
  v31 = v2;
  v41 = v2;
  if ( *v2 != 0 )
  {
    while ( 1 )
    {
      for ( i = v41; *i != 0 && *i != 95; v41 = i )
        ++i;
      v6 = i - v31;
      if ( (unsigned int)(i - v31) > 0xF )
        return 269;
      qmemcpy(nptr, v31, v6);
      nptr[v6] = 0;
      if ( *v41 != 0 )
        ++v41;
      v31 = v41;
      if ( v30 != 0 )
      {
        v7 = 0;
        for ( j = 0; j < 1428; j += 17 )
        {
          if ( strcmp(nptr, (&off_102B2100)[j]) == 0 )
            break;
          ++v7;
        }
        if ( v7 == 84 )
          return 269;
        this = v42;
        v9 = *((_DWORD *)v42 + 14);
        v10 = dword_102B2108[16 * v7 + v7 + v9];
        if ( v10 > 0xFFFFFFFA )
        {
          switch ( v10 )
          {
            case 0xFFFFFFFB:
              v45 = 267;
              break;
            case 0xFFFFFFFC:
              v45 = 266;
              break;
            case 0xFFFFFFFD:
              v45 = 264;
              break;
            case 0xFFFFFFFE:
              v45 = 265;
              break;
            default:
              *((_DWORD *)v42 + 21) = 2023;
              return 269;
          }
        }
        else if ( v10 == -6 )
        {
          v45 = 268;
        }
        else if ( v10 != 0 )
        {
          v11 = v10 - 1;
          if ( v11 != 0 )
          {
            v12 = v11 - 1;
            if ( v12 != 0 )
            {
              v13 = v12 - 1;
              if ( v13 != 0 )
              {
                v14 = v13 - 1;
                if ( v14 != 0 )
                {
                  if ( v14 == 1 )
                    v45 = 263;
                }
                else
                {
                  v45 = 262;
                }
              }
              else
              {
                v45 = 261;
              }
            }
            else
            {
              v45 = 260;
            }
          }
          else
          {
            v45 = 259;
          }
        }
        else
        {
          v45 = 258;
        }
        v15 = dword_102B2104[17 * v7];
        v29 = v15;
        v30 = 0;
        if ( v9 >= 6 && v9 <= 9 && v45 >= 259 && v45 <= 263 )
          v36 = 1;
        if ( (v9 >= 4 && v9 <= 5 || v9 >= 6 && v9 <= 14) && v45 >= 259 && v45 <= 263 && v15 != 31 )
          v32 = 1;
        if ( v9 >= 10 )
        {
          if ( v9 <= 14 && v15 == 31 )
            v34 = 1;
          if ( v9 <= 14 && v45 >= 259 && v45 <= 263 )
            v33 = 1;
        }
        if ( (v9 >= 4 && v9 <= 5 || v9 >= 10 && v9 <= 14) && v15 == 31 )
          v38 = 1;
        if ( v9 >= 13 && v9 <= 14 && v15 == 31 )
          v35 = 1;
        if ( (unsigned int)v9 <= 5 && v15 == 31 )
          v37 = 1;
        if ( v15 == 40 || v15 == 44 || v15 == 94 )
          v39 = 1;
        *((_DWORD *)v42 + 21) = 2024;
        goto LABEL_209;
      }
      if ( v32 != 0 && strcmp(nptr, "sat") == 0 )
      {
        BYTE2(v44) |= 0x10u;
        v36 = 0;
        v32 = 0;
      }
      else if ( v34 != 0 && strcmp(nptr, "centroid") == 0 )
      {
        BYTE2(v44) |= 0x40u;
        v34 = 0;
      }
      else
      {
        if ( v36 != 0 )
        {
          if ( strcmp(nptr, "x8") == 0 )
          {
            v44 = 50331648;
          }
          else if ( strcmp(nptr, "x4") == 0 )
          {
            v44 = 0x2000000;
          }
          else if ( strcmp(nptr, "x2") == 0 )
          {
            v44 = 0x1000000;
          }
          else if ( strcmp(nptr, "d2") == 0 )
          {
            v44 = 251658240;
          }
          else if ( strcmp(nptr, "d4") == 0 )
          {
            v44 = 234881024;
          }
          else
          {
            if ( strcmp(nptr, "d8") != 0 )
              return 269;
            v44 = 218103808;
          }
          v36 = 0;
          goto LABEL_208;
        }
        if ( v38 == 0 )
          goto LABEL_107;
        v16 = 0;
        if ( strcmp(nptr, "2d") == 0 )
        {
          v16 = 0x10000000;
        }
        else if ( strcmp(nptr, "cube") == 0 )
        {
          v16 = 402653184;
        }
        else if ( strcmp(nptr, "volume") == 0 )
        {
          v16 = 0x20000000;
        }
        v43 |= v16;
        v38 = 0;
        if ( v16 != 0 )
        {
          v35 = 0;
          v37 = 0;
        }
        else
        {
LABEL_107:
          if ( v33 == 0 || strcmp(nptr, "pp") != 0 )
          {
            if ( v35 == 0 )
              goto LABEL_152;
            v17 = nptr;
            if ( nptr[0] != 0 )
            {
              do
              {
                if ( isalpha(c: *v17) == 0 )
                  break;
                ++v17;
              }
              while ( *v17 != 0 );
              v18 = *v17 != 0 ? atoi(nptr: v17) : 0;
            }
            else
            {
              v18 = 0;
            }
            if ( v18 > 0xF )
              goto LABEL_152;
            v40 = *v17;
            v28 = v17;
            if ( *v17 != 0 )
              *v17++ = 0;
            v19 = *v17;
            if ( *v17 != 0 )
            {
              do
              {
                if ( isdigit(c: v19) == 0 )
                  break;
                v19 = *++v17;
              }
              while ( *v17 != 0 );
              if ( *v17 != 0 )
                goto LABEL_151;
            }
            v20 = 0;
            if ( strcmp(nptr, "position") == 0 )
            {
              if ( v18 != 0 )
                goto LABEL_125;
LABEL_151:
              *v28 = v40;
LABEL_152:
              if ( v37 == 0 )
              {
                if ( v39 == 0 )
                  return 269;
                if ( strcmp(nptr, "gt") == 0 )
                {
                  v43 = 1;
                }
                else if ( strcmp(nptr, "eq") == 0 )
                {
                  v43 = 2;
                }
                else if ( strcmp(nptr, "ge") == 0 )
                {
                  v43 = 3;
                }
                else if ( strcmp(nptr, "lt") == 0 )
                {
                  v43 = 4;
                }
                else if ( strcmp(nptr, "ne") == 0 )
                {
                  v43 = 5;
                }
                else
                {
                  if ( strcmp(nptr, "le") != 0 )
                    return 269;
                  v43 = 6;
                }
                v39 = 0;
                goto LABEL_208;
              }
              v21 = nptr;
              if ( nptr[0] != 0 )
              {
                do
                {
                  if ( isalpha(c: *v21) == 0 )
                    break;
                  ++v21;
                }
                while ( *v21 != 0 );
                if ( *v21 != 0 )
                  v22 = atoi(nptr: v21);
                else
                  v22 = 0;
              }
              else
              {
                v22 = 0;
              }
              if ( v22 > 0xF )
                return 269;
              if ( *v21 != 0 )
                *v21++ = 0;
              v23 = *v21;
              if ( *v21 != 0 )
              {
                do
                {
                  if ( isdigit(c: v23) == 0 )
                    break;
                  v23 = *++v21;
                }
                while ( *v21 != 0 );
                if ( *v21 != 0 )
                  return 269;
              }
              v24 = 0;
              if ( strcmp(nptr, "position") != 0 )
              {
                if ( strcmp(nptr, "blendweight") == 0 )
                {
                  v24 = 1;
                  goto LABEL_192;
                }
                if ( strcmp(nptr, "blendindices") == 0 )
                {
                  v27 = 2;
                  goto LABEL_191;
                }
                if ( strcmp(nptr, (const char *)&stru_1029DFB4) == 0 )
                {
                  v27 = 3;
                  goto LABEL_191;
                }
                if ( strcmp(nptr, "psize") == 0 )
                {
                  v27 = 4;
                  goto LABEL_191;
                }
                if ( strcmp(nptr, "texcoord") == 0 )
                {
                  v27 = 5;
                  goto LABEL_191;
                }
                v24 = 8;
                if ( strcmp(nptr, "tangent") == 0 )
                {
                  v27 = 6;
                  goto LABEL_191;
                }
                if ( strcmp(nptr, "binormal") == 0 )
                {
                  v27 = 7;
                  goto LABEL_191;
                }
                if ( strcmp(nptr, "tessfactor") != 0 )
                {
                  v24 = 10;
                  if ( strcmp(nptr, "positiont") == 0 )
                  {
                    v27 = 9;
                    goto LABEL_191;
                  }
                  if ( strcmp(nptr, "color") != 0 )
                  {
                    if ( strcmp(nptr, "fog") == 0 )
                    {
                      v27 = 11;
                    }
                    else if ( strcmp(nptr, "depth") == 0 )
                    {
                      v27 = 12;
                    }
                    else
                    {
                      if ( strcmp(nptr, "sample") != 0 )
                        return 269;
                      v27 = 13;
                    }
LABEL_191:
                    v24 = v27;
                  }
                }
              }
LABEL_192:
              v37 = 0;
              v43 = v24 & 0xF | ((v22 & 0xF) << 16);
LABEL_193:
              v38 = 0;
              goto LABEL_208;
            }
            if ( strcmp(nptr, "blendweight") == 0 )
            {
              v20 = 1;
LABEL_125:
              v43 |= v20 & 0xF | ((v18 & 0xF) << 16);
              v35 = 0;
              goto LABEL_193;
            }
            if ( strcmp(nptr, "blendindices") == 0 )
            {
              v26 = 2;
            }
            else if ( strcmp(nptr, (const char *)&stru_1029DFB4) == 0 )
            {
              v26 = 3;
            }
            else
            {
              v20 = 6;
              if ( strcmp(nptr, "psize") == 0 )
              {
                v26 = 4;
              }
              else if ( strcmp(nptr, "texcoord") == 0 )
              {
                v26 = 5;
              }
              else
              {
                if ( strcmp(nptr, "tangent") == 0 )
                  goto LABEL_125;
                if ( strcmp(nptr, "binormal") == 0 )
                {
                  v26 = 7;
                }
                else if ( strcmp(nptr, "tessfactor") == 0 )
                {
                  v26 = 8;
                }
                else
                {
                  v20 = 10;
                  if ( strcmp(nptr, "positiont") == 0 )
                  {
                    v26 = 9;
                  }
                  else
                  {
                    if ( strcmp(nptr, "color") == 0 )
                      goto LABEL_125;
                    if ( strcmp(nptr, "fog") == 0 )
                    {
                      v26 = 11;
                    }
                    else if ( strcmp(nptr, "depth") == 0 )
                    {
                      v26 = 12;
                    }
                    else
                    {
                      if ( strcmp(nptr, "sample") != 0 )
                        goto LABEL_151;
                      v26 = 13;
                    }
                  }
                }
              }
            }
            v20 = v26;
            goto LABEL_125;
          }
          BYTE2(v44) |= 0x20u;
          v33 = 0;
        }
      }
LABEL_208:
      this = v42;
LABEL_209:
      if ( *v41 == 0 )
      {
        v4 = v29;
        if ( v29 != 40 )
          goto LABEL_214;
        if ( v39 == 0 )
        {
          if ( dword_102B3758[*((_DWORD *)this + 14)] == -1 )
            return 269;
          v4 = 41;
          v45 = 268;
LABEL_214:
          if ( v4 == 44 )
          {
            if ( v39 == 0 )
            {
              if ( dword_102B37A0[*((_DWORD *)this + 14)] == -1 )
                return 269;
              v4 = 45;
              v45 = 268;
              goto LABEL_218;
            }
          }
          else
          {
LABEL_218:
            if ( v4 == 94 && v39 != 0 )
              return 269;
          }
        }
        if ( v37 == 0 )
          break;
        return 269;
      }
    }
  }
  *((_DWORD *)this + 17) = v44;
  *((_DWORD *)this + 18) = v43;
  *((_DWORD *)this + 16) = v4;
  *((_DWORD *)this + 21) = 0;
  return v45;
}

//------------------------------------------------------------------------------
// Address: 0x101C63CE
// Name: protected: unsigned long D3DXShader::CAssembler::DecodeMask(struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CAssembler::DecodeMask(
        D3DXShader::CTErrors **this,
        struct D3DXShader::D3DXTOKEN *a2)
{
  const char *v3; // edx
  unsigned int result; // eax
  char v5; // cl
  char *v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // [esp+8h] [ebp-4h]

  v3 = *((const char **)a2 + 2);
  result = 0;
  if ( v3 != nullptr )
  {
    v5 = *v3;
    if ( *v3 != 0 )
    {
      v6 = *((char **)a2 + 2);
      while ( 1 )
      {
        if ( v5 > 119 )
        {
          v11 = v5 - 120;
          if ( v11 != 0 )
          {
            v12 = v11 - 1;
            if ( v12 == 0 )
            {
LABEL_20:
              v10 = 1;
              result |= 0x20000u;
              goto LABEL_11;
            }
            if ( v12 != 1 )
              goto LABEL_21;
LABEL_19:
            v10 = 2;
            result |= 0x40000u;
            goto LABEL_11;
          }
        }
        else
        {
          if ( v5 == 119 || (v7 = v5 - 97) == 0 )
          {
            v10 = 3;
            result |= 0x80000u;
            goto LABEL_11;
          }
          v8 = v7 - 1;
          if ( v8 == 0 )
            goto LABEL_19;
          v9 = v8 - 5;
          if ( v9 == 0 )
            goto LABEL_20;
          if ( v9 != 11 )
            goto LABEL_21;
        }
        v10 = 0;
        result |= 0x10000u;
LABEL_11:
        if ( v6 != v3 && v10 <= v13 )
        {
LABEL_21:
          D3DXShader::CTErrors::Error(this: *this, a2, a3: 0x7D3u, format: "invalid mask '%s'", v3);
          *(this + 19) = (D3DXShader::CTErrors *)1;
          return 0;
        }
        ++v6;
        v13 = v10;
        v5 = *v6;
        if ( *v6 == 0 )
          return result;
      }
    }
  }
  return 983040;
}

//------------------------------------------------------------------------------
// Address: 0x101C6483
// Name: protected: unsigned long D3DXShader::CAssembler::DecodeSwizzle(struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CAssembler::DecodeSwizzle(
        D3DXShader::CTErrors **this,
        struct D3DXShader::D3DXTOKEN *a2)
{
  const char *v2; // esi
  int v3; // edi
  const char *v5; // eax
  char v6; // dl
  int v7; // edx
  int v8; // edx
  int v9; // edx
  char v10; // cl
  int v12; // edx
  int v13; // edx
  int v14; // [esp-4h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v2 = *((const char **)a2 + 2);
  v3 = 0;
  v15 = 0;
  v5 = v2;
  if ( v2 == nullptr || *v2 == 0 )
    return 14942208;
  for ( i = 16; i < 0x18; i += 2 )
  {
    v6 = *v5;
    if ( *v5 == 0 )
      goto LABEL_13;
    if ( v6 > 119 )
    {
      v12 = v6 - 120;
      if ( v12 == 0 )
        goto LABEL_11;
      v13 = v12 - 1;
      if ( v13 == 0 )
      {
LABEL_22:
        v3 = 1;
        goto LABEL_12;
      }
      if ( v13 != 1 )
        goto LABEL_15;
LABEL_21:
      v14 = 2;
LABEL_17:
      v3 = v14;
      goto LABEL_12;
    }
    if ( v6 == 119 || (v7 = v6 - 97) == 0 )
    {
      v14 = 3;
      goto LABEL_17;
    }
    v8 = v7 - 1;
    if ( v8 == 0 )
      goto LABEL_21;
    v9 = v8 - 5;
    if ( v9 == 0 )
      goto LABEL_22;
    if ( v9 != 11 )
      goto LABEL_15;
LABEL_11:
    v3 = 0;
LABEL_12:
    ++v5;
LABEL_13:
    v10 = i;
    v15 |= v3 << v10;
  }
  if ( *v5 != 0 )
  {
LABEL_15:
    D3DXShader::CTErrors::Error(this: *this, a2, a3: 0x7D4u, format: "invalid swizzle '%s'", v2);
    *(this + 19) = (D3DXShader::CTErrors *)1;
    return 0;
  }
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x101C653F
// Name: protected: long D3DXShader::CAssembler::Validate(struct D3DXShader::D3DXTOKEN __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::Validate(D3DXShader::CAssembler *this, struct D3DXShader::D3DXTOKEN *a2)
{
  int v3; // edi
  unsigned int v4; // edx
  unsigned int v5; // ecx
  int result; // eax
  int v7; // [esp-Ch] [ebp-14h]

  v3 = *((_DWORD *)this + 2);
  if ( v3 == 0 )
    return 0;
  v4 = *((_DWORD *)this + 25);
  v5 = *((_DWORD *)this + 23);
  if ( v4 >= v5 )
    return 0;
  v7 = *((_DWORD *)this + 22) + 4 * v4;
  *((_DWORD *)this + 12) = a2;
  result = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, unsigned int))(*(_DWORD *)v3 + 16))(
             a1: v3,
             a2: *((_DWORD *)a2 + 4),
             a3: *((_DWORD *)a2 + 5),
             a4: v7,
             a5: v5 - v4);
  if ( result < 0 )
  {
    *((_DWORD *)this + 19) = 1;
    *((_DWORD *)this + 20) = 1;
  }
  *((_DWORD *)this + 25) = *((_DWORD *)this + 23);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6594
// Name: protected: long D3DXShader::CAssembler::Assure(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::Assure(D3DXShader::CAssembler *this, unsigned int a2)
{
  int v3; // eax
  unsigned int v5; // edx
  unsigned int v6; // eax
  bool v7; // cc
  void *v8; // edi
  unsigned int v10; // [esp+14h] [ebp+8h]

  v3 = *((_DWORD *)this + 23);
  v5 = a2 + v3;
  v6 = *((_DWORD *)this + 24);
  if ( v5 > v6 )
  {
    v10 = *((_DWORD *)this + 24);
    if ( v6 == 0 )
      v10 = 256;
    if ( v5 > v10 )
    {
      do
      {
        v7 = a2 + *((_DWORD *)this + 23) <= 2 * v10;
        v10 *= 2;
      }
      while ( !v7 );
    }
    v8 = MemAlloc_Alloc(nSize: 4 * v10);
    if ( v8 == nullptr )
      return -2147024882;
    qmemcpy(v8, *((const void **)this + 22), 4 * *((_DWORD *)this + 23));
    free(pMem: *((void **)this + 22));
    *((_DWORD *)this + 22) = v8;
    *((_DWORD *)this + 24) = v10;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C6625
// Name: protected: long D3DXShader::CAssembler::Emit(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::Emit(D3DXShader::CAssembler *this, unsigned int a2)
{
  int result; // eax

  result = D3DXShader::CAssembler::Assure(this, a2: 1u);
  if ( result >= 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 22) + 4 * (*((_DWORD *)this + 23))++) = a2;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C664E
// Name: protected: long D3DXShader::CAssembler::EmitInstruction(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::EmitInstruction(D3DXShader::CAssembler *this, struct D3DXShader::CNode *a2)
{
  int v4; // eax
  int v5; // eax
  int result; // eax
  _DWORD *v7; // ebx
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // ebx
  int v13; // eax
  int *v14; // ebx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // edx
  bool v23; // zf
  int v24; // eax
  int v25; // eax
  int v26; // eax
  _DWORD *v27; // ecx
  int v28; // eax
  unsigned int v29; // eax
  _DWORD *v30; // ecx
  _DWORD *v31; // ecx
  int v32; // ecx
  int *v33; // ebx
  int v34; // ecx
  int v35; // edx
  int *v36; // ebx
  int v37; // ecx
  _DWORD *v38; // eax
  int v39; // ecx
  unsigned int v40; // ecx
  _DWORD *v41; // eax
  unsigned int v42; // [esp+8h] [ebp-Ch]
  int v43; // [esp+Ch] [ebp-8h]
  unsigned int v44; // [esp+10h] [ebp-4h]
  float v45; // [esp+10h] [ebp-4h]
  _DWORD *v46; // [esp+10h] [ebp-4h]
  struct D3DXShader::CNode *v47; // [esp+1Ch] [ebp+8h]
  struct D3DXShader::CNode *v48; // [esp+1Ch] [ebp+8h]
  struct D3DXShader::CNode *v49; // [esp+1Ch] [ebp+8h]
  struct D3DXShader::CNode *v50; // [esp+1Ch] [ebp+8h]

  *((_DWORD *)a2 + 22) = 4 * *((_DWORD *)this + 23);
  v4 = *((_DWORD *)a2 + 12);
  v44 = 1;
  v43 = 0;
  if ( v4 == 31 )
    v44 = 2;
  if ( *((_DWORD *)this + 30) != 0 )
  {
    if ( v4 == 26 || v4 == 25 || v4 == 28 || v4 == 30 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
        a3: 0x7E9u,
        format: "call, callnz, label, and ret instructions are not allowed in assembly fragments");
      return -2147467259;
    }
    if ( v4 == 20 || v4 == 21 || v4 == 22 || v4 == 23 || v4 == 24 )
    {
      v5 = *((_DWORD *)a2 + 18);
      if ( v5 != 0 && *(_DWORD *)(v5 + 16) == 0 )
      {
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)this,
          a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
          a3: 0x7EAu,
          format: "Matrices cannot be specified in temp registers with the fragment linker");
        return -2147467259;
      }
    }
  }
  v7 = *((_DWORD **)a2 + 15);
  if ( v7 != nullptr && v7[1] == 19 )
  {
    ++v44;
    if ( v7[4] == -1 )
      v43 = 1;
    if ( v7[5] != 0 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
        a3: 0x7DEu,
        format: "source modifiers are not allowed on destination parameters");
      *((_DWORD *)this + 19) = 1;
    }
    v8 = v7[10];
    if ( v8 != 0 )
    {
      v9 = *((_DWORD *)this + 14);
      if ( v9 < 4 || v9 > 5 )
      {
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)this,
          a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
          a3: 0x7D8u,
          format: "relative addressing of destination parameters is not supported in this shader version");
        *((_DWORD *)this + 19) = 1;
      }
      else
      {
        if ( *(_DWORD *)(v8 + 16) == -1 )
          v43 = 1;
        if ( *(_DWORD *)(v8 + 40) != 0 )
        {
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
            a3: 0x7D9u,
            format: "only one address register reference is allowed in a relative address expression");
          *((_DWORD *)this + 19) = 1;
        }
        ++v44;
      }
    }
  }
  v10 = *((_DWORD *)a2 + 16);
  if ( v10 != 0 && *(_DWORD *)(v10 + 4) == 19 )
  {
    v11 = *((_DWORD *)this + 14);
    if ( (unsigned int)v11 < 2 || v11 >= 6 && v11 <= 10 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
        a3: 0x7E5u,
        format: "predicates are not supported in this shader version");
      *((_DWORD *)this + 19) = 1;
    }
    v12 = *((_DWORD **)a2 + 16);
    ++v44;
    if ( v12[4] == -1 )
      v43 = 1;
    v13 = v12[5];
    if ( v13 != 0 && v13 != 218103808 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
        a3: 0x7E3u,
        format: "source modifiers are not allowed on predicates");
      *((_DWORD *)this + 19) = 1;
    }
    if ( v12[10] != 0 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
        a3: 0x7E4u,
        format: "relative addressing of predicates is not supported in this shader version");
      *((_DWORD *)this + 19) = 1;
    }
  }
  v47 = nullptr;
  v14 = (int *)((char *)a2 + 68);
  do
  {
    v15 = *v14;
    if ( *v14 == 0 )
      break;
    v16 = *((_DWORD *)a2 + 12);
    ++v44;
    if ( v16 != 81 && v16 != 48 && v16 != 47 )
    {
      if ( *(_DWORD *)(v15 + 16) == -1 )
        v43 = 1;
      v17 = *(_DWORD *)(v15 + 40);
      if ( v17 != 0 )
      {
        if ( *(_DWORD *)(v17 + 16) == -1 )
          v43 = 1;
        if ( *(_DWORD *)(v17 + 40) != 0 )
        {
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
            a3: 0x7D9u,
            format: "only one address register reference is allowed in a relative address expression");
          *((_DWORD *)this + 19) = 1;
        }
        if ( *((_DWORD *)this + 14) != 0 )
          ++v44;
      }
    }
    v47 = (struct D3DXShader::CNode *)((char *)v47 + 1);
    ++v14;
  }
  while ( (unsigned int)v47 < 4 );
  result = D3DXShader::CAssembler::Assure(this, a2: v44);
  if ( result >= 0 )
  {
    v18 = *((_DWORD *)a2 + 12);
    v42 = v44 + *((_DWORD *)this + 23);
    if ( v18 != 3 )
      goto LABEL_90;
    v19 = *((_DWORD *)this + 14);
    if ( (unsigned int)v19 >= 6 && (v19 < 10 || v19 > 14) )
      goto LABEL_90;
    v20 = *((_DWORD *)a2 + 18);
    v21 = *(_DWORD *)(v20 + 20);
    v22 = 117440512;
    v18 = 2;
    if ( v21 > 0x7000000 )
    {
      if ( v21 != 0x8000000 )
      {
        if ( v21 == 150994944 || v21 == 167772160 )
          goto LABEL_76;
        v22 = 184549376;
        if ( v21 == 184549376 )
        {
          *(_DWORD *)(v20 + 20) = 201326592;
          goto LABEL_90;
        }
        if ( v21 != 201326592 )
        {
          v23 = v21 == 218103808;
LABEL_75:
          if ( !v23 )
          {
LABEL_90:
            if ( *((_DWORD *)a2 + 21) != 0 )
              v18 |= 0x40000000u;
            if ( *((_DWORD *)a2 + 16) != 0 )
              v18 |= 0x10000000u;
            v24 = *((_DWORD *)this + 14);
            if ( v24 >= 1 && v24 <= 5 || v24 >= 10 && v24 <= 14 )
              v18 |= (v44 - 1) << 24;
            v25 = *((_DWORD *)a2 + 12);
            if ( v25 == 41 || v25 == 45 || v25 == 94 )
              v18 |= (*((_DWORD *)a2 + 14) & 7) << 16;
            *(_DWORD *)(*((_DWORD *)this + 22) + 4 * (*((_DWORD *)this + 23))++) = v18;
            v26 = *((_DWORD *)this + 23);
            if ( *((_DWORD *)a2 + 12) == 31 )
            {
              *(_DWORD *)(*((_DWORD *)this + 22) + 4 * v26) = *((_DWORD *)a2 + 14) | 0x80000000;
              v26 = ++*((_DWORD *)this + 23);
            }
            v27 = *((_DWORD **)a2 + 15);
            if ( v27 != nullptr && v27[1] == 19 )
            {
              if ( *((_DWORD *)this + 14) == 0 && v27[8] == 983040 )
              {
                v28 = *((_DWORD *)a2 + 12);
                if ( v28 == 21 || v28 == 23 )
                {
                  v27[8] = 458752;
                }
                else if ( v28 == 24 )
                {
                  v27[8] = 196608;
                }
              }
              v29 = v27[8] & 0xF0000
                  | v27[6] & 0x7FF
                  | *((_DWORD *)a2 + 13) & 0xFF00000
                  | ((v27[4] & 0x18 | ((v27[4] | 0xFFFFFFF8) << 20)) << 8);
              if ( v27[10] != 0 )
                v29 |= 0x2000u;
              *(_DWORD *)(*((_DWORD *)this + 22) + 4 * (*((_DWORD *)this + 23))++) = v29;
              v30 = (_DWORD *)v27[10];
              v26 = *((_DWORD *)this + 23);
              if ( v30 != nullptr )
              {
                *(_DWORD *)(*((_DWORD *)this + 22) + 4 * v26) = v30[9] & 0xFF0000
                                                              | v30[6] & 0x7FF
                                                              | v30[5] & 0xF000000
                                                              | ((v30[4] & 0x18 | ((v30[4] | 0xFFFFFFF8) << 20)) << 8);
                v26 = ++*((_DWORD *)this + 23);
              }
            }
            v31 = *((_DWORD **)a2 + 16);
            if ( v31 != nullptr && v31[1] == 19 )
            {
              *(_DWORD *)(*((_DWORD *)this + 22) + 4 * v26) = v31[9] & 0xFF0000
                                                            | v31[6] & 0x7FF
                                                            | v31[5] & 0xF000000
                                                            | ((v31[4] & 0x18 | ((v31[4] | 0xFFFFFFF8) << 20)) << 8);
              v26 = ++*((_DWORD *)this + 23);
            }
            v32 = *((_DWORD *)a2 + 12);
            switch ( v32 )
            {
              case 'Q':
                v48 = nullptr;
                v33 = (int *)((char *)a2 + 68);
                do
                {
                  v34 = *v33;
                  if ( *v33 == 0 )
                    break;
                  v35 = *(_DWORD *)(v34 + 16);
                  if ( v35 >= 5 && v35 <= 8 )
                  {
                    v45 = *(double *)(v34 + 24);
                    *(float *)(*((_DWORD *)this + 22) + 4 * v26) = v45;
                  }
                  ++*((_DWORD *)this + 23);
                  v48 = (struct D3DXShader::CNode *)((char *)v48 + 1);
                  v26 = *((_DWORD *)this + 23);
                  ++v33;
                }
                while ( (unsigned int)v48 < 4 );
                break;
              case '0':
                v49 = nullptr;
                v36 = (int *)((char *)a2 + 68);
                do
                {
                  v37 = *v36;
                  if ( *v36 == 0 )
                    break;
                  if ( *(_DWORD *)(v37 + 16) == 2 || *(_DWORD *)(v37 + 16) == 4 )
                    *(_DWORD *)(*((_DWORD *)this + 22) + 4 * v26) = *(_DWORD *)(v37 + 24);
                  ++*((_DWORD *)this + 23);
                  v49 = (struct D3DXShader::CNode *)((char *)v49 + 1);
                  v26 = *((_DWORD *)this + 23);
                  ++v36;
                }
                while ( (unsigned int)v49 < 4 );
                break;
              case '/':
                *(_DWORD *)(*((_DWORD *)this + 22) + 4 * v26) = *(_DWORD *)(*((_DWORD *)a2 + 17) + 24) != 0;
                ++*((_DWORD *)this + 23);
                break;
              default:
                v50 = nullptr;
                v46 = (_DWORD *)((char *)a2 + 68);
                do
                {
                  v38 = (_DWORD *)*v46;
                  if ( *v46 == 0 )
                    break;
                  if ( *((_DWORD *)this + 14) == 0 && v38[9] == 14942208 )
                  {
                    v39 = *((_DWORD *)a2 + 12);
                    if ( v39 == 6 || v39 == 7 || v39 == 14 || v39 == 78 || v39 == 15 || v39 == 79 )
                      v38[9] = 16711680;
                  }
                  v40 = v38[9] & 0xFF0000
                      | v38[6] & 0x7FF
                      | v38[5] & 0xF000000
                      | ((v38[4] & 0x18 | ((v38[4] | 0xFFFFFFF8) << 20)) << 8);
                  if ( v38[10] != 0 )
                    v40 |= 0x2000u;
                  *(_DWORD *)(*((_DWORD *)this + 22) + 4 * (*((_DWORD *)this + 23))++) = v40;
                  v41 = (_DWORD *)v38[10];
                  if ( v41 != nullptr )
                  {
                    if ( *((_DWORD *)this + 14) != 0 )
                    {
                      *(_DWORD *)(*((_DWORD *)this + 22) + 4 * (*((_DWORD *)this + 23))++) = v41[9] & 0xFF0000
                                                                                           | v41[6] & 0x7FF
                                                                                           | v41[5] & 0xF000000
                                                                                           | ((v41[4] & 0x18
                                                                                             | ((v41[4] | 0xFFFFFFF8) << 20)) << 8);
                    }
                    else if ( v41[4] != 3 || v41[5] != 0 || v41[6] != 0 || v41[9] != 0 )
                    {
                      D3DXShader::CTErrors::Error(
                        this: *(D3DXShader::CTErrors **)this,
                        a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
                        a3: 0x7D7u,
                        format: "only a0.x is allowed as a relative address register in vs_1_1");
                      *((_DWORD *)this + 19) = 1;
                    }
                  }
                  v50 = (struct D3DXShader::CNode *)((char *)v50 + 1);
                  ++v46;
                }
                while ( (unsigned int)v50 < 4 );
                break;
            }
            if ( *((_DWORD *)this + 23) != v42 )
            {
              D3DXShader::CTErrors::Error(
                this: *(D3DXShader::CTErrors **)this,
                a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
                a3: 0,
                format: "internal error: instruction size mismatch");
              *((_DWORD *)this + 19) = 1;
            }
            if ( v43 != 0 )
            {
              *((_DWORD *)this + 25) = *((_DWORD *)this + 23);
            }
            else if ( D3DXShader::CAssembler::Validate(this, a2: (struct D3DXShader::CNode *)((char *)a2 + 16)) < 0 )
            {
              *((_DWORD *)this + 20) = 1;
            }
            return 0;
          }
LABEL_76:
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (struct D3DXShader::CNode *)((char *)a2 + 16),
            a3: 0x7DDu,
            format: "source modifiers incompatible with SUB instruction");
          *((_DWORD *)this + 19) = 1;
          goto LABEL_90;
        }
      }
    }
    else
    {
      switch ( v21 )
      {
        case 0x7000000u:
          *(_DWORD *)(v20 + 20) = 0x8000000;
          goto LABEL_90;
        case 0u:
          *(_DWORD *)(v20 + 20) = 0x1000000;
          goto LABEL_90;
        case 0x1000000u:
          *(_DWORD *)(v20 + 20) = 0;
          goto LABEL_90;
        default:
          break;
      }
      v22 = 0x2000000;
      if ( v21 == 0x2000000 )
      {
        *(_DWORD *)(v20 + 20) = 50331648;
        goto LABEL_90;
      }
      if ( v21 != 50331648 )
      {
        v22 = 0x4000000;
        if ( v21 == 0x4000000 )
        {
          *(_DWORD *)(v20 + 20) = 83886080;
          goto LABEL_90;
        }
        if ( v21 != 83886080 )
        {
          v23 = v21 == 100663296;
          goto LABEL_75;
        }
      }
    }
    *(_DWORD *)(v20 + 20) = v22;
    goto LABEL_90;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6DCA
// Name: int D3DXShader::compare(void const __near *,void const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl D3DXShader::compare(const void ***a1, const char ***a2)
{
  const char *v2; // edx
  const char **v3; // eax
  const char *v4; // edi
  int result; // eax
  bool v6; // cf
  const char *v7; // eax
  const char *v8; // esi
  unsigned __int8 v9; // dl

  v2 = (const char *)**a1;
  v3 = *a2;
  if ( *(_WORD *)"v_" == *(_WORD *)v2
    || *(_WORD *)"r_" == *(_WORD *)v2
    || *(_WORD *)"o_" == *(_WORD *)v2
    || (v4 = *v3, *(_WORD *)"v_" == *(_WORD *)*v3)
    || *(_WORD *)"r_" == *(_WORD *)v4
    || *(_WORD *)"o_" == *(_WORD *)v4 )
  {
    v7 = *v3;
    v8 = (const char *)**a1;
    while ( 1 )
    {
      v6 = *v8 < (unsigned int)*v7;
      if ( *v8 != *v7 )
        break;
      if ( *v8 != 0 )
      {
        v9 = v8[1];
        v6 = v9 < (unsigned int)v7[1];
        if ( v9 != v7[1] )
          return -v6 - (v6 - 1);
        v8 += 2;
        v7 += 2;
        if ( v9 != 0 )
          continue;
      }
      return 0;
    }
    return -v6 - (v6 - 1);
  }
  result = strcmp(v2 + 2, v4 + 2);
  if ( result == 0 )
  {
    result = 0;
    v6 = false;
    if ( memcmp(**a1, v4, 2u) != 0 )
      return -v6 - (v6 - 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6E91
// Name: protected: long D3DXShader::CAssembler::EmitFragmentInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::EmitFragmentInfo(D3DXShader::CAssembler *this)
{
  int v2; // edi
  _DWORD *v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct D3DXShader::CRegisterEntryNode **v7; // eax
  struct D3DXShader::CRegisterEntryNode **v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // esi
  unsigned int v17; // esi
  int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // esi
  int v22; // eax
  unsigned int v24[7]; // [esp+8h] [ebp-3Ch] BYREF
  _BYTE v25[16]; // [esp+24h] [ebp-20h] BYREF
  void *pMem; // [esp+34h] [ebp-10h]
  unsigned int nSize; // [esp+38h] [ebp-Ch]
  unsigned int v28; // [esp+3Ch] [ebp-8h]
  void *v29; // [esp+40h] [ebp-4h]

  v2 = 0;
  D3DXShader::CCommentBlock::CCommentBlock(this: (D3DXShader::CCommentBlock *)v25, a2: 0x464E4946u);
  v3 = *((_DWORD **)this + 30);
  v4 = v3[42] + v3[43];
  pMem = nullptr;
  v5 = v3[41] + v4;
  v29 = nullptr;
  v6 = v3[39] + v3[40] + v5;
  if ( v6 != 0 )
  {
    v7 = (struct D3DXShader::CRegisterEntryNode **)MemAlloc_Alloc(nSize: 4 * v6);
    v8 = v7;
    pMem = v7;
    if ( v7 != nullptr )
    {
      D3DXShader::CFragmentRegisterAllocator::GetElements(
        this: *((D3DXShader::CFragmentRegisterAllocator **)this + 30),
        a2: v7);
      v9 = *((_DWORD *)this + 30);
      v10 = *(_DWORD *)(v9 + 172);
      D3DXShader::CFragmentRegisterAllocator::GetElements(
        this: (D3DXShader::CFragmentRegisterAllocator *)(v9 + 112),
        a2: &v8[v10]);
      v11 = *((_DWORD *)this + 30);
      v12 = *(_DWORD *)(v11 + 168) + v10;
      D3DXShader::CFragmentRegisterAllocator::GetElements(
        this: (D3DXShader::CFragmentRegisterAllocator *)(v11 + 28),
        a2: &v8[v12]);
      v13 = *((_DWORD *)this + 30);
      v14 = *(_DWORD *)(v13 + 156) + v12;
      D3DXShader::CFragmentRegisterAllocator::GetElements(
        this: (D3DXShader::CFragmentRegisterAllocator *)(v13 + 56),
        a2: &v8[v14]);
      v15 = *((_DWORD *)this + 30);
      v16 = *(_DWORD *)(v15 + 160) + v14;
      D3DXShader::CFragmentRegisterAllocator::GetElements(
        this: (D3DXShader::CFragmentRegisterAllocator *)(v15 + 84),
        a2: &v8[v16]);
      v17 = *(_DWORD *)(*((_DWORD *)this + 30) + 164) + v16;
      qsort(base: v8, num: v17, width: 4u, comp: (int (__cdecl *)(const void *, const void *))D3DXShader::compare);
      nSize = 20 * v17;
      v29 = MemAlloc_Alloc(nSize: 20 * v17);
      if ( v29 != nullptr )
      {
        memset(v24, 0, sizeof(v24));
        v18 = *((_DWORD *)this + 15);
        v24[2] = 0;
        v24[0] = 28;
        v24[5] = v18 | 4;
        v24[3] = v17;
        v2 = D3DXShader::CCommentBlock::Add(
               this: (D3DXShader::CCommentBlock *)v25,
               pMem: v24,
               nSize: 0x1Cu,
               a4: 1u,
               a5: nullptr);
        if ( v2 >= 0 )
        {
          v19 = nSize;
          memset(v29, 0, nSize);
          v2 = D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v25,
                 pMem: v29,
                 nSize: v19,
                 a4: 1u,
                 a5: &v24[4]);
          if ( v2 >= 0 )
          {
            v28 = 0;
            if ( v17 != 0 )
            {
              nSize = (unsigned int)v29;
              while ( 1 )
              {
                v2 = D3DXShader::CFragmentConstants::AddRegister(
                       this: *((D3DXShader::CFragmentConstants **)this + 31),
                       a2: (struct D3DXShader::CCommentBlock *)v25,
                       a3: (struct _D3DXSHADER_CONSTANTINFO *)nSize,
                       a4: **((const char ***)pMem + v28),
                       a5: *(_DWORD *)(*((_DWORD *)pMem + v28) + 4),
                       a6: **((_DWORD **)this + 22));
                if ( v2 < 0 )
                  break;
                ++v28;
                nSize += 20;
                if ( v28 >= v17 )
                  goto LABEL_12;
              }
            }
            else
            {
LABEL_12:
              v2 = D3DXShader::CCommentBlock::Add(
                     this: (D3DXShader::CCommentBlock *)v25,
                     pMem: "Microsoft (R) D3DX9 Shader Assembler 5.04.00.3900",
                     nSize: 0xFFFFFFFF,
                     a4: 5u,
                     a5: &v24[1]);
              if ( v2 >= 0 )
              {
                v20 = D3DXShader::CCommentBlock::SizeInDwords(this: (D3DXShader::CCommentBlock *)v25);
                v21 = v20;
                if ( v20 > 0x8000 )
                {
                  D3DXShader::CTErrors::Error(
                    this: *(D3DXShader::CTErrors **)this,
                    a2: (D3DXShader::CAssembler *)((char *)this + 16),
                    a3: 0x7EFu,
                    format: "fragment info exceeds maximum comment size");
                  v2 = -2147467259;
                }
                else
                {
                  v2 = D3DXShader::CAssembler::Assure(this, a2: v20);
                  if ( v2 >= 0 )
                  {
                    memmove(
                      dst: (unsigned __int8 *)(*((_DWORD *)this + 22) + 4 * v21 + 4),
                      src: (unsigned __int8 *)(*((_DWORD *)this + 22) + 4),
                      count: 4 * *((_DWORD *)this + 23) - 4);
                    v2 = D3DXShader::CCommentBlock::WriteComment(
                           this: (D3DXShader::CCommentBlock *)v25,
                           a2: (unsigned int *)(*((_DWORD *)this + 22) + 4),
                           a3: v21);
                    if ( v2 >= 0 )
                    {
                      *((_DWORD *)this + 23) += v21;
                      v22 = *((_DWORD *)this + 23);
                      *((_DWORD *)this + 26) += v21;
                      *((_DWORD *)this + 25) = v22;
                      v2 = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v2 = -2147024882;
      }
    }
    else
    {
      v2 = -2147024882;
    }
  }
  free(pMem);
  free(pMem: v29);
  D3DXShader::CCommentBlock::~CCommentBlock(this: (D3DXShader::CCommentBlock *)v25);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101C7103
// Name: public: D3DXShader::CRegisterEntryNode::CRegisterEntryNode(char __near *,unsigned int,unsigned int,class D3DXShader::CRegisterEntryNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CRegisterEntryNode *__thiscall D3DXShader::CRegisterEntryNode::CRegisterEntryNode(
        D3DXShader::CRegisterEntryNode *this,
        char *a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CRegisterEntryNode *a5)
{
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 8) = a5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C7129
// Name: protected: long D3DXShader::CAssembler::EmitDebugInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::EmitDebugInfo(D3DXShader::CAssembler *this)
{
  int v2; // ebx
  int i; // eax
  int v4; // ecx
  int j; // eax
  void *v6; // edi
  int v7; // edi
  char *v8; // ebx
  const void *v9; // eax
  unsigned int v10; // eax
  const void *v11; // eax
  const void *v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  int v17; // eax
  unsigned int v19[10]; // [esp+Ch] [ebp-50h] BYREF
  _BYTE v20[16]; // [esp+34h] [ebp-28h] BYREF
  unsigned int nSize; // [esp+44h] [ebp-18h]
  unsigned int v22; // [esp+48h] [ebp-14h] BYREF
  unsigned int k; // [esp+4Ch] [ebp-10h]
  void *pMem; // [esp+50h] [ebp-Ch]
  void *v25; // [esp+54h] [ebp-8h]
  int v26; // [esp+58h] [ebp-4h]

  D3DXShader::CCommentBlock::CCommentBlock(this: (D3DXShader::CCommentBlock *)v20, a2: 0x47554244u);
  memset(v19, 0, sizeof(v19));
  v2 = 0;
  v19[0] = 40;
  pMem = nullptr;
  v25 = nullptr;
  v26 = D3DXShader::CCommentBlock::Add(
          this: (D3DXShader::CCommentBlock *)v20,
          pMem: v19,
          nSize: 0x28u,
          a4: 1u,
          a5: nullptr);
  if ( v26 >= 0 )
  {
    for ( i = *((_DWORD *)this + 13); i != 0; i = *(_DWORD *)(i + 12) )
    {
      v4 = *(_DWORD *)(i + 8);
      if ( v4 != 0 && *(_DWORD *)(v4 + 4) == 18 )
      {
        v2 = *(_DWORD *)(i + 8);
        break;
      }
    }
    for ( j = v2; j != 0; j = *(_DWORD *)(j + 12) )
      ++v19[5];
    if ( v19[5] == 0 )
      goto LABEL_29;
    v6 = MemAlloc_Alloc(nSize: 4 * v19[5]);
    pMem = v6;
    if ( v6 == nullptr || (memset(v6, 0, 4 * v19[5]), (v25 = MemAlloc_Alloc(nSize: 8 * v19[5])) == nullptr) )
    {
      v26 = -2147024882;
      goto LABEL_44;
    }
    nSize = 8 * v19[5];
    memset(v25, 0, 8 * v19[5]);
    v7 = v2;
    if ( v2 != 0 )
    {
      v8 = (char *)v25 + 8 * v19[5] - 6;
      do
      {
        *(_WORD *)v8 = -1;
        *((_WORD *)v8 - 1) = *(_WORD *)(v7 + 36);
        *(_DWORD *)(v8 + 2) = *(_DWORD *)(v7 + 88);
        v9 = *(const void **)(v7 + 32);
        if ( v9 != nullptr )
        {
          if ( D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v20,
                 pMem: v9,
                 nSize: 0xFFFFFFFF,
                 a4: 7u,
                 a5: &v22) < 0 )
            goto LABEL_44;
          v10 = 0;
          for ( k = 0; v10 < v19[3]; k = ++v10 )
          {
            if ( *((_DWORD *)pMem + v10) == v22 )
              break;
          }
          if ( v10 == v19[3] )
          {
            *((_DWORD *)pMem + v19[3]++) = v22;
            LOWORD(v10) = k;
          }
          *(_WORD *)v8 = v10;
        }
        v7 = *(_DWORD *)(v7 + 12);
        v8 -= 8;
      }
      while ( v7 != 0 );
    }
    if ( v19[3] == 0
      || (v26 = D3DXShader::CCommentBlock::Add(
                  this: (D3DXShader::CCommentBlock *)v20,
                  pMem,
                  nSize: 4 * v19[3],
                  a4: 1u,
                  a5: &v19[4])) >= 0 )
    {
      v26 = D3DXShader::CCommentBlock::Add(
              this: (D3DXShader::CCommentBlock *)v20,
              pMem: v25,
              nSize,
              a4: 1u,
              a5: &v19[6]);
      if ( v26 >= 0 )
      {
LABEL_29:
        v11 = *((const void **)this + 29);
        if ( v11 == nullptr
          || (v26 = D3DXShader::CCommentBlock::Add(
                      this: (D3DXShader::CCommentBlock *)v20,
                      pMem: v11,
                      nSize: 0xFFFFFFFF,
                      a4: 7u,
                      a5: &v19[9])) >= 0 )
        {
          v12 = *((const void **)this + 27);
          if ( (v12 == nullptr
             || D3DXShader::CCommentBlock::Add(
                  this: (D3DXShader::CCommentBlock *)v20,
                  pMem: v12,
                  nSize: *((_DWORD *)this + 28),
                  a4: 5u,
                  a5: &v19[2]) >= 0
             && D3DXShader::CCommentBlock::Add(
                  this: (D3DXShader::CCommentBlock *)v20,
                  pMem: &::pMem,
                  nSize: 1u,
                  a4: 5u,
                  a5: nullptr) >= 0)
            && D3DXShader::CCommentBlock::Add(
                 this: (D3DXShader::CCommentBlock *)v20,
                 pMem: "Microsoft (R) D3DX9 Shader Assembler 5.04.00.3900",
                 nSize: 0xFFFFFFFF,
                 a4: 5u,
                 a5: &v19[1]) >= 0 )
          {
            v13 = D3DXShader::CCommentBlock::SizeInDwords(this: (D3DXShader::CCommentBlock *)v20);
            v14 = v13;
            if ( v13 > 0x8000 )
            {
              D3DXShader::CTErrors::Warning(
                this: *(D3DXShader::CTErrors **)this,
                a2: (D3DXShader::CAssembler *)((char *)this + 16),
                a3: 0x7EEu,
                format: "debug info exceeds maximum comment size; no debug info emitted");
              goto LABEL_43;
            }
            v26 = D3DXShader::CAssembler::Assure(this, a2: v13);
            if ( v26 >= 0 )
            {
              memmove(
                dst: (unsigned __int8 *)(*((_DWORD *)this + 22) + 4 * v14 + 4),
                src: (unsigned __int8 *)(*((_DWORD *)this + 22) + 4),
                count: 4 * *((_DWORD *)this + 23) - 4);
              v15 = 0;
              if ( v19[5] != 0 )
              {
                v16 = (char *)v25 + 4;
                do
                {
                  *v16 += 4 * (v14 + *((_DWORD *)this + 26));
                  ++v15;
                  v16 += 2;
                }
                while ( v15 < v19[5] );
              }
              v26 = D3DXShader::CCommentBlock::WriteComment(
                      this: (D3DXShader::CCommentBlock *)v20,
                      a2: (unsigned int *)(*((_DWORD *)this + 22) + 4),
                      a3: v14);
              if ( v26 >= 0 )
              {
                *((_DWORD *)this + 23) += v14;
                v17 = *((_DWORD *)this + 23);
                *((_DWORD *)this + 26) += v14;
                *((_DWORD *)this + 25) = v17;
LABEL_43:
                v26 = 0;
              }
            }
          }
        }
      }
    }
  }
LABEL_44:
  free(pMem);
  free(pMem: v25);
  D3DXShader::CCommentBlock::~CCommentBlock(this: (D3DXShader::CCommentBlock *)v20);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x101C7430
// Name: public: D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(
        D3DXShader::CFragmentRegisterAllocator *this)
{
  unsigned int i; // esi
  D3DXShader::CRegisterEntryNode *v3; // ecx

  for ( i = 0; i < 7; ++i )
  {
    v3 = *((D3DXShader::CRegisterEntryNode **)this + i);
    if ( v3 != nullptr )
      D3DXShader::CRegisterEntryNode::`scalar deleting destructor'(this: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C744F
// Name: protected: long D3DXShader::CAssembler::GetShaderCode(struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::GetShaderCode(D3DXShader::CAssembler *this, struct ID3DXBuffer **a2)
{
  int result; // eax
  unsigned int v4; // eax
  struct D3DXCore::CBuffer *v5; // [esp+4h] [ebp-4h] BYREF

  result = D3DXCore::CBuffer::Create(a1: 4 * *((_DWORD *)this + 23), a2: &v5);
  if ( result >= 0 )
  {
    v4 = (*(int (__stdcall **)(struct D3DXCore::CBuffer *))(*(_DWORD *)v5 + 16))(a1: v5);
    qmemcpy(
      (void *)(*(int (__stdcall **)(struct D3DXCore::CBuffer *))(*(_DWORD *)v5 + 12))(a1: v5),
      *((const void **)this + 22),
      v4);
    *a2 = (struct ID3DXBuffer *)v5;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C74A8
// Name: public: long D3DXShader::CFragmentRegisterAllocator::AddElement(char const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CFragmentRegisterAllocator::AddElement(
        struct D3DXShader::CRegisterEntryNode **this,
        D3DXShader *a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int v4; // kr00_4
  D3DXShader *v5; // ebx
  D3DXShader::CRegisterEntryNode *v6; // eax
  D3DXShader::CRegisterEntryNode *v7; // eax
  const char *v9; // [esp+0h] [ebp-8h]
  unsigned int v10; // [esp+0h] [ebp-8h]

  v10 = D3DXShader::RegisterHash(this: a2, a2: v9);
  v4 = strlen((const char *)a2);
  v5 = (D3DXShader *)MemAlloc_Alloc(nSize: v4 + 1);
  if ( v5 == nullptr )
    return -2147024882;
  qmemcpy(v5, a2, v4 + 1);
  v6 = (D3DXShader::CRegisterEntryNode *)MemAlloc_Alloc(nSize: 0x24u);
  v7 = v6 != nullptr
     ? D3DXShader::CRegisterEntryNode::CRegisterEntryNode(this: v6, a2: (char *)v5, a3, a4, a5: *(this + v10))
     : nullptr;
  if ( v7 == nullptr )
    return -2147024882;
  *(this + v10) = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C7538
// Name: public: D3DXShader::CFragmentInfo::CFragmentInfo(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CFragmentInfo *__thiscall D3DXShader::CFragmentInfo::CFragmentInfo(D3DXShader::CFragmentInfo *this, int a2)
{
  memset(this, 0, 0x1Cu);
  memset((char *)this + 28, 0, 0x1Cu);
  memset((char *)this + 56, 0, 0x1Cu);
  memset((char *)this + 84, 0, 0x1Cu);
  memset((char *)this + 112, 0, 0x1Cu);
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 45) = a2;
  *((_DWORD *)this + 44) = 0;
  if ( a2 >= 4 && a2 <= 5 )
    *((_DWORD *)this + 44) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C75C7
// Name: public: D3DXShader::CFragmentInfo::~CFragmentInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CFragmentInfo::~CFragmentInfo(D3DXShader::CFragmentInfo *this)
{
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CFragmentInfo *)((char *)this + 112));
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CFragmentInfo *)((char *)this + 84));
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CFragmentInfo *)((char *)this + 56));
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this: (D3DXShader::CFragmentInfo *)((char *)this + 28));
  D3DXShader::CFragmentRegisterAllocator::~CFragmentRegisterAllocator(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C75F4
// Name: public: long D3DXShader::CFragmentInfo::GetRegisterInfo(class D3DXShader::CTErrors __near *,class D3DXShader::CFragmentConstants __near *,struct D3DXShader::D3DXTOKEN __near *,char const __near *,class D3DXShader::CNode __near *,unsigned long __near *,unsigned long __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXShader::CFragmentInfo::GetRegisterInfo@<eax>(
        D3DXShader::CFragmentInfo *this@<ecx>,
        unsigned __int8 *a2@<edi>,
        struct D3DXShader::CTErrors *a3,
        struct D3DXShader::CFragmentConstants *a4,
        struct D3DXShader::D3DXTOKEN *a5,
        D3DXShader *a6,
        struct D3DXShader::CNode *a7,
        unsigned int *a8,
        unsigned int *a9,
        unsigned int *a10)
{
  D3DXShader *v10; // ebx
  int result; // eax
  unsigned int *v13; // ecx
  unsigned int *v14; // edi
  int v15; // eax
  struct D3DXShader::CRegisterEntryNode **v16; // edi
  struct D3DXShader::CRegisterEntryNode *Element; // eax
  unsigned int *v18; // esi
  struct D3DXShader::CRegisterEntryNode **v19; // edi
  struct D3DXShader::CRegisterEntryNode *v20; // eax
  unsigned int *v21; // esi
  __int16 v22; // dx
  struct D3DXShader::CRegisterEntryNode **v23; // edi
  struct D3DXShader::CRegisterEntryNode *v24; // eax
  unsigned int *v25; // esi
  int v26; // edi
  struct D3DXShader::CRegisterEntryNode *v27; // eax
  unsigned int *v28; // ecx
  unsigned int *v29; // edi
  unsigned int v30; // eax
  int v31; // [esp-8h] [ebp-10h]
  unsigned int *v32; // [esp-8h] [ebp-10h]

  v10 = a6;
  if ( strlen((const char *)a6) <= 2 )
  {
    D3DXShader::CTErrors::Error(
      this: a3,
      a2: a5,
      a3: 0x7D5u,
      format: "invalid register, input, or constant name '%s'",
      (const char *)a6);
    return -2147467259;
  }
  v13 = a9;
  v14 = a8;
  *a8 = 0;
  *v13 = 0;
  *a10 = 0;
  if ( *(_WORD *)v10 == *(_WORD *)"v_" )
  {
    v15 = *((_DWORD *)this + 45);
    if ( v15 < 10 || v15 > 12 )
    {
      *v14 = 1;
      v16 = (struct D3DXShader::CRegisterEntryNode **)((char *)this + 28);
      Element = D3DXShader::CFragmentRegisterAllocator::GetElement(
                  this: (D3DXShader::CFragmentInfo *)((char *)this + 28),
                  lpString2: v10);
      if ( Element != nullptr )
      {
        *a10 = *((_DWORD *)Element + 1);
      }
      else
      {
        if ( D3DXShader::GetUsageAndIndex(
               this: (D3DXShader *)((char *)v10 + 2),
               a2: (const char *)&a8 + 3,
               a3: (unsigned __int8 *)&a6 + 3,
               a4: a2) < 0 )
          goto LABEL_7;
        v18 = (unsigned int *)((char *)this + 156);
        *a10 = *v18;
        D3DXShader::CFragmentRegisterAllocator::AddElement(this: v16, a2: v10, a3: *v18, a4: 1u);
        ++*v18;
      }
      if ( a7 != nullptr )
      {
        D3DXShader::CTErrors::Error(
          this: a3,
          a2: a5,
          a3: 0x7D5u,
          format: "addressing operations are not allowed on input registers '%s'",
          v10);
        return -2147467259;
      }
    }
    else
    {
      if ( D3DXShader::GetUsageAndIndex(
             this: (D3DXShader *)((char *)v10 + 2),
             a2: (const char *)&a7 + 3,
             a3: (unsigned __int8 *)&a6 + 3,
             a4: a2) < 0 )
      {
LABEL_7:
        D3DXShader::CTErrors::Error(this: a3, a2: a5, a3: 0x7D5u, format: "Invalid input register '%s' specified", v10);
        return -2147467259;
      }
      if ( HIBYTE(a7) == 5 )
      {
        *v14 = 3;
      }
      else
      {
        if ( HIBYTE(a7) != 10 )
        {
          D3DXShader::CTErrors::Error(
            this: a3,
            a2: a5,
            a3: 0x7D5u,
            format: "Invalid pixel shader input register '%s' specified",
            v10);
          return -2147467259;
        }
        *v14 = 1;
      }
      *a10 = HIBYTE(a6);
    }
  }
  else if ( *(_WORD *)v10 == *(_WORD *)"r_" )
  {
    *v14 = 0;
    v19 = (struct D3DXShader::CRegisterEntryNode **)((char *)this + 84);
    v20 = D3DXShader::CFragmentRegisterAllocator::GetElement(
            this: (D3DXShader::CFragmentInfo *)((char *)this + 84),
            lpString2: v10);
    if ( v20 != nullptr )
    {
      *a10 = *((_DWORD *)v20 + 1);
    }
    else
    {
      v21 = (unsigned int *)((char *)this + 164);
      *a10 = *v21;
      D3DXShader::CFragmentRegisterAllocator::AddElement(this: v19, a2: v10, a3: *v21, a4: 1u);
      ++*v21;
    }
    if ( a7 != nullptr )
    {
      D3DXShader::CTErrors::Error(
        this: a3,
        a2: a5,
        a3: 0x7D5u,
        format: "addressing operations not allowed on temporary registers '%s'",
        v10);
      return -2147467259;
    }
  }
  else
  {
    v22 = *(_WORD *)v10;
    if ( *(_WORD *)v10 == *(_WORD *)"c_" || v22 == *(_WORD *)"b_" || v22 == *(_WORD *)"i_" || v22 == *(_WORD *)"s_" )
    {
      if ( *(_WORD *)v10 == *(_WORD *)"b_" )
      {
        *v14 = 14;
        v26 = 0;
      }
      else if ( *(_WORD *)v10 == *(_WORD *)"i_" )
      {
        *v14 = 7;
        v26 = 1;
      }
      else
      {
        if ( *(_WORD *)v10 == *(_WORD *)"s_" )
        {
          *v14 = 10;
          v31 = 2;
        }
        else
        {
          *v14 = 2;
          v31 = 3;
        }
        v26 = v31;
      }
      v27 = D3DXShader::CFragmentRegisterAllocator::GetElement(this, lpString2: v10);
      if ( v27 != nullptr )
      {
        v28 = a10;
        *a10 = *((_DWORD *)v27 + 1);
        a9 = *((unsigned int **)v27 + 2);
      }
      else
      {
        result = D3DXShader::CFragmentConstants::GetConstantSize(
                   this: a4,
                   a2: a5,
                   a3: (const char *)v10,
                   a4: (unsigned int *)&a9);
        if ( result < 0 )
          return result;
        if ( a9 == nullptr )
        {
          D3DXShader::CTErrors::Error(
            this: a3,
            a2: a5,
            a3: 0x7D5u,
            format: "constant register '%s' must be defined as a variable '%s'",
            (const char *)v10,
            (const char *)v10 + 2);
          return -2147467259;
        }
        v32 = a9;
        v29 = (unsigned int *)((char *)this + 4 * v26 + 140);
        *a10 = *v29;
        D3DXShader::CFragmentRegisterAllocator::AddElement(
          (struct D3DXShader::CRegisterEntryNode **)this,
          a2: v10,
          a3: *v29,
          a4: (unsigned int)v32);
        *v29 += (unsigned int)a9;
        ++*((_DWORD *)this + 43);
        v28 = a10;
      }
      if ( a7 != nullptr )
      {
        v30 = *((_DWORD *)a7 + 6);
        if ( v30 > (unsigned int)a9 )
        {
          D3DXShader::CTErrors::Error(
            this: a3,
            a2: a5,
            a3: 0x7D5u,
            format: "constant register address out of bounds on constant '%s', size %d, offset %d",
            (const char *)v10,
            a9,
            v30);
          return -2147467259;
        }
        *v28 += v30;
      }
    }
    else
    {
      if ( *((_DWORD *)this + 44) == 0 || v22 != *(_WORD *)"o_" )
      {
        D3DXShader::CTErrors::Error(
          this: a3,
          a2: a5,
          a3: 0x7D5u,
          format: "'%s' is not a valid register name.  Registers must start with v_, r_, c_, b_, or i_ depending on the register "
          "type. (o_ for vs_3_0 only)",
          v10);
        return -2147467259;
      }
      *v14 = 6;
      v23 = (struct D3DXShader::CRegisterEntryNode **)((char *)this + 56);
      v24 = D3DXShader::CFragmentRegisterAllocator::GetElement(
              this: (D3DXShader::CFragmentInfo *)((char *)this + 56),
              lpString2: v10);
      if ( v24 != nullptr )
      {
        *a10 = *((_DWORD *)v24 + 1);
      }
      else
      {
        if ( D3DXShader::GetUsageAndIndex(
               this: (D3DXShader *)((char *)v10 + 2),
               a2: (const char *)&a8 + 3,
               a3: (unsigned __int8 *)&a6 + 3,
               a4: a2) < 0 )
        {
          D3DXShader::CTErrors::Error(
            this: a3,
            a2: a5,
            a3: 0x7D5u,
            format: "Invalid output register '%s' specified",
            v10);
          return -2147467259;
        }
        v25 = (unsigned int *)((char *)this + 160);
        *a10 = *v25;
        D3DXShader::CFragmentRegisterAllocator::AddElement(this: v23, a2: v10, a3: *v25, a4: 1u);
        ++*v25;
      }
      if ( a7 != nullptr )
      {
        D3DXShader::CTErrors::Error(
          this: a3,
          a2: a5,
          a3: 0x7D5u,
          format: "addressing operations are not allowed on output registers '%s'",
          v10);
        return -2147467259;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C7987
// Name: protected: int D3DXShader::CAssembler::Token(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::Token(D3DXShader::CAssembler *this)
{
  struct D3DXShader::D3DXTOKEN *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = (D3DXShader::CAssembler *)((char *)this + 16);
  while ( 1 )
  {
    if ( D3DXShader::CPreProcessor::GetToken(this: *((D3DXShader::CPreProcessor **)this + 1), a2: v2) < 0 )
    {
      *((_DWORD *)this + 19) = 1;
      *((_DWORD *)this + 20) = 1;
      return -1;
    }
    v3 = *(_DWORD *)v2;
    if ( *(int *)v2 <= 9 )
      break;
    v4 = v3 - 10;
    if ( v4 == 0 )
      return 272;
    v5 = v4 - 2;
    if ( v5 != 0 )
    {
      if ( v5 != 1 )
        return 272;
      return -1;
    }
  }
  if ( *(_DWORD *)v2 == 9 )
  {
    if ( strcmp(*((const char **)this + 6), "entrypoint") == 0 )
    {
      return 257;
    }
    else if ( strcmp(*((const char **)this + 6), "true") == 0 )
    {
      return 273;
    }
    else if ( strcmp(*((const char **)this + 6), "false") == 0 )
    {
      return 274;
    }
    else if ( *((_DWORD *)this + 14) == -1 )
    {
      return 269;
    }
    else
    {
      return D3DXShader::CAssembler::DecodeOpcode(this, a2: (D3DXShader::CAssembler *)((char *)this + 16));
    }
  }
  else
  {
    if ( v3 == 0 )
      return 272;
    if ( v3 == 1 )
    {
      if ( *((_BYTE *)this + 25) != 0 )
        return 272;
      return *((char *)this + 24);
    }
    else
    {
      if ( v3 <= 1 )
        return 272;
      if ( v3 > 4 )
      {
        if ( v3 <= 8 )
          return 271;
        return 272;
      }
      return 270;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7A65
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CAssembler::DecodeRegister(struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CAssembler::DecodeRegister(
        D3DXShader::CAssembler *this,
        struct D3DXShader::D3DXTOKEN *a2,
        struct D3DXShader::CNode *a3)
{
  D3DXShader *v3; // edx
  struct D3DXShader::CNode *v4; // esi
  char *v5; // edi
  D3DXShader::CAssembler *v6; // ebx
  int v7; // eax
  unsigned int v8; // eax
  char *v9; // esi
  char v10; // al
  unsigned int i; // edx
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  unsigned int v16; // edx
  char *v17; // esi
  int v18; // ecx
  bool v19; // zf
  unsigned int v20; // eax
  char *v21; // esi
  int v22; // ecx
  bool v23; // zf
  char *v24; // esi
  int v25; // ecx
  bool v26; // zf
  char *v27; // esi
  int v28; // ecx
  bool v29; // zf
  char *v30; // esi
  int v31; // ecx
  bool v32; // zf
  char *v33; // esi
  int v34; // ecx
  bool v35; // zf
  char *v36; // esi
  int v37; // ecx
  bool v38; // zf
  char *v39; // esi
  int v40; // ecx
  bool v41; // zf
  D3DXShader::CFragmentInfo *v42; // ecx
  unsigned __int8 *v43; // eax
  struct D3DXShader::CNode *result; // eax
  int v45; // eax
  unsigned __int8 *v46; // eax
  unsigned __int8 *v47; // eax
  int v48; // [esp+Ch] [ebp-48h]
  D3DXShader *v49; // [esp+10h] [ebp-44h]
  int v50; // [esp+14h] [ebp-40h]
  int v51; // [esp+18h] [ebp-3Ch]
  int v52; // [esp+1Ch] [ebp-38h]
  D3DXShader *v53; // [esp+20h] [ebp-34h]
  D3DXShader *v54; // [esp+24h] [ebp-30h]
  unsigned int v55; // [esp+28h] [ebp-2Ch] BYREF
  struct D3DXShader::D3DXTOKEN *v56; // [esp+2Ch] [ebp-28h]
  D3DXShader::CAssembler *v57; // [esp+30h] [ebp-24h]
  struct D3DXShader::CNode *v58; // [esp+34h] [ebp-20h]
  unsigned int v59; // [esp+38h] [ebp-1Ch] BYREF
  unsigned int v60; // [esp+3Ch] [ebp-18h] BYREF
  char nptr[16]; // [esp+40h] [ebp-14h] BYREF

  v3 = *((D3DXShader **)a2 + 2);
  v4 = a3;
  v5 = nullptr;
  v19 = *(_BYTE *)v3 == 0;
  v6 = this;
  v57 = this;
  v56 = a2;
  v58 = a3;
  v59 = 0;
  v60 = 0;
  v55 = 0;
  v51 = 0;
  v48 = 1;
  v50 = 0;
  v52 = 0;
  v53 = v3;
  v49 = v3;
  v54 = v3;
  if ( v19 )
  {
LABEL_2:
    v7 = *((_DWORD *)v6 + 30);
    if ( v7 == 0 )
      goto LABEL_152;
    if ( *(_DWORD *)(v7 + 176) != 0 )
    {
      if ( v59 != 3 && v59 != 15 && v59 != 18 && v59 != 19 )
      {
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)v6,
          a2: v56,
          a3: 0x7D5u,
          format: "temporary, constant, and output registers are not allowed in vs_3_0 assembly fragments");
        goto LABEL_149;
      }
      goto LABEL_152;
    }
    if ( v59 == 3 || v59 == 5 || v59 == 6 || v59 == 8 || v59 == 9 || v59 == 4 || v59 == 15 || v59 == 18 || v59 == 19 )
    {
LABEL_152:
      v47 = D3DXShader::CNode::operator new(a1: 0x2Cu);
      if ( v47 != nullptr )
        result = (struct D3DXShader::CNode *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
                                               this: (D3DXShader::CNodeAsmRegister *)v47,
                                               a2: v59,
                                               a3: v55,
                                               a4: v60,
                                               a5: v51,
                                               a6: nullptr);
      else
        result = nullptr;
      if ( result != nullptr )
      {
        if ( v4 != nullptr )
        {
          *((_DWORD *)result + 10) = *((_DWORD *)v4 + 10);
          *((_DWORD *)v4 + 10) = 0;
        }
        return result;
      }
      return nullptr;
    }
    D3DXShader::CTErrors::Error(
      this: *(D3DXShader::CTErrors **)v6,
      a2: v56,
      a3: 0x7D5u,
      format: "temporary and constant registers are not allowed in assembly fragments");
LABEL_149:
    *((_DWORD *)v6 + 19) = 1;
    v46 = D3DXShader::CNode::operator new(a1: 0x2Cu);
    if ( v46 != nullptr )
      return (struct D3DXShader::CNode *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
                                           this: (D3DXShader::CNodeAsmRegister *)v46,
                                           a2: 0xFFFFFFFF,
                                           a3: 0,
                                           a4: 0,
                                           a5: 0,
                                           a6: nullptr);
    return nullptr;
  }
  while ( 1 )
  {
    while ( *(_BYTE *)v3 != 0 && *(_BYTE *)v3 != 95 )
    {
      v3 = (D3DXShader *)((char *)v3 + 1);
      v54 = v3;
    }
    v8 = v3 - v49;
    if ( (unsigned int)(v3 - v49) > 0xF )
      break;
    qmemcpy(nptr, v49, v8);
    v19 = *(_BYTE *)v3 == 0;
    nptr[v8] = 0;
    if ( !v19 )
    {
      v3 = (D3DXShader *)((char *)v3 + 1);
      v54 = v3;
    }
    v5 = nullptr;
    v49 = v3;
    if ( v48 != 0 )
    {
      v9 = nptr;
      if ( nptr[0] == 0 )
        goto LABEL_21;
      do
      {
        if ( isalpha(c: *v9) == 0 )
          break;
        ++v9;
      }
      while ( *v9 != 0 );
      if ( *v9 != 0 )
        v60 = atoi(nptr: v9);
      else
LABEL_21:
        v60 = -1;
      if ( *v9 != 0 )
        *v9++ = 0;
      v10 = *v9;
      if ( *v9 != 0 )
      {
        do
        {
          if ( isdigit(c: v10) == 0 )
            break;
          v10 = *++v9;
        }
        while ( *v9 != 0 );
        if ( *v9 != 0 )
        {
LABEL_123:
          v6 = v57;
LABEL_124:
          v4 = v58;
          break;
        }
      }
      for ( i = 0; i < 378; i += 18 )
      {
        if ( strcmp(nptr, (&off_102B37E0)[i]) == 0 )
          break;
        ++v5;
      }
      v6 = v57;
      if ( v5 == (char *)21 )
        goto LABEL_124;
      v12 = *((_DWORD *)v57 + 14);
      v13 = dword_102B37E8[18 * (_DWORD)v5 + v12];
      if ( v13 == -1 )
        goto LABEL_124;
      v4 = v58;
      if ( v13 >= 0 )
      {
        if ( v58 != nullptr )
          break;
        v14 = v60;
      }
      else
      {
        v14 = v60;
        if ( v60 == -1 )
        {
          if ( v58 == nullptr )
            break;
          v14 = *((_DWORD *)v58 + 6);
LABEL_39:
          v60 = v14;
        }
        else if ( v58 != nullptr )
        {
          v14 = *((_DWORD *)v58 + 6) + v60;
          goto LABEL_39;
        }
        v13 = -v13;
      }
      if ( v14 == -1 )
      {
        if ( v13 != 0 )
          break;
        LOWORD(v14) = 0;
        v60 = 0;
      }
      else if ( (v58 == nullptr || *((_DWORD *)v58 + 10) == 0) && v14 >= v13 )
      {
        break;
      }
      v15 = 18 * (_DWORD)v5;
      v5 = (char *)dword_102B37E4[18 * (_DWORD)v5];
      v51 = dword_102B3824[v15];
      v59 = (unsigned int)v5;
      if ( v5 == (char *)2 )
      {
        v16 = v14 & 0x1FFF;
        if ( v16 >= 0x800 )
        {
          if ( v16 >= 0x1000 )
          {
            if ( v16 >= 0x1800 )
              v59 = 13;
            else
              v59 = 12;
          }
          else
          {
            v59 = 11;
          }
        }
        else
        {
          v59 = 2;
        }
        v60 = v16 & 0x7FF;
        goto LABEL_70;
      }
      if ( v5 == (char *)-3 )
      {
        v59 = 4;
        goto LABEL_60;
      }
      if ( v5 == (char *)-4 )
      {
        v59 = 4;
        v60 = 2;
        goto LABEL_70;
      }
      if ( v5 == (char *)-5 )
      {
        v59 = 4;
        goto LABEL_69;
      }
      if ( v5 == (char *)-6 )
      {
        v59 = 17;
LABEL_60:
        v60 = 0;
      }
      else if ( v5 == (char *)-7 )
      {
        v59 = 17;
LABEL_69:
        v60 = 1;
      }
LABEL_70:
      v48 = 0;
      if ( v12 >= 6 && v12 <= 9 )
        v50 = 1;
      if ( v12 >= 4 && v12 <= 5 || v12 >= 13 && v12 <= 14 )
        v52 = 1;
      v3 = v54;
      goto LABEL_79;
    }
    if ( v50 == 0 )
    {
LABEL_116:
      if ( v52 == 0 )
        goto LABEL_123;
      v5 = "abs";
      v39 = nptr;
      v40 = 4;
      v41 = true;
      do
      {
        if ( v40 == 0 )
          break;
        v41 = *v39++ == *v5++;
        --v40;
      }
      while ( v41 );
      if ( !v41 )
        goto LABEL_123;
      v52 = 0;
      v55 = 184549376;
      goto LABEL_122;
    }
    v5 = "bias";
    v17 = nptr;
    v18 = 5;
    v19 = true;
    do
    {
      if ( v18 == 0 )
        break;
      v19 = *v17++ == *v5++;
      --v18;
    }
    while ( v19 );
    if ( v19 )
    {
      v20 = 0x2000000;
    }
    else
    {
      v5 = "bx2";
      v21 = nptr;
      v22 = 4;
      v23 = true;
      do
      {
        if ( v22 == 0 )
          break;
        v23 = *v21++ == *v5++;
        --v22;
      }
      while ( v23 );
      if ( v23 )
      {
        v20 = 0x4000000;
      }
      else
      {
        v5 = "x2";
        v24 = nptr;
        v25 = 3;
        v26 = true;
        do
        {
          if ( v25 == 0 )
            break;
          v26 = *v24++ == *v5++;
          --v25;
        }
        while ( v26 );
        if ( v26 )
        {
          v20 = 117440512;
        }
        else
        {
          v5 = "dz";
          v27 = nptr;
          v28 = 3;
          v29 = true;
          do
          {
            if ( v28 == 0 )
              break;
            v29 = *v27++ == *v5++;
            --v28;
          }
          while ( v29 );
          if ( v29 )
            goto LABEL_101;
          v5 = "db";
          v30 = nptr;
          v31 = 3;
          v32 = true;
          do
          {
            if ( v31 == 0 )
              break;
            v32 = *v30++ == *v5++;
            --v31;
          }
          while ( v32 );
          if ( v32 )
          {
LABEL_101:
            v20 = 150994944;
          }
          else
          {
            v5 = "dw";
            v33 = nptr;
            v34 = 3;
            v35 = true;
            do
            {
              if ( v34 == 0 )
                break;
              v35 = *v33++ == *v5++;
              --v34;
            }
            while ( v35 );
            if ( !v35 )
            {
              v5 = "da";
              v36 = nptr;
              v37 = 3;
              v38 = true;
              do
              {
                if ( v37 == 0 )
                  break;
                v38 = *v36++ == *v5++;
                --v37;
              }
              while ( v38 );
              if ( !v38 )
                goto LABEL_116;
            }
            v20 = 167772160;
          }
        }
      }
    }
    v50 = 0;
    v55 = v20;
LABEL_122:
    v6 = v57;
    v4 = v58;
LABEL_79:
    if ( *(_BYTE *)v3 == 0 )
      goto LABEL_2;
  }
  v42 = *((D3DXShader::CFragmentInfo **)v6 + 30);
  if ( v42 == nullptr )
  {
    if ( v4 != nullptr )
    {
      v45 = *((_DWORD *)v4 + 10);
      if ( v45 != 0 )
      {
        if ( *(_DWORD *)(v45 + 16) != -1 )
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)v6,
            a2: v56,
            a3: 0x7D5u,
            format: "invalid register '%s[...]'",
            v53);
      }
      else
      {
        D3DXShader::CTErrors::Error(
          this: *(D3DXShader::CTErrors **)v6,
          a2: v56,
          a3: 0x7D5u,
          format: "invalid register '%s[%u]'",
          (const char *)v53,
          *((_DWORD *)v4 + 6));
      }
    }
    else
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)v6,
        a2: v56,
        a3: 0x7D5u,
        format: "invalid register '%s'",
        v53);
    }
    goto LABEL_149;
  }
  if ( D3DXShader::CFragmentInfo::GetRegisterInfo(
         this: v42,
         a2: (unsigned __int8 *)v5,
         a3: *(struct D3DXShader::CTErrors **)v6,
         a4: *((struct D3DXShader::CFragmentConstants **)v6 + 31),
         a5: v56,
         a6: v53,
         a7: v4,
         a8: &v59,
         a9: &v55,
         a10: &v60) < 0 )
    goto LABEL_149;
  v43 = D3DXShader::CNode::operator new(a1: 0x2Cu);
  if ( v43 != nullptr )
    result = (struct D3DXShader::CNode *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
                                           this: (D3DXShader::CNodeAsmRegister *)v43,
                                           a2: v59,
                                           a3: v55,
                                           a4: v60,
                                           a5: v51,
                                           a6: nullptr);
  else
    result = nullptr;
  if ( result == nullptr )
    return nullptr;
  if ( v4 != nullptr )
  {
    *((_DWORD *)result + 10) = *((_DWORD *)v4 + 10);
    *((_DWORD *)v4 + 10) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C7FBB
// Name: public: D3DXShader::CRegisterEntryNode::~CRegisterEntryNode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CRegisterEntryNode::~CRegisterEntryNode(void **this)
{
  D3DXShader::CRegisterEntryNode *v2; // ecx

  free(pMem: *this);
  v2 = (D3DXShader::CRegisterEntryNode *)*(this + 8);
  if ( v2 != nullptr )
    D3DXShader::CRegisterEntryNode::`scalar deleting destructor'(this: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101C7FD8
// Name: public: D3DXShader::CAssembler::~CAssembler(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CAssembler::~CAssembler(D3DXShader::CAssembler *this)
{
  int v2; // eax
  D3DXShader::CFragmentInfo *v3; // ecx

  v2 = *((_DWORD *)this + 2);
  if ( v2 != 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    *((_DWORD *)this + 2) = 0;
  }
  free(pMem: *((void **)this + 22));
  v3 = *((D3DXShader::CFragmentInfo **)this + 30);
  if ( v3 != nullptr )
    D3DXShader::CFragmentInfo::`scalar deleting destructor'(this: v3, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101C8007
// Name: protected: void D3DXShader::CAssembler::Production(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CAssembler::Production(D3DXShader::CAssembler *this, unsigned int a2, unsigned int a3)
{
  struct D3DXShader::CNode *v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  struct D3DXShader::D3DXTOKEN *v9; // eax
  struct D3DXShader::CNode *v10; // eax
  unsigned int v11; // ecx
  struct D3DXShader::CNode **v12; // edx
  struct D3DXShader::CNode **v13; // eax
  struct D3DXShader::CNode *v14; // ebx
  unsigned int v15; // ecx
  struct D3DXShader::CNode **v16; // edx
  struct D3DXShader::CNode **v17; // eax
  struct D3DXShader::CNode *v18; // ebx
  int v19; // eax
  int v20; // eax
  struct D3DXShader::CNode *v21; // eax
  struct D3DXShader::CNode *v22; // eax
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // eax
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  double v27; // st7
  double v28; // st7
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // eax
  int v32; // eax
  unsigned int v33; // [esp-Ch] [ebp-54h]
  const char *v34; // [esp-8h] [ebp-50h]
  struct D3DXShader::CNode *v35; // [esp+8h] [ebp-40h] BYREF
  struct D3DXShader::CNode *v36; // [esp+Ch] [ebp-3Ch]

  v4 = nullptr;
  if ( *((_DWORD *)this + 20) == 0 )
  {
    v5 = a3;
    if ( a3 != 0 )
    {
      while ( 1 )
      {
        v6 = *((_DWORD *)this + 13);
        --v5;
        if ( v6 == 0 )
          break;
        *(&v35 + v5) = *(struct D3DXShader::CNode **)(v6 + 8);
        *((_DWORD *)this + 13) = *(_DWORD *)(v6 + 12);
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 12) = 0;
        if ( v5 == 0 )
          goto LABEL_5;
      }
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (D3DXShader::CAssembler *)((char *)this + 16),
        a3: 0,
        format: "internal error: stack underflow");
      *((_DWORD *)this + 19) = 1;
    }
    else
    {
LABEL_5:
      switch ( a2 )
      {
        case 0u:
        case 6u:
          v4 = nullptr;
          break;
        case 1u:
        case 2u:
        case 4u:
        case 5u:
        case 0xAu:
        case 0x17u:
        case 0x19u:
        case 0x1Du:
        case 0x23u:
        case 0x29u:
        case 0x2Au:
        case 0x2Fu:
        case 0x30u:
          v4 = v35;
          break;
        case 3u:
          v4 = D3DXShader::CNode::Append(a1: v36, a2: v35);
          break;
        case 7u:
          v4 = nullptr;
          if ( *((_DWORD *)this + 29) == 0 )
            *((_DWORD *)this + 29) = *((_DWORD *)v35 + 6);
          break;
        case 8u:
          v4 = v35;
          goto LABEL_16;
        case 9u:
          v7 = *((_DWORD *)this + 14);
          v4 = v35;
          if ( v7 < 6 || v7 > 9 )
          {
            v34 = "instruction coissue is not supported in this shader version";
            v33 = 2027;
            goto LABEL_24;
          }
          *((_DWORD *)v35 + 21) = 1;
LABEL_16:
          D3DXShader::CAssembler::EmitInstruction(this, a2: v4);
          break;
        case 0xBu:
          v8 = *((_DWORD *)this + 14);
          v4 = v36;
          if ( v8 >= 2 && v8 <= 5 || v8 >= 11 && v8 <= 14 )
          {
            *((_DWORD *)v36 + 16) = v35;
            break;
          }
          v34 = "instruction predication is not supported in this shader version";
          v33 = 2028;
LABEL_24:
          v9 = (struct D3DXShader::CNode *)((char *)v4 + 16);
          goto LABEL_61;
        case 0xCu:
        case 0xDu:
        case 0xEu:
        case 0xFu:
        case 0x10u:
        case 0x11u:
        case 0x12u:
        case 0x13u:
        case 0x14u:
          v4 = v35;
          v35 = nullptr;
          if ( a3 > 1 )
          {
            v10 = v36;
            v36 = nullptr;
            *((_DWORD *)v4 + 15) = v10;
          }
          v11 = 2;
          if ( a3 > 2 )
          {
            v12 = (struct D3DXShader::CNode **)((char *)v4 + 68);
            do
            {
              v13 = &v35 + v11;
              v14 = *v13;
              *v13 = nullptr;
              *v12 = v14;
              ++v11;
              ++v12;
            }
            while ( v11 < a3 );
          }
          break;
        case 0x15u:
        case 0x16u:
          v4 = v35;
          v35 = nullptr;
          v15 = 1;
          if ( a3 > 1 )
          {
            v16 = (struct D3DXShader::CNode **)((char *)v4 + 68);
            do
            {
              v17 = &v35 + v15;
              v18 = *v17;
              *v17 = nullptr;
              *v16 = v18;
              ++v15;
              ++v16;
            }
            while ( v15 < a3 );
          }
          break;
        case 0x18u:
          v4 = v35;
          if ( *((_DWORD *)v35 + 7) != 0 )
          {
            D3DXShader::CTErrors::Error(
              this: *(D3DXShader::CTErrors **)this,
              a2: (D3DXShader::CAssembler *)((char *)this + 16),
              a3: 0x7E6u,
              format: "scalar registers cannot be masked");
            *((_DWORD *)this + 19) = 1;
            *((_DWORD *)v4 + 8) = 983040;
          }
          else
          {
            *((_DWORD *)v4 + 8) = D3DXShader::CAssembler::DecodeMask(
                                    (D3DXShader::CTErrors **)this,
                                    a2: (struct D3DXShader::CNode *)((char *)v36 + 16));
          }
          break;
        case 0x1Au:
          v4 = v35;
          if ( *((_DWORD *)v35 + 5) != 0 )
          {
            v34 = "not cannot be used with other modifiers";
            v33 = 2018;
            goto LABEL_60;
          }
          *((_DWORD *)v35 + 5) = 218103808;
          break;
        case 0x1Bu:
          v4 = v35;
          v19 = *((_DWORD *)v35 + 5);
          if ( v19 != 0 )
          {
            switch ( v19 )
            {
              case 33554432:
                *((_DWORD *)v35 + 5) = 50331648;
                break;
              case 67108864:
                *((_DWORD *)v35 + 5) = 83886080;
                break;
              case 117440512:
                *((_DWORD *)v35 + 5) = 0x8000000;
                break;
              case 150994944:
              case 167772160:
                v34 = "negate and divide modifiers cannot be combined";
                v33 = 2011;
                goto LABEL_60;
              case 184549376:
                *((_DWORD *)v35 + 5) = 201326592;
                break;
              default:
                break;
            }
          }
          else
          {
            *((_DWORD *)v35 + 5) = 0x1000000;
          }
          break;
        case 0x1Cu:
          v4 = v36;
          if ( *((_DWORD *)v35 + 6) != 1 )
          {
            v34 = "invalid complement expression";
            v33 = 2010;
            goto LABEL_60;
          }
          v20 = *((_DWORD *)this + 14);
          if ( v20 < 6 || v20 > 9 )
          {
            v34 = "complement is not supported in this shader version";
            v33 = 2029;
            goto LABEL_60;
          }
          if ( *((_DWORD *)v36 + 5) != 0 )
          {
            v34 = "complement cannot be used with other modifiers";
            v33 = 2012;
            goto LABEL_60;
          }
          *((_DWORD *)v36 + 5) = 100663296;
          break;
        case 0x1Eu:
          v4 = v35;
          if ( *((_DWORD *)v35 + 7) != 0 )
          {
            D3DXShader::CTErrors::Error(
              this: *(D3DXShader::CTErrors **)this,
              a2: (D3DXShader::CAssembler *)((char *)this + 16),
              a3: 0x7E6u,
              format: "scalar registers cannot be swizzled");
            *((_DWORD *)this + 19) = 1;
            *((_DWORD *)v4 + 9) = 14942208;
          }
          else
          {
            *((_DWORD *)v4 + 9) = D3DXShader::CAssembler::DecodeSwizzle(
                                    (D3DXShader::CTErrors **)this,
                                    a2: (struct D3DXShader::CNode *)((char *)v36 + 16));
          }
          break;
        case 0x21u:
          v21 = D3DXShader::CAssembler::DecodeRegister(
                  this,
                  a2: (struct D3DXShader::CNode *)((char *)v35 + 16),
                  a3: nullptr);
          goto LABEL_94;
        case 0x22u:
          v21 = D3DXShader::CAssembler::DecodeRegister(
                  this,
                  a2: (struct D3DXShader::CNode *)((char *)v35 + 16),
                  a3: v36);
          goto LABEL_94;
        case 0x24u:
          v22 = v36;
          v4 = v35;
          *((_DWORD *)v35 + 6) += *((_DWORD *)v36 + 6);
          if ( *((_DWORD *)v4 + 10) != 0 )
          {
            if ( *((_DWORD *)v22 + 10) != 0 )
            {
              v34 = "only one address register reference allowed in a relative address expression";
              v33 = 2009;
LABEL_60:
              v9 = (D3DXShader::CAssembler *)((char *)this + 16);
LABEL_61:
              D3DXShader::CTErrors::Error(this: *(D3DXShader::CTErrors **)this, a2: v9, a3: v33, format: v34);
              *((_DWORD *)this + 19) = 1;
            }
          }
          else
          {
            *((_DWORD *)v4 + 10) = *((_DWORD *)v22 + 10);
            *((_DWORD *)v22 + 10) = 0;
          }
          break;
        case 0x25u:
          v23 = D3DXShader::CNode::operator new(a1: 0x2Cu);
          v4 = nullptr;
          if ( v23 == nullptr )
            goto LABEL_98;
          v21 = (struct D3DXShader::CNode *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
                                              this: (D3DXShader::CNodeAsmRegister *)v23,
                                              a2: 0,
                                              a3: 0,
                                              a4: 0,
                                              a5: 0,
                                              a6: v35);
          goto LABEL_94;
        case 0x26u:
          v24 = D3DXShader::CNode::operator new(a1: 0x2Cu);
          v4 = nullptr;
          if ( v24 == nullptr )
            goto LABEL_98;
          v21 = (struct D3DXShader::CNode *)D3DXShader::CNodeAsmRegister::CNodeAsmRegister(
                                              this: (D3DXShader::CNodeAsmRegister *)v24,
                                              a2: 0,
                                              a3: 0,
                                              a4: *((_DWORD *)v35 + 6),
                                              a5: 0,
                                              a6: nullptr);
          goto LABEL_94;
        case 0x27u:
          v25 = D3DXShader::CNode::operator new(a1: 0x30u);
          if ( v25 != nullptr )
            v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                               this: (D3DXShader::CNodeToken *)v25,
                                               a2: (D3DXShader::CAssembler *)((char *)this + 16));
          else
            v4 = nullptr;
          D3DXShader::CAssembler::NonNull((D3DXShader::CTErrors **)this, a2: v4);
          *((_DWORD *)v4 + 4) = 2;
          *((_DWORD *)v4 + 6) = 1;
          break;
        case 0x28u:
          v26 = D3DXShader::CNode::operator new(a1: 0x30u);
          if ( v26 != nullptr )
            v4 = (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                               this: (D3DXShader::CNodeToken *)v26,
                                               a2: (D3DXShader::CAssembler *)((char *)this + 16));
          else
            v4 = nullptr;
          D3DXShader::CAssembler::NonNull((D3DXShader::CTErrors **)this, a2: v4);
          *((_DWORD *)v4 + 6) = 0;
          *((_DWORD *)v4 + 4) = 2;
          break;
        case 0x2Bu:
          v4 = v35;
          *((_DWORD *)v35 + 6) = -*((_DWORD *)v35 + 6);
          break;
        case 0x2Cu:
        case 0x2Du:
          v4 = v35;
          v27 = (double)*((unsigned int *)v35 + 6);
          *((_DWORD *)v35 + 4) = 5;
          goto LABEL_88;
        case 0x2Eu:
          v4 = v35;
          v28 = (double)*((unsigned int *)v35 + 6);
          *((_DWORD *)v35 + 4) = 5;
          goto LABEL_91;
        case 0x31u:
          v4 = v35;
          v28 = *((double *)v35 + 3);
LABEL_91:
          v27 = -v28;
LABEL_88:
          *((double *)v4 + 3) = v27;
          break;
        case 0x32u:
        case 0x33u:
        case 0x34u:
        case 0x35u:
        case 0x36u:
        case 0x37u:
        case 0x38u:
        case 0x39u:
        case 0x3Au:
        case 0x3Bu:
        case 0x3Cu:
          v29 = D3DXShader::CNode::operator new(a1: 0x60u);
          if ( v29 == nullptr )
            goto LABEL_97;
          v21 = (struct D3DXShader::CNode *)D3DXShader::CNodeAsmInstruction::CNodeAsmInstruction(
                                              this: (D3DXShader::CNodeAsmInstruction *)v29,
                                              a2: (D3DXShader::CAssembler *)((char *)this + 16),
                                              a3: *((_DWORD *)this + 16),
                                              a4: *((_DWORD *)this + 17),
                                              a5: *((_DWORD *)this + 18));
          goto LABEL_94;
        case 0x3Du:
        case 0x3Eu:
        case 0x3Fu:
          v30 = D3DXShader::CNode::operator new(a1: 0x30u);
          if ( v30 != nullptr )
          {
            v21 = (struct D3DXShader::CNode *)D3DXShader::CNodeToken::CNodeToken(
                                                this: (D3DXShader::CNodeToken *)v30,
                                                a2: (D3DXShader::CAssembler *)((char *)this + 16));
LABEL_94:
            v4 = v21;
          }
          else
          {
LABEL_97:
            v4 = nullptr;
          }
LABEL_98:
          D3DXShader::CAssembler::NonNull((D3DXShader::CTErrors **)this, a2: v4);
          break;
        default:
          break;
      }
      if ( *((_DWORD *)this + 20) == 0 )
      {
        v31 = D3DXShader::CNode::operator new(a1: 0x14u);
        if ( v31 != nullptr )
          v32 = D3DXShader::CNodeList::CNodeList(
                  this: (D3DXShader::CNodeList *)v31,
                  a2: v4,
                  a3: *((struct D3DXShader::CNode **)this + 13),
                  a4: "Stack");
        else
          v32 = 0;
        if ( v32 != 0 )
        {
          *((_DWORD *)this + 13) = v32;
        }
        else
        {
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (D3DXShader::CAssembler *)((char *)this + 16),
            a3: 0,
            format: "internal error: out of memory");
          *((_DWORD *)this + 20) = 1;
          *((_DWORD *)this + 19) = 1;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C85B4
// Name: int D3DXShader::d3dxasm_parse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::d3dxasm_parse()
{
  int v0; // esi
  int v1; // eax
  int v2; // ecx
  unsigned int v3; // ecx
  int v4; // ecx
  __int16 *v5; // eax
  unsigned int v6; // ecx
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  __int16 *v11; // eax
  int v12; // edx
  bool v13; // zf
  int v15; // esi
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  __int16 *i; // ecx
  unsigned int v21; // eax

  v0 = 0;
  D3DXShader::d3dxasm_nerrs = 0;
  D3DXShader::d3dxasm_errflag = 0;
  D3DXShader::d3dxasm_ssp = (__int16 *)&D3DXShader::d3dxasm_ss;
  D3DXShader::d3dxasm_vsp = (int *)&D3DXShader::d3dxasm_vs;
  LOWORD(D3DXShader::d3dxasm_ss) = 0;
  while ( 2 )
  {
    v1 = -1;
    D3DXShader::d3dxasm_char = -1;
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *((__int16 *)&D3DXShader::d3dxasm_defred + v0);
        if ( *((_WORD *)&D3DXShader::d3dxasm_defred + v0) == 0 )
          break;
LABEL_17:
        v8 = 2 * v2;
        v9 = *((__int16 *)&D3DXShader::d3dxasm_len + v2);
        D3DXShader::d3dxasm_val = D3DXShader::d3dxasm_vsp[-v9 + 1];
        switch ( v2 )
        {
          case 1:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0, a3: 0);
            break;
          case 2:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 1u, a3: 1u);
            break;
          case 3:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 2u, a3: 1u);
            break;
          case 4:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 3u, a3: 2u);
            break;
          case 5:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 4u, a3: 1u);
            break;
          case 6:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 5u, a3: 1u);
            break;
          case 7:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 6u, a3: 0);
            break;
          case 8:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 7u, a3: 1u);
            break;
          case 9:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 8u, a3: 1u);
            break;
          case 10:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 9u, a3: 1u);
            break;
          case 11:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xAu, a3: 1u);
            break;
          case 12:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xBu, a3: 2u);
            break;
          case 13:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xCu, a3: 1u);
            break;
          case 14:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xDu, a3: 2u);
            break;
          case 15:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xEu, a3: 3u);
            break;
          case 16:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0xFu, a3: 4u);
            break;
          case 17:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x10u, a3: 5u);
            break;
          case 18:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x11u, a3: 6u);
            break;
          case 19:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x12u, a3: 6u);
            break;
          case 20:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x13u, a3: 6u);
            break;
          case 21:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x14u, a3: 3u);
            break;
          case 22:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x15u, a3: 2u);
            break;
          case 23:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x16u, a3: 3u);
            break;
          case 24:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x17u, a3: 1u);
            break;
          case 25:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x18u, a3: 2u);
            break;
          case 26:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x19u, a3: 1u);
            break;
          case 27:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x1Au, a3: 1u);
            break;
          case 28:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x1Bu, a3: 1u);
            break;
          case 29:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x1Cu, a3: 2u);
            break;
          case 30:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x1Du, a3: 1u);
            break;
          case 31:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x1Eu, a3: 2u);
            break;
          case 32:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x21u, a3: 1u);
            break;
          case 33:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x22u, a3: 2u);
            break;
          case 34:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x23u, a3: 1u);
            break;
          case 35:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x24u, a3: 2u);
            break;
          case 36:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x25u, a3: 1u);
            break;
          case 37:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x26u, a3: 1u);
            break;
          case 38:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x27u, a3: 0);
            break;
          case 39:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x28u, a3: 0);
            break;
          case 40:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x29u, a3: 1u);
            break;
          case 41:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Au, a3: 1u);
            break;
          case 42:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Bu, a3: 1u);
            break;
          case 43:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Cu, a3: 1u);
            break;
          case 44:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Du, a3: 1u);
            break;
          case 45:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Eu, a3: 1u);
            break;
          case 46:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x2Fu, a3: 1u);
            break;
          case 47:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x30u, a3: 1u);
            break;
          case 48:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x31u, a3: 1u);
            break;
          case 49:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x32u, a3: 0);
            break;
          case 50:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x33u, a3: 0);
            break;
          case 51:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x34u, a3: 0);
            break;
          case 52:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x35u, a3: 0);
            break;
          case 53:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x36u, a3: 0);
            break;
          case 54:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x37u, a3: 0);
            break;
          case 55:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x38u, a3: 0);
            break;
          case 56:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x39u, a3: 0);
            break;
          case 57:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Au, a3: 0);
            break;
          case 58:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Bu, a3: 0);
            break;
          case 59:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Cu, a3: 0);
            break;
          case 60:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Du, a3: 0);
            break;
          case 61:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Eu, a3: 0);
            break;
          case 62:
            D3DXShader::CAssembler::Production(this: D3DXShader::CAssembler::s_pAsm, a2: 0x3Fu, a3: 0);
            break;
          default:
            break;
        }
        v10 = *(__int16 *)((char *)&D3DXShader::d3dxasm_lhs + v8);
        v11 = &D3DXShader::d3dxasm_ssp[-v9];
        D3DXShader::d3dxasm_ssp = v11;
        v12 = *v11;
        D3DXShader::d3dxasm_vsp -= v9;
        if ( v12 != 0 || v10 != 0 )
        {
          v15 = 2 * v10;
          v16 = *((__int16 *)&D3DXShader::d3dxasm_gindex + v10);
          if ( v16 != 0
            && (unsigned int)(v17 = v12 + v16) < 0x128
            && (v18 = 2 * v17, *(__int16 *)((char *)&D3DXShader::d3dxasm_check + v18) == v12) )
          {
            v0 = *(__int16 *)((char *)&D3DXShader::d3dxasm_table + v18);
          }
          else
          {
            v0 = *(__int16 *)((char *)&D3DXShader::d3dxasm_dgoto + v15);
          }
          if ( v11 >= &word_1035B19E )
            goto LABEL_108;
          D3DXShader::d3dxasm_ssp = v11 + 1;
          v11[1] = v0;
          v19 = D3DXShader::d3dxasm_val;
LABEL_105:
          *++D3DXShader::d3dxasm_vsp = v19;
          v1 = D3DXShader::d3dxasm_char;
        }
        else
        {
          D3DXShader::d3dxasm_ssp = v11 + 1;
          v0 = 16;
          v11[1] = 16;
          *++D3DXShader::d3dxasm_vsp = D3DXShader::d3dxasm_val;
          v1 = D3DXShader::d3dxasm_char;
          v13 = D3DXShader::d3dxasm_char == 0;
          if ( D3DXShader::d3dxasm_char < 0 )
          {
            v1 = D3DXShader::CAssembler::Token(this: D3DXShader::CAssembler::s_pAsm);
            v13 = v1 == 0;
            D3DXShader::d3dxasm_char = v1;
            if ( v1 < 0 )
            {
              v1 = 0;
              D3DXShader::d3dxasm_char = 0;
              v13 = true;
            }
          }
          if ( v13 )
            return 0;
        }
      }
      if ( v1 < 0 )
      {
        v1 = D3DXShader::CAssembler::Token(this: D3DXShader::CAssembler::s_pAsm);
        D3DXShader::d3dxasm_char = v1;
        if ( v1 < 0 )
        {
          v1 = 0;
          D3DXShader::d3dxasm_char = 0;
        }
      }
      if ( *((_WORD *)&D3DXShader::d3dxasm_sindex + v0) == 0 )
        break;
      v3 = v1 + *((__int16 *)&D3DXShader::d3dxasm_sindex + v0);
      if ( v3 >= 0x128 )
        break;
      v4 = 2 * v3;
      if ( *(__int16 *)((char *)&D3DXShader::d3dxasm_check + v4) != v1 )
        break;
      v5 = D3DXShader::d3dxasm_ssp;
      if ( D3DXShader::d3dxasm_ssp >= &word_1035B19E )
        goto LABEL_108;
      v0 = *(__int16 *)((char *)&D3DXShader::d3dxasm_table + v4);
      ++D3DXShader::d3dxasm_ssp;
      v5[1] = v0;
      *++D3DXShader::d3dxasm_vsp = D3DXShader::d3dxasm_lval;
      v1 = -1;
      D3DXShader::d3dxasm_char = -1;
      if ( D3DXShader::d3dxasm_errflag > 0 )
        --D3DXShader::d3dxasm_errflag;
    }
    if ( *((_WORD *)&D3DXShader::d3dxasm_rindex + v0) != 0 )
    {
      v6 = v1 + *((__int16 *)&D3DXShader::d3dxasm_rindex + v0);
      if ( v6 < 0x128 )
      {
        v7 = 2 * v6;
        if ( *(__int16 *)((char *)&D3DXShader::d3dxasm_check + v7) == v1 )
        {
          v2 = *(__int16 *)((char *)&D3DXShader::d3dxasm_table + v7);
          goto LABEL_17;
        }
      }
    }
    if ( D3DXShader::d3dxasm_errflag == 0 )
    {
      D3DXShader::CAssembler::Error(this: D3DXShader::CAssembler::s_pAsm, format: "syntax error");
      ++D3DXShader::d3dxasm_nerrs;
      v1 = D3DXShader::d3dxasm_char;
    }
    if ( D3DXShader::d3dxasm_errflag >= 3 )
    {
      if ( v1 == 0 )
        return 1;
      continue;
    }
    break;
  }
  D3DXShader::d3dxasm_errflag = 3;
  for ( i = D3DXShader::d3dxasm_ssp; ; D3DXShader::d3dxasm_ssp = i )
  {
    if ( *((_WORD *)&D3DXShader::d3dxasm_sindex + *i) != 0 )
    {
      v21 = *((__int16 *)&D3DXShader::d3dxasm_sindex + *i) + 256;
      if ( v21 < 0x128 && *((_WORD *)&D3DXShader::d3dxasm_check + v21) == 256 )
        break;
    }
    if ( i <= (__int16 *)&D3DXShader::d3dxasm_ss )
      return 1;
    --i;
    --D3DXShader::d3dxasm_vsp;
  }
  if ( i < &word_1035B19E )
  {
    v0 = *((__int16 *)&D3DXShader::d3dxasm_table + v21);
    D3DXShader::d3dxasm_ssp = i + 1;
    i[1] = v0;
    v19 = D3DXShader::d3dxasm_lval;
    goto LABEL_105;
  }
LABEL_108:
  D3DXShader::CAssembler::Error(this: D3DXShader::CAssembler::s_pAsm, format: "yacc stack overflow");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8B9B
// Name: public: long D3DXShader::CAssembler::Assemble(class D3DXShader::CPreProcessor __near *,unsigned long,class D3DXShader::CFragmentConstants __near *,struct ID3DXBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CAssembler::Assemble(
        D3DXShader::CAssembler *this,
        struct D3DXShader::CPreProcessor *a2,
        char *a3,
        struct D3DXShader::CFragmentConstants *a4,
        struct ID3DXBuffer **a5)
{
  int result; // eax
  D3DXShader::CFragmentInfo *v7; // ecx
  int v8; // eax
  int ShaderCode; // edi
  unsigned int v10; // eax
  struct D3DXShader::CFragmentConstants *v11; // eax
  D3DXShader::CFragmentInfo *v12; // eax
  D3DXShader::CFragmentInfo *v13; // eax
  int v14; // eax
  int v15; // eax
  HMODULE ModuleHandleA; // eax
  int (*Direct3DShaderValidatorCreate9)(void); // eax
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // eax
  _BYTE v22[4]; // [esp+4h] [ebp-10h] BYREF
  int v23; // [esp+8h] [ebp-Ch]
  char *v24; // [esp+10h] [ebp-4h] BYREF

  if ( ((unsigned int)a3 & 0xFFFFFF3C) != 0 )
    return -2005530516;
  if ( a5 == nullptr )
    return -2005530516;
  *a5 = nullptr;
  free(pMem: *((void **)this + 22));
  v7 = *((D3DXShader::CFragmentInfo **)this + 30);
  if ( v7 != nullptr )
    D3DXShader::CFragmentInfo::`scalar deleting destructor'(this: v7, a2: 1);
  D3DXShader::CAssembler::s_pAsm = this;
  *((_DWORD *)this + 14) = -1;
  *(_DWORD *)this = (char *)a2 + 24;
  *((_DWORD *)this + 15) = a3;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  D3DXShader::CPreProcessor::GetFileLine(this: a2, a2: (const char **)&v24, a3: nullptr);
  if ( v24 == nullptr )
    D3DXShader::CPreProcessor::GetBufferPointer(
      this: *((D3DXShader::CPreProcessor **)this + 1),
      a2: (const char **)this + 27,
      a3: (unsigned int *)this + 28);
  result = D3DXShader::CPreProcessor::Begin(this: *((D3DXShader::CPreProcessor **)this + 1), a2: 2u);
  if ( result >= 0 )
  {
    D3DXShader::CAssembler::Token(this);
    if ( *((_DWORD *)this + 4) == 9 && (int)D3DXGetTargetDescByName(a1: *((_DWORD *)this + 6), a2: 1, a3: v22) >= 0 )
    {
      v8 = v23;
      *((_DWORD *)this + 4) = 0;
      *((_DWORD *)this + 6) = v8;
    }
    if ( *((_DWORD *)this + 4) != 0 )
    {
      D3DXShader::CTErrors::Error(
        this: *(D3DXShader::CTErrors **)this,
        a2: (D3DXShader::CAssembler *)((char *)this + 16),
        a3: 0x7D1u,
        format: "shader version expected");
      goto LABEL_15;
    }
    if ( *((_DWORD *)this + 6) == -130816 )
    {
      D3DXShader::CTErrors::Warning(
        this: *(D3DXShader::CTErrors **)this,
        a2: (D3DXShader::CAssembler *)((char *)this + 16),
        a3: 0x7DFu,
        format: "vs_1_0 is no longer supported; using vs_1_1");
      *((_DWORD *)this + 6) = -130815;
    }
    if ( *((_DWORD *)this + 6) == -65280 )
    {
      D3DXShader::CTErrors::Warning(
        this: *(D3DXShader::CTErrors **)this,
        a2: (D3DXShader::CAssembler *)((char *)this + 16),
        a3: 0x7DFu,
        format: "ps_1_0 is no longer supported; using ps_1_1");
      *((_DWORD *)this + 6) = -65279;
    }
    if ( *((_DWORD *)this + 6) == -65022 )
      *((_DWORD *)this + 6) = -65023;
    if ( ((unsigned __int8)a3 & 0x40) != 0 && (*((_DWORD *)this + 6) & 0xFFFF0000) == 0xFFFE0000
      || (char)a3 < 0 && (*((_DWORD *)this + 6) & 0xFFFF0000) == 0xFFFF0000 )
    {
      *((_DWORD *)this + 15) |= 1u;
    }
    v10 = *((_DWORD *)this + 6);
    if ( v10 > 0xFFFF0102 )
    {
      switch ( v10 )
      {
        case 0xFFFF0103:
          *((_DWORD *)this + 14) = 8;
          break;
        case 0xFFFF0104:
          *((_DWORD *)this + 14) = 9;
          break;
        case 0xFFFF0200:
          *((_DWORD *)this + 14) = 10;
          break;
        case 0xFFFF0201:
          *((_DWORD *)this + 14) = 11;
          break;
        case 0xFFFF02FF:
          *((_DWORD *)this + 14) = 12;
          break;
        case 0xFFFF0300:
          *((_DWORD *)this + 14) = 13;
          break;
        case 0xFFFF03FF:
          *((_DWORD *)this + 14) = 14;
          break;
        default:
          goto LABEL_51;
      }
    }
    else
    {
      switch ( v10 )
      {
        case 0xFFFF0102:
          *((_DWORD *)this + 14) = 7;
          break;
        case 0xFFFE0101:
          *((_DWORD *)this + 14) = 0;
          break;
        case 0xFFFE0200:
          *((_DWORD *)this + 14) = 1;
          break;
        case 0xFFFE0201:
          *((_DWORD *)this + 14) = 2;
          break;
        case 0xFFFE02FF:
          *((_DWORD *)this + 14) = 3;
          break;
        case 0xFFFE0300:
          *((_DWORD *)this + 14) = 4;
          break;
        case 0xFFFE03FF:
          *((_DWORD *)this + 14) = 5;
          break;
        case 0xFFFF0101:
          *((_DWORD *)this + 14) = 6;
          break;
        default:
LABEL_51:
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (D3DXShader::CAssembler *)((char *)this + 16),
            a3: 0x7D2u,
            format: "unrecognized shader version");
          goto LABEL_15;
      }
    }
    v11 = a4;
    if ( a4 != nullptr )
    {
      *((_DWORD *)this + 15) |= 2u;
      *((_DWORD *)this + 31) = v11;
      v12 = (D3DXShader::CFragmentInfo *)MemAlloc_Alloc(nSize: 0xB8u);
      if ( v12 != nullptr )
        v13 = D3DXShader::CFragmentInfo::CFragmentInfo(this: v12, a2: *((_DWORD *)this + 14));
      else
        v13 = nullptr;
      *((_DWORD *)this + 30) = v13;
      if ( v13 == nullptr )
        return -2147024882;
      v14 = *((_DWORD *)this + 14);
      if ( (unsigned int)v14 > 5 )
      {
        if ( v14 < 10 || v14 > 14 )
        {
          D3DXShader::CTErrors::Error(
            this: *(D3DXShader::CTErrors **)this,
            a2: (D3DXShader::CAssembler *)((char *)this + 16),
            a3: 0x7D1u,
            format: "only vs_1_1, vs_2_0, vs_2_x, vs_2_sw, ps_2_0, ps_2_x, and ps_2_sw are supported for assembly fragments");
          goto LABEL_72;
        }
        v15 = *((unsigned __int8 *)this + 25) | 0x7FFF00;
      }
      else
      {
        v15 = *((unsigned __int8 *)this + 25) | 0x7FFE00;
      }
      *((_DWORD *)this + 6) = (unsigned __int8)*((_DWORD *)this + 6) | (v15 << 8);
    }
LABEL_72:
    if ( (*((_BYTE *)this + 60) & 2) == 0 )
    {
      ModuleHandleA = GetModuleHandleA(lpModuleName: "d3d9.dll");
      if ( ModuleHandleA != nullptr || (ModuleHandleA = LoadLibraryA(lpLibFileName: "d3d9.dll")) != nullptr )
      {
        Direct3DShaderValidatorCreate9 = GetProcAddress(
                                           hModule: ModuleHandleA,
                                           lpProcName: "Direct3DShaderValidatorCreate9");
        if ( Direct3DShaderValidatorCreate9 != nullptr )
        {
          v18 = Direct3DShaderValidatorCreate9();
          *((_DWORD *)this + 2) = v18;
          if ( v18 != 0 )
          {
            ShaderCode = (*(int (__stdcall **)(int, int (__stdcall *)(const char *, unsigned int, __int16, unsigned int, const char *, D3DXShader::CTErrors **), D3DXShader::CAssembler *, _DWORD))(*(_DWORD *)v18 + 12))(
                           a1: v18,
                           a2: D3DXShader::CAssembler::ValidationError,
                           a3: this,
                           a4: 0);
            if ( ShaderCode < 0 )
              goto LABEL_98;
          }
        }
      }
    }
    ShaderCode = D3DXShader::CAssembler::Emit(this, a2: *((_DWORD *)this + 6));
    if ( ShaderCode < 0 )
      goto LABEL_98;
    ShaderCode = D3DXShader::CAssembler::Validate(this, a2: (D3DXShader::CAssembler *)((char *)this + 16));
    if ( ShaderCode < 0 )
      goto LABEL_98;
    if ( *((_DWORD *)this + 19) == 0 )
    {
      if ( D3DXShader::d3dxasm_parse() != 0 )
        *((_DWORD *)this + 19) = 1;
      if ( *((_DWORD *)this + 19) == 0 )
      {
        if ( *((_DWORD *)this + 27) != 0 )
        {
          D3DXShader::CPreProcessor::GetBufferPointer(
            this: *((D3DXShader::CPreProcessor **)this + 1),
            a2: (const char **)&a3,
            a3: nullptr);
          v19 = *((_DWORD *)this + 27);
          if ( v19 < (unsigned int)a3 && v19 + *((_DWORD *)this + 28) > (unsigned int)a3 )
            *((_DWORD *)this + 28) = &a3[-v19];
        }
        if ( *((_DWORD *)this + 30) != 0 )
        {
          ShaderCode = D3DXShader::CAssembler::EmitFragmentInfo(this);
          if ( ShaderCode < 0 )
            goto LABEL_98;
        }
        if ( (*((_BYTE *)this + 60) & 1) != 0 )
        {
          ShaderCode = D3DXShader::CAssembler::EmitDebugInfo(this);
          if ( ShaderCode < 0 )
            goto LABEL_98;
        }
        ShaderCode = D3DXShader::CAssembler::Emit(this, a2: 0xFFFFu);
        if ( ShaderCode < 0 )
          goto LABEL_98;
        ShaderCode = D3DXShader::CAssembler::Validate(this, a2: (D3DXShader::CAssembler *)((char *)this + 16));
        if ( ShaderCode < 0 )
          goto LABEL_98;
        v20 = *((_DWORD *)this + 2);
        if ( v20 != 0 )
        {
          ShaderCode = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v20 + 20))(a1: *((_DWORD *)this + 2));
          if ( ShaderCode < 0 )
            goto LABEL_98;
        }
        if ( D3DXShader::CTErrors::GetErrorCount(this: *(D3DXShader::CTErrors **)this) == 0 )
        {
          ShaderCode = D3DXShader::CAssembler::GetShaderCode(this, a2: a5);
          if ( ShaderCode >= 0 )
          {
            ShaderCode = 0;
            goto LABEL_100;
          }
LABEL_98:
          *((_DWORD *)this + 19) = 1;
LABEL_100:
          v21 = *((_DWORD *)this + 2);
          if ( v21 != 0 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v21 + 8))(a1: *((_DWORD *)this + 2));
            *((_DWORD *)this + 2) = 0;
          }
          D3DXShader::CPreProcessor::End(this: *((D3DXShader::CPreProcessor **)this + 1));
          return ShaderCode;
        }
      }
    }
LABEL_15:
    ShaderCode = -2005529767;
    goto LABEL_98;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9053
// Name: public: D3DXShader::CCompiler::CCompiler(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CCompiler *__thiscall D3DXShader::CCompiler::CCompiler(D3DXShader::CCompiler *this)
{
  *((double *)this + 22) = 0.000001;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 2146435072;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = -1048576;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C90EE
// Name: protected: unsigned int __near * D3DXShader::CCompiler::Scratch(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__thiscall D3DXShader::CCompiler::Scratch(D3DXShader::CCompiler *this, unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int *result; // eax
  unsigned int *v6; // [esp+10h] [ebp+8h]

  v3 = *((_DWORD *)this + 37);
  if ( a2 <= v3 )
    return *((unsigned int **)this + 36);
  if ( v3 != 0 )
    v4 = 2 * v3;
  else
    v4 = 16;
  while ( v4 < a2 )
    v4 *= 2;
  result = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v4);
  v6 = result;
  if ( result != nullptr )
  {
    free(pMem: *((void **)this + 36));
    *((_DWORD *)this + 36) = v6;
    *((_DWORD *)this + 37) = v4;
    return *((unsigned int **)this + 36);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9151
// Name: protected: unsigned int __near * D3DXShader::CCompiler::StackAlloc(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__thiscall D3DXShader::CCompiler::StackAlloc(D3DXShader::CCompiler *this, unsigned int a2)
{
  unsigned int v3; // ebx
  int v4; // edi
  unsigned int *result; // eax

  v3 = a2 + 2;
  if ( *((_DWORD *)this + 35) >= a2 + 2 )
  {
    result = *((unsigned int **)this + 34);
    *result = (unsigned int)result;
    result[1] = *((_DWORD *)this + 35);
    goto LABEL_7;
  }
  v4 = a2 + 2;
  if ( v3 < 0x2000 )
    v4 = 0x2000;
  result = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v4);
  if ( result != nullptr )
  {
    *result = *((_DWORD *)this + 34);
    result[1] = -*((_DWORD *)this + 35);
    *((_DWORD *)this + 34) = result;
    *((_DWORD *)this + 35) = v4;
LABEL_7:
    *((_DWORD *)this + 35) -= v3;
    *((_DWORD *)this + 34) += 4 * v3;
    result += 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C91D2
// Name: protected: void D3DXShader::CCompiler::StackFree(unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CCompiler::StackFree(D3DXShader::CCompiler *this, unsigned int *a2)
{
  int v2; // eax

  if ( a2 != nullptr )
  {
    *((_DWORD *)this + 34) = *(a2 - 2);
    v2 = *(a2 - 1);
    if ( v2 <= 0 )
    {
      *((_DWORD *)this + 35) = -v2;
      free(pMem: a2 - 2);
    }
    else
    {
      *((_DWORD *)this + 35) = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C920B
// Name: protected: long D3DXShader::CCompiler::EmitTemp(unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitTemp(D3DXShader::CCompiler *this, unsigned int *a2, unsigned int a3)
{
  if ( a3 != 0 )
    memset(a2, 0xFFu, 4 * a3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C9227
// Name: protected: long D3DXShader::CCompiler::VectorizeBase(enum D3DXShader::_D3DXTYPE_TEMPLATE,unsigned int,unsigned int,unsigned long,unsigned int __near *,unsigned int,unsigned int __near *,class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::VectorizeBase(
        _DWORD *this,
        int a2,
        unsigned int a3,
        unsigned int a4,
        __int16 a5,
        unsigned int *a6,
        unsigned int a7,
        _DWORD *a8,
        int a9,
        int *a10)
{
  unsigned int v10; // eax
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ebx
  int v16; // edi
  int v17; // eax
  bool v19; // zf
  int v20; // esi
  unsigned int v21; // edi
  unsigned int v22; // eax
  int v23; // edx
  _DWORD *v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // ecx
  int v28; // [esp+8h] [ebp-20h]
  unsigned int i; // [esp+10h] [ebp-18h]
  int v30; // [esp+14h] [ebp-14h]
  int v32; // [esp+1Ch] [ebp-Ch]
  int v33; // [esp+20h] [ebp-8h]
  int v34; // [esp+24h] [ebp-4h]
  unsigned int *v35; // [esp+30h] [ebp+8h]
  unsigned int *v36; // [esp+3Ch] [ebp+14h]

  v10 = a3;
  v11 = a4;
  v12 = a4 * a3;
  v28 = a4 * a3;
  if ( a4 * a3 != 0 )
  {
    if ( a2 != 2 || (a5 & 0x400) != 0 )
    {
      v32 = 0;
    }
    else
    {
      a3 = a4;
      v32 = 1;
      a4 = v10;
      v11 = v10;
    }
    v13 = *(this + 2);
    v14 = a7;
    v15 = (v11 + 3) >> 2;
    v16 = a3 * v15;
    if ( a7 >= *(_DWORD *)(v13 + 4) )
      v17 = 0;
    else
      v17 = *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * a7);
    if ( v17 == 0 )
      return -2147467259;
    v19 = (*(_BYTE *)(v17 + 4) & 0x40) == 0;
    v30 = *(_DWORD *)(v17 + 16);
    v20 = v30;
    *(_DWORD *)(v17 + 16) = v30 + v16;
    if ( !v19 )
      *(_DWORD *)(v17 + 8) = v30 + v16;
    if ( a3 != 0 )
    {
      v33 = 0;
      v34 = 0;
      v36 = a6;
      for ( i = a3; i != 0; --i )
      {
        v21 = 0;
        if ( a4 != 0 )
        {
          v35 = v36;
          do
          {
            if ( v32 != 0 )
              v22 = *v35;
            else
              v22 = a6[v21 + v34];
            v23 = *(this + 2);
            if ( v22 >= *(_DWORD *)(v23 + 8) )
              v24 = nullptr;
            else
              v24 = *(_DWORD **)(*(_DWORD *)(v23 + 20) + 4 * v22);
            if ( v24 != nullptr )
            {
              v24[1] = v14;
              v25 = v33 + (v21 >> 2) + v20;
              v24[26] = a9;
              v26 = v21 & 3;
              v24[3] = v25;
              v24[4] = v26;
              v27 = v26 + *a8 + 4 * (v25 - v30);
              v20 = v30;
              v24[28] = v27;
              v14 = a7;
            }
            v35 += a3;
            ++v21;
          }
          while ( v21 < a4 );
        }
        ++v36;
        v34 += a4;
        v33 += v15;
      }
      v16 = a3 * v15;
    }
    v12 = v28;
    *a8 += 4 * v16;
  }
  if ( a10 != nullptr )
    *a10 = v12;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C9389
// Name: protected: long D3DXShader::CCompiler::VectorizeDefaults(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::VectorizeDefaults(D3DXShader::CCompiler *this, struct D3DXShader::CNode *a2)
{
  unsigned int v3; // edx
  D3DXShader::CCompiler *v4; // ebx
  int v5; // ecx
  unsigned int v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // ecx
  struct D3DXShader::CNode *v14; // [esp+18h] [ebp+8h]

  v3 = 0;
  v4 = this;
  if ( *((_DWORD *)a2 + 5) != 0 && *((_DWORD *)a2 + 10) != 0 && *((_DWORD *)a2 + 14) == 0 )
  {
    *((_DWORD *)a2 + 13) = 0;
    v5 = 4 * *((_DWORD *)a2 + 4);
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)v4 + 2) + 20) + 4 * *(_DWORD *)(v5 + *((_DWORD *)v4 + 6)))
                     + 112)
         + 1;
      if ( *((_DWORD *)a2 + 13) < v6 )
        *((_DWORD *)a2 + 13) = v6;
      ++v3;
      v5 += 4;
    }
    while ( v3 < *((_DWORD *)a2 + 5) );
    v7 = D3DXCore::CAlloc::Alloc(this: D3DXShader::CNode::s_pAlloc, a2: 4 * *((_DWORD *)a2 + 13), a3: 0x10u);
    *((_DWORD *)a2 + 14) = v7;
    if ( v7 == nullptr )
      return -2147024882;
    v8 = D3DXCore::CAlloc::Alloc(this: D3DXShader::CNode::s_pAlloc, a2: 4 * *((_DWORD *)a2 + 5), a3: 0x10u);
    *((_DWORD *)a2 + 15) = v8;
    if ( v8 == nullptr )
      return -2147024882;
    v14 = nullptr;
    memset(*((void **)a2 + 14), 0, 4 * *((_DWORD *)a2 + 13));
    memset(*((void **)a2 + 15), 0, 4 * *((_DWORD *)a2 + 5));
    v10 = *(_DWORD *)(*((_DWORD *)a2 + 10) + 32);
    if ( *((_DWORD *)a2 + 5) != 0 )
    {
      do
      {
        if ( v10 == 0 )
          break;
        v11 = *((_DWORD *)v4 + 2);
        v12 = *(_DWORD **)(*(_DWORD *)(v11 + 20)
                         + 4 * *(_DWORD *)(*((_DWORD *)v4 + 6) + 4 * ((_DWORD)v14 + *((_DWORD *)a2 + 4))));
        if ( *(char *)(*(_DWORD *)(*(_DWORD *)(v11 + 16) + 4 * v12[1]) + 4) >= 0 )
        {
          *(_DWORD *)(*((_DWORD *)a2 + 14) + 4 * v12[28]) = *(_DWORD *)(v10 + 8) + 16;
          v4 = this;
          *(_DWORD *)(*((_DWORD *)a2 + 15) + 4 * v12[25]) = *(_DWORD *)(v10 + 8) + 16;
        }
        v14 = (struct D3DXShader::CNode *)((char *)v14 + 1);
        v10 = *(_DWORD *)(v10 + 12);
      }
      while ( (unsigned int)v14 < *((_DWORD *)a2 + 5) );
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C94CC
// Name: protected: void D3DXShader::CCompiler::EvalRange_Mul(struct D3DXShader::_D3DXRANGE __near *,struct D3DXShader::_D3DXRANGE __near *,struct D3DXShader::_D3DXRANGE __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CCompiler::EvalRange_Mul(
        D3DXShader::CCompiler *this,
        struct D3DXShader::_D3DXRANGE *a2,
        struct D3DXShader::_D3DXRANGE *a3,
        struct D3DXShader::_D3DXRANGE *a4,
        char a5)
{
  int v5; // ebx
  long double *v6; // edi
  double *v7; // eax
  double v8[4]; // [esp+14h] [ebp-20h] BYREF

  v8[0] = *(double *)a3 * *(double *)a4;
  v5 = 0;
  v8[1] = *(double *)a3 * *((double *)a4 + 1);
  v8[2] = *(double *)a4 * *((double *)a3 + 1);
  v8[3] = *((double *)a3 + 1) * *((double *)a4 + 1);
  *(double *)a2 = *((double *)this + 20);
  *((double *)a2 + 1) = *((double *)this + 21);
  while ( 1 )
  {
    v6 = &v8[v5];
    if ( _isnan(x: *v6) != 0 )
      break;
LABEL_5:
    if ( *(double *)a2 > *v6 )
      *(long double *)a2 = *v6;
    if ( *((double *)a2 + 1) < *v6 )
      *((long double *)a2 + 1) = *v6;
    if ( (unsigned int)++v5 >= 4 )
      return;
  }
  if ( (a5 & 0x40) == 0 )
  {
    *v6 = 0.0;
    goto LABEL_5;
  }
  v7 = &v8[v5];
  *(double *)a2 = *v7;
  *((double *)a2 + 1) = *v7;
}

//------------------------------------------------------------------------------
// Address: 0x101C956F
// Name: protected: long D3DXShader::CCompiler::EvalRange(unsigned int,struct D3DXShader::_D3DXRANGE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EvalRange(
        D3DXShader::CCompiler *this,
        unsigned int a2,
        struct D3DXShader::_D3DXRANGE *a3)
{
  _DWORD *v4; // eax
  double *v5; // edi
  int v6; // ecx
  bool v7; // zf
  struct D3DXShader::_D3DXRANGE *v8; // eax
  double v9; // st7
  unsigned int v11; // ecx
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // edx
  int v16; // ecx
  int *v17; // esi
  int v18; // eax
  int v19; // ebx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  char *v22; // esi
  long double v23; // st7
  long double v24; // st7
  long double v25; // st7
  long double v26; // st6
  long double v27; // st7
  long double v28; // st7
  long double v29; // st7
  long double v30; // st6
  long double v31; // st7
  long double v32; // st7
  long double v33; // st7
  unsigned int v34; // esi
  long double v35; // st7
  long double v36; // st7
  long double v37; // st7
  unsigned int v38; // ecx
  int v39; // eax
  unsigned int v40; // ebx
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // ebx
  long double v45; // st6
  int v46; // ebx
  int v47; // ebx
  long double v48; // st7
  long double v49; // st7
  unsigned __int8 v51; // c0
  unsigned __int8 v52; // c3
  int v53; // esi
  long double v54; // st7
  long double v55; // [esp+14h] [ebp-54h] BYREF
  long double v56; // [esp+1Ch] [ebp-4Ch]
  long double v57; // [esp+24h] [ebp-44h] BYREF
  long double v58; // [esp+2Ch] [ebp-3Ch]
  long double v59; // [esp+34h] [ebp-34h] BYREF
  long double v60; // [esp+3Ch] [ebp-2Ch]
  long double x; // [esp+44h] [ebp-24h] BYREF
  long double v62; // [esp+4Ch] [ebp-1Ch] BYREF
  long double v63; // [esp+54h] [ebp-14h] BYREF
  long double v64; // [esp+5Ch] [ebp-Ch]
  D3DXShader::CCompiler *v65; // [esp+64h] [ebp-4h]
  unsigned int v66; // [esp+70h] [ebp+8h]
  unsigned int v67; // [esp+70h] [ebp+8h]
  unsigned int v68; // [esp+70h] [ebp+8h]

  v4 = *((_DWORD **)this + 2);
  v5 = *(double **)(v4[5] + 4 * a2);
  v6 = *(_DWORD *)v5;
  v7 = (*(_DWORD *)v5 & 0x100) == 0;
  v65 = this;
  if ( !v7 )
  {
    v8 = a3;
    if ( a3 != nullptr )
    {
      *(double *)a3 = v5[4];
      v9 = v5[5];
LABEL_7:
      *((double *)v8 + 1) = v9;
      return 0;
    }
    return 0;
  }
  if ( (v6 & 0x80u) != 0 )
  {
    v8 = a3;
    if ( a3 != nullptr )
    {
      *(double *)a3 = v5[4];
      v9 = v5[4];
      goto LABEL_7;
    }
    return 0;
  }
  v59 = *((double *)this + 21);
  v60 = *((double *)this + 20);
  v11 = *((_DWORD *)v5 + 2);
  if ( v11 == -1 )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v4[4] + 4 * *((_DWORD *)v5 + 1)) + 4) & 2) == 0 )
      goto LABEL_206;
    v16 = *((_DWORD *)v5 + 18);
    if ( v16 == -1 )
      goto LABEL_206;
    v17 = *(int **)(v4[6] + 4 * v16);
    v18 = *v17;
    v19 = *((_DWORD *)v5 + 4);
    v20 = *v17 & 0xF0000000;
    if ( v20 == 0x10000000 )
    {
      v21 = v18 & 0xFFF00000;
      if ( v21 == 284164096
        || v21 == 285212672
        || v21 == 286261248
        || v21 == 287309824
        || v21 == 288358400
        || v21 == 289406976
        || v21 == 290455552 )
      {
        goto LABEL_206;
      }
      if ( D3DXShader::CCompiler::EvalRange(
             this: v65,
             a2: *(_DWORD *)(v17[2] + 4 * v19),
             a3: (struct D3DXShader::_D3DXRANGE *)&x) < 0 )
        goto LABEL_193;
      v22 = (char *)(*v17 & 0xFFF00000);
      if ( (unsigned int)v22 <= 0x10700000 )
      {
        if ( v22 == (char *)275775488 )
        {
          if ( x < 0.0 )
            goto LABEL_206;
          v59 = 1.0 / sqrt(v62);
          v24 = 1.0 / sqrt(x);
          goto LABEL_205;
        }
        if ( v22 != (char *)0x10000000 )
        {
          if ( v22 == (char *)&loc_10100000 )
          {
            v59 = -v62;
            v24 = -x;
          }
          else
          {
            if ( v22 != (char *)&loc_101FFFFF + 1 )
            {
              if ( v22 == (char *)&unk_10300000 )
              {
                if ( x <= 0.0 && v62 >= 0.0 )
                  goto LABEL_206;
                v59 = 1.0 / v62;
                v24 = 1.0 / x;
                goto LABEL_205;
              }
              if ( v22 != (char *)272629760 )
              {
                if ( v22 != (char *)273678336 )
                {
                  if ( v22 == (char *)274726912 )
                  {
                    if ( x <= 0.0 )
                      v23 = *((double *)v65 + 21);
                    else
                      v23 = __FYL2X__(x, 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
                    v59 = v23;
                    if ( v62 <= 0.0 )
                      v24 = *((double *)v65 + 21);
                    else
                      v24 = __FYL2X__(v62, 0.6931471805599453094) / __FYL2X__(2.0, 0.6931471805599453094);
                    goto LABEL_205;
                  }
LABEL_206:
                  v53 = 0;
                  goto LABEL_207;
                }
                v59 = pow(2.0, x);
                v25 = 2.0;
                v26 = v62;
                goto LABEL_184;
              }
              if ( x == v62 )
              {
                if ( _finite(x) != 0 )
                {
                  v27 = x - floor(X: v62);
LABEL_200:
                  v60 = v27;
                  v59 = v27;
                  goto LABEL_206;
                }
                goto LABEL_75;
              }
              goto LABEL_109;
            }
            if ( x >= 0.0 )
            {
              if ( x == 0.0 )
                v28 = 0.0;
              else
                v28 = x + *((double *)v65 + 22);
            }
            else
            {
              v28 = x - *((double *)v65 + 22);
            }
            v59 = v28;
            if ( v62 >= 0.0 )
            {
              if ( v62 == 0.0 )
              {
LABEL_190:
                v24 = 0.0;
                goto LABEL_205;
              }
              v24 = v62 + *((double *)v65 + 22);
            }
            else
            {
              v24 = v62 - *((double *)v65 + 22);
            }
          }
LABEL_205:
          v60 = v24;
          goto LABEL_206;
        }
        goto LABEL_158;
      }
      if ( v22 != (char *)276824064 )
      {
        if ( v22 != (char *)277872640 )
        {
          if ( v22 == (char *)278921216 )
          {
            if ( x >= -1.0 && v62 <= 1.0 )
            {
              v59 = asin(x);
              v24 = asin(v62);
              goto LABEL_205;
            }
            goto LABEL_87;
          }
          if ( v22 != (char *)279969792 )
          {
            if ( v22 != (char *)281018368 )
            {
              if ( v22 != (char *)282066944 && v22 != (char *)283115520 || x != v62 || _finite(x) == 0 )
                goto LABEL_206;
              goto LABEL_75;
            }
            if ( x == v62 && _finite(x) != 0 )
            {
              v29 = x;
              v30 = 1.0;
LABEL_79:
              v27 = atan2(v29, v30);
              goto LABEL_200;
            }
LABEL_87:
            v59 = -1.570796370506287;
            v24 = 1.570796370506287;
            goto LABEL_205;
          }
          if ( x >= -1.0 && v62 <= 1.0 )
          {
            v59 = acos(v62);
            v24 = acos(x);
            goto LABEL_205;
          }
          v31 = 0.0;
LABEL_132:
          v59 = v31;
          v24 = 3.141592741012573;
          goto LABEL_205;
        }
        if ( x == v62 && _finite(x) != 0 )
        {
          v32 = x;
LABEL_202:
          v27 = cos(v32);
          goto LABEL_200;
        }
LABEL_203:
        v35 = -1.0;
        goto LABEL_204;
      }
      if ( x != v62 || _finite(x) == 0 )
        goto LABEL_203;
      v33 = x;
LABEL_199:
      v27 = sin(v33);
      goto LABEL_200;
    }
    if ( v20 != 0x20000000 )
    {
      v38 = v18 & 0xFFF00000;
      if ( (v18 & 0xFFF00000) == 0x50000000 )
      {
        v39 = v18 & 0xFFFFF;
        v59 = 0.0;
        HIDWORD(v64) = v39;
        v60 = 0.0;
        v40 = 0;
        if ( v39 != 0 )
        {
          v67 = 4 * v39;
          while ( D3DXShader::CCompiler::EvalRange(
                    this: v65,
                    a2: *(_DWORD *)(v17[2] + 4 * v40),
                    a3: (struct D3DXShader::_D3DXRANGE *)&x) >= 0
               && D3DXShader::CCompiler::EvalRange(
                    this: v65,
                    a2: *(_DWORD *)(v67 + v17[2]),
                    a3: (struct D3DXShader::_D3DXRANGE *)&v57) >= 0 )
          {
            D3DXShader::CCompiler::EvalRange_Mul(
              this: v65,
              a2: (struct D3DXShader::_D3DXRANGE *)&v55,
              a3: (struct D3DXShader::_D3DXRANGE *)&x,
              a4: (struct D3DXShader::_D3DXRANGE *)&v57,
              a5: *(_DWORD *)v5);
            v67 += 4;
            ++v40;
            v59 = v55 + v59;
            v60 = v56 + v60;
            if ( v40 >= HIDWORD(v64) )
              goto LABEL_206;
          }
          goto LABEL_193;
        }
        goto LABEL_206;
      }
      if ( v38 != 805306368 )
      {
        if ( v38 != 1343225856 )
        {
          if ( v38 != 1345323008 )
            goto LABEL_206;
          if ( D3DXShader::CCompiler::EvalRange(
                 this: v65,
                 a2: *(_DWORD *)v17[2],
                 a3: (struct D3DXShader::_D3DXRANGE *)&v57) < 0 )
            goto LABEL_193;
          if ( v57 != v58 || _finite(x: v57) == 0 )
            goto LABEL_203;
          if ( v19 == 0 )
          {
            v32 = v57;
            goto LABEL_202;
          }
          if ( v19 != 1 )
            goto LABEL_206;
          v33 = v57;
          goto LABEL_199;
        }
        if ( v19 != 0 )
        {
          v46 = v19 - 1;
          if ( v46 == 0 )
          {
            if ( D3DXShader::CCompiler::EvalRange(
                   this: v65,
                   a2: *(_DWORD *)v17[2],
                   a3: (struct D3DXShader::_D3DXRANGE *)&v57) < 0 )
              goto LABEL_193;
            if ( v57 <= 0.0 )
            {
              v59 = 0.0;
              if ( (v51 | v52) != 0 )
                goto LABEL_190;
            }
            else
            {
              v59 = v57;
            }
            v24 = v58;
            goto LABEL_205;
          }
          v47 = v46 - 1;
          if ( v47 == 0 )
          {
            if ( D3DXShader::CCompiler::EvalRange(
                   this: v65,
                   a2: *(_DWORD *)v17[2],
                   a3: (struct D3DXShader::_D3DXRANGE *)&v57) < 0 )
              goto LABEL_193;
            if ( v58 > 0.0 )
            {
              if ( D3DXShader::CCompiler::EvalRange(
                     this: v65,
                     a2: *(_DWORD *)(v17[2] + 4),
                     a3: (struct D3DXShader::_D3DXRANGE *)&x) < 0 )
                goto LABEL_193;
              if ( v62 > 0.0 )
              {
                if ( D3DXShader::CCompiler::EvalRange(
                       this: v65,
                       a2: *(_DWORD *)(v17[2] + 12),
                       a3: (struct D3DXShader::_D3DXRANGE *)&v55) < 0 )
                  goto LABEL_193;
                if ( x >= 1.0 )
                  v48 = v55;
                else
                  v48 = v56;
                v64 = v48;
                v59 = pow(x, v48);
                if ( v62 >= 1.0 )
                  v49 = v56;
                else
                  v49 = v55;
                v64 = v49;
                v25 = v62;
                v26 = v64;
LABEL_184:
                v24 = pow(v25, v26);
                goto LABEL_205;
              }
            }
            goto LABEL_75;
          }
          if ( v47 != 1 )
            goto LABEL_206;
        }
        goto LABEL_106;
      }
      v41 = v17[2];
      v68 = *(_DWORD *)(v41 + 4 * v19);
      v42 = v17[3];
      v43 = *(_DWORD *)(v41 + 4 * (v42 + v19));
      v44 = *(_DWORD *)(v41 + 4 * (v19 + 2 * v42));
      HIDWORD(v64) = v43;
      if ( D3DXShader::CCompiler::EvalRange(this: v65, a2: v68, a3: (struct D3DXShader::_D3DXRANGE *)&v55) < 0
        || D3DXShader::CCompiler::EvalRange(this: v65, a2: HIDWORD(v64), a3: (struct D3DXShader::_D3DXRANGE *)&x) < 0
        || D3DXShader::CCompiler::EvalRange(this: v65, a2: v44, a3: (struct D3DXShader::_D3DXRANGE *)&v57) < 0 )
      {
        goto LABEL_193;
      }
      if ( (*v17 & 0xFFF00000) != 0x30000000 )
        goto LABEL_206;
      if ( v68 == HIDWORD(v64) )
      {
        if ( x < 0.0 )
          x = 0.0;
        if ( v62 < 0.0 )
          v62 = 0.0;
      }
      if ( v68 == v44 )
      {
        if ( v57 > 0.0 )
          v57 = 0.0;
        v24 = v58;
        if ( v58 > 0.0 )
          v24 = 0.0;
      }
      else
      {
        v24 = v58;
      }
      if ( v55 >= 0.0 )
      {
LABEL_158:
        v59 = x;
        goto LABEL_165;
      }
      if ( v56 < 0.0 )
      {
        v59 = v57;
        goto LABEL_205;
      }
      if ( x >= v57 )
        v45 = v57;
      else
        v45 = x;
      v59 = v45;
      if ( v62 <= v24 )
        goto LABEL_205;
      goto LABEL_165;
    }
    if ( (v18 & 0xFFF00000) == 0x20900000 )
      goto LABEL_206;
    if ( D3DXShader::CCompiler::EvalRange(
           this: v65,
           a2: *(_DWORD *)(v17[2] + 4 * v19),
           a3: (struct D3DXShader::_D3DXRANGE *)&v63) < 0
      || D3DXShader::CCompiler::EvalRange(
           this: v65,
           a2: *(_DWORD *)(v17[2] + 4 * (v19 + v17[3])),
           a3: (struct D3DXShader::_D3DXRANGE *)&x) < 0 )
    {
      goto LABEL_193;
    }
    v34 = *v17 & 0xFFF00000;
    if ( v34 > 0x20400000 )
    {
      if ( v34 == 542113792 )
      {
        D3DXShader::CCompiler::EvalRange_Mul(
          this: v65,
          a2: (struct D3DXShader::_D3DXRANGE *)&v59,
          a3: (struct D3DXShader::_D3DXRANGE *)&v63,
          a4: (struct D3DXShader::_D3DXRANGE *)&x,
          a5: *(_DWORD *)v5);
        goto LABEL_206;
      }
      if ( v34 == 543162368 )
      {
        if ( v63 == v64 && _finite(x: v63) != 0 && x == v62 && _finite(x) != 0 )
        {
          v29 = v63;
          v30 = x;
          goto LABEL_79;
        }
        v31 = -3.141592741012573;
        goto LABEL_132;
      }
      if ( v34 != 544210944 && v34 != 545259520 )
        goto LABEL_206;
      if ( v63 < x )
      {
LABEL_111:
        v36 = v63;
        goto LABEL_124;
      }
    }
    else
    {
      if ( v34 == 541065216 )
      {
        v59 = x + v63;
        v24 = v62 + v64;
        goto LABEL_205;
      }
      if ( v34 == 0x20000000 )
      {
        if ( v63 >= x )
          v37 = x;
        else
          v37 = v63;
        v59 = v37;
        if ( v64 >= v62 )
          goto LABEL_165;
LABEL_125:
        v24 = v64;
        goto LABEL_205;
      }
      if ( v34 != 537919488 )
      {
        if ( v34 != 538968064 )
        {
          if ( v34 != 540016640 )
            goto LABEL_206;
          if ( v64 < x )
            goto LABEL_75;
          if ( v63 >= v62 )
            goto LABEL_106;
LABEL_109:
          v35 = 0.0;
          goto LABEL_204;
        }
        if ( v63 >= v62 )
        {
LABEL_75:
          v59 = 0.0;
          goto LABEL_190;
        }
        if ( v64 >= x )
          goto LABEL_109;
LABEL_106:
        v35 = 1.0;
LABEL_204:
        v59 = v35;
        v24 = 1.0;
        goto LABEL_205;
      }
      if ( v63 > x )
        goto LABEL_111;
    }
    v36 = x;
LABEL_124:
    v59 = v36;
    if ( v64 > v62 )
      goto LABEL_125;
LABEL_165:
    v24 = v62;
    goto LABEL_205;
  }
  if ( D3DXShader::CCompiler::EvalValue(this, a2: v11, a3: &v62) < 0 )
    goto LABEL_206;
  v12 = *((_DWORD *)this + 2);
  v13 = *((_DWORD *)v5 + 3) + (__int64)v62;
  v66 = 0;
  HIDWORD(v64) = *(_DWORD *)(v12 + 8);
  if ( HIDWORD(v64) == 0 )
    goto LABEL_206;
  v14 = *(_DWORD *)(v12 + 20);
  while ( 1 )
  {
    v15 = *(_DWORD **)v14;
    if ( *(_DWORD *)(*(_DWORD *)v14 + 4) == *((_DWORD *)v5 + 1)
      && v15[2] == -1
      && v15[3] == v13
      && v15[4] == *((_DWORD *)v5 + 4) )
    {
      break;
    }
    ++v66;
    v14 += 4;
    if ( v66 >= HIDWORD(v64) )
      goto LABEL_206;
  }
  if ( D3DXShader::CCompiler::EvalRange(this, a2: v66, a3: (struct D3DXShader::_D3DXRANGE *)&v59) >= 0 )
    goto LABEL_206;
LABEL_193:
  v53 = -2147467259;
  v59 = *((double *)v65 + 21);
  v60 = *((double *)v65 + 20);
LABEL_207:
  if ( (*(_DWORD *)v5 & 4) != 0 )
  {
    if ( v59 <= 0.0 )
      v59 = 0.0;
    if ( v60 <= 0.0 )
      v60 = 0.0;
  }
  else if ( v59 >= 0.0 )
  {
    *(_DWORD *)v5 |= 4u;
  }
  if ( (*(_DWORD *)v5 & 8) != 0 )
  {
    if ( v59 >= 0.0 )
      v59 = 0.0;
    if ( v60 >= 0.0 )
      v60 = 0.0;
  }
  else if ( v60 <= 0.0 )
  {
    *(_DWORD *)v5 |= 8u;
  }
  if ( (*(_DWORD *)v5 & 0x10) != 0 )
  {
    if ( v59 <= -1.0 )
      v59 = -1.0;
    if ( v60 <= -1.0 )
      v60 = -1.0;
    if ( v59 >= 1.0 )
      v59 = 1.0;
    if ( v60 >= 1.0 )
      v60 = 1.0;
  }
  else if ( v59 >= -1.0 && v60 <= 1.0 )
  {
    *(_DWORD *)v5 |= 0x10u;
  }
  if ( v59 == v60 && _finite(x: v59) != 0 )
  {
    *(_BYTE *)v5 |= 0x80u;
    if ( 0.0 == v59 || 1.0 == v59 )
      *(_DWORD *)v5 |= 1u;
    if ( fabs(v59 - (double)(int)(__int64)v59) < 0.000001 )
      *(_DWORD *)v5 |= 2u;
  }
  v5[4] = v59;
  v54 = v60;
  *((_BYTE *)v5 + 1) |= 1u;
  v5[5] = v54;
  if ( a3 != nullptr )
  {
    *(long double *)a3 = v59;
    *((long double *)a3 + 1) = v60;
  }
  return v53;
}

//------------------------------------------------------------------------------
// Address: 0x101CA239
// Name: protected: int D3DXShader::CCompiler::IsFullySemantic(unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::IsFullySemantic(D3DXShader::CCompiler *this, unsigned int *a2, unsigned int a3)
{
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax

  v3 = 0;
  if ( a3 == 0 )
    return 1;
  v4 = *((_DWORD *)this + 2);
  while ( 1 )
  {
    v5 = a2[v3];
    v6 = v5 >= *(_DWORD *)(v4 + 8) ? 0 : *(_DWORD *)(*(_DWORD *)(v4 + 20) + 4 * v5);
    if ( v6 == 0 || *(_DWORD *)(v6 + 104) == 0 )
      break;
    if ( ++v3 >= a3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CA27E
// Name: protected: int D3DXShader::CCompiler::IsRowMajor(unsigned int __near *,enum D3DXShader::_D3DXTYPE_TEMPLATE,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::IsRowMajor(_DWORD *this, _DWORD *a2, int a3, unsigned int a4, unsigned int a5)
{
  int result; // eax
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  int v9; // esi
  _DWORD *v10; // edx
  bool v11; // zf
  int v12; // eax
  _DWORD *v13; // ebx
  _DWORD *v14; // edx
  int v15; // edi
  _DWORD *v16; // esi
  bool v17; // zf
  int v18; // [esp+4h] [ebp-14h]
  int v19; // [esp+8h] [ebp-10h]
  unsigned int v20; // [esp+10h] [ebp-8h]
  unsigned int v21; // [esp+10h] [ebp-8h]
  _DWORD *v22; // [esp+14h] [ebp-4h]
  unsigned int v23; // [esp+20h] [ebp+8h]
  unsigned int v24; // [esp+24h] [ebp+Ch]
  _DWORD *v25; // [esp+24h] [ebp+Ch]

  if ( a3 != 2 )
    return a4 == 1;
  result = a5 * a4;
  if ( a5 * a4 != 0 )
  {
    v20 = 0;
    if ( a5 != 0 )
    {
      v6 = *(this + 2);
      v7 = a2;
      v19 = *(_DWORD *)(v6 + 20);
      v18 = *(_DWORD *)(v6 + 16);
      while ( 1 )
      {
        v8 = *(_DWORD **)(v19 + 4 * *v7);
        v9 = v8[1];
        v24 = 0;
        if ( a4 != 0 )
          break;
LABEL_15:
        ++v20;
        ++v7;
        if ( v20 >= a5 )
          goto LABEL_16;
      }
      v22 = v7;
      while ( 1 )
      {
        v10 = *(_DWORD **)(*(_DWORD *)(*(this + 2) + 20) + 4 * *v22);
        if ( v9 != v10[1] )
          return 1;
        if ( (*(_BYTE *)(*(_DWORD *)(v18 + 4 * v9) + 4) & 0x40) != 0 )
        {
          if ( v8[3] + (v24 >> 2) != v10[3] )
            return 1;
          v11 = v8[4] + (v24 & 3) == v10[4];
        }
        else
        {
          v11 = v8[18] == v10[18];
        }
        if ( !v11 )
          return 1;
        ++v24;
        v22 += a5;
        if ( v24 >= a4 )
          goto LABEL_15;
      }
    }
LABEL_16:
    v21 = 0;
    if ( a4 == 0 )
      return 1;
    v12 = *(this + 2);
    v13 = a2;
    while ( 1 )
    {
      v14 = *(_DWORD **)(*(_DWORD *)(v12 + 20) + 4 * *v13);
      v23 = 0;
      v15 = v14[1];
      if ( a5 != 0 )
        break;
LABEL_27:
      ++v21;
      v13 += a5;
      if ( v21 >= a4 )
        return 1;
    }
    v25 = v13;
    while ( 1 )
    {
      v16 = *(_DWORD **)(*(_DWORD *)(*(this + 2) + 20) + 4 * *v25);
      if ( v15 != v16[1] )
        return 0;
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * v15) + 4) & 0x40) != 0 )
      {
        if ( v14[3] + (v23 >> 2) != v16[3] )
          return 0;
        v17 = v14[4] + (v23 & 3) == v16[4];
      }
      else
      {
        v17 = v14[18] == v16[18];
      }
      if ( !v17 )
        return 0;
      ++v23;
      ++v25;
      if ( v23 >= a5 )
        goto LABEL_27;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CA412
// Name: protected: int D3DXShader::CCompiler::IsColumnMajor(unsigned int __near *,enum D3DXShader::_D3DXTYPE_TEMPLATE,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::IsColumnMajor(_DWORD *this, _DWORD *a2, int a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // esi
  int result; // eax
  int v7; // eax
  _DWORD *v8; // ebx
  _DWORD *v9; // edx
  int v10; // edi
  _DWORD *v11; // esi
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // edi
  _DWORD *v16; // eax
  int v17; // esi
  _DWORD *v18; // edx
  bool v19; // zf
  int v20; // [esp+4h] [ebp-14h]
  int v22; // [esp+Ch] [ebp-Ch]
  unsigned int v23; // [esp+10h] [ebp-8h]
  unsigned int v24; // [esp+10h] [ebp-8h]
  _DWORD *v25; // [esp+14h] [ebp-4h]
  unsigned int v26; // [esp+20h] [ebp+8h]
  unsigned int v27; // [esp+24h] [ebp+Ch]
  _DWORD *v28; // [esp+24h] [ebp+Ch]

  v5 = this;
  if ( a3 != 2 )
    return a4 > 1;
  result = a5 * a4;
  if ( a5 * a4 != 0 )
  {
    v23 = 0;
    if ( a4 != 0 )
    {
      v7 = *(this + 2);
      v8 = a2;
      while ( 1 )
      {
        v9 = *(_DWORD **)(*(_DWORD *)(v7 + 20) + 4 * *v8);
        v27 = 0;
        v10 = v9[1];
        if ( a5 != 0 )
          break;
LABEL_16:
        ++v23;
        v8 += a5;
        if ( v23 >= a4 )
          goto LABEL_17;
      }
      v22 = *(_DWORD *)(v5[2] + 20);
      v25 = v8;
      while ( 1 )
      {
        v11 = *(_DWORD **)(v22 + 4 * *v25);
        if ( v10 != v11[1] )
          return 1;
        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v7 + 16) + 4 * v10) + 4) & 0x40) != 0 )
        {
          if ( v9[3] + (v27 >> 2) != v11[3] )
            return 1;
          v12 = v9[4] + (v27 & 3) == v11[4];
        }
        else
        {
          v12 = v9[18] == v11[18];
        }
        if ( !v12 )
          return 1;
        ++v27;
        ++v25;
        if ( v27 >= a5 )
        {
          v5 = this;
          goto LABEL_16;
        }
      }
    }
LABEL_17:
    v24 = 0;
    if ( a5 == 0 )
      return 1;
    v13 = v5[2];
    v14 = *(_DWORD *)(v13 + 20);
    v15 = a2;
    v20 = *(_DWORD *)(v13 + 16);
    while ( 1 )
    {
      v16 = *(_DWORD **)(v14 + 4 * *v15);
      v26 = 0;
      v17 = v16[1];
      if ( a4 != 0 )
        break;
LABEL_28:
      ++v24;
      ++v15;
      if ( v24 >= a5 )
        return 1;
    }
    v28 = v15;
    while ( 1 )
    {
      v18 = *(_DWORD **)(*(_DWORD *)(*(this + 2) + 20) + 4 * *v28);
      if ( v17 != v18[1] )
        return 0;
      if ( (*(_BYTE *)(*(_DWORD *)(v20 + 4 * v17) + 4) & 0x40) != 0 )
      {
        if ( v16[3] + (v26 >> 2) != v18[3] )
          return 0;
        v19 = v16[4] + (v26 & 3) == v18[4];
      }
      else
      {
        v19 = v16[18] == v18[18];
      }
      if ( !v19 )
        return 0;
      ++v26;
      v28 += a5;
      if ( v26 >= a4 )
        goto LABEL_28;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CA5A8
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CCompiler::FindFunction(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CCompiler::FindFunction(D3DXShader::CCompiler *this, const char *a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // edi
  int v6; // eax
  unsigned int v7; // ecx
  _BYTE v9[4]; // [esp+4h] [ebp-18h] BYREF
  unsigned int v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  unsigned int v13; // [esp+18h] [ebp-4h]

  v11 = 0;
  v13 = -1;
  v3 = *((_DWORD *)this + 1);
  if ( v3 == 0 || *(_DWORD *)(v3 + 4) != 4 )
    return nullptr;
  for ( i = *(_DWORD *)(v3 + 28); i != 0; i = *(_DWORD *)(i + 12) )
  {
    v4 = *(_DWORD **)(i + 8);
    if ( v4 != nullptr && v4[1] == 6 && v4[4] == 2 && strcmp(*(const char **)(v4[5] + 24), a2) == 0 )
    {
      v5 = v4[6];
      if ( *(_DWORD *)(v5 + 60) != 0 && (*(_BYTE *)(v5 + 24) & 2) == 0 )
      {
        v6 = *(_DWORD *)(v5 + 28);
        v7 = 0;
        if ( v6 != 0 )
        {
          if ( (int)D3DXGetTargetDescByName(a1: *(_DWORD *)(v6 + 24), a2: 0, a3: v9) < 0 )
            v7 = -1;
          else
            v7 = v10;
        }
        if ( ((v7 & 0xFFFF0000) == 0 || (v7 & 0xFFFF0000) == (*((_DWORD *)this + 4) & 0xFFFF0000))
          && ((_WORD)v7 == 0 || (unsigned __int16)v7 == (unsigned __int16)*((_DWORD *)this + 4))
          && (v13 == -1 || v7 > v13) )
        {
          v11 = v5;
          v13 = v7;
        }
      }
    }
  }
  return (struct D3DXShader::CNode *)v11;
}

//------------------------------------------------------------------------------
// Address: 0x101CA6BE
// Name: protected: class D3DXShader::CNode __near * D3DXShader::CCompiler::FindFunction(class D3DXShader::CNode __near *,char const __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CCompiler::FindFunction(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        const char **a3)
{
  int v4; // eax
  _DWORD *v5; // esi
  struct D3DXShader::CNode *v6; // eax
  int v7; // edi
  int v8; // eax
  unsigned int v9; // ecx
  const char *v10; // eax
  _BYTE v12[4]; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v13; // [esp+8h] [ebp-18h]
  int v14; // [esp+10h] [ebp-10h]
  const char *v15; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned int v17; // [esp+1Ch] [ebp-4h]

  v14 = 0;
  v17 = -1;
  v15 = nullptr;
  v4 = *((_DWORD *)this + 1);
  if ( v4 == 0 || *(_DWORD *)(v4 + 4) != 4 )
    return nullptr;
  for ( i = *(_DWORD *)(v4 + 28); i != 0; i = *(_DWORD *)(i + 12) )
  {
    v5 = *(_DWORD **)(i + 8);
    if ( v5 != nullptr && v5[1] == 6 && v5[4] == 2 )
    {
      v6 = a2;
      if ( a2 != nullptr )
      {
        do
        {
          if ( v5[9] == *(_DWORD *)(*((_DWORD *)v6 + 2) + 24) )
            break;
          v6 = *((struct D3DXShader::CNode **)v6 + 3);
        }
        while ( v6 != nullptr );
        if ( v6 != nullptr )
        {
          v7 = v5[6];
          if ( *(_DWORD *)(v7 + 60) != 0 )
          {
            v8 = *(_DWORD *)(v7 + 28);
            v9 = 0;
            if ( v8 != 0 )
            {
              if ( (int)D3DXGetTargetDescByName(a1: *(_DWORD *)(v8 + 24), a2: 0, a3: v12) < 0 )
                v9 = -1;
              else
                v9 = v13;
            }
            if ( ((v9 & 0xFFFF0000) == 0 || (v9 & 0xFFFF0000) == (*((_DWORD *)this + 4) & 0xFFFF0000))
              && ((_WORD)v9 == 0 || (unsigned __int16)v9 == (unsigned __int16)*((_DWORD *)this + 4))
              && (v17 == -1 || v9 > v17) )
            {
              v10 = *(const char **)(v5[5] + 24);
              v14 = v7;
              v17 = v9;
              v15 = v10;
            }
          }
        }
      }
    }
  }
  if ( a3 != nullptr )
    *a3 = v15;
  return (struct D3DXShader::CNode *)v14;
}

//------------------------------------------------------------------------------
// Address: 0x101CA7FA
// Name: protected: long D3DXShader::CCompiler::PragmaDef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::PragmaDef(D3DXShader::CCompiler *this)
{
  unsigned int v2; // edi
  char *v3; // eax
  unsigned int v4; // esi
  int v5; // eax
  double *v6; // esi
  _BYTE v8[4]; // [esp+14h] [ebp-14h] BYREF
  int v9; // [esp+18h] [ebp-10h]
  char *dst; // [esp+20h] [ebp-8h]
  unsigned int v11; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)(*(_DWORD *)this + 60);
  do
  {
LABEL_18:
    if ( v2 == 0 )
      return 0;
    v3 = *(char **)(v2 + 4);
    v4 = 0;
    v11 = 0;
    dst = v3;
    do
    {
      if ( _stricmp(dst, src: *(const char **)(v2 + 4)) != 0 )
        break;
      if ( (int)D3DXGetTargetDescByName(a1: *(_DWORD *)v2, a2: 0, a3: v8) >= 0 )
      {
        v5 = *((_DWORD *)this + 4);
        if ( v5 == v9 )
        {
          if ( v4 == 0 )
            v4 = v2;
        }
        else if ( (v5 & 0xFFFF0000) == v9 && v11 == 0 )
        {
          v11 = v2;
        }
      }
      v2 = *(_DWORD *)(v2 + 40);
    }
    while ( v2 != 0 );
    if ( v4 != 0 )
      break;
    v4 = v11;
  }
  while ( v11 == 0 );
  dst = (char *)D3DXShader::CBaseProgram::AddPool(
                  this: *((D3DXShader::CBaseProgram **)this + 2),
                  a2: *(char **)(v4 + 4),
                  a3: 0xB51u,
                  a4: 1u,
                  a5: 4u);
  if ( dst != (char *)-1 )
  {
    v11 = 0;
    v6 = (double *)(v4 + 8);
    while ( D3DXShader::CBaseProgram::AddArgument(
              this: *((D3DXShader::CBaseProgram **)this + 2),
              a2: (unsigned int)dst,
              a3: 0,
              a4: v11,
              a5: *v6) != -1 )
    {
      ++v11;
      ++v6;
      if ( v11 >= 4 )
        goto LABEL_18;
    }
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x101CA8D4
// Name: protected: struct D3DXShader::D3DXTOKEN __near * D3DXShader::CCompiler::GetToken(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::D3DXTOKEN *__thiscall D3DXShader::CCompiler::GetToken(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::D3DXTOKEN *result; // eax

  if ( a2 == nullptr )
    return nullptr;
  if ( *((_DWORD *)a2 + 1) == 6 )
    return (struct D3DXShader::D3DXTOKEN *)(*((_DWORD *)a2 + 5) + 16);
  if ( *((_DWORD *)a2 + 1) == 11 )
    return nullptr;
  if ( *((_DWORD *)a2 + 1) != 12 )
  {
    if ( *((_DWORD *)a2 + 1) == 13 )
      return (struct D3DXShader::CNode *)((char *)a2 + 48);
    return nullptr;
  }
  result = D3DXShader::CCompiler::GetToken(this, a2: *((struct D3DXShader::CNode **)a2 + 5));
  if ( result == nullptr )
  {
    result = D3DXShader::CCompiler::GetToken(this, a2: *((struct D3DXShader::CNode **)a2 + 6));
    if ( result == nullptr )
    {
      result = D3DXShader::CCompiler::GetToken(this, a2: *((struct D3DXShader::CNode **)a2 + 7));
      if ( result == nullptr )
      {
        result = D3DXShader::CCompiler::GetToken(this, a2: *((struct D3DXShader::CNode **)a2 + 8));
        if ( result == nullptr )
          return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CA946
// Name: protected: long D3DXShader::CCompiler::Error(class D3DXShader::CNode __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CCompiler::Error(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        char *format,
        ...)
{
  struct D3DXShader::D3DXTOKEN *Token; // eax
  char string[256]; // [esp+4h] [ebp-104h] BYREF
  va_list ap; // [esp+120h] [ebp+18h] BYREF

  va_start(ap, format);
  *((_DWORD *)this + 19) = 1;
  _vsnprintf(string, count: 0x100u, format, ap);
  string[255] = 0;
  Token = D3DXShader::CCompiler::GetToken(this, a2);
  D3DXShader::CTErrors::Error(this: (D3DXShader::CTErrors *)(*(_DWORD *)this + 24), a2: Token, a3, format: "%s", string);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CA9B8
// Name: protected: long D3DXShader::CCompiler::Warning(class D3DXShader::CNode __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int D3DXShader::CCompiler::Warning(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        char *format,
        ...)
{
  struct D3DXShader::D3DXTOKEN *Token; // eax
  int v5; // edx
  char string[256]; // [esp+0h] [ebp-104h] BYREF
  va_list ap; // [esp+11Ch] [ebp+18h] BYREF

  va_start(ap, format);
  _vsnprintf(string, count: 0x100u, format, ap);
  string[255] = 0;
  Token = D3DXShader::CCompiler::GetToken(this, a2);
  D3DXShader::CTErrors::Warning(this: (D3DXShader::CTErrors *)(*(_DWORD *)v5 + 24), a2: Token, a3, format: "%s", string);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CAA21
// Name: protected: static int D3DXShader::CCompiler::CompareSemantic(unsigned int,unsigned int,void const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CCompiler::CompareSemantic(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v10; // edx
  unsigned int v11; // ecx

  v3 = a3[6];
  v4 = *(_DWORD *)(a3[2] + 20);
  v5 = *(_DWORD *)(v4 + 4 * *(_DWORD *)(v3 + 4 * a1));
  v6 = *(_DWORD *)(v4 + 4 * *(_DWORD *)(v3 + 4 * a2));
  v7 = *(_DWORD *)(v5 + 108);
  v8 = *(_DWORD *)(v6 + 108);
  if ( v7 < v8 )
    return -1;
  if ( v7 > v8 )
    return 1;
  v10 = *(_DWORD *)(v5 + 16);
  v11 = *(_DWORD *)(v6 + 16);
  if ( v10 < v11 )
    return -1;
  if ( v10 > v11 )
    return 1;
  if ( a2 > a1 )
    return -1;
  return a2 < a1;
}

//------------------------------------------------------------------------------
// Address: 0x101CAA78
// Name: public: D3DXShader::CCompiler::~CCompiler(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CCompiler::~CCompiler(D3DXShader::CCompiler *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 2);
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  free(pMem: *((void **)this + 6));
  free(pMem: *((void **)this + 34));
  free(pMem: *((void **)this + 36));
  free(pMem: *((void **)this + 38));
}

//------------------------------------------------------------------------------
// Address: 0x101CAAB8
// Name: protected: unsigned int D3DXShader::CCompiler::GetTypeFlags(class D3DXShader::CNode __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CCompiler::GetTypeFlags(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3)
{
  struct D3DXShader::CNode **v3; // esi
  unsigned int v4; // edi
  unsigned int v6; // ebx
  unsigned int v8; // eax
  unsigned int TypeFlags; // eax
  int v10; // [esp-8h] [ebp-14h]

  v3 = a2;
  v4 = 0;
  if ( a2 == nullptr )
    return 0;
  v6 = 0;
  if ( a2[1] == (struct D3DXShader::CNode *)1 )
  {
    do
    {
      if ( v3[1] != (struct D3DXShader::CNode *)1 )
        break;
      TypeFlags = D3DXShader::CCompiler::GetTypeFlags(this, a2: v3[2], a3: &a3[v6]);
      v3 = (struct D3DXShader::CNode **)v3[3];
      v6 += TypeFlags;
    }
    while ( v3 != nullptr );
    if ( v3 != nullptr )
      v6 += D3DXShader::CCompiler::GetTypeFlags(this, a2: (struct D3DXShader::CNode *)v3, a3: &a3[v6]);
    return v6;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)6 )
    return D3DXShader::CCompiler::GetTypeFlags(this, a2: a2[6], a3);
  if ( a2[1] == (struct D3DXShader::CNode *)8 )
  {
    if ( a2[5] != nullptr )
    {
      do
      {
        v6 += D3DXShader::CCompiler::GetTypeFlags(this, a2: a2[4], a3: &a3[v6]);
        ++v4;
      }
      while ( v4 < (unsigned int)a2[5] );
    }
    return v6;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)9 )
  {
    v6 = (_DWORD)a2[6] * (_DWORD)a2[7];
    v8 = 0;
    switch ( (unsigned int)a2[5] )
    {
      case 0u:
        v10 = 23;
        goto LABEL_14;
      case 1u:
      case 5u:
        v10 = 2;
LABEL_14:
        v8 = v10;
        break;
      case 2u:
      case 6u:
        v8 = 33554434;
        break;
      case 3u:
      case 7u:
        v8 = 67108866;
        break;
      case 4u:
      case 8u:
        v8 = 134217730;
        break;
      case 0xAu:
        v8 = 0x2000000;
        break;
      case 0xBu:
        v8 = 0x4000000;
        break;
      case 0xCu:
        v8 = 0x8000000;
        break;
      default:
        break;
    }
    if ( (*((_BYTE *)this + 20) & 0x20) != 0 )
      v8 = v8 & 0xF1FFFFFF | 0x2000000;
    if ( v6 != 0 )
      memset32(a3, v8, v6);
    return v6;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)11 )
    return D3DXShader::CCompiler::GetTypeFlags(this, a2: a2[8], a3);
  D3DXShader::CCompiler::Error(this, a2: nullptr, a3: 0, format: "internal error: unknown node");
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101CAC25
// Name: protected: long D3DXShader::CCompiler::VectorizeType(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int,int,int,class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::VectorizeType(
        D3DXShader::CBaseProgram **this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6,
        struct D3DXShader::CNode *a7,
        unsigned int *a8,
        unsigned int *a9)
{
  int v9; // ebx
  struct D3DXShader::CNode **v11; // esi
  int result; // eax
  int v13; // eax
  struct D3DXShader::CNode **i; // eax
  unsigned int *v15; // ebx
  int v16; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v17; // [esp+10h] [ebp-4h] BYREF

  v9 = 0;
  v17 = 0;
  v16 = 0;
  if ( a8 == nullptr )
    a8 = (unsigned int *)&v16;
  v11 = a2;
  if ( a2 == nullptr )
    goto LABEL_34;
  if ( a2[1] == (struct D3DXShader::CNode *)1 )
  {
    v15 = a3;
    result = D3DXShader::CCompiler::VectorizeType(
               (D3DXShader::CCompiler *)this,
               a2: a2[2],
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9: (unsigned int *)&a3);
    if ( result < 0 )
      return result;
    result = D3DXShader::CCompiler::VectorizeType(
               (D3DXShader::CCompiler *)this,
               a2: v11[3],
               a3: &v15[(_DWORD)a3],
               a4,
               a5,
               a6,
               a7,
               a8,
               a9: (unsigned int *)&a2);
    if ( result < 0 )
      return result;
    v17 = (unsigned int)a2 + (_DWORD)a3;
    goto LABEL_34;
  }
  if ( a2[1] == (struct D3DXShader::CNode *)6 )
  {
    result = D3DXShader::CCompiler::VectorizeType(
               (D3DXShader::CCompiler *)this,
               a2: a2[6],
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9: &v17);
    goto LABEL_11;
  }
  if ( a2[1] != (struct D3DXShader::CNode *)8 )
  {
    if ( a2[1] == (struct D3DXShader::CNode *)9 )
    {
      if ( a2[4] == (struct D3DXShader::CNode *)3 )
      {
        if ( a6 != 0 )
        {
          v13 = *(_DWORD *)(*((_DWORD *)*(this + 2) + 4) + 4 * a4);
          *(_BYTE *)(v13 + 4) |= 0x80u;
        }
        else
        {
          a4 = D3DXShader::CBaseProgram::AddPool(this: *(this + 2), a2: "s", a3: 0x2D1u, a4: 0xFFFFFFFF, a5: 4u);
        }
      }
      result = D3DXShader::CCompiler::VectorizeBase(
                 this,
                 a2: (int)v11[4],
                 a3: (unsigned int)v11[6],
                 a4: (unsigned int)v11[7],
                 a5: (__int16)v11[8],
                 a6: a3,
                 a7: a4,
                 a8,
                 a9: (int)a7,
                 a10: (int *)&v17);
    }
    else
    {
      if ( a2[1] != (struct D3DXShader::CNode *)11 )
      {
        D3DXShader::CCompiler::Error(
          (D3DXShader::CCompiler *)this,
          a2: nullptr,
          a3: 0,
          format: "internal error: unknown node");
LABEL_34:
        if ( a9 != nullptr )
          *a9 = v17;
        return 0;
      }
      result = D3DXShader::CCompiler::VectorizeVar(
                 (D3DXShader::CCompiler *)this,
                 a2: a2[8],
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9: a2[11],
                 a10: a2[12],
                 a11: &v17);
    }
LABEL_11:
    if ( result < 0 )
      return result;
    goto LABEL_34;
  }
  if ( a6 == 0 )
  {
    for ( i = a2; i != nullptr; i = (struct D3DXShader::CNode **)i[4] )
    {
      if ( i[1] != (struct D3DXShader::CNode *)8 )
        break;
    }
    if ( i != nullptr && i[1] == (struct D3DXShader::CNode *)9 && i[4] == (struct D3DXShader::CNode *)3 )
    {
      a4 = D3DXShader::CBaseProgram::AddPool(this: *(this + 2), a2: "s", a3: 0x2D1u, a4: 0xFFFFFFFF, a5: 4u);
      a6 = 1;
    }
  }
  if ( v11[5] == nullptr )
    goto LABEL_34;
  while ( 1 )
  {
    result = D3DXShader::CCompiler::VectorizeType(
               (D3DXShader::CCompiler *)this,
               a2: v11[4],
               a3: &a3[v17],
               a4,
               a5,
               a6,
               a7,
               a8,
               a9: (unsigned int *)&a2);
    if ( result < 0 )
      return result;
    v17 += (unsigned int)a2;
    if ( ++v9 >= (unsigned int)v11[5] )
      goto LABEL_34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CAE31
// Name: protected: long D3DXShader::CCompiler::EvalValue(unsigned int,double __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EvalValue(D3DXShader::CCompiler *this, unsigned int a2, double *a3)
{
  int v3; // esi
  double *v4; // eax
  double v5; // st7
  int result; // eax
  double x[2]; // [esp+Ch] [ebp-10h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a2);
  if ( *(char *)v3 >= 0 )
  {
    result = D3DXShader::CCompiler::EvalRange(this, a2, a3: (struct D3DXShader::_D3DXRANGE *)x);
    if ( result < 0 )
      return result;
    if ( x[0] == x[1] && _finite(x: x[0]) != 0 )
    {
      v4 = a3;
      if ( a3 != nullptr )
      {
        v5 = x[0];
        goto LABEL_10;
      }
      return 0;
    }
  }
  else if ( _finite(x: *(double *)(v3 + 32)) != 0 )
  {
    v4 = a3;
    if ( a3 != nullptr )
    {
      v5 = *(double *)(v3 + 32);
LABEL_10:
      *v4 = v5;
      return 0;
    }
    return 0;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101CAEB4
// Name: protected: long D3DXShader::CCompiler::Reset(unsigned int,unsigned int,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::Reset(
        D3DXShader::CCompiler *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4)
{
  int v5; // eax
  unsigned int i; // esi
  D3DXShader::CArgument *v7; // ecx
  int v8; // eax
  unsigned int j; // esi
  D3DXShader::CInstruction *v10; // ecx

  v5 = *((_DWORD *)this + 2);
  for ( i = a2; i < *(_DWORD *)(v5 + 8); ++i )
  {
    v7 = *(D3DXShader::CArgument **)(*(_DWORD *)(v5 + 20) + 4 * i);
    if ( v7 != nullptr )
      D3DXShader::CArgument::`scalar deleting destructor'(this: v7, a2: 1);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * i) = 0;
    v5 = *((_DWORD *)this + 2);
  }
  *(_DWORD *)(*((_DWORD *)this + 2) + 8) = a2;
  v8 = *((_DWORD *)this + 2);
  for ( j = a3; j < *(_DWORD *)(v8 + 12); ++j )
  {
    v10 = *(D3DXShader::CInstruction **)(*(_DWORD *)(v8 + 24) + 4 * j);
    if ( v10 != nullptr )
      D3DXShader::CInstruction::`scalar deleting destructor'(this: v10, a2: 1);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * j) = 0;
    v8 = *((_DWORD *)this + 2);
  }
  *(_DWORD *)(*((_DWORD *)this + 2) + 12) = a3;
  qmemcpy(*((void **)this + 6), a4, 4 * *(_DWORD *)(*((_DWORD *)this + 1) + 24));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CAF52
// Name: protected: long D3DXShader::CCompiler::EmitInst(class D3DXShader::CNode __near *,unsigned long,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitInst(
        char **this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int *a5,
        __int64 a6)
{
  unsigned int v6; // edx
  unsigned int v8; // eax
  unsigned int *v9; // esi
  unsigned int v10; // edi
  int result; // eax
  char *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // esi
  char *v15; // ecx
  unsigned int j; // eax
  _DWORD *v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // edi
  int v21; // eax
  int v22; // edi
  int v23; // esi
  unsigned int v24; // eax
  int v25; // ebx
  bool v26; // cf
  unsigned int *v27; // ebx
  unsigned int Inputs; // eax
  unsigned int *v29; // edi
  unsigned int v30; // edx
  void *v31; // esi
  unsigned int k; // edx
  unsigned int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // edi
  unsigned int v37; // eax
  int v38; // ecx
  unsigned int *v39; // eax
  unsigned int v40; // eax
  int v41; // ecx
  int *v42; // ecx
  int v43; // edx
  unsigned int m; // edi
  unsigned int v45; // edi
  bool v46; // zf
  unsigned int v47; // eax
  int v48; // edi
  void *v49; // eax
  int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  int v53; // eax
  _DWORD *v54; // ecx
  unsigned int v55; // eax
  int v56; // ecx
  int v57; // edx
  int v58; // eax
  int v59; // edx
  int v60; // ecx
  unsigned int *v61; // edi
  unsigned int v62; // edi
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  unsigned int *v67; // [esp+14h] [ebp-20h]
  unsigned int *v68; // [esp+18h] [ebp-1Ch]
  _DWORD *v69; // [esp+1Ch] [ebp-18h]
  int v70; // [esp+20h] [ebp-14h]
  double v71; // [esp+24h] [ebp-10h] BYREF
  void *pMem; // [esp+2Ch] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-4h]
  unsigned int v74; // [esp+40h] [ebp+Ch]
  char *v75; // [esp+40h] [ebp+Ch]
  unsigned int Outputs; // [esp+40h] [ebp+Ch]
  unsigned int *v77; // [esp+48h] [ebp+14h]
  unsigned int *v78; // [esp+48h] [ebp+14h]
  unsigned int *v79; // [esp+48h] [ebp+14h]
  unsigned int *n; // [esp+48h] [ebp+14h]
  unsigned int *v81; // [esp+48h] [ebp+14h]
  __int64 v82; // [esp+4Ch] [ebp+18h]
  unsigned int kk; // [esp+50h] [ebp+1Ch]
  unsigned int jj; // [esp+50h] [ebp+1Ch]
  unsigned int ii; // [esp+50h] [ebp+1Ch]
  _DWORD *v86; // [esp+50h] [ebp+1Ch]
  unsigned int mm; // [esp+50h] [ebp+1Ch]

  v6 = a3;
  pMem = this;
  if ( (a3 & 0xFFF00000) == 0x20500000 && (a6 & 0x400000000LL) != 0 )
  {
    v8 = a3 & 0xFFFFF;
    v74 = 0;
    if ( (v6 & 0xFFFFF) != 0 )
    {
      v9 = a5;
      v10 = a6 - (_DWORD)a5;
      for ( i = a6 - (_DWORD)a5; *v9 == *(unsigned int *)((char *)v9 + v10); v10 = i )
      {
        if ( (**(_BYTE **)(*((_DWORD *)*(this + 2) + 5) + 4 * *v9) & 1) == 0 )
          break;
        ++v74;
        ++v9;
        if ( v74 >= v8 )
          break;
      }
    }
    if ( v74 == v8 )
      v6 = v6 & 0xFFFFF | 0x10000000;
  }
  if ( v6 == 1342177281 )
  {
    result = D3DXShader::CCompiler::EmitInst(
               (D3DXShader::CCompiler *)this,
               a2,
               a3: 0x20500001u,
               a4,
               a5,
               (unsigned int *)a6,
               a7: HIDWORD(a6));
    goto LABEL_18;
  }
  if ( v6 != 1342177282 || ((*(this + 2))[108] & 0x20) != 0 )
  {
    v12 = *(this + 2);
    if ( v12[108] < 0 )
    {
      v13 = v6 & 0xFFF00000;
      HIDWORD(v71) = v6 & 0xFFF00000;
      if ( (v6 & 0xFFF00000) == 0x20000000 || v13 == 537919488 || v13 == 538968064 || v13 == 540016640 )
      {
        v14 = v6 & 0xFFFFF;
        v15 = (char *)MemAlloc_Alloc(nSize: 16 * (v6 & 0xFFFFF));
        pMem = v15;
        if ( v15 != nullptr )
        {
          for ( j = 0; j < 4; ++j )
          {
            (&v67)[j] = (unsigned int *)v15;
            v15 += 4 * v14;
          }
          if ( v14 == 0 )
          {
LABEL_40:
            v21 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v67, a3: v14);
            if ( v21 < 0
              || (v21 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v68, a3: v14)) < 0
              || (v22 = v14 & 0xFFFFF,
                  (v21 = D3DXShader::CCompiler::EmitInst(
                           (D3DXShader::CCompiler *)this,
                           a2,
                           a3: (unsigned int)&loc_10100000 | v14 & 0xFFFFF,
                           a4: v67,
                           a5: (unsigned int *)a6,
                           a6: nullptr,
                           a7: BYTE4(a6) & 0x40)) < 0)
              || (v21 = D3DXShader::CCompiler::EmitInst(
                          (D3DXShader::CCompiler *)this,
                          a2,
                          a3: v22 | 0x20400000,
                          a4: v68,
                          a5,
                          a6: v67,
                          a7: BYTE4(a6) & 0x40)) < 0
              || (v21 = D3DXShader::CCompiler::EmitInst(
                          (D3DXShader::CCompiler *)this,
                          a2,
                          a3: v22 | 0x30000000,
                          a4,
                          a5: v68,
                          a6: (unsigned int *)pMem + 2 * v14,
                          a7: HIDWORD(a6))) < 0 )
            {
              v23 = v21;
            }
            else
            {
              v23 = 0;
            }
            free(pMem);
            return v23;
          }
          v17 = v69;
          v75 = (char *)((char *)a5 - (char *)v69);
          v18 = a6 - (_DWORD)v69;
          v19 = v70 - (_DWORD)v69;
          i = v14;
          while ( 1 )
          {
            if ( HIDWORD(v71) == 0x20000000 )
            {
              *v17 = *(_DWORD *)((char *)v17 + v18);
              v20 = *(_DWORD *)((char *)v17 + (_DWORD)v75);
              goto LABEL_38;
            }
            if ( HIDWORD(v71) == 537919488 )
            {
              *v17 = *(_DWORD *)((char *)v17 + (_DWORD)v75);
              v20 = *(_DWORD *)((char *)v17 + v18);
              goto LABEL_38;
            }
            if ( HIDWORD(v71) == 538968064 )
              break;
            if ( HIDWORD(v71) == 540016640 )
            {
              *v17 = *(this + 8);
              v20 = (int)*(this + 9);
LABEL_38:
              *(_DWORD *)((char *)v17 + v19) = v20;
            }
            ++v17;
            if ( --i == 0 )
              goto LABEL_40;
          }
          *v17 = *(this + 9);
          v20 = (int)*(this + 8);
          goto LABEL_38;
        }
        return -2147024882;
      }
    }
    v24 = D3DXShader::CBaseProgram::AddInstruction(
            this: (D3DXShader::CBaseProgram *)v12,
            a2: v6,
            a3: 0xFFFFFFFF,
            a4: 0xFFFFFFFF);
    v25 = (int)*(this + 2);
    v26 = v24 < *(_DWORD *)(v25 + 12);
    i = v24;
    if ( v26 )
      v27 = *(unsigned int **)(*(_DWORD *)(v25 + 24) + 4 * v24);
    else
      v27 = nullptr;
    if ( v27 == nullptr )
      return -2147024882;
    if ( v27[3] == 0 && v27[1] == 0 )
    {
      *v27 = 0;
      return 0;
    }
    Outputs = D3DXShader::CInstruction::GetOutputs(this: (D3DXShader::CInstruction *)v27, a2: 0, a3: nullptr);
    Inputs = D3DXShader::CInstruction::GetInputs(this: (D3DXShader::CInstruction *)v27, a2: 0, a3: nullptr);
    v29 = (unsigned int *)v27[2];
    v30 = v27[1] - Inputs;
    HIDWORD(v71) = 4 * Inputs;
    qmemcpy(v29, a5, 4 * ((4 * Inputs) >> 2));
    qmemcpy((void *)(4 * Inputs + v27[2]), (const void *)a6, 4 * v30);
    v31 = pMem;
    for ( k = 0; k < v27[1]; ++k )
    {
      v33 = *(_DWORD *)(v27[2] + 4 * k);
      v34 = *((_DWORD *)v31 + 2);
      if ( v33 >= *(_DWORD *)(v34 + 8) )
        v35 = 0;
      else
        v35 = *(_DWORD *)(*(_DWORD *)(v34 + 20) + 4 * v33);
      if ( v35 != 0 )
        ++*(_DWORD *)(v35 + 92);
    }
    v36 = 0;
    LODWORD(a6) = 0;
    if ( Outputs != 0 )
    {
      while ( 1 )
      {
        v77 = nullptr;
        if ( a4 != nullptr )
        {
          v37 = a4[v36];
          if ( v37 != -1 )
          {
            v38 = *((_DWORD *)v31 + 2);
            v39 = v37 >= *(_DWORD *)(v38 + 8) ? nullptr : *(unsigned int **)(*(_DWORD *)(v38 + 20) + 4 * v37);
            v77 = v39;
            if ( v39 == nullptr )
              break;
          }
        }
        v40 = D3DXShader::CBaseProgram::AddArgument(
                this: *((D3DXShader::CBaseProgram **)v31 + 2),
                a2: *(_DWORD *)(*((_DWORD *)v31 + 2) + 136),
                a3: 0,
                a4: 0,
                a5: 0.0);
        HIDWORD(v71) = v40;
        if ( v40 == -1 )
          return -2147024882;
        v41 = *((_DWORD *)v31 + 2);
        v42 = v40 >= *(_DWORD *)(v41 + 8) ? nullptr : *(int **)(*(_DWORD *)(v41 + 20) + 4 * v40);
        if ( v42 == nullptr )
          return -2147024882;
        *v42 = HIDWORD(a6);
        v42[18] = i;
        v42[4] = v36;
        if ( (a6 & 0xE00000000000000LL) == 0 )
        {
          v36 = a6;
          *v42 = HIDWORD(a6) | *((_DWORD *)v31 + 25);
        }
        v42[5] = *((_DWORD *)v31 + 12);
        v42[6] = *((_DWORD *)v31 + 13);
        v43 = v36;
        *(_DWORD *)(4 * v36 + v27[4]) = v40;
        if ( a4 != nullptr )
          a4[v43] = v40;
        if ( v77 != nullptr )
        {
          v42[12] = v77[12];
          v42[24] = v77[24];
          v42[25] = v77[25];
        }
        if ( v42[12] != -1 )
        {
          *(_DWORD *)(*((_DWORD *)v31 + 6) + 4 * v42[12]) = *(_DWORD *)(v43 * 4 + v27[4]);
          if ( v42[24] == 0 )
            D3DXShader::CCompiler::Error(
              this: (D3DXShader::CCompiler *)v31,
              a2: nullptr,
              a3: 0,
              format: "internal error: argument missing context (A%u)",
              HIDWORD(v71));
        }
        v36 = a6 + 1;
        LODWORD(a6) = a6 + 1;
        if ( (unsigned int)a6 >= Outputs )
          goto LABEL_84;
      }
      D3DXShader::CCompiler::Error(
        this: (D3DXShader::CCompiler *)v31,
        a2: nullptr,
        a3: 0,
        format: "internal error: result register invalid");
      return -2147467259;
    }
LABEL_84:
    for ( m = 0; m < Outputs; ++m )
      D3DXShader::CCompiler::EvalRange(this: (D3DXShader::CCompiler *)v31, a2: *(_DWORD *)(v27[4] + 4 * m), a3: nullptr);
    if ( (*((_BYTE *)v31 + 20) & 4) == 0
      && D3DXShader::CInstruction::IsFlowControl(this: (D3DXShader::CInstruction *)v27) == 0 )
    {
      v45 = 0;
      v46 = Outputs == 0;
      if ( Outputs != 0 )
      {
        do
        {
          v47 = *(_DWORD *)(v27[4] + 4 * v45);
          if ( (**(_BYTE **)(*(_DWORD *)(*((_DWORD *)v31 + 2) + 20) + 4 * v47) & 0x40) != 0 )
            break;
          if ( D3DXShader::CCompiler::EvalValue(this: (D3DXShader::CCompiler *)v31, a2: v47, a3: &v71) < 0 )
            break;
          ++v45;
        }
        while ( v45 < Outputs );
        v46 = v45 == Outputs;
      }
      if ( v46 )
      {
        *v27 = Outputs & 0xFFFFF | 0x10000000;
        v48 = 0;
        v27[1] = v27[3];
        if ( Outputs != 0 )
        {
          do
          {
            *(_DWORD *)(v27[2] + 4 * v48) = D3DXShader::CBaseProgram::AddArgument(
                                              this: *((D3DXShader::CBaseProgram **)v31 + 2),
                                              a2: *(_DWORD *)(*((_DWORD *)v31 + 2) + 120),
                                              a3: 0,
                                              a4: 0,
                                              a5: *(double *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)v31 + 2) + 20)
                                                                    + 4 * *(_DWORD *)(v27[4] + 4 * v48))
                                                        + 32));
            if ( *(_DWORD *)(v27[2] + 4 * v48) == -1 )
              return -2147024882;
          }
          while ( ++v48 < Outputs );
        }
      }
    }
    v49 = (void *)(*v27 & 0xFFF00000);
    if ( (unsigned int)v49 > 0x20500000 )
    {
      if ( v49 != (void *)544210944 && v49 != (void *)545259520 )
      {
        if ( v49 == (void *)805306368 )
        {
          v62 = 0;
          for ( n = nullptr; v62 < Outputs; n = (unsigned int *)v62 )
          {
            v63 = *(_DWORD *)(*((_DWORD *)v31 + 2) + 20);
            v86 = *(_DWORD **)(v63 + 4 * *(_DWORD *)(v27[4] + 4 * v62));
            v64 = **(_DWORD **)(v63 + 4 * *(_DWORD *)(v27[2] + 4 * (v27[3] + v62)))
                & **(_DWORD **)(v63 + 4 * *(_DWORD *)(v27[2] + 4 * ((_DWORD)n + 2 * v27[3])));
            if ( (v64 & 1) != 0 )
            {
              *v86 |= 0x17u;
            }
            else if ( (v64 & 2) != 0 )
            {
              *v86 |= 2u;
            }
            v62 = (unsigned int)n + 1;
          }
        }
        else if ( v49 == (void *)1342177280 )
        {
          v82 = *(unsigned int *)(*(_DWORD *)(*((_DWORD *)v31 + 2) + 20) + 4 * *(_DWORD *)v27[4]);
          if ( Outputs != 0 )
          {
            v79 = (unsigned int *)v27[2];
            v61 = &v79[v27[3]];
            do
            {
              if ( (**(_BYTE **)(*(_DWORD *)(*((_DWORD *)v31 + 2) + 20) + 4 * *v61)
                  & **(_BYTE **)(*(_DWORD *)(*((_DWORD *)v31 + 2) + 20) + 4 * *v79)
                  & 2) == 0 )
                break;
              ++HIDWORD(v82);
              ++v79;
              ++v61;
            }
            while ( HIDWORD(v82) < Outputs );
          }
          if ( HIDWORD(v82) == Outputs )
            *(_DWORD *)v82 |= 2u;
        }
        goto LABEL_138;
      }
    }
    else if ( v49 != (void *)542113792 )
    {
      if ( v49 == (void *)0x10000000 )
      {
        v55 = 0;
        for ( ii = 0; ii < Outputs; ++ii )
        {
          v56 = *(_DWORD *)(*((_DWORD *)v31 + 2) + 20);
          v57 = 4 * v55;
          v58 = *(_DWORD *)(v56 + 4 * *(_DWORD *)(4 * v55 + v27[4]));
          v59 = *(_DWORD *)(v57 + v27[2]);
          v60 = *(_DWORD *)(v56 + 4 * v59);
          *(_DWORD *)(v58 + 52) = v59;
          *(_DWORD *)v58 |= *(_DWORD *)v60;
          *(double *)(v58 + 32) = *(double *)(v60 + 32);
          *(double *)(v58 + 40) = *(double *)(v60 + 40);
          v55 = ii + 1;
        }
        goto LABEL_138;
      }
      if ( v49 == &loc_10100000 )
      {
        v51 = 0;
        for ( jj = 0; jj < Outputs; ++jj )
        {
          v52 = v51;
          v53 = *(_DWORD *)(*((_DWORD *)v31 + 2) + 20);
          v52 *= 4;
          v54 = *(_DWORD **)(v53 + 4 * *(_DWORD *)(v52 + v27[4]));
          *v54 |= **(_DWORD **)(v53 + 4 * *(_DWORD *)(v52 + v27[2])) & 2;
          v51 = jj + 1;
        }
        goto LABEL_138;
      }
      if ( v49 != (void *)0x20000000 && v49 != (void *)537919488 )
      {
        if ( v49 == (void *)541065216 )
        {
          for ( kk = 0; kk < Outputs; ++kk )
          {
            v50 = *(_DWORD *)(*((_DWORD *)v31 + 2) + 20);
            v78 = *(unsigned int **)(v50 + 4 * *(_DWORD *)(4 * kk + v27[4]));
            *v78 |= **(_DWORD **)(v50 + 4 * *(_DWORD *)(4 * kk + v27[2]))
                  & **(_DWORD **)(v50 + 4 * *(_DWORD *)(v27[2] + 4 * (kk + v27[3])))
                  & 2;
          }
        }
LABEL_138:
        v27[15] = (unsigned int)a2;
        v27[14] = *((_DWORD *)v31 + 14);
        return 0;
      }
    }
    for ( mm = 0; mm < Outputs; ++mm )
    {
      v65 = *(_DWORD *)(*((_DWORD *)v31 + 2) + 20);
      v81 = *(unsigned int **)(v65 + 4 * *(_DWORD *)(4 * mm + v27[4]));
      v66 = **(_DWORD **)(v65 + 4 * *(_DWORD *)(4 * mm + v27[2]))
          & **(_DWORD **)(v65 + 4 * *(_DWORD *)(v27[2] + 4 * (mm + v27[3])));
      if ( (v66 & 1) != 0 )
      {
        *v81 |= 0x17u;
      }
      else if ( (v66 & 2) != 0 )
      {
        *v81 |= 2u;
      }
    }
    goto LABEL_138;
  }
  v71 = NAN;
  result = D3DXShader::CCompiler::EmitInst(
             (D3DXShader::CCompiler *)this,
             a2,
             a3: 0x20500001u,
             a4: (unsigned int *)&v71,
             a5,
             (unsigned int *)a6,
             a7: BYTE4(a6) & 0x40);
  if ( result >= 0 )
  {
    result = D3DXShader::CCompiler::EmitInst(
               (D3DXShader::CCompiler *)this,
               a2,
               a3: 0x20500001u,
               a4: (unsigned int *)&v71 + 1,
               a5: a5 + 1,
               a6: (unsigned int *)(a6 + 4),
               a7: BYTE4(a6) & 0x40);
    if ( result >= 0 )
    {
      result = D3DXShader::CCompiler::EmitInst(
                 (D3DXShader::CCompiler *)this,
                 a2,
                 a3: 0x20400001u,
                 a4,
                 a5: (unsigned int *)&v71,
                 a6: (unsigned int *)&v71 + 1,
                 a7: HIDWORD(a6));
LABEL_18:
      if ( result < 0 )
        return result;
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CB768
// Name: protected: long D3DXShader::CCompiler::ApplyType(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::ApplyType(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3,
        unsigned int a4)
{
  unsigned int *v5; // eax
  unsigned int *v6; // ebx
  unsigned int *v8; // ecx
  _DWORD *v9; // eax

  v5 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * a4);
  v6 = v5;
  if ( v5 == nullptr )
    return -2147024882;
  D3DXShader::CCompiler::GetTypeFlags(this, a2, a3: v5);
  if ( a4 != 0 )
  {
    v8 = v6;
    do
    {
      v9 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                      + 4 * *(unsigned int *)((char *)v8 + (char *)a3 - (char *)v6));
      *v9 |= *v8++;
      --a4;
    }
    while ( a4 != 0 );
  }
  free(pMem: v6);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CB7CF
// Name: protected: long D3DXShader::CCompiler::VectorizeVar(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int,int,int,class D3DXShader::CNode __near *,unsigned int __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::VectorizeVar(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6,
        struct D3DXShader::CNode *a7,
        unsigned int *a8,
        struct D3DXShader::CNode *a9,
        struct D3DXShader::CNode *a10,
        unsigned int *a11)
{
  struct D3DXShader::CNode *v11; // edi
  struct D3DXShader::CNode *v12; // esi
  int result; // eax
  _DWORD *v14; // eax
  bool v15; // zf
  int v16; // ecx
  int v17; // eax
  struct D3DXShader::CNode *v18; // ebx
  int v19; // eax
  int v20; // ebx
  D3DXShader::CCompiler *v21; // esi
  D3DXShader::CBaseProgram *v22; // ecx
  struct D3DXShader::CPool *v23; // eax
  unsigned int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int v29; // esi
  unsigned __int8 *v30; // eax
  unsigned __int8 *v31; // edx
  _BYTE v32[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v33; // [esp+10h] [ebp-18h]
  int v34; // [esp+18h] [ebp-10h] BYREF
  unsigned int v35; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int v36; // [esp+20h] [ebp-8h]
  D3DXShader::CCompiler *v37; // [esp+24h] [ebp-4h]
  unsigned int v38; // [esp+40h] [ebp+18h]
  struct D3DXShader::CNode *v39; // [esp+4Ch] [ebp+24h]
  struct D3DXShader::CNode *v40; // [esp+50h] [ebp+28h]

  v11 = nullptr;
  v37 = this;
  v35 = 0;
  v34 = 0;
  if ( a2 == nullptr )
    goto LABEL_9;
  if ( a5 == 0 && a9 != nullptr )
  {
    a7 = a9;
    a8 = (unsigned int *)&v34;
    a5 = 1;
  }
  if ( a6 == 0 )
  {
    v12 = a10;
    if ( a10 != nullptr && *((_DWORD *)this + 33) == 0 )
    {
      while ( 1 )
      {
        v14 = *((_DWORD **)v12 + 2);
        v15 = v14[1] == 17;
        v39 = nullptr;
        v36 = 0;
        if ( v15 )
        {
          v16 = v14[5];
          v17 = v14[4];
          v18 = *(struct D3DXShader::CNode **)(v16 + 24);
          if ( v17 != 0 )
          {
            if ( (int)D3DXGetTargetDescByName(a1: *(_DWORD *)(v17 + 24), a2: 0, a3: v32) >= 0 )
            {
              v19 = *((_DWORD *)v37 + 4);
              if ( v19 == v33 )
              {
                v39 = v18;
              }
              else if ( (v19 & 0xFFFF0000) == v33 )
              {
                v11 = v18;
              }
            }
          }
          else
          {
            v36 = *(_DWORD *)(v16 + 24);
          }
        }
        v20 = 0;
        v40 = *((struct D3DXShader::CNode **)v12 + 3);
        if ( v39 != nullptr || (v11 == nullptr ? (v39 = (struct D3DXShader::CNode *)v36) : (v39 = v11), v39 != nullptr) )
        {
          v21 = v37;
          v22 = *((D3DXShader::CBaseProgram **)v37 + 2);
          if ( a4 >= *((_DWORD *)v22 + 1) )
            v23 = nullptr;
          else
            v23 = *(struct D3DXShader::CPool **)(*((_DWORD *)v22 + 4) + 4 * a4);
          if ( v23 == nullptr )
            return -2147467259;
          v24 = D3DXShader::CBaseProgram::CopyPool(this: v22, a2: v23);
          v25 = *((_DWORD *)v21 + 2);
          a4 = v24;
          if ( v24 < *(_DWORD *)(v25 + 4) )
            v20 = *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * v24);
          if ( v20 == 0 )
            return -2147024882;
          v26 = *(_DWORD *)(v20 + 4);
          if ( (v26 & 0x800) != 0 )
          {
            v29 = strlen(*(const char **)v20);
            v36 = v29;
            v38 = strlen((const char *)v39);
            v30 = D3DXCore::CAlloc::Alloc(this: *(D3DXCore::CAlloc **)v37, a2: v38 + v29 + 3, a3: 4u);
            if ( v30 == nullptr )
              return -2147024882;
            qmemcpy(v30, *(const void **)v20, v29);
            v31 = &v30[v36];
            *v31 = 59;
            v31[1] = 32;
            qmemcpy(v31 + 2, v39, v38);
            v30[v38 + 2 + v36] = 0;
            *(_DWORD *)v20 = v30;
          }
          else
          {
            v27 = v26 | 0x840;
            *(_DWORD *)v20 = v39;
            *(_DWORD *)(v20 + 4) = v27;
            if ( (v27 & 0x10) != 0 && (v27 & 0x80u) == 0 )
            {
              if ( (v27 & 0x200) != 0 && (*(_DWORD *)(*((_DWORD *)v37 + 2) + 112) & 0x200) != 0 )
                *(_DWORD *)(v20 + 4) = v27 | 0x400;
              v28 = *(_DWORD *)(v20 + 4);
              if ( (v28 & 0x200) == 0 && (*(_BYTE *)(*((_DWORD *)v37 + 2) + 113) & 4) != 0 )
                *(_DWORD *)(v20 + 4) = v28 | 0x100400;
            }
          }
          a6 = 1;
        }
        v11 = nullptr;
        if ( v40 == nullptr )
          break;
        v12 = v40;
      }
    }
  }
  result = D3DXShader::CCompiler::VectorizeType(
             this: (D3DXShader::CBaseProgram **)v37,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9: &v35);
  if ( result >= 0 )
  {
LABEL_9:
    if ( a11 != nullptr )
      *a11 = v35;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CBA1E
// Name: protected: long D3DXShader::CCompiler::EmitSinCos(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitSinCos(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int a6)
{
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  unsigned int *v11; // ecx
  unsigned int v12; // eax
  unsigned int *v13; // ecx
  unsigned int v14; // eax
  unsigned int *v15; // ecx
  unsigned int v16; // edi
  D3DXShader::CBaseProgram *v17; // ecx
  unsigned int v18; // eax
  D3DXShader::CBaseProgram *v19; // ecx
  unsigned int v20; // eax
  D3DXShader::CBaseProgram *v21; // ecx
  unsigned int v22; // eax
  D3DXShader::CBaseProgram *v23; // ecx
  unsigned int v24; // eax
  D3DXShader::CBaseProgram *v25; // ecx
  unsigned int v26; // eax
  D3DXShader::CBaseProgram *v27; // ecx
  unsigned int v28; // eax
  D3DXShader::CBaseProgram *v29; // ecx
  unsigned int v30; // eax
  D3DXShader::CBaseProgram *v31; // ecx
  unsigned int v32; // eax
  D3DXShader::CBaseProgram *v33; // ecx
  char *v34; // eax
  unsigned int v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // edx
  int v38; // edx
  unsigned int *v39; // eax
  unsigned int v40; // ecx
  int v41; // edx
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  unsigned int v45; // [esp-Ch] [ebp-13Ch]
  unsigned int v46; // [esp-Ch] [ebp-13Ch]
  unsigned int v47; // [esp-Ch] [ebp-13Ch]
  unsigned int v48; // [esp-Ch] [ebp-13Ch]
  unsigned int v49; // [esp-Ch] [ebp-13Ch]
  unsigned int v50; // [esp-Ch] [ebp-13Ch]
  unsigned int v51; // [esp-Ch] [ebp-13Ch]
  unsigned int v52; // [esp-Ch] [ebp-13Ch]
  unsigned int v53; // [esp-Ch] [ebp-13Ch]
  __int64 v54; // [esp+0h] [ebp-130h]
  unsigned int v55[4]; // [esp+14h] [ebp-11Ch] BYREF
  double v56[2]; // [esp+24h] [ebp-10Ch] BYREF
  unsigned int v57; // [esp+34h] [ebp-FCh] BYREF
  int v58; // [esp+38h] [ebp-F8h]
  int v59; // [esp+3Ch] [ebp-F4h]
  int v60; // [esp+40h] [ebp-F0h]
  unsigned int v61; // [esp+44h] [ebp-ECh]
  unsigned int v62; // [esp+48h] [ebp-E8h]
  unsigned int v63; // [esp+4Ch] [ebp-E4h]
  unsigned int v64; // [esp+50h] [ebp-E0h]
  unsigned int v65; // [esp+54h] [ebp-DCh]
  unsigned int v66; // [esp+58h] [ebp-D8h]
  unsigned int v67; // [esp+5Ch] [ebp-D4h]
  unsigned int v68; // [esp+60h] [ebp-D0h]
  int v69; // [esp+64h] [ebp-CCh]
  int v70; // [esp+68h] [ebp-C8h]
  int v71; // [esp+6Ch] [ebp-C4h]
  int v72; // [esp+70h] [ebp-C0h]
  int v73; // [esp+74h] [ebp-BCh]
  int v74; // [esp+78h] [ebp-B8h]
  int v75; // [esp+7Ch] [ebp-B4h]
  unsigned int v76; // [esp+80h] [ebp-B0h]
  int v77; // [esp+84h] [ebp-ACh]
  int v78; // [esp+88h] [ebp-A8h]
  int v79; // [esp+8Ch] [ebp-A4h]
  unsigned int v80; // [esp+90h] [ebp-A0h]
  int v81; // [esp+94h] [ebp-9Ch]
  unsigned int *v82; // [esp+98h] [ebp-98h]
  unsigned int *v83; // [esp+9Ch] [ebp-94h]
  unsigned int *v84; // [esp+A0h] [ebp-90h]
  unsigned int *v85; // [esp+A4h] [ebp-8Ch]
  unsigned int *v86; // [esp+A8h] [ebp-88h]
  unsigned int *v87; // [esp+ACh] [ebp-84h]
  unsigned int *v88; // [esp+B0h] [ebp-80h]
  unsigned int *v89; // [esp+B4h] [ebp-7Ch]
  unsigned int *v90; // [esp+B8h] [ebp-78h]
  unsigned int *v91; // [esp+BCh] [ebp-74h]
  unsigned int *v92; // [esp+C0h] [ebp-70h]
  unsigned int *v93; // [esp+C4h] [ebp-6Ch]
  unsigned int *v94; // [esp+C8h] [ebp-68h]
  unsigned int *v95; // [esp+CCh] [ebp-64h]
  unsigned int *v96; // [esp+D0h] [ebp-60h]
  unsigned int *v97; // [esp+D4h] [ebp-5Ch]
  unsigned int *v98; // [esp+D8h] [ebp-58h]
  unsigned int *v99; // [esp+DCh] [ebp-54h]
  unsigned int *v100; // [esp+E0h] [ebp-50h]
  unsigned int *v101; // [esp+E4h] [ebp-4Ch]
  unsigned int *v102; // [esp+E8h] [ebp-48h]
  unsigned int *v103; // [esp+ECh] [ebp-44h]
  unsigned int *v104; // [esp+F0h] [ebp-40h]
  unsigned int *v105; // [esp+F4h] [ebp-3Ch]
  unsigned int *v106; // [esp+F8h] [ebp-38h]
  unsigned int *v107; // [esp+FCh] [ebp-34h]
  unsigned int *v108; // [esp+100h] [ebp-30h]
  unsigned int v109; // [esp+104h] [ebp-2Ch] BYREF
  unsigned int v110; // [esp+108h] [ebp-28h] BYREF
  unsigned int v111; // [esp+10Ch] [ebp-24h] BYREF
  unsigned int v112; // [esp+110h] [ebp-20h] BYREF
  unsigned int v113; // [esp+114h] [ebp-1Ch] BYREF
  void *pMem; // [esp+118h] [ebp-18h]
  unsigned int v115; // [esp+11Ch] [ebp-14h] BYREF
  unsigned int v116; // [esp+120h] [ebp-10h] BYREF
  unsigned int v117; // [esp+124h] [ebp-Ch] BYREF
  unsigned int v118; // [esp+128h] [ebp-8h] BYREF
  int v119; // [esp+12Ch] [ebp-4h]
  unsigned int *v120; // [esp+13Ch] [ebp+Ch]
  unsigned int *v121; // [esp+13Ch] [ebp+Ch]
  unsigned int v122; // [esp+148h] [ebp+18h]
  unsigned int v123; // [esp+148h] [ebp+18h]

  v7 = a6;
  v8 = 1;
  pMem = nullptr;
  v118 = 1;
  if ( a6 > 1 )
  {
    while ( a3[v8] == *a3 )
    {
      if ( ++v8 >= a6 )
        goto LABEL_6;
    }
    v118 = 0;
  }
LABEL_6:
  v9 = *(_DWORD *)(*((_DWORD *)this + 2) + 108);
  if ( (v9 & 0x200) != 0 )
  {
    if ( a4 != nullptr )
    {
      v119 = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: a6 & 0xFFFFF | 0x10800000,
               a4,
               a5: a3,
               a6: 0x1000000000LL);
      if ( v119 < 0 )
        goto LABEL_67;
      v7 = a6;
    }
    if ( a5 == nullptr
      || (v119 = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: v7 & 0xFFFFF | 0x10900000,
                   a4: a5,
                   a5: a3,
                   a6: 0x1000000000LL)) >= 0 )
    {
LABEL_66:
      v119 = 0;
    }
  }
  else if ( (v9 & 0x100) != 0 && v118 != 0 )
  {
    v10 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 0.1591549386630057);
    v11 = *((unsigned int **)this + 2);
    v118 = v10;
    v12 = D3DXShader::CBaseProgram::AddArgument(
            this: (D3DXShader::CBaseProgram *)v11,
            a2: v11[30],
            a3: 0,
            a4: 0,
            a5: 0.5);
    v13 = *((unsigned int **)this + 2);
    v117 = v12;
    v14 = D3DXShader::CBaseProgram::AddArgument(
            this: (D3DXShader::CBaseProgram *)v13,
            a2: v13[30],
            a3: 0,
            a4: 0,
            a5: 6.283185482025146);
    v15 = *((unsigned int **)this + 2);
    v115 = v14;
    v116 = D3DXShader::CBaseProgram::AddArgument(
             this: (D3DXShader::CBaseProgram *)v15,
             a2: v15[30],
             a3: 0,
             a4: 0,
             a5: -3.141592741012573);
    v119 = D3DXShader::CCompiler::EvalRange(this, a2: *a3, a3: (struct D3DXShader::_D3DXRANGE *)v56);
    if ( v119 < 0 )
      goto LABEL_67;
    if ( v56[0] < -3.141592741012573 || v56[1] > 3.141592741012573 )
    {
      v109 = -1;
      v110 = -1;
      v111 = -1;
      v112 = -1;
      v113 = -1;
      v119 = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: 0x20500001u,
               a4: &v109,
               a5: a3,
               a6: (unsigned int)&v118);
      if ( v119 < 0 )
        goto LABEL_67;
      v119 = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: 0x20400001u,
               a4: &v110,
               a5: &v109,
               a6: (unsigned int)&v117);
      if ( v119 < 0 )
        goto LABEL_67;
      v119 = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: 0x10400001u,
               a4: &v111,
               a5: &v110,
               a6: 0x1400000000LL);
      if ( v119 < 0 )
        goto LABEL_67;
      HIDWORD(v54) = 4;
      LODWORD(v54) = &v115;
      v119 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20500001u, a4: &v112, a5: &v111, a6: v54);
      if ( v119 < 0 )
        goto LABEL_67;
      v119 = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: 0x20400001u,
               a4: &v113,
               a5: &v112,
               a6: (unsigned int)&v116);
      if ( v119 < 0 )
        goto LABEL_67;
    }
    else
    {
      v113 = *a3;
    }
    v57 = -1;
    v58 = -1;
    v59 = -1;
    v60 = -1;
    v55[0] = v113;
    v55[1] = v113;
    v55[2] = v113;
    v55[3] = v113;
    v119 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x50300004u, a4: &v57, a5: v55, a6: 0x1000000000LL);
    if ( v119 >= 0 )
    {
      if ( a5 != nullptr && a6 != 0 )
        memset32(a5, v57, a6);
      if ( a4 != nullptr && a6 != 0 )
        memset32(a4, v58, a6);
      goto LABEL_66;
    }
  }
  else
  {
    v16 = a4 != nullptr ? a6 : 0;
    v17 = *((D3DXShader::CBaseProgram **)this + 2);
    v45 = *((_DWORD *)v17 + 30);
    v68 = a5 != nullptr ? a6 : 0;
    v118 = v16 + v68;
    v18 = D3DXShader::CBaseProgram::AddArgument(this: v17, a2: v45, a3: 0, a4: 0, a5: 0.1591549386630057);
    v19 = *((D3DXShader::CBaseProgram **)this + 2);
    v46 = *((_DWORD *)v19 + 30);
    v117 = v18;
    v20 = D3DXShader::CBaseProgram::AddArgument(this: v19, a2: v46, a3: 0, a4: 0, a5: 0.25);
    v21 = *((D3DXShader::CBaseProgram **)this + 2);
    v47 = *((_DWORD *)v21 + 30);
    v61 = v20;
    v22 = D3DXShader::CBaseProgram::AddArgument(this: v21, a2: v47, a3: 0, a4: 0, a5: 0.5);
    v23 = *((D3DXShader::CBaseProgram **)this + 2);
    v48 = *((_DWORD *)v23 + 30);
    v62 = v22;
    v24 = D3DXShader::CBaseProgram::AddArgument(this: v23, a2: v48, a3: 0, a4: 0, a5: 6.283185482025146);
    v25 = *((D3DXShader::CBaseProgram **)this + 2);
    v49 = *((_DWORD *)v25 + 30);
    v66 = v24;
    v26 = D3DXShader::CBaseProgram::AddArgument(this: v25, a2: v49, a3: 0, a4: 0, a5: -3.141592741012573);
    v27 = *((D3DXShader::CBaseProgram **)this + 2);
    v50 = *((_DWORD *)v27 + 30);
    v67 = v26;
    v28 = D3DXShader::CBaseProgram::AddArgument(this: v27, a2: v50, a3: 0, a4: 0, a5: -0.0000002523985176899309);
    v29 = *((D3DXShader::CBaseProgram **)this + 2);
    v51 = *((_DWORD *)v29 + 30);
    v65 = v28;
    v63 = D3DXShader::CBaseProgram::AddArgument(this: v29, a2: v51, a3: 0, a4: 0, a5: 0.0000247609);
    v30 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: -0.0013888397);
    v31 = *((D3DXShader::CBaseProgram **)this + 2);
    v52 = *((_DWORD *)v31 + 30);
    v64 = v30;
    v32 = D3DXShader::CBaseProgram::AddArgument(this: v31, a2: v52, a3: 0, a4: 0, a5: 0.0416666418);
    v33 = *((D3DXShader::CBaseProgram **)this + 2);
    v53 = *((_DWORD *)v33 + 30);
    v80 = v32;
    v76 = D3DXShader::CBaseProgram::AddArgument(this: v33, a2: v53, a3: 0, a4: 0, a5: -0.4999999963);
    v34 = (char *)MemAlloc_Alloc(nSize: 108 * (v16 + v68));
    pMem = v34;
    if ( v34 != nullptr )
    {
      v35 = 0;
      v36 = 4 * v118;
      do
      {
        (&v82)[v35++] = (unsigned int *)v34;
        v34 += v36;
      }
      while ( v35 < 0x1B );
      v37 = 0;
      while ( 1 )
      {
        v119 = D3DXShader::CCompiler::EmitTemp(this, a2: (&v82)[v37], a3: v118);
        if ( v119 < 0 )
          break;
        v37 = v38 + 1;
        if ( v37 >= 0xF )
        {
          v122 = 0;
          if ( v118 != 0 )
          {
            v39 = v97;
            v119 = (int)&a3[-v16];
            v115 = (char *)a5 - (char *)a3;
            v116 = (char *)a4 - (char *)v97;
            v73 = (char *)v98 - (char *)v97;
            v79 = (char *)v99 - (char *)v97;
            v77 = (char *)v100 - (char *)v97;
            v75 = (char *)v101 - (char *)v97;
            v81 = (char *)v102 - (char *)v97;
            v71 = (char *)v103 - (char *)v97;
            v69 = (char *)v104 - (char *)v97;
            v78 = (char *)v105 - (char *)v97;
            v74 = (char *)v106 - (char *)v97;
            v72 = (char *)v107 - (char *)v97;
            v120 = (unsigned int *)((char *)a3 - (char *)v97);
            v70 = (char *)v108 - (char *)v97;
            do
            {
              if ( v122 >= v16 )
                v40 = *(_DWORD *)(v115 + v119);
              else
                v40 = *(unsigned int *)((char *)v39 + v116);
              v41 = v73;
              *v39 = v40;
              *(unsigned int *)((char *)v39 + v41) = v117;
              v42 = v61;
              if ( v122 >= v16 )
                v42 = v62;
              *(unsigned int *)((char *)v39 + v79) = v42;
              *(unsigned int *)((char *)v39 + v77) = v66;
              *(unsigned int *)((char *)v39 + v75) = v67;
              *(unsigned int *)((char *)v39 + v81) = v65;
              *(unsigned int *)((char *)v39 + v71) = v63;
              *(unsigned int *)((char *)v39 + v69) = v64;
              *(unsigned int *)((char *)v39 + v78) = v80;
              *(unsigned int *)((char *)v39 + v74) = v76;
              *(unsigned int *)((char *)v39 + v72) = *((_DWORD *)this + 8);
              if ( v122 >= v16 )
                v43 = *(_DWORD *)v119;
              else
                v43 = *(unsigned int *)((char *)v39 + (_DWORD)v120);
              ++v122;
              v119 += 4;
              *(unsigned int *)((char *)v39++ + v70) = v43;
            }
            while ( v122 < v118 );
          }
          v121 = (unsigned int *)(v118 & 0xFFFFF | 0x20500000);
          v118 &= 0xFFFFFu;
          v119 = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: (unsigned int)v121,
                   a4: v82,
                   a5: v108,
                   a6: (unsigned int)v98);
          if ( v119 >= 0 )
          {
            v123 = v118 | 0x20400000;
            v119 = D3DXShader::CCompiler::EmitInst(
                     (char **)this,
                     a2,
                     a3: v118 | 0x20400000,
                     a4: v83,
                     a5: v82,
                     a6: (unsigned int)v99);
            if ( v119 >= 0 )
            {
              v119 = D3DXShader::CCompiler::EmitInst(
                       (char **)this,
                       a2,
                       a3: v118 | 0x10400000,
                       a4: v84,
                       a5: v83,
                       a6: 0x1400000000LL);
              if ( v119 >= 0 )
              {
                v119 = D3DXShader::CCompiler::EmitInst(
                         (char **)this,
                         a2,
                         a3: (unsigned int)v121,
                         a4: v85,
                         a5: v84,
                         a6: (unsigned int)v100 | 0x400000000LL);
                if ( v119 >= 0 )
                {
                  v119 = D3DXShader::CCompiler::EmitInst(
                           (char **)this,
                           a2,
                           a3: v123,
                           a4: v86,
                           a5: v85,
                           a6: (unsigned int)v101);
                  if ( v119 >= 0 )
                  {
                    v119 = D3DXShader::CCompiler::EmitInst(
                             (char **)this,
                             a2,
                             a3: (unsigned int)v121,
                             a4: v87,
                             a5: v86,
                             a6: (unsigned int)v86 | 0x400000000LL);
                    if ( v119 >= 0 )
                    {
                      v119 = D3DXShader::CCompiler::EmitInst(
                               (char **)this,
                               a2,
                               a3: (unsigned int)v121,
                               a4: v88,
                               a5: v87,
                               a6: (unsigned int)v102);
                      if ( v119 >= 0 )
                      {
                        v119 = D3DXShader::CCompiler::EmitInst(
                                 (char **)this,
                                 a2,
                                 a3: v123,
                                 a4: v89,
                                 a5: v88,
                                 a6: (unsigned int)v103);
                        if ( v119 >= 0 )
                        {
                          v119 = D3DXShader::CCompiler::EmitInst(
                                   (char **)this,
                                   a2,
                                   a3: (unsigned int)v121,
                                   a4: v90,
                                   a5: v87,
                                   a6: (unsigned int)v89);
                          if ( v119 >= 0 )
                          {
                            v119 = D3DXShader::CCompiler::EmitInst(
                                     (char **)this,
                                     a2,
                                     a3: v123,
                                     a4: v91,
                                     a5: v90,
                                     a6: (unsigned int)v104);
                            if ( v119 >= 0 )
                            {
                              v119 = D3DXShader::CCompiler::EmitInst(
                                       (char **)this,
                                       a2,
                                       a3: (unsigned int)v121,
                                       a4: v92,
                                       a5: v87,
                                       a6: (unsigned int)v91);
                              if ( v119 >= 0 )
                              {
                                v119 = D3DXShader::CCompiler::EmitInst(
                                         (char **)this,
                                         a2,
                                         a3: v123,
                                         a4: v93,
                                         a5: v92,
                                         a6: (unsigned int)v105);
                                if ( v119 >= 0 )
                                {
                                  v119 = D3DXShader::CCompiler::EmitInst(
                                           (char **)this,
                                           a2,
                                           a3: (unsigned int)v121,
                                           a4: v94,
                                           a5: v87,
                                           a6: (unsigned int)v93);
                                  if ( v119 >= 0 )
                                  {
                                    v119 = D3DXShader::CCompiler::EmitInst(
                                             (char **)this,
                                             a2,
                                             a3: v123,
                                             a4: v95,
                                             a5: v94,
                                             a6: (unsigned int)v106);
                                    if ( v119 >= 0 )
                                    {
                                      v119 = D3DXShader::CCompiler::EmitInst(
                                               (char **)this,
                                               a2,
                                               a3: (unsigned int)v121,
                                               a4: v96,
                                               a5: v87,
                                               a6: (unsigned int)v95);
                                      if ( v119 >= 0 )
                                      {
                                        v119 = D3DXShader::CCompiler::EmitInst(
                                                 (char **)this,
                                                 a2,
                                                 a3: v123,
                                                 a4: v97,
                                                 a5: v96,
                                                 a6: (unsigned int)v107 | 0x1000000000LL);
                                        if ( v119 >= 0 )
                                        {
                                          qmemcpy(a4, v97, 4 * v16);
                                          qmemcpy(a5, &v97[v16], 4 * v68);
                                          goto LABEL_66;
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
          }
          break;
        }
      }
    }
    else
    {
      v119 = -2147024882;
    }
  }
LABEL_67:
  free(pMem);
  return v119;
}

//------------------------------------------------------------------------------
// Address: 0x101CC2C0
// Name: protected: long D3DXShader::CCompiler::EmitASinACos(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitASinACos(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int a6)
{
  bool v7; // zf
  int v8; // edi
  int v9; // eax
  unsigned int v11; // eax
  D3DXShader::CBaseProgram *v12; // ecx
  unsigned int v13; // eax
  D3DXShader::CBaseProgram *v14; // ecx
  char *v15; // eax
  unsigned int i; // ecx
  unsigned int v17; // edx
  int v18; // edx
  unsigned int *v19; // eax
  int v20; // ecx
  unsigned int v21; // [esp-Ch] [ebp-CCh]
  unsigned int v22; // [esp-Ch] [ebp-CCh]
  unsigned int v23; // [esp+14h] [ebp-ACh]
  int v24; // [esp+18h] [ebp-A8h]
  int v25; // [esp+1Ch] [ebp-A4h]
  int v26; // [esp+20h] [ebp-A0h]
  unsigned int v27; // [esp+24h] [ebp-9Ch]
  unsigned int v28; // [esp+28h] [ebp-98h]
  int v29; // [esp+2Ch] [ebp-94h]
  int v30; // [esp+30h] [ebp-90h]
  unsigned int v31; // [esp+34h] [ebp-8Ch]
  int v32; // [esp+38h] [ebp-88h]
  unsigned int v33; // [esp+3Ch] [ebp-84h]
  unsigned int *v34; // [esp+40h] [ebp-80h]
  unsigned int *v35; // [esp+44h] [ebp-7Ch]
  unsigned int *v36; // [esp+48h] [ebp-78h]
  unsigned int *v37; // [esp+4Ch] [ebp-74h]
  unsigned int *v38; // [esp+50h] [ebp-70h]
  unsigned int *v39; // [esp+54h] [ebp-6Ch]
  unsigned int *v40; // [esp+58h] [ebp-68h]
  unsigned int *v41; // [esp+5Ch] [ebp-64h]
  unsigned int *v42; // [esp+60h] [ebp-60h]
  unsigned int *v43; // [esp+64h] [ebp-5Ch]
  unsigned int *v44; // [esp+68h] [ebp-58h]
  unsigned int *v45; // [esp+6Ch] [ebp-54h]
  unsigned int *v46; // [esp+70h] [ebp-50h]
  unsigned int *v47; // [esp+74h] [ebp-4Ch]
  unsigned int *v48; // [esp+78h] [ebp-48h]
  unsigned int *v49; // [esp+7Ch] [ebp-44h]
  unsigned int *v50; // [esp+80h] [ebp-40h]
  unsigned int *v51; // [esp+84h] [ebp-3Ch]
  unsigned int *v52; // [esp+88h] [ebp-38h]
  unsigned int *v53; // [esp+8Ch] [ebp-34h]
  unsigned int *v54; // [esp+90h] [ebp-30h]
  unsigned int *v55; // [esp+94h] [ebp-2Ch]
  unsigned int *v56; // [esp+98h] [ebp-28h]
  unsigned int *v57; // [esp+9Ch] [ebp-24h]
  unsigned int *v58; // [esp+A0h] [ebp-20h]
  unsigned int *v59; // [esp+A4h] [ebp-1Ch]
  unsigned int *v60; // [esp+A8h] [ebp-18h]
  unsigned int *v61; // [esp+ACh] [ebp-14h]
  void *pMem; // [esp+B0h] [ebp-10h]
  unsigned int v63; // [esp+B4h] [ebp-Ch]
  unsigned int v64; // [esp+B8h] [ebp-8h]
  unsigned int j; // [esp+BCh] [ebp-4h]
  unsigned int v66; // [esp+D8h] [ebp+18h]

  v7 = (*(_BYTE *)(*((_DWORD *)this + 2) + 109) & 2) == 0;
  pMem = nullptr;
  if ( v7 )
  {
    v11 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: -0.0187293);
    v12 = *((D3DXShader::CBaseProgram **)this + 2);
    v21 = *((_DWORD *)v12 + 30);
    v63 = v11;
    v13 = D3DXShader::CBaseProgram::AddArgument(this: v12, a2: v21, a3: 0, a4: 0, a5: 0.07426099999999999);
    v14 = *((D3DXShader::CBaseProgram **)this + 2);
    v22 = *((_DWORD *)v14 + 30);
    v64 = v13;
    v23 = D3DXShader::CBaseProgram::AddArgument(this: v14, a2: v22, a3: 0, a4: 0, a5: -0.2121144);
    v33 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 1.5707288);
    v28 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: -2.0);
    v31 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 3.141592741012573);
    v27 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 1.570796370506287);
    v15 = (char *)MemAlloc_Alloc(nSize: 112 * a6);
    pMem = v15;
    if ( v15 != nullptr )
    {
      for ( i = 0; i < 0x1C; ++i )
      {
        (&v34)[i] = (unsigned int *)v15;
        v15 += 4 * a6;
      }
      v17 = 0;
      while ( 1 )
      {
        v8 = D3DXShader::CCompiler::EmitTemp(this, a2: (&v34)[v17], a3: a6);
        if ( v8 < 0 )
          break;
        v17 = v18 + 1;
        if ( v17 >= 0x14 )
        {
          if ( a6 != 0 )
          {
            v19 = v55;
            v30 = (char *)v56 - (char *)v55;
            v24 = (char *)v57 - (char *)v55;
            v26 = (char *)v58 - (char *)v55;
            v32 = (char *)v59 - (char *)v55;
            v29 = (char *)v60 - (char *)v55;
            v20 = (char *)v54 - (char *)v55;
            v25 = (char *)v61 - (char *)v55;
            for ( j = a6; j != 0; --j )
            {
              *(unsigned int *)((char *)v19 + v20) = *((_DWORD *)this + 8);
              *v19 = v63;
              *(unsigned int *)((char *)v19 + v30) = v64;
              *(unsigned int *)((char *)v19 + v24) = v23;
              *(unsigned int *)((char *)v19 + v26) = v33;
              *(unsigned int *)((char *)v19 + v32) = v28;
              *(unsigned int *)((char *)v19 + v29) = v31;
              *(unsigned int *)((char *)v19++ + v25) = v27;
            }
          }
          j = a6 & 0xFFFFF | 0x10100000;
          v66 = a6 & 0xFFFFF;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: j, a4: v34, a5: a3, a6: 0);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x20100000,
                 a4: v35,
                 a5: a3,
                 a6: (unsigned int)v34 | 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: j, a4: v36, a5: v35, a6: 0x800000000LL);
          if ( v8 < 0 )
            break;
          v64 = v66 | 0x20400000;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x20400000,
                 a4: v37,
                 a5: v36,
                 a6: (unsigned int)v54);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x10700000,
                 a4: v38,
                 a5: v37,
                 a6: 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: (unsigned int)&unk_10300000 | v66,
                 a4: v39,
                 a5: v38,
                 a6: 0x400000000LL);
          if ( v8 < 0 )
            break;
          v63 = v66 | 0x20500000;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x20500000,
                 a4: v40,
                 a5: v55,
                 a6: (unsigned int)v35);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v64, a4: v41, a5: v40, a6: (unsigned int)v56);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v63, a4: v42, a5: v41, a6: (unsigned int)v35);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v64, a4: v43, a5: v42, a6: (unsigned int)v57);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v63, a4: v44, a5: v43, a6: (unsigned int)v35);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v64, a4: v45, a5: v44, a6: (unsigned int)v58);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v63, a4: v46, a5: v45, a6: (unsigned int)v39);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v63, a4: v47, a5: v46, a6: (unsigned int)v59);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v64, a4: v48, a5: v47, a6: (unsigned int)v60);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x20200000,
                 a4: v49,
                 a5: a3,
                 a6: (unsigned int)v34 | 0x1700000000LL);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v63, a4: v50, a5: v48, a6: (unsigned int)v49);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v64,
                 a4: v51,
                 a5: v46,
                 a6: (unsigned int)v50 | 0x400000000LL);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: j, a4: v52, a5: v51, a6: 0x800000000LL);
          if ( v8 < 0 )
            break;
          v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v64, a4: v53, a5: v52, a6: (unsigned int)v61);
          if ( v8 < 0 )
            break;
          if ( a4 != nullptr )
          {
            v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v66 | 0x10000000, a4, a5: v53, a6: 0);
            if ( v8 < 0 )
              break;
          }
          if ( a5 == nullptr )
            goto LABEL_7;
          v9 = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v66 | 0x10000000,
                 a4: a5,
                 a5: v51,
                 a6: 0x400000000LL);
          goto LABEL_6;
        }
      }
    }
    else
    {
      v8 = -2147024882;
    }
  }
  else if ( a4 == nullptr
         || (v8 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: a6 & 0xFFFFF | 0x10A00000, a4, a5: a3, a6: 0)) >= 0 )
  {
    if ( a5 == nullptr )
      goto LABEL_7;
    v9 = D3DXShader::CCompiler::EmitInst(
           (char **)this,
           a2,
           a3: a6 & 0xFFFFF | 0x10B00000,
           a4: a5,
           a5: a3,
           a6: 0x400000000LL);
LABEL_6:
    v8 = v9;
    if ( v9 >= 0 )
LABEL_7:
      v8 = 0;
  }
  free(pMem);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101CC83E
// Name: protected: long D3DXShader::CCompiler::EmitATan2(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitATan2(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int a6)
{
  bool v7; // zf
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  D3DXShader::CBaseProgram *v12; // ecx
  unsigned int v13; // eax
  D3DXShader::CBaseProgram *v14; // ecx
  unsigned int v15; // eax
  D3DXShader::CBaseProgram *v16; // ecx
  unsigned int v17; // edi
  char *v18; // edx
  int v19; // edi
  unsigned int i; // eax
  unsigned int v21; // edx
  int v22; // edx
  unsigned int *v23; // eax
  unsigned int v24; // edx
  int v25; // ecx
  unsigned int v27; // [esp-Ch] [ebp-124h]
  unsigned int v28; // [esp-Ch] [ebp-124h]
  unsigned int v29; // [esp-Ch] [ebp-124h]
  __int64 v30; // [esp+0h] [ebp-118h]
  unsigned int v31; // [esp+14h] [ebp-104h]
  unsigned int v32; // [esp+18h] [ebp-100h]
  int v33; // [esp+1Ch] [ebp-FCh]
  unsigned int v34; // [esp+20h] [ebp-F8h]
  int v35; // [esp+24h] [ebp-F4h]
  int v36; // [esp+28h] [ebp-F0h]
  unsigned int v37; // [esp+2Ch] [ebp-ECh]
  int v38; // [esp+30h] [ebp-E8h]
  int v39; // [esp+34h] [ebp-E4h]
  unsigned int v40; // [esp+38h] [ebp-E0h]
  unsigned int *v41; // [esp+3Ch] [ebp-DCh]
  unsigned int *v42; // [esp+40h] [ebp-D8h]
  unsigned int *v43; // [esp+44h] [ebp-D4h]
  unsigned int *v44; // [esp+48h] [ebp-D0h]
  unsigned int *v45; // [esp+4Ch] [ebp-CCh]
  unsigned int *v46; // [esp+50h] [ebp-C8h]
  unsigned int *v47; // [esp+54h] [ebp-C4h]
  unsigned int *v48; // [esp+58h] [ebp-C0h]
  unsigned int *v49; // [esp+5Ch] [ebp-BCh]
  unsigned int *v50; // [esp+60h] [ebp-B8h]
  unsigned int *v51; // [esp+64h] [ebp-B4h]
  unsigned int *v52; // [esp+68h] [ebp-B0h]
  unsigned int *v53; // [esp+6Ch] [ebp-ACh]
  unsigned int *v54; // [esp+70h] [ebp-A8h]
  unsigned int *v55; // [esp+74h] [ebp-A4h]
  unsigned int *v56; // [esp+78h] [ebp-A0h]
  unsigned int *v57; // [esp+7Ch] [ebp-9Ch]
  unsigned int *v58; // [esp+80h] [ebp-98h]
  unsigned int *v59; // [esp+84h] [ebp-94h]
  unsigned int *v60; // [esp+88h] [ebp-90h]
  unsigned int *v61; // [esp+8Ch] [ebp-8Ch]
  unsigned int *v62; // [esp+90h] [ebp-88h]
  unsigned int *v63; // [esp+94h] [ebp-84h]
  unsigned int *v64; // [esp+A4h] [ebp-74h]
  unsigned int *v65; // [esp+A8h] [ebp-70h]
  unsigned int *v66; // [esp+ACh] [ebp-6Ch]
  unsigned int *v67; // [esp+B0h] [ebp-68h]
  unsigned int *v68; // [esp+B4h] [ebp-64h]
  unsigned int *v69; // [esp+B8h] [ebp-60h]
  unsigned int *v70; // [esp+BCh] [ebp-5Ch]
  unsigned int *v71; // [esp+C0h] [ebp-58h]
  unsigned int *v72; // [esp+C4h] [ebp-54h]
  unsigned int *v73; // [esp+C8h] [ebp-50h]
  unsigned int *v74; // [esp+CCh] [ebp-4Ch]
  unsigned int *v75; // [esp+D0h] [ebp-48h]
  unsigned int *v76; // [esp+D4h] [ebp-44h]
  unsigned int *v77; // [esp+D8h] [ebp-40h]
  unsigned int *v78; // [esp+DCh] [ebp-3Ch]
  unsigned int *v79; // [esp+E0h] [ebp-38h]
  unsigned int *v80; // [esp+E4h] [ebp-34h]
  unsigned int *v81; // [esp+E8h] [ebp-30h]
  unsigned int *v82; // [esp+ECh] [ebp-2Ch]
  unsigned int *v83; // [esp+F0h] [ebp-28h]
  unsigned int *v84; // [esp+F4h] [ebp-24h]
  unsigned int *v85; // [esp+F8h] [ebp-20h]
  void *pMem; // [esp+FCh] [ebp-1Ch]
  unsigned int v87; // [esp+100h] [ebp-18h]
  unsigned int v88; // [esp+104h] [ebp-14h]
  unsigned int v89; // [esp+108h] [ebp-10h]
  unsigned int v90; // [esp+10Ch] [ebp-Ch]
  unsigned int v91; // [esp+110h] [ebp-8h]
  unsigned int v92; // [esp+114h] [ebp-4h]
  int v93; // [esp+130h] [ebp+18h]

  v7 = (*(_BYTE *)(*((_DWORD *)this + 2) + 109) & 2) == 0;
  pMem = nullptr;
  if ( v7 )
  {
    v11 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 0.0208351);
    v12 = *((D3DXShader::CBaseProgram **)this + 2);
    v27 = *((_DWORD *)v12 + 30);
    v90 = v11;
    v13 = D3DXShader::CBaseProgram::AddArgument(this: v12, a2: v27, a3: 0, a4: 0, a5: -0.085133);
    v14 = *((D3DXShader::CBaseProgram **)this + 2);
    v28 = *((_DWORD *)v14 + 30);
    v91 = v13;
    v15 = D3DXShader::CBaseProgram::AddArgument(this: v14, a2: v28, a3: 0, a4: 0, a5: 0.180141);
    v16 = *((D3DXShader::CBaseProgram **)this + 2);
    v29 = *((_DWORD *)v16 + 30);
    v92 = v15;
    v31 = D3DXShader::CBaseProgram::AddArgument(this: v16, a2: v29, a3: 0, a4: 0, a5: -0.3302995);
    v40 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 0.999866);
    v34 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: -2.0);
    v32 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: 1.570796370506287);
    v17 = a6;
    v37 = D3DXShader::CBaseProgram::AddArgument(
            this: *((D3DXShader::CBaseProgram **)this + 2),
            a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
            a3: 0,
            a4: 0,
            a5: -3.141592741012573);
    v18 = (char *)MemAlloc_Alloc(nSize: 192 * a6);
    pMem = v18;
    if ( v18 != nullptr )
    {
      for ( i = 0; i < 0x30; ++i )
      {
        (&v41)[i] = (unsigned int *)v18;
        v18 += 4 * a6;
      }
      v21 = 0;
      while ( 1 )
      {
        v19 = D3DXShader::CCompiler::EmitTemp(this, a2: (&v41)[v21], a3: v17);
        if ( v19 < 0 )
          break;
        v21 = v22 + 1;
        if ( v21 >= 0x27 )
        {
          if ( a6 != 0 )
          {
            v23 = v78;
            v33 = (char *)v80 - (char *)v78;
            v38 = (char *)v81 - (char *)v78;
            v36 = (char *)v82 - (char *)v78;
            v39 = (char *)v83 - (char *)v78;
            v35 = (char *)v84 - (char *)v78;
            v24 = (char *)v79 - (char *)v78;
            v25 = (char *)v77 - (char *)v78;
            v87 = (char *)v85 - (char *)v78;
            v88 = (char *)v79 - (char *)v78;
            v89 = a6;
            while ( 1 )
            {
              *(unsigned int *)((char *)v23 + v25) = v90;
              *v23 = v91;
              *(unsigned int *)((char *)v23 + v24) = v92;
              *(unsigned int *)((char *)v23 + v33) = v31;
              *(unsigned int *)((char *)v23 + v38) = v40;
              *(unsigned int *)((char *)v23 + v36) = v34;
              *(unsigned int *)((char *)v23 + v39) = v32;
              *(unsigned int *)((char *)v23 + v35) = v37;
              *(unsigned int *)((char *)v23++ + v87) = *((_DWORD *)this + 8);
              if ( --v89 == 0 )
                break;
              v24 = v88;
            }
          }
          if ( a4 == nullptr )
            a4 = v85;
          v90 = a6 & 0xFFFFF | 0x10100000;
          v91 = a6 & 0xFFFFF;
          v19 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v90, a4: v41, a5: a3, a6: 0);
          if ( v19 >= 0 )
          {
            v89 = v91 | 0x20100000;
            v19 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: v91 | 0x20100000,
                    a4: v42,
                    a5: a3,
                    a6: (unsigned int)v41 | 0x400000000LL);
            if ( v19 >= 0 )
            {
              v19 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v90, a4: v43, a5: a4, a6: 0);
              if ( v19 >= 0 )
              {
                v19 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: v89,
                        a4: v44,
                        a5: a4,
                        a6: (unsigned int)v43 | 0x400000000LL);
                if ( v19 >= 0 )
                {
                  v87 = v91 | 0x20000000;
                  v19 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: v91 | 0x20000000,
                          a4: v45,
                          a5: v42,
                          a6: (unsigned int)v44 | 0x400000000LL);
                  if ( v19 >= 0 )
                  {
                    v19 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: v89,
                            a4: v46,
                            a5: v42,
                            a6: (unsigned int)v44 | 0x400000000LL);
                    if ( v19 >= 0 )
                    {
                      v19 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: (unsigned int)&unk_10300000 | v91,
                              a4: v47,
                              a5: v46,
                              a6: 0x400000000LL);
                      if ( v19 >= 0 )
                      {
                        v93 = v91 | 0x20500000;
                        v19 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: v91 | 0x20500000,
                                a4: v48,
                                a5: v45,
                                a6: (unsigned int)v47 | 0x1400000000LL);
                        if ( v19 >= 0 )
                        {
                          v19 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: v93,
                                  a4: v49,
                                  a5: v48,
                                  a6: (unsigned int)v48 | 0x1400000000LL);
                          if ( v19 >= 0 )
                          {
                            v19 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: v93,
                                    a4: v50,
                                    a5: v49,
                                    a6: (unsigned int)v77);
                            if ( v19 >= 0 )
                            {
                              v92 = v91 | 0x20400000;
                              v19 = D3DXShader::CCompiler::EmitInst(
                                      (char **)this,
                                      a2,
                                      a3: v91 | 0x20400000,
                                      a4: v51,
                                      a5: v50,
                                      a6: (unsigned int)v78);
                              if ( v19 >= 0 )
                              {
                                v19 = D3DXShader::CCompiler::EmitInst(
                                        (char **)this,
                                        a2,
                                        a3: v93,
                                        a4: v52,
                                        a5: v49,
                                        a6: (unsigned int)v51);
                                if ( v19 >= 0 )
                                {
                                  v19 = D3DXShader::CCompiler::EmitInst(
                                          (char **)this,
                                          a2,
                                          a3: v92,
                                          a4: v53,
                                          a5: v52,
                                          a6: (unsigned int)v79);
                                  if ( v19 >= 0 )
                                  {
                                    v19 = D3DXShader::CCompiler::EmitInst(
                                            (char **)this,
                                            a2,
                                            a3: v93,
                                            a4: v54,
                                            a5: v49,
                                            a6: (unsigned int)v53);
                                    if ( v19 >= 0 )
                                    {
                                      v19 = D3DXShader::CCompiler::EmitInst(
                                              (char **)this,
                                              a2,
                                              a3: v92,
                                              a4: v55,
                                              a5: v54,
                                              a6: (unsigned int)v80);
                                      if ( v19 >= 0 )
                                      {
                                        v19 = D3DXShader::CCompiler::EmitInst(
                                                (char **)this,
                                                a2,
                                                a3: v93,
                                                a4: v56,
                                                a5: v49,
                                                a6: (unsigned int)v55);
                                        if ( v19 >= 0 )
                                        {
                                          v19 = D3DXShader::CCompiler::EmitInst(
                                                  (char **)this,
                                                  a2,
                                                  a3: v92,
                                                  a4: v57,
                                                  a5: v56,
                                                  a6: (unsigned int)v81);
                                          if ( v19 >= 0 )
                                          {
                                            v19 = D3DXShader::CCompiler::EmitInst(
                                                    (char **)this,
                                                    a2,
                                                    a3: v93,
                                                    a4: v58,
                                                    a5: v48,
                                                    a6: (unsigned int)v57);
                                            if ( v19 >= 0 )
                                            {
                                              v88 = v91 | 0x20200000;
                                              v19 = D3DXShader::CCompiler::EmitInst(
                                                      (char **)this,
                                                      a2,
                                                      a3: v91 | 0x20200000,
                                                      a4: v59,
                                                      a5: v44,
                                                      a6: (unsigned int)v42 | 0x1700000000LL);
                                              if ( v19 >= 0 )
                                              {
                                                v19 = D3DXShader::CCompiler::EmitInst(
                                                        (char **)this,
                                                        a2,
                                                        a3: v93,
                                                        a4: v60,
                                                        a5: v58,
                                                        a6: (unsigned int)v82);
                                                if ( v19 >= 0 )
                                                {
                                                  v19 = D3DXShader::CCompiler::EmitInst(
                                                          (char **)this,
                                                          a2,
                                                          a3: v92,
                                                          a4: v61,
                                                          a5: v60,
                                                          a6: (unsigned int)v83);
                                                  if ( v19 >= 0 )
                                                  {
                                                    v19 = D3DXShader::CCompiler::EmitInst(
                                                            (char **)this,
                                                            a2,
                                                            a3: v93,
                                                            a4: v62,
                                                            a5: v61,
                                                            a6: (unsigned int)v59);
                                                    if ( v19 >= 0 )
                                                    {
                                                      v19 = D3DXShader::CCompiler::EmitInst(
                                                              (char **)this,
                                                              a2,
                                                              a3: v92,
                                                              a4: v63,
                                                              a5: v62,
                                                              a6: (unsigned int)v58);
                                                      if ( v19 >= 0 )
                                                      {
                                                        v19 = D3DXShader::CCompiler::EmitInst(
                                                                (char **)this,
                                                                a2,
                                                                a3: v88,
                                                                a4: v64,
                                                                a5: a4,
                                                                a6: (unsigned int)v43 | 0x1700000000LL);
                                                        if ( v19 >= 0 )
                                                        {
                                                          v19 = D3DXShader::CCompiler::EmitInst(
                                                                  (char **)this,
                                                                  a2,
                                                                  a3: v93,
                                                                  a4: v65,
                                                                  a5: v64,
                                                                  a6: (unsigned int)v84);
                                                          if ( v19 >= 0 )
                                                          {
                                                            v19 = D3DXShader::CCompiler::EmitInst(
                                                                    (char **)this,
                                                                    a2,
                                                                    a3: v92,
                                                                    a4: v66,
                                                                    a5: v63,
                                                                    a6: (unsigned int)v65);
                                                            if ( v19 >= 0 )
                                                            {
                                                              v19 = D3DXShader::CCompiler::EmitInst(
                                                                      (char **)this,
                                                                      a2,
                                                                      a3: v87,
                                                                      a4: v67,
                                                                      a5: a3,
                                                                      a6: (unsigned int)a4);
                                                              if ( v19 >= 0 )
                                                              {
                                                                v19 = D3DXShader::CCompiler::EmitInst(
                                                                        (char **)this,
                                                                        a2,
                                                                        a3: v89,
                                                                        a4: v68,
                                                                        a5: a3,
                                                                        a6: (unsigned int)a4);
                                                                if ( v19 >= 0 )
                                                                {
                                                                  v19 = D3DXShader::CCompiler::EmitInst(
                                                                          (char **)this,
                                                                          a2,
                                                                          a3: v90,
                                                                          a4: v69,
                                                                          a5: v67,
                                                                          a6: 0);
                                                                  if ( v19 >= 0 )
                                                                  {
                                                                    v19 = D3DXShader::CCompiler::EmitInst(
                                                                            (char **)this,
                                                                            a2,
                                                                            a3: v88,
                                                                            a4: v70,
                                                                            a5: v67,
                                                                            a6: (unsigned int)v69 | 0x1700000000LL);
                                                                    if ( v19 >= 0 )
                                                                    {
                                                                      v19 = D3DXShader::CCompiler::EmitInst(
                                                                              (char **)this,
                                                                              a2,
                                                                              a3: v90,
                                                                              a4: v71,
                                                                              a5: v68,
                                                                              a6: 0);
                                                                      if ( v19 >= 0 )
                                                                      {
                                                                        v19 = D3DXShader::CCompiler::EmitInst(
                                                                                (char **)this,
                                                                                a2,
                                                                                a3: v91 | 0x20300000,
                                                                                a4: v72,
                                                                                a5: v68,
                                                                                a6: (unsigned int)v71 | 0x1700000000LL);
                                                                        if ( v19 >= 0 )
                                                                        {
                                                                          v19 = D3DXShader::CCompiler::EmitInst(
                                                                                  (char **)this,
                                                                                  a2,
                                                                                  a3: v93,
                                                                                  a4: v73,
                                                                                  a5: v70,
                                                                                  a6: (unsigned int)v72 | 0x1700000000LL);
                                                                          if ( v19 >= 0 )
                                                                          {
                                                                            v19 = D3DXShader::CCompiler::EmitInst(
                                                                                    (char **)this,
                                                                                    a2,
                                                                                    a3: v92,
                                                                                    a4: v74,
                                                                                    a5: v66,
                                                                                    a6: (unsigned int)v66);
                                                                            if ( v19 >= 0 )
                                                                            {
                                                                              v19 = D3DXShader::CCompiler::EmitInst(
                                                                                      (char **)this,
                                                                                      a2,
                                                                                      a3: v90,
                                                                                      a4: v75,
                                                                                      a5: v74,
                                                                                      a6: 0);
                                                                              if ( v19 >= 0 )
                                                                              {
                                                                                v19 = D3DXShader::CCompiler::EmitInst(
                                                                                        (char **)this,
                                                                                        a2,
                                                                                        a3: v93,
                                                                                        a4: v76,
                                                                                        a5: v73,
                                                                                        a6: (unsigned int)v75);
                                                                                if ( v19 >= 0 )
                                                                                {
                                                                                  v10 = D3DXShader::CCompiler::EmitInst(
                                                                                          (char **)this,
                                                                                          a2,
                                                                                          a3: v92,
                                                                                          a4: a5,
                                                                                          a5: v66,
                                                                                          a6: (unsigned int)v76);
                                                                                  goto LABEL_57;
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
                    }
                  }
                }
              }
            }
          }
          break;
        }
        v17 = a6;
      }
    }
    else
    {
      v19 = -2147024882;
    }
  }
  else
  {
    v8 = a6 & 0xFFFFF;
    HIDWORD(v30) = 0;
    if ( a4 != nullptr )
    {
      LODWORD(v30) = a4;
      v9 = v8 | 0x20600000;
    }
    else
    {
      LODWORD(v30) = 0;
      v9 = v8 | 0x10C00000;
    }
    v10 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v9, a4: a5, a5: a3, a6: v30);
LABEL_57:
    v19 = v10;
    if ( v10 >= 0 )
      v19 = 0;
  }
  free(pMem);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x101CD064
// Name: protected: long D3DXShader::CCompiler::EmitLerp(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitLerp(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int *a6,
        unsigned int a7)
{
  int v8; // eax
  unsigned int i; // edx
  unsigned int v11; // ecx
  char *v12; // ecx
  unsigned int v13; // eax
  unsigned int *v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // esi
  unsigned int v18; // edi
  int v19; // eax
  unsigned int *v20; // ecx
  unsigned int k; // eax
  unsigned int v22; // edi
  unsigned int *v24; // edx
  unsigned int m; // eax
  unsigned int n; // eax
  unsigned int v27; // edi
  unsigned int v28; // edi
  unsigned int *v29; // [esp+Ch] [ebp-18h]
  unsigned int *v30; // [esp+10h] [ebp-14h]
  unsigned int *v31; // [esp+14h] [ebp-10h]
  unsigned int *v32; // [esp+18h] [ebp-Ch]
  unsigned int *v33; // [esp+1Ch] [ebp-8h]
  void *pMem; // [esp+20h] [ebp-4h]
  unsigned int *j; // [esp+34h] [ebp+10h]
  unsigned int *v36; // [esp+38h] [ebp+14h]
  unsigned int v37; // [esp+40h] [ebp+1Ch]
  int v38; // [esp+40h] [ebp+1Ch]

  v8 = *((_DWORD *)this + 2);
  pMem = *(void **)(v8 + 108);
  if ( (char)pMem < 0 )
  {
    for ( i = 0; i < a7; ++i )
    {
      v11 = a6[i];
      if ( (**(_BYTE **)(*(_DWORD *)(v8 + 20) + 4 * v11) & 1) == 0 || ((unsigned __int8)pMem & 4) != 0 && v11 != *a6 )
        break;
    }
    if ( i == a7 )
    {
      v12 = (char *)MemAlloc_Alloc(nSize: 12 * a7);
      pMem = v12;
      if ( v12 != nullptr )
      {
        v13 = 0;
        v37 = 4 * a7;
        do
        {
          (&v31)[v13++] = (unsigned int *)v12;
          v12 += 4 * a7;
        }
        while ( v13 < 3 );
        if ( a7 != 0 )
        {
          v14 = v32;
          v36 = (unsigned int *)((char *)a5 - (char *)v32);
          v15 = (char *)a4 - (char *)v32;
          v16 = (char *)v33 - (char *)v32;
          for ( j = (unsigned int *)a7; j != nullptr; j = (unsigned int *)((char *)j - 1) )
          {
            *v14 = *(unsigned int *)((char *)v14 + v15);
            *(unsigned int *)((char *)v14 + v16) = *(unsigned int *)((char *)v14 + (_DWORD)v36);
            ++v14;
          }
        }
        v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v31, a3: a7);
        if ( v17 >= 0 )
        {
          v17 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a7);
          if ( v17 >= 0 )
          {
            v18 = a7 & 0xFFFFF;
            v17 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (unsigned int)&loc_10100000 | v18,
                    a4: v31,
                    a5: a6,
                    a6: 0x1A00000000LL);
            if ( v17 >= 0 )
            {
              v19 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: v18 | 0x30000000,
                      a4: a3,
                      a5: v31,
                      a6: (unsigned int)pMem + v37);
              goto LABEL_30;
            }
          }
        }
        goto LABEL_32;
      }
LABEL_34:
      v17 = -2147024882;
      goto LABEL_32;
    }
  }
  if ( (HIBYTE(pMem) & 2) == 0 )
  {
    pMem = MemAlloc_Alloc(nSize: 12 * a7);
    if ( pMem != nullptr )
    {
      v20 = (unsigned int *)pMem;
      for ( k = 0; k < 3; ++k )
      {
        (&v31)[k] = v20;
        v20 += a7;
      }
      v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v31, a3: a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v32, a3: a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v33, a3: a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a7);
      if ( v17 < 0 )
        goto LABEL_32;
      v22 = a7 & 0xFFFFF;
      v17 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | a7 & 0xFFFFF,
              a4: v31,
              a5: a4,
              a6: 0);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v22 | 0x20400000, a4: v32, a5, a6: (unsigned int)v31);
      if ( v17 < 0 )
        goto LABEL_32;
      v17 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v22 | 0x20500000,
              a4: v33,
              a5: a6,
              a6: (unsigned int)v32);
      if ( v17 < 0 )
        goto LABEL_32;
      v19 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v22 | 0x20400000,
              a4: a3,
              a5: a4,
              a6: (unsigned int)v33);
      goto LABEL_30;
    }
    goto LABEL_34;
  }
  pMem = MemAlloc_Alloc(nSize: 20 * a7);
  if ( pMem == nullptr )
    goto LABEL_34;
  v24 = (unsigned int *)pMem;
  for ( m = 0; m < 5; ++m )
  {
    (&v29)[m] = v24;
    v24 += a7;
  }
  for ( n = 0; n < a7; ++n )
    v33[n] = *((_DWORD *)this + 8);
  v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v29, a3: a7);
  if ( v17 >= 0 )
  {
    v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v30, a3: a7);
    if ( v17 >= 0 )
    {
      v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v31, a3: a7);
      if ( v17 >= 0 )
      {
        v17 = D3DXShader::CCompiler::EmitTemp(this, a2: v32, a3: a7);
        if ( v17 >= 0 )
        {
          v17 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a7);
          if ( v17 >= 0 )
          {
            v27 = a7 & 0xFFFFF;
            v17 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (unsigned int)&loc_10100000 | a7 & 0xFFFFF,
                    a4: v29,
                    a5: a6,
                    a6: 0);
            if ( v17 >= 0 )
            {
              v38 = v27 | 0x20400000;
              v17 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: v27 | 0x20400000,
                      a4: v30,
                      a5: v29,
                      a6: (unsigned int)v33);
              if ( v17 >= 0 )
              {
                v28 = v27 | 0x20500000;
                v17 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: v28,
                        a4: v31,
                        a5: v30,
                        a6: (unsigned int)a4);
                if ( v17 >= 0 )
                {
                  v17 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: v28,
                          a4: v32,
                          a5: a6,
                          a6: (unsigned int)a5);
                  if ( v17 >= 0 )
                  {
                    v19 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: v38,
                            a4: a3,
                            a5: v31,
                            a6: (unsigned int)v32);
LABEL_30:
                    v17 = v19;
                    if ( v19 >= 0 )
                      v17 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_32:
  free(pMem);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x101CD40D
// Name: protected: long D3DXShader::CCompiler::EmitPow(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitPow(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int a6)
{
  unsigned int v7; // esi
  unsigned int v8; // eax
  bool v9; // zf
  void *v11; // edx
  unsigned int i; // ecx
  int v13; // eax
  unsigned int *v14; // edx
  int m; // esi
  int v16; // eax
  bool v17; // zf
  int v18; // ecx
  unsigned int v19; // eax
  int j; // edx
  unsigned int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  int v24; // ecx
  unsigned int k; // eax
  int v26; // edx
  unsigned int *v27; // edx
  unsigned int n; // eax
  unsigned int v29; // edi
  __int64 v31; // [esp-8h] [ebp-2Ch]
  double v32; // [esp+Ch] [ebp-18h] BYREF
  unsigned int *v33[2]; // [esp+14h] [ebp-10h] BYREF
  int v34; // [esp+1Ch] [ebp-8h]
  void *pMem; // [esp+20h] [ebp-4h]
  unsigned int *v36; // [esp+38h] [ebp+14h]
  unsigned int v37; // [esp+3Ch] [ebp+18h]

  v7 = 0;
  v8 = 1;
  v9 = a6 == 0;
  pMem = nullptr;
  v34 = 1;
  v33[1] = (unsigned int *)1;
  if ( a6 != 0 )
  {
    do
    {
      if ( D3DXShader::CCompiler::EvalValue(this, a2: a4[v7], a3: &v32) < 0 )
        break;
      if ( v32 != 0.0 )
        v34 = 0;
      if ( v32 != 1.0 )
        v33[1] = nullptr;
      ++v7;
    }
    while ( v7 < a6 );
    v8 = 1;
    v9 = v7 == a6;
  }
  if ( v9 && (v34 != 0 || v33[1] != nullptr) )
  {
    v11 = MemAlloc_Alloc(nSize: 4 * a6);
    pMem = v11;
    if ( v11 != nullptr )
    {
      for ( i = 0; i < a6; ++i )
      {
        if ( v34 != 0 )
          v13 = *((_DWORD *)this + 9);
        else
          v13 = *((_DWORD *)this + 8);
        *((_DWORD *)v11 + i) = v13;
      }
      m = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a6);
      if ( m < 0 )
        goto LABEL_70;
      v16 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: a6 & 0xFFFFF | 0x10000000, a4: a3, a5: v14, a6: 0);
      goto LABEL_68;
    }
LABEL_59:
    m = -2147024882;
    goto LABEL_70;
  }
  v17 = a6 == 1;
  if ( a6 > 1 )
  {
    do
    {
      if ( *a5 != a5[v8] )
        break;
      ++v8;
    }
    while ( v8 < a6 );
    v17 = v8 == a6;
  }
  if ( !v17 || D3DXShader::CCompiler::EvalValue(this, a2: *a5, a3: (double *)v33) < 0 )
    goto LABEL_58;
  v34 = (__int64)*(double *)v33;
  if ( fabs(*(double *)v33 - (double)v34) < 0.000001 )
  {
    v18 = 0;
    v19 = abs32(v34);
    v37 = v19;
    for ( j = 0; v19 != 0; v19 >>= 1 )
    {
      ++v18;
      j += v19 & 1;
    }
    v21 = (v18 != 0 ? v18 - 1 : 0) + (j != 0 ? j - 1 : 0);
    if ( v34 < 0 )
      v21 += a6;
    v22 = *((_DWORD *)this + 2);
    if ( (*(_BYTE *)(v22 + 108) & 0x40) != 0 && (*((_BYTE *)this + 20) & 0x20) != 0 )
    {
      v23 = a6 + 1;
    }
    else
    {
      v24 = *(_DWORD *)(v22 + 100);
      if ( v24 == 0 )
        v24 = 1;
      v23 = 2 * a6 * v24 + 1;
    }
    if ( v21 <= v23 )
    {
      pMem = MemAlloc_Alloc(nSize: 4 * a6);
      if ( pMem == nullptr )
        goto LABEL_59;
      for ( k = 0; k < a6; ++k )
        *((_DWORD *)pMem + k) = *((_DWORD *)this + 8);
      m = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a6);
      if ( m < 0 )
        goto LABEL_70;
      v36 = (unsigned int *)(a6 & 0xFFFFF);
      HIBYTE(v36) = 16;
      v33[1] = (unsigned int *)(a6 & 0xFFFFF);
      m = D3DXShader::CCompiler::EmitInst(
            (char **)this,
            a2,
            a3: (unsigned int)v36,
            a4: a3,
            a5: (unsigned int *)pMem,
            a6: 0);
      if ( m < 0 )
        goto LABEL_70;
      if ( v37 != 0 )
      {
        m = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)pMem, a3: a6);
        if ( m >= v26 )
        {
          HIDWORD(v31) = v26;
          LODWORD(v31) = v26;
          for ( m = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: (unsigned int)v36,
                      a4: (unsigned int *)pMem,
                      a5: a4,
                      a6: v31);
                m >= 0;
                m = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: (int)v33[1] | 0x20500000,
                      a4: (unsigned int *)pMem,
                      a5: (unsigned int *)pMem,
                      a6: (unsigned int)pMem | 0x400000000LL) )
          {
            if ( (v37 & 1) != 0 )
            {
              m = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (int)v33[1] | 0x20500000,
                    a4: a3,
                    a5: a3,
                    a6: (unsigned int)pMem);
              if ( m < 0 )
                break;
            }
            v37 >>= 1;
            if ( v37 == 0 )
              goto LABEL_51;
          }
        }
        goto LABEL_70;
      }
LABEL_51:
      if ( v34 < 0 )
      {
        v16 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                a2,
                a3: (unsigned int)&unk_10300000 | (unsigned int)v33[1],
                a4: a3,
                a5: a3,
                a6: 0);
        goto LABEL_68;
      }
LABEL_69:
      m = 0;
      goto LABEL_70;
    }
    goto LABEL_58;
  }
  if ( fabs(fabs(*(long double *)v33) - 0.5) >= 0.000001 )
  {
LABEL_58:
    pMem = MemAlloc_Alloc(nSize: 8 * a6);
    if ( pMem == nullptr )
      goto LABEL_59;
    v27 = (unsigned int *)pMem;
    for ( n = 0; n < 2; ++n )
    {
      v33[n] = v27;
      v27 += a6;
    }
    m = D3DXShader::CCompiler::EmitTemp(this, a2: v33[0], a3: a6);
    if ( m < 0 )
      goto LABEL_70;
    m = D3DXShader::CCompiler::EmitTemp(this, a2: v33[1], a3: a6);
    if ( m < 0 )
      goto LABEL_70;
    m = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a6);
    if ( m < 0 )
      goto LABEL_70;
    v29 = a6 & 0xFFFFF;
    m = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v29 | 0x10600000, a4: v33[0], a5: a4, a6: 0);
    if ( m < 0 )
      goto LABEL_70;
    m = D3DXShader::CCompiler::EmitInst(
          (char **)this,
          a2,
          a3: v29 | 0x20500000,
          a4: v33[1],
          a5,
          a6: (unsigned int)v33[0]);
    if ( m < 0 )
      goto LABEL_70;
    v16 = D3DXShader::CCompiler::EmitInst(
            (char **)this,
            a2,
            a3: v29 | 0x10500000,
            a4: a3,
            a5: v33[1],
            a6: 0x400000000LL);
    goto LABEL_68;
  }
  m = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: a6);
  if ( m >= 0 )
  {
    m = D3DXShader::CCompiler::EmitInst(
          (char **)this,
          a2,
          a3: a6 & 0xFFFFF | 0x10700000,
          a4: a3,
          a5: a4,
          a6: 0x400000000LL);
    if ( m < 0 )
      goto LABEL_70;
    if ( *(double *)v33 < 0.0 )
      goto LABEL_69;
    v16 = D3DXShader::CCompiler::EmitInst(
            (char **)this,
            a2,
            a3: (unsigned int)&unk_10300000 | a6 & 0xFFFFF,
            a4: a3,
            a5: a3,
            a6: 0x400000000LL);
LABEL_68:
    m = v16;
    if ( v16 >= 0 )
      goto LABEL_69;
  }
LABEL_70:
  free(pMem);
  return m;
}

//------------------------------------------------------------------------------
// Address: 0x101CD839
// Name: protected: long D3DXShader::CCompiler::EmitClip(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitClip(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int a4)
{
  char *v6; // edx
  unsigned int i; // eax
  int v8; // edx
  unsigned int j; // eax
  unsigned int v10; // edx
  unsigned int k; // edx
  int v12; // ecx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v17; // [esp+8h] [ebp-10h]
  unsigned int *v18; // [esp+Ch] [ebp-Ch]
  unsigned int *v19; // [esp+10h] [ebp-8h]
  void *pMem; // [esp+14h] [ebp-4h]
  signed int v21; // [esp+28h] [ebp+10h]

  v6 = (char *)MemAlloc_Alloc(nSize: 12 * a4);
  pMem = v6;
  if ( v6 != nullptr )
  {
    for ( i = 0; i < 3; ++i )
    {
      *(&v17 + i) = (int)v6;
      v6 += 4 * a4;
    }
    v8 = v17;
    for ( j = 0; j < a4; ++j )
      *(_DWORD *)(v8 + 4 * j) = *((_DWORD *)this + 11);
    v21 = D3DXShader::CCompiler::EmitTemp(this, a2: v18, a3: a4);
    if ( v21 >= 0 )
    {
      v21 = D3DXShader::CCompiler::EmitTemp(this, a2: v19, a3: a4);
      if ( v21 >= 0 )
      {
        v21 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                a2,
                a3: a4 & 0xFFFFF | 0x20500000,
                a4: v18,
                a5: a3,
                a6: v10);
        if ( v21 >= 0 )
        {
          v21 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: a4 & 0xFFFFF | 0x11000000,
                  a4: v19,
                  a5: v18,
                  a6: 0);
          if ( v21 >= 0 )
          {
            for ( k = 0; k < a4; v13[3] = v14 )
            {
              v12 = *((_DWORD *)this + 2);
              v13 = *(_DWORD **)(*(_DWORD *)(v12 + 20) + 4 * v19[k]);
              v13[1] = *(_DWORD *)(v12 + 168);
              v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 16)
                                          + 4 * *(_DWORD *)(*((_DWORD *)this + 2) + 168))
                              + 8);
              v13[4] = k++;
            }
            v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 16) + 4 * *(_DWORD *)(*((_DWORD *)this + 2) + 168));
            ++*(_DWORD *)(v15 + 8);
            v21 = 0;
          }
        }
      }
    }
  }
  else
  {
    v21 = -2147024882;
  }
  free(pMem);
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x101CD96E
// Name: protected: long D3DXShader::CCompiler::EmitPositive(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitPositive(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        unsigned int a6)
{
  bool v7; // zf
  void *v9; // ebx
  int v10; // edi
  unsigned int v11; // eax
  unsigned int *v12; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // esi
  int v16; // eax
  unsigned int *v17; // edi
  unsigned int *v18; // esi
  unsigned int *v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // edx
  D3DXShader::CCompiler *v23; // esi
  unsigned int i; // eax
  unsigned int j; // ecx
  _DWORD *v26; // eax
  unsigned int *v28; // [esp+Ch] [ebp-18h]
  unsigned int *v29; // [esp+10h] [ebp-14h]
  unsigned int *v30; // [esp+14h] [ebp-10h]
  void *pMem; // [esp+18h] [ebp-Ch]
  unsigned int v32; // [esp+1Ch] [ebp-8h]
  D3DXShader::CCompiler *v33; // [esp+20h] [ebp-4h]
  unsigned int *v34; // [esp+38h] [ebp+14h]
  unsigned int v35; // [esp+3Ch] [ebp+18h]

  v7 = (*(_BYTE *)(*((_DWORD *)this + 2) + 113) & 0x10) == 0;
  v33 = this;
  if ( v7 )
  {
    v9 = MemAlloc_Alloc(nSize: 8 * a6);
    pMem = v9;
    if ( v9 != nullptr )
    {
      v10 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)v9, a3: 2 * a6);
      if ( v10 >= 0 )
      {
        v11 = 0;
        v35 = 4 * a6;
        v12 = (unsigned int *)v9;
        do
        {
          (&v28)[v11++] = v12;
          v12 += a6;
        }
        while ( v11 < 2 );
        v14 = 0;
        v32 = 4;
        if ( a6 == 0 )
          goto LABEL_10;
        v34 = *(unsigned int **)(*((_DWORD *)v33 + 2) + 20);
        do
          v32 = *(_BYTE *)v34[a5[v14++]] & 4 & (unsigned __int8)v32;
        while ( v14 < a6 );
        if ( v32 == 0 )
        {
          v15 = a6 & 0xFFFFF;
          v16 = D3DXShader::CCompiler::EmitInst(
                  this: (char **)v33,
                  a2,
                  a3: v15 | 0x20500000,
                  a4: v28,
                  a5,
                  a6: (unsigned int)a5 | 0x400000000LL);
        }
        else
        {
LABEL_10:
          v15 = a6 & 0xFFFFF;
          v16 = D3DXShader::CCompiler::EmitInst(
                  this: (char **)v33,
                  a2,
                  a3: v15 | 0x10000000,
                  a4: v28,
                  a5,
                  a6: 0x400000000LL);
        }
        v10 = v16;
        if ( v16 >= 0 )
        {
          v10 = D3DXShader::CCompiler::EmitInst(
                  this: (char **)v33,
                  a2,
                  a3: (unsigned int)&loc_10100000 | v15,
                  a4: v29,
                  a5: v28,
                  a6: 0x800000000LL);
          if ( v10 >= 0 )
          {
            if ( a3 != nullptr )
              qmemcpy(a3, v28, v35);
            v17 = a4;
            if ( a4 != nullptr )
            {
              v18 = v29;
LABEL_36:
              qmemcpy(v17, v18, v35);
            }
LABEL_37:
            v10 = 0;
            goto LABEL_38;
          }
        }
      }
      goto LABEL_38;
    }
LABEL_19:
    v10 = -2147024882;
    goto LABEL_38;
  }
  pMem = MemAlloc_Alloc(nSize: 12 * a6);
  if ( pMem == nullptr )
    goto LABEL_19;
  v10 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)pMem, a3: 3 * a6);
  if ( v10 >= 0 )
  {
    v20 = (unsigned int *)pMem;
    v21 = 0;
    v22 = 4 * a6;
    v35 = 4 * a6;
    do
    {
      (&v28)[v21++] = v20;
      v20 = (unsigned int *)((char *)v20 + v22);
    }
    while ( v21 < 3 );
    v32 = a6 & 0xFFFFF | 0x10100000;
    v10 = D3DXShader::CCompiler::EmitInst(this: (char **)v33, a2, a3: v32, a4: v28, a5, a6: 0);
    if ( v10 >= 0 )
    {
      v23 = v33;
      v10 = D3DXShader::CCompiler::EmitInst(
              this: (char **)v33,
              a2,
              a3: a6 & 0xFFFFF | 0x20100000,
              a4: v29,
              a5,
              a6: (unsigned int)v28 | 0x400000000LL);
      if ( v10 >= 0 )
      {
        v10 = D3DXShader::CCompiler::EmitInst(this: (char **)v23, a2, a3: v32, a4: v30, a5: v29, a6: 0x800000000LL);
        if ( v10 >= 0 )
        {
          for ( i = 0; i < a6; ++i )
          {
            if ( (**(_BYTE **)(*(_DWORD *)(*((_DWORD *)v23 + 2) + 20) + 4 * a5[i]) & 0x17) == 0 )
              break;
          }
          if ( i == a6 )
          {
            for ( j = 0; j < a6; ++j )
            {
              v26 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)v23 + 2) + 20) + 4 * v29[j]);
              *v26 |= 0x17u;
            }
          }
          if ( a3 != nullptr )
            qmemcpy(a3, v29, v35);
          v17 = a4;
          if ( a4 == nullptr )
            goto LABEL_37;
          v18 = v30;
          goto LABEL_36;
        }
      }
    }
  }
LABEL_38:
  free(pMem);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101CDBF0
// Name: protected: long D3DXShader::CCompiler::Vectorize(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int,int,int,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::Vectorize(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6,
        struct D3DXShader::CNode *a7,
        struct D3DXShader::CNode *a8)
{
  D3DXShader::CBaseProgram *v10; // ecx
  struct D3DXShader::CPool *v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  unsigned int v17; // [esp+4h] [ebp-4h] BYREF

  if ( a2 == nullptr )
    return 0;
  v10 = *((D3DXShader::CBaseProgram **)this + 2);
  v17 = 0;
  if ( a4 >= *((_DWORD *)v10 + 1) )
    v11 = nullptr;
  else
    v11 = *(struct D3DXShader::CPool **)(*((_DWORD *)v10 + 4) + 4 * a4);
  if ( v11 == nullptr )
    return -2147467259;
  v12 = D3DXShader::CBaseProgram::CopyPool(this: v10, a2: v11);
  v13 = *((_DWORD *)this + 2);
  if ( v12 >= *(_DWORD *)(v13 + 4) )
    v14 = 0;
  else
    v14 = *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * v12);
  if ( v14 == 0 )
    return -2147024882;
  *(_DWORD *)(v14 + 4) |= 0x40u;
  v15 = *(_DWORD *)(v14 + 4);
  if ( (v15 & 0x10) != 0 && (v15 & 0x80u) == 0 )
  {
    if ( (v15 & 0x200) != 0 && (*(_DWORD *)(*((_DWORD *)this + 2) + 112) & 0x200) != 0 )
      *(_DWORD *)(v14 + 4) = v15 | 0x400;
    v16 = *(_DWORD *)(v14 + 4);
    if ( (v16 & 0x200) == 0 && (*(_DWORD *)(*((_DWORD *)this + 2) + 112) & 0x400) != 0 )
      *(_DWORD *)(v14 + 4) = v16 | 0x100400;
  }
  return D3DXShader::CCompiler::VectorizeVar(this, a2, a3, a4: v12, a5, a6, a7, a8: &v17, a9: a7, a10: a8, a11: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101CDCC4
// Name: protected: long D3DXShader::CCompiler::Unalias(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::Unalias(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode **a2,
        unsigned int *a3,
        unsigned int a4)
{
  unsigned int *v5; // edx
  _DWORD *v6; // eax
  _DWORD *v7; // ecx
  unsigned int v8; // ebx
  D3DXShader::CBaseProgram *v9; // ecx
  int v10; // esi
  unsigned int v11; // eax
  int v12; // eax
  int result; // eax
  int v14; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]

  v14 = 1;
  if ( a4 != 0 )
  {
    v5 = a3;
    for ( i = a4; i != 0; --i )
    {
      v6 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v5);
      if ( v6[13] != -1 )
      {
        do
        {
          if ( v6[2] != -1 )
            break;
          v7 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v6[13]);
          if ( v7[24] == 0 )
          {
            v7[24] = v6[24];
            v7[25] = v6[25];
          }
          *v5 = v6[13];
          v6 = v7;
        }
        while ( v7[13] != -1 );
      }
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 16) + 4 * v6[1]) + 5) & 1) == 0 || v6[2] != -1 )
        v14 = 0;
      ++v5;
    }
  }
  v8 = 0;
  if ( a2 == nullptr || v14 == 0 )
    return 0;
  if ( a4 == 0 )
  {
LABEL_17:
    result = D3DXShader::CCompiler::Vectorize(
               this,
               a2,
               a3,
               a4: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
               a5: 1,
               a6: 1,
               a7: nullptr,
               a8: nullptr);
    if ( result < 0 )
      return result;
    return 0;
  }
  while ( 1 )
  {
    v9 = *((D3DXShader::CBaseProgram **)this + 2);
    v10 = *(_DWORD *)(*((_DWORD *)v9 + 5) + 4 * a3[v8]);
    v11 = D3DXShader::CBaseProgram::AddArgument(
            this: v9,
            a2: *((_DWORD *)v9 + 30),
            a3: 0,
            a4: 0,
            a5: *(double *)(v10 + 32));
    a3[v8] = v11;
    if ( v11 == -1 )
      return -2147024882;
    v12 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v11);
    *(_DWORD *)(v12 + 96) = *(_DWORD *)(v10 + 96);
    ++v8;
    *(_DWORD *)(v12 + 100) = *(_DWORD *)(v10 + 100);
    if ( v8 >= a4 )
      goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDDD2
// Name: protected: int D3DXShader::CCompiler::IsLimited(unsigned int,unsigned int,unsigned int __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CCompiler::IsLimited(
        D3DXShader::CCompiler *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int *a5)
{
  unsigned int i; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // edi
  unsigned int *v11; // ebx
  int v12; // esi
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // eax
  int v16; // eax
  unsigned int *v17; // eax
  int v18; // ecx
  int v19; // eax
  int *v20; // edi
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  _DWORD *v26; // ecx
  _DWORD *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // eax
  _DWORD *v30; // edx
  int v31; // eax
  int v32; // edi
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  _DWORD *v36; // edx
  _DWORD *v37; // ecx
  _DWORD *v38; // edx
  unsigned int v39; // edi
  unsigned int v40; // ebx
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  double v44; // [esp+Ch] [ebp-24h] BYREF
  double v45; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD *v46; // [esp+1Ch] [ebp-14h]
  int v47; // [esp+20h] [ebp-10h]
  unsigned int v48; // [esp+24h] [ebp-Ch] BYREF
  unsigned int v49; // [esp+28h] [ebp-8h]
  unsigned int v50; // [esp+2Ch] [ebp-4h]

  for ( i = a2; ; i = *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4) )
  {
    while ( 1 )
    {
      if ( i == -1 )
        return false;
      v7 = *((_DWORD *)this + 2);
      v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 20) + 4 * i) + 72);
      if ( v8 == -1 )
        return false;
      v9 = *(_DWORD *)(*(_DWORD *)(v7 + 24) + 4 * v8);
      if ( *(_DWORD *)v9 != 268435457 )
        break;
LABEL_10:
      i = **(_DWORD **)(v9 + 8);
    }
    if ( *(_DWORD *)v9 != 542113793 )
      break;
    if ( D3DXShader::CCompiler::EvalValue(this, a2: **(_DWORD **)(v9 + 8), a3: &v45) < 0 || 1.0 != v45 )
    {
      if ( D3DXShader::CCompiler::EvalValue(this, a2: *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4), a3: &v45) < 0 || 1.0 != v45 )
        return false;
      goto LABEL_10;
    }
  }
  if ( *(_DWORD *)v9 == 538968065 )
  {
    if ( D3DXShader::CCompiler::EvalValue(this, a2: **(_DWORD **)(v9 + 8), a3: &v45) >= 0 && v45 == (double)a3 )
    {
      a2 = *(_DWORD *)(*(_DWORD *)(v9 + 8) + 4);
      if ( D3DXShader::CCompiler::Unalias(this, a2: nullptr, a3: &a2, a4: 1u) >= 0 )
      {
        v11 = a5;
        if ( *a5 != -1 )
          return a2 == *a5;
        v12 = *((_DWORD *)this + 2);
        v13 = *(_DWORD *)(v12 + 20);
        v14 = a2;
        v15 = *(_DWORD *)(v13 + 4 * a2);
        if ( (*(_BYTE *)v15 & 2) != 0 )
        {
          v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * *(_DWORD *)(v15 + 4)) + 4);
          if ( (v16 & 0x100) == 0 && (v16 & 0x10) != 0 && (v16 & 0x200) != 0 )
          {
            v17 = a4;
            if ( a4 != nullptr )
            {
              v18 = *(_DWORD *)(v13 + 4 * **(_DWORD **)(v9 + 8));
              goto LABEL_25;
            }
            goto LABEL_26;
          }
        }
      }
    }
    return false;
  }
  if ( *(_DWORD *)v9 != 805306369 )
    return false;
  v19 = *((_DWORD *)this + 2);
  v20 = *(int **)(v9 + 8);
  v21 = *(_DWORD *)(*(_DWORD *)(v19 + 20) + 4 * v20[1]);
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v19 + 16) + 4 * *(_DWORD *)(v21 + 4)) + 4) & 0x100) == 0 )
    return false;
  if ( *(_DWORD *)(v21 + 8) != -1 )
    return false;
  if ( 0.0 != *(double *)(v21 + 32) )
    return false;
  v22 = *((_DWORD *)this + 2);
  v23 = *(_DWORD *)(*(_DWORD *)(v22 + 20) + 4 * v20[2]);
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * *(_DWORD *)(v23 + 4)) + 4) & 0x100) == 0 )
    return false;
  if ( *(_DWORD *)(v23 + 8) != -1 )
    return false;
  if ( 1.0 != *(double *)(v23 + 32) )
    return false;
  v24 = *((_DWORD *)this + 2);
  v25 = *v20;
  v26 = *(_DWORD **)(*(_DWORD *)(v24 + 20) + 4 * v25);
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v24 + 16) + 4 * v26[1]) + 4) & 2) == 0 )
    return false;
  if ( v26[2] != -1 )
    return false;
  v27 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * v26[18]);
  v28 = *v27 & 0xFFF00000;
  v46 = v27;
  if ( v28 != 541065216 )
    return false;
  v29 = v27[3];
  a2 = 0;
  if ( v29 != 0 )
  {
    v30 = (_DWORD *)v27[4];
    do
    {
      if ( *v30 == v25 )
        break;
      ++a2;
      ++v30;
    }
    while ( a2 < v29 );
  }
  v49 = 0;
  v47 = 1;
  while ( 2 )
  {
    v31 = v27[3];
    v32 = v27[2];
    v33 = *((_DWORD *)this + 2);
    v34 = *(_DWORD *)(v33 + 20);
    v35 = *(_DWORD *)(v33 + 16);
    HIDWORD(v45) = *(_DWORD *)(v32 + 4 * (a2 + v49 * v31));
    v36 = *(_DWORD **)(v34 + 4 * HIDWORD(v45));
    if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * v36[1]) + 4) & 2) == 0 )
      goto LABEL_61;
    if ( v36[2] != -1 )
      goto LABEL_61;
    v37 = *(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * v36[18]);
    if ( (_UNKNOWN *)(*v37 & 0xFFF00000) != &loc_10100000 )
      goto LABEL_61;
    v50 = 0;
    if ( v37[3] != 0 )
    {
      v38 = (_DWORD *)v37[4];
      do
      {
        if ( *v38 == HIDWORD(v45) )
          break;
        ++v50;
        ++v38;
      }
      while ( v50 < v37[3] );
    }
    v39 = *(_DWORD *)(v32 + 4 * (a2 + v47 * v31));
    v40 = *(_DWORD *)(v37[2] + 4 * v50);
    if ( D3DXShader::CCompiler::EvalValue(this, a2: v39, a3: &v44) < 0 )
      goto LABEL_61;
    if ( v44 != (double)a3 )
      goto LABEL_61;
    v48 = v40;
    if ( D3DXShader::CCompiler::Unalias(this, a2: nullptr, a3: &v48, a4: 1u) < 0 )
      goto LABEL_61;
    v11 = a5;
    if ( *a5 != -1 )
    {
      if ( v48 == *a5 )
        return true;
      goto LABEL_61;
    }
    v41 = *((_DWORD *)this + 2);
    v14 = v48;
    v42 = *(_DWORD *)(*(_DWORD *)(v41 + 20) + 4 * v48);
    if ( (*(_BYTE *)v42 & 2) == 0
      || ((v43 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 16) + 4 * *(_DWORD *)(v42 + 4)) + 4)) & 0x100) != 0
      || (v43 & 0x10) == 0
      || (v43 & 0x200) == 0 )
    {
LABEL_61:
      ++v49;
      --v47;
      if ( v49 >= 2 )
        return false;
      v27 = v46;
      continue;
    }
    break;
  }
  v17 = a4;
  if ( a4 != nullptr )
  {
    v18 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v39);
LABEL_25:
    *v17 = *(_DWORD *)(v18 + 48);
  }
LABEL_26:
  *v11 = v14;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101CE187
// Name: protected: long D3DXShader::CCompiler::EmitIf(class D3DXShader::CNode __near *,unsigned int,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitIf(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CNode *m)
{
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // eax
  unsigned int v11; // edx
  _DWORD *i; // edi
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  int v16; // edx
  int v17; // esi
  _DWORD *v18; // esi
  _DWORD *v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ecx
  int v25; // esi
  bool v26; // zf
  int v27; // eax
  int v28; // eax
  _DWORD *v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  _DWORD *v34; // eax
  int v35; // ecx
  unsigned int v36; // eax
  char *v37; // edi
  char *v38; // esi
  char *v39; // edi
  char *v40; // esi
  char v41; // cl
  int v42; // eax
  int v43; // eax
  int v44; // eax
  unsigned int v45; // eax
  char *v46; // edi
  char *v47; // esi
  char *v48; // edi
  char *v49; // esi
  char v50; // cl
  int v51; // eax
  int v52; // eax
  int v53; // eax
  struct D3DXShader::CNode *v54; // edx
  _DWORD *v55; // eax
  unsigned int v56; // eax
  int v57; // ecx
  unsigned int v58; // edx
  _DWORD **v59; // ecx
  unsigned int v60; // esi
  unsigned int j; // esi
  D3DXShader::CInstruction *v62; // ecx
  void *v63; // esi
  unsigned int *v64; // eax
  unsigned int v65; // eax
  int v66; // eax
  int v67; // eax
  unsigned int *v68; // eax
  unsigned int v69; // eax
  int v70; // ecx
  int *v71; // ecx
  int v72; // edx
  int v73; // eax
  int v74; // ecx
  int v75; // edx
  int v76; // esi
  int v77; // edx
  unsigned int v78; // edx
  unsigned int v79; // edx
  unsigned int v80; // edi
  char *v81; // edx
  unsigned int k; // eax
  unsigned int *v83; // eax
  unsigned int *v84; // esi
  int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // ecx
  int v89; // eax
  unsigned int v90; // edi
  unsigned int v91; // ecx
  int v92; // eax
  int v93; // edx
  bool v94; // cf
  unsigned int v95; // ecx
  int v96; // eax
  int v97; // edx
  unsigned int v98; // ecx
  int v99; // edx
  unsigned int *v100; // edi
  int v101; // eax
  D3DXShader::CArgument *v102; // esi
  int v103; // ecx
  unsigned int v104; // edx
  BOOL v105; // eax
  int v106; // ecx
  BOOL v107; // eax
  struct D3DXShader::CNode *v109; // [esp-14h] [ebp-9Ch]
  struct D3DXShader::CNode *v110; // [esp-14h] [ebp-9Ch]
  unsigned int *v111; // [esp-10h] [ebp-98h]
  unsigned int *v112; // [esp-10h] [ebp-98h]
  unsigned int *v113; // [esp-Ch] [ebp-94h]
  unsigned int *v114; // [esp-Ch] [ebp-94h]
  __int64 v115; // [esp-8h] [ebp-90h]
  __int64 v116; // [esp-8h] [ebp-90h]
  __int64 v117; // [esp-8h] [ebp-90h]
  struct D3DXShader::CNode *v118; // [esp-8h] [ebp-90h]
  struct D3DXShader::CNode *v119; // [esp-8h] [ebp-90h]
  unsigned int *v120; // [esp-8h] [ebp-90h]
  unsigned int *v121; // [esp-4h] [ebp-8Ch]
  unsigned int *v122; // [esp-4h] [ebp-8Ch]
  unsigned int v123; // [esp-4h] [ebp-8Ch]
  unsigned int *v124; // [esp+Ch] [ebp-7Ch]
  unsigned int *v125; // [esp+10h] [ebp-78h]
  unsigned int *v126[2]; // [esp+14h] [ebp-74h] BYREF
  double v127; // [esp+1Ch] [ebp-6Ch]
  int v128; // [esp+24h] [ebp-64h]
  int v129; // [esp+28h] [ebp-60h]
  int v130; // [esp+2Ch] [ebp-5Ch]
  void *v131; // [esp+30h] [ebp-58h]
  int v132; // [esp+34h] [ebp-54h]
  unsigned int v133; // [esp+38h] [ebp-50h] BYREF
  int v134; // [esp+3Ch] [ebp-4Ch]
  int v135; // [esp+40h] [ebp-48h]
  unsigned int v136; // [esp+44h] [ebp-44h] BYREF
  int v137; // [esp+48h] [ebp-40h]
  int v138; // [esp+4Ch] [ebp-3Ch]
  int v139; // [esp+50h] [ebp-38h]
  unsigned int v140; // [esp+54h] [ebp-34h] BYREF
  unsigned int v141; // [esp+58h] [ebp-30h] BYREF
  unsigned int v142; // [esp+5Ch] [ebp-2Ch] BYREF
  unsigned int n; // [esp+60h] [ebp-28h]
  int v144; // [esp+64h] [ebp-24h]
  unsigned int v145; // [esp+68h] [ebp-20h] BYREF
  void *v146; // [esp+6Ch] [ebp-1Ch]
  void *v147; // [esp+70h] [ebp-18h]
  unsigned int v148; // [esp+74h] [ebp-14h] BYREF
  int v149; // [esp+78h] [ebp-10h]
  void *pMem; // [esp+7Ch] [ebp-Ch]
  unsigned int v151; // [esp+80h] [ebp-8h]
  struct D3DXShader::CNode *v152; // [esp+84h] [ebp-4h]

  v136 = *((_DWORD *)this + 11);
  v135 = *((_DWORD *)this + 12);
  v134 = *((_DWORD *)this + 13);
  v130 = *((_DWORD *)this + 15);
  v129 = *((_DWORD *)this + 16);
  pMem = nullptr;
  v147 = nullptr;
  v146 = nullptr;
  v131 = nullptr;
  v132 = 0;
  v139 = 0;
  v137 = 0;
  v138 = 0;
  if ( D3DXShader::CCompiler::EvalRange(this, a2: a3, a3: (struct D3DXShader::_D3DXRANGE *)v126) >= 0 )
  {
    if ( *(double *)v126 > 0.0 || v127 < 0.0 )
    {
      v6 = D3DXShader::CCompiler::EmitStatement(this, a2: (struct D3DXShader::CNode *)a4, a3: nullptr);
      goto LABEL_8;
    }
    if ( *(double *)v126 == 0.0 && v127 == 0.0 )
    {
      v6 = D3DXShader::CCompiler::EmitStatement(this, a2: m, a3: nullptr);
LABEL_8:
      v7 = v6;
      goto LABEL_219;
    }
  }
  v7 = D3DXShader::CCompiler::Unalias(this, a2: nullptr, &a3, a4: 1u);
  if ( v7 < 0 )
    goto LABEL_219;
  v141 = -1;
  v8 = *((_DWORD *)this + 2);
  v149 = *(_DWORD *)(*(_DWORD *)(v8 + 20) + 4 * a3);
  v9 = *(_DWORD *)(v149 + 72);
  if ( v9 != -1 )
  {
    v10 = *(_DWORD **)(*(_DWORD *)(v8 + 24) + 4 * v9);
    if ( (*v10 & 0xFFF00000) == 0x20300000 )
    {
      v11 = 0;
      n = v10[3];
      if ( n != 0 )
      {
        for ( i = (_DWORD *)v10[4]; *i != a3; i = (_DWORD *)v144 )
        {
          ++v11;
          v144 = (int)(i + 1);
          if ( v11 >= n )
            break;
        }
      }
      v13 = v10[2];
      v14 = *(_DWORD *)(v13 + 4 * v11);
      v15 = *(_DWORD *)(v13 + 4 * (v11 + n));
      v145 = v15;
      v16 = *(_DWORD *)(v8 + 20);
      v17 = *(_DWORD *)(*(_DWORD *)(v16 + 4 * v14) + 72);
      if ( v17 != -1 && (**(_BYTE **)(v16 + 4 * v15) & 1) != 0 )
      {
        v18 = *(_DWORD **)(*(_DWORD *)(v8 + 24) + 4 * v17);
        if ( (_UNKNOWN *)(*v18 & 0xFFF00000) == &loc_10100000 )
        {
          n = 0;
          if ( v18[3] != 0 )
          {
            v19 = (_DWORD *)v18[4];
            do
            {
              if ( *v19 == v14 )
                break;
              ++n;
              ++v19;
            }
            while ( n < v18[3] );
          }
          if ( *(_DWORD *)(v18[2] + 4 * n) == v15 )
          {
            v7 = D3DXShader::CCompiler::Unalias(this, a2: nullptr, a3: &v145, a4: 1u);
            if ( v7 < 0 )
              goto LABEL_219;
            v148 = -1;
            v142 = -1;
            v7 = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10000001u,
                   a4: &v148,
                   a5: &v145,
                   a6: 0x1700000000LL);
            if ( v7 < 0 )
              goto LABEL_219;
            v7 = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10000001u,
                   a4: &v142,
                   a5: &a3,
                   a6: 0x1700000000LL);
            if ( v7 < 0 )
              goto LABEL_219;
            v20 = *((_DWORD *)this + 2);
            v21 = *(_DWORD *)(*(_DWORD *)(v20 + 20) + 4 * v145);
            v22 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 16) + 4 * *(_DWORD *)(v21 + 4)) + 4);
            v144 = 0;
            if ( (v22 & 0x10) == 0 || (v22 & 0x200) == 0 || *(_DWORD *)(v21 + 8) != -1 )
            {
              v145 = 0;
              goto LABEL_45;
            }
            goto LABEL_39;
          }
        }
      }
    }
  }
  v23 = v149;
  if ( (*(_BYTE *)v149 & 1) != 0 )
  {
    v140 = -1;
    v148 = -1;
    v142 = -1;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10100001u, a4: &v140, a5: &a3, a6: 0x1000000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10000001u, a4: &v148, a5: &a3, a6: 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v115) = 23;
    LODWORD(v115) = &a3;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20300001u, a4: &v142, a5: &v140, a6: v115);
    if ( v7 < 0 )
      goto LABEL_219;
    v24 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 16) + 4 * *(_DWORD *)(v23 + 4)) + 4);
    v144 = 1;
    if ( (v24 & 0x10) != 0 && (v24 & 0x200) != 0 && *(_DWORD *)(v23 + 8) == -1 )
    {
LABEL_39:
      v145 = 1;
      goto LABEL_45;
    }
  }
  else
  {
    v133 = -1;
    v140 = -1;
    v148 = -1;
    v142 = -1;
    v7 = D3DXShader::CCompiler::EmitPositive(this, a2, a3: &v133, a4: &v140, a5: &a3, a6: 1u);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v116) = 23;
    LODWORD(v116) = &v133;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20200001u, a4: &v148, a5: &v140, a6: v116);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v117) = 23;
    LODWORD(v117) = &v133;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20300001u, a4: &v142, a5: &v140, a6: v117);
    if ( v7 < 0 )
      goto LABEL_219;
    v144 = 1;
  }
  v145 = 0;
LABEL_45:
  v7 = D3DXShader::CCompiler::Unalias(this, a2: nullptr, a3: &v148, a4: 1u);
  if ( v7 < 0 )
    goto LABEL_219;
  v25 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 16)
                  + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v148) + 4));
  n = 0;
  v26 = (*(_DWORD *)(v25 + 4) & 0x800) == 0;
  v149 = 1;
  if ( v26 )
  {
LABEL_60:
    v29 = *((_DWORD **)this + 2);
    if ( v29[22] == 0 && (v29[21] == 0 || v145 == 0) && (v29[13] == 0 || *((_DWORD *)this + 12) != -1) )
      goto LABEL_67;
    v30 = 1;
    n = 1;
    goto LABEL_66;
  }
  strchr(string: *(unsigned __int8 **)v25, chr: 0x62u);
  if ( v27 == 0 )
  {
    strchr(string: *(unsigned __int8 **)v25, chr: 0x42u);
    if ( v28 == 0 )
    {
      if ( (*(_DWORD *)(v25 + 4) & 0x800) != 0 )
      {
        strchr(string: *(unsigned __int8 **)v25, chr: 0x63u);
        if ( v31 != 0 || (strchr(string: *(unsigned __int8 **)v25, chr: 0x43u), v32 != 0) )
        {
          v29 = *((_DWORD **)this + 2);
          if ( v29[22] != 0 || v29[13] != 0 && *((_DWORD *)this + 12) == -1 )
          {
            v149 = 1;
            n = 1;
          }
          v145 = 0;
          goto LABEL_67;
        }
      }
      goto LABEL_60;
    }
  }
  v29 = *((_DWORD **)this + 2);
  v30 = 0;
  if ( v29[21] != 0 && v145 != 0 )
  {
    n = 1;
LABEL_66:
    v149 = v30;
  }
LABEL_67:
  if ( v29[13] == 0 )
  {
    if ( v149 == 0 )
      goto LABEL_78;
    if ( n != 0 )
    {
      if ( v145 != 0 )
      {
        if ( *((_DWORD *)this + 15) < v29[21] )
          goto LABEL_75;
        goto LABEL_74;
      }
      if ( *((_DWORD *)this + 16) >= v29[22] )
LABEL_74:
        n = 0;
    }
  }
LABEL_75:
  if ( v149 != 0 && (*((_BYTE *)this + 21) & 2) != 0 )
    n = 0;
LABEL_78:
  if ( n != 0 && (*((_BYTE *)this + 21) & 4) != 0 )
    v149 = 0;
  v152 = *(struct D3DXShader::CNode **)(*((_DWORD *)this + 1) + 24);
  v151 = 0;
  pMem = MemAlloc_Alloc(nSize: 4 * (_DWORD)v152);
  if ( pMem == nullptr )
    goto LABEL_218;
  v147 = MemAlloc_Alloc(nSize: 4 * (_DWORD)v152);
  if ( v147 == nullptr )
    goto LABEL_218;
  v146 = MemAlloc_Alloc(nSize: 4 * (_DWORD)v152);
  if ( v146 == nullptr )
    goto LABEL_218;
  qmemcpy(pMem, *((const void **)this + 6), 4 * (_DWORD)v152);
  if ( n != 0 )
  {
    v33 = *((_DWORD *)this + 2);
    v26 = *(_DWORD *)(v33 + 52) == 0;
    n = *(_DWORD *)(v33 + 12);
    if ( v26 )
    {
      if ( v145 != 0 )
        ++*((_DWORD *)this + 15);
      else
        ++*((_DWORD *)this + 16);
    }
    v141 = -1;
    v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10F00001u, a4: &v141, a5: &v148, a6: 0);
    if ( v7 < 0 )
      goto LABEL_219;
    v34 = *((_DWORD **)this + 2);
    if ( v34[13] != 0 )
      v35 = v34[36];
    else
      v35 = v34[40];
    v26 = a4 == 0;
    *(_DWORD *)(*(_DWORD *)(v34[5] + 4 * v141) + 4) = v35;
    if ( v26 )
    {
      qmemcpy(v147, pMem, 4 * (_DWORD)v152);
    }
    else
    {
      v121 = (unsigned int *)pMem;
      *((_DWORD *)this + 12) = v141;
      v118 = (struct D3DXShader::CNode *)a4;
      *((_DWORD *)this + 13) = v144;
      v7 = D3DXShader::CCompiler::EmitStatement(this, a2: v118, a3: v121);
      if ( v7 < 0 )
        goto LABEL_219;
      v36 = 4 * (_DWORD)v152;
      qmemcpy(v147, *((const void **)this + 6), 4 * (_DWORD)v152);
      v37 = *((char **)this + 6);
      v38 = (char *)pMem;
      qmemcpy(v37, pMem, 4 * (v36 >> 2));
      v40 = &v38[4 * (v36 >> 2)];
      v39 = &v37[4 * (v36 >> 2)];
      v41 = v36;
      v42 = v135;
      qmemcpy(v39, v40, v41 & 3);
      *((_DWORD *)this + 12) = v42;
      *((_DWORD *)this + 13) = v134;
      v43 = *((_DWORD *)this + 20);
      *((_DWORD *)this + 20) = 0;
      v132 = v43;
      v44 = *((_DWORD *)this + 21);
      *((_DWORD *)this + 21) = 0;
      v137 = v44;
    }
    if ( m != nullptr )
    {
      v122 = (unsigned int *)pMem;
      *((_DWORD *)this + 12) = v141;
      v119 = m;
      *((_DWORD *)this + 13) = v144 == 0;
      v7 = D3DXShader::CCompiler::EmitStatement(this, a2: v119, a3: v122);
      if ( v7 < 0 )
        goto LABEL_219;
      v45 = 4 * (_DWORD)v152;
      qmemcpy(v146, *((const void **)this + 6), 4 * (_DWORD)v152);
      v46 = *((char **)this + 6);
      v47 = (char *)pMem;
      qmemcpy(v46, pMem, 4 * (v45 >> 2));
      v49 = &v47[4 * (v45 >> 2)];
      v48 = &v46[4 * (v45 >> 2)];
      v50 = v45;
      v51 = v135;
      qmemcpy(v48, v49, v50 & 3);
      *((_DWORD *)this + 12) = v51;
      *((_DWORD *)this + 13) = v134;
      v52 = *((_DWORD *)this + 20);
      *((_DWORD *)this + 20) = 0;
      v139 = v52;
      v53 = *((_DWORD *)this + 21);
      *((_DWORD *)this + 21) = 0;
      v138 = v53;
    }
    else
    {
      qmemcpy(v146, pMem, 4 * (_DWORD)v152);
    }
    v54 = v152;
    v151 = 0;
    if ( v152 != nullptr )
    {
      v55 = v147;
      do
      {
        if ( *v55 != *(_DWORD *)((char *)v55 + (_BYTE *)v146 - (_BYTE *)v147) )
          ++v151;
        ++v55;
        v54 = (struct D3DXShader::CNode *)((char *)v54 - 1);
      }
      while ( v54 != nullptr );
    }
    v26 = v149 == 0;
    *((_DWORD *)this + 15) = v130;
    *((_DWORD *)this + 16) = v129;
    if ( v26 )
    {
      v56 = n;
      goto LABEL_122;
    }
    if ( v151 > 0x10 )
    {
      v56 = n;
    }
    else
    {
      v56 = n;
      if ( *(_DWORD *)(*((_DWORD *)this + 2) + 12) - n <= 0x20 )
      {
LABEL_112:
        if ( v149 != 0 )
        {
          v57 = *((_DWORD *)this + 2);
          v58 = v56;
          if ( v56 < *(_DWORD *)(v57 + 12) )
          {
            v59 = (_DWORD **)(*(_DWORD *)(v57 + 24) + 4 * v56);
            while ( (**v59 & 0xF0000000) != 0x60000000 )
            {
              ++v58;
              ++v59;
              if ( v58 >= *(_DWORD *)(*((_DWORD *)this + 2) + 12) )
                goto LABEL_119;
            }
            v149 = 0;
          }
LABEL_119:
          if ( v149 != 0 )
          {
LABEL_130:
            for ( j = v56; j < *(_DWORD *)(*((_DWORD *)this + 2) + 12); ++j )
            {
              v62 = *(D3DXShader::CInstruction **)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * j);
              if ( v62 != nullptr )
              {
                D3DXShader::CInstruction::`scalar deleting destructor'(this: v62, a2: 1);
                v56 = n;
              }
              *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * j) = 0;
            }
            v63 = pMem;
            *(_DWORD *)(*((_DWORD *)this + 2) + 12) = v56;
            qmemcpy(*((void **)this + 6), v63, 4 * (_DWORD)v152);
            goto LABEL_135;
          }
        }
LABEL_122:
        if ( v145 == 0 )
        {
          v60 = v56;
          if ( v56 < *(_DWORD *)(*((_DWORD *)this + 2) + 12) )
          {
            while ( D3DXShader::CInstruction::IsGradient(this: *(D3DXShader::CInstruction **)(*(_DWORD *)(*((_DWORD *)this + 2) + 24)
                                                                                            + 4 * v60)) == 0 )
            {
              if ( ++v60 >= *(_DWORD *)(*((_DWORD *)this + 2) + 12) )
                goto LABEL_128;
            }
            v149 = 1;
          }
        }
LABEL_128:
        if ( v149 == 0 )
        {
LABEL_164:
          if ( v151 == 0 )
            goto LABEL_199;
          v80 = v151;
          v81 = (char *)MemAlloc_Alloc(nSize: 24 * v151);
          v131 = v81;
          if ( v81 != nullptr )
          {
            for ( k = 0; k < 6; ++k )
            {
              (&v124)[k] = (unsigned int *)v81;
              v81 += 4 * v80;
            }
            v83 = v125;
            if ( v152 != nullptr )
            {
              v84 = (unsigned int *)v146;
              n = (char *)v124 - (char *)v125;
              v85 = (_BYTE *)v147 - (_BYTE *)v146;
              a4 = (char *)v126[0] - (char *)v125;
              v128 = (_BYTE *)v147 - (_BYTE *)v146;
              for ( m = v152; m != nullptr; m = (struct D3DXShader::CNode *)((char *)m - 1) )
              {
                v145 = (unsigned int)v84 + v85;
                if ( *(unsigned int *)((char *)v84 + v85) != *v84 )
                {
                  v86 = v148;
                  if ( v144 == 0 )
                    v86 = v142;
                  *(unsigned int *)((char *)v83 + n) = v86;
                  v87 = *(_DWORD *)v145;
                  if ( *(_DWORD *)v145 == -1
                    || *(_DWORD *)(*((_DWORD *)this + 2) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                                                                         + 4 * v87)
                                                                             + 4) )
                  {
                    v87 = *((_DWORD *)this + 9);
                  }
                  *v83 = v87;
                  v88 = *v84;
                  if ( *v84 == -1
                    || *(_DWORD *)(*((_DWORD *)this + 2) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                                                                         + 4 * v88)
                                                                             + 4) )
                  {
                    v88 = *((_DWORD *)this + 9);
                  }
                  v80 = v151;
                  *(unsigned int *)((char *)v83 + a4) = v88;
                  v85 = v128;
                  ++v83;
                }
                ++v84;
              }
            }
            if ( v149 != 0 )
            {
              v89 = D3DXShader::CCompiler::EmitLerp(this, a2, a3: v126[1], a4: v126[0], a5: v125, a6: v124, a7: v80);
            }
            else
            {
              v113 = v125;
              v90 = v151 & 0xFFFFF;
              v111 = v125;
              a4 = v151 & 0xFFFFF;
              HIBYTE(a4) = 16;
              v109 = (struct D3DXShader::CNode *)a4;
              *((_DWORD *)this + 12) = v141;
              *((_DWORD *)this + 13) = v144;
              v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: (unsigned int)v109, a4: v111, a5: v113, a6: 0);
              if ( v7 < 0 )
                goto LABEL_219;
              v91 = 0;
              if ( v151 != 0 )
              {
                do
                {
                  v92 = *((_DWORD *)this + 2);
                  v93 = *(_DWORD *)(*(_DWORD *)(v92 + 20) + 4 * v125[v91++]);
                  v94 = v91 < v151;
                  *(_DWORD *)(v93 + 4) = *(_DWORD *)(v92 + 152);
                }
                while ( v94 );
              }
              *((_DWORD *)this + 12) = v141;
              v114 = v126[0];
              v112 = v126[0];
              v110 = (struct D3DXShader::CNode *)a4;
              *((_DWORD *)this + 13) = v144 == 0;
              v7 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: (unsigned int)v110, a4: v112, a5: v114, a6: 0);
              if ( v7 < 0 )
                goto LABEL_219;
              v95 = 0;
              if ( v151 != 0 )
              {
                do
                {
                  v96 = *((_DWORD *)this + 2);
                  v97 = *(_DWORD *)(*(_DWORD *)(v96 + 20) + 4 * v126[0][v95++]);
                  v94 = v95 < v151;
                  *(_DWORD *)(v97 + 4) = *(_DWORD *)(v96 + 152);
                }
                while ( v94 );
              }
              v123 = v151;
              *((_DWORD *)this + 12) = v135;
              v120 = v126[1];
              *((_DWORD *)this + 13) = v134;
              v7 = D3DXShader::CCompiler::EmitTemp(this, a2: v120, a3: v123);
              if ( v7 < 0 )
                goto LABEL_219;
              v89 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: v90 | 0x20700000,
                      a4: v126[1],
                      a5: v125,
                      a6: (unsigned int)v126[0]);
            }
            v7 = v89;
            if ( v89 < 0 )
              goto LABEL_219;
            v98 = 0;
            a4 = 0;
            if ( v152 != nullptr )
            {
              v99 = (_BYTE *)v146 - (_BYTE *)v147;
              v100 = v126[1];
              n = (_BYTE *)v146 - (_BYTE *)v147;
              do
              {
                if ( *((_DWORD *)v147 + v98) != *(_DWORD *)((char *)v147 + 4 * v98 + v99) )
                {
                  v101 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
                  v102 = *(D3DXShader::CArgument **)(v101 + 4 * *v100);
                  v103 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v98);
                  if ( v103 != -1 )
                    D3DXShader::CArgument::Instance(this: v102, a2: *(struct D3DXShader::CArgument **)(v101 + 4 * v103));
                  v104 = a4;
                  *(_DWORD *)(*((_DWORD *)this + 6) + 4 * a4) = *v100;
                  v98 = v104;
                  v99 = n;
                  *((_DWORD *)v102 + 12) = v98;
                  ++v100;
                }
                a4 = ++v98;
              }
              while ( v98 < (unsigned int)v152 );
            }
            goto LABEL_199;
          }
LABEL_218:
          v7 = -2147024882;
          goto LABEL_219;
        }
        v56 = n;
        goto LABEL_130;
      }
    }
    v149 = 0;
    goto LABEL_112;
  }
LABEL_135:
  if ( v149 == 0 )
    goto LABEL_164;
  if ( a4 != 0 )
  {
    v7 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)this + 11, a3: 1u);
    if ( v7 < 0 )
      goto LABEL_219;
    v64 = &v148;
    if ( v144 == 0 )
      v64 = &v142;
    v7 = D3DXShader::CCompiler::EmitInst(
           (char **)this,
           a2,
           a3: 0x20500001u,
           a4: (unsigned int *)this + 11,
           a5: &v136,
           a6: (unsigned int)v64 | 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = D3DXShader::CCompiler::EmitStatement(this, a2: (struct D3DXShader::CNode *)a4, a3: (unsigned int *)pMem);
    if ( v7 < 0 )
      goto LABEL_219;
    v65 = 4 * (_DWORD)v152;
    qmemcpy(v147, *((const void **)this + 6), 4 * (_DWORD)v152);
    qmemcpy(*((void **)this + 6), pMem, v65);
    *((_DWORD *)this + 11) = v136;
    v66 = *((_DWORD *)this + 20);
    *((_DWORD *)this + 20) = 0;
    v132 = v66;
    v67 = *((_DWORD *)this + 21);
    *((_DWORD *)this + 21) = 0;
    v137 = v67;
  }
  else
  {
    qmemcpy(v147, pMem, 4 * (_DWORD)v152);
  }
  if ( m != nullptr )
  {
    v7 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)this + 11, a3: 1u);
    if ( v7 < 0 )
      goto LABEL_219;
    v68 = &v142;
    if ( v144 == 0 )
      v68 = &v148;
    v7 = D3DXShader::CCompiler::EmitInst(
           (char **)this,
           a2,
           a3: 0x20500001u,
           a4: (unsigned int *)this + 11,
           a5: &v136,
           a6: (unsigned int)v68 | 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = D3DXShader::CCompiler::EmitStatement(this, a2: m, a3: (unsigned int *)pMem);
    if ( v7 < 0 )
      goto LABEL_219;
    v69 = 4 * (_DWORD)v152;
    qmemcpy(v146, *((const void **)this + 6), 4 * (_DWORD)v152);
    qmemcpy(*((void **)this + 6), pMem, v69);
    v70 = *((_DWORD *)this + 21);
    *((_DWORD *)this + 11) = v136;
    v139 = *((_DWORD *)this + 20);
    *((_DWORD *)this + 20) = 0;
    v138 = v70;
    *((_DWORD *)this + 21) = 0;
  }
  else
  {
    qmemcpy(v146, pMem, 4 * (_DWORD)v152);
  }
  v151 = 0;
  a4 = 0;
  if ( v152 != nullptr )
  {
    v71 = (int *)v147;
    v72 = (_BYTE *)v146 - (_BYTE *)v147;
    m = (struct D3DXShader::CNode *)v147;
    for ( n = (_BYTE *)v146 - (_BYTE *)v147; ; v72 = n )
    {
      v73 = *v71;
      v145 = (unsigned int)v71 + v72;
      v74 = *(int *)((char *)v71 + v72);
      if ( v73 != v74 )
      {
        if ( v73 == -1
          || (v75 = *((_DWORD *)this + 2),
              v76 = *(_DWORD *)(v75 + 20),
              (v77 = *(_DWORD *)(v75 + 116)) == *(_DWORD *)(*(_DWORD *)(v76 + 4 * v73) + 4)) )
        {
          v79 = a4;
          *(_DWORD *)m = v74;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v79) = v74;
        }
        else if ( v74 == -1 || v77 == *(_DWORD *)(*(_DWORD *)(v76 + 4 * v74) + 4) )
        {
          v78 = a4;
          *(_DWORD *)v145 = v73;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v78) = v73;
        }
        else
        {
          ++v151;
        }
      }
      ++a4;
      v71 = (int *)((char *)m + 4);
      m = (struct D3DXShader::CNode *)((char *)m + 4);
      if ( a4 >= (unsigned int)v152 )
        break;
    }
    goto LABEL_164;
  }
LABEL_199:
  v7 = 0;
  v105 = v137 != 0 && v138 != 0;
  v106 = v132;
  v26 = v132 == 0;
  *((_DWORD *)this + 21) = v105;
  v107 = !v26 && (v139 != 0 || v138 != 0) || v139 != 0 && (v106 != 0 || v137 != 0);
  *((_DWORD *)this + 20) = v107;
  if ( v106 != 0 )
  {
    if ( v139 != 0 )
      goto LABEL_215;
    if ( v138 == 0 )
    {
LABEL_217:
      D3DXShader::CCompiler::Error(
        this,
        a2,
        a3: 0xDACu,
        format: "asymetric returns from if statements not yet implemented");
      v7 = -2147467263;
      goto LABEL_219;
    }
  }
  if ( v139 != 0 )
  {
LABEL_215:
    if ( v106 == 0 && v137 == 0 )
      goto LABEL_217;
  }
LABEL_219:
  free(pMem);
  free(pMem: v147);
  free(pMem: v146);
  free(pMem: v131);
  *((_DWORD *)this + 11) = v136;
  *((_DWORD *)this + 12) = v135;
  *((_DWORD *)this + 13) = v134;
  *((_DWORD *)this + 15) = v130;
  *((_DWORD *)this + 16) = v129;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101CEEC6
// Name: protected: long D3DXShader::CCompiler::EmitForLoop(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitForLoop(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *k,
        unsigned int a6)
{
  int v7; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // eax
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // esi
  unsigned int v23; // edi
  unsigned int v24; // ecx
  _DWORD *v25; // esi
  unsigned int v26; // eax
  struct D3DXShader::_D3DXRANGE *v27; // eax
  struct D3DXShader::_D3DXRANGE *v28; // eax
  unsigned int v29; // edx
  double *v30; // edi
  _DWORD *v31; // esi
  unsigned int v32; // ecx
  double v33; // st7
  unsigned int *v34; // edi
  double *v35; // esi
  int v36; // eax
  double v37; // st7
  int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // esi
  int v41; // eax
  unsigned int v42; // esi
  bool v43; // zf
  _DWORD **v44; // ecx
  char *v45; // eax
  bool v46; // zf
  unsigned int v47; // ecx
  int i; // edi
  unsigned int v49; // eax
  void *v50; // edx
  char *v51; // edx
  unsigned int v52; // eax
  int v53; // edi
  char *v54; // ecx
  unsigned int *v55; // edx
  char *v56; // ecx
  unsigned int *v57; // eax
  unsigned int *v58; // ecx
  unsigned int v59; // eax
  unsigned int *v60; // ecx
  bool v61; // sf
  double v62; // st7
  unsigned int v63; // eax
  unsigned int *v64; // esi
  int v65; // edx
  double *v66; // ecx
  double v67; // st7
  unsigned int v68; // eax
  double v69; // st7
  int v70; // eax
  int v71; // ecx
  int v72; // eax
  unsigned int *v73; // eax
  int v74; // ecx
  unsigned int *v75; // eax
  int v76; // edx
  unsigned int v77; // ecx
  unsigned int *v78; // eax
  int v79; // ecx
  unsigned int v80; // ecx
  int v81; // eax
  int v82; // edx
  bool v83; // cf
  unsigned int v84; // ecx
  int v85; // eax
  int v86; // edx
  unsigned int v87; // ecx
  int v88; // eax
  int v89; // edx
  unsigned int v90; // ecx
  int v91; // eax
  int v92; // edx
  unsigned int v93; // ecx
  int v94; // eax
  int v95; // edx
  _DWORD *v96; // esi
  int v97; // edx
  double *v98; // ecx
  double v99; // st7
  unsigned int *v100; // eax
  double v101; // st7
  int v102; // eax
  unsigned int v103; // [esp-Ch] [ebp-E8h]
  struct D3DXShader::CNode *v104; // [esp-Ch] [ebp-E8h]
  unsigned int v105; // [esp-Ch] [ebp-E8h]
  unsigned int *v106; // [esp-8h] [ebp-E4h]
  unsigned int *v107; // [esp-8h] [ebp-E4h]
  unsigned int *v108; // [esp-8h] [ebp-E4h]
  unsigned int *v109; // [esp-8h] [ebp-E4h]
  unsigned int *v110; // [esp-4h] [ebp-E0h]
  unsigned int *v111; // [esp-4h] [ebp-E0h]
  unsigned int *v112; // [esp-4h] [ebp-E0h]
  unsigned int *v113; // [esp-4h] [ebp-E0h]
  __int64 v114; // [esp+0h] [ebp-DCh]
  __int64 v115; // [esp+0h] [ebp-DCh]
  double v116; // [esp+14h] [ebp-C8h] BYREF
  double v117; // [esp+1Ch] [ebp-C0h]
  double v118; // [esp+24h] [ebp-B8h] BYREF
  double v119; // [esp+2Ch] [ebp-B0h]
  double v120; // [esp+34h] [ebp-A8h] BYREF
  double v121; // [esp+3Ch] [ebp-A0h]
  int v122; // [esp+44h] [ebp-98h]
  int v123; // [esp+48h] [ebp-94h]
  int v124; // [esp+4Ch] [ebp-90h]
  unsigned int v125; // [esp+50h] [ebp-8Ch] BYREF
  double v126; // [esp+54h] [ebp-88h] BYREF
  void *v127; // [esp+5Ch] [ebp-80h]
  unsigned int v128; // [esp+60h] [ebp-7Ch] BYREF
  unsigned int v129; // [esp+64h] [ebp-78h] BYREF
  int v130; // [esp+68h] [ebp-74h]
  int v131; // [esp+6Ch] [ebp-70h]
  unsigned int v132; // [esp+70h] [ebp-6Ch]
  unsigned int v133; // [esp+74h] [ebp-68h]
  void *pMem; // [esp+78h] [ebp-64h]
  char *v135; // [esp+7Ch] [ebp-60h]
  unsigned int *v136; // [esp+80h] [ebp-5Ch]
  unsigned int *v137; // [esp+84h] [ebp-58h]
  unsigned int *v138; // [esp+88h] [ebp-54h]
  unsigned int *v139; // [esp+8Ch] [ebp-50h]
  unsigned int *v140; // [esp+90h] [ebp-4Ch]
  unsigned int *v141; // [esp+94h] [ebp-48h]
  unsigned int *v142; // [esp+98h] [ebp-44h]
  unsigned int *v143; // [esp+9Ch] [ebp-40h]
  unsigned int v144; // [esp+A0h] [ebp-3Ch] BYREF
  BOOL v145; // [esp+A4h] [ebp-38h]
  BOOL v146; // [esp+A8h] [ebp-34h]
  void *v147; // [esp+ACh] [ebp-30h]
  void *v148; // [esp+B0h] [ebp-2Ch]
  void *v149; // [esp+B4h] [ebp-28h]
  unsigned int v150; // [esp+B8h] [ebp-24h]
  unsigned int v151; // [esp+BCh] [ebp-20h] BYREF
  void *v152; // [esp+C0h] [ebp-1Ch]
  unsigned int j; // [esp+C4h] [ebp-18h]
  unsigned int v154; // [esp+C8h] [ebp-14h]
  unsigned int nSize; // [esp+CCh] [ebp-10h]
  unsigned int v156; // [esp+D0h] [ebp-Ch] BYREF
  struct D3DXShader::_D3DXRANGE *v157; // [esp+D4h] [ebp-8h]
  unsigned int v158; // [esp+D8h] [ebp-4h]
  struct D3DXShader::CNode *v159; // [esp+E4h] [ebp+8h]

  v7 = *((_DWORD *)this + 12);
  v8 = *((_DWORD *)this + 17);
  v130 = v7;
  v131 = *((_DWORD *)this + 13);
  v122 = *((_DWORD *)this + 26);
  v123 = *((_DWORD *)this + 27);
  v127 = nullptr;
  v149 = nullptr;
  v152 = nullptr;
  v148 = nullptr;
  v147 = nullptr;
  v145 = a3 != 0;
  v9 = *((_DWORD **)this + 2);
  if ( v8 >= v9[23] )
    return -2147467259;
  *((_DWORD *)this + 17) = v8 + 1;
  v11 = v9[2];
  v12 = *(_DWORD *)(*((_DWORD *)this + 1) + 24);
  j = v9[3];
  v158 = v12;
  v133 = v11;
  pMem = MemAlloc_Alloc(nSize: 4 * v12);
  if ( pMem != nullptr )
  {
    v149 = MemAlloc_Alloc(nSize: 4 * v158);
    if ( v149 != nullptr )
    {
      v152 = MemAlloc_Alloc(nSize: 4 * v158);
      if ( v152 != nullptr )
      {
        nSize = 16 * v158;
        v148 = MemAlloc_Alloc(nSize: 16 * v158);
        if ( v148 != nullptr )
        {
          v147 = MemAlloc_Alloc(nSize);
          if ( v147 != nullptr )
          {
            v13 = 0;
            if ( v158 != 0 )
            {
              a3 = (unsigned int)v148;
              do
              {
                v14 = 4 * v13;
                v15 = *(_DWORD *)(4 * v13 + *((_DWORD *)this + 6));
                if ( v15 == -1
                  || D3DXShader::CCompiler::EvalRange(this, a2: v15, (struct D3DXShader::_D3DXRANGE *)a3) < 0 )
                {
                  v16 = a3;
                  *(double *)a3 = *((double *)this + 20);
                  *(double *)(v16 + 8) = *((double *)this + 21);
                }
                v17 = *(_DWORD *)(v14 + *((_DWORD *)this + 6));
                if ( v17 == -1
                  || (v18 = *((_DWORD *)this + 2),
                      v19 = *(_DWORD **)(*(_DWORD *)(v18 + 20) + 4 * v17),
                      *(_DWORD *)(v18 + 116) == v19[1]) )
                {
                  *(_DWORD *)((char *)v149 + v14) = 31;
                }
                else
                {
                  *(_DWORD *)((char *)v149 + v14) = *v19 & 0x1F;
                }
                a3 += 16;
                ++v13;
              }
              while ( v13 < v158 );
            }
            v126 = 1.0;
            qmemcpy(v152, v149, 4 * ((4 * v158) >> 2));
            qmemcpy(v147, v148, nSize);
            v20 = *((_DWORD *)this + 8);
            v128 = -1;
            v129 = -1;
            v151 = v20;
            v156 = 1;
            v146 = true;
            v150 = *(_DWORD *)(*((_DWORD *)this + 2) + 104);
            if ( v150 == 0 )
              v150 = 255;
            v154 = 0;
            while ( 1 )
            {
              v21 = v154;
              *((_DWORD *)this + 26) = v154;
              v43 = k == nullptr;
              v132 = v21 + 1;
              *((_DWORD *)this + 27) = v21 + 1;
              if ( !v43 && v145 )
              {
                v22 = D3DXShader::CCompiler::EmitStatement(this, a2: k, a3: nullptr);
                if ( v22 < 0 )
                  goto LABEL_218;
                if ( *((_DWORD *)this + 23) != 0 )
                  goto LABEL_91;
                if ( *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0 )
                  goto LABEL_215;
              }
              qmemcpy(pMem, *((const void **)this + 6), 4 * v158);
              a3 = -1;
              if ( a4 != nullptr )
                break;
LABEL_33:
              if ( D3DXShader::CCompiler::EvalValue(this, a2: v151, a3: &v126) < 0 || 0.0 == v126 )
              {
                v28 = nullptr;
                v157 = nullptr;
                if ( v158 == 0 )
                  goto LABEL_57;
                v29 = a6 - (_DWORD)v152;
                v30 = (double *)v147;
                nSize = a6 - (_DWORD)v152;
                while ( 1 )
                {
                  v31 = (char *)v152 + 4 * (_DWORD)v28;
                  v32 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v28);
                  if ( *(_DWORD *)((char *)v31 + v29) != v32 )
                    break;
LABEL_56:
                  v28 = (struct D3DXShader::_D3DXRANGE *)((char *)v28 + 1);
                  v30 += 2;
                  v157 = v28;
                  if ( (unsigned int)v28 >= v158 )
                    goto LABEL_57;
                }
                if ( *v30 > *((double *)this + 21) || v30[1] < *((double *)this + 20) )
                {
                  if ( D3DXShader::CCompiler::EvalRange(this, a2: v32, a3: (struct D3DXShader::_D3DXRANGE *)&v118) < 0 )
                  {
                    *v30 = *((double *)this + 20);
                    v33 = *((double *)this + 21);
                  }
                  else
                  {
                    if ( *v30 > v118 )
                      *v30 = v118;
                    if ( v30[1] >= v119 )
                      goto LABEL_55;
                    v33 = v119;
                  }
                  v30[1] = v33;
                }
LABEL_55:
                *v31 &= **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                    + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v157));
                v29 = nSize;
                v28 = v157;
                goto LABEL_56;
              }
              v23 = 0;
              if ( v158 != 0 )
              {
                v24 = a6 - (_DWORD)v152;
                v157 = (struct D3DXShader::_D3DXRANGE *)v147;
                nSize = a6 - (_DWORD)v152;
                do
                {
                  v25 = (char *)v152 + 4 * v23;
                  v26 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v23);
                  if ( *(_DWORD *)((char *)v25 + v24) != v26 )
                  {
                    if ( D3DXShader::CCompiler::EvalRange(this, a2: v26, a3: v157) < 0 )
                    {
                      v27 = v157;
                      *(double *)v157 = *((double *)this + 20);
                      *((double *)v27 + 1) = *((double *)this + 21);
                    }
                    v24 = nSize;
                    *v25 = **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                       + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v23));
                  }
                  v157 = (struct D3DXShader::_D3DXRANGE *)((char *)v157 + 16);
                  ++v23;
                }
                while ( v23 < v158 );
              }
LABEL_57:
              if ( a3 != -1 )
              {
                if ( D3DXShader::CCompiler::EvalRange(this, a2: a3, a3: (struct D3DXShader::_D3DXRANGE *)&v116) >= 0 )
                {
                  if ( 0.0 == v116 && 0.0 == v117 )
                    goto LABEL_91;
                  if ( v116 <= 0.0 && v117 >= 0.0 )
                    v156 = 0;
                }
                *(double *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a3) + 32) = 1.0;
                *(double *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a3) + 40) = 1.0;
              }
              if ( v158 != 0 )
              {
                v34 = (unsigned int *)pMem;
                v35 = (double *)v148;
                v36 = a6 - (_DWORD)pMem;
                v157 = (struct D3DXShader::_D3DXRANGE *)((_BYTE *)v149 - (_BYTE *)pMem);
                v124 = a6 - (_DWORD)pMem;
                nSize = v158;
                while ( *(unsigned int *)((char *)v34 + v36) == *v34 )
                {
LABEL_78:
                  v35 += 2;
                  ++v34;
                  if ( --nSize == 0 )
                    goto LABEL_79;
                }
                if ( *v35 > *((double *)this + 21) || v35[1] < *((double *)this + 20) )
                {
                  if ( D3DXShader::CCompiler::EvalRange(this, a2: *v34, a3: (struct D3DXShader::_D3DXRANGE *)&v120) < 0 )
                  {
                    *v35 = *((double *)this + 20);
                    v37 = *((double *)this + 21);
LABEL_76:
                    v35[1] = v37;
                  }
                  else
                  {
                    if ( *v35 > v120 )
                      *v35 = v120;
                    if ( v35[1] < v121 )
                    {
                      v37 = v121;
                      goto LABEL_76;
                    }
                  }
                }
                *(_DWORD *)((char *)v157 + (_DWORD)v34) &= **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                                                       + 4 * *v34);
                v36 = v124;
                goto LABEL_78;
              }
LABEL_79:
              if ( v146 )
                v146 = v156 == 0 && D3DXShader::CCompiler::IsLimited(this, a2: a3, a3: v154, a4: &v128, a5: &v129);
              if ( k != nullptr && !v145 )
              {
                v22 = D3DXShader::CCompiler::EmitStatement(this, a2: k, a3: nullptr);
                if ( v22 < 0 )
                  goto LABEL_218;
                if ( *((_DWORD *)this + 23) != 0 )
                  goto LABEL_91;
                if ( *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0 )
                  goto LABEL_215;
              }
              v154 = v132;
              if ( v132 >= v150 )
                goto LABEL_91;
            }
            a3 = -1;
            v22 = D3DXShader::CCompiler::EmitExpression(this, a2: a4, &a3, a4: nullptr);
            if ( v22 < 0 )
              goto LABEL_218;
            HIDWORD(v114) = 23;
            LODWORD(v114) = &a3;
            v22 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2: a4,
                    a3: 0x20500001u,
                    a4: &v151,
                    a5: &v151,
                    a6: v114);
            if ( v22 < 0 )
              goto LABEL_218;
            if ( *((_DWORD *)this + 23) == 0 )
            {
              if ( *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0 )
                goto LABEL_215;
              goto LABEL_33;
            }
LABEL_91:
            if ( v154 <= 1 )
              goto LABEL_215;
            if ( v154 < v150 )
            {
              if ( *((_DWORD *)this + 24) != 0 || (*((_BYTE *)this + 21) & 2) != 0 )
                goto LABEL_215;
              if ( *((_DWORD *)this + 23) == 0 )
                v146 = false;
            }
            if ( v156 != 0 || v146 )
            {
              v39 = j;
            }
            else
            {
              v38 = *((_DWORD *)this + 2);
              if ( (*(_BYTE *)(v38 + 112) & 4) == 0 )
                goto LABEL_215;
              v39 = j;
              v40 = j;
              if ( j < *(_DWORD *)(v38 + 12) )
              {
                do
                {
                  if ( D3DXShader::CInstruction::IsGradient(this: *(D3DXShader::CInstruction **)(*(_DWORD *)(*((_DWORD *)this + 2) + 24)
                                                                                               + 4 * v40)) != 0 )
                    goto LABEL_215;
                  ++v40;
                }
                while ( v40 < *(_DWORD *)(*((_DWORD *)this + 2) + 12) );
              }
            }
            if ( *((_DWORD *)this + 23) != 0 )
            {
              v154 = v150;
              *((_DWORD *)this + 23) = 0;
            }
            if ( v154 == v150 && D3DXShader::CCompiler::EvalValue(this, a2: v151, a3: &v126) >= 0 && 0.0 != v126 )
              goto LABEL_215;
            if ( v154 >= v150 || v156 == 0 || (*((_BYTE *)this + 21) & 4) != 0 )
              goto LABEL_131;
            v41 = *((_DWORD *)this + 2);
            v42 = *(_DWORD *)(v41 + 12);
            v43 = v39 == v42;
            if ( v39 >= v42 )
              goto LABEL_130;
            v44 = (_DWORD **)(*(_DWORD *)(v41 + 24) + 4 * v39);
            while ( 2 )
            {
              v45 = (char *)(**v44 & 0xFFF00000);
              if ( (unsigned int)v45 > 0x20100000 )
              {
                if ( v45 != (char *)538968064
                  && v45 != (char *)540016640
                  && v45 != (char *)541065216
                  && v45 != (char *)542113792 )
                {
                  v46 = v45 == (char *)805306368;
                  goto LABEL_127;
                }
              }
              else if ( v45 != (char *)537919488
                     && v45 != nullptr
                     && v45 != (char *)0x10000000
                     && v45 != (char *)&loc_10100000
                     && v45 != (char *)&loc_101FFFFF + 1
                     && v45 != (char *)272629760 )
              {
                v46 = v45 == (char *)0x20000000;
LABEL_127:
                if ( !v46 )
                  break;
              }
              ++v39;
              ++v44;
              if ( v39 < *(_DWORD *)(*((_DWORD *)this + 2) + 12) )
                continue;
              break;
            }
            v43 = v39 == v42;
LABEL_130:
            if ( v43 )
              goto LABEL_215;
LABEL_131:
            v47 = 0;
            for ( i = 0; v47 < v158; ++v47 )
            {
              v49 = *(_DWORD *)(a6 + 4 * v47);
              if ( v49 != -1 && *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v47) != v49 )
                ++i;
            }
            v50 = MemAlloc_Alloc(nSize: 36 * i);
            v127 = v50;
            if ( v50 != nullptr )
            {
              v22 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)v50, a3: 9 * i);
              if ( v22 < 0 )
                goto LABEL_218;
              v52 = 0;
              v53 = 4 * i;
              v54 = v51;
              do
              {
                (&v135)[v52++] = v54;
                v54 += v53;
              }
              while ( v52 < 9 );
              v55 = v136;
              v56 = nullptr;
              a3 = 0;
              v157 = nullptr;
              if ( v158 != 0 )
              {
                nSize = (char *)v137 - (char *)v136;
                v156 = v135 - (char *)v137;
                do
                {
                  v57 = (unsigned int *)(4 * (_DWORD)v56 + a6);
                  if ( *v57 != -1 && *(_DWORD *)(4 * (_DWORD)v56 + *((_DWORD *)this + 6)) != *v57 )
                  {
                    v58 = (unsigned int *)((char *)v55 + nSize);
                    *(unsigned int *)((char *)v58 + v156) = (unsigned int)v157;
                    *v55 = *v57;
                    *v58 = *v57;
                    if ( *v57 == -1
                      || *(_DWORD *)(*((_DWORD *)this + 2) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                                                                           + 4 * *v57)
                                                                               + 4) )
                    {
                      *v55 = *((_DWORD *)this + 9);
                    }
                    ++a3;
                    ++v55;
                  }
                  v56 = (char *)v157 + 1;
                  v157 = (struct D3DXShader::_D3DXRANGE *)((char *)v157 + 1);
                }
                while ( (unsigned int)v157 < v158 );
              }
              D3DXShader::CCompiler::Reset(this, a2: v133, a3: j, a4: (unsigned int *)a6);
              v59 = v154;
              v60 = *((unsigned int **)this + 2);
              v61 = (v154 & 0x80000000) != 0;
              a6 = v154;
              v62 = (double)(int)v154;
              *((_DWORD *)this + 26) = 0;
              *((_DWORD *)this + 27) = v59;
              if ( v61 )
                v62 = v62 + 4294967296.0;
              v63 = D3DXShader::CBaseProgram::AddArgument(
                      this: (D3DXShader::CBaseProgram *)v60,
                      a2: v60[30],
                      a3: 0,
                      a4: 0,
                      a5: v62);
              v144 = -1;
              v125 = v63;
              v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x11100001u, a4: &v144, a5: &v125, a6: 0);
              if ( v22 < 0 )
                goto LABEL_218;
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v144) + 4) = *(_DWORD *)(*((_DWORD *)this + 2) + 164);
              v110 = v136;
              *((_DWORD *)this + 12) = v144;
              v106 = v137;
              a6 = a3 & 0xFFFFF;
              v103 = a3 & 0xFFFFF | 0x11200000;
              *((_DWORD *)this + 13) = 1;
              v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v103, a4: v106, a5: v110, a6: 0);
              if ( v22 < 0 )
                goto LABEL_218;
              v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: a6 | 0x11300000, a4: v143, a5: v137, a6: 0);
              if ( v22 < 0 )
                goto LABEL_218;
              if ( a3 != 0 )
              {
                v64 = v137;
                v156 = v135 - (char *)v137;
                v132 = (char *)v143 - (char *)v137;
                j = a3;
                do
                {
                  v65 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v64);
                  v66 = (double *)((char *)v148 + 16 * *(unsigned int *)((char *)v64 + v156));
                  if ( *v66 <= v66[1] )
                  {
                    *(double *)(v65 + 32) = *v66;
                    v67 = v66[1];
                    *(_BYTE *)(v65 + 1) |= 1u;
                    v68 = *(_DWORD *)v65;
                    *(double *)(v65 + 40) = v67;
                    v69 = v66[1];
                    v133 = v68;
                    if ( *v66 == v69 )
                      *(_DWORD *)v65 = v133 | 0x80;
                  }
                  *(_DWORD *)v65 |= *((_DWORD *)v149 + *(unsigned int *)((char *)v64 + v156));
                  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v64) + 4) = *(_DWORD *)(*((_DWORD *)this + 2) + 152);
                  v70 = *((_DWORD *)this + 2);
                  v71 = *(_DWORD *)(*(_DWORD *)(v70 + 20) + 4 * *(unsigned int *)((char *)v64 + v132));
                  v72 = *(_DWORD *)(v70 + 172);
                  ++v64;
                  v43 = j-- == 1;
                  *(_DWORD *)(v71 + 4) = v72;
                }
                while ( !v43 );
              }
              if ( k != nullptr && v145 )
              {
                v22 = D3DXShader::CCompiler::EmitStatement(this, a2: k, a3: nullptr);
                if ( v22 < 0 )
                  goto LABEL_218;
              }
              v151 = -1;
              v22 = D3DXShader::CCompiler::EmitExpression(this, a2: a4, a3: &v151, a4: nullptr);
              if ( v22 < 0 )
                goto LABEL_218;
              if ( a3 != 0 )
              {
                v73 = v137;
                v74 = v135 - (char *)v137;
                for ( j = a3; j != 0; --j )
                {
                  *v73 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(unsigned int *)((char *)v73 + v74));
                  ++v73;
                }
              }
              if ( D3DXShader::CCompiler::EvalRange(this, a2: v151, a3: (struct D3DXShader::_D3DXRANGE *)&v120) >= 0
                && (v120 > 0.0 || v121 < 0.0) )
              {
                if ( k == nullptr || v145 || (v22 = D3DXShader::CCompiler::EmitStatement(this, a2: k, a3: nullptr)) >= 0 )
                {
                  if ( a3 != 0 )
                  {
                    v75 = v141;
                    v76 = v135 - (char *)v141;
                    for ( k = (struct D3DXShader::CNode *)a3; k != nullptr; k = (struct D3DXShader::CNode *)((char *)k - 1) )
                    {
                      v77 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(unsigned int *)((char *)v75 + v76));
                      *v75 = v77;
                      if ( v77 == -1 )
                        *v75 = *((_DWORD *)this + 9);
                      ++v75;
                    }
                  }
                  goto LABEL_197;
                }
                goto LABEL_218;
              }
              if ( v154 < v150 && (*(_BYTE *)(*((_DWORD *)this + 2) + 112) & 4) == 0 )
              {
LABEL_215:
                v22 = -2147467259;
                goto LABEL_218;
              }
              v156 = -1;
              v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x11400001u, a4: &v156, a5: &v151, a6: 0);
              if ( v22 >= 0 )
              {
                v43 = k == nullptr;
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v156) + 4) = *(_DWORD *)(*((_DWORD *)this + 2) + 160);
                *((_DWORD *)this + 12) = v156;
                *((_DWORD *)this + 13) = 1;
                if ( v43 || v145 || (v22 = D3DXShader::CCompiler::EmitStatement(this, a2: k, a3: nullptr)) >= 0 )
                {
                  v78 = v138;
                  if ( a3 != 0 )
                  {
                    v79 = v135 - (char *)v138;
                    for ( k = (struct D3DXShader::CNode *)a3; k != nullptr; k = (struct D3DXShader::CNode *)((char *)k - 1) )
                    {
                      *v78 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(unsigned int *)((char *)v78 + v79));
                      ++v78;
                    }
                  }
                  k = (struct D3DXShader::CNode *)(a6 | 0x10000000);
                  v22 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: a6 | 0x10000000,
                          a4: v139,
                          a5: v138,
                          a6: 0);
                  if ( v22 >= 0 )
                  {
                    v80 = 0;
                    if ( a3 != 0 )
                    {
                      do
                      {
                        v81 = *((_DWORD *)this + 2);
                        v82 = *(_DWORD *)(*(_DWORD *)(v81 + 20) + 4 * v139[v80++]);
                        v83 = v80 < a3;
                        *(_DWORD *)(v82 + 4) = *(_DWORD *)(v81 + 152);
                      }
                      while ( v83 );
                    }
                    v111 = v137;
                    v107 = v140;
                    *((_DWORD *)this + 12) = v156;
                    v104 = k;
                    *((_DWORD *)this + 13) = 0;
                    v22 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: (unsigned int)v104,
                            a4: v107,
                            a5: v111,
                            a6: 0);
                    if ( v22 >= 0 )
                    {
                      v84 = 0;
                      if ( a3 != 0 )
                      {
                        do
                        {
                          v85 = *((_DWORD *)this + 2);
                          v86 = *(_DWORD *)(*(_DWORD *)(v85 + 20) + 4 * v140[v84++]);
                          v83 = v84 < a3;
                          *(_DWORD *)(v86 + 4) = *(_DWORD *)(v85 + 152);
                        }
                        while ( v83 );
                      }
                      v115 = (unsigned int)v140;
                      *((_DWORD *)this + 12) = v144;
                      v112 = v139;
                      v108 = v141;
                      v105 = a6 | 0x20800000;
                      *((_DWORD *)this + 13) = 1;
                      v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v105, a4: v108, a5: v112, a6: v115);
                      if ( v22 >= 0 )
                      {
                        v87 = 0;
                        if ( a3 != 0 )
                        {
                          do
                          {
                            v88 = *((_DWORD *)this + 2);
                            v89 = *(_DWORD *)(*(_DWORD *)(v88 + 20) + 4 * v141[v87++]);
                            v83 = v87 < a3;
                            *(_DWORD *)(v89 + 4) = *(_DWORD *)(v88 + 152);
                          }
                          while ( v83 );
                        }
LABEL_197:
                        v22 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: a6 | 0x10000000,
                                a4: v141,
                                a5: v141,
                                a6: 0);
                        if ( v22 >= 0 )
                        {
                          v90 = 0;
                          if ( a3 != 0 )
                          {
                            do
                            {
                              v91 = *((_DWORD *)this + 2);
                              v92 = *(_DWORD *)(*(_DWORD *)(v91 + 20) + 4 * v141[v90++]);
                              v83 = v90 < a3;
                              *(_DWORD *)(v92 + 4) = *(_DWORD *)(v91 + 152);
                            }
                            while ( v83 );
                          }
                          v22 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: a6 | 0x20900000,
                                  a4: v142,
                                  a5: v141,
                                  a6: (unsigned int)v143);
                          if ( v22 >= 0 )
                          {
                            v93 = 0;
                            if ( a3 != 0 )
                            {
                              do
                              {
                                v94 = *((_DWORD *)this + 2);
                                v95 = *(_DWORD *)(*(_DWORD *)(v94 + 20) + 4 * v142[v93++]);
                                v83 = v93 < a3;
                                *(_DWORD *)(v95 + 4) = *(_DWORD *)(v94 + 152);
                              }
                              while ( v83 );
                            }
                            v113 = v142;
                            *((_DWORD *)this + 12) = v130;
                            v109 = v137;
                            *((_DWORD *)this + 13) = v131;
                            v22 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: a6 | 0x11500000,
                                    a4: v109,
                                    a5: v113,
                                    a6: 0);
                            if ( v22 >= 0 )
                            {
                              if ( a3 != 0 )
                              {
                                v96 = v135;
                                v159 = (struct D3DXShader::CNode *)((char *)v137 - v135);
                                for ( k = (struct D3DXShader::CNode *)a3;
                                      k != nullptr;
                                      k = (struct D3DXShader::CNode *)((char *)k - 1) )
                                {
                                  v97 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                                                  + 4 * *(_DWORD *)((char *)v96 + (_DWORD)v159));
                                  v98 = (double *)((char *)v147 + 16 * *v96);
                                  if ( *v98 <= v98[1] )
                                  {
                                    *(double *)(v97 + 32) = *v98;
                                    v99 = v98[1];
                                    *(_BYTE *)(v97 + 1) |= 1u;
                                    v100 = *(unsigned int **)v97;
                                    *(double *)(v97 + 40) = v99;
                                    v101 = v98[1];
                                    a6 = (unsigned int)v100;
                                    if ( *v98 == v101 )
                                      *(_DWORD *)v97 = a6 | 0x80;
                                  }
                                  *(_DWORD *)v97 |= *((_DWORD *)v152 + *v96++);
                                }
                              }
                              if ( v154 == 0
                                || !v146
                                || *((_DWORD *)this + 20) != 0
                                || *((_DWORD *)this + 21) != 0
                                || D3DXShader::CCompiler::EmitInst(
                                     (char **)this,
                                     a2: a4,
                                     a3: 0x10000001u,
                                     a4: (unsigned int *)(*((_DWORD *)this + 6) + 4 * v128),
                                     a5: &v129,
                                     a6: 0) >= 0 )
                              {
                                v22 = 0;
                                goto LABEL_218;
                              }
                              goto LABEL_215;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
LABEL_218:
              free(pMem);
              free(pMem: v149);
              free(pMem: v152);
              free(pMem: v148);
              free(pMem: v147);
              free(pMem: v127);
              *((_DWORD *)this + 12) = v130;
              *((_DWORD *)this + 13) = v131;
              *((_DWORD *)this + 26) = v122;
              v102 = v123;
              --*((_DWORD *)this + 17);
              *((_DWORD *)this + 27) = v102;
              return v22;
            }
          }
        }
      }
    }
  }
  v22 = -2147024882;
  goto LABEL_218;
}

//------------------------------------------------------------------------------
// Address: 0x101CFD04
// Name: protected: long D3DXShader::CCompiler::EmitForUnrolled(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitForUnrolled(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5,
        unsigned int *j)
{
  unsigned int *v7; // esi
  unsigned int v8; // esi
  bool v9; // zf
  int v10; // esi
  unsigned int v11; // edi
  int v12; // esi
  unsigned int v13; // eax
  unsigned int v14; // eax
  int v15; // ecx
  int v16; // eax
  _DWORD *v17; // ecx
  unsigned int v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int *v22; // esi
  int v23; // edi
  double v24; // st7
  double *v25; // ecx
  BOOL IsLimited; // eax
  unsigned int *v27; // esi
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  double v33; // st7
  void *v34; // eax
  void *v35; // eax
  _DWORD *v36; // edx
  double *v37; // ecx
  int v38; // esi
  int v39; // eax
  void *v40; // edi
  void *v41; // esi
  unsigned int v42; // kr00_4
  struct D3DXShader::CNode *v44; // [esp-10h] [ebp-98h]
  struct D3DXShader::CNode *v45; // [esp-Ch] [ebp-94h]
  unsigned int v46; // [esp-Ch] [ebp-94h]
  __int64 v47; // [esp-8h] [ebp-90h]
  __int64 v48; // [esp-8h] [ebp-90h]
  struct D3DXShader::CNode *v49; // [esp-8h] [ebp-90h]
  struct D3DXShader::CNode *v50; // [esp-8h] [ebp-90h]
  void *v51; // [esp-4h] [ebp-8Ch]
  void *v52; // [esp-4h] [ebp-8Ch]
  double v53; // [esp+Ch] [ebp-7Ch] BYREF
  double v54; // [esp+14h] [ebp-74h]
  double v55; // [esp+1Ch] [ebp-6Ch] BYREF
  double v56; // [esp+24h] [ebp-64h]
  int v57; // [esp+2Ch] [ebp-5Ch]
  unsigned int v58; // [esp+30h] [ebp-58h]
  unsigned int v59; // [esp+34h] [ebp-54h]
  unsigned int v60; // [esp+38h] [ebp-50h]
  void *v61; // [esp+3Ch] [ebp-4Ch]
  unsigned int v62; // [esp+40h] [ebp-48h] BYREF
  unsigned int v63; // [esp+44h] [ebp-44h] BYREF
  unsigned int *i; // [esp+48h] [ebp-40h]
  unsigned int v65; // [esp+4Ch] [ebp-3Ch] BYREF
  int v66; // [esp+50h] [ebp-38h]
  int v67; // [esp+54h] [ebp-34h]
  int v68; // [esp+58h] [ebp-30h]
  unsigned int v69; // [esp+5Ch] [ebp-2Ch] BYREF
  double *v70; // [esp+60h] [ebp-28h]
  void *v71; // [esp+64h] [ebp-24h]
  void *v72; // [esp+68h] [ebp-20h]
  void *v73; // [esp+6Ch] [ebp-1Ch]
  unsigned int v74; // [esp+70h] [ebp-18h]
  unsigned int *v75; // [esp+74h] [ebp-14h]
  void *v76; // [esp+78h] [ebp-10h]
  unsigned int nSize; // [esp+7Ch] [ebp-Ch]
  void *v78; // [esp+80h] [ebp-8h]
  void *pMem; // [esp+84h] [ebp-4h]

  v57 = *((_DWORD *)this + 22);
  v66 = *((_DWORD *)this + 23);
  v61 = *((void **)this + 6);
  v7 = *(unsigned int **)(*((_DWORD *)this + 1) + 24);
  v73 = nullptr;
  v76 = nullptr;
  v72 = nullptr;
  v78 = nullptr;
  v71 = nullptr;
  v75 = v7;
  nSize = 4 * (_DWORD)v7;
  pMem = MemAlloc_Alloc(nSize: 4 * (_DWORD)v7);
  if ( pMem == nullptr
    || (v73 = MemAlloc_Alloc(nSize)) == nullptr
    || (v8 = 16 * (_DWORD)v7, v60 = v8, (v76 = MemAlloc_Alloc(nSize: v8)) == nullptr)
    || (v72 = MemAlloc_Alloc(nSize: v8)) == nullptr
    || (v78 = MemAlloc_Alloc(nSize)) == nullptr
    || (v71 = MemAlloc_Alloc(nSize)) == nullptr )
  {
    v10 = -2147024882;
    goto LABEL_94;
  }
  v9 = a3 == 0;
  *((_DWORD *)this + 23) = 0;
  if ( v9 )
    goto LABEL_13;
  v10 = D3DXShader::CCompiler::EmitStatement(this, a2: (struct D3DXShader::CNode *)a3, a3: nullptr);
  if ( v10 >= 0 )
  {
    v10 = 0;
    if ( *((_DWORD *)this + 23) != 0 )
      v66 = 1;
    if ( *((_DWORD *)this + 20) == 0 && *((_DWORD *)this + 21) == 0 )
    {
LABEL_13:
      qmemcpy(pMem, *((const void **)this + 6), nSize);
      qmemcpy(j, *((const void **)this + 6), nSize);
      v11 = 0;
      if ( v75 != nullptr )
      {
        a3 = (unsigned int)v76;
        do
        {
          v12 = 4 * v11;
          v13 = *(_DWORD *)(4 * v11 + *((_DWORD *)this + 6));
          if ( v13 == -1 || D3DXShader::CCompiler::EvalRange(this, a2: v13, (struct D3DXShader::_D3DXRANGE *)a3) < 0 )
          {
            v14 = a3;
            *(double *)a3 = *((double *)this + 20);
            *(double *)(v14 + 8) = *((double *)this + 21);
          }
          v15 = *(_DWORD *)(v12 + *((_DWORD *)this + 6));
          if ( v15 == -1
            || (v16 = *((_DWORD *)this + 2),
                v17 = *(_DWORD **)(*(_DWORD *)(v16 + 20) + 4 * v15),
                *(_DWORD *)(v16 + 116) == v17[1]) )
          {
            *(_DWORD *)((char *)v78 + v12) = 31;
          }
          else
          {
            *(_DWORD *)((char *)v78 + v12) = *v17 & 0x1F;
          }
          a3 += 16;
          ++v11;
        }
        while ( v11 < (unsigned int)v75 );
      }
      v18 = *((_DWORD *)this + 8);
      v67 = 0;
      v62 = -1;
      v63 = -1;
      v74 = 0;
      v65 = v18;
      v69 = v18;
      v68 = 1;
      while ( 1 )
      {
        v19 = *((_DWORD *)this + 2);
        v20 = *(_DWORD *)(v19 + 8);
        v21 = *(_DWORD *)(v19 + 12);
        v58 = v20;
        v59 = v21;
        qmemcpy(v73, pMem, nSize);
        qmemcpy(v72, v76, v60);
        a3 = -1;
        qmemcpy(v71, v78, nSize);
        if ( a4 != nullptr )
        {
          a3 = -1;
          *((_DWORD *)this + 6) = pMem;
          v45 = a4;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
          v10 = D3DXShader::CCompiler::EmitExpression(this, a2: v45, &a3, a4: nullptr);
          if ( v10 < 0 )
            goto LABEL_94;
          HIDWORD(v47) = 23;
          LODWORD(v47) = &a3;
          v10 = D3DXShader::CCompiler::EmitInst((char **)this, a2: a4, a3: 0x20500001u, a4: &v65, a5: &v65, a6: v47);
          if ( v10 < 0 )
            goto LABEL_94;
          a3 = -1;
          *((_DWORD *)this + 6) = j;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
          v10 = D3DXShader::CCompiler::EmitExpression(this, a2: a4, &a3, a4: nullptr);
          if ( v10 < 0 )
            goto LABEL_94;
          HIDWORD(v48) = 23;
          LODWORD(v48) = &a3;
          v10 = D3DXShader::CCompiler::EmitInst((char **)this, a2: a4, a3: 0x20500001u, a4: &v69, a5: &v69, a6: v48);
          if ( v10 < 0 )
            goto LABEL_94;
          if ( *((_DWORD *)this + 22) == 0 && (*((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0) )
            goto LABEL_79;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
        }
        if ( D3DXShader::CCompiler::EvalRange(this, a2: v69, a3: (struct D3DXShader::_D3DXRANGE *)&v55) < 0 )
        {
          v55 = *((double *)this + 21);
          v56 = *((double *)this + 20);
        }
        if ( v55 > 0.0 || v56 < 0.0 )
          v67 = 1;
        if ( v75 != nullptr )
        {
          v22 = j;
          v70 = (double *)v76;
          v23 = (_BYTE *)v78 - (_BYTE *)j;
          i = v75;
          do
          {
            if ( *v22 == -1 )
            {
              v25 = v70;
            }
            else
            {
              if ( D3DXShader::CCompiler::EvalRange(this, a2: *v22, a3: (struct D3DXShader::_D3DXRANGE *)&v53) >= 0 )
              {
                v24 = v54;
              }
              else
              {
                v53 = *((double *)this + 20);
                v24 = *((double *)this + 21);
                v54 = v24;
              }
              v25 = v70;
              if ( v67 != 0 )
              {
                *v70 = v53;
                v25[1] = v24;
                *(unsigned int *)((char *)v22 + v23) = **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v22)
                                                     & 0x1F;
              }
              else
              {
                if ( *v70 > v53 )
                  *v70 = v53;
                if ( v24 > v25[1] )
                  v25[1] = v24;
                *(unsigned int *)((char *)v22 + v23) &= **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v22);
              }
            }
            ++v22;
            v9 = i == (unsigned int *)1;
            i = (unsigned int *)((char *)i - 1);
            v70 = v25 + 2;
          }
          while ( !v9 );
        }
        if ( 0.0 == v55 && 0.0 == v56 )
          goto LABEL_79;
        if ( v55 <= 0.0 && v56 >= 0.0 )
          *((_DWORD *)this + 22) = 1;
        if ( v68 != 0 )
        {
          if ( v67 != 0
            || (IsLimited = D3DXShader::CCompiler::IsLimited(this, a2: a3, a3: v74, a4: &v62, a5: &v63),
                v68 = 1,
                !IsLimited) )
          {
            v68 = 0;
          }
        }
        if ( v75 != nullptr )
        {
          v27 = j;
          v28 = (_BYTE *)pMem - (_BYTE *)j;
          v70 = (double *)((_BYTE *)pMem - (_BYTE *)j);
          for ( i = v75; i != nullptr; i = (unsigned int *)((char *)i - 1) )
          {
            v29 = *(unsigned int *)((char *)v27 + v28);
            if ( v29 != *v27 )
            {
              v30 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
              v31 = *(_DWORD *)(v30 + 4 * v29);
              v32 = *(_DWORD *)(v30 + 4 * *v27);
              *(_WORD *)v31 &= 0xFE60u;
              *(_DWORD *)v31 |= *(_DWORD *)v32 & 0x19F;
              *(double *)(v31 + 32) = *(double *)(v32 + 32);
              v33 = *(double *)(v32 + 40);
              v28 = (int)v70;
              *(double *)(v31 + 40) = v33;
            }
            ++v27;
          }
        }
        if ( a5 != nullptr )
        {
          v49 = a5;
          v46 = v69;
          *((_DWORD *)this + 6) = pMem;
          v44 = a4;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
          v10 = D3DXShader::CCompiler::EmitIf(this, a2: v44, a3: v46, a4: (unsigned int)v49, m: nullptr);
          if ( v10 < 0 )
            goto LABEL_94;
          v50 = a5;
          *((_DWORD *)this + 6) = j;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
          v10 = D3DXShader::CCompiler::EmitStatement(this, a2: v50, a3: nullptr);
          if ( v10 < 0 )
            goto LABEL_94;
          if ( *((_DWORD *)this + 22) == 0 && (*((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0) )
            goto LABEL_79;
          *((_DWORD *)this + 20) = 0;
          *((_DWORD *)this + 21) = 0;
        }
        if ( *((_DWORD *)this + 23) != 0 )
          break;
        if ( ++v74 >= 0x400 )
          goto LABEL_79;
      }
      v51 = v73;
      v73 = pMem;
      v34 = v76;
      v76 = v72;
      v72 = v34;
      v35 = v78;
      pMem = v51;
      v78 = v71;
      v71 = v35;
      D3DXShader::CCompiler::Reset(this, a2: v58, a3: v59, a4: (unsigned int *)v51);
      v9 = v74 == 0;
      *((_DWORD *)this + 19) = 0;
      *((_DWORD *)this + 20) = 0;
      *((_DWORD *)this + 21) = 0;
      if ( v9 )
        v66 = 1;
LABEL_79:
      if ( v74 == 1024 )
      {
        D3DXShader::CCompiler::Error(
          this,
          a2,
          a3: 0xDB7u,
          format: "loop does not appear to terminate in a timely manner (%d iterations)",
          1024);
      }
      else
      {
        if ( v75 != nullptr )
        {
          v36 = pMem;
          v37 = (double *)v76;
          v38 = (_BYTE *)v78 - (_BYTE *)pMem;
          for ( j = v75; j != nullptr; j = (unsigned int *)((char *)j - 1) )
          {
            if ( *v36 != -1 )
            {
              v39 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v36);
              *(double *)(v39 + 32) = *v37;
              *(double *)(v39 + 40) = v37[1];
              *(_DWORD *)v39 = *(_DWORD *)((char *)v36 + v38) | 0x180;
            }
            v37 += 2;
            ++v36;
          }
        }
        v40 = v61;
        v41 = pMem;
        v42 = nSize;
        *((_DWORD *)this + 6) = v61;
        qmemcpy(v40, v41, v42);
        if ( v74 == 0
          || v68 == 0
          || *((_DWORD *)this + 20) != 0
          || *((_DWORD *)this + 21) != 0
          || D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2: a4,
               a3: 0x10000001u,
               a4: (unsigned int *)(*((_DWORD *)this + 6) + 4 * v62),
               a5: &v63,
               a6: 0) >= 0 )
        {
          v10 = 0;
          goto LABEL_94;
        }
      }
      v10 = -2147467259;
    }
  }
LABEL_94:
  v52 = pMem;
  *((_DWORD *)this + 6) = v61;
  free(pMem: v52);
  free(pMem: v73);
  free(pMem: v76);
  free(pMem: v72);
  free(pMem: v78);
  free(pMem: v71);
  *((_DWORD *)this + 22) = v57;
  *((_DWORD *)this + 23) = v66;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101D039C
// Name: protected: long D3DXShader::CCompiler::EmitIntrinsic(class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitIntrinsic(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        unsigned int *a3)
{
  int result; // eax
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int *v8; // ecx
  int v9; // eax
  unsigned int *v10; // edi
  struct D3DXShader::CNode **v11; // esi
  void *v12; // eax
  unsigned int v13; // edi
  int v14; // esi
  int v15; // eax
  _DWORD *v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  struct D3DXShader::CNode *v19; // edx
  unsigned int *v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  unsigned int *v23; // eax
  unsigned int v24; // esi
  int v25; // eax
  unsigned int *v26; // eax
  unsigned int *v27; // eax
  unsigned int i; // ecx
  unsigned int *v29; // eax
  unsigned int *v30; // edx
  unsigned int v31; // eax
  unsigned int *v32; // eax
  unsigned int *v33; // eax
  D3DXShader::CBaseProgram *v34; // ecx
  unsigned int *v35; // eax
  unsigned int *v36; // esi
  unsigned int *v37; // eax
  unsigned int j; // ecx
  unsigned int *v39; // eax
  int v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // edx
  unsigned int v43; // edx
  int v44; // edx
  unsigned int v45; // edx
  int v46; // edx
  double v47; // st7
  unsigned int v48; // eax
  unsigned int v49; // edx
  unsigned int v50; // edx
  unsigned int v51; // edx
  unsigned int v52; // edx
  unsigned int v53; // edx
  unsigned int v54; // edx
  unsigned int v55; // esi
  unsigned int *v56; // eax
  unsigned int k; // ecx
  int v58; // eax
  int v59; // edx
  unsigned int *v60; // eax
  unsigned int *v61; // esi
  unsigned int *v62; // eax
  unsigned int m; // ecx
  int v64; // edx
  int v65; // esi
  unsigned int *v66; // eax
  unsigned int n; // ecx
  unsigned int v68; // eax
  unsigned int *v69; // eax
  unsigned int *v70; // edx
  unsigned int *v71; // esi
  unsigned int *v72; // eax
  unsigned int ii; // ecx
  unsigned int v74; // edx
  int v75; // edx
  int v76; // edx
  unsigned int *v77; // esi
  unsigned int *v78; // eax
  unsigned int jj; // ecx
  unsigned int *v80; // esi
  unsigned int *v81; // eax
  unsigned int kk; // ecx
  int v83; // esi
  unsigned int *v84; // eax
  unsigned int mm; // ecx
  int v86; // eax
  unsigned int v87; // eax
  int v88; // esi
  unsigned int *v89; // eax
  unsigned int nn; // ecx
  int v91; // eax
  unsigned int v92; // eax
  int v93; // esi
  unsigned int *v94; // eax
  unsigned int i1; // ecx
  unsigned int v96; // eax
  unsigned int *v97; // eax
  int v98; // eax
  int v99; // edx
  int v100; // edx
  unsigned int *v101; // eax
  unsigned int i2; // ecx
  unsigned int *v103; // eax
  unsigned int *v104; // esi
  unsigned int *v105; // eax
  unsigned int i3; // ecx
  unsigned int *v107; // eax
  unsigned int *v108; // eax
  unsigned int i4; // ecx
  int v110; // edx
  int v111; // edx
  int v112; // edx
  unsigned int *v113; // esi
  unsigned int *v114; // eax
  unsigned int i5; // ecx
  unsigned int *v116; // edx
  unsigned int v117; // eax
  unsigned int *v118; // edx
  unsigned int *v119; // edx
  unsigned int v120; // eax
  int v121; // eax
  unsigned int v122; // ecx
  unsigned int *v123; // eax
  unsigned int v124; // ecx
  unsigned int v125; // eax
  unsigned int v126; // esi
  unsigned int *v127; // eax
  unsigned int i9; // ecx
  unsigned int *v129; // eax
  unsigned int *v130; // ecx
  int v131; // edx
  unsigned int v132; // esi
  unsigned int *v133; // esi
  unsigned int v134; // eax
  unsigned int *v135; // ecx
  unsigned int v136; // edx
  unsigned int v137; // esi
  unsigned int v138; // eax
  unsigned int v139; // edx
  unsigned int *v140; // ecx
  unsigned int *v141; // esi
  int v142; // eax
  unsigned int *v143; // eax
  unsigned int v144; // ecx
  unsigned int v145; // edx
  unsigned int *v146; // eax
  unsigned int *v147; // ecx
  int v148; // edx
  unsigned int *v149; // esi
  unsigned int v150; // edx
  unsigned int v151; // eax
  _DWORD *v152; // ecx
  unsigned int *v153; // eax
  unsigned int v154; // ecx
  int v155; // eax
  unsigned int *v156; // edx
  unsigned int v157; // eax
  unsigned int v158; // edx
  int v159; // esi
  unsigned int *v160; // edx
  unsigned int v161; // edx
  unsigned int v162; // eax
  unsigned int *v163; // eax
  unsigned int *v164; // esi
  unsigned int v165; // ecx
  int v166; // edx
  unsigned int *v167; // edx
  unsigned int v168; // eax
  unsigned int v169; // edx
  unsigned int *v170; // esi
  unsigned int *v171; // eax
  unsigned int i11; // ecx
  unsigned int *v173; // eax
  int v174; // ecx
  unsigned int *v175; // eax
  int v176; // esi
  unsigned int *v177; // eax
  unsigned int i12; // ecx
  int v179; // edx
  unsigned int *v180; // esi
  unsigned int *v181; // eax
  unsigned int i13; // ecx
  unsigned int *v183; // eax
  int v184; // ecx
  int v185; // esi
  unsigned int *v186; // eax
  unsigned int i14; // ecx
  unsigned int v188; // esi
  unsigned int *v189; // edx
  unsigned int *v190; // edx
  unsigned int *v191; // eax
  D3DXShader::CBaseProgram *v192; // ecx
  unsigned int *v193; // eax
  unsigned int *v194; // esi
  unsigned int *v195; // eax
  unsigned int i15; // ecx
  unsigned int *v197; // eax
  int v198; // ecx
  unsigned int *v199; // eax
  D3DXShader::CBaseProgram *v200; // ecx
  unsigned int v201; // eax
  unsigned int *v202; // esi
  unsigned int *v203; // eax
  unsigned int i16; // ecx
  unsigned int v205; // edx
  int v206; // edx
  unsigned int *v207; // eax
  int v208; // ecx
  unsigned int v209; // esi
  unsigned int *v210; // eax
  int v211; // edx
  unsigned int *v212; // esi
  unsigned int *v213; // eax
  unsigned int i18; // ecx
  unsigned int *v215; // eax
  unsigned int *v216; // esi
  unsigned int *v217; // eax
  unsigned int i19; // ecx
  unsigned int v219; // edx
  unsigned int v220; // edx
  unsigned int v221; // edx
  unsigned int v222; // edx
  unsigned int v223; // edx
  unsigned int v224; // edx
  unsigned int v225; // edx
  unsigned int v226; // edx
  int v227; // edx
  unsigned int **v228; // eax
  unsigned int i20; // ecx
  _DWORD *v230; // eax
  _DWORD *v231; // ecx
  _DWORD *v232; // edx
  int v233; // edx
  unsigned int i21; // ecx
  unsigned int v235; // eax
  unsigned int i22; // eax
  unsigned int i23; // eax
  unsigned int i24; // eax
  unsigned int i25; // eax
  unsigned int *v240; // eax
  int v241; // ecx
  unsigned int *v242; // esi
  unsigned int i26; // eax
  unsigned int i27; // eax
  unsigned int i28; // eax
  unsigned int i29; // eax
  unsigned int *v247; // eax
  int v248; // ecx
  unsigned int *v249; // esi
  unsigned int i30; // eax
  unsigned int i31; // eax
  unsigned int i32; // eax
  unsigned int i33; // eax
  unsigned int *v254; // eax
  int v255; // ecx
  unsigned int *v256; // esi
  unsigned int i34; // eax
  unsigned int i35; // eax
  unsigned int i36; // eax
  unsigned int *v260; // eax
  unsigned int v261; // ecx
  char *v262; // edx
  unsigned int v263; // ecx
  unsigned int *v264; // eax
  unsigned int v265; // [esp-Ch] [ebp-214h]
  unsigned int v266; // [esp-Ch] [ebp-214h]
  unsigned int v267; // [esp-Ch] [ebp-214h]
  unsigned int *v268; // [esp-4h] [ebp-20Ch]
  unsigned int *v269; // [esp-4h] [ebp-20Ch]
  unsigned int *v270; // [esp-4h] [ebp-20Ch]
  unsigned int *v271; // [esp-4h] [ebp-20Ch]
  unsigned int *v272; // [esp-4h] [ebp-20Ch]
  __int64 v273; // [esp+0h] [ebp-208h]
  __int64 v274; // [esp+0h] [ebp-208h]
  __int64 v275; // [esp+0h] [ebp-208h]
  __int64 v276; // [esp+0h] [ebp-208h]
  __int64 v277; // [esp+0h] [ebp-208h]
  __int64 v278; // [esp+0h] [ebp-208h]
  __int64 v279; // [esp+0h] [ebp-208h]
  __int64 v280; // [esp+0h] [ebp-208h]
  __int64 v281; // [esp+0h] [ebp-208h]
  __int64 v282; // [esp+0h] [ebp-208h]
  __int64 v283; // [esp+0h] [ebp-208h]
  __int64 v284; // [esp+0h] [ebp-208h]
  __int64 v285; // [esp+0h] [ebp-208h]
  __int64 v286; // [esp+0h] [ebp-208h]
  unsigned int v287[3]; // [esp+14h] [ebp-1F4h] BYREF
  unsigned int v288[3]; // [esp+20h] [ebp-1E8h] BYREF
  unsigned int v289[3]; // [esp+2Ch] [ebp-1DCh] BYREF
  unsigned int v290[3]; // [esp+38h] [ebp-1D0h] BYREF
  unsigned int v291[3]; // [esp+44h] [ebp-1C4h] BYREF
  unsigned int v292[3]; // [esp+50h] [ebp-1B8h] BYREF
  unsigned int v293[3]; // [esp+5Ch] [ebp-1ACh] BYREF
  unsigned int v294[3]; // [esp+68h] [ebp-1A0h] BYREF
  unsigned int v295[3]; // [esp+74h] [ebp-194h] BYREF
  unsigned int v296[3]; // [esp+80h] [ebp-188h] BYREF
  unsigned int v297[3]; // [esp+8Ch] [ebp-17Ch] BYREF
  unsigned int v298[3]; // [esp+98h] [ebp-170h] BYREF
  int v299; // [esp+A4h] [ebp-164h]
  int v300; // [esp+A8h] [ebp-160h]
  int v301; // [esp+ACh] [ebp-15Ch]
  unsigned int v302[3]; // [esp+B0h] [ebp-158h] BYREF
  unsigned int v303[3]; // [esp+BCh] [ebp-14Ch] BYREF
  unsigned int v304; // [esp+C8h] [ebp-140h] BYREF
  int v305; // [esp+CCh] [ebp-13Ch]
  int v306; // [esp+D0h] [ebp-138h]
  unsigned int v307; // [esp+D4h] [ebp-134h] BYREF
  int v308; // [esp+D8h] [ebp-130h]
  int v309; // [esp+DCh] [ebp-12Ch]
  unsigned int v310; // [esp+E0h] [ebp-128h] BYREF
  int v311; // [esp+E4h] [ebp-124h]
  int v312; // [esp+E8h] [ebp-120h]
  unsigned int v313; // [esp+ECh] [ebp-11Ch] BYREF
  int v314; // [esp+F0h] [ebp-118h]
  int v315; // [esp+F4h] [ebp-114h]
  unsigned int v316; // [esp+F8h] [ebp-110h] BYREF
  unsigned int v317; // [esp+FCh] [ebp-10Ch] BYREF
  unsigned int v318; // [esp+100h] [ebp-108h] BYREF
  unsigned int *v319; // [esp+104h] [ebp-104h]
  unsigned int *v320; // [esp+108h] [ebp-100h]
  unsigned int *v321; // [esp+10Ch] [ebp-FCh] BYREF
  unsigned int *v322; // [esp+110h] [ebp-F8h]
  unsigned int *v323; // [esp+114h] [ebp-F4h]
  unsigned int *v324; // [esp+118h] [ebp-F0h] BYREF
  unsigned int *v325; // [esp+11Ch] [ebp-ECh]
  unsigned int *v326; // [esp+120h] [ebp-E8h]
  unsigned int *v327; // [esp+124h] [ebp-E4h] BYREF
  unsigned int *v328; // [esp+128h] [ebp-E0h]
  unsigned int *v329; // [esp+12Ch] [ebp-DCh]
  unsigned int *v330; // [esp+130h] [ebp-D8h] BYREF
  unsigned int *v331; // [esp+134h] [ebp-D4h]
  unsigned int *v332; // [esp+138h] [ebp-D0h]
  unsigned int v333; // [esp+13Ch] [ebp-CCh] BYREF
  unsigned int *v334; // [esp+140h] [ebp-C8h] BYREF
  unsigned int *v335; // [esp+144h] [ebp-C4h] BYREF
  unsigned int v336; // [esp+148h] [ebp-C0h] BYREF
  unsigned int v337; // [esp+14Ch] [ebp-BCh] BYREF
  unsigned int v338; // [esp+150h] [ebp-B8h] BYREF
  unsigned int *v339; // [esp+154h] [ebp-B4h]
  int v340; // [esp+158h] [ebp-B0h]
  unsigned int v341; // [esp+15Ch] [ebp-ACh] BYREF
  int v342; // [esp+160h] [ebp-A8h]
  unsigned int *v343; // [esp+164h] [ebp-A4h]
  unsigned int *v344; // [esp+168h] [ebp-A0h] BYREF
  unsigned int *v345; // [esp+16Ch] [ebp-9Ch]
  unsigned int *v346; // [esp+170h] [ebp-98h]
  unsigned int *v347; // [esp+174h] [ebp-94h] BYREF
  unsigned int *v348; // [esp+178h] [ebp-90h]
  unsigned int *v349; // [esp+17Ch] [ebp-8Ch]
  unsigned int *v350; // [esp+180h] [ebp-88h] BYREF
  unsigned int *v351; // [esp+184h] [ebp-84h]
  unsigned int *v352; // [esp+188h] [ebp-80h]
  unsigned int v353; // [esp+18Ch] [ebp-7Ch] BYREF
  unsigned int v354; // [esp+190h] [ebp-78h] BYREF
  unsigned int v355; // [esp+194h] [ebp-74h] BYREF
  unsigned int v356; // [esp+198h] [ebp-70h] BYREF
  unsigned int *v357; // [esp+19Ch] [ebp-6Ch] BYREF
  unsigned int *v358; // [esp+1A0h] [ebp-68h] BYREF
  unsigned int v359; // [esp+1A4h] [ebp-64h] BYREF
  unsigned int v360; // [esp+1A8h] [ebp-60h]
  unsigned int v361; // [esp+1ACh] [ebp-5Ch] BYREF
  unsigned int *v362; // [esp+1B0h] [ebp-58h] BYREF
  unsigned int *v363; // [esp+1B4h] [ebp-54h] BYREF
  unsigned int *i17; // [esp+1B8h] [ebp-50h] BYREF
  unsigned int v365; // [esp+1BCh] [ebp-4Ch] BYREF
  void *pMem; // [esp+1C0h] [ebp-48h] BYREF
  unsigned int *v367; // [esp+1C4h] [ebp-44h]
  unsigned int *v368; // [esp+1C8h] [ebp-40h]
  unsigned int **v369; // [esp+1CCh] [ebp-3Ch]
  unsigned int *v370; // [esp+1D0h] [ebp-38h]
  unsigned int *v371; // [esp+1D4h] [ebp-34h] BYREF
  unsigned int *v372; // [esp+1D8h] [ebp-30h]
  unsigned int *v373; // [esp+1DCh] [ebp-2Ch] BYREF
  unsigned int *v374; // [esp+1E0h] [ebp-28h]
  unsigned int *v375[2]; // [esp+1E4h] [ebp-24h] BYREF
  unsigned int *v376[2]; // [esp+1ECh] [ebp-1Ch] BYREF
  unsigned int i6; // [esp+1F4h] [ebp-14h] BYREF
  unsigned int *v378; // [esp+1F8h] [ebp-10h] BYREF
  unsigned int *i8; // [esp+1FCh] [ebp-Ch] BYREF
  unsigned int v380; // [esp+200h] [ebp-8h]
  unsigned int *v381; // [esp+204h] [ebp-4h]
  void **p_pMem; // [esp+210h] [ebp+8h]
  struct D3DXShader::CNode *v383; // [esp+210h] [ebp+8h]
  struct D3DXShader::CNode *v384; // [esp+210h] [ebp+8h]
  struct D3DXShader::CNode *v385; // [esp+210h] [ebp+8h]
  unsigned int *v386; // [esp+214h] [ebp+Ch]
  unsigned int *v387; // [esp+214h] [ebp+Ch]
  unsigned int *v388; // [esp+214h] [ebp+Ch]
  unsigned int *v389; // [esp+214h] [ebp+Ch]
  unsigned int i10; // [esp+214h] [ebp+Ch]
  unsigned int *v391; // [esp+214h] [ebp+Ch]
  unsigned int i7; // [esp+214h] [ebp+Ch]

  result = (int)a2;
  if ( a2 == nullptr )
  {
    if ( a3 == nullptr )
      return result;
    return -2147467259;
  }
  if ( *((_DWORD *)a2 + 1) != 13 )
    return -2147467259;
  v5 = *((_DWORD *)a2 + 7) == 26;
  v381 = (unsigned int *)(*((_DWORD *)a2 + 6) * *((_DWORD *)a2 + 5));
  v6 = *((_DWORD *)a2 + 9);
  v299 = v6;
  if ( !v5 )
    return -2147467259;
  v301 = *((_DWORD *)this + 7);
  v375[0] = nullptr;
  v375[1] = nullptr;
  v376[0] = nullptr;
  v376[1] = nullptr;
  v7 = *(_DWORD *)(v6 + 8);
  v337 = 0;
  v338 = 0;
  v339 = nullptr;
  v340 = 0;
  pMem = nullptr;
  v367 = nullptr;
  v368 = nullptr;
  v369 = nullptr;
  v300 = *((_DWORD *)this + 25);
  v361 = 234881024;
  v359 = v7;
  if ( v7 == 0 )
    goto LABEL_16;
  i8 = nullptr;
  do
  {
    v8 = *(unsigned int **)(v359 + 8);
    if ( v8 != nullptr )
    {
      v9 = v8[5] * v8[6];
      v10 = i8;
      *(unsigned int *)((char *)&v337 + (_DWORD)i8) = v9;
      v11 = (struct D3DXShader::CNode **)((char *)v375 + (_DWORD)v10);
      *(unsigned int **)((char *)v375 + (_DWORD)v10) = v8;
      v12 = MemAlloc_Alloc(nSize: 4 * v9);
      *(void **)((char *)&pMem + (_DWORD)v10) = v12;
      v13 = 0;
      i6 = (unsigned int)v12;
      if ( v12 == nullptr )
      {
LABEL_901:
        v14 = -2147024882;
        goto LABEL_1100;
      }
      v14 = D3DXShader::CCompiler::EmitExpression(this, a2: *v11, a3: (unsigned int *)v12, a4: nullptr);
      if ( v14 < 0 )
        goto LABEL_1100;
      if ( *(unsigned int *)((char *)&v337 + (_DWORD)i8) != 0 )
      {
        v15 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
        v16 = (_DWORD *)i6;
        v17 = *(unsigned int *)((char *)&v337 + (_DWORD)i8);
        do
        {
          v361 &= **(_DWORD **)(v15 + 4 * *v16++);
          --v17;
        }
        while ( v17 != 0 );
      }
    }
    v18 = *(_DWORD *)(v359 + 12);
    ++i8;
    v359 = v18;
  }
  while ( v18 != 0 );
  if ( v361 == 234881024 )
LABEL_16:
    v361 = 0;
  v19 = a2;
  *((_DWORD *)this + 25) = v361;
  switch ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)a2 + 8) + 8) + 24) )
  {
    case 0:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v20 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      v378 = v20;
      if ( v20 == nullptr )
        goto LABEL_901;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v20, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
        if ( v14 >= 0 )
        {
          v380 = (unsigned int)v381 & 0xFFFFF;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: (unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF,
                  a4: v378,
                  a5: (unsigned int *)pMem,
                  a6: 0);
          if ( v14 >= 0 )
          {
            v273 = (unsigned int)v378 | 0x400000000LL;
            v21 = v380 | 0x20100000;
            goto LABEL_25;
          }
        }
      }
      break;
    case 1:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v22 = D3DXShader::CCompiler::EmitASinACos(
                this,
                a2,
                a3: (unsigned int *)pMem,
                a4: nullptr,
                a5: a3,
                a6: (unsigned int)v381);
        goto LABEL_27;
      }
      break;
    case 2:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v24 = v337;
      switch ( v337 )
      {
        case 1u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v25 = D3DXShader::CCompiler::EmitPositive(this, a2, a3: &i6, a4: &v365, a5: (unsigned int *)pMem, a6: 1u);
LABEL_46:
          v14 = v25;
          if ( v25 >= 0 )
          {
            HIDWORD(v274) = 23;
            LODWORD(v274) = &i6;
            v26 = &v365;
            goto LABEL_48;
          }
          goto LABEL_1100;
        case 2u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v358, a3: 1u);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: 0x20500001u,
                          a4: &i6,
                          a5: (unsigned int *)pMem,
                          a6: (unsigned int)pMem + 4);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitPositive(
                            this,
                            a2,
                            a3: &v365,
                            a4: (unsigned int *)&v358,
                            a5: &i6,
                            a6: 1u);
                    if ( v14 >= 0 )
                    {
                      HIDWORD(v274) = 23;
                      LODWORD(v274) = &v365;
                      v26 = (unsigned int *)&v358;
                      goto LABEL_48;
                    }
                  }
                }
              }
            }
          }
          break;
        case 3u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v363, a3: 2u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: 0x20500001u,
                  a4: (unsigned int *)&v363,
                  a5: (unsigned int *)pMem,
                  a6: (unsigned int)pMem + 4);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: 0x20500001u,
                  a4: (unsigned int *)&i17,
                  a5: (unsigned int *)&v363,
                  a6: (unsigned int)pMem + 8);
          if ( v14 < 0 )
            goto LABEL_1100;
          v25 = D3DXShader::CCompiler::EmitPositive(this, a2, a3: &i6, a4: &v365, a5: (unsigned int *)&i17, a6: 1u);
          goto LABEL_46;
        default:
          v27 = D3DXShader::CCompiler::Scratch(this, a2: 3 * v337);
          if ( v27 == nullptr )
            goto LABEL_901;
          for ( i = 0; i < 3; ++i )
          {
            (&v362)[i] = v27;
            v27 += v24;
          }
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v362, a3: v337);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v363, a3: v337);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: i17, a3: v337);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&i8, a3: 1u);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
                    if ( v14 >= 0 )
                    {
                      v361 = v337 & 0xFFFFF;
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: v337 & 0xFFFFF | 0x20500000,
                              a4: v362,
                              a5: (unsigned int *)pMem,
                              a6: (unsigned int)pMem | 0x400000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: (unsigned int)&loc_10100000 | v361,
                                a4: v363,
                                a5: v362,
                                a6: 0x800000000LL);
                        if ( v14 >= 0 )
                        {
                          v14 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: v361 | 0x20300000,
                                  a4: i17,
                                  a5: v363,
                                  a6: (unsigned int)v362 | 0x1700000000LL);
                          if ( v14 >= 0 )
                          {
                            v14 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: v361 | 0x50000000,
                                    a4: (unsigned int *)&i8,
                                    a5: i17,
                                    a6: (unsigned int)i17 | 0x600000000LL);
                            if ( v14 >= 0 )
                            {
                              v14 = D3DXShader::CCompiler::EmitInst(
                                      (char **)this,
                                      a2,
                                      a3: 0x10100001u,
                                      a4: &i6,
                                      a5: (unsigned int *)&i8,
                                      a6: 0xA00000000LL);
                              if ( v14 >= 0 )
                              {
                                HIDWORD(v275) = 23;
                                LODWORD(v275) = &i8;
                                v22 = D3DXShader::CCompiler::EmitInst(
                                        (char **)this,
                                        a2,
                                        a3: 0x20300001u,
                                        a4: a3,
                                        a5: &i6,
                                        a6: v275);
                                goto LABEL_27;
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
          break;
      }
      break;
    case 3:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&i8, a3: 1u);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: v337 & 0xFFFFF | 0x50000000,
                    a4: (unsigned int *)&i8,
                    a5: (unsigned int *)pMem,
                    a6: (unsigned int)pMem | 0x400000000LL);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x10100001u,
                      a4: &i6,
                      a5: (unsigned int *)&i8,
                      a6: 0x800000000LL);
              if ( v14 >= 0 )
              {
                HIDWORD(v274) = 23;
                LODWORD(v274) = &i8;
                v26 = &i6;
LABEL_48:
                v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20200001u, a4: a3, a5: v26, a6: v274);
                goto LABEL_27;
              }
            }
          }
        }
      }
      break;
    case 4:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v22 = D3DXShader::CCompiler::EmitASinACos(
                this,
                a2,
                a3: (unsigned int *)pMem,
                a4: a3,
                a5: nullptr,
                a6: (unsigned int)v381);
        goto LABEL_27;
      }
      break;
    case 5:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v22 = D3DXShader::CCompiler::EmitATan2(
                this,
                a2,
                a3: (unsigned int *)pMem,
                a4: nullptr,
                a5: a3,
                a6: (unsigned int)v381);
        goto LABEL_27;
      }
      break;
    case 6:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v22 = D3DXShader::CCompiler::EmitATan2(
                this,
                a2,
                a3: (unsigned int *)pMem,
                a4: v367,
                a5: a3,
                a6: (unsigned int)v381);
        goto LABEL_27;
      }
      break;
    case 7:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v29 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (_DWORD)v381);
      v378 = v29;
      if ( v29 == nullptr )
        goto LABEL_901;
      i8 = &v29[(_DWORD)v381];
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v29, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v30, a3: (unsigned int)v381);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
          if ( v14 >= 0 )
          {
            v380 = (unsigned int)v381 & 0xFFFFF;
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF,
                    a4: v378,
                    a5: (unsigned int *)pMem,
                    a6: 0);
            if ( v14 >= 0 )
            {
              HIDWORD(v276) = 20;
              v31 = v380 | 0x10400000;
              goto LABEL_109;
            }
          }
        }
      }
      break;
    case 8:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v32 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      v378 = v32;
      if ( v32 == nullptr )
        goto LABEL_901;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v32, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
        if ( v14 >= 0 )
        {
          v380 = (unsigned int)v381 & 0xFFFFF;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: (unsigned int)v381 & 0xFFFFF | 0x20100000,
                  a4: v378,
                  a5: (unsigned int *)pMem,
                  a6: (unsigned int)v367);
          if ( v14 >= 0 )
          {
            v273 = (unsigned int)v368;
            v268 = v378;
            goto LABEL_799;
          }
        }
      }
      break;
    case 9:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      v22 = D3DXShader::CCompiler::EmitClip(this, a2, a3: (unsigned int *)pMem, a4: v337);
      goto LABEL_27;
    case 0xA:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitSinCos(
              this,
              a2,
              a3: (unsigned int *)pMem,
              a4: nullptr,
              a5: a3,
              a6: (unsigned int)v381);
      goto LABEL_27;
    case 0xB:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v33 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                              this: *((D3DXShader::CBaseProgram **)this + 2),
                              a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                              a3: 0,
                              a4: 0,
                              a5: 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v34 = *((D3DXShader::CBaseProgram **)this + 2);
      v265 = *((_DWORD *)v34 + 30);
      i17 = v33;
      v35 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(this: v34, a2: v265, a3: 0, a4: 0, a5: 0.5);
      v36 = v381;
      v357 = v35;
      v37 = D3DXShader::CCompiler::Scratch(this, a2: 7 * (_DWORD)v381);
      if ( v37 == nullptr )
        goto LABEL_901;
      for ( j = 0; j < 7; ++j )
      {
        (&v372)[j] = v37;
        v37 += (int)v36;
      }
      if ( v36 != nullptr )
      {
        v39 = v376[1];
        v40 = (char *)v376[0] - (char *)v376[1];
        do
        {
          *(unsigned int *)((char *)v39 + v40) = (unsigned int)i17;
          *v39++ = (unsigned int)v357;
          v36 = (unsigned int *)((char *)v36 - 1);
        }
        while ( v36 != nullptr );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v372, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v373, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v374, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v360 = (unsigned int)v381 & 0xFFFFF | 0x20500000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v360,
              a4: v372,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v376[0]);
      if ( v14 < 0 )
        break;
      i8 = (unsigned int *)(v380 | 0x10500000);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10500000,
              a4: v373,
              a5: v372,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v374,
              a5: v372,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)i8,
              a4: v375[0],
              a5: v374,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v375[1],
              a5: v373,
              a6: (unsigned int)v375[0] | 0x400000000LL);
      if ( v14 < 0 )
        break;
      HIDWORD(v277) = 4;
      goto LABEL_147;
    case 0xC:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v362 = *((unsigned int **)pMem + 1);
      v363 = *((unsigned int **)pMem + 2);
      i17 = *(unsigned int **)pMem;
      v334 = (unsigned int *)v367[2];
      v335 = (unsigned int *)*v367;
      v336 = v367[1];
      v303[0] = *((_DWORD *)pMem + 2);
      v303[1] = *(_DWORD *)pMem;
      v303[2] = *((_DWORD *)pMem + 1);
      v355 = v367[1];
      v356 = v367[2];
      v357 = (unsigned int *)*v367;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v375[1], a3: 3u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v302, a3: v41);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v338, a3: v42);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: v43);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v360 = (unsigned int)v381 & 0xFFFFF | 0x20500000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v360,
              a4: (unsigned int *)&v375[1],
              a5: (unsigned int *)&v362,
              a6: (unsigned int)&v334);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v360, a4: v302, a5: v303, a6: (unsigned int)&v355);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: &v338,
              a5: v302,
              a6: 0);
      if ( v14 < 0 )
        break;
      HIDWORD(v273) = 0;
      LODWORD(v273) = &v338;
      v268 = (unsigned int *)&v375[1];
      goto LABEL_111;
    case 0xD:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0;
      v270 = (unsigned int *)pMem;
      v45 = v44 & 0xFFFFF | 0x10D00000;
      goto LABEL_884;
    case 0xE:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0;
      v270 = (unsigned int *)pMem;
      v45 = v46 & 0xFFFFF | 0x10E00000;
      goto LABEL_884;
    case 0xF:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v47 = 57.29577791868205;
      goto LABEL_696;
    case 0x10:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( v337 == 1 )
      {
        *a3 = *(_DWORD *)pMem;
        goto LABEL_28;
      }
      v48 = v375[0][5];
      switch ( v48 )
      {
        case 2u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v334, a3: 3u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
            if ( v14 >= 0 )
            {
              v356 = *(_DWORD *)pMem;
              v363 = *((unsigned int **)pMem + 3);
              v357 = *((unsigned int **)pMem + 1);
              i17 = *((unsigned int **)pMem + 2);
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x20500002u,
                      a4: (unsigned int *)&v334,
                      a5: &v356,
                      a6: (unsigned int)&v363);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: 0x10100001u,
                        a4: &v336,
                        a5: (unsigned int *)&v335,
                        a6: 0);
                if ( v14 >= 0 )
                {
                  HIDWORD(v279) = 0;
                  LODWORD(v279) = &v336;
                  v271 = (unsigned int *)&v334;
                  goto LABEL_180;
                }
              }
            }
          }
          break;
        case 3u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v302, a3: 3u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v375[1], a3: v49);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v338, a3: v50);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v303, a3: v51);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
                  if ( v14 >= 0 )
                  {
                    v362 = *((unsigned int **)pMem + 4);
                    v363 = *((unsigned int **)pMem + 7);
                    i17 = *((unsigned int **)pMem + 1);
                    v355 = *((_DWORD *)pMem + 8);
                    v356 = *((_DWORD *)pMem + 2);
                    v357 = *((unsigned int **)pMem + 5);
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: 0x20500003u,
                            a4: v302,
                            a5: (unsigned int *)&v362,
                            a6: (unsigned int)&v355);
                    if ( v14 >= 0 )
                    {
                      v362 = *((unsigned int **)pMem + 7);
                      v363 = *((unsigned int **)pMem + 1);
                      i17 = *((unsigned int **)pMem + 4);
                      v355 = *((_DWORD *)pMem + 5);
                      v356 = *((_DWORD *)pMem + 8);
                      v357 = *((unsigned int **)pMem + 2);
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: 0x20500003u,
                              a4: (unsigned int *)&v375[1],
                              a5: (unsigned int *)&v362,
                              a6: (unsigned int)&v355);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: (unsigned int)&loc_10100003,
                                a4: &v338,
                                a5: (unsigned int *)&v375[1],
                                a6: 0);
                        if ( v14 >= 0 )
                        {
                          v14 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: 0x20400003u,
                                  a4: v303,
                                  a5: v302,
                                  a6: (unsigned int)&v338);
                          if ( v14 >= 0 )
                          {
                            v362 = *(unsigned int **)pMem;
                            v363 = *((unsigned int **)pMem + 3);
                            i17 = *((unsigned int **)pMem + 6);
                            v22 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: 0x50000003u,
                                    a4: a3,
                                    a5: v303,
                                    a6: (unsigned int)&v362);
                            goto LABEL_27;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          break;
        case 4u:
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v291, a3: 0xCu);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v295, a3: v52);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v287, a3: v53);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v321, a3: v54);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)v375, a3: 4u);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
                    if ( v14 >= 0 )
                    {
                      v341 = *((_DWORD *)pMem + 10);
                      v342 = *((_DWORD *)pMem + 14);
                      v343 = *((unsigned int **)pMem + 6);
                      v344 = *((unsigned int **)pMem + 14);
                      v345 = *((unsigned int **)pMem + 2);
                      v346 = *((unsigned int **)pMem + 10);
                      v347 = *((unsigned int **)pMem + 6);
                      v348 = *((unsigned int **)pMem + 14);
                      v349 = *((unsigned int **)pMem + 2);
                      v350 = *((unsigned int **)pMem + 10);
                      v351 = *((unsigned int **)pMem + 2);
                      v352 = *((unsigned int **)pMem + 6);
                      v304 = *((_DWORD *)pMem + 15);
                      v305 = *((_DWORD *)pMem + 7);
                      v306 = *((_DWORD *)pMem + 11);
                      v307 = *((_DWORD *)pMem + 11);
                      v308 = *((_DWORD *)pMem + 15);
                      v309 = *((_DWORD *)pMem + 3);
                      v310 = *((_DWORD *)pMem + 15);
                      v311 = *((_DWORD *)pMem + 3);
                      v312 = *((_DWORD *)pMem + 7);
                      v313 = *((_DWORD *)pMem + 7);
                      v314 = *((_DWORD *)pMem + 11);
                      v315 = *((_DWORD *)pMem + 3);
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: 0x20500003u,
                              a4: v291,
                              a5: &v341,
                              a6: (unsigned int)&v304);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: 0x20500003u,
                                a4: v292,
                                a5: (unsigned int *)&v344,
                                a6: (unsigned int)&v307);
                        if ( v14 >= 0 )
                        {
                          v14 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: 0x20500003u,
                                  a4: v293,
                                  a5: (unsigned int *)&v347,
                                  a6: (unsigned int)&v310);
                          if ( v14 >= 0 )
                          {
                            v14 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: 0x20500003u,
                                    a4: v294,
                                    a5: (unsigned int *)&v350,
                                    a6: (unsigned int)&v313);
                            if ( v14 >= 0 )
                            {
                              v341 = *((_DWORD *)pMem + 14);
                              v342 = *((_DWORD *)pMem + 6);
                              v343 = *((unsigned int **)pMem + 10);
                              v344 = *((unsigned int **)pMem + 10);
                              v345 = *((unsigned int **)pMem + 14);
                              v346 = *((unsigned int **)pMem + 2);
                              v347 = *((unsigned int **)pMem + 14);
                              v348 = *((unsigned int **)pMem + 2);
                              v349 = *((unsigned int **)pMem + 6);
                              v350 = *((unsigned int **)pMem + 6);
                              v351 = *((unsigned int **)pMem + 10);
                              v352 = *((unsigned int **)pMem + 2);
                              v304 = *((_DWORD *)pMem + 11);
                              v305 = *((_DWORD *)pMem + 15);
                              v306 = *((_DWORD *)pMem + 7);
                              v307 = *((_DWORD *)pMem + 15);
                              v308 = *((_DWORD *)pMem + 3);
                              v309 = *((_DWORD *)pMem + 11);
                              v310 = *((_DWORD *)pMem + 7);
                              v311 = *((_DWORD *)pMem + 15);
                              v312 = *((_DWORD *)pMem + 3);
                              v313 = *((_DWORD *)pMem + 11);
                              v314 = *((_DWORD *)pMem + 3);
                              v315 = *((_DWORD *)pMem + 7);
                              v14 = D3DXShader::CCompiler::EmitInst(
                                      (char **)this,
                                      a2,
                                      a3: 0x20500003u,
                                      a4: v295,
                                      a5: &v341,
                                      a6: (unsigned int)&v304);
                              if ( v14 >= 0 )
                              {
                                v14 = D3DXShader::CCompiler::EmitInst(
                                        (char **)this,
                                        a2,
                                        a3: 0x20500003u,
                                        a4: v296,
                                        a5: (unsigned int *)&v344,
                                        a6: (unsigned int)&v307);
                                if ( v14 >= 0 )
                                {
                                  v14 = D3DXShader::CCompiler::EmitInst(
                                          (char **)this,
                                          a2,
                                          a3: 0x20500003u,
                                          a4: v297,
                                          a5: (unsigned int *)&v347,
                                          a6: (unsigned int)&v310);
                                  if ( v14 >= 0 )
                                  {
                                    v14 = D3DXShader::CCompiler::EmitInst(
                                            (char **)this,
                                            a2,
                                            a3: 0x20500003u,
                                            a4: v298,
                                            a5: (unsigned int *)&v350,
                                            a6: (unsigned int)&v313);
                                    if ( v14 >= 0 )
                                    {
                                      v14 = D3DXShader::CCompiler::EmitInst(
                                              (char **)this,
                                              a2,
                                              a3: (unsigned int)&loc_10100003,
                                              a4: v287,
                                              a5: v295,
                                              a6: 0);
                                      if ( v14 >= 0 )
                                      {
                                        v14 = D3DXShader::CCompiler::EmitInst(
                                                (char **)this,
                                                a2,
                                                a3: (unsigned int)&loc_10100003,
                                                a4: v288,
                                                a5: v296,
                                                a6: 0);
                                        if ( v14 >= 0 )
                                        {
                                          v14 = D3DXShader::CCompiler::EmitInst(
                                                  (char **)this,
                                                  a2,
                                                  a3: (unsigned int)&loc_10100003,
                                                  a4: v289,
                                                  a5: v297,
                                                  a6: 0);
                                          if ( v14 >= 0 )
                                          {
                                            v14 = D3DXShader::CCompiler::EmitInst(
                                                    (char **)this,
                                                    a2,
                                                    a3: (unsigned int)&loc_10100003,
                                                    a4: v290,
                                                    a5: v298,
                                                    a6: 0);
                                            if ( v14 >= 0 )
                                            {
                                              v14 = D3DXShader::CCompiler::EmitInst(
                                                      (char **)this,
                                                      a2,
                                                      a3: 0x20400003u,
                                                      a4: (unsigned int *)&v321,
                                                      a5: v291,
                                                      a6: (unsigned int)v287);
                                              if ( v14 >= 0 )
                                              {
                                                v14 = D3DXShader::CCompiler::EmitInst(
                                                        (char **)this,
                                                        a2,
                                                        a3: 0x20400003u,
                                                        a4: (unsigned int *)&v324,
                                                        a5: v292,
                                                        a6: (unsigned int)v288);
                                                if ( v14 >= 0 )
                                                {
                                                  v14 = D3DXShader::CCompiler::EmitInst(
                                                          (char **)this,
                                                          a2,
                                                          a3: 0x20400003u,
                                                          a4: (unsigned int *)&v327,
                                                          a5: v293,
                                                          a6: (unsigned int)v289);
                                                  if ( v14 >= 0 )
                                                  {
                                                    v14 = D3DXShader::CCompiler::EmitInst(
                                                            (char **)this,
                                                            a2,
                                                            a3: 0x20400003u,
                                                            a4: (unsigned int *)&v330,
                                                            a5: v294,
                                                            a6: (unsigned int)v290);
                                                    if ( v14 >= 0 )
                                                    {
                                                      v341 = *((_DWORD *)pMem + 5);
                                                      v342 = *((_DWORD *)pMem + 9);
                                                      v343 = *((unsigned int **)pMem + 13);
                                                      v344 = *((unsigned int **)pMem + 1);
                                                      v345 = *((unsigned int **)pMem + 9);
                                                      v346 = *((unsigned int **)pMem + 13);
                                                      v347 = *((unsigned int **)pMem + 1);
                                                      v348 = *((unsigned int **)pMem + 5);
                                                      v349 = *((unsigned int **)pMem + 13);
                                                      v350 = *((unsigned int **)pMem + 1);
                                                      v351 = *((unsigned int **)pMem + 5);
                                                      v352 = *((unsigned int **)pMem + 9);
                                                      v14 = D3DXShader::CCompiler::EmitInst(
                                                              (char **)this,
                                                              a2,
                                                              a3: 0x50000003u,
                                                              a4: (unsigned int *)v375,
                                                              a5: (unsigned int *)&v321,
                                                              a6: (unsigned int)&v341);
                                                      if ( v14 >= 0 )
                                                      {
                                                        v14 = D3DXShader::CCompiler::EmitInst(
                                                                (char **)this,
                                                                a2,
                                                                a3: 0x50000003u,
                                                                a4: (unsigned int *)&v375[1],
                                                                a5: (unsigned int *)&v324,
                                                                a6: (unsigned int)&v344);
                                                        if ( v14 >= 0 )
                                                        {
                                                          v14 = D3DXShader::CCompiler::EmitInst(
                                                                  (char **)this,
                                                                  a2,
                                                                  a3: 0x50000003u,
                                                                  a4: (unsigned int *)v376,
                                                                  a5: (unsigned int *)&v327,
                                                                  a6: (unsigned int)&v347);
                                                          if ( v14 >= 0 )
                                                          {
                                                            v14 = D3DXShader::CCompiler::EmitInst(
                                                                    (char **)this,
                                                                    a2,
                                                                    a3: 0x50000003u,
                                                                    a4: (unsigned int *)&v376[1],
                                                                    a5: (unsigned int *)&v330,
                                                                    a6: (unsigned int)&v350);
                                                            if ( v14 >= 0 )
                                                            {
                                                              v341 = *(_DWORD *)pMem;
                                                              v342 = *((_DWORD *)pMem + 4);
                                                              v343 = *((unsigned int **)pMem + 8);
                                                              v344 = *((unsigned int **)pMem + 12);
                                                              v22 = D3DXShader::CCompiler::EmitInst(
                                                                      (char **)this,
                                                                      a2,
                                                                      a3: 0x50000004u,
                                                                      a4: a3,
                                                                      a5: (unsigned int *)v375,
                                                                      a6: (unsigned int)&v341);
                                                              goto LABEL_27;
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
          break;
        default:
          goto LABEL_28;
      }
      break;
    case 0x11:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v55 = v337;
      v56 = D3DXShader::CCompiler::Scratch(this, a2: 2 * v337);
      if ( v56 == nullptr )
        goto LABEL_901;
      for ( k = 0; k < 2; ++k )
      {
        (&v363)[k] = v56;
        v56 += v55;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v363, a3: v337);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: i17, a3: v337);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
      if ( v14 < 0 )
        break;
      v361 = v337 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v337 & 0xFFFFF,
              a4: v363,
              a5: v367,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v361 | 0x20400000,
              a4: i17,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v363);
      if ( v14 < 0 )
        break;
      v58 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v361 | 0x50000000,
              a4: &i6,
              a5: i17,
              a6: (unsigned int)i17 | 0x400000000LL);
      goto LABEL_234;
    case 0x12:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v367;
      v21 = v337 & 0xFFFFF | 0x50000000;
      goto LABEL_25;
    case 0x13:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v371 = *((unsigned int **)this + 8);
      v372 = *((unsigned int **)pMem + 1);
      v373 = *((unsigned int **)pMem + 2);
      v374 = v371;
      v375[0] = v371;
      v375[1] = (unsigned int *)v367[1];
      v376[0] = v371;
      v376[1] = (unsigned int *)v367[3];
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      HIDWORD(v278) = 0;
      LODWORD(v278) = v375;
      v270 = (unsigned int *)&v371;
      v45 = v59 & 0xFFFFF | 0x20500000;
      goto LABEL_884;
    case 0x14:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v60 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                              this: *((D3DXShader::CBaseProgram **)this + 2),
                              a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                              a3: 0,
                              a4: 0,
                              a5: 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v61 = v381;
      i17 = v60;
      v62 = D3DXShader::CCompiler::Scratch(this, a2: 3 * (_DWORD)v381);
      if ( v62 == nullptr )
        goto LABEL_901;
      for ( m = 0; m < 3; ++m )
      {
        (&v334)[m] = v62;
        v62 += (int)v61;
      }
      if ( v61 != nullptr )
      {
        memset32(v334, (int)i17, (unsigned int)v381);
        v13 = 0;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v335, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x20500000,
              a4: v335,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v334);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10500000,
              a4: a3,
              a5: v335,
              a6: 0x400000000LL);
      goto LABEL_27;
    case 0x15:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0x400000000LL;
      v270 = (unsigned int *)pMem;
      v45 = v64 & 0xFFFFF | 0x10500000;
      goto LABEL_884;
    case 0x16:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x50000000,
              a4: &i6,
              a5: v367,
              a6: (unsigned int)v368);
      if ( v14 < 0 )
        break;
      HIDWORD(v280) = 23;
      LODWORD(v280) = (char *)this + 36;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20300001u, a4: &v365, a5: &i6, a6: v280);
      if ( v14 < 0 )
        break;
      v65 = 4 * (_DWORD)v381;
      v66 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
      if ( v66 == nullptr )
        goto LABEL_901;
      for ( n = 0; n < 4; ++n )
      {
        v375[n] = v66;
        v66 = (unsigned int *)((char *)v66 + v65);
      }
      v68 = 0;
      if ( v381 != nullptr )
      {
        do
          v376[1][v68++] = v365;
        while ( v68 < (unsigned int)v381 );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v375[0],
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v359 = v380 | 0x20400000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v375[1],
              a5: v375[0],
              a6: (unsigned int)v375[0]);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20500000,
              a4: v376[0],
              a5: v375[1],
              a6: (unsigned int)v376[1]);
      if ( v14 < 0 )
        break;
      v281 = (unsigned int)v376[0];
      goto LABEL_283;
    case 0x17:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v69 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (_DWORD)v381);
      v378 = v69;
      if ( v69 == nullptr )
        goto LABEL_901;
      i8 = &v69[(_DWORD)v381];
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v69, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v70, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x10400000,
              a4: v378,
              a5: (unsigned int *)pMem,
              a6: 0x1400000000LL);
      if ( v14 < 0 )
        break;
      HIDWORD(v276) = 24;
      v31 = (unsigned int)&loc_10100000 | v380;
LABEL_109:
      LODWORD(v276) = 0;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v31, a4: i8, a5: v378, a6: v276);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)i8 | 0x200000000LL;
      v268 = (unsigned int *)pMem;
      goto LABEL_111;
    case 0x18:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v71 = v381;
      v72 = D3DXShader::CCompiler::Scratch(this, a2: 8 * (_DWORD)v381);
      if ( v72 == nullptr )
        goto LABEL_901;
      for ( ii = 0; ii < 8; ++ii )
      {
        (&v371)[ii] = v72;
        v72 += (int)v71;
      }
      v74 = 0;
      while ( 1 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (&v371)[v74], a3: (unsigned int)v381);
        if ( v14 < 0 )
          goto LABEL_1100;
        v74 = v75 + 1;
        if ( v74 >= 8 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
          if ( v14 >= 0 )
          {
            v380 = (unsigned int)v381 & 0xFFFFF;
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (unsigned int)&unk_10300000 | (unsigned int)v381 & 0xFFFFF,
                    a4: v371,
                    a5: v367,
                    a6: 0);
            if ( v14 >= 0 )
            {
              v360 = v380 | 0x20500000;
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: v380 | 0x20500000,
                      a4: v372,
                      a5: (unsigned int *)pMem,
                      a6: (unsigned int)v371);
              if ( v14 >= 0 )
              {
                v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: (unsigned int)&loc_10100000 | v380,
                        a4: v373,
                        a5: v372,
                        a6: 0);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: v380 | 0x20100000,
                          a4: v374,
                          a5: v372,
                          a6: (unsigned int)v373 | 0x400000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: v380 | 0x10400000,
                            a4: v375[0],
                            a5: v374,
                            a6: 0x1400000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: v380 | 0x20300000,
                              a4: v375[1],
                              a5: v372,
                              a6: (unsigned int)v373 | 0x1700000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: (unsigned int)v378,
                                a4: v376[0],
                                a5: v375[0],
                                a6: 0);
                        if ( v14 >= 0 )
                        {
                          v14 = D3DXShader::CCompiler::EmitLerp(
                                  this,
                                  a2,
                                  a3: v376[1],
                                  a4: v376[0],
                                  a5: v375[0],
                                  a6: v375[1],
                                  a7: (unsigned int)v381);
                          if ( v14 >= 0 )
                          {
                            v277 = (unsigned int)v367;
                            v269 = v376[1];
                            goto LABEL_924;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          goto LABEL_1100;
        }
      }
    case 0x19:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0;
      v270 = (unsigned int *)pMem;
      v45 = v76 & 0xFFFFF | 0x10400000;
      goto LABEL_884;
    case 0x1A:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      v77 = v381;
      i8 = (unsigned int *)(4 * (_DWORD)v381);
      v367 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * (_DWORD)v381);
      if ( v367 == nullptr )
        goto LABEL_901;
      v78 = D3DXShader::CCompiler::Scratch(this, a2: 10 * (_DWORD)v77);
      if ( v78 == nullptr )
        goto LABEL_901;
      for ( jj = 0; jj < 0xA; ++jj )
      {
        (&v343)[jj] = v78;
        v78 = (unsigned int *)((char *)v78 + (_DWORD)i8);
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v343, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v344, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v345, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v346, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v347, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v348, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v349, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v350, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v367, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v343,
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20100000,
              a4: v344,
              a5: v343,
              a6: (unsigned int)pMem | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v345,
              a5: v344,
              a6: 0x800000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20300000,
              a4: v346,
              a5: v345,
              a6: (unsigned int)v344 | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v359 = v380 | 0x20400000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v347,
              a5: v346,
              a6: (unsigned int)v344 | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v380 | 0x10600000, a4: v348, a5: v347, a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: (unsigned int)v378, a4: v349, a5: v348, a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10400000,
              a4: v350,
              a5: v349,
              a6: 0x1400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v359,
              a4: v367,
              a5: v348,
              a6: (unsigned int)v350 | 0x200000000LL);
      if ( v14 < 0 )
        break;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v351, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v352, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10500000,
              a4: v351,
              a5: v367,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&unk_10300000 | v380,
              a4: v352,
              a5: v351,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v352;
      goto LABEL_346;
    case 0x1B:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v80 = v381;
      v81 = D3DXShader::CCompiler::Scratch(this, a2: 6 * (_DWORD)v381);
      if ( v81 == nullptr )
        goto LABEL_901;
      for ( kk = 0; kk < 6; ++kk )
      {
        (&v373)[kk] = v81;
        v81 += (int)v80;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v373, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v374, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x10D00000,
              a4: v373,
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v374,
              a5: v373,
              a6: 0);
      if ( v14 < 0 )
        break;
      i17 = (unsigned int *)(v380 | 0x20100000);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20100000,
              a4: v375[0],
              a5: v374,
              a6: (unsigned int)v373 | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10E00000,
              a4: v375[1],
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: (unsigned int)v378, a4: v376[0], a5: v375[1], a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)i17,
              a4: v376[1],
              a5: v376[0],
              a6: (unsigned int)v375[1] | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v376[1] | 0x400000000LL;
      v268 = v375[0];
      goto LABEL_111;
    case 0x1C:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( (*(_BYTE *)(*((_DWORD *)this + 2) + 110) & 0x10) != 0 )
      {
        v87 = 0;
        if ( v381 != nullptr )
        {
          do
            a3[v87++] = *((_DWORD *)this + 8);
          while ( v87 < (unsigned int)v381 );
        }
        goto LABEL_28;
      }
      v83 = 4 * (_DWORD)v381;
      v84 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
      if ( v84 == nullptr )
        goto LABEL_901;
      for ( mm = 0; mm < 4; ++mm )
      {
        v375[mm] = v84;
        v84 = (unsigned int *)((char *)v84 + v83);
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: (unsigned int)v381);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
              if ( v14 >= 0 )
              {
                v380 = (unsigned int)v381 & 0xFFFFF;
                v378 = (unsigned int *)((unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF);
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: (unsigned int)v378,
                        a4: v375[0],
                        a5: (unsigned int *)pMem,
                        a6: 0x4000000000LL);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: v380 | 0x20400000,
                          a4: v375[1],
                          a5: (unsigned int *)pMem,
                          a6: (unsigned int)v375[0] | 0x4000000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: v380 | 0x20500000,
                            a4: v376[0],
                            a5: v375[1],
                            a6: (unsigned int)v375[1] | 0x4000000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: (unsigned int)v378,
                              a4: v376[1],
                              a5: v376[0],
                              a6: 0x4000000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: v380 | 0x20300000,
                                a4: a3,
                                a5: v376[1],
                                a6: (unsigned int)v376[0] | 0x5700000000LL);
                        if ( v14 >= 0 )
                        {
                          i8 = nullptr;
                          if ( v381 == nullptr )
                            goto LABEL_28;
                          v383 = (struct D3DXShader::CNode *)a3;
                          v387 = (unsigned int *)((_BYTE *)pMem - (_BYTE *)a3);
                          while ( 1 )
                          {
                            v14 = D3DXShader::CCompiler::EvalRange(
                                    this,
                                    a2: *(_DWORD *)((char *)v383 + (_DWORD)v387),
                                    a3: (struct D3DXShader::_D3DXRANGE *)v375);
                            if ( v14 < 0 )
                              goto LABEL_1100;
                            if ( *(double *)v375 <= *((double *)this + 21) || *(double *)v376 >= *((double *)this + 20) )
                            {
                              if ( *(double *)v375 != *((double *)this + 20)
                                && *(double *)v376 != *((double *)this + 21) )
                              {
                                goto LABEL_392;
                              }
                              v86 = *((_DWORD *)this + 9);
                            }
                            else
                            {
                              v86 = *((_DWORD *)this + 8);
                            }
                            *(_DWORD *)v383 = v86;
LABEL_392:
                            i8 = (unsigned int *)((char *)i8 + 1);
                            v383 = (struct D3DXShader::CNode *)((char *)v383 + 4);
                            if ( i8 >= v381 )
                              goto LABEL_28;
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
      break;
    case 0x1D:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( (*(_BYTE *)(*((_DWORD *)this + 2) + 110) & 0x10) != 0 )
      {
        v92 = 0;
        if ( v381 != nullptr )
        {
          do
            a3[v92++] = *((_DWORD *)this + 9);
          while ( v92 < (unsigned int)v381 );
        }
LABEL_28:
        v23 = *(unsigned int **)(v299 + 12);
        v386 = v23;
        if ( v23 != nullptr )
        {
          p_pMem = &pMem;
          do
          {
            if ( v23[2] != 0 )
            {
              *((_DWORD *)this + 7) = *p_pMem;
              v14 = D3DXShader::CCompiler::EmitExpression(
                      this,
                      a2: (struct D3DXShader::CNode *)v386[2],
                      a3: nullptr,
                      a4: nullptr);
              if ( v14 < 0 )
                goto LABEL_1100;
              v23 = v386;
            }
            v23 = (unsigned int *)v23[3];
            ++p_pMem;
            v386 = v23;
          }
          while ( v23 != nullptr );
        }
        v14 = 0;
      }
      else
      {
        v88 = 4 * (_DWORD)v381;
        v89 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
        if ( v89 == nullptr )
          goto LABEL_901;
        for ( nn = 0; nn < 4; ++nn )
        {
          v375[nn] = v89;
          v89 = (unsigned int *)((char *)v89 + v88);
        }
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: (unsigned int)v381);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
                if ( v14 >= 0 )
                {
                  v380 = (unsigned int)v381 & 0xFFFFF;
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: (unsigned int)&unk_10300000 | (unsigned int)v381 & 0xFFFFF,
                          a4: v375[0],
                          a5: (unsigned int *)pMem,
                          a6: 0x4000000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: v380 | 0x20500000,
                            a4: v375[1],
                            a5: v375[0],
                            a6: (unsigned int)v375[0] | 0x4000000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: (unsigned int)&loc_10100000 | v380,
                              a4: v376[0],
                              a5: v375[1],
                              a6: 0x4000000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: v380 | 0x20300000,
                                a4: a3,
                                a5: v376[0],
                                a6: (unsigned int)v375[1] | 0x5700000000LL);
                        if ( v14 >= 0 )
                        {
                          i8 = nullptr;
                          if ( v381 == nullptr )
                            goto LABEL_28;
                          v384 = (struct D3DXShader::CNode *)a3;
                          v388 = (unsigned int *)((_BYTE *)pMem - (_BYTE *)a3);
                          while ( 1 )
                          {
                            v14 = D3DXShader::CCompiler::EvalRange(
                                    this,
                                    a2: *(unsigned int *)((char *)v388 + (_DWORD)v384),
                                    a3: (struct D3DXShader::_D3DXRANGE *)v375);
                            if ( v14 < 0 )
                              goto LABEL_1100;
                            if ( *(double *)v375 <= *((double *)this + 21) || *(double *)v376 >= *((double *)this + 20) )
                            {
                              if ( *(double *)v375 != *((double *)this + 20)
                                && *(double *)v376 != *((double *)this + 21) )
                              {
                                goto LABEL_422;
                              }
                              v91 = *((_DWORD *)this + 8);
                            }
                            else
                            {
                              v91 = *((_DWORD *)this + 9);
                            }
                            *(_DWORD *)v384 = v91;
LABEL_422:
                            i8 = (unsigned int *)((char *)i8 + 1);
                            v384 = (struct D3DXShader::CNode *)((char *)v384 + 4);
                            if ( i8 >= v381 )
                              goto LABEL_28;
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
      break;
    case 0x1E:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( (*(_BYTE *)(*((_DWORD *)this + 2) + 110) & 0x10) != 0 )
      {
        v96 = 0;
        if ( v381 != nullptr )
        {
          do
            a3[v96++] = *((_DWORD *)this + 9);
          while ( v96 < (unsigned int)v381 );
        }
        goto LABEL_28;
      }
      v93 = 4 * (_DWORD)v381;
      v94 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
      if ( v94 == nullptr )
        goto LABEL_901;
      for ( i1 = 0; i1 < 4; ++i1 )
      {
        v375[i1] = v94;
        v94 = (unsigned int *)((char *)v94 + v93);
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x20500000,
              a4: v375[0],
              a5: (unsigned int *)pMem,
              a6: (unsigned int)pMem | 0x4000000000LL);
      if ( v14 < 0 )
        break;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v375[1],
              a5: v375[0],
              a6: 0x4000000000LL);
      if ( v14 < 0 )
        break;
      i17 = (unsigned int *)(v380 | 0x20300000);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20300000,
              a4: v376[0],
              a5: v375[0],
              a6: (unsigned int)v375[1] | 0x5700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v376[1],
              a5: v376[0],
              a6: 0x5A00000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)i17,
              a4: a3,
              a5: v376[1],
              a6: (unsigned int)v376[0] | 0x5700000000LL);
      if ( v14 < 0 )
        break;
      i8 = nullptr;
      if ( v381 == nullptr )
        goto LABEL_28;
      v385 = (struct D3DXShader::CNode *)a3;
      v389 = (unsigned int *)((_BYTE *)pMem - (_BYTE *)a3);
      do
      {
        v14 = D3DXShader::CCompiler::EvalRange(
                this,
                a2: *(unsigned int *)((char *)v389 + (_DWORD)v385),
                a3: (struct D3DXShader::_D3DXRANGE *)v375);
        if ( v14 < 0 )
          goto LABEL_1100;
        if ( *(double *)v375 > *((double *)this + 21)
          || *(double *)v376 < *((double *)this + 20)
          || *(double *)v375 == *((double *)this + 20)
          || *(double *)v376 == *((double *)this + 21) )
        {
          *(_DWORD *)v385 = *((_DWORD *)this + 9);
        }
        i8 = (unsigned int *)((char *)i8 + 1);
        v385 = (struct D3DXShader::CNode *)((char *)v385 + 4);
      }
      while ( i8 < v381 );
      goto LABEL_28;
    case 0x1F:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v97 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      v378 = v97;
      if ( v97 == nullptr )
        goto LABEL_901;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v97, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x10500000,
              a4: v378,
              a5: v367,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v378;
      goto LABEL_346;
    case 0x20:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v98 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
      v14 = v98;
      if ( v99 == 1 )
      {
        if ( v98 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: 0x10100001u,
                    a4: &i6,
                    a5: (unsigned int *)pMem,
                    a6: 0);
            if ( v14 >= 0 )
            {
              HIDWORD(v282) = 4;
              LODWORD(v282) = &i6;
              v22 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x20100001u,
                      a4: a3,
                      a5: (unsigned int *)pMem,
                      a6: v282);
              goto LABEL_27;
            }
          }
        }
      }
      else if ( v98 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
          if ( v14 >= 0 )
          {
            v58 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: v100 & 0xFFFFF | 0x50000000,
                    a4: &i6,
                    a5: (unsigned int *)pMem,
                    a6: (unsigned int)pMem | 0x400000000LL);
LABEL_234:
            v14 = v58;
            if ( v58 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x10700001u,
                      a4: &v365,
                      a5: &i6,
                      a6: 0x400000000LL);
              if ( v14 >= 0 )
              {
                v22 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: (unsigned int)&unk_10300001,
                        a4: a3,
                        a5: &v365,
                        a6: 0x400000000LL);
                goto LABEL_27;
              }
            }
          }
        }
      }
      break;
    case 0x21:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v22 = D3DXShader::CCompiler::EmitLerp(
              this,
              a2,
              a3,
              a4: (unsigned int *)pMem,
              a5: v367,
              a6: v368,
              a7: (unsigned int)v381);
      goto LABEL_27;
    case 0x22:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr || v381 != (unsigned int *)4 )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( (*(_BYTE *)(*((_DWORD *)this + 2) + 108) & 0x40) != 0 )
      {
        *(double *)v375 = *(double *)pMem;
        v376[0] = (unsigned int *)*v368;
        v376[1] = (unsigned int *)*v368;
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 4u);
        if ( v14 < 0 )
          break;
        v22 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                a2,
                a3: 0x50100004u,
                a4: a3,
                a5: (unsigned int *)v375,
                a6: 0);
        goto LABEL_27;
      }
      v101 = D3DXShader::CCompiler::Scratch(this, a2: 6u);
      if ( v101 == nullptr )
        goto LABEL_901;
      for ( i2 = 0; i2 < 6; ++i2 )
        (&v373)[i2] = (unsigned int *)((char *)&(&v373)[i2] + (char *)v101 - (char *)&v373);
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v101, a3: 6u);
      if ( v14 >= 0 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 4u);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: 0x10100001u,
                  a4: v373,
                  a5: (unsigned int *)pMem,
                  a6: 0);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: 0x20200001u,
                    a4: v374,
                    a5: v373,
                    a6: (unsigned int)pMem | 0x1700000000LL);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x20500001u,
                      a4: a3 + 1,
                      a5: v374,
                      a6: (unsigned int)pMem);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10100001u, a4: v375[0], a5: v367, a6: 0);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: 0x20200001u,
                          a4: v375[1],
                          a5: v375[0],
                          a6: (unsigned int)v367 | 0x1700000000LL);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: 0x20500001u,
                            a4: v376[0],
                            a5: v374,
                            a6: (unsigned int)v375[1] | 0x1700000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = D3DXShader::CCompiler::EmitPow(this, a2, a3: v376[1], a4: v367, a5: v368, a6: 1u);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: 0x20500001u,
                                a4: a3 + 2,
                                a5: v376[0],
                                a6: (unsigned int)v376[1] | 0x400000000LL);
                        if ( v14 >= 0 )
                        {
                          v14 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: 0x10000001u,
                                  a4: a3,
                                  a5: (unsigned int *)this + 8,
                                  a6: 0x1700000000LL);
                          if ( v14 >= 0 )
                          {
                            v22 = D3DXShader::CCompiler::EmitInst(
                                    (char **)this,
                                    a2,
                                    a3: 0x10000001u,
                                    a4: a3 + 3,
                                    a5: (unsigned int *)this + 8,
                                    a6: 0x1700000000LL);
                            goto LABEL_27;
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
      break;
    case 0x23:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v103 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: __FYL2X__(2.0, 0.6931471805599453094));
      v104 = v381;
      i17 = v103;
      v105 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (_DWORD)v381);
      if ( v105 == nullptr )
        goto LABEL_901;
      for ( i3 = 0; i3 < 2; ++i3 )
      {
        *(&v356 + i3) = (unsigned int)v105;
        v105 += (int)v104;
      }
      goto LABEL_507;
    case 0x24:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v107 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: __FYL2X__(2.0, 0.6931471805599453094) / __FYL2X__(10.0, 0.6931471805599453094));
      v104 = v381;
      i17 = v107;
      v108 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (_DWORD)v381);
      if ( v108 == nullptr )
        goto LABEL_901;
      for ( i4 = 0; i4 < 2; ++i4 )
      {
        *(&v356 + i4) = (unsigned int)v108;
        v108 += (int)v104;
      }
LABEL_507:
      if ( v104 != nullptr )
      {
        memset32((void *)v356, (int)i17, (unsigned int)v381);
        v13 = 0;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v357, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x10600000,
              a4: v357,
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v357;
      v268 = (unsigned int *)v356;
      goto LABEL_896;
    case 0x25:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0;
      v270 = (unsigned int *)pMem;
      v45 = v110 & 0xFFFFF | 0x10600000;
      goto LABEL_884;
    case 0x26:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = (unsigned int)v367;
      v270 = (unsigned int *)pMem;
      v45 = v111 & 0xFFFFF | 0x20100000;
      goto LABEL_884;
    case 0x27:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = (unsigned int)v367;
      v270 = (unsigned int *)pMem;
      v45 = v112 & 0xFFFFF | 0x20000000;
      goto LABEL_884;
    case 0x28:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      v113 = v381;
      i8 = (unsigned int *)(4 * (_DWORD)v381);
      v367 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * (_DWORD)v381);
      if ( v367 == nullptr )
        goto LABEL_901;
      v114 = D3DXShader::CCompiler::Scratch(this, a2: 10 * (_DWORD)v113);
      if ( v114 == nullptr )
        goto LABEL_901;
      for ( i5 = 0; i5 < 0xA; ++i5 )
      {
        (&v343)[i5] = v114;
        v114 = (unsigned int *)((char *)v114 + (_DWORD)i8);
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v343, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v344, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v345, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v346, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v347, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v348, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v349, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v350, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v351, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v367, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: ((unsigned int)&loc_101FFFFF + 1) | (unsigned int)v381 & 0xFFFFF,
              a4: v343,
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10400000,
              a4: v344,
              a5: v343,
              a6: 0x1400000000LL);
      if ( v14 < 0 )
        break;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v345,
              a5: v344,
              a6: 0x1800000000LL);
      if ( v14 < 0 )
        break;
      v359 = v380 | 0x20400000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v346,
              a5: v345,
              a6: (unsigned int)v343 | 0x200000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v347,
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      i6 = v380 | 0x20200000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20200000,
              a4: v348,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v347 | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: (unsigned int)v378, a4: v349, a5: v344, a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: i6,
              a4: v350,
              a5: v349,
              a6: (unsigned int)v344 | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20500000,
              a4: v351,
              a5: v348,
              a6: (unsigned int)v350 | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v359,
              a4: v367,
              a5: v346,
              a6: (unsigned int)v351 | 0x200000000LL);
      if ( v14 < 0 )
        break;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v352, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v352,
              a5: v367,
              a6: 0x200000000LL);
      if ( v14 < 0 )
        break;
      v281 = (unsigned int)v352 | 0x1000000000LL;
LABEL_283:
      v272 = (unsigned int *)pMem;
      goto LABEL_284;
    case 0x29:
    case 0x2A:
    case 0x2B:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v116 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      if ( v116 == nullptr )
        goto LABEL_901;
      v117 = 0;
      if ( v381 != nullptr )
      {
        do
          v116[v117++] = *(_DWORD *)pMem;
        while ( v117 < (unsigned int)v381 );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v367;
      v268 = v118;
      goto LABEL_701;
    case 0x2C:
    case 0x2F:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v119 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      if ( v119 == nullptr )
        goto LABEL_901;
      v120 = 0;
      if ( v381 != nullptr )
      {
        do
          v119[v120++] = *v367;
        while ( v120 < (unsigned int)v381 );
      }
      goto LABEL_699;
    case 0x2D:
    case 0x2E:
    case 0x30:
    case 0x31:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      i8 = (unsigned int *)v375[0][4];
      if ( i8 == nullptr || i8[1] != 9 )
        goto LABEL_1099;
      if ( i8[4] == 1 )
      {
        v121 = D3DXShader::CCompiler::Unalias(
                 this,
                 a2: (struct D3DXShader::CNode **)i8,
                 a3: (unsigned int *)pMem,
                 a4: v337);
      }
      else
      {
        D3DXShader::CNodeType::CNodeType(a1: &v307, a2: 2, a3: i8[5], a4: i8[6], a5: i8[7], a6: 1024);
        v121 = D3DXShader::CCompiler::Unalias(
                 this,
                 a2: (struct D3DXShader::CNode **)&v307,
                 a3: (unsigned int *)pMem,
                 a4: v337);
      }
      v14 = v121;
      if ( v121 < 0 )
        break;
      v122 = i8[6];
      v359 = i8[7];
      v123 = (unsigned int *)v375[1][4];
      v360 = v122;
      v378 = v123;
      if ( v123 == nullptr || v123[1] != 9 )
        goto LABEL_1099;
      if ( v123[4] == 1 )
      {
        v14 = D3DXShader::CCompiler::Unalias(this, a2: (struct D3DXShader::CNode **)v123, a3: v367, a4: v338);
        if ( v14 < 0 )
          break;
        v124 = v378[7];
        v125 = v378[6];
      }
      else
      {
        D3DXShader::CNodeType::CNodeType(a1: &v344, a2: 2, a3: v378[5], a4: v378[6], a5: v378[7], a6: 2048);
        v14 = D3DXShader::CCompiler::Unalias(this, a2: (struct D3DXShader::CNode **)&v344, a3: v367, a4: v338);
        if ( v14 < 0 )
          break;
        v124 = v378[6];
        v125 = v378[7];
      }
      v380 = v125;
      v361 = v124;
      if ( v359 != v124 || v381 != (unsigned int *)(v360 * v380) )
      {
LABEL_1099:
        v14 = -2147467259;
        break;
      }
      v126 = v360;
      if ( D3DXShader::CCompiler::IsRowMajor(this, a2: pMem, a3: i8[4], a4: v360, a5: v359) != 0 )
      {
        v137 = v380;
        if ( D3DXShader::CCompiler::IsColumnMajor(this, a2: v367, a3: v378[4], a4: v361, a5: v380) != 0 )
        {
          v378 = D3DXShader::CCompiler::Scratch(this, a2: v338);
          if ( v378 == nullptr )
            goto LABEL_901;
          v138 = v361;
          if ( v361 != 0 )
          {
            v358 = v378;
            v139 = v137;
            i8 = v367;
            v365 = v361;
            while ( 1 )
            {
              if ( v139 != 0 )
              {
                v140 = i8;
                v141 = v358;
                v142 = 4 * v138;
                for ( i6 = v139; i6 != 0; --i6 )
                {
                  *v141 = *v140++;
                  v141 = (unsigned int *)((char *)v141 + v142);
                }
                v139 = v380;
              }
              ++v358;
              i8 += v139;
              if ( --v365 == 0 )
                break;
              v138 = v361;
            }
          }
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
          if ( v14 < 0 )
            break;
          i6 = 0;
          if ( v360 == 0 )
            goto LABEL_28;
          v365 = (unsigned int)a3;
          v381 = (unsigned int *)pMem;
          do
          {
            i8 = nullptr;
            if ( v380 != 0 )
            {
              i17 = (unsigned int *)(v359 & 0xFFFFF | 0x50000000);
              v391 = (unsigned int *)v365;
              v358 = v378;
              do
              {
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: (unsigned int)i17,
                        a4: v391,
                        a5: v381,
                        a6: (unsigned int)v358);
                if ( v14 < 0 )
                  goto LABEL_1100;
                i8 = (unsigned int *)((char *)i8 + 1);
                ++v391;
                v358 += v361;
              }
              while ( (unsigned int)i8 < v380 );
            }
            ++i6;
            v381 += v359;
            v365 += 4 * v380;
          }
          while ( i6 < v360 );
        }
        else
        {
          v143 = D3DXShader::CCompiler::Scratch(this, a2: 5 * v137);
          if ( v143 == nullptr )
            goto LABEL_901;
          v144 = 0;
          v145 = 4 * v380;
          do
          {
            v375[v144++ - 1] = v143;
            v143 = (unsigned int *)((char *)v143 + v145);
          }
          while ( v144 < 5 );
          v358 = nullptr;
          if ( v360 != 0 )
          {
            i6 = 0;
            v365 = (unsigned int)a3;
            while ( 1 )
            {
              for ( i7 = 0; i7 < v359; v13 = 0 )
              {
                if ( v380 != 0 )
                {
                  v146 = &v367[i7 * v380];
                  i17 = (unsigned int *)((char *)pMem + 4 * i7 + 4 * i6);
                  v147 = v375[0];
                  v148 = (char *)v374 - (char *)v375[0];
                  for ( i8 = (unsigned int *)v380; i8 != nullptr; i8 = (unsigned int *)((char *)i8 - 1) )
                  {
                    *(unsigned int *)((char *)v147 + v148) = *i17;
                    *v147++ = *v146++;
                  }
                }
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: v380);
                if ( v14 < 0 )
                  goto LABEL_1100;
                i17 = (unsigned int *)(v380 & 0xFFFFF);
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: v380 & 0xFFFFF | 0x20500000,
                        a4: v376[0],
                        a5: v374,
                        a6: (unsigned int)v375[0]);
                if ( v14 < 0 )
                  goto LABEL_1100;
                if ( i7 != 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: v380);
                  if ( v14 < 0 )
                    goto LABEL_1100;
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: (unsigned int)i17 | 0x20400000,
                          a4: v376[1],
                          a5: v375[1],
                          a6: (unsigned int)v376[0]);
                  if ( v14 < 0 )
                    goto LABEL_1100;
                  v149 = v376[1];
                }
                else
                {
                  v149 = v376[0];
                }
                qmemcpy(v375[1], v149, 4 * v380);
                ++i7;
              }
              v150 = v380;
              v151 = 0;
              if ( v380 != 0 )
              {
                v152 = (_DWORD *)v365;
                do
                  *v152++ = v375[1][v151++];
                while ( v151 < v150 );
              }
              i6 += v359;
              v358 = (unsigned int *)((char *)v358 + 1);
              v365 += 4 * v150;
              if ( (unsigned int)v358 >= v360 )
                goto LABEL_28;
            }
          }
        }
      }
      else
      {
        v127 = D3DXShader::CCompiler::Scratch(this, a2: 5 * v126);
        if ( v127 == nullptr )
          goto LABEL_901;
        for ( i9 = 0; i9 < 5; ++i9 )
        {
          v375[i9 - 1] = v127;
          v127 += v126;
        }
        i8 = nullptr;
        if ( v380 != 0 )
        {
          v378 = a3;
          while ( 1 )
          {
            for ( i10 = 0; i10 < v361; v13 = 0 )
            {
              if ( v360 != 0 )
              {
                i6 = v360;
                v357 = (unsigned int *)(4 * v359);
                v129 = (unsigned int *)((char *)pMem + 4 * i10);
                i17 = &v367[(_DWORD)i8 + v380 * i10];
                v130 = v375[0];
                v131 = (char *)v374 - (char *)v375[0];
                do
                {
                  v132 = *v129;
                  v129 = (unsigned int *)((char *)v129 + (_DWORD)v357);
                  *(unsigned int *)((char *)v130 + v131) = v132;
                  *v130++ = *i17;
                  --i6;
                }
                while ( i6 != 0 );
              }
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: v360);
              if ( v14 < 0 )
                goto LABEL_1100;
              i17 = (unsigned int *)(v360 & 0xFFFFF);
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: v360 & 0xFFFFF | 0x20500000,
                      a4: v376[0],
                      a5: v374,
                      a6: (unsigned int)v375[0]);
              if ( v14 < 0 )
                goto LABEL_1100;
              if ( i10 != 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: v360);
                if ( v14 < 0 )
                  goto LABEL_1100;
                v14 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        a2,
                        a3: (unsigned int)i17 | 0x20400000,
                        a4: v376[1],
                        a5: v375[1],
                        a6: (unsigned int)v376[0]);
                if ( v14 < 0 )
                  goto LABEL_1100;
                v133 = v376[1];
              }
              else
              {
                v133 = v376[0];
              }
              qmemcpy(v375[1], v133, 4 * v360);
              ++i10;
            }
            v134 = 0;
            if ( v360 != 0 )
            {
              v135 = v378;
              v136 = 4 * v380;
              do
              {
                *v135 = v375[1][v134++];
                v135 = (unsigned int *)((char *)v135 + v136);
              }
              while ( v134 < v360 );
            }
            i8 = (unsigned int *)((char *)i8 + 1);
            ++v378;
            if ( (unsigned int)i8 >= v380 )
              goto LABEL_28;
          }
        }
      }
      goto LABEL_28;
    case 0x32:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
      if ( v14 < 0 )
        break;
      v273 = 0x1000000000LL;
      v21 = v337 & 0xFFFFF | 0x50200000;
LABEL_25:
      v268 = (unsigned int *)pMem;
      goto LABEL_26;
    case 0x33:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      if ( v381 == (unsigned int *)1 )
      {
        v153 = D3DXShader::CCompiler::Scratch(this, a2: 4u);
        if ( v153 == nullptr )
          goto LABEL_901;
        v154 = 0;
        v155 = (char *)v153 - (char *)v375;
        do
        {
          v375[v154] = (unsigned int *)((char *)&v375[v154] + v155);
          ++v154;
        }
        while ( v154 < 4 );
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: 1u);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: 1u);
          if ( v14 >= 0 )
          {
            v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: 1u);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: 1u);
              if ( v14 >= 0 )
              {
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 1u);
                if ( v14 >= 0 )
                {
                  v14 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          a2,
                          a3: 0x10100001u,
                          a4: v375[0],
                          a5: (unsigned int *)pMem,
                          a6: 0);
                  if ( v14 >= 0 )
                  {
                    v14 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            a2,
                            a3: 0x20200001u,
                            a4: v375[1],
                            a5: v375[0],
                            a6: (unsigned int)pMem | 0x1700000000LL);
                    if ( v14 >= 0 )
                    {
                      v14 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              a2,
                              a3: 0x20200001u,
                              a4: v376[0],
                              a5: (unsigned int *)pMem,
                              a6: (unsigned int)v375[0] | 0x1700000000LL);
                      if ( v14 >= 0 )
                      {
                        v14 = D3DXShader::CCompiler::EmitInst(
                                (char **)this,
                                a2,
                                a3: 0x10100001u,
                                a4: v376[1],
                                a5: v376[0],
                                a6: 0x1A00000000LL);
                        if ( v14 >= 0 )
                        {
                          v279 = (unsigned int)v376[1] | 0x1200000000LL;
                          v271 = v375[1];
LABEL_180:
                          v22 = D3DXShader::CCompiler::EmitInst(
                                  (char **)this,
                                  a2,
                                  a3: 0x20400001u,
                                  a4: a3,
                                  a5: v271,
                                  a6: v279);
                          goto LABEL_27;
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
      else
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
        if ( v14 >= 0 )
        {
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
          if ( v14 >= 0 )
          {
            v380 = (unsigned int)v381 & 0xFFFFF;
            v14 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    a2,
                    a3: (unsigned int)v381 & 0xFFFFF | 0x50000000,
                    a4: &i6,
                    a5: (unsigned int *)pMem,
                    a6: (unsigned int)pMem | 0x400000000LL);
            if ( v14 >= 0 )
            {
              v14 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      a2,
                      a3: 0x10700001u,
                      a4: &v365,
                      a5: &i6,
                      a6: 0x400000000LL);
              if ( v14 >= 0 )
              {
                v156 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
                if ( v156 == nullptr )
                  goto LABEL_901;
                v157 = 0;
                if ( v381 != nullptr )
                {
                  do
                    v156[v157++] = v365;
                  while ( v157 < (unsigned int)v381 );
                }
                v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
                if ( v14 >= 0 )
                {
                  v273 = v158;
LABEL_346:
                  v268 = (unsigned int *)pMem;
LABEL_896:
                  v162 = v380;
LABEL_897:
                  v21 = v162 | 0x20500000;
LABEL_26:
                  v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v21, a4: a3, a5: v268, a6: v273);
                  goto LABEL_27;
                }
              }
            }
          }
        }
      }
      break;
    case 0x34:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v22 = D3DXShader::CCompiler::EmitPow(this, a2, a3, a4: (unsigned int *)pMem, a5: v367, a6: (unsigned int)v381);
      goto LABEL_27;
    case 0x35:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v47 = 0.01745329300562541;
LABEL_696:
      v159 = D3DXShader::CBaseProgram::AddArgument(
               this: *((D3DXShader::CBaseProgram **)this + 2),
               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
               a3: 0,
               a4: 0,
               a5: v47);
      v160 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      if ( v160 == nullptr )
        goto LABEL_901;
      if ( v381 != nullptr )
      {
        memset32(v160, v159, (unsigned int)v381);
        v13 = 0;
      }
LABEL_699:
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v273 = v161;
      v268 = (unsigned int *)pMem;
LABEL_701:
      v162 = (unsigned int)v381 & 0xFFFFF;
      goto LABEL_897;
    case 0x36:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v358, a3: 1u);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x50000000,
              a4: &i6,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v367);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20400001u,
              a4: &v365,
              a5: &i6,
              a6: (unsigned int)&i6);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x10100001u,
              a4: (unsigned int *)&v358,
              a5: &v365,
              a6: 0);
      if ( v14 < 0 )
        break;
      v163 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (_DWORD)v381);
      if ( v163 == nullptr )
        goto LABEL_901;
      v164 = v381;
      v165 = 0;
      v166 = 4 * (_DWORD)v381;
      do
      {
        (&v363)[v165++] = v163;
        v163 = (unsigned int *)((char *)v163 + v166);
      }
      while ( v165 < 2 );
      v167 = v363;
      v168 = 0;
      if ( v164 != nullptr )
      {
        do
          v167[v168++] = (unsigned int)v358;
        while ( v168 < (unsigned int)v164 );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: i17, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v380 | 0x20500000, a4: i17, a5: v367, a6: v169);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)pMem;
      v268 = i17;
      goto LABEL_111;
    case 0x37:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&i8, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v361, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v317, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v359, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v378, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v316, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v318, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &i6, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v365, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v333, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v358, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&v357, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v353, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: &v354, a3: 1u);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)&i17, a3: 1u);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x50000000,
              a4: (unsigned int *)&i8,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v367);
      if ( v14 < 0 )
        break;
      HIDWORD(v283) = 4;
      LODWORD(v283) = &i8;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20500001u,
              a4: &v361,
              a5: (unsigned int *)&i8,
              a6: v283);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20500001u,
              a4: &v317,
              a5: v368,
              a6: (unsigned int)v368 | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10100001u, a4: &v359, a5: &v361, a6: 0x800000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20400001u,
              a4: (unsigned int *)&v378,
              a5: (unsigned int *)this + 8,
              a6: (unsigned int)&v359);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20500001u,
              a4: &v316,
              a5: &v317,
              a6: (unsigned int)&v378);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10100001u, a4: &v318, a5: &v316, a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20400001u,
              a4: &i6,
              a5: (unsigned int *)this + 8,
              a6: (unsigned int)&v318);
      if ( v14 < 0 )
        break;
      HIDWORD(v284) = 23;
      LODWORD(v284) = (char *)this + 36;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20300001u, a4: &v365, a5: &i6, a6: v284);
      if ( v14 < 0 )
        break;
      HIDWORD(v285) = 4;
      LODWORD(v285) = &v365;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20500001u, a4: &v333, a5: &i6, a6: v285);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20500001u,
              a4: (unsigned int *)&v358,
              a5: v368,
              a6: (unsigned int)&v365);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20500001u,
              a4: (unsigned int *)&v357,
              a5: (unsigned int *)&v358,
              a6: (unsigned int)&i8);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10700001u, a4: &v353, a5: &v333, a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&unk_10300001,
              a4: &v354,
              a5: &v353,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x20400001u,
              a4: (unsigned int *)&i17,
              a5: (unsigned int *)&v357,
              a6: (unsigned int)&v354);
      if ( v14 < 0 )
        break;
      v170 = v381;
      v171 = D3DXShader::CCompiler::Scratch(this, a2: 5 * (_DWORD)v381);
      if ( v171 == nullptr )
        goto LABEL_901;
      for ( i11 = 0; i11 < 5; ++i11 )
      {
        v375[i11 - 1] = v171;
        v171 += (int)v170;
      }
      v173 = v376[1];
      if ( v170 != nullptr )
      {
        v174 = (char *)v376[0] - (char *)v376[1];
        do
        {
          *(unsigned int *)((char *)v173 + v174) = (unsigned int)v358;
          *v173++ = (unsigned int)i17;
          v170 = (unsigned int *)((char *)v170 - 1);
        }
        while ( v170 != nullptr );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v374, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v360 = v380 | 0x20500000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20500000,
              a4: v374,
              a5: v376[0],
              a6: (unsigned int)pMem);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v360,
              a4: v375[0],
              a5: v376[1],
              a6: (unsigned int)v367);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v375[1],
              a5: v375[0],
              a6: 0);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v375[1];
      v268 = v374;
      goto LABEL_111;
    case 0x38:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v175 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: 0.5);
      v176 = 4 * (_DWORD)v381;
      i17 = v175;
      v177 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
      if ( v177 == nullptr )
        goto LABEL_901;
      for ( i12 = 0; i12 < 4; ++i12 )
      {
        v375[i12] = v177;
        v177 = (unsigned int *)((char *)v177 + v176);
      }
      if ( v381 != nullptr )
      {
        memset32(v376[1], (int)i17, (unsigned int)v381);
        v13 = 0;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v359 = (unsigned int)v381 & 0xFFFFF | 0x20400000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v359,
              a4: v375[0],
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v376[1]);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10400000,
              a4: v375[1],
              a5: v375[0],
              a6: 0x1400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v376[0],
              a5: v375[1],
              a6: 0x1800000000LL);
      if ( v14 < 0 )
        break;
      v281 = (unsigned int)v376[0] | 0x200000000LL;
      v272 = v375[0];
LABEL_284:
      v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v359, a4: a3, a5: v272, a6: v281);
      goto LABEL_27;
    case 0x39:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = 0x400000000LL;
      v270 = (unsigned int *)pMem;
      v45 = v179 & 0xFFFFF | 0x10700000;
      goto LABEL_884;
    case 0x3A:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v180 = v381;
      v181 = D3DXShader::CCompiler::Scratch(this, a2: 3 * (_DWORD)v381);
      if ( v181 == nullptr )
        goto LABEL_901;
      for ( i13 = 0; i13 < 3; ++i13 )
      {
        (&v362)[i13] = v181;
        v181 += (int)v180;
      }
      v183 = v363;
      if ( v180 != nullptr )
      {
        v184 = (char *)v362 - (char *)v363;
        do
        {
          *(unsigned int *)((char *)v183 + v184) = *((_DWORD *)this + 9);
          *v183++ = *((_DWORD *)this + 8);
          v180 = (unsigned int *)((char *)v180 - 1);
        }
        while ( v180 != nullptr );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: i17, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x20100000,
              a4: i17,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v362 | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v363 | 0x1400000000LL;
      v268 = i17;
LABEL_799:
      v21 = v380 | 0x20000000;
      goto LABEL_26;
    case 0x3B:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v185 = 4 * (_DWORD)v381;
      v186 = D3DXShader::CCompiler::Scratch(this, a2: 4 * (_DWORD)v381);
      if ( v186 == nullptr )
        goto LABEL_901;
      for ( i14 = 0; i14 < 4; ++i14 )
      {
        v375[i14] = v186;
        v186 = (unsigned int *)((char *)v186 + v185);
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v375[0],
              a5: (unsigned int *)pMem,
              a6: 0);
      if ( v14 < 0 )
        break;
      i6 = v380 | 0x20200000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20200000,
              a4: v375[1],
              a5: v375[0],
              a6: (unsigned int)pMem | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: i6,
              a4: v376[0],
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v375[0] | 0x1700000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v376[1],
              a5: v376[0],
              a6: 0x1A00000000LL);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)v376[1] | 0x1200000000LL;
      v268 = v375[1];
LABEL_111:
      v21 = v380 | 0x20400000;
      goto LABEL_26;
    case 0x3C:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitSinCos(
              this,
              a2,
              a3: (unsigned int *)pMem,
              a4: a3,
              a5: nullptr,
              a6: (unsigned int)v381);
      goto LABEL_27;
    case 0x3D:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      v188 = 4 * v337;
      v367 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v337);
      if ( v367 == nullptr )
        goto LABEL_901;
      v368 = (unsigned int *)MemAlloc_Alloc(nSize: v188);
      if ( v368 == nullptr )
        goto LABEL_901;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v367, a3: v337);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v189, a3: v337);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitSinCos(this, a2, a3: (unsigned int *)pMem, a4: v367, a5: v190, a6: v337);
      goto LABEL_27;
    case 0x3E:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v191 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v192 = *((D3DXShader::CBaseProgram **)this + 2);
      v266 = *((_DWORD *)v192 + 30);
      i17 = v191;
      v193 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(this: v192, a2: v266, a3: 0, a4: 0, a5: 0.5);
      v194 = v381;
      v357 = v193;
      v195 = D3DXShader::CCompiler::Scratch(this, a2: 8 * (_DWORD)v381);
      if ( v195 == nullptr )
        goto LABEL_901;
      for ( i15 = 0; i15 < 8; ++i15 )
      {
        (&v371)[i15] = v195;
        v195 += (int)v194;
      }
      if ( v194 != nullptr )
      {
        v197 = v376[1];
        v198 = (char *)v376[0] - (char *)v376[1];
        do
        {
          *(unsigned int *)((char *)v197 + v198) = (unsigned int)i17;
          *v197++ = (unsigned int)v357;
          v194 = (unsigned int *)((char *)v194 - 1);
        }
        while ( v194 != nullptr );
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v371, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v372, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v373, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v374, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v360 = (unsigned int)v381 & 0xFFFFF | 0x20500000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v360,
              a4: v371,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v376[0]);
      if ( v14 < 0 )
        break;
      i8 = (unsigned int *)(v380 | 0x10500000);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10500000,
              a4: v372,
              a5: v371,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v373,
              a5: v371,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)i8,
              a4: v374,
              a5: v373,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v375[0],
              a5: v374,
              a6: 0x800000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v375[1],
              a5: v372,
              a6: (unsigned int)v375[0]);
      if ( v14 < 0 )
        break;
      HIDWORD(v277) = 0;
LABEL_147:
      *(unsigned int **)&v277 = v376[1];
      v269 = v375[1];
      goto LABEL_924;
    case 0x3F:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v199 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: -2.0);
      v200 = *((D3DXShader::CBaseProgram **)this + 2);
      v267 = *((_DWORD *)v200 + 30);
      v357 = v199;
      v201 = D3DXShader::CBaseProgram::AddArgument(this: v200, a2: v267, a3: 0, a4: 0, a5: 3.0);
      v202 = v381;
      v353 = v201;
      v203 = D3DXShader::CCompiler::Scratch(this, a2: 14 * (_DWORD)v381);
      if ( v203 == nullptr )
        goto LABEL_901;
      for ( i16 = 0; i16 < 0xE; ++i16 )
      {
        (&v319)[i16] = v203;
        v203 += (int)v202;
      }
      v205 = 0;
      while ( 1 )
      {
        v14 = D3DXShader::CCompiler::EmitTemp(this, a2: (&v319)[v205], a3: (unsigned int)v381);
        if ( v14 < 0 )
          goto LABEL_1100;
        v205 = v206 + 1;
        if ( v205 >= 0xA )
        {
          v207 = v330;
          if ( v381 != nullptr )
          {
            v354 = (char *)v331 - (char *)v330;
            v208 = (char *)v329 - (char *)v330;
            v333 = (char *)v332 - (char *)v330;
            for ( i17 = v381; i17 != nullptr; i17 = (unsigned int *)((char *)i17 - 1) )
            {
              v209 = v354;
              *(unsigned int *)((char *)v207 + v208) = *((_DWORD *)this + 9);
              *v207 = *((_DWORD *)this + 8);
              *(unsigned int *)((char *)v207 + v209) = (unsigned int)v357;
              *(unsigned int *)((char *)v207++ + v333) = v353;
            }
          }
          v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
          if ( v14 < 0 )
            goto LABEL_1100;
          v380 = (unsigned int)v381 & 0xFFFFF;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: (unsigned int)&loc_10100000 | (unsigned int)v381 & 0xFFFFF,
                  a4: v319,
                  a5: (unsigned int *)pMem,
                  a6: 0);
          if ( v14 < 0 )
            goto LABEL_1100;
          v359 = v380 | 0x20400000;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v380 | 0x20400000,
                  a4: v320,
                  a5: v367,
                  a6: (unsigned int)v319);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v359, a4: v321, a5: v368, a6: (unsigned int)v319);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: (unsigned int)&unk_10300000 | v380,
                  a4: v322,
                  a5: v320,
                  a6: 0);
          if ( v14 < 0 )
            goto LABEL_1100;
          v360 = v380 | 0x20500000;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v380 | 0x20500000,
                  a4: v323,
                  a5: v321,
                  a6: (unsigned int)v322);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v380 | 0x20100000,
                  a4: v324,
                  a5: v323,
                  a6: (unsigned int)v329 | 0x400000000LL);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v380 | 0x20000000,
                  a4: v325,
                  a5: v324,
                  a6: (unsigned int)v330 | 0x1400000000LL);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v360,
                  a4: v326,
                  a5: v325,
                  a6: (unsigned int)v331 | 0x800000000LL);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v359, a4: v327, a5: v326, a6: (unsigned int)v332);
          if ( v14 < 0 )
            goto LABEL_1100;
          v14 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2,
                  a3: v360,
                  a4: v328,
                  a5: v325,
                  a6: (unsigned int)v325 | 0x1400000000LL);
          if ( v14 < 0 )
            goto LABEL_1100;
          v277 = (unsigned int)v328;
          v269 = v327;
LABEL_924:
          v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v360, a4: a3, a5: v269, a6: v277);
          goto LABEL_27;
        }
      }
    case 0x40:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v210 = D3DXShader::CCompiler::Scratch(this, a2: (unsigned int)v381);
      v378 = v210;
      if ( v210 == nullptr )
        goto LABEL_901;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v210, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v381 & 0xFFFFF | 0x10700000,
              a4: v378,
              a5: (unsigned int *)pMem,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&unk_10300000 | v380,
              a4: a3,
              a5: v378,
              a6: 0x400000000LL);
      goto LABEL_27;
    case 0x41:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v278 = (unsigned int)pMem | 0x1700000000LL;
      v270 = v367;
      v45 = v211 & 0xFFFFF | 0x20300000;
LABEL_884:
      v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v45, a4: a3, a5: v270, a6: v278);
      goto LABEL_27;
    case 0x42:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      v212 = v381;
      v213 = D3DXShader::CCompiler::Scratch(this, a2: 3 * (_DWORD)v381);
      if ( v213 == nullptr )
        goto LABEL_901;
      for ( i18 = 0; i18 < 3; ++i18 )
      {
        (&v362)[i18] = v213;
        v213 += (int)v212;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v362, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v363, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: i17, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitSinCos(
              this,
              a2,
              a3: (unsigned int *)pMem,
              a4: v362,
              a5: v363,
              a6: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v380 = (unsigned int)v381 & 0xFFFFF;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&unk_10300000 | (unsigned int)v381 & 0xFFFFF,
              a4: i17,
              a5: v363,
              a6: 0);
      if ( v14 < 0 )
        break;
      v273 = (unsigned int)i17;
      v268 = v362;
      goto LABEL_896;
    case 0x43:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v215 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: 1.0 / __FYL2X__(2.0, 0.6931471805599453094));
      v216 = v381;
      i17 = v215;
      v217 = D3DXShader::CCompiler::Scratch(this, a2: 9 * (_DWORD)v381);
      if ( v217 == nullptr )
        goto LABEL_901;
      for ( i19 = 0; i19 < 9; ++i19 )
      {
        (&v370)[i19] = v217;
        v217 += (int)v216;
      }
      if ( v216 != nullptr )
      {
        memset32(v376[1], (int)i17, (unsigned int)v381);
        v13 = 0;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v370, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v371, a3: v219);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v372, a3: v220);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v373, a3: v221);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v374, a3: v222);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[0], a3: v223);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v375[1], a3: v224);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: v376[0], a3: v225);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: v226);
      if ( v14 < 0 )
        break;
      v380 = v227 & 0xFFFFF;
      v360 = v227 & 0xFFFFF | 0x20500000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v360,
              a4: v370,
              a5: (unsigned int *)pMem,
              a6: (unsigned int)v376[1]);
      if ( v14 < 0 )
        break;
      i8 = (unsigned int *)(v380 | 0x10500000);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x10500000,
              a4: v371,
              a5: v370,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v378 = (unsigned int *)((unsigned int)&loc_10100000 | v380);
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&loc_10100000 | v380,
              a4: v372,
              a5: v370,
              a6: 0);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)i8,
              a4: v373,
              a5: v372,
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)v378,
              a4: v374,
              a5: v373,
              a6: 0x800000000LL);
      if ( v14 < 0 )
        break;
      v359 = v380 | 0x20400000;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v380 | 0x20400000,
              a4: v375[0],
              a5: v371,
              a6: (unsigned int)v374);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: v359,
              a4: v375[1],
              a5: v371,
              a6: (unsigned int)v373 | 0x400000000LL);
      if ( v14 < 0 )
        break;
      v14 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: (unsigned int)&unk_10300000 | v380,
              a4: v376[0],
              a5: v375[1],
              a6: 0x400000000LL);
      if ( v14 < 0 )
        break;
      v277 = (unsigned int)v376[0];
      v269 = v375[0];
      goto LABEL_924;
    case 0x44:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v228 = (unsigned int **)v367;
      for ( i20 = 0; i20 < 2; ++i20 )
      {
        v375[i20] = *(unsigned int **)pMem;
        v376[i20] = *v228;
      }
      i17 = *v228;
      D3DXShader::CCompiler::Unalias(this, a2: nullptr, a3: (unsigned int *)&i17, a4: 1u);
      v230 = *((_DWORD **)this + 2);
      v231 = *(_DWORD **)(v230[5] + 4 * (int)v376[0]);
      if ( (*(_BYTE *)(*(_DWORD *)(v230[4] + 4 * v231[1]) + 4) & 0x10) == 0 || v231[4] != 0 )
        goto LABEL_943;
      v5 = v230[2] == 0;
      i8 = nullptr;
      if ( !v5 )
      {
        i6 = v230[5];
        while ( 1 )
        {
          v232 = *(_DWORD **)i6;
          if ( v231[1] == *(_DWORD *)(*(_DWORD *)i6 + 4) && v231[2] == v232[2] && v231[3] == v232[3] && v232[4] == 1 )
            break;
          i8 = (unsigned int *)((char *)i8 + 1);
          v233 = *((_DWORD *)this + 2);
          i6 += 4;
          if ( (unsigned int)i8 >= *(_DWORD *)(v233 + 8) )
            goto LABEL_941;
        }
        v376[1] = i8;
      }
LABEL_941:
      if ( i8 == (unsigned int *)v230[2] )
        D3DXShader::CCompiler::Warning(
          this,
          a2,
          a3: 0xDB5u,
          format: "tex1D will considered dependent since texcoord was not declared as at least float2");
LABEL_943:
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 >= 0 )
      {
        v22 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                a2,
                a3: 0x60000002u,
                a4: a3,
                a5: (unsigned int *)v375,
                a6: (unsigned int)v376);
LABEL_27:
        v14 = v22;
        if ( v22 >= 0 )
          goto LABEL_28;
      }
      break;
    case 0x45:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr || v376[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i21 = 0; i21 < 2; ++i21 )
      {
        v235 = i21;
        (&v371)[v235] = *(unsigned int **)pMem;
        (&v373)[v235] = (unsigned int *)*v367;
        v375[v235] = (unsigned int *)*v368;
        v376[v235] = *v369;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60100002u,
              a4: a3,
              a5: (unsigned int *)&v371,
              a6: (unsigned int)&v373);
      goto LABEL_27;
    case 0x46:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i22 = 0; i22 < 4; ++i22 )
        v375[i22] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60200004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x47:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i23 = 0; i23 < 4; ++i23 )
        v375[i23] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60300004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x48:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i24 = 0; i24 < 4; ++i24 )
        v375[i24] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60400004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x49:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i25 = 0; i25 < 2; ++i25 )
        (&v363)[i25] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60500002u,
              a4: a3,
              a5: (unsigned int *)&v363,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x4A:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr || v376[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v240 = v367;
      v357 = (unsigned int *)((char *)&v373 - (char *)v367);
      i8 = (unsigned int *)((char *)v368 - (char *)v367);
      v354 = (char *)v375 - (char *)v367;
      v361 = (char *)v369 - (char *)v367;
      v241 = (char *)&v371 - (char *)v367;
      v353 = (char *)v376 - (char *)v367;
      for ( i17 = (unsigned int *)2; i17 != nullptr; i17 = (unsigned int *)((char *)i17 - 1) )
      {
        v242 = v357;
        *(unsigned int *)((char *)v240 + v241) = *(_DWORD *)pMem;
        *(unsigned int *)((char *)v240 + (_DWORD)v242) = *v240;
        *(unsigned int *)((char *)v240 + v354) = *(unsigned int *)((char *)v240 + (_DWORD)i8);
        *(unsigned int *)((char *)v240 + v353) = *(unsigned int *)((char *)v240 + v361);
        ++v240;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60600002u,
              a4: a3,
              a5: (unsigned int *)&v371,
              a6: (unsigned int)&v373);
      goto LABEL_27;
    case 0x4B:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i26 = 0; i26 < 4; ++i26 )
        v375[i26] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60700004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x4C:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i27 = 0; i27 < 4; ++i27 )
        v375[i27] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60800004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x4D:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i28 = 0; i28 < 4; ++i28 )
        v375[i28] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60900004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x4E:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i29 = 0; i29 < 3; ++i29 )
        v375[i29 + 1] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60A00003u,
              a4: a3,
              a5: (unsigned int *)&v375[1],
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x4F:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr || v376[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v247 = v367;
      v357 = (unsigned int *)((char *)&v324 - (char *)v367);
      i8 = (unsigned int *)((char *)v368 - (char *)v367);
      v354 = (char *)&v327 - (char *)v367;
      v361 = (char *)v369 - (char *)v367;
      v248 = (char *)&v321 - (char *)v367;
      v353 = (char *)&v330 - (char *)v367;
      for ( i17 = (unsigned int *)3; i17 != nullptr; i17 = (unsigned int *)((char *)i17 - 1) )
      {
        v249 = v357;
        *(unsigned int *)((char *)v247 + v248) = *(_DWORD *)pMem;
        *(unsigned int *)((char *)v247 + (_DWORD)v249) = *v247;
        *(unsigned int *)((char *)v247 + v354) = *(unsigned int *)((char *)i8 + (_DWORD)v247);
        *(unsigned int *)((char *)v247 + v353) = *(unsigned int *)((char *)v247 + v361);
        ++v247;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60B00003u,
              a4: a3,
              a5: (unsigned int *)&v321,
              a6: (unsigned int)&v324);
      goto LABEL_27;
    case 0x50:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i30 = 0; i30 < 4; ++i30 )
        v375[i30] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60C00004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x51:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i31 = 0; i31 < 4; ++i31 )
        v375[i31] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60D00004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x52:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i32 = 0; i32 < 4; ++i32 )
        v375[i32] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60E00004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x53:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i33 = 0; i33 < 3; ++i33 )
        v375[i33 + 1] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x60F00003u,
              a4: a3,
              a5: (unsigned int *)&v375[1],
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x54:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr || v376[0] == nullptr || v376[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v254 = v367;
      v357 = (unsigned int *)((char *)&v324 - (char *)v367);
      i8 = (unsigned int *)((char *)v368 - (char *)v367);
      v354 = (char *)&v327 - (char *)v367;
      v361 = (char *)v369 - (char *)v367;
      v255 = (char *)&v321 - (char *)v367;
      v353 = (char *)&v330 - (char *)v367;
      for ( i17 = (unsigned int *)3; i17 != nullptr; i17 = (unsigned int *)((char *)i17 - 1) )
      {
        v256 = v357;
        *(unsigned int *)((char *)v254 + v255) = *(_DWORD *)pMem;
        *(unsigned int *)((char *)v254 + (_DWORD)v256) = *v254;
        *(unsigned int *)((char *)v254 + v354) = *(unsigned int *)((char *)i8 + (_DWORD)v254);
        *(unsigned int *)((char *)v254 + v353) = *(unsigned int *)((char *)v254 + v361);
        ++v254;
      }
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x61000003u,
              a4: a3,
              a5: (unsigned int *)&v321,
              a6: (unsigned int)&v324);
      goto LABEL_27;
    case 0x55:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i34 = 0; i34 < 4; ++i34 )
        v375[i34] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x61100004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x56:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i35 = 0; i35 < 4; ++i35 )
        v375[i35] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x61200004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x57:
      v13 = 0;
      if ( v375[0] == nullptr || v375[1] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      for ( i36 = 0; i36 < 4; ++i36 )
        v375[i36] = *(unsigned int **)pMem;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: (unsigned int)v381);
      if ( v14 < 0 )
        break;
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2,
              a3: 0x61300004u,
              a4: a3,
              a5: (unsigned int *)v375,
              a6: (unsigned int)v367);
      goto LABEL_27;
    case 0x58:
      v260 = v375[0];
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 != nullptr )
      {
        v5 = v375[0][6] == 0;
        v361 = 0;
        if ( !v5 )
        {
          v261 = v375[0][5];
          do
          {
            for ( i8 = nullptr; (unsigned int)i8 < v261; v19 = a2 )
            {
              v262 = (char *)i8 + v361 * *((_DWORD *)v19 + 6);
              v263 = *((_DWORD *)pMem + v361 + (_DWORD)i8 * v260[6]);
              i8 = (unsigned int *)((char *)i8 + 1);
              a3[(_DWORD)v262] = v263;
              v261 = v260[5];
            }
            ++v361;
          }
          while ( v361 < v260[6] );
        }
      }
      goto LABEL_28;
    case 0x59:
      v13 = 0;
      if ( v375[0] == nullptr )
        goto LABEL_1099;
      if ( a3 == nullptr )
        goto LABEL_28;
      v264 = (unsigned int *)D3DXShader::CBaseProgram::AddArgument(
                               this: *((D3DXShader::CBaseProgram **)this + 2),
                               a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
                               a3: 0,
                               a4: 0,
                               a5: 255.001953125);
      v337 = *((_DWORD *)pMem + 2);
      v338 = *((_DWORD *)pMem + 1);
      v339 = *(unsigned int **)pMem;
      v340 = *((_DWORD *)pMem + 3);
      v375[0] = v264;
      v375[1] = v264;
      v376[0] = v264;
      v376[1] = v264;
      v14 = D3DXShader::CCompiler::EmitTemp(this, a2: a3, a3: 4u);
      if ( v14 < 0 )
        break;
      HIDWORD(v286) = 6;
      LODWORD(v286) = v375;
      v22 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20500004u, a4: a3, a5: &v337, a6: v286);
      goto LABEL_27;
    default:
      D3DXShader::CCompiler::Error(
        this,
        a2,
        a3: 0xDACu,
        format: "intrinsic function '%s' is not yet implemented",
        *((const char **)a2 + 14));
      v13 = 0;
      goto LABEL_1099;
  }
LABEL_1100:
  *((_DWORD *)this + 7) = v301;
  *((_DWORD *)this + 25) = v300;
  do
    free(pMem: *(&pMem + v13++));
  while ( v13 < 4 );
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101D6120
// Name: protected: long D3DXShader::CCompiler::EmitArray(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int,unsigned int __near *,unsigned int,class D3DXShader::CNode __near *,unsigned int __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitArray(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CNode *a2,
        __int64 a3,
        unsigned int *a4,
        unsigned int a5,
        struct D3DXShader::CNode *a6,
        unsigned int a7,
        unsigned int a8)
{
  unsigned int v9; // ebx
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  double v13; // st6
  double v14; // st7
  __int64 v15; // rax
  unsigned int v16; // eax
  int result; // eax
  __int16 v18; // ax
  unsigned int v19; // edx
  int v20; // ecx
  struct D3DXShader::CNode *v21; // ebx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  unsigned int *v25; // edi
  unsigned int *v26; // esi
  unsigned int v27; // eax
  int v28; // ecx
  _DWORD *v29; // edx
  _DWORD *v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  unsigned int *v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // ebx
  unsigned int v39; // eax
  int v40; // ecx
  int v41; // edi
  unsigned int v42; // edx
  bool v43; // cf
  unsigned int v44; // edx
  unsigned int *v45; // ebx
  int v46; // ecx
  int v47; // eax
  unsigned int *v48; // edx
  unsigned int n; // eax
  unsigned int *v50; // edx
  unsigned int v51; // ebx
  unsigned int *v52; // eax
  unsigned int *v53; // edx
  unsigned int *v54; // eax
  unsigned int m; // ecx
  unsigned int v56; // ecx
  int v57; // ebx
  unsigned int v58; // eax
  int v59; // ecx
  int v60; // ecx
  int v61; // eax
  unsigned int v62; // eax
  unsigned int v63; // ebx
  unsigned int v64; // edi
  double v65; // st7
  unsigned int v66; // ebx
  unsigned int v67; // eax
  int v68; // eax
  unsigned int v69; // ecx
  unsigned int *v70; // edi
  unsigned int v71; // ebx
  unsigned int *v72; // ecx
  unsigned int v73; // eax
  unsigned int v74; // edi
  unsigned int *v75; // ebx
  unsigned int v76; // edi
  unsigned int v77; // edx
  unsigned int *v78; // eax
  unsigned int *v79; // eax
  unsigned int *v80; // edx
  unsigned int *v81; // eax
  unsigned int i; // ecx
  unsigned int v83; // ecx
  int v84; // ebx
  unsigned int j; // ecx
  unsigned int v86; // eax
  int v87; // ecx
  int v88; // ecx
  int v89; // eax
  unsigned int v90; // eax
  unsigned int v91; // ebx
  unsigned int v92; // edi
  double v93; // st7
  unsigned int v94; // ebx
  unsigned int v95; // eax
  int v96; // eax
  unsigned int v97; // ecx
  unsigned int *v98; // edi
  unsigned int v99; // ebx
  unsigned int *v100; // ecx
  unsigned int v101; // eax
  unsigned int v102; // edi
  unsigned int k; // eax
  int v104; // edi
  _DWORD *v105; // eax
  char *v106; // ecx
  char *v107; // edx
  int v108; // eax
  __int64 x; // [esp+0h] [ebp-7Ch]
  __int64 xa; // [esp+0h] [ebp-7Ch]
  __int64 xb; // [esp+0h] [ebp-7Ch]
  __int64 xc; // [esp+0h] [ebp-7Ch]
  __int64 xd; // [esp+0h] [ebp-7Ch]
  unsigned int *v114; // [esp+14h] [ebp-68h]
  unsigned int *v115; // [esp+18h] [ebp-64h]
  unsigned int *v116; // [esp+1Ch] [ebp-60h]
  unsigned int *v117; // [esp+20h] [ebp-5Ch]
  unsigned int *v118; // [esp+24h] [ebp-58h]
  unsigned int *v119; // [esp+28h] [ebp-54h]
  unsigned int *v120; // [esp+2Ch] [ebp-50h]
  unsigned int *v121; // [esp+30h] [ebp-4Ch]
  unsigned int *v122; // [esp+34h] [ebp-48h]
  unsigned int *v123; // [esp+38h] [ebp-44h]
  unsigned int *v124; // [esp+3Ch] [ebp-40h]
  unsigned int *v125; // [esp+40h] [ebp-3Ch]
  unsigned int v126; // [esp+44h] [ebp-38h] BYREF
  unsigned int v127[2]; // [esp+48h] [ebp-34h] BYREF
  unsigned int v128[2]; // [esp+50h] [ebp-2Ch] BYREF
  int v129; // [esp+58h] [ebp-24h]
  BOOL v130; // [esp+5Ch] [ebp-20h]
  int v131; // [esp+60h] [ebp-1Ch]
  unsigned int v132; // [esp+64h] [ebp-18h]
  unsigned int *v133; // [esp+68h] [ebp-14h]
  unsigned int v134; // [esp+6Ch] [ebp-10h]
  int v135; // [esp+70h] [ebp-Ch]
  unsigned int v136; // [esp+74h] [ebp-8h]
  unsigned int v137; // [esp+78h] [ebp-4h]
  struct D3DXShader::CNode *v138; // [esp+84h] [ebp+8h]
  int v139; // [esp+88h] [ebp+Ch]
  unsigned int *v140; // [esp+90h] [ebp+14h]

  if ( a5 == 0 )
    goto LABEL_41;
  v9 = HIDWORD(a3);
  v137 = 0;
  if ( HIDWORD(a3) != 0 )
    v136 = a5 / HIDWORD(a3);
  else
    v136 = 1;
  if ( D3DXShader::CCompiler::EvalRange(this, a2: *(_DWORD *)a7, a3: (struct D3DXShader::_D3DXRANGE *)v127) < 0 )
    goto LABEL_27;
  if ( (v11 | v12) != 0 )
  {
    v13 = *(double *)v127 - *((double *)this + 22);
  }
  else if ( *(double *)v127 <= 0.0 )
  {
    v13 = 0.0;
  }
  else
  {
    v13 = *(double *)v127 + *((double *)this + 22);
  }
  *(double *)v127 = v13;
  if ( *(double *)v128 >= 0.0 )
  {
    if ( *(double *)v128 <= 0.0 )
      v14 = 0.0;
    else
      v14 = *(double *)v128 + *((double *)this + 22);
  }
  else
  {
    v14 = *(double *)v128 - *((double *)this + 22);
  }
  *(double *)v128 = v14;
  if ( _finite(x: *(long double *)v127) != 0 && *(double *)v127 >= 0.0 )
    v137 = (__int64)*(double *)v127;
  else
    v137 = 0;
  if ( *(double *)v128 < 0.0 || HIDWORD(a3) * v137 >= a5 )
  {
    if ( *((_DWORD *)this + 22) != 0 )
    {
      *((_DWORD *)this + 23) = 1;
      v25 = (unsigned int *)a3;
      if ( (_DWORD)a3 != 0 )
      {
        v26 = a4;
LABEL_40:
        qmemcpy(v25, v26, 4 * v9);
      }
      return 0;
    }
LABEL_41:
    D3DXShader::CCompiler::Error(this, a2, a3: 0xDB0u, format: "array index out of bounds");
    return -2147467259;
  }
  if ( _finite(x: *(long double *)v128) != 0 )
    v15 = (__int64)*(double *)v128;
  else
    LODWORD(v15) = v136 - 1;
  v16 = v15 + 1;
  if ( v136 > v16 )
    v136 = v16;
LABEL_27:
  if ( (_DWORD)a3 == 0 )
    return 0;
  if ( a8 == 0 )
  {
    result = D3DXShader::CCompiler::Unalias(this, a2: (struct D3DXShader::CNode **)a6, a3: a4, a4: a5);
    if ( result < 0 )
      return result;
  }
  v18 = -1;
  v19 = 0;
  v134 = 0;
  if ( a5 != 0 )
  {
    v20 = *((_DWORD *)this + 2);
    v21 = *(struct D3DXShader::CNode **)(v20 + 20);
    v22 = *(_DWORD *)(v20 + 16);
    a6 = v21;
    v131 = v22;
    do
    {
      v23 = *(_DWORD *)(*(_DWORD *)(v131 + 4 * *(_DWORD *)(*((_DWORD *)a6 + a4[v19]) + 4)) + 4);
      v134 |= v23;
      v18 &= v23;
      ++v19;
    }
    while ( v19 < a5 );
  }
  v9 = HIDWORD(a3);
  v130 = (v134 & 0x80) == 0;
  v131 = v18 & 2;
  v24 = v18 & 0x40;
  v129 = v24;
  a6 = (struct D3DXShader::CNode *)(v18 & 0x400);
  if ( (v134 & 0x100000) != 0 )
  {
    if ( v137 < *((_DWORD *)this + 26) || v136 > *((_DWORD *)this + 27) )
    {
      a6 = nullptr;
LABEL_44:
      *((_DWORD *)this + 24) = 1;
    }
  }
  else if ( a6 == nullptr && (*(_BYTE *)(*((_DWORD *)this + 2) + 113) & 2) == 0 )
  {
    goto LABEL_44;
  }
  if ( v137 + 1 == v136 )
  {
    v26 = &a4[HIDWORD(a3) * v137];
LABEL_65:
    v25 = (unsigned int *)a3;
    goto LABEL_40;
  }
  v27 = HIDWORD(a3);
  v135 = v24;
  v134 = v24;
  v132 = HIDWORD(a3);
  if ( HIDWORD(a3) < a5 )
  {
    v133 = a4;
    do
    {
      if ( v135 == 0 && v134 == 0 )
        goto LABEL_61;
      v28 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
      v29 = *(_DWORD **)(v28 + 4 * *v133);
      v30 = *(_DWORD **)(v28 + 4 * a4[v27]);
      if ( v29[1] == v30[1] && v29[2] == v30[2] )
      {
        if ( v29[3] != v30[3] )
          v135 = 0;
        if ( v29[4] == v30[4] )
          goto LABEL_59;
      }
      else
      {
        v135 = 0;
      }
      v134 = 0;
LABEL_59:
      ++v133;
      v27 = ++v132;
    }
    while ( v132 < a5 );
  }
  if ( v134 == 0 )
LABEL_61:
    a6 = nullptr;
  if ( v135 != 0 && v134 != 0 )
  {
    v26 = a4;
    goto LABEL_65;
  }
  if ( a6 == nullptr )
    goto LABEL_76;
  if ( v135 == 0 )
  {
    v31 = *((_DWORD *)this + 2);
    v32 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 20) + 4 * a4[HIDWORD(a3)]) + 12)
        - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 20) + 4 * *a4) + 12);
    v9 = HIDWORD(a3);
    v134 = 1;
    if ( HIDWORD(a3) > 1 )
    {
      v33 = *(_DWORD *)(v31 + 20);
      v133 = &a4[HIDWORD(a3) + 1];
      while ( v32 == *(_DWORD *)(*(_DWORD *)(v33 + 4 * *v133) + 12) - *(_DWORD *)(*(_DWORD *)(v33 + 4 * a4[v134]) + 12) )
      {
        ++v134;
        ++v133;
        if ( v134 >= HIDWORD(a3) )
          goto LABEL_74;
      }
      a6 = nullptr;
LABEL_74:
      v9 = HIDWORD(a3);
    }
  }
  if ( a6 == nullptr )
LABEL_76:
    v131 = 0;
  if ( a8 != 0 && v131 == 0 )
  {
    if ( *((_DWORD *)this + 22) == 0 || *((_DWORD *)this + 17) == 0 )
      D3DXShader::CCompiler::Error(
        this,
        a2,
        a3: 0xDACu,
        format: "array reference cannot be used as an l-value; not natively addressable");
    return -2147467259;
  }
  if ( a6 != nullptr )
  {
    v34 = 1;
    if ( a5 > v9 )
      v34 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a4[v9]) + 12)
          - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *a4) + 12);
    a5 = *(_DWORD *)a7;
    if ( v34 != 1 || (*(_BYTE *)(*((_DWORD *)this + 2) + 111) & 1) == 0 )
    {
      v35 = *((unsigned int **)this + 2);
      a7 = v34;
      a8 = D3DXShader::CBaseProgram::AddArgument(
             this: (D3DXShader::CBaseProgram *)v35,
             a2: v35[30],
             a3: 0,
             a4: 0,
             a5: (double)(unsigned int)v34);
      if ( a8 == -1 )
        return -2147024882;
      v126 = -1;
      v127[0] = -1;
      v127[1] = -1;
      v128[0] = -1;
      v128[1] = -1;
      if ( (**(_BYTE **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a5) & 2) == 0 )
      {
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: (unsigned int)&loc_101FFFFF + 2,
                   a4: &v126,
                   &a5,
                   a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10400001u,
                   a4: v127,
                   a5: &v126,
                   a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10100001u,
                   a4: &v127[1],
                   a5: v127,
                   a6: 0x800000000LL);
        if ( result < 0 )
          return result;
        HIDWORD(x) = 6;
        LODWORD(x) = &v126;
        result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20400001u, a4: v128, a5: &v127[1], a6: x);
        if ( result < 0 )
          return result;
        a5 = v128[0];
      }
      HIDWORD(xa) = 2;
      LODWORD(xa) = &a8;
      result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20500001u, a4: &v128[1], &a5, a6: xa);
      if ( result < 0 )
        return result;
      a5 = v128[1];
    }
    v36 = *((_DWORD *)this + 2);
    a7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v36 + 20) + 4 * *a4) + 8);
    if ( a7 == -1 )
    {
LABEL_105:
      if ( *(_DWORD *)(*((_DWORD *)this + 2) + 48) != 0 )
      {
        a8 = -1;
        result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x10000001u, a4: &a8, &a5, a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        v37 = *((_DWORD *)this + 2);
        a5 = a8;
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v37 + 20) + 4 * a8) + 4) = *(_DWORD *)(v37 + 140);
      }
      a8 = 0;
      if ( HIDWORD(a3) == 0 )
        return 0;
      v38 = a3 - (_DWORD)a4;
      v138 = (struct D3DXShader::CNode *)a4;
      v139 = a3 - (_DWORD)a4;
      while ( 1 )
      {
        v39 = D3DXShader::CBaseProgram::AddArgument(
                this: *((D3DXShader::CBaseProgram **)this + 2),
                a2: *(_DWORD *)(*((_DWORD *)this + 2) + 136),
                a3: 0,
                a4: 0,
                a5: 0.0);
        *(_DWORD *)((char *)v138 + v38) = v39;
        if ( v39 == -1 )
          break;
        v40 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
        v41 = *(_DWORD *)(v40 + 4 * v39);
        D3DXShader::CArgument::Initialize(
          this: (D3DXShader::CArgument *)v41,
          a2: *(struct D3DXShader::CArgument **)(v40 + 4 * *(_DWORD *)v138));
        *(_DWORD *)(v41 + 52) = -1;
        v42 = v136;
        v43 = v137 < v136;
        *(_DWORD *)(v41 + 8) = a5;
        *(_DWORD *)v41 = 31;
        *(double *)(v41 + 32) = *((double *)this + 20);
        *(double *)(v41 + 40) = *((double *)this + 21);
        if ( v43 )
        {
          v44 = v42 - v137;
          v45 = &a4[a8 + HIDWORD(a3) * v137];
          do
          {
            v46 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * *v45);
            *(_DWORD *)v41 &= *(_DWORD *)v46;
            if ( (*(_BYTE *)(v46 + 1) & 1) != 0 )
            {
              if ( *(double *)(v41 + 32) > *(double *)(v46 + 32) )
                *(double *)(v41 + 32) = *(double *)(v46 + 32);
              if ( *(double *)(v41 + 40) < *(double *)(v46 + 40) )
                *(double *)(v41 + 40) = *(double *)(v46 + 40);
            }
            v45 += HIDWORD(a3);
            --v44;
          }
          while ( v44 != 0 );
          v38 = v139;
        }
        if ( *(double *)(v41 + 32) <= *(double *)(v41 + 40) )
          *(_BYTE *)(v41 + 1) |= 1u;
        if ( *(double *)(v41 + 32) == *(double *)(v41 + 40) )
          *(_BYTE *)v41 |= 0x80u;
        ++a8;
        v138 = (struct D3DXShader::CNode *)((char *)v138 + 4);
        if ( a8 >= HIDWORD(a3) )
          return 0;
      }
      return -2147024882;
    }
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v36 + 20) + 4 * a7) + 4) = *(_DWORD *)(v36 + 136);
    v126 = -1;
    v127[0] = -1;
    v127[1] = -1;
    v128[0] = -1;
    v128[1] = -1;
    if ( (**(_BYTE **)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * a7) & 2) != 0 )
    {
LABEL_103:
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: 0x20400001u,
                 a4: &v128[1],
                 a5: &a7,
                 a6: (unsigned int)&a5);
      if ( result < 0 )
        return result;
      a5 = v128[1];
      goto LABEL_105;
    }
    result = D3DXShader::CCompiler::EmitInst(
               (char **)this,
               a2,
               a3: (unsigned int)&loc_101FFFFF + 2,
               a4: &v126,
               a5: &a7,
               a6: 0x400000000LL);
    if ( result >= 0 )
    {
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: 0x10400001u,
                 a4: v127,
                 a5: &v126,
                 a6: 0x400000000LL);
      if ( result >= 0 )
      {
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10100001u,
                   a4: &v127[1],
                   a5: v127,
                   a6: 0x800000000LL);
        if ( result >= 0 )
        {
          HIDWORD(xb) = 6;
          LODWORD(xb) = &v126;
          result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20400001u, a4: v128, a5: &v127[1], a6: xb);
          if ( result >= 0 )
          {
            a7 = v128[0];
            goto LABEL_103;
          }
        }
      }
    }
    return result;
  }
  if ( !v130 )
  {
    if ( *((_DWORD *)this + 22) != 0 )
      *((_DWORD *)this + 24) = 1;
    else
      D3DXShader::CCompiler::Error(this, a2, a3: 0xDB8u, format: "sampler array index must be a literal expression");
    return -2147467259;
  }
  v47 = *((_DWORD *)this + 2);
  if ( (**(_BYTE **)(*(_DWORD *)(v47 + 20) + 4 * *(_DWORD *)a7) & 1) == 0 )
  {
    v51 = v136 - v137;
    a5 = v136 - v137;
    if ( v136 - v137 > 4 || (HIDWORD(a3) != 1 || v129 != 0) && (HIDWORD(a3) > 4 || v135 == 0) )
    {
      if ( *((_DWORD *)this + 22) != 0 )
        *((_DWORD *)this + 24) = 1;
      v79 = D3DXShader::CCompiler::Scratch(this, a2: 2 * (v51 + HIDWORD(a3) + 2 * v51) + 4);
      if ( v79 == nullptr )
        return -2147024882;
      result = D3DXShader::CCompiler::EmitTemp(this, a2: v79, a3: 2 * (v51 + HIDWORD(a3) + 2 * v51) + 4);
      if ( result < 0 )
        return result;
      v81 = v80;
      for ( i = 0; i < 4; ++i )
        (&v114)[i] = v81++;
      v83 = 4;
      v84 = 4 * v51;
      do
      {
        (&v114)[v83] = v81;
        v81 = (unsigned int *)((char *)v81 + v84);
        ++v83;
      }
      while ( v83 < 0xA );
      for ( j = 10; j < 0xC; ++j )
      {
        (&v114)[j] = v81;
        v81 += HIDWORD(a3);
      }
      v86 = *(_DWORD *)a7;
      v87 = *((_DWORD *)this + 2);
      a8 = v86;
      if ( (**(_BYTE **)(*(_DWORD *)(v87 + 20) + 4 * v86) & 2) == 0 )
      {
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: (unsigned int)&loc_101FFFFF + 2,
                   a4: v114,
                   a5: &a8,
                   a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10400001u,
                   a4: v115,
                   a5: v114,
                   a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10100001u,
                   a4: v116,
                   a5: v115,
                   a6: 0x800000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x20400001u,
                   a4: v117,
                   a5: v116,
                   a6: (unsigned int)v114 | 0x600000000LL);
        if ( result < 0 )
          return result;
        v86 = *v117;
        a8 = *v117;
      }
      v88 = *((_DWORD *)this + 2);
      if ( (*(_BYTE *)(v88 + 113) & 2) != 0 && a5 <= 4 )
      {
        if ( v137 != 0 )
        {
          a7 = v137;
          a6 = (struct D3DXShader::CNode *)D3DXShader::CBaseProgram::AddArgument(
                                             this: (D3DXShader::CBaseProgram *)v88,
                                             a2: *(_DWORD *)(v88 + 120),
                                             a3: 0,
                                             a4: 0,
                                             a5: -(double)v137);
          if ( a6 == (struct D3DXShader::CNode *)-1 )
            return -2147024882;
          a7 = -1;
          HIDWORD(xd) = 4;
          LODWORD(xd) = &a6;
          result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20400001u, a4: &a7, a5: &a8, a6: xd);
          if ( result < 0 )
            return result;
          a8 = a7;
        }
        if ( *(_DWORD *)(*((_DWORD *)this + 2) + 48) != 0 )
        {
          a7 = -1;
          result = D3DXShader::CCompiler::EmitInst(
                     (char **)this,
                     a2,
                     a3: 0x10000001u,
                     a4: &a7,
                     a5: &a8,
                     a6: 0x400000000LL);
          if ( result < 0 )
            return result;
          v89 = *((_DWORD *)this + 2);
          a8 = a7;
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v89 + 20) + 4 * a7) + 4) = *(_DWORD *)(v89 + 140);
        }
        if ( *((_DWORD *)this + 18) == -1 )
        {
          v90 = D3DXShader::CBaseProgram::AddPool(
                  this: *((D3DXShader::CBaseProgram **)this + 2),
                  a2: "l",
                  a3: 0x751u,
                  a4: 4u,
                  a5: 4u);
          *((_DWORD *)this + 18) = v90;
          if ( v90 != -1 )
          {
            v91 = 0;
LABEL_228:
            v92 = 0;
            while ( 1 )
            {
              v93 = v91 == v92 ? 1.0 : 0.0;
              if ( D3DXShader::CBaseProgram::AddArgument(
                     this: *((D3DXShader::CBaseProgram **)this + 2),
                     a2: *((_DWORD *)this + 18),
                     a3: v91,
                     a4: v92,
                     a5: v93) == -1 )
                break;
              if ( ++v92 >= 4 )
              {
                if ( ++v91 < 4 )
                  goto LABEL_228;
                goto LABEL_235;
              }
            }
          }
          return -2147024882;
        }
LABEL_235:
        v94 = 0;
        if ( a5 != 0 )
        {
          do
          {
            v95 = D3DXShader::CBaseProgram::AddArgument(
                    this: *((D3DXShader::CBaseProgram **)this + 2),
                    a2: *((_DWORD *)this + 18),
                    a3: 0,
                    a4: v94,
                    a5: 0.0);
            v123[v94] = v95;
            if ( v95 == -1 )
              return -2147024882;
            v96 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v95);
            v97 = a8;
            *(double *)(v96 + 32) = 0.0;
            v43 = ++v94 < a5;
            *(double *)(v96 + 40) = 1.0;
            *(_DWORD *)(v96 + 8) = v97;
            *(_DWORD *)v96 = 279;
          }
          while ( v43 );
        }
      }
      else
      {
        v98 = v119;
        v99 = 0;
        if ( a5 != 0 )
        {
          a7 = (char *)v118 - (char *)v119;
          while ( 1 )
          {
            *(unsigned int *)((char *)v98 + a7) = v86;
            v100 = *((unsigned int **)this + 2);
            a6 = (struct D3DXShader::CNode *)(v99 + v137);
            v101 = D3DXShader::CBaseProgram::AddArgument(
                     this: (D3DXShader::CBaseProgram *)v100,
                     a2: v100[30],
                     a3: 0,
                     a4: 0,
                     a5: -(double)(v99 + v137));
            *v98 = v101;
            if ( v101 == -1 )
              return -2147024882;
            ++v99;
            ++v98;
            if ( v99 >= a5 )
              break;
            v86 = a8;
          }
        }
        v102 = a5 & 0xFFFFF;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: a5 & 0xFFFFF | 0x20400000,
                   a4: v120,
                   a5: v118,
                   a6: (unsigned int)v119 | 0x200000000LL);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitPositive(this, a2, a3: v121, a4: v122, a5: v120, a6: a5);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: v102 | 0x20300000,
                   a4: v123,
                   a5: v122,
                   a6: (unsigned int)v121 | 0x1700000000LL);
        if ( result < 0 )
          return result;
      }
      for ( k = 0; k < HIDWORD(a3); ++k )
        *(_DWORD *)(a3 + 4 * k) = *((_DWORD *)this + 9);
      a6 = nullptr;
      if ( a5 == 0 )
        return 0;
      a7 = (unsigned int)v123;
      v140 = &a4[HIDWORD(a3) * v137];
      while ( 1 )
      {
        v104 = HIDWORD(a3);
        if ( HIDWORD(a3) != 0 )
        {
          v105 = (_DWORD *)a3;
          v106 = (char *)v124 - a3;
          v107 = (char *)v125 - a3;
          do
          {
            *(_DWORD *)((char *)v105 + (_DWORD)v106) = *(_DWORD *)a7;
            *(_DWORD *)((char *)v105 + (_DWORD)v107) = *v105;
            ++v105;
            --v104;
          }
          while ( v104 != 0 );
        }
        result = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)a3, a3: HIDWORD(a3));
        if ( result < 0 )
          break;
        v108 = *(_DWORD *)(*((_DWORD *)this + 2) + 108);
        if ( (v108 & 0x80u) == 0 || (v108 & 4) != 0 )
        {
          result = D3DXShader::CCompiler::EmitInst(
                     (char **)this,
                     a2,
                     a3: HIDWORD(a3) & 0xFFFFF | 0x20500000,
                     a4: (unsigned int *)a3,
                     a5: v124,
                     a6: (unsigned int)v140);
          if ( result < 0 )
            return result;
          result = D3DXShader::CCompiler::EmitInst(
                     (char **)this,
                     a2,
                     a3: HIDWORD(a3) & 0xFFFFF | 0x20400000,
                     a4: (unsigned int *)a3,
                     a5: (unsigned int *)a3,
                     a6: (unsigned int)v125);
        }
        else
        {
          result = D3DXShader::CCompiler::EmitLerp(
                     this,
                     a2,
                     (unsigned int *)a3,
                     a4: v125,
                     a5: v140,
                     a6: v124,
                     a7: HIDWORD(a3));
        }
        if ( result < 0 )
          break;
        a6 = (struct D3DXShader::CNode *)((char *)a6 + 1);
        a7 += 4;
        v140 += HIDWORD(a3);
        if ( (unsigned int)a6 >= a5 )
          return 0;
      }
      return result;
    }
    if ( *((_DWORD *)this + 22) != 0 && (HIDWORD(a3) > 1 || (*(_BYTE *)(v47 + 113) & 2) == 0) )
      *((_DWORD *)this + 24) = 1;
    v52 = D3DXShader::CCompiler::Scratch(this, a2: 7 * v51 + 4);
    if ( v52 == nullptr )
      return -2147024882;
    result = D3DXShader::CCompiler::EmitTemp(this, a2: v52, a3: 7 * v51 + 4);
    if ( result < 0 )
      return result;
    v54 = v53;
    for ( m = 0; m < 4; ++m )
      (&v114)[m] = v54++;
    v56 = 4;
    v57 = 4 * v51;
    do
    {
      (&v114)[v56] = v54;
      v54 = (unsigned int *)((char *)v54 + v57);
      ++v56;
    }
    while ( v56 < 0xB );
    v58 = *(_DWORD *)a7;
    v59 = *((_DWORD *)this + 2);
    a8 = v58;
    if ( (**(_BYTE **)(*(_DWORD *)(v59 + 20) + 4 * v58) & 2) == 0
      && ((*(_BYTE *)(v59 + 113) & 2) == 0 || (*(_BYTE *)(v59 + 111) & 1) == 0) )
    {
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: (unsigned int)&loc_101FFFFF + 2,
                 a4: v114,
                 a5: &a8,
                 a6: 0x400000000LL);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: 0x10400001u,
                 a4: v115,
                 a5: v114,
                 a6: 0x400000000LL);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: 0x10100001u,
                 a4: v116,
                 a5: v115,
                 a6: 0x800000000LL);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: 0x20400001u,
                 a4: v117,
                 a5: v116,
                 a6: (unsigned int)v114 | 0x600000000LL);
      if ( result < 0 )
        return result;
      v58 = *v117;
      a8 = *v117;
    }
    v60 = *((_DWORD *)this + 2);
    if ( (*(_BYTE *)(v60 + 113) & 2) != 0 )
    {
      if ( v137 != 0 )
      {
        a7 = v137;
        a6 = (struct D3DXShader::CNode *)D3DXShader::CBaseProgram::AddArgument(
                                           this: (D3DXShader::CBaseProgram *)v60,
                                           a2: *(_DWORD *)(v60 + 120),
                                           a3: 0,
                                           a4: 0,
                                           a5: -(double)v137);
        if ( a6 == (struct D3DXShader::CNode *)-1 )
          return -2147024882;
        a7 = -1;
        HIDWORD(xc) = 4;
        LODWORD(xc) = &a6;
        result = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: 0x20400001u, a4: &a7, a5: &a8, a6: xc);
        if ( result < 0 )
          return result;
        a8 = a7;
      }
      if ( *(_DWORD *)(*((_DWORD *)this + 2) + 48) != 0 )
      {
        a7 = -1;
        result = D3DXShader::CCompiler::EmitInst(
                   (char **)this,
                   a2,
                   a3: 0x10000001u,
                   a4: &a7,
                   a5: &a8,
                   a6: 0x400000000LL);
        if ( result < 0 )
          return result;
        v61 = *((_DWORD *)this + 2);
        a8 = a7;
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v61 + 20) + 4 * a7) + 4) = *(_DWORD *)(v61 + 140);
      }
      if ( *((_DWORD *)this + 18) == -1 )
      {
        v62 = D3DXShader::CBaseProgram::AddPool(
                this: *((D3DXShader::CBaseProgram **)this + 2),
                a2: "l",
                a3: 0x751u,
                a4: 4u,
                a5: 4u);
        *((_DWORD *)this + 18) = v62;
        if ( v62 != -1 )
        {
          v63 = 0;
LABEL_172:
          v64 = 0;
          while ( 1 )
          {
            v65 = v63 == v64 ? 1.0 : 0.0;
            if ( D3DXShader::CBaseProgram::AddArgument(
                   this: *((D3DXShader::CBaseProgram **)this + 2),
                   a2: *((_DWORD *)this + 18),
                   a3: v63,
                   a4: v64,
                   a5: v65) == -1 )
              break;
            if ( ++v64 >= 4 )
            {
              if ( ++v63 < 4 )
                goto LABEL_172;
              goto LABEL_179;
            }
          }
        }
        return -2147024882;
      }
LABEL_179:
      v66 = 0;
      if ( a5 != 0 )
      {
        do
        {
          v67 = D3DXShader::CBaseProgram::AddArgument(
                  this: *((D3DXShader::CBaseProgram **)this + 2),
                  a2: *((_DWORD *)this + 18),
                  a3: 0,
                  a4: v66,
                  a5: 0.0);
          v123[v66] = v67;
          if ( v67 == -1 )
            return -2147024882;
          v68 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v67);
          v69 = a8;
          *(double *)(v68 + 32) = 0.0;
          v43 = ++v66 < a5;
          *(double *)(v68 + 40) = 1.0;
          *(_DWORD *)(v68 + 8) = v69;
          *(_DWORD *)v68 = 279;
        }
        while ( v43 );
      }
    }
    else
    {
      v70 = v119;
      v71 = 0;
      if ( a5 != 0 )
      {
        a7 = (char *)v118 - (char *)v119;
        while ( 1 )
        {
          *(unsigned int *)((char *)v70 + a7) = v58;
          v72 = *((unsigned int **)this + 2);
          a6 = (struct D3DXShader::CNode *)(v71 + v137);
          v73 = D3DXShader::CBaseProgram::AddArgument(
                  this: (D3DXShader::CBaseProgram *)v72,
                  a2: v72[30],
                  a3: 0,
                  a4: 0,
                  a5: -(double)(v71 + v137));
          *v70 = v73;
          if ( v73 == -1 )
            return -2147024882;
          ++v71;
          ++v70;
          if ( v71 >= a5 )
            break;
          v58 = a8;
        }
      }
      v74 = a5 & 0xFFFFF;
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: a5 & 0xFFFFF | 0x20400000,
                 a4: v120,
                 a5: v118,
                 a6: (unsigned int)v119 | 0x200000000LL);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitPositive(this, a2, a3: v121, a4: v122, a5: v120, a6: a5);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v74 | 0x20300000,
                 a4: v123,
                 a5: v122,
                 a6: (unsigned int)v121 | 0x1700000000LL);
      if ( result < 0 )
        return result;
    }
    result = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)a3, a3: HIDWORD(a3));
    if ( result < 0 )
      return result;
    a7 = 0;
    if ( HIDWORD(a3) == 0 )
      return 0;
    v75 = v124;
    v76 = a5 & 0xFFFFF | 0x50000000;
    while ( 1 )
    {
      v77 = 0;
      if ( a5 != 0 )
      {
        v78 = &a4[a7 + HIDWORD(a3) * v137];
        do
        {
          v75[v77++] = *v78;
          v78 += HIDWORD(a3);
        }
        while ( v77 < a5 );
      }
      result = D3DXShader::CCompiler::EmitInst(
                 (char **)this,
                 a2,
                 a3: v76,
                 a4: (unsigned int *)a3,
                 a5: v75,
                 a6: (unsigned int)v123);
      if ( result < 0 )
        break;
      ++a7;
      LODWORD(a3) = a3 + 4;
      if ( a7 >= HIDWORD(a3) )
        return 0;
    }
    return result;
  }
  v48 = D3DXShader::CCompiler::Scratch(this, a2: v9);
  if ( v48 == nullptr )
    return -2147024882;
  for ( n = 0; n < v9; ++n )
    v48[n] = *(_DWORD *)a7;
  result = D3DXShader::CCompiler::EmitTemp(this, a2: (unsigned int *)a3, a3: v9);
  if ( result >= 0 )
  {
    result = D3DXShader::CCompiler::EmitLerp(this, a2, (unsigned int *)a3, a4, a5: &a4[v9], a6: v50, a7: v9);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D714E
// Name: protected: long D3DXShader::CCompiler::EmitFor(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitFor(
        const void **this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5)
{
  int result; // eax
  int v7; // eax
  unsigned int v8; // esi
  unsigned int *v9; // edx
  const void *v10; // esi
  const void *v11; // edi
  unsigned int v12; // [esp+8h] [ebp-14h]
  unsigned int v13; // [esp+Ch] [ebp-10h]
  const void *v14; // [esp+10h] [ebp-Ch]
  unsigned int *pMem; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  if ( a3 != nullptr && (a5 != a3 || (*((_BYTE *)*(this + 2) + 112) & 4) == 0) )
  {
    result = D3DXShader::CCompiler::EmitStatement((D3DXShader::CCompiler *)this, a2: a3, a3: nullptr);
    if ( result < 0 )
      return result;
    if ( *(this + 20) != nullptr || *(this + 21) != nullptr )
      return 0;
    a3 = nullptr;
  }
  v7 = (int)*(this + 2);
  v8 = 4 * *((_DWORD *)*(this + 1) + 6);
  v12 = *(_DWORD *)(v7 + 8);
  v13 = *(_DWORD *)(v7 + 12);
  v9 = (unsigned int *)MemAlloc_Alloc(nSize: v8);
  pMem = v9;
  if ( v9 != nullptr )
  {
    qmemcpy(v9, *(this + 6), v8);
    if ( *((_DWORD *)*(this + 2) + 23) != 0 )
    {
      v10 = *(this + 22);
      v11 = *(this + 23);
      v14 = *(this + 24);
      *(this + 22) = (const void *)1;
      *(this + 23) = nullptr;
      *(this + 24) = nullptr;
      v16 = D3DXShader::CCompiler::EmitForLoop(
              (D3DXShader::CCompiler *)this,
              a2,
              (unsigned int)a3,
              a4,
              k: a5,
              a6: (unsigned int)v9);
      *(this + 19) = nullptr;
      *(this + 20) = nullptr;
      *(this + 21) = nullptr;
      *(this + 22) = v10;
      *(this + 23) = v11;
      *(this + 24) = v14;
      if ( v16 >= 0 )
        goto LABEL_16;
      D3DXShader::CCompiler::Reset((D3DXShader::CCompiler *)this, a2: v12, a3: v13, a4: pMem);
    }
    v16 = D3DXShader::CCompiler::EmitForUnrolled((D3DXShader::CCompiler *)this, a2, (unsigned int)a3, a4, a5, j: pMem);
    if ( v16 >= 0 )
      v16 = 0;
    goto LABEL_16;
  }
  v16 = -2147024882;
LABEL_16:
  free(pMem);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x101D727C
// Name: protected: long D3DXShader::CCompiler::EmitStatement(class D3DXShader::CNode __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitStatement(D3DXShader::CCompiler *this, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // esi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  struct D3DXShader::CNode **v13; // ecx
  D3DXShader::CBaseProgram *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  int v17; // ecx
  _DWORD *v18; // ecx
  unsigned int v19; // edx
  int v20; // edi
  int result; // eax
  int v22; // eax
  unsigned int v23; // edi
  int v24; // eax
  unsigned int v25; // eax
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // esi
  D3DXShader::CInstruction *v29; // ecx
  int v30; // eax
  unsigned int *v31; // esi
  unsigned int v32; // [esp+14h] [ebp-1Ch]
  struct D3DXShader::CNode *v33; // [esp+18h] [ebp-18h]
  struct D3DXShader::CNode *v34; // [esp+18h] [ebp-18h]
  struct D3DXShader::CNode **v35; // [esp+1Ch] [ebp-14h]
  struct D3DXShader::CNode *v36; // [esp+1Ch] [ebp-14h]
  int v37; // [esp+20h] [ebp-10h]
  unsigned int v38; // [esp+20h] [ebp-10h]
  unsigned int v39; // [esp+24h] [ebp-Ch]
  int v40; // [esp+28h] [ebp-8h]
  int v41; // [esp+2Ch] [ebp-4h]

  v3 = a2;
  if ( a2 == 0 || *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0 )
    return 0;
  v5 = *(_DWORD *)(*((_DWORD *)this + 2) + 12);
  v6 = *(_DWORD *)(a2 + 4);
  v32 = *(_DWORD *)(*((_DWORD *)this + 2) + 12);
  if ( v6 == 6 )
  {
    v7 = *(_DWORD *)(a2 + 16);
    if ( v7 == 1 )
    {
      v8 = *(_DWORD *)(a2 + 24);
      a2 = *(_DWORD *)(v8 + 16);
      v39 = *(_DWORD *)(v8 + 20);
      v9 = *(_DWORD *)(v8 + 24);
      if ( v9 != 0 || (v40 = 1, (*(_BYTE *)(v8 + 28) & 0x40) == 0) )
        v40 = 0;
      if ( v9 == 0 || (v37 = 1, (*(_BYTE *)(v8 + 28) & 2) == 0) )
        v37 = 0;
      v35 = *(struct D3DXShader::CNode ***)(v8 + 32);
      v10 = *(_DWORD *)(v8 + 28) & 0x80;
      v33 = *(struct D3DXShader::CNode **)(v8 + 48);
      v11 = a2;
      *(_DWORD *)(v8 + 28) &= 0xFFFFF3FF;
LABEL_15:
      if ( v10 != 0 )
      {
        D3DXShader::CCompiler::EmitExpression(
          this,
          a2: *(struct D3DXShader::CNode **)(*(_DWORD *)(v3 + 24) + 40),
          a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * v11),
          a4: nullptr);
        goto LABEL_72;
      }
      a2 = 0;
      if ( v39 != 0 )
      {
        v41 = 4 * v11;
        do
        {
          if ( v37 == 0 || *(_DWORD *)(v41 + *((_DWORD *)this + 6)) == -1 )
          {
            v14 = *((D3DXShader::CBaseProgram **)this + 2);
            if ( v40 != 0 )
              v15 = *((_DWORD *)v14 + 31);
            else
              v15 = *((_DWORD *)v14 + 29);
            v16 = D3DXShader::CBaseProgram::AddArgument(this: v14, a2: v15, a3: 0, a4: 0, a5: 0.0);
            v17 = *((_DWORD *)this + 2);
            if ( v16 >= *(_DWORD *)(v17 + 8) )
              v18 = nullptr;
            else
              v18 = *(_DWORD **)(*(_DWORD *)(v17 + 20) + 4 * v16);
            if ( v18 != nullptr )
            {
              v18[12] = v11 + a2;
              v19 = a2;
              v18[24] = v3;
              v18[25] = v19;
            }
            *(_DWORD *)(v41 + *((_DWORD *)this + 6)) = v16;
          }
          ++a2;
          v41 += 4;
        }
        while ( a2 < v39 );
      }
      if ( v40 != 0 )
      {
        v20 = 4 * v11;
        result = D3DXShader::CCompiler::ApplyType(
                   this,
                   a2: v35,
                   a3: (unsigned int *)(v20 + *((_DWORD *)this + 6)),
                   a4: v39);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::Vectorize(
                   this,
                   a2: v35,
                   a3: (unsigned int *)(v20 + *((_DWORD *)this + 6)),
                   a4: *(_DWORD *)(*((_DWORD *)this + 2) + 124),
                   a5: 1,
                   a6: 0,
                   a7: nullptr,
                   a8: v33);
        if ( result < 0 )
          return result;
        result = D3DXShader::CCompiler::VectorizeDefaults(this, a2: *(struct D3DXShader::CNode **)(v3 + 24));
        goto LABEL_35;
      }
      goto LABEL_72;
    }
    if ( v7 == 2 )
    {
      v12 = *(_DWORD *)(a2 + 24);
      v11 = *(_DWORD *)(v12 + 16);
      v39 = *(_DWORD *)(v12 + 20);
      v13 = *(struct D3DXShader::CNode ***)(v12 + 32);
      v10 = 0;
      *(_BYTE *)(v12 + 25) &= 0xF3u;
      v35 = v13;
      v40 = 0;
      v37 = 0;
      v33 = *(struct D3DXShader::CNode **)(v12 + 52);
      goto LABEL_15;
    }
    return 0;
  }
  if ( v6 != 12 )
  {
    if ( v6 != 1 )
    {
      D3DXShader::CCompiler::Error(this, a2: nullptr, a3: 0, format: "internal error: unrecognized statement");
      return -2147467259;
    }
    do
    {
      if ( *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0 )
        break;
      result = D3DXShader::CCompiler::EmitStatement(this, a2: *(struct D3DXShader::CNode **)(v3 + 8), a3: nullptr);
      if ( result < 0 )
        return result;
      v3 = *(_DWORD *)(v3 + 12);
    }
    while ( v3 != 0 );
    goto LABEL_72;
  }
  v22 = *(_DWORD *)(a2 + 16);
  if ( v22 < 0 )
    goto LABEL_72;
  if ( v22 > 1 )
  {
    if ( v22 == 2 )
    {
      a2 = -1;
      result = D3DXShader::CCompiler::EmitExpression(
                 this,
                 a2: *(struct D3DXShader::CNode **)(v3 + 24),
                 a3: &a2,
                 a4: nullptr);
      if ( result < 0 )
        return result;
      result = D3DXShader::CCompiler::EmitIf(
                 this,
                 a2: *(struct D3DXShader::CNode **)(v3 + 24),
                 a3: a2,
                 a4: *(_DWORD *)(v3 + 28),
                 m: *(struct D3DXShader::CNode **)(v3 + 32));
    }
    else if ( v22 == 3 )
    {
      result = D3DXShader::CCompiler::EmitFor(
                 (const void **)this,
                 (struct D3DXShader::CNode *)a2,
                 a3: *(struct D3DXShader::CNode **)(a2 + 20),
                 a4: *(struct D3DXShader::CNode **)(a2 + 24),
                 a5: *(struct D3DXShader::CNode **)(a2 + 28));
    }
    else if ( v22 == 4 )
    {
      result = D3DXShader::CCompiler::EmitFor(
                 (const void **)this,
                 (struct D3DXShader::CNode *)a2,
                 a3: nullptr,
                 a4: *(struct D3DXShader::CNode **)(a2 + 24),
                 a5: *(struct D3DXShader::CNode **)(a2 + 28));
    }
    else
    {
      if ( v22 != 5 )
      {
        if ( v22 == 6 )
        {
          result = D3DXShader::CCompiler::EmitClip(
                     this,
                     a2: *(struct D3DXShader::CNode **)(a2 + 24),
                     a3: (unsigned int *)this + 10,
                     a4: 1u);
          if ( result < 0 )
            return result;
          *((_DWORD *)this + 21) = 1;
        }
        goto LABEL_72;
      }
      result = D3DXShader::CCompiler::EmitFor(
                 (const void **)this,
                 (struct D3DXShader::CNode *)a2,
                 a3: *(struct D3DXShader::CNode **)(a2 + 28),
                 a4: *(struct D3DXShader::CNode **)(a2 + 24),
                 a5: *(struct D3DXShader::CNode **)(a2 + 28));
    }
LABEL_35:
    if ( result < 0 )
      return result;
    goto LABEL_72;
  }
  v23 = v5;
  result = D3DXShader::CCompiler::EmitExpression(
             this,
             a2: *(struct D3DXShader::CNode **)(a2 + 20),
             a3: nullptr,
             a4: nullptr);
  if ( result < 0 )
    return result;
  v24 = *((_DWORD *)this + 2);
  v36 = nullptr;
  v34 = nullptr;
  v38 = *(_DWORD *)(v24 + 12);
  if ( v23 < v38 )
  {
    a2 = *(_DWORD *)(v24 + 24) + 4 * v23;
    v25 = *(_DWORD *)(*((_DWORD *)this + 2) + 12) - v23;
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)a2 + 56) == *((_DWORD *)this + 14) )
      {
        v26 = *(_DWORD *)(*(_DWORD *)a2 + 60);
        if ( v26 != 0 && *(_DWORD *)(v26 + 4) == 13 && *(_DWORD *)(v26 + 68) >= (unsigned int)v34 )
        {
          v36 = *(struct D3DXShader::CNode **)(*(_DWORD *)a2 + 60);
          v34 = *(struct D3DXShader::CNode **)(v26 + 68);
        }
      }
      a2 += 4;
      --v25;
    }
    while ( v25 != 0 );
  }
  if ( v23 < v38 )
  {
    do
    {
      v27 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * v23);
      if ( *(_DWORD *)(v27 + 56) == *((_DWORD *)this + 14) )
        *(_DWORD *)(v27 + 60) = v36;
      ++v23;
    }
    while ( v23 < *(_DWORD *)(*((_DWORD *)this + 2) + 12) );
  }
  *((_DWORD *)this + 20) = *(_DWORD *)(v3 + 16) == 1;
LABEL_72:
  if ( *((_DWORD *)this + 21) == 0 || a3 == nullptr )
    return 0;
  v28 = v32;
  a2 = 0;
  while ( 1 )
  {
    v30 = *((_DWORD *)this + 2);
    if ( v28 >= *(_DWORD *)(v30 + 12) )
      break;
    v29 = *(D3DXShader::CInstruction **)(*(_DWORD *)(v30 + 24) + 4 * v28);
    if ( (*(_DWORD *)v29 & 0xFFF00000) == 0x11000000 )
      a2 = *((_DWORD *)v29 + 15);
    D3DXShader::CInstruction::`scalar deleting destructor'(this: v29, a2: 1);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 24) + 4 * v28++) = 0;
  }
  v31 = a3;
  *(_DWORD *)(v30 + 12) = v32;
  qmemcpy(*((void **)this + 6), v31, 4 * *(_DWORD *)(*((_DWORD *)this + 1) + 24));
  result = D3DXShader::CCompiler::EmitClip(this, (struct D3DXShader::CNode *)a2, a3: (unsigned int *)this + 10, a4: 1u);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D767A
// Name: protected: long D3DXShader::CCompiler::EmitFunction(char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,unsigned int __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitFunction(
        D3DXShader::CCompiler *this,
        char *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        unsigned int *a5,
        int a6,
        int a7)
{
  struct D3DXShader::CNode *v7; // edi
  int v10; // eax
  int v11; // ecx
  struct D3DXShader::CNode *v12; // edx
  int v13; // edx
  unsigned int v14; // esi
  struct D3DXShader::CNode *v15; // edx
  int v16; // esi
  unsigned int *v17; // eax
  int v18; // ecx
  int v19; // eax
  struct D3DXShader::CNode *v20; // eax
  struct D3DXShader::CNode *v21; // ecx
  int v22; // eax
  struct D3DXShader::CNode *v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // esi
  _DWORD *v27; // eax
  int v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // eax
  int v31; // ecx
  _DWORD *v32; // ecx
  unsigned int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  unsigned int *v37; // edx
  int v38; // esi
  int v39; // eax
  int v40; // ecx
  _DWORD *v41; // edx
  unsigned int *v42; // eax
  int v43; // ecx
  unsigned int v44; // eax
  int v45; // edx
  int v46; // eax
  unsigned int v47; // esi
  unsigned int *v48; // eax
  int v49; // esi
  unsigned int v50; // eax
  BOOL v51; // ecx
  unsigned int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // eax
  int v56; // edi
  int v57; // ecx
  int v58; // esi
  int v59; // edi
  char *v60; // eax
  _DWORD *v61; // ecx
  int v62; // eax
  int v63; // edi
  struct D3DXShader::CNode *v64; // eax
  const char *v65; // eax
  unsigned int v66; // kr00_4
  char *v67; // eax
  unsigned int *v68; // [esp-8h] [ebp-50h]
  unsigned int *v69; // [esp-8h] [ebp-50h]
  unsigned int v70; // [esp+0h] [ebp-48h]
  const void *v71; // [esp+8h] [ebp-40h]
  struct D3DXShader::CNode *v72; // [esp+14h] [ebp-34h]
  int v73; // [esp+14h] [ebp-34h]
  struct D3DXShader::CNode *v74; // [esp+18h] [ebp-30h]
  struct D3DXShader::CNode *v75; // [esp+18h] [ebp-30h]
  struct D3DXShader::CNode *v76; // [esp+18h] [ebp-30h]
  struct D3DXShader::CNode *v77; // [esp+18h] [ebp-30h]
  unsigned int *v78; // [esp+1Ch] [ebp-2Ch]
  unsigned int *pMem; // [esp+20h] [ebp-28h]
  struct D3DXShader::CNode *v80; // [esp+24h] [ebp-24h]
  struct D3DXShader::CNode *v81; // [esp+24h] [ebp-24h]
  struct D3DXShader::CNode *v82; // [esp+24h] [ebp-24h]
  unsigned int k; // [esp+24h] [ebp-24h]
  unsigned int *v84; // [esp+28h] [ebp-20h]
  unsigned int *v85; // [esp+2Ch] [ebp-1Ch]
  int v86; // [esp+30h] [ebp-18h]
  unsigned int v87; // [esp+30h] [ebp-18h]
  int v88; // [esp+30h] [ebp-18h]
  int v89; // [esp+30h] [ebp-18h]
  unsigned int v90; // [esp+34h] [ebp-14h]
  unsigned int j; // [esp+34h] [ebp-14h]
  unsigned int v92; // [esp+34h] [ebp-14h]
  int (__stdcall *v93)(unsigned int, unsigned int, const void *); // [esp+38h] [ebp-10h]
  unsigned int *v94; // [esp+3Ch] [ebp-Ch]
  unsigned int *v95; // [esp+3Ch] [ebp-Ch]
  unsigned int *v96; // [esp+3Ch] [ebp-Ch]
  unsigned int *v97; // [esp+40h] [ebp-8h]
  int v98; // [esp+44h] [ebp-4h]
  unsigned int i; // [esp+44h] [ebp-4h]
  struct D3DXShader::CNode *m; // [esp+54h] [ebp+Ch]
  struct D3DXShader::CNode *v101; // [esp+54h] [ebp+Ch]
  struct D3DXShader::CNode *v102; // [esp+54h] [ebp+Ch]
  struct D3DXShader::CNode *v103; // [esp+58h] [ebp+10h]
  struct D3DXShader::CNode *v104; // [esp+58h] [ebp+10h]
  struct D3DXShader::CNode *v105; // [esp+58h] [ebp+10h]
  struct D3DXShader::CNode *v106; // [esp+58h] [ebp+10h]
  struct D3DXShader::CNode *v107; // [esp+58h] [ebp+10h]
  struct D3DXShader::CNode *v108; // [esp+58h] [ebp+10h]
  unsigned int *v109; // [esp+5Ch] [ebp+14h]
  unsigned int *v110; // [esp+5Ch] [ebp+14h]

  v7 = a3;
  pMem = nullptr;
  v85 = nullptr;
  v78 = nullptr;
  v84 = nullptr;
  v93 = nullptr;
  v97 = nullptr;
  if ( a3 == nullptr || *((_DWORD *)a3 + 1) != 10 )
    return -2147467259;
  if ( *((_DWORD *)a3 + 14) != 0 )
  {
    D3DXShader::CCompiler::Error(this, a2: a3, a3: 0xDACu, format: "'%s': recursive functions not yet implemented", a2);
    return -2147467263;
  }
  if ( a6 != 0 )
  {
    v98 = D3DXShader::CProgram::SetName(this: *((void ***)this + 2), a2);
    if ( v98 < 0 )
      goto LABEL_137;
  }
  if ( a4 != nullptr )
    v80 = *((struct D3DXShader::CNode **)a4 + 2);
  else
    v80 = nullptr;
  if ( a4 != nullptr )
    v72 = *((struct D3DXShader::CNode **)a4 + 3);
  else
    v72 = nullptr;
  v10 = *((_DWORD *)a3 + 9);
  v11 = 0;
  while ( v10 != 0 )
  {
    v12 = *(struct D3DXShader::CNode **)(v10 + 8);
    v10 = *(_DWORD *)(v10 + 12);
    v103 = v12;
    if ( v10 != 0 )
    {
      v13 = *(_DWORD *)(v10 + 8);
      if ( v13 != 0 && *(_DWORD *)(v13 + 4) == 12 )
        v10 = *(_DWORD *)(v10 + 12);
    }
    v11 += *(_DWORD *)(*((_DWORD *)v103 + 6) + 20);
  }
  v14 = 4 * v11;
  v85 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v11);
  if ( v85 == nullptr )
    goto LABEL_182;
  if ( a6 != 0 )
  {
    v93 = (int (__stdcall *)(unsigned int, unsigned int, const void *))MemAlloc_Alloc(nSize: v14);
    if ( v93 == nullptr )
      goto LABEL_182;
  }
  v15 = v80;
  v16 = *((_DWORD *)a3 + 9);
  v17 = v85;
  v104 = v80;
  while ( 1 )
  {
    v94 = v17;
    if ( v16 == 0 )
      break;
    v18 = *(_DWORD *)(v16 + 8);
    v16 = *(_DWORD *)(v16 + 12);
    if ( v16 != 0 )
    {
      v19 = *(_DWORD *)(v16 + 8);
      if ( v19 != 0 && *(_DWORD *)(v19 + 4) == 12 )
        v16 = *(_DWORD *)(v16 + 12);
    }
    v20 = *(struct D3DXShader::CNode **)(v18 + 24);
    v74 = v20;
    if ( (a6 == 0 || a7 != 0 && (*((_BYTE *)v20 + 28) & 0x40) != 0) && v15 != nullptr )
    {
      v21 = *((struct D3DXShader::CNode **)v15 + 2);
      if ( v21 != nullptr )
      {
        v98 = D3DXShader::CCompiler::EmitExpression(this, a2: v21, a3: v94, a4: nullptr);
        if ( v98 < 0 )
          goto LABEL_137;
        v20 = v74;
        v15 = v104;
      }
      v15 = *((struct D3DXShader::CNode **)v15 + 3);
      v104 = v15;
    }
    v17 = &v94[*((_DWORD *)v20 + 5)];
  }
  v22 = *((_DWORD *)a3 + 9);
  v105 = v80;
  v95 = v85;
  if ( v22 != 0 )
  {
    while ( 1 )
    {
      v23 = *(struct D3DXShader::CNode **)(v22 + 8);
      v24 = *(_DWORD *)(v22 + 12);
      v75 = nullptr;
      v81 = v23;
      v86 = v24;
      if ( v24 != 0 )
      {
        v25 = *(_DWORD *)(v24 + 8);
        if ( v25 != 0 && *(_DWORD *)(v25 + 4) == 12 )
        {
          v75 = *(struct D3DXShader::CNode **)(v24 + 8);
          v86 = *(_DWORD *)(v24 + 12);
        }
      }
      v26 = *((_DWORD *)v81 + 6);
      if ( a6 != 0 && (a7 == 0 || (*(_BYTE *)(v26 + 28) & 0x40) == 0) )
        break;
      v98 = D3DXShader::CCompiler::EmitStatement(this, a2: (unsigned int)v81, a3: nullptr);
      if ( v98 < 0 )
        goto LABEL_137;
      if ( v105 == nullptr )
      {
        v35 = D3DXShader::CCompiler::EmitStatement(this, a2: (unsigned int)v75, a3: nullptr);
LABEL_79:
        v98 = v35;
        if ( v35 < 0 )
          goto LABEL_137;
        goto LABEL_80;
      }
      if ( (*(_BYTE *)(v26 + 28) & 0x10) != 0 )
      {
        v98 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                a2: *((struct D3DXShader::CNode **)v105 + 2),
                a3: *(_DWORD *)(v26 + 20) & 0xFFFFF | 0x10000000,
                a4: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v26 + 16)),
                a5: v95,
                a6: 0);
        if ( v98 < 0 )
          goto LABEL_137;
      }
      v105 = *((struct D3DXShader::CNode **)v105 + 3);
LABEL_80:
      v95 += *(_DWORD *)(v26 + 20);
      if ( v86 == 0 )
        goto LABEL_81;
      v22 = v86;
    }
    v27 = *((_DWORD **)this + 2);
    v90 = v27[29];
    v28 = *(_DWORD *)(v26 + 28);
    if ( (v28 & 0x40) != 0 )
    {
      v29 = v27[31];
    }
    else
    {
      if ( (v28 & 0x10) == 0 )
      {
LABEL_53:
        for ( i = 0; i < *(_DWORD *)(v26 + 20); *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v76) = v30 )
        {
          v76 = (struct D3DXShader::CNode *)(i + *(_DWORD *)(v26 + 16));
          v30 = D3DXShader::CBaseProgram::AddArgument(
                  this: *((D3DXShader::CBaseProgram **)this + 2),
                  a2: v90,
                  a3: 0,
                  a4: 0,
                  a5: 0.0);
          v31 = *((_DWORD *)this + 2);
          if ( v30 >= *(_DWORD *)(v31 + 8) )
            v32 = nullptr;
          else
            v32 = *(_DWORD **)(*(_DWORD *)(v31 + 20) + 4 * v30);
          if ( v32 != nullptr )
          {
            v32[12] = v76;
            v32[24] = v81;
            v32[25] = i;
          }
          ++i;
        }
        v33 = v90;
        if ( *(_DWORD *)(*((_DWORD *)this + 2) + 116) != v90 )
        {
          v98 = D3DXShader::CCompiler::ApplyType(
                  this,
                  a2: *(struct D3DXShader::CNode ***)(v26 + 32),
                  a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v26 + 16)),
                  a4: *(_DWORD *)(v26 + 20));
          if ( v98 < 0 )
            goto LABEL_137;
          v33 = v90;
        }
        v34 = *((_DWORD *)this + 2);
        if ( *(_DWORD *)(v34 + 124) != v33 )
        {
          if ( *(_DWORD *)(v34 + 128) == v33 )
          {
            v98 = D3DXShader::CCompiler::Vectorize(
                    this,
                    a2: *(struct D3DXShader::CNode ***)(v26 + 32),
                    a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v26 + 16)),
                    a4: v90,
                    a5: 0,
                    a6: 0,
                    a7: *(struct D3DXShader::CNode **)(v26 + 44),
                    a8: *(struct D3DXShader::CNode **)(v26 + 48));
            if ( v98 < 0 )
              goto LABEL_137;
            if ( D3DXShader::CCompiler::IsFullySemantic(
                   this,
                   a2: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v26 + 16)),
                   a3: *(_DWORD *)(v26 + 20)) != 0 )
            {
              for ( j = 0; j < *(_DWORD *)(v26 + 20); *((_DWORD *)v93 + (_DWORD)v37) = v36 )
              {
                v36 = j + *(_DWORD *)(v26 + 16);
                v37 = v97;
                v97 = (unsigned int *)((char *)v97 + 1);
                ++j;
              }
            }
            else
            {
              D3DXShader::CCompiler::Error(
                this,
                a2: (struct D3DXShader::CNode *)v26,
                a3: 0xDAEu,
                format: "'%s': input parameter '%s' missing semantics",
                a2,
                *(const char **)(*((_DWORD *)v81 + 5) + 24));
            }
          }
          goto LABEL_80;
        }
        v98 = D3DXShader::CCompiler::Vectorize(
                this,
                a2: *(struct D3DXShader::CNode ***)(v26 + 32),
                a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v26 + 16)),
                a4: v90,
                a5: 1,
                a6: 0,
                a7: nullptr,
                a8: *(struct D3DXShader::CNode **)(v26 + 48));
        if ( v98 < 0 )
          goto LABEL_137;
        v35 = D3DXShader::CCompiler::VectorizeDefaults(this, a2: (struct D3DXShader::CNode *)v26);
        goto LABEL_79;
      }
      v29 = v27[32];
    }
    v90 = v29;
    goto LABEL_53;
  }
LABEL_81:
  if ( a6 != 0 )
  {
    v38 = 0;
    if ( v97 != nullptr )
    {
      while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**((_DWORD **)this + 2) + 4))(
                a1: *((_DWORD *)this + 2),
                a2: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                          + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v93 + v38))),
                a3: 1) >= 0 )
      {
        if ( ++v38 >= (unsigned int)v97 )
          goto LABEL_85;
      }
LABEL_114:
      v98 = -2147467259;
      goto LABEL_137;
    }
LABEL_85:
    D3DXShader::HeapSort(
      this: (D3DXShader *)D3DXShader::CCompiler::CompareSemantic,
      a2: v93,
      a3: v97,
      a4: (unsigned int)this,
      a5: v71);
    v106 = nullptr;
    if ( v97 != nullptr )
    {
      v39 = *((_DWORD *)this + 6);
      v40 = *(_DWORD *)(*((_DWORD *)this + 2) + 20);
      v82 = *(struct D3DXShader::CNode **)(v40 + 4 * *(_DWORD *)(v39 + 4 * *(_DWORD *)v93));
      v87 = 1;
      if ( (unsigned int)v97 > 1 )
      {
        do
        {
          v41 = *(_DWORD **)(v40 + 4 * *(_DWORD *)(v39 + 4 * *((_DWORD *)v93 + v87)));
          if ( *((_DWORD *)v82 + 27) == v41[27] && *((_DWORD *)v82 + 4) == v41[4] && *(_DWORD *)v82 == *v41 )
            v106 = (struct D3DXShader::CNode *)((char *)v106 + 1);
          else
            v82 = *(struct D3DXShader::CNode **)(v40 + 4 * *(_DWORD *)(v39 + 4 * *((_DWORD *)v93 + v87)));
          ++v87;
        }
        while ( v87 < (unsigned int)v97 );
        if ( v106 != nullptr )
        {
          v78 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * (_DWORD)v106);
          if ( v78 == nullptr )
            goto LABEL_182;
          v42 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * (_DWORD)v106);
          v84 = v42;
          if ( v42 == nullptr )
            goto LABEL_182;
          v43 = *(_DWORD *)v93;
          v88 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                          + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)v93));
          v77 = (struct D3DXShader::CNode *)v42;
          v44 = 0;
          v107 = nullptr;
          for ( k = 1; k < (unsigned int)v97; ++k )
          {
            v92 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v93 + k));
            v45 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v92);
            if ( *(_DWORD *)(v88 + 108) == *(_DWORD *)(v45 + 108) && *(_DWORD *)(v88 + 16) == *(_DWORD *)(v45 + 16) )
            {
              *(_DWORD *)((char *)v77 + (char *)v78 - (char *)v84) = v92;
              *(_DWORD *)v77 = *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v43);
              v44 = (unsigned int)v107 + 1;
              v107 = (struct D3DXShader::CNode *)((char *)v107 + 1);
              v77 = (struct D3DXShader::CNode *)((char *)v77 + 4);
            }
            else
            {
              v43 = *((_DWORD *)v93 + k);
              v88 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20) + 4 * v92);
            }
          }
          v98 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  a2: a3,
                  a3: v44 & 0xFFFFF | 0x10000000,
                  a4: v78,
                  a5: v84,
                  a6: 0);
          if ( v98 < 0 )
            goto LABEL_137;
        }
      }
    }
  }
  v46 = *(_DWORD *)(*((_DWORD *)this + 1) + 24);
  if ( a6 != 0 )
  {
    v47 = 4 * v46;
    v48 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v46);
    pMem = v48;
    if ( v48 == nullptr )
    {
LABEL_182:
      v98 = -2147024882;
      goto LABEL_137;
    }
    qmemcpy(v48, *((const void **)this + 6), v47);
    v7 = a3;
  }
  v49 = *((_DWORD *)this + 20);
  *((_DWORD *)this + 20) = 0;
  v70 = *((_DWORD *)v7 + 10);
  *((_DWORD *)v7 + 14) = 1;
  v98 = D3DXShader::CCompiler::EmitStatement(this, a2: v70, a3: pMem);
  v50 = 0;
  v51 = *((_DWORD *)this + 20) != 0 || *((_DWORD *)this + 21) != 0;
  *((_DWORD *)this + 20) = v49;
  *((_DWORD *)v7 + 14) = 0;
  if ( v98 < 0 )
    goto LABEL_137;
  if ( !v51 && *((_DWORD *)v7 + 5) != 0 )
  {
    D3DXShader::CCompiler::Error(this, a2: v7, a3: 0xDB3u, format: "'%s': function must return a value", a2);
    goto LABEL_114;
  }
  if ( a6 != 0 )
  {
    if ( *((_DWORD *)v7 + 5) != 0 )
    {
      if ( *((_DWORD *)this + 21) != 0 )
      {
        do
        {
          v52 = v50 + *((_DWORD *)v7 + 4);
          ++v50;
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * v52) = *((_DWORD *)this + 9);
        }
        while ( v50 < *((_DWORD *)v7 + 5) );
      }
      v53 = 0;
      v68 = (unsigned int *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v7 + 4));
      v98 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2: v7,
              a3: *((_DWORD *)v7 + 5) & 0xFFFFF | 0x10000000,
              a4: v68,
              a5: v68,
              a6: 0);
      if ( v98 < 0 )
        goto LABEL_137;
      v98 = D3DXShader::CCompiler::ApplyType(
              this,
              a2: *((struct D3DXShader::CNode ***)v7 + 8),
              a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v7 + 4)),
              a4: *((_DWORD *)v7 + 5));
      if ( v98 < 0 )
        goto LABEL_137;
      v98 = D3DXShader::CCompiler::Vectorize(
              this,
              a2: *((struct D3DXShader::CNode ***)v7 + 8),
              a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v7 + 4)),
              a4: *(_DWORD *)(*((_DWORD *)this + 2) + 132),
              a5: 0,
              a6: 1,
              a7: *((struct D3DXShader::CNode **)v7 + 12),
              a8: nullptr);
      if ( v98 < 0 )
        goto LABEL_137;
      if ( D3DXShader::CCompiler::IsFullySemantic(
             this,
             a2: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)v7 + 4)),
             a3: *((_DWORD *)v7 + 5)) != 0 )
      {
        if ( *((_DWORD *)v7 + 5) != 0 )
        {
          while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**((_DWORD **)this + 2) + 4))(
                    a1: *((_DWORD *)this + 2),
                    a2: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                              + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (v53 + *((_DWORD *)v7 + 4)))),
                    a3: 1) >= 0 )
          {
            if ( (unsigned int)++v53 >= *((_DWORD *)v7 + 5) )
              goto LABEL_135;
          }
          *((_DWORD *)this + 19) = 1;
        }
      }
      else
      {
        D3DXShader::CCompiler::Error(
          this,
          a2: v7,
          a3: 0xDAFu,
          format: "'%s': function return value missing semantics",
          a2);
      }
    }
  }
  else if ( a5 != nullptr )
  {
    if ( *((_DWORD *)this + 21) != 0 )
    {
      if ( *((_DWORD *)v7 + 5) != 0 )
      {
        do
          a5[v50++] = *((_DWORD *)this + 9);
        while ( v50 < *((_DWORD *)v7 + 5) );
      }
    }
    else
    {
      qmemcpy(a5, (const void *)(*((_DWORD *)this + 6) + 4 * *((_DWORD *)a3 + 4)), 4 * *((_DWORD *)a3 + 5));
      v7 = a3;
    }
  }
LABEL_135:
  v54 = *((_DWORD *)v7 + 9);
  v108 = v72;
  v96 = v85;
  if ( v54 == 0 )
  {
LABEL_136:
    v98 = 0;
    goto LABEL_137;
  }
  while ( 1 )
  {
    v55 = *(_DWORD *)(v54 + 8);
    v56 = *(_DWORD *)(v54 + 12);
    v73 = v55;
    v89 = v56;
    if ( v56 != 0 )
    {
      v57 = *(_DWORD *)(v56 + 8);
      if ( v57 != 0 && *(_DWORD *)(v57 + 4) == 12 )
        v89 = *(_DWORD *)(v56 + 12);
    }
    v58 = *(_DWORD *)(v55 + 24);
    if ( (*(_BYTE *)(v58 + 28) & 0x20) == 0 )
      goto LABEL_170;
    v59 = *(_DWORD *)(v55 + 20) + 16;
    if ( *((_DWORD *)this + 21) == 0 )
      break;
    for ( m = nullptr;
          (unsigned int)m < *(_DWORD *)(v58 + 20);
          *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (_DWORD)v60) = *((_DWORD *)this + 9) )
    {
      v60 = (char *)m + *(_DWORD *)(v58 + 16);
      m = (struct D3DXShader::CNode *)((char *)m + 1);
    }
LABEL_156:
    if ( a6 != 0 )
    {
      v69 = (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v58 + 16));
      v98 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              a2: (struct D3DXShader::CNode *)v58,
              a3: *(_DWORD *)(v58 + 20) & 0xFFFFF | 0x10000000,
              a4: v69,
              a5: v69,
              a6: 0);
      if ( v98 < 0 )
        goto LABEL_137;
      v98 = D3DXShader::CCompiler::ApplyType(
              this,
              a2: *(struct D3DXShader::CNode ***)(v58 + 32),
              a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v58 + 16)),
              a4: *(_DWORD *)(v58 + 20));
      if ( v98 < 0 )
        goto LABEL_137;
      v98 = D3DXShader::CCompiler::Vectorize(
              this,
              a2: *(struct D3DXShader::CNode ***)(v58 + 32),
              a3: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v58 + 16)),
              a4: *(_DWORD *)(*((_DWORD *)this + 2) + 132),
              a5: 0,
              a6: 1,
              a7: *(struct D3DXShader::CNode **)(v58 + 44),
              a8: nullptr);
      if ( v98 < 0 )
        goto LABEL_137;
      if ( D3DXShader::CCompiler::IsFullySemantic(
             this,
             a2: (unsigned int *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v58 + 16)),
             a3: *(_DWORD *)(v58 + 20)) != 0 )
      {
        v63 = 0;
        if ( *(_DWORD *)(v58 + 20) != 0 )
        {
          while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**((_DWORD **)this + 2) + 4))(
                    a1: *((_DWORD *)this + 2),
                    a2: *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 2) + 20)
                              + 4 * *(_DWORD *)(*((_DWORD *)this + 6) + 4 * (v63 + *(_DWORD *)(v58 + 16)))),
                    a3: 1) >= 0 )
          {
            if ( (unsigned int)++v63 >= *(_DWORD *)(v58 + 20) )
              goto LABEL_170;
          }
          *((_DWORD *)this + 19) = 1;
        }
      }
      else
      {
        D3DXShader::CCompiler::Error(
          this,
          a2: (struct D3DXShader::CNode *)v58,
          a3: 0xDAFu,
          format: "'%s': output parameter '%s' missing semantics",
          a2,
          *(const char **)(v59 + 8));
      }
    }
    else
    {
      if ( v108 == nullptr )
        goto LABEL_179;
      v64 = *((struct D3DXShader::CNode **)v108 + 2);
      if ( v64 == nullptr )
      {
LABEL_177:
        if ( v108 != nullptr )
          v108 = *((struct D3DXShader::CNode **)v108 + 3);
        goto LABEL_179;
      }
      v98 = D3DXShader::CCompiler::EmitExpression(this, a2: v64, a3: nullptr, a4: nullptr);
      if ( v98 < 0 )
        goto LABEL_137;
    }
LABEL_170:
    if ( a6 == 0 || a7 != 0 && (*(_BYTE *)(v58 + 28) & 0x40) != 0 )
      goto LABEL_177;
    if ( (*(_BYTE *)(v58 + 28) & 0x40) != 0 )
    {
      v65 = *(const char **)(*(_DWORD *)(v73 + 20) + 24);
      v110 = (unsigned int *)v65;
      if ( *v65 != 36 )
      {
        v66 = strlen(v65);
        v67 = (char *)D3DXCore::CAlloc::Alloc(this: *(D3DXCore::CAlloc **)this, a2: v66 + 2, a3: 1u);
        v102 = (struct D3DXShader::CNode *)v67;
        if ( v67 == nullptr )
          goto LABEL_182;
        _snprintf(string: v67, count: v66 + 2, format: "$%s", (const char *)v110);
        *(_DWORD *)(*(_DWORD *)(v73 + 20) + 24) = v102;
      }
    }
LABEL_179:
    v96 += *(_DWORD *)(v58 + 20);
    if ( v89 == 0 )
      goto LABEL_136;
    v54 = v89;
  }
  v109 = nullptr;
  if ( *(_DWORD *)(v58 + 20) == 0 )
    goto LABEL_156;
  v61 = *((_DWORD **)this + 2);
  v101 = (struct D3DXShader::CNode *)(*((_DWORD *)this + 6) + 4 * *(_DWORD *)(v58 + 16));
  while ( 1 )
  {
    v62 = *(_DWORD *)v101 >= v61[2] ? 0 : *(_DWORD *)(v61[5] + 4 * *(_DWORD *)v101);
    if ( v62 != 0 && v61[29] == *(_DWORD *)(v62 + 4) )
      break;
    v109 = (unsigned int *)((char *)v109 + 1);
    v101 = (struct D3DXShader::CNode *)((char *)v101 + 4);
    if ( (unsigned int)v109 >= *(_DWORD *)(v58 + 20) )
      goto LABEL_156;
  }
  D3DXShader::CCompiler::Error(
    this,
    a2: *(struct D3DXShader::CNode **)(v62 + 96),
    a3: 0xDB4u,
    format: "'%s': output parameter '%s' never assigned a value",
    a2,
    *(const char **)(v59 + 8));
LABEL_137:
  free(pMem);
  free(pMem: v85);
  free(pMem: v93);
  free(pMem: v78);
  free(pMem: v84);
  return v98;
}

//------------------------------------------------------------------------------
// Address: 0x101D812F
// Name: protected: long D3DXShader::CCompiler::EmitProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitProgram(D3DXShader::CCompiler *this)
{
  struct D3DXShader::CNode *v2; // ebx
  D3DXShader::CProgram *v3; // ecx
  int result; // eax
  void *v5; // edi
  unsigned int v6; // eax
  unsigned int *v7; // ecx
  unsigned int v8; // eax
  unsigned int *v9; // ecx
  unsigned int v10; // eax

  v2 = *((struct D3DXShader::CNode **)this + 1);
  if ( v2 == nullptr || *((_DWORD *)v2 + 1) != 4 )
    return 0;
  v3 = *((D3DXShader::CProgram **)this + 2);
  if ( v3 == nullptr )
    return -2147467259;
  result = D3DXShader::CProgram::Initialize(
             this: v3,
             a2: v2,
             a3: (struct D3DXShader::CTErrors *)(*(_DWORD *)this + 24),
             a4: *((_DWORD *)this + 4),
             a5: *((_DWORD *)this + 5));
  if ( result >= 0 )
  {
    free(pMem: *((void **)this + 6));
    v5 = MemAlloc_Alloc(nSize: 4 * *((_DWORD *)v2 + 6));
    *((_DWORD *)this + 6) = v5;
    if ( v5 != nullptr )
    {
      memset(v5, 0xFFu, 4 * *((_DWORD *)v2 + 6));
      v6 = D3DXShader::CBaseProgram::AddArgument(
             this: *((D3DXShader::CBaseProgram **)this + 2),
             a2: *(_DWORD *)(*((_DWORD *)this + 2) + 120),
             a3: 0,
             a4: 0,
             a5: 1.0);
      v7 = *((unsigned int **)this + 2);
      *((_DWORD *)this + 8) = v6;
      v8 = D3DXShader::CBaseProgram::AddArgument(
             this: (D3DXShader::CBaseProgram *)v7,
             a2: v7[30],
             a3: 0,
             a4: 0,
             a5: 0.0);
      v9 = *((unsigned int **)this + 2);
      *((_DWORD *)this + 9) = v8;
      v10 = D3DXShader::CBaseProgram::AddArgument(
              this: (D3DXShader::CBaseProgram *)v9,
              a2: v9[30],
              a3: 0,
              a4: 0,
              a5: -1.0);
      *((_DWORD *)this + 12) = -1;
      *((_DWORD *)this + 10) = v10;
      *((_DWORD *)this + 11) = *((_DWORD *)this + 8);
      *((_DWORD *)this + 13) = 1;
      result = D3DXShader::CCompiler::EmitStatement(this, a2: *((_DWORD *)v2 + 7), a3: nullptr);
      if ( result >= 0 )
        return *((_DWORD *)this + 19) != 0 ? 0x80004005 : 0;
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8235
// Name: protected: long D3DXShader::CCompiler::EmitExpression(class D3DXShader::CNode __near *,unsigned int __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitExpression(void **this, __int64 a2, unsigned int i4)
{
  int v3; // esi
  struct D3DXShader::CNode *v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  unsigned int i; // eax
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // edx
  int v19; // ecx
  unsigned int *v20; // esi
  unsigned int *v21; // edi
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int *v29; // eax
  unsigned int j; // ecx
  unsigned int k; // ecx
  unsigned int *v32; // esi
  unsigned int *v33; // eax
  unsigned int m; // ecx
  int v35; // eax
  unsigned int v36; // eax
  int v37; // eax
  struct D3DXShader::CNode *v38; // eax
  int v39; // eax
  unsigned int *v40; // eax
  unsigned int v41; // ecx
  unsigned int *v42; // edx
  unsigned int *v43; // eax
  unsigned int v44; // ecx
  unsigned int *v45; // edx
  int v46; // eax
  int v47; // eax
  unsigned int *v48; // ecx
  int v49; // eax
  unsigned int *v50; // eax
  unsigned int jj; // ecx
  unsigned int *v52; // eax
  unsigned int kk; // ecx
  int v54; // eax
  struct D3DXShader::CNode *v55; // eax
  unsigned int *v56; // eax
  unsigned int n; // ecx
  unsigned int ii; // edx
  int v59; // edx
  _DWORD *v60; // esi
  int v61; // eax
  unsigned int v62; // ecx
  _DWORD *mm; // eax
  unsigned int *v64; // eax
  unsigned int v65; // edx
  unsigned int v66; // ecx
  unsigned int *v67; // esi
  char *v68; // eax
  unsigned int v69; // eax
  struct D3DXShader::CNode *Function; // eax
  unsigned int v71; // eax
  _BYTE *v72; // edx
  unsigned int v73; // ecx
  _DWORD *v74; // eax
  int v75; // ecx
  int v76; // eax
  int v77; // esi
  int v78; // esi
  unsigned int *v79; // eax
  unsigned int i1; // ecx
  int *v81; // eax
  unsigned int *v82; // edx
  unsigned int v83; // ecx
  int v84; // ecx
  _DWORD *v85; // eax
  unsigned int *v86; // ecx
  unsigned int i2; // edx
  struct D3DXShader::CNode *v88; // esi
  unsigned int *v89; // eax
  unsigned int i3; // ecx
  int *v91; // eax
  unsigned int *v92; // edx
  unsigned int v93; // ecx
  int v94; // ecx
  unsigned int i5; // edx
  int v96; // edx
  unsigned int *v97; // ecx
  int v98; // eax
  int *v99; // esi
  int v100; // eax
  int v101; // eax
  double v102; // st7
  double v104; // st7
  char v105; // c0
  double v107; // st7
  char v108; // c0
  double v109; // st7
  double *v110; // edx
  double v111; // st7
  int v112; // ecx
  unsigned int v113; // ecx
  int v114; // eax
  unsigned int *v115; // esi
  unsigned int *v116; // ecx
  unsigned int v117; // eax
  unsigned int v118; // edi
  unsigned int v119; // edx
  bool v120; // zf
  unsigned int *v121; // [esp-4h] [ebp-7Ch]
  __int64 x; // [esp+0h] [ebp-78h]
  __int64 xa; // [esp+0h] [ebp-78h]
  __int64 xb; // [esp+0h] [ebp-78h]
  unsigned int *v125; // [esp+14h] [ebp-64h]
  unsigned int *v126; // [esp+18h] [ebp-60h]
  unsigned int *v127; // [esp+1Ch] [ebp-5Ch]
  unsigned int *v128; // [esp+20h] [ebp-58h]
  unsigned int *v129; // [esp+24h] [ebp-54h]
  unsigned int *v130; // [esp+28h] [ebp-50h]
  unsigned int *v131; // [esp+2Ch] [ebp-4Ch]
  unsigned int *v132[2]; // [esp+30h] [ebp-48h] BYREF
  unsigned int *v133[2]; // [esp+38h] [ebp-40h]
  unsigned int *v134; // [esp+40h] [ebp-38h]
  unsigned int *v135; // [esp+44h] [ebp-34h]
  unsigned int *v136; // [esp+48h] [ebp-30h]
  unsigned int *v137; // [esp+4Ch] [ebp-2Ch]
  unsigned int *v138; // [esp+50h] [ebp-28h]
  unsigned int *v139; // [esp+54h] [ebp-24h]
  unsigned int nn; // [esp+58h] [ebp-20h]
  char *v141; // [esp+5Ch] [ebp-1Ch]
  unsigned int v142; // [esp+60h] [ebp-18h]
  struct D3DXShader::CNode *v143; // [esp+64h] [ebp-14h]
  struct D3DXShader::CNode *v144; // [esp+68h] [ebp-10h]
  unsigned int v145; // [esp+6Ch] [ebp-Ch]
  unsigned int *v146; // [esp+70h] [ebp-8h]
  unsigned int *v147; // [esp+74h] [ebp-4h]
  double *v148; // [esp+80h] [ebp+8h]
  unsigned int v149; // [esp+84h] [ebp+Ch]

  v3 = a2;
  if ( (_DWORD)a2 == 0 )
  {
    if ( HIDWORD(a2) == 0 )
      return 0;
  }
  else if ( *(_DWORD *)(a2 + 4) == 13 )
  {
    v6 = *(struct D3DXShader::CNode **)(a2 + 32);
    v7 = *(_DWORD *)(a2 + 24) * *(_DWORD *)(a2 + 20);
    v8 = 0;
    v145 = v7;
    v142 = 0;
    nn = 0;
    v147 = nullptr;
    v146 = nullptr;
    v144 = nullptr;
    v143 = nullptr;
    if ( v6 != nullptr && *((_DWORD *)v6 + 1) == 13 )
    {
      v8 = *((_DWORD *)v6 + 5) * *((_DWORD *)v6 + 6);
      v144 = v6;
      v142 = v8;
    }
    v9 = *(_DWORD **)(a2 + 36);
    if ( v9 != nullptr && v9[1] == 13 )
    {
      v10 = v9[5] * v9[6];
      v143 = *(struct D3DXShader::CNode **)(a2 + 36);
      nn = v10;
    }
    if ( v144 != nullptr )
    {
      v147 = D3DXShader::CCompiler::StackAlloc((D3DXShader::CCompiler *)this, a2: v8);
      if ( v147 == nullptr )
        goto LABEL_328;
    }
    if ( v143 != nullptr )
    {
      v146 = D3DXShader::CCompiler::StackAlloc((D3DXShader::CCompiler *)this, a2: nn);
      if ( v146 == nullptr )
        goto LABEL_328;
    }
    v11 = *(_DWORD *)(a2 + 28);
    v141 = nullptr;
    if ( v11 >= 0 )
    {
      if ( v11 <= 3 )
      {
LABEL_20:
        v141 = (char *)i4;
        goto LABEL_21;
      }
      if ( v11 <= 19 )
        goto LABEL_21;
      if ( v11 > 21 )
      {
        if ( v11 > 23 )
          goto LABEL_21;
        goto LABEL_20;
      }
      v141 = (char *)1;
    }
LABEL_21:
    if ( *(_DWORD *)(a2 + 40) != 0 )
    {
      if ( v144 != nullptr )
      {
        v12 = D3DXShader::CCompiler::EmitExpression((D3DXShader::CCompiler *)this, a2: v144, a3: v147, a4: v141);
        if ( v12 < 0 )
          goto LABEL_385;
        v3 = a2;
      }
      if ( v143 == nullptr )
        goto LABEL_35;
      v13 = D3DXShader::CCompiler::EmitExpression((D3DXShader::CCompiler *)this, a2: v143, a3: v146, a4: nullptr);
    }
    else
    {
      if ( v143 != nullptr )
      {
        v12 = D3DXShader::CCompiler::EmitExpression((D3DXShader::CCompiler *)this, a2: v143, a3: v146, a4: nullptr);
        if ( v12 < 0 )
          goto LABEL_385;
        v3 = a2;
      }
      if ( v144 == nullptr )
        goto LABEL_35;
      v13 = D3DXShader::CCompiler::EmitExpression((D3DXShader::CCompiler *)this, a2: v144, a3: v147, a4: v141);
    }
    v12 = v13;
    if ( v13 < 0 )
      goto LABEL_385;
    v3 = a2;
LABEL_35:
    switch ( *(_DWORD *)(v3 + 28) )
    {
      case 0:
      case 1:
        if ( v144 == nullptr )
        {
          v22 = D3DXShader::CCompiler::EmitArgs(
                  (D3DXShader::CCompiler *)this,
                  a2: *(struct D3DXShader::CNode **)(a2 + 32),
                  a3: (unsigned int *)HIDWORD(a2),
                  a4: v7);
          goto LABEL_100;
        }
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        if ( v142 == 1 )
        {
          for ( i = 0; i < v7; ++i )
            *(_DWORD *)(HIDWORD(a2) + 4 * i) = *v147;
          goto LABEL_41;
        }
        if ( v7 == v142 )
          goto LABEL_86;
        v17 = *(_DWORD *)(a2 + 20);
        if ( v17 == 1 && v7 < v142 )
          goto LABEL_86;
        if ( v17 > *((_DWORD *)v144 + 5) || *(_DWORD *)(a2 + 24) > *((_DWORD *)v144 + 6) )
          goto LABEL_384;
        v18 = 0;
        if ( v17 == 0 )
          goto LABEL_41;
        do
        {
          v19 = *(_DWORD *)(a2 + 24);
          v20 = &v147[v18 * *((_DWORD *)v144 + 6)];
          v21 = (unsigned int *)(HIDWORD(a2) + 4 * v18 * v19);
          ++v18;
          qmemcpy(v21, v20, 4 * v19);
        }
        while ( v18 < *(_DWORD *)(a2 + 20) );
        goto LABEL_248;
      case 2:
        if ( v144 == nullptr )
          goto LABEL_384;
        v29 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: v7);
        if ( v29 == nullptr )
          goto LABEL_328;
        for ( j = 0; j < v7; ++j )
          v29[j] = (unsigned int)*(this + 8);
        goto LABEL_83;
      case 3:
        if ( v144 == nullptr )
          goto LABEL_384;
        v29 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: v7);
        if ( v29 == nullptr )
          goto LABEL_328;
        for ( k = 0; k < v7; ++k )
          v29[k] = (unsigned int)*(this + 10);
LABEL_83:
        v27 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: v7 & 0xFFFFF | 0x20400000,
                a4: v147,
                a5: v147,
                a6: (unsigned int)v29);
        goto LABEL_84;
      case 4:
        if ( v144 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v33 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 2 * v7);
        if ( v33 == nullptr )
          goto LABEL_328;
        for ( m = 0; m < 2; ++m )
        {
          (&v138)[m] = v33;
          v33 += v7;
        }
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v138, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v139, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitPositive(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v138,
                a4: v139,
                a5: v147,
                a6: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = (unsigned int)v138 | 0x1700000000LL;
        v121 = v139;
        goto LABEL_97;
      case 5:
        if ( v144 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v22 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | v7 & 0xFFFFF,
                a4: (unsigned int *)HIDWORD(a2),
                a5: v147,
                a6: 0);
        goto LABEL_100;
      case 6:
        if ( v144 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = 0;
        v121 = v147;
        goto LABEL_273;
      case 7:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        HIDWORD(xb) = 0;
        goto LABEL_210;
      case 8:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v55 = (struct D3DXShader::CNode *)D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: v7);
        v143 = v55;
        if ( v55 == nullptr )
          goto LABEL_328;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)v55, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&unk_10300000 | v7 & 0xFFFFF,
                a4: (unsigned int *)v143,
                a5: v146,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v54 = i4;
        xb = (unsigned int)v143;
        goto LABEL_211;
      case 9:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v56 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 8 * v7);
        if ( v56 == nullptr )
          goto LABEL_328;
        for ( n = 0; n < 8; ++n )
        {
          (&v128)[n] = v56;
          v56 += v7;
        }
        for ( ii = 0; ii < 8; ii = v59 + 1 )
        {
          v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (&v128)[ii], a3: v7);
          if ( v12 < 0 )
            goto LABEL_385;
        }
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v143 = (struct D3DXShader::CNode *)(v7 & 0xFFFFF | 0x20500000);
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)v143,
                a4: v128,
                a5: v147,
                a6: (unsigned int)v146);
        if ( v12 < 0 )
          goto LABEL_385;
        v139 = (unsigned int *)((unsigned int)&loc_10100000 | i4);
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | i4,
                a4: v129,
                a5: v128,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: i4 | 0x20300000,
                a4: v130,
                a5: v128,
                a6: (unsigned int)v129 | 0x1700000000LL);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)v139,
                a4: v131,
                a5: v146,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitLerp(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v132[0],
                a4: v131,
                a5: v146,
                a6: v130,
                a7: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&unk_10300000 | i4,
                a4: v132[1],
                a5: v132[0],
                a6: 0x4000000000LL);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)v143,
                a4: v133[0],
                a5: v147,
                a6: (unsigned int)v132[1]);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: i4 | 0x10400000,
                a4: v133[1],
                a5: v133[0],
                a6: 0x400000000LL);
        if ( v12 < 0 )
          goto LABEL_385;
        v22 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)v143,
                a4: (unsigned int *)HIDWORD(a2),
                a5: v132[0],
                a6: (unsigned int)v133[1]);
        goto LABEL_100;
      case 0xA:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        xa = (unsigned int)v146;
        v37 = v7 & 0xFFFFF;
        goto LABEL_115;
      case 0xB:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v38 = (struct D3DXShader::CNode *)D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: v7);
        v143 = v38;
        if ( v38 == nullptr )
          goto LABEL_328;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)v38, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | v7 & 0xFFFFF,
                a4: (unsigned int *)v143,
                a5: v146,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v37 = i4;
        xa = (unsigned int)v143;
LABEL_115:
        v22 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: v37 | 0x20400000,
                a4: (unsigned int *)HIDWORD(a2),
                a5: v147,
                a6: xa);
        goto LABEL_100;
      case 0xC:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = (unsigned int)v146 | 0x1700000000LL;
        v121 = v147;
        goto LABEL_134;
      case 0xD:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = (unsigned int)v147 | 0x1700000000LL;
        v121 = v146;
LABEL_134:
        v39 = v7 & 0xFFFFF;
        goto LABEL_135;
      case 0xE:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = (unsigned int)v147 | 0x1700000000LL;
        v121 = v146;
        goto LABEL_97;
      case 0xF:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        x = (unsigned int)v146 | 0x1700000000LL;
        v121 = v147;
LABEL_97:
        v35 = v7 & 0xFFFFF;
        goto LABEL_98;
      case 0x10:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v40 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 4 * v7);
        if ( v40 == nullptr )
          goto LABEL_328;
        v41 = 0;
        v42 = v40;
        do
        {
          (&v134)[v41++] = v42;
          v42 += v7;
        }
        while ( v41 < 4 );
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v40, a3: 4 * v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | v7 & 0xFFFFF,
                a4: v134,
                a5: v146,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: i4 | 0x20400000,
                a4: v135,
                a5: v147,
                a6: (unsigned int)v134);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitPositive(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v136,
                a4: v137,
                a5: v135,
                a6: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v35 = i4;
        x = (unsigned int)v136 | 0x1700000000LL;
        v121 = v137;
LABEL_98:
        v36 = v35 | 0x20300000;
        goto LABEL_99;
      case 0x11:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v43 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 4 * v7);
        if ( v43 == nullptr )
          goto LABEL_328;
        v44 = 0;
        v45 = v43;
        do
        {
          (&v134)[v44++] = v45;
          v45 += v7;
        }
        while ( v44 < 4 );
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v43, a3: 4 * v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | v7 & 0xFFFFF,
                a4: v134,
                a5: v146,
                a6: 0);
        if ( v12 < 0 )
          goto LABEL_385;
        v46 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: i4 | 0x20400000,
                a4: v135,
                a5: v147,
                a6: (unsigned int)v134);
        goto LABEL_168;
      case 0x12:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        i4 = 0;
        if ( v7 == 0 )
          goto LABEL_178;
        v48 = v146;
        v49 = *((_DWORD *)*(this + 2) + 5);
        while ( (**(_BYTE **)(v49 + 4 * *(unsigned int *)((char *)v48 + (char *)v147 - (char *)v146)) & 1) != 0
             && (**(_BYTE **)(v49 + 4 * *v48) & 1) != 0 )
        {
          ++i4;
          ++v48;
          if ( i4 >= v7 )
          {
LABEL_178:
            v12 = D3DXShader::CCompiler::EmitTemp(
                    (D3DXShader::CCompiler *)this,
                    a2: (unsigned int *)HIDWORD(a2),
                    a3: v7);
            if ( v12 < 0 )
              goto LABEL_385;
            HIDWORD(xb) = 23;
LABEL_210:
            LODWORD(xb) = v146;
            v54 = v7 & 0xFFFFF;
LABEL_211:
            v22 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    (struct D3DXShader::CNode *)a2,
                    a3: v54 | 0x20500000,
                    a4: (unsigned int *)HIDWORD(a2),
                    a5: v147,
                    a6: xb);
            goto LABEL_100;
          }
        }
        v50 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 3 * v7);
        if ( v50 == nullptr )
          goto LABEL_328;
        for ( jj = 0; jj < 3; ++jj )
        {
          (&v135)[jj] = v50;
          v50 += v7;
        }
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v135, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v136, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v137, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v46 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: v7 & 0xFFFFF | 0x20500000,
                a4: v135,
                a5: v147,
                a6: (unsigned int)v146);
LABEL_168:
        v12 = v46;
        if ( v46 < 0 )
          goto LABEL_385;
        v47 = D3DXShader::CCompiler::EmitPositive(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v136,
                a4: v137,
                a5: v135,
                a6: v7);
LABEL_203:
        v12 = v47;
        if ( v47 < 0 )
          goto LABEL_385;
        v39 = i4;
        x = (unsigned int)v136 | 0x1700000000LL;
        v121 = v137;
LABEL_135:
        v36 = v39 | 0x20200000;
        goto LABEL_99;
      case 0x13:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v52 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 4 * v7);
        if ( v52 == nullptr )
          goto LABEL_328;
        for ( kk = 0; kk < 4; ++kk )
        {
          (&v134)[kk] = v52;
          v52 += v7;
        }
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v134, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v135, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v136, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v137, a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitPositive(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v134,
                a4: nullptr,
                a5: v147,
                a6: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        v12 = D3DXShader::CCompiler::EmitPositive(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: v135,
                a4: nullptr,
                a5: v146,
                a6: v7);
        if ( v12 < 0 )
          goto LABEL_385;
        i4 = v7 & 0xFFFFF;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: v7 & 0xFFFFF | 0x20400000,
                a4: v136,
                a5: v134,
                a6: (unsigned int)v135 | 0x400000000LL);
        if ( v12 < 0 )
          goto LABEL_385;
        v47 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | i4,
                a4: v137,
                a5: v136,
                a6: 0x800000000LL);
        goto LABEL_203;
      case 0x14:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( v7 == 0 )
          goto LABEL_41;
        v23 = *(this + 2);
        if ( *v147 >= v23[2] )
          v24 = 0;
        else
          v24 = *(_DWORD *)(v23[5] + 4 * *v147);
        if ( v24 == 0 || v23[29] != *(_DWORD *)(v24 + 4) )
          goto LABEL_85;
        v25 = 0;
        v26 = v23[5];
        while ( *(_DWORD *)(*(_DWORD *)(v26 + 4 * v147[v25]) + 48) != -1 )
        {
          if ( ++v25 >= v7 )
            goto LABEL_65;
        }
        goto LABEL_73;
      case 0x15:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( v7 == 0 )
          goto LABEL_41;
        v28 = 0;
        while ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)*(this + 2) + 5) + 4 * v147[v28]) + 48) != -1 )
        {
          if ( ++v28 >= v7 )
          {
LABEL_65:
            v27 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    (struct D3DXShader::CNode *)a2,
                    a3: v7 & 0xFFFFF | 0x10000000,
                    a4: v147,
                    a5: v146,
                    a6: 0);
LABEL_84:
            v12 = v27;
            if ( v27 < 0 )
              goto LABEL_385;
LABEL_85:
            if ( HIDWORD(a2) != 0 )
            {
LABEL_86:
              v32 = v147;
LABEL_247:
              qmemcpy((void *)HIDWORD(a2), v32, 4 * v145);
LABEL_248:
              v7 = v145;
              goto LABEL_41;
            }
            goto LABEL_382;
          }
        }
LABEL_73:
        D3DXShader::CCompiler::Error(
          (D3DXShader::CCompiler *)this,
          (struct D3DXShader::CNode *)a2,
          a3: 0,
          format: "internal error: l-value expected");
        goto LABEL_384;
      case 0x16:
        if ( v143 == nullptr )
          goto LABEL_384;
        v22 = D3DXShader::CCompiler::EmitArray(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: __SPAIR64__(v7, HIDWORD(a2)),
                a4: v147,
                a5: v142,
                a6: *((struct D3DXShader::CNode **)v144 + 4),
                a7: (unsigned int)v146,
                a8: i4);
        goto LABEL_100;
      case 0x17:
        if ( v144 == nullptr )
          goto LABEL_384;
        v60 = *(_DWORD **)(v3 + 36);
        if ( v60 == nullptr )
          goto LABEL_384;
        v61 = v60[1];
        if ( v61 == 14 )
        {
          if ( v60[4] != 2 )
            goto LABEL_384;
          if ( HIDWORD(a2) != 0 )
          {
            v32 = &v147[v60[6]];
            goto LABEL_247;
          }
        }
        else
        {
          if ( v61 != 1 )
            goto LABEL_384;
          if ( HIDWORD(a2) != 0 )
          {
            v62 = 0;
            for ( mm = v60; v62 < v7; ++v62 )
            {
              *(_DWORD *)(HIDWORD(a2) + 4 * v62) = v147[*(_DWORD *)(mm[2] + 24)];
              mm = (_DWORD *)mm[3];
            }
            goto LABEL_41;
          }
        }
        goto LABEL_382;
      case 0x18:
        if ( v144 == nullptr || v143 == nullptr )
          goto LABEL_384;
        if ( HIDWORD(a2) == 0 )
          goto LABEL_382;
        v64 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 3 * v7);
        if ( v64 == nullptr )
          goto LABEL_328;
        v65 = 0;
        v66 = v7;
        do
        {
          (&v135)[v65++] = v64;
          v64 = (unsigned int *)((char *)v64 + v66 * 4);
        }
        while ( v65 < 3 );
        v141 = nullptr;
        v67 = v135;
        if ( v7 == 0 )
          goto LABEL_270;
        v142 = (unsigned int)&v146[v66];
        i4 = (char *)v146 - (char *)v135;
        v139 = (unsigned int *)((char *)v147 - (char *)v146);
        break;
      case 0x19:
        Function = D3DXShader::CCompiler::FindFunction(
                     (D3DXShader::CCompiler *)this,
                     a2: *(struct D3DXShader::CNode **)(v3 + 32),
                     a3: (const char **)&i4);
        if ( Function == nullptr )
        {
          D3DXShader::CCompiler::Error(
            (D3DXShader::CCompiler *)this,
            a2: (struct D3DXShader::CNode *)v3,
            a3: 0xDB6u,
            format: "function '%s' missing implementation",
            *(const char **)(v3 + 56));
          goto LABEL_384;
        }
        *(this + 14) = (char *)*(this + 14) + 1;
        v22 = D3DXShader::CCompiler::EmitFunction(
                (D3DXShader::CCompiler *)this,
                a2: (char *)i4,
                a3: Function,
                a4: *(struct D3DXShader::CNode **)(a2 + 36),
                a5: (unsigned int *)HIDWORD(a2),
                a6: 0,
                a7: 0);
        *(this + 14) = (char *)*(this + 14) - 1;
        goto LABEL_100;
      case 0x1A:
        v22 = D3DXShader::CCompiler::EmitIntrinsic(
                (D3DXShader::CCompiler *)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int *)HIDWORD(a2));
        goto LABEL_100;
      default:
        D3DXShader::CCompiler::Error(
          (D3DXShader::CCompiler *)this,
          a2: nullptr,
          a3: 0,
          format: "internal error: unrecognized expression");
        goto LABEL_384;
    }
    while ( D3DXShader::CCompiler::EvalRange(
              (D3DXShader::CCompiler *)this,
              a2: *(unsigned int *)((char *)v139 + (_DWORD)v67 + i4),
              a3: (struct D3DXShader::_D3DXRANGE *)v132) >= 0 )
    {
      if ( *(double *)v132 > 0.0 || *(double *)v133 < 0.0 )
      {
        v68 = (char *)v67 + i4;
      }
      else
      {
        if ( *(double *)v132 != 0.0 || *(double *)v133 != 0.0 )
          break;
        v68 = (char *)v142;
      }
      v69 = *(_DWORD *)v68;
      ++v141;
      v142 += 4;
      *v67++ = v69;
      if ( (unsigned int)v141 >= v7 )
        break;
    }
LABEL_270:
    if ( v141 == (char *)v7 )
    {
      v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (unsigned int *)HIDWORD(a2), a3: v7);
      if ( v12 < 0 )
        goto LABEL_385;
      x = 0;
      v121 = v135;
LABEL_273:
      v36 = v7 & 0xFFFFF | 0x10000000;
LABEL_99:
      v22 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              (struct D3DXShader::CNode *)a2,
              a3: v36,
              a4: (unsigned int *)HIDWORD(a2),
              a5: v121,
              a6: x);
    }
    else
    {
      v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v135, a3: v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v136, a3: v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v137, a3: v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = D3DXShader::CCompiler::EmitPositive(
              (D3DXShader::CCompiler *)this,
              (struct D3DXShader::CNode *)a2,
              a3: v135,
              a4: v136,
              a5: v147,
              a6: v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              (struct D3DXShader::CNode *)a2,
              a3: v7 & 0xFFFFF | 0x20200000,
              a4: v137,
              a5: v136,
              a6: (unsigned int)v135 | 0x1700000000LL);
      if ( v12 < 0 )
        goto LABEL_385;
      v22 = D3DXShader::CCompiler::EmitLerp(
              (D3DXShader::CCompiler *)this,
              (struct D3DXShader::CNode *)a2,
              a3: (unsigned int *)HIDWORD(a2),
              a4: &v146[v7],
              a5: v146,
              a6: v137,
              a7: v7);
    }
LABEL_100:
    v12 = v22;
    if ( v22 < 0 )
      goto LABEL_385;
LABEL_41:
    if ( HIDWORD(a2) == 0 )
    {
LABEL_382:
      v12 = 0;
      goto LABEL_385;
    }
    v15 = (unsigned int)*(this + 39);
    if ( v7 <= v15 )
      goto LABEL_289;
    if ( v15 != 0 )
      v16 = 2 * v15;
    else
      v16 = 16;
    while ( v16 < v7 )
      v16 *= 2;
    i4 = (unsigned int)MemAlloc_Alloc(nSize: 8 * v16);
    if ( i4 == 0 )
    {
LABEL_328:
      D3DXShader::CCompiler::Error(
        (D3DXShader::CCompiler *)this,
        (struct D3DXShader::CNode *)a2,
        a3: 0,
        format: "internal error: out of memory");
      v12 = -2147024882;
      goto LABEL_385;
    }
    free(pMem: *(this + 38));
    *(this + 38) = (void *)i4;
    *(this + 39) = (void *)v16;
LABEL_289:
    v145 = (unsigned int)*(this + 38);
    v139 = (unsigned int *)(v145 + 4 * v7);
    D3DXShader::CCompiler::GetTypeFlags(
      (D3DXShader::CCompiler *)this,
      a2: *(struct D3DXShader::CNode ***)(a2 + 16),
      a3: v139);
    i4 = 0;
    v144 = nullptr;
    v142 = 0;
    if ( v7 == 0 )
      goto LABEL_372;
    v71 = HIDWORD(a2) - (_DWORD)v139;
    v141 = (char *)v139 - v145;
    v143 = (struct D3DXShader::CNode *)v145;
    for ( nn = HIDWORD(a2) - (_DWORD)v139; ; v71 = nn )
    {
      v72 = (char *)v143 + (_DWORD)v141;
      v73 = *(_DWORD *)((char *)v143 + (_DWORD)v141 + v71);
      v74 = *(this + 2);
      if ( v73 >= v74[2] )
        v75 = 0;
      else
        v75 = *(_DWORD *)(v74[5] + 4 * v73);
      if ( v75 == 0 )
      {
        D3DXShader::CCompiler::Error(
          (D3DXShader::CCompiler *)this,
          a2: nullptr,
          a3: 0,
          format: "internal error: result register invalid");
LABEL_384:
        v12 = -2147467259;
        goto LABEL_385;
      }
      v76 = v74[29];
      v77 = *(_DWORD *)(v75 + 4);
      if ( v76 == v77 )
        goto LABEL_304;
      if ( (*v72 & 1) != 0 && (*(_BYTE *)v75 & 1) == 0 )
      {
        ++i4;
        *(_DWORD *)v143 = 1;
        goto LABEL_305;
      }
      if ( v76 == v77 || (*v72 & 2) == 0 || (*(_BYTE *)v75 & 2) != 0 )
      {
LABEL_304:
        *(_DWORD *)v143 = 0;
      }
      else
      {
        v144 = (struct D3DXShader::CNode *)((char *)v144 + 1);
        *(_DWORD *)v143 = 2;
      }
LABEL_305:
      ++v142;
      v143 = (struct D3DXShader::CNode *)((char *)v143 + 4);
      if ( v142 >= v7 )
        break;
    }
    if ( i4 == 0 )
      goto LABEL_326;
    v78 = 4 * i4;
    v79 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 4 * i4);
    if ( v79 == nullptr )
      goto LABEL_328;
    for ( i1 = 0; i1 < 4; ++i1 )
    {
      (&v134)[i1] = v79;
      v79 = (unsigned int *)((char *)v79 + v78);
    }
    v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v135, a3: i4);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: v136, a3: i4);
    if ( v12 < 0 )
      goto LABEL_385;
    v81 = (int *)HIDWORD(a2);
    v82 = v137;
    v83 = v145 - HIDWORD(a2);
    v142 = v145 - HIDWORD(a2);
    v141 = (char *)((char *)v134 - (char *)v137);
    for ( nn = v7; nn != 0; --nn )
    {
      if ( *(int *)((char *)v81 + v83) == 1 )
      {
        *(unsigned int *)((char *)v82 + (_DWORD)v141) = *v81;
        if ( *(_DWORD *)(a2 + 28) != 0 )
          v84 = *v81;
        else
          v84 = -1;
        *v82 = v84;
        v83 = v142;
        ++v82;
      }
      ++v81;
    }
    v12 = D3DXShader::CCompiler::EmitPositive(
            (D3DXShader::CCompiler *)this,
            (struct D3DXShader::CNode *)a2,
            a3: v135,
            a4: v136,
            a5: v134,
            a6: i4);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = D3DXShader::CCompiler::EmitInst(
            (char **)this,
            (struct D3DXShader::CNode *)a2,
            a3: i4 & 0xFFFFF | 0x20200000,
            a4: v137,
            a5: v136,
            a6: (unsigned int)v135 | 0x1700000000LL);
    if ( v12 < 0 )
      goto LABEL_385;
    v85 = (_DWORD *)HIDWORD(a2);
    v86 = v137;
    for ( i2 = v7; i2 != 0; --i2 )
    {
      if ( *(_DWORD *)((char *)v85 + v142) == 1 )
        *v85 = *v86++;
      ++v85;
    }
LABEL_326:
    if ( v144 == nullptr )
    {
LABEL_372:
      if ( v7 == 0 )
        goto LABEL_382;
      v115 = v139;
      nn = HIDWORD(a2) - (_DWORD)v139;
      v149 = v7;
      while ( 1 )
      {
        v116 = *(unsigned int **)(*((_DWORD *)*(this + 2) + 5) + 4 * *(unsigned int *)((char *)v115 + nn));
        v117 = *v116 | *v115 & 0xF1FFFFFF;
        *v116 = v117;
        v118 = v117 & 0xE000000;
        v119 = *v115 & 0xE000000;
        if ( (v117 & 0xE000000) == 0 )
          v118 = *v115 & 0xE000000;
        if ( v116[23] != 0 )
        {
          if ( v118 > v119 )
LABEL_380:
            v119 = v118;
        }
        else if ( v118 < v119 )
        {
          goto LABEL_380;
        }
        ++v115;
        v120 = v149-- == 1;
        *v116 = v119 | v117 & 0xF1FFFFFF;
        if ( v120 )
          goto LABEL_382;
      }
    }
    v88 = v144;
    v89 = D3DXShader::CCompiler::Scratch((D3DXShader::CCompiler *)this, a2: 11 * (_DWORD)v144);
    if ( v89 == nullptr )
      goto LABEL_328;
    for ( i3 = 0; i3 < 0xB; ++i3 )
    {
      (&v125)[i3] = v89;
      v89 += (int)v88;
    }
    v91 = (int *)HIDWORD(a2);
    v92 = v133[1];
    v93 = v145 - HIDWORD(a2);
    v142 = v145 - HIDWORD(a2);
    v143 = (struct D3DXShader::CNode *)((char *)v125 - (char *)v133[1]);
    for ( i4 = v7; i4 != 0; --i4 )
    {
      if ( *(int *)((char *)v91 + v93) == 2 )
      {
        *(unsigned int *)((char *)v92 + (_DWORD)v143) = *v91;
        if ( *(_DWORD *)(a2 + 28) != 0 )
          v94 = *v91;
        else
          v94 = -1;
        *v92 = v94;
        v93 = v142;
        ++v92;
      }
      ++v91;
    }
    for ( i5 = 1; i5 < 0xA; i5 = v96 + 1 )
    {
      v12 = D3DXShader::CCompiler::EmitTemp((D3DXShader::CCompiler *)this, a2: (&v125)[i5], a3: (unsigned int)v144);
      if ( v12 < 0 )
        goto LABEL_385;
    }
    i4 = (unsigned int)v144 & 0xFFFFF;
    v12 = D3DXShader::CCompiler::EmitInst(
            (char **)this,
            (struct D3DXShader::CNode *)a2,
            a3: ((unsigned int)&loc_101FFFFF + 1) | (unsigned int)v144 & 0xFFFFF,
            a4: v126,
            a5: v125,
            a6: 0);
    if ( v12 >= 0 )
    {
      v12 = D3DXShader::CCompiler::EmitInst(
              (char **)this,
              (struct D3DXShader::CNode *)a2,
              a3: i4 | 0x10400000,
              a4: v127,
              a5: v126,
              a6: 0x1400000000LL);
      if ( v12 >= 0 )
      {
        nn = (unsigned int)&loc_10100000 | i4;
        v12 = D3DXShader::CCompiler::EmitInst(
                (char **)this,
                (struct D3DXShader::CNode *)a2,
                a3: (unsigned int)&loc_10100000 | i4,
                a4: v128,
                a5: v127,
                a6: 0x1800000000LL);
        if ( v12 >= 0 )
        {
          v144 = (struct D3DXShader::CNode *)(i4 | 0x20400000);
          v12 = D3DXShader::CCompiler::EmitInst(
                  (char **)this,
                  (struct D3DXShader::CNode *)a2,
                  a3: i4 | 0x20400000,
                  a4: v129,
                  a5: v128,
                  a6: (unsigned int)v126 | 0x200000000LL);
          if ( v12 >= 0 )
          {
            v12 = D3DXShader::CCompiler::EmitInst(
                    (char **)this,
                    (struct D3DXShader::CNode *)a2,
                    a3: nn,
                    a4: v130,
                    a5: v125,
                    a6: 0);
            if ( v12 >= 0 )
            {
              v141 = (char *)(i4 | 0x20200000);
              v12 = D3DXShader::CCompiler::EmitInst(
                      (char **)this,
                      (struct D3DXShader::CNode *)a2,
                      a3: i4 | 0x20200000,
                      a4: v131,
                      a5: v125,
                      a6: (unsigned int)v130 | 0x1700000000LL);
              if ( v12 >= 0 )
              {
                v12 = D3DXShader::CCompiler::EmitInst(
                        (char **)this,
                        (struct D3DXShader::CNode *)a2,
                        a3: nn,
                        a4: v132[0],
                        a5: v127,
                        a6: 0);
                if ( v12 >= 0 )
                {
                  v12 = D3DXShader::CCompiler::EmitInst(
                          (char **)this,
                          (struct D3DXShader::CNode *)a2,
                          a3: (unsigned int)v141,
                          a4: v132[1],
                          a5: v132[0],
                          a6: (unsigned int)v127 | 0x1700000000LL);
                  if ( v12 >= 0 )
                  {
                    v12 = D3DXShader::CCompiler::EmitInst(
                            (char **)this,
                            (struct D3DXShader::CNode *)a2,
                            a3: i4 | 0x20500000,
                            a4: v133[0],
                            a5: v131,
                            a6: (unsigned int)v132[1] | 0x1700000000LL);
                    if ( v12 >= 0 )
                    {
                      v12 = D3DXShader::CCompiler::EmitInst(
                              (char **)this,
                              (struct D3DXShader::CNode *)a2,
                              a3: (unsigned int)v144,
                              a4: v133[1],
                              a5: v129,
                              a6: (unsigned int)v133[0] | 0x200000000LL);
                      if ( v12 >= 0 )
                      {
                        v97 = v133[1];
                        v141 = (char *)HIDWORD(a2);
                        i4 = (unsigned int)v133[1];
                        for ( nn = v7; nn != 0; --nn )
                        {
                          if ( *(_DWORD *)&v141[v142] == 2 )
                          {
                            v98 = *((_DWORD *)*(this + 2) + 5);
                            v99 = *(int **)(v98 + 4 * *(_DWORD *)((char *)v143 + (_DWORD)v97));
                            v148 = *(double **)(v98 + 4 * *v97);
                            v100 = *v99;
                            if ( (*v99 & 0x80u) != 0 )
                            {
                              *((double *)v99 + 5) = *((double *)v99 + 4);
                              *v99 = v100 | 0x100;
                            }
                            if ( (*((_BYTE *)v99 + 1) & 1) != 0 )
                            {
                              v101 = _finite(x: *((double *)v99 + 4));
                              v102 = *((double *)v99 + 4);
                              if ( v101 != 0 )
                              {
                                v104 = *((double *)this + 22);
                                if ( v105 != 0 )
                                  v102 = -floor(X: v104 - *((double *)v99 + 4));
                                else
                                  v102 = floor(X: v104 + *((double *)v99 + 4));
                              }
                              v148[4] = v102;
                              if ( _finite(x: *((double *)v99 + 5)) != 0 )
                              {
                                v107 = *((double *)this + 22);
                                if ( v108 != 0 )
                                  v109 = -floor(X: v107 - *((double *)v99 + 5));
                                else
                                  v109 = floor(X: v107 + *((double *)v99 + 5));
                                v148[5] = v109;
                                v110 = v148;
                              }
                              else
                              {
                                v110 = v148;
                                v148[5] = *((double *)v99 + 5);
                              }
                              v111 = v110[5];
                              *((_BYTE *)v110 + 1) |= 1u;
                              v112 = *(_DWORD *)v110;
                              if ( v110[4] == v111 )
                                v113 = v112 | 0x80;
                              else
                                v113 = v112 & 0xFFFFFF7F;
                              *(_DWORD *)v110 = v113;
                            }
                            v114 = *(_DWORD *)i4;
                            i4 += 4;
                            *(_DWORD *)v141 = v114;
                            v97 = (unsigned int *)i4;
                          }
                          v141 += 4;
                        }
                        goto LABEL_372;
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
LABEL_385:
    D3DXShader::CCompiler::StackFree((D3DXShader::CCompiler *)this, a2: v146);
    D3DXShader::CCompiler::StackFree((D3DXShader::CCompiler *)this, a2: v147);
    return v12;
  }
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101D98E6
// Name: protected: long D3DXShader::CCompiler::EmitArgs(class D3DXShader::CNode __near *,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitArgs(D3DXShader::CBaseProgram **this, __int64 a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int i; // esi
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned int *v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  double v13; // st7
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // edi
  _DWORD *v18; // eax
  int result; // eax
  struct D3DXShader::CNode *v20; // eax
  unsigned int v21; // esi
  int v22; // eax
  __int64 v23; // [esp-4h] [ebp-18h]
  int v24; // [esp+20h] [ebp+Ch]

  v3 = a2;
  if ( (_DWORD)a2 == 0 )
  {
    if ( HIDWORD(a2) != 0 )
    {
      for ( i = 0; i < a3; ++i )
      {
        v6 = D3DXShader::CBaseProgram::AddArgument(
               this: *(this + 2),
               a2: *((_DWORD *)*(this + 2) + 34),
               a3: 0,
               a4: 0,
               a5: 0.0);
        *(_DWORD *)(HIDWORD(a2) + 4 * i) = v6;
        v7 = (int)*(this + 2);
        if ( v6 >= *(_DWORD *)(v7 + 8) )
          v8 = 0;
        else
          v8 = *(_DWORD *)(*(_DWORD *)(v7 + 20) + 4 * v6);
        if ( v8 != 0 )
          *(_DWORD *)(v8 + 48) = -1;
      }
    }
    return 0;
  }
  v9 = *(_DWORD *)(a2 + 4);
  switch ( v9 )
  {
    case 14:
      v10 = (unsigned int *)HIDWORD(a2);
      if ( HIDWORD(a2) == 0 )
        return 0;
      v11 = *(_DWORD *)(a2 + 16);
      if ( v11 == 6 )
      {
        v12 = 0;
        if ( *(_DWORD *)(a2 + 24) == -1 )
        {
          if ( a3 != 0 )
          {
            do
            {
              *(_DWORD *)(HIDWORD(a2) + 4 * v12) = *((_DWORD *)*(this + 7) + v12);
              ++v12;
            }
            while ( v12 < a3 );
          }
        }
        else if ( a3 != 0 )
        {
          do
          {
            *(_DWORD *)(HIDWORD(a2) + 4 * v12) = *((_DWORD *)*(this + 6) + v12 + *(_DWORD *)(a2 + 24));
            ++v12;
          }
          while ( v12 < a3 );
        }
        return 0;
      }
      v13 = 0.0;
      v24 = 0;
      if ( v11 != 0 )
      {
        v14 = v11 - 1;
        if ( v14 != 0 )
        {
          v15 = v14 - 1;
          if ( v15 != 0 )
          {
            if ( v15 == 1 )
              v13 = *(double *)(a2 + 24);
            goto LABEL_33;
          }
          v13 = (double)*(unsigned int *)(a2 + 24);
        }
        else
        {
          v13 = (double)*(int *)(a2 + 24);
        }
        v24 = 2;
      }
      else
      {
        if ( *(_DWORD *)(a2 + 24) != 0 )
          v13 = 1.0;
        else
          v13 = 0.0;
        v24 = 23;
      }
LABEL_33:
      v16 = D3DXShader::CBaseProgram::AddArgument(
              this: *(this + 2),
              a2: *((_DWORD *)*(this + 2) + 30),
              a3: 0,
              a4: 0,
              a5: v13);
      *v10 = v16;
      v17 = (int)*(this + 2);
      if ( v16 >= *(_DWORD *)(v17 + 8) )
        v18 = nullptr;
      else
        v18 = *(_DWORD **)(*(_DWORD *)(v17 + 20) + 4 * v16);
      if ( v18 != nullptr )
      {
        *v18 |= v24;
        v18[12] = -1;
      }
      return 0;
    case 13:
      return D3DXShader::CCompiler::EmitExpression((void **)this, a2, i4: 0);
    case 1:
      while ( 1 )
      {
        v20 = *(struct D3DXShader::CNode **)(v3 + 8);
        if ( v20 == nullptr )
          goto LABEL_41;
        if ( *((_DWORD *)v20 + 1) == 14 )
        {
          v21 = 1;
          if ( *((_DWORD *)v20 + 4) == 6 )
            v21 = *((_DWORD *)v20 + 7);
          result = D3DXShader::CCompiler::EmitArgs(
                     (D3DXShader::CCompiler *)this,
                     a2: v20,
                     a3: (unsigned int *)HIDWORD(a2),
                     a4: v21);
          if ( result < 0 )
            return result;
          v22 = HIDWORD(a2);
          if ( HIDWORD(a2) != 0 )
            goto LABEL_54;
        }
        else
        {
          if ( *((_DWORD *)v20 + 1) != 13 )
            goto LABEL_41;
          v21 = *((_DWORD *)v20 + 5) * *((_DWORD *)v20 + 6);
          HIDWORD(v23) = HIDWORD(a2);
          LODWORD(v23) = *(_DWORD *)(v3 + 8);
          result = D3DXShader::CCompiler::EmitExpression((void **)this, a2: v23, i4: 0);
          if ( result < 0 )
            return result;
          if ( HIDWORD(a2) != 0 )
          {
            v22 = HIDWORD(a2);
LABEL_54:
            HIDWORD(a2) = v22 + 4 * v21;
          }
        }
        v3 = *(_DWORD *)(v3 + 12);
        if ( v3 == 0 )
          return 0;
      }
    default:
      break;
  }
LABEL_41:
  D3DXShader::CCompiler::Error(
    (D3DXShader::CCompiler *)this,
    a2: nullptr,
    a3: 0,
    format: "internal error: unrecognized value");
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x101D9AE7
// Name: protected: long D3DXShader::CCompiler::EmitEval(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::EmitEval(D3DXShader::CCompiler *this, struct D3DXShader::CNode *a2)
{
  unsigned int v4; // edi
  unsigned int *v5; // eax
  unsigned int *v6; // ebx
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // [esp+4h] [ebp-4h]
  unsigned int i; // [esp+4h] [ebp-4h]

  if ( *((_DWORD *)a2 + 1) != 13 )
    return 0;
  v4 = *((_DWORD *)a2 + 5) * *((_DWORD *)a2 + 6);
  v5 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v10 = D3DXShader::CCompiler::EmitTemp(this, a2: v5, a3: v4);
    if ( v10 >= 0 )
    {
      v10 = D3DXShader::CCompiler::EmitExpression(
              (void **)this,
              a2: __SPAIR64__((unsigned int)v6, (unsigned int)a2),
              i4: 0);
      if ( v10 >= 0 )
      {
        v10 = D3DXShader::CCompiler::EmitInst((char **)this, a2, a3: v4 & 0xFFFFF | 0x10000000, a4: v6, a5: v6, a6: 0);
        if ( v10 >= 0 )
        {
          for ( i = 0; i < v4; ++i )
          {
            v7 = v6[i];
            v8 = *((_DWORD **)this + 2);
            if ( v7 >= v8[2] )
              v9 = 0;
            else
              v9 = *(_DWORD *)(v8[5] + 4 * v7);
            if ( v9 != 0 )
              *(_DWORD *)(v9 + 4) = v8[33];
          }
          v10 = D3DXShader::CCompiler::Vectorize(
                  this,
                  a2: *((struct D3DXShader::CNode ***)a2 + 4),
                  a3: v6,
                  a4: *(_DWORD *)(*((_DWORD *)this + 2) + 132),
                  a5: 1,
                  a6: 1,
                  a7: nullptr,
                  a8: nullptr);
        }
      }
    }
  }
  else
  {
    v10 = -2147024882;
  }
  free(pMem: v6);
  if ( *((_DWORD *)this + 19) != 0 )
    return -2147467259;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101D9BE8
// Name: protected: long D3DXShader::CCompiler::CompileInternal(class D3DXShader::CPreProcessor __near *,class D3DXShader::CNode __near *,char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int,char const __near *,unsigned long,struct ID3DXBuffer __near * __near *,struct ID3DXConstantTable __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::CompileInternal(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CPreProcessor *a2,
        struct D3DXShader::CNode *a3,
        char *a4,
        struct D3DXShader::CNode *a5,
        struct D3DXShader::CNode *a6,
        struct D3DXShader::CNode *a7,
        int a8,
        const char *a9,
        unsigned int a10,
        struct ID3DXBuffer **a11,
        struct ID3DXConstantTable **a12)
{
  unsigned int v13; // ebx
  int v14; // ebx
  void (__thiscall ***v15)(_DWORD, int); // ecx
  int v16; // ecx
  const char *v17; // eax
  D3DXShader::CFXLProgram *v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  bool v21; // zf
  D3DXShader::CVSProgram *v22; // eax
  D3DXShader::CFXLProgram *v23; // eax
  D3DXShader::CPSProgram *v24; // eax
  D3DXShader::CPSLegacyProgram *v25; // eax
  D3DXShader::C30Program *v26; // eax
  D3DXShader::CParse *v27; // eax
  void *v28; // eax
  int v29; // eax
  struct D3DXShader::CNode *Function; // eax
  int v31; // ecx
  unsigned int *v32; // eax
  void (__thiscall ***v33)(_DWORD, int); // ecx
  struct D3DXShader::CPreProcessor *v35; // [esp-Ch] [ebp-ACh]
  unsigned int v36; // [esp-8h] [ebp-A8h]
  void *v37; // [esp-4h] [ebp-A4h]
  _BYTE v38[96]; // [esp+Ch] [ebp-94h] BYREF
  _BYTE v39[24]; // [esp+6Ch] [ebp-34h] BYREF
  _BYTE v40[4]; // [esp+84h] [ebp-1Ch] BYREF
  int v41; // [esp+88h] [ebp-18h]
  struct ID3DXConstantTable *v42; // [esp+90h] [ebp-10h] BYREF
  int v43; // [esp+94h] [ebp-Ch]
  int v44; // [esp+98h] [ebp-8h]
  struct ID3DXBuffer *v45; // [esp+9Ch] [ebp-4h] BYREF

  D3DXCore::CAlloc::CAlloc(this: (D3DXCore::CAlloc *)v39, a2: 0x100000u, a3: 0x10000u);
  v13 = a10;
  v44 = 0;
  v43 = 0;
  if ( (a10 & 0xFFFFF800) != 0 || a3 != nullptr && (a10 & 0x18) != 0 || a11 == nullptr )
    goto LABEL_2;
  v15 = *((void (__thiscall ****)(_DWORD, int))this + 2);
  if ( v15 != nullptr )
    (**v15)(a1: v15, a2: 1);
  free(pMem: *((void **)this + 6));
  *((_DWORD *)this + 18) = -1;
  v21 = a6 == nullptr;
  v16 = a8;
  *(_DWORD *)this = a2;
  v17 = a9;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 3) = v17;
  *((_DWORD *)this + 5) = v13;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = v16;
  if ( !v21 )
  {
    *((_DWORD *)this + 4) = 1180172800;
    v18 = (D3DXShader::CFXLProgram *)MemAlloc_Alloc(nSize: 0x1FCu);
    if ( v18 != nullptr )
      v19 = D3DXShader::CFXLProgram::CFXLProgram(this: v18);
    else
      v19 = 0;
    *((_BYTE *)this + 21) |= 1u;
    goto LABEL_61;
  }
  if ( (v13 & 0xC0) != 0 )
  {
    if ( (int)D3DXGetTargetDescByName(a1: v17, a2: 2, a3: v40) < 0 )
    {
LABEL_15:
      D3DXShader::CCompiler::Error(
        this,
        a2: nullptr,
        a3: 0xDB2u,
        format: "unrecognized compiler target '%s'",
        *((const char **)this + 3));
LABEL_2:
      v14 = -2005530516;
      goto LABEL_100;
    }
    if ( (v41 & 0xFFFF0000) == 0xFFFE0000 )
    {
      if ( (v13 & 0x40) != 0 )
      {
        v13 |= 5u;
        if ( (v41 & 0xFF00) == 0x300 )
          *((_DWORD *)this + 3) = "vs_3_sw";
        else
          *((_DWORD *)this + 3) = "vs_2_sw";
      }
    }
    else if ( (v41 & 0xFFFF0000) == 0xFFFF0000 && (v13 & 0x80u) != 0 )
    {
      v13 |= 5u;
      if ( (v41 & 0xFF00) == 0x300 )
        *((_DWORD *)this + 3) = "ps_3_sw";
      else
        *((_DWORD *)this + 3) = "ps_2_sw";
    }
  }
  if ( (int)D3DXGetTargetDescByName(a1: *((_DWORD *)this + 3), a2: 2, a3: v40) < 0 )
    goto LABEL_15;
  v21 = v41 == -130816;
  *((_DWORD *)this + 4) = v41;
  *((_DWORD *)this + 5) = v13;
  if ( v21 )
  {
    *((_DWORD *)this + 4) = -130815;
    v44 = 1;
  }
  if ( *((_DWORD *)this + 4) == -65280 )
  {
    *((_DWORD *)this + 4) = -65279;
    v43 = 1;
  }
  v20 = *((_DWORD *)this + 4);
  if ( v20 > 0xFFFE03FF )
  {
    if ( v20 > 0xFFFF02FF )
    {
      if ( v20 != -64768 )
      {
        v21 = v20 == -64513;
LABEL_56:
        if ( !v21 )
          goto LABEL_57;
      }
LABEL_58:
      v26 = (D3DXShader::C30Program *)MemAlloc_Alloc(nSize: 0x1F8u);
      if ( v26 != nullptr )
      {
        v19 = D3DXShader::C30Program::C30Program(this: v26, a2: a8);
        goto LABEL_61;
      }
LABEL_60:
      v19 = 0;
      goto LABEL_61;
    }
    if ( v20 != -64769 )
    {
      if ( v20 < 0xFFFF0101 )
      {
LABEL_57:
        *((_DWORD *)this + 2) = 0;
        goto LABEL_62;
      }
      if ( v20 <= 0xFFFF0104 )
      {
        *((_DWORD *)this + 5) = v13 & 0xFFFFFFFB;
        v25 = (D3DXShader::CPSLegacyProgram *)MemAlloc_Alloc(nSize: 0x484u);
        if ( v25 == nullptr )
          goto LABEL_60;
        v19 = D3DXShader::CPSLegacyProgram::CPSLegacyProgram(this: v25);
        goto LABEL_61;
      }
      if ( v20 != -65024 && (v20 <= 0xFFFF0201 || v20 > 0xFFFF0203) )
        goto LABEL_57;
    }
    v24 = (D3DXShader::CPSProgram *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v24 == nullptr )
      goto LABEL_60;
    v19 = D3DXShader::CPSProgram::CPSProgram(this: v24, a2: a8);
  }
  else
  {
    switch ( v20 )
    {
      case 0xFFFE03FF:
        goto LABEL_58;
      case 0x54580100u:
        *((_DWORD *)this + 5) = v13 | 0x100;
        v23 = (D3DXShader::CFXLProgram *)MemAlloc_Alloc(nSize: 0x1FCu);
        if ( v23 == nullptr )
          goto LABEL_60;
        v19 = D3DXShader::CFXLProgram::CFXLProgram(this: v23);
        break;
      case 0xFFFE0101:
      case 0xFFFE0200:
      case 0xFFFE0202:
      case 0xFFFE02FF:
        v22 = (D3DXShader::CVSProgram *)MemAlloc_Alloc(nSize: 0x1F8u);
        if ( v22 == nullptr )
          goto LABEL_60;
        v19 = D3DXShader::CVSProgram::CVSProgram(this: v22, a2: a8);
        break;
      default:
        v21 = v20 == -130304;
        goto LABEL_56;
    }
  }
LABEL_61:
  *((_DWORD *)this + 2) = v19;
LABEL_62:
  if ( *((_DWORD *)this + 2) == 0 )
  {
LABEL_63:
    v14 = -2147024882;
    goto LABEL_100;
  }
  if ( a3 != nullptr )
  {
    *((_DWORD *)this + 1) = a3;
    goto LABEL_68;
  }
  v36 = *((_DWORD *)this + 5) | 0x80000000;
  v35 = *(struct D3DXShader::CPreProcessor **)this;
  v27 = (D3DXShader::CParse *)D3DXShader::CParse::CParse(this: (D3DXShader::CParse *)v38);
  v14 = D3DXShader::CParse::Parse(this: v27, a2: v35, a3: v36, a4: (struct D3DXShader::CNode **)this + 1);
  D3DXShader::CNodeState::Print(this: (D3DXShader::CNodeState *)v38);
  if ( v14 >= 0 )
  {
LABEL_68:
    if ( v44 != 0 )
      D3DXShader::CCompiler::Warning(
        this,
        a2: nullptr,
        a3: 0xDB1u,
        format: "vs_1_0 is no longer supported; using vs_1_1");
    if ( v43 != 0 )
      D3DXShader::CCompiler::Warning(
        this,
        a2: nullptr,
        a3: 0xDB1u,
        format: "ps_1_0 is no longer supported; using ps_1_1");
    if ( *((_DWORD *)this + 34) == 0 )
    {
      *((_DWORD *)this + 35) = 4096;
      v28 = MemAlloc_Alloc(nSize: 0x4000u);
      *((_DWORD *)this + 34) = v28;
      if ( v28 == nullptr )
        goto LABEL_63;
    }
    D3DXShader::CArgument::SetAlloc(a1: (struct D3DXCore::CAlloc *)v39);
    D3DXShader::CInstruction::SetAlloc(a1: (struct D3DXCore::CAlloc *)v39);
    v14 = D3DXShader::CCompiler::EmitProgram(this);
    if ( v14 < 0 )
      goto LABEL_97;
    if ( a6 != nullptr )
    {
      v29 = D3DXShader::CCompiler::EmitEval(this, a2: a6);
LABEL_86:
      v14 = v29;
      if ( v29 < 0 )
        goto LABEL_97;
      if ( *((_DWORD *)this + 19) == 0 )
      {
        v14 = D3DXShader::CCompiler::PragmaDef(this);
        if ( v14 >= 0 )
        {
          v14 = (*(int (__thiscall **)(_DWORD, struct ID3DXBuffer **))(**((_DWORD **)this + 2) + 8))(
                  a1: *((_DWORD *)this + 2),
                  a2: &v45);
          if ( v14 >= 0 )
          {
            if ( a12 != nullptr
              && (v32 = (unsigned int *)v45->GetBufferPointer(this: v45),
                  (v14 = D3DXGetShaderConstantTable(a1: v32, a2: &v42)) < 0) )
            {
              if ( v45 != nullptr )
              {
                v45->Release(this: v45);
                v45 = nullptr;
              }
            }
            else
            {
              *a11 = v45;
              if ( a12 != nullptr )
                *a12 = v42;
              v14 = 0;
            }
          }
        }
        goto LABEL_97;
      }
      goto LABEL_83;
    }
    if ( a4 != nullptr )
    {
      Function = D3DXShader::CCompiler::FindFunction(this, a2: a4);
      if ( Function == nullptr )
      {
        D3DXShader::CCompiler::Error(this, a2: nullptr, a3: 0xDADu, format: "'%s': entrypoint not found", a4);
LABEL_83:
        v14 = -2147467259;
        goto LABEL_97;
      }
      v31 = 0;
    }
    else
    {
      Function = D3DXShader::CCompiler::FindFunction(this, a2: a5, a3: (const char **)&a4);
      if ( Function == nullptr )
      {
        D3DXShader::CCompiler::Error(this, a2: nullptr, a3: 0xDADu, format: "overloaded function not found");
        goto LABEL_83;
      }
      v31 = 1;
    }
    v29 = D3DXShader::CCompiler::EmitFunction(this, a2: a4, a3: Function, a4: a7, a5: nullptr, a6: 1, a7: v31);
    goto LABEL_86;
  }
LABEL_97:
  v33 = *((void (__thiscall ****)(_DWORD, int))this + 2);
  *((_DWORD *)this + 1) = 0;
  if ( v33 != nullptr )
    (**v33)(a1: v33, a2: 1);
  v37 = *((void **)this + 6);
  *((_DWORD *)this + 2) = 0;
  free(pMem: v37);
  *((_DWORD *)this + 6) = 0;
  D3DXShader::CArgument::SetAlloc(a1: nullptr);
  D3DXShader::CInstruction::SetAlloc(a1: nullptr);
LABEL_100:
  D3DXCore::CAlloc::~CAlloc(this: (D3DXCore::CAlloc *)v39);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101DA0D7
// Name: public: long D3DXShader::CCompiler::Compile(class D3DXShader::CPreProcessor __near *,class D3DXShader::CNode __near *,char const __near *,int,char const __near *,unsigned long,struct ID3DXBuffer __near * __near *,struct ID3DXConstantTable __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CCompiler::Compile(
        D3DXShader::CCompiler *this,
        struct D3DXShader::CPreProcessor *a2,
        struct D3DXShader::CNode *a3,
        char *a4,
        int a5,
        char *a6,
        unsigned int a7,
        struct ID3DXBuffer **a8,
        struct ID3DXConstantTable **a9)
{
  if ( a8 != nullptr )
    *a8 = nullptr;
  if ( a9 != nullptr )
    *a9 = nullptr;
  if ( a4 != nullptr )
    return D3DXShader::CCompiler::CompileInternal(
             this,
             a2,
             a3,
             a4,
             a5: nullptr,
             a6: nullptr,
             a7: nullptr,
             a8: a5,
             a9: a6,
             a10: a7,
             a11: a8,
             a12: a9);
  else
    return -2005530516;
}

//------------------------------------------------------------------------------
// Address: 0x101DA11E
// Name: sub_101DA11E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall sub_101DA11E(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v7; // eax
  _DWORD *v8; // ebx
  unsigned int result; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+18h] [ebp+10h]

  if ( *(_WORD *)(a3 + 10) != 0 )
  {
    v7 = *(_DWORD *)(a1 + 8) + *(_DWORD *)(a3 + 12);
    v13 = 0;
    v8 = (_DWORD *)(v7 + 4);
    do
    {
      if ( *v8 != 0 )
        sub_101DA11E(
          a1,
          a2,
          a3: *v8 + *(_DWORD *)(a1 + 8),
          a4: a4 * *(unsigned __int16 *)(*v8 + *(_DWORD *)(a1 + 8) + 8),
          a5,
          a6);
      result = *(unsigned __int16 *)(a3 + 10);
      ++v13;
      v8 += 2;
    }
    while ( v13 < result );
  }
  else
  {
    if ( *(_WORD *)(a2 + 4) != 0 )
    {
      if ( *(_WORD *)a3 == 3 )
      {
        v12 = *(unsigned __int16 *)(a3 + 4);
        v11 = *(unsigned __int16 *)(a3 + 6);
      }
      else
      {
        v12 = *(unsigned __int16 *)(a3 + 6);
        v11 = *(unsigned __int16 *)(a3 + 4);
      }
      v10 = (v12 + 3) >> 2;
    }
    else
    {
      v10 = *(unsigned __int16 *)(a3 + 6);
      v11 = *(unsigned __int16 *)(a3 + 4);
    }
    *a5 += a4 * v11 * v10;
    *a6 += a4 * *(unsigned __int16 *)(a3 + 4) * *(unsigned __int16 *)(a3 + 6);
    return (unsigned int)a6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA1D9
// Name: sub_101DA1D9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_101DA1D9@<eax>(char *a1@<eax>, int a2@<ebx>, unsigned int a3)
{
  unsigned int v3; // edi
  bool v4; // zf
  int v5; // esi
  char v6; // cl

  v3 = 0;
  v4 = a3 == 0;
  if ( a3 != 0 )
  {
    v5 = a2 - (_DWORD)a1;
    while ( 1 )
    {
      v6 = a1[v5];
      if ( v6 < *a1 )
        break;
      if ( v6 > *a1 )
        return 1;
      ++v3;
      ++a1;
      if ( v3 >= a3 )
      {
        v4 = v3 == a3;
        return v4 && *(_BYTE *)(v3 + a2) != 0;
      }
    }
    return -1;
  }
  else
  {
    return v4 && *(_BYTE *)(v3 + a2) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA21A
// Name: public: D3DXShader::CConstant::CConstant(class D3DXShader::CConstantTable __near *,struct _D3DXSHADER_CONSTANTINFO __near *,struct _D3DXSHADER_TYPEINFO __near *,long (*)(void const __near *,unsigned int,void const __near *,unsigned long __near *,unsigned int),unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CConstant::CConstant(
        D3DXShader::CConstant *this,
        struct D3DXShader::CConstantTable *a2,
        struct _D3DXSHADER_CONSTANTINFO *a3,
        struct _D3DXSHADER_TYPEINFO *a4,
        int (__stdcall *a5)(const void *, unsigned int, const void *, unsigned int *, unsigned int),
        unsigned int *a6)
{
  _DWORD *v6; // ebx
  _DWORD *v7; // edi
  _DWORD *v8; // edx

  *(_DWORD *)this = a2;
  qmemcpy((char *)this + 4, a3, 0x14u);
  v6 = (_DWORD *)((char *)this + 52);
  v7 = (_DWORD *)((char *)this + 44);
  *((_DWORD *)this + 7) = a5;
  *((_DWORD *)this + 8) = a6;
  *((_DWORD *)this + 6) = a4;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 13) = 0;
  sub_101DA11E(a1: (int)a2, a2: (int)a3, a3: (int)a4, a4: 1, a5: (_DWORD *)this + 11, a6: (_DWORD *)this + 13);
  v8[10] = *v7 * *((unsigned __int16 *)a4 + 4);
  v8[12] = *v6 * *((unsigned __int16 *)a4 + 4);
  v8[14] = 0;
  v8[15] = 0;
  v8[16] = 0;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101DA28B
// Name: public: D3DXShader::CConstant::~CConstant(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CConstant::~CConstant(D3DXShader::CConstant *this)
{
  unsigned int v2; // ebx
  int v3; // eax
  void *v4; // edi
  unsigned int v5; // edi
  int v6; // eax
  void *v7; // ebx

  v2 = 0;
  if ( *((_DWORD *)this + 14) != 0 )
  {
    if ( *(_WORD *)(*((_DWORD *)this + 6) + 10) != 0 )
    {
      do
      {
        v3 = *((_DWORD *)this + 14);
        v4 = *(void **)(v3 + 4 * v2);
        if ( v4 != nullptr )
        {
          D3DXShader::CConstant::~CConstant(this: *(D3DXShader::CConstant **)(v3 + 4 * v2));
          free(pMem: v4);
        }
        ++v2;
      }
      while ( v2 < *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10) );
    }
    free(pMem: *((void **)this + 14));
  }
  v5 = 0;
  if ( *((_DWORD *)this + 15) != 0 )
  {
    if ( *(_WORD *)(*((_DWORD *)this + 6) + 8) != 0 )
    {
      do
      {
        v6 = *((_DWORD *)this + 15);
        v7 = *(void **)(v6 + 4 * v5);
        if ( v7 != nullptr )
        {
          D3DXShader::CConstant::~CConstant(this: *(D3DXShader::CConstant **)(v6 + 4 * v5));
          free(pMem: v7);
        }
        ++v5;
      }
      while ( v5 < *(unsigned __int16 *)(*((_DWORD *)this + 6) + 8) );
    }
    free(pMem: *((void **)this + 15));
  }
  free(pMem: *((void **)this + 16));
}

//------------------------------------------------------------------------------
// Address: 0x101DA319
// Name: public: long D3DXShader::CConstant::SetScratch(unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstant::SetScratch(D3DXShader::CConstant *this, unsigned int *a2)
{
  int v3; // eax
  int v5; // ecx
  int v6; // ebx
  unsigned int *v8; // [esp+10h] [ebp+8h]

  v3 = *((_DWORD *)this + 6);
  v8 = nullptr;
  *((_DWORD *)this + 8) = a2;
  if ( *(_WORD *)(v3 + 10) != 0 )
  {
    v5 = *((_DWORD *)this + 14);
    do
    {
      v6 = 4 * (_DWORD)v8;
      D3DXShader::CConstant::SetScratch(this: *(D3DXShader::CConstant **)(v5 + 4 * (_DWORD)v8), a2);
      v5 = *((_DWORD *)this + 14);
      v8 = (unsigned int *)((char *)v8 + 1);
      a2 += *(_DWORD *)(*(_DWORD *)(v5 + v6) + 44)
          * *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v5 + v6) + 24) + 8)
          * (*(_WORD *)(*(_DWORD *)(v5 + v6) + 8) != 0 ? 4 : 1);
    }
    while ( (unsigned int)v8 < *(unsigned __int16 *)(*((_DWORD *)this + 6) + 10) );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DDA92
// Name: public: virtual long D3DXShader::CConstantTable::SetBoolArray(struct IDirect3DDevice9 __near *,char const __near *,int const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetBoolArray(
        D3DXShader::CConstantTable *this,
        struct IDirect3DDevice9 *a2,
        int a3,
        float *a4,
        unsigned int a5)
{
  int v5; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v5 = -a3;
    goto LABEL_6;
  }
  result = D3DXShader::CConstantTable::FindConstantByName(
             this,
             a2: (const char *)a3,
             (struct D3DXShader::CConstant **)&a3);
  if ( result >= 0 )
  {
    v5 = a3;
LABEL_6:
    while ( 1 )
    {
      result = D3DXShader::SetTyped<0,1,1,1,0>::Set(a1: v5, (int)a2, a3: a4, a4: a5, a5: 0);
      if ( result < 0 )
        break;
      v5 = *(_DWORD *)(v5 + 36);
      if ( v5 == 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DDADE
// Name: public: virtual long D3DXShader::CConstantTable::SetInt(struct IDirect3DDevice9 __near *,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetInt(
        D3DXShader::CConstantTable *this,
        struct IDirect3DDevice9 *a2,
        int a3,
        float a4)
{
  int v4; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v4 = -a3;
    goto LABEL_6;
  }
  result = D3DXShader::CConstantTable::FindConstantByName(
             this,
             a2: (const char *)a3,
             (struct D3DXShader::CConstant **)&a3);
  if ( result >= 0 )
  {
    v4 = a3;
LABEL_6:
    while ( 1 )
    {
      result = D3DXShader::SetTyped<0,2,1,1,0>::Set(a1: v4, (int)a2, a3: &a4, a4: 1u, a5: 0);
      if ( result < 0 )
        break;
      v4 = *(_DWORD *)(v4 + 36);
      if ( v4 == 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DDB2A
// Name: public: virtual long D3DXShader::CConstantTable::SetIntArray(struct IDirect3DDevice9 __near *,char const __near *,int const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::SetIntArray(
        D3DXShader::CConstantTable *this,
        struct IDirect3DDevice9 *a2,
        int a3,
        float *a4,
        unsigned int a5)
{
  int v5; // esi
  int result; // eax

  if ( a3 < 0 )
  {
    v5 = -a3;
    goto LABEL_6;
  }
  result = D3DXShader::CConstantTable::FindConstantByName(
             this,
             a2: (const char *)a3,
             (struct D3DXShader::CConstant **)&a3);
  if ( result >= 0 )
  {
    v5 = a3;
LABEL_6:
    while ( 1 )
    {
      result = D3DXShader::SetTyped<0,2,1,1,0>::Set(a1: v5, (int)a2, a3: a4, a4: a5, a5: 0);
      if ( result < 0 )
        break;
      v5 = *(_DWORD *)(v5 + 36);
      if ( v5 == 0 )
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028CAA0
// Name: _dynamic_atexit_destructor_for__notsetVal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__notsetVal__()
{
  GASValue::~GASValue(this: &notsetVal);
}
